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


//all the vec data;
typedef struct VECPACKAGE{
	vec_Curve_t *vec_Package[VEC_CURVE_NUM];   //address array;
}vec_Curve_Package_t;

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

#endif // STRUCTS_H_INCLUDED
