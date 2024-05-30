/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MotorWorking_data.c
 *
 * Code generated for Simulink model 'MotorWorking'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon May 27 17:09:21 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorWorking.h"

/* Block parameters (default storage) */
P_MotorWorking_T MotorWorking_P = {
  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S1>/Constant'
   */
  5.0,

  /* Expression: 50
   * Referenced by: '<Root>/Constant'
   */
  50.0,

  /* Expression: 5
   * Referenced by: '<Root>/Sine Wave'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Computed Parameter: SineWave_Hsin
   * Referenced by: '<Root>/Sine Wave'
   */
  0.01999866669333308,

  /* Computed Parameter: SineWave_HCos
   * Referenced by: '<Root>/Sine Wave'
   */
  0.99980000666657776,

  /* Computed Parameter: SineWave_PSin
   * Referenced by: '<Root>/Sine Wave'
   */
  -0.01999866669333308,

  /* Computed Parameter: SineWave_PCos
   * Referenced by: '<Root>/Sine Wave'
   */
  0.99980000666657776,

  /* Computed Parameter: Initial1_Value
   * Referenced by: '<Root>/Initial1'
   */
  40U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
