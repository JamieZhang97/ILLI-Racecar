/*
 * File: F28379D_IPC_CPU2_2020a.h
 *
 * Code generated for Simulink model 'F28379D_IPC_CPU2_2020a'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Oct  8 00:59:53 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_F28379D_IPC_CPU2_2020a_h_
#define RTW_HEADER_F28379D_IPC_CPU2_2020a_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef F28379D_IPC_CPU2_2020a_COMMON_INCLUDES_
# define F28379D_IPC_CPU2_2020a_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "can_message.h"
#include "MW_c28xIPC.h"
#include "c2000BoardSupport.h"
#include "F2837xD_device.h"
#endif                             /* F28379D_IPC_CPU2_2020a_COMMON_INCLUDES_ */

#include "F28379D_IPC_CPU2_2020a_types.h"

/* Child system includes */
#include "uint16Tofloat16.h"
#include "MW_target_hardware_resources.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

extern void configureCPU2Peripherals(uint32_T gpioNumber, uint32_T gpGRegValA,
  uint32_T gpRegValA);
extern void init_eCAN_B ( uint16_T bitRatePrescaler, uint16_T timeSeg1, uint16_T
  timeSeg2, uint16_T sbg, uint16_T sjw, uint16_T sam);

/* user code (top of export header file) */
#include "can_message.h"
#include "can_message.h"

/* Block signals (default storage) */
typedef struct {
  CAN_DATATYPE CANExternalReceive_o2;  /* '<Root>/CAN External Receive' */
  real_T Integrator;                   /* '<S3>/Integrator' */
  real_T DataTypeConversion;           /* '<S3>/Data Type Conversion' */
  real_T CANUnpack1_o1;                /* '<S2>/CAN Unpack1' */
  real_T CANUnpack1_o2;                /* '<S2>/CAN Unpack1' */
  real_T CANUnpack1_o3;                /* '<S2>/CAN Unpack1' */
  real_T CANUnpack1_o4;                /* '<S2>/CAN Unpack1' */
  real_T CANUnpack1_o5;                /* '<S2>/CAN Unpack1' */
  real_T CANUnpack1_o6;                /* '<S2>/CAN Unpack1' */
  real_T CANUnpack1_o7;                /* '<S2>/CAN Unpack1' */
  real_T CANUnpack1_o8;                /* '<S2>/CAN Unpack1' */
  real32_T TmpRTBAtSubtractInport1;
  real32_T Subtract;                   /* '<S3>/Subtract' */
  real32_T Kp;                         /* '<S3>/Kp' */
  real32_T Ki;                         /* '<S3>/Ki' */
  real32_T Subtract1;                  /* '<S3>/Subtract1' */
  real32_T TmpRTBAtsingle_array1Inport2;
                                  /* '<Root>/pure pursuit lateral controller' */
  real32_T TmpRTBAtSubtractInport2[2];
  real32_T Subtract_l[2];              /* '<S6>/Subtract' */
  real32_T Atan2;                      /* '<S6>/Atan2' */
  real32_T TmpRTBAtheadingerrorinpipiInpor;
  real32_T Gain;                       /* '<S6>/Gain' */
  real32_T output_array[4];            /* '<Root>/single_array1' */
  real32_T y;                          /* '<S6>/heading error in [-pi,pi]' */
  real32_T output_array_e[4];          /* '<Root>/list parameter in an array' */
  real32_T x_lh;                       /* '<Root>/find look-ahead points' */
  real32_T y_lh;                       /* '<Root>/find look-ahead points' */
  real32_T IPCReceive1_o1[4];          /* '<S1>/IPC Receive1' */
  uint16_T IPCReceive1_o2;             /* '<S1>/IPC Receive1' */
  uint16_T CANUnpack1_o9;              /* '<S2>/CAN Unpack1' */
  uint16_T CANUnpack1_o10;             /* '<S2>/CAN Unpack1' */
  uint16_T DataTypeConversion_h;       /* '<S2>/Data Type Conversion' */
  uint16_T DataTypeConversion1;        /* '<S2>/Data Type Conversion1' */
  uint16_T DataTypeConversion2;        /* '<S2>/Data Type Conversion2' */
  uint16_T DataTypeConversion3;        /* '<S2>/Data Type Conversion3' */
  uint16_T DataTypeConversion4;        /* '<S2>/Data Type Conversion4' */
  uint16_T DataTypeConversion5;        /* '<S2>/Data Type Conversion5' */
  uint16_T DataTypeConversion6;        /* '<S2>/Data Type Conversion6' */
  uint16_T DataTypeConversion7;        /* '<S2>/Data Type Conversion7' */
  rtB_uint16Tofloat16 sf_u2f_4;        /* '<Root>/u2f_4' */
  rtB_uint16Tofloat16 sf_u2f_3;        /* '<Root>/u2f_3' */
  rtB_uint16Tofloat16 sf_u2f_2;        /* '<Root>/u2f_2' */
  rtB_uint16Tofloat16 sf_u2f_1;        /* '<Root>/u2f_1' */
} BlockIO_F28379D_IPC_CPU2_2020a;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  volatile real32_T TmpRTBAtSubtractInport1_Buffer[2];/* synthesized block */
  real32_T TmpRTBAtsingle_array1Inport2_Bu;/* synthesized block */
  volatile real32_T TmpRTBAtSubtractInport2_Buffer[4];/* synthesized block */
  volatile real32_T TmpRTBAtheadingerrorinpipiInpor[2];/* synthesized block */
  int_T CANUnpack1_ModeSignalID;       /* '<S2>/CAN Unpack1' */
  int_T CANUnpack1_StatusPortID;       /* '<S2>/CAN Unpack1' */
  volatile int16_T TmpRTBAtSubtractInport1_ActiveB;/* synthesized block */
  volatile int16_T TmpRTBAtSubtractInport1_semapho;/* synthesized block */
  volatile int16_T TmpRTBAtSubtractInport2_ActiveB;/* synthesized block */
  volatile int16_T TmpRTBAtSubtractInport2_semapho;/* synthesized block */
  volatile int16_T TmpRTBAtheadingerrorinpipiInp_b;/* synthesized block */
  volatile int16_T TmpRTBAtheadingerrorinpipiInp_p;/* synthesized block */
} D_Work_F28379D_IPC_CPU2_2020a;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S3>/Integrator' */
} ContinuousStates_F28379D_IPC_CP;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S3>/Integrator' */
} StateDerivatives_F28379D_IPC_CP;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S3>/Integrator' */
} StateDisabled_F28379D_IPC_CPU2_;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct Parameters_F28379D_IPC_CPU2_202_ {
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */
  real_T Ki_Gain;                      /* Expression: 1
                                        * Referenced by: '<S3>/Ki'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real32_T TmpRTBAtSubtractInport1_Initial;
                          /* Computed Parameter: TmpRTBAtSubtractInport1_Initial
                           * Referenced by: synthesized block
                           */
  real32_T DesiredVelocity_Value;   /* Computed Parameter: DesiredVelocity_Value
                                     * Referenced by: '<S3>/DesiredVelocity'
                                     */
  real32_T Kp_Gain;                    /* Computed Parameter: Kp_Gain
                                        * Referenced by: '<S3>/Kp'
                                        */
  real32_T TmpRTBAtsingle_array1Inport2_In;
                          /* Computed Parameter: TmpRTBAtsingle_array1Inport2_In
                           * Referenced by: synthesized block
                           */
  real32_T lookaheaddistance_Value;
                                  /* Computed Parameter: lookaheaddistance_Value
                                   * Referenced by: '<Root>/look-ahead distance'
                                   */
  real32_T TmpRTBAtSubtractInport2_Initial;
                          /* Computed Parameter: TmpRTBAtSubtractInport2_Initial
                           * Referenced by: synthesized block
                           */
  real32_T TmpRTBAtheadingerrorinpipiInpor;
                          /* Computed Parameter: TmpRTBAtheadingerrorinpipiInpor
                           * Referenced by: synthesized block
                           */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S6>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_F28379D_IPC_CPU2_2020a {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  ContinuousStates_F28379D_IPC_CP *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[4];
  } Timing;
};

/* Block parameters (default storage) */
extern Parameters_F28379D_IPC_CPU2_202 F28379D_IPC_CPU2_2020a_P;

/* Block signals (default storage) */
extern BlockIO_F28379D_IPC_CPU2_2020a F28379D_IPC_CPU2_2020a_B;

/* Continuous states (default storage) */
extern ContinuousStates_F28379D_IPC_CP F28379D_IPC_CPU2_2020a_X;

/* Block states (default storage) */
extern D_Work_F28379D_IPC_CPU2_2020a F28379D_IPC_CPU2_2020a_DWork;

/* External function called from main */
extern void F28379D_IPC_CPU2_2020a_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void F28379D_IPC_CPU2_2020a_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void F28379D_IPC_CPU2_2020a_initialize(void);
extern void F28379D_IPC_CPU2_2020a_step0(void);
extern void F28379D_IPC_CPU2_2020a_step2(void);
extern void F28379D_IPC_CPU2_2020a_terminate(void);

/* Real-time Model object */
extern RT_MODEL_F28379D_IPC_CPU2_2020a *const F28379D_IPC_CPU2_2020a_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'F28379D_IPC_CPU2_2020a'
 * '<S1>'   : 'F28379D_IPC_CPU2_2020a/IPC 1'
 * '<S2>'   : 'F28379D_IPC_CPU2_2020a/Msg Converter'
 * '<S3>'   : 'F28379D_IPC_CPU2_2020a/PI longitude controller'
 * '<S4>'   : 'F28379D_IPC_CPU2_2020a/find look-ahead points'
 * '<S5>'   : 'F28379D_IPC_CPU2_2020a/list parameter in an array'
 * '<S6>'   : 'F28379D_IPC_CPU2_2020a/pure pursuit lateral controller'
 * '<S7>'   : 'F28379D_IPC_CPU2_2020a/single_array1'
 * '<S8>'   : 'F28379D_IPC_CPU2_2020a/u2f_1'
 * '<S9>'   : 'F28379D_IPC_CPU2_2020a/u2f_2'
 * '<S10>'  : 'F28379D_IPC_CPU2_2020a/u2f_3'
 * '<S11>'  : 'F28379D_IPC_CPU2_2020a/u2f_4'
 * '<S12>'  : 'F28379D_IPC_CPU2_2020a/pure pursuit lateral controller/heading error in [-pi,pi]'
 */
#endif                                /* RTW_HEADER_F28379D_IPC_CPU2_2020a_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
