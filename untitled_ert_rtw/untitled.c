/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue May 28 20:24:51 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "rtwtypes.h"
#include "untitled_private.h"
#include "untitled_dt.h"

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void untitled_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(untitled_M, 2));
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
  if (untitled_M->Timing.TaskCounters.TID[1] == 0) {
    untitled_M->Timing.RateInteraction.TID1_2 =
      (untitled_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (untitled_M->Timing.TaskCounters.TID[2])++;
  if ((untitled_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.02s, 0.0s] */
    untitled_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model step function for TID0 */
void untitled_step0(void)              /* Sample time: [0.0s, 0.0s] */
{
  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/Rate Transition' */
  if (untitled_M->Timing.RateInteraction.TID1_2) {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Clock: '<Root>/Clock1'
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Initial1'
     *  Constant: '<S1>/Constant'
     *  RelationalOperator: '<S1>/Compare'
     */
    if (untitled_M->Timing.t[0] <= untitled_P.CompareToConstant1_const) {
      untitled_DW.RateTransition_Buffer[0] = untitled_P.Initial1_Value[0];
      untitled_DW.RateTransition_Buffer[1] = untitled_P.Initial1_Value[1];
      untitled_DW.RateTransition_Buffer[2] = untitled_P.Initial1_Value[2];
      untitled_DW.RateTransition_Buffer[3] = untitled_P.Initial1_Value[3];
    } else {
      untitled_DW.RateTransition_Buffer[0] = untitled_P.Constant_Value[0];
      untitled_DW.RateTransition_Buffer[1] = untitled_P.Constant_Value[1];
      untitled_DW.RateTransition_Buffer[2] = untitled_P.Constant_Value[2];
      untitled_DW.RateTransition_Buffer[3] = untitled_P.Constant_Value[3];
    }

    /* End of Switch: '<Root>/Switch1' */
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* External mode */
  rtExtModeUploadCheckTrigger(3);
  rtExtModeUpload(1, (real_T)untitled_M->Timing.t[0]);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(untitled_M)!=-1) &&
        !((rtmGetTFinal(untitled_M)-untitled_M->Timing.t[0]) >
          untitled_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled_M)) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.t[0] =
    ((time_T)(++untitled_M->Timing.clockTick0)) * untitled_M->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  untitled_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void untitled_step2(void)              /* Sample time: [0.02s, 0.0s] */
{
  /* MATLABSystem: '<Root>/Motor 1' incorporates:
   *  RateTransition: '<Root>/Rate Transition'
   */
  rc_servo_send_pulse_normalized(1, (untitled_DW.RateTransition_Buffer[0] - 90.0)
    / 60.0);

  /* MATLABSystem: '<Root>/Motor 2' incorporates:
   *  RateTransition: '<Root>/Rate Transition'
   */
  rc_servo_send_pulse_normalized(2, (untitled_DW.RateTransition_Buffer[1] - 90.0)
    / 60.0);

  /* MATLABSystem: '<Root>/Motor 3' incorporates:
   *  RateTransition: '<Root>/Rate Transition'
   */
  rc_servo_send_pulse_normalized(3, (untitled_DW.RateTransition_Buffer[2] - 90.0)
    / 60.0);

  /* MATLABSystem: '<Root>/Motor 4' incorporates:
   *  RateTransition: '<Root>/Rate Transition'
   */
  rc_servo_send_pulse_normalized(4, (untitled_DW.RateTransition_Buffer[3] - 90.0)
    / 60.0);
  rtExtModeUpload(2, (real_T)((untitled_M->Timing.clockTick2) * 0.02));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.02, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  untitled_M->Timing.clockTick2++;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void untitled_step(int_T tid)
{
  switch (tid) {
   case 0 :
    untitled_step0();
    break;

   case 2 :
    untitled_step2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, (&rtmGetErrorStatus
      (untitled_M)));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&untitled_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&untitled_M->solverInfo, false);
  rtsiSetSolverName(&untitled_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (2135034586U);
  untitled_M->Sizes.checksums[1] = (3574773840U);
  untitled_M->Sizes.checksums[2] = (1159205704U);
  untitled_M->Sizes.checksums[3] = (1046543997U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/Motor 1' */
  untitled_DW.obj_ib.matlabCodegenIsDeleted = false;
  untitled_DW.obj_ib.isInitialized = 1;
  untitled_DW.obj_ib.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Motor 2' */
  untitled_DW.obj_i.matlabCodegenIsDeleted = false;
  untitled_DW.obj_i.isInitialized = 1;
  untitled_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Motor 3' */
  untitled_DW.obj_n.matlabCodegenIsDeleted = false;
  untitled_DW.obj_n.isInitialized = 1;
  untitled_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Motor 4' */
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.isInitialized = 1;
  untitled_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Motor 1' */
  if (!untitled_DW.obj_ib.matlabCodegenIsDeleted) {
    untitled_DW.obj_ib.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_ib.isInitialized == 1) &&
        untitled_DW.obj_ib.isSetupComplete) {
      rc_servo_send_pulse_normalized(1, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Motor 1' */

  /* Terminate for MATLABSystem: '<Root>/Motor 2' */
  if (!untitled_DW.obj_i.matlabCodegenIsDeleted) {
    untitled_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_i.isInitialized == 1) &&
        untitled_DW.obj_i.isSetupComplete) {
      rc_servo_send_pulse_normalized(2, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Motor 2' */

  /* Terminate for MATLABSystem: '<Root>/Motor 3' */
  if (!untitled_DW.obj_n.matlabCodegenIsDeleted) {
    untitled_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_n.isInitialized == 1) &&
        untitled_DW.obj_n.isSetupComplete) {
      rc_servo_send_pulse_normalized(3, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Motor 3' */

  /* Terminate for MATLABSystem: '<Root>/Motor 4' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj.isInitialized == 1) && untitled_DW.obj.isSetupComplete)
    {
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
