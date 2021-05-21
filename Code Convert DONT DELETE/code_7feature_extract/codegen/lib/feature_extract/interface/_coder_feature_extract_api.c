/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_feature_extract_api.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 08:47:07
 */

/* Include Files */
#include "_coder_feature_extract_api.h"
#include "_coder_feature_extract_mex.h"

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
  int32_T iv[2];
  int32_T i;
  const mxArray *c_y;
  char_T b_u[7];
  static const char_T t0_f1[7] = { 'a', 'c', 'x', '_', 'm', 'a', 'x' };

  static const int32_T iv1[2] = { 1, 7 };

  static const char_T t0_f2[7] = { 'a', 'c', 'y', '_', 'm', 'a', 'x' };

  static const int32_T iv2[2] = { 1, 7 };

  static const char_T t0_f3[7] = { 'a', 'c', 'z', '_', 'm', 'a', 'x' };

  static const int32_T iv3[2] = { 1, 7 };

  char_T c_u[8];
  static const char_T t0_f4[8] = { 't', 'e', 'm', 'p', '_', 'm', 'a', 'x' };

  static const int32_T iv4[2] = { 1, 8 };

  static const char_T t0_f5[7] = { 'E', 'D', 'A', '_', 'm', 'a', 'x' };

  static const int32_T iv5[2] = { 1, 7 };

  static const char_T t0_f6[8] = { 'S', 'P', 'O', '2', '_', 'm', 'a', 'x' };

  static const int32_T iv6[2] = { 1, 8 };

  static const int32_T iv7[2] = { 1, 6 };

  static const char_T t0_f7[6] = { 'H', 'R', '_', 'm', 'a', 'x' };

  static const char * enumNames[4] = { "unset", "continuous", "step", "event" };

  static const int32_T enumValues[4] = { 0, 1, 2, 3 };

  uint8_T d_u[7];
  const mxArray *m2;
  static const int32_T iv8[2] = { 1, 7 };

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
  m1 = emlrtCreateDoubleScalar(7.0);
  emlrtAssign(&b_y, m1);
  emlrtAssign(&m, b_y);
  propValues[0] = m;
  m = NULL;
  b_y = NULL;
  m1 = emlrtCreateLogicalScalar(u->hasLabels);
  emlrtAssign(&b_y, m1);
  emlrtAssign(&m, b_y);
  propValues[1] = m;
  m = NULL;
  b_y = NULL;
  iv[0] = 1;
  iv[1] = 7;
  emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(2, iv));
  for (i = 0; i < 7; i++) {
    b_u[i] = t0_f1[i];
  }

  c_y = NULL;
  m1 = emlrtCreateCharArray(2, iv1);
  emlrtInitCharArrayR2013a(sp, 7, m1, &b_u[0]);
  emlrtAssign(&c_y, m1);
  emlrtSetCell(b_y, 0, c_y);
  for (i = 0; i < 7; i++) {
    b_u[i] = t0_f2[i];
  }

  c_y = NULL;
  m1 = emlrtCreateCharArray(2, iv2);
  emlrtInitCharArrayR2013a(sp, 7, m1, &b_u[0]);
  emlrtAssign(&c_y, m1);
  emlrtSetCell(b_y, 1, c_y);
  for (i = 0; i < 7; i++) {
    b_u[i] = t0_f3[i];
  }

  c_y = NULL;
  m1 = emlrtCreateCharArray(2, iv3);
  emlrtInitCharArrayR2013a(sp, 7, m1, &b_u[0]);
  emlrtAssign(&c_y, m1);
  emlrtSetCell(b_y, 2, c_y);
  for (i = 0; i < 8; i++) {
    c_u[i] = t0_f4[i];
  }

  c_y = NULL;
  m1 = emlrtCreateCharArray(2, iv4);
  emlrtInitCharArrayR2013a(sp, 8, m1, &c_u[0]);
  emlrtAssign(&c_y, m1);
  emlrtSetCell(b_y, 3, c_y);
  for (i = 0; i < 7; i++) {
    b_u[i] = t0_f5[i];
  }

  c_y = NULL;
  m1 = emlrtCreateCharArray(2, iv5);
  emlrtInitCharArrayR2013a(sp, 7, m1, &b_u[0]);
  emlrtAssign(&c_y, m1);
  emlrtSetCell(b_y, 4, c_y);
  for (i = 0; i < 8; i++) {
    c_u[i] = t0_f6[i];
  }

  c_y = NULL;
  m1 = emlrtCreateCharArray(2, iv6);
  emlrtInitCharArrayR2013a(sp, 8, m1, &c_u[0]);
  emlrtAssign(&c_y, m1);
  emlrtSetCell(b_y, 5, c_y);
  c_y = NULL;
  m1 = emlrtCreateCharArray(2, iv7);
  emlrtInitCharArrayR2013a(sp, 6, m1, &t0_f7[0]);
  emlrtAssign(&c_y, m1);
  emlrtSetCell(b_y, 6, c_y);
  emlrtAssign(&m, b_y);
  propValues[2] = m;
  m = NULL;
  b_y = NULL;
  iv[0] = 1;
  iv[1] = 7;
  emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(2, iv));
  for (i = 0; i < 7; i++) {
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
  iv[1] = 7;
  emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(2, iv));
  for (i = 0; i < 7; i++) {
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
  for (i = 0; i < 7; i++) {
    d_u[i] = u->continuity[i];
  }

  c_y = NULL;
  m2 = emlrtCreateNumericArray(2, iv8, mxUINT8_CLASS, mxREAL);
  pData = (uint8_T *)emlrtMxGetData(m2);
  i = 0;
  for (b_i = 0; b_i < 7; b_i++) {
    pData[i] = d_u[b_i];
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
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[12]
 */
  static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[12]
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

  static const char_T t1_f1[3] = { 'R', 'o', 'w' };

  static const int32_T iv2[2] = { 1, 9 };

  static const char_T t1_f2[9] = { 'V', 'a', 'r', 'i', 'a', 'b', 'l', 'e', 's' };

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

  int32_T i;
  real_T b_u[7];
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
  emlrtInitCharArrayR2013a(sp, 3, m2, &t1_f1[0]);
  emlrtAssign(&d_y, m2);
  emlrtSetCell(c_y, 0, d_y);
  d_y = NULL;
  m2 = emlrtCreateCharArray(2, iv2);
  emlrtInitCharArrayR2013a(sp, 9, m2, &t1_f2[0]);
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
  for (i = 0; i < 7; i++) {
    b_u[i] = u->data[i];
  }

  b_y = NULL;
  iv[0] = 1;
  iv[1] = 7;
  emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(2, iv));
  for (i = 0; i < 7; i++) {
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
