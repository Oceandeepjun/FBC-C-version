#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "../headers/function.h"
#include "../headers/structs.h"
#include "../headers/macros.h"


int main()
{
    /*-----------------For Test---------------------
    printf("Hello world!\n");
    printf("Hello git!\n");
    int a[]={1,2,1,2,1,2,1};
    char b[]={'w','e','w','q'};
    int *c[1];
    c[0]=a;
    printf("%d\n",sizeof(b));
    printf("%d\n",c[0][3]);
	-------------Rotate_1D_Array Test-------------
    float a[3]={2,5,6};
    Rotate_1D_Array(a,3,8);
    unsigned int i=0;
    while(i<sizeof(a)/4)
        printf("%f\n",a[(++i)-1]);
        i=0;
    Rotate_1D_Array(a,3,8);
    while(i<sizeof(a)/4)
        printf("%f\n",a[(++i)-1]);
        i=0;
    Rotate_1D_Array(a,3,8);
    while(i<sizeof(a)/4)
        printf("%f\n",a[(++i)-1]);
    ---------------Global Test------------------
    int*p;
    p=say1(); //There is a static variable in say1() which can be modified through pointer;
    *p=88;
    say1();
    say1();
    -----------get_VEC_Node Test------------
    VEC_Node nods[2]={{2.0,1},{24.0,3}};
    VEC_CURVE cur={2,nods};
    VEC_Node nod=get_VEC_Node(cur,2);
    printf("%f\n%d",nod.y,nod.x);   //correct result;
    ----------------------------------------*/
	//---------------read vec.inf----------------------
	struct stat vecinf_Status;
	stat("99925vec.inf",&vecinf_Status);                              	//get vecinf file size
	long vecinf_Size=vecinf_Status.st_size;
	FILE* vecinfp=fopen("99925vec.inf","rb");
	char* vecinf_Buffer=(char*)malloc(vecinf_Size);
	fread(vecinf_Buffer,VECINF_STRUCT_SIZE,vecinf_Size/VECINF_STRUCT_SIZE,vecinfp);  	//read vecinf into buffer
	fclose(vecinfp);

	vec_Inf_t vecinf_Array[vecinf_Size/VECINF_STRUCT_SIZE];
	int count;
	char cn[2];
	short sv[4];
	float fv[3];
	char un[2];
	for(count=0;count<vecinf_Size/VECINF_STRUCT_SIZE;count++){            		//move vecinf into buffered array
		memcpy(cn,vecinf_Buffer+((count-1)*VECINF_STRUCT_SIZE+0),2);
		memcpy(cn,vecinf_Buffer+((count-1)*VECINF_STRUCT_SIZE+0),2);   			//must convert in mem!
		memcpy(fv,vecinf_Buffer+((count-1)*VECINF_STRUCT_SIZE+10),12);
		memcpy(sv,vecinf_Buffer+((count-1)*VECINF_STRUCT_SIZE+2),8);
		memcpy(un,vecinf_Buffer+((count-1)*VECINF_STRUCT_SIZE+22),2);
		vecinf_Array[count].Chname[0]=cn[0];
		vecinf_Array[count].Chname[1]=cn[1];
		vecinf_Array[count].Chname[2]='\0';
		vecinf_Array[count].ChanNo=sv[0];
		vecinf_Array[count].nodeNo=sv[1];
		vecinf_Array[count].DataType=sv[2];
		vecinf_Array[count].Address=sv[3];
		vecinf_Array[count].XSumCheck=fv[0];
		vecinf_Array[count].YSumCheck=fv[1];
		vecinf_Array[count].Frequency=fv[2];
		vecinf_Array[count].Unit[0]=un[0];
		vecinf_Array[count].Unit[1]='\0';
		}
	free(vecinf_Buffer);

	int a=0;
	printf("%s\n%d\n%d\n%d\n%d\n%.1f\n%.1f\n%.1f\n%s\n",vecinf_Array[a].Chname,
			vecinf_Array[a].ChanNo,vecinf_Array[a].nodeNo,vecinf_Array[a].DataType,vecinf_Array[a].Address,
			vecinf_Array[a].XSumCheck,vecinf_Array[a].YSumCheck,vecinf_Array[a].Frequency,
			vecinf_Array[a].Unit);


//	struct stat vecdat_Status;
//	stat("99925vec.dat",&vecdat_Status);                              	//get vecinf file size
//	long vecdat_Size=vecdat_Status.st_size;
//
//
//	vec_Node_t *vecdat_Buffer=(vec_Node_t*)malloc(vecdat_Size);
//	FILE *vecdatp=fopen("99925vec.dat","rb");
//	fread(vecdat_Buffer,sizeof(vec_Node_t),vecdat_Size/sizeof(vec_Node_t),vecdatp);
//	fclose(vecdatp);
//
//	vec_Curve_t vec_Curve_array[vecinf_Size/VECINF_STRUCT_SIZE];	//vec curve array;
//
////	vec_Curve_Package_t vec_Curve_p;								//used for delivering,can be removed.
////	vec_Curve_p.vec_Package=vec_Curve_array;
//
//	int curvenum=0;
//	int nodeNo_Sum=0;
//	for(curvenum=0;curvenum<vecinf_Size/VECINF_STRUCT_SIZE;curvenum++){  //Initialize curve array
//		vec_Curve_array[curvenum].nodeNo=vecinf_Array[curvenum].nodeNo;
//		vec_Curve_array[curvenum].vec_Nodes=vecdat_Buffer+nodeNo_Sum;
//		nodeNo_Sum+=vecinf_Array[curvenum].nodeNo;    //nodeNo_Sum+=sizeof(vec_Node_t)/sizeof(float)*vecinf_Array[curvenum].nodeNo;
//		}
//	int position=0;
//	vec_Node_t nodes[vec_Curve_array[position].nodeNo];
//	memcpy(nodes,vec_Curve_array[position].vec_Nodes,vec_Curve_array[position].nodeNo);
//	//nodes=vec_Curve_array[position].vec_Nodes;
//	while(--vec_Curve_array[position].nodeNo>0)
//	printf("%f.1,%f.1  ",nodes[0].y,nodes[1].x);
//
//
//
//
//
//	free(vecdat_Buffer);
    return 0;
}
