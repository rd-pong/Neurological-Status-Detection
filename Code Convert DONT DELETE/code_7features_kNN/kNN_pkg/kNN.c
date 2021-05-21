/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: kNN.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 06-May-2021 23:36:41
 */

/* Include Files */
#include "kNN.h"
#include "ClassificationKNN.h"
#include "kNN_data.h"
#include "kNN_initialize.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const double input_data[7]
 *                double *label
 *                double score[4]
 * Return Type  : void
 */
void kNN(const double input_data[7], double *label, double score[4])
{
  static c_classreg_learning_coder_class expl_temp;
  double kNN_ClassNames[4];
  double kNN_Prior[4];
  double kNN_Cost[16];
  static double kNN_X[101479];
  static unsigned int kNN_YIdx[14497];
  static double kNN_W[14497];
  int k;
  double Xin[7];
  bool notNaN;
  int i;
  int idx;
  double cost[4];
  bool exitg1;
  double ex;
  double d;
  int classnum;
  if (isInitialized_kNN == false) {
    kNN_initialize();
  }

  c_ClassificationKNN_Classificat(&expl_temp);
  kNN_ClassNames[0] = expl_temp.ClassNames[0];
  kNN_Prior[0] = expl_temp.Prior[0];
  kNN_ClassNames[1] = expl_temp.ClassNames[1];
  kNN_Prior[1] = expl_temp.Prior[1];
  kNN_ClassNames[2] = expl_temp.ClassNames[2];
  kNN_Prior[2] = expl_temp.Prior[2];
  kNN_ClassNames[3] = expl_temp.ClassNames[3];
  kNN_Prior[3] = expl_temp.Prior[3];
  memcpy(&kNN_Cost[0], &expl_temp.Cost[0], 16U * sizeof(double));
  memcpy(&kNN_X[0], &expl_temp.X[0], 101479U * sizeof(double));
  memcpy(&kNN_YIdx[0], &expl_temp.YIdx[0], 14497U * sizeof(unsigned int));
  memcpy(&kNN_W[0], &expl_temp.W[0], 14497U * sizeof(double));
  for (k = 0; k < 7; k++) {
    Xin[k] = (input_data[k] - expl_temp.Mu[k]) / expl_temp.Sigma[k];
  }

  ClassificationKNN_score(kNN_X, kNN_YIdx, kNN_W, Xin, score, &notNaN);
  for (i = 0; i < 4; i++) {
    k = i << 2;
    cost[i] = ((score[0] * kNN_Cost[k] + score[1] * kNN_Cost[k + 1]) + score[2] *
               kNN_Cost[k + 2]) + score[3] * kNN_Cost[k + 3];
  }

  if (!rtIsNaN(expl_temp.Prior[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!rtIsNaN(kNN_Prior[k - 1])) {
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
    ex = kNN_Prior[idx - 1];
    i = idx + 1;
    for (k = i; k < 5; k++) {
      d = kNN_Prior[k - 1];
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

  *label = kNN_ClassNames[idx - 1];
  if (notNaN) {
    *label = kNN_ClassNames[classnum - 1];
  }
}

/*
 * File trailer for kNN.c
 *
 * [EOF]
 */
