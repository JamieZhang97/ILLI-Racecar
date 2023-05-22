/*
 * File: uint16Tofloat16.h
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

#ifndef RTW_HEADER_uint16Tofloat16_h_
#define RTW_HEADER_uint16Tofloat16_h_
#include <math.h>
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
#include "rt_nonfinite.h"

/* Block signals for system '<Root>/u2f_1' */
typedef struct {
  real32_T result;                     /* '<Root>/u2f_1' */
} rtB_uint16Tofloat16;

extern void uint16Tofloat16(uint16_T rtu_u1, uint16_T rtu_u2,
  rtB_uint16Tofloat16 *localB);

#endif                                 /* RTW_HEADER_uint16Tofloat16_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
