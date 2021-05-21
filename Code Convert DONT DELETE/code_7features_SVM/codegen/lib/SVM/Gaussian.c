/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Gaussian.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 08:53:12
 */

/* Include Files */
#include "Gaussian.h"
#include "SVM.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *svT
 *                const double svInnerProduct_data[]
 *                const int svInnerProduct_size[2]
 *                const double x[7]
 *                double kernelProduct_data[]
 *                int kernelProduct_size[2]
 * Return Type  : void
 */
void Gaussian(const emxArray_real_T *svT, const double svInnerProduct_data[],
              const int svInnerProduct_size[2], const double x[7], double
              kernelProduct_data[], int kernelProduct_size[2])
{
  int j;
  int n;
  double y[7];
  int y_size_idx_1;
  double b_x;
  int boffset;
  int k;
  double y_data[2361];
  double c_data[2361];
  for (j = 0; j < 7; j++) {
    y[j] = -2.0 * x[j];
  }

  n = svT->size[1];
  y_size_idx_1 = svT->size[1];
  for (j = 0; j < n; j++) {
    boffset = j * 7;
    b_x = 0.0;
    for (k = 0; k < 7; k++) {
      b_x += svT->data[boffset + k] * y[k];
    }

    y_data[j] = b_x;
  }

  b_x = 0.0;
  for (j = 0; j < 7; j++) {
    b_x += x[j] * x[j];
  }

  n = (short)y_size_idx_1;
  j = (short)y_size_idx_1 - 1;
  for (k = 0; k <= j; k++) {
    c_data[k] = y_data[k] + b_x;
  }

  if (n == svInnerProduct_size[1]) {
    kernelProduct_size[1] = n;
  } else {
    if (svInnerProduct_size[1] < n) {
      kernelProduct_size[1] = (short)svInnerProduct_size[1];
    } else {
      kernelProduct_size[1] = n;
    }

    if (svInnerProduct_size[1] < n) {
      n = (short)svInnerProduct_size[1];
    }
  }

  j = n - 1;
  for (k = 0; k <= j; k++) {
    kernelProduct_data[k] = c_data[k] + svInnerProduct_data[k];
  }

  kernelProduct_size[0] = 1;
  n = kernelProduct_size[1] - 1;
  for (j = 0; j <= n; j++) {
    kernelProduct_data[j] = -kernelProduct_data[j];
  }

  n = kernelProduct_size[1];
  for (k = 0; k < n; k++) {
    kernelProduct_data[k] = exp(kernelProduct_data[k]);
  }
}

/*
 * File trailer for Gaussian.c
 *
 * [EOF]
 */
