/* Include files */

#include "MotorWorking_cgxe.h"
#include "m_bg50hRmc6UAsemHLG3AoeE.h"
#include "m_dYZZzNbePGHHoKucqxRynD.h"
#include "m_mGg5kldJFMUqqcMFYTCXk.h"
#include "m_vhCIMhSDxW7vJ4zd5fVmYF.h"

unsigned int cgxe_MotorWorking_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 408886430 &&
      ssGetChecksum1(S) == 2425695206 &&
      ssGetChecksum2(S) == 24992230 &&
      ssGetChecksum3(S) == 889795311) {
    method_dispatcher_bg50hRmc6UAsemHLG3AoeE(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1242825737 &&
      ssGetChecksum1(S) == 1957486664 &&
      ssGetChecksum2(S) == 1023472015 &&
      ssGetChecksum3(S) == 3225921124) {
    method_dispatcher_dYZZzNbePGHHoKucqxRynD(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3850330985 &&
      ssGetChecksum1(S) == 2530738285 &&
      ssGetChecksum2(S) == 3272486770 &&
      ssGetChecksum3(S) == 1577317180) {
    method_dispatcher_mGg5kldJFMUqqcMFYTCXk(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 4094220946 &&
      ssGetChecksum1(S) == 205389497 &&
      ssGetChecksum2(S) == 3328263072 &&
      ssGetChecksum3(S) == 1286763140) {
    method_dispatcher_vhCIMhSDxW7vJ4zd5fVmYF(S, method, data);
    return 1;
  }

  return 0;
}
