/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pressure_types.h
 *
 * Code generated for Simulink model 'pressure'.
 *
 * Model version                  : 2.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon May 20 10:25:17 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef pressure_types_h_
#define pressure_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Custom Type definition for MATLABSystem: '<S1>/Barometer' */
#include "MW_SVD.h"
#ifndef struct_tag_oH2PxaXVLCzd6lwdaSR6p
#define struct_tag_oH2PxaXVLCzd6lwdaSR6p

struct tag_oH2PxaXVLCzd6lwdaSR6p
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_oH2PxaXVLCzd6lwdaSR6p */

#ifndef typedef_g_beagleboneblue_bbblueI2CMas_T
#define typedef_g_beagleboneblue_bbblueI2CMas_T

typedef struct tag_oH2PxaXVLCzd6lwdaSR6p g_beagleboneblue_bbblueI2CMas_T;

#endif                             /* typedef_g_beagleboneblue_bbblueI2CMas_T */

#ifndef struct_tag_AVxjDeyQkunEdpGYBzp3BE
#define struct_tag_AVxjDeyQkunEdpGYBzp3BE

struct tag_AVxjDeyQkunEdpGYBzp3BE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  real_T SampleTime;
  g_beagleboneblue_bbblueI2CMas_T i2cObj;
  uint16_T dig_T1;
  int16_T dig_T2;
  int16_T dig_T3;
  uint16_T dig_P1;
  int16_T dig_P2;
  int16_T dig_P3;
  int16_T dig_P4;
  int16_T dig_P5;
  int16_T dig_P6;
  int16_T dig_P7;
  int16_T dig_P8;
  int16_T dig_P9;
  boolean_T BMPConnect;
};

#endif                                 /* struct_tag_AVxjDeyQkunEdpGYBzp3BE */

#ifndef typedef_beagleboneblue_bbblueBaromete_T
#define typedef_beagleboneblue_bbblueBaromete_T

typedef struct tag_AVxjDeyQkunEdpGYBzp3BE beagleboneblue_bbblueBaromete_T;

#endif                             /* typedef_beagleboneblue_bbblueBaromete_T */

#ifndef struct_tag_AsOxN3n1NecewzPiU8MVVE
#define struct_tag_AsOxN3n1NecewzPiU8MVVE

struct tag_AsOxN3n1NecewzPiU8MVVE
{
  int32_T S0_isInitialized;
  real_T W0_states[513];
  real_T W1_simContextBuf[1026];
  real_T W2_simRevCoeff[514];
  int32_T W3_halideSimTBBGrainSize;
  real_T P0_InitialStates;
  real_T P1_Coefficients[514];
};

#endif                                 /* struct_tag_AsOxN3n1NecewzPiU8MVVE */

#ifndef typedef_b_dsp_FIRFilter_0_pressure_T
#define typedef_b_dsp_FIRFilter_0_pressure_T

typedef struct tag_AsOxN3n1NecewzPiU8MVVE b_dsp_FIRFilter_0_pressure_T;

#endif                                /* typedef_b_dsp_FIRFilter_0_pressure_T */

#ifndef struct_tag_96Mf4SScldVSxksKiIoDZF
#define struct_tag_96Mf4SScldVSxksKiIoDZF

struct tag_96Mf4SScldVSxksKiIoDZF
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_pressure_T cSFunObject;
};

#endif                                 /* struct_tag_96Mf4SScldVSxksKiIoDZF */

#ifndef typedef_b_dspcodegen_FIRFilter_pressu_T
#define typedef_b_dspcodegen_FIRFilter_pressu_T

typedef struct tag_96Mf4SScldVSxksKiIoDZF b_dspcodegen_FIRFilter_pressu_T;

#endif                             /* typedef_b_dspcodegen_FIRFilter_pressu_T */

#ifndef struct_tag_xm5q3dGCROLmOPhUk992jB
#define struct_tag_xm5q3dGCROLmOPhUk992jB

struct tag_xm5q3dGCROLmOPhUk992jB
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  real_T ForgettingFactor;
  real_T pwN;
  real_T pmN;
  real_T plambda;
};

#endif                                 /* struct_tag_xm5q3dGCROLmOPhUk992jB */

#ifndef typedef_h_dsp_internal_ExponentialMov_T
#define typedef_h_dsp_internal_ExponentialMov_T

typedef struct tag_xm5q3dGCROLmOPhUk992jB h_dsp_internal_ExponentialMov_T;

#endif                             /* typedef_h_dsp_internal_ExponentialMov_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_pressure_T
#define typedef_cell_wrap_pressure_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_pressure_T;

#endif                                 /* typedef_cell_wrap_pressure_T */

#ifndef struct_tag_va6ONpw9abisLr5kG3DOME
#define struct_tag_va6ONpw9abisLr5kG3DOME

struct tag_va6ONpw9abisLr5kG3DOME
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_pressure_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_pressu_T *FilterObj;
  b_dspcodegen_FIRFilter_pressu_T _pobj0;
};

#endif                                 /* struct_tag_va6ONpw9abisLr5kG3DOME */

#ifndef typedef_dsp_simulink_LowpassFilter_pr_T
#define typedef_dsp_simulink_LowpassFilter_pr_T

typedef struct tag_va6ONpw9abisLr5kG3DOME dsp_simulink_LowpassFilter_pr_T;

#endif                             /* typedef_dsp_simulink_LowpassFilter_pr_T */

#ifndef struct_tag_V9i0BeISxaZywwPOT5PprG
#define struct_tag_V9i0BeISxaZywwPOT5PprG

struct tag_V9i0BeISxaZywwPOT5PprG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_pressure_T inputVarSize;
  real_T ForgettingFactor;
  h_dsp_internal_ExponentialMov_T *pStatistic;
  int32_T NumChannels;
  int32_T FrameLength;
  h_dsp_internal_ExponentialMov_T _pobj0;
};

#endif                                 /* struct_tag_V9i0BeISxaZywwPOT5PprG */

#ifndef typedef_dsp_simulink_MovingAverage_pr_T
#define typedef_dsp_simulink_MovingAverage_pr_T

typedef struct tag_V9i0BeISxaZywwPOT5PprG dsp_simulink_MovingAverage_pr_T;

#endif                             /* typedef_dsp_simulink_MovingAverage_pr_T */

/* Parameters (default storage) */
typedef struct P_pressure_T_ P_pressure_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_pressure_T RT_MODEL_pressure_T;

#endif                                 /* pressure_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
