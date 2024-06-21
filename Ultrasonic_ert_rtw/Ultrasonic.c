/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Ultrasonic.c
 *
 * Code generated for Simulink model 'Ultrasonic'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Jun 20 17:33:09 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Ultrasonic.h"
#include "rtwtypes.h"
#include "Ultrasonic_private.h"
#include "zero_crossing_types.h"
#include "Ultrasonic_dt.h"

/* Block signals (default storage) */
B_Ultrasonic_T Ultrasonic_B;

/* Block states (default storage) */
DW_Ultrasonic_T Ultrasonic_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Ultrasonic_T Ultrasonic_PrevZCX;

/* Real-time model */
static RT_MODEL_Ultrasonic_T Ultrasonic_M_;
RT_MODEL_Ultrasonic_T *const Ultrasonic_M = &Ultrasonic_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Ultrasonic_M->Timing.TaskCounters.TID[1])++;
  if ((Ultrasonic_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.01s, 0.0s] */
    Ultrasonic_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void Ultrasonic_step(void)
{
  boolean_T tmp;

  /* Reset subsysRan breadcrumbs */
  srClearBC(Ultrasonic_DW.SampleandHold_SubsysRanBC);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  Ultrasonic_B.PulseGenerator = (Ultrasonic_DW.clockTickCounter <
    Ultrasonic_P.PulseGenerator_Duty) && (Ultrasonic_DW.clockTickCounter >= 0) ?
    Ultrasonic_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  if (Ultrasonic_DW.clockTickCounter >= Ultrasonic_P.PulseGenerator_Period - 1.0)
  {
    Ultrasonic_DW.clockTickCounter = 0;
  } else {
    Ultrasonic_DW.clockTickCounter++;
  }

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(Ultrasonic_DW.obj_g.MW_DIGITALIO_HANDLE,
                     Ultrasonic_B.PulseGenerator != 0.0);

  /* MATLABSystem: '<Root>/Digital Read' */
  if (Ultrasonic_DW.obj.SampleTime != Ultrasonic_P.DigitalRead_SampleTime) {
    Ultrasonic_DW.obj.SampleTime = Ultrasonic_P.DigitalRead_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Read' */
  Ultrasonic_B.echo = MW_digitalIO_read(Ultrasonic_DW.obj.MW_DIGITALIO_HANDLE);

  /* Outputs for Triggered SubSystem: '<S1>/Sample and Hold' incorporates:
   *  TriggerPort: '<S3>/Trigger'
   */
  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  tmp = !Ultrasonic_B.echo;
  if (tmp && (Ultrasonic_PrevZCX.SampleandHold_Trig_ZCE != ZERO_ZCSIG)) {
    /* SignalConversion generated from: '<S3>/In' incorporates:
     *  Memory generated from: '<S1>/Sample and Hold'
     */
    Ultrasonic_B.In = Ultrasonic_DW.TmpLatchAtSampleandHoldInport1_;
    Ultrasonic_DW.SampleandHold_SubsysRanBC = 4;
  }

  Ultrasonic_PrevZCX.SampleandHold_Trig_ZCE = Ultrasonic_B.echo;

  /* End of Outputs for SubSystem: '<S1>/Sample and Hold' */
  if (Ultrasonic_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S4>/sum1' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     *  Gain: '<S4>/C'
     *  Gain: '<S4>/D'
     *  SignalConversion generated from: '<S3>/In'
     *  UnitDelay: '<S4>/Delay_x'
     */
    Ultrasonic_B.yk = (real_T)Ultrasonic_B.In * 0.0001 * Ultrasonic_P.D_Gain +
      Ultrasonic_P.C_Gain * Ultrasonic_DW.Delay_x_DSTATE;
  }

  if (Ultrasonic_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S4>/A*x(k) + B*u(k)' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     *  Gain: '<S4>/A'
     *  Gain: '<S4>/B'
     *  SignalConversion generated from: '<S3>/In'
     *  UnitDelay: '<S4>/Delay_x'
     */
    Ultrasonic_DW.Delay_x_DSTATE = (real_T)Ultrasonic_B.In * 0.0001 *
      Ultrasonic_P.B_Gain + Ultrasonic_P.A_Gain * Ultrasonic_DW.Delay_x_DSTATE;
  }

  /* DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  if (tmp && (Ultrasonic_DW.DiscreteTimeIntegrator_PrevRese == 1)) {
    Ultrasonic_DW.DiscreteTimeIntegrator_DSTATE =
      Ultrasonic_P.DiscreteTimeIntegrator_IC;
  }

  /* Update for Memory generated from: '<S1>/Sample and Hold' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Gain: '<S1>/Multiply'
   */
  Ultrasonic_DW.TmpLatchAtSampleandHoldInport1_ = (uint16_T)((uint32_T)
    Ultrasonic_P.Multiply_Gain * Ultrasonic_DW.DiscreteTimeIntegrator_DSTATE);

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  Ultrasonic_DW.DiscreteTimeIntegrator_DSTATE = (uint8_T)((uint32_T)
    Ultrasonic_DW.DiscreteTimeIntegrator_DSTATE + Ultrasonic_B.echo);
  Ultrasonic_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)Ultrasonic_B.echo;

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0001s, 0.0s] */
    rtExtModeUpload(0, (real_T)Ultrasonic_M->Timing.taskTime0);
  }

  if (Ultrasonic_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(1, (real_T)((Ultrasonic_M->Timing.clockTick1) * 0.01));
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0001s, 0.0s] */
    if ((rtmGetTFinal(Ultrasonic_M)!=-1) &&
        !((rtmGetTFinal(Ultrasonic_M)-Ultrasonic_M->Timing.taskTime0) >
          Ultrasonic_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Ultrasonic_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Ultrasonic_M)) {
      rtmSetErrorStatus(Ultrasonic_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Ultrasonic_M->Timing.taskTime0 =
    ((time_T)(++Ultrasonic_M->Timing.clockTick0)) *
    Ultrasonic_M->Timing.stepSize0;
  if (Ultrasonic_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Ultrasonic_M->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void Ultrasonic_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Ultrasonic_M, -1);
  Ultrasonic_M->Timing.stepSize0 = 0.0001;

  /* External mode info */
  Ultrasonic_M->Sizes.checksums[0] = (1123481065U);
  Ultrasonic_M->Sizes.checksums[1] = (2799127792U);
  Ultrasonic_M->Sizes.checksums[2] = (3716092593U);
  Ultrasonic_M->Sizes.checksums[3] = (2374761215U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    Ultrasonic_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&Ultrasonic_DW.SampleandHold_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Ultrasonic_M->extModeInfo,
      &Ultrasonic_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Ultrasonic_M->extModeInfo, Ultrasonic_M->Sizes.checksums);
    rteiSetTPtr(Ultrasonic_M->extModeInfo, rtmGetTPtr(Ultrasonic_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Ultrasonic_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 24;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* InitializeConditions for Memory generated from: '<S1>/Sample and Hold' */
  Ultrasonic_DW.TmpLatchAtSampleandHoldInport1_ =
    Ultrasonic_P.TmpLatchAtSampleandHoldInport1_;

  /* InitializeConditions for UnitDelay: '<S4>/Delay_x' */
  Ultrasonic_DW.Delay_x_DSTATE = Ultrasonic_P.Delay_x_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  Ultrasonic_DW.DiscreteTimeIntegrator_DSTATE =
    Ultrasonic_P.DiscreteTimeIntegrator_IC;
  Ultrasonic_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* SystemInitialize for Triggered SubSystem: '<S1>/Sample and Hold' */
  /* SystemInitialize for SignalConversion generated from: '<S3>/In' incorporates:
   *  Outport: '<S3>/ '
   */
  Ultrasonic_B.In = Ultrasonic_P._Y0;

  /* End of SystemInitialize for SubSystem: '<S1>/Sample and Hold' */

  /* Start for MATLABSystem: '<Root>/Digital Write' */
  Ultrasonic_DW.obj_g.matlabCodegenIsDeleted = false;
  Ultrasonic_DW.obj_g.isInitialized = 1;
  Ultrasonic_DW.obj_g.MW_DIGITALIO_HANDLE = MW_digitalIO_open(98, 1);
  Ultrasonic_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Read' */
  Ultrasonic_DW.obj.matlabCodegenIsDeleted = false;
  Ultrasonic_DW.obj.SampleTime = Ultrasonic_P.DigitalRead_SampleTime;
  Ultrasonic_DW.obj.isInitialized = 1;
  Ultrasonic_DW.obj.MW_DIGITALIO_HANDLE = MW_digitalIO_open(97, 0);
  Ultrasonic_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void Ultrasonic_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  if (!Ultrasonic_DW.obj_g.matlabCodegenIsDeleted) {
    Ultrasonic_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Ultrasonic_DW.obj_g.isInitialized == 1) &&
        Ultrasonic_DW.obj_g.isSetupComplete) {
      MW_digitalIO_close(Ultrasonic_DW.obj_g.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  if (!Ultrasonic_DW.obj.matlabCodegenIsDeleted) {
    Ultrasonic_DW.obj.matlabCodegenIsDeleted = true;
    if ((Ultrasonic_DW.obj.isInitialized == 1) &&
        Ultrasonic_DW.obj.isSetupComplete) {
      MW_digitalIO_close(Ultrasonic_DW.obj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Read' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
