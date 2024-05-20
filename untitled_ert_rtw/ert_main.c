/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
<<<<<<< Updated upstream
 * C/C++ source code generated on : Mon May 20 11:12:51 2024
=======
 * C/C++ source code generated on : Sun May 19 15:03:49 2024
>>>>>>> Stashed changes
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdio.h>
#include <stdlib.h>
#include "untitled.h"
#include "untitled_private.h"
#include "rtwtypes.h"
#include "limits.h"
<<<<<<< Updated upstream
#include "rt_nonfinite.h"
=======
>>>>>>> Stashed changes
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
  runModel = (rtmGetErrorStatus(untitled_M) == (NULL)) && !rtmGetStopRequested
    (untitled_M);
  while (runModel) {
    sem_wait(&baserateTaskSem);

    /* External mode */
    {
      boolean_T rtmStopReq = false;
<<<<<<< Updated upstream
      rtExtModePauseIfNeeded(untitled_M->extModeInfo, 2, &rtmStopReq);
=======
      rtExtModePauseIfNeeded(untitled_M->extModeInfo, 1, &rtmStopReq);
>>>>>>> Stashed changes
      if (rtmStopReq) {
        rtmSetStopRequested(untitled_M, true);
      }

      if (rtmGetStopRequested(untitled_M) == true) {
        rtmSetErrorStatus(untitled_M, "Simulation finished");
        break;
      }
    }

    /* External mode */
    {
      boolean_T rtmStopReq = false;
<<<<<<< Updated upstream
      rtExtModeOneStep(untitled_M->extModeInfo, 2, &rtmStopReq);
=======
      rtExtModeOneStep(untitled_M->extModeInfo, 1, &rtmStopReq);
>>>>>>> Stashed changes
      if (rtmStopReq) {
        rtmSetStopRequested(untitled_M, true);
      }
    }

    untitled_step();

    /* Get model outputs here */
    rtExtModeCheckEndTrigger();
    stopRequested = !((rtmGetErrorStatus(untitled_M) == (NULL)) &&
                      !rtmGetStopRequested(untitled_M));
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
  rtmSetErrorStatus(untitled_M, "stopping the model");
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
  untitled_terminate();
<<<<<<< Updated upstream
  rtExtModeShutdown(2);
=======
  rtExtModeShutdown(1);
>>>>>>> Stashed changes
  sem_post(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  MW_bbblue_init();
  rtmSetErrorStatus(untitled_M, 0);
  rtExtModeParseArgs(argc, (const char_T **)argv, NULL);

  /* Initialize model */
  untitled_initialize();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(untitled_M));
<<<<<<< Updated upstream
  rtExtModeCheckInit(2);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(untitled_M->extModeInfo, 2, &rtmStopReq);
=======
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(untitled_M->extModeInfo, 1, &rtmStopReq);
>>>>>>> Stashed changes
    if (rtmStopReq) {
      rtmSetStopRequested(untitled_M, true);
    }
  }

  rtERTExtModeStartMsg();

  /* Call RTOS Initialization function */
  myRTOSInit(0.1, 0);

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
