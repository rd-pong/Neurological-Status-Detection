/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: predictOneWithCache.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 10:01:49
 */

/* Include Files */
#include "predictOneWithCache.h"
#include "CompactClassificationTree.h"
#include "RF.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : const double X[7]
 *                double cachedScore[4]
 *                double *cachedWeights
 *                const char combiner[15]
 *                const double weak_learner_CutPredictorIndex[1201]
 *                const double weak_learner_Children[2402]
 *                const double weak_learner_CutPoint[1201]
 *                const bool weak_learner_NanCutPoints[1201]
 *                const double weak_learner_ClassNames[4]
 *                const double weak_learner_Cost[16]
 *                const double weak_learner_ClassProbability[4804]
 *                bool *cached
 *                const double classnames[4]
 *                bool initCache
 *                double score[4]
 * Return Type  : void
 */
void predictOneWithCache(const double X[7], double cachedScore[4], double
  *cachedWeights, const char combiner[15], const double
  weak_learner_CutPredictorIndex[1201], const double weak_learner_Children[2402],
  const double weak_learner_CutPoint[1201], const bool
  weak_learner_NanCutPoints[1201], const double weak_learner_ClassNames[4],
  const double weak_learner_Cost[16], const double
  weak_learner_ClassProbability[4804], bool *cached, const double classnames[4],
  bool initCache, double score[4])
{
  double learnerscore[4];
  int iloc_idx_0;
  int i;
  bool exitg1;
  int iloc_idx_1;
  double absx;
  int exponent;
  int iloc_idx_2;
  int iloc_idx_3;
  double dv[4];
  bool tf[4];
  bool y;
  int exitg2;
  static const char cv[128] = { '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\x07', '\x08', '	', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f',
    '\x10', '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18',
    '\x19', '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#',
    '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2',
    '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a',
    'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_',
    '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}',
    '~', '\x7f' };

  static const char cv1[15] = { 'w', 'e', 'i', 'g', 'h', 't', 'e', 'd', 'a', 'v',
    'e', 'r', 'a', 'g', 'e' };

  learnerscore[0] = rtNaN;
  learnerscore[1] = rtNaN;
  learnerscore[2] = rtNaN;
  learnerscore[3] = rtNaN;
  iloc_idx_0 = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 4)) {
    absx = fabs(classnames[i] / 2.0);
    if (absx <= 2.2250738585072014E-308) {
      absx = 4.94065645841247E-324;
    } else {
      frexp(absx, &exponent);
      absx = ldexp(1.0, exponent - 53);
    }

    if (fabs(classnames[i] - weak_learner_ClassNames[0]) < absx) {
      iloc_idx_0 = i + 1;
      exitg1 = true;
    } else {
      i++;
    }
  }

  iloc_idx_1 = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 4)) {
    absx = fabs(classnames[i] / 2.0);
    if (absx <= 2.2250738585072014E-308) {
      absx = 4.94065645841247E-324;
    } else {
      frexp(absx, &exponent);
      absx = ldexp(1.0, exponent - 53);
    }

    if (fabs(classnames[i] - weak_learner_ClassNames[1]) < absx) {
      iloc_idx_1 = i + 1;
      exitg1 = true;
    } else {
      i++;
    }
  }

  iloc_idx_2 = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 4)) {
    absx = fabs(classnames[i] / 2.0);
    if (absx <= 2.2250738585072014E-308) {
      absx = 4.94065645841247E-324;
    } else {
      frexp(absx, &exponent);
      absx = ldexp(1.0, exponent - 53);
    }

    if (fabs(classnames[i] - weak_learner_ClassNames[2]) < absx) {
      iloc_idx_2 = i + 1;
      exitg1 = true;
    } else {
      i++;
    }
  }

  iloc_idx_3 = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 4)) {
    absx = fabs(classnames[i] / 2.0);
    if (absx <= 2.2250738585072014E-308) {
      absx = 4.94065645841247E-324;
    } else {
      frexp(absx, &exponent);
      absx = ldexp(1.0, exponent - 53);
    }

    if (fabs(classnames[i] - weak_learner_ClassNames[3]) < absx) {
      iloc_idx_3 = i + 1;
      exitg1 = true;
    } else {
      i++;
    }
  }

  c_CompactClassificationTree_pre(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    weak_learner_ClassNames, weak_learner_Cost, weak_learner_ClassProbability, X,
    &absx, dv);
  learnerscore[iloc_idx_0 - 1] = dv[0];
  learnerscore[iloc_idx_1 - 1] = dv[1];
  learnerscore[iloc_idx_2 - 1] = dv[2];
  learnerscore[iloc_idx_3 - 1] = dv[3];
  if (initCache) {
    cachedScore[0] = 0.0;
    cachedScore[1] = 0.0;
    cachedScore[2] = 0.0;
    cachedScore[3] = 0.0;
  } else {
    tf[0] = rtIsNaN(cachedScore[0]);
    tf[1] = rtIsNaN(cachedScore[1]);
    tf[2] = rtIsNaN(cachedScore[2]);
    tf[3] = rtIsNaN(cachedScore[3]);
    y = false;
    iloc_idx_0 = 0;
    exitg1 = false;
    while ((!exitg1) && (iloc_idx_0 < 4)) {
      if (tf[iloc_idx_0]) {
        y = true;
        exitg1 = true;
      } else {
        iloc_idx_0++;
      }
    }

    if (y) {
      if (tf[0]) {
        cachedScore[0] = 0.0;
      }

      if (tf[1]) {
        cachedScore[1] = 0.0;
      }

      if (tf[2]) {
        cachedScore[2] = 0.0;
      }

      if (tf[3]) {
        cachedScore[3] = 0.0;
      }
    }
  }

  cachedScore[0] += learnerscore[0];
  cachedScore[1] += learnerscore[1];
  cachedScore[2] += learnerscore[2];
  cachedScore[3] += learnerscore[3];
  y = false;
  iloc_idx_0 = 0;
  do {
    exitg2 = 0;
    if (iloc_idx_0 < 15) {
      if (cv[(unsigned char)combiner[iloc_idx_0]] != cv[(int)cv1[iloc_idx_0]]) {
        exitg2 = 1;
      } else {
        iloc_idx_0++;
      }
    } else {
      y = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  if (y) {
    score[0] = cachedScore[0] / (*cachedWeights + 1.0);
    score[1] = cachedScore[1] / (*cachedWeights + 1.0);
    score[2] = cachedScore[2] / (*cachedWeights + 1.0);
    score[3] = cachedScore[3] / (*cachedWeights + 1.0);
  } else {
    score[0] = cachedScore[0];
    score[1] = cachedScore[1];
    score[2] = cachedScore[2];
    score[3] = cachedScore[3];
  }

  (*cachedWeights)++;
  *cached = true;
}

/*
 * File trailer for predictOneWithCache.c
 *
 * [EOF]
 */
