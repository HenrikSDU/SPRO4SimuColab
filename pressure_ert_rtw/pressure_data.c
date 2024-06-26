/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pressure_data.c
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

#include "pressure.h"

/* Block parameters (default storage) */
P_pressure_T pressure_P = {
  /* Expression: 0.01
   * Referenced by: '<S1>/Barometer'
   */
  0.01,

  /* Expression: 1.0
   * Referenced by: '<S2>/Moving Average'
   */
  1.0,

  /* Expression: initCond
   * Referenced by: '<S3>/ '
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S2>/Step3'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S2>/Step3'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/Step3'
   */
  1.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
