/*
 * cc2m.h
 *
 *  Created on: 2016��6��25��
 *      Author: Ajun
 */

#ifndef HEADERS_CC2M_H_
#define HEADERS_CC2M_H_
#include "macros.h"
enum PowerSupplyAdCoilsID
{
	PSC_CS	= 0,
	PSC_PF1U,
	PSC_PF1L,
	PSC_PF2U,
	PSC_PF2L,
	PSC_PF3U,
	PSC_PF3L,
	PSC_PF4U,
	PSC_PF4L,
	PSC_PF5U,
	PSC_PF5L,
	PSC_PF6U,
	PSC_PF6L,
	PSC_PF7U,
	PSC_PF7L,
	PSC_PF8U,
	PSC_PF8L,
	PSC_COUNT
};

enum AcqDataID
{
	ACQ_IP_ID			= PSC_COUNT,
	ACQ_FL_IU_ID,
	ACQ_FL_IL_ID,
	ACQ_FL_OU_ID,
	ACQ_FL_OL_ID,
	ACQ_COUNT
};

enum PowerSupplyStates
{
	/* PS_UNLOCK					= 1,	*/				/* ��Դ���ڷ���״̬*/
	/* PS_LOCK,							*/			/* ��Դ���ڽ����״̬ */


	PS_CLOSE_STATE				= 1,				/* ��Դ���ڷ���״̬*/
	PS_POS_FULL_OPERATION,						/* ����ȫ����״̬ */
	PS_POS_PART_OPERATION,						/* ���鲿������״̬ */
	PS_CIRCLE_CURRENT_OPERATION,					/* ��������״̬ */
	PS_NEG_PART_OPERATION,						/* ���鲿������ */
	PS_NEG_FULL_OPERATION						/* ����ȫ���� */
};

enum PidControlOption
{
	CNTRL_OPTION_PID			= 0,
	CNTRL_OPTION_P,
	CNTRL_OPTION_PI,
	CNTRL_OPTION_PD
	/* default option PID control */
};

/*
enum PowerSupplySystemMode
{
	PSS_ONLY_NEG_GROUP				= 0,
	PSS_BOTH_POS_NEG_GROUP
}

*/
enum PowerSupplyMode
{
	PS_ONLY_NEG_GROUP				= 0,
	PS_BOTH_POS_NEG_GROUP
};


enum NormalDischarePhase
{
	NDP_CS_CHAREG			= 1,
	NDP_CS_INVERSE,
	NDP_IP_RAMP_UP_NO_FB,
	NDP_IP_RAMP_UP_FB,
	NDP_IP_FLATTOP_RAMP_DOWN,
};

enum PowerSupplySignal
{
	SIG_PS_LOCK_POS		= 0,
	SIG_PS_LOCK_NEG,
	SIG_PS_LOCK_POS_NEG,

	SIG_PS_UNLOCK_POS,
	SIG_PS_UNLOCK_NEG,
	SIG_PS_UNLOCK_POS_NEG,

	SIG_COVTER_OPEN_POS,
	SIG_COVTER_OPEN_NEG,
	SIG_COVTER_CLOSE_POS,
	SIG_COVTER_CLOSE_NEG
};

enum PowerSupplyCtrlComand
{
	CMD_PS_POS		= 1,
	CMD_PS_NEG,
	CMD_PS_POS_NEG
};

enum freedBackContrlMode
{
	CTRL_RZIP				= 0,
	CTRL_ISOFLUX,
	CTRL_GAP
};

enum ControllerPidOptionSet
{
	SET_CTRLLER_IP			= 0,
	SET_CTRLLER_R,
	SET_CTRLLER_Z,
	SET_CTRLLER_ISOFLUX
};

/* struct. for HL-2M feed back control system */
typedef struct PowerSupplyAndCoils
{
/*  dpf value */
	int						id;
	bool						cmd;					/* ָ�� 0,1 */
	float						u2l;						/*  ��Դ�ߵ�ѹ(V) */
	float						maxDeltaU;				/* ��Դ��ѹ���������(V) */
	float						psInvAngle;				/* ��Դ ��䱣������ֵ*/
	float						maxCurrent;				/* ��Ȧ������(kA)   */
	float						maxIcircle;				/* ��Ȧ�л���ʱ������(kA) 1-5 */
	float						rcI;						/*  ��Ȧ����RC�˲�����0.01-0.1 */
	float						di;
	float						du;
	float						sumDu;
//	int						positiveGroupStatus;
//	int						negtiveGroupStatus;
	int						operationMode;	/* power supply : PS_ONLY_NEG_GROUP/PS_BOTH_POS_NEG_GROUP */
	int						operationStatus;	/* six states : unlock->positive Full->postive party->cirlce current-> neg. party-> neg. full */
	waveFormDescrption_t		iAcq;		/*  acq current of coil /  (kA) */
	waveFormDescrption_t		iTarget;		/*  target current in coils/plasma current  (kA) */
	waveFormDescrption_t		vTarget;	/*  target votage (V) */
	pidController_t			pidParameter;
}PowerSupplyAndCoils_t;

typedef struct PlasCoilsMutualMatrix
{
	float				PlasRp;
	float				PlasLp;
	float				PlasCoil[PSC_COUNT];
	float				Rcoils[PSC_COUNT];
	float				Mcoils[PSC_COUNT][PSC_COUNT];
}PlasCoilsMutualMatrix_t;


typedef struct PowerSupplyAndCoilSystem
{
	PowerSupplyAndCoils_t			*psAndcoils2m[PSC_COUNT];
	PowerSupplyAndCoils_t			*readyPsAddress[PSC_COUNT];
	PowerSupplyAndCoils_t	 		*readyPsIdAddress[PSC_COUNT];		/* PF7U_adderr = readyPsIdAddress[PSC_PF7U] */
	PowerSupplyAndCoils_t	 		*workingPsIdAddress[PSC_COUNT];	/* CS_adderr =  workingPsIdAddress[PSC_CS] */
	int							readyPsCount;
	int							workingPsCount;
	float							controlPeriodTime;		/* 1ms */
	int							cycleCount;				/* -7000 : +7000 */
	int							cycleIndx;				/* waveForm_data[cycleIndx] */
	float							VotageMGforPF;			/* VMG Ϊ���򳡹���ķ���������ѹ(V) 1000 - 3500 */
}PowerSupplyAndCoilSystem_t;

typedef struct magneticDiagnostic
{
	waveFormDescrption_t			fluxLoop[NUMBER_FLUX];			/* flux loop(V) */
	int							fl_iu;	/* indx of flux loop  iu */
	int							fl_il;	/* indx of flux loop  il */
	int							fl_ou;	 /* indx of flux loop  ou */
	int							fl_ol;	 /* indx of flux loop  ol */

	waveFormDescrption_t			mProbe[NUMBER_PROBE];			/* magnetic probe(V) */
	waveFormDescrption_t			ipAcq;							/* plasma current */
	float							ipRc;
	float							acqData[ACQ_COUNT];
}magneticDiagnostic_t;

typedef struct rzIpControl
{
	waveFormDescrption_t			fluxLoop[NUMBER_FLUX];			/* flux loop(V) */
	waveFormDescrption_t			mProbe[NUMBER_PROBE];			/* magnetic probe(V) */
	waveFormDescrption_t			ipAcq;
	waveFormDescrption_t			ipTarget;						/* plasma current (kA) */
	waveFormDescrption_t			phTarget;						/* plasma horizontal position (mm) */
	waveFormDescrption_t			pvTarget;						/* plasma vertical position (mm) */
	pidController_t				ipControler;
	pidController_t				hControler;
	pidController_t				vControler;

	waveFormDescrption_t			phCal;
	waveFormDescrption_t			pvCal;
	float							rcIp;
	float							rcPh;
	float							rcPv;
	int							flouIndx;	/* indx */
	int							flolIndx;
	int							fliuIndx;
	int							flilIndx;
}rzIpControl_t;


typedef struct RfreedBackControl
{
	waveFormDescrption_t			target;						/* plasma horizontal position (mm) */
	pidController_t				controller;
	float							deltaIp;
}RfreedBackControl_t;

typedef struct ZfreedBackControl
{
	waveFormDescrption_t			target;						/* plasma horizontal position (mm) */
	pidController_t				controller;
	float							deltaIp;
}ZfreedBackControl_t;

typedef struct IpfreedBackControl
{
	waveFormDescrption_t			target;						/* plasma horizontal position (mm) */
	pidController_t				controller;
	float							deltaIp;
}IpfreedBackControl_t;

typedef struct plasmaDispacement
{
	waveFormDescrption_t			phCal;
	waveFormDescrption_t			pvCal;
	float							rcPh;
	float							rcPv;
}plasmaDispacement_t;


typedef struct isoFluxControlStruct
{
	waveFormDescrption_t			psiError[ISO_FLUX_POINTS];						/* plasma horizontal position (mm) */
	pidController_t				pidCtroller[ISO_FLUX_POINTS];
	float							gainMatrix[PSC_COUNT-1][ISO_FLUX_POINTS];		/* û��CS */
	float							deltaPsi[ISO_FLUX_POINTS];
	float							deltaIp;
}isoFluxControlStruct_t;

typedef struct dischareFailure
{
	float							ipPre;	/* ǰһʱ�̵�������������ɼ�����ʼ�ź� */
	float							ipCur;	/* ��ǰʱ�̵�������������ɼ�����ʼ�ź� */
	bool							disrupt;
	int							disrupTimes ;	/* times dip/dt <-10 kA/ms */
	bool							dischareFailure;
}dischareFailure_t;

typedef struct freedBackControl
{
	PlasCoilsMutualMatrix_t			MutualMatrix;
	magneticDiagnostic_t			mDiag;
	plasmaDispacement_t			plasDisp;
	RfreedBackControl_t			rControl;
	ZfreedBackControl_t			zControl;
	IpfreedBackControl_t			ipControl;
	isoFluxControlStruct_t			isofluxCtrl;
	int							ctrlMode;		/* plasma freed back control,rzip,isoflux */
	bool							doFreedBackCntrl;
	//float							dIpOverdt;		/* if  dIpOverdt < -10kA/ms disruption ,dischare failure */
	dischareFailure_t				disFail;
}freedBackControl_t;

typedef struct powerSupplyCtrlCmd
{
	int		cmdType;	/* cmdType = CMD_PS_POS(alphaPos) or CMD_PS_NEG(alphaPos) */
	float		alphaPos;	/*CMD_PS_POS_NEG(alphaPos, alphaNeg) */
	float		alphaNeg;
}powerSupplyCtrlCmd_t;

typedef struct incrementPidController
{
	float		e[3];
	float		Kp;
	float		Td;
	float		Ti;
	float		Ts;				/*  == 1 */
	int		option;			/* option:0-pid, 1-p, 2-pi 3-pd */
}incrementPidController_t;


typedef struct rcFilter2m
{
	float		signal[2];
	float		taoRc;		/* */
}rcFilter2m_t;

typedef struct FlDispacementCal
{
	float			iuPhi;
	float			ilPhi;
	float			ouPhi;
	float			olPhi;
	float			ip;				/* plasma current (kA) */
	float			dh;
	float			dv;
}FlDispacementCal_t;







#endif /* HEADERS_CC2M_H_ */
