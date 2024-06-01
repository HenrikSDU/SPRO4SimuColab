/*
 * Ultrasonic_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Ultrasonic".
 *
 * Model version              : 1.6
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Thu May 30 19:52:24 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(uint8_T),
  sizeof(uint16_T),
  sizeof(beagleboneblue_bbblueDigitalR_T),
  sizeof(beagleboneblue_bbblueDigitalW_T),
  sizeof(uint8_T),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "uint8_T",
  "uint16_T",
  "beagleboneblue_bbblueDigitalR_T",
  "beagleboneblue_bbblueDigitalW_T",
  "uint8_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Ultrasonic_B.PulseGenerator), 0, 0, 1 },

  { (char_T *)(&Ultrasonic_B.In), 16, 0, 1 },

  { (char_T *)(&Ultrasonic_B.echo), 8, 0, 1 }
  ,

  { (char_T *)(&Ultrasonic_DW.obj), 17, 0, 1 },

  { (char_T *)(&Ultrasonic_DW.obj_g), 18, 0, 1 },

  { (char_T *)(&Ultrasonic_DW.Scope_PWORK.LoggedData[0]), 11, 0, 3 },

  { (char_T *)(&Ultrasonic_DW.clockTickCounter), 6, 0, 1 },

  { (char_T *)(&Ultrasonic_DW.TmpLatchAtSampleandHoldInport1_), 16, 0, 1 },

  { (char_T *)(&Ultrasonic_DW.DiscreteTimeIntegrator_DSTATE), 15, 0, 1 },

  { (char_T *)(&Ultrasonic_DW.DiscreteTimeIntegrator_PrevRese), 2, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  10U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Ultrasonic_P.DigitalRead_SampleTime), 0, 0, 5 },

  { (char_T *)(&Ultrasonic_P._Y0), 16, 0, 2 },

  { (char_T *)(&Ultrasonic_P.DiscreteTimeIntegrator_IC), 15, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] Ultrasonic_dt.h */
