/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Controller_implementation.h
 *
 * Code generated for Simulink model 'Controller_implementation'.
 *
 * Model version                  : 1.32
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Jun 20 18:11:25 2024
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
#include "MW_digitalIO.h"
#include "MW_MPU9250.h"
#endif                          /* Controller_implementation_COMMON_INCLUDES_ */

#include "Controller_implementation_types.h"
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
  real_T TmpRTBAtEnabledSubsystemInp[56];
  real_T TmpRTBAtEnabledSubsystemI_g[56];
  real_T Bkuk[8];                      /* '<S29>/B[k]*u[k]' */
  real_T Add[8];                       /* '<S29>/Add' */
  uint8_T b_output[24];
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
  real_T RateTransition;               /* '<S5>/Rate Transition' */
  real_T Gain;                         /* '<S67>/Gain' */
  real_T Gain1[3];                     /* '<S66>/Gain1' */
  real_T Reshapexhat[8];               /* '<S7>/Reshapexhat' */
  real_T Gain_f[4];                    /* '<S2>/Gain' */
  real_T PWMlimit[4];                  /* '<S3>/PWM limit' */
  real_T Sum[4];                       /* '<S6>/Sum' */
  real_T U[4];                         /* '<S6>/MATLAB Function' */
  real_T req_rotorspeed[4];
  real_T DersiredMotorThrusts[4];      /* '<S64>/Gain' */
  real_T roll;                         /* '<S5>/roll ' */
  real_T pitch;                        /* '<S5>/pitch' */
  real_T In;                           /* '<S72>/In' */
  real_T In_c[7];                      /* '<S8>/In' */
  real_T Product2[8];                  /* '<S62>/Product2' */
  real_T Product3[8];                  /* '<S60>/Product3' */
  real_T dv[7];
  real_T max_possible_rot_speed;
  real_T pwLocal;
  real_T lambda;
  real_T yaw;
  real_T rtb_DersiredMotorThrusts_c;
  real_T Gain_f_k;
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
  uint16_T In_d;                       /* '<S75>/In' */
  boolean_T DigitalRead;               /* '<S5>/Digital Read' */
} B_Controller_implementation_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_Co_T obj; /* '<S67>/Moving Average' */
  beagleboneblue_bbblueBaromete_T obj_j;/* '<S5>/Barometer' */
  beagleboneblue_bbblueMPU9250__T obj_n;/* '<S5>/MPU9250' */
  beagleboneblue_bbblueDigitalR_T obj_b;/* '<S5>/Digital Read' */
  beagleboneblue_bbblueServo_Co_T obj_bh;/* '<S3>/Motor 4' */
  beagleboneblue_bbblueServo_Co_T obj_h;/* '<S3>/Motor 3' */
  beagleboneblue_bbblueServo_Co_T obj_p;/* '<S3>/Motor 2' */
  beagleboneblue_bbblueServo_Co_T obj_k;/* '<S3>/Motor 1' */
  beagleboneblue_bbblueDigitalW_T obj_d;/* '<S73>/Digital Write' */
  real_T Delay_x_DSTATE;               /* '<S76>/Delay_x' */
  real_T MemoryX_DSTATE[8];            /* '<S7>/MemoryX' */
  volatile real_T TmpRTBAtMeasurementUpdateInport[56];/* synthesized block */
  volatile real_T TmpRTBAtEnabledSubsystemInport2[56];/* synthesized block */
  volatile real_T TmpRTBAtMeasurementUpdateInpo_p[56];/* synthesized block */
  volatile real_T TmpRTBAtEnabledSubsystemInport1[56];/* synthesized block */
  real_T RateTransition_Buffer;        /* '<S5>/Rate Transition' */
  real_T RateTransition_Buffer_c[4];   /* '<S3>/Rate Transition' */
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
  } TrackPWM_PWORK;                    /* '<S3>/Track PWM' */

  struct {
    void *LoggedData;
  } DesiredU_PWORK;                    /* '<Root>/Desired U' */

  struct {
    void *LoggedData[7];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  int32_T clockTickCounter;            /* '<S73>/Pulse Generator' */
  uint16_T TmpLatchAtSampleandHoldInport1_;/* synthesized block */
  uint16_T RateTransition1_Buffer;     /* '<S73>/Rate Transition1' */
  uint8_T DiscreteTimeIntegrator_DSTATE;/* '<S73>/Discrete-Time Integrator' */
  volatile int8_T TmpRTBAtMeasurementUpdateInpo_j;/* synthesized block */
  volatile int8_T TmpRTBAtEnabledSubsystemInpor_n;/* synthesized block */
  volatile int8_T TmpRTBAtMeasurementUpdateInp_pv;/* synthesized block */
  volatile int8_T TmpRTBAtEnabledSubsystemInpor_l;/* synthesized block */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S73>/Discrete-Time Integrator' */
  int8_T SampleandHold_SubsysRanBC;    /* '<S73>/Sample and Hold' */
  int8_T SampleandHold_SubsysRanBC_p;  /* '<S67>/Sample and Hold' */
  int8_T SampleandHold_SubsysRanBC_k;  /* '<S1>/Sample and Hold' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S36>/Enabled Subsystem' */
  int8_T MeasurementUpdate_SubsysRanBC;/* '<S29>/MeasurementUpdate' */
  boolean_T RateTransition2_Buffer;    /* '<S3>/Rate Transition2' */
  boolean_T icLoad;                    /* '<S7>/MemoryX' */
  boolean_T EnabledSubsystem_MODE;     /* '<S36>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S29>/MeasurementUpdate' */
} DW_Controller_implementation_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SampleandHold_Trig_ZCE;   /* '<S73>/Sample and Hold' */
  ZCSigState SampleandHold_Trig_ZCE_e; /* '<S67>/Sample and Hold' */
  ZCSigState SampleandHold_Trig_ZCE_i; /* '<S1>/Sample and Hold' */
} PrevZCX_Controller_implementa_T;

/* Parameters (default storage) */
struct P_Controller_implementation_T_ {
  real_T KV_rating;                    /* Variable: KV_rating
                                        * Referenced by:
                                        *   '<S64>/Constant1'
                                        *   '<S77>/Constant'
                                        */
  real_T K_D_LQR_reduced[32];          /* Variable: K_D_LQR_reduced
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T K_mm[16];                     /* Variable: K_mm
                                        * Referenced by: '<S64>/Gain'
                                        */
  real_T Ts;                           /* Variable: Ts
                                        * Referenced by:
                                        *   '<S5>/Barometer'
                                        *   '<S5>/MPU9250'
                                        */
  real_T battery_voltage;              /* Variable: battery_voltage
                                        * Referenced by:
                                        *   '<S64>/Constant'
                                        *   '<S77>/Battery Voltage'
                                        */
  real_T dis;                          /* Variable: dis
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T drag_co;                      /* Variable: drag_co
                                        * Referenced by: '<S77>/Gain1'
                                        */
  real_T lift_co;                      /* Variable: lift_co
                                        * Referenced by:
                                        *   '<S64>/Constant2'
                                        *   '<S77>/Gain'
                                        */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S63>/Constant'
                                      */
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S60>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T deltax_Y0;                    /* Expression: 0
                                        * Referenced by: '<S62>/deltax'
                                        */
  real_T _Y0;                          /* Expression: initCond
                                        * Referenced by: '<S8>/ '
                                        */
  real_T DigitalRead_SampleTime;       /* Expression: 0.0001
                                        * Referenced by: '<S5>/Digital Read'
                                        */
  real_T MovingAverage_ForgettingFactor;/* Expression: 1
                                         * Referenced by: '<S67>/Moving Average'
                                         */
  real_T _Y0_l;                        /* Expression: initCond
                                        * Referenced by: '<S72>/ '
                                        */
  real_T CovarianceZ_Value[64];        /* Expression: pInitialization.Z
                                        * Referenced by: '<S9>/CovarianceZ'
                                        */
  real_T C_Value[56];                  /* Expression: pInitialization.C
                                        * Referenced by: '<S7>/C'
                                        */
  real_T KalmanGainL_Value[56];        /* Expression: pInitialization.L
                                        * Referenced by: '<S9>/KalmanGainL'
                                        */
  real_T KalmanGainM_Value[56];        /* Expression: pInitialization.M
                                        * Referenced by: '<S9>/KalmanGainM'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S73>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S73>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S73>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S73>/Pulse Generator'
                                        */
  real_T Delay_x_InitialCondition;     /* Expression: sps.x0
                                        * Referenced by: '<S76>/Delay_x'
                                        */
  real_T C_Gain;                       /* Expression: sps.C
                                        * Referenced by: '<S76>/C'
                                        */
  real_T D_Gain;                       /* Expression: sps.D
                                        * Referenced by: '<S76>/D'
                                        */
  real_T B_Gain;                       /* Expression: sps.B
                                        * Referenced by: '<S76>/B'
                                        */
  real_T A_Gain;                       /* Expression: sps.A
                                        * Referenced by: '<S76>/A'
                                        */
  real_T A_Value[64];                  /* Expression: pInitialization.A
                                        * Referenced by: '<S7>/A'
                                        */
  real_T B_Value[32];                  /* Expression: pInitialization.B
                                        * Referenced by: '<S7>/B'
                                        */
  real_T D_Value[28];                  /* Expression: pInitialization.D
                                        * Referenced by: '<S7>/D'
                                        */
  real_T Step_Time;                    /* Expression: 0.1
                                        * Referenced by: '<S67>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S67>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S67>/Step'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S67>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S66>/Gain1'
                                        */
  real_T Constant_Value[8];            /* Expression: [0.2;0;0;0;0;0;0;0;]
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Step_Time_a;                  /* Expression: 0.02
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Step_Y0_h;                    /* Expression: 0
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Step_YFinal_b;                /* Expression: 1
                                        * Referenced by: '<S1>/Step'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T PWMlimit_UpperSat;            /* Expression: 140
                                        * Referenced by: '<S3>/PWM limit'
                                        */
  real_T PWMlimit_LowerSat;            /* Expression: 40
                                        * Referenced by: '<S3>/PWM limit'
                                        */
  real_T SignConvention_Gain[4];       /* Expression: [1;-1;1;-1]
                                        * Referenced by: '<S77>/Sign Convention'
                                        */
  real_T Constant1_Value[4];           /* Expression: [-m*g*0;0;0;0]
                                        * Referenced by: '<S6>/Constant1'
                                        */
  uint16_T _Y0_b;                      /* Computed Parameter: _Y0_b
                                        * Referenced by: '<S75>/ '
                                        */
  uint16_T TmpLatchAtSampleandHoldInport1_;
                          /* Computed Parameter: TmpLatchAtSampleandHoldInport1_
                           * Referenced by:
                           */
  boolean_T isSqrtUsed_Value;          /* Expression: pInitialization.isSqrtUsed
                                        * Referenced by: '<S58>/isSqrtUsed'
                                        */
  boolean_T Enable_Value;              /* Expression: true()
                                        * Referenced by: '<S7>/Enable'
                                        */
  uint8_T DiscreteTimeIntegrator_IC;
                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                 * Referenced by: '<S73>/Discrete-Time Integrator'
                                 */
  uint8_T Gain_Gain_d;                 /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S73>/Gain'
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
    uint32_T clockTick3;
    uint32_T clockTick4;
    struct {
      uint16_T TID[5];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
      boolean_T TID1_3;
      boolean_T TID2_3;
      boolean_T TID3_4;
    } RateInteraction;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[5];
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
extern void Controller_implementation_step3(void);
extern void Controller_implementation_step4(void);
extern void Controller_implementation_step(int_T tid);
extern void Controller_implementation_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Controller_implement_T *const Controller_implementation_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S53>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Conversion' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Conversion' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/G' : Unused code path elimination
 * Block '<S7>/H' : Unused code path elimination
 * Block '<S7>/N' : Unused code path elimination
 * Block '<S7>/P0' : Unused code path elimination
 * Block '<S7>/Q' : Unused code path elimination
 * Block '<S7>/R' : Unused code path elimination
 * Block '<S49>/CheckSignalProperties' : Unused code path elimination
 * Block '<S50>/CheckSignalProperties' : Unused code path elimination
 * Block '<S51>/CheckSignalProperties' : Unused code path elimination
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S4>/Constant1' : Unused code path elimination
 * Block '<S52>/Conversion' : Eliminate redundant data type conversion
 * Block '<S53>/Conversion' : Eliminate redundant data type conversion
 * Block '<S55>/Conversion' : Eliminate redundant data type conversion
 * Block '<S25>/Conversion' : Eliminate redundant data type conversion
 * Block '<S29>/Reshape' : Reshape block reduction
 * Block '<S7>/ReshapeX0' : Reshape block reduction
 * Block '<S7>/Reshapeu' : Reshape block reduction
 * Block '<S7>/Reshapey' : Reshape block reduction
 * Block '<S1>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S3>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S67>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<Root>/Zero-Order Hold' : Eliminated since input and output rates are identical
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
 * '<S2>'   : 'Controller_implementation/LQR_reduced'
 * '<S3>'   : 'Controller_implementation/Motor Control'
 * '<S4>'   : 'Controller_implementation/Reference Generator'
 * '<S5>'   : 'Controller_implementation/Sensor Readings'
 * '<S6>'   : 'Controller_implementation/System U estimator'
 * '<S7>'   : 'Controller_implementation/Kalman/Kalman Filter'
 * '<S8>'   : 'Controller_implementation/Kalman/Sample and Hold'
 * '<S9>'   : 'Controller_implementation/Kalman/Kalman Filter/CalculatePL'
 * '<S10>'  : 'Controller_implementation/Kalman/Kalman Filter/CalculateYhat'
 * '<S11>'  : 'Controller_implementation/Kalman/Kalman Filter/CovarianceOutputConfigurator'
 * '<S12>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionA'
 * '<S13>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionB'
 * '<S14>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionC'
 * '<S15>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionD'
 * '<S16>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionEnable'
 * '<S17>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionG'
 * '<S18>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionH'
 * '<S19>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionN'
 * '<S20>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionP'
 * '<S21>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionP0'
 * '<S22>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionQ'
 * '<S23>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionR'
 * '<S24>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionReset'
 * '<S25>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionX'
 * '<S26>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionX0'
 * '<S27>'  : 'Controller_implementation/Kalman/Kalman Filter/DataTypeConversionu'
 * '<S28>'  : 'Controller_implementation/Kalman/Kalman Filter/MemoryP'
 * '<S29>'  : 'Controller_implementation/Kalman/Kalman Filter/Observer'
 * '<S30>'  : 'Controller_implementation/Kalman/Kalman Filter/ReducedQRN'
 * '<S31>'  : 'Controller_implementation/Kalman/Kalman Filter/Reset'
 * '<S32>'  : 'Controller_implementation/Kalman/Kalman Filter/Reshapeyhat'
 * '<S33>'  : 'Controller_implementation/Kalman/Kalman Filter/ScalarExpansionP0'
 * '<S34>'  : 'Controller_implementation/Kalman/Kalman Filter/ScalarExpansionQ'
 * '<S35>'  : 'Controller_implementation/Kalman/Kalman Filter/ScalarExpansionR'
 * '<S36>'  : 'Controller_implementation/Kalman/Kalman Filter/UseCurrentEstimator'
 * '<S37>'  : 'Controller_implementation/Kalman/Kalman Filter/checkA'
 * '<S38>'  : 'Controller_implementation/Kalman/Kalman Filter/checkB'
 * '<S39>'  : 'Controller_implementation/Kalman/Kalman Filter/checkC'
 * '<S40>'  : 'Controller_implementation/Kalman/Kalman Filter/checkD'
 * '<S41>'  : 'Controller_implementation/Kalman/Kalman Filter/checkEnable'
 * '<S42>'  : 'Controller_implementation/Kalman/Kalman Filter/checkG'
 * '<S43>'  : 'Controller_implementation/Kalman/Kalman Filter/checkH'
 * '<S44>'  : 'Controller_implementation/Kalman/Kalman Filter/checkN'
 * '<S45>'  : 'Controller_implementation/Kalman/Kalman Filter/checkP0'
 * '<S46>'  : 'Controller_implementation/Kalman/Kalman Filter/checkQ'
 * '<S47>'  : 'Controller_implementation/Kalman/Kalman Filter/checkR'
 * '<S48>'  : 'Controller_implementation/Kalman/Kalman Filter/checkReset'
 * '<S49>'  : 'Controller_implementation/Kalman/Kalman Filter/checkX0'
 * '<S50>'  : 'Controller_implementation/Kalman/Kalman Filter/checku'
 * '<S51>'  : 'Controller_implementation/Kalman/Kalman Filter/checky'
 * '<S52>'  : 'Controller_implementation/Kalman/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S53>'  : 'Controller_implementation/Kalman/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S54>'  : 'Controller_implementation/Kalman/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S55>'  : 'Controller_implementation/Kalman/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S56>'  : 'Controller_implementation/Kalman/Kalman Filter/CalculatePL/Ground'
 * '<S57>'  : 'Controller_implementation/Kalman/Kalman Filter/CalculateYhat/Ground'
 * '<S58>'  : 'Controller_implementation/Kalman/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S59>'  : 'Controller_implementation/Kalman/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S60>'  : 'Controller_implementation/Kalman/Kalman Filter/Observer/MeasurementUpdate'
 * '<S61>'  : 'Controller_implementation/Kalman/Kalman Filter/ReducedQRN/Ground'
 * '<S62>'  : 'Controller_implementation/Kalman/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S63>'  : 'Controller_implementation/Motor Control/Compare To Constant1'
 * '<S64>'  : 'Controller_implementation/Motor Control/Motor Mixing Algorithm'
 * '<S65>'  : 'Controller_implementation/Motor Control/Motor Mixing Algorithm/Calculate PWM'
 * '<S66>'  : 'Controller_implementation/Sensor Readings/Degrees to Radians'
 * '<S67>'  : 'Controller_implementation/Sensor Readings/Yaw Offset'
 * '<S68>'  : 'Controller_implementation/Sensor Readings/altitude cal'
 * '<S69>'  : 'Controller_implementation/Sensor Readings/pitch'
 * '<S70>'  : 'Controller_implementation/Sensor Readings/roll '
 * '<S71>'  : 'Controller_implementation/Sensor Readings/yaw'
 * '<S72>'  : 'Controller_implementation/Sensor Readings/Yaw Offset/Sample and Hold'
 * '<S73>'  : 'Controller_implementation/Sensor Readings/altitude cal/altitude calc'
 * '<S74>'  : 'Controller_implementation/Sensor Readings/altitude cal/altitude calc/First-Order Filter'
 * '<S75>'  : 'Controller_implementation/Sensor Readings/altitude cal/altitude calc/Sample and Hold'
 * '<S76>'  : 'Controller_implementation/Sensor Readings/altitude cal/altitude calc/First-Order Filter/Model'
 * '<S77>'  : 'Controller_implementation/System U estimator/Actuators'
 * '<S78>'  : 'Controller_implementation/System U estimator/MATLAB Function'
 * '<S79>'  : 'Controller_implementation/System U estimator/Actuators/MATLAB Function'
 */
#endif                                 /* Controller_implementation_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
