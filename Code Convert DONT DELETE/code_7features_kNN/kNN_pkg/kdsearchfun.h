/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: kdsearchfun.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 06-May-2021 23:36:41
 */

#ifndef KDSEARCHFUN_H
#define KDSEARCHFUN_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "kNN_types.h"

/* Function Declarations */
extern void search_kdtree(const double obj_cutDim_data[], const double
  obj_cutVal_data[], const double obj_lowerBounds_data[], const int
  obj_lowerBounds_size[2], const double obj_upperBounds_data[], const int
  obj_upperBounds_size[2], const double obj_leftChild_data[], const double
  obj_rightChild_data[], const bool obj_leafNode_data[], const unsigned int
  obj_idxAll[14497], const double obj_idxDim_data[], const double X[101479],
  const double queryPt[7], int numNN, double pq_D_data[], int pq_D_size[1],
  unsigned int pq_I_data[], int pq_I_size[1]);

#endif

/*
 * File trailer for kdsearchfun.h
 *
 * [EOF]
 */
