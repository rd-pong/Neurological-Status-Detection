/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: bsxfun.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 06-May-2021 23:36:41
 */

/* Include Files */
#include "bsxfun.h"
#include "kNN.h"
#include "kNN_emxutil.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *a
 *                const double b[7]
 *                emxArray_real_T *c
 * Return Type  : void
 */
void bsxfun(const emxArray_real_T *a, const double b[7], emxArray_real_T *c)
{
  int i;
  int acoef;
  int k;
  int b_k;
  i = c->size[0] * c->size[1];
  c->size[0] = (short)a->size[0];
  c->size[1] = 7;
  emxEnsureCapacity_real_T(c, i);
  if ((short)a->size[0] != 0) {
    acoef = (a->size[0] != 1);
    for (k = 0; k < 7; k++) {
      i = c->size[0] - 1;
      for (b_k = 0; b_k <= i; b_k++) {
        c->data[b_k + c->size[0] * k] = a->data[acoef * b_k + a->size[0] * k] -
          b[k];
      }
    }
  }
}

/*
 * File trailer for bsxfun.c
 *
 * [EOF]
 */
