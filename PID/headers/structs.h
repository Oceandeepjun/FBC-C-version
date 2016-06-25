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
	int			startIndx;			/* 开始时刻索引 t[Indx]= -MAX_DISCHARGE_TIME/2+Indx*dt    dt,control period */
	int			endIndx;			/* 结束时刻索引 */
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


	waveFormDescrption_t			w1;						/* 1#2#电机副励磁电源电压(V) */
	waveFormDescrption_t			w2;						/* 1#2#电机主励磁电源电压(V) */
	waveFormDescrption_t			w3;						/* 3#电机励磁电源电压(V) */
	waveFormDescrption_t			w4;						/* 4#电机励磁电源电压(V) */

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

	waveFormDescrption_t			v1;						/* 1#2#电机副励磁发电电压(V) */
	waveFormDescrption_t			v2;						/* 1#2#电机主励磁发电电压(V) */
	waveFormDescrption_t			v3;						/* 3#电机励磁发电电压(V) */
	waveFormDescrption_t			v4;						/* 4#电机励磁发电电压(V) */

	waveFormDescrption_t			vcs;						/* power supply votage of CS (V) */
	waveFormDescrption_t			ics;						/* coil current of CS (kA) */

	waveFormDescrption_t			vmb;					/* 分子束送气脉冲电压 (mV) */
	waveFormDescrption_t			vGP;					/* 送气脉冲电压 (mv) */
	waveFormDescrption_t			z1;						/* 2#电机副励磁电源电压(V) */
	waveFormDescrption_t			z2;						/* 2#电机主励磁电源电压(V) */

	waveFormDescrption_t			ip;						/* plasma current (kA) */
	waveFormDescrption_t			ph;						/* plasma horizontal position (mm) */
	waveFormDescrption_t			pv;						/* plasma vertical position (mm) */
	waveFormDescrption_t			ne;						/* plasma density (m-3) */
}ccTargetWaveForm_t;

typedef struct pidController
{
	int			pidOption;
	float			Kp[MAX_DISCHARGE_TIME];				/* 比例系数*/
	float			Ti[MAX_DISCHARGE_TIME];					/* 积分时间常数(ms) */
	float			Td[MAX_DISCHARGE_TIME];				/* 微分时间常数(ms) */
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

	pidController_t			mG12Secondary;		/* 1#2#电机副励磁电压控制*/
	pidController_t			mG12Primary;		/* 1#2#电机主励磁电压控制*/
	pidController_t			mG3;				/* 3#电机励磁电压控制*/
	pidController_t			mG4;				/* 4#电机励磁电压控制 */
	pidController_t			ipCtrl;				/* plasma current control */
	pidController_t			hpCtrl;				/* horizontal position control */
	pidController_t			vpCtrl;				/* vertical position control */
	pidController_t			neCtrl;				/* plasma density control */
	pidController_t			mG2Secondary;		/* 2#电机副励磁电压控制 */
	pidController_t			mG2Primary;		/* 2#电机主励磁电压控制 */
}psVotageControll_t;

/* DPF */

typedef struct DpfCentralCtrl
{
	char		shotnum[8];						/* */
	bool		feedBackCmd;					/* 反馈指令 0,1  */
	int			OperationMode;					/* 运行模式 0=测试标定，1=First Plasma,2=对称模式*/
	bool		feedBackMode;					/* 反馈模式 0,1 0-du,di=0 用于调试?*/
	int			CtrlMode;						/* 等离子体控制模式  0RZIP， 1isoFlux, 2Gap */
	int			RZMode;							/* RZ 计算模式 0=磁通磁探针模式，1=EFIT模式 0,1 */
	int			IPmax;							/* 等离子体电流最大值 0-1200 kA */
	int			Tflattop;						/* 等离子体电流平顶长度 0-5000ms */
	int			FBStartTime;					/* 反馈控制系统中IP等曲线的反馈起始时刻 0-100ms */
	int			DischargeStartStep;
/* 放电的起点时刻，以步长为单位。它等于CS线圈充磁时刻，只是单位由ms改为步长.*/
/* -3000 - -1000ms */
	int			DischargeEndStep;
/*放电的终点时刻，以步长为单位。它相当于以前的CS线圈结束时刻。 5000-8000ms */
}DpfCentralCtrl_t;

enum FBOperationMode
{
	FB_NO_PLASMA				= 0,			/* no plasma */
	FIRST_PLASMA				= 1,
	NORMAL_PLASMA				= 2
};

typedef struct DpfMotorGenerator
{
	bool			MG1Cmd;					/* 1#电机指令 0,1 */
	bool			MG2Cmd;					/* 2#电机指令 0,1 */
	bool			MG3Cmd;					/* 3#电机指令 0,1 */
	bool			MG4Cmd;					/* 4#电机指令 0,1 */
	int			FBW1StartTime;				/* W1反馈起始时刻(ms)-6000 - 5000 */
	int			FBW2StartTime;				/* W2反馈起始时刻(ms)-6000 - 5000 */
	int			FBW3StartTime;				/* W3反馈起始时刻(ms)-6000 - 5000 */
	int			FBW4StartTime;				/* W4反馈起始时刻(ms)-6000 - 5000 */
	int			MaxDeltaW1;				/* W1电压最大修正量(V) 0 - 50 */
	int			MaxDeltaW2;				/* W2电压最大修正量(V) 0 - 50 */
	int			MaxDeltaW3;				/* W3电压最大修正量(V) 0 - 50 */
	int			MaxDeltaW4;				/* W4电压最大修正量(V) 0 - 50 */
}DpfMotorGenerator_t;

typedef struct DpfPowerSupply
{
	bool			TFCmd;						/* TF指令 0,1 */
	bool			CSCmd;						/* CS指令 0,1 */
	bool			PF1UpperCmd;				/* PF1Upper指令 0,1 */
	bool			PF2UpperCmd;				/* PF2Upper指令 0,1 */
	bool			PF3UpperCmd;				/* PF3Upper指令 0,1 */
	bool			PF4UpperCmd;				/* PF4Upper指令 0,1 */
	bool			PF5UpperCmd;				/* PF5Upper指令 0,1 */
	bool			PF6UpperCmd;				/* PF6Upper指令 0,1 */
	bool			PF7UpperCmd;				/* PF7Upper指令 0,1 */
	bool			PF8UpperCmd;				/* PF8Upper指令 0,1 */
	bool			PF1LowerCmd;				/* PF1Lower指令 0,1 */
	bool			PF2LowerCmd;				/* PF2Lower指令 0,1 */
	bool			PF3LowerCmd;				/* PF3Lower指令 0,1 */
	bool			PF4LowerCmd;				/* PF4Lower指令 0,1 */
	bool			PF5LowerCmd;				/* PF5Lower指令 0,1 */
	bool			PF6LowerCmd;				/* PF6Lower指令 0,1 */
	bool			PF7LowerCmd;				/* PF7Lower指令 0,1 */
	bool			PF8LowerCmd;				/* PF8Lower指令 0,1 */

	int			CSOperationMode;
	/*CS放电模式： 0对称方式；1非对称方式,正组逆变，无负组,*/
	/* 2正组当负组用，负组整流 0 -10 */



	int			MGOperationMode;
	/* 电机工作模式 01号机+2号机+3号机为纵场供电，4号机为极向场供电；*/
	/* 11号机+2号机为纵场供电，3号机为极向场供电 0 -10 */


	float			VotageMGforPF;				/* VMG 为极向场供电的发电机发电电压(V) 1000 - 3500 */
	float			u2lCS;						/* CS电源线电压(V) 10 - 2000 */
	float			u2lPF1Upper;				/* PF1U电源线电压(V) 10 - 1000 */
	float			u2lPF2Upper;				/* PF2U电源线电压(V) 10 - 1000 */
	float			u2lPF3Upper;				/* PF3U电源线电压(V) 10 - 1000 */
	float			u2lPF4Upper;				/* PF4U电源线电压(V) 10 - 1000 */
	float			u2lPF5Upper;				/* PF5U电源线电压(V) 10 - 1000 */
	float			u2lPF6Upper;				/* PF6U电源线电压(V) 10 - 1000 */
	float			u2lPF7Upper;				/* PF7U电源线电压(V) 10 - 1000 */
	float			u2lPF8Upper;				/* PF8U电源线电压(V) 10 - 1000 */
	float			u2lPF1Lower;				/* PF1L电源线电压(V) 10 - 1000 */
	float			u2lPF2Lower;				/* PF2L电源线电压(V) 10 - 1000 */
	float			u2lPF3Lower;				/* PF3L电源线电压(V) 10 - 1000 */
	float			u2lPF4Lower;				/* PF4L电源线电压(V) 10 - 1000 */
	float			u2lPF5Lower;				/* PF5L电源线电压(V) 10 - 1000 */
	float			u2lPF6Lower;				/* PF6L电源线电压(V) 10 - 1000 */
	float			u2lPF7Lower;				/* PF7L电源线电压(V) 10 - 1000 */
	float			u2lPF8Lower;				/* PF8L电源线电压(V) 10 - 1000 */

	float			MaxdeltaUCS;				/* CS电源电压最大修正量(V) */
	float			MaxdeltaUPF1Upper;			/* PF1U电源电压最大修正量(V) */
	float			MaxdeltaUPF2Upper;			/* PF2U电源电压最大修正量(V) */
	float			MaxdeltaUPF3Upper;			/* PF3U电源电压最大修正量(V) */
	float			MaxdeltaUPF4Upper;			/* PF4U电源电压最大修正量(V) */
	float			MaxdeltaUPF5Upper;			/* PF5U电源电压最大修正量(V) */
	float			MaxdeltaUPF6Upper;			/* PF6U电源电压最大修正量(V) */
	float			MaxdeltaUPF7Upper;			/* PF7U电源电压最大修正量(V) */
	float			MaxdeltaUPF8Upper;			/* PF8U电源电压最大修正量(V) */
	float			MaxdeltaUPF1Lower;			/* PF1L电源电压最大修正量(V) */
	float			MaxdeltaUPF2Lower;			/* PF2L电源电压最大修正量(V) */
	float			MaxdeltaUPF3Lower;			/* PF3L电源电压最大修正量(V) */
	float			MaxdeltaUPF4Lower;			/* PF4L电源电压最大修正量(V) */
	float			MaxdeltaUPF5Lower;			/* PF5L电源电压最大修正量(V) */
	float			MaxdeltaUPF6Lower;			/* PF6L电源电压最大修正量(V) */
	float			MaxdeltaUPF7Lower;			/* PF7L电源电压最大修正量(V) */
	float			MaxdeltaUPF8Lower;			/* PF8L电源电压最大修正量(V) */

	float			InvAngleCS;					/* CS电源 逆变保护控制值 -2.5 - -1 */
	float			InvAnglePF1Upper;			/* PF1U电源 逆变保护控制值 -2.5 - -1  */
	float			InvAnglePF2Upper;			/* PF2U电源 逆变保护控制值 -2.5 - -1  */
	float			InvAnglePF3Upper;			/* PF3U电源 逆变保护控制值 -2.5 - -1  */
	float			InvAnglePF4Upper;			/* PF4U电源 逆变保护控制值 -2.5 - -1  */
	float			InvAnglePF5Upper;			/* PF5U电源 逆变保护控制值 -2.5 - -1  */
	float			InvAnglePF6Upper;			/* PF6U电源 逆变保护控制值 -2.5 - -1  */
	float			InvAnglePF7Upper;			/* PF7U电源 逆变保护控制值 -2.5 - -1  */
	float			InvAnglePF8Upper;			/* PF8U电源 逆变保护控制值 -2.5 - -1  */
	float			InvAnglePF1Lower;			/* PF1L电源 逆变保护控制值 -2.5 - -1  */
	float			InvAnglePF2Lower;			/* PF2L电源 逆变保护控制值 -2.5 - -1  */
	float			InvAnglePF3Lower;			/* PF3L电源 逆变保护控制值 -2.5 - -1  */
	float			InvAnglePF4Lower;			/* PF4L电源 逆变保护控制值 -2.5 - -1  */
	float			InvAnglePF5Lower;			/* PF5L电源 逆变保护控制值 -2.5 - -1  */
	float			InvAnglePF6Lower;			/* PF6L电源 逆变保护控制值 -2.5 - -1  */
	float			InvAnglePF7Lower;			/* PF7L电源 逆变保护控制值 -2.5 - -1  */
	float			InvAnglePF8Lower;			/* PF8L电源 逆变保护控制值 -2.5 - -1  */

	float			ICSmax;						/* CS线圈最大电流(kA) -220 - 220 */
	float			IPF1UpperMax;				/* PF1U线圈最大电流(kA)   0 - 15 */
	float			IPF2UpperMax;				/* PF2U线圈最大电流(kA)   0 - 15 */
	float			IPF3UpperMax;				/* PF3U线圈最大电流(kA)   0 - 15 */
	float			IPF4UpperMax;				/* PF4U线圈最大电流(kA)   0 - 15 */
	float			IPF5UpperMax;				/* PF5U线圈最大电流(kA)  0 - 38 */
	float			IPF6UpperMax;				/* PF6U线圈最大电流(kA)  0 - 38 */
	float			IPF7UpperMax;				/* PF7U线圈最大电流(kA) 0 - 42 */
	float			IPF8UpperMax;				/* PF8U线圈最大电流(kA) 0 - 39 */
	float			IPF1LowerMax;				/* PF1L线圈最大电流(kA)  0 - 15 */
	float			IPF2LowerMax;				/* PF2L线圈最大电流(kA)  0 - 15 */
	float			IPF3LowerMax;				/* PF3L线圈最大电流(kA)  0 - 15 */
	float			IPF4LowerMax;				/* PF4L线圈最大电流(kA)  0 - 15 */
	float			IPF5LowerMax;				/* PF5L线圈最大电流(kA)  0 - 38 */
	float			IPF6LowerMax;				/* PF6L线圈最大电流(kA)  0 - 38 */
	float			IPF7LowerMax;				/* PF7L线圈最大电流(kA) 0 - 42 */
	float			IPF8LowerMax;				/* PF8L线圈最大电流(kA) 0 - 39 */

	float			IcircleCS;					/* 允许有环流时CS线圈最大电流(kA) 1-5 */
	float			IcirclePF1Upper;				/* PF1U线圈有环流时最大电流(kA) 1-5 */
	float			IcirclePF2Upper;				/* PF1U线圈有环流时最大电流(kA) 1-5 */
	float			IcirclePF3Upper;				/* PF2U线圈有环流时最大电流(kA) 1-5 */
	float			IcirclePF4Upper;				/* PF3U线圈有环流时最大电流(kA) 1-5 */
	float			IcirclePF5Upper;				/* PF4U线圈有环流时最大电流(kA) 1-5 */
	float			IcirclePF6Upper;				/* PF5U线圈有环流时最大电流(kA) 1-5 */
	float			IcirclePF7Upper;				/* PF6U线圈有环流时最大电流(kA) 1-5 */
	float			IcirclePF8Upper;				/* PF7U线圈有环流时最大电流(kA) 1-5 */
	float			IcirclePF1Lower;				/* PF1L线圈有环流时最大电流(kA) 1-5 */
	float			IcirclePF2Lower;				/* PF1L线圈有环流时最大电流(kA) 1-5 */
	float			IcirclePF3Lower;				/* PF1L线圈有环流时最大电流(kA) 1-5 */
	float			IcirclePF4Lower;				/* PF1L线圈有环流时最大电流(kA) 1-5 */
	float			IcirclePF5Lower;				/* PF1L线圈有环流时最大电流(kA) 1-5 */
	float			IcirclePF6Lower;				/* PF1L线圈有环流时最大电流(kA) 1-5 */
	float			IcirclePF7Lower;				/* PF1L线圈有环流时最大电流(kA) 1-5 */
	float			IcirclePF8Lower;				/* PF1L线圈有环流时最大电流(kA) 1-5 */
}DpfPowerSupply_t;

typedef struct DpfVacuum
{
	bool			VacuumCmd;				/* 真空指令 0,1 */
	bool			pelletInjectionCmd;			/* 弹丸指令 0,1 */
	bool			MbeamCmd;					/* 分子束指令 0,1 */
	float			UneMaximum;				/* UneMaximum 密度反馈输出的最高电压(V) 3.6- 4.6 */
	float			UneMinimum;				/* UneMinimum 密度反馈输出的最低电压 2.6- 3.6 */
	float			neMinimum;					/* neMaximum 密度变化最大值(e13 cm-3) 0.6- 1.0 */
	int			NeFBMode;					/* NeFBMode 密度反馈控制模式 0-10 */
	int			TminDelayFB;				/* TminDelayFB 密度反馈下一次送气最小等待时间(ms) 0 -10 */
	int			smbiTminDelayFB;			/* smbiTminDelayFB 密度反馈分子束下一次送气最小等待时间(ms) 0 -10 */
	int			NrepFB;						/* NrepFB 密度反馈控制系统送气的脉冲个数 0 - 1000 */
	int			TdelayFB;					/* TdelayFB 密度反馈控制系统送气时的延迟时间(ms) 0 - 1000 */
	int			TwidthFB;					/* TwidthFB 密 度反馈控制系统送气时的脉冲宽度(ms) 0-1000 */
	int			VheightFB;					/* VheightFB 密度反馈控制系统送气的脉冲高度(ms) 0-1000 */
}DpfVacuum_t;

typedef struct DpfMachine
{
	bool			macCmd;					/* MAC指令 负责主机安全 0,1 */
	bool			waterCmd;					/* 水系统指令 0,1 */
}DpfMachine_t;

typedef struct DpfAuxHeating
{
	bool			LHCDCmd;					/* 低混杂波指令 0,1 */
	bool			ECRHCmd;					/* 电子回旋指令 0,1 */
	bool			NBICmd;					/* 中性束指令 0,1 */
}DpfAuxHeating_t;

typedef struct DpfDasRCfilter
{
	float			rcIp;						/* RCIP 等离子体电流RC滤波参数 0.01-0.1 */
	float			rcDh;						/* RCDH 水平位移RC滤波参数 0.01-0.1 */
	float			rcDv;						/* RCDV 垂直位移RC滤波参数0.01-0.1 */
	float			rcNe;						/* RCNE 密度RC滤波参数0.01-0.1 */
	float			rcV1;						/* RCV1 发电机发电电压RC滤波参数0.01-0.1 */
	float			rcV2;						/* RCV2 发电机发电电压RC滤波参数0.01-0.1 */
	float			rcV3;						/* RCV3 发电机发电电压RC滤波参数0.01-0.1 */
	float			rcV4;						/* RCV4 发电机发电电压RC滤波参数0.01-0.1 */
	float			rcICS;						/* rcICS 线圈电流RC滤波参数0.01-0.1  */
	float			rcIPF1Upper;				/* RCPF1U 线圈电流RC滤波参数0.01-0.1 */
	float			rcIPF2Upper;				/* RCPF2L 线圈电流RC滤波参数0.01-0.1 */
	float			rcIPF3Upper;				/* RCPF3U 线圈电流RC滤波参数0.01-0.1 */
	float			rcIPF4Upper;				/* RCPF4U 线圈电流RC滤波参数0.01-0.1 */
	float			rcIPF5Upper;				/* RCPF5U 线圈电流RC滤波参数0.01-0.1 */
	float			rcIPF6Upper;				/* RCPF6U 线圈电流RC滤波参数0.01-0.1 */
	float			rcIPF7Upper;				/* RCPF7U 线圈电流RC滤波参数0.01-0.1 */
	float			rcIPF8Upper;				/* RCPF8U 线圈电流RC滤波参数0.01-0.1 */
	float			rcIPF1Lower;				/* RCPF1L 线圈电流RC滤波参数0.01-0.1 */
	float			rcIPF2Lower;				/* RCPF2L 线圈电流RC滤波参数0.01-0.1 */
	float			rcIPF3Lower;				/* RCPF3L 线圈电流RC滤波参数0.01-0.1 */
	float			rcIPF4Lower;				/* RCPF4L 线圈电流RC滤波参数0.01-0.1 */
	float			rcIPF5Lower;				/* RCPF5L 线圈电流RC滤波参数0.01-0.1 */
	float			rcIPF6Lower;				/* RCPF6L 线圈电流RC滤波参数0.01-0.1 */
	float			rcIPF7Lower;				/* RCPF7L 线圈电流RC滤波参数0.01-0.1 */
	float			rcIPF8Lower;				/* RCPF8L 线圈电流RC滤波参数0.01-0.1 */
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
	/* PS_UNLOCK					= 1,	*/				/* 电源处于封锁状态*/
	/* PS_LOCK,							*/			/* 电源处于解封锁状态 */


	PS_CLOSE_STATE				= 1,				/* 电源处于封锁状态*/
	PS_POS_FULL_OPERATION,						/* 正组全运行状态 */
	PS_POS_PART_OPERATION,						/* 正组部分运行状态 */
	PS_CIRCLE_CURRENT_OPERATION,					/* 环流运行状态 */
	PS_NEG_PART_OPERATION,						/* 负组部分运行 */
	PS_NEG_FULL_OPERATION						/* 负组全运行 */
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
	bool					cmd;					/* 指令 0,1 */
	float					u2l;					/*  电源线电压(V) */
	float					maxDeltaU;				/* 电源电压最大修正量(V) */
	float					psInvAngle;				/* 电源 逆变保护控制值*/
	float					maxCurrent;				/* 线圈最大电流(kA)*/
	float					maxIcircle;				/* 线圈有环流时最大电流(kA) 1-5 */
	float					rcI;					/*  线圈电流RC滤波参数0.01-0.1 */
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
	float							VotageMGforPF;			/* VMG 为极向场供电的发电机发电电压(V) 1000 - 3500 */
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
	float							gainMatrix[PSC_COUNT-1][ISO_FLUX_POINTS];		/* 没有CS */
	float							deltaPsi[ISO_FLUX_POINTS];
	float							deltaIp;
}isoFluxControlStruct_t;

typedef struct dischareFailure
{
	float							ipPre;	/* 前一时刻等离子体电流，采集到的始信号 */
	float							ipCur;	/* 当前时刻等离子体电流，采集到的始信号 */
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
