#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include "structs.h"
void Rotate_1D_Array(float *array_name,float elem);
vec_Node_t get_VEC_Node(vec_Curve_t vec_Curve, int subscript);

void ChildNodeFinder(xmlNodePtr nodePtr);

float pid_Calculator(vec_Curve_t pid_K, vec_Curve_t pid_J, vec_Curve_t pid_D,
					float *rotate_array, float acqDATA, int subscript);

#endif // FUNCTION_H_INCLUDED
