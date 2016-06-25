#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED

/*---------macro definitions-------------*/

#define CONTROL_PERIOD 1
#define CURRENT_MAX 1*E7
#define CURRENT_MIN -1*E7
#define VEC_CURVE_NUM 94
#define VEC_NODE_TYPE float
#define VECINF_STRUCT_SIZE 24						//Inf Struct Size
/*
 * Defined by Zhang
 *
 */

#define		FLUXLOOP_IN_UPPER				1		/* */
#define		FLUXLOOP_IN_LOWER				2
#define		FLUXLOOP_OUT_UPPER				3
#define		FLUXLOOP_OUT_LOWER				4

#define	DISRUPTION_OCC			-10.0			/* -10 kA/ms, if dIp/dt < DISRUPTION_DIP */
#define	IP_TARGET_FACTOR			0.6				/* if (ip_acq < IP_TARGET_FACTOR*ip_target) dischareFailure = 1*/
#define	DISRUPT_MAX_TIMES			3
#define	ISO_FLUX_POINTS			8

#define MAX_DISCHARGE_TIME                14000	/* discharge time -7000ms to 7000ms  */
#define NUMBER_FLUX             			   40		/* number of flux loop  */
#define NUMBER_PROBE             		   60		/* number of magnetic probe */

#endif // MACROS_H_INCLUDED
