/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: feature_extract.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 11:34:10
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
  td_analysis(*(double (*)[48])&frame_AccTempEDA[0], &output->data[0],
              &output->data[1], &output->data[2], &output->data[3]);
  td_analysis(*(double (*)[48])&frame_AccTempEDA[48], &output->data[4],
              &output->data[5], &output->data[6], &output->data[7]);
  td_analysis(*(double (*)[48])&frame_AccTempEDA[96], &output->data[8],
              &output->data[9], &output->data[10], &output->data[11]);
  td_analysis(*(double (*)[48])&frame_AccTempEDA[144], &output->data[12],
              &output->data[13], &output->data[14], &output->data[15]);
  td_analysis(*(double (*)[48])&frame_AccTempEDA[192], &output->data[16],
              &output->data[17], &output->data[18], &output->data[19]);

  /*  SpO2HR */
  b_td_analysis(*(double (*)[6])&frame_SpO2HR[0], &output->data[20],
                &output->data[21], &output->data[22], &output->data[23]);
  b_td_analysis(*(double (*)[6])&frame_SpO2HR[6], &output->data[24],
                &output->data[25], &output->data[26], &output->data[27]);

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
  output->varDim.units[7].f1.size[0] = 1;
  output->varDim.units[7].f1.size[1] = 0;
  output->varDim.units[8].f1.size[0] = 1;
  output->varDim.units[8].f1.size[1] = 0;
  output->varDim.units[9].f1.size[0] = 1;
  output->varDim.units[9].f1.size[1] = 0;
  output->varDim.units[10].f1.size[0] = 1;
  output->varDim.units[10].f1.size[1] = 0;
  output->varDim.units[11].f1.size[0] = 1;
  output->varDim.units[11].f1.size[1] = 0;
  output->varDim.units[12].f1.size[0] = 1;
  output->varDim.units[12].f1.size[1] = 0;
  output->varDim.units[13].f1.size[0] = 1;
  output->varDim.units[13].f1.size[1] = 0;
  output->varDim.units[14].f1.size[0] = 1;
  output->varDim.units[14].f1.size[1] = 0;
  output->varDim.units[15].f1.size[0] = 1;
  output->varDim.units[15].f1.size[1] = 0;
  output->varDim.units[16].f1.size[0] = 1;
  output->varDim.units[16].f1.size[1] = 0;
  output->varDim.units[17].f1.size[0] = 1;
  output->varDim.units[17].f1.size[1] = 0;
  output->varDim.units[18].f1.size[0] = 1;
  output->varDim.units[18].f1.size[1] = 0;
  output->varDim.units[19].f1.size[0] = 1;
  output->varDim.units[19].f1.size[1] = 0;
  output->varDim.units[20].f1.size[0] = 1;
  output->varDim.units[20].f1.size[1] = 0;
  output->varDim.units[21].f1.size[0] = 1;
  output->varDim.units[21].f1.size[1] = 0;
  output->varDim.units[22].f1.size[0] = 1;
  output->varDim.units[22].f1.size[1] = 0;
  output->varDim.units[23].f1.size[0] = 1;
  output->varDim.units[23].f1.size[1] = 0;
  output->varDim.units[24].f1.size[0] = 1;
  output->varDim.units[24].f1.size[1] = 0;
  output->varDim.units[25].f1.size[0] = 1;
  output->varDim.units[25].f1.size[1] = 0;
  output->varDim.units[26].f1.size[0] = 1;
  output->varDim.units[26].f1.size[1] = 0;
  output->varDim.units[27].f1.size[0] = 1;
  output->varDim.units[27].f1.size[1] = 0;
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
  output->varDim.descrs[7].f1.size[0] = 1;
  output->varDim.descrs[7].f1.size[1] = 0;
  output->varDim.descrs[8].f1.size[0] = 1;
  output->varDim.descrs[8].f1.size[1] = 0;
  output->varDim.descrs[9].f1.size[0] = 1;
  output->varDim.descrs[9].f1.size[1] = 0;
  output->varDim.descrs[10].f1.size[0] = 1;
  output->varDim.descrs[10].f1.size[1] = 0;
  output->varDim.descrs[11].f1.size[0] = 1;
  output->varDim.descrs[11].f1.size[1] = 0;
  output->varDim.descrs[12].f1.size[0] = 1;
  output->varDim.descrs[12].f1.size[1] = 0;
  output->varDim.descrs[13].f1.size[0] = 1;
  output->varDim.descrs[13].f1.size[1] = 0;
  output->varDim.descrs[14].f1.size[0] = 1;
  output->varDim.descrs[14].f1.size[1] = 0;
  output->varDim.descrs[15].f1.size[0] = 1;
  output->varDim.descrs[15].f1.size[1] = 0;
  output->varDim.descrs[16].f1.size[0] = 1;
  output->varDim.descrs[16].f1.size[1] = 0;
  output->varDim.descrs[17].f1.size[0] = 1;
  output->varDim.descrs[17].f1.size[1] = 0;
  output->varDim.descrs[18].f1.size[0] = 1;
  output->varDim.descrs[18].f1.size[1] = 0;
  output->varDim.descrs[19].f1.size[0] = 1;
  output->varDim.descrs[19].f1.size[1] = 0;
  output->varDim.descrs[20].f1.size[0] = 1;
  output->varDim.descrs[20].f1.size[1] = 0;
  output->varDim.descrs[21].f1.size[0] = 1;
  output->varDim.descrs[21].f1.size[1] = 0;
  output->varDim.descrs[22].f1.size[0] = 1;
  output->varDim.descrs[22].f1.size[1] = 0;
  output->varDim.descrs[23].f1.size[0] = 1;
  output->varDim.descrs[23].f1.size[1] = 0;
  output->varDim.descrs[24].f1.size[0] = 1;
  output->varDim.descrs[24].f1.size[1] = 0;
  output->varDim.descrs[25].f1.size[0] = 1;
  output->varDim.descrs[25].f1.size[1] = 0;
  output->varDim.descrs[26].f1.size[0] = 1;
  output->varDim.descrs[26].f1.size[1] = 0;
  output->varDim.descrs[27].f1.size[0] = 1;
  output->varDim.descrs[27].f1.size[1] = 0;
  output->varDim.hasContinuity = false;
  for (i = 0; i < 28; i++) {
    output->varDim.continuity[i] = unset;
  }

  output->varDim.hasCustomProps = false;
}

/*
 * File trailer for feature_extract.c
 *
 * [EOF]
 */
