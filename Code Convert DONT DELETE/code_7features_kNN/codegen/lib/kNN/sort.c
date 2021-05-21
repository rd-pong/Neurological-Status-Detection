/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sort.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 06-May-2021 23:36:41
 */

/* Include Files */
#include "sort.h"
#include "kNN.h"
#include "kNN_emxutil.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *x
 *                int idx_data[]
 *                int idx_size[1]
 * Return Type  : void
 */
void sort(emxArray_real_T *x, int idx_data[], int idx_size[1])
{
  int dim;
  emxArray_real_T *vwork;
  int i;
  int vlen;
  int j;
  int vstride;
  int k;
  static int iidx_data[14497];
  int iidx_size[1];
  dim = 0;
  if (x->size[0] != 1) {
    dim = -1;
  }

  emxInit_real_T(&vwork, 1);
  if (dim + 2 <= 1) {
    i = x->size[0];
  } else {
    i = 1;
  }

  vlen = i - 1;
  j = vwork->size[0];
  vwork->size[0] = i;
  emxEnsureCapacity_real_T(vwork, j);
  idx_size[0] = x->size[0];
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x->size[0];
  }

  for (j = 0; j < vstride; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork->data[k] = x->data[j + k * vstride];
    }

    sortIdx(vwork, iidx_data, iidx_size);
    for (k = 0; k <= vlen; k++) {
      i = j + k * vstride;
      x->data[i] = vwork->data[k];
      idx_data[i] = iidx_data[k];
    }
  }

  emxFree_real_T(&vwork);
}

/*
 * File trailer for sort.c
 *
 * [EOF]
 */
