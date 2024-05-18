/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BBB_calibration.h
 *
 * Code generated for Simulink model 'BBB_calibration'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat May 18 13:59:17 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef BBB_calibration_h_
#define BBB_calibration_h_
#ifndef BBB_calibration_COMMON_INCLUDES_
#define BBB_calibration_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_I2C.h"
#include "MW_bbblue_driver.h"
#include "MW_MPU9250.h"
#endif                                 /* BBB_calibration_COMMON_INCLUDES_ */

#include "BBB_calibration_types.h"
#include "multiword_types.h"
#include <math.h>
#include <float.h>
#include <stddef.h>
#include <string.h>
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T rtb_MPU9250_o1_m[3];
  real_T mdata[3];
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
  real_T Subtract;                     /* '<Root>/Subtract' */
  real_T pitch;                        /* '<Root>/MATLAB Function1' */
  real_T roll;                         /* '<Root>/MATLAB Function' */
  real_T rtb_Barometer1_c;
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
} B_BBB_calibration_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  beagleboneblue_bbblueBaromete_T obj; /* '<Root>/Barometer1' */
  beagleboneblue_bbblueMPU9250__T obj_h;/* '<Root>/MPU9250' */
  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope12_PWORK;                     /* '<Root>/Scope12' */

  struct {
    void *LoggedData;
  } Scope11_PWORK;                     /* '<Root>/Scope11' */
} DW_BBB_calibration_T;

/* Parameters (default storage) */
struct P_BBB_calibration_T_ {
  real_T Barometer1_SampleTime;        /* Expression: 0.1
                                        * Referenced by: '<Root>/Barometer1'
                                        */
  real_T MPU9250_SampleTime;           /* Expression: 0.1
                                        * Referenced by: '<Root>/MPU9250'
                                        */
  real_T Constant_Value;               /* Expression: 10^5
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_BBB_calibration_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;

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
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_BBB_calibration_T BBB_calibration_P;

/* Block signals (default storage) */
extern B_BBB_calibration_T BBB_calibration_B;

/* Block states (default storage) */
extern DW_BBB_calibration_T BBB_calibration_DW;

/* Model entry point functions */
extern void BBB_calibration_initialize(void);
extern void BBB_calibration_step(void);
extern void BBB_calibration_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BBB_calibration_T *const BBB_calibration_M;
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
 * '<Root>' : 'BBB_calibration'
 * '<S1>'   : 'BBB_calibration/MATLAB Function'
 * '<S2>'   : 'BBB_calibration/MATLAB Function1'
 */
#endif                                 /* BBB_calibration_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
