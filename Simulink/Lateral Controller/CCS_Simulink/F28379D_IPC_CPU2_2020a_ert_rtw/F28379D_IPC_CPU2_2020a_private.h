/*
 * File: F28379D_IPC_CPU2_2020a_private.h
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

#ifndef RTW_HEADER_F28379D_IPC_CPU2_2020a_private_h_
#define RTW_HEADER_F28379D_IPC_CPU2_2020a_private_h_
#include "rtwtypes.h"
#include "can_message.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_can.h"
#include "driverlib/can.h"
#include "F28379D_IPC_CPU2_2020a.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern real32_T rt_powf_snf(real32_T u0, real32_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real32_T rt_atan2f_snf(real32_T u0, real32_T u1);
void isr_int1pie14_task_fcn(void);
extern void configureGPIOExtInterrupt(void);
void isr_int1pie14_task_fcn(void);     /* private model entry point functions */
extern void F28379D_IPC_CPU2_2020a_derivatives(void);

#endif                        /* RTW_HEADER_F28379D_IPC_CPU2_2020a_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
