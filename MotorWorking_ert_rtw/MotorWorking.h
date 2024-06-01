/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MotorWorking.h
 *
 * Code generated for Simulink model 'MotorWorking'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon May 27 19:13:32 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef MotorWorking_h_
#define MotorWorking_h_
#ifndef MotorWorking_COMMON_INCLUDES_
#define MotorWorking_COMMON_INCLUDES_
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
#endif                                 /* MotorWorking_COMMON_INCLUDES_ */

#include "MotorWorking_types.h"
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rtGetNaN.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Gain1[3];                     /* '<S3>/Gain1' */
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
  real_T z;                            /* '<S2>/Constant' */
  real_T TmpRTBAtSwitch1Inport3;       /* '<Root>/Manual Switch' */
  real_T sensor;                       /* '<S4>/Add' */
  real_T yaw;                          /* '<S2>/yaw' */
  real_T roll;                         /* '<S2>/roll ' */
  real_T pitch;                        /* '<S2>/pitch' */
  real_T height;                       /* '<S4>/height' */
  real_T In;                           /* '<S8>/In' */
  real_T pmLocal;
  real_T lambda;
  real_T Switch1;                      /* '<Root>/Switch1' */
  real_T pitch_tmp;
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
  uint8_T TmpRTBAtSwitch1Inport1;      /* '<Root>/Initial1' */
} B_MotorWorking_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_Mo_T obj; /* '<S4>/Moving Average' */
  beagleboneblue_bbblueBaromete_T obj_d;/* '<S2>/Barometer' */
  beagleboneblue_bbblueMPU9250__T obj_j;/* '<S2>/MPU9250' */
  beagleboneblue_bbblueServo_Mo_T obj_jv;/* '<Root>/Servo Motor3' */
  beagleboneblue_bbblueServo_Mo_T obj_h;/* '<Root>/Servo Motor2' */
  beagleboneblue_bbblueServo_Mo_T obj_h5;/* '<Root>/Servo Motor1' */
  beagleboneblue_bbblueServo_Mo_T obj_g;/* '<Root>/Servo Motor' */
  real_T TmpRTBAtSwitch1Inport3_Buffer0;/* synthesized block */
  struct {
    void *LoggedData[7];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[3];
  } Scope1_PWORK_k;                    /* '<S4>/Scope1' */

  int8_T SampleandHold3_SubsysRanBC;   /* '<S4>/Sample and Hold3' */
  uint8_T TmpRTBAtSwitch1Inport1_Buffer0;/* synthesized block */
} DW_MotorWorking_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SampleandHold3_Trig_ZCE;  /* '<S4>/Sample and Hold3' */
} PrevZCX_MotorWorking_T;

/* Parameters (default storage) */
struct P_MotorWorking_T_ {
  real_T Ts;                           /* Variable: Ts
                                        * Referenced by:
                                        *   '<S2>/Barometer'
                                        *   '<S2>/MPU9250'
                                        */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S1>/Constant'
                                      */
  real_T MovingAverage_ForgettingFactor;/* Expression: 1.0
                                         * Referenced by: '<S4>/Moving Average'
                                         */
  real_T _Y0;                          /* Expression: initCond
                                        * Referenced by: '<S8>/ '
                                        */
  real_T Gain_Gain;                    /* Expression: 1.054388803297024
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T TmpRTBAtSwitch1Inport3_InitialC;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Step3_Time;                   /* Expression: 5
                                        * Referenced by: '<S4>/Step3'
                                        */
  real_T Step3_Y0;                     /* Expression: 0
                                        * Referenced by: '<S4>/Step3'
                                        */
  real_T Step3_YFinal;                 /* Expression: 1
                                        * Referenced by: '<S4>/Step3'
                                        */
  real_T Constant_Value_g;             /* Expression: 68
                                        * Referenced by: '<Root>/Constant'
                                        */
  uint8_T TmpRTBAtSwitch1Inport1_InitialC;
                          /* Computed Parameter: TmpRTBAtSwitch1Inport1_InitialC
                           * Referenced by:
                           */
  uint8_T Initial1_Value;              /* Computed Parameter: Initial1_Value
                                        * Referenced by: '<Root>/Initial1'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
};

/* Real-time Model Data Structure */
struct tag_RTM_MotorWorking_T {
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
    uint32_T clockTick2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_MotorWorking_T MotorWorking_P;

/* Block signals (default storage) */
extern B_MotorWorking_T MotorWorking_B;

/* Block states (default storage) */
extern DW_MotorWorking_T MotorWorking_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_MotorWorking_T MotorWorking_PrevZCX;

/* External function called from main */
extern void MotorWorking_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void MotorWorking_initialize(void);
extern void MotorWorking_step0(void);
extern void MotorWorking_step2(void);
extern void MotorWorking_step(int_T tid);
extern void MotorWorking_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MotorWorking_T *const MotorWorking_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Sine Wave' : Unused code path elimination
 */

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
 * '<Root>' : 'MotorWorking'
 * '<S1>'   : 'MotorWorking/Compare To Constant1'
 * '<S2>'   : 'MotorWorking/Sensor Readings'
 * '<S3>'   : 'MotorWorking/Sensor Readings/Degrees to Radians'
 * '<S4>'   : 'MotorWorking/Sensor Readings/Pressure to altitude'
 * '<S5>'   : 'MotorWorking/Sensor Readings/pitch'
 * '<S6>'   : 'MotorWorking/Sensor Readings/roll '
 * '<S7>'   : 'MotorWorking/Sensor Readings/yaw'
 * '<S8>'   : 'MotorWorking/Sensor Readings/Pressure to altitude/Sample and Hold3'
 * '<S9>'   : 'MotorWorking/Sensor Readings/Pressure to altitude/height'
 */
#endif                                 /* MotorWorking_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
