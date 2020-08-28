/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: td_analysis.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 11:34:10
 */

#ifndef TD_ANALYSIS_H
#define TD_ANALYSIS_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "feature_extract_types.h"

/* Function Declarations */
extern void b_td_analysis(const double s[6], double *frame_mean, double
  *frame_max, double *frame_min, double *frame_change);
extern void td_analysis(const double s[48], double *frame_mean, double
  *frame_max, double *frame_min, double *frame_change);

#endif

/*
 * File trailer for td_analysis.h
 *
 * [EOF]
 */
