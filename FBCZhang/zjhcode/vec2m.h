

#define MAX_DISCHARGE_TIME                14000	/* discharge time -7000ms to 7000ms  */
#define NUMBER_FLUX             			   40		/* number of flux loop  */
#define NUMBER_PROBE             		   60		/* number of magnetic probe */

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

