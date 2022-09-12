/*
 * File: feedback_control_types.h
 *
 * Code generated for Simulink model 'feedback_control'.
 *
 * Model version                  : 1.42
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Mon Jan 24 21:00:58 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_feedback_control_types_h_
#define RTW_HEADER_feedback_control_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_pid_param_
#define DEFINED_TYPEDEF_FOR_pid_param_

typedef struct {
  real_T P;
  real_T I;
  real_T D;
  real_T N;
} pid_param;

#endif

/* Parameters (default storage) */
typedef struct Parameters_feedback_control_ Parameters_feedback_control;

/* Forward declaration for rtModel */
typedef struct tag_RTM_feedback_control RT_MODEL_feedback_control;

#endif                                /* RTW_HEADER_feedback_control_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
