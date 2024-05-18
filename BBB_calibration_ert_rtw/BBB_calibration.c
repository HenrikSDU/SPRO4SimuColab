/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BBB_calibration.c
 *
 * Code generated for Simulink model 'BBB_calibration'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat May 18 12:50:26 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BBB_calibration.h"
#include "BBB_calibration_types.h"
#include <math.h>
#include "rtwtypes.h"
#include "BBB_calibration_private.h"
#include "rt_nonfinite.h"
#include "BBB_calibration_dt.h"

/* Block signals (default storage) */
B_BBB_calibration_T BBB_calibration_B;

/* Block states (default storage) */
DW_BBB_calibration_T BBB_calibration_DW;

/* Real-time model */
static RT_MODEL_BBB_calibration_T BBB_calibration_M_;
RT_MODEL_BBB_calibration_T *const BBB_calibration_M = &BBB_calibration_M_;

/* Forward declaration for local functions */
static void BBB_calibratio_SystemCore_setup(beagleboneblue_bbblueMPU9250__T *obj);
static void BBB_calibratio_SystemCore_setup(beagleboneblue_bbblueMPU9250__T *obj)
{
  /* Start for MATLABSystem: '<Root>/MPU9250' */
  obj->isInitialized = 1;
  MW_IMU_DMP_isAccel_Calibrated();
  MW_IMU_DMP_isGyro_Calibrated();
  MW_IMU_DMP_isMag_Calibrated();

  /* Start for MATLABSystem: '<Root>/MPU9250' */
  obj->i2cObjmpu.MW_I2C_HANDLE = MW_I2C_Open(2, MW_I2C_MASTER);
  obj->i2cObjmpu.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObjmpu.MW_I2C_HANDLE, obj->i2cObjmpu.BusSpeed);
  obj->i2cObjak8963.MW_I2C_HANDLE = MW_I2C_Open(2, MW_I2C_MASTER);
  obj->i2cObjak8963.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObjak8963.MW_I2C_HANDLE, obj->i2cObjak8963.BusSpeed);
  MW_Init_IMU_DMP(200);
  obj->TunablePropsChanged = false;
}

/* Model step function */
void BBB_calibration_step(void)
{
  real_T mdata[3];
  real_T rtb_MPU9250_o1_0[3];

  /* MATLABSystem: '<Root>/MPU9250' */
  if (BBB_calibration_DW.obj.SampleTime != BBB_calibration_P.MPU9250_SampleTime)
  {
    BBB_calibration_DW.obj.SampleTime = BBB_calibration_P.MPU9250_SampleTime;
  }

  if (BBB_calibration_DW.obj.TunablePropsChanged) {
    BBB_calibration_DW.obj.TunablePropsChanged = false;
  }

  MW_Read_Accel(&rtb_MPU9250_o1_0[0]);
  mdata[0] = 0.0;
  mdata[1] = 0.0;
  mdata[2] = 0.0;
  MW_Read_Gyro(&mdata[0]);
  mdata[0] = 0.0;
  mdata[1] = 0.0;
  mdata[2] = 0.0;
  MW_Read_Mag(&mdata[0]);

  /* MATLABSystem: '<Root>/MPU9250' */
  BBB_calibration_B.MPU9250_o3[0] = mdata[0];
  BBB_calibration_B.MPU9250_o3[1] = mdata[1];
  BBB_calibration_B.MPU9250_o3[2] = mdata[2];

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  MATLABSystem: '<Root>/MPU9250'
   */
  BBB_calibration_B.roll = atan(rtb_MPU9250_o1_0[0] / rtb_MPU9250_o1_0[2]) *
    180.0 / 3.1415926535897931;

  /* Scope: '<Root>/Scope1' */
  {
    StructLogVar *svar = (StructLogVar *)
      BBB_calibration_DW.Scope1_PWORK.LoggedData[0];
    LogVar *var = svar->signals.values;

    /* time */
    {
      double locTime = BBB_calibration_M->Timing.taskTime0
        ;
      rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
    }

    /* signals */
    {
      real_T up0[1];
      up0[0] = BBB_calibration_B.roll;
      rt_UpdateLogVar((LogVar *)var, up0, 0);
      var = var->next;
    }

    {
      real_T up1[1];
      up1[0] = BBB_calibration_B.MPU9250_o3[0];
      rt_UpdateLogVar((LogVar *)var, up1, 0);
    }
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(BBB_calibration_M->rtwLogInfo,
                      (&BBB_calibration_M->Timing.taskTime0));

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, (real_T)BBB_calibration_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
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
  BBB_calibration_M->Timing.stepSize0 = 0.1;

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
  BBB_calibration_M->Sizes.checksums[0] = (3355735933U);
  BBB_calibration_M->Sizes.checksums[1] = (460389100U);
  BBB_calibration_M->Sizes.checksums[2] = (2162751714U);
  BBB_calibration_M->Sizes.checksums[3] = (568709380U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    BBB_calibration_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
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

  /* SetupRuntimeResources for Scope: '<Root>/Scope1' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 1, 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1, 2 };

    static int_T rt_ScopeSignalDimensions[] = { 1, 1, 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4, 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "roll",
      "" };

    static char_T rt_ScopeSignalTitles[] = "roll";
    static int_T rt_ScopeSignalTitleLengths[] = { 4, 0 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 1, 1 };

    BuiltInDTypeId dTypes[2] = { SS_DOUBLE, SS_DOUBLE };

    static char_T rt_ScopeBlockName[] = "BBB_calibration/Scope1";
    static int_T rt_ScopeFrameData[] = { 0, 0 };

    static RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs[] =
      {
      (NULL), (NULL), (NULL)
    };

    rt_ScopeSignalInfo.numSignals = 2;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = rt_ScopeFrameData;
    rt_ScopeSignalInfo.preprocessingPtrs =
      rt_ScopeSignalLoggingPreprocessingFcnPtrs;
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    BBB_calibration_DW.Scope1_PWORK.LoggedData[0] = rt_CreateStructLogVar(
      BBB_calibration_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(BBB_calibration_M),
      BBB_calibration_M->Timing.stepSize0,
      (&rtmGetErrorStatus(BBB_calibration_M)),
      "ScopeData1",
      1,
      5000,
      1,
      0.1,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (BBB_calibration_DW.Scope1_PWORK.LoggedData[0] == (NULL))
      return;
  }

  /* Start for MATLABSystem: '<Root>/MPU9250' */
  BBB_calibration_DW.obj.isInitialized = 0;
  BBB_calibration_DW.obj.i2cObjmpu.DefaultMaximumBusSpeedInHz = 400000.0;
  BBB_calibration_DW.obj.i2cObjmpu.isInitialized = 0;
  BBB_calibration_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = false;
  BBB_calibration_DW.obj.i2cObjak8963.DefaultMaximumBusSpeedInHz = 400000.0;
  BBB_calibration_DW.obj.i2cObjak8963.isInitialized = 0;
  BBB_calibration_DW.obj.i2cObjak8963.matlabCodegenIsDeleted = false;
  BBB_calibration_DW.obj.matlabCodegenIsDeleted = false;
  BBB_calibration_DW.obj.SampleTime = BBB_calibration_P.MPU9250_SampleTime;
  BBB_calibratio_SystemCore_setup(&BBB_calibration_DW.obj);
}

/* Model terminate function */
void BBB_calibration_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/MPU9250' */
  if (!BBB_calibration_DW.obj.matlabCodegenIsDeleted) {
    BBB_calibration_DW.obj.matlabCodegenIsDeleted = true;
  }

  if (!BBB_calibration_DW.obj.i2cObjak8963.matlabCodegenIsDeleted) {
    BBB_calibration_DW.obj.i2cObjak8963.matlabCodegenIsDeleted = true;
    if (BBB_calibration_DW.obj.i2cObjak8963.isInitialized == 1) {
      BBB_calibration_DW.obj.i2cObjak8963.isInitialized = 2;
    }
  }

  if (!BBB_calibration_DW.obj.i2cObjmpu.matlabCodegenIsDeleted) {
    BBB_calibration_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = true;
    if (BBB_calibration_DW.obj.i2cObjmpu.isInitialized == 1) {
      BBB_calibration_DW.obj.i2cObjmpu.isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/MPU9250' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
