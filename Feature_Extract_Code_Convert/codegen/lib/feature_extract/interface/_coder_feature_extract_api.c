/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_feature_extract_api.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 11:34:10
 */

/* Include Files */
#include "_coder_feature_extract_api.h"
#include "_coder_feature_extract_mex.h"

/* Type Definitions */
#ifndef typedef_cell_2
#define typedef_cell_2

typedef struct {
  char_T f1[8];
  char_T f2[7];
  char_T f3[7];
  char_T f4[10];
  char_T f5[8];
  char_T f6[7];
  char_T f7[7];
  char_T f8[10];
  char_T f9[8];
  char_T f10[7];
  char_T f11[7];
  char_T f12[10];
  char_T f13[9];
  char_T f14[8];
  char_T f15[8];
  char_T f16[11];
  char_T f17[8];
  char_T f18[7];
  char_T f19[7];
  char_T f20[10];
  char_T f21[9];
  char_T f22[7];
  char_T f23[8];
  char_T f24[11];
  char_T f25[7];
  char_T f26[6];
  char_T f27[6];
  char_T f28[9];
} cell_2;

#endif                                 /*typedef_cell_2*/

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131483U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "feature_extract",                   /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[240];
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const
  f_matlab_internal_coder_tabular *u);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *frame_SpO2HR, const char_T *identifier))[12];
static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp, const cell_2 *u);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[12];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[240];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *frame_AccTempEDA, const char_T *identifier))[240];
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const
  matlab_internal_coder_table *u);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[12];

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[240]
 */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[240]
{
  real_T (*y)[240];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const f_matlab_internal_coder_tabular *u
 * Return Type  : const mxArray *
 */
  static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const
  f_matlab_internal_coder_tabular *u)
{
  const mxArray *y;
  const mxArray *m;
  const mxArray *b_y;
  const mxArray *m1;
  const mxArray *propValues[11];
  int32_T i;
  cell_2 r;
  static const char_T cv[8] = { 'a', 'c', 'x', '_', 'm', 'e', 'a', 'n' };

  static const char_T cv1[7] = { 'a', 'c', 'x', '_', 'm', 'a', 'x' };

  static const char_T cv2[7] = { 'a', 'c', 'x', '_', 'm', 'i', 'n' };

  static const char_T cv3[10] = { 'a', 'c', 'x', '_', 'c', 'h', 'a', 'n', 'g',
    'e' };

  static const char_T cv4[8] = { 'a', 'c', 'y', '_', 'm', 'e', 'a', 'n' };

  static const char_T cv5[7] = { 'a', 'c', 'y', '_', 'm', 'a', 'x' };

  static const char_T cv6[7] = { 'a', 'c', 'y', '_', 'm', 'i', 'n' };

  static const char_T cv7[10] = { 'a', 'c', 'y', '_', 'c', 'h', 'a', 'n', 'g',
    'e' };

  static const char_T cv8[8] = { 'a', 'c', 'z', '_', 'm', 'e', 'a', 'n' };

  static const char_T cv9[7] = { 'a', 'c', 'z', '_', 'm', 'a', 'x' };

  static const char_T cv10[7] = { 'a', 'c', 'z', '_', 'm', 'i', 'n' };

  static const char_T cv11[10] = { 'a', 'c', 'z', '_', 'c', 'h', 'a', 'n', 'g',
    'e' };

  static const char_T cv12[9] = { 't', 'e', 'm', 'p', '_', 'm', 'e', 'a', 'n' };

  static const char_T cv13[8] = { 't', 'e', 'm', 'p', '_', 'm', 'a', 'x' };

  static const char_T cv14[8] = { 't', 'e', 'm', 'p', '_', 'm', 'i', 'n' };

  static const char_T cv15[11] = { 't', 'e', 'm', 'p', '_', 'c', 'h', 'a', 'n',
    'g', 'e' };

  static const char_T cv16[8] = { 'E', 'D', 'A', '_', 'm', 'e', 'a', 'n' };

  static const char_T cv17[7] = { 'E', 'D', 'A', '_', 'm', 'a', 'x' };

  static const char_T cv18[7] = { 'E', 'D', 'A', '_', 'm', 'i', 'n' };

  static const char_T cv19[10] = { 'E', 'D', 'A', '_', 'c', 'h', 'a', 'n', 'g',
    'e' };

  static const char_T cv20[9] = { 'S', 'P', 'O', '2', '_', 'm', 'e', 'a', 'n' };

  static const char_T cv21[7] = { 'P', 'O', '2', '_', 'm', 'a', 'x' };

  static const char_T cv22[8] = { 'S', 'P', 'O', '2', '_', 'm', 'i', 'n' };

  static const char_T cv23[11] = { 'S', 'P', 'O', '2', '_', 'c', 'h', 'a', 'n',
    'g', 'e' };

  static const char_T cv24[7] = { 'H', 'R', '_', 'm', 'e', 'a', 'n' };

  static const char_T cv25[6] = { 'H', 'R', '_', 'm', 'a', 'x' };

  static const char_T cv26[6] = { 'H', 'R', '_', 'm', 'i', 'n' };

  static const char_T cv27[9] = { 'H', 'R', '_', 'c', 'h', 'a', 'n', 'g', 'e' };

  int32_T iv[2];
  const mxArray *c_y;
  static const char * enumNames[4] = { "unset", "continuous", "step", "event" };

  static const int32_T enumValues[4] = { 0, 1, 2, 3 };

  uint8_T b_u[28];
  const mxArray *m2;
  static const int32_T iv1[2] = { 1, 28 };

  uint8_T *pData;
  int32_T b_i;
  const char * propNames[11] = { "length", "hasLabels", "labels", "descrs",
    "units", "continuity", "customProps", "hasDescrs", "hasUnits",
    "hasContinuity", "hasCustomProps" };

  const char * propClasses[11] = {
    "matlab.internal.coder.tabular.private.tabularDimension",
    "matlab.internal.coder.tabular.private.tabularDimension",
    "matlab.internal.coder.tabular.private.varNamesDim",
    "matlab.internal.coder.tabular.private.varNamesDim",
    "matlab.internal.coder.tabular.private.varNamesDim",
    "matlab.internal.coder.tabular.private.varNamesDim",
    "matlab.internal.coder.tabular.private.varNamesDim",
    "matlab.internal.coder.tabular.private.varNamesDim",
    "matlab.internal.coder.tabular.private.varNamesDim",
    "matlab.internal.coder.tabular.private.varNamesDim",
    "matlab.internal.coder.tabular.private.varNamesDim" };

  y = NULL;
  emlrtAssign(&y, emlrtCreateClassInstance(
    "matlab.internal.coder.tabular.private.varNamesDim"));
  m = NULL;
  b_y = NULL;
  m1 = emlrtCreateDoubleScalar(28.0);
  emlrtAssign(&b_y, m1);
  emlrtAssign(&m, b_y);
  propValues[0] = m;
  m = NULL;
  b_y = NULL;
  m1 = emlrtCreateLogicalScalar(u->hasLabels);
  emlrtAssign(&b_y, m1);
  emlrtAssign(&m, b_y);
  propValues[1] = m;
  for (i = 0; i < 8; i++) {
    r.f1[i] = cv[i];
  }

  for (i = 0; i < 7; i++) {
    r.f2[i] = cv1[i];
    r.f3[i] = cv2[i];
  }

  for (i = 0; i < 10; i++) {
    r.f4[i] = cv3[i];
  }

  for (i = 0; i < 8; i++) {
    r.f5[i] = cv4[i];
  }

  for (i = 0; i < 7; i++) {
    r.f6[i] = cv5[i];
    r.f7[i] = cv6[i];
  }

  for (i = 0; i < 10; i++) {
    r.f8[i] = cv7[i];
  }

  for (i = 0; i < 8; i++) {
    r.f9[i] = cv8[i];
  }

  for (i = 0; i < 7; i++) {
    r.f10[i] = cv9[i];
    r.f11[i] = cv10[i];
  }

  for (i = 0; i < 10; i++) {
    r.f12[i] = cv11[i];
  }

  for (i = 0; i < 9; i++) {
    r.f13[i] = cv12[i];
  }

  for (i = 0; i < 8; i++) {
    r.f14[i] = cv13[i];
    r.f15[i] = cv14[i];
  }

  for (i = 0; i < 11; i++) {
    r.f16[i] = cv15[i];
  }

  for (i = 0; i < 8; i++) {
    r.f17[i] = cv16[i];
  }

  for (i = 0; i < 7; i++) {
    r.f18[i] = cv17[i];
    r.f19[i] = cv18[i];
  }

  for (i = 0; i < 10; i++) {
    r.f20[i] = cv19[i];
  }

  for (i = 0; i < 9; i++) {
    r.f21[i] = cv20[i];
  }

  for (i = 0; i < 7; i++) {
    r.f22[i] = cv21[i];
  }

  for (i = 0; i < 8; i++) {
    r.f23[i] = cv22[i];
  }

  for (i = 0; i < 11; i++) {
    r.f24[i] = cv23[i];
  }

  for (i = 0; i < 7; i++) {
    r.f25[i] = cv24[i];
  }

  for (i = 0; i < 6; i++) {
    r.f26[i] = cv25[i];
    r.f27[i] = cv26[i];
  }

  for (i = 0; i < 9; i++) {
    r.f28[i] = cv27[i];
  }

  m = NULL;
  emlrtAssign(&m, c_emlrt_marshallOut(sp, &r));
  propValues[2] = m;
  m = NULL;
  b_y = NULL;
  iv[0] = 1;
  iv[1] = 28;
  emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(2, iv));
  for (i = 0; i < 28; i++) {
    c_y = NULL;
    iv[0] = 1;
    iv[1] = 0;
    m1 = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(sp, 0, m1, NULL);
    emlrtAssign(&c_y, m1);
    emlrtSetCell(b_y, i, c_y);
  }

  emlrtAssign(&m, b_y);
  propValues[3] = m;
  m = NULL;
  b_y = NULL;
  iv[0] = 1;
  iv[1] = 28;
  emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(2, iv));
  for (i = 0; i < 28; i++) {
    c_y = NULL;
    iv[0] = 1;
    iv[1] = 0;
    m1 = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(sp, 0, m1, NULL);
    emlrtAssign(&c_y, m1);
    emlrtSetCell(b_y, i, c_y);
  }

  emlrtAssign(&m, b_y);
  propValues[4] = m;
  m = NULL;
  b_y = NULL;
  m1 = NULL;
  emlrtCheckEnumR2012b(sp, "matlab.internal.coder.tabular.Continuity", 4,
                       enumNames, enumValues);
  for (i = 0; i < 28; i++) {
    b_u[i] = u->continuity[i];
  }

  c_y = NULL;
  m2 = emlrtCreateNumericArray(2, iv1, mxUINT8_CLASS, mxREAL);
  pData = (uint8_T *)emlrtMxGetData(m2);
  i = 0;
  for (b_i = 0; b_i < 28; b_i++) {
    pData[i] = b_u[b_i];
    i++;
  }

  emlrtAssign(&c_y, m2);
  emlrtAssign(&m1, c_y);
  emlrtAssign(&b_y, emlrtCreateEnumR2012b(sp,
    "matlab.internal.coder.tabular.Continuity", m1));
  emlrtDestroyArray(&m1);
  emlrtAssign(&m, b_y);
  propValues[5] = m;
  m = NULL;
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  emlrtAssign(&m, b_y);
  propValues[6] = m;
  m = NULL;
  b_y = NULL;
  m1 = emlrtCreateLogicalScalar(u->hasDescrs);
  emlrtAssign(&b_y, m1);
  emlrtAssign(&m, b_y);
  propValues[7] = m;
  m = NULL;
  b_y = NULL;
  m1 = emlrtCreateLogicalScalar(u->hasUnits);
  emlrtAssign(&b_y, m1);
  emlrtAssign(&m, b_y);
  propValues[8] = m;
  m = NULL;
  b_y = NULL;
  m1 = emlrtCreateLogicalScalar(u->hasContinuity);
  emlrtAssign(&b_y, m1);
  emlrtAssign(&m, b_y);
  propValues[9] = m;
  m = NULL;
  b_y = NULL;
  m1 = emlrtCreateLogicalScalar(u->hasCustomProps);
  emlrtAssign(&b_y, m1);
  emlrtAssign(&m, b_y);
  propValues[10] = m;
  emlrtSetAllProperties(sp, &y, 0, 11, propNames, propClasses, propValues);
  emlrtAssign(&y, emlrtConvertInstanceToRedirectSource(sp, y, 0,
    "matlab.internal.coder.tabular.private.varNamesDim"));
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *frame_SpO2HR
 *                const char_T *identifier
 * Return Type  : real_T (*)[12]
 */
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *frame_SpO2HR, const char_T *identifier))[12]
{
  real_T (*y)[12];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(frame_SpO2HR), &thisId);
  emlrtDestroyArray(&frame_SpO2HR);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const cell_2 *u
 * Return Type  : const mxArray *
 */
  static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp, const cell_2
  *u)
{
  const mxArray *y;
  int32_T iv[2];
  int32_T i;
  const mxArray *b_y;
  char_T b_u[8];
  const mxArray *m;
  static const int32_T iv1[2] = { 1, 8 };

  char_T c_u[7];
  static const int32_T iv2[2] = { 1, 7 };

  static const int32_T iv3[2] = { 1, 7 };

  char_T d_u[10];
  static const int32_T iv4[2] = { 1, 10 };

  static const int32_T iv5[2] = { 1, 8 };

  static const int32_T iv6[2] = { 1, 7 };

  static const int32_T iv7[2] = { 1, 7 };

  static const int32_T iv8[2] = { 1, 10 };

  static const int32_T iv9[2] = { 1, 8 };

  static const int32_T iv10[2] = { 1, 7 };

  static const int32_T iv11[2] = { 1, 7 };

  static const int32_T iv12[2] = { 1, 10 };

  char_T e_u[9];
  static const int32_T iv13[2] = { 1, 9 };

  static const int32_T iv14[2] = { 1, 8 };

  static const int32_T iv15[2] = { 1, 8 };

  char_T f_u[11];
  static const int32_T iv16[2] = { 1, 11 };

  static const int32_T iv17[2] = { 1, 8 };

  static const int32_T iv18[2] = { 1, 7 };

  static const int32_T iv19[2] = { 1, 7 };

  static const int32_T iv20[2] = { 1, 10 };

  static const int32_T iv21[2] = { 1, 9 };

  static const int32_T iv22[2] = { 1, 7 };

  static const int32_T iv23[2] = { 1, 8 };

  static const int32_T iv24[2] = { 1, 11 };

  static const int32_T iv25[2] = { 1, 7 };

  char_T g_u[6];
  static const int32_T iv26[2] = { 1, 6 };

  static const int32_T iv27[2] = { 1, 6 };

  static const int32_T iv28[2] = { 1, 9 };

  y = NULL;
  iv[0] = 1;
  iv[1] = 28;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, iv));
  for (i = 0; i < 8; i++) {
    b_u[i] = u->f1[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv1);
  emlrtInitCharArrayR2013a(sp, 8, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 0, b_y);
  for (i = 0; i < 7; i++) {
    c_u[i] = u->f2[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv2);
  emlrtInitCharArrayR2013a(sp, 7, m, &c_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 1, b_y);
  for (i = 0; i < 7; i++) {
    c_u[i] = u->f3[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv3);
  emlrtInitCharArrayR2013a(sp, 7, m, &c_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 2, b_y);
  for (i = 0; i < 10; i++) {
    d_u[i] = u->f4[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv4);
  emlrtInitCharArrayR2013a(sp, 10, m, &d_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 3, b_y);
  for (i = 0; i < 8; i++) {
    b_u[i] = u->f5[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv5);
  emlrtInitCharArrayR2013a(sp, 8, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 4, b_y);
  for (i = 0; i < 7; i++) {
    c_u[i] = u->f6[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv6);
  emlrtInitCharArrayR2013a(sp, 7, m, &c_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 5, b_y);
  for (i = 0; i < 7; i++) {
    c_u[i] = u->f7[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv7);
  emlrtInitCharArrayR2013a(sp, 7, m, &c_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 6, b_y);
  for (i = 0; i < 10; i++) {
    d_u[i] = u->f8[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv8);
  emlrtInitCharArrayR2013a(sp, 10, m, &d_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 7, b_y);
  for (i = 0; i < 8; i++) {
    b_u[i] = u->f9[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv9);
  emlrtInitCharArrayR2013a(sp, 8, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 8, b_y);
  for (i = 0; i < 7; i++) {
    c_u[i] = u->f10[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv10);
  emlrtInitCharArrayR2013a(sp, 7, m, &c_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 9, b_y);
  for (i = 0; i < 7; i++) {
    c_u[i] = u->f11[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv11);
  emlrtInitCharArrayR2013a(sp, 7, m, &c_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 10, b_y);
  for (i = 0; i < 10; i++) {
    d_u[i] = u->f12[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv12);
  emlrtInitCharArrayR2013a(sp, 10, m, &d_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 11, b_y);
  for (i = 0; i < 9; i++) {
    e_u[i] = u->f13[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv13);
  emlrtInitCharArrayR2013a(sp, 9, m, &e_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 12, b_y);
  for (i = 0; i < 8; i++) {
    b_u[i] = u->f14[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv14);
  emlrtInitCharArrayR2013a(sp, 8, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 13, b_y);
  for (i = 0; i < 8; i++) {
    b_u[i] = u->f15[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv15);
  emlrtInitCharArrayR2013a(sp, 8, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 14, b_y);
  for (i = 0; i < 11; i++) {
    f_u[i] = u->f16[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv16);
  emlrtInitCharArrayR2013a(sp, 11, m, &f_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 15, b_y);
  for (i = 0; i < 8; i++) {
    b_u[i] = u->f17[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv17);
  emlrtInitCharArrayR2013a(sp, 8, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 16, b_y);
  for (i = 0; i < 7; i++) {
    c_u[i] = u->f18[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv18);
  emlrtInitCharArrayR2013a(sp, 7, m, &c_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 17, b_y);
  for (i = 0; i < 7; i++) {
    c_u[i] = u->f19[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv19);
  emlrtInitCharArrayR2013a(sp, 7, m, &c_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 18, b_y);
  for (i = 0; i < 10; i++) {
    d_u[i] = u->f20[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv20);
  emlrtInitCharArrayR2013a(sp, 10, m, &d_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 19, b_y);
  for (i = 0; i < 9; i++) {
    e_u[i] = u->f21[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv21);
  emlrtInitCharArrayR2013a(sp, 9, m, &e_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 20, b_y);
  for (i = 0; i < 7; i++) {
    c_u[i] = u->f22[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv22);
  emlrtInitCharArrayR2013a(sp, 7, m, &c_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 21, b_y);
  for (i = 0; i < 8; i++) {
    b_u[i] = u->f23[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv23);
  emlrtInitCharArrayR2013a(sp, 8, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 22, b_y);
  for (i = 0; i < 11; i++) {
    f_u[i] = u->f24[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv24);
  emlrtInitCharArrayR2013a(sp, 11, m, &f_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 23, b_y);
  for (i = 0; i < 7; i++) {
    c_u[i] = u->f25[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv25);
  emlrtInitCharArrayR2013a(sp, 7, m, &c_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 24, b_y);
  for (i = 0; i < 6; i++) {
    g_u[i] = u->f26[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv26);
  emlrtInitCharArrayR2013a(sp, 6, m, &g_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 25, b_y);
  for (i = 0; i < 6; i++) {
    g_u[i] = u->f27[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv27);
  emlrtInitCharArrayR2013a(sp, 6, m, &g_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 26, b_y);
  for (i = 0; i < 9; i++) {
    e_u[i] = u->f28[i];
  }

  b_y = NULL;
  m = emlrtCreateCharArray(2, iv28);
  emlrtInitCharArrayR2013a(sp, 9, m, &e_u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 27, b_y);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[12]
 */
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[12]
{
  real_T (*y)[12];
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[240]
 */
  static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[240]
{
  real_T (*ret)[240];
  static const int32_T dims[2] = { 48, 5 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[240])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *frame_AccTempEDA
 *                const char_T *identifier
 * Return Type  : real_T (*)[240]
 */
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *frame_AccTempEDA, const char_T *identifier))[240]
{
  real_T (*y)[240];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(frame_AccTempEDA), &thisId);
  emlrtDestroyArray(&frame_AccTempEDA);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const matlab_internal_coder_table *u
 * Return Type  : const mxArray *
 */
  static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const
  matlab_internal_coder_table *u)
{
  const mxArray *y;
  const mxArray *m;
  const mxArray *b_y;
  const mxArray *propValues[6];
  const mxArray *m1;
  const mxArray *c_y;
  const mxArray *m2;
  const mxArray *b_propValues[4];
  int32_T iv[2];
  const mxArray *d_y;
  static const int32_T iv1[2] = { 1, 3 };

  static const char_T t0_f1[3] = { 'R', 'o', 'w' };

  static const int32_T iv2[2] = { 1, 9 };

  static const char_T t0_f2[9] = { 'V', 'a', 'r', 'i', 'a', 'b', 'l', 'e', 's' };

  const char * propNames[4] = { "length", "hasLabels", "labels",
    "backwardsCompatibility" };

  const char * propClasses[4] = {
    "matlab.internal.coder.tabular.private.tabularDimension",
    "matlab.internal.coder.tabular.private.tabularDimension",
    "matlab.internal.coder.tabular.private.metaDim",
    "matlab.internal.coder.tabular.private.metaDim" };

  const mxArray *c_propValues[3];
  const char * b_propNames[3] = { "length", "hasLabels", "labels" };

  const char * b_propClasses[3] = {
    "matlab.internal.coder.tabular.private.tabularDimension",
    "matlab.internal.coder.tabular.private.tabularDimension",
    "matlab.internal.coder.tabular.private.rowNamesDim" };

  real_T b_u[28];
  int32_T i;
  real_T c_u;
  static const char * sv[2] = { "Description", "UserData" };

  static const int32_T iv3[2] = { 0, 0 };

  const char * c_propNames[6] = { "emptyPropertiesObj", "metaDim", "rowDim",
    "varDim", "data", "arrayProps" };

  const char * c_propClasses[6] = { "matlab.internal.coder.table",
    "matlab.internal.coder.table", "matlab.internal.coder.table",
    "matlab.internal.coder.table", "matlab.internal.coder.table",
    "matlab.internal.coder.table" };

  y = NULL;
  emlrtAssign(&y, emlrtCreateClassInstance("matlab.internal.coder.table"));
  m = NULL;
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateClassInstance(
    "matlab.internal.coder.tabular.TableProperties"));
  emlrtSetAllProperties(sp, &b_y, 0, 0, NULL, NULL, NULL);
  emlrtAssign(&b_y, emlrtConvertInstanceToRedirectSource(sp, b_y, 0,
    "matlab.internal.coder.tabular.TableProperties"));
  emlrtAssign(&m, b_y);
  propValues[0] = m;
  m = NULL;
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateClassInstance(
    "matlab.internal.coder.tabular.private.metaDim"));
  m1 = NULL;
  c_y = NULL;
  m2 = emlrtCreateDoubleScalar(2.0);
  emlrtAssign(&c_y, m2);
  emlrtAssign(&m1, c_y);
  b_propValues[0] = m1;
  m1 = NULL;
  c_y = NULL;
  m2 = emlrtCreateLogicalScalar(u->metaDim.hasLabels);
  emlrtAssign(&c_y, m2);
  emlrtAssign(&m1, c_y);
  b_propValues[1] = m1;
  m1 = NULL;
  c_y = NULL;
  iv[0] = 1;
  iv[1] = 2;
  emlrtAssign(&c_y, emlrtCreateCellArrayR2014a(2, iv));
  d_y = NULL;
  m2 = emlrtCreateCharArray(2, iv1);
  emlrtInitCharArrayR2013a(sp, 3, m2, &t0_f1[0]);
  emlrtAssign(&d_y, m2);
  emlrtSetCell(c_y, 0, d_y);
  d_y = NULL;
  m2 = emlrtCreateCharArray(2, iv2);
  emlrtInitCharArrayR2013a(sp, 9, m2, &t0_f2[0]);
  emlrtAssign(&d_y, m2);
  emlrtSetCell(c_y, 1, d_y);
  emlrtAssign(&m1, c_y);
  b_propValues[2] = m1;
  m1 = NULL;
  c_y = NULL;
  m2 = emlrtCreateLogicalScalar(u->metaDim.backwardsCompatibility);
  emlrtAssign(&c_y, m2);
  emlrtAssign(&m1, c_y);
  b_propValues[3] = m1;
  emlrtSetAllProperties(sp, &b_y, 0, 4, propNames, propClasses, b_propValues);
  emlrtAssign(&b_y, emlrtConvertInstanceToRedirectSource(sp, b_y, 0,
    "matlab.internal.coder.tabular.private.metaDim"));
  emlrtAssign(&m, b_y);
  propValues[1] = m;
  m = NULL;
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateClassInstance(
    "matlab.internal.coder.tabular.private.rowNamesDim"));
  m1 = NULL;
  c_y = NULL;
  m2 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&c_y, m2);
  emlrtAssign(&m1, c_y);
  c_propValues[0] = m1;
  m1 = NULL;
  c_y = NULL;
  m2 = emlrtCreateLogicalScalar(u->rowDim.hasLabels);
  emlrtAssign(&c_y, m2);
  emlrtAssign(&m1, c_y);
  c_propValues[1] = m1;
  m1 = NULL;
  c_y = NULL;
  iv[0] = 0;
  iv[1] = 0;
  emlrtAssign(&c_y, emlrtCreateCellArrayR2014a(2, iv));
  emlrtAssign(&m1, c_y);
  c_propValues[2] = m1;
  emlrtSetAllProperties(sp, &b_y, 0, 3, b_propNames, b_propClasses, c_propValues);
  emlrtAssign(&b_y, emlrtConvertInstanceToRedirectSource(sp, b_y, 0,
    "matlab.internal.coder.tabular.private.rowNamesDim"));
  emlrtAssign(&m, b_y);
  propValues[2] = m;
  m = NULL;
  emlrtAssign(&m, b_emlrt_marshallOut(sp, &u->varDim));
  propValues[3] = m;
  m = NULL;
  memcpy(&b_u[0], &u->data[0], 28U * sizeof(real_T));
  b_y = NULL;
  iv[0] = 1;
  iv[1] = 28;
  emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(2, iv));
  for (i = 0; i < 28; i++) {
    c_u = b_u[i];
    c_y = NULL;
    m1 = emlrtCreateDoubleScalar(c_u);
    emlrtAssign(&c_y, m1);
    emlrtSetCell(b_y, i, c_y);
  }

  emlrtAssign(&m, b_y);
  propValues[4] = m;
  m = NULL;
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 2, sv));
  c_y = NULL;
  iv[0] = u->arrayProps.Description.size[0];
  iv[1] = u->arrayProps.Description.size[1];
  m1 = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a(sp, 0, m1, NULL);
  emlrtAssign(&c_y, m1);
  emlrtSetFieldR2017b(b_y, 0, "Description", c_y, 0);
  c_y = NULL;
  m1 = emlrtCreateNumericArray(2, iv3, mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&c_y, m1);
  emlrtSetFieldR2017b(b_y, 0, "UserData", c_y, 1);
  emlrtAssign(&m, b_y);
  propValues[5] = m;
  emlrtSetAllProperties(sp, &y, 0, 6, c_propNames, c_propClasses, propValues);
  emlrtAssign(&y, emlrtConvertInstanceToRedirectSource(sp, y, 0,
    "matlab.internal.coder.table"));
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[12]
 */
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[12]
{
  real_T (*ret)[12];
  static const int32_T dims[2] = { 6, 2 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[12])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const mxArray * const prhs[2]
 *                int32_T nlhs
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
  void feature_extract_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[1])
{
  real_T (*frame_AccTempEDA)[240];
  real_T (*frame_SpO2HR)[12];
  matlab_internal_coder_table output;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  frame_AccTempEDA = emlrt_marshallIn(&st, emlrtAlias(prhs[0]),
    "frame_AccTempEDA");
  frame_SpO2HR = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "frame_SpO2HR");

  /* Invoke the target function */
  feature_extract(*frame_AccTempEDA, *frame_SpO2HR, &output);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, &output);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void feature_extract_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  feature_extract_xil_terminate();
  feature_extract_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void feature_extract_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void feature_extract_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_feature_extract_api.c
 *
 * [EOF]
 */
