/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SVM_emxutil.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 08:51:25
 */

#ifndef SVM_EMXUTIL_H
#define SVM_EMXUTIL_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "SVM_types.h"

/* Function Declarations */
extern void c_emxFreeMatrix_classreg_learni(c_classreg_learning_coder_class
  pMatrix[6]);
extern void c_emxInitMatrix_classreg_learni(c_classreg_learning_coder_class
  pMatrix[6]);
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

/*
 * File trailer for SVM_emxutil.h
 *
 * [EOF]
 */
