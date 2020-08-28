/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: feature_extract_types.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 11:34:10
 */

#ifndef FEATURE_EXTRACT_TYPES_H
#define FEATURE_EXTRACT_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c_matlab_internal_coder_tabular
#define typedef_c_matlab_internal_coder_tabular

typedef struct {
  bool hasLabels;
  bool backwardsCompatibility;
} c_matlab_internal_coder_tabular;

#endif                                 /*typedef_c_matlab_internal_coder_tabular*/

#ifndef struct_emxArray_char_T_1x0
#define struct_emxArray_char_T_1x0

struct emxArray_char_T_1x0
{
  int size[2];
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
  bool hasLabels;
} d_matlab_internal_coder_tabular;

#endif                                 /*typedef_d_matlab_internal_coder_tabular*/

#ifndef typedef_e_matlab_internal_coder_tabular
#define typedef_e_matlab_internal_coder_tabular

typedef unsigned char e_matlab_internal_coder_tabular;

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
  int size[2];
};

#endif                                 /*struct_emxArray_char_T_0x0*/

#ifndef typedef_emxArray_char_T_0x0
#define typedef_emxArray_char_T_0x0

typedef struct emxArray_char_T_0x0 emxArray_char_T_0x0;

#endif                                 /*typedef_emxArray_char_T_0x0*/

#ifndef struct_s2APwg4oggURCdMUvVZZ4_tag
#define struct_s2APwg4oggURCdMUvVZZ4_tag

struct s2APwg4oggURCdMUvVZZ4_tag
{
  bool hasLabels;
  cell_wrap_3 descrs[28];
  cell_wrap_3 units[28];
  e_matlab_internal_coder_tabular continuity[28];
  bool hasDescrs;
  bool hasUnits;
  bool hasContinuity;
  bool hasCustomProps;
};

#endif                                 /*struct_s2APwg4oggURCdMUvVZZ4_tag*/

#ifndef typedef_f_matlab_internal_coder_tabular
#define typedef_f_matlab_internal_coder_tabular

typedef struct s2APwg4oggURCdMUvVZZ4_tag f_matlab_internal_coder_tabular;

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

#ifndef struct_sRoqwTFsKR1miE3qfLfJHRD_tag
#define struct_sRoqwTFsKR1miE3qfLfJHRD_tag

struct sRoqwTFsKR1miE3qfLfJHRD_tag
{
  c_matlab_internal_coder_tabular metaDim;
  d_matlab_internal_coder_tabular rowDim;
  f_matlab_internal_coder_tabular varDim;
  double data[28];
  struct0_T arrayProps;
};

#endif                                 /*struct_sRoqwTFsKR1miE3qfLfJHRD_tag*/

#ifndef typedef_matlab_internal_coder_table
#define typedef_matlab_internal_coder_table

typedef struct sRoqwTFsKR1miE3qfLfJHRD_tag matlab_internal_coder_table;

#endif                                 /*typedef_matlab_internal_coder_table*/
#endif

/*
 * File trailer for feature_extract_types.h
 *
 * [EOF]
 */
