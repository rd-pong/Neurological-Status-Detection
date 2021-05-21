/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: predictOneWithCache.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 09:51:20
 */

#ifndef PREDICTONEWITHCACHE_H
#define PREDICTONEWITHCACHE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "RF_full_types.h"

/* Function Declarations */
extern void predictOneWithCache(const double X[7], double cachedScore[4], double
  *cachedWeights, const char combiner[15], const double
  weak_learner_CutPredictorIndex[1001], const double weak_learner_Children[2002],
  const double weak_learner_CutPoint[1001], const bool
  weak_learner_NanCutPoints[1001], const double weak_learner_ClassNames[4],
  const double weak_learner_Cost[16], const double
  weak_learner_ClassProbability[4004], bool *cached, const double classnames[4],
  bool initCache, double score[4]);

#endif

/*
 * File trailer for predictOneWithCache.h
 *
 * [EOF]
 */
