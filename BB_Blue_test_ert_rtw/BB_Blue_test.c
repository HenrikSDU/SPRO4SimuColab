/*
 * BB_Blue_test.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "BB_Blue_test".
 *
 * Model version              : 3.21
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Thu Mar 21 14:21:25 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BB_Blue_test.h"
#include "BB_Blue_test_types.h"
#include "BB_Blue_test_private.h"
#include "MW_I2C.h"
#include "rtwtypes.h"
#include <string.h>
#include "BB_Blue_test_dt.h"

/* Block signals (default storage) */
B_BB_Blue_test_T BB_Blue_test_B;

/* Continuous states */
X_BB_Blue_test_T BB_Blue_test_X;

/* Disabled State Vector */
XDis_BB_Blue_test_T BB_Blue_test_XDis;

/* Block states (default storage) */
DW_BB_Blue_test_T BB_Blue_test_DW;

/* Real-time model */
static RT_MODEL_BB_Blue_test_T BB_Blue_test_M_;
RT_MODEL_BB_Blue_test_T *const BB_Blue_test_M = &BB_Blue_test_M_;

/* Forward declaration for local functions */
static void BB_Blue_test_SystemCore_setup(beagleboneblue_bbblueMPU9250__T *obj);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  BB_Blue_test_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  BB_Blue_test_step();
  BB_Blue_test_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  BB_Blue_test_step();
  BB_Blue_test_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

static void BB_Blue_test_SystemCore_setup(beagleboneblue_bbblueMPU9250__T *obj)
{
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  obj->isInitialized = 1;
  MW_IMU_DMP_isAccel_Calibrated();
  MW_IMU_DMP_isGyro_Calibrated();
  MW_IMU_DMP_isMag_Calibrated();
  ModeType = MW_I2C_MASTER;
  i2cname = 2;
  obj->i2cObjmpu.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cObjmpu.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObjmpu.MW_I2C_HANDLE, obj->i2cObjmpu.BusSpeed);
  ModeType = MW_I2C_MASTER;
  i2cname = 2;
  obj->i2cObjak8963.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cObjak8963.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObjak8963.MW_I2C_HANDLE, obj->i2cObjak8963.BusSpeed);
  MW_Init_IMU_DMP(200);
  obj->TunablePropsChanged = false;
}

/* Model step function */
void BB_Blue_test_step(void)
{
  if (rtmIsMajorTimeStep(BB_Blue_test_M)) {
    /* set solver stop time */
    if (!(BB_Blue_test_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&BB_Blue_test_M->solverInfo,
                            ((BB_Blue_test_M->Timing.clockTickH0 + 1) *
        BB_Blue_test_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&BB_Blue_test_M->solverInfo,
                            ((BB_Blue_test_M->Timing.clockTick0 + 1) *
        BB_Blue_test_M->Timing.stepSize0 + BB_Blue_test_M->Timing.clockTickH0 *
        BB_Blue_test_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(BB_Blue_test_M)) {
    BB_Blue_test_M->Timing.t[0] = rtsiGetT(&BB_Blue_test_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(BB_Blue_test_M)) {
    /* MATLABSystem: '<Root>/MPU9250' */
    if (BB_Blue_test_DW.obj.SampleTime != BB_Blue_test_P.MPU9250_SampleTime) {
      BB_Blue_test_DW.obj.SampleTime = BB_Blue_test_P.MPU9250_SampleTime;
    }

    if (BB_Blue_test_DW.obj.TunablePropsChanged) {
      BB_Blue_test_DW.obj.TunablePropsChanged = false;
    }

    MW_Read_Accel(&BB_Blue_test_B.accel[0]);

    /* MATLABSystem: '<Root>/MPU9250' */
    BB_Blue_test_B.ang_vel[0] = 0.0;
    BB_Blue_test_B.ang_vel[1] = 0.0;
    BB_Blue_test_B.ang_vel[2] = 0.0;

    /* MATLABSystem: '<Root>/MPU9250' */
    MW_Read_Gyro(&BB_Blue_test_B.ang_vel[0]);

    /* MATLABSystem: '<Root>/MPU9250' */
    BB_Blue_test_B.attitude[0] = 0.0;
    BB_Blue_test_B.attitude[1] = 0.0;
    BB_Blue_test_B.attitude[2] = 0.0;

    /* MATLABSystem: '<Root>/MPU9250' */
    MW_Read_Euler(&BB_Blue_test_B.attitude[0]);
  }

  /* Integrator: '<Root>/Integrator' */
  BB_Blue_test_B.ang_pos[0] = BB_Blue_test_X.Integrator_CSTATE[0];
  BB_Blue_test_B.ang_pos[1] = BB_Blue_test_X.Integrator_CSTATE[1];
  BB_Blue_test_B.ang_pos[2] = BB_Blue_test_X.Integrator_CSTATE[2];
  if (rtmIsMajorTimeStep(BB_Blue_test_M)) {
  }

  if (rtmIsMajorTimeStep(BB_Blue_test_M)) {
    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, (real_T)BB_Blue_test_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(BB_Blue_test_M)) {/* Sample time: [0.001s, 0.0s] */
      rtExtModeUpload(1, (real_T)(((BB_Blue_test_M->Timing.clockTick1+
        BB_Blue_test_M->Timing.clockTickH1* 4294967296.0)) * 0.001));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(BB_Blue_test_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(BB_Blue_test_M)!=-1) &&
          !((rtmGetTFinal(BB_Blue_test_M)-(((BB_Blue_test_M->Timing.clockTick1+
               BB_Blue_test_M->Timing.clockTickH1* 4294967296.0)) * 0.001)) >
            (((BB_Blue_test_M->Timing.clockTick1+
               BB_Blue_test_M->Timing.clockTickH1* 4294967296.0)) * 0.001) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(BB_Blue_test_M, "Simulation finished");
      }

      if (rtmGetStopRequested(BB_Blue_test_M)) {
        rtmSetErrorStatus(BB_Blue_test_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&BB_Blue_test_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++BB_Blue_test_M->Timing.clockTick0)) {
      ++BB_Blue_test_M->Timing.clockTickH0;
    }

    BB_Blue_test_M->Timing.t[0] = rtsiGetSolverStopTime
      (&BB_Blue_test_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      BB_Blue_test_M->Timing.clockTick1++;
      if (!BB_Blue_test_M->Timing.clockTick1) {
        BB_Blue_test_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void BB_Blue_test_derivatives(void)
{
  XDot_BB_Blue_test_T *_rtXdot;
  _rtXdot = ((XDot_BB_Blue_test_T *) BB_Blue_test_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' incorporates:
   *  MATLABSystem: '<Root>/MPU9250'
   */
  _rtXdot->Integrator_CSTATE[0] = BB_Blue_test_B.ang_vel[0];
  _rtXdot->Integrator_CSTATE[1] = BB_Blue_test_B.ang_vel[1];
  _rtXdot->Integrator_CSTATE[2] = BB_Blue_test_B.ang_vel[2];
}

/* Model initialize function */
void BB_Blue_test_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)BB_Blue_test_M, 0,
                sizeof(RT_MODEL_BB_Blue_test_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&BB_Blue_test_M->solverInfo,
                          &BB_Blue_test_M->Timing.simTimeStep);
    rtsiSetTPtr(&BB_Blue_test_M->solverInfo, &rtmGetTPtr(BB_Blue_test_M));
    rtsiSetStepSizePtr(&BB_Blue_test_M->solverInfo,
                       &BB_Blue_test_M->Timing.stepSize0);
    rtsiSetdXPtr(&BB_Blue_test_M->solverInfo, &BB_Blue_test_M->derivs);
    rtsiSetContStatesPtr(&BB_Blue_test_M->solverInfo, (real_T **)
                         &BB_Blue_test_M->contStates);
    rtsiSetNumContStatesPtr(&BB_Blue_test_M->solverInfo,
      &BB_Blue_test_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&BB_Blue_test_M->solverInfo,
      &BB_Blue_test_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&BB_Blue_test_M->solverInfo,
      &BB_Blue_test_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&BB_Blue_test_M->solverInfo,
      &BB_Blue_test_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&BB_Blue_test_M->solverInfo, (boolean_T**)
      &BB_Blue_test_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&BB_Blue_test_M->solverInfo, (&rtmGetErrorStatus
      (BB_Blue_test_M)));
    rtsiSetRTModelPtr(&BB_Blue_test_M->solverInfo, BB_Blue_test_M);
  }

  rtsiSetSimTimeStep(&BB_Blue_test_M->solverInfo, MAJOR_TIME_STEP);
  BB_Blue_test_M->intgData.y = BB_Blue_test_M->odeY;
  BB_Blue_test_M->intgData.f[0] = BB_Blue_test_M->odeF[0];
  BB_Blue_test_M->intgData.f[1] = BB_Blue_test_M->odeF[1];
  BB_Blue_test_M->intgData.f[2] = BB_Blue_test_M->odeF[2];
  BB_Blue_test_M->contStates = ((X_BB_Blue_test_T *) &BB_Blue_test_X);
  BB_Blue_test_M->contStateDisabled = ((XDis_BB_Blue_test_T *)
    &BB_Blue_test_XDis);
  BB_Blue_test_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&BB_Blue_test_M->solverInfo, (void *)
                    &BB_Blue_test_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&BB_Blue_test_M->solverInfo, false);
  rtsiSetSolverName(&BB_Blue_test_M->solverInfo,"ode3");
  rtmSetTPtr(BB_Blue_test_M, &BB_Blue_test_M->Timing.tArray[0]);
  rtmSetTFinal(BB_Blue_test_M, -1);
  BB_Blue_test_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  BB_Blue_test_M->Sizes.checksums[0] = (2057434347U);
  BB_Blue_test_M->Sizes.checksums[1] = (2924661332U);
  BB_Blue_test_M->Sizes.checksums[2] = (3986818878U);
  BB_Blue_test_M->Sizes.checksums[3] = (848087145U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    BB_Blue_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(BB_Blue_test_M->extModeInfo,
      &BB_Blue_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(BB_Blue_test_M->extModeInfo,
                        BB_Blue_test_M->Sizes.checksums);
    rteiSetTPtr(BB_Blue_test_M->extModeInfo, rtmGetTPtr(BB_Blue_test_M));
  }

  /* block I/O */
  (void) memset(((void *) &BB_Blue_test_B), 0,
                sizeof(B_BB_Blue_test_T));

  /* states (continuous) */
  {
    (void) memset((void *)&BB_Blue_test_X, 0,
                  sizeof(X_BB_Blue_test_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&BB_Blue_test_XDis, 0,
                  sizeof(XDis_BB_Blue_test_T));
  }

  /* states (dwork) */
  (void) memset((void *)&BB_Blue_test_DW, 0,
                sizeof(DW_BB_Blue_test_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    BB_Blue_test_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/MPU9250' */
  BB_Blue_test_DW.obj.isInitialized = 0;
  BB_Blue_test_DW.obj.i2cObjmpu.DefaultMaximumBusSpeedInHz = 400000.0;
  BB_Blue_test_DW.obj.i2cObjmpu.isInitialized = 0;
  BB_Blue_test_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = false;
  BB_Blue_test_DW.obj.i2cObjak8963.DefaultMaximumBusSpeedInHz = 400000.0;
  BB_Blue_test_DW.obj.i2cObjak8963.isInitialized = 0;
  BB_Blue_test_DW.obj.i2cObjak8963.matlabCodegenIsDeleted = false;
  BB_Blue_test_DW.obj.matlabCodegenIsDeleted = false;
  BB_Blue_test_DW.objisempty = true;
  BB_Blue_test_DW.obj.SampleTime = BB_Blue_test_P.MPU9250_SampleTime;
  BB_Blue_test_SystemCore_setup(&BB_Blue_test_DW.obj);

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  BB_Blue_test_X.Integrator_CSTATE[0] = BB_Blue_test_P.Integrator_IC;
  BB_Blue_test_X.Integrator_CSTATE[1] = BB_Blue_test_P.Integrator_IC;
  BB_Blue_test_X.Integrator_CSTATE[2] = BB_Blue_test_P.Integrator_IC;
}

/* Model terminate function */
void BB_Blue_test_terminate(void)
{
  i_beagleboneblue_bbblueI2CMas_T *obj_0;
  j_beagleboneblue_bbblueI2CMas_T *obj;

  /* Terminate for MATLABSystem: '<Root>/MPU9250' */
  if (!BB_Blue_test_DW.obj.matlabCodegenIsDeleted) {
    BB_Blue_test_DW.obj.matlabCodegenIsDeleted = true;
  }

  obj = &BB_Blue_test_DW.obj.i2cObjak8963;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  obj_0 = &BB_Blue_test_DW.obj.i2cObjmpu;
  if (!obj_0->matlabCodegenIsDeleted) {
    obj_0->matlabCodegenIsDeleted = true;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/MPU9250' */
}
