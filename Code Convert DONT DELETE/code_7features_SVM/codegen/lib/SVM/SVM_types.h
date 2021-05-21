/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SVM_types.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 08:53:12
 */

#ifndef SVM_TYPES_H
#define SVM_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
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

#ifndef enum_d_classreg_learning_coderutils_
#define enum_d_classreg_learning_coderutils_

enum d_classreg_learning_coderutils_
{
  linear = 1,                          /* Default value */
  gaussian = 2,
  rbf = 2,
  polynomial = 3
};

#endif                                 /*enum_d_classreg_learning_coderutils_*/

#ifndef typedef_d_classreg_learning_coderutils_
#define typedef_d_classreg_learning_coderutils_

typedef enum d_classreg_learning_coderutils_ d_classreg_learning_coderutils_;

#endif                                 /*typedef_d_classreg_learning_coderutils_*/

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

#ifndef struct_emxArray_real_T_2361
#define struct_emxArray_real_T_2361

struct emxArray_real_T_2361
{
  double data[2361];
  int size[1];
};

#endif                                 /*struct_emxArray_real_T_2361*/

#ifndef typedef_emxArray_real_T_2361
#define typedef_emxArray_real_T_2361

typedef struct emxArray_real_T_2361 emxArray_real_T_2361;

#endif                                 /*typedef_emxArray_real_T_2361*/

#ifndef struct_sncFFFgmXQaTh5O9rz2f2C_tag
#define struct_sncFFFgmXQaTh5O9rz2f2C_tag

struct sncFFFgmXQaTh5O9rz2f2C_tag
{
  emxArray_real_T_2361 Alpha;
  double Bias;
  emxArray_real_T *SupportVectorsT;
  double Scale;
  double Order;
  double Mu[7];
  double Sigma[7];
  d_classreg_learning_coderutils_ KernelFunction;
  double ClassNames[2];
  int ClassNamesLength[2];
  c_classreg_learning_coderutils_ ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[4];
};

#endif                                 /*struct_sncFFFgmXQaTh5O9rz2f2C_tag*/

#ifndef typedef_c_classreg_learning_coder_class
#define typedef_c_classreg_learning_coder_class

typedef struct sncFFFgmXQaTh5O9rz2f2C_tag c_classreg_learning_coder_class;

#endif                                 /*typedef_c_classreg_learning_coder_class*/
#endif

/*
 * File trailer for SVM_types.h
 *
 * [EOF]
 */
