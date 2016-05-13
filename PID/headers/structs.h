#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#include "macros.h"

typedef struct VECNode{
    VEC_NODE_TYPE y;
    VEC_NODE_TYPE x;              //time unit: ms
}VEC_Node;


//one of VEC curves;
typedef struct VECCURVE{
    int nodeNo;
    VEC_Node *vec_Nodes;          //2D array of vec data(x,y), no interpolation;
}VEC_CURVE;


//all the vec data;
typedef struct VECPACKAGE{
    VEC_CURVE *vec_Package[VEC_CURVE_NUM];   //address array;
}VEC_PACKAGE;

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
}VEC_INF;

#endif // STRUCTS_H_INCLUDED
