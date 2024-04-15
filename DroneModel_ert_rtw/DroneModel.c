/*
 * DroneModel.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DroneModel".
 *
 * Model version              : 1.17
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Thu Mar 21 13:26:39 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DroneModel.h"
#include "DroneModel_types.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include <string.h>
#include <stddef.h>
#include "DroneModel_private.h"
#include "MW_I2C.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "DroneModel_dt.h"

/* Block signals (default storage) */
B_DroneModel_T DroneModel_B;

/* Continuous states */
X_DroneModel_T DroneModel_X;

/* Block states (default storage) */
DW_DroneModel_T DroneModel_DW;

/* Real-time model */
static RT_MODEL_DroneModel_T DroneModel_M_;
RT_MODEL_DroneModel_T *const DroneModel_M = &DroneModel_M_;

/* Forward declaration for local functions */
static beagleboneblue_bbblueMPU9250__T *Dro_bbblueMPU9250_bbblueMPU9250
  (beagleboneblue_bbblueMPU9250__T *obj);
static void DroneModel_SystemCore_setup_n(beagleboneblue_bbblueMPU9250__T *obj);
static beagleboneblue_bbblueBaromete_T *bbblueBarometer_bbblueBarometer
  (beagleboneblue_bbblueBaromete_T *obj);
static void DroneModel_SystemCore_setup(beagleboneblue_bbblueBaromete_T *obj);
static void bbblueBarometer_BMP_ReadRegiste(const
  beagleboneblue_bbblueBaromete_T *obj, uint8_T RegisterValue[6], uint8_T
  *varargout_1);
static int64m_T DroneModel_i64ddiv(real_T x, const int64m_T y);
static uint64m_T DroneModel_eml_mixed_uint64_mul(const uint64m_T nv, real_T y);
static int64m_T DroneModel_times(real_T x, const int64m_T y);
static real_T DroneM_bbblueBarometer_stepImpl(const
  beagleboneblue_bbblueBaromete_T *obj);
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

boolean_T sMultiWordGe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return sMultiWordCmp(u1, u2, n) >= 0;
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

boolean_T uMultiWordGt(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return uMultiWordCmp(u1, u2, n) > 0;
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

boolean_T uMultiWordLe(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  return uMultiWordCmp(u1, u2, n) <= 0;
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  DroneModel_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  DroneModel_step();
  DroneModel_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  DroneModel_step();
  DroneModel_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

static beagleboneblue_bbblueMPU9250__T *Dro_bbblueMPU9250_bbblueMPU9250
  (beagleboneblue_bbblueMPU9250__T *obj)
{
  beagleboneblue_bbblueMPU9250__T *b_obj;
  obj->AK8963SensitivityAdj[0] = 0.0;
  obj->AK8963SensitivityAdj[1] = 0.0;
  obj->AK8963SensitivityAdj[2] = 0.0;
  obj->AK8963Data[0] = 0.0;
  obj->AK8963Data[1] = 0.0;
  obj->AK8963Data[2] = 0.0;
  obj->isInitialized = 0;
  obj->SampleTime = -1.0;
  b_obj = obj;
  obj->i2cObjmpu.DefaultMaximumBusSpeedInHz = 400000.0;
  obj->i2cObjmpu.isInitialized = 0;
  obj->i2cObjmpu.matlabCodegenIsDeleted = false;
  obj->i2cObjak8963.DefaultMaximumBusSpeedInHz = 400000.0;
  obj->i2cObjak8963.isInitialized = 0;
  obj->i2cObjak8963.matlabCodegenIsDeleted = false;
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static void DroneModel_SystemCore_setup_n(beagleboneblue_bbblueMPU9250__T *obj)
{
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  real_T y;
  int32_T ii_data[3];
  int32_T idx;
  int32_T vlen;
  uint8_T output_raw[3];
  uint8_T temp[3];
  uint8_T x_tmp[3];
  uint8_T SwappedDataBytes[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T SwappedDataBytes_0;
  uint8_T regSet;
  uint8_T status;
  boolean_T exitg1;
  obj->isInitialized = 1;
  ModeType = MW_I2C_MASTER;
  i2cname = 2;
  obj->i2cObjmpu.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cObjmpu.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObjmpu.MW_I2C_HANDLE, obj->i2cObjmpu.BusSpeed);
  ModeType = MW_I2C_MASTER;
  i2cname = 2;
  obj->i2cObjak8963.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cObjak8963.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObjak8963.MW_I2C_HANDLE, obj->i2cObjak8963.BusSpeed);
  regSet = 128U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
         (uint8_T));
  b_SwappedDataBytes[0] = 107U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)2
         * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                     2U, false, false);
  regSet = 0U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
         (uint8_T));
  b_SwappedDataBytes[0] = 107U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)2
         * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                     2U, false, false);
  MW_usleep(MAX_uint16_T);
  status = 117U;
  memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
         (uint8_T));
  status = MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U,
    &SwappedDataBytes_0, 1U, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &status, 1U, false,
                      true);
    memcpy((void *)&regSet, (void *)&status, (size_t)1 * sizeof(uint8_T));
  } else {
    regSet = 0U;
  }

  obj->MPUConnect = (regSet == 113);
  if (obj->MPUConnect) {
    regSet = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 25U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                       2U, false, false);
    regSet = 1U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 29U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                       2U, false, false);
    status = 28U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U,
      &SwappedDataBytes_0, 1U, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &status, 1U, false,
                        true);
      memcpy((void *)&regSet, (void *)&status, (size_t)1 * sizeof(uint8_T));
    } else {
      regSet = 0U;
    }

    regSet = (uint8_T)(regSet & 231);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 28U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                       2U, false, false);
    status = 27U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U,
      &SwappedDataBytes_0, 1U, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &status, 1U, false,
                        true);
      memcpy((void *)&regSet, (void *)&status, (size_t)1 * sizeof(uint8_T));
    } else {
      regSet = 0U;
    }

    regSet = (uint8_T)(regSet & 228);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 27U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                       2U, false, false);
    status = 26U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U,
      &SwappedDataBytes_0, 1U, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &status, 1U, false,
                        true);
      memcpy((void *)&regSet, (void *)&status, (size_t)1 * sizeof(uint8_T));
    } else {
      regSet = 0U;
    }

    regSet = (uint8_T)((regSet & 248) | 1);
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 26U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                       2U, false, false);
    regSet = 0U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 106U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                       2U, false, false);
    MW_usleep(3000);
    regSet = 130U;
    memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
           (uint8_T));
    b_SwappedDataBytes[0] = 55U;
    memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)
           2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->i2cObjmpu.MW_I2C_HANDLE, 104U, &SwappedDataBytes[0],
                       2U, false, false);
    status = 0U;
    memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(obj->i2cObjak8963.MW_I2C_HANDLE, 12U,
      &SwappedDataBytes_0, 1U, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(obj->i2cObjak8963.MW_I2C_HANDLE, 12U, &status, 1U, false,
                        true);
      memcpy((void *)&regSet, (void *)&status, (size_t)1 * sizeof(uint8_T));
    } else {
      regSet = 0U;
    }

    obj->AK8963Connect = (regSet == 72);
    temp[0] = 0U;
    temp[1] = 0U;
    temp[2] = 0U;
    if (obj->AK8963Connect) {
      regSet = 0U;
      memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
             (uint8_T));
      b_SwappedDataBytes[0] = 10U;
      memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
             (size_t)2 * sizeof(uint8_T));
      MW_I2C_MasterWrite(obj->i2cObjak8963.MW_I2C_HANDLE, 12U,
                         &SwappedDataBytes[0], 2U, false, false);
      MW_usleep(1000);
      regSet = 15U;
      memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
             (uint8_T));
      b_SwappedDataBytes[0] = 10U;
      memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
             (size_t)2 * sizeof(uint8_T));
      MW_I2C_MasterWrite(obj->i2cObjak8963.MW_I2C_HANDLE, 12U,
                         &SwappedDataBytes[0], 2U, false, false);
      MW_usleep(1000);
      status = 16U;
      memcpy((void *)&SwappedDataBytes_0, (void *)&status, (size_t)1 * sizeof
             (uint8_T));
      status = MW_I2C_MasterWrite(obj->i2cObjak8963.MW_I2C_HANDLE, 12U,
        &SwappedDataBytes_0, 1U, true, false);
      if (status == 0) {
        MW_I2C_MasterRead(obj->i2cObjak8963.MW_I2C_HANDLE, 12U, &output_raw[0],
                          3U, false, true);
        memcpy((void *)&temp[0], (void *)&output_raw[0], (size_t)3 * sizeof
               (uint8_T));
      } else {
        temp[0] = 0U;
        temp[1] = 0U;
        temp[2] = 0U;
      }

      regSet = 0U;
      memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
             (uint8_T));
      b_SwappedDataBytes[0] = 10U;
      memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
             (size_t)2 * sizeof(uint8_T));
      MW_I2C_MasterWrite(obj->i2cObjak8963.MW_I2C_HANDLE, 12U,
                         &SwappedDataBytes[0], 2U, false, false);
      MW_usleep(100);
      regSet = 22U;
      memcpy((void *)&b_SwappedDataBytes[1], (void *)&regSet, (size_t)1 * sizeof
             (uint8_T));
      b_SwappedDataBytes[0] = 10U;
      memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0],
             (size_t)2 * sizeof(uint8_T));
      MW_I2C_MasterWrite(obj->i2cObjak8963.MW_I2C_HANDLE, 12U,
                         &SwappedDataBytes[0], 2U, false, false);
      MW_usleep(100);
    }

    x_tmp[0] = temp[0];
    x_tmp[1] = temp[1];
    x_tmp[2] = temp[2];
    idx = 0;
    vlen = 1;
    exitg1 = false;
    while ((!exitg1) && (vlen - 1 < 3)) {
      if (x_tmp[vlen - 1] == 0) {
        idx++;
        ii_data[idx - 1] = vlen;
        if (idx >= 3) {
          exitg1 = true;
        } else {
          vlen++;
        }
      } else {
        vlen++;
      }
    }

    if (idx < 1) {
      idx = 0;
    }

    if (idx - 1 >= 0) {
      memcpy(&DroneModel_B.i_data[0], &ii_data[0], (uint32_T)idx * sizeof
             (int32_T));
    }

    vlen = idx;
    if (idx == 0) {
      y = 0.0;
    } else {
      y = DroneModel_B.i_data[0];
      for (idx = 2; idx <= vlen; idx++) {
        y += (real_T)DroneModel_B.i_data[idx - 1];
      }
    }

    if (y != 6.0) {
      obj->AK8963SensitivityAdj[0] = ((real_T)temp[0] - 128.0) / 256.0 + 1.0;
      obj->AK8963SensitivityAdj[1] = ((real_T)temp[1] - 128.0) / 256.0 + 1.0;
      obj->AK8963SensitivityAdj[2] = ((real_T)temp[2] - 128.0) / 256.0 + 1.0;
    }
  }

  obj->TunablePropsChanged = false;
}

static beagleboneblue_bbblueBaromete_T *bbblueBarometer_bbblueBarometer
  (beagleboneblue_bbblueBaromete_T *obj)
{
  beagleboneblue_bbblueBaromete_T *b_obj;
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

static void DroneModel_SystemCore_setup(beagleboneblue_bbblueBaromete_T *obj)
{
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  int32_T i;
  uint16_T c;
  uint8_T output_raw[24];
  uint8_T SwappedDataBytes[2];
  uint8_T b_SwappedDataBytes[2];
  uint8_T SwappedDataBytes_0;
  uint8_T regVal;
  uint8_T status;
  obj->isInitialized = 1;
  ModeType = MW_I2C_MASTER;
  i2cname = 2;
  obj->i2cObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cObj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cObj.MW_I2C_HANDLE, obj->i2cObj.BusSpeed);
  regVal = 182U;
  memcpy((void *)&b_SwappedDataBytes[1], (void *)&regVal, (size_t)1 * sizeof
         (uint8_T));
  b_SwappedDataBytes[0] = 224U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&b_SwappedDataBytes[0], (size_t)2
         * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->i2cObj.MW_I2C_HANDLE, 118U, &SwappedDataBytes[0], 2U,
                     false, false);
  MW_usleep(1000);
  status = 208U;
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
      memcpy((void *)&DroneModel_B.b_RegisterValue[0], (void *)&output_raw[0],
             (size_t)24 * sizeof(uint8_T));
    } else {
      for (i = 0; i < 24; i++) {
        DroneModel_B.b_RegisterValue[i] = 0U;
      }
    }

    obj->dig_T1 = (uint16_T)(DroneModel_B.b_RegisterValue[1] << 8 |
      DroneModel_B.b_RegisterValue[0]);
    c = (uint16_T)(DroneModel_B.b_RegisterValue[3] << 8 |
                   DroneModel_B.b_RegisterValue[2]);
    memcpy((void *)&obj->dig_T2, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(DroneModel_B.b_RegisterValue[5] << 8 |
                   DroneModel_B.b_RegisterValue[4]);
    memcpy((void *)&obj->dig_T3, (void *)&c, (size_t)1 * sizeof(int16_T));
    obj->dig_P1 = (uint16_T)(DroneModel_B.b_RegisterValue[7] << 8 |
      DroneModel_B.b_RegisterValue[6]);
    c = (uint16_T)(DroneModel_B.b_RegisterValue[9] << 8 |
                   DroneModel_B.b_RegisterValue[8]);
    memcpy((void *)&obj->dig_P2, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(DroneModel_B.b_RegisterValue[11] << 8 |
                   DroneModel_B.b_RegisterValue[10]);
    memcpy((void *)&obj->dig_P3, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(DroneModel_B.b_RegisterValue[13] << 8 |
                   DroneModel_B.b_RegisterValue[12]);
    memcpy((void *)&obj->dig_P4, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(DroneModel_B.b_RegisterValue[15] << 8 |
                   DroneModel_B.b_RegisterValue[14]);
    memcpy((void *)&obj->dig_P5, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(DroneModel_B.b_RegisterValue[17] << 8 |
                   DroneModel_B.b_RegisterValue[16]);
    memcpy((void *)&obj->dig_P6, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(DroneModel_B.b_RegisterValue[19] << 8 |
                   DroneModel_B.b_RegisterValue[18]);
    memcpy((void *)&obj->dig_P7, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(DroneModel_B.b_RegisterValue[21] << 8 |
                   DroneModel_B.b_RegisterValue[20]);
    memcpy((void *)&obj->dig_P8, (void *)&c, (size_t)1 * sizeof(int16_T));
    c = (uint16_T)(DroneModel_B.b_RegisterValue[23] << 8 |
                   DroneModel_B.b_RegisterValue[22]);
    memcpy((void *)&obj->dig_P9, (void *)&c, (size_t)1 * sizeof(int16_T));
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

static int64m_T DroneModel_i64ddiv(real_T x, const int64m_T y)
{
  int64m_T z;
  int32_T firstbitn;
  int32_T shiftAmount;
  int32_T xexp;
  boolean_T b_isQuotNegative;
  boolean_T b_p;
  static const uint64m_T tmp = { { 0U, 2147483648U }/* chunks */
  };

  static const uint64m_T tmp_0 = { { 1U, 0U }/* chunks */
  };

  static const int64m_T tmp_1 = { { 0U, 0U }/* chunks */
  };

  static const uint64m_T tmp_2 = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  static const uint64m_T tmp_3 = { { 0U, 0U }/* chunks */
  };

  static const uint64m_T tmp_4 = { { MAX_uint32_T, MAX_uint32_T }/* chunks */
  };

  static const int64m_T tmp_5 = { { MAX_uint32_T, 2147483647U }/* chunks */
  };

  static const int64m_T tmp_6 = { { 0U, 2147483648U }/* chunks */
  };

  int32_T exitg1;
  int32_T exitg2;
  int32_T exitg3;
  boolean_T guard1;
  boolean_T guard11;
  boolean_T guard2;
  if (x == 0.0) {
    memcpy((void *)&DroneModel_B.ux[0], (void *)&x, (size_t)2 * sizeof(uint32_T));
    if ((DroneModel_B.ux[0] != 0U) || (DroneModel_B.ux[1] != 0U)) {
      b_p = true;
    } else {
      b_p = false;
    }
  } else {
    b_p = false;
  }

  if ((sMultiWordLt(&y.chunks[0U], &tmp_1.chunks[0U], 2) && (x >= 0.0) && (!b_p))
      || (sMultiWordGe(&y.chunks[0U], &tmp_1.chunks[0U], 2) && ((x < 0.0) || b_p)))
  {
    b_isQuotNegative = true;
  } else {
    b_isQuotNegative = false;
  }

  if (sMultiWordLt(&y.chunks[0U], &tmp_1.chunks[0U], 2)) {
    if (sMultiWordGt(&y.chunks[0U], &tmp_6.chunks[0U], 2)) {
      DroneModel_B.r25 = y;
      MultiWordNeg(&y.chunks[0U], &DroneModel_B.r24.chunks[0U], 2);
      sMultiWord2MultiWord(&DroneModel_B.r24.chunks[0U], 2,
                           &DroneModel_B.nk_unsgn.chunks[0U], 2);
    } else {
      DroneModel_B.nk_unsgn = tmp;
    }
  } else {
    sMultiWord2MultiWord(&y.chunks[0U], 2, &DroneModel_B.nk_unsgn.chunks[0U], 2);
  }

  if ((x < 0.0) || b_p) {
    DroneModel_B.x_unsgn = -x;
  } else {
    DroneModel_B.x_unsgn = x;
  }

  if (uMultiWordEq(&DroneModel_B.nk_unsgn.chunks[0U], &tmp_3.chunks[0U], 2)) {
    if (DroneModel_B.x_unsgn > 0.0) {
      DroneModel_B.res = tmp_4;
    } else {
      DroneModel_B.res = tmp_3;
    }
  } else if ((DroneModel_B.x_unsgn <= 0.0) || rtIsNaN(DroneModel_B.x_unsgn)) {
    DroneModel_B.res = tmp_3;
  } else if (rtIsInf(DroneModel_B.x_unsgn)) {
    DroneModel_B.res = tmp_4;
  } else {
    DroneModel_B.x_unsgn = frexp(DroneModel_B.x_unsgn, &shiftAmount);
    Double2MultiWord(rt_roundd_snf(DroneModel_B.x_unsgn * 9.007199254740992E+15),
                     &DroneModel_B.xint.chunks[0U], 2);
    xexp = shiftAmount - 53;
    firstbitn = 63;
    do {
      exitg1 = 0;
      uMultiWordShr(&DroneModel_B.nk_unsgn.chunks[0U], 2, (uint32_T)firstbitn,
                    &DroneModel_B.res.chunks[0U], 2);
      if (uMultiWordGt(&DroneModel_B.res.chunks[0U], &tmp_3.chunks[0U], 2)) {
        exitg1 = 1;
      } else {
        firstbitn--;
      }
    } while (exitg1 == 0);

    if (shiftAmount - 53 < firstbitn - 53) {
      DroneModel_B.res = tmp_3;
    } else if (shiftAmount - 53 > firstbitn + 12) {
      DroneModel_B.res = tmp_4;
    } else {
      DroneModel_B.res = tmp_3;
      guard1 = false;
      guard2 = false;
      if (firstbitn < 63) {
        uMultiWordDivZero(&DroneModel_B.xint.chunks[0U], 2,
                          &DroneModel_B.nk_unsgn.chunks[0U], 2,
                          &DroneModel_B.res.chunks[0U], 2,
                          &DroneModel_B.r26.chunks[0U], 2,
                          &DroneModel_B.r27.chunks[0U], 2,
                          &DroneModel_B.r28.chunks[0U], 2);
        if (!uMultiWordEq(&DroneModel_B.nk_unsgn.chunks[0U], &tmp_3.chunks[0U],
                          2)) {
          uMultiWordDivZero(&DroneModel_B.xint.chunks[0U], 2,
                            &DroneModel_B.nk_unsgn.chunks[0U], 2,
                            &DroneModel_B.r28.chunks[0U], 2,
                            &DroneModel_B.r29.chunks[0U], 2,
                            &DroneModel_B.r30.chunks[0U], 2,
                            &DroneModel_B.r31.chunks[0U], 2);
          uMultiWordMul(&DroneModel_B.r28.chunks[0U], 2,
                        &DroneModel_B.nk_unsgn.chunks[0U], 2,
                        &DroneModel_B.r2.chunks[0U], 4);
          uMultiWord2MultiWord(&DroneModel_B.r2.chunks[0U], 4,
                               &DroneModel_B.r27.chunks[0U], 2);
          MultiWordSub(&DroneModel_B.xint.chunks[0U], &DroneModel_B.r27.chunks
                       [0U], &DroneModel_B.r28.chunks[0U], 2);
          DroneModel_B.xint = DroneModel_B.r28;
        }

        if (shiftAmount - 53 < 0) {
          uMultiWordShr(&DroneModel_B.res.chunks[0U], 2, (uint32_T)(53 -
            shiftAmount), &DroneModel_B.r41.chunks[0U], 2);
          uMultiWordShr(&DroneModel_B.res.chunks[0U], 2, (uint32_T)(52 -
            shiftAmount), &DroneModel_B.r39.chunks[0U], 2);
          MultiWordAnd(&DroneModel_B.r39.chunks[0U], &tmp_0.chunks[0U],
                       &DroneModel_B.r38.chunks[0U], 2);
          MultiWordAdd(&DroneModel_B.r41.chunks[0U], &DroneModel_B.r38.chunks[0U],
                       &DroneModel_B.res.chunks[0U], 2);
        } else {
          do {
            exitg2 = 0;
            if (xexp > 0) {
              if (63 - firstbitn > xexp) {
                shiftAmount = xexp;
              } else {
                shiftAmount = 63 - firstbitn;
              }

              uMultiWordShr(&DroneModel_B.res.chunks[0U], 2, (uint32_T)(64 -
                shiftAmount), &DroneModel_B.r29.chunks[0U], 2);
              if (uMultiWordGt(&DroneModel_B.r29.chunks[0U], &tmp_3.chunks[0U],
                               2)) {
                DroneModel_B.res = tmp_4;
                exitg2 = 1;
              } else {
                uMultiWordShl(&DroneModel_B.res.chunks[0U], 2, (uint32_T)
                              shiftAmount, &DroneModel_B.r32.chunks[0U], 2);
                xexp -= shiftAmount;
                uMultiWordShl(&DroneModel_B.xint.chunks[0U], 2, (uint32_T)
                              shiftAmount, &DroneModel_B.r33.chunks[0U], 2);
                DroneModel_B.xint = DroneModel_B.r33;
                uMultiWordDivZero(&DroneModel_B.r33.chunks[0U], 2,
                                  &DroneModel_B.nk_unsgn.chunks[0U], 2,
                                  &DroneModel_B.nIsOdd.chunks[0U], 2,
                                  &DroneModel_B.r34.chunks[0U], 2,
                                  &DroneModel_B.r35.chunks[0U], 2,
                                  &DroneModel_B.r36.chunks[0U], 2);
                DroneModel_B.r35 = tmp_4;
                MultiWordSub(&tmp_4.chunks[0U], &DroneModel_B.nIsOdd.chunks[0U],
                             &DroneModel_B.r34.chunks[0U], 2);
                if (uMultiWordLe(&DroneModel_B.r34.chunks[0U],
                                 &DroneModel_B.r32.chunks[0U], 2)) {
                  DroneModel_B.res = tmp_4;
                  exitg2 = 1;
                } else {
                  MultiWordAdd(&DroneModel_B.r32.chunks[0U],
                               &DroneModel_B.nIsOdd.chunks[0U],
                               &DroneModel_B.r35.chunks[0U], 2);
                  DroneModel_B.res = DroneModel_B.r35;
                  DroneModel_B.r36 = tmp_3;
                  if (!uMultiWordEq(&DroneModel_B.nk_unsgn.chunks[0U],
                                    &tmp_3.chunks[0U], 2)) {
                    uMultiWordDivZero(&DroneModel_B.r33.chunks[0U], 2,
                                      &DroneModel_B.nk_unsgn.chunks[0U], 2,
                                      &DroneModel_B.r37.chunks[0U], 2,
                                      &DroneModel_B.r38.chunks[0U], 2,
                                      &DroneModel_B.r39.chunks[0U], 2,
                                      &DroneModel_B.r40.chunks[0U], 2);
                    uMultiWordMul(&DroneModel_B.r37.chunks[0U], 2,
                                  &DroneModel_B.nk_unsgn.chunks[0U], 2,
                                  &DroneModel_B.r2.chunks[0U], 4);
                    uMultiWord2MultiWord(&DroneModel_B.r2.chunks[0U], 4,
                                         &DroneModel_B.r41.chunks[0U], 2);
                    MultiWordSub(&DroneModel_B.r33.chunks[0U],
                                 &DroneModel_B.r41.chunks[0U],
                                 &DroneModel_B.r37.chunks[0U], 2);
                    DroneModel_B.xint = DroneModel_B.r37;
                  }
                }
              }
            } else {
              uMultiWordShl(&DroneModel_B.xint.chunks[0U], 2, 1U,
                            &DroneModel_B.r27.chunks[0U], 2);
              if (uMultiWordGe(&DroneModel_B.r27.chunks[0U],
                               &DroneModel_B.nk_unsgn.chunks[0U], 2)) {
                MultiWordAdd(&DroneModel_B.res.chunks[0U], &tmp_0.chunks[0U],
                             &DroneModel_B.r30.chunks[0U], 2);
                DroneModel_B.res = DroneModel_B.r30;
              }

              exitg2 = 1;
            }
          } while (exitg2 == 0);
        }
      } else if (shiftAmount - 53 > 10) {
        uMultiWordShl(&DroneModel_B.xint.chunks[0U], 2, 11U,
                      &DroneModel_B.r26.chunks[0U], 2);
        DroneModel_B.xint = DroneModel_B.r26;
        xexp = shiftAmount - 64;
        DroneModel_B.r26 = tmp_0;
        MultiWordAnd(&DroneModel_B.nk_unsgn.chunks[0U], &tmp_0.chunks[0U],
                     &DroneModel_B.nIsOdd.chunks[0U], 2);
        if (uMultiWordGe(&DroneModel_B.xint.chunks[0U],
                         &DroneModel_B.nk_unsgn.chunks[0U], 2)) {
          DroneModel_B.res = tmp_0;
          MultiWordSub(&DroneModel_B.xint.chunks[0U],
                       &DroneModel_B.nk_unsgn.chunks[0U],
                       &DroneModel_B.r27.chunks[0U], 2);
          DroneModel_B.xint = DroneModel_B.r27;
        } else if (shiftAmount - 64 > 0) {
          xexp = shiftAmount - 65;
          DroneModel_B.res = tmp_0;
          uMultiWordShr(&DroneModel_B.nk_unsgn.chunks[0U], 2, 1U,
                        &DroneModel_B.r27.chunks[0U], 2);
          MultiWordSub(&DroneModel_B.xint.chunks[0U], &DroneModel_B.r27.chunks
                       [0U], &DroneModel_B.r26.chunks[0U], 2);
          uMultiWordShl(&DroneModel_B.r26.chunks[0U], 2, 1U,
                        &DroneModel_B.xint.chunks[0U], 2);
          if (uMultiWordNe(&DroneModel_B.nIsOdd.chunks[0U], &tmp_3.chunks[0U], 2))
          {
            MultiWordSub(&DroneModel_B.xint.chunks[0U], &tmp_0.chunks[0U],
                         &DroneModel_B.r28.chunks[0U], 2);
            DroneModel_B.xint = DroneModel_B.r28;
          }
        }

        do {
          exitg1 = 0;
          if (xexp > 0) {
            if (uMultiWordEq(&DroneModel_B.xint.chunks[0U], &tmp_3.chunks[0U], 2))
            {
              uMultiWordShr(&DroneModel_B.res.chunks[0U], 2, (uint32_T)(64 -
                xexp), &DroneModel_B.r40.chunks[0U], 2);
              if (uMultiWordGt(&DroneModel_B.r40.chunks[0U], &tmp_3.chunks[0U],
                               2)) {
                DroneModel_B.res = tmp_4;
                exitg1 = 1;
              } else {
                uMultiWordShl(&DroneModel_B.res.chunks[0U], 2, (uint32_T)xexp,
                              &DroneModel_B.r41.chunks[0U], 2);
                DroneModel_B.res = DroneModel_B.r41;
                xexp = 0;
              }
            } else {
              firstbitn = 63;
              do {
                exitg3 = 0;
                uMultiWordShr(&DroneModel_B.xint.chunks[0U], 2, (uint32_T)
                              firstbitn, &DroneModel_B.r32.chunks[0U], 2);
                if (uMultiWordGt(&DroneModel_B.r32.chunks[0U], &tmp_3.chunks[0U],
                                 2)) {
                  exitg3 = 1;
                } else {
                  firstbitn--;
                }
              } while (exitg3 == 0);

              if (63 - firstbitn >= xexp) {
                shiftAmount = xexp;
              } else {
                shiftAmount = 63 - firstbitn;
              }

              guard11 = false;
              if (shiftAmount != 0) {
                uMultiWordShr(&DroneModel_B.res.chunks[0U], 2, (uint32_T)(64 -
                  shiftAmount), &DroneModel_B.r33.chunks[0U], 2);
                if (uMultiWordGt(&DroneModel_B.r33.chunks[0U], &tmp_3.chunks[0U],
                                 2)) {
                  DroneModel_B.res = tmp_4;
                  exitg1 = 1;
                } else {
                  guard11 = true;
                }
              } else {
                guard11 = true;
              }

              if (guard11) {
                uMultiWordShl(&DroneModel_B.res.chunks[0U], 2, (uint32_T)
                              shiftAmount, &DroneModel_B.r34.chunks[0U], 2);
                DroneModel_B.res = DroneModel_B.r34;
                xexp -= shiftAmount;
                uMultiWordShl(&DroneModel_B.xint.chunks[0U], 2, (uint32_T)
                              shiftAmount, &DroneModel_B.r35.chunks[0U], 2);
                DroneModel_B.xint = DroneModel_B.r35;
                if (uMultiWordGt(&DroneModel_B.xint.chunks[0U],
                                 &DroneModel_B.nk_unsgn.chunks[0U], 2)) {
                  DroneModel_B.r26 = tmp_0;
                  MultiWordAdd(&DroneModel_B.r34.chunks[0U], &tmp_0.chunks[0U],
                               &DroneModel_B.r39.chunks[0U], 2);
                  DroneModel_B.res = DroneModel_B.r39;
                  MultiWordSub(&DroneModel_B.xint.chunks[0U],
                               &DroneModel_B.nk_unsgn.chunks[0U],
                               &DroneModel_B.r26.chunks[0U], 2);
                  DroneModel_B.xint = DroneModel_B.r26;
                } else if (xexp > 0) {
                  xexp--;
                  uMultiWordShr(&DroneModel_B.r34.chunks[0U], 2, 63U,
                                &DroneModel_B.r36.chunks[0U], 2);
                  if (uMultiWordGt(&DroneModel_B.r36.chunks[0U], &tmp_3.chunks
                                   [0U], 2)) {
                    DroneModel_B.res = tmp_4;
                    exitg1 = 1;
                  } else {
                    uMultiWordShl(&DroneModel_B.r34.chunks[0U], 2, 1U,
                                  &DroneModel_B.r37.chunks[0U], 2);
                    DroneModel_B.r26 = tmp_0;
                    MultiWordAdd(&DroneModel_B.r37.chunks[0U], &tmp_0.chunks[0U],
                                 &DroneModel_B.res.chunks[0U], 2);
                    uMultiWordShr(&DroneModel_B.nk_unsgn.chunks[0U], 2, 1U,
                                  &DroneModel_B.r26.chunks[0U], 2);
                    MultiWordSub(&DroneModel_B.xint.chunks[0U],
                                 &DroneModel_B.r26.chunks[0U],
                                 &DroneModel_B.r37.chunks[0U], 2);
                    uMultiWordShl(&DroneModel_B.r37.chunks[0U], 2, 1U,
                                  &DroneModel_B.xint.chunks[0U], 2);
                    DroneModel_B.r37 = tmp_3;
                    if (uMultiWordNe(&DroneModel_B.nIsOdd.chunks[0U],
                                     &tmp_3.chunks[0U], 2)) {
                      MultiWordSub(&DroneModel_B.xint.chunks[0U], &tmp_0.chunks
                                   [0U], &DroneModel_B.r38.chunks[0U], 2);
                      DroneModel_B.xint = DroneModel_B.r38;
                    }
                  }
                }
              }
            }
          } else {
            guard2 = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      } else {
        uMultiWordShl(&DroneModel_B.xint.chunks[0U], 2, 10U,
                      &DroneModel_B.r26.chunks[0U], 2);
        DroneModel_B.xint = DroneModel_B.r26;
        guard2 = true;
      }

      if (guard2) {
        MultiWordAnd(&DroneModel_B.xint.chunks[0U], &tmp.chunks[0U],
                     &DroneModel_B.r29.chunks[0U], 2);
        if (uMultiWordNe(&DroneModel_B.r29.chunks[0U], &tmp_3.chunks[0U], 2)) {
          guard1 = true;
        } else {
          uMultiWordShl(&DroneModel_B.xint.chunks[0U], 2, 1U,
                        &DroneModel_B.r30.chunks[0U], 2);
          if (uMultiWordGe(&DroneModel_B.r30.chunks[0U],
                           &DroneModel_B.nk_unsgn.chunks[0U], 2)) {
            guard1 = true;
          }
        }
      }

      if (guard1) {
        MultiWordAdd(&DroneModel_B.res.chunks[0U], &tmp_0.chunks[0U],
                     &DroneModel_B.r31.chunks[0U], 2);
        DroneModel_B.res = DroneModel_B.r31;
      }
    }
  }

  if (b_isQuotNegative) {
    if (uMultiWordLe(&DroneModel_B.res.chunks[0U], &tmp_2.chunks[0U], 2)) {
      uMultiWord2MultiWord(&DroneModel_B.res.chunks[0U], 2,
                           &DroneModel_B.r25.chunks[0U], 2);
      MultiWordNeg(&DroneModel_B.r25.chunks[0U], &z.chunks[0U], 2);
    } else {
      z = tmp_6;
    }
  } else if (uMultiWordLe(&DroneModel_B.res.chunks[0U], &tmp_2.chunks[0U], 2)) {
    uMultiWord2MultiWord(&DroneModel_B.res.chunks[0U], 2,
                         &DroneModel_B.r24.chunks[0U], 2);
    z = DroneModel_B.r24;
  } else {
    z = tmp_5;
  }

  return z;
}

static uint64m_T DroneModel_eml_mixed_uint64_mul(const uint64m_T nv, real_T y)
{
  uint64m_T z;
  int32_T ex_t;
  int16_T tmp;
  int16_T tmp_0;
  int16_T tmp_1;
  static const uint64m_T tmp_2 = { { MAX_uint32_T, MAX_uint32_T }/* chunks */
  };

  static const uint64m_T tmp_3 = { { 1U, 0U }/* chunks */
  };

  static const uint64m_T tmp_4 = { { MAX_uint32_T, 0U }/* chunks */
  };

  static const uint64m_T tmp_5 = { { 0U, 0U }/* chunks */
  };

  boolean_T guard1;
  if (rtIsNaN(y) || (y <= 0.0)) {
    z = tmp_5;
  } else {
    DroneModel_B.yd = frexp(y, &ex_t);
    if (ex_t <= -64) {
      z = tmp_5;
    } else {
      Double2MultiWord(rt_roundd_snf(DroneModel_B.yd * 9.007199254740992E+15),
                       &DroneModel_B.yint.chunks[0U], 2);
      uMultiWordShr(&DroneModel_B.yint.chunks[0U], 2, 32U,
                    &DroneModel_B.b_y1.chunks[0U], 2);
      MultiWordAnd(&DroneModel_B.yint.chunks[0U], &tmp_4.chunks[0U],
                   &DroneModel_B.b_y0.chunks[0U], 2);
      if (uMultiWordEq(&nv.chunks[0U], &tmp_5.chunks[0U], 2)) {
        z = tmp_5;
      } else if (rtIsInf(y)) {
        z = tmp_2;
      } else if (ex_t - 53 > 64) {
        z = tmp_2;
      } else {
        uMultiWordShr(&nv.chunks[0U], 2, 32U, &DroneModel_B.n1.chunks[0U], 2);
        DroneModel_B.r45 = nv;
        DroneModel_B.r46 = tmp_4;
        MultiWordAnd(&nv.chunks[0U], &tmp_4.chunks[0U], &DroneModel_B.n0.chunks
                     [0U], 2);
        uMultiWordMul(&DroneModel_B.n0.chunks[0U], 2, &DroneModel_B.b_y0.chunks
                      [0U], 2, &DroneModel_B.r3.chunks[0U], 4);
        uMultiWord2MultiWord(&DroneModel_B.r3.chunks[0U], 4,
                             &DroneModel_B.yint.chunks[0U], 2);
        uMultiWordMul(&DroneModel_B.n0.chunks[0U], 2, &DroneModel_B.b_y1.chunks
                      [0U], 2, &DroneModel_B.r3.chunks[0U], 4);
        uMultiWord2MultiWord(&DroneModel_B.r3.chunks[0U], 4,
                             &DroneModel_B.n0.chunks[0U], 2);
        uMultiWordMul(&DroneModel_B.n1.chunks[0U], 2, &DroneModel_B.b_y0.chunks
                      [0U], 2, &DroneModel_B.r3.chunks[0U], 4);
        uMultiWord2MultiWord(&DroneModel_B.r3.chunks[0U], 4,
                             &DroneModel_B.b_y0.chunks[0U], 2);
        DroneModel_B.r47 = tmp_4;
        MultiWordAnd(&DroneModel_B.n0.chunks[0U], &tmp_4.chunks[0U],
                     &DroneModel_B.r46.chunks[0U], 2);
        uMultiWordShr(&DroneModel_B.yint.chunks[0U], 2, 32U,
                      &DroneModel_B.r47.chunks[0U], 2);
        MultiWordAdd(&DroneModel_B.r46.chunks[0U], &DroneModel_B.r47.chunks[0U],
                     &DroneModel_B.r45.chunks[0U], 2);
        DroneModel_B.r47 = tmp_4;
        MultiWordAnd(&DroneModel_B.b_y0.chunks[0U], &tmp_4.chunks[0U],
                     &DroneModel_B.r46.chunks[0U], 2);
        MultiWordAdd(&DroneModel_B.r45.chunks[0U], &DroneModel_B.r46.chunks[0U],
                     &DroneModel_B.temp.chunks[0U], 2);
        DroneModel_B.r46 = tmp_4;
        MultiWordAnd(&DroneModel_B.yint.chunks[0U], &tmp_4.chunks[0U],
                     &DroneModel_B.r45.chunks[0U], 2);
        uMultiWordShl(&DroneModel_B.temp.chunks[0U], 2, 32U,
                      &DroneModel_B.r46.chunks[0U], 2);
        MultiWordAdd(&DroneModel_B.r45.chunks[0U], &DroneModel_B.r46.chunks[0U],
                     &DroneModel_B.yint.chunks[0U], 2);
        uMultiWordMul(&DroneModel_B.n1.chunks[0U], 2, &DroneModel_B.b_y1.chunks
                      [0U], 2, &DroneModel_B.r3.chunks[0U], 4);
        uMultiWord2MultiWord(&DroneModel_B.r3.chunks[0U], 4,
                             &DroneModel_B.r47.chunks[0U], 2);
        uMultiWordShr(&DroneModel_B.n0.chunks[0U], 2, 32U,
                      &DroneModel_B.r48.chunks[0U], 2);
        MultiWordAdd(&DroneModel_B.r47.chunks[0U], &DroneModel_B.r48.chunks[0U],
                     &DroneModel_B.r46.chunks[0U], 2);
        uMultiWordShr(&DroneModel_B.b_y0.chunks[0U], 2, 32U,
                      &DroneModel_B.r47.chunks[0U], 2);
        MultiWordAdd(&DroneModel_B.r46.chunks[0U], &DroneModel_B.r47.chunks[0U],
                     &DroneModel_B.r45.chunks[0U], 2);
        uMultiWordShr(&DroneModel_B.temp.chunks[0U], 2, 32U,
                      &DroneModel_B.r46.chunks[0U], 2);
        MultiWordAdd(&DroneModel_B.r45.chunks[0U], &DroneModel_B.r46.chunks[0U],
                     &DroneModel_B.b_y1.chunks[0U], 2);
        if (ex_t - 53 >= 0) {
          if (uMultiWordGt(&DroneModel_B.b_y1.chunks[0U], &tmp_5.chunks[0U], 2))
          {
            z = tmp_2;
          } else {
            guard1 = false;
            if (117 - ex_t < 64) {
              tmp = (int16_T)(117 - ex_t);
              if ((int16_T)(117 - ex_t) < 0) {
                tmp = 0;
              }

              uMultiWordShr(&DroneModel_B.yint.chunks[0U], 2, (uint32_T)tmp,
                            &DroneModel_B.r50.chunks[0U], 2);
              if (uMultiWordGt(&DroneModel_B.r50.chunks[0U], &tmp_5.chunks[0U],
                               2)) {
                z = tmp_2;
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }

            if (guard1) {
              tmp = (int16_T)(ex_t - 53);
              if ((int16_T)(ex_t - 53) < 0) {
                tmp = 0;
              } else if ((int16_T)(ex_t - 53) > 255) {
                tmp = 255;
              }

              uMultiWordShl(&DroneModel_B.yint.chunks[0U], 2, (uint32_T)tmp,
                            &z.chunks[0U], 2);
            }
          }
        } else if (ex_t - 53 > -64) {
          tmp = (int16_T)(53 - ex_t);
          if ((int16_T)(53 - ex_t) < 0) {
            tmp = 0;
          }

          uMultiWordShr(&DroneModel_B.b_y1.chunks[0U], 2, (uint32_T)tmp,
                        &DroneModel_B.r45.chunks[0U], 2);
          if (uMultiWordGt(&DroneModel_B.r45.chunks[0U], &tmp_5.chunks[0U], 2))
          {
            z = tmp_2;
          } else {
            tmp = (int16_T)(53 - ex_t);
            if ((int16_T)(53 - ex_t) < 0) {
              tmp = 0;
            }

            tmp_0 = (int16_T)(ex_t + 11);
            if ((int16_T)(ex_t + 11) < 0) {
              tmp_0 = 0;
            } else if ((int16_T)(ex_t + 11) > 255) {
              tmp_0 = 255;
            }

            tmp_1 = (int16_T)(52 - ex_t);
            if ((int16_T)(52 - ex_t) < 0) {
              tmp_1 = 0;
            }

            uMultiWordShr(&DroneModel_B.yint.chunks[0U], 2, (uint32_T)tmp,
                          &DroneModel_B.r50.chunks[0U], 2);
            uMultiWordShl(&DroneModel_B.b_y1.chunks[0U], 2, (uint32_T)tmp_0,
                          &z.chunks[0U], 2);
            MultiWordAdd(&DroneModel_B.r50.chunks[0U], &z.chunks[0U],
                         &DroneModel_B.r49.chunks[0U], 2);
            uMultiWordShr(&DroneModel_B.yint.chunks[0U], 2, (uint32_T)tmp_1,
                          &z.chunks[0U], 2);
            MultiWordAnd(&z.chunks[0U], &tmp_3.chunks[0U],
                         &DroneModel_B.r50.chunks[0U], 2);
            MultiWordAdd(&DroneModel_B.r49.chunks[0U], &DroneModel_B.r50.chunks
                         [0U], &z.chunks[0U], 2);
          }
        } else if (ex_t - 53 == -64) {
          uMultiWordShr(&DroneModel_B.yint.chunks[0U], 2, 63U,
                        &DroneModel_B.r46.chunks[0U], 2);
          MultiWordAnd(&DroneModel_B.r46.chunks[0U], &tmp_3.chunks[0U],
                       &DroneModel_B.r45.chunks[0U], 2);
          MultiWordAdd(&DroneModel_B.b_y1.chunks[0U], &DroneModel_B.r45.chunks
                       [0U], &DroneModel_B.r46.chunks[0U], 2);
          z = DroneModel_B.r46;
        } else {
          tmp = (int16_T)-(ex_t + 11);
          if ((int16_T)-(ex_t + 11) < 0) {
            tmp = 0;
          }

          tmp_0 = (int16_T)-(ex_t + 12);
          if ((int16_T)-(ex_t + 12) < 0) {
            tmp_0 = 0;
          }

          uMultiWordShr(&DroneModel_B.b_y1.chunks[0U], 2, (uint32_T)tmp,
                        &DroneModel_B.r45.chunks[0U], 2);
          uMultiWordShr(&DroneModel_B.b_y1.chunks[0U], 2, (uint32_T)tmp_0,
                        &DroneModel_B.r47.chunks[0U], 2);
          MultiWordAnd(&DroneModel_B.r47.chunks[0U], &tmp_3.chunks[0U],
                       &DroneModel_B.r46.chunks[0U], 2);
          MultiWordAdd(&DroneModel_B.r45.chunks[0U], &DroneModel_B.r46.chunks[0U],
                       &DroneModel_B.r47.chunks[0U], 2);
          z = DroneModel_B.r47;
        }
      }
    }
  }

  return z;
}

static int64m_T DroneModel_times(real_T x, const int64m_T y)
{
  int64m_T z;
  boolean_T isProdNegative;
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

  if ((sMultiWordLt(&y.chunks[0U], &tmp_2.chunks[0U], 2) && (x > 0.0)) ||
      (sMultiWordGt(&y.chunks[0U], &tmp_2.chunks[0U], 2) && (x < 0.0))) {
    isProdNegative = true;
  } else {
    isProdNegative = false;
  }

  if (x < 0.0) {
    if (sMultiWordLt(&y.chunks[0U], &tmp_2.chunks[0U], 2)) {
      if (sMultiWordGt(&y.chunks[0U], &tmp.chunks[0U], 2)) {
        DroneModel_B.r44 = y;
        MultiWordNeg(&y.chunks[0U], &DroneModel_B.r43.chunks[0U], 2);
        sMultiWord2MultiWord(&DroneModel_B.r43.chunks[0U], 2,
                             &DroneModel_B.prod_unsgn.chunks[0U], 2);
      } else {
        DroneModel_B.prod_unsgn = tmp_3;
      }
    } else {
      sMultiWord2MultiWord(&y.chunks[0U], 2, &DroneModel_B.prod_unsgn.chunks[0U],
                           2);
    }

    DroneModel_B.prod_unsgn = DroneModel_eml_mixed_uint64_mul
      (DroneModel_B.prod_unsgn, -x);
  } else {
    if (sMultiWordLt(&y.chunks[0U], &tmp_2.chunks[0U], 2)) {
      if (sMultiWordGt(&y.chunks[0U], &tmp.chunks[0U], 2)) {
        MultiWordNeg(&y.chunks[0U], &DroneModel_B.r42.chunks[0U], 2);
        sMultiWord2MultiWord(&DroneModel_B.r42.chunks[0U], 2,
                             &DroneModel_B.prod_unsgn.chunks[0U], 2);
      } else {
        DroneModel_B.prod_unsgn = tmp_3;
      }
    } else {
      sMultiWord2MultiWord(&y.chunks[0U], 2, &DroneModel_B.prod_unsgn.chunks[0U],
                           2);
    }

    DroneModel_B.prod_unsgn = DroneModel_eml_mixed_uint64_mul
      (DroneModel_B.prod_unsgn, x);
  }

  if (isProdNegative) {
    if (uMultiWordLe(&DroneModel_B.prod_unsgn.chunks[0U], &tmp_1.chunks[0U], 2))
    {
      uMultiWord2MultiWord(&DroneModel_B.prod_unsgn.chunks[0U], 2,
                           &DroneModel_B.r44.chunks[0U], 2);
      MultiWordNeg(&DroneModel_B.r44.chunks[0U], &z.chunks[0U], 2);
    } else {
      z = tmp;
    }
  } else if (uMultiWordLe(&DroneModel_B.prod_unsgn.chunks[0U], &tmp_1.chunks[0U],
              2)) {
    uMultiWord2MultiWord(&DroneModel_B.prod_unsgn.chunks[0U], 2,
                         &DroneModel_B.r43.chunks[0U], 2);
    z = DroneModel_B.r43;
  } else {
    z = tmp_0;
  }

  return z;
}

static real_T DroneM_bbblueBarometer_stepImpl(const
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

  bbblueBarometer_BMP_ReadRegiste(obj, data, &a__3);
  rawT = data[3] << 12 | data[4] << 4 | data[5] >> 4;
  sLong2MultiWord(rawT, &DroneModel_B.r17.chunks[0U], 2);
  sMultiWordShr(&DroneModel_B.r17.chunks[0U], 2, 3U, &DroneModel_B.r16.chunks[0U],
                2);
  sMultiWord2MultiWord(&DroneModel_B.r16.chunks[0U], 2, &DroneModel_B.r9.chunks
                       [0U], 3);
  uLong2MultiWord(obj->dig_T1, &DroneModel_B.r17.chunks[0U], 2);
  sMultiWordShl(&DroneModel_B.r17.chunks[0U], 2, 1U, &DroneModel_B.r16.chunks[0U],
                2);
  sMultiWord2MultiWord(&DroneModel_B.r16.chunks[0U], 2,
                       &DroneModel_B.r10.chunks[0U], 3);
  MultiWordSub(&DroneModel_B.r9.chunks[0U], &DroneModel_B.r10.chunks[0U],
               &DroneModel_B.r8.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&DroneModel_B.r8.chunks[0U], 3,
    &DroneModel_B.r15.chunks[0U], 2);
  sLong2MultiWord(obj->dig_T2, &DroneModel_B.r16.chunks[0U], 2);
  sMultiWordMul(&DroneModel_B.r15.chunks[0U], 2, &DroneModel_B.r16.chunks[0U], 2,
                &DroneModel_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&DroneModel_B.r.chunks[0U], 4,
    &DroneModel_B.r14.chunks[0U], 2);
  sMultiWordShr(&DroneModel_B.r14.chunks[0U], 2, 11U, &DroneModel_B.r13.chunks
                [0U], 2);
  sMultiWord2MultiWord(&DroneModel_B.r13.chunks[0U], 2, &DroneModel_B.r7.chunks
                       [0U], 3);
  sLong2MultiWord(rawT, &DroneModel_B.r19.chunks[0U], 2);
  sMultiWordShr(&DroneModel_B.r19.chunks[0U], 2, 4U, &DroneModel_B.r18.chunks[0U],
                2);
  sMultiWord2MultiWord(&DroneModel_B.r18.chunks[0U], 2,
                       &DroneModel_B.r10.chunks[0U], 3);
  uLong2MultiWord(obj->dig_T1, &DroneModel_B.r18.chunks[0U], 2);
  sMultiWord2MultiWord(&DroneModel_B.r18.chunks[0U], 2,
                       &DroneModel_B.r11.chunks[0U], 3);
  MultiWordSub(&DroneModel_B.r10.chunks[0U], &DroneModel_B.r11.chunks[0U],
               &DroneModel_B.r9.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&DroneModel_B.r9.chunks[0U], 3,
    &DroneModel_B.r17.chunks[0U], 2);
  sLong2MultiWord(rawT, &DroneModel_B.r20.chunks[0U], 2);
  sMultiWordShr(&DroneModel_B.r20.chunks[0U], 2, 4U, &DroneModel_B.r19.chunks[0U],
                2);
  sMultiWord2MultiWord(&DroneModel_B.r19.chunks[0U], 2,
                       &DroneModel_B.r10.chunks[0U], 3);
  uLong2MultiWord(obj->dig_T1, &DroneModel_B.r19.chunks[0U], 2);
  sMultiWord2MultiWord(&DroneModel_B.r19.chunks[0U], 2,
                       &DroneModel_B.r11.chunks[0U], 3);
  MultiWordSub(&DroneModel_B.r10.chunks[0U], &DroneModel_B.r11.chunks[0U],
               &DroneModel_B.r9.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&DroneModel_B.r9.chunks[0U], 3,
    &DroneModel_B.r18.chunks[0U], 2);
  sMultiWordMul(&DroneModel_B.r17.chunks[0U], 2, &DroneModel_B.r18.chunks[0U], 2,
                &DroneModel_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&DroneModel_B.r1.chunks[0U], 4,
    &DroneModel_B.r16.chunks[0U], 2);
  sMultiWordShr(&DroneModel_B.r16.chunks[0U], 2, 12U, &DroneModel_B.r15.chunks
                [0U], 2);
  sLong2MultiWord(obj->dig_T3, &DroneModel_B.r16.chunks[0U], 2);
  sMultiWordMul(&DroneModel_B.r15.chunks[0U], 2, &DroneModel_B.r16.chunks[0U], 2,
                &DroneModel_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&DroneModel_B.r.chunks[0U], 4,
    &DroneModel_B.r14.chunks[0U], 2);
  sMultiWordShr(&DroneModel_B.r14.chunks[0U], 2, 14U, &DroneModel_B.r13.chunks
                [0U], 2);
  sMultiWord2MultiWord(&DroneModel_B.r13.chunks[0U], 2, &DroneModel_B.r8.chunks
                       [0U], 3);
  MultiWordAdd(&DroneModel_B.r7.chunks[0U], &DroneModel_B.r8.chunks[0U],
               &DroneModel_B.r6.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&DroneModel_B.r6.chunks[0U], 3,
    &DroneModel_B.r12.chunks[0U], 2);
  sMultiWord2MultiWord(&DroneModel_B.r12.chunks[0U], 2, &DroneModel_B.r5.chunks
                       [0U], 3);
  DroneModel_B.r12 = tmp_0;
  sMultiWord2MultiWord(&tmp_0.chunks[0U], 2, &DroneModel_B.r6.chunks[0U], 3);
  MultiWordSub(&DroneModel_B.r5.chunks[0U], &DroneModel_B.r6.chunks[0U],
               &DroneModel_B.r4.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&DroneModel_B.r4.chunks[0U], 3,
    &DroneModel_B.val3.chunks[0U], 2);
  sMultiWordMul(&DroneModel_B.val3.chunks[0U], 2, &DroneModel_B.val3.chunks[0U],
                2, &DroneModel_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&DroneModel_B.r1.chunks[0U], 4,
    &DroneModel_B.r13.chunks[0U], 2);
  sLong2MultiWord(obj->dig_P6, &DroneModel_B.r14.chunks[0U], 2);
  sMultiWordMul(&DroneModel_B.r13.chunks[0U], 2, &DroneModel_B.r14.chunks[0U], 2,
                &DroneModel_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&DroneModel_B.r.chunks[0U], 4,
    &DroneModel_B.r12.chunks[0U], 2);
  sMultiWord2MultiWord(&DroneModel_B.r12.chunks[0U], 2, &DroneModel_B.r5.chunks
                       [0U], 3);
  sLong2MultiWord(obj->dig_P5, &DroneModel_B.r14.chunks[0U], 2);
  sMultiWordMul(&DroneModel_B.val3.chunks[0U], 2, &DroneModel_B.r14.chunks[0U],
                2, &DroneModel_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&DroneModel_B.r.chunks[0U], 4,
    &DroneModel_B.r13.chunks[0U], 2);
  sMultiWordShl(&DroneModel_B.r13.chunks[0U], 2, 17U, &DroneModel_B.r12.chunks
                [0U], 2);
  sMultiWord2MultiWord(&DroneModel_B.r12.chunks[0U], 2, &DroneModel_B.r6.chunks
                       [0U], 3);
  MultiWordAdd(&DroneModel_B.r5.chunks[0U], &DroneModel_B.r6.chunks[0U],
               &DroneModel_B.r4.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&DroneModel_B.r4.chunks[0U], 3,
    &DroneModel_B.val4.chunks[0U], 2);
  sMultiWordMul(&DroneModel_B.val3.chunks[0U], 2, &DroneModel_B.val3.chunks[0U],
                2, &DroneModel_B.r1.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&DroneModel_B.r1.chunks[0U], 4,
    &DroneModel_B.r13.chunks[0U], 2);
  sLong2MultiWord(obj->dig_P3, &DroneModel_B.r14.chunks[0U], 2);
  sMultiWordMul(&DroneModel_B.r13.chunks[0U], 2, &DroneModel_B.r14.chunks[0U], 2,
                &DroneModel_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&DroneModel_B.r.chunks[0U], 4,
    &DroneModel_B.r12.chunks[0U], 2);
  sMultiWordShr(&DroneModel_B.r12.chunks[0U], 2, 8U, &DroneModel_B.c.chunks[0U],
                2);
  sLong2MultiWord(obj->dig_P2, &DroneModel_B.r13.chunks[0U], 2);
  sMultiWordMul(&DroneModel_B.val3.chunks[0U], 2, &DroneModel_B.r13.chunks[0U],
                2, &DroneModel_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&DroneModel_B.r.chunks[0U], 4,
    &DroneModel_B.r12.chunks[0U], 2);
  sMultiWordShl(&DroneModel_B.r12.chunks[0U], 2, 12U, &DroneModel_B.val3.chunks
                [0U], 2);
  DroneModel_B.r14 = tmp;
  sMultiWord2MultiWord(&tmp.chunks[0U], 2, &DroneModel_B.r5.chunks[0U], 3);
  sMultiWord2MultiWord(&DroneModel_B.c.chunks[0U], 2, &DroneModel_B.r8.chunks[0U],
                       3);
  sMultiWord2MultiWord(&DroneModel_B.val3.chunks[0U], 2,
                       &DroneModel_B.r9.chunks[0U], 3);
  MultiWordAdd(&DroneModel_B.r8.chunks[0U], &DroneModel_B.r9.chunks[0U],
               &DroneModel_B.r7.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&DroneModel_B.r7.chunks[0U], 3,
    &DroneModel_B.r14.chunks[0U], 2);
  sMultiWord2MultiWord(&DroneModel_B.r14.chunks[0U], 2, &DroneModel_B.r6.chunks
                       [0U], 3);
  MultiWordAdd(&DroneModel_B.r5.chunks[0U], &DroneModel_B.r6.chunks[0U],
               &DroneModel_B.r4.chunks[0U], 3);
  sMultiWord2sMultiWordSat(&DroneModel_B.r4.chunks[0U], 3,
    &DroneModel_B.r13.chunks[0U], 2);
  uLong2MultiWord(obj->dig_P1, &DroneModel_B.r14.chunks[0U], 2);
  sMultiWordMul(&DroneModel_B.r13.chunks[0U], 2, &DroneModel_B.r14.chunks[0U], 2,
                &DroneModel_B.r.chunks[0U], 4);
  sMultiWord2sMultiWordSat(&DroneModel_B.r.chunks[0U], 4,
    &DroneModel_B.r12.chunks[0U], 2);
  sMultiWordShr(&DroneModel_B.r12.chunks[0U], 2, 33U, &DroneModel_B.val3.chunks
                [0U], 2);
  if (sMultiWordEq(&DroneModel_B.val3.chunks[0U], &tmp_2.chunks[0U], 2)) {
    y = 0.0;
  } else {
    sLong2MultiWord(1048576 - (data[0] << 12 | data[1] << 4 | data[2] >> 4),
                    &DroneModel_B.r16.chunks[0U], 2);
    sMultiWordShl(&DroneModel_B.r16.chunks[0U], 2, 31U,
                  &DroneModel_B.r15.chunks[0U], 2);
    sMultiWord2MultiWord(&DroneModel_B.r15.chunks[0U], 2,
                         &DroneModel_B.r6.chunks[0U], 3);
    sMultiWord2MultiWord(&DroneModel_B.val4.chunks[0U], 2,
                         &DroneModel_B.r9.chunks[0U], 3);
    sLong2MultiWord(obj->dig_P4, &DroneModel_B.r17.chunks[0U], 2);
    sMultiWordShl(&DroneModel_B.r17.chunks[0U], 2, 35U,
                  &DroneModel_B.r16.chunks[0U], 2);
    sMultiWord2MultiWord(&DroneModel_B.r16.chunks[0U], 2,
                         &DroneModel_B.r10.chunks[0U], 3);
    MultiWordAdd(&DroneModel_B.r9.chunks[0U], &DroneModel_B.r10.chunks[0U],
                 &DroneModel_B.r8.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&DroneModel_B.r8.chunks[0U], 3,
      &DroneModel_B.r15.chunks[0U], 2);
    sMultiWord2MultiWord(&DroneModel_B.r15.chunks[0U], 2,
                         &DroneModel_B.r7.chunks[0U], 3);
    MultiWordSub(&DroneModel_B.r6.chunks[0U], &DroneModel_B.r7.chunks[0U],
                 &DroneModel_B.r5.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&DroneModel_B.r5.chunks[0U], 3,
      &DroneModel_B.r14.chunks[0U], 2);
    DroneModel_B.r15 = tmp_1;
    sMultiWordMul(&DroneModel_B.r14.chunks[0U], 2, &tmp_1.chunks[0U], 2,
                  &DroneModel_B.r4.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&DroneModel_B.r4.chunks[0U], 3,
      &DroneModel_B.r13.chunks[0U], 2);
    DroneModel_B.val4 = DroneModel_i64ddiv(sMultiWord2Double
      (&DroneModel_B.r13.chunks[0U], 2, 0), DroneModel_B.val3);
    sMultiWord2MultiWord(&DroneModel_B.val4.chunks[0U], 2,
                         &DroneModel_B.r9.chunks[0U], 3);
    sLong2MultiWord(obj->dig_P9, &DroneModel_B.r20.chunks[0U], 2);
    sMultiWordShr(&DroneModel_B.val4.chunks[0U], 2, 13U,
                  &DroneModel_B.r22.chunks[0U], 2);
    sMultiWordShr(&DroneModel_B.val4.chunks[0U], 2, 13U,
                  &DroneModel_B.r23.chunks[0U], 2);
    sMultiWordMul(&DroneModel_B.r22.chunks[0U], 2, &DroneModel_B.r23.chunks[0U],
                  2, &DroneModel_B.r1.chunks[0U], 4);
    sMultiWord2sMultiWordSat(&DroneModel_B.r1.chunks[0U], 4,
      &DroneModel_B.r21.chunks[0U], 2);
    sMultiWordMul(&DroneModel_B.r20.chunks[0U], 2, &DroneModel_B.r21.chunks[0U],
                  2, &DroneModel_B.r.chunks[0U], 4);
    sMultiWord2sMultiWordSat(&DroneModel_B.r.chunks[0U], 4,
      &DroneModel_B.r19.chunks[0U], 2);
    sMultiWordShr(&DroneModel_B.r19.chunks[0U], 2, 25U,
                  &DroneModel_B.r18.chunks[0U], 2);
    sMultiWord2MultiWord(&DroneModel_B.r18.chunks[0U], 2,
                         &DroneModel_B.r10.chunks[0U], 3);
    MultiWordAdd(&DroneModel_B.r9.chunks[0U], &DroneModel_B.r10.chunks[0U],
                 &DroneModel_B.r8.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&DroneModel_B.r8.chunks[0U], 3,
      &DroneModel_B.r17.chunks[0U], 2);
    sMultiWord2MultiWord(&DroneModel_B.r17.chunks[0U], 2,
                         &DroneModel_B.r7.chunks[0U], 3);
    DroneModel_B.r18 = DroneModel_times((real_T)obj->dig_P8, DroneModel_B.val4);
    sMultiWordShr(&DroneModel_B.r18.chunks[0U], 2, 19U,
                  &DroneModel_B.r17.chunks[0U], 2);
    sMultiWord2MultiWord(&DroneModel_B.r17.chunks[0U], 2,
                         &DroneModel_B.r8.chunks[0U], 3);
    MultiWordAdd(&DroneModel_B.r7.chunks[0U], &DroneModel_B.r8.chunks[0U],
                 &DroneModel_B.r6.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&DroneModel_B.r6.chunks[0U], 3,
      &DroneModel_B.r16.chunks[0U], 2);
    sMultiWordShr(&DroneModel_B.r16.chunks[0U], 2, 8U, &DroneModel_B.r15.chunks
                  [0U], 2);
    sMultiWord2MultiWord(&DroneModel_B.r15.chunks[0U], 2,
                         &DroneModel_B.r5.chunks[0U], 3);
    sLong2MultiWord(obj->dig_P7, &DroneModel_B.r16.chunks[0U], 2);
    sMultiWordShl(&DroneModel_B.r16.chunks[0U], 2, 4U, &DroneModel_B.r15.chunks
                  [0U], 2);
    sMultiWord2MultiWord(&DroneModel_B.r15.chunks[0U], 2,
                         &DroneModel_B.r6.chunks[0U], 3);
    MultiWordAdd(&DroneModel_B.r5.chunks[0U], &DroneModel_B.r6.chunks[0U],
                 &DroneModel_B.r4.chunks[0U], 3);
    sMultiWord2sMultiWordSat(&DroneModel_B.r4.chunks[0U], 3,
      &DroneModel_B.r14.chunks[0U], 2);
    y = sMultiWord2Double(&DroneModel_B.r14.chunks[0U], 2, 0) / 256.0;
  }

  return y;
}

/* Model step function */
void DroneModel_step(void)
{
  int32_T i;
  int_T ri;
  uint8_T b_RegisterValue_1[7];
  uint8_T output_raw_0[7];
  uint8_T b_RegisterValue[6];
  uint8_T output_raw[6];
  uint8_T SwappedDataBytes;
  uint8_T b_RegisterValue_0;
  uint8_T status;
  boolean_T guard1;
  if (rtmIsMajorTimeStep(DroneModel_M)) {
    /* set solver stop time */
    if (!(DroneModel_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&DroneModel_M->solverInfo,
                            ((DroneModel_M->Timing.clockTickH0 + 1) *
        DroneModel_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&DroneModel_M->solverInfo,
                            ((DroneModel_M->Timing.clockTick0 + 1) *
        DroneModel_M->Timing.stepSize0 + DroneModel_M->Timing.clockTickH0 *
        DroneModel_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(DroneModel_M)) {
    DroneModel_M->Timing.t[0] = rtsiGetT(&DroneModel_M->solverInfo);
  }

  /* StateSpace: '<S2>/State-Space' */
  for (i = 0; i < 6; i++) {
    DroneModel_B.StateSpace[i] = 0.0;
  }

  for (i = 0; i < 12; i++) {
    for (ri = 0; ri < 6; ri++) {
      DroneModel_B.StateSpace[ri] += DroneModel_P.C[i * 6 + ri] *
        DroneModel_X.StateSpace_CSTATE[i];
    }
  }

  /* End of StateSpace: '<S2>/State-Space' */
  if (rtmIsMajorTimeStep(DroneModel_M)) {
    /* Gain: '<S2>/Multiply' incorporates:
     *  Constant: '<S2>/Motor Thrusts'
     */
    DroneModel_B.Multiply[0] = DroneModel_P.Multiply_Gain *
      DroneModel_P.MotorThrusts_Value[0];
    DroneModel_B.Multiply[1] = DroneModel_P.Multiply_Gain *
      DroneModel_P.MotorThrusts_Value[1];
    DroneModel_B.Multiply[2] = DroneModel_P.Multiply_Gain *
      DroneModel_P.MotorThrusts_Value[2];
    DroneModel_B.Multiply[3] = DroneModel_P.Multiply_Gain *
      DroneModel_P.MotorThrusts_Value[3];
  }

  /* Step: '<S2>/Step' */
  if (DroneModel_M->Timing.t[0] < DroneModel_P.Step_Time) {
    DroneModel_B.Step = DroneModel_P.Step_Y0;
  } else {
    DroneModel_B.Step = DroneModel_P.Step_YFinal;
  }

  /* End of Step: '<S2>/Step' */

  /* Sum: '<S3>/Subtract' incorporates:
   *  Constant: '<S3>/Load per motor'
   */
  DroneModel_B.d = DroneModel_P.m * DroneModel_P.g / 4.0;

  /* Sum: '<S3>/Subtract' incorporates:
   *  Gain: '<S2>/Multiply'
   *  Product: '<S2>/Product'
   */
  DroneModel_B.Subtract[0] = DroneModel_B.Step * DroneModel_B.Multiply[0] -
    DroneModel_B.d;
  DroneModel_B.Subtract[1] = DroneModel_B.Step * DroneModel_B.Multiply[1] -
    DroneModel_B.d;
  DroneModel_B.Subtract[2] = DroneModel_B.Step * DroneModel_B.Multiply[2] -
    DroneModel_B.d;
  DroneModel_B.Subtract[3] = DroneModel_B.Step * DroneModel_B.Multiply[3] -
    DroneModel_B.d;
  if (rtmIsMajorTimeStep(DroneModel_M)) {
    /* MATLABSystem: '<S2>/MPU9250' */
    if (DroneModel_DW.obj.SampleTime != DroneModel_P.MPU9250_SampleTime) {
      DroneModel_DW.obj.SampleTime = DroneModel_P.MPU9250_SampleTime;
    }

    if (DroneModel_DW.obj.TunablePropsChanged) {
      DroneModel_DW.obj.TunablePropsChanged = false;
    }

    status = 59U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(DroneModel_DW.obj.i2cObjmpu.MW_I2C_HANDLE, 104U,
      &SwappedDataBytes, 1U, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(DroneModel_DW.obj.i2cObjmpu.MW_I2C_HANDLE, 104U,
                        &output_raw[0], 6U, false, true);
      memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (size_t)6 *
             sizeof(uint8_T));
    } else {
      for (i = 0; i < 6; i++) {
        b_RegisterValue[i] = 0U;
      }
    }

    DroneModel_B.MPU9250_o1[0] = (int16_T)(b_RegisterValue[0] << 8) |
      b_RegisterValue[1];
    DroneModel_B.MPU9250_o1[1] = (int16_T)(b_RegisterValue[2] << 8) |
      b_RegisterValue[3];
    DroneModel_B.MPU9250_o1[2] = (int16_T)(b_RegisterValue[4] << 8) |
      b_RegisterValue[5];
    status = 67U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(DroneModel_DW.obj.i2cObjmpu.MW_I2C_HANDLE, 104U,
      &SwappedDataBytes, 1U, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(DroneModel_DW.obj.i2cObjmpu.MW_I2C_HANDLE, 104U,
                        &output_raw[0], 6U, false, true);
      memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (size_t)6 *
             sizeof(uint8_T));
    } else {
      for (i = 0; i < 6; i++) {
        b_RegisterValue[i] = 0U;
      }
    }

    DroneModel_B.MPU9250_o2[0] = (int16_T)(b_RegisterValue[0] << 8) |
      b_RegisterValue[1];
    DroneModel_B.MPU9250_o2[1] = (int16_T)(b_RegisterValue[2] << 8) |
      b_RegisterValue[3];
    DroneModel_B.MPU9250_o2[2] = (int16_T)(b_RegisterValue[4] << 8) |
      b_RegisterValue[5];
    status = 2U;
    memcpy((void *)&SwappedDataBytes, (void *)&status, (size_t)1 * sizeof
           (uint8_T));
    status = MW_I2C_MasterWrite(DroneModel_DW.obj.i2cObjak8963.MW_I2C_HANDLE,
      12U, &SwappedDataBytes, 1U, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(DroneModel_DW.obj.i2cObjak8963.MW_I2C_HANDLE, 12U,
                        &status, 1U, false, true);
      memcpy((void *)&b_RegisterValue_0, (void *)&status, (size_t)1 * sizeof
             (uint8_T));
    } else {
      b_RegisterValue_0 = 0U;
    }

    guard1 = false;
    if ((b_RegisterValue_0 & 1U) != 0U) {
      status = 3U;
      memcpy((void *)&SwappedDataBytes, (void *)&status, (size_t)1 * sizeof
             (uint8_T));
      status = MW_I2C_MasterWrite(DroneModel_DW.obj.i2cObjak8963.MW_I2C_HANDLE,
        12U, &SwappedDataBytes, 1U, true, false);
      if (status == 0) {
        MW_I2C_MasterRead(DroneModel_DW.obj.i2cObjak8963.MW_I2C_HANDLE, 12U,
                          &output_raw_0[0], 7U, false, true);
        memcpy((void *)&b_RegisterValue_1[0], (void *)&output_raw_0[0], (size_t)
               7 * sizeof(uint8_T));
      } else {
        for (i = 0; i < 7; i++) {
          b_RegisterValue_1[i] = 0U;
        }
      }

      if ((b_RegisterValue_1[6] & 8) != 8) {
        DroneModel_B.Step = (real_T)((int16_T)(b_RegisterValue_1[1] << 8) |
          b_RegisterValue_1[0]) * DroneModel_DW.obj.AK8963SensitivityAdj[0];
        DroneModel_DW.obj.AK8963Data[0] = DroneModel_B.Step *
          0.14993894993894993;
        DroneModel_B.Step = (real_T)((int16_T)(b_RegisterValue_1[3] << 8) |
          b_RegisterValue_1[2]) * DroneModel_DW.obj.AK8963SensitivityAdj[1];
        DroneModel_DW.obj.AK8963Data[1] = DroneModel_B.Step *
          0.14993894993894993;
        DroneModel_B.Step = (real_T)((int16_T)(b_RegisterValue_1[5] << 8) |
          b_RegisterValue_1[4]) * DroneModel_DW.obj.AK8963SensitivityAdj[2];
        DroneModel_DW.obj.AK8963Data[2] = DroneModel_B.Step *
          0.14993894993894993;

        /* MATLABSystem: '<S2>/MPU9250' */
        DroneModel_B.MPU9250_o3[0] = DroneModel_DW.obj.AK8963Data[0];
        DroneModel_B.MPU9250_o3[1] = DroneModel_DW.obj.AK8963Data[1];
        DroneModel_B.MPU9250_o3[2] = DroneModel_DW.obj.AK8963Data[2];
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      /* MATLABSystem: '<S2>/MPU9250' */
      DroneModel_B.MPU9250_o3[0] = DroneModel_DW.obj.AK8963Data[0];
      DroneModel_B.MPU9250_o3[1] = DroneModel_DW.obj.AK8963Data[1];
      DroneModel_B.MPU9250_o3[2] = DroneModel_DW.obj.AK8963Data[2];
    }

    /* MATLABSystem: '<S2>/MPU9250' */
    DroneModel_B.MPU9250_o1[0] = DroneModel_B.MPU9250_o1[0] * 9.80665 / 16384.0;

    /* MATLABSystem: '<S2>/MPU9250' */
    DroneModel_B.MPU9250_o2[0] *= 0.00762939453125;

    /* MATLABSystem: '<S2>/MPU9250' */
    DroneModel_B.MPU9250_o1[1] = DroneModel_B.MPU9250_o1[1] * 9.80665 / 16384.0;

    /* MATLABSystem: '<S2>/MPU9250' */
    DroneModel_B.MPU9250_o2[1] *= 0.00762939453125;

    /* MATLABSystem: '<S2>/MPU9250' */
    DroneModel_B.MPU9250_o1[2] = DroneModel_B.MPU9250_o1[2] * 9.80665 / 16384.0;

    /* MATLABSystem: '<S2>/MPU9250' */
    DroneModel_B.MPU9250_o2[2] *= 0.00762939453125;

    /* MATLABSystem: '<S2>/Barometer' */
    if (DroneModel_DW.obj_e.SampleTime != DroneModel_P.Barometer_SampleTime) {
      DroneModel_DW.obj_e.SampleTime = DroneModel_P.Barometer_SampleTime;
    }

    /* MATLABSystem: '<S2>/Barometer' */
    DroneModel_B.Barometer = DroneM_bbblueBarometer_stepImpl
      (&DroneModel_DW.obj_e);
  }

  if (rtmIsMajorTimeStep(DroneModel_M)) {
    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, (real_T)DroneModel_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(DroneModel_M)) {/* Sample time: [0.1s, 0.0s] */
      rtExtModeUpload(1, (real_T)(((DroneModel_M->Timing.clockTick1+
        DroneModel_M->Timing.clockTickH1* 4294967296.0)) * 0.1));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(DroneModel_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(DroneModel_M)!=-1) &&
          !((rtmGetTFinal(DroneModel_M)-(((DroneModel_M->Timing.clockTick1+
               DroneModel_M->Timing.clockTickH1* 4294967296.0)) * 0.1)) >
            (((DroneModel_M->Timing.clockTick1+DroneModel_M->Timing.clockTickH1*
               4294967296.0)) * 0.1) * (DBL_EPSILON))) {
        rtmSetErrorStatus(DroneModel_M, "Simulation finished");
      }

      if (rtmGetStopRequested(DroneModel_M)) {
        rtmSetErrorStatus(DroneModel_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&DroneModel_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++DroneModel_M->Timing.clockTick0)) {
      ++DroneModel_M->Timing.clockTickH0;
    }

    DroneModel_M->Timing.t[0] = rtsiGetSolverStopTime(&DroneModel_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.1s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.1, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      DroneModel_M->Timing.clockTick1++;
      if (!DroneModel_M->Timing.clockTick1) {
        DroneModel_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void DroneModel_derivatives(void)
{
  XDot_DroneModel_T *_rtXdot;
  real_T Subtract;
  real_T Subtract_0;
  real_T Subtract_1;
  real_T Subtract_2;
  int_T is;
  int_T ri;
  _rtXdot = ((XDot_DroneModel_T *) DroneModel_M->derivs);

  /* Derivatives for StateSpace: '<S2>/State-Space' incorporates:
   *  Sum: '<S3>/Subtract'
   */
  memset(&_rtXdot->StateSpace_CSTATE[0], 0, 12U * sizeof(real_T));
  for (is = 0; is < 12; is++) {
    for (ri = 0; ri < 12; ri++) {
      _rtXdot->StateSpace_CSTATE[ri] += DroneModel_P.A[is * 12 + ri] *
        DroneModel_X.StateSpace_CSTATE[is];
    }
  }

  Subtract = DroneModel_B.Subtract[0];
  Subtract_0 = DroneModel_B.Subtract[1];
  Subtract_1 = DroneModel_B.Subtract[2];
  Subtract_2 = DroneModel_B.Subtract[3];
  for (ri = 0; ri < 12; ri++) {
    _rtXdot->StateSpace_CSTATE[ri] = (((DroneModel_P.B[ri] * Subtract +
      _rtXdot->StateSpace_CSTATE[ri]) + DroneModel_P.B[ri + 12] * Subtract_0) +
      DroneModel_P.B[ri + 24] * Subtract_1) + DroneModel_P.B[ri + 36] *
      Subtract_2;
  }

  /* End of Derivatives for StateSpace: '<S2>/State-Space' */
}

/* Model initialize function */
void DroneModel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)DroneModel_M, 0,
                sizeof(RT_MODEL_DroneModel_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&DroneModel_M->solverInfo,
                          &DroneModel_M->Timing.simTimeStep);
    rtsiSetTPtr(&DroneModel_M->solverInfo, &rtmGetTPtr(DroneModel_M));
    rtsiSetStepSizePtr(&DroneModel_M->solverInfo,
                       &DroneModel_M->Timing.stepSize0);
    rtsiSetdXPtr(&DroneModel_M->solverInfo, &DroneModel_M->derivs);
    rtsiSetContStatesPtr(&DroneModel_M->solverInfo, (real_T **)
                         &DroneModel_M->contStates);
    rtsiSetNumContStatesPtr(&DroneModel_M->solverInfo,
      &DroneModel_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&DroneModel_M->solverInfo,
      &DroneModel_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&DroneModel_M->solverInfo,
      &DroneModel_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&DroneModel_M->solverInfo,
      &DroneModel_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&DroneModel_M->solverInfo, (&rtmGetErrorStatus
      (DroneModel_M)));
    rtsiSetRTModelPtr(&DroneModel_M->solverInfo, DroneModel_M);
  }

  rtsiSetSimTimeStep(&DroneModel_M->solverInfo, MAJOR_TIME_STEP);
  DroneModel_M->intgData.y = DroneModel_M->odeY;
  DroneModel_M->intgData.f[0] = DroneModel_M->odeF[0];
  DroneModel_M->intgData.f[1] = DroneModel_M->odeF[1];
  DroneModel_M->intgData.f[2] = DroneModel_M->odeF[2];
  DroneModel_M->contStates = ((X_DroneModel_T *) &DroneModel_X);
  rtsiSetSolverData(&DroneModel_M->solverInfo, (void *)&DroneModel_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&DroneModel_M->solverInfo, false);
  rtsiSetSolverName(&DroneModel_M->solverInfo,"ode3");
  rtmSetTPtr(DroneModel_M, &DroneModel_M->Timing.tArray[0]);
  rtmSetTFinal(DroneModel_M, -1);
  DroneModel_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  DroneModel_M->Sizes.checksums[0] = (2379884857U);
  DroneModel_M->Sizes.checksums[1] = (1494586340U);
  DroneModel_M->Sizes.checksums[2] = (2191468998U);
  DroneModel_M->Sizes.checksums[3] = (2014791328U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    DroneModel_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DroneModel_M->extModeInfo,
      &DroneModel_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DroneModel_M->extModeInfo, DroneModel_M->Sizes.checksums);
    rteiSetTPtr(DroneModel_M->extModeInfo, rtmGetTPtr(DroneModel_M));
  }

  /* block I/O */
  (void) memset(((void *) &DroneModel_B), 0,
                sizeof(B_DroneModel_T));

  /* states (continuous) */
  {
    (void) memset((void *)&DroneModel_X, 0,
                  sizeof(X_DroneModel_T));
  }

  /* states (dwork) */
  (void) memset((void *)&DroneModel_DW, 0,
                sizeof(DW_DroneModel_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    DroneModel_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<S2>/MPU9250' */
  DroneModel_DW.obj.i2cObjmpu.matlabCodegenIsDeleted = true;
  DroneModel_DW.obj.i2cObjak8963.matlabCodegenIsDeleted = true;
  DroneModel_DW.obj.matlabCodegenIsDeleted = true;
  Dro_bbblueMPU9250_bbblueMPU9250(&DroneModel_DW.obj);
  DroneModel_DW.objisempty = true;
  DroneModel_DW.obj.SampleTime = DroneModel_P.MPU9250_SampleTime;
  DroneModel_SystemCore_setup_n(&DroneModel_DW.obj);

  /* Start for MATLABSystem: '<S2>/Barometer' */
  DroneModel_DW.obj_e.i2cObj.matlabCodegenIsDeleted = true;
  DroneModel_DW.obj_e.matlabCodegenIsDeleted = true;
  bbblueBarometer_bbblueBarometer(&DroneModel_DW.obj_e);
  DroneModel_DW.objisempty_o = true;
  DroneModel_DW.obj_e.SampleTime = DroneModel_P.Barometer_SampleTime;
  DroneModel_SystemCore_setup(&DroneModel_DW.obj_e);

  /* InitializeConditions for StateSpace: '<S2>/State-Space' */
  memcpy(&DroneModel_X.StateSpace_CSTATE[0], &DroneModel_P.x0[0], 12U * sizeof
         (real_T));
}

/* Model terminate function */
void DroneModel_terminate(void)
{
  f_beagleboneblue_bbblueI2CMas_T *obj_1;
  h_beagleboneblue_bbblueI2CMas_T *obj_0;
  i_beagleboneblue_bbblueI2CMas_T *obj;

  /* Terminate for MATLABSystem: '<S2>/MPU9250' */
  if (!DroneModel_DW.obj.matlabCodegenIsDeleted) {
    DroneModel_DW.obj.matlabCodegenIsDeleted = true;
  }

  obj = &DroneModel_DW.obj.i2cObjak8963;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  obj_0 = &DroneModel_DW.obj.i2cObjmpu;
  if (!obj_0->matlabCodegenIsDeleted) {
    obj_0->matlabCodegenIsDeleted = true;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/MPU9250' */

  /* Terminate for MATLABSystem: '<S2>/Barometer' */
  if (!DroneModel_DW.obj_e.matlabCodegenIsDeleted) {
    DroneModel_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  obj_1 = &DroneModel_DW.obj_e.i2cObj;
  if (!obj_1->matlabCodegenIsDeleted) {
    obj_1->matlabCodegenIsDeleted = true;
    if (obj_1->isInitialized == 1) {
      obj_1->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Barometer' */
}
