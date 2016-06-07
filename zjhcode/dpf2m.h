
/* dischare file for HL-2M */
/* define structure */

typedef struct DpfCentralCtrl
{
	char			shotnum[8];						/* */
	bool			feedBackCmd;					/* ·´À¡Ö¸Áî 0,1  */
	int			OperationMode;					/* ÔËĞĞÄ£Ê½ 0=²âÊÔ±ê¶¨£¬1=First Plasma,2=¶Ô³ÆÄ£Ê½*/
	bool			feedBackMode;					/* ·´À¡Ä£Ê½ 0,1 0-du,di=0 ÓÃÓÚµ÷ÊÔ¡*/
	int			CtrlMode;						/* µÈÀë×ÓÌå¿ØÖÆÄ£Ê½  0RZIP£¬ 1isoFlux, 2Gap */
	int			RZMode;							/* RZ ¼ÆËãÄ£Ê½ 0=´ÅÍ¨´ÅÌ½ÕëÄ£Ê½£¬1=EFITÄ£Ê½ 0,1 */
	int			IPmax;							/* µÈÀë×ÓÌåµçÁ÷×î´óÖµ 0-1200 kA */
	int			Tflattop;						/* µÈÀë×ÓÌåµçÁ÷Æ½¶¥³¤¶È 0-5000ms */
	int			FBStartTime;					/* ·´À¡¿ØÖÆÏµÍ³ÖĞIPµÈÇúÏßµÄ·´À¡ÆğÊ¼Ê±¿Ì 0-100ms */
	int			DischargeStartStep;				
/* ·ÅµçµÄÆğµãÊ±¿Ì£¬ÒÔ²½³¤Îªµ¥Î»¡£ËüµÈÓÚCSÏßÈ¦³ä´ÅÊ±¿Ì£¬Ö»ÊÇµ¥Î»ÓÉms¸ÄÎª²½³¤.*/
/* -3000 - -1000ms */
	int			DischargeEndStep;				
/*·ÅµçµÄÖÕµãÊ±¿Ì£¬ÒÔ²½³¤Îªµ¥Î»¡£ËüÏàµ±ÓÚÒÔÇ°µÄCSÏßÈ¦½áÊøÊ±¿Ì¡£ 5000-8000ms */
}DpfCentralCtrl_t;

enum FBOperationMode
{
	FB_NO_PLASMA				= 0,			/* no plasma */
	FIRST_PLASMA				= 1,						
	NORMAL_PLASMA				= 2		
};

typedef struct DpfMotorGenerator
{
	bool			MG1Cmd;					/* 1#µç»úÖ¸Áî 0,1 */
	bool			MG2Cmd;					/* 2#µç»úÖ¸Áî 0,1 */
	bool			MG3Cmd;					/* 3#µç»úÖ¸Áî 0,1 */
	bool			MG4Cmd;					/* 4#µç»úÖ¸Áî 0,1 */
	int			FBW1StartTime;				/* W1·´À¡ÆğÊ¼Ê±¿Ì(ms)-6000 - 5000 */
	int			FBW2StartTime;				/* W2·´À¡ÆğÊ¼Ê±¿Ì(ms)-6000 - 5000 */
	int			FBW3StartTime;				/* W3·´À¡ÆğÊ¼Ê±¿Ì(ms)-6000 - 5000 */
	int			FBW4StartTime;				/* W4·´À¡ÆğÊ¼Ê±¿Ì(ms)-6000 - 5000 */
	int			MaxDeltaW1;				/* W1µçÑ¹×î´óĞŞÕıÁ¿(V) 0 - 50 */
	int			MaxDeltaW2;				/* W2µçÑ¹×î´óĞŞÕıÁ¿(V) 0 - 50 */
	int			MaxDeltaW3;				/* W3µçÑ¹×î´óĞŞÕıÁ¿(V) 0 - 50 */
	int			MaxDeltaW4;				/* W4µçÑ¹×î´óĞŞÕıÁ¿(V) 0 - 50 */
}DpfMotorGenerator_t;

typedef struct DpfPowerSupply
{
	bool			TFCmd;						/* TFÖ¸Áî 0,1 */
	bool			CSCmd;						/* CSÖ¸Áî 0,1 */
	bool			PF1UpperCmd;				/* PF1UpperÖ¸Áî 0,1 */
	bool			PF2UpperCmd;				/* PF2UpperÖ¸Áî 0,1 */
	bool			PF3UpperCmd;				/* PF3UpperÖ¸Áî 0,1 */
	bool			PF4UpperCmd;				/* PF4UpperÖ¸Áî 0,1 */
	bool			PF5UpperCmd;				/* PF5UpperÖ¸Áî 0,1 */
	bool			PF6UpperCmd;				/* PF6UpperÖ¸Áî 0,1 */
	bool			PF7UpperCmd;				/* PF7UpperÖ¸Áî 0,1 */
	bool			PF8UpperCmd;				/* PF8UpperÖ¸Áî 0,1 */
	bool			PF1LowerCmd;				/* PF1LowerÖ¸Áî 0,1 */
	bool			PF2LowerCmd;				/* PF2LowerÖ¸Áî 0,1 */
	bool			PF3LowerCmd;				/* PF3LowerÖ¸Áî 0,1 */
	bool			PF4LowerCmd;				/* PF4LowerÖ¸Áî 0,1 */
	bool			PF5LowerCmd;				/* PF5LowerÖ¸Áî 0,1 */
	bool			PF6LowerCmd;				/* PF6LowerÖ¸Áî 0,1 */
	bool			PF7LowerCmd;				/* PF7LowerÖ¸Áî 0,1 */
	bool			PF8LowerCmd;				/* PF8LowerÖ¸Áî 0,1 */

	int			CSOperationMode;
	/*CS·ÅµçÄ£Ê½£º 0¶Ô³Æ·½Ê½£»1·Ç¶Ô³Æ·½Ê½,Õı×éÄæ±ä£¬ÎŞ¸º×é,*/
	/* 2Õı×éµ±¸º×éÓÃ£¬¸º×éÕûÁ÷ 0 -10 */


	
	int			MGOperationMode;
	/* µç»ú¹¤×÷Ä£Ê½ 01ºÅ»ú+2ºÅ»ú+3ºÅ»úÎª×İ³¡¹©µç£¬4ºÅ»úÎª¼«Ïò³¡¹©µç£»*/
	/* 11ºÅ»ú+2ºÅ»úÎª×İ³¡¹©µç£¬3ºÅ»úÎª¼«Ïò³¡¹©µç 0 -10 */

	
	float			VotageMGforPF;				/* VMG Îª¼«Ïò³¡¹©µçµÄ·¢µç»ú·¢µçµçÑ¹(V) 1000 - 3500 */
	float			u2lCS;						/* CSµçÔ´ÏßµçÑ¹(V) 10 - 2000 */
	float			u2lPF1Upper;				/* PF1UµçÔ´ÏßµçÑ¹(V) 10 - 1000 */
	float			u2lPF2Upper;				/* PF2UµçÔ´ÏßµçÑ¹(V) 10 - 1000 */
	float			u2lPF3Upper;				/* PF3UµçÔ´ÏßµçÑ¹(V) 10 - 1000 */
	float			u2lPF4Upper;				/* PF4UµçÔ´ÏßµçÑ¹(V) 10 - 1000 */
	float			u2lPF5Upper;				/* PF5UµçÔ´ÏßµçÑ¹(V) 10 - 1000 */
	float			u2lPF6Upper;				/* PF6UµçÔ´ÏßµçÑ¹(V) 10 - 1000 */
	float			u2lPF7Upper;				/* PF7UµçÔ´ÏßµçÑ¹(V) 10 - 1000 */
	float			u2lPF8Upper;				/* PF8UµçÔ´ÏßµçÑ¹(V) 10 - 1000 */
	float			u2lPF1Lower;				/* PF1LµçÔ´ÏßµçÑ¹(V) 10 - 1000 */
	float			u2lPF2Lower;				/* PF2LµçÔ´ÏßµçÑ¹(V) 10 - 1000 */
	float			u2lPF3Lower;				/* PF3LµçÔ´ÏßµçÑ¹(V) 10 - 1000 */
	float			u2lPF4Lower;				/* PF4LµçÔ´ÏßµçÑ¹(V) 10 - 1000 */
	float			u2lPF5Lower;				/* PF5LµçÔ´ÏßµçÑ¹(V) 10 - 1000 */
	float			u2lPF6Lower;				/* PF6LµçÔ´ÏßµçÑ¹(V) 10 - 1000 */
	float			u2lPF7Lower;				/* PF7LµçÔ´ÏßµçÑ¹(V) 10 - 1000 */
	float			u2lPF8Lower;				/* PF8LµçÔ´ÏßµçÑ¹(V) 10 - 1000 */
	
	float			MaxdeltaUCS;				/* CSµçÔ´µçÑ¹×î´óĞŞÕıÁ¿(V) */
	float			MaxdeltaUPF1Upper;			/* PF1UµçÔ´µçÑ¹×î´óĞŞÕıÁ¿(V) */
	float			MaxdeltaUPF2Upper;			/* PF2UµçÔ´µçÑ¹×î´óĞŞÕıÁ¿(V) */
	float			MaxdeltaUPF3Upper;			/* PF3UµçÔ´µçÑ¹×î´óĞŞÕıÁ¿(V) */
	float			MaxdeltaUPF4Upper;			/* PF4UµçÔ´µçÑ¹×î´óĞŞÕıÁ¿(V) */
	float			MaxdeltaUPF5Upper;			/* PF5UµçÔ´µçÑ¹×î´óĞŞÕıÁ¿(V) */
	float			MaxdeltaUPF6Upper;			/* PF6UµçÔ´µçÑ¹×î´óĞŞÕıÁ¿(V) */
	float			MaxdeltaUPF7Upper;			/* PF7UµçÔ´µçÑ¹×î´óĞŞÕıÁ¿(V) */
	float			MaxdeltaUPF8Upper;			/* PF8UµçÔ´µçÑ¹×î´óĞŞÕıÁ¿(V) */
	float			MaxdeltaUPF1Lower;			/* PF1LµçÔ´µçÑ¹×î´óĞŞÕıÁ¿(V) */
	float			MaxdeltaUPF2Lower;			/* PF2LµçÔ´µçÑ¹×î´óĞŞÕıÁ¿(V) */
	float			MaxdeltaUPF3Lower;			/* PF3LµçÔ´µçÑ¹×î´óĞŞÕıÁ¿(V) */
	float			MaxdeltaUPF4Lower;			/* PF4LµçÔ´µçÑ¹×î´óĞŞÕıÁ¿(V) */
	float			MaxdeltaUPF5Lower;			/* PF5LµçÔ´µçÑ¹×î´óĞŞÕıÁ¿(V) */
	float			MaxdeltaUPF6Lower;			/* PF6LµçÔ´µçÑ¹×î´óĞŞÕıÁ¿(V) */
	float			MaxdeltaUPF7Lower;			/* PF7LµçÔ´µçÑ¹×î´óĞŞÕıÁ¿(V) */
	float			MaxdeltaUPF8Lower;			/* PF8LµçÔ´µçÑ¹×î´óĞŞÕıÁ¿(V) */

	float			InvAngleCS;					/* CSµçÔ´ Äæ±ä±£»¤¿ØÖÆÖµ -2.5 - -1 */
	float			InvAnglePF1Upper;			/* PF1UµçÔ´ Äæ±ä±£»¤¿ØÖÆÖµ -2.5 - -1  */
	float			InvAnglePF2Upper;			/* PF2UµçÔ´ Äæ±ä±£»¤¿ØÖÆÖµ -2.5 - -1  */
	float			InvAnglePF3Upper;			/* PF3UµçÔ´ Äæ±ä±£»¤¿ØÖÆÖµ -2.5 - -1  */
	float			InvAnglePF4Upper;			/* PF4UµçÔ´ Äæ±ä±£»¤¿ØÖÆÖµ -2.5 - -1  */
	float			InvAnglePF5Upper;			/* PF5UµçÔ´ Äæ±ä±£»¤¿ØÖÆÖµ -2.5 - -1  */
	float			InvAnglePF6Upper;			/* PF6UµçÔ´ Äæ±ä±£»¤¿ØÖÆÖµ -2.5 - -1  */
	float			InvAnglePF7Upper;			/* PF7UµçÔ´ Äæ±ä±£»¤¿ØÖÆÖµ -2.5 - -1  */
	float			InvAnglePF8Upper;			/* PF8UµçÔ´ Äæ±ä±£»¤¿ØÖÆÖµ -2.5 - -1  */
	float			InvAnglePF1Lower;			/* PF1LµçÔ´ Äæ±ä±£»¤¿ØÖÆÖµ -2.5 - -1  */
	float			InvAnglePF2Lower;			/* PF2LµçÔ´ Äæ±ä±£»¤¿ØÖÆÖµ -2.5 - -1  */
	float			InvAnglePF3Lower;			/* PF3LµçÔ´ Äæ±ä±£»¤¿ØÖÆÖµ -2.5 - -1  */
	float			InvAnglePF4Lower;			/* PF4LµçÔ´ Äæ±ä±£»¤¿ØÖÆÖµ -2.5 - -1  */
	float			InvAnglePF5Lower;			/* PF5LµçÔ´ Äæ±ä±£»¤¿ØÖÆÖµ -2.5 - -1  */
	float			InvAnglePF6Lower;			/* PF6LµçÔ´ Äæ±ä±£»¤¿ØÖÆÖµ -2.5 - -1  */
	float			InvAnglePF7Lower;			/* PF7LµçÔ´ Äæ±ä±£»¤¿ØÖÆÖµ -2.5 - -1  */
	float			InvAnglePF8Lower;			/* PF8LµçÔ´ Äæ±ä±£»¤¿ØÖÆÖµ -2.5 - -1  */

	float			ICSmax;						/* CSÏßÈ¦×î´óµçÁ÷(kA) -220 - 220 */
	float			IPF1UpperMax;				/* PF1UÏßÈ¦×î´óµçÁ÷(kA)   0 - 15 */
	float			IPF2UpperMax;				/* PF2UÏßÈ¦×î´óµçÁ÷(kA)   0 - 15 */
	float			IPF3UpperMax;				/* PF3UÏßÈ¦×î´óµçÁ÷(kA)   0 - 15 */
	float			IPF4UpperMax;				/* PF4UÏßÈ¦×î´óµçÁ÷(kA)   0 - 15 */
	float			IPF5UpperMax;				/* PF5UÏßÈ¦×î´óµçÁ÷(kA)  0 - 38 */
	float			IPF6UpperMax;				/* PF6UÏßÈ¦×î´óµçÁ÷(kA)  0 - 38 */
	float			IPF7UpperMax;				/* PF7UÏßÈ¦×î´óµçÁ÷(kA) 0 - 42 */
	float			IPF8UpperMax;				/* PF8UÏßÈ¦×î´óµçÁ÷(kA) 0 - 39 */
	float			IPF1LowerMax;				/* PF1LÏßÈ¦×î´óµçÁ÷(kA)  0 - 15 */
	float			IPF2LowerMax;				/* PF2LÏßÈ¦×î´óµçÁ÷(kA)  0 - 15 */
	float			IPF3LowerMax;				/* PF3LÏßÈ¦×î´óµçÁ÷(kA)  0 - 15 */
	float			IPF4LowerMax;				/* PF4LÏßÈ¦×î´óµçÁ÷(kA)  0 - 15 */
	float			IPF5LowerMax;				/* PF5LÏßÈ¦×î´óµçÁ÷(kA)  0 - 38 */
	float			IPF6LowerMax;				/* PF6LÏßÈ¦×î´óµçÁ÷(kA)  0 - 38 */
	float			IPF7LowerMax;				/* PF7LÏßÈ¦×î´óµçÁ÷(kA) 0 - 42 */
	float			IPF8LowerMax;				/* PF8LÏßÈ¦×î´óµçÁ÷(kA) 0 - 39 */

	float			IcircleCS;					/* ÔÊĞíÓĞ»·Á÷Ê±CSÏßÈ¦×î´óµçÁ÷(kA) 1-5 */
	float			IcirclePF1Upper;				/* PF1UÏßÈ¦ÓĞ»·Á÷Ê±×î´óµçÁ÷(kA) 1-5 */
	float			IcirclePF2Upper;				/* PF1UÏßÈ¦ÓĞ»·Á÷Ê±×î´óµçÁ÷(kA) 1-5 */
	float			IcirclePF3Upper;				/* PF2UÏßÈ¦ÓĞ»·Á÷Ê±×î´óµçÁ÷(kA) 1-5 */
	float			IcirclePF4Upper;				/* PF3UÏßÈ¦ÓĞ»·Á÷Ê±×î´óµçÁ÷(kA) 1-5 */
	float			IcirclePF5Upper;				/* PF4UÏßÈ¦ÓĞ»·Á÷Ê±×î´óµçÁ÷(kA) 1-5 */
	float			IcirclePF6Upper;				/* PF5UÏßÈ¦ÓĞ»·Á÷Ê±×î´óµçÁ÷(kA) 1-5 */
	float			IcirclePF7Upper;				/* PF6UÏßÈ¦ÓĞ»·Á÷Ê±×î´óµçÁ÷(kA) 1-5 */
	float			IcirclePF8Upper;				/* PF7UÏßÈ¦ÓĞ»·Á÷Ê±×î´óµçÁ÷(kA) 1-5 */
	float			IcirclePF1Lower;				/* PF1LÏßÈ¦ÓĞ»·Á÷Ê±×î´óµçÁ÷(kA) 1-5 */
	float			IcirclePF2Lower;				/* PF1LÏßÈ¦ÓĞ»·Á÷Ê±×î´óµçÁ÷(kA) 1-5 */
	float			IcirclePF3Lower;				/* PF1LÏßÈ¦ÓĞ»·Á÷Ê±×î´óµçÁ÷(kA) 1-5 */
	float			IcirclePF4Lower;				/* PF1LÏßÈ¦ÓĞ»·Á÷Ê±×î´óµçÁ÷(kA) 1-5 */
	float			IcirclePF5Lower;				/* PF1LÏßÈ¦ÓĞ»·Á÷Ê±×î´óµçÁ÷(kA) 1-5 */
	float			IcirclePF6Lower;				/* PF1LÏßÈ¦ÓĞ»·Á÷Ê±×î´óµçÁ÷(kA) 1-5 */
	float			IcirclePF7Lower;				/* PF1LÏßÈ¦ÓĞ»·Á÷Ê±×î´óµçÁ÷(kA) 1-5 */
	float			IcirclePF8Lower;				/* PF1LÏßÈ¦ÓĞ»·Á÷Ê±×î´óµçÁ÷(kA) 1-5 */
}DpfPowerSupply_t;

typedef struct DpfVacuum
{
	bool			VacuumCmd;				/* Õæ¿ÕÖ¸Áî 0,1 */
	bool			pelletInjectionCmd;			/* µ¯ÍèÖ¸Áî 0,1 */
	bool			MbeamCmd;					/* ·Ö×ÓÊøÖ¸Áî 0,1 */
	float			UneMaximum;				/* UneMaximum ÃÜ¶È·´À¡Êä³öµÄ×î¸ßµçÑ¹(V) 3.6- 4.6 */
	float			UneMinimum;				/* UneMinimum ÃÜ¶È·´À¡Êä³öµÄ×îµÍµçÑ¹ 2.6- 3.6 */
	float			neMinimum;					/* neMaximum ÃÜ¶È±ä»¯×î´óÖµ(e13 cm-3) 0.6- 1.0 */
	int			NeFBMode;					/* NeFBMode ÃÜ¶È·´À¡¿ØÖÆÄ£Ê½ 0-10 */
	int			TminDelayFB;				/* TminDelayFB ÃÜ¶È·´À¡ÏÂÒ»´ÎËÍÆø×îĞ¡µÈ´ıÊ±¼ä(ms) 0 -10 */
	int			smbiTminDelayFB;			/* smbiTminDelayFB ÃÜ¶È·´À¡·Ö×ÓÊøÏÂÒ»´ÎËÍÆø×îĞ¡µÈ´ıÊ±¼ä(ms) 0 -10 */
	int			NrepFB;						/* NrepFB ÃÜ¶È·´À¡¿ØÖÆÏµÍ³ËÍÆøµÄÂö³å¸öÊı 0 - 1000 */
	int			TdelayFB;					/* TdelayFB ÃÜ¶È·´À¡¿ØÖÆÏµÍ³ËÍÆøÊ±µÄÑÓ³ÙÊ±¼ä(ms) 0 - 1000 */
	int			TwidthFB;					/* TwidthFB ÃÜ ¶È·´À¡¿ØÖÆÏµÍ³ËÍÆøÊ±µÄÂö³å¿í¶È(ms) 0-1000 */
	int			VheightFB;					/* VheightFB ÃÜ¶È·´À¡¿ØÖÆÏµÍ³ËÍÆøµÄÂö³å¸ß¶È(ms) 0-1000 */
}DpfVacuum_t;

typedef struct DpfMachine
{
	bool			macCmd;					/* MACÖ¸Áî ¸ºÔğÖ÷»ú°²È« 0,1 */
	bool			waterCmd;					/* Ë®ÏµÍ³Ö¸Áî 0,1 */
}DpfMachine_t;

typedef struct DpfAuxHeating
{
	bool			LHCDCmd;					/* µÍ»ìÔÓ²¨Ö¸Áî 0,1 */
	bool			ECRHCmd;					/* µç×Ó»ØĞıÖ¸Áî 0,1 */		
	bool			NBICmd;					/* ÖĞĞÔÊøÖ¸Áî 0,1 */		
}DpfAuxHeating_t;

typedef struct DpfDasRCfilter
{
	float			rcIp;						/* RCIP µÈÀë×ÓÌåµçÁ÷RCÂË²¨²ÎÊı 0.01-0.1 */
	float			rcDh;						/* RCDH Ë®Æ½Î»ÒÆRCÂË²¨²ÎÊı 0.01-0.1 */
	float			rcDv;						/* RCDV ´¹Ö±Î»ÒÆRCÂË²¨²ÎÊı0.01-0.1 */
	float			rcNe;						/* RCNE ÃÜ¶ÈRCÂË²¨²ÎÊı0.01-0.1 */
	float			rcV1;						/* RCV1 ·¢µç»ú·¢µçµçÑ¹RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcV2;						/* RCV2 ·¢µç»ú·¢µçµçÑ¹RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcV3;						/* RCV3 ·¢µç»ú·¢µçµçÑ¹RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcV4;						/* RCV4 ·¢µç»ú·¢µçµçÑ¹RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcICS;						/* rcICS ÏßÈ¦µçÁ÷RCÂË²¨²ÎÊı0.01-0.1  */
	float			rcIPF1Upper;				/* RCPF1U ÏßÈ¦µçÁ÷RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcIPF2Upper;				/* RCPF2L ÏßÈ¦µçÁ÷RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcIPF3Upper;				/* RCPF3U ÏßÈ¦µçÁ÷RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcIPF4Upper;				/* RCPF4U ÏßÈ¦µçÁ÷RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcIPF5Upper;				/* RCPF5U ÏßÈ¦µçÁ÷RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcIPF6Upper;				/* RCPF6U ÏßÈ¦µçÁ÷RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcIPF7Upper;				/* RCPF7U ÏßÈ¦µçÁ÷RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcIPF8Upper;				/* RCPF8U ÏßÈ¦µçÁ÷RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcIPF1Lower;				/* RCPF1L ÏßÈ¦µçÁ÷RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcIPF2Lower;				/* RCPF2L ÏßÈ¦µçÁ÷RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcIPF3Lower;				/* RCPF3L ÏßÈ¦µçÁ÷RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcIPF4Lower;				/* RCPF4L ÏßÈ¦µçÁ÷RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcIPF5Lower;				/* RCPF5L ÏßÈ¦µçÁ÷RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcIPF6Lower;				/* RCPF6L ÏßÈ¦µçÁ÷RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcIPF7Lower;				/* RCPF7L ÏßÈ¦µçÁ÷RCÂË²¨²ÎÊı0.01-0.1 */
	float			rcIPF8Lower;				/* RCPF8L ÏßÈ¦µçÁ÷RCÂË²¨²ÎÊı0.01-0.1 */
}DpfDasRCfilter_t;

