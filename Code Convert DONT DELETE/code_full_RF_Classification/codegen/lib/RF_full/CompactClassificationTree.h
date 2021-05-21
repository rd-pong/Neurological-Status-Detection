/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationTree.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 20:59:21
 */

#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "RF_full_types.h"

/* Function Declarations */
extern void ab_CompactClassificationTree_Co(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void bb_CompactClassificationTree_Co(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void c_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void c_CompactClassificationTree_pre(const double obj_CutPredictorIndex
  [101], const double obj_Children[202], const double obj_CutPoint[101], const
  bool obj_NanCutPoints[101], const double obj_ClassNames[4], const double
  obj_Cost[16], const double obj_ClassProbability[404], const double X[28],
  double *labels, double scores[4]);
extern void cb_CompactClassificationTree_Co(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void d_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void db_CompactClassificationTree_Co(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void e_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void eb_CompactClassificationTree_Co(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void f_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void fb_CompactClassificationTree_Co(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void g_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void gb_CompactClassificationTree_Co(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void h_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void i_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void j_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void k_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void l_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void m_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void n_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void o_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void p_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void q_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void r_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void s_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void t_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void u_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void v_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void w_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void x_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);
extern void y_CompactClassificationTree_Com(double obj_CutPredictorIndex[101],
  double obj_Children[202], double obj_CutPoint[101], bool obj_NanCutPoints[101],
  bool obj_InfCutPoints[101], double obj_ClassNames[4], int
  obj_ClassNamesLength[4], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[4], bool obj_ClassLogicalIndices[4], double obj_Cost[16],
  double obj_ClassProbability[404]);

#endif

/*
 * File trailer for CompactClassificationTree.h
 *
 * [EOF]
 */
