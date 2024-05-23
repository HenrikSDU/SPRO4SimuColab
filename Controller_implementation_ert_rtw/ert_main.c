/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'Controller_implementation'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu May 23 13:33:11 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller_implementation.h"
#include "Controller_implementation_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
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
  runModel = (rtmGetErrorStatus(Controller_implementation_M) == (NULL)) &&
    !rtmGetStopRequested(Controller_implementation_M);
  while (runModel) {
    sem_wait(&baserateTaskSem);

    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModePauseIfNeeded(Controller_implementation_M->extModeInfo, 1,
        &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(Controller_implementation_M, true);
      }

      if (rtmGetStopRequested(Controller_implementation_M) == true) {
        rtmSetErrorStatus(Controller_implementation_M, "Simulation finished");
        break;
      }
    }

    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(Controller_implementation_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(Controller_implementation_M, true);
      }
    }

    Controller_implementation_step();

    /* Get model outputs here */
    rtExtModeCheckEndTrigger();
    stopRequested = !((rtmGetErrorStatus(Controller_implementation_M) == (NULL))
                      && !rtmGetStopRequested(Controller_implementation_M));
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
  rtmSetErrorStatus(Controller_implementation_M, "stopping the model");
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
  Controller_implementation_terminate();
  rtExtModeShutdown(1);
  sem_post(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  MW_bbblue_init();
  rtmSetErrorStatus(Controller_implementation_M, 0);
  rtExtModeParseArgs(argc, (const char_T **)argv, NULL);

  /* Initialize model */
  Controller_implementation_initialize();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(Controller_implementation_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(Controller_implementation_M->extModeInfo, 1,
      &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(Controller_implementation_M, true);
    }
  }

  rtERTExtModeStartMsg();

  /* Call RTOS Initialization function */
  myRTOSInit(0.01, 0);

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
