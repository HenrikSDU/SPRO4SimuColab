/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include <stdio.h>
#include <stdlib.h>
#include "Ultrasonic.h"
#include "Ultrasonic_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "ext_work.h"
#include "MW_bbblue_init.h"
#include "linuxinitialize.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(Ultrasonic_M) == (NULL)) && !rtmGetStopRequested
    (Ultrasonic_M);
  while (runModel) {
    sem_wait(&baserateTaskSem);

    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModePauseIfNeeded(Ultrasonic_M->extModeInfo, 2, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(Ultrasonic_M, true);
      }

      if (rtmGetStopRequested(Ultrasonic_M) == true) {
        rtmSetErrorStatus(Ultrasonic_M, "Simulation finished");
        break;
      }
    }

    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(Ultrasonic_M->extModeInfo, 2, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(Ultrasonic_M, true);
      }
    }

    Ultrasonic_step();

    /* Get model outputs here */
    rtExtModeCheckEndTrigger();
    stopRequested = !((rtmGetErrorStatus(Ultrasonic_M) == (NULL)) &&
                      !rtmGetStopRequested(Ultrasonic_M));
    runModel = !stopRequested;
  }

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(Ultrasonic_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  MW_bbblue_terminate();

  /* Terminate model */
  Ultrasonic_terminate();
  rtExtModeShutdown(2);
  sem_post(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  MW_bbblue_init();
  rtmSetErrorStatus(Ultrasonic_M, 0);
  rtExtModeParseArgs(argc, (const char_T **)argv, NULL);

  /* Initialize model */
  Ultrasonic_initialize();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(Ultrasonic_M));
  rtExtModeCheckInit(2);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(Ultrasonic_M->extModeInfo, 2, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(Ultrasonic_M, true);
    }
  }

  rtERTExtModeStartMsg();

  /* Call RTOS Initialization function */
  myRTOSInit(0.0001, 0);

  /* Wait for stop semaphore */
  sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(sem_destroy(&timerTaskSem[i]), 0, "sem_destroy");
    }
  }

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
