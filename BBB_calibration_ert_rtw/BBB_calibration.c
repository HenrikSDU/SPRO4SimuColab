/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BBB_calibration.c
 *
 * Code generated for Simulink model 'BBB_calibration'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun May 19 15:46:22 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BBB_calibration.h"
#include "BBB_calibration_private.h"
#include "rt_nonfinite.h"
#include "BBB_calibration_dt.h"

/* Block states (default storage) */
DW_BBB_calibration_T BBB_calibration_DW;

/* Real-time model */
static RT_MODEL_BBB_calibration_T BBB_calibration_M_;
RT_MODEL_BBB_calibration_T *const BBB_calibration_M = &BBB_calibration_M_;

/* Model step function */
void BBB_calibration_step(void)
{
  /* MATLABSystem: '<Root>/Servo Motor' incorporates:
   *  Constant: '<Root>/motor in'
   *  Gain: '<Root>/Gain'
   */
  rc_servo_send_pulse_normalized(1, (BBB_calibration_P.Gain_Gain *
    BBB_calibration_P.motorin_Value - 90.0) / 60.0);

  /* Matfile logging */
  rt_UpdateTXYLogVars(BBB_calibration_M->rtwLogInfo,
                      (&BBB_calibration_M->Timing.taskTime0));

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.0025s, 0.0s] */
    rtExtModeUpload(0, (real_T)BBB_calibration_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0025s, 0.0s] */
    if ((rtmGetTFinal(BBB_calibration_M)!=-1) &&
        !((rtmGetTFinal(BBB_calibration_M)-BBB_calibration_M->Timing.taskTime0) >
          BBB_calibration_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(BBB_calibration_M, "Simulation finished");
    }

    if (rtmGetStopRequested(BBB_calibration_M)) {
      rtmSetErrorStatus(BBB_calibration_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  BBB_calibration_M->Timing.taskTime0 =
    ((time_T)(++BBB_calibration_M->Timing.clockTick0)) *
    BBB_calibration_M->Timing.stepSize0;
}

/* Model initialize function */
void BBB_calibration_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(BBB_calibration_M, -1);
  BBB_calibration_M->Timing.stepSize0 = 0.0025;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    BBB_calibration_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(BBB_calibration_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(BBB_calibration_M->rtwLogInfo, (NULL));
    rtliSetLogT(BBB_calibration_M->rtwLogInfo, "tout");
    rtliSetLogX(BBB_calibration_M->rtwLogInfo, "");
    rtliSetLogXFinal(BBB_calibration_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(BBB_calibration_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(BBB_calibration_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(BBB_calibration_M->rtwLogInfo, 0);
    rtliSetLogDecimation(BBB_calibration_M->rtwLogInfo, 1);
    rtliSetLogY(BBB_calibration_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(BBB_calibration_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(BBB_calibration_M->rtwLogInfo, (NULL));
  }

  /* External mode info */
  BBB_calibration_M->Sizes.checksums[0] = (2878624834U);
  BBB_calibration_M->Sizes.checksums[1] = (948786945U);
  BBB_calibration_M->Sizes.checksums[2] = (2502373552U);
  BBB_calibration_M->Sizes.checksums[3] = (605058127U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    BBB_calibration_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(BBB_calibration_M->extModeInfo,
      &BBB_calibration_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(BBB_calibration_M->extModeInfo,
                        BBB_calibration_M->Sizes.checksums);
    rteiSetTPtr(BBB_calibration_M->extModeInfo, rtmGetTPtr(BBB_calibration_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    BBB_calibration_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(BBB_calibration_M->rtwLogInfo, 0.0,
    rtmGetTFinal(BBB_calibration_M), BBB_calibration_M->Timing.stepSize0,
    (&rtmGetErrorStatus(BBB_calibration_M)));

  /* Start for MATLABSystem: '<Root>/Servo Motor' */
  BBB_calibration_DW.obj.matlabCodegenIsDeleted = false;
  BBB_calibration_DW.obj.isInitialized = 1;
  BBB_calibration_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void BBB_calibration_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Servo Motor' */
  if (!BBB_calibration_DW.obj.matlabCodegenIsDeleted) {
    BBB_calibration_DW.obj.matlabCodegenIsDeleted = true;
    if ((BBB_calibration_DW.obj.isInitialized == 1) &&
        BBB_calibration_DW.obj.isSetupComplete) {
      rc_servo_send_pulse_normalized(1, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Servo Motor' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
