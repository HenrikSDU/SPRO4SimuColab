/*
 * DroneModel_private.h
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

#ifndef RTW_HEADER_DroneModel_private_h_
#define RTW_HEADER_DroneModel_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "DroneModel_types.h"
#include "DroneModel.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_roundd_snf(real_T u);
extern void sMultiWord2sMultiWordSat(const uint32_T u1[], int32_T n1, uint32_T
  y[], int32_T n);
extern void MultiWordSub(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
  int32_T n);
extern void sMultiWord2MultiWord(const uint32_T u1[], int32_T n1, uint32_T y[],
  int32_T n);
extern void MultiWordAdd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
  int32_T n);
extern void sMultiWordShr(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T
  y[], int32_T n);
extern void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[],
  int32_T n2, uint32_T y[], int32_T n);
extern void sLong2MultiWord(int32_T u, uint32_T y[], int32_T n);
extern void sMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T
  y[], int32_T n);
extern void uLong2MultiWord(uint32_T u, uint32_T y[], int32_T n);
extern boolean_T sMultiWordEq(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern int32_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n);
extern real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1);
extern boolean_T sMultiWordLt(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern boolean_T sMultiWordGe(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern boolean_T sMultiWordGt(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern void MultiWordNeg(const uint32_T u1[], uint32_T y[], int32_T n);
extern boolean_T uMultiWordEq(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern int32_T uMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n);
extern void Double2MultiWord(real_T u1, uint32_T y[], int32_T n);
extern boolean_T uMultiWordGt(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern void uMultiWordShr(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T
  y[], int32_T n);
extern void uMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T
  y[], int32_T n);
extern void MultiWordAnd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
  int32_T n);
extern boolean_T uMultiWordGe(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern boolean_T uMultiWordNe(const uint32_T u1[], const uint32_T u2[], int32_T
  n);
extern void uMultiWordDivZero(const uint32_T u1[], int32_T n1, const uint32_T
  u2[], int32_T n2, uint32_T y1[], int32_T m1, uint32_T y2[], int32_T m2,
  uint32_T t1[], int32_T l1, uint32_T t2[], int32_T l2);
extern void uMultiWord2MultiWord(const uint32_T u1[], int32_T n1, uint32_T y[],
  int32_T n);
extern void MultiWordSetUnsignedMax(uint32_T y[], int32_T n);
extern int32_T uMultiWordDiv(uint32_T a[], int32_T na, uint32_T b[], int32_T nb,
  uint32_T q[], int32_T nq, uint32_T r[], int32_T nr);
extern void uMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[],
  int32_T n2, uint32_T y[], int32_T n);
extern boolean_T uMultiWordLe(const uint32_T u1[], const uint32_T u2[], int32_T
  n);

/* private model entry point functions */
extern void DroneModel_derivatives(void);

#endif                                 /* RTW_HEADER_DroneModel_private_h_ */