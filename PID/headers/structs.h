#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#include "macros.h"

typedef struct VECNode{
    VEC_NODE_TYPE y;
    VEC_NODE_TYPE x;              //time unit: ms
}vec_Node_t;


//one of VEC curves;
typedef struct VECCURVE{
    int nodeNo;
    vec_Node_t *vec_Nodes;
}vec_Curve_t;

typedef struct VECINF{
	char Chname[3];
	short ChanNo;
	short nodeNo;
	short DataType;
	short Address;
	float XSumCheck;
	float YSumCheck;
	float Frequency;
	char Unit[3];
}vec_Inf_t;

/*---------------------VEC---------------------------*/

typedef struct waveFormDescrption
{
	/* t[i]= -MAX_DISCHARGE_TIME/2+i*dt(=Ts), (i=0,...MAX_DISCHARGE_TIME-1)
	    i = MAX_DISCHARGE_TIME/2 + t
	    t0=0 -> i = MAX_DISCHARGE_TIME/2 */

	char			channelName[3];
	float			data[MAX_DISCHARGE_TIME];
	int			startIndx;			/* ��ʼʱ������ t[Indx]= -MAX_DISCHARGE_TIME/2+Indx*dt    dt,control period */
	int			endIndx;			/* ����ʱ������ */
	short		channelId;
	char			PhysUnit[3];
}waveFormDescrption_t;

typedef struct dataAcqChannel
{
	waveFormDescrption_t			fluxLoop[NUMBER_FLUX];	/* flux loop(V) */
	waveFormDescrption_t			mProbe[NUMBER_PROBE];	/* magnetic probe(V) */
	waveFormDescrption_t			ipf1u;					/* coil current of PF1U (kA) */
	waveFormDescrption_t			ipf2u;					/* coil current of PF2U (kA) */
	waveFormDescrption_t			ipf3u;					/* coil current of PF3U (kA) */
	waveFormDescrption_t			ipf4u;					/* coil current of PF4U (kA) */
	waveFormDescrption_t			ipf5u;					/* coil current of PF5U (kA) */
	waveFormDescrption_t			ipf6u;					/* coil current of PF6U (kA) */
	waveFormDescrption_t			ipf7u;					/* coil current of PF7U (kA) */
	waveFormDescrption_t			ipf8u;					/* coil current of PF8U (kA) */
	waveFormDescrption_t			ipf1l;					/* coil current of PF1L (kA) */
	waveFormDescrption_t			ipf2l;					/* coil current of PF2L (kA) */
	waveFormDescrption_t			ipf3l;					/* coil current of PF3L (kA) */
	waveFormDescrption_t			ipf4l;					/* coil current of PF4L (kA) */
	waveFormDescrption_t			ipf5l;					/* coil current of PF5L (kA) */
	waveFormDescrption_t			ipf6l;					/* coil current of PF6L (kA) */
	waveFormDescrption_t			ipf7l;					/* coil current of PF7L (kA) */
	waveFormDescrption_t			ipf8l;					/* coil current of PF8L (kA) */
	waveFormDescrption_t			ics;						/* coil current of CS (kA) */
	waveFormDescrption_t			ip;						/* plasma  current  (kA) */
	waveFormDescrption_t			itf;						/* TF coil  current  (kA) */
}dataAcqChannel_t;

typedef struct ccTargetWaveForm
{
	waveFormDescrption_t			vpf1u;					/* power supply votage of PF1U (V) */
	waveFormDescrption_t			vpf2u;					/* power supply votage of PF2U (V) */
	waveFormDescrption_t			vpf3u;					/* power supply votage of PF3U (V) */
	waveFormDescrption_t			vpf4u;					/* power supply votage of PF4U (V) */
	waveFormDescrption_t			vpf5u;					/* power supply votage of PF5U (V) */
	waveFormDescrption_t			vpf6u;					/* power supply votage of PF6U (V) */
	waveFormDescrption_t			vpf7u;					/* power supply votage of PF7U (V) */
	waveFormDescrption_t			vpf8u;					/* power supply votage of PF8U (V) */
	waveFormDescrption_t			vpf1l;					/* power supply votage of PF1L (V) */
	waveFormDescrption_t			vpf2l;					/* power supply votage of PF2L (V) */
	waveFormDescrption_t			vpf3l;					/* power supply votage of PF3L (V) */
	waveFormDescrption_t			vpf4l;					/* power supply votage of PF4L (V) */
	waveFormDescrption_t			vpf5l;					/* power supply votage of PF5L (V) */
	waveFormDescrption_t			vpf6l;					/* power supply votage of PF6L (V) */
	waveFormDescrption_t			vpf7l;					/* power supply votage of PF7L (V) */
	waveFormDescrption_t			vpf8l;					/* power supply votage of PF8L (V) */


	waveFormDescrption_t			w1;						/* 1#2#��������ŵ�Դ��ѹ(V) */
	waveFormDescrption_t			w2;						/* 1#2#��������ŵ�Դ��ѹ(V) */
	waveFormDescrption_t			w3;						/* 3#������ŵ�Դ��ѹ(V) */
	waveFormDescrption_t			w4;						/* 4#������ŵ�Դ��ѹ(V) */

	waveFormDescrption_t			ipf1u;					/* coil current of PF1U (kA) */
	waveFormDescrption_t			ipf2u;					/* coil current of PF2U (kA) */
	waveFormDescrption_t			ipf3u;					/* coil current of PF3U (kA) */
	waveFormDescrption_t			ipf4u;					/* coil current of PF4U (kA) */
	waveFormDescrption_t			ipf5u;					/* coil current of PF5U (kA) */
	waveFormDescrption_t			ipf6u;					/* coil current of PF6U (kA) */
	waveFormDescrption_t			ipf7u;					/* coil current of PF7U (kA) */
	waveFormDescrption_t			ipf8u;					/* coil current of PF8U (kA) */
	waveFormDescrption_t			ipf1l;					/* coil current of PF1L (kA) */
	waveFormDescrption_t			ipf2l;					/* coil current of PF2L (kA) */
	waveFormDescrption_t			ipf3l;					/* coil current of PF3L (kA) */
	waveFormDescrption_t			ipf4l;					/* coil current of PF4L (kA) */
	waveFormDescrption_t			ipf5l;					/* coil current of PF5L (kA) */
	waveFormDescrption_t			ipf6l;					/* coil current of PF6L (kA) */
	waveFormDescrption_t			ipf7l;					/* coil current of PF7L (kA) */
	waveFormDescrption_t			ipf8l;					/* coil current of PF8L (kA) */

	waveFormDescrption_t			v1;						/* 1#2#��������ŷ����ѹ(V) */
	waveFormDescrption_t			v2;						/* 1#2#��������ŷ����ѹ(V) */
	waveFormDescrption_t			v3;						/* 3#������ŷ����ѹ(V) */
	waveFormDescrption_t			v4;						/* 4#������ŷ����ѹ(V) */

	waveFormDescrption_t			vcs;						/* power supply votage of CS (V) */
	waveFormDescrption_t			ics;						/* coil current of CS (kA) */

	waveFormDescrption_t			vmb;					/* ���������������ѹ (mV) */
	waveFormDescrption_t			vGP;					/* ���������ѹ (mv) */
	waveFormDescrption_t			z1;						/* 2#��������ŵ�Դ��ѹ(V) */
	waveFormDescrption_t			z2;						/* 2#��������ŵ�Դ��ѹ(V) */

	waveFormDescrption_t			ip;						/* plasma current (kA) */
	waveFormDescrption_t			ph;						/* plasma horizontal position (mm) */
	waveFormDescrption_t			pv;						/* plasma vertical position (mm) */
	waveFormDescrption_t			ne;						/* plasma density (m-3) */
}ccTargetWaveForm_t;

typedef struct pidController
{
	int			pidOption;
	float			Kp[MAX_DISCHARGE_TIME];				/* ����ϵ��*/
	float			Ti[MAX_DISCHARGE_TIME];					/* ����ʱ�䳣��(ms) */
	float			Td[MAX_DISCHARGE_TIME];				/* ΢��ʱ�䳣��(ms) */
}pidController_t;


typedef struct psVotageControll
{
	/* deltaU=PID(deltaI) */
	pidController_t			pf1u;
	pidController_t			pf2u;
	pidController_t			pf3u;
	pidController_t			pf4u;
	pidController_t			pf5u;
	pidController_t			pf6u;
	pidController_t			pf7u;
	pidController_t			pf8u;

	pidController_t			pf1l;
	pidController_t			pf2l;
	pidController_t			pf3l;
	pidController_t			pf4l;
	pidController_t			pf5l;
	pidController_t			pf6l;
	pidController_t			pf7l;
	pidController_t			pf8l;

	pidController_t			cs;

	pidController_t			mG12Secondary;		/* 1#2#��������ŵ�ѹ����*/
	pidController_t			mG12Primary;		/* 1#2#��������ŵ�ѹ����*/
	pidController_t			mG3;				/* 3#������ŵ�ѹ����*/
	pidController_t			mG4;				/* 4#������ŵ�ѹ���� */
	pidController_t			ipCtrl;				/* plasma current control */
	pidController_t			hpCtrl;				/* horizontal position control */
	pidController_t			vpCtrl;				/* vertical position control */
	pidController_t			neCtrl;				/* plasma density control */
	pidController_t			mG2Secondary;		/* 2#��������ŵ�ѹ���� */
	pidController_t			mG2Primary;		/* 2#��������ŵ�ѹ���� */
}psVotageControll_t;

/* DPF */

typedef struct DpfCentralCtrl
{
	char		shotnum[8];						/* */
	bool		feedBackCmd;					/* ����ָ�� 0,1  */
	int			OperationMode;					/* ����ģʽ 0=���Ա궨��1=First Plasma,2=�Գ�ģʽ*/
	bool		feedBackMode;					/* ����ģʽ 0,1 0-du,di=0 ���ڵ���?*/
	int			CtrlMode;						/* �����������ģʽ  0RZIP�� 1isoFlux, 2Gap */
	int			RZMode;							/* RZ ����ģʽ 0=��ͨ��̽��ģʽ��1=EFITģʽ 0,1 */
	int			IPmax;							/* ��������������ֵ 0-1200 kA */
	int			Tflattop;						/* �����������ƽ������ 0-5000ms */
	int			FBStartTime;					/* ��������ϵͳ��IP�����ߵķ�����ʼʱ�� 0-100ms */
	int			DischargeStartStep;
/* �ŵ�����ʱ�̣��Բ���Ϊ��λ��������CS��Ȧ���ʱ�̣�ֻ�ǵ�λ��ms��Ϊ����.*/
/* -3000 - -1000ms */
	int			DischargeEndStep;
/*�ŵ���յ�ʱ�̣��Բ���Ϊ��λ�����൱����ǰ��CS��Ȧ����ʱ�̡� 5000-8000ms */
}DpfCentralCtrl_t;

enum FBOperationMode
{
	FB_NO_PLASMA				= 0,			/* no plasma */
	FIRST_PLASMA				= 1,
	NORMAL_PLASMA				= 2
};

typedef struct DpfMotorGenerator
{
	bool			MG1Cmd;					/* 1#���ָ�� 0,1 */
	bool			MG2Cmd;					/* 2#���ָ�� 0,1 */
	bool			MG3Cmd;					/* 3#���ָ�� 0,1 */
	bool			MG4Cmd;					/* 4#���ָ�� 0,1 */
	int			FBW1StartTime;				/* W1������ʼʱ��(ms)-6000 - 5000 */
	int			FBW2StartTime;				/* W2������ʼʱ��(ms)-6000 - 5000 */
	int			FBW3StartTime;				/* W3������ʼʱ��(ms)-6000 - 5000 */
	int			FBW4StartTime;				/* W4������ʼʱ��(ms)-6000 - 5000 */
	int			MaxDeltaW1;				/* W1��ѹ���������(V) 0 - 50 */
	int			MaxDeltaW2;				/* W2��ѹ���������(V) 0 - 50 */
	int			MaxDeltaW3;				/* W3��ѹ���������(V) 0 - 50 */
	int			MaxDeltaW4;				/* W4��ѹ���������(V) 0 - 50 */
}DpfMotorGenerator_t;

typedef struct DpfPowerSupply
{
	bool			TFCmd;						/* TFָ�� 0,1 */
	bool			CSCmd;						/* CSָ�� 0,1 */
	bool			PF1UpperCmd;				/* PF1Upperָ�� 0,1 */
	bool			PF2UpperCmd;				/* PF2Upperָ�� 0,1 */
	bool			PF3UpperCmd;				/* PF3Upperָ�� 0,1 */
	bool			PF4UpperCmd;				/* PF4Upperָ�� 0,1 */
	bool			PF5UpperCmd;				/* PF5Upperָ�� 0,1 */
	bool			PF6UpperCmd;				/* PF6Upperָ�� 0,1 */
	bool			PF7UpperCmd;				/* PF7Upperָ�� 0,1 */
	bool			PF8UpperCmd;				/* PF8Upperָ�� 0,1 */
	bool			PF1LowerCmd;				/* PF1Lowerָ�� 0,1 */
	bool			PF2LowerCmd;				/* PF2Lowerָ�� 0,1 */
	bool			PF3LowerCmd;				/* PF3Lowerָ�� 0,1 */
	bool			PF4LowerCmd;				/* PF4Lowerָ�� 0,1 */
	bool			PF5LowerCmd;				/* PF5Lowerָ�� 0,1 */
	bool			PF6LowerCmd;				/* PF6Lowerָ�� 0,1 */
	bool			PF7LowerCmd;				/* PF7Lowerָ�� 0,1 */
	bool			PF8LowerCmd;				/* PF8Lowerָ�� 0,1 */

	int			CSOperationMode;
	/*CS�ŵ�ģʽ�� 0�ԳƷ�ʽ��1�ǶԳƷ�ʽ,������䣬�޸���,*/
	/* 2���鵱�����ã��������� 0 -10 */



	int			MGOperationMode;
	/* �������ģʽ 01�Ż�+2�Ż�+3�Ż�Ϊ�ݳ����磬4�Ż�Ϊ���򳡹��磻*/
	/* 11�Ż�+2�Ż�Ϊ�ݳ����磬3�Ż�Ϊ���򳡹��� 0 -10 */


	float			VotageMGforPF;				/* VMG Ϊ���򳡹���ķ���������ѹ(V) 1000 - 3500 */
	float			u2lCS;						/* CS��Դ�ߵ�ѹ(V) 10 - 2000 */
	float			u2lPF1Upper;				/* PF1U��Դ�ߵ�ѹ(V) 10 - 1000 */
	float			u2lPF2Upper;				/* PF2U��Դ�ߵ�ѹ(V) 10 - 1000 */
	float			u2lPF3Upper;				/* PF3U��Դ�ߵ�ѹ(V) 10 - 1000 */
	float			u2lPF4Upper;				/* PF4U��Դ�ߵ�ѹ(V) 10 - 1000 */
	float			u2lPF5Upper;				/* PF5U��Դ�ߵ�ѹ(V) 10 - 1000 */
	float			u2lPF6Upper;				/* PF6U��Դ�ߵ�ѹ(V) 10 - 1000 */
	float			u2lPF7Upper;				/* PF7U��Դ�ߵ�ѹ(V) 10 - 1000 */
	float			u2lPF8Upper;				/* PF8U��Դ�ߵ�ѹ(V) 10 - 1000 */
	float			u2lPF1Lower;				/* PF1L��Դ�ߵ�ѹ(V) 10 - 1000 */
	float			u2lPF2Lower;				/* PF2L��Դ�ߵ�ѹ(V) 10 - 1000 */
	float			u2lPF3Lower;				/* PF3L��Դ�ߵ�ѹ(V) 10 - 1000 */
	float			u2lPF4Lower;				/* PF4L��Դ�ߵ�ѹ(V) 10 - 1000 */
	float			u2lPF5Lower;				/* PF5L��Դ�ߵ�ѹ(V) 10 - 1000 */
	float			u2lPF6Lower;				/* PF6L��Դ�ߵ�ѹ(V) 10 - 1000 */
	float			u2lPF7Lower;				/* PF7L��Դ�ߵ�ѹ(V) 10 - 1000 */
	float			u2lPF8Lower;				/* PF8L��Դ�ߵ�ѹ(V) 10 - 1000 */

	float			MaxdeltaUCS;				/* CS��Դ��ѹ���������(V) */
	float			MaxdeltaUPF1Upper;			/* PF1U��Դ��ѹ���������(V) */
	float			MaxdeltaUPF2Upper;			/* PF2U��Դ��ѹ���������(V) */
	float			MaxdeltaUPF3Upper;			/* PF3U��Դ��ѹ���������(V) */
	float			MaxdeltaUPF4Upper;			/* PF4U��Դ��ѹ���������(V) */
	float			MaxdeltaUPF5Upper;			/* PF5U��Դ��ѹ���������(V) */
	float			MaxdeltaUPF6Upper;			/* PF6U��Դ��ѹ���������(V) */
	float			MaxdeltaUPF7Upper;			/* PF7U��Դ��ѹ���������(V) */
	float			MaxdeltaUPF8Upper;			/* PF8U��Դ��ѹ���������(V) */
	float			MaxdeltaUPF1Lower;			/* PF1L��Դ��ѹ���������(V) */
	float			MaxdeltaUPF2Lower;			/* PF2L��Դ��ѹ���������(V) */
	float			MaxdeltaUPF3Lower;			/* PF3L��Դ��ѹ���������(V) */
	float			MaxdeltaUPF4Lower;			/* PF4L��Դ��ѹ���������(V) */
	float			MaxdeltaUPF5Lower;			/* PF5L��Դ��ѹ���������(V) */
	float			MaxdeltaUPF6Lower;			/* PF6L��Դ��ѹ���������(V) */
	float			MaxdeltaUPF7Lower;			/* PF7L��Դ��ѹ���������(V) */
	float			MaxdeltaUPF8Lower;			/* PF8L��Դ��ѹ���������(V) */

	float			InvAngleCS;					/* CS��Դ ��䱣������ֵ -2.5 - -1 */
	float			InvAnglePF1Upper;			/* PF1U��Դ ��䱣������ֵ -2.5 - -1  */
	float			InvAnglePF2Upper;			/* PF2U��Դ ��䱣������ֵ -2.5 - -1  */
	float			InvAnglePF3Upper;			/* PF3U��Դ ��䱣������ֵ -2.5 - -1  */
	float			InvAnglePF4Upper;			/* PF4U��Դ ��䱣������ֵ -2.5 - -1  */
	float			InvAnglePF5Upper;			/* PF5U��Դ ��䱣������ֵ -2.5 - -1  */
	float			InvAnglePF6Upper;			/* PF6U��Դ ��䱣������ֵ -2.5 - -1  */
	float			InvAnglePF7Upper;			/* PF7U��Դ ��䱣������ֵ -2.5 - -1  */
	float			InvAnglePF8Upper;			/* PF8U��Դ ��䱣������ֵ -2.5 - -1  */
	float			InvAnglePF1Lower;			/* PF1L��Դ ��䱣������ֵ -2.5 - -1  */
	float			InvAnglePF2Lower;			/* PF2L��Դ ��䱣������ֵ -2.5 - -1  */
	float			InvAnglePF3Lower;			/* PF3L��Դ ��䱣������ֵ -2.5 - -1  */
	float			InvAnglePF4Lower;			/* PF4L��Դ ��䱣������ֵ -2.5 - -1  */
	float			InvAnglePF5Lower;			/* PF5L��Դ ��䱣������ֵ -2.5 - -1  */
	float			InvAnglePF6Lower;			/* PF6L��Դ ��䱣������ֵ -2.5 - -1  */
	float			InvAnglePF7Lower;			/* PF7L��Դ ��䱣������ֵ -2.5 - -1  */
	float			InvAnglePF8Lower;			/* PF8L��Դ ��䱣������ֵ -2.5 - -1  */

	float			ICSmax;						/* CS��Ȧ������(kA) -220 - 220 */
	float			IPF1UpperMax;				/* PF1U��Ȧ������(kA)   0 - 15 */
	float			IPF2UpperMax;				/* PF2U��Ȧ������(kA)   0 - 15 */
	float			IPF3UpperMax;				/* PF3U��Ȧ������(kA)   0 - 15 */
	float			IPF4UpperMax;				/* PF4U��Ȧ������(kA)   0 - 15 */
	float			IPF5UpperMax;				/* PF5U��Ȧ������(kA)  0 - 38 */
	float			IPF6UpperMax;				/* PF6U��Ȧ������(kA)  0 - 38 */
	float			IPF7UpperMax;				/* PF7U��Ȧ������(kA) 0 - 42 */
	float			IPF8UpperMax;				/* PF8U��Ȧ������(kA) 0 - 39 */
	float			IPF1LowerMax;				/* PF1L��Ȧ������(kA)  0 - 15 */
	float			IPF2LowerMax;				/* PF2L��Ȧ������(kA)  0 - 15 */
	float			IPF3LowerMax;				/* PF3L��Ȧ������(kA)  0 - 15 */
	float			IPF4LowerMax;				/* PF4L��Ȧ������(kA)  0 - 15 */
	float			IPF5LowerMax;				/* PF5L��Ȧ������(kA)  0 - 38 */
	float			IPF6LowerMax;				/* PF6L��Ȧ������(kA)  0 - 38 */
	float			IPF7LowerMax;				/* PF7L��Ȧ������(kA) 0 - 42 */
	float			IPF8LowerMax;				/* PF8L��Ȧ������(kA) 0 - 39 */

	float			IcircleCS;					/* �����л���ʱCS��Ȧ������(kA) 1-5 */
	float			IcirclePF1Upper;				/* PF1U��Ȧ�л���ʱ������(kA) 1-5 */
	float			IcirclePF2Upper;				/* PF1U��Ȧ�л���ʱ������(kA) 1-5 */
	float			IcirclePF3Upper;				/* PF2U��Ȧ�л���ʱ������(kA) 1-5 */
	float			IcirclePF4Upper;				/* PF3U��Ȧ�л���ʱ������(kA) 1-5 */
	float			IcirclePF5Upper;				/* PF4U��Ȧ�л���ʱ������(kA) 1-5 */
	float			IcirclePF6Upper;				/* PF5U��Ȧ�л���ʱ������(kA) 1-5 */
	float			IcirclePF7Upper;				/* PF6U��Ȧ�л���ʱ������(kA) 1-5 */
	float			IcirclePF8Upper;				/* PF7U��Ȧ�л���ʱ������(kA) 1-5 */
	float			IcirclePF1Lower;				/* PF1L��Ȧ�л���ʱ������(kA) 1-5 */
	float			IcirclePF2Lower;				/* PF1L��Ȧ�л���ʱ������(kA) 1-5 */
	float			IcirclePF3Lower;				/* PF1L��Ȧ�л���ʱ������(kA) 1-5 */
	float			IcirclePF4Lower;				/* PF1L��Ȧ�л���ʱ������(kA) 1-5 */
	float			IcirclePF5Lower;				/* PF1L��Ȧ�л���ʱ������(kA) 1-5 */
	float			IcirclePF6Lower;				/* PF1L��Ȧ�л���ʱ������(kA) 1-5 */
	float			IcirclePF7Lower;				/* PF1L��Ȧ�л���ʱ������(kA) 1-5 */
	float			IcirclePF8Lower;				/* PF1L��Ȧ�л���ʱ������(kA) 1-5 */
}DpfPowerSupply_t;

typedef struct DpfVacuum
{
	bool			VacuumCmd;				/* ���ָ�� 0,1 */
	bool			pelletInjectionCmd;			/* ����ָ�� 0,1 */
	bool			MbeamCmd;					/* ������ָ�� 0,1 */
	float			UneMaximum;				/* UneMaximum �ܶȷ����������ߵ�ѹ(V) 3.6- 4.6 */
	float			UneMinimum;				/* UneMinimum �ܶȷ����������͵�ѹ 2.6- 3.6 */
	float			neMinimum;					/* neMaximum �ܶȱ仯���ֵ(e13 cm-3) 0.6- 1.0 */
	int			NeFBMode;					/* NeFBMode �ܶȷ�������ģʽ 0-10 */
	int			TminDelayFB;				/* TminDelayFB �ܶȷ�����һ��������С�ȴ�ʱ��(ms) 0 -10 */
	int			smbiTminDelayFB;			/* smbiTminDelayFB �ܶȷ�����������һ��������С�ȴ�ʱ��(ms) 0 -10 */
	int			NrepFB;						/* NrepFB �ܶȷ�������ϵͳ������������� 0 - 1000 */
	int			TdelayFB;					/* TdelayFB �ܶȷ�������ϵͳ����ʱ���ӳ�ʱ��(ms) 0 - 1000 */
	int			TwidthFB;					/* TwidthFB �� �ȷ�������ϵͳ����ʱ��������(ms) 0-1000 */
	int			VheightFB;					/* VheightFB �ܶȷ�������ϵͳ����������߶�(ms) 0-1000 */
}DpfVacuum_t;

typedef struct DpfMachine
{
	bool			macCmd;					/* MACָ�� ����������ȫ 0,1 */
	bool			waterCmd;					/* ˮϵͳָ�� 0,1 */
}DpfMachine_t;

typedef struct DpfAuxHeating
{
	bool			LHCDCmd;					/* �ͻ��Ӳ�ָ�� 0,1 */
	bool			ECRHCmd;					/* ���ӻ���ָ�� 0,1 */
	bool			NBICmd;					/* ������ָ�� 0,1 */
}DpfAuxHeating_t;

typedef struct DpfDasRCfilter
{
	float			rcIp;						/* RCIP �����������RC�˲����� 0.01-0.1 */
	float			rcDh;						/* RCDH ˮƽλ��RC�˲����� 0.01-0.1 */
	float			rcDv;						/* RCDV ��ֱλ��RC�˲�����0.01-0.1 */
	float			rcNe;						/* RCNE �ܶ�RC�˲�����0.01-0.1 */
	float			rcV1;						/* RCV1 ����������ѹRC�˲�����0.01-0.1 */
	float			rcV2;						/* RCV2 ����������ѹRC�˲�����0.01-0.1 */
	float			rcV3;						/* RCV3 ����������ѹRC�˲�����0.01-0.1 */
	float			rcV4;						/* RCV4 ����������ѹRC�˲�����0.01-0.1 */
	float			rcICS;						/* rcICS ��Ȧ����RC�˲�����0.01-0.1  */
	float			rcIPF1Upper;				/* RCPF1U ��Ȧ����RC�˲�����0.01-0.1 */
	float			rcIPF2Upper;				/* RCPF2L ��Ȧ����RC�˲�����0.01-0.1 */
	float			rcIPF3Upper;				/* RCPF3U ��Ȧ����RC�˲�����0.01-0.1 */
	float			rcIPF4Upper;				/* RCPF4U ��Ȧ����RC�˲�����0.01-0.1 */
	float			rcIPF5Upper;				/* RCPF5U ��Ȧ����RC�˲�����0.01-0.1 */
	float			rcIPF6Upper;				/* RCPF6U ��Ȧ����RC�˲�����0.01-0.1 */
	float			rcIPF7Upper;				/* RCPF7U ��Ȧ����RC�˲�����0.01-0.1 */
	float			rcIPF8Upper;				/* RCPF8U ��Ȧ����RC�˲�����0.01-0.1 */
	float			rcIPF1Lower;				/* RCPF1L ��Ȧ����RC�˲�����0.01-0.1 */
	float			rcIPF2Lower;				/* RCPF2L ��Ȧ����RC�˲�����0.01-0.1 */
	float			rcIPF3Lower;				/* RCPF3L ��Ȧ����RC�˲�����0.01-0.1 */
	float			rcIPF4Lower;				/* RCPF4L ��Ȧ����RC�˲�����0.01-0.1 */
	float			rcIPF5Lower;				/* RCPF5L ��Ȧ����RC�˲�����0.01-0.1 */
	float			rcIPF6Lower;				/* RCPF6L ��Ȧ����RC�˲�����0.01-0.1 */
	float			rcIPF7Lower;				/* RCPF7L ��Ȧ����RC�˲�����0.01-0.1 */
	float			rcIPF8Lower;				/* RCPF8L ��Ȧ����RC�˲�����0.01-0.1 */
}DpfDasRCfilter_t;


/*CC2m*/


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
	ACQ_IP_ID	= PSC_COUNT,
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
	CNTRL_OPTION_PID  = 0,
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
	PS_ONLY_NEG_GROUP	= 0,
	PS_BOTH_POS_NEG_GROUP
};


enum NormalDischarePhase
{
	NDP_CS_CHAREG		= 1,
	NDP_CS_INVERSE,
	NDP_IP_RAMP_UP_NO_FB,
	NDP_IP_RAMP_UP_FB,
	NDP_IP_FLATTOP_RAMP_DOWN
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


typedef struct PlasCoilsMutualMatrix
{
	float				PlasRp;
	float				PlasLp;
	float				PlasCoil[PSC_COUNT];
	float				Rcoils[PSC_COUNT];
	float				Mcoils[PSC_COUNT][PSC_COUNT];
}PlasCoilsMutualMatrix_t;

typedef struct PowerSupplyAndCoils
{
	int						id;
	bool					cmd;					/* ָ�� 0,1 */
	float					u2l;					/*  ��Դ�ߵ�ѹ(V) */
	float					maxDeltaU;				/* ��Դ��ѹ���������(V) */
	float					psInvAngle;				/* ��Դ ��䱣������ֵ*/
	float					maxCurrent;				/* ��Ȧ������(kA)*/
	float					maxIcircle;				/* ��Ȧ�л���ʱ������(kA) 1-5 */
	float					rcI;					/*  ��Ȧ����RC�˲�����0.01-0.1 */
	float					di;
	float					du;
	float					sumDu;
	int						operationMode;
	int						operationStatus;
	waveFormDescrption_t		iAcq;
	waveFormDescrption_t		iTarget;
	waveFormDescrption_t		vTarget;
	pidController_t			pidParameter;
}PowerSupplyAndCoils_type;

typedef struct PowerSupplyAndCoilSystem
{
	PowerSupplyAndCoils_type			*psAndcoils2m[PSC_COUNT];
	PowerSupplyAndCoils_type			*readyPsAddress[PSC_COUNT];
	PowerSupplyAndCoils_type	 		*readyPsIdAddress[PSC_COUNT];		/* PF7U_adderr = readyPsIdAddress[PSC_PF7U] */
	PowerSupplyAndCoils_type	 		*workingPsIdAddress[PSC_COUNT];	/* CS_adderr =  workingPsIdAddress[PSC_CS] */
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


#endif // STRUCTS_H_INCLUDED
