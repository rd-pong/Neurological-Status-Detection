/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sort.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 15:49:21
 */

/* Include Files */
#include "sort.h"
#include "RF_full.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : double x[14497]
 *                int idx[14497]
 * Return Type  : void
 */
void sort(double x[14497], int idx[14497])
{
  double x4[4];
  short idx4[4];
  static double xwork[14497];
  int nNaNs;
  int ib;
  int k;
  signed char perm[4];
  int i2;
  int quartetOffset;
  int i3;
  static int iwork[14497];
  int i4;
  double d;
  double d1;
  x4[0] = 0.0;
  idx4[0] = 0;
  x4[1] = 0.0;
  idx4[1] = 0;
  x4[2] = 0.0;
  idx4[2] = 0;
  x4[3] = 0.0;
  idx4[3] = 0;
  memset(&idx[0], 0, 14497U * sizeof(int));
  memset(&xwork[0], 0, 14497U * sizeof(double));
  nNaNs = 0;
  ib = 0;
  for (k = 0; k < 14497; k++) {
    if (rtIsNaN(x[k])) {
      idx[14496 - nNaNs] = k + 1;
      xwork[14496 - nNaNs] = x[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = (short)(k + 1);
      x4[ib - 1] = x[k];
      if (ib == 4) {
        quartetOffset = k - nNaNs;
        if (x4[0] <= x4[1]) {
          ib = 1;
          i2 = 2;
        } else {
          ib = 2;
          i2 = 1;
        }

        if (x4[2] <= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        d = x4[ib - 1];
        d1 = x4[i3 - 1];
        if (d <= d1) {
          d = x4[i2 - 1];
          if (d <= d1) {
            perm[0] = (signed char)ib;
            perm[1] = (signed char)i2;
            perm[2] = (signed char)i3;
            perm[3] = (signed char)i4;
          } else if (d <= x4[i4 - 1]) {
            perm[0] = (signed char)ib;
            perm[1] = (signed char)i3;
            perm[2] = (signed char)i2;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)ib;
            perm[1] = (signed char)i3;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)i2;
          }
        } else {
          d1 = x4[i4 - 1];
          if (d <= d1) {
            if (x4[i2 - 1] <= d1) {
              perm[0] = (signed char)i3;
              perm[1] = (signed char)ib;
              perm[2] = (signed char)i2;
              perm[3] = (signed char)i4;
            } else {
              perm[0] = (signed char)i3;
              perm[1] = (signed char)ib;
              perm[2] = (signed char)i4;
              perm[3] = (signed char)i2;
            }
          } else {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)i4;
            perm[2] = (signed char)ib;
            perm[3] = (signed char)i2;
          }
        }

        i3 = perm[0] - 1;
        idx[quartetOffset - 3] = idx4[i3];
        i4 = perm[1] - 1;
        idx[quartetOffset - 2] = idx4[i4];
        ib = perm[2] - 1;
        idx[quartetOffset - 1] = idx4[ib];
        i2 = perm[3] - 1;
        idx[quartetOffset] = idx4[i2];
        x[quartetOffset - 3] = x4[i3];
        x[quartetOffset - 2] = x4[i4];
        x[quartetOffset - 1] = x4[ib];
        x[quartetOffset] = x4[i2];
        ib = 0;
      }
    }
  }

  if (ib > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] <= x4[1]) {
      if (x4[1] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    for (k = 0; k < ib; k++) {
      i3 = perm[k] - 1;
      i4 = ((k - nNaNs) - ib) + 14497;
      idx[i4] = idx4[i3];
      x[i4] = x4[i3];
    }
  }

  i2 = (nNaNs >> 1) + 14497;
  for (k = 0; k <= i2 - 14498; k++) {
    ib = (k - nNaNs) + 14497;
    i3 = idx[ib];
    idx[ib] = idx[14496 - k];
    idx[14496 - k] = i3;
    x[ib] = xwork[14496 - k];
    x[14496 - k] = xwork[ib];
  }

  if ((nNaNs & 1) != 0) {
    ib = i2 - nNaNs;
    x[ib] = xwork[ib];
  }

  memset(&iwork[0], 0, 14497U * sizeof(int));
  ib = 2;
  if (14497 - nNaNs > 1) {
    i2 = (14497 - nNaNs) >> 8;
    if (i2 > 0) {
      for (ib = 0; ib < i2; ib++) {
        merge_pow2_block(idx, x, ib << 8);
      }

      ib = i2 << 8;
      i2 = 14497 - (nNaNs + ib);
      if (i2 > 0) {
        merge_block(idx, x, ib, i2, 2, iwork, xwork);
      }

      ib = 8;
    }

    merge_block(idx, x, 0, 14497 - nNaNs, ib, iwork, xwork);
  }
}

/*
 * File trailer for sort.c
 *
 * [EOF]
 */
