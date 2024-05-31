/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Controller_implementation.c
 *
 * Code generated for Simulink model 'Controller_implementation'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu May 30 19:42:55 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Controller_implementation.h"
#include "Controller_implementation_types.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include <math.h>
#include "Controller_implementation_private.h"
#include <string.h>
#include <stddef.h>
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#include "rt_defines.h"
#include "Controller_implementation_dt.h"

/* Block signals (default storage) */
B_Controller_implementation_T Controller_implementation_B;

/* Block states (default storage) */
DW_Controller_implementation_T Controller_implementation_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Controller_implementa_T Controller_implementati_PrevZCX;

/* Real-time model */
static RT_MODEL_Controller_implement_T Controller_implementation_M_;
RT_MODEL_Controller_implement_T *const Controller_implementation_M =
  &Controller_implementation_M_;

/* Forward declaration for local functions */
static void bbblueBarometer_BMP_ReadRegiste(const
  beagleboneblue_bbblueBaromete_T *obj, uint8_T RegisterValue[6], uint8_T
  *varargout_1);
static int64m_T Controller_implementati_i64ddiv(real_T x, const int64m_T y);
static uint64m_T Controller_eml_mixed_uint64_mul(const uint64m_T nv, real_T y);
static int64m_T Controller_implementation_times(real_T x, const int64m_T y);
static real_T Contro_bbblueBarometer_stepImpl(const
  beagleboneblue_bbblueBaromete_T *obj);
static beagleboneblue_bbblueBaromete_T *bbblueBarometer_bbblueBarometer
  (beagleboneblue_bbblueBaromete_T *obj);
static void Controller_imp_SystemCore_setup(beagleboneblue_bbblueBaromete_T *obj);
static void Controller__SystemCore_setup_p5(dsp_simulink_MovingAverage_Co_T *obj);
static void Controller_i_SystemCore_setup_p(beagleboneblue_bbblueMPU9250__T *obj);
static void rate_monotonic_scheduler(void);
void sMultiWord2sMultiWordSat(const uint32_T u1[], int32_T n1, uint32_T y[],
  int32_T n)
{
  int32_T i;
  int32_T nm1;
  uint32_T ys;
  boolean_T doSaturation = false;
  nm1 = n - 1;
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  if (n1 > n) {
    doSaturation = (((u1[n1 - 1] ^ u1[n - 1]) & 2147483648U) != 0U);
    i = n1 - 1;
    while ((!doSaturation) && (i >= n)) {
      doSaturation = (u1[i] != ys);
      i--;
    }
  }

  if (doSaturation) {
    ys = ~ys;
    for (i = 0; i < nm1; i++) {
      y[i] = ys;
    }

    y[i] = ys ^ 2147483648U;
  } else {
    nm1 = n1 < n ? n1 : n;
    for (i = 0; i < nm1; i++) {
      y[i] = u1[i];
    }

    while (i < n) {
      y[i] = ys;
      i++;
    }
  }
}

void MultiWordSub(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int32_T n)
{
  int32_T i;
  uint32_T borrow = 0U;
  uint32_T u1i;
  uint32_T yi;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i - u2[i]) - borrow;
    y[i] = yi;
    borrow = borrow != 0U ? (uint32_T)(yi >= u1i) : (uint32_T)(yi > u1i);
  }
}

void sMultiWord2MultiWord(const uint32_T u1[], int32_T n1, uint32_T y[], int32_T
  n)
{
  int32_T i;
  int32_T nm;
  uint32_T u1i;
  nm = n1 < n ? n1 : n;
  for (i = 0; i < nm; i++) {
    y[i] = u1[i];
  }

  if (n > n1) {
    u1i = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
    for (i = nm; i < n; i++) {
      y[i] = u1i;
    }
  }
}

void MultiWordAdd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int32_T n)
{
  int32_T i;
  uint32_T carry = 0U;
  uint32_T u1i;
  uint32_T yi;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i + u2[i]) + carry;
    y[i] = yi;
    carry = carry != 0U ? (uint32_T)(yi <= u1i) : (uint32_T)(yi < u1i);
  }
}

void sMultiWordShr(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T i;
  int32_T i1;
  int32_T nb;
  int32_T nc;
  uint32_T nr;
  uint32_T u1i;
  uint32_T yi;
  uint32_T ys;
  nb = (int32_T)(n2 >> 5);
  i = 0;
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint32_T)nb << 5);
    if (nr > 0U) {
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << (32U - nr) | yi;
        i++;
      }

      y[i] = (nc < n1 ? u1[nc] : ys) << (32U - nr) | u1i >> nr;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T ni;
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T cb1;
  uint32_T cb2;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  boolean_T isNegative1;
  boolean_T isNegative2;
  isNegative1 = ((u1[n1 - 1] & 2147483648U) != 0U);
  isNegative2 = ((u2[n2 - 1] & 2147483648U) != 0U);
  cb1 = 1U;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    cb2 = 1U;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1U;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

void sLong2MultiWord(int32_T u, uint32_T y[], int32_T n)
{
  int32_T i;
  uint32_T yi;
  y[0] = (uint32_T)u;
  yi = u < 0 ? MAX_uint32_T : 0U;
  for (i = 1; i < n; i++) {
    y[i] = yi;
  }
}

void sMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T i;
  int32_T nb;
  int32_T nc;
  uint32_T nl;
  uint32_T u1i;
  uint32_T yi;
  uint32_T ys;
  nb = (int32_T)(n2 >> 5);
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  nc = nb > n ? n : nb;
  u1i = 0U;
  for (i = 0; i < nc; i++) {
    y[i] = 0U;
  }

  if (nb < n) {
    nl = n2 - ((uint32_T)nb << 5);
    nb += n1;
    if (nb > n) {
      nb = n;
    }

    nb -= i;
    if (nl > 0U) {
      for (nc = 0; nc < nb; nc++) {
        yi = u1i >> (32U - nl);
        u1i = u1[nc];
        y[i] = u1i << nl | yi;
        i++;
      }

      if (i < n) {
        y[i] = u1i >> (32U - nl) | ys << nl;
        i++;
      }
    } else {
      for (nc = 0; nc < nb; nc++) {
        y[i] = u1[nc];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void uLong2MultiWord(uint32_T u, uint32_T y[], int32_T n)
{
  int32_T i;
  y[0] = u;
  for (i = 1; i < n; i++) {
    y[i] = 0U;
  }
}

boolean_T sMultiWordEq(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return sMultiWordCmp(u1, u2, n) == 0;
}

int32_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  int32_T i;
  int32_T y;
  uint32_T su1;
  uint32_T u2i;
  su1 = u1[n - 1] & 2147483648U;
  if ((u2[n - 1] & 2147483648U) != su1) {
    y = su1 != 0U ? -1 : 1;
  } else {
    y = 0;
    i = n;
    while ((y == 0) && (i > 0)) {
      i--;
      su1 = u1[i];
      u2i = u2[i];
      if (su1 != u2i) {
        y = su1 > u2i ? 1 : -1;
      }
    }
  }

  return y;
}

real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T exp_0;
  int32_T i;
  uint32_T cb;
  uint32_T u1i;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

boolean_T sMultiWordLt(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return sMultiWordCmp(u1, u2, n) < 0;
}

boolean_T sMultiWordGt(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return sMultiWordCmp(u1, u2, n) > 0;
}

void MultiWordNeg(const uint32_T u1[], uint32_T y[], int32_T n)
{
  int32_T i;
  uint32_T carry = 1U;
  uint32_T yi;
  for (i = 0; i < n; i++) {
    yi = ~u1[i] + carry;
    y[i] = yi;
    carry = (uint32_T)(yi < carry);
  }
}

boolean_T uMultiWordEq(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return uMultiWordCmp(u1, u2, n) == 0;
}

int32_T uMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  int32_T i;
  int32_T y;
  uint32_T u1i;
  uint32_T u2i;
  y = 0;
  i = n;
  while ((y == 0) && (i > 0)) {
    i--;
    u1i = u1[i];
    u2i = u2[i];
    if (u1i != u2i) {
      y = u1i > u2i ? 1 : -1;
    }
  }

  return y;
}

void Double2MultiWord(real_T u1, uint32_T y[], int32_T n)
{
  real_T yd;
  real_T yn;
  int32_T currExp;
  int32_T i;
  int32_T msl;
  int32_T prevExp;
  uint32_T cb;
  uint32_T u1i;
  boolean_T isNegative;
  isNegative = (u1 < 0.0);
  yn = frexp(u1, &currExp);
  msl = currExp <= 0 ? -1 : (currExp - 1) / 32;
  cb = 1U;
  for (i = msl + 1; i < n; i++) {
    y[i] = 0U;
  }

  yn = isNegative ? -yn : yn;
  prevExp = msl << 5;
  for (i = msl; i >= 0; i--) {
    yn = ldexp(yn, currExp - prevExp);
    yd = floor(yn);
    yn -= yd;
    if (i < n) {
      y[i] = (uint32_T)yd;
    }

    currExp = prevExp;
    prevExp -= 32;
  }

  if (isNegative) {
    for (i = 0; i < n; i++) {
      u1i = ~y[i];
      cb += u1i;
      y[i] = cb;
      cb = (uint32_T)(cb < u1i);
    }
  }
}

boolean_T uMultiWordLe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return uMultiWordCmp(u1, u2, n) <= 0;
}

void uMultiWordShr(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T i;
  int32_T i1;
  int32_T nb;
  int32_T nc;
  uint32_T nr;
  uint32_T u1i;
  uint32_T yi;
  nb = (int32_T)(n2 >> 5);
  i = 0;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint32_T)nb << 5);
    if (nr > 0U) {
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << (32U - nr) | yi;
        i++;
      }

      yi = u1i >> nr;
      if (nc < n1) {
        yi |= u1[nc] << (32U - nr);
      }

      y[i] = yi;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = 0U;
    i++;
  }
}

void uMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T i;
  int32_T nb;
  int32_T nc;
  uint32_T nl;
  uint32_T u1i;
  uint32_T yi;
  uint32_T ys;
  nb = (int32_T)(n2 >> 5);
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? MAX_uint32_T : 0U;
  nc = nb > n ? n : nb;
  u1i = 0U;
  for (i = 0; i < nc; i++) {
    y[i] = 0U;
  }

  if (nb < n) {
    nl = n2 - ((uint32_T)nb << 5);
    nb += n1;
    if (nb > n) {
      nb = n;
    }

    nb -= i;
    if (nl > 0U) {
      for (nc = 0; nc < nb; nc++) {
        yi = u1i >> (32U - nl);
        u1i = u1[nc];
        y[i] = u1i << nl | yi;
        i++;
      }

      if (i < n) {
        y[i] = u1i >> (32U - nl) | ys << nl;
        i++;
      }
    } else {
      for (nc = 0; nc < nb; nc++) {
        y[i] = u1[nc];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void MultiWordAnd(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int32_T n)
{
  int32_T i;
  for (i = 0; i < n; i++) {
    y[i] = u1[i] & u2[i];
  }
}

boolean_T uMultiWordGe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return uMultiWordCmp(u1, u2, n) >= 0;
}

boolean_T uMultiWordNe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return uMultiWordCmp(u1, u2, n) != 0;
}

boolean_T uMultiWordGt(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return uMultiWordCmp(u1, u2, n) > 0;
}

void uMultiWordDivZero(const uint32_T u1[], int32_T n1, const uint32_T u2[],
  int32_T n2, uint32_T y1[], int32_T m1, uint32_T y2[], int32_T m2, uint32_T t1[],
  int32_T l1, uint32_T t2[], int32_T l2)
{
  uMultiWord2MultiWord(u1, n1, t1, l1);
  uMultiWord2MultiWord(u2, n2, t2, l2);
  if (uMultiWordDiv(t1, l1, t2, l2, y1, m1, y2, m2) < 0) {
    MultiWordSetUnsignedMax(y1, m1);
  }
}

void uMultiWord2MultiWord(const uint32_T u1[], int32_T n1, uint32_T y[], int32_T
  n)
{
  int32_T i;
  int32_T nm;
  nm = n1 < n ? n1 : n;
  for (i = 0; i < nm; i++) {
    y[i] = u1[i];
  }

  if (n > n1) {
    for (i = nm; i < n; i++) {
      y[i] = 0U;
    }
  }
}

void MultiWordSetUnsignedMax(uint32_T y[], int32_T n)
{
  int32_T i;
  for (i = 0; i < n; i++) {
    y[i] = MAX_uint32_T;
  }
}

int32_T uMultiWordDiv(uint32_T a[], int32_T na, uint32_T b[], int32_T nb,
                      uint32_T q[], int32_T nq, uint32_T r[], int32_T nr)
{
  int32_T ka;
  int32_T kr;
  int32_T na1;
  int32_T nb1;
  int32_T nza;
  int32_T nzb;
  int32_T tpi;
  int32_T y;
  uint32_T ak;
  uint32_T bk;
  uint32_T kba;
  uint32_T kbb;
  uint32_T mask;
  uint32_T nba;
  uint32_T nbb;
  uint32_T nbq;
  uint32_T t;
  uint32_T tnb;
  nzb = nb;
  tpi = nb - 1;
  while ((nzb > 0) && (b[tpi] == 0U)) {
    nzb--;
    tpi--;
  }

  if (nzb > 0) {
    nza = na;
    for (tpi = 0; tpi < nq; tpi++) {
      q[tpi] = 0U;
    }

    tpi = na - 1;
    while ((nza > 0) && (a[tpi] == 0U)) {
      nza--;
      tpi--;
    }

    if ((nza > 0) && (nza >= nzb)) {
      nb1 = nzb - 1;
      na1 = nza - 1;
      for (kr = 0; kr < nr; kr++) {
        r[kr] = 0U;
      }

      /* Quick return if dividend and divisor fit into single word. */
      if (nza == 1) {
        ak = a[0];
        bk = b[0];
        nbq = ak / bk;
        q[0] = nbq;
        r[0] = ak - nbq * bk;
        y = 7;
      } else {
        /* Remove leading zeros from both, dividend and divisor. */
        kbb = 1U;
        t = b[nzb - 1] >> 1U;
        while (t != 0U) {
          kbb++;
          t >>= 1U;
        }

        kba = 1U;
        t = a[nza - 1] >> 1U;
        while (t != 0U) {
          kba++;
          t >>= 1U;
        }

        /* Quick return if quotient is zero. */
        if ((nza > nzb) || (kba >= kbb)) {
          nba = ((uint32_T)(nza - 1) << 5) + kba;
          nbb = ((uint32_T)(nzb - 1) << 5) + kbb;

          /* Normalize b. */
          if (kbb != 32U) {
            bk = b[nzb - 1];
            for (kr = nzb - 1; kr > 0; kr--) {
              t = bk << (32U - kbb);
              bk = b[kr - 1];
              t |= bk >> kbb;
              b[kr] = t;
            }

            b[kr] = bk << (32U - kbb);
            mask = ~((1U << (32U - kbb)) - 1U);
          } else {
            mask = MAX_uint32_T;
          }

          /* Initialize quotient to zero. */
          tnb = 0U;
          y = 0;

          /* Until exit conditions have been met, do */
          do {
            /* Normalize a */
            if (kba != 32U) {
              tnb = (tnb - kba) + 32U;
              ak = a[na1];
              for (ka = na1; ka > 0; ka--) {
                t = ak << (32U - kba);
                ak = a[ka - 1];
                t |= ak >> kba;
                a[ka] = t;
              }

              a[ka] = ak << (32U - kba);
            }

            /* Compare b against the a. */
            ak = a[na1];
            bk = b[nzb - 1];
            if (((nzb - 1 == 0 ? mask : MAX_uint32_T) & ak) == bk) {
              tpi = 0;
              ka = na1;
              kr = nzb - 1;
              while ((tpi == 0) && (kr > 0)) {
                ka--;
                ak = a[ka];
                kr--;
                bk = b[kr];
                if (((kr == 0 ? mask : MAX_uint32_T) & ak) != bk) {
                  tpi = ak > bk ? 1 : -1;
                }
              }
            } else {
              tpi = ak > bk ? 1 : -1;
            }

            /* If the remainder in a is still greater or equal to b, subtract normalized divisor from a. */
            if ((tpi >= 0) || (nba > nbb)) {
              nbq = nba - nbb;

              /* If the remainder and the divisor are equal, set remainder to zero. */
              if (tpi == 0) {
                ka = na1;
                for (kr = nzb - 1; kr > 0; kr--) {
                  a[ka] = 0U;
                  ka--;
                }

                a[ka] -= b[kr];
              } else {
                /* Otherwise, subtract the divisor from the remainder */
                if (tpi < 0) {
                  ak = a[na1];
                  kba = 31U;
                  for (ka = na1; ka > 0; ka--) {
                    t = ak << 1U;
                    ak = a[ka - 1];
                    t |= ak >> 31U;
                    a[ka] = t;
                  }

                  a[ka] = ak << 1U;
                  tnb++;
                  nbq--;
                }

                bk = 0U;
                ka = (na1 - nzb) + 1;
                for (kr = 0; kr < nzb; kr++) {
                  t = a[ka];
                  ak = (t - b[kr]) - bk;
                  bk = bk != 0U ? (uint32_T)(ak >= t) : (uint32_T)(ak > t);
                  a[ka] = ak;
                  ka++;
                }
              }

              /* Update the quotient. */
              tpi = (int32_T)(nbq >> 5);
              q[tpi] |= 1U << (nbq - ((uint32_T)tpi << 5));

              /* Remove leading zeros from the remainder and check whether the exit conditions have been met. */
              tpi = na1;
              while ((nza > 0) && (a[tpi] == 0U)) {
                nza--;
                tpi--;
              }

              if (nza >= nzb) {
                na1 = nza - 1;
                kba = 1U;
                t = a[nza - 1] >> 1U;
                while (t != 0U) {
                  kba++;
                  t >>= 1U;
                }

                nba = (((uint32_T)(nza - 1) << 5) + kba) - tnb;
                if (nba < nbb) {
                  y = 2;
                }
              } else if (nza == 0) {
                y = 1;
              } else {
                na1 = nza - 1;
                y = 4;
              }
            } else {
              y = 3;
            }
          } while (y == 0);

          /* Return the remainder. */
          if (y == 1) {
            r[0] = a[0];
          } else {
            tpi = (int32_T)(tnb >> 5);
            nbq = tnb - ((uint32_T)tpi << 5);
            if (nbq == 0U) {
              ka = tpi;
              for (kr = 0; kr <= nb1; kr++) {
                r[kr] = a[ka];
                ka++;
              }
            } else {
              ak = a[tpi];
              kr = 0;
              for (ka = tpi + 1; ka <= na1; ka++) {
                t = ak >> nbq;
                ak = a[ka];
                t |= ak << (32U - nbq);
                r[kr] = t;
                kr++;
              }

              r[kr] = ak >> nbq;
            }
          }

          /* Restore b. */
          if (kbb != 32U) {
            bk = b[0];
            for (kr = 0; kr < nb1; kr++) {
              t = bk >> (32U - kbb);
              bk = b[kr + 1];
              t |= bk << kbb;
              b[kr] = t;
            }

            b[kr] = bk >> (32U - kbb);
          }
        } else {
          for (kr = 0; kr < nr; kr++) {
            r[kr] = a[kr];
          }

          y = 6;
        }
      }
    } else {
      for (kr = 0; kr < nr; kr++) {
        r[kr] = a[kr];
      }

      y = 5;
    }
  } else {
    y = -1;
  }

  return y;
}

void uMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T ni;
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

boolean_T sMultiWordGe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return sMultiWordCmp(u1, u2, n) >= 0;
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Controller_implementation_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(Controller_implementation_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (Controller_implementation_M->Timing.TaskCounters.TID[1] == 0) {
    Controller_implementation_M->Timing.RateInteraction.TID1_2 =
      (Controller_implementation_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Controller_implementation_M->Timing.TaskCounters.TID[2])++;
  if ((Controller_implementation_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.02s, 0.0s] */
    Controller_implementation_M->Timing.TaskCounters.TID[2] = 0;
  }
}

static void bbblueBarometer_BMP_ReadRegiste(const
  beagleboneblue_bbblueBaromete_T *obj, uint8_T RegisterValue[6], uint8_T
  *varargout_1)
{
  int32_T i;
  uint8_T output_raw[6];
  uint8_T Data;
  uint8_T SwappedDataBytes;
  Data = 247U;

  /* Start for MATLABSystem: '<S5>/Barometer' */
  memcpy((void *)&SwappedDataBytes, (void *)&Data, (size_t)1 * sizeof(uint8_T));
  *varargout_1 = MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U,
    &SwappedDataBytes, 1U, true, false);
  if (*varargout_1 == 0) {
    *varargout_1 = MW_I2C_MasterRead(obj->i2cObj.MW_I2C_HANDLE, 118U,
      &output_raw[0], 6U, false, true);
    memcpy((void *)&RegisterValue[0], (void *)&output_raw[0], (size_t)6 * sizeof
           (uint8_T));
  } else {
    for (i = 0; i < 6; i++) {
      RegisterValue[i] = 0U;
    }
  }

  /* End of Start for MATLABSystem: '<S5>/Barometer' */
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static int64m_T Controller_implementati_i64ddiv(real_T x, const int64m_T y)
{
  int64m_T tmp_1;
  int64m_T z;
  uint64m_T tmp;
  uint64m_T tmp_0;
  int32_T firstbitn;
  int32_T shiftAmount;
  int32_T xexp;
  boolean_T b_p;
  boolean_T tmp_2;
  static const int64m_T tmp_3 = { { 0U, 2147483648U }/* chunks */
  };

  static const uint64m_T tmp_4 = { { 0U, 2147483648U }/* chunks */
  };

  static const uint64m_T tmp_5 = { { 0U, 0U }/* chunks */
  };

  static const uint64m_T tmp_6 = { { 1U, 0U }/* chunks */
  };

  static const uint64m_T tmp_7 = { { MAX_uint32_T, MAX_uint32_T }/* chunks */
  };

  static const int64m_T tmp_8 = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  static const int64m_T tmp_9 = { { 0U, 0U }/* chunks */
  };

  static const uint64m_T tmp_a = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  int32_T exitg1;
  int32_T exitg2;
  int32_T exitg3;
  boolean_T guard1;

  /* Start for MATLABSystem: '<S5>/Barometer' */
  if (x == 0.0) {
    memcpy((void *)&Controller_implementation_B.ux[0], (void *)&x, (size_t)2 *
           sizeof(uint32_T));
    if ((Controller_implementation_B.ux[0] != 0U) ||
        (Controller_implementation_B.ux[1] != 0U)) {
      b_p = true;
    } else {
      b_p = false;
    }
  } else {
    b_p = false;
  }

  if (sMultiWordLt(&y.chunks[0U], &tmp_9.chunks[0U], 2)) {
    if (sMultiWordGt(&y.chunks[0U], &tmp_3.chunks[0U], 2)) {
      MultiWordNeg(&y.chunks[0U], &Controller_implementation_B.r25.chunks[0U], 2);
      sMultiWord2MultiWord(&Controller_implementation_B.r25.chunks[0U], 2,
                           &Controller_implementation_B.nk_unsgn.chunks[0U], 2);
    } else {
      Controller_implementation_B.nk_unsgn = tmp_4;
    }
  } else {
    sMultiWord2MultiWord(&y.chunks[0U], 2,
                         &Controller_implementation_B.nk_unsgn.chunks[0U], 2);
  }

  tmp_2 = ((x < 0.0) || b_p);
  if (tmp_2) {
    Controller_implementation_B.x_unsgn = -x;
  } else {
    Controller_implementation_B.x_unsgn = x;
  }

  if (uMultiWordEq(&Controller_implementation_B.nk_unsgn.chunks[0U],
                   &tmp_5.chunks[0U], 2)) {
    if (Controller_implementation_B.x_unsgn > 0.0) {
      Controller_implementation_B.res = tmp_7;
    } else {
      Controller_implementation_B.res = tmp_5;
    }
  } else if ((Controller_implementation_B.x_unsgn <= 0.0) || rtIsNaN
             (Controller_implementation_B.x_unsgn)) {
    Controller_implementation_B.res = tmp_5;
  } else if (rtIsInf(Controller_implementation_B.x_unsgn)) {
    Controller_implementation_B.res = tmp_7;
  } else {
    Controller_implementation_B.x_unsgn = frexp
      (Controller_implementation_B.x_unsgn, &shiftAmount);
    Double2MultiWord(rt_roundd_snf(Controller_implementation_B.x_unsgn *
      9.007199254740992E+15), &Controller_implementation_B.xint.chunks[0U], 2);
    xexp = shiftAmount - 53;
    firstbitn = 63;
    do {
      exitg1 = 0;
      uMultiWordShr(&Controller_implementation_B.nk_unsgn.chunks[0U], 2,
                    (uint32_T)firstbitn,
                    &Controller_implementation_B.res.chunks[0U], 2);
      if (uMultiWordLe(&Controller_implementation_B.res.chunks[0U],
                       &tmp_5.chunks[0U], 2)) {
        firstbitn--;
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (shiftAmount - 53 < firstbitn - 53) {
      Controller_implementation_B.res = tmp_5;
    } else if (shiftAmount - 53 > firstbitn + 12) {
      Controller_implementation_B.res = tmp_7;
    } else {
      Controller_implementation_B.res = tmp_5;
      guard1 = false;
      if (firstbitn < 63) {
        uMultiWordDivZero(&Controller_implementation_B.xint.chunks[0U], 2,
                          &Controller_implementation_B.nk_unsgn.chunks[0U], 2,
                          &Controller_implementation_B.res.chunks[0U], 2,
                          &Controller_implementation_B.r26.chunks[0U], 2,
                          &Controller_implementation_B.r27.chunks[0U], 2,
                          &Controller_implementation_B.r28.chunks[0U], 2);
        if (!uMultiWordEq(&Controller_implementation_B.nk_unsgn.chunks[0U],
                          &tmp_5.chunks[0U], 2)) {
          uMultiWordDivZero(&Controller_implementation_B.xint.chunks[0U], 2,
                            &Controller_implementation_B.nk_unsgn.chunks[0U], 2,
                            &Controller_implementation_B.r28.chunks[0U], 2,
                            &Controller_implementation_B.r29.chunks[0U], 2,
                            &Controller_implementation_B.r30.chunks[0U], 2,
                            &Controller_implementation_B.r31.chunks[0U], 2);
          uMultiWordMul(&Controller_implementation_B.r28.chunks[0U], 2,
                        &Controller_implementation_B.nk_unsgn.chunks[0U], 2,
                        &Controller_implementation_B.r3.chunks[0U], 4);
          uMultiWord2MultiWord(&Controller_implementation_B.r3.chunks[0U], 4,
                               &Controller_implementation_B.r27.chunks[0U], 2);
          MultiWordSub(&Controller_implementation_B.xint.chunks[0U],
                       &Controller_implementation_B.r27.chunks[0U],
                       &Controller_implementation_B.r28.chunks[0U], 2);
          Controller_implementation_B.xint = Controller_implementation_B.r28;
        }

        if (shiftAmount - 53 < 0) {
          uMultiWordShr(&Controller_implementation_B.res.chunks[0U], 2,
                        (uint32_T)(53 - shiftAmount), &tmp_0.chunks[0U], 2);
          uMultiWordShr(&Controller_implementation_B.res.chunks[0U], 2,
                        (uint32_T)(52 - shiftAmount),
                        &Controller_implementation_B.r39.chunks[0U], 2);
          MultiWordAnd(&Controller_implementation_B.r39.chunks[0U],
                       &tmp_6.chunks[0U],
                       &Controller_implementation_B.r38.chunks[0U], 2);
          MultiWordAdd(&tmp_0.chunks[0U],
                       &Controller_implementation_B.r38.chunks[0U],
                       &Controller_implementation_B.res.chunks[0U], 2);
        } else {
          do {
            exitg2 = 0;
            if (xexp > 0) {
              if (63 - firstbitn > xexp) {
                shiftAmount = xexp;
              } else {
                shiftAmount = 63 - firstbitn;
              }

              uMultiWordShr(&Controller_implementation_B.res.chunks[0U], 2,
                            (uint32_T)(64 - shiftAmount),
                            &Controller_implementation_B.r29.chunks[0U], 2);
              if (uMultiWordGt(&Controller_implementation_B.r29.chunks[0U],
                               &tmp_5.chunks[0U], 2)) {
                Controller_implementation_B.res = tmp_7;
                exitg2 = 1;
              } else {
                uMultiWordShl(&Controller_implementation_B.res.chunks[0U], 2,
                              (uint32_T)shiftAmount,
                              &Controller_implementation_B.r32.chunks[0U], 2);
                xexp -= shiftAmount;
                uMultiWordShl(&Controller_implementation_B.xint.chunks[0U], 2,
                              (uint32_T)shiftAmount,
                              &Controller_implementation_B.r33.chunks[0U], 2);
                Controller_implementation_B.xint =
                  Controller_implementation_B.r33;
                uMultiWordDivZero(&Controller_implementation_B.r33.chunks[0U], 2,
                                  &Controller_implementation_B.nk_unsgn.chunks
                                  [0U], 2,
                                  &Controller_implementation_B.nIsOdd.chunks[0U],
                                  2, &Controller_implementation_B.r34.chunks[0U],
                                  2, &Controller_implementation_B.r35.chunks[0U],
                                  2, &Controller_implementation_B.r36.chunks[0U],
                                  2);
                Controller_implementation_B.r35 = tmp_7;
                MultiWordSub(&tmp_7.chunks[0U],
                             &Controller_implementation_B.nIsOdd.chunks[0U],
                             &Controller_implementation_B.r34.chunks[0U], 2);
                if (uMultiWordLe(&Controller_implementation_B.r34.chunks[0U],
                                 &Controller_implementation_B.r32.chunks[0U], 2))
                {
                  Controller_implementation_B.res = tmp_7;
                  exitg2 = 1;
                } else {
                  MultiWordAdd(&Controller_implementation_B.r32.chunks[0U],
                               &Controller_implementation_B.nIsOdd.chunks[0U],
                               &Controller_implementation_B.r35.chunks[0U], 2);
                  Controller_implementation_B.res =
                    Controller_implementation_B.r35;
                  Controller_implementation_B.r36 = tmp_5;
                  if (!uMultiWordEq
                      (&Controller_implementation_B.nk_unsgn.chunks[0U],
                       &tmp_5.chunks[0U], 2)) {
                    uMultiWordDivZero(&Controller_implementation_B.r33.chunks[0U],
                                      2,
                                      &Controller_implementation_B.nk_unsgn.chunks
                                      [0U], 2,
                                      &Controller_implementation_B.r37.chunks[0U],
                                      2,
                                      &Controller_implementation_B.r38.chunks[0U],
                                      2,
                                      &Controller_implementation_B.r39.chunks[0U],
                                      2, &tmp.chunks[0U], 2);
                    uMultiWordMul(&Controller_implementation_B.r37.chunks[0U], 2,
                                  &Controller_implementation_B.nk_unsgn.chunks
                                  [0U], 2,
                                  &Controller_implementation_B.r3.chunks[0U], 4);
                    uMultiWord2MultiWord(&Controller_implementation_B.r3.chunks
                                         [0U], 4, &tmp_0.chunks[0U], 2);
                    MultiWordSub(&Controller_implementation_B.r33.chunks[0U],
                                 &tmp_0.chunks[0U],
                                 &Controller_implementation_B.r37.chunks[0U], 2);
                    Controller_implementation_B.xint =
                      Controller_implementation_B.r37;
                  }
                }
              }
            } else {
              uMultiWordShl(&Controller_implementation_B.xint.chunks[0U], 2, 1U,
                            &Controller_implementation_B.r27.chunks[0U], 2);
              if (uMultiWordGe(&Controller_implementation_B.r27.chunks[0U],
                               &Controller_implementation_B.nk_unsgn.chunks[0U],
                               2)) {
                MultiWordAdd(&Controller_implementation_B.res.chunks[0U],
                             &tmp_6.chunks[0U],
                             &Controller_implementation_B.r30.chunks[0U], 2);
                Controller_implementation_B.res =
                  Controller_implementation_B.r30;
              }

              exitg2 = 1;
            }
          } while (exitg2 == 0);
        }
      } else if (shiftAmount - 53 > 10) {
        uMultiWordShl(&Controller_implementation_B.xint.chunks[0U], 2, 11U,
                      &Controller_implementation_B.r26.chunks[0U], 2);
        Controller_implementation_B.xint = Controller_implementation_B.r26;
        xexp = shiftAmount - 64;
        Controller_implementation_B.r26 = tmp_6;
        MultiWordAnd(&Controller_implementation_B.nk_unsgn.chunks[0U],
                     &tmp_6.chunks[0U],
                     &Controller_implementation_B.nIsOdd.chunks[0U], 2);
        if (uMultiWordGe(&Controller_implementation_B.xint.chunks[0U],
                         &Controller_implementation_B.nk_unsgn.chunks[0U], 2)) {
          Controller_implementation_B.res = tmp_6;
          MultiWordSub(&Controller_implementation_B.xint.chunks[0U],
                       &Controller_implementation_B.nk_unsgn.chunks[0U],
                       &Controller_implementation_B.r27.chunks[0U], 2);
          Controller_implementation_B.xint = Controller_implementation_B.r27;
        } else if (shiftAmount - 64 > 0) {
          xexp = shiftAmount - 65;
          Controller_implementation_B.res = tmp_6;
          uMultiWordShr(&Controller_implementation_B.nk_unsgn.chunks[0U], 2, 1U,
                        &Controller_implementation_B.r27.chunks[0U], 2);
          MultiWordSub(&Controller_implementation_B.xint.chunks[0U],
                       &Controller_implementation_B.r27.chunks[0U],
                       &Controller_implementation_B.r26.chunks[0U], 2);
          uMultiWordShl(&Controller_implementation_B.r26.chunks[0U], 2, 1U,
                        &Controller_implementation_B.xint.chunks[0U], 2);
          if (uMultiWordNe(&Controller_implementation_B.nIsOdd.chunks[0U],
                           &tmp_5.chunks[0U], 2)) {
            MultiWordSub(&Controller_implementation_B.xint.chunks[0U],
                         &tmp_6.chunks[0U],
                         &Controller_implementation_B.r28.chunks[0U], 2);
            Controller_implementation_B.xint = Controller_implementation_B.r28;
          }
        }

        do {
          exitg1 = 0;
          if (xexp > 0) {
            if (uMultiWordEq(&Controller_implementation_B.xint.chunks[0U],
                             &tmp_5.chunks[0U], 2)) {
              uMultiWordShr(&Controller_implementation_B.res.chunks[0U], 2,
                            (uint32_T)(64 - xexp), &tmp.chunks[0U], 2);
              if (uMultiWordGt(&tmp.chunks[0U], &tmp_5.chunks[0U], 2)) {
                Controller_implementation_B.res = tmp_7;
                exitg1 = 1;
              } else {
                uMultiWordShl(&Controller_implementation_B.res.chunks[0U], 2,
                              (uint32_T)xexp, &tmp_0.chunks[0U], 2);
                Controller_implementation_B.res = tmp_0;
                xexp = 0;
              }
            } else {
              firstbitn = 63;
              do {
                exitg3 = 0;
                uMultiWordShr(&Controller_implementation_B.xint.chunks[0U], 2,
                              (uint32_T)firstbitn,
                              &Controller_implementation_B.r32.chunks[0U], 2);
                if (uMultiWordLe(&Controller_implementation_B.r32.chunks[0U],
                                 &tmp_5.chunks[0U], 2)) {
                  firstbitn--;
                } else {
                  exitg3 = 1;
                }
              } while (exitg3 == 0);

              if (63 - firstbitn >= xexp) {
                shiftAmount = xexp;
              } else {
                shiftAmount = 63 - firstbitn;
              }

              uMultiWordShr(&Controller_implementation_B.res.chunks[0U], 2,
                            (uint32_T)(64 - shiftAmount),
                            &Controller_implementation_B.r33.chunks[0U], 2);
              if ((shiftAmount != 0) && uMultiWordGt
                  (&Controller_implementation_B.r33.chunks[0U], &tmp_5.chunks[0U],
                   2)) {
                Controller_implementation_B.res = tmp_7;
                exitg1 = 1;
              } else {
                uMultiWordShl(&Controller_implementation_B.res.chunks[0U], 2,
                              (uint32_T)shiftAmount,
                              &Controller_implementation_B.r34.chunks[0U], 2);
                Controller_implementation_B.res =
                  Controller_implementation_B.r34;
                xexp -= shiftAmount;
                uMultiWordShl(&Controller_implementation_B.xint.chunks[0U], 2,
                              (uint32_T)shiftAmount,
                              &Controller_implementation_B.r35.chunks[0U], 2);
                Controller_implementation_B.xint =
                  Controller_implementation_B.r35;
                if (uMultiWordGt(&Controller_implementation_B.xint.chunks[0U],
                                 &Controller_implementation_B.nk_unsgn.chunks[0U],
                                 2)) {
                  Controller_implementation_B.r26 = tmp_6;
                  MultiWordAdd(&Controller_implementation_B.r34.chunks[0U],
                               &tmp_6.chunks[0U],
                               &Controller_implementation_B.r39.chunks[0U], 2);
                  Controller_implementation_B.res =
                    Controller_implementation_B.r39;
                  MultiWordSub(&Controller_implementation_B.xint.chunks[0U],
                               &Controller_implementation_B.nk_unsgn.chunks[0U],
                               &Controller_implementation_B.r26.chunks[0U], 2);
                  Controller_implementation_B.xint =
                    Controller_implementation_B.r26;
                } else if (xexp > 0) {
                  xexp--;
                  uMultiWordShr(&Controller_implementation_B.r34.chunks[0U], 2,
                                63U, &Controller_implementation_B.r36.chunks[0U],
                                2);
                  if (uMultiWordGt(&Controller_implementation_B.r36.chunks[0U],
                                   &tmp_5.chunks[0U], 2)) {
                    Controller_implementation_B.res = tmp_7;
                    exitg1 = 1;
                  } else {
                    uMultiWordShl(&Controller_implementation_B.r34.chunks[0U], 2,
                                  1U, &Controller_implementation_B.r37.chunks[0U],
                                  2);
                    Controller_implementation_B.r26 = tmp_6;
                    MultiWordAdd(&Controller_implementation_B.r37.chunks[0U],
                                 &tmp_6.chunks[0U],
                                 &Controller_implementation_B.res.chunks[0U], 2);
                    uMultiWordShr(&Controller_implementation_B.nk_unsgn.chunks
                                  [0U], 2, 1U,
                                  &Controller_implementation_B.r26.chunks[0U], 2);
                    MultiWordSub(&Controller_implementation_B.xint.chunks[0U],
                                 &Controller_implementation_B.r26.chunks[0U],
                                 &Controller_implementation_B.r37.chunks[0U], 2);
                    uMultiWordShl(&Controller_implementation_B.r37.chunks[0U], 2,
                                  1U, &Controller_implementation_B.xint.chunks
                                  [0U], 2);
                    Controller_implementation_B.r37 = tmp_5;
                    if (uMultiWordNe(&Controller_implementation_B.nIsOdd.chunks
                                     [0U], &tmp_5.chunks[0U], 2)) {
                      MultiWordSub(&Controller_implementation_B.xint.chunks[0U],
                                   &tmp_6.chunks[0U],
                                   &Controller_implementation_B.r38.chunks[0U],
                                   2);
                      Controller_implementation_B.xint =
                        Controller_implementation_B.r38;
                    }
                  }
                }
              }
            }
          } else {
            guard1 = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      } else {
        uMultiWordShl(&Controller_implementation_B.xint.chunks[0U], 2, 10U,
                      &Controller_implementation_B.r26.chunks[0U], 2);
        Controller_implementation_B.xint = Controller_implementation_B.r26;
        guard1 = true;
      }

      if (guard1) {
        MultiWordAnd(&Controller_implementation_B.xint.chunks[0U],
                     &tmp_4.chunks[0U], &Controller_implementation_B.r29.chunks
                     [0U], 2);
        uMultiWordShl(&Controller_implementation_B.xint.chunks[0U], 2, 1U,
                      &Controller_implementation_B.r30.chunks[0U], 2);
        if (uMultiWordNe(&Controller_implementation_B.r29.chunks[0U],
                         &tmp_5.chunks[0U], 2) || uMultiWordGe
            (&Controller_implementation_B.r30.chunks[0U],
             &Controller_implementation_B.nk_unsgn.chunks[0U], 2)) {
          MultiWordAdd(&Controller_implementation_B.res.chunks[0U],
                       &tmp_6.chunks[0U],
                       &Controller_implementation_B.r31.chunks[0U], 2);
          Controller_implementation_B.res = Controller_implementation_B.r31;
        }
      }
    }
  }

  if ((sMultiWordLt(&y.chunks[0U], &tmp_9.chunks[0U], 2) && (x >= 0.0) && (!b_p))
      || (sMultiWordGe(&y.chunks[0U], &tmp_9.chunks[0U], 2) && tmp_2)) {
    if (uMultiWordLe(&Controller_implementation_B.res.chunks[0U], &tmp_a.chunks
                     [0U], 2)) {
      uMultiWord2MultiWord(&Controller_implementation_B.res.chunks[0U], 2,
                           &tmp_1.chunks[0U], 2);
      MultiWordNeg(&tmp_1.chunks[0U], &z.chunks[0U], 2);
    } else {
      z = tmp_3;
    }
  } else if (uMultiWordLe(&Controller_implementation_B.res.chunks[0U],
                          &tmp_a.chunks[0U], 2)) {
    uMultiWord2MultiWord(&Controller_implementation_B.res.chunks[0U], 2,
                         &z.chunks[0U], 2);
  } else {
    z = tmp_8;
  }

  /* End of Start for MATLABSystem: '<S5>/Barometer' */
  return z;
}

static uint64m_T Controller_eml_mixed_uint64_mul(const uint64m_T nv, real_T y)
{
  uint64m_T tmp_2;
  uint64m_T tmp_3;
  uint64m_T tmp_4;
  uint64m_T z;
  int32_T ex_t;
  int16_T tmp;
  int16_T tmp_0;
  int16_T tmp_1;
  static const uint64m_T tmp_5 = { { MAX_uint32_T, MAX_uint32_T }/* chunks */
  };

  static const uint64m_T tmp_6 = { { 1U, 0U }/* chunks */
  };

  static const uint64m_T tmp_7 = { { 0U, 0U }/* chunks */
  };

  static const uint64m_T tmp_8 = { { MAX_uint32_T, 0U }/* chunks */
  };

  /* Start for MATLABSystem: '<S5>/Barometer' */
  if (rtIsNaN(y) || (y <= 0.0)) {
    z = tmp_7;
  } else {
    Controller_implementation_B.yd = frexp(y, &ex_t);
    if (ex_t <= -64) {
      z = tmp_7;
    } else {
      Double2MultiWord(rt_roundd_snf(Controller_implementation_B.yd *
        9.007199254740992E+15), &Controller_implementation_B.yint.chunks[0U], 2);
      uMultiWordShr(&Controller_implementation_B.yint.chunks[0U], 2, 32U,
                    &Controller_implementation_B.b_y1.chunks[0U], 2);
      MultiWordAnd(&Controller_implementation_B.yint.chunks[0U], &tmp_8.chunks
                   [0U], &Controller_implementation_B.b_y0.chunks[0U], 2);
      if (uMultiWordEq(&nv.chunks[0U], &tmp_7.chunks[0U], 2)) {
        z = tmp_7;
      } else if (rtIsInf(y)) {
        z = tmp_5;
      } else if (ex_t - 53 > 64) {
        z = tmp_5;
      } else {
        uMultiWordShr(&nv.chunks[0U], 2, 32U,
                      &Controller_implementation_B.n1.chunks[0U], 2);
        Controller_implementation_B.r42 = nv;
        Controller_implementation_B.r43 = tmp_8;
        MultiWordAnd(&nv.chunks[0U], &tmp_8.chunks[0U],
                     &Controller_implementation_B.yint.chunks[0U], 2);
        uMultiWordMul(&Controller_implementation_B.yint.chunks[0U], 2,
                      &Controller_implementation_B.b_y0.chunks[0U], 2,
                      &Controller_implementation_B.r4.chunks[0U], 4);
        uMultiWord2MultiWord(&Controller_implementation_B.r4.chunks[0U], 4,
                             &Controller_implementation_B.ldword.chunks[0U], 2);
        uMultiWordMul(&Controller_implementation_B.yint.chunks[0U], 2,
                      &Controller_implementation_B.b_y1.chunks[0U], 2,
                      &Controller_implementation_B.r4.chunks[0U], 4);
        uMultiWord2MultiWord(&Controller_implementation_B.r4.chunks[0U], 4,
                             &Controller_implementation_B.temp0.chunks[0U], 2);
        uMultiWordMul(&Controller_implementation_B.n1.chunks[0U], 2,
                      &Controller_implementation_B.b_y0.chunks[0U], 2,
                      &Controller_implementation_B.r4.chunks[0U], 4);
        uMultiWord2MultiWord(&Controller_implementation_B.r4.chunks[0U], 4,
                             &Controller_implementation_B.b_y0.chunks[0U], 2);
        Controller_implementation_B.r44 = tmp_8;
        MultiWordAnd(&Controller_implementation_B.temp0.chunks[0U],
                     &tmp_8.chunks[0U], &Controller_implementation_B.r43.chunks
                     [0U], 2);
        uMultiWordShr(&Controller_implementation_B.ldword.chunks[0U], 2, 32U,
                      &Controller_implementation_B.r44.chunks[0U], 2);
        MultiWordAdd(&Controller_implementation_B.r43.chunks[0U],
                     &Controller_implementation_B.r44.chunks[0U],
                     &Controller_implementation_B.r42.chunks[0U], 2);
        Controller_implementation_B.r44 = tmp_8;
        MultiWordAnd(&Controller_implementation_B.b_y0.chunks[0U],
                     &tmp_8.chunks[0U], &Controller_implementation_B.r43.chunks
                     [0U], 2);
        MultiWordAdd(&Controller_implementation_B.r42.chunks[0U],
                     &Controller_implementation_B.r43.chunks[0U],
                     &Controller_implementation_B.yint.chunks[0U], 2);
        Controller_implementation_B.r43 = tmp_8;
        MultiWordAnd(&Controller_implementation_B.ldword.chunks[0U],
                     &tmp_8.chunks[0U], &Controller_implementation_B.r42.chunks
                     [0U], 2);
        uMultiWordShl(&Controller_implementation_B.yint.chunks[0U], 2, 32U,
                      &Controller_implementation_B.r43.chunks[0U], 2);
        MultiWordAdd(&Controller_implementation_B.r42.chunks[0U],
                     &Controller_implementation_B.r43.chunks[0U],
                     &Controller_implementation_B.ldword.chunks[0U], 2);
        uMultiWordMul(&Controller_implementation_B.n1.chunks[0U], 2,
                      &Controller_implementation_B.b_y1.chunks[0U], 2,
                      &Controller_implementation_B.r4.chunks[0U], 4);
        uMultiWord2MultiWord(&Controller_implementation_B.r4.chunks[0U], 4,
                             &Controller_implementation_B.r44.chunks[0U], 2);
        uMultiWordShr(&Controller_implementation_B.temp0.chunks[0U], 2, 32U,
                      &tmp_2.chunks[0U], 2);
        MultiWordAdd(&Controller_implementation_B.r44.chunks[0U], &tmp_2.chunks
                     [0U], &Controller_implementation_B.r43.chunks[0U], 2);
        uMultiWordShr(&Controller_implementation_B.b_y0.chunks[0U], 2, 32U,
                      &Controller_implementation_B.r44.chunks[0U], 2);
        MultiWordAdd(&Controller_implementation_B.r43.chunks[0U],
                     &Controller_implementation_B.r44.chunks[0U],
                     &Controller_implementation_B.r42.chunks[0U], 2);
        uMultiWordShr(&Controller_implementation_B.yint.chunks[0U], 2, 32U,
                      &Controller_implementation_B.r43.chunks[0U], 2);
        MultiWordAdd(&Controller_implementation_B.r42.chunks[0U],
                     &Controller_implementation_B.r43.chunks[0U],
                     &Controller_implementation_B.yint.chunks[0U], 2);
        if (ex_t - 53 >= 0) {
          if (uMultiWordGt(&Controller_implementation_B.yint.chunks[0U],
                           &tmp_7.chunks[0U], 2)) {
            z = tmp_5;
          } else {
            tmp = (int16_T)(117 - ex_t);
            if (117 - ex_t < 0) {
              tmp = 0;
            }

            uMultiWordShr(&Controller_implementation_B.ldword.chunks[0U], 2,
                          (uint32_T)tmp, &tmp_4.chunks[0U], 2);
            if ((117 - ex_t < 64) && uMultiWordGt(&tmp_4.chunks[0U],
                 &tmp_7.chunks[0U], 2)) {
              z = tmp_5;
            } else {
              tmp = (int16_T)(ex_t - 53);
              if (ex_t - 53 < 0) {
                tmp = 0;
              } else if (ex_t - 53 > 255) {
                tmp = 255;
              }

              uMultiWordShl(&Controller_implementation_B.ldword.chunks[0U], 2,
                            (uint32_T)tmp, &z.chunks[0U], 2);
            }
          }
        } else if (ex_t - 53 > -64) {
          tmp = (int16_T)(53 - ex_t);
          if (53 - ex_t < 0) {
            tmp = 0;
          }

          uMultiWordShr(&Controller_implementation_B.yint.chunks[0U], 2,
                        (uint32_T)tmp, &Controller_implementation_B.r42.chunks
                        [0U], 2);
          if (uMultiWordGt(&Controller_implementation_B.r42.chunks[0U],
                           &tmp_7.chunks[0U], 2)) {
            z = tmp_5;
          } else {
            tmp = (int16_T)(53 - ex_t);
            if (53 - ex_t < 0) {
              tmp = 0;
            }

            tmp_0 = (int16_T)(ex_t + 11);
            if (ex_t + 11 < 0) {
              tmp_0 = 0;
            } else if (ex_t + 11 > 255) {
              tmp_0 = 255;
            }

            tmp_1 = (int16_T)(52 - ex_t);
            if (52 - ex_t < 0) {
              tmp_1 = 0;
            }

            uMultiWordShr(&Controller_implementation_B.ldword.chunks[0U], 2,
                          (uint32_T)tmp, &tmp_4.chunks[0U], 2);
            uMultiWordShl(&Controller_implementation_B.yint.chunks[0U], 2,
                          (uint32_T)tmp_0, &z.chunks[0U], 2);
            MultiWordAdd(&tmp_4.chunks[0U], &z.chunks[0U], &tmp_3.chunks[0U], 2);
            uMultiWordShr(&Controller_implementation_B.ldword.chunks[0U], 2,
                          (uint32_T)tmp_1, &z.chunks[0U], 2);
            MultiWordAnd(&z.chunks[0U], &tmp_6.chunks[0U], &tmp_4.chunks[0U], 2);
            MultiWordAdd(&tmp_3.chunks[0U], &tmp_4.chunks[0U], &z.chunks[0U], 2);
          }
        } else if (ex_t - 53 == -64) {
          uMultiWordShr(&Controller_implementation_B.ldword.chunks[0U], 2, 63U,
                        &Controller_implementation_B.r43.chunks[0U], 2);
          MultiWordAnd(&Controller_implementation_B.r43.chunks[0U],
                       &tmp_6.chunks[0U],
                       &Controller_implementation_B.r42.chunks[0U], 2);
          MultiWordAdd(&Controller_implementation_B.yint.chunks[0U],
                       &Controller_implementation_B.r42.chunks[0U],
                       &Controller_implementation_B.r43.chunks[0U], 2);
          z = Controller_implementation_B.r43;
        } else {
          tmp = (int16_T)-(ex_t + 11);
          if (-(ex_t + 11) < 0) {
            tmp = 0;
          }

          tmp_0 = (int16_T)-(ex_t + 12);
          if (-(ex_t + 12) < 0) {
            tmp_0 = 0;
          }

          uMultiWordShr(&Controller_implementation_B.yint.chunks[0U], 2,
                        (uint32_T)tmp, &Controller_implementation_B.r42.chunks
                        [0U], 2);
          uMultiWordShr(&Controller_implementation_B.yint.chunks[0U], 2,
                        (uint32_T)tmp_0,
                        &Controller_implementation_B.r44.chunks[0U], 2);
          MultiWordAnd(&Controller_implementation_B.r44.chunks[0U],
                       &tmp_6.chunks[0U],
                       &Controller_implementation_B.r43.chunks[0U], 2);
          MultiWordAdd(&Controller_implementation_B.r42.chunks[0U],
                       &Controller_implementation_B.r43.chunks[0U],
                       &Controller_implementation_B.r44.chunks[0U], 2);
          z = Controller_implementation_B.r44;
        }
      }
    }
  }

  /* End of Start for MATLABSystem: '<S5>/Barometer' */
  return z;
}

static int64m_T Controller_implementation_times(real_T x, const int64m_T y)
{
  int64m_T z;
  static const int64m_T tmp = { { 0U, 2147483648U }/* chunks */
  };

  static const int64m_T tmp_0 = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  static const uint64m_T tmp_1 = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  static const int64m_T tmp_2 = { { 0U, 0U }/* chunks */
  };

  static const uint64m_T tmp_3 = { { 0U, 2147483648U }/* chunks */
  };

  /* Start for MATLABSystem: '<S5>/Barometer' */
  if (x < 0.0) {
    if (sMultiWordLt(&y.chunks[0U], &tmp_2.chunks[0U], 2)) {
      if (sMultiWordGt(&y.chunks[0U], &tmp.chunks[0U], 2)) {
        MultiWordNeg(&y.chunks[0U], &Controller_implementation_B.r40.chunks[0U],
                     2);
        sMultiWord2MultiWord(&Controller_implementation_B.r40.chunks[0U], 2,
                             &Controller_implementation_B.n_unsgn.chunks[0U], 2);
      } else {
        Controller_implementation_B.n_unsgn = tmp_3;
      }
    } else {
      sMultiWord2MultiWord(&y.chunks[0U], 2,
                           &Controller_implementation_B.n_unsgn.chunks[0U], 2);
    }

    Controller_implementation_B.n_unsgn = Controller_eml_mixed_uint64_mul
      (Controller_implementation_B.n_unsgn, -x);
  } else {
    if (sMultiWordLt(&y.chunks[0U], &tmp_2.chunks[0U], 2)) {
      if (sMultiWordGt(&y.chunks[0U], &tmp.chunks[0U], 2)) {
        MultiWordNeg(&y.chunks[0U], &Controller_implementation_B.r40.chunks[0U],
                     2);
        sMultiWord2MultiWord(&Controller_implementation_B.r40.chunks[0U], 2,
                             &Controller_implementation_B.n_unsgn.chunks[0U], 2);
      } else {
        Controller_implementation_B.n_unsgn = tmp_3;
      }
    } else {
      sMultiWord2MultiWord(&y.chunks[0U], 2,
                           &Controller_implementation_B.n_unsgn.chunks[0U], 2);
    }

    Controller_implementation_B.n_unsgn = Controller_eml_mixed_uint64_mul
      (Controller_implementation_B.n_unsgn, x);
  }

  if ((sMultiWordLt(&y.chunks[0U], &tmp_2.chunks[0U], 2) && (x > 0.0)) ||
      (sMultiWordGt(&y.chunks[0U], &tmp_2.chunks[0U], 2) && (x < 0.0))) {
    if (uMultiWordLe(&Controller_implementation_B.n_unsgn.chunks[0U],
                     &tmp_1.chunks[0U], 2)) {
      uMultiWord2MultiWord(&Controller_implementation_B.n_unsgn.chunks[0U], 2,
                           &Controller_implementation_B.r41.chunks[0U], 2);
      MultiWordNeg(&Controller_implementation_B.r41.chunks[0U], &z.chunks[0U], 2);
    } else {
      z = tmp;
    }
  } else if (uMultiWordLe(&Controller_implementation_B.n_unsgn.chunks[0U],
                          &tmp_1.chunks[0U], 2)) {
    uMultiWord2MultiWord(&Controller_implementation_B.n_unsgn.chunks[0U], 2,
                         &z.chunks[0U], 2);
  } else {
    z = tmp_0;
  }

  /* End of Start for MATLABSystem: '<S5>/Barometer' */
  return z;
}

static real_T Contro_bbblueBarometer_stepImpl(const
  beagleboneblue_bbblueBaromete_T *obj)
{
  real_T y;
  int32_T rawT;
  uint8_T data[6];
  uint8_T a__3;
  static const int64m_T tmp = { { 0U, 32768U }/* chunks */
  };

  static const int64m_T tmp_0 = { { 128000U, 0U }/* chunks */
  };

  static const int64m_T tmp_1 = { { 3125U, 0U }/* chunks */
  };

  static const int64m_T tmp_2 = { { 0U, 0U }/* chunks */
  };

  /* Start for MATLABSystem: '<S5>/Barometer' */
  bbblueBarometer_BMP_ReadRegiste(obj, data, &a__3);
  rawT = data[3] << 12 | data[4] << 4 | data[5] >> 4;
  sLong2MultiWord(rawT, &Controller_implementation_B.r18.chunks[0U], 2);
  sMultiWordShr(&Controller_implementation_B.r18.chunks[0U], 2, 3U,
                &Controller_implementation_B.r17.chunks[0U], 2);
  sMultiWord2MultiWord(&Controller_implementation_B.r17.chunks[0U], 2,
                       &Controller_implementation_B.r10.chunks[0U], 3);

  /* Start for MATLABSystem: '<S5>/Barometer' */
  uLong2MultiWord(obj->dig_T1, &Controller_implementation_B.r18.chunks[0U], 2);
  sMultiWordShl(&Controller_implementation_B.r18.chunks[0U], 2, 1U,
                &Controller_implementation_B.r17.chunks[0U], 2);
  sMultiWord2MultiWord(&Controller_implementation_B.r17.chunks[0U], 2,
                       &Controller_implementation_B.r11.chunks[0U], 3);
  MultiWordSub(&Controller_implementation_B.r10.chunks[0U],
               &Controller_implementation_B.r11.chunks[0U],
               &Controller_implementation_B.r9.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r9.chunks[0U], 3,
    &Controller_implementation_B.r16.chunks[0U], 2);

  /* Start for MATLABSystem: '<S5>/Barometer' */
  sLong2MultiWord(obj->dig_T2, &Controller_implementation_B.r17.chunks[0U], 2);
  sMultiWordMul(&Controller_implementation_B.r16.chunks[0U], 2,
                &Controller_implementation_B.r17.chunks[0U], 2,
                &Controller_implementation_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r.chunks[0U], 4,
    &Controller_implementation_B.r15.chunks[0U], 2);

  /* Start for MATLABSystem: '<S5>/Barometer' */
  sMultiWordShr(&Controller_implementation_B.r15.chunks[0U], 2, 11U,
                &Controller_implementation_B.r14.chunks[0U], 2);
  sMultiWord2MultiWord(&Controller_implementation_B.r14.chunks[0U], 2,
                       &Controller_implementation_B.r8.chunks[0U], 3);
  sLong2MultiWord(rawT, &Controller_implementation_B.r20.chunks[0U], 2);
  sMultiWordShr(&Controller_implementation_B.r20.chunks[0U], 2, 4U,
                &Controller_implementation_B.r19.chunks[0U], 2);
  sMultiWord2MultiWord(&Controller_implementation_B.r19.chunks[0U], 2,
                       &Controller_implementation_B.r11.chunks[0U], 3);

  /* Start for MATLABSystem: '<S5>/Barometer' */
  uLong2MultiWord(obj->dig_T1, &Controller_implementation_B.r19.chunks[0U], 2);
  sMultiWord2MultiWord(&Controller_implementation_B.r19.chunks[0U], 2,
                       &Controller_implementation_B.r12.chunks[0U], 3);
  MultiWordSub(&Controller_implementation_B.r11.chunks[0U],
               &Controller_implementation_B.r12.chunks[0U],
               &Controller_implementation_B.r10.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r10.chunks[0U], 3,
    &Controller_implementation_B.r18.chunks[0U], 2);

  /* Start for MATLABSystem: '<S5>/Barometer' */
  sLong2MultiWord(rawT, &Controller_implementation_B.r21.chunks[0U], 2);
  sMultiWordShr(&Controller_implementation_B.r21.chunks[0U], 2, 4U,
                &Controller_implementation_B.r20.chunks[0U], 2);
  sMultiWord2MultiWord(&Controller_implementation_B.r20.chunks[0U], 2,
                       &Controller_implementation_B.r11.chunks[0U], 3);

  /* Start for MATLABSystem: '<S5>/Barometer' */
  uLong2MultiWord(obj->dig_T1, &Controller_implementation_B.r20.chunks[0U], 2);
  sMultiWord2MultiWord(&Controller_implementation_B.r20.chunks[0U], 2,
                       &Controller_implementation_B.r12.chunks[0U], 3);
  MultiWordSub(&Controller_implementation_B.r11.chunks[0U],
               &Controller_implementation_B.r12.chunks[0U],
               &Controller_implementation_B.r10.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r10.chunks[0U], 3,
    &Controller_implementation_B.r19.chunks[0U], 2);
  sMultiWordMul(&Controller_implementation_B.r18.chunks[0U], 2,
                &Controller_implementation_B.r19.chunks[0U], 2,
                &Controller_implementation_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r1.chunks[0U], 4,
    &Controller_implementation_B.r17.chunks[0U], 2);

  /* Start for MATLABSystem: '<S5>/Barometer' */
  sMultiWordShr(&Controller_implementation_B.r17.chunks[0U], 2, 12U,
                &Controller_implementation_B.r16.chunks[0U], 2);
  sLong2MultiWord(obj->dig_T3, &Controller_implementation_B.r17.chunks[0U], 2);
  sMultiWordMul(&Controller_implementation_B.r16.chunks[0U], 2,
                &Controller_implementation_B.r17.chunks[0U], 2,
                &Controller_implementation_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r.chunks[0U], 4,
    &Controller_implementation_B.r15.chunks[0U], 2);

  /* Start for MATLABSystem: '<S5>/Barometer' */
  sMultiWordShr(&Controller_implementation_B.r15.chunks[0U], 2, 14U,
                &Controller_implementation_B.r14.chunks[0U], 2);
  sMultiWord2MultiWord(&Controller_implementation_B.r14.chunks[0U], 2,
                       &Controller_implementation_B.r9.chunks[0U], 3);
  MultiWordAdd(&Controller_implementation_B.r8.chunks[0U],
               &Controller_implementation_B.r9.chunks[0U],
               &Controller_implementation_B.r7.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r7.chunks[0U], 3,
    &Controller_implementation_B.r13.chunks[0U], 2);
  sMultiWord2MultiWord(&Controller_implementation_B.r13.chunks[0U], 2,
                       &Controller_implementation_B.r6.chunks[0U], 3);
  Controller_implementation_B.r13 = tmp_0;
  sMultiWord2MultiWord(&tmp_0.chunks[0U], 2,
                       &Controller_implementation_B.r7.chunks[0U], 3);
  MultiWordSub(&Controller_implementation_B.r6.chunks[0U],
               &Controller_implementation_B.r7.chunks[0U],
               &Controller_implementation_B.r5.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r5.chunks[0U], 3,
    &Controller_implementation_B.val1.chunks[0U], 2);
  sMultiWordMul(&Controller_implementation_B.val1.chunks[0U], 2,
                &Controller_implementation_B.val1.chunks[0U], 2,
                &Controller_implementation_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r1.chunks[0U], 4,
    &Controller_implementation_B.r14.chunks[0U], 2);

  /* Start for MATLABSystem: '<S5>/Barometer' */
  sLong2MultiWord(obj->dig_P6, &Controller_implementation_B.r15.chunks[0U], 2);
  sMultiWordMul(&Controller_implementation_B.r14.chunks[0U], 2,
                &Controller_implementation_B.r15.chunks[0U], 2,
                &Controller_implementation_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r.chunks[0U], 4,
    &Controller_implementation_B.r13.chunks[0U], 2);
  sMultiWord2MultiWord(&Controller_implementation_B.r13.chunks[0U], 2,
                       &Controller_implementation_B.r6.chunks[0U], 3);

  /* Start for MATLABSystem: '<S5>/Barometer' */
  sLong2MultiWord(obj->dig_P5, &Controller_implementation_B.r15.chunks[0U], 2);
  sMultiWordMul(&Controller_implementation_B.val1.chunks[0U], 2,
                &Controller_implementation_B.r15.chunks[0U], 2,
                &Controller_implementation_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r.chunks[0U], 4,
    &Controller_implementation_B.r14.chunks[0U], 2);

  /* Start for MATLABSystem: '<S5>/Barometer' */
  sMultiWordShl(&Controller_implementation_B.r14.chunks[0U], 2, 17U,
                &Controller_implementation_B.r13.chunks[0U], 2);
  sMultiWord2MultiWord(&Controller_implementation_B.r13.chunks[0U], 2,
                       &Controller_implementation_B.r7.chunks[0U], 3);
  MultiWordAdd(&Controller_implementation_B.r6.chunks[0U],
               &Controller_implementation_B.r7.chunks[0U],
               &Controller_implementation_B.r5.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r5.chunks[0U], 3,
    &Controller_implementation_B.val4.chunks[0U], 2);

  /* Start for MATLABSystem: '<S5>/Barometer' */
  Controller_implementation_B.r15 = tmp;
  sMultiWord2MultiWord(&tmp.chunks[0U], 2,
                       &Controller_implementation_B.r6.chunks[0U], 3);
  sMultiWordMul(&Controller_implementation_B.val1.chunks[0U], 2,
                &Controller_implementation_B.val1.chunks[0U], 2,
                &Controller_implementation_B.r2.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r2.chunks[0U], 4,
    &Controller_implementation_B.r18.chunks[0U], 2);

  /* Start for MATLABSystem: '<S5>/Barometer' */
  sLong2MultiWord(obj->dig_P3, &Controller_implementation_B.r19.chunks[0U], 2);
  sMultiWordMul(&Controller_implementation_B.r18.chunks[0U], 2,
                &Controller_implementation_B.r19.chunks[0U], 2,
                &Controller_implementation_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r1.chunks[0U], 4,
    &Controller_implementation_B.r17.chunks[0U], 2);

  /* Start for MATLABSystem: '<S5>/Barometer' */
  sMultiWordShr(&Controller_implementation_B.r17.chunks[0U], 2, 8U,
                &Controller_implementation_B.r16.chunks[0U], 2);
  sMultiWord2MultiWord(&Controller_implementation_B.r16.chunks[0U], 2,
                       &Controller_implementation_B.r9.chunks[0U], 3);
  sLong2MultiWord(obj->dig_P2, &Controller_implementation_B.r18.chunks[0U], 2);
  sMultiWordMul(&Controller_implementation_B.val1.chunks[0U], 2,
                &Controller_implementation_B.r18.chunks[0U], 2,
                &Controller_implementation_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r1.chunks[0U], 4,
    &Controller_implementation_B.r17.chunks[0U], 2);

  /* Start for MATLABSystem: '<S5>/Barometer' */
  sMultiWordShl(&Controller_implementation_B.r17.chunks[0U], 2, 12U,
                &Controller_implementation_B.r16.chunks[0U], 2);
  sMultiWord2MultiWord(&Controller_implementation_B.r16.chunks[0U], 2,
                       &Controller_implementation_B.r10.chunks[0U], 3);
  MultiWordAdd(&Controller_implementation_B.r9.chunks[0U],
               &Controller_implementation_B.r10.chunks[0U],
               &Controller_implementation_B.r8.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r8.chunks[0U], 3,
    &Controller_implementation_B.r15.chunks[0U], 2);
  sMultiWord2MultiWord(&Controller_implementation_B.r15.chunks[0U], 2,
                       &Controller_implementation_B.r7.chunks[0U], 3);
  MultiWordAdd(&Controller_implementation_B.r6.chunks[0U],
               &Controller_implementation_B.r7.chunks[0U],
               &Controller_implementation_B.r5.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r5.chunks[0U], 3,
    &Controller_implementation_B.r14.chunks[0U], 2);

  /* Start for MATLABSystem: '<S5>/Barometer' */
  uLong2MultiWord(obj->dig_P1, &Controller_implementation_B.r15.chunks[0U], 2);
  sMultiWordMul(&Controller_implementation_B.r14.chunks[0U], 2,
                &Controller_implementation_B.r15.chunks[0U], 2,
                &Controller_implementation_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&Controller_implementation_B.r.chunks[0U], 4,
    &Controller_implementation_B.r13.chunks[0U], 2);

  /* Start for MATLABSystem: '<S5>/Barometer' */
  sMultiWordShr(&Controller_implementation_B.r13.chunks[0U], 2, 33U,
                &Controller_implementation_B.val1.chunks[0U], 2);
  if (sMultiWordEq(&Controller_implementation_B.val1.chunks[0U], &tmp_2.chunks
                   [0U], 2)) {
    y = 0.0;
  } else {
    sLong2MultiWord(1048576 - (data[0] << 12 | data[1] << 4 | data[2] >> 4),
                    &Controller_implementation_B.r17.chunks[0U], 2);
    sMultiWordShl(&Controller_implementation_B.r17.chunks[0U], 2, 31U,
                  &Controller_implementation_B.r16.chunks[0U], 2);
    sMultiWord2MultiWord(&Controller_implementation_B.r16.chunks[0U], 2,
                         &Controller_implementation_B.r7.chunks[0U], 3);
    sMultiWord2MultiWord(&Controller_implementation_B.val4.chunks[0U], 2,
                         &Controller_implementation_B.r10.chunks[0U], 3);
    sLong2MultiWord(obj->dig_P4, &Controller_implementation_B.r18.chunks[0U], 2);
    sMultiWordShl(&Controller_implementation_B.r18.chunks[0U], 2, 35U,
                  &Controller_implementation_B.r17.chunks[0U], 2);
    sMultiWord2MultiWord(&Controller_implementation_B.r17.chunks[0U], 2,
                         &Controller_implementation_B.r11.chunks[0U], 3);
    MultiWordAdd(&Controller_implementation_B.r10.chunks[0U],
                 &Controller_implementation_B.r11.chunks[0U],
                 &Controller_implementation_B.r9.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&Controller_implementation_B.r9.chunks[0U], 3,
      &Controller_implementation_B.r16.chunks[0U], 2);
    sMultiWord2MultiWord(&Controller_implementation_B.r16.chunks[0U], 2,
                         &Controller_implementation_B.r8.chunks[0U], 3);
    MultiWordSub(&Controller_implementation_B.r7.chunks[0U],
                 &Controller_implementation_B.r8.chunks[0U],
                 &Controller_implementation_B.r6.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&Controller_implementation_B.r6.chunks[0U], 3,
      &Controller_implementation_B.r15.chunks[0U], 2);
    Controller_implementation_B.r16 = tmp_1;
    sMultiWordMul(&Controller_implementation_B.r15.chunks[0U], 2, &tmp_1.chunks
                  [0U], 2, &Controller_implementation_B.r5.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&Controller_implementation_B.r5.chunks[0U], 3,
      &Controller_implementation_B.r14.chunks[0U], 2);
    Controller_implementation_B.val1 = Controller_implementati_i64ddiv
      (sMultiWord2Double(&Controller_implementation_B.r14.chunks[0U], 2, 0),
       Controller_implementation_B.val1);
    sMultiWord2MultiWord(&Controller_implementation_B.val1.chunks[0U], 2,
                         &Controller_implementation_B.r10.chunks[0U], 3);
    sLong2MultiWord(obj->dig_P9, &Controller_implementation_B.r21.chunks[0U], 2);
    sMultiWordShr(&Controller_implementation_B.val1.chunks[0U], 2, 13U,
                  &Controller_implementation_B.r23.chunks[0U], 2);
    sMultiWordShr(&Controller_implementation_B.val1.chunks[0U], 2, 13U,
                  &Controller_implementation_B.r24.chunks[0U], 2);
    sMultiWordMul(&Controller_implementation_B.r23.chunks[0U], 2,
                  &Controller_implementation_B.r24.chunks[0U], 2,
                  &Controller_implementation_B.r1.chunks[0U], 4);
    sMultiWord2sMultiWordSat(&Controller_implementation_B.r1.chunks[0U], 4,
      &Controller_implementation_B.r22.chunks[0U], 2);
    sMultiWordMul(&Controller_implementation_B.r21.chunks[0U], 2,
                  &Controller_implementation_B.r22.chunks[0U], 2,
                  &Controller_implementation_B.r.chunks[0U], 4);
    sMultiWord2sMultiWordSat(&Controller_implementation_B.r.chunks[0U], 4,
      &Controller_implementation_B.r20.chunks[0U], 2);
    sMultiWordShr(&Controller_implementation_B.r20.chunks[0U], 2, 25U,
                  &Controller_implementation_B.r19.chunks[0U], 2);
    sMultiWord2MultiWord(&Controller_implementation_B.r19.chunks[0U], 2,
                         &Controller_implementation_B.r11.chunks[0U], 3);
    MultiWordAdd(&Controller_implementation_B.r10.chunks[0U],
                 &Controller_implementation_B.r11.chunks[0U],
                 &Controller_implementation_B.r9.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&Controller_implementation_B.r9.chunks[0U], 3,
      &Controller_implementation_B.r18.chunks[0U], 2);
    sMultiWord2MultiWord(&Controller_implementation_B.r18.chunks[0U], 2,
                         &Controller_implementation_B.r8.chunks[0U], 3);
    Controller_implementation_B.r19 = Controller_implementation_times((real_T)
      obj->dig_P8, Controller_implementation_B.val1);
    sMultiWordShr(&Controller_implementation_B.r19.chunks[0U], 2, 19U,
                  &Controller_implementation_B.r18.chunks[0U], 2);
    sMultiWord2MultiWord(&Controller_implementation_B.r18.chunks[0U], 2,
                         &Controller_implementation_B.r9.chunks[0U], 3);
    MultiWordAdd(&Controller_implementation_B.r8.chunks[0U],
                 &Controller_implementation_B.r9.chunks[0U],
                 &Controller_implementation_B.r7.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&Controller_implementation_B.r7.chunks[0U], 3,
      &Controller_implementation_B.r17.chunks[0U], 2);
    sMultiWordShr(&Controller_implementation_B.r17.chunks[0U], 2, 8U,
                  &Controller_implementation_B.r16.chunks[0U], 2);
    sMultiWord2MultiWord(&Controller_implementation_B.r16.chunks[0U], 2,
                         &Controller_implementation_B.r6.chunks[0U], 3);
    sLong2MultiWord(obj->dig_P7, &Controller_implementation_B.r17.chunks[0U], 2);
    sMultiWordShl(&Controller_implementation_B.r17.chunks[0U], 2, 4U,
                  &Controller_implementation_B.r16.chunks[0U], 2);
    sMultiWord2MultiWord(&Controller_implementation_B.r16.chunks[0U], 2,
                         &Controller_implementation_B.r7.chunks[0U], 3);
    MultiWordAdd(&Controller_implementation_B.r6.chunks[0U],
                 &Controller_implementation_B.r7.chunks[0U],
                 &Controller_implementation_B.r5.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&Controller_implementation_B.r5.chunks[0U], 3,
      &Controller_implementation_B.r15.chunks[0U], 2);
    y = sMultiWord2Double(&Controller_implementation_B.r15.chunks[0U], 2, 0) /
      256.0;
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T tmp;
  int32_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static beagleboneblue_bbblueBaromete_T *bbblueBarometer_bbblueBarometer
  (beagleboneblue_bbblueBaromete_T *obj)
{
  beagleboneblue_bbblueBaromete_T *b_obj;

  /* Start for MATLABSystem: '<S5>/Barometer' */
  obj->dig_T1 = 0U;
  obj->dig_T2 = 0;
  obj->dig_T3 = 0;
  obj->dig_P1 = 0U;
  obj->dig_P2 = 0;
  obj->dig_P3 = 0;
  obj->dig_P4 = 0;
  obj->dig_P5 = 0;
  obj->dig_P6 = 0;
  obj->dig_P7 = 0;
  obj->dig_P8 = 0;
  obj->dig_P9 = 0;
  obj->isInitialized = 0;
  obj->SampleTime = -1.0;
  b_obj = obj;
  obj->i2cObj.DefaultMaximumBusSpeedInHz = 400000.0;
  obj->i2cObj.isInitialized = 0;
  obj->i2cObj.matlabCodegenIsDeleted = false;
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static void Controller_imp_SystemCore_setup(beagleboneblue_bbblueBaromete_T *obj)
{
  int32_T i;
  uint16_T c;
  uint8_T output_raw[24];
  uint8_T SwappedDataBytes[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T SwappedDataBytes_0;
  uint8_T regVal;
  uint8_T status;

  /* Start for MATLABSystem: '<S5>/Barometer' */
  obj->isInitialized = 1;
  obj->i2cObj.MW_I2C_HANDLE = MW_I2C_Open(2, MW_I2C_MASTER);
  obj->i2cObj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObj.MW_I2C_HANDLE, obj->i2cObj.BusSpeed);
  regVal = 182U;

  /* Start for MATLABSystem: '<S5>/Barometer' */
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&regVal, (size_t)1 * sizeof
         (uint8_T));
  b_SwappedDataBytes[0] = 224U;

  /* Start for MATLABSystem: '<S5>/Barometer' */
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)2
         * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U, &SwappedDataBytes[0], 2U,
                     false, false);
  MW_usleep(1000);
  status = 208U;

  /* Start for MATLABSystem: '<S5>/Barometer' */
  memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
         (uint8_T));
  status = MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U,
    &SwappedDataBytes_0, 1U, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj->i2cObj.MW_I2C_HANDLE, 118U, &status, 1U, false, true);
    memcpy((void *)&regVal, (void *)&status, (size_t)1 * sizeof(uint8_T));
  } else {
    regVal = 0U;
  }

  obj->BMPConnect = (regVal == 88);
  if (obj->BMPConnect) {
    MW_usleep(150);
    regVal = 39U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regVal, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 244U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U, &SwappedDataBytes[0], 2U,
                       false, false);
    MW_usleep(150);
    regVal = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regVal, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 245U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U, &SwappedDataBytes[0], 2U,
                       false, false);
    MW_usleep(150);
    regVal = 1U;
    while ((regVal & 1U) != 0U) {
      MW_usleep(20000);
      status = 243U;
      memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
             (uint8_T));
      status = MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U,
        &SwappedDataBytes_0, 1U, true, false);
      if (status == 0) {
        MW_I2C_MasterRead(obj->i2cObj.MW_I2C_HANDLE, 118U, &status, 1U, false,
                          true);
        memcpy((void *)&regVal, (void *)&status, (size_t)1 * sizeof(uint8_T));
      } else {
        regVal = 0U;
      }
    }

    status = 136U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U,
      &SwappedDataBytes_0, 1U, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObj.MW_I2C_HANDLE, 118U, &output_raw[0], 24U,
                        false, true);
      memcpy((void *)&Controller_implementation_B.b_output[0], (void *)
             &output_raw[0], (size_t)24 * sizeof(uint8_T));
    } else {
      for (i = 0; i < 24; i++) {
        Controller_implementation_B.b_output[i] = 0U;
      }
    }

    obj->dig_T1 = (uint16_T)(Controller_implementation_B.b_output[1] << 8 |
      Controller_implementation_B.b_output[0]);
    c = (uint16_T)(Controller_implementation_B.b_output[3] << 8 |
                   Controller_implementation_B.b_output[2]);
    memcpy((void *)&obj->dig_T2, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(Controller_implementation_B.b_output[5] << 8 |
                   Controller_implementation_B.b_output[4]);
    memcpy((void *)&obj->dig_T3, (void *)&c, (size_t)1 * sizeof(int16_T));
    obj->dig_P1 = (uint16_T)(Controller_implementation_B.b_output[7] << 8 |
      Controller_implementation_B.b_output[6]);
    c = (uint16_T)(Controller_implementation_B.b_output[9] << 8 |
                   Controller_implementation_B.b_output[8]);
    memcpy((void *)&obj->dig_P2, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(Controller_implementation_B.b_output[11] << 8 |
                   Controller_implementation_B.b_output[10]);
    memcpy((void *)&obj->dig_P3, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(Controller_implementation_B.b_output[13] << 8 |
                   Controller_implementation_B.b_output[12]);
    memcpy((void *)&obj->dig_P4, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(Controller_implementation_B.b_output[15] << 8 |
                   Controller_implementation_B.b_output[14]);
    memcpy((void *)&obj->dig_P5, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(Controller_implementation_B.b_output[17] << 8 |
                   Controller_implementation_B.b_output[16]);
    memcpy((void *)&obj->dig_P6, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(Controller_implementation_B.b_output[19] << 8 |
                   Controller_implementation_B.b_output[18]);
    memcpy((void *)&obj->dig_P7, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(Controller_implementation_B.b_output[21] << 8 |
                   Controller_implementation_B.b_output[20]);
    memcpy((void *)&obj->dig_P8, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(Controller_implementation_B.b_output[23] << 8 |
                   Controller_implementation_B.b_output[22]);
    memcpy((void *)&obj->dig_P9, (void *)&c, (size_t)1 * sizeof(int16_T));
  }
}

static void Controller__SystemCore_setup_p5(dsp_simulink_MovingAverage_Co_T *obj)
{
  real_T varargin_2;
  boolean_T flag;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;

  /* Start for MATLABSystem: '<S67>/Moving Average' incorporates:
   *  MATLABSystem: '<S68>/Moving Average'
   */
  obj->NumChannels = 1;
  obj->FrameLength = 1;
  varargin_2 = obj->ForgettingFactor;
  obj->_pobj0.isInitialized = 0;
  obj->_pobj0.isInitialized = 0;
  flag = (obj->_pobj0.isInitialized == 1);
  if (flag) {
    /* Start for MATLABSystem: '<S67>/Moving Average' incorporates:
     *  MATLABSystem: '<S68>/Moving Average'
     */
    obj->_pobj0.TunablePropsChanged = true;
  }

  /* Start for MATLABSystem: '<S67>/Moving Average' incorporates:
   *  MATLABSystem: '<S68>/Moving Average'
   */
  obj->_pobj0.ForgettingFactor = varargin_2;
  obj->pStatistic = &obj->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

static void Controller_i_SystemCore_setup_p(beagleboneblue_bbblueMPU9250__T *obj)
{
  /* Start for MATLABSystem: '<S5>/MPU9250' */
  obj->isInitialized = 1;
  MW_IMU_DMP_isAccel_Calibrated();
  MW_IMU_DMP_isGyro_Calibrated();
  MW_IMU_DMP_isMag_Calibrated();

  /* Start for MATLABSystem: '<S5>/MPU9250' */
  obj->i2cObjmpu.MW_I2C_HANDLE = MW_I2C_Open(2, MW_I2C_MASTER);
  obj->i2cObjmpu.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObjmpu.MW_I2C_HANDLE, obj->i2cObjmpu.BusSpeed);
  obj->i2cObjak8963.MW_I2C_HANDLE = MW_I2C_Open(2, MW_I2C_MASTER);
  obj->i2cObjak8963.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObjak8963.MW_I2C_HANDLE, obj->i2cObjak8963.BusSpeed);
  MW_Init_IMU_DMP(200);
  obj->TunablePropsChanged = false;
}

/* Model step function for TID0 */
void Controller_implementation_step0(void) /* Sample time: [0.0s, 0.0s] */
{
  int32_T i;
  int32_T i_0;
  boolean_T flag;
  ZCEventType zcEvent;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Controller_implementation_DW.MeasurementUpdate_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Controller_implementation_DW.EnabledSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Controller_implementation_DW.SampleandHold_SubsysRanBC_k);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Controller_implementation_DW.SampleandHold3_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Controller_implementation_DW.SampleandHold_SubsysRanBC);

  /* MATLABSystem: '<S5>/Barometer' */
  if (Controller_implementation_DW.obj_j.SampleTime !=
      Controller_implementation_P.Ts) {
    Controller_implementation_DW.obj_j.SampleTime =
      Controller_implementation_P.Ts;
  }

  Controller_implementation_B.d = Contro_bbblueBarometer_stepImpl
    (&Controller_implementation_DW.obj_j);

  /* MATLABSystem: '<S67>/Moving Average' incorporates:
   *  MATLABSystem: '<S5>/Barometer'
   */
  if (Controller_implementation_DW.obj_m.ForgettingFactor !=
      Controller_implementation_P.MovingAverage_ForgettingFactor) {
    if (Controller_implementation_DW.obj_m.isInitialized == 1) {
      Controller_implementation_DW.obj_m.TunablePropsChanged = true;
    }

    Controller_implementation_DW.obj_m.ForgettingFactor =
      Controller_implementation_P.MovingAverage_ForgettingFactor;
  }

  if (Controller_implementation_DW.obj_m.TunablePropsChanged) {
    Controller_implementation_DW.obj_m.TunablePropsChanged = false;
    flag = (Controller_implementation_DW.obj_m.pStatistic->isInitialized == 1);
    if (flag) {
      Controller_implementation_DW.obj_m.pStatistic->TunablePropsChanged = true;
    }

    Controller_implementation_DW.obj_m.pStatistic->ForgettingFactor =
      Controller_implementation_DW.obj_m.ForgettingFactor;
  }

  if (Controller_implementation_DW.obj_m.pStatistic->isInitialized != 1) {
    Controller_implementation_DW.obj_m.pStatistic->isSetupComplete = false;
    Controller_implementation_DW.obj_m.pStatistic->isInitialized = 1;
    Controller_implementation_DW.obj_m.pStatistic->pwN = 1.0;
    Controller_implementation_DW.obj_m.pStatistic->pmN = 0.0;
    Controller_implementation_DW.obj_m.pStatistic->plambda =
      Controller_implementation_DW.obj_m.pStatistic->ForgettingFactor;
    Controller_implementation_DW.obj_m.pStatistic->isSetupComplete = true;
    Controller_implementation_DW.obj_m.pStatistic->TunablePropsChanged = false;
    Controller_implementation_DW.obj_m.pStatistic->pwN = 1.0;
    Controller_implementation_DW.obj_m.pStatistic->pmN = 0.0;
  }

  if (Controller_implementation_DW.obj_m.pStatistic->TunablePropsChanged) {
    Controller_implementation_DW.obj_m.pStatistic->TunablePropsChanged = false;
    Controller_implementation_DW.obj_m.pStatistic->plambda =
      Controller_implementation_DW.obj_m.pStatistic->ForgettingFactor;
  }

  Controller_implementation_B.pwLocal =
    Controller_implementation_DW.obj_m.pStatistic->pwN;
  Controller_implementation_B.max_possible_rot_speed =
    Controller_implementation_DW.obj_m.pStatistic->pmN;
  Controller_implementation_B.lambda =
    Controller_implementation_DW.obj_m.pStatistic->plambda;
  Controller_implementation_B.max_possible_rot_speed = (1.0 - 1.0 /
    Controller_implementation_B.pwLocal) *
    Controller_implementation_B.max_possible_rot_speed + 1.0 /
    Controller_implementation_B.pwLocal * Controller_implementation_B.d;
  Controller_implementation_DW.obj_m.pStatistic->pwN =
    Controller_implementation_B.lambda * Controller_implementation_B.pwLocal +
    1.0;
  Controller_implementation_DW.obj_m.pStatistic->pmN =
    Controller_implementation_B.max_possible_rot_speed;

  /* Step: '<S67>/Step3' */
  if (((Controller_implementation_M->Timing.clockTick1) * 0.01) <
      Controller_implementation_P.Step3_Time) {
    Controller_implementation_B.pwLocal = Controller_implementation_P.Step3_Y0;
  } else {
    Controller_implementation_B.pwLocal =
      Controller_implementation_P.Step3_YFinal;
  }

  /* Outputs for Triggered SubSystem: '<S67>/Sample and Hold3' incorporates:
   *  TriggerPort: '<S73>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &Controller_implementati_PrevZCX.SampleandHold3_Trig_ZCE,
                     (Controller_implementation_B.pwLocal));

  /* End of Step: '<S67>/Step3' */
  if (zcEvent != NO_ZCEVENT) {
    /* SignalConversion generated from: '<S73>/In' incorporates:
     *  MATLABSystem: '<S67>/Moving Average'
     * */
    Controller_implementation_B.In_c =
      Controller_implementation_B.max_possible_rot_speed;
    Controller_implementation_DW.SampleandHold3_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S67>/Sample and Hold3' */

  /* Sum: '<S67>/Add' incorporates:
   *  MATLABSystem: '<S5>/Barometer'
   */
  Controller_implementation_B.sensor = Controller_implementation_B.d -
    Controller_implementation_B.In_c;

  /* Clock: '<S67>/Clock1' incorporates:
   *  Clock: '<S3>/Clock1'
   */
  Controller_implementation_B.d = Controller_implementation_M->Timing.t[0];

  /* Switch: '<S67>/Switch' incorporates:
   *  Clock: '<S67>/Clock1'
   *  Constant: '<S72>/Constant'
   *  RelationalOperator: '<S72>/Compare'
   */
  if (Controller_implementation_B.d <=
      Controller_implementation_P.CompareToConstant_const) {
    /* Switch: '<S67>/Switch' incorporates:
     *  Constant: '<S67>/Constant'
     */
    Controller_implementation_B.Switch =
      Controller_implementation_P.Constant_Value;
  } else {
    /* Switch: '<S67>/Switch' incorporates:
     *  MATLAB Function: '<S67>/height'
     */
    Controller_implementation_B.Switch = -(Controller_implementation_B.sensor /
      Controller_implementation_B.In_c) * 8430.0;
  }

  /* End of Switch: '<S67>/Switch' */

  /* MATLABSystem: '<S5>/MPU9250' */
  if (Controller_implementation_DW.obj_n.SampleTime !=
      Controller_implementation_P.Ts) {
    Controller_implementation_DW.obj_n.SampleTime =
      Controller_implementation_P.Ts;
  }

  if (Controller_implementation_DW.obj_n.TunablePropsChanged) {
    Controller_implementation_DW.obj_n.TunablePropsChanged = false;
  }

  MW_Read_Accel(&Controller_implementation_B.rtb_MPU9250_o1_m[0]);
  Controller_implementation_B.Gain1[0] = 0.0;
  Controller_implementation_B.Gain1[1] = 0.0;
  Controller_implementation_B.Gain1[2] = 0.0;
  MW_Read_Gyro(&Controller_implementation_B.Gain1[0]);
  Controller_implementation_B.mdata[0] = 0.0;
  Controller_implementation_B.mdata[1] = 0.0;
  Controller_implementation_B.mdata[2] = 0.0;
  MW_Read_Mag(&Controller_implementation_B.mdata[0]);

  /* MATLAB Function: '<S5>/roll ' incorporates:
   *  MATLABSystem: '<S5>/MPU9250'
   */
  Controller_implementation_B.roll =
    Controller_implementation_B.rtb_MPU9250_o1_m[1] /
    Controller_implementation_B.rtb_MPU9250_o1_m[2];
  Controller_implementation_B.roll = atan(Controller_implementation_B.roll);

  /* MATLAB Function: '<S5>/pitch' incorporates:
   *  MATLAB Function: '<S5>/yaw'
   *  MATLABSystem: '<S5>/MPU9250'
   */
  Controller_implementation_B.yaw = sin(Controller_implementation_B.roll);
  Controller_implementation_B.max_possible_rot_speed = cos
    (Controller_implementation_B.roll);
  Controller_implementation_B.pitch =
    -Controller_implementation_B.rtb_MPU9250_o1_m[0] /
    (Controller_implementation_B.rtb_MPU9250_o1_m[1] *
     Controller_implementation_B.yaw +
     Controller_implementation_B.rtb_MPU9250_o1_m[2] *
     Controller_implementation_B.max_possible_rot_speed);
  Controller_implementation_B.pitch = atan(Controller_implementation_B.pitch);

  /* MATLAB Function: '<S5>/yaw' incorporates:
   *  MATLABSystem: '<S5>/MPU9250'
   * */
  Controller_implementation_B.yaw = rt_atan2d_snf
    (Controller_implementation_B.mdata[2] * Controller_implementation_B.yaw -
     Controller_implementation_B.mdata[1] *
     Controller_implementation_B.max_possible_rot_speed,
     (Controller_implementation_B.mdata[1] * Controller_implementation_B.yaw +
      Controller_implementation_B.mdata[2] *
      Controller_implementation_B.max_possible_rot_speed) * sin
     (Controller_implementation_B.pitch) + Controller_implementation_B.mdata[0] *
     cos(Controller_implementation_B.pitch));

  /* MATLABSystem: '<S68>/Moving Average' */
  if (Controller_implementation_DW.obj.ForgettingFactor !=
      Controller_implementation_P.MovingAverage_ForgettingFacto_c) {
    if (Controller_implementation_DW.obj.isInitialized == 1) {
      Controller_implementation_DW.obj.TunablePropsChanged = true;
    }

    Controller_implementation_DW.obj.ForgettingFactor =
      Controller_implementation_P.MovingAverage_ForgettingFacto_c;
  }

  if (Controller_implementation_DW.obj.TunablePropsChanged) {
    Controller_implementation_DW.obj.TunablePropsChanged = false;
    flag = (Controller_implementation_DW.obj.pStatistic->isInitialized == 1);
    if (flag) {
      Controller_implementation_DW.obj.pStatistic->TunablePropsChanged = true;
    }

    Controller_implementation_DW.obj.pStatistic->ForgettingFactor =
      Controller_implementation_DW.obj.ForgettingFactor;
  }

  if (Controller_implementation_DW.obj.pStatistic->isInitialized != 1) {
    Controller_implementation_DW.obj.pStatistic->isSetupComplete = false;
    Controller_implementation_DW.obj.pStatistic->isInitialized = 1;
    Controller_implementation_DW.obj.pStatistic->pwN = 1.0;
    Controller_implementation_DW.obj.pStatistic->pmN = 0.0;
    Controller_implementation_DW.obj.pStatistic->plambda =
      Controller_implementation_DW.obj.pStatistic->ForgettingFactor;
    Controller_implementation_DW.obj.pStatistic->isSetupComplete = true;
    Controller_implementation_DW.obj.pStatistic->TunablePropsChanged = false;
    Controller_implementation_DW.obj.pStatistic->pwN = 1.0;
    Controller_implementation_DW.obj.pStatistic->pmN = 0.0;
  }

  if (Controller_implementation_DW.obj.pStatistic->TunablePropsChanged) {
    Controller_implementation_DW.obj.pStatistic->TunablePropsChanged = false;
    Controller_implementation_DW.obj.pStatistic->plambda =
      Controller_implementation_DW.obj.pStatistic->ForgettingFactor;
  }

  Controller_implementation_B.pwLocal =
    Controller_implementation_DW.obj.pStatistic->pwN;
  Controller_implementation_B.max_possible_rot_speed =
    Controller_implementation_DW.obj.pStatistic->pmN;
  Controller_implementation_B.lambda =
    Controller_implementation_DW.obj.pStatistic->plambda;
  Controller_implementation_B.max_possible_rot_speed = (1.0 - 1.0 /
    Controller_implementation_B.pwLocal) *
    Controller_implementation_B.max_possible_rot_speed + 1.0 /
    Controller_implementation_B.pwLocal * Controller_implementation_B.yaw;
  Controller_implementation_DW.obj.pStatistic->pwN =
    Controller_implementation_B.lambda * Controller_implementation_B.pwLocal +
    1.0;
  Controller_implementation_DW.obj.pStatistic->pmN =
    Controller_implementation_B.max_possible_rot_speed;

  /* Step: '<S68>/Step' incorporates:
   *  Step: '<S1>/Step'
   */
  Controller_implementation_B.pwLocal = Controller_implementation_M->Timing.t[0];
  if (Controller_implementation_B.pwLocal <
      Controller_implementation_P.Step_Time) {
    Controller_implementation_B.lambda = Controller_implementation_P.Step_Y0;
  } else {
    Controller_implementation_B.lambda = Controller_implementation_P.Step_YFinal;
  }

  /* Outputs for Triggered SubSystem: '<S68>/Sample and Hold' incorporates:
   *  TriggerPort: '<S75>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &Controller_implementati_PrevZCX.SampleandHold_Trig_ZCE,
                     (Controller_implementation_B.lambda));

  /* End of Step: '<S68>/Step' */
  if (zcEvent != NO_ZCEVENT) {
    /* SignalConversion generated from: '<S75>/In' incorporates:
     *  MATLABSystem: '<S68>/Moving Average'
     * */
    Controller_implementation_B.In =
      Controller_implementation_B.max_possible_rot_speed;
    Controller_implementation_DW.SampleandHold_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S68>/Sample and Hold' */

  /* Gain: '<S68>/Gain' incorporates:
   *  Sum: '<S68>/Sum'
   */
  Controller_implementation_B.Gain = (Controller_implementation_B.yaw -
    Controller_implementation_B.In) * Controller_implementation_P.Gain_Gain;

  /* Gain: '<S66>/Gain1' incorporates:
   *  MATLABSystem: '<S5>/MPU9250'
   */
  Controller_implementation_B.Gain1[0] *= Controller_implementation_P.Gain1_Gain;
  Controller_implementation_B.Gain1[1] *= Controller_implementation_P.Gain1_Gain;
  Controller_implementation_B.Gain1[2] *= Controller_implementation_P.Gain1_Gain;

  /* Step: '<S1>/Step' */
  if (Controller_implementation_B.pwLocal <
      Controller_implementation_P.Step_Time_a) {
    Controller_implementation_B.pwLocal = Controller_implementation_P.Step_Y0_h;
  } else {
    Controller_implementation_B.pwLocal =
      Controller_implementation_P.Step_YFinal_b;
  }

  /* Outputs for Triggered SubSystem: '<S1>/Sample and Hold' incorporates:
   *  TriggerPort: '<S8>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &Controller_implementati_PrevZCX.SampleandHold_Trig_ZCE_i,
                     (Controller_implementation_B.pwLocal));
  if (zcEvent != NO_ZCEVENT) {
    /* SignalConversion generated from: '<S8>/In' */
    Controller_implementation_B.In_ca[0] = Controller_implementation_B.Switch;
    Controller_implementation_B.In_ca[1] = Controller_implementation_B.roll;
    Controller_implementation_B.In_ca[2] = Controller_implementation_B.pitch;
    Controller_implementation_B.In_ca[3] = Controller_implementation_B.Gain;
    Controller_implementation_B.In_ca[4] = Controller_implementation_B.Gain1[0];
    Controller_implementation_B.In_ca[5] = Controller_implementation_B.Gain1[1];
    Controller_implementation_B.In_ca[6] = Controller_implementation_B.Gain1[2];
    Controller_implementation_DW.SampleandHold_SubsysRanBC_k = 4;
  }

  /* End of Outputs for SubSystem: '<S1>/Sample and Hold' */

  /* Delay: '<S7>/MemoryX' incorporates:
   *  Constant: '<S1>/Constant'
   *  SignalConversion generated from: '<S7>/MemoryX'
   */
  if (Controller_implementation_DW.icLoad) {
    Controller_implementation_DW.MemoryX_DSTATE[3] =
      Controller_implementation_P.Constant_Value_k;
    Controller_implementation_DW.MemoryX_DSTATE[4] =
      Controller_implementation_P.Constant_Value_k;
    Controller_implementation_DW.MemoryX_DSTATE[0] =
      Controller_implementation_B.In_ca[0];
    Controller_implementation_DW.MemoryX_DSTATE[5] =
      Controller_implementation_B.In_ca[4];
    Controller_implementation_DW.MemoryX_DSTATE[1] =
      Controller_implementation_B.In_ca[1];
    Controller_implementation_DW.MemoryX_DSTATE[6] =
      Controller_implementation_B.In_ca[5];
    Controller_implementation_DW.MemoryX_DSTATE[2] =
      Controller_implementation_B.In_ca[2];
    Controller_implementation_DW.MemoryX_DSTATE[7] =
      Controller_implementation_B.In_ca[6];
  }

  /* Outputs for Enabled SubSystem: '<S36>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S62>/Enable'
   */
  /* Constant: '<S7>/Enable' */
  if (Controller_implementation_P.Enable_Value) {
    Controller_implementation_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S62>/Product' incorporates:
     *  Constant: '<S7>/C'
     *  Delay: '<S7>/MemoryX'
     */
    for (i = 0; i < 7; i++) {
      Controller_implementation_B.yaw = 0.0;
      for (i_0 = 0; i_0 < 8; i_0++) {
        Controller_implementation_B.yaw += Controller_implementation_P.C_Value[7
          * i_0 + i] * Controller_implementation_DW.MemoryX_DSTATE[i_0];
      }

      Controller_implementation_B.Bkuk[i] = Controller_implementation_B.yaw;
    }

    /* End of Product: '<S62>/Product' */

    /* Sum: '<S62>/Add1' */
    Controller_implementation_B.dv[0] = Controller_implementation_B.Switch -
      Controller_implementation_B.Bkuk[0];
    Controller_implementation_B.dv[1] = Controller_implementation_B.roll -
      Controller_implementation_B.Bkuk[1];
    Controller_implementation_B.dv[2] = Controller_implementation_B.pitch -
      Controller_implementation_B.Bkuk[2];
    Controller_implementation_B.dv[3] = Controller_implementation_B.Gain -
      Controller_implementation_B.Bkuk[3];
    Controller_implementation_B.dv[4] = Controller_implementation_B.Gain1[0] -
      Controller_implementation_B.Bkuk[4];
    Controller_implementation_B.dv[5] = Controller_implementation_B.Gain1[1] -
      Controller_implementation_B.Bkuk[5];
    Controller_implementation_B.dv[6] = Controller_implementation_B.Gain1[2] -
      Controller_implementation_B.Bkuk[6];
    for (i = 0; i < 7; i++) {
      Controller_implementation_B.Bkuk[i] = Controller_implementation_B.dv[i];
    }

    /* End of Sum: '<S62>/Add1' */
    for (i = 0; i < 8; i++) {
      /* Product: '<S62>/Product2' incorporates:
       *  Constant: '<S9>/KalmanGainM'
       */
      Controller_implementation_B.yaw = 0.0;
      for (i_0 = 0; i_0 < 7; i_0++) {
        Controller_implementation_B.yaw +=
          Controller_implementation_P.KalmanGainM_Value[(i_0 << 3) + i] *
          Controller_implementation_B.Bkuk[i_0];
      }

      Controller_implementation_B.Product2[i] = Controller_implementation_B.yaw;

      /* End of Product: '<S62>/Product2' */
    }

    srUpdateBC(Controller_implementation_DW.EnabledSubsystem_SubsysRanBC);
  } else if (Controller_implementation_DW.EnabledSubsystem_MODE) {
    for (i = 0; i < 8; i++) {
      /* Disable for Product: '<S62>/Product2' incorporates:
       *  Outport: '<S62>/deltax'
       */
      Controller_implementation_B.Product2[i] =
        Controller_implementation_P.deltax_Y0;
    }

    Controller_implementation_DW.EnabledSubsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S36>/Enabled Subsystem' */
  for (i = 0; i < 8; i++) {
    /* Reshape: '<S7>/Reshapexhat' incorporates:
     *  Delay: '<S7>/MemoryX'
     *  Sum: '<S36>/Add'
     */
    Controller_implementation_B.yaw = Controller_implementation_B.Product2[i] +
      Controller_implementation_DW.MemoryX_DSTATE[i];
    Controller_implementation_B.Reshapexhat[i] = Controller_implementation_B.yaw;

    /* Sum: '<S2>/Sum' incorporates:
     *  Constant: '<S4>/Constant'
     */
    Controller_implementation_B.Bkuk[i] =
      Controller_implementation_P.Constant_Value_a[i] -
      Controller_implementation_B.yaw;
  }

  for (i = 0; i < 4; i++) {
    /* Gain: '<S2>/Gain' */
    Controller_implementation_B.yaw = 0.0;
    for (i_0 = 0; i_0 < 8; i_0++) {
      Controller_implementation_B.yaw +=
        Controller_implementation_P.K_D_LQR_reduced[(i_0 << 2) + i] *
        Controller_implementation_B.Bkuk[i_0];
    }

    Controller_implementation_B.Gain_f[i] = Controller_implementation_B.yaw;

    /* End of Gain: '<S2>/Gain' */
  }

  /* MATLAB Function: '<S64>/Calculate PWM' incorporates:
   *  Constant: '<S64>/Constant'
   *  Constant: '<S64>/Constant1'
   */
  Controller_implementation_B.max_possible_rot_speed =
    Controller_implementation_P.battery_voltage *
    Controller_implementation_P.KV_rating;

  /* Gain: '<S64>/Gain' */
  Controller_implementation_B.yaw = Controller_implementation_B.Gain_f[1];
  Controller_implementation_B.pwLocal = Controller_implementation_B.Gain_f[0];
  Controller_implementation_B.lambda = Controller_implementation_B.Gain_f[2];
  Controller_implementation_B.Gain_f_k = Controller_implementation_B.Gain_f[3];
  for (i = 0; i < 4; i++) {
    Controller_implementation_B.rtb_DersiredMotorThrusts_c =
      ((Controller_implementation_P.K_mm[i + 4] *
        Controller_implementation_B.yaw + Controller_implementation_P.K_mm[i] *
        Controller_implementation_B.pwLocal) +
       Controller_implementation_P.K_mm[i + 8] *
       Controller_implementation_B.lambda) + Controller_implementation_P.K_mm[i
      + 12] * Controller_implementation_B.Gain_f_k;

    /* MATLAB Function: '<S64>/Calculate PWM' incorporates:
     *  Constant: '<S64>/Constant2'
     */
    if (Controller_implementation_B.rtb_DersiredMotorThrusts_c > 0.0) {
      Controller_implementation_B.rtb_DersiredMotorThrusts_c = sqrt
        (Controller_implementation_B.rtb_DersiredMotorThrusts_c /
         Controller_implementation_P.lift_co);
    } else {
      Controller_implementation_B.rtb_DersiredMotorThrusts_c = 0.0;
    }

    Controller_implementation_B.rtb_DersiredMotorThrusts_c =
      Controller_implementation_B.rtb_DersiredMotorThrusts_c /
      Controller_implementation_B.max_possible_rot_speed * 100.0 + 40.0;

    /* Saturate: '<S3>/PWM limit' */
    if (Controller_implementation_B.rtb_DersiredMotorThrusts_c >
        Controller_implementation_P.PWMlimit_UpperSat) {
      /* Saturate: '<S3>/PWM limit' */
      Controller_implementation_B.rtb_DersiredMotorThrusts_c =
        Controller_implementation_P.PWMlimit_UpperSat;
    } else if (Controller_implementation_B.rtb_DersiredMotorThrusts_c <
               Controller_implementation_P.PWMlimit_LowerSat) {
      /* Saturate: '<S3>/PWM limit' */
      Controller_implementation_B.rtb_DersiredMotorThrusts_c =
        Controller_implementation_P.PWMlimit_LowerSat;
    }

    /* End of Saturate: '<S3>/PWM limit' */

    /* Saturate: '<S3>/PWM limit' */
    Controller_implementation_B.PWMlimit[i] =
      Controller_implementation_B.rtb_DersiredMotorThrusts_c;

    /* MATLAB Function: '<S76>/MATLAB Function' incorporates:
     *  Constant: '<S76>/Battery Voltage'
     *  Constant: '<S76>/Constant'
     *  Saturate: '<S3>/PWM limit'
     */
    Controller_implementation_B.rtb_DersiredMotorThrusts_c =
      (Controller_implementation_B.rtb_DersiredMotorThrusts_c - 40.0) / 100.0 *
      Controller_implementation_P.battery_voltage *
      Controller_implementation_P.KV_rating;

    /* Math: '<S76>/Square' */
    Controller_implementation_B.rtb_DersiredMotorThrusts_c *=
      Controller_implementation_B.rtb_DersiredMotorThrusts_c;

    /* Gain: '<S76>/Gain' incorporates:
     *  Math: '<S76>/Square'
     */
    Controller_implementation_B.req_rotorspeed[i] =
      Controller_implementation_P.lift_co *
      Controller_implementation_B.rtb_DersiredMotorThrusts_c;

    /* Gain: '<S76>/Sign Convention' incorporates:
     *  Gain: '<S76>/Gain1'
     *  Math: '<S76>/Square'
     */
    Controller_implementation_B.DersiredMotorThrusts[i] =
      Controller_implementation_P.drag_co *
      Controller_implementation_B.rtb_DersiredMotorThrusts_c *
      Controller_implementation_P.SignConvention_Gain[i];
  }

  /* End of Gain: '<S64>/Gain' */

  /* MATLAB Function: '<S6>/MATLAB Function' incorporates:
   *  Constant: '<S6>/Constant'
   *  Gain: '<S76>/Gain'
   */
  Controller_implementation_B.yaw = Controller_implementation_B.req_rotorspeed[0]
    + Controller_implementation_B.req_rotorspeed[1];
  Controller_implementation_B.U[1] = ((Controller_implementation_B.yaw -
    Controller_implementation_B.req_rotorspeed[2]) -
    Controller_implementation_B.req_rotorspeed[3]) *
    Controller_implementation_P.dis;
  Controller_implementation_B.U[2] = (Controller_implementation_B.yaw -
    (Controller_implementation_B.req_rotorspeed[2] +
     Controller_implementation_B.req_rotorspeed[3])) *
    Controller_implementation_P.dis;
  Controller_implementation_B.U[0] = (Controller_implementation_B.yaw +
    Controller_implementation_B.req_rotorspeed[2]) +
    Controller_implementation_B.req_rotorspeed[3];
  Controller_implementation_B.U[3] =
    ((Controller_implementation_B.DersiredMotorThrusts[0] +
      Controller_implementation_B.DersiredMotorThrusts[1]) +
     Controller_implementation_B.DersiredMotorThrusts[2]) +
    Controller_implementation_B.DersiredMotorThrusts[3];

  /* Sum: '<S6>/Sum' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  Controller_implementation_B.Sum[0] = Controller_implementation_B.U[0] +
    Controller_implementation_P.Constant1_Value[0];
  Controller_implementation_B.Sum[1] = Controller_implementation_B.U[1] +
    Controller_implementation_P.Constant1_Value[1];
  Controller_implementation_B.Sum[2] = Controller_implementation_B.U[2] +
    Controller_implementation_P.Constant1_Value[2];
  Controller_implementation_B.Sum[3] = Controller_implementation_B.U[3] +
    Controller_implementation_P.Constant1_Value[3];

  /* Outputs for Enabled SubSystem: '<S29>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S60>/Enable'
   */
  /* Constant: '<S7>/Enable' */
  if (Controller_implementation_P.Enable_Value) {
    Controller_implementation_DW.MeasurementUpdate_MODE = true;
    for (i = 0; i < 7; i++) {
      /* Product: '<S60>/C[k]*xhat[k|k-1]' incorporates:
       *  Constant: '<S7>/C'
       *  Delay: '<S7>/MemoryX'
       */
      Controller_implementation_B.yaw = 0.0;
      for (i_0 = 0; i_0 < 8; i_0++) {
        Controller_implementation_B.yaw += Controller_implementation_P.C_Value[7
          * i_0 + i] * Controller_implementation_DW.MemoryX_DSTATE[i_0];
      }

      /* Sum: '<S60>/Add1' incorporates:
       *  Constant: '<S7>/D'
       *  Product: '<S60>/C[k]*xhat[k|k-1]'
       *  Product: '<S60>/D[k]*u[k]'
       */
      Controller_implementation_B.Bkuk[i] =
        (((Controller_implementation_P.D_Value[i + 7] *
           Controller_implementation_B.Sum[1] +
           Controller_implementation_P.D_Value[i] *
           Controller_implementation_B.Sum[0]) +
          Controller_implementation_P.D_Value[i + 14] *
          Controller_implementation_B.Sum[2]) +
         Controller_implementation_P.D_Value[i + 21] *
         Controller_implementation_B.Sum[3]) + Controller_implementation_B.yaw;
    }

    /* Sum: '<S60>/Sum' */
    Controller_implementation_B.dv[0] = Controller_implementation_B.Switch -
      Controller_implementation_B.Bkuk[0];
    Controller_implementation_B.dv[1] = Controller_implementation_B.roll -
      Controller_implementation_B.Bkuk[1];
    Controller_implementation_B.dv[2] = Controller_implementation_B.pitch -
      Controller_implementation_B.Bkuk[2];
    Controller_implementation_B.dv[3] = Controller_implementation_B.Gain -
      Controller_implementation_B.Bkuk[3];
    Controller_implementation_B.dv[4] = Controller_implementation_B.Gain1[0] -
      Controller_implementation_B.Bkuk[4];
    Controller_implementation_B.dv[5] = Controller_implementation_B.Gain1[1] -
      Controller_implementation_B.Bkuk[5];
    Controller_implementation_B.dv[6] = Controller_implementation_B.Gain1[2] -
      Controller_implementation_B.Bkuk[6];
    for (i = 0; i < 7; i++) {
      Controller_implementation_B.Bkuk[i] = Controller_implementation_B.dv[i];
    }

    /* End of Sum: '<S60>/Sum' */
    for (i = 0; i < 8; i++) {
      /* Product: '<S60>/Product3' incorporates:
       *  Constant: '<S9>/KalmanGainL'
       */
      Controller_implementation_B.yaw = 0.0;
      for (i_0 = 0; i_0 < 7; i_0++) {
        Controller_implementation_B.yaw +=
          Controller_implementation_P.KalmanGainL_Value[(i_0 << 3) + i] *
          Controller_implementation_B.Bkuk[i_0];
      }

      Controller_implementation_B.Product3[i] = Controller_implementation_B.yaw;

      /* End of Product: '<S60>/Product3' */
    }

    srUpdateBC(Controller_implementation_DW.MeasurementUpdate_SubsysRanBC);
  } else if (Controller_implementation_DW.MeasurementUpdate_MODE) {
    for (i = 0; i < 8; i++) {
      /* Disable for Product: '<S60>/Product3' incorporates:
       *  Outport: '<S60>/L*(y[k]-yhat[k|k-1])'
       */
      Controller_implementation_B.Product3[i] =
        Controller_implementation_P.Lykyhatkk1_Y0;
    }

    Controller_implementation_DW.MeasurementUpdate_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S29>/MeasurementUpdate' */
  for (i = 0; i < 8; i++) {
    /* Product: '<S29>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S7>/A'
     *  Delay: '<S7>/MemoryX'
     */
    Controller_implementation_B.pwLocal = 0.0;
    for (i_0 = 0; i_0 < 8; i_0++) {
      Controller_implementation_B.pwLocal +=
        Controller_implementation_P.A_Value[(i_0 << 3) + i] *
        Controller_implementation_DW.MemoryX_DSTATE[i_0];
    }

    /* Sum: '<S29>/Add' incorporates:
     *  Constant: '<S7>/B'
     *  Product: '<S29>/A[k]*xhat[k|k-1]'
     *  Product: '<S29>/B[k]*u[k]'
     */
    Controller_implementation_B.Add[i] =
      ((((Controller_implementation_P.B_Value[i + 8] *
          Controller_implementation_B.Sum[1] +
          Controller_implementation_P.B_Value[i] *
          Controller_implementation_B.Sum[0]) +
         Controller_implementation_P.B_Value[i + 16] *
         Controller_implementation_B.Sum[2]) +
        Controller_implementation_P.B_Value[i + 24] *
        Controller_implementation_B.Sum[3]) +
       Controller_implementation_B.pwLocal) +
      Controller_implementation_B.Product3[i];
  }

  /* RateTransition: '<S3>/Rate Transition' */
  if (Controller_implementation_M->Timing.RateInteraction.TID1_2) {
    /* Switch: '<S3>/Switch1' incorporates:
     *  Constant: '<S3>/Initial1'
     *  Constant: '<S63>/Constant'
     *  RelationalOperator: '<S63>/Compare'
     *  Saturate: '<S3>/PWM limit'
     */
    if (Controller_implementation_B.d <=
        Controller_implementation_P.CompareToConstant1_const) {
      Controller_implementation_DW.RateTransition_Buffer[0] =
        Controller_implementation_P.Initial1_Value[0];
      Controller_implementation_DW.RateTransition_Buffer[1] =
        Controller_implementation_P.Initial1_Value[1];
      Controller_implementation_DW.RateTransition_Buffer[2] =
        Controller_implementation_P.Initial1_Value[2];
      Controller_implementation_DW.RateTransition_Buffer[3] =
        Controller_implementation_P.Initial1_Value[3];
    } else {
      Controller_implementation_DW.RateTransition_Buffer[0] =
        Controller_implementation_B.PWMlimit[0];
      Controller_implementation_DW.RateTransition_Buffer[1] =
        Controller_implementation_B.PWMlimit[1];
      Controller_implementation_DW.RateTransition_Buffer[2] =
        Controller_implementation_B.PWMlimit[2];
      Controller_implementation_DW.RateTransition_Buffer[3] =
        Controller_implementation_B.PWMlimit[3];
    }

    /* End of Switch: '<S3>/Switch1' */
  }

  /* End of RateTransition: '<S3>/Rate Transition' */

  /* Update for Delay: '<S7>/MemoryX' */
  Controller_implementation_DW.icLoad = false;
  memcpy(&Controller_implementation_DW.MemoryX_DSTATE[0],
         &Controller_implementation_B.Add[0], sizeof(real_T) << 3U);

  /* External mode */
  rtExtModeUploadCheckTrigger(3);
  rtExtModeUpload(1, (real_T)Controller_implementation_M->Timing.t[0]);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Controller_implementation_M)!=-1) &&
        !((rtmGetTFinal(Controller_implementation_M)-
           Controller_implementation_M->Timing.t[0]) >
          Controller_implementation_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(Controller_implementation_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Controller_implementation_M)) {
      rtmSetErrorStatus(Controller_implementation_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Controller_implementation_M->Timing.t[0] =
    ((time_T)(++Controller_implementation_M->Timing.clockTick0)) *
    Controller_implementation_M->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Controller_implementation_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void Controller_implementation_step2(void) /* Sample time: [0.02s, 0.0s] */
{
  /* MATLABSystem: '<S3>/Motor 1' incorporates:
   *  RateTransition: '<S3>/Rate Transition'
   */
  rc_servo_send_pulse_normalized(1,
    (Controller_implementation_DW.RateTransition_Buffer[0] - 90.0) / 60.0);

  /* MATLABSystem: '<S3>/Motor 2' incorporates:
   *  RateTransition: '<S3>/Rate Transition'
   */
  rc_servo_send_pulse_normalized(2,
    (Controller_implementation_DW.RateTransition_Buffer[1] - 90.0) / 60.0);

  /* MATLABSystem: '<S3>/Motor 3' incorporates:
   *  RateTransition: '<S3>/Rate Transition'
   */
  rc_servo_send_pulse_normalized(3,
    (Controller_implementation_DW.RateTransition_Buffer[2] - 90.0) / 60.0);

  /* MATLABSystem: '<S3>/Motor 4' incorporates:
   *  RateTransition: '<S3>/Rate Transition'
   */
  rc_servo_send_pulse_normalized(4,
    (Controller_implementation_DW.RateTransition_Buffer[3] - 90.0) / 60.0);
  rtExtModeUpload(2, (real_T)((Controller_implementation_M->Timing.clockTick2) *
    0.02));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.02, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Controller_implementation_M->Timing.clockTick2++;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Controller_implementation_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Controller_implementation_step0();
    break;

   case 2 :
    Controller_implementation_step2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Controller_implementation_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Controller_implementation_M->solverInfo,
                          &Controller_implementation_M->Timing.simTimeStep);
    rtsiSetTPtr(&Controller_implementation_M->solverInfo, &rtmGetTPtr
                (Controller_implementation_M));
    rtsiSetStepSizePtr(&Controller_implementation_M->solverInfo,
                       &Controller_implementation_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Controller_implementation_M->solverInfo,
                          (&rtmGetErrorStatus(Controller_implementation_M)));
    rtsiSetRTModelPtr(&Controller_implementation_M->solverInfo,
                      Controller_implementation_M);
  }

  rtsiSetSimTimeStep(&Controller_implementation_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Controller_implementation_M->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&Controller_implementation_M->solverInfo, false);
  rtsiSetSolverName(&Controller_implementation_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Controller_implementation_M,
             &Controller_implementation_M->Timing.tArray[0]);
  rtmSetTFinal(Controller_implementation_M, -1);
  Controller_implementation_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Controller_implementation_M->Sizes.checksums[0] = (482771379U);
  Controller_implementation_M->Sizes.checksums[1] = (859215998U);
  Controller_implementation_M->Sizes.checksums[2] = (1021800416U);
  Controller_implementation_M->Sizes.checksums[3] = (969786294U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[22];
    Controller_implementation_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &Controller_implementation_DW.MeasurementUpdate_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &Controller_implementation_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &Controller_implementation_DW.SampleandHold_SubsysRanBC_k;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = (sysRanDType *)
      &Controller_implementation_DW.SampleandHold3_SubsysRanBC;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = (sysRanDType *)
      &Controller_implementation_DW.SampleandHold_SubsysRanBC;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Controller_implementation_M->extModeInfo,
      &Controller_implementation_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Controller_implementation_M->extModeInfo,
                        Controller_implementation_M->Sizes.checksums);
    rteiSetTPtr(Controller_implementation_M->extModeInfo, rtmGetTPtr
                (Controller_implementation_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Controller_implementation_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    int32_T i;
    boolean_T flag;
    Controller_implementati_PrevZCX.SampleandHold_Trig_ZCE_i =
      UNINITIALIZED_ZCSIG;
    Controller_implementati_PrevZCX.SampleandHold3_Trig_ZCE =
      UNINITIALIZED_ZCSIG;
    Controller_implementati_PrevZCX.SampleandHold_Trig_ZCE = UNINITIALIZED_ZCSIG;

    /* InitializeConditions for Delay: '<S7>/MemoryX' */
    Controller_implementation_DW.icLoad = true;

    /* SystemInitialize for Enabled SubSystem: '<S36>/Enabled Subsystem' */
    /* SystemInitialize for Enabled SubSystem: '<S29>/MeasurementUpdate' */
    for (i = 0; i < 8; i++) {
      /* SystemInitialize for Product: '<S60>/Product3' incorporates:
       *  Outport: '<S60>/L*(y[k]-yhat[k|k-1])'
       */
      Controller_implementation_B.Product3[i] =
        Controller_implementation_P.Lykyhatkk1_Y0;

      /* SystemInitialize for Product: '<S62>/Product2' incorporates:
       *  Outport: '<S62>/deltax'
       */
      Controller_implementation_B.Product2[i] =
        Controller_implementation_P.deltax_Y0;
    }

    /* End of SystemInitialize for SubSystem: '<S29>/MeasurementUpdate' */
    /* End of SystemInitialize for SubSystem: '<S36>/Enabled Subsystem' */

    /* SystemInitialize for Triggered SubSystem: '<S1>/Sample and Hold' */
    for (i = 0; i < 7; i++) {
      /* SystemInitialize for SignalConversion generated from: '<S8>/In' incorporates:
       *  Outport: '<S8>/ '
       */
      Controller_implementation_B.In_ca[i] = Controller_implementation_P._Y0;
    }

    /* End of SystemInitialize for SubSystem: '<S1>/Sample and Hold' */

    /* SystemInitialize for Triggered SubSystem: '<S67>/Sample and Hold3' */
    /* SystemInitialize for SignalConversion generated from: '<S73>/In' incorporates:
     *  Outport: '<S73>/ '
     */
    Controller_implementation_B.In_c = Controller_implementation_P._Y0_j;

    /* End of SystemInitialize for SubSystem: '<S67>/Sample and Hold3' */

    /* SystemInitialize for Triggered SubSystem: '<S68>/Sample and Hold' */
    /* SystemInitialize for SignalConversion generated from: '<S75>/In' incorporates:
     *  Outport: '<S75>/ '
     */
    Controller_implementation_B.In = Controller_implementation_P._Y0_l;

    /* End of SystemInitialize for SubSystem: '<S68>/Sample and Hold' */

    /* Start for MATLABSystem: '<S5>/Barometer' */
    Controller_implementation_DW.obj_j.i2cObj.matlabCodegenIsDeleted = true;
    Controller_implementation_DW.obj_j.matlabCodegenIsDeleted = true;
    bbblueBarometer_bbblueBarometer(&Controller_implementation_DW.obj_j);
    Controller_implementation_DW.obj_j.SampleTime =
      Controller_implementation_P.Ts;
    Controller_imp_SystemCore_setup(&Controller_implementation_DW.obj_j);

    /* Start for MATLABSystem: '<S67>/Moving Average' */
    Controller_implementation_DW.obj_m.isInitialized = 0;
    Controller_implementation_DW.obj_m.NumChannels = -1;
    Controller_implementation_DW.obj_m.FrameLength = -1;
    Controller_implementation_DW.obj_m.matlabCodegenIsDeleted = false;
    flag = (Controller_implementation_DW.obj_m.isInitialized == 1);
    if (flag) {
      Controller_implementation_DW.obj_m.TunablePropsChanged = true;
    }

    Controller_implementation_DW.obj_m.ForgettingFactor =
      Controller_implementation_P.MovingAverage_ForgettingFactor;
    Controller__SystemCore_setup_p5(&Controller_implementation_DW.obj_m);

    /* InitializeConditions for MATLABSystem: '<S67>/Moving Average' */
    if (Controller_implementation_DW.obj_m.pStatistic->isInitialized == 1) {
      Controller_implementation_DW.obj_m.pStatistic->pwN = 1.0;
      Controller_implementation_DW.obj_m.pStatistic->pmN = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S67>/Moving Average' */

    /* Start for MATLABSystem: '<S5>/MPU9250' */
    Controller_implementation_DW.obj_n.isInitialized = 0;
    Controller_implementation_DW.obj_n.i2cObjmpu.DefaultMaximumBusSpeedInHz =
      400000.0;
    Controller_implementation_DW.obj_n.i2cObjmpu.isInitialized = 0;
    Controller_implementation_DW.obj_n.i2cObjmpu.matlabCodegenIsDeleted = false;
    Controller_implementation_DW.obj_n.i2cObjak8963.DefaultMaximumBusSpeedInHz =
      400000.0;
    Controller_implementation_DW.obj_n.i2cObjak8963.isInitialized = 0;
    Controller_implementation_DW.obj_n.i2cObjak8963.matlabCodegenIsDeleted =
      false;
    Controller_implementation_DW.obj_n.matlabCodegenIsDeleted = false;
    Controller_implementation_DW.obj_n.SampleTime =
      Controller_implementation_P.Ts;
    Controller_i_SystemCore_setup_p(&Controller_implementation_DW.obj_n);

    /* Start for MATLABSystem: '<S68>/Moving Average' */
    Controller_implementation_DW.obj.isInitialized = 0;
    Controller_implementation_DW.obj.NumChannels = -1;
    Controller_implementation_DW.obj.FrameLength = -1;
    Controller_implementation_DW.obj.matlabCodegenIsDeleted = false;
    flag = (Controller_implementation_DW.obj.isInitialized == 1);
    if (flag) {
      Controller_implementation_DW.obj.TunablePropsChanged = true;
    }

    Controller_implementation_DW.obj.ForgettingFactor =
      Controller_implementation_P.MovingAverage_ForgettingFacto_c;
    Controller__SystemCore_setup_p5(&Controller_implementation_DW.obj);

    /* InitializeConditions for MATLABSystem: '<S68>/Moving Average' */
    if (Controller_implementation_DW.obj.pStatistic->isInitialized == 1) {
      Controller_implementation_DW.obj.pStatistic->pwN = 1.0;
      Controller_implementation_DW.obj.pStatistic->pmN = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S68>/Moving Average' */

    /* Start for MATLABSystem: '<S3>/Motor 1' */
    Controller_implementation_DW.obj_k.matlabCodegenIsDeleted = false;
    Controller_implementation_DW.obj_k.isInitialized = 1;
    Controller_implementation_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Motor 2' */
    Controller_implementation_DW.obj_p.matlabCodegenIsDeleted = false;
    Controller_implementation_DW.obj_p.isInitialized = 1;
    Controller_implementation_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Motor 3' */
    Controller_implementation_DW.obj_h.matlabCodegenIsDeleted = false;
    Controller_implementation_DW.obj_h.isInitialized = 1;
    Controller_implementation_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Motor 4' */
    Controller_implementation_DW.obj_b.matlabCodegenIsDeleted = false;
    Controller_implementation_DW.obj_b.isInitialized = 1;
    Controller_implementation_DW.obj_b.isSetupComplete = true;
  }
}

/* Model terminate function */
void Controller_implementation_terminate(void)
{
  /* Terminate for MATLABSystem: '<S5>/Barometer' */
  if (!Controller_implementation_DW.obj_j.matlabCodegenIsDeleted) {
    Controller_implementation_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  if (!Controller_implementation_DW.obj_j.i2cObj.matlabCodegenIsDeleted) {
    Controller_implementation_DW.obj_j.i2cObj.matlabCodegenIsDeleted = true;
    if (Controller_implementation_DW.obj_j.i2cObj.isInitialized == 1) {
      Controller_implementation_DW.obj_j.i2cObj.isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Barometer' */

  /* Terminate for MATLABSystem: '<S67>/Moving Average' */
  if (!Controller_implementation_DW.obj_m.matlabCodegenIsDeleted) {
    Controller_implementation_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Controller_implementation_DW.obj_m.isInitialized == 1) &&
        Controller_implementation_DW.obj_m.isSetupComplete) {
      if (Controller_implementation_DW.obj_m.pStatistic->isInitialized == 1) {
        Controller_implementation_DW.obj_m.pStatistic->isInitialized = 2;
      }

      Controller_implementation_DW.obj_m.NumChannels = -1;
      Controller_implementation_DW.obj_m.FrameLength = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S67>/Moving Average' */

  /* Terminate for MATLABSystem: '<S5>/MPU9250' */
  if (!Controller_implementation_DW.obj_n.matlabCodegenIsDeleted) {
    Controller_implementation_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  if (!Controller_implementation_DW.obj_n.i2cObjak8963.matlabCodegenIsDeleted) {
    Controller_implementation_DW.obj_n.i2cObjak8963.matlabCodegenIsDeleted =
      true;
    if (Controller_implementation_DW.obj_n.i2cObjak8963.isInitialized == 1) {
      Controller_implementation_DW.obj_n.i2cObjak8963.isInitialized = 2;
    }
  }

  if (!Controller_implementation_DW.obj_n.i2cObjmpu.matlabCodegenIsDeleted) {
    Controller_implementation_DW.obj_n.i2cObjmpu.matlabCodegenIsDeleted = true;
    if (Controller_implementation_DW.obj_n.i2cObjmpu.isInitialized == 1) {
      Controller_implementation_DW.obj_n.i2cObjmpu.isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/MPU9250' */

  /* Terminate for MATLABSystem: '<S68>/Moving Average' */
  if (!Controller_implementation_DW.obj.matlabCodegenIsDeleted) {
    Controller_implementation_DW.obj.matlabCodegenIsDeleted = true;
    if ((Controller_implementation_DW.obj.isInitialized == 1) &&
        Controller_implementation_DW.obj.isSetupComplete) {
      if (Controller_implementation_DW.obj.pStatistic->isInitialized == 1) {
        Controller_implementation_DW.obj.pStatistic->isInitialized = 2;
      }

      Controller_implementation_DW.obj.NumChannels = -1;
      Controller_implementation_DW.obj.FrameLength = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S68>/Moving Average' */

  /* Terminate for MATLABSystem: '<S3>/Motor 1' */
  if (!Controller_implementation_DW.obj_k.matlabCodegenIsDeleted) {
    Controller_implementation_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((Controller_implementation_DW.obj_k.isInitialized == 1) &&
        Controller_implementation_DW.obj_k.isSetupComplete) {
      rc_servo_send_pulse_normalized(1, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Motor 1' */

  /* Terminate for MATLABSystem: '<S3>/Motor 2' */
  if (!Controller_implementation_DW.obj_p.matlabCodegenIsDeleted) {
    Controller_implementation_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Controller_implementation_DW.obj_p.isInitialized == 1) &&
        Controller_implementation_DW.obj_p.isSetupComplete) {
      rc_servo_send_pulse_normalized(2, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Motor 2' */

  /* Terminate for MATLABSystem: '<S3>/Motor 3' */
  if (!Controller_implementation_DW.obj_h.matlabCodegenIsDeleted) {
    Controller_implementation_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Controller_implementation_DW.obj_h.isInitialized == 1) &&
        Controller_implementation_DW.obj_h.isSetupComplete) {
      rc_servo_send_pulse_normalized(3, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Motor 3' */

  /* Terminate for MATLABSystem: '<S3>/Motor 4' */
  if (!Controller_implementation_DW.obj_b.matlabCodegenIsDeleted) {
    Controller_implementation_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Controller_implementation_DW.obj_b.isInitialized == 1) &&
        Controller_implementation_DW.obj_b.isSetupComplete) {
      rc_servo_send_pulse_normalized(4, 0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Motor 4' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
