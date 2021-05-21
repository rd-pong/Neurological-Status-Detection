/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SVM_emxutil.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 08:53:12
 */

/* Include Files */
#include "SVM_emxutil.h"
#include "SVM.h"
#include "rt_nonfinite.h"
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
static void c_emxFreeStruct_classreg_learni(c_classreg_learning_coder_class
  *pStruct);
static void c_emxInitStruct_classreg_learni(c_classreg_learning_coder_class
  *pStruct);

/* Function Definitions */

/*
 * Arguments    : c_classreg_learning_coder_class *pStruct
 * Return Type  : void
 */
static void c_emxFreeStruct_classreg_learni(c_classreg_learning_coder_class
  *pStruct)
{
  emxFree_real_T(&pStruct->SupportVectorsT);
}

/*
 * Arguments    : c_classreg_learning_coder_class *pStruct
 * Return Type  : void
 */
static void c_emxInitStruct_classreg_learni(c_classreg_learning_coder_class
  *pStruct)
{
  pStruct->Alpha.size[0] = 0;
  emxInit_real_T(&pStruct->SupportVectorsT, 2);
}

/*
 * Arguments    : c_classreg_learning_coder_class pMatrix[6]
 * Return Type  : void
 */
void c_emxFreeMatrix_classreg_learni(c_classreg_learning_coder_class pMatrix[6])
{
  int i;
  for (i = 0; i < 6; i++) {
    c_emxFreeStruct_classreg_learni(&pMatrix[i]);
  }
}

/*
 * Arguments    : c_classreg_learning_coder_class pMatrix[6]
 * Return Type  : void
 */
void c_emxInitMatrix_classreg_learni(c_classreg_learning_coder_class pMatrix[6])
{
  int i;
  for (i = 0; i < 6; i++) {
    c_emxInitStruct_classreg_learni(&pMatrix[i]);
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
 * File trailer for SVM_emxutil.c
 *
 * [EOF]
 */
