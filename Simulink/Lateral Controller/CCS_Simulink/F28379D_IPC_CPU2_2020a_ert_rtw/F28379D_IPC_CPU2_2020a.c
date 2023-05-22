/*
 * File: F28379D_IPC_CPU2_2020a.c
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

#include "F28379D_IPC_CPU2_2020a.h"
#include "F28379D_IPC_CPU2_2020a_private.h"

/* Block signals (default storage) */
BlockIO_F28379D_IPC_CPU2_2020a F28379D_IPC_CPU2_2020a_B;

/* Continuous states */
ContinuousStates_F28379D_IPC_CP F28379D_IPC_CPU2_2020a_X;

/* Block states (default storage) */
D_Work_F28379D_IPC_CPU2_2020a F28379D_IPC_CPU2_2020a_DWork;

/* Real-time model */
RT_MODEL_F28379D_IPC_CPU2_2020a F28379D_IPC_CPU2_2020a_M_;
RT_MODEL_F28379D_IPC_CPU2_2020a *const F28379D_IPC_CPU2_2020a_M =
  &F28379D_IPC_CPU2_2020a_M_;
static void rate_monotonic_scheduler(void);

/* Hardware Interrupt Block: '<Root>/IPC Interrupt' */
void isr_int1pie14_task_fcn(void)
{
  /* Call the system: <Root>/IPC 1 */
  {
    /* S-Function (c28xisr_c2000): '<Root>/IPC Interrupt' */

    /* Output and update for function-call system: '<Root>/IPC 1' */

    /* S-Function (c28xipc_rx): '<S1>/IPC Receive1' */
    MW_IPC_Receive(CHANNEL1, (uint32_t *)
                   &F28379D_IPC_CPU2_2020a_B.IPCReceive1_o1[0],
                   &F28379D_IPC_CPU2_2020a_B.IPCReceive1_o2, 4, 8, 0, 0);

    /* End of Outputs for S-Function (c28xisr_c2000): '<Root>/IPC Interrupt' */

    /* RateTransition generated from: '<S3>/Subtract' */
    F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport1_Buffer[F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport1_semapho
      == 0] = F28379D_IPC_CPU2_2020a_B.IPCReceive1_o1[3];
    F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport1_ActiveB =
      (F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport1_semapho == 0);

    /* RateTransition generated from: '<S6>/Subtract' */
    F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport2_Buffer
      [(F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport2_semapho == 0) << 1U]
      = F28379D_IPC_CPU2_2020a_B.IPCReceive1_o1[0];
    F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport2_Buffer[1 +
      ((F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport2_semapho == 0) << 1U)]
      = F28379D_IPC_CPU2_2020a_B.IPCReceive1_o1[1];
    F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport2_ActiveB =
      (F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport2_semapho == 0);

    /* RateTransition generated from: '<S6>/heading error in [-pi,pi]' */
    F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtheadingerrorinpipiInpor[F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtheadingerrorinpipiInp_p
      == 0] = F28379D_IPC_CPU2_2020a_B.IPCReceive1_o1[2];
    F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtheadingerrorinpipiInp_b =
      (F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtheadingerrorinpipiInp_p == 0);
  }
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void F28379D_IPC_CPU2_2020a_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(F28379D_IPC_CPU2_2020a_M, 2));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (F28379D_IPC_CPU2_2020a_M->Timing.TaskCounters.TID[1] == 0) {
    F28379D_IPC_CPU2_2020a_M->Timing.RateInteraction.TID1_2 =
      (F28379D_IPC_CPU2_2020a_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (F28379D_IPC_CPU2_2020a_M->Timing.TaskCounters.TID[2])++;
  if ((F28379D_IPC_CPU2_2020a_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.005s, 0.0s] */
    F28379D_IPC_CPU2_2020a_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  F28379D_IPC_CPU2_2020a_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  F28379D_IPC_CPU2_2020a_step0();
  F28379D_IPC_CPU2_2020a_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  F28379D_IPC_CPU2_2020a_step0();
  F28379D_IPC_CPU2_2020a_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  int16_T tmp;
  int16_T tmp_0;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    if (u1 > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = (real32_T)atan2(tmp_0, tmp);
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = (real32_T)atan2(u0, u1);
  }

  return y;
}

/* Model step function for TID0 */
void F28379D_IPC_CPU2_2020a_step0(void) /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(F28379D_IPC_CPU2_2020a_M)) {
    /* set solver stop time */
    if (!(F28379D_IPC_CPU2_2020a_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&F28379D_IPC_CPU2_2020a_M->solverInfo,
                            ((F28379D_IPC_CPU2_2020a_M->Timing.clockTickH0 + 1) *
        F28379D_IPC_CPU2_2020a_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&F28379D_IPC_CPU2_2020a_M->solverInfo,
                            ((F28379D_IPC_CPU2_2020a_M->Timing.clockTick0 + 1) *
        F28379D_IPC_CPU2_2020a_M->Timing.stepSize0 +
        F28379D_IPC_CPU2_2020a_M->Timing.clockTickH0 *
        F28379D_IPC_CPU2_2020a_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(F28379D_IPC_CPU2_2020a_M)) {
    F28379D_IPC_CPU2_2020a_M->Timing.t[0] = rtsiGetT
      (&F28379D_IPC_CPU2_2020a_M->solverInfo);
  }

  /* S-Function (c28xisr_c2000): '<Root>/IPC Interrupt' */
  /* RateTransition generated from: '<Root>/single_array1' */
  if (rtmIsMajorTimeStep(F28379D_IPC_CPU2_2020a_M)) {
    /* RateTransition generated from: '<S3>/Subtract' */
    F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport1_semapho =
      F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport1_ActiveB;
    F28379D_IPC_CPU2_2020a_B.TmpRTBAtSubtractInport1 =
      F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport1_Buffer[F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport1_semapho];
    if (F28379D_IPC_CPU2_2020a_M->Timing.RateInteraction.TID1_2) {
      F28379D_IPC_CPU2_2020a_B.TmpRTBAtsingle_array1Inport2 =
        F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtsingle_array1Inport2_Bu;
    }
  }

  /* End of RateTransition generated from: '<Root>/single_array1' */
  /* End of Outputs for S-Function (c28xisr_c2000): '<Root>/IPC Interrupt' */

  /* Sum: '<S3>/Subtract' incorporates:
   *  Constant: '<S3>/DesiredVelocity'
   */
  F28379D_IPC_CPU2_2020a_B.Subtract =
    F28379D_IPC_CPU2_2020a_P.DesiredVelocity_Value -
    F28379D_IPC_CPU2_2020a_B.TmpRTBAtSubtractInport1;

  /* Gain: '<S3>/Kp' */
  F28379D_IPC_CPU2_2020a_B.Kp = F28379D_IPC_CPU2_2020a_P.Kp_Gain *
    F28379D_IPC_CPU2_2020a_B.Subtract;

  /* Integrator: '<S3>/Integrator' */
  F28379D_IPC_CPU2_2020a_B.Integrator =
    F28379D_IPC_CPU2_2020a_X.Integrator_CSTATE;

  /* Gain: '<S3>/Ki' */
  F28379D_IPC_CPU2_2020a_B.Ki = (real32_T)(F28379D_IPC_CPU2_2020a_P.Ki_Gain *
    F28379D_IPC_CPU2_2020a_B.Integrator);

  /* Sum: '<S3>/Subtract1' */
  F28379D_IPC_CPU2_2020a_B.Subtract1 = F28379D_IPC_CPU2_2020a_B.Kp +
    F28379D_IPC_CPU2_2020a_B.Ki;

  /* MATLAB Function: '<Root>/single_array1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  /* MATLAB Function 'single_array1': '<S7>:1' */
  /* '<S7>:1:3' */
  F28379D_IPC_CPU2_2020a_B.output_array[0] = F28379D_IPC_CPU2_2020a_B.Subtract1;
  F28379D_IPC_CPU2_2020a_B.output_array[1] =
    F28379D_IPC_CPU2_2020a_B.TmpRTBAtsingle_array1Inport2;
  F28379D_IPC_CPU2_2020a_B.output_array[2] = (real32_T)
    F28379D_IPC_CPU2_2020a_P.Constant1_Value;
  F28379D_IPC_CPU2_2020a_B.output_array[3] = (real32_T)
    F28379D_IPC_CPU2_2020a_P.Constant1_Value;

  /* S-Function (c28xipc_tx): '<Root>/IPC Transmit 1' */
  MW_IPC_Transmit(CHANNEL1, (uint32_t *)&F28379D_IPC_CPU2_2020a_B.output_array[0],
                  4, 8, 0, 0);

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  F28379D_IPC_CPU2_2020a_B.DataTypeConversion =
    F28379D_IPC_CPU2_2020a_B.Subtract;
  if (rtmIsMajorTimeStep(F28379D_IPC_CPU2_2020a_M)) {
    rt_ertODEUpdateContinuousStates(&F28379D_IPC_CPU2_2020a_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++F28379D_IPC_CPU2_2020a_M->Timing.clockTick0)) {
      ++F28379D_IPC_CPU2_2020a_M->Timing.clockTickH0;
    }

    F28379D_IPC_CPU2_2020a_M->Timing.t[0] = rtsiGetSolverStopTime
      (&F28379D_IPC_CPU2_2020a_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    F28379D_IPC_CPU2_2020a_M->Timing.clockTick1++;
    if (!F28379D_IPC_CPU2_2020a_M->Timing.clockTick1) {
      F28379D_IPC_CPU2_2020a_M->Timing.clockTickH1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void F28379D_IPC_CPU2_2020a_derivatives(void)
{
  StateDerivatives_F28379D_IPC_CP *_rtXdot;
  _rtXdot = ((StateDerivatives_F28379D_IPC_CP *)
             F28379D_IPC_CPU2_2020a_M->derivs);

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE = F28379D_IPC_CPU2_2020a_B.DataTypeConversion;
}

/* Model step function for TID2 */
void F28379D_IPC_CPU2_2020a_step2(void) /* Sample time: [0.005s, 0.0s] */
{
  real_T i;
  real32_T x_t;
  real32_T y_t;
  int16_T tmp;
  int32_T exitg1;

  /* S-Function (c280xcanrcv): '<Root>/CAN External Receive' */
  {
    tCANMsgObject sRXCANMessage;
    unsigned char ucRXMsgData[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

    sRXCANMessage.ui32MsgID = 1;       // CAN message ID
    sRXCANMessage.ui32MsgIDMask = 0;   // no mask needed for TX
    sRXCANMessage.ui32Flags = MSG_OBJ_NO_FLAGS;
    sRXCANMessage.ui32MsgLen = sizeof(ucRXMsgData);// size of message
    sRXCANMessage.pucMsgData = ucRXMsgData;// ptr to message content

    // Get the receive message
    CANMessageGet(CANB_BASE, 1, &sRXCANMessage, false);
    if (sRXCANMessage.ui32MsgLen > 0) {
      F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Extended = 0;
      F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Length =
        sRXCANMessage.ui32MsgLen;
      F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.ID = 1;
      F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[0] = ucRXMsgData[0];
      F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[1] = ucRXMsgData[1];
      F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[2] = ucRXMsgData[2];
      F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[3] = ucRXMsgData[3];
      F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[4] = ucRXMsgData[4];
      F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[5] = ucRXMsgData[5];
      F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[6] = ucRXMsgData[6];
      F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[7] = ucRXMsgData[7];

      /* -- Call CAN RX Fcn-Call_0 -- */

      /* Output and update for function-call system: '<Root>/Msg Converter' */

      /* S-Function (scanunpack): '<S2>/CAN Unpack1' */
      {
        /* S-Function (scanunpack): '<S2>/CAN Unpack1' */
        uint8_T msgReceived = 0;
        if ((8 == F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Length) &&
            (F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.ID != INVALID_CAN_ID)
            ) {
          if ((1 == F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.ID) && (0U ==
               F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Extended) ) {
            msgReceived = 1;

            {
              /* --------------- START Unpacking signal 0 ------------------
               *  startBit                = 0
               *  length                  = 8
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)
                        (F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[0]);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  F28379D_IPC_CPU2_2020a_B.CANUnpack1_o1 = result;
                }
              }

              /* --------------- START Unpacking signal 1 ------------------
               *  startBit                = 8
               *  length                  = 8
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)
                        (F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[1]);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  F28379D_IPC_CPU2_2020a_B.CANUnpack1_o2 = result;
                }
              }

              /* --------------- START Unpacking signal 2 ------------------
               *  startBit                = 16
               *  length                  = 8
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)
                        (F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[2]);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  F28379D_IPC_CPU2_2020a_B.CANUnpack1_o3 = result;
                }
              }

              /* --------------- START Unpacking signal 3 ------------------
               *  startBit                = 24
               *  length                  = 8
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)
                        (F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[3]);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  F28379D_IPC_CPU2_2020a_B.CANUnpack1_o4 = result;
                }
              }

              /* --------------- START Unpacking signal 4 ------------------
               *  startBit                = 32
               *  length                  = 8
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)
                        (F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[4]);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  F28379D_IPC_CPU2_2020a_B.CANUnpack1_o5 = result;
                }
              }

              /* --------------- START Unpacking signal 5 ------------------
               *  startBit                = 40
               *  length                  = 8
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)
                        (F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[5]);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  F28379D_IPC_CPU2_2020a_B.CANUnpack1_o6 = result;
                }
              }

              /* --------------- START Unpacking signal 6 ------------------
               *  startBit                = 48
               *  length                  = 8
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)
                        (F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[6]);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  F28379D_IPC_CPU2_2020a_B.CANUnpack1_o7 = result;
                }
              }

              /* --------------- START Unpacking signal 7 ------------------
               *  startBit                = 56
               *  length                  = 8
               *  desiredSignalByteLayout = LITTLEENDIAN
               *  dataType                = UNSIGNED
               *  factor                  = 1.0
               *  offset                  = 0.0
               * -----------------------------------------------------------------------*/
              {
                real64_T outValue = 0;

                {
                  uint8_T unpackedValue = 0;

                  {
                    uint8_T tempValue = (uint8_T) (0);

                    {
                      tempValue = tempValue | (uint8_T)
                        (F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[7]);
                    }

                    unpackedValue = tempValue;
                  }

                  outValue = (real64_T) (unpackedValue);
                }

                {
                  real64_T result = (real64_T) outValue;
                  F28379D_IPC_CPU2_2020a_B.CANUnpack1_o8 = result;
                }
              }
            }

            /* Extract the length */
            F28379D_IPC_CPU2_2020a_B.CANUnpack1_o9 =
              F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Length;
          }
        }

        /* Status port */
        F28379D_IPC_CPU2_2020a_B.CANUnpack1_o10 = msgReceived;
      }

      /* DataTypeConversion: '<S2>/Data Type Conversion' */
      F28379D_IPC_CPU2_2020a_B.DataTypeConversion_h = (uint16_T)
        F28379D_IPC_CPU2_2020a_B.CANUnpack1_o1 & 255U;

      /* DataTypeConversion: '<S2>/Data Type Conversion1' */
      F28379D_IPC_CPU2_2020a_B.DataTypeConversion1 = (uint16_T)
        F28379D_IPC_CPU2_2020a_B.CANUnpack1_o2 & 255U;

      /* DataTypeConversion: '<S2>/Data Type Conversion2' */
      F28379D_IPC_CPU2_2020a_B.DataTypeConversion2 = (uint16_T)
        F28379D_IPC_CPU2_2020a_B.CANUnpack1_o3 & 255U;

      /* DataTypeConversion: '<S2>/Data Type Conversion3' */
      F28379D_IPC_CPU2_2020a_B.DataTypeConversion3 = (uint16_T)
        F28379D_IPC_CPU2_2020a_B.CANUnpack1_o4 & 255U;

      /* DataTypeConversion: '<S2>/Data Type Conversion4' */
      F28379D_IPC_CPU2_2020a_B.DataTypeConversion4 = (uint16_T)
        F28379D_IPC_CPU2_2020a_B.CANUnpack1_o5 & 255U;

      /* DataTypeConversion: '<S2>/Data Type Conversion5' */
      F28379D_IPC_CPU2_2020a_B.DataTypeConversion5 = (uint16_T)
        F28379D_IPC_CPU2_2020a_B.CANUnpack1_o6 & 255U;

      /* DataTypeConversion: '<S2>/Data Type Conversion6' */
      F28379D_IPC_CPU2_2020a_B.DataTypeConversion6 = (uint16_T)
        F28379D_IPC_CPU2_2020a_B.CANUnpack1_o7 & 255U;

      /* DataTypeConversion: '<S2>/Data Type Conversion7' */
      F28379D_IPC_CPU2_2020a_B.DataTypeConversion7 = (uint16_T)
        F28379D_IPC_CPU2_2020a_B.CANUnpack1_o8 & 255U;
    }
  }

  /* End of Outputs for S-Function (c280xcanrcv): '<Root>/CAN External Receive' */

  /* MATLAB Function: '<Root>/u2f_1' */
  uint16Tofloat16(F28379D_IPC_CPU2_2020a_B.DataTypeConversion_h,
                  F28379D_IPC_CPU2_2020a_B.DataTypeConversion1,
                  &F28379D_IPC_CPU2_2020a_B.sf_u2f_1);

  /* MATLAB Function: '<Root>/u2f_2' */
  uint16Tofloat16(F28379D_IPC_CPU2_2020a_B.DataTypeConversion2,
                  F28379D_IPC_CPU2_2020a_B.DataTypeConversion3,
                  &F28379D_IPC_CPU2_2020a_B.sf_u2f_2);

  /* MATLAB Function: '<Root>/u2f_3' */
  uint16Tofloat16(F28379D_IPC_CPU2_2020a_B.DataTypeConversion4,
                  F28379D_IPC_CPU2_2020a_B.DataTypeConversion5,
                  &F28379D_IPC_CPU2_2020a_B.sf_u2f_3);

  /* MATLAB Function: '<Root>/u2f_4' */
  uint16Tofloat16(F28379D_IPC_CPU2_2020a_B.DataTypeConversion6,
                  F28379D_IPC_CPU2_2020a_B.DataTypeConversion7,
                  &F28379D_IPC_CPU2_2020a_B.sf_u2f_4);

  /* MATLAB Function: '<Root>/list parameter in an array' */
  /* MATLAB Function 'list parameter in an array': '<S5>:1' */
  /* '<S5>:1:3' */
  F28379D_IPC_CPU2_2020a_B.output_array_e[0] =
    F28379D_IPC_CPU2_2020a_B.sf_u2f_1.result;
  F28379D_IPC_CPU2_2020a_B.output_array_e[1] =
    F28379D_IPC_CPU2_2020a_B.sf_u2f_2.result;
  F28379D_IPC_CPU2_2020a_B.output_array_e[2] =
    F28379D_IPC_CPU2_2020a_B.sf_u2f_3.result;
  F28379D_IPC_CPU2_2020a_B.output_array_e[3] =
    F28379D_IPC_CPU2_2020a_B.sf_u2f_4.result;

  /* MATLAB Function: '<Root>/find look-ahead points' */
  /* MATLAB Function 'find look-ahead points': '<S4>:1' */
  /* '<S4>:1:3' */
  i = 0.0;
  do {
    exitg1 = 0L;

    /* '<S4>:1:6' */
    x_t = F28379D_IPC_CPU2_2020a_P.lookaheaddistance_Value - (real32_T)i;

    /* '<S4>:1:7' */
    y_t = ((x_t * x_t * F28379D_IPC_CPU2_2020a_B.output_array_e[2] +
            F28379D_IPC_CPU2_2020a_B.output_array_e[3] * rt_powf_snf(x_t, 3.0F))
           + F28379D_IPC_CPU2_2020a_B.output_array_e[1] * x_t) +
      F28379D_IPC_CPU2_2020a_B.output_array_e[0];

    /* '<S4>:1:9' */
    if (x_t <= 0.01) {
      /* '<S4>:1:10' */
      /* '<S4>:1:11' */
      F28379D_IPC_CPU2_2020a_B.x_lh =
        F28379D_IPC_CPU2_2020a_P.lookaheaddistance_Value;

      /* '<S4>:1:12' */
      F28379D_IPC_CPU2_2020a_B.y_lh = 0.0F;
      exitg1 = 1L;
    } else if (fabsf((real32_T)sqrt(x_t * x_t + y_t * y_t) -
                     F28379D_IPC_CPU2_2020a_P.lookaheaddistance_Value) <= 0.01)
    {
      /* '<S4>:1:15' */
      /* '<S4>:1:16' */
      F28379D_IPC_CPU2_2020a_B.x_lh = x_t;

      /* '<S4>:1:17' */
      F28379D_IPC_CPU2_2020a_B.y_lh = y_t;
      exitg1 = 1L;
    } else {
      /* '<S4>:1:20' */
      i += 0.01;
    }
  } while (exitg1 == 0L);

  /* RateTransition generated from: '<S6>/Subtract' */
  F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport2_semapho =
    F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport2_ActiveB;
  tmp = F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport2_semapho << 1U;
  F28379D_IPC_CPU2_2020a_B.TmpRTBAtSubtractInport2[0] =
    F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport2_Buffer[tmp];
  F28379D_IPC_CPU2_2020a_B.TmpRTBAtSubtractInport2[1] =
    F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport2_Buffer[tmp + 1];

  /* Sum: '<S6>/Subtract' */
  F28379D_IPC_CPU2_2020a_B.Subtract_l[0] = F28379D_IPC_CPU2_2020a_B.x_lh -
    F28379D_IPC_CPU2_2020a_B.TmpRTBAtSubtractInport2[0];
  F28379D_IPC_CPU2_2020a_B.Subtract_l[1] = F28379D_IPC_CPU2_2020a_B.y_lh -
    F28379D_IPC_CPU2_2020a_B.TmpRTBAtSubtractInport2[1];

  /* Trigonometry: '<S6>/Atan2' */
  F28379D_IPC_CPU2_2020a_B.Atan2 = rt_atan2f_snf
    (F28379D_IPC_CPU2_2020a_B.Subtract_l[1],
     F28379D_IPC_CPU2_2020a_B.Subtract_l[0]);

  /* RateTransition generated from: '<S6>/heading error in [-pi,pi]' */
  F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtheadingerrorinpipiInp_p =
    F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtheadingerrorinpipiInp_b;
  F28379D_IPC_CPU2_2020a_B.TmpRTBAtheadingerrorinpipiInpor =
    F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtheadingerrorinpipiInpor[F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtheadingerrorinpipiInp_p];

  /* MATLAB Function: '<S6>/heading error in [-pi,pi]' */
  /* MATLAB Function 'pure pursuit lateral controller/heading error in [-pi,pi]': '<S12>:1' */
  /* '<S12>:1:2' */
  for (x_t = F28379D_IPC_CPU2_2020a_B.Atan2 -
       F28379D_IPC_CPU2_2020a_B.TmpRTBAtheadingerrorinpipiInpor; x_t >
       3.1415926535897931; x_t -= 6.28318548F) {
    /* '<S12>:1:3' */
    /* '<S12>:1:4' */
  }

  while (x_t < -3.1415926535897931) {
    /* '<S12>:1:7' */
    /* '<S12>:1:8' */
    x_t += 6.28318548F;
  }

  /* '<S12>:1:10' */
  F28379D_IPC_CPU2_2020a_B.y = x_t;

  /* End of MATLAB Function: '<S6>/heading error in [-pi,pi]' */

  /* Gain: '<S6>/Gain' */
  F28379D_IPC_CPU2_2020a_B.Gain = F28379D_IPC_CPU2_2020a_P.Gain_Gain *
    F28379D_IPC_CPU2_2020a_B.y;

  /* RateTransition generated from: '<Root>/single_array1' */
  F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtsingle_array1Inport2_Bu =
    F28379D_IPC_CPU2_2020a_B.Gain;
}

/* Model initialize function */
void F28379D_IPC_CPU2_2020a_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)F28379D_IPC_CPU2_2020a_M, 0,
                sizeof(RT_MODEL_F28379D_IPC_CPU2_2020a));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&F28379D_IPC_CPU2_2020a_M->solverInfo,
                          &F28379D_IPC_CPU2_2020a_M->Timing.simTimeStep);
    rtsiSetTPtr(&F28379D_IPC_CPU2_2020a_M->solverInfo, &rtmGetTPtr
                (F28379D_IPC_CPU2_2020a_M));
    rtsiSetStepSizePtr(&F28379D_IPC_CPU2_2020a_M->solverInfo,
                       &F28379D_IPC_CPU2_2020a_M->Timing.stepSize0);
    rtsiSetdXPtr(&F28379D_IPC_CPU2_2020a_M->solverInfo,
                 &F28379D_IPC_CPU2_2020a_M->derivs);
    rtsiSetContStatesPtr(&F28379D_IPC_CPU2_2020a_M->solverInfo, (real_T **)
                         &F28379D_IPC_CPU2_2020a_M->contStates);
    rtsiSetNumContStatesPtr(&F28379D_IPC_CPU2_2020a_M->solverInfo,
      &F28379D_IPC_CPU2_2020a_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&F28379D_IPC_CPU2_2020a_M->solverInfo,
      &F28379D_IPC_CPU2_2020a_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&F28379D_IPC_CPU2_2020a_M->solverInfo,
      &F28379D_IPC_CPU2_2020a_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&F28379D_IPC_CPU2_2020a_M->solverInfo,
      &F28379D_IPC_CPU2_2020a_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&F28379D_IPC_CPU2_2020a_M->solverInfo,
                          (&rtmGetErrorStatus(F28379D_IPC_CPU2_2020a_M)));
    rtsiSetRTModelPtr(&F28379D_IPC_CPU2_2020a_M->solverInfo,
                      F28379D_IPC_CPU2_2020a_M);
  }

  rtsiSetSimTimeStep(&F28379D_IPC_CPU2_2020a_M->solverInfo, MAJOR_TIME_STEP);
  F28379D_IPC_CPU2_2020a_M->intgData.y = F28379D_IPC_CPU2_2020a_M->odeY;
  F28379D_IPC_CPU2_2020a_M->intgData.f[0] = F28379D_IPC_CPU2_2020a_M->odeF[0];
  F28379D_IPC_CPU2_2020a_M->intgData.f[1] = F28379D_IPC_CPU2_2020a_M->odeF[1];
  F28379D_IPC_CPU2_2020a_M->intgData.f[2] = F28379D_IPC_CPU2_2020a_M->odeF[2];
  F28379D_IPC_CPU2_2020a_M->contStates = ((ContinuousStates_F28379D_IPC_CP *)
    &F28379D_IPC_CPU2_2020a_X);
  rtsiSetSolverData(&F28379D_IPC_CPU2_2020a_M->solverInfo, (void *)
                    &F28379D_IPC_CPU2_2020a_M->intgData);
  rtsiSetSolverName(&F28379D_IPC_CPU2_2020a_M->solverInfo,"ode3");
  rtmSetTPtr(F28379D_IPC_CPU2_2020a_M, &F28379D_IPC_CPU2_2020a_M->Timing.tArray
             [0]);
  F28379D_IPC_CPU2_2020a_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &F28379D_IPC_CPU2_2020a_B), 0,
                sizeof(BlockIO_F28379D_IPC_CPU2_2020a));

  {
    F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2 = CAN_DATATYPE_GROUND;
    F28379D_IPC_CPU2_2020a_B.Integrator = 0.0;
    F28379D_IPC_CPU2_2020a_B.DataTypeConversion = 0.0;
    F28379D_IPC_CPU2_2020a_B.CANUnpack1_o1 = 0.0;
    F28379D_IPC_CPU2_2020a_B.CANUnpack1_o2 = 0.0;
    F28379D_IPC_CPU2_2020a_B.CANUnpack1_o3 = 0.0;
    F28379D_IPC_CPU2_2020a_B.CANUnpack1_o4 = 0.0;
    F28379D_IPC_CPU2_2020a_B.CANUnpack1_o5 = 0.0;
    F28379D_IPC_CPU2_2020a_B.CANUnpack1_o6 = 0.0;
    F28379D_IPC_CPU2_2020a_B.CANUnpack1_o7 = 0.0;
    F28379D_IPC_CPU2_2020a_B.CANUnpack1_o8 = 0.0;
    F28379D_IPC_CPU2_2020a_B.TmpRTBAtSubtractInport1 = 0.0F;
    F28379D_IPC_CPU2_2020a_B.Subtract = 0.0F;
    F28379D_IPC_CPU2_2020a_B.Kp = 0.0F;
    F28379D_IPC_CPU2_2020a_B.Ki = 0.0F;
    F28379D_IPC_CPU2_2020a_B.Subtract1 = 0.0F;
    F28379D_IPC_CPU2_2020a_B.TmpRTBAtsingle_array1Inport2 = 0.0F;
    F28379D_IPC_CPU2_2020a_B.TmpRTBAtSubtractInport2[0] = 0.0F;
    F28379D_IPC_CPU2_2020a_B.TmpRTBAtSubtractInport2[1] = 0.0F;
    F28379D_IPC_CPU2_2020a_B.Subtract_l[0] = 0.0F;
    F28379D_IPC_CPU2_2020a_B.Subtract_l[1] = 0.0F;
    F28379D_IPC_CPU2_2020a_B.Atan2 = 0.0F;
    F28379D_IPC_CPU2_2020a_B.TmpRTBAtheadingerrorinpipiInpor = 0.0F;
    F28379D_IPC_CPU2_2020a_B.Gain = 0.0F;
    F28379D_IPC_CPU2_2020a_B.output_array[0] = 0.0F;
    F28379D_IPC_CPU2_2020a_B.output_array[1] = 0.0F;
    F28379D_IPC_CPU2_2020a_B.output_array[2] = 0.0F;
    F28379D_IPC_CPU2_2020a_B.output_array[3] = 0.0F;
    F28379D_IPC_CPU2_2020a_B.y = 0.0F;
    F28379D_IPC_CPU2_2020a_B.output_array_e[0] = 0.0F;
    F28379D_IPC_CPU2_2020a_B.output_array_e[1] = 0.0F;
    F28379D_IPC_CPU2_2020a_B.output_array_e[2] = 0.0F;
    F28379D_IPC_CPU2_2020a_B.output_array_e[3] = 0.0F;
    F28379D_IPC_CPU2_2020a_B.x_lh = 0.0F;
    F28379D_IPC_CPU2_2020a_B.y_lh = 0.0F;
    F28379D_IPC_CPU2_2020a_B.IPCReceive1_o1[0] = 0.0F;
    F28379D_IPC_CPU2_2020a_B.IPCReceive1_o1[1] = 0.0F;
    F28379D_IPC_CPU2_2020a_B.IPCReceive1_o1[2] = 0.0F;
    F28379D_IPC_CPU2_2020a_B.IPCReceive1_o1[3] = 0.0F;
    F28379D_IPC_CPU2_2020a_B.sf_u2f_4.result = 0.0F;
    F28379D_IPC_CPU2_2020a_B.sf_u2f_3.result = 0.0F;
    F28379D_IPC_CPU2_2020a_B.sf_u2f_2.result = 0.0F;
    F28379D_IPC_CPU2_2020a_B.sf_u2f_1.result = 0.0F;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&F28379D_IPC_CPU2_2020a_X, 0,
                  sizeof(ContinuousStates_F28379D_IPC_CP));
  }

  /* states (dwork) */
  (void) memset((void *)&F28379D_IPC_CPU2_2020a_DWork, 0,
                sizeof(D_Work_F28379D_IPC_CPU2_2020a));
  F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport1_Buffer[0] = 0.0F;
  F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport1_Buffer[1] = 0.0F;
  F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtsingle_array1Inport2_Bu = 0.0F;
  F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport2_Buffer[0] = 0.0F;
  F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport2_Buffer[1] = 0.0F;
  F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport2_Buffer[2] = 0.0F;
  F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport2_Buffer[3] = 0.0F;
  F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtheadingerrorinpipiInpor[0] = 0.0F;
  F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtheadingerrorinpipiInpor[1] = 0.0F;

  /* Start for S-Function (c28xisr_c2000): '<Root>/IPC Interrupt' incorporates:
   *  SubSystem: '<Root>/IPC 1'
   */

  /* Start for function-call system: '<Root>/IPC 1' */

  /* Start for S-Function (c28xipc_rx): '<S1>/IPC Receive1' */
  IPCInit(CHANNEL1, 4, 0);

  /* End of Start for S-Function (c28xisr_c2000): '<Root>/IPC Interrupt' */

  /* Start for RateTransition generated from: '<Root>/single_array1' */
  F28379D_IPC_CPU2_2020a_B.TmpRTBAtsingle_array1Inport2 =
    F28379D_IPC_CPU2_2020a_P.TmpRTBAtsingle_array1Inport2_In;

  /* Start for S-Function (c28xipc_tx): '<Root>/IPC Transmit 1' */
  IPCInit(CHANNEL1, 4, 0);

  /* Start for S-Function (c280xcanrcv): '<Root>/CAN External Receive' incorporates:
   *  SubSystem: '<Root>/Msg Converter'
   */

  /* Start for function-call system: '<Root>/Msg Converter' */

  /* Start for S-Function (scanunpack): '<S2>/CAN Unpack1' */

  /*-----------S-Function Block: <S2>/CAN Unpack1 -----------------*/
  {
    tCANMsgObject sRXCANMessage;
    unsigned char ucRXMsgData[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    sRXCANMessage.ui32MsgID = 1;       // CAN message ID
    sRXCANMessage.ui32MsgIDMask = 0;   // no mask needed for TX
    sRXCANMessage.ui32Flags = MSG_OBJ_NO_FLAGS;
    sRXCANMessage.ui32MsgLen = sizeof(ucRXMsgData);// size of message is 4
    sRXCANMessage.pucMsgData = ucRXMsgData;// ptr to message content

    // Setup the message object being used to receive messages
    CANMessageSet(CANB_BASE, 1, &sRXCANMessage, MSG_OBJ_TYPE_RX);
  }

  /* Initialize F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2 */
  {
    F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Extended = 0;
    F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Length = 8;
    F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.ID = 1;
    F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[0] = (uint8_T)0.0;
    F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[1] = (uint8_T)0.0;
    F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[2] = (uint8_T)0.0;
    F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[3] = (uint8_T)0.0;
    F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[4] = (uint8_T)0.0;
    F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[5] = (uint8_T)0.0;
    F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[6] = (uint8_T)0.0;
    F28379D_IPC_CPU2_2020a_B.CANExternalReceive_o2.Data[7] = (uint8_T)0.0;
  }

  /* End of Start for S-Function (c280xcanrcv): '<Root>/CAN External Receive' */

  /* InitializeConditions for RateTransition generated from: '<S3>/Subtract' */
  F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport1_Buffer[0] =
    F28379D_IPC_CPU2_2020a_P.TmpRTBAtSubtractInport1_Initial;

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  F28379D_IPC_CPU2_2020a_X.Integrator_CSTATE =
    F28379D_IPC_CPU2_2020a_P.Integrator_IC;

  /* InitializeConditions for RateTransition generated from: '<Root>/single_array1' */
  F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtsingle_array1Inport2_Bu =
    F28379D_IPC_CPU2_2020a_P.TmpRTBAtsingle_array1Inport2_In;

  /* InitializeConditions for RateTransition generated from: '<S6>/Subtract' */
  F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport2_Buffer[0] =
    F28379D_IPC_CPU2_2020a_P.TmpRTBAtSubtractInport2_Initial;
  F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtSubtractInport2_Buffer[1] =
    F28379D_IPC_CPU2_2020a_P.TmpRTBAtSubtractInport2_Initial;

  /* InitializeConditions for RateTransition generated from: '<S6>/heading error in [-pi,pi]' */
  F28379D_IPC_CPU2_2020a_DWork.TmpRTBAtheadingerrorinpipiInpor[0] =
    F28379D_IPC_CPU2_2020a_P.TmpRTBAtheadingerrorinpipiInpor;
}

/* Model terminate function */
void F28379D_IPC_CPU2_2020a_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
