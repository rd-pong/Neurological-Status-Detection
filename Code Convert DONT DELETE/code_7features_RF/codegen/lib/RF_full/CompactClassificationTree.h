/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationTree.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 09:51:20
 */

#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "RF_full_types.h"

/* Function Declarations */
extern void c_CompactClassificationTree_Com(double obj_CutPredictorIndex[1001],
  double obj_Children[2002], double obj_CutPoint[1001], bool obj_NanCutPoints
  [1001], bool obj_InfCutPoints[1001], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[4004]);
extern void c_CompactClassificationTree_pre(const double obj_CutPredictorIndex
  [1001], const double obj_Children[2002], const double obj_CutPoint[1001],
  const bool obj_NanCutPoints[1001], const double obj_ClassNames[4], const
  double obj_Cost[16], const double obj_ClassProbability[4004], const double X[7],
  double *labels, double scores[4]);
extern void d_CompactClassificationTree_Com(double obj_CutPredictorIndex[1001],
  double obj_Children[2002], double obj_CutPoint[1001], bool obj_NanCutPoints
  [1001], bool obj_InfCutPoints[1001], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[4004]);
extern void e_CompactClassificationTree_Com(double obj_CutPredictorIndex[1001],
  double obj_Children[2002], double obj_CutPoint[1001], bool obj_NanCutPoints
  [1001], bool obj_InfCutPoints[1001], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[4004]);

#endif

/*
 * File trailer for CompactClassificationTree.h
 *
 * [EOF]
 */
