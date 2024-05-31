/* Include files */

#include "untitled1_cgxe.h"
#include "m_KSyYKg7FUdPkgGqKxrBY1D.h"
#include "m_K0sDCYisWLoONosTaTsLwE.h"
#include "m_qKSfSZXZWPHGlAZMQnGbwG.h"
#include "m_zwwNTCMWCBv9fj2J1ifTPH.h"

unsigned int cgxe_untitled1_method_dispatcher(SimStruct* S, int_T method, void
  * data)
{
  if (ssGetChecksum0(S) == 787184473 &&
      ssGetChecksum1(S) == 1846887133 &&
      ssGetChecksum2(S) == 283802050 &&
      ssGetChecksum3(S) == 372995362) {
    method_dispatcher_KSyYKg7FUdPkgGqKxrBY1D(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 972335248 &&
      ssGetChecksum1(S) == 832310734 &&
      ssGetChecksum2(S) == 137330586 &&
      ssGetChecksum3(S) == 421168437) {
    method_dispatcher_K0sDCYisWLoONosTaTsLwE(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1464607412 &&
      ssGetChecksum1(S) == 1382769335 &&
      ssGetChecksum2(S) == 1062112459 &&
      ssGetChecksum3(S) == 1646169528) {
    method_dispatcher_qKSfSZXZWPHGlAZMQnGbwG(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2056874202 &&
      ssGetChecksum1(S) == 1603169276 &&
      ssGetChecksum2(S) == 3850955300 &&
      ssGetChecksum3(S) == 3424564146) {
    method_dispatcher_zwwNTCMWCBv9fj2J1ifTPH(S, method, data);
    return 1;
  }

  return 0;
}
