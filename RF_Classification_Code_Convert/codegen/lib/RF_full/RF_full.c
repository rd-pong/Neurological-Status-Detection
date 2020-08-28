/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: RF_full.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 15:49:21
 */

/* Include Files */
#include "RF_full.h"
#include "ClassificationKNN.h"
#include "RF_full_data.h"
#include "RF_full_initialize.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const double input_data[28]
 *                double *label
 *                double score[4]
 * Return Type  : void
 */
void RF_full(const double input_data[28], double *label, double score[4])
{
  static c_classreg_learning_coder_class expl_temp;
  double RF_ClassNames[4];
  double RF_Prior[4];
  double RF_Cost[16];
  static double RF_X[405916];
  static unsigned int RF_YIdx[14497];
  static double RF_W[14497];
  int k;
  double Xin[28];
  bool notNaN;
  int i;
  int idx;
  double cost[4];
  bool exitg1;
  double ex;
  double d;
  int classnum;
  if (isInitialized_RF_full == false) {
    RF_full_initialize();
  }

  c_ClassificationKNN_Classificat(&expl_temp);
  RF_ClassNames[0] = expl_temp.ClassNames[0];
  RF_Prior[0] = expl_temp.Prior[0];
  RF_ClassNames[1] = expl_temp.ClassNames[1];
  RF_Prior[1] = expl_temp.Prior[1];
  RF_ClassNames[2] = expl_temp.ClassNames[2];
  RF_Prior[2] = expl_temp.Prior[2];
  RF_ClassNames[3] = expl_temp.ClassNames[3];
  RF_Prior[3] = expl_temp.Prior[3];
  memcpy(&RF_Cost[0], &expl_temp.Cost[0], 16U * sizeof(double));
  memcpy(&RF_X[0], &expl_temp.X[0], 405916U * sizeof(double));
  memcpy(&RF_YIdx[0], &expl_temp.YIdx[0], 14497U * sizeof(unsigned int));
  memcpy(&RF_W[0], &expl_temp.W[0], 14497U * sizeof(double));
  for (k = 0; k < 28; k++) {
    Xin[k] = (input_data[k] - expl_temp.Mu[k]) / expl_temp.Sigma[k];
  }

  ClassificationKNN_score(RF_X, RF_YIdx, RF_W, Xin, score, &notNaN);
  for (i = 0; i < 4; i++) {
    k = i << 2;
    cost[i] = ((score[0] * RF_Cost[k] + score[1] * RF_Cost[k + 1]) + score[2] *
               RF_Cost[k + 2]) + score[3] * RF_Cost[k + 3];
  }

  if (!rtIsNaN(expl_temp.Prior[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!rtIsNaN(RF_Prior[k - 1])) {
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
    ex = RF_Prior[idx - 1];
    i = idx + 1;
    for (k = i; k < 5; k++) {
      d = RF_Prior[k - 1];
      if (ex < d) {
        ex = d;
        idx = k;
      }
    }
  }

  if (notNaN) {
    if (!rtIsNaN(cost[0])) {
      classnum = 1;
    } else {
      classnum = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 5)) {
        if (!rtIsNaN(cost[k - 1])) {
          classnum = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (classnum == 0) {
      classnum = 1;
    } else {
      ex = cost[classnum - 1];
      i = classnum + 1;
      for (k = i; k < 5; k++) {
        d = cost[k - 1];
        if (ex > d) {
          ex = d;
          classnum = k;
        }
      }
    }
  }

  *label = RF_ClassNames[idx - 1];
  if (notNaN) {
    *label = RF_ClassNames[classnum - 1];
  }
}

/*
 * File trailer for RF_full.c
 *
 * [EOF]
 */
