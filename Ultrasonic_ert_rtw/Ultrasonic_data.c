/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Ultrasonic_data.c
 *
 * Code generated for Simulink model 'Ultrasonic'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu May 23 18:11:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Ultrasonic.h"

/* Block parameters (default storage) */
P_Ultrasonic_T Ultrasonic_P = {
  /* Expression: 0.0001
   * Referenced by: '<Root>/Digital Read'
   */
  0.0001,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Unit Delay'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0U,

  /* Computed Parameter: Multiply_Gain
   * Referenced by: '<S2>/Multiply'
   */
  170U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
