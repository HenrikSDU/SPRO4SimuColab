/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MotorWorking.c
 *
 * Code generated for Simulink model 'MotorWorking'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon May 27 17:09:21 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MotorWorking.h"
#include <math.h>
#include "rtwtypes.h"
#include "MotorWorking_private.h"
#include "MotorWorking_dt.h"

/* Block states (default storage) */
DW_MotorWorking_T MotorWorking_DW;

/* Real-time model */
static RT_MODEL_MotorWorking_T MotorWorking_M_;
RT_MODEL_MotorWorking_T *const MotorWorking_M = &MotorWorking_M_;

/* Model step function */
void MotorWorking_step(void)
{
  {
    real_T rtb_Switch1;

    /* Sin: '<Root>/Sine Wave' */
    if (MotorWorking_DW.systemEnable != 0) {
      rtb_Switch1 = MotorWorking_P.SineWave_Freq *
        ((MotorWorking_M->Timing.clockTick1) * 0.02);
      MotorWorking_DW.lastSin = sin(rtb_Switch1);
      MotorWorking_DW.lastCos = cos(rtb_Switch1);
      MotorWorking_DW.systemEnable = 0;
    }

    /* Switch: '<Root>/Switch1' incorporates:
     *  Clock: '<Root>/Clock1'
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Initial1'
     *  Constant: '<S1>/Constant'
     *  RelationalOperator: '<S1>/Compare'
     *  Sin: '<Root>/Sine Wave'
     *  Sum: '<Root>/Sum'
     */
    if (MotorWorking_M->Timing.t[0] <= MotorWorking_P.CompareToConstant1_const)
    {
      rtb_Switch1 = MotorWorking_P.Initial1_Value;
    } else {
      rtb_Switch1 = (((MotorWorking_DW.lastSin * MotorWorking_P.SineWave_PCos +
                       MotorWorking_DW.lastCos * MotorWorking_P.SineWave_PSin) *
                      MotorWorking_P.SineWave_HCos + (MotorWorking_DW.lastCos *
        MotorWorking_P.SineWave_PCos - MotorWorking_DW.lastSin *
        MotorWorking_P.SineWave_PSin) * MotorWorking_P.SineWave_Hsin) *
                     MotorWorking_P.SineWave_Amp + MotorWorking_P.SineWave_Bias)
        + MotorWorking_P.Constant_Value;
    }

    /* End of Switch: '<Root>/Switch1' */

    /* MATLABSystem: '<Root>/Servo Motor' */
    rc_servo_send_pulse_normalized(1, (rtb_Switch1 - 90.0) / 60.0);

    /* MATLABSystem: '<Root>/Servo Motor1' */
    rc_servo_send_pulse_normalized(2, (rtb_Switch1 - 90.0) / 60.0);

    /* MATLABSystem: '<Root>/Servo Motor2' */
    rc_servo_send_pulse_normalized(3, (rtb_Switch1 - 90.0) / 60.0);

    /* MATLABSystem: '<Root>/Servo Motor3' */
    rc_servo_send_pulse_normalized(4, (rtb_Switch1 - 90.0) / 60.0);
  }

  {
    real_T HoldSine;

    /* Update for Sin: '<Root>/Sine Wave' */
    HoldSine = MotorWorking_DW.lastSin;
    MotorWorking_DW.lastSin = MotorWorking_DW.lastSin *
      MotorWorking_P.SineWave_HCos + MotorWorking_DW.lastCos *
      MotorWorking_P.SineWave_Hsin;
    MotorWorking_DW.lastCos = MotorWorking_DW.lastCos *
      MotorWorking_P.SineWave_HCos - HoldSine * MotorWorking_P.SineWave_Hsin;
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, (real_T)MotorWorking_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.02s, 0.0s] */
    rtExtModeUpload(1, (real_T)((MotorWorking_M->Timing.clockTick1) * 0.02));
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(MotorWorking_M)!=-1) &&
        !((rtmGetTFinal(MotorWorking_M)-MotorWorking_M->Timing.t[0]) >
          MotorWorking_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(MotorWorking_M, "Simulation finished");
    }

    if (rtmGetStopRequested(MotorWorking_M)) {
      rtmSetErrorStatus(MotorWorking_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  MotorWorking_M->Timing.t[0] =
    ((time_T)(++MotorWorking_M->Timing.clockTick0)) *
    MotorWorking_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.02, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    MotorWorking_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void MotorWorking_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&MotorWorking_M->solverInfo,
                          &MotorWorking_M->Timing.simTimeStep);
    rtsiSetTPtr(&MotorWorking_M->solverInfo, &rtmGetTPtr(MotorWorking_M));
    rtsiSetStepSizePtr(&MotorWorking_M->solverInfo,
                       &MotorWorking_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&MotorWorking_M->solverInfo, (&rtmGetErrorStatus
      (MotorWorking_M)));
    rtsiSetRTModelPtr(&MotorWorking_M->solverInfo, MotorWorking_M);
  }

  rtsiSetSimTimeStep(&MotorWorking_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&MotorWorking_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&MotorWorking_M->solverInfo, false);
  rtsiSetSolverName(&MotorWorking_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(MotorWorking_M, &MotorWorking_M->Timing.tArray[0]);
  rtmSetTFinal(MotorWorking_M, -1);
  MotorWorking_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  MotorWorking_M->Sizes.checksums[0] = (2050144508U);
  MotorWorking_M->Sizes.checksums[1] = (862636658U);
  MotorWorking_M->Sizes.checksums[2] = (2748419980U);
  MotorWorking_M->Sizes.checksums[3] = (3574971U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    MotorWorking_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(MotorWorking_M->extModeInfo,
      &MotorWorking_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(MotorWorking_M->extModeInfo,
                        MotorWorking_M->Sizes.checksums);
    rteiSetTPtr(MotorWorking_M->extModeInfo, rtmGetTPtr(MotorWorking_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    MotorWorking_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<Root>/Servo Motor' */
  MotorWorking_DW.obj_g.matlabCodegenIsDeleted = false;
  MotorWorking_DW.obj_g.isInitialized = 1;
  MotorWorking_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Servo Motor1' */
  MotorWorking_DW.obj_h5.matlabCodegenIsDeleted = false;
  MotorWorking_DW.obj_h5.isInitialized = 1;
  MotorWorking_DW.obj_h5.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Servo Motor2' */
  MotorWorking_DW.obj_h.matlabCodegenIsDeleted = false;
  MotorWorking_DW.obj_h.isInitialized = 1;
  MotorWorking_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Servo Motor3' */
  MotorWorking_DW.obj.matlabCodegenIsDeleted = false;
  MotorWorking_DW.obj.isInitialized = 1;
  MotorWorking_DW.obj.isSetupComplete = true;

  /* Enable for Sin: '<Root>/Sine Wave' */
  MotorWorking_DW.systemEnable = 1;
}

/* Model terminate function */
void MotorWorking_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Servo Motor' */
  if (!MotorWorking_DW.obj_g.matlabCodegenIsDeleted) {
    MotorWorking_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((MotorWorking_DW.obj_g.isInitialized == 1) &&
        MotorWorking_DW.obj_g.isSetupComplete) {
      rc_servo_send_pulse_normalized(1, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Servo Motor' */

  /* Terminate for MATLABSystem: '<Root>/Servo Motor1' */
  if (!MotorWorking_DW.obj_h5.matlabCodegenIsDeleted) {
    MotorWorking_DW.obj_h5.matlabCodegenIsDeleted = true;
    if ((MotorWorking_DW.obj_h5.isInitialized == 1) &&
        MotorWorking_DW.obj_h5.isSetupComplete) {
      rc_servo_send_pulse_normalized(2, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Servo Motor1' */

  /* Terminate for MATLABSystem: '<Root>/Servo Motor2' */
  if (!MotorWorking_DW.obj_h.matlabCodegenIsDeleted) {
    MotorWorking_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((MotorWorking_DW.obj_h.isInitialized == 1) &&
        MotorWorking_DW.obj_h.isSetupComplete) {
      rc_servo_send_pulse_normalized(3, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Servo Motor2' */

  /* Terminate for MATLABSystem: '<Root>/Servo Motor3' */
  if (!MotorWorking_DW.obj.matlabCodegenIsDeleted) {
    MotorWorking_DW.obj.matlabCodegenIsDeleted = true;
    if ((MotorWorking_DW.obj.isInitialized == 1) &&
        MotorWorking_DW.obj.isSetupComplete) {
      rc_servo_send_pulse_normalized(4, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Servo Motor3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
