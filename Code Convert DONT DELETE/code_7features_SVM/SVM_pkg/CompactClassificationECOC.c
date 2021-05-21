/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationECOC.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 08:51:25
 */

/* Include Files */
#include "CompactClassificationECOC.h"
#include "CompactSVM.h"
#include "SVM.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const double obj_ClassNames[4]
 *                const double obj_Prior[4]
 *                const c_classreg_learning_coder_class obj_BinaryLearners[6]
 *                const double obj_CodingMatrix[24]
 *                const double Xin[7]
 *                double *labels
 *                double negloss[4]
 * Return Type  : void
 */
void c_CompactClassificationECOC_pre(const double obj_ClassNames[4], const
  double obj_Prior[4], const c_classreg_learning_coder_class obj_BinaryLearners
  [6], const double obj_CodingMatrix[24], const double Xin[7], double *labels,
  double negloss[4])
{
  int idx;
  double M[24];
  int k;
  int partialTrueCount;
  bool notNaN;
  double classnum;
  double Xnorm[7];
  int bcoef;
  bool x[7];
  bool exitg1;
  double pscore[6];
  bool b[4];
  double ex;
  signed char i;
  signed char tmp_data[7];
  int c_size_idx_1;
  int acoef;
  signed char b_tmp_data[7];
  double c_data[7];
  for (idx = 0; idx < 24; idx++) {
    M[idx] = obj_CodingMatrix[idx];
    if (obj_CodingMatrix[idx] == 0.0) {
      M[idx] = rtNaN;
    }
  }

  for (idx = 0; idx < 6; idx++) {
    for (partialTrueCount = 0; partialTrueCount < 7; partialTrueCount++) {
      Xnorm[partialTrueCount] = Xin[partialTrueCount];
      x[partialTrueCount] = (obj_BinaryLearners[idx].Mu[partialTrueCount] == 0.0);
    }

    notNaN = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 6)) {
      if (!x[k]) {
        notNaN = false;
        exitg1 = true;
      } else {
        k++;
      }
    }

    if (!notNaN) {
      for (k = 0; k < 7; k++) {
        Xnorm[k] = Xin[k] - obj_BinaryLearners[idx].Mu[k];
      }
    }

    for (partialTrueCount = 0; partialTrueCount < 7; partialTrueCount++) {
      x[partialTrueCount] = (obj_BinaryLearners[idx].Sigma[partialTrueCount] ==
        1.0);
    }

    notNaN = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 6)) {
      if (!x[k]) {
        notNaN = false;
        exitg1 = true;
      } else {
        k++;
      }
    }

    if (!notNaN) {
      k = 0;
      for (bcoef = 0; bcoef < 7; bcoef++) {
        if (obj_BinaryLearners[idx].Sigma[bcoef] > 0.0) {
          k++;
        }
      }

      partialTrueCount = 0;
      for (bcoef = 0; bcoef < 7; bcoef++) {
        if (obj_BinaryLearners[idx].Sigma[bcoef] > 0.0) {
          tmp_data[partialTrueCount] = (signed char)(bcoef + 1);
          partialTrueCount++;
        }
      }

      if (k == 1) {
        i = 1;
      } else {
        i = (signed char)k;
      }

      c_size_idx_1 = i;
      if (i != 0) {
        acoef = (k != 1);
        bcoef = (k != 1);
        partialTrueCount = i - 1;
        for (k = 0; k <= partialTrueCount; k++) {
          c_data[k] = Xnorm[tmp_data[acoef * k] - 1] / obj_BinaryLearners[idx].
            Sigma[tmp_data[bcoef * k] - 1];
        }
      }

      partialTrueCount = 0;
      for (bcoef = 0; bcoef < 7; bcoef++) {
        if (obj_BinaryLearners[idx].Sigma[bcoef] > 0.0) {
          b_tmp_data[partialTrueCount] = (signed char)(bcoef + 1);
          partialTrueCount++;
        }
      }

      for (partialTrueCount = 0; partialTrueCount < c_size_idx_1;
           partialTrueCount++) {
        Xnorm[b_tmp_data[partialTrueCount] - 1] = c_data[partialTrueCount];
      }
    }

    pscore[idx] = CompactSVM_kernelScore(obj_BinaryLearners[idx].Alpha.data,
      obj_BinaryLearners[idx].Bias, obj_BinaryLearners[idx].SupportVectorsT,
      Xnorm);
  }

  for (k = 0; k < 4; k++) {
    classnum = 0.0;
    bcoef = 0;
    for (partialTrueCount = 0; partialTrueCount < 6; partialTrueCount++) {
      classnum += fmax(0.0, 1.0 - M[k + (partialTrueCount << 2)] *
                       pscore[partialTrueCount]);
      bcoef++;
    }

    if (bcoef == 0) {
      classnum = rtNaN;
    } else {
      classnum /= (double)bcoef;
    }

    classnum = -(classnum / 2.0);
    negloss[k] = classnum;
    b[k] = rtIsNaN(classnum);
  }

  notNaN = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= 3)) {
    if (!b[k]) {
      notNaN = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  notNaN = !notNaN;
  if (!rtIsNaN(obj_Prior[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!rtIsNaN(obj_Prior[k - 1])) {
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
    ex = obj_Prior[idx - 1];
    partialTrueCount = idx + 1;
    for (k = partialTrueCount; k < 5; k++) {
      classnum = obj_Prior[k - 1];
      if (ex < classnum) {
        ex = classnum;
        idx = k;
      }
    }
  }

  classnum = rtNaN;
  if (notNaN) {
    if (!rtIsNaN(negloss[0])) {
      bcoef = 1;
    } else {
      bcoef = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 5)) {
        if (!rtIsNaN(negloss[k - 1])) {
          bcoef = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (bcoef == 0) {
      bcoef = 1;
    } else {
      ex = negloss[bcoef - 1];
      partialTrueCount = bcoef + 1;
      for (k = partialTrueCount; k < 5; k++) {
        classnum = negloss[k - 1];
        if (ex < classnum) {
          ex = classnum;
          bcoef = k;
        }
      }
    }

    classnum = bcoef;
  }

  *labels = obj_ClassNames[idx - 1];
  if (notNaN) {
    if (classnum < 4.294967296E+9) {
      partialTrueCount = (int)classnum;
    } else {
      partialTrueCount = 0;
    }

    *labels = obj_ClassNames[partialTrueCount - 1];
  }
}

/*
 * File trailer for CompactClassificationECOC.c
 *
 * [EOF]
 */
