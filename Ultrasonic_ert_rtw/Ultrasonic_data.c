/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Ultrasonic_data.c
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

#include "Ultrasonic.h"

/* Block parameters (default storage) */
P_Ultrasonic_T Ultrasonic_P = {
  /* Expression: 0.001
   * Referenced by: '<Root>/Digital Read'
   */
  0.001,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<Root>/Pulse Generator'
   */
  10.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0,

  /* Computed Parameter: _Y0
   * Referenced by: '<S1>/ '
   */
  0U,

  /* Computed Parameter: TmpLatchAtSampleandHoldInport1_
   * Referenced by:
   */
  0U,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0U,

  /* Computed Parameter: Multiply_Gain
   * Referenced by: '<Root>/Multiply'
   */
  172U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
