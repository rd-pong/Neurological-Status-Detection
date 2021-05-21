/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_feature_extract_api.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 08:47:07
 */

#ifndef _CODER_FEATURE_EXTRACT_API_H
#define _CODER_FEATURE_EXTRACT_API_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_c_matlab_internal_coder_tabular
#define typedef_c_matlab_internal_coder_tabular

typedef struct {
  boolean_T hasLabels;
  boolean_T backwardsCompatibility;
} c_matlab_internal_coder_tabular;

#endif                                 /*typedef_c_matlab_internal_coder_tabular*/

#ifndef struct_emxArray_char_T_1x0
#define struct_emxArray_char_T_1x0

struct emxArray_char_T_1x0
{
  int32_T size[2];
};

#endif                                 /*struct_emxArray_char_T_1x0*/

#ifndef typedef_emxArray_char_T_1x0
#define typedef_emxArray_char_T_1x0

typedef struct emxArray_char_T_1x0 emxArray_char_T_1x0;

#endif                                 /*typedef_emxArray_char_T_1x0*/

#ifndef struct_slLo5y4j6XXk7KEoykxMrL_tag
#define struct_slLo5y4j6XXk7KEoykxMrL_tag

struct slLo5y4j6XXk7KEoykxMrL_tag
{
  emxArray_char_T_1x0 f1;
};

#endif                                 /*struct_slLo5y4j6XXk7KEoykxMrL_tag*/

#ifndef typedef_cell_wrap_3
#define typedef_cell_wrap_3

typedef struct slLo5y4j6XXk7KEoykxMrL_tag cell_wrap_3;

#endif                                 /*typedef_cell_wrap_3*/

#ifndef typedef_d_matlab_internal_coder_tabular
#define typedef_d_matlab_internal_coder_tabular

typedef struct {
  boolean_T hasLabels;
} d_matlab_internal_coder_tabular;

#endif                                 /*typedef_d_matlab_internal_coder_tabular*/

#ifndef typedef_e_matlab_internal_coder_tabular
#define typedef_e_matlab_internal_coder_tabular

typedef uint8_T e_matlab_internal_coder_tabular;

#endif                                 /*typedef_e_matlab_internal_coder_tabular*/

#ifndef e_matlab_internal_coder_tabular_constants
#define e_matlab_internal_coder_tabular_constants

/* enum e_matlab_internal_coder_tabular */
#define unset                          ((e_matlab_internal_coder_tabular)0U)
#define continuous                     ((e_matlab_internal_coder_tabular)1U)
#define step                           ((e_matlab_internal_coder_tabular)2U)
#define event                          ((e_matlab_internal_coder_tabular)3U)
#endif                                 /*e_matlab_internal_coder_tabular_constants*/

#ifndef struct_emxArray_char_T_0x0
#define struct_emxArray_char_T_0x0

struct emxArray_char_T_0x0
{
  int32_T size[2];
};

#endif                                 /*struct_emxArray_char_T_0x0*/

#ifndef typedef_emxArray_char_T_0x0
#define typedef_emxArray_char_T_0x0

typedef struct emxArray_char_T_0x0 emxArray_char_T_0x0;

#endif                                 /*typedef_emxArray_char_T_0x0*/

#ifndef struct_sGcG4EbgjSGxFwEsWd6HiTB_tag
#define struct_sGcG4EbgjSGxFwEsWd6HiTB_tag

struct sGcG4EbgjSGxFwEsWd6HiTB_tag
{
  boolean_T hasLabels;
  cell_wrap_3 descrs[7];
  cell_wrap_3 units[7];
  e_matlab_internal_coder_tabular continuity[7];
  boolean_T hasDescrs;
  boolean_T hasUnits;
  boolean_T hasContinuity;
  boolean_T hasCustomProps;
};

#endif                                 /*struct_sGcG4EbgjSGxFwEsWd6HiTB_tag*/

#ifndef typedef_f_matlab_internal_coder_tabular
#define typedef_f_matlab_internal_coder_tabular

typedef struct sGcG4EbgjSGxFwEsWd6HiTB_tag f_matlab_internal_coder_tabular;

#endif                                 /*typedef_f_matlab_internal_coder_tabular*/

#ifndef struct_sETWvvlNf2x0WVO89J1448_tag
#define struct_sETWvvlNf2x0WVO89J1448_tag

struct sETWvvlNf2x0WVO89J1448_tag
{
  emxArray_char_T_0x0 Description;
};

#endif                                 /*struct_sETWvvlNf2x0WVO89J1448_tag*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct sETWvvlNf2x0WVO89J1448_tag struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef struct_skW2kD1LDYnkjSzoI8X1e5C_tag
#define struct_skW2kD1LDYnkjSzoI8X1e5C_tag

struct skW2kD1LDYnkjSzoI8X1e5C_tag
{
  c_matlab_internal_coder_tabular metaDim;
  d_matlab_internal_coder_tabular rowDim;
  f_matlab_internal_coder_tabular varDim;
  real_T data[7];
  struct0_T arrayProps;
};

#endif                                 /*struct_skW2kD1LDYnkjSzoI8X1e5C_tag*/

#ifndef typedef_matlab_internal_coder_table
#define typedef_matlab_internal_coder_table

typedef struct skW2kD1LDYnkjSzoI8X1e5C_tag matlab_internal_coder_table;

#endif                                 /*typedef_matlab_internal_coder_table*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void feature_extract(real_T frame_AccTempEDA[240], real_T frame_SpO2HR[12],
  matlab_internal_coder_table *output);
extern void feature_extract_api(const mxArray * const prhs[2], int32_T nlhs,
  const mxArray *plhs[1]);
extern void feature_extract_atexit(void);
extern void feature_extract_initialize(void);
extern void feature_extract_terminate(void);
extern void feature_extract_xil_shutdown(void);
extern void feature_extract_xil_terminate(void);

#endif

/*
 * File trailer for _coder_feature_extract_api.h
 *
 * [EOF]
 */
