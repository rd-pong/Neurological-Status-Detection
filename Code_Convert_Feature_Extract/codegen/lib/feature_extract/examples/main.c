/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 28-Aug-2020 11:34:10
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "feature_extract.h"
#include "feature_extract_terminate.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void argInit_48x5_real_T(double result[240]);
static void argInit_6x2_real_T(double result[12]);
static double argInit_real_T(void);
static void main_feature_extract(void);

/* Function Definitions */

/*
 * Arguments    : double result[240]
 * Return Type  : void
 */
static void argInit_48x5_real_T(double result[240])
{
  int idx0;
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 48; idx0++) {
    for (idx1 = 0; idx1 < 5; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result[idx0 + 48 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : double result[12]
 * Return Type  : void
 */
static void argInit_6x2_real_T(double result[12])
{
  int idx0;
  double result_tmp;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 6; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result_tmp = argInit_real_T();
    result[idx0] = result_tmp;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0 + 6] = result_tmp;
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_feature_extract(void)
{
  double dv[240];
  double dv1[12];
  matlab_internal_coder_table output;

  /* Initialize function 'feature_extract' input arguments. */
  /* Initialize function input argument 'frame_AccTempEDA'. */
  /* Initialize function input argument 'frame_SpO2HR'. */
  /* Call the entry-point 'feature_extract'. */
  argInit_48x5_real_T(dv);
  argInit_6x2_real_T(dv1);
  feature_extract(dv, dv1, &output);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_feature_extract();

  /* Terminate the application.
     You do not need to do this more than one time. */
  feature_extract_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
