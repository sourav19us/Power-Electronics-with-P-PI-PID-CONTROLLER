/*
 * File: feedback_control.h
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

#ifndef RTW_HEADER_feedback_control_h_
#define RTW_HEADER_feedback_control_h_
#ifndef feedback_control_COMMON_INCLUDES_
# define feedback_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* feedback_control_COMMON_INCLUDES_ */

#include "feedback_control_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S33>/Integrator' */
  real_T Filter_DSTATE;                /* '<S28>/Filter' */
} D_Work_feedback_control;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T control_input;                /* '<Root>/u' */
} ExternalInputs_feedback_control;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T y;                            /* '<Root>/y' */
} ExternalOutputs_feedback_contro;

/* Parameters (default storage) */
struct Parameters_feedback_control_ {
  pid_param pid;                       /* Variable: pid
                                        * Referenced by:
                                        *   '<S27>/Derivative Gain'
                                        *   '<S30>/Integral Gain'
                                        *   '<S36>/Filter Coefficient'
                                        *   '<S38>/Proportional Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_feedback_control {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern Parameters_feedback_control feedback_control_P;

/* Block states (default storage) */
extern D_Work_feedback_control feedback_control_DWork;

/* External inputs (root inport signals with default storage) */
extern ExternalInputs_feedback_control feedback_control_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExternalOutputs_feedback_contro feedback_control_Y;

/* Model entry point functions */
extern void feedback_control_initialize(void);
extern void feedback_control_step(void);
extern void feedback_control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_feedback_control *const feedback_control_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'feedback_control'
 * '<S1>'   : 'feedback_control/Discrete PID Controller'
 * '<S2>'   : 'feedback_control/Discrete PID Controller/Anti-windup'
 * '<S3>'   : 'feedback_control/Discrete PID Controller/D Gain'
 * '<S4>'   : 'feedback_control/Discrete PID Controller/Filter'
 * '<S5>'   : 'feedback_control/Discrete PID Controller/Filter ICs'
 * '<S6>'   : 'feedback_control/Discrete PID Controller/I Gain'
 * '<S7>'   : 'feedback_control/Discrete PID Controller/Ideal P Gain'
 * '<S8>'   : 'feedback_control/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S9>'   : 'feedback_control/Discrete PID Controller/Integrator'
 * '<S10>'  : 'feedback_control/Discrete PID Controller/Integrator ICs'
 * '<S11>'  : 'feedback_control/Discrete PID Controller/N Copy'
 * '<S12>'  : 'feedback_control/Discrete PID Controller/N Gain'
 * '<S13>'  : 'feedback_control/Discrete PID Controller/P Copy'
 * '<S14>'  : 'feedback_control/Discrete PID Controller/Parallel P Gain'
 * '<S15>'  : 'feedback_control/Discrete PID Controller/Reset Signal'
 * '<S16>'  : 'feedback_control/Discrete PID Controller/Saturation'
 * '<S17>'  : 'feedback_control/Discrete PID Controller/Saturation Fdbk'
 * '<S18>'  : 'feedback_control/Discrete PID Controller/Sum'
 * '<S19>'  : 'feedback_control/Discrete PID Controller/Sum Fdbk'
 * '<S20>'  : 'feedback_control/Discrete PID Controller/Tracking Mode'
 * '<S21>'  : 'feedback_control/Discrete PID Controller/Tracking Mode Sum'
 * '<S22>'  : 'feedback_control/Discrete PID Controller/Tsamp - Integral'
 * '<S23>'  : 'feedback_control/Discrete PID Controller/Tsamp - Ngain'
 * '<S24>'  : 'feedback_control/Discrete PID Controller/postSat Signal'
 * '<S25>'  : 'feedback_control/Discrete PID Controller/preSat Signal'
 * '<S26>'  : 'feedback_control/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S27>'  : 'feedback_control/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S28>'  : 'feedback_control/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S29>'  : 'feedback_control/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S30>'  : 'feedback_control/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S31>'  : 'feedback_control/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S32>'  : 'feedback_control/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S33>'  : 'feedback_control/Discrete PID Controller/Integrator/Discrete'
 * '<S34>'  : 'feedback_control/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S35>'  : 'feedback_control/Discrete PID Controller/N Copy/Disabled'
 * '<S36>'  : 'feedback_control/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S37>'  : 'feedback_control/Discrete PID Controller/P Copy/Disabled'
 * '<S38>'  : 'feedback_control/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S39>'  : 'feedback_control/Discrete PID Controller/Reset Signal/Disabled'
 * '<S40>'  : 'feedback_control/Discrete PID Controller/Saturation/Passthrough'
 * '<S41>'  : 'feedback_control/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S42>'  : 'feedback_control/Discrete PID Controller/Sum/Sum_PID'
 * '<S43>'  : 'feedback_control/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S44>'  : 'feedback_control/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S45>'  : 'feedback_control/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S46>'  : 'feedback_control/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S47>'  : 'feedback_control/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S48>'  : 'feedback_control/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S49>'  : 'feedback_control/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_feedback_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
