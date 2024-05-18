/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BBB_calibration.h
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
#include "MW_MPU9250.h"
#endif                                 /* BBB_calibration_COMMON_INCLUDES_ */

#include "BBB_calibration_types.h"
#include <stddef.h>
#include <float.h>
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
  real_T MPU9250_o3[3];                /* '<Root>/MPU9250' */
  real_T roll;                         /* '<Root>/MATLAB Function1' */
} B_BBB_calibration_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  beagleboneblue_bbblueMPU9250__T obj; /* '<Root>/MPU9250' */
  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */
} DW_BBB_calibration_T;

/* Parameters (default storage) */
struct P_BBB_calibration_T_ {
  real_T MPU9250_SampleTime;           /* Expression: 0.1
                                        * Referenced by: '<Root>/MPU9250'
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
 * '<S3>'   : 'BBB_calibration/MATLAB Function2'
 */
#endif                                 /* BBB_calibration_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
