/*
 * helikopter_task3.c
 *
 * Code generation for model "helikopter_task3".
 *
 * Model version              : 1.188
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Feb 20 12:17:12 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "helikopter_task3.h"
#include "helikopter_task3_private.h"
#include "helikopter_task3_dt.h"

/* Block signals (auto storage) */
B_helikopter_task3_T helikopter_task3_B;

/* Continuous states */
X_helikopter_task3_T helikopter_task3_X;

/* Block states (auto storage) */
DW_helikopter_task3_T helikopter_task3_DW;

/* Real-time model */
RT_MODEL_helikopter_task3_T helikopter_task3_M_;
RT_MODEL_helikopter_task3_T *const helikopter_task3_M = &helikopter_task3_M_;

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
  helikopter_task3_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void helikopter_task3_output(void)
{
  /* local block i/o variables */
  real_T rtb_FromWorkspace1;
  real_T rtb_FromWorkspace2;
  real_T rtb_FromWorkspace3;
  real_T rtb_Frontgain;
  real_T rtb_Derivative;
  real_T rtb_Backgain;
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T rtb_Gain1_f;
  real_T rtb_Gain1_i;
  real_T *lastU;
  real_T rtb_Gain1_idx_2;
  real_T rtb_Gain1_idx_3;
  real_T rtb_Gain1_idx_4;
  real_T rtb_Gain1_idx_5;
  if (rtmIsMajorTimeStep(helikopter_task3_M)) {
    /* set solver stop time */
    if (!(helikopter_task3_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&helikopter_task3_M->solverInfo,
                            ((helikopter_task3_M->Timing.clockTickH0 + 1) *
        helikopter_task3_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&helikopter_task3_M->solverInfo,
                            ((helikopter_task3_M->Timing.clockTick0 + 1) *
        helikopter_task3_M->Timing.stepSize0 +
        helikopter_task3_M->Timing.clockTickH0 *
        helikopter_task3_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(helikopter_task3_M)) {
    helikopter_task3_M->Timing.t[0] = rtsiGetT(&helikopter_task3_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(helikopter_task3_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S6>/HIL Read Encoder Timebase' */

    /* S-Function Block: helikopter_task3/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (helikopter_task3_DW.HILReadEncoderTimebase_Task, 1,
         &helikopter_task3_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
      } else {
        rtb_Gain1_f = helikopter_task3_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_Gain1_i = helikopter_task3_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          helikopter_task3_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }
  }

  /* Clock: '<Root>/Clock' */
  helikopter_task3_B.Clock = helikopter_task3_M->Timing.t[0];
  if (rtmIsMajorTimeStep(helikopter_task3_M)) {
    /* ToFile: '<Root>/To File2' */
    {
      if (!(++helikopter_task3_DW.ToFile2_IWORK.Decimation % 1) &&
          (helikopter_task3_DW.ToFile2_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) helikopter_task3_DW.ToFile2_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          helikopter_task3_DW.ToFile2_IWORK.Decimation = 0;
          u[0] = helikopter_task3_M->Timing.t[1];
          u[1] = helikopter_task3_B.Clock;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(helikopter_task3_M,
                              "Error writing to MAT-file measured_time.mat");
            return;
          }

          if (((++helikopter_task3_DW.ToFile2_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file measured_time.mat.\n");
          }
        }
      }
    }

    /* Gain: '<S6>/Travel: Count to rad' */
    helikopter_task3_B.TravelCounttorad =
      helikopter_task3_P.TravelCounttorad_Gain * rtb_Gain1_f;

    /* Gain: '<S13>/Gain' */
    helikopter_task3_B.Gain = helikopter_task3_P.Gain_Gain *
      helikopter_task3_B.TravelCounttorad;

    /* Sum: '<Root>/Sum5' incorporates:
     *  Constant: '<Root>/elavation_offset [deg]1'
     */
    helikopter_task3_B.Sum5 = helikopter_task3_B.Gain +
      helikopter_task3_P.elavation_offsetdeg1_Value;

    /* Gain: '<S4>/Gain1' */
    rtb_Gain1_f = helikopter_task3_P.Gain1_Gain * helikopter_task3_B.Sum5;

    /* ToFile: '<Root>/To File' */
    {
      if (!(++helikopter_task3_DW.ToFile_IWORK.Decimation % 1) &&
          (helikopter_task3_DW.ToFile_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) helikopter_task3_DW.ToFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          helikopter_task3_DW.ToFile_IWORK.Decimation = 0;
          u[0] = helikopter_task3_M->Timing.t[1];
          u[1] = rtb_Gain1_f;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(helikopter_task3_M,
                              "Error writing to MAT-file measured_travel.mat");
            return;
          }

          if (((++helikopter_task3_DW.ToFile_IWORK.Count)*2)+1 >= 100000000) {
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
    helikopter_task3_B.PitchCounttorad = helikopter_task3_P.PitchCounttorad_Gain
      * rtb_Gain1_i;

    /* Gain: '<S10>/Gain' */
    helikopter_task3_B.Gain_i = helikopter_task3_P.Gain_Gain_a *
      helikopter_task3_B.PitchCounttorad;

    /* Gain: '<S3>/Gain1' */
    rtb_Gain1_i = helikopter_task3_P.Gain1_Gain_e * helikopter_task3_B.Gain_i;

    /* ToFile: '<Root>/To File1' */
    {
      if (!(++helikopter_task3_DW.ToFile1_IWORK.Decimation % 1) &&
          (helikopter_task3_DW.ToFile1_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) helikopter_task3_DW.ToFile1_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          helikopter_task3_DW.ToFile1_IWORK.Decimation = 0;
          u[0] = helikopter_task3_M->Timing.t[1];
          u[1] = rtb_Gain1_i;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(helikopter_task3_M,
                              "Error writing to MAT-file measured_pitch.mat");
            return;
          }

          if (((++helikopter_task3_DW.ToFile1_IWORK.Count)*2)+1 >= 100000000) {
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

  /* FromWorkspace: '<Root>/From Workspace1' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task3_DW.FromWorkspace1_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task3_DW.FromWorkspace1_PWORK.TimePtr;
    int_T currTimeIndex = helikopter_task3_DW.FromWorkspace1_IWORK.PrevIndex;
    real_T t = helikopter_task3_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[140]) {
      currTimeIndex = 139;
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

    helikopter_task3_DW.FromWorkspace1_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_FromWorkspace1 = pDataValues[currTimeIndex];
        } else {
          rtb_FromWorkspace1 = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_FromWorkspace1 = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 141;
      }
    }
  }

  /* FromWorkspace: '<Root>/From Workspace2' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task3_DW.FromWorkspace2_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task3_DW.FromWorkspace2_PWORK.TimePtr;
    int_T currTimeIndex = helikopter_task3_DW.FromWorkspace2_IWORK.PrevIndex;
    real_T t = helikopter_task3_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[140]) {
      currTimeIndex = 139;
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

    helikopter_task3_DW.FromWorkspace2_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_FromWorkspace2 = pDataValues[currTimeIndex];
        } else {
          rtb_FromWorkspace2 = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_FromWorkspace2 = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 141;
      }
    }
  }

  /* FromWorkspace: '<Root>/From Workspace3' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task3_DW.FromWorkspace3_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task3_DW.FromWorkspace3_PWORK.TimePtr;
    int_T currTimeIndex = helikopter_task3_DW.FromWorkspace3_IWORK.PrevIndex;
    real_T t = helikopter_task3_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[140]) {
      currTimeIndex = 139;
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

    helikopter_task3_DW.FromWorkspace3_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_FromWorkspace3 = pDataValues[currTimeIndex];
        } else {
          rtb_FromWorkspace3 = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_FromWorkspace3 = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 141;
      }
    }
  }

  /* FromWorkspace: '<Root>/From Workspace' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task3_DW.FromWorkspace_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task3_DW.FromWorkspace_PWORK.TimePtr;
    int_T currTimeIndex = helikopter_task3_DW.FromWorkspace_IWORK.PrevIndex;
    real_T t = helikopter_task3_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[140]) {
      currTimeIndex = 139;
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

    helikopter_task3_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_Frontgain = pDataValues[currTimeIndex];
        } else {
          rtb_Frontgain = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Frontgain = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 141;
      }
    }
  }

  /* FromWorkspace: '<Root>/From Workspace4' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task3_DW.FromWorkspace4_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task3_DW.FromWorkspace4_PWORK.TimePtr;
    int_T currTimeIndex = helikopter_task3_DW.FromWorkspace4_IWORK.PrevIndex;
    real_T t = helikopter_task3_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[140]) {
      currTimeIndex = 139;
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

    helikopter_task3_DW.FromWorkspace4_IWORK.PrevIndex = currTimeIndex;

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
        pDataValues += 141;
      }
    }
  }

  /* TransferFcn: '<S6>/Travel: Transfer Fcn' */
  rtb_Backgain = 0.0;
  rtb_Backgain += helikopter_task3_P.TravelTransferFcn_C *
    helikopter_task3_X.TravelTransferFcn_CSTATE;
  rtb_Backgain += helikopter_task3_P.TravelTransferFcn_D *
    helikopter_task3_B.TravelCounttorad;

  /* Gain: '<S14>/Gain' */
  helikopter_task3_B.Gain_d = helikopter_task3_P.Gain_Gain_l * rtb_Backgain;

  /* TransferFcn: '<S6>/Pitch: Transfer Fcn' */
  rtb_Backgain = 0.0;
  rtb_Backgain += helikopter_task3_P.PitchTransferFcn_C *
    helikopter_task3_X.PitchTransferFcn_CSTATE;
  rtb_Backgain += helikopter_task3_P.PitchTransferFcn_D *
    helikopter_task3_B.PitchCounttorad;

  /* Gain: '<S11>/Gain' */
  helikopter_task3_B.Gain_b = helikopter_task3_P.Gain_Gain_ae * rtb_Backgain;
  if (rtmIsMajorTimeStep(helikopter_task3_M)) {
    /* Gain: '<S6>/Elevation: Count to rad' */
    helikopter_task3_B.ElevationCounttorad =
      helikopter_task3_P.ElevationCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o3;

    /* Gain: '<S8>/Gain' */
    helikopter_task3_B.Gain_e = helikopter_task3_P.Gain_Gain_lv *
      helikopter_task3_B.ElevationCounttorad;

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/elavation_offset [deg]'
     */
    helikopter_task3_B.Sum = helikopter_task3_B.Gain_e +
      helikopter_task3_P.elavation_offsetdeg_Value;
  }

  /* TransferFcn: '<S6>/Elevation: Transfer Fcn' */
  rtb_Backgain = 0.0;
  rtb_Backgain += helikopter_task3_P.ElevationTransferFcn_C *
    helikopter_task3_X.ElevationTransferFcn_CSTATE;
  rtb_Backgain += helikopter_task3_P.ElevationTransferFcn_D *
    helikopter_task3_B.ElevationCounttorad;

  /* Gain: '<S9>/Gain' */
  helikopter_task3_B.Gain_dg = helikopter_task3_P.Gain_Gain_n * rtb_Backgain;

  /* Gain: '<S2>/Gain1' */
  rtb_Gain1_idx_2 = helikopter_task3_P.Gain1_Gain_f * helikopter_task3_B.Gain_i;
  rtb_Gain1_idx_3 = helikopter_task3_P.Gain1_Gain_f * helikopter_task3_B.Gain_b;
  rtb_Gain1_idx_4 = helikopter_task3_P.Gain1_Gain_f * helikopter_task3_B.Sum;
  rtb_Gain1_idx_5 = helikopter_task3_P.Gain1_Gain_f * helikopter_task3_B.Gain_dg;

  /* Gain: '<Root>/Gain' incorporates:
   *  Gain: '<S2>/Gain1'
   *  Sum: '<Root>/Sum3'
   */
  rtb_Backgain = (((helikopter_task3_P.Gain1_Gain_f * helikopter_task3_B.Sum5 -
                    rtb_FromWorkspace2) * helikopter_task3_P.K[0] +
                   (helikopter_task3_P.Gain1_Gain_f * helikopter_task3_B.Gain_d
                    - rtb_FromWorkspace3) * helikopter_task3_P.K[1]) +
                  (rtb_Gain1_idx_2 - rtb_Frontgain) * helikopter_task3_P.K[2]) +
    (rtb_Gain1_idx_3 - rtb_Derivative) * helikopter_task3_P.K[3];

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Vd_bias'
   *  Gain: '<S7>/K_pd'
   *  Gain: '<S7>/K_pp'
   *  Sum: '<Root>/Sum4'
   *  Sum: '<S7>/Sum2'
   *  Sum: '<S7>/Sum3'
   */
  helikopter_task3_B.Sum1 = (((rtb_FromWorkspace1 - rtb_Backgain) -
    rtb_Gain1_idx_2) * helikopter_task3_P.K_pp - helikopter_task3_P.K_pd *
    rtb_Gain1_idx_3) + helikopter_task3_P.Vd_ff;
  if (rtmIsMajorTimeStep(helikopter_task3_M)) {
  }

  /* Integrator: '<S5>/Integrator'
   *
   * Regarding '<S5>/Integrator':
   *  Limited Integrator
   */
  if (helikopter_task3_X.Integrator_CSTATE >=
      helikopter_task3_P.Integrator_UpperSat ) {
    helikopter_task3_X.Integrator_CSTATE =
      helikopter_task3_P.Integrator_UpperSat;
  } else if (helikopter_task3_X.Integrator_CSTATE <=
             (helikopter_task3_P.Integrator_LowerSat) ) {
    helikopter_task3_X.Integrator_CSTATE =
      (helikopter_task3_P.Integrator_LowerSat);
  }

  rtb_Backgain = helikopter_task3_X.Integrator_CSTATE;

  /* Sum: '<S5>/Sum' incorporates:
   *  Constant: '<Root>/elevation_ref'
   */
  rtb_Derivative = helikopter_task3_P.elevation_ref_Value - rtb_Gain1_idx_4;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Vs_bias'
   *  Gain: '<S5>/K_ed'
   *  Gain: '<S5>/K_ep'
   *  Sum: '<S5>/Sum1'
   */
  helikopter_task3_B.Sum2 = ((helikopter_task3_P.K_ep * rtb_Derivative +
    rtb_Backgain) - helikopter_task3_P.K_ed * rtb_Gain1_idx_5) +
    helikopter_task3_P.Vs_ff;
  if (rtmIsMajorTimeStep(helikopter_task3_M)) {
  }

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  rtb_Backgain = (helikopter_task3_B.Sum2 - helikopter_task3_B.Sum1) *
    helikopter_task3_P.Backgain_Gain;

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  rtb_Frontgain = (helikopter_task3_B.Sum1 + helikopter_task3_B.Sum2) *
    helikopter_task3_P.Frontgain_Gain;

  /* Gain: '<S5>/K_ei' */
  helikopter_task3_B.K_ei = helikopter_task3_P.K_ei * rtb_Derivative;
  if (rtmIsMajorTimeStep(helikopter_task3_M)) {
  }

  /* Derivative: '<S6>/Derivative' */
  if ((helikopter_task3_DW.TimeStampA >= helikopter_task3_M->Timing.t[0]) &&
      (helikopter_task3_DW.TimeStampB >= helikopter_task3_M->Timing.t[0])) {
    rtb_Derivative = 0.0;
  } else {
    rtb_Gain1_idx_2 = helikopter_task3_DW.TimeStampA;
    lastU = &helikopter_task3_DW.LastUAtTimeA;
    if (helikopter_task3_DW.TimeStampA < helikopter_task3_DW.TimeStampB) {
      if (helikopter_task3_DW.TimeStampB < helikopter_task3_M->Timing.t[0]) {
        rtb_Gain1_idx_2 = helikopter_task3_DW.TimeStampB;
        lastU = &helikopter_task3_DW.LastUAtTimeB;
      }
    } else {
      if (helikopter_task3_DW.TimeStampA >= helikopter_task3_M->Timing.t[0]) {
        rtb_Gain1_idx_2 = helikopter_task3_DW.TimeStampB;
        lastU = &helikopter_task3_DW.LastUAtTimeB;
      }
    }

    rtb_Derivative = (helikopter_task3_B.PitchCounttorad - *lastU) /
      (helikopter_task3_M->Timing.t[0] - rtb_Gain1_idx_2);
  }

  /* End of Derivative: '<S6>/Derivative' */

  /* Gain: '<S12>/Gain' */
  helikopter_task3_B.Gain_l = helikopter_task3_P.Gain_Gain_a1 * rtb_Derivative;
  if (rtmIsMajorTimeStep(helikopter_task3_M)) {
  }

  /* Saturate: '<S6>/Back motor: Saturation' */
  if (rtb_Backgain > helikopter_task3_P.BackmotorSaturation_UpperSat) {
    helikopter_task3_B.BackmotorSaturation =
      helikopter_task3_P.BackmotorSaturation_UpperSat;
  } else if (rtb_Backgain < helikopter_task3_P.BackmotorSaturation_LowerSat) {
    helikopter_task3_B.BackmotorSaturation =
      helikopter_task3_P.BackmotorSaturation_LowerSat;
  } else {
    helikopter_task3_B.BackmotorSaturation = rtb_Backgain;
  }

  /* End of Saturate: '<S6>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(helikopter_task3_M)) {
  }

  /* Saturate: '<S6>/Front motor: Saturation' */
  if (rtb_Frontgain > helikopter_task3_P.FrontmotorSaturation_UpperSat) {
    helikopter_task3_B.FrontmotorSaturation =
      helikopter_task3_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Frontgain < helikopter_task3_P.FrontmotorSaturation_LowerSat) {
    helikopter_task3_B.FrontmotorSaturation =
      helikopter_task3_P.FrontmotorSaturation_LowerSat;
  } else {
    helikopter_task3_B.FrontmotorSaturation = rtb_Frontgain;
  }

  /* End of Saturate: '<S6>/Front motor: Saturation' */
  if (rtmIsMajorTimeStep(helikopter_task3_M)) {
    /* S-Function (hil_write_analog_block): '<S6>/HIL Write Analog' */

    /* S-Function Block: helikopter_task3/Helicopter_interface/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      helikopter_task3_DW.HILWriteAnalog_Buffer[0] =
        helikopter_task3_B.FrontmotorSaturation;
      helikopter_task3_DW.HILWriteAnalog_Buffer[1] =
        helikopter_task3_B.BackmotorSaturation;
      result = hil_write_analog(helikopter_task3_DW.HILInitialize_Card,
        helikopter_task3_P.HILWriteAnalog_channels, 2,
        &helikopter_task3_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
      }
    }
  }
}

/* Model update function */
void helikopter_task3_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<S6>/Derivative' */
  if (helikopter_task3_DW.TimeStampA == (rtInf)) {
    helikopter_task3_DW.TimeStampA = helikopter_task3_M->Timing.t[0];
    lastU = &helikopter_task3_DW.LastUAtTimeA;
  } else if (helikopter_task3_DW.TimeStampB == (rtInf)) {
    helikopter_task3_DW.TimeStampB = helikopter_task3_M->Timing.t[0];
    lastU = &helikopter_task3_DW.LastUAtTimeB;
  } else if (helikopter_task3_DW.TimeStampA < helikopter_task3_DW.TimeStampB) {
    helikopter_task3_DW.TimeStampA = helikopter_task3_M->Timing.t[0];
    lastU = &helikopter_task3_DW.LastUAtTimeA;
  } else {
    helikopter_task3_DW.TimeStampB = helikopter_task3_M->Timing.t[0];
    lastU = &helikopter_task3_DW.LastUAtTimeB;
  }

  *lastU = helikopter_task3_B.PitchCounttorad;

  /* End of Update for Derivative: '<S6>/Derivative' */
  if (rtmIsMajorTimeStep(helikopter_task3_M)) {
    rt_ertODEUpdateContinuousStates(&helikopter_task3_M->solverInfo);
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
  if (!(++helikopter_task3_M->Timing.clockTick0)) {
    ++helikopter_task3_M->Timing.clockTickH0;
  }

  helikopter_task3_M->Timing.t[0] = rtsiGetSolverStopTime
    (&helikopter_task3_M->solverInfo);

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
    if (!(++helikopter_task3_M->Timing.clockTick1)) {
      ++helikopter_task3_M->Timing.clockTickH1;
    }

    helikopter_task3_M->Timing.t[1] = helikopter_task3_M->Timing.clockTick1 *
      helikopter_task3_M->Timing.stepSize1 +
      helikopter_task3_M->Timing.clockTickH1 *
      helikopter_task3_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void helikopter_task3_derivatives(void)
{
  XDot_helikopter_task3_T *_rtXdot;
  _rtXdot = ((XDot_helikopter_task3_T *) helikopter_task3_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S6>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += helikopter_task3_P.TravelTransferFcn_A *
    helikopter_task3_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += helikopter_task3_B.TravelCounttorad;

  /* Derivatives for TransferFcn: '<S6>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += helikopter_task3_P.PitchTransferFcn_A *
    helikopter_task3_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += helikopter_task3_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S6>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    helikopter_task3_P.ElevationTransferFcn_A *
    helikopter_task3_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += helikopter_task3_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( helikopter_task3_X.Integrator_CSTATE <=
            (helikopter_task3_P.Integrator_LowerSat) );
    usat = ( helikopter_task3_X.Integrator_CSTATE >=
            helikopter_task3_P.Integrator_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (helikopter_task3_B.K_ei > 0)) ||
        (usat && (helikopter_task3_B.K_ei < 0)) ) {
      ((XDot_helikopter_task3_T *) helikopter_task3_M->ModelData.derivs)
        ->Integrator_CSTATE = helikopter_task3_B.K_ei;
    } else {
      /* in saturation */
      ((XDot_helikopter_task3_T *) helikopter_task3_M->ModelData.derivs)
        ->Integrator_CSTATE = 0.0;
    }
  }
}

/* Model initialize function */
void helikopter_task3_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helikopter_task3/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &helikopter_task3_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (helikopter_task3_DW.HILInitialize_Card, "update_rate=normal;decimation=1",
       32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(helikopter_task3_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
      return;
    }

    if ((helikopter_task3_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (helikopter_task3_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &helikopter_task3_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = helikopter_task3_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &helikopter_task3_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = helikopter_task3_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges
        (helikopter_task3_DW.HILInitialize_Card,
         helikopter_task3_P.HILInitialize_analog_input_chan, 8U,
         &helikopter_task3_DW.HILInitialize_AIMinimums[0],
         &helikopter_task3_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task3_P.HILInitialize_set_analog_output && !is_switching) ||
        (helikopter_task3_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &helikopter_task3_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = helikopter_task3_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &helikopter_task3_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = helikopter_task3_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges
        (helikopter_task3_DW.HILInitialize_Card,
         helikopter_task3_P.HILInitialize_analog_output_cha, 8U,
         &helikopter_task3_DW.HILInitialize_AOMinimums[0],
         &helikopter_task3_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task3_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (helikopter_task3_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &helikopter_task3_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helikopter_task3_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(helikopter_task3_DW.HILInitialize_Card,
        helikopter_task3_P.HILInitialize_analog_output_cha, 8U,
        &helikopter_task3_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
        return;
      }
    }

    if (helikopter_task3_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &helikopter_task3_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helikopter_task3_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (helikopter_task3_DW.HILInitialize_Card,
         helikopter_task3_P.HILInitialize_analog_output_cha, 8U,
         &helikopter_task3_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task3_P.HILInitialize_set_encoder_param && !is_switching) ||
        (helikopter_task3_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &helikopter_task3_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = helikopter_task3_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (helikopter_task3_DW.HILInitialize_Card,
         helikopter_task3_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &helikopter_task3_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task3_P.HILInitialize_set_encoder_count && !is_switching) ||
        (helikopter_task3_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &helikopter_task3_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            helikopter_task3_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(helikopter_task3_DW.HILInitialize_Card,
        helikopter_task3_P.HILInitialize_encoder_channels, 8U,
        &helikopter_task3_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task3_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (helikopter_task3_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &helikopter_task3_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = helikopter_task3_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(helikopter_task3_DW.HILInitialize_Card,
        helikopter_task3_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &helikopter_task3_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          helikopter_task3_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues =
          &helikopter_task3_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            helikopter_task3_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = p_HILInitialize_pwm_channels[i1];
            helikopter_task3_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = helikopter_task3_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            helikopter_task3_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = p_HILInitialize_pwm_channels[i1];
            helikopter_task3_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              helikopter_task3_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(helikopter_task3_DW.HILInitialize_Card,
          &helikopter_task3_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &helikopter_task3_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(helikopter_task3_DW.HILInitialize_Card,
          &helikopter_task3_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &helikopter_task3_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &helikopter_task3_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            helikopter_task3_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &helikopter_task3_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = helikopter_task3_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &helikopter_task3_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = helikopter_task3_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(helikopter_task3_DW.HILInitialize_Card,
        helikopter_task3_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &helikopter_task3_DW.HILInitialize_POModeValues
        [0],
        (t_pwm_alignment *) &helikopter_task3_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &helikopter_task3_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &helikopter_task3_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] =
            helikopter_task3_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &helikopter_task3_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helikopter_task3_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(helikopter_task3_DW.HILInitialize_Card,
        helikopter_task3_P.HILInitialize_pwm_channels, 8U,
        &helikopter_task3_DW.HILInitialize_POSortedFreqs[0],
        &helikopter_task3_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task3_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (helikopter_task3_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &helikopter_task3_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helikopter_task3_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(helikopter_task3_DW.HILInitialize_Card,
        helikopter_task3_P.HILInitialize_pwm_channels, 8U,
        &helikopter_task3_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
        return;
      }
    }

    if (helikopter_task3_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &helikopter_task3_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helikopter_task3_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (helikopter_task3_DW.HILInitialize_Card,
         helikopter_task3_P.HILInitialize_pwm_channels, 8U,
         &helikopter_task3_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S6>/HIL Read Encoder Timebase' */

  /* S-Function Block: helikopter_task3/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (helikopter_task3_DW.HILInitialize_Card,
       helikopter_task3_P.HILReadEncoderTimebase_samples_,
       helikopter_task3_P.HILReadEncoderTimebase_channels, 3,
       &helikopter_task3_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
    }
  }

  /* Start for ToFile: '<Root>/To File2' */
  {
    char fileName[509] = "measured_time.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(helikopter_task3_M,
                        "Error creating .mat file measured_time.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"measured_time")) {
      rtmSetErrorStatus(helikopter_task3_M,
                        "Error writing mat file header to file measured_time.mat");
      return;
    }

    helikopter_task3_DW.ToFile2_IWORK.Count = 0;
    helikopter_task3_DW.ToFile2_IWORK.Decimation = -1;
    helikopter_task3_DW.ToFile2_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File' */
  {
    char fileName[509] = "measured_travel.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(helikopter_task3_M,
                        "Error creating .mat file measured_travel.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"measured_travel")) {
      rtmSetErrorStatus(helikopter_task3_M,
                        "Error writing mat file header to file measured_travel.mat");
      return;
    }

    helikopter_task3_DW.ToFile_IWORK.Count = 0;
    helikopter_task3_DW.ToFile_IWORK.Decimation = -1;
    helikopter_task3_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File1' */
  {
    char fileName[509] = "measured_pitch.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(helikopter_task3_M,
                        "Error creating .mat file measured_pitch.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"measured_pitch")) {
      rtmSetErrorStatus(helikopter_task3_M,
                        "Error writing mat file header to file measured_pitch.mat");
      return;
    }

    helikopter_task3_DW.ToFile1_IWORK.Count = 0;
    helikopter_task3_DW.ToFile1_IWORK.Decimation = -1;
    helikopter_task3_DW.ToFile1_PWORK.FilePtr = fp;
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
      19.75, 20.0, 20.25, 20.5, 20.75, 21.0, 21.25, 21.5, 21.75, 22.0, 22.25,
      22.5, 22.75, 23.0, 23.25, 23.5, 23.75, 24.0, 24.25, 24.5, 24.75, 25.0,
      25.25, 25.5, 25.75, 26.0, 26.25, 26.5, 26.75, 27.0, 27.25, 27.5, 27.75,
      28.0, 28.25, 28.5, 28.75, 29.0, 29.25, 29.5, 29.75, 30.0, 30.25, 30.5,
      30.75, 31.0, 31.25, 31.5, 31.75, 32.0, 32.25, 32.5, 32.75, 33.0, 33.25,
      33.5, 33.75, 34.0, 34.25, 34.5, 34.75, 35.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.52359877559807633,
      0.5235987755980368, 0.52359877559798584, 0.52359877559791856,
      0.52359877559782708, 0.52359877559769752, 0.52359877559750412,
      0.52359877559719181, 0.52359877559662016, 0.52359877559529355,
      0.523598775589332, 0.38860546389102035, 0.1095169909174698,
      -0.11003833738107634, -0.27691123544853052, -0.39790682520562531,
      -0.479636749184537, -0.52359193014168715, -0.52359877534492194,
      -0.52359877536483534, -0.52359872266631369, -0.50343489229945881,
      -0.46497043897095752, -0.42077345731395, -0.37347862441942631,
      -0.32522986453662961, -0.27772344600389448, -0.23225530209368853,
      -0.1897701876335757, -0.15091074046330755, -0.11606494626431166,
      -0.085410890463798392, -0.058958015868243133, -0.036584388865839951,
      -0.018069712627069291, -0.0031240163038023139, 0.008587900936049709,
      0.017426078505365334, 0.023758780878180386, 0.027949331910130722,
      0.030346034230277388, 0.031274796724164847, 0.031034093720423334,
      0.029891891559064614, 0.028084198822607834, 0.025814923109906313,
      0.02325674766940513, 0.020552773689788355, 0.017818707115316568,
      0.015145401361167748, 0.012601598374981723, 0.010236739488296568,
      0.008083743995053053, 0.0061616771262931764, 0.0044782499454615885,
      0.003032111666416116, 0.0018149100842331743, 0.00081310836131904217,
      9.5565291511106016E-6, -0.00061517601971299062, -0.0010816948164583142,
      -0.0014108848900305216, -0.00162320634279955, -0.0017381600571613437,
      -0.0017739020734852311, -0.0017469853816909167, -0.0016722086788734064,
      -0.0015625529032339785, -0.0014291879215759511, -0.0012815335066174217,
      -0.0011273605944207169, -0.00097292068311841345, -0.0008230930605746448,
      -0.00068154128449249155, -0.00055087195076496186, -0.0004327902528423276,
      -0.00032824814428729105, -0.00023758206401880457, -0.00016063817075177947,
      -9.6883866454730772E-5, -4.5505078632640539E-5, -5.4893310576959811E-6,
      2.4304922511354287E-5, 4.5091880073432816E-5, 5.8113799311665329E-5,
      6.4606933336015026E-5, 6.5776522041032149E-5, 6.2779200911743178E-5,
      5.6710998292133607E-5, 4.8598837819682634E-5, 3.9393103041911077E-5,
      2.9958322914449642E-5, 2.1058409866217359E-5, 1.3332266106284715E-5,
      7.2554391572394559E-6, 3.0850995602113246E-6, 7.9190498544134013E-7,
      -4.0242296691128868E-17, -1.5199404269500641E-17, -1.7771458472818954E-26,
      -1.7771458472818954E-26, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task3_DW.FromWorkspace1_PWORK.TimePtr = (void *) pTimeValues0;
    helikopter_task3_DW.FromWorkspace1_PWORK.DataPtr = (void *) pDataValues0;
    helikopter_task3_DW.FromWorkspace1_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace2' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75,
      2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0,
      5.25, 5.5, 5.75, 6.0, 6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.25,
      8.5, 8.75, 9.0, 9.25, 9.5, 9.75, 10.0, 10.25, 10.5, 10.75, 11.0, 11.25,
      11.5, 11.75, 12.0, 12.25, 12.5, 12.75, 13.0, 13.25, 13.5, 13.75, 14.0,
      14.25, 14.5, 14.75, 15.0, 15.25, 15.5, 15.75, 16.0, 16.25, 16.5, 16.75,
      17.0, 17.25, 17.5, 17.75, 18.0, 18.25, 18.5, 18.75, 19.0, 19.25, 19.5,
      19.75, 20.0, 20.25, 20.5, 20.75, 21.0, 21.25, 21.5, 21.75, 22.0, 22.25,
      22.5, 22.75, 23.0, 23.25, 23.5, 23.75, 24.0, 24.25, 24.5, 24.75, 25.0,
      25.25, 25.5, 25.75, 26.0, 26.25, 26.5, 26.75, 27.0, 27.25, 27.5, 27.75,
      28.0, 28.25, 28.5, 28.75, 29.0, 29.25, 29.5, 29.75, 30.0, 30.25, 30.5,
      30.75, 31.0, 31.25, 31.5, 31.75, 32.0, 32.25, 32.5, 32.75, 33.0, 33.25,
      33.5, 33.75, 34.0, 34.25, 34.5, 34.75, 35.0 } ;

    static real_T pDataValues0[] = { 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1378421413625275, 3.1262155534580049,
      3.1033093000299816, 3.0666274151912147, 3.0144539223942242,
      2.9456562771176751, 2.8595077632937125, 2.7555515879654031,
      2.6335051104906491, 2.4931956060326255, 2.3345185760651015,
      2.1583782719117446, 1.9678000778115241, 1.767411044399066,
      1.562581050985725, 1.3586839674439228, 1.1605920895595441,
      0.97235419585578942, 0.79695012226480244, 0.6364329328088163,
      0.49215959716533658, 0.36485729758962671, 0.25463993225132259,
      0.16109623570317386, 0.083400591199501481, 0.020423624628454505,
      -0.029167512602323711, -0.066823004349801665, -0.094039184938717241,
      -0.11230168981468099, -0.12304167554131822, -0.12760358310742217,
      -0.12722285337732953, -0.12301203909037241, -0.11595384711187075,
      -0.10689976307628538, -0.0965730442408032, -0.085575006614299259,
      -0.074393673321265272, -0.063413988416493747, -0.052928930825710194,
      -0.043150984470613316, -0.034223531396285478, -0.026231833928208017,
      -0.019213359141782769, -0.013167274256390847, -0.00806300533842605,
      -0.0038478045446914866, -0.00045331387844516465, 0.0021988529915415978,
      0.0041924638710402716, 0.0056128908488706063, 0.0065441252621094266,
      0.0070665001949369545, 0.0072550329664246424, 0.0071783004868153488,
      0.006897763373307989, 0.0064674596458465074, 0.0059339950918422821,
      0.0053367645048762007, 0.0047083455583468749, 0.004075014740209452,
      0.00345734228911474, 0.0028708302377633849, 0.00232656434323583,
      0.0018318567704917173, 0.0013908618376324477, 0.0010051519057520753,
      0.00067424460403684122, 0.00039607604406255133, 0.00016741753276115187,
      -1.5764411467935187E-5, -0.00015800314660920808, -0.00026407916665800821,
      -0.00033881565221715687, -0.00038691781589945658, -0.000412851209418502,
      -0.00042075404950891771, -0.0004143786905011939, -0.00039705758053658704,
      -0.00037168934911078821, -0.00034074105393427689, -0.00030626303783622279,
      -0.00026991328892395224, -0.00023298864077549882, -0.00019646057892327547,
      -0.00016101382300183934, -0.00012708622057210374, -9.49088100252896E-5,
      -6.4545177698857391E-5, -3.5929439226104111E-5, -8.9023060714567354E-6,
      1.6755258771874447E-5, 4.129135321636422E-5, 6.4956154283157979E-5,
      8.7979679014015959E-5, 0.00011055569364571112, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
    } ;

    helikopter_task3_DW.FromWorkspace2_PWORK.TimePtr = (void *) pTimeValues0;
    helikopter_task3_DW.FromWorkspace2_PWORK.DataPtr = (void *) pDataValues0;
    helikopter_task3_DW.FromWorkspace2_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace3' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75,
      2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0,
      5.25, 5.5, 5.75, 6.0, 6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.25,
      8.5, 8.75, 9.0, 9.25, 9.5, 9.75, 10.0, 10.25, 10.5, 10.75, 11.0, 11.25,
      11.5, 11.75, 12.0, 12.25, 12.5, 12.75, 13.0, 13.25, 13.5, 13.75, 14.0,
      14.25, 14.5, 14.75, 15.0, 15.25, 15.5, 15.75, 16.0, 16.25, 16.5, 16.75,
      17.0, 17.25, 17.5, 17.75, 18.0, 18.25, 18.5, 18.75, 19.0, 19.25, 19.5,
      19.75, 20.0, 20.25, 20.5, 20.75, 21.0, 21.25, 21.5, 21.75, 22.0, 22.25,
      22.5, 22.75, 23.0, 23.25, 23.5, 23.75, 24.0, 24.25, 24.5, 24.75, 25.0,
      25.25, 25.5, 25.75, 26.0, 26.25, 26.5, 26.75, 27.0, 27.25, 27.5, 27.75,
      28.0, 28.25, 28.5, 28.75, 29.0, 29.25, 29.5, 29.75, 30.0, 30.25, 30.5,
      30.75, 31.0, 31.25, 31.5, 31.75, 32.0, 32.25, 32.5, 32.75, 33.0, 33.25,
      33.5, 33.75, 34.0, 34.25, 34.5, 34.75, 35.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      -0.01500204890906205, -0.046506351618091225, -0.091625013712091488,
      -0.14672753935506802, -0.208693971187962, -0.27519058110619621,
      -0.344594055295849, -0.415824701313238, -0.48818590989901617,
      -0.56123801783209437, -0.634708119870094, -0.70456121661342741,
      -0.76231277640088291, -0.80155613364983225, -0.8193199736533644,
      -0.81558833416720811, -0.79236751153751461, -0.75295157481501906,
      -0.70161629436394757, -0.64206875782394457, -0.57709334257391876,
      -0.50920919830283962, -0.44086946135321636, -0.37417478619259487,
      -0.3107825780146895, -0.25190786628418793, -0.19836454892311287,
      -0.15062196698991184, -0.10886472235566227, -0.073050019503855,
      -0.042959942906548941, -0.018247630264415764, 0.0015229189203705765,
      0.01684325714782843, 0.028232767914006637, 0.036216336142341536,
      0.041306875341928707, 0.043992150506015737, 0.04472533317213595,
      0.043918739619086107, 0.041940230363134212, 0.03911178542038752,
      0.035709812297311357, 0.031966789872309838, 0.028073899145700992,
      0.024184339541567689, 0.020417075671859193, 0.016860803174938249,
      0.013577962664985288, 0.01060866747994705, 0.0079744435179946952,
      0.0056817079113213381, 0.0037249376529552803, 0.0020894997313101122,
      0.00075413108595075422, -0.00030692991843717316, -0.0011221484540294372,
      -0.0017212149098459254, -0.0021338582160169012, -0.002388922347864328,
      -0.0025136757861173036, -0.0025333232725496934, -0.0024706898043788468,
      -0.0023460482054054191, -0.00217706357811022, -0.0019788302909764508,
      -0.0017639797314370782, -0.00154283972752149, -0.0013236292068609359,
      -0.0011126742398971596, -0.00091463404520559784, -0.00073272777691634828,
      -0.00056895494056509151, -0.00042430408019520071, -0.00029894594223659469,
      -0.00019240865472919889, -0.00010373357407618156, -3.1611360361662839E-5,
      2.5501436030895172E-5, 6.9284439858427428E-5, 0.00010147292570319543,
      0.00012379318070604523, 0.00013791206439221654, 0.00014539899564908218,
      0.00014769859259381363, 0.00014611224740889339, 0.00014178702368574463,
      0.00013571040971894246, 0.00012870964218725657, 0.00012145452930572882,
      0.00011446295389101311, 0.00010810853261858949, 0.00010263025937332472,
      9.81443777779591E-5, 9.4659204267174982E-5, 9.2094098923431962E-5,
      9.0304058526780612E-5, 8.9110958456947549E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task3_DW.FromWorkspace3_PWORK.TimePtr = (void *) pTimeValues0;
    helikopter_task3_DW.FromWorkspace3_PWORK.DataPtr = (void *) pDataValues0;
    helikopter_task3_DW.FromWorkspace3_IWORK.PrevIndex = 0;
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
      19.75, 20.0, 20.25, 20.5, 20.75, 21.0, 21.25, 21.5, 21.75, 22.0, 22.25,
      22.5, 22.75, 23.0, 23.25, 23.5, 23.75, 24.0, 24.25, 24.5, 24.75, 25.0,
      25.25, 25.5, 25.75, 26.0, 26.25, 26.5, 26.75, 27.0, 27.25, 27.5, 27.75,
      28.0, 28.25, 28.5, 28.75, 29.0, 29.25, 29.5, 29.75, 30.0, 30.25, 30.5,
      30.75, 31.0, 31.25, 31.5, 31.75, 32.0, 32.25, 32.5, 32.75, 33.0, 33.25,
      33.5, 33.75, 34.0, 34.25, 34.5, 34.75, 35.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.10602875205861047, 0.22266037932307398, 0.31888147181624382,
      0.38944360631121688, 0.43795507377648479, 0.46997264230352392,
      0.49051724877498426, 0.503431001414098, 0.51142138585939068,
      0.51630439857561206, 0.5192586212675474, 0.49369500926311111,
      0.40816596791677678, 0.27735706108669539, 0.12554803672221249,
      -0.026373802688430734, -0.16411590577561186, -0.27857678689361443,
      -0.36281815609319995, -0.42085924567858074, -0.45922141936817434,
      -0.47977920517786155, -0.48299916022839384, -0.471372491791005,
      -0.4480319164459502, -0.41610397689243367, -0.37842371767256572,
      -0.337426335103833, -0.29512425701406431, -0.25312464129038104,
      -0.21266516929118778, -0.17465718754888548, -0.13973069080650896,
      -0.10827829939895457, -0.08049671217686262, -0.056424811127885083,
      -0.035977986867622581, -0.018978499290863121, -0.0051818550646620751,
      0.0057006951761592838, 0.013983347782466661, 0.019990368606568526,
      0.024043846741414941, 0.02645425295278004, 0.02751346487035811,
      0.027489921768933986, 0.026625582225598597, 0.025134375785238066,
      0.023201862931369905, 0.02098584432510885, 0.018617688891814133,
      0.016204179619030177, 0.013829704850157661, 0.011558650618491166,
      0.0094378755771235626, 0.0074991739351916034, 0.0057616532586881042,
      0.00423397291232856, 0.0029164052899613648, 0.0018026958689862311,
      0.00088170965533873277, 0.00013886093027309045, -0.00044266943185647606,
      -0.0008809192180249055, -0.0011943188065715715, -0.0014010371635686052,
      -0.0015184816984094302, -0.0015629330891757508, -0.0015492962384436035,
      -0.001490949137902327, -0.001399672459933565, -0.0012856440300429463,
      -0.0011574838586837031, -0.0010223370355738118, -0.00088598344190927753,
      -0.00075296485903969849, -0.00062672160298428837, -0.00050973226138701635,
      -0.00040365143220020611, -0.00030944154930773724, -0.00022749592442105834,
      -0.00015775103773675708, -9.978687756451339E-5, -5.2914770690725568E-5,
      -1.6252672935920593E-5, 1.1211681904974879E-5, 3.0569029371897362E-5,
      4.2947186717460186E-5, 4.9478751158364313E-5, 5.1276366950654766E-5,
      4.9413784786302027E-5, 4.4910622652535219E-5, 3.871834301784139E-5,
      3.1704497853756281E-5, 2.4631875305575876E-5, 1.8129184896314983E-5,
      1.2651321865561652E-5, 8.4323756209743844E-6, 5.4485883187363461E-6, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task3_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    helikopter_task3_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    helikopter_task3_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace4' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75,
      2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0,
      5.25, 5.5, 5.75, 6.0, 6.25, 6.5, 6.75, 7.0, 7.25, 7.5, 7.75, 8.0, 8.25,
      8.5, 8.75, 9.0, 9.25, 9.5, 9.75, 10.0, 10.25, 10.5, 10.75, 11.0, 11.25,
      11.5, 11.75, 12.0, 12.25, 12.5, 12.75, 13.0, 13.25, 13.5, 13.75, 14.0,
      14.25, 14.5, 14.75, 15.0, 15.25, 15.5, 15.75, 16.0, 16.25, 16.5, 16.75,
      17.0, 17.25, 17.5, 17.75, 18.0, 18.25, 18.5, 18.75, 19.0, 19.25, 19.5,
      19.75, 20.0, 20.25, 20.5, 20.75, 21.0, 21.25, 21.5, 21.75, 22.0, 22.25,
      22.5, 22.75, 23.0, 23.25, 23.5, 23.75, 24.0, 24.25, 24.5, 24.75, 25.0,
      25.25, 25.5, 25.75, 26.0, 26.25, 26.5, 26.75, 27.0, 27.25, 27.5, 27.75,
      28.0, 28.25, 28.5, 28.75, 29.0, 29.25, 29.5, 29.75, 30.0, 30.25, 30.5,
      30.75, 31.0, 31.25, 31.5, 31.75, 32.0, 32.25, 32.5, 32.75, 33.0, 33.25,
      33.5, 33.75, 34.0, 34.25, 34.5, 34.75, 35.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.42411500823444187, 0.46652650905785403, 0.38488436997267944,
      0.28224853797989208, 0.19404586986107164, 0.1280702741081565,
      0.082178425885841344, 0.051655010556455133, 0.031961537781170585,
      0.019532050864885485, 0.011816890767741074, -0.10225444801774518,
      -0.34211616538533735, -0.52323562732032558, -0.6072360974579315,
      -0.607687357642573, -0.5509684123487244, -0.45784352447201021,
      -0.33696547679834216, -0.23216435834152313, -0.15344869475837444,
      -0.0822311432387487, -0.01287982020212922, 0.0465066737495554,
      0.093362301380219281, 0.12771175821406594, 0.15072103687947172,
      0.16398953027493077, 0.16920831235907502, 0.16799846289473314,
      0.16183788799677296, 0.15203192696920925, 0.13970598696950609,
      0.12580956563021747, 0.11112634888836788, 0.0962876041959101,
      0.08178729704105, 0.067997950307037841, 0.055186576904804184,
      0.043530200963285436, 0.033130610425229509, 0.02402808329640746,
      0.016213912539385651, 0.0096416248454604, 0.0042368476703122842,
      -9.4172405696494539E-5, -0.00345735817334156, -0.0059648257614421177,
      -0.0077300514154726545, -0.0088640744250442251, -0.009472621733178848,
      -0.0096540370911358322, -0.00949789907549006, -0.0090842169266659757,
      -0.0084831001654704172, -0.0077548065677278339, -0.0069500827060139979,
      -0.0061107213854381748, -0.005270270489468782, -0.004454837683900534,
      -0.0036839448545899936, -0.0029713949002625694, -0.0023261214485182659,
      -0.0017529991446737182, -0.0012535983541866634, -0.00082687342798813538,
      -0.00046977813936329989, -0.00017780556306528232, 5.4547402928589749E-5,
      0.00023338840216510537, 0.00036510671187504868, 0.000456113719562475,
      0.000512640685436973, 0.00054058729243956576, 0.00054541437465813712,
      0.00053207433147831593, 0.00050497302422164057, 0.0004679573663890882,
      0.00042432331674724095, 0.00037683953156987548, 0.00032778249954671572,
      0.00027897954673720504, 0.00023185664068897476, 0.00018748842749515132,
      0.00014664839101921992, 0.00010985741936358188, 7.742938986768991E-5,
      4.9512629382251316E-5, 2.6126257763616489E-5, 7.19046316916183E-6,
      -7.4503286574109394E-6, -1.8012648535067239E-5, -2.4769118538775309E-5,
      -2.8055380656340441E-5, -2.8290490192721611E-5, -2.6010761637043574E-5,
      -2.1911452123013335E-5, -1.687578497834907E-5, -1.1935149208952157E-5,
      -8.0237391738844672E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task3_DW.FromWorkspace4_PWORK.TimePtr = (void *) pTimeValues0;
    helikopter_task3_DW.FromWorkspace4_PWORK.DataPtr = (void *) pDataValues0;
    helikopter_task3_DW.FromWorkspace4_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for TransferFcn: '<S6>/Travel: Transfer Fcn' */
  helikopter_task3_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S6>/Pitch: Transfer Fcn' */
  helikopter_task3_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S6>/Elevation: Transfer Fcn' */
  helikopter_task3_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  helikopter_task3_X.Integrator_CSTATE = helikopter_task3_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<S6>/Derivative' */
  helikopter_task3_DW.TimeStampA = (rtInf);
  helikopter_task3_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void helikopter_task3_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helikopter_task3/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(helikopter_task3_DW.HILInitialize_Card);
    hil_monitor_stop_all(helikopter_task3_DW.HILInitialize_Card);
    is_switching = false;
    if ((helikopter_task3_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (helikopter_task3_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &helikopter_task3_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helikopter_task3_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((helikopter_task3_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (helikopter_task3_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &helikopter_task3_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helikopter_task3_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(helikopter_task3_DW.HILInitialize_Card
                         , helikopter_task3_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , helikopter_task3_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &helikopter_task3_DW.HILInitialize_AOVoltages[0]
                         , &helikopter_task3_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(helikopter_task3_DW.HILInitialize_Card,
            helikopter_task3_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs,
            &helikopter_task3_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(helikopter_task3_DW.HILInitialize_Card,
            helikopter_task3_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &helikopter_task3_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helikopter_task3_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(helikopter_task3_DW.HILInitialize_Card);
    hil_monitor_delete_all(helikopter_task3_DW.HILInitialize_Card);
    hil_close(helikopter_task3_DW.HILInitialize_Card);
    helikopter_task3_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<Root>/To File2' */
  {
    FILE *fp = (FILE *) helikopter_task3_DW.ToFile2_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "measured_time.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task3_M,
                          "Error closing MAT-file measured_time.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(helikopter_task3_M,
                          "Error reopening MAT-file measured_time.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, helikopter_task3_DW.ToFile2_IWORK.Count,
           "measured_time")) {
        rtmSetErrorStatus(helikopter_task3_M,
                          "Error writing header for measured_time to MAT-file measured_time.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task3_M,
                          "Error closing MAT-file measured_time.mat");
        return;
      }

      helikopter_task3_DW.ToFile2_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) helikopter_task3_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "measured_travel.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task3_M,
                          "Error closing MAT-file measured_travel.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(helikopter_task3_M,
                          "Error reopening MAT-file measured_travel.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, helikopter_task3_DW.ToFile_IWORK.Count,
           "measured_travel")) {
        rtmSetErrorStatus(helikopter_task3_M,
                          "Error writing header for measured_travel to MAT-file measured_travel.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task3_M,
                          "Error closing MAT-file measured_travel.mat");
        return;
      }

      helikopter_task3_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (FILE *) helikopter_task3_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "measured_pitch.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task3_M,
                          "Error closing MAT-file measured_pitch.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(helikopter_task3_M,
                          "Error reopening MAT-file measured_pitch.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, helikopter_task3_DW.ToFile1_IWORK.Count,
           "measured_pitch")) {
        rtmSetErrorStatus(helikopter_task3_M,
                          "Error writing header for measured_pitch to MAT-file measured_pitch.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task3_M,
                          "Error closing MAT-file measured_pitch.mat");
        return;
      }

      helikopter_task3_DW.ToFile1_PWORK.FilePtr = (NULL);
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
  helikopter_task3_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  helikopter_task3_update();
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
  helikopter_task3_initialize();
}

void MdlTerminate(void)
{
  helikopter_task3_terminate();
}

/* Registration function */
RT_MODEL_helikopter_task3_T *helikopter_task3(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  helikopter_task3_P.Integrator_UpperSat = rtInf;
  helikopter_task3_P.Integrator_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)helikopter_task3_M, 0,
                sizeof(RT_MODEL_helikopter_task3_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&helikopter_task3_M->solverInfo,
                          &helikopter_task3_M->Timing.simTimeStep);
    rtsiSetTPtr(&helikopter_task3_M->solverInfo, &rtmGetTPtr(helikopter_task3_M));
    rtsiSetStepSizePtr(&helikopter_task3_M->solverInfo,
                       &helikopter_task3_M->Timing.stepSize0);
    rtsiSetdXPtr(&helikopter_task3_M->solverInfo,
                 &helikopter_task3_M->ModelData.derivs);
    rtsiSetContStatesPtr(&helikopter_task3_M->solverInfo, (real_T **)
                         &helikopter_task3_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&helikopter_task3_M->solverInfo,
      &helikopter_task3_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&helikopter_task3_M->solverInfo, (&rtmGetErrorStatus
      (helikopter_task3_M)));
    rtsiSetRTModelPtr(&helikopter_task3_M->solverInfo, helikopter_task3_M);
  }

  rtsiSetSimTimeStep(&helikopter_task3_M->solverInfo, MAJOR_TIME_STEP);
  helikopter_task3_M->ModelData.intgData.f[0] =
    helikopter_task3_M->ModelData.odeF[0];
  helikopter_task3_M->ModelData.contStates = ((real_T *) &helikopter_task3_X);
  rtsiSetSolverData(&helikopter_task3_M->solverInfo, (void *)
                    &helikopter_task3_M->ModelData.intgData);
  rtsiSetSolverName(&helikopter_task3_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = helikopter_task3_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    helikopter_task3_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    helikopter_task3_M->Timing.sampleTimes =
      (&helikopter_task3_M->Timing.sampleTimesArray[0]);
    helikopter_task3_M->Timing.offsetTimes =
      (&helikopter_task3_M->Timing.offsetTimesArray[0]);

    /* task periods */
    helikopter_task3_M->Timing.sampleTimes[0] = (0.0);
    helikopter_task3_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    helikopter_task3_M->Timing.offsetTimes[0] = (0.0);
    helikopter_task3_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(helikopter_task3_M, &helikopter_task3_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = helikopter_task3_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    helikopter_task3_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(helikopter_task3_M, 45.0);
  helikopter_task3_M->Timing.stepSize0 = 0.002;
  helikopter_task3_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  helikopter_task3_M->Sizes.checksums[0] = (4113106223U);
  helikopter_task3_M->Sizes.checksums[1] = (3010681683U);
  helikopter_task3_M->Sizes.checksums[2] = (94432185U);
  helikopter_task3_M->Sizes.checksums[3] = (2909986540U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    helikopter_task3_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(helikopter_task3_M->extModeInfo,
      &helikopter_task3_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(helikopter_task3_M->extModeInfo,
                        helikopter_task3_M->Sizes.checksums);
    rteiSetTPtr(helikopter_task3_M->extModeInfo, rtmGetTPtr(helikopter_task3_M));
  }

  helikopter_task3_M->solverInfoPtr = (&helikopter_task3_M->solverInfo);
  helikopter_task3_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&helikopter_task3_M->solverInfo, 0.002);
  rtsiSetSolverMode(&helikopter_task3_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  helikopter_task3_M->ModelData.blockIO = ((void *) &helikopter_task3_B);

  {
    helikopter_task3_B.Clock = 0.0;
    helikopter_task3_B.TravelCounttorad = 0.0;
    helikopter_task3_B.Gain = 0.0;
    helikopter_task3_B.Sum5 = 0.0;
    helikopter_task3_B.PitchCounttorad = 0.0;
    helikopter_task3_B.Gain_i = 0.0;
    helikopter_task3_B.Gain_d = 0.0;
    helikopter_task3_B.Gain_b = 0.0;
    helikopter_task3_B.ElevationCounttorad = 0.0;
    helikopter_task3_B.Gain_e = 0.0;
    helikopter_task3_B.Sum = 0.0;
    helikopter_task3_B.Gain_dg = 0.0;
    helikopter_task3_B.Sum1 = 0.0;
    helikopter_task3_B.Sum2 = 0.0;
    helikopter_task3_B.K_ei = 0.0;
    helikopter_task3_B.Gain_l = 0.0;
    helikopter_task3_B.BackmotorSaturation = 0.0;
    helikopter_task3_B.FrontmotorSaturation = 0.0;
  }

  /* parameters */
  helikopter_task3_M->ModelData.defaultParam = ((real_T *)&helikopter_task3_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &helikopter_task3_X;
    helikopter_task3_M->ModelData.contStates = (x);
    (void) memset((void *)&helikopter_task3_X, 0,
                  sizeof(X_helikopter_task3_T));
  }

  /* states (dwork) */
  helikopter_task3_M->ModelData.dwork = ((void *) &helikopter_task3_DW);
  (void) memset((void *)&helikopter_task3_DW, 0,
                sizeof(DW_helikopter_task3_T));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task3_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task3_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task3_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task3_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task3_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task3_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task3_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task3_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  helikopter_task3_DW.TimeStampA = 0.0;
  helikopter_task3_DW.LastUAtTimeA = 0.0;
  helikopter_task3_DW.TimeStampB = 0.0;
  helikopter_task3_DW.LastUAtTimeB = 0.0;
  helikopter_task3_DW.HILWriteAnalog_Buffer[0] = 0.0;
  helikopter_task3_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    helikopter_task3_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  helikopter_task3_M->Sizes.numContStates = (4);/* Number of continuous states */
  helikopter_task3_M->Sizes.numY = (0);/* Number of model outputs */
  helikopter_task3_M->Sizes.numU = (0);/* Number of model inputs */
  helikopter_task3_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  helikopter_task3_M->Sizes.numSampTimes = (2);/* Number of sample times */
  helikopter_task3_M->Sizes.numBlocks = (68);/* Number of blocks */
  helikopter_task3_M->Sizes.numBlockIO = (18);/* Number of block outputs */
  helikopter_task3_M->Sizes.numBlockPrms = (148);/* Sum of parameter "widths" */
  return helikopter_task3_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
