/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortIdx.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 06-May-2021 23:36:41
 */

/* Include Files */
#include "sortIdx.h"
#include "kNN.h"
#include "kNN_emxutil.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static void merge(int idx_data[], emxArray_real_T *x, int offset, int np, int nq,
                  int iwork_data[], emxArray_real_T *xwork);
static void merge_block(int idx_data[], emxArray_real_T *x, int offset, int n,
  int preSortLevel, int iwork_data[], emxArray_real_T *xwork);
static void merge_pow2_block(int idx_data[], emxArray_real_T *x, int offset);

/* Function Definitions */

/*
 * Arguments    : int idx_data[]
 *                emxArray_real_T *x
 *                int offset
 *                int np
 *                int nq
 *                int iwork_data[]
 *                emxArray_real_T *xwork
 * Return Type  : void
 */
static void merge(int idx_data[], emxArray_real_T *x, int offset, int np, int nq,
                  int iwork_data[], emxArray_real_T *xwork)
{
  int n_tmp;
  int iout;
  int p;
  int i;
  int q;
  int exitg1;
  if (nq != 0) {
    n_tmp = np + nq;
    for (iout = 0; iout < n_tmp; iout++) {
      i = offset + iout;
      iwork_data[iout] = idx_data[i];
      xwork->data[iout] = x->data[i];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork->data[p] <= xwork->data[q]) {
        idx_data[iout] = iwork_data[p];
        x->data[iout] = xwork->data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x->data[iout] = xwork->data[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          for (iout = p + 1; iout <= np; iout++) {
            i = q + iout;
            idx_data[i] = iwork_data[iout - 1];
            x->data[i] = xwork->data[iout - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/*
 * Arguments    : int idx_data[]
 *                emxArray_real_T *x
 *                int offset
 *                int n
 *                int preSortLevel
 *                int iwork_data[]
 *                emxArray_real_T *xwork
 * Return Type  : void
 */
static void merge_block(int idx_data[], emxArray_real_T *x, int offset, int n,
  int preSortLevel, int iwork_data[], emxArray_real_T *xwork)
{
  int nPairs;
  int bLen;
  int tailOffset;
  int nTail;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        merge(idx_data, x, offset + tailOffset, bLen, nTail - bLen, iwork_data,
              xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      merge(idx_data, x, offset + nTail * tailOffset, bLen, bLen, iwork_data,
            xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    merge(idx_data, x, offset, bLen, n - bLen, iwork_data, xwork);
  }
}

/*
 * Arguments    : int idx_data[]
 *                emxArray_real_T *x
 *                int offset
 * Return Type  : void
 */
static void merge_pow2_block(int idx_data[], emxArray_real_T *x, int offset)
{
  int b;
  int bLen;
  int bLen2;
  int nPairs;
  int k;
  int blockOffset;
  int j;
  int p;
  int iout;
  int q;
  int iwork[256];
  double xwork[256];
  int exitg1;
  for (b = 0; b < 6; b++) {
    bLen = 1 << (b + 2);
    bLen2 = bLen << 1;
    nPairs = 256 >> (b + 3);
    for (k = 0; k < nPairs; k++) {
      blockOffset = offset + k * bLen2;
      for (j = 0; j < bLen2; j++) {
        iout = blockOffset + j;
        iwork[j] = idx_data[iout];
        xwork[j] = x->data[iout];
      }

      p = 0;
      q = bLen;
      iout = blockOffset - 1;
      do {
        exitg1 = 0;
        iout++;
        if (xwork[p] <= xwork[q]) {
          idx_data[iout] = iwork[p];
          x->data[iout] = xwork[p];
          if (p + 1 < bLen) {
            p++;
          } else {
            exitg1 = 1;
          }
        } else {
          idx_data[iout] = iwork[q];
          x->data[iout] = xwork[q];
          if (q + 1 < bLen2) {
            q++;
          } else {
            iout -= p;
            for (j = p + 1; j <= bLen; j++) {
              q = iout + j;
              idx_data[q] = iwork[j - 1];
              x->data[q] = xwork[j - 1];
            }

            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    }
  }
}

/*
 * Arguments    : emxArray_real_T *x
 *                int idx_data[]
 *                int idx_size[1]
 * Return Type  : void
 */
void sortIdx(emxArray_real_T *x, int idx_data[], int idx_size[1])
{
  short unnamed_idx_0;
  int ib;
  int n;
  int b_n;
  double x4[4];
  short idx4[4];
  int iwork_data[14497];
  emxArray_real_T *xwork;
  int i1;
  int nNaNs;
  int k;
  int i4;
  int idx_tmp;
  signed char perm[4];
  int quartetOffset;
  int i2;
  double d;
  double d1;
  unnamed_idx_0 = (short)x->size[0];
  idx_size[0] = unnamed_idx_0;
  ib = unnamed_idx_0;
  if (0 <= ib - 1) {
    memset(&idx_data[0], 0, ib * sizeof(int));
  }

  if (x->size[0] != 0) {
    n = x->size[0];
    b_n = x->size[0];
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    ib = unnamed_idx_0;
    if (0 <= ib - 1) {
      memset(&iwork_data[0], 0, ib * sizeof(int));
    }

    emxInit_real_T(&xwork, 1);
    i1 = xwork->size[0];
    xwork->size[0] = x->size[0];
    emxEnsureCapacity_real_T(xwork, i1);
    ib = xwork->size[0];
    for (i1 = 0; i1 < ib; i1++) {
      xwork->data[i1] = 0.0;
    }

    nNaNs = 0;
    ib = -1;
    for (k = 0; k < b_n; k++) {
      if (rtIsNaN(x->data[k])) {
        idx_tmp = (b_n - nNaNs) - 1;
        idx_data[idx_tmp] = k + 1;
        xwork->data[idx_tmp] = x->data[k];
        nNaNs++;
      } else {
        ib++;
        idx4[ib] = (short)(k + 1);
        x4[ib] = x->data[k];
        if (ib + 1 == 4) {
          quartetOffset = k - nNaNs;
          if (x4[0] <= x4[1]) {
            i1 = 1;
            i2 = 2;
          } else {
            i1 = 2;
            i2 = 1;
          }

          if (x4[2] <= x4[3]) {
            ib = 3;
            i4 = 4;
          } else {
            ib = 4;
            i4 = 3;
          }

          d = x4[i1 - 1];
          d1 = x4[ib - 1];
          if (d <= d1) {
            d = x4[i2 - 1];
            if (d <= d1) {
              perm[0] = (signed char)i1;
              perm[1] = (signed char)i2;
              perm[2] = (signed char)ib;
              perm[3] = (signed char)i4;
            } else if (d <= x4[i4 - 1]) {
              perm[0] = (signed char)i1;
              perm[1] = (signed char)ib;
              perm[2] = (signed char)i2;
              perm[3] = (signed char)i4;
            } else {
              perm[0] = (signed char)i1;
              perm[1] = (signed char)ib;
              perm[2] = (signed char)i4;
              perm[3] = (signed char)i2;
            }
          } else {
            d1 = x4[i4 - 1];
            if (d <= d1) {
              if (x4[i2 - 1] <= d1) {
                perm[0] = (signed char)ib;
                perm[1] = (signed char)i1;
                perm[2] = (signed char)i2;
                perm[3] = (signed char)i4;
              } else {
                perm[0] = (signed char)ib;
                perm[1] = (signed char)i1;
                perm[2] = (signed char)i4;
                perm[3] = (signed char)i2;
              }
            } else {
              perm[0] = (signed char)ib;
              perm[1] = (signed char)i4;
              perm[2] = (signed char)i1;
              perm[3] = (signed char)i2;
            }
          }

          idx_tmp = perm[0] - 1;
          idx_data[quartetOffset - 3] = idx4[idx_tmp];
          i2 = perm[1] - 1;
          idx_data[quartetOffset - 2] = idx4[i2];
          ib = perm[2] - 1;
          idx_data[quartetOffset - 1] = idx4[ib];
          i1 = perm[3] - 1;
          idx_data[quartetOffset] = idx4[i1];
          x->data[quartetOffset - 3] = x4[idx_tmp];
          x->data[quartetOffset - 2] = x4[i2];
          x->data[quartetOffset - 1] = x4[ib];
          x->data[quartetOffset] = x4[i1];
          ib = -1;
        }
      }
    }

    i4 = (b_n - nNaNs) - 1;
    if (ib + 1 > 0) {
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (ib + 1 == 1) {
        perm[0] = 1;
      } else if (ib + 1 == 2) {
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

      for (k = 0; k <= ib; k++) {
        idx_tmp = perm[k] - 1;
        i2 = (i4 - ib) + k;
        idx_data[i2] = idx4[idx_tmp];
        x->data[i2] = x4[idx_tmp];
      }
    }

    ib = (nNaNs >> 1) + 1;
    for (k = 0; k <= ib - 2; k++) {
      i1 = (i4 + k) + 1;
      i2 = idx_data[i1];
      idx_tmp = (b_n - k) - 1;
      idx_data[i1] = idx_data[idx_tmp];
      idx_data[idx_tmp] = i2;
      x->data[i1] = xwork->data[idx_tmp];
      x->data[idx_tmp] = xwork->data[i1];
    }

    if ((nNaNs & 1) != 0) {
      i1 = i4 + ib;
      x->data[i1] = xwork->data[i1];
    }

    i2 = n - nNaNs;
    ib = 2;
    if (i2 > 1) {
      if (n >= 256) {
        i1 = i2 >> 8;
        if (i1 > 0) {
          for (ib = 0; ib < i1; ib++) {
            merge_pow2_block(idx_data, x, ib << 8);
          }

          ib = i1 << 8;
          i1 = i2 - ib;
          if (i1 > 0) {
            merge_block(idx_data, x, ib, i1, 2, iwork_data, xwork);
          }

          ib = 8;
        }
      }

      merge_block(idx_data, x, 0, i2, ib, iwork_data, xwork);
    }

    emxFree_real_T(&xwork);
  }
}

/*
 * File trailer for sortIdx.c
 *
 * [EOF]
 */
