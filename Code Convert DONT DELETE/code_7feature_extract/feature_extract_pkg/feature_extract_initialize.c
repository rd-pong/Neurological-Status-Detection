/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: feature_extract_initialize.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 00:58:57
 */

/* Include Files */
#include "feature_extract_initialize.h"
#include "feature_extract.h"
#include "feature_extract_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void feature_extract_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_feature_extract = true;
}

/*
 * File trailer for feature_extract_initialize.c
 *
 * [EOF]
 */
