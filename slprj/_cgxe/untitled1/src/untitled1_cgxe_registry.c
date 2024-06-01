#define S_FUNCTION_LEVEL               2
#define S_FUNCTION_NAME                untitled1_cgxe
#include "simstruc.h"
#include "untitled1_cgxe.h"
#define MDL_START

static void mdlStart(SimStruct* S)
{
  unsigned int success;
  success = cgxe_untitled1_method_dispatcher(S, SS_CALL_MDL_START, NULL);
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
  checksumData[0] = 787184473;
  checksumData[1] = 1846887133;
  checksumData[2] = 283802050;
  checksumData[3] = 372995362;
  mxSetCell(mxModules, 0, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 972335248;
  checksumData[1] = 832310734;
  checksumData[2] = 137330586;
  checksumData[3] = 421168437;
  mxSetCell(mxModules, 1, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1464607412;
  checksumData[1] = 1382769335;
  checksumData[2] = 1062112459;
  checksumData[3] = 1646169528;
  mxSetCell(mxModules, 2, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2056874202;
  checksumData[1] = 1603169276;
  checksumData[2] = 3850955300;
  checksumData[3] = 3424564146;
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
    checksumData[0] = 462295020;
    checksumData[1] = 3392677503;
    checksumData[2] = 3266202981;
    checksumData[3] = 1960041265;
    mxSetField(mxChecksum, 0, "model", mxModelChksum);
  }

  {
    mxArray* mxMakefileChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxMakefileChksum);
    checksumData[0] = 396432642;
    checksumData[1] = 2221221456;
    checksumData[2] = 804354158;
    checksumData[3] = 3927177495;
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
    checksumData[0] = 1495812816;
    checksumData[1] = 2265832211;
    checksumData[2] = 118271785;
    checksumData[3] = 2499075531;
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
  success = cgxe_untitled1_method_dispatcher(S, SS_CALL_MDL_GET_SIM_STATE, (void
    *) (plhs));
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
  success = cgxe_untitled1_method_dispatcher(S, SS_CALL_MDL_SET_SIM_STATE, (void
    *) prhs[2]);
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
  if (strcmp(tpChksum, "KSyYKg7FUdPkgGqKxrBY1D") == 0) {
    extern mxArray *cgxe_KSyYKg7FUdPkgGqKxrBY1D_BuildInfoUpdate(void);
    plhs[0] = cgxe_KSyYKg7FUdPkgGqKxrBY1D_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "K0sDCYisWLoONosTaTsLwE") == 0) {
    extern mxArray *cgxe_K0sDCYisWLoONosTaTsLwE_BuildInfoUpdate(void);
    plhs[0] = cgxe_K0sDCYisWLoONosTaTsLwE_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "qKSfSZXZWPHGlAZMQnGbwG") == 0) {
    extern mxArray *cgxe_qKSfSZXZWPHGlAZMQnGbwG_BuildInfoUpdate(void);
    plhs[0] = cgxe_qKSfSZXZWPHGlAZMQnGbwG_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "zwwNTCMWCBv9fj2J1ifTPH") == 0) {
    extern mxArray *cgxe_zwwNTCMWCBv9fj2J1ifTPH_BuildInfoUpdate(void);
    plhs[0] = cgxe_zwwNTCMWCBv9fj2J1ifTPH_BuildInfoUpdate();
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
  if (strcmp(tpChksum, "KSyYKg7FUdPkgGqKxrBY1D") == 0) {
    extern mxArray *cgxe_KSyYKg7FUdPkgGqKxrBY1D_fallback_info(void);
    plhs[0] = cgxe_KSyYKg7FUdPkgGqKxrBY1D_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "K0sDCYisWLoONosTaTsLwE") == 0) {
    extern mxArray *cgxe_K0sDCYisWLoONosTaTsLwE_fallback_info(void);
    plhs[0] = cgxe_K0sDCYisWLoONosTaTsLwE_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "qKSfSZXZWPHGlAZMQnGbwG") == 0) {
    extern mxArray *cgxe_qKSfSZXZWPHGlAZMQnGbwG_fallback_info(void);
    plhs[0] = cgxe_qKSfSZXZWPHGlAZMQnGbwG_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "zwwNTCMWCBv9fj2J1ifTPH") == 0) {
    extern mxArray *cgxe_zwwNTCMWCBv9fj2J1ifTPH_fallback_info(void);
    plhs[0] = cgxe_zwwNTCMWCBv9fj2J1ifTPH_fallback_info();
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
