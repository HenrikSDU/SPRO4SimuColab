/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Controller_implementation.h
 *
 * Code generated for Simulink model 'Controller_implementation'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon May 27 17:16:40 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Controller_implementation_h_
#define Controller_implementation_h_
#ifndef Controller_implementation_COMMON_INCLUDES_
#define Controller_implementation_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_bbblue_driver.h"
#include "MW_I2C.h"
#include "MW_MPU9250.h"
#endif                          /* Controller_implementation_COMMON_INCLUDES_ */

#include "Controller_implementation_types.h"
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
  real_T Add[8];                       /* '<S30>/Add' */
  real_T Reshapey[7];                  /* '<S9>/Reshapey' */
  real_T rtb_Reshapey_m[7];
  real_T req_rotorspeed[4];
  real_T DersiredMotorThrusts[4];      /* '<S66>/Gain' */
  real_T Subtract[4];                  /* '<S2>/Subtract' */
  uint8_T b_output[24];
  real_T rtb_MPU9250_o1_c[3];
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
  real_T z;                            /* '<S7>/Constant' */
  real_T Gain1[3];                     /* '<S68>/Gain1' */
  real_T Reshapexhat[8];               /* '<S9>/Reshapexhat' */
  real_T Sum[4];                       /* '<S2>/Sum' */
  real_T PWMlimit[4];                  /* '<S3>/PWM limit' */
  real_T Sum_o[4];                     /* '<S8>/Sum' */
  real_T Gain;                         /* '<S4>/Gain' */
  real_T Gain_n;                       /* '<S5>/Gain' */
  real_T sensor;                       /* '<S69>/Add' */
  real_T U[4];                         /* '<S8>/MATLAB Function' */
  real_T roll;                         /* '<S7>/roll ' */
  real_T pitch;                        /* '<S7>/pitch' */
  real_T height;                       /* '<S69>/height' */
  real_T In;                           /* '<S73>/In' */
  real_T Product2[8];                  /* '<S63>/Product2' */
  real_T Product3[8];                  /* '<S61>/Product3' */
  int32_T angle[4];                    /* '<S3>/MATLAB Function' */
  real_T max_possible_rot_speed;
  real_T Gain1_k;
  real_T unnamed_idx_1;
  real_T unnamed_idx_2;
  real_T unnamed_idx_3;
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
  int64m_T r40;
  int64m_T r41;
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
  uint64m_T n_unsgn;
  uint64m_T yint;
  uint64m_T b_y1;
  uint64m_T b_y0;
  uint64m_T n1;
  uint64m_T ldword;
  uint64m_T temp0;
  uint64m_T r42;
  uint64m_T r43;
  uint64m_T r44;
} B_Controller_implementation_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_Co_T obj; /* '<S69>/Moving Average' */
  beagleboneblue_bbblueBaromete_T obj_j;/* '<S7>/Barometer' */
  beagleboneblue_bbblueMPU9250__T obj_n;/* '<S7>/MPU9250' */
  beagleboneblue_bbblueServo_Co_T obj_b;/* '<S3>/Motor 4' */
  beagleboneblue_bbblueServo_Co_T obj_h;/* '<S3>/Motor 3' */
  beagleboneblue_bbblueServo_Co_T obj_p;/* '<S3>/Motor 2' */
  beagleboneblue_bbblueServo_Co_T obj_k;/* '<S3>/Motor 1' */
  real_T MemoryX_DSTATE[8];            /* '<S9>/MemoryX' */
  real_T DiscreteTimeIntegrator_DSTATE[4];/* '<S2>/Discrete-Time Integrator' */
  struct {
    void *LoggedData[8];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } SystemUMonitor_PWORK;              /* '<Root>/System U Monitor' */

  struct {
    void *LoggedData;
  } Scope_PWORK_p;                     /* '<S3>/Scope' */

  struct {
    void *LoggedData;
  } TrackPWM_PWORK;                    /* '<S3>/Track PWM' */

  struct {
    void *LoggedData;
  } DesiredU_PWORK;                    /* '<Root>/Desired U' */

  struct {
    void *LoggedData[7];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Pitch_PWORK;                       /* '<Root>/Pitch' */

  struct {
    void *LoggedData;
  } Roll_PWORK;                        /* '<Root>/Roll' */

  struct {
    void *LoggedData[3];
  } Scope1_PWORK_m;                    /* '<S69>/Scope1' */

  struct {
    void *LoggedData;
  } yaw_PWORK;                         /* '<Root>/yaw' */

  int32_T RateTransition_Buffer[4];    /* '<S3>/Rate Transition' */
  int8_T SampleandHold3_SubsysRanBC;   /* '<S69>/Sample and Hold3' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S37>/Enabled Subsystem' */
  int8_T MeasurementUpdate_SubsysRanBC;/* '<S30>/MeasurementUpdate' */
  boolean_T icLoad;                    /* '<S9>/MemoryX' */
  boolean_T EnabledSubsystem_MODE;     /* '<S37>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S30>/MeasurementUpdate' */
} DW_Controller_implementation_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SampleandHold3_Trig_ZCE;  /* '<S69>/Sample and Hold3' */
} PrevZCX_Controller_implementa_T;

/* Parameters (default storage) */
struct P_Controller_implementation_T_ {
  real_T F[32];                        /* Variable: F
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T KV_rating;                    /* Variable: KV_rating
                                        * Referenced by:
                                        *   '<S66>/Constant1'
                                        *   '<S75>/Constant'
                                        */
  real_T K_mm[16];                     /* Variable: K_mm
                                        * Referenced by: '<S66>/Gain'
                                        */
  real_T Ki_D_lqi_reduced_a[16];       /* Variable: Ki_D_lqi_reduced_a
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T Kx_D_lqi_reduced_a[32];       /* Variable: Kx_D_lqi_reduced_a
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Ts;                           /* Variable: Ts
                                        * Referenced by:
                                        *   '<S7>/Barometer'
                                        *   '<S7>/MPU9250'
                                        */
  real_T battery_voltage;              /* Variable: battery_voltage
                                        * Referenced by:
                                        *   '<S66>/Constant'
                                        *   '<S75>/Battery Voltage'
                                        */
  real_T dis;                          /* Variable: dis
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T drag_co;                      /* Variable: drag_co
                                        * Referenced by: '<S75>/Gain1'
                                        */
  real_T lift_co;                      /* Variable: lift_co
                                        * Referenced by:
                                        *   '<S66>/Constant2'
                                        *   '<S75>/Gain'
                                        */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S64>/Constant'
                                      */
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S61>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S63>/deltax'
                                        */
  real_T MovingAverage_ForgettingFactor;/* Expression: 1.0
                                         * Referenced by: '<S69>/Moving Average'
                                         */
  real_T _Y0;                          /* Expression: initCond
                                        * Referenced by: '<S73>/ '
                                        */
  real_T A_Value[64];                  /* Expression: pInitialization.A
                                        * Referenced by: '<S9>/A'
                                        */
  real_T KalmanGainM_Value[56];        /* Expression: pInitialization.M
                                        * Referenced by: '<S10>/KalmanGainM'
                                        */
  real_T C_Value[56];                  /* Expression: pInitialization.C
                                        * Referenced by: '<S9>/C'
                                        */
  real_T KalmanGainL_Value[56];        /* Expression: pInitialization.L
                                        * Referenced by: '<S10>/KalmanGainL'
                                        */
  real_T B_Value[32];                  /* Expression: pInitialization.B
                                        * Referenced by: '<S9>/B'
                                        */
  real_T D_Value[28];                  /* Expression: pInitialization.D
                                        * Referenced by: '<S9>/D'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S68>/Gain1'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T X0_Value[8];                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S9>/X0'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S2>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  real_T PWMlimit_UpperSat;            /* Expression: 255
                                        * Referenced by: '<S3>/PWM limit'
                                        */
  real_T PWMlimit_LowerSat;            /* Expression: 0
                                        * Referenced by: '<S3>/PWM limit'
                                        */
  real_T SignConvention_Gain[4];       /* Expression: [1;-1;1;-1]
                                        * Referenced by: '<S75>/Sign Convention'
                                        */
  real_T Constant1_Value[4];           /* Expression: [0;0;0;0]
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Constant_Value_a[4];          /* Expression: [0;0;0;0;]
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 180/pi
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T CovarianceZ_Value[64];        /* Expression: pInitialization.Z
                                        * Referenced by: '<S10>/CovarianceZ'
                                        */
  real_T Step3_Time;                   /* Expression: 5
                                        * Referenced by: '<S69>/Step3'
                                        */
  real_T Step3_Y0;                     /* Expression: 0
                                        * Referenced by: '<S69>/Step3'
                                        */
  real_T Step3_YFinal;                 /* Expression: 1
                                        * Referenced by: '<S69>/Step3'
                                        */
  int32_T Servolimit_UpperSat;        /* Computed Parameter: Servolimit_UpperSat
                                       * Referenced by: '<S3>/Servo limit'
                                       */
  int32_T Servolimit_LowerSat;        /* Computed Parameter: Servolimit_LowerSat
                                       * Referenced by: '<S3>/Servo limit'
                                       */
  boolean_T Enable_Value;              /* Expression: true()
                                        * Referenced by: '<S9>/Enable'
                                        */
  boolean_T isSqrtUsed_Value;          /* Expression: pInitialization.isSqrtUsed
                                        * Referenced by: '<S59>/isSqrtUsed'
                                        */
  uint8_T Initial1_Value[4];           /* Computed Parameter: Initial1_Value
                                        * Referenced by: '<S3>/Initial1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Controller_implementa_T {
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
extern P_Controller_implementation_T Controller_implementation_P;

/* Block signals (default storage) */
extern B_Controller_implementation_T Controller_implementation_B;

/* Block states (default storage) */
extern DW_Controller_implementation_T Controller_implementation_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_Controller_implementa_T Controller_implementati_PrevZCX;

/* External function called from main */
extern void Controller_implementation_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void Controller_implementation_initialize(void);
extern void Controller_implementation_step0(void);
extern void Controller_implementation_step2(void);
extern void Controller_implementation_step(int_T tid);
extern void Controller_implementation_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Controller_implement_T *const Controller_implementation_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Conversion' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Conversion' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/G' : Unused code path elimination
 * Block '<S9>/H' : Unused code path elimination
 * Block '<S9>/N' : Unused code path elimination
 * Block '<S9>/P0' : Unused code path elimination
 * Block '<S9>/Q' : Unused code path elimination
 * Block '<S9>/R' : Unused code path elimination
 * Block '<S51>/CheckSignalProperties' : Unused code path elimination
 * Block '<S52>/CheckSignalProperties' : Unused code path elimination
 * Block '<Root>/Product' : Unused code path elimination
 * Block '<S53>/Conversion' : Eliminate redundant data type conversion
 * Block '<S54>/Conversion' : Eliminate redundant data type conversion
 * Block '<S56>/Conversion' : Eliminate redundant data type conversion
 * Block '<S26>/Conversion' : Eliminate redundant data type conversion
 * Block '<S30>/Reshape' : Reshape block reduction
 * Block '<S9>/ReshapeX0' : Reshape block reduction
 * Block '<S9>/Reshapeu' : Reshape block reduction
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
 * '<Root>' : 'Controller_implementation'
 * '<S1>'   : 'Controller_implementation/Kalman'
 * '<S2>'   : 'Controller_implementation/LQI_reduced_a'
 * '<S3>'   : 'Controller_implementation/Motor Control'
 * '<S4>'   : 'Controller_implementation/Radians to Degrees'
 * '<S5>'   : 'Controller_implementation/Radians to Degrees1'
 * '<S6>'   : 'Controller_implementation/Reference Generator'
 * '<S7>'   : 'Controller_implementation/Sensor Readings'
 * '<S8>'   : 'Controller_implementation/System U estimator'
 * '<S9>'   : 'Controller_implementation/Kalman/Kalman Filter'
 * '<S10>'  : 'Controller_implementation/Kalman/Kalman Filter/CalculatePL'
 * '<S11>'  : 'Controller_implementation/Kalman/Kalman Filter/CalculateYhat'
 * '<S12>'  : 'Controller_implementation/Kalman/Kalman Filter/CovarianceOutputConfigurator'
 * '<S13>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionA'
 * '<S14>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionB'
 * '<S15>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionC'
 * '<S16>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionD'
 * '<S17>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionEnable'
 * '<S18>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionG'
 * '<S19>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionH'
 * '<S20>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionN'
 * '<S21>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionP'
 * '<S22>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionP0'
 * '<S23>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionQ'
 * '<S24>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionR'
 * '<S25>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionReset'
 * '<S26>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionX'
 * '<S27>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionX0'
 * '<S28>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionu'
 * '<S29>'  : 'Controller_implementation/Kalman/Kalman Filter/MemoryP'
 * '<S30>'  : 'Controller_implementation/Kalman/Kalman Filter/Observer'
 * '<S31>'  : 'Controller_implementation/Kalman/Kalman Filter/ReducedQRN'
 * '<S32>'  : 'Controller_implementation/Kalman/Kalman Filter/Reset'
 * '<S33>'  : 'Controller_implementation/Kalman/Kalman Filter/Reshapeyhat'
 * '<S34>'  : 'Controller_implementation/Kalman/Kalman Filter/ScalarExpansionP0'
 * '<S35>'  : 'Controller_implementation/Kalman/Kalman Filter/ScalarExpansionQ'
 * '<S36>'  : 'Controller_implementation/Kalman/Kalman Filter/ScalarExpansionR'
 * '<S37>'  : 'Controller_implementation/Kalman/Kalman Filter/UseCurrentEstimator'
 * '<S38>'  : 'Controller_implementation/Kalman/Kalman Filter/checkA'
 * '<S39>'  : 'Controller_implementation/Kalman/Kalman Filter/checkB'
 * '<S40>'  : 'Controller_implementation/Kalman/Kalman Filter/checkC'
 * '<S41>'  : 'Controller_implementation/Kalman/Kalman Filter/checkD'
 * '<S42>'  : 'Controller_implementation/Kalman/Kalman Filter/checkEnable'
 * '<S43>'  : 'Controller_implementation/Kalman/Kalman Filter/checkG'
 * '<S44>'  : 'Controller_implementation/Kalman/Kalman Filter/checkH'
 * '<S45>'  : 'Controller_implementation/Kalman/Kalman Filter/checkN'
 * '<S46>'  : 'Controller_implementation/Kalman/Kalman Filter/checkP0'
 * '<S47>'  : 'Controller_implementation/Kalman/Kalman Filter/checkQ'
 * '<S48>'  : 'Controller_implementation/Kalman/Kalman Filter/checkR'
 * '<S49>'  : 'Controller_implementation/Kalman/Kalman Filter/checkReset'
 * '<S50>'  : 'Controller_implementation/Kalman/Kalman Filter/checkX0'
 * '<S51>'  : 'Controller_implementation/Kalman/Kalman Filter/checku'
 * '<S52>'  : 'Controller_implementation/Kalman/Kalman Filter/checky'
 * '<S53>'  : 'Controller_implementation/Kalman/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S54>'  : 'Controller_implementation/Kalman/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S55>'  : 'Controller_implementation/Kalman/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S56>'  : 'Controller_implementation/Kalman/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S57>'  : 'Controller_implementation/Kalman/Kalman Filter/CalculatePL/Ground'
 * '<S58>'  : 'Controller_implementation/Kalman/Kalman Filter/CalculateYhat/Ground'
 * '<S59>'  : 'Controller_implementation/Kalman/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S60>'  : 'Controller_implementation/Kalman/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S61>'  : 'Controller_implementation/Kalman/Kalman Filter/Observer/MeasurementUpdate'
 * '<S62>'  : 'Controller_implementation/Kalman/Kalman Filter/ReducedQRN/Ground'
 * '<S63>'  : 'Controller_implementation/Kalman/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S64>'  : 'Controller_implementation/Motor Control/Compare To Constant1'
 * '<S65>'  : 'Controller_implementation/Motor Control/MATLAB Function'
 * '<S66>'  : 'Controller_implementation/Motor Control/Motor Mixing Algorithm'
 * '<S67>'  : 'Controller_implementation/Motor Control/Motor Mixing Algorithm/Calculate PWM'
 * '<S68>'  : 'Controller_implementation/Sensor Readings/Degrees to Radians'
 * '<S69>'  : 'Controller_implementation/Sensor Readings/Pressure to altitude'
 * '<S70>'  : 'Controller_implementation/Sensor Readings/pitch'
 * '<S71>'  : 'Controller_implementation/Sensor Readings/roll '
 * '<S72>'  : 'Controller_implementation/Sensor Readings/yaw'
 * '<S73>'  : 'Controller_implementation/Sensor Readings/Pressure to altitude/Sample and Hold3'
 * '<S74>'  : 'Controller_implementation/Sensor Readings/Pressure to altitude/height'
 * '<S75>'  : 'Controller_implementation/System U estimator/Actuators'
 * '<S76>'  : 'Controller_implementation/System U estimator/MATLAB Function'
 * '<S77>'  : 'Controller_implementation/System U estimator/Actuators/MATLAB Function'
 */
#endif                                 /* Controller_implementation_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
