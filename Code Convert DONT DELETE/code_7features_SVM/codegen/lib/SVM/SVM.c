/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: SVM.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 08:53:12
 */

/* Include Files */
#include "SVM.h"
#include "CompactClassificationECOC.h"
#include "CompactClassificationSVM.h"
#include "SVM_data.h"
#include "SVM_emxutil.h"
#include "SVM_initialize.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : const double input_data[7]
 *                double *label
 *                double score[4]
 * Return Type  : void
 */
void SVM(const double input_data[7], double *label, double score[4])
{
  c_classreg_learning_coder_class SVM_BinaryLearners[6];
  double SVM_ClassNames[4];
  double SVM_Prior[4];
  static const double SVM_CodingMatrix[24] = { 1.0, -1.0, -0.0, -0.0, 1.0, -0.0,
    -1.0, -0.0, 1.0, -0.0, -0.0, -1.0, 0.0, 1.0, -1.0, -0.0, 0.0, 1.0, -0.0,
    -1.0, 0.0, 0.0, 1.0, -1.0 };

  if (isInitialized_SVM == false) {
    SVM_initialize();
  }

  c_emxInitMatrix_classreg_learni(SVM_BinaryLearners);
  c_CompactClassificationSVM_Comp(SVM_BinaryLearners[0].Alpha.data,
    SVM_BinaryLearners[0].Alpha.size, &SVM_BinaryLearners[0].Bias,
    SVM_BinaryLearners[0].SupportVectorsT, &SVM_BinaryLearners[0].Scale,
    &SVM_BinaryLearners[0].Order, SVM_BinaryLearners[0].Mu, SVM_BinaryLearners[0]
    .Sigma, &SVM_BinaryLearners[0].KernelFunction, SVM_BinaryLearners[0].
    ClassNames, SVM_BinaryLearners[0].ClassNamesLength, &SVM_BinaryLearners[0].
    ScoreTransform, SVM_BinaryLearners[0].Prior, SVM_BinaryLearners[0].
    ClassLogicalIndices, SVM_BinaryLearners[0].Cost);
  d_CompactClassificationSVM_Comp(SVM_BinaryLearners[1].Alpha.data,
    SVM_BinaryLearners[1].Alpha.size, &SVM_BinaryLearners[1].Bias,
    SVM_BinaryLearners[1].SupportVectorsT, &SVM_BinaryLearners[1].Scale,
    &SVM_BinaryLearners[1].Order, SVM_BinaryLearners[1].Mu, SVM_BinaryLearners[1]
    .Sigma, &SVM_BinaryLearners[1].KernelFunction, SVM_BinaryLearners[1].
    ClassNames, SVM_BinaryLearners[1].ClassNamesLength, &SVM_BinaryLearners[1].
    ScoreTransform, SVM_BinaryLearners[1].Prior, SVM_BinaryLearners[1].
    ClassLogicalIndices, SVM_BinaryLearners[1].Cost);
  e_CompactClassificationSVM_Comp(SVM_BinaryLearners[2].Alpha.data,
    SVM_BinaryLearners[2].Alpha.size, &SVM_BinaryLearners[2].Bias,
    SVM_BinaryLearners[2].SupportVectorsT, &SVM_BinaryLearners[2].Scale,
    &SVM_BinaryLearners[2].Order, SVM_BinaryLearners[2].Mu, SVM_BinaryLearners[2]
    .Sigma, &SVM_BinaryLearners[2].KernelFunction, SVM_BinaryLearners[2].
    ClassNames, SVM_BinaryLearners[2].ClassNamesLength, &SVM_BinaryLearners[2].
    ScoreTransform, SVM_BinaryLearners[2].Prior, SVM_BinaryLearners[2].
    ClassLogicalIndices, SVM_BinaryLearners[2].Cost);
  f_CompactClassificationSVM_Comp(SVM_BinaryLearners[3].Alpha.data,
    SVM_BinaryLearners[3].Alpha.size, &SVM_BinaryLearners[3].Bias,
    SVM_BinaryLearners[3].SupportVectorsT, &SVM_BinaryLearners[3].Scale,
    &SVM_BinaryLearners[3].Order, SVM_BinaryLearners[3].Mu, SVM_BinaryLearners[3]
    .Sigma, &SVM_BinaryLearners[3].KernelFunction, SVM_BinaryLearners[3].
    ClassNames, SVM_BinaryLearners[3].ClassNamesLength, &SVM_BinaryLearners[3].
    ScoreTransform, SVM_BinaryLearners[3].Prior, SVM_BinaryLearners[3].
    ClassLogicalIndices, SVM_BinaryLearners[3].Cost);
  g_CompactClassificationSVM_Comp(SVM_BinaryLearners[4].Alpha.data,
    SVM_BinaryLearners[4].Alpha.size, &SVM_BinaryLearners[4].Bias,
    SVM_BinaryLearners[4].SupportVectorsT, &SVM_BinaryLearners[4].Scale,
    &SVM_BinaryLearners[4].Order, SVM_BinaryLearners[4].Mu, SVM_BinaryLearners[4]
    .Sigma, &SVM_BinaryLearners[4].KernelFunction, SVM_BinaryLearners[4].
    ClassNames, SVM_BinaryLearners[4].ClassNamesLength, &SVM_BinaryLearners[4].
    ScoreTransform, SVM_BinaryLearners[4].Prior, SVM_BinaryLearners[4].
    ClassLogicalIndices, SVM_BinaryLearners[4].Cost);
  h_CompactClassificationSVM_Comp(SVM_BinaryLearners[5].Alpha.data,
    SVM_BinaryLearners[5].Alpha.size, &SVM_BinaryLearners[5].Bias,
    SVM_BinaryLearners[5].SupportVectorsT, &SVM_BinaryLearners[5].Scale,
    &SVM_BinaryLearners[5].Order, SVM_BinaryLearners[5].Mu, SVM_BinaryLearners[5]
    .Sigma, &SVM_BinaryLearners[5].KernelFunction, SVM_BinaryLearners[5].
    ClassNames, SVM_BinaryLearners[5].ClassNamesLength, &SVM_BinaryLearners[5].
    ScoreTransform, SVM_BinaryLearners[5].Prior, SVM_BinaryLearners[5].
    ClassLogicalIndices, SVM_BinaryLearners[5].Cost);
  SVM_ClassNames[0] = 0.0;
  SVM_Prior[0] = 0.52210802234945164;
  SVM_ClassNames[1] = 1.0;
  SVM_Prior[1] = 0.14265020349037733;
  SVM_ClassNames[2] = 2.0;
  SVM_Prior[2] = 0.18031316824170518;
  SVM_ClassNames[3] = 3.0;
  SVM_Prior[3] = 0.15492860591846588;
  c_CompactClassificationECOC_pre(SVM_ClassNames, SVM_Prior, SVM_BinaryLearners,
    SVM_CodingMatrix, input_data, label, score);
  c_emxFreeMatrix_classreg_learni(SVM_BinaryLearners);
}

/*
 * File trailer for SVM.c
 *
 * [EOF]
 */
