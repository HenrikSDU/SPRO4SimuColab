/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.h
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon May 20 11:12:51 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef untitled_h_
#define untitled_h_
#ifndef untitled_COMMON_INCLUDES_
#define untitled_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_I2C.h"
#include "MW_bbblue_driver.h"
#endif                                 /* untitled_COMMON_INCLUDES_ */

#include "untitled_types.h"
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include <math.h>
#include <float.h>
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
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
  int128m_T r;
  int128m_T r1;
  int128m_T r2;
  uint128m_T r3;
  uint128m_T r4;
  int96m_T r5;
  int96m_T r6;
  int96m_T r7;
  int96m_T r8;
  int96m_T r9;
  int96m_T r10;
  int96m_T r11;
  int96m_T r12;
  real_T sensor;                       /* '<Root>/Add' */
  real_T height;                       /* '<Root>/height' */
  real_T In;                           /* '<S1>/In' */
  real_T d;
  real_T pwLocal;
  real_T pmLocal;
  real_T lambda;
  real_T x_unsgn;
  real_T yd;
  uint32_T ux[2];
  int64m_T val1;
  int64m_T val4;
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
  int64m_T r39;
  int64m_T r40;
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
  uint64m_T n_unsgn;
  uint64m_T yint;
  uint64m_T b_y1;
  uint64m_T b_y0;
  uint64m_T n1;
  uint64m_T ldword;
  uint64m_T temp0;
  uint64m_T r41;
  uint64m_T r42;
} B_untitled_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_un_T obj; /* '<Root>/Moving Average' */
  beagleboneblue_bbblueBaromete_T obj_n;/* '<Root>/Barometer' */
  struct {
    void *LoggedData[3];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  int8_T SampleandHold3_SubsysRanBC;   /* '<Root>/Sample and Hold3' */
} DW_untitled_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SampleandHold3_Trig_ZCE;  /* '<Root>/Sample and Hold3' */
} PrevZCX_untitled_T;

/* Parameters (default storage) */
struct P_untitled_T_ {
  real_T Barometer_SampleTime;         /* Expression: 0.1
                                        * Referenced by: '<Root>/Barometer'
                                        */
  real_T MovingAverage_ForgettingFactor;/* Expression: 1.0
                                         * Referenced by: '<Root>/Moving Average'
                                         */
  real_T _Y0;                          /* Expression: initCond
                                        * Referenced by: '<S1>/ '
                                        */
  real_T Step3_Time;                   /* Expression: 2
                                        * Referenced by: '<Root>/Step3'
                                        */
  real_T Step3_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step3'
                                        */
  real_T Step3_YFinal;                 /* Expression: 1
                                        * Referenced by: '<Root>/Step3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_untitled_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
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
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_untitled_T untitled_P;

/* Block signals (default storage) */
extern B_untitled_T untitled_B;

/* Block states (default storage) */
extern DW_untitled_T untitled_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_untitled_T untitled_PrevZCX;

/* Model entry point functions */
extern void untitled_initialize(void);
extern void untitled_step(void);
extern void untitled_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled_T *const untitled_M;
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
 * '<Root>' : 'untitled'
 * '<S1>'   : 'untitled/Sample and Hold3'
 * '<S2>'   : 'untitled/height'
 */
#endif                                 /* untitled_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
