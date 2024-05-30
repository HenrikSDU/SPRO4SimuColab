/*
 * DroneModel.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DroneModel".
 *
 * Model version              : 3.25
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Fri May 24 20:45:04 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DroneModel.h"
#include "DroneModel_private.h"
#include <string.h>
#include "DroneModel_dt.h"

/* Block states (default storage) */
DW_DroneModel_T DroneModel_DW;

/* Real-time model */
static RT_MODEL_DroneModel_T DroneModel_M_;
RT_MODEL_DroneModel_T *const DroneModel_M = &DroneModel_M_;

/* Model step function */
void DroneModel_step(void)
{
  /* MATLABSystem: '<Root>/Servo Motor' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rc_servo_send_pulse_normalized(1, (DroneModel_P.Constant_Value - 90.0) / 60.0);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(0, (real_T)DroneModel_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(DroneModel_M)!=-1) &&
        !((rtmGetTFinal(DroneModel_M)-DroneModel_M->Timing.taskTime0) >
          DroneModel_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(DroneModel_M, "Simulation finished");
    }

    if (rtmGetStopRequested(DroneModel_M)) {
      rtmSetErrorStatus(DroneModel_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++DroneModel_M->Timing.clockTick0)) {
    ++DroneModel_M->Timing.clockTickH0;
  }

  DroneModel_M->Timing.taskTime0 = DroneModel_M->Timing.clockTick0 *
    DroneModel_M->Timing.stepSize0 + DroneModel_M->Timing.clockTickH0 *
    DroneModel_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void DroneModel_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)DroneModel_M, 0,
                sizeof(RT_MODEL_DroneModel_T));
  rtmSetTFinal(DroneModel_M, -1);
  DroneModel_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  DroneModel_M->Sizes.checksums[0] = (3792263365U);
  DroneModel_M->Sizes.checksums[1] = (522558056U);
  DroneModel_M->Sizes.checksums[2] = (1174985144U);
  DroneModel_M->Sizes.checksums[3] = (633386027U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    DroneModel_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DroneModel_M->extModeInfo,
      &DroneModel_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DroneModel_M->extModeInfo, DroneModel_M->Sizes.checksums);
    rteiSetTPtr(DroneModel_M->extModeInfo, rtmGetTPtr(DroneModel_M));
  }

  /* states (dwork) */
  (void) memset((void *)&DroneModel_DW, 0,
                sizeof(DW_DroneModel_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    DroneModel_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/Servo Motor' */
  DroneModel_DW.obj.matlabCodegenIsDeleted = false;
  DroneModel_DW.objisempty = true;
  DroneModel_DW.obj.isInitialized = 1;
  DroneModel_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void DroneModel_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Servo Motor' */
  if (!DroneModel_DW.obj.matlabCodegenIsDeleted) {
    DroneModel_DW.obj.matlabCodegenIsDeleted = true;
    if ((DroneModel_DW.obj.isInitialized == 1) &&
        DroneModel_DW.obj.isSetupComplete) {
      rc_servo_send_pulse_normalized(1, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Servo Motor' */
}
