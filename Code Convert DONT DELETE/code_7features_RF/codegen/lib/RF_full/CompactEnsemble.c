/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactEnsemble.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 09:51:20
 */

/* Include Files */
#include "CompactEnsemble.h"
#include "CompactClassificationTree.h"
#include "RF_full.h"
#include "predictOneWithCache.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const double X[7]
 *                const double classnames[4]
 *                double score[4]
 * Return Type  : void
 */
void CompactEnsemble_ensemblePredict(const double X[7], const double classnames
  [4], double score[4])
{
  double weak_learner_CutPredictorIndex[1001];
  double weak_learner_Children[2002];
  double weak_learner_CutPoint[1001];
  bool weak_learner_NanCutPoints[1001];
  bool expl_temp[1001];
  double weak_learner_ClassNames[4];
  int b_expl_temp[4];
  c_classreg_learning_coderutils_ c_expl_temp;
  double d_expl_temp[4];
  bool e_expl_temp[4];
  double weak_learner_Cost[16];
  double weak_learner_ClassProbability[4004];
  double cachedScore[4];
  double cachedWeights;
  bool b;
  static const char combiner[15] = { 'W', 'e', 'i', 'g', 'h', 't', 'e', 'd', 'A',
    'v', 'e', 'r', 'a', 'g', 'e' };

  c_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  cachedScore[0] = 0.0;
  cachedScore[1] = 0.0;
  cachedScore[2] = 0.0;
  cachedScore[3] = 0.0;
  cachedWeights = 0.0;
  b = false;
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, true,
                      d_expl_temp);
  d_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = false;
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  e_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = false;
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      score);
}

/*
 * File trailer for CompactEnsemble.c
 *
 * [EOF]
 */
