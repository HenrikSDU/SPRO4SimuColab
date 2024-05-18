/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BBB_calibration.c
 *
 * Code generated for Simulink model 'BBB_calibration'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat May 18 13:59:17 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BBB_calibration.h"
#include "BBB_calibration_types.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rt_nonfinite.h"
#include "BBB_calibration_private.h"
#include "BBB_calibration_dt.h"

/* Block signals (default storage) */
B_BBB_calibration_T BBB_calibration_B;

/* Block states (default storage) */
DW_BBB_calibration_T BBB_calibration_DW;

/* Real-time model */
static RT_MODEL_BBB_calibration_T BBB_calibration_M_;
RT_MODEL_BBB_calibration_T *const BBB_calibration_M = &BBB_calibration_M_;

/* Forward declaration for local functions */
static void bbblueBarometer_BMP_ReadRegiste(const
  beagleboneblue_bbblueBaromete_T *obj, uint8_T RegisterValue[6], uint8_T
  *varargout_1);
static int64m_T BBB_calibration_i64ddiv(real_T x, const int64m_T y);
static uint64m_T BBB_calibr_eml_mixed_uint64_mul(const uint64m_T nv, real_T y);
static int64m_T BBB_calibration_times(real_T x, const int64m_T y);
static real_T BBB_ca_bbblueBarometer_stepImpl(const
  beagleboneblue_bbblueBaromete_T *obj);
static void BBB_calibrat_SystemCore_setup_f(beagleboneblue_bbblueMPU9250__T *obj);
static beagleboneblue_bbblueBaromete_T *bbblueBarometer_bbblueBarometer
  (beagleboneblue_bbblueBaromete_T *obj);
static void BBB_calibratio_SystemCore_setup(beagleboneblue_bbblueBaromete_T *obj);
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

static void bbblueBarometer_BMP_ReadRegiste(const
  beagleboneblue_bbblueBaromete_T *obj, uint8_T RegisterValue[6], uint8_T
  *varargout_1)
{
  int32_T i;
  uint8_T output_raw[6];
  uint8_T Data;
  uint8_T SwappedDataBytes;
  Data = 247U;

  /* Start for MATLABSystem: '<Root>/Barometer1' */
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

  /* End of Start for MATLABSystem: '<Root>/Barometer1' */
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

static int64m_T BBB_calibration_i64ddiv(real_T x, const int64m_T y)
{
  int64m_T tmp_2;
  int64m_T z;
  uint64m_T tmp;
  uint64m_T tmp_0;
  uint64m_T tmp_1;
  int32_T firstbitn;
  int32_T shiftAmount;
  int32_T xexp;
  boolean_T b_p;
  boolean_T tmp_3;
  static const int64m_T tmp_4 = { { 0U, 2147483648U }/* chunks */
  };

  static const uint64m_T tmp_5 = { { 0U, 2147483648U }/* chunks */
  };

  static const uint64m_T tmp_6 = { { 0U, 0U }/* chunks */
  };

  static const uint64m_T tmp_7 = { { 1U, 0U }/* chunks */
  };

  static const uint64m_T tmp_8 = { { MAX_uint32_T, MAX_uint32_T }/* chunks */
  };

  static const int64m_T tmp_9 = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  static const int64m_T tmp_a = { { 0U, 0U }/* chunks */
  };

  static const uint64m_T tmp_b = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  int32_T exitg1;
  int32_T exitg2;
  int32_T exitg3;
  boolean_T guard1;

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  if (x == 0.0) {
    memcpy((void *)&BBB_calibration_B.ux[0], (void *)&x, (size_t)2 * sizeof
           (uint32_T));
    if ((BBB_calibration_B.ux[0] != 0U) || (BBB_calibration_B.ux[1] != 0U)) {
      b_p = true;
    } else {
      b_p = false;
    }
  } else {
    b_p = false;
  }

  if (sMultiWordLt(&y.chunks[0U], &tmp_a.chunks[0U], 2)) {
    if (sMultiWordGt(&y.chunks[0U], &tmp_4.chunks[0U], 2)) {
      MultiWordNeg(&y.chunks[0U], &BBB_calibration_B.r25.chunks[0U], 2);
      sMultiWord2MultiWord(&BBB_calibration_B.r25.chunks[0U], 2,
                           &BBB_calibration_B.nk_unsgn.chunks[0U], 2);
    } else {
      BBB_calibration_B.nk_unsgn = tmp_5;
    }
  } else {
    sMultiWord2MultiWord(&y.chunks[0U], 2, &BBB_calibration_B.nk_unsgn.chunks[0U],
                         2);
  }

  tmp_3 = ((x < 0.0) || b_p);
  if (tmp_3) {
    BBB_calibration_B.x_unsgn = -x;
  } else {
    BBB_calibration_B.x_unsgn = x;
  }

  if (uMultiWordEq(&BBB_calibration_B.nk_unsgn.chunks[0U], &tmp_6.chunks[0U], 2))
  {
    if (BBB_calibration_B.x_unsgn > 0.0) {
      BBB_calibration_B.res = tmp_8;
    } else {
      BBB_calibration_B.res = tmp_6;
    }
  } else if ((BBB_calibration_B.x_unsgn <= 0.0) || rtIsNaN
             (BBB_calibration_B.x_unsgn)) {
    BBB_calibration_B.res = tmp_6;
  } else if (rtIsInf(BBB_calibration_B.x_unsgn)) {
    BBB_calibration_B.res = tmp_8;
  } else {
    BBB_calibration_B.x_unsgn = frexp(BBB_calibration_B.x_unsgn, &shiftAmount);
    Double2MultiWord(rt_roundd_snf(BBB_calibration_B.x_unsgn *
      9.007199254740992E+15), &BBB_calibration_B.xint.chunks[0U], 2);
    xexp = shiftAmount - 53;
    firstbitn = 63;
    do {
      exitg1 = 0;
      uMultiWordShr(&BBB_calibration_B.nk_unsgn.chunks[0U], 2, (uint32_T)
                    firstbitn, &BBB_calibration_B.res.chunks[0U], 2);
      if (uMultiWordLe(&BBB_calibration_B.res.chunks[0U], &tmp_6.chunks[0U], 2))
      {
        firstbitn--;
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (shiftAmount - 53 < firstbitn - 53) {
      BBB_calibration_B.res = tmp_6;
    } else if (shiftAmount - 53 > firstbitn + 12) {
      BBB_calibration_B.res = tmp_8;
    } else {
      BBB_calibration_B.res = tmp_6;
      guard1 = false;
      if (firstbitn < 63) {
        uMultiWordDivZero(&BBB_calibration_B.xint.chunks[0U], 2,
                          &BBB_calibration_B.nk_unsgn.chunks[0U], 2,
                          &BBB_calibration_B.res.chunks[0U], 2,
                          &BBB_calibration_B.r26.chunks[0U], 2,
                          &BBB_calibration_B.r27.chunks[0U], 2,
                          &BBB_calibration_B.r28.chunks[0U], 2);
        if (!uMultiWordEq(&BBB_calibration_B.nk_unsgn.chunks[0U], &tmp_6.chunks
                          [0U], 2)) {
          uMultiWordDivZero(&BBB_calibration_B.xint.chunks[0U], 2,
                            &BBB_calibration_B.nk_unsgn.chunks[0U], 2,
                            &BBB_calibration_B.r28.chunks[0U], 2,
                            &BBB_calibration_B.r29.chunks[0U], 2,
                            &BBB_calibration_B.r30.chunks[0U], 2,
                            &BBB_calibration_B.r31.chunks[0U], 2);
          uMultiWordMul(&BBB_calibration_B.r28.chunks[0U], 2,
                        &BBB_calibration_B.nk_unsgn.chunks[0U], 2,
                        &BBB_calibration_B.r3.chunks[0U], 4);
          uMultiWord2MultiWord(&BBB_calibration_B.r3.chunks[0U], 4,
                               &BBB_calibration_B.r27.chunks[0U], 2);
          MultiWordSub(&BBB_calibration_B.xint.chunks[0U],
                       &BBB_calibration_B.r27.chunks[0U],
                       &BBB_calibration_B.r28.chunks[0U], 2);
          BBB_calibration_B.xint = BBB_calibration_B.r28;
        }

        if (shiftAmount - 53 < 0) {
          uMultiWordShr(&BBB_calibration_B.res.chunks[0U], 2, (uint32_T)(53 -
            shiftAmount), &tmp_1.chunks[0U], 2);
          uMultiWordShr(&BBB_calibration_B.res.chunks[0U], 2, (uint32_T)(52 -
            shiftAmount), &tmp.chunks[0U], 2);
          MultiWordAnd(&tmp.chunks[0U], &tmp_7.chunks[0U],
                       &BBB_calibration_B.r38.chunks[0U], 2);
          MultiWordAdd(&tmp_1.chunks[0U], &BBB_calibration_B.r38.chunks[0U],
                       &BBB_calibration_B.res.chunks[0U], 2);
        } else {
          do {
            exitg2 = 0;
            if (xexp > 0) {
              if (63 - firstbitn > xexp) {
                shiftAmount = xexp;
              } else {
                shiftAmount = 63 - firstbitn;
              }

              uMultiWordShr(&BBB_calibration_B.res.chunks[0U], 2, (uint32_T)(64
                - shiftAmount), &BBB_calibration_B.r29.chunks[0U], 2);
              if (uMultiWordGt(&BBB_calibration_B.r29.chunks[0U], &tmp_6.chunks
                               [0U], 2)) {
                BBB_calibration_B.res = tmp_8;
                exitg2 = 1;
              } else {
                uMultiWordShl(&BBB_calibration_B.res.chunks[0U], 2, (uint32_T)
                              shiftAmount, &BBB_calibration_B.r32.chunks[0U], 2);
                xexp -= shiftAmount;
                uMultiWordShl(&BBB_calibration_B.xint.chunks[0U], 2, (uint32_T)
                              shiftAmount, &BBB_calibration_B.r33.chunks[0U], 2);
                BBB_calibration_B.xint = BBB_calibration_B.r33;
                uMultiWordDivZero(&BBB_calibration_B.r33.chunks[0U], 2,
                                  &BBB_calibration_B.nk_unsgn.chunks[0U], 2,
                                  &BBB_calibration_B.nIsOdd.chunks[0U], 2,
                                  &BBB_calibration_B.r34.chunks[0U], 2,
                                  &BBB_calibration_B.r35.chunks[0U], 2,
                                  &BBB_calibration_B.r36.chunks[0U], 2);
                BBB_calibration_B.r35 = tmp_8;
                MultiWordSub(&tmp_8.chunks[0U],
                             &BBB_calibration_B.nIsOdd.chunks[0U],
                             &BBB_calibration_B.r34.chunks[0U], 2);
                if (uMultiWordLe(&BBB_calibration_B.r34.chunks[0U],
                                 &BBB_calibration_B.r32.chunks[0U], 2)) {
                  BBB_calibration_B.res = tmp_8;
                  exitg2 = 1;
                } else {
                  MultiWordAdd(&BBB_calibration_B.r32.chunks[0U],
                               &BBB_calibration_B.nIsOdd.chunks[0U],
                               &BBB_calibration_B.r35.chunks[0U], 2);
                  BBB_calibration_B.res = BBB_calibration_B.r35;
                  BBB_calibration_B.r36 = tmp_6;
                  if (!uMultiWordEq(&BBB_calibration_B.nk_unsgn.chunks[0U],
                                    &tmp_6.chunks[0U], 2)) {
                    uMultiWordDivZero(&BBB_calibration_B.r33.chunks[0U], 2,
                                      &BBB_calibration_B.nk_unsgn.chunks[0U], 2,
                                      &BBB_calibration_B.r37.chunks[0U], 2,
                                      &BBB_calibration_B.r38.chunks[0U], 2,
                                      &tmp.chunks[0U], 2, &tmp_0.chunks[0U], 2);
                    uMultiWordMul(&BBB_calibration_B.r37.chunks[0U], 2,
                                  &BBB_calibration_B.nk_unsgn.chunks[0U], 2,
                                  &BBB_calibration_B.r3.chunks[0U], 4);
                    uMultiWord2MultiWord(&BBB_calibration_B.r3.chunks[0U], 4,
                                         &tmp_1.chunks[0U], 2);
                    MultiWordSub(&BBB_calibration_B.r33.chunks[0U],
                                 &tmp_1.chunks[0U],
                                 &BBB_calibration_B.r37.chunks[0U], 2);
                    BBB_calibration_B.xint = BBB_calibration_B.r37;
                  }
                }
              }
            } else {
              uMultiWordShl(&BBB_calibration_B.xint.chunks[0U], 2, 1U,
                            &BBB_calibration_B.r27.chunks[0U], 2);
              if (uMultiWordGe(&BBB_calibration_B.r27.chunks[0U],
                               &BBB_calibration_B.nk_unsgn.chunks[0U], 2)) {
                MultiWordAdd(&BBB_calibration_B.res.chunks[0U], &tmp_7.chunks[0U],
                             &BBB_calibration_B.r30.chunks[0U], 2);
                BBB_calibration_B.res = BBB_calibration_B.r30;
              }

              exitg2 = 1;
            }
          } while (exitg2 == 0);
        }
      } else if (shiftAmount - 53 > 10) {
        uMultiWordShl(&BBB_calibration_B.xint.chunks[0U], 2, 11U,
                      &BBB_calibration_B.r26.chunks[0U], 2);
        BBB_calibration_B.xint = BBB_calibration_B.r26;
        xexp = shiftAmount - 64;
        BBB_calibration_B.r26 = tmp_7;
        MultiWordAnd(&BBB_calibration_B.nk_unsgn.chunks[0U], &tmp_7.chunks[0U],
                     &BBB_calibration_B.nIsOdd.chunks[0U], 2);
        if (uMultiWordGe(&BBB_calibration_B.xint.chunks[0U],
                         &BBB_calibration_B.nk_unsgn.chunks[0U], 2)) {
          BBB_calibration_B.res = tmp_7;
          MultiWordSub(&BBB_calibration_B.xint.chunks[0U],
                       &BBB_calibration_B.nk_unsgn.chunks[0U],
                       &BBB_calibration_B.r27.chunks[0U], 2);
          BBB_calibration_B.xint = BBB_calibration_B.r27;
        } else if (shiftAmount - 64 > 0) {
          xexp = shiftAmount - 65;
          BBB_calibration_B.res = tmp_7;
          uMultiWordShr(&BBB_calibration_B.nk_unsgn.chunks[0U], 2, 1U,
                        &BBB_calibration_B.r27.chunks[0U], 2);
          MultiWordSub(&BBB_calibration_B.xint.chunks[0U],
                       &BBB_calibration_B.r27.chunks[0U],
                       &BBB_calibration_B.r26.chunks[0U], 2);
          uMultiWordShl(&BBB_calibration_B.r26.chunks[0U], 2, 1U,
                        &BBB_calibration_B.xint.chunks[0U], 2);
          if (uMultiWordNe(&BBB_calibration_B.nIsOdd.chunks[0U], &tmp_6.chunks
                           [0U], 2)) {
            MultiWordSub(&BBB_calibration_B.xint.chunks[0U], &tmp_7.chunks[0U],
                         &BBB_calibration_B.r28.chunks[0U], 2);
            BBB_calibration_B.xint = BBB_calibration_B.r28;
          }
        }

        do {
          exitg1 = 0;
          if (xexp > 0) {
            if (uMultiWordEq(&BBB_calibration_B.xint.chunks[0U], &tmp_6.chunks
                             [0U], 2)) {
              uMultiWordShr(&BBB_calibration_B.res.chunks[0U], 2, (uint32_T)(64
                - xexp), &tmp_0.chunks[0U], 2);
              if (uMultiWordGt(&tmp_0.chunks[0U], &tmp_6.chunks[0U], 2)) {
                BBB_calibration_B.res = tmp_8;
                exitg1 = 1;
              } else {
                uMultiWordShl(&BBB_calibration_B.res.chunks[0U], 2, (uint32_T)
                              xexp, &tmp_1.chunks[0U], 2);
                BBB_calibration_B.res = tmp_1;
                xexp = 0;
              }
            } else {
              firstbitn = 63;
              do {
                exitg3 = 0;
                uMultiWordShr(&BBB_calibration_B.xint.chunks[0U], 2, (uint32_T)
                              firstbitn, &BBB_calibration_B.r32.chunks[0U], 2);
                if (uMultiWordLe(&BBB_calibration_B.r32.chunks[0U],
                                 &tmp_6.chunks[0U], 2)) {
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

              uMultiWordShr(&BBB_calibration_B.res.chunks[0U], 2, (uint32_T)(64
                - shiftAmount), &BBB_calibration_B.r33.chunks[0U], 2);
              if ((shiftAmount != 0) && uMultiWordGt
                  (&BBB_calibration_B.r33.chunks[0U], &tmp_6.chunks[0U], 2)) {
                BBB_calibration_B.res = tmp_8;
                exitg1 = 1;
              } else {
                uMultiWordShl(&BBB_calibration_B.res.chunks[0U], 2, (uint32_T)
                              shiftAmount, &BBB_calibration_B.r34.chunks[0U], 2);
                BBB_calibration_B.res = BBB_calibration_B.r34;
                xexp -= shiftAmount;
                uMultiWordShl(&BBB_calibration_B.xint.chunks[0U], 2, (uint32_T)
                              shiftAmount, &BBB_calibration_B.r35.chunks[0U], 2);
                BBB_calibration_B.xint = BBB_calibration_B.r35;
                if (uMultiWordGt(&BBB_calibration_B.xint.chunks[0U],
                                 &BBB_calibration_B.nk_unsgn.chunks[0U], 2)) {
                  BBB_calibration_B.r26 = tmp_7;
                  MultiWordAdd(&BBB_calibration_B.r34.chunks[0U], &tmp_7.chunks
                               [0U], &tmp.chunks[0U], 2);
                  BBB_calibration_B.res = tmp;
                  MultiWordSub(&BBB_calibration_B.xint.chunks[0U],
                               &BBB_calibration_B.nk_unsgn.chunks[0U],
                               &BBB_calibration_B.r26.chunks[0U], 2);
                  BBB_calibration_B.xint = BBB_calibration_B.r26;
                } else if (xexp > 0) {
                  xexp--;
                  uMultiWordShr(&BBB_calibration_B.r34.chunks[0U], 2, 63U,
                                &BBB_calibration_B.r36.chunks[0U], 2);
                  if (uMultiWordGt(&BBB_calibration_B.r36.chunks[0U],
                                   &tmp_6.chunks[0U], 2)) {
                    BBB_calibration_B.res = tmp_8;
                    exitg1 = 1;
                  } else {
                    uMultiWordShl(&BBB_calibration_B.r34.chunks[0U], 2, 1U,
                                  &BBB_calibration_B.r37.chunks[0U], 2);
                    BBB_calibration_B.r26 = tmp_7;
                    MultiWordAdd(&BBB_calibration_B.r37.chunks[0U],
                                 &tmp_7.chunks[0U],
                                 &BBB_calibration_B.res.chunks[0U], 2);
                    uMultiWordShr(&BBB_calibration_B.nk_unsgn.chunks[0U], 2, 1U,
                                  &BBB_calibration_B.r26.chunks[0U], 2);
                    MultiWordSub(&BBB_calibration_B.xint.chunks[0U],
                                 &BBB_calibration_B.r26.chunks[0U],
                                 &BBB_calibration_B.r37.chunks[0U], 2);
                    uMultiWordShl(&BBB_calibration_B.r37.chunks[0U], 2, 1U,
                                  &BBB_calibration_B.xint.chunks[0U], 2);
                    BBB_calibration_B.r37 = tmp_6;
                    if (uMultiWordNe(&BBB_calibration_B.nIsOdd.chunks[0U],
                                     &tmp_6.chunks[0U], 2)) {
                      MultiWordSub(&BBB_calibration_B.xint.chunks[0U],
                                   &tmp_7.chunks[0U],
                                   &BBB_calibration_B.r38.chunks[0U], 2);
                      BBB_calibration_B.xint = BBB_calibration_B.r38;
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
        uMultiWordShl(&BBB_calibration_B.xint.chunks[0U], 2, 10U,
                      &BBB_calibration_B.r26.chunks[0U], 2);
        BBB_calibration_B.xint = BBB_calibration_B.r26;
        guard1 = true;
      }

      if (guard1) {
        MultiWordAnd(&BBB_calibration_B.xint.chunks[0U], &tmp_5.chunks[0U],
                     &BBB_calibration_B.r29.chunks[0U], 2);
        uMultiWordShl(&BBB_calibration_B.xint.chunks[0U], 2, 1U,
                      &BBB_calibration_B.r30.chunks[0U], 2);
        if (uMultiWordNe(&BBB_calibration_B.r29.chunks[0U], &tmp_6.chunks[0U], 2)
            || uMultiWordGe(&BBB_calibration_B.r30.chunks[0U],
                            &BBB_calibration_B.nk_unsgn.chunks[0U], 2)) {
          MultiWordAdd(&BBB_calibration_B.res.chunks[0U], &tmp_7.chunks[0U],
                       &BBB_calibration_B.r31.chunks[0U], 2);
          BBB_calibration_B.res = BBB_calibration_B.r31;
        }
      }
    }
  }

  if ((sMultiWordLt(&y.chunks[0U], &tmp_a.chunks[0U], 2) && (x >= 0.0) && (!b_p))
      || (sMultiWordGe(&y.chunks[0U], &tmp_a.chunks[0U], 2) && tmp_3)) {
    if (uMultiWordLe(&BBB_calibration_B.res.chunks[0U], &tmp_b.chunks[0U], 2)) {
      uMultiWord2MultiWord(&BBB_calibration_B.res.chunks[0U], 2, &tmp_2.chunks
                           [0U], 2);
      MultiWordNeg(&tmp_2.chunks[0U], &z.chunks[0U], 2);
    } else {
      z = tmp_4;
    }
  } else if (uMultiWordLe(&BBB_calibration_B.res.chunks[0U], &tmp_b.chunks[0U],
                          2)) {
    uMultiWord2MultiWord(&BBB_calibration_B.res.chunks[0U], 2, &z.chunks[0U], 2);
  } else {
    z = tmp_9;
  }

  /* End of Start for MATLABSystem: '<Root>/Barometer1' */
  return z;
}

static uint64m_T BBB_calibr_eml_mixed_uint64_mul(const uint64m_T nv, real_T y)
{
  uint64m_T tmp_2;
  uint64m_T tmp_3;
  uint64m_T tmp_4;
  uint64m_T tmp_5;
  uint64m_T tmp_6;
  uint64m_T z;
  int32_T ex_t;
  int16_T tmp;
  int16_T tmp_0;
  int16_T tmp_1;
  static const uint64m_T tmp_7 = { { MAX_uint32_T, MAX_uint32_T }/* chunks */
  };

  static const uint64m_T tmp_8 = { { 1U, 0U }/* chunks */
  };

  static const uint64m_T tmp_9 = { { 0U, 0U }/* chunks */
  };

  static const uint64m_T tmp_a = { { MAX_uint32_T, 0U }/* chunks */
  };

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  if (rtIsNaN(y) || (y <= 0.0)) {
    z = tmp_9;
  } else {
    BBB_calibration_B.yd = frexp(y, &ex_t);
    if (ex_t <= -64) {
      z = tmp_9;
    } else {
      Double2MultiWord(rt_roundd_snf(BBB_calibration_B.yd *
        9.007199254740992E+15), &BBB_calibration_B.yint.chunks[0U], 2);
      uMultiWordShr(&BBB_calibration_B.yint.chunks[0U], 2, 32U,
                    &BBB_calibration_B.b_y1.chunks[0U], 2);
      MultiWordAnd(&BBB_calibration_B.yint.chunks[0U], &tmp_a.chunks[0U],
                   &BBB_calibration_B.b_y0.chunks[0U], 2);
      if (uMultiWordEq(&nv.chunks[0U], &tmp_9.chunks[0U], 2)) {
        z = tmp_9;
      } else if (rtIsInf(y)) {
        z = tmp_7;
      } else if (ex_t - 53 > 64) {
        z = tmp_7;
      } else {
        uMultiWordShr(&nv.chunks[0U], 2, 32U, &BBB_calibration_B.n1.chunks[0U],
                      2);
        BBB_calibration_B.r41 = nv;
        tmp_2 = tmp_a;
        MultiWordAnd(&nv.chunks[0U], &tmp_a.chunks[0U],
                     &BBB_calibration_B.yint.chunks[0U], 2);
        uMultiWordMul(&BBB_calibration_B.yint.chunks[0U], 2,
                      &BBB_calibration_B.b_y0.chunks[0U], 2,
                      &BBB_calibration_B.r4.chunks[0U], 4);
        uMultiWord2MultiWord(&BBB_calibration_B.r4.chunks[0U], 4,
                             &BBB_calibration_B.ldword.chunks[0U], 2);
        uMultiWordMul(&BBB_calibration_B.yint.chunks[0U], 2,
                      &BBB_calibration_B.b_y1.chunks[0U], 2,
                      &BBB_calibration_B.r4.chunks[0U], 4);
        uMultiWord2MultiWord(&BBB_calibration_B.r4.chunks[0U], 4,
                             &BBB_calibration_B.temp0.chunks[0U], 2);
        uMultiWordMul(&BBB_calibration_B.n1.chunks[0U], 2,
                      &BBB_calibration_B.b_y0.chunks[0U], 2,
                      &BBB_calibration_B.r4.chunks[0U], 4);
        uMultiWord2MultiWord(&BBB_calibration_B.r4.chunks[0U], 4,
                             &BBB_calibration_B.b_y0.chunks[0U], 2);
        tmp_3 = tmp_a;
        MultiWordAnd(&BBB_calibration_B.temp0.chunks[0U], &tmp_a.chunks[0U],
                     &tmp_2.chunks[0U], 2);
        uMultiWordShr(&BBB_calibration_B.ldword.chunks[0U], 2, 32U,
                      &tmp_3.chunks[0U], 2);
        MultiWordAdd(&tmp_2.chunks[0U], &tmp_3.chunks[0U],
                     &BBB_calibration_B.r41.chunks[0U], 2);
        tmp_3 = tmp_a;
        MultiWordAnd(&BBB_calibration_B.b_y0.chunks[0U], &tmp_a.chunks[0U],
                     &tmp_2.chunks[0U], 2);
        MultiWordAdd(&BBB_calibration_B.r41.chunks[0U], &tmp_2.chunks[0U],
                     &BBB_calibration_B.yint.chunks[0U], 2);
        tmp_2 = tmp_a;
        MultiWordAnd(&BBB_calibration_B.ldword.chunks[0U], &tmp_a.chunks[0U],
                     &BBB_calibration_B.r41.chunks[0U], 2);
        uMultiWordShl(&BBB_calibration_B.yint.chunks[0U], 2, 32U, &tmp_2.chunks
                      [0U], 2);
        MultiWordAdd(&BBB_calibration_B.r41.chunks[0U], &tmp_2.chunks[0U],
                     &BBB_calibration_B.ldword.chunks[0U], 2);
        uMultiWordMul(&BBB_calibration_B.n1.chunks[0U], 2,
                      &BBB_calibration_B.b_y1.chunks[0U], 2,
                      &BBB_calibration_B.r4.chunks[0U], 4);
        uMultiWord2MultiWord(&BBB_calibration_B.r4.chunks[0U], 4, &tmp_3.chunks
                             [0U], 2);
        uMultiWordShr(&BBB_calibration_B.temp0.chunks[0U], 2, 32U,
                      &tmp_4.chunks[0U], 2);
        MultiWordAdd(&tmp_3.chunks[0U], &tmp_4.chunks[0U], &tmp_2.chunks[0U], 2);
        uMultiWordShr(&BBB_calibration_B.b_y0.chunks[0U], 2, 32U, &tmp_3.chunks
                      [0U], 2);
        MultiWordAdd(&tmp_2.chunks[0U], &tmp_3.chunks[0U],
                     &BBB_calibration_B.r41.chunks[0U], 2);
        uMultiWordShr(&BBB_calibration_B.yint.chunks[0U], 2, 32U, &tmp_2.chunks
                      [0U], 2);
        MultiWordAdd(&BBB_calibration_B.r41.chunks[0U], &tmp_2.chunks[0U],
                     &BBB_calibration_B.yint.chunks[0U], 2);
        if (ex_t - 53 >= 0) {
          if (uMultiWordGt(&BBB_calibration_B.yint.chunks[0U], &tmp_9.chunks[0U],
                           2)) {
            z = tmp_7;
          } else {
            tmp = (int16_T)(117 - ex_t);
            if (117 - ex_t < 0) {
              tmp = 0;
            }

            uMultiWordShr(&BBB_calibration_B.ldword.chunks[0U], 2, (uint32_T)tmp,
                          &tmp_6.chunks[0U], 2);
            if ((117 - ex_t < 64) && uMultiWordGt(&tmp_6.chunks[0U],
                 &tmp_9.chunks[0U], 2)) {
              z = tmp_7;
            } else {
              tmp = (int16_T)(ex_t - 53);
              if (ex_t - 53 < 0) {
                tmp = 0;
              } else if (ex_t - 53 > 255) {
                tmp = 255;
              }

              uMultiWordShl(&BBB_calibration_B.ldword.chunks[0U], 2, (uint32_T)
                            tmp, &z.chunks[0U], 2);
            }
          }
        } else if (ex_t - 53 > -64) {
          tmp = (int16_T)(53 - ex_t);
          if (53 - ex_t < 0) {
            tmp = 0;
          }

          uMultiWordShr(&BBB_calibration_B.yint.chunks[0U], 2, (uint32_T)tmp,
                        &BBB_calibration_B.r41.chunks[0U], 2);
          if (uMultiWordGt(&BBB_calibration_B.r41.chunks[0U], &tmp_9.chunks[0U],
                           2)) {
            z = tmp_7;
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

            uMultiWordShr(&BBB_calibration_B.ldword.chunks[0U], 2, (uint32_T)tmp,
                          &tmp_6.chunks[0U], 2);
            uMultiWordShl(&BBB_calibration_B.yint.chunks[0U], 2, (uint32_T)tmp_0,
                          &z.chunks[0U], 2);
            MultiWordAdd(&tmp_6.chunks[0U], &z.chunks[0U], &tmp_5.chunks[0U], 2);
            uMultiWordShr(&BBB_calibration_B.ldword.chunks[0U], 2, (uint32_T)
                          tmp_1, &z.chunks[0U], 2);
            MultiWordAnd(&z.chunks[0U], &tmp_8.chunks[0U], &tmp_6.chunks[0U], 2);
            MultiWordAdd(&tmp_5.chunks[0U], &tmp_6.chunks[0U], &z.chunks[0U], 2);
          }
        } else if (ex_t - 53 == -64) {
          uMultiWordShr(&BBB_calibration_B.ldword.chunks[0U], 2, 63U,
                        &tmp_2.chunks[0U], 2);
          MultiWordAnd(&tmp_2.chunks[0U], &tmp_8.chunks[0U],
                       &BBB_calibration_B.r41.chunks[0U], 2);
          MultiWordAdd(&BBB_calibration_B.yint.chunks[0U],
                       &BBB_calibration_B.r41.chunks[0U], &tmp_2.chunks[0U], 2);
          z = tmp_2;
        } else {
          tmp = (int16_T)-(ex_t + 11);
          if (-(ex_t + 11) < 0) {
            tmp = 0;
          }

          tmp_0 = (int16_T)-(ex_t + 12);
          if (-(ex_t + 12) < 0) {
            tmp_0 = 0;
          }

          uMultiWordShr(&BBB_calibration_B.yint.chunks[0U], 2, (uint32_T)tmp,
                        &BBB_calibration_B.r41.chunks[0U], 2);
          uMultiWordShr(&BBB_calibration_B.yint.chunks[0U], 2, (uint32_T)tmp_0,
                        &tmp_3.chunks[0U], 2);
          MultiWordAnd(&tmp_3.chunks[0U], &tmp_8.chunks[0U], &tmp_2.chunks[0U],
                       2);
          MultiWordAdd(&BBB_calibration_B.r41.chunks[0U], &tmp_2.chunks[0U],
                       &tmp_3.chunks[0U], 2);
          z = tmp_3;
        }
      }
    }
  }

  /* End of Start for MATLABSystem: '<Root>/Barometer1' */
  return z;
}

static int64m_T BBB_calibration_times(real_T x, const int64m_T y)
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

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  if (x < 0.0) {
    if (sMultiWordLt(&y.chunks[0U], &tmp_2.chunks[0U], 2)) {
      if (sMultiWordGt(&y.chunks[0U], &tmp.chunks[0U], 2)) {
        MultiWordNeg(&y.chunks[0U], &BBB_calibration_B.r39.chunks[0U], 2);
        sMultiWord2MultiWord(&BBB_calibration_B.r39.chunks[0U], 2,
                             &BBB_calibration_B.n_unsgn.chunks[0U], 2);
      } else {
        BBB_calibration_B.n_unsgn = tmp_3;
      }
    } else {
      sMultiWord2MultiWord(&y.chunks[0U], 2, &BBB_calibration_B.n_unsgn.chunks
                           [0U], 2);
    }

    BBB_calibration_B.n_unsgn = BBB_calibr_eml_mixed_uint64_mul
      (BBB_calibration_B.n_unsgn, -x);
  } else {
    if (sMultiWordLt(&y.chunks[0U], &tmp_2.chunks[0U], 2)) {
      if (sMultiWordGt(&y.chunks[0U], &tmp.chunks[0U], 2)) {
        MultiWordNeg(&y.chunks[0U], &BBB_calibration_B.r39.chunks[0U], 2);
        sMultiWord2MultiWord(&BBB_calibration_B.r39.chunks[0U], 2,
                             &BBB_calibration_B.n_unsgn.chunks[0U], 2);
      } else {
        BBB_calibration_B.n_unsgn = tmp_3;
      }
    } else {
      sMultiWord2MultiWord(&y.chunks[0U], 2, &BBB_calibration_B.n_unsgn.chunks
                           [0U], 2);
    }

    BBB_calibration_B.n_unsgn = BBB_calibr_eml_mixed_uint64_mul
      (BBB_calibration_B.n_unsgn, x);
  }

  if ((sMultiWordLt(&y.chunks[0U], &tmp_2.chunks[0U], 2) && (x > 0.0)) ||
      (sMultiWordGt(&y.chunks[0U], &tmp_2.chunks[0U], 2) && (x < 0.0))) {
    if (uMultiWordLe(&BBB_calibration_B.n_unsgn.chunks[0U], &tmp_1.chunks[0U], 2))
    {
      uMultiWord2MultiWord(&BBB_calibration_B.n_unsgn.chunks[0U], 2,
                           &BBB_calibration_B.r40.chunks[0U], 2);
      MultiWordNeg(&BBB_calibration_B.r40.chunks[0U], &z.chunks[0U], 2);
    } else {
      z = tmp;
    }
  } else if (uMultiWordLe(&BBB_calibration_B.n_unsgn.chunks[0U], &tmp_1.chunks
                          [0U], 2)) {
    uMultiWord2MultiWord(&BBB_calibration_B.n_unsgn.chunks[0U], 2, &z.chunks[0U],
                         2);
  } else {
    z = tmp_0;
  }

  /* End of Start for MATLABSystem: '<Root>/Barometer1' */
  return z;
}

static real_T BBB_ca_bbblueBarometer_stepImpl(const
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

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  bbblueBarometer_BMP_ReadRegiste(obj, data, &a__3);
  rawT = data[3] << 12 | data[4] << 4 | data[5] >> 4;
  sLong2MultiWord(rawT, &BBB_calibration_B.r18.chunks[0U], 2);
  sMultiWordShr(&BBB_calibration_B.r18.chunks[0U], 2, 3U,
                &BBB_calibration_B.r17.chunks[0U], 2);
  sMultiWord2MultiWord(&BBB_calibration_B.r17.chunks[0U], 2,
                       &BBB_calibration_B.r10.chunks[0U], 3);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  uLong2MultiWord(obj->dig_T1, &BBB_calibration_B.r18.chunks[0U], 2);
  sMultiWordShl(&BBB_calibration_B.r18.chunks[0U], 2, 1U,
                &BBB_calibration_B.r17.chunks[0U], 2);
  sMultiWord2MultiWord(&BBB_calibration_B.r17.chunks[0U], 2,
                       &BBB_calibration_B.r11.chunks[0U], 3);
  MultiWordSub(&BBB_calibration_B.r10.chunks[0U], &BBB_calibration_B.r11.chunks
               [0U], &BBB_calibration_B.r9.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r9.chunks[0U], 3,
    &BBB_calibration_B.r16.chunks[0U], 2);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  sLong2MultiWord(obj->dig_T2, &BBB_calibration_B.r17.chunks[0U], 2);
  sMultiWordMul(&BBB_calibration_B.r16.chunks[0U], 2,
                &BBB_calibration_B.r17.chunks[0U], 2,
                &BBB_calibration_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r.chunks[0U], 4,
    &BBB_calibration_B.r15.chunks[0U], 2);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  sMultiWordShr(&BBB_calibration_B.r15.chunks[0U], 2, 11U,
                &BBB_calibration_B.r14.chunks[0U], 2);
  sMultiWord2MultiWord(&BBB_calibration_B.r14.chunks[0U], 2,
                       &BBB_calibration_B.r8.chunks[0U], 3);
  sLong2MultiWord(rawT, &BBB_calibration_B.r20.chunks[0U], 2);
  sMultiWordShr(&BBB_calibration_B.r20.chunks[0U], 2, 4U,
                &BBB_calibration_B.r19.chunks[0U], 2);
  sMultiWord2MultiWord(&BBB_calibration_B.r19.chunks[0U], 2,
                       &BBB_calibration_B.r11.chunks[0U], 3);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  uLong2MultiWord(obj->dig_T1, &BBB_calibration_B.r19.chunks[0U], 2);
  sMultiWord2MultiWord(&BBB_calibration_B.r19.chunks[0U], 2,
                       &BBB_calibration_B.r12.chunks[0U], 3);
  MultiWordSub(&BBB_calibration_B.r11.chunks[0U], &BBB_calibration_B.r12.chunks
               [0U], &BBB_calibration_B.r10.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r10.chunks[0U], 3,
    &BBB_calibration_B.r18.chunks[0U], 2);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  sLong2MultiWord(rawT, &BBB_calibration_B.r21.chunks[0U], 2);
  sMultiWordShr(&BBB_calibration_B.r21.chunks[0U], 2, 4U,
                &BBB_calibration_B.r20.chunks[0U], 2);
  sMultiWord2MultiWord(&BBB_calibration_B.r20.chunks[0U], 2,
                       &BBB_calibration_B.r11.chunks[0U], 3);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  uLong2MultiWord(obj->dig_T1, &BBB_calibration_B.r20.chunks[0U], 2);
  sMultiWord2MultiWord(&BBB_calibration_B.r20.chunks[0U], 2,
                       &BBB_calibration_B.r12.chunks[0U], 3);
  MultiWordSub(&BBB_calibration_B.r11.chunks[0U], &BBB_calibration_B.r12.chunks
               [0U], &BBB_calibration_B.r10.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r10.chunks[0U], 3,
    &BBB_calibration_B.r19.chunks[0U], 2);
  sMultiWordMul(&BBB_calibration_B.r18.chunks[0U], 2,
                &BBB_calibration_B.r19.chunks[0U], 2,
                &BBB_calibration_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r1.chunks[0U], 4,
    &BBB_calibration_B.r17.chunks[0U], 2);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  sMultiWordShr(&BBB_calibration_B.r17.chunks[0U], 2, 12U,
                &BBB_calibration_B.r16.chunks[0U], 2);
  sLong2MultiWord(obj->dig_T3, &BBB_calibration_B.r17.chunks[0U], 2);
  sMultiWordMul(&BBB_calibration_B.r16.chunks[0U], 2,
                &BBB_calibration_B.r17.chunks[0U], 2,
                &BBB_calibration_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r.chunks[0U], 4,
    &BBB_calibration_B.r15.chunks[0U], 2);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  sMultiWordShr(&BBB_calibration_B.r15.chunks[0U], 2, 14U,
                &BBB_calibration_B.r14.chunks[0U], 2);
  sMultiWord2MultiWord(&BBB_calibration_B.r14.chunks[0U], 2,
                       &BBB_calibration_B.r9.chunks[0U], 3);
  MultiWordAdd(&BBB_calibration_B.r8.chunks[0U], &BBB_calibration_B.r9.chunks[0U],
               &BBB_calibration_B.r7.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r7.chunks[0U], 3,
    &BBB_calibration_B.r13.chunks[0U], 2);
  sMultiWord2MultiWord(&BBB_calibration_B.r13.chunks[0U], 2,
                       &BBB_calibration_B.r6.chunks[0U], 3);
  BBB_calibration_B.r13 = tmp_0;
  sMultiWord2MultiWord(&tmp_0.chunks[0U], 2, &BBB_calibration_B.r7.chunks[0U], 3);
  MultiWordSub(&BBB_calibration_B.r6.chunks[0U], &BBB_calibration_B.r7.chunks[0U],
               &BBB_calibration_B.r5.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r5.chunks[0U], 3,
    &BBB_calibration_B.val1.chunks[0U], 2);
  sMultiWordMul(&BBB_calibration_B.val1.chunks[0U], 2,
                &BBB_calibration_B.val1.chunks[0U], 2,
                &BBB_calibration_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r1.chunks[0U], 4,
    &BBB_calibration_B.r14.chunks[0U], 2);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  sLong2MultiWord(obj->dig_P6, &BBB_calibration_B.r15.chunks[0U], 2);
  sMultiWordMul(&BBB_calibration_B.r14.chunks[0U], 2,
                &BBB_calibration_B.r15.chunks[0U], 2,
                &BBB_calibration_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r.chunks[0U], 4,
    &BBB_calibration_B.r13.chunks[0U], 2);
  sMultiWord2MultiWord(&BBB_calibration_B.r13.chunks[0U], 2,
                       &BBB_calibration_B.r6.chunks[0U], 3);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  sLong2MultiWord(obj->dig_P5, &BBB_calibration_B.r15.chunks[0U], 2);
  sMultiWordMul(&BBB_calibration_B.val1.chunks[0U], 2,
                &BBB_calibration_B.r15.chunks[0U], 2,
                &BBB_calibration_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r.chunks[0U], 4,
    &BBB_calibration_B.r14.chunks[0U], 2);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  sMultiWordShl(&BBB_calibration_B.r14.chunks[0U], 2, 17U,
                &BBB_calibration_B.r13.chunks[0U], 2);
  sMultiWord2MultiWord(&BBB_calibration_B.r13.chunks[0U], 2,
                       &BBB_calibration_B.r7.chunks[0U], 3);
  MultiWordAdd(&BBB_calibration_B.r6.chunks[0U], &BBB_calibration_B.r7.chunks[0U],
               &BBB_calibration_B.r5.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r5.chunks[0U], 3,
    &BBB_calibration_B.val4.chunks[0U], 2);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  BBB_calibration_B.r15 = tmp;
  sMultiWord2MultiWord(&tmp.chunks[0U], 2, &BBB_calibration_B.r6.chunks[0U], 3);
  sMultiWordMul(&BBB_calibration_B.val1.chunks[0U], 2,
                &BBB_calibration_B.val1.chunks[0U], 2,
                &BBB_calibration_B.r2.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r2.chunks[0U], 4,
    &BBB_calibration_B.r18.chunks[0U], 2);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  sLong2MultiWord(obj->dig_P3, &BBB_calibration_B.r19.chunks[0U], 2);
  sMultiWordMul(&BBB_calibration_B.r18.chunks[0U], 2,
                &BBB_calibration_B.r19.chunks[0U], 2,
                &BBB_calibration_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r1.chunks[0U], 4,
    &BBB_calibration_B.r17.chunks[0U], 2);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  sMultiWordShr(&BBB_calibration_B.r17.chunks[0U], 2, 8U,
                &BBB_calibration_B.r16.chunks[0U], 2);
  sMultiWord2MultiWord(&BBB_calibration_B.r16.chunks[0U], 2,
                       &BBB_calibration_B.r9.chunks[0U], 3);
  sLong2MultiWord(obj->dig_P2, &BBB_calibration_B.r18.chunks[0U], 2);
  sMultiWordMul(&BBB_calibration_B.val1.chunks[0U], 2,
                &BBB_calibration_B.r18.chunks[0U], 2,
                &BBB_calibration_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r1.chunks[0U], 4,
    &BBB_calibration_B.r17.chunks[0U], 2);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  sMultiWordShl(&BBB_calibration_B.r17.chunks[0U], 2, 12U,
                &BBB_calibration_B.r16.chunks[0U], 2);
  sMultiWord2MultiWord(&BBB_calibration_B.r16.chunks[0U], 2,
                       &BBB_calibration_B.r10.chunks[0U], 3);
  MultiWordAdd(&BBB_calibration_B.r9.chunks[0U], &BBB_calibration_B.r10.chunks
               [0U], &BBB_calibration_B.r8.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r8.chunks[0U], 3,
    &BBB_calibration_B.r15.chunks[0U], 2);
  sMultiWord2MultiWord(&BBB_calibration_B.r15.chunks[0U], 2,
                       &BBB_calibration_B.r7.chunks[0U], 3);
  MultiWordAdd(&BBB_calibration_B.r6.chunks[0U], &BBB_calibration_B.r7.chunks[0U],
               &BBB_calibration_B.r5.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r5.chunks[0U], 3,
    &BBB_calibration_B.r14.chunks[0U], 2);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  uLong2MultiWord(obj->dig_P1, &BBB_calibration_B.r15.chunks[0U], 2);
  sMultiWordMul(&BBB_calibration_B.r14.chunks[0U], 2,
                &BBB_calibration_B.r15.chunks[0U], 2,
                &BBB_calibration_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&BBB_calibration_B.r.chunks[0U], 4,
    &BBB_calibration_B.r13.chunks[0U], 2);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  sMultiWordShr(&BBB_calibration_B.r13.chunks[0U], 2, 33U,
                &BBB_calibration_B.val1.chunks[0U], 2);
  if (sMultiWordEq(&BBB_calibration_B.val1.chunks[0U], &tmp_2.chunks[0U], 2)) {
    y = 0.0;
  } else {
    sLong2MultiWord(1048576 - (data[0] << 12 | data[1] << 4 | data[2] >> 4),
                    &BBB_calibration_B.r17.chunks[0U], 2);
    sMultiWordShl(&BBB_calibration_B.r17.chunks[0U], 2, 31U,
                  &BBB_calibration_B.r16.chunks[0U], 2);
    sMultiWord2MultiWord(&BBB_calibration_B.r16.chunks[0U], 2,
                         &BBB_calibration_B.r7.chunks[0U], 3);
    sMultiWord2MultiWord(&BBB_calibration_B.val4.chunks[0U], 2,
                         &BBB_calibration_B.r10.chunks[0U], 3);
    sLong2MultiWord(obj->dig_P4, &BBB_calibration_B.r18.chunks[0U], 2);
    sMultiWordShl(&BBB_calibration_B.r18.chunks[0U], 2, 35U,
                  &BBB_calibration_B.r17.chunks[0U], 2);
    sMultiWord2MultiWord(&BBB_calibration_B.r17.chunks[0U], 2,
                         &BBB_calibration_B.r11.chunks[0U], 3);
    MultiWordAdd(&BBB_calibration_B.r10.chunks[0U],
                 &BBB_calibration_B.r11.chunks[0U],
                 &BBB_calibration_B.r9.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&BBB_calibration_B.r9.chunks[0U], 3,
      &BBB_calibration_B.r16.chunks[0U], 2);
    sMultiWord2MultiWord(&BBB_calibration_B.r16.chunks[0U], 2,
                         &BBB_calibration_B.r8.chunks[0U], 3);
    MultiWordSub(&BBB_calibration_B.r7.chunks[0U], &BBB_calibration_B.r8.chunks
                 [0U], &BBB_calibration_B.r6.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&BBB_calibration_B.r6.chunks[0U], 3,
      &BBB_calibration_B.r15.chunks[0U], 2);
    BBB_calibration_B.r16 = tmp_1;
    sMultiWordMul(&BBB_calibration_B.r15.chunks[0U], 2, &tmp_1.chunks[0U], 2,
                  &BBB_calibration_B.r5.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&BBB_calibration_B.r5.chunks[0U], 3,
      &BBB_calibration_B.r14.chunks[0U], 2);
    BBB_calibration_B.val1 = BBB_calibration_i64ddiv(sMultiWord2Double
      (&BBB_calibration_B.r14.chunks[0U], 2, 0), BBB_calibration_B.val1);
    sMultiWord2MultiWord(&BBB_calibration_B.val1.chunks[0U], 2,
                         &BBB_calibration_B.r10.chunks[0U], 3);
    sLong2MultiWord(obj->dig_P9, &BBB_calibration_B.r21.chunks[0U], 2);
    sMultiWordShr(&BBB_calibration_B.val1.chunks[0U], 2, 13U,
                  &BBB_calibration_B.r23.chunks[0U], 2);
    sMultiWordShr(&BBB_calibration_B.val1.chunks[0U], 2, 13U,
                  &BBB_calibration_B.r24.chunks[0U], 2);
    sMultiWordMul(&BBB_calibration_B.r23.chunks[0U], 2,
                  &BBB_calibration_B.r24.chunks[0U], 2,
                  &BBB_calibration_B.r1.chunks[0U], 4);
    sMultiWord2sMultiWordSat(&BBB_calibration_B.r1.chunks[0U], 4,
      &BBB_calibration_B.r22.chunks[0U], 2);
    sMultiWordMul(&BBB_calibration_B.r21.chunks[0U], 2,
                  &BBB_calibration_B.r22.chunks[0U], 2,
                  &BBB_calibration_B.r.chunks[0U], 4);
    sMultiWord2sMultiWordSat(&BBB_calibration_B.r.chunks[0U], 4,
      &BBB_calibration_B.r20.chunks[0U], 2);
    sMultiWordShr(&BBB_calibration_B.r20.chunks[0U], 2, 25U,
                  &BBB_calibration_B.r19.chunks[0U], 2);
    sMultiWord2MultiWord(&BBB_calibration_B.r19.chunks[0U], 2,
                         &BBB_calibration_B.r11.chunks[0U], 3);
    MultiWordAdd(&BBB_calibration_B.r10.chunks[0U],
                 &BBB_calibration_B.r11.chunks[0U],
                 &BBB_calibration_B.r9.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&BBB_calibration_B.r9.chunks[0U], 3,
      &BBB_calibration_B.r18.chunks[0U], 2);
    sMultiWord2MultiWord(&BBB_calibration_B.r18.chunks[0U], 2,
                         &BBB_calibration_B.r8.chunks[0U], 3);
    BBB_calibration_B.r19 = BBB_calibration_times((real_T)obj->dig_P8,
      BBB_calibration_B.val1);
    sMultiWordShr(&BBB_calibration_B.r19.chunks[0U], 2, 19U,
                  &BBB_calibration_B.r18.chunks[0U], 2);
    sMultiWord2MultiWord(&BBB_calibration_B.r18.chunks[0U], 2,
                         &BBB_calibration_B.r9.chunks[0U], 3);
    MultiWordAdd(&BBB_calibration_B.r8.chunks[0U], &BBB_calibration_B.r9.chunks
                 [0U], &BBB_calibration_B.r7.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&BBB_calibration_B.r7.chunks[0U], 3,
      &BBB_calibration_B.r17.chunks[0U], 2);
    sMultiWordShr(&BBB_calibration_B.r17.chunks[0U], 2, 8U,
                  &BBB_calibration_B.r16.chunks[0U], 2);
    sMultiWord2MultiWord(&BBB_calibration_B.r16.chunks[0U], 2,
                         &BBB_calibration_B.r6.chunks[0U], 3);
    sLong2MultiWord(obj->dig_P7, &BBB_calibration_B.r17.chunks[0U], 2);
    sMultiWordShl(&BBB_calibration_B.r17.chunks[0U], 2, 4U,
                  &BBB_calibration_B.r16.chunks[0U], 2);
    sMultiWord2MultiWord(&BBB_calibration_B.r16.chunks[0U], 2,
                         &BBB_calibration_B.r7.chunks[0U], 3);
    MultiWordAdd(&BBB_calibration_B.r6.chunks[0U], &BBB_calibration_B.r7.chunks
                 [0U], &BBB_calibration_B.r5.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&BBB_calibration_B.r5.chunks[0U], 3,
      &BBB_calibration_B.r15.chunks[0U], 2);
    y = sMultiWord2Double(&BBB_calibration_B.r15.chunks[0U], 2, 0) / 256.0;
  }

  return y;
}

static void BBB_calibrat_SystemCore_setup_f(beagleboneblue_bbblueMPU9250__T *obj)
{
  /* Start for MATLABSystem: '<Root>/MPU9250' */
  obj->isInitialized = 1;
  MW_IMU_DMP_isAccel_Calibrated();
  MW_IMU_DMP_isGyro_Calibrated();
  MW_IMU_DMP_isMag_Calibrated();

  /* Start for MATLABSystem: '<Root>/MPU9250' */
  obj->i2cObjmpu.MW_I2C_HANDLE = MW_I2C_Open(2, MW_I2C_MASTER);
  obj->i2cObjmpu.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObjmpu.MW_I2C_HANDLE, obj->i2cObjmpu.BusSpeed);
  obj->i2cObjak8963.MW_I2C_HANDLE = MW_I2C_Open(2, MW_I2C_MASTER);
  obj->i2cObjak8963.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObjak8963.MW_I2C_HANDLE, obj->i2cObjak8963.BusSpeed);
  MW_Init_IMU_DMP(200);
  obj->TunablePropsChanged = false;
}

static beagleboneblue_bbblueBaromete_T *bbblueBarometer_bbblueBarometer
  (beagleboneblue_bbblueBaromete_T *obj)
{
  beagleboneblue_bbblueBaromete_T *b_obj;

  /* Start for MATLABSystem: '<Root>/Barometer1' */
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

static void BBB_calibratio_SystemCore_setup(beagleboneblue_bbblueBaromete_T *obj)
{
  int32_T i;
  uint16_T c;
  uint8_T b_output[24];
  uint8_T output_raw[24];
  uint8_T SwappedDataBytes[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T SwappedDataBytes_0;
  uint8_T regVal;
  uint8_T status;

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  obj->isInitialized = 1;
  obj->i2cObj.MW_I2C_HANDLE = MW_I2C_Open(2, MW_I2C_MASTER);
  obj->i2cObj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObj.MW_I2C_HANDLE, obj->i2cObj.BusSpeed);
  regVal = 182U;

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&regVal, (size_t)1 * sizeof
         (uint8_T));
  b_SwappedDataBytes[0] = 224U;

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)2
         * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U, &SwappedDataBytes[0], 2U,
                     false, false);
  MW_usleep(1000);
  status = 208U;

  /* Start for MATLABSystem: '<Root>/Barometer1' */
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
      memcpy((void *)&b_output[0], (void *)&output_raw[0], (size_t)24 * sizeof
             (uint8_T));
    } else {
      for (i = 0; i < 24; i++) {
        b_output[i] = 0U;
      }
    }

    obj->dig_T1 = (uint16_T)(b_output[1] << 8 | b_output[0]);
    c = (uint16_T)(b_output[3] << 8 | b_output[2]);
    memcpy((void *)&obj->dig_T2, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(b_output[5] << 8 | b_output[4]);
    memcpy((void *)&obj->dig_T3, (void *)&c, (size_t)1 * sizeof(int16_T));
    obj->dig_P1 = (uint16_T)(b_output[7] << 8 | b_output[6]);
    c = (uint16_T)(b_output[9] << 8 | b_output[8]);
    memcpy((void *)&obj->dig_P2, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(b_output[11] << 8 | b_output[10]);
    memcpy((void *)&obj->dig_P3, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(b_output[13] << 8 | b_output[12]);
    memcpy((void *)&obj->dig_P4, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(b_output[15] << 8 | b_output[14]);
    memcpy((void *)&obj->dig_P5, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(b_output[17] << 8 | b_output[16]);
    memcpy((void *)&obj->dig_P6, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(b_output[19] << 8 | b_output[18]);
    memcpy((void *)&obj->dig_P7, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(b_output[21] << 8 | b_output[20]);
    memcpy((void *)&obj->dig_P8, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(b_output[23] << 8 | b_output[22]);
    memcpy((void *)&obj->dig_P9, (void *)&c, (size_t)1 * sizeof(int16_T));
  }
}

/* Model step function */
void BBB_calibration_step(void)
{
  /* MATLABSystem: '<Root>/MPU9250' */
  if (BBB_calibration_DW.obj_h.SampleTime !=
      BBB_calibration_P.MPU9250_SampleTime) {
    BBB_calibration_DW.obj_h.SampleTime = BBB_calibration_P.MPU9250_SampleTime;
  }

  if (BBB_calibration_DW.obj_h.TunablePropsChanged) {
    BBB_calibration_DW.obj_h.TunablePropsChanged = false;
  }

  MW_Read_Accel(&BBB_calibration_B.rtb_MPU9250_o1_m[0]);
  BBB_calibration_B.mdata[0] = 0.0;
  BBB_calibration_B.mdata[1] = 0.0;
  BBB_calibration_B.mdata[2] = 0.0;
  MW_Read_Gyro(&BBB_calibration_B.mdata[0]);
  BBB_calibration_B.mdata[0] = 0.0;
  BBB_calibration_B.mdata[1] = 0.0;
  BBB_calibration_B.mdata[2] = 0.0;
  MW_Read_Mag(&BBB_calibration_B.mdata[0]);

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  MATLABSystem: '<Root>/MPU9250'
   */
  BBB_calibration_B.roll = BBB_calibration_B.rtb_MPU9250_o1_m[0] /
    BBB_calibration_B.rtb_MPU9250_o1_m[2];
  BBB_calibration_B.roll = atan(BBB_calibration_B.roll);

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  MATLABSystem: '<Root>/MPU9250'
   */
  BBB_calibration_B.pitch = BBB_calibration_B.rtb_MPU9250_o1_m[1] /
    BBB_calibration_B.rtb_MPU9250_o1_m[2];
  BBB_calibration_B.pitch = atan(BBB_calibration_B.pitch);

  /* MATLABSystem: '<Root>/Barometer1' */
  if (BBB_calibration_DW.obj.SampleTime !=
      BBB_calibration_P.Barometer1_SampleTime) {
    BBB_calibration_DW.obj.SampleTime = BBB_calibration_P.Barometer1_SampleTime;
  }

  BBB_calibration_B.rtb_Barometer1_c = BBB_ca_bbblueBarometer_stepImpl
    (&BBB_calibration_DW.obj);

  /* Sum: '<Root>/Subtract' incorporates:
   *  Constant: '<Root>/Constant'
   *  MATLABSystem: '<Root>/Barometer1'
   */
  BBB_calibration_B.Subtract = BBB_calibration_B.rtb_Barometer1_c -
    BBB_calibration_P.Constant_Value;

  /* Matfile logging */
  rt_UpdateTXYLogVars(BBB_calibration_M->rtwLogInfo,
                      (&BBB_calibration_M->Timing.taskTime0));

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, (real_T)BBB_calibration_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(BBB_calibration_M)!=-1) &&
        !((rtmGetTFinal(BBB_calibration_M)-BBB_calibration_M->Timing.taskTime0) >
          BBB_calibration_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(BBB_calibration_M, "Simulation finished");
    }

    if (rtmGetStopRequested(BBB_calibration_M)) {
      rtmSetErrorStatus(BBB_calibration_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  BBB_calibration_M->Timing.taskTime0 =
    ((time_T)(++BBB_calibration_M->Timing.clockTick0)) *
    BBB_calibration_M->Timing.stepSize0;
}

/* Model initialize function */
void BBB_calibration_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(BBB_calibration_M, 5.0);
  BBB_calibration_M->Timing.stepSize0 = 0.1;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    BBB_calibration_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(BBB_calibration_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(BBB_calibration_M->rtwLogInfo, (NULL));
    rtliSetLogT(BBB_calibration_M->rtwLogInfo, "tout");
    rtliSetLogX(BBB_calibration_M->rtwLogInfo, "");
    rtliSetLogXFinal(BBB_calibration_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(BBB_calibration_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(BBB_calibration_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(BBB_calibration_M->rtwLogInfo, 0);
    rtliSetLogDecimation(BBB_calibration_M->rtwLogInfo, 1);
    rtliSetLogY(BBB_calibration_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(BBB_calibration_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(BBB_calibration_M->rtwLogInfo, (NULL));
  }

  /* External mode info */
  BBB_calibration_M->Sizes.checksums[0] = (656797509U);
  BBB_calibration_M->Sizes.checksums[1] = (4047475739U);
  BBB_calibration_M->Sizes.checksums[2] = (1666128813U);
  BBB_calibration_M->Sizes.checksums[3] = (2752616412U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    BBB_calibration_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(BBB_calibration_M->extModeInfo,
      &BBB_calibration_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(BBB_calibration_M->extModeInfo,
                        BBB_calibration_M->Sizes.checksums);
    rteiSetTPtr(BBB_calibration_M->extModeInfo, rtmGetTPtr(BBB_calibration_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    BBB_calibration_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(BBB_calibration_M->rtwLogInfo, 0.0,
    rtmGetTFinal(BBB_calibration_M), BBB_calibration_M->Timing.stepSize0,
    (&rtmGetErrorStatus(BBB_calibration_M)));

  /* Start for MATLABSystem: '<Root>/MPU9250' */
  BBB_calibration_DW.obj_h.isInitialized = 0;
  BBB_calibration_DW.obj_h.i2cObjmpu.DefaultMaximumBusSpeedInHz = 400000.0;
  BBB_calibration_DW.obj_h.i2cObjmpu.isInitialized = 0;
  BBB_calibration_DW.obj_h.i2cObjmpu.matlabCodegenIsDeleted = false;
  BBB_calibration_DW.obj_h.i2cObjak8963.DefaultMaximumBusSpeedInHz = 400000.0;
  BBB_calibration_DW.obj_h.i2cObjak8963.isInitialized = 0;
  BBB_calibration_DW.obj_h.i2cObjak8963.matlabCodegenIsDeleted = false;
  BBB_calibration_DW.obj_h.matlabCodegenIsDeleted = false;
  BBB_calibration_DW.obj_h.SampleTime = BBB_calibration_P.MPU9250_SampleTime;
  BBB_calibrat_SystemCore_setup_f(&BBB_calibration_DW.obj_h);

  /* Start for MATLABSystem: '<Root>/Barometer1' */
  BBB_calibration_DW.obj.i2cObj.matlabCodegenIsDeleted = true;
  BBB_calibration_DW.obj.matlabCodegenIsDeleted = true;
  bbblueBarometer_bbblueBarometer(&BBB_calibration_DW.obj);
  BBB_calibration_DW.obj.SampleTime = BBB_calibration_P.Barometer1_SampleTime;
  BBB_calibratio_SystemCore_setup(&BBB_calibration_DW.obj);
}

/* Model terminate function */
void BBB_calibration_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/MPU9250' */
  if (!BBB_calibration_DW.obj_h.matlabCodegenIsDeleted) {
    BBB_calibration_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  if (!BBB_calibration_DW.obj_h.i2cObjak8963.matlabCodegenIsDeleted) {
    BBB_calibration_DW.obj_h.i2cObjak8963.matlabCodegenIsDeleted = true;
    if (BBB_calibration_DW.obj_h.i2cObjak8963.isInitialized == 1) {
      BBB_calibration_DW.obj_h.i2cObjak8963.isInitialized = 2;
    }
  }

  if (!BBB_calibration_DW.obj_h.i2cObjmpu.matlabCodegenIsDeleted) {
    BBB_calibration_DW.obj_h.i2cObjmpu.matlabCodegenIsDeleted = true;
    if (BBB_calibration_DW.obj_h.i2cObjmpu.isInitialized == 1) {
      BBB_calibration_DW.obj_h.i2cObjmpu.isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/MPU9250' */

  /* Terminate for MATLABSystem: '<Root>/Barometer1' */
  if (!BBB_calibration_DW.obj.matlabCodegenIsDeleted) {
    BBB_calibration_DW.obj.matlabCodegenIsDeleted = true;
  }

  if (!BBB_calibration_DW.obj.i2cObj.matlabCodegenIsDeleted) {
    BBB_calibration_DW.obj.i2cObj.matlabCodegenIsDeleted = true;
    if (BBB_calibration_DW.obj.i2cObj.isInitialized == 1) {
      BBB_calibration_DW.obj.i2cObj.isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Barometer1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
