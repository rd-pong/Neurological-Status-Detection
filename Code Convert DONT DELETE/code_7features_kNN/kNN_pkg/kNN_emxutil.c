/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: kNN_emxutil.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 06-May-2021 23:36:41
 */

/* Include Files */
#include "kNN_emxutil.h"
#include "kNN.h"
#include "rt_nonfinite.h"
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
static void emxExpand_cell_wrap_31_1023(cell_wrap_31 data[1023], int fromIndex,
  int toIndex);
static void emxFreeStruct_cell_wrap_31(cell_wrap_31 *pStruct);
static void emxInitStruct_cell_wrap_31(cell_wrap_31 *pStruct);
static void emxTrim_cell_wrap_31_1023(cell_wrap_31 data[1023], int fromIndex,
  int toIndex);

/* Function Definitions */

/*
 * Arguments    : cell_wrap_31 data[1023]
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxExpand_cell_wrap_31_1023(cell_wrap_31 data[1023], int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_31(&data[i]);
  }
}

/*
 * Arguments    : cell_wrap_31 *pStruct
 * Return Type  : void
 */
static void emxFreeStruct_cell_wrap_31(cell_wrap_31 *pStruct)
{
  emxFree_real_T(&pStruct->f1);
}

/*
 * Arguments    : cell_wrap_31 *pStruct
 * Return Type  : void
 */
static void emxInitStruct_cell_wrap_31(cell_wrap_31 *pStruct)
{
  emxInit_real_T(&pStruct->f1, 2);
}

/*
 * Arguments    : cell_wrap_31 data[1023]
 *                int fromIndex
 *                int toIndex
 * Return Type  : void
 */
static void emxTrim_cell_wrap_31_1023(cell_wrap_31 data[1023], int fromIndex,
  int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_31(&data[i]);
  }
}

/*
 * Arguments    : cell_wrap_31 data[1023]
 *                const int size[1]
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_cell_wrap_31(cell_wrap_31 data[1023], const int size[1],
  int oldNumel)
{
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  if (oldNumel > size[0]) {
    emxTrim_cell_wrap_31_1023(data, size[0], oldNumel);
  } else {
    if (oldNumel < size[0]) {
      emxExpand_cell_wrap_31_1023(data, oldNumel, size[0]);
    }
  }
}

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int oldNumel
 * Return Type  : void
 */
void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }

    newData = calloc((unsigned int)i, sizeof(double));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(double) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (double *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T(struct_T *pStruct)
{
  emxFree_real_T(&pStruct->wasnanIdx);
}

/*
 * Arguments    : b_struct_T *pStruct
 * Return Type  : void
 */
void emxFreeStruct_struct_T1(b_struct_T *pStruct)
{
  emxFree_real_T(&pStruct->D);
}

/*
 * Arguments    : emxArray_cell_wrap_31_1023 *pEmxArray
 * Return Type  : void
 */
void emxFree_cell_wrap_31_1023(emxArray_cell_wrap_31_1023 *pEmxArray)
{
  int numEl;
  int i;
  numEl = 1;
  for (i = 0; i < 1; i++) {
    numEl *= pEmxArray->size[0];
  }

  for (i = 0; i < numEl; i++) {
    emxFreeStruct_cell_wrap_31(&pEmxArray->data[i]);
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (double *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T(struct_T *pStruct)
{
  emxInit_real_T(&pStruct->wasnanIdx, 2);
  pStruct->cutDim.size[0] = 0;
  pStruct->cutVal.size[0] = 0;
  pStruct->lowerBounds.size[0] = 0;
  pStruct->lowerBounds.size[1] = 0;
  pStruct->upperBounds.size[0] = 0;
  pStruct->upperBounds.size[1] = 0;
  pStruct->leftChild.size[0] = 0;
  pStruct->rightChild.size[0] = 0;
  pStruct->leafNode.size[0] = 0;
  pStruct->idxDim.size[0] = 0;
}

/*
 * Arguments    : b_struct_T *pStruct
 * Return Type  : void
 */
void emxInitStruct_struct_T1(b_struct_T *pStruct)
{
  emxInit_real_T(&pStruct->D, 1);
  pStruct->b_I.size[0] = 0;
}

/*
 * Arguments    : emxArray_cell_wrap_31_1023 *pEmxArray
 * Return Type  : void
 */
void emxInit_cell_wrap_31_1023(emxArray_cell_wrap_31_1023 *pEmxArray)
{
  pEmxArray->size[0] = 0;
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxArray_real_T *emxArray;
  int i;
  *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
  emxArray = *pEmxArray;
  emxArray->data = (double *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * File trailer for kNN_emxutil.c
 *
 * [EOF]
 */
