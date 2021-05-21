/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SVM_terminate.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 08:53:12
 */

/* Include Files */
#include "SVM_terminate.h"
#include "SVM.h"
#include "SVM_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void SVM_terminate(void)
{
  /* (no terminate code required) */
  isInitialized_SVM = false;
}

/*
 * File trailer for SVM_terminate.c
 *
 * [EOF]
 */
