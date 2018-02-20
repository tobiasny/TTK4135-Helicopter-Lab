/*
 * helikopter_task4_without_feed_data.c
 *
 * Code generation for model "helikopter_task4_without_feed".
 *
 * Model version              : 1.1
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Feb 20 09:24:21 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "helikopter_task4_without_feed.h"
#include "helikopter_task4_without_feed_private.h"

/* Block parameters (auto storage) */
P_helikopter_task4_without_fe_T helikopter_task4_without_feed_P = {
  /*  Variable: K
   * Referenced by: '<Root>/Gain'
   */
  { -0.52898293589902023, 1.2467209169856375E-16, -2.1270666096519761,
    -4.7322121082974708E-16, 1.1201741852240816, 1.9829709545131969E-16,
    0.37393478440998479, 4.925303233055202E-17, 2.5266495314666226E-16,
    0.22281342325868908, 3.4527981745229181E-16, 0.32171974309735729 },
  10.954808019028201,                  /* Variable: K_ed
                                        * Referenced by: '<S5>/K_ed'
                                        */
  0.27387020047570504,                 /* Variable: K_ei
                                        * Referenced by: '<S5>/K_ei'
                                        */
  2.7387020047570503,                  /* Variable: K_ep
                                        * Referenced by: '<S5>/K_ep'
                                        */
  5.1571865443425073,                  /* Variable: K_pd
                                        * Referenced by: '<S7>/K_pd'
                                        */
  4.6414678899082569,                  /* Variable: K_pp
                                        * Referenced by: '<S7>/K_pp'
                                        */
  0.3,                                 /* Variable: Vd_ff
                                        * Referenced by: '<Root>/Vd_bias'
                                        */
  6.2,                                 /* Variable: Vs_ff
                                        * Referenced by: '<Root>/Vs_bias'
                                        */
  10.0,                                /* Mask Parameter: HILInitialize_analog_input_maxi
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* Mask Parameter: HILInitialize_analog_input_mini
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  10.0,                                /* Mask Parameter: HILInitialize_analog_output_max
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* Mask Parameter: HILInitialize_analog_output_min
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_final_analog_outp
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_final_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_initial_analog_ou
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_initial_pwm_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  24305.934065934067,                  /* Mask Parameter: HILInitialize_pwm_frequency
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_leading_deadb
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_trailing_dead
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_g
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_n
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_watchdog_analog_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_watchdog_pwm_outp
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILReadEncoderTimebase_clock
                                        * Referenced by: '<S6>/HIL Read Encoder Timebase'
                                        */

  /*  Mask Parameter: HILInitialize_hardware_clocks
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 1, 2 },
  0,                                   /* Mask Parameter: HILInitialize_initial_encoder_c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_alignment
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_configuration
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_modes
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_pwm_polarity
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_watchdog_digital_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */

  /*  Mask Parameter: HILInitialize_analog_input_chan
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Mask Parameter: HILInitialize_analog_output_cha
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Mask Parameter: HILReadEncoderTimebase_channels
   * Referenced by: '<S6>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },

  /*  Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S6>/HIL Write Analog'
   */
  { 0U, 1U },

  /*  Mask Parameter: HILInitialize_encoder_channels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Mask Parameter: HILInitialize_pwm_channels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
  4U,                                  /* Mask Parameter: HILInitialize_quadrature
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  500U,                                /* Mask Parameter: HILReadEncoderTimebase_samples_
                                        * Referenced by: '<S6>/HIL Read Encoder Timebase'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_final_digital_out
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_initial_digital_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_input_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_inpu_e
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_output
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_outp_e
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_out_ct
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_outp_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_b
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequen
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequ_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_params_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_param_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_l
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_i
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_e
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_g
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_ou_aj
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_count
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_cou_p
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_param
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_par_e
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_other_outpu_b
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_l
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_j
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_b
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_params_at
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_params__p
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  -0.0015339807878856412,              /* Expression: -2 * pi /4096
                                        * Referenced by: '<S6>/Elevation: Count to rad'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S8>/Gain'
                                        */
  -30.0,                               /* Expression: -30
                                        * Referenced by: '<Root>/elavation_offset [deg]'
                                        */
  0.00076699039394282058,              /* Expression: 2*pi/8192
                                        * Referenced by: '<S6>/Travel: Count to rad'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain'
                                        */
  180.0,                               /* Expression: 180
                                        * Referenced by: '<Root>/elavation_offset [deg]1'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S4>/Gain1'
                                        */
  0.0015339807878856412,               /* Expression: 2*pi /4096
                                        * Referenced by: '<S6>/Pitch: Count to rad'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S10>/Gain'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S3>/Gain1'
                                        */
  -10.0,                               /* Computed Parameter: TravelTransferFcn_A
                                        * Referenced by: '<S6>/Travel: Transfer Fcn'
                                        */
  -100.0,                              /* Computed Parameter: TravelTransferFcn_C
                                        * Referenced by: '<S6>/Travel: Transfer Fcn'
                                        */
  10.0,                                /* Computed Parameter: TravelTransferFcn_D
                                        * Referenced by: '<S6>/Travel: Transfer Fcn'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S14>/Gain'
                                        */
  -30.0,                               /* Computed Parameter: PitchTransferFcn_A
                                        * Referenced by: '<S6>/Pitch: Transfer Fcn'
                                        */
  -900.0,                              /* Computed Parameter: PitchTransferFcn_C
                                        * Referenced by: '<S6>/Pitch: Transfer Fcn'
                                        */
  30.0,                                /* Computed Parameter: PitchTransferFcn_D
                                        * Referenced by: '<S6>/Pitch: Transfer Fcn'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S11>/Gain'
                                        */
  -10.0,                               /* Computed Parameter: ElevationTransferFcn_A
                                        * Referenced by: '<S6>/Elevation: Transfer Fcn'
                                        */
  -100.0,                              /* Computed Parameter: ElevationTransferFcn_C
                                        * Referenced by: '<S6>/Elevation: Transfer Fcn'
                                        */
  10.0,                                /* Computed Parameter: ElevationTransferFcn_D
                                        * Referenced by: '<S6>/Elevation: Transfer Fcn'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S9>/Gain'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S2>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Integrator'
                                        */
  0.0,                                 /* Expression: inf
                                        * Referenced by: '<S5>/Integrator'
                                        */
  0.0,                                 /* Expression: -inf
                                        * Referenced by: '<S5>/Integrator'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S1>/Back gain'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S1>/Front gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S12>/Gain'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S6>/Back motor: Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S6>/Back motor: Saturation'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S6>/Front motor: Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S6>/Front motor: Saturation'
                                        */
  1,                                   /* Computed Parameter: HILReadEncoderTimebase_Active
                                        * Referenced by: '<S6>/HIL Read Encoder Timebase'
                                        */
  0                                    /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<S6>/HIL Write Analog'
                                        */
};
