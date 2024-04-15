/*
 * DroneModel_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DroneModel".
 *
 * Model version              : 1.17
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Thu Mar 21 13:26:39 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DroneModel.h"

/* Block parameters (default storage) */
P_DroneModel_T DroneModel_P = {
  /* Variable: A
   * Referenced by: '<S2>/State-Space'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 9.81, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -9.81, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0 },

  /* Variable: B
   * Referenced by: '<S2>/State-Space'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 12.755102040816327,
    -3.7878787878787881, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0,
    12.755102040816327, 0.0, 3.7878787878787881, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0,
    0.0, 0.0, 0.0, 0.0, -12.755102040816327, -3.7878787878787881, 0.0, 0.0, 0.0,
    0.0, 0.0, 2.0, 0.0, 0.0, 0.0, -12.755102040816327, 0.0, 3.7878787878787881 },

  /* Variable: C
   * Referenced by: '<S2>/State-Space'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Variable: g
   * Referenced by: '<S3>/Load per motor'
   */
  9.81,

  /* Variable: m
   * Referenced by: '<S3>/Load per motor'
   */
  0.5,

  /* Variable: x0
   * Referenced by: '<S2>/State-Space'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0.1
   * Referenced by: '<S2>/Barometer'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S2>/MPU9250'
   */
  0.1,

  /* Expression: [1.5; 1.2; 1.5; 1.2;]
   * Referenced by: '<S2>/Motor Thrusts'
   */
  { 1.5, 1.2, 1.5, 1.2 },

  /* Expression: 1
   * Referenced by: '<S2>/Multiply'
   */
  1.0,

  /* Expression: 5
   * Referenced by: '<S2>/Step'
   */
  5.0,

  /* Expression: 1
   * Referenced by: '<S2>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Step'
   */
  0.0
};
