#include <stdbool.h>
enum PowerSupplyAdCoilsID
{
	PSC_CS				= 0,
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
enum PowerSupplySystemMode
{
	PSS_ONLY_NEG_GROUP				= 0,
	PSS_BOTH_POS_NEG_GROUP
};

enum PowerSupplyMode
{
	PS_ONLY_NEG_GROUP				= 0,
	PS_BOTH_POS_NEG_GROUP
};

enum freedBackContrlMode
{
	CTRL_RZIP				= 0,
	CTRL_ISOFLUX,
	CTRL_GAP
};

#define ISO_FLUX_POINTS		8	

/* struct. for HL-2M feed back control system */
typedef struct PowerSupplyAndCoils
{
/*  dpf value */
	int						id;
	bool					cmd;					/* 指令 0,1 */
	float					u2l;						/*  电源线电压(V) */
	float					maxDeltaU;				/* 电源电压最大修正量(V) */
	float					psInvAngle;				/* 电源 逆变保护控制值*/
	float					maxCurrent;				/* 线圈最大电流(kA)   */
	float					maxIcircle;				/* 线圈有环流时最大电流(kA) 1-5 */
	float					rcI;						/*  线圈电流RC滤波参数0.01-0.1 */
	float					di;
	float					du;
	float					sumDu;
	int						positiveGroupStatus;
	int						negtiveGroupStatus;
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
	int							readyPsCount;
	float							controlPeriodTime;		/* 1ms */
	int							cycleCount;				/* -7000 : +7000 */
	int							cycleIndx;				/* waveForm_data[cycleIndx] */
}PowerSupplyAndCoilSystem_t;

typedef struct magneticDiagnostic
{
	waveFormDescrption_t			fluxLoop[NUMBER_FLUX];			/* flux loop(V) */
	waveFormDescrption_t			mProbe[NUMBER_PROBE];			/* magnetic probe(V) */
	waveFormDescrption_t			ipAcq;							/* plasma current */
	float							ipRc;
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
	float							gainMatrix[PSC_COUNT-1][ISO_FLUX_POINTS];		/* 没有CS */
	float							deltaPsi[ISO_FLUX_POINTS];
	float							deltaIp;
}isoFluxControlStruct_t;

typedef struct freedBackControl
{
	PlasCoilsMutualMatrix_t			MutualMatrix;
	magneticDiagnostic_t			mDiag;
	plasmaDispacement_t			plasDisp;
	RfreedBackControl_t			rControl;
	ZfreedBackControl_t			zControl;
	IpfreedBackControl_t			ipControl;
	isoFluxControlStruct_t			isofluxCtrl;
	int							ctrlMode;		/* */
	int							flouIndx;	/* indx */
	int							flolIndx;
	int							fliuIndx;
	int							flilIndx;

}freedBackControl_t;

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




