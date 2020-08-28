/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortIdx.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 15:49:21
 */

#ifndef SORTIDX_H
#define SORTIDX_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "RF_full_types.h"

/* Function Declarations */
extern void merge_block(int idx[14497], double x[14497], int offset, int n, int
  preSortLevel, int iwork[14497], double xwork[14497]);
extern void merge_pow2_block(int idx[14497], double x[14497], int offset);

#endif

/*
 * File trailer for sortIdx.h
 *
 * [EOF]
 */
