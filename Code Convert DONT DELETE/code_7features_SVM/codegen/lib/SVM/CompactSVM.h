/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactSVM.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 08:53:12
 */

#ifndef COMPACTSVM_H
#define COMPACTSVM_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "SVM_types.h"

/* Function Declarations */
extern double CompactSVM_kernelScore(const double obj_Alpha_data[], double
  obj_Bias, const emxArray_real_T *obj_SupportVectorsT, const double X[7]);

#endif

/*
 * File trailer for CompactSVM.h
 *
 * [EOF]
 */
