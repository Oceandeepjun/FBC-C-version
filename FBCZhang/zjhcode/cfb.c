#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include "dpf2m.h"
#include "vec2m.h"
#include "cc2m.h"

enum PowerSupplyStates
{
	PS_UNLOCK					= 1,					/* 电源处于封锁状态*/
	PS_LOCK,										/* 电源处于解封锁状态 */
	POSITIVE_FULL_OPERATION,						/* 正组全运行状态 */
	POSITIVE_PART_OPERATION,						/* 正组部分运行状态 */
	CIRCLE_CURRENT_OPERATION,					/* 环流运行状态 */
	NEGTIVE_PART_OPERATION,						/* 负组部分运行 */
	NEGTIVE_FULL_OPERATION						/* 负组全运行 */
};

enum PidControlOption
{
	CNTRL_OPTION_PID			= 0,
	CNTRL_OPTION_P,
	CNTRL_OPTION_PI,
	CNTRL_OPTION_PD
	/* default option PID control */
};
#define		FLUXLOOP_IN_UPPER					1		/* */
#define		FLUXLOOP_IN_LOWER				2
#define		FLUXLOOP_OUT_UPPER				3
#define		FLUXLOOP_OUT_LOWER				4

#define		POWER_SUPPLY_LOCK		0
#define 	POWER_SUPPLY_UNLOCK		1
#define 	COVERTER_LOCK				0
#define 	COVERTER_UNLOCK			1



/*  */

/* functions */
void  horizontalDispacementCal(FlDispacementCal_t *);
void  verticalDispacementCal(FlDispacementCal_t *);

float IncrementPidCal(incrementPidController_t *);
float RcFilter(rcFilter2m_t *);
int	  cycleCounterToIndex(int );
int	  indexToCycleCounter(int );
void  pscSysInitial(PowerSupplyAndCoilSystem_t *);
void  unlockPscSys(PowerSupplyAndCoilSystem_t *);
void  lockPscSys(PowerSupplyAndCoilSystem_t *);
void  plasmalessDischarge(PowerSupplyAndCoilSystem_t *);

void  horizontaPositionControl(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);
void  verticalPositionControl(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);
void  plasmaCurrentControl(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);
void  currentfreedBackControl(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);
void  votageCorrectCal(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);
void  isoFluxControl(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);

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
	PowerSupplyAndCoils_t			psCs;
	PowerSupplyAndCoils_t			psPf1u;
	PowerSupplyAndCoils_t			psPf2u;
	PowerSupplyAndCoils_t			psPf3u;
	PowerSupplyAndCoils_t			psPf4u;
	PowerSupplyAndCoils_t			psPf5u;
	PowerSupplyAndCoils_t			psPf6u;
	PowerSupplyAndCoils_t			psPf7u;
	PowerSupplyAndCoils_t			psPf8u;
	PowerSupplyAndCoils_t			psPf1l;
	PowerSupplyAndCoils_t			psPf2l;
	PowerSupplyAndCoils_t			psPf3l;
	PowerSupplyAndCoils_t			psPf4l;
	PowerSupplyAndCoils_t			psPf5l;
	PowerSupplyAndCoils_t			psPf6l;
	PowerSupplyAndCoils_t			psPf7l;
	PowerSupplyAndCoils_t			psPf8l;

	PowerSupplyAndCoilSystem_t	pscSys;	
	freedBackControl_t			Control;


	int		cycleCounter;		/* 循环计数器，以控制周期为单位*/

	/* read 2mdpf.xml file */
	if (!dpfCentralCtrl2m.feedBackCmd) return 0;		/* 反馈不投入 */
	/* read vec 文件并插值 */
	psCs.id = PSC_CS;
	psPf1u.id = PSC_PF1U;
	psPf2u.id = PSC_PF2U;
	psPf3u.id = PSC_PF3U;
	psPf4u.id = PSC_PF4U;
	psPf5u.id = PSC_PF5U;
	psPf6u.id = PSC_PF6U;
	psPf7u.id = PSC_PF7U;
	psPf8u.id = PSC_PF8U;

	psPf1l.id = PSC_PF1L;
	psPf2l.id = PSC_PF2L;
	psPf3l.id = PSC_PF3L;
	psPf4l.id = PSC_PF4L;
	psPf5l.id = PSC_PF5L;
	psPf6l.id = PSC_PF6L;
	psPf7l.id = PSC_PF7L;
	psPf8l.id = PSC_PF8L;
	pscSys.psAndcoils2m[PSC_CS]	= &psCs;
	pscSys.psAndcoils2m[PSC_PF1U]	= &psPf1u;
	pscSys.psAndcoils2m[PSC_PF2U]	= &psPf2u;
	pscSys.psAndcoils2m[PSC_PF3U]	= &psPf3u;
	pscSys.psAndcoils2m[PSC_PF4U]	= &psPf4u;
	pscSys.psAndcoils2m[PSC_PF5U]	= &psPf5u;
	pscSys.psAndcoils2m[PSC_PF6U]	= &psPf6u;
	pscSys.psAndcoils2m[PSC_PF7U]	= &psPf7u;
	pscSys.psAndcoils2m[PSC_PF8U]	= &psPf8u;
	pscSys.psAndcoils2m[PSC_PF1L]	= &psPf1l;
	pscSys.psAndcoils2m[PSC_PF2L]	= &psPf2l;
	pscSys.psAndcoils2m[PSC_PF3L]	= &psPf3l;
	pscSys.psAndcoils2m[PSC_PF4L]	= &psPf4l;
	pscSys.psAndcoils2m[PSC_PF5L]	= &psPf5l;
	pscSys.psAndcoils2m[PSC_PF6L]	= &psPf6l;
	pscSys.psAndcoils2m[PSC_PF7L]	= &psPf7l;
	pscSys.psAndcoils2m[PSC_PF8L]	= &psPf8l;


	pscSys.controlPeriodTime		= 1.0;	/* (ms) */

	pscSysInitial(&pscSys);
	unlockPscSys(&pscSys);
	/*  反馈与时序、逻辑的关系*/
	/*  cycleCounter  */
	
	//if (cycleCounter == dpfCentralCtrl2m.DischargeStartStep)		/* Discharge Start */
	do
	{
			pscSys.cycleCount = cycleCounter;
			pscSys.cycleIndx = cycleCounterToIndex(cycleCounter);
			/* get current time from TSC ??????????  linux MRG */
			switch (dpfCentralCtrl2m.OperationMode)
				{
				case FB_NO_PLASMA:		/* plasmaless discharge, test & scaling */
					plasmalessDischarge(&pscSys);
					break;
					
				case FIRST_PLASMA:
					if (cycleCounter < dpfCentralCtrl2m.FBStartTime)
						{
							/* delta_I->delta_u ->u2 */
						}
					else
						{
						}
					break;
					
				case NORMAL_PLASMA:
					if (cycleCounter < dpfCentralCtrl2m.FBStartTime)
						{
							/* delta_I->delta_u ->u2 */
						}
					else
						{
						}

					break;
					
				default :
						;
				}
			
			
			switch (pfPs2m.pssOperationMode)
				{
				case PSS_ONLY_NEG_GROUP :
					break;
					
				case PSS_BOTH_POS_NEG_GROUP :
					/*  power status change ? */
					/* disruptin Ip->0???*/

					/* one control period */
					break;
					
				default :
					pfPs2m.pssOperationMode = PSS_BOTH_POS_NEG_GROUP;
				}
			/* check 一个控制周期的剩余时间  */
			cycleCounter++;
		}
	while(cycleCounter < dpfCentralCtrl2m->DischargeEndStep);			/* 实时程序将修改这种循环结构*/
		lockPscSys((&pscSys);
}









void pscSysInitial(PowerSupplyAndCoilSystem_t *pscSys)
{
	int i,count;
	PowerSupplyAndCoils_t	*p;
	
	count = 0;
	for(i=0; i<PSC_COUNT; i++) 
		{
			p = pscSys->psAndcoils2m[i];
			if (p->cmd)
				{
					pscSys->readyPsAddress[count++] = p;
					pscSys->readyPsIdAddress[p->id] = p;
					p->di = 0.0;
					p->du = 0.0;
					p->sumDu = 0.0;
					p->positiveGroupStatus = PS_LOCK;
					p->negtiveGroupStatus = PS_LOCK;
					p->operationStatus = PS_LOCK;
				}
			else{
					pscSys->readyPsAddress[count++] = NULL;
					pscSys->readyPsIdAddress[p->id] = NULL;
				}
				
		}
	pscSys->readyPsCount = count;
}

void unlockPscSys(PowerSupplyAndCoilSystem_t *pscSys)
{
	int					i,indx;
	PowerSupplyAndCoils_t	*p;
	
	for (i=0; i<pscSys->readyPsCount; i++)
	{
		p = pscSys->readyPsAddress[i];
		indx = p->vTarget.startIndx;
		if ( p->vTarget.data[indx+3] > 0.0)
			{
				p->operationMode = PS_BOTH_POS_NEG_GROUP;
				p->operationStatus = PS_UNLOCK;
				p->positiveGroupStatus = PS_UNLOCK;
				/* send cmd to power supply system, unlock (p->id).positiveGroup */
			}
		else
			{
				p->operationMode = PS_ONLY_NEG_GROUP;
				p->operationStatus = PS_UNLOCK;
				p->negtiveGroupStatus = PS_UNLOCK;
				/* send cmd to power supply system, unlock (p->id).negtiveGroup */
			}
	}
	

}


void lockPscSys(PowerSupplyAndCoilSystem_t *pscSys)
{
	int						i;
	PowerSupplyAndCoils_t		*p;

	for (i=0; i<pscSys->readyPsCount; i++)
	{
		p = pscSys->readyPsAddress[i];
		if (p->positiveGroupStatus == PS_UNLOCK)
			{
				/* send cmd to power supply system, unlock (p->id).positiveGroup */
			}
		if (p->negtiveGroupStatus == PS_UNLOCK)
			{
				/* send cmd to power supply system, unlock (p->id).negtiveGroup */
			}
	}
	
}


void plasmalessDischarge(PowerSupplyAndCoilSystem_t *pscSys)
{	
	int 						i;
	PowerSupplyAndCoils_t		*p;
	
	for (i=0; i<pscSys->readyPsCount; i++)
	{
		
	}
}

void plasCurrentControl(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *Control)
{
	int 						i,t0indx;
	int						indx, t0indx;
	float						delta_ip;
	float						ipf0;			/* iPF(t=t0), null field condition */
	incrementPidController_t	dPid;
	PowerSupplyAndCoils_t		*p;
	float						multPlasCoil, Lp, Rp, Ip, delta_t, psi_pf0, alpha;

	/* plsma current control */
	indx = pscSys->cycleIndx;

	dPid.option = Control->ipControl.controller.pidOption; /* = CNTRL_OPTION_PID;	 pid control */
	dPid.e[0] = Control->mDiag.ipAcq.data[indx-2] - Control->ipControl.target.data[indx-2];
	dPid.e[1] = Control->mDiag.ipAcq.data[indx-1] - Control->ipControl.target.data[indx-1];
	dPid.e[2] = Control->mDiag.ipAcq.data[indx] - Control->ipControl.target.data[indx];
	dPid.Ts = pscSys->controlPeriodTime;
	dPid.Kp = Control->ipControl.controller.Kp[indx];
	dPid.Ti = Control->ipControl.controller.Ti[indx];
	dPid.Td = Control->ipControl.controller.Td[indx];
	delta_ip = IncrementPidCal(&dPid);

	switch (Control->ctrlMode)
	{
		case CTRL_ISOFLUX :
			delta_ip -= Control->isofluxCtrl.deltaIp;			/* if isoFlux control */
			break;
			
		case CTRL_GAP :
			break;
			
		case CTRL_RZIP :	
			break;										/* default: rzIp control */
		default :
		delta_ip -= Control->rControl.deltaIp;			/*  rzIp control */
	}

	/* calculate delta_Ipf, from delta_Ip:

		delta_Ipf(i) = alpha * Ipf(i,t=t0),　　极向场线圈电流只提供磁通变化，不产生磁场。

		Lp*delta_ip = alpha*SUM[Mp,c(i)]*Ipf(i,t=t0) + Rp*Ip*delta_t

	*/

	Lp		= Control->MutualMatrix.PlasLp;
	Rp		= Control->MutualMatrix.PlasRp;
	Ip		= Control->mDiag.ipAcq.data[indx];
	delta_t = pscSys->controlPeriodTime;


	/*choice t0, if  Ics(0) >1kA, t0=0, otherwisw t0=5*delta_t */
	p = pscSys->readyPsIdAddress[PSC_CS];
	if (p->iAcq.data[cycleCounterToIndex(0) > 1.0)
		t0indx = 0;
	else
		t0indx = 5;

	/* calculate alpha */
	psi_pf0 = 0.0;
	for (i=PSC_CS; i<PSC_COUNT; i++)
	{
		p = pscSys->readyPsIdAddress[i];
		if ( p != NULL)
		{
			ipf0 = p->iAcq.data[cycleCounterToIndex(t0indx)];
			psi_pf0 += ipf0*Control->MutualMatrix.PlasCoil[i];			/* psi0 = SUM[Mpl,ci*ipfi(t0)] */
		}
	}
	alpha = (Lp*delta_ip - Rp*Ip*delta_t)/psi_pf0;

	/* calculate delta_ipf */
	for (i=PSC_CS; i<PSC_COUNT; i++)
	{
		p = pscSys->readyPsIdAddress[i];
		if ( p != NULL)
		{
			ipf0 = p->iAcq.data[cycleCounterToIndex(t0indx)];
			p->di += alpha*ipf0;						/* delta_ipf = alpha * ipf(t0) */ 
		}
	}

}

void currentfreedBackControl(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *Control)
{
	int 						i,indx;
	PowerSupplyAndCoils_t		*p;
	incrementPidController_t	dPid;

	/* coil current freed back control => power supply votage */

	indx = pscSys->cycleIndx;
	/* calculate delta_i */
	for (i=PSC_CS; i<PSC_COUNT; i++)
	{
		p = pscSys->readyPsIdAddress[i];
		if ( p != NULL)
		{
			dPid.option = p->pidParameter.pidOption;		/* = CNTRL_OPTION_PID;	 pid control */
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

void votageCorrectCal(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *Control)
{
	int 						i, j;
	PowerSupplyAndCoils_t		*p, q;
	float						du;

	/*	decopling,  delta_I -> delta_u */
	for (i=PSC_CS; i<PSC_COUNT; i++)
	{
		p = pscSys->readyPsIdAddress[i];
		if ( p != NULL)
		{
			du = 0.0;
			for (j=PSC_CS; j<PSC_COUNT; j++)
				{
					q = pscSys->readyPsIdAddress[j];
					if ( q != NULL)
						{
							du += (Control->MutualMatrix.Mcoils[i][j]) * (q->di) / (pscSys->controlPeriodTime);
							if (i==j) du += (Control->MutualMatrix.Rcoils ) * (q->di);
						}
				}
		}
		p->du = du;
		p->sumDu += du;
	}
}

void horizontaPositionControl(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *Control)
{
	int						indx;
	float						delta_i;
	incrementPidController_t	dPid;
	FlDispacementCal_t		disp;
	float						mult8u, mult8l, Lp, Rp, Ip, delta_t;
	/*  磁通的滤波在采集后实现*/

	/* plasma horizontal control */
	if (pscSys->readyPsIdAddress[PSC_PF8U] == NULL) return; /* */
	if (pscSys->readyPsIdAddress[PSC_PF8L] == NULL) return; /* */

	indx = pscSys->cycleIndx;

	/* plasma horizontal  dispacement */
	disp.iuPhi = Control->mDiag.fluxLoop[Control.fliuIndx].data[indx];
	disp.ilPhi = Control->mDiag.fluxLoop[Control->flilIndx].data[indx];
	disp.ouPhi = Control->mDiag.fluxLoop[Control->flouIndx].data[indx];
	disp.olPhi = Control->mDiag.fluxLoop[Control->flolIndx].data[indx];
	disp.ip = Control->mDiag.ipAcq.data[indx];
	horizontalDispacementCal(&disp);
	Control->plasDisp.phCal.data[indx] = disp.dh;
		/* RC filter ?????????????????????????????????????????????????????????????????/ **/

	/* plsma horizontal position control */
	dPid.option = Control->rControl.controller.pidOption; /* = CNTRL_OPTION_PID;	 pid control */
	dPid.e[0] = Control->plasDisp.phCal.data[indx-2] - Control->rControl.target.data[indx-2];
	dPid.e[1] = Control->plasDisp.phCal.data[indx-1] - Control->rControl.target.data[indx-1];
	dPid.e[2] = Control->plasDisp.phCal.data[indx] - Control->rControl.target.data[indx];
	dPid.Ts = pscSys->controlPeriodTime;
	dPid.Kp = Control->rControl.controller.Kp[indx];
	dPid.Ti = Control->rControl.controller.Ti[indx];
	dPid.Td = Control->rControl.controller.Td[indx];
	delta_i = IncrementPidCal(&dPid);

	pscSys->readyPsIdAddress[PSC_PF8U]->di += delta_i;
	pscSys->readyPsIdAddress[PSC_PF8L]->di += delta_i;

	/* calculate delta_Ip, Lp*delta_Ip = (mult8u+mult8l)*delta_i + Rp*Ip*delta_t */
	mult8u	= Control->MutualMatrix.PlasCoil[PSC_PF8U];
	mult8l	= Control->MutualMatrix.PlasCoil[PSC_PF8L];
	Lp		= Control->MutualMatrix.PlasLp;
	Rp		= Control->MutualMatrix.PlasRp;
	Ip		= Control->mDiag.ipAcq.data[indx];
	delta_t = pscSys->controlPeriodTime;

	Control->rControl.deltaIp = ((mult8u+mult8l)*delta_i + Rp*Ip*delta_t)/Lp;

}


void verticalPositionControl(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *Control)
{
	int						indx;
	float						delta_i;
	incrementPidController_t	dPid;
	FlDispacementCal_t		disp;
	/*  磁通的滤波在采集后实现， * /
	/* plasma vertical position control */

	if (pscSys->readyPsIdAddress[PSC_PF7U] == NULL) return; /* */
	if (pscSys->readyPsIdAddress[PSC_PF7L] == NULL) return; /* */

	indx = pscSys->cycleIndx;

	disp.iuPhi = Control->mDiag.fluxLoop[Control.fliuIndx].data[indx];
	disp.ilPhi = Control->mDiag.fluxLoop[Control->flilIndx].data[indx];
	disp.ouPhi = Control->mDiag.fluxLoop[Control->flouIndx].data[indx];
	disp.olPhi = Control->mDiag.fluxLoop[Control->flolIndx].data[indx];
	disp.ip = Control->mDiag.ipAcq.data[indx];
	verticalDispacementCal(&disp);
	Control->plasDisp.pvCal.data[indx] = disp.dv;
		/* RC filter ?????????????????????????????????????????????????????????????????/ **/

	/* plasma vertical position control */
	dPid.option = Control->zControl.controller.pidOption;                /* = CNTRL_OPTION_PID;	 pid control */
	dPid.e[0] = Control->plasDisp.pvCal.data[indx-2] - Control->zControl.target.data[indx-2];
	dPid.e[1] = Control->plasDisp.pvCal.data[indx-1] - Control->zControl.target.data[indx-1];
	dPid.e[2] = Control->plasDisp.pvCal.data[indx] - Control->zControl.target.data[indx];
	dPid.Ts = pscSys->controlPeriodTime;
	dPid.Kp = Control->zControl.controller.Kp[indx];
	dPid.Ti = Control->zControl.controller.Ti[indx];
	dPid.Td = Control->zControl.controller.Td[indx];
	delta_i = IncrementPidCal(&dPid);
	if (dPid.e[2] > 0.0){
			pscSys->readyPsIdAddress[PSC_PF7U]->di -= delta_i;
			pscSys->readyPsIdAddress[PSC_PF7L]->di += delta_i;
		}
	else
		{
			pscSys->readyPsIdAddress[PSC_PF7U]->di += delta_i;
			pscSys->readyPsIdAddress[PSC_PF7L]->di -= delta_i;
		}
	Control->zControl.deltaIp = 0.0;
}

void isoFluxControl(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *Control)
{
	int						i, j, indx;
	PowerSupplyAndCoils_t		*p;
	incrementPidController_t	dPid;
	float						delta_i;	
	float						delta_flux, Lp, Rp, Ip, delta_t;


	indx = pscSys->cycleIndx;
	
	for (j=0; j<ISO_FLUX_POINTS; j++)
	{
		dPid.option = Control->isofluxCtrl.pidCtroller[j].pidOption;                /* = CNTRL_OPTION_PID;	 pid control */
		dPid.e[0] = Control->isofluxCtrl.psiError[j].data[indx-2];
		dPid.e[1] = Control->isofluxCtrl.psiError[j].data[indx-1];
		dPid.e[2] = Control->isofluxCtrl.psiError[j].data[indx];
		Control->isofluxCtrl.deltaPsi[j] = IncrementPidCal(&dPid);
	}

	delta_t = pscSys->controlPeriodTime;
	Lp		= Control->MutualMatrix.PlasLp;
	Rp		= Control->MutualMatrix.PlasRp;
	Ip		= Control->mDiag.ipAcq.data[indx];

	delta_flux = 0.0
	for (i=PSC_PF1U; i<PSC_COUNT; i++)
	{
		p = pscSys->readyPsIdAddress[i];
		if ( p != NULL)
		{
			delta_i = 0.0;
			for (j=0; j<ISO_FLUX_POINTS; j++)
			{
				delta_i += (Control->isofluxCtrl.gainMatrix[i-PSC_PF1U][j]) * (Control->isofluxCtrl.deltaPsi[j]);
			}
			p->di += delta_i;
			/*calculate delta_psi, delta_psi = SUM{[multi]*[delta_i]} */
			delta_flux += (Control->MutualMatrix.PlasCoil[i]) * delta_i;
		}
	}
	/* calculate delta_Ip, Lp*delta_Ip = delta_flux + Rp*Ip*delta_t */
	Control->isofluxCtrl.deltaIp = (delta_flux + Rp*Ip*delta_t)/Lp;
}

int	cycleCounterToIndex(int cycleCounter)
{
	return MAX_DISCHARGE_TIME/2+cycleCounter;
}

int	indexToCycleCounter(int indx)
{
	return -MAX_DISCHARGE_TIME/2+indx;
}

void  horizontalDispacementCal(FlDispacementCal_t *fl)
{
	/*  dh = ((phi_ou-phi_iu) + (phi_od-phi_id))/2/ip */
	fl->dh =((fl->ouPhi - fl->iuPhi) + (fl->olPhi- fl->ilPhi))/2/fl->ip;
}
void  verticalDispacementCal(FlDispacementCal_t *fl)
{
	/*  dv = ((phi_ou+phi_iu) - (phi_od+phi_id))/2/ip */
	fl->dv =((fl->ouPhi + fl->iuPhi) - (fl->olPhi + fl->ilPhi))/2/fl->ip;
}

float IncrementPidCal(incrementPidController_t *c)
{
	/* e = Data(Measured) - Data(target), e(k-2), e(k-1),e(k) */ 
	/* pid : du(k) = Kp*Td/Ts*e(k-2) -Kp(1+2Td/Ts)*e(k-1) + Kp(1+Ts/Ti+Td/Ts)*e(k) */
	/* pid : du(2) = Kp*Td/Ts*e(0) -Kp(1+2Td/Ts)*e(1) + Kp(1+Ts/Ti+Td/Ts)*e(2) */

	switch (c->option)
	{
	case CNTRL_OPTION_P :		/* P control */
		return c->Kp*(c->e(2)-c->e[1]); 

	case CNTRL_OPTION_PI :		 /* PI control */
		return -c->Kp*c->e[1]+c->Kp*(1+c->Ts/c->Ti)*c->e[2]; 
	
	case CNTRL_OPTION_PD :		 /* PD control */
		return  c->Kp*c->Td/c->Ts*c->e[0]-c->Kp*(1.0+2.0*c->Td/c->Ts)*c->e[1]+c->Kp*(1.0+c->Td/c->Ts)*c->e[2]; 

	case CNTRL_OPTION_PID :
		;
	default:		/* PID control */
		return  c->Kp*c->Td/c->Ts*c->e[0] -c->Kp*(1.0+2.0*c->Td/c->Ts)*c->e[1] +c->Kp*(1.0+c->Td/c->Ts+c->Ts/c->Ti)*c->e[2];
	}
}

float RcFilter(rcFilter2m_t *f)
{
	return f->signal[1]*(f->taoRc/(1+f->taoRc)) + f->signal[0]/f->taoRc;
}

