/*
 * File: uint16Tofloat16.c
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

#include "uint16Tofloat16.h"

/* Include model header file for global data */
#include "F28379D_IPC_CPU2_2020a.h"
#include "F28379D_IPC_CPU2_2020a_private.h"

/* Forward declaration for local functions */
static real32_T F28379D_IPC_CPU_get_significant(uint16_T x);
real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T tmp;
  real32_T tmp_0;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else {
    tmp = fabsf(u0);
    tmp_0 = fabsf(u1);
    if (rtIsInfF(u1)) {
      if (tmp == 1.0F) {
        y = 1.0F;
      } else if (tmp > 1.0F) {
        if (u1 > 0.0F) {
          y = (rtInfF);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = (rtInfF);
      }
    } else if (tmp_0 == 0.0F) {
      y = 1.0F;
    } else if (tmp_0 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = (real32_T)sqrt(u0);
    } else if ((u0 < 0.0F) && (u1 > (real32_T)floor(u1))) {
      y = (rtNaNF);
    } else {
      y = (real32_T)pow(u0, u1);
    }
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/u2f_1' */
static real32_T F28379D_IPC_CPU_get_significant(uint16_T x)
{
  real32_T significant_result;
  uint16_T m;
  real_T n;
  real_T b_significant_result;
  int16_T i;

  /* '<S8>:1:53' */
  m = x;

  /* '<S8>:1:54' */
  n = 10.0;

  /* '<S8>:1:55' */
  b_significant_result = 0.0;

  /* '<S8>:1:56' */
  for (i = 0; i < 10; i++) {
    /* '<S8>:1:56' */
    if ((m & 1U) == 1U) {
      /* '<S8>:1:57' */
      /* '<S8>:1:58' */
      b_significant_result += rt_powd_snf(2.0, -n);
    }

    /* '<S8>:1:60' */
    n--;

    /* '<S8>:1:61' */
    m = x >> (i + 1);
  }

  /* '<S8>:1:63' */
  significant_result = (real32_T)b_significant_result;
  return significant_result;
}

/*
 * Output and update for atomic system:
 *    '<Root>/u2f_1'
 *    '<Root>/u2f_2'
 *    '<Root>/u2f_3'
 *    '<Root>/u2f_4'
 */
void uint16Tofloat16(uint16_T rtu_u1, uint16_T rtu_u2, rtB_uint16Tofloat16
                     *localB)
{
  real32_T result;
  uint16_T c;
  uint16_T exponent;
  int16_T sign_bit;
  uint16_T b_c;

  /* MATLAB Function 'u2f_1': '<S8>:1' */
  /* '<S8>:1:12' */
  /* '<S8>:1:13' */
  /* '<S8>:1:14' */
  c = (rtu_u1 << 8U) + rtu_u2;

  /* '<S8>:1:17' */
  /* '<S8>:1:18' */
  sign_bit = (int16_T)(c >> 15);

  /* '<S8>:1:21' */
  /* '<S8>:1:22' */
  b_c = (c & 31744U) >> 10;
  exponent = (c & 31744U) >> 10;

  /* '<S8>:1:23' */
  /* '<S8>:1:26' */
  /* '<S8>:1:27' */
  c &= 1023U;
  if ((int16_T)b_c == 0) {
    /* '<S8>:1:29' */
    if ((int16_T)c == 0) {
      /* '<S8>:1:30' */
      /* '<S8>:1:31' */
      result = 0.0F;
    } else if (sign_bit == 0) {
      /* '<S8>:1:33' */
      /* '<S8>:1:34' */
      result = F28379D_IPC_CPU_get_significant(c);
      result *= 6.10351563E-5F;
    } else {
      /* '<S8>:1:36' */
      result = F28379D_IPC_CPU_get_significant(c);
      result *= -6.10351563E-5F;
    }
  } else if ((int16_T)b_c == 31) {
    /* '<S8>:1:39' */
    /* '<S8>:1:41' */
    result = 65505.0F;
  } else if (sign_bit == 0) {
    /* '<S8>:1:44' */
    /* '<S8>:1:45' */
    result = rt_powf_snf(2.0F, (real32_T)exponent - 15.0F) *
      (F28379D_IPC_CPU_get_significant(c) + 1.0F);
  } else {
    /* '<S8>:1:47' */
    result = -rt_powf_snf(2.0F, (real32_T)exponent - 15.0F) *
      (F28379D_IPC_CPU_get_significant(c) + 1.0F);
  }

  localB->result = result;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
