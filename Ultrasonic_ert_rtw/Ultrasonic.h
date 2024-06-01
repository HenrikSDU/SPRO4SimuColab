/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Ultrasonic.h
 *
 * Code generated for Simulink model 'Ultrasonic'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu May 30 19:52:24 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Ultrasonic_h_
#define Ultrasonic_h_
#ifndef Ultrasonic_COMMON_INCLUDES_
#define Ultrasonic_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_digitalIO.h"
#endif                                 /* Ultrasonic_COMMON_INCLUDES_ */

#include "Ultrasonic_types.h"
#include <float.h>
#include <string.h>
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
  real_T PulseGenerator;               /* '<Root>/Pulse Generator' */
  uint16_T In;                         /* '<S1>/In' */
  boolean_T echo;                      /* '<Root>/Digital Read' */
} B_Ultrasonic_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  beagleboneblue_bbblueDigitalR_T obj; /* '<Root>/Digital Read' */
  beagleboneblue_bbblueDigitalW_T obj_g;/* '<Root>/Digital Write' */
  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  uint16_T TmpLatchAtSampleandHoldInport1_;/* synthesized block */
  uint8_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<Root>/Discrete-Time Integrator' */
  int8_T SampleandHold_SubsysRanBC;    /* '<Root>/Sample and Hold' */
} DW_Ultrasonic_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SampleandHold_Trig_ZCE;   /* '<Root>/Sample and Hold' */
} PrevZCX_Ultrasonic_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T Out1;                       /* '<Root>/Out1' */
} ExtY_Ultrasonic_T;

/* Parameters (default storage) */
struct P_Ultrasonic_T_ {
  real_T DigitalRead_SampleTime;       /* Expression: 0.001
                                        * Referenced by: '<Root>/Digital Read'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<Root>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<Root>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  uint16_T _Y0;                        /* Computed Parameter: _Y0
                                        * Referenced by: '<S1>/ '
                                        */
  uint16_T TmpLatchAtSampleandHoldInport1_;
                          /* Computed Parameter: TmpLatchAtSampleandHoldInport1_
                           * Referenced by:
                           */
  uint8_T DiscreteTimeIntegrator_IC;
                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                 * Referenced by: '<Root>/Discrete-Time Integrator'
                                 */
  uint8_T Multiply_Gain;               /* Computed Parameter: Multiply_Gain
                                        * Referenced by: '<Root>/Multiply'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Ultrasonic_T {
  const char_T *errorStatus;
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
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Ultrasonic_T Ultrasonic_P;

/* Block signals (default storage) */
extern B_Ultrasonic_T Ultrasonic_B;

/* Block states (default storage) */
extern DW_Ultrasonic_T Ultrasonic_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Ultrasonic_T Ultrasonic_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Ultrasonic_T Ultrasonic_Y;

/* Model entry point functions */
extern void Ultrasonic_initialize(void);
extern void Ultrasonic_step(void);
extern void Ultrasonic_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Ultrasonic_T *const Ultrasonic_M;
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
 * '<Root>' : 'Ultrasonic'
 * '<S1>'   : 'Ultrasonic/Sample and Hold'
 */
#endif                                 /* Ultrasonic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
