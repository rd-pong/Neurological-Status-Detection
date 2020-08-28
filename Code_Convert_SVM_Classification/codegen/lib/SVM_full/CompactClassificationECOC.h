/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationECOC.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 22:51:15
 */

#ifndef COMPACTCLASSIFICATIONECOC_H
#define COMPACTCLASSIFICATIONECOC_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "SVM_full_types.h"

/* Function Declarations */
extern void c_CompactClassificationECOC_pre(const double obj_ClassNames[4],
  const double obj_Prior[4], const c_classreg_learning_coder_class
  obj_BinaryLearners[6], const double obj_CodingMatrix[24], const double Xin[28],
  double *labels, double negloss[4]);

#endif

/*
 * File trailer for CompactClassificationECOC.h
 *
 * [EOF]
 */
