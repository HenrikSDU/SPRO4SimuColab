/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled1.c
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue May 28 22:04:50 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled1.h"
#include "rtwtypes.h"
#include "untitled1_private.h"
#include "untitled1_dt.h"

/* Block states (default storage) */
DW_untitled1_T untitled1_DW;

/* Real-time model */
static RT_MODEL_untitled1_T untitled1_M_;
RT_MODEL_untitled1_T *const untitled1_M = &untitled1_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void untitled1_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(untitled1_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
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
  if (untitled1_M->Timing.TaskCounters.TID[1] == 0) {
    untitled1_M->Timing.RateInteraction.TID1_2 =
      (untitled1_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (untitled1_M->Timing.TaskCounters.TID[2])++;
  if ((untitled1_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.02s, 0.0s] */
    untitled1_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model step function for TID0 */
void untitled1_step0(void)             /* Sample time: [0.0s, 0.0s] */
{
  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/Rate Transition' */
  if (untitled1_M->Timing.RateInteraction.TID1_2) {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Clock: '<Root>/Clock1'
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Initial1'
     *  Constant: '<S1>/Constant'
     *  RelationalOperator: '<S1>/Compare'
     */
    if (untitled1_M->Timing.t[0] <= untitled1_P.CompareToConstant1_const) {
      untitled1_DW.RateTransition_Buffer[0] = untitled1_P.Initial1_Value[0];
      untitled1_DW.RateTransition_Buffer[1] = untitled1_P.Initial1_Value[1];
      untitled1_DW.RateTransition_Buffer[2] = untitled1_P.Initial1_Value[2];
      untitled1_DW.RateTransition_Buffer[3] = untitled1_P.Initial1_Value[3];
    } else {
      untitled1_DW.RateTransition_Buffer[0] = untitled1_P.Constant_Value[0];
      untitled1_DW.RateTransition_Buffer[1] = untitled1_P.Constant_Value[1];
      untitled1_DW.RateTransition_Buffer[2] = untitled1_P.Constant_Value[2];
      untitled1_DW.RateTransition_Buffer[3] = untitled1_P.Constant_Value[3];
    }

    /* End of Switch: '<Root>/Switch1' */
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* External mode */
  rtExtModeUploadCheckTrigger(3);
  rtExtModeUpload(1, (real_T)untitled1_M->Timing.t[0]);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(untitled1_M)!=-1) &&
        !((rtmGetTFinal(untitled1_M)-untitled1_M->Timing.t[0]) >
          untitled1_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled1_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled1_M)) {
      rtmSetErrorStatus(untitled1_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled1_M->Timing.t[0] =
    ((time_T)(++untitled1_M->Timing.clockTick0)) * untitled1_M->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  untitled1_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void untitled1_step2(void)             /* Sample time: [0.02s, 0.0s] */
{
  /* MATLABSystem: '<Root>/Motor 1' incorporates:
   *  RateTransition: '<Root>/Rate Transition'
   */
  rc_servo_send_pulse_normalized(1, (untitled1_DW.RateTransition_Buffer[0] -
    90.0) / 60.0);

  /* MATLABSystem: '<Root>/Motor 2' incorporates:
   *  RateTransition: '<Root>/Rate Transition'
   */
  rc_servo_send_pulse_normalized(2, (untitled1_DW.RateTransition_Buffer[1] -
    90.0) / 60.0);

  /* MATLABSystem: '<Root>/Motor 3' incorporates:
   *  RateTransition: '<Root>/Rate Transition'
   */
  rc_servo_send_pulse_normalized(3, (untitled1_DW.RateTransition_Buffer[2] -
    90.0) / 60.0);

  /* MATLABSystem: '<Root>/Motor 4' incorporates:
   *  RateTransition: '<Root>/Rate Transition'
   */
  rc_servo_send_pulse_normalized(4, (untitled1_DW.RateTransition_Buffer[3] -
    90.0) / 60.0);
  rtExtModeUpload(2, (real_T)((untitled1_M->Timing.clockTick2) * 0.02));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.02, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  untitled1_M->Timing.clockTick2++;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void untitled1_step(int_T tid)
{
  switch (tid) {
   case 0 :
    untitled1_step0();
    break;

   case 2 :
    untitled1_step2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void untitled1_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled1_M->solverInfo,
                          &untitled1_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled1_M->solverInfo, &rtmGetTPtr(untitled1_M));
    rtsiSetStepSizePtr(&untitled1_M->solverInfo, &untitled1_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&untitled1_M->solverInfo, (&rtmGetErrorStatus
      (untitled1_M)));
    rtsiSetRTModelPtr(&untitled1_M->solverInfo, untitled1_M);
  }

  rtsiSetSimTimeStep(&untitled1_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&untitled1_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&untitled1_M->solverInfo, false);
  rtsiSetSolverName(&untitled1_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(untitled1_M, &untitled1_M->Timing.tArray[0]);
  rtmSetTFinal(untitled1_M, 30.0);
  untitled1_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  untitled1_M->Sizes.checksums[0] = (627180478U);
  untitled1_M->Sizes.checksums[1] = (885033094U);
  untitled1_M->Sizes.checksums[2] = (1715829512U);
  untitled1_M->Sizes.checksums[3] = (714675226U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    untitled1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled1_M->extModeInfo,
      &untitled1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled1_M->extModeInfo, untitled1_M->Sizes.checksums);
    rteiSetTPtr(untitled1_M->extModeInfo, rtmGetTPtr(untitled1_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/Motor 1' */
  untitled1_DW.obj_b.matlabCodegenIsDeleted = false;
  untitled1_DW.obj_b.isInitialized = 1;
  untitled1_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Motor 2' */
  untitled1_DW.obj_l.matlabCodegenIsDeleted = false;
  untitled1_DW.obj_l.isInitialized = 1;
  untitled1_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Motor 3' */
  untitled1_DW.obj_i.matlabCodegenIsDeleted = false;
  untitled1_DW.obj_i.isInitialized = 1;
  untitled1_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Motor 4' */
  untitled1_DW.obj.matlabCodegenIsDeleted = false;
  untitled1_DW.obj.isInitialized = 1;
  untitled1_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void untitled1_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Motor 1' */
  if (!untitled1_DW.obj_b.matlabCodegenIsDeleted) {
    untitled1_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj_b.isInitialized == 1) &&
        untitled1_DW.obj_b.isSetupComplete) {
      rc_servo_send_pulse_normalized(1, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Motor 1' */

  /* Terminate for MATLABSystem: '<Root>/Motor 2' */
  if (!untitled1_DW.obj_l.matlabCodegenIsDeleted) {
    untitled1_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj_l.isInitialized == 1) &&
        untitled1_DW.obj_l.isSetupComplete) {
      rc_servo_send_pulse_normalized(2, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Motor 2' */

  /* Terminate for MATLABSystem: '<Root>/Motor 3' */
  if (!untitled1_DW.obj_i.matlabCodegenIsDeleted) {
    untitled1_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj_i.isInitialized == 1) &&
        untitled1_DW.obj_i.isSetupComplete) {
      rc_servo_send_pulse_normalized(3, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Motor 3' */

  /* Terminate for MATLABSystem: '<Root>/Motor 4' */
  if (!untitled1_DW.obj.matlabCodegenIsDeleted) {
    untitled1_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj.isInitialized == 1) &&
        untitled1_DW.obj.isSetupComplete) {
      rc_servo_send_pulse_normalized(4, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Motor 4' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
