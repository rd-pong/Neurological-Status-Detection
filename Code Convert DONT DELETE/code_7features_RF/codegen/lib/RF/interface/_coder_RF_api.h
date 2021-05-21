/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_RF_api.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 10:01:49
 */

#ifndef _CODER_RF_API_H
#define _CODER_RF_API_H

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
extern void RF(real_T input_data[7], real_T *label, real_T score[4]);
extern void RF_api(const mxArray * const prhs[1], int32_T nlhs, const mxArray
                   *plhs[2]);
extern void RF_atexit(void);
extern void RF_initialize(void);
extern void RF_terminate(void);
extern void RF_xil_shutdown(void);
extern void RF_xil_terminate(void);

#endif

/*
 * File trailer for _coder_RF_api.h
 *
 * [EOF]
 */
