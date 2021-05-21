/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: RF_full.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 20:59:21
 */

/* Include Files */
#include "RF_full.h"
#include "CompactEnsemble.h"
#include "RF_full_data.h"
#include "RF_full_initialize.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const double input_data[28]
 *                double *label
 *                double score[4]
 * Return Type  : void
 */
void RF_full(const double input_data[28], double *label, double score[4])
{
  int i;
  double dv[4];
  bool RF_IsCached[30];
  bool b[4];
  bool notNaN;
  bool exitg1;
  double classnum;
  int idx;
  int b_i;
  double d;
  if (isInitialized_RF_full == false) {
    RF_full_initialize();
  }

  for (i = 0; i < 30; i++) {
    RF_IsCached[i] = false;
  }

  dv[0] = 0.0;
  dv[1] = 1.0;
  dv[2] = 2.0;
  dv[3] = 3.0;
  CompactEnsemble_ensemblePredict(RF_IsCached, input_data, dv, score);
  b[0] = rtIsNaN(score[0]);
  b[1] = rtIsNaN(score[1]);
  b[2] = rtIsNaN(score[2]);
  b[3] = rtIsNaN(score[3]);
  notNaN = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 4)) {
    if (!b[i]) {
      notNaN = false;
      exitg1 = true;
    } else {
      i++;
    }
  }

  notNaN = !notNaN;
  classnum = rtNaN;
  if (notNaN) {
    if (!rtIsNaN(score[0])) {
      idx = 1;
    } else {
      idx = 0;
      i = 2;
      exitg1 = false;
      while ((!exitg1) && (i < 5)) {
        if (!rtIsNaN(score[i - 1])) {
          idx = i;
          exitg1 = true;
        } else {
          i++;
        }
      }
    }

    if (idx == 0) {
      idx = 1;
    } else {
      classnum = score[idx - 1];
      b_i = idx + 1;
      for (i = b_i; i < 5; i++) {
        d = score[i - 1];
        if (classnum < d) {
          classnum = d;
          idx = i;
        }
      }
    }

    classnum = idx;
  }

  *label = 0.0;
  if (notNaN) {
    if (classnum < 4.294967296E+9) {
      b_i = (int)classnum;
    } else {
      b_i = 0;
    }

    *label = (double)b_i - 1.0;
  }
}

/*
 * File trailer for RF_full.c
 *
 * [EOF]
 */
