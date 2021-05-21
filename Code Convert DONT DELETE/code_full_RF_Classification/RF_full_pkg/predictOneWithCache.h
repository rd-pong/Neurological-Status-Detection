/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: predictOneWithCache.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 20:59:21
 */

#ifndef PREDICTONEWITHCACHE_H
#define PREDICTONEWITHCACHE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "RF_full_types.h"

/* Function Declarations */
extern void predictOneWithCache(const double X[28], double cachedScore[4],
  double *cachedWeights, const char combiner[15], const double
  weak_learner_CutPredictorIndex[101], const double weak_learner_Children[202],
  const double weak_learner_CutPoint[101], const bool weak_learner_NanCutPoints
  [101], const double weak_learner_ClassNames[4], const double
  weak_learner_Cost[16], const double weak_learner_ClassProbability[404], bool
  *cached, const double classnames[4], bool initCache, double score[4]);

#endif

/*
 * File trailer for predictOneWithCache.h
 *
 * [EOF]
 */
