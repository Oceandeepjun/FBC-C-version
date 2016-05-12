#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#include "macros.h"

typedef struct VECNode{
    VEC_Node_Type y;
    int x;              //time unit: ms
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


#endif // STRUCTS_H_INCLUDED
