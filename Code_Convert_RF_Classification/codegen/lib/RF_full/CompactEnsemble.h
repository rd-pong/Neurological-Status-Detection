/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactEnsemble.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 20:59:21
 */

#ifndef COMPACTENSEMBLE_H
#define COMPACTENSEMBLE_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "RF_full_types.h"

/* Function Declarations */
extern void CompactEnsemble_ensemblePredict(const bool obj_IsCached[30], const
  double X[28], const double classnames[4], double score[4]);

#endif

/*
 * File trailer for CompactEnsemble.h
 *
 * [EOF]
 */
