/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SVM_full_initialize.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 22:51:15
 */

/* Include Files */
#include "SVM_full_initialize.h"
#include "SVM_full.h"
#include "SVM_full_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void SVM_full_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_SVM_full = true;
}

/*
 * File trailer for SVM_full_initialize.c
 *
 * [EOF]
 */
