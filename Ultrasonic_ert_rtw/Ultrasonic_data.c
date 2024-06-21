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
 * C/C++ source code generated on : Thu Jun 20 17:33:09 2024
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
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<Root>/Pulse Generator'
   */
  1000.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<Root>/Pulse Generator'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0,

  /* Expression: sps.D
   * Referenced by: '<S4>/D'
   */
  0.047656876842497552,

  /* Expression: sps.x0
   * Referenced by: '<S4>/Delay_x'
   */
  0.0,

  /* Expression: sps.C
   * Referenced by: '<S4>/C'
   */
  0.0095234312315750237,

  /* Expression: sps.A
   * Referenced by: '<S4>/A'
   */
  0.90468624631500483,

  /* Expression: sps.B
   * Referenced by: '<S4>/B'
   */
  9.53137536849951,

  /* Computed Parameter: _Y0
   * Referenced by: '<S3>/ '
   */
  0U,

  /* Computed Parameter: TmpLatchAtSampleandHoldInport1_
   * Referenced by:
   */
  0U,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0U,

  /* Computed Parameter: Multiply_Gain
   * Referenced by: '<S1>/Multiply'
   */
  170U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
