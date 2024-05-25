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
 * C/C++ source code generated on : Sat May 25 15:33:57 2024
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

/* Block signals (default storage) */
B_untitled_T untitled_B;

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
  eventFlags[1] = ((boolean_T)rtmStepTask(untitled_M, 1));
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

  /* tid 0 shares data with slower tid rate: 1 */
  untitled_M->Timing.RateInteraction.TID0_1 =
    (untitled_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (untitled_M->Timing.TaskCounters.TID[1])++;
  if ((untitled_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.0025s, 0.0s] */
    untitled_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void untitled_step0(void)              /* Sample time: [0.00025s, 0.0s] */
{
  real_T rtb_PulseGenerator1;

  {                                    /* Sample time: [0.00025s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  rtb_PulseGenerator1 = (untitled_DW.clockTickCounter <
    untitled_P.PulseGenerator1_Duty) && (untitled_DW.clockTickCounter >= 0) ?
    untitled_P.PulseGenerator1_Amp : 0.0;
  if (untitled_DW.clockTickCounter >= untitled_P.PulseGenerator1_Period - 1.0) {
    untitled_DW.clockTickCounter = 0;
  } else {
    untitled_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator1' */

  /* RateTransition generated from: '<Root>/Manual Switch1' */
  if (untitled_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<Root>/Manual Switch1' */
    untitled_B.TmpRTBAtManualSwitch1Inport1 =
      untitled_DW.TmpRTBAtManualSwitch1Inport1_Bu;
  }

  /* End of RateTransition generated from: '<Root>/Manual Switch1' */

  /* ManualSwitch: '<Root>/Manual Switch1' */
  if (untitled_P.ManualSwitch1_CurrentSetting == 1) {
    rtb_PulseGenerator1 = untitled_B.TmpRTBAtManualSwitch1Inport1;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(untitled_DW.obj_i.MW_DIGITALIO_HANDLE, rtb_PulseGenerator1
                     != 0.0);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(untitled_DW.obj_n.MW_DIGITALIO_HANDLE, rtb_PulseGenerator1
                     != 0.0);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(untitled_DW.obj_j.MW_DIGITALIO_HANDLE, rtb_PulseGenerator1
                     != 0.0);

  /* MATLABSystem: '<Root>/Digital Write3' */
  MW_digitalIO_write(untitled_DW.obj.MW_DIGITALIO_HANDLE, rtb_PulseGenerator1 !=
                     0.0);

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)untitled_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.00025s, 0.0s] */
    if ((rtmGetTFinal(untitled_M)!=-1) &&
        !((rtmGetTFinal(untitled_M)-untitled_M->Timing.taskTime0) >
          untitled_M->Timing.taskTime0 * (DBL_EPSILON))) {
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
  untitled_M->Timing.taskTime0 =
    ((time_T)(++untitled_M->Timing.clockTick0)) * untitled_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void untitled_step1(void)              /* Sample time: [0.0025s, 0.0s] */
{
  real_T rtb_PulseGenerator2;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator2' */
  rtb_PulseGenerator2 = (untitled_DW.clockTickCounter_g <
    untitled_P.PulseGenerator2_Duty) && (untitled_DW.clockTickCounter_g >= 0) ?
    untitled_P.PulseGenerator2_Amp : 0.0;
  if (untitled_DW.clockTickCounter_g >= untitled_P.PulseGenerator2_Period - 1.0)
  {
    untitled_DW.clockTickCounter_g = 0;
  } else {
    untitled_DW.clockTickCounter_g++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator2' */

  /* RateTransition generated from: '<Root>/Manual Switch1' */
  untitled_DW.TmpRTBAtManualSwitch1Inport1_Bu = rtb_PulseGenerator2;
  rtExtModeUpload(1, (real_T)((untitled_M->Timing.clockTick1) * 0.0025));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.0025, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  untitled_M->Timing.clockTick1++;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void untitled_step(int_T tid)
{
  switch (tid) {
   case 0 :
    untitled_step0();
    break;

   case 1 :
    untitled_step1();
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
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.00025;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (1799495404U);
  untitled_M->Sizes.checksums[1] = (2151791646U);
  untitled_M->Sizes.checksums[2] = (1065890362U);
  untitled_M->Sizes.checksums[3] = (321331878U);

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

  /* Start for RateTransition generated from: '<Root>/Manual Switch1' */
  untitled_B.TmpRTBAtManualSwitch1Inport1 =
    untitled_P.TmpRTBAtManualSwitch1Inport1_In;

  /* InitializeConditions for RateTransition generated from: '<Root>/Manual Switch1' */
  untitled_DW.TmpRTBAtManualSwitch1Inport1_Bu =
    untitled_P.TmpRTBAtManualSwitch1Inport1_In;

  /* Start for MATLABSystem: '<Root>/Digital Write' */
  untitled_DW.obj_i.matlabCodegenIsDeleted = false;
  untitled_DW.obj_i.isInitialized = 1;
  untitled_DW.obj_i.MW_DIGITALIO_HANDLE = MW_digitalIO_open(57, 1);
  untitled_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write1' */
  untitled_DW.obj_n.matlabCodegenIsDeleted = false;
  untitled_DW.obj_n.isInitialized = 1;
  untitled_DW.obj_n.MW_DIGITALIO_HANDLE = MW_digitalIO_open(49, 1);
  untitled_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write2' */
  untitled_DW.obj_j.matlabCodegenIsDeleted = false;
  untitled_DW.obj_j.isInitialized = 1;
  untitled_DW.obj_j.MW_DIGITALIO_HANDLE = MW_digitalIO_open(97, 1);
  untitled_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Write3' */
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.isInitialized = 1;
  untitled_DW.obj.MW_DIGITALIO_HANDLE = MW_digitalIO_open(98, 1);
  untitled_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!untitled_DW.obj_i.matlabCodegenIsDeleted) {
    untitled_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_i.isInitialized == 1) &&
        untitled_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(untitled_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  if (!untitled_DW.obj_n.matlabCodegenIsDeleted) {
    untitled_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_n.isInitialized == 1) &&
        untitled_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(untitled_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  if (!untitled_DW.obj_j.matlabCodegenIsDeleted) {
    untitled_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_j.isInitialized == 1) &&
        untitled_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(untitled_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write2' */

  /* Terminate for MATLABSystem: '<Root>/Digital Write3' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj.isInitialized == 1) && untitled_DW.obj.isSetupComplete)
    {
      MW_digitalIO_close(untitled_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
