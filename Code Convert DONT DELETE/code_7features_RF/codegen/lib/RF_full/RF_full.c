/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: RF_full.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 09:51:20
 */

/* Include Files */
#include "RF_full.h"
#include "CompactEnsemble.h"
#include "RF_full_data.h"
#include "RF_full_initialize.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const double input_data[7]
 *                double *label
 *                double score[4]
 * Return Type  : void
 */
void RF_full(const double input_data[7], double *label, double score[4])
{
  double dv[4];
  bool b[4];
  bool notNaN;
  int k;
  bool exitg1;
  double classnum;
  int idx;
  int i;
  double d;
  if (isInitialized_RF_full == false) {
    RF_full_initialize();
  }

  dv[0] = 0.0;
  dv[1] = 1.0;
  dv[2] = 2.0;
  dv[3] = 3.0;
  CompactEnsemble_ensemblePredict(input_data, dv, score);
  b[0] = rtIsNaN(score[0]);
  b[1] = rtIsNaN(score[1]);
  b[2] = rtIsNaN(score[2]);
  b[3] = rtIsNaN(score[3]);
  notNaN = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    if (!b[k]) {
      notNaN = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  notNaN = !notNaN;
  classnum = rtNaN;
  if (notNaN) {
    if (!rtIsNaN(score[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 5)) {
        if (!rtIsNaN(score[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      idx = 1;
    } else {
      classnum = score[idx - 1];
      i = idx + 1;
      for (k = i; k < 5; k++) {
        d = score[k - 1];
        if (classnum < d) {
          classnum = d;
          idx = k;
        }
      }
    }

    classnum = idx;
  }

  *label = 0.0;
  if (notNaN) {
    if (classnum < 4.294967296E+9) {
      i = (int)classnum;
    } else {
      i = 0;
    }

    *label = (double)i - 1.0;
  }
}

/*
 * File trailer for RF_full.c
 *
 * [EOF]
 */
