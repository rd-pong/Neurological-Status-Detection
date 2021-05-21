/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_kNN_api.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 06-May-2021 23:36:41
 */

#ifndef _CODER_KNN_API_H
#define _CODER_KNN_API_H

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
extern void kNN(real_T input_data[7], real_T *label, real_T score[4]);
extern void kNN_api(const mxArray * const prhs[1], int32_T nlhs, const mxArray
                    *plhs[2]);
extern void kNN_atexit(void);
extern void kNN_initialize(void);
extern void kNN_terminate(void);
extern void kNN_xil_shutdown(void);
extern void kNN_xil_terminate(void);

#endif

/*
 * File trailer for _coder_kNN_api.h
 *
 * [EOF]
 */
