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
 * C/C++ source code generated on : Mon May 27 19:13:32 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorWorking.h"

/* Block parameters (default storage) */
P_MotorWorking_T MotorWorking_P = {
  /* Variable: Ts
   * Referenced by:
   *   '<S2>/Barometer'
   *   '<S2>/MPU9250'
   */
  0.01,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S1>/Constant'
   */
  5.0,

  /* Expression: 1.0
   * Referenced by: '<S4>/Moving Average'
   */
  1.0,

  /* Expression: initCond
   * Referenced by: '<S8>/ '
   */
  1.0E+8,

  /* Expression: 1.054388803297024
   * Referenced by: '<Root>/Gain'
   */
  1.0543888032970239,

  /* Expression: pi/180
   * Referenced by: '<S3>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S2>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S4>/Step3'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S4>/Step3'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Step3'
   */
  1.0,

  /* Expression: 68
   * Referenced by: '<Root>/Constant'
   */
  68.0,

  /* Computed Parameter: TmpRTBAtSwitch1Inport1_InitialC
   * Referenced by:
   */
  0U,

  /* Computed Parameter: Initial1_Value
   * Referenced by: '<Root>/Initial1'
   */
  40U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
