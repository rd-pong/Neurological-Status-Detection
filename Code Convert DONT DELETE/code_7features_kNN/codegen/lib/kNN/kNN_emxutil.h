/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: kNN_emxutil.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 06-May-2021 23:36:41
 */

#ifndef KNN_EMXUTIL_H
#define KNN_EMXUTIL_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "kNN_types.h"

/* Function Declarations */
extern void emxEnsureCapacity_cell_wrap_31(cell_wrap_31 data[1023], const int
  size[1], int oldNumel);
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);
extern void emxFreeStruct_struct_T(struct_T *pStruct);
extern void emxFreeStruct_struct_T1(b_struct_T *pStruct);
extern void emxFree_cell_wrap_31_1023(emxArray_cell_wrap_31_1023 *pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInitStruct_struct_T(struct_T *pStruct);
extern void emxInitStruct_struct_T1(b_struct_T *pStruct);
extern void emxInit_cell_wrap_31_1023(emxArray_cell_wrap_31_1023 *pEmxArray);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

/*
 * File trailer for kNN_emxutil.h
 *
 * [EOF]
 */
