#define S_FUNCTION_LEVEL               2
#define S_FUNCTION_NAME                MotorWorking_cgxe
#include "simstruc.h"
#include "MotorWorking_cgxe.h"
#define MDL_START

static void mdlStart(SimStruct* S)
{
  unsigned int success;
  success = cgxe_MotorWorking_method_dispatcher(S, SS_CALL_MDL_START, NULL);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }
}

#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  mexPrintf("ERROR: Calling model mdlInitializeConditions method directly.\n");
}

#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  mexPrintf("ERROR: Calling model mdlUpdate method directly.\n");
}

static void mdlOutputs(SimStruct* S, int_T tid)
{
  mexPrintf("ERROR: Calling model mdlOutputs method directly.\n");
}

static void mdlTerminate(SimStruct *S)
{
  mexPrintf("ERROR: Calling model mdlTerminate method directly.\n");
}

static void mdlInitializeSizes(SimStruct *S)
{
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
}

static mxArray* cgxe_get_supported_modules(void)
{
  mxArray* mxModules = mxCreateCellMatrix(4, 1);
  mxArray* mxChksum = NULL;
  uint32_T* checksumData = NULL;
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1242825737;
  checksumData[1] = 1957486664;
  checksumData[2] = 1023472015;
  checksumData[3] = 3225921124;
  mxSetCell(mxModules, 0, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3850330985;
  checksumData[1] = 2530738285;
  checksumData[2] = 3272486770;
  checksumData[3] = 1577317180;
  mxSetCell(mxModules, 1, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 4094220946;
  checksumData[1] = 205389497;
  checksumData[2] = 3328263072;
  checksumData[3] = 1286763140;
  mxSetCell(mxModules, 2, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 4119192743;
  checksumData[1] = 597865442;
  checksumData[2] = 3900754408;
  checksumData[3] = 1162886962;
  mxSetCell(mxModules, 3, mxChksum);
  return mxModules;
}

static int cgxe_process_get_checksums(int nlhs, mxArray* plhs[], int nrhs, const
  mxArray* prhs[])
{
  const char* checksumFields[] = { "modules", "model", "makefile", "target",
    "overall" };

  mxArray* mxChecksum = mxCreateStructMatrix(1, 1, 5, checksumFields);
  mxSetField(mxChecksum, 0, "modules", cgxe_get_supported_modules());

  {
    mxArray* mxModelChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxModelChksum);
    checksumData[0] = 760421926;
    checksumData[1] = 4006056387;
    checksumData[2] = 3422878040;
    checksumData[3] = 3335524000;
    mxSetField(mxChecksum, 0, "model", mxModelChksum);
  }

  {
    mxArray* mxMakefileChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxMakefileChksum);
    checksumData[0] = 4091305763;
    checksumData[1] = 2008808526;
    checksumData[2] = 367612842;
    checksumData[3] = 3761837735;
    mxSetField(mxChecksum, 0, "makefile", mxMakefileChksum);
  }

  {
    mxArray* mxTargetChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxTargetChksum);
    checksumData[0] = 2911221907;
    checksumData[1] = 2308967934;
    checksumData[2] = 2419390157;
    checksumData[3] = 1906300239;
    mxSetField(mxChecksum, 0, "target", mxTargetChksum);
  }

  {
    mxArray* mxOverallChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxOverallChksum);
    checksumData[0] = 2627374930;
    checksumData[1] = 3826603412;
    checksumData[2] = 235761837;
    checksumData[3] = 3194683655;
    mxSetField(mxChecksum, 0, "overall", mxOverallChksum);
  }

  plhs[0] = mxChecksum;
  return 1;
}

static int cgxe_mex_unlock_call(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  while (mexIsLocked()) {
    mexUnlock();
  }

  return 1;
}

static SimStruct* cgxe_unpack_simstruct(const mxArray *mxS)
{
  uint32_T *uintPtr = (uint32_T*)malloc(sizeof(SimStruct*));
  int nEl = sizeof(SimStruct*)/sizeof(uint32_T);
  uint32_T *uintDataPtr = (uint32_T *)mxGetData(mxS);
  int el;
  SimStruct *S;
  for (el=0; el < nEl; el++) {
    uintPtr[el] = uintDataPtr[el];
  }

  memcpy(&S,uintPtr,sizeof(SimStruct*));
  free(uintPtr);
  return S;
}

static int cgxe_get_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_MotorWorking_method_dispatcher(S, SS_CALL_MDL_GET_SIM_STATE,
    (void *) (plhs));
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_set_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_MotorWorking_method_dispatcher(S, SS_CALL_MDL_SET_SIM_STATE,
    (void *) prhs[2]);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_get_BuildInfoUpdate(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(tpChksum, "dYZZzNbePGHHoKucqxRynD") == 0) {
    extern mxArray *cgxe_dYZZzNbePGHHoKucqxRynD_BuildInfoUpdate(void);
    plhs[0] = cgxe_dYZZzNbePGHHoKucqxRynD_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "mGg5kldJFMUqqcMFYTCXk") == 0) {
    extern mxArray *cgxe_mGg5kldJFMUqqcMFYTCXk_BuildInfoUpdate(void);
    plhs[0] = cgxe_mGg5kldJFMUqqcMFYTCXk_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "vhCIMhSDxW7vJ4zd5fVmYF") == 0) {
    extern mxArray *cgxe_vhCIMhSDxW7vJ4zd5fVmYF_BuildInfoUpdate(void);
    plhs[0] = cgxe_vhCIMhSDxW7vJ4zd5fVmYF_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "mbrvObo7hU5hfZxNeR1UkC") == 0) {
    extern mxArray *cgxe_mbrvObo7hU5hfZxNeR1UkC_BuildInfoUpdate(void);
    plhs[0] = cgxe_mbrvObo7hU5hfZxNeR1UkC_BuildInfoUpdate();
    return 1;
  }

  return 0;
}

static int cgxe_get_fallback_info(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(tpChksum, "dYZZzNbePGHHoKucqxRynD") == 0) {
    extern mxArray *cgxe_dYZZzNbePGHHoKucqxRynD_fallback_info(void);
    plhs[0] = cgxe_dYZZzNbePGHHoKucqxRynD_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "mGg5kldJFMUqqcMFYTCXk") == 0) {
    extern mxArray *cgxe_mGg5kldJFMUqqcMFYTCXk_fallback_info(void);
    plhs[0] = cgxe_mGg5kldJFMUqqcMFYTCXk_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "vhCIMhSDxW7vJ4zd5fVmYF") == 0) {
    extern mxArray *cgxe_vhCIMhSDxW7vJ4zd5fVmYF_fallback_info(void);
    plhs[0] = cgxe_vhCIMhSDxW7vJ4zd5fVmYF_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "mbrvObo7hU5hfZxNeR1UkC") == 0) {
    extern mxArray *cgxe_mbrvObo7hU5hfZxNeR1UkC_fallback_info(void);
    plhs[0] = cgxe_mbrvObo7hU5hfZxNeR1UkC_fallback_info();
    return 1;
  }

  return 0;
}

#define PROCESS_MEX_SFUNCTION_CMD_LINE_CALL

static int ProcessMexSfunctionCmdLineCall(int nlhs, mxArray* plhs[], int nrhs,
  const mxArray* prhs[])
{
  char commandName[64];
  if (nrhs < 1 || !mxIsChar(prhs[0]))
    return 0;
  mxGetString(prhs[0], commandName, sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName, "get_checksums") == 0) {
    return cgxe_process_get_checksums(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "mex_unlock") == 0) {
    return cgxe_mex_unlock_call(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_sim_state") == 0) {
    return cgxe_get_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "set_sim_state") == 0) {
    return cgxe_set_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_BuildInfoUpdate") == 0) {
    return cgxe_get_BuildInfoUpdate(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_fallback_info") == 0) {
    return cgxe_get_fallback_info(nlhs, plhs, nrhs, prhs);
  }

  return 0;
}

#include "simulink.c"
