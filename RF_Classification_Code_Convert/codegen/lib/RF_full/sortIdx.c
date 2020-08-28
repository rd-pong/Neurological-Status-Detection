/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortIdx.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 15:49:21
 */

/* Include Files */
#include "sortIdx.h"
#include "RF_full.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void merge(int idx[14497], double x[14497], int offset, int np, int nq,
                  int iwork[14497], double xwork[14497]);

/* Function Definitions */

/*
 * Arguments    : int idx[14497]
 *                double x[14497]
 *                int offset
 *                int np
 *                int nq
 *                int iwork[14497]
 *                double xwork[14497]
 * Return Type  : void
 */
static void merge(int idx[14497], double x[14497], int offset, int np, int nq,
                  int iwork[14497], double xwork[14497])
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
      iwork[iout] = idx[i];
      xwork[iout] = x[i];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] <= xwork[q]) {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          for (iout = p + 1; iout <= np; iout++) {
            i = q + iout;
            idx[i] = iwork[iout - 1];
            x[i] = xwork[iout - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/*
 * Arguments    : int idx[14497]
 *                double x[14497]
 *                int offset
 *                int n
 *                int preSortLevel
 *                int iwork[14497]
 *                double xwork[14497]
 * Return Type  : void
 */
void merge_block(int idx[14497], double x[14497], int offset, int n, int
                 preSortLevel, int iwork[14497], double xwork[14497])
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
        merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      merge(idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

/*
 * Arguments    : int idx[14497]
 *                double x[14497]
 *                int offset
 * Return Type  : void
 */
void merge_pow2_block(int idx[14497], double x[14497], int offset)
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
        iwork[j] = idx[iout];
        xwork[j] = x[iout];
      }

      p = 0;
      q = bLen;
      iout = blockOffset - 1;
      do {
        exitg1 = 0;
        iout++;
        if (xwork[p] <= xwork[q]) {
          idx[iout] = iwork[p];
          x[iout] = xwork[p];
          if (p + 1 < bLen) {
            p++;
          } else {
            exitg1 = 1;
          }
        } else {
          idx[iout] = iwork[q];
          x[iout] = xwork[q];
          if (q + 1 < bLen2) {
            q++;
          } else {
            iout -= p;
            for (j = p + 1; j <= bLen; j++) {
              q = iout + j;
              idx[q] = iwork[j - 1];
              x[q] = xwork[j - 1];
            }

            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    }
  }
}

/*
 * File trailer for sortIdx.c
 *
 * [EOF]
 */
