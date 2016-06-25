#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
#include <math.h>
//#include <netinet/in.h>
//#include <sys/socket.h>
#include <winsock2.h>

#include "dpf2m.h"
#include "vec2m.h"
#include "cc2m.h"

#define		FLUXLOOP_IN_UPPER				1		/* */
#define		FLUXLOOP_IN_LOWER				2
#define		FLUXLOOP_OUT_UPPER				3
#define		FLUXLOOP_OUT_LOWER				4

/*  */

/* functions */
void pscSysInitial(PowerSupplyAndCoilSystem_t *pscSys, int pidOption);
void ctrlSysInitial(freedBackControl_t *);
void rzfluxIndxSet(freedBackControl_t *ctrlSys, int, int, int, int);

void pidOpotionSet(freedBackControl_t *, int, int);


void  horizontalDispacementCal(FlDispacementCal_t *);
void  verticalDispacementCal(FlDispacementCal_t *);

float IncrementPidCal(incrementPidController_t *);
float RcFilter(rcFilter2m_t *f);
int	cycleCounterToIndex(int );
int	indexToCycleCounter(int );
void pscCtrlParameterInitial(PowerSupplyAndCoils_t *, int);
void unlockPscSysCheck(PowerSupplyAndCoilSystem_t *);
void unlockPs(PowerSupplyAndCoils_t *, int);

void lockPscSysCheck(PowerSupplyAndCoilSystem_t *);
void PsOperationStatusCheck(PowerSupplyAndCoilSystem_t *);

void lockPs( PowerSupplyAndCoils_t *, int);   /*-------------------------------------*/

void plasmalessDischarge(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);
void firstPlasmaDischarge(PowerSupplyAndCoilSystem_t *, freedBackControl_t *, bool);
void normalPlasmaDischarge(PowerSupplyAndCoilSystem_t *, freedBackControl_t *, int);
void dischareFailureHandle(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);


int	getDischarePhase(PowerSupplyAndCoilSystem_t *, freedBackControl_t *, DpfCentralCtrl_t *);
void getAcqData(void  *);
void acqDataProcess(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);

void horizontaPositionControl(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);
void verticalPositionControl(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);
//void plasmaCurrentControl(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);
void plasCurrentControl(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *ctrlSys);

void currentfreedBackInit(PowerSupplyAndCoilSystem_t *);
void currentfreedBackControl(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);
void votageCorrectCal(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);
void calculatePsCtrlAngle(PowerSupplyAndCoilSystem_t *, freedBackControl_t *, bool);
void sendCtrlAngleToPs(int, powerSupplyCtrlCmd_t *);

void isoFluxControl(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);

float GAcqData[ACQ_COUNT];
PowerSupplyAndCoils_t			psPf2m[PSC_COUNT];
PowerSupplyAndCoilSystem_t	pscSys;
freedBackControl_t				ctrlSys;

int main (int argc,char * argv[])
{
	/* vec2m variables */
	//dataAcqChannel_t				dataAcqChannel2m; 
	//ccTargetWaveForm_t			ccTargetWaveForm2m;
	//psVotageControl_t				pidcontroll2m;

	/* dpf2m vairables */
	DpfCentralCtrl_t				dpfCentralCtrl2m;
	//DpfMotorGenerator_t			dpfMotorGenerator2m;
	//DpfPowerSupply_t				dpfPowerSupply2m;
	//DpfVacuum_t					dpfVacuum2m;
	//DpfMachine_t					dpfMachine2m;
	//DpfAuxHeating_t				dpfAuxHeating2m;
	//DpfDasRCfilter_t				dpfDasRCfilter2m;

	/* hl-2m poloidal power supply and coils variable sets */



	int				id, cycleCounter;		/* 循环计数器，以控制周期为单位*/

	int				discharePhase;		/* 放电阶段  */ 

	bool				forceNoBFCntrl;		/* 强制不返馈 */

	/* read 2mdpf.xml file */
	if (!dpfCentralCtrl2m.feedBackCmd) return 0;		/* 反馈不投入 */
	/* read vec 文件并插值 */
	
	for (id=PSC_CS; id<PSC_COUNT; id++)
		{
			psPf2m[id].id = id;
			pscSys.psAndcoils2m[id] = &(psPf2m[id]);
		}

	pscSys.controlPeriodTime		= 1.0;	/* (ms) */


	/* pid(iPF_acq-iPF_target), pid option : CNTRL_OPTION_PID, CNTRL_OPTION_P, CNTRL_OPTION_PI, CNTRL_OPTION_PD */
	pscSysInitial(&pscSys, CNTRL_OPTION_PID);
	rzfluxIndxSet(&ctrlSys, FLUXLOOP_IN_UPPER, FLUXLOOP_IN_LOWER, FLUXLOOP_OUT_UPPER, FLUXLOOP_OUT_LOWER);
	ctrlSysInitial(&ctrlSys);
	pidOpotionSet(&ctrlSys, SET_CTRLLER_IP, CNTRL_OPTION_PID);
	pidOpotionSet(&ctrlSys, SET_CTRLLER_R, CNTRL_OPTION_PID);
	pidOpotionSet(&ctrlSys, SET_CTRLLER_Z, CNTRL_OPTION_PID);
	pidOpotionSet(&ctrlSys, SET_CTRLLER_ISOFLUX, CNTRL_OPTION_PID);

	/* read 2mdpf.xml file */
	/* read 2mvec file */
	/* read ctrlSys.MutualMatrix */

	ctrlSys.ctrlMode = dpfCentralCtrl2m.CtrlMode;
	/*ctrlSys.doFreedBackCntrl = dpfCentralCtrl2m.feedBackMode;*/
	/*  反馈与时序、逻辑的关系*/
	/*  cycleCounter  */
	
	//if (cycleCounter == dpfCentralCtrl2m.DischargeStartStep)		/* Discharge Start */
	do {	/* 实时程序将修改这种循环结构*/
			/* get current time from TSC ??????????  linux MRG */
			
			pscSys.cycleCount = cycleCounter;
			pscSys.cycleIndx = cycleCounterToIndex(cycleCounter);
			/* get acq data & filter for acq_data ??????????????????????????????? */
			getAcqData(&(ctrlSys.mDiag.acqData));
			acqDataProcess(&pscSys, &ctrlSys);
			if (ctrlSys.disFail.disrupTimes >= DISRUPT_MAX_TIMES) ctrlSys.disFail.dischareFailure = 1;
			if (ctrlSys.disFail.dischareFailure)
				{
					dischareFailureHandle(&pscSys, &ctrlSys);
				}
			else
				{
					switch (dpfCentralCtrl2m.OperationMode)
						{
						case FB_NO_PLASMA :	
							/* plasmaless discharge, test & scaling */
							plasmalessDischarge(&pscSys, &ctrlSys);
							break;
							
						case FIRST_PLASMA :
							/* 所有电源只有负组工作*/
							ctrlSys.ctrlMode = CTRL_RZIP;
							//if (cycleCounter < 10 )
							if (ctrlSys.mDiag.ipAcq.data[pscSys.cycleIndx] < 5.0 )
								{
									forceNoBFCntrl = 1;
								}
							else if (cycleCounter < dpfCentralCtrl2m.FBStartTime)
								{
									forceNoBFCntrl = dpfCentralCtrl2m.feedBackMode;
									ctrlSys.doFreedBackCntrl = 0;
								}
							else
								{
									forceNoBFCntrl = dpfCentralCtrl2m.feedBackMode;
									ctrlSys.doFreedBackCntrl = 1;
								}
								firstPlasmaDischarge(&pscSys, &ctrlSys, forceNoBFCntrl);
							
							break;
							
						case NORMAL_PLASMA :
						default :
							discharePhase = getDischarePhase(&pscSys, &ctrlSys, &dpfCentralCtrl2m);
							normalPlasmaDischarge(&pscSys, &ctrlSys, discharePhase);
						}
					/* check 一个控制周期的剩余时间  */
					cycleCounter++;
				}
		}
	while(cycleCounter < dpfCentralCtrl2m.DischargeEndStep);
	return 0;
}



void pscSysInitial(PowerSupplyAndCoilSystem_t *pscSys, int pidOption)
{
	int i,count;
	PowerSupplyAndCoils_t	*p;
	
	count = 0;
	for(i=PSC_CS; i<PSC_COUNT; i++) 
		{
			p = pscSys->psAndcoils2m[i];
			if (p->cmd)
				{
					pscSys->readyPsAddress[count++] = p;
					pscSys->readyPsIdAddress[p->id] = p;
					p->di = 0.0;
					p->du = 0.0;
					p->sumDu = 0.0;
					//p->positiveGroupStatus = PS_LOCK;
					//p->negtiveGroupStatus = PS_LOCK;
					p->operationStatus = PS_CLOSE_STATE;
					pscCtrlParameterInitial(p, pidOption);
					/* send cmd to power supply system, lock (p->id).positiveGroup & negtiveGroup ???? */
					lockPs(p, SIG_PS_LOCK_POS_NEG);
				}
			else{
					pscSys->readyPsIdAddress[p->id] = NULL;
				}
			pscSys->workingPsIdAddress[p->id] = NULL;
				
		}
	pscSys->readyPsCount = count;
	pscSys->workingPsCount = 0;
}

void rzfluxIndxSet(freedBackControl_t *ctrlSys, int iu, int il, int ou, int ol)
{
	ctrlSys->mDiag.fl_iu = iu;	/*  flux_iu(t) = ctrlSys->mDiag.fluxLoop[iu].data[t] ;*/
	ctrlSys->mDiag.fl_il = il;
	ctrlSys->mDiag.fl_ou = ou;
	ctrlSys->mDiag.fl_ol = ol;
}

void ctrlSysInitial(freedBackControl_t * ctrlSys)
{
	int i,j;

	ctrlSys->disFail.ipPre = 0.0;
	ctrlSys->disFail.ipCur= 0.0;
	ctrlSys->disFail.disrupTimes = 0;
	ctrlSys->disFail.dischareFailure = 0;

	for (i=0; i<MAX_DISCHARGE_TIME; i++)
		{
			ctrlSys->mDiag.ipAcq.data[i] = 0.0;
			for (j=0; j<NUMBER_FLUX; j++)
				ctrlSys->mDiag.fluxLoop[j].data[i] = 0.0;
			for (j=0; j<NUMBER_PROBE; j++)
				ctrlSys->mDiag.mProbe[j].data[i] = 0.0;
			
			ctrlSys->ipControl.target.data[i] = 0.0;
			ctrlSys->ipControl.controller.Kp[i] = 0.0;
			ctrlSys->ipControl.controller.Ti[i] = 0.0;
			ctrlSys->ipControl.controller.Td[i] = 0.0;
			
			ctrlSys->rControl.target.data[i] =0.0;
			ctrlSys->rControl.controller.Kp[i] = 0.0;
			ctrlSys->rControl.controller.Ti[i] = 0.0;
			ctrlSys->rControl.controller.Td[i] = 0.0;

			ctrlSys->zControl.target.data[i] = 0.0;
			ctrlSys->zControl.controller.Kp[i] = 0.0;
			ctrlSys->zControl.controller.Ti[i] = 0.0;
			ctrlSys->zControl.controller.Td[i] = 0.0;
			for (j=0; j<ISO_FLUX_POINTS; j++)
				{
					ctrlSys->isofluxCtrl.pidCtroller[j].Kp[i] = 0.0;
					ctrlSys->isofluxCtrl.pidCtroller[j].Ti[i] = 0.0;
					ctrlSys->isofluxCtrl.pidCtroller[j].Td[i] = 0.0;
				}
		}

}

void pidOpotionSet(freedBackControl_t * ctrlSys, int controller, int pidOpition)
{
	int	 i;
	switch (controller)
		{
		case SET_CTRLLER_IP:
			ctrlSys->ipControl.controller.pidOption = pidOpition;
			break;
			
		case SET_CTRLLER_R:
			ctrlSys->rControl.controller.pidOption = pidOpition;
			break;
			
		case SET_CTRLLER_Z:
			ctrlSys->zControl.controller.pidOption = pidOpition;
			break;

		case SET_CTRLLER_ISOFLUX:
			for (i=0; i<ISO_FLUX_POINTS; i++)
				ctrlSys->isofluxCtrl.pidCtroller[i].pidOption = pidOpition;
			break;
		}
}


void pscCtrlParameterInitial(PowerSupplyAndCoils_t *p, int pidOption)
{
	int		i;

	p->pidParameter.pidOption = pidOption;
	for (i=0; i<MAX_DISCHARGE_TIME; i++)
		{
			p->iAcq.data[i] = 0.0;
			p->iTarget.data[i] = 0.0;
			p->vTarget.data[i] = 0.0;
			p->pidParameter.Kp[i] = 0.0;
			p->pidParameter.Ti[i] = 0.0;
			p->pidParameter.Td[i] = 0.0;
		}
}

void unlockPscSysCheck(PowerSupplyAndCoilSystem_t *pscSys)
{
	int					i,indx;
	PowerSupplyAndCoils_t	*p;

	for (i=PSC_CS; i<PSC_COUNT; i++)
	{
		p = pscSys->readyPsIdAddress[i];
		if (p != NULL)
		{
			indx = p->vTarget.startIndx;
			if (pscSys->cycleCount == indexToCycleCounter(indx))		/* 解封锁时刻*/
				{
					if ( p->vTarget.data[indx+3] > 0.0)
						{
							p->operationMode = PS_BOTH_POS_NEG_GROUP;
							// p->positiveGroupStatus = PS_UNLOCK;
							/* send cmd to power supply system, unlock (p->id).positiveGroup */
							unlockPs(p, SIG_PS_UNLOCK_POS);
							p->operationStatus = PS_POS_FULL_OPERATION;
						}
					else
						{
							p->operationMode = PS_ONLY_NEG_GROUP;
							// p->negtiveGroupStatus = PS_UNLOCK;
							/* send cmd to power supply system, unlock (p->id).negtiveGroup */
							unlockPs(p, SIG_PS_UNLOCK_NEG);
							p->operationStatus = PS_NEG_FULL_OPERATION;
						}
					pscSys->workingPsIdAddress[p->id] = p;
					pscSys->workingPsCount += 1;
					pscSys->readyPsIdAddress[p->id] = NULL;
					pscSys->readyPsCount -= 1;

				}
		}
	}

}


void PsOperationStatusCheck(PowerSupplyAndCoilSystem_t *pscSys)
{
	int	i,indx;

	PowerSupplyAndCoils_t	*p;
	indx = pscSys->cycleIndx;
	for (i=PSC_CS; i<PSC_COUNT; i++)
	{
		p = pscSys->workingPsIdAddress[i];
		if (p != NULL)
		{
			if (p->operationMode == PS_BOTH_POS_NEG_GROUP)
				{
				
					switch (p->operationStatus)
					{
						case PS_POS_FULL_OPERATION :
							if (p->iAcq.data[indx] <= p->maxIcircle)
								{
									lockPs(p, SIG_COVTER_CLOSE_POS);	/* 关闭部分正组变流器 */
									unlockPs(p, SIG_PS_UNLOCK_NEG);		/*  解封锁负组电源 */
									p->operationStatus = PS_POS_PART_OPERATION;
								}
							break;
							
						case PS_POS_PART_OPERATION :
							if (p->iAcq.data[indx]<= p->maxIcircle/3.0)
								{
									unlockPs(p, SIG_COVTER_OPEN_NEG);	/*  打开负组部分变流器 */
									p->operationStatus = PS_CIRCLE_CURRENT_OPERATION;
								}
							break;
							
						case PS_CIRCLE_CURRENT_OPERATION :
							if (p->iAcq.data[indx] <= -p->maxIcircle/3.0)
								{
									unlockPs(p, SIG_COVTER_CLOSE_POS);		/* 关闭正组全部变流器 */
									p->operationStatus = PS_NEG_PART_OPERATION;
								}
							break;
							
						case PS_NEG_PART_OPERATION :
							if (p->iAcq.data[indx] <= -p->maxIcircle)
								{
									unlockPs(p, SIG_COVTER_OPEN_NEG);		/* 打开负组全部变流器 */
									unlockPs(p, SIG_PS_LOCK_POS);			/* 封锁正组电源 */
									p->operationStatus = PS_NEG_FULL_OPERATION;
								}
							break;
							
						case PS_NEG_FULL_OPERATION :
						default :
							break;
					}
				}
			
		}
	}

}

void unlockPs(PowerSupplyAndCoils_t *ps, int sig)
{

}

void lockPscSysCheck(PowerSupplyAndCoilSystem_t *pscSys)
{
	int						i, indx;
	PowerSupplyAndCoils_t		*p;

	for (i=PSC_CS; i<PSC_COUNT; i++)
	{
		p = pscSys->workingPsIdAddress[i];
		if (p != NULL)
		{
			indx = p->vTarget.endIndx;
			if (pscSys->cycleCount == indexToCycleCounter(indx-3))		/*  封锁时刻*/
			{
			switch (p->operationStatus)
				{
					case PS_POS_FULL_OPERATION :
					case PS_POS_PART_OPERATION:
						/* send cmd to power supply system, unlock (p->id).positiveGroup */
						lockPs(p, SIG_PS_LOCK_POS);
						p->operationStatus = PS_CLOSE_STATE;
						pscSys->workingPsIdAddress[p->id] = NULL;
						pscSys->workingPsCount -= 1;
						break;
						
					case PS_CIRCLE_CURRENT_OPERATION:
						/* ??????????????? */
						break;
						
					case PS_NEG_PART_OPERATION:
					case PS_NEG_FULL_OPERATION:
						/* send cmd to power supply system, unlock (p->id).negtiveGroup */
						lockPs(p, SIG_PS_LOCK_NEG);
						p->operationStatus = PS_CLOSE_STATE;
						pscSys->workingPsIdAddress[p->id] = NULL;
						pscSys->workingPsCount -= 1;

						break;
				}
			}
		}
	}
	
}

void lockPs(PowerSupplyAndCoils_t *ps, int sig)
{

}

void getAcqData(void  *acqDataAdress)
{
	int	i;
	float  *acqData;
	acqData = (float * ) acqDataAdress;
	for (i=PSC_CS; i<ACQ_COUNT; i++)
		{
			acqData[i] = GAcqData[i];				/* acqData[PCS_CS...PCSPF8L] = I_PF[0...17]  */
		}
	//acqData[ACQ_IP_ID];					/* acqData[] = Ip */
	//acqData[ACQ_FL_IU_ID];
	//acqData[ACQ_FL_IL_ID];
	//acqData[ACQ_FL_OU_ID];
	//acqData[ACQ_FL_OU_ID];
}
void acqDataProcess(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *ctrlSys)
{
	int					i,indx;
	int					iu, il, ou, ol;
	PowerSupplyAndCoils_t	*p;

	rcFilter2m_t			filter;
	
	indx = pscSys->cycleIndx;
	for (i=PSC_CS; i<PSC_COUNT; i++)
		{
			p = pscSys->workingPsIdAddress[i];
			if (p != NULL)
				{
					p->iAcq.data[indx] = ctrlSys->mDiag.acqData[i];
					filter.signal[0] = p->iAcq.data[indx-1];
					filter.signal[1] = p->iAcq.data[indx];
					filter.taoRc = p->rcI;
					p->iAcq.data[indx] = RcFilter(&filter);
				}
		}
	
	ctrlSys->mDiag.ipAcq.data[indx] = ctrlSys->mDiag.acqData[ACQ_IP_ID];
	
	ctrlSys->disFail.ipCur = ctrlSys->mDiag.ipAcq.data[indx];
	if (((ctrlSys->disFail.ipCur-ctrlSys->disFail.ipPre)/pscSys->controlPeriodTime) < DISRUPTION_OCC)
		{
			ctrlSys->disFail.disrupt = 1;
			ctrlSys->disFail.disrupTimes += 1;
		}
	else
		ctrlSys->disFail.disrupt = 0;
	ctrlSys->disFail.ipPre = ctrlSys->disFail.ipCur;

	if (ctrlSys->mDiag.ipAcq.data[indx] < IP_TARGET_FACTOR*(ctrlSys->ipControl.target.data[indx]))
			ctrlSys->disFail.dischareFailure = 1;
	
	filter.signal[0] = ctrlSys->mDiag.ipAcq.data[indx-1];
	filter.signal[1] = ctrlSys->mDiag.ipAcq.data[indx];
	filter.taoRc = ctrlSys->mDiag.ipRc;
	ctrlSys->mDiag.ipAcq.data[indx] = RcFilter(&filter);
	
	
	iu= ctrlSys->mDiag.fl_iu;
	il= ctrlSys->mDiag.fl_il;
	ou= ctrlSys->mDiag.fl_ou;
	ol= ctrlSys->mDiag.fl_ol;
	ctrlSys->mDiag.fluxLoop[iu].data[indx] = ctrlSys->mDiag.acqData[ACQ_FL_IU_ID];
	ctrlSys->mDiag.fluxLoop[il].data[indx] = ctrlSys->mDiag.acqData[ACQ_FL_IL_ID];
	ctrlSys->mDiag.fluxLoop[ou].data[indx] = ctrlSys->mDiag.acqData[ACQ_FL_OU_ID];
	ctrlSys->mDiag.fluxLoop[ol].data[indx] = ctrlSys->mDiag.acqData[ACQ_FL_OL_ID];

	filter.signal[0] = ctrlSys->mDiag.fluxLoop[iu].data[indx-1];
	filter.signal[1] = ctrlSys->mDiag.fluxLoop[iu].data[indx];
	filter.taoRc = ctrlSys->plasDisp.rcPh;						/* ??? rcPv */
	ctrlSys->mDiag.fluxLoop[iu].data[indx] = RcFilter(&filter);

	filter.signal[0] = ctrlSys->mDiag.fluxLoop[il].data[indx-1];
	filter.signal[1] = ctrlSys->mDiag.fluxLoop[il].data[indx];
	filter.taoRc = ctrlSys->plasDisp.rcPh;						/* ??? rcPv */
	ctrlSys->mDiag.fluxLoop[il].data[indx] = RcFilter(&filter);

	filter.signal[0] = ctrlSys->mDiag.fluxLoop[ou].data[indx-1];
	filter.signal[1] = ctrlSys->mDiag.fluxLoop[ou].data[indx];
	filter.taoRc = ctrlSys->plasDisp.rcPh;						/* ??? rcPv */
	ctrlSys->mDiag.fluxLoop[ou].data[indx] = RcFilter(&filter);

	filter.signal[0] = ctrlSys->mDiag.fluxLoop[ol].data[indx-1];
	filter.signal[1] = ctrlSys->mDiag.fluxLoop[ol].data[indx];
	filter.taoRc = ctrlSys->plasDisp.rcPh;						/* ??? rcPv */
	ctrlSys->mDiag.fluxLoop[ol].data[indx] = RcFilter(&filter);

}

void plasmalessDischarge(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *ctrlSys)
{	
	int   i;
	bool		forceNoBFCntrl;
	int		idCircleCurrent;
	PowerSupplyAndCoils_t  *p;

	if (pscSys->readyPsCount > 0) unlockPscSysCheck(pscSys);

	if (ctrlSys->doFreedBackCntrl) 
		{
			/* PF coil current freed back control di->du */
			currentfreedBackInit(pscSys);				/* set delta_di = 0 */
			currentfreedBackControl(pscSys, ctrlSys);		/* delta_di = pid(i_acq-i_Target) */
			votageCorrectCal(pscSys, ctrlSys);			/* du = M*di + Rdi, sumDu += du */
			forceNoBFCntrl = 0;
			calculatePsCtrlAngle(pscSys, ctrlSys, forceNoBFCntrl);	/* calclate control angle alpha */
		}
	else
		{
			forceNoBFCntrl = 1;
			calculatePsCtrlAngle(pscSys, ctrlSys, forceNoBFCntrl);
		}

	PsOperationStatusCheck(pscSys);

	if (pscSys->workingPsCount > 0) lockPscSysCheck(pscSys);
}


void firstPlasmaDischarge(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *ctrlSys, bool forceNoBFCntrl)
{

	if (pscSys->readyPsCount > 0) unlockPscSysCheck(pscSys);
	if (forceNoBFCntrl)
		{
			/*  during plasma breakdown or test dischare */
			calculatePsCtrlAngle(pscSys, ctrlSys, forceNoBFCntrl);
		}
	else if (ctrlSys->doFreedBackCntrl)
		{
			/* Ip < 50 kA */
			/* PF coil current freed back control di->du */
			currentfreedBackInit(pscSys);				/* set delta_di = 0 */
			currentfreedBackControl(pscSys, ctrlSys);		/* delta_di = pid(i_acq-i_Target) */
			votageCorrectCal(pscSys, ctrlSys);			/* du = M*di/dt + Rdi, sumDu += du */
			calculatePsCtrlAngle(pscSys, ctrlSys, 0);			/* calclate control angle alpha */
		}
	else
		{
			currentfreedBackInit(pscSys);				/* set delta_di = 0 */
			horizontaPositionControl(pscSys, ctrlSys);
			verticalPositionControl(pscSys, ctrlSys);
			plasCurrentControl(pscSys, ctrlSys);
			currentfreedBackControl(pscSys, ctrlSys);		/* delta_di = pid(i_acq-i_Target) */
			votageCorrectCal(pscSys, ctrlSys);			/* du = M*di + Rdi/dt, sumDu += du */
			calculatePsCtrlAngle(pscSys, ctrlSys, 0);			/* calclate control angle alpha */
		}

	if (pscSys->workingPsCount > 0) lockPscSysCheck(pscSys);
}

void normalPlasmaDischarge(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *ctrlSys, int discharePhase)
{
	bool		forceNoBFCntrl;

	switch (discharePhase)
		{
		case NDP_CS_CHAREG :
			if (pscSys->readyPsCount > 0) unlockPscSysCheck(pscSys);
			
			if (ctrlSys->doFreedBackCntrl) 
				{
					/* PF coil current freed back control di->du */
					currentfreedBackInit(pscSys);				/* set delta_di = 0 */
					currentfreedBackControl(pscSys, ctrlSys);		/* delta_di = pid(i_acq-i_Target) */
					votageCorrectCal(pscSys, ctrlSys);			/* du = M*di/dt + Rdi, sumDu += du */
					forceNoBFCntrl = 0;
					calculatePsCtrlAngle(pscSys, ctrlSys, forceNoBFCntrl);	/* calclate control angle alpha */
				}
			else
				{
					forceNoBFCntrl = 1;
					calculatePsCtrlAngle(pscSys, ctrlSys, forceNoBFCntrl);
				}

			break;
			
		case NDP_CS_INVERSE :
		
			forceNoBFCntrl = 1;
			calculatePsCtrlAngle(pscSys, ctrlSys, forceNoBFCntrl);
			break;
			
		case NDP_IP_RAMP_UP_NO_FB :
			ctrlSys->disFail.disrupt;
			
			currentfreedBackInit(pscSys);				/* set delta_di = 0 */
			currentfreedBackControl(pscSys, ctrlSys);		/* delta_di = pid(i_acq-i_Target) */
			votageCorrectCal(pscSys, ctrlSys);			/* du = M*di + Rdi/dt, sumDu += du */
			calculatePsCtrlAngle(pscSys, ctrlSys, 0);			/* calclate control angle alpha */
			break;
			
		case NDP_IP_RAMP_UP_FB :
		case NDP_IP_FLATTOP_RAMP_DOWN:
			currentfreedBackInit(pscSys);				/* set delta_di = 0 */
			switch (ctrlSys->ctrlMode)
			{
				case CTRL_ISOFLUX :
					isoFluxControl(pscSys, ctrlSys);
					break;
					
				case CTRL_GAP :
					break;
					
				case CTRL_RZIP :	
				default :
					horizontaPositionControl(pscSys, ctrlSys);
					verticalPositionControl(pscSys, ctrlSys);
			}
			plasCurrentControl(pscSys, ctrlSys);
			currentfreedBackControl(pscSys, ctrlSys);		/* delta_di = pid(i_acq-i_Target) */
			votageCorrectCal(pscSys, ctrlSys);			/* du = M*di + Rdi, sumDu += du */
			calculatePsCtrlAngle(pscSys, ctrlSys, 0);			/* calclate control angle alpha */
			if (pscSys->workingPsCount > 0) lockPscSysCheck(pscSys);
			break;
			
		default:
			break;
			
		PsOperationStatusCheck(pscSys);

		}

}

void dischareFailureHandle(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *ctrlSys)
{
	int						i,indx;
	PowerSupplyAndCoils_t		*p;
	powerSupplyCtrlCmd_t 		psCmd;
	float						u,ud;
	float pi  = 3.1415926;

	indx = pscSys->cycleIndx;
	for (i=PSC_CS; i<PSC_COUNT; i++)
	{
		p = pscSys->workingPsIdAddress[i];
		if (p != NULL)
		{
			switch (p->operationStatus)
			{
				case PS_POS_FULL_OPERATION :
				case PS_POS_PART_OPERATION :
					if (p->iAcq.data[pscSys->cycleIndx] > 0.0)
						{
							ud = p->vTarget.data[indx];
							u = ud/(1.35*p->u2l*pscSys->VotageMGforPF/3000.0);
							psCmd.cmdType = CMD_PS_POS;
							psCmd.alphaPos = acos(u);
							sendCtrlAngleToPs(p->id, &psCmd);
						}
					else
						{
							lockPs(p, SIG_PS_LOCK_POS);	/* close PS positive set  */
							pscSys->workingPsIdAddress[p->id] = NULL;
							pscSys->workingPsCount -= 1;
						}
					break;
					
				case PS_CIRCLE_CURRENT_OPERATION :
							lockPs(p, SIG_PS_LOCK_POS_NEG);
							pscSys->workingPsIdAddress[p->id] = NULL;
							pscSys->workingPsCount -= 1;
							break;
					
				case PS_NEG_PART_OPERATION :
							lockPs(p, SIG_PS_LOCK_POS_NEG);
							pscSys->workingPsIdAddress[p->id] = NULL;
							pscSys->workingPsCount -= 1;
					break;
					
				case PS_NEG_FULL_OPERATION :
					if (p->iAcq.data[pscSys->cycleIndx] > 0.0)
						{
							ud = p->vTarget.data[indx];
							u = ud/(1.35*p->u2l*pscSys->VotageMGforPF/3000.0);
							psCmd.cmdType = CMD_PS_NEG;
							psCmd.alphaNeg = acos(-u);
							sendCtrlAngleToPs(p->id, &psCmd);
						}
					else
						{
							lockPs(p, SIG_PS_LOCK_POS);	/* close positve group */
							pscSys->workingPsIdAddress[p->id] = NULL;
							pscSys->workingPsCount -= 1;
						}
					break;
				default :
					break;
			}
		
		}
	}
}

int	getDischarePhase(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *ctrlSys, DpfCentralCtrl_t *cc2m)
{
	float ip, ipMax;
	if (pscSys->cycleCount < 0) return NDP_CS_CHAREG;

	//if (((pscSys->cycleCount >= 0) && (pscSys->cycleCount <= 10)) ||ctrlSys->mDiag.ipAcq < 5.0) return NDP_CS_INVERSE;
	if (ctrlSys->mDiag.ipAcq.data[pscSys->cycleIndx] < 5.0) return NDP_CS_INVERSE;

	if (pscSys->cycleCount < cc2m->FBStartTime) return NDP_IP_RAMP_UP_NO_FB;

	ip = ctrlSys->mDiag.ipAcq.data[pscSys->cycleIndx];
	ipMax = cc2m->IPmax;
	if ((pscSys->cycleCount >= cc2m->FBStartTime) && (ip < ipMax*0.95)) return NDP_IP_RAMP_UP_FB;

	return NDP_IP_FLATTOP_RAMP_DOWN;
}



void plasCurrentControl(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *ctrlSys)
{
	int 						i,indx,t0indx;
	float						delta_ip;
	float						ipf0;			/* iPF(t=t0), null field condition */
	incrementPidController_t	dPid;
	PowerSupplyAndCoils_t		*p;
	float						multPlasCoil, Lp, Rp, Ip, delta_t, psi_pf0, alpha;

	/* plsma current control */
	indx = pscSys->cycleIndx;

	dPid.option = ctrlSys->ipControl.controller.pidOption;
	dPid.e[0] = ctrlSys->mDiag.ipAcq.data[indx-2] - ctrlSys->ipControl.target.data[indx-2];
	dPid.e[1] = ctrlSys->mDiag.ipAcq.data[indx-1] - ctrlSys->ipControl.target.data[indx-1];
	dPid.e[2] = ctrlSys->mDiag.ipAcq.data[indx] - ctrlSys->ipControl.target.data[indx];
	dPid.Ts = pscSys->controlPeriodTime;
	dPid.Kp = ctrlSys->ipControl.controller.Kp[indx];
	dPid.Ti = ctrlSys->ipControl.controller.Ti[indx];
	dPid.Td = ctrlSys->ipControl.controller.Td[indx];
	delta_ip = IncrementPidCal(&dPid);

	switch (ctrlSys->ctrlMode)
	{
		case CTRL_ISOFLUX :
			delta_ip -= ctrlSys->isofluxCtrl.deltaIp;			/* if isoFlux control */
			break;
			
		case CTRL_GAP :
			break;
			
		case CTRL_RZIP :	
		default :
		delta_ip -= ctrlSys->rControl.deltaIp;			/*  rzIp control */
	}

	/* calculate delta_Ipf, from delta_Ip:

		delta_Ipf(i) = alpha * Ipf(i,t=t0),　　极向场线圈电流只提供磁通变化，不产生磁场。

		Lp*delta_ip = alpha*SUM[Mp,c(i)]*Ipf(i,t=t0) + Rp*Ip*delta_t

	*/

	Lp		= ctrlSys->MutualMatrix.PlasLp;
	Rp		= ctrlSys->MutualMatrix.PlasRp;
	Ip		= ctrlSys->mDiag.ipAcq.data[indx];
	delta_t = pscSys->controlPeriodTime;


	/* choice t0, if  Ics(0) >1kA, t0=0, otherwisw t0=5*delta_t */
	 p = pscSys->workingPsIdAddress[PSC_CS];
	t0indx = 0;
	if (p->operationMode == PS_ONLY_NEG_GROUP) t0indx = 5;
	/*
	if (p->iAcq.data[cycleCounterToIndex(0) > 1.0)
		t0indx = 0;
	else
		t0indx = 5;
	*/

	/* calculate alpha:  Lp*delta_ip + Rp*Ip*delta_t = alpha * SUMi{MutualMatrix.PlasCoil[i]*Ipf(t0)[i]} */
	psi_pf0 = 0.0;
	for (i=PSC_CS; i<PSC_COUNT; i++)
	{
		p = pscSys->workingPsIdAddress[i];
		if ( p != NULL)
		{
			ipf0 = p->iAcq.data[cycleCounterToIndex(t0indx)];
			psi_pf0 += ipf0*ctrlSys->MutualMatrix.PlasCoil[i];			/* psi0 = SUM[Mpl,ci*ipfi(t0)] */
		}
	}
	alpha = (Lp*delta_ip + Rp*Ip*delta_t)/psi_pf0;

	/* calculate delta_ipf */
	for (i=PSC_CS; i<PSC_COUNT; i++)
	{
		p = pscSys->workingPsIdAddress[i];
		if ( p != NULL)
		{
			ipf0 = p->iAcq.data[cycleCounterToIndex(t0indx)];
			p->di += alpha*ipf0;						/* delta_ipf = alpha * ipf(t0) */ 
		}
	}

}

void currentfreedBackInit(PowerSupplyAndCoilSystem_t *pscSys)
{
	int 						i;
	PowerSupplyAndCoils_t		*p;

	/* set  delta_i = 0.0  */
	for (i=PSC_CS; i<PSC_COUNT; i++)
	{
		p = pscSys->workingPsIdAddress[i];
		if ( p != NULL) p->di = 0.0;
	}
}

void currentfreedBackControl(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *ctrlSys)
{
	int 						i,indx;
	PowerSupplyAndCoils_t		*p;
	incrementPidController_t	dPid;

	/* coil current freed back control => power supply votage */

	indx = pscSys->cycleIndx;
	/* calculate delta_i */
	for (i=PSC_CS; i<PSC_COUNT; i++)
	{
		p = pscSys->workingPsIdAddress[i];
		if ( p != NULL)
		{
			dPid.option = p->pidParameter.pidOption;
			dPid.e[0] = p->iAcq.data[indx-2] - p->iTarget.data[indx-2];
			dPid.e[1] = p->iAcq.data[indx-1] - p->iTarget.data[indx-1];
			dPid.e[2] = p->iAcq.data[indx] - p->iTarget.data[indx];
			dPid.Ts = pscSys->controlPeriodTime;
			dPid.Kp = p->pidParameter.Kp[indx];
			dPid.Ti = p->pidParameter.Ti[indx];
			dPid.Td = p->pidParameter.Td[indx];
			p->di += IncrementPidCal(&dPid);
		}
	}

}

void votageCorrectCal(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *ctrlSys)
{
	int 						i, j;
	PowerSupplyAndCoils_t		*p, *q;
	float						du;

	/*	decopling,  delta_I -> delta_u */
	for (i=PSC_CS; i<PSC_COUNT; i++)
	{
		p = pscSys->workingPsIdAddress[i];
		if ( p != NULL)
		{
			du = 0.0;
			for (j=PSC_CS; j<PSC_COUNT; j++)
			{
				q = pscSys->workingPsIdAddress[j];
				if ( q != NULL)
				{
					du += (ctrlSys->MutualMatrix.Mcoils[i][j]) * (q->di) / (pscSys->controlPeriodTime);
					if (i==j) du += (ctrlSys->MutualMatrix.Rcoils[i]) * (q->di);
				}
			}
		}
		p->du = du;
		p->sumDu += du;
	}
}

void calculatePsCtrlAngle(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *ctrlSys, bool forceNoBFCntrl)
{
	int 						i;
	PowerSupplyAndCoils_t		*p;
	powerSupplyCtrlCmd_t 		psCmd;
	float						u,ud, alphaPos,alphaNeg;
	float						pi  = 3.1415926;

	for (i=PSC_CS; i<PSC_COUNT; i++)
	{
		p = pscSys->workingPsIdAddress[i];
		if ( p != NULL)
		{
			switch (p->operationStatus)
				{
				case PS_POS_FULL_OPERATION:
				case PS_POS_PART_OPERATION:
					if (forceNoBFCntrl || (!ctrlSys->doFreedBackCntrl))
						{	
							ud = p->vTarget.data[pscSys->cycleIndx];
						}
					else
						{
							if (p->iAcq.data[pscSys->cycleIndx] > p->maxCurrent)
								
							if  (p->sumDu > p->maxDeltaU) p->sumDu = p->maxDeltaU;
							if  (p->sumDu < -p->maxDeltaU) p->sumDu = -p->maxDeltaU;
							ud = p->vTarget.data[pscSys->cycleIndx] + p->sumDu;
							/* 线圈电流 过流保护???????? */
							if (p->iAcq.data[pscSys->cycleIndx] > p->maxCurrent) ud -= p->u2l/3.0;
						}
					u = ud/(1.35*p->u2l*pscSys->VotageMGforPF/3000.0);
					psCmd.alphaPos = acos(u);
					if (psCmd.alphaPos < p->psInvAngle ) psCmd.alphaPos = p->psInvAngle;		/* 不区分整流与逆变?? */
					psCmd.cmdType = CMD_PS_POS;
					sendCtrlAngleToPs(p->id, &psCmd);
					break;
					
				case PS_CIRCLE_CURRENT_OPERATION:
					ud = p->vTarget.data[pscSys->cycleIndx];
					u = ud/(1.35*p->u2l*pscSys->VotageMGforPF/3000.0);

					alphaPos = acos(u);
					if (alphaPos < pi/3.0) alphaPos = pi/3.0;
					if (alphaPos > 2.0*pi/3.0) alphaPos = 2.0*pi/3.0;

					alphaNeg = acos(-u);
					if (alphaNeg < pi/3.0) alphaNeg = pi/3.0;
					if (alphaNeg > 2.0*pi/3.0) alphaNeg = 2.0*pi/3.0;

					alphaPos += 5.0*pi/180.0;
					alphaNeg += 5.0*pi/180.0;
					psCmd.cmdType = CMD_PS_POS_NEG;
					psCmd.alphaPos = alphaPos;
					psCmd.alphaNeg = alphaNeg;
					sendCtrlAngleToPs(p->id, &psCmd);
					break;
					
				case PS_NEG_FULL_OPERATION:
				case PS_NEG_PART_OPERATION:
					if (ctrlSys->doFreedBackCntrl)
						{	
							if  (p->sumDu > p->maxDeltaU) p->sumDu = p->maxDeltaU;
							if  (p->sumDu < -p->maxDeltaU) p->sumDu = -p->maxDeltaU;
							ud = p->vTarget.data[pscSys->cycleIndx] + p->sumDu;
							/* 线圈电流 过流保护???????? */
							if (p->iAcq.data[pscSys->cycleIndx] > -p->maxCurrent) ud += p->u2l/3.0;
						}
					else
						{
							ud = p->vTarget.data[pscSys->cycleIndx];
						}
					u = ud/(1.35*p->u2l*pscSys->VotageMGforPF/3000.0);
					psCmd.alphaNeg = acos(-u); 
					if (psCmd.alphaNeg < p->psInvAngle ) psCmd.alphaNeg = p->psInvAngle; 		/* 不区分整流与逆变?? */
					psCmd.cmdType = CMD_PS_NEG;
					sendCtrlAngleToPs(p->id, &psCmd);
					break;
					
				case PS_CLOSE_STATE:
				default:
					break;
				
				}
		}
	}
}

void sendCtrlAngleToPs(int id, powerSupplyCtrlCmd_t *psCmd)
{
	switch  (psCmd->cmdType == CMD_PS_POS)
		{
		case CMD_PS_POS:
			/* send */psCmd->alphaPos; /* to PS(id) postive set  ?????????????????*/
			break;
			
		case CMD_PS_NEG:
			/* send */psCmd->alphaNeg; /* to PS(id) negtive set  */
			break;
			
		case CMD_PS_POS_NEG:
			/* circle current operation */
			/* send */psCmd->alphaPos; /* to PS(id) postive set  */
			psCmd->alphaNeg; /* to PS(id) negtive set  */
			break;
		}
}

void horizontaPositionControl(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *ctrlSys)
{
	int						indx;
	float						delta_i;
	incrementPidController_t	dPid;
	FlDispacementCal_t		disp;
	int						iu, il, ou, ol;
	float						mult8u, mult8l, Lp, Rp, Ip, delta_t;
	/*  磁通的滤波在采集后实现*/

	/* plasma horizontal control */
	if (pscSys->workingPsIdAddress[PSC_PF8U] == NULL) return; /* */
	if (pscSys->workingPsIdAddress[PSC_PF8L] == NULL) return; /* */

	indx = pscSys->cycleIndx;

	/* plasma horizontal  dispacement */
	iu= ctrlSys->mDiag.fl_iu;
	il= ctrlSys->mDiag.fl_il;
	ou= ctrlSys->mDiag.fl_ou;
	ol= ctrlSys->mDiag.fl_ol;
	
	disp.iuPhi = ctrlSys->mDiag.fluxLoop[iu].data[indx];
	disp.ilPhi = ctrlSys->mDiag.fluxLoop[il].data[indx];
	disp.ouPhi = ctrlSys->mDiag.fluxLoop[ou].data[indx];
	disp.olPhi = ctrlSys->mDiag.fluxLoop[ol].data[indx];
	disp.ip = ctrlSys->mDiag.ipAcq.data[indx];
	horizontalDispacementCal(&disp);
	ctrlSys->plasDisp.phCal.data[indx] = disp.dh;

	/* plsma horizontal position control */
	dPid.option = ctrlSys->rControl.controller.pidOption;
	dPid.e[0] = ctrlSys->plasDisp.phCal.data[indx-2] - ctrlSys->rControl.target.data[indx-2];
	dPid.e[1] = ctrlSys->plasDisp.phCal.data[indx-1] - ctrlSys->rControl.target.data[indx-1];
	dPid.e[2] = ctrlSys->plasDisp.phCal.data[indx] - ctrlSys->rControl.target.data[indx];
	dPid.Ts = pscSys->controlPeriodTime;
	dPid.Kp = ctrlSys->rControl.controller.Kp[indx];
	dPid.Ti = ctrlSys->rControl.controller.Ti[indx];
	dPid.Td = ctrlSys->rControl.controller.Td[indx];
	delta_i = IncrementPidCal(&dPid);

	pscSys->workingPsIdAddress[PSC_PF8U]->di += delta_i;
	pscSys->workingPsIdAddress[PSC_PF8L]->di += delta_i;

	/* calculate delta_Ip, Lp*delta_Ip = (mult8u+mult8l)*delta_i + Rp*Ip*delta_t */
	mult8u	= ctrlSys->MutualMatrix.PlasCoil[PSC_PF8U];
	mult8l	= ctrlSys->MutualMatrix.PlasCoil[PSC_PF8L];
	Lp		= ctrlSys->MutualMatrix.PlasLp;
	Rp		= ctrlSys->MutualMatrix.PlasRp;
	Ip		= ctrlSys->mDiag.ipAcq.data[indx];
	delta_t = pscSys->controlPeriodTime;

	ctrlSys->rControl.deltaIp = ((mult8u+mult8l)*delta_i + Rp*Ip*delta_t)/Lp;

}


void verticalPositionControl(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *ctrlSys)
{
	int						indx;
	float						delta_i;
	incrementPidController_t	dPid;
	int						iu, il, ou, ol;
	FlDispacementCal_t		disp;
	/*  磁通的滤波在采集后实现，
	plasma vertical position control */

	if (pscSys->workingPsIdAddress[PSC_PF7U] == NULL) return; /* */
	if (pscSys->workingPsIdAddress[PSC_PF7L] == NULL) return; /* */

	indx = pscSys->cycleIndx;
	iu= ctrlSys->mDiag.fl_iu;
	il= ctrlSys->mDiag.fl_il;
	ou= ctrlSys->mDiag.fl_ou;
	ol= ctrlSys->mDiag.fl_ol;

	disp.iuPhi = ctrlSys->mDiag.fluxLoop[iu].data[indx];
	disp.ilPhi = ctrlSys->mDiag.fluxLoop[il].data[indx];
	disp.ouPhi = ctrlSys->mDiag.fluxLoop[ou].data[indx];
	disp.olPhi = ctrlSys->mDiag.fluxLoop[ol].data[indx];
	disp.ip = ctrlSys->mDiag.ipAcq.data[indx];
	verticalDispacementCal(&disp);
	ctrlSys->plasDisp.pvCal.data[indx] = disp.dv;

	/* plasma vertical position control */
	dPid.option = ctrlSys->zControl.controller.pidOption;
	dPid.e[0] = ctrlSys->plasDisp.pvCal.data[indx-2] - ctrlSys->zControl.target.data[indx-2];
	dPid.e[1] = ctrlSys->plasDisp.pvCal.data[indx-1] - ctrlSys->zControl.target.data[indx-1];
	dPid.e[2] = ctrlSys->plasDisp.pvCal.data[indx] - ctrlSys->zControl.target.data[indx];
	dPid.Ts = pscSys->controlPeriodTime;
	dPid.Kp = ctrlSys->zControl.controller.Kp[indx];
	dPid.Ti = ctrlSys->zControl.controller.Ti[indx];
	dPid.Td = ctrlSys->zControl.controller.Td[indx];
	delta_i = IncrementPidCal(&dPid);
	if (dPid.e[2] > 0.0){
			pscSys->workingPsIdAddress[PSC_PF7U]->di -= delta_i;
			pscSys->workingPsIdAddress[PSC_PF7L]->di += delta_i;
		}
	else
		{
			pscSys->workingPsIdAddress[PSC_PF7U]->di += delta_i;
			pscSys->workingPsIdAddress[PSC_PF7L]->di -= delta_i;
		}
	ctrlSys->zControl.deltaIp = 0.0;
}

void isoFluxControl(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *ctrlSys)
{
	int						i, j, indx;
	PowerSupplyAndCoils_t		*p;
	incrementPidController_t	dPid;
	float						delta_i;	
	float						delta_flux, Lp, Rp, Ip, delta_t;


	indx = pscSys->cycleIndx;
	
	for (j=0; j<ISO_FLUX_POINTS; j++)
	{
		dPid.option = ctrlSys->isofluxCtrl.pidCtroller[j].pidOption;
		dPid.e[0] = ctrlSys->isofluxCtrl.psiError[j].data[indx-2];
		dPid.e[1] = ctrlSys->isofluxCtrl.psiError[j].data[indx-1];
		dPid.e[2] = ctrlSys->isofluxCtrl.psiError[j].data[indx];
		ctrlSys->isofluxCtrl.deltaPsi[j] = IncrementPidCal(&dPid);
	}

	delta_t	= pscSys->controlPeriodTime;
	Lp		= ctrlSys->MutualMatrix.PlasLp;
	Rp		= ctrlSys->MutualMatrix.PlasRp;
	Ip		= ctrlSys->mDiag.ipAcq.data[indx];

	delta_flux = 0.0;
	for (i=PSC_PF1U; i<PSC_COUNT; i++)
	{
		p = pscSys->workingPsIdAddress[i];
		if ( p != NULL)
		{
			delta_i = 0.0;
			for (j=0; j<ISO_FLUX_POINTS; j++)
			{
				delta_i += (ctrlSys->isofluxCtrl.gainMatrix[i-PSC_PF1U][j]) * (ctrlSys->isofluxCtrl.deltaPsi[j]);
			}
			p->di += delta_i;
			/*calculate delta_psi, delta_psi = SUM{[multi]*[delta_i]} */
			delta_flux += (ctrlSys->MutualMatrix.PlasCoil[i]) * delta_i;
		}
	}
	/* calculate delta_Ip, Lp*delta_Ip = delta_flux + Rp*Ip*delta_t */
	ctrlSys->isofluxCtrl.deltaIp = (delta_flux + Rp*Ip*delta_t)/Lp;
}

int	cycleCounterToIndex(int cycleCounter)
{
	/*
		time step          :-7000............................cycleCounter......................................7000      for MAX_DISCHARGE_TIME = 14000
		waveForm data :     0    1    2    3 ......................index.......................................13999   index = 7000 + cycleCounter
	*/
	return MAX_DISCHARGE_TIME/2+cycleCounter;
}

int	indexToCycleCounter(int indx)
{
	/*
		waveForm data :     0    1    2    3 ......................index.......................................13999   for MAX_DISCHARGE_TIME = 14000
		time step          :-7000............................cycleCounter......................................7000    cycleCounter  = -7000 + index
	*/
	return -MAX_DISCHARGE_TIME/2+indx;
}

void  horizontalDispacementCal(FlDispacementCal_t *fl)
{
	float	ip;
	/*  dh = ((phi_ou-phi_iu) + (phi_od-phi_id))/2/ip */
	ip = fl->ip;
	if (ip <0.01) ip =0.01;
	fl->dh =((fl->ouPhi - fl->iuPhi) + (fl->olPhi- fl->ilPhi))/2.0/ip;
}
void  verticalDispacementCal(FlDispacementCal_t *fl)
{
	float	ip;
	/*  dv = ((phi_ou+phi_iu) - (phi_od+phi_id))/2/ip */
	ip = fl->ip;
	if (ip <0.01) ip =0.01;
	fl->dv =((fl->ouPhi + fl->iuPhi) - (fl->olPhi + fl->ilPhi))/2.0/fl->ip;
}

float IncrementPidCal(incrementPidController_t *c)
{
	/* e = Data(Measured) - Data(target), e(k-2), e(k-1),e(k) */ 
	/* pid : du(k) = Kp*Td/Ts*e(k-2) -Kp(1+2Td/Ts)*e(k-1) + Kp(1+Ts/Ti+Td/Ts)*e(k) */
	/* pid : du(2) = Kp*Td/Ts*e(0) -Kp(1+2Td/Ts)*e(1) + Kp(1+Ts/Ti+Td/Ts)*e(2) */

	switch (c->option)
	{
	case CNTRL_OPTION_P :		/* P control */
		return c->Kp*(c->e[2]-c->e[1]);

	case CNTRL_OPTION_PI :		 /* PI control */
		return -c->Kp*c->e[1]+c->Kp*(1.0+c->Ts/c->Ti)*c->e[2]; 
	
	case CNTRL_OPTION_PD :		 /* PD control */
		return  c->Kp*c->Td/c->Ts*c->e[0]-c->Kp*(1.0+2.0*c->Td/c->Ts)*c->e[1]+c->Kp*(1.0+c->Td/c->Ts)*c->e[2]; 

	case CNTRL_OPTION_PID :
	default:		/* PID control */
		return  c->Kp*c->Td/c->Ts*c->e[0] -c->Kp*(1.0+2.0*c->Td/c->Ts)*c->e[1] +c->Kp*(1.0+c->Td/c->Ts+c->Ts/c->Ti)*c->e[2];
	}
}

float RcFilter(rcFilter2m_t *f)
{
	return f->signal[1]*(f->taoRc/(1.0+f->taoRc)) + f->signal[0]/f->taoRc;
}

