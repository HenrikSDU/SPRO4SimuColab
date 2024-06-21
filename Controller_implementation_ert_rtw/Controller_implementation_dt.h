/*
 * Controller_implementation_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Controller_implementation".
 *
 * Model version              : 1.32
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Thu Jun 20 18:11:25 2024
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
  sizeof(beagleboneblue_bbblueServo_Co_T),
  sizeof(beagleboneblue_bbblueBaromete_T),
  sizeof(beagleboneblue_bbblueDigitalR_T),
  sizeof(beagleboneblue_bbblueMPU9250__T),
  sizeof(dsp_simulink_MovingAverage_Co_T),
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
  "beagleboneblue_bbblueServo_Co_T",
  "beagleboneblue_bbblueBaromete_T",
  "beagleboneblue_bbblueDigitalR_T",
  "beagleboneblue_bbblueMPU9250__T",
  "dsp_simulink_MovingAverage_Co_T",
  "beagleboneblue_bbblueDigitalW_T",
  "uint8_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Controller_implementation_B.RateTransition), 0, 0, 29 },

  { (char_T *)(&Controller_implementation_B.roll), 0, 0, 26 },

  { (char_T *)(&Controller_implementation_B.In_d), 16, 0, 1 },

  { (char_T *)(&Controller_implementation_B.DigitalRead), 8, 0, 1 }
  ,

  { (char_T *)(&Controller_implementation_DW.obj), 21, 0, 1 },

  { (char_T *)(&Controller_implementation_DW.obj_j), 18, 0, 1 },

  { (char_T *)(&Controller_implementation_DW.obj_n), 20, 0, 1 },

  { (char_T *)(&Controller_implementation_DW.obj_b), 19, 0, 1 },

  { (char_T *)(&Controller_implementation_DW.obj_bh), 17, 0, 4 },

  { (char_T *)(&Controller_implementation_DW.obj_d), 22, 0, 1 },

  { (char_T *)(&Controller_implementation_DW.Delay_x_DSTATE), 0, 0, 238 },

  { (char_T *)(&Controller_implementation_DW.Scope_PWORK.LoggedData[0]), 11, 0,
    19 },

  { (char_T *)(&Controller_implementation_DW.clockTickCounter), 6, 0, 1 },

  { (char_T *)(&Controller_implementation_DW.TmpLatchAtSampleandHoldInport1_),
    16, 0, 2 },

  { (char_T *)(&Controller_implementation_DW.DiscreteTimeIntegrator_DSTATE), 15,
    0, 1 },

  { (char_T *)(&Controller_implementation_DW.TmpRTBAtMeasurementUpdateInpo_j), 2,
    0, 10 },

  { (char_T *)(&Controller_implementation_DW.RateTransition2_Buffer), 8, 0, 4 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  17U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Controller_implementation_P.KV_rating), 0, 0, 453 },

  { (char_T *)(&Controller_implementation_P._Y0_b), 16, 0, 2 },

  { (char_T *)(&Controller_implementation_P.isSqrtUsed_Value), 8, 0, 2 },

  { (char_T *)(&Controller_implementation_P.DiscreteTimeIntegrator_IC), 15, 0, 6
  }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] Controller_implementation_dt.h */
