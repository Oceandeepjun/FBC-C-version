#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include "structs.h"
//#include "dpf2m.h"
//#include "vec2m.h"
//#include "cc2m.h"

void Rotate_1D_Array(float *array_name,float elem);
vec_Node_t get_VEC_Node(vec_Curve_t vec_Curve, int subscript);

void ChildNodeFinder(xmlNodePtr nodePtr);

float pid_Calculator(vec_Curve_t pid_K, vec_Curve_t pid_J, vec_Curve_t pid_D,
					float *rotate_array, float acqDATA, int subscript);

/*
 *Defined by Zhang
 *
 * */
void pscSysInitial(PowerSupplyAndCoilSystem_t *pscSys, int pidOption);
void ctrlSysInitial(freedBackControl_t *);
void rzfluxIndxSet(freedBackControl_t *ctrlSys, int, int, int, int);

void pidOpotionSet(freedBackControl_t *, int, int);


void  horizontalDispacementCal(FlDispacementCal_t *);
void  verticalDispacementCal(FlDispacementCal_t *);

float IncrementPidCal(incrementPidController_t *);
float RcFilter(rcFilter2m_t *f);
int	cycleCounterToIndex(int );
int	indexToCycleCounter(int );
void pscCtrlParameterInitial(PowerSupplyAndCoils_type *, int);
void unlockPscSysCheck(PowerSupplyAndCoilSystem_t *);
void unlockPs(PowerSupplyAndCoils_type *, int);

void lockPscSysCheck(PowerSupplyAndCoilSystem_t *);
void PsOperationStatusCheck(PowerSupplyAndCoilSystem_t *);

void lockPs( PowerSupplyAndCoils_type *, int);   /*-------------------------------------*/

void plasmalessDischarge(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);
void firstPlasmaDischarge(PowerSupplyAndCoilSystem_t *, freedBackControl_t *, bool);
void normalPlasmaDischarge(PowerSupplyAndCoilSystem_t *, freedBackControl_t *, int);
void dischareFailureHandle(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);


int	getDischarePhase(PowerSupplyAndCoilSystem_t *, freedBackControl_t *, DpfCentralCtrl_t *);
void getAcqData(void  *);
void acqDataProcess(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);

void horizontaPositionControl(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);
void verticalPositionControl(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);
//void plasmaCurrentControl(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);
void plasCurrentControl(PowerSupplyAndCoilSystem_t *pscSys, freedBackControl_t *ctrlSys);

void currentfreedBackInit(PowerSupplyAndCoilSystem_t *);
void currentfreedBackControl(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);
void votageCorrectCal(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);
void calculatePsCtrlAngle(PowerSupplyAndCoilSystem_t *, freedBackControl_t *, bool);
void sendCtrlAngleToPs(int, powerSupplyCtrlCmd_t *);

void isoFluxControl(PowerSupplyAndCoilSystem_t *, freedBackControl_t *);





#endif // FUNCTION_H_INCLUDED
