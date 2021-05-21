/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: td_analysis.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 11:34:10
 */

/* Include Files */
#include "td_analysis.h"
#include "feature_extract.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */

/*
 * return mean min max change along with frame indexing given tm/sampling intervals
 *
 *  L     window size
 *  n     window range
 *  R     window shift
 *  window1 = 1; --> Rectangular window
 *  window2 = 0; --> Hamming window
 *  debug_fig set below to 1, if want to show debug figures
 * Arguments    : const double s[6]
 *                double *frame_mean
 *                double *frame_max
 *                double *frame_min
 *                double *frame_change
 * Return Type  : void
 */
void b_td_analysis(const double s[6], double *frame_mean, double *frame_max,
                   double *frame_min, double *frame_change)
{
  int i;
  double y;
  double framesignal1[6];
  int k;
  bool b;
  bool exitg1;

  /*  Window setup */
  /*  window range temp */
  /* Rectangular window */
  /*  calculate the total number of frames (dividing sig_length by frame_length) */
  /*  Initialization */
  for (i = 0; i < 6; i++) {
    framesignal1[i] = s[i];
  }

  y = framesignal1[0];
  for (k = 0; k < 5; k++) {
    y += framesignal1[k + 1];
  }

  *frame_mean = y / 6.0;

  /*  mean */
  b = rtIsNaN(framesignal1[0]);
  if (!b) {
    i = 1;
  } else {
    i = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 6)) {
      if (!rtIsNaN(framesignal1[k - 1])) {
        i = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (i == 0) {
    *frame_max = framesignal1[0];
  } else {
    *frame_max = framesignal1[i - 1];
    i++;
    for (k = i; k < 7; k++) {
      y = framesignal1[k - 1];
      if (*frame_max < y) {
        *frame_max = y;
      }
    }
  }

  /*  max */
  if (!b) {
    i = 1;
  } else {
    i = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 6)) {
      if (!rtIsNaN(framesignal1[k - 1])) {
        i = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (i == 0) {
    *frame_min = framesignal1[0];
  } else {
    *frame_min = framesignal1[i - 1];
    i++;
    for (k = i; k < 7; k++) {
      y = framesignal1[k - 1];
      if (*frame_min > y) {
        *frame_min = y;
      }
    }
  }

  /*  min */
  *frame_change = framesignal1[0] - framesignal1[5];

  /*  change */
}

/*
 * return mean min max change along with frame indexing given tm/sampling intervals
 *
 *  L     window size
 *  n     window range
 *  R     window shift
 *  window1 = 1; --> Rectangular window
 *  window2 = 0; --> Hamming window
 *  debug_fig set below to 1, if want to show debug figures
 * Arguments    : const double s[48]
 *                double *frame_mean
 *                double *frame_max
 *                double *frame_min
 *                double *frame_change
 * Return Type  : void
 */
void td_analysis(const double s[48], double *frame_mean, double *frame_max,
                 double *frame_min, double *frame_change)
{
  double framesignal1[48];
  double y;
  int k;
  bool b;
  int idx;
  bool exitg1;

  /*  Window setup */
  /*  window range temp */
  /* Rectangular window */
  /*  calculate the total number of frames (dividing sig_length by frame_length) */
  /*  Initialization */
  memcpy(&framesignal1[0], &s[0], 48U * sizeof(double));
  y = framesignal1[0];
  for (k = 0; k < 47; k++) {
    y += framesignal1[k + 1];
  }

  *frame_mean = y / 48.0;

  /*  mean */
  b = rtIsNaN(framesignal1[0]);
  if (!b) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 48)) {
      if (!rtIsNaN(framesignal1[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    *frame_max = framesignal1[0];
  } else {
    *frame_max = framesignal1[idx - 1];
    idx++;
    for (k = idx; k < 49; k++) {
      y = framesignal1[k - 1];
      if (*frame_max < y) {
        *frame_max = y;
      }
    }
  }

  /*  max */
  if (!b) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 48)) {
      if (!rtIsNaN(framesignal1[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    *frame_min = framesignal1[0];
  } else {
    *frame_min = framesignal1[idx - 1];
    idx++;
    for (k = idx; k < 49; k++) {
      y = framesignal1[k - 1];
      if (*frame_min > y) {
        *frame_min = y;
      }
    }
  }

  /*  min */
  *frame_change = framesignal1[0] - framesignal1[47];

  /*  change */
}

/*
 * File trailer for td_analysis.c
 *
 * [EOF]
 */
