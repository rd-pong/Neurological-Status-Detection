/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: kNN_initialize.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 06-May-2021 23:36:41
 */

/* Include Files */
#include "kNN_initialize.h"
#include "kNN.h"
#include "kNN_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void kNN_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_kNN = true;
}

/*
 * File trailer for kNN_initialize.c
 *
 * [EOF]
 */
