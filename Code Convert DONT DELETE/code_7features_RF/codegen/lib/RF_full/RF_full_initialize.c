/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: RF_full_initialize.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 09:51:20
 */

/* Include Files */
#include "RF_full_initialize.h"
#include "RF_full.h"
#include "RF_full_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void RF_full_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_RF_full = true;
}

/*
 * File trailer for RF_full_initialize.c
 *
 * [EOF]
 */
