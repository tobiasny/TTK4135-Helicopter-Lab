/*
 * helikopter_task4.c
 *
 * Code generation for model "helikopter_task4".
 *
 * Model version              : 1.199
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Feb 20 12:59:51 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "helikopter_task4.h"
#include "helikopter_task4_private.h"
#include "helikopter_task4_dt.h"

/* Block signals (auto storage) */
B_helikopter_task4_T helikopter_task4_B;

/* Continuous states */
X_helikopter_task4_T helikopter_task4_X;

/* Block states (auto storage) */
DW_helikopter_task4_T helikopter_task4_DW;

/* Real-time model */
RT_MODEL_helikopter_task4_T helikopter_task4_M_;
RT_MODEL_helikopter_task4_T *const helikopter_task4_M = &helikopter_task4_M_;

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
  helikopter_task4_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void helikopter_task4_output(void)
{
  /* local block i/o variables */
  real_T rtb_FromWorkspace2;
  real_T rtb_FromWorkspace3;
  real_T rtb_FromWorkspace4;
  real_T rtb_Frontgain;
  real_T rtb_Derivative;
  real_T rtb_Backgain;
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_Gain1_f;
  real_T *lastU;
  real_T rtb_Sum3_e[6];
  real_T tmp[2];
  int32_T i;
  int32_T i_0;
  real_T rtb_Gain1_idx_2;
  real_T rtb_Gain1_idx_3;
  real_T rtb_Gain1_idx_4;
  real_T rtb_Gain1_idx_5;
  if (rtmIsMajorTimeStep(helikopter_task4_M)) {
    /* set solver stop time */
    if (!(helikopter_task4_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&helikopter_task4_M->solverInfo,
                            ((helikopter_task4_M->Timing.clockTickH0 + 1) *
        helikopter_task4_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&helikopter_task4_M->solverInfo,
                            ((helikopter_task4_M->Timing.clockTick0 + 1) *
        helikopter_task4_M->Timing.stepSize0 +
        helikopter_task4_M->Timing.clockTickH0 *
        helikopter_task4_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(helikopter_task4_M)) {
    helikopter_task4_M->Timing.t[0] = rtsiGetT(&helikopter_task4_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(helikopter_task4_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S9>/HIL Read Encoder Timebase' */

    /* S-Function Block: helikopter_task4/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (helikopter_task4_DW.HILReadEncoderTimebase_Task, 1,
         &helikopter_task4_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          helikopter_task4_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          helikopter_task4_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_Gain1_f = helikopter_task4_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }
  }

  /* Clock: '<Root>/Clock' */
  helikopter_task4_B.Clock = helikopter_task4_M->Timing.t[0];
  if (rtmIsMajorTimeStep(helikopter_task4_M)) {
    /* ToFile: '<Root>/To File2' */
    {
      if (!(++helikopter_task4_DW.ToFile2_IWORK.Decimation % 1) &&
          (helikopter_task4_DW.ToFile2_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) helikopter_task4_DW.ToFile2_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          helikopter_task4_DW.ToFile2_IWORK.Decimation = 0;
          u[0] = helikopter_task4_M->Timing.t[1];
          u[1] = helikopter_task4_B.Clock;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(helikopter_task4_M,
                              "Error writing to MAT-file measured_time.mat");
            return;
          }

          if (((++helikopter_task4_DW.ToFile2_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file measured_time.mat.\n");
          }
        }
      }
    }
  }

  /* FromWorkspace: '<Root>/From Workspace6' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task4_DW.FromWorkspace6_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task4_DW.FromWorkspace6_PWORK.TimePtr;
    int_T currTimeIndex = helikopter_task4_DW.FromWorkspace6_IWORK.PrevIndex;
    real_T t = helikopter_task4_M->Timing.t[0];

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

    helikopter_task4_DW.FromWorkspace6_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          helikopter_task4_B.FromWorkspace6 = pDataValues[currTimeIndex];
        } else {
          helikopter_task4_B.FromWorkspace6 = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        helikopter_task4_B.FromWorkspace6 = (real_T) rtInterpolate(d1, d2, f1,
          f2);
        pDataValues += 81;
      }
    }
  }

  if (rtmIsMajorTimeStep(helikopter_task4_M)) {
    /* Gain: '<S9>/Elevation: Count to rad' */
    helikopter_task4_B.ElevationCounttorad =
      helikopter_task4_P.ElevationCounttorad_Gain * rtb_Gain1_f;

    /* Gain: '<S11>/Gain' */
    helikopter_task4_B.Gain = helikopter_task4_P.Gain_Gain *
      helikopter_task4_B.ElevationCounttorad;

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/elavation_offset [deg]'
     */
    helikopter_task4_B.Sum = helikopter_task4_B.Gain +
      helikopter_task4_P.elavation_offsetdeg_Value;
  }

  /* FromWorkspace: '<Root>/From Workspace2' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task4_DW.FromWorkspace2_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task4_DW.FromWorkspace2_PWORK.TimePtr;
    int_T currTimeIndex = helikopter_task4_DW.FromWorkspace2_IWORK.PrevIndex;
    real_T t = helikopter_task4_M->Timing.t[0];

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

    helikopter_task4_DW.FromWorkspace2_IWORK.PrevIndex = currTimeIndex;

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
        pDataValues += 81;
      }
    }
  }

  /* FromWorkspace: '<Root>/From Workspace3' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task4_DW.FromWorkspace3_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task4_DW.FromWorkspace3_PWORK.TimePtr;
    int_T currTimeIndex = helikopter_task4_DW.FromWorkspace3_IWORK.PrevIndex;
    real_T t = helikopter_task4_M->Timing.t[0];

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

    helikopter_task4_DW.FromWorkspace3_IWORK.PrevIndex = currTimeIndex;

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
        pDataValues += 81;
      }
    }
  }

  /* FromWorkspace: '<Root>/From Workspace4' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task4_DW.FromWorkspace4_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task4_DW.FromWorkspace4_PWORK.TimePtr;
    int_T currTimeIndex = helikopter_task4_DW.FromWorkspace4_IWORK.PrevIndex;
    real_T t = helikopter_task4_M->Timing.t[0];

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

    helikopter_task4_DW.FromWorkspace4_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_FromWorkspace4 = pDataValues[currTimeIndex];
        } else {
          rtb_FromWorkspace4 = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_FromWorkspace4 = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 81;
      }
    }
  }

  /* FromWorkspace: '<Root>/From Workspace5' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task4_DW.FromWorkspace5_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task4_DW.FromWorkspace5_PWORK.TimePtr;
    int_T currTimeIndex = helikopter_task4_DW.FromWorkspace5_IWORK.PrevIndex;
    real_T t = helikopter_task4_M->Timing.t[0];

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

    helikopter_task4_DW.FromWorkspace5_IWORK.PrevIndex = currTimeIndex;

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
        pDataValues += 81;
      }
    }
  }

  /* FromWorkspace: '<Root>/From Workspace7' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task4_DW.FromWorkspace7_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task4_DW.FromWorkspace7_PWORK.TimePtr;
    int_T currTimeIndex = helikopter_task4_DW.FromWorkspace7_IWORK.PrevIndex;
    real_T t = helikopter_task4_M->Timing.t[0];

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

    helikopter_task4_DW.FromWorkspace7_IWORK.PrevIndex = currTimeIndex;

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

  if (rtmIsMajorTimeStep(helikopter_task4_M)) {
    /* Gain: '<S9>/Travel: Count to rad' */
    helikopter_task4_B.TravelCounttorad =
      helikopter_task4_P.TravelCounttorad_Gain * rtb_HILReadEncoderTimebase_o1;

    /* Gain: '<S16>/Gain' */
    helikopter_task4_B.Gain_p = helikopter_task4_P.Gain_Gain_a *
      helikopter_task4_B.TravelCounttorad;

    /* Sum: '<Root>/Sum5' incorporates:
     *  Constant: '<Root>/elavation_offset [deg]1'
     */
    helikopter_task4_B.Sum5 = helikopter_task4_B.Gain_p +
      helikopter_task4_P.elavation_offsetdeg1_Value;
  }

  /* TransferFcn: '<S9>/Travel: Transfer Fcn' */
  rtb_Backgain = 0.0;
  rtb_Backgain += helikopter_task4_P.TravelTransferFcn_C *
    helikopter_task4_X.TravelTransferFcn_CSTATE;
  rtb_Backgain += helikopter_task4_P.TravelTransferFcn_D *
    helikopter_task4_B.TravelCounttorad;

  /* Gain: '<S17>/Gain' */
  helikopter_task4_B.Gain_d = helikopter_task4_P.Gain_Gain_l * rtb_Backgain;
  if (rtmIsMajorTimeStep(helikopter_task4_M)) {
    /* Gain: '<S9>/Pitch: Count to rad' */
    helikopter_task4_B.PitchCounttorad = helikopter_task4_P.PitchCounttorad_Gain
      * rtb_HILReadEncoderTimebase_o2;

    /* Gain: '<S13>/Gain' */
    helikopter_task4_B.Gain_i = helikopter_task4_P.Gain_Gain_ar *
      helikopter_task4_B.PitchCounttorad;
  }

  /* TransferFcn: '<S9>/Pitch: Transfer Fcn' */
  rtb_Backgain = 0.0;
  rtb_Backgain += helikopter_task4_P.PitchTransferFcn_C *
    helikopter_task4_X.PitchTransferFcn_CSTATE;
  rtb_Backgain += helikopter_task4_P.PitchTransferFcn_D *
    helikopter_task4_B.PitchCounttorad;

  /* Gain: '<S14>/Gain' */
  helikopter_task4_B.Gain_b = helikopter_task4_P.Gain_Gain_ae * rtb_Backgain;

  /* TransferFcn: '<S9>/Elevation: Transfer Fcn' */
  rtb_Backgain = 0.0;
  rtb_Backgain += helikopter_task4_P.ElevationTransferFcn_C *
    helikopter_task4_X.ElevationTransferFcn_CSTATE;
  rtb_Backgain += helikopter_task4_P.ElevationTransferFcn_D *
    helikopter_task4_B.ElevationCounttorad;

  /* Gain: '<S12>/Gain' */
  helikopter_task4_B.Gain_dg = helikopter_task4_P.Gain_Gain_n * rtb_Backgain;

  /* Gain: '<S2>/Gain1' */
  rtb_Gain1_idx_2 = helikopter_task4_P.Gain1_Gain * helikopter_task4_B.Gain_i;
  rtb_Gain1_idx_3 = helikopter_task4_P.Gain1_Gain * helikopter_task4_B.Gain_b;
  rtb_Gain1_idx_4 = helikopter_task4_P.Gain1_Gain * helikopter_task4_B.Sum;
  rtb_Gain1_idx_5 = helikopter_task4_P.Gain1_Gain * helikopter_task4_B.Gain_dg;

  /* Sum: '<Root>/Sum3' incorporates:
   *  Gain: '<S2>/Gain1'
   */
  rtb_Sum3_e[0] = helikopter_task4_P.Gain1_Gain * helikopter_task4_B.Sum5 -
    rtb_FromWorkspace2;
  rtb_Sum3_e[1] = helikopter_task4_P.Gain1_Gain * helikopter_task4_B.Gain_d -
    rtb_FromWorkspace3;
  rtb_Sum3_e[2] = rtb_Gain1_idx_2 - rtb_FromWorkspace4;
  rtb_Sum3_e[3] = rtb_Gain1_idx_3 - rtb_Frontgain;
  rtb_Sum3_e[4] = rtb_Gain1_idx_4 - helikopter_task4_B.FromWorkspace6;
  rtb_Sum3_e[5] = rtb_Gain1_idx_5 - rtb_Derivative;

  /* FromWorkspace: '<Root>/From Workspace' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task4_DW.FromWorkspace_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task4_DW.FromWorkspace_PWORK.TimePtr;
    int_T currTimeIndex = helikopter_task4_DW.FromWorkspace_IWORK.PrevIndex;
    real_T t = helikopter_task4_M->Timing.t[0];

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

    helikopter_task4_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_Backgain = pDataValues[currTimeIndex];
        } else {
          rtb_Backgain = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Backgain = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 81;
      }
    }
  }

  /* FromWorkspace: '<Root>/From Workspace1' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task4_DW.FromWorkspace1_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task4_DW.FromWorkspace1_PWORK.TimePtr;
    int_T currTimeIndex = helikopter_task4_DW.FromWorkspace1_IWORK.PrevIndex;
    real_T t = helikopter_task4_M->Timing.t[0];

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

    helikopter_task4_DW.FromWorkspace1_IWORK.PrevIndex = currTimeIndex;

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

  /* Gain: '<Root>/Gain' incorporates:
   *  Sum: '<Root>/Sum4'
   */
  for (i = 0; i < 2; i++) {
    tmp[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp[i] += helikopter_task4_P.K[(i_0 << 1) + i] * rtb_Sum3_e[i_0];
    }
  }

  /* End of Gain: '<Root>/Gain' */

  /* Sum: '<Root>/Sum4' */
  helikopter_task4_B.Sum4[0] = rtb_Backgain - tmp[0];
  helikopter_task4_B.Sum4[1] = rtb_Derivative - tmp[1];
  if (rtmIsMajorTimeStep(helikopter_task4_M)) {
    /* Gain: '<S4>/Gain1' */
    rtb_Gain1_f = helikopter_task4_P.Gain1_Gain_n * helikopter_task4_B.Sum5;

    /* ToFile: '<Root>/To File' */
    {
      if (!(++helikopter_task4_DW.ToFile_IWORK.Decimation % 1) &&
          (helikopter_task4_DW.ToFile_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) helikopter_task4_DW.ToFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          helikopter_task4_DW.ToFile_IWORK.Decimation = 0;
          u[0] = helikopter_task4_M->Timing.t[1];
          u[1] = rtb_Gain1_f;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(helikopter_task4_M,
                              "Error writing to MAT-file measured_travel.mat");
            return;
          }

          if (((++helikopter_task4_DW.ToFile_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file measured_travel.mat.\n");
          }
        }
      }
    }

    /* Gain: '<S3>/Gain1' */
    rtb_Gain1_f = helikopter_task4_P.Gain1_Gain_e * helikopter_task4_B.Gain_i;

    /* ToFile: '<Root>/To File1' */
    {
      if (!(++helikopter_task4_DW.ToFile1_IWORK.Decimation % 1) &&
          (helikopter_task4_DW.ToFile1_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) helikopter_task4_DW.ToFile1_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          helikopter_task4_DW.ToFile1_IWORK.Decimation = 0;
          u[0] = helikopter_task4_M->Timing.t[1];
          u[1] = rtb_Gain1_f;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(helikopter_task4_M,
                              "Error writing to MAT-file measured_pitch.mat");
            return;
          }

          if (((++helikopter_task4_DW.ToFile1_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file measured_pitch.mat.\n");
          }
        }
      }
    }

    /* Gain: '<S5>/Gain1' */
    rtb_Gain1_f = helikopter_task4_P.Gain1_Gain_k * helikopter_task4_B.Sum;

    /* ToFile: '<Root>/To File3' */
    {
      if (!(++helikopter_task4_DW.ToFile3_IWORK.Decimation % 1) &&
          (helikopter_task4_DW.ToFile3_IWORK.Count*2)+1 < 100000000 ) {
        FILE *fp = (FILE *) helikopter_task4_DW.ToFile3_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          helikopter_task4_DW.ToFile3_IWORK.Decimation = 0;
          u[0] = helikopter_task4_M->Timing.t[1];
          u[1] = rtb_Gain1_f;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(helikopter_task4_M,
                              "Error writing to MAT-file measured_elevation.mat");
            return;
          }

          if (((++helikopter_task4_DW.ToFile3_IWORK.Count)*2)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file measured_elevation.mat.\n");
          }
        }
      }
    }
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Vd_bias'
   *  Gain: '<S10>/K_pd'
   *  Gain: '<S10>/K_pp'
   *  Sum: '<S10>/Sum2'
   *  Sum: '<S10>/Sum3'
   */
  helikopter_task4_B.Sum1 = ((helikopter_task4_B.Sum4[0] - rtb_Gain1_idx_2) *
    helikopter_task4_P.K_pp - helikopter_task4_P.K_pd * rtb_Gain1_idx_3) +
    helikopter_task4_P.Vd_ff;
  if (rtmIsMajorTimeStep(helikopter_task4_M)) {
  }

  /* Gain: '<S6>/Gain1' */
  helikopter_task4_B.Gain1 = helikopter_task4_P.Gain1_Gain_f *
    helikopter_task4_B.Gain_d;
  if (rtmIsMajorTimeStep(helikopter_task4_M)) {
  }

  /* Gain: '<S7>/Gain1' */
  helikopter_task4_B.Gain1_h = helikopter_task4_P.Gain1_Gain_o *
    helikopter_task4_B.Gain_dg;
  if (rtmIsMajorTimeStep(helikopter_task4_M)) {
  }

  /* Integrator: '<S8>/Integrator'
   *
   * Regarding '<S8>/Integrator':
   *  Limited Integrator
   */
  if (helikopter_task4_X.Integrator_CSTATE >=
      helikopter_task4_P.Integrator_UpperSat ) {
    helikopter_task4_X.Integrator_CSTATE =
      helikopter_task4_P.Integrator_UpperSat;
  } else if (helikopter_task4_X.Integrator_CSTATE <=
             (helikopter_task4_P.Integrator_LowerSat) ) {
    helikopter_task4_X.Integrator_CSTATE =
      (helikopter_task4_P.Integrator_LowerSat);
  }

  rtb_Backgain = helikopter_task4_X.Integrator_CSTATE;

  /* Sum: '<S8>/Sum' */
  rtb_Derivative = helikopter_task4_B.Sum4[1] - rtb_Gain1_idx_4;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Vs_bias'
   *  Gain: '<S8>/K_ed'
   *  Gain: '<S8>/K_ep'
   *  Sum: '<S8>/Sum1'
   */
  helikopter_task4_B.Sum2 = ((helikopter_task4_P.K_ep * rtb_Derivative +
    rtb_Backgain) - helikopter_task4_P.K_ed * rtb_Gain1_idx_5) +
    helikopter_task4_P.Vs_ff;
  if (rtmIsMajorTimeStep(helikopter_task4_M)) {
  }

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  rtb_Backgain = (helikopter_task4_B.Sum2 - helikopter_task4_B.Sum1) *
    helikopter_task4_P.Backgain_Gain;

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  rtb_Frontgain = (helikopter_task4_B.Sum1 + helikopter_task4_B.Sum2) *
    helikopter_task4_P.Frontgain_Gain;

  /* Gain: '<S8>/K_ei' */
  helikopter_task4_B.K_ei = helikopter_task4_P.K_ei * rtb_Derivative;
  if (rtmIsMajorTimeStep(helikopter_task4_M)) {
  }

  /* Derivative: '<S9>/Derivative' */
  if ((helikopter_task4_DW.TimeStampA >= helikopter_task4_M->Timing.t[0]) &&
      (helikopter_task4_DW.TimeStampB >= helikopter_task4_M->Timing.t[0])) {
    rtb_Derivative = 0.0;
  } else {
    rtb_Gain1_idx_2 = helikopter_task4_DW.TimeStampA;
    lastU = &helikopter_task4_DW.LastUAtTimeA;
    if (helikopter_task4_DW.TimeStampA < helikopter_task4_DW.TimeStampB) {
      if (helikopter_task4_DW.TimeStampB < helikopter_task4_M->Timing.t[0]) {
        rtb_Gain1_idx_2 = helikopter_task4_DW.TimeStampB;
        lastU = &helikopter_task4_DW.LastUAtTimeB;
      }
    } else {
      if (helikopter_task4_DW.TimeStampA >= helikopter_task4_M->Timing.t[0]) {
        rtb_Gain1_idx_2 = helikopter_task4_DW.TimeStampB;
        lastU = &helikopter_task4_DW.LastUAtTimeB;
      }
    }

    rtb_Derivative = (helikopter_task4_B.PitchCounttorad - *lastU) /
      (helikopter_task4_M->Timing.t[0] - rtb_Gain1_idx_2);
  }

  /* End of Derivative: '<S9>/Derivative' */

  /* Gain: '<S15>/Gain' */
  helikopter_task4_B.Gain_l = helikopter_task4_P.Gain_Gain_a1 * rtb_Derivative;
  if (rtmIsMajorTimeStep(helikopter_task4_M)) {
  }

  /* Saturate: '<S9>/Back motor: Saturation' */
  if (rtb_Backgain > helikopter_task4_P.BackmotorSaturation_UpperSat) {
    helikopter_task4_B.BackmotorSaturation =
      helikopter_task4_P.BackmotorSaturation_UpperSat;
  } else if (rtb_Backgain < helikopter_task4_P.BackmotorSaturation_LowerSat) {
    helikopter_task4_B.BackmotorSaturation =
      helikopter_task4_P.BackmotorSaturation_LowerSat;
  } else {
    helikopter_task4_B.BackmotorSaturation = rtb_Backgain;
  }

  /* End of Saturate: '<S9>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(helikopter_task4_M)) {
  }

  /* Saturate: '<S9>/Front motor: Saturation' */
  if (rtb_Frontgain > helikopter_task4_P.FrontmotorSaturation_UpperSat) {
    helikopter_task4_B.FrontmotorSaturation =
      helikopter_task4_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Frontgain < helikopter_task4_P.FrontmotorSaturation_LowerSat) {
    helikopter_task4_B.FrontmotorSaturation =
      helikopter_task4_P.FrontmotorSaturation_LowerSat;
  } else {
    helikopter_task4_B.FrontmotorSaturation = rtb_Frontgain;
  }

  /* End of Saturate: '<S9>/Front motor: Saturation' */
  if (rtmIsMajorTimeStep(helikopter_task4_M)) {
    /* S-Function (hil_write_analog_block): '<S9>/HIL Write Analog' */

    /* S-Function Block: helikopter_task4/Helicopter_interface/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      helikopter_task4_DW.HILWriteAnalog_Buffer[0] =
        helikopter_task4_B.FrontmotorSaturation;
      helikopter_task4_DW.HILWriteAnalog_Buffer[1] =
        helikopter_task4_B.BackmotorSaturation;
      result = hil_write_analog(helikopter_task4_DW.HILInitialize_Card,
        helikopter_task4_P.HILWriteAnalog_channels, 2,
        &helikopter_task4_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
      }
    }
  }
}

/* Model update function */
void helikopter_task4_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<S9>/Derivative' */
  if (helikopter_task4_DW.TimeStampA == (rtInf)) {
    helikopter_task4_DW.TimeStampA = helikopter_task4_M->Timing.t[0];
    lastU = &helikopter_task4_DW.LastUAtTimeA;
  } else if (helikopter_task4_DW.TimeStampB == (rtInf)) {
    helikopter_task4_DW.TimeStampB = helikopter_task4_M->Timing.t[0];
    lastU = &helikopter_task4_DW.LastUAtTimeB;
  } else if (helikopter_task4_DW.TimeStampA < helikopter_task4_DW.TimeStampB) {
    helikopter_task4_DW.TimeStampA = helikopter_task4_M->Timing.t[0];
    lastU = &helikopter_task4_DW.LastUAtTimeA;
  } else {
    helikopter_task4_DW.TimeStampB = helikopter_task4_M->Timing.t[0];
    lastU = &helikopter_task4_DW.LastUAtTimeB;
  }

  *lastU = helikopter_task4_B.PitchCounttorad;

  /* End of Update for Derivative: '<S9>/Derivative' */
  if (rtmIsMajorTimeStep(helikopter_task4_M)) {
    rt_ertODEUpdateContinuousStates(&helikopter_task4_M->solverInfo);
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
  if (!(++helikopter_task4_M->Timing.clockTick0)) {
    ++helikopter_task4_M->Timing.clockTickH0;
  }

  helikopter_task4_M->Timing.t[0] = rtsiGetSolverStopTime
    (&helikopter_task4_M->solverInfo);

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
    if (!(++helikopter_task4_M->Timing.clockTick1)) {
      ++helikopter_task4_M->Timing.clockTickH1;
    }

    helikopter_task4_M->Timing.t[1] = helikopter_task4_M->Timing.clockTick1 *
      helikopter_task4_M->Timing.stepSize1 +
      helikopter_task4_M->Timing.clockTickH1 *
      helikopter_task4_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void helikopter_task4_derivatives(void)
{
  XDot_helikopter_task4_T *_rtXdot;
  _rtXdot = ((XDot_helikopter_task4_T *) helikopter_task4_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S9>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += helikopter_task4_P.TravelTransferFcn_A *
    helikopter_task4_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += helikopter_task4_B.TravelCounttorad;

  /* Derivatives for TransferFcn: '<S9>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += helikopter_task4_P.PitchTransferFcn_A *
    helikopter_task4_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += helikopter_task4_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S9>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    helikopter_task4_P.ElevationTransferFcn_A *
    helikopter_task4_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += helikopter_task4_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<S8>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( helikopter_task4_X.Integrator_CSTATE <=
            (helikopter_task4_P.Integrator_LowerSat) );
    usat = ( helikopter_task4_X.Integrator_CSTATE >=
            helikopter_task4_P.Integrator_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (helikopter_task4_B.K_ei > 0)) ||
        (usat && (helikopter_task4_B.K_ei < 0)) ) {
      ((XDot_helikopter_task4_T *) helikopter_task4_M->ModelData.derivs)
        ->Integrator_CSTATE = helikopter_task4_B.K_ei;
    } else {
      /* in saturation */
      ((XDot_helikopter_task4_T *) helikopter_task4_M->ModelData.derivs)
        ->Integrator_CSTATE = 0.0;
    }
  }
}

/* Model initialize function */
void helikopter_task4_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helikopter_task4/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &helikopter_task4_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (helikopter_task4_DW.HILInitialize_Card, "update_rate=normal;decimation=1",
       32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(helikopter_task4_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
      return;
    }

    if ((helikopter_task4_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (helikopter_task4_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &helikopter_task4_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = helikopter_task4_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &helikopter_task4_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = helikopter_task4_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges
        (helikopter_task4_DW.HILInitialize_Card,
         helikopter_task4_P.HILInitialize_analog_input_chan, 8U,
         &helikopter_task4_DW.HILInitialize_AIMinimums[0],
         &helikopter_task4_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task4_P.HILInitialize_set_analog_output && !is_switching) ||
        (helikopter_task4_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &helikopter_task4_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = helikopter_task4_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &helikopter_task4_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = helikopter_task4_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges
        (helikopter_task4_DW.HILInitialize_Card,
         helikopter_task4_P.HILInitialize_analog_output_cha, 8U,
         &helikopter_task4_DW.HILInitialize_AOMinimums[0],
         &helikopter_task4_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task4_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (helikopter_task4_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &helikopter_task4_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helikopter_task4_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(helikopter_task4_DW.HILInitialize_Card,
        helikopter_task4_P.HILInitialize_analog_output_cha, 8U,
        &helikopter_task4_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
        return;
      }
    }

    if (helikopter_task4_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &helikopter_task4_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helikopter_task4_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (helikopter_task4_DW.HILInitialize_Card,
         helikopter_task4_P.HILInitialize_analog_output_cha, 8U,
         &helikopter_task4_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task4_P.HILInitialize_set_encoder_param && !is_switching) ||
        (helikopter_task4_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &helikopter_task4_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = helikopter_task4_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (helikopter_task4_DW.HILInitialize_Card,
         helikopter_task4_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &helikopter_task4_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task4_P.HILInitialize_set_encoder_count && !is_switching) ||
        (helikopter_task4_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &helikopter_task4_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            helikopter_task4_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(helikopter_task4_DW.HILInitialize_Card,
        helikopter_task4_P.HILInitialize_encoder_channels, 8U,
        &helikopter_task4_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task4_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (helikopter_task4_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &helikopter_task4_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = helikopter_task4_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(helikopter_task4_DW.HILInitialize_Card,
        helikopter_task4_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &helikopter_task4_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          helikopter_task4_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues =
          &helikopter_task4_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            helikopter_task4_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = p_HILInitialize_pwm_channels[i1];
            helikopter_task4_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = helikopter_task4_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            helikopter_task4_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = p_HILInitialize_pwm_channels[i1];
            helikopter_task4_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              helikopter_task4_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(helikopter_task4_DW.HILInitialize_Card,
          &helikopter_task4_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &helikopter_task4_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(helikopter_task4_DW.HILInitialize_Card,
          &helikopter_task4_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &helikopter_task4_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &helikopter_task4_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            helikopter_task4_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &helikopter_task4_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = helikopter_task4_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &helikopter_task4_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = helikopter_task4_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(helikopter_task4_DW.HILInitialize_Card,
        helikopter_task4_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &helikopter_task4_DW.HILInitialize_POModeValues
        [0],
        (t_pwm_alignment *) &helikopter_task4_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &helikopter_task4_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &helikopter_task4_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] =
            helikopter_task4_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &helikopter_task4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helikopter_task4_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(helikopter_task4_DW.HILInitialize_Card,
        helikopter_task4_P.HILInitialize_pwm_channels, 8U,
        &helikopter_task4_DW.HILInitialize_POSortedFreqs[0],
        &helikopter_task4_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task4_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (helikopter_task4_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &helikopter_task4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helikopter_task4_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(helikopter_task4_DW.HILInitialize_Card,
        helikopter_task4_P.HILInitialize_pwm_channels, 8U,
        &helikopter_task4_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
        return;
      }
    }

    if (helikopter_task4_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &helikopter_task4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helikopter_task4_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (helikopter_task4_DW.HILInitialize_Card,
         helikopter_task4_P.HILInitialize_pwm_channels, 8U,
         &helikopter_task4_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S9>/HIL Read Encoder Timebase' */

  /* S-Function Block: helikopter_task4/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (helikopter_task4_DW.HILInitialize_Card,
       helikopter_task4_P.HILReadEncoderTimebase_samples_,
       helikopter_task4_P.HILReadEncoderTimebase_channels, 3,
       &helikopter_task4_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
    }
  }

  /* Start for ToFile: '<Root>/To File2' */
  {
    char fileName[509] = "measured_time.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(helikopter_task4_M,
                        "Error creating .mat file measured_time.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"measured_time")) {
      rtmSetErrorStatus(helikopter_task4_M,
                        "Error writing mat file header to file measured_time.mat");
      return;
    }

    helikopter_task4_DW.ToFile2_IWORK.Count = 0;
    helikopter_task4_DW.ToFile2_IWORK.Decimation = -1;
    helikopter_task4_DW.ToFile2_PWORK.FilePtr = fp;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace6' */
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
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.002762461652437992, 0.0078252556680861087, 0.014807513601247504,
      0.023394400916691972, 0.033323697291382931, 0.044373690463312361,
      0.056352039319776892, 0.0690853875892288, 0.082409388689812915,
      0.096158757853594817, 0.11015715922540245, 0.12420643732747712,
      0.13807513479640143, 0.15148578057946085, 0.16410048999040858,
      0.17550461412118076, 0.185187965597055, 0.19252295525536775,
      0.19673905277581527, 0.19689294863176082, 0.19393430220032618,
      0.18863883949803339, 0.18163702242847959, 0.17343817006576476,
      0.16445094881654654, 0.15500055823899922, 0.1453432080132096,
      0.13567829679858825, 0.12615861570907591, 0.11689888141790329,
      0.10798283535447693, 0.099469257527912025, 0.091396829508971,
      0.083788310643556629, 0.07665382837873605, 0.069993783188682671,
      0.063801038886666564, 0.058062840380624953, 0.0527623131046416, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0 } ;

    helikopter_task4_DW.FromWorkspace6_PWORK.TimePtr = (void *) pTimeValues0;
    helikopter_task4_DW.FromWorkspace6_PWORK.DataPtr = (void *) pDataValues0;
    helikopter_task4_DW.FromWorkspace6_IWORK.PrevIndex = 0;
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
      19.75, 20.0 } ;

    static real_T pDataValues0[] = { 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
      3.1415926535897931, 3.1378421413625261, 3.1262155534579983,
      3.1033093000299643, 3.0666274151911783, 3.0144539223941584,
      2.947609854732681, 2.8730648783549331, 2.7980648783549329,
      2.7230648783549327, 2.6480648783549325, 2.5730648783549324,
      2.4980648783549322, 2.423064878354932, 2.3480648783549318,
      2.2730648783549317, 2.1980648783549315, 2.1230648783549313,
      2.0480648783549311, 1.9730648783549312, 1.8980648783549312,
      1.8230648783549313, 1.7480648783549313, 1.6730648783549313,
      1.5980648783549314, 1.5230648783549314, 1.4480648783549315,
      1.3730648783549315, 1.2980648783549316, 1.2230648783549316,
      1.1480648783549317, 1.0730648783549317, 0.99806487835493174,
      0.92306487835493178, 0.84806487835493183, 0.77306487835493187,
      0.69806487835493192, 0.623064878354932, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task4_DW.FromWorkspace2_PWORK.TimePtr = (void *) pTimeValues0;
    helikopter_task4_DW.FromWorkspace2_PWORK.DataPtr = (void *) pDataValues0;
    helikopter_task4_DW.FromWorkspace2_IWORK.PrevIndex = 0;
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
      19.75, 20.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      -0.015002048909068423, -0.046506351618112111, -0.091625013712135384,
      -0.14672753935514371, -0.20869397118807925, -0.26737627064590985,
      -0.29817990551099205, -0.3, -0.3, -0.3, -0.3, -0.3, -0.3, -0.3, -0.3, -0.3,
      -0.3, -0.3, -0.3, -0.3, -0.3, -0.3, -0.3, -0.3, -0.3, -0.3, -0.3, -0.3,
      -0.3, -0.3, -0.3, -0.3, -0.3, -0.3, -0.3, -0.3, -0.3, -0.3, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0 } ;

    helikopter_task4_DW.FromWorkspace3_PWORK.TimePtr = (void *) pTimeValues0;
    helikopter_task4_DW.FromWorkspace3_PWORK.DataPtr = (void *) pDataValues0;
    helikopter_task4_DW.FromWorkspace3_IWORK.PrevIndex = 0;
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
      19.75, 20.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.10602875205865551, 0.22266037932317656, 0.31888147181640641,
      0.38944360631144165, 0.43795507377677839, 0.41474408043590777,
      0.21770832660336753, 0.012863732711982439, -1.4638434442683428E-16,
      1.4059655098607267E-16, -1.8597126505587745E-16, 1.4268460849298531E-16,
      -1.7442677028849972E-17, 1.3646558309986564E-17, -1.0153657378588301E-17,
      1.7568457561969833E-16, 1.1205729736647371E-16, 7.4424696523473635E-17,
      -1.3350133434352234E-16, 6.6877313670058418E-17, 1.547234434493497E-16,
      1.3896543901219752E-16, 1.7296679876370171E-17, -2.0826911538040526E-17,
      -3.1862129156765255E-17, 1.7719604129745077E-16, 1.8178963878705246E-16,
      -9.9814205850274346E-19, 1.6192617370134613E-17, -1.1972037922756161E-16,
      -6.96490844974282E-17, -1.0712949124747923E-16, 2.0553166508369507E-17,
      7.7457378072262081E-17, -2.6249231673644749E-17, 9.4454474066823507E-17,
      -1.3314277070728039E-16, 1.0756037292796892E-16, 1.0511651587772851E-8,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task4_DW.FromWorkspace4_PWORK.TimePtr = (void *) pTimeValues0;
    helikopter_task4_DW.FromWorkspace4_PWORK.DataPtr = (void *) pDataValues0;
    helikopter_task4_DW.FromWorkspace4_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace5' */
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
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.42411500823462206, 0.46652650905808424, 0.38488436997291947,
      0.282248537980141, 0.19404586986134689, -0.092843973363482671,
      -0.78814301533016085, -0.81937837556554038, -0.051454930847930347,
      1.1479231344737574E-15, -1.3062705710533042E-15, 1.3146239125413889E-15,
      -6.405083896287181E-16, 1.2435737119375717E-16, -9.5200566306147355E-17,
      7.4335281610637113E-16, -2.5450896467976227E-16, -1.5053038936145122E-16,
      -8.3170412781189384E-16, 8.0151457927737654E-16, 3.5138451964321333E-16,
      -6.303201496379161E-17, -4.8667503257920307E-16, -1.524943948031E-16,
      -4.4140875899609215E-17, 8.3623269253730345E-16, 1.8374404601910507E-17,
      -7.3115112616156007E-16, 6.8763015007730967E-17, -5.4365197117226743E-16,
      2.0028515764199726E-16, -1.499216395691919E-16, 5.1073062948840083E-16,
      2.2761687429296745E-16, -4.1482644972190028E-16, 4.8281482216351106E-16,
      -9.1039087638852657E-16, 9.6281403963316826E-16, 4.2046605920850759E-8,
      -9.2590987979035866E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task4_DW.FromWorkspace5_PWORK.TimePtr = (void *) pTimeValues0;
    helikopter_task4_DW.FromWorkspace5_PWORK.DataPtr = (void *) pDataValues0;
    helikopter_task4_DW.FromWorkspace5_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace7' */
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
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.011049846609751968, 0.020251176062592469, 0.027929031732645576,
      0.034347549261777861, 0.039717185498763838, 0.044199972687717713,
      0.047913395425858131, 0.05093339307780765, 0.053296004402336408,
      0.054997476655127622, 0.055993605487230529, 0.056197112408298625,
      0.055474789875697261, 0.05364258313223768, 0.050458837643790874,
      0.045616496523088745, 0.038733405903496873, 0.029339958633251045,
      0.016864390081790089, 0.00061558342378227073, -0.011834585725738622,
      -0.021181850809171131, -0.028007268278215185, -0.032795409450859292,
      -0.035948884996872821, -0.037801562310189281, -0.038629400903158563,
      -0.038659644858485373, -0.038078724358049321, -0.037038937164690519,
      -0.035664184253705433, -0.034054311306259646, -0.032289712075764108,
      -0.030434075461657491, -0.0285379290592823, -0.026640180760213492,
      -0.024770977208064406, -0.022952794024166466, -0.021202109103933411,
      -0.019530468549164126, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task4_DW.FromWorkspace7_PWORK.TimePtr = (void *) pTimeValues0;
    helikopter_task4_DW.FromWorkspace7_PWORK.DataPtr = (void *) pDataValues0;
    helikopter_task4_DW.FromWorkspace7_IWORK.PrevIndex = 0;
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
      0.52359877559829882, 0.25086513674401284, -0.52359877559829882,
      -0.49953255417214687, 0.2553415447621622, 0.019216193310493776,
      -1.9007828871663118E-15, 1.9248570024349857E-15, -1.1390215275521213E-15,
      3.7528743046576754E-16, -1.5032688208559163E-16, 9.4311925077399755E-16,
      -4.1613422506141484E-16, 2.1265453296176928E-17, -8.96153915238836E-16,
      1.1666283810656015E-15, 2.0135430249184936E-16, -5.4320789757935696E-17,
      -4.3832819921662123E-16, 1.0784093986203035E-17, -1.8371757593965461E-17,
      1.0170086139216005E-15, -1.1241627831340384E-16, -7.277281316862557E-16,
      3.5694781879392048E-16, -6.8066267651921753E-16, 3.3057576957890833E-16,
      -3.2953538240878172E-16, 5.7939139687025764E-16, 1.1082583611013298E-16,
      -5.196790996792997E-16, 7.2473819687199774E-16, -1.209795353103114E-15,
      1.3955080093647004E-15, 5.1909389773733204E-8, -1.148289555920148E-6,
      -1.148289555920148E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task4_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    helikopter_task4_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    helikopter_task4_DW.FromWorkspace_IWORK.PrevIndex = 0;
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
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.17679754575603152,
      0.19142065768445593, 0.20661285662365761, 0.2222376630647851,
      0.23811189044013456, 0.25398773793500928, 0.26953835185250058,
      0.2843472345979372, 0.29788739282346771, 0.30949296124323389,
      0.31833735662396995, 0.32338929053960647, 0.32338844833697528,
      0.31679028893491307, 0.30170553951020335, 0.27584367322339026,
      0.23643702616929357, 0.18014308141123503, 0.10293870330668384,
      -3.9094559699859229E-7, -1.3199213899473803E-6, -1.6356061138730192E-6,
      2.1945893680831919E-7, -4.9237713310073053E-7, -2.2411117409477895E-7,
      -2.0693478992114703E-7, -7.1791171909593261E-7, -9.4865886399611358E-7,
      -6.4341375509199845E-7, -5.539868253353887E-9, -1.0863739249218719E-6,
      1.1156221409220235E-7, -8.2218263304892668E-7, 5.950505614216773E-7,
      -1.1298996559850943E-6, 5.6719152838201506E-7, 3.6217226746455012E-7,
      8.0529879206274355E-7, 8.2151372955360541E-7, 6.5284119983972387E-7,
      6.5284119983972387E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task4_DW.FromWorkspace1_PWORK.TimePtr = (void *) pTimeValues0;
    helikopter_task4_DW.FromWorkspace1_PWORK.DataPtr = (void *) pDataValues0;
    helikopter_task4_DW.FromWorkspace1_IWORK.PrevIndex = 0;
  }

  /* Start for ToFile: '<Root>/To File' */
  {
    char fileName[509] = "measured_travel.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(helikopter_task4_M,
                        "Error creating .mat file measured_travel.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"measured_travel")) {
      rtmSetErrorStatus(helikopter_task4_M,
                        "Error writing mat file header to file measured_travel.mat");
      return;
    }

    helikopter_task4_DW.ToFile_IWORK.Count = 0;
    helikopter_task4_DW.ToFile_IWORK.Decimation = -1;
    helikopter_task4_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File1' */
  {
    char fileName[509] = "measured_pitch.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(helikopter_task4_M,
                        "Error creating .mat file measured_pitch.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"measured_pitch")) {
      rtmSetErrorStatus(helikopter_task4_M,
                        "Error writing mat file header to file measured_pitch.mat");
      return;
    }

    helikopter_task4_DW.ToFile1_IWORK.Count = 0;
    helikopter_task4_DW.ToFile1_IWORK.Decimation = -1;
    helikopter_task4_DW.ToFile1_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File3' */
  {
    char fileName[509] = "measured_elevation.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(helikopter_task4_M,
                        "Error creating .mat file measured_elevation.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"measured_elevation")) {
      rtmSetErrorStatus(helikopter_task4_M,
                        "Error writing mat file header to file measured_elevation.mat");
      return;
    }

    helikopter_task4_DW.ToFile3_IWORK.Count = 0;
    helikopter_task4_DW.ToFile3_IWORK.Decimation = -1;
    helikopter_task4_DW.ToFile3_PWORK.FilePtr = fp;
  }

  /* InitializeConditions for TransferFcn: '<S9>/Travel: Transfer Fcn' */
  helikopter_task4_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S9>/Pitch: Transfer Fcn' */
  helikopter_task4_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S9>/Elevation: Transfer Fcn' */
  helikopter_task4_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S8>/Integrator' */
  helikopter_task4_X.Integrator_CSTATE = helikopter_task4_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<S9>/Derivative' */
  helikopter_task4_DW.TimeStampA = (rtInf);
  helikopter_task4_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void helikopter_task4_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helikopter_task4/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(helikopter_task4_DW.HILInitialize_Card);
    hil_monitor_stop_all(helikopter_task4_DW.HILInitialize_Card);
    is_switching = false;
    if ((helikopter_task4_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (helikopter_task4_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &helikopter_task4_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = helikopter_task4_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((helikopter_task4_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (helikopter_task4_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &helikopter_task4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = helikopter_task4_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(helikopter_task4_DW.HILInitialize_Card
                         , helikopter_task4_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , helikopter_task4_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &helikopter_task4_DW.HILInitialize_AOVoltages[0]
                         , &helikopter_task4_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(helikopter_task4_DW.HILInitialize_Card,
            helikopter_task4_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs,
            &helikopter_task4_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(helikopter_task4_DW.HILInitialize_Card,
            helikopter_task4_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &helikopter_task4_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helikopter_task4_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(helikopter_task4_DW.HILInitialize_Card);
    hil_monitor_delete_all(helikopter_task4_DW.HILInitialize_Card);
    hil_close(helikopter_task4_DW.HILInitialize_Card);
    helikopter_task4_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<Root>/To File2' */
  {
    FILE *fp = (FILE *) helikopter_task4_DW.ToFile2_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "measured_time.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task4_M,
                          "Error closing MAT-file measured_time.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(helikopter_task4_M,
                          "Error reopening MAT-file measured_time.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, helikopter_task4_DW.ToFile2_IWORK.Count,
           "measured_time")) {
        rtmSetErrorStatus(helikopter_task4_M,
                          "Error writing header for measured_time to MAT-file measured_time.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task4_M,
                          "Error closing MAT-file measured_time.mat");
        return;
      }

      helikopter_task4_DW.ToFile2_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) helikopter_task4_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "measured_travel.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task4_M,
                          "Error closing MAT-file measured_travel.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(helikopter_task4_M,
                          "Error reopening MAT-file measured_travel.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, helikopter_task4_DW.ToFile_IWORK.Count,
           "measured_travel")) {
        rtmSetErrorStatus(helikopter_task4_M,
                          "Error writing header for measured_travel to MAT-file measured_travel.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task4_M,
                          "Error closing MAT-file measured_travel.mat");
        return;
      }

      helikopter_task4_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (FILE *) helikopter_task4_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "measured_pitch.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task4_M,
                          "Error closing MAT-file measured_pitch.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(helikopter_task4_M,
                          "Error reopening MAT-file measured_pitch.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, helikopter_task4_DW.ToFile1_IWORK.Count,
           "measured_pitch")) {
        rtmSetErrorStatus(helikopter_task4_M,
                          "Error writing header for measured_pitch to MAT-file measured_pitch.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task4_M,
                          "Error closing MAT-file measured_pitch.mat");
        return;
      }

      helikopter_task4_DW.ToFile1_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File3' */
  {
    FILE *fp = (FILE *) helikopter_task4_DW.ToFile3_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "measured_elevation.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task4_M,
                          "Error closing MAT-file measured_elevation.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(helikopter_task4_M,
                          "Error reopening MAT-file measured_elevation.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2, helikopter_task4_DW.ToFile3_IWORK.Count,
           "measured_elevation")) {
        rtmSetErrorStatus(helikopter_task4_M,
                          "Error writing header for measured_elevation to MAT-file measured_elevation.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task4_M,
                          "Error closing MAT-file measured_elevation.mat");
        return;
      }

      helikopter_task4_DW.ToFile3_PWORK.FilePtr = (NULL);
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
  helikopter_task4_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  helikopter_task4_update();
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
  helikopter_task4_initialize();
}

void MdlTerminate(void)
{
  helikopter_task4_terminate();
}

/* Registration function */
RT_MODEL_helikopter_task4_T *helikopter_task4(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  helikopter_task4_P.Integrator_UpperSat = rtInf;
  helikopter_task4_P.Integrator_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)helikopter_task4_M, 0,
                sizeof(RT_MODEL_helikopter_task4_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&helikopter_task4_M->solverInfo,
                          &helikopter_task4_M->Timing.simTimeStep);
    rtsiSetTPtr(&helikopter_task4_M->solverInfo, &rtmGetTPtr(helikopter_task4_M));
    rtsiSetStepSizePtr(&helikopter_task4_M->solverInfo,
                       &helikopter_task4_M->Timing.stepSize0);
    rtsiSetdXPtr(&helikopter_task4_M->solverInfo,
                 &helikopter_task4_M->ModelData.derivs);
    rtsiSetContStatesPtr(&helikopter_task4_M->solverInfo, (real_T **)
                         &helikopter_task4_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&helikopter_task4_M->solverInfo,
      &helikopter_task4_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&helikopter_task4_M->solverInfo, (&rtmGetErrorStatus
      (helikopter_task4_M)));
    rtsiSetRTModelPtr(&helikopter_task4_M->solverInfo, helikopter_task4_M);
  }

  rtsiSetSimTimeStep(&helikopter_task4_M->solverInfo, MAJOR_TIME_STEP);
  helikopter_task4_M->ModelData.intgData.f[0] =
    helikopter_task4_M->ModelData.odeF[0];
  helikopter_task4_M->ModelData.contStates = ((real_T *) &helikopter_task4_X);
  rtsiSetSolverData(&helikopter_task4_M->solverInfo, (void *)
                    &helikopter_task4_M->ModelData.intgData);
  rtsiSetSolverName(&helikopter_task4_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = helikopter_task4_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    helikopter_task4_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    helikopter_task4_M->Timing.sampleTimes =
      (&helikopter_task4_M->Timing.sampleTimesArray[0]);
    helikopter_task4_M->Timing.offsetTimes =
      (&helikopter_task4_M->Timing.offsetTimesArray[0]);

    /* task periods */
    helikopter_task4_M->Timing.sampleTimes[0] = (0.0);
    helikopter_task4_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    helikopter_task4_M->Timing.offsetTimes[0] = (0.0);
    helikopter_task4_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(helikopter_task4_M, &helikopter_task4_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = helikopter_task4_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    helikopter_task4_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(helikopter_task4_M, 45.0);
  helikopter_task4_M->Timing.stepSize0 = 0.002;
  helikopter_task4_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  helikopter_task4_M->Sizes.checksums[0] = (2040631303U);
  helikopter_task4_M->Sizes.checksums[1] = (3713224119U);
  helikopter_task4_M->Sizes.checksums[2] = (1129541304U);
  helikopter_task4_M->Sizes.checksums[3] = (437570964U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    helikopter_task4_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(helikopter_task4_M->extModeInfo,
      &helikopter_task4_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(helikopter_task4_M->extModeInfo,
                        helikopter_task4_M->Sizes.checksums);
    rteiSetTPtr(helikopter_task4_M->extModeInfo, rtmGetTPtr(helikopter_task4_M));
  }

  helikopter_task4_M->solverInfoPtr = (&helikopter_task4_M->solverInfo);
  helikopter_task4_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&helikopter_task4_M->solverInfo, 0.002);
  rtsiSetSolverMode(&helikopter_task4_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  helikopter_task4_M->ModelData.blockIO = ((void *) &helikopter_task4_B);

  {
    helikopter_task4_B.Clock = 0.0;
    helikopter_task4_B.FromWorkspace6 = 0.0;
    helikopter_task4_B.ElevationCounttorad = 0.0;
    helikopter_task4_B.Gain = 0.0;
    helikopter_task4_B.Sum = 0.0;
    helikopter_task4_B.TravelCounttorad = 0.0;
    helikopter_task4_B.Gain_p = 0.0;
    helikopter_task4_B.Sum5 = 0.0;
    helikopter_task4_B.Gain_d = 0.0;
    helikopter_task4_B.PitchCounttorad = 0.0;
    helikopter_task4_B.Gain_i = 0.0;
    helikopter_task4_B.Gain_b = 0.0;
    helikopter_task4_B.Gain_dg = 0.0;
    helikopter_task4_B.Sum4[0] = 0.0;
    helikopter_task4_B.Sum4[1] = 0.0;
    helikopter_task4_B.Sum1 = 0.0;
    helikopter_task4_B.Gain1 = 0.0;
    helikopter_task4_B.Gain1_h = 0.0;
    helikopter_task4_B.Sum2 = 0.0;
    helikopter_task4_B.K_ei = 0.0;
    helikopter_task4_B.Gain_l = 0.0;
    helikopter_task4_B.BackmotorSaturation = 0.0;
    helikopter_task4_B.FrontmotorSaturation = 0.0;
  }

  /* parameters */
  helikopter_task4_M->ModelData.defaultParam = ((real_T *)&helikopter_task4_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &helikopter_task4_X;
    helikopter_task4_M->ModelData.contStates = (x);
    (void) memset((void *)&helikopter_task4_X, 0,
                  sizeof(X_helikopter_task4_T));
  }

  /* states (dwork) */
  helikopter_task4_M->ModelData.dwork = ((void *) &helikopter_task4_DW);
  (void) memset((void *)&helikopter_task4_DW, 0,
                sizeof(DW_helikopter_task4_T));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task4_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task4_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task4_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task4_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task4_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task4_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task4_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      helikopter_task4_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  helikopter_task4_DW.TimeStampA = 0.0;
  helikopter_task4_DW.LastUAtTimeA = 0.0;
  helikopter_task4_DW.TimeStampB = 0.0;
  helikopter_task4_DW.LastUAtTimeB = 0.0;
  helikopter_task4_DW.HILWriteAnalog_Buffer[0] = 0.0;
  helikopter_task4_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    helikopter_task4_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  helikopter_task4_M->Sizes.numContStates = (4);/* Number of continuous states */
  helikopter_task4_M->Sizes.numY = (0);/* Number of model outputs */
  helikopter_task4_M->Sizes.numU = (0);/* Number of model inputs */
  helikopter_task4_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  helikopter_task4_M->Sizes.numSampTimes = (2);/* Number of sample times */
  helikopter_task4_M->Sizes.numBlocks = (79);/* Number of blocks */
  helikopter_task4_M->Sizes.numBlockIO = (22);/* Number of block outputs */
  helikopter_task4_M->Sizes.numBlockPrms = (158);/* Sum of parameter "widths" */
  return helikopter_task4_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
