/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactSVM.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 08:51:25
 */

/* Include Files */
#include "CompactSVM.h"
#include "Gaussian.h"
#include "SVM.h"
#include "SVM_emxutil.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const double obj_Alpha_data[]
 *                double obj_Bias
 *                const emxArray_real_T *obj_SupportVectorsT
 *                const double X[7]
 * Return Type  : double
 */
double CompactSVM_kernelScore(const double obj_Alpha_data[], double obj_Bias,
  const emxArray_real_T *obj_SupportVectorsT, const double X[7])
{
  emxArray_real_T *svT;
  int npages;
  int i2;
  int c_size[2];
  int ic;
  int i;
  int i1;
  double c_data[2361];
  double b_X[7];
  double tmp_data[2361];
  int tmp_size[2];
  double c;
  int iy;
  int k;
  emxInit_real_T(&svT, 2);
  npages = svT->size[0] * svT->size[1];
  svT->size[0] = 7;
  svT->size[1] = obj_SupportVectorsT->size[1];
  emxEnsureCapacity_real_T(svT, npages);
  i2 = obj_SupportVectorsT->size[0] * obj_SupportVectorsT->size[1];
  for (npages = 0; npages < i2; npages++) {
    svT->data[npages] = obj_SupportVectorsT->data[npages] / 0.66;
  }

  c_size[0] = 1;
  c_size[1] = (short)svT->size[1];
  npages = svT->size[1];
  i2 = 1;
  ic = -1;
  for (i = 0; i < npages; i++) {
    i1 = i2 - 1;
    ic++;
    i2 += 7;
    iy = i1;
    c = 0.0;
    for (k = 0; k < 7; k++) {
      c += svT->data[i1] * svT->data[iy];
      i1++;
      iy++;
    }

    c_data[ic] = c;
  }

  for (npages = 0; npages < 7; npages++) {
    b_X[npages] = X[npages] / 0.66;
  }

  Gaussian(svT, c_data, c_size, b_X, tmp_data, tmp_size);
  c = 0.0;
  i2 = tmp_size[1];
  emxFree_real_T(&svT);
  for (npages = 0; npages < i2; npages++) {
    c += tmp_data[npages] * obj_Alpha_data[npages];
  }

  return c + obj_Bias;
}

/*
 * File trailer for CompactSVM.c
 *
 * [EOF]
 */
