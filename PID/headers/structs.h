#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#include "macros.h"

//one of VEC curves;
typedef struct VECELEMENT{
    int nodeNo;
    double *vec_Nodes;          //2D array of vec data(x,y), no interpolation;
}VEC_ELEMENT;


//all the vec data;
typedef struct VECDATA{
    VEC_ELEMENT *vec_Elements[VEC_ELEMENT_NUM];   //address array;
}VEC_DATA;


#endif // STRUCTS_H_INCLUDED
