/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: kdsearchfun.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 06-May-2021 23:36:41
 */

/* Include Files */
#include "kdsearchfun.h"
#include "bsxfun.h"
#include "kNN.h"
#include "kNN_emxutil.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void accuDist(const emxArray_real_T *distIn, emxArray_real_T *distOut);
static bool ball_within_bounds(const double queryPt[7], const double
  lowBounds_data[], const double upBounds_data[], double poweredRadius);
static void getNodeFromArray(const unsigned int idxAll[14497], const double
  idxDim_data[], double this_node, unsigned int node_idx_this_data[], int
  node_idx_this_size[1]);
static void search_node(const double X[101479], const double queryPt[7], const
  unsigned int node_idx_start_data[], const int node_idx_start_size[1], int
  numNN, b_struct_T *pq);

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *distIn
 *                emxArray_real_T *distOut
 * Return Type  : void
 */
static void accuDist(const emxArray_real_T *distIn, emxArray_real_T *distOut)
{
  emxArray_real_T *aDistOut;
  int vstride;
  int k;
  int j;
  int xoffset;
  emxInit_real_T(&aDistOut, 1);
  if (distIn->size[0] == 0) {
    aDistOut->size[0] = 0;
  } else {
    vstride = distIn->size[0];
    k = aDistOut->size[0];
    aDistOut->size[0] = (short)distIn->size[0];
    emxEnsureCapacity_real_T(aDistOut, k);
    for (j = 0; j < vstride; j++) {
      aDistOut->data[j] = distIn->data[j];
    }

    for (k = 0; k < 6; k++) {
      xoffset = (k + 1) * vstride;
      for (j = 0; j < vstride; j++) {
        aDistOut->data[j] += distIn->data[xoffset + j];
      }
    }
  }

  j = aDistOut->size[0];
  k = distOut->size[0];
  distOut->size[0] = aDistOut->size[0];
  emxEnsureCapacity_real_T(distOut, k);
  for (k = 0; k < j; k++) {
    distOut->data[k] = aDistOut->data[k];
  }

  emxFree_real_T(&aDistOut);
}

/*
 * Arguments    : const double queryPt[7]
 *                const double lowBounds_data[]
 *                const double upBounds_data[]
 *                double poweredRadius
 * Return Type  : bool
 */
static bool ball_within_bounds(const double queryPt[7], const double
  lowBounds_data[], const double upBounds_data[], double poweredRadius)
{
  bool ballIsWithinBounds;
  int idx;
  double x_data[7];
  double d;
  double lowDist_tmp;
  int k;
  double lowDist[7];
  bool exitg1;
  double pRadIn[7];
  double upDist[7];
  for (idx = 0; idx < 7; idx++) {
    d = queryPt[idx] - lowBounds_data[idx];
    lowDist_tmp = d * d;
    lowDist[idx] = lowDist_tmp;
    d = queryPt[idx] - upBounds_data[idx];
    pRadIn[idx] = d;
    upDist[idx] = d * d;
    x_data[idx] = lowDist_tmp;
  }

  if (!rtIsNaN(x_data[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 8)) {
      if (!rtIsNaN(x_data[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    lowDist_tmp = lowDist[0];
  } else {
    lowDist_tmp = lowDist[idx - 1];
    idx++;
    for (k = idx; k < 8; k++) {
      d = lowDist[k - 1];
      if (lowDist_tmp > d) {
        lowDist_tmp = d;
      }
    }
  }

  if (lowDist_tmp <= poweredRadius) {
    ballIsWithinBounds = false;
  } else {
    for (idx = 0; idx < 7; idx++) {
      x_data[idx] = pRadIn[idx] * pRadIn[idx];
    }

    if (!rtIsNaN(x_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 8)) {
        if (!rtIsNaN(x_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      lowDist_tmp = upDist[0];
    } else {
      lowDist_tmp = upDist[idx - 1];
      idx++;
      for (k = idx; k < 8; k++) {
        d = upDist[k - 1];
        if (lowDist_tmp > d) {
          lowDist_tmp = d;
        }
      }
    }

    if (lowDist_tmp <= poweredRadius) {
      ballIsWithinBounds = false;
    } else {
      ballIsWithinBounds = true;
    }
  }

  return ballIsWithinBounds;
}

/*
 * Arguments    : const unsigned int idxAll[14497]
 *                const double idxDim_data[]
 *                double this_node
 *                unsigned int node_idx_this_data[]
 *                int node_idx_this_size[1]
 * Return Type  : void
 */
static void getNodeFromArray(const unsigned int idxAll[14497], const double
  idxDim_data[], double this_node, unsigned int node_idx_this_data[], int
  node_idx_this_size[1])
{
  int i;
  int vlen;
  double nIdx;
  int k;
  i = (int)this_node - 1;
  if (idxDim_data[i] == 0.0) {
    node_idx_this_size[0] = 0;
  } else if (this_node == 1.0) {
    if (1.0 > idxDim_data[0]) {
      vlen = 0;
    } else {
      vlen = (int)idxDim_data[0];
    }

    node_idx_this_size[0] = vlen;
    if (0 <= vlen - 1) {
      memcpy(&node_idx_this_data[0], &idxAll[0], vlen * sizeof(unsigned int));
    }
  } else {
    vlen = (int)(this_node - 1.0);
    nIdx = idxDim_data[0];
    for (k = 2; k <= vlen; k++) {
      nIdx += idxDim_data[k - 1];
    }

    vlen = (int)floor(idxDim_data[i] - 1.0);
    node_idx_this_size[0] = vlen + 1;
    for (i = 0; i <= vlen; i++) {
      node_idx_this_data[i] = idxAll[(int)(nIdx + (double)(i + 1)) - 1];
    }
  }
}

/*
 * Arguments    : const double X[101479]
 *                const double queryPt[7]
 *                const unsigned int node_idx_start_data[]
 *                const int node_idx_start_size[1]
 *                int numNN
 *                b_struct_T *pq
 * Return Type  : void
 */
static void search_node(const double X[101479], const double queryPt[7], const
  unsigned int node_idx_start_data[], const int node_idx_start_size[1], int
  numNN, b_struct_T *pq)
{
  emxArray_real_T *b_X;
  int i;
  int cD1;
  emxArray_real_T *diffAllDim;
  int x;
  emxArray_real_T *distInP;
  static int iidx_data[14497];
  int iidx_size[1];
  emxArray_real_T *r;
  int cD2;
  int uBound;
  bool exitg1;
  static unsigned int tmp_data[14500];
  emxInit_real_T(&b_X, 2);
  i = b_X->size[0] * b_X->size[1];
  b_X->size[0] = node_idx_start_size[0];
  b_X->size[1] = 7;
  emxEnsureCapacity_real_T(b_X, i);
  cD1 = node_idx_start_size[0];
  for (i = 0; i < 7; i++) {
    for (x = 0; x < cD1; x++) {
      b_X->data[x + b_X->size[0] * i] = X[((int)node_idx_start_data[x] + 14497 *
        i) - 1];
    }
  }

  emxInit_real_T(&diffAllDim, 2);
  bsxfun(b_X, queryPt, diffAllDim);
  i = b_X->size[0] * b_X->size[1];
  b_X->size[0] = diffAllDim->size[0];
  b_X->size[1] = 7;
  emxEnsureCapacity_real_T(b_X, i);
  cD1 = diffAllDim->size[0] * diffAllDim->size[1];
  for (i = 0; i < cD1; i++) {
    b_X->data[i] = diffAllDim->data[i] * diffAllDim->data[i];
  }

  emxFree_real_T(&diffAllDim);
  emxInit_real_T(&distInP, 1);
  accuDist(b_X, distInP);
  sort(distInP, iidx_data, iidx_size);
  emxFree_real_T(&b_X);
  if (pq->D->size[0] == 0) {
    if (distInP->size[0] <= numNN) {
      i = pq->D->size[0];
      pq->D->size[0] = distInP->size[0];
      emxEnsureCapacity_real_T(pq->D, i);
      cD1 = distInP->size[0];
      for (i = 0; i < cD1; i++) {
        pq->D->data[i] = distInP->data[i];
      }

      pq->b_I.size[0] = iidx_size[0];
      cD1 = iidx_size[0];
      for (i = 0; i < cD1; i++) {
        pq->b_I.data[i] = node_idx_start_data[iidx_data[i] - 1];
      }
    } else {
      i = pq->D->size[0];
      pq->D->size[0] = numNN;
      emxEnsureCapacity_real_T(pq->D, i);
      for (i = 0; i < numNN; i++) {
        pq->D->data[i] = distInP->data[i];
      }

      pq->b_I.size[0] = numNN;
      for (i = 0; i < numNN; i++) {
        pq->b_I.data[i] = node_idx_start_data[iidx_data[i] - 1];
      }
    }
  } else {
    emxInit_real_T(&r, 1);
    cD1 = 0;
    cD2 = 0;
    x = pq->D->size[0] + distInP->size[0];
    if (x > numNN) {
      uBound = numNN;
    } else {
      uBound = x;
    }

    i = r->size[0];
    r->size[0] = uBound;
    emxEnsureCapacity_real_T(r, i);
    for (i = 0; i < uBound; i++) {
      r->data[i] = 0.0;
      tmp_data[i] = 0U;
    }

    x = 0;
    exitg1 = false;
    while ((!exitg1) && (x <= uBound - 1)) {
      if (pq->D->data[cD1] <= distInP->data[cD2]) {
        r->data[x] = pq->D->data[cD1];
        tmp_data[x] = pq->b_I.data[cD1];
        cD1++;
        if (cD1 + 1 > pq->D->size[0]) {
          i = x + 2;
          for (x = i; x <= uBound; x++) {
            r->data[x - 1] = distInP->data[cD2];
            tmp_data[x - 1] = node_idx_start_data[iidx_data[cD2] - 1];
            cD2++;
          }

          exitg1 = true;
        } else {
          x++;
        }
      } else {
        r->data[x] = distInP->data[cD2];
        tmp_data[x] = node_idx_start_data[iidx_data[cD2] - 1];
        cD2++;
        if (cD2 + 1 > distInP->size[0]) {
          i = x + 2;
          for (x = i; x <= uBound; x++) {
            r->data[x - 1] = pq->D->data[cD1];
            tmp_data[x - 1] = pq->b_I.data[cD1];
            cD1++;
          }

          exitg1 = true;
        } else {
          x++;
        }
      }
    }

    i = pq->D->size[0];
    pq->D->size[0] = r->size[0];
    emxEnsureCapacity_real_T(pq->D, i);
    cD1 = r->size[0];
    for (i = 0; i < cD1; i++) {
      pq->D->data[i] = r->data[i];
    }

    emxFree_real_T(&r);
    pq->b_I.size[0] = uBound;
    if (0 <= uBound - 1) {
      memcpy(&pq->b_I.data[0], &tmp_data[0], uBound * sizeof(unsigned int));
    }
  }

  emxFree_real_T(&distInP);
}

/*
 * Arguments    : const double obj_cutDim_data[]
 *                const double obj_cutVal_data[]
 *                const double obj_lowerBounds_data[]
 *                const int obj_lowerBounds_size[2]
 *                const double obj_upperBounds_data[]
 *                const int obj_upperBounds_size[2]
 *                const double obj_leftChild_data[]
 *                const double obj_rightChild_data[]
 *                const bool obj_leafNode_data[]
 *                const unsigned int obj_idxAll[14497]
 *                const double obj_idxDim_data[]
 *                const double X[101479]
 *                const double queryPt[7]
 *                int numNN
 *                double pq_D_data[]
 *                int pq_D_size[1]
 *                unsigned int pq_I_data[]
 *                int pq_I_size[1]
 * Return Type  : void
 */
void search_kdtree(const double obj_cutDim_data[], const double obj_cutVal_data[],
                   const double obj_lowerBounds_data[], const int
                   obj_lowerBounds_size[2], const double obj_upperBounds_data[],
                   const int obj_upperBounds_size[2], const double
                   obj_leftChild_data[], const double obj_rightChild_data[],
                   const bool obj_leafNode_data[], const unsigned int
                   obj_idxAll[14497], const double obj_idxDim_data[], const
                   double X[101479], const double queryPt[7], int numNN, double
                   pq_D_data[], int pq_D_size[1], unsigned int pq_I_data[], int
                   pq_I_size[1])
{
  double start_node;
  int exitg1;
  int i;
  static b_struct_T r;
  static unsigned int tmp_data[14497];
  int tmp_size[1];
  int loop_ub;
  int k;
  bool ballIsWithinBounds;
  emxArray_real_T *t1_D;
  double b_obj_lowerBounds_data[7];
  double b_obj_upperBounds_data[7];
  int nodeStack_size_idx_0;
  double nodeStack_data[1450];
  double currentNode;
  double x_data[1023];
  double b_x_data[1023];
  double sumDist;
  bool exitg2;
  double pRadIn;
  static unsigned int t1_I_data[14497];
  start_node = 1.0;
  do {
    exitg1 = 0;
    i = (int)start_node - 1;
    if (!obj_leafNode_data[i]) {
      if (queryPt[(int)obj_cutDim_data[i] - 1] <= obj_cutVal_data[i]) {
        start_node = obj_leftChild_data[i];
      } else {
        start_node = obj_rightChild_data[i];
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxInitStruct_struct_T1(&r);
  r.D->size[0] = 0;
  r.b_I.size[0] = 0;
  getNodeFromArray(obj_idxAll, obj_idxDim_data, start_node, tmp_data, tmp_size);
  search_node(X, queryPt, tmp_data, tmp_size, numNN, &r);
  pq_D_size[0] = r.D->size[0];
  loop_ub = r.D->size[0];
  for (k = 0; k < loop_ub; k++) {
    pq_D_data[k] = r.D->data[k];
  }

  pq_I_size[0] = r.b_I.size[0];
  loop_ub = r.b_I.size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&pq_I_data[0], &r.b_I.data[0], loop_ub * sizeof(unsigned int));
  }

  if (r.D->size[0] != 0) {
    for (k = 0; k < 7; k++) {
      b_obj_lowerBounds_data[k] = obj_lowerBounds_data[i + obj_lowerBounds_size
        [0] * k];
      b_obj_upperBounds_data[k] = obj_upperBounds_data[i + obj_upperBounds_size
        [0] * k];
    }

    ballIsWithinBounds = ball_within_bounds(queryPt, b_obj_lowerBounds_data,
      b_obj_upperBounds_data, r.D->data[r.D->size[0] - 1]);
  } else {
    ballIsWithinBounds = false;
  }

  emxInit_real_T(&t1_D, 1);
  if ((r.D->size[0] != numNN) || (!ballIsWithinBounds)) {
    nodeStack_size_idx_0 = 1;
    nodeStack_data[0] = 1.0;
    while (nodeStack_size_idx_0 != 0) {
      currentNode = nodeStack_data[0];
      if (0 <= nodeStack_size_idx_0 - 1) {
        memcpy(&x_data[0], &nodeStack_data[0], nodeStack_size_idx_0 * sizeof
               (double));
      }

      for (k = 0; k <= nodeStack_size_idx_0 - 2; k++) {
        x_data[k] = x_data[k + 1];
      }

      if (1 > nodeStack_size_idx_0 - 1) {
        loop_ub = 0;
      } else {
        loop_ub = nodeStack_size_idx_0 - 1;
      }

      if (0 <= loop_ub - 1) {
        memcpy(&b_x_data[0], &x_data[0], loop_ub * sizeof(double));
        memcpy(&x_data[0], &b_x_data[0], loop_ub * sizeof(double));
      }

      nodeStack_size_idx_0 = loop_ub;
      if (0 <= loop_ub - 1) {
        memcpy(&nodeStack_data[0], &x_data[0], loop_ub * sizeof(double));
      }

      k = (int)currentNode - 1;
      for (i = 0; i < 7; i++) {
        b_obj_lowerBounds_data[i] = obj_lowerBounds_data[k +
          obj_lowerBounds_size[0] * i];
        b_obj_upperBounds_data[i] = obj_upperBounds_data[k +
          obj_upperBounds_size[0] * i];
      }

      ballIsWithinBounds = true;
      sumDist = 0.0;
      k = 0;
      exitg2 = false;
      while ((!exitg2) && (k < 7)) {
        if (queryPt[k] < b_obj_lowerBounds_data[k]) {
          pRadIn = queryPt[k] - b_obj_lowerBounds_data[k];
          sumDist += pRadIn * pRadIn;
        } else {
          if (queryPt[k] > b_obj_upperBounds_data[k]) {
            pRadIn = queryPt[k] - b_obj_upperBounds_data[k];
            sumDist += pRadIn * pRadIn;
          }
        }

        if (sumDist > pq_D_data[pq_D_size[0] - 1]) {
          ballIsWithinBounds = false;
          exitg2 = true;
        } else {
          k++;
        }
      }

      if ((pq_D_size[0] < numNN) || ballIsWithinBounds) {
        i = (int)currentNode - 1;
        if (!obj_leafNode_data[i]) {
          if (queryPt[(int)obj_cutDim_data[i] - 1] <= obj_cutVal_data[i]) {
            nodeStack_size_idx_0 = loop_ub + 2;
            nodeStack_data[0] = obj_leftChild_data[i];
            nodeStack_data[1] = obj_rightChild_data[i];
            if (0 <= loop_ub - 1) {
              memcpy(&nodeStack_data[2], &x_data[0], loop_ub * sizeof(double));
            }
          } else {
            nodeStack_size_idx_0 = loop_ub + 2;
            nodeStack_data[0] = obj_rightChild_data[i];
            nodeStack_data[1] = obj_leftChild_data[i];
            if (0 <= loop_ub - 1) {
              memcpy(&nodeStack_data[2], &x_data[0], loop_ub * sizeof(double));
            }
          }
        } else {
          if (currentNode != start_node) {
            i = t1_D->size[0];
            t1_D->size[0] = pq_D_size[0];
            emxEnsureCapacity_real_T(t1_D, i);
            loop_ub = pq_D_size[0];
            for (i = 0; i < loop_ub; i++) {
              t1_D->data[i] = pq_D_data[i];
            }

            k = pq_I_size[0];
            loop_ub = pq_I_size[0];
            if (0 <= loop_ub - 1) {
              memcpy(&t1_I_data[0], &pq_I_data[0], loop_ub * sizeof(unsigned int));
            }

            i = r.D->size[0];
            r.D->size[0] = t1_D->size[0];
            emxEnsureCapacity_real_T(r.D, i);
            loop_ub = t1_D->size[0];
            for (i = 0; i < loop_ub; i++) {
              r.D->data[i] = t1_D->data[i];
            }

            r.b_I.size[0] = pq_I_size[0];
            if (0 <= k - 1) {
              memcpy(&r.b_I.data[0], &t1_I_data[0], k * sizeof(unsigned int));
            }

            getNodeFromArray(obj_idxAll, obj_idxDim_data, currentNode, tmp_data,
                             tmp_size);
            search_node(X, queryPt, tmp_data, tmp_size, numNN, &r);
            pq_D_size[0] = r.D->size[0];
            loop_ub = r.D->size[0];
            for (i = 0; i < loop_ub; i++) {
              pq_D_data[i] = r.D->data[i];
            }

            pq_I_size[0] = r.b_I.size[0];
            loop_ub = r.b_I.size[0];
            if (0 <= loop_ub - 1) {
              memcpy(&pq_I_data[0], &r.b_I.data[0], loop_ub * sizeof(unsigned
                      int));
            }
          }
        }
      }
    }
  }

  emxFree_real_T(&t1_D);
  emxFreeStruct_struct_T1(&r);
}

/*
 * File trailer for kdsearchfun.c
 *
 * [EOF]
 */
