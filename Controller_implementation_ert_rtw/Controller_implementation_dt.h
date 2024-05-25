/*
 * Controller_implementation_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Controller_implementation".
 *
 * Model version              : 1.16
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Fri May 24 10:07:43 2024
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
  sizeof(beagleboneblue_bbblueServo_Co_T),
  sizeof(beagleboneblue_bbblueBaromete_T),
  sizeof(beagleboneblue_bbblueMPU9250__T),
  sizeof(dsp_simulink_MovingAverage_Co_T),
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
  "beagleboneblue_bbblueServo_Co_T",
  "beagleboneblue_bbblueBaromete_T",
  "beagleboneblue_bbblueMPU9250__T",
  "dsp_simulink_MovingAverage_Co_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Controller_implementation_B.z), 0, 0, 52 }
  ,

  { (char_T *)(&Controller_implementation_DW.obj), 18, 0, 1 },

  { (char_T *)(&Controller_implementation_DW.obj_j), 16, 0, 1 },

  { (char_T *)(&Controller_implementation_DW.obj_n), 17, 0, 1 },

  { (char_T *)(&Controller_implementation_DW.obj_b), 15, 0, 4 },

  { (char_T *)(&Controller_implementation_DW.MemoryX_DSTATE[0]), 0, 0, 12 },

  { (char_T *)(&Controller_implementation_DW.Scope_PWORK.LoggedData[0]), 11, 0,
    25 },

  { (char_T *)(&Controller_implementation_DW.SampleandHold3_SubsysRanBC), 2, 0,
    3 },

  { (char_T *)(&Controller_implementation_DW.icLoad), 8, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Controller_implementation_P.F[0]), 0, 0, 499 },

  { (char_T *)(&Controller_implementation_P.Enable_Value), 8, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] Controller_implementation_dt.h */
