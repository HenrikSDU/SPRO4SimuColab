/*
 * DroneModel.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DroneModel".
 *
 * Model version              : 1.17
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Thu Mar 21 13:26:39 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DroneModel_h_
#define RTW_HEADER_DroneModel_h_
#ifndef DroneModel_COMMON_INCLUDES_
#define DroneModel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_I2C.h"
#include "MW_bbblue_driver.h"
#include "MW_MPU9250.h"
#endif                                 /* DroneModel_COMMON_INCLUDES_ */

#include "DroneModel_types.h"
#include "multiword_types.h"
#include <math.h>
#include <float.h>
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T StateSpace[6];                /* '<S2>/State-Space' */
  real_T Multiply[4];                  /* '<S2>/Multiply' */
  real_T Subtract[4];                  /* '<S3>/Subtract' */
  uint8_T b_RegisterValue[24];
  real_T MPU9250_o1[3];                /* '<S2>/MPU9250' */
  real_T MPU9250_o2[3];                /* '<S2>/MPU9250' */
  real_T MPU9250_o3[3];                /* '<S2>/MPU9250' */
  int128m_T r;
  int128m_T r1;
  uint128m_T r2;
  uint128m_T r3;
  int96m_T r4;
  int96m_T r5;
  int96m_T r6;
  int96m_T r7;
  int96m_T r8;
  int96m_T r9;
  int96m_T r10;
  int96m_T r11;
  int32_T i_data[3];
  real_T Barometer;                    /* '<S2>/Barometer' */
  real_T d;
  real_T Step;                         /* '<S2>/Step' */
  real_T x_unsgn;
  real_T yd;
  uint32_T ux[2];
  int64m_T val3;
  int64m_T c;
  int64m_T val4;
  int64m_T r12;
  int64m_T r13;
  int64m_T r14;
  int64m_T r15;
  int64m_T r16;
  int64m_T r17;
  int64m_T r18;
  int64m_T r19;
  int64m_T r20;
  int64m_T r21;
  int64m_T r22;
  int64m_T r23;
  int64m_T r24;
  int64m_T r25;
  int64m_T r42;
  int64m_T r43;
  int64m_T r44;
  uint64m_T nk_unsgn;
  uint64m_T xint;
  uint64m_T res;
  uint64m_T nIsOdd;
  uint64m_T r26;
  uint64m_T r27;
  uint64m_T r28;
  uint64m_T r29;
  uint64m_T r30;
  uint64m_T r31;
  uint64m_T r32;
  uint64m_T r33;
  uint64m_T r34;
  uint64m_T r35;
  uint64m_T r36;
  uint64m_T r37;
  uint64m_T r38;
  uint64m_T r39;
  uint64m_T r40;
  uint64m_T r41;
  uint64m_T prod_unsgn;
  uint64m_T yint;
  uint64m_T b_y1;
  uint64m_T b_y0;
  uint64m_T n1;
  uint64m_T n0;
  uint64m_T temp;
  uint64m_T r45;
  uint64m_T r46;
  uint64m_T r47;
  uint64m_T r48;
  uint64m_T r49;
  uint64m_T r50;
} B_DroneModel_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  beagleboneblue_bbblueMPU9250__T obj; /* '<S2>/MPU9250' */
  beagleboneblue_bbblueBaromete_T obj_e;/* '<S2>/Barometer' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S2>/Scope' */

  struct {
    void *LoggedData[4];
  } Scope1_PWORK;                      /* '<S2>/Scope1' */

  boolean_T objisempty;                /* '<S2>/MPU9250' */
  boolean_T objisempty_o;              /* '<S2>/Barometer' */
} DW_DroneModel_T;

/* Continuous states (default storage) */
typedef struct {
  real_T StateSpace_CSTATE[12];        /* '<S2>/State-Space' */
} X_DroneModel_T;

/* State derivatives (default storage) */
typedef struct {
  real_T StateSpace_CSTATE[12];        /* '<S2>/State-Space' */
} XDot_DroneModel_T;

/* State disabled  */
typedef struct {
  boolean_T StateSpace_CSTATE[12];     /* '<S2>/State-Space' */
} XDis_DroneModel_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_DroneModel_T_ {
  real_T A[144];                       /* Variable: A
                                        * Referenced by: '<S2>/State-Space'
                                        */
  real_T B[48];                        /* Variable: B
                                        * Referenced by: '<S2>/State-Space'
                                        */
  real_T C[72];                        /* Variable: C
                                        * Referenced by: '<S2>/State-Space'
                                        */
  real_T g;                            /* Variable: g
                                        * Referenced by: '<S3>/Load per motor'
                                        */
  real_T m;                            /* Variable: m
                                        * Referenced by: '<S3>/Load per motor'
                                        */
  real_T x0[12];                       /* Variable: x0
                                        * Referenced by: '<S2>/State-Space'
                                        */
  real_T Barometer_SampleTime;         /* Expression: 0.1
                                        * Referenced by: '<S2>/Barometer'
                                        */
  real_T MPU9250_SampleTime;           /* Expression: 0.1
                                        * Referenced by: '<S2>/MPU9250'
                                        */
  real_T MotorThrusts_Value[4];        /* Expression: [1.5; 1.2; 1.5; 1.2;]
                                        * Referenced by: '<S2>/Motor Thrusts'
                                        */
  real_T Multiply_Gain;                /* Expression: 1
                                        * Referenced by: '<S2>/Multiply'
                                        */
  real_T Step_Time;                    /* Expression: 5
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 1
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0
                                        * Referenced by: '<S2>/Step'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_DroneModel_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_DroneModel_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_DroneModel_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[12];
  real_T odeF[3][12];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_DroneModel_T DroneModel_P;

/* Block signals (default storage) */
extern B_DroneModel_T DroneModel_B;

/* Continuous states (default storage) */
extern X_DroneModel_T DroneModel_X;

/* Block states (default storage) */
extern DW_DroneModel_T DroneModel_DW;

/* Model entry point functions */
extern void DroneModel_initialize(void);
extern void DroneModel_step(void);
extern void DroneModel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DroneModel_T *const DroneModel_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'DroneModel'
 * '<S1>'   : 'DroneModel/Controller'
 * '<S2>'   : 'DroneModel/Drone Model'
 * '<S3>'   : 'DroneModel/Drone Model/Gravity Model'
 * '<S4>'   : 'DroneModel/Drone Model/Motor Model'
 */
#endif                                 /* RTW_HEADER_DroneModel_h_ */
