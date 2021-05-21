/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: createkds.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 06-May-2021 23:36:41
 */

/* Include Files */
#include "createkds.h"
#include "kNN.h"
#include "kNN_emxutil.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include <math.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const double X[101479]
 *                struct_T *sObj
 * Return Type  : void
 */
void createkds(const double X[101479], struct_T *sObj)
{
  int i;
  int m;
  short notnan_data[14497];
  signed char cutDimTemp_data[1023];
  double cutValTemp_data[1023];
  static double upperBoundsTemp_data[7161];
  double leftChildTemp_data[1023];
  static double lowerBoundsTemp_data[7161];
  double rightChildTemp_data[1023];
  bool leafNodeTemp_data[1023];
  emxArray_cell_wrap_31_1023 idxTemp;
  int currentNode;
  int nextUnusedNode;
  emxArray_real_T *x;
  int exitg1;
  int idxTemp_size[1];
  int unusedNodes;
  int half;
  double cc;
  double temp[7];
  static const char dist[9] = { 'e', 'u', 'c', 'l', 'i', 'd', 'e', 'a', 'n' };

  int b_i;
  double minval[7];
  int i1;
  double d;
  static int idxTemp_data[14497];
  short tempDim_data[1023];
  for (i = 0; i < 14497; i++) {
    notnan_data[i] = (short)(i + 1);
  }

  frexp(289.94, &m);
  memset(&cutDimTemp_data[0], 0, 1023U * sizeof(signed char));
  memset(&cutValTemp_data[0], 0, 1023U * sizeof(double));
  for (i = 0; i < 7161; i++) {
    upperBoundsTemp_data[i] = rtInf;
  }

  for (i = 0; i < 7161; i++) {
    lowerBoundsTemp_data[i] = rtMinusInf;
  }

  memset(&leftChildTemp_data[0], 0, 1023U * sizeof(double));
  memset(&rightChildTemp_data[0], 0, 1023U * sizeof(double));
  memset(&leafNodeTemp_data[0], 0, 1023U * sizeof(bool));
  emxInit_cell_wrap_31_1023(&idxTemp);
  i = idxTemp.size[0];
  idxTemp.size[0] = 1023;
  emxEnsureCapacity_cell_wrap_31(idxTemp.data, idxTemp.size, i);
  i = idxTemp.data[0].f1->size[0] * idxTemp.data[0].f1->size[1];
  idxTemp.data[0].f1->size[0] = 1;
  idxTemp.data[0].f1->size[1] = 14497;
  emxEnsureCapacity_real_T(idxTemp.data[0].f1, i);
  for (i = 0; i < 14497; i++) {
    idxTemp.data[0].f1->data[i] = notnan_data[i];
  }

  currentNode = 0;
  nextUnusedNode = 1;
  emxInit_real_T(&x, 1);
  do {
    exitg1 = 0;
    i = nextUnusedNode + 1;
    if (currentNode + 1 < i) {
      if (idxTemp.data[currentNode].f1->size[1] <= 50) {
        leafNodeTemp_data[currentNode] = true;
      } else {
        idxTemp_size[0] = idxTemp.data[currentNode].f1->size[1];
        m = idxTemp_size[0];
        idxTemp_size[0] = idxTemp.data[currentNode].f1->size[1];
        unusedNodes = idxTemp_size[0];
        for (half = 0; half < 7; half++) {
          temp[half] = X[((int)idxTemp.data[currentNode].f1->data[0] + 14497 *
                          half) - 1];
          for (b_i = 2; b_i <= m; b_i++) {
            i1 = ((int)idxTemp.data[currentNode].f1->data[b_i - 1] + 14497 *
                  half) - 1;
            if (temp[half] < X[i1]) {
              temp[half] = X[i1];
            }
          }

          minval[half] = X[((int)idxTemp.data[currentNode].f1->data[0] + 14497 *
                            half) - 1];
          for (b_i = 2; b_i <= unusedNodes; b_i++) {
            i1 = ((int)idxTemp.data[currentNode].f1->data[b_i - 1] + 14497 *
                  half) - 1;
            if (minval[half] > X[i1]) {
              minval[half] = X[i1];
            }
          }

          temp[half] -= minval[half];
        }

        cc = temp[0];
        b_i = 0;
        for (m = 0; m < 6; m++) {
          d = temp[m + 1];
          if (cc < d) {
            cc = d;
            b_i = m + 1;
          }
        }

        i1 = x->size[0];
        x->size[0] = idxTemp.data[currentNode].f1->size[1];
        emxEnsureCapacity_real_T(x, i1);
        unusedNodes = idxTemp.data[currentNode].f1->size[1];
        for (i1 = 0; i1 < unusedNodes; i1++) {
          x->data[i1] = X[((int)idxTemp.data[currentNode].f1->data[i1] + 14497 *
                           b_i) - 1];
        }

        sort(x, idxTemp_data, idxTemp_size);
        unusedNodes = idxTemp_size[0];
        for (i1 = 0; i1 < unusedNodes; i1++) {
          notnan_data[i1] = (short)idxTemp.data[currentNode].f1->
            data[idxTemp_data[i1] - 1];
        }

        half = (int)ceil((double)x->size[0] / 2.0);
        cc = (x->data[half - 1] + x->data[half]) / 2.0;
        cutDimTemp_data[currentNode] = (signed char)(b_i + 1);
        cutValTemp_data[currentNode] = cc;
        leftChildTemp_data[currentNode] = i;
        rightChildTemp_data[currentNode] = (double)i + 1.0;
        for (i = 0; i < 7; i++) {
          m = currentNode + 1023 * i;
          temp[i] = upperBoundsTemp_data[m];
          minval[i] = upperBoundsTemp_data[m];
        }

        for (i = 0; i < 7; i++) {
          upperBoundsTemp_data[(nextUnusedNode + 1023 * i) + 1] = minval[i];
        }

        temp[b_i] = cc;
        for (i = 0; i < 7; i++) {
          upperBoundsTemp_data[nextUnusedNode + 1023 * i] = temp[i];
          m = currentNode + 1023 * i;
          temp[i] = lowerBoundsTemp_data[m];
          minval[i] = lowerBoundsTemp_data[m];
        }

        for (i = 0; i < 7; i++) {
          lowerBoundsTemp_data[nextUnusedNode + 1023 * i] = minval[i];
        }

        temp[b_i] = cc;
        for (i = 0; i < 7; i++) {
          lowerBoundsTemp_data[(nextUnusedNode + 1023 * i) + 1] = temp[i];
        }

        idxTemp.data[currentNode].f1->size[0] = 1;
        idxTemp.data[currentNode].f1->size[1] = 0;
        i = idxTemp.data[nextUnusedNode].f1->size[0] *
          idxTemp.data[nextUnusedNode].f1->size[1];
        idxTemp.data[nextUnusedNode].f1->size[0] = 1;
        idxTemp.data[nextUnusedNode].f1->size[1] = half;
        emxEnsureCapacity_real_T(idxTemp.data[nextUnusedNode].f1, i);
        for (i = 0; i < half; i++) {
          idxTemp.data[nextUnusedNode].f1->data[i] = notnan_data[i];
        }

        if (half + 1 > idxTemp_size[0]) {
          half = 0;
          i = 0;
        } else {
          i = idxTemp_size[0];
        }

        i1 = idxTemp.data[nextUnusedNode + 1].f1->size[0] *
          idxTemp.data[nextUnusedNode + 1].f1->size[1];
        idxTemp.data[nextUnusedNode + 1].f1->size[0] = 1;
        unusedNodes = i - half;
        idxTemp.data[nextUnusedNode + 1].f1->size[1] = unusedNodes;
        emxEnsureCapacity_real_T(idxTemp.data[nextUnusedNode + 1].f1, i1);
        for (i = 0; i < unusedNodes; i++) {
          idxTemp.data[nextUnusedNode + 1].f1->data[i] = notnan_data[half + i];
        }

        nextUnusedNode += 2;
      }

      currentNode++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_real_T(&x);
  unusedNodes = nextUnusedNode - 1;
  memcpy(&sObj->X[0], &X[0], 101479U * sizeof(double));
  for (i = 0; i < 9; i++) {
    sObj->Distance[i] = dist[i];
  }

  sObj->BucketSize = 50.0;
  sObj->wasnanIdx->size[0] = 1;
  sObj->wasnanIdx->size[1] = 0;
  sObj->numNodes = nextUnusedNode;
  sObj->nx_nonan = 14497.0;
  sObj->cutDim.size[0] = nextUnusedNode;
  sObj->cutVal.size[0] = nextUnusedNode;
  for (i = 0; i < nextUnusedNode; i++) {
    sObj->cutDim.data[i] = cutDimTemp_data[i];
    sObj->cutVal.data[i] = cutValTemp_data[i];
  }

  sObj->lowerBounds.size[0] = nextUnusedNode;
  sObj->lowerBounds.size[1] = 7;
  sObj->upperBounds.size[0] = nextUnusedNode;
  sObj->upperBounds.size[1] = 7;
  for (i = 0; i < 7; i++) {
    for (i1 = 0; i1 < nextUnusedNode; i1++) {
      sObj->lowerBounds.data[i1 + sObj->lowerBounds.size[0] * i] =
        lowerBoundsTemp_data[i1 + 1023 * i];
      sObj->upperBounds.data[i1 + sObj->upperBounds.size[0] * i] =
        upperBoundsTemp_data[i1 + 1023 * i];
    }
  }

  memset(&sObj->idxAll[0], 0, 14497U * sizeof(unsigned int));
  cc = 1.0;
  for (m = 0; m <= unusedNodes; m++) {
    tempDim_data[m] = (short)idxTemp.data[m].f1->size[1];
    if ((short)idxTemp.data[m].f1->size[1] > 0) {
      d = (cc + (double)(short)idxTemp.data[m].f1->size[1]) - 1.0;
      if (cc > d) {
        i = -1;
        i1 = 0;
      } else {
        i = (int)cc - 2;
        i1 = (int)d;
      }

      currentNode = (i1 - i) - 1;
      for (i1 = 0; i1 < currentNode; i1++) {
        sObj->idxAll[(i + i1) + 1] = (unsigned int)idxTemp.data[m].f1->data[i1];
      }

      cc += (double)tempDim_data[m];
    }
  }

  emxFree_cell_wrap_31_1023(&idxTemp);
  sObj->idxDim.size[0] = nextUnusedNode;
  for (i = 0; i < nextUnusedNode; i++) {
    sObj->idxDim.data[i] = tempDim_data[i];
  }

  sObj->leftChild.size[0] = nextUnusedNode;
  sObj->rightChild.size[0] = nextUnusedNode;
  sObj->leafNode.size[0] = nextUnusedNode;
  if (0 <= nextUnusedNode - 1) {
    memcpy(&sObj->leftChild.data[0], &leftChildTemp_data[0], nextUnusedNode *
           sizeof(double));
    memcpy(&sObj->rightChild.data[0], &rightChildTemp_data[0], nextUnusedNode *
           sizeof(double));
    memcpy(&sObj->leafNode.data[0], &leafNodeTemp_data[0], nextUnusedNode *
           sizeof(bool));
  }
}

/*
 * File trailer for createkds.c
 *
 * [EOF]
 */
