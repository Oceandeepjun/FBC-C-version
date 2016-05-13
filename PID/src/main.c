#include <stdio.h>
#include <stdlib.h>
#include "../headers/function.h"
#include "../headers/structs.h"
#include "../headers/macros.h"
#include <string.h>

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
//	FILE *fp,*fp1;
//	fp = fopen("aa.txt","wb");
//	typedef struct {
//		float va;
//		float vb;
//	}ss;
//	ss st={123,456};
//	fwrite(&st,sizeof(st),1,fp);
//	fclose(fp);
//	char *fvp=(char*)malloc(sizeof(ss));
//	float fv;
//
//	fp1=fopen("aa.txt","rb");
//	fread(fvp,sizeof(st),1,fp1);
//	memcpy(&fv,fvp+4,4);
//	fclose(fp1);
//	printf("%f",fv);
//	free(fvp);


	FILE* vecfp=fopen("99925vec.inf","rb");
	//VEC_INF vec_INF;
	int blockl=24;
	int count=3;
	char* st=(char*)malloc(24*count);

	fread(st,blockl,count,vecfp);
	char cn[2];
	short sv[4];
	float fv[3];
	char un[2];
	memcpy(cn,st+((count-1)*blockl+0),2);//must mem convert!
	memcpy(fv,st+((count-1)*blockl+10),12);
	memcpy(sv,st+((count-1)*blockl+2),8);
	memcpy(un,st+((count-1)*blockl+22),2);
	fclose(vecfp);
	printf("%c\t%c\n%d\t%d\t%d\t%d\n%f\t%f\t%f\n%c\n",cn[0],cn[1],
			sv[0],sv[1],sv[2],sv[3],
			fv[0],fv[1],fv[2],
			un[0],un[1]);



//	printf("%s\n%d\n%d\n%d\n%d\n%f\n%f\n%f\n%s\n",vec_INF.Chname,
//			vec_INF.ChanNo,vec_INF.nodeNo,vec_INF.DataType,vec_INF.Address,
//			vec_INF.XSumCheck,vec_INF.YSumCheck,vec_INF.Frequency,
//			vec_INF.Unit);

    return 0;
}
