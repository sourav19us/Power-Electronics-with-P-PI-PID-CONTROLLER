/*
 * File: feedback_control.c
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

#include "feedback_control.h"
#include "feedback_control_private.h"

/* Block states (default storage) */
D_Work_feedback_control feedback_control_DWork;

/* External inputs (root inport signals with default storage) */
ExternalInputs_feedback_control feedback_control_U;

/* External outputs (root outports fed by signals with default storage) */
ExternalOutputs_feedback_contro feedback_control_Y;

/* Real-time model */
RT_MODEL_feedback_control feedback_control_M_;
RT_MODEL_feedback_control *const feedback_control_M = &feedback_control_M_;

/* Model step function */
void feedback_control_step(void)
{
  real_T rtb_FilterCoefficient;

  /* Gain: '<S36>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S28>/Filter'
   *  Gain: '<S27>/Derivative Gain'
   *  Inport: '<Root>/u'
   *  Sum: '<S28>/SumD'
   */
  rtb_FilterCoefficient = ((feedback_control_P.pid.D *
    feedback_control_U.control_input) - feedback_control_DWork.Filter_DSTATE) *
    feedback_control_P.pid.N;

  /* Outport: '<Root>/y' incorporates:
   *  DiscreteIntegrator: '<S33>/Integrator'
   *  Gain: '<S38>/Proportional Gain'
   *  Inport: '<Root>/u'
   *  Sum: '<S42>/Sum'
   */
  feedback_control_Y.y = ((feedback_control_P.pid.P *
    feedback_control_U.control_input) + feedback_control_DWork.Integrator_DSTATE)
    + rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S33>/Integrator' incorporates:
   *  Gain: '<S30>/Integral Gain'
   *  Inport: '<Root>/u'
   */
  feedback_control_DWork.Integrator_DSTATE += (feedback_control_P.pid.I *
    feedback_control_U.control_input) * 0.001;

  /* Update for DiscreteIntegrator: '<S28>/Filter' */
  feedback_control_DWork.Filter_DSTATE += 0.001 * rtb_FilterCoefficient;
}

/* Model initialize function */
void feedback_control_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void feedback_control_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
