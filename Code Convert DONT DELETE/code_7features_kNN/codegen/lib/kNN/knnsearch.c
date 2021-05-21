/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: knnsearch.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 06-May-2021 23:36:41
 */

/* Include Files */
#include "knnsearch.h"
#include "createkds.h"
#include "kNN.h"
#include "kNN_emxutil.h"
#include "kdsearchfun.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const double X[101479]
 *                const double Y[7]
 *                double Idx_data[]
 *                int Idx_size[2]
 *                double D_data[]
 *                int D_size[2]
 * Return Type  : void
 */
void knnsearch(const double X[101479], const double Y[7], double Idx_data[], int
               Idx_size[2], double D_data[], int D_size[2])
{
  static struct_T expl_temp;
  static double cgstruct_X[101479];
  emxArray_real_T *cgstruct_wasnanIdx;
  int yk;
  int loop_ub;
  double cgstruct_cutDim_data[1023];
  double cgstruct_cutVal_data[1023];
  int cgstruct_lowerBounds_size[2];
  static double cgstruct_lowerBounds_data[7161];
  int cgstruct_upperBounds_size[2];
  static double cgstruct_upperBounds_data[7161];
  double cgstruct_leftChild_data[1023];
  double cgstruct_rightChild_data[1023];
  bool cgstruct_leafNode_data[1023];
  static unsigned int cgstruct_idxAll[14497];
  double cgstruct_idxDim_data[1023];
  bool wasNaNY;
  bool x_data[14497];
  bool exitg1;
  int numNN;
  int cgstruct_wasnanIdx_size[2];
  static int noNanCol_data[14497];
  int i;
  double distTemp_data[3];
  double b_distTemp_data[3];
  int distTemp_size[1];
  unsigned int t3_I_data[3];
  int t3_I_size[1];
  static int tmp_data[14497];
  int i1;
  unsigned int b_t3_I_data[3];
  int b_loop_ub;
  emxInitStruct_struct_T(&expl_temp);
  createkds(X, &expl_temp);
  memcpy(&cgstruct_X[0], &expl_temp.X[0], 101479U * sizeof(double));
  emxInit_real_T(&cgstruct_wasnanIdx, 2);
  yk = cgstruct_wasnanIdx->size[0] * cgstruct_wasnanIdx->size[1];
  cgstruct_wasnanIdx->size[0] = 1;
  cgstruct_wasnanIdx->size[1] = expl_temp.wasnanIdx->size[1];
  emxEnsureCapacity_real_T(cgstruct_wasnanIdx, yk);
  loop_ub = expl_temp.wasnanIdx->size[0] * expl_temp.wasnanIdx->size[1];
  for (yk = 0; yk < loop_ub; yk++) {
    cgstruct_wasnanIdx->data[yk] = expl_temp.wasnanIdx->data[yk];
  }

  loop_ub = expl_temp.cutDim.size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&cgstruct_cutDim_data[0], &expl_temp.cutDim.data[0], loop_ub * sizeof
           (double));
  }

  loop_ub = expl_temp.cutVal.size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&cgstruct_cutVal_data[0], &expl_temp.cutVal.data[0], loop_ub * sizeof
           (double));
  }

  cgstruct_lowerBounds_size[0] = expl_temp.lowerBounds.size[0];
  cgstruct_lowerBounds_size[1] = expl_temp.lowerBounds.size[1];
  loop_ub = expl_temp.lowerBounds.size[0] * expl_temp.lowerBounds.size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&cgstruct_lowerBounds_data[0], &expl_temp.lowerBounds.data[0],
           loop_ub * sizeof(double));
  }

  cgstruct_upperBounds_size[0] = expl_temp.upperBounds.size[0];
  cgstruct_upperBounds_size[1] = expl_temp.upperBounds.size[1];
  loop_ub = expl_temp.upperBounds.size[0] * expl_temp.upperBounds.size[1];
  if (0 <= loop_ub - 1) {
    memcpy(&cgstruct_upperBounds_data[0], &expl_temp.upperBounds.data[0],
           loop_ub * sizeof(double));
  }

  loop_ub = expl_temp.leftChild.size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&cgstruct_leftChild_data[0], &expl_temp.leftChild.data[0], loop_ub *
           sizeof(double));
  }

  loop_ub = expl_temp.rightChild.size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&cgstruct_rightChild_data[0], &expl_temp.rightChild.data[0], loop_ub *
           sizeof(double));
  }

  loop_ub = expl_temp.leafNode.size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&cgstruct_leafNode_data[0], &expl_temp.leafNode.data[0], loop_ub *
           sizeof(bool));
  }

  memcpy(&cgstruct_idxAll[0], &expl_temp.idxAll[0], 14497U * sizeof(unsigned int));
  loop_ub = expl_temp.idxDim.size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&cgstruct_idxDim_data[0], &expl_temp.idxDim.data[0], loop_ub * sizeof
           (double));
  }

  for (yk = 0; yk < 7; yk++) {
    x_data[yk] = rtIsNaN(Y[yk]);
  }

  wasNaNY = false;
  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= 6)) {
    if (!x_data[loop_ub]) {
      loop_ub++;
    } else {
      wasNaNY = true;
      exitg1 = true;
    }
  }

  if (3.0 > expl_temp.nx_nonan) {
    numNN = (int)expl_temp.nx_nonan;
  } else {
    numNN = 3;
  }

  emxFreeStruct_struct_T(&expl_temp);
  if (numNN > 0) {
    Idx_size[0] = 1;
    Idx_size[1] = 3;
    D_size[0] = 1;
    D_size[1] = 3;
    Idx_data[0] = 0.0;
    D_data[0] = 0.0;
    Idx_data[1] = 0.0;
    D_data[1] = 0.0;
    Idx_data[2] = 0.0;
    D_data[2] = 0.0;
    noNanCol_data[0] = 1;
    yk = 1;
    for (loop_ub = 2; loop_ub <= numNN; loop_ub++) {
      yk++;
      noNanCol_data[loop_ub - 1] = yk;
    }

    if (wasNaNY) {
      for (yk = 0; yk < numNN; yk++) {
        D_data[noNanCol_data[yk] - 1] = rtNaN;
      }

      for (yk = 0; yk < numNN; yk++) {
        Idx_data[noNanCol_data[yk] - 1] = noNanCol_data[yk];
      }
    } else {
      search_kdtree(cgstruct_cutDim_data, cgstruct_cutVal_data,
                    cgstruct_lowerBounds_data, cgstruct_lowerBounds_size,
                    cgstruct_upperBounds_data, cgstruct_upperBounds_size,
                    cgstruct_leftChild_data, cgstruct_rightChild_data,
                    cgstruct_leafNode_data, cgstruct_idxAll,
                    cgstruct_idxDim_data, cgstruct_X, Y, numNN, distTemp_data,
                    distTemp_size, t3_I_data, t3_I_size);
      yk = distTemp_size[0];
      for (loop_ub = 0; loop_ub < yk; loop_ub++) {
        distTemp_data[loop_ub] = sqrt(distTemp_data[loop_ub]);
      }

      for (yk = 0; yk < numNN; yk++) {
        tmp_data[yk] = noNanCol_data[yk] - 1;
      }

      if (0 <= numNN - 1) {
        memcpy(&b_distTemp_data[0], &distTemp_data[0], numNN * sizeof(double));
        memcpy(&distTemp_data[0], &b_distTemp_data[0], numNN * sizeof(double));
      }

      for (yk = 0; yk < numNN; yk++) {
        D_data[tmp_data[yk]] = distTemp_data[yk];
      }

      for (yk = 0; yk < numNN; yk++) {
        tmp_data[yk] = noNanCol_data[yk] - 1;
      }

      if (0 <= numNN - 1) {
        memcpy(&b_t3_I_data[0], &t3_I_data[0], numNN * sizeof(unsigned int));
        memcpy(&t3_I_data[0], &b_t3_I_data[0], numNN * sizeof(unsigned int));
      }

      for (yk = 0; yk < numNN; yk++) {
        Idx_data[tmp_data[yk]] = t3_I_data[yk];
      }
    }
  } else {
    Idx_size[0] = 1;
    Idx_size[1] = 0;
    D_size[0] = 1;
    D_size[1] = 0;
  }

  if (3 - numNN > 0) {
    if (numNN + 1 > 3) {
      yk = 0;
    } else {
      yk = numNN;
    }

    loop_ub = 2 - numNN;
    cgstruct_wasnanIdx_size[0] = 1;
    cgstruct_wasnanIdx_size[1] = 3 - numNN;
    for (i = 0; i <= loop_ub; i++) {
      distTemp_data[i] = cgstruct_wasnanIdx->data[i];
    }

    repmat(distTemp_data, cgstruct_wasnanIdx_size, b_distTemp_data,
           cgstruct_upperBounds_size);
    loop_ub = cgstruct_upperBounds_size[1];
    for (i = 0; i < loop_ub; i++) {
      Idx_data[yk + i] = b_distTemp_data[i];
    }

    if (wasNaNY) {
      if (numNN + 1 > 3) {
        yk = 0;
        i = 0;
        i1 = 0;
      } else {
        yk = numNN;
        i = 3;
        i1 = numNN;
      }

      cgstruct_upperBounds_size[0] = 1;
      loop_ub = i - yk;
      cgstruct_upperBounds_size[1] = loop_ub;
      for (i = 0; i < loop_ub; i++) {
        b_distTemp_data[i] = (short)((short)(yk + i) + 1);
      }

      b_repmat(b_distTemp_data, cgstruct_upperBounds_size, 1.0, distTemp_data,
               cgstruct_lowerBounds_size);
      loop_ub = cgstruct_lowerBounds_size[1];
      for (yk = 0; yk < loop_ub; yk++) {
        b_loop_ub = cgstruct_lowerBounds_size[0];
        for (i = 0; i < b_loop_ub; i++) {
          Idx_data[i1 + yk] = distTemp_data[i + cgstruct_lowerBounds_size[0] *
            yk];
        }
      }
    }

    if (numNN + 1 > 3) {
      numNN = 0;
      yk = -1;
      i = 0;
    } else {
      yk = 2;
      i = numNN;
    }

    loop_ub = yk - numNN;
    for (yk = 0; yk <= loop_ub; yk++) {
      D_data[i + yk] = rtNaN;
    }
  }

  emxFree_real_T(&cgstruct_wasnanIdx);
}

/*
 * File trailer for knnsearch.c
 *
 * [EOF]
 */
