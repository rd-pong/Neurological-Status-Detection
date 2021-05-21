/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: RF_initialize.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 10:01:49
 */

/* Include Files */
#include "RF_initialize.h"
#include "RF.h"
#include "RF_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void RF_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_RF = true;
}

/*
 * File trailer for RF_initialize.c
 *
 * [EOF]
 */
