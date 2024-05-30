/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Ultrasonic.c
 *
 * Code generated for Simulink model 'Ultrasonic'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu May 23 18:11:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Ultrasonic.h"
#include "rtwtypes.h"
#include "Ultrasonic_private.h"
#include "Ultrasonic_dt.h"

/* Block signals (default storage) */
B_Ultrasonic_T Ultrasonic_B;

/* Block states (default storage) */
DW_Ultrasonic_T Ultrasonic_DW;

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
  if ((Ultrasonic_M->Timing.TaskCounters.TID[1]) > 14999) {/* Sample time: [1.5s, 0.0s] */
    Ultrasonic_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void Ultrasonic_step(void)
{
  if (Ultrasonic_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/Constant'
     *  UnitDelay: '<S1>/Unit Delay'
     */
    Ultrasonic_B.Sum = Ultrasonic_P.Constant_Value -
      Ultrasonic_DW.UnitDelay_DSTATE;

    /* MATLABSystem: '<Root>/Digital Write' */
    MW_digitalIO_write(Ultrasonic_DW.obj_g.MW_DIGITALIO_HANDLE, Ultrasonic_B.Sum
                       != 0.0);
  }

  /* MATLABSystem: '<Root>/Digital Read' */
  if (Ultrasonic_DW.obj.SampleTime != Ultrasonic_P.DigitalRead_SampleTime) {
    Ultrasonic_DW.obj.SampleTime = Ultrasonic_P.DigitalRead_SampleTime;
  }

  /* MATLABSystem: '<Root>/Digital Read' */
  Ultrasonic_B.echo = MW_digitalIO_read(Ultrasonic_DW.obj.MW_DIGITALIO_HANDLE);

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  if ((!Ultrasonic_B.echo) && (Ultrasonic_DW.DiscreteTimeIntegrator_PrevRese ==
       1)) {
    Ultrasonic_DW.DiscreteTimeIntegrator_DSTATE =
      Ultrasonic_P.DiscreteTimeIntegrator_IC;
  }

  /* Gain: '<S2>/Multiply' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   */
  Ultrasonic_B.Multiply = (uint16_T)((uint32_T)Ultrasonic_P.Multiply_Gain *
    Ultrasonic_DW.DiscreteTimeIntegrator_DSTATE);
  if (Ultrasonic_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S1>/Unit Delay' */
    Ultrasonic_DW.UnitDelay_DSTATE = Ultrasonic_B.Sum;
  }

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  Ultrasonic_DW.DiscreteTimeIntegrator_DSTATE = (uint8_T)((uint32_T)
    Ultrasonic_DW.DiscreteTimeIntegrator_DSTATE + Ultrasonic_B.echo);
  Ultrasonic_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)Ultrasonic_B.echo;

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0001s, 0.0s] */
    rtExtModeUpload(0, (real_T)Ultrasonic_M->Timing.taskTime0);
  }

  if (Ultrasonic_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [1.5s, 0.0s] */
    rtExtModeUpload(1, (real_T)((Ultrasonic_M->Timing.clockTick1) * 1.5));
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
    /* Update absolute timer for sample time: [1.5s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.5, which is the step size
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
  Ultrasonic_M->Sizes.checksums[0] = (3694572734U);
  Ultrasonic_M->Sizes.checksums[1] = (2127255463U);
  Ultrasonic_M->Sizes.checksums[2] = (4189412061U);
  Ultrasonic_M->Sizes.checksums[3] = (1528743913U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Ultrasonic_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
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

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  Ultrasonic_DW.UnitDelay_DSTATE = Ultrasonic_P.UnitDelay_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  Ultrasonic_DW.DiscreteTimeIntegrator_DSTATE =
    Ultrasonic_P.DiscreteTimeIntegrator_IC;
  Ultrasonic_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* Start for MATLABSystem: '<Root>/Digital Write' */
  Ultrasonic_DW.obj_g.matlabCodegenIsDeleted = false;
  Ultrasonic_DW.obj_g.isInitialized = 1;
  Ultrasonic_DW.obj_g.MW_DIGITALIO_HANDLE = MW_digitalIO_open(49, 1);
  Ultrasonic_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Digital Read' */
  Ultrasonic_DW.obj.matlabCodegenIsDeleted = false;
  Ultrasonic_DW.obj.SampleTime = Ultrasonic_P.DigitalRead_SampleTime;
  Ultrasonic_DW.obj.isInitialized = 1;
  Ultrasonic_DW.obj.MW_DIGITALIO_HANDLE = MW_digitalIO_open(57, 0);
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
