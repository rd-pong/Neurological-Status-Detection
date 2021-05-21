/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationSVM.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 08:51:25
 */

#ifndef COMPACTCLASSIFICATIONSVM_H
#define COMPACTCLASSIFICATIONSVM_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "SVM_types.h"

/* Function Declarations */
extern void c_CompactClassificationSVM_Comp(double obj_Alpha_data[], int
  obj_Alpha_size[1], double *obj_Bias, emxArray_real_T *obj_SupportVectorsT,
  double *obj_Scale, double *obj_Order, double obj_Mu[7], double obj_Sigma[7],
  d_classreg_learning_coderutils_ *obj_KernelFunction, double obj_ClassNames[2],
  int obj_ClassNamesLength[2], c_classreg_learning_coderutils_
  *obj_ScoreTransform, double obj_Prior[2], bool obj_ClassLogicalIndices[2],
  double obj_Cost[4]);
extern void d_CompactClassificationSVM_Comp(double obj_Alpha_data[], int
  obj_Alpha_size[1], double *obj_Bias, emxArray_real_T *obj_SupportVectorsT,
  double *obj_Scale, double *obj_Order, double obj_Mu[7], double obj_Sigma[7],
  d_classreg_learning_coderutils_ *obj_KernelFunction, double obj_ClassNames[2],
  int obj_ClassNamesLength[2], c_classreg_learning_coderutils_
  *obj_ScoreTransform, double obj_Prior[2], bool obj_ClassLogicalIndices[2],
  double obj_Cost[4]);
extern void e_CompactClassificationSVM_Comp(double obj_Alpha_data[], int
  obj_Alpha_size[1], double *obj_Bias, emxArray_real_T *obj_SupportVectorsT,
  double *obj_Scale, double *obj_Order, double obj_Mu[7], double obj_Sigma[7],
  d_classreg_learning_coderutils_ *obj_KernelFunction, double obj_ClassNames[2],
  int obj_ClassNamesLength[2], c_classreg_learning_coderutils_
  *obj_ScoreTransform, double obj_Prior[2], bool obj_ClassLogicalIndices[2],
  double obj_Cost[4]);
extern void f_CompactClassificationSVM_Comp(double obj_Alpha_data[], int
  obj_Alpha_size[1], double *obj_Bias, emxArray_real_T *obj_SupportVectorsT,
  double *obj_Scale, double *obj_Order, double obj_Mu[7], double obj_Sigma[7],
  d_classreg_learning_coderutils_ *obj_KernelFunction, double obj_ClassNames[2],
  int obj_ClassNamesLength[2], c_classreg_learning_coderutils_
  *obj_ScoreTransform, double obj_Prior[2], bool obj_ClassLogicalIndices[2],
  double obj_Cost[4]);
extern void g_CompactClassificationSVM_Comp(double obj_Alpha_data[], int
  obj_Alpha_size[1], double *obj_Bias, emxArray_real_T *obj_SupportVectorsT,
  double *obj_Scale, double *obj_Order, double obj_Mu[7], double obj_Sigma[7],
  d_classreg_learning_coderutils_ *obj_KernelFunction, double obj_ClassNames[2],
  int obj_ClassNamesLength[2], c_classreg_learning_coderutils_
  *obj_ScoreTransform, double obj_Prior[2], bool obj_ClassLogicalIndices[2],
  double obj_Cost[4]);
extern void h_CompactClassificationSVM_Comp(double obj_Alpha_data[], int
  obj_Alpha_size[1], double *obj_Bias, emxArray_real_T *obj_SupportVectorsT,
  double *obj_Scale, double *obj_Order, double obj_Mu[7], double obj_Sigma[7],
  d_classreg_learning_coderutils_ *obj_KernelFunction, double obj_ClassNames[2],
  int obj_ClassNamesLength[2], c_classreg_learning_coderutils_
  *obj_ScoreTransform, double obj_Prior[2], bool obj_ClassLogicalIndices[2],
  double obj_Cost[4]);

#endif

/*
 * File trailer for CompactClassificationSVM.h
 *
 * [EOF]
 */
