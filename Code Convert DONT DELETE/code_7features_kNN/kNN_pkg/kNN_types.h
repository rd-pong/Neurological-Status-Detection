/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: kNN_types.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 06-May-2021 23:36:41
 */

#ifndef KNN_TYPES_H
#define KNN_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  bool canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef struct_emxArray_uint32_T_14497
#define struct_emxArray_uint32_T_14497

struct emxArray_uint32_T_14497
{
  unsigned int data[14497];
  int size[1];
};

#endif                                 /*struct_emxArray_uint32_T_14497*/

#ifndef typedef_emxArray_uint32_T_14497
#define typedef_emxArray_uint32_T_14497

typedef struct emxArray_uint32_T_14497 emxArray_uint32_T_14497;

#endif                                 /*typedef_emxArray_uint32_T_14497*/

#ifndef struct_szNA0l1PUggxJhLmvwY0yLD_tag
#define struct_szNA0l1PUggxJhLmvwY0yLD_tag

struct szNA0l1PUggxJhLmvwY0yLD_tag
{
  emxArray_real_T *D;
  emxArray_uint32_T_14497 b_I;
};

#endif                                 /*struct_szNA0l1PUggxJhLmvwY0yLD_tag*/

#ifndef typedef_b_struct_T
#define typedef_b_struct_T

typedef struct szNA0l1PUggxJhLmvwY0yLD_tag b_struct_T;

#endif                                 /*typedef_b_struct_T*/

#ifndef enum_c_classreg_learning_coderutils_
#define enum_c_classreg_learning_coderutils_

enum c_classreg_learning_coderutils_
{
  Logit = 0,                           /* Default value */
  Doublelogit,
  Invlogit,
  Ismax,
  Sign,
  Symmetric,
  Symmetricismax,
  Symmetriclogit,
  Identity
};

#endif                                 /*enum_c_classreg_learning_coderutils_*/

#ifndef typedef_c_classreg_learning_coderutils_
#define typedef_c_classreg_learning_coderutils_

typedef enum c_classreg_learning_coderutils_ c_classreg_learning_coderutils_;

#endif                                 /*typedef_c_classreg_learning_coderutils_*/

#ifndef typedef_c_classreg_learning_coder_class
#define typedef_c_classreg_learning_coder_class

typedef struct {
  double ClassNames[4];
  int ClassNamesLength[4];
  c_classreg_learning_coderutils_ ScoreTransform;
  double Prior[4];
  bool ClassLogicalIndices[4];
  double Cost[16];
  double X[101479];
  unsigned int YIdx[14497];
  double W[14497];
  double Mu[7];
  double Sigma[7];
} c_classreg_learning_coder_class;

#endif                                 /*typedef_c_classreg_learning_coder_class*/

#ifndef struct_shuKBxKl6ch3I8L2iLz6UOF_tag
#define struct_shuKBxKl6ch3I8L2iLz6UOF_tag

struct shuKBxKl6ch3I8L2iLz6UOF_tag
{
  emxArray_real_T *f1;
};

#endif                                 /*struct_shuKBxKl6ch3I8L2iLz6UOF_tag*/

#ifndef typedef_cell_wrap_31
#define typedef_cell_wrap_31

typedef struct shuKBxKl6ch3I8L2iLz6UOF_tag cell_wrap_31;

#endif                                 /*typedef_cell_wrap_31*/

#ifndef struct_emxArray_boolean_T_1023
#define struct_emxArray_boolean_T_1023

struct emxArray_boolean_T_1023
{
  bool data[1023];
  int size[1];
};

#endif                                 /*struct_emxArray_boolean_T_1023*/

#ifndef typedef_emxArray_boolean_T_1023
#define typedef_emxArray_boolean_T_1023

typedef struct emxArray_boolean_T_1023 emxArray_boolean_T_1023;

#endif                                 /*typedef_emxArray_boolean_T_1023*/

#ifndef struct_c_emxArray_shuKBxKl6ch3I8L2iLz6
#define struct_c_emxArray_shuKBxKl6ch3I8L2iLz6

struct c_emxArray_shuKBxKl6ch3I8L2iLz6
{
  cell_wrap_31 data[1023];
  int size[1];
};

#endif                                 /*struct_c_emxArray_shuKBxKl6ch3I8L2iLz6*/

#ifndef typedef_emxArray_cell_wrap_31_1023
#define typedef_emxArray_cell_wrap_31_1023

typedef struct c_emxArray_shuKBxKl6ch3I8L2iLz6 emxArray_cell_wrap_31_1023;

#endif                                 /*typedef_emxArray_cell_wrap_31_1023*/

#ifndef struct_emxArray_real_T_1023
#define struct_emxArray_real_T_1023

struct emxArray_real_T_1023
{
  double data[1023];
  int size[1];
};

#endif                                 /*struct_emxArray_real_T_1023*/

#ifndef typedef_emxArray_real_T_1023
#define typedef_emxArray_real_T_1023

typedef struct emxArray_real_T_1023 emxArray_real_T_1023;

#endif                                 /*typedef_emxArray_real_T_1023*/

#ifndef struct_emxArray_real_T_1023x7
#define struct_emxArray_real_T_1023x7

struct emxArray_real_T_1023x7
{
  double data[7161];
  int size[2];
};

#endif                                 /*struct_emxArray_real_T_1023x7*/

#ifndef typedef_emxArray_real_T_1023x7
#define typedef_emxArray_real_T_1023x7

typedef struct emxArray_real_T_1023x7 emxArray_real_T_1023x7;

#endif                                 /*typedef_emxArray_real_T_1023x7*/

#ifndef struct_stvgLq9VtwvB7YVAS4vG9mD_tag
#define struct_stvgLq9VtwvB7YVAS4vG9mD_tag

struct stvgLq9VtwvB7YVAS4vG9mD_tag
{
  double X[101479];
  char Distance[9];
  double BucketSize;
  emxArray_real_T *wasnanIdx;
  int numNodes;
  emxArray_real_T_1023 cutDim;
  emxArray_real_T_1023 cutVal;
  emxArray_real_T_1023x7 lowerBounds;
  emxArray_real_T_1023x7 upperBounds;
  emxArray_real_T_1023 leftChild;
  emxArray_real_T_1023 rightChild;
  emxArray_boolean_T_1023 leafNode;
  double nx_nonan;
  unsigned int idxAll[14497];
  emxArray_real_T_1023 idxDim;
};

#endif                                 /*struct_stvgLq9VtwvB7YVAS4vG9mD_tag*/

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct stvgLq9VtwvB7YVAS4vG9mD_tag struct_T;

#endif                                 /*typedef_struct_T*/
#endif

/*
 * File trailer for kNN_types.h
 *
 * [EOF]
 */
