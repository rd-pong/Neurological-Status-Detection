/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: td_analysis.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 07-May-2021 08:47:07
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
 * Return Type  : double
 */
double b_td_analysis(const double s[6])
{
  double frame_max;
  int i;
  double x_data[48];
  double framesignal1[6];
  int k;
  bool exitg1;
  double d;

  /*  Window setup */
  /*  window range temp */
  /* Rectangular window */
  /*  calculate the total number of frames (dividing sig_length by frame_length) */
  /*  Initialization */
  /*  frame_mean = [zeros(frame_number, 1)]; */
  /*  frame_change = [zeros(frame_number, 1)]; */
  /*  frame_min = [zeros(frame_number, 1)]; */
  /*      frame_mean(i) = mean(framesignal1); % mean */
  for (i = 0; i < 6; i++) {
    framesignal1[i] = s[i];
    x_data[i] = s[i];
  }

  if (!rtIsNaN(x_data[0])) {
    i = 1;
  } else {
    i = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 6)) {
      if (!rtIsNaN(x_data[k - 1])) {
        i = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (i == 0) {
    frame_max = framesignal1[0];
  } else {
    frame_max = framesignal1[i - 1];
    i++;
    for (k = i; k < 7; k++) {
      d = framesignal1[k - 1];
      if (frame_max < d) {
        frame_max = d;
      }
    }
  }

  /*  max */
  /*      frame_min(i) = min(framesignal1); % min */
  /*      frame_change(i) = framesignal1(1) - framesignal1(end); % change */
  return frame_max;
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
 * Return Type  : double
 */
double td_analysis(const double s[48])
{
  double frame_max;
  double framesignal1[48];
  double x_data[48];
  int idx;
  int k;
  bool exitg1;
  double d;

  /*  Window setup */
  /*  window range temp */
  /* Rectangular window */
  /*  calculate the total number of frames (dividing sig_length by frame_length) */
  /*  Initialization */
  /*  frame_mean = [zeros(frame_number, 1)]; */
  /*  frame_change = [zeros(frame_number, 1)]; */
  /*  frame_min = [zeros(frame_number, 1)]; */
  /*      frame_mean(i) = mean(framesignal1); % mean */
  memcpy(&framesignal1[0], &s[0], 48U * sizeof(double));
  memcpy(&x_data[0], &s[0], 48U * sizeof(double));
  if (!rtIsNaN(x_data[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 48)) {
      if (!rtIsNaN(x_data[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    frame_max = framesignal1[0];
  } else {
    frame_max = framesignal1[idx - 1];
    idx++;
    for (k = idx; k < 49; k++) {
      d = framesignal1[k - 1];
      if (frame_max < d) {
        frame_max = d;
      }
    }
  }

  /*  max */
  /*      frame_min(i) = min(framesignal1); % min */
  /*      frame_change(i) = framesignal1(1) - framesignal1(end); % change */
  return frame_max;
}

/*
 * File trailer for td_analysis.c
 *
 * [EOF]
 */
