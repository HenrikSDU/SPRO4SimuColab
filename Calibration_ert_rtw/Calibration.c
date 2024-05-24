/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Calibration.c
 *
 * Code generated for Simulink model 'Calibration'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri May 24 17:31:49 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Calibration.h"
#include "Calibration_private.h"
#include "Calibration_dt.h"

/* Block states (default storage) */
DW_Calibration_T Calibration_DW;

/* Real-time model */
static RT_MODEL_Calibration_T Calibration_M_;
RT_MODEL_Calibration_T *const Calibration_M = &Calibration_M_;

/* Model step function */
void Calibration_step(void)
{
  /* MATLABSystem: '<Root>/Servo Motor' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rc_servo_send_pulse_normalized(1, (Calibration_P.Constant_Value - 90.0) / 60.0);

  /* MATLABSystem: '<Root>/Servo Motor1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rc_servo_send_pulse_normalized(2, (Calibration_P.Constant_Value - 90.0) / 60.0);

  /* MATLABSystem: '<Root>/Servo Motor2' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rc_servo_send_pulse_normalized(3, (Calibration_P.Constant_Value - 90.0) / 60.0);

  /* MATLABSystem: '<Root>/Servo Motor3' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rc_servo_send_pulse_normalized(4, (Calibration_P.Constant_Value - 90.0) / 60.0);

  /* MATLABSystem: '<Root>/Servo Motor4' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rc_servo_send_pulse_normalized(8, (Calibration_P.Constant_Value - 90.0) / 60.0);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.005s, 0.0s] */
    rtExtModeUpload(0, (real_T)Calibration_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(Calibration_M)!=-1) &&
        !((rtmGetTFinal(Calibration_M)-Calibration_M->Timing.taskTime0) >
          Calibration_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Calibration_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Calibration_M)) {
      rtmSetErrorStatus(Calibration_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Calibration_M->Timing.taskTime0 =
    ((time_T)(++Calibration_M->Timing.clockTick0)) *
    Calibration_M->Timing.stepSize0;
}

/* Model initialize function */
void Calibration_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Calibration_M, -1);
  Calibration_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  Calibration_M->Sizes.checksums[0] = (3383956808U);
  Calibration_M->Sizes.checksums[1] = (38308619U);
  Calibration_M->Sizes.checksums[2] = (1465088259U);
  Calibration_M->Sizes.checksums[3] = (3964384046U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    Calibration_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Calibration_M->extModeInfo,
      &Calibration_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Calibration_M->extModeInfo,
                        Calibration_M->Sizes.checksums);
    rteiSetTPtr(Calibration_M->extModeInfo, rtmGetTPtr(Calibration_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Calibration_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/Servo Motor' */
  Calibration_DW.obj_p.matlabCodegenIsDeleted = false;
  Calibration_DW.obj_p.isInitialized = 1;
  Calibration_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Servo Motor1' */
  Calibration_DW.obj_k.matlabCodegenIsDeleted = false;
  Calibration_DW.obj_k.isInitialized = 1;
  Calibration_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Servo Motor2' */
  Calibration_DW.obj_l.matlabCodegenIsDeleted = false;
  Calibration_DW.obj_l.isInitialized = 1;
  Calibration_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Servo Motor3' */
  Calibration_DW.obj_e.matlabCodegenIsDeleted = false;
  Calibration_DW.obj_e.isInitialized = 1;
  Calibration_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Servo Motor4' */
  Calibration_DW.obj.matlabCodegenIsDeleted = false;
  Calibration_DW.obj.isInitialized = 1;
  Calibration_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void Calibration_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Servo Motor' */
  if (!Calibration_DW.obj_p.matlabCodegenIsDeleted) {
    Calibration_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Calibration_DW.obj_p.isInitialized == 1) &&
        Calibration_DW.obj_p.isSetupComplete) {
      rc_servo_send_pulse_normalized(1, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Servo Motor' */

  /* Terminate for MATLABSystem: '<Root>/Servo Motor1' */
  if (!Calibration_DW.obj_k.matlabCodegenIsDeleted) {
    Calibration_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((Calibration_DW.obj_k.isInitialized == 1) &&
        Calibration_DW.obj_k.isSetupComplete) {
      rc_servo_send_pulse_normalized(2, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Servo Motor1' */

  /* Terminate for MATLABSystem: '<Root>/Servo Motor2' */
  if (!Calibration_DW.obj_l.matlabCodegenIsDeleted) {
    Calibration_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Calibration_DW.obj_l.isInitialized == 1) &&
        Calibration_DW.obj_l.isSetupComplete) {
      rc_servo_send_pulse_normalized(3, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Servo Motor2' */

  /* Terminate for MATLABSystem: '<Root>/Servo Motor3' */
  if (!Calibration_DW.obj_e.matlabCodegenIsDeleted) {
    Calibration_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Calibration_DW.obj_e.isInitialized == 1) &&
        Calibration_DW.obj_e.isSetupComplete) {
      rc_servo_send_pulse_normalized(4, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Servo Motor3' */

  /* Terminate for MATLABSystem: '<Root>/Servo Motor4' */
  if (!Calibration_DW.obj.matlabCodegenIsDeleted) {
    Calibration_DW.obj.matlabCodegenIsDeleted = true;
    if ((Calibration_DW.obj.isInitialized == 1) &&
        Calibration_DW.obj.isSetupComplete) {
      rc_servo_send_pulse_normalized(8, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Servo Motor4' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
