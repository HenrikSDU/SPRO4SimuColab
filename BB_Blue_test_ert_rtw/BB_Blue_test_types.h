/*
 * BB_Blue_test_types.h
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

#ifndef RTW_HEADER_BB_Blue_test_types_h_
#define RTW_HEADER_BB_Blue_test_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Custom Type definition for MATLABSystem: '<Root>/MPU9250' */
#include "MW_SVD.h"
#include "MW_I2C.h"
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

#ifndef typedef_i_beagleboneblue_bbblueI2CMas_T
#define typedef_i_beagleboneblue_bbblueI2CMas_T

typedef struct tag_oH2PxaXVLCzd6lwdaSR6p i_beagleboneblue_bbblueI2CMas_T;

#endif                             /* typedef_i_beagleboneblue_bbblueI2CMas_T */

#ifndef struct_tag_s0kXae1yCOw6kF09CPTiMB
#define struct_tag_s0kXae1yCOw6kF09CPTiMB

struct tag_s0kXae1yCOw6kF09CPTiMB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_s0kXae1yCOw6kF09CPTiMB */

#ifndef typedef_j_beagleboneblue_bbblueI2CMas_T
#define typedef_j_beagleboneblue_bbblueI2CMas_T

typedef struct tag_s0kXae1yCOw6kF09CPTiMB j_beagleboneblue_bbblueI2CMas_T;

#endif                             /* typedef_j_beagleboneblue_bbblueI2CMas_T */

#ifndef struct_tag_A4EdOul8eEsRYmBAaIUDRF
#define struct_tag_A4EdOul8eEsRYmBAaIUDRF

struct tag_A4EdOul8eEsRYmBAaIUDRF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T SampleTime;
  i_beagleboneblue_bbblueI2CMas_T i2cObjmpu;
  j_beagleboneblue_bbblueI2CMas_T i2cObjak8963;
};

#endif                                 /* struct_tag_A4EdOul8eEsRYmBAaIUDRF */

#ifndef typedef_beagleboneblue_bbblueMPU9250__T
#define typedef_beagleboneblue_bbblueMPU9250__T

typedef struct tag_A4EdOul8eEsRYmBAaIUDRF beagleboneblue_bbblueMPU9250__T;

#endif                             /* typedef_beagleboneblue_bbblueMPU9250__T */

/* Parameters (default storage) */
typedef struct P_BB_Blue_test_T_ P_BB_Blue_test_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_BB_Blue_test_T RT_MODEL_BB_Blue_test_T;

#endif                                 /* RTW_HEADER_BB_Blue_test_types_h_ */
