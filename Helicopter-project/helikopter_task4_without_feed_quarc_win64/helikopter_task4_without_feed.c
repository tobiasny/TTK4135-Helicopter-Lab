/*
 * helikopter_task4_without_feed.c
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
#include "helikopter_task4_without_feed_dt.h"

/* Block signals (auto storage) */
B_helikopter_task4_without_fe_T helikopter_task4_without_feed_B;

/* Continuous states */
X_helikopter_task4_without_fe_T helikopter_task4_without_feed_X;

/* Block states (auto storage) */
DW_helikopter_task4_without_f_T helikopter_task4_without_fee_DW;

/* Real-time model */
RT_MODEL_helikopter_task4_wit_T helikopter_task4_without_fee_M_;
RT_MODEL_helikopter_task4_wit_T *const helikopter_task4_without_fee_M =
  &helikopter_task4_without_fee_M_;

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
  helikopter_task4_without_feed_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void helikopter_task4_without_feed_output(void)
{
  /* local block i/o variables */
  real_T rtb_FromWorkspace2;
  real_T rtb_FromWorkspace3;
  real_T rtb_Frontgain;
  real_T rtb_Derivative;
  real_T rtb_Backgain;
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_Gain1_g;
  real_T *lastU;
  real_T lastTime;
  real_T rtb_Gain1[6];
  real_T tmp[2];
  int32_T i;
  int32_T i_0;
  if (rtmIsMajorTimeStep(helikopter_task4_without_fee_M)) {
    /* set solver stop time */
    if (!(helikopter_task4_without_fee_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&helikopter_task4_without_fee_M->solverInfo,
                            ((helikopter_task4_without_fee_M->Timing.clockTickH0
        + 1) * helikopter_task4_without_fee_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&helikopter_task4_without_fee_M->solverInfo,
                            ((helikopter_task4_without_fee_M->Timing.clockTick0
        + 1) * helikopter_task4_without_fee_M->Timing.stepSize0 +
        helikopter_task4_without_fee_M->Timing.clockTickH0 *
        helikopter_task4_without_fee_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(helikopter_task4_without_fee_M)) {
    helikopter_task4_without_fee_M->Timing.t[0] = rtsiGetT
      (&helikopter_task4_without_fee_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(helikopter_task4_without_fee_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S6>/HIL Read Encoder Timebase' */

    /* S-Function Block: helikopter_task4_without_feed/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (helikopter_task4_without_fee_DW.HILReadEncoderTimebase_Task, 1,
         &helikopter_task4_without_fee_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          helikopter_task4_without_fee_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          helikopter_task4_without_fee_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_Gain1_g =
          helikopter_task4_without_fee_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }
  }

  /* FromWorkspace: '<Root>/From Workspace6' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task4_without_fee_DW.FromWorkspace6_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task4_without_fee_DW.FromWorkspace6_PWORK.TimePtr;
    int_T currTimeIndex =
      helikopter_task4_without_fee_DW.FromWorkspace6_IWORK.PrevIndex;
    real_T t = helikopter_task4_without_fee_M->Timing.t[0];

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

    helikopter_task4_without_fee_DW.FromWorkspace6_IWORK.PrevIndex =
      currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          helikopter_task4_without_feed_B.FromWorkspace6 =
            pDataValues[currTimeIndex];
        } else {
          helikopter_task4_without_feed_B.FromWorkspace6 =
            pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        helikopter_task4_without_feed_B.FromWorkspace6 = (real_T) rtInterpolate
          (d1, d2, f1, f2);
        pDataValues += 81;
      }
    }
  }

  if (rtmIsMajorTimeStep(helikopter_task4_without_fee_M)) {
    /* Gain: '<S6>/Elevation: Count to rad' */
    helikopter_task4_without_feed_B.ElevationCounttorad =
      helikopter_task4_without_feed_P.ElevationCounttorad_Gain * rtb_Gain1_g;

    /* Gain: '<S8>/Gain' */
    helikopter_task4_without_feed_B.Gain =
      helikopter_task4_without_feed_P.Gain_Gain *
      helikopter_task4_without_feed_B.ElevationCounttorad;

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/elavation_offset [deg]'
     */
    helikopter_task4_without_feed_B.Sum = helikopter_task4_without_feed_B.Gain +
      helikopter_task4_without_feed_P.elavation_offsetdeg_Value;
  }

  /* FromWorkspace: '<Root>/From Workspace2' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task4_without_fee_DW.FromWorkspace2_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task4_without_fee_DW.FromWorkspace2_PWORK.TimePtr;
    int_T currTimeIndex =
      helikopter_task4_without_fee_DW.FromWorkspace2_IWORK.PrevIndex;
    real_T t = helikopter_task4_without_fee_M->Timing.t[0];

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

    helikopter_task4_without_fee_DW.FromWorkspace2_IWORK.PrevIndex =
      currTimeIndex;

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
      helikopter_task4_without_fee_DW.FromWorkspace3_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task4_without_fee_DW.FromWorkspace3_PWORK.TimePtr;
    int_T currTimeIndex =
      helikopter_task4_without_fee_DW.FromWorkspace3_IWORK.PrevIndex;
    real_T t = helikopter_task4_without_fee_M->Timing.t[0];

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

    helikopter_task4_without_fee_DW.FromWorkspace3_IWORK.PrevIndex =
      currTimeIndex;

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
      helikopter_task4_without_fee_DW.FromWorkspace4_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task4_without_fee_DW.FromWorkspace4_PWORK.TimePtr;
    int_T currTimeIndex =
      helikopter_task4_without_fee_DW.FromWorkspace4_IWORK.PrevIndex;
    real_T t = helikopter_task4_without_fee_M->Timing.t[0];

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

    helikopter_task4_without_fee_DW.FromWorkspace4_IWORK.PrevIndex =
      currTimeIndex;

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

  /* FromWorkspace: '<Root>/From Workspace5' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task4_without_fee_DW.FromWorkspace5_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task4_without_fee_DW.FromWorkspace5_PWORK.TimePtr;
    int_T currTimeIndex =
      helikopter_task4_without_fee_DW.FromWorkspace5_IWORK.PrevIndex;
    real_T t = helikopter_task4_without_fee_M->Timing.t[0];

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

    helikopter_task4_without_fee_DW.FromWorkspace5_IWORK.PrevIndex =
      currTimeIndex;

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

  /* FromWorkspace: '<Root>/From Workspace7' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task4_without_fee_DW.FromWorkspace7_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task4_without_fee_DW.FromWorkspace7_PWORK.TimePtr;
    int_T currTimeIndex =
      helikopter_task4_without_fee_DW.FromWorkspace7_IWORK.PrevIndex;
    real_T t = helikopter_task4_without_fee_M->Timing.t[0];

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

    helikopter_task4_without_fee_DW.FromWorkspace7_IWORK.PrevIndex =
      currTimeIndex;

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

  /* SignalConversion: '<Root>/TmpSignal ConversionAtGainInport1' */
  rtb_Gain1[0] = rtb_FromWorkspace2;
  rtb_Gain1[1] = rtb_FromWorkspace3;
  rtb_Gain1[2] = rtb_Frontgain;
  rtb_Gain1[3] = rtb_Derivative;
  rtb_Gain1[4] = helikopter_task4_without_feed_B.FromWorkspace6;
  rtb_Gain1[5] = rtb_Backgain;

  /* FromWorkspace: '<Root>/From Workspace' */
  {
    real_T *pDataValues = (real_T *)
      helikopter_task4_without_fee_DW.FromWorkspace_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task4_without_fee_DW.FromWorkspace_PWORK.TimePtr;
    int_T currTimeIndex =
      helikopter_task4_without_fee_DW.FromWorkspace_IWORK.PrevIndex;
    real_T t = helikopter_task4_without_fee_M->Timing.t[0];

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

    helikopter_task4_without_fee_DW.FromWorkspace_IWORK.PrevIndex =
      currTimeIndex;

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
      helikopter_task4_without_fee_DW.FromWorkspace1_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      helikopter_task4_without_fee_DW.FromWorkspace1_PWORK.TimePtr;
    int_T currTimeIndex =
      helikopter_task4_without_fee_DW.FromWorkspace1_IWORK.PrevIndex;
    real_T t = helikopter_task4_without_fee_M->Timing.t[0];

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

    helikopter_task4_without_fee_DW.FromWorkspace1_IWORK.PrevIndex =
      currTimeIndex;

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
      tmp[i] += helikopter_task4_without_feed_P.K[(i_0 << 1) + i] *
        rtb_Gain1[i_0];
    }
  }

  /* End of Gain: '<Root>/Gain' */

  /* Sum: '<Root>/Sum4' */
  helikopter_task4_without_feed_B.Sum4[0] = rtb_Backgain - tmp[0];
  helikopter_task4_without_feed_B.Sum4[1] = rtb_Derivative - tmp[1];
  if (rtmIsMajorTimeStep(helikopter_task4_without_fee_M)) {
    /* Gain: '<S6>/Travel: Count to rad' */
    helikopter_task4_without_feed_B.TravelCounttorad =
      helikopter_task4_without_feed_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;

    /* Gain: '<S13>/Gain' */
    helikopter_task4_without_feed_B.Gain_c =
      helikopter_task4_without_feed_P.Gain_Gain_i *
      helikopter_task4_without_feed_B.TravelCounttorad;

    /* Sum: '<Root>/Sum5' incorporates:
     *  Constant: '<Root>/elavation_offset [deg]1'
     */
    helikopter_task4_without_feed_B.Sum5 =
      helikopter_task4_without_feed_B.Gain_c +
      helikopter_task4_without_feed_P.elavation_offsetdeg1_Value;

    /* Gain: '<S4>/Gain1' */
    rtb_Gain1_g = helikopter_task4_without_feed_P.Gain1_Gain *
      helikopter_task4_without_feed_B.Sum5;

    /* ToFile: '<Root>/To File' */
    {
      if (!(++helikopter_task4_without_fee_DW.ToFile_IWORK.Decimation % 1) &&
          (helikopter_task4_without_fee_DW.ToFile_IWORK.Count*2)+1 < 100000000 )
      {
        FILE *fp = (FILE *) helikopter_task4_without_fee_DW.ToFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          helikopter_task4_without_fee_DW.ToFile_IWORK.Decimation = 0;
          u[0] = helikopter_task4_without_fee_M->Timing.t[1];
          u[1] = rtb_Gain1_g;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(helikopter_task4_without_fee_M,
                              "Error writing to MAT-file measured_travel.mat");
            return;
          }

          if (((++helikopter_task4_without_fee_DW.ToFile_IWORK.Count)*2)+1 >=
              100000000) {
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
    helikopter_task4_without_feed_B.PitchCounttorad =
      helikopter_task4_without_feed_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Gain: '<S10>/Gain' */
    helikopter_task4_without_feed_B.Gain_n =
      helikopter_task4_without_feed_P.Gain_Gain_j *
      helikopter_task4_without_feed_B.PitchCounttorad;

    /* Gain: '<S3>/Gain1' */
    rtb_Gain1_g = helikopter_task4_without_feed_P.Gain1_Gain_h *
      helikopter_task4_without_feed_B.Gain_n;

    /* ToFile: '<Root>/To File1' */
    {
      if (!(++helikopter_task4_without_fee_DW.ToFile1_IWORK.Decimation % 1) &&
          (helikopter_task4_without_fee_DW.ToFile1_IWORK.Count*2)+1 < 100000000 )
      {
        FILE *fp = (FILE *)
          helikopter_task4_without_fee_DW.ToFile1_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          helikopter_task4_without_fee_DW.ToFile1_IWORK.Decimation = 0;
          u[0] = helikopter_task4_without_fee_M->Timing.t[1];
          u[1] = rtb_Gain1_g;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(helikopter_task4_without_fee_M,
                              "Error writing to MAT-file measured_pitch.mat");
            return;
          }

          if (((++helikopter_task4_without_fee_DW.ToFile1_IWORK.Count)*2)+1 >=
              100000000) {
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

  /* TransferFcn: '<S6>/Travel: Transfer Fcn' */
  rtb_Backgain = 0.0;
  rtb_Backgain += helikopter_task4_without_feed_P.TravelTransferFcn_C *
    helikopter_task4_without_feed_X.TravelTransferFcn_CSTATE;
  rtb_Backgain += helikopter_task4_without_feed_P.TravelTransferFcn_D *
    helikopter_task4_without_feed_B.TravelCounttorad;

  /* Gain: '<S14>/Gain' */
  helikopter_task4_without_feed_B.Gain_o =
    helikopter_task4_without_feed_P.Gain_Gain_n * rtb_Backgain;

  /* TransferFcn: '<S6>/Pitch: Transfer Fcn' */
  rtb_Backgain = 0.0;
  rtb_Backgain += helikopter_task4_without_feed_P.PitchTransferFcn_C *
    helikopter_task4_without_feed_X.PitchTransferFcn_CSTATE;
  rtb_Backgain += helikopter_task4_without_feed_P.PitchTransferFcn_D *
    helikopter_task4_without_feed_B.PitchCounttorad;

  /* Gain: '<S11>/Gain' */
  helikopter_task4_without_feed_B.Gain_i =
    helikopter_task4_without_feed_P.Gain_Gain_g * rtb_Backgain;

  /* TransferFcn: '<S6>/Elevation: Transfer Fcn' */
  rtb_Backgain = 0.0;
  rtb_Backgain += helikopter_task4_without_feed_P.ElevationTransferFcn_C *
    helikopter_task4_without_feed_X.ElevationTransferFcn_CSTATE;
  rtb_Backgain += helikopter_task4_without_feed_P.ElevationTransferFcn_D *
    helikopter_task4_without_feed_B.ElevationCounttorad;

  /* Gain: '<S9>/Gain' */
  helikopter_task4_without_feed_B.Gain_f =
    helikopter_task4_without_feed_P.Gain_Gain_a * rtb_Backgain;

  /* Gain: '<S2>/Gain1' */
  rtb_Gain1[4] = helikopter_task4_without_feed_P.Gain1_Gain_c *
    helikopter_task4_without_feed_B.Sum;
  rtb_Gain1[5] = helikopter_task4_without_feed_P.Gain1_Gain_c *
    helikopter_task4_without_feed_B.Gain_f;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Vd_bias'
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S7>/K_pd'
   *  Gain: '<S7>/K_pp'
   *  Sum: '<S7>/Sum2'
   *  Sum: '<S7>/Sum3'
   */
  helikopter_task4_without_feed_B.Sum1 = ((helikopter_task4_without_feed_B.Sum4
    [0] - helikopter_task4_without_feed_P.Gain1_Gain_c *
    helikopter_task4_without_feed_B.Gain_n) *
    helikopter_task4_without_feed_P.K_pp -
    helikopter_task4_without_feed_P.Gain1_Gain_c *
    helikopter_task4_without_feed_B.Gain_i *
    helikopter_task4_without_feed_P.K_pd) +
    helikopter_task4_without_feed_P.Vd_ff;
  if (rtmIsMajorTimeStep(helikopter_task4_without_fee_M)) {
  }

  /* Integrator: '<S5>/Integrator'
   *
   * Regarding '<S5>/Integrator':
   *  Limited Integrator
   */
  if (helikopter_task4_without_feed_X.Integrator_CSTATE >=
      helikopter_task4_without_feed_P.Integrator_UpperSat ) {
    helikopter_task4_without_feed_X.Integrator_CSTATE =
      helikopter_task4_without_feed_P.Integrator_UpperSat;
  } else if (helikopter_task4_without_feed_X.Integrator_CSTATE <=
             (helikopter_task4_without_feed_P.Integrator_LowerSat) ) {
    helikopter_task4_without_feed_X.Integrator_CSTATE =
      (helikopter_task4_without_feed_P.Integrator_LowerSat);
  }

  rtb_Backgain = helikopter_task4_without_feed_X.Integrator_CSTATE;

  /* Sum: '<S5>/Sum' */
  rtb_Derivative = helikopter_task4_without_feed_B.Sum4[1] - rtb_Gain1[4];

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Vs_bias'
   *  Gain: '<S5>/K_ed'
   *  Gain: '<S5>/K_ep'
   *  Sum: '<S5>/Sum1'
   */
  helikopter_task4_without_feed_B.Sum2 = ((helikopter_task4_without_feed_P.K_ep *
    rtb_Derivative + rtb_Backgain) - helikopter_task4_without_feed_P.K_ed *
    rtb_Gain1[5]) + helikopter_task4_without_feed_P.Vs_ff;
  if (rtmIsMajorTimeStep(helikopter_task4_without_fee_M)) {
  }

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  rtb_Backgain = (helikopter_task4_without_feed_B.Sum2 -
                  helikopter_task4_without_feed_B.Sum1) *
    helikopter_task4_without_feed_P.Backgain_Gain;

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  rtb_Frontgain = (helikopter_task4_without_feed_B.Sum1 +
                   helikopter_task4_without_feed_B.Sum2) *
    helikopter_task4_without_feed_P.Frontgain_Gain;

  /* Gain: '<S5>/K_ei' */
  helikopter_task4_without_feed_B.K_ei = helikopter_task4_without_feed_P.K_ei *
    rtb_Derivative;
  if (rtmIsMajorTimeStep(helikopter_task4_without_fee_M)) {
  }

  /* Derivative: '<S6>/Derivative' */
  if ((helikopter_task4_without_fee_DW.TimeStampA >=
       helikopter_task4_without_fee_M->Timing.t[0]) &&
      (helikopter_task4_without_fee_DW.TimeStampB >=
       helikopter_task4_without_fee_M->Timing.t[0])) {
    rtb_Derivative = 0.0;
  } else {
    lastTime = helikopter_task4_without_fee_DW.TimeStampA;
    lastU = &helikopter_task4_without_fee_DW.LastUAtTimeA;
    if (helikopter_task4_without_fee_DW.TimeStampA <
        helikopter_task4_without_fee_DW.TimeStampB) {
      if (helikopter_task4_without_fee_DW.TimeStampB <
          helikopter_task4_without_fee_M->Timing.t[0]) {
        lastTime = helikopter_task4_without_fee_DW.TimeStampB;
        lastU = &helikopter_task4_without_fee_DW.LastUAtTimeB;
      }
    } else {
      if (helikopter_task4_without_fee_DW.TimeStampA >=
          helikopter_task4_without_fee_M->Timing.t[0]) {
        lastTime = helikopter_task4_without_fee_DW.TimeStampB;
        lastU = &helikopter_task4_without_fee_DW.LastUAtTimeB;
      }
    }

    rtb_Derivative = (helikopter_task4_without_feed_B.PitchCounttorad - *lastU) /
      (helikopter_task4_without_fee_M->Timing.t[0] - lastTime);
  }

  /* End of Derivative: '<S6>/Derivative' */

  /* Gain: '<S12>/Gain' */
  helikopter_task4_without_feed_B.Gain_m =
    helikopter_task4_without_feed_P.Gain_Gain_e * rtb_Derivative;
  if (rtmIsMajorTimeStep(helikopter_task4_without_fee_M)) {
  }

  /* Saturate: '<S6>/Back motor: Saturation' */
  if (rtb_Backgain >
      helikopter_task4_without_feed_P.BackmotorSaturation_UpperSat) {
    helikopter_task4_without_feed_B.BackmotorSaturation =
      helikopter_task4_without_feed_P.BackmotorSaturation_UpperSat;
  } else if (rtb_Backgain <
             helikopter_task4_without_feed_P.BackmotorSaturation_LowerSat) {
    helikopter_task4_without_feed_B.BackmotorSaturation =
      helikopter_task4_without_feed_P.BackmotorSaturation_LowerSat;
  } else {
    helikopter_task4_without_feed_B.BackmotorSaturation = rtb_Backgain;
  }

  /* End of Saturate: '<S6>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(helikopter_task4_without_fee_M)) {
  }

  /* Saturate: '<S6>/Front motor: Saturation' */
  if (rtb_Frontgain >
      helikopter_task4_without_feed_P.FrontmotorSaturation_UpperSat) {
    helikopter_task4_without_feed_B.FrontmotorSaturation =
      helikopter_task4_without_feed_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Frontgain <
             helikopter_task4_without_feed_P.FrontmotorSaturation_LowerSat) {
    helikopter_task4_without_feed_B.FrontmotorSaturation =
      helikopter_task4_without_feed_P.FrontmotorSaturation_LowerSat;
  } else {
    helikopter_task4_without_feed_B.FrontmotorSaturation = rtb_Frontgain;
  }

  /* End of Saturate: '<S6>/Front motor: Saturation' */
  if (rtmIsMajorTimeStep(helikopter_task4_without_fee_M)) {
    /* S-Function (hil_write_analog_block): '<S6>/HIL Write Analog' */

    /* S-Function Block: helikopter_task4_without_feed/Helicopter_interface/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      helikopter_task4_without_fee_DW.HILWriteAnalog_Buffer[0] =
        helikopter_task4_without_feed_B.FrontmotorSaturation;
      helikopter_task4_without_fee_DW.HILWriteAnalog_Buffer[1] =
        helikopter_task4_without_feed_B.BackmotorSaturation;
      result = hil_write_analog
        (helikopter_task4_without_fee_DW.HILInitialize_Card,
         helikopter_task4_without_feed_P.HILWriteAnalog_channels, 2,
         &helikopter_task4_without_fee_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
      }
    }
  }

  /* Clock: '<Root>/Clock' */
  helikopter_task4_without_feed_B.Clock =
    helikopter_task4_without_fee_M->Timing.t[0];
  if (rtmIsMajorTimeStep(helikopter_task4_without_fee_M)) {
    /* ToFile: '<Root>/To File2' */
    {
      if (!(++helikopter_task4_without_fee_DW.ToFile2_IWORK.Decimation % 1) &&
          (helikopter_task4_without_fee_DW.ToFile2_IWORK.Count*2)+1 < 100000000 )
      {
        FILE *fp = (FILE *)
          helikopter_task4_without_fee_DW.ToFile2_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[2];
          helikopter_task4_without_fee_DW.ToFile2_IWORK.Decimation = 0;
          u[0] = helikopter_task4_without_fee_M->Timing.t[1];
          u[1] = helikopter_task4_without_feed_B.Clock;
          if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
            rtmSetErrorStatus(helikopter_task4_without_fee_M,
                              "Error writing to MAT-file measured_time.mat");
            return;
          }

          if (((++helikopter_task4_without_fee_DW.ToFile2_IWORK.Count)*2)+1 >=
              100000000) {
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
}

/* Model update function */
void helikopter_task4_without_feed_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<S6>/Derivative' */
  if (helikopter_task4_without_fee_DW.TimeStampA == (rtInf)) {
    helikopter_task4_without_fee_DW.TimeStampA =
      helikopter_task4_without_fee_M->Timing.t[0];
    lastU = &helikopter_task4_without_fee_DW.LastUAtTimeA;
  } else if (helikopter_task4_without_fee_DW.TimeStampB == (rtInf)) {
    helikopter_task4_without_fee_DW.TimeStampB =
      helikopter_task4_without_fee_M->Timing.t[0];
    lastU = &helikopter_task4_without_fee_DW.LastUAtTimeB;
  } else if (helikopter_task4_without_fee_DW.TimeStampA <
             helikopter_task4_without_fee_DW.TimeStampB) {
    helikopter_task4_without_fee_DW.TimeStampA =
      helikopter_task4_without_fee_M->Timing.t[0];
    lastU = &helikopter_task4_without_fee_DW.LastUAtTimeA;
  } else {
    helikopter_task4_without_fee_DW.TimeStampB =
      helikopter_task4_without_fee_M->Timing.t[0];
    lastU = &helikopter_task4_without_fee_DW.LastUAtTimeB;
  }

  *lastU = helikopter_task4_without_feed_B.PitchCounttorad;

  /* End of Update for Derivative: '<S6>/Derivative' */
  if (rtmIsMajorTimeStep(helikopter_task4_without_fee_M)) {
    rt_ertODEUpdateContinuousStates(&helikopter_task4_without_fee_M->solverInfo);
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
  if (!(++helikopter_task4_without_fee_M->Timing.clockTick0)) {
    ++helikopter_task4_without_fee_M->Timing.clockTickH0;
  }

  helikopter_task4_without_fee_M->Timing.t[0] = rtsiGetSolverStopTime
    (&helikopter_task4_without_fee_M->solverInfo);

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
    if (!(++helikopter_task4_without_fee_M->Timing.clockTick1)) {
      ++helikopter_task4_without_fee_M->Timing.clockTickH1;
    }

    helikopter_task4_without_fee_M->Timing.t[1] =
      helikopter_task4_without_fee_M->Timing.clockTick1 *
      helikopter_task4_without_fee_M->Timing.stepSize1 +
      helikopter_task4_without_fee_M->Timing.clockTickH1 *
      helikopter_task4_without_fee_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void helikopter_task4_without_feed_derivatives(void)
{
  XDot_helikopter_task4_without_T *_rtXdot;
  _rtXdot = ((XDot_helikopter_task4_without_T *)
             helikopter_task4_without_fee_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S6>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE +=
    helikopter_task4_without_feed_P.TravelTransferFcn_A *
    helikopter_task4_without_feed_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE +=
    helikopter_task4_without_feed_B.TravelCounttorad;

  /* Derivatives for TransferFcn: '<S6>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE +=
    helikopter_task4_without_feed_P.PitchTransferFcn_A *
    helikopter_task4_without_feed_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE +=
    helikopter_task4_without_feed_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S6>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    helikopter_task4_without_feed_P.ElevationTransferFcn_A *
    helikopter_task4_without_feed_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    helikopter_task4_without_feed_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( helikopter_task4_without_feed_X.Integrator_CSTATE <=
            (helikopter_task4_without_feed_P.Integrator_LowerSat) );
    usat = ( helikopter_task4_without_feed_X.Integrator_CSTATE >=
            helikopter_task4_without_feed_P.Integrator_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (helikopter_task4_without_feed_B.K_ei > 0)) ||
        (usat && (helikopter_task4_without_feed_B.K_ei < 0)) ) {
      ((XDot_helikopter_task4_without_T *)
        helikopter_task4_without_fee_M->ModelData.derivs)->Integrator_CSTATE =
        helikopter_task4_without_feed_B.K_ei;
    } else {
      /* in saturation */
      ((XDot_helikopter_task4_without_T *)
        helikopter_task4_without_fee_M->ModelData.derivs)->Integrator_CSTATE =
        0.0;
    }
  }
}

/* Model initialize function */
void helikopter_task4_without_feed_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helikopter_task4_without_feed/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0",
                      &helikopter_task4_without_fee_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (helikopter_task4_without_fee_DW.HILInitialize_Card,
       "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (helikopter_task4_without_fee_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
      return;
    }

    if ((helikopter_task4_without_feed_P.HILInitialize_set_analog_input_ &&
         !is_switching) ||
        (helikopter_task4_without_feed_P.HILInitialize_set_analog_inpu_e &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &helikopter_task4_without_fee_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] =
            helikopter_task4_without_feed_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &helikopter_task4_without_fee_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] =
            helikopter_task4_without_feed_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges
        (helikopter_task4_without_fee_DW.HILInitialize_Card,
         helikopter_task4_without_feed_P.HILInitialize_analog_input_chan, 8U,
         &helikopter_task4_without_fee_DW.HILInitialize_AIMinimums[0],
         &helikopter_task4_without_fee_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task4_without_feed_P.HILInitialize_set_analog_output &&
         !is_switching) ||
        (helikopter_task4_without_feed_P.HILInitialize_set_analog_outp_o &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums =
          &helikopter_task4_without_fee_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] =
            helikopter_task4_without_feed_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums =
          &helikopter_task4_without_fee_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] =
            helikopter_task4_without_feed_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges
        (helikopter_task4_without_fee_DW.HILInitialize_Card,
         helikopter_task4_without_feed_P.HILInitialize_analog_output_cha, 8U,
         &helikopter_task4_without_fee_DW.HILInitialize_AOMinimums[0],
         &helikopter_task4_without_fee_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task4_without_feed_P.HILInitialize_set_analog_outp_e &&
         !is_switching) ||
        (helikopter_task4_without_feed_P.HILInitialize_set_analog_outp_c &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &helikopter_task4_without_fee_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            helikopter_task4_without_feed_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog
        (helikopter_task4_without_fee_DW.HILInitialize_Card,
         helikopter_task4_without_feed_P.HILInitialize_analog_output_cha, 8U,
         &helikopter_task4_without_fee_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
        return;
      }
    }

    if (helikopter_task4_without_feed_P.HILInitialize_set_analog_outp_b) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &helikopter_task4_without_fee_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            helikopter_task4_without_feed_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (helikopter_task4_without_fee_DW.HILInitialize_Card,
         helikopter_task4_without_feed_P.HILInitialize_analog_output_cha, 8U,
         &helikopter_task4_without_fee_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task4_without_feed_P.HILInitialize_set_encoder_param &&
         !is_switching) ||
        (helikopter_task4_without_feed_P.HILInitialize_set_encoder_par_e &&
         is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &helikopter_task4_without_fee_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            helikopter_task4_without_feed_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (helikopter_task4_without_fee_DW.HILInitialize_Card,
         helikopter_task4_without_feed_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &helikopter_task4_without_fee_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task4_without_feed_P.HILInitialize_set_encoder_count &&
         !is_switching) ||
        (helikopter_task4_without_feed_P.HILInitialize_set_encoder_cou_p &&
         is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &helikopter_task4_without_fee_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            helikopter_task4_without_feed_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts
        (helikopter_task4_without_fee_DW.HILInitialize_Card,
         helikopter_task4_without_feed_P.HILInitialize_encoder_channels, 8U,
         &helikopter_task4_without_fee_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task4_without_feed_P.HILInitialize_set_pwm_params_at &&
         !is_switching) ||
        (helikopter_task4_without_feed_P.HILInitialize_set_pwm_params__p &&
         is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &helikopter_task4_without_fee_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            helikopter_task4_without_feed_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode
        (helikopter_task4_without_fee_DW.HILInitialize_Card,
         helikopter_task4_without_feed_P.HILInitialize_pwm_channels, 8U,
         (t_pwm_mode *)
         &helikopter_task4_without_fee_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          helikopter_task4_without_feed_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues =
          &helikopter_task4_without_fee_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            helikopter_task4_without_fee_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = p_HILInitialize_pwm_channels[i1];
            helikopter_task4_without_fee_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = helikopter_task4_without_feed_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            helikopter_task4_without_fee_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = p_HILInitialize_pwm_channels[i1];
            helikopter_task4_without_fee_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              helikopter_task4_without_feed_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency
          (helikopter_task4_without_fee_DW.HILInitialize_Card,
           &helikopter_task4_without_fee_DW.HILInitialize_POSortedChans[0],
           num_duty_cycle_modes,
           &helikopter_task4_without_fee_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (helikopter_task4_without_fee_DW.HILInitialize_Card,
           &helikopter_task4_without_fee_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
           num_frequency_modes,
           &helikopter_task4_without_fee_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &helikopter_task4_without_fee_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            helikopter_task4_without_feed_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &helikopter_task4_without_fee_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] =
            helikopter_task4_without_feed_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &helikopter_task4_without_fee_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] =
            helikopter_task4_without_feed_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration
        (helikopter_task4_without_fee_DW.HILInitialize_Card,
         helikopter_task4_without_feed_P.HILInitialize_pwm_channels, 8U,
         (t_pwm_configuration *)
         &helikopter_task4_without_fee_DW.HILInitialize_POModeValues[0],
         (t_pwm_alignment *)
         &helikopter_task4_without_fee_DW.HILInitialize_POAlignValues[0],
         (t_pwm_polarity *)
         &helikopter_task4_without_fee_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &helikopter_task4_without_fee_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] =
            helikopter_task4_without_feed_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues =
          &helikopter_task4_without_fee_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            helikopter_task4_without_feed_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband
        (helikopter_task4_without_fee_DW.HILInitialize_Card,
         helikopter_task4_without_feed_P.HILInitialize_pwm_channels, 8U,
         &helikopter_task4_without_fee_DW.HILInitialize_POSortedFreqs[0],
         &helikopter_task4_without_fee_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
        return;
      }
    }

    if ((helikopter_task4_without_feed_P.HILInitialize_set_pwm_outputs_a &&
         !is_switching) ||
        (helikopter_task4_without_feed_P.HILInitialize_set_pwm_outputs_l &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues =
          &helikopter_task4_without_fee_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            helikopter_task4_without_feed_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(helikopter_task4_without_fee_DW.HILInitialize_Card,
        helikopter_task4_without_feed_P.HILInitialize_pwm_channels, 8U,
        &helikopter_task4_without_fee_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
        return;
      }
    }

    if (helikopter_task4_without_feed_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues =
          &helikopter_task4_without_fee_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            helikopter_task4_without_feed_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (helikopter_task4_without_fee_DW.HILInitialize_Card,
         helikopter_task4_without_feed_P.HILInitialize_pwm_channels, 8U,
         &helikopter_task4_without_fee_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S6>/HIL Read Encoder Timebase' */

  /* S-Function Block: helikopter_task4_without_feed/Helicopter_interface/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (helikopter_task4_without_fee_DW.HILInitialize_Card,
       helikopter_task4_without_feed_P.HILReadEncoderTimebase_samples_,
       helikopter_task4_without_feed_P.HILReadEncoderTimebase_channels, 3,
       &helikopter_task4_without_fee_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
    }
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
      0.004817705018478868, 0.013247638846626482, 0.024366495135859343,
      0.03746096013185498, 0.0519719789045678, 0.067451046242986784,
      0.083525048315376937, 0.099867143100106526, 0.11617109116591719,
      0.1321272778109604, 0.14739853272658282, 0.16159363368166801,
      0.17423675071071471, 0.1847302197623194, 0.1923077627256676,
      0.19768074241314862, 0.20138757318799203, 0.20383578754784568,
      0.20533381460159905, 0.20611506915872446, 0.20635624346226272,
      0.20619105487524875, 0.20572066168959088, 0.20502163987240377,
      0.20415194034102205, 0.20315541048725819, 0.20206521716132522,
      0.2009064479775802, 0.19969808680588358, 0.19845447062596594,
      0.19718644057911919, 0.19590218810770205, 0.19460790077755413,
      0.19330824365257751, 0.19200674598875359, 0.19070603087745663,
      0.18940809345910573, 0.18811441877622237, 0.18682613799629053, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0 } ;

    helikopter_task4_without_fee_DW.FromWorkspace6_PWORK.TimePtr = (void *)
      pTimeValues0;
    helikopter_task4_without_fee_DW.FromWorkspace6_PWORK.DataPtr = (void *)
      pDataValues0;
    helikopter_task4_without_fee_DW.FromWorkspace6_IWORK.PrevIndex = 0;
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
      2.9456562771175667, 2.8595077632935446, 2.7555515879651526,
      2.633505110490284, 2.4931956060320961, 2.334518576064299,
      2.1574113214711188, 1.9631882438910111, 1.7562585144291003,
      1.5432753191862381, 1.3312275860058411, 1.1257905467201614,
      0.93109280567204167, 0.74995907000935336, 0.5842476147810447,
      0.43514806862872762, 0.30340689485586869, 0.18948534043219339,
      0.093664971875101047, 0.015852756993180218, -0.044733660398241462,
      -0.0894837069486485, -0.12019297811756771, -0.13885765005650472,
      -0.14750450363121145, -0.1480655407668148, -0.14229407480747869,
      -0.13171543886585621, -0.11760509603619959, -0.10098780812842219,
      -0.082652657777828348, -0.063179733406762889, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task4_without_fee_DW.FromWorkspace2_PWORK.TimePtr = (void *)
      pTimeValues0;
    helikopter_task4_without_fee_DW.FromWorkspace2_PWORK.DataPtr = (void *)
      pDataValues0;
    helikopter_task4_without_fee_DW.FromWorkspace2_IWORK.PrevIndex = 0;
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
      -0.14672753935514371, -0.20869397118807925, -0.27519058110636674,
      -0.34459405529608839, -0.41582470131356869, -0.48818590989947469,
      -0.56123801783275185, -0.63470811987118858, -0.7084290183727211,
      -0.77689231032043, -0.8277189178476424, -0.85193278097144964,
      -0.84819093272158752, -0.82174815714271909, -0.77879096419247851,
      -0.72453494265075336, -0.662845820913235, -0.59639818460926808,
      -0.52696469509143551, -0.45568621769470125, -0.38328147422836939,
      -0.31124885952768333, -0.24234566956568671, -0.17900018620162822,
      -0.12283708467567682, -0.074658687755748063, -0.034587414298826925,
      -0.0022441485424134085, 0.023085863837344411, 0.042314543766489923,
      0.05644137131862647, 0.066469151631109544, 0.073340601402375361,
      0.077891697484261849, 0.080819284425536139, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task4_without_fee_DW.FromWorkspace3_PWORK.TimePtr = (void *)
      pTimeValues0;
    helikopter_task4_without_fee_DW.FromWorkspace3_PWORK.DataPtr = (void *)
      pDataValues0;
    helikopter_task4_without_fee_DW.FromWorkspace3_IWORK.PrevIndex = 0;
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
      0.38944360631144165, 0.43795507377677839, 0.46997264230390062,
      0.49051724877547076, 0.5034310014147434, 0.5114213858602934,
      0.51630439857701838, 0.519258621270637, 0.52103115488680807,
      0.48387239976634194, 0.35922305014135819, 0.17113433672279688,
      -0.026445954331339807, -0.18688743868177535, -0.30360503342337808,
      -0.38346083862313435, -0.43599515193353144, -0.46962651550204193,
      -0.49072938565100838, -0.50376905533539706, -0.51172907376816235,
      -0.50909900977719025, -0.4869814309240672, -0.44770168330697113,
      -0.39693935159354038, -0.34050650898216711, -0.28320845664422689,
      -0.22858984972252838, -0.17902285338055132, -0.13590096586008379,
      -0.099843021775209012, -0.070872521406608213, -0.048564782617169115,
      -0.032165408937559953, -0.020691066387531546, -0.013030626381427142, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task4_without_fee_DW.FromWorkspace4_PWORK.TimePtr = (void *)
      pTimeValues0;
    helikopter_task4_without_fee_DW.FromWorkspace4_PWORK.DataPtr = (void *)
      pDataValues0;
    helikopter_task4_without_fee_DW.FromWorkspace4_IWORK.PrevIndex = 0;
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
      0.28224853798014093, 0.19404586986134695, 0.128070274108489,
      0.082178425886280465, 0.051655010557090583, 0.031961537782199845,
      0.019532050866899832, 0.011816890774474309, 0.0070901344646845076,
      -0.14863502048186472, -0.498597398499935, -0.75235485367424526,
      -0.79032116421654675, -0.64176593740174215, -0.46687037896641104,
      -0.31942322079902513, -0.21013725324158833, -0.13452545427404208,
      -0.08441148059586577, -0.052158678737554628, -0.0318400737310607,
      0.010520255963888567, 0.088470315412492076, 0.15711899046838432,
      0.20304932685372304, 0.22573137044549296, 0.22919220935176102,
      0.21847442768679412, 0.19826798536790827, 0.17248755008187008,
      0.14423177633949913, 0.1158820014744032, 0.089230955157756364,
      0.06559749471843665, 0.045897370200113641, 0.030641760024417621,
      0.019823113717084707, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task4_without_fee_DW.FromWorkspace5_PWORK.TimePtr = (void *)
      pTimeValues0;
    helikopter_task4_without_fee_DW.FromWorkspace5_PWORK.DataPtr = (void *)
      pDataValues0;
    helikopter_task4_without_fee_DW.FromWorkspace5_IWORK.PrevIndex = 0;
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
      0.019270820073915472, 0.033719735312590454, 0.044475425156931453,
      0.052377859983982561, 0.058044075090851251, 0.061916269353675932,
      0.064296008289560627, 0.065368379138918367, 0.065215792263242714,
      0.063824746580172856, 0.061085019662489637, 0.056780403820340844,
      0.050572468116186722, 0.041973876206418806, 0.030310171853392791,
      0.021491918749924177, 0.014827323099373606, 0.0097928574394145554,
      0.0059921082150135611, 0.0031250182285016918, 0.00096469721415296937,
      -0.00066075434805590706, -0.0018815727426313811, -0.0027960872687484684,
      -0.0034787981255268038, -0.0039861194150555132, -0.0043607733037317742,
      -0.0046350767349801134, -0.0048334446867864672, -0.00497446471967058,
      -0.0050721201873869777, -0.00513700988566857, -0.00517714932059167,
      -0.0051986284999063718, -0.0052059906552957939, -0.0052028604451878537,
      -0.0051917496734035992, -0.0051746987315333219, -0.0051531231197274015,
      -0.0051282699830387073, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task4_without_fee_DW.FromWorkspace7_PWORK.TimePtr = (void *)
      pTimeValues0;
    helikopter_task4_without_fee_DW.FromWorkspace7_PWORK.DataPtr = (void *)
      pDataValues0;
    helikopter_task4_without_fee_DW.FromWorkspace7_IWORK.PrevIndex = 0;
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
      0.52359877559829882, 0.52359877559829882, 0.33488327074183061,
      -0.07617118641164683, -0.38340551853520338, -0.52359877559829882,
      -0.52359877559829882, -0.52359877559829882, -0.52359877559829882,
      -0.52359877559829882, -0.52359877559829882, -0.52359877559829882,
      -0.52359877559829882, -0.52359877559829882, -0.48685021170947779,
      -0.40380525918038063, -0.32604720863257897, -0.25570065585383922,
      -0.19408879718336539, -0.1418540771401926, -0.099080327807330074,
      -0.065405317632833262, -0.04011978608662807, -0.022253691243128964,
      -0.010643158649647646, -0.00398776867605341, -0.00090412732924894431,
      1.8124489258328961E-7, -2.4175740954424969E-6, -1.0198262439617919E-6,
      -1.0198262439617919E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task4_without_fee_DW.FromWorkspace_PWORK.TimePtr = (void *)
      pTimeValues0;
    helikopter_task4_without_fee_DW.FromWorkspace_PWORK.DataPtr = (void *)
      pDataValues0;
    helikopter_task4_without_fee_DW.FromWorkspace_IWORK.PrevIndex = 0;
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
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.30833312118264761,
      0.30826592411446163, 0.30748768772723217, 0.3057642446932074,
      0.30278929705065522, 0.29815695079541238, 0.29132579183197566,
      0.2815902335819741, 0.26800770025697862, 0.24933812786713663,
      0.22394706217857524, 0.18966457818814492, 0.14363404096501634,
      0.0820771996520298, -3.4195851726202291E-7, -3.147085994234217E-7,
      -5.2764732675533674E-7, 5.481972704888108E-7, 4.8331968552054255E-7,
      -8.8147670401425063E-7, 3.9617234717036318E-8, 6.20147075480069E-7,
      -1.138909757768392E-6, -1.3017029498741875E-6, -1.0493921531035634E-6,
      -7.7639358372040661E-7, -8.4075836310200724E-7, -9.35758481728478E-7,
      -3.3362200684947247E-7, -7.59674788333494E-7, -8.5685036588463364E-7,
      -8.64988372528103E-7, -6.8165182283402624E-7, -6.8064215072107248E-7,
      1.9134046746659182E-7, -1.0401524134043853E-6, -6.8882812957248114E-7,
      -9.7742975273140669E-7, 1.4513651560560537E-7, -1.2986619399864871E-7,
      -1.2986619399864871E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

    helikopter_task4_without_fee_DW.FromWorkspace1_PWORK.TimePtr = (void *)
      pTimeValues0;
    helikopter_task4_without_fee_DW.FromWorkspace1_PWORK.DataPtr = (void *)
      pDataValues0;
    helikopter_task4_without_fee_DW.FromWorkspace1_IWORK.PrevIndex = 0;
  }

  /* Start for ToFile: '<Root>/To File' */
  {
    char fileName[509] = "measured_travel.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(helikopter_task4_without_fee_M,
                        "Error creating .mat file measured_travel.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"measured_travel")) {
      rtmSetErrorStatus(helikopter_task4_without_fee_M,
                        "Error writing mat file header to file measured_travel.mat");
      return;
    }

    helikopter_task4_without_fee_DW.ToFile_IWORK.Count = 0;
    helikopter_task4_without_fee_DW.ToFile_IWORK.Decimation = -1;
    helikopter_task4_without_fee_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File1' */
  {
    char fileName[509] = "measured_pitch.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(helikopter_task4_without_fee_M,
                        "Error creating .mat file measured_pitch.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"measured_pitch")) {
      rtmSetErrorStatus(helikopter_task4_without_fee_M,
                        "Error writing mat file header to file measured_pitch.mat");
      return;
    }

    helikopter_task4_without_fee_DW.ToFile1_IWORK.Count = 0;
    helikopter_task4_without_fee_DW.ToFile1_IWORK.Decimation = -1;
    helikopter_task4_without_fee_DW.ToFile1_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File2' */
  {
    char fileName[509] = "measured_time.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(helikopter_task4_without_fee_M,
                        "Error creating .mat file measured_time.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"measured_time")) {
      rtmSetErrorStatus(helikopter_task4_without_fee_M,
                        "Error writing mat file header to file measured_time.mat");
      return;
    }

    helikopter_task4_without_fee_DW.ToFile2_IWORK.Count = 0;
    helikopter_task4_without_fee_DW.ToFile2_IWORK.Decimation = -1;
    helikopter_task4_without_fee_DW.ToFile2_PWORK.FilePtr = fp;
  }

  /* InitializeConditions for TransferFcn: '<S6>/Travel: Transfer Fcn' */
  helikopter_task4_without_feed_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S6>/Pitch: Transfer Fcn' */
  helikopter_task4_without_feed_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S6>/Elevation: Transfer Fcn' */
  helikopter_task4_without_feed_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  helikopter_task4_without_feed_X.Integrator_CSTATE =
    helikopter_task4_without_feed_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<S6>/Derivative' */
  helikopter_task4_without_fee_DW.TimeStampA = (rtInf);
  helikopter_task4_without_fee_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void helikopter_task4_without_feed_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: helikopter_task4_without_feed/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(helikopter_task4_without_fee_DW.HILInitialize_Card);
    hil_monitor_stop_all(helikopter_task4_without_fee_DW.HILInitialize_Card);
    is_switching = false;
    if ((helikopter_task4_without_feed_P.HILInitialize_set_analog_outp_a &&
         !is_switching) ||
        (helikopter_task4_without_feed_P.HILInitialize_set_analog_out_ct &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &helikopter_task4_without_fee_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            helikopter_task4_without_feed_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((helikopter_task4_without_feed_P.HILInitialize_set_pwm_outputs_b &&
         !is_switching) ||
        (helikopter_task4_without_feed_P.HILInitialize_set_pwm_outputs_j &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues =
          &helikopter_task4_without_fee_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            helikopter_task4_without_feed_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(helikopter_task4_without_fee_DW.HILInitialize_Card
                         ,
                         helikopter_task4_without_feed_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         ,
                         helikopter_task4_without_feed_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         ,
                         &helikopter_task4_without_fee_DW.HILInitialize_AOVoltages
                         [0]
                         ,
                         &helikopter_task4_without_fee_DW.HILInitialize_POValues[
                         0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (helikopter_task4_without_fee_DW.HILInitialize_Card,
             helikopter_task4_without_feed_P.HILInitialize_analog_output_cha,
             num_final_analog_outputs,
             &helikopter_task4_without_fee_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm
            (helikopter_task4_without_fee_DW.HILInitialize_Card,
             helikopter_task4_without_feed_P.HILInitialize_pwm_channels,
             num_final_pwm_outputs,
             &helikopter_task4_without_fee_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(helikopter_task4_without_fee_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(helikopter_task4_without_fee_DW.HILInitialize_Card);
    hil_monitor_delete_all(helikopter_task4_without_fee_DW.HILInitialize_Card);
    hil_close(helikopter_task4_without_fee_DW.HILInitialize_Card);
    helikopter_task4_without_fee_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) helikopter_task4_without_fee_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "measured_travel.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task4_without_fee_M,
                          "Error closing MAT-file measured_travel.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(helikopter_task4_without_fee_M,
                          "Error reopening MAT-file measured_travel.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2,
           helikopter_task4_without_fee_DW.ToFile_IWORK.Count, "measured_travel"))
      {
        rtmSetErrorStatus(helikopter_task4_without_fee_M,
                          "Error writing header for measured_travel to MAT-file measured_travel.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task4_without_fee_M,
                          "Error closing MAT-file measured_travel.mat");
        return;
      }

      helikopter_task4_without_fee_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (FILE *) helikopter_task4_without_fee_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "measured_pitch.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task4_without_fee_M,
                          "Error closing MAT-file measured_pitch.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(helikopter_task4_without_fee_M,
                          "Error reopening MAT-file measured_pitch.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2,
           helikopter_task4_without_fee_DW.ToFile1_IWORK.Count, "measured_pitch"))
      {
        rtmSetErrorStatus(helikopter_task4_without_fee_M,
                          "Error writing header for measured_pitch to MAT-file measured_pitch.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task4_without_fee_M,
                          "Error closing MAT-file measured_pitch.mat");
        return;
      }

      helikopter_task4_without_fee_DW.ToFile1_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File2' */
  {
    FILE *fp = (FILE *) helikopter_task4_without_fee_DW.ToFile2_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "measured_time.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task4_without_fee_M,
                          "Error closing MAT-file measured_time.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(helikopter_task4_without_fee_M,
                          "Error reopening MAT-file measured_time.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2,
           helikopter_task4_without_fee_DW.ToFile2_IWORK.Count, "measured_time"))
      {
        rtmSetErrorStatus(helikopter_task4_without_fee_M,
                          "Error writing header for measured_time to MAT-file measured_time.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(helikopter_task4_without_fee_M,
                          "Error closing MAT-file measured_time.mat");
        return;
      }

      helikopter_task4_without_fee_DW.ToFile2_PWORK.FilePtr = (NULL);
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
  helikopter_task4_without_feed_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  helikopter_task4_without_feed_update();
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
  helikopter_task4_without_feed_initialize();
}

void MdlTerminate(void)
{
  helikopter_task4_without_feed_terminate();
}

/* Registration function */
RT_MODEL_helikopter_task4_wit_T *helikopter_task4_without_feed(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  helikopter_task4_without_feed_P.Integrator_UpperSat = rtInf;
  helikopter_task4_without_feed_P.Integrator_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)helikopter_task4_without_fee_M, 0,
                sizeof(RT_MODEL_helikopter_task4_wit_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&helikopter_task4_without_fee_M->solverInfo,
                          &helikopter_task4_without_fee_M->Timing.simTimeStep);
    rtsiSetTPtr(&helikopter_task4_without_fee_M->solverInfo, &rtmGetTPtr
                (helikopter_task4_without_fee_M));
    rtsiSetStepSizePtr(&helikopter_task4_without_fee_M->solverInfo,
                       &helikopter_task4_without_fee_M->Timing.stepSize0);
    rtsiSetdXPtr(&helikopter_task4_without_fee_M->solverInfo,
                 &helikopter_task4_without_fee_M->ModelData.derivs);
    rtsiSetContStatesPtr(&helikopter_task4_without_fee_M->solverInfo, (real_T **)
                         &helikopter_task4_without_fee_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&helikopter_task4_without_fee_M->solverInfo,
      &helikopter_task4_without_fee_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&helikopter_task4_without_fee_M->solverInfo,
                          (&rtmGetErrorStatus(helikopter_task4_without_fee_M)));
    rtsiSetRTModelPtr(&helikopter_task4_without_fee_M->solverInfo,
                      helikopter_task4_without_fee_M);
  }

  rtsiSetSimTimeStep(&helikopter_task4_without_fee_M->solverInfo,
                     MAJOR_TIME_STEP);
  helikopter_task4_without_fee_M->ModelData.intgData.f[0] =
    helikopter_task4_without_fee_M->ModelData.odeF[0];
  helikopter_task4_without_fee_M->ModelData.contStates = ((real_T *)
    &helikopter_task4_without_feed_X);
  rtsiSetSolverData(&helikopter_task4_without_fee_M->solverInfo, (void *)
                    &helikopter_task4_without_fee_M->ModelData.intgData);
  rtsiSetSolverName(&helikopter_task4_without_fee_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      helikopter_task4_without_fee_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    helikopter_task4_without_fee_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    helikopter_task4_without_fee_M->Timing.sampleTimes =
      (&helikopter_task4_without_fee_M->Timing.sampleTimesArray[0]);
    helikopter_task4_without_fee_M->Timing.offsetTimes =
      (&helikopter_task4_without_fee_M->Timing.offsetTimesArray[0]);

    /* task periods */
    helikopter_task4_without_fee_M->Timing.sampleTimes[0] = (0.0);
    helikopter_task4_without_fee_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    helikopter_task4_without_fee_M->Timing.offsetTimes[0] = (0.0);
    helikopter_task4_without_fee_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(helikopter_task4_without_fee_M,
             &helikopter_task4_without_fee_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = helikopter_task4_without_fee_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    helikopter_task4_without_fee_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(helikopter_task4_without_fee_M, -1);
  helikopter_task4_without_fee_M->Timing.stepSize0 = 0.002;
  helikopter_task4_without_fee_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  helikopter_task4_without_fee_M->Sizes.checksums[0] = (49167358U);
  helikopter_task4_without_fee_M->Sizes.checksums[1] = (2357015147U);
  helikopter_task4_without_fee_M->Sizes.checksums[2] = (228520437U);
  helikopter_task4_without_fee_M->Sizes.checksums[3] = (2515151197U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    helikopter_task4_without_fee_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(helikopter_task4_without_fee_M->extModeInfo,
      &helikopter_task4_without_fee_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(helikopter_task4_without_fee_M->extModeInfo,
                        helikopter_task4_without_fee_M->Sizes.checksums);
    rteiSetTPtr(helikopter_task4_without_fee_M->extModeInfo, rtmGetTPtr
                (helikopter_task4_without_fee_M));
  }

  helikopter_task4_without_fee_M->solverInfoPtr =
    (&helikopter_task4_without_fee_M->solverInfo);
  helikopter_task4_without_fee_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&helikopter_task4_without_fee_M->solverInfo, 0.002);
  rtsiSetSolverMode(&helikopter_task4_without_fee_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  helikopter_task4_without_fee_M->ModelData.blockIO = ((void *)
    &helikopter_task4_without_feed_B);
  (void) memset(((void *) &helikopter_task4_without_feed_B), 0,
                sizeof(B_helikopter_task4_without_fe_T));

  /* parameters */
  helikopter_task4_without_fee_M->ModelData.defaultParam = ((real_T *)
    &helikopter_task4_without_feed_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &helikopter_task4_without_feed_X;
    helikopter_task4_without_fee_M->ModelData.contStates = (x);
    (void) memset((void *)&helikopter_task4_without_feed_X, 0,
                  sizeof(X_helikopter_task4_without_fe_T));
  }

  /* states (dwork) */
  helikopter_task4_without_fee_M->ModelData.dwork = ((void *)
    &helikopter_task4_without_fee_DW);
  (void) memset((void *)&helikopter_task4_without_fee_DW, 0,
                sizeof(DW_helikopter_task4_without_f_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    helikopter_task4_without_fee_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  helikopter_task4_without_fee_M->Sizes.numContStates = (4);/* Number of continuous states */
  helikopter_task4_without_fee_M->Sizes.numY = (0);/* Number of model outputs */
  helikopter_task4_without_fee_M->Sizes.numU = (0);/* Number of model inputs */
  helikopter_task4_without_fee_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  helikopter_task4_without_fee_M->Sizes.numSampTimes = (2);/* Number of sample times */
  helikopter_task4_without_fee_M->Sizes.numBlocks = (73);/* Number of blocks */
  helikopter_task4_without_fee_M->Sizes.numBlockIO = (20);/* Number of block outputs */
  helikopter_task4_without_fee_M->Sizes.numBlockPrms = (155);/* Sum of parameter "widths" */
  return helikopter_task4_without_fee_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
