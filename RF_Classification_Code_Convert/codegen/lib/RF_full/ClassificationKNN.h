/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ClassificationKNN.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 15:49:21
 */

#ifndef CLASSIFICATIONKNN_H
#define CLASSIFICATIONKNN_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "RF_full_types.h"

/* Function Declarations */
extern void ClassificationKNN_score(const double obj_X[405916], const unsigned
  int obj_YIdx[14497], const double obj_W[14497], const double X[28], double
  scores[4], bool *nonnanscoreindices);
extern void c_ClassificationKNN_Classificat(c_classreg_learning_coder_class *obj);

#endif

/*
 * File trailer for ClassificationKNN.h
 *
 * [EOF]
 */
