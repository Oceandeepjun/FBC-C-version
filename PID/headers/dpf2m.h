#ifndef DPF2M_H_INCLUDED
#define DPF2M_H_INCLUDED
#include "macros.h"
#include <stdbool.h>
/* dischare file for HL-2M */
/* define structure */

typedef struct DpfCentralCtrl
{
	char			shotnum[8];						/* */
	bool			feedBackCmd;					/* 反馈指令 0,1  */
	int			OperationMode;					/* 运行模式 0=测试标定，1=First Plasma,2=对称模式*/
	bool			feedBackMode;					/* 反馈模式 0,1 0-du,di=0 用于调试�*/
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

#endif //DPF2M_H_INCLUDED
