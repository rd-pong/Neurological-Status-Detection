/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: feature_extract.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 00:58:57
 */

/* Include Files */
#include "feature_extract.h"
#include "feature_extract_data.h"
#include "feature_extract_initialize.h"
#include "rt_nonfinite.h"
#include "td_analysis.h"

/* Function Definitions */

/*
 * input: AccTempEDA, SpO2HR
 *  output: feature matrix of size (5+2)*4,
 *  5column-->AccTempEDA, 2column-->SpO2HR,4-->features(min/max/mean/change)
 * Arguments    : const double frame_AccTempEDA[240]
 *                const double frame_SpO2HR[12]
 *                matlab_internal_coder_table *output
 * Return Type  : void
 */
void feature_extract(const double frame_AccTempEDA[240], const double
                     frame_SpO2HR[12], matlab_internal_coder_table *output)
{
  int i;
  if (isInitialized_feature_extract == false) {
    feature_extract_initialize();
  }

  /*  AccTempEDA */
  output->data[0] = td_analysis(*(double (*)[48])&frame_AccTempEDA[0]);
  output->data[1] = td_analysis(*(double (*)[48])&frame_AccTempEDA[48]);
  output->data[2] = td_analysis(*(double (*)[48])&frame_AccTempEDA[96]);
  output->data[3] = td_analysis(*(double (*)[48])&frame_AccTempEDA[144]);
  output->data[4] = td_analysis(*(double (*)[48])&frame_AccTempEDA[192]);

  /*  SpO2HR */
  output->data[5] = b_td_analysis(*(double (*)[6])&frame_SpO2HR[0]);
  output->data[6] = b_td_analysis(*(double (*)[6])&frame_SpO2HR[6]);

  /*  Create table according to Code Generation (Restriction) for Tables */
  output->metaDim.hasLabels = true;
  output->metaDim.backwardsCompatibility = true;
  output->arrayProps.Description.size[0] = 0;
  output->arrayProps.Description.size[1] = 0;
  output->rowDim.hasLabels = false;
  output->varDim.hasLabels = true;
  output->varDim.hasUnits = false;
  output->varDim.units[0].f1.size[0] = 1;
  output->varDim.units[0].f1.size[1] = 0;
  output->varDim.units[1].f1.size[0] = 1;
  output->varDim.units[1].f1.size[1] = 0;
  output->varDim.units[2].f1.size[0] = 1;
  output->varDim.units[2].f1.size[1] = 0;
  output->varDim.units[3].f1.size[0] = 1;
  output->varDim.units[3].f1.size[1] = 0;
  output->varDim.units[4].f1.size[0] = 1;
  output->varDim.units[4].f1.size[1] = 0;
  output->varDim.units[5].f1.size[0] = 1;
  output->varDim.units[5].f1.size[1] = 0;
  output->varDim.units[6].f1.size[0] = 1;
  output->varDim.units[6].f1.size[1] = 0;
  output->varDim.hasDescrs = false;
  output->varDim.descrs[0].f1.size[0] = 1;
  output->varDim.descrs[0].f1.size[1] = 0;
  output->varDim.descrs[1].f1.size[0] = 1;
  output->varDim.descrs[1].f1.size[1] = 0;
  output->varDim.descrs[2].f1.size[0] = 1;
  output->varDim.descrs[2].f1.size[1] = 0;
  output->varDim.descrs[3].f1.size[0] = 1;
  output->varDim.descrs[3].f1.size[1] = 0;
  output->varDim.descrs[4].f1.size[0] = 1;
  output->varDim.descrs[4].f1.size[1] = 0;
  output->varDim.descrs[5].f1.size[0] = 1;
  output->varDim.descrs[5].f1.size[1] = 0;
  output->varDim.descrs[6].f1.size[0] = 1;
  output->varDim.descrs[6].f1.size[1] = 0;
  output->varDim.hasContinuity = false;
  for (i = 0; i < 7; i++) {
    output->varDim.continuity[i] = unset;
  }

  output->varDim.hasCustomProps = false;
}

/*
 * File trailer for feature_extract.c
 *
 * [EOF]
 */
