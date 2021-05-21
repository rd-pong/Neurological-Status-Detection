/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Gaussian.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 08:51:25
 */

#ifndef GAUSSIAN_H
#define GAUSSIAN_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "SVM_types.h"

/* Function Declarations */
extern void Gaussian(const emxArray_real_T *svT, const double
                     svInnerProduct_data[], const int svInnerProduct_size[2],
                     const double x[7], double kernelProduct_data[], int
                     kernelProduct_size[2]);

#endif

/*
 * File trailer for Gaussian.h
 *
 * [EOF]
 */
