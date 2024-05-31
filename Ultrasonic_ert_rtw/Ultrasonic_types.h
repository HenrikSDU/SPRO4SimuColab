/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Ultrasonic_types.h
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

#ifndef Ultrasonic_types_h_
#define Ultrasonic_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Custom Type definition for MATLABSystem: '<Root>/Digital Write' */
#include "MW_SVD.h"
#ifndef struct_tag_1EBWQ6hhKs9Y37qjpZj8aH
#define struct_tag_1EBWQ6hhKs9Y37qjpZj8aH

struct tag_1EBWQ6hhKs9Y37qjpZj8aH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_1EBWQ6hhKs9Y37qjpZj8aH */

#ifndef typedef_beagleboneblue_bbblueDigitalR_T
#define typedef_beagleboneblue_bbblueDigitalR_T

typedef struct tag_1EBWQ6hhKs9Y37qjpZj8aH beagleboneblue_bbblueDigitalR_T;

#endif                             /* typedef_beagleboneblue_bbblueDigitalR_T */

#ifndef struct_tag_xLdvsTzAcwQ23cLj0I6KhF
#define struct_tag_xLdvsTzAcwQ23cLj0I6KhF

struct tag_xLdvsTzAcwQ23cLj0I6KhF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /* struct_tag_xLdvsTzAcwQ23cLj0I6KhF */

#ifndef typedef_beagleboneblue_bbblueDigitalW_T
#define typedef_beagleboneblue_bbblueDigitalW_T

typedef struct tag_xLdvsTzAcwQ23cLj0I6KhF beagleboneblue_bbblueDigitalW_T;

#endif                             /* typedef_beagleboneblue_bbblueDigitalW_T */

/* Parameters (default storage) */
typedef struct P_Ultrasonic_T_ P_Ultrasonic_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Ultrasonic_T RT_MODEL_Ultrasonic_T;

#endif                                 /* Ultrasonic_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
