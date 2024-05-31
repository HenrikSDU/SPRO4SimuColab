/*
 * MotorWorking_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MotorWorking".
 *
 * Model version              : 1.2
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Mon May 27 19:13:32 2024
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
  sizeof(beagleboneblue_bbblueBaromete_T),
  sizeof(beagleboneblue_bbblueMPU9250__T),
  sizeof(dsp_simulink_MovingAverage_Mo_T),
  sizeof(beagleboneblue_bbblueServo_Mo_T),
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
  "beagleboneblue_bbblueBaromete_T",
  "beagleboneblue_bbblueMPU9250__T",
  "dsp_simulink_MovingAverage_Mo_T",
  "beagleboneblue_bbblueServo_Mo_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&MotorWorking_B.Gain1[0]), 0, 0, 3 },

  { (char_T *)(&MotorWorking_B.z), 0, 0, 8 },

  { (char_T *)(&MotorWorking_B.TmpRTBAtSwitch1Inport1), 3, 0, 1 }
  ,

  { (char_T *)(&MotorWorking_DW.obj), 17, 0, 1 },

  { (char_T *)(&MotorWorking_DW.obj_d), 15, 0, 1 },

  { (char_T *)(&MotorWorking_DW.obj_j), 16, 0, 1 },

  { (char_T *)(&MotorWorking_DW.obj_jv), 18, 0, 4 },

  { (char_T *)(&MotorWorking_DW.TmpRTBAtSwitch1Inport3_Buffer0), 0, 0, 1 },

  { (char_T *)(&MotorWorking_DW.Scope1_PWORK.LoggedData[0]), 11, 0, 10 },

  { (char_T *)(&MotorWorking_DW.SampleandHold3_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&MotorWorking_DW.TmpRTBAtSwitch1Inport1_Buffer0), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  11U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&MotorWorking_P.Ts), 0, 0, 12 },

  { (char_T *)(&MotorWorking_P.TmpRTBAtSwitch1Inport1_InitialC), 3, 0, 3 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] MotorWorking_dt.h */
