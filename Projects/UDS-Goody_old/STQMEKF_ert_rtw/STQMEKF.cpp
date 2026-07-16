//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: STQMEKF.cpp
//
// Code generated for Simulink model 'STQMEKF'.
//
// Model version                  : 4.571
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Tue May 20 15:56:51 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "STQMEKF.h"
#include "rtwtypes.h"
#include "STQMEKF_types.h"
#include "STQMEKF_private.h"
#include <string.h>
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "coder_posix_time.h"
#include "rt_defines.h"

// Block signals (default storage)
B_STQMEKF_T STQMEKF_B;

// Block states (default storage)
DW_STQMEKF_T STQMEKF_DW;

// Real-time model
RT_MODEL_STQMEKF_T STQMEKF_M_ = RT_MODEL_STQMEKF_T();
RT_MODEL_STQMEKF_T *const STQMEKF_M = &STQMEKF_M_;

// Forward declaration for local functions
static real_T STQMEKF_xzlangeM(const real_T x[24]);
static void STQMEKF_xzlascl(real_T cfrom, real_T cto, real_T A[24]);
static real_T STQMEKF_xnrm2(int32_T n, const real_T x[24], int32_T ix0);
static real_T STQMEKF_xdotc(int32_T n, const real_T x[24], int32_T ix0, const
  real_T y[24], int32_T iy0);
static void STQMEKF_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[24],
  int32_T iy0);
static real_T STQMEKF_xdotc_o(const real_T x[9], const real_T y[9], int32_T iy0);
static void STQMEKF_xaxpy_gop(real_T a, real_T y[9], int32_T iy0);
static real_T STQMEKF_xnrm2_p(const real_T x[3], int32_T ix0);
static void STQMEKF_xaxpy_g(int32_T n, real_T a, const real_T x[24], int32_T ix0,
  real_T y[8], int32_T iy0);
static void STQMEKF_xaxpy_go(int32_T n, real_T a, const real_T x[8], int32_T ix0,
  real_T y[24], int32_T iy0);
static void STQMEKF_xzlascl_i(real_T cfrom, real_T cto, real_T A[3]);
static void STQMEKF_xrotg(real_T a, real_T b, real_T *b_a, real_T *b_b, real_T
  *c, real_T *s);
static void STQMEKF_xrot_ps(real_T x[9], int32_T ix0, int32_T iy0, real_T c,
  real_T s);
static void STQMEKF_xrot_psj(real_T x[24], int32_T ix0, int32_T iy0, real_T c,
  real_T s);
static void STQMEKF_xswap_dj(real_T x[9], int32_T ix0, int32_T iy0);
static void STQMEKF_xswap_dj5(real_T x[24], int32_T ix0, int32_T iy0);
static void STQMEKF_svd(const real_T A[24], real_T U[24], real_T s[3], real_T V
  [9]);

// Forward declaration for local functions
static real_T STQMEKF_maximum(const real_T x[8]);

// Forward declaration for local functions
static real_T STQMEKF_norm(const real_T x[3]);
static real_T STQMEKF_norm_h(const real_T x[81]);
static void STQMEKF_mpower(const real_T a[81], real_T b, real_T c[81]);
static real_T STQMEKF_log2(real_T x);
static void STQMEKF_padeApproximation(const real_T A[81], const real_T A2[81],
  const real_T A4[81], const real_T A6[81], int32_T m, real_T F[81]);
static void STQMEKF_recomputeBlockDiag(const real_T A[81], real_T F[81], const
  int32_T blockFormat[8]);
static real_T STQMEKF_xnrm2_pp(int32_T n, const real_T x[81], int32_T ix0);
static void STQMEKF_xzsyhetrd(real_T A[81], real_T D[9], real_T E[8], real_T
  tau[8]);
static void STQMEKF_xzlascl_l(real_T cfrom, real_T cto, int32_T m, real_T A[9],
  int32_T iA0);
static void STQMEKF_xzlascl_lr(real_T cfrom, real_T cto, int32_T m, real_T A[8],
  int32_T iA0);
static void STQMEKF_xzlartg(real_T f, real_T g, real_T *cs, real_T *sn, real_T
  *r);
static void STQMEKF_rotateRight_b(int32_T n, real_T z[81], int32_T iz0, const
  real_T cs[16], int32_T ic0, int32_T is0);
static void STQMEKF_xdlaev2(real_T a, real_T b, real_T c, real_T *rt1, real_T
  *rt2, real_T *cs1, real_T *sn1);
static void STQMEKF_rotateRight(int32_T n, real_T z[81], int32_T iz0, const
  real_T cs[16], int32_T ic0, int32_T is0);
static int32_T STQMEKF_xzsteqr(real_T d[9], real_T e[8], real_T z[81]);
static void STQMEKF_xsyheev(real_T A[81], int32_T *info, real_T W[9]);
static void STQMEKF_prop(const real_T x[13], real_T dt, real_T x_new[13], real_T
  F[144], real_T G[72]);
static void STQMEKF_smallQuat(const real_T q[4], real_T p[4]);
static void STQMEKF_xzgetrf(real_T A[36], int32_T ipiv[6], int32_T *info);
static boolean_T STQMEKF_hasFiniteBounds(boolean_T hasLB[12], boolean_T hasUB[12]);
static void STQMEKF_QMEKF_anonFcn1(const real_T P[144], const real_T H[72],
  const real_T R[36], const real_T V[36], const real_T x[12], real_T
  varargout_1[36]);
static void STQMEKF_finDiffEvalAndChkErr(const real_T
  obj_nonlin_workspace_fun_worksp[144], const real_T
  obj_nonlin_workspace_fun_work_0[72], const real_T
  obj_nonlin_workspace_fun_work_1[36], int32_T dim, real_T delta, real_T xk[12],
  boolean_T *evalOK, real_T *fplus, real_T cEqPlus[36]);
static boolean_T STQMEK_computeFiniteDifferences(s_nQKPRbEKofXRewaeXLaVf_STQME_T
  *obj, const real_T cEqCurrent[36], real_T xk[12], real_T JacCeqTrans[432]);
static real_T STQMEKF_computeFirstOrderOpt(const real_T gradf[12], boolean_T
  hasFiniteBounds, const real_T *projSteepestDescentInfNorm);
static real_T STQMEKF_norm_hm(const real_T x[12]);
static int32_T STQMEKF_checkStoppingCriteria(const real_T gradf[12], real_T
  relFactor, const real_T x[12], int32_T funcCount, real_T
  projSteepestDescentInfNorm, boolean_T hasFiniteBounds);
static real_T STQMEKF_xnrm2_ppp(int32_T n, const real_T x[576], int32_T ix0);
static real_T STQMEKF_xzlarfg(int32_T n, real_T *alpha1, real_T x[576], int32_T
  ix0);
static void STQMEKF_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T
  C[576], int32_T ic0, real_T work[12]);
static void STQMEKF_linearLeastSquares(real_T lhs[576], real_T rhs[48], real_T
  dx[12]);
static int32_T STQMEKF_checkStoppingCriteria_h(const real_T gradf[12], real_T
  relFactor, real_T funDiff, const real_T x[12], const real_T dx[12], int32_T
  funcCount, boolean_T stepSuccessful, int32_T *iter, real_T
  projSteepestDescentInfNorm, boolean_T hasFiniteBounds);
static void STQMEKF_lsqnonlin(const real_T fun_workspace_P[144], const real_T
  fun_workspace_H[72], const real_T fun_workspace_V[36], real_T xCurrent[12]);
static real_T STQMEKF_xnrm2_j(int32_T n, const real_T x[153], int32_T ix0);
static real_T STQMEKF_xzlarfg_a(int32_T n, real_T *alpha1, real_T x[153],
  int32_T ix0);
static void STQMEKF_xzlarf_p(int32_T m, int32_T n, int32_T iv0, real_T tau,
  real_T C[153], int32_T ic0, real_T work[17]);
static void STQMEKF_qrf(real_T A[153], int32_T m, int32_T n, int32_T nfxd,
  real_T tau[9]);
static void STQMEKF_xgeqp3(real_T A[153], int32_T m, int32_T n, int32_T jpvt[17],
  real_T tau[9]);
static void STQMEKF_countsort(int32_T x[17], int32_T xLen, int32_T workspace[17],
  int32_T xMin, int32_T xMax);
static void STQMEKF_removeConstr(srnx7tMxlsAQ9dn31gXFrqF_STQME_T *obj, int32_T
  idx_global);
static void STQMEKF_RemoveDependentIneq_(srnx7tMxlsAQ9dn31gXFrqF_STQME_T
  *workingset, sTj3C1mXm6Z2qP847mPxR8C_STQME_T *qrmanager,
  sLLWTJNyuJQrAxk3RwmbzBG_STQME_T *memspace, real_T tolfactor);
static void STQMEKF_computeQ_(sTj3C1mXm6Z2qP847mPxR8C_STQME_T *obj, int32_T
  nrows);
static int32_T STQMEKF_rank(const real_T qrmanager_QR[153], int32_T
  qrmanager_mrows, int32_T qrmanager_ncols);
static real_T STQMEKF_maxConstraintViolation(const
  srnx7tMxlsAQ9dn31gXFrqF_STQME_T *obj, const real_T x[153], int32_T ix0);
static boolean_T STQMEKF_feasibleX0ForWorkingSet(real_T workspace[153], real_T
  xCurrent[9], const srnx7tMxlsAQ9dn31gXFrqF_STQME_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_STQME_T *qrmanager);
static real_T STQMEK_maxConstraintViolation_b(const
  srnx7tMxlsAQ9dn31gXFrqF_STQME_T *obj, const real_T x[9]);
static void STQMEKF_setProblemType(srnx7tMxlsAQ9dn31gXFrqF_STQME_T *obj, int32_T
  PROBLEM_TYPE);
static void STQMEKF_xgemv(int32_T m, int32_T n, const real_T A[64], int32_T lda,
  const real_T x[9], real_T y[8]);
static void STQMEKF_computeGrad_StoreHx(s87IldPMN2ICa85Nu8z6UL_STQMEK_T *obj,
  const real_T H[64], const real_T f[8], const real_T x[9]);
static real_T STQMEKF_computeFval_ReuseHx(const s87IldPMN2ICa85Nu8z6UL_STQMEK_T *
  obj, real_T workspace[153], const real_T f[8], const real_T x[9]);
static void STQMEKF_factorQR(sTj3C1mXm6Z2qP847mPxR8C_STQME_T *obj, const real_T
  A[153], int32_T mrows, int32_T ncols);
static void STQMEKF_xrotg_j(real_T *a, real_T *b, real_T *c, real_T *s);
static void STQMEKF_squareQ_appendCol(sTj3C1mXm6Z2qP847mPxR8C_STQME_T *obj,
  const real_T vec[153], int32_T iv0);
static void STQMEKF_deleteColMoveEnd(sTj3C1mXm6Z2qP847mPxR8C_STQME_T *obj,
  int32_T idx);
static void STQMEKF_fullColLDL2_(smSS6fEwaptVbzYAOdOZgjB_STQME_T *obj, int32_T
  NColsRemain, real_T REG_PRIMAL);
static void STQMEKF_xgemv_k(int32_T m, int32_T n, const real_T A[81], int32_T
  ia0, const real_T x[153], real_T y[9]);
static void STQMEKF_compute_deltax(const real_T H[64],
  sraTyWZlTzdIJhNDrRZT2SF_STQME_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_STQME_T
  *memspace, const sTj3C1mXm6Z2qP847mPxR8C_STQME_T *qrmanager,
  smSS6fEwaptVbzYAOdOZgjB_STQME_T *cholmanager, const
  s87IldPMN2ICa85Nu8z6UL_STQMEK_T *objective);
static real_T STQMEKF_xnrm2_jd(int32_T n, const real_T x[9]);
static void STQMEKF_feasibleratiotest(const real_T solution_xstar[9], const
  real_T solution_searchDir[9], int32_T workingset_nVar, const real_T
  workingset_lb[9], const int32_T workingset_indexLB[9], const int32_T
  workingset_indexUB[9], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[17],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx);
static void STQM_addBoundToActiveSetMatrix_(srnx7tMxlsAQ9dn31gXFrqF_STQME_T *obj,
  int32_T TYPE, int32_T idx_local);
static void STQMEKF_addAineqConstr(const srnx7tMxlsAQ9dn31gXFrqF_STQME_T *obj);
static void STQMEKF_compute_lambda(real_T workspace[153],
  sraTyWZlTzdIJhNDrRZT2SF_STQME_T *solution, const
  s87IldPMN2ICa85Nu8z6UL_STQMEK_T *objective, const
  sTj3C1mXm6Z2qP847mPxR8C_STQME_T *qrmanager);
static void STQMEKF_phaseone(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_STQME_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_STQME_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_STQME_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_STQME_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_STQME_T
  *cholmanager, const sIOJhD9KwAkF5sEguPjYquC_STQME_T *runTimeOptions,
  s87IldPMN2ICa85Nu8z6UL_STQMEK_T *objective);
static int32_T STQMEKF_RemoveDependentEq_(sLLWTJNyuJQrAxk3RwmbzBG_STQME_T
  *memspace, const srnx7tMxlsAQ9dn31gXFrqF_STQME_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_STQME_T *qrmanager);
static void STQMEKF_ratiotest(const real_T solution_xstar[9], const real_T
  solution_searchDir[9], int32_T workingset_nVar, const real_T workingset_lb[9],
  const int32_T workingset_indexLB[9], const int32_T workingset_indexUB[9],
  const int32_T workingset_sizes[5], const int32_T workingset_isActiveIdx[6],
  const boolean_T workingset_isActiveConstr[17], const int32_T
  workingset_nWConstr[5], real_T *toldelta, real_T *alpha, boolean_T
  *newBlocking, int32_T *constrType, int32_T *constrIdx);
static void STQMEKF_iterate(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_STQME_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_STQME_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_STQME_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_STQME_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_STQME_T
  *cholmanager, s87IldPMN2ICa85Nu8z6UL_STQMEK_T *objective, boolean_T
  runTimeOptions_RemainFeasible, real_T runTimeOptions_ProbRelTolFactor);
static void STQMEKF_computeFirstOrderOpt_m(sraTyWZlTzdIJhNDrRZT2SF_STQME_T
  *solution, const s87IldPMN2ICa85Nu8z6UL_STQMEK_T *objective, int32_T
  workingset_nVar, const real_T workingset_ATwset[153], int32_T
  workingset_nActiveConstr, real_T workspace[153]);
static void STQMEKF_phaseone_o(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_STQME_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_STQME_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_STQME_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_STQME_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_STQME_T
  *cholmanager, s87IldPMN2ICa85Nu8z6UL_STQMEK_T *objective, const
  sIOJhD9KwAkF5sEguPjYquC_STQME_T *runTimeOptions);
static void STQMEKF_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
  real_T workspace[153], const real_T H[64], const real_T f[8], const real_T x[9]);
static real_T STQMEKF_computeFval(const s87IldPMN2ICa85Nu8z6UL_STQMEK_T *obj,
  real_T workspace[153], const real_T H[64], const real_T f[8], const real_T x[9]);
static void STQMEKF_quadprog(const real_T H[64], const real_T f[8], const real_T
  x0[8], real_T x[8], real_T *fval, real_T *exitflag);
static real_T STQMEKF_maximum_i(const real_T x[8]);
static void STQMEKF_pause(real_T varargin_1);
static void S_bmi160_set_EnableSecondaryMag(b_bmi160_STQMEKF_T *obj);
static void STQMEKF_SystemCore_setup(nvidiacoder_sensors_BMI160Blo_T *obj);
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

//
// Output and update for action system:
//    '<S1>/Phase #0: Synchronization'
//    '<S1>/Phase #1: Start Floating '
//
void STQMEKF_Phase0Synchronization(real_T *rtd_ARM_Control_Law_Enabler, real_T
  *rtd_ARM_Path_Planner_Selection, real_T *rtd_BLACK_Control_Law_Enabler, real_T
  *rtd_BLACK_Path_Planner_Selectio, real_T *rtd_BLUE_Control_Law_Enabler, real_T
  *rtd_BLUE_Path_Planner_Selection, real_T *rtd_Float_State, real_T
  *rtd_RED_Control_Law_Enabler, char_T rtd_RED_Logger[256], real_T
  *rtd_RED_Path_Planner_Selection, P_Phase0Synchronization_STQME_T *localP)
{
  // DataStoreWrite: '<S18>/Data Store Write2' incorporates:
  //   Constant: '<S18>/Constant1'

  *rtd_BLACK_Control_Law_Enabler = localP->Constant1_Value;

  // DataStoreWrite: '<S18>/Data Store Write3' incorporates:
  //   Constant: '<S18>/Constant2'

  *rtd_BLUE_Control_Law_Enabler = localP->Constant2_Value;

  // DataStoreWrite: '<S18>/Data Store Write7' incorporates:
  //   Constant: '<S18>/Constant3'

  *rtd_RED_Path_Planner_Selection = localP->Constant3_Value;

  // DataStoreWrite: '<S18>/Data Store Write8' incorporates:
  //   Constant: '<S18>/Constant4'

  *rtd_ARM_Path_Planner_Selection = localP->Constant4_Value;

  // DataStoreWrite: '<S18>/Data Store Write' incorporates:
  //   Constant: '<S18>/Constant5'

  *rtd_RED_Control_Law_Enabler = localP->Constant5_Value;

  // DataStoreWrite: '<S18>/Data Store Write6' incorporates:
  //   Constant: '<S18>/Constant6'

  *rtd_BLACK_Path_Planner_Selectio = localP->Constant6_Value;

  // DataStoreWrite: '<S18>/Data Store Write5' incorporates:
  //   Constant: '<S18>/Constant7'

  *rtd_BLUE_Path_Planner_Selection = localP->Constant7_Value;

  // DataStoreWrite: '<S18>/Data Store Write9' incorporates:
  //   Constant: '<S18>/Constant8'

  *rtd_ARM_Control_Law_Enabler = localP->Constant8_Value;

  // StringConstant: '<S18>/String Constant' incorporates:
  //   DataStoreWrite: '<S18>/Data Store Write1'

  strncpy(&rtd_RED_Logger[0], &localP->StringConstant_String[0], 255U);
  rtd_RED_Logger[255] = '\x00';

  // DataStoreWrite: '<S18>/Data Store Write4' incorporates:
  //   Constant: '<S18>/Puck State'

  *rtd_Float_State = localP->PuckState_Value;
}

//
// Output and update for action system:
//    '<S1>/Phase #4: Return Home'
//    '<S1>/Phase #5: Hold Home'
//
void STQMEKF_Phase4ReturnHome(real_T *rtd_ARM_Control_Law_Enabler, real_T
  rtd_ARM_Desired_States[3], real_T *rtd_ARM_Path_Planner_Selection, real_T
  *rtd_BLACK_Control_Law_Enabler, real_T rtd_BLACK_Desired_States[3], real_T
  *rtd_BLACK_Path_Planner_Selectio, real_T *rtd_BLUE_Control_Law_Enabler, real_T
  rtd_BLUE_Desired_States[3], real_T *rtd_BLUE_Path_Planner_Selection, real_T
  *rtd_Float_State, real_T *rtd_RED_Control_Law_Enabler, real_T
  rtd_RED_Desired_States[3], real_T *rtd_RED_Path_Planner_Selection,
  P_Phase4ReturnHome_STQMEKF_T *localP)
{
  // DataStoreWrite: '<S22>/Data Store Write24' incorporates:
  //   Constant: '<S22>/Constant11'

  *rtd_RED_Path_Planner_Selection = localP->Constant11_Value;

  // DataStoreWrite: '<S22>/Data Store Write3' incorporates:
  //   Constant: '<S22>/Constant12'

  *rtd_ARM_Path_Planner_Selection = localP->Constant12_Value;

  // DataStoreWrite: '<S22>/Data Store Write23' incorporates:
  //   Constant: '<S22>/Constant14'

  *rtd_BLACK_Path_Planner_Selectio = localP->Constant14_Value;

  // DataStoreWrite: '<S22>/Data Store Write22' incorporates:
  //   Constant: '<S22>/Constant15'

  *rtd_BLUE_Path_Planner_Selection = localP->Constant15_Value;

  // DataStoreWrite: '<S22>/Data Store Write4' incorporates:
  //   Constant: '<S22>/Constant18'

  *rtd_ARM_Control_Law_Enabler = localP->Constant18_Value;

  // DataStoreWrite: '<S22>/Data Store Write5' incorporates:
  //   Constant: '<S22>/Constant4'

  *rtd_BLACK_Control_Law_Enabler = localP->Constant4_Value;

  // DataStoreWrite: '<S22>/Data Store Write8' incorporates:
  //   Constant: '<S22>/Constant5'

  *rtd_RED_Control_Law_Enabler = localP->Constant5_Value;

  // DataStoreWrite: '<S22>/Data Store Write7' incorporates:
  //   Constant: '<S22>/Constant6'

  *rtd_Float_State = localP->Constant6_Value;

  // DataStoreWrite: '<S22>/Data Store Write16' incorporates:
  //   Constant: '<S22>/Constant8'

  *rtd_BLUE_Control_Law_Enabler = localP->Constant8_Value;

  // DataStoreWrite: '<S22>/Data Store Write13' incorporates:
  //   Constant: '<S72>/Constant1'
  //   Constant: '<S72>/Constant2'
  //   Constant: '<S72>/Constant3'

  rtd_ARM_Desired_States[0] = localP->Constant3_Value;
  rtd_ARM_Desired_States[1] = localP->Constant1_Value;
  rtd_ARM_Desired_States[2] = localP->Constant2_Value;

  // DataStoreWrite: '<S22>/Data Store Write18' incorporates:
  //   Constant: '<S74>/Desired States (BLUE)'

  rtd_BLUE_Desired_States[0] = STQMEKF_P.home_states_BLUE[0];

  // DataStoreWrite: '<S22>/Data Store Write6' incorporates:
  //   Constant: '<S73>/Desired States (BLACK)'

  rtd_BLACK_Desired_States[0] = STQMEKF_P.home_states_BLACK[0];

  // DataStoreWrite: '<S22>/Data Store Write9' incorporates:
  //   Constant: '<S75>/Constant2'

  rtd_RED_Desired_States[0] = STQMEKF_P.home_states_RED[0];

  // DataStoreWrite: '<S22>/Data Store Write18' incorporates:
  //   Constant: '<S74>/Desired States (BLUE)'

  rtd_BLUE_Desired_States[1] = STQMEKF_P.home_states_BLUE[1];

  // DataStoreWrite: '<S22>/Data Store Write6' incorporates:
  //   Constant: '<S73>/Desired States (BLACK)'

  rtd_BLACK_Desired_States[1] = STQMEKF_P.home_states_BLACK[1];

  // DataStoreWrite: '<S22>/Data Store Write9' incorporates:
  //   Constant: '<S75>/Constant2'

  rtd_RED_Desired_States[1] = STQMEKF_P.home_states_RED[1];

  // DataStoreWrite: '<S22>/Data Store Write18' incorporates:
  //   Constant: '<S74>/Desired States (BLUE)'

  rtd_BLUE_Desired_States[2] = STQMEKF_P.home_states_BLUE[2];

  // DataStoreWrite: '<S22>/Data Store Write6' incorporates:
  //   Constant: '<S73>/Desired States (BLACK)'

  rtd_BLACK_Desired_States[2] = STQMEKF_P.home_states_BLACK[2];

  // DataStoreWrite: '<S22>/Data Store Write9' incorporates:
  //   Constant: '<S75>/Constant2'

  rtd_RED_Desired_States[2] = STQMEKF_P.home_states_RED[2];
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(static_cast<real_T>(tmp), static_cast<real_T>(tmp_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

//
// Output and update for atomic system:
//    '<S85>/MATLAB Function'
//    '<S84>/MATLAB Function'
//
void STQMEKF_MATLABFunction(const real_T rtu_desiredPosition[3], const real_T
  rtu_obstacles[4], real_T rtu_attractiveGain, real_T rtu_repulsiveGain, real_T
  rtu_influenceRange, real_T rtu_angularGain, real_T rty_currentPosition[3])
{
  real_T absxk;
  real_T distanceToObstacle;
  real_T newTheta;
  real_T repulsiveForce_idx_0;
  real_T repulsiveForce_idx_1;
  real_T scale;
  real_T t;
  real_T x_tmp_idx_0;
  repulsiveForce_idx_0 = 0.0;
  repulsiveForce_idx_1 = 0.0;
  scale = 3.3121686421112381E-170;
  newTheta = rty_currentPosition[0] - rtu_obstacles[0];
  x_tmp_idx_0 = newTheta;
  absxk = fabs(newTheta);
  if (absxk > 3.3121686421112381E-170) {
    distanceToObstacle = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    distanceToObstacle = t * t;
  }

  newTheta = rty_currentPosition[1] - rtu_obstacles[2];
  absxk = fabs(newTheta);
  if (absxk > scale) {
    t = scale / absxk;
    distanceToObstacle = distanceToObstacle * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    distanceToObstacle += t * t;
  }

  distanceToObstacle = scale * sqrt(distanceToObstacle);
  if (distanceToObstacle < rtu_influenceRange) {
    scale = (1.0 / distanceToObstacle - 1.0 / rtu_influenceRange) *
      rtu_repulsiveGain * (1.0 / (distanceToObstacle * distanceToObstacle));
    repulsiveForce_idx_0 = x_tmp_idx_0 / distanceToObstacle * scale;
    repulsiveForce_idx_1 = newTheta / distanceToObstacle * scale;
  }

  scale = 3.3121686421112381E-170;
  newTheta = rty_currentPosition[0] - rtu_obstacles[1];
  x_tmp_idx_0 = newTheta;
  absxk = fabs(newTheta);
  if (absxk > 3.3121686421112381E-170) {
    distanceToObstacle = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    distanceToObstacle = t * t;
  }

  newTheta = rty_currentPosition[1] - rtu_obstacles[3];
  absxk = fabs(newTheta);
  if (absxk > scale) {
    t = scale / absxk;
    distanceToObstacle = distanceToObstacle * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    distanceToObstacle += t * t;
  }

  distanceToObstacle = scale * sqrt(distanceToObstacle);
  if (distanceToObstacle < rtu_influenceRange) {
    scale = (1.0 / distanceToObstacle - 1.0 / rtu_influenceRange) *
      rtu_repulsiveGain * (1.0 / (distanceToObstacle * distanceToObstacle));
    repulsiveForce_idx_0 += x_tmp_idx_0 / distanceToObstacle * scale;
    repulsiveForce_idx_1 += newTheta / distanceToObstacle * scale;
  }

  newTheta = rtu_desiredPosition[2] - rty_currentPosition[2];
  newTheta = rt_atan2d_snf(sin(newTheta), cos(newTheta)) * rtu_angularGain *
    STQMEKF_P.baseRate + rty_currentPosition[2];
  rty_currentPosition[0] += ((rtu_desiredPosition[0] - rty_currentPosition[0]) *
    rtu_attractiveGain + repulsiveForce_idx_0) * STQMEKF_P.baseRate;
  rty_currentPosition[1] += ((rtu_desiredPosition[1] - rty_currentPosition[1]) *
    rtu_attractiveGain + repulsiveForce_idx_1) * STQMEKF_P.baseRate;
  rty_currentPosition[2] = rt_atan2d_snf(sin(newTheta), cos(newTheta));
}

//
// Output and update for atomic system:
//    '<S154>/MATLAB Function'
//    '<S131>/MATLAB Function'
//    '<S144>/MATLAB Function'
//    '<S121>/MATLAB Function'
//    '<S149>/MATLAB Function'
//    '<S126>/MATLAB Function'
//
void STQMEKF_MATLABFunction_n(real_T rtu_Rz_path, real_T rtu_Rz_measured, real_T
  *rty_Rz_error)
{
  real_T q;
  real_T r;
  q = (rtu_Rz_measured - rtu_Rz_path) + 3.1415926535897931;
  if (rtIsNaN(q)) {
    r = (rtNaN);
  } else if (rtIsInf(q)) {
    r = (rtNaN);
  } else if (q == 0.0) {
    r = 0.0;
  } else {
    boolean_T rEQ0;
    r = fmod(q, 6.2831853071795862);
    rEQ0 = (r == 0.0);
    if (!rEQ0) {
      q = fabs(q / 6.2831853071795862);
      rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
    }

    if (rEQ0) {
      r = 0.0;
    } else if (r < 0.0) {
      r += 6.2831853071795862;
    }
  }

  *rty_Rz_error = r - 3.1415926535897931;
}

//
// Output and update for action system:
//    '<S3>/Custom Control (RED)'
//    '<S3>/Disable Thrusters (RED)'
//    '<S3>/Custom Control (ARM)'
//
void STQMEKF_CustomControlRED(real_T rty_u[3], P_CustomControlRED_STQMEKF_T
  *localP)
{
  // SignalConversion generated from: '<S109>/u' incorporates:
  //   Constant: '<S109>/Zero'

  rty_u[0] = localP->Zero_Value;
  rty_u[1] = localP->Zero_Value;
  rty_u[2] = localP->Zero_Value;
}

//
// Output and update for action system:
//    '<S3>/Disable Thrusters (BLACK)'
//    '<S3>/Disable Thrusters (BLUE)'
//
void STQMEKF_DisableThrustersBLACK(real_T rty_Out1[3],
  P_DisableThrustersBLACK_STQME_T *localP)
{
  // SignalConversion generated from: '<S118>/Out1' incorporates:
  //   Constant: '<S118>/Zero'

  rty_Out1[0] = localP->Zero_Value;
  rty_Out1[1] = localP->Zero_Value;
  rty_Out1[2] = localP->Zero_Value;
}

//
// System initialize for action system:
//    '<S4>/Change BLACK Behavior'
//    '<S4>/Change BLUE Behavior'
//    '<S4>/Change RED Behavior'
//
void STQMEK_ChangeBLACKBehavior_Init(RT_MODEL_STQMEKF_T * const STQMEKF_M,
  DW_ChangeBLACKBehavior_STQMEK_T *localDW, P_ChangeBLACKBehavior_STQMEKF_T
  *localP)
{
  char_T *sErr;

  // Start for S-Function (sdspToNetwork): '<S159>/UDP Send'
  sErr = GetErrorBuffer(&localDW->UDPSend_NetworkLib[0U]);
  CreateUDPInterface(&localDW->UDPSend_NetworkLib[0U]);
  if (*sErr == 0) {
    LibCreate_Network(&localDW->UDPSend_NetworkLib[0U], 1, "0.0.0.0", -1,
                      "255.255.255.255", localP->UDPSend_Port, 8192, 4, 0);
  }

  if (*sErr == 0) {
    LibStart(&localDW->UDPSend_NetworkLib[0U]);
  }

  if (*sErr != 0) {
    DestroyUDPInterface(&localDW->UDPSend_NetworkLib[0U]);
    if (*sErr != 0) {
      STQMEKF_M->setErrorStatus(sErr);
      STQMEKF_M->setStopRequested(1);
    }
  }

  // End of Start for S-Function (sdspToNetwork): '<S159>/UDP Send'
}

//
// Output and update for action system:
//    '<S4>/Change BLACK Behavior'
//    '<S4>/Change BLUE Behavior'
//    '<S4>/Change RED Behavior'
//
void STQMEKF_ChangeBLACKBehavior(RT_MODEL_STQMEKF_T * const STQMEKF_M,
  DW_ChangeBLACKBehavior_STQMEK_T *localDW, P_ChangeBLACKBehavior_STQMEKF_T
  *localP)
{
  char_T *sErr;

  // Update for S-Function (sdspToNetwork): '<S159>/UDP Send' incorporates:
  //   Constant: '<S159>/Constant1'

  sErr = GetErrorBuffer(&localDW->UDPSend_NetworkLib[0U]);
  LibUpdate_Network(&localDW->UDPSend_NetworkLib[0U], &localP->Constant1_Value,
                    1);
  if (*sErr != 0) {
    STQMEKF_M->setErrorStatus(sErr);
    STQMEKF_M->setStopRequested(1);
  }

  // End of Update for S-Function (sdspToNetwork): '<S159>/UDP Send'
}

//
// Termination for action system:
//    '<S4>/Change BLACK Behavior'
//    '<S4>/Change BLUE Behavior'
//    '<S4>/Change RED Behavior'
//
void STQMEK_ChangeBLACKBehavior_Term(RT_MODEL_STQMEKF_T * const STQMEKF_M,
  DW_ChangeBLACKBehavior_STQMEK_T *localDW)
{
  char_T *sErr;

  // Terminate for S-Function (sdspToNetwork): '<S159>/UDP Send'
  sErr = GetErrorBuffer(&localDW->UDPSend_NetworkLib[0U]);
  LibTerminate(&localDW->UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    STQMEKF_M->setErrorStatus(sErr);
    STQMEKF_M->setStopRequested(1);
  }

  LibDestroy(&localDW->UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&localDW->UDPSend_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S159>/UDP Send'
}

//
// Output and update for atomic system:
//    '<S182>/MATLAB Function'
//    '<S192>/MATLAB Function'
//    '<S202>/MATLAB Function'
//
void STQMEKF_MATLABFunction_j(real_T rtu_dt, real_T rtu_dataRate, real_T
  *rty_dt_out)
{
  if (rtu_dt <= 0.0) {
    *rty_dt_out = rtu_dataRate;
  } else {
    *rty_dt_out = rtu_dt;
  }
}

//
// System initialize for enable system:
//    '<S183>/Enabled Subsystem'
//    '<S193>/Enabled Subsystem'
//    '<S203>/Enabled Subsystem'
//
void STQMEKF_EnabledSubsystem_Init(real_T rty_dydt[3],
  DW_EnabledSubsystem_STQMEKF_T *localDW, P_EnabledSubsystem_STQMEKF_T *localP)
{
  // InitializeConditions for Delay: '<S188>/Delay'
  localDW->icLoad = true;

  // InitializeConditions for Delay: '<S188>/Delay1'
  localDW->Delay1_DSTATE[0] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S188>/dy//dt'
  rty_dydt[0] = localP->dydt_Y0;

  // InitializeConditions for Delay: '<S188>/Delay1'
  localDW->Delay1_DSTATE[1] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S188>/dy//dt'
  rty_dydt[1] = localP->dydt_Y0;

  // InitializeConditions for Delay: '<S188>/Delay1'
  localDW->Delay1_DSTATE[2] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S188>/dy//dt'
  rty_dydt[2] = localP->dydt_Y0;
}

//
// Disable for enable system:
//    '<S183>/Enabled Subsystem'
//    '<S193>/Enabled Subsystem'
//    '<S203>/Enabled Subsystem'
//
void STQMEK_EnabledSubsystem_Disable(DW_EnabledSubsystem_STQMEKF_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

//
// Outputs for enable system:
//    '<S183>/Enabled Subsystem'
//    '<S193>/Enabled Subsystem'
//    '<S203>/Enabled Subsystem'
//
void STQMEKF_EnabledSubsystem(const boolean_T rtu_Enable[3], const real_T rtu_y
  [3], real_T rtu_dt, real_T rty_dydt[3], B_EnabledSubsystem_STQMEKF_T *localB,
  DW_EnabledSubsystem_STQMEKF_T *localDW, P_EnabledSubsystem_STQMEKF_T *localP)
{
  real_T ema;
  real_T x;

  // Outputs for Enabled SubSystem: '<S183>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S188>/Enable'

  if (rtu_Enable[0] || rtu_Enable[1] || rtu_Enable[2]) {
    localDW->EnabledSubsystem_MODE = true;
  } else if (localDW->EnabledSubsystem_MODE) {
    STQMEK_EnabledSubsystem_Disable(localDW);
  }

  if (localDW->EnabledSubsystem_MODE) {
    // Delay: '<S188>/Delay'
    if (localDW->icLoad) {
      localDW->Delay_DSTATE[0] = rtu_y[0];
      localDW->Delay_DSTATE[1] = rtu_y[1];
      localDW->Delay_DSTATE[2] = rtu_y[2];
    }

    // MATLAB Function: '<S188>/MATLAB Function' incorporates:
    //   Constant: '<S188>/Constant2'

    x = exp(-rtu_dt / localP->Constant2_Value);

    // Delay: '<S188>/Delay'
    localB->Delay[0] = localDW->Delay_DSTATE[0];

    // Delay: '<S188>/Delay1'
    localB->Delay1[0] = localDW->Delay1_DSTATE[0];

    // MATLAB Function: '<S188>/MATLAB Function' incorporates:
    //   Delay: '<S188>/Delay'

    ema = (1.0 - (1.0 - x)) * localDW->Delay_DSTATE[0] + (1.0 - x) * rtu_y[0];
    localB->ema[0] = ema;

    // MATLAB Function: '<S188>/MATLAB Function' incorporates:
    //   Delay: '<S188>/Delay'

    rty_dydt[0] = (ema - localDW->Delay_DSTATE[0]) / rtu_dt;

    // Delay: '<S188>/Delay'
    localB->Delay[1] = localDW->Delay_DSTATE[1];

    // Delay: '<S188>/Delay1'
    localB->Delay1[1] = localDW->Delay1_DSTATE[1];

    // MATLAB Function: '<S188>/MATLAB Function' incorporates:
    //   Delay: '<S188>/Delay'

    ema = (1.0 - (1.0 - x)) * localDW->Delay_DSTATE[1] + (1.0 - x) * rtu_y[1];
    localB->ema[1] = ema;

    // MATLAB Function: '<S188>/MATLAB Function' incorporates:
    //   Delay: '<S188>/Delay'

    rty_dydt[1] = (ema - localDW->Delay_DSTATE[1]) / rtu_dt;

    // Delay: '<S188>/Delay'
    localB->Delay[2] = localDW->Delay_DSTATE[2];

    // Delay: '<S188>/Delay1'
    localB->Delay1[2] = localDW->Delay1_DSTATE[2];

    // MATLAB Function: '<S188>/MATLAB Function' incorporates:
    //   Delay: '<S188>/Delay'

    ema = (1.0 - (1.0 - x)) * localDW->Delay_DSTATE[2] + (1.0 - x) * rtu_y[2];
    localB->ema[2] = ema;

    // MATLAB Function: '<S188>/MATLAB Function' incorporates:
    //   Delay: '<S188>/Delay'

    rty_dydt[2] = (ema - localDW->Delay_DSTATE[2]) / rtu_dt;
  }

  // End of Outputs for SubSystem: '<S183>/Enabled Subsystem'
}

//
// Update for enable system:
//    '<S183>/Enabled Subsystem'
//    '<S193>/Enabled Subsystem'
//    '<S203>/Enabled Subsystem'
//
void STQMEKF_EnabledSubsystem_Update(real_T rty_dydt[3],
  B_EnabledSubsystem_STQMEKF_T *localB, DW_EnabledSubsystem_STQMEKF_T *localDW)
{
  // Update for Enabled SubSystem: '<S183>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S188>/Enable'

  if (localDW->EnabledSubsystem_MODE) {
    // Update for Delay: '<S188>/Delay'
    localDW->icLoad = false;
    localDW->Delay_DSTATE[0] = localB->ema[0];

    // Update for Delay: '<S188>/Delay1'
    localDW->Delay1_DSTATE[0] = rty_dydt[0];

    // Update for Delay: '<S188>/Delay'
    localDW->Delay_DSTATE[1] = localB->ema[1];

    // Update for Delay: '<S188>/Delay1'
    localDW->Delay1_DSTATE[1] = rty_dydt[1];

    // Update for Delay: '<S188>/Delay'
    localDW->Delay_DSTATE[2] = localB->ema[2];

    // Update for Delay: '<S188>/Delay1'
    localDW->Delay1_DSTATE[2] = rty_dydt[2];
  }

  // End of Update for SubSystem: '<S183>/Enabled Subsystem'
}

//
// System initialize for enable system:
//    '<S184>/Enabled Subsystem'
//    '<S194>/Enabled Subsystem'
//    '<S204>/Enabled Subsystem'
//
void STQMEKF_EnabledSubsystem_e_Init(real_T rty_dydt[3],
  DW_EnabledSubsystem_STQMEKF_m_T *localDW, P_EnabledSubsystem_STQMEKF_d_T
  *localP)
{
  // InitializeConditions for Delay: '<S190>/Delay'
  localDW->icLoad = true;

  // InitializeConditions for Delay: '<S190>/Delay1'
  localDW->Delay1_DSTATE[0] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S190>/dy//dt'
  rty_dydt[0] = localP->dydt_Y0;

  // InitializeConditions for Delay: '<S190>/Delay1'
  localDW->Delay1_DSTATE[1] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S190>/dy//dt'
  rty_dydt[1] = localP->dydt_Y0;

  // InitializeConditions for Delay: '<S190>/Delay1'
  localDW->Delay1_DSTATE[2] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S190>/dy//dt'
  rty_dydt[2] = localP->dydt_Y0;
}

//
// Disable for enable system:
//    '<S184>/Enabled Subsystem'
//    '<S194>/Enabled Subsystem'
//    '<S204>/Enabled Subsystem'
//
void STQM_EnabledSubsystem_l_Disable(DW_EnabledSubsystem_STQMEKF_m_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

//
// Outputs for enable system:
//    '<S184>/Enabled Subsystem'
//    '<S194>/Enabled Subsystem'
//    '<S204>/Enabled Subsystem'
//
void STQMEKF_EnabledSubsystem_n(const boolean_T rtu_Enable[3], real_T rtu_y,
  real_T rtu_y_p, real_T rtu_y_o, real_T rtu_dt, real_T rty_dydt[3],
  B_EnabledSubsystem_STQMEKF_b_T *localB, DW_EnabledSubsystem_STQMEKF_m_T
  *localDW, P_EnabledSubsystem_STQMEKF_d_T *localP)
{
  real_T x;

  // Outputs for Enabled SubSystem: '<S184>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S190>/Enable'

  if (rtu_Enable[0] || rtu_Enable[1] || rtu_Enable[2]) {
    localDW->EnabledSubsystem_MODE = true;
  } else if (localDW->EnabledSubsystem_MODE) {
    STQM_EnabledSubsystem_l_Disable(localDW);
  }

  if (localDW->EnabledSubsystem_MODE) {
    // Delay: '<S190>/Delay' incorporates:
    //   SignalConversion generated from: '<S190>/Delay'

    if (localDW->icLoad) {
      localDW->Delay_DSTATE[0] = rtu_y;
      localDW->Delay_DSTATE[1] = rtu_y_p;
      localDW->Delay_DSTATE[2] = rtu_y_o;
    }

    // Delay: '<S190>/Delay'
    localB->Delay[0] = localDW->Delay_DSTATE[0];

    // Delay: '<S190>/Delay1'
    localB->Delay1[0] = localDW->Delay1_DSTATE[0];

    // Delay: '<S190>/Delay'
    localB->Delay[1] = localDW->Delay_DSTATE[1];

    // Delay: '<S190>/Delay1'
    localB->Delay1[1] = localDW->Delay1_DSTATE[1];

    // Delay: '<S190>/Delay'
    localB->Delay[2] = localDW->Delay_DSTATE[2];

    // Delay: '<S190>/Delay1'
    localB->Delay1[2] = localDW->Delay1_DSTATE[2];

    // MATLAB Function: '<S190>/MATLAB Function' incorporates:
    //   Constant: '<S190>/Constant2'
    //   SignalConversion generated from: '<S191>/ SFunction '

    x = exp(-rtu_dt / localP->Constant2_Value);
    localB->ema[0] = (1.0 - (1.0 - x)) * localB->Delay[0] + (1.0 - x) * rtu_y;
    localB->ema[1] = (1.0 - (1.0 - x)) * localB->Delay[1] + (1.0 - x) * rtu_y_p;
    localB->ema[2] = (1.0 - (1.0 - x)) * localB->Delay[2] + (1.0 - x) * rtu_y_o;
    rty_dydt[0] = (localB->ema[0] - localB->Delay[0]) / rtu_dt;
    rty_dydt[1] = (localB->ema[1] - localB->Delay[1]) / rtu_dt;
    rty_dydt[2] = (localB->ema[2] - localB->Delay[2]) / rtu_dt;
  }

  // End of Outputs for SubSystem: '<S184>/Enabled Subsystem'
}

//
// Update for enable system:
//    '<S184>/Enabled Subsystem'
//    '<S194>/Enabled Subsystem'
//    '<S204>/Enabled Subsystem'
//
void STQME_EnabledSubsystem_n_Update(real_T rty_dydt[3],
  B_EnabledSubsystem_STQMEKF_b_T *localB, DW_EnabledSubsystem_STQMEKF_m_T
  *localDW)
{
  // Update for Enabled SubSystem: '<S184>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S190>/Enable'

  if (localDW->EnabledSubsystem_MODE) {
    // Update for Delay: '<S190>/Delay'
    localDW->icLoad = false;
    localDW->Delay_DSTATE[0] = localB->ema[0];

    // Update for Delay: '<S190>/Delay1'
    localDW->Delay1_DSTATE[0] = rty_dydt[0];

    // Update for Delay: '<S190>/Delay'
    localDW->Delay_DSTATE[1] = localB->ema[1];

    // Update for Delay: '<S190>/Delay1'
    localDW->Delay1_DSTATE[1] = rty_dydt[1];

    // Update for Delay: '<S190>/Delay'
    localDW->Delay_DSTATE[2] = localB->ema[2];

    // Update for Delay: '<S190>/Delay1'
    localDW->Delay1_DSTATE[2] = rty_dydt[2];
  }

  // End of Update for SubSystem: '<S184>/Enabled Subsystem'
}

static real_T STQMEKF_xzlangeM(const real_T x[24])
{
  real_T y;
  int32_T b_k;
  boolean_T exitg1;
  y = 0.0;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 24)) {
    real_T absxk;
    absxk = fabs(x[b_k]);
    if (rtIsNaN(absxk)) {
      y = (rtNaN);
      exitg1 = true;
    } else {
      if (absxk > y) {
        y = absxk;
      }

      b_k++;
    }
  }

  return y;
}

static void STQMEKF_xzlascl(real_T cfrom, real_T cto, real_T A[24])
{
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;

  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    real_T cfrom1;
    real_T cto1;
    real_T mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }

    for (int32_T i = 0; i < 24; i++) {
      A[i] *= mul;
    }
  }

  // End of Start for MATLABSystem: '<S231>/Pseudoinverse1'
}

static real_T STQMEKF_xnrm2(int32_T n, const real_T x[24], int32_T ix0)
{
  real_T scale;
  real_T y;
  int32_T kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;

  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  kend = ix0 + n;
  for (int32_T k = ix0; k < kend; k++) {
    real_T absxk;
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      real_T t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      real_T t;
      t = absxk / scale;
      y += t * t;
    }
  }

  // End of Start for MATLABSystem: '<S231>/Pseudoinverse1'
  return scale * sqrt(y);
}

static real_T STQMEKF_xdotc(int32_T n, const real_T x[24], int32_T ix0, const
  real_T y[24], int32_T iy0)
{
  real_T d;
  int32_T b;
  d = 0.0;

  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  b = static_cast<uint8_T>(n);
  for (int32_T k = 0; k < b; k++) {
    // Start for MATLABSystem: '<S231>/Pseudoinverse1'
    d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
  }

  return d;
}

static void STQMEKF_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[24],
  int32_T iy0)
{
  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  if (!(a == 0.0)) {
    for (int32_T k = 0; k < n; k++) {
      int32_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += y[(ix0 + k) - 1] * a;
    }
  }

  // End of Start for MATLABSystem: '<S231>/Pseudoinverse1'
}

static real_T STQMEKF_xdotc_o(const real_T x[9], const real_T y[9], int32_T iy0)
{
  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  return y[iy0 - 1] * x[1] + x[2] * y[iy0];
}

static void STQMEKF_xaxpy_gop(real_T a, real_T y[9], int32_T iy0)
{
  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  if (!(a == 0.0)) {
    y[iy0 - 1] += a * y[1];
    y[iy0] += a * y[2];
  }

  // End of Start for MATLABSystem: '<S231>/Pseudoinverse1'
}

static real_T STQMEKF_xnrm2_p(const real_T x[3], int32_T ix0)
{
  real_T scale;
  real_T y;
  y = 0.0;
  scale = 3.3121686421112381E-170;

  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  for (int32_T k = ix0; k <= ix0 + 1; k++) {
    real_T absxk;
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      real_T t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      real_T t;
      t = absxk / scale;
      y += t * t;
    }
  }

  // End of Start for MATLABSystem: '<S231>/Pseudoinverse1'
  return scale * sqrt(y);
}

static void STQMEKF_xaxpy_g(int32_T n, real_T a, const real_T x[24], int32_T ix0,
  real_T y[8], int32_T iy0)
{
  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  if (!(a == 0.0)) {
    for (int32_T k = 0; k < n; k++) {
      int32_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += x[(ix0 + k) - 1] * a;
    }
  }

  // End of Start for MATLABSystem: '<S231>/Pseudoinverse1'
}

static void STQMEKF_xaxpy_go(int32_T n, real_T a, const real_T x[8], int32_T ix0,
  real_T y[24], int32_T iy0)
{
  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  if (!(a == 0.0)) {
    for (int32_T k = 0; k < n; k++) {
      int32_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += x[(ix0 + k) - 1] * a;
    }
  }

  // End of Start for MATLABSystem: '<S231>/Pseudoinverse1'
}

static void STQMEKF_xzlascl_i(real_T cfrom, real_T cto, real_T A[3])
{
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;

  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    real_T cfrom1;
    real_T cto1;
    real_T mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }

    A[0] *= mul;
    A[1] *= mul;
    A[2] *= mul;
  }

  // End of Start for MATLABSystem: '<S231>/Pseudoinverse1'
}

static void STQMEKF_xrotg(real_T a, real_T b, real_T *b_a, real_T *b_b, real_T
  *c, real_T *s)
{
  real_T absa;
  real_T absb;
  real_T roe;
  real_T scale;

  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  roe = b;
  absa = fabs(a);
  absb = fabs(b);
  if (absa > absb) {
    // Start for MATLABSystem: '<S231>/Pseudoinverse1'
    roe = a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *b_a = 0.0;
    *b_b = 0.0;
  } else {
    real_T ads;
    real_T bds;
    ads = absa / scale;
    bds = absb / scale;

    // Start for MATLABSystem: '<S231>/Pseudoinverse1'
    *b_a = sqrt(ads * ads + bds * bds) * scale;
    if (roe < 0.0) {
      *b_a = -*b_a;
    }

    // Start for MATLABSystem: '<S231>/Pseudoinverse1'
    *c = a / *b_a;
    *s = b / *b_a;
    if (absa > absb) {
      *b_b = *s;
    } else if (*c != 0.0) {
      // Start for MATLABSystem: '<S231>/Pseudoinverse1'
      *b_b = 1.0 / *c;
    } else {
      *b_b = 1.0;
    }
  }
}

static void STQMEKF_xrot_ps(real_T x[9], int32_T ix0, int32_T iy0, real_T c,
  real_T s)
{
  real_T temp;
  real_T temp_tmp;

  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  temp = x[iy0 - 1];
  temp_tmp = x[ix0 - 1];
  x[iy0 - 1] = temp * c - temp_tmp * s;
  x[ix0 - 1] = temp_tmp * c + temp * s;
  temp = x[ix0] * c + x[iy0] * s;
  x[iy0] = x[iy0] * c - x[ix0] * s;
  x[ix0] = temp;
  temp = x[iy0 + 1];
  temp_tmp = x[ix0 + 1];
  x[iy0 + 1] = temp * c - temp_tmp * s;
  x[ix0 + 1] = temp_tmp * c + temp * s;
}

static void STQMEKF_xrot_psj(real_T x[24], int32_T ix0, int32_T iy0, real_T c,
  real_T s)
{
  for (int32_T k = 0; k < 8; k++) {
    real_T temp_tmp;
    real_T temp_tmp_0;
    int32_T temp_tmp_tmp;
    int32_T temp_tmp_tmp_0;

    // Start for MATLABSystem: '<S231>/Pseudoinverse1'
    temp_tmp_tmp = (iy0 + k) - 1;
    temp_tmp = x[temp_tmp_tmp];

    // Start for MATLABSystem: '<S231>/Pseudoinverse1'
    temp_tmp_tmp_0 = (ix0 + k) - 1;
    temp_tmp_0 = x[temp_tmp_tmp_0];

    // Start for MATLABSystem: '<S231>/Pseudoinverse1'
    x[temp_tmp_tmp] = temp_tmp * c - temp_tmp_0 * s;
    x[temp_tmp_tmp_0] = temp_tmp_0 * c + temp_tmp * s;
  }
}

static void STQMEKF_xswap_dj(real_T x[9], int32_T ix0, int32_T iy0)
{
  real_T temp;

  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  temp = x[ix0 - 1];
  x[ix0 - 1] = x[iy0 - 1];
  x[iy0 - 1] = temp;
  temp = x[ix0];
  x[ix0] = x[iy0];
  x[iy0] = temp;
  temp = x[ix0 + 1];
  x[ix0 + 1] = x[iy0 + 1];
  x[iy0 + 1] = temp;
}

static void STQMEKF_xswap_dj5(real_T x[24], int32_T ix0, int32_T iy0)
{
  for (int32_T k = 0; k < 8; k++) {
    real_T temp;
    int32_T temp_tmp;
    int32_T tmp;

    // Start for MATLABSystem: '<S231>/Pseudoinverse1'
    temp_tmp = (ix0 + k) - 1;
    temp = x[temp_tmp];

    // Start for MATLABSystem: '<S231>/Pseudoinverse1'
    tmp = (iy0 + k) - 1;
    x[temp_tmp] = x[tmp];
    x[tmp] = temp;
  }
}

static void STQMEKF_svd(const real_T A[24], real_T U[24], real_T s[3], real_T V
  [9])
{
  real_T A_0[24];
  real_T Vf[9];
  real_T work[8];
  real_T e[3];
  real_T s_0[3];
  real_T a__3;
  real_T anrm;
  real_T b;
  real_T cscale;
  real_T d_sn;
  real_T emm1;
  real_T nrm;
  real_T r;
  real_T smm1;
  real_T sqds;
  real_T ztest;
  int32_T b_0;
  int32_T colqp1;
  int32_T i;
  int32_T qjj;
  int32_T qp1;
  int32_T qq;
  int32_T qq_tmp_tmp;
  boolean_T apply_transform;
  boolean_T doscale;
  boolean_T exitg1;

  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  memcpy(&A_0[0], &A[0], 24U * sizeof(real_T));
  s_0[0] = 0.0;
  e[0] = 0.0;
  s_0[1] = 0.0;
  e[1] = 0.0;
  s_0[2] = 0.0;
  e[2] = 0.0;
  memset(&work[0], 0, sizeof(real_T) << 3U);
  memset(&U[0], 0, 24U * sizeof(real_T));
  memset(&Vf[0], 0, 9U * sizeof(real_T));
  doscale = false;

  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  anrm = STQMEKF_xzlangeM(A);
  cscale = anrm;

  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
    doscale = true;
    cscale = 6.7178761075670888E-139;
    STQMEKF_xzlascl(anrm, cscale, A_0);
  } else if (anrm > 1.4885657073574029E+138) {
    doscale = true;
    cscale = 1.4885657073574029E+138;
    STQMEKF_xzlascl(anrm, cscale, A_0);
  }

  for (i = 0; i < 3; i++) {
    // Start for MATLABSystem: '<S231>/Pseudoinverse1'
    qp1 = i + 2;
    qq_tmp_tmp = i << 3;

    // Start for MATLABSystem: '<S231>/Pseudoinverse1'
    colqp1 = qq_tmp_tmp + i;
    qq = colqp1 + 1;
    apply_transform = false;

    // Start for MATLABSystem: '<S231>/Pseudoinverse1'
    nrm = STQMEKF_xnrm2(8 - i, A_0, colqp1 + 1);
    if (nrm > 0.0) {
      apply_transform = true;

      // Start for MATLABSystem: '<S231>/Pseudoinverse1'
      if (A_0[colqp1] < 0.0) {
        r = -nrm;
        s_0[i] = -nrm;
      } else {
        r = nrm;
        s_0[i] = nrm;
      }

      if (fabs(r) >= 1.0020841800044864E-292) {
        r = 1.0 / r;
        b_0 = (colqp1 - i) + 1;
        for (qjj = qq; qjj <= b_0 + 7; qjj++) {
          A_0[qjj - 1] *= r;
        }
      } else {
        b_0 = (colqp1 - i) + 1;
        for (qjj = qq; qjj <= b_0 + 7; qjj++) {
          A_0[qjj - 1] /= s_0[i];
        }
      }

      A_0[colqp1]++;
      s_0[i] = -s_0[i];
    } else {
      s_0[i] = 0.0;
    }

    for (qq = qp1; qq < 4; qq++) {
      // Start for MATLABSystem: '<S231>/Pseudoinverse1'
      qjj = (((qq - 1) << 3) + i) + 1;
      if (apply_transform) {
        // Start for MATLABSystem: '<S231>/Pseudoinverse1'
        STQMEKF_xaxpy(8 - i, -(STQMEKF_xdotc(8 - i, A_0, colqp1 + 1, A_0, qjj) /
          A_0[colqp1]), colqp1 + 1, A_0, qjj);
      }

      e[qq - 1] = A_0[qjj - 1];
    }

    // Start for MATLABSystem: '<S231>/Pseudoinverse1'
    for (colqp1 = i + 1; colqp1 < 9; colqp1++) {
      qjj = (qq_tmp_tmp + colqp1) - 1;
      U[qjj] = A_0[qjj];
    }

    if (i + 1 <= 1) {
      nrm = STQMEKF_xnrm2_p(e, i + 2);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[i + 1] < 0.0) {
          nrm = -nrm;
        }

        e[0] = nrm;
        if (fabs(nrm) >= 1.0020841800044864E-292) {
          r = 1.0 / nrm;
          for (qjj = qp1; qjj <= i + 3; qjj++) {
            e[qjj - 1] *= r;
          }
        } else {
          for (qjj = qp1; qjj <= i + 3; qjj++) {
            e[qjj - 1] /= nrm;
          }
        }

        e[i + 1]++;
        e[0] = -e[0];
        for (colqp1 = qp1; colqp1 < 9; colqp1++) {
          work[colqp1 - 1] = 0.0;
        }

        for (colqp1 = qp1; colqp1 < 4; colqp1++) {
          STQMEKF_xaxpy_g(7 - i, e[colqp1 - 1], A_0, (i + ((colqp1 - 1) << 3)) +
                          2, work, i + 2);
        }

        for (colqp1 = qp1; colqp1 < 4; colqp1++) {
          STQMEKF_xaxpy_go(7 - i, -e[colqp1 - 1] / e[i + 1], work, i + 2, A_0,
                           (i + ((colqp1 - 1) << 3)) + 2);
        }
      }

      for (colqp1 = qp1; colqp1 < 4; colqp1++) {
        Vf[colqp1 - 1] = e[colqp1 - 1];
      }
    }
  }

  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  i = 2;
  e[1] = A_0[17];
  e[2] = 0.0;

  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  for (qp1 = 2; qp1 >= 0; qp1--) {
    colqp1 = qp1 << 3;
    qq = colqp1 + qp1;
    if (s_0[qp1] != 0.0) {
      for (qq_tmp_tmp = qp1 + 2; qq_tmp_tmp < 4; qq_tmp_tmp++) {
        qjj = (((qq_tmp_tmp - 1) << 3) + qp1) + 1;
        STQMEKF_xaxpy(8 - qp1, -(STQMEKF_xdotc(8 - qp1, U, qq + 1, U, qjj) /
          U[qq]), qq + 1, U, qjj);
      }

      for (qq_tmp_tmp = qp1 + 1; qq_tmp_tmp < 9; qq_tmp_tmp++) {
        qjj = (colqp1 + qq_tmp_tmp) - 1;
        U[qjj] = -U[qjj];
      }

      U[qq]++;
      for (qq = 0; qq < qp1; qq++) {
        U[qq + colqp1] = 0.0;
      }
    } else {
      memset(&U[colqp1], 0, sizeof(real_T) << 3U);
      U[qq] = 1.0;
    }

    if ((qp1 + 1 <= 1) && (e[0] != 0.0)) {
      STQMEKF_xaxpy_gop(-(STQMEKF_xdotc_o(Vf, Vf, 5) / Vf[1]), Vf, 5);
      STQMEKF_xaxpy_gop(-(STQMEKF_xdotc_o(Vf, Vf, 8) / Vf[1]), Vf, 8);
    }

    Vf[3 * qp1] = 0.0;
    Vf[3 * qp1 + 1] = 0.0;
    Vf[3 * qp1 + 2] = 0.0;
    Vf[qp1 + 3 * qp1] = 1.0;
  }

  for (qp1 = 0; qp1 < 3; qp1++) {
    r = s_0[qp1];
    if (r != 0.0) {
      // Start for MATLABSystem: '<S231>/Pseudoinverse1'
      nrm = fabs(r);
      r /= nrm;
      s_0[qp1] = nrm;

      // Start for MATLABSystem: '<S231>/Pseudoinverse1'
      if (qp1 + 1 < 3) {
        e[qp1] /= r;
      }

      qq = qp1 << 3;

      // Start for MATLABSystem: '<S231>/Pseudoinverse1'
      for (qjj = qq + 1; qjj <= qq + 8; qjj++) {
        U[qjj - 1] *= r;
      }
    }

    // Start for MATLABSystem: '<S231>/Pseudoinverse1'
    if (qp1 + 1 < 3) {
      ztest = e[qp1];
      if (ztest != 0.0) {
        nrm = fabs(ztest);
        r = nrm / ztest;
        e[qp1] = nrm;
        s_0[qp1 + 1] *= r;
        colqp1 = (qp1 + 1) * 3;
        for (qjj = colqp1 + 1; qjj <= colqp1 + 3; qjj++) {
          Vf[qjj - 1] *= r;
        }
      }
    }
  }

  qp1 = 0;
  r = 0.0;

  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  ztest = fabs(s_0[0]);
  nrm = fabs(e[0]);
  if ((ztest >= nrm) || rtIsNaN(nrm)) {
    nrm = ztest;
  }

  if ((!(nrm <= 0.0)) && (!rtIsNaN(nrm))) {
    r = nrm;
  }

  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  ztest = fabs(s_0[1]);
  nrm = fabs(e[1]);
  if ((ztest >= nrm) || rtIsNaN(nrm)) {
    nrm = ztest;
  }

  if ((!(r >= nrm)) && (!rtIsNaN(nrm))) {
    r = nrm;
  }

  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  ztest = fabs(s_0[2]);
  nrm = fabs(e[2]);
  if ((ztest >= nrm) || rtIsNaN(nrm)) {
    nrm = ztest;
  }

  if ((!(r >= nrm)) && (!rtIsNaN(nrm))) {
    r = nrm;
  }

  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  while ((i + 1 > 0) && (qp1 < 75)) {
    colqp1 = i;
    qq = i;
    exitg1 = false;
    while ((!exitg1) && (qq > -1)) {
      colqp1 = qq;
      if (qq == 0) {
        exitg1 = true;
      } else {
        nrm = fabs(e[qq - 1]);
        if ((nrm <= (fabs(s_0[qq - 1]) + fabs(s_0[qq])) * 2.2204460492503131E-16)
            || ((nrm <= 1.0020841800044864E-292) || ((qp1 > 20) && (nrm <=
               2.2204460492503131E-16 * r)))) {
          e[qq - 1] = 0.0;
          exitg1 = true;
        } else {
          qq--;
        }
      }
    }

    if (colqp1 == i) {
      qjj = 4;
    } else {
      qq = i + 1;
      qjj = i + 1;
      exitg1 = false;
      while ((!exitg1) && (qjj >= colqp1)) {
        qq = qjj;
        if (qjj == colqp1) {
          exitg1 = true;
        } else {
          nrm = 0.0;
          if (qjj < i + 1) {
            nrm = fabs(e[qjj - 1]);
          }

          if (qjj > colqp1 + 1) {
            nrm += fabs(e[qjj - 2]);
          }

          ztest = fabs(s_0[qjj - 1]);
          if ((ztest <= 2.2204460492503131E-16 * nrm) || (ztest <=
               1.0020841800044864E-292)) {
            s_0[qjj - 1] = 0.0;
            exitg1 = true;
          } else {
            qjj--;
          }
        }
      }

      if (qq == colqp1) {
        qjj = 3;
      } else if (i + 1 == qq) {
        qjj = 1;
      } else {
        qjj = 2;
        colqp1 = qq;
      }
    }

    switch (qjj) {
     case 1:
      nrm = e[i - 1];
      e[i - 1] = 0.0;
      for (qq = i; qq >= colqp1 + 1; qq--) {
        STQMEKF_xrotg(s_0[qq - 1], nrm, &s_0[qq - 1], &nrm, &ztest, &sqds);
        if (qq > colqp1 + 1) {
          nrm = -sqds * e[0];
          e[0] *= ztest;
        }

        STQMEKF_xrot_ps(Vf, 3 * (qq - 1) + 1, 3 * i + 1, ztest, sqds);
      }
      break;

     case 2:
      nrm = e[colqp1 - 1];
      e[colqp1 - 1] = 0.0;
      for (qq = colqp1 + 1; qq <= i + 1; qq++) {
        STQMEKF_xrotg(s_0[qq - 1], nrm, &s_0[qq - 1], &ztest, &sqds, &b);
        ztest = e[qq - 1];
        nrm = -b * ztest;
        e[qq - 1] = ztest * sqds;
        STQMEKF_xrot_psj(U, ((qq - 1) << 3) + 1, ((colqp1 - 1) << 3) + 1, sqds,
                         b);
      }
      break;

     case 3:
      ztest = fabs(s_0[i]);
      sqds = s_0[i - 1];
      nrm = fabs(sqds);
      if ((ztest >= nrm) || rtIsNaN(nrm)) {
        nrm = ztest;
      }

      b = e[i - 1];
      ztest = fabs(b);
      if ((nrm >= ztest) || rtIsNaN(ztest)) {
        ztest = nrm;
      }

      nrm = fabs(s_0[colqp1]);
      if ((ztest >= nrm) || rtIsNaN(nrm)) {
        nrm = ztest;
      }

      ztest = fabs(e[colqp1]);
      if ((nrm >= ztest) || rtIsNaN(ztest)) {
        ztest = nrm;
      }

      nrm = s_0[i] / ztest;
      smm1 = sqds / ztest;
      emm1 = b / ztest;
      sqds = s_0[colqp1] / ztest;
      b = ((smm1 + nrm) * (smm1 - nrm) + emm1 * emm1) / 2.0;
      smm1 = nrm * emm1;
      smm1 *= smm1;
      if ((b != 0.0) || (smm1 != 0.0)) {
        emm1 = sqrt(b * b + smm1);
        if (b < 0.0) {
          emm1 = -emm1;
        }

        emm1 = smm1 / (b + emm1);
      } else {
        emm1 = 0.0;
      }

      nrm = (sqds + nrm) * (sqds - nrm) + emm1;
      ztest = e[colqp1] / ztest * sqds;
      for (qq = colqp1 + 1; qq <= i; qq++) {
        STQMEKF_xrotg(nrm, ztest, &smm1, &emm1, &sqds, &b);
        if (qq > colqp1 + 1) {
          e[0] = smm1;
        }

        smm1 = e[qq - 1];
        nrm = s_0[qq - 1];
        e[qq - 1] = smm1 * sqds - nrm * b;
        ztest = b * s_0[qq];
        s_0[qq] *= sqds;
        STQMEKF_xrot_ps(Vf, 3 * (qq - 1) + 1, 3 * qq + 1, sqds, b);
        STQMEKF_xrotg(nrm * sqds + smm1 * b, ztest, &s_0[qq - 1], &a__3, &emm1,
                      &d_sn);
        smm1 = e[qq - 1];
        nrm = smm1 * emm1 + d_sn * s_0[qq];
        s_0[qq] = smm1 * -d_sn + emm1 * s_0[qq];
        ztest = d_sn * e[qq];
        e[qq] *= emm1;
        STQMEKF_xrot_psj(U, ((qq - 1) << 3) + 1, (qq << 3) + 1, emm1, d_sn);
      }

      e[i - 1] = nrm;
      qp1++;
      break;

     default:
      if (s_0[colqp1] < 0.0) {
        s_0[colqp1] = -s_0[colqp1];
        qq = 3 * colqp1;
        for (qjj = qq + 1; qjj <= qq + 3; qjj++) {
          Vf[qjj - 1] = -Vf[qjj - 1];
        }
      }

      qp1 = colqp1 + 1;
      while ((colqp1 + 1 < 3) && (s_0[colqp1] < s_0[qp1])) {
        nrm = s_0[colqp1];
        s_0[colqp1] = s_0[qp1];
        s_0[qp1] = nrm;
        STQMEKF_xswap_dj(Vf, 3 * colqp1 + 1, 3 * (colqp1 + 1) + 1);
        STQMEKF_xswap_dj5(U, (colqp1 << 3) + 1, ((colqp1 + 1) << 3) + 1);
        colqp1 = qp1;
        qp1++;
      }

      qp1 = 0;
      i--;
      break;
    }
  }

  s[0] = s_0[0];
  s[1] = s_0[1];
  s[2] = s_0[2];
  if (doscale) {
    // Start for MATLABSystem: '<S231>/Pseudoinverse1'
    STQMEKF_xzlascl_i(cscale, anrm, s);
  }

  for (i = 0; i < 3; i++) {
    V[3 * i] = Vf[3 * i];
    qp1 = 3 * i + 1;
    V[qp1] = Vf[qp1];
    qp1 = 3 * i + 2;
    V[qp1] = Vf[qp1];
  }
}

// System initialize for atomic system:
void STQMEKF_Pseudoinverse1_Init(DW_Pseudoinverse1_STQMEKF_T *localDW)
{
  // Start for MATLABSystem: '<S231>/Pseudoinverse1'
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
}

// Output and update for atomic system:
void STQMEKF_Pseudoinverse1(const real_T rtu_0[24], B_Pseudoinverse1_STQMEKF_T
  *localB)
{
  real_T A[24];
  real_T U[24];
  real_T X[24];
  real_T V[9];
  real_T s[3];
  real_T absx;
  int32_T ar;
  int32_T b_exponent;
  int32_T b_k;
  int32_T br;
  int32_T d;
  int32_T f;
  int32_T i;
  int32_T vcol;
  boolean_T b[24];
  boolean_T b_0[24];
  boolean_T exitg1;
  boolean_T y;

  // MATLABSystem: '<S231>/Pseudoinverse1'
  for (i = 0; i < 24; i++) {
    // Start for MATLABSystem: '<S231>/Pseudoinverse1'
    absx = rtu_0[i];
    b[i] = rtIsInf(absx);
    b_0[i] = rtIsNaN(absx);
  }

  y = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 24)) {
    if (b[b_k] || b_0[b_k]) {
      y = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (y) {
    for (i = 0; i < 3; i++) {
      for (b_k = 0; b_k < 8; b_k++) {
        A[b_k + (i << 3)] = rtu_0[3 * b_k + i];
      }
    }

    y = true;
    for (b_k = 0; b_k < 24; b_k++) {
      X[b_k] = 0.0;
      if (y) {
        absx = A[b_k];
        if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
        } else {
          y = false;
        }
      } else {
        y = false;
      }
    }

    if (!y) {
      for (i = 0; i < 24; i++) {
        X[i] = (rtNaN);
      }
    } else {
      STQMEKF_svd(A, U, s, V);
      absx = fabs(s[0]);
      if (rtIsInf(absx) || rtIsNaN(absx)) {
        absx = (rtNaN);
      } else if (absx < 4.4501477170144028E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &b_exponent);
        absx = ldexp(1.0, b_exponent - 53);
      }

      absx *= 8.0;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 3)) {
        if (rtIsInf(s[i]) || rtIsNaN(s[i])) {
          absx = 1.7976931348623157E+308;
          exitg1 = true;
        } else {
          i++;
        }
      }

      i = -1;
      b_k = 0;
      while ((b_k < 3) && (s[b_k] > absx)) {
        i++;
        b_k++;
      }

      if (i + 1 > 0) {
        vcol = 3;
        for (b_k = 0; b_k <= i; b_k++) {
          absx = 1.0 / s[b_k];
          for (b_exponent = vcol - 2; b_exponent <= vcol; b_exponent++) {
            V[b_exponent - 1] *= absx;
          }

          vcol += 3;
        }

        for (b_k = 0; b_k <= 21; b_k += 3) {
          for (b_exponent = b_k + 1; b_exponent <= b_k + 3; b_exponent++) {
            X[b_exponent - 1] = 0.0;
          }
        }

        br = 0;
        for (b_k = 0; b_k <= 21; b_k += 3) {
          ar = 0;
          br++;
          d = (i << 3) + br;
          for (b_exponent = br; b_exponent <= d; b_exponent += 8) {
            f = b_k + 3;
            for (vcol = b_k + 1; vcol <= f; vcol++) {
              X[vcol - 1] += V[((ar + vcol) - b_k) - 1] * U[b_exponent - 1];
            }

            ar += 3;
          }
        }
      }
    }

    for (i = 0; i < 3; i++) {
      for (b_k = 0; b_k < 8; b_k++) {
        localB->Pseudoinverse1[b_k + (i << 3)] = X[3 * b_k + i];
      }
    }
  } else {
    memset(&localB->Pseudoinverse1[0], 0, 24U * sizeof(real_T));
  }

  // End of MATLABSystem: '<S231>/Pseudoinverse1'
}

// Function for MATLAB Function: '<S228>/MATLAB Function1'
static real_T STQMEKF_maximum(const real_T x[8])
{
  real_T ex;
  int32_T idx;
  int32_T k;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    for (k = idx + 1; k < 9; k++) {
      real_T x_0;
      x_0 = x[k - 1];
      if (ex < x_0) {
        ex = x_0;
      }
    }
  }

  return ex;
}

//
// Output and update for atomic system:
//    '<S228>/MATLAB Function1'
//    '<S240>/MATLAB Function1'
//    '<S252>/MATLAB Function8'
//
void STQMEKF_MATLABFunction1(const real_T rtu_ThrustPer[8], real_T
  rty_ThrustPer_Final[8])
{
  real_T TControl;
  real_T ThrustPer_Sat;
  real_T maxval;
  int32_T i;
  TControl = 1.0 / STQMEKF_P.PWMFreq;
  maxval = STQMEKF_maximum(rtu_ThrustPer);
  for (i = 0; i < 8; i++) {
    if (maxval > 1.0) {
      ThrustPer_Sat = rtu_ThrustPer[i] / maxval;
    } else {
      ThrustPer_Sat = rtu_ThrustPer[i];
    }

    if (ThrustPer_Sat > 0.007 / TControl) {
      rty_ThrustPer_Final[i] = ThrustPer_Sat;
    } else {
      rty_ThrustPer_Final[i] = 0.0;
    }
  }
}

//
// Output and update for atomic system:
//    '<S234>/Create Rotation Matrix'
//    '<S246>/Create Rotation Matrix'
//    '<S258>/Create Rotation Matrix'
//
void STQMEKF_CreateRotationMatrix(real_T rtu_Rz, real_T rty_C_Ib[4])
{
  real_T x_tmp;
  real_T x_tmp_0;
  x_tmp = sin(rtu_Rz);
  x_tmp_0 = cos(rtu_Rz);
  if (fabs(-x_tmp) > fabs(x_tmp_0)) {
    real_T r_tmp;
    real_T t;
    r_tmp = x_tmp_0 / -x_tmp;
    t = 1.0 / (r_tmp * x_tmp_0 - x_tmp);
    x_tmp_0 = r_tmp * t;
    rty_C_Ib[0] = x_tmp_0;
    rty_C_Ib[1] = -t;
    rty_C_Ib[2] = -x_tmp / -x_tmp * t;
    rty_C_Ib[3] = x_tmp_0;
  } else {
    real_T r_tmp;
    real_T t;
    r_tmp = -x_tmp / x_tmp_0;
    t = 1.0 / (x_tmp_0 - r_tmp * x_tmp);
    rty_C_Ib[0] = x_tmp_0 / x_tmp_0 * t;
    rty_C_Ib[1] = -r_tmp * t;
    rty_C_Ib[2] = r_tmp * t;
    rty_C_Ib[3] = t;
  }
}

//
// Output and update for atomic system:
//    '<S229>/Create Rotation Matrix'
//    '<S241>/Create Rotation Matrix'
//    '<S253>/Create Rotation Matrix'
//
void STQMEKF_CreateRotationMatrix_a(real_T rtu_Rz, real_T rty_C_bI[4])
{
  real_T tmp;
  real_T tmp_0;
  tmp = sin(rtu_Rz);
  tmp_0 = cos(rtu_Rz);
  rty_C_bI[0] = tmp_0;
  rty_C_bI[2] = tmp;
  rty_C_bI[1] = -tmp;
  rty_C_bI[3] = tmp_0;
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static real_T STQMEKF_norm(const real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static real_T STQMEKF_norm_h(const real_T x[81])
{
  real_T y;
  int32_T j;
  boolean_T exitg1;
  y = 0.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 9)) {
    real_T s;
    s = 0.0;
    for (int32_T i = 0; i < 9; i++) {
      s += fabs(x[9 * j + i]);
    }

    if (rtIsNaN(s)) {
      y = (rtNaN);
      exitg1 = true;
    } else {
      if (s > y) {
        y = s;
      }

      j++;
    }
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_mpower(const real_T a[81], real_T b, real_T c[81])
{
  real_T aBuffer[81];
  real_T b_a[81];
  real_T cBuffer[81];
  real_T cBuffer_0[81];
  real_T cBuffer_1[81];
  real_T e;
  e = fabs(b);
  if (e <= 2.147483647E+9) {
    int32_T b_n;
    int32_T n;
    int32_T nb;
    int32_T nbitson;
    memcpy(&b_a[0], &a[0], 81U * sizeof(real_T));
    n = static_cast<int32_T>(e);
    b_n = static_cast<int32_T>(e);
    nbitson = 0;
    nb = -2;
    while (b_n > 0) {
      nb++;
      if ((static_cast<uint32_T>(b_n) & 1U) != 0U) {
        nbitson++;
      }

      b_n >>= 1;
    }

    if (static_cast<int32_T>(e) <= 2) {
      if (b == 2.0) {
        for (b_n = 0; b_n < 9; b_n++) {
          for (nbitson = 0; nbitson < 9; nbitson++) {
            e = 0.0;
            for (int32_T i = 0; i < 9; i++) {
              e += a[9 * i + nbitson] * a[9 * b_n + i];
            }

            c[nbitson + 9 * b_n] = e;
          }
        }
      } else {
        boolean_T firstmult;
        firstmult = false;
        for (n = 0; n < 81; n++) {
          if (!firstmult) {
            firstmult = rtIsNaN(a[n]);
          }
        }

        if (firstmult) {
          for (b_n = 0; b_n < 81; b_n++) {
            c[b_n] = (rtNaN);
          }
        } else {
          memset(&c[0], 0, 81U * sizeof(real_T));
          for (n = 0; n < 9; n++) {
            c[n + 9 * n] = 1.0;
          }
        }
      }
    } else {
      real_T ed2;
      boolean_T aBufferInUse;
      boolean_T cBufferInUse;
      boolean_T firstmult;
      firstmult = true;
      aBufferInUse = false;
      cBufferInUse = ((static_cast<uint32_T>(nbitson) & 1U) == 0U);
      for (int32_T k = 0; k <= nb; k++) {
        if ((static_cast<uint32_T>(n) & 1U) != 0U) {
          if (firstmult) {
            firstmult = false;
            if (cBufferInUse) {
              if (aBufferInUse) {
                memcpy(&cBuffer[0], &aBuffer[0], 81U * sizeof(real_T));
              } else {
                memcpy(&cBuffer[0], &b_a[0], 81U * sizeof(real_T));
              }
            } else if (aBufferInUse) {
              memcpy(&c[0], &aBuffer[0], 81U * sizeof(real_T));
            } else {
              memcpy(&c[0], &b_a[0], 81U * sizeof(real_T));
            }
          } else {
            if (aBufferInUse) {
              if (cBufferInUse) {
                for (b_n = 0; b_n < 9; b_n++) {
                  for (nbitson = 0; nbitson < 9; nbitson++) {
                    e = 0.0;
                    for (int32_T i = 0; i < 9; i++) {
                      e += cBuffer[9 * i + b_n] * aBuffer[9 * nbitson + i];
                    }

                    c[b_n + 9 * nbitson] = e;
                  }
                }
              } else {
                for (b_n = 0; b_n < 9; b_n++) {
                  for (nbitson = 0; nbitson < 9; nbitson++) {
                    e = 0.0;
                    for (int32_T i = 0; i < 9; i++) {
                      e += c[9 * i + b_n] * aBuffer[9 * nbitson + i];
                    }

                    cBuffer[b_n + 9 * nbitson] = e;
                  }
                }
              }
            } else if (cBufferInUse) {
              for (b_n = 0; b_n < 9; b_n++) {
                for (nbitson = 0; nbitson < 9; nbitson++) {
                  e = 0.0;
                  for (int32_T i = 0; i < 9; i++) {
                    e += cBuffer[9 * i + b_n] * b_a[9 * nbitson + i];
                  }

                  c[b_n + 9 * nbitson] = e;
                }
              }
            } else {
              for (b_n = 0; b_n < 9; b_n++) {
                for (nbitson = 0; nbitson < 9; nbitson++) {
                  e = 0.0;
                  for (int32_T i = 0; i < 9; i++) {
                    e += c[9 * i + b_n] * b_a[9 * nbitson + i];
                  }

                  cBuffer[b_n + 9 * nbitson] = e;
                }
              }
            }

            cBufferInUse = !cBufferInUse;
          }
        }

        n >>= 1;
        if (aBufferInUse) {
          for (b_n = 0; b_n < 9; b_n++) {
            for (nbitson = 0; nbitson < 9; nbitson++) {
              ed2 = 0.0;
              for (int32_T i = 0; i < 9; i++) {
                ed2 += aBuffer[9 * i + b_n] * aBuffer[9 * nbitson + i];
              }

              b_a[b_n + 9 * nbitson] = ed2;
            }
          }
        } else {
          for (b_n = 0; b_n < 9; b_n++) {
            for (nbitson = 0; nbitson < 9; nbitson++) {
              e = 0.0;
              for (int32_T i = 0; i < 9; i++) {
                e += b_a[9 * i + b_n] * b_a[9 * nbitson + i];
              }

              aBuffer[b_n + 9 * nbitson] = e;
            }
          }
        }

        aBufferInUse = !aBufferInUse;
      }

      for (b_n = 0; b_n < 9; b_n++) {
        for (nbitson = 0; nbitson < 9; nbitson++) {
          e = 0.0;
          ed2 = 0.0;
          for (int32_T i = 0; i < 9; i++) {
            real_T cBuffer_2;
            cBuffer_2 = cBuffer[9 * i + nbitson];
            n = 9 * b_n + i;
            e += aBuffer[n] * cBuffer_2;
            ed2 += b_a[n] * cBuffer_2;
          }

          n = 9 * b_n + nbitson;
          cBuffer_1[n] = ed2;
          cBuffer_0[n] = e;
        }
      }

      for (b_n = 0; b_n < 81; b_n++) {
        if (firstmult) {
          if (aBufferInUse) {
            c[b_n] = aBuffer[b_n];
          } else {
            c[b_n] = b_a[b_n];
          }
        } else if (aBufferInUse) {
          c[b_n] = cBuffer_0[b_n];
        } else {
          c[b_n] = cBuffer_1[b_n];
        }
      }
    }
  } else {
    memcpy(&b_a[0], &a[0], 81U * sizeof(real_T));
    if ((!rtIsInf(b)) && (!rtIsNaN(b))) {
      boolean_T firstmult;
      firstmult = true;
      real_T ed2;
      int32_T exitg1;
      do {
        exitg1 = 0;
        ed2 = floor(e / 2.0);
        if (2.0 * ed2 != e) {
          if (firstmult) {
            memcpy(&c[0], &b_a[0], 81U * sizeof(real_T));
            firstmult = false;
          } else {
            for (int32_T b_n = 0; b_n < 9; b_n++) {
              for (int32_T nbitson = 0; nbitson < 9; nbitson++) {
                e = 0.0;
                for (int32_T i = 0; i < 9; i++) {
                  e += c[9 * i + b_n] * b_a[9 * nbitson + i];
                }

                cBuffer[b_n + 9 * nbitson] = e;
              }
            }

            memcpy(&c[0], &cBuffer[0], 81U * sizeof(real_T));
          }
        }

        if (ed2 == 0.0) {
          exitg1 = 1;
        } else {
          e = ed2;
          for (int32_T b_n = 0; b_n < 9; b_n++) {
            for (int32_T nbitson = 0; nbitson < 9; nbitson++) {
              ed2 = 0.0;
              for (int32_T i = 0; i < 9; i++) {
                ed2 += b_a[9 * i + b_n] * b_a[9 * nbitson + i];
              }

              cBuffer[b_n + 9 * nbitson] = ed2;
            }
          }

          memcpy(&b_a[0], &cBuffer[0], 81U * sizeof(real_T));
        }
      } while (exitg1 == 0);
    } else {
      for (int32_T b_n = 0; b_n < 81; b_n++) {
        c[b_n] = (rtNaN);
      }
    }
  }
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static real_T STQMEKF_log2(real_T x)
{
  real_T f;
  int32_T inte;
  if (x == 0.0) {
    f = (rtMinusInf);
  } else if ((!rtIsInf(x)) && (!rtIsNaN(x))) {
    real_T t;
    t = frexp(x, &inte);
    if (t == 0.5) {
      f = static_cast<real_T>(inte) - 1.0;
    } else if ((inte == 1) && (t < 0.75)) {
      f = log(2.0 * t) / 0.69314718055994529;
    } else {
      f = log(t) / 0.69314718055994529 + static_cast<real_T>(inte);
    }
  } else {
    f = x;
  }

  return f;
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_padeApproximation(const real_T A[81], const real_T A2[81],
  const real_T A4[81], const real_T A6[81], int32_T m, real_T F[81])
{
  real_T A6_0[81];
  real_T V[81];
  real_T d;
  int32_T e_k;
  int32_T jA;
  int32_T jBcol;
  int32_T jj;
  int32_T kAcol;
  int8_T ipiv[9];
  switch (m) {
   case 3:
    memcpy(&F[0], &A2[0], 81U * sizeof(real_T));
    for (e_k = 0; e_k < 9; e_k++) {
      jj = 9 * e_k + e_k;
      F[jj] += 60.0;
    }

    for (e_k = 0; e_k < 9; e_k++) {
      for (jj = 0; jj < 9; jj++) {
        d = 0.0;
        for (jA = 0; jA < 9; jA++) {
          d += A[9 * jA + jj] * F[9 * e_k + jA];
        }

        A6_0[jj + 9 * e_k] = d;
      }
    }

    for (e_k = 0; e_k < 81; e_k++) {
      F[e_k] = A6_0[e_k];
      V[e_k] = 12.0 * A2[e_k];
    }

    d = 120.0;
    break;

   case 5:
    for (e_k = 0; e_k < 81; e_k++) {
      F[e_k] = 420.0 * A2[e_k] + A4[e_k];
    }

    for (e_k = 0; e_k < 9; e_k++) {
      jj = 9 * e_k + e_k;
      F[jj] += 15120.0;
    }

    for (e_k = 0; e_k < 9; e_k++) {
      for (jj = 0; jj < 9; jj++) {
        d = 0.0;
        for (jA = 0; jA < 9; jA++) {
          d += A[9 * jA + jj] * F[9 * e_k + jA];
        }

        A6_0[jj + 9 * e_k] = d;
      }
    }

    for (e_k = 0; e_k < 81; e_k++) {
      F[e_k] = A6_0[e_k];
      V[e_k] = 30.0 * A4[e_k] + 3360.0 * A2[e_k];
    }

    d = 30240.0;
    break;

   case 7:
    for (e_k = 0; e_k < 81; e_k++) {
      F[e_k] = (1512.0 * A4[e_k] + A6[e_k]) + 277200.0 * A2[e_k];
    }

    for (e_k = 0; e_k < 9; e_k++) {
      jj = 9 * e_k + e_k;
      F[jj] += 8.64864E+6;
    }

    for (e_k = 0; e_k < 9; e_k++) {
      for (jj = 0; jj < 9; jj++) {
        d = 0.0;
        for (jA = 0; jA < 9; jA++) {
          d += A[9 * jA + jj] * F[9 * e_k + jA];
        }

        A6_0[jj + 9 * e_k] = d;
      }
    }

    for (e_k = 0; e_k < 81; e_k++) {
      F[e_k] = A6_0[e_k];
      V[e_k] = (56.0 * A6[e_k] + 25200.0 * A4[e_k]) + 1.99584E+6 * A2[e_k];
    }

    d = 1.729728E+7;
    break;

   case 9:
    for (e_k = 0; e_k < 9; e_k++) {
      for (jj = 0; jj < 9; jj++) {
        d = 0.0;
        for (jA = 0; jA < 9; jA++) {
          d += A6[9 * jA + jj] * A2[9 * e_k + jA];
        }

        V[jj + 9 * e_k] = d;
      }
    }

    for (e_k = 0; e_k < 81; e_k++) {
      F[e_k] = ((3960.0 * A6[e_k] + V[e_k]) + 2.16216E+6 * A4[e_k]) +
        3.027024E+8 * A2[e_k];
    }

    for (e_k = 0; e_k < 9; e_k++) {
      jj = 9 * e_k + e_k;
      F[jj] += 8.8216128E+9;
    }

    for (e_k = 0; e_k < 9; e_k++) {
      for (jj = 0; jj < 9; jj++) {
        d = 0.0;
        for (jA = 0; jA < 9; jA++) {
          d += A[9 * jA + jj] * F[9 * e_k + jA];
        }

        A6_0[jj + 9 * e_k] = d;
      }
    }

    for (e_k = 0; e_k < 81; e_k++) {
      F[e_k] = A6_0[e_k];
      V[e_k] = ((90.0 * V[e_k] + 110880.0 * A6[e_k]) + 3.027024E+7 * A4[e_k]) +
        2.0756736E+9 * A2[e_k];
    }

    d = 1.76432256E+10;
    break;

   default:
    for (e_k = 0; e_k < 81; e_k++) {
      F[e_k] = (3.352212864E+10 * A6[e_k] + 1.05594705216E+13 * A4[e_k]) +
        1.1873537964288E+15 * A2[e_k];
    }

    for (e_k = 0; e_k < 9; e_k++) {
      jj = 9 * e_k + e_k;
      F[jj] += 3.238237626624E+16;
    }

    for (e_k = 0; e_k < 81; e_k++) {
      V[e_k] = (16380.0 * A4[e_k] + A6[e_k]) + 4.08408E+7 * A2[e_k];
    }

    for (e_k = 0; e_k < 9; e_k++) {
      for (jj = 0; jj < 9; jj++) {
        d = 0.0;
        for (jA = 0; jA < 9; jA++) {
          d += A6[9 * jA + e_k] * V[9 * jj + jA];
        }

        jA = 9 * jj + e_k;
        A6_0[jA] = F[jA] + d;
      }
    }

    for (e_k = 0; e_k < 9; e_k++) {
      for (jj = 0; jj < 9; jj++) {
        d = 0.0;
        for (jA = 0; jA < 9; jA++) {
          d += A[9 * jA + jj] * A6_0[9 * e_k + jA];
        }

        F[jj + 9 * e_k] = d;
      }
    }

    for (e_k = 0; e_k < 81; e_k++) {
      A6_0[e_k] = (182.0 * A6[e_k] + 960960.0 * A4[e_k]) + 1.32324192E+9 *
        A2[e_k];
    }

    for (e_k = 0; e_k < 9; e_k++) {
      for (jj = 0; jj < 9; jj++) {
        d = 0.0;
        for (jA = 0; jA < 9; jA++) {
          d += A6[9 * jA + e_k] * A6_0[9 * jj + jA];
        }

        jA = 9 * jj + e_k;
        V[jA] = ((A6[jA] * 6.704425728E+11 + d) + A4[jA] * 1.29060195264E+14) +
          A2[jA] * 7.7717703038976E+15;
      }
    }

    d = 6.476475253248E+16;
    break;
  }

  for (jj = 0; jj < 9; jj++) {
    jA = 9 * jj + jj;
    V[jA] += d;
  }

  for (jj = 0; jj < 81; jj++) {
    d = F[jj];
    V[jj] -= d;
    F[jj] = 2.0 * d;
  }

  for (e_k = 0; e_k < 9; e_k++) {
    ipiv[e_k] = static_cast<int8_T>(e_k + 1);
  }

  for (e_k = 0; e_k < 8; e_k++) {
    int8_T ipiv_0;
    jj = e_k * 10;
    jA = 8 - e_k;
    jBcol = 0;
    d = fabs(V[jj]);
    for (int32_T k_k = 2; k_k <= jA + 1; k_k++) {
      real_T s;
      s = fabs(V[(jj + k_k) - 1]);
      if (s > d) {
        jBcol = k_k - 1;
        d = s;
      }
    }

    if (V[jj + jBcol] != 0.0) {
      if (jBcol != 0) {
        jBcol += e_k;
        ipiv[e_k] = static_cast<int8_T>(jBcol + 1);
        for (int32_T k_k = 0; k_k < 9; k_k++) {
          kAcol = k_k * 9 + e_k;
          d = V[kAcol];
          jA = k_k * 9 + jBcol;
          V[kAcol] = V[jA];
          V[jA] = d;
        }
      }

      jA = (jj - e_k) + 9;
      for (jBcol = jj + 2; jBcol <= jA; jBcol++) {
        V[jBcol - 1] /= V[jj];
      }
    }

    jA = jj + 11;
    jBcol = 7 - e_k;
    for (int32_T k_k = 0; k_k <= jBcol; k_k++) {
      d = V[(k_k * 9 + jj) + 9];
      if (d != 0.0) {
        kAcol = (jA - e_k) + 7;
        for (int32_T ijA = jA; ijA <= kAcol; ijA++) {
          V[ijA - 1] += V[((jj + ijA) - jA) + 1] * -d;
        }
      }

      jA += 9;
    }

    ipiv_0 = ipiv[e_k];
    if (e_k + 1 != ipiv_0) {
      for (jA = 0; jA < 9; jA++) {
        jBcol = 9 * jA + e_k;
        d = F[jBcol];
        jj = (9 * jA + ipiv_0) - 1;
        F[jBcol] = F[jj];
        F[jj] = d;
      }
    }
  }

  for (jA = 0; jA < 9; jA++) {
    jBcol = 9 * jA;
    for (int32_T k_k = 0; k_k < 9; k_k++) {
      kAcol = 9 * k_k;
      e_k = k_k + jBcol;
      if (F[e_k] != 0.0) {
        for (int32_T ijA = k_k + 2; ijA < 10; ijA++) {
          jj = (ijA + jBcol) - 1;
          F[jj] -= V[(ijA + kAcol) - 1] * F[e_k];
        }
      }
    }
  }

  for (jA = 0; jA < 9; jA++) {
    jBcol = 9 * jA;
    for (int32_T k_k = 8; k_k >= 0; k_k--) {
      kAcol = 9 * k_k;
      e_k = k_k + jBcol;
      d = F[e_k];
      if (d != 0.0) {
        F[e_k] = d / V[k_k + kAcol];
        for (int32_T ijA = 0; ijA < k_k; ijA++) {
          jj = ijA + jBcol;
          F[jj] -= V[ijA + kAcol] * F[e_k];
        }
      }
    }
  }

  for (e_k = 0; e_k < 9; e_k++) {
    jj = 9 * e_k + e_k;
    F[jj]++;
  }
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_recomputeBlockDiag(const real_T A[81], real_T F[81], const
  int32_T blockFormat[8])
{
  for (int32_T j = 0; j < 8; j++) {
    switch (blockFormat[j]) {
     case 0:
      break;

     case 1:
      {
        real_T A_0;
        real_T delta;
        real_T expa;
        real_T sinchdelta;
        real_T u1;
        real_T x12;
        int32_T A_tmp;
        int32_T A_tmp_0;
        A_tmp_0 = 9 * j + j;
        x12 = A[A_tmp_0];
        expa = exp(x12);
        A_tmp = (j + 1) * 9 + j;
        A_0 = A[A_tmp + 1];
        sinchdelta = exp(A_0);
        delta = (A_0 + x12) / 2.0;
        u1 = fabs(x12 - A_0) / 2.0;
        if ((delta >= u1) || rtIsNaN(u1)) {
          u1 = delta;
        }

        if (u1 < 709.782712893384) {
          x12 = (A_0 - x12) / 2.0;
          if (x12 == 0.0) {
            x12 = 1.0;
          } else {
            x12 = sinh(x12) / x12;
          }

          x12 *= A[A_tmp] * exp(delta);
        } else {
          x12 = (sinchdelta - expa) * A[A_tmp] / (A_0 - x12);
        }

        F[A_tmp_0] = expa;
        F[A_tmp] = x12;
        F[A_tmp + 1] = sinchdelta;
      }
      break;

     default:
      {
        real_T A_0;
        real_T delta;
        real_T expa;
        real_T sinchdelta;
        real_T x12;
        int32_T A_tmp;
        int32_T A_tmp_0;
        A_tmp_0 = (j + 1) * 9 + j;
        x12 = A[A_tmp_0];
        A_tmp = 9 * j + j;
        A_0 = A[A_tmp + 1];
        delta = sqrt(fabs(x12 * A_0));
        expa = exp(A[A_tmp]);
        if (delta == 0.0) {
          sinchdelta = 1.0;
        } else {
          sinchdelta = sin(delta) / delta;
        }

        delta = expa * cos(delta);
        F[A_tmp] = delta;
        F[A_tmp + 1] = A_0 * expa * sinchdelta;
        F[A_tmp_0] = x12 * expa * sinchdelta;
        F[A_tmp_0 + 1] = delta;
      }
      break;
    }
  }

  if (blockFormat[7] == 0) {
    F[80] = exp(A[80]);
  }
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static real_T STQMEKF_xnrm2_pp(int32_T n, const real_T x[81], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = ix0 + n;
      for (int32_T k = ix0; k < kend; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_xzsyhetrd(real_T A[81], real_T D[9], real_T E[8], real_T
  tau[8])
{
  real_T tau_tmp;
  real_T taui;
  real_T temp2;
  real_T xnorm;
  int32_T alpha_tmp_tmp_tmp;
  int32_T b_jj;
  int32_T d_k;
  int32_T h;
  int32_T i;
  int32_T ii;
  int32_T ix0;
  int32_T knt;
  int32_T tau_tmp_tmp;
  for (i = 0; i < 8; i++) {
    alpha_tmp_tmp_tmp = 9 * i + i;
    temp2 = A[alpha_tmp_tmp_tmp + 1];
    if (i + 3 <= 9) {
      b_jj = i + 3;
    } else {
      b_jj = 9;
    }

    ix0 = i * 9 + b_jj;
    taui = 0.0;
    xnorm = STQMEKF_xnrm2_pp(7 - i, A, ix0);
    if (xnorm != 0.0) {
      xnorm = rt_hypotd_snf(temp2, xnorm);
      if (temp2 >= 0.0) {
        xnorm = -xnorm;
      }

      if (fabs(xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        h = (ix0 - i) + 6;
        do {
          knt++;
          for (d_k = ix0; d_k <= h; d_k++) {
            A[d_k - 1] *= 9.9792015476736E+291;
          }

          xnorm *= 9.9792015476736E+291;
          temp2 *= 9.9792015476736E+291;
        } while ((fabs(xnorm) < 1.0020841800044864E-292) && (knt < 20));

        xnorm = rt_hypotd_snf(temp2, STQMEKF_xnrm2_pp(7 - i, A, ix0));
        if (temp2 >= 0.0) {
          xnorm = -xnorm;
        }

        taui = (xnorm - temp2) / xnorm;
        temp2 = 1.0 / (temp2 - xnorm);
        for (d_k = ix0; d_k <= h; d_k++) {
          A[d_k - 1] *= temp2;
        }

        for (ix0 = 0; ix0 < knt; ix0++) {
          xnorm *= 1.0020841800044864E-292;
        }

        temp2 = xnorm;
      } else {
        taui = (xnorm - temp2) / xnorm;
        temp2 = 1.0 / (temp2 - xnorm);
        h = (ix0 - i) + 6;
        for (knt = ix0; knt <= h; knt++) {
          A[knt - 1] *= temp2;
        }

        temp2 = xnorm;
      }
    }

    E[i] = temp2;
    if (taui != 0.0) {
      A[alpha_tmp_tmp_tmp + 1] = 1.0;
      for (ix0 = i + 1; ix0 < 9; ix0++) {
        tau[ix0 - 1] = 0.0;
      }

      ix0 = 7 - i;
      knt = 9 - i;
      for (b_jj = 0; b_jj <= ix0; b_jj++) {
        h = i + b_jj;
        xnorm = A[(9 * i + h) + 1] * taui;
        temp2 = 0.0;
        d_k = (h + 1) * 9 + i;
        tau[h] += A[(d_k + b_jj) + 1] * xnorm;
        for (ii = b_jj + 2; ii < knt; ii++) {
          tau_tmp_tmp = i + ii;
          tau_tmp = A[d_k + ii];
          tau[tau_tmp_tmp - 1] += tau_tmp * xnorm;
          temp2 += A[9 * i + tau_tmp_tmp] * tau_tmp;
        }

        tau[h] += taui * temp2;
      }

      xnorm = 0.0;
      h = 8 - i;
      for (d_k = 0; d_k < h; d_k++) {
        xnorm += A[(alpha_tmp_tmp_tmp + d_k) + 1] * tau[i + d_k];
      }

      xnorm *= -0.5 * taui;
      if (!(xnorm == 0.0)) {
        for (b_jj = 0; b_jj < h; b_jj++) {
          d_k = i + b_jj;
          tau[d_k] += A[(alpha_tmp_tmp_tmp + b_jj) + 1] * xnorm;
        }
      }

      for (d_k = 0; d_k <= ix0; d_k++) {
        h = i + d_k;
        xnorm = A[(9 * i + h) + 1];
        temp2 = tau[h];
        tau_tmp = temp2 * xnorm;
        b_jj = (h + 1) * 9;
        ii = b_jj + i;
        A[(h + b_jj) + 1] = (A[(ii + d_k) + 1] - tau_tmp) - tau_tmp;
        for (h = d_k + 2; h < knt; h++) {
          tau_tmp_tmp = i + h;
          A[tau_tmp_tmp + b_jj] = (A[ii + h] - tau[tau_tmp_tmp - 1] * xnorm) -
            A[9 * i + tau_tmp_tmp] * temp2;
        }
      }
    }

    A[alpha_tmp_tmp_tmp + 1] = E[i];
    D[i] = A[alpha_tmp_tmp_tmp];
    tau[i] = taui;
  }

  D[8] = A[80];
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_xzlascl_l(real_T cfrom, real_T cto, int32_T m, real_T A[9],
  int32_T iA0)
{
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    real_T cfrom1;
    real_T cto1;
    real_T mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }

    for (int32_T b_i = 0; b_i < m; b_i++) {
      int32_T tmp;
      tmp = (b_i + iA0) - 1;
      A[tmp] *= mul;
    }
  }
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_xzlascl_lr(real_T cfrom, real_T cto, int32_T m, real_T A[8],
  int32_T iA0)
{
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    real_T cfrom1;
    real_T cto1;
    real_T mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }

    for (int32_T b_i = 0; b_i < m; b_i++) {
      int32_T tmp;
      tmp = (b_i + iA0) - 1;
      A[tmp] *= mul;
    }
  }
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_xzlartg(real_T f, real_T g, real_T *cs, real_T *sn, real_T
  *r)
{
  real_T f1;
  real_T g1;
  f1 = fabs(f);
  g1 = fabs(g);
  if (g == 0.0) {
    *cs = 1.0;
    *sn = 0.0;
    *r = f;
  } else if (f == 0.0) {
    *cs = 0.0;
    if (g >= 0.0) {
      *sn = 1.0;
    } else {
      *sn = -1.0;
    }

    *r = g1;
  } else if ((f1 > 1.4916681462400413E-154) && (f1 < 4.7403759540545887E+153) &&
             (g1 > 1.4916681462400413E-154) && (g1 < 4.7403759540545887E+153)) {
    *r = sqrt(f * f + g * g);
    *cs = f1 / *r;
    if (!(f >= 0.0)) {
      *r = -*r;
    }

    *sn = g / *r;
  } else {
    real_T fs;
    if ((f1 >= g1) || rtIsNaN(g1)) {
      g1 = f1;
    }

    if ((g1 <= 2.2250738585072014E-308) || rtIsNaN(g1)) {
      g1 = 2.2250738585072014E-308;
    }

    if (g1 >= 4.49423283715579E+307) {
      g1 = 4.49423283715579E+307;
    }

    fs = f / g1;
    f1 = g / g1;
    *r = sqrt(fs * fs + f1 * f1);
    *cs = fabs(fs) / *r;
    if (!(f >= 0.0)) {
      *r = -*r;
    }

    *sn = f1 / *r;
    *r *= g1;
  }
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_rotateRight_b(int32_T n, real_T z[81], int32_T iz0, const
  real_T cs[16], int32_T ic0, int32_T is0)
{
  for (int32_T b_j = 0; b_j <= n - 2; b_j++) {
    real_T ctemp;
    real_T stemp;
    int32_T offsetj;
    int32_T offsetjp1;
    ctemp = cs[(ic0 + b_j) - 1];
    stemp = cs[(is0 + b_j) - 1];
    offsetj = (b_j * 9 + iz0) - 1;
    offsetjp1 = ((b_j + 1) * 9 + iz0) - 1;
    if ((ctemp != 1.0) || (stemp != 0.0)) {
      for (int32_T i = 0; i < 9; i++) {
        real_T temp;
        int32_T temp_tmp;
        int32_T tmp;
        temp_tmp = offsetjp1 + i;
        temp = z[temp_tmp];
        tmp = offsetj + i;
        z[temp_tmp] = ctemp * temp - z[tmp] * stemp;
        z[tmp] = z[tmp] * ctemp + stemp * temp;
      }
    }
  }
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_xdlaev2(real_T a, real_T b, real_T c, real_T *rt1, real_T
  *rt2, real_T *cs1, real_T *sn1)
{
  real_T ab;
  real_T acmn;
  real_T acmx;
  real_T adf;
  real_T df;
  real_T sm;
  real_T tb;
  int32_T sgn1;
  int32_T sgn2;
  sm = a + c;
  df = a - c;
  adf = fabs(df);
  tb = b + b;
  ab = fabs(tb);
  if (fabs(a) > fabs(c)) {
    acmx = a;
    acmn = c;
  } else {
    acmx = c;
    acmn = a;
  }

  if (adf > ab) {
    real_T b_a;
    b_a = ab / adf;
    adf *= sqrt(b_a * b_a + 1.0);
  } else if (adf < ab) {
    adf /= ab;
    adf = sqrt(adf * adf + 1.0) * ab;
  } else {
    adf = ab * 1.4142135623730951;
  }

  if (sm < 0.0) {
    *rt1 = (sm - adf) * 0.5;
    sgn1 = -1;
    *rt2 = acmx / *rt1 * acmn - b / *rt1 * b;
  } else if (sm > 0.0) {
    *rt1 = (sm + adf) * 0.5;
    sgn1 = 1;
    *rt2 = acmx / *rt1 * acmn - b / *rt1 * b;
  } else {
    *rt1 = 0.5 * adf;
    *rt2 = -0.5 * adf;
    sgn1 = 1;
  }

  if (df >= 0.0) {
    df += adf;
    sgn2 = 1;
  } else {
    df -= adf;
    sgn2 = -1;
  }

  if (fabs(df) > ab) {
    tb = -tb / df;
    *sn1 = 1.0 / sqrt(tb * tb + 1.0);
    *cs1 = tb * *sn1;
  } else if (ab == 0.0) {
    *cs1 = 1.0;
    *sn1 = 0.0;
  } else {
    tb = -df / tb;
    *cs1 = 1.0 / sqrt(tb * tb + 1.0);
    *sn1 = tb * *cs1;
  }

  if (sgn1 == sgn2) {
    tb = *cs1;
    *cs1 = -*sn1;
    *sn1 = tb;
  }
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_rotateRight(int32_T n, real_T z[81], int32_T iz0, const
  real_T cs[16], int32_T ic0, int32_T is0)
{
  for (int32_T j = n - 1; j >= 1; j--) {
    real_T ctemp;
    real_T stemp;
    int32_T offsetj;
    int32_T offsetjp1;
    ctemp = cs[(ic0 + j) - 2];
    stemp = cs[(is0 + j) - 2];
    offsetj = ((j - 1) * 9 + iz0) - 1;
    offsetjp1 = (j * 9 + iz0) - 1;
    if ((ctemp != 1.0) || (stemp != 0.0)) {
      for (int32_T i = 0; i < 9; i++) {
        real_T temp;
        int32_T temp_tmp;
        int32_T tmp;
        temp_tmp = offsetjp1 + i;
        temp = z[temp_tmp];
        tmp = offsetj + i;
        z[temp_tmp] = ctemp * temp - z[tmp] * stemp;
        z[tmp] = z[tmp] * ctemp + stemp * temp;
      }
    }
  }
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static int32_T STQMEKF_xzsteqr(real_T d[9], real_T e[8], real_T z[81])
{
  real_T work[16];
  real_T b;
  real_T b_anorm;
  real_T b_r;
  real_T b_s;
  real_T c;
  real_T p;
  real_T r;
  real_T s;
  real_T tst;
  int32_T b_anorm_tmp;
  int32_T exitg1;
  int32_T exitg3;
  int32_T exitg4;
  int32_T i;
  int32_T info;
  int32_T iscale;
  int32_T l;
  int32_T l1;
  int32_T lend;
  int32_T lendsv;
  int32_T lsv;
  int32_T m;
  int32_T n_tmp;
  boolean_T exitg2;
  info = 0;
  memset(&work[0], 0, sizeof(real_T) << 4U);
  i = 0;
  l1 = 1;
  do {
    exitg1 = 0;
    if (l1 > 9) {
      for (i = 0; i < 8; i++) {
        m = i;
        p = d[i];
        for (l1 = i + 2; l1 < 10; l1++) {
          tst = d[l1 - 1];
          if (tst < p) {
            m = l1 - 1;
            p = tst;
          }
        }

        if (m != i) {
          d[m] = d[i];
          d[i] = p;
          lsv = i * 9;
          l = m * 9;
          for (l1 = 0; l1 < 9; l1++) {
            lend = lsv + l1;
            tst = z[lend];
            m = l + l1;
            z[lend] = z[m];
            z[m] = tst;
          }
        }
      }

      exitg1 = 1;
    } else {
      if (l1 > 1) {
        e[l1 - 2] = 0.0;
      }

      m = l1;
      exitg2 = false;
      while ((!exitg2) && (m < 9)) {
        tst = fabs(e[m - 1]);
        if (tst == 0.0) {
          exitg2 = true;
        } else if (tst <= sqrt(fabs(d[m - 1])) * sqrt(fabs(d[m])) *
                   2.2204460492503131E-16) {
          e[m - 1] = 0.0;
          exitg2 = true;
        } else {
          m++;
        }
      }

      l = l1 - 1;
      lsv = l1;
      lend = m;
      lendsv = m;
      l1 = m + 1;
      if (l + 1 == m) {
      } else {
        n_tmp = m - l;
        if (n_tmp <= 0) {
          tst = 0.0;
        } else {
          tst = fabs(d[(l + n_tmp) - 1]);
          iscale = 0;
          exitg2 = false;
          while ((!exitg2) && (iscale <= n_tmp - 2)) {
            b_anorm_tmp = l + iscale;
            b_anorm = fabs(d[b_anorm_tmp]);
            if (rtIsNaN(b_anorm)) {
              tst = (rtNaN);
              exitg2 = true;
            } else {
              if (b_anorm > tst) {
                tst = b_anorm;
              }

              b_anorm = fabs(e[b_anorm_tmp]);
              if (rtIsNaN(b_anorm)) {
                tst = (rtNaN);
                exitg2 = true;
              } else {
                if (b_anorm > tst) {
                  tst = b_anorm;
                }

                iscale++;
              }
            }
          }
        }

        iscale = 0;
        if (tst == 0.0) {
        } else if (rtIsInf(tst) || rtIsNaN(tst)) {
          for (i = 0; i < 9; i++) {
            d[i] = (rtNaN);
          }

          for (m = 0; m < 81; m++) {
            z[m] = (rtNaN);
          }

          exitg1 = 1;
        } else {
          if (tst > 2.2346346549904327E+153) {
            iscale = 1;
            STQMEKF_xzlascl_l(tst, 2.2346346549904327E+153, n_tmp, d, l + 1);
            STQMEKF_xzlascl_lr(tst, 2.2346346549904327E+153, n_tmp - 1, e, l + 1);
          } else if (tst < 3.02546243347603E-123) {
            iscale = 2;
            STQMEKF_xzlascl_l(tst, 3.02546243347603E-123, n_tmp, d, l + 1);
            STQMEKF_xzlascl_lr(tst, 3.02546243347603E-123, n_tmp - 1, e, l + 1);
          }

          if (fabs(d[m - 1]) < fabs(d[l])) {
            lend = lsv;
            l = m - 1;
          }

          if (lend > l + 1) {
            do {
              exitg4 = 0;
              if (l + 1 != lend) {
                m = l;
                exitg2 = false;
                while ((!exitg2) && (m + 1 < lend)) {
                  b_anorm = fabs(e[m]);
                  if (b_anorm * b_anorm <= 4.9303806576313238E-32 * fabs(d[m]) *
                      fabs(d[m + 1]) + 2.2250738585072014E-308) {
                    exitg2 = true;
                  } else {
                    m++;
                  }
                }
              } else {
                m = lend - 1;
              }

              if (m + 1 < lend) {
                e[m] = 0.0;
              }

              if (m + 1 == l + 1) {
                l++;
                if (l + 1 > lend) {
                  exitg4 = 1;
                }
              } else if (m + 1 == l + 2) {
                STQMEKF_xdlaev2(d[l], e[l], d[l + 1], &d[l], &b_anorm, &work[l],
                                &p);
                d[l + 1] = b_anorm;
                work[l + 8] = p;
                STQMEKF_rotateRight(2, z, l * 9 + 1, work, l + 1, l + 9);
                e[l] = 0.0;
                l += 2;
                if (l + 1 > lend) {
                  exitg4 = 1;
                }
              } else if (i == 270) {
                exitg4 = 1;
              } else {
                i++;
                b_anorm = (d[l + 1] - d[l]) / (2.0 * e[l]);
                p = rt_hypotd_snf(b_anorm, 1.0);
                if (!(b_anorm >= 0.0)) {
                  p = -p;
                }

                b_anorm = e[l] / (b_anorm + p) + (d[m] - d[l]);
                s = 1.0;
                c = 1.0;
                p = 0.0;
                for (n_tmp = m; n_tmp >= l + 1; n_tmp--) {
                  r = e[n_tmp - 1];
                  b = c * r;
                  STQMEKF_xzlartg(b_anorm, s * r, &c, &b_s, &b_r);
                  s = b_s;
                  if (n_tmp != m) {
                    e[n_tmp] = b_r;
                  }

                  b_anorm = d[n_tmp] - p;
                  r = (d[n_tmp - 1] - b_anorm) * b_s + 2.0 * c * b;
                  p = b_s * r;
                  d[n_tmp] = b_anorm + p;
                  b_anorm = c * r - b;
                  work[n_tmp - 1] = c;
                  work[n_tmp + 7] = -b_s;
                }

                STQMEKF_rotateRight((m - l) + 1, z, l * 9 + 1, work, l + 1, l +
                                    9);
                d[l] -= p;
                e[l] = b_anorm;
              }
            } while (exitg4 == 0);
          } else {
            do {
              exitg3 = 0;
              if (l + 1 != lend) {
                m = l + 1;
                exitg2 = false;
                while ((!exitg2) && (m > lend)) {
                  b_anorm = fabs(e[m - 2]);
                  if (b_anorm * b_anorm <= fabs(d[m - 1]) *
                      4.9303806576313238E-32 * fabs(d[m - 2]) +
                      2.2250738585072014E-308) {
                    exitg2 = true;
                  } else {
                    m--;
                  }
                }
              } else {
                m = lend;
              }

              if (m > lend) {
                e[m - 2] = 0.0;
              }

              if (l + 1 == m) {
                l--;
                if (l + 1 < lend) {
                  exitg3 = 1;
                }
              } else if (m == l) {
                STQMEKF_xdlaev2(d[l - 1], e[l - 1], d[l], &d[l - 1], &b_anorm,
                                &work[m - 1], &p);
                d[l] = b_anorm;
                work[m + 7] = p;
                STQMEKF_rotateRight_b(2, z, (l - 1) * 9 + 1, work, m, m + 8);
                e[l - 1] = 0.0;
                l -= 2;
                if (l + 1 < lend) {
                  exitg3 = 1;
                }
              } else if (i == 270) {
                exitg3 = 1;
              } else {
                i++;
                p = e[l - 1];
                b_anorm = (d[l - 1] - d[l]) / (p * 2.0);
                s = rt_hypotd_snf(b_anorm, 1.0);
                if (!(b_anorm >= 0.0)) {
                  s = -s;
                }

                b_anorm = (d[m - 1] - d[l]) + p / (b_anorm + s);
                s = 1.0;
                c = 1.0;
                p = 0.0;
                for (n_tmp = m; n_tmp <= l; n_tmp++) {
                  r = e[n_tmp - 1];
                  b = c * r;
                  STQMEKF_xzlartg(b_anorm, s * r, &c, &b_s, &b_r);
                  s = b_s;
                  if (n_tmp != m) {
                    e[n_tmp - 2] = b_r;
                  }

                  b_anorm = d[n_tmp - 1] - p;
                  r = (d[n_tmp] - b_anorm) * b_s + 2.0 * c * b;
                  p = b_s * r;
                  d[n_tmp - 1] = b_anorm + p;
                  b_anorm = c * r - b;
                  work[n_tmp - 1] = c;
                  work[n_tmp + 7] = b_s;
                }

                STQMEKF_rotateRight_b((l - m) + 2, z, (m - 1) * 9 + 1, work, m,
                                      m + 8);
                d[l] -= p;
                e[l - 1] = b_anorm;
              }
            } while (exitg3 == 0);
          }

          switch (iscale) {
           case 1:
            m = lendsv - lsv;
            STQMEKF_xzlascl_l(2.2346346549904327E+153, tst, m + 1, d, lsv);
            STQMEKF_xzlascl_lr(2.2346346549904327E+153, tst, m, e, lsv);
            break;

           case 2:
            m = lendsv - lsv;
            STQMEKF_xzlascl_l(3.02546243347603E-123, tst, m + 1, d, lsv);
            STQMEKF_xzlascl_lr(3.02546243347603E-123, tst, m, e, lsv);
            break;
          }

          if (i >= 270) {
            for (i = 0; i < 8; i++) {
              if (e[i] != 0.0) {
                info++;
              }
            }

            exitg1 = 1;
          }
        }
      }
    }
  } while (exitg1 == 0);

  return info;
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_xsyheev(real_T A[81], int32_T *info, real_T W[9])
{
  real_T work[9];
  real_T e[8];
  real_T tau[8];
  real_T absx;
  real_T anrm;
  real_T cfrom1;
  real_T cfromc;
  real_T cto1;
  real_T mul;
  int32_T b_ia;
  int32_T coltop;
  int32_T e_i;
  int32_T exitg1;
  int32_T f;
  int32_T iaii;
  int32_T jA;
  int32_T lastc;
  int32_T lastv;
  boolean_T exitg2;
  boolean_T guard1;
  boolean_T iscale;
  boolean_T notdone;
  *info = 0;
  anrm = 0.0;
  iaii = 0;
  exitg2 = false;
  while ((!exitg2) && (iaii < 9)) {
    e_i = 0;
    do {
      exitg1 = 0;
      if (e_i <= iaii) {
        absx = fabs(A[9 * iaii + e_i]);
        if (rtIsNaN(absx)) {
          anrm = (rtNaN);
          exitg1 = 1;
        } else {
          if (absx > anrm) {
            anrm = absx;
          }

          e_i++;
        }
      } else {
        iaii++;
        exitg1 = 2;
      }
    } while (exitg1 == 0);

    if (exitg1 == 1) {
      exitg2 = true;
    }
  }

  if (rtIsInf(anrm) || rtIsNaN(anrm)) {
    for (e_i = 0; e_i < 9; e_i++) {
      W[e_i] = (rtNaN);
    }

    for (e_i = 0; e_i < 81; e_i++) {
      A[e_i] = (rtNaN);
    }
  } else {
    iscale = false;
    guard1 = false;
    if ((anrm > 0.0) && (anrm < 1.0010415475915505E-146)) {
      iscale = true;
      anrm = 1.0010415475915505E-146 / anrm;
      guard1 = true;
    } else if (anrm > 9.9895953610111751E+145) {
      iscale = true;
      anrm = 9.9895953610111751E+145 / anrm;
      guard1 = true;
    }

    if (guard1) {
      absx = anrm;
      cfromc = 1.0;
      notdone = true;
      while (notdone) {
        cfrom1 = cfromc * 2.0041683600089728E-292;
        cto1 = absx / 4.9896007738368E+291;
        if ((fabs(cfrom1) > absx) && (absx != 0.0)) {
          mul = 2.0041683600089728E-292;
          cfromc = cfrom1;
        } else if (cto1 > fabs(cfromc)) {
          mul = 4.9896007738368E+291;
          absx = cto1;
        } else {
          mul = absx / cfromc;
          notdone = false;
        }

        for (e_i = 0; e_i < 81; e_i++) {
          A[e_i] *= mul;
        }
      }
    }

    STQMEKF_xzsyhetrd(A, W, e, tau);
    for (iaii = 7; iaii >= 0; iaii--) {
      e_i = (iaii + 1) * 9;
      A[e_i] = 0.0;
      for (lastv = iaii + 3; lastv < 10; lastv++) {
        A[(lastv + e_i) - 1] = A[(9 * iaii + lastv) - 1];
      }
    }

    A[0] = 1.0;
    memset(&A[1], 0, sizeof(real_T) << 3U);
    memset(&work[0], 0, 9U * sizeof(real_T));
    for (e_i = 7; e_i >= 0; e_i--) {
      iaii = (e_i * 9 + e_i) + 20;
      if (e_i + 1 < 8) {
        A[iaii - 10] = 1.0;
        if (tau[e_i] != 0.0) {
          lastv = 8 - e_i;
          lastc = iaii - e_i;
          while ((lastv > 0) && (A[lastc - 3] == 0.0)) {
            lastv--;
            lastc--;
          }

          lastc = 7 - e_i;
          exitg2 = false;
          while ((!exitg2) && (lastc > 0)) {
            coltop = (lastc - 1) * 9 + iaii;
            b_ia = coltop;
            do {
              exitg1 = 0;
              if (b_ia <= (coltop + lastv) - 1) {
                if (A[b_ia - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  b_ia++;
                }
              } else {
                lastc--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }

          lastc--;
        } else {
          lastv = 0;
          lastc = -1;
        }

        if (lastv > 0) {
          if (lastc + 1 != 0) {
            memset(&work[0], 0, static_cast<uint32_T>(lastc + 1) * sizeof(real_T));
            b_ia = 9 * lastc + iaii;
            for (coltop = iaii; coltop <= b_ia; coltop += 9) {
              absx = 0.0;
              f = (coltop + lastv) - 1;
              for (jA = coltop; jA <= f; jA++) {
                absx += A[((iaii + jA) - coltop) - 10] * A[jA - 1];
              }

              jA = div_nde_s32_floor(coltop - iaii, 9);
              work[jA] += absx;
            }
          }

          if (!(-tau[e_i] == 0.0)) {
            jA = iaii;
            for (coltop = 0; coltop <= lastc; coltop++) {
              absx = work[coltop];
              if (absx != 0.0) {
                absx *= -tau[e_i];
                f = (lastv + jA) - 1;
                for (b_ia = jA; b_ia <= f; b_ia++) {
                  A[b_ia - 1] += A[((iaii + b_ia) - jA) - 10] * absx;
                }
              }

              jA += 9;
            }
          }
        }

        lastc = (iaii - e_i) - 2;
        for (lastv = iaii - 8; lastv <= lastc; lastv++) {
          A[lastv - 1] *= -tau[e_i];
        }
      }

      A[iaii - 10] = 1.0 - tau[e_i];
      for (lastv = 0; lastv < e_i; lastv++) {
        A[(iaii - lastv) - 11] = 0.0;
      }
    }

    *info = STQMEKF_xzsteqr(W, e, A);
    if (*info != 0) {
      for (e_i = 0; e_i < 9; e_i++) {
        W[e_i] = (rtNaN);
      }

      for (e_i = 0; e_i < 81; e_i++) {
        A[e_i] = (rtNaN);
      }
    } else if (iscale) {
      anrm = 1.0 / anrm;
      for (e_i = 0; e_i < 9; e_i++) {
        W[e_i] *= anrm;
      }
    }
  }
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_prop(const real_T x[13], real_T dt, real_T x_new[13], real_T
  F[144], real_T G[72])
{
  real_T A[81];
  real_T A2[81];
  real_T A4[81];
  real_T A6[81];
  real_T Phi_m[81];
  real_T T[81];
  real_T q[16];
  real_T A_tmp[9];
  real_T w[9];
  real_T q_new[4];
  real_T vector[3];
  real_T a;
  real_T absxk;
  real_T eta1;
  real_T omega_norm;
  real_T q_idx_2;
  real_T t;
  real_T theta;
  real_T x_0;
  int32_T blockFormat[8];
  int32_T b_k;
  int32_T b_s;
  int32_T e_i;
  int32_T e_j;
  int32_T q_tmp;
  int8_T q_new_tmp[9];
  boolean_T recomputeDiags;
  static const int8_T c_b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const real_T e[27] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2,
    0.2, 0.2 };

  static const int8_T f[36] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T g[36] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T tmp[81];
  int32_T exitg1;
  boolean_T exitg2;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T guard3;
  boolean_T guard4;
  omega_norm = STQMEKF_norm(&x[4]);
  if (omega_norm > 1.0E-10) {
    theta = omega_norm * dt / 2.0;
    a = sin(theta);
    theta = cos(theta);
    eta1 = x[4] / omega_norm * a;
    q_idx_2 = x[5] / omega_norm * a;
    omega_norm = x[6] / omega_norm * a;
  } else {
    theta = 1.0;
    eta1 = 0.0;
    q_idx_2 = 0.0;
    omega_norm = 0.0;
  }

  vector[0] = eta1;
  vector[1] = q_idx_2;
  vector[2] = omega_norm;
  for (e_j = 0; e_j < 9; e_j++) {
    q_new_tmp[e_j] = c_b[e_j];
  }

  A_tmp[0] = 0.0;
  A_tmp[3] = -omega_norm;
  A_tmp[6] = q_idx_2;
  A_tmp[1] = omega_norm;
  A_tmp[4] = 0.0;
  A_tmp[7] = -eta1;
  A_tmp[2] = -q_idx_2;
  A_tmp[5] = eta1;
  A_tmp[8] = 0.0;
  q[0] = theta;
  for (e_j = 0; e_j < 3; e_j++) {
    omega_norm = vector[e_j];
    e_i = (e_j + 1) << 2;
    q[e_i] = -omega_norm;
    q[e_j + 1] = omega_norm;
    q[e_i + 1] = static_cast<real_T>(q_new_tmp[3 * e_j]) * theta + A_tmp[3 * e_j];
    q_tmp = 3 * e_j + 1;
    q[e_i + 2] = static_cast<real_T>(q_new_tmp[q_tmp]) * theta + A_tmp[q_tmp];
    q_tmp = 3 * e_j + 2;
    q[e_i + 3] = static_cast<real_T>(q_new_tmp[q_tmp]) * theta + A_tmp[q_tmp];
  }

  theta = 0.0;
  omega_norm = 3.3121686421112381E-170;
  eta1 = x[1];
  q_idx_2 = x[0];
  a = x[2];
  x_0 = x[3];
  for (e_j = 0; e_j < 4; e_j++) {
    absxk = ((q[e_j + 4] * eta1 + q[e_j] * q_idx_2) + q[e_j + 8] * a) + q[e_j +
      12] * x_0;
    q_new[e_j] = absxk;
    absxk = fabs(absxk);
    if (absxk > omega_norm) {
      t = omega_norm / absxk;
      theta = theta * t * t + 1.0;
      omega_norm = absxk;
    } else {
      t = absxk / omega_norm;
      theta += t * t;
    }
  }

  theta = omega_norm * sqrt(theta);
  x_new[0] = q_new[0] / theta;
  x_new[1] = q_new[1] / theta;
  x_new[2] = q_new[2] / theta;
  x_new[3] = q_new[3] / theta;
  x_new[4] = x[4];
  x_new[7] = x[10] * dt + x[7];
  x_new[10] = x[10];
  x_new[5] = x[5];
  x_new[8] = x[11] * dt + x[8];
  x_new[11] = x[11];
  x_new[6] = x[6];
  x_new[9] = x[12] * dt + x[9];
  x_new[12] = x[12];
  for (e_j = 0; e_j < 9; e_j++) {
    A_tmp[e_j] = static_cast<real_T>(q_new_tmp[e_j]) * dt;
  }

  A[0] = -0.0 * dt;
  A[9] = x[6] / 2.0 * dt;
  A[18] = -x[5] / 2.0 * dt;
  A[1] = -x[6] / 2.0 * dt;
  A[10] = -0.0 * dt;
  A[19] = x[4] / 2.0 * dt;
  A[2] = x[5] / 2.0 * dt;
  A[11] = -x[4] / 2.0 * dt;
  A[20] = -0.0 * dt;
  for (e_j = 0; e_j < 3; e_j++) {
    e_i = (e_j + 3) * 9;
    A[e_i] = A_tmp[3 * e_j];
    q_tmp = (e_j + 6) * 9;
    A[q_tmp] = 0.0 * dt;
    A[e_i + 1] = A_tmp[3 * e_j + 1];
    A[q_tmp + 1] = 0.0 * dt;
    A[e_i + 2] = A_tmp[3 * e_j + 2];
    A[q_tmp + 2] = 0.0 * dt;
  }

  for (e_j = 0; e_j < 9; e_j++) {
    A[9 * e_j + 3] = e[3 * e_j] * dt;
    A[9 * e_j + 6] = 0.0 * dt;
    A[9 * e_j + 4] = e[3 * e_j + 1] * dt;
    A[9 * e_j + 7] = 0.0 * dt;
    A[9 * e_j + 5] = e[3 * e_j + 2] * dt;
    A[9 * e_j + 8] = 0.0 * dt;
  }

  recomputeDiags = true;
  for (e_j = 0; e_j < 81; e_j++) {
    if (recomputeDiags) {
      theta = A[e_j];
      if (rtIsInf(theta) || rtIsNaN(theta)) {
        recomputeDiags = false;
      }
    }
  }

  if (!recomputeDiags) {
    for (e_j = 0; e_j < 81; e_j++) {
      Phi_m[e_j] = (rtNaN);
    }
  } else {
    recomputeDiags = true;
    e_j = 0;
    exitg2 = false;
    while ((!exitg2) && (e_j < 9)) {
      e_i = 0;
      do {
        exitg1 = 0;
        if (e_i < 9) {
          if ((e_i != e_j) && (!(A[9 * e_j + e_i] == 0.0))) {
            recomputeDiags = false;
            exitg1 = 1;
          } else {
            e_i++;
          }
        } else {
          e_j++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (recomputeDiags) {
      memset(&Phi_m[0], 0, 81U * sizeof(real_T));
      for (e_j = 0; e_j < 9; e_j++) {
        b_s = 9 * e_j + e_j;
        Phi_m[b_s] = exp(A[b_s]);
      }
    } else {
      recomputeDiags = true;
      e_j = 0;
      exitg2 = false;
      while ((!exitg2) && (e_j < 9)) {
        e_i = 0;
        do {
          exitg1 = 0;
          if (e_i <= e_j) {
            if (!(A[9 * e_j + e_i] == A[9 * e_i + e_j])) {
              recomputeDiags = false;
              exitg1 = 1;
            } else {
              e_i++;
            }
          } else {
            e_j++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      if (recomputeDiags) {
        STQMEKF_xsyheev(A, &b_s, w);
        for (e_j = 0; e_j < 9; e_j++) {
          theta = exp(w[e_j]);
          for (e_i = 0; e_i < 9; e_i++) {
            b_s = 9 * e_j + e_i;
            Phi_m[b_s] = A[b_s] * theta;
          }
        }

        for (e_j = 0; e_j < 9; e_j++) {
          for (e_i = 0; e_i < 9; e_i++) {
            theta = 0.0;
            for (q_tmp = 0; q_tmp < 9; q_tmp++) {
              theta += Phi_m[9 * q_tmp + e_j] * A[9 * q_tmp + e_i];
            }

            A2[e_j + 9 * e_i] = theta;
          }
        }

        memcpy(&Phi_m[0], &A2[0], 81U * sizeof(real_T));
        for (e_j = 0; e_j < 9; e_j++) {
          for (e_i = 0; e_i < 9; e_i++) {
            b_s = 9 * e_j + e_i;
            A2[b_s] = (Phi_m[9 * e_i + e_j] + Phi_m[b_s]) / 2.0;
          }
        }

        memcpy(&Phi_m[0], &A2[0], 81U * sizeof(real_T));
      } else {
        recomputeDiags = true;
        e_j = 3;
        while (recomputeDiags && (e_j <= 9)) {
          e_i = e_j;
          while (recomputeDiags && (e_i <= 9)) {
            recomputeDiags = (A[((e_j - 3) * 9 + e_i) - 1] == 0.0);
            e_i++;
          }

          e_j++;
        }

        if (recomputeDiags) {
          q_tmp = 1;
          exitg2 = false;
          while ((!exitg2) && (q_tmp - 1 < 8)) {
            e_j = (q_tmp - 1) * 9 + q_tmp;
            omega_norm = A[e_j];
            if (omega_norm != 0.0) {
              if ((q_tmp != 8) && (A[(9 * q_tmp + q_tmp) + 1] != 0.0)) {
                recomputeDiags = false;
                exitg2 = true;
              } else {
                e_i = 9 * q_tmp + q_tmp;
                if (A[e_j - 1] != A[e_i]) {
                  recomputeDiags = false;
                  exitg2 = true;
                } else {
                  theta = A[e_i - 1];
                  if (rtIsNaN(omega_norm)) {
                    omega_norm = (rtNaN);
                  } else if (omega_norm < 0.0) {
                    omega_norm = -1.0;
                  } else {
                    omega_norm = (omega_norm > 0.0);
                  }

                  if (rtIsNaN(theta)) {
                    theta = (rtNaN);
                  } else if (theta < 0.0) {
                    theta = -1.0;
                  } else {
                    theta = (theta > 0.0);
                  }

                  if (omega_norm * theta != -1.0) {
                    recomputeDiags = false;
                    exitg2 = true;
                  } else {
                    q_tmp++;
                  }
                }
              }
            } else {
              q_tmp++;
            }
          }
        }

        theta = 0.0;
        for (e_j = 0; e_j < 9; e_j++) {
          for (e_i = 0; e_i < 9; e_i++) {
            omega_norm = 0.0;
            for (q_tmp = 0; q_tmp < 9; q_tmp++) {
              omega_norm += A[9 * q_tmp + e_i] * A[9 * e_j + q_tmp];
            }

            A2[e_i + 9 * e_j] = omega_norm;
          }
        }

        for (e_j = 0; e_j < 9; e_j++) {
          for (e_i = 0; e_i < 9; e_i++) {
            q_idx_2 = 0.0;
            for (q_tmp = 0; q_tmp < 9; q_tmp++) {
              q_idx_2 += A2[9 * q_tmp + e_j] * A2[9 * e_i + q_tmp];
            }

            A4[e_j + 9 * e_i] = q_idx_2;
          }

          for (e_i = 0; e_i < 9; e_i++) {
            omega_norm = 0.0;
            for (q_tmp = 0; q_tmp < 9; q_tmp++) {
              omega_norm += A4[9 * q_tmp + e_j] * A2[9 * e_i + q_tmp];
            }

            A6[e_j + 9 * e_i] = omega_norm;
          }
        }

        omega_norm = rt_powd_snf(STQMEKF_norm_h(A6), 0.16666666666666666);
        eta1 = rt_powd_snf(STQMEKF_norm_h(A4), 0.25);
        if ((!(eta1 >= omega_norm)) && (!rtIsNaN(omega_norm))) {
          eta1 = omega_norm;
        }

        guard1 = false;
        guard2 = false;
        guard3 = false;
        guard4 = false;
        if (eta1 <= 0.01495585217958292) {
          for (e_j = 0; e_j < 81; e_j++) {
            Phi_m[e_j] = 0.19285012468241128 * fabs(A[e_j]);
          }

          STQMEKF_mpower(Phi_m, 7.0, tmp);
          q_idx_2 = ceil(STQMEKF_log2(STQMEKF_norm_h(tmp) / STQMEKF_norm_h(A) *
            2.0 / 2.2204460492503131E-16) / 6.0);
          if (!(q_idx_2 >= 0.0)) {
            q_idx_2 = 0.0;
          }

          if (q_idx_2 == 0.0) {
            b_s = 3;
          } else {
            guard4 = true;
          }
        } else {
          guard4 = true;
        }

        if (guard4) {
          if (eta1 <= 0.253939833006323) {
            for (e_j = 0; e_j < 81; e_j++) {
              Phi_m[e_j] = 0.12321872304378752 * fabs(A[e_j]);
            }

            STQMEKF_mpower(Phi_m, 11.0, tmp);
            q_idx_2 = ceil(STQMEKF_log2(STQMEKF_norm_h(tmp) / STQMEKF_norm_h(A) *
              2.0 / 2.2204460492503131E-16) / 10.0);
            if (!(q_idx_2 >= 0.0)) {
              q_idx_2 = 0.0;
            }

            if (q_idx_2 == 0.0) {
              b_s = 5;
            } else {
              guard3 = true;
            }
          } else {
            guard3 = true;
          }
        }

        if (guard3) {
          STQMEKF_mpower(A4, 2.0, tmp);
          eta1 = rt_powd_snf(STQMEKF_norm_h(tmp), 0.125);
          if ((!(omega_norm >= eta1)) && (!rtIsNaN(eta1))) {
            omega_norm = eta1;
          }

          if (omega_norm <= 0.95041789961629319) {
            for (e_j = 0; e_j < 81; e_j++) {
              Phi_m[e_j] = 0.090475336558796943 * fabs(A[e_j]);
            }

            STQMEKF_mpower(Phi_m, 15.0, tmp);
            q_idx_2 = ceil(STQMEKF_log2(STQMEKF_norm_h(tmp) / STQMEKF_norm_h(A) *
              2.0 / 2.2204460492503131E-16) / 14.0);
            if (!(q_idx_2 >= 0.0)) {
              q_idx_2 = 0.0;
            }

            if (q_idx_2 == 0.0) {
              b_s = 7;
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }
        }

        if (guard2) {
          if (omega_norm <= 2.097847961257068) {
            for (e_j = 0; e_j < 81; e_j++) {
              Phi_m[e_j] = 0.071467735648795785 * fabs(A[e_j]);
            }

            STQMEKF_mpower(Phi_m, 19.0, tmp);
            q_idx_2 = ceil(STQMEKF_log2(STQMEKF_norm_h(tmp) / STQMEKF_norm_h(A) *
              2.0 / 2.2204460492503131E-16) / 18.0);
            if (!(q_idx_2 >= 0.0)) {
              q_idx_2 = 0.0;
            }

            if (q_idx_2 == 0.0) {
              b_s = 9;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }
        }

        if (guard1) {
          for (e_j = 0; e_j < 9; e_j++) {
            for (e_i = 0; e_i < 9; e_i++) {
              q_idx_2 = 0.0;
              for (q_tmp = 0; q_tmp < 9; q_tmp++) {
                q_idx_2 += A4[9 * q_tmp + e_i] * A6[9 * e_j + q_tmp];
              }

              Phi_m[e_i + 9 * e_j] = q_idx_2;
            }
          }

          q_idx_2 = rt_powd_snf(STQMEKF_norm_h(Phi_m), 0.1);
          if ((eta1 >= q_idx_2) || rtIsNaN(q_idx_2)) {
            q_idx_2 = eta1;
          }

          if ((omega_norm <= q_idx_2) || rtIsNaN(q_idx_2)) {
            q_idx_2 = omega_norm;
          }

          q_idx_2 = ceil(STQMEKF_log2(q_idx_2 / 5.3719203511481517));
          if (q_idx_2 >= 0.0) {
            theta = q_idx_2;
          }

          omega_norm = rt_powd_snf(2.0, theta);
          for (e_j = 0; e_j < 81; e_j++) {
            eta1 = A[e_j] / omega_norm;
            T[e_j] = eta1;
            Phi_m[e_j] = 0.05031554467093536 * fabs(eta1);
          }

          STQMEKF_mpower(Phi_m, 27.0, tmp);
          q_idx_2 = ceil(STQMEKF_log2(STQMEKF_norm_h(tmp) / STQMEKF_norm_h(T) *
            2.0 / 2.2204460492503131E-16) / 26.0);
          if (!(q_idx_2 >= 0.0)) {
            q_idx_2 = 0.0;
          }

          theta += q_idx_2;
          if (rtIsInf(theta)) {
            omega_norm = STQMEKF_norm_h(A) / 5.3719203511481517;
            if ((!rtIsInf(omega_norm)) && (!rtIsNaN(omega_norm))) {
              omega_norm = frexp(omega_norm, &b_s);
            } else {
              b_s = 0;
            }

            theta = b_s;
            if (omega_norm == 0.5) {
              theta = static_cast<real_T>(b_s) - 1.0;
            }
          }

          b_s = 13;
        }

        if (theta != 0.0) {
          omega_norm = rt_powd_snf(2.0, theta);
          eta1 = rt_powd_snf(2.0, 2.0 * theta);
          q_idx_2 = rt_powd_snf(2.0, 4.0 * theta);
          a = rt_powd_snf(2.0, 6.0 * theta);
          for (e_j = 0; e_j < 81; e_j++) {
            A[e_j] /= omega_norm;
            A2[e_j] /= eta1;
            A4[e_j] /= q_idx_2;
            A6[e_j] /= a;
          }
        }

        if (recomputeDiags) {
          for (e_j = 0; e_j < 8; e_j++) {
            blockFormat[e_j] = 0;
          }

          e_j = 0;
          while (e_j + 1 < 8) {
            omega_norm = A[(9 * e_j + e_j) + 1];
            if (omega_norm != 0.0) {
              blockFormat[e_j] = 2;
              blockFormat[e_j + 1] = 0;
              e_j += 2;
            } else if ((omega_norm == 0.0) && (A[((e_j + 1) * 9 + e_j) + 2] ==
                        0.0)) {
              blockFormat[e_j] = 1;
              e_j++;
            } else {
              blockFormat[e_j] = 0;
              e_j++;
            }
          }

          if (A[71] != 0.0) {
            blockFormat[7] = 2;
          } else {
            switch (blockFormat[6]) {
             case 0:
              blockFormat[7] = 1;
              break;

             case 1:
              blockFormat[7] = 1;
              break;
            }
          }
        }

        STQMEKF_padeApproximation(A, A2, A4, A6, b_s, Phi_m);
        if (recomputeDiags) {
          STQMEKF_recomputeBlockDiag(A, Phi_m, blockFormat);
        }

        b_s = static_cast<int32_T>(theta);
        for (b_k = 0; b_k < b_s; b_k++) {
          for (e_j = 0; e_j < 9; e_j++) {
            for (e_i = 0; e_i < 9; e_i++) {
              theta = 0.0;
              for (q_tmp = 0; q_tmp < 9; q_tmp++) {
                theta += Phi_m[9 * q_tmp + e_j] * Phi_m[9 * e_i + q_tmp];
              }

              A2[e_j + 9 * e_i] = theta;
            }
          }

          memcpy(&Phi_m[0], &A2[0], 81U * sizeof(real_T));
          if (recomputeDiags) {
            for (e_j = 0; e_j < 81; e_j++) {
              A[e_j] *= 2.0;
            }

            STQMEKF_recomputeBlockDiag(A, Phi_m, blockFormat);
          }
        }
      }
    }
  }

  for (e_j = 0; e_j < 6; e_j++) {
    F[12 * e_j] = Phi_m[9 * e_j];
    F[12 * e_j + 1] = Phi_m[9 * e_j + 1];
    F[12 * e_j + 2] = Phi_m[9 * e_j + 2];
  }

  for (e_j = 0; e_j < 3; e_j++) {
    b_s = (e_j + 6) * 12;
    F[b_s] = 0.0;
    e_i = (e_j + 9) * 12;
    F[e_i] = 0.0;
    F[b_s + 1] = 0.0;
    F[e_i + 1] = 0.0;
    F[b_s + 2] = 0.0;
    F[e_i + 2] = 0.0;
  }

  for (e_j = 0; e_j < 12; e_j++) {
    F[12 * e_j + 3] = f[3 * e_j];
    F[12 * e_j + 4] = f[3 * e_j + 1];
    F[12 * e_j + 5] = f[3 * e_j + 2];
  }

  for (e_j = 0; e_j < 3; e_j++) {
    F[12 * e_j + 6] = 0.0;
    b_s = (e_j + 3) * 12;
    F[b_s + 6] = 0.0;
    e_i = (e_j + 6) * 12;
    F[e_i + 6] = q_new_tmp[3 * e_j];
    q_tmp = (e_j + 9) * 12;
    F[q_tmp + 6] = A_tmp[3 * e_j];
    F[12 * e_j + 7] = 0.0;
    F[b_s + 7] = 0.0;
    b_k = 3 * e_j + 1;
    F[e_i + 7] = q_new_tmp[b_k];
    F[q_tmp + 7] = A_tmp[b_k];
    F[12 * e_j + 8] = 0.0;
    F[b_s + 8] = 0.0;
    b_s = 3 * e_j + 2;
    F[e_i + 8] = q_new_tmp[b_s];
    F[q_tmp + 8] = A_tmp[b_s];
  }

  for (e_j = 0; e_j < 12; e_j++) {
    F[12 * e_j + 9] = g[3 * e_j];
    F[12 * e_j + 10] = g[3 * e_j + 1];
    F[12 * e_j + 11] = g[3 * e_j + 2];
  }

  theta = dt * dt;
  for (e_j = 0; e_j < 3; e_j++) {
    G[12 * e_j] = 0.0;
    b_s = (e_j + 6) * 9;
    e_i = (e_j + 3) * 12;
    G[e_i] = Phi_m[b_s];
    G[12 * e_j + 3] = 0.0;
    G[e_i + 3] = Phi_m[b_s + 3];
    G[12 * e_j + 6] = static_cast<real_T>(q_new_tmp[3 * e_j]) * theta / 24.0;
    G[e_i + 6] = 0.0;
    G[12 * e_j + 9] = A_tmp[3 * e_j] / 12.0;
    G[e_i + 9] = 0.0;
    G[12 * e_j + 1] = 0.0;
    G[e_i + 1] = Phi_m[b_s + 1];
    G[12 * e_j + 4] = 0.0;
    G[e_i + 4] = Phi_m[b_s + 4];
    q_tmp = 3 * e_j + 1;
    G[12 * e_j + 7] = static_cast<real_T>(q_new_tmp[q_tmp]) * theta / 24.0;
    G[e_i + 7] = 0.0;
    G[12 * e_j + 10] = A_tmp[q_tmp] / 12.0;
    G[e_i + 10] = 0.0;
    G[12 * e_j + 2] = 0.0;
    G[e_i + 2] = Phi_m[b_s + 2];
    G[12 * e_j + 5] = 0.0;
    G[e_i + 5] = Phi_m[b_s + 5];
    b_s = 3 * e_j + 2;
    G[12 * e_j + 8] = static_cast<real_T>(q_new_tmp[b_s]) * theta / 24.0;
    G[e_i + 8] = 0.0;
    G[12 * e_j + 11] = A_tmp[b_s] / 12.0;
    G[e_i + 11] = 0.0;
  }
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_smallQuat(const real_T q[4], real_T p[4])
{
  real_T axis[3];
  real_T a_idx_0;
  real_T a_idx_1;
  real_T angle;
  real_T den;
  real_T p_tmp;
  real_T r;
  boolean_T rEQ0;
  angle = 2.0 * acos(q[0]);
  den = sin(angle / 2.0);
  a_idx_0 = q[1] / den;
  a_idx_1 = q[2] / den;
  den = q[3] / den;
  rEQ0 = rtIsNaN(a_idx_0);
  if (!rEQ0) {
    rEQ0 = rtIsNaN(a_idx_1);
  }

  if (!rEQ0) {
    rEQ0 = rtIsNaN(den);
  }

  if (!rEQ0) {
    rEQ0 = rtIsNaN(angle);
  }

  if (rEQ0) {
    p[0] = 1.0;
    p[1] = 0.0;
    p[2] = 0.0;
    p[3] = 0.0;
  } else {
    if (rtIsNaN(angle + 3.1415926535897931)) {
      r = (rtNaN);
    } else if (rtIsInf(angle + 3.1415926535897931)) {
      r = (rtNaN);
    } else if (angle + 3.1415926535897931 == 0.0) {
      r = 0.0;
    } else {
      r = fmod(angle + 3.1415926535897931, 6.2831853071795862);
      rEQ0 = (r == 0.0);
      if (!rEQ0) {
        angle = fabs((angle + 3.1415926535897931) / 6.2831853071795862);
        rEQ0 = !(fabs(angle - floor(angle + 0.5)) > 2.2204460492503131E-16 *
                 angle);
      }

      if (rEQ0) {
        r = 0.0;
      } else if (r < 0.0) {
        r += 6.2831853071795862;
      }
    }

    axis[0] = a_idx_0;
    axis[1] = a_idx_1;
    axis[2] = den;
    angle = STQMEKF_norm(axis);
    r = (r - 3.1415926535897931) / 2.0;
    p_tmp = sin(r);
    p[0] = cos(r);
    p[1] = a_idx_0 / angle * p_tmp;
    p[2] = a_idx_1 / angle * p_tmp;
    p[3] = den / angle * p_tmp;
  }
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_xzgetrf(real_T A[36], int32_T ipiv[6], int32_T *info)
{
  int32_T k;
  for (k = 0; k < 6; k++) {
    ipiv[k] = k + 1;
  }

  *info = 0;
  for (int32_T j = 0; j < 5; j++) {
    real_T smax;
    int32_T jA;
    int32_T jj;
    int32_T n;
    int32_T temp_tmp;
    jj = j * 7;
    n = 5 - j;
    jA = 0;
    smax = fabs(A[jj]);
    for (k = 2; k <= n + 1; k++) {
      real_T s;
      s = fabs(A[(jj + k) - 1]);
      if (s > smax) {
        jA = k - 1;
        smax = s;
      }
    }

    if (A[jj + jA] != 0.0) {
      if (jA != 0) {
        jA += j;
        ipiv[j] = jA + 1;
        for (n = 0; n < 6; n++) {
          temp_tmp = n * 6 + j;
          smax = A[temp_tmp];
          k = n * 6 + jA;
          A[temp_tmp] = A[k];
          A[k] = smax;
        }
      }

      n = (jj - j) + 6;
      for (k = jj + 2; k <= n; k++) {
        A[k - 1] /= A[jj];
      }
    } else {
      *info = j + 1;
    }

    jA = jj + 8;
    temp_tmp = 4 - j;
    for (k = 0; k <= temp_tmp; k++) {
      smax = A[(k * 6 + jj) + 6];
      if (smax != 0.0) {
        int32_T d;
        d = (jA - j) + 4;
        for (n = jA; n <= d; n++) {
          A[n - 1] += A[((jj + n) - jA) + 1] * -smax;
        }
      }

      jA += 6;
    }
  }

  if ((*info == 0) && (!(A[35] != 0.0))) {
    *info = 6;
  }
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static boolean_T STQMEKF_hasFiniteBounds(boolean_T hasLB[12], boolean_T hasUB[12])
{
  boolean_T hasBounds;
  hasLB[0] = true;
  hasUB[0] = false;
  hasBounds = true;
  for (int32_T idx = 1; idx < 12; idx++) {
    hasLB[idx] = true;
    hasUB[idx] = false;
  }

  return hasBounds;
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_QMEKF_anonFcn1(const real_T P[144], const real_T H[72],
  const real_T R[36], const real_T V[36], const real_T x[12], real_T
  varargout_1[36])
{
  real_T Lambda[144];
  real_T Lambda_0[144];
  real_T Lambda_1[144];
  real_T H_0[72];
  real_T a[36];
  real_T b_x[36];
  real_T Lambda_2;
  int32_T ipiv[6];
  int32_T b_i;
  int32_T i;
  int32_T ipiv_0;
  int32_T j;
  int32_T jBcol;
  int32_T kAcol;
  int32_T pipk;
  int8_T p[6];
  static const int8_T Izz[36] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

  memset(&Lambda[0], 0, 144U * sizeof(real_T));
  for (j = 0; j < 12; j++) {
    Lambda[j + 12 * j] = x[j];
  }

  memset(&a[0], 0, 36U * sizeof(real_T));
  for (j = 0; j < 12; j++) {
    for (ipiv_0 = 0; ipiv_0 < 12; ipiv_0++) {
      Lambda_2 = 0.0;
      for (pipk = 0; pipk < 12; pipk++) {
        Lambda_2 += Lambda[12 * pipk + j] * P[12 * ipiv_0 + pipk];
      }

      Lambda_0[j + 12 * ipiv_0] = Lambda_2;
    }

    for (ipiv_0 = 0; ipiv_0 < 12; ipiv_0++) {
      Lambda_2 = 0.0;
      for (pipk = 0; pipk < 12; pipk++) {
        Lambda_2 += Lambda_0[12 * pipk + j] * Lambda[12 * ipiv_0 + pipk];
      }

      Lambda_1[j + 12 * ipiv_0] = Lambda_2;
    }
  }

  for (j = 0; j < 6; j++) {
    for (ipiv_0 = 0; ipiv_0 < 12; ipiv_0++) {
      Lambda_2 = 0.0;
      for (pipk = 0; pipk < 12; pipk++) {
        Lambda_2 += H[6 * pipk + j] * Lambda_1[12 * ipiv_0 + pipk];
      }

      H_0[j + 6 * ipiv_0] = Lambda_2;
    }

    for (ipiv_0 = 0; ipiv_0 < 6; ipiv_0++) {
      Lambda_2 = 0.0;
      for (pipk = 0; pipk < 12; pipk++) {
        Lambda_2 += H_0[6 * pipk + j] * H[6 * pipk + ipiv_0];
      }

      pipk = 6 * ipiv_0 + j;
      b_x[pipk] = R[pipk] + Lambda_2;
    }
  }

  STQMEKF_xzgetrf(b_x, ipiv, &j);
  for (j = 0; j < 6; j++) {
    p[j] = static_cast<int8_T>(j + 1);
  }

  for (j = 0; j < 5; j++) {
    ipiv_0 = ipiv[j];
    if (ipiv_0 > j + 1) {
      pipk = p[ipiv_0 - 1];
      p[ipiv_0 - 1] = p[j];
      p[j] = static_cast<int8_T>(pipk);
    }
  }

  for (pipk = 0; pipk < 6; pipk++) {
    ipiv_0 = (p[pipk] - 1) * 6;
    a[pipk + ipiv_0] = 1.0;
    for (jBcol = pipk + 1; jBcol < 7; jBcol++) {
      j = (ipiv_0 + jBcol) - 1;
      if (a[j] != 0.0) {
        for (i = jBcol + 1; i < 7; i++) {
          kAcol = (ipiv_0 + i) - 1;
          a[kAcol] -= b_x[((jBcol - 1) * 6 + i) - 1] * a[j];
        }
      }
    }
  }

  for (pipk = 0; pipk < 6; pipk++) {
    jBcol = 6 * pipk;
    for (i = 5; i >= 0; i--) {
      kAcol = 6 * i;
      j = i + jBcol;
      Lambda_2 = a[j];
      if (Lambda_2 != 0.0) {
        a[j] = Lambda_2 / b_x[i + kAcol];
        for (b_i = 0; b_i < i; b_i++) {
          ipiv_0 = b_i + jBcol;
          a[ipiv_0] -= b_x[b_i + kAcol] * a[j];
        }
      }
    }
  }

  for (j = 0; j < 6; j++) {
    for (ipiv_0 = 0; ipiv_0 < 6; ipiv_0++) {
      Lambda_2 = 0.0;
      for (pipk = 0; pipk < 6; pipk++) {
        Lambda_2 += a[6 * pipk + j] * V[6 * ipiv_0 + pipk];
      }

      pipk = 6 * ipiv_0 + j;
      varargout_1[pipk] = static_cast<real_T>(Izz[pipk]) - Lambda_2;
    }
  }
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_finDiffEvalAndChkErr(const real_T
  obj_nonlin_workspace_fun_worksp[144], const real_T
  obj_nonlin_workspace_fun_work_0[72], const real_T
  obj_nonlin_workspace_fun_work_1[36], int32_T dim, real_T delta, real_T xk[12],
  boolean_T *evalOK, real_T *fplus, real_T cEqPlus[36])
{
  real_T temp_tmp;
  int32_T idx;
  static const real_T b[36] = { 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9 };

  *fplus = 0.0;
  *evalOK = true;
  temp_tmp = xk[dim - 1];
  xk[dim - 1] = temp_tmp + delta;
  STQMEKF_QMEKF_anonFcn1(obj_nonlin_workspace_fun_worksp,
    obj_nonlin_workspace_fun_work_0, b, obj_nonlin_workspace_fun_work_1, xk,
    cEqPlus);
  idx = 0;
  while ((*evalOK) && (idx + 1 <= 36)) {
    *evalOK = ((!rtIsInf(cEqPlus[idx])) && (!rtIsNaN(cEqPlus[idx])));
    idx++;
  }

  xk[dim - 1] = temp_tmp;
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static boolean_T STQMEK_computeFiniteDifferences(s_nQKPRbEKofXRewaeXLaVf_STQME_T
  *obj, const real_T cEqCurrent[36], real_T xk[12], real_T JacCeqTrans[432])
{
  real_T b;
  real_T deltaX;
  real_T u0;
  int32_T idx;
  int32_T idx_row;
  boolean_T evalOK;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T modifiedStep;
  evalOK = true;
  obj->numEvals = 0;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 12)) {
    u0 = fabs(xk[idx]);
    if (!(u0 >= 1.0)) {
      u0 = 1.0;
    }

    u0 *= (1.0 - static_cast<real_T>(xk[idx] < 0.0) * 2.0) *
      1.4901161193847656E-8;
    modifiedStep = false;
    if ((xk[idx] >= 1.0) && (xk[idx] + u0 < 1.0)) {
      u0 = -u0;
      modifiedStep = true;
    }

    deltaX = u0;
    STQMEKF_finDiffEvalAndChkErr(obj->nonlin.workspace.fun.workspace.P,
      obj->nonlin.workspace.fun.workspace.H,
      obj->nonlin.workspace.fun.workspace.V, idx + 1, u0, xk, &evalOK, &b,
      obj->cEq_1);
    obj->f_1 = 0.0;
    obj->numEvals++;
    guard1 = false;
    if (!evalOK) {
      if (!modifiedStep) {
        deltaX = -u0;
        if (!obj->hasBounds) {
          STQMEKF_finDiffEvalAndChkErr(obj->nonlin.workspace.fun.workspace.P,
            obj->nonlin.workspace.fun.workspace.H,
            obj->nonlin.workspace.fun.workspace.V, idx + 1, -u0, xk, &evalOK, &b,
            obj->cEq_1);
          obj->f_1 = 0.0;
          obj->numEvals++;
        }
      }

      if (!evalOK) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      for (idx_row = 0; idx_row < 36; idx_row++) {
        JacCeqTrans[idx + 12 * idx_row] = (obj->cEq_1[idx_row] -
          cEqCurrent[idx_row]) / deltaX;
      }

      idx++;
    }
  }

  return evalOK;
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static real_T STQMEKF_computeFirstOrderOpt(const real_T gradf[12], boolean_T
  hasFiniteBounds, const real_T *projSteepestDescentInfNorm)
{
  real_T firstOrderOpt;
  if (hasFiniteBounds) {
    real_T absx;
    real_T b_absx;
    absx = 0.0;
    for (int32_T k = 0; k < 12; k++) {
      b_absx = fabs(gradf[k]);
      if (rtIsNaN(b_absx)) {
        absx = (rtNaN);
      } else if (b_absx > absx) {
        absx = b_absx;
      }
    }

    if ((*projSteepestDescentInfNorm >= absx) || rtIsNaN(absx)) {
      b_absx = *projSteepestDescentInfNorm;
    } else {
      b_absx = absx;
    }

    if (fabs(*projSteepestDescentInfNorm - absx) < 2.2204460492503131E-16 *
        b_absx) {
      firstOrderOpt = *projSteepestDescentInfNorm;
    } else if (absx == 0.0) {
      firstOrderOpt = *projSteepestDescentInfNorm;
    } else {
      firstOrderOpt = *projSteepestDescentInfNorm * *projSteepestDescentInfNorm /
        absx;
    }
  } else {
    firstOrderOpt = 0.0;
    for (int32_T k = 0; k < 12; k++) {
      real_T absx;
      absx = fabs(gradf[k]);
      if (rtIsNaN(absx)) {
        firstOrderOpt = (rtNaN);
      } else if (absx > firstOrderOpt) {
        firstOrderOpt = absx;
      }
    }
  }

  return firstOrderOpt;
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static real_T STQMEKF_norm_hm(const real_T x[12])
{
  real_T scale;
  real_T y;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (int32_T k = 0; k < 12; k++) {
    real_T absxk;
    absxk = fabs(x[k]);
    if (absxk > scale) {
      real_T t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      real_T t;
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static int32_T STQMEKF_checkStoppingCriteria(const real_T gradf[12], real_T
  relFactor, const real_T x[12], int32_T funcCount, real_T
  projSteepestDescentInfNorm, boolean_T hasFiniteBounds)
{
  real_T tmp[12];
  real_T absx;
  real_T normGradF;
  int32_T exitflag;
  int32_T k;
  normGradF = 0.0;
  for (k = 0; k < 12; k++) {
    absx = fabs(gradf[k]);
    if (rtIsNaN(absx)) {
      normGradF = (rtNaN);
    } else if (absx > normGradF) {
      normGradF = absx;
    }
  }

  if (hasFiniteBounds && (projSteepestDescentInfNorm *
                          projSteepestDescentInfNorm <= 1.0E-10 * normGradF *
                          relFactor)) {
    exitflag = 1;
  } else if ((!hasFiniteBounds) && (normGradF <= 1.0E-10 * relFactor)) {
    exitflag = 1;
  } else if (funcCount >= 2400) {
    exitflag = 0;
  } else {
    for (k = 0; k < 12; k++) {
      tmp[k] = (rtInf);
    }

    if (STQMEKF_norm_hm(tmp) < (STQMEKF_norm_hm(x) + 1.4901161193847656E-8) *
        1.0E-6) {
      exitflag = 4;
    } else {
      exitflag = -5;
    }
  }

  return exitflag;
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static real_T STQMEKF_xnrm2_ppp(int32_T n, const real_T x[576], int32_T ix0)
{
  real_T scale;
  real_T y;
  int32_T kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = ix0 + n;
  for (int32_T k = ix0; k < kend; k++) {
    real_T absxk;
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      real_T t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      real_T t;
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static real_T STQMEKF_xzlarfg(int32_T n, real_T *alpha1, real_T x[576], int32_T
  ix0)
{
  real_T a;
  real_T tau;
  real_T xnorm;
  int32_T c;
  int32_T d_tmp;
  int32_T knt;
  tau = 0.0;
  xnorm = STQMEKF_xnrm2_ppp(n - 1, x, ix0);
  if (xnorm != 0.0) {
    xnorm = rt_hypotd_snf(*alpha1, xnorm);
    if (*alpha1 >= 0.0) {
      xnorm = -xnorm;
    }

    if (fabs(xnorm) < 1.0020841800044864E-292) {
      knt = 0;
      d_tmp = (ix0 + n) - 2;
      do {
        knt++;
        for (c = ix0; c <= d_tmp; c++) {
          x[c - 1] *= 9.9792015476736E+291;
        }

        xnorm *= 9.9792015476736E+291;
        *alpha1 *= 9.9792015476736E+291;
      } while ((fabs(xnorm) < 1.0020841800044864E-292) && (knt < 20));

      xnorm = rt_hypotd_snf(*alpha1, STQMEKF_xnrm2_ppp(n - 1, x, ix0));
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }

      tau = (xnorm - *alpha1) / xnorm;
      a = 1.0 / (*alpha1 - xnorm);
      for (c = ix0; c <= d_tmp; c++) {
        x[c - 1] *= a;
      }

      for (c = 0; c < knt; c++) {
        xnorm *= 1.0020841800044864E-292;
      }

      *alpha1 = xnorm;
    } else {
      tau = (xnorm - *alpha1) / xnorm;
      a = 1.0 / (*alpha1 - xnorm);
      c = (ix0 + n) - 2;
      for (knt = ix0; knt <= c; knt++) {
        x[knt - 1] *= a;
      }

      *alpha1 = xnorm;
    }
  }

  return tau;
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T
  C[576], int32_T ic0, real_T work[12])
{
  int32_T coltop;
  int32_T jA;
  int32_T lastc;
  int32_T lastv;
  if (tau != 0.0) {
    boolean_T exitg2;
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      int32_T exitg1;
      coltop = (lastc - 1) * 48 + ic0;
      jA = coltop;
      do {
        exitg1 = 0;
        if (jA <= (coltop + lastv) - 1) {
          if (C[jA - 1] != 0.0) {
            exitg1 = 1;
          } else {
            jA++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    real_T c;
    int32_T d;
    int32_T e;
    if (lastc != 0) {
      memset(&work[0], 0, static_cast<uint8_T>(lastc) * sizeof(real_T));
      d = (lastc - 1) * 48 + ic0;
      for (coltop = ic0; coltop <= d; coltop += 48) {
        c = 0.0;
        e = (coltop + lastv) - 1;
        for (jA = coltop; jA <= e; jA++) {
          c += C[((iv0 + jA) - coltop) - 1] * C[jA - 1];
        }

        jA = div_nde_s32_floor(coltop - ic0, 48);
        work[jA] += c;
      }
    }

    if (!(-tau == 0.0)) {
      jA = ic0;
      d = static_cast<uint8_T>(lastc) - 1;
      for (lastc = 0; lastc <= d; lastc++) {
        c = work[lastc];
        if (c != 0.0) {
          c *= -tau;
          e = (lastv + jA) - 1;
          for (coltop = jA; coltop <= e; coltop++) {
            C[coltop - 1] += C[((iv0 + coltop) - jA) - 1] * c;
          }
        }

        jA += 48;
      }
    }
  }
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_linearLeastSquares(real_T lhs[576], real_T rhs[48], real_T
  dx[12])
{
  real_T jpvt[12];
  real_T tau[12];
  real_T vn1[12];
  real_T vn2[12];
  real_T work[12];
  real_T s;
  real_T temp;
  real_T temp2;
  int32_T b_ix;
  int32_T b_temp_tmp;
  int32_T d_ix;
  int32_T i;
  int32_T ii;
  int32_T iy;
  int32_T nfxd;
  int32_T pvt;
  int32_T r;
  memset(&jpvt[0], 0, 12U * sizeof(real_T));
  nfxd = 0;
  for (r = 0; r < 12; r++) {
    if (jpvt[r] != 0.0) {
      nfxd++;
      if (r + 1 != nfxd) {
        b_ix = r * 48;
        iy = (nfxd - 1) * 48;
        for (ii = 0; ii < 48; ii++) {
          pvt = b_ix + ii;
          temp = lhs[pvt];
          i = iy + ii;
          lhs[pvt] = lhs[i];
          lhs[i] = temp;
        }

        jpvt[r] = jpvt[nfxd - 1];
        jpvt[nfxd - 1] = static_cast<real_T>(r) + 1.0;
      } else {
        jpvt[r] = static_cast<real_T>(r) + 1.0;
      }
    } else {
      jpvt[r] = static_cast<real_T>(r) + 1.0;
    }

    tau[r] = 0.0;
    work[r] = 0.0;
  }

  r = static_cast<uint8_T>(nfxd);
  for (i = 0; i < r; i++) {
    ii = i * 48 + i;
    s = lhs[ii];
    temp = STQMEKF_xzlarfg(48 - i, &s, lhs, ii + 2);
    tau[i] = temp;
    lhs[ii] = s;
    if (i + 1 < 12) {
      lhs[ii] = 1.0;
      STQMEKF_xzlarf(48 - i, 11 - i, ii + 1, temp, lhs, ii + 49, work);
      lhs[ii] = s;
    }
  }

  if (nfxd < 12) {
    memset(&work[0], 0, 12U * sizeof(real_T));
    memset(&vn1[0], 0, 12U * sizeof(real_T));
    memset(&vn2[0], 0, 12U * sizeof(real_T));
    for (i = nfxd + 1; i < 13; i++) {
      temp = STQMEKF_xnrm2_ppp(48 - nfxd, lhs, ((i - 1) * 48 + nfxd) + 1);
      vn1[i - 1] = temp;
      vn2[i - 1] = temp;
    }

    for (r = nfxd + 1; r < 13; r++) {
      ii = (r - 1) * 48;
      b_ix = (ii + r) - 1;
      iy = 13 - r;
      pvt = -1;
      if (13 - r > 1) {
        temp = fabs(vn1[r - 1]);
        for (i = 2; i <= iy; i++) {
          s = fabs(vn1[(r + i) - 2]);
          if (s > temp) {
            pvt = i - 2;
            temp = s;
          }
        }
      }

      pvt += r;
      if (pvt + 1 != r) {
        d_ix = pvt * 48;
        for (iy = 0; iy < 48; iy++) {
          b_temp_tmp = d_ix + iy;
          temp = lhs[b_temp_tmp];
          i = ii + iy;
          lhs[b_temp_tmp] = lhs[i];
          lhs[i] = temp;
        }

        temp = jpvt[pvt];
        jpvt[pvt] = jpvt[r - 1];
        jpvt[r - 1] = temp;
        vn1[pvt] = vn1[r - 1];
        vn2[pvt] = vn2[r - 1];
      }

      s = lhs[b_ix];
      temp = STQMEKF_xzlarfg(49 - r, &s, lhs, b_ix + 2);
      tau[r - 1] = temp;
      lhs[b_ix] = s;
      if (r < 12) {
        lhs[b_ix] = 1.0;
        STQMEKF_xzlarf(49 - r, 12 - r, b_ix + 1, temp, lhs, b_ix + 49, work);
        lhs[b_ix] = s;
      }

      for (i = r + 1; i < 13; i++) {
        ii = (i - 1) * 48 + r;
        temp = vn1[i - 1];
        if (temp != 0.0) {
          s = fabs(lhs[ii - 1]) / temp;
          s = 1.0 - s * s;
          if (s < 0.0) {
            s = 0.0;
          }

          temp2 = temp / vn2[i - 1];
          temp2 = temp2 * temp2 * s;
          if (temp2 <= 1.4901161193847656E-8) {
            temp = STQMEKF_xnrm2_ppp(48 - r, lhs, ii + 1);
            vn1[i - 1] = temp;
            vn2[i - 1] = temp;
          } else {
            vn1[i - 1] = temp * sqrt(s);
          }
        }
      }
    }
  }

  for (nfxd = 0; nfxd < 12; nfxd++) {
    if (tau[nfxd] != 0.0) {
      temp = rhs[nfxd];
      for (i = nfxd + 2; i < 49; i++) {
        temp += lhs[(48 * nfxd + i) - 1] * rhs[i - 1];
      }

      temp *= tau[nfxd];
      if (temp != 0.0) {
        rhs[nfxd] -= temp;
        for (i = nfxd + 2; i < 49; i++) {
          rhs[i - 1] -= lhs[(48 * nfxd + i) - 1] * temp;
        }
      }
    }
  }

  r = 0;
  temp = 1.0658141036401503E-13 * fabs(lhs[0]);
  while ((r < 12) && (!(fabs(lhs[48 * r + r]) <= temp))) {
    r++;
  }

  memcpy(&dx[0], &rhs[0], 12U * sizeof(real_T));
  if (r != 0) {
    for (nfxd = r; nfxd >= 1; nfxd--) {
      ii = ((nfxd - 1) * 48 + nfxd) - 2;
      dx[nfxd - 1] /= lhs[ii + 1];
      for (i = 0; i <= nfxd - 2; i++) {
        b_ix = (nfxd - i) - 2;
        dx[b_ix] -= dx[nfxd - 1] * lhs[ii - i];
      }
    }
  }

  for (i = r + 1; i < 13; i++) {
    dx[i - 1] = 0.0;
  }

  memcpy(&tau[0], &dx[0], 12U * sizeof(real_T));
  for (i = 0; i < 12; i++) {
    dx[static_cast<int32_T>(jpvt[i]) - 1] = tau[i];
  }
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static int32_T STQMEKF_checkStoppingCriteria_h(const real_T gradf[12], real_T
  relFactor, real_T funDiff, const real_T x[12], const real_T dx[12], int32_T
  funcCount, boolean_T stepSuccessful, int32_T *iter, real_T
  projSteepestDescentInfNorm, boolean_T hasFiniteBounds)
{
  real_T absx;
  real_T normGradF;
  int32_T exitflag;
  int32_T k;
  normGradF = 0.0;
  for (k = 0; k < 12; k++) {
    absx = fabs(gradf[k]);
    if (rtIsNaN(absx)) {
      normGradF = (rtNaN);
    } else if (absx > normGradF) {
      normGradF = absx;
    }
  }

  if (hasFiniteBounds && (projSteepestDescentInfNorm *
                          projSteepestDescentInfNorm <= 1.0E-10 * normGradF *
                          relFactor)) {
    exitflag = 1;
  } else if ((!hasFiniteBounds) && (normGradF <= 1.0E-10 * relFactor)) {
    exitflag = 1;
  } else if (funcCount >= 2400) {
    exitflag = 0;
  } else if (*iter >= 400) {
    exitflag = 0;
  } else if (STQMEKF_norm_hm(dx) < (STQMEKF_norm_hm(x) + 1.4901161193847656E-8) *
             1.0E-6) {
    exitflag = 4;
    if (!stepSuccessful) {
      (*iter)++;
    }
  } else if (funDiff <= 1.0E-6) {
    exitflag = 3;
  } else {
    exitflag = -5;
  }

  return exitflag;
}

// Function for MATLAB Function: '<S218>/MATLAB Function'
static void STQMEKF_lsqnonlin(const real_T fun_workspace_P[144], const real_T
  fun_workspace_H[72], const real_T fun_workspace_V[36], real_T xCurrent[12])
{
  s_nQKPRbEKofXRewaeXLaVf_STQME_T FiniteDifferences;
  real_T JacCeqTrans[432];
  real_T rhs[48];
  real_T fNew[36];
  real_T f_temp[36];
  real_T fval[36];
  real_T a__3[12];
  real_T dx[12];
  real_T gradf[12];
  real_T b_gamma;
  real_T c;
  real_T funDiff;
  real_T projSteepestDescentInfNorm;
  real_T resnorm;
  real_T resnormNew;
  real_T u0;
  int32_T aIdx;
  int32_T funcCount;
  int32_T i;
  int32_T iter;
  boolean_T hasLB[12];
  boolean_T hasUB[12];
  boolean_T indActive[12];
  boolean_T hasFiniteBounds;
  boolean_T indActive_0;
  boolean_T stepSuccessful;
  static const real_T b[36] = { 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9 };

  boolean_T exitg1;
  boolean_T guard1;
  for (i = 0; i < 12; i++) {
    indActive[i] = false;
  }

  funDiff = (rtInf);
  iter = 0;
  hasFiniteBounds = STQMEKF_hasFiniteBounds(hasLB, hasUB);
  if (!hasFiniteBounds) {
    for (i = 0; i < 12; i++) {
      xCurrent[i] = 1.1;
    }
  } else {
    for (funcCount = 0; funcCount < 12; funcCount++) {
      xCurrent[funcCount] = 1.1;
    }
  }

  STQMEKF_QMEKF_anonFcn1(fun_workspace_P, fun_workspace_H, b, fun_workspace_V,
    xCurrent, f_temp);
  resnorm = 0.0;
  for (i = 0; i < 36; i++) {
    b_gamma = f_temp[i];
    fval[i] = b_gamma;
    resnorm += b_gamma * b_gamma;
  }

  memcpy(&FiniteDifferences.nonlin.workspace.fun.workspace.P[0],
         &fun_workspace_P[0], 144U * sizeof(real_T));
  memcpy(&FiniteDifferences.nonlin.workspace.fun.workspace.H[0],
         &fun_workspace_H[0], 72U * sizeof(real_T));
  memcpy(&FiniteDifferences.nonlin.workspace.fun.workspace.V[0],
         &fun_workspace_V[0], 36U * sizeof(real_T));
  FiniteDifferences.numEvals = 0;
  FiniteDifferences.hasBounds = STQMEKF_hasFiniteBounds(FiniteDifferences.hasLB,
    FiniteDifferences.hasUB);
  for (i = 0; i < 12; i++) {
    a__3[i] = 1.1;
  }

  STQMEK_computeFiniteDifferences(&FiniteDifferences, fval, a__3, JacCeqTrans);
  for (i = 0; i < 12; i++) {
    for (aIdx = 0; aIdx < 36; aIdx++) {
      STQMEKF_B.augJacobian[aIdx + 48 * i] = JacCeqTrans[12 * aIdx + i];
    }
  }

  funcCount = FiniteDifferences.numEvals + 1;
  for (i = 0; i < 12; i++) {
    memcpy(&JacCeqTrans[i * 36], &STQMEKF_B.augJacobian[i * 48], 36U * sizeof
           (real_T));
  }

  b_gamma = 0.01;
  for (i = 0; i < 12; i++) {
    memset(&STQMEKF_B.augJacobian[(i + 1) * 48 + -12], 0, 12U * sizeof(real_T));
    STQMEKF_B.augJacobian[(i + 48 * i) + 36] = 0.1;
    gradf[i] = 0.0;
  }

  for (i = 0; i <= 396; i += 36) {
    c = 0.0;
    for (aIdx = i + 1; aIdx <= i + 36; aIdx++) {
      c += fval[(aIdx - i) - 1] * JacCeqTrans[aIdx - 1];
    }

    aIdx = div_nde_s32_floor(i, 36);
    gradf[aIdx] += c;
  }

  projSteepestDescentInfNorm = 0.0;
  for (i = 0; i < 12; i++) {
    resnormNew = -gradf[i];
    if ((resnormNew <= -0.10000000000000009) || rtIsNaN(resnormNew)) {
      resnormNew = -0.10000000000000009;
    }

    resnormNew = fabs(resnormNew);
    if (!(projSteepestDescentInfNorm >= resnormNew)) {
      projSteepestDescentInfNorm = resnormNew;
    }
  }

  c = STQMEKF_computeFirstOrderOpt(gradf, hasFiniteBounds,
    &projSteepestDescentInfNorm);
  if (!(c >= 1.0)) {
    c = 1.0;
  }

  stepSuccessful = true;
  i = STQMEKF_checkStoppingCriteria(gradf, c, xCurrent,
    FiniteDifferences.numEvals + 1, projSteepestDescentInfNorm, hasFiniteBounds);
  exitg1 = false;
  while ((!exitg1) && (i == -5)) {
    for (i = 0; i < 36; i++) {
      rhs[i] = -fval[i];
    }

    memset(&rhs[36], 0, 12U * sizeof(real_T));
    if (hasFiniteBounds) {
      projSteepestDescentInfNorm = 0.0;
      for (i = 0; i < 12; i++) {
        resnormNew = -gradf[i] / (b_gamma + 1.0);
        u0 = 1.0 - xCurrent[i];
        if ((u0 >= resnormNew) || rtIsNaN(resnormNew)) {
          resnormNew = u0;
        }

        resnormNew = fabs(resnormNew);
        if ((!(projSteepestDescentInfNorm >= resnormNew)) && (!rtIsNaN
             (resnormNew))) {
          projSteepestDescentInfNorm = resnormNew;
        }
      }

      for (i = 0; i < 12; i++) {
        if (xCurrent[i] - 1.0 <= projSteepestDescentInfNorm) {
          indActive_0 = (gradf[i] > 0.0);
          indActive[i] = indActive_0;
        } else {
          indActive_0 = false;
          indActive[i] = false;
        }

        if (indActive_0) {
          memset(&STQMEKF_B.augJacobian[48 * i], 0, 36U * sizeof(real_T));
        }
      }
    }

    STQMEKF_linearLeastSquares(STQMEKF_B.augJacobian, rhs, dx);
    for (i = 0; i < 12; i++) {
      if (hasFiniteBounds) {
        if (indActive[i]) {
          dx[i] = -gradf[i] / (b_gamma + 1.0);
        }

        resnormNew = xCurrent[i] + dx[i];
        if ((resnormNew <= 1.0) || rtIsNaN(resnormNew)) {
          gradf[i] = 1.0;
        } else {
          gradf[i] = resnormNew;
        }
      } else {
        gradf[i] = xCurrent[i] + dx[i];
      }
    }

    STQMEKF_QMEKF_anonFcn1(fun_workspace_P, fun_workspace_H, b, fun_workspace_V,
      gradf, f_temp);
    resnormNew = 0.0;
    indActive_0 = true;
    for (i = 0; i < 36; i++) {
      projSteepestDescentInfNorm = f_temp[i];
      fNew[i] = projSteepestDescentInfNorm;
      resnormNew += projSteepestDescentInfNorm * projSteepestDescentInfNorm;
      if (indActive_0 && (rtIsInf(projSteepestDescentInfNorm) || rtIsNaN
                          (projSteepestDescentInfNorm))) {
        indActive_0 = false;
      }
    }

    funcCount++;
    guard1 = false;
    if ((resnormNew < resnorm) && indActive_0) {
      iter++;
      funDiff = fabs(resnormNew - resnorm) / resnorm;
      resnorm = resnormNew;
      memcpy(&a__3[0], &gradf[0], 12U * sizeof(real_T));
      indActive_0 = STQMEK_computeFiniteDifferences(&FiniteDifferences, fNew,
        a__3, JacCeqTrans);
      funcCount += FiniteDifferences.numEvals;
      for (i = 0; i < 12; i++) {
        for (aIdx = 0; aIdx < 36; aIdx++) {
          STQMEKF_B.augJacobian[aIdx + 48 * i] = JacCeqTrans[12 * aIdx + i];
        }
      }

      memcpy(&fval[0], &fNew[0], 36U * sizeof(real_T));
      for (i = 0; i < 12; i++) {
        memcpy(&JacCeqTrans[i * 36], &STQMEKF_B.augJacobian[i * 48], 36U *
               sizeof(real_T));
      }

      if (indActive_0) {
        memcpy(&xCurrent[0], &gradf[0], 12U * sizeof(real_T));
        if (stepSuccessful) {
          b_gamma *= 0.1;
        }

        stepSuccessful = true;
        guard1 = true;
      } else {
        exitg1 = true;
      }
    } else {
      b_gamma *= 10.0;
      stepSuccessful = false;
      for (i = 0; i < 12; i++) {
        memcpy(&STQMEKF_B.augJacobian[i * 48], &JacCeqTrans[i * 36], 36U *
               sizeof(real_T));
      }

      guard1 = true;
    }

    if (guard1) {
      resnormNew = sqrt(b_gamma);
      for (i = 0; i < 12; i++) {
        memset(&STQMEKF_B.augJacobian[(i + 1) * 48 + -12], 0, 12U * sizeof
               (real_T));
        STQMEKF_B.augJacobian[(i + 48 * i) + 36] = resnormNew;
        gradf[i] = 0.0;
      }

      for (i = 0; i <= 396; i += 36) {
        resnormNew = 0.0;
        for (aIdx = i + 1; aIdx <= i + 36; aIdx++) {
          resnormNew += fval[(aIdx - i) - 1] * JacCeqTrans[aIdx - 1];
        }

        aIdx = div_nde_s32_floor(i, 36);
        gradf[aIdx] += resnormNew;
      }

      projSteepestDescentInfNorm = 0.0;
      for (i = 0; i < 12; i++) {
        resnormNew = -gradf[i];
        u0 = 1.0 - xCurrent[i];
        if ((u0 >= resnormNew) || rtIsNaN(resnormNew)) {
          resnormNew = u0;
        }

        resnormNew = fabs(resnormNew);
        if ((!(projSteepestDescentInfNorm >= resnormNew)) && (!rtIsNaN
             (resnormNew))) {
          projSteepestDescentInfNorm = resnormNew;
        }
      }

      i = STQMEKF_checkStoppingCriteria_h(gradf, c, funDiff, xCurrent, dx,
        funcCount, stepSuccessful, &iter, projSteepestDescentInfNorm,
        hasFiniteBounds);
      if (i != -5) {
        exitg1 = true;
      }
    }
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static real_T STQMEKF_xnrm2_j(int32_T n, const real_T x[153], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = ix0 + n;
      for (int32_T k = ix0; k < kend; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static real_T STQMEKF_xzlarfg_a(int32_T n, real_T *alpha1, real_T x[153],
  int32_T ix0)
{
  real_T a;
  real_T tau;
  real_T xnorm;
  int32_T c_tmp;
  int32_T d;
  int32_T knt;
  tau = 0.0;
  if (n > 0) {
    xnorm = STQMEKF_xnrm2_j(n - 1, x, ix0);
    if (xnorm != 0.0) {
      xnorm = rt_hypotd_snf(*alpha1, xnorm);
      if (*alpha1 >= 0.0) {
        xnorm = -xnorm;
      }

      if (fabs(xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        c_tmp = (ix0 + n) - 2;
        do {
          knt++;
          for (d = ix0; d <= c_tmp; d++) {
            x[d - 1] *= 9.9792015476736E+291;
          }

          xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(xnorm) < 1.0020841800044864E-292) && (knt < 20));

        xnorm = rt_hypotd_snf(*alpha1, STQMEKF_xnrm2_j(n - 1, x, ix0));
        if (*alpha1 >= 0.0) {
          xnorm = -xnorm;
        }

        tau = (xnorm - *alpha1) / xnorm;
        a = 1.0 / (*alpha1 - xnorm);
        for (d = ix0; d <= c_tmp; d++) {
          x[d - 1] *= a;
        }

        for (d = 0; d < knt; d++) {
          xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = xnorm;
      } else {
        tau = (xnorm - *alpha1) / xnorm;
        a = 1.0 / (*alpha1 - xnorm);
        d = (ix0 + n) - 2;
        for (knt = ix0; knt <= d; knt++) {
          x[knt - 1] *= a;
        }

        *alpha1 = xnorm;
      }
    }
  }

  return tau;
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_xzlarf_p(int32_T m, int32_T n, int32_T iv0, real_T tau,
  real_T C[153], int32_T ic0, real_T work[17])
{
  int32_T b_ia;
  int32_T coltop;
  int32_T lastc;
  int32_T lastv;
  if (tau != 0.0) {
    boolean_T exitg2;
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      int32_T exitg1;
      coltop = (lastc - 1) * 9 + ic0;
      b_ia = coltop;
      do {
        exitg1 = 0;
        if (b_ia <= (coltop + lastv) - 1) {
          if (C[b_ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            b_ia++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    lastc--;
  } else {
    lastv = 0;
    lastc = -1;
  }

  if (lastv > 0) {
    real_T c;
    int32_T d;
    int32_T jA;
    if (lastc + 1 != 0) {
      if (lastc >= 0) {
        memset(&work[0], 0, static_cast<uint32_T>(lastc + 1) * sizeof(real_T));
      }

      jA = 9 * lastc + ic0;
      for (coltop = ic0; coltop <= jA; coltop += 9) {
        c = 0.0;
        d = (coltop + lastv) - 1;
        for (b_ia = coltop; b_ia <= d; b_ia++) {
          c += C[((iv0 + b_ia) - coltop) - 1] * C[b_ia - 1];
        }

        b_ia = div_nde_s32_floor(coltop - ic0, 9);
        work[b_ia] += c;
      }
    }

    if (!(-tau == 0.0)) {
      jA = ic0;
      for (coltop = 0; coltop <= lastc; coltop++) {
        c = work[coltop];
        if (c != 0.0) {
          c *= -tau;
          d = (lastv + jA) - 1;
          for (b_ia = jA; b_ia <= d; b_ia++) {
            C[b_ia - 1] += C[((iv0 + b_ia) - jA) - 1] * c;
          }
        }

        jA += 9;
      }
    }
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_qrf(real_T A[153], int32_T m, int32_T n, int32_T nfxd,
  real_T tau[9])
{
  real_T work[17];
  real_T b_atmp;
  real_T tau_0;
  int32_T b;
  int32_T i;
  int32_T ii;
  int32_T mmi;
  memset(&work[0], 0, 17U * sizeof(real_T));
  b = static_cast<uint8_T>(nfxd);
  for (i = 0; i < b; i++) {
    ii = i * 9 + i;
    mmi = m - i;
    if (i + 1 < m) {
      b_atmp = A[ii];
      tau_0 = STQMEKF_xzlarfg_a(mmi, &b_atmp, A, ii + 2);
      tau[i] = tau_0;
      A[ii] = b_atmp;
    } else {
      tau_0 = 0.0;
      tau[i] = 0.0;
    }

    if (i + 1 < n) {
      b_atmp = A[ii];
      A[ii] = 1.0;
      STQMEKF_xzlarf_p(mmi, (n - i) - 1, ii + 1, tau_0, A, ii + 10, work);
      A[ii] = b_atmp;
    }
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_xgeqp3(real_T A[153], int32_T m, int32_T n, int32_T jpvt[17],
  real_T tau[9])
{
  real_T vn1[17];
  real_T vn2[17];
  real_T work[17];
  real_T s;
  real_T temp;
  real_T temp2;
  int32_T b_temp_tmp;
  int32_T c_ix;
  int32_T i;
  int32_T idxmax;
  int32_T itemp;
  int32_T ix;
  int32_T iy;
  int32_T minmn_tmp;
  int32_T mmi;
  int32_T nfxd;
  int32_T pvt;
  int32_T temp_tmp;
  if (m <= n) {
    minmn_tmp = m;
  } else {
    minmn_tmp = n;
  }

  memset(&tau[0], 0, 9U * sizeof(real_T));
  if (minmn_tmp < 1) {
    for (minmn_tmp = 0; minmn_tmp < n; minmn_tmp++) {
      jpvt[minmn_tmp] = minmn_tmp + 1;
    }
  } else {
    nfxd = -1;
    for (i = 0; i < n; i++) {
      if (jpvt[i] != 0) {
        nfxd++;
        if (i + 1 != nfxd + 1) {
          ix = i * 9;
          iy = nfxd * 9;
          for (mmi = 0; mmi < m; mmi++) {
            temp_tmp = ix + mmi;
            temp = A[temp_tmp];
            itemp = iy + mmi;
            A[temp_tmp] = A[itemp];
            A[itemp] = temp;
          }

          jpvt[i] = jpvt[nfxd];
          jpvt[nfxd] = i + 1;
        } else {
          jpvt[i] = i + 1;
        }
      } else {
        jpvt[i] = i + 1;
      }
    }

    if (nfxd + 1 <= minmn_tmp) {
      nfxd++;
    } else {
      nfxd = minmn_tmp;
    }

    memset(&tau[0], 0, 9U * sizeof(real_T));
    STQMEKF_qrf(A, m, n, nfxd, tau);
    if (nfxd < minmn_tmp) {
      memset(&work[0], 0, 17U * sizeof(real_T));
      memset(&vn1[0], 0, 17U * sizeof(real_T));
      memset(&vn2[0], 0, 17U * sizeof(real_T));
      for (i = nfxd + 1; i <= n; i++) {
        temp = STQMEKF_xnrm2_j(m - nfxd, A, ((i - 1) * 9 + nfxd) + 1);
        vn1[i - 1] = temp;
        vn2[i - 1] = temp;
      }

      for (i = nfxd + 1; i <= minmn_tmp; i++) {
        temp_tmp = (i - 1) * 9;
        ix = (temp_tmp + i) - 1;
        iy = n - i;
        mmi = m - i;
        if (iy + 1 < 1) {
          idxmax = -2;
        } else {
          idxmax = -1;
          if (iy + 1 > 1) {
            temp = fabs(vn1[i - 1]);
            for (itemp = 2; itemp <= iy + 1; itemp++) {
              s = fabs(vn1[(i + itemp) - 2]);
              if (s > temp) {
                idxmax = itemp - 2;
                temp = s;
              }
            }
          }
        }

        pvt = i + idxmax;
        if (pvt + 1 != i) {
          c_ix = pvt * 9;
          for (idxmax = 0; idxmax < m; idxmax++) {
            b_temp_tmp = c_ix + idxmax;
            temp = A[b_temp_tmp];
            itemp = temp_tmp + idxmax;
            A[b_temp_tmp] = A[itemp];
            A[itemp] = temp;
          }

          itemp = jpvt[pvt];
          jpvt[pvt] = jpvt[i - 1];
          jpvt[i - 1] = itemp;
          vn1[pvt] = vn1[i - 1];
          vn2[pvt] = vn2[i - 1];
        }

        if (i < m) {
          s = A[ix];
          temp = STQMEKF_xzlarfg_a(mmi + 1, &s, A, ix + 2);
          tau[i - 1] = temp;
          A[ix] = s;
        } else {
          temp = 0.0;
          tau[i - 1] = 0.0;
        }

        if (i < n) {
          s = A[ix];
          A[ix] = 1.0;
          STQMEKF_xzlarf_p(mmi + 1, iy, ix + 1, temp, A, ix + 10, work);
          A[ix] = s;
        }

        for (itemp = i + 1; itemp <= n; itemp++) {
          ix = (itemp - 1) * 9 + i;
          temp = vn1[itemp - 1];
          if (temp != 0.0) {
            s = fabs(A[ix - 1]) / temp;
            s = 1.0 - s * s;
            if (s < 0.0) {
              s = 0.0;
            }

            temp2 = temp / vn2[itemp - 1];
            temp2 = temp2 * temp2 * s;
            if (temp2 <= 1.4901161193847656E-8) {
              if (i < m) {
                temp = STQMEKF_xnrm2_j(mmi, A, ix + 1);
                vn1[itemp - 1] = temp;
                vn2[itemp - 1] = temp;
              } else {
                vn1[itemp - 1] = 0.0;
                vn2[itemp - 1] = 0.0;
              }
            } else {
              vn1[itemp - 1] = temp * sqrt(s);
            }
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_countsort(int32_T x[17], int32_T xLen, int32_T workspace[17],
  int32_T xMin, int32_T xMax)
{
  if ((xLen > 1) && (xMax > xMin)) {
    int32_T b_tmp;
    int32_T idxEnd;
    int32_T idxFill;
    int32_T idxStart;
    int32_T maxOffset;
    b_tmp = xMax - xMin;
    if (b_tmp >= 0) {
      memset(&workspace[0], 0, static_cast<uint32_T>(b_tmp + 1) * sizeof(int32_T));
    }

    maxOffset = b_tmp - 1;
    for (b_tmp = 0; b_tmp < xLen; b_tmp++) {
      idxFill = x[b_tmp] - xMin;
      workspace[idxFill]++;
    }

    for (b_tmp = 2; b_tmp <= maxOffset + 2; b_tmp++) {
      workspace[b_tmp - 1] += workspace[b_tmp - 2];
    }

    idxStart = 1;
    idxEnd = workspace[0];
    for (b_tmp = 0; b_tmp <= maxOffset; b_tmp++) {
      for (idxFill = idxStart; idxFill <= idxEnd; idxFill++) {
        x[idxFill - 1] = b_tmp + xMin;
      }

      idxStart = workspace[b_tmp] + 1;
      idxEnd = workspace[b_tmp + 1];
    }

    for (maxOffset = idxStart; maxOffset <= idxEnd; maxOffset++) {
      x[maxOffset - 1] = xMax;
    }
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_removeConstr(srnx7tMxlsAQ9dn31gXFrqF_STQME_T *obj, int32_T
  idx_global)
{
  int32_T TYPE_tmp;
  TYPE_tmp = obj->Wid[idx_global - 1] - 1;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE_tmp] + obj->Wlocalidx[idx_global -
                       1]) - 2] = false;
  if (idx_global < obj->nActiveConstr) {
    int32_T b;
    obj->Wid[idx_global - 1] = obj->Wid[obj->nActiveConstr - 1];
    obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[obj->nActiveConstr - 1];
    b = static_cast<uint8_T>(obj->nVar);
    for (int32_T idx = 0; idx < b; idx++) {
      obj->ATwset[idx + 9 * (idx_global - 1)] = obj->ATwset[(obj->nActiveConstr
        - 1) * 9 + idx];
    }

    obj->bwset[idx_global - 1] = obj->bwset[obj->nActiveConstr - 1];
  }

  obj->nActiveConstr--;
  obj->nWConstr[TYPE_tmp]--;
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_RemoveDependentIneq_(srnx7tMxlsAQ9dn31gXFrqF_STQME_T
  *workingset, sTj3C1mXm6Z2qP847mPxR8C_STQME_T *qrmanager,
  sLLWTJNyuJQrAxk3RwmbzBG_STQME_T *memspace, real_T tolfactor)
{
  real_T b_tol;
  real_T maxDiag;
  real_T u1;
  int32_T b_idx;
  int32_T idxDiag;
  int32_T iy0_tmp;
  int32_T nDepIneq;
  int32_T nFixedConstr;
  nDepIneq = workingset->nActiveConstr;
  nFixedConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  idxDiag = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    if (workingset->nVar >= workingset->nActiveConstr) {
      b_idx = workingset->nVar;
    } else {
      b_idx = workingset->nActiveConstr;
    }

    u1 = 2.2204460492503131E-15 * static_cast<real_T>(b_idx);
    if (u1 >= 1.4901161193847656E-8) {
      u1 = 1.4901161193847656E-8;
    }

    b_tol = tolfactor * u1;
    for (b_idx = 0; b_idx < nFixedConstr; b_idx++) {
      qrmanager->jpvt[b_idx] = 1;
    }

    if (nFixedConstr + 1 <= workingset->nActiveConstr) {
      memset(&qrmanager->jpvt[nFixedConstr], 0, static_cast<uint32_T>
             (workingset->nActiveConstr - nFixedConstr) * sizeof(int32_T));
    }

    for (b_idx = 0; b_idx < nDepIneq; b_idx++) {
      iy0_tmp = 9 * b_idx;
      memcpy(&qrmanager->QR[iy0_tmp], &workingset->ATwset[iy0_tmp], static_cast<
             uint8_T>(idxDiag) * sizeof(real_T));
    }

    if (workingset->nVar * workingset->nActiveConstr == 0) {
      qrmanager->mrows = workingset->nVar;
      qrmanager->ncols = workingset->nActiveConstr;
      qrmanager->minRowCol = 0;
    } else {
      qrmanager->usedPivoting = true;
      qrmanager->mrows = workingset->nVar;
      qrmanager->ncols = workingset->nActiveConstr;
      if (workingset->nVar <= workingset->nActiveConstr) {
        qrmanager->minRowCol = workingset->nVar;
      } else {
        qrmanager->minRowCol = workingset->nActiveConstr;
      }

      STQMEKF_xgeqp3(qrmanager->QR, workingset->nVar, workingset->nActiveConstr,
                     qrmanager->jpvt, qrmanager->tau);
    }

    nDepIneq = 0;
    for (b_idx = workingset->nActiveConstr - 1; b_idx + 1 > idxDiag; b_idx--) {
      nDepIneq++;
      memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[b_idx];
    }

    maxDiag = fabs(qrmanager->QR[0]);
    for (idxDiag = 0; idxDiag < b_idx; idxDiag++) {
      u1 = fabs(qrmanager->QR[((idxDiag + 1) * 9 + idxDiag) + 1]);
      if ((!(maxDiag >= u1)) && (!rtIsNaN(u1))) {
        maxDiag = u1;
      }
    }

    if (b_idx + 1 <= workingset->nVar) {
      idxDiag = 9 * b_idx + b_idx;
      while ((b_idx + 1 > nFixedConstr) && (fabs(qrmanager->QR[idxDiag]) < b_tol
              * maxDiag)) {
        nDepIneq++;
        memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[b_idx];
        b_idx--;
        idxDiag -= 10;
      }
    }

    STQMEKF_countsort(memspace->workspace_int, nDepIneq,
                      memspace->workspace_sort, nFixedConstr + 1,
                      workingset->nActiveConstr);
    for (nFixedConstr = nDepIneq; nFixedConstr >= 1; nFixedConstr--) {
      STQMEKF_removeConstr(workingset, memspace->workspace_int[nFixedConstr - 1]);
    }
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_computeQ_(sTj3C1mXm6Z2qP847mPxR8C_STQME_T *obj, int32_T
  nrows)
{
  real_T work[9];
  int32_T i;
  int32_T iQR0;
  int32_T ia;
  int32_T idx;
  i = obj->minRowCol;
  for (idx = 0; idx < i; idx++) {
    iQR0 = 9 * idx + idx;
    ia = obj->mrows - idx;
    if (ia - 2 >= 0) {
      memcpy(&obj->Q[iQR0 + 1], &obj->QR[iQR0 + 1], static_cast<uint32_T>(ia - 1)
             * sizeof(real_T));
    }
  }

  idx = obj->mrows;
  if (nrows >= 1) {
    int32_T itau;
    for (itau = i; itau < nrows; itau++) {
      ia = itau * 9;
      memset(&obj->Q[ia], 0, static_cast<uint32_T>(idx) * sizeof(real_T));
      obj->Q[ia + itau] = 1.0;
    }

    itau = obj->minRowCol - 1;
    memset(&work[0], 0, 9U * sizeof(real_T));
    for (i = obj->minRowCol; i >= 1; i--) {
      int32_T lastc;
      iQR0 = ((i - 1) * 9 + i) - 1;
      if (i < nrows) {
        int32_T c_ia;
        int32_T coltop;
        obj->Q[iQR0] = 1.0;
        ia = idx - i;
        if (obj->tau[itau] != 0.0) {
          boolean_T exitg2;
          lastc = iQR0 + ia;
          while ((ia + 1 > 0) && (obj->Q[lastc] == 0.0)) {
            ia--;
            lastc--;
          }

          lastc = nrows - i;
          exitg2 = false;
          while ((!exitg2) && (lastc > 0)) {
            int32_T exitg1;
            coltop = ((lastc - 1) * 9 + iQR0) + 10;
            c_ia = coltop;
            do {
              exitg1 = 0;
              if (c_ia <= coltop + ia) {
                if (obj->Q[c_ia - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  c_ia++;
                }
              } else {
                lastc--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }

          lastc--;
        } else {
          ia = -1;
          lastc = -1;
        }

        if (ia + 1 > 0) {
          real_T b_c;
          int32_T f;
          int32_T jA;
          if (lastc + 1 != 0) {
            if (lastc >= 0) {
              memset(&work[0], 0, static_cast<uint32_T>(lastc + 1) * sizeof
                     (real_T));
            }

            c_ia = (9 * lastc + iQR0) + 10;
            for (coltop = iQR0 + 10; coltop <= c_ia; coltop += 9) {
              b_c = 0.0;
              f = coltop + ia;
              for (jA = coltop; jA <= f; jA++) {
                b_c += obj->Q[(iQR0 + jA) - coltop] * obj->Q[jA - 1];
              }

              jA = div_nde_s32_floor((coltop - iQR0) - 10, 9);
              work[jA] += b_c;
            }
          }

          if (!(-obj->tau[itau] == 0.0)) {
            jA = iQR0 + 10;
            for (coltop = 0; coltop <= lastc; coltop++) {
              b_c = work[coltop];
              if (b_c != 0.0) {
                b_c *= -obj->tau[itau];
                f = ia + jA;
                for (c_ia = jA; c_ia <= f; c_ia++) {
                  obj->Q[c_ia - 1] += obj->Q[(iQR0 + c_ia) - jA] * b_c;
                }
              }

              jA += 9;
            }
          }
        }
      }

      if (i < idx) {
        lastc = ((iQR0 + idx) - i) + 1;
        for (ia = iQR0 + 2; ia <= lastc; ia++) {
          obj->Q[ia - 1] *= -obj->tau[itau];
        }
      }

      obj->Q[iQR0] = 1.0 - obj->tau[itau];
      for (ia = 0; ia <= i - 2; ia++) {
        obj->Q[(iQR0 - ia) - 1] = 0.0;
      }

      itau--;
    }
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static int32_T STQMEKF_rank(const real_T qrmanager_QR[153], int32_T
  qrmanager_mrows, int32_T qrmanager_ncols)
{
  int32_T minmn;
  int32_T r;
  r = 0;
  if (qrmanager_mrows < qrmanager_ncols) {
    minmn = 8;
  } else {
    minmn = qrmanager_ncols;
  }

  if (minmn > 0) {
    real_T b_tol;
    int32_T tmp;
    if (qrmanager_mrows >= qrmanager_ncols) {
      tmp = qrmanager_mrows;
    } else {
      tmp = qrmanager_ncols;
    }

    b_tol = 2.2204460492503131E-15 * static_cast<real_T>(tmp);
    if (b_tol >= 1.4901161193847656E-8) {
      b_tol = 1.4901161193847656E-8;
    }

    b_tol *= fabs(qrmanager_QR[0]);
    while ((r < minmn) && (!(fabs(qrmanager_QR[9 * r + r]) <= b_tol))) {
      r++;
    }
  }

  return r;
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static real_T STQMEKF_maxConstraintViolation(const
  srnx7tMxlsAQ9dn31gXFrqF_STQME_T *obj, const real_T x[153], int32_T ix0)
{
  real_T u1;
  real_T v;
  int32_T b;
  v = 0.0;
  b = static_cast<uint8_T>(obj->sizes[3]);
  for (int32_T idx = 0; idx < b; idx++) {
    u1 = -x[(ix0 + obj->indexLB[idx]) - 2] - obj->lb[obj->indexLB[idx] - 1];
    if ((!(v >= u1)) && (!rtIsNaN(u1))) {
      v = u1;
    }
  }

  for (int32_T idx = 0; idx < 8; idx++) {
    u1 = x[(ix0 + obj->indexUB[idx]) - 2] - 1.0;
    if ((!(v >= u1)) && (!rtIsNaN(u1))) {
      v = u1;
    }
  }

  return v;
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static boolean_T STQMEKF_feasibleX0ForWorkingSet(real_T workspace[153], real_T
  xCurrent[9], const srnx7tMxlsAQ9dn31gXFrqF_STQME_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_STQME_T *qrmanager)
{
  real_T B[153];
  real_T constrViolation_basicX;
  real_T temp;
  int32_T b_ar;
  int32_T exitg1;
  int32_T h_k;
  int32_T iAcol;
  int32_T ix;
  int32_T ix0_tmp;
  int32_T jBcol;
  int32_T mWConstr;
  int32_T nVar;
  int32_T rankQR;
  int32_T s;
  int32_T tmp;
  boolean_T guard1;
  boolean_T nonDegenerateWset;
  mWConstr = workingset->nActiveConstr;
  nVar = workingset->nVar;
  nonDegenerateWset = true;
  if (workingset->nActiveConstr != 0) {
    if (workingset->nActiveConstr >= workingset->nVar) {
      h_k = static_cast<uint8_T>(workingset->nVar);
      for (rankQR = 0; rankQR < h_k; rankQR++) {
        ix = 9 * rankQR;
        for (ix0_tmp = 0; ix0_tmp < mWConstr; ix0_tmp++) {
          qrmanager->QR[ix0_tmp + ix] = workingset->ATwset[9 * ix0_tmp + rankQR];
        }

        qrmanager->jpvt[rankQR] = 0;
      }

      if (workingset->nActiveConstr * workingset->nVar == 0) {
        qrmanager->mrows = workingset->nActiveConstr;
        qrmanager->ncols = workingset->nVar;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = workingset->nActiveConstr;
        qrmanager->ncols = workingset->nVar;
        if (workingset->nActiveConstr <= workingset->nVar) {
          qrmanager->minRowCol = workingset->nActiveConstr;
        } else {
          qrmanager->minRowCol = workingset->nVar;
        }

        STQMEKF_xgeqp3(qrmanager->QR, workingset->nActiveConstr,
                       workingset->nVar, qrmanager->jpvt, qrmanager->tau);
      }

      STQMEKF_computeQ_(qrmanager, qrmanager->mrows);
      rankQR = STQMEKF_rank(qrmanager->QR, qrmanager->mrows, qrmanager->ncols);
      for (ix0_tmp = 0; ix0_tmp < mWConstr; ix0_tmp++) {
        workspace[ix0_tmp] = workingset->bwset[ix0_tmp];
        workspace[ix0_tmp + 17] = workingset->bwset[ix0_tmp];
      }

      jBcol = (workingset->nActiveConstr - 1) * 9 + 1;
      for (ix = 1; ix <= jBcol; ix += 9) {
        temp = 0.0;
        iAcol = (ix + nVar) - 1;
        for (ix0_tmp = ix; ix0_tmp <= iAcol; ix0_tmp++) {
          temp += workingset->ATwset[ix0_tmp - 1] * xCurrent[ix0_tmp - ix];
        }

        ix0_tmp = div_nde_s32_floor(ix - 1, 9);
        workspace[ix0_tmp] -= temp;
      }

      memcpy(&B[0], &workspace[0], 153U * sizeof(real_T));
      for (ix0_tmp = 0; ix0_tmp <= 17; ix0_tmp += 17) {
        jBcol = ix0_tmp + nVar;
        for (ix = ix0_tmp + 1; ix <= jBcol; ix++) {
          workspace[ix - 1] = 0.0;
        }
      }

      iAcol = -1;
      for (ix0_tmp = 0; ix0_tmp <= 17; ix0_tmp += 17) {
        b_ar = -1;
        s = ix0_tmp + nVar;
        for (ix = ix0_tmp + 1; ix <= s; ix++) {
          temp = 0.0;
          for (jBcol = 0; jBcol < mWConstr; jBcol++) {
            temp += qrmanager->Q[(jBcol + b_ar) + 1] * B[(jBcol + iAcol) + 1];
          }

          workspace[ix - 1] += temp;
          b_ar += 9;
        }

        iAcol += 17;
      }

      for (mWConstr = 0; mWConstr < 2; mWConstr++) {
        iAcol = 17 * mWConstr - 1;
        for (ix = rankQR; ix >= 1; ix--) {
          b_ar = (ix - 1) * 9;
          ix0_tmp = ix + iAcol;
          temp = workspace[ix0_tmp];
          if (temp != 0.0) {
            workspace[ix0_tmp] = temp / qrmanager->QR[(ix + b_ar) - 1];
            s = static_cast<uint8_T>(ix - 1);
            for (jBcol = 0; jBcol < s; jBcol++) {
              tmp = (jBcol + iAcol) + 1;
              workspace[tmp] -= qrmanager->QR[jBcol + b_ar] * workspace[ix0_tmp];
            }
          }
        }
      }

      for (mWConstr = rankQR + 1; mWConstr <= nVar; mWConstr++) {
        workspace[mWConstr - 1] = 0.0;
        workspace[mWConstr + 16] = 0.0;
      }

      for (rankQR = 0; rankQR < h_k; rankQR++) {
        workspace[qrmanager->jpvt[rankQR] + 33] = workspace[rankQR];
      }

      for (rankQR = 0; rankQR < h_k; rankQR++) {
        workspace[rankQR] = workspace[rankQR + 34];
      }

      for (rankQR = 0; rankQR < h_k; rankQR++) {
        workspace[qrmanager->jpvt[rankQR] + 33] = workspace[rankQR + 17];
      }

      for (rankQR = 0; rankQR < h_k; rankQR++) {
        workspace[rankQR + 17] = workspace[rankQR + 34];
      }
    } else {
      if (workingset->nActiveConstr - 1 >= 0) {
        memset(&qrmanager->jpvt[0], 0, static_cast<uint32_T>
               (workingset->nActiveConstr) * sizeof(int32_T));
      }

      ix0_tmp = workingset->nVar * workingset->nActiveConstr;
      guard1 = false;
      if (ix0_tmp > 0) {
        for (rankQR = 0; rankQR < mWConstr; rankQR++) {
          ix0_tmp = 9 * rankQR;
          memcpy(&qrmanager->QR[ix0_tmp], &workingset->ATwset[ix0_tmp],
                 static_cast<uint8_T>(nVar) * sizeof(real_T));
        }

        guard1 = true;
      } else if (ix0_tmp == 0) {
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = workingset->nActiveConstr;
        qrmanager->minRowCol = 0;
      } else {
        guard1 = true;
      }

      if (guard1) {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = workingset->nActiveConstr;
        if (workingset->nVar <= workingset->nActiveConstr) {
          qrmanager->minRowCol = workingset->nVar;
        } else {
          qrmanager->minRowCol = workingset->nActiveConstr;
        }

        STQMEKF_xgeqp3(qrmanager->QR, workingset->nVar,
                       workingset->nActiveConstr, qrmanager->jpvt,
                       qrmanager->tau);
      }

      STQMEKF_computeQ_(qrmanager, qrmanager->minRowCol);
      rankQR = STQMEKF_rank(qrmanager->QR, qrmanager->mrows, qrmanager->ncols);
      for (h_k = 0; h_k < mWConstr; h_k++) {
        ix = (qrmanager->jpvt[h_k] - 1) * 9;
        temp = 0.0;
        jBcol = static_cast<uint8_T>(nVar);
        for (ix0_tmp = 0; ix0_tmp < jBcol; ix0_tmp++) {
          temp += workingset->ATwset[ix + ix0_tmp] * xCurrent[ix0_tmp];
        }

        constrViolation_basicX = workingset->bwset[qrmanager->jpvt[h_k] - 1];
        workspace[h_k] = constrViolation_basicX - temp;
        workspace[h_k + 17] = constrViolation_basicX;
      }

      ix = static_cast<uint8_T>(rankQR);
      for (h_k = 0; h_k < 2; h_k++) {
        jBcol = 17 * h_k;
        for (mWConstr = 0; mWConstr < ix; mWConstr++) {
          iAcol = 9 * mWConstr;
          b_ar = mWConstr + jBcol;
          temp = workspace[b_ar];
          for (ix0_tmp = 0; ix0_tmp < mWConstr; ix0_tmp++) {
            temp -= qrmanager->QR[ix0_tmp + iAcol] * workspace[ix0_tmp + jBcol];
          }

          workspace[b_ar] = temp / qrmanager->QR[mWConstr + iAcol];
        }
      }

      memcpy(&B[0], &workspace[0], 153U * sizeof(real_T));
      for (h_k = 0; h_k <= 17; h_k += 17) {
        ix0_tmp = h_k + nVar;
        for (mWConstr = h_k + 1; mWConstr <= ix0_tmp; mWConstr++) {
          workspace[mWConstr - 1] = 0.0;
        }
      }

      ix = 1;
      for (h_k = 0; h_k <= 17; h_k += 17) {
        jBcol = -1;
        iAcol = ix + rankQR;
        for (mWConstr = ix; mWConstr < iAcol; mWConstr++) {
          b_ar = h_k + nVar;
          for (ix0_tmp = h_k + 1; ix0_tmp <= b_ar; ix0_tmp++) {
            workspace[ix0_tmp - 1] += qrmanager->Q[(jBcol + ix0_tmp) - h_k] *
              B[mWConstr - 1];
          }

          jBcol += 9;
        }

        ix += 17;
      }
    }

    rankQR = 0;
    do {
      exitg1 = 0;
      if (rankQR <= static_cast<uint8_T>(nVar) - 1) {
        if (rtIsInf(workspace[rankQR]) || rtIsNaN(workspace[rankQR])) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          constrViolation_basicX = workspace[rankQR + 17];
          if (rtIsInf(constrViolation_basicX) || rtIsNaN(constrViolation_basicX))
          {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            rankQR++;
          }
        }
      } else {
        for (rankQR = 0; rankQR < nVar; rankQR++) {
          workspace[rankQR] += xCurrent[rankQR];
        }

        temp = STQMEKF_maxConstraintViolation(workingset, workspace, 1);
        constrViolation_basicX = STQMEKF_maxConstraintViolation(workingset,
          workspace, 18);
        if ((temp <= 2.2204460492503131E-16) || (temp < constrViolation_basicX))
        {
          memcpy(&xCurrent[0], &workspace[0], static_cast<uint8_T>(nVar) *
                 sizeof(real_T));
        } else {
          memcpy(&xCurrent[0], &workspace[17], static_cast<uint8_T>(nVar) *
                 sizeof(real_T));
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return nonDegenerateWset;
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static real_T STQMEK_maxConstraintViolation_b(const
  srnx7tMxlsAQ9dn31gXFrqF_STQME_T *obj, const real_T x[9])
{
  real_T u1;
  real_T v;
  int32_T b;
  v = 0.0;
  b = static_cast<uint8_T>(obj->sizes[3]);
  for (int32_T idx = 0; idx < b; idx++) {
    u1 = -x[obj->indexLB[idx] - 1] - obj->lb[obj->indexLB[idx] - 1];
    if ((!(v >= u1)) && (!rtIsNaN(u1))) {
      v = u1;
    }
  }

  for (int32_T idx = 0; idx < 8; idx++) {
    u1 = x[obj->indexUB[idx] - 1] - 1.0;
    if ((!(v >= u1)) && (!rtIsNaN(u1))) {
      v = u1;
    }
  }

  return v;
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_setProblemType(srnx7tMxlsAQ9dn31gXFrqF_STQME_T *obj, int32_T
  PROBLEM_TYPE)
{
  switch (PROBLEM_TYPE) {
   case 3:
    {
      int32_T b_idx;
      obj->nVar = 8;
      obj->mConstr = 16;
      if (obj->nWConstr[4] > 0) {
        int32_T b_idxUpperExisting;
        b_idxUpperExisting = obj->isActiveIdx[4] - 1;
        for (int32_T b = 0; b < 8; b++) {
          b_idx = b_idxUpperExisting + b;
          obj->isActiveConstr[b + 8] = obj->isActiveConstr[b_idx];
          obj->isActiveConstr[b_idx] = false;
        }
      }

      for (b_idx = 0; b_idx < 5; b_idx++) {
        obj->sizes[b_idx] = obj->sizesNormal[b_idx];
      }

      for (b_idx = 0; b_idx < 6; b_idx++) {
        obj->isActiveIdx[b_idx] = obj->isActiveIdxNormal[b_idx];
      }
    }
    break;

   case 1:
    {
      int32_T b;
      int32_T b_idx;
      int32_T b_idxUpperExisting;
      obj->nVar = 9;
      obj->mConstr = 17;
      for (b_idx = 0; b_idx < 5; b_idx++) {
        obj->sizes[b_idx] = obj->sizesPhaseOne[b_idx];
      }

      obj->indexLB[8] = 9;
      obj->lb[8] = 0.0;
      b = obj->nActiveConstr;
      for (b_idx = 1; b_idx <= b; b_idx++) {
        obj->ATwset[9 * (b_idx - 1) + 8] = -1.0;
      }

      b_idxUpperExisting = obj->isActiveIdx[4];
      if (obj->nWConstr[4] > 0) {
        for (b = 7; b >= 0; b--) {
          b_idx = b_idxUpperExisting + b;
          obj->isActiveConstr[b_idx] = obj->isActiveConstr[b_idx - 1];
        }
      } else {
        obj->isActiveConstr[16] = false;
      }

      obj->isActiveConstr[obj->isActiveIdx[4] - 1] = false;
      for (b_idx = 0; b_idx < 6; b_idx++) {
        obj->isActiveIdx[b_idx] = obj->isActiveIdxPhaseOne[b_idx];
      }
    }
    break;

   case 2:
    {
      obj->nVar = 8;
      obj->mConstr = 16;
      for (int32_T b_idx = 0; b_idx < 5; b_idx++) {
        obj->sizes[b_idx] = obj->sizesRegularized[b_idx];
      }

      if (obj->probType != 4) {
        int32_T b;
        if (obj->nWConstr[4] > 0) {
          for (int32_T b_idx = 0; b_idx < 8; b_idx++) {
            obj->isActiveConstr[b_idx + 9] = obj->isActiveConstr
              [(obj->isActiveIdx[4] + b_idx) - 1];
          }
        }

        b = obj->nActiveConstr;
        for (int32_T b_idx = 1; b_idx <= b; b_idx++) {
          int32_T b_idxUpperExisting;
          b_idxUpperExisting = (b_idx - 1) * 9 - 1;
          if (obj->Wid[b_idx - 1] == 3) {
            int32_T e;
            e = obj->Wlocalidx[b_idx - 1] + 7;
            if (e >= 9) {
              memset(&obj->ATwset[b_idxUpperExisting + 9], 0,
                     static_cast<uint32_T>(e - 8) * sizeof(real_T));
            }

            e = obj->Wlocalidx[b_idx - 1];
            obj->ATwset[(e + b_idxUpperExisting) + 8] = -1.0;
            e += 9;
            if (e <= 8) {
              memset(&obj->ATwset[e + b_idxUpperExisting], 0,
                     static_cast<uint32_T>(((b_idxUpperExisting - e) -
                       b_idxUpperExisting) + 9) * sizeof(real_T));
            }
          }
        }
      }

      for (int32_T b_idx = 0; b_idx < 6; b_idx++) {
        obj->isActiveIdx[b_idx] = obj->isActiveIdxRegularized[b_idx];
      }
    }
    break;

   default:
    {
      int32_T b;
      int32_T b_idx;
      int32_T b_idxUpperExisting;
      obj->nVar = 9;
      obj->mConstr = 17;
      for (b_idx = 0; b_idx < 5; b_idx++) {
        obj->sizes[b_idx] = obj->sizesRegPhaseOne[b_idx];
      }

      obj->indexLB[8] = 9;
      obj->lb[8] = 0.0;
      b = obj->nActiveConstr;
      for (b_idx = 1; b_idx <= b; b_idx++) {
        obj->ATwset[9 * (b_idx - 1) + 8] = -1.0;
      }

      b_idxUpperExisting = obj->isActiveIdx[4];
      if (obj->nWConstr[4] > 0) {
        for (b = 7; b >= 0; b--) {
          b_idx = b_idxUpperExisting + b;
          obj->isActiveConstr[b_idx] = obj->isActiveConstr[b_idx - 1];
        }
      } else {
        obj->isActiveConstr[16] = false;
      }

      obj->isActiveConstr[obj->isActiveIdx[4] - 1] = false;
      for (b_idx = 0; b_idx < 6; b_idx++) {
        obj->isActiveIdx[b_idx] = obj->isActiveIdxRegPhaseOne[b_idx];
      }
    }
    break;
  }

  obj->probType = PROBLEM_TYPE;
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_xgemv(int32_T m, int32_T n, const real_T A[64], int32_T lda,
  const real_T x[9], real_T y[8])
{
  if ((m != 0) && (n != 0)) {
    int32_T b;
    int32_T ix;
    if (m - 1 >= 0) {
      memset(&y[0], 0, static_cast<uint32_T>(m) * sizeof(real_T));
    }

    ix = 0;
    b = (n - 1) * lda + 1;
    for (int32_T b_iy = 1; lda < 0 ? b_iy >= b : b_iy <= b; b_iy += lda) {
      int32_T c;
      c = (b_iy + m) - 1;
      for (int32_T ia = b_iy; ia <= c; ia++) {
        int32_T tmp;
        tmp = ia - b_iy;
        y[tmp] += A[ia - 1] * x[ix];
      }

      ix++;
    }
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_computeGrad_StoreHx(s87IldPMN2ICa85Nu8z6UL_STQMEK_T *obj,
  const real_T H[64], const real_T f[8], const real_T x[9])
{
  int32_T b_ixlast;
  int32_T idx;
  switch (obj->objtype) {
   case 5:
    if (obj->nvar - 2 >= 0) {
      memset(&obj->grad[0], 0, static_cast<uint32_T>(obj->nvar - 1) * sizeof
             (real_T));
    }

    obj->grad[obj->nvar - 1] = obj->gammaScalar;
    break;

   case 3:
    STQMEKF_xgemv(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    if (obj->nvar - 1 >= 0) {
      memcpy(&obj->grad[0], &obj->Hx[0], static_cast<uint32_T>(obj->nvar) *
             sizeof(real_T));
    }

    if (obj->hasLinear && (obj->nvar >= 1)) {
      b_ixlast = obj->nvar;
      for (idx = 0; idx < b_ixlast; idx++) {
        obj->grad[idx] += f[idx];
      }
    }
    break;

   default:
    STQMEKF_xgemv(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    b_ixlast = obj->nvar + 1;
    for (idx = b_ixlast; idx < 9; idx++) {
      obj->Hx[idx - 1] = x[idx - 1] * 0.0;
    }

    memcpy(&obj->grad[0], &obj->Hx[0], sizeof(real_T) << 3U);
    if (obj->hasLinear && (obj->nvar >= 1)) {
      b_ixlast = obj->nvar;
      for (idx = 0; idx < b_ixlast; idx++) {
        obj->grad[idx] += f[idx];
      }
    }
    break;
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static real_T STQMEKF_computeFval_ReuseHx(const s87IldPMN2ICa85Nu8z6UL_STQMEK_T *
  obj, real_T workspace[153], const real_T f[8], const real_T x[9])
{
  real_T val;
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    {
      if (obj->hasLinear) {
        int32_T ixlast;
        ixlast = obj->nvar;
        for (int32_T k = 0; k < ixlast; k++) {
          workspace[k] = 0.5 * obj->Hx[k] + f[k];
        }

        val = 0.0;
        if (obj->nvar >= 1) {
          for (int32_T k = 0; k < ixlast; k++) {
            val += x[k] * workspace[k];
          }
        }
      } else {
        val = 0.0;
        if (obj->nvar >= 1) {
          int32_T ixlast;
          ixlast = obj->nvar;
          for (int32_T k = 0; k < ixlast; k++) {
            val += x[k] * obj->Hx[k];
          }
        }

        val *= 0.5;
      }
    }
    break;

   default:
    {
      if (obj->hasLinear) {
        int32_T ixlast;
        if (obj->nvar - 1 >= 0) {
          memcpy(&workspace[0], &f[0], static_cast<uint32_T>(obj->nvar) * sizeof
                 (real_T));
        }

        ixlast = 8 - obj->nvar;
        for (int32_T k = 0; k < ixlast; k++) {
          workspace[obj->nvar + k] = 0.0;
        }

        val = 0.0;
        for (int32_T k = 0; k < 8; k++) {
          real_T workspace_0;
          workspace_0 = 0.5 * obj->Hx[k] + workspace[k];
          workspace[k] = workspace_0;
          val += x[k] * workspace_0;
        }
      } else {
        int32_T ixlast;
        val = 0.0;
        for (int32_T k = 0; k < 8; k++) {
          val += x[k] * obj->Hx[k];
        }

        val *= 0.5;
        ixlast = obj->nvar + 1;
        for (int32_T k = ixlast; k < 9; k++) {
          val += x[k - 1] * 0.0;
        }
      }
    }
    break;
  }

  return val;
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_factorQR(sTj3C1mXm6Z2qP847mPxR8C_STQME_T *obj, const real_T
  A[153], int32_T mrows, int32_T ncols)
{
  int32_T i;
  int32_T ix0_tmp;
  boolean_T guard1;
  i = mrows * ncols;
  guard1 = false;
  if (i > 0) {
    for (i = 0; i < ncols; i++) {
      ix0_tmp = 9 * i;
      memcpy(&obj->QR[ix0_tmp], &A[ix0_tmp], static_cast<uint8_T>(mrows) *
             sizeof(real_T));
    }

    guard1 = true;
  } else if (i == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }

  if (guard1) {
    obj->usedPivoting = false;
    obj->mrows = mrows;
    obj->ncols = ncols;
    for (i = 0; i < ncols; i++) {
      obj->jpvt[i] = i + 1;
    }

    if (mrows <= ncols) {
      i = mrows;
    } else {
      i = ncols;
    }

    obj->minRowCol = i;
    memset(&obj->tau[0], 0, 9U * sizeof(real_T));
    if (i >= 1) {
      memset(&obj->tau[0], 0, 9U * sizeof(real_T));
      STQMEKF_qrf(obj->QR, mrows, ncols, i, obj->tau);
    }
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_xrotg_j(real_T *a, real_T *b, real_T *c, real_T *s)
{
  real_T absa;
  real_T absb;
  real_T roe;
  real_T scale;
  roe = *b;
  absa = fabs(*a);
  absb = fabs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    real_T ads;
    real_T bds;
    ads = absa / scale;
    bds = absb / scale;
    scale *= sqrt(ads * ads + bds * bds);
    if (roe < 0.0) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = scale;
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_squareQ_appendCol(sTj3C1mXm6Z2qP847mPxR8C_STQME_T *obj,
  const real_T vec[153], int32_T iv0)
{
  real_T b_c;
  real_T s;
  real_T temp;
  real_T temp_tmp;
  int32_T c_iy;
  int32_T e;
  int32_T ia;
  int32_T idx;
  int32_T iyend;
  if (obj->mrows <= obj->ncols + 1) {
    obj->minRowCol = obj->mrows;
  } else {
    obj->minRowCol = obj->ncols + 1;
  }

  idx = 9 * obj->ncols;
  if (obj->mrows != 0) {
    iyend = idx + obj->mrows;
    if (idx + 1 <= iyend) {
      memset(&obj->QR[idx], 0, static_cast<uint32_T>(iyend - idx) * sizeof
             (real_T));
    }

    iyend = (obj->mrows - 1) * 9 + 1;
    for (c_iy = 1; c_iy <= iyend; c_iy += 9) {
      b_c = 0.0;
      e = (c_iy + obj->mrows) - 1;
      for (ia = c_iy; ia <= e; ia++) {
        b_c += vec[((iv0 + ia) - c_iy) - 1] * obj->Q[ia - 1];
      }

      ia = div_nde_s32_floor(c_iy - 1, 9) + idx;
      obj->QR[ia] += b_c;
    }
  }

  obj->ncols++;
  obj->jpvt[obj->ncols - 1] = obj->ncols;
  for (idx = obj->mrows - 2; idx + 2 > obj->ncols; idx--) {
    c_iy = (obj->ncols - 1) * 9 + idx;
    temp = obj->QR[c_iy + 1];
    STQMEKF_xrotg_j(&obj->QR[c_iy], &temp, &b_c, &s);
    obj->QR[c_iy + 1] = temp;
    iyend = 9 * idx;
    ia = obj->mrows;
    if (obj->mrows >= 1) {
      for (c_iy = 0; c_iy < ia; c_iy++) {
        e = iyend + c_iy;
        temp_tmp = obj->Q[e + 9];
        temp = temp_tmp * s + obj->Q[e] * b_c;
        obj->Q[e + 9] = temp_tmp * b_c - obj->Q[e] * s;
        obj->Q[e] = temp;
      }
    }
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_deleteColMoveEnd(sTj3C1mXm6Z2qP847mPxR8C_STQME_T *obj,
  int32_T idx)
{
  real_T b_s;
  real_T b_temp;
  real_T b_temp_tmp_0;
  real_T c_c;
  int32_T QRk0;
  int32_T b_n;
  int32_T b_temp_tmp;
  int32_T e_k;
  int32_T i;
  int32_T idxRotGCol;
  int32_T k;
  int32_T temp_tmp;
  if (obj->usedPivoting) {
    i = 1;
    while ((i <= obj->ncols) && (obj->jpvt[i - 1] != idx)) {
      i++;
    }

    idx = i;
  }

  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    obj->jpvt[idx - 1] = obj->jpvt[obj->ncols - 1];
    QRk0 = obj->minRowCol;
    for (i = 0; i < QRk0; i++) {
      obj->QR[i + 9 * (idx - 1)] = obj->QR[(obj->ncols - 1) * 9 + i];
    }

    obj->ncols--;
    if (obj->mrows <= obj->ncols) {
      obj->minRowCol = obj->mrows;
    } else {
      obj->minRowCol = obj->ncols;
    }

    if (idx < obj->mrows) {
      if (obj->mrows - 1 <= obj->ncols) {
        i = obj->mrows - 1;
      } else {
        i = obj->ncols;
      }

      k = i;
      idxRotGCol = (idx - 1) * 9;
      while (k >= idx) {
        QRk0 = k + idxRotGCol;
        b_temp = obj->QR[QRk0];
        STQMEKF_xrotg_j(&obj->QR[QRk0 - 1], &b_temp, &c_c, &b_s);
        obj->QR[QRk0] = b_temp;
        e_k = (k - 1) * 9;
        obj->QR[k + e_k] = 0.0;
        QRk0 = 9 * idx + k;
        b_temp_tmp = obj->ncols - idx;
        if (b_temp_tmp >= 1) {
          for (b_n = 0; b_n < b_temp_tmp; b_n++) {
            temp_tmp = b_n * 9 + QRk0;
            b_temp_tmp_0 = obj->QR[temp_tmp - 1];
            b_temp = b_temp_tmp_0 * c_c + obj->QR[temp_tmp] * b_s;
            obj->QR[temp_tmp] = obj->QR[temp_tmp] * c_c - b_temp_tmp_0 * b_s;
            obj->QR[temp_tmp - 1] = b_temp;
          }
        }

        b_n = obj->mrows;
        if (obj->mrows >= 1) {
          for (QRk0 = 0; QRk0 < b_n; QRk0++) {
            b_temp_tmp = e_k + QRk0;
            b_temp_tmp_0 = obj->Q[b_temp_tmp + 9];
            b_temp = b_temp_tmp_0 * b_s + obj->Q[b_temp_tmp] * c_c;
            obj->Q[b_temp_tmp + 9] = b_temp_tmp_0 * c_c - obj->Q[b_temp_tmp] *
              b_s;
            obj->Q[b_temp_tmp] = b_temp;
          }
        }

        k--;
      }

      for (k = idx + 1; k <= i; k++) {
        idxRotGCol = (k - 1) * 9;
        QRk0 = k + idxRotGCol;
        b_temp = obj->QR[QRk0];
        STQMEKF_xrotg_j(&obj->QR[QRk0 - 1], &b_temp, &c_c, &b_s);
        obj->QR[QRk0] = b_temp;
        QRk0 = k * 10;
        b_n = obj->ncols - k;
        if (b_n >= 1) {
          for (e_k = 0; e_k < b_n; e_k++) {
            b_temp_tmp = e_k * 9 + QRk0;
            b_temp_tmp_0 = obj->QR[b_temp_tmp - 1];
            b_temp = b_temp_tmp_0 * c_c + obj->QR[b_temp_tmp] * b_s;
            obj->QR[b_temp_tmp] = obj->QR[b_temp_tmp] * c_c - b_temp_tmp_0 * b_s;
            obj->QR[b_temp_tmp - 1] = b_temp;
          }
        }

        e_k = obj->mrows;
        if (obj->mrows >= 1) {
          for (QRk0 = 0; QRk0 < e_k; QRk0++) {
            b_n = idxRotGCol + QRk0;
            b_temp_tmp_0 = obj->Q[b_n + 9];
            b_temp = b_temp_tmp_0 * b_s + obj->Q[b_n] * c_c;
            obj->Q[b_n + 9] = b_temp_tmp_0 * c_c - obj->Q[b_n] * b_s;
            obj->Q[b_n] = b_temp;
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_fullColLDL2_(smSS6fEwaptVbzYAOdOZgjB_STQME_T *obj, int32_T
  NColsRemain, real_T REG_PRIMAL)
{
  int32_T lastDiag;
  for (lastDiag = 0; lastDiag < NColsRemain; lastDiag++) {
    real_T obj_FMat;
    int32_T LD_diagOffset;
    int32_T b_k;
    int32_T subMatrixDim;
    LD_diagOffset = 10 * lastDiag;
    obj_FMat = obj->FMat[LD_diagOffset];
    if (fabs(obj_FMat) <= obj->regTol_) {
      obj_FMat += REG_PRIMAL;
      obj->FMat[LD_diagOffset] = obj_FMat;
    }

    obj_FMat = -1.0 / obj_FMat;
    subMatrixDim = (NColsRemain - lastDiag) - 2;
    for (b_k = 0; b_k <= subMatrixDim; b_k++) {
      obj->workspace_[b_k] = obj->FMat[(LD_diagOffset + b_k) + 1];
    }

    if (!(obj_FMat == 0.0)) {
      int32_T jA;
      jA = LD_diagOffset + 11;
      for (b_k = 0; b_k <= subMatrixDim; b_k++) {
        real_T temp;
        temp = obj->workspace_[b_k];
        if (temp != 0.0) {
          int32_T b;
          temp *= obj_FMat;
          b = subMatrixDim + jA;
          for (int32_T ijA = jA; ijA <= b; ijA++) {
            obj->FMat[ijA - 1] += obj->workspace_[ijA - jA] * temp;
          }
        }

        jA += 9;
      }
    }

    obj_FMat = 1.0 / obj->FMat[LD_diagOffset];
    b_k = LD_diagOffset + subMatrixDim;
    for (subMatrixDim = LD_diagOffset + 2; subMatrixDim <= b_k + 2; subMatrixDim
         ++) {
      obj->FMat[subMatrixDim - 1] *= obj_FMat;
    }
  }

  lastDiag = (NColsRemain - 1) * 10;
  if (fabs(obj->FMat[lastDiag]) <= obj->regTol_) {
    obj->FMat[lastDiag] += REG_PRIMAL;
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_xgemv_k(int32_T m, int32_T n, const real_T A[81], int32_T
  ia0, const real_T x[153], real_T y[9])
{
  if (m != 0) {
    int32_T b;
    int32_T ix;
    if (m - 1 >= 0) {
      memset(&y[0], 0, static_cast<uint32_T>(m) * sizeof(real_T));
    }

    ix = 0;
    b = (n - 1) * 9 + ia0;
    for (int32_T b_iy = ia0; b_iy <= b; b_iy += 9) {
      int32_T c;
      c = (b_iy + m) - 1;
      for (int32_T ia = b_iy; ia <= c; ia++) {
        int32_T tmp;
        tmp = ia - b_iy;
        y[tmp] += A[ia - 1] * x[ix];
      }

      ix++;
    }
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_compute_deltax(const real_T H[64],
  sraTyWZlTzdIJhNDrRZT2SF_STQME_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_STQME_T
  *memspace, const sTj3C1mXm6Z2qP847mPxR8C_STQME_T *qrmanager,
  smSS6fEwaptVbzYAOdOZgjB_STQME_T *cholmanager, const
  s87IldPMN2ICa85Nu8z6UL_STQMEK_T *objective)
{
  real_T s;
  real_T smax;
  real_T temp;
  int32_T A_maxDiag_idx;
  int32_T ar;
  int32_T b_A_maxDiag_idx;
  int32_T br;
  int32_T e_ix;
  int32_T exitg1;
  int32_T h;
  int32_T i;
  int32_T ic;
  int32_T lastColC;
  int32_T mNull_tmp;
  int32_T nVar;
  int32_T nVars;
  int32_T nullStartIdx;
  nVar = qrmanager->mrows - 1;
  mNull_tmp = qrmanager->mrows - qrmanager->ncols;
  if (mNull_tmp <= 0) {
    if (qrmanager->mrows - 1 >= 0) {
      memset(&solution->searchDir[0], 0, static_cast<uint32_T>((qrmanager->mrows
               - 1) + 1) * sizeof(real_T));
    }
  } else {
    for (A_maxDiag_idx = 0; A_maxDiag_idx <= nVar; A_maxDiag_idx++) {
      solution->searchDir[A_maxDiag_idx] = -objective->grad[A_maxDiag_idx];
    }

    if (qrmanager->ncols <= 0) {
      if (objective->objtype == 3) {
        temp = 1.4901161193847656E-8 * cholmanager->scaleFactor *
          static_cast<real_T>(qrmanager->mrows);
        cholmanager->ndims = qrmanager->mrows;
        for (mNull_tmp = 0; mNull_tmp <= nVar; mNull_tmp++) {
          nullStartIdx = (nVar + 1) * mNull_tmp;
          nVars = 9 * mNull_tmp;
          for (A_maxDiag_idx = 0; A_maxDiag_idx <= nVar; A_maxDiag_idx++) {
            cholmanager->FMat[nVars + A_maxDiag_idx] = H[A_maxDiag_idx +
              nullStartIdx];
          }
        }

        if (qrmanager->mrows < 1) {
          A_maxDiag_idx = -1;
        } else {
          A_maxDiag_idx = 0;
          if (qrmanager->mrows > 1) {
            smax = fabs(cholmanager->FMat[0]);
            for (mNull_tmp = 2; mNull_tmp <= nVar + 1; mNull_tmp++) {
              s = fabs(cholmanager->FMat[(mNull_tmp - 1) * 10]);
              if (s > smax) {
                A_maxDiag_idx = mNull_tmp - 1;
                smax = s;
              }
            }
          }
        }

        smax = fabs(cholmanager->FMat[9 * A_maxDiag_idx + A_maxDiag_idx]) *
          2.2204460492503131E-16;
        s = fabs(temp);
        if ((smax >= s) || rtIsNaN(s)) {
          cholmanager->regTol_ = smax;
        } else {
          cholmanager->regTol_ = s;
        }

        STQMEKF_fullColLDL2_(cholmanager, qrmanager->mrows, temp);
        if (cholmanager->ConvexCheck) {
          mNull_tmp = 0;
          do {
            exitg1 = 0;
            if (mNull_tmp <= nVar) {
              if (cholmanager->FMat[9 * mNull_tmp + mNull_tmp] <= 0.0) {
                cholmanager->info = -mNull_tmp - 1;
                exitg1 = 1;
              } else {
                mNull_tmp++;
              }
            } else {
              cholmanager->ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          nVar = cholmanager->ndims;
          if (cholmanager->ndims != 0) {
            for (mNull_tmp = 0; mNull_tmp < nVar; mNull_tmp++) {
              nullStartIdx = mNull_tmp * 9 + mNull_tmp;
              nVars = (nVar - mNull_tmp) - 2;
              for (A_maxDiag_idx = 0; A_maxDiag_idx <= nVars; A_maxDiag_idx++) {
                b_A_maxDiag_idx = (A_maxDiag_idx + mNull_tmp) + 1;
                solution->searchDir[b_A_maxDiag_idx] -= cholmanager->FMat
                  [(A_maxDiag_idx + nullStartIdx) + 1] * solution->
                  searchDir[mNull_tmp];
              }
            }
          }

          for (mNull_tmp = 0; mNull_tmp < nVar; mNull_tmp++) {
            solution->searchDir[mNull_tmp] /= cholmanager->FMat[9 * mNull_tmp +
              mNull_tmp];
          }

          if (cholmanager->ndims != 0) {
            for (mNull_tmp = nVar; mNull_tmp >= 1; mNull_tmp--) {
              nullStartIdx = (mNull_tmp - 1) * 9;
              temp = solution->searchDir[mNull_tmp - 1];
              for (A_maxDiag_idx = nVar; A_maxDiag_idx >= mNull_tmp + 1;
                   A_maxDiag_idx--) {
                temp -= cholmanager->FMat[(nullStartIdx + A_maxDiag_idx) - 1] *
                  solution->searchDir[A_maxDiag_idx - 1];
              }

              solution->searchDir[mNull_tmp - 1] = temp;
            }
          }
        }
      }
    } else {
      A_maxDiag_idx = 9 * qrmanager->ncols;
      nullStartIdx = A_maxDiag_idx + 1;
      if (objective->objtype == 5) {
        for (nullStartIdx = 0; nullStartIdx < mNull_tmp; nullStartIdx++) {
          memspace->workspace_float[nullStartIdx] = -qrmanager->Q
            [(qrmanager->ncols + nullStartIdx) * 9 + nVar];
        }

        STQMEKF_xgemv_k(qrmanager->mrows, mNull_tmp, qrmanager->Q, A_maxDiag_idx
                        + 1, memspace->workspace_float, solution->searchDir);
      } else {
        if (objective->objtype == 3) {
          nVars = qrmanager->mrows;
          if ((qrmanager->mrows != 0) && (mNull_tmp != 0)) {
            br = A_maxDiag_idx;
            lastColC = (mNull_tmp - 1) * 17;
            for (b_A_maxDiag_idx = 0; b_A_maxDiag_idx <= lastColC;
                 b_A_maxDiag_idx += 17) {
              e_ix = b_A_maxDiag_idx + nVars;
              for (ic = b_A_maxDiag_idx + 1; ic <= e_ix; ic++) {
                memspace->workspace_float[ic - 1] = 0.0;
              }
            }

            for (b_A_maxDiag_idx = 0; b_A_maxDiag_idx <= lastColC;
                 b_A_maxDiag_idx += 17) {
              ar = -1;
              h = br + nVars;
              for (ic = br + 1; ic <= h; ic++) {
                i = b_A_maxDiag_idx + nVars;
                for (e_ix = b_A_maxDiag_idx + 1; e_ix <= i; e_ix++) {
                  memspace->workspace_float[e_ix - 1] += H[(ar + e_ix) -
                    b_A_maxDiag_idx] * qrmanager->Q[ic - 1];
                }

                ar += nVars;
              }

              br += 9;
            }
          }

          if (mNull_tmp != 0) {
            br = (mNull_tmp - 1) * 9;
            for (b_A_maxDiag_idx = 0; b_A_maxDiag_idx <= br; b_A_maxDiag_idx +=
                 9) {
              e_ix = b_A_maxDiag_idx + mNull_tmp;
              for (ic = b_A_maxDiag_idx + 1; ic <= e_ix; ic++) {
                cholmanager->FMat[ic - 1] = 0.0;
              }
            }

            lastColC = -1;
            for (b_A_maxDiag_idx = 0; b_A_maxDiag_idx <= br; b_A_maxDiag_idx +=
                 9) {
              ar = A_maxDiag_idx;
              h = b_A_maxDiag_idx + mNull_tmp;
              for (ic = b_A_maxDiag_idx + 1; ic <= h; ic++) {
                temp = 0.0;
                for (e_ix = 0; e_ix < nVars; e_ix++) {
                  temp += memspace->workspace_float[(e_ix + lastColC) + 1] *
                    qrmanager->Q[e_ix + ar];
                }

                cholmanager->FMat[ic - 1] += temp;
                ar += 9;
              }

              lastColC += 17;
            }
          }
        }

        temp = 1.4901161193847656E-8 * cholmanager->scaleFactor *
          static_cast<real_T>(mNull_tmp);
        cholmanager->ndims = mNull_tmp;
        b_A_maxDiag_idx = 0;
        if (mNull_tmp > 1) {
          smax = fabs(cholmanager->FMat[0]);
          for (nVars = 2; nVars <= mNull_tmp; nVars++) {
            s = fabs(cholmanager->FMat[(nVars - 1) * 10]);
            if (s > smax) {
              b_A_maxDiag_idx = nVars - 1;
              smax = s;
            }
          }
        }

        smax = fabs(cholmanager->FMat[9 * b_A_maxDiag_idx + b_A_maxDiag_idx]) *
          2.2204460492503131E-16;
        s = fabs(temp);
        if ((smax >= s) || rtIsNaN(s)) {
          cholmanager->regTol_ = smax;
        } else {
          cholmanager->regTol_ = s;
        }

        STQMEKF_fullColLDL2_(cholmanager, mNull_tmp, temp);
        if (cholmanager->ConvexCheck) {
          nVars = 0;
          do {
            exitg1 = 0;
            if (nVars <= mNull_tmp - 1) {
              if (cholmanager->FMat[9 * nVars + nVars] <= 0.0) {
                cholmanager->info = -nVars - 1;
                exitg1 = 1;
              } else {
                nVars++;
              }
            } else {
              cholmanager->ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          if (qrmanager->mrows != 0) {
            memset(&memspace->workspace_float[0], 0, static_cast<uint32_T>
                   (mNull_tmp) * sizeof(real_T));
            ic = ((mNull_tmp - 1) * 9 + A_maxDiag_idx) + 1;
            for (nVars = nullStartIdx; nVars <= ic; nVars += 9) {
              temp = 0.0;
              e_ix = nVars + nVar;
              for (b_A_maxDiag_idx = nVars; b_A_maxDiag_idx <= e_ix;
                   b_A_maxDiag_idx++) {
                temp += qrmanager->Q[b_A_maxDiag_idx - 1] * objective->
                  grad[b_A_maxDiag_idx - nVars];
              }

              b_A_maxDiag_idx = div_nde_s32_floor((nVars - A_maxDiag_idx) - 1, 9);
              memspace->workspace_float[b_A_maxDiag_idx] -= temp;
            }
          }

          nVars = cholmanager->ndims;
          if (cholmanager->ndims != 0) {
            for (nVar = 0; nVar < nVars; nVar++) {
              b_A_maxDiag_idx = nVar * 9 + nVar;
              ic = (nVars - nVar) - 2;
              for (nullStartIdx = 0; nullStartIdx <= ic; nullStartIdx++) {
                e_ix = (nullStartIdx + nVar) + 1;
                memspace->workspace_float[e_ix] -= cholmanager->FMat
                  [(nullStartIdx + b_A_maxDiag_idx) + 1] *
                  memspace->workspace_float[nVar];
              }
            }
          }

          nullStartIdx = cholmanager->ndims;
          for (nVar = 0; nVar < nullStartIdx; nVar++) {
            memspace->workspace_float[nVar] /= cholmanager->FMat[9 * nVar + nVar];
          }

          nVars = cholmanager->ndims;
          if (cholmanager->ndims != 0) {
            for (nVar = nVars; nVar >= 1; nVar--) {
              b_A_maxDiag_idx = (nVar - 1) * 9;
              temp = memspace->workspace_float[nVar - 1];
              for (nullStartIdx = nVars; nullStartIdx >= nVar + 1; nullStartIdx
                   --) {
                temp -= cholmanager->FMat[(b_A_maxDiag_idx + nullStartIdx) - 1] *
                  memspace->workspace_float[nullStartIdx - 1];
              }

              memspace->workspace_float[nVar - 1] = temp;
            }
          }

          STQMEKF_xgemv_k(qrmanager->mrows, mNull_tmp, qrmanager->Q,
                          A_maxDiag_idx + 1, memspace->workspace_float,
                          solution->searchDir);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static real_T STQMEKF_xnrm2_jd(int32_T n, const real_T x[9])
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[0]);
    } else {
      real_T scale;
      scale = 3.3121686421112381E-170;
      for (int32_T k = 0; k < n; k++) {
        real_T absxk;
        absxk = fabs(x[k]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_feasibleratiotest(const real_T solution_xstar[9], const
  real_T solution_searchDir[9], int32_T workingset_nVar, const real_T
  workingset_lb[9], const int32_T workingset_indexLB[9], const int32_T
  workingset_indexUB[9], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[17],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx)
{
  real_T denomTol;
  real_T phaseOneCorrectionP;
  real_T phaseOneCorrectionX;
  real_T pk_corrected;
  real_T ratio;
  real_T u0;
  int32_T b;
  int32_T idx;
  int32_T workingset_indexLB_0;
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  denomTol = 2.2204460492503131E-13 * STQMEKF_xnrm2_jd(workingset_nVar,
    solution_searchDir);
  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] * static_cast<
      real_T>(isPhaseOne);
    b = static_cast<uint8_T>(workingset_sizes[3] - 1);
    for (idx = 0; idx < b; idx++) {
      workingset_indexLB_0 = workingset_indexLB[idx];
      pk_corrected = -solution_searchDir[workingset_indexLB_0 - 1] -
        phaseOneCorrectionP;
      if ((pk_corrected > denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[3] + idx) - 1])) {
        ratio = -solution_xstar[workingset_indexLB_0 - 1] - phaseOneCorrectionX;
        u0 = fabs(ratio);
        if ((!(u0 <= 1.0E-8 - ratio)) && (!rtIsNaN(1.0E-8 - ratio))) {
          u0 = 1.0E-8 - ratio;
        }

        ratio = u0 / pk_corrected;
        if (ratio < *alpha) {
          *alpha = ratio;
          *constrType = 4;
          *constrIdx = idx + 1;
          *newBlocking = true;
        }
      }
    }

    b = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    phaseOneCorrectionX = -solution_searchDir[b];
    if ((phaseOneCorrectionX > denomTol) && (!workingset_isActiveConstr
         [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      ratio = -solution_xstar[b] - workingset_lb[b];
      u0 = fabs(ratio);
      if ((!(u0 <= 1.0E-8 - ratio)) && (!rtIsNaN(1.0E-8 - ratio))) {
        u0 = 1.0E-8 - ratio;
      }

      ratio = u0 / phaseOneCorrectionX;
      if (ratio < *alpha) {
        *alpha = ratio;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }
    }
  }

  if (workingset_nWConstr[4] < 8) {
    phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    for (b = 0; b < 8; b++) {
      idx = workingset_indexUB[b];
      pk_corrected = solution_searchDir[idx - 1] - phaseOneCorrectionP;
      if ((pk_corrected > denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[4] + b) - 1])) {
        ratio = (solution_xstar[idx - 1] - 1.0) - phaseOneCorrectionX;
        u0 = fabs(ratio);
        if ((!(u0 <= 1.0E-8 - ratio)) && (!rtIsNaN(1.0E-8 - ratio))) {
          u0 = 1.0E-8 - ratio;
        }

        ratio = u0 / pk_corrected;
        if (ratio < *alpha) {
          *alpha = ratio;
          *constrType = 5;
          *constrIdx = b + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (!isPhaseOne) {
    *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
    if (!(*alpha <= 1.0)) {
      *alpha = 1.0;
    }
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQM_addBoundToActiveSetMatrix_(srnx7tMxlsAQ9dn31gXFrqF_STQME_T *obj,
  int32_T TYPE, int32_T idx_local)
{
  int32_T colOffset;
  int32_T idx_bnd_local;
  obj->nWConstr[TYPE - 1]++;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE - 1] + idx_local) - 2] = true;
  obj->nActiveConstr++;
  obj->Wid[obj->nActiveConstr - 1] = TYPE;
  obj->Wlocalidx[obj->nActiveConstr - 1] = idx_local;
  colOffset = (obj->nActiveConstr - 1) * 9 - 1;
  if (TYPE == 5) {
    idx_bnd_local = obj->indexUB[idx_local - 1];
    obj->bwset[obj->nActiveConstr - 1] = 1.0;
  } else {
    idx_bnd_local = obj->indexLB[idx_local - 1];
    obj->bwset[obj->nActiveConstr - 1] = obj->lb[idx_bnd_local - 1];
  }

  if (static_cast<uint8_T>(idx_bnd_local - 1) - 1 >= 0) {
    memset(&obj->ATwset[colOffset + 1], 0, static_cast<uint8_T>(idx_bnd_local -
            1) * sizeof(real_T));
  }

  obj->ATwset[idx_bnd_local + colOffset] = static_cast<real_T>(TYPE == 5) * 2.0
    - 1.0;
  if (idx_bnd_local + 1 <= obj->nVar) {
    memset(&obj->ATwset[(idx_bnd_local + colOffset) + 1], 0,
           static_cast<uint32_T>(((obj->nVar + colOffset) - idx_bnd_local) -
            colOffset) * sizeof(real_T));
  }

  switch (obj->probType) {
   case 3:
   case 2:
    break;

   default:
    obj->ATwset[obj->nVar + colOffset] = -1.0;
    break;
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_addAineqConstr(const srnx7tMxlsAQ9dn31gXFrqF_STQME_T *obj)
{
  int32_T b;
  b = obj->nVar;
  for (int32_T idx = 0; idx < b; idx++) {
    // Check node always fails. would cause program termination and was eliminated 
  }

  // Check node always fails. would cause program termination and was eliminated 
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_compute_lambda(real_T workspace[153],
  sraTyWZlTzdIJhNDrRZT2SF_STQME_T *solution, const
  s87IldPMN2ICa85Nu8z6UL_STQMEK_T *objective, const
  sTj3C1mXm6Z2qP847mPxR8C_STQME_T *qrmanager)
{
  int32_T nActiveConstr_tmp_tmp;
  nActiveConstr_tmp_tmp = qrmanager->ncols;
  if (qrmanager->ncols > 0) {
    real_T c;
    int32_T b_idx;
    int32_T idxQR;
    boolean_T guard1;
    guard1 = false;
    if (objective->objtype != 4) {
      boolean_T nonDegenerate;
      if (qrmanager->mrows >= qrmanager->ncols) {
        idxQR = qrmanager->mrows;
      } else {
        idxQR = qrmanager->ncols;
      }

      c = 2.2204460492503131E-15 * static_cast<real_T>(idxQR);
      if (c >= 1.4901161193847656E-8) {
        c = 1.4901161193847656E-8;
      }

      nonDegenerate = ((qrmanager->mrows > 0) && (qrmanager->ncols > 0));
      if (nonDegenerate) {
        boolean_T guard2;
        b_idx = qrmanager->ncols;
        guard2 = false;
        if (qrmanager->mrows < qrmanager->ncols) {
          idxQR = (qrmanager->ncols - 1) * 9 + qrmanager->mrows;
          while ((b_idx > qrmanager->mrows) && (fabs(qrmanager->QR[idxQR - 1]) >=
                  c)) {
            b_idx--;
            idxQR -= 9;
          }

          nonDegenerate = (b_idx == qrmanager->mrows);
          if (!nonDegenerate) {
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          idxQR = (b_idx - 1) * 9 + b_idx;
          while ((b_idx >= 1) && (fabs(qrmanager->QR[idxQR - 1]) >= c)) {
            b_idx--;
            idxQR -= 10;
          }

          nonDegenerate = (b_idx == 0);
        }
      }

      if (!nonDegenerate) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      int32_T b_ix;
      int32_T jjA;
      if (qrmanager->mrows != 0) {
        memset(&workspace[0], 0, static_cast<uint32_T>(qrmanager->ncols) *
               sizeof(real_T));
        jjA = (qrmanager->ncols - 1) * 9 + 1;
        for (b_idx = 1; b_idx <= jjA; b_idx += 9) {
          c = 0.0;
          b_ix = (b_idx + qrmanager->mrows) - 1;
          for (idxQR = b_idx; idxQR <= b_ix; idxQR++) {
            c += qrmanager->Q[idxQR - 1] * objective->grad[idxQR - b_idx];
          }

          idxQR = div_nde_s32_floor(b_idx - 1, 9);
          workspace[idxQR] += c;
        }
      }

      for (b_idx = nActiveConstr_tmp_tmp; b_idx >= 1; b_idx--) {
        jjA = ((b_idx - 1) * 9 + b_idx) - 2;
        workspace[b_idx - 1] /= qrmanager->QR[jjA + 1];
        for (idxQR = 0; idxQR <= b_idx - 2; idxQR++) {
          b_ix = (b_idx - idxQR) - 2;
          workspace[b_ix] -= workspace[b_idx - 1] * qrmanager->QR[jjA - idxQR];
        }
      }

      for (b_idx = 0; b_idx < nActiveConstr_tmp_tmp; b_idx++) {
        solution->lambda[b_idx] = -workspace[b_idx];
      }
    }
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_phaseone(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_STQME_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_STQME_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_STQME_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_STQME_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_STQME_T
  *cholmanager, const sIOJhD9KwAkF5sEguPjYquC_STQME_T *runTimeOptions,
  s87IldPMN2ICa85Nu8z6UL_STQMEK_T *objective)
{
  real_T normDelta;
  real_T solution_lambda;
  int32_T e;
  int32_T exitg1;
  int32_T g;
  int32_T i;
  int32_T idxEndIneq;
  int32_T idxMinLambda;
  int32_T idxStartIneq;
  int32_T idxStartIneq_tmp;
  boolean_T exitg2;
  boolean_T guard1;
  boolean_T nonDegenerateWset;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  solution->xstar[8] = solution->maxConstr + 1.0;
  STQMEKF_setProblemType(workingset, 1);
  idxStartIneq_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
  idxEndIneq = idxStartIneq_tmp + 1;
  idxStartIneq = workingset->nActiveConstr;
  for (i = idxEndIneq; i <= idxStartIneq; i++) {
    workingset->isActiveConstr[(workingset->isActiveIdx[workingset->Wid[i - 1] -
      1] + workingset->Wlocalidx[i - 1]) - 2] = false;
  }

  workingset->nWConstr[2] = 0;
  workingset->nWConstr[3] = 0;
  workingset->nWConstr[4] = 0;
  workingset->nActiveConstr = idxStartIneq_tmp;
  memset(&objective->grad[0], 0, 9U * sizeof(real_T));
  memset(&objective->Hx[0], 0, sizeof(real_T) << 3U);
  objective->maxVar = 9;
  objective->beta = 0.0;
  objective->rho = 0.0;
  objective->prev_objtype = 3;
  objective->prev_nvar = 8;
  objective->prev_hasLinear = true;
  objective->objtype = 5;
  objective->nvar = 9;
  objective->gammaScalar = 1.0;
  objective->hasLinear = true;
  subProblemChanged = true;
  updateFval = true;
  idxEndIneq = 0;
  i = workingset->nVar;
  idxStartIneq = 0;
  STQMEKF_computeGrad_StoreHx(objective, H, f, solution->xstar);
  solution->fstar = STQMEKF_computeFval_ReuseHx(objective,
    memspace->workspace_float, f, solution->xstar);
  solution->state = -5;
  memset(&solution->lambda[0], 0, 17U * sizeof(real_T));
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      guard1 = false;
      if (subProblemChanged) {
        switch (idxEndIneq) {
         case 1:
          STQMEKF_squareQ_appendCol(qrmanager, workingset->ATwset, 9 *
            (workingset->nActiveConstr - 1) + 1);
          break;

         case -1:
          STQMEKF_deleteColMoveEnd(qrmanager, idxStartIneq);
          break;

         default:
          STQMEKF_factorQR(qrmanager, workingset->ATwset, i,
                           workingset->nActiveConstr);
          STQMEKF_computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        STQMEKF_compute_deltax(H, solution, memspace, qrmanager, cholmanager,
          objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          normDelta = STQMEKF_xnrm2_jd(i, solution->searchDir);
          guard1 = true;
        }
      } else {
        idxMinLambda = static_cast<uint8_T>(i);
        memset(&solution->searchDir[0], 0, static_cast<uint8_T>(i) * sizeof
               (real_T));
        normDelta = 0.0;
        guard1 = true;
      }

      if (guard1) {
        if ((!subProblemChanged) || (normDelta < 1.4901161193847657E-10) ||
            (workingset->nActiveConstr >= i)) {
          STQMEKF_compute_lambda(memspace->workspace_float, solution, objective,
            qrmanager);
          if ((solution->state != -7) || (workingset->nActiveConstr > i)) {
            idxMinLambda = 0;
            normDelta = 0.0 * runTimeOptions->ProbRelTolFactor * 0.0;
            e = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
            g = workingset->nActiveConstr;
            for (idxStartIneq_tmp = e; idxStartIneq_tmp <= g; idxStartIneq_tmp++)
            {
              solution_lambda = solution->lambda[idxStartIneq_tmp - 1];
              if (solution_lambda < normDelta) {
                normDelta = solution_lambda;
                idxMinLambda = idxStartIneq_tmp;
              }
            }

            if (idxMinLambda == 0) {
              solution->state = 1;
            } else {
              idxEndIneq = -1;
              idxStartIneq = idxMinLambda;
              subProblemChanged = true;
              STQMEKF_removeConstr(workingset, idxMinLambda);
              if (idxMinLambda < workingset->nActiveConstr + 1) {
                solution->lambda[idxMinLambda - 1] = solution->lambda
                  [workingset->nActiveConstr];
              }

              solution->lambda[workingset->nActiveConstr] = 0.0;
            }
          } else {
            idxStartIneq_tmp = workingset->nActiveConstr;
            idxEndIneq = 0;
            idxStartIneq = workingset->nActiveConstr;
            subProblemChanged = true;
            STQMEKF_removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda[idxStartIneq_tmp - 1] = 0.0;
          }

          updateFval = false;
        } else {
          STQMEKF_feasibleratiotest(solution->xstar, solution->searchDir,
            workingset->nVar, workingset->lb, workingset->indexLB,
            workingset->indexUB, workingset->sizes, workingset->isActiveIdx,
            workingset->isActiveConstr, workingset->nWConstr, true, &normDelta,
            &updateFval, &idxStartIneq_tmp, &idxMinLambda);
          if (updateFval) {
            switch (idxStartIneq_tmp) {
             case 3:
              STQMEKF_addAineqConstr(workingset);
              break;

             case 4:
              STQM_addBoundToActiveSetMatrix_(workingset, 4, idxMinLambda);
              break;

             default:
              STQM_addBoundToActiveSetMatrix_(workingset, 5, idxMinLambda);
              break;
            }

            idxEndIneq = 1;
          } else {
            if (objective->objtype == 5) {
              if (STQMEKF_xnrm2_jd(objective->nvar, solution->searchDir) > 100.0
                  * static_cast<real_T>(objective->nvar) * 1.4901161193847656E-8)
              {
                solution->state = 3;
              } else {
                solution->state = 4;
              }
            }

            subProblemChanged = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }

          if (!(normDelta == 0.0)) {
            for (idxStartIneq_tmp = 0; idxStartIneq_tmp < i; idxStartIneq_tmp++)
            {
              solution->xstar[idxStartIneq_tmp] += normDelta *
                solution->searchDir[idxStartIneq_tmp];
            }
          }

          STQMEKF_computeGrad_StoreHx(objective, H, f, solution->xstar);
          updateFval = true;
        }

        solution->iterations++;
        if (solution->iterations >= 5) {
          solution->state = 0;
        }

        if (solution->iterations - solution->iterations / 50 * 50 == 0) {
          solution->maxConstr = STQMEK_maxConstraintViolation_b(workingset,
            solution->xstar);
          if (solution->maxConstr - solution->xstar[8] > 1.0E-8) {
            memcpy(&solution->searchDir[0], &solution->xstar[0], 9U * sizeof
                   (real_T));
            nonDegenerateWset = STQMEKF_feasibleX0ForWorkingSet
              (memspace->workspace_float, solution->searchDir, workingset,
               qrmanager);
            if ((!nonDegenerateWset) && (solution->state != 0)) {
              solution->state = -2;
            }

            idxEndIneq = 0;
            normDelta = STQMEK_maxConstraintViolation_b(workingset,
              solution->searchDir);
            if (normDelta < solution->maxConstr) {
              memcpy(&solution->xstar[0], &solution->searchDir[0], 9U * sizeof
                     (real_T));
            }
          }
        }

        if (updateFval) {
          solution->fstar = STQMEKF_computeFval_ReuseHx(objective,
            memspace->workspace_float, f, solution->xstar);
          if ((solution->fstar < 1.0E-8) && (solution->state != 0)) {
            solution->state = 2;
          }
        }
      }
    } else {
      if (!updateFval) {
        solution->fstar = STQMEKF_computeFval_ReuseHx(objective,
          memspace->workspace_float, f, solution->xstar);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (workingset->isActiveConstr[(workingset->isActiveIdx[3] + workingset->
       sizes[3]) - 2]) {
    i = 1;
    exitg2 = false;
    while ((!exitg2) && (i <= workingset->nActiveConstr)) {
      if ((workingset->Wid[i - 1] == 4) && (workingset->Wlocalidx[i - 1] ==
           workingset->sizes[3])) {
        STQMEKF_removeConstr(workingset, i);
        exitg2 = true;
      } else {
        i++;
      }
    }
  }

  for (i = workingset->nActiveConstr; i > 8; i--) {
    STQMEKF_removeConstr(workingset, i);
  }

  solution->maxConstr = solution->xstar[8];
  STQMEKF_setProblemType(workingset, 3);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static int32_T STQMEKF_RemoveDependentEq_(sLLWTJNyuJQrAxk3RwmbzBG_STQME_T
  *memspace, const srnx7tMxlsAQ9dn31gXFrqF_STQME_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_STQME_T *qrmanager)
{
  real_T b_tol;
  real_T qtb;
  int32_T b_tmp;
  int32_T c_idx;
  int32_T idxDiag;
  int32_T idx_col;
  int32_T idx_row;
  int32_T ix;
  int32_T mTotalWorkingEq_tmp;
  int32_T mWorkingFixed;
  int32_T nDepInd;
  boolean_T exitg1;
  mWorkingFixed = workingset->nWConstr[0];
  mTotalWorkingEq_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
  nDepInd = 0;
  if (mTotalWorkingEq_tmp > 0) {
    b_tmp = static_cast<uint8_T>(workingset->nVar);
    for (idx_row = 0; idx_row < mTotalWorkingEq_tmp; idx_row++) {
      for (idx_col = 0; idx_col < b_tmp; idx_col++) {
        qrmanager->QR[idx_row + 9 * idx_col] = workingset->ATwset[9 * idx_row +
          idx_col];
      }
    }

    nDepInd = mTotalWorkingEq_tmp - workingset->nVar;
    if (nDepInd <= 0) {
      nDepInd = 0;
    }

    memset(&qrmanager->jpvt[0], 0, static_cast<uint8_T>(workingset->nVar) *
           sizeof(int32_T));
    idx_row = mTotalWorkingEq_tmp * workingset->nVar;
    if (idx_row == 0) {
      qrmanager->mrows = mTotalWorkingEq_tmp;
      qrmanager->ncols = workingset->nVar;
      qrmanager->minRowCol = 0;
    } else {
      qrmanager->usedPivoting = true;
      qrmanager->mrows = mTotalWorkingEq_tmp;
      qrmanager->ncols = workingset->nVar;
      if (mTotalWorkingEq_tmp <= workingset->nVar) {
        qrmanager->minRowCol = mTotalWorkingEq_tmp;
      } else {
        qrmanager->minRowCol = workingset->nVar;
      }

      STQMEKF_xgeqp3(qrmanager->QR, mTotalWorkingEq_tmp, workingset->nVar,
                     qrmanager->jpvt, qrmanager->tau);
    }

    if (mTotalWorkingEq_tmp >= workingset->nVar) {
      idx_col = mTotalWorkingEq_tmp;
    } else {
      idx_col = workingset->nVar;
    }

    b_tol = 2.2204460492503131E-15 * static_cast<real_T>(idx_col);
    if (b_tol >= 1.4901161193847656E-8) {
      b_tol = 1.4901161193847656E-8;
    }

    if (workingset->nVar <= mTotalWorkingEq_tmp) {
      idx_col = workingset->nVar;
    } else {
      idx_col = mTotalWorkingEq_tmp;
    }

    idxDiag = (idx_col - 1) * 9 + idx_col;
    while ((idxDiag > 0) && (fabs(qrmanager->QR[idxDiag - 1]) < b_tol * fabs
            (qrmanager->QR[0]))) {
      idxDiag -= 10;
      nDepInd++;
    }

    if (nDepInd > 0) {
      STQMEKF_computeQ_(qrmanager, qrmanager->mrows);
      c_idx = 0;
      exitg1 = false;
      while ((!exitg1) && (c_idx <= nDepInd - 1)) {
        ix = ((mTotalWorkingEq_tmp - c_idx) - 1) * 9;
        qtb = 0.0;
        for (idxDiag = 0; idxDiag < mTotalWorkingEq_tmp; idxDiag++) {
          qtb += qrmanager->Q[ix + idxDiag] * workingset->bwset[idxDiag];
        }

        if (fabs(qtb) >= b_tol) {
          nDepInd = -1;
          exitg1 = true;
        } else {
          c_idx++;
        }
      }
    }

    if (nDepInd > 0) {
      for (idxDiag = 0; idxDiag < mTotalWorkingEq_tmp; idxDiag++) {
        ix = 9 * idxDiag;
        memcpy(&qrmanager->QR[ix], &workingset->ATwset[ix], static_cast<uint32_T>
               (b_tmp) * sizeof(real_T));
      }

      for (b_tmp = 0; b_tmp < mWorkingFixed; b_tmp++) {
        qrmanager->jpvt[b_tmp] = 1;
      }

      b_tmp = workingset->nWConstr[0] + 1;
      if (b_tmp <= mTotalWorkingEq_tmp) {
        memset(&qrmanager->jpvt[b_tmp + -1], 0, static_cast<uint32_T>
               ((mTotalWorkingEq_tmp - b_tmp) + 1) * sizeof(int32_T));
      }

      if (idx_row == 0) {
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = mTotalWorkingEq_tmp;
        qrmanager->minRowCol = 0;
      } else {
        qrmanager->usedPivoting = true;
        qrmanager->mrows = workingset->nVar;
        qrmanager->ncols = mTotalWorkingEq_tmp;
        qrmanager->minRowCol = idx_col;
        STQMEKF_xgeqp3(qrmanager->QR, workingset->nVar, mTotalWorkingEq_tmp,
                       qrmanager->jpvt, qrmanager->tau);
      }

      for (mWorkingFixed = 0; mWorkingFixed < nDepInd; mWorkingFixed++) {
        memspace->workspace_int[mWorkingFixed] = qrmanager->jpvt
          [(mTotalWorkingEq_tmp - nDepInd) + mWorkingFixed];
      }

      STQMEKF_countsort(memspace->workspace_int, nDepInd,
                        memspace->workspace_sort, 1, mTotalWorkingEq_tmp);
      if (mTotalWorkingEq_tmp != 0) {
        for (mWorkingFixed = nDepInd; mWorkingFixed >= 1; mWorkingFixed--) {
          if (memspace->workspace_int[mWorkingFixed - 1] <= mTotalWorkingEq_tmp)
          {
            // Check node always fails. would cause program termination and was eliminated 
          }
        }
      }
    }
  }

  return nDepInd;
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_ratiotest(const real_T solution_xstar[9], const real_T
  solution_searchDir[9], int32_T workingset_nVar, const real_T workingset_lb[9],
  const int32_T workingset_indexLB[9], const int32_T workingset_indexUB[9],
  const int32_T workingset_sizes[5], const int32_T workingset_isActiveIdx[6],
  const boolean_T workingset_isActiveConstr[17], const int32_T
  workingset_nWConstr[5], real_T *toldelta, real_T *alpha, boolean_T
  *newBlocking, int32_T *constrType, int32_T *constrIdx)
{
  real_T denomTol;
  real_T p_max;
  real_T phaseOneCorrectionP;
  real_T phaseOneCorrectionX;
  real_T pk_corrected;
  real_T ratio;
  real_T ratio_tmp;
  real_T u0;
  int32_T b;
  int32_T idx;
  int32_T workingset_indexLB_0;
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  p_max = 0.0;
  denomTol = 2.2204460492503131E-13 * STQMEKF_xnrm2_jd(workingset_nVar,
    solution_searchDir);
  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] * 0.0;
    phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] * 0.0;
    b = static_cast<uint8_T>(workingset_sizes[3] - 1);
    for (idx = 0; idx < b; idx++) {
      workingset_indexLB_0 = workingset_indexLB[idx];
      pk_corrected = -solution_searchDir[workingset_indexLB_0 - 1] -
        phaseOneCorrectionP;
      if ((pk_corrected > denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[3] + idx) - 1])) {
        ratio_tmp = -solution_xstar[workingset_indexLB_0 - 1];
        ratio = (ratio_tmp - *toldelta) - phaseOneCorrectionX;
        u0 = fabs(ratio);
        if ((!(u0 <= 1.0E-8 - ratio)) && (!rtIsNaN(1.0E-8 - ratio))) {
          u0 = 1.0E-8 - ratio;
        }

        ratio = u0 / pk_corrected;
        if ((ratio <= *alpha) && (fabs(pk_corrected) > p_max)) {
          *alpha = ratio;
          *constrType = 4;
          *constrIdx = idx + 1;
          *newBlocking = true;
        }

        ratio = ratio_tmp - phaseOneCorrectionX;
        u0 = fabs(ratio);
        if ((!(u0 <= 1.0E-8 - ratio)) && (!rtIsNaN(1.0E-8 - ratio))) {
          u0 = 1.0E-8 - ratio;
        }

        ratio = u0 / pk_corrected;
        if (ratio < *alpha) {
          *alpha = ratio;
          *constrType = 4;
          *constrIdx = idx + 1;
          *newBlocking = true;
          p_max = fabs(pk_corrected);
        }
      }
    }

    idx = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    phaseOneCorrectionX = solution_searchDir[idx];
    if ((-phaseOneCorrectionX > denomTol) && (!workingset_isActiveConstr
         [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      ratio_tmp = -solution_xstar[idx] - workingset_lb[idx];
      ratio = ratio_tmp - *toldelta;
      u0 = fabs(ratio);
      if ((!(u0 <= 1.0E-8 - ratio)) && (!rtIsNaN(1.0E-8 - ratio))) {
        u0 = 1.0E-8 - ratio;
      }

      ratio = u0 / -phaseOneCorrectionX;
      if ((ratio <= *alpha) && (fabs(phaseOneCorrectionX) > p_max)) {
        *alpha = ratio;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }

      u0 = fabs(ratio_tmp);
      if ((!(u0 <= 1.0E-8 - ratio_tmp)) && (!rtIsNaN(1.0E-8 - ratio_tmp))) {
        u0 = 1.0E-8 - ratio_tmp;
      }

      ratio = u0 / -phaseOneCorrectionX;
      if (ratio < *alpha) {
        *alpha = ratio;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
        p_max = fabs(phaseOneCorrectionX);
      }
    }
  }

  if (workingset_nWConstr[4] < 8) {
    phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] * 0.0;
    phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] * 0.0;
    for (idx = 0; idx < 8; idx++) {
      b = workingset_indexUB[idx];
      pk_corrected = solution_searchDir[b - 1] - phaseOneCorrectionP;
      if ((pk_corrected > denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[4] + idx) - 1])) {
        ratio_tmp = solution_xstar[b - 1] - 1.0;
        ratio = (ratio_tmp - *toldelta) - phaseOneCorrectionX;
        u0 = fabs(ratio);
        if ((!(u0 <= 1.0E-8 - ratio)) && (!rtIsNaN(1.0E-8 - ratio))) {
          u0 = 1.0E-8 - ratio;
        }

        ratio = u0 / pk_corrected;
        if ((ratio <= *alpha) && (fabs(pk_corrected) > p_max)) {
          *alpha = ratio;
          *constrType = 5;
          *constrIdx = idx + 1;
          *newBlocking = true;
        }

        ratio = ratio_tmp - phaseOneCorrectionX;
        u0 = fabs(ratio);
        if ((!(u0 <= 1.0E-8 - ratio)) && (!rtIsNaN(1.0E-8 - ratio))) {
          u0 = 1.0E-8 - ratio;
        }

        ratio = u0 / pk_corrected;
        if (ratio < *alpha) {
          *alpha = ratio;
          *constrType = 5;
          *constrIdx = idx + 1;
          *newBlocking = true;
          p_max = fabs(pk_corrected);
        }
      }
    }
  }

  *toldelta += 6.608625846508183E-7;
  if (p_max > 0.0) {
    p_max = 6.608625846508183E-7 / p_max;
    if (!(*alpha >= p_max)) {
      *alpha = p_max;
    }
  }

  *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
  if (!(*alpha <= 1.0)) {
    *alpha = 1.0;
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_iterate(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_STQME_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_STQME_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_STQME_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_STQME_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_STQME_T
  *cholmanager, s87IldPMN2ICa85Nu8z6UL_STQMEK_T *objective, boolean_T
  runTimeOptions_RemainFeasible, real_T runTimeOptions_ProbRelTolFactor)
{
  real_T normDelta;
  real_T solution_lambda;
  real_T tolDelta;
  int32_T TYPE;
  int32_T activeConstrChangedType;
  int32_T activeSetChangeID;
  int32_T c;
  int32_T d;
  int32_T exitg1;
  int32_T globalActiveConstrIdx;
  int32_T localActiveConstrIdx;
  int32_T nVar;
  boolean_T guard1;
  boolean_T newBlocking;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  subProblemChanged = true;
  updateFval = true;
  activeSetChangeID = 0;
  TYPE = objective->objtype;
  tolDelta = 6.7434957617430445E-7;
  nVar = workingset->nVar;
  globalActiveConstrIdx = 0;
  STQMEKF_computeGrad_StoreHx(objective, H, f, solution->xstar);
  solution->fstar = STQMEKF_computeFval_ReuseHx(objective,
    memspace->workspace_float, f, solution->xstar);
  if (solution->iterations < 5) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }

  memset(&solution->lambda[0], 0, 17U * sizeof(real_T));
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      guard1 = false;
      if (subProblemChanged) {
        switch (activeSetChangeID) {
         case 1:
          STQMEKF_squareQ_appendCol(qrmanager, workingset->ATwset, 9 *
            (workingset->nActiveConstr - 1) + 1);
          break;

         case -1:
          STQMEKF_deleteColMoveEnd(qrmanager, globalActiveConstrIdx);
          break;

         default:
          STQMEKF_factorQR(qrmanager, workingset->ATwset, nVar,
                           workingset->nActiveConstr);
          STQMEKF_computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        STQMEKF_compute_deltax(H, solution, memspace, qrmanager, cholmanager,
          objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          normDelta = STQMEKF_xnrm2_jd(nVar, solution->searchDir);
          guard1 = true;
        }
      } else {
        localActiveConstrIdx = static_cast<uint8_T>(nVar);
        memset(&solution->searchDir[0], 0, static_cast<uint8_T>(nVar) * sizeof
               (real_T));
        normDelta = 0.0;
        guard1 = true;
      }

      if (guard1) {
        if ((!subProblemChanged) || (normDelta < 1.0E-8) ||
            (workingset->nActiveConstr >= nVar)) {
          STQMEKF_compute_lambda(memspace->workspace_float, solution, objective,
            qrmanager);
          if ((solution->state != -7) || (workingset->nActiveConstr > nVar)) {
            localActiveConstrIdx = 0;
            normDelta = 0.0 * runTimeOptions_ProbRelTolFactor *
              static_cast<real_T>(TYPE != 5);
            c = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
            d = workingset->nActiveConstr;
            for (activeConstrChangedType = c; activeConstrChangedType <= d;
                 activeConstrChangedType++) {
              solution_lambda = solution->lambda[activeConstrChangedType - 1];
              if (solution_lambda < normDelta) {
                normDelta = solution_lambda;
                localActiveConstrIdx = activeConstrChangedType;
              }
            }

            if (localActiveConstrIdx == 0) {
              solution->state = 1;
            } else {
              activeSetChangeID = -1;
              globalActiveConstrIdx = localActiveConstrIdx;
              subProblemChanged = true;
              STQMEKF_removeConstr(workingset, localActiveConstrIdx);
              if (localActiveConstrIdx < workingset->nActiveConstr + 1) {
                solution->lambda[localActiveConstrIdx - 1] = solution->
                  lambda[workingset->nActiveConstr];
              }

              solution->lambda[workingset->nActiveConstr] = 0.0;
            }
          } else {
            localActiveConstrIdx = workingset->nActiveConstr;
            activeSetChangeID = 0;
            globalActiveConstrIdx = workingset->nActiveConstr;
            subProblemChanged = true;
            STQMEKF_removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda[localActiveConstrIdx - 1] = 0.0;
          }

          updateFval = false;
        } else {
          updateFval = (TYPE == 5);
          if (updateFval || runTimeOptions_RemainFeasible) {
            STQMEKF_feasibleratiotest(solution->xstar, solution->searchDir,
              workingset->nVar, workingset->lb, workingset->indexLB,
              workingset->indexUB, workingset->sizes, workingset->isActiveIdx,
              workingset->isActiveConstr, workingset->nWConstr, updateFval,
              &normDelta, &newBlocking, &activeConstrChangedType,
              &localActiveConstrIdx);
          } else {
            STQMEKF_ratiotest(solution->xstar, solution->searchDir,
                              workingset->nVar, workingset->lb,
                              workingset->indexLB, workingset->indexUB,
                              workingset->sizes, workingset->isActiveIdx,
                              workingset->isActiveConstr, workingset->nWConstr,
                              &tolDelta, &normDelta, &newBlocking,
                              &activeConstrChangedType, &localActiveConstrIdx);
          }

          if (newBlocking) {
            switch (activeConstrChangedType) {
             case 3:
              STQMEKF_addAineqConstr(workingset);
              break;

             case 4:
              STQM_addBoundToActiveSetMatrix_(workingset, 4,
                localActiveConstrIdx);
              break;

             default:
              STQM_addBoundToActiveSetMatrix_(workingset, 5,
                localActiveConstrIdx);
              break;
            }

            activeSetChangeID = 1;
          } else {
            if (objective->objtype == 5) {
              if (STQMEKF_xnrm2_jd(objective->nvar, solution->searchDir) > 100.0
                  * static_cast<real_T>(objective->nvar) * 1.4901161193847656E-8)
              {
                solution->state = 3;
              } else {
                solution->state = 4;
              }
            }

            subProblemChanged = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }

          if (!(normDelta == 0.0)) {
            for (activeConstrChangedType = 0; activeConstrChangedType < nVar;
                 activeConstrChangedType++) {
              solution->xstar[activeConstrChangedType] += normDelta *
                solution->searchDir[activeConstrChangedType];
            }
          }

          STQMEKF_computeGrad_StoreHx(objective, H, f, solution->xstar);
          updateFval = true;
        }

        solution->iterations++;
        activeConstrChangedType = objective->nvar;
        if ((solution->iterations >= 5) && ((solution->state != 1) ||
             (objective->objtype == 5))) {
          solution->state = 0;
        }

        if (solution->iterations - solution->iterations / 50 * 50 == 0) {
          solution->maxConstr = STQMEK_maxConstraintViolation_b(workingset,
            solution->xstar);
          normDelta = solution->maxConstr;
          if (objective->objtype == 5) {
            normDelta = solution->maxConstr - solution->xstar[objective->nvar -
              1];
          }

          if (normDelta > 1.0E-8) {
            if (objective->nvar - 1 >= 0) {
              memcpy(&solution->searchDir[0], &solution->xstar[0],
                     static_cast<uint32_T>(objective->nvar) * sizeof(real_T));
            }

            newBlocking = STQMEKF_feasibleX0ForWorkingSet
              (memspace->workspace_float, solution->searchDir, workingset,
               qrmanager);
            if ((!newBlocking) && (solution->state != 0)) {
              solution->state = -2;
            }

            activeSetChangeID = 0;
            normDelta = STQMEK_maxConstraintViolation_b(workingset,
              solution->searchDir);
            if (normDelta < solution->maxConstr) {
              localActiveConstrIdx = static_cast<uint8_T>(objective->nvar);
              if (static_cast<uint8_T>(objective->nvar) - 1 >= 0) {
                memcpy(&solution->xstar[0], &solution->searchDir[0],
                       static_cast<uint8_T>(objective->nvar) * sizeof(real_T));
              }

              solution->maxConstr = normDelta;
            }
          }
        }

        if (updateFval) {
          solution->fstar = STQMEKF_computeFval_ReuseHx(objective,
            memspace->workspace_float, f, solution->xstar);
          if ((solution->fstar < -1.0E+20) && ((solution->state != 0) ||
               (objective->objtype != 5))) {
            solution->state = 2;
          }
        }
      }
    } else {
      if (!updateFval) {
        solution->fstar = STQMEKF_computeFval_ReuseHx(objective,
          memspace->workspace_float, f, solution->xstar);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_computeFirstOrderOpt_m(sraTyWZlTzdIJhNDrRZT2SF_STQME_T
  *solution, const s87IldPMN2ICa85Nu8z6UL_STQMEK_T *objective, int32_T
  workingset_nVar, const real_T workingset_ATwset[153], int32_T
  workingset_nActiveConstr, real_T workspace[153])
{
  real_T infNorm;
  int32_T k;
  boolean_T exitg1;
  memcpy(&workspace[0], &objective->grad[0], static_cast<uint8_T>
         (workingset_nVar) * sizeof(real_T));
  if (workingset_nActiveConstr != 0) {
    int32_T c;
    int32_T ix;
    ix = 0;
    c = (workingset_nActiveConstr - 1) * 9 + 1;
    for (k = 1; k <= c; k += 9) {
      int32_T d;
      d = (k + workingset_nVar) - 1;
      for (int32_T b = k; b <= d; b++) {
        int32_T tmp;
        tmp = b - k;
        workspace[tmp] += workingset_ATwset[b - 1] * solution->lambda[ix];
      }

      ix++;
    }
  }

  infNorm = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= static_cast<uint8_T>(workingset_nVar) - 1)) {
    real_T abs_workspace_i;
    abs_workspace_i = fabs(workspace[k]);
    if (rtIsNaN(abs_workspace_i)) {
      infNorm = (rtNaN);
      exitg1 = true;
    } else {
      if (!(infNorm >= abs_workspace_i)) {
        infNorm = abs_workspace_i;
      }

      k++;
    }
  }

  solution->firstorderopt = infNorm;
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_phaseone_o(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_STQME_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_STQME_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_STQME_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_STQME_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_STQME_T
  *cholmanager, s87IldPMN2ICa85Nu8z6UL_STQMEK_T *objective, const
  sIOJhD9KwAkF5sEguPjYquC_STQME_T *runTimeOptions)
{
  real_T normDelta;
  real_T solution_lambda;
  int32_T PROBTYPE_ORIG;
  int32_T b_nVar;
  int32_T e;
  int32_T exitg1;
  int32_T g;
  int32_T idxEndIneq;
  int32_T idxMinLambda;
  int32_T idxStartIneq;
  int32_T idxStartIneq_tmp;
  int32_T nVar_tmp;
  boolean_T exitg2;
  boolean_T guard1;
  boolean_T nonDegenerateWset;
  boolean_T subProblemChanged;
  boolean_T updateFval;
  PROBTYPE_ORIG = workingset->probType;
  nVar_tmp = workingset->nVar;
  solution->xstar[8] = solution->maxConstr + 1.0;
  if (workingset->probType == 3) {
    b_nVar = 1;
  } else {
    b_nVar = 4;
  }

  STQMEKF_setProblemType(workingset, b_nVar);
  idxEndIneq = workingset->nWConstr[0] + workingset->nWConstr[1];
  idxStartIneq_tmp = idxEndIneq + 1;
  idxStartIneq = workingset->nActiveConstr;
  for (b_nVar = idxStartIneq_tmp; b_nVar <= idxStartIneq; b_nVar++) {
    workingset->isActiveConstr[(workingset->isActiveIdx[workingset->Wid[b_nVar -
      1] - 1] + workingset->Wlocalidx[b_nVar - 1]) - 2] = false;
  }

  workingset->nWConstr[2] = 0;
  workingset->nWConstr[3] = 0;
  workingset->nWConstr[4] = 0;
  workingset->nActiveConstr = idxEndIneq;
  objective->prev_objtype = objective->objtype;
  objective->prev_nvar = objective->nvar;
  objective->prev_hasLinear = objective->hasLinear;
  objective->objtype = 5;
  objective->nvar = 9;
  objective->gammaScalar = 1.0;
  objective->hasLinear = true;
  subProblemChanged = true;
  updateFval = true;
  idxEndIneq = 0;
  idxStartIneq_tmp = workingset->nVar;
  idxStartIneq = 0;
  STQMEKF_computeGrad_StoreHx(objective, H, f, solution->xstar);
  solution->fstar = STQMEKF_computeFval_ReuseHx(objective,
    memspace->workspace_float, f, solution->xstar);
  solution->state = -5;
  memset(&solution->lambda[0], 0, 17U * sizeof(real_T));
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      guard1 = false;
      if (subProblemChanged) {
        switch (idxEndIneq) {
         case 1:
          STQMEKF_squareQ_appendCol(qrmanager, workingset->ATwset, 9 *
            (workingset->nActiveConstr - 1) + 1);
          break;

         case -1:
          STQMEKF_deleteColMoveEnd(qrmanager, idxStartIneq);
          break;

         default:
          STQMEKF_factorQR(qrmanager, workingset->ATwset, idxStartIneq_tmp,
                           workingset->nActiveConstr);
          STQMEKF_computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        STQMEKF_compute_deltax(H, solution, memspace, qrmanager, cholmanager,
          objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          normDelta = STQMEKF_xnrm2_jd(idxStartIneq_tmp, solution->searchDir);
          guard1 = true;
        }
      } else {
        idxMinLambda = static_cast<uint8_T>(idxStartIneq_tmp);
        memset(&solution->searchDir[0], 0, static_cast<uint8_T>(idxStartIneq_tmp)
               * sizeof(real_T));
        normDelta = 0.0;
        guard1 = true;
      }

      if (guard1) {
        if ((!subProblemChanged) || (normDelta < 1.4901161193847657E-10) ||
            (workingset->nActiveConstr >= idxStartIneq_tmp)) {
          STQMEKF_compute_lambda(memspace->workspace_float, solution, objective,
            qrmanager);
          if ((solution->state != -7) || (workingset->nActiveConstr >
               idxStartIneq_tmp)) {
            idxMinLambda = 0;
            normDelta = 0.0 * runTimeOptions->ProbRelTolFactor * 0.0;
            e = (workingset->nWConstr[0] + workingset->nWConstr[1]) + 1;
            g = workingset->nActiveConstr;
            for (b_nVar = e; b_nVar <= g; b_nVar++) {
              solution_lambda = solution->lambda[b_nVar - 1];
              if (solution_lambda < normDelta) {
                normDelta = solution_lambda;
                idxMinLambda = b_nVar;
              }
            }

            if (idxMinLambda == 0) {
              solution->state = 1;
            } else {
              idxEndIneq = -1;
              idxStartIneq = idxMinLambda;
              subProblemChanged = true;
              STQMEKF_removeConstr(workingset, idxMinLambda);
              if (idxMinLambda < workingset->nActiveConstr + 1) {
                solution->lambda[idxMinLambda - 1] = solution->lambda
                  [workingset->nActiveConstr];
              }

              solution->lambda[workingset->nActiveConstr] = 0.0;
            }
          } else {
            b_nVar = workingset->nActiveConstr;
            idxEndIneq = 0;
            idxStartIneq = workingset->nActiveConstr;
            subProblemChanged = true;
            STQMEKF_removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda[b_nVar - 1] = 0.0;
          }

          updateFval = false;
        } else {
          STQMEKF_feasibleratiotest(solution->xstar, solution->searchDir,
            workingset->nVar, workingset->lb, workingset->indexLB,
            workingset->indexUB, workingset->sizes, workingset->isActiveIdx,
            workingset->isActiveConstr, workingset->nWConstr, true, &normDelta,
            &updateFval, &b_nVar, &idxMinLambda);
          if (updateFval) {
            switch (b_nVar) {
             case 3:
              STQMEKF_addAineqConstr(workingset);
              break;

             case 4:
              STQM_addBoundToActiveSetMatrix_(workingset, 4, idxMinLambda);
              break;

             default:
              STQM_addBoundToActiveSetMatrix_(workingset, 5, idxMinLambda);
              break;
            }

            idxEndIneq = 1;
          } else {
            if (objective->objtype == 5) {
              if (STQMEKF_xnrm2_jd(objective->nvar, solution->searchDir) > 100.0
                  * static_cast<real_T>(objective->nvar) * 1.4901161193847656E-8)
              {
                solution->state = 3;
              } else {
                solution->state = 4;
              }
            }

            subProblemChanged = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }

          if (!(normDelta == 0.0)) {
            for (b_nVar = 0; b_nVar < idxStartIneq_tmp; b_nVar++) {
              solution->xstar[b_nVar] += normDelta * solution->searchDir[b_nVar];
            }
          }

          STQMEKF_computeGrad_StoreHx(objective, H, f, solution->xstar);
          updateFval = true;
        }

        solution->iterations++;
        idxMinLambda = objective->nvar;
        if ((solution->iterations >= 5) && ((solution->state != 1) ||
             (objective->objtype == 5))) {
          solution->state = 0;
        }

        if (solution->iterations - solution->iterations / 50 * 50 == 0) {
          solution->maxConstr = STQMEK_maxConstraintViolation_b(workingset,
            solution->xstar);
          normDelta = solution->maxConstr;
          if (objective->objtype == 5) {
            normDelta = solution->maxConstr - solution->xstar[objective->nvar -
              1];
          }

          if (normDelta > 1.0E-8) {
            if (objective->nvar - 1 >= 0) {
              memcpy(&solution->searchDir[0], &solution->xstar[0],
                     static_cast<uint32_T>(objective->nvar) * sizeof(real_T));
            }

            nonDegenerateWset = STQMEKF_feasibleX0ForWorkingSet
              (memspace->workspace_float, solution->searchDir, workingset,
               qrmanager);
            if ((!nonDegenerateWset) && (solution->state != 0)) {
              solution->state = -2;
            }

            idxEndIneq = 0;
            normDelta = STQMEK_maxConstraintViolation_b(workingset,
              solution->searchDir);
            if ((normDelta < solution->maxConstr) && (objective->nvar - 1 >= 0))
            {
              memcpy(&solution->xstar[0], &solution->searchDir[0],
                     static_cast<uint32_T>(objective->nvar) * sizeof(real_T));
            }
          }
        }

        if (updateFval) {
          solution->fstar = STQMEKF_computeFval_ReuseHx(objective,
            memspace->workspace_float, f, solution->xstar);
          if ((solution->fstar < 1.0E-8) && ((solution->state != 0) ||
               (objective->objtype != 5))) {
            solution->state = 2;
          }
        }
      }
    } else {
      if (!updateFval) {
        solution->fstar = STQMEKF_computeFval_ReuseHx(objective,
          memspace->workspace_float, f, solution->xstar);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (workingset->isActiveConstr[(workingset->isActiveIdx[3] + workingset->
       sizes[3]) - 2]) {
    b_nVar = 1;
    exitg2 = false;
    while ((!exitg2) && (b_nVar <= workingset->nActiveConstr)) {
      if ((workingset->Wid[b_nVar - 1] == 4) && (workingset->Wlocalidx[b_nVar -
           1] == workingset->sizes[3])) {
        STQMEKF_removeConstr(workingset, b_nVar);
        exitg2 = true;
      } else {
        b_nVar++;
      }
    }
  }

  b_nVar = workingset->nActiveConstr;
  while ((b_nVar > 0) && (b_nVar > nVar_tmp)) {
    STQMEKF_removeConstr(workingset, b_nVar);
    b_nVar--;
  }

  solution->maxConstr = solution->xstar[8];
  STQMEKF_setProblemType(workingset, PROBTYPE_ORIG);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
  real_T workspace[153], const real_T H[64], const real_T f[8], const real_T x[9])
{
  int32_T beta1;
  beta1 = 0;
  if (obj_hasLinear) {
    if (static_cast<uint8_T>(obj_nvar) - 1 >= 0) {
      memcpy(&workspace[0], &f[0], static_cast<uint8_T>(obj_nvar) * sizeof
             (real_T));
    }

    beta1 = 1;
  }

  if (obj_nvar != 0) {
    int32_T e;
    int32_T ix;
    if (beta1 != 1) {
      memset(&workspace[0], 0, static_cast<uint8_T>(obj_nvar) * sizeof(real_T));
    }

    ix = 0;
    e = (obj_nvar - 1) * obj_nvar + 1;
    for (beta1 = 1; obj_nvar < 0 ? beta1 >= e : beta1 <= e; beta1 += obj_nvar) {
      real_T c;
      int32_T g;
      c = 0.5 * x[ix];
      g = (beta1 + obj_nvar) - 1;
      for (int32_T b = beta1; b <= g; b++) {
        int32_T tmp;
        tmp = b - beta1;
        workspace[tmp] += H[b - 1] * c;
      }

      ix++;
    }
  }
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static real_T STQMEKF_computeFval(const s87IldPMN2ICa85Nu8z6UL_STQMEK_T *obj,
  real_T workspace[153], const real_T H[64], const real_T f[8], const real_T x[9])
{
  real_T val;
  int32_T idx;
  int32_T ixlast;
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    STQMEKF_linearForm_(obj->hasLinear, obj->nvar, workspace, H, f, x);
    val = 0.0;
    if (obj->nvar >= 1) {
      ixlast = obj->nvar;
      for (idx = 0; idx < ixlast; idx++) {
        val += x[idx] * workspace[idx];
      }
    }
    break;

   default:
    STQMEKF_linearForm_(obj->hasLinear, obj->nvar, workspace, H, f, x);
    ixlast = obj->nvar + 1;
    for (idx = ixlast; idx < 9; idx++) {
      workspace[idx - 1] = x[idx - 1] * 0.0;
    }

    val = 0.0;
    for (idx = 0; idx < 8; idx++) {
      val += x[idx] * workspace[idx];
    }
    break;
  }

  return val;
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static void STQMEKF_quadprog(const real_T H[64], const real_T f[8], const real_T
  x0[8], real_T x[8], real_T *fval, real_T *exitflag)
{
  s87IldPMN2ICa85Nu8z6UL_STQMEK_T objective;
  sIOJhD9KwAkF5sEguPjYquC_STQME_T runTimeOptions;
  sLLWTJNyuJQrAxk3RwmbzBG_STQME_T memspace;
  sTj3C1mXm6Z2qP847mPxR8C_STQME_T qrmanager;
  sraTyWZlTzdIJhNDrRZT2SF_STQME_T solution;
  srnx7tMxlsAQ9dn31gXFrqF_STQME_T workingset;
  real_T H_infnrm;
  real_T colSum;
  real_T f_infnrm;
  int32_T i;
  int32_T idxEndIneq;
  int32_T idx_global;
  boolean_T okWorkingSet;
  static const int8_T h_ub[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 0 };

  static const int8_T h_indexLB[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 0 };

  static const int8_T h_sizes[5] = { 0, 0, 0, 8, 8 };

  static const int8_T h_isActiveIdx[6] = { 1, 1, 1, 1, 9, 17 };

  static const int8_T h_sizesPhaseOne[5] = { 0, 0, 0, 9, 8 };

  static const int8_T h_isActiveIdxPhaseOne[6] = { 1, 1, 1, 1, 10, 18 };

  int32_T i_tmp;
  boolean_T guard1;
  boolean_T guard2;
  solution.fstar = 0.0;
  solution.firstorderopt = 0.0;
  memset(&solution.lambda[0], 0, 17U * sizeof(real_T));
  memset(&solution.searchDir[0], 0, 9U * sizeof(real_T));
  STQMEKF_B.obj.ndims = 0;
  STQMEKF_B.obj.info = 0;
  STQMEKF_B.obj.ConvexCheck = true;
  STQMEKF_B.obj.regTol_ = 0.0;
  H_infnrm = 0.0;
  f_infnrm = 0.0;
  for (i = 0; i < 8; i++) {
    solution.xstar[i] = x0[i];
    colSum = 0.0;
    for (idxEndIneq = 0; idxEndIneq < 8; idxEndIneq++) {
      colSum += fabs(H[(i << 3) + idxEndIneq]);
    }

    if ((!(H_infnrm >= colSum)) && (!rtIsNaN(colSum))) {
      H_infnrm = colSum;
    }

    colSum = fabs(f[i]);
    if ((!(f_infnrm >= colSum)) && (!rtIsNaN(colSum))) {
      f_infnrm = colSum;
    }
  }

  if (f_infnrm <= 1.0) {
    f_infnrm = 1.0;
  }

  if (f_infnrm >= H_infnrm) {
    H_infnrm = f_infnrm;
    runTimeOptions.ProbRelTolFactor = f_infnrm;
  } else {
    runTimeOptions.ProbRelTolFactor = H_infnrm;
  }

  STQMEKF_B.obj.scaleFactor = H_infnrm;
  memset(&objective.grad[0], 0, 9U * sizeof(real_T));
  memset(&objective.Hx[0], 0, sizeof(real_T) << 3U);
  objective.hasLinear = true;
  objective.nvar = 8;
  objective.maxVar = 9;
  objective.beta = 0.0;
  objective.rho = 0.0;
  objective.objtype = 3;
  objective.prev_objtype = 3;
  objective.prev_nvar = 0;
  objective.prev_hasLinear = false;
  objective.gammaScalar = 0.0;
  runTimeOptions.RemainFeasible = true;
  solution.state = 82;
  workingset.mConstr = 16;
  workingset.mConstrOrig = 16;
  workingset.mConstrMax = 17;
  workingset.nVar = 8;
  workingset.nVarOrig = 8;
  workingset.nVarMax = 9;
  workingset.ldA = 9;
  for (i = 0; i < 9; i++) {
    workingset.lb[i] = 0.0;
    workingset.ub[i] = h_ub[i];
    workingset.indexLB[i] = h_indexLB[i];
    workingset.indexUB[i] = h_indexLB[i];
    workingset.indexFixed[i] = 0;
  }

  workingset.mEqRemoved = 0;
  memset(&workingset.ATwset[0], 0, 153U * sizeof(real_T));
  workingset.nActiveConstr = 0;
  memset(&workingset.bwset[0], 0, 17U * sizeof(real_T));
  memset(&workingset.maxConstrWorkspace[0], 0, 17U * sizeof(real_T));
  for (i = 0; i < 5; i++) {
    workingset.sizes[i] = h_sizes[i];
    workingset.sizesNormal[i] = h_sizes[i];
    workingset.sizesPhaseOne[i] = h_sizesPhaseOne[i];
    workingset.sizesRegularized[i] = h_sizes[i];
    workingset.sizesRegPhaseOne[i] = h_sizesPhaseOne[i];
  }

  for (i = 0; i < 6; i++) {
    workingset.isActiveIdx[i] = h_isActiveIdx[i];
    workingset.isActiveIdxNormal[i] = h_isActiveIdx[i];
    workingset.isActiveIdxPhaseOne[i] = h_isActiveIdxPhaseOne[i];
    workingset.isActiveIdxRegularized[i] = h_isActiveIdx[i];
    workingset.isActiveIdxRegPhaseOne[i] = h_isActiveIdxPhaseOne[i];
  }

  memset(&workingset.Wid[0], 0, 17U * sizeof(int32_T));
  memset(&workingset.Wlocalidx[0], 0, 17U * sizeof(int32_T));
  for (i = 0; i < 17; i++) {
    workingset.isActiveConstr[i] = false;
  }

  for (i = 0; i < 5; i++) {
    workingset.nWConstr[i] = 0;
  }

  workingset.probType = 3;
  workingset.SLACK0 = 0.0;
  memset(&qrmanager.QR[0], 0, 153U * sizeof(real_T));
  memset(&qrmanager.Q[0], 0, 81U * sizeof(real_T));
  memset(&qrmanager.jpvt[0], 0, 17U * sizeof(int32_T));
  qrmanager.mrows = 0;
  qrmanager.ncols = 0;
  memset(&qrmanager.tau[0], 0, 9U * sizeof(real_T));
  qrmanager.minRowCol = 0;
  qrmanager.usedPivoting = false;
  STQMEKF_RemoveDependentIneq_(&workingset, &qrmanager, &memspace, 1.0);
  okWorkingSet = STQMEKF_feasibleX0ForWorkingSet(memspace.workspace_float,
    solution.xstar, &workingset, &qrmanager);
  if (!okWorkingSet) {
    STQMEKF_RemoveDependentIneq_(&workingset, &qrmanager, &memspace, 10.0);
    okWorkingSet = STQMEKF_feasibleX0ForWorkingSet(memspace.workspace_float,
      solution.xstar, &workingset, &qrmanager);
    if (!okWorkingSet) {
      solution.state = -7;
    }
  }

  if (solution.state >= 0) {
    solution.iterations = 0;
    solution.maxConstr = STQMEK_maxConstraintViolation_b(&workingset,
      solution.xstar);
    guard1 = false;
    if (solution.maxConstr > 1.0E-8) {
      STQMEKF_phaseone(H, f, &solution, &memspace, &workingset, &qrmanager,
                       &STQMEKF_B.obj, &runTimeOptions, &objective);
      if (solution.state == 0) {
      } else {
        solution.maxConstr = STQMEK_maxConstraintViolation_b(&workingset,
          solution.xstar);
        if (solution.maxConstr > 1.0E-8) {
          solution.fstar = STQMEKF_computeFval(&objective,
            memspace.workspace_float, H, f, solution.xstar);
          solution.state = -2;
        } else {
          if (solution.maxConstr > 0.0) {
            memcpy(&solution.searchDir[0], &solution.xstar[0], sizeof(real_T) <<
                   3U);
            solution.state = 82;
            i = STQMEKF_RemoveDependentEq_(&memspace, &workingset, &qrmanager);
            if ((i != -1) && (workingset.nActiveConstr <= 9)) {
              STQMEKF_RemoveDependentIneq_(&workingset, &qrmanager, &memspace,
                1.0);
              okWorkingSet = STQMEKF_feasibleX0ForWorkingSet
                (memspace.workspace_float, solution.xstar, &workingset,
                 &qrmanager);
              guard2 = false;
              if (!okWorkingSet) {
                STQMEKF_RemoveDependentIneq_(&workingset, &qrmanager, &memspace,
                  10.0);
                okWorkingSet = STQMEKF_feasibleX0ForWorkingSet
                  (memspace.workspace_float, solution.xstar, &workingset,
                   &qrmanager);
                if (!okWorkingSet) {
                  solution.state = -7;
                } else {
                  guard2 = true;
                }
              } else {
                guard2 = true;
              }

              if (guard2) {
                if (workingset.nWConstr[0] + workingset.nWConstr[1] ==
                    workingset.nVar) {
                  f_infnrm = STQMEK_maxConstraintViolation_b(&workingset,
                    solution.xstar);
                  if (f_infnrm > 1.0E-8) {
                    solution.state = -2;
                  }
                }
              }
            } else {
              solution.state = -3;
              i = (workingset.nWConstr[0] + workingset.nWConstr[1]) + 1;
              idxEndIneq = workingset.nActiveConstr;
              for (idx_global = i; idx_global <= idxEndIneq; idx_global++) {
                workingset.isActiveConstr
                  [(workingset.isActiveIdx[workingset.Wid[idx_global - 1] - 1] +
                    workingset.Wlocalidx[idx_global - 1]) - 2] = false;
              }

              workingset.nWConstr[2] = 0;
              workingset.nWConstr[3] = 0;
              workingset.nWConstr[4] = 0;
              workingset.nActiveConstr = workingset.nWConstr[0] +
                workingset.nWConstr[1];
            }

            f_infnrm = STQMEK_maxConstraintViolation_b(&workingset,
              solution.xstar);
            if (f_infnrm >= solution.maxConstr) {
              solution.maxConstr = f_infnrm;
              memcpy(&solution.xstar[0], &solution.searchDir[0], sizeof(real_T) <<
                     3U);
            }
          }

          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      STQMEKF_iterate(H, f, &solution, &memspace, &workingset, &qrmanager,
                      &STQMEKF_B.obj, &objective, true, H_infnrm);
      if (solution.state != -6) {
        solution.maxConstr = STQMEK_maxConstraintViolation_b(&workingset,
          solution.xstar);
        STQMEKF_computeFirstOrderOpt_m(&solution, &objective, workingset.nVar,
          workingset.ATwset, workingset.nActiveConstr, memspace.workspace_float);
        runTimeOptions.RemainFeasible = false;
        while ((solution.iterations < 5) && ((solution.state == -7) ||
                ((solution.state == 1) && ((solution.maxConstr > 1.0E-8) ||
                  (solution.firstorderopt > 1.0E-8 * H_infnrm))))) {
          STQMEKF_feasibleX0ForWorkingSet(memspace.workspace_float,
            solution.xstar, &workingset, &qrmanager);
          solution.state = 82;
          i = STQMEKF_RemoveDependentEq_(&memspace, &workingset, &qrmanager);
          if ((i != -1) && (workingset.nActiveConstr <= 9)) {
            STQMEKF_RemoveDependentIneq_(&workingset, &qrmanager, &memspace, 1.0);
            okWorkingSet = STQMEKF_feasibleX0ForWorkingSet
              (memspace.workspace_float, solution.xstar, &workingset, &qrmanager);
            guard2 = false;
            if (!okWorkingSet) {
              STQMEKF_RemoveDependentIneq_(&workingset, &qrmanager, &memspace,
                10.0);
              okWorkingSet = STQMEKF_feasibleX0ForWorkingSet
                (memspace.workspace_float, solution.xstar, &workingset,
                 &qrmanager);
              if (!okWorkingSet) {
                solution.state = -7;
              } else {
                guard2 = true;
              }
            } else {
              guard2 = true;
            }

            if (guard2) {
              if (workingset.nWConstr[0] + workingset.nWConstr[1] ==
                  workingset.nVar) {
                f_infnrm = STQMEK_maxConstraintViolation_b(&workingset,
                  solution.xstar);
                if (f_infnrm > 1.0E-8) {
                  solution.state = -2;
                }
              }
            }
          } else {
            solution.state = -3;
            i_tmp = workingset.nWConstr[0] + workingset.nWConstr[1];
            i = i_tmp + 1;
            idxEndIneq = workingset.nActiveConstr;
            for (idx_global = i; idx_global <= idxEndIneq; idx_global++) {
              workingset.isActiveConstr
                [(workingset.isActiveIdx[workingset.Wid[idx_global - 1] - 1] +
                  workingset.Wlocalidx[idx_global - 1]) - 2] = false;
            }

            workingset.nWConstr[2] = 0;
            workingset.nWConstr[3] = 0;
            workingset.nWConstr[4] = 0;
            workingset.nActiveConstr = i_tmp;
          }

          STQMEKF_phaseone_o(H, f, &solution, &memspace, &workingset, &qrmanager,
                             &STQMEKF_B.obj, &objective, &runTimeOptions);
          STQMEKF_iterate(H, f, &solution, &memspace, &workingset, &qrmanager,
                          &STQMEKF_B.obj, &objective, false, H_infnrm);
          solution.maxConstr = STQMEK_maxConstraintViolation_b(&workingset,
            solution.xstar);
          STQMEKF_computeFirstOrderOpt_m(&solution, &objective, workingset.nVar,
            workingset.ATwset, workingset.nActiveConstr,
            memspace.workspace_float);
        }
      }
    }
  }

  memcpy(&x[0], &solution.xstar[0], sizeof(real_T) << 3U);
  if (solution.state > 0) {
    *fval = solution.fstar;
  } else {
    *fval = STQMEKF_computeFval(&objective, memspace.workspace_float, H, f,
      solution.xstar);
  }

  switch (solution.state) {
   case 2:
    solution.state = -3;
    break;

   case -3:
    solution.state = -2;
    break;

   case 4:
    solution.state = -2;
    break;
  }

  *exitflag = solution.state;
}

// Function for MATLAB Function: '<S228>/MATLAB Function5'
static real_T STQMEKF_maximum_i(const real_T x[8])
{
  real_T ex;
  int32_T idx;
  int32_T k;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 9)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    for (k = idx + 1; k < 9; k++) {
      real_T x_0;
      x_0 = x[k - 1];
      if (ex < x_0) {
        ex = x_0;
      }
    }
  }

  return ex;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void STQMEKF_pause(real_T varargin_1)
{
  coderTimespec b_timespec;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  if (STQMEKF_DW.pauseState == 0) {
    real_T delay;
    real_T delayInt;
    delay = varargin_1;
    if ((varargin_1 < 0.0) || rtIsNaN(varargin_1)) {
      delay = 0.0;
    }

    delayInt = floor(delay);
    if (delayInt > 4.294967295E+9) {
      delayInt = 4.294967295E+9;
      delay = 0.0;
    } else {
      delay -= delayInt;
    }

    b_timespec.tv_sec = delayInt;
    if (delay > 0.0) {
      b_timespec.tv_nsec = floor(delay * 1.0E+9);
    } else {
      b_timespec.tv_nsec = 0.0;
    }

    coderTimeSleep(&b_timespec);
  }

  // End of Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
}

static void S_bmi160_set_EnableSecondaryMag(b_bmi160_STQMEKF_T *obj)
{
  b_bmi160_STQMEKF_T *obj_0;
  b_bmi160_STQMEKF_T *obj_1;
  e_matlabshared_devicedrivers__T *obj_3;
  f_matlabshared_sensors_coder__T *obj_2;
  uint8_T b_data[2];
  uint8_T b_status;
  uint8_T slaveAddress;
  uint8_T val;
  obj_0 = obj;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_2 = obj->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 25U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  STQMEKF_pause(0.06);
  obj_1 = obj_0;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 55U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  STQMEKF_pause(0.001);
  obj_2 = obj_1->Device;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 154U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  STQMEKF_pause(0.001);
  obj_2 = obj_1->Device;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 192U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  STQMEKF_pause(0.001);
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 5U;
  b_data[1] = 32U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  obj_2 = obj_0->Device;
  b_status = 75U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 75U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 1U) | 32);
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  STQMEKF_pause(0.001);
  obj_2 = obj_0->Device;
  b_status = 76U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 76U;
  b_data[1] = 131U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  STQMEKF_pause(0.001);
  obj_2 = obj_0->Device;
  b_status = 107U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 107U;
  b_data[1] = 32U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  STQMEKF_pause(0.001);
  obj_2 = obj_0->Device;
  b_status = 79U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  b_status = 78U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 79U;
  b_data[1] = 1U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 78U;
  b_data[1] = 75U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  STQMEKF_pause(0.001);
  obj_1 = obj_0;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 77U;
  b_data[1] = 64U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  STQMEKF_pause(0.001);
  obj_2 = obj_1->Device;
  b_status = 4U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  obj_1 = obj_0;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  b_status = 79U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  b_status = 78U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 79U;
  b_data[1] = 4U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 78U;
  b_data[1] = 81U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  STQMEKF_pause(0.001);
  obj_2 = obj_1->Device;
  b_status = 79U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  obj_2 = obj_1->Device;
  b_status = 78U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  obj_2 = obj_1->Device;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 79U;
  b_data[1] = 14U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  obj_2 = obj_1->Device;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 78U;
  b_data[1] = 82U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  STQMEKF_pause(0.001);
  obj_2 = obj_0->Device;
  b_status = 79U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  b_status = 78U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 79U;
  b_data[1] = 2U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 78U;
  b_data[1] = 76U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  obj_2 = obj_0->Device;
  b_status = 77U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 77U;
  b_data[1] = 66U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
}

static void STQMEKF_SystemCore_setup(nvidiacoder_sensors_BMI160Blo_T *obj)
{
  b_bmi160_STQMEKF_T *b_obj;
  b_bmi160_STQMEKF_T *obj_2;
  e_codertarget_jetson_sensors__T *varargin_1;
  e_matlabshared_devicedrivers__T *obj_4;
  f_matlabshared_sensors_coder__T *obj_3;
  nvidiacoder_sensors_BMI160Blo_T *obj_0;
  nvidiacoder_sensors_BMI160Blo_T *obj_1;
  real_T bus;
  uint8_T b_data[2];
  uint8_T b_status;
  uint8_T i2cModule;
  uint8_T val;
  obj->isSetupComplete = false;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj->isInitialized = 1;
  obj_0 = obj;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj->_pobj3.currentTime = -1.0;
  obj->HwUtilityObject = &obj->_pobj3;
  obj_1 = obj;
  varargin_1 = obj->HwUtilityObject;
  b_obj = &obj->_pobj2;
  obj->_pobj2.isInitialized = 0;
  obj->_pobj2.Parent = varargin_1;
  obj->_pobj2._pobj0.isInitialized = 0;
  obj->_pobj2._pobj0.Bus = 1.0;
  obj->_pobj2._pobj0.BusI2CDriver = obj->_pobj2._pobj0.Bus;
  bus = obj->_pobj2._pobj0.BusI2CDriver;
  bus = rt_roundd_snf(bus);
  if (bus < 256.0) {
    if (bus >= 0.0) {
      obj->_pobj2._pobj0.Device.Bus = static_cast<uint8_T>(bus);
    } else {
      obj->_pobj2._pobj0.Device.Bus = 0U;
    }
  } else {
    obj->_pobj2._pobj0.Device.Bus = MAX_uint8_T;
  }

  obj->_pobj2._pobj0.Device.DeviceAddress = 105U;
  obj->_pobj2._pobj0.Device._pobj0.MW_I2C_HANDLE = NULL;
  obj->_pobj2._pobj0.Device.InterfaceObj = &obj->_pobj2._pobj0.Device._pobj0;
  obj_4 = obj->_pobj2._pobj0.Device.InterfaceObj;
  i2cModule = obj->_pobj2._pobj0.Device.Bus;
  obj_4->MW_I2C_HANDLE = MW_I2C_Open(i2cModule, MW_I2C_MASTER);
  obj->_pobj2.Device = &obj->_pobj2._pobj0;
  obj_3 = obj->_pobj2.Device;
  b_status = 0U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U, false,
                      true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_2 = &obj->_pobj2;
  obj_3 = obj->_pobj2.Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 182U;
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  STQMEKF_pause(0.06);
  obj_3 = obj_2->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 3U;
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  STQMEKF_pause(0.06);
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 17U;
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  STQMEKF_pause(0.005);
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 21U;
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  STQMEKF_pause(0.085);
  S_bmi160_set_EnableSecondaryMag(b_obj);

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  b_status = 65U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 65U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 240U) | 3);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 64U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 64U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 112U) | 8);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 64U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 64U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 15U) | 32);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 67U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 67U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 248U) | 4);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 66U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 66U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 240U) | 8);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 66U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 66U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 207U) | 32);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 68U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 68U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 240U) | 6);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 76U;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 76U;
  b_data[1] = static_cast<uint8_T>(val & 63);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  STQMEKF_pause(0.001);
  b_obj->matlabCodegenIsDeleted = false;
  obj_1->SensorObject = b_obj;

  // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  obj_0->OutputModules.f1 = &obj_0->_pobj1;
  obj_0->OutputModules.f2 = &obj_0->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

// Model step function
void STQMEKF_step(void)
{
  // local block i/o variables
  real_T rtb_DataStoreRead_f[7];
  real_T rtb_ThrustPer_Final[8];
  real_T rtb_ThrustPer_Final_b[8];
  real_T rtb_ThrustPer_Final_d[8];

  {
    e_matlabshared_devicedrivers__T *obj_0;
    f_matlabshared_sensors_coder__T *obj;
    real_T F[144];
    real_T F_0[144];
    real_T F_1[144];
    real_T F_2[144];
    real_T P_k[144];
    real_T P_tmp[144];
    real_T b_u1[135];
    real_T a__2[72];
    real_T a__2_tmp[72];
    real_T rtb_H_a[72];
    real_T rtb_H_nz[72];
    real_T tmp_6[64];
    real_T y[64];
    real_T V[36];
    real_T x[36];
    real_T rtb_H[24];
    real_T rtb_H_tmp[24];
    real_T tmp[24];
    real_T tmp_0[18];
    real_T rtb_MatrixConcatenate_0[16];
    real_T rtb_z_true_1[16];
    real_T BLACK_KF_States[13];
    real_T delta_x[12];
    real_T tmp_4[9];
    real_T tmp_5[9];
    real_T PWMs[8];
    real_T PWMs_tmp_tmp[8];
    real_T b_maxval[8];
    real_T prev_duty_cycles[8];
    real_T rtb_Delay1[7];
    real_T rtb_z_true[7];
    real_T z_bar[7];
    real_T rtb_y[6];
    real_T tmp_1[6];
    real_T tmp_2[6];
    real_T tmp_3[6];
    real_T rtb_Delay1_0[4];
    real_T rtb_MatrixConcatenate[4];
    real_T BLACK_Controls[3];
    real_T BLACK_Path[3];
    real_T RED_Controls[3];
    real_T RED_Path[3];
    real_T axis[3];
    real_T b_vector[3];
    real_T rtb_Merge6[3];
    real_T ARM_Path_idx_0;
    real_T ARM_Path_idx_1;
    real_T ARM_Path_idx_2;
    real_T BLUE_Path_Planner_Selection;
    real_T BLUE_Path_idx_0;
    real_T BLUE_Path_idx_1;
    real_T BLUE_Path_idx_2;
    real_T dxds;
    real_T dyds;
    real_T env;
    real_T rtb_TSamp;
    real_T rtb_TSamp_af;
    real_T rtb_TSamp_e;
    real_T rtb_TSamp_jb;
    real_T rtb_TSamp_k;
    real_T rtb_TSamp_n5;
    real_T rtb_TSamp_o;
    real_T rtb_z_true_0;
    real_T sampleTime;
    real_T sampleTime_0;
    real_T sampleTime_1;
    real_T ty;
    real_T u_loop;
    real_T y_off;
    int32_T ipiv[6];
    int32_T V_tmp;
    int32_T b_k;
    int32_T i;
    int32_T jAcol;
    int32_T jBcol;
    int32_T jj;
    int32_T kBcol;
    int32_T nz;
    int32_T rtb_StartClock;
    int32_T samplesRead;
    int32_T samplesRead_0;
    int32_T samplesRead_1;
    char_T *sErr;
    int8_T q_tmp[9];
    int8_T ipiv_0[6];
    int8_T p[6];
    int8_T rtAction;
    int8_T rtPrevAction;
    uint8_T b_output[6];
    uint8_T b_output_0[6];
    uint8_T b_status;
    uint8_T slaveAddress;
    boolean_T x_0[8];
    boolean_T RelationalOperator_i[3];
    boolean_T isodd;
    static const real_T Q[144] = { 0.0007, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0007, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0007, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 1.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 1.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 1.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0001,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0001, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-5, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-5, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-5 };

    static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    static const real_T R[36] = { 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9 };

    static const int8_T d[144] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 1 };

    static const int8_T b_0[8] = { -1, -1, 0, 0, 1, 1, 0, 0 };

    static const int8_T c[8] = { 0, 0, 1, 1, 0, 0, -1, -1 };

    real_T BLUE_Path_Planner_Selection_tmp;
    int32_T exitg2;
    boolean_T exitg1;

    // Outputs for IfAction SubSystem: '<S2>/Custom PPL (ARM)' incorporates:
    //   ActionPort: '<S80>/Action Port'

    // If: '<S2>/If3' incorporates:
    //   DataStoreRead: '<S90>/Data Store Read'
    //   DataStoreWrite: '<S2>/Data Store Write9'

    ARM_Path_idx_0 = STQMEKF_DW.ARM_Desired_States[0];
    ARM_Path_idx_1 = STQMEKF_DW.ARM_Desired_States[1];
    ARM_Path_idx_2 = STQMEKF_DW.ARM_Desired_States[2];

    // End of Outputs for SubSystem: '<S2>/Custom PPL (ARM)'

    // If: '<S2>/If1' incorporates:
    //   DataStoreRead: '<S2>/Data Store Read1'

    if (STQMEKF_DW.BLACK_Path_Planner_Selection == 1.0) {
      // Outputs for IfAction SubSystem: '<S2>/Default APF PPL (BLACK)' incorporates:
      //   ActionPort: '<S84>/Action Port'

      // Concatenate: '<S96>/Matrix Concatenate' incorporates:
      //   DataStoreRead: '<S97>/Data Store Read1'
      //   DataStoreRead: '<S98>/RED Measured States '

      rtb_MatrixConcatenate[0] = STQMEKF_DW.BLUE_Measured_States[0];
      rtb_MatrixConcatenate[1] = STQMEKF_DW.RED_Measured_States[0];
      rtb_MatrixConcatenate[2] = STQMEKF_DW.BLUE_Measured_States[1];
      rtb_MatrixConcatenate[3] = STQMEKF_DW.RED_Measured_States[1];

      // DataStoreWrite: '<S2>/Data Store Write3' incorporates:
      //   Constant: '<S84>/Angular Gain'
      //   Constant: '<S84>/Attractive Gain'
      //   Constant: '<S84>/Influence Range'
      //   Constant: '<S84>/Repulsive Gain'
      //   DataStoreRead: '<S84>/RED_Px'
      //   DataStoreRead: '<S94>/RED_Px'
      //   MATLAB Function: '<S84>/MATLAB Function'

      BLACK_Path[0] = STQMEKF_DW.BLACK_Measured_States[0];
      BLACK_Path[1] = STQMEKF_DW.BLACK_Measured_States[1];
      BLACK_Path[2] = STQMEKF_DW.BLACK_Measured_States[2];
      STQMEKF_MATLABFunction(STQMEKF_DW.BLACK_Desired_States,
        rtb_MatrixConcatenate, STQMEKF_P.AttractiveGain_Value_i,
        STQMEKF_P.RepulsiveGain_Value_k, STQMEKF_P.InfluenceRange_Value_d,
        STQMEKF_P.AngularGain_Value_l, BLACK_Path);

      // End of Outputs for SubSystem: '<S2>/Default APF PPL (BLACK)'
    } else {
      // Outputs for IfAction SubSystem: '<S2>/Disable PPL (BLACK)' incorporates:
      //   ActionPort: '<S87>/Action Port'

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLACK)' incorporates:
      //   ActionPort: '<S81>/Action Port'

      // DataStoreWrite: '<S2>/Data Store Write3' incorporates:
      //   DataStoreRead: '<S105>/BLACK_Px'
      //   DataStoreRead: '<S91>/BLACK_Px'
      //   Merge: '<S3>/Merge6'

      BLACK_Path[0] = STQMEKF_DW.BLACK_Desired_States[0];
      BLACK_Path[1] = STQMEKF_DW.BLACK_Desired_States[1];
      BLACK_Path[2] = STQMEKF_DW.BLACK_Desired_States[2];

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLACK)'
      // End of Outputs for SubSystem: '<S2>/Disable PPL (BLACK)'
    }

    // End of If: '<S2>/If1'

    // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
    //   ActionPort: '<S82>/Action Port'

    // If: '<S2>/If2' incorporates:
    //   DataStoreRead: '<S92>/Data Store Read4'
    //   DataStoreWrite: '<S2>/Data Store Write6'

    BLUE_Path_idx_0 = STQMEKF_DW.BLUE_Desired_States[0];
    BLUE_Path_idx_1 = STQMEKF_DW.BLUE_Desired_States[1];
    BLUE_Path_idx_2 = STQMEKF_DW.BLUE_Desired_States[2];

    // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

    // If: '<S2>/If' incorporates:
    //   DataStoreRead: '<S2>/Data Store Read'

    if (STQMEKF_DW.RED_Path_Planner_Selection == 1.0) {
      // Outputs for IfAction SubSystem: '<S2>/Default APF PPL (RED)' incorporates:
      //   ActionPort: '<S85>/Action Port'

      // Concatenate: '<S101>/Matrix Concatenate' incorporates:
      //   DataStoreRead: '<S102>/BLACK Measured States '
      //   DataStoreRead: '<S103>/Data Store Read1'

      rtb_MatrixConcatenate[0] = STQMEKF_DW.BLUE_Measured_States[0];
      rtb_MatrixConcatenate[1] = STQMEKF_DW.BLACK_Measured_States[0];
      rtb_MatrixConcatenate[2] = STQMEKF_DW.BLUE_Measured_States[1];
      rtb_MatrixConcatenate[3] = STQMEKF_DW.BLACK_Measured_States[1];

      // DataStoreWrite: '<S2>/Data Store Write' incorporates:
      //   Constant: '<S85>/Angular Gain'
      //   Constant: '<S85>/Attractive Gain'
      //   Constant: '<S85>/Influence Range'
      //   Constant: '<S85>/Repulsive Gain'
      //   DataStoreRead: '<S85>/RED_Px'
      //   DataStoreRead: '<S99>/RED_Px'
      //   MATLAB Function: '<S85>/MATLAB Function'

      RED_Path[0] = STQMEKF_DW.RED_Measured_States[0];
      RED_Path[1] = STQMEKF_DW.RED_Measured_States[1];
      RED_Path[2] = STQMEKF_DW.RED_Measured_States[2];
      STQMEKF_MATLABFunction(STQMEKF_DW.RED_Desired_States,
        rtb_MatrixConcatenate, STQMEKF_P.AttractiveGain_Value,
        STQMEKF_P.RepulsiveGain_Value, STQMEKF_P.InfluenceRange_Value,
        STQMEKF_P.AngularGain_Value, RED_Path);

      // End of Outputs for SubSystem: '<S2>/Default APF PPL (RED)'
    } else {
      // Outputs for IfAction SubSystem: '<S2>/Disable PPL (RED)' incorporates:
      //   ActionPort: '<S89>/Action Port'

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (RED)' incorporates:
      //   ActionPort: '<S83>/Action Port'

      // DataStoreWrite: '<S2>/Data Store Write' incorporates:
      //   DataStoreRead: '<S107>/RED_Px'
      //   DataStoreRead: '<S93>/RED_Px'
      //   Merge: '<S3>/Merge6'

      RED_Path[0] = STQMEKF_DW.RED_Desired_States[0];
      RED_Path[1] = STQMEKF_DW.RED_Desired_States[1];
      RED_Path[2] = STQMEKF_DW.RED_Desired_States[2];

      // End of Outputs for SubSystem: '<S2>/Custom PPL (RED)'
      // End of Outputs for SubSystem: '<S2>/Disable PPL (RED)'
    }

    // End of If: '<S2>/If'

    // If: '<S3>/If1' incorporates:
    //   DataStoreRead: '<S3>/Data Store Read3'

    if (STQMEKF_DW.BLACK_Control_Law_Enabler == 1.0) {
      // Outputs for IfAction SubSystem: '<S3>/Default PD Control (BLACK)' incorporates:
      //   ActionPort: '<S114>/Action Port'

      // MATLAB Function: '<S144>/MATLAB Function' incorporates:
      //   DataStoreRead: '<S114>/Data Store Read1'
      //   DataStoreRead: '<S114>/Data Store Read13'

      STQMEKF_MATLABFunction_n(BLACK_Path[2], STQMEKF_DW.BLACK_Measured_States[2],
        &rtb_TSamp_k);

      // SampleTimeMath: '<S145>/TSamp' incorporates:
      //   DataStoreRead: '<S114>/Data Store Read1'
      //
      //  About '<S145>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_af = BLACK_Path[0] * STQMEKF_P.TSamp_WtEt_i;

      // Sum: '<S145>/Diff' incorporates:
      //   UnitDelay: '<S145>/UD'
      //
      //  Block description for '<S145>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S145>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_eh = rtb_TSamp_af - STQMEKF_DW.UD_DSTATE_eh;

      // SampleTimeMath: '<S146>/TSamp' incorporates:
      //   DataStoreRead: '<S114>/Data Store Read1'
      //
      //  About '<S146>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_o = BLACK_Path[1] * STQMEKF_P.TSamp_WtEt_hr;

      // Sum: '<S146>/Diff' incorporates:
      //   UnitDelay: '<S146>/UD'
      //
      //  Block description for '<S146>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S146>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_hv = rtb_TSamp_o - STQMEKF_DW.UD_DSTATE_hv;

      // SampleTimeMath: '<S147>/TSamp' incorporates:
      //   DataStoreRead: '<S114>/Data Store Read1'
      //
      //  About '<S147>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_n5 = BLACK_Path[2] * STQMEKF_P.TSamp_WtEt_ca;

      // Sum: '<S147>/Diff' incorporates:
      //   UnitDelay: '<S147>/UD'
      //
      //  Block description for '<S147>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S147>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_kv = rtb_TSamp_n5 - STQMEKF_DW.UD_DSTATE_kv;

      // Sum: '<S114>/Subtract7' incorporates:
      //   DataStoreRead: '<S114>/Data Store Read13'
      //   UnitDelay: '<S145>/UD'
      //
      //  Block description for '<S145>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_eh = STQMEKF_DW.BLACK_Measured_States[3] -
        STQMEKF_DW.UD_DSTATE_eh;

      // Sum: '<S114>/Subtract6' incorporates:
      //   DataStoreRead: '<S114>/Data Store Read13'
      //   UnitDelay: '<S146>/UD'
      //
      //  Block description for '<S146>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_hv = STQMEKF_DW.BLACK_Measured_States[4] -
        STQMEKF_DW.UD_DSTATE_hv;

      // Sum: '<S114>/Subtract8' incorporates:
      //   DataStoreRead: '<S114>/Data Store Read13'
      //   UnitDelay: '<S147>/UD'
      //
      //  Block description for '<S147>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_kv = STQMEKF_DW.BLACK_Measured_States[5] -
        STQMEKF_DW.UD_DSTATE_kv;

      // Gain: '<S114>/Gain6' incorporates:
      //   DataStoreRead: '<S114>/Data Store Read1'
      //   DataStoreRead: '<S114>/Data Store Read13'
      //   Gain: '<S114>/Gain'
      //   Gain: '<S114>/Gain3'
      //   Merge: '<S3>/Merge1'
      //   Sum: '<S114>/Subtract5'
      //   Sum: '<S114>/Sum'
      //   UnitDelay: '<S145>/UD'
      //
      //  Block description for '<S145>/UD':
      //
      //   Store in Global RAM

      STQMEKF_B.Merge1[0] = ((STQMEKF_DW.BLACK_Measured_States[0] - BLACK_Path[0])
        * STQMEKF_P.Kp_xb + STQMEKF_P.Kd_xb * STQMEKF_DW.UD_DSTATE_eh) *
        STQMEKF_P.Gain6_Gain_g;

      // Gain: '<S114>/Gain7' incorporates:
      //   DataStoreRead: '<S114>/Data Store Read1'
      //   DataStoreRead: '<S114>/Data Store Read13'
      //   Gain: '<S114>/Gain1'
      //   Gain: '<S114>/Gain4'
      //   Merge: '<S3>/Merge1'
      //   Sum: '<S114>/Subtract4'
      //   Sum: '<S114>/Sum1'
      //   UnitDelay: '<S146>/UD'
      //
      //  Block description for '<S146>/UD':
      //
      //   Store in Global RAM

      STQMEKF_B.Merge1[1] = ((STQMEKF_DW.BLACK_Measured_States[1] - BLACK_Path[1])
        * STQMEKF_P.Kp_yb + STQMEKF_P.Kd_yb * STQMEKF_DW.UD_DSTATE_hv) *
        STQMEKF_P.Gain7_Gain_b;

      // Gain: '<S114>/Gain8' incorporates:
      //   Gain: '<S114>/Gain2'
      //   Gain: '<S114>/Gain5'
      //   Merge: '<S3>/Merge1'
      //   Sum: '<S114>/Sum2'
      //   UnitDelay: '<S147>/UD'
      //
      //  Block description for '<S147>/UD':
      //
      //   Store in Global RAM

      STQMEKF_B.Merge1[2] = (STQMEKF_P.Kp_tb * rtb_TSamp_k + STQMEKF_P.Kd_tb *
        STQMEKF_DW.UD_DSTATE_kv) * STQMEKF_P.Gain8_Gain_m;

      // Update for UnitDelay: '<S145>/UD'
      //
      //  Block description for '<S145>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_eh = rtb_TSamp_af;

      // Update for UnitDelay: '<S146>/UD'
      //
      //  Block description for '<S146>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_hv = rtb_TSamp_o;

      // Update for UnitDelay: '<S147>/UD'
      //
      //  Block description for '<S147>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_kv = rtb_TSamp_n5;

      // End of Outputs for SubSystem: '<S3>/Default PD Control (BLACK)'
    } else if (STQMEKF_DW.BLACK_Control_Law_Enabler == 2.0) {
      // Outputs for IfAction SubSystem: '<S3>/Default LQR Control (BLACK)' incorporates:
      //   ActionPort: '<S110>/Action Port'

      // Product: '<S110>/Matrix Multiply' incorporates:
      //   DataStoreRead: '<S110>/Data Store Read1'
      //   DataStoreRead: '<S110>/Data Store Read13'
      //   MATLAB Function: '<S121>/MATLAB Function'

      STQMEKF_MATLABFunction_n(BLACK_Path[2], STQMEKF_DW.BLACK_Measured_States[2],
        &tmp_1[2]);

      // SampleTimeMath: '<S122>/TSamp' incorporates:
      //   DataStoreRead: '<S110>/Data Store Read1'
      //
      //  About '<S122>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_k = BLACK_Path[0] * STQMEKF_P.TSamp_WtEt_nd;

      // Sum: '<S122>/Diff' incorporates:
      //   UnitDelay: '<S122>/UD'
      //
      //  Block description for '<S122>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S122>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_j = rtb_TSamp_k - STQMEKF_DW.UD_DSTATE_j;

      // SampleTimeMath: '<S123>/TSamp' incorporates:
      //   DataStoreRead: '<S110>/Data Store Read1'
      //
      //  About '<S123>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_af = BLACK_Path[1] * STQMEKF_P.TSamp_WtEt_co;

      // Sum: '<S123>/Diff' incorporates:
      //   UnitDelay: '<S123>/UD'
      //
      //  Block description for '<S123>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S123>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_c = rtb_TSamp_af - STQMEKF_DW.UD_DSTATE_c;

      // SampleTimeMath: '<S124>/TSamp' incorporates:
      //   DataStoreRead: '<S110>/Data Store Read1'
      //
      //  About '<S124>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_o = BLACK_Path[2] * STQMEKF_P.TSamp_WtEt_no;

      // Sum: '<S124>/Diff' incorporates:
      //   UnitDelay: '<S124>/UD'
      //
      //  Block description for '<S124>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S124>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_d = rtb_TSamp_o - STQMEKF_DW.UD_DSTATE_d;

      // Sum: '<S110>/Subtract7' incorporates:
      //   DataStoreRead: '<S110>/Data Store Read13'
      //   UnitDelay: '<S122>/UD'
      //
      //  Block description for '<S122>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_j = STQMEKF_DW.BLACK_Measured_States[3] -
        STQMEKF_DW.UD_DSTATE_j;

      // Sum: '<S110>/Subtract6' incorporates:
      //   DataStoreRead: '<S110>/Data Store Read13'
      //   UnitDelay: '<S123>/UD'
      //
      //  Block description for '<S123>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_c = STQMEKF_DW.BLACK_Measured_States[4] -
        STQMEKF_DW.UD_DSTATE_c;

      // Sum: '<S110>/Subtract8' incorporates:
      //   DataStoreRead: '<S110>/Data Store Read13'
      //   UnitDelay: '<S124>/UD'
      //
      //  Block description for '<S124>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_d = STQMEKF_DW.BLACK_Measured_States[5] -
        STQMEKF_DW.UD_DSTATE_d;
      for (b_k = 0; b_k < 18; b_k++) {
        // Product: '<S110>/Matrix Multiply' incorporates:
        //   Constant: '<S110>/Constant2'

        tmp_0[b_k] = -STQMEKF_P.K_BLACK[b_k];
      }

      // Product: '<S110>/Matrix Multiply' incorporates:
      //   DataStoreRead: '<S110>/Data Store Read1'
      //   DataStoreRead: '<S110>/Data Store Read13'
      //   Reshape: '<S110>/Reshape1'
      //   Reshape: '<S110>/Reshape3'
      //   Sum: '<S110>/Subtract4'
      //   Sum: '<S110>/Subtract5'
      //   UnitDelay: '<S122>/UD'
      //   UnitDelay: '<S123>/UD'
      //   UnitDelay: '<S124>/UD'
      //
      //  Block description for '<S122>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S123>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S124>/UD':
      //
      //   Store in Global RAM

      tmp_1[0] = STQMEKF_DW.BLACK_Measured_States[0] - BLACK_Path[0];
      tmp_1[1] = STQMEKF_DW.BLACK_Measured_States[1] - BLACK_Path[1];
      tmp_1[3] = STQMEKF_DW.UD_DSTATE_j;
      tmp_1[4] = STQMEKF_DW.UD_DSTATE_c;
      tmp_1[5] = STQMEKF_DW.UD_DSTATE_d;
      for (b_k = 0; b_k < 3; b_k++) {
        // Product: '<S110>/Matrix Multiply' incorporates:
        //   Merge: '<S3>/Merge1'

        rtb_TSamp_n5 = 0.0;
        for (jj = 0; jj < 6; jj++) {
          // Merge: '<S3>/Merge1' incorporates:
          //   Product: '<S110>/Matrix Multiply'
          //   Reshape: '<S110>/Reshape4'

          rtb_TSamp_n5 += tmp_0[3 * jj + b_k] * tmp_1[jj];
        }

        // Merge: '<S3>/Merge1' incorporates:
        //   Product: '<S110>/Matrix Multiply'

        STQMEKF_B.Merge1[b_k] = rtb_TSamp_n5;
      }

      // Update for UnitDelay: '<S122>/UD'
      //
      //  Block description for '<S122>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_j = rtb_TSamp_k;

      // Update for UnitDelay: '<S123>/UD'
      //
      //  Block description for '<S123>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_c = rtb_TSamp_af;

      // Update for UnitDelay: '<S124>/UD'
      //
      //  Block description for '<S124>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_d = rtb_TSamp_o;

      // End of Outputs for SubSystem: '<S3>/Default LQR Control (BLACK)'
    } else {
      // Outputs for IfAction SubSystem: '<S3>/Disable Thrusters (BLACK)' incorporates:
      //   ActionPort: '<S118>/Action Port'

      STQMEKF_DisableThrustersBLACK(STQMEKF_B.Merge1,
        &STQMEKF_P.DisableThrustersBLACK);

      // End of Outputs for SubSystem: '<S3>/Disable Thrusters (BLACK)'
    }

    // End of If: '<S3>/If1'

    // DataStoreWrite: '<S3>/BLACK Controls'
    BLACK_Controls[0] = STQMEKF_B.Merge1[0];
    BLACK_Controls[1] = STQMEKF_B.Merge1[1];
    BLACK_Controls[2] = STQMEKF_B.Merge1[2];

    // If: '<S3>/If2' incorporates:
    //   DataStoreRead: '<S3>/Data Store Read2'

    if (STQMEKF_DW.BLUE_Control_Law_Enabler == 1.0) {
      // Outputs for IfAction SubSystem: '<S3>/Default PD Control (BLUE)' incorporates:
      //   ActionPort: '<S115>/Action Port'

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S82>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S115>/Data Store Read2'
      //   DataStoreRead: '<S92>/Data Store Read4'
      //   MATLAB Function: '<S149>/MATLAB Function'
      //   SampleTimeMath: '<S150>/TSamp'
      //
      //  About '<S150>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      STQMEKF_MATLABFunction_n(STQMEKF_DW.BLUE_Desired_States[2],
        STQMEKF_DW.BLUE_Measured_States[2], &rtb_TSamp_k);
      rtb_TSamp_af = STQMEKF_DW.BLUE_Desired_States[0] * STQMEKF_P.TSamp_WtEt_p;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Sum: '<S150>/Diff' incorporates:
      //   UnitDelay: '<S150>/UD'
      //
      //  Block description for '<S150>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S150>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_o = rtb_TSamp_af - STQMEKF_DW.UD_DSTATE_o;

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S82>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S92>/Data Store Read4'
      //   SampleTimeMath: '<S151>/TSamp'
      //
      //  About '<S151>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_o = STQMEKF_DW.BLUE_Desired_States[1] * STQMEKF_P.TSamp_WtEt_o;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Sum: '<S151>/Diff' incorporates:
      //   UnitDelay: '<S151>/UD'
      //
      //  Block description for '<S151>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S151>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_n = rtb_TSamp_o - STQMEKF_DW.UD_DSTATE_n;

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S82>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S92>/Data Store Read4'
      //   SampleTimeMath: '<S152>/TSamp'
      //
      //  About '<S152>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_n5 = STQMEKF_DW.BLUE_Desired_States[2] * STQMEKF_P.TSamp_WtEt_px;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Sum: '<S152>/Diff' incorporates:
      //   UnitDelay: '<S152>/UD'
      //
      //  Block description for '<S152>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S152>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_hu = rtb_TSamp_n5 - STQMEKF_DW.UD_DSTATE_hu;

      // Sum: '<S115>/Subtract7' incorporates:
      //   DataStoreRead: '<S115>/Data Store Read2'
      //   UnitDelay: '<S150>/UD'
      //
      //  Block description for '<S150>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_o = STQMEKF_DW.BLUE_Measured_States[3] -
        STQMEKF_DW.UD_DSTATE_o;

      // Sum: '<S115>/Subtract6' incorporates:
      //   DataStoreRead: '<S115>/Data Store Read2'
      //   UnitDelay: '<S151>/UD'
      //
      //  Block description for '<S151>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_n = STQMEKF_DW.BLUE_Measured_States[4] -
        STQMEKF_DW.UD_DSTATE_n;

      // Sum: '<S115>/Subtract8' incorporates:
      //   DataStoreRead: '<S115>/Data Store Read2'
      //   UnitDelay: '<S152>/UD'
      //
      //  Block description for '<S152>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_hu = STQMEKF_DW.BLUE_Measured_States[5] -
        STQMEKF_DW.UD_DSTATE_hu;

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S82>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S115>/Data Store Read2'
      //   DataStoreRead: '<S92>/Data Store Read4'
      //   Gain: '<S115>/Gain'
      //   Gain: '<S115>/Gain1'
      //   Gain: '<S115>/Gain3'
      //   Gain: '<S115>/Gain4'
      //   Gain: '<S115>/Gain6'
      //   Gain: '<S115>/Gain7'
      //   Merge: '<S3>/Merge2'
      //   Sum: '<S115>/Subtract4'
      //   Sum: '<S115>/Subtract5'
      //   Sum: '<S115>/Sum'
      //   Sum: '<S115>/Sum1'
      //   UnitDelay: '<S150>/UD'
      //   UnitDelay: '<S151>/UD'
      //
      //  Block description for '<S150>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S151>/UD':
      //
      //   Store in Global RAM

      STQMEKF_B.Merge2[0] = ((STQMEKF_DW.BLUE_Measured_States[0] -
        STQMEKF_DW.BLUE_Desired_States[0]) * STQMEKF_P.Kp_xblue +
        STQMEKF_P.Kd_xblue * STQMEKF_DW.UD_DSTATE_o) * STQMEKF_P.Gain6_Gain_a;
      STQMEKF_B.Merge2[1] = ((STQMEKF_DW.BLUE_Measured_States[1] -
        STQMEKF_DW.BLUE_Desired_States[1]) * STQMEKF_P.Kp_yblue +
        STQMEKF_P.Kd_yblue * STQMEKF_DW.UD_DSTATE_n) * STQMEKF_P.Gain7_Gain_e;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Gain: '<S115>/Gain8' incorporates:
      //   Gain: '<S115>/Gain2'
      //   Gain: '<S115>/Gain5'
      //   Merge: '<S3>/Merge2'
      //   Sum: '<S115>/Sum2'
      //   UnitDelay: '<S152>/UD'
      //
      //  Block description for '<S152>/UD':
      //
      //   Store in Global RAM

      STQMEKF_B.Merge2[2] = (STQMEKF_P.Kp_tblue * rtb_TSamp_k +
        STQMEKF_P.Kd_tblue * STQMEKF_DW.UD_DSTATE_hu) * STQMEKF_P.Gain8_Gain_g;

      // Update for UnitDelay: '<S150>/UD'
      //
      //  Block description for '<S150>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_o = rtb_TSamp_af;

      // Update for UnitDelay: '<S151>/UD'
      //
      //  Block description for '<S151>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_n = rtb_TSamp_o;

      // Update for UnitDelay: '<S152>/UD'
      //
      //  Block description for '<S152>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_hu = rtb_TSamp_n5;

      // End of Outputs for SubSystem: '<S3>/Default PD Control (BLUE)'
    } else if (STQMEKF_DW.BLUE_Control_Law_Enabler == 2.0) {
      // Outputs for IfAction SubSystem: '<S3>/Default LQR Control (BLUE)' incorporates:
      //   ActionPort: '<S111>/Action Port'

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S82>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S111>/Data Store Read2'
      //   DataStoreRead: '<S92>/Data Store Read4'
      //   MATLAB Function: '<S126>/MATLAB Function'
      //   Product: '<S111>/Matrix Multiply'
      //   SampleTimeMath: '<S127>/TSamp'
      //
      //  About '<S127>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      STQMEKF_MATLABFunction_n(STQMEKF_DW.BLUE_Desired_States[2],
        STQMEKF_DW.BLUE_Measured_States[2], &tmp_2[2]);
      rtb_TSamp_k = STQMEKF_DW.BLUE_Desired_States[0] * STQMEKF_P.TSamp_WtEt_ft;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Sum: '<S127>/Diff' incorporates:
      //   UnitDelay: '<S127>/UD'
      //
      //  Block description for '<S127>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S127>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_l = rtb_TSamp_k - STQMEKF_DW.UD_DSTATE_l;

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S82>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S92>/Data Store Read4'
      //   SampleTimeMath: '<S128>/TSamp'
      //
      //  About '<S128>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_af = STQMEKF_DW.BLUE_Desired_States[1] * STQMEKF_P.TSamp_WtEt_eh;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Sum: '<S128>/Diff' incorporates:
      //   UnitDelay: '<S128>/UD'
      //
      //  Block description for '<S128>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S128>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_k = rtb_TSamp_af - STQMEKF_DW.UD_DSTATE_k;

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S82>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S92>/Data Store Read4'
      //   SampleTimeMath: '<S129>/TSamp'
      //
      //  About '<S129>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_o = STQMEKF_DW.BLUE_Desired_States[2] * STQMEKF_P.TSamp_WtEt_ii;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Sum: '<S129>/Diff' incorporates:
      //   UnitDelay: '<S129>/UD'
      //
      //  Block description for '<S129>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S129>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_h = rtb_TSamp_o - STQMEKF_DW.UD_DSTATE_h;

      // Sum: '<S111>/Subtract7' incorporates:
      //   DataStoreRead: '<S111>/Data Store Read2'
      //   UnitDelay: '<S127>/UD'
      //
      //  Block description for '<S127>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_l = STQMEKF_DW.BLUE_Measured_States[3] -
        STQMEKF_DW.UD_DSTATE_l;

      // Sum: '<S111>/Subtract6' incorporates:
      //   DataStoreRead: '<S111>/Data Store Read2'
      //   UnitDelay: '<S128>/UD'
      //
      //  Block description for '<S128>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_k = STQMEKF_DW.BLUE_Measured_States[4] -
        STQMEKF_DW.UD_DSTATE_k;

      // Sum: '<S111>/Subtract8' incorporates:
      //   DataStoreRead: '<S111>/Data Store Read2'
      //   UnitDelay: '<S129>/UD'
      //
      //  Block description for '<S129>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_h = STQMEKF_DW.BLUE_Measured_States[5] -
        STQMEKF_DW.UD_DSTATE_h;
      for (b_k = 0; b_k < 18; b_k++) {
        // Product: '<S111>/Matrix Multiply' incorporates:
        //   Constant: '<S111>/Constant2'

        tmp_0[b_k] = -STQMEKF_P.K_BLUE[b_k];
      }

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S82>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S111>/Data Store Read2'
      //   DataStoreRead: '<S92>/Data Store Read4'
      //   Product: '<S111>/Matrix Multiply'
      //   Reshape: '<S111>/Reshape1'
      //   Sum: '<S111>/Subtract4'
      //   Sum: '<S111>/Subtract5'

      tmp_2[0] = STQMEKF_DW.BLUE_Measured_States[0] -
        STQMEKF_DW.BLUE_Desired_States[0];
      tmp_2[1] = STQMEKF_DW.BLUE_Measured_States[1] -
        STQMEKF_DW.BLUE_Desired_States[1];

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Product: '<S111>/Matrix Multiply' incorporates:
      //   Reshape: '<S111>/Reshape2'
      //   UnitDelay: '<S127>/UD'
      //   UnitDelay: '<S128>/UD'
      //   UnitDelay: '<S129>/UD'
      //
      //  Block description for '<S127>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S128>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S129>/UD':
      //
      //   Store in Global RAM

      tmp_2[3] = STQMEKF_DW.UD_DSTATE_l;
      tmp_2[4] = STQMEKF_DW.UD_DSTATE_k;
      tmp_2[5] = STQMEKF_DW.UD_DSTATE_h;
      for (b_k = 0; b_k < 3; b_k++) {
        // Product: '<S111>/Matrix Multiply' incorporates:
        //   Merge: '<S3>/Merge2'

        rtb_TSamp_n5 = 0.0;
        for (jj = 0; jj < 6; jj++) {
          // Merge: '<S3>/Merge2' incorporates:
          //   Product: '<S111>/Matrix Multiply'
          //   Reshape: '<S111>/Reshape4'

          rtb_TSamp_n5 += tmp_0[3 * jj + b_k] * tmp_2[jj];
        }

        // Merge: '<S3>/Merge2' incorporates:
        //   Product: '<S111>/Matrix Multiply'

        STQMEKF_B.Merge2[b_k] = rtb_TSamp_n5;
      }

      // Update for UnitDelay: '<S127>/UD'
      //
      //  Block description for '<S127>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_l = rtb_TSamp_k;

      // Update for UnitDelay: '<S128>/UD'
      //
      //  Block description for '<S128>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_k = rtb_TSamp_af;

      // Update for UnitDelay: '<S129>/UD'
      //
      //  Block description for '<S129>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_h = rtb_TSamp_o;

      // End of Outputs for SubSystem: '<S3>/Default LQR Control (BLUE)'
    } else {
      // Outputs for IfAction SubSystem: '<S3>/Disable Thrusters (BLUE)' incorporates:
      //   ActionPort: '<S119>/Action Port'

      STQMEKF_DisableThrustersBLACK(STQMEKF_B.Merge2,
        &STQMEKF_P.DisableThrustersBLUE);

      // End of Outputs for SubSystem: '<S3>/Disable Thrusters (BLUE)'
    }

    // End of If: '<S3>/If2'

    // DataStoreWrite: '<S3>/BLUE Controls'
    rtb_TSamp_af = STQMEKF_B.Merge2[0];
    rtb_TSamp_o = STQMEKF_B.Merge2[1];
    rtb_TSamp_k = STQMEKF_B.Merge2[2];

    // If: '<S3>/If3' incorporates:
    //   DataStoreRead: '<S3>/Data Store Read5'

    if (STQMEKF_DW.ARM_Control_Law_Enabler == 1.0) {
      // Outputs for IfAction SubSystem: '<S3>/Default PD (ARM)' incorporates:
      //   ActionPort: '<S113>/Action Port'

      // DataStoreWrite: '<S113>/Data Store Write12' incorporates:
      //   Constant: '<S113>/Constant7'

      STQMEKF_DW.ARM_Control_Mode = STQMEKF_P.Constant7_Value_a;

      // If: '<S113>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
      //   DataStoreRead: '<S113>/Data Store Read4'

      if (STQMEKF_DW.isSim == 1.0) {
        // Outputs for IfAction SubSystem: '<S113>/Simulated Position Controller' incorporates:
        //   ActionPort: '<S137>/Action Port'

        // Outputs for IfAction SubSystem: '<S2>/Custom PPL (ARM)' incorporates:
        //   ActionPort: '<S80>/Action Port'

        // If: '<S2>/If3' incorporates:
        //   DataStoreRead: '<S137>/Data Store Read2'
        //   DataStoreRead: '<S90>/Data Store Read'
        //   Sum: '<S137>/Subtract3'

        rtb_TSamp_n5 = STQMEKF_DW.ARM_Desired_States[1] -
          STQMEKF_DW.ARM_Measured_States[1];

        // End of Outputs for SubSystem: '<S2>/Custom PPL (ARM)'

        // SampleTimeMath: '<S141>/TSamp'
        //
        //  About '<S141>/TSamp':
        //   y = u * K where K = 1 / ( w * Ts )
        //
        rtb_TSamp = rtb_TSamp_n5 * STQMEKF_P.TSamp_WtEt_pu;

        // Sum: '<S138>/Sum3' incorporates:
        //   Gain: '<S138>/kd_elarm'
        //   Gain: '<S138>/kp_elarm'
        //   Sum: '<S141>/Diff'
        //   UnitDelay: '<S141>/UD'
        //
        //  Block description for '<S141>/Diff':
        //
        //   Add in CPU
        //
        //  Block description for '<S141>/UD':
        //
        //   Store in Global RAM

        STQMEKF_DW.UD_DSTATE = (rtb_TSamp - STQMEKF_DW.UD_DSTATE) *
          STQMEKF_P.Kd_elarm + STQMEKF_P.Kp_elarm * rtb_TSamp_n5;

        // Outputs for IfAction SubSystem: '<S2>/Custom PPL (ARM)' incorporates:
        //   ActionPort: '<S80>/Action Port'

        // If: '<S2>/If3' incorporates:
        //   DataStoreRead: '<S137>/Data Store Read2'
        //   DataStoreRead: '<S90>/Data Store Read'
        //   Sum: '<S137>/Subtract2'

        rtb_TSamp_n5 = STQMEKF_DW.ARM_Desired_States[0] -
          STQMEKF_DW.ARM_Measured_States[0];

        // End of Outputs for SubSystem: '<S2>/Custom PPL (ARM)'

        // SampleTimeMath: '<S142>/TSamp'
        //
        //  About '<S142>/TSamp':
        //   y = u * K where K = 1 / ( w * Ts )
        //
        rtb_TSamp_e = rtb_TSamp_n5 * STQMEKF_P.TSamp_WtEt_f0;

        // Sum: '<S139>/Sum3' incorporates:
        //   Gain: '<S139>/kd_sharm'
        //   Gain: '<S139>/kp_sharm'
        //   Sum: '<S142>/Diff'
        //   UnitDelay: '<S142>/UD'
        //
        //  Block description for '<S142>/Diff':
        //
        //   Add in CPU
        //
        //  Block description for '<S142>/UD':
        //
        //   Store in Global RAM

        STQMEKF_DW.UD_DSTATE_e = (rtb_TSamp_e - STQMEKF_DW.UD_DSTATE_e) *
          STQMEKF_P.Kd_sharm + STQMEKF_P.Kp_sharm * rtb_TSamp_n5;

        // Outputs for IfAction SubSystem: '<S2>/Custom PPL (ARM)' incorporates:
        //   ActionPort: '<S80>/Action Port'

        // If: '<S2>/If3' incorporates:
        //   DataStoreRead: '<S137>/Data Store Read2'
        //   DataStoreRead: '<S90>/Data Store Read'
        //   Sum: '<S137>/Subtract4'

        rtb_TSamp_n5 = STQMEKF_DW.ARM_Desired_States[2] -
          STQMEKF_DW.ARM_Measured_States[2];

        // End of Outputs for SubSystem: '<S2>/Custom PPL (ARM)'

        // SampleTimeMath: '<S143>/TSamp'
        //
        //  About '<S143>/TSamp':
        //   y = u * K where K = 1 / ( w * Ts )
        //
        rtb_TSamp_jb = rtb_TSamp_n5 * STQMEKF_P.TSamp_WtEt_nz;

        // Sum: '<S140>/Sum3' incorporates:
        //   Gain: '<S140>/kd_wrarm'
        //   Gain: '<S140>/kp_wrarm'
        //   Sum: '<S143>/Diff'
        //   UnitDelay: '<S143>/UD'
        //
        //  Block description for '<S143>/Diff':
        //
        //   Add in CPU
        //
        //  Block description for '<S143>/UD':
        //
        //   Store in Global RAM

        STQMEKF_DW.UD_DSTATE_a = (rtb_TSamp_jb - STQMEKF_DW.UD_DSTATE_a) *
          STQMEKF_P.Kd_wrarm + STQMEKF_P.Kp_wrarm * rtb_TSamp_n5;

        // Saturate: '<S137>/Saturation' incorporates:
        //   UnitDelay: '<S142>/UD'
        //
        //  Block description for '<S142>/UD':
        //
        //   Store in Global RAM

        if (STQMEKF_DW.UD_DSTATE_e > STQMEKF_P.Tz_lim_sharm) {
          // Merge: '<S3>/Merge6' incorporates:
          //   Merge: '<S113>/Merge3'

          rtb_Merge6[0] = STQMEKF_P.Tz_lim_sharm;
        } else if (STQMEKF_DW.UD_DSTATE_e < -STQMEKF_P.Tz_lim_sharm) {
          // Merge: '<S3>/Merge6' incorporates:
          //   Merge: '<S113>/Merge3'

          rtb_Merge6[0] = -STQMEKF_P.Tz_lim_sharm;
        } else {
          // Merge: '<S3>/Merge6' incorporates:
          //   Merge: '<S113>/Merge3'

          rtb_Merge6[0] = STQMEKF_DW.UD_DSTATE_e;
        }

        // End of Saturate: '<S137>/Saturation'

        // Saturate: '<S137>/Saturation1' incorporates:
        //   UnitDelay: '<S141>/UD'
        //
        //  Block description for '<S141>/UD':
        //
        //   Store in Global RAM

        if (STQMEKF_DW.UD_DSTATE > STQMEKF_P.Tz_lim_elarm) {
          // Merge: '<S3>/Merge6' incorporates:
          //   Merge: '<S113>/Merge4'

          rtb_Merge6[1] = STQMEKF_P.Tz_lim_elarm;
        } else if (STQMEKF_DW.UD_DSTATE < -STQMEKF_P.Tz_lim_elarm) {
          // Merge: '<S3>/Merge6' incorporates:
          //   Merge: '<S113>/Merge4'

          rtb_Merge6[1] = -STQMEKF_P.Tz_lim_elarm;
        } else {
          // Merge: '<S3>/Merge6' incorporates:
          //   Merge: '<S113>/Merge4'

          rtb_Merge6[1] = STQMEKF_DW.UD_DSTATE;
        }

        // End of Saturate: '<S137>/Saturation1'

        // Saturate: '<S137>/Saturation3' incorporates:
        //   UnitDelay: '<S143>/UD'
        //
        //  Block description for '<S143>/UD':
        //
        //   Store in Global RAM

        if (STQMEKF_DW.UD_DSTATE_a > STQMEKF_P.Tz_lim_wrarm) {
          // Merge: '<S3>/Merge6' incorporates:
          //   Merge: '<S113>/Merge5'

          rtb_Merge6[2] = STQMEKF_P.Tz_lim_wrarm;
        } else if (STQMEKF_DW.UD_DSTATE_a < -STQMEKF_P.Tz_lim_wrarm) {
          // Merge: '<S3>/Merge6' incorporates:
          //   Merge: '<S113>/Merge5'

          rtb_Merge6[2] = -STQMEKF_P.Tz_lim_wrarm;
        } else {
          // Merge: '<S3>/Merge6' incorporates:
          //   Merge: '<S113>/Merge5'

          rtb_Merge6[2] = STQMEKF_DW.UD_DSTATE_a;
        }

        // End of Saturate: '<S137>/Saturation3'

        // Update for UnitDelay: '<S141>/UD'
        //
        //  Block description for '<S141>/UD':
        //
        //   Store in Global RAM

        STQMEKF_DW.UD_DSTATE = rtb_TSamp;

        // Update for UnitDelay: '<S142>/UD'
        //
        //  Block description for '<S142>/UD':
        //
        //   Store in Global RAM

        STQMEKF_DW.UD_DSTATE_e = rtb_TSamp_e;

        // Update for UnitDelay: '<S143>/UD'
        //
        //  Block description for '<S143>/UD':
        //
        //   Store in Global RAM

        STQMEKF_DW.UD_DSTATE_a = rtb_TSamp_jb;

        // End of Outputs for SubSystem: '<S113>/Simulated Position Controller'
      } else {
        // Outputs for IfAction SubSystem: '<S113>/Passthrough for Experiment' incorporates:
        //   ActionPort: '<S136>/Action Port'

        // Outputs for IfAction SubSystem: '<S2>/Custom PPL (ARM)' incorporates:
        //   ActionPort: '<S80>/Action Port'

        // If: '<S2>/If3' incorporates:
        //   DataStoreRead: '<S90>/Data Store Read'
        //   Merge: '<S113>/Merge3'
        //   Merge: '<S113>/Merge4'
        //   Merge: '<S113>/Merge5'
        //   Merge: '<S3>/Merge6'
        //   SignalConversion generated from: '<S136>/q1_desired'
        //   SignalConversion generated from: '<S136>/q2_desired'
        //   SignalConversion generated from: '<S136>/q3_desired'

        rtb_Merge6[0] = STQMEKF_DW.ARM_Desired_States[0];
        rtb_Merge6[1] = STQMEKF_DW.ARM_Desired_States[1];
        rtb_Merge6[2] = STQMEKF_DW.ARM_Desired_States[2];

        // End of Outputs for SubSystem: '<S2>/Custom PPL (ARM)'
        // End of Outputs for SubSystem: '<S113>/Passthrough for Experiment'
      }

      // End of If: '<S113>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 
      // End of Outputs for SubSystem: '<S3>/Default PD (ARM)'
    } else if (STQMEKF_DW.ARM_Control_Law_Enabler == 2.0) {
      // Outputs for IfAction SubSystem: '<S3>/Custom Control (ARM)' incorporates:
      //   ActionPort: '<S108>/Action Port'

      STQMEKF_CustomControlRED(rtb_Merge6, &STQMEKF_P.CustomControlARM);

      // End of Outputs for SubSystem: '<S3>/Custom Control (ARM)'
    } else {
      // Outputs for IfAction SubSystem: '<S3>/Disable Control (ARM)' incorporates:
      //   ActionPort: '<S117>/Action Port'

      // DataStoreWrite: '<S117>/Data Store Write12' incorporates:
      //   Constant: '<S117>/Constant7'

      STQMEKF_DW.ARM_Control_Mode = STQMEKF_P.Constant7_Value_h;

      // Merge: '<S3>/Merge6' incorporates:
      //   Constant: '<S117>/Zero'
      //   SignalConversion generated from: '<S117>/Out1'

      rtb_Merge6[0] = STQMEKF_P.Zero_Value;
      rtb_Merge6[1] = STQMEKF_P.Zero_Value;
      rtb_Merge6[2] = STQMEKF_P.Zero_Value;

      // End of Outputs for SubSystem: '<S3>/Disable Control (ARM)'
    }

    // End of If: '<S3>/If3'

    // If: '<S3>/If' incorporates:
    //   DataStoreRead: '<S3>/Data Store Read1'

    if (STQMEKF_DW.RED_Control_Law_Enabler == 1.0) {
      // Outputs for IfAction SubSystem: '<S3>/Default PD Control (RED)' incorporates:
      //   ActionPort: '<S116>/Action Port'

      // MATLAB Function: '<S154>/MATLAB Function' incorporates:
      //   DataStoreRead: '<S116>/Data Store Read1'
      //   DataStoreRead: '<S116>/Data Store Read13'

      STQMEKF_MATLABFunction_n(RED_Path[2], STQMEKF_DW.RED_Measured_States[2],
        &rtb_TSamp_n5);

      // SampleTimeMath: '<S155>/TSamp' incorporates:
      //   DataStoreRead: '<S116>/Data Store Read1'
      //
      //  About '<S155>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp = RED_Path[0] * STQMEKF_P.TSamp_WtEt;

      // Sum: '<S155>/Diff' incorporates:
      //   UnitDelay: '<S155>/UD'
      //
      //  Block description for '<S155>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S155>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_eg = rtb_TSamp - STQMEKF_DW.UD_DSTATE_eg;

      // SampleTimeMath: '<S156>/TSamp' incorporates:
      //   DataStoreRead: '<S116>/Data Store Read1'
      //
      //  About '<S156>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_e = RED_Path[1] * STQMEKF_P.TSamp_WtEt_f;

      // Sum: '<S156>/Diff' incorporates:
      //   UnitDelay: '<S156>/UD'
      //
      //  Block description for '<S156>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S156>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_cd = rtb_TSamp_e - STQMEKF_DW.UD_DSTATE_cd;

      // SampleTimeMath: '<S157>/TSamp' incorporates:
      //   DataStoreRead: '<S116>/Data Store Read1'
      //
      //  About '<S157>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_jb = RED_Path[2] * STQMEKF_P.TSamp_WtEt_c;

      // Sum: '<S157>/Diff' incorporates:
      //   UnitDelay: '<S157>/UD'
      //
      //  Block description for '<S157>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S157>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_hd = rtb_TSamp_jb - STQMEKF_DW.UD_DSTATE_hd;

      // Sum: '<S116>/Subtract7' incorporates:
      //   DataStoreRead: '<S116>/Data Store Read13'
      //   UnitDelay: '<S155>/UD'
      //
      //  Block description for '<S155>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_eg = STQMEKF_DW.RED_Measured_States[3] -
        STQMEKF_DW.UD_DSTATE_eg;

      // Sum: '<S116>/Subtract6' incorporates:
      //   DataStoreRead: '<S116>/Data Store Read13'
      //   UnitDelay: '<S156>/UD'
      //
      //  Block description for '<S156>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_cd = STQMEKF_DW.RED_Measured_States[4] -
        STQMEKF_DW.UD_DSTATE_cd;

      // Sum: '<S116>/Subtract8' incorporates:
      //   DataStoreRead: '<S116>/Data Store Read13'
      //   UnitDelay: '<S157>/UD'
      //
      //  Block description for '<S157>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_hd = STQMEKF_DW.RED_Measured_States[5] -
        STQMEKF_DW.UD_DSTATE_hd;

      // Gain: '<S116>/Gain6' incorporates:
      //   DataStoreRead: '<S116>/Data Store Read1'
      //   DataStoreRead: '<S116>/Data Store Read13'
      //   Gain: '<S116>/Gain'
      //   Gain: '<S116>/Gain3'
      //   Merge: '<S3>/Merge'
      //   Sum: '<S116>/Subtract5'
      //   Sum: '<S116>/Sum'
      //   UnitDelay: '<S155>/UD'
      //
      //  Block description for '<S155>/UD':
      //
      //   Store in Global RAM

      STQMEKF_B.Merge[0] = ((STQMEKF_DW.RED_Measured_States[0] - RED_Path[0]) *
                            STQMEKF_P.Kp_xr + STQMEKF_P.Kd_xr *
                            STQMEKF_DW.UD_DSTATE_eg) * STQMEKF_P.Gain6_Gain;

      // Gain: '<S116>/Gain7' incorporates:
      //   DataStoreRead: '<S116>/Data Store Read1'
      //   DataStoreRead: '<S116>/Data Store Read13'
      //   Gain: '<S116>/Gain1'
      //   Gain: '<S116>/Gain4'
      //   Merge: '<S3>/Merge'
      //   Sum: '<S116>/Subtract4'
      //   Sum: '<S116>/Sum1'
      //   UnitDelay: '<S156>/UD'
      //
      //  Block description for '<S156>/UD':
      //
      //   Store in Global RAM

      STQMEKF_B.Merge[1] = ((STQMEKF_DW.RED_Measured_States[1] - RED_Path[1]) *
                            STQMEKF_P.Kp_yr + STQMEKF_P.Kd_yr *
                            STQMEKF_DW.UD_DSTATE_cd) * STQMEKF_P.Gain7_Gain;

      // Gain: '<S116>/Gain8' incorporates:
      //   Gain: '<S116>/Gain2'
      //   Gain: '<S116>/Gain5'
      //   Merge: '<S3>/Merge'
      //   Sum: '<S116>/Sum2'
      //   UnitDelay: '<S157>/UD'
      //
      //  Block description for '<S157>/UD':
      //
      //   Store in Global RAM

      STQMEKF_B.Merge[2] = (STQMEKF_P.Kp_tr * rtb_TSamp_n5 + STQMEKF_P.Kd_tr *
                            STQMEKF_DW.UD_DSTATE_hd) * STQMEKF_P.Gain8_Gain;

      // Update for UnitDelay: '<S155>/UD'
      //
      //  Block description for '<S155>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_eg = rtb_TSamp;

      // Update for UnitDelay: '<S156>/UD'
      //
      //  Block description for '<S156>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_cd = rtb_TSamp_e;

      // Update for UnitDelay: '<S157>/UD'
      //
      //  Block description for '<S157>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_hd = rtb_TSamp_jb;

      // End of Outputs for SubSystem: '<S3>/Default PD Control (RED)'
    } else if (STQMEKF_DW.RED_Control_Law_Enabler == 2.0) {
      // Outputs for IfAction SubSystem: '<S3>/Default LQR Control (RED)' incorporates:
      //   ActionPort: '<S112>/Action Port'

      // Product: '<S112>/Matrix Multiply' incorporates:
      //   DataStoreRead: '<S112>/Data Store Read1'
      //   DataStoreRead: '<S112>/Data Store Read13'
      //   MATLAB Function: '<S131>/MATLAB Function'

      STQMEKF_MATLABFunction_n(RED_Path[2], STQMEKF_DW.RED_Measured_States[2],
        &tmp_3[2]);

      // SampleTimeMath: '<S132>/TSamp' incorporates:
      //   DataStoreRead: '<S112>/Data Store Read1'
      //
      //  About '<S132>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_n5 = RED_Path[0] * STQMEKF_P.TSamp_WtEt_h;

      // Sum: '<S132>/Diff' incorporates:
      //   UnitDelay: '<S132>/UD'
      //
      //  Block description for '<S132>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S132>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_aq = rtb_TSamp_n5 - STQMEKF_DW.UD_DSTATE_aq;

      // SampleTimeMath: '<S133>/TSamp' incorporates:
      //   DataStoreRead: '<S112>/Data Store Read1'
      //
      //  About '<S133>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp = RED_Path[1] * STQMEKF_P.TSamp_WtEt_e;

      // Sum: '<S133>/Diff' incorporates:
      //   UnitDelay: '<S133>/UD'
      //
      //  Block description for '<S133>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S133>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_p = rtb_TSamp - STQMEKF_DW.UD_DSTATE_p;

      // SampleTimeMath: '<S134>/TSamp' incorporates:
      //   DataStoreRead: '<S112>/Data Store Read1'
      //
      //  About '<S134>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_e = RED_Path[2] * STQMEKF_P.TSamp_WtEt_n;

      // Sum: '<S134>/Diff' incorporates:
      //   UnitDelay: '<S134>/UD'
      //
      //  Block description for '<S134>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S134>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_pr = rtb_TSamp_e - STQMEKF_DW.UD_DSTATE_pr;

      // Sum: '<S112>/Subtract7' incorporates:
      //   DataStoreRead: '<S112>/Data Store Read13'
      //   UnitDelay: '<S132>/UD'
      //
      //  Block description for '<S132>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_aq = STQMEKF_DW.RED_Measured_States[3] -
        STQMEKF_DW.UD_DSTATE_aq;

      // Sum: '<S112>/Subtract6' incorporates:
      //   DataStoreRead: '<S112>/Data Store Read13'
      //   UnitDelay: '<S133>/UD'
      //
      //  Block description for '<S133>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_p = STQMEKF_DW.RED_Measured_States[4] -
        STQMEKF_DW.UD_DSTATE_p;

      // Sum: '<S112>/Subtract8' incorporates:
      //   DataStoreRead: '<S112>/Data Store Read13'
      //   UnitDelay: '<S134>/UD'
      //
      //  Block description for '<S134>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_pr = STQMEKF_DW.RED_Measured_States[5] -
        STQMEKF_DW.UD_DSTATE_pr;
      for (b_k = 0; b_k < 18; b_k++) {
        // Product: '<S112>/Matrix Multiply' incorporates:
        //   Constant: '<S112>/Constant2'

        tmp_0[b_k] = -STQMEKF_P.K_RED[b_k];
      }

      // Product: '<S112>/Matrix Multiply' incorporates:
      //   DataStoreRead: '<S112>/Data Store Read1'
      //   DataStoreRead: '<S112>/Data Store Read13'
      //   Reshape: '<S112>/Reshape2'
      //   Reshape: '<S112>/Reshape3'
      //   Sum: '<S112>/Subtract4'
      //   Sum: '<S112>/Subtract5'
      //   UnitDelay: '<S132>/UD'
      //   UnitDelay: '<S133>/UD'
      //   UnitDelay: '<S134>/UD'
      //
      //  Block description for '<S132>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S133>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S134>/UD':
      //
      //   Store in Global RAM

      tmp_3[0] = STQMEKF_DW.RED_Measured_States[0] - RED_Path[0];
      tmp_3[1] = STQMEKF_DW.RED_Measured_States[1] - RED_Path[1];
      tmp_3[3] = STQMEKF_DW.UD_DSTATE_aq;
      tmp_3[4] = STQMEKF_DW.UD_DSTATE_p;
      tmp_3[5] = STQMEKF_DW.UD_DSTATE_pr;
      for (b_k = 0; b_k < 3; b_k++) {
        // Product: '<S112>/Matrix Multiply' incorporates:
        //   Merge: '<S3>/Merge'

        rtb_TSamp_jb = 0.0;
        for (jj = 0; jj < 6; jj++) {
          // Merge: '<S3>/Merge' incorporates:
          //   Product: '<S112>/Matrix Multiply'
          //   Reshape: '<S112>/Reshape4'

          rtb_TSamp_jb += tmp_0[3 * jj + b_k] * tmp_3[jj];
        }

        // Merge: '<S3>/Merge' incorporates:
        //   Product: '<S112>/Matrix Multiply'

        STQMEKF_B.Merge[b_k] = rtb_TSamp_jb;
      }

      // Update for UnitDelay: '<S132>/UD'
      //
      //  Block description for '<S132>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_aq = rtb_TSamp_n5;

      // Update for UnitDelay: '<S133>/UD'
      //
      //  Block description for '<S133>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_p = rtb_TSamp;

      // Update for UnitDelay: '<S134>/UD'
      //
      //  Block description for '<S134>/UD':
      //
      //   Store in Global RAM

      STQMEKF_DW.UD_DSTATE_pr = rtb_TSamp_e;

      // End of Outputs for SubSystem: '<S3>/Default LQR Control (RED)'
    } else if (STQMEKF_DW.RED_Control_Law_Enabler == 3.0) {
      // Outputs for IfAction SubSystem: '<S3>/Custom Control (RED)' incorporates:
      //   ActionPort: '<S109>/Action Port'

      STQMEKF_CustomControlRED(STQMEKF_B.Merge, &STQMEKF_P.CustomControlRED);

      // End of Outputs for SubSystem: '<S3>/Custom Control (RED)'
    } else {
      // Outputs for IfAction SubSystem: '<S3>/Disable Thrusters (RED)' incorporates:
      //   ActionPort: '<S120>/Action Port'

      STQMEKF_CustomControlRED(STQMEKF_B.Merge, &STQMEKF_P.DisableThrustersRED);

      // End of Outputs for SubSystem: '<S3>/Disable Thrusters (RED)'
    }

    // End of If: '<S3>/If'

    // DataStoreWrite: '<S3>/RED Controls'
    RED_Controls[0] = STQMEKF_B.Merge[0];
    RED_Controls[1] = STQMEKF_B.Merge[1];
    RED_Controls[2] = STQMEKF_B.Merge[2];
    for (i = 0; i < 7; i++) {
      // DataStoreRead: '<S14>/Data Store Read'
      rtb_DataStoreRead_f[i] = STQMEKF_DW.BLACK_States_Vis_raw[i];
    }

    // Delay: '<S217>/Delay1'
    rtb_Delay1[0] = STQMEKF_DW.Delay1_DSTATE;
    for (i = 0; i < 6; i++) {
      rtb_Delay1[i + 1] = rtb_DataStoreRead_f[i];
    }

    // End of Delay: '<S217>/Delay1'

    // MATLAB Function: '<S217>/Pre-Process'
    isodd = false;
    for (jj = 0; jj < 7; jj++) {
      if (!isodd) {
        isodd = rtIsNaN(rtb_DataStoreRead_f[jj]);
      }
    }

    if (isodd) {
      for (i = 0; i < 7; i++) {
        rtb_Delay1[i] = (rtNaN);
      }
    } else {
      isodd = true;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k < 7)) {
        if (!(rtb_DataStoreRead_f[b_k] - rtb_Delay1[b_k] < 1.0E-10)) {
          isodd = false;
          exitg1 = true;
        } else {
          b_k++;
        }
      }

      for (b_k = 0; b_k < 7; b_k++) {
        if (isodd) {
          rtb_Delay1[b_k] = (rtNaN);
        } else {
          rtb_Delay1[b_k] = rtb_DataStoreRead_f[b_k];
        }
      }
    }

    // End of MATLAB Function: '<S217>/Pre-Process'

    // Delay: '<S217>/Delay'
    rtb_TSamp_n5 = STQMEKF_DW.Delay_DSTATE;

    // DataStoreRead: '<S14>/Data Store Read2' incorporates:
    //   Delay: '<S217>/Delay'

    STQMEKF_DW.Delay_DSTATE = STQMEKF_DW.Univ_Time;

    // Sum: '<S217>/Sum' incorporates:
    //   DataStoreWrite: '<S217>/Measured States for BLACK2'
    //   Delay: '<S217>/Delay'

    rtb_TSamp_n5 = STQMEKF_DW.Delay_DSTATE - rtb_TSamp_n5;

    // MATLAB Function: '<S217>/Build quat ' incorporates:
    //   DataStoreRead: '<S14>/Data Store Read1'

    rtb_TSamp = sin(STQMEKF_DW.RED_Measured_States[2] / 2.0);
    rtb_z_true[0] = cos(STQMEKF_DW.RED_Measured_States[2] / 2.0);
    rtb_z_true[1] = 0.0 * rtb_TSamp;
    rtb_z_true[2] = 0.0 * rtb_TSamp;
    rtb_z_true[3] = rtb_TSamp;
    rtb_z_true[4] = STQMEKF_DW.RED_Measured_States[0];
    rtb_z_true[5] = STQMEKF_DW.RED_Measured_States[1];
    rtb_z_true[6] = 0.0;

    // Delay: '<S218>/Delay2'
    memcpy(&STQMEKF_B.x[0], &STQMEKF_DW.Delay2_DSTATE[0], 13U * sizeof(real_T));

    // Delay: '<S218>/Delay1'
    memcpy(&STQMEKF_B.P[0], &STQMEKF_DW.Delay1_DSTATE_n[0], 144U * sizeof(real_T));
    for (i = 0; i < 36; i++) {
      // Delay: '<S218>/Delay3'
      rtb_TSamp_e = STQMEKF_DW.Delay3_DSTATE[i];
      STQMEKF_B.V[i] = rtb_TSamp_e;

      // MATLAB Function: '<S218>/MATLAB Function'
      V[i] = rtb_TSamp_e;
    }

    // MATLAB Function: '<S218>/MATLAB Function' incorporates:
    //   DataStoreWrite: '<S217>/Measured States for BLACK2'

    isodd = false;
    for (jj = 0; jj < 7; jj++) {
      if (!isodd) {
        isodd = rtIsNaN(rtb_Delay1[jj]);
      }
    }

    if (isodd) {
      memcpy(&BLACK_KF_States[0], &STQMEKF_B.x[0], 13U * sizeof(real_T));
      STQMEKF_prop(BLACK_KF_States, rtb_TSamp_n5, STQMEKF_B.x, F, a__2);
      for (b_k = 0; b_k < 12; b_k++) {
        for (jj = 0; jj < 12; jj++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_e += F[12 * i + jj] * STQMEKF_B.P[12 * b_k + i];
          }

          F_0[jj + 12 * b_k] = rtb_TSamp_e;
        }
      }

      for (b_k = 0; b_k < 12; b_k++) {
        for (jj = 0; jj < 12; jj++) {
          rtb_TSamp_jb = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_jb += F_0[12 * i + b_k] * F[12 * jj + i];
          }

          i = 12 * jj + b_k;
          STQMEKF_B.P[i] = Q[i] + rtb_TSamp_jb;
        }
      }

      for (i = 0; i < 6; i++) {
        rtb_y[i] = (rtNaN);
      }
    } else {
      STQMEKF_prop(STQMEKF_B.x, rtb_TSamp_n5, BLACK_KF_States, F, a__2);
      for (b_k = 0; b_k < 12; b_k++) {
        for (jj = 0; jj < 12; jj++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_e += F[12 * i + b_k] * STQMEKF_B.P[12 * jj + i];
          }

          F_0[b_k + 12 * jj] = rtb_TSamp_e;
        }

        for (jj = 0; jj < 12; jj++) {
          rtb_TSamp_jb = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_jb += F_0[12 * i + b_k] * F[12 * i + jj];
          }

          i = 12 * jj + b_k;
          P_k[i] = Q[i] + rtb_TSamp_jb;
        }
      }

      for (i = 0; i < 7; i++) {
        z_bar[i] = 0.0 * rtb_Delay1[i];
      }

      rtb_TSamp_e = sqrt(((rtb_z_true[0] * rtb_z_true[0] + rtb_z_true[1] *
                           rtb_z_true[1]) + rtb_z_true[2] * rtb_z_true[2]) +
                         rtb_TSamp * rtb_TSamp);
      axis[0] = rtb_z_true[1];
      axis[1] = rtb_z_true[2];
      axis[2] = rtb_TSamp;
      for (b_k = 0; b_k < 9; b_k++) {
        q_tmp[b_k] = b[b_k];
      }

      rtb_z_true_0 = rtb_z_true[0];
      tmp_4[0] = 0.0;
      tmp_4[3] = -rtb_TSamp;
      tmp_4[6] = rtb_z_true[2];
      tmp_4[1] = rtb_TSamp;
      tmp_4[4] = 0.0;
      tmp_4[7] = -rtb_z_true[1];
      tmp_4[2] = -rtb_z_true[2];
      tmp_4[5] = rtb_z_true[1];
      tmp_4[8] = 0.0;
      rtb_z_true_1[0] = rtb_z_true[0];
      for (b_k = 0; b_k < 3; b_k++) {
        BLUE_Path_Planner_Selection = axis[b_k];
        jj = (b_k + 1) << 2;
        rtb_z_true_1[jj] = -BLUE_Path_Planner_Selection;
        rtb_z_true_1[b_k + 1] = BLUE_Path_Planner_Selection;
        rtb_z_true_1[jj + 1] = static_cast<real_T>(q_tmp[3 * b_k]) *
          rtb_z_true_0 + tmp_4[3 * b_k];
        i = 3 * b_k + 1;
        rtb_z_true_1[jj + 2] = static_cast<real_T>(q_tmp[i]) * rtb_z_true_0 +
          tmp_4[i];
        i = 3 * b_k + 2;
        rtb_z_true_1[jj + 3] = static_cast<real_T>(q_tmp[i]) * rtb_z_true_0 +
          tmp_4[i];
        rtb_MatrixConcatenate[b_k + 1] = BLACK_KF_States[b_k + 7] -
          rtb_z_true[b_k + 4];
      }

      rtb_TSamp_jb = rtb_MatrixConcatenate[1];
      BLUE_Path_Planner_Selection = rtb_MatrixConcatenate[2];
      rtb_z_true_0 = rtb_MatrixConcatenate[3];
      for (b_k = 0; b_k < 4; b_k++) {
        rtb_MatrixConcatenate[b_k] = ((rtb_z_true_1[b_k + 4] * rtb_TSamp_jb +
          rtb_z_true_1[b_k] * 0.0) + rtb_z_true_1[b_k + 8] *
          BLUE_Path_Planner_Selection) + rtb_z_true_1[b_k + 12] * rtb_z_true_0;
      }

      axis[0] = rtb_MatrixConcatenate[1];
      axis[1] = rtb_MatrixConcatenate[2];
      axis[2] = rtb_MatrixConcatenate[3];
      rtb_TSamp_jb = rtb_MatrixConcatenate[0];
      tmp_4[0] = 0.0;
      tmp_4[3] = -rtb_MatrixConcatenate[3];
      tmp_4[6] = rtb_MatrixConcatenate[2];
      tmp_4[1] = rtb_MatrixConcatenate[3];
      tmp_4[4] = 0.0;
      tmp_4[7] = -rtb_MatrixConcatenate[1];
      tmp_4[2] = -rtb_MatrixConcatenate[2];
      tmp_4[5] = rtb_MatrixConcatenate[1];
      tmp_4[8] = 0.0;
      rtb_TSamp_e *= rtb_TSamp_e;
      rtb_MatrixConcatenate_0[0] = rtb_MatrixConcatenate[0];
      for (b_k = 0; b_k < 3; b_k++) {
        BLUE_Path_Planner_Selection = axis[b_k];
        jj = (b_k + 1) << 2;
        rtb_MatrixConcatenate_0[jj] = -BLUE_Path_Planner_Selection;
        rtb_MatrixConcatenate_0[b_k + 1] = BLUE_Path_Planner_Selection;
        rtb_MatrixConcatenate_0[jj + 1] = static_cast<real_T>(q_tmp[3 * b_k]) *
          rtb_TSamp_jb + tmp_4[3 * b_k];
        i = 3 * b_k + 1;
        rtb_MatrixConcatenate_0[jj + 2] = static_cast<real_T>(q_tmp[i]) *
          rtb_TSamp_jb + tmp_4[i];
        i = 3 * b_k + 2;
        rtb_MatrixConcatenate_0[jj + 3] = static_cast<real_T>(q_tmp[i]) *
          rtb_TSamp_jb + tmp_4[i];
      }

      rtb_TSamp_jb = rtb_z_true[0] / rtb_TSamp_e;
      BLUE_Path_Planner_Selection = -rtb_z_true[1] / rtb_TSamp_e;
      rtb_z_true_0 = -rtb_z_true[2] / rtb_TSamp_e;
      rtb_TSamp_e = -rtb_TSamp / rtb_TSamp_e;
      for (b_k = 0; b_k < 4; b_k++) {
        rtb_MatrixConcatenate[b_k] = ((rtb_MatrixConcatenate_0[b_k + 4] *
          BLUE_Path_Planner_Selection + rtb_MatrixConcatenate_0[b_k] *
          rtb_TSamp_jb) + rtb_MatrixConcatenate_0[b_k + 8] * rtb_z_true_0) +
          rtb_MatrixConcatenate_0[b_k + 12] * rtb_TSamp_e;
      }

      axis[0] = BLACK_KF_States[1];
      axis[1] = BLACK_KF_States[2];
      axis[2] = BLACK_KF_States[3];
      rtb_TSamp_e = BLACK_KF_States[0];
      tmp_4[0] = 0.0;
      tmp_4[3] = -BLACK_KF_States[3];
      tmp_4[6] = BLACK_KF_States[2];
      tmp_4[1] = BLACK_KF_States[3];
      tmp_4[4] = 0.0;
      tmp_4[7] = -BLACK_KF_States[1];
      tmp_4[2] = -BLACK_KF_States[2];
      tmp_4[5] = BLACK_KF_States[1];
      tmp_4[8] = 0.0;
      rtb_z_true_1[0] = BLACK_KF_States[0];
      for (b_k = 0; b_k < 3; b_k++) {
        z_bar[b_k + 4] = rtb_MatrixConcatenate[b_k + 1];
        BLUE_Path_Planner_Selection = axis[b_k];
        jj = (b_k + 1) << 2;
        rtb_z_true_1[jj] = -BLUE_Path_Planner_Selection;
        rtb_z_true_1[b_k + 1] = BLUE_Path_Planner_Selection;
        rtb_z_true_1[jj + 1] = static_cast<real_T>(q_tmp[3 * b_k]) * rtb_TSamp_e
          + tmp_4[3 * b_k];
        i = 3 * b_k + 1;
        rtb_z_true_1[jj + 2] = static_cast<real_T>(q_tmp[i]) * rtb_TSamp_e +
          tmp_4[i];
        i = 3 * b_k + 2;
        rtb_z_true_1[jj + 3] = static_cast<real_T>(q_tmp[i]) * rtb_TSamp_e +
          tmp_4[i];
      }

      rtb_TSamp_jb = rtb_z_true[0];
      BLUE_Path_Planner_Selection = -rtb_z_true[1];
      rtb_z_true_0 = -rtb_z_true[2];
      for (b_k = 0; b_k < 4; b_k++) {
        z_bar[b_k] = ((rtb_z_true_1[b_k + 4] * BLUE_Path_Planner_Selection +
                       rtb_z_true_1[b_k] * rtb_TSamp_jb) + rtb_z_true_1[b_k + 8]
                      * rtb_z_true_0) + rtb_z_true_1[b_k + 12] * -rtb_TSamp;
      }

      STQMEKF_smallQuat(&z_bar[0], rtb_MatrixConcatenate);
      z_bar[0] = rtb_MatrixConcatenate[0];
      z_bar[1] = rtb_MatrixConcatenate[1];
      z_bar[2] = rtb_MatrixConcatenate[2];
      z_bar[3] = rtb_MatrixConcatenate[3];
      axis[0] = rtb_Delay1[1];
      axis[1] = rtb_Delay1[2];
      axis[2] = rtb_Delay1[3];
      rtb_TSamp_e = rtb_Delay1[0];
      tmp_4[0] = 0.0;
      tmp_4[3] = -rtb_Delay1[3];
      tmp_4[6] = rtb_Delay1[2];
      tmp_4[1] = rtb_Delay1[3];
      tmp_4[4] = 0.0;
      tmp_4[7] = -rtb_Delay1[1];
      tmp_4[2] = -rtb_Delay1[2];
      tmp_4[5] = rtb_Delay1[1];
      tmp_4[8] = 0.0;
      rtb_z_true_1[0] = rtb_Delay1[0];
      for (b_k = 0; b_k < 3; b_k++) {
        BLUE_Path_Planner_Selection = axis[b_k];
        jj = (b_k + 1) << 2;
        rtb_z_true_1[jj] = -BLUE_Path_Planner_Selection;
        rtb_z_true_1[b_k + 1] = BLUE_Path_Planner_Selection;
        rtb_z_true_1[jj + 1] = static_cast<real_T>(q_tmp[3 * b_k]) * rtb_TSamp_e
          + tmp_4[3 * b_k];
        i = 3 * b_k + 1;
        rtb_z_true_1[jj + 2] = static_cast<real_T>(q_tmp[i]) * rtb_TSamp_e +
          tmp_4[i];
        i = 3 * b_k + 2;
        rtb_z_true_1[jj + 3] = static_cast<real_T>(q_tmp[i]) * rtb_TSamp_e +
          tmp_4[i];
      }

      rtb_TSamp_e = rtb_MatrixConcatenate[0];
      rtb_TSamp_jb = -rtb_MatrixConcatenate[1];
      BLUE_Path_Planner_Selection = -rtb_MatrixConcatenate[2];
      rtb_z_true_0 = -rtb_MatrixConcatenate[3];
      for (b_k = 0; b_k < 4; b_k++) {
        rtb_Delay1_0[b_k] = ((rtb_z_true_1[b_k + 4] * rtb_TSamp_jb +
                              rtb_z_true_1[b_k] * rtb_TSamp_e) +
                             rtb_z_true_1[b_k + 8] * BLUE_Path_Planner_Selection)
          + rtb_z_true_1[b_k + 12] * rtb_z_true_0;
      }

      STQMEKF_smallQuat(rtb_Delay1_0, rtb_MatrixConcatenate);
      memset(&rtb_H_nz[0], 0, 72U * sizeof(real_T));
      rtb_TSamp_e = -rtb_TSamp * -rtb_TSamp;
      rtb_TSamp_jb = -rtb_z_true[2] * -rtb_z_true[2];
      rtb_H_nz[39] = 1.0 - (rtb_TSamp_jb + rtb_TSamp_e) * 2.0;
      BLUE_Path_Planner_Selection = -rtb_z_true[1] * -rtb_z_true[2];
      rtb_z_true_0 = rtb_z_true[0] * -rtb_TSamp;
      rtb_H_nz[45] = (BLUE_Path_Planner_Selection + rtb_z_true_0) * 2.0;
      dyds = (-rtb_z_true[1] * -rtb_TSamp + rtb_z_true[0] * -rtb_z_true[2]) *
        2.0;
      rtb_H_nz[51] = dyds;
      rtb_H_nz[40] = (BLUE_Path_Planner_Selection - rtb_z_true_0) * 2.0;
      BLUE_Path_Planner_Selection = -rtb_z_true[1] * -rtb_z_true[1];
      rtb_H_nz[46] = 1.0 - (BLUE_Path_Planner_Selection + rtb_TSamp_e) * 2.0;
      rtb_TSamp_e = -rtb_z_true[2] * -rtb_TSamp;
      rtb_z_true_0 = rtb_z_true[0] * -rtb_z_true[1];
      rtb_H_nz[52] = (rtb_TSamp_e + rtb_z_true_0) * 2.0;
      rtb_H_nz[41] = dyds;
      rtb_H_nz[47] = (rtb_TSamp_e - rtb_z_true_0) * 2.0;
      rtb_H_nz[53] = 1.0 - (BLUE_Path_Planner_Selection + rtb_TSamp_jb) * 2.0;
      rtb_y[0] = rtb_MatrixConcatenate[1] / (rtb_MatrixConcatenate[0] + 1.0);
      rtb_y[1] = rtb_MatrixConcatenate[2] / (rtb_MatrixConcatenate[0] + 1.0);
      rtb_y[2] = rtb_MatrixConcatenate[3] / (rtb_MatrixConcatenate[0] + 1.0);
      for (i = 0; i < 3; i++) {
        rtb_H_nz[6 * i] = q_tmp[3 * i];
        b_k = (i + 3) * 6;
        rtb_H_nz[b_k + 3] = 0.0;
        jj = (i + 9) * 6;
        rtb_H_nz[jj + 3] = 0.0;
        rtb_H_nz[6 * i + 1] = q_tmp[3 * i + 1];
        rtb_H_nz[b_k + 4] = 0.0;
        rtb_H_nz[jj + 4] = 0.0;
        rtb_H_nz[6 * i + 2] = q_tmp[3 * i + 2];
        rtb_H_nz[b_k + 5] = 0.0;
        rtb_H_nz[jj + 5] = 0.0;
        rtb_y[i + 3] = rtb_Delay1[i + 4] - z_bar[i + 4];
      }

      memcpy(&x[0], &STQMEKF_B.V[0], 36U * sizeof(real_T));
      STQMEKF_xzgetrf(x, ipiv, &b_k);
      rtb_TSamp_e = x[0];
      isodd = false;
      for (i = 0; i < 5; i++) {
        rtb_TSamp_e *= x[((i + 1) * 6 + i) + 1];
        if (ipiv[i] > i + 1) {
          isodd = !isodd;
        }
      }

      if (isodd) {
        rtb_TSamp_e = -rtb_TSamp_e;
      }

      if (rtb_TSamp_e == 0.0) {
        for (b_k = 0; b_k < 6; b_k++) {
          for (jj = 0; jj < 6; jj++) {
            V[jj + 6 * b_k] = rtb_y[jj] * rtb_y[b_k];
          }
        }
      } else {
        for (b_k = 0; b_k < 6; b_k++) {
          for (jj = 0; jj < 6; jj++) {
            V_tmp = 6 * b_k + jj;
            V[V_tmp] = (rtb_y[jj] * rtb_y[b_k] + STQMEKF_B.V[V_tmp]) / 2.0;
          }
        }
      }

      STQMEKF_lsqnonlin(STQMEKF_B.P, rtb_H_nz, V, delta_x);
      for (b_k = 0; b_k < 6; b_k++) {
        for (jj = 0; jj < 12; jj++) {
          a__2_tmp[jj + 12 * b_k] = rtb_H_nz[6 * jj + b_k];
        }
      }

      for (b_k = 0; b_k < 6; b_k++) {
        for (jj = 0; jj < 12; jj++) {
          rtb_TSamp_e = 0.0;
          rtb_TSamp_jb = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_e += P_k[12 * i + jj] * a__2_tmp[12 * b_k + i];
            rtb_TSamp_jb += rtb_H_nz[6 * i + b_k] * P_k[12 * jj + i];
          }

          a__2[jj + 12 * b_k] = rtb_TSamp_e;
          rtb_H_a[b_k + 6 * jj] = rtb_TSamp_jb;
        }

        for (jj = 0; jj < 6; jj++) {
          rtb_TSamp_jb = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_jb += rtb_H_a[6 * i + b_k] * a__2_tmp[12 * jj + i];
          }

          jAcol = 6 * jj + b_k;
          x[jAcol] = R[jAcol] + rtb_TSamp_jb;
        }
      }

      STQMEKF_xzgetrf(x, ipiv, &b_k);
      for (i = 0; i < 6; i++) {
        jBcol = 12 * i;
        jAcol = 6 * i;
        for (b_k = 0; b_k < i; b_k++) {
          kBcol = 12 * b_k;
          rtb_TSamp_jb = x[b_k + jAcol];
          if (rtb_TSamp_jb != 0.0) {
            for (V_tmp = 0; V_tmp < 12; V_tmp++) {
              jj = V_tmp + jBcol;
              a__2[jj] -= a__2[V_tmp + kBcol] * rtb_TSamp_jb;
            }
          }
        }

        rtb_TSamp_e = 1.0 / x[i + jAcol];
        for (V_tmp = 0; V_tmp < 12; V_tmp++) {
          jj = V_tmp + jBcol;
          a__2[jj] *= rtb_TSamp_e;
        }
      }

      for (b_k = 5; b_k >= 0; b_k--) {
        jAcol = 12 * b_k;
        jBcol = 6 * b_k - 1;
        for (i = b_k + 2; i < 7; i++) {
          kBcol = (i - 1) * 12;
          rtb_TSamp_jb = x[i + jBcol];
          if (rtb_TSamp_jb != 0.0) {
            for (V_tmp = 0; V_tmp < 12; V_tmp++) {
              jj = V_tmp + jAcol;
              a__2[jj] -= a__2[V_tmp + kBcol] * rtb_TSamp_jb;
            }
          }
        }
      }

      for (V_tmp = 4; V_tmp >= 0; V_tmp--) {
        b_k = ipiv[V_tmp];
        if (V_tmp + 1 != b_k) {
          for (i = 0; i < 12; i++) {
            jAcol = 12 * V_tmp + i;
            rtb_TSamp_e = a__2[jAcol];
            jj = (b_k - 1) * 12 + i;
            a__2[jAcol] = a__2[jj];
            a__2[jj] = rtb_TSamp_e;
          }
        }
      }

      for (b_k = 0; b_k < 144; b_k++) {
        F[b_k] = d[b_k];
      }

      for (b_k = 0; b_k < 12; b_k++) {
        for (jj = 0; jj < 12; jj++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp_e += a__2[12 * i + jj] * rtb_H_nz[6 * b_k + i];
          }

          P_tmp[jj + 12 * b_k] = rtb_TSamp_e;
        }
      }

      for (b_k = 0; b_k < 144; b_k++) {
        F_0[b_k] = F[b_k] - P_tmp[b_k];
      }

      for (b_k = 0; b_k < 12; b_k++) {
        for (jj = 0; jj < 12; jj++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_e += F_0[12 * i + b_k] * P_k[12 * jj + i];
          }

          V_tmp = 12 * jj + b_k;
          F_1[V_tmp] = rtb_TSamp_e;
          F_2[jj + 12 * b_k] = F[V_tmp] - P_tmp[V_tmp];
        }

        for (jj = 0; jj < 6; jj++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp_e += a__2[12 * i + b_k] * R[6 * jj + i];
          }

          rtb_H_nz[b_k + 12 * jj] = rtb_TSamp_e;
        }
      }

      for (b_k = 0; b_k < 12; b_k++) {
        for (jj = 0; jj < 12; jj++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_e += F_1[12 * i + b_k] * F_2[12 * jj + i];
          }

          V_tmp = 12 * jj + b_k;
          F[V_tmp] = rtb_TSamp_e;
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp_e += rtb_H_nz[12 * i + b_k] * a__2[12 * i + jj];
          }

          F_0[V_tmp] = rtb_TSamp_e;
        }
      }

      for (b_k = 0; b_k < 144; b_k++) {
        STQMEKF_B.P[b_k] = F[b_k] + F_0[b_k];
      }

      for (b_k = 0; b_k < 12; b_k++) {
        rtb_TSamp_e = 0.0;
        for (jj = 0; jj < 6; jj++) {
          rtb_TSamp_e += a__2[12 * jj + b_k] * rtb_y[jj];
        }

        delta_x[b_k] = rtb_TSamp_e;
      }

      rtb_TSamp_e = STQMEKF_norm(&delta_x[0]);
      rtb_TSamp_e *= rtb_TSamp_e;
      rtb_TSamp_e = (sqrt(rtb_TSamp_e * 0.0 + 1.0) - rtb_TSamp_e) / (rtb_TSamp_e
        + 1.0);
      rtb_TSamp_jb = (rtb_TSamp_e + 1.0) * delta_x[0];
      BLUE_Path_Planner_Selection = (rtb_TSamp_e + 1.0) * delta_x[1];
      rtb_z_true_0 = (rtb_TSamp_e + 1.0) * delta_x[2];
      axis[0] = rtb_TSamp_jb;
      axis[1] = BLUE_Path_Planner_Selection;
      axis[2] = rtb_z_true_0;
      tmp_4[0] = 0.0;
      tmp_4[3] = -rtb_z_true_0;
      tmp_4[6] = BLUE_Path_Planner_Selection;
      tmp_4[1] = rtb_z_true_0;
      tmp_4[4] = 0.0;
      tmp_4[7] = -rtb_TSamp_jb;
      tmp_4[2] = -BLUE_Path_Planner_Selection;
      tmp_4[5] = rtb_TSamp_jb;
      tmp_4[8] = 0.0;
      rtb_MatrixConcatenate_0[0] = rtb_TSamp_e;
      for (b_k = 0; b_k < 3; b_k++) {
        BLUE_Path_Planner_Selection = axis[b_k];
        jj = (b_k + 1) << 2;
        rtb_MatrixConcatenate_0[jj] = -BLUE_Path_Planner_Selection;
        rtb_MatrixConcatenate_0[b_k + 1] = BLUE_Path_Planner_Selection;
        rtb_MatrixConcatenate_0[jj + 1] = static_cast<real_T>(q_tmp[3 * b_k]) *
          rtb_TSamp_e + tmp_4[3 * b_k];
        i = 3 * b_k + 1;
        rtb_MatrixConcatenate_0[jj + 2] = static_cast<real_T>(q_tmp[i]) *
          rtb_TSamp_e + tmp_4[i];
        i = 3 * b_k + 2;
        rtb_MatrixConcatenate_0[jj + 3] = static_cast<real_T>(q_tmp[i]) *
          rtb_TSamp_e + tmp_4[i];
      }

      rtb_TSamp_e = BLACK_KF_States[1];
      BLUE_Path_Planner_Selection = BLACK_KF_States[0];
      rtb_z_true_0 = BLACK_KF_States[2];
      dyds = BLACK_KF_States[3];
      for (b_k = 0; b_k < 4; b_k++) {
        rtb_TSamp_jb = ((rtb_MatrixConcatenate_0[b_k + 4] * rtb_TSamp_e +
                         rtb_MatrixConcatenate_0[b_k] *
                         BLUE_Path_Planner_Selection) +
                        rtb_MatrixConcatenate_0[b_k + 8] * rtb_z_true_0) +
          rtb_MatrixConcatenate_0[b_k + 12] * dyds;
        STQMEKF_B.x[b_k] = rtb_TSamp_jb;
        rtb_MatrixConcatenate[b_k] = rtb_TSamp_jb * rtb_TSamp_jb;
      }

      rtb_TSamp_e = sqrt(((rtb_MatrixConcatenate[0] + rtb_MatrixConcatenate[1])
                          + rtb_MatrixConcatenate[2]) + rtb_MatrixConcatenate[3]);
      STQMEKF_B.x[0] /= rtb_TSamp_e;
      STQMEKF_B.x[1] /= rtb_TSamp_e;
      STQMEKF_B.x[2] /= rtb_TSamp_e;
      STQMEKF_B.x[3] /= rtb_TSamp_e;
      for (i = 0; i < 9; i++) {
        STQMEKF_B.x[i + 4] = BLACK_KF_States[i + 4] + delta_x[i + 3];
      }
    }

    memcpy(&STQMEKF_B.V[0], &V[0], 36U * sizeof(real_T));

    // DataStoreWrite: '<S216>/Data Store Write'
    memcpy(&BLACK_KF_States[0], &STQMEKF_B.x[0], 13U * sizeof(real_T));

    // MATLAB Function: '<S216>/Nis'
    for (b_k = 0; b_k < 36; b_k++) {
      V[b_k] = STQMEKF_B.V[b_k];
      x[b_k] = 0.0;
    }

    for (b_k = 0; b_k < 6; b_k++) {
      ipiv_0[b_k] = static_cast<int8_T>(b_k + 1);
    }

    for (b_k = 0; b_k < 5; b_k++) {
      jj = b_k * 7;
      V_tmp = 5 - b_k;
      jAcol = 0;
      rtb_TSamp_e = fabs(V[jj]);
      for (i = 2; i <= V_tmp + 1; i++) {
        rtb_TSamp_jb = fabs(V[(jj + i) - 1]);
        if (rtb_TSamp_jb > rtb_TSamp_e) {
          jAcol = i - 1;
          rtb_TSamp_e = rtb_TSamp_jb;
        }
      }

      if (V[jj + jAcol] != 0.0) {
        if (jAcol != 0) {
          jBcol = b_k + jAcol;
          ipiv_0[b_k] = static_cast<int8_T>(jBcol + 1);
          for (i = 0; i < 6; i++) {
            jAcol = i * 6 + b_k;
            rtb_TSamp_e = V[jAcol];
            V_tmp = i * 6 + jBcol;
            V[jAcol] = V[V_tmp];
            V[V_tmp] = rtb_TSamp_e;
          }
        }

        i = (jj - b_k) + 6;
        for (V_tmp = jj + 2; V_tmp <= i; V_tmp++) {
          V[V_tmp - 1] /= V[jj];
        }
      }

      jAcol = 4 - b_k;
      jBcol = jj + 8;
      for (i = 0; i <= jAcol; i++) {
        rtb_TSamp_jb = V[(i * 6 + jj) + 6];
        if (rtb_TSamp_jb != 0.0) {
          kBcol = (jBcol - b_k) + 4;
          for (V_tmp = jBcol; V_tmp <= kBcol; V_tmp++) {
            V[V_tmp - 1] += V[((jj + V_tmp) - jBcol) + 1] * -rtb_TSamp_jb;
          }
        }

        jBcol += 6;
      }
    }

    for (b_k = 0; b_k < 6; b_k++) {
      p[b_k] = static_cast<int8_T>(b_k + 1);
    }

    for (b_k = 0; b_k < 5; b_k++) {
      rtPrevAction = ipiv_0[b_k];
      if (rtPrevAction > b_k + 1) {
        jj = p[rtPrevAction - 1];
        p[rtPrevAction - 1] = p[b_k];
        p[b_k] = static_cast<int8_T>(jj);
      }
    }

    for (jj = 0; jj < 6; jj++) {
      jAcol = (p[jj] - 1) * 6;
      x[jj + jAcol] = 1.0;
      for (V_tmp = jj + 1; V_tmp < 7; V_tmp++) {
        b_k = (jAcol + V_tmp) - 1;
        if (x[b_k] != 0.0) {
          for (i = V_tmp + 1; i < 7; i++) {
            jBcol = (jAcol + i) - 1;
            x[jBcol] -= V[((V_tmp - 1) * 6 + i) - 1] * x[b_k];
          }
        }
      }
    }

    for (i = 0; i < 6; i++) {
      jBcol = 6 * i;
      for (jj = 5; jj >= 0; jj--) {
        kBcol = 6 * jj;
        b_k = jj + jBcol;
        rtb_TSamp_jb = x[b_k];
        if (rtb_TSamp_jb != 0.0) {
          x[b_k] = rtb_TSamp_jb / V[jj + kBcol];
          for (V_tmp = 0; V_tmp < jj; V_tmp++) {
            jAcol = V_tmp + jBcol;
            x[jAcol] -= V[V_tmp + kBcol] * x[b_k];
          }
        }
      }
    }

    // MATLAB Function: '<S217>/Rel 2 Global'
    axis[0] = rtb_z_true[1];
    axis[1] = rtb_z_true[2];
    axis[2] = rtb_TSamp;
    rtb_TSamp_jb = rtb_z_true[0];
    rtb_TSamp_e = sqrt(((rtb_z_true[0] * rtb_z_true[0] + -rtb_z_true[1] *
                         -rtb_z_true[1]) + -rtb_z_true[2] * -rtb_z_true[2]) +
                       -rtb_TSamp * -rtb_TSamp);
    b_vector[0] = -rtb_z_true[1];
    b_vector[1] = -rtb_z_true[2];
    b_vector[2] = -rtb_TSamp;
    for (b_k = 0; b_k < 9; b_k++) {
      q_tmp[b_k] = b[b_k];
    }

    tmp_4[0] = 0.0;
    tmp_4[3] = rtb_TSamp;
    tmp_4[6] = -rtb_z_true[2];
    tmp_4[1] = -rtb_TSamp;
    tmp_4[4] = 0.0;
    tmp_4[7] = rtb_z_true[1];
    tmp_4[2] = rtb_z_true[2];
    tmp_4[5] = -rtb_z_true[1];
    tmp_4[8] = 0.0;
    rtb_z_true_1[0] = rtb_z_true[0];
    for (b_k = 0; b_k < 3; b_k++) {
      BLUE_Path_Planner_Selection = b_vector[b_k];
      jj = (b_k + 1) << 2;
      rtb_z_true_1[jj] = -BLUE_Path_Planner_Selection;
      rtb_z_true_1[b_k + 1] = BLUE_Path_Planner_Selection;
      rtb_z_true_1[jj + 1] = static_cast<real_T>(q_tmp[3 * b_k]) * rtb_TSamp_jb
        + tmp_4[3 * b_k];
      i = 3 * b_k + 1;
      rtb_z_true_1[jj + 2] = static_cast<real_T>(q_tmp[i]) * rtb_TSamp_jb +
        tmp_4[i];
      i = 3 * b_k + 2;
      rtb_z_true_1[jj + 3] = static_cast<real_T>(q_tmp[i]) * rtb_TSamp_jb +
        tmp_4[i];
      rtb_MatrixConcatenate[b_k + 1] = rtb_Delay1[b_k + 4];
    }

    rtb_TSamp_jb = rtb_MatrixConcatenate[1];
    BLUE_Path_Planner_Selection = rtb_MatrixConcatenate[2];
    rtb_z_true_0 = rtb_MatrixConcatenate[3];
    for (b_k = 0; b_k < 4; b_k++) {
      rtb_MatrixConcatenate[b_k] = ((rtb_z_true_1[b_k + 4] * rtb_TSamp_jb +
        rtb_z_true_1[b_k] * 0.0) + rtb_z_true_1[b_k + 8] *
        BLUE_Path_Planner_Selection) + rtb_z_true_1[b_k + 12] * rtb_z_true_0;
    }

    b_vector[0] = rtb_MatrixConcatenate[1];
    b_vector[1] = rtb_MatrixConcatenate[2];
    b_vector[2] = rtb_MatrixConcatenate[3];

    // DataStoreWrite: '<S16>/Data Store Write' incorporates:
    //   Constant: '<S16>/Constant'

    STQMEKF_DW.isSim = STQMEKF_P.simMode;

    // If: '<S1>/Separate Phases' incorporates:
    //   Constant: '<S1>/Constant'
    //   Constant: '<S1>/Constant1'
    //   Constant: '<S1>/Constant2'
    //   Constant: '<S1>/Constant3'
    //   Constant: '<S1>/Constant4'
    //   Constant: '<S1>/Constant6'
    //   DataStoreRead: '<S1>/Universal_Time25'

    if (STQMEKF_DW.Univ_Time < STQMEKF_P.Phase0_End) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #0: Synchronization' incorporates:
      //   ActionPort: '<S18>/Action Port'

      STQMEKF_Phase0Synchronization(&STQMEKF_DW.ARM_Control_Law_Enabler,
        &rtb_TSamp_jb, &STQMEKF_DW.BLACK_Control_Law_Enabler,
        &STQMEKF_DW.BLACK_Path_Planner_Selection,
        &STQMEKF_DW.BLUE_Control_Law_Enabler, &BLUE_Path_Planner_Selection,
        &STQMEKF_DW.Float_State, &STQMEKF_DW.RED_Control_Law_Enabler,
        STQMEKF_DW.RED_Logger, &STQMEKF_DW.RED_Path_Planner_Selection,
        &STQMEKF_P.Phase0Synchronization);

      // End of Outputs for SubSystem: '<S1>/Phase #0: Synchronization'
    } else if ((STQMEKF_DW.Univ_Time < STQMEKF_P.Phase1_End) &&
               (STQMEKF_DW.Univ_Time >= STQMEKF_P.Phase0_End)) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #1: Start Floating ' incorporates:
      //   ActionPort: '<S19>/Action Port'

      STQMEKF_Phase0Synchronization(&STQMEKF_DW.ARM_Control_Law_Enabler,
        &rtb_TSamp_jb, &STQMEKF_DW.BLACK_Control_Law_Enabler,
        &STQMEKF_DW.BLACK_Path_Planner_Selection,
        &STQMEKF_DW.BLUE_Control_Law_Enabler, &BLUE_Path_Planner_Selection,
        &STQMEKF_DW.Float_State, &STQMEKF_DW.RED_Control_Law_Enabler,
        STQMEKF_DW.RED_Logger, &STQMEKF_DW.RED_Path_Planner_Selection,
        &STQMEKF_P.Phase1StartFloating);

      // End of Outputs for SubSystem: '<S1>/Phase #1: Start Floating '
    } else if ((STQMEKF_DW.Univ_Time < STQMEKF_P.Phase2_End) &&
               (STQMEKF_DW.Univ_Time >= STQMEKF_P.Phase1_End)) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #2: Initial Position' incorporates:
      //   ActionPort: '<S20>/Action Port'

      // DataStoreWrite: '<S20>/Data Store Write24' incorporates:
      //   Constant: '<S20>/Constant11'

      STQMEKF_DW.RED_Path_Planner_Selection = STQMEKF_P.Constant11_Value;

      // DataStoreWrite: '<S20>/Data Store Write23' incorporates:
      //   Constant: '<S20>/Constant14'

      STQMEKF_DW.BLACK_Path_Planner_Selection = STQMEKF_P.Constant14_Value;

      // DataStoreWrite: '<S20>/Data Store Write27' incorporates:
      //   Constant: '<S20>/Constant18'

      STQMEKF_DW.ARM_Control_Law_Enabler = STQMEKF_P.Constant18_Value;

      // DataStoreWrite: '<S20>/Data Store Write4' incorporates:
      //   Constant: '<S20>/Constant4'

      STQMEKF_DW.BLACK_Control_Law_Enabler = STQMEKF_P.Constant4_Value;

      // DataStoreWrite: '<S20>/Data Store Write8' incorporates:
      //   Constant: '<S20>/Constant5'

      STQMEKF_DW.RED_Control_Law_Enabler = STQMEKF_P.Constant5_Value;

      // DataStoreWrite: '<S20>/Data Store Write7' incorporates:
      //   Constant: '<S20>/Constant6'

      STQMEKF_DW.Float_State = STQMEKF_P.Constant6_Value;

      // DataStoreWrite: '<S20>/Data Store Write16' incorporates:
      //   Constant: '<S20>/Constant8'

      STQMEKF_DW.BLUE_Control_Law_Enabler = STQMEKF_P.Constant8_Value;

      // DataStoreWrite: '<S20>/Data Store Write13' incorporates:
      //   Constant: '<S25>/Constant1'
      //   Constant: '<S25>/Constant2'
      //   Constant: '<S25>/Constant3'

      STQMEKF_DW.ARM_Desired_States[0] = STQMEKF_P.Constant3_Value;
      STQMEKF_DW.ARM_Desired_States[1] = STQMEKF_P.Constant1_Value;
      STQMEKF_DW.ARM_Desired_States[2] = STQMEKF_P.Constant2_Value;

      // DataStoreWrite: '<S20>/Data Store Write1' incorporates:
      //   Constant: '<S26>/Desired States (BLACK)'

      STQMEKF_DW.BLACK_Desired_States[0] = STQMEKF_P.init_states_BLACK[0];

      // DataStoreWrite: '<S20>/Data Store Write18' incorporates:
      //   Constant: '<S27>/Desired States (BLUE)'

      STQMEKF_DW.BLUE_Desired_States[0] = STQMEKF_P.init_states_BLUE[0];

      // DataStoreWrite: '<S20>/Data Store Write9' incorporates:
      //   Constant: '<S28>/Constant2'

      STQMEKF_DW.RED_Desired_States[0] = STQMEKF_P.init_states_RED[0];

      // DataStoreWrite: '<S20>/Data Store Write1' incorporates:
      //   Constant: '<S26>/Desired States (BLACK)'

      STQMEKF_DW.BLACK_Desired_States[1] = STQMEKF_P.init_states_BLACK[1];

      // DataStoreWrite: '<S20>/Data Store Write18' incorporates:
      //   Constant: '<S27>/Desired States (BLUE)'

      STQMEKF_DW.BLUE_Desired_States[1] = STQMEKF_P.init_states_BLUE[1];

      // DataStoreWrite: '<S20>/Data Store Write9' incorporates:
      //   Constant: '<S28>/Constant2'

      STQMEKF_DW.RED_Desired_States[1] = STQMEKF_P.init_states_RED[1];

      // DataStoreWrite: '<S20>/Data Store Write1' incorporates:
      //   Constant: '<S26>/Desired States (BLACK)'

      STQMEKF_DW.BLACK_Desired_States[2] = STQMEKF_P.init_states_BLACK[2];

      // DataStoreWrite: '<S20>/Data Store Write18' incorporates:
      //   Constant: '<S27>/Desired States (BLUE)'

      STQMEKF_DW.BLUE_Desired_States[2] = STQMEKF_P.init_states_BLUE[2];

      // DataStoreWrite: '<S20>/Data Store Write9' incorporates:
      //   Constant: '<S28>/Constant2'

      STQMEKF_DW.RED_Desired_States[2] = STQMEKF_P.init_states_RED[2];

      // End of Outputs for SubSystem: '<S1>/Phase #2: Initial Position'
    } else if ((STQMEKF_DW.Univ_Time < STQMEKF_P.Phase3_End) &&
               (STQMEKF_DW.Univ_Time >= STQMEKF_P.Phase2_End)) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #3: Experiment' incorporates:
      //   ActionPort: '<S21>/Action Port'

      // If: '<S21>/Experiment Sub-Phases' incorporates:
      //   Constant: '<S21>/Constant1'
      //   Constant: '<S21>/Constant2'
      //   Constant: '<S21>/Constant3'
      //   Constant: '<S21>/Constant4'
      //   DataStoreRead: '<S21>/Universal_Time'

      if (STQMEKF_DW.Univ_Time < STQMEKF_P.Phase3_SubPhase1_End) {
        // Outputs for IfAction SubSystem: '<S21>/Sub-Phase #1' incorporates:
        //   ActionPort: '<S29>/Action Port'

        // DataStoreWrite: '<S29>/Data Store Write24' incorporates:
        //   Constant: '<S29>/Constant11'

        STQMEKF_DW.RED_Path_Planner_Selection = STQMEKF_P.Constant11_Value_e;

        // DataStoreWrite: '<S29>/Data Store Write23' incorporates:
        //   Constant: '<S29>/Constant14'

        STQMEKF_DW.BLACK_Path_Planner_Selection = STQMEKF_P.Constant14_Value_f;

        // DataStoreWrite: '<S29>/Data Store Write2' incorporates:
        //   Constant: '<S29>/Constant18'

        STQMEKF_DW.ARM_Control_Law_Enabler = STQMEKF_P.Constant18_Value_m;

        // DataStoreWrite: '<S29>/Data Store Write4' incorporates:
        //   Constant: '<S29>/Constant4'

        STQMEKF_DW.BLACK_Control_Law_Enabler = STQMEKF_P.Constant4_Value_g;

        // DataStoreWrite: '<S29>/Data Store Write3' incorporates:
        //   Constant: '<S29>/Constant5'

        STQMEKF_DW.RED_Control_Law_Enabler = STQMEKF_P.Constant5_Value_o;

        // DataStoreWrite: '<S29>/Data Store Write7' incorporates:
        //   Constant: '<S29>/Constant6'

        STQMEKF_DW.Float_State = STQMEKF_P.Constant6_Value_i;

        // DataStoreWrite: '<S29>/Data Store Write16' incorporates:
        //   Constant: '<S29>/Constant8'

        STQMEKF_DW.BLUE_Control_Law_Enabler = STQMEKF_P.Constant8_Value_m;

        // DataStoreWrite: '<S29>/Data Store Write13' incorporates:
        //   Constant: '<S33>/Constant1'
        //   Constant: '<S33>/Constant2'
        //   Constant: '<S33>/Constant3'

        STQMEKF_DW.ARM_Desired_States[0] = STQMEKF_P.Constant3_Value_b;
        STQMEKF_DW.ARM_Desired_States[1] = STQMEKF_P.Constant1_Value_o;
        STQMEKF_DW.ARM_Desired_States[2] = STQMEKF_P.Constant2_Value_f;

        // Product: '<S35>/Product' incorporates:
        //   Constant: '<S35>/Desired Rate '
        //   Constant: '<S38>/Constant2'
        //   DataStoreRead: '<S40>/Universal_Time'
        //   Sum: '<S38>/Subtract3'

        BLUE_Path_Planner_Selection = (STQMEKF_DW.Univ_Time -
          STQMEKF_P.Phase2_End) * STQMEKF_P.DesiredRate_Value;

        // Trigonometry: '<S37>/Sin' incorporates:
        //   Trigonometry: '<S39>/Sin'

        rtb_TSamp_jb = sin(BLUE_Path_Planner_Selection);

        // Trigonometry: '<S37>/Cos' incorporates:
        //   Trigonometry: '<S39>/Cos'

        BLUE_Path_Planner_Selection = cos(BLUE_Path_Planner_Selection);

        // DataStoreWrite: '<S29>/Data Store Write18' incorporates:
        //   Constant: '<S37>/Constant1'
        //   Constant: '<S37>/Constant2'
        //   Gain: '<S37>/Gain'
        //   Gain: '<S37>/Gain1'
        //   Sum: '<S37>/Sum1'
        //   Sum: '<S37>/Sum2'
        //   Trigonometry: '<S37>/Cos'
        //   Trigonometry: '<S37>/Sin'
        //   Trigonometry: '<S39>/Atan2'

        STQMEKF_DW.BLUE_Desired_States[0] = STQMEKF_P.Gain_Gain *
          BLUE_Path_Planner_Selection + STQMEKF_P.xLength / 2.0;
        STQMEKF_DW.BLUE_Desired_States[1] = STQMEKF_P.Gain1_Gain * rtb_TSamp_jb
          + STQMEKF_P.yLength / 2.0;
        STQMEKF_DW.BLUE_Desired_States[2] = rt_atan2d_snf(rtb_TSamp_jb,
          BLUE_Path_Planner_Selection);

        // DataStoreWrite: '<S29>/Data Store Write5' incorporates:
        //   Constant: '<S34>/Constant'
        //   SignalGenerator: '<S34>/Signal Generator'
        //   Sum: '<S34>/Sum'

        STQMEKF_DW.BLACK_Desired_States[0] = STQMEKF_P.init_states_BLACK[0];
        STQMEKF_DW.BLACK_Desired_States[1] = sin(6.2831853071795862 *
          STQMEKF_M->Timing.t[0] * STQMEKF_P.SignalGenerator_Frequency) *
          STQMEKF_P.SignalGenerator_Amplitude + STQMEKF_P.init_states_BLACK[1];
        STQMEKF_DW.BLACK_Desired_States[2] = STQMEKF_P.init_states_BLACK[2];

        // DataStoreWrite: '<S29>/Data Store Write9' incorporates:
        //   Constant: '<S36>/Constant'

        STQMEKF_DW.RED_Desired_States[0] = STQMEKF_P.init_states_RED[0];
        STQMEKF_DW.RED_Desired_States[1] = STQMEKF_P.init_states_RED[1];
        STQMEKF_DW.RED_Desired_States[2] = STQMEKF_P.init_states_RED[2];

        // End of Outputs for SubSystem: '<S21>/Sub-Phase #1'
      } else if ((STQMEKF_DW.Univ_Time < STQMEKF_P.Phase3_SubPhase2_End) &&
                 (STQMEKF_DW.Univ_Time >= STQMEKF_P.Phase3_SubPhase1_End)) {
        // Outputs for IfAction SubSystem: '<S21>/Sub-Phase #2 ' incorporates:
        //   ActionPort: '<S30>/Action Port'

        // DataStoreWrite: '<S30>/Data Store Write24' incorporates:
        //   Constant: '<S30>/Constant11'

        STQMEKF_DW.RED_Path_Planner_Selection = STQMEKF_P.Constant11_Value_m;

        // DataStoreWrite: '<S30>/Data Store Write23' incorporates:
        //   Constant: '<S30>/Constant14'

        STQMEKF_DW.BLACK_Path_Planner_Selection = STQMEKF_P.Constant14_Value_i;

        // DataStoreWrite: '<S30>/Data Store Write2' incorporates:
        //   Constant: '<S30>/Constant18'

        STQMEKF_DW.ARM_Control_Law_Enabler = STQMEKF_P.Constant18_Value_n;

        // DataStoreWrite: '<S30>/Data Store Write4' incorporates:
        //   Constant: '<S30>/Constant4'

        STQMEKF_DW.BLACK_Control_Law_Enabler = STQMEKF_P.Constant4_Value_a;

        // DataStoreWrite: '<S30>/Data Store Write3' incorporates:
        //   Constant: '<S30>/Constant5'

        STQMEKF_DW.RED_Control_Law_Enabler = STQMEKF_P.Constant5_Value_m;

        // DataStoreWrite: '<S30>/Data Store Write7' incorporates:
        //   Constant: '<S30>/Constant6'

        STQMEKF_DW.Float_State = STQMEKF_P.Constant6_Value_p;

        // DataStoreWrite: '<S30>/Data Store Write16' incorporates:
        //   Constant: '<S30>/Constant8'

        STQMEKF_DW.BLUE_Control_Law_Enabler = STQMEKF_P.Constant8_Value_o;

        // DataStoreWrite: '<S30>/Data Store Write13' incorporates:
        //   Constant: '<S41>/Constant1'
        //   Constant: '<S41>/Constant2'
        //   Constant: '<S41>/Constant3'

        STQMEKF_DW.ARM_Desired_States[0] = STQMEKF_P.Constant3_Value_p;
        STQMEKF_DW.ARM_Desired_States[1] = STQMEKF_P.Constant1_Value_m;
        STQMEKF_DW.ARM_Desired_States[2] = STQMEKF_P.Constant2_Value_p;

        // Sum: '<S49>/Subtract3' incorporates:
        //   Constant: '<S49>/Constant2'
        //   DataStoreRead: '<S51>/Universal_Time'
        //   Sum: '<S47>/Subtract'

        BLUE_Path_Planner_Selection_tmp = STQMEKF_DW.Univ_Time -
          STQMEKF_P.Phase2_End;

        // Product: '<S43>/Product' incorporates:
        //   Constant: '<S43>/Desired Rate '
        //   Sum: '<S49>/Subtract3'

        BLUE_Path_Planner_Selection = BLUE_Path_Planner_Selection_tmp *
          STQMEKF_P.DesiredRate_Value_h;

        // Trigonometry: '<S48>/Sin' incorporates:
        //   Trigonometry: '<S50>/Sin'

        rtb_TSamp_jb = sin(BLUE_Path_Planner_Selection);

        // Trigonometry: '<S48>/Cos' incorporates:
        //   Trigonometry: '<S50>/Cos'

        BLUE_Path_Planner_Selection = cos(BLUE_Path_Planner_Selection);

        // DataStoreWrite: '<S30>/Data Store Write18' incorporates:
        //   Constant: '<S48>/Constant1'
        //   Constant: '<S48>/Constant2'
        //   Gain: '<S48>/Gain'
        //   Gain: '<S48>/Gain1'
        //   Sum: '<S48>/Sum1'
        //   Sum: '<S48>/Sum2'
        //   Trigonometry: '<S48>/Cos'
        //   Trigonometry: '<S48>/Sin'
        //   Trigonometry: '<S50>/Atan2'

        STQMEKF_DW.BLUE_Desired_States[0] = STQMEKF_P.Gain_Gain_h *
          BLUE_Path_Planner_Selection + STQMEKF_P.xLength / 2.0;
        STQMEKF_DW.BLUE_Desired_States[1] = STQMEKF_P.Gain1_Gain_c *
          rtb_TSamp_jb + STQMEKF_P.yLength / 2.0;
        STQMEKF_DW.BLUE_Desired_States[2] = rt_atan2d_snf(rtb_TSamp_jb,
          BLUE_Path_Planner_Selection);

        // Product: '<S45>/Product' incorporates:
        //   Constant: '<S45>/Desired Rate (BLACK)'

        rtb_TSamp_jb = BLUE_Path_Planner_Selection_tmp *
          STQMEKF_P.DesiredRateBLACK_Value;

        // DataStoreWrite: '<S30>/Data Store Write5' incorporates:
        //   Constant: '<S42>/Desired X-Position (BLACK)'
        //   Constant: '<S42>/Desired Y-Position (BLACK)'
        //   Trigonometry: '<S46>/Atan2'
        //   Trigonometry: '<S46>/Cos'
        //   Trigonometry: '<S46>/Sin'

        STQMEKF_DW.BLACK_Desired_States[0] = STQMEKF_P.xLength / 2.0;
        STQMEKF_DW.BLACK_Desired_States[1] = STQMEKF_P.yLength / 2.0;
        STQMEKF_DW.BLACK_Desired_States[2] = rt_atan2d_snf(sin(rtb_TSamp_jb),
          cos(rtb_TSamp_jb));

        // DataStoreWrite: '<S30>/Data Store Write9' incorporates:
        //   Constant: '<S44>/Constant'
        //   Constant: '<S44>/Constant1'
        //   Constant: '<S44>/Constant4'

        STQMEKF_DW.RED_Desired_States[0] = STQMEKF_P.init_states_RED[0];
        STQMEKF_DW.RED_Desired_States[1] = STQMEKF_P.init_states_RED[1];
        STQMEKF_DW.RED_Desired_States[2] = STQMEKF_P.init_states_RED[2];

        // End of Outputs for SubSystem: '<S21>/Sub-Phase #2 '
      } else if ((STQMEKF_DW.Univ_Time < STQMEKF_P.Phase3_SubPhase3_End) &&
                 (STQMEKF_DW.Univ_Time >= STQMEKF_P.Phase3_SubPhase2_End)) {
        // Outputs for IfAction SubSystem: '<S21>/Sub-Phase #3 ' incorporates:
        //   ActionPort: '<S31>/Action Port'

        // DataStoreWrite: '<S31>/Data Store Write24' incorporates:
        //   Constant: '<S31>/Constant11'

        STQMEKF_DW.RED_Path_Planner_Selection = STQMEKF_P.Constant11_Value_b;

        // DataStoreWrite: '<S31>/Data Store Write23' incorporates:
        //   Constant: '<S31>/Constant14'

        STQMEKF_DW.BLACK_Path_Planner_Selection = STQMEKF_P.Constant14_Value_n;

        // DataStoreWrite: '<S31>/Data Store Write2' incorporates:
        //   Constant: '<S31>/Constant18'

        STQMEKF_DW.ARM_Control_Law_Enabler = STQMEKF_P.Constant18_Value_l;

        // DataStoreWrite: '<S31>/Data Store Write4' incorporates:
        //   Constant: '<S31>/Constant4'

        STQMEKF_DW.BLACK_Control_Law_Enabler = STQMEKF_P.Constant4_Value_b;

        // DataStoreWrite: '<S31>/Data Store Write3' incorporates:
        //   Constant: '<S31>/Constant5'

        STQMEKF_DW.RED_Control_Law_Enabler = STQMEKF_P.Constant5_Value_n;

        // DataStoreWrite: '<S31>/Data Store Write7' incorporates:
        //   Constant: '<S31>/Constant6'

        STQMEKF_DW.Float_State = STQMEKF_P.Constant6_Value_n;

        // DataStoreWrite: '<S31>/Data Store Write16' incorporates:
        //   Constant: '<S31>/Constant8'

        STQMEKF_DW.BLUE_Control_Law_Enabler = STQMEKF_P.Constant8_Value_f;

        // DataStoreWrite: '<S31>/Data Store Write13' incorporates:
        //   Constant: '<S52>/Constant1'
        //   Constant: '<S52>/Constant2'
        //   Constant: '<S52>/Constant3'

        STQMEKF_DW.ARM_Desired_States[0] = STQMEKF_P.Constant3_Value_e;
        STQMEKF_DW.ARM_Desired_States[1] = STQMEKF_P.Constant1_Value_p;
        STQMEKF_DW.ARM_Desired_States[2] = STQMEKF_P.Constant2_Value_c;

        // Sum: '<S57>/Subtract3' incorporates:
        //   Constant: '<S57>/Constant2'
        //   DataStoreRead: '<S59>/Universal_Time'
        //   Sum: '<S63>/Subtract'

        BLUE_Path_Planner_Selection_tmp = STQMEKF_DW.Univ_Time -
          STQMEKF_P.Phase2_End;

        // Product: '<S53>/Product' incorporates:
        //   Constant: '<S53>/Desired Rate '
        //   Sum: '<S57>/Subtract3'

        BLUE_Path_Planner_Selection = BLUE_Path_Planner_Selection_tmp *
          STQMEKF_P.DesiredRate_Value_l;

        // Trigonometry: '<S56>/Sin' incorporates:
        //   Trigonometry: '<S58>/Sin'

        rtb_TSamp_jb = sin(BLUE_Path_Planner_Selection);

        // Trigonometry: '<S56>/Cos' incorporates:
        //   Trigonometry: '<S58>/Cos'

        BLUE_Path_Planner_Selection = cos(BLUE_Path_Planner_Selection);

        // DataStoreWrite: '<S31>/Data Store Write18' incorporates:
        //   Constant: '<S56>/Constant1'
        //   Constant: '<S56>/Constant2'
        //   Gain: '<S56>/Gain'
        //   Gain: '<S56>/Gain1'
        //   Sum: '<S56>/Sum1'
        //   Sum: '<S56>/Sum2'
        //   Trigonometry: '<S56>/Cos'
        //   Trigonometry: '<S56>/Sin'
        //   Trigonometry: '<S58>/Atan2'

        STQMEKF_DW.BLUE_Desired_States[0] = STQMEKF_P.Gain_Gain_b *
          BLUE_Path_Planner_Selection + STQMEKF_P.xLength / 2.0;
        STQMEKF_DW.BLUE_Desired_States[1] = STQMEKF_P.Gain1_Gain_k *
          rtb_TSamp_jb + STQMEKF_P.yLength / 2.0;
        STQMEKF_DW.BLUE_Desired_States[2] = rt_atan2d_snf(rtb_TSamp_jb,
          BLUE_Path_Planner_Selection);

        // Sum: '<S55>/Subtract' incorporates:
        //   Clock: '<S55>/Clock'
        //   Constant: '<S55>/Constant'

        rtb_z_true_0 = STQMEKF_M->Timing.t[0] - STQMEKF_P.Phase3_SubPhase2_End;

        // MATLAB Function: '<S55>/MATLAB Function'
        if (!(rtb_z_true_0 <= 120.0)) {
          rtb_z_true_0 = 120.0;
        }

        if (rtb_z_true_0 <= 0.0) {
          rtb_z_true_0 = 0.0;
        }

        if (rtb_z_true_0 <= 24.0) {
          rtb_TSamp_jb = (1.0 - cos(rtb_z_true_0 / 24.0 * 3.1415926535897931)) /
            4.0;
          isodd = false;
          u_loop = 0.0;
        } else if (rtb_z_true_0 <= 96.0) {
          rtb_TSamp_jb = 0.5;
          u_loop = (rtb_z_true_0 - 24.0) / 72.0;
          isodd = true;
        } else {
          rtb_TSamp_jb = (1.0 - cos(((rtb_z_true_0 - 24.0) - 72.0) / 24.0 *
            3.1415926535897931)) / 4.0 + 0.5;
          isodd = false;
          u_loop = 0.0;
        }

        dxds = (1.0 - rtb_TSamp_jb) * 6.0 * rtb_TSamp_jb * -1.6;
        rtb_z_true_0 = (1.0 - rtb_TSamp_jb) * (1.0 - rtb_TSamp_jb) * 3.0;
        BLUE_Path_Planner_Selection = rtb_TSamp_jb * rtb_TSamp_jb;
        dyds = BLUE_Path_Planner_Selection * 3.0 * -0.6 + -rtb_z_true_0;
        y_off = rt_hypotd_snf(dxds, dyds);
        dxds /= y_off + 2.2204460492503131E-16;
        ty = dyds / (y_off + 2.2204460492503131E-16);
        dyds = 0.0;
        y_off = 0.0;
        if (isodd) {
          y_off = cos(6.2831853071795862 * u_loop);
          env = (1.0 - y_off) * 0.5;
          u_loop = sin(6.2831853071795862 * u_loop);
          dyds = (y_off * -ty + u_loop * dxds) * (0.3 * env);
          y_off = (y_off * dxds + u_loop * ty) * (0.3 * env);
        }

        u_loop = rt_powd_snf(1.0 - rtb_TSamp_jb, 3.0);
        dxds = rt_powd_snf(rtb_TSamp_jb, 3.0);

        // Product: '<S60>/Product' incorporates:
        //   Constant: '<S60>/Desired Rate (BLACK)'

        ty = BLUE_Path_Planner_Selection_tmp *
          STQMEKF_P.DesiredRateBLACK_Value_c;

        // MATLAB Function: '<S55>/MATLAB Function'
        rtb_z_true_0 *= rtb_TSamp_jb;
        rtb_TSamp_jb = (1.0 - rtb_TSamp_jb) * 3.0 * BLUE_Path_Planner_Selection;

        // DataStoreWrite: '<S31>/Data Store Write5' incorporates:
        //   MATLAB Function: '<S55>/MATLAB Function'
        //   Trigonometry: '<S62>/Atan2'
        //   Trigonometry: '<S62>/Cos'
        //   Trigonometry: '<S62>/Sin'

        STQMEKF_DW.BLACK_Desired_States[0] = (((rtb_z_true_0 * 2.0 + u_loop *
          2.0) + rtb_TSamp_jb * 0.4) + dxds * 0.4) + dyds;
        STQMEKF_DW.BLACK_Desired_States[1] = (((u_loop * 2.0 + rtb_z_true_0) +
          rtb_TSamp_jb) + dxds * 0.4) + y_off;
        STQMEKF_DW.BLACK_Desired_States[2] = rt_atan2d_snf(sin(ty), cos(ty));

        // DataStoreWrite: '<S31>/Data Store Write9' incorporates:
        //   Constant: '<S54>/Constant'

        STQMEKF_DW.RED_Desired_States[0] = STQMEKF_P.init_states_RED[0];
        STQMEKF_DW.RED_Desired_States[1] = STQMEKF_P.init_states_RED[1];
        STQMEKF_DW.RED_Desired_States[2] = STQMEKF_P.init_states_RED[2];

        // End of Outputs for SubSystem: '<S21>/Sub-Phase #3 '
      } else if ((STQMEKF_DW.Univ_Time < STQMEKF_P.Phase3_SubPhase4_End) &&
                 (STQMEKF_DW.Univ_Time >= STQMEKF_P.Phase3_SubPhase3_End)) {
        // Outputs for IfAction SubSystem: '<S21>/Sub-Phase #4' incorporates:
        //   ActionPort: '<S32>/Action Port'

        // DataStoreWrite: '<S32>/Data Store Write24' incorporates:
        //   Constant: '<S32>/Constant11'

        STQMEKF_DW.RED_Path_Planner_Selection = STQMEKF_P.Constant11_Value_p;

        // DataStoreWrite: '<S32>/Data Store Write23' incorporates:
        //   Constant: '<S32>/Constant14'

        STQMEKF_DW.BLACK_Path_Planner_Selection = STQMEKF_P.Constant14_Value_f2;

        // DataStoreWrite: '<S32>/Data Store Write2' incorporates:
        //   Constant: '<S32>/Constant18'

        STQMEKF_DW.ARM_Control_Law_Enabler = STQMEKF_P.Constant18_Value_e;

        // DataStoreWrite: '<S32>/Data Store Write4' incorporates:
        //   Constant: '<S32>/Constant4'

        STQMEKF_DW.BLACK_Control_Law_Enabler = STQMEKF_P.Constant4_Value_l;

        // DataStoreWrite: '<S32>/Data Store Write3' incorporates:
        //   Constant: '<S32>/Constant5'

        STQMEKF_DW.RED_Control_Law_Enabler = STQMEKF_P.Constant5_Value_p;

        // DataStoreWrite: '<S32>/Data Store Write7' incorporates:
        //   Constant: '<S32>/Constant6'

        STQMEKF_DW.Float_State = STQMEKF_P.Constant6_Value_m;

        // DataStoreWrite: '<S32>/Data Store Write16' incorporates:
        //   Constant: '<S32>/Constant8'

        STQMEKF_DW.BLUE_Control_Law_Enabler = STQMEKF_P.Constant8_Value_j;

        // DataStoreWrite: '<S32>/Data Store Write13' incorporates:
        //   Constant: '<S64>/Constant1'
        //   Constant: '<S64>/Constant2'
        //   Constant: '<S64>/Constant3'

        STQMEKF_DW.ARM_Desired_States[0] = STQMEKF_P.Constant3_Value_k;
        STQMEKF_DW.ARM_Desired_States[1] = STQMEKF_P.Constant1_Value_b;
        STQMEKF_DW.ARM_Desired_States[2] = STQMEKF_P.Constant2_Value_g;

        // Product: '<S66>/Product' incorporates:
        //   Constant: '<S66>/Desired Rate '
        //   Constant: '<S69>/Constant2'
        //   DataStoreRead: '<S71>/Universal_Time'
        //   Sum: '<S69>/Subtract3'

        BLUE_Path_Planner_Selection = (STQMEKF_DW.Univ_Time -
          STQMEKF_P.Phase2_End) * STQMEKF_P.DesiredRate_Value_ha;

        // Trigonometry: '<S68>/Sin' incorporates:
        //   Trigonometry: '<S70>/Sin'

        rtb_TSamp_jb = sin(BLUE_Path_Planner_Selection);

        // Trigonometry: '<S68>/Cos' incorporates:
        //   Trigonometry: '<S70>/Cos'

        BLUE_Path_Planner_Selection = cos(BLUE_Path_Planner_Selection);

        // DataStoreWrite: '<S32>/Data Store Write18' incorporates:
        //   Constant: '<S68>/Constant1'
        //   Constant: '<S68>/Constant2'
        //   Gain: '<S68>/Gain'
        //   Gain: '<S68>/Gain1'
        //   Sum: '<S68>/Sum1'
        //   Sum: '<S68>/Sum2'
        //   Trigonometry: '<S68>/Cos'
        //   Trigonometry: '<S68>/Sin'
        //   Trigonometry: '<S70>/Atan2'

        STQMEKF_DW.BLUE_Desired_States[0] = STQMEKF_P.Gain_Gain_o *
          BLUE_Path_Planner_Selection + STQMEKF_P.xLength / 2.0;
        STQMEKF_DW.BLUE_Desired_States[1] = STQMEKF_P.Gain1_Gain_b *
          rtb_TSamp_jb + STQMEKF_P.yLength / 2.0;
        STQMEKF_DW.BLUE_Desired_States[2] = rt_atan2d_snf(rtb_TSamp_jb,
          BLUE_Path_Planner_Selection);

        // DataStoreWrite: '<S32>/Data Store Write5' incorporates:
        //   Constant: '<S65>/Constant'

        STQMEKF_DW.BLACK_Desired_States[0] = STQMEKF_P.home_states_BLACK[0];

        // DataStoreWrite: '<S32>/Data Store Write9' incorporates:
        //   Constant: '<S67>/Constant'

        STQMEKF_DW.RED_Desired_States[0] = STQMEKF_P.home_states_RED[0];

        // DataStoreWrite: '<S32>/Data Store Write5' incorporates:
        //   Constant: '<S65>/Constant'

        STQMEKF_DW.BLACK_Desired_States[1] = STQMEKF_P.home_states_BLACK[1];

        // DataStoreWrite: '<S32>/Data Store Write9' incorporates:
        //   Constant: '<S67>/Constant'

        STQMEKF_DW.RED_Desired_States[1] = STQMEKF_P.home_states_RED[1];

        // DataStoreWrite: '<S32>/Data Store Write5' incorporates:
        //   Constant: '<S65>/Constant'

        STQMEKF_DW.BLACK_Desired_States[2] = STQMEKF_P.home_states_BLACK[2];

        // DataStoreWrite: '<S32>/Data Store Write9' incorporates:
        //   Constant: '<S67>/Constant'

        STQMEKF_DW.RED_Desired_States[2] = STQMEKF_P.home_states_RED[2];

        // End of Outputs for SubSystem: '<S21>/Sub-Phase #4'
      }

      // End of If: '<S21>/Experiment Sub-Phases'
      // End of Outputs for SubSystem: '<S1>/Phase #3: Experiment'
    } else if ((STQMEKF_DW.Univ_Time < STQMEKF_P.Phase4_End) &&
               (STQMEKF_DW.Univ_Time >= STQMEKF_P.Phase3_End)) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #4: Return Home' incorporates:
      //   ActionPort: '<S22>/Action Port'

      STQMEKF_Phase4ReturnHome(&STQMEKF_DW.ARM_Control_Law_Enabler,
        STQMEKF_DW.ARM_Desired_States, &rtb_TSamp_jb,
        &STQMEKF_DW.BLACK_Control_Law_Enabler, STQMEKF_DW.BLACK_Desired_States,
        &STQMEKF_DW.BLACK_Path_Planner_Selection,
        &STQMEKF_DW.BLUE_Control_Law_Enabler, STQMEKF_DW.BLUE_Desired_States,
        &BLUE_Path_Planner_Selection, &STQMEKF_DW.Float_State,
        &STQMEKF_DW.RED_Control_Law_Enabler, STQMEKF_DW.RED_Desired_States,
        &STQMEKF_DW.RED_Path_Planner_Selection, &STQMEKF_P.Phase4ReturnHome);

      // End of Outputs for SubSystem: '<S1>/Phase #4: Return Home'
    } else if ((STQMEKF_DW.Univ_Time < STQMEKF_P.Phase5_End) &&
               (STQMEKF_DW.Univ_Time >= STQMEKF_P.Phase4_End)) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #5: Hold Home' incorporates:
      //   ActionPort: '<S23>/Action Port'

      STQMEKF_Phase4ReturnHome(&STQMEKF_DW.ARM_Control_Law_Enabler,
        STQMEKF_DW.ARM_Desired_States, &rtb_TSamp_jb,
        &STQMEKF_DW.BLACK_Control_Law_Enabler, STQMEKF_DW.BLACK_Desired_States,
        &STQMEKF_DW.BLACK_Path_Planner_Selection,
        &STQMEKF_DW.BLUE_Control_Law_Enabler, STQMEKF_DW.BLUE_Desired_States,
        &BLUE_Path_Planner_Selection, &STQMEKF_DW.Float_State,
        &STQMEKF_DW.RED_Control_Law_Enabler, STQMEKF_DW.RED_Desired_States,
        &STQMEKF_DW.RED_Path_Planner_Selection, &STQMEKF_P.Phase5HoldHome);

      // End of Outputs for SubSystem: '<S1>/Phase #5: Hold Home'
    } else if (STQMEKF_DW.Univ_Time >= STQMEKF_P.Phase5_End) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #6: Clean Shutdown' incorporates:
      //   ActionPort: '<S24>/Action Port'

      // DataStoreWrite: '<S24>/Data Store Write2' incorporates:
      //   Constant: '<S24>/Constant1'

      STQMEKF_DW.BLACK_Control_Law_Enabler = STQMEKF_P.Constant1_Value_n;

      // DataStoreWrite: '<S24>/Data Store Write3' incorporates:
      //   Constant: '<S24>/Constant2'

      STQMEKF_DW.BLUE_Control_Law_Enabler = STQMEKF_P.Constant2_Value_a;

      // DataStoreWrite: '<S24>/Data Store Write7' incorporates:
      //   Constant: '<S24>/Constant3'

      STQMEKF_DW.RED_Path_Planner_Selection = STQMEKF_P.Constant3_Value_d;

      // DataStoreWrite: '<S24>/Data Store Write' incorporates:
      //   Constant: '<S24>/Constant5'

      STQMEKF_DW.RED_Control_Law_Enabler = STQMEKF_P.Constant5_Value_ph;

      // DataStoreWrite: '<S24>/Data Store Write6' incorporates:
      //   Constant: '<S24>/Constant6'

      STQMEKF_DW.BLACK_Path_Planner_Selection = STQMEKF_P.Constant6_Value_d;

      // DataStoreWrite: '<S24>/Data Store Write9' incorporates:
      //   Constant: '<S24>/Constant8'

      STQMEKF_DW.ARM_Control_Law_Enabler = STQMEKF_P.Constant8_Value_h;

      // DataStoreWrite: '<S24>/Data Store Write4' incorporates:
      //   Constant: '<S24>/Puck State'

      STQMEKF_DW.Float_State = STQMEKF_P.PuckState_Value;

      // End of Outputs for SubSystem: '<S1>/Phase #6: Clean Shutdown'
    }

    // End of If: '<S1>/Separate Phases'

    // If: '<S4>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
    //   DataStoreRead: '<S4>/Data Store Read'
    //   DataStoreRead: '<S4>/Data Store Read1'

    if ((STQMEKF_DW.WhoAmI == 2.0) && (STQMEKF_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S4>/Change BLACK Behavior' incorporates:
      //   ActionPort: '<S159>/Action Port'

      STQMEKF_ChangeBLACKBehavior(STQMEKF_M, &STQMEKF_DW.ChangeBLACKBehavior,
        &STQMEKF_P.ChangeBLACKBehavior);

      // End of Outputs for SubSystem: '<S4>/Change BLACK Behavior'
    }

    // End of If: '<S4>/This IF block determines whether or not to run the BLACK sim//exp' 

    // If: '<S4>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
    //   DataStoreRead: '<S4>/Data Store Read'
    //   DataStoreRead: '<S4>/Data Store Read1'

    if ((STQMEKF_DW.WhoAmI == 3.0) && (STQMEKF_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S4>/Change BLUE Behavior' incorporates:
      //   ActionPort: '<S160>/Action Port'

      STQMEKF_ChangeBLACKBehavior(STQMEKF_M, &STQMEKF_DW.ChangeBLUEBehavior,
        &STQMEKF_P.ChangeBLUEBehavior);

      // End of Outputs for SubSystem: '<S4>/Change BLUE Behavior'
    }

    // End of If: '<S4>/This IF block determines whether or not to run the BLUE sim//exp' 

    // If: '<S4>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   DataStoreRead: '<S4>/Data Store Read'
    //   DataStoreRead: '<S4>/Data Store Read1'

    if ((STQMEKF_DW.WhoAmI == 1.0) && (STQMEKF_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S4>/Change RED Behavior' incorporates:
      //   ActionPort: '<S161>/Action Port'

      STQMEKF_ChangeBLACKBehavior(STQMEKF_M, &STQMEKF_DW.ChangeREDBehavior,
        &STQMEKF_P.ChangeREDBehavior);

      // End of Outputs for SubSystem: '<S4>/Change RED Behavior'
    }

    // End of If: '<S4>/This IF block determines whether or not to run the RED sim//exp ' 

    // MATLAB Function: '<S217>/Rel 2 Global'
    //         %% Define input properties
    //  Call C-function implementing device output
    rtb_z_true_0 = rtb_z_true[0];
    tmp_4[0] = 0.0;
    tmp_4[3] = -rtb_TSamp;
    tmp_4[6] = rtb_z_true[2];
    tmp_4[1] = rtb_TSamp;
    tmp_4[4] = 0.0;
    tmp_4[7] = -rtb_z_true[1];
    tmp_4[2] = -rtb_z_true[2];
    tmp_4[5] = rtb_z_true[1];
    tmp_4[8] = 0.0;
    rtb_z_true_1[0] = rtb_z_true[0];
    rtb_TSamp_jb = rtb_MatrixConcatenate[0];
    tmp_5[0] = 0.0;
    tmp_5[3] = -rtb_MatrixConcatenate[3];
    tmp_5[6] = rtb_MatrixConcatenate[2];
    tmp_5[1] = rtb_MatrixConcatenate[3];
    tmp_5[4] = 0.0;
    tmp_5[7] = -rtb_MatrixConcatenate[1];
    tmp_5[2] = -rtb_MatrixConcatenate[2];
    tmp_5[5] = rtb_MatrixConcatenate[1];
    tmp_5[8] = 0.0;
    rtb_TSamp_e *= rtb_TSamp_e;
    rtb_MatrixConcatenate_0[0] = rtb_MatrixConcatenate[0];
    for (b_k = 0; b_k < 3; b_k++) {
      BLUE_Path_Planner_Selection = axis[b_k];
      jj = (b_k + 1) << 2;
      rtb_z_true_1[jj] = -BLUE_Path_Planner_Selection;
      rtb_z_true_1[b_k + 1] = BLUE_Path_Planner_Selection;
      BLUE_Path_Planner_Selection = b_vector[b_k];
      rtb_MatrixConcatenate_0[jj] = -BLUE_Path_Planner_Selection;
      rtb_MatrixConcatenate_0[b_k + 1] = BLUE_Path_Planner_Selection;
      i = q_tmp[3 * b_k];
      rtb_z_true_1[jj + 1] = rtb_z_true_0 * static_cast<real_T>(i) + tmp_4[3 *
        b_k];
      rtb_MatrixConcatenate_0[jj + 1] = rtb_TSamp_jb * static_cast<real_T>(i) +
        tmp_5[3 * b_k];
      V_tmp = 3 * b_k + 1;
      i = q_tmp[V_tmp];
      rtb_z_true_1[jj + 2] = rtb_z_true_0 * static_cast<real_T>(i) + tmp_4[V_tmp];
      rtb_MatrixConcatenate_0[jj + 2] = rtb_TSamp_jb * static_cast<real_T>(i) +
        tmp_5[V_tmp];
      V_tmp = 3 * b_k + 2;
      i = q_tmp[V_tmp];
      rtb_z_true_1[jj + 3] = rtb_z_true_0 * static_cast<real_T>(i) + tmp_4[V_tmp];
      rtb_MatrixConcatenate_0[jj + 3] = rtb_TSamp_jb * static_cast<real_T>(i) +
        tmp_5[V_tmp];
    }

    rtb_TSamp_jb = rtb_z_true[0] / rtb_TSamp_e;
    BLUE_Path_Planner_Selection = rtb_z_true[1] / rtb_TSamp_e;
    rtb_z_true_0 = rtb_z_true[2] / rtb_TSamp_e;
    rtb_TSamp /= rtb_TSamp_e;
    rtb_TSamp_e = rtb_Delay1[1];
    dyds = rtb_Delay1[0];
    u_loop = rtb_Delay1[2];
    dxds = rtb_Delay1[3];
    for (b_k = 0; b_k < 4; b_k++) {
      rtb_Delay1_0[b_k] = ((rtb_z_true_1[b_k + 4] * rtb_TSamp_e +
                            rtb_z_true_1[b_k] * dyds) + rtb_z_true_1[b_k + 8] *
                           u_loop) + rtb_z_true_1[b_k + 12] * dxds;
      rtb_MatrixConcatenate[b_k] = ((rtb_MatrixConcatenate_0[b_k + 4] *
        BLUE_Path_Planner_Selection + rtb_MatrixConcatenate_0[b_k] *
        rtb_TSamp_jb) + rtb_MatrixConcatenate_0[b_k + 8] * rtb_z_true_0) +
        rtb_MatrixConcatenate_0[b_k + 12] * rtb_TSamp;
    }

    // MATLAB Function: '<S216>/Nis'
    rtb_TSamp = 0.0;
    for (b_k = 0; b_k < 6; b_k++) {
      rtb_TSamp_e = 0.0;
      for (jj = 0; jj < 6; jj++) {
        rtb_TSamp_e += x[6 * b_k + jj] * rtb_y[jj];
      }

      rtb_TSamp += rtb_TSamp_e * rtb_y[b_k];
    }

    // MATLABSystem: '<S162>/MATLAB System' incorporates:
    //   DataStoreRead: '<S5>/Data Store Read'
    //   DataStoreRead: '<S5>/Data Store Read1'
    //   DataStoreRead: '<S5>/Data Store Read10'
    //   DataStoreRead: '<S5>/Data Store Read11'
    //   DataStoreRead: '<S5>/Data Store Read12'
    //   DataStoreRead: '<S5>/Data Store Read13'
    //   DataStoreRead: '<S5>/Data Store Read14'
    //   DataStoreRead: '<S5>/Data Store Read15'
    //   DataStoreRead: '<S5>/Data Store Read16'
    //   DataStoreRead: '<S5>/Data Store Read17'
    //   DataStoreRead: '<S5>/Data Store Read18'
    //   DataStoreRead: '<S5>/Data Store Read19'
    //   DataStoreRead: '<S5>/Data Store Read2'
    //   DataStoreRead: '<S5>/Data Store Read20'
    //   DataStoreRead: '<S5>/Data Store Read22'
    //   DataStoreRead: '<S5>/Data Store Read23'
    //   DataStoreRead: '<S5>/Data Store Read26'
    //   DataStoreRead: '<S5>/Data Store Read28'
    //   DataStoreRead: '<S5>/Data Store Read29'
    //   DataStoreRead: '<S5>/Data Store Read3'
    //   DataStoreRead: '<S5>/Data Store Read30'
    //   DataStoreRead: '<S5>/Data Store Read36'
    //   DataStoreRead: '<S5>/Data Store Read37'
    //   DataStoreRead: '<S5>/Data Store Read4'
    //   DataStoreRead: '<S5>/Data Store Read5'
    //   DataStoreRead: '<S5>/Data Store Read59'
    //   DataStoreRead: '<S5>/Data Store Read6'
    //   DataStoreRead: '<S5>/Data Store Read60'
    //   DataStoreRead: '<S5>/Data Store Read7'
    //   DataStoreRead: '<S5>/Data Store Read8'
    //   DataStoreRead: '<S5>/Data Store Read82'
    //   DataStoreRead: '<S5>/Data Store Read83'
    //   DataStoreRead: '<S5>/Data Store Read84'
    //   DataStoreRead: '<S5>/Data Store Read85'
    //   DataStoreRead: '<S5>/Data Store Read86'
    //   DataStoreRead: '<S5>/Data Store Read9'
    //   DataStoreWrite: '<S217>/Measured States for BLACK1'
    //   DataStoreWrite: '<S3>/Data Store Write9'
    //   MATLAB Function: '<S162>/MATLAB Function'
    //   MATLAB Function: '<S216>/Nis'
    //   MATLAB Function: '<S217>/Rel 2 Global'
    //   SignalConversion generated from: '<S162>/MATLAB System'

    b_u1[0] = STQMEKF_DW.Univ_Time;
    b_u1[1] = RED_Controls[0];
    b_u1[4] = STQMEKF_DW.RED_Saturated_Controls[0];
    b_u1[2] = RED_Controls[1];
    b_u1[5] = STQMEKF_DW.RED_Saturated_Controls[1];
    b_u1[3] = RED_Controls[2];
    b_u1[6] = STQMEKF_DW.RED_Saturated_Controls[2];
    memcpy(&b_u1[7], &STQMEKF_DW.RED_Measured_States[0], 9U * sizeof(real_T));
    b_u1[22] = STQMEKF_DW.RED_Thruster_ON_Count;
    b_u1[23] = STQMEKF_DW.RED_Control_Law_Enabler;
    b_u1[27] = STQMEKF_DW.ARM_Control_Mode;
    b_u1[16] = STQMEKF_DW.RED_Desired_States[0];
    b_u1[19] = STQMEKF_DW.RED_IMU_Measurements[0];
    b_u1[24] = RED_Path[0];
    b_u1[28] = rtb_Merge6[0];
    b_u1[17] = STQMEKF_DW.RED_Desired_States[1];
    b_u1[20] = STQMEKF_DW.RED_IMU_Measurements[1];
    b_u1[25] = RED_Path[1];
    b_u1[29] = rtb_Merge6[1];
    b_u1[18] = STQMEKF_DW.RED_Desired_States[2];
    b_u1[21] = STQMEKF_DW.RED_IMU_Measurements[2];
    b_u1[26] = RED_Path[2];
    b_u1[30] = rtb_Merge6[2];
    for (b_k = 0; b_k < 6; b_k++) {
      b_u1[b_k + 31] = STQMEKF_DW.ARM_Measured_States[b_k];
    }

    b_u1[37] = ARM_Path_idx_0;
    b_u1[40] = STQMEKF_DW.ARM_Desired_States[0];
    b_u1[43] = BLACK_Controls[0];
    b_u1[46] = STQMEKF_DW.BLACK_Saturated_Controls[0];
    b_u1[38] = ARM_Path_idx_1;
    b_u1[41] = STQMEKF_DW.ARM_Desired_States[1];
    b_u1[44] = BLACK_Controls[1];
    b_u1[47] = STQMEKF_DW.BLACK_Saturated_Controls[1];
    b_u1[39] = ARM_Path_idx_2;
    b_u1[42] = STQMEKF_DW.ARM_Desired_States[2];
    b_u1[45] = BLACK_Controls[2];
    b_u1[48] = STQMEKF_DW.BLACK_Saturated_Controls[2];
    b_u1[64] = STQMEKF_DW.BLACK_Thruster_ON_Count;
    b_u1[65] = STQMEKF_DW.BLACK_Control_Law_Enabler;
    b_u1[58] = STQMEKF_DW.BLACK_Desired_States[0];
    b_u1[61] = STQMEKF_DW.BLACK_IMU_Measurements[0];
    b_u1[66] = BLACK_Path[0];
    b_u1[69] = rtb_TSamp_af;
    b_u1[72] = STQMEKF_DW.BLUE_Saturated_Controls[0];
    b_u1[59] = STQMEKF_DW.BLACK_Desired_States[1];
    b_u1[62] = STQMEKF_DW.BLACK_IMU_Measurements[1];
    b_u1[67] = BLACK_Path[1];
    b_u1[70] = rtb_TSamp_o;
    b_u1[73] = STQMEKF_DW.BLUE_Saturated_Controls[1];
    b_u1[60] = STQMEKF_DW.BLACK_Desired_States[2];
    b_u1[63] = STQMEKF_DW.BLACK_IMU_Measurements[2];
    b_u1[68] = BLACK_Path[2];
    b_u1[71] = rtb_TSamp_k;
    b_u1[74] = STQMEKF_DW.BLUE_Saturated_Controls[2];
    for (b_k = 0; b_k < 9; b_k++) {
      b_u1[b_k + 49] = STQMEKF_DW.BLACK_Measured_States[b_k];
      b_u1[b_k + 75] = STQMEKF_DW.BLUE_Measured_States[b_k];
    }

    b_u1[90] = STQMEKF_DW.BLUE_Thruster_ON_Count;
    b_u1[91] = STQMEKF_DW.BLUE_Control_Law_Enabler;
    b_u1[84] = STQMEKF_DW.BLUE_Desired_States[0];
    b_u1[87] = STQMEKF_DW.BLUE_IMU_Measurements[0];
    b_u1[92] = BLUE_Path_idx_0;
    b_u1[85] = STQMEKF_DW.BLUE_Desired_States[1];
    b_u1[88] = STQMEKF_DW.BLUE_IMU_Measurements[1];
    b_u1[93] = BLUE_Path_idx_1;
    b_u1[86] = STQMEKF_DW.BLUE_Desired_States[2];
    b_u1[89] = STQMEKF_DW.BLUE_IMU_Measurements[2];
    b_u1[94] = BLUE_Path_idx_2;
    b_u1[95] = STQMEKF_DW.Float_State;
    b_u1[96] = STQMEKF_DW.WhoAmI;
    b_u1[97] = STQMEKF_DW.isSim;
    b_u1[105] = rtb_Delay1_0[0];
    b_u1[106] = rtb_Delay1_0[1];
    b_u1[107] = rtb_Delay1_0[2];
    b_u1[108] = rtb_Delay1_0[3];
    b_u1[109] = rtb_MatrixConcatenate[1] + rtb_z_true[4];
    b_u1[110] = rtb_MatrixConcatenate[2] + rtb_z_true[5];
    b_u1[111] = rtb_MatrixConcatenate[3];
    for (b_k = 0; b_k < 7; b_k++) {
      b_u1[b_k + 98] = STQMEKF_DW.BLACK_States_Vis_raw[b_k];
      b_u1[b_k + 112] = rtb_z_true[b_k];
    }

    b_u1[119] = rtb_TSamp_n5;
    memcpy(&b_u1[120], &BLACK_KF_States[0], 13U * sizeof(real_T));
    b_u1[133] = rtb_TSamp;
    b_u1[134] = STQMEKF_DW.Confidance;
    appendDataToFile(&b_u1[0], 135.0);

    // End of MATLABSystem: '<S162>/MATLAB System'

    // If: '<S6>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read'
    //   DataStoreRead: '<S6>/Data Store Read1'

    if ((STQMEKF_DW.WhoAmI == 2.0) && (STQMEKF_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S6>/Change BLACK Behavior' incorporates:
      //   ActionPort: '<S164>/Action Port'

      // StringToASCII: '<S164>/String to ASCII1' incorporates:
      //   StringConstant: '<S164>/String Constant1'

      strncpy((char_T *)&STQMEKF_B.StringtoASCII1[0],
              &STQMEKF_P.StringConstant1_String[0], 31U);

      // Update for S-Function (sdspToNetwork): '<S164>/UDP Send1' incorporates:
      //   StringToASCII: '<S164>/String to ASCII1'
      //
      sErr = GetErrorBuffer(&STQMEKF_DW.UDPSend1_NetworkLib[0U]);
      LibUpdate_Network(&STQMEKF_DW.UDPSend1_NetworkLib[0U],
                        &STQMEKF_B.StringtoASCII1[0U], 31);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }

      // End of Update for S-Function (sdspToNetwork): '<S164>/UDP Send1'
      // End of Outputs for SubSystem: '<S6>/Change BLACK Behavior'
    }

    // End of If: '<S6>/This IF block determines whether or not to run the BLACK sim//exp' 

    // If: '<S6>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read'
    //   DataStoreRead: '<S6>/Data Store Read1'

    if ((STQMEKF_DW.WhoAmI == 3.0) && (STQMEKF_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S6>/Change BLUE Behavior' incorporates:
      //   ActionPort: '<S165>/Action Port'

      // StringToASCII: '<S165>/String to ASCII2' incorporates:
      //   StringConstant: '<S165>/String Constant2'

      strncpy((char_T *)&STQMEKF_B.StringtoASCII2[0],
              &STQMEKF_P.StringConstant2_String[0], 31U);

      // Update for S-Function (sdspToNetwork): '<S165>/UDP Send2' incorporates:
      //   StringToASCII: '<S165>/String to ASCII2'
      //
      sErr = GetErrorBuffer(&STQMEKF_DW.UDPSend2_NetworkLib[0U]);
      LibUpdate_Network(&STQMEKF_DW.UDPSend2_NetworkLib[0U],
                        &STQMEKF_B.StringtoASCII2[0U], 31);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }

      // End of Update for S-Function (sdspToNetwork): '<S165>/UDP Send2'
      // End of Outputs for SubSystem: '<S6>/Change BLUE Behavior'
    }

    // End of If: '<S6>/This IF block determines whether or not to run the BLUE sim//exp' 

    // If: '<S6>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read'
    //   DataStoreRead: '<S6>/Data Store Read1'

    if ((STQMEKF_DW.WhoAmI == 1.0) && (STQMEKF_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S6>/Change RED Behavior' incorporates:
      //   ActionPort: '<S166>/Action Port'

      // StringToASCII: '<S166>/String to ASCII' incorporates:
      //   DataStoreRead: '<S166>/Data Store Read'

      strncpy((char_T *)&STQMEKF_B.StringtoASCII[0], &STQMEKF_DW.RED_Logger[0],
              31U);

      // Update for S-Function (sdspToNetwork): '<S166>/UDP Send3' incorporates:
      //   StringToASCII: '<S166>/String to ASCII'
      //
      sErr = GetErrorBuffer(&STQMEKF_DW.UDPSend3_NetworkLib[0U]);
      LibUpdate_Network(&STQMEKF_DW.UDPSend3_NetworkLib[0U],
                        &STQMEKF_B.StringtoASCII[0U], 31);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }

      // End of Update for S-Function (sdspToNetwork): '<S166>/UDP Send3'
      // End of Outputs for SubSystem: '<S6>/Change RED Behavior'
    }

    // End of If: '<S6>/This IF block determines whether or not to run the RED sim//exp ' 

    // If: '<S7>/This IF block determines whether or not to run the exp code' incorporates:
    //   DataStoreRead: '<S7>/Data Store Read'
    //   If: '<S8>/This IF block determines whether or not to run the exp code'

    if (STQMEKF_DW.isSim == 0.0) {
      // Outputs for IfAction SubSystem: '<S7>/Enable Pucks' incorporates:
      //   ActionPort: '<S167>/Action Port'

      // MATLABSystem: '<S167>/GPIO Write1' incorporates:
      //   DataStoreRead: '<S167>/Data Store Read1'

      if (STQMEKF_DW.obj_c.gpioPin != STQMEKF_P.GPIOWrite1_gpioPin) {
        STQMEKF_DW.obj_c.gpioPin = STQMEKF_P.GPIOWrite1_gpioPin;
      }

      if (STQMEKF_DW.obj_c.pinDirection != STQMEKF_P.GPIOWrite1_pinDirection) {
        STQMEKF_DW.obj_c.pinDirection = STQMEKF_P.GPIOWrite1_pinDirection;
      }

      //         %% Define input properties
      //  Call C-function implementing device output
      // coder.ceval('export_gpio', obj.gpioPin);
      set_pin_direction(STQMEKF_DW.obj_c.gpioPin, STQMEKF_DW.obj_c.pinDirection);
      change_gpio_value(STQMEKF_DW.obj_c.gpioPin, STQMEKF_DW.Float_State);

      // End of MATLABSystem: '<S167>/GPIO Write1'
      // End of Outputs for SubSystem: '<S7>/Enable Pucks'

      // Outputs for IfAction SubSystem: '<S8>/Log Gyro//Accel' incorporates:
      //   ActionPort: '<S168>/Action Port'

      // MATLABSystem: '<S168>/Gyroscope//Accelerometer'
      if (STQMEKF_DW.obj.SampleTime != STQMEKF_P.GyroscopeAccelerometer_SampleTi)
      {
        STQMEKF_DW.obj.SampleTime = STQMEKF_P.GyroscopeAccelerometer_SampleTi;
      }

      if (STQMEKF_DW.obj.TunablePropsChanged) {
        STQMEKF_DW.obj.TunablePropsChanged = false;
      }

      obj = STQMEKF_DW.obj.SensorObject->Device;
      obj_0 = obj->Device.InterfaceObj;
      slaveAddress = obj->Device.DeviceAddress;
      for (i = 0; i < 6; i++) {
        b_output[i] = 0U;
      }

      b_status = 18U;
      b_status = MW_I2C_MasterWrite(obj_0->MW_I2C_HANDLE, slaveAddress,
        &b_status, 1U, true, false);
      if (b_status == 0) {
        MW_I2C_MasterRead(obj_0->MW_I2C_HANDLE, slaveAddress, &b_output[0], 6U,
                          false, true);
      }

      obj = STQMEKF_DW.obj.SensorObject->Device;
      obj_0 = obj->Device.InterfaceObj;
      slaveAddress = obj->Device.DeviceAddress;
      for (i = 0; i < 6; i++) {
        b_output_0[i] = 0U;
      }

      b_status = 12U;
      b_status = MW_I2C_MasterWrite(obj_0->MW_I2C_HANDLE, slaveAddress,
        &b_status, 1U, true, false);
      if (b_status == 0) {
        MW_I2C_MasterRead(obj_0->MW_I2C_HANDLE, slaveAddress, &b_output_0[0], 6U,
                          false, true);
      }

      ARM_Path_idx_0 = static_cast<real_T>(static_cast<int16_T>
        (static_cast<int16_T>(b_output[1] << 8) | b_output[0])) * 6.103515625E-5
        * 9.81;
      ARM_Path_idx_1 = static_cast<real_T>(static_cast<int16_T>
        (static_cast<int16_T>(b_output[3] << 8) | b_output[2])) * 6.103515625E-5
        * 9.81;
      BLACK_Path[2] = static_cast<real_T>(static_cast<int16_T>
        (static_cast<int16_T>(b_output_0[5] << 8) | b_output_0[4])) *
        6.6512957317073178E-5;

      // End of MATLABSystem: '<S168>/Gyroscope//Accelerometer'

      // MATLAB Function: '<S168>/Parse IMU Data' incorporates:
      //   DataStoreRead: '<S168>/Data Store Read'

      if (STQMEKF_DW.WhoAmI == 1.0) {
        // DataStoreWrite: '<S168>/Data Store Write9'
        STQMEKF_DW.RED_IMU_Measurements[0] = ARM_Path_idx_0;
        STQMEKF_DW.RED_IMU_Measurements[1] = ARM_Path_idx_1;
        STQMEKF_DW.RED_IMU_Measurements[2] = BLACK_Path[2];

        // DataStoreWrite: '<S168>/Data Store Write10'
        STQMEKF_DW.BLACK_IMU_Measurements[0] = 0.0;
        STQMEKF_DW.BLACK_IMU_Measurements[1] = 0.0;
        STQMEKF_DW.BLACK_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S168>/Data Store Write11'
        STQMEKF_DW.BLUE_IMU_Measurements[0] = 0.0;
        STQMEKF_DW.BLUE_IMU_Measurements[1] = 0.0;
        STQMEKF_DW.BLUE_IMU_Measurements[2] = 0.0;
      } else if (STQMEKF_DW.WhoAmI == 2.0) {
        // DataStoreWrite: '<S168>/Data Store Write9'
        STQMEKF_DW.RED_IMU_Measurements[0] = 0.0;
        STQMEKF_DW.RED_IMU_Measurements[1] = 0.0;
        STQMEKF_DW.RED_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S168>/Data Store Write10'
        STQMEKF_DW.BLACK_IMU_Measurements[0] = ARM_Path_idx_0;
        STQMEKF_DW.BLACK_IMU_Measurements[1] = ARM_Path_idx_1;
        STQMEKF_DW.BLACK_IMU_Measurements[2] = BLACK_Path[2];

        // DataStoreWrite: '<S168>/Data Store Write11'
        STQMEKF_DW.BLUE_IMU_Measurements[0] = 0.0;
        STQMEKF_DW.BLUE_IMU_Measurements[1] = 0.0;
        STQMEKF_DW.BLUE_IMU_Measurements[2] = 0.0;
      } else if (STQMEKF_DW.WhoAmI == 3.0) {
        // DataStoreWrite: '<S168>/Data Store Write9'
        STQMEKF_DW.RED_IMU_Measurements[0] = 0.0;
        STQMEKF_DW.RED_IMU_Measurements[1] = 0.0;
        STQMEKF_DW.RED_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S168>/Data Store Write10'
        STQMEKF_DW.BLACK_IMU_Measurements[0] = 0.0;
        STQMEKF_DW.BLACK_IMU_Measurements[1] = 0.0;
        STQMEKF_DW.BLACK_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S168>/Data Store Write11'
        STQMEKF_DW.BLUE_IMU_Measurements[0] = ARM_Path_idx_0;
        STQMEKF_DW.BLUE_IMU_Measurements[1] = ARM_Path_idx_1;
        STQMEKF_DW.BLUE_IMU_Measurements[2] = BLACK_Path[2];
      } else {
        // DataStoreWrite: '<S168>/Data Store Write9'
        STQMEKF_DW.RED_IMU_Measurements[0] = 0.0;
        STQMEKF_DW.RED_IMU_Measurements[1] = 0.0;
        STQMEKF_DW.RED_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S168>/Data Store Write10'
        STQMEKF_DW.BLACK_IMU_Measurements[0] = 0.0;
        STQMEKF_DW.BLACK_IMU_Measurements[1] = 0.0;
        STQMEKF_DW.BLACK_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S168>/Data Store Write11'
        STQMEKF_DW.BLUE_IMU_Measurements[0] = 0.0;
        STQMEKF_DW.BLUE_IMU_Measurements[1] = 0.0;
        STQMEKF_DW.BLUE_IMU_Measurements[2] = 0.0;
      }

      // End of MATLAB Function: '<S168>/Parse IMU Data'
      // End of Outputs for SubSystem: '<S8>/Log Gyro//Accel'
    }

    // End of If: '<S7>/This IF block determines whether or not to run the exp code' 

    // If: '<S9>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   DataStoreRead: '<S9>/Data Store Read1'
    //   DataStoreRead: '<S9>/Data Store Read2'

    if ((STQMEKF_DW.WhoAmI == 1.0) && (STQMEKF_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S9>/Change ARM Behavior' incorporates:
      //   ActionPort: '<S170>/Action Port'

      // MATLABSystem: '<S170>/Read Joint Positions using  Dynamixel Encoders'
      if (STQMEKF_DW.obj_d.SampleTime != STQMEKF_P.baseRate) {
        if (((!rtIsInf(STQMEKF_P.baseRate)) && (!rtIsNaN(STQMEKF_P.baseRate))) ||
            rtIsInf(STQMEKF_P.baseRate)) {
          sampleTime = STQMEKF_P.baseRate;
        }

        STQMEKF_DW.obj_d.SampleTime = sampleTime;
      }

      //         %% Define input properties
      //         %% Define output properties
      ARM_Path_idx_2 = 0.0;
      ARM_Path_idx_0 = 0.0;
      ARM_Path_idx_1 = 0.0;

      // DataStoreWrite: '<S170>/Data Store Write' incorporates:
      //   Delay: '<S170>/Delay'
      //   Delay: '<S170>/Delay1'
      //   Delay: '<S170>/Delay2'
      //   MATLABSystem: '<S170>/Read Joint Positions using  Dynamixel Encoders'

      STQMEKF_DW.ARM_Measured_States[3] = 0.0;
      STQMEKF_DW.ARM_Measured_States[4] = 0.0;
      STQMEKF_DW.ARM_Measured_States[5] = 0.0;
      read_dynamixel_position(&ARM_Path_idx_2, &ARM_Path_idx_0, &ARM_Path_idx_1,
        &STQMEKF_DW.ARM_Measured_States[3], &STQMEKF_DW.ARM_Measured_States[4],
        &STQMEKF_DW.ARM_Measured_States[5], STQMEKF_DW.Delay_DSTATE_o,
        STQMEKF_DW.Delay1_DSTATE_cg, STQMEKF_DW.Delay2_DSTATE_h);

      // MATLABSystem: '<S170>/Read Joint Positions using  Dynamixel Encoders' incorporates:
      //   Delay: '<S170>/Delay'
      //   Delay: '<S170>/Delay1'
      //   Delay: '<S170>/Delay2'

      STQMEKF_DW.Delay_DSTATE_o = ARM_Path_idx_2;
      STQMEKF_DW.Delay1_DSTATE_cg = ARM_Path_idx_0;
      STQMEKF_DW.Delay2_DSTATE_h = ARM_Path_idx_1;

      // DataStoreWrite: '<S170>/Data Store Write' incorporates:
      //   Delay: '<S170>/Delay'
      //   Delay: '<S170>/Delay1'
      //   Delay: '<S170>/Delay2'

      STQMEKF_DW.ARM_Measured_States[0] = STQMEKF_DW.Delay_DSTATE_o;
      STQMEKF_DW.ARM_Measured_States[1] = STQMEKF_DW.Delay1_DSTATE_cg;
      STQMEKF_DW.ARM_Measured_States[2] = STQMEKF_DW.Delay2_DSTATE_h;

      // End of Outputs for SubSystem: '<S9>/Change ARM Behavior'
    }

    // End of If: '<S9>/This IF block determines whether or not to run the RED sim//exp ' 

    // If: '<S10>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' incorporates:
    //   Constant: '<S177>/Constant'
    //   Constant: '<S182>/Constant3'
    //   Constant: '<S192>/Constant3'
    //   Constant: '<S202>/Constant3'
    //   DataStoreRead: '<S10>/Data Store Read2'
    //   Delay: '<S182>/Delay1'
    //   Delay: '<S192>/Delay1'
    //   Delay: '<S202>/Delay1'
    //   RelationalOperator: '<S177>/Relational Operator'
    //   RelationalOperator: '<S182>/Relational Operator'
    //   RelationalOperator: '<S183>/Relational Operator'
    //   RelationalOperator: '<S192>/Relational Operator'
    //   RelationalOperator: '<S193>/Relational Operator'
    //   RelationalOperator: '<S202>/Relational Operator'
    //   RelationalOperator: '<S203>/Relational Operator'
    //   SignalConversion generated from: '<S188>/Enable'
    //   SignalConversion generated from: '<S190>/Enable'
    //   SignalConversion generated from: '<S198>/Enable'
    //   SignalConversion generated from: '<S200>/Enable'
    //   SignalConversion generated from: '<S208>/Enable'
    //   SignalConversion generated from: '<S210>/Enable'
    //   Sum: '<S182>/Subtract2'
    //   Sum: '<S192>/Subtract2'
    //   Sum: '<S202>/Subtract2'

    rtPrevAction = STQMEKF_DW.Ifperforminganexperimentgrabthe;
    rtAction = -1;
    if (STQMEKF_DW.isSim == 0.0) {
      rtAction = 0;
    } else if (STQMEKF_DW.isSim == 1.0) {
      rtAction = 1;
    }

    STQMEKF_DW.Ifperforminganexperimentgrabthe = rtAction;
    if (rtPrevAction != rtAction) {
      rtsiSetBlockStateForSolverChangedAtMajorStep(&STQMEKF_M->solverInfo, true);
      if (rtPrevAction == 0) {
        // Disable for Enabled SubSystem: '<S184>/Enabled Subsystem'
        if (STQMEKF_DW.EnabledSubsystem_n.EnabledSubsystem_MODE) {
          STQM_EnabledSubsystem_l_Disable(&STQMEKF_DW.EnabledSubsystem_n);
        }

        // End of Disable for SubSystem: '<S184>/Enabled Subsystem'

        // Disable for Enabled SubSystem: '<S183>/Enabled Subsystem'
        if (STQMEKF_DW.EnabledSubsystem_m.EnabledSubsystem_MODE) {
          STQMEK_EnabledSubsystem_Disable(&STQMEKF_DW.EnabledSubsystem_m);
        }

        // End of Disable for SubSystem: '<S183>/Enabled Subsystem'

        // Disable for Enabled SubSystem: '<S194>/Enabled Subsystem'
        if (STQMEKF_DW.EnabledSubsystem_g.EnabledSubsystem_MODE) {
          STQM_EnabledSubsystem_l_Disable(&STQMEKF_DW.EnabledSubsystem_g);
        }

        // End of Disable for SubSystem: '<S194>/Enabled Subsystem'

        // Disable for Enabled SubSystem: '<S193>/Enabled Subsystem'
        if (STQMEKF_DW.EnabledSubsystem_l.EnabledSubsystem_MODE) {
          STQMEK_EnabledSubsystem_Disable(&STQMEKF_DW.EnabledSubsystem_l);
        }

        // End of Disable for SubSystem: '<S193>/Enabled Subsystem'

        // Disable for Enabled SubSystem: '<S204>/Enabled Subsystem'
        if (STQMEKF_DW.EnabledSubsystem_a.EnabledSubsystem_MODE) {
          STQM_EnabledSubsystem_l_Disable(&STQMEKF_DW.EnabledSubsystem_a);
        }

        // End of Disable for SubSystem: '<S204>/Enabled Subsystem'

        // Disable for Enabled SubSystem: '<S203>/Enabled Subsystem'
        if (STQMEKF_DW.EnabledSubsystem_k.EnabledSubsystem_MODE) {
          STQMEK_EnabledSubsystem_Disable(&STQMEKF_DW.EnabledSubsystem_k);
        }

        // End of Disable for SubSystem: '<S203>/Enabled Subsystem'
      }
    }

    switch (rtAction) {
     case 0:
      // Outputs for IfAction SubSystem: '<S10>/Use Hardware to Obtain States' incorporates:
      //   ActionPort: '<S172>/Action Port'

      // S-Function (sdspFromNetwork): '<S173>/Receive PhaseSpace Data'
      sErr = GetErrorBuffer(&STQMEKF_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
      samplesRead = 19;
      LibOutputs_Network(&STQMEKF_DW.ReceivePhaseSpaceData_NetworkLi[0U],
                         &STQMEKF_B.ReceivePhaseSpaceData_o1[0U], &samplesRead);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }

      // End of S-Function (sdspFromNetwork): '<S173>/Receive PhaseSpace Data'

      // Gain: '<S174>/Convert BLAX from [mm] to [m]'
      STQMEKF_B.ConvertBLAXfrommmtom = STQMEKF_P.ConvertBLAXfrommmtom_Gain *
        STQMEKF_B.ReceivePhaseSpaceData_o1[4];

      // Gain: '<S174>/Convert BLAY from [mm] to [m]'
      ARM_Path_idx_0 = STQMEKF_P.ConvertBLAYfrommmtom_Gain *
        STQMEKF_B.ReceivePhaseSpaceData_o1[5];

      // Trigonometry: '<S185>/Sin'
      ARM_Path_idx_1 = sin(STQMEKF_B.ReceivePhaseSpaceData_o1[6]);

      // Trigonometry: '<S185>/Cos'
      ARM_Path_idx_2 = cos(STQMEKF_B.ReceivePhaseSpaceData_o1[6]);

      // DataStoreWrite: '<S174>/RED_Px7' incorporates:
      //   Gain: '<S174>/Convert BLACKVX from [mm] to [m]'
      //   Gain: '<S174>/Convert BLACKVY from [mm] to [m]'
      //   Trigonometry: '<S185>/Atan2'

      STQMEKF_DW.BLACK_Measured_States[2] = rt_atan2d_snf(ARM_Path_idx_1,
        ARM_Path_idx_2);
      STQMEKF_DW.BLACK_Measured_States[3] =
        STQMEKF_P.ConvertBLACKVXfrommmtom_Gain *
        STQMEKF_B.ReceivePhaseSpaceData_o1[13];
      STQMEKF_DW.BLACK_Measured_States[4] =
        STQMEKF_P.ConvertBLACKVYfrommmtom_Gain *
        STQMEKF_B.ReceivePhaseSpaceData_o1[14];

      // Sum: '<S182>/Subtract1' incorporates:
      //   Delay: '<S182>/Delay2'

      ARM_Path_idx_2 = STQMEKF_B.ReceivePhaseSpaceData_o1[0] -
        STQMEKF_DW.Delay2_DSTATE_j;

      // Outputs for Enabled SubSystem: '<S182>/Enabled Subsystem3' incorporates:
      //   EnablePort: '<S186>/Enable'

      if (STQMEKF_B.ConvertBLAXfrommmtom - STQMEKF_DW.Delay1_DSTATE_i !=
          STQMEKF_P.Constant3_Value_eq) {
        // SignalConversion generated from: '<S186>/y2-y1'
        STQMEKF_B.y2y1_ob = ARM_Path_idx_2;
      }

      // End of Outputs for SubSystem: '<S182>/Enabled Subsystem3'

      // MATLAB Function: '<S182>/MATLAB Function' incorporates:
      //   Constant: '<S182>/Constant'
      //   Constant: '<S182>/Constant3'
      //   Delay: '<S182>/Delay1'
      //   RelationalOperator: '<S182>/Relational Operator'
      //   Sum: '<S182>/Subtract2'

      STQMEKF_MATLABFunction_j(STQMEKF_B.y2y1_ob, STQMEKF_P.dataRate,
        &ARM_Path_idx_1);

      // Sum: '<S184>/Subtract1' incorporates:
      //   Delay: '<S184>/Delay1'

      ARM_Path_idx_2 = STQMEKF_B.ReceivePhaseSpaceData_o1[6] -
        STQMEKF_DW.Delay1_DSTATE_g[2];

      // RelationalOperator: '<S184>/Relational Operator' incorporates:
      //   Constant: '<S184>/Constant3'
      //   Delay: '<S184>/Delay1'
      //   Sum: '<S184>/Subtract1'

      RelationalOperator_i[0] = (STQMEKF_B.ConvertBLAXfrommmtom -
        STQMEKF_DW.Delay1_DSTATE_g[0] != STQMEKF_P.Constant3_Value_a);
      RelationalOperator_i[1] = (ARM_Path_idx_0 - STQMEKF_DW.Delay1_DSTATE_g[1]
        != STQMEKF_P.Constant3_Value_a);
      RelationalOperator_i[2] = (ARM_Path_idx_2 != STQMEKF_P.Constant3_Value_a);

      // Outputs for Enabled SubSystem: '<S184>/Enabled Subsystem'
      STQMEKF_EnabledSubsystem_n(RelationalOperator_i,
        STQMEKF_B.ConvertBLAXfrommmtom, ARM_Path_idx_0,
        STQMEKF_B.ReceivePhaseSpaceData_o1[6], ARM_Path_idx_1, STQMEKF_B.dy_i,
        &STQMEKF_B.EnabledSubsystem_n, &STQMEKF_DW.EnabledSubsystem_n,
        &STQMEKF_P.EnabledSubsystem_n);

      // End of Outputs for SubSystem: '<S184>/Enabled Subsystem'

      // RelationalOperator: '<S183>/Relational Operator' incorporates:
      //   Constant: '<S183>/Constant3'
      //   Delay: '<S183>/Delay1'
      //   SignalConversion generated from: '<S190>/Enable'
      //   Sum: '<S183>/Subtract1'

      RelationalOperator_i[0] = (STQMEKF_B.dy_i[0] - STQMEKF_DW.Delay1_DSTATE_b
        [0] != STQMEKF_P.Constant3_Value_d4);
      RelationalOperator_i[1] = (STQMEKF_B.dy_i[1] - STQMEKF_DW.Delay1_DSTATE_b
        [1] != STQMEKF_P.Constant3_Value_d4);
      RelationalOperator_i[2] = (STQMEKF_B.dy_i[2] - STQMEKF_DW.Delay1_DSTATE_b
        [2] != STQMEKF_P.Constant3_Value_d4);

      // Outputs for Enabled SubSystem: '<S183>/Enabled Subsystem'
      STQMEKF_EnabledSubsystem(RelationalOperator_i, STQMEKF_B.dy_i,
        ARM_Path_idx_1, STQMEKF_B.dy_k, &STQMEKF_B.EnabledSubsystem_m,
        &STQMEKF_DW.EnabledSubsystem_m, &STQMEKF_P.EnabledSubsystem_m);

      // End of Outputs for SubSystem: '<S183>/Enabled Subsystem'

      // DataStoreWrite: '<S174>/RED_Px7' incorporates:
      //   RelationalOperator: '<S183>/Relational Operator'
      //   SignalConversion generated from: '<S188>/Enable'

      STQMEKF_DW.BLACK_Measured_States[0] = STQMEKF_B.ConvertBLAXfrommmtom;
      STQMEKF_DW.BLACK_Measured_States[1] = ARM_Path_idx_0;
      STQMEKF_DW.BLACK_Measured_States[5] = STQMEKF_B.ReceivePhaseSpaceData_o1
        [15];
      STQMEKF_DW.BLACK_Measured_States[6] = STQMEKF_B.dy_k[0];
      STQMEKF_DW.BLACK_Measured_States[7] = STQMEKF_B.dy_k[1];
      STQMEKF_DW.BLACK_Measured_States[8] = STQMEKF_B.dy_k[2];

      // SignalConversion generated from: '<S184>/Delay1' incorporates:
      //   Delay: '<S184>/Delay1'

      STQMEKF_DW.Delay1_DSTATE_g[0] = STQMEKF_B.ConvertBLAXfrommmtom;
      STQMEKF_DW.Delay1_DSTATE_g[1] = ARM_Path_idx_0;
      STQMEKF_DW.Delay1_DSTATE_g[2] = STQMEKF_B.ReceivePhaseSpaceData_o1[6];

      // Gain: '<S175>/Convert BLUX from [mm] to [m]'
      STQMEKF_B.ConvertBLUXfrommmtom = STQMEKF_P.ConvertBLUXfrommmtom_Gain *
        STQMEKF_B.ReceivePhaseSpaceData_o1[7];

      // Gain: '<S175>/Convert BLUY from [mm] to [m]'
      ARM_Path_idx_0 = STQMEKF_P.ConvertBLUYfrommmtom_Gain *
        STQMEKF_B.ReceivePhaseSpaceData_o1[8];

      // Trigonometry: '<S195>/Sin'
      ARM_Path_idx_1 = sin(STQMEKF_B.ReceivePhaseSpaceData_o1[9]);

      // Trigonometry: '<S195>/Cos'
      ARM_Path_idx_2 = cos(STQMEKF_B.ReceivePhaseSpaceData_o1[9]);

      // DataStoreWrite: '<S175>/RED_Px7' incorporates:
      //   Gain: '<S175>/Convert BLUEVX from [mm] to [m]'
      //   Gain: '<S175>/Convert BLUEVY from [mm] to [m]'
      //   Trigonometry: '<S195>/Atan2'

      STQMEKF_DW.BLUE_Measured_States[2] = rt_atan2d_snf(ARM_Path_idx_1,
        ARM_Path_idx_2);
      STQMEKF_DW.BLUE_Measured_States[3] = STQMEKF_P.ConvertBLUEVXfrommmtom_Gain
        * STQMEKF_B.ReceivePhaseSpaceData_o1[16];
      STQMEKF_DW.BLUE_Measured_States[4] = STQMEKF_P.ConvertBLUEVYfrommmtom_Gain
        * STQMEKF_B.ReceivePhaseSpaceData_o1[17];

      // Sum: '<S192>/Subtract1' incorporates:
      //   Delay: '<S192>/Delay2'

      ARM_Path_idx_2 = STQMEKF_B.ReceivePhaseSpaceData_o1[0] -
        STQMEKF_DW.Delay2_DSTATE_l;

      // Outputs for Enabled SubSystem: '<S192>/Enabled Subsystem3' incorporates:
      //   EnablePort: '<S196>/Enable'

      if (STQMEKF_B.ConvertBLUXfrommmtom - STQMEKF_DW.Delay1_DSTATE_l !=
          STQMEKF_P.Constant3_Value_o) {
        // SignalConversion generated from: '<S196>/y2-y1'
        STQMEKF_B.y2y1_o = ARM_Path_idx_2;
      }

      // End of Outputs for SubSystem: '<S192>/Enabled Subsystem3'

      // MATLAB Function: '<S192>/MATLAB Function' incorporates:
      //   Constant: '<S192>/Constant'
      //   Constant: '<S192>/Constant3'
      //   Delay: '<S192>/Delay1'
      //   RelationalOperator: '<S192>/Relational Operator'
      //   Sum: '<S192>/Subtract2'

      STQMEKF_MATLABFunction_j(STQMEKF_B.y2y1_o, STQMEKF_P.dataRate,
        &ARM_Path_idx_1);

      // Sum: '<S194>/Subtract1' incorporates:
      //   Delay: '<S194>/Delay1'

      ARM_Path_idx_2 = STQMEKF_B.ReceivePhaseSpaceData_o1[9] -
        STQMEKF_DW.Delay1_DSTATE_m[2];

      // RelationalOperator: '<S194>/Relational Operator' incorporates:
      //   Constant: '<S194>/Constant3'
      //   Delay: '<S194>/Delay1'
      //   Sum: '<S194>/Subtract1'

      RelationalOperator_i[0] = (STQMEKF_B.ConvertBLUXfrommmtom -
        STQMEKF_DW.Delay1_DSTATE_m[0] != STQMEKF_P.Constant3_Value_c);
      RelationalOperator_i[1] = (ARM_Path_idx_0 - STQMEKF_DW.Delay1_DSTATE_m[1]
        != STQMEKF_P.Constant3_Value_c);
      RelationalOperator_i[2] = (ARM_Path_idx_2 != STQMEKF_P.Constant3_Value_c);

      // Outputs for Enabled SubSystem: '<S194>/Enabled Subsystem'
      STQMEKF_EnabledSubsystem_n(RelationalOperator_i,
        STQMEKF_B.ConvertBLUXfrommmtom, ARM_Path_idx_0,
        STQMEKF_B.ReceivePhaseSpaceData_o1[9], ARM_Path_idx_1, STQMEKF_B.dy_c,
        &STQMEKF_B.EnabledSubsystem_g, &STQMEKF_DW.EnabledSubsystem_g,
        &STQMEKF_P.EnabledSubsystem_g);

      // End of Outputs for SubSystem: '<S194>/Enabled Subsystem'

      // RelationalOperator: '<S193>/Relational Operator' incorporates:
      //   Constant: '<S193>/Constant3'
      //   Delay: '<S193>/Delay1'
      //   SignalConversion generated from: '<S200>/Enable'
      //   Sum: '<S193>/Subtract1'

      RelationalOperator_i[0] = (STQMEKF_B.dy_c[0] -
        STQMEKF_DW.Delay1_DSTATE_lv[0] != STQMEKF_P.Constant3_Value_ke);
      RelationalOperator_i[1] = (STQMEKF_B.dy_c[1] -
        STQMEKF_DW.Delay1_DSTATE_lv[1] != STQMEKF_P.Constant3_Value_ke);
      RelationalOperator_i[2] = (STQMEKF_B.dy_c[2] -
        STQMEKF_DW.Delay1_DSTATE_lv[2] != STQMEKF_P.Constant3_Value_ke);

      // Outputs for Enabled SubSystem: '<S193>/Enabled Subsystem'
      STQMEKF_EnabledSubsystem(RelationalOperator_i, STQMEKF_B.dy_c,
        ARM_Path_idx_1, STQMEKF_B.dy_e, &STQMEKF_B.EnabledSubsystem_l,
        &STQMEKF_DW.EnabledSubsystem_l, &STQMEKF_P.EnabledSubsystem_l);

      // End of Outputs for SubSystem: '<S193>/Enabled Subsystem'

      // DataStoreWrite: '<S175>/RED_Px7' incorporates:
      //   RelationalOperator: '<S193>/Relational Operator'
      //   SignalConversion generated from: '<S198>/Enable'

      STQMEKF_DW.BLUE_Measured_States[0] = STQMEKF_B.ConvertBLUXfrommmtom;
      STQMEKF_DW.BLUE_Measured_States[1] = ARM_Path_idx_0;
      STQMEKF_DW.BLUE_Measured_States[5] = STQMEKF_B.ReceivePhaseSpaceData_o1[18];
      STQMEKF_DW.BLUE_Measured_States[6] = STQMEKF_B.dy_e[0];
      STQMEKF_DW.BLUE_Measured_States[7] = STQMEKF_B.dy_e[1];
      STQMEKF_DW.BLUE_Measured_States[8] = STQMEKF_B.dy_e[2];

      // SignalConversion generated from: '<S194>/Delay1' incorporates:
      //   Delay: '<S194>/Delay1'

      STQMEKF_DW.Delay1_DSTATE_m[0] = STQMEKF_B.ConvertBLUXfrommmtom;
      STQMEKF_DW.Delay1_DSTATE_m[1] = ARM_Path_idx_0;
      STQMEKF_DW.Delay1_DSTATE_m[2] = STQMEKF_B.ReceivePhaseSpaceData_o1[9];

      // Gain: '<S176>/Convert REDX from [mm] to [m]'
      STQMEKF_B.ConvertREDXfrommmtom = STQMEKF_P.ConvertREDXfrommmtom_Gain *
        STQMEKF_B.ReceivePhaseSpaceData_o1[1];

      // Gain: '<S176>/Convert REDY from [mm] to [m]'
      ARM_Path_idx_0 = STQMEKF_P.ConvertREDYfrommmtom_Gain *
        STQMEKF_B.ReceivePhaseSpaceData_o1[2];

      // Trigonometry: '<S205>/Sin'
      ARM_Path_idx_1 = sin(STQMEKF_B.ReceivePhaseSpaceData_o1[3]);

      // Trigonometry: '<S205>/Cos'
      ARM_Path_idx_2 = cos(STQMEKF_B.ReceivePhaseSpaceData_o1[3]);

      // DataStoreWrite: '<S176>/RED_Px7' incorporates:
      //   Gain: '<S176>/Convert REDVX from [mm] to [m]'
      //   Gain: '<S176>/Convert REDVY from [mm] to [m]'
      //   Trigonometry: '<S205>/Atan2'

      STQMEKF_DW.RED_Measured_States[2] = rt_atan2d_snf(ARM_Path_idx_1,
        ARM_Path_idx_2);
      STQMEKF_DW.RED_Measured_States[3] = STQMEKF_P.ConvertREDVXfrommmtom_Gain *
        STQMEKF_B.ReceivePhaseSpaceData_o1[10];
      STQMEKF_DW.RED_Measured_States[4] = STQMEKF_P.ConvertREDVYfrommmtom_Gain *
        STQMEKF_B.ReceivePhaseSpaceData_o1[11];

      // Sum: '<S202>/Subtract1' incorporates:
      //   Delay: '<S202>/Delay2'

      ARM_Path_idx_2 = STQMEKF_B.ReceivePhaseSpaceData_o1[0] -
        STQMEKF_DW.Delay2_DSTATE_l0;

      // Outputs for Enabled SubSystem: '<S202>/Enabled Subsystem3' incorporates:
      //   EnablePort: '<S206>/Enable'

      if (STQMEKF_B.ConvertREDXfrommmtom - STQMEKF_DW.Delay1_DSTATE_ld !=
          STQMEKF_P.Constant3_Value_f) {
        // SignalConversion generated from: '<S206>/y2-y1'
        STQMEKF_B.y2y1 = ARM_Path_idx_2;
      }

      // End of Outputs for SubSystem: '<S202>/Enabled Subsystem3'

      // MATLAB Function: '<S202>/MATLAB Function' incorporates:
      //   Constant: '<S202>/Constant'
      //   Constant: '<S202>/Constant3'
      //   Delay: '<S202>/Delay1'
      //   RelationalOperator: '<S202>/Relational Operator'
      //   Sum: '<S202>/Subtract2'

      STQMEKF_MATLABFunction_j(STQMEKF_B.y2y1, STQMEKF_P.dataRate,
        &ARM_Path_idx_1);

      // Sum: '<S204>/Subtract1' incorporates:
      //   Delay: '<S204>/Delay1'

      ARM_Path_idx_2 = STQMEKF_B.ReceivePhaseSpaceData_o1[3] -
        STQMEKF_DW.Delay1_DSTATE_c[2];

      // RelationalOperator: '<S204>/Relational Operator' incorporates:
      //   Constant: '<S204>/Constant3'
      //   Delay: '<S204>/Delay1'
      //   Sum: '<S204>/Subtract1'

      RelationalOperator_i[0] = (STQMEKF_B.ConvertREDXfrommmtom -
        STQMEKF_DW.Delay1_DSTATE_c[0] != STQMEKF_P.Constant3_Value_dh);
      RelationalOperator_i[1] = (ARM_Path_idx_0 - STQMEKF_DW.Delay1_DSTATE_c[1]
        != STQMEKF_P.Constant3_Value_dh);
      RelationalOperator_i[2] = (ARM_Path_idx_2 != STQMEKF_P.Constant3_Value_dh);

      // Outputs for Enabled SubSystem: '<S204>/Enabled Subsystem'
      STQMEKF_EnabledSubsystem_n(RelationalOperator_i,
        STQMEKF_B.ConvertREDXfrommmtom, ARM_Path_idx_0,
        STQMEKF_B.ReceivePhaseSpaceData_o1[3], ARM_Path_idx_1, STQMEKF_B.dy,
        &STQMEKF_B.EnabledSubsystem_a, &STQMEKF_DW.EnabledSubsystem_a,
        &STQMEKF_P.EnabledSubsystem_a);

      // End of Outputs for SubSystem: '<S204>/Enabled Subsystem'

      // RelationalOperator: '<S203>/Relational Operator' incorporates:
      //   Constant: '<S203>/Constant3'
      //   Delay: '<S203>/Delay1'
      //   SignalConversion generated from: '<S210>/Enable'
      //   Sum: '<S203>/Subtract1'

      RelationalOperator_i[0] = (STQMEKF_B.dy[0] - STQMEKF_DW.Delay1_DSTATE_cq[0]
        != STQMEKF_P.Constant3_Value_dz);
      RelationalOperator_i[1] = (STQMEKF_B.dy[1] - STQMEKF_DW.Delay1_DSTATE_cq[1]
        != STQMEKF_P.Constant3_Value_dz);
      RelationalOperator_i[2] = (STQMEKF_B.dy[2] - STQMEKF_DW.Delay1_DSTATE_cq[2]
        != STQMEKF_P.Constant3_Value_dz);

      // Outputs for Enabled SubSystem: '<S203>/Enabled Subsystem'
      STQMEKF_EnabledSubsystem(RelationalOperator_i, STQMEKF_B.dy,
        ARM_Path_idx_1, STQMEKF_B.dy_l, &STQMEKF_B.EnabledSubsystem_k,
        &STQMEKF_DW.EnabledSubsystem_k, &STQMEKF_P.EnabledSubsystem_k);

      // End of Outputs for SubSystem: '<S203>/Enabled Subsystem'

      // DataStoreWrite: '<S176>/RED_Px7' incorporates:
      //   RelationalOperator: '<S203>/Relational Operator'
      //   SignalConversion generated from: '<S208>/Enable'

      STQMEKF_DW.RED_Measured_States[0] = STQMEKF_B.ConvertREDXfrommmtom;
      STQMEKF_DW.RED_Measured_States[1] = ARM_Path_idx_0;
      STQMEKF_DW.RED_Measured_States[5] = STQMEKF_B.ReceivePhaseSpaceData_o1[12];
      STQMEKF_DW.RED_Measured_States[6] = STQMEKF_B.dy_l[0];
      STQMEKF_DW.RED_Measured_States[7] = STQMEKF_B.dy_l[1];
      STQMEKF_DW.RED_Measured_States[8] = STQMEKF_B.dy_l[2];

      // MATLAB Function: '<S178>/MATLAB Function' incorporates:
      //   Delay: '<S178>/Delay'
      //   Delay: '<S178>/Delay1'
      //   Delay: '<S178>/Delay2'

      rtb_StartClock = 0;
      if (STQMEKF_P.platformSelection == 1.0) {
        rtb_StartClock = (STQMEKF_DW.Delay_DSTATE_i[0] == 1);
      } else if (STQMEKF_P.platformSelection == 2.0) {
        rtb_StartClock = (STQMEKF_DW.Delay1_DSTATE_h[0] == 1);
      } else if (STQMEKF_P.platformSelection == 3.0) {
        rtb_StartClock = ((STQMEKF_DW.Delay_DSTATE_i[0] == 1) &&
                          (STQMEKF_DW.Delay1_DSTATE_h[0] == 1));
      } else if (STQMEKF_P.platformSelection == 4.0) {
        rtb_StartClock = ((STQMEKF_DW.Delay_DSTATE_i[0] == 1) &&
                          (STQMEKF_DW.Delay1_DSTATE_h[0] == 1));
      } else if (STQMEKF_P.platformSelection == 5.0) {
        rtb_StartClock = (STQMEKF_DW.Delay_DSTATE_i[0] == 1);
      } else if (STQMEKF_P.platformSelection == 6.0) {
        rtb_StartClock = (STQMEKF_DW.Delay2_DSTATE_hq[0] == 1);
      } else if (STQMEKF_P.platformSelection == 7.0) {
        rtb_StartClock = ((STQMEKF_DW.Delay_DSTATE_i[0] == 1) &&
                          (STQMEKF_DW.Delay2_DSTATE_hq[0] == 1));
      } else if (STQMEKF_P.platformSelection == 8.0) {
        rtb_StartClock = ((STQMEKF_DW.Delay_DSTATE_i[0] == 1) &&
                          (STQMEKF_DW.Delay1_DSTATE_h[0] == 1) &&
                          (STQMEKF_DW.Delay2_DSTATE_hq[0] == 1));
      } else if (STQMEKF_P.platformSelection == 9.0) {
        rtb_StartClock = ((STQMEKF_DW.Delay1_DSTATE_h[0] == 1) &&
                          (STQMEKF_DW.Delay2_DSTATE_hq[0] == 1));
      } else if (STQMEKF_P.platformSelection == 10.0) {
        rtb_StartClock = ((STQMEKF_DW.Delay_DSTATE_i[0] == 1) &&
                          (STQMEKF_DW.Delay2_DSTATE_hq[0] == 1));
      } else if (STQMEKF_P.platformSelection == 11.0) {
        rtb_StartClock = ((STQMEKF_DW.Delay_DSTATE_i[0] == 1) &&
                          (STQMEKF_DW.Delay1_DSTATE_h[0] == 1) &&
                          (STQMEKF_DW.Delay2_DSTATE_hq[0] == 1));
      }

      // End of MATLAB Function: '<S178>/MATLAB Function'

      // RelationalOperator: '<S177>/Relational Operator1' incorporates:
      //   Constant: '<S177>/Constant'

      STQMEKF_B.RelationalOperator1 = (rtb_StartClock !=
        STQMEKF_P.Constant_Value);

      // Outputs for Enabled SubSystem: '<S177>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S179>/Enable'

      if (STQMEKF_B.RelationalOperator1) {
        // Memory: '<S179>/Memory'
        STQMEKF_B.Memory = STQMEKF_DW.Memory_PreviousInput;
      }

      // End of Outputs for SubSystem: '<S177>/Enabled Subsystem'

      // Clock: '<S173>/Clock'
      STQMEKF_B.Clock = STQMEKF_M->Timing.t[0];

      // Outputs for Enabled SubSystem: '<S177>/Enabled Subsystem1' incorporates:
      //   EnablePort: '<S180>/Enable'

      if (rtb_StartClock == STQMEKF_P.Constant_Value) {
        // Sum: '<S180>/Subtract'
        STQMEKF_B.Subtract = STQMEKF_B.Clock - STQMEKF_B.Memory;
      }

      // End of Outputs for SubSystem: '<S177>/Enabled Subsystem1'

      // DataStoreWrite: '<S176>/Universal_Time' incorporates:
      //   Constant: '<S177>/Constant'
      //   RelationalOperator: '<S177>/Relational Operator'

      STQMEKF_DW.Univ_Time = STQMEKF_B.Subtract;

      // SignalConversion generated from: '<S204>/Delay1' incorporates:
      //   Delay: '<S204>/Delay1'

      STQMEKF_DW.Delay1_DSTATE_c[0] = STQMEKF_B.ConvertREDXfrommmtom;
      STQMEKF_DW.Delay1_DSTATE_c[1] = ARM_Path_idx_0;
      STQMEKF_DW.Delay1_DSTATE_c[2] = STQMEKF_B.ReceivePhaseSpaceData_o1[3];

      // S-Function (sdspFromNetwork): '<S178>/UDP Receive'
      sErr = GetErrorBuffer(&STQMEKF_DW.UDPReceive_NetworkLib[0U]);
      rtb_StartClock = 1;
      LibOutputs_Network(&STQMEKF_DW.UDPReceive_NetworkLib[0U],
                         &STQMEKF_B.UDPReceive_o1, &rtb_StartClock);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }

      // End of S-Function (sdspFromNetwork): '<S178>/UDP Receive'

      // S-Function (sdspFromNetwork): '<S178>/UDP Receive2'
      sErr = GetErrorBuffer(&STQMEKF_DW.UDPReceive2_NetworkLib[0U]);
      nz = 1;
      LibOutputs_Network(&STQMEKF_DW.UDPReceive2_NetworkLib[0U],
                         &STQMEKF_B.UDPReceive2_o1, &nz);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }

      // End of S-Function (sdspFromNetwork): '<S178>/UDP Receive2'

      // S-Function (sdspFromNetwork): '<S178>/UDP Receive3'
      sErr = GetErrorBuffer(&STQMEKF_DW.UDPReceive3_NetworkLib[0U]);
      samplesRead_1 = 1;
      LibOutputs_Network(&STQMEKF_DW.UDPReceive3_NetworkLib[0U],
                         &STQMEKF_B.UDPReceive3_o1, &samplesRead_1);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }

      // End of S-Function (sdspFromNetwork): '<S178>/UDP Receive3'
      // End of Outputs for SubSystem: '<S10>/Use Hardware to Obtain States'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S10>/Initialize Universal Time (Simulation)' incorporates:
      //   ActionPort: '<S171>/Action Port'

      // Clock: '<S171>/Set Universal Time (If this is a simulation)' incorporates:
      //   DataStoreWrite: '<S171>/Universal_Time'

      STQMEKF_DW.Univ_Time = STQMEKF_M->Timing.t[0];

      // End of Outputs for SubSystem: '<S10>/Initialize Universal Time (Simulation)' 
      break;
    }

    // End of If: '<S10>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 

    // If: '<S12>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
    //   DataStoreRead: '<S11>/Data Store Read1'
    //   If: '<S11>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.'

    if (STQMEKF_DW.isSim == 0.0) {
      // Outputs for IfAction SubSystem: '<S11>/Subsystem' incorporates:
      //   ActionPort: '<S212>/Action Port'

      // MATLABSystem: '<S212>/WhoAmI' incorporates:
      //   DataStoreWrite: '<S212>/Data Store Write'

      if (STQMEKF_DW.obj_dk.SampleTime != STQMEKF_P.baseRate) {
        if (((!rtIsInf(STQMEKF_P.baseRate)) && (!rtIsNaN(STQMEKF_P.baseRate))) ||
            rtIsInf(STQMEKF_P.baseRate)) {
          sampleTime_0 = STQMEKF_P.baseRate;
        }

        STQMEKF_DW.obj_dk.SampleTime = sampleTime_0;
      }

      //         %% Define output properties
      //  Call C-function implementing device output
      STQMEKF_DW.WhoAmI = WhoAmI();

      // End of MATLABSystem: '<S212>/WhoAmI'
      // End of Outputs for SubSystem: '<S11>/Subsystem'

      // Outputs for IfAction SubSystem: '<S12>/Subsystem' incorporates:
      //   ActionPort: '<S213>/Action Port'

      // S-Function (sdspFromNetwork): '<S213>/UDP Receive1'
      sErr = GetErrorBuffer(&STQMEKF_DW.UDPReceive1_NetworkLib[0U]);
      samplesRead_0 = 4;
      LibOutputs_Network(&STQMEKF_DW.UDPReceive1_NetworkLib[0U],
                         &STQMEKF_B.UDPReceive1_o1[0U], &samplesRead_0);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }

      // End of S-Function (sdspFromNetwork): '<S213>/UDP Receive1'

      // DataStoreWrite: '<S213>/Measured States for BLACK' incorporates:
      //   DataTypeConversion: '<S213>/Cast To Double'
      //   DataTypeConversion: '<S213>/Cast To Double1'

      STQMEKF_DW.BLACK_States_Vis_raw[4] = STQMEKF_B.UDPReceive1_o1[0];
      STQMEKF_DW.BLACK_States_Vis_raw[5] = STQMEKF_B.UDPReceive1_o1[1];

      // DataTypeConversion: '<S213>/Cast To Double2'
      sampleTime_0 = STQMEKF_B.UDPReceive1_o1[2];

      // MATLAB Function: '<S213>/Build quat' incorporates:
      //   SignalConversion generated from: '<S214>/ SFunction '

      rtb_MatrixConcatenate[3] = sampleTime_0;
      rtb_MatrixConcatenate[0] = 0.0;
      rtb_MatrixConcatenate[1] = 0.0;
      rtb_MatrixConcatenate[2] = 1.0;
      ARM_Path_idx_2 = sin(sampleTime_0 / 2.0);

      // DataStoreWrite: '<S213>/Measured States for BLACK' incorporates:
      //   MATLAB Function: '<S213>/Build quat'
      //   SignalConversion generated from: '<S214>/ SFunction '

      STQMEKF_DW.BLACK_States_Vis_raw[0] = cos(sampleTime_0 / 2.0);
      STQMEKF_DW.BLACK_States_Vis_raw[1] = 0.0 * ARM_Path_idx_2;
      STQMEKF_DW.BLACK_States_Vis_raw[2] = 0.0 * ARM_Path_idx_2;
      STQMEKF_DW.BLACK_States_Vis_raw[3] = ARM_Path_idx_2;
      STQMEKF_DW.BLACK_States_Vis_raw[6] = 0.0;

      // DataTypeConversion: '<S213>/Cast To Double3' incorporates:
      //   DataStoreWrite: '<S213>/Measured States for BLACK1'

      STQMEKF_DW.Confidance = STQMEKF_B.UDPReceive1_o1[3];

      // End of Outputs for SubSystem: '<S12>/Subsystem'
    }

    // End of If: '<S12>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 

    // If: '<S13>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   DataStoreRead: '<S13>/Data Store Read'
    //   DataStoreRead: '<S13>/Data Store Read1'

    if ((STQMEKF_DW.WhoAmI == 1.0) && (STQMEKF_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S13>/Change ARM Behavior' incorporates:
      //   ActionPort: '<S215>/Action Port'

      // MATLABSystem: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' incorporates:
      //   DataStoreRead: '<S215>/Arm Control Mode'
      //   DataStoreWrite: '<S3>/Data Store Write9'

      if (STQMEKF_DW.obj_n.POSITION_P_GAIN !=
          STQMEKF_P.ControlDynamixelActuatorsineith) {
        STQMEKF_DW.obj_n.POSITION_P_GAIN =
          STQMEKF_P.ControlDynamixelActuatorsineith;
      }

      if (STQMEKF_DW.obj_n.POSITION_I_GAIN !=
          STQMEKF_P.ControlDynamixelActuatorsinei_b) {
        STQMEKF_DW.obj_n.POSITION_I_GAIN =
          STQMEKF_P.ControlDynamixelActuatorsinei_b;
      }

      if (STQMEKF_DW.obj_n.POSITION_D_GAIN !=
          STQMEKF_P.ControlDynamixelActuatorsinei_h) {
        STQMEKF_DW.obj_n.POSITION_D_GAIN =
          STQMEKF_P.ControlDynamixelActuatorsinei_h;
      }

      if (STQMEKF_DW.obj_n.MAX_POSITION !=
          STQMEKF_P.ControlDynamixelActuatorsinei_j) {
        STQMEKF_DW.obj_n.MAX_POSITION =
          STQMEKF_P.ControlDynamixelActuatorsinei_j;
      }

      if (STQMEKF_DW.obj_n.MIN_POSITION !=
          STQMEKF_P.ControlDynamixelActuatorsinei_m) {
        STQMEKF_DW.obj_n.MIN_POSITION =
          STQMEKF_P.ControlDynamixelActuatorsinei_m;
      }

      if (STQMEKF_DW.obj_n.MOVE_TIME !=
          STQMEKF_P.ControlDynamixelActuatorsine_hy) {
        STQMEKF_DW.obj_n.MOVE_TIME = STQMEKF_P.ControlDynamixelActuatorsine_hy;
      }

      if (STQMEKF_DW.obj_n.CURRENT_LIMIT !=
          STQMEKF_P.ControlDynamixelActuatorsinei_i) {
        STQMEKF_DW.obj_n.CURRENT_LIMIT =
          STQMEKF_P.ControlDynamixelActuatorsinei_i;
      }

      if (STQMEKF_DW.obj_n.SPEED_P_GAIN !=
          STQMEKF_P.ControlDynamixelActuatorsinei_g) {
        STQMEKF_DW.obj_n.SPEED_P_GAIN =
          STQMEKF_P.ControlDynamixelActuatorsinei_g;
      }

      if (STQMEKF_DW.obj_n.SPEED_I_GAIN !=
          STQMEKF_P.ControlDynamixelActuatorsine_g3) {
        STQMEKF_DW.obj_n.SPEED_I_GAIN =
          STQMEKF_P.ControlDynamixelActuatorsine_g3;
      }

      if (STQMEKF_DW.obj_n.VELOCITY_LIMIT !=
          STQMEKF_P.ControlDynamixelActuatorsine_bf) {
        STQMEKF_DW.obj_n.VELOCITY_LIMIT =
          STQMEKF_P.ControlDynamixelActuatorsine_bf;
      }

      if (STQMEKF_DW.obj_n.ACCELERATION_TIME !=
          STQMEKF_P.ControlDynamixelActuatorsinei_l) {
        STQMEKF_DW.obj_n.ACCELERATION_TIME =
          STQMEKF_P.ControlDynamixelActuatorsinei_l;
      }

      if (STQMEKF_DW.obj_n.SampleTime != STQMEKF_P.baseRate) {
        if (((!rtIsInf(STQMEKF_P.baseRate)) && (!rtIsNaN(STQMEKF_P.baseRate))) ||
            rtIsInf(STQMEKF_P.baseRate)) {
          sampleTime_1 = STQMEKF_P.baseRate;
        }

        STQMEKF_DW.obj_n.SampleTime = sampleTime_1;
      }

      //         %% Define input properties
      //  Call C-function implementing device output
      //  include the dynamicel functions
      //  Run the main controller code. If the switch state is
      //  true then this code will initialize the parameters and
      //  then start the actuator, and THEN run the command. If the
      //  switch state is false, it will not reinitialize the
      //  motor
      dynamixel_controller(STQMEKF_DW.ARM_Control_Mode,
                           STQMEKF_DW.obj_n.POSITION_P_GAIN,
                           STQMEKF_DW.obj_n.POSITION_I_GAIN,
                           STQMEKF_DW.obj_n.POSITION_D_GAIN,
                           STQMEKF_DW.obj_n.MAX_POSITION,
                           STQMEKF_DW.obj_n.MIN_POSITION,
                           STQMEKF_DW.obj_n.MOVE_TIME, rtb_Merge6[0],
                           rtb_Merge6[1], rtb_Merge6[2],
                           STQMEKF_DW.obj_n.CURRENT_LIMIT, rtb_Merge6[0],
                           rtb_Merge6[1], rtb_Merge6[2],
                           STQMEKF_DW.obj_n.SPEED_P_GAIN,
                           STQMEKF_DW.obj_n.SPEED_I_GAIN,
                           STQMEKF_DW.obj_n.VELOCITY_LIMIT, rtb_Merge6[0],
                           rtb_Merge6[1], rtb_Merge6[2],
                           STQMEKF_DW.obj_n.ACCELERATION_TIME);

      // End of MATLABSystem: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
      // End of Outputs for SubSystem: '<S13>/Change ARM Behavior'
    }

    // End of If: '<S13>/This IF block determines whether or not to run the RED sim//exp ' 

    // If: '<S15>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
    //   DataStoreRead: '<S15>/Data Store Read1'

    if (STQMEKF_DW.isSim == 0.0) {
      // Outputs for IfAction SubSystem: '<S15>/Subsystem' incorporates:
      //   ActionPort: '<S224>/Action Port'

      // SignalConversion generated from: '<S224>/UDP Send' incorporates:
      //   DataStoreRead: '<S224>/BLACK States'
      //   DataStoreRead: '<S224>/BLUE States'
      //   DataStoreRead: '<S224>/RED States'
      //   DataStoreRead: '<S224>/Time'

      STQMEKF_B.TmpSignalConversionAtUDPSendI_o[0] = STQMEKF_DW.Univ_Time;
      for (i = 0; i < 9; i++) {
        STQMEKF_B.TmpSignalConversionAtUDPSendI_o[i + 1] =
          STQMEKF_DW.RED_Measured_States[i];
        STQMEKF_B.TmpSignalConversionAtUDPSendI_o[i + 10] =
          STQMEKF_DW.BLACK_Measured_States[i];
        STQMEKF_B.TmpSignalConversionAtUDPSendI_o[i + 19] =
          STQMEKF_DW.BLUE_Measured_States[i];
      }

      // Update for S-Function (sdspToNetwork): '<S224>/UDP Send' incorporates:
      //   SignalConversion generated from: '<S224>/UDP Send'
      //
      sErr = GetErrorBuffer(&STQMEKF_DW.UDPSend_NetworkLib_m[0U]);
      LibUpdate_Network(&STQMEKF_DW.UDPSend_NetworkLib_m[0U],
                        &STQMEKF_B.TmpSignalConversionAtUDPSendI_o[0U], 28);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }

      // End of Update for S-Function (sdspToNetwork): '<S224>/UDP Send'
      // End of Outputs for SubSystem: '<S15>/Subsystem'
    }

    // End of If: '<S15>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 

    // If: '<S17>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   Constant: '<S254>/Constant1'
    //   Constant: '<S254>/Constant2'
    //   DataStoreRead: '<S17>/Data Store Read'
    //   DataStoreRead: '<S17>/Data Store Read1'
    //   Delay: '<S254>/Delay'
    //   RelationalOperator: '<S254>/Relational Operator1'
    //   RelationalOperator: '<S254>/Relational Operator2'

    if ((STQMEKF_DW.WhoAmI == 1.0) || (STQMEKF_DW.isSim == 1.0)) {
      // Outputs for IfAction SubSystem: '<S17>/Change RED Behavior' incorporates:
      //   ActionPort: '<S227>/Action Port'

      // MATLAB Function: '<S258>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S227>/Data Store Read1'

      STQMEKF_CreateRotationMatrix(STQMEKF_DW.RED_Measured_States[2],
        rtb_MatrixConcatenate);

      // MATLAB Function: '<S253>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S227>/Data Store Read1'

      STQMEKF_CreateRotationMatrix_a(STQMEKF_DW.RED_Measured_States[2],
        &rtb_ThrustPer_Final[0]);

      // Product: '<S253>/Rotate F_I to F_b' incorporates:
      //   DataStoreRead: '<S227>/Data Store Read'

      rtb_TSamp_jb = rtb_ThrustPer_Final[0] * RED_Controls[0] + RED_Controls[1] *
        rtb_ThrustPer_Final[2];
      BLUE_Path_Planner_Selection = RED_Controls[0] * rtb_ThrustPer_Final[1] +
        RED_Controls[1] * rtb_ThrustPer_Final[3];

      // SignalConversion generated from: '<S255>/Product3' incorporates:
      //   DataStoreRead: '<S227>/Data Store Read'

      rtb_Merge6[2] = RED_Controls[2];

      // MATLAB Function: '<S255>/MATLAB Function'
      for (i = 0; i < 8; i++) {
        prev_duty_cycles[i] = STQMEKF_P.F_thrusters_RED[i] / 2.0;
      }

      memset(&y[0], 0, sizeof(real_T) << 6U);
      for (V_tmp = 0; V_tmp < 8; V_tmp++) {
        y[V_tmp + (V_tmp << 3)] = prev_duty_cycles[V_tmp];

        // MATLAB Function: '<S252>/MATLAB Function5'
        rtb_H_tmp[3 * V_tmp] = b_0[V_tmp];
        rtb_H_tmp[3 * V_tmp + 1] = c[V_tmp];
        rtb_H_tmp[3 * V_tmp + 2] = STQMEKF_P.thruster_dist2CG_RED[V_tmp] /
          1000.0;
      }

      for (b_k = 0; b_k < 8; b_k++) {
        for (jj = 0; jj < 3; jj++) {
          sampleTime_1 = 0.0;
          for (i = 0; i < 8; i++) {
            sampleTime_1 += rtb_H_tmp[3 * i + jj] * y[(b_k << 3) + i];
          }

          rtb_H[jj + 3 * b_k] = sampleTime_1;
        }
      }

      // End of MATLAB Function: '<S255>/MATLAB Function'
      STQMEKF_Pseudoinverse1(rtb_H, &STQMEKF_B.Pseudoinverse1_pn);

      // MATLAB Function: '<S252>/MATLAB Function5'
      sampleTime_1 = 1.0;
      rtb_z_true_0 = 2.0 * STQMEKF_P.MATLABFunction5_tol_g;
      for (b_k = 0; b_k < 8; b_k++) {
        // Product: '<S255>/Product3' incorporates:
        //   MATLABSystem: '<S255>/Pseudoinverse1'
        //   Product: '<S253>/Rotate F_I to F_b'

        sampleTime_0 = (STQMEKF_B.Pseudoinverse1_pn.Pseudoinverse1[b_k + 8] *
                        BLUE_Path_Planner_Selection +
                        STQMEKF_B.Pseudoinverse1_pn.Pseudoinverse1[b_k] *
                        rtb_TSamp_jb) +
          STQMEKF_B.Pseudoinverse1_pn.Pseudoinverse1[b_k + 16] * rtb_Merge6[2];
        STQMEKF_B.duty_cycles[b_k] = sampleTime_0;

        // MATLAB Function: '<S252>/MATLAB Function5' incorporates:
        //   Product: '<S255>/Product3'

        prev_duty_cycles[b_k] = sampleTime_0 + rtb_z_true_0;
      }

      // MATLAB Function: '<S252>/MATLAB Function5'
      samplesRead = 0;
      do {
        exitg2 = 0;
        if (samplesRead <= static_cast<int32_T>
            (STQMEKF_P.MATLABFunction5_max_iters_e) - 1) {
          ARM_Path_idx_0 = STQMEKF_P.F_red_X_nominal * sampleTime_1 / 2.0;
          PWMs_tmp_tmp[0] = ARM_Path_idx_0;
          PWMs_tmp_tmp[1] = ARM_Path_idx_0;
          sampleTime_1 = STQMEKF_P.F_red_Y_nominal * sampleTime_1 / 2.0;
          PWMs_tmp_tmp[2] = sampleTime_1;
          PWMs_tmp_tmp[3] = sampleTime_1;
          PWMs_tmp_tmp[4] = ARM_Path_idx_0;
          PWMs_tmp_tmp[5] = ARM_Path_idx_0;
          PWMs_tmp_tmp[6] = sampleTime_1;
          PWMs_tmp_tmp[7] = sampleTime_1;
          memset(&y[0], 0, sizeof(real_T) << 6U);
          for (i = 0; i < 8; i++) {
            y[i + (i << 3)] = PWMs_tmp_tmp[i];
          }

          for (b_k = 0; b_k < 3; b_k++) {
            for (jj = 0; jj < 8; jj++) {
              sampleTime_1 = 0.0;
              for (i = 0; i < 8; i++) {
                sampleTime_1 += rtb_H_tmp[3 * i + b_k] * y[(jj << 3) + i];
              }

              rtb_H[b_k + 3 * jj] = sampleTime_1;
              tmp[jj + (b_k << 3)] = sampleTime_1;
            }
          }

          for (b_k = 0; b_k < 8; b_k++) {
            rtb_z_true_0 = tmp[b_k + 8];
            sampleTime_1 = tmp[b_k];
            sampleTime_0 = tmp[b_k + 16];
            for (jj = 0; jj < 8; jj++) {
              y[b_k + (jj << 3)] = (rtb_H[3 * jj + 1] * rtb_z_true_0 + rtb_H[3 *
                                    jj] * sampleTime_1) + rtb_H[3 * jj + 2] *
                sampleTime_0;
            }

            PWMs_tmp_tmp[b_k] = (rtb_z_true_0 * BLUE_Path_Planner_Selection +
                                 sampleTime_1 * rtb_TSamp_jb) + sampleTime_0 *
              rtb_Merge6[2];
          }

          for (b_k = 0; b_k < 64; b_k++) {
            tmp_6[b_k] = 2.0 * y[b_k];
          }

          for (b_k = 0; b_k < 8; b_k++) {
            PWMs[b_k] = -2.0 * PWMs_tmp_tmp[b_k];
          }

          STQMEKF_quadprog(tmp_6, PWMs, STQMEKF_B.duty_cycles, PWMs_tmp_tmp,
                           &sampleTime_1, &rtb_TSamp_e);
          sampleTime_1 = STQMEKF_maximum_i(PWMs_tmp_tmp);
          for (i = 0; i < 8; i++) {
            sampleTime_0 = PWMs_tmp_tmp[i];
            STQMEKF_B.duty_cycles[i] = sampleTime_0;
            PWMs[i] = sampleTime_0;
            if (sampleTime_1 > 1.0) {
              sampleTime_0 /= sampleTime_1;
              PWMs[i] = sampleTime_0;
            }

            x_0[i] = (sampleTime_0 > 0.0);
          }

          nz = x_0[0];
          for (jj = 0; jj < 7; jj++) {
            nz += x_0[jj + 1];
          }

          for (b_k = 0; b_k < 8; b_k++) {
            rtb_z_true_0 = PWMs[b_k];
            if (rtb_z_true_0 >= 0.0) {
              b_maxval[b_k] = rtb_z_true_0;
            } else {
              b_maxval[b_k] = 0.0;
            }
          }

          rtb_TSamp_e = b_maxval[0];
          for (jj = 0; jj < 7; jj++) {
            rtb_TSamp_e += b_maxval[jj + 1];
          }

          if (nz >= 1) {
            b_k = nz;
          } else {
            b_k = 1;
          }

          sampleTime_1 = rtb_TSamp_e / static_cast<real_T>(b_k);
          if ((sampleTime_1 < 0.3) || (nz == 0)) {
            sampleTime_1 = 1.0;
          } else {
            sampleTime_1 = (0.6 - 2.0 * sampleTime_1) + 1.0;
            if (!(sampleTime_1 >= 0.5)) {
              sampleTime_1 = 0.5;
            }
          }

          sampleTime_0 = 0.0;
          for (i = 0; i < 8; i++) {
            ARM_Path_idx_2 = PWMs_tmp_tmp[i] - prev_duty_cycles[i];
            prev_duty_cycles[i] = ARM_Path_idx_2;
            ARM_Path_idx_2 = fabs(ARM_Path_idx_2);
            if (rtIsNaN(ARM_Path_idx_2)) {
              sampleTime_0 = (rtNaN);
            } else if (ARM_Path_idx_2 > sampleTime_0) {
              sampleTime_0 = ARM_Path_idx_2;
            }
          }

          if (sampleTime_0 < STQMEKF_P.MATLABFunction5_tol_g) {
            ARM_Path_idx_0 = STQMEKF_P.F_red_X_nominal * sampleTime_1;
            PWMs_tmp_tmp[0] = ARM_Path_idx_0;
            PWMs_tmp_tmp[1] = ARM_Path_idx_0;
            sampleTime_1 *= STQMEKF_P.F_red_Y_nominal;
            PWMs_tmp_tmp[2] = sampleTime_1;
            PWMs_tmp_tmp[3] = sampleTime_1;
            PWMs_tmp_tmp[4] = ARM_Path_idx_0;
            PWMs_tmp_tmp[5] = ARM_Path_idx_0;
            PWMs_tmp_tmp[6] = sampleTime_1;
            PWMs_tmp_tmp[7] = sampleTime_1;
            memset(&y[0], 0, sizeof(real_T) << 6U);
            for (b_k = 0; b_k < 8; b_k++) {
              y[b_k + (b_k << 3)] = PWMs_tmp_tmp[b_k];
            }

            for (b_k = 0; b_k < 8; b_k++) {
              for (jj = 0; jj < 3; jj++) {
                sampleTime_1 = 0.0;
                for (i = 0; i < 8; i++) {
                  sampleTime_1 += rtb_H_tmp[3 * i + jj] * y[(b_k << 3) + i];
                }

                rtb_H[jj + 3 * b_k] = sampleTime_1;
              }
            }

            exitg2 = 1;
          } else {
            memcpy(&prev_duty_cycles[0], &PWMs_tmp_tmp[0], sizeof(real_T) << 3U);
            samplesRead++;
          }
        } else {
          ARM_Path_idx_0 = STQMEKF_P.F_red_X_nominal * sampleTime_1;
          PWMs_tmp_tmp[0] = ARM_Path_idx_0;
          PWMs_tmp_tmp[1] = ARM_Path_idx_0;
          sampleTime_1 *= STQMEKF_P.F_red_Y_nominal;
          PWMs_tmp_tmp[2] = sampleTime_1;
          PWMs_tmp_tmp[3] = sampleTime_1;
          PWMs_tmp_tmp[4] = ARM_Path_idx_0;
          PWMs_tmp_tmp[5] = ARM_Path_idx_0;
          PWMs_tmp_tmp[6] = sampleTime_1;
          PWMs_tmp_tmp[7] = sampleTime_1;
          memset(&y[0], 0, sizeof(real_T) << 6U);
          for (V_tmp = 0; V_tmp < 8; V_tmp++) {
            y[V_tmp + (V_tmp << 3)] = PWMs_tmp_tmp[V_tmp];
          }

          for (b_k = 0; b_k < 8; b_k++) {
            for (jj = 0; jj < 3; jj++) {
              sampleTime_1 = 0.0;
              for (i = 0; i < 8; i++) {
                sampleTime_1 += rtb_H_tmp[3 * i + jj] * y[(b_k << 3) + i];
              }

              rtb_H[jj + 3 * b_k] = sampleTime_1;
            }
          }

          exitg2 = 1;
        }
      } while (exitg2 == 0);

      // MATLAB Function: '<S252>/MATLAB Function8'
      STQMEKF_MATLABFunction1(STQMEKF_B.duty_cycles, rtb_ThrustPer_Final);

      // Outputs for Enabled SubSystem: '<S254>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S259>/Enable'

      if (STQMEKF_DW.Delay_DSTATE_b >= 1.0 / STQMEKF_P.PWMFreq) {
        // SignalConversion generated from: '<S259>/In1' incorporates:
        //   DataStoreRead: '<S254>/Data Store Read'

        STQMEKF_B.In1 = STQMEKF_DW.Univ_Time;
      }

      // End of Outputs for SubSystem: '<S254>/Enabled Subsystem'

      // Sum: '<S254>/Subtract' incorporates:
      //   Constant: '<S254>/Constant1'
      //   DataStoreRead: '<S254>/Data Store Read'
      //   Delay: '<S254>/Delay'
      //   RelationalOperator: '<S254>/Relational Operator1'

      STQMEKF_DW.Delay_DSTATE_b = STQMEKF_DW.Univ_Time - STQMEKF_B.In1;

      // Outputs for Enabled SubSystem: '<S254>/Enabled Subsystem1' incorporates:
      //   EnablePort: '<S260>/Enable'

      if (STQMEKF_DW.Delay_DSTATE_b == STQMEKF_P.Constant2_Value_e) {
        // SignalConversion generated from: '<S260>/ThrustPer_Final'
        memcpy(&STQMEKF_B.ThrustPer_Final[0], &rtb_ThrustPer_Final[0], sizeof
               (real_T) << 3U);
      }

      // End of Outputs for SubSystem: '<S254>/Enabled Subsystem1'

      // Product: '<S252>/Product1' incorporates:
      //   Constant: '<S254>/Constant2'
      //   Delay: '<S254>/Delay'
      //   RelationalOperator: '<S254>/Relational Operator2'

      for (b_k = 0; b_k < 3; b_k++) {
        sampleTime_1 = 0.0;
        for (jj = 0; jj < 8; jj++) {
          sampleTime_1 += rtb_H[3 * jj + b_k] * STQMEKF_B.ThrustPer_Final[jj];
        }

        rtb_Merge6[b_k] = sampleTime_1;
      }

      // End of Product: '<S252>/Product1'

      // DataStoreWrite: '<S227>/Data Store Write1' incorporates:
      //   Product: '<S258>/Rotate F_b to F_I'

      STQMEKF_DW.RED_Saturated_Controls[0] = rtb_MatrixConcatenate[0] *
        rtb_Merge6[0] + rtb_Merge6[1] * rtb_MatrixConcatenate[2];
      STQMEKF_DW.RED_Saturated_Controls[1] = rtb_Merge6[0] *
        rtb_MatrixConcatenate[1] + rtb_Merge6[1] * rtb_MatrixConcatenate[3];
      STQMEKF_DW.RED_Saturated_Controls[2] = rtb_Merge6[2];

      // End of Outputs for SubSystem: '<S17>/Change RED Behavior'
    }

    // End of If: '<S17>/This IF block determines whether or not to run the RED sim//exp ' 

    // If: '<S17>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
    //   Constant: '<S230>/Constant1'
    //   Constant: '<S230>/Constant2'
    //   DataStoreRead: '<S17>/Data Store Read'
    //   DataStoreRead: '<S17>/Data Store Read1'
    //   Delay: '<S230>/Delay'
    //   RelationalOperator: '<S230>/Relational Operator1'
    //   RelationalOperator: '<S230>/Relational Operator2'

    if ((STQMEKF_DW.WhoAmI == 2.0) || (STQMEKF_DW.isSim == 1.0)) {
      // Outputs for IfAction SubSystem: '<S17>/Change BLACK Behavior' incorporates:
      //   ActionPort: '<S225>/Action Port'

      // MATLAB Function: '<S234>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S225>/BLACK States'

      STQMEKF_CreateRotationMatrix(STQMEKF_DW.BLACK_Measured_States[2],
        rtb_MatrixConcatenate);

      // MATLAB Function: '<S229>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S225>/BLACK States'

      STQMEKF_CreateRotationMatrix_a(STQMEKF_DW.BLACK_Measured_States[2],
        &rtb_ThrustPer_Final_d[0]);

      // Product: '<S229>/Rotate F_I to F_b' incorporates:
      //   DataStoreRead: '<S225>/BLACK Controls'

      rtb_TSamp_jb = rtb_ThrustPer_Final_d[0] * BLACK_Controls[0] +
        BLACK_Controls[1] * rtb_ThrustPer_Final_d[2];
      BLUE_Path_Planner_Selection = BLACK_Controls[0] * rtb_ThrustPer_Final_d[1]
        + BLACK_Controls[1] * rtb_ThrustPer_Final_d[3];

      // SignalConversion generated from: '<S231>/Product3' incorporates:
      //   DataStoreRead: '<S225>/BLACK Controls'

      RED_Controls[2] = BLACK_Controls[2];

      // MATLAB Function: '<S231>/MATLAB Function'
      for (i = 0; i < 8; i++) {
        prev_duty_cycles[i] = STQMEKF_P.F_thrusters_BLACK[i] / 2.0;
      }

      memset(&y[0], 0, sizeof(real_T) << 6U);
      for (V_tmp = 0; V_tmp < 8; V_tmp++) {
        y[V_tmp + (V_tmp << 3)] = prev_duty_cycles[V_tmp];

        // MATLAB Function: '<S228>/MATLAB Function5'
        rtb_H_tmp[3 * V_tmp] = b_0[V_tmp];
        rtb_H_tmp[3 * V_tmp + 1] = c[V_tmp];
        rtb_H_tmp[3 * V_tmp + 2] = STQMEKF_P.thruster_dist2CG_BLACK[V_tmp] /
          1000.0;
      }

      for (b_k = 0; b_k < 8; b_k++) {
        for (jj = 0; jj < 3; jj++) {
          sampleTime_1 = 0.0;
          for (i = 0; i < 8; i++) {
            sampleTime_1 += rtb_H_tmp[3 * i + jj] * y[(b_k << 3) + i];
          }

          rtb_H[jj + 3 * b_k] = sampleTime_1;
        }
      }

      // End of MATLAB Function: '<S231>/MATLAB Function'
      STQMEKF_Pseudoinverse1(rtb_H, &STQMEKF_B.Pseudoinverse1);

      // MATLAB Function: '<S228>/MATLAB Function5'
      sampleTime_1 = 1.0;
      rtb_z_true_0 = 2.0 * STQMEKF_P.MATLABFunction5_tol;
      for (b_k = 0; b_k < 8; b_k++) {
        // Product: '<S231>/Product3' incorporates:
        //   MATLABSystem: '<S231>/Pseudoinverse1'
        //   Product: '<S229>/Rotate F_I to F_b'

        sampleTime_0 = (STQMEKF_B.Pseudoinverse1.Pseudoinverse1[b_k + 8] *
                        BLUE_Path_Planner_Selection +
                        STQMEKF_B.Pseudoinverse1.Pseudoinverse1[b_k] *
                        rtb_TSamp_jb) +
          STQMEKF_B.Pseudoinverse1.Pseudoinverse1[b_k + 16] * RED_Controls[2];
        STQMEKF_B.duty_cycles_l[b_k] = sampleTime_0;

        // MATLAB Function: '<S228>/MATLAB Function5' incorporates:
        //   Product: '<S231>/Product3'

        prev_duty_cycles[b_k] = sampleTime_0 + rtb_z_true_0;
      }

      // MATLAB Function: '<S228>/MATLAB Function5'
      samplesRead = 0;
      do {
        exitg2 = 0;
        if (samplesRead <= static_cast<int32_T>
            (STQMEKF_P.MATLABFunction5_max_iters) - 1) {
          ARM_Path_idx_0 = STQMEKF_P.F_black_X_nominal * sampleTime_1 / 2.0;
          PWMs_tmp_tmp[0] = ARM_Path_idx_0;
          PWMs_tmp_tmp[1] = ARM_Path_idx_0;
          sampleTime_1 = STQMEKF_P.F_black_Y_nominal * sampleTime_1 / 2.0;
          PWMs_tmp_tmp[2] = sampleTime_1;
          PWMs_tmp_tmp[3] = sampleTime_1;
          PWMs_tmp_tmp[4] = ARM_Path_idx_0;
          PWMs_tmp_tmp[5] = ARM_Path_idx_0;
          PWMs_tmp_tmp[6] = sampleTime_1;
          PWMs_tmp_tmp[7] = sampleTime_1;
          memset(&y[0], 0, sizeof(real_T) << 6U);
          for (i = 0; i < 8; i++) {
            y[i + (i << 3)] = PWMs_tmp_tmp[i];
          }

          for (b_k = 0; b_k < 3; b_k++) {
            for (jj = 0; jj < 8; jj++) {
              sampleTime_1 = 0.0;
              for (i = 0; i < 8; i++) {
                sampleTime_1 += rtb_H_tmp[3 * i + b_k] * y[(jj << 3) + i];
              }

              rtb_H[b_k + 3 * jj] = sampleTime_1;
              tmp[jj + (b_k << 3)] = sampleTime_1;
            }
          }

          for (b_k = 0; b_k < 8; b_k++) {
            rtb_z_true_0 = tmp[b_k + 8];
            sampleTime_1 = tmp[b_k];
            sampleTime_0 = tmp[b_k + 16];
            for (jj = 0; jj < 8; jj++) {
              y[b_k + (jj << 3)] = (rtb_H[3 * jj + 1] * rtb_z_true_0 + rtb_H[3 *
                                    jj] * sampleTime_1) + rtb_H[3 * jj + 2] *
                sampleTime_0;
            }

            PWMs_tmp_tmp[b_k] = (rtb_z_true_0 * BLUE_Path_Planner_Selection +
                                 sampleTime_1 * rtb_TSamp_jb) + sampleTime_0 *
              RED_Controls[2];
          }

          for (b_k = 0; b_k < 64; b_k++) {
            tmp_6[b_k] = 2.0 * y[b_k];
          }

          for (b_k = 0; b_k < 8; b_k++) {
            PWMs[b_k] = -2.0 * PWMs_tmp_tmp[b_k];
          }

          STQMEKF_quadprog(tmp_6, PWMs, STQMEKF_B.duty_cycles_l, PWMs_tmp_tmp,
                           &sampleTime_1, &rtb_TSamp_e);
          sampleTime_1 = STQMEKF_maximum_i(PWMs_tmp_tmp);
          for (i = 0; i < 8; i++) {
            sampleTime_0 = PWMs_tmp_tmp[i];
            STQMEKF_B.duty_cycles_l[i] = sampleTime_0;
            PWMs[i] = sampleTime_0;
            if (sampleTime_1 > 1.0) {
              sampleTime_0 /= sampleTime_1;
              PWMs[i] = sampleTime_0;
            }

            x_0[i] = (sampleTime_0 > 0.0);
          }

          nz = x_0[0];
          for (jj = 0; jj < 7; jj++) {
            nz += x_0[jj + 1];
          }

          for (b_k = 0; b_k < 8; b_k++) {
            rtb_z_true_0 = PWMs[b_k];
            if (rtb_z_true_0 >= 0.0) {
              b_maxval[b_k] = rtb_z_true_0;
            } else {
              b_maxval[b_k] = 0.0;
            }
          }

          rtb_TSamp_e = b_maxval[0];
          for (jj = 0; jj < 7; jj++) {
            rtb_TSamp_e += b_maxval[jj + 1];
          }

          if (nz >= 1) {
            b_k = nz;
          } else {
            b_k = 1;
          }

          sampleTime_1 = rtb_TSamp_e / static_cast<real_T>(b_k);
          if ((sampleTime_1 < 0.3) || (nz == 0)) {
            sampleTime_1 = 1.0;
          } else {
            sampleTime_1 = (0.6 - 2.0 * sampleTime_1) + 1.0;
            if (!(sampleTime_1 >= 0.5)) {
              sampleTime_1 = 0.5;
            }
          }

          sampleTime_0 = 0.0;
          for (i = 0; i < 8; i++) {
            ARM_Path_idx_2 = PWMs_tmp_tmp[i] - prev_duty_cycles[i];
            prev_duty_cycles[i] = ARM_Path_idx_2;
            ARM_Path_idx_2 = fabs(ARM_Path_idx_2);
            if (rtIsNaN(ARM_Path_idx_2)) {
              sampleTime_0 = (rtNaN);
            } else if (ARM_Path_idx_2 > sampleTime_0) {
              sampleTime_0 = ARM_Path_idx_2;
            }
          }

          if (sampleTime_0 < STQMEKF_P.MATLABFunction5_tol) {
            ARM_Path_idx_0 = STQMEKF_P.F_black_X_nominal * sampleTime_1;
            PWMs_tmp_tmp[0] = ARM_Path_idx_0;
            PWMs_tmp_tmp[1] = ARM_Path_idx_0;
            sampleTime_1 *= STQMEKF_P.F_black_Y_nominal;
            PWMs_tmp_tmp[2] = sampleTime_1;
            PWMs_tmp_tmp[3] = sampleTime_1;
            PWMs_tmp_tmp[4] = ARM_Path_idx_0;
            PWMs_tmp_tmp[5] = ARM_Path_idx_0;
            PWMs_tmp_tmp[6] = sampleTime_1;
            PWMs_tmp_tmp[7] = sampleTime_1;
            memset(&y[0], 0, sizeof(real_T) << 6U);
            for (b_k = 0; b_k < 8; b_k++) {
              y[b_k + (b_k << 3)] = PWMs_tmp_tmp[b_k];
            }

            for (b_k = 0; b_k < 8; b_k++) {
              for (jj = 0; jj < 3; jj++) {
                sampleTime_1 = 0.0;
                for (i = 0; i < 8; i++) {
                  sampleTime_1 += rtb_H_tmp[3 * i + jj] * y[(b_k << 3) + i];
                }

                rtb_H[jj + 3 * b_k] = sampleTime_1;
              }
            }

            exitg2 = 1;
          } else {
            memcpy(&prev_duty_cycles[0], &PWMs_tmp_tmp[0], sizeof(real_T) << 3U);
            samplesRead++;
          }
        } else {
          ARM_Path_idx_0 = STQMEKF_P.F_black_X_nominal * sampleTime_1;
          PWMs_tmp_tmp[0] = ARM_Path_idx_0;
          PWMs_tmp_tmp[1] = ARM_Path_idx_0;
          sampleTime_1 *= STQMEKF_P.F_black_Y_nominal;
          PWMs_tmp_tmp[2] = sampleTime_1;
          PWMs_tmp_tmp[3] = sampleTime_1;
          PWMs_tmp_tmp[4] = ARM_Path_idx_0;
          PWMs_tmp_tmp[5] = ARM_Path_idx_0;
          PWMs_tmp_tmp[6] = sampleTime_1;
          PWMs_tmp_tmp[7] = sampleTime_1;
          memset(&y[0], 0, sizeof(real_T) << 6U);
          for (V_tmp = 0; V_tmp < 8; V_tmp++) {
            y[V_tmp + (V_tmp << 3)] = PWMs_tmp_tmp[V_tmp];
          }

          for (b_k = 0; b_k < 8; b_k++) {
            for (jj = 0; jj < 3; jj++) {
              sampleTime_1 = 0.0;
              for (i = 0; i < 8; i++) {
                sampleTime_1 += rtb_H_tmp[3 * i + jj] * y[(b_k << 3) + i];
              }

              rtb_H[jj + 3 * b_k] = sampleTime_1;
            }
          }

          exitg2 = 1;
        }
      } while (exitg2 == 0);

      // MATLAB Function: '<S228>/MATLAB Function1'
      STQMEKF_MATLABFunction1(STQMEKF_B.duty_cycles_l, rtb_ThrustPer_Final_d);

      // Outputs for Enabled SubSystem: '<S230>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S235>/Enable'

      if (STQMEKF_DW.Delay_DSTATE_kz >= 1.0 / STQMEKF_P.PWMFreq) {
        // SignalConversion generated from: '<S235>/In1' incorporates:
        //   DataStoreRead: '<S230>/Data Store Read'

        STQMEKF_B.In1_g2 = STQMEKF_DW.Univ_Time;
      }

      // End of Outputs for SubSystem: '<S230>/Enabled Subsystem'

      // Sum: '<S230>/Subtract' incorporates:
      //   Constant: '<S230>/Constant1'
      //   DataStoreRead: '<S230>/Data Store Read'
      //   Delay: '<S230>/Delay'
      //   RelationalOperator: '<S230>/Relational Operator1'

      STQMEKF_DW.Delay_DSTATE_kz = STQMEKF_DW.Univ_Time - STQMEKF_B.In1_g2;

      // Outputs for Enabled SubSystem: '<S230>/Enabled Subsystem1' incorporates:
      //   EnablePort: '<S236>/Enable'

      if (STQMEKF_DW.Delay_DSTATE_kz == STQMEKF_P.Constant2_Value_h) {
        // SignalConversion generated from: '<S236>/ThrustPer_Final'
        memcpy(&STQMEKF_B.ThrustPer_Final_h5[0], &rtb_ThrustPer_Final_d[0],
               sizeof(real_T) << 3U);
      }

      // End of Outputs for SubSystem: '<S230>/Enabled Subsystem1'

      // Product: '<S228>/Product1' incorporates:
      //   Constant: '<S230>/Constant2'
      //   Delay: '<S230>/Delay'
      //   RelationalOperator: '<S230>/Relational Operator2'

      for (b_k = 0; b_k < 3; b_k++) {
        sampleTime_1 = 0.0;
        for (jj = 0; jj < 8; jj++) {
          sampleTime_1 += rtb_H[3 * jj + b_k] * STQMEKF_B.ThrustPer_Final_h5[jj];
        }

        RED_Controls[b_k] = sampleTime_1;
      }

      // End of Product: '<S228>/Product1'

      // DataStoreWrite: '<S225>/Data Store Write2' incorporates:
      //   Product: '<S234>/Rotate F_b to F_I'

      STQMEKF_DW.BLACK_Saturated_Controls[0] = rtb_MatrixConcatenate[0] *
        RED_Controls[0] + RED_Controls[1] * rtb_MatrixConcatenate[2];
      STQMEKF_DW.BLACK_Saturated_Controls[1] = RED_Controls[0] *
        rtb_MatrixConcatenate[1] + RED_Controls[1] * rtb_MatrixConcatenate[3];
      STQMEKF_DW.BLACK_Saturated_Controls[2] = RED_Controls[2];

      // End of Outputs for SubSystem: '<S17>/Change BLACK Behavior'
    }

    // End of If: '<S17>/This IF block determines whether or not to run the BLACK sim//exp' 

    // If: '<S17>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
    //   Constant: '<S242>/Constant1'
    //   Constant: '<S242>/Constant2'
    //   DataStoreRead: '<S17>/Data Store Read'
    //   DataStoreRead: '<S17>/Data Store Read1'
    //   Delay: '<S242>/Delay'
    //   RelationalOperator: '<S242>/Relational Operator1'
    //   RelationalOperator: '<S242>/Relational Operator2'

    if ((STQMEKF_DW.WhoAmI == 3.0) || (STQMEKF_DW.isSim == 1.0)) {
      // Outputs for IfAction SubSystem: '<S17>/Change BLUE Behavior' incorporates:
      //   ActionPort: '<S226>/Action Port'

      // MATLAB Function: '<S246>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S226>/Data Store Read1'

      STQMEKF_CreateRotationMatrix(STQMEKF_DW.BLUE_Measured_States[2],
        rtb_MatrixConcatenate);

      // MATLAB Function: '<S241>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S226>/Data Store Read1'

      STQMEKF_CreateRotationMatrix_a(STQMEKF_DW.BLUE_Measured_States[2],
        &rtb_ThrustPer_Final_b[0]);

      // Product: '<S241>/Rotate F_I to F_b' incorporates:
      //   DataStoreRead: '<S226>/Data Store Read'

      rtb_TSamp_jb = rtb_ThrustPer_Final_b[0] * rtb_TSamp_af +
        rtb_ThrustPer_Final_b[2] * rtb_TSamp_o;
      BLUE_Path_Planner_Selection = rtb_ThrustPer_Final_b[1] * rtb_TSamp_af +
        rtb_ThrustPer_Final_b[3] * rtb_TSamp_o;

      // MATLAB Function: '<S243>/MATLAB Function'
      for (i = 0; i < 8; i++) {
        prev_duty_cycles[i] = STQMEKF_P.F_thrusters_BLUE[i] / 2.0;
      }

      memset(&y[0], 0, sizeof(real_T) << 6U);
      for (V_tmp = 0; V_tmp < 8; V_tmp++) {
        y[V_tmp + (V_tmp << 3)] = prev_duty_cycles[V_tmp];

        // MATLAB Function: '<S240>/MATLAB Function5'
        rtb_H_tmp[3 * V_tmp] = b_0[V_tmp];
        rtb_H_tmp[3 * V_tmp + 1] = c[V_tmp];
        rtb_H_tmp[3 * V_tmp + 2] = STQMEKF_P.thruster_dist2CG_BLUE[V_tmp] /
          1000.0;
      }

      for (b_k = 0; b_k < 8; b_k++) {
        for (jj = 0; jj < 3; jj++) {
          sampleTime_1 = 0.0;
          for (i = 0; i < 8; i++) {
            sampleTime_1 += rtb_H_tmp[3 * i + jj] * y[(b_k << 3) + i];
          }

          rtb_H[jj + 3 * b_k] = sampleTime_1;
        }
      }

      // End of MATLAB Function: '<S243>/MATLAB Function'
      STQMEKF_Pseudoinverse1(rtb_H, &STQMEKF_B.Pseudoinverse1_p);

      // MATLAB Function: '<S240>/MATLAB Function5'
      sampleTime_1 = 1.0;
      rtb_z_true_0 = 2.0 * STQMEKF_P.MATLABFunction5_tol_m;
      for (b_k = 0; b_k < 8; b_k++) {
        // Product: '<S243>/Product3' incorporates:
        //   DataStoreRead: '<S226>/Data Store Read'
        //   MATLABSystem: '<S243>/Pseudoinverse1'
        //   Product: '<S241>/Rotate F_I to F_b'
        //   SignalConversion generated from: '<S243>/Product3'

        rtb_TSamp_af = (STQMEKF_B.Pseudoinverse1_p.Pseudoinverse1[b_k + 8] *
                        BLUE_Path_Planner_Selection +
                        STQMEKF_B.Pseudoinverse1_p.Pseudoinverse1[b_k] *
                        rtb_TSamp_jb) +
          STQMEKF_B.Pseudoinverse1_p.Pseudoinverse1[b_k + 16] * rtb_TSamp_k;
        STQMEKF_B.duty_cycles_p[b_k] = rtb_TSamp_af;

        // MATLAB Function: '<S240>/MATLAB Function5' incorporates:
        //   Product: '<S243>/Product3'

        prev_duty_cycles[b_k] = rtb_TSamp_af + rtb_z_true_0;
      }

      // MATLAB Function: '<S240>/MATLAB Function5'
      samplesRead = 0;
      do {
        exitg2 = 0;
        if (samplesRead <= static_cast<int32_T>
            (STQMEKF_P.MATLABFunction5_max_iters_c) - 1) {
          ARM_Path_idx_0 = STQMEKF_P.F_blue_X_nominal * sampleTime_1 / 2.0;
          PWMs_tmp_tmp[0] = ARM_Path_idx_0;
          PWMs_tmp_tmp[1] = ARM_Path_idx_0;
          sampleTime_1 = STQMEKF_P.F_blue_Y_nominal * sampleTime_1 / 2.0;
          PWMs_tmp_tmp[2] = sampleTime_1;
          PWMs_tmp_tmp[3] = sampleTime_1;
          PWMs_tmp_tmp[4] = ARM_Path_idx_0;
          PWMs_tmp_tmp[5] = ARM_Path_idx_0;
          PWMs_tmp_tmp[6] = sampleTime_1;
          PWMs_tmp_tmp[7] = sampleTime_1;
          memset(&y[0], 0, sizeof(real_T) << 6U);
          for (i = 0; i < 8; i++) {
            y[i + (i << 3)] = PWMs_tmp_tmp[i];
          }

          for (b_k = 0; b_k < 3; b_k++) {
            for (jj = 0; jj < 8; jj++) {
              sampleTime_1 = 0.0;
              for (i = 0; i < 8; i++) {
                sampleTime_1 += rtb_H_tmp[3 * i + b_k] * y[(jj << 3) + i];
              }

              rtb_H[b_k + 3 * jj] = sampleTime_1;
              tmp[jj + (b_k << 3)] = sampleTime_1;
            }
          }

          for (b_k = 0; b_k < 8; b_k++) {
            rtb_z_true_0 = tmp[b_k + 8];
            sampleTime_1 = tmp[b_k];
            sampleTime_0 = tmp[b_k + 16];
            for (jj = 0; jj < 8; jj++) {
              y[b_k + (jj << 3)] = (rtb_H[3 * jj + 1] * rtb_z_true_0 + rtb_H[3 *
                                    jj] * sampleTime_1) + rtb_H[3 * jj + 2] *
                sampleTime_0;
            }

            PWMs_tmp_tmp[b_k] = (rtb_z_true_0 * BLUE_Path_Planner_Selection +
                                 sampleTime_1 * rtb_TSamp_jb) + sampleTime_0 *
              rtb_TSamp_k;
          }

          for (b_k = 0; b_k < 64; b_k++) {
            tmp_6[b_k] = 2.0 * y[b_k];
          }

          for (b_k = 0; b_k < 8; b_k++) {
            PWMs[b_k] = -2.0 * PWMs_tmp_tmp[b_k];
          }

          STQMEKF_quadprog(tmp_6, PWMs, STQMEKF_B.duty_cycles_p, PWMs_tmp_tmp,
                           &sampleTime_1, &rtb_TSamp_e);
          sampleTime_1 = STQMEKF_maximum_i(PWMs_tmp_tmp);
          for (i = 0; i < 8; i++) {
            sampleTime_0 = PWMs_tmp_tmp[i];
            STQMEKF_B.duty_cycles_p[i] = sampleTime_0;
            PWMs[i] = sampleTime_0;
            if (sampleTime_1 > 1.0) {
              sampleTime_0 /= sampleTime_1;
              PWMs[i] = sampleTime_0;
            }

            x_0[i] = (sampleTime_0 > 0.0);
          }

          nz = x_0[0];
          for (jj = 0; jj < 7; jj++) {
            nz += x_0[jj + 1];
          }

          for (b_k = 0; b_k < 8; b_k++) {
            rtb_z_true_0 = PWMs[b_k];
            if (rtb_z_true_0 >= 0.0) {
              b_maxval[b_k] = rtb_z_true_0;
            } else {
              b_maxval[b_k] = 0.0;
            }
          }

          rtb_TSamp_e = b_maxval[0];
          for (jj = 0; jj < 7; jj++) {
            rtb_TSamp_e += b_maxval[jj + 1];
          }

          if (nz >= 1) {
            b_k = nz;
          } else {
            b_k = 1;
          }

          sampleTime_1 = rtb_TSamp_e / static_cast<real_T>(b_k);
          if ((sampleTime_1 < 0.3) || (nz == 0)) {
            sampleTime_1 = 1.0;
          } else {
            sampleTime_1 = (0.6 - 2.0 * sampleTime_1) + 1.0;
            if (!(sampleTime_1 >= 0.5)) {
              sampleTime_1 = 0.5;
            }
          }

          sampleTime_0 = 0.0;
          for (i = 0; i < 8; i++) {
            ARM_Path_idx_2 = PWMs_tmp_tmp[i] - prev_duty_cycles[i];
            prev_duty_cycles[i] = ARM_Path_idx_2;
            ARM_Path_idx_2 = fabs(ARM_Path_idx_2);
            if (rtIsNaN(ARM_Path_idx_2)) {
              sampleTime_0 = (rtNaN);
            } else if (ARM_Path_idx_2 > sampleTime_0) {
              sampleTime_0 = ARM_Path_idx_2;
            }
          }

          if (sampleTime_0 < STQMEKF_P.MATLABFunction5_tol_m) {
            ARM_Path_idx_0 = STQMEKF_P.F_blue_X_nominal * sampleTime_1;
            PWMs_tmp_tmp[0] = ARM_Path_idx_0;
            PWMs_tmp_tmp[1] = ARM_Path_idx_0;
            sampleTime_1 *= STQMEKF_P.F_blue_Y_nominal;
            PWMs_tmp_tmp[2] = sampleTime_1;
            PWMs_tmp_tmp[3] = sampleTime_1;
            PWMs_tmp_tmp[4] = ARM_Path_idx_0;
            PWMs_tmp_tmp[5] = ARM_Path_idx_0;
            PWMs_tmp_tmp[6] = sampleTime_1;
            PWMs_tmp_tmp[7] = sampleTime_1;
            memset(&y[0], 0, sizeof(real_T) << 6U);
            for (b_k = 0; b_k < 8; b_k++) {
              y[b_k + (b_k << 3)] = PWMs_tmp_tmp[b_k];
            }

            for (b_k = 0; b_k < 8; b_k++) {
              for (jj = 0; jj < 3; jj++) {
                sampleTime_1 = 0.0;
                for (i = 0; i < 8; i++) {
                  sampleTime_1 += rtb_H_tmp[3 * i + jj] * y[(b_k << 3) + i];
                }

                rtb_H[jj + 3 * b_k] = sampleTime_1;
              }
            }

            exitg2 = 1;
          } else {
            memcpy(&prev_duty_cycles[0], &PWMs_tmp_tmp[0], sizeof(real_T) << 3U);
            samplesRead++;
          }
        } else {
          ARM_Path_idx_0 = STQMEKF_P.F_blue_X_nominal * sampleTime_1;
          PWMs_tmp_tmp[0] = ARM_Path_idx_0;
          PWMs_tmp_tmp[1] = ARM_Path_idx_0;
          sampleTime_1 *= STQMEKF_P.F_blue_Y_nominal;
          PWMs_tmp_tmp[2] = sampleTime_1;
          PWMs_tmp_tmp[3] = sampleTime_1;
          PWMs_tmp_tmp[4] = ARM_Path_idx_0;
          PWMs_tmp_tmp[5] = ARM_Path_idx_0;
          PWMs_tmp_tmp[6] = sampleTime_1;
          PWMs_tmp_tmp[7] = sampleTime_1;
          memset(&y[0], 0, sizeof(real_T) << 6U);
          for (V_tmp = 0; V_tmp < 8; V_tmp++) {
            y[V_tmp + (V_tmp << 3)] = PWMs_tmp_tmp[V_tmp];
          }

          for (b_k = 0; b_k < 8; b_k++) {
            for (jj = 0; jj < 3; jj++) {
              sampleTime_1 = 0.0;
              for (i = 0; i < 8; i++) {
                sampleTime_1 += rtb_H_tmp[3 * i + jj] * y[(b_k << 3) + i];
              }

              rtb_H[jj + 3 * b_k] = sampleTime_1;
            }
          }

          exitg2 = 1;
        }
      } while (exitg2 == 0);

      // MATLAB Function: '<S240>/MATLAB Function1'
      STQMEKF_MATLABFunction1(STQMEKF_B.duty_cycles_p, rtb_ThrustPer_Final_b);

      // Outputs for Enabled SubSystem: '<S242>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S247>/Enable'

      if (STQMEKF_DW.Delay_DSTATE_k >= 1.0 / STQMEKF_P.PWMFreq) {
        // SignalConversion generated from: '<S247>/In1' incorporates:
        //   DataStoreRead: '<S242>/Data Store Read'

        STQMEKF_B.In1_g = STQMEKF_DW.Univ_Time;
      }

      // End of Outputs for SubSystem: '<S242>/Enabled Subsystem'

      // Sum: '<S242>/Subtract' incorporates:
      //   Constant: '<S242>/Constant1'
      //   DataStoreRead: '<S242>/Data Store Read'
      //   Delay: '<S242>/Delay'
      //   RelationalOperator: '<S242>/Relational Operator1'

      STQMEKF_DW.Delay_DSTATE_k = STQMEKF_DW.Univ_Time - STQMEKF_B.In1_g;

      // Outputs for Enabled SubSystem: '<S242>/Enabled Subsystem1' incorporates:
      //   EnablePort: '<S248>/Enable'

      if (STQMEKF_DW.Delay_DSTATE_k == STQMEKF_P.Constant2_Value_fq) {
        // SignalConversion generated from: '<S248>/ThrustPer_Final'
        memcpy(&STQMEKF_B.ThrustPer_Final_h[0], &rtb_ThrustPer_Final_b[0],
               sizeof(real_T) << 3U);
      }

      // End of Outputs for SubSystem: '<S242>/Enabled Subsystem1'

      // Product: '<S240>/Product1' incorporates:
      //   Constant: '<S242>/Constant2'
      //   Delay: '<S242>/Delay'
      //   RelationalOperator: '<S242>/Relational Operator2'

      for (b_k = 0; b_k < 3; b_k++) {
        rtb_TSamp_k = 0.0;
        for (jj = 0; jj < 8; jj++) {
          rtb_TSamp_k += rtb_H[3 * jj + b_k] * STQMEKF_B.ThrustPer_Final_h[jj];
        }

        BLACK_Controls[b_k] = rtb_TSamp_k;
      }

      // End of Product: '<S240>/Product1'

      // DataStoreWrite: '<S226>/Data Store Write3' incorporates:
      //   Product: '<S246>/Rotate F_b to F_I'

      STQMEKF_DW.BLUE_Saturated_Controls[0] = rtb_MatrixConcatenate[0] *
        BLACK_Controls[0] + BLACK_Controls[1] * rtb_MatrixConcatenate[2];
      STQMEKF_DW.BLUE_Saturated_Controls[1] = BLACK_Controls[0] *
        rtb_MatrixConcatenate[1] + BLACK_Controls[1] * rtb_MatrixConcatenate[3];
      STQMEKF_DW.BLUE_Saturated_Controls[2] = BLACK_Controls[2];

      // End of Outputs for SubSystem: '<S17>/Change BLUE Behavior'
    }

    // End of If: '<S17>/This IF block determines whether or not to run the BLUE sim//exp' 

    // SignalConversion generated from: '<S17>/UDP Send' incorporates:
    //   Constant: '<S17>/PWM Frequency'
    //   Constant: '<S17>/Safety Number'
    //   Gain: '<S17>/Gain'
    //   Gain: '<S17>/Gain1'
    //   Gain: '<S17>/Gain2'
    //   Gain: '<S17>/Gain3'
    //   Gain: '<S17>/Gain4'
    //   Gain: '<S17>/Gain5'
    //   Gain: '<S17>/Gain6'
    //   Gain: '<S17>/Gain7'
    //   Sum: '<S17>/Sum'
    //   Sum: '<S17>/Sum1'
    //   Sum: '<S17>/Sum2'
    //   Sum: '<S17>/Sum3'
    //   Sum: '<S17>/Sum4'
    //   Sum: '<S17>/Sum5'
    //   Sum: '<S17>/Sum6'
    //   Sum: '<S17>/Sum7'

    STQMEKF_B.TmpSignalConversionAtUDPSendInp[0] = STQMEKF_P.SafetyNumber_Value;
    STQMEKF_B.TmpSignalConversionAtUDPSendInp[1] = STQMEKF_P.PWMFreq;
    STQMEKF_B.TmpSignalConversionAtUDPSendInp[2] = ((STQMEKF_B.duty_cycles[0] +
      STQMEKF_B.duty_cycles_l[0]) + STQMEKF_B.duty_cycles_p[0]) *
      STQMEKF_P.Gain_Gain_oy;
    STQMEKF_B.TmpSignalConversionAtUDPSendInp[3] = ((STQMEKF_B.duty_cycles[1] +
      STQMEKF_B.duty_cycles_l[1]) + STQMEKF_B.duty_cycles_p[1]) *
      STQMEKF_P.Gain1_Gain_e;
    STQMEKF_B.TmpSignalConversionAtUDPSendInp[4] = ((STQMEKF_B.duty_cycles[2] +
      STQMEKF_B.duty_cycles_l[2]) + STQMEKF_B.duty_cycles_p[2]) *
      STQMEKF_P.Gain2_Gain;
    STQMEKF_B.TmpSignalConversionAtUDPSendInp[5] = ((STQMEKF_B.duty_cycles[3] +
      STQMEKF_B.duty_cycles_l[3]) + STQMEKF_B.duty_cycles_p[3]) *
      STQMEKF_P.Gain3_Gain;
    STQMEKF_B.TmpSignalConversionAtUDPSendInp[6] = ((STQMEKF_B.duty_cycles[4] +
      STQMEKF_B.duty_cycles_l[4]) + STQMEKF_B.duty_cycles_p[4]) *
      STQMEKF_P.Gain4_Gain;
    STQMEKF_B.TmpSignalConversionAtUDPSendInp[7] = ((STQMEKF_B.duty_cycles[5] +
      STQMEKF_B.duty_cycles_l[5]) + STQMEKF_B.duty_cycles_p[5]) *
      STQMEKF_P.Gain5_Gain;
    STQMEKF_B.TmpSignalConversionAtUDPSendInp[8] = ((STQMEKF_B.duty_cycles[6] +
      STQMEKF_B.duty_cycles_l[6]) + STQMEKF_B.duty_cycles_p[6]) *
      STQMEKF_P.Gain6_Gain_c;
    STQMEKF_B.TmpSignalConversionAtUDPSendInp[9] = ((STQMEKF_B.duty_cycles[7] +
      STQMEKF_B.duty_cycles_l[7]) + STQMEKF_B.duty_cycles_p[7]) *
      STQMEKF_P.Gain7_Gain_l;
  }

  {
    char_T *sErr;

    // Update for Delay: '<S217>/Delay1'
    STQMEKF_DW.Delay1_DSTATE = rtb_DataStoreRead_f[6];

    // Update for Delay: '<S218>/Delay2'
    memcpy(&STQMEKF_DW.Delay2_DSTATE[0], &STQMEKF_B.x[0], 13U * sizeof(real_T));

    // Update for Delay: '<S218>/Delay1'
    memcpy(&STQMEKF_DW.Delay1_DSTATE_n[0], &STQMEKF_B.P[0], 144U * sizeof(real_T));

    // Update for Delay: '<S218>/Delay3'
    memcpy(&STQMEKF_DW.Delay3_DSTATE[0], &STQMEKF_B.V[0], 36U * sizeof(real_T));

    // Update for If: '<S10>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 
    if (STQMEKF_DW.Ifperforminganexperimentgrabthe == 0) {
      // Update for IfAction SubSystem: '<S10>/Use Hardware to Obtain States' incorporates:
      //   ActionPort: '<S172>/Action Port'

      // Update for Delay: '<S182>/Delay2'
      STQMEKF_DW.Delay2_DSTATE_j = STQMEKF_B.ReceivePhaseSpaceData_o1[0];

      // Update for Delay: '<S182>/Delay1'
      STQMEKF_DW.Delay1_DSTATE_i = STQMEKF_B.ConvertBLAXfrommmtom;

      // Update for Enabled SubSystem: '<S184>/Enabled Subsystem'
      STQME_EnabledSubsystem_n_Update(STQMEKF_B.dy_i,
        &STQMEKF_B.EnabledSubsystem_n, &STQMEKF_DW.EnabledSubsystem_n);

      // End of Update for SubSystem: '<S184>/Enabled Subsystem'

      // Update for Delay: '<S183>/Delay1'
      STQMEKF_DW.Delay1_DSTATE_b[0] = STQMEKF_B.dy_i[0];
      STQMEKF_DW.Delay1_DSTATE_b[1] = STQMEKF_B.dy_i[1];
      STQMEKF_DW.Delay1_DSTATE_b[2] = STQMEKF_B.dy_i[2];

      // Update for Enabled SubSystem: '<S183>/Enabled Subsystem'
      STQMEKF_EnabledSubsystem_Update(STQMEKF_B.dy_k,
        &STQMEKF_B.EnabledSubsystem_m, &STQMEKF_DW.EnabledSubsystem_m);

      // End of Update for SubSystem: '<S183>/Enabled Subsystem'

      // Update for Delay: '<S192>/Delay2'
      STQMEKF_DW.Delay2_DSTATE_l = STQMEKF_B.ReceivePhaseSpaceData_o1[0];

      // Update for Delay: '<S192>/Delay1'
      STQMEKF_DW.Delay1_DSTATE_l = STQMEKF_B.ConvertBLUXfrommmtom;

      // Update for Enabled SubSystem: '<S194>/Enabled Subsystem'
      STQME_EnabledSubsystem_n_Update(STQMEKF_B.dy_c,
        &STQMEKF_B.EnabledSubsystem_g, &STQMEKF_DW.EnabledSubsystem_g);

      // End of Update for SubSystem: '<S194>/Enabled Subsystem'

      // Update for Delay: '<S193>/Delay1'
      STQMEKF_DW.Delay1_DSTATE_lv[0] = STQMEKF_B.dy_c[0];
      STQMEKF_DW.Delay1_DSTATE_lv[1] = STQMEKF_B.dy_c[1];
      STQMEKF_DW.Delay1_DSTATE_lv[2] = STQMEKF_B.dy_c[2];

      // Update for Enabled SubSystem: '<S193>/Enabled Subsystem'
      STQMEKF_EnabledSubsystem_Update(STQMEKF_B.dy_e,
        &STQMEKF_B.EnabledSubsystem_l, &STQMEKF_DW.EnabledSubsystem_l);

      // End of Update for SubSystem: '<S193>/Enabled Subsystem'

      // Update for Delay: '<S202>/Delay2'
      STQMEKF_DW.Delay2_DSTATE_l0 = STQMEKF_B.ReceivePhaseSpaceData_o1[0];

      // Update for Delay: '<S202>/Delay1'
      STQMEKF_DW.Delay1_DSTATE_ld = STQMEKF_B.ConvertREDXfrommmtom;

      // Update for Enabled SubSystem: '<S204>/Enabled Subsystem'
      STQME_EnabledSubsystem_n_Update(STQMEKF_B.dy,
        &STQMEKF_B.EnabledSubsystem_a, &STQMEKF_DW.EnabledSubsystem_a);

      // End of Update for SubSystem: '<S204>/Enabled Subsystem'

      // Update for Delay: '<S203>/Delay1'
      STQMEKF_DW.Delay1_DSTATE_cq[0] = STQMEKF_B.dy[0];
      STQMEKF_DW.Delay1_DSTATE_cq[1] = STQMEKF_B.dy[1];
      STQMEKF_DW.Delay1_DSTATE_cq[2] = STQMEKF_B.dy[2];

      // Update for Enabled SubSystem: '<S203>/Enabled Subsystem'
      STQMEKF_EnabledSubsystem_Update(STQMEKF_B.dy_l,
        &STQMEKF_B.EnabledSubsystem_k, &STQMEKF_DW.EnabledSubsystem_k);

      // End of Update for SubSystem: '<S203>/Enabled Subsystem'

      // Update for Delay: '<S178>/Delay'
      STQMEKF_DW.Delay_DSTATE_i[0] = STQMEKF_DW.Delay_DSTATE_i[1];

      // Update for Delay: '<S178>/Delay1'
      STQMEKF_DW.Delay1_DSTATE_h[0] = STQMEKF_DW.Delay1_DSTATE_h[1];

      // Update for Delay: '<S178>/Delay2'
      STQMEKF_DW.Delay2_DSTATE_hq[0] = STQMEKF_DW.Delay2_DSTATE_hq[1];

      // Update for Delay: '<S178>/Delay'
      STQMEKF_DW.Delay_DSTATE_i[1] = STQMEKF_DW.Delay_DSTATE_i[2];

      // Update for Delay: '<S178>/Delay1'
      STQMEKF_DW.Delay1_DSTATE_h[1] = STQMEKF_DW.Delay1_DSTATE_h[2];

      // Update for Delay: '<S178>/Delay2'
      STQMEKF_DW.Delay2_DSTATE_hq[1] = STQMEKF_DW.Delay2_DSTATE_hq[2];

      // Update for Delay: '<S178>/Delay'
      STQMEKF_DW.Delay_DSTATE_i[2] = STQMEKF_DW.Delay_DSTATE_i[3];

      // Update for Delay: '<S178>/Delay1'
      STQMEKF_DW.Delay1_DSTATE_h[2] = STQMEKF_DW.Delay1_DSTATE_h[3];

      // Update for Delay: '<S178>/Delay2'
      STQMEKF_DW.Delay2_DSTATE_hq[2] = STQMEKF_DW.Delay2_DSTATE_hq[3];

      // Update for Delay: '<S178>/Delay'
      STQMEKF_DW.Delay_DSTATE_i[3] = STQMEKF_DW.Delay_DSTATE_i[4];

      // Update for Delay: '<S178>/Delay1'
      STQMEKF_DW.Delay1_DSTATE_h[3] = STQMEKF_DW.Delay1_DSTATE_h[4];

      // Update for Delay: '<S178>/Delay2'
      STQMEKF_DW.Delay2_DSTATE_hq[3] = STQMEKF_DW.Delay2_DSTATE_hq[4];

      // Update for Delay: '<S178>/Delay'
      STQMEKF_DW.Delay_DSTATE_i[4] = STQMEKF_B.UDPReceive_o1;

      // Update for Delay: '<S178>/Delay1'
      STQMEKF_DW.Delay1_DSTATE_h[4] = STQMEKF_B.UDPReceive2_o1;

      // Update for Delay: '<S178>/Delay2'
      STQMEKF_DW.Delay2_DSTATE_hq[4] = STQMEKF_B.UDPReceive3_o1;

      // Update for Enabled SubSystem: '<S177>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S179>/Enable'

      if (STQMEKF_B.RelationalOperator1) {
        // Update for Memory: '<S179>/Memory'
        STQMEKF_DW.Memory_PreviousInput = STQMEKF_B.Clock;
      }

      // End of Update for SubSystem: '<S177>/Enabled Subsystem'
      // End of Update for SubSystem: '<S10>/Use Hardware to Obtain States'
    }

    // End of Update for If: '<S10>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 

    // Update for S-Function (sdspToNetwork): '<S17>/UDP Send' incorporates:
    //   SignalConversion generated from: '<S17>/UDP Send'

    sErr = GetErrorBuffer(&STQMEKF_DW.UDPSend_NetworkLib[0U]);
    LibUpdate_Network(&STQMEKF_DW.UDPSend_NetworkLib[0U],
                      &STQMEKF_B.TmpSignalConversionAtUDPSendInp[0U], 10);
    if (*sErr != 0) {
      STQMEKF_M->setErrorStatus(sErr);
      STQMEKF_M->setStopRequested(1);
    }

    // End of Update for S-Function (sdspToNetwork): '<S17>/UDP Send'
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  STQMEKF_M->Timing.t[0] =
    ((time_T)(++STQMEKF_M->Timing.clockTick0)) * STQMEKF_M->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.05s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.05, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    STQMEKF_M->Timing.clockTick1++;
  }
}

// Model initialize function
void STQMEKF_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&STQMEKF_M->solverInfo, &STQMEKF_M->Timing.simTimeStep);
    rtsiSetTPtr(&STQMEKF_M->solverInfo, STQMEKF_M->getTPtrPtr());
    rtsiSetStepSizePtr(&STQMEKF_M->solverInfo, &STQMEKF_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&STQMEKF_M->solverInfo, STQMEKF_M->getErrorStatusPtr());
    rtsiSetRTModelPtr(&STQMEKF_M->solverInfo, STQMEKF_M);
  }

  rtsiSetSimTimeStep(&STQMEKF_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&STQMEKF_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&STQMEKF_M->solverInfo, false);
  rtsiSetSolverName(&STQMEKF_M->solverInfo,"FixedStepDiscrete");
  STQMEKF_M->setTPtr(&STQMEKF_M->Timing.tArray[0]);
  STQMEKF_M->Timing.stepSize0 = 0.05;

  {
    real_T sampleTime;
    real_T sampleTime_0;
    real_T sampleTime_1;
    int32_T i;
    char_T *sErr;

    // Start for If: '<S10>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 
    STQMEKF_DW.Ifperforminganexperimentgrabthe = -1;

    // Start for S-Function (sdspToNetwork): '<S17>/UDP Send'
    sErr = GetErrorBuffer(&STQMEKF_DW.UDPSend_NetworkLib[0U]);
    CreateUDPInterface(&STQMEKF_DW.UDPSend_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&STQMEKF_DW.UDPSend_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "127.0.0.1", STQMEKF_P.UDPSend_Port_h, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&STQMEKF_DW.UDPSend_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&STQMEKF_DW.UDPSend_NetworkLib[0U]);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S17>/UDP Send'

    // Start for DataStoreMemory: '<Root>/RED_Tz1'
    STQMEKF_DW.BLUE_Control_Law_Enabler = STQMEKF_P.RED_Tz1_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz15'
    STQMEKF_DW.ARM_Control_Mode = STQMEKF_P.RED_Tz15_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz20'
    STQMEKF_DW.RED_Control_Law_Enabler = STQMEKF_P.RED_Tz20_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz25'
    STQMEKF_DW.RED_Path_Planner_Selection = STQMEKF_P.RED_Tz25_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz3'
    strncpy(&STQMEKF_DW.RED_Logger[0], &STQMEKF_P.RED_Tz3_InitialValue[0], 255U);
    STQMEKF_DW.RED_Logger[255] = '\x00';

    // Start for DataStoreMemory: '<Root>/RED_Tz38'
    STQMEKF_DW.ARM_Control_Law_Enabler = STQMEKF_P.RED_Tz38_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz7'
    STQMEKF_DW.Float_State = STQMEKF_P.RED_Tz7_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz8'
    STQMEKF_DW.BLACK_Control_Law_Enabler = STQMEKF_P.RED_Tz8_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz9'
    STQMEKF_DW.BLACK_Path_Planner_Selection = STQMEKF_P.RED_Tz9_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time'
    STQMEKF_DW.Univ_Time = STQMEKF_P.Universal_Time_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time10'
    memcpy(&STQMEKF_DW.BLACK_Measured_States[0],
           &STQMEKF_P.Universal_Time10_InitialValue[0], 9U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Universal_Time14'
    STQMEKF_DW.BLUE_Thruster_ON_Count = STQMEKF_P.Universal_Time14_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time13'
    STQMEKF_DW.BLUE_Desired_States[0] = STQMEKF_P.Universal_Time13_InitialValue
      [0];

    // Start for DataStoreMemory: '<Root>/Universal_Time15'
    STQMEKF_DW.BLACK_Saturated_Controls[0] =
      STQMEKF_P.Universal_Time15_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time13'
    STQMEKF_DW.BLUE_Desired_States[1] = STQMEKF_P.Universal_Time13_InitialValue
      [1];

    // Start for DataStoreMemory: '<Root>/Universal_Time15'
    STQMEKF_DW.BLACK_Saturated_Controls[1] =
      STQMEKF_P.Universal_Time15_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time13'
    STQMEKF_DW.BLUE_Desired_States[2] = STQMEKF_P.Universal_Time13_InitialValue
      [2];

    // Start for DataStoreMemory: '<Root>/Universal_Time15'
    STQMEKF_DW.BLACK_Saturated_Controls[2] =
      STQMEKF_P.Universal_Time15_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time16'
    STQMEKF_DW.RED_Thruster_ON_Count = STQMEKF_P.Universal_Time16_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time19'
    STQMEKF_DW.WhoAmI = STQMEKF_P.Universal_Time19_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time20'
    STQMEKF_DW.isSim = STQMEKF_P.Universal_Time20_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time24'
    for (i = 0; i < 6; i++) {
      STQMEKF_DW.ARM_Measured_States[i] =
        STQMEKF_P.Universal_Time24_InitialValue[i];
    }

    // End of Start for DataStoreMemory: '<Root>/Universal_Time24'

    // Start for DataStoreMemory: '<Root>/Universal_Time25'
    STQMEKF_DW.BLACK_Desired_States[0] =
      STQMEKF_P.Universal_Time25_InitialValue[0];
    STQMEKF_DW.BLACK_Desired_States[1] =
      STQMEKF_P.Universal_Time25_InitialValue[1];
    STQMEKF_DW.BLACK_Desired_States[2] =
      STQMEKF_P.Universal_Time25_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time3'
    STQMEKF_DW.BLACK_Thruster_ON_Count = STQMEKF_P.Universal_Time3_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time28'
    STQMEKF_DW.RED_Saturated_Controls[0] =
      STQMEKF_P.Universal_Time28_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time29'
    STQMEKF_DW.RED_Desired_States[0] = STQMEKF_P.Universal_Time29_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time31'
    STQMEKF_DW.RED_IMU_Measurements[0] =
      STQMEKF_P.Universal_Time31_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time33'
    STQMEKF_DW.BLACK_IMU_Measurements[0] =
      STQMEKF_P.Universal_Time33_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time34'
    STQMEKF_DW.BLUE_IMU_Measurements[0] =
      STQMEKF_P.Universal_Time34_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time28'
    STQMEKF_DW.RED_Saturated_Controls[1] =
      STQMEKF_P.Universal_Time28_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time29'
    STQMEKF_DW.RED_Desired_States[1] = STQMEKF_P.Universal_Time29_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time31'
    STQMEKF_DW.RED_IMU_Measurements[1] =
      STQMEKF_P.Universal_Time31_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time33'
    STQMEKF_DW.BLACK_IMU_Measurements[1] =
      STQMEKF_P.Universal_Time33_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time34'
    STQMEKF_DW.BLUE_IMU_Measurements[1] =
      STQMEKF_P.Universal_Time34_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time28'
    STQMEKF_DW.RED_Saturated_Controls[2] =
      STQMEKF_P.Universal_Time28_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time29'
    STQMEKF_DW.RED_Desired_States[2] = STQMEKF_P.Universal_Time29_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time31'
    STQMEKF_DW.RED_IMU_Measurements[2] =
      STQMEKF_P.Universal_Time31_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time33'
    STQMEKF_DW.BLACK_IMU_Measurements[2] =
      STQMEKF_P.Universal_Time33_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time34'
    STQMEKF_DW.BLUE_IMU_Measurements[2] =
      STQMEKF_P.Universal_Time34_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time38'
    STQMEKF_DW.Confidance = STQMEKF_P.Universal_Time38_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time26'
    memcpy(&STQMEKF_DW.RED_Measured_States[0],
           &STQMEKF_P.Universal_Time26_InitialValue[0], 9U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Universal_Time4'
    memcpy(&STQMEKF_DW.BLUE_Measured_States[0],
           &STQMEKF_P.Universal_Time4_InitialValue[0], 9U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Universal_Time6'
    STQMEKF_DW.BLUE_Saturated_Controls[0] =
      STQMEKF_P.Universal_Time6_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time8'
    STQMEKF_DW.ARM_Desired_States[0] = STQMEKF_P.Universal_Time8_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time6'
    STQMEKF_DW.BLUE_Saturated_Controls[1] =
      STQMEKF_P.Universal_Time6_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time8'
    STQMEKF_DW.ARM_Desired_States[1] = STQMEKF_P.Universal_Time8_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time6'
    STQMEKF_DW.BLUE_Saturated_Controls[2] =
      STQMEKF_P.Universal_Time6_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time8'
    STQMEKF_DW.ARM_Desired_States[2] = STQMEKF_P.Universal_Time8_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time9'
    for (i = 0; i < 7; i++) {
      STQMEKF_DW.BLACK_States_Vis_raw[i] =
        STQMEKF_P.Universal_Time9_InitialValue[i];
    }

    // End of Start for DataStoreMemory: '<Root>/Universal_Time9'

    // InitializeConditions for Delay: '<S217>/Delay1'
    STQMEKF_DW.Delay1_DSTATE = STQMEKF_P.Delay1_InitialCondition_o;

    // InitializeConditions for Delay: '<S217>/Delay'
    STQMEKF_DW.Delay_DSTATE = STQMEKF_P.Delay_InitialCondition_h;

    // InitializeConditions for Delay: '<S218>/Delay2'
    memcpy(&STQMEKF_DW.Delay2_DSTATE[0], &STQMEKF_P.Delay2_InitialCondition_h[0],
           13U * sizeof(real_T));

    // InitializeConditions for Delay: '<S218>/Delay1'
    memcpy(&STQMEKF_DW.Delay1_DSTATE_n[0],
           &STQMEKF_P.Delay1_InitialCondition_jf[0], 144U * sizeof(real_T));

    // InitializeConditions for Delay: '<S218>/Delay3'
    memcpy(&STQMEKF_DW.Delay3_DSTATE[0], &STQMEKF_P.Delay3_InitialCondition[0],
           36U * sizeof(real_T));

    // SystemInitialize for IfAction SubSystem: '<S3>/Default PD Control (BLACK)' 
    // InitializeConditions for UnitDelay: '<S145>/UD'
    //
    //  Block description for '<S145>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_eh = STQMEKF_P.DiscreteDerivative_ICPrevScal_p;

    // InitializeConditions for UnitDelay: '<S146>/UD'
    //
    //  Block description for '<S146>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_hv = STQMEKF_P.DiscreteDerivative1_ICPrevSca_m;

    // InitializeConditions for UnitDelay: '<S147>/UD'
    //
    //  Block description for '<S147>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_kv = STQMEKF_P.DiscreteDerivative2_ICPrevSca_a;

    // End of SystemInitialize for SubSystem: '<S3>/Default PD Control (BLACK)'

    // SystemInitialize for IfAction SubSystem: '<S3>/Default LQR Control (BLACK)' 
    // InitializeConditions for UnitDelay: '<S122>/UD'
    //
    //  Block description for '<S122>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_j = STQMEKF_P.DiscreteDerivative_ICPrevScal_d;

    // InitializeConditions for UnitDelay: '<S123>/UD'
    //
    //  Block description for '<S123>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_c = STQMEKF_P.DiscreteDerivative1_ICPrevSca_i;

    // InitializeConditions for UnitDelay: '<S124>/UD'
    //
    //  Block description for '<S124>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_d = STQMEKF_P.DiscreteDerivative2_ICPrevSc_oo;

    // End of SystemInitialize for SubSystem: '<S3>/Default LQR Control (BLACK)' 

    // SystemInitialize for IfAction SubSystem: '<S3>/Default PD Control (BLUE)' 
    // InitializeConditions for UnitDelay: '<S150>/UD'
    //
    //  Block description for '<S150>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_o = STQMEKF_P.DiscreteDerivative_ICPrevSca_pf;

    // InitializeConditions for UnitDelay: '<S151>/UD'
    //
    //  Block description for '<S151>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_n = STQMEKF_P.DiscreteDerivative1_ICPrevSca_l;

    // InitializeConditions for UnitDelay: '<S152>/UD'
    //
    //  Block description for '<S152>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_hu = STQMEKF_P.DiscreteDerivative2_ICPrevSc_on;

    // End of SystemInitialize for SubSystem: '<S3>/Default PD Control (BLUE)'

    // SystemInitialize for IfAction SubSystem: '<S3>/Default LQR Control (BLUE)' 
    // InitializeConditions for UnitDelay: '<S127>/UD'
    //
    //  Block description for '<S127>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_l = STQMEKF_P.DiscreteDerivative_ICPrevScal_n;

    // InitializeConditions for UnitDelay: '<S128>/UD'
    //
    //  Block description for '<S128>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_k = STQMEKF_P.DiscreteDerivative1_ICPrevSca_f;

    // InitializeConditions for UnitDelay: '<S129>/UD'
    //
    //  Block description for '<S129>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_h = STQMEKF_P.DiscreteDerivative2_ICPrevSca_g;

    // End of SystemInitialize for SubSystem: '<S3>/Default LQR Control (BLUE)'

    // SystemInitialize for IfAction SubSystem: '<S3>/Default PD (ARM)'
    // SystemInitialize for IfAction SubSystem: '<S113>/Simulated Position Controller' 
    // InitializeConditions for UnitDelay: '<S141>/UD'
    //
    //  Block description for '<S141>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE = STQMEKF_P.DiscreteDerivative1_ICPrevSca_j;

    // InitializeConditions for UnitDelay: '<S142>/UD'
    //
    //  Block description for '<S142>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_e = STQMEKF_P.DiscreteDerivative1_ICPrevSca_a;

    // InitializeConditions for UnitDelay: '<S143>/UD'
    //
    //  Block description for '<S143>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_a = STQMEKF_P.DiscreteDerivative1_ICPrevSca_k;

    // End of SystemInitialize for SubSystem: '<S113>/Simulated Position Controller' 
    // End of SystemInitialize for SubSystem: '<S3>/Default PD (ARM)'

    // SystemInitialize for IfAction SubSystem: '<S3>/Default PD Control (RED)'
    // InitializeConditions for UnitDelay: '<S155>/UD'
    //
    //  Block description for '<S155>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_eg = STQMEKF_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for UnitDelay: '<S156>/UD'
    //
    //  Block description for '<S156>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_cd = STQMEKF_P.DiscreteDerivative1_ICPrevScale;

    // InitializeConditions for UnitDelay: '<S157>/UD'
    //
    //  Block description for '<S157>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_hd = STQMEKF_P.DiscreteDerivative2_ICPrevScale;

    // End of SystemInitialize for SubSystem: '<S3>/Default PD Control (RED)'

    // SystemInitialize for IfAction SubSystem: '<S3>/Default LQR Control (RED)' 
    // InitializeConditions for UnitDelay: '<S132>/UD'
    //
    //  Block description for '<S132>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_aq = STQMEKF_P.DiscreteDerivative_ICPrevScal_i;

    // InitializeConditions for UnitDelay: '<S133>/UD'
    //
    //  Block description for '<S133>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_p = STQMEKF_P.DiscreteDerivative1_ICPrevSca_e;

    // InitializeConditions for UnitDelay: '<S134>/UD'
    //
    //  Block description for '<S134>/UD':
    //
    //   Store in Global RAM

    STQMEKF_DW.UD_DSTATE_pr = STQMEKF_P.DiscreteDerivative2_ICPrevSca_o;

    // End of SystemInitialize for SubSystem: '<S3>/Default LQR Control (RED)'

    // SystemInitialize for Merge: '<S3>/Merge1'
    STQMEKF_B.Merge1[0] = STQMEKF_P.Merge1_InitialOutput;

    // SystemInitialize for Merge: '<S3>/Merge2'
    STQMEKF_B.Merge2[0] = STQMEKF_P.Merge2_InitialOutput;

    // SystemInitialize for Merge: '<S3>/Merge'
    STQMEKF_B.Merge[0] = STQMEKF_P.Merge_InitialOutput;

    // SystemInitialize for Merge: '<S3>/Merge1'
    STQMEKF_B.Merge1[1] = STQMEKF_P.Merge1_InitialOutput;

    // SystemInitialize for Merge: '<S3>/Merge2'
    STQMEKF_B.Merge2[1] = STQMEKF_P.Merge2_InitialOutput;

    // SystemInitialize for Merge: '<S3>/Merge'
    STQMEKF_B.Merge[1] = STQMEKF_P.Merge_InitialOutput;

    // SystemInitialize for Merge: '<S3>/Merge1'
    STQMEKF_B.Merge1[2] = STQMEKF_P.Merge1_InitialOutput;

    // SystemInitialize for Merge: '<S3>/Merge2'
    STQMEKF_B.Merge2[2] = STQMEKF_P.Merge2_InitialOutput;

    // SystemInitialize for Merge: '<S3>/Merge'
    STQMEKF_B.Merge[2] = STQMEKF_P.Merge_InitialOutput;

    // SystemInitialize for IfAction SubSystem: '<S4>/Change BLACK Behavior'
    STQMEK_ChangeBLACKBehavior_Init(STQMEKF_M, &STQMEKF_DW.ChangeBLACKBehavior,
      &STQMEKF_P.ChangeBLACKBehavior);

    // End of SystemInitialize for SubSystem: '<S4>/Change BLACK Behavior'

    // SystemInitialize for IfAction SubSystem: '<S4>/Change BLUE Behavior'
    STQMEK_ChangeBLACKBehavior_Init(STQMEKF_M, &STQMEKF_DW.ChangeBLUEBehavior,
      &STQMEKF_P.ChangeBLUEBehavior);

    // End of SystemInitialize for SubSystem: '<S4>/Change BLUE Behavior'

    // SystemInitialize for IfAction SubSystem: '<S4>/Change RED Behavior'
    STQMEK_ChangeBLACKBehavior_Init(STQMEKF_M, &STQMEKF_DW.ChangeREDBehavior,
      &STQMEKF_P.ChangeREDBehavior);

    // End of SystemInitialize for SubSystem: '<S4>/Change RED Behavior'

    // SystemInitialize for IfAction SubSystem: '<S6>/Change BLACK Behavior'
    // Start for S-Function (sdspToNetwork): '<S164>/UDP Send1'
    sErr = GetErrorBuffer(&STQMEKF_DW.UDPSend1_NetworkLib[0U]);
    CreateUDPInterface(&STQMEKF_DW.UDPSend1_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&STQMEKF_DW.UDPSend1_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "255.255.255.255", STQMEKF_P.UDPSend1_Port, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&STQMEKF_DW.UDPSend1_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&STQMEKF_DW.UDPSend1_NetworkLib[0U]);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S164>/UDP Send1'
    // End of SystemInitialize for SubSystem: '<S6>/Change BLACK Behavior'

    // SystemInitialize for IfAction SubSystem: '<S6>/Change BLUE Behavior'
    // Start for S-Function (sdspToNetwork): '<S165>/UDP Send2'
    sErr = GetErrorBuffer(&STQMEKF_DW.UDPSend2_NetworkLib[0U]);
    CreateUDPInterface(&STQMEKF_DW.UDPSend2_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&STQMEKF_DW.UDPSend2_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "255.255.255.255", STQMEKF_P.UDPSend2_Port, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&STQMEKF_DW.UDPSend2_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&STQMEKF_DW.UDPSend2_NetworkLib[0U]);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S165>/UDP Send2'
    // End of SystemInitialize for SubSystem: '<S6>/Change BLUE Behavior'

    // SystemInitialize for IfAction SubSystem: '<S6>/Change RED Behavior'
    // Start for S-Function (sdspToNetwork): '<S166>/UDP Send3'
    sErr = GetErrorBuffer(&STQMEKF_DW.UDPSend3_NetworkLib[0U]);
    CreateUDPInterface(&STQMEKF_DW.UDPSend3_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&STQMEKF_DW.UDPSend3_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "255.255.255.255", STQMEKF_P.UDPSend3_Port, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&STQMEKF_DW.UDPSend3_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&STQMEKF_DW.UDPSend3_NetworkLib[0U]);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S166>/UDP Send3'
    // End of SystemInitialize for SubSystem: '<S6>/Change RED Behavior'

    // SystemInitialize for IfAction SubSystem: '<S7>/Enable Pucks'
    // Start for MATLABSystem: '<S167>/GPIO Write1'
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    STQMEKF_DW.obj_c.matlabCodegenIsDeleted = false;
    STQMEKF_DW.obj_c.gpioPin = STQMEKF_P.GPIOWrite1_gpioPin;
    STQMEKF_DW.obj_c.pinDirection = STQMEKF_P.GPIOWrite1_pinDirection;
    STQMEKF_DW.obj_c.isInitialized = 1;

    //         %% Define input properties
    //  Call C-function implementing device initialization
    export_gpio(STQMEKF_DW.obj_c.gpioPin);
    set_pin_direction(STQMEKF_DW.obj_c.gpioPin, STQMEKF_DW.obj_c.pinDirection);
    STQMEKF_DW.obj_c.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S7>/Enable Pucks'

    // SystemInitialize for IfAction SubSystem: '<S8>/Log Gyro//Accel'
    // Start for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
    STQMEKF_DW.obj._pobj2.matlabCodegenIsDeleted = true;
    STQMEKF_DW.obj.isInitialized = 0;
    STQMEKF_DW.obj.matlabCodegenIsDeleted = false;
    STQMEKF_DW.obj.SampleTime = STQMEKF_P.GyroscopeAccelerometer_SampleTi;
    STQMEKF_SystemCore_setup(&STQMEKF_DW.obj);

    // End of SystemInitialize for SubSystem: '<S8>/Log Gyro//Accel'

    // SystemInitialize for IfAction SubSystem: '<S9>/Change ARM Behavior'
    // InitializeConditions for Delay: '<S170>/Delay'
    STQMEKF_DW.Delay_DSTATE_o = STQMEKF_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S170>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_cg = STQMEKF_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S170>/Delay2'
    STQMEKF_DW.Delay2_DSTATE_h = STQMEKF_P.Delay2_InitialCondition;

    // Start for MATLABSystem: '<S170>/Read Joint Positions using  Dynamixel Encoders' 
    STQMEKF_DW.obj_d.matlabCodegenIsDeleted = false;
    if (((!rtIsInf(STQMEKF_P.baseRate)) && (!rtIsNaN(STQMEKF_P.baseRate))) ||
        rtIsInf(STQMEKF_P.baseRate)) {
      sampleTime = STQMEKF_P.baseRate;
    }

    STQMEKF_DW.obj_d.SampleTime = sampleTime;
    STQMEKF_DW.obj_d.isInitialized = 1;

    //         %% Define input properties
    //  Call C-function implementing device initialization
    STQMEKF_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S170>/Read Joint Positions using  Dynamixel Encoders' 
    // End of SystemInitialize for SubSystem: '<S9>/Change ARM Behavior'

    // SystemInitialize for IfAction SubSystem: '<S10>/Use Hardware to Obtain States' 
    // Start for S-Function (sdspFromNetwork): '<S173>/Receive PhaseSpace Data'
    sErr = GetErrorBuffer(&STQMEKF_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
    CreateUDPInterface(&STQMEKF_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&STQMEKF_DW.ReceivePhaseSpaceData_NetworkLi[0U], 0,
                        "0.0.0.0", STQMEKF_P.ReceivePhaseSpaceData_Port,
                        "0.0.0.0", -1, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&STQMEKF_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&STQMEKF_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S173>/Receive PhaseSpace Data' 

    // Start for S-Function (sdspFromNetwork): '<S178>/UDP Receive'
    sErr = GetErrorBuffer(&STQMEKF_DW.UDPReceive_NetworkLib[0U]);
    CreateUDPInterface(&STQMEKF_DW.UDPReceive_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&STQMEKF_DW.UDPReceive_NetworkLib[0U], 0, "0.0.0.0",
                        STQMEKF_P.UDPReceive_Port, "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&STQMEKF_DW.UDPReceive_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&STQMEKF_DW.UDPReceive_NetworkLib[0U]);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S178>/UDP Receive'

    // Start for S-Function (sdspFromNetwork): '<S178>/UDP Receive2'
    sErr = GetErrorBuffer(&STQMEKF_DW.UDPReceive2_NetworkLib[0U]);
    CreateUDPInterface(&STQMEKF_DW.UDPReceive2_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&STQMEKF_DW.UDPReceive2_NetworkLib[0U], 0, "0.0.0.0",
                        STQMEKF_P.UDPReceive2_Port, "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&STQMEKF_DW.UDPReceive2_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&STQMEKF_DW.UDPReceive2_NetworkLib[0U]);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S178>/UDP Receive2'

    // Start for S-Function (sdspFromNetwork): '<S178>/UDP Receive3'
    sErr = GetErrorBuffer(&STQMEKF_DW.UDPReceive3_NetworkLib[0U]);
    CreateUDPInterface(&STQMEKF_DW.UDPReceive3_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&STQMEKF_DW.UDPReceive3_NetworkLib[0U], 0, "0.0.0.0",
                        STQMEKF_P.UDPReceive3_Port, "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&STQMEKF_DW.UDPReceive3_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&STQMEKF_DW.UDPReceive3_NetworkLib[0U]);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S178>/UDP Receive3'

    // InitializeConditions for Delay: '<S182>/Delay2'
    STQMEKF_DW.Delay2_DSTATE_j = STQMEKF_P.Delay2_InitialCondition_e;

    // InitializeConditions for Delay: '<S182>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_i = STQMEKF_P.Delay1_InitialCondition_m;

    // InitializeConditions for Delay: '<S192>/Delay2'
    STQMEKF_DW.Delay2_DSTATE_l = STQMEKF_P.Delay2_InitialCondition_a;

    // InitializeConditions for Delay: '<S192>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_l = STQMEKF_P.Delay1_InitialCondition_i3;

    // InitializeConditions for Delay: '<S202>/Delay2'
    STQMEKF_DW.Delay2_DSTATE_l0 = STQMEKF_P.Delay2_InitialCondition_m;

    // InitializeConditions for Delay: '<S202>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_ld = STQMEKF_P.Delay1_InitialCondition_l;

    // InitializeConditions for Delay: '<S184>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_g[0] = STQMEKF_P.Delay1_InitialCondition_i;

    // InitializeConditions for Delay: '<S183>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_b[0] = STQMEKF_P.Delay1_InitialCondition_it;

    // InitializeConditions for Delay: '<S194>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_m[0] = STQMEKF_P.Delay1_InitialCondition_h;

    // InitializeConditions for Delay: '<S193>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_lv[0] = STQMEKF_P.Delay1_InitialCondition_j;

    // InitializeConditions for Delay: '<S204>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_c[0] = STQMEKF_P.Delay1_InitialCondition_k;

    // InitializeConditions for Delay: '<S203>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_cq[0] = STQMEKF_P.Delay1_InitialCondition_c;

    // InitializeConditions for Delay: '<S184>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_g[1] = STQMEKF_P.Delay1_InitialCondition_i;

    // InitializeConditions for Delay: '<S183>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_b[1] = STQMEKF_P.Delay1_InitialCondition_it;

    // InitializeConditions for Delay: '<S194>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_m[1] = STQMEKF_P.Delay1_InitialCondition_h;

    // InitializeConditions for Delay: '<S193>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_lv[1] = STQMEKF_P.Delay1_InitialCondition_j;

    // InitializeConditions for Delay: '<S204>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_c[1] = STQMEKF_P.Delay1_InitialCondition_k;

    // InitializeConditions for Delay: '<S203>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_cq[1] = STQMEKF_P.Delay1_InitialCondition_c;

    // InitializeConditions for Delay: '<S184>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_g[2] = STQMEKF_P.Delay1_InitialCondition_i;

    // InitializeConditions for Delay: '<S183>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_b[2] = STQMEKF_P.Delay1_InitialCondition_it;

    // InitializeConditions for Delay: '<S194>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_m[2] = STQMEKF_P.Delay1_InitialCondition_h;

    // InitializeConditions for Delay: '<S193>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_lv[2] = STQMEKF_P.Delay1_InitialCondition_j;

    // InitializeConditions for Delay: '<S204>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_c[2] = STQMEKF_P.Delay1_InitialCondition_k;

    // InitializeConditions for Delay: '<S203>/Delay1'
    STQMEKF_DW.Delay1_DSTATE_cq[2] = STQMEKF_P.Delay1_InitialCondition_c;
    for (i = 0; i < 5; i++) {
      // InitializeConditions for Delay: '<S178>/Delay'
      STQMEKF_DW.Delay_DSTATE_i[i] = STQMEKF_P.Delay_InitialCondition_j;

      // InitializeConditions for Delay: '<S178>/Delay1'
      STQMEKF_DW.Delay1_DSTATE_h[i] = STQMEKF_P.Delay1_InitialCondition_d;

      // InitializeConditions for Delay: '<S178>/Delay2'
      STQMEKF_DW.Delay2_DSTATE_hq[i] = STQMEKF_P.Delay2_InitialCondition_ak;
    }

    // SystemInitialize for Enabled SubSystem: '<S182>/Enabled Subsystem3'
    // SystemInitialize for SignalConversion generated from: '<S186>/y2-y1' incorporates:
    //   Outport: '<S186>/dy(t)//dt'

    STQMEKF_B.y2y1_ob = STQMEKF_P.dytdt_Y0;

    // End of SystemInitialize for SubSystem: '<S182>/Enabled Subsystem3'

    // SystemInitialize for Enabled SubSystem: '<S184>/Enabled Subsystem'
    STQMEKF_EnabledSubsystem_e_Init(STQMEKF_B.dy_i,
      &STQMEKF_DW.EnabledSubsystem_n, &STQMEKF_P.EnabledSubsystem_n);

    // End of SystemInitialize for SubSystem: '<S184>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S183>/Enabled Subsystem'
    STQMEKF_EnabledSubsystem_Init(STQMEKF_B.dy_k, &STQMEKF_DW.EnabledSubsystem_m,
      &STQMEKF_P.EnabledSubsystem_m);

    // End of SystemInitialize for SubSystem: '<S183>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S192>/Enabled Subsystem3'
    // SystemInitialize for SignalConversion generated from: '<S196>/y2-y1' incorporates:
    //   Outport: '<S196>/dy(t)//dt'

    STQMEKF_B.y2y1_o = STQMEKF_P.dytdt_Y0_j;

    // End of SystemInitialize for SubSystem: '<S192>/Enabled Subsystem3'

    // SystemInitialize for Enabled SubSystem: '<S194>/Enabled Subsystem'
    STQMEKF_EnabledSubsystem_e_Init(STQMEKF_B.dy_c,
      &STQMEKF_DW.EnabledSubsystem_g, &STQMEKF_P.EnabledSubsystem_g);

    // End of SystemInitialize for SubSystem: '<S194>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S193>/Enabled Subsystem'
    STQMEKF_EnabledSubsystem_Init(STQMEKF_B.dy_e, &STQMEKF_DW.EnabledSubsystem_l,
      &STQMEKF_P.EnabledSubsystem_l);

    // End of SystemInitialize for SubSystem: '<S193>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S202>/Enabled Subsystem3'
    // SystemInitialize for SignalConversion generated from: '<S206>/y2-y1' incorporates:
    //   Outport: '<S206>/dy(t)//dt'

    STQMEKF_B.y2y1 = STQMEKF_P.dytdt_Y0_d;

    // End of SystemInitialize for SubSystem: '<S202>/Enabled Subsystem3'

    // SystemInitialize for Enabled SubSystem: '<S204>/Enabled Subsystem'
    STQMEKF_EnabledSubsystem_e_Init(STQMEKF_B.dy, &STQMEKF_DW.EnabledSubsystem_a,
      &STQMEKF_P.EnabledSubsystem_a);

    // End of SystemInitialize for SubSystem: '<S204>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S203>/Enabled Subsystem'
    STQMEKF_EnabledSubsystem_Init(STQMEKF_B.dy_l, &STQMEKF_DW.EnabledSubsystem_k,
      &STQMEKF_P.EnabledSubsystem_k);

    // End of SystemInitialize for SubSystem: '<S203>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S177>/Enabled Subsystem'
    // InitializeConditions for Memory: '<S179>/Memory'
    STQMEKF_DW.Memory_PreviousInput = STQMEKF_P.Memory_InitialCondition;

    // SystemInitialize for Memory: '<S179>/Memory' incorporates:
    //   Outport: '<S179>/Out1'

    STQMEKF_B.Memory = STQMEKF_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S177>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S177>/Enabled Subsystem1'
    // SystemInitialize for Sum: '<S180>/Subtract' incorporates:
    //   Outport: '<S180>/Out1'

    STQMEKF_B.Subtract = STQMEKF_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S177>/Enabled Subsystem1'
    // End of SystemInitialize for SubSystem: '<S10>/Use Hardware to Obtain States' 

    // SystemInitialize for IfAction SubSystem: '<S11>/Subsystem'
    // Start for MATLABSystem: '<S212>/WhoAmI'
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    STQMEKF_DW.obj_dk.matlabCodegenIsDeleted = false;
    if (((!rtIsInf(STQMEKF_P.baseRate)) && (!rtIsNaN(STQMEKF_P.baseRate))) ||
        rtIsInf(STQMEKF_P.baseRate)) {
      sampleTime_0 = STQMEKF_P.baseRate;
    }

    STQMEKF_DW.obj_dk.SampleTime = sampleTime_0;
    STQMEKF_DW.obj_dk.isInitialized = 1;

    //         %% Define output properties
    //  Call C-function implementing device initialization
    STQMEKF_DW.obj_dk.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S212>/WhoAmI'
    // End of SystemInitialize for SubSystem: '<S11>/Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S12>/Subsystem'
    // Start for S-Function (sdspFromNetwork): '<S213>/UDP Receive1'
    sErr = GetErrorBuffer(&STQMEKF_DW.UDPReceive1_NetworkLib[0U]);
    CreateUDPInterface(&STQMEKF_DW.UDPReceive1_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&STQMEKF_DW.UDPReceive1_NetworkLib[0U], 0, "0.0.0.0",
                        STQMEKF_P.UDPReceive1_Port, "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&STQMEKF_DW.UDPReceive1_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&STQMEKF_DW.UDPReceive1_NetworkLib[0U]);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S213>/UDP Receive1'
    // End of SystemInitialize for SubSystem: '<S12>/Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S13>/Change ARM Behavior'
    // Start for MATLABSystem: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    STQMEKF_DW.obj_n.matlabCodegenIsDeleted = false;
    STQMEKF_DW.obj_n.POSITION_P_GAIN = STQMEKF_P.ControlDynamixelActuatorsineith;
    STQMEKF_DW.obj_n.POSITION_I_GAIN = STQMEKF_P.ControlDynamixelActuatorsinei_b;
    STQMEKF_DW.obj_n.POSITION_D_GAIN = STQMEKF_P.ControlDynamixelActuatorsinei_h;
    STQMEKF_DW.obj_n.MAX_POSITION = STQMEKF_P.ControlDynamixelActuatorsinei_j;
    STQMEKF_DW.obj_n.MIN_POSITION = STQMEKF_P.ControlDynamixelActuatorsinei_m;
    STQMEKF_DW.obj_n.MOVE_TIME = STQMEKF_P.ControlDynamixelActuatorsine_hy;
    STQMEKF_DW.obj_n.CURRENT_LIMIT = STQMEKF_P.ControlDynamixelActuatorsinei_i;
    STQMEKF_DW.obj_n.SPEED_P_GAIN = STQMEKF_P.ControlDynamixelActuatorsinei_g;
    STQMEKF_DW.obj_n.SPEED_I_GAIN = STQMEKF_P.ControlDynamixelActuatorsine_g3;
    STQMEKF_DW.obj_n.VELOCITY_LIMIT = STQMEKF_P.ControlDynamixelActuatorsine_bf;
    STQMEKF_DW.obj_n.ACCELERATION_TIME =
      STQMEKF_P.ControlDynamixelActuatorsinei_l;
    if (((!rtIsInf(STQMEKF_P.baseRate)) && (!rtIsNaN(STQMEKF_P.baseRate))) ||
        rtIsInf(STQMEKF_P.baseRate)) {
      sampleTime_1 = STQMEKF_P.baseRate;
    }

    STQMEKF_DW.obj_n.SampleTime = sampleTime_1;
    STQMEKF_DW.obj_n.isInitialized = 1;

    //         %% Define input properties
    initialize_dynamixel();
    STQMEKF_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
    // End of SystemInitialize for SubSystem: '<S13>/Change ARM Behavior'

    // SystemInitialize for IfAction SubSystem: '<S15>/Subsystem'
    // Start for S-Function (sdspToNetwork): '<S224>/UDP Send'
    sErr = GetErrorBuffer(&STQMEKF_DW.UDPSend_NetworkLib_m[0U]);
    CreateUDPInterface(&STQMEKF_DW.UDPSend_NetworkLib_m[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&STQMEKF_DW.UDPSend_NetworkLib_m[0U], 1, "0.0.0.0", -1,
                        "192.168.1.115", STQMEKF_P.UDPSend_Port, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&STQMEKF_DW.UDPSend_NetworkLib_m[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&STQMEKF_DW.UDPSend_NetworkLib_m[0U]);
      if (*sErr != 0) {
        STQMEKF_M->setErrorStatus(sErr);
        STQMEKF_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S224>/UDP Send'
    // End of SystemInitialize for SubSystem: '<S15>/Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S17>/Change RED Behavior'
    // InitializeConditions for Delay: '<S254>/Delay'
    STQMEKF_DW.Delay_DSTATE_b = STQMEKF_P.Delay_InitialCondition_p;

    // SystemInitialize for Enabled SubSystem: '<S254>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S259>/In1' incorporates:
    //   Outport: '<S259>/Out1'

    STQMEKF_B.In1 = STQMEKF_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S254>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S254>/Enabled Subsystem1'
    for (i = 0; i < 8; i++) {
      // SystemInitialize for SignalConversion generated from: '<S260>/ThrustPer_Final' incorporates:
      //   Outport: '<S260>/Out1'

      STQMEKF_B.ThrustPer_Final[i] = STQMEKF_P.Out1_Y0_d;
    }

    // End of SystemInitialize for SubSystem: '<S254>/Enabled Subsystem1'
    STQMEKF_Pseudoinverse1_Init(&STQMEKF_DW.Pseudoinverse1_pn);

    // End of SystemInitialize for SubSystem: '<S17>/Change RED Behavior'

    // SystemInitialize for IfAction SubSystem: '<S17>/Change BLACK Behavior'
    // InitializeConditions for Delay: '<S230>/Delay'
    STQMEKF_DW.Delay_DSTATE_kz = STQMEKF_P.Delay_InitialCondition_i;

    // SystemInitialize for Enabled SubSystem: '<S230>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S235>/In1' incorporates:
    //   Outport: '<S235>/Out1'

    STQMEKF_B.In1_g2 = STQMEKF_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S230>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S230>/Enabled Subsystem1'
    // SystemInitialize for IfAction SubSystem: '<S17>/Change RED Behavior'
    for (i = 0; i < 8; i++) {
      // SystemInitialize for Outport: '<S227>/RED DC'
      STQMEKF_B.duty_cycles[i] = STQMEKF_P.REDDC_Y0;

      // SystemInitialize for SignalConversion generated from: '<S236>/ThrustPer_Final' incorporates:
      //   Outport: '<S236>/Out1'

      STQMEKF_B.ThrustPer_Final_h5[i] = STQMEKF_P.Out1_Y0_j;
    }

    // End of SystemInitialize for SubSystem: '<S17>/Change RED Behavior'
    // End of SystemInitialize for SubSystem: '<S230>/Enabled Subsystem1'
    STQMEKF_Pseudoinverse1_Init(&STQMEKF_DW.Pseudoinverse1);

    // End of SystemInitialize for SubSystem: '<S17>/Change BLACK Behavior'

    // SystemInitialize for IfAction SubSystem: '<S17>/Change BLUE Behavior'
    // InitializeConditions for Delay: '<S242>/Delay'
    STQMEKF_DW.Delay_DSTATE_k = STQMEKF_P.Delay_InitialCondition_n;

    // SystemInitialize for Enabled SubSystem: '<S242>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S247>/In1' incorporates:
    //   Outport: '<S247>/Out1'

    STQMEKF_B.In1_g = STQMEKF_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<S242>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S242>/Enabled Subsystem1'
    // SystemInitialize for IfAction SubSystem: '<S17>/Change BLACK Behavior'
    for (i = 0; i < 8; i++) {
      // SystemInitialize for Outport: '<S225>/BLACK DC'
      STQMEKF_B.duty_cycles_l[i] = STQMEKF_P.BLACKDC_Y0;

      // SystemInitialize for SignalConversion generated from: '<S248>/ThrustPer_Final' incorporates:
      //   Outport: '<S248>/Out1'

      STQMEKF_B.ThrustPer_Final_h[i] = STQMEKF_P.Out1_Y0_js;
    }

    // End of SystemInitialize for SubSystem: '<S17>/Change BLACK Behavior'
    // End of SystemInitialize for SubSystem: '<S242>/Enabled Subsystem1'
    STQMEKF_Pseudoinverse1_Init(&STQMEKF_DW.Pseudoinverse1_p);

    // SystemInitialize for Outport: '<S226>/BLUE DC'
    for (i = 0; i < 8; i++) {
      STQMEKF_B.duty_cycles_p[i] = STQMEKF_P.BLUEDC_Y0;
    }

    // End of SystemInitialize for Outport: '<S226>/BLUE DC'
    // End of SystemInitialize for SubSystem: '<S17>/Change BLUE Behavior'

    // Start for MATLABSystem: '<S162>/MATLAB System'
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    STQMEKF_DW.obj_m.matlabCodegenIsDeleted = false;
    STQMEKF_DW.obj_m.isInitialized = 1;

    //         %% Define input properties
    //  Call C-function implementing device initialization
    createFile();
    STQMEKF_DW.obj_m.isSetupComplete = true;
  }
}

// Model terminate function
void STQMEKF_terminate(void)
{
  char_T *sErr;

  // Terminate for IfAction SubSystem: '<S4>/Change BLACK Behavior'
  STQMEK_ChangeBLACKBehavior_Term(STQMEKF_M, &STQMEKF_DW.ChangeBLACKBehavior);

  // End of Terminate for SubSystem: '<S4>/Change BLACK Behavior'

  // Terminate for IfAction SubSystem: '<S4>/Change BLUE Behavior'
  STQMEK_ChangeBLACKBehavior_Term(STQMEKF_M, &STQMEKF_DW.ChangeBLUEBehavior);

  // End of Terminate for SubSystem: '<S4>/Change BLUE Behavior'

  // Terminate for IfAction SubSystem: '<S4>/Change RED Behavior'
  STQMEK_ChangeBLACKBehavior_Term(STQMEKF_M, &STQMEKF_DW.ChangeREDBehavior);

  // End of Terminate for SubSystem: '<S4>/Change RED Behavior'

  // Terminate for MATLABSystem: '<S162>/MATLAB System'
  if (!STQMEKF_DW.obj_m.matlabCodegenIsDeleted) {
    STQMEKF_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S162>/MATLAB System'

  // Terminate for IfAction SubSystem: '<S6>/Change BLACK Behavior'
  // Terminate for S-Function (sdspToNetwork): '<S164>/UDP Send1'
  sErr = GetErrorBuffer(&STQMEKF_DW.UDPSend1_NetworkLib[0U]);
  LibTerminate(&STQMEKF_DW.UDPSend1_NetworkLib[0U]);
  if (*sErr != 0) {
    STQMEKF_M->setErrorStatus(sErr);
    STQMEKF_M->setStopRequested(1);
  }

  LibDestroy(&STQMEKF_DW.UDPSend1_NetworkLib[0U], 1);
  DestroyUDPInterface(&STQMEKF_DW.UDPSend1_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S164>/UDP Send1'
  // End of Terminate for SubSystem: '<S6>/Change BLACK Behavior'

  // Terminate for IfAction SubSystem: '<S6>/Change BLUE Behavior'
  // Terminate for S-Function (sdspToNetwork): '<S165>/UDP Send2'
  sErr = GetErrorBuffer(&STQMEKF_DW.UDPSend2_NetworkLib[0U]);
  LibTerminate(&STQMEKF_DW.UDPSend2_NetworkLib[0U]);
  if (*sErr != 0) {
    STQMEKF_M->setErrorStatus(sErr);
    STQMEKF_M->setStopRequested(1);
  }

  LibDestroy(&STQMEKF_DW.UDPSend2_NetworkLib[0U], 1);
  DestroyUDPInterface(&STQMEKF_DW.UDPSend2_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S165>/UDP Send2'
  // End of Terminate for SubSystem: '<S6>/Change BLUE Behavior'

  // Terminate for IfAction SubSystem: '<S6>/Change RED Behavior'
  // Terminate for S-Function (sdspToNetwork): '<S166>/UDP Send3'
  sErr = GetErrorBuffer(&STQMEKF_DW.UDPSend3_NetworkLib[0U]);
  LibTerminate(&STQMEKF_DW.UDPSend3_NetworkLib[0U]);
  if (*sErr != 0) {
    STQMEKF_M->setErrorStatus(sErr);
    STQMEKF_M->setStopRequested(1);
  }

  LibDestroy(&STQMEKF_DW.UDPSend3_NetworkLib[0U], 1);
  DestroyUDPInterface(&STQMEKF_DW.UDPSend3_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S166>/UDP Send3'
  // End of Terminate for SubSystem: '<S6>/Change RED Behavior'

  // Terminate for IfAction SubSystem: '<S7>/Enable Pucks'
  // Terminate for MATLABSystem: '<S167>/GPIO Write1'
  if (!STQMEKF_DW.obj_c.matlabCodegenIsDeleted) {
    STQMEKF_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((STQMEKF_DW.obj_c.isInitialized == 1) &&
        STQMEKF_DW.obj_c.isSetupComplete) {
      //  Call C-function implementing device termination
      change_gpio_value(STQMEKF_DW.obj_c.gpioPin, 0.0);
      unexport_gpio(STQMEKF_DW.obj_c.gpioPin);
    }
  }

  // End of Terminate for MATLABSystem: '<S167>/GPIO Write1'
  // End of Terminate for SubSystem: '<S7>/Enable Pucks'

  // Terminate for IfAction SubSystem: '<S8>/Log Gyro//Accel'
  // Terminate for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  if (!STQMEKF_DW.obj.matlabCodegenIsDeleted) {
    STQMEKF_DW.obj.matlabCodegenIsDeleted = true;
  }

  if (!STQMEKF_DW.obj._pobj2.matlabCodegenIsDeleted) {
    STQMEKF_DW.obj._pobj2.matlabCodegenIsDeleted = true;
    if (STQMEKF_DW.obj._pobj2.isInitialized == 1) {
      STQMEKF_DW.obj._pobj2.isInitialized = 2;
    }
  }

  // End of Terminate for MATLABSystem: '<S168>/Gyroscope//Accelerometer'
  // End of Terminate for SubSystem: '<S8>/Log Gyro//Accel'

  // Terminate for IfAction SubSystem: '<S9>/Change ARM Behavior'
  // Terminate for MATLABSystem: '<S170>/Read Joint Positions using  Dynamixel Encoders' 
  if (!STQMEKF_DW.obj_d.matlabCodegenIsDeleted) {
    STQMEKF_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S170>/Read Joint Positions using  Dynamixel Encoders' 
  // End of Terminate for SubSystem: '<S9>/Change ARM Behavior'

  // Terminate for IfAction SubSystem: '<S10>/Use Hardware to Obtain States'
  // Terminate for S-Function (sdspFromNetwork): '<S173>/Receive PhaseSpace Data' 
  sErr = GetErrorBuffer(&STQMEKF_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
  LibTerminate(&STQMEKF_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
  if (*sErr != 0) {
    STQMEKF_M->setErrorStatus(sErr);
    STQMEKF_M->setStopRequested(1);
  }

  LibDestroy(&STQMEKF_DW.ReceivePhaseSpaceData_NetworkLi[0U], 0);
  DestroyUDPInterface(&STQMEKF_DW.ReceivePhaseSpaceData_NetworkLi[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S173>/Receive PhaseSpace Data' 

  // Terminate for S-Function (sdspFromNetwork): '<S178>/UDP Receive'
  sErr = GetErrorBuffer(&STQMEKF_DW.UDPReceive_NetworkLib[0U]);
  LibTerminate(&STQMEKF_DW.UDPReceive_NetworkLib[0U]);
  if (*sErr != 0) {
    STQMEKF_M->setErrorStatus(sErr);
    STQMEKF_M->setStopRequested(1);
  }

  LibDestroy(&STQMEKF_DW.UDPReceive_NetworkLib[0U], 0);
  DestroyUDPInterface(&STQMEKF_DW.UDPReceive_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S178>/UDP Receive'

  // Terminate for S-Function (sdspFromNetwork): '<S178>/UDP Receive2'
  sErr = GetErrorBuffer(&STQMEKF_DW.UDPReceive2_NetworkLib[0U]);
  LibTerminate(&STQMEKF_DW.UDPReceive2_NetworkLib[0U]);
  if (*sErr != 0) {
    STQMEKF_M->setErrorStatus(sErr);
    STQMEKF_M->setStopRequested(1);
  }

  LibDestroy(&STQMEKF_DW.UDPReceive2_NetworkLib[0U], 0);
  DestroyUDPInterface(&STQMEKF_DW.UDPReceive2_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S178>/UDP Receive2'

  // Terminate for S-Function (sdspFromNetwork): '<S178>/UDP Receive3'
  sErr = GetErrorBuffer(&STQMEKF_DW.UDPReceive3_NetworkLib[0U]);
  LibTerminate(&STQMEKF_DW.UDPReceive3_NetworkLib[0U]);
  if (*sErr != 0) {
    STQMEKF_M->setErrorStatus(sErr);
    STQMEKF_M->setStopRequested(1);
  }

  LibDestroy(&STQMEKF_DW.UDPReceive3_NetworkLib[0U], 0);
  DestroyUDPInterface(&STQMEKF_DW.UDPReceive3_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S178>/UDP Receive3'
  // End of Terminate for SubSystem: '<S10>/Use Hardware to Obtain States'

  // Terminate for IfAction SubSystem: '<S11>/Subsystem'
  // Terminate for MATLABSystem: '<S212>/WhoAmI'
  if (!STQMEKF_DW.obj_dk.matlabCodegenIsDeleted) {
    STQMEKF_DW.obj_dk.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S212>/WhoAmI'
  // End of Terminate for SubSystem: '<S11>/Subsystem'

  // Terminate for IfAction SubSystem: '<S12>/Subsystem'
  // Terminate for S-Function (sdspFromNetwork): '<S213>/UDP Receive1'
  sErr = GetErrorBuffer(&STQMEKF_DW.UDPReceive1_NetworkLib[0U]);
  LibTerminate(&STQMEKF_DW.UDPReceive1_NetworkLib[0U]);
  if (*sErr != 0) {
    STQMEKF_M->setErrorStatus(sErr);
    STQMEKF_M->setStopRequested(1);
  }

  LibDestroy(&STQMEKF_DW.UDPReceive1_NetworkLib[0U], 0);
  DestroyUDPInterface(&STQMEKF_DW.UDPReceive1_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S213>/UDP Receive1'
  // End of Terminate for SubSystem: '<S12>/Subsystem'

  // Terminate for IfAction SubSystem: '<S13>/Change ARM Behavior'
  // Terminate for MATLABSystem: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
  if (!STQMEKF_DW.obj_n.matlabCodegenIsDeleted) {
    STQMEKF_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((STQMEKF_DW.obj_n.isInitialized == 1) &&
        STQMEKF_DW.obj_n.isSetupComplete) {
      terminate_dynamixel();
    }
  }

  // End of Terminate for MATLABSystem: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
  // End of Terminate for SubSystem: '<S13>/Change ARM Behavior'

  // Terminate for IfAction SubSystem: '<S15>/Subsystem'
  // Terminate for S-Function (sdspToNetwork): '<S224>/UDP Send'
  sErr = GetErrorBuffer(&STQMEKF_DW.UDPSend_NetworkLib_m[0U]);
  LibTerminate(&STQMEKF_DW.UDPSend_NetworkLib_m[0U]);
  if (*sErr != 0) {
    STQMEKF_M->setErrorStatus(sErr);
    STQMEKF_M->setStopRequested(1);
  }

  LibDestroy(&STQMEKF_DW.UDPSend_NetworkLib_m[0U], 1);
  DestroyUDPInterface(&STQMEKF_DW.UDPSend_NetworkLib_m[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S224>/UDP Send'
  // End of Terminate for SubSystem: '<S15>/Subsystem'

  // Terminate for S-Function (sdspToNetwork): '<S17>/UDP Send'
  sErr = GetErrorBuffer(&STQMEKF_DW.UDPSend_NetworkLib[0U]);
  LibTerminate(&STQMEKF_DW.UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    STQMEKF_M->setErrorStatus(sErr);
    STQMEKF_M->setStopRequested(1);
  }

  LibDestroy(&STQMEKF_DW.UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&STQMEKF_DW.UDPSend_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S17>/UDP Send'
}

time_T** RT_MODEL_STQMEKF_T::getTPtrPtr()
{
  return &(Timing.t);
}

boolean_T RT_MODEL_STQMEKF_T::getStopRequested() const
{
  return (Timing.stopRequestedFlag);
}

void RT_MODEL_STQMEKF_T::setStopRequested(boolean_T aStopRequested)
{
  (Timing.stopRequestedFlag = aStopRequested);
}

const char_T* RT_MODEL_STQMEKF_T::getErrorStatus() const
{
  return (errorStatus);
}

void RT_MODEL_STQMEKF_T::setErrorStatus(const char_T* const aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

time_T* RT_MODEL_STQMEKF_T::getTPtr() const
{
  return (Timing.t);
}

void RT_MODEL_STQMEKF_T::setTPtr(time_T* aTPtr)
{
  (Timing.t = aTPtr);
}

boolean_T* RT_MODEL_STQMEKF_T::getStopRequestedPtr()
{
  return (&(Timing.stopRequestedFlag));
}

const char_T** RT_MODEL_STQMEKF_T::getErrorStatusPtr()
{
  return &errorStatus;
}

boolean_T RT_MODEL_STQMEKF_T::isMajorTimeStep() const
{
  return ((Timing.simTimeStep) == MAJOR_TIME_STEP);
}

boolean_T RT_MODEL_STQMEKF_T::isMinorTimeStep() const
{
  return ((Timing.simTimeStep) == MINOR_TIME_STEP);
}

//
// File trailer for generated code.
//
// [EOF]
//
