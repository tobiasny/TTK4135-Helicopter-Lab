/*
 * helikopter_task5.c
 *
 * Code generation for model "helikopter_task5".
 *
 * Model version              : 1.197
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Feb 20 12:10:26 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "helikopter_task5.h"
#include "helikopter_task5_private.h"
#include "helikopter_task5_dt.h"

/* Block signals (auto storage) */
B_helikopter_task5_T helikopter_task5_B;

/* Continuous states */
X_helikopter_task5_T helikopter_task5_X;

/* Block states (auto storage) */
DW_helikopter_task5_T helikopter_task5_DW;

/* Real-time model */
RT_MODEL_helikopter_task5_T helikopter_task5_M_;
RT_MODEL_helikopter_task5_T *const helikopter_task5_M = &helikopter_task5_M_;

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  helikopter_task5_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void helikopter_task5_output(void)
{
  /* local block i/o variables */
  real_T rtb_Derivative;
  real_T rtb_Backgain;
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_Gain1_i;
  real_T *lastU;
  real_T rtb_Gain1_idx_4;
  real_T rtb_Gain1_idx_5;
  if (rtmIsMajorTimeStep(helikopter_task5_M)) {
    /* set solver stop time */
    if (!(helikopter_task5_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&helikopter_task5_M->solverInfo,
                            ((helikopter_task5_M->Timing.clockTickH0 + 1) *
        helikopter_task5_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&helikopter_task5_M->solverInfo,
                            ((helikopter_task5_M->Timing.clockTick0 + 1) *
        helikopter_task5_M->Timing.stepSize0 +
        helikopter_task5_M->Timing.clockTickH0 *
        helikopter_task5_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(helikopter_task5_M)) {
    helikopter_task5_M->Timing.t[0] = rtsiGetT(&helikopter_task5_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(helikopter_task5_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S6>/HIL Read Encoder Timebase' */

    /* S-Function Block: helikopter_task5/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (helikopter_task5_DW.HILReadEncoderTimebase_Task, 1,
         &helikopter_task5_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          helikopter_task5_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          helikopter_task5_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_Gain1_i = helikopter_task5_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }
  }

  /* Clock: '<Root>/Clock' */
  helikopter_task5_B.Clock = helikopter_task5_M->Timing.t[0];
  if (rtmIsMajorTimeStep(helikopter_task5_M)) {
    /* ToFile: '<Root>/To File2' */
    {
      if (!(++helikopter_task5_DW.ToFile2_IWORK.Decimation % 1) &&
          (helikopter_task5_DW.ToFile2_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) helikopter_task5_DW.ToFile2_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          helikopter_task5_DW.ToFile2_IWORK.Decimation = 0;
          u[0] = helikopter_task5_M->Timing.t[1];
          u[1] = helikopter_task5_B.Clock;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(helikopter_task5_M,
                              "Error writing to MAT-file measured_time.mat");
            return;
          }

          if (((++helikopter_task5_DW.ToFile2_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file measured_time.mat.\n");
          }
        }
      }
    }

    /* Gain: '<S6>/Elevation: Count to rad' */
    helikopter_task5_B.ElevationCounttorad =
      helikopter_task5_P.ElevationCounttorad_Gain * rtb_Gain1_i;

    /* Gain: '<S8>/Gain' */
    helikopter_task5_B.Gain = helikopter_task5_P.Gain_Gain *
      helikopter_task5_B.ElevationCounttorad;

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/elavation_offset [deg]'
     */
    helikopter_task5_B.Sum = helikopter_task5_B.Gain +
      helikopter_task5_P.elavation_offsetdeg_Value;

    /* Gain: '<S6>/Travel: Count to rad' */
    helikopter_task5_B.TravelCounttorad =
      helikopter_task5_P.TravelCounttorad_Gain * rtb_HILReadEncoderTimebase_o1;

    /* Gain: '<S13>/Gain' */
    helikopter_task5_B.Gain_p = helikopter_task5_P.Gain_Gain_a *
      helikopter_task5_B.TravelCounttorad;

    /* Sum: '<Root>/Sum5' incorporates:
     *  Constant: '<Root>/elavation_offset [deg]1'
     */
    helikopter_task5_B.Sum5 = helikopter_task5_B.Gain_p +
      helikopter_task5_P.elavation_offsetdeg1_Value;

    /* Gain: '<S4>/Gain1' */
    rtb_Gain1_i = helikopter_task5_P.Gain1_Gain * helikopter_task5_B.Sum5;

    /* ToFile: '<Root>/To File' */
    {
      if (!(++helikopter_task5_DW.ToFile_IWORK.Decimation % 1) &&
          (helikopter_task5_DW.ToFile_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) helikopter_task5_DW.ToFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          helikopter_task5_DW.ToFile_IWORK.Decimation = 0;
          u[0] = helikopter_task5_M->Timing.t[1];
          u[1] = rtb_Gain1_i;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(helikopter_task5_M,
                              "Error writing to MAT-file measured_travel.mat");
            return;
          }

          if (((++helikopter_task5_DW.ToFile_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file measured_travel.mat.\n");
          }
        }
      }
    }

    /* Gain: '<S6>/Pitch: Count to rad' */
    helikopter_task5_B.PitchCounttorad = helikopter_task5_P.PitchCounttorad_Gain
      * rtb_HILReadEncoderTimebase_o2;

    /* Gain: '<S10>/Gain' */
    helikopter_task5_B.Gain_i = helikopter_task5_P.Gain_Gain_ar *
      helikopter_task5_B.PitchCounttorad;

    /* Gain: '<S3>/Gain1' */
    rtb_Gain1_i = helikopter_task5_P.Gain1_Gain_e * helikopter_task5_B.Gain_i;

    /* ToFile: '<Root>/To File1' */
    {
      if (!(++helikopter_task5_DW.ToFile1_IWORK.Decimation % 1) &&
          (helikopter_task5_DW.ToFile1_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) helikopter_task5_DW.ToFile1_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          helikopter_task5_DW.ToFile1_IWORK.Decimation = 0;
          u[0] = helikopter_task5_M->Timing.t[1];
          u[1] = rtb_Gain1_i;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(helikopter_task5_M,
                              "Error writing to MAT-file measured_pitch.mat");
            return;
          }

          if (((++helikopter_task5_DW.ToFile1_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file measured_pitch.mat.\n");
          }
        }
      }
    }
  }

  /* FromWorkspace: '<Root>/From Workspace' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task5_DW.FromWorkspace_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task5_DW.FromWorkspace_PWORK.TimePtr;
    int_T currTimeIndex = helikopter_task5_DW.FromWorkspace_IWORK.PrevIndex;
    real_T t = helikopter_task5_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[80]) {
      currTimeIndex = 79;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    helikopter_task5_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_Derivative = pDataValues[currTimeIndex];
        } else {
          rtb_Derivative = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Derivative = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 81;
      }
    }
  }

  /* TransferFcn: '<S6>/Travel: Transfer Fcn' */
  rtb_Backgain = 0.0;
  rtb_Backgain += helikopter_task5_P.TravelTransferFcn_C *
    helikopter_task5_X.TravelTransferFcn_CSTATE;
  rtb_Backgain += helikopter_task5_P.TravelTransferFcn_D *
    helikopter_task5_B.TravelCounttorad;

  /* Gain: '<S14>/Gain' */
  helikopter_task5_B.Gain_d = helikopter_task5_P.Gain_Gain_l * rtb_Backgain;

  /* TransferFcn: '<S6>/Pitch: Transfer Fcn' */
  rtb_Backgain = 0.0;
  rtb_Backgain += helikopter_task5_P.PitchTransferFcn_C *
    helikopter_task5_X.PitchTransferFcn_CSTATE;
  rtb_Backgain += helikopter_task5_P.PitchTransferFcn_D *
    helikopter_task5_B.PitchCounttorad;

  /* Gain: '<S11>/Gain' */
  helikopter_task5_B.Gain_b = helikopter_task5_P.Gain_Gain_ae * rtb_Backgain;

  /* TransferFcn: '<S6>/Elevation: Transfer Fcn' */
  rtb_Backgain = 0.0;
  rtb_Backgain += helikopter_task5_P.ElevationTransferFcn_C *
    helikopter_task5_X.ElevationTransferFcn_CSTATE;
  rtb_Backgain += helikopter_task5_P.ElevationTransferFcn_D *
    helikopter_task5_B.ElevationCounttorad;

  /* Gain: '<S9>/Gain' */
  helikopter_task5_B.Gain_dg = helikopter_task5_P.Gain_Gain_n * rtb_Backgain;

  /* Gain: '<S2>/Gain1' */
  rtb_Gain1_idx_4 = helikopter_task5_P.Gain1_Gain_f * helikopter_task5_B.Sum;
  rtb_Gain1_idx_5 = helikopter_task5_P.Gain1_Gain_f * helikopter_task5_B.Gain_dg;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Vd_bias'
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S7>/K_pd'
   *  Gain: '<S7>/K_pp'
   *  Sum: '<S7>/Sum2'
   *  Sum: '<S7>/Sum3'
   */
  helikopter_task5_B.Sum1 = ((rtb_Derivative - helikopter_task5_P.Gain1_Gain_f *
    helikopter_task5_B.Gain_i) * helikopter_task5_P.K_pp -
    helikopter_task5_P.Gain1_Gain_f * helikopter_task5_B.Gain_b *
    helikopter_task5_P.K_pd) + helikopter_task5_P.Vd_ff;
  if (rtmIsMajorTimeStep(helikopter_task5_M)) {
  }

  /* Integrator: '<S5>/Integrator'
   *
   * Regarding '<S5>/Integrator':
   *  Limited Integrator
   */
  if (helikopter_task5_X.Integrator_CSTATE >=
      helikopter_task5_P.Integrator_UpperSat ) {
    helikopter_task5_X.Integrator_CSTATE =
      helikopter_task5_P.Integrator_UpperSat;
  } else if (helikopter_task5_X.Integrator_CSTATE <=
             (helikopter_task5_P.Integrator_LowerSat) ) {
    helikopter_task5_X.Integrator_CSTATE =
      (helikopter_task5_P.Integrator_LowerSat);
  }

  rtb_Backgain = helikopter_task5_X.Integrator_CSTATE;

  /* FromWorkspace: '<Root>/From Workspace1' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task5_DW.FromWorkspace1_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task5_DW.FromWorkspace1_PWORK.TimePtr;
    int_T currTimeIndex = helikopter_task5_DW.FromWorkspace1_IWORK.PrevIndex;
    real_T t = helikopter_task5_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[80]) {
      currTimeIndex = 79;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    helikopter_task5_DW.FromWorkspace1_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_Derivative = pDataValues[currTimeIndex];
        } else {
          rtb_Derivative = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Derivative = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 81;
      }
    }
  }

  /* Sum: '<S5>/Sum' */
  rtb_Derivative -= rtb_Gain1_idx_4;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Vs_bias'
   *  Gain: '<S5>/K_ed'
   *  Gain: '<S5>/K_ep'
   *  Sum: '<S5>/Sum1'
   */
  helikopter_task5_B.Sum2 = ((helikopter_task5_P.K_ep * rtb_Derivative +
    rtb_Backgain) - helikopter_task5_P.K_ed * rtb_Gain1_idx_5) +
    helikopter_task5_P.Vs_ff;
  if (rtmIsMajorTimeStep(helikopter_task5_M)) {
  }

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  rtb_Backgain = (helikopter_task5_B.Sum2 - helikopter_task5_B.Sum1) *
    helikopter_task5_P.Backgain_Gain;

  /* Gain: '<S5>/K_ei' */
  helikopter_task5_B.K_ei = helikopter_task5_P.K_ei * rtb_Derivative;
  if (rtmIsMajorTimeStep(helikopter_task5_M)) {
  }

  /* Derivative: '<S6>/Derivative' */
  if ((helikopter_task5_DW.TimeStampA >= helikopter_task5_M->Timing.t[0]) &&
      (helikopter_task5_DW.TimeStampB >= helikopter_task5_M->Timing.t[0])) {
    rtb_Derivative = 0.0;
  } else {
    rtb_Gain1_idx_4 = helikopter_task5_DW.TimeStampA;
    lastU = &helikopter_task5_DW.LastUAtTimeA;
    if (helikopter_task5_DW.TimeStampA < helikopter_task5_DW.TimeStampB) {
      if (helikopter_task5_DW.TimeStampB < helikopter_task5_M->Timing.t[0]) {
        rtb_Gain1_idx_4 = helikopter_task5_DW.TimeStampB;
        lastU = &helikopter_task5_DW.LastUAtTimeB;
      }
    } else {
      if (helikopter_task5_DW.TimeStampA >= helikopter_task5_M->Timing.t[0]) {
        rtb_Gain1_idx_4 = helikopter_task5_DW.TimeStampB;
        lastU = &helikopter_task5_DW.LastUAtTimeB;
      }
    }

    rtb_Derivative = (helikopter_task5_B.PitchCounttorad - *lastU) /
      (helikopter_task5_M->Timing.t[0] - rtb_Gain1_idx_4);
  }

  /* End of Derivative: '<S6>/Derivative' */

  /* Gain: '<S12>/Gain' */
  helikopter_task5_B.Gain_l = helikopter_task5_P.Gain_Gain_a1 * rtb_Derivative;
  if (rtmIsMajorTimeStep(helikopter_task5_M)) {
  }

  /* Saturate: '<S6>/Back motor: Saturation' */
  if (rtb_Backgain > helikopter_task5_P.BackmotorSaturation_UpperSat) {
    helikopter_task5_B.BackmotorSaturation =
      helikopter_task5_P.BackmotorSaturation_UpperSat;
  } else if (rtb_Backgain < helikopter_task5_P.BackmotorSaturation_LowerSat) {
    helikopter_task5_B.BackmotorSaturation =
      helikopter_task5_P.BackmotorSaturation_LowerSat;
  } else {
    helikopter_task5_B.BackmotorSaturation = rtb_Backgain;
  }

  /* End of Saturate: '<S6>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(helikopter_task5_M)) {
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  rtb_Gain1_idx_4 = (helikopter_task5_B.Sum1 + helikopter_task5_B.Sum2) *
    helikopter_task5_P.Frontgain_Gain;

  /* Saturate: '<S6>/Front motor: Saturation' */
  if (rtb_Gain1_idx_4 > helikopter_task5_P.FrontmotorSaturation_UpperSat) {
    helikopter_task5_B.FrontmotorSaturation =
      helikopter_task5_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Gain1_idx_4 < helikopter_task5_P.FrontmotorSaturation_LowerSat)
  {
    helikopter_task5_B.FrontmotorSaturation =
      helikopter_task5_P.FrontmotorSaturation_LowerSat;
  } else {
    helikopter_task5_B.FrontmotorSaturation = rtb_Gain1_idx_4;
  }

  /* End of Saturate: '<S6>/Front motor: Saturation' */
  if (rtmIsMajorTimeStep(helikopter_task5_M)) {
    /* S-Function (hil_write_analog_block): '<S6>/HIL Write Analog' */

    /* S-Function Block: helikopter_task5/Helicopter_interface/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      helikopter_task5_DW.HILWriteAnalog_Buffer[0] =
        helikopter_task5_B.FrontmotorSaturation;
      helikopter_task5_DW.HILWriteAnalog_Buffer[1] =
        helikopter_task5_B.BackmotorSaturation;
      result = hil_write_analog(helikopter_task5_DW.HILInitialize_Card,
        helikopter_task5_P.HILWriteAnalog_channels, 2,
        &helikopter_task5_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
      }
    }
  }
}

/* Model update function */
void helikopter_task5_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<S6>/Derivative' */
  if (helikopter_task5_DW.TimeStampA == (rtInf)) {
    helikopter_task5_DW.TimeStampA = helikopter_task5_M->Timing.t[0];
    lastU = &helikopter_task5_DW.LastUAtTimeA;
  } else if (helikopter_task5_DW.TimeStampB == (rtInf)) {
    helikopter_task5_DW.TimeStampB = helikopter_task5_M->Timing.t[0];
    lastU = &helikopter_task5_DW.LastUAtTimeB;
  } else if (helikopter_task5_DW.TimeStampA < helikopter_task5_DW.TimeStampB) {
    helikopter_task5_DW.TimeStampA = helikopter_task5_M->Timing.t[0];
    lastU = &helikopter_task5_DW.LastUAtTimeA;
  } else {
    helikopter_task5_DW.TimeStampB = helikopter_task5_M->Timing.t[0];
    lastU = &helikopter_task5_DW.LastUAtTimeB;
  }

  *lastU = helikopter_task5_B.PitchCounttorad;

  /* End of Update for Derivative: '<S6>/Derivative' */
  if (rtmIsMajorTimeStep(helikopter_task5_M)) {
    rt_ertODEUpdateContinuousStates(&helikopter_task5_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++helikopter_task5_M->Timing.clockTick0)) {
    ++helikopter_task5_M->Timing.clockTickH0;
  }

  helikopter_task5_M->Timing.t[0] = rtsiGetSolverStopTime
    (&helikopter_task5_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++helikopter_task5_M->Timing.clockTick1)) {
      ++helikopter_task5_M->Timing.clockTickH1;
    }

    helikopter_task5_M->Timing.t[1] = helikopter_task5_M->Timing.clockTick1 *
      helikopter_task5_M->Timing.stepSize1 +
      helikopter_task5_M->Timing.clockTickH1 *
      helikopter_task5_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void helikopter_task5_derivatives(void)
{
  XDot_helikopter_task5_T *_rtXdot;
  _rtXdot = ((XDot_helikopter_task5_T *) helikopter_task5_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S6>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += helikopter_task5_P.TravelTransferFcn_A *
    helikopter_task5_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += helikopter_task5_B.TravelCounttorad;

  /* Derivatives for TransferFcn: '<S6>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += helikopter_task5_P.PitchTransferFcn_A *
    helikopter_task5_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += helikopter_task5_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S6>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    helikopter_task5_P.ElevationTransferFcn_A *
    helikopter_task5_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += helikopter_task5_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( helikopter_task5_X.Integrator_CSTATE <=
            (helikopter_task5_P.Integrator_LowerSat) );
    usat = ( helikopter_task5_X.Integrator_CSTATE >=
            helikopter_task5_P.Integrator_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (helikopter_task5_B.K_ei > 0)) ||
        (usat && (helikopter_task5_B.K_ei < 0)) ) {
      ((XDot_helikopter_task5_T *) helikopter_task5_M->ModelData.derivs)
        ->Integrator_CSTATE = helikopter_task5_B.K_ei;
    } else {
      /* in saturation */
      ((XDot_helikopter_task5_T *) helikopter_task5_M->ModelData.derivs)
        ->Integrator_CSTATE = 0.0;
    }
  }
}

/* Model initialize function */
void helikopter_task5_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helikopter_task5/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &helikopter_task5_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (helikopter_task5_DW.HILInitialize_Card, "update_rate=normal;decimation=1",
       32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(helikopter_task5_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
      return;
    }

    if ((helikopter_task5_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (helikopter_task5_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &helikopter_task5_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = helikopter_task5_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &helikopter_task5_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = helikopter_task5_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges
        (helikopter_task5_DW.HILInitialize_Card,
         helikopter_task5_P.HILInitialize_analog_input_chan, 8U,
         &helikopter_task5_DW.HILInitialize_AIMinimums[0],
         &helikopter_task5_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task5_P.HILInitialize_set_analog_output && !is_switching) ||
        (helikopter_task5_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &helikopter_task5_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = helikopter_task5_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &helikopter_task5_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = helikopter_task5_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges
        (helikopter_task5_DW.HILInitialize_Card,
         helikopter_task5_P.HILInitialize_analog_output_cha, 8U,
         &helikopter_task5_DW.HILInitialize_AOMinimums[0],
         &helikopter_task5_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task5_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (helikopter_task5_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &helikopter_task5_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helikopter_task5_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(helikopter_task5_DW.HILInitialize_Card,
        helikopter_task5_P.HILInitialize_analog_output_cha, 8U,
        &helikopter_task5_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
        return;
      }
    }

    if (helikopter_task5_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &helikopter_task5_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helikopter_task5_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (helikopter_task5_DW.HILInitialize_Card,
         helikopter_task5_P.HILInitialize_analog_output_cha, 8U,
         &helikopter_task5_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task5_P.HILInitialize_set_encoder_param && !is_switching) ||
        (helikopter_task5_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &helikopter_task5_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = helikopter_task5_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (helikopter_task5_DW.HILInitialize_Card,
         helikopter_task5_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &helikopter_task5_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task5_P.HILInitialize_set_encoder_count && !is_switching) ||
        (helikopter_task5_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &helikopter_task5_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            helikopter_task5_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(helikopter_task5_DW.HILInitialize_Card,
        helikopter_task5_P.HILInitialize_encoder_channels, 8U,
        &helikopter_task5_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task5_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (helikopter_task5_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &helikopter_task5_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = helikopter_task5_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(helikopter_task5_DW.HILInitialize_Card,
        helikopter_task5_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &helikopter_task5_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          helikopter_task5_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues =
          &helikopter_task5_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            helikopter_task5_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = p_HILInitialize_pwm_channels[i1];
            helikopter_task5_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = helikopter_task5_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            helikopter_task5_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = p_HILInitialize_pwm_channels[i1];
            helikopter_task5_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              helikopter_task5_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(helikopter_task5_DW.HILInitialize_Card,
          &helikopter_task5_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &helikopter_task5_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(helikopter_task5_DW.HILInitialize_Card,
          &helikopter_task5_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &helikopter_task5_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &helikopter_task5_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            helikopter_task5_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &helikopter_task5_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = helikopter_task5_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &helikopter_task5_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = helikopter_task5_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(helikopter_task5_DW.HILInitialize_Card,
        helikopter_task5_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &helikopter_task5_DW.HILInitialize_POModeValues
        [0],
        (t_pwm_alignment *) &helikopter_task5_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &helikopter_task5_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &helikopter_task5_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] =
            helikopter_task5_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &helikopter_task5_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helikopter_task5_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(helikopter_task5_DW.HILInitialize_Card,
        helikopter_task5_P.HILInitialize_pwm_channels, 8U,
        &helikopter_task5_DW.HILInitialize_POSortedFreqs[0],
        &helikopter_task5_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task5_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (helikopter_task5_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &helikopter_task5_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helikopter_task5_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(helikopter_task5_DW.HILInitialize_Card,
        helikopter_task5_P.HILInitialize_pwm_channels, 8U,
        &helikopter_task5_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
        return;
      }
    }

    if (helikopter_task5_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &helikopter_task5_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helikopter_task5_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (helikopter_task5_DW.HILInitialize_Card,
         helikopter_task5_P.HILInitialize_pwm_channels, 8U,
         &helikopter_task5_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S6>/HIL Read Encoder Timebase' */

  /* S-Function Block: helikopter_task5/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (helikopter_task5_DW.HILInitialize_Card,
       helikopter_task5_P.HILReadEncoderTimebase_samples_,
       helikopter_task5_P.HILReadEncoderTimebase_channels, 3,
       &helikopter_task5_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
    }
  }

  /* Start for ToFile: '<Root>/To File2' */
  {
    char fileName[509] = "measured_time.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(helikopter_task5_M,
                        "Error creating .mat file measured_time.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"measured_time")) {
      rtmSetErrorStatus(helikopter_task5_M,
                        "Error writing mat file header to file measured_time.mat");
      return;
    }

    helikopter_task5_DW.ToFile2_IWORK.Count = 0;
    helikopter_task5_DW.ToFile2_IWORK.Decimation = -1;
    helikopter_task5_DW.ToFile2_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File' */
  {
    char fileName[509] = "measured_travel.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(helikopter_task5_M,
                        "Error creating .mat file measured_travel.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"measured_travel")) {
      rtmSetErrorStatus(helikopter_task5_M,
                        "Error writing mat file header to file measured_travel.mat");
      return;
    }

    helikopter_task5_DW.ToFile_IWORK.Count = 0;
    helikopter_task5_DW.ToFile_IWORK.Decimation = -1;
    helikopter_task5_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File1' */
  {
    char fileName[509] = "measured_pitch.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(helikopter_task5_M,
                        "Error creating .mat file measured_pitch.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"measured_pitch")) {
      rtmSetErrorStatus(helikopter_task5_M,
                        "Error writing mat file header to file measured_pitch.mat");
      return;
    }

    helikopter_task5_DW.ToFile1_IWORK.Count = 0;
    helikopter_task5_DW.ToFile1_IWORK.Decimation = -1;
    helikopter_task5_DW.ToFile1_PWORK.FilePtr = fp;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75,
      2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0,
      5.25, 5.5, 5.75, 6.0, 6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.25,
      8.5, 8.75, 9.0, 9.25, 9.5, 9.75, 10.0, 10.25, 10.5, 10.75, 11.0, 11.25,
      11.5, 11.75, 12.0, 12.25, 12.5, 12.75, 13.0, 13.25, 13.5, 13.75, 14.0,
      14.25, 14.5, 14.75, 15.0, 15.25, 15.5, 15.75, 16.0, 16.25, 16.5, 16.75,
      17.0, 17.25, 17.5, 17.75, 18.0, 18.25, 18.5, 18.75, 19.0, 19.25, 19.5,
      19.75, 20.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.52359877559829882,
      0.52359877559829882, 0.52359877559829882, 0.52359877559829882,
      0.52359877559829882, 0.52359877559829882, 0.52359877559829882,
      0.52359877559829882, 0.52359877559829882, 0.52359877559829882,
      0.52359877559829882, 0.52359877559829882, 0.33488060791579954,
      -0.0761704689345384, -0.38340462214554494, -0.52359877559829882,
      -0.52359877559829882, -0.52359877559829882, -0.52359877559829882,
      -0.52359877559829882, -0.52359877559829882, -0.52359877559829882,
      -0.52359877559829882, -0.52359877559829882, -0.4868467986108142,
      -0.40380506652565146, -0.32604722763622035, -0.25570053531427128,
      -0.1940892191572563, -0.14185395328345068, -0.099080055201048872,
      -0.065404648063688425, -0.040119985086602243, -0.022253313801007049,
      -0.010643369673724019, -0.00398745922929878, -0.0009039855457261348,
      -1.4152773240766007E-7, -9.0979029977805061E-7, 2.3621848807350944E-7,
      2.3621848807350944E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task5_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    helikopter_task5_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    helikopter_task5_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace1' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75,
      2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0,
      5.25, 5.5, 5.75, 6.0, 6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.25,
      8.5, 8.75, 9.0, 9.25, 9.5, 9.75, 10.0, 10.25, 10.5, 10.75, 11.0, 11.25,
      11.5, 11.75, 12.0, 12.25, 12.5, 12.75, 13.0, 13.25, 13.5, 13.75, 14.0,
      14.25, 14.5, 14.75, 15.0, 15.25, 15.5, 15.75, 16.0, 16.25, 16.5, 16.75,
      17.0, 17.25, 17.5, 17.75, 18.0, 18.25, 18.5, 18.75, 19.0, 19.25, 19.5,
      19.75, 20.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.28635464616750017,
      0.30388588092317076, 0.32058248296975528, 0.33584827976700343,
      0.34893388504151013, 0.35890354473170394, 0.3646008628410794,
      0.364600503741345, 0.35715909672476359, 0.34015288685054046,
      0.31099579392171239, 0.26656872655999581, 0.20310034571478272,
      0.11605660246739011, 2.5692972220767306E-7, 9.0152059416537432E-7,
      1.3060110585653841E-7, 9.3922123992212042E-7, 1.31350713692167E-6,
      7.88775183367056E-7, 4.3418752694850831E-7, -2.5594803124984805E-7,
      2.9880915169998741E-6, -1.3624442948750619E-7, 2.4513177987349833E-6,
      1.8866357249111926E-6, -2.7757823992634069E-9, -6.6599304937048537E-7,
      -9.4272741312939774E-7, 1.534110588518347E-6, -1.866808863627414E-7,
      2.3941172847454264E-6, -5.4708972515030294E-7, -1.2560064149311197E-6,
      -6.1723410438725673E-7, -4.3358190310357356E-7, -7.6308158950629676E-7,
      -5.1874173460306225E-7, 9.915955026771346E-7, 1.389526674397441E-6,
      1.389526674397441E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task5_DW.FromWorkspace1_PWORK.TimePtr = (void *) pTimeValues0;
    helikopter_task5_DW.FromWorkspace1_PWORK.DataPtr = (void *) pDataValues0;
    helikopter_task5_DW.FromWorkspace1_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for TransferFcn: '<S6>/Travel: Transfer Fcn' */
  helikopter_task5_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S6>/Pitch: Transfer Fcn' */
  helikopter_task5_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S6>/Elevation: Transfer Fcn' */
  helikopter_task5_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  helikopter_task5_X.Integrator_CSTATE = helikopter_task5_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<S6>/Derivative' */
  helikopter_task5_DW.TimeStampA = (rtInf);
  helikopter_task5_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void helikopter_task5_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helikopter_task5/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(helikopter_task5_DW.HILInitialize_Card);
    hil_monitor_stop_all(helikopter_task5_DW.HILInitialize_Card);
    is_switching = false;
    if ((helikopter_task5_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (helikopter_task5_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &helikopter_task5_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helikopter_task5_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((helikopter_task5_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (helikopter_task5_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &helikopter_task5_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helikopter_task5_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(helikopter_task5_DW.HILInitialize_Card
                         , helikopter_task5_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , helikopter_task5_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &helikopter_task5_DW.HILInitialize_AOVoltages[0]
                         , &helikopter_task5_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(helikopter_task5_DW.HILInitialize_Card,
            helikopter_task5_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs,
            &helikopter_task5_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(helikopter_task5_DW.HILInitialize_Card,
            helikopter_task5_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &helikopter_task5_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helikopter_task5_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(helikopter_task5_DW.HILInitialize_Card);
    hil_monitor_delete_all(helikopter_task5_DW.HILInitialize_Card);
    hil_close(helikopter_task5_DW.HILInitialize_Card);
    helikopter_task5_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<Root>/To File2' */
  {
    FILE *fp = (FILE *) helikopter_task5_DW.ToFile2_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "measured_time.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task5_M,
                          "Error closing MAT-file measured_time.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(helikopter_task5_M,
                          "Error reopening MAT-file measured_time.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, helikopter_task5_DW.ToFile2_IWORK.Count,
           "measured_time")) {
        rtmSetErrorStatus(helikopter_task5_M,
                          "Error writing header for measured_time to MAT-file measured_time.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task5_M,
                          "Error closing MAT-file measured_time.mat");
        return;
      }

      helikopter_task5_DW.ToFile2_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) helikopter_task5_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "measured_travel.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task5_M,
                          "Error closing MAT-file measured_travel.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(helikopter_task5_M,
                          "Error reopening MAT-file measured_travel.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, helikopter_task5_DW.ToFile_IWORK.Count,
           "measured_travel")) {
        rtmSetErrorStatus(helikopter_task5_M,
                          "Error writing header for measured_travel to MAT-file measured_travel.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task5_M,
                          "Error closing MAT-file measured_travel.mat");
        return;
      }

      helikopter_task5_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (FILE *) helikopter_task5_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "measured_pitch.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task5_M,
                          "Error closing MAT-file measured_pitch.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(helikopter_task5_M,
                          "Error reopening MAT-file measured_pitch.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, helikopter_task5_DW.ToFile1_IWORK.Count,
           "measured_pitch")) {
        rtmSetErrorStatus(helikopter_task5_M,
                          "Error writing header for measured_pitch to MAT-file measured_pitch.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task5_M,
                          "Error closing MAT-file measured_pitch.mat");
        return;
      }

      helikopter_task5_DW.ToFile1_PWORK.FilePtr = (NULL);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  helikopter_task5_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  helikopter_task5_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  helikopter_task5_initialize();
}

void MdlTerminate(void)
{
  helikopter_task5_terminate();
}

/* Registration function */
RT_MODEL_helikopter_task5_T *helikopter_task5(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  helikopter_task5_P.Integrator_UpperSat = rtInf;
  helikopter_task5_P.Integrator_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)helikopter_task5_M, 0,
                sizeof(RT_MODEL_helikopter_task5_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&helikopter_task5_M->solverInfo,
                          &helikopter_task5_M->Timing.simTimeStep);
    rtsiSetTPtr(&helikopter_task5_M->solverInfo, &rtmGetTPtr(helikopter_task5_M));
    rtsiSetStepSizePtr(&helikopter_task5_M->solverInfo,
                       &helikopter_task5_M->Timing.stepSize0);
    rtsiSetdXPtr(&helikopter_task5_M->solverInfo,
                 &helikopter_task5_M->ModelData.derivs);
    rtsiSetContStatesPtr(&helikopter_task5_M->solverInfo, (real_T **)
                         &helikopter_task5_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&helikopter_task5_M->solverInfo,
      &helikopter_task5_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&helikopter_task5_M->solverInfo, (&rtmGetErrorStatus
      (helikopter_task5_M)));
    rtsiSetRTModelPtr(&helikopter_task5_M->solverInfo, helikopter_task5_M);
  }

  rtsiSetSimTimeStep(&helikopter_task5_M->solverInfo, MAJOR_TIME_STEP);
  helikopter_task5_M->ModelData.intgData.f[0] =
    helikopter_task5_M->ModelData.odeF[0];
  helikopter_task5_M->ModelData.contStates = ((real_T *) &helikopter_task5_X);
  rtsiSetSolverData(&helikopter_task5_M->solverInfo, (void *)
                    &helikopter_task5_M->ModelData.intgData);
  rtsiSetSolverName(&helikopter_task5_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = helikopter_task5_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    helikopter_task5_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    helikopter_task5_M->Timing.sampleTimes =
      (&helikopter_task5_M->Timing.sampleTimesArray[0]);
    helikopter_task5_M->Timing.offsetTimes =
      (&helikopter_task5_M->Timing.offsetTimesArray[0]);

    /* task periods */
    helikopter_task5_M->Timing.sampleTimes[0] = (0.0);
    helikopter_task5_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    helikopter_task5_M->Timing.offsetTimes[0] = (0.0);
    helikopter_task5_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(helikopter_task5_M, &helikopter_task5_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = helikopter_task5_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    helikopter_task5_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(helikopter_task5_M, 45.0);
  helikopter_task5_M->Timing.stepSize0 = 0.002;
  helikopter_task5_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  helikopter_task5_M->Sizes.checksums[0] = (62978332U);
  helikopter_task5_M->Sizes.checksums[1] = (1449561892U);
  helikopter_task5_M->Sizes.checksums[2] = (1445352216U);
  helikopter_task5_M->Sizes.checksums[3] = (1152774460U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    helikopter_task5_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(helikopter_task5_M->extModeInfo,
      &helikopter_task5_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(helikopter_task5_M->extModeInfo,
                        helikopter_task5_M->Sizes.checksums);
    rteiSetTPtr(helikopter_task5_M->extModeInfo, rtmGetTPtr(helikopter_task5_M));
  }

  helikopter_task5_M->solverInfoPtr = (&helikopter_task5_M->solverInfo);
  helikopter_task5_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&helikopter_task5_M->solverInfo, 0.002);
  rtsiSetSolverMode(&helikopter_task5_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  helikopter_task5_M->ModelData.blockIO = ((void *) &helikopter_task5_B);

  {
    helikopter_task5_B.Clock = 0.0;
    helikopter_task5_B.ElevationCounttorad = 0.0;
    helikopter_task5_B.Gain = 0.0;
    helikopter_task5_B.Sum = 0.0;
    helikopter_task5_B.TravelCounttorad = 0.0;
    helikopter_task5_B.Gain_p = 0.0;
    helikopter_task5_B.Sum5 = 0.0;
    helikopter_task5_B.PitchCounttorad = 0.0;
    helikopter_task5_B.Gain_i = 0.0;
    helikopter_task5_B.Gain_d = 0.0;
    helikopter_task5_B.Gain_b = 0.0;
    helikopter_task5_B.Gain_dg = 0.0;
    helikopter_task5_B.Sum1 = 0.0;
    helikopter_task5_B.Sum2 = 0.0;
    helikopter_task5_B.K_ei = 0.0;
    helikopter_task5_B.Gain_l = 0.0;
    helikopter_task5_B.BackmotorSaturation = 0.0;
    helikopter_task5_B.FrontmotorSaturation = 0.0;
  }

  /* parameters */
  helikopter_task5_M->ModelData.defaultParam = ((real_T *)&helikopter_task5_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &helikopter_task5_X;
    helikopter_task5_M->ModelData.contStates = (x);
    (void) memset((void *)&helikopter_task5_X, 0,
                  sizeof(X_helikopter_task5_T));
  }

  /* states (dwork) */
  helikopter_task5_M->ModelData.dwork = ((void *) &helikopter_task5_DW);
  (void) memset((void *)&helikopter_task5_DW, 0,
                sizeof(DW_helikopter_task5_T));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task5_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task5_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task5_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task5_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task5_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task5_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task5_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task5_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  helikopter_task5_DW.TimeStampA = 0.0;
  helikopter_task5_DW.LastUAtTimeA = 0.0;
  helikopter_task5_DW.TimeStampB = 0.0;
  helikopter_task5_DW.LastUAtTimeB = 0.0;
  helikopter_task5_DW.HILWriteAnalog_Buffer[0] = 0.0;
  helikopter_task5_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    helikopter_task5_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  helikopter_task5_M->Sizes.numContStates = (4);/* Number of continuous states */
  helikopter_task5_M->Sizes.numY = (0);/* Number of model outputs */
  helikopter_task5_M->Sizes.numU = (0);/* Number of model inputs */
  helikopter_task5_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  helikopter_task5_M->Sizes.numSampTimes = (2);/* Number of sample times */
  helikopter_task5_M->Sizes.numBlocks = (62);/* Number of blocks */
  helikopter_task5_M->Sizes.numBlockIO = (18);/* Number of block outputs */
  helikopter_task5_M->Sizes.numBlockPrms = (143);/* Sum of parameter "widths" */
  return helikopter_task5_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
