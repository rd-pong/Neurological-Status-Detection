/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactEnsemble.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 20:59:21
 */

/* Include Files */
#include "CompactEnsemble.h"
#include "CompactClassificationTree.h"
#include "RF_full.h"
#include "predictOneWithCache.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : const bool obj_IsCached[30]
 *                const double X[28]
 *                const double classnames[4]
 *                double score[4]
 * Return Type  : void
 */
void CompactEnsemble_ensemblePredict(const bool obj_IsCached[30], const double
  X[28], const double classnames[4], double score[4])
{
  double weak_learner_CutPredictorIndex[101];
  double weak_learner_Children[202];
  double weak_learner_CutPoint[101];
  bool weak_learner_NanCutPoints[101];
  bool expl_temp[101];
  double weak_learner_ClassNames[4];
  int b_expl_temp[4];
  c_classreg_learning_coderutils_ c_expl_temp;
  double d_expl_temp[4];
  bool e_expl_temp[4];
  double weak_learner_Cost[16];
  double weak_learner_ClassProbability[404];
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
  b = obj_IsCached[1];
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
  b = obj_IsCached[2];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  f_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[3];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  g_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[4];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  h_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[5];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  i_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[6];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  j_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[7];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  k_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[8];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  l_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[9];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  m_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[10];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  n_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[11];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  o_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[12];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  p_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[13];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  q_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[14];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  r_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[15];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  s_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[16];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  t_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[17];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  u_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[18];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  v_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[19];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  w_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[20];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  x_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[21];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  y_CompactClassificationTree_Com(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[22];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  ab_CompactClassificationTree_Co(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[23];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  bb_CompactClassificationTree_Co(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[24];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  cb_CompactClassificationTree_Co(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[25];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  db_CompactClassificationTree_Co(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[26];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  eb_CompactClassificationTree_Co(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[27];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  fb_CompactClassificationTree_Co(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[28];
  predictOneWithCache(X, cachedScore, &cachedWeights, combiner,
                      weak_learner_CutPredictorIndex, weak_learner_Children,
                      weak_learner_CutPoint, weak_learner_NanCutPoints,
                      weak_learner_ClassNames, weak_learner_Cost,
                      weak_learner_ClassProbability, &b, classnames, false,
                      d_expl_temp);
  gb_CompactClassificationTree_Co(weak_learner_CutPredictorIndex,
    weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
    expl_temp, weak_learner_ClassNames, b_expl_temp, &c_expl_temp, d_expl_temp,
    e_expl_temp, weak_learner_Cost, weak_learner_ClassProbability);
  b = obj_IsCached[29];
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
