/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: repmat.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 06-May-2021 23:36:41
 */

/* Include Files */
#include "repmat.h"
#include "kNN.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const double a_data[]
 *                const int a_size[2]
 *                double varargin_1
 *                double b_data[]
 *                int b_size[2]
 * Return Type  : void
 */
void b_repmat(const double a_data[], const int a_size[2], double varargin_1,
              double b_data[], int b_size[2])
{
  int i;
  int ncols;
  int jcol;
  int ibmat;
  i = (int)varargin_1;
  b_size[0] = (signed char)i;
  b_size[1] = (signed char)a_size[1];
  ncols = a_size[1];
  for (jcol = 0; jcol < ncols; jcol++) {
    ibmat = jcol * i;
    if (0 <= i - 1) {
      b_data[ibmat] = a_data[jcol];
    }
  }
}

/*
 * Arguments    : const double a_data[]
 *                const int a_size[2]
 *                double b_data[]
 *                int b_size[2]
 * Return Type  : void
 */
void repmat(const double a_data[], const int a_size[2], double b_data[], int
            b_size[2])
{
  int ncols;
  b_size[0] = 1;
  b_size[1] = (signed char)a_size[1];
  ncols = a_size[1];
  if (0 <= ncols - 1) {
    memcpy(&b_data[0], &a_data[0], ncols * sizeof(double));
  }
}

/*
 * File trailer for repmat.c
 *
 * [EOF]
 */
