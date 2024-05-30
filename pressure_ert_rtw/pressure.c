/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pressure.c
 *
 * Code generated for Simulink model 'pressure'.
 *
 * Model version                  : 2.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon May 20 10:25:17 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pressure.h"
#include "pressure_types.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include <string.h>
#include <stddef.h>
#include "rt_nonfinite.h"
#include <math.h>
#include "pressure_private.h"
#include "zero_crossing_types.h"
#include "pressure_dt.h"

/* Block signals (default storage) */
B_pressure_T pressure_B;

/* Block states (default storage) */
DW_pressure_T pressure_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_pressure_T pressure_PrevZCX;

/* Real-time model */
static RT_MODEL_pressure_T pressure_M_;
RT_MODEL_pressure_T *const pressure_M = &pressure_M_;

/* Forward declaration for local functions */
static void bbblueBarometer_BMP_ReadRegiste(const
  beagleboneblue_bbblueBaromete_T *obj, uint8_T RegisterValue[6], uint8_T
  *varargout_1);
static int64m_T pressure_i64ddiv(real_T x, const int64m_T y);
static uint64m_T pressure_eml_mixed_uint64_mul(const uint64m_T nv, real_T y);
static int64m_T pressure_times(real_T x, const int64m_T y);
static real_T pressu_bbblueBarometer_stepImpl(const
  beagleboneblue_bbblueBaromete_T *obj);
static beagleboneblue_bbblueBaromete_T *bbblueBarometer_bbblueBarometer
  (beagleboneblue_bbblueBaromete_T *obj);
static void pressure_SystemCore_setup(beagleboneblue_bbblueBaromete_T *obj);
static void pressure_SystemCore_setup_j(dsp_simulink_MovingAverage_pr_T *obj);
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

  /* Start for MATLABSystem: '<S1>/Barometer' */
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

  /* End of Start for MATLABSystem: '<S1>/Barometer' */
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

static int64m_T pressure_i64ddiv(real_T x, const int64m_T y)
{
  int64m_T tmp_0;
  int64m_T z;
  uint64m_T tmp;
  int32_T firstbitn;
  int32_T shiftAmount;
  int32_T xexp;
  boolean_T b_p;
  boolean_T tmp_1;
  static const int64m_T tmp_2 = { { 0U, 2147483648U }/* chunks */
  };

  static const uint64m_T tmp_3 = { { 0U, 2147483648U }/* chunks */
  };

  static const uint64m_T tmp_4 = { { 0U, 0U }/* chunks */
  };

  static const uint64m_T tmp_5 = { { 1U, 0U }/* chunks */
  };

  static const uint64m_T tmp_6 = { { MAX_uint32_T, MAX_uint32_T }/* chunks */
  };

  static const int64m_T tmp_7 = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  static const int64m_T tmp_8 = { { 0U, 0U }/* chunks */
  };

  static const uint64m_T tmp_9 = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  int32_T exitg1;
  int32_T exitg2;
  int32_T exitg3;
  boolean_T guard1;

  /* Start for MATLABSystem: '<S1>/Barometer' */
  if (x == 0.0) {
    memcpy((void *)&pressure_B.ux[0], (void *)&x, (size_t)2 * sizeof(uint32_T));
    if ((pressure_B.ux[0] != 0U) || (pressure_B.ux[1] != 0U)) {
      b_p = true;
    } else {
      b_p = false;
    }
  } else {
    b_p = false;
  }

  if (sMultiWordLt(&y.chunks[0U], &tmp_8.chunks[0U], 2)) {
    if (sMultiWordGt(&y.chunks[0U], &tmp_2.chunks[0U], 2)) {
      MultiWordNeg(&y.chunks[0U], &pressure_B.r25.chunks[0U], 2);
      sMultiWord2MultiWord(&pressure_B.r25.chunks[0U], 2,
                           &pressure_B.nk_unsgn.chunks[0U], 2);
    } else {
      pressure_B.nk_unsgn = tmp_3;
    }
  } else {
    sMultiWord2MultiWord(&y.chunks[0U], 2, &pressure_B.nk_unsgn.chunks[0U], 2);
  }

  tmp_1 = ((x < 0.0) || b_p);
  if (tmp_1) {
    pressure_B.x_unsgn = -x;
  } else {
    pressure_B.x_unsgn = x;
  }

  if (uMultiWordEq(&pressure_B.nk_unsgn.chunks[0U], &tmp_4.chunks[0U], 2)) {
    if (pressure_B.x_unsgn > 0.0) {
      pressure_B.res = tmp_6;
    } else {
      pressure_B.res = tmp_4;
    }
  } else if ((pressure_B.x_unsgn <= 0.0) || rtIsNaN(pressure_B.x_unsgn)) {
    pressure_B.res = tmp_4;
  } else if (rtIsInf(pressure_B.x_unsgn)) {
    pressure_B.res = tmp_6;
  } else {
    pressure_B.x_unsgn = frexp(pressure_B.x_unsgn, &shiftAmount);
    Double2MultiWord(rt_roundd_snf(pressure_B.x_unsgn * 9.007199254740992E+15),
                     &pressure_B.xint.chunks[0U], 2);
    xexp = shiftAmount - 53;
    firstbitn = 63;
    do {
      exitg1 = 0;
      uMultiWordShr(&pressure_B.nk_unsgn.chunks[0U], 2, (uint32_T)firstbitn,
                    &pressure_B.res.chunks[0U], 2);
      if (uMultiWordLe(&pressure_B.res.chunks[0U], &tmp_4.chunks[0U], 2)) {
        firstbitn--;
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (shiftAmount - 53 < firstbitn - 53) {
      pressure_B.res = tmp_4;
    } else if (shiftAmount - 53 > firstbitn + 12) {
      pressure_B.res = tmp_6;
    } else {
      pressure_B.res = tmp_4;
      guard1 = false;
      if (firstbitn < 63) {
        uMultiWordDivZero(&pressure_B.xint.chunks[0U], 2,
                          &pressure_B.nk_unsgn.chunks[0U], 2,
                          &pressure_B.res.chunks[0U], 2, &pressure_B.r26.chunks
                          [0U], 2, &pressure_B.r27.chunks[0U], 2,
                          &pressure_B.r28.chunks[0U], 2);
        if (!uMultiWordEq(&pressure_B.nk_unsgn.chunks[0U], &tmp_4.chunks[0U], 2))
        {
          uMultiWordDivZero(&pressure_B.xint.chunks[0U], 2,
                            &pressure_B.nk_unsgn.chunks[0U], 2,
                            &pressure_B.r28.chunks[0U], 2,
                            &pressure_B.r29.chunks[0U], 2,
                            &pressure_B.r30.chunks[0U], 2,
                            &pressure_B.r31.chunks[0U], 2);
          uMultiWordMul(&pressure_B.r28.chunks[0U], 2,
                        &pressure_B.nk_unsgn.chunks[0U], 2,
                        &pressure_B.r3.chunks[0U], 4);
          uMultiWord2MultiWord(&pressure_B.r3.chunks[0U], 4,
                               &pressure_B.r27.chunks[0U], 2);
          MultiWordSub(&pressure_B.xint.chunks[0U], &pressure_B.r27.chunks[0U],
                       &pressure_B.r28.chunks[0U], 2);
          pressure_B.xint = pressure_B.r28;
        }

        if (shiftAmount - 53 < 0) {
          uMultiWordShr(&pressure_B.res.chunks[0U], 2, (uint32_T)(53 -
            shiftAmount), &tmp.chunks[0U], 2);
          uMultiWordShr(&pressure_B.res.chunks[0U], 2, (uint32_T)(52 -
            shiftAmount), &pressure_B.r39.chunks[0U], 2);
          MultiWordAnd(&pressure_B.r39.chunks[0U], &tmp_5.chunks[0U],
                       &pressure_B.r38.chunks[0U], 2);
          MultiWordAdd(&tmp.chunks[0U], &pressure_B.r38.chunks[0U],
                       &pressure_B.res.chunks[0U], 2);
        } else {
          do {
            exitg2 = 0;
            if (xexp > 0) {
              if (63 - firstbitn > xexp) {
                shiftAmount = xexp;
              } else {
                shiftAmount = 63 - firstbitn;
              }

              uMultiWordShr(&pressure_B.res.chunks[0U], 2, (uint32_T)(64 -
                shiftAmount), &pressure_B.r29.chunks[0U], 2);
              if (uMultiWordGt(&pressure_B.r29.chunks[0U], &tmp_4.chunks[0U], 2))
              {
                pressure_B.res = tmp_6;
                exitg2 = 1;
              } else {
                uMultiWordShl(&pressure_B.res.chunks[0U], 2, (uint32_T)
                              shiftAmount, &pressure_B.r32.chunks[0U], 2);
                xexp -= shiftAmount;
                uMultiWordShl(&pressure_B.xint.chunks[0U], 2, (uint32_T)
                              shiftAmount, &pressure_B.r33.chunks[0U], 2);
                pressure_B.xint = pressure_B.r33;
                uMultiWordDivZero(&pressure_B.r33.chunks[0U], 2,
                                  &pressure_B.nk_unsgn.chunks[0U], 2,
                                  &pressure_B.nIsOdd.chunks[0U], 2,
                                  &pressure_B.r34.chunks[0U], 2,
                                  &pressure_B.r35.chunks[0U], 2,
                                  &pressure_B.r36.chunks[0U], 2);
                pressure_B.r35 = tmp_6;
                MultiWordSub(&tmp_6.chunks[0U], &pressure_B.nIsOdd.chunks[0U],
                             &pressure_B.r34.chunks[0U], 2);
                if (uMultiWordLe(&pressure_B.r34.chunks[0U],
                                 &pressure_B.r32.chunks[0U], 2)) {
                  pressure_B.res = tmp_6;
                  exitg2 = 1;
                } else {
                  MultiWordAdd(&pressure_B.r32.chunks[0U],
                               &pressure_B.nIsOdd.chunks[0U],
                               &pressure_B.r35.chunks[0U], 2);
                  pressure_B.res = pressure_B.r35;
                  pressure_B.r36 = tmp_4;
                  if (!uMultiWordEq(&pressure_B.nk_unsgn.chunks[0U],
                                    &tmp_4.chunks[0U], 2)) {
                    uMultiWordDivZero(&pressure_B.r33.chunks[0U], 2,
                                      &pressure_B.nk_unsgn.chunks[0U], 2,
                                      &pressure_B.r37.chunks[0U], 2,
                                      &pressure_B.r38.chunks[0U], 2,
                                      &pressure_B.r39.chunks[0U], 2,
                                      &pressure_B.r40.chunks[0U], 2);
                    uMultiWordMul(&pressure_B.r37.chunks[0U], 2,
                                  &pressure_B.nk_unsgn.chunks[0U], 2,
                                  &pressure_B.r3.chunks[0U], 4);
                    uMultiWord2MultiWord(&pressure_B.r3.chunks[0U], 4,
                                         &tmp.chunks[0U], 2);
                    MultiWordSub(&pressure_B.r33.chunks[0U], &tmp.chunks[0U],
                                 &pressure_B.r37.chunks[0U], 2);
                    pressure_B.xint = pressure_B.r37;
                  }
                }
              }
            } else {
              uMultiWordShl(&pressure_B.xint.chunks[0U], 2, 1U,
                            &pressure_B.r27.chunks[0U], 2);
              if (uMultiWordGe(&pressure_B.r27.chunks[0U],
                               &pressure_B.nk_unsgn.chunks[0U], 2)) {
                MultiWordAdd(&pressure_B.res.chunks[0U], &tmp_5.chunks[0U],
                             &pressure_B.r30.chunks[0U], 2);
                pressure_B.res = pressure_B.r30;
              }

              exitg2 = 1;
            }
          } while (exitg2 == 0);
        }
      } else if (shiftAmount - 53 > 10) {
        uMultiWordShl(&pressure_B.xint.chunks[0U], 2, 11U,
                      &pressure_B.r26.chunks[0U], 2);
        pressure_B.xint = pressure_B.r26;
        xexp = shiftAmount - 64;
        pressure_B.r26 = tmp_5;
        MultiWordAnd(&pressure_B.nk_unsgn.chunks[0U], &tmp_5.chunks[0U],
                     &pressure_B.nIsOdd.chunks[0U], 2);
        if (uMultiWordGe(&pressure_B.xint.chunks[0U],
                         &pressure_B.nk_unsgn.chunks[0U], 2)) {
          pressure_B.res = tmp_5;
          MultiWordSub(&pressure_B.xint.chunks[0U], &pressure_B.nk_unsgn.chunks
                       [0U], &pressure_B.r27.chunks[0U], 2);
          pressure_B.xint = pressure_B.r27;
        } else if (shiftAmount - 64 > 0) {
          xexp = shiftAmount - 65;
          pressure_B.res = tmp_5;
          uMultiWordShr(&pressure_B.nk_unsgn.chunks[0U], 2, 1U,
                        &pressure_B.r27.chunks[0U], 2);
          MultiWordSub(&pressure_B.xint.chunks[0U], &pressure_B.r27.chunks[0U],
                       &pressure_B.r26.chunks[0U], 2);
          uMultiWordShl(&pressure_B.r26.chunks[0U], 2, 1U,
                        &pressure_B.xint.chunks[0U], 2);
          if (uMultiWordNe(&pressure_B.nIsOdd.chunks[0U], &tmp_4.chunks[0U], 2))
          {
            MultiWordSub(&pressure_B.xint.chunks[0U], &tmp_5.chunks[0U],
                         &pressure_B.r28.chunks[0U], 2);
            pressure_B.xint = pressure_B.r28;
          }
        }

        do {
          exitg1 = 0;
          if (xexp > 0) {
            if (uMultiWordEq(&pressure_B.xint.chunks[0U], &tmp_4.chunks[0U], 2))
            {
              uMultiWordShr(&pressure_B.res.chunks[0U], 2, (uint32_T)(64 - xexp),
                            &pressure_B.r40.chunks[0U], 2);
              if (uMultiWordGt(&pressure_B.r40.chunks[0U], &tmp_4.chunks[0U], 2))
              {
                pressure_B.res = tmp_6;
                exitg1 = 1;
              } else {
                uMultiWordShl(&pressure_B.res.chunks[0U], 2, (uint32_T)xexp,
                              &tmp.chunks[0U], 2);
                pressure_B.res = tmp;
                xexp = 0;
              }
            } else {
              firstbitn = 63;
              do {
                exitg3 = 0;
                uMultiWordShr(&pressure_B.xint.chunks[0U], 2, (uint32_T)
                              firstbitn, &pressure_B.r32.chunks[0U], 2);
                if (uMultiWordLe(&pressure_B.r32.chunks[0U], &tmp_4.chunks[0U],
                                 2)) {
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

              uMultiWordShr(&pressure_B.res.chunks[0U], 2, (uint32_T)(64 -
                shiftAmount), &pressure_B.r33.chunks[0U], 2);
              if ((shiftAmount != 0) && uMultiWordGt(&pressure_B.r33.chunks[0U],
                   &tmp_4.chunks[0U], 2)) {
                pressure_B.res = tmp_6;
                exitg1 = 1;
              } else {
                uMultiWordShl(&pressure_B.res.chunks[0U], 2, (uint32_T)
                              shiftAmount, &pressure_B.r34.chunks[0U], 2);
                pressure_B.res = pressure_B.r34;
                xexp -= shiftAmount;
                uMultiWordShl(&pressure_B.xint.chunks[0U], 2, (uint32_T)
                              shiftAmount, &pressure_B.r35.chunks[0U], 2);
                pressure_B.xint = pressure_B.r35;
                if (uMultiWordGt(&pressure_B.xint.chunks[0U],
                                 &pressure_B.nk_unsgn.chunks[0U], 2)) {
                  pressure_B.r26 = tmp_5;
                  MultiWordAdd(&pressure_B.r34.chunks[0U], &tmp_5.chunks[0U],
                               &pressure_B.r39.chunks[0U], 2);
                  pressure_B.res = pressure_B.r39;
                  MultiWordSub(&pressure_B.xint.chunks[0U],
                               &pressure_B.nk_unsgn.chunks[0U],
                               &pressure_B.r26.chunks[0U], 2);
                  pressure_B.xint = pressure_B.r26;
                } else if (xexp > 0) {
                  xexp--;
                  uMultiWordShr(&pressure_B.r34.chunks[0U], 2, 63U,
                                &pressure_B.r36.chunks[0U], 2);
                  if (uMultiWordGt(&pressure_B.r36.chunks[0U], &tmp_4.chunks[0U],
                                   2)) {
                    pressure_B.res = tmp_6;
                    exitg1 = 1;
                  } else {
                    uMultiWordShl(&pressure_B.r34.chunks[0U], 2, 1U,
                                  &pressure_B.r37.chunks[0U], 2);
                    pressure_B.r26 = tmp_5;
                    MultiWordAdd(&pressure_B.r37.chunks[0U], &tmp_5.chunks[0U],
                                 &pressure_B.res.chunks[0U], 2);
                    uMultiWordShr(&pressure_B.nk_unsgn.chunks[0U], 2, 1U,
                                  &pressure_B.r26.chunks[0U], 2);
                    MultiWordSub(&pressure_B.xint.chunks[0U],
                                 &pressure_B.r26.chunks[0U],
                                 &pressure_B.r37.chunks[0U], 2);
                    uMultiWordShl(&pressure_B.r37.chunks[0U], 2, 1U,
                                  &pressure_B.xint.chunks[0U], 2);
                    pressure_B.r37 = tmp_4;
                    if (uMultiWordNe(&pressure_B.nIsOdd.chunks[0U],
                                     &tmp_4.chunks[0U], 2)) {
                      MultiWordSub(&pressure_B.xint.chunks[0U], &tmp_5.chunks[0U],
                                   &pressure_B.r38.chunks[0U], 2);
                      pressure_B.xint = pressure_B.r38;
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
        uMultiWordShl(&pressure_B.xint.chunks[0U], 2, 10U,
                      &pressure_B.r26.chunks[0U], 2);
        pressure_B.xint = pressure_B.r26;
        guard1 = true;
      }

      if (guard1) {
        MultiWordAnd(&pressure_B.xint.chunks[0U], &tmp_3.chunks[0U],
                     &pressure_B.r29.chunks[0U], 2);
        uMultiWordShl(&pressure_B.xint.chunks[0U], 2, 1U,
                      &pressure_B.r30.chunks[0U], 2);
        if (uMultiWordNe(&pressure_B.r29.chunks[0U], &tmp_4.chunks[0U], 2) ||
            uMultiWordGe(&pressure_B.r30.chunks[0U],
                         &pressure_B.nk_unsgn.chunks[0U], 2)) {
          MultiWordAdd(&pressure_B.res.chunks[0U], &tmp_5.chunks[0U],
                       &pressure_B.r31.chunks[0U], 2);
          pressure_B.res = pressure_B.r31;
        }
      }
    }
  }

  if ((sMultiWordLt(&y.chunks[0U], &tmp_8.chunks[0U], 2) && (x >= 0.0) && (!b_p))
      || (sMultiWordGe(&y.chunks[0U], &tmp_8.chunks[0U], 2) && tmp_1)) {
    if (uMultiWordLe(&pressure_B.res.chunks[0U], &tmp_9.chunks[0U], 2)) {
      uMultiWord2MultiWord(&pressure_B.res.chunks[0U], 2, &tmp_0.chunks[0U], 2);
      MultiWordNeg(&tmp_0.chunks[0U], &z.chunks[0U], 2);
    } else {
      z = tmp_2;
    }
  } else if (uMultiWordLe(&pressure_B.res.chunks[0U], &tmp_9.chunks[0U], 2)) {
    uMultiWord2MultiWord(&pressure_B.res.chunks[0U], 2, &z.chunks[0U], 2);
  } else {
    z = tmp_7;
  }

  /* End of Start for MATLABSystem: '<S1>/Barometer' */
  return z;
}

static uint64m_T pressure_eml_mixed_uint64_mul(const uint64m_T nv, real_T y)
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

  /* Start for MATLABSystem: '<S1>/Barometer' */
  if (rtIsNaN(y) || (y <= 0.0)) {
    z = tmp_7;
  } else {
    pressure_B.yd = frexp(y, &ex_t);
    if (ex_t <= -64) {
      z = tmp_7;
    } else {
      Double2MultiWord(rt_roundd_snf(pressure_B.yd * 9.007199254740992E+15),
                       &pressure_B.yint.chunks[0U], 2);
      uMultiWordShr(&pressure_B.yint.chunks[0U], 2, 32U,
                    &pressure_B.b_y1.chunks[0U], 2);
      MultiWordAnd(&pressure_B.yint.chunks[0U], &tmp_8.chunks[0U],
                   &pressure_B.b_y0.chunks[0U], 2);
      if (uMultiWordEq(&nv.chunks[0U], &tmp_7.chunks[0U], 2)) {
        z = tmp_7;
      } else if (rtIsInf(y)) {
        z = tmp_5;
      } else if (ex_t - 53 > 64) {
        z = tmp_5;
      } else {
        uMultiWordShr(&nv.chunks[0U], 2, 32U, &pressure_B.n1.chunks[0U], 2);
        pressure_B.r43 = nv;
        pressure_B.r44 = tmp_8;
        MultiWordAnd(&nv.chunks[0U], &tmp_8.chunks[0U], &pressure_B.yint.chunks
                     [0U], 2);
        uMultiWordMul(&pressure_B.yint.chunks[0U], 2, &pressure_B.b_y0.chunks[0U],
                      2, &pressure_B.r4.chunks[0U], 4);
        uMultiWord2MultiWord(&pressure_B.r4.chunks[0U], 4,
                             &pressure_B.ldword.chunks[0U], 2);
        uMultiWordMul(&pressure_B.yint.chunks[0U], 2, &pressure_B.b_y1.chunks[0U],
                      2, &pressure_B.r4.chunks[0U], 4);
        uMultiWord2MultiWord(&pressure_B.r4.chunks[0U], 4,
                             &pressure_B.temp0.chunks[0U], 2);
        uMultiWordMul(&pressure_B.n1.chunks[0U], 2, &pressure_B.b_y0.chunks[0U],
                      2, &pressure_B.r4.chunks[0U], 4);
        uMultiWord2MultiWord(&pressure_B.r4.chunks[0U], 4,
                             &pressure_B.b_y0.chunks[0U], 2);
        pressure_B.r45 = tmp_8;
        MultiWordAnd(&pressure_B.temp0.chunks[0U], &tmp_8.chunks[0U],
                     &pressure_B.r44.chunks[0U], 2);
        uMultiWordShr(&pressure_B.ldword.chunks[0U], 2, 32U,
                      &pressure_B.r45.chunks[0U], 2);
        MultiWordAdd(&pressure_B.r44.chunks[0U], &pressure_B.r45.chunks[0U],
                     &pressure_B.r43.chunks[0U], 2);
        pressure_B.r45 = tmp_8;
        MultiWordAnd(&pressure_B.b_y0.chunks[0U], &tmp_8.chunks[0U],
                     &pressure_B.r44.chunks[0U], 2);
        MultiWordAdd(&pressure_B.r43.chunks[0U], &pressure_B.r44.chunks[0U],
                     &pressure_B.yint.chunks[0U], 2);
        pressure_B.r44 = tmp_8;
        MultiWordAnd(&pressure_B.ldword.chunks[0U], &tmp_8.chunks[0U],
                     &pressure_B.r43.chunks[0U], 2);
        uMultiWordShl(&pressure_B.yint.chunks[0U], 2, 32U,
                      &pressure_B.r44.chunks[0U], 2);
        MultiWordAdd(&pressure_B.r43.chunks[0U], &pressure_B.r44.chunks[0U],
                     &pressure_B.ldword.chunks[0U], 2);
        uMultiWordMul(&pressure_B.n1.chunks[0U], 2, &pressure_B.b_y1.chunks[0U],
                      2, &pressure_B.r4.chunks[0U], 4);
        uMultiWord2MultiWord(&pressure_B.r4.chunks[0U], 4,
                             &pressure_B.r45.chunks[0U], 2);
        uMultiWordShr(&pressure_B.temp0.chunks[0U], 2, 32U, &tmp_2.chunks[0U], 2);
        MultiWordAdd(&pressure_B.r45.chunks[0U], &tmp_2.chunks[0U],
                     &pressure_B.r44.chunks[0U], 2);
        uMultiWordShr(&pressure_B.b_y0.chunks[0U], 2, 32U,
                      &pressure_B.r45.chunks[0U], 2);
        MultiWordAdd(&pressure_B.r44.chunks[0U], &pressure_B.r45.chunks[0U],
                     &pressure_B.r43.chunks[0U], 2);
        uMultiWordShr(&pressure_B.yint.chunks[0U], 2, 32U,
                      &pressure_B.r44.chunks[0U], 2);
        MultiWordAdd(&pressure_B.r43.chunks[0U], &pressure_B.r44.chunks[0U],
                     &pressure_B.yint.chunks[0U], 2);
        if (ex_t - 53 >= 0) {
          if (uMultiWordGt(&pressure_B.yint.chunks[0U], &tmp_7.chunks[0U], 2)) {
            z = tmp_5;
          } else {
            tmp = (int16_T)(117 - ex_t);
            if (117 - ex_t < 0) {
              tmp = 0;
            }

            uMultiWordShr(&pressure_B.ldword.chunks[0U], 2, (uint32_T)tmp,
                          &tmp_4.chunks[0U], 2);
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

              uMultiWordShl(&pressure_B.ldword.chunks[0U], 2, (uint32_T)tmp,
                            &z.chunks[0U], 2);
            }
          }
        } else if (ex_t - 53 > -64) {
          tmp = (int16_T)(53 - ex_t);
          if (53 - ex_t < 0) {
            tmp = 0;
          }

          uMultiWordShr(&pressure_B.yint.chunks[0U], 2, (uint32_T)tmp,
                        &pressure_B.r43.chunks[0U], 2);
          if (uMultiWordGt(&pressure_B.r43.chunks[0U], &tmp_7.chunks[0U], 2)) {
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

            uMultiWordShr(&pressure_B.ldword.chunks[0U], 2, (uint32_T)tmp,
                          &tmp_4.chunks[0U], 2);
            uMultiWordShl(&pressure_B.yint.chunks[0U], 2, (uint32_T)tmp_0,
                          &z.chunks[0U], 2);
            MultiWordAdd(&tmp_4.chunks[0U], &z.chunks[0U], &tmp_3.chunks[0U], 2);
            uMultiWordShr(&pressure_B.ldword.chunks[0U], 2, (uint32_T)tmp_1,
                          &z.chunks[0U], 2);
            MultiWordAnd(&z.chunks[0U], &tmp_6.chunks[0U], &tmp_4.chunks[0U], 2);
            MultiWordAdd(&tmp_3.chunks[0U], &tmp_4.chunks[0U], &z.chunks[0U], 2);
          }
        } else if (ex_t - 53 == -64) {
          uMultiWordShr(&pressure_B.ldword.chunks[0U], 2, 63U,
                        &pressure_B.r44.chunks[0U], 2);
          MultiWordAnd(&pressure_B.r44.chunks[0U], &tmp_6.chunks[0U],
                       &pressure_B.r43.chunks[0U], 2);
          MultiWordAdd(&pressure_B.yint.chunks[0U], &pressure_B.r43.chunks[0U],
                       &pressure_B.r44.chunks[0U], 2);
          z = pressure_B.r44;
        } else {
          tmp = (int16_T)-(ex_t + 11);
          if (-(ex_t + 11) < 0) {
            tmp = 0;
          }

          tmp_0 = (int16_T)-(ex_t + 12);
          if (-(ex_t + 12) < 0) {
            tmp_0 = 0;
          }

          uMultiWordShr(&pressure_B.yint.chunks[0U], 2, (uint32_T)tmp,
                        &pressure_B.r43.chunks[0U], 2);
          uMultiWordShr(&pressure_B.yint.chunks[0U], 2, (uint32_T)tmp_0,
                        &pressure_B.r45.chunks[0U], 2);
          MultiWordAnd(&pressure_B.r45.chunks[0U], &tmp_6.chunks[0U],
                       &pressure_B.r44.chunks[0U], 2);
          MultiWordAdd(&pressure_B.r43.chunks[0U], &pressure_B.r44.chunks[0U],
                       &pressure_B.r45.chunks[0U], 2);
          z = pressure_B.r45;
        }
      }
    }
  }

  /* End of Start for MATLABSystem: '<S1>/Barometer' */
  return z;
}

static int64m_T pressure_times(real_T x, const int64m_T y)
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

  /* Start for MATLABSystem: '<S1>/Barometer' */
  if (x < 0.0) {
    if (sMultiWordLt(&y.chunks[0U], &tmp_2.chunks[0U], 2)) {
      if (sMultiWordGt(&y.chunks[0U], &tmp.chunks[0U], 2)) {
        MultiWordNeg(&y.chunks[0U], &pressure_B.r41.chunks[0U], 2);
        sMultiWord2MultiWord(&pressure_B.r41.chunks[0U], 2,
                             &pressure_B.n_unsgn.chunks[0U], 2);
      } else {
        pressure_B.n_unsgn = tmp_3;
      }
    } else {
      sMultiWord2MultiWord(&y.chunks[0U], 2, &pressure_B.n_unsgn.chunks[0U], 2);
    }

    pressure_B.n_unsgn = pressure_eml_mixed_uint64_mul(pressure_B.n_unsgn, -x);
  } else {
    if (sMultiWordLt(&y.chunks[0U], &tmp_2.chunks[0U], 2)) {
      if (sMultiWordGt(&y.chunks[0U], &tmp.chunks[0U], 2)) {
        MultiWordNeg(&y.chunks[0U], &pressure_B.r41.chunks[0U], 2);
        sMultiWord2MultiWord(&pressure_B.r41.chunks[0U], 2,
                             &pressure_B.n_unsgn.chunks[0U], 2);
      } else {
        pressure_B.n_unsgn = tmp_3;
      }
    } else {
      sMultiWord2MultiWord(&y.chunks[0U], 2, &pressure_B.n_unsgn.chunks[0U], 2);
    }

    pressure_B.n_unsgn = pressure_eml_mixed_uint64_mul(pressure_B.n_unsgn, x);
  }

  if ((sMultiWordLt(&y.chunks[0U], &tmp_2.chunks[0U], 2) && (x > 0.0)) ||
      (sMultiWordGt(&y.chunks[0U], &tmp_2.chunks[0U], 2) && (x < 0.0))) {
    if (uMultiWordLe(&pressure_B.n_unsgn.chunks[0U], &tmp_1.chunks[0U], 2)) {
      uMultiWord2MultiWord(&pressure_B.n_unsgn.chunks[0U], 2,
                           &pressure_B.r42.chunks[0U], 2);
      MultiWordNeg(&pressure_B.r42.chunks[0U], &z.chunks[0U], 2);
    } else {
      z = tmp;
    }
  } else if (uMultiWordLe(&pressure_B.n_unsgn.chunks[0U], &tmp_1.chunks[0U], 2))
  {
    uMultiWord2MultiWord(&pressure_B.n_unsgn.chunks[0U], 2, &z.chunks[0U], 2);
  } else {
    z = tmp_0;
  }

  /* End of Start for MATLABSystem: '<S1>/Barometer' */
  return z;
}

static real_T pressu_bbblueBarometer_stepImpl(const
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

  /* Start for MATLABSystem: '<S1>/Barometer' */
  bbblueBarometer_BMP_ReadRegiste(obj, data, &a__3);
  rawT = data[3] << 12 | data[4] << 4 | data[5] >> 4;
  sLong2MultiWord(rawT, &pressure_B.r18.chunks[0U], 2);
  sMultiWordShr(&pressure_B.r18.chunks[0U], 2, 3U, &pressure_B.r17.chunks[0U], 2);
  sMultiWord2MultiWord(&pressure_B.r17.chunks[0U], 2, &pressure_B.r10.chunks[0U],
                       3);

  /* Start for MATLABSystem: '<S1>/Barometer' */
  uLong2MultiWord(obj->dig_T1, &pressure_B.r18.chunks[0U], 2);
  sMultiWordShl(&pressure_B.r18.chunks[0U], 2, 1U, &pressure_B.r17.chunks[0U], 2);
  sMultiWord2MultiWord(&pressure_B.r17.chunks[0U], 2, &pressure_B.r11.chunks[0U],
                       3);
  MultiWordSub(&pressure_B.r10.chunks[0U], &pressure_B.r11.chunks[0U],
               &pressure_B.r9.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&pressure_B.r9.chunks[0U], 3, &pressure_B.r16.chunks
    [0U], 2);

  /* Start for MATLABSystem: '<S1>/Barometer' */
  sLong2MultiWord(obj->dig_T2, &pressure_B.r17.chunks[0U], 2);
  sMultiWordMul(&pressure_B.r16.chunks[0U], 2, &pressure_B.r17.chunks[0U], 2,
                &pressure_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&pressure_B.r.chunks[0U], 4, &pressure_B.r15.chunks
    [0U], 2);

  /* Start for MATLABSystem: '<S1>/Barometer' */
  sMultiWordShr(&pressure_B.r15.chunks[0U], 2, 11U, &pressure_B.r14.chunks[0U],
                2);
  sMultiWord2MultiWord(&pressure_B.r14.chunks[0U], 2, &pressure_B.r8.chunks[0U],
                       3);
  sLong2MultiWord(rawT, &pressure_B.r20.chunks[0U], 2);
  sMultiWordShr(&pressure_B.r20.chunks[0U], 2, 4U, &pressure_B.r19.chunks[0U], 2);
  sMultiWord2MultiWord(&pressure_B.r19.chunks[0U], 2, &pressure_B.r11.chunks[0U],
                       3);

  /* Start for MATLABSystem: '<S1>/Barometer' */
  uLong2MultiWord(obj->dig_T1, &pressure_B.r19.chunks[0U], 2);
  sMultiWord2MultiWord(&pressure_B.r19.chunks[0U], 2, &pressure_B.r12.chunks[0U],
                       3);
  MultiWordSub(&pressure_B.r11.chunks[0U], &pressure_B.r12.chunks[0U],
               &pressure_B.r10.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&pressure_B.r10.chunks[0U], 3,
    &pressure_B.r18.chunks[0U], 2);

  /* Start for MATLABSystem: '<S1>/Barometer' */
  sLong2MultiWord(rawT, &pressure_B.r21.chunks[0U], 2);
  sMultiWordShr(&pressure_B.r21.chunks[0U], 2, 4U, &pressure_B.r20.chunks[0U], 2);
  sMultiWord2MultiWord(&pressure_B.r20.chunks[0U], 2, &pressure_B.r11.chunks[0U],
                       3);

  /* Start for MATLABSystem: '<S1>/Barometer' */
  uLong2MultiWord(obj->dig_T1, &pressure_B.r20.chunks[0U], 2);
  sMultiWord2MultiWord(&pressure_B.r20.chunks[0U], 2, &pressure_B.r12.chunks[0U],
                       3);
  MultiWordSub(&pressure_B.r11.chunks[0U], &pressure_B.r12.chunks[0U],
               &pressure_B.r10.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&pressure_B.r10.chunks[0U], 3,
    &pressure_B.r19.chunks[0U], 2);
  sMultiWordMul(&pressure_B.r18.chunks[0U], 2, &pressure_B.r19.chunks[0U], 2,
                &pressure_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&pressure_B.r1.chunks[0U], 4, &pressure_B.r17.chunks
    [0U], 2);

  /* Start for MATLABSystem: '<S1>/Barometer' */
  sMultiWordShr(&pressure_B.r17.chunks[0U], 2, 12U, &pressure_B.r16.chunks[0U],
                2);
  sLong2MultiWord(obj->dig_T3, &pressure_B.r17.chunks[0U], 2);
  sMultiWordMul(&pressure_B.r16.chunks[0U], 2, &pressure_B.r17.chunks[0U], 2,
                &pressure_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&pressure_B.r.chunks[0U], 4, &pressure_B.r15.chunks
    [0U], 2);

  /* Start for MATLABSystem: '<S1>/Barometer' */
  sMultiWordShr(&pressure_B.r15.chunks[0U], 2, 14U, &pressure_B.r14.chunks[0U],
                2);
  sMultiWord2MultiWord(&pressure_B.r14.chunks[0U], 2, &pressure_B.r9.chunks[0U],
                       3);
  MultiWordAdd(&pressure_B.r8.chunks[0U], &pressure_B.r9.chunks[0U],
               &pressure_B.r7.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&pressure_B.r7.chunks[0U], 3, &pressure_B.r13.chunks
    [0U], 2);
  sMultiWord2MultiWord(&pressure_B.r13.chunks[0U], 2, &pressure_B.r6.chunks[0U],
                       3);
  pressure_B.r13 = tmp_0;
  sMultiWord2MultiWord(&tmp_0.chunks[0U], 2, &pressure_B.r7.chunks[0U], 3);
  MultiWordSub(&pressure_B.r6.chunks[0U], &pressure_B.r7.chunks[0U],
               &pressure_B.r5.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&pressure_B.r5.chunks[0U], 3,
    &pressure_B.val1.chunks[0U], 2);
  sMultiWordMul(&pressure_B.val1.chunks[0U], 2, &pressure_B.val1.chunks[0U], 2,
                &pressure_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&pressure_B.r1.chunks[0U], 4, &pressure_B.r14.chunks
    [0U], 2);

  /* Start for MATLABSystem: '<S1>/Barometer' */
  sLong2MultiWord(obj->dig_P6, &pressure_B.r15.chunks[0U], 2);
  sMultiWordMul(&pressure_B.r14.chunks[0U], 2, &pressure_B.r15.chunks[0U], 2,
                &pressure_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&pressure_B.r.chunks[0U], 4, &pressure_B.r13.chunks
    [0U], 2);
  sMultiWord2MultiWord(&pressure_B.r13.chunks[0U], 2, &pressure_B.r6.chunks[0U],
                       3);

  /* Start for MATLABSystem: '<S1>/Barometer' */
  sLong2MultiWord(obj->dig_P5, &pressure_B.r15.chunks[0U], 2);
  sMultiWordMul(&pressure_B.val1.chunks[0U], 2, &pressure_B.r15.chunks[0U], 2,
                &pressure_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&pressure_B.r.chunks[0U], 4, &pressure_B.r14.chunks
    [0U], 2);

  /* Start for MATLABSystem: '<S1>/Barometer' */
  sMultiWordShl(&pressure_B.r14.chunks[0U], 2, 17U, &pressure_B.r13.chunks[0U],
                2);
  sMultiWord2MultiWord(&pressure_B.r13.chunks[0U], 2, &pressure_B.r7.chunks[0U],
                       3);
  MultiWordAdd(&pressure_B.r6.chunks[0U], &pressure_B.r7.chunks[0U],
               &pressure_B.r5.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&pressure_B.r5.chunks[0U], 3,
    &pressure_B.val4.chunks[0U], 2);

  /* Start for MATLABSystem: '<S1>/Barometer' */
  pressure_B.r15 = tmp;
  sMultiWord2MultiWord(&tmp.chunks[0U], 2, &pressure_B.r6.chunks[0U], 3);
  sMultiWordMul(&pressure_B.val1.chunks[0U], 2, &pressure_B.val1.chunks[0U], 2,
                &pressure_B.r2.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&pressure_B.r2.chunks[0U], 4, &pressure_B.r18.chunks
    [0U], 2);

  /* Start for MATLABSystem: '<S1>/Barometer' */
  sLong2MultiWord(obj->dig_P3, &pressure_B.r19.chunks[0U], 2);
  sMultiWordMul(&pressure_B.r18.chunks[0U], 2, &pressure_B.r19.chunks[0U], 2,
                &pressure_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&pressure_B.r1.chunks[0U], 4, &pressure_B.r17.chunks
    [0U], 2);

  /* Start for MATLABSystem: '<S1>/Barometer' */
  sMultiWordShr(&pressure_B.r17.chunks[0U], 2, 8U, &pressure_B.r16.chunks[0U], 2);
  sMultiWord2MultiWord(&pressure_B.r16.chunks[0U], 2, &pressure_B.r9.chunks[0U],
                       3);
  sLong2MultiWord(obj->dig_P2, &pressure_B.r18.chunks[0U], 2);
  sMultiWordMul(&pressure_B.val1.chunks[0U], 2, &pressure_B.r18.chunks[0U], 2,
                &pressure_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&pressure_B.r1.chunks[0U], 4, &pressure_B.r17.chunks
    [0U], 2);

  /* Start for MATLABSystem: '<S1>/Barometer' */
  sMultiWordShl(&pressure_B.r17.chunks[0U], 2, 12U, &pressure_B.r16.chunks[0U],
                2);
  sMultiWord2MultiWord(&pressure_B.r16.chunks[0U], 2, &pressure_B.r10.chunks[0U],
                       3);
  MultiWordAdd(&pressure_B.r9.chunks[0U], &pressure_B.r10.chunks[0U],
               &pressure_B.r8.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&pressure_B.r8.chunks[0U], 3, &pressure_B.r15.chunks
    [0U], 2);
  sMultiWord2MultiWord(&pressure_B.r15.chunks[0U], 2, &pressure_B.r7.chunks[0U],
                       3);
  MultiWordAdd(&pressure_B.r6.chunks[0U], &pressure_B.r7.chunks[0U],
               &pressure_B.r5.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&pressure_B.r5.chunks[0U], 3, &pressure_B.r14.chunks
    [0U], 2);

  /* Start for MATLABSystem: '<S1>/Barometer' */
  uLong2MultiWord(obj->dig_P1, &pressure_B.r15.chunks[0U], 2);
  sMultiWordMul(&pressure_B.r14.chunks[0U], 2, &pressure_B.r15.chunks[0U], 2,
                &pressure_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&pressure_B.r.chunks[0U], 4, &pressure_B.r13.chunks
    [0U], 2);

  /* Start for MATLABSystem: '<S1>/Barometer' */
  sMultiWordShr(&pressure_B.r13.chunks[0U], 2, 33U, &pressure_B.val1.chunks[0U],
                2);
  if (sMultiWordEq(&pressure_B.val1.chunks[0U], &tmp_2.chunks[0U], 2)) {
    y = 0.0;
  } else {
    sLong2MultiWord(1048576 - (data[0] << 12 | data[1] << 4 | data[2] >> 4),
                    &pressure_B.r17.chunks[0U], 2);
    sMultiWordShl(&pressure_B.r17.chunks[0U], 2, 31U, &pressure_B.r16.chunks[0U],
                  2);
    sMultiWord2MultiWord(&pressure_B.r16.chunks[0U], 2, &pressure_B.r7.chunks[0U],
                         3);
    sMultiWord2MultiWord(&pressure_B.val4.chunks[0U], 2, &pressure_B.r10.chunks
                         [0U], 3);
    sLong2MultiWord(obj->dig_P4, &pressure_B.r18.chunks[0U], 2);
    sMultiWordShl(&pressure_B.r18.chunks[0U], 2, 35U, &pressure_B.r17.chunks[0U],
                  2);
    sMultiWord2MultiWord(&pressure_B.r17.chunks[0U], 2, &pressure_B.r11.chunks
                         [0U], 3);
    MultiWordAdd(&pressure_B.r10.chunks[0U], &pressure_B.r11.chunks[0U],
                 &pressure_B.r9.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&pressure_B.r9.chunks[0U], 3,
      &pressure_B.r16.chunks[0U], 2);
    sMultiWord2MultiWord(&pressure_B.r16.chunks[0U], 2, &pressure_B.r8.chunks[0U],
                         3);
    MultiWordSub(&pressure_B.r7.chunks[0U], &pressure_B.r8.chunks[0U],
                 &pressure_B.r6.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&pressure_B.r6.chunks[0U], 3,
      &pressure_B.r15.chunks[0U], 2);
    pressure_B.r16 = tmp_1;
    sMultiWordMul(&pressure_B.r15.chunks[0U], 2, &tmp_1.chunks[0U], 2,
                  &pressure_B.r5.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&pressure_B.r5.chunks[0U], 3,
      &pressure_B.r14.chunks[0U], 2);
    pressure_B.val1 = pressure_i64ddiv(sMultiWord2Double(&pressure_B.r14.chunks
      [0U], 2, 0), pressure_B.val1);
    sMultiWord2MultiWord(&pressure_B.val1.chunks[0U], 2, &pressure_B.r10.chunks
                         [0U], 3);
    sLong2MultiWord(obj->dig_P9, &pressure_B.r21.chunks[0U], 2);
    sMultiWordShr(&pressure_B.val1.chunks[0U], 2, 13U, &pressure_B.r23.chunks[0U],
                  2);
    sMultiWordShr(&pressure_B.val1.chunks[0U], 2, 13U, &pressure_B.r24.chunks[0U],
                  2);
    sMultiWordMul(&pressure_B.r23.chunks[0U], 2, &pressure_B.r24.chunks[0U], 2,
                  &pressure_B.r1.chunks[0U], 4);
    sMultiWord2sMultiWordSat(&pressure_B.r1.chunks[0U], 4,
      &pressure_B.r22.chunks[0U], 2);
    sMultiWordMul(&pressure_B.r21.chunks[0U], 2, &pressure_B.r22.chunks[0U], 2,
                  &pressure_B.r.chunks[0U], 4);
    sMultiWord2sMultiWordSat(&pressure_B.r.chunks[0U], 4,
      &pressure_B.r20.chunks[0U], 2);
    sMultiWordShr(&pressure_B.r20.chunks[0U], 2, 25U, &pressure_B.r19.chunks[0U],
                  2);
    sMultiWord2MultiWord(&pressure_B.r19.chunks[0U], 2, &pressure_B.r11.chunks
                         [0U], 3);
    MultiWordAdd(&pressure_B.r10.chunks[0U], &pressure_B.r11.chunks[0U],
                 &pressure_B.r9.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&pressure_B.r9.chunks[0U], 3,
      &pressure_B.r18.chunks[0U], 2);
    sMultiWord2MultiWord(&pressure_B.r18.chunks[0U], 2, &pressure_B.r8.chunks[0U],
                         3);
    pressure_B.r19 = pressure_times((real_T)obj->dig_P8, pressure_B.val1);
    sMultiWordShr(&pressure_B.r19.chunks[0U], 2, 19U, &pressure_B.r18.chunks[0U],
                  2);
    sMultiWord2MultiWord(&pressure_B.r18.chunks[0U], 2, &pressure_B.r9.chunks[0U],
                         3);
    MultiWordAdd(&pressure_B.r8.chunks[0U], &pressure_B.r9.chunks[0U],
                 &pressure_B.r7.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&pressure_B.r7.chunks[0U], 3,
      &pressure_B.r17.chunks[0U], 2);
    sMultiWordShr(&pressure_B.r17.chunks[0U], 2, 8U, &pressure_B.r16.chunks[0U],
                  2);
    sMultiWord2MultiWord(&pressure_B.r16.chunks[0U], 2, &pressure_B.r6.chunks[0U],
                         3);
    sLong2MultiWord(obj->dig_P7, &pressure_B.r17.chunks[0U], 2);
    sMultiWordShl(&pressure_B.r17.chunks[0U], 2, 4U, &pressure_B.r16.chunks[0U],
                  2);
    sMultiWord2MultiWord(&pressure_B.r16.chunks[0U], 2, &pressure_B.r7.chunks[0U],
                         3);
    MultiWordAdd(&pressure_B.r6.chunks[0U], &pressure_B.r7.chunks[0U],
                 &pressure_B.r5.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&pressure_B.r5.chunks[0U], 3,
      &pressure_B.r15.chunks[0U], 2);
    y = sMultiWord2Double(&pressure_B.r15.chunks[0U], 2, 0) / 256.0;
  }

  return y;
}

static beagleboneblue_bbblueBaromete_T *bbblueBarometer_bbblueBarometer
  (beagleboneblue_bbblueBaromete_T *obj)
{
  beagleboneblue_bbblueBaromete_T *b_obj;

  /* Start for MATLABSystem: '<S1>/Barometer' */
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

static void pressure_SystemCore_setup(beagleboneblue_bbblueBaromete_T *obj)
{
  int32_T i;
  uint16_T c;
  uint8_T output_raw[24];
  uint8_T SwappedDataBytes[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T SwappedDataBytes_0;
  uint8_T regVal;
  uint8_T status;

  /* Start for MATLABSystem: '<S1>/Barometer' */
  obj->isInitialized = 1;
  obj->i2cObj.MW_I2C_HANDLE = MW_I2C_Open(2, MW_I2C_MASTER);
  obj->i2cObj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObj.MW_I2C_HANDLE, obj->i2cObj.BusSpeed);
  regVal = 182U;

  /* Start for MATLABSystem: '<S1>/Barometer' */
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&regVal, (size_t)1 * sizeof
         (uint8_T));
  b_SwappedDataBytes[0] = 224U;

  /* Start for MATLABSystem: '<S1>/Barometer' */
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)2
         * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U, &SwappedDataBytes[0], 2U,
                     false, false);
  MW_usleep(1000);
  status = 208U;

  /* Start for MATLABSystem: '<S1>/Barometer' */
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
    regVal = 87U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regVal, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 244U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U, &SwappedDataBytes[0], 2U,
                       false, false);
    MW_usleep(150);
    regVal = 4U;
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
      memcpy((void *)&pressure_B.b_output[0], (void *)&output_raw[0], (size_t)24
             * sizeof(uint8_T));
    } else {
      for (i = 0; i < 24; i++) {
        pressure_B.b_output[i] = 0U;
      }
    }

    obj->dig_T1 = (uint16_T)(pressure_B.b_output[1] << 8 | pressure_B.b_output[0]);
    c = (uint16_T)(pressure_B.b_output[3] << 8 | pressure_B.b_output[2]);
    memcpy((void *)&obj->dig_T2, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(pressure_B.b_output[5] << 8 | pressure_B.b_output[4]);
    memcpy((void *)&obj->dig_T3, (void *)&c, (size_t)1 * sizeof(int16_T));
    obj->dig_P1 = (uint16_T)(pressure_B.b_output[7] << 8 | pressure_B.b_output[6]);
    c = (uint16_T)(pressure_B.b_output[9] << 8 | pressure_B.b_output[8]);
    memcpy((void *)&obj->dig_P2, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(pressure_B.b_output[11] << 8 | pressure_B.b_output[10]);
    memcpy((void *)&obj->dig_P3, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(pressure_B.b_output[13] << 8 | pressure_B.b_output[12]);
    memcpy((void *)&obj->dig_P4, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(pressure_B.b_output[15] << 8 | pressure_B.b_output[14]);
    memcpy((void *)&obj->dig_P5, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(pressure_B.b_output[17] << 8 | pressure_B.b_output[16]);
    memcpy((void *)&obj->dig_P6, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(pressure_B.b_output[19] << 8 | pressure_B.b_output[18]);
    memcpy((void *)&obj->dig_P7, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(pressure_B.b_output[21] << 8 | pressure_B.b_output[20]);
    memcpy((void *)&obj->dig_P8, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(pressure_B.b_output[23] << 8 | pressure_B.b_output[22]);
    memcpy((void *)&obj->dig_P9, (void *)&c, (size_t)1 * sizeof(int16_T));
  }
}

static void pressure_SystemCore_setup_j(dsp_simulink_MovingAverage_pr_T *obj)
{
  real_T varargin_2;
  boolean_T flag;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;

  /* Start for MATLABSystem: '<S2>/Moving Average' */
  obj->NumChannels = 1;
  obj->FrameLength = 1;
  varargin_2 = obj->ForgettingFactor;
  obj->_pobj0.isInitialized = 0;
  obj->_pobj0.isInitialized = 0;
  flag = (obj->_pobj0.isInitialized == 1);
  if (flag) {
    /* Start for MATLABSystem: '<S2>/Moving Average' */
    obj->_pobj0.TunablePropsChanged = true;
  }

  /* Start for MATLABSystem: '<S2>/Moving Average' */
  obj->_pobj0.ForgettingFactor = varargin_2;
  obj->pStatistic = &obj->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

/* Model step function */
void pressure_step(void)
{
  b_dspcodegen_FIRFilter_pressu_T *obj;
  int32_T srcIdx;
  boolean_T flag;
  ZCEventType zcEvent;

  /* Reset subsysRan breadcrumbs */
  srClearBC(pressure_DW.SampleandHold3_SubsysRanBC);

  /* MATLABSystem: '<S1>/Barometer' */
  if (pressure_DW.obj_k.SampleTime != pressure_P.Barometer_SampleTime) {
    pressure_DW.obj_k.SampleTime = pressure_P.Barometer_SampleTime;
  }

  pressure_B.d = pressu_bbblueBarometer_stepImpl(&pressure_DW.obj_k);

  /* MATLABSystem: '<S2>/Moving Average' incorporates:
   *  MATLABSystem: '<S1>/Barometer'
   */
  if (pressure_DW.obj_f.ForgettingFactor !=
      pressure_P.MovingAverage_ForgettingFactor) {
    if (pressure_DW.obj_f.isInitialized == 1) {
      pressure_DW.obj_f.TunablePropsChanged = true;
    }

    pressure_DW.obj_f.ForgettingFactor =
      pressure_P.MovingAverage_ForgettingFactor;
  }

  if (pressure_DW.obj_f.TunablePropsChanged) {
    pressure_DW.obj_f.TunablePropsChanged = false;
    flag = (pressure_DW.obj_f.pStatistic->isInitialized == 1);
    if (flag) {
      pressure_DW.obj_f.pStatistic->TunablePropsChanged = true;
    }

    pressure_DW.obj_f.pStatistic->ForgettingFactor =
      pressure_DW.obj_f.ForgettingFactor;
  }

  if (pressure_DW.obj_f.pStatistic->isInitialized != 1) {
    pressure_DW.obj_f.pStatistic->isSetupComplete = false;
    pressure_DW.obj_f.pStatistic->isInitialized = 1;
    pressure_DW.obj_f.pStatistic->pwN = 1.0;
    pressure_DW.obj_f.pStatistic->pmN = 0.0;
    pressure_DW.obj_f.pStatistic->plambda =
      pressure_DW.obj_f.pStatistic->ForgettingFactor;
    pressure_DW.obj_f.pStatistic->isSetupComplete = true;
    pressure_DW.obj_f.pStatistic->TunablePropsChanged = false;
    pressure_DW.obj_f.pStatistic->pwN = 1.0;
    pressure_DW.obj_f.pStatistic->pmN = 0.0;
  }

  if (pressure_DW.obj_f.pStatistic->TunablePropsChanged) {
    pressure_DW.obj_f.pStatistic->TunablePropsChanged = false;
    pressure_DW.obj_f.pStatistic->plambda =
      pressure_DW.obj_f.pStatistic->ForgettingFactor;
  }

  pressure_B.pwLocal = pressure_DW.obj_f.pStatistic->pwN;
  pressure_B.pmLocal = pressure_DW.obj_f.pStatistic->pmN;
  pressure_B.lambda = pressure_DW.obj_f.pStatistic->plambda;
  pressure_B.pmLocal = (1.0 - 1.0 / pressure_B.pwLocal) * pressure_B.pmLocal +
    1.0 / pressure_B.pwLocal * pressure_B.d;
  pressure_DW.obj_f.pStatistic->pwN = pressure_B.lambda * pressure_B.pwLocal +
    1.0;
  pressure_DW.obj_f.pStatistic->pmN = pressure_B.pmLocal;

  /* Step: '<S2>/Step3' */
  if (pressure_M->Timing.t[0] < pressure_P.Step3_Time) {
    pressure_B.pwLocal = pressure_P.Step3_Y0;
  } else {
    pressure_B.pwLocal = pressure_P.Step3_YFinal;
  }

  /* Outputs for Triggered SubSystem: '<S2>/Sample and Hold3' incorporates:
   *  TriggerPort: '<S3>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &pressure_PrevZCX.SampleandHold3_Trig_ZCE,
                     (pressure_B.pwLocal));

  /* End of Step: '<S2>/Step3' */
  if (zcEvent != NO_ZCEVENT) {
    /* SignalConversion generated from: '<S3>/In' incorporates:
     *  MATLABSystem: '<S2>/Moving Average'
     * */
    pressure_B.In = pressure_B.pmLocal;
    pressure_DW.SampleandHold3_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S2>/Sample and Hold3' */

  /* MATLAB Function: '<S2>/height' incorporates:
   *  MATLABSystem: '<S1>/Barometer'
   *  Sum: '<S2>/Add'
   */
  pressure_B.height = -((pressure_B.d - pressure_B.In) / pressure_B.In) * 8430.0;

  /* MATLABSystem: '<S2>/Lowpass Filter' */
  obj = pressure_DW.obj.FilterObj;
  if (pressure_DW.obj.FilterObj->isInitialized != 1) {
    pressure_DW.obj.FilterObj->isSetupComplete = false;
    pressure_DW.obj.FilterObj->isInitialized = 1;
    pressure_DW.obj.FilterObj->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (srcIdx = 0; srcIdx < 513; srcIdx++) {
      pressure_DW.obj.FilterObj->cSFunObject.W0_states[srcIdx] =
        pressure_DW.obj.FilterObj->cSFunObject.P0_InitialStates;
    }
  }

  /* System object Outputs function: dsp.FIRFilter */
  /* Reverse the coefficients */
  for (srcIdx = 0; srcIdx < 514; srcIdx++) {
    obj->cSFunObject.W2_simRevCoeff[513 - srcIdx] =
      obj->cSFunObject.P1_Coefficients[srcIdx];
  }

  /* Reverse copy the states from States_Dwork to ContextBuff_Dwork */
  /* Copy the initial part of input to ContextBuff_Dwork */
  for (srcIdx = 0; srcIdx < 513; srcIdx++) {
    obj->cSFunObject.W1_simContextBuf[512 - srcIdx] = obj->
      cSFunObject.W0_states[srcIdx];
  }

  obj->cSFunObject.W1_simContextBuf[513] = 0.0;

  /* Shift state buffer when input buffer is shorter than state buffer */
  for (srcIdx = 511; srcIdx >= 0; srcIdx--) {
    obj->cSFunObject.W0_states[srcIdx + 1] = obj->cSFunObject.W0_states[srcIdx];
  }

  /* Reverse copy the states from input to States_Dwork */
  obj->cSFunObject.W0_states[0] = 0.0;

  /* End of MATLABSystem: '<S2>/Lowpass Filter' */

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, (real_T)pressure_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(1, (real_T)((pressure_M->Timing.clockTick1) * 0.01));
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(pressure_M)!=-1) &&
        !((rtmGetTFinal(pressure_M)-pressure_M->Timing.t[0]) >
          pressure_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(pressure_M, "Simulation finished");
    }

    if (rtmGetStopRequested(pressure_M)) {
      rtmSetErrorStatus(pressure_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  pressure_M->Timing.t[0] =
    ((time_T)(++pressure_M->Timing.clockTick0)) * pressure_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    pressure_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void pressure_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&pressure_M->solverInfo,
                          &pressure_M->Timing.simTimeStep);
    rtsiSetTPtr(&pressure_M->solverInfo, &rtmGetTPtr(pressure_M));
    rtsiSetStepSizePtr(&pressure_M->solverInfo, &pressure_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&pressure_M->solverInfo, (&rtmGetErrorStatus
      (pressure_M)));
    rtsiSetRTModelPtr(&pressure_M->solverInfo, pressure_M);
  }

  rtsiSetSimTimeStep(&pressure_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&pressure_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&pressure_M->solverInfo, false);
  rtsiSetSolverName(&pressure_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(pressure_M, &pressure_M->Timing.tArray[0]);
  rtmSetTFinal(pressure_M, -1);
  pressure_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  pressure_M->Sizes.checksums[0] = (3267946832U);
  pressure_M->Sizes.checksums[1] = (1933253447U);
  pressure_M->Sizes.checksums[2] = (1710642951U);
  pressure_M->Sizes.checksums[3] = (2057453320U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    pressure_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)&pressure_DW.SampleandHold3_SubsysRanBC;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(pressure_M->extModeInfo,
      &pressure_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(pressure_M->extModeInfo, pressure_M->Sizes.checksums);
    rteiSetTPtr(pressure_M->extModeInfo, rtmGetTPtr(pressure_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    pressure_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 22;
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
    static const real_T tmp[514] = { 5.9231424475921442E-5, 2.052105273202542E-5,
      2.3887893582430588E-5, 2.74764530354529E-5, 3.1270785465977549E-5,
      3.5251155094390732E-5, 3.9393920105059533E-5, 4.3670724871784565E-5,
      4.8049187071970924E-5, 5.249290320186238E-5, 5.6961257945787314E-5,
      6.1409825884073947E-5, 6.5789660740345416E-5, 7.0050097797813029E-5,
      7.4132363865163248E-5, 7.7984807013510153E-5, 8.153526655115483E-5,
      8.4734718377605319E-5, 8.750575191338767E-5, 8.9787684991618616E-5,
      9.1517884935180335E-5, 9.2623554194371936E-5, 9.3040935720208867E-5,
      9.2710342153651628E-5, 9.1566964724264433E-5, 8.9549958161980387E-5,
      8.6607907567925278E-5, 8.2691979679524243E-5, 7.77557844488977E-5,
      7.1759009898415463E-5, 6.4673876327727949E-5, 5.6475742951965273E-5,
      4.7151588766256861E-5, 3.6692120332400552E-5, 2.510431371858063E-5,
      1.2404650805063085E-5, -1.3813521335823495E-6, -1.6215137633378273E-5,
      -3.20476645456679E-5, -4.8817502621220513E-5, -6.6448316994003717E-5,
      -8.48530562725473E-5, -0.00010393446454483994, -0.00012358093227715338,
      -0.0001436694231119447, -0.00016406583777751519, -0.00018462616359218761,
      -0.0002051940206472051, -0.00022560771759548706, -0.00024569549795026748,
      -0.00026527793765137447, -0.00028416925916724151, -0.00030217971032129182,
      -0.00031911723604627373, -0.00033478785255481165, -0.0003489972331554146,
      -0.0003615539233338546, -0.000372269524978622, -0.00038095999590083516,
      -0.00038745083023304031, -0.0003915776376092158, -0.00039318743117397654,
      -0.00039213996913873921, -0.00038831127932323258, -0.00038159241459682,
      -0.00037189550572598639, -0.00035915337991880287, -0.00034332045592207878,
      -0.00032437459960582571, -0.0003023198403345565, -0.0002771851773770777,
      -0.00024902659574943618, -0.0002179293433470221, -0.00018400763515382,
      -0.00014740461190490038, -0.00010829227209724766, -6.68721678478806E-5,
      -2.3374848641756389E-5, 2.1941591552225727E-5, 6.87940159047906E-5,
      0.00011687124377085727, 0.00016584106323920707, 0.00021534863056562562,
      0.00026501824751861514, 0.00031445565020211567, 0.0003632536864353013,
      0.00041099173337220182, 0.00045723870645438588, 0.00050155826621383866,
      0.000543510551815915, 0.00058265705123420708, 0.00061856696228037883,
      0.00065081703110451234, 0.00067899609680732264, 0.00070271446053621681,
      0.0007216008438632065, 0.00073531160056093333, 0.00074352586718272416,
      0.000745958451382394, 0.00074236093573704553, 0.000732523843581699,
      0.00071627952562124694, 0.00069351236951016224, 0.00066415901631907749,
      0.00062820414315573861, 0.00058568837134739642, 0.000536711277812685,
      0.00048142006312023135, 0.000420019079590517, 0.00035277990627354482,
      0.00028002079996209035, 0.00020213892059721327, 0.00011957988315103329,
      3.2852299364961338E-5, -5.7492371906419341E-5, -0.00015085854083197488,
      -0.00024660718357576785, -0.00034404635812154108, -0.00044242666884664565,
      -0.00054095420173217563, -0.00063882562126174407, -0.00073525470825783331,
      -0.00082943251340356408, -0.00092043868766954521, -0.0010073212423665141,
      -0.0010894804538519197, -0.0011658051901370849, -0.001235607115517439,
      -0.0012980249393911767, -0.0013522889422597738, -0.0013976566841114768,
      -0.0014334334840399301, -0.0014589781023648816, -0.0014737102052656288,
      -0.0014771173784975675, -0.0014687616285596638, -0.0014482861547781031,
      -0.0014154193332921177, -0.0013699858059009569, -0.0013118949783497166,
      -0.0012411816217088255, -0.0011579418250584933, -0.0010624314667139552,
      -0.00095496970858415019, -0.00083600059619174587, -0.00070609126474451759,
      -0.00056589986907479815, -0.0004161905058984531, -0.00025784390405585595,
      -9.18398906842014E-5, 8.0753593443760635E-5, 0.00025877584142653851,
      0.00044097603502149866, 0.00062602414003925415, 0.00081252732154412494,
      0.00099902901205976618, 0.0011840255728300486, 0.0013659623025640908,
      0.0015432626571502957, 0.0017143293099905628, 0.0018775596899893213,
      0.0020313595021619647, 0.0021741487120592812, 0.0023043795463521736,
      0.002420553592159, 0.0025212302383881054, 0.0026050402545465421,
      0.00267070186196667, 0.0027170293785121966, 0.0027429473034466002,
      0.002747503812802326, 0.0027298858808858049, 0.0026894219596849287,
      0.0026255980235580876, 0.0025380634913310619, 0.0024266413204352905,
      0.0022913345865681429, 0.0021323327181211513, 0.0019500186850964479,
      0.0017449711394133751, 0.0015179639243358728, 0.0012699693118475208,
      0.0010021584746379864, 0.000715897368441948, 0.00041274529303375368,
      9.4448906807460123E-5, -0.0002370641573564672, -0.00057969409922221092,
      -0.0009311749377794215, -0.0012890900674030902, -0.0016508812949739598,
      -0.0020138617735060123, -0.002375231649722127, -0.0027320950589174242,
      -0.0030814750803031879, -0.0034203326001589649, -0.0037455857926484626,
      -0.0040541293564540842, -0.0043428542830269319, -0.0046086674911402876,
      -0.0048485139476774431, -0.0050593973915148624, -0.0052384010309212553,
      -0.0053827089248438993, -0.0054896308517637582, -0.00555661740282064,
      -0.0055812832384505772, -0.0055614261129714841, -0.0054950452813111424,
      -0.0053803566727542926, -0.005215812024427802, -0.0050001129984592529,
      -0.0047322251127568382, -0.0044113928299829557, -0.00403714822204745,
      -0.0036093182550831476, -0.0031280354839292438, -0.002593742459956948,
      -0.0020071918629703386, -0.0013694517834454104, -0.00068190141995491584,
      5.3762705508808144E-5, 0.00083553943508519991, 0.001661126770619953,
      0.0025279302322888386, 0.0034330731645848159, 0.004373414585880836,
      0.0053455590056957518, 0.00634586775795065, 0.00737048272521685,
      0.0084153461815689463, 0.0094762164880387648, 0.010548699947622739,
      0.011628273549085247, 0.012710294866614666, 0.013790045539420683,
      0.014862737435146319, 0.015923561963246666, 0.016967708383966842,
      0.017990395136936385, 0.0189868863730051, 0.0199525196260218,
      0.020882743244368465, 0.021773153276994712, 0.022619506342128358,
      0.023417723233634273, 0.024163933202274838, 0.024854536377097766,
      0.025486175240099176, 0.026055702628252797, 0.026560388200370717,
      0.026997694188350511, 0.027365485900286958, 0.027661932515069897,
      0.027885566350280392, 0.028035276038638514, 0.028110317500233906,
      0.028110317500233906, 0.028035276038638514, 0.027885566350280392,
      0.027661932515069897, 0.027365485900286958, 0.026997694188350511,
      0.026560388200370717, 0.026055702628252797, 0.025486175240099176,
      0.024854536377097766, 0.024163933202274838, 0.023417723233634273,
      0.022619506342128358, 0.021773153276994712, 0.020882743244368465,
      0.0199525196260218, 0.0189868863730051, 0.017990395136936385,
      0.016967708383966842, 0.015923561963246666, 0.014862737435146319,
      0.013790045539420683, 0.012710294866614666, 0.011628273549085247,
      0.010548699947622739, 0.0094762164880387648, 0.0084153461815689463,
      0.00737048272521685, 0.00634586775795065, 0.0053455590056957518,
      0.004373414585880836, 0.0034330731645848159, 0.0025279302322888386,
      0.001661126770619953, 0.00083553943508519991, 5.3762705508808144E-5,
      -0.00068190141995491584, -0.0013694517834454104, -0.0020071918629703386,
      -0.002593742459956948, -0.0031280354839292438, -0.0036093182550831476,
      -0.00403714822204745, -0.0044113928299829557, -0.0047322251127568382,
      -0.0050001129984592529, -0.005215812024427802, -0.0053803566727542926,
      -0.0054950452813111424, -0.0055614261129714841, -0.0055812832384505772,
      -0.00555661740282064, -0.0054896308517637582, -0.0053827089248438993,
      -0.0052384010309212553, -0.0050593973915148624, -0.0048485139476774431,
      -0.0046086674911402876, -0.0043428542830269319, -0.0040541293564540842,
      -0.0037455857926484626, -0.0034203326001589649, -0.0030814750803031879,
      -0.0027320950589174242, -0.002375231649722127, -0.0020138617735060123,
      -0.0016508812949739598, -0.0012890900674030902, -0.0009311749377794215,
      -0.00057969409922221092, -0.0002370641573564672, 9.4448906807460123E-5,
      0.00041274529303375368, 0.000715897368441948, 0.0010021584746379864,
      0.0012699693118475208, 0.0015179639243358728, 0.0017449711394133751,
      0.0019500186850964479, 0.0021323327181211513, 0.0022913345865681429,
      0.0024266413204352905, 0.0025380634913310619, 0.0026255980235580876,
      0.0026894219596849287, 0.0027298858808858049, 0.002747503812802326,
      0.0027429473034466002, 0.0027170293785121966, 0.00267070186196667,
      0.0026050402545465421, 0.0025212302383881054, 0.002420553592159,
      0.0023043795463521736, 0.0021741487120592812, 0.0020313595021619647,
      0.0018775596899893213, 0.0017143293099905628, 0.0015432626571502957,
      0.0013659623025640908, 0.0011840255728300486, 0.00099902901205976618,
      0.00081252732154412494, 0.00062602414003925415, 0.00044097603502149866,
      0.00025877584142653851, 8.0753593443760635E-5, -9.18398906842014E-5,
      -0.00025784390405585595, -0.0004161905058984531, -0.00056589986907479815,
      -0.00070609126474451759, -0.00083600059619174587, -0.00095496970858415019,
      -0.0010624314667139552, -0.0011579418250584933, -0.0012411816217088255,
      -0.0013118949783497166, -0.0013699858059009569, -0.0014154193332921177,
      -0.0014482861547781031, -0.0014687616285596638, -0.0014771173784975675,
      -0.0014737102052656288, -0.0014589781023648816, -0.0014334334840399301,
      -0.0013976566841114768, -0.0013522889422597738, -0.0012980249393911767,
      -0.001235607115517439, -0.0011658051901370849, -0.0010894804538519197,
      -0.0010073212423665141, -0.00092043868766954521, -0.00082943251340356408,
      -0.00073525470825783331, -0.00063882562126174407, -0.00054095420173217563,
      -0.00044242666884664565, -0.00034404635812154108, -0.00024660718357576785,
      -0.00015085854083197488, -5.7492371906419341E-5, 3.2852299364961338E-5,
      0.00011957988315103329, 0.00020213892059721327, 0.00028002079996209035,
      0.00035277990627354482, 0.000420019079590517, 0.00048142006312023135,
      0.000536711277812685, 0.00058568837134739642, 0.00062820414315573861,
      0.00066415901631907749, 0.00069351236951016224, 0.00071627952562124694,
      0.000732523843581699, 0.00074236093573704553, 0.000745958451382394,
      0.00074352586718272416, 0.00073531160056093333, 0.0007216008438632065,
      0.00070271446053621681, 0.00067899609680732264, 0.00065081703110451234,
      0.00061856696228037883, 0.00058265705123420708, 0.000543510551815915,
      0.00050155826621383866, 0.00045723870645438588, 0.00041099173337220182,
      0.0003632536864353013, 0.00031445565020211567, 0.00026501824751861514,
      0.00021534863056562562, 0.00016584106323920707, 0.00011687124377085727,
      6.87940159047906E-5, 2.1941591552225727E-5, -2.3374848641756389E-5,
      -6.68721678478806E-5, -0.00010829227209724766, -0.00014740461190490038,
      -0.00018400763515382, -0.0002179293433470221, -0.00024902659574943618,
      -0.0002771851773770777, -0.0003023198403345565, -0.00032437459960582571,
      -0.00034332045592207878, -0.00035915337991880287, -0.00037189550572598639,
      -0.00038159241459682, -0.00038831127932323258, -0.00039213996913873921,
      -0.00039318743117397654, -0.0003915776376092158, -0.00038745083023304031,
      -0.00038095999590083516, -0.000372269524978622, -0.0003615539233338546,
      -0.0003489972331554146, -0.00033478785255481165, -0.00031911723604627373,
      -0.00030217971032129182, -0.00028416925916724151, -0.00026527793765137447,
      -0.00024569549795026748, -0.00022560771759548706, -0.0002051940206472051,
      -0.00018462616359218761, -0.00016406583777751519, -0.0001436694231119447,
      -0.00012358093227715338, -0.00010393446454483994, -8.48530562725473E-5,
      -6.6448316994003717E-5, -4.8817502621220513E-5, -3.20476645456679E-5,
      -1.6215137633378273E-5, -1.3813521335823495E-6, 1.2404650805063085E-5,
      2.510431371858063E-5, 3.6692120332400552E-5, 4.7151588766256861E-5,
      5.6475742951965273E-5, 6.4673876327727949E-5, 7.1759009898415463E-5,
      7.77557844488977E-5, 8.2691979679524243E-5, 8.6607907567925278E-5,
      8.9549958161980387E-5, 9.1566964724264433E-5, 9.2710342153651628E-5,
      9.3040935720208867E-5, 9.2623554194371936E-5, 9.1517884935180335E-5,
      8.9787684991618616E-5, 8.750575191338767E-5, 8.4734718377605319E-5,
      8.153526655115483E-5, 7.7984807013510153E-5, 7.4132363865163248E-5,
      7.0050097797813029E-5, 6.5789660740345416E-5, 6.1409825884073947E-5,
      5.6961257945787314E-5, 5.249290320186238E-5, 4.8049187071970924E-5,
      4.3670724871784565E-5, 3.9393920105059533E-5, 3.5251155094390732E-5,
      3.1270785465977549E-5, 2.74764530354529E-5, 2.3887893582430588E-5,
      2.052105273202542E-5, 5.9231424475921442E-5 };

    pressure_PrevZCX.SampleandHold3_Trig_ZCE = UNINITIALIZED_ZCSIG;

    /* SystemInitialize for Triggered SubSystem: '<S2>/Sample and Hold3' */
    /* SystemInitialize for SignalConversion generated from: '<S3>/In' incorporates:
     *  Outport: '<S3>/ '
     */
    pressure_B.In = pressure_P._Y0;

    /* End of SystemInitialize for SubSystem: '<S2>/Sample and Hold3' */

    /* Start for MATLABSystem: '<S1>/Barometer' */
    pressure_DW.obj_k.i2cObj.matlabCodegenIsDeleted = true;
    pressure_DW.obj_k.matlabCodegenIsDeleted = true;
    bbblueBarometer_bbblueBarometer(&pressure_DW.obj_k);
    pressure_DW.obj_k.SampleTime = pressure_P.Barometer_SampleTime;
    pressure_SystemCore_setup(&pressure_DW.obj_k);

    /* Start for MATLABSystem: '<S2>/Moving Average' */
    pressure_DW.obj_f.isInitialized = 0;
    pressure_DW.obj_f.NumChannels = -1;
    pressure_DW.obj_f.FrameLength = -1;
    pressure_DW.obj_f.matlabCodegenIsDeleted = false;
    flag = (pressure_DW.obj_f.isInitialized == 1);
    if (flag) {
      pressure_DW.obj_f.TunablePropsChanged = true;
    }

    pressure_DW.obj_f.ForgettingFactor =
      pressure_P.MovingAverage_ForgettingFactor;
    pressure_SystemCore_setup_j(&pressure_DW.obj_f);

    /* InitializeConditions for MATLABSystem: '<S2>/Moving Average' */
    if (pressure_DW.obj_f.pStatistic->isInitialized == 1) {
      pressure_DW.obj_f.pStatistic->pwN = 1.0;
      pressure_DW.obj_f.pStatistic->pmN = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S2>/Moving Average' */

    /* Start for MATLABSystem: '<S2>/Lowpass Filter' */
    pressure_DW.obj.NumChannels = -1;
    pressure_DW.obj.matlabCodegenIsDeleted = false;
    pressure_DW.obj.isInitialized = 1;
    if (pressure_DW.obj.NumChannels == -1) {
      pressure_DW.obj.NumChannels = 1;
    }

    pressure_DW.obj._pobj0.isInitialized = 0;

    /* System object Constructor function: dsp.FIRFilter */
    pressure_DW.obj._pobj0.cSFunObject.P0_InitialStates = 0.0;
    memcpy(&pressure_DW.obj._pobj0.cSFunObject.P1_Coefficients[0], &tmp[0], 514U
           * sizeof(real_T));
    pressure_DW.obj.FilterObj = &pressure_DW.obj._pobj0;
    pressure_DW.obj.isSetupComplete = true;

    /* InitializeConditions for MATLABSystem: '<S2>/Lowpass Filter' */
    if (pressure_DW.obj.FilterObj->isInitialized == 1) {
      /* System object Initialization function: dsp.FIRFilter */
      for (i = 0; i < 513; i++) {
        pressure_DW.obj.FilterObj->cSFunObject.W0_states[i] =
          pressure_DW.obj.FilterObj->cSFunObject.P0_InitialStates;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<S2>/Lowpass Filter' */
  }
}

/* Model terminate function */
void pressure_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Barometer' */
  if (!pressure_DW.obj_k.matlabCodegenIsDeleted) {
    pressure_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  if (!pressure_DW.obj_k.i2cObj.matlabCodegenIsDeleted) {
    pressure_DW.obj_k.i2cObj.matlabCodegenIsDeleted = true;
    if (pressure_DW.obj_k.i2cObj.isInitialized == 1) {
      pressure_DW.obj_k.i2cObj.isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Barometer' */

  /* Terminate for MATLABSystem: '<S2>/Moving Average' */
  if (!pressure_DW.obj_f.matlabCodegenIsDeleted) {
    pressure_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((pressure_DW.obj_f.isInitialized == 1) &&
        pressure_DW.obj_f.isSetupComplete) {
      if (pressure_DW.obj_f.pStatistic->isInitialized == 1) {
        pressure_DW.obj_f.pStatistic->isInitialized = 2;
      }

      pressure_DW.obj_f.NumChannels = -1;
      pressure_DW.obj_f.FrameLength = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Moving Average' */

  /* Terminate for MATLABSystem: '<S2>/Lowpass Filter' */
  if (!pressure_DW.obj.matlabCodegenIsDeleted) {
    pressure_DW.obj.matlabCodegenIsDeleted = true;
    if ((pressure_DW.obj.isInitialized == 1) && pressure_DW.obj.isSetupComplete)
    {
      if (pressure_DW.obj.FilterObj->isInitialized == 1) {
        pressure_DW.obj.FilterObj->isInitialized = 2;
      }

      pressure_DW.obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Lowpass Filter' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
