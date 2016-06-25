#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>
//#include <netinet/in.h>
//#include <sys/socket.h>

/*
 *	For Xml options
 */
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#define IN_LIBXML
/*
 *  User headers
 */
#include "../headers/dpf2m.h"
#include "../headers/vec2m.h"
#include "../headers/cc2m.h"
#include "../headers/function.h"
#include "../headers/structs.h"
#include "../headers/macros.h"

#include<time.h>
/*
 * Sockets libs
 */
#include <winsock2.h> //<sys/socket.h> <types.h> in Linux


/*
 * Must declared as global variables
 * Stack memory is not enough for all wave data
 *
 * */
float GAcqData[ACQ_COUNT];
PowerSupplyAndCoils_t			psPf2m[PSC_COUNT];
PowerSupplyAndCoilSystem_t	pscSys;
freedBackControl_t				ctrlSys;

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
	//-------------------Rotate_1D_Array Test--------------
    float a[3]={2,5,6};
    Rotate_1D_Array(a,8);
    unsigned int i=0;
    while(i<sizeof(a)/4)
        printf("%f\n",a[(++i)-1]);
        i=0;
    Rotate_1D_Array(a,8);
    while(i<sizeof(a)/4)
        printf("%f\n",a[(++i)-1]);
        i=0;
    Rotate_1D_Array(a,8);
    while(i<sizeof(a)/4)
        printf("%f\n",a[(++i)-1]);
    //---------------Global Test------------------
    int*p;
    p=say1(); //There is a static variable in say1() which can be modified through pointer;
    *p=88;
    say1();
    say1();
    //-----------get_VEC_Node Test------------
    VEC_Node nods[2]={{2.0,1},{24.0,3}};
    VEC_CURVE cur={2,nods};
    VEC_Node nod=get_VEC_Node(cur,2);
    printf("%f\n%d",nod.y,nod.x);   //correct result;
    ----------------------------------------*/
/**
 *
 * Test End
 *
 */

	//-----------------------------read vec.inf------------------------------------

	struct stat vecinf_Status;
	stat("99925vec.inf",&vecinf_Status);                              					/*get vecinf file size*/
	long vecinf_Size=vecinf_Status.st_size;
	FILE* vecinfp=fopen("99925vec.inf","rb");
	char* vecinf_Buffer=(char*)malloc(vecinf_Size);
	fread(vecinf_Buffer,VECINF_STRUCT_SIZE,vecinf_Size/VECINF_STRUCT_SIZE,vecinfp);  	/*read vecinf into buffer*/
	fclose(vecinfp);

	vec_Inf_t vecinf_Array[vecinf_Size/VECINF_STRUCT_SIZE];
	int count;
	char cn[2];
	short sv[4];
	float fv[3];
	char un[2];
	for(count=0;count<vecinf_Size/VECINF_STRUCT_SIZE;count++){            				/*move vecinf into buffered array*/
		memcpy(cn,vecinf_Buffer+((count)*VECINF_STRUCT_SIZE+0),2);
		memcpy(cn,vecinf_Buffer+((count)*VECINF_STRUCT_SIZE+0),2);   					/*must convert in mem!*/
		memcpy(fv,vecinf_Buffer+((count)*VECINF_STRUCT_SIZE+10),12);
		memcpy(sv,vecinf_Buffer+((count)*VECINF_STRUCT_SIZE+2),8);
		memcpy(un,vecinf_Buffer+((count)*VECINF_STRUCT_SIZE+22),2);
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
		vecinf_Array[count].Unit[1]=un[1];
		vecinf_Array[count].Unit[2]='\0';

		//-----------------------display vecinf structs--------------------------

//		printf("%2s  %3d  %3d  %d  %6d  %8.1f  %8.1f  %8.1f  %2s\n",vecinf_Array[count].Chname,
//					vecinf_Array[count].ChanNo,vecinf_Array[count].nodeNo,
//					vecinf_Array[count].DataType,vecinf_Array[count].Address,
//					vecinf_Array[count].XSumCheck,vecinf_Array[count].YSumCheck,
//					vecinf_Array[count].Frequency,
//					vecinf_Array[count].Unit);

		}
	free(vecinf_Buffer);

	/*----------------------------------read vec.dat----------------------------*/
	struct stat vecdat_Status;
	stat("99925vec.dat",&vecdat_Status);                              					/*get vecdat file size*/
	long vecdat_Size=vecdat_Status.st_size;

	vec_Node_t *vecdat_Buffer=(vec_Node_t*)malloc(vecdat_Size);
	FILE *vecdatp=fopen("99925vec.dat","rb");											/*read into vecdat buffer*/
	fread(vecdat_Buffer,sizeof(vec_Node_t),vecdat_Size/sizeof(vec_Node_t),vecdatp);
	fclose(vecdatp);

	vec_Curve_t vec_Curve_array[vecinf_Size/VECINF_STRUCT_SIZE];						/*Initialize curve addr array*/
	int curvenum=0;
	int nodeNo_Sum=0;
	for(curvenum=0;curvenum<vecinf_Size/VECINF_STRUCT_SIZE;curvenum++){
		vec_Curve_array[curvenum].nodeNo=vecinf_Array[curvenum].nodeNo;
		vec_Curve_array[curvenum].vec_Nodes=vecdat_Buffer+nodeNo_Sum;
		nodeNo_Sum+=vecinf_Array[curvenum].nodeNo;
		}

	/*----------------------display the vec nodes at position-------------------*/

//	int position=1;
//	int i = 0;
//	for(i=0;i<vec_Curve_array[position].nodeNo;i++)
//	printf("%8.1f %8.1f\n",vec_Curve_array[position].vec_Nodes[i].y,vec_Curve_array[position].vec_Nodes[i].x);
//
	free(vecdat_Buffer);

	xmlDocPtr doc;
	xmlNodePtr cur;
	if(!xmlFree) xmlMemGet(&xmlFree,&xmlMalloc,&xmlRealloc,NULL);//only for windows platform!
//	xmlKeepBlanksDefault(0);
	doc = xmlParseFile("2MDPF-new.xml");
	//doc = xmlParseFile("aa.xml");
	cur = xmlDocGetRootElement(doc);
	ChildNodeFinder(cur);
	xmlFreeNode(cur);
	xmlFreeDoc(doc);

/*
 *
 *  Main Starts
 *  Use zhang main
 *
 * */
	/* vec2m variables */
		//dataAcqChannel_t				dataAcqChannel2m;
		//ccTargetWaveForm_t			ccTargetWaveForm2m;
		//psVotageControl_t				pidcontroll2m;

		/* dpf2m vairables */
		DpfCentralCtrl_t				dpfCentralCtrl2m;
		//DpfMotorGenerator_t			dpfMotorGenerator2m;
		//DpfPowerSupply_t				dpfPowerSupply2m;
		//DpfVacuum_t					dpfVacuum2m;
		//DpfMachine_t					dpfMachine2m;
		//DpfAuxHeating_t				dpfAuxHeating2m;
		//DpfDasRCfilter_t				dpfDasRCfilter2m;

		/* hl-2m poloidal power supply and coils variable sets */



		int				id, cycleCounter;		/* 循环计数器，以控制周期为单位*/

		int				discharePhase;		/* 放电阶段  */

		bool				forceNoBFCntrl;		/* 强制不返馈 */

		/* read 2mdpf.xml file */
		if (!dpfCentralCtrl2m.feedBackCmd) return 0;		/* 反馈不投入 */
		/* read vec 文件并插值 */

		for (id=PSC_CS; id<PSC_COUNT; id++)
			{
				psPf2m[id].id = id;
				pscSys.psAndcoils2m[id] = &(psPf2m[id]);
			}

		pscSys.controlPeriodTime		= 1.0;	/* (ms) */


		/* pid(iPF_acq-iPF_target), pid option : CNTRL_OPTION_PID, CNTRL_OPTION_P, CNTRL_OPTION_PI, CNTRL_OPTION_PD */
		pscSysInitial(&pscSys, CNTRL_OPTION_PID);
		rzfluxIndxSet(&ctrlSys, FLUXLOOP_IN_UPPER, FLUXLOOP_IN_LOWER, FLUXLOOP_OUT_UPPER, FLUXLOOP_OUT_LOWER);
		ctrlSysInitial(&ctrlSys);
		pidOpotionSet(&ctrlSys, SET_CTRLLER_IP, CNTRL_OPTION_PID);
		pidOpotionSet(&ctrlSys, SET_CTRLLER_R, CNTRL_OPTION_PID);
		pidOpotionSet(&ctrlSys, SET_CTRLLER_Z, CNTRL_OPTION_PID);
		pidOpotionSet(&ctrlSys, SET_CTRLLER_ISOFLUX, CNTRL_OPTION_PID);

		/* read 2mdpf.xml file */
		/* read 2mvec file */
		/* read ctrlSys.MutualMatrix */

		ctrlSys.ctrlMode = dpfCentralCtrl2m.CtrlMode;
		/*ctrlSys.doFreedBackCntrl = dpfCentralCtrl2m.feedBackMode;*/
		/*  反馈与时序、逻辑的关系*/
		/*  cycleCounter  */

		//if (cycleCounter == dpfCentralCtrl2m.DischargeStartStep)		/* Discharge Start */
		do {	/* 实时程序将修改这种循环结构*/
				/* get current time from TSC ??????????  linux MRG */

				pscSys.cycleCount = cycleCounter;
				pscSys.cycleIndx = cycleCounterToIndex(cycleCounter);
				/* get acq data & filter for acq_data ??????????????????????????????? */
				getAcqData(&(ctrlSys.mDiag.acqData));
				acqDataProcess(&pscSys, &ctrlSys);
				if (ctrlSys.disFail.disrupTimes >= DISRUPT_MAX_TIMES) ctrlSys.disFail.dischareFailure = 1;
				if (ctrlSys.disFail.dischareFailure)
					{
						dischareFailureHandle(&pscSys, &ctrlSys);
					}
				else
					{
						switch (dpfCentralCtrl2m.OperationMode)
							{
							case FB_NO_PLASMA :
								/* plasmaless discharge, test & scaling */
								plasmalessDischarge(&pscSys, &ctrlSys);
								break;

							case FIRST_PLASMA :
								/* 所有电源只有负组工作*/
								ctrlSys.ctrlMode = CTRL_RZIP;
								//if (cycleCounter < 10 )
								if (ctrlSys.mDiag.ipAcq.data[pscSys.cycleIndx] < 5.0 )
									{
										forceNoBFCntrl = 1;
									}
								else if (cycleCounter < dpfCentralCtrl2m.FBStartTime)
									{
										forceNoBFCntrl = dpfCentralCtrl2m.feedBackMode;
										ctrlSys.doFreedBackCntrl = 0;
									}
								else
									{
										forceNoBFCntrl = dpfCentralCtrl2m.feedBackMode;
										ctrlSys.doFreedBackCntrl = 1;
									}
									firstPlasmaDischarge(&pscSys, &ctrlSys, forceNoBFCntrl);

								break;

							case NORMAL_PLASMA :
							default :
								discharePhase = getDischarePhase(&pscSys, &ctrlSys, &dpfCentralCtrl2m);
								normalPlasmaDischarge(&pscSys, &ctrlSys, discharePhase);
							}
						/* check 一个控制周期的剩余时间  */
						cycleCounter++;
					}
			}
		while(cycleCounter < dpfCentralCtrl2m.DischargeEndStep);



    return 0;

}
