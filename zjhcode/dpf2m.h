
/* dischare file for HL-2M */
/* define structure */

typedef struct DpfCentralCtrl
{
	char			shotnum[8];						/* */
	bool			feedBackCmd;					/* ����ָ�� 0,1  */
	int			OperationMode;					/* ����ģʽ 0=���Ա궨��1=First Plasma,2=�Գ�ģʽ*/
	bool			feedBackMode;					/* ����ģʽ 0,1 0-du,di=0 ���ڵ��ԡ*/
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

