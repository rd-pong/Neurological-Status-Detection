/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_NN_full_api.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 02-Sep-2020 17:13:45
 */

#ifndef _CODER_NN_FULL_API_H
#define _CODER_NN_FULL_API_H

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
extern void NN_full(real_T input_data[28], real_T Y[4]);
extern void NN_full_api(const mxArray * const prhs[1], int32_T nlhs, const
  mxArray *plhs[1]);
extern void NN_full_atexit(void);
extern void NN_full_initialize(void);
extern void NN_full_terminate(void);
extern void NN_full_xil_shutdown(void);
extern void NN_full_xil_terminate(void);

#endif

/*
 * File trailer for _coder_NN_full_api.h
 *
 * [EOF]
 */
