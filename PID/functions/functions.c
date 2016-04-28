#include <stdio.h>

//rotate just 1 element for array;
void Rotate_1D_Array(float *array_name,float elem){
    int len=sizeof(array_name);
    int i;
    for(i=1; i<len-1 ;i++){
        array_name[len-i]=array_name[len-i-1];
    }
    array_name[0]=elem;
}


