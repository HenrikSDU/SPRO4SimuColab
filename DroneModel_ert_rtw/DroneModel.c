/*
 * DroneModel.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DroneModel".
 *
 * Model version              : 3.13
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Mon May 13 16:34:50 2024
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

/* Block signals (default storage) */
B_DroneModel_T DroneModel_B;

/* Block states (default storage) */
DW_DroneModel_T DroneModel_DW;

/* Real-time model */
static RT_MODEL_DroneModel_T DroneModel_M_;
RT_MODEL_DroneModel_T *const DroneModel_M = &DroneModel_M_;

/* Model step function */
void DroneModel_step(void)
{
  /* Constant: '<Root>/Constant' */
  DroneModel_B.Constant = DroneModel_P.Constant_Value;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)DroneModel_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
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
  DroneModel_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  DroneModel_M->Sizes.checksums[0] = (3442563702U);
  DroneModel_M->Sizes.checksums[1] = (1988521037U);
  DroneModel_M->Sizes.checksums[2] = (2605647860U);
  DroneModel_M->Sizes.checksums[3] = (1476487357U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    DroneModel_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DroneModel_M->extModeInfo,
      &DroneModel_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DroneModel_M->extModeInfo, DroneModel_M->Sizes.checksums);
    rteiSetTPtr(DroneModel_M->extModeInfo, rtmGetTPtr(DroneModel_M));
  }

  /* block I/O */
  (void) memset(((void *) &DroneModel_B), 0,
                sizeof(B_DroneModel_T));

  /* states (dwork) */
  (void) memset((void *)&DroneModel_DW, 0,
                sizeof(DW_DroneModel_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    DroneModel_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }
}

/* Model terminate function */
void DroneModel_terminate(void)
{
  /* (no terminate code required) */
}
