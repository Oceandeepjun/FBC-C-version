#include <stdio.h>
#include "../headers/macros.h"
#include "../headers/structs.h"

/*rotate just 1 element for array*/
void Rotate_1D_Array(float *array_name,unsigned int len,float elem){
    unsigned int i;
    for(i=1; i<len ;i++){
        array_name[len-i]=array_name[len-i-1];
        }
    array_name[0]=elem;
}

/*get the x,y value of one vec node;*/
vec_Node_t get_VEC_Node(vec_Curve_t vec_Curve, int subscript){
    int i;
    if(subscript<=vec_Curve.vec_Nodes[0].x)
        return vec_Curve.vec_Nodes[0];
    else if(subscript>=vec_Curve.vec_Nodes[vec_Curve.nodeNo-1].x)
        return vec_Curve.vec_Nodes[vec_Curve.nodeNo-1];
        else {
            for (i=1;i<vec_Curve.nodeNo;i++)
                if(subscript==vec_Curve.vec_Nodes[i].x)
                    return vec_Curve.vec_Nodes[i];
                else if(subscript<vec_Curve.vec_Nodes[i].x){
                		vec_Node_t tempnode;
                        tempnode.y=(vec_Curve.vec_Nodes[i-1].y+
                        (vec_Curve.vec_Nodes[i].y-vec_Curve.vec_Nodes[i-1].y)/
                        (vec_Curve.vec_Nodes[i].x-vec_Curve.vec_Nodes[i-1].x)*
                        (subscript-vec_Curve.vec_Nodes[i-1].x));
                        tempnode.x=subscript;
                        return tempnode;
                        }
              }
}


























