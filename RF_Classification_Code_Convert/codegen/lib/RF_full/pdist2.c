/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: pdist2.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 15:49:21
 */

/* Include Files */
#include "pdist2.h"
#include "RF_full.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void partialSort(const double Din[14497], double Dout[3], double Iout[3]);

/* Function Definitions */

/*
 * Arguments    : const double Din[14497]
 *                double Dout[3]
 *                double Iout[3]
 * Return Type  : void
 */
static void partialSort(const double Din[14497], double Dout[3], double Iout[3])
{
  static double D[14497];
  static int iidx[14497];
  memcpy(&D[0], &Din[0], 14497U * sizeof(double));
  sort(D, iidx);
  Dout[0] = D[0];
  Iout[0] = iidx[0];
  Dout[1] = D[1];
  Iout[1] = iidx[1];
  Dout[2] = D[2];
  Iout[2] = iidx[2];
}

/*
 * Arguments    : const double Xin[405916]
 *                const double Yin[28]
 *                double D[3]
 *                double b_I[3]
 * Return Type  : void
 */
void pdist2(const double Xin[405916], const double Yin[28], double D[3], double
            b_I[3])
{
  int i;
  bool nanflag;
  int qq;
  bool exitg1;
  static double X[405916];
  static double d[14497];
  double tempSum;
  double tempSum_tmp;
  for (i = 0; i < 14497; i++) {
    for (qq = 0; qq < 28; qq++) {
      X[qq + 28 * i] = Xin[i + 14497 * qq];
    }
  }

  nanflag = false;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 28)) {
    if (rtIsNaN(Yin[i])) {
      nanflag = true;
      exitg1 = true;
    } else {
      i++;
    }
  }

  for (i = 0; i < 14497; i++) {
    d[i] = rtNaN;
  }

  if (!nanflag) {
    for (qq = 0; qq < 14497; qq++) {
      tempSum = 0.0;
      for (i = 0; i < 28; i++) {
        tempSum_tmp = X[i + 28 * qq] - Yin[i];
        tempSum += tempSum_tmp * tempSum_tmp;
      }

      d[qq] = sqrt(tempSum);
    }
  }

  partialSort(d, D, b_I);
}

/*
 * File trailer for pdist2.c
 *
 * [EOF]
 */
