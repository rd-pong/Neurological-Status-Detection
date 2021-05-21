/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_SVM_full_api.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 22:51:15
 */

#ifndef _CODER_SVM_FULL_API_H
#define _CODER_SVM_FULL_API_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void SVM_full(real_T input_data[28], real_T *label, real_T score[4]);
extern void SVM_full_api(const mxArray * const prhs[1], int32_T nlhs, const
  mxArray *plhs[2]);
extern void SVM_full_atexit(void);
extern void SVM_full_initialize(void);
extern void SVM_full_terminate(void);
extern void SVM_full_xil_shutdown(void);
extern void SVM_full_xil_terminate(void);

#endif

/*
 * File trailer for _coder_SVM_full_api.h
 *
 * [EOF]
 */
