//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MPC.cpp
//
// Code generated for Simulink model 'MPC'.
//
// Model version                  : 4.1555
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Mon Jul 14 15:22:05 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "MPC.h"
#include "rtwtypes.h"
#include "MPC_types.h"
#include "MPC_private.h"
#include <string.h>
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "coder_posix_time.h"
#include "rt_defines.h"

// Block signals (default storage)
B_MPC_T MPC_B;

// Block states (default storage)
DW_MPC_T MPC_DW;

// Real-time model
RT_MODEL_MPC_T MPC_M_ = RT_MODEL_MPC_T();
RT_MODEL_MPC_T *const MPC_M = &MPC_M_;

// Forward declaration for local functions
static real_T MPC_xzlangeM(const real_T x[24]);
static void MPC_xzlascl(real_T cfrom, real_T cto, real_T A[24]);
static real_T MPC_xnrm2(int32_T n, const real_T x[24], int32_T ix0);
static real_T MPC_xdotc(int32_T n, const real_T x[24], int32_T ix0, const real_T
  y[24], int32_T iy0);
static void MPC_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[24], int32_T
                      iy0);
static real_T MPC_xdotc_o(const real_T x[9], const real_T y[9], int32_T iy0);
static void MPC_xaxpy_gop(real_T a, real_T y[9], int32_T iy0);
static real_T MPC_xnrm2_p(const real_T x[3], int32_T ix0);
static void MPC_xaxpy_g(int32_T n, real_T a, const real_T x[24], int32_T ix0,
  real_T y[8], int32_T iy0);
static void MPC_xaxpy_go(int32_T n, real_T a, const real_T x[8], int32_T ix0,
  real_T y[24], int32_T iy0);
static void MPC_xzlascl_i(real_T cfrom, real_T cto, real_T A[3]);
static void MPC_xrotg(real_T a, real_T b, real_T *b_a, real_T *b_b, real_T *c,
                      real_T *s);
static void MPC_xrot_ps(real_T x[9], int32_T ix0, int32_T iy0, real_T c, real_T
  s);
static void MPC_xrot_psj(real_T x[24], int32_T ix0, int32_T iy0, real_T c,
  real_T s);
static void MPC_xswap_dj(real_T x[9], int32_T ix0, int32_T iy0);
static void MPC_xswap_dj5(real_T x[24], int32_T ix0, int32_T iy0);
static void MPC_svd(const real_T A[24], real_T U[24], real_T s[3], real_T V[9]);

// Forward declaration for local functions
static real_T MPC_maximum(const real_T x[8]);

// Forward declaration for local functions
static void MPC_timeKeeper(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime);
static void MPC_tic(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime);
static real_T MPC_norm(const real_T x[3]);
static real_T MPC_norm_j(const real_T x[81]);
static void MPC_mpower(const real_T a[81], real_T b, real_T c[81]);
static real_T MPC_log2(real_T x);
static void MPC_padeApproximation(const real_T A[81], const real_T A2[81], const
  real_T A4[81], const real_T A6[81], int32_T m, real_T F[81]);
static void MPC_recomputeBlockDiag(const real_T A[81], real_T F[81], const
  int32_T blockFormat[8]);
static real_T MPC_xnrm2_o(int32_T n, const real_T x[81], int32_T ix0);
static void MPC_xzsyhetrd(real_T A[81], real_T D[9], real_T E[8], real_T tau[8]);
static void MPC_xzlascl_m(real_T cfrom, real_T cto, int32_T m, real_T A[9],
  int32_T iA0);
static void MPC_xzlascl_ml(real_T cfrom, real_T cto, int32_T m, real_T A[8],
  int32_T iA0);
static void MPC_xzlartg(real_T f, real_T g, real_T *cs, real_T *sn, real_T *r);
static void MPC_rotateRight_b(int32_T n, real_T z[81], int32_T iz0, const real_T
  cs[16], int32_T ic0, int32_T is0);
static void MPC_xdlaev2(real_T a, real_T b, real_T c, real_T *rt1, real_T *rt2,
  real_T *cs1, real_T *sn1);
static void MPC_rotateRight(int32_T n, real_T z[81], int32_T iz0, const real_T
  cs[16], int32_T ic0, int32_T is0);
static int32_T MPC_xzsteqr(real_T d[9], real_T e[8], real_T z[81]);
static void MPC_xsyheev(real_T A[81], int32_T *info, real_T W[9]);
static void MPC_expm(real_T A[81], real_T F[81]);
static real_T MPC_rand(void);
static void MPC_xgetrf(real_T A[36], int32_T ipiv[6], int32_T *info);
static void MPC_mrdiv_n(real_T A[72], const real_T B[36]);
static void MPC_timeKeeper_m(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime, real_T
  *outTime_tv_sec, real_T *outTime_tv_nsec);
static real_T MPC_toc(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime);
static void MPC_timeKeeper_k(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_f);
static void MPC_tic_e(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_f);
static real_T MPC_norm_a(const real_T x[9]);
static void MPC_mpower_m(const real_T a[9], real_T b, real_T c[9]);
static void MPC_padeApproximation_g(const real_T A[9], const real_T A2[9], const
  real_T A4[9], const real_T A6[9], int32_T m, real_T F[9]);
static void MPC_recomputeBlockDiag_c(const real_T A[9], real_T F[9], const
  int32_T blockFormat[2]);
static void MPC_xzsyhetrd_c(real_T A[9], real_T D[3], real_T E[2], real_T tau[2]);
static void MPC_xzlascl_mlt(real_T cfrom, real_T cto, int32_T m, real_T A[3],
  int32_T iA0);
static void MPC_xzlascl_mlt2(real_T cfrom, real_T cto, int32_T m, real_T A[2],
  int32_T iA0);
static void MPC_rotateRight_m1(int32_T n, real_T z[9], int32_T iz0, const real_T
  cs[4], int32_T ic0, int32_T is0);
static void MPC_rotateRight_m(int32_T n, real_T z[9], int32_T iz0, const real_T
  cs[4], int32_T ic0, int32_T is0);
static int32_T MPC_xzsteqr_c(real_T d[3], real_T e[2], real_T z[9]);
static void MPC_xsyheev_o(real_T A[9], int32_T *info, real_T W[3]);
static void MPC_expm_o(real_T A[9], real_T F[9]);
static real_T MPC_norm_ai(const real_T x[2]);
static void MPC_timeKeeper_kw(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_f, real_T
  *outTime_tv_sec, real_T *outTime_tv_nsec);
static real_T MPC_toc_f(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_f);
static void MPC_timeKeeper_a(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_a);
static void MPC_tic_k(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_a);
static real_T MPC_rand_p(void);
static real_T MPC_det(const real_T x[9]);
static boolean_T MPC_hasFiniteBounds(boolean_T hasLB[6], boolean_T hasUB[6]);
static void MPC_corrP4Q_anonFcn1(const real_T P_k[144], const real_T H[72],
  const real_T b_R[36], const real_T V[36], const real_T x[6], real_T
  varargout_1[36]);
static void MPC_finDiffEvalAndChkErr(const real_T
  obj_nonlin_workspace_fun_worksp[144], const real_T
  obj_nonlin_workspace_fun_work_0[72], const real_T
  obj_nonlin_workspace_fun_work_1[36], int32_T dim, real_T delta, real_T xk[6],
  boolean_T *evalOK, real_T *fplus, real_T cEqPlus[36]);
static boolean_T MPC_computeFiniteDifferences(s_B0kB2CQLsoRkj8KoaXWXYC_MPC_T
  *obj, const real_T cEqCurrent[36], real_T xk[6], real_T JacCeqTrans[216]);
static real_T MPC_computeFirstOrderOpt(const real_T gradf[6], boolean_T
  hasFiniteBounds, const real_T *projSteepestDescentInfNorm);
static real_T MPC_norm_izm(const real_T x[6]);
static int32_T MPC_checkStoppingCriteria(const real_T gradf[6], real_T relFactor,
  const real_T x[6], int32_T funcCount, real_T projSteepestDescentInfNorm,
  boolean_T hasFiniteBounds);
static real_T MPC_xnrm2_gy(int32_T n, const real_T x[252], int32_T ix0);
static real_T MPC_xzlarfg(int32_T n, real_T *alpha1, real_T x[252], int32_T ix0);
static void MPC_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T C
  [252], int32_T ic0, real_T work[6]);
static void MPC_linearLeastSquares(real_T lhs[252], real_T rhs[42], real_T dx[6]);
static int32_T MPC_checkStoppingCriteria_o(const real_T gradf[6], real_T
  relFactor, real_T funDiff, const real_T x[6], const real_T dx[6], int32_T
  funcCount, boolean_T stepSuccessful, int32_T *iter, real_T
  projSteepestDescentInfNorm, boolean_T hasFiniteBounds);
static void MPC_lsqnonlin(const real_T fun_workspace_P_k[144], const real_T
  fun_workspace_H[72], const real_T fun_workspace_V[36], real_T xCurrent[6]);
static void MPC_timeKeeper_aw(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_a, real_T
  *outTime_tv_sec, real_T *outTime_tv_nsec);
static real_T MPC_toc_h(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_a);
static void MPC_mrdiv_dtsy(real_T A[6], const real_T B[36]);
static void MPC_timeKeeper_g(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_aw);
static void MPC_tic_p(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_aw);
static real_T MPC_rand_pn(void);
static void MPC_corrP4R_anonFcn1(const real_T P_k[144], const real_T H[72],
  const real_T b_R[36], const real_T V[36], const real_T x[6], real_T
  varargout_1[36]);
static void MPC_finDiffEvalAndChkErr_a(const real_T
  obj_nonlin_workspace_fun_worksp[144], const real_T
  obj_nonlin_workspace_fun_work_0[72], const real_T
  obj_nonlin_workspace_fun_work_1[36], int32_T dim, real_T delta, real_T xk[6],
  boolean_T *evalOK, real_T *fplus, real_T cEqPlus[36]);
static boolean_T MPC_computeFiniteDifferences_m(s_B0kB2CQLsoRkj8KoaXWXYC_MPC_T
  *obj, const real_T cEqCurrent[36], real_T xk[6], real_T JacCeqTrans[216]);
static void MPC_lsqnonlin_e(const real_T fun_workspace_P_k[144], const real_T
  fun_workspace_H[72], const real_T fun_workspace_V[36], real_T xCurrent[6]);
static void MPC_timeKeeper_gw(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_aw,
  real_T *outTime_tv_sec, real_T *outTime_tv_nsec);
static real_T MPC_toc_a(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_aw);
static real_T MPC_xnrm2_ob(int32_T n, const real_T x[153], int32_T ix0);
static real_T MPC_xzlarfg_m(int32_T n, real_T *alpha1, real_T x[153], int32_T
  ix0);
static void MPC_xzlarf_b(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T
  C[153], int32_T ic0, real_T work[17]);
static void MPC_qrf(real_T A[153], int32_T m, int32_T n, int32_T nfxd, real_T
                    tau[9]);
static void MPC_xgeqp3(real_T A[153], int32_T m, int32_T n, int32_T jpvt[17],
  real_T tau[9]);
static void MPC_countsort(int32_T x[17], int32_T xLen, int32_T workspace[17],
  int32_T xMin, int32_T xMax);
static void MPC_removeConstr(srnx7tMxlsAQ9dn31gXFrqF_MPC_T *obj, int32_T
  idx_global);
static void MPC_RemoveDependentIneq_(srnx7tMxlsAQ9dn31gXFrqF_MPC_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_MPC_T *qrmanager, sLLWTJNyuJQrAxk3RwmbzBG_MPC_T
  *memspace, real_T tolfactor);
static void MPC_computeQ_(sTj3C1mXm6Z2qP847mPxR8C_MPC_T *obj, int32_T nrows);
static int32_T MPC_rank(const real_T qrmanager_QR[153], int32_T qrmanager_mrows,
  int32_T qrmanager_ncols);
static real_T MPC_maxConstraintViolation(const srnx7tMxlsAQ9dn31gXFrqF_MPC_T
  *obj, const real_T x[153], int32_T ix0);
static boolean_T MPC_feasibleX0ForWorkingSet(real_T workspace[153], real_T
  xCurrent[9], const srnx7tMxlsAQ9dn31gXFrqF_MPC_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_MPC_T *qrmanager);
static real_T MPC_maxConstraintViolation_c(const srnx7tMxlsAQ9dn31gXFrqF_MPC_T
  *obj, const real_T x[9]);
static void MPC_setProblemType(srnx7tMxlsAQ9dn31gXFrqF_MPC_T *obj, int32_T
  PROBLEM_TYPE);
static void MPC_xgemv(int32_T m, int32_T n, const real_T A[64], int32_T lda,
                      const real_T x[9], real_T y[8]);
static void MPC_computeGrad_StoreHx(s87IldPMN2ICa85Nu8z6UL_MPC_T *obj, const
  real_T H[64], const real_T f[8], const real_T x[9]);
static real_T MPC_computeFval_ReuseHx(const s87IldPMN2ICa85Nu8z6UL_MPC_T *obj,
  real_T workspace[153], const real_T f[8], const real_T x[9]);
static void MPC_factorQR(sTj3C1mXm6Z2qP847mPxR8C_MPC_T *obj, const real_T A[153],
  int32_T mrows, int32_T ncols);
static void MPC_xrotg_o(real_T *a, real_T *b, real_T *c, real_T *s);
static void MPC_squareQ_appendCol(sTj3C1mXm6Z2qP847mPxR8C_MPC_T *obj, const
  real_T vec[153], int32_T iv0);
static void MPC_deleteColMoveEnd(sTj3C1mXm6Z2qP847mPxR8C_MPC_T *obj, int32_T idx);
static void MPC_fullColLDL2_(smSS6fEwaptVbzYAOdOZgjB_MPC_T *obj, int32_T
  NColsRemain, real_T REG_PRIMAL);
static void MPC_xgemv_a(int32_T m, int32_T n, const real_T A[81], int32_T ia0,
  const real_T x[153], real_T y[9]);
static void MPC_compute_deltax(const real_T H[64], sraTyWZlTzdIJhNDrRZT2SF_MPC_T
  *solution, sLLWTJNyuJQrAxk3RwmbzBG_MPC_T *memspace, const
  sTj3C1mXm6Z2qP847mPxR8C_MPC_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_MPC_T
  *cholmanager, const s87IldPMN2ICa85Nu8z6UL_MPC_T *objective);
static real_T MPC_xnrm2_ob0(int32_T n, const real_T x[9]);
static void MPC_feasibleratiotest(const real_T solution_xstar[9], const real_T
  solution_searchDir[9], int32_T workingset_nVar, const real_T workingset_lb[9],
  const int32_T workingset_indexLB[9], const int32_T workingset_indexUB[9],
  const int32_T workingset_sizes[5], const int32_T workingset_isActiveIdx[6],
  const boolean_T workingset_isActiveConstr[17], const int32_T
  workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha, boolean_T
  *newBlocking, int32_T *constrType, int32_T *constrIdx);
static void MPC_addBoundToActiveSetMatrix_(srnx7tMxlsAQ9dn31gXFrqF_MPC_T *obj,
  int32_T TYPE, int32_T idx_local);
static void MPC_addAineqConstr(const srnx7tMxlsAQ9dn31gXFrqF_MPC_T *obj);
static void MPC_compute_lambda(real_T workspace[153],
  sraTyWZlTzdIJhNDrRZT2SF_MPC_T *solution, const s87IldPMN2ICa85Nu8z6UL_MPC_T
  *objective, const sTj3C1mXm6Z2qP847mPxR8C_MPC_T *qrmanager);
static void MPC_phaseone(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_MPC_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_MPC_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_MPC_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_MPC_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_MPC_T
  *cholmanager, const sIOJhD9KwAkF5sEguPjYquC_MPC_T *runTimeOptions,
  s87IldPMN2ICa85Nu8z6UL_MPC_T *objective);
static int32_T MPC_RemoveDependentEq_(sLLWTJNyuJQrAxk3RwmbzBG_MPC_T *memspace,
  const srnx7tMxlsAQ9dn31gXFrqF_MPC_T *workingset, sTj3C1mXm6Z2qP847mPxR8C_MPC_T
  *qrmanager);
static void MPC_ratiotest(const real_T solution_xstar[9], const real_T
  solution_searchDir[9], int32_T workingset_nVar, const real_T workingset_lb[9],
  const int32_T workingset_indexLB[9], const int32_T workingset_indexUB[9],
  const int32_T workingset_sizes[5], const int32_T workingset_isActiveIdx[6],
  const boolean_T workingset_isActiveConstr[17], const int32_T
  workingset_nWConstr[5], real_T *toldelta, real_T *alpha, boolean_T
  *newBlocking, int32_T *constrType, int32_T *constrIdx);
static void MPC_iterate(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_MPC_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_MPC_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_MPC_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_MPC_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_MPC_T
  *cholmanager, s87IldPMN2ICa85Nu8z6UL_MPC_T *objective, boolean_T
  runTimeOptions_RemainFeasible, real_T runTimeOptions_ProbRelTolFactor);
static void MPC_computeFirstOrderOpt_h(sraTyWZlTzdIJhNDrRZT2SF_MPC_T *solution,
  const s87IldPMN2ICa85Nu8z6UL_MPC_T *objective, int32_T workingset_nVar, const
  real_T workingset_ATwset[153], int32_T workingset_nActiveConstr, real_T
  workspace[153]);
static void MPC_phaseone_i(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_MPC_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_MPC_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_MPC_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_MPC_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_MPC_T
  *cholmanager, s87IldPMN2ICa85Nu8z6UL_MPC_T *objective, const
  sIOJhD9KwAkF5sEguPjYquC_MPC_T *runTimeOptions);
static void MPC_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar, real_T
  workspace[153], const real_T H[64], const real_T f[8], const real_T x[9]);
static real_T MPC_computeFval(const s87IldPMN2ICa85Nu8z6UL_MPC_T *obj, real_T
  workspace[153], const real_T H[64], const real_T f[8], const real_T x[9]);
static void MPC_quadprog(const real_T H[64], const real_T f[8], const real_T x0
  [8], real_T x[8], real_T *fval, real_T *exitflag);
static real_T MPC_maximum_h(const real_T x[8]);
static void MPC_pause(real_T varargin_1);
static void M_bmi160_set_EnableSecondaryMag(b_bmi160_MPC_T *obj);
static void MPC_SystemCore_setup(nvidiacoder_sensors_BMI160Blo_T *obj);
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
void MPC_Phase0Synchronization(real_T *rtd_ARM_Control_Law_Enabler, real_T
  *rtd_ARM_Path_Planner_Selection, real_T *rtd_BLACK_Control_Law_Enabler, real_T
  *rtd_BLACK_Path_Planner_Selectio, real_T *rtd_BLUE_Control_Law_Enabler, real_T
  *rtd_BLUE_Path_Planner_Selection, real_T *rtd_Float_State, real_T
  *rtd_RED_Control_Law_Enabler, char_T rtd_RED_Logger[256], real_T
  *rtd_RED_Path_Planner_Selection, real_T *rtd_Toggle_Nav,
  P_Phase0Synchronization_MPC_T *localP)
{
  // DataStoreWrite: '<S20>/Data Store Write2' incorporates:
  //   Constant: '<S20>/Constant1'

  *rtd_BLACK_Control_Law_Enabler = localP->Constant1_Value;

  // DataStoreWrite: '<S20>/Data Store Write3' incorporates:
  //   Constant: '<S20>/Constant2'

  *rtd_BLUE_Control_Law_Enabler = localP->Constant2_Value;

  // DataStoreWrite: '<S20>/Data Store Write7' incorporates:
  //   Constant: '<S20>/Constant3'

  *rtd_RED_Path_Planner_Selection = localP->Constant3_Value;

  // DataStoreWrite: '<S20>/Data Store Write8' incorporates:
  //   Constant: '<S20>/Constant4'

  *rtd_ARM_Path_Planner_Selection = localP->Constant4_Value;

  // DataStoreWrite: '<S20>/Data Store Write' incorporates:
  //   Constant: '<S20>/Constant5'

  *rtd_RED_Control_Law_Enabler = localP->Constant5_Value;

  // DataStoreWrite: '<S20>/Data Store Write6' incorporates:
  //   Constant: '<S20>/Constant6'

  *rtd_BLACK_Path_Planner_Selectio = localP->Constant6_Value;

  // DataStoreWrite: '<S20>/Data Store Write5' incorporates:
  //   Constant: '<S20>/Constant7'

  *rtd_BLUE_Path_Planner_Selection = localP->Constant7_Value;

  // DataStoreWrite: '<S20>/Data Store Write9' incorporates:
  //   Constant: '<S20>/Constant8'

  *rtd_ARM_Control_Law_Enabler = localP->Constant8_Value;

  // StringConstant: '<S20>/String Constant' incorporates:
  //   DataStoreWrite: '<S20>/Data Store Write1'

  strncpy(&rtd_RED_Logger[0], &localP->StringConstant_String[0], 255U);
  rtd_RED_Logger[255] = '\x00';

  // DataStoreWrite: '<S20>/Data Store Write10' incorporates:
  //   Constant: '<S20>/Puck State1'

  *rtd_Toggle_Nav = localP->PuckState1_Value;

  // DataStoreWrite: '<S20>/Data Store Write4' incorporates:
  //   Constant: '<S20>/Puck State'

  *rtd_Float_State = localP->PuckState_Value;
}

//
// Output and update for action system:
//    '<S1>/Phase #4: Return Home'
//    '<S1>/Phase #5: Hold Home'
//
void MPC_Phase4ReturnHome(real_T *rtd_ARM_Control_Law_Enabler, real_T
  rtd_ARM_Desired_States[3], real_T *rtd_ARM_Path_Planner_Selection, real_T
  *rtd_BLACK_Control_Law_Enabler, real_T rtd_BLACK_Desired_States[3], real_T
  *rtd_BLACK_Path_Planner_Selectio, real_T *rtd_BLUE_Control_Law_Enabler, real_T
  rtd_BLUE_Desired_States[3], real_T *rtd_BLUE_Path_Planner_Selection, real_T
  *rtd_Float_State, real_T *rtd_RED_Control_Law_Enabler, real_T
  rtd_RED_Desired_States[3], real_T *rtd_RED_Path_Planner_Selection, real_T
  *rtd_Toggle_Nav, P_Phase4ReturnHome_MPC_T *localP)
{
  // DataStoreWrite: '<S24>/Data Store Write24' incorporates:
  //   Constant: '<S24>/Constant11'

  *rtd_RED_Path_Planner_Selection = localP->Constant11_Value;

  // DataStoreWrite: '<S24>/Data Store Write3' incorporates:
  //   Constant: '<S24>/Constant12'

  *rtd_ARM_Path_Planner_Selection = localP->Constant12_Value;

  // DataStoreWrite: '<S24>/Data Store Write23' incorporates:
  //   Constant: '<S24>/Constant14'

  *rtd_BLACK_Path_Planner_Selectio = localP->Constant14_Value;

  // DataStoreWrite: '<S24>/Data Store Write22' incorporates:
  //   Constant: '<S24>/Constant15'

  *rtd_BLUE_Path_Planner_Selection = localP->Constant15_Value;

  // DataStoreWrite: '<S24>/Data Store Write4' incorporates:
  //   Constant: '<S24>/Constant18'

  *rtd_ARM_Control_Law_Enabler = localP->Constant18_Value;

  // DataStoreWrite: '<S24>/Data Store Write5' incorporates:
  //   Constant: '<S24>/Constant4'

  *rtd_BLACK_Control_Law_Enabler = localP->Constant4_Value;

  // DataStoreWrite: '<S24>/Data Store Write8' incorporates:
  //   Constant: '<S24>/Constant5'

  *rtd_RED_Control_Law_Enabler = localP->Constant5_Value;

  // DataStoreWrite: '<S24>/Data Store Write7' incorporates:
  //   Constant: '<S24>/Constant6'

  *rtd_Float_State = localP->Constant6_Value;

  // DataStoreWrite: '<S24>/Data Store Write16' incorporates:
  //   Constant: '<S24>/Constant8'

  *rtd_BLUE_Control_Law_Enabler = localP->Constant8_Value;

  // DataStoreWrite: '<S24>/Data Store Write10' incorporates:
  //   Constant: '<S24>/Puck State1'

  *rtd_Toggle_Nav = localP->PuckState1_Value;

  // DataStoreWrite: '<S24>/Data Store Write13' incorporates:
  //   Constant: '<S55>/Constant1'
  //   Constant: '<S55>/Constant2'
  //   Constant: '<S55>/Constant3'

  rtd_ARM_Desired_States[0] = localP->Constant3_Value;
  rtd_ARM_Desired_States[1] = localP->Constant1_Value;
  rtd_ARM_Desired_States[2] = localP->Constant2_Value;

  // DataStoreWrite: '<S24>/Data Store Write18' incorporates:
  //   Constant: '<S57>/Desired States (BLUE)'

  rtd_BLUE_Desired_States[0] = MPC_P.home_states_BLUE[0];

  // DataStoreWrite: '<S24>/Data Store Write6' incorporates:
  //   Constant: '<S56>/Desired States (BLACK)'

  rtd_BLACK_Desired_States[0] = MPC_P.home_states_BLACK[0];

  // DataStoreWrite: '<S24>/Data Store Write9' incorporates:
  //   Constant: '<S58>/Constant2'

  rtd_RED_Desired_States[0] = MPC_P.home_states_RED[0];

  // DataStoreWrite: '<S24>/Data Store Write18' incorporates:
  //   Constant: '<S57>/Desired States (BLUE)'

  rtd_BLUE_Desired_States[1] = MPC_P.home_states_BLUE[1];

  // DataStoreWrite: '<S24>/Data Store Write6' incorporates:
  //   Constant: '<S56>/Desired States (BLACK)'

  rtd_BLACK_Desired_States[1] = MPC_P.home_states_BLACK[1];

  // DataStoreWrite: '<S24>/Data Store Write9' incorporates:
  //   Constant: '<S58>/Constant2'

  rtd_RED_Desired_States[1] = MPC_P.home_states_RED[1];

  // DataStoreWrite: '<S24>/Data Store Write18' incorporates:
  //   Constant: '<S57>/Desired States (BLUE)'

  rtd_BLUE_Desired_States[2] = MPC_P.home_states_BLUE[2];

  // DataStoreWrite: '<S24>/Data Store Write6' incorporates:
  //   Constant: '<S56>/Desired States (BLACK)'

  rtd_BLACK_Desired_States[2] = MPC_P.home_states_BLACK[2];

  // DataStoreWrite: '<S24>/Data Store Write9' incorporates:
  //   Constant: '<S58>/Constant2'

  rtd_RED_Desired_States[2] = MPC_P.home_states_RED[2];
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
//    '<S68>/MATLAB Function'
//    '<S67>/MATLAB Function'
//
void MPC_MATLABFunction(const real_T rtu_desiredPosition[3], const real_T
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
    MPC_P.baseRate + rty_currentPosition[2];
  rty_currentPosition[0] += ((rtu_desiredPosition[0] - rty_currentPosition[0]) *
    rtu_attractiveGain + repulsiveForce_idx_0) * MPC_P.baseRate;
  rty_currentPosition[1] += ((rtu_desiredPosition[1] - rty_currentPosition[1]) *
    rtu_attractiveGain + repulsiveForce_idx_1) * MPC_P.baseRate;
  rty_currentPosition[2] = rt_atan2d_snf(sin(newTheta), cos(newTheta));
}

//
// Output and update for atomic system:
//    '<S92>/MATLAB Function'
//    '<S92>/MATLAB Function1'
//    '<S92>/MATLAB Function2'
//    '<S92>/MATLAB Function4'
//    '<S92>/MATLAB Function6'
//    '<S92>/MATLAB Function8'
//
void MPC_MATLABFunction_g(const real_T rtu_true[4], const real_T rtu_true_m[3],
  const real_T rtu_true_b[3], const real_T rtu_true_g[3], const real_T rtu_est
  [13], real_T rty_y[6])
{
  real_T a_0[16];
  real_T rtb_TmpSignalConversionAtSFun_m[13];
  real_T temp[9];
  real_T a[4];
  real_T q[4];
  real_T vector[3];
  real_T a_tmp;
  real_T absxk;
  real_T b_norm;
  real_T c_norm;
  real_T t;
  boolean_T rEQ0;
  static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  // SignalConversion generated from: '<S103>/ SFunction '
  rtb_TmpSignalConversionAtSFun_m[4] = rtu_true_m[0];
  rtb_TmpSignalConversionAtSFun_m[7] = rtu_true_b[0];
  rtb_TmpSignalConversionAtSFun_m[10] = rtu_true_g[0];
  rtb_TmpSignalConversionAtSFun_m[5] = rtu_true_m[1];
  rtb_TmpSignalConversionAtSFun_m[8] = rtu_true_b[1];
  rtb_TmpSignalConversionAtSFun_m[11] = rtu_true_g[1];
  rtb_TmpSignalConversionAtSFun_m[6] = rtu_true_m[2];
  rtb_TmpSignalConversionAtSFun_m[9] = rtu_true_b[2];
  rtb_TmpSignalConversionAtSFun_m[12] = rtu_true_g[2];
  b_norm = sqrt(((rtu_true[0] * rtu_true[0] + rtu_true[1] * rtu_true[1]) +
                 rtu_true[2] * rtu_true[2]) + rtu_true[3] * rtu_true[3]);
  c_norm = rtu_true[0] / b_norm;
  rtb_TmpSignalConversionAtSFun_m[0] = c_norm;
  a[0] = c_norm * c_norm;

  // SignalConversion generated from: '<S103>/ SFunction '
  c_norm = rtu_true[1] / b_norm;
  rtb_TmpSignalConversionAtSFun_m[1] = c_norm;
  a[1] = c_norm * c_norm;

  // SignalConversion generated from: '<S103>/ SFunction '
  c_norm = rtu_true[2] / b_norm;
  rtb_TmpSignalConversionAtSFun_m[2] = c_norm;
  a[2] = c_norm * c_norm;

  // SignalConversion generated from: '<S103>/ SFunction '
  c_norm = rtu_true[3] / b_norm;
  rtb_TmpSignalConversionAtSFun_m[3] = c_norm;
  b_norm = sqrt(((a[0] + a[1]) + a[2]) + c_norm * c_norm);
  b_norm *= b_norm;
  a[0] = rtb_TmpSignalConversionAtSFun_m[0] / b_norm;
  a_tmp = -rtb_TmpSignalConversionAtSFun_m[1] / b_norm;
  absxk = -rtb_TmpSignalConversionAtSFun_m[2] / b_norm;
  b_norm = -c_norm / b_norm;
  vector[0] = a_tmp;
  vector[1] = absxk;
  vector[2] = b_norm;
  c_norm = a[0];
  temp[0] = 0.0;
  temp[3] = -b_norm;
  temp[6] = absxk;
  temp[1] = b_norm;
  temp[4] = 0.0;
  temp[7] = -a_tmp;
  temp[2] = -absxk;
  temp[5] = a_tmp;
  temp[8] = 0.0;
  a_0[0] = a[0];
  for (int32_T i = 0; i < 3; i++) {
    int32_T a_tmp_0;
    int32_T a_tmp_1;
    b_norm = vector[i];
    a_tmp_0 = (i + 1) << 2;
    a_0[a_tmp_0] = -b_norm;
    a_0[i + 1] = b_norm;
    a_0[a_tmp_0 + 1] = static_cast<real_T>(b[3 * i]) * c_norm + temp[3 * i];
    a_tmp_1 = 3 * i + 1;
    a_0[a_tmp_0 + 2] = static_cast<real_T>(b[a_tmp_1]) * c_norm + temp[a_tmp_1];
    a_tmp_1 = 3 * i + 2;
    a_0[a_tmp_0 + 3] = static_cast<real_T>(b[a_tmp_1]) * c_norm + temp[a_tmp_1];
  }

  c_norm = rtu_est[1];
  b_norm = rtu_est[0];
  a_tmp = rtu_est[2];
  absxk = rtu_est[3];
  for (int32_T i = 0; i < 4; i++) {
    t = ((a_0[i + 4] * c_norm + a_0[i] * b_norm) + a_0[i + 8] * a_tmp) + a_0[i +
      12] * absxk;
    q[i] = t;
    a[i] = t * t;
  }

  c_norm = sqrt(((a[0] + a[1]) + a[2]) + a[3]);
  q[0] /= c_norm;
  q[1] /= c_norm;
  q[2] /= c_norm;
  q[3] /= c_norm;
  b_norm = 2.0 * acos(q[0]);
  c_norm = sin(b_norm / 2.0);
  a[0] = q[1] / c_norm;
  a[1] = q[2] / c_norm;
  a[2] = q[3] / c_norm;
  rEQ0 = rtIsNaN(a[0]);
  if (!rEQ0) {
    rEQ0 = rtIsNaN(a[1]);
  }

  if (!rEQ0) {
    rEQ0 = rtIsNaN(a[2]);
  }

  if (!rEQ0) {
    rEQ0 = rtIsNaN(b_norm);
  }

  if (rEQ0) {
    q[0] = 1.0;
    q[3] = 0.0;
  } else {
    if (rtIsNaN(b_norm + 3.1415926535897931)) {
      c_norm = (rtNaN);
    } else if (rtIsInf(b_norm + 3.1415926535897931)) {
      c_norm = (rtNaN);
    } else if (b_norm + 3.1415926535897931 == 0.0) {
      c_norm = 0.0;
    } else {
      c_norm = fmod(b_norm + 3.1415926535897931, 6.2831853071795862);
      rEQ0 = (c_norm == 0.0);
      if (!rEQ0) {
        b_norm = fabs((b_norm + 3.1415926535897931) / 6.2831853071795862);
        rEQ0 = !(fabs(b_norm - floor(b_norm + 0.5)) > 2.2204460492503131E-16 *
                 b_norm);
      }

      if (rEQ0) {
        c_norm = 0.0;
      } else if (c_norm < 0.0) {
        c_norm += 6.2831853071795862;
      }
    }

    b_norm = 3.3121686421112381E-170;
    absxk = fabs(a[0]);
    if (absxk > 3.3121686421112381E-170) {
      a_tmp = 1.0;
      b_norm = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      a_tmp = t * t;
    }

    absxk = fabs(a[1]);
    if (absxk > b_norm) {
      t = b_norm / absxk;
      a_tmp = a_tmp * t * t + 1.0;
      b_norm = absxk;
    } else {
      t = absxk / b_norm;
      a_tmp += t * t;
    }

    absxk = fabs(a[2]);
    if (absxk > b_norm) {
      t = b_norm / absxk;
      a_tmp = a_tmp * t * t + 1.0;
      b_norm = absxk;
    } else {
      t = absxk / b_norm;
      a_tmp += t * t;
    }

    c_norm = (c_norm - 3.1415926535897931) / 2.0;
    q[0] = cos(c_norm);
    q[3] = a[2] / (b_norm * sqrt(a_tmp)) * sin(c_norm);
  }

  for (int32_T i = 0; i < 9; i++) {
    temp[i] = rtb_TmpSignalConversionAtSFun_m[i + 4] - rtu_est[i + 4];
  }

  rty_y[0] = q[3] / (q[0] + 1.0);
  rty_y[3] = temp[5];
  rty_y[1] = temp[0];
  rty_y[4] = temp[6];
  rty_y[2] = temp[1];
  rty_y[5] = temp[7];
}

//
// Output and update for atomic system:
//    '<S91>/MATLAB Function'
//    '<S91>/MATLAB Function1'
//
void MPC_MATLABFunction_d(const real_T rtu_u[6], real_T rty_states[12])
{
  rty_states[0] = rtu_u[0];
  rty_states[1] = rtu_u[1];
  rty_states[2] = 0.0;
  rty_states[3] = 0.0;
  rty_states[4] = 0.0;
  rty_states[5] = rtu_u[2];
  rty_states[6] = rtu_u[3];
  rty_states[7] = rtu_u[4];
  rty_states[8] = 0.0;
  rty_states[9] = 0.0;
  rty_states[10] = 0.0;
  rty_states[11] = rtu_u[5];
}

//
// Output and update for atomic system:
//    '<S91>/MATLAB Function11'
//    '<S91>/MATLAB Function12'
//
void MPC_MATLABFunction11(const real_T rtu_q_red[4], const real_T rtu_q_vis[4],
  const real_T rtu_v[3], const real_T rtu_x[3], real_T rty_y[7])
{
  real_T rtu_q_vis_0[16];
  real_T tmp[9];
  real_T b_y[4];
  real_T q[4];
  real_T q_black[4];
  real_T vector[3];
  real_T absxk;
  real_T angle;
  real_T b_norm;
  real_T t;
  int32_T k;
  int32_T rtu_q_vis_tmp;
  int32_T rtu_q_vis_tmp_0;
  int8_T q_tmp[9];
  boolean_T b[4];
  boolean_T c[4];
  boolean_T rEQ0;
  static const int8_T b_b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  boolean_T exitg1;
  b[0] = !rtIsInf(rtu_q_vis[0]);
  c[0] = !rtIsNaN(rtu_q_vis[0]);
  b[1] = !rtIsInf(rtu_q_vis[1]);
  c[1] = !rtIsNaN(rtu_q_vis[1]);
  b[2] = !rtIsInf(rtu_q_vis[2]);
  c[2] = !rtIsNaN(rtu_q_vis[2]);
  b[3] = !rtIsInf(rtu_q_vis[3]);
  c[3] = !rtIsNaN(rtu_q_vis[3]);
  rEQ0 = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    if ((!b[k]) || (!c[k])) {
      rEQ0 = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (rEQ0) {
    real_T rtu_q_red_0;
    vector[0] = rtu_q_vis[1];
    vector[1] = rtu_q_vis[2];
    vector[2] = rtu_q_vis[3];
    b_norm = rtu_q_vis[0];
    tmp[0] = 0.0;
    tmp[3] = -rtu_q_vis[3];
    tmp[6] = rtu_q_vis[2];
    tmp[1] = rtu_q_vis[3];
    tmp[4] = 0.0;
    tmp[7] = -rtu_q_vis[1];
    tmp[2] = -rtu_q_vis[2];
    tmp[5] = rtu_q_vis[1];
    tmp[8] = 0.0;
    rtu_q_vis_0[0] = rtu_q_vis[0];
    for (k = 0; k < 3; k++) {
      t = vector[k];
      rtu_q_vis_tmp = (k + 1) << 2;
      rtu_q_vis_0[rtu_q_vis_tmp] = -t;
      rtu_q_vis_0[k + 1] = t;
      rtu_q_vis_0[rtu_q_vis_tmp + 1] = static_cast<real_T>(b_b[3 * k]) * b_norm
        + tmp[3 * k];
      rtu_q_vis_tmp_0 = 3 * k + 1;
      rtu_q_vis_0[rtu_q_vis_tmp + 2] = static_cast<real_T>(b_b[rtu_q_vis_tmp_0])
        * b_norm + tmp[rtu_q_vis_tmp_0];
      rtu_q_vis_tmp_0 = 3 * k + 2;
      rtu_q_vis_0[rtu_q_vis_tmp + 3] = static_cast<real_T>(b_b[rtu_q_vis_tmp_0])
        * b_norm + tmp[rtu_q_vis_tmp_0];
    }

    angle = rtu_q_red[1];
    b_norm = rtu_q_red[0];
    t = rtu_q_red[2];
    rtu_q_red_0 = rtu_q_red[3];
    for (k = 0; k < 4; k++) {
      absxk = ((rtu_q_vis_0[k + 4] * angle + rtu_q_vis_0[k] * b_norm) +
               rtu_q_vis_0[k + 8] * t) + rtu_q_vis_0[k + 12] * rtu_q_red_0;
      q[k] = absxk;
      b_y[k] = absxk * absxk;
    }

    b_norm = sqrt(((b_y[0] + b_y[1]) + b_y[2]) + b_y[3]);
    q[0] /= b_norm;
    q[1] /= b_norm;
    q[2] /= b_norm;
    q[3] /= b_norm;
    angle = 2.0 * acos(q[0]);
    b_norm = sin(angle / 2.0);
    q_black[0] = q[1] / b_norm;
    q_black[1] = q[2] / b_norm;
    q_black[2] = q[3] / b_norm;
    rEQ0 = rtIsNaN(q_black[0]);
    if (!rEQ0) {
      rEQ0 = rtIsNaN(q_black[1]);
    }

    if (!rEQ0) {
      rEQ0 = rtIsNaN(q_black[2]);
    }

    if (!rEQ0) {
      rEQ0 = rtIsNaN(angle);
    }

    if (rEQ0) {
      q_black[0] = 1.0;
      q_black[1] = 0.0;
      q_black[2] = 0.0;
      q_black[3] = 0.0;
    } else {
      if (rtIsNaN(angle + 3.1415926535897931)) {
        b_norm = (rtNaN);
      } else if (rtIsInf(angle + 3.1415926535897931)) {
        b_norm = (rtNaN);
      } else if (angle + 3.1415926535897931 == 0.0) {
        b_norm = 0.0;
      } else {
        b_norm = fmod(angle + 3.1415926535897931, 6.2831853071795862);
        rEQ0 = (b_norm == 0.0);
        if (!rEQ0) {
          angle = fabs((angle + 3.1415926535897931) / 6.2831853071795862);
          rEQ0 = !(fabs(angle - floor(angle + 0.5)) > 2.2204460492503131E-16 *
                   angle);
        }

        if (rEQ0) {
          b_norm = 0.0;
        } else if (b_norm < 0.0) {
          b_norm += 6.2831853071795862;
        }
      }

      angle = 3.3121686421112381E-170;
      absxk = fabs(q_black[0]);
      if (absxk > 3.3121686421112381E-170) {
        rtu_q_red_0 = 1.0;
        angle = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        rtu_q_red_0 = t * t;
      }

      absxk = fabs(q_black[1]);
      if (absxk > angle) {
        t = angle / absxk;
        rtu_q_red_0 = rtu_q_red_0 * t * t + 1.0;
        angle = absxk;
      } else {
        t = absxk / angle;
        rtu_q_red_0 += t * t;
      }

      absxk = fabs(q_black[2]);
      if (absxk > angle) {
        t = angle / absxk;
        rtu_q_red_0 = rtu_q_red_0 * t * t + 1.0;
        angle = absxk;
      } else {
        t = absxk / angle;
        rtu_q_red_0 += t * t;
      }

      rtu_q_red_0 = angle * sqrt(rtu_q_red_0);
      vector[0] = q_black[0] / rtu_q_red_0;
      vector[1] = q_black[1] / rtu_q_red_0;
      vector[2] = q_black[2] / rtu_q_red_0;
      b_norm = (b_norm - 3.1415926535897931) / 2.0;
      angle = sin(b_norm);
      q_black[0] = cos(b_norm);
      q_black[1] = vector[0] * angle;
      q_black[2] = vector[1] * angle;
      q_black[3] = vector[2] * angle;
    }
  } else {
    q_black[0] = (rtNaN);
    q_black[1] = (rtNaN);
    q_black[2] = (rtNaN);
    q_black[3] = (rtNaN);
  }

  b_norm = sqrt(((rtu_q_red[0] * rtu_q_red[0] + rtu_q_red[1] * rtu_q_red[1]) +
                 rtu_q_red[2] * rtu_q_red[2]) + rtu_q_red[3] * rtu_q_red[3]);
  vector[0] = rtu_q_red[1];
  vector[1] = rtu_q_red[2];
  vector[2] = rtu_q_red[3];
  for (k = 0; k < 9; k++) {
    q_tmp[k] = b_b[k];
  }

  angle = rtu_q_red[0];
  tmp[0] = 0.0;
  tmp[3] = -rtu_q_red[3];
  tmp[6] = rtu_q_red[2];
  tmp[1] = rtu_q_red[3];
  tmp[4] = 0.0;
  tmp[7] = -rtu_q_red[1];
  tmp[2] = -rtu_q_red[2];
  tmp[5] = rtu_q_red[1];
  tmp[8] = 0.0;
  rtu_q_vis_0[0] = rtu_q_red[0];
  for (k = 0; k < 3; k++) {
    t = vector[k];
    rtu_q_vis_tmp = (k + 1) << 2;
    rtu_q_vis_0[rtu_q_vis_tmp] = -t;
    rtu_q_vis_0[k + 1] = t;
    rtu_q_vis_0[rtu_q_vis_tmp + 1] = static_cast<real_T>(q_tmp[3 * k]) * angle +
      tmp[3 * k];
    rtu_q_vis_tmp_0 = 3 * k + 1;
    rtu_q_vis_0[rtu_q_vis_tmp + 2] = static_cast<real_T>(q_tmp[rtu_q_vis_tmp_0])
      * angle + tmp[rtu_q_vis_tmp_0];
    rtu_q_vis_tmp_0 = 3 * k + 2;
    rtu_q_vis_0[rtu_q_vis_tmp + 3] = static_cast<real_T>(q_tmp[rtu_q_vis_tmp_0])
      * angle + tmp[rtu_q_vis_tmp_0];
    q[k + 1] = rtu_v[k];
  }

  angle = q[1];
  absxk = q[2];
  t = q[3];
  for (k = 0; k < 4; k++) {
    q[k] = ((rtu_q_vis_0[k + 4] * angle + rtu_q_vis_0[k] * 0.0) + rtu_q_vis_0[k
            + 8] * absxk) + rtu_q_vis_0[k + 12] * t;
  }

  vector[0] = q[1];
  vector[1] = q[2];
  vector[2] = q[3];
  absxk = q[0];
  tmp[0] = 0.0;
  tmp[3] = -q[3];
  tmp[6] = q[2];
  tmp[1] = q[3];
  tmp[4] = 0.0;
  tmp[7] = -q[1];
  tmp[2] = -q[2];
  tmp[5] = q[1];
  tmp[8] = 0.0;
  b_norm *= b_norm;
  rtu_q_vis_0[0] = q[0];
  for (k = 0; k < 3; k++) {
    t = vector[k];
    rtu_q_vis_tmp = (k + 1) << 2;
    rtu_q_vis_0[rtu_q_vis_tmp] = -t;
    rtu_q_vis_0[k + 1] = t;
    rtu_q_vis_0[rtu_q_vis_tmp + 1] = static_cast<real_T>(q_tmp[3 * k]) * absxk +
      tmp[3 * k];
    rtu_q_vis_tmp_0 = 3 * k + 1;
    rtu_q_vis_0[rtu_q_vis_tmp + 2] = static_cast<real_T>(q_tmp[rtu_q_vis_tmp_0])
      * absxk + tmp[rtu_q_vis_tmp_0];
    rtu_q_vis_tmp_0 = 3 * k + 2;
    rtu_q_vis_0[rtu_q_vis_tmp + 3] = static_cast<real_T>(q_tmp[rtu_q_vis_tmp_0])
      * absxk + tmp[rtu_q_vis_tmp_0];
  }

  angle = rtu_q_red[0] / b_norm;
  absxk = -rtu_q_red[1] / b_norm;
  t = -rtu_q_red[2] / b_norm;
  b_norm = -rtu_q_red[3] / b_norm;
  for (k = 0; k < 4; k++) {
    q[k] = ((rtu_q_vis_0[k + 4] * absxk + rtu_q_vis_0[k] * angle) +
            rtu_q_vis_0[k + 8] * t) + rtu_q_vis_0[k + 12] * b_norm;
    rty_y[k] = q_black[k];
  }

  rty_y[4] = rtu_x[0] + q[1];
  rty_y[5] = rtu_x[1] + q[2];
  rty_y[6] = rtu_x[2] + q[3];
}

//
// Output and update for atomic system:
//    '<S97>/MATLAB Function'
//    '<S101>/MATLAB Function2'
//
void MPC_MATLABFunction_a(const real_T rtu_u[13], real_T rty_out[13])
{
  real_T y[13];
  real_T a_idx_0;
  real_T a_idx_1;
  real_T angle;
  real_T b_norm;
  real_T den;
  boolean_T rEQ0;
  memcpy(&y[0], &rtu_u[0], 13U * sizeof(real_T));
  b_norm = sqrt(((rtu_u[0] * rtu_u[0] + rtu_u[1] * rtu_u[1]) + rtu_u[2] * rtu_u
                 [2]) + rtu_u[3] * rtu_u[3]);
  angle = acos(rtu_u[0] / b_norm) * 2.0;
  den = sin(angle / 2.0);
  a_idx_0 = rtu_u[1] / b_norm / den;
  a_idx_1 = rtu_u[2] / b_norm / den;
  b_norm = rtu_u[3] / b_norm / den;
  rEQ0 = rtIsNaN(a_idx_0);
  if (!rEQ0) {
    rEQ0 = rtIsNaN(a_idx_1);
  }

  if (!rEQ0) {
    rEQ0 = rtIsNaN(b_norm);
  }

  if (!rEQ0) {
    rEQ0 = rtIsNaN(angle);
  }

  if (rEQ0) {
    rty_out[0] = 1.0;
    a_idx_1 = 0.0;
    b_norm = 0.0;
    a_idx_0 = 0.0;
  } else {
    real_T absxk;
    real_T scale;
    real_T t;
    if (rtIsNaN(angle + 3.1415926535897931)) {
      den = (rtNaN);
    } else if (rtIsInf(angle + 3.1415926535897931)) {
      den = (rtNaN);
    } else if (angle + 3.1415926535897931 == 0.0) {
      den = 0.0;
    } else {
      den = fmod(angle + 3.1415926535897931, 6.2831853071795862);
      rEQ0 = (den == 0.0);
      if (!rEQ0) {
        angle = fabs((angle + 3.1415926535897931) / 6.2831853071795862);
        rEQ0 = !(fabs(angle - floor(angle + 0.5)) > 2.2204460492503131E-16 *
                 angle);
      }

      if (rEQ0) {
        den = 0.0;
      } else if (den < 0.0) {
        den += 6.2831853071795862;
      }
    }

    scale = 3.3121686421112381E-170;
    absxk = fabs(a_idx_0);
    if (absxk > 3.3121686421112381E-170) {
      angle = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      angle = t * t;
    }

    absxk = fabs(a_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      angle = angle * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      angle += t * t;
    }

    absxk = fabs(b_norm);
    if (absxk > scale) {
      t = scale / absxk;
      angle = angle * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      angle += t * t;
    }

    angle = scale * sqrt(angle);
    scale = a_idx_1 / angle;
    absxk = b_norm / angle;
    a_idx_1 = (den - 3.1415926535897931) / 2.0;
    den = sin(a_idx_1);
    rty_out[0] = cos(a_idx_1);
    a_idx_1 = a_idx_0 / angle * den;
    b_norm = scale * den;
    a_idx_0 = absxk * den;
  }

  rty_out[1] = a_idx_1;
  rty_out[2] = b_norm;
  rty_out[3] = a_idx_0;
  rty_out[4] = y[7];
  rty_out[7] = -rtu_u[4];
  rty_out[10] = y[10];
  rty_out[5] = y[8];
  rty_out[8] = -rtu_u[5];
  rty_out[11] = y[11];
  rty_out[6] = y[9];
  rty_out[9] = -rtu_u[6];
  rty_out[12] = y[12];
}

//
// Output and update for atomic system:
//    '<S98>/MATLAB Function'
//    '<S102>/MATLAB Function'
//
void MPC_MATLABFunction_gs(const real_T rtu_x[9], const real_T rtu_q[4], real_T
  rty_out[13])
{
  real_T y[13];
  real_T a_idx_0;
  real_T a_idx_1;
  real_T angle;
  real_T b_norm;
  real_T den;
  boolean_T rEQ0;
  y[0] = rtu_q[0];
  y[1] = rtu_q[1];
  y[2] = rtu_q[2];
  y[3] = rtu_q[3];
  memcpy(&y[4], &rtu_x[0], 9U * sizeof(real_T));
  b_norm = sqrt(((y[0] * y[0] + y[1] * y[1]) + y[2] * y[2]) + y[3] * y[3]);
  angle = acos(y[0] / b_norm) * 2.0;
  den = sin(angle / 2.0);
  a_idx_0 = y[1] / b_norm / den;
  a_idx_1 = y[2] / b_norm / den;
  b_norm = y[3] / b_norm / den;
  rEQ0 = rtIsNaN(a_idx_0);
  if (!rEQ0) {
    rEQ0 = rtIsNaN(a_idx_1);
  }

  if (!rEQ0) {
    rEQ0 = rtIsNaN(b_norm);
  }

  if (!rEQ0) {
    rEQ0 = rtIsNaN(angle);
  }

  if (rEQ0) {
    y[0] = 1.0;
    y[1] = 0.0;
    y[2] = 0.0;
    y[3] = 0.0;
  } else {
    real_T absxk;
    real_T scale;
    real_T t;
    if (rtIsNaN(angle + 3.1415926535897931)) {
      den = (rtNaN);
    } else if (rtIsInf(angle + 3.1415926535897931)) {
      den = (rtNaN);
    } else if (angle + 3.1415926535897931 == 0.0) {
      den = 0.0;
    } else {
      den = fmod(angle + 3.1415926535897931, 6.2831853071795862);
      rEQ0 = (den == 0.0);
      if (!rEQ0) {
        angle = fabs((angle + 3.1415926535897931) / 6.2831853071795862);
        rEQ0 = !(fabs(angle - floor(angle + 0.5)) > 2.2204460492503131E-16 *
                 angle);
      }

      if (rEQ0) {
        den = 0.0;
      } else if (den < 0.0) {
        den += 6.2831853071795862;
      }
    }

    scale = 3.3121686421112381E-170;
    absxk = fabs(a_idx_0);
    if (absxk > 3.3121686421112381E-170) {
      angle = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      angle = t * t;
    }

    absxk = fabs(a_idx_1);
    if (absxk > scale) {
      t = scale / absxk;
      angle = angle * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      angle += t * t;
    }

    absxk = fabs(b_norm);
    if (absxk > scale) {
      t = scale / absxk;
      angle = angle * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      angle += t * t;
    }

    angle = scale * sqrt(angle);
    den = (den - 3.1415926535897931) / 2.0;
    scale = sin(den);
    y[0] = cos(den);
    y[1] = a_idx_0 / angle * scale;
    y[2] = a_idx_1 / angle * scale;
    y[3] = b_norm / angle * scale;
  }

  for (int32_T i = 0; i < 7; i++) {
    rty_out[i] = y[i];
  }

  rty_out[7] = y[10];
  rty_out[10] = y[7];
  rty_out[8] = y[11];
  rty_out[11] = y[8];
  rty_out[9] = y[12];
  rty_out[12] = y[9];
}

//
// Output and update for atomic system:
//    '<S98>/MATLAB Function11'
//    '<S102>/MATLAB Function11'
//
void MPC_MATLABFunction11_l(const real_T rtu_u[9], real_T rty_y[4])
{
  real_T A[9];
  real_T u[9];
  real_T smax;
  int8_T ipiv[3];
  boolean_T isodd;
  memcpy(&u[0], &rtu_u[0], 9U * sizeof(real_T));
  memcpy(&A[0], &rtu_u[0], 9U * sizeof(real_T));
  ipiv[0] = 1;
  ipiv[1] = 2;
  for (int32_T j = 0; j < 2; j++) {
    int32_T a;
    int32_T c_k;
    int32_T jA;
    int32_T jj;
    int32_T n;
    jj = j << 2;
    n = 2 - j;
    a = 0;
    smax = fabs(A[jj]);
    for (c_k = 2; c_k <= n + 1; c_k++) {
      real_T s;
      s = fabs(A[(jj + c_k) - 1]);
      if (s > smax) {
        a = c_k - 1;
        smax = s;
      }
    }

    if (A[jj + a] != 0.0) {
      if (a != 0) {
        c_k = j + a;
        ipiv[j] = static_cast<int8_T>(c_k + 1);
        smax = A[j];
        A[j] = A[c_k];
        A[c_k] = smax;
        smax = A[j + 3];
        A[j + 3] = A[c_k + 3];
        A[c_k + 3] = smax;
        smax = A[j + 6];
        A[j + 6] = A[c_k + 6];
        A[c_k + 6] = smax;
      }

      n = (jj - j) + 3;
      for (c_k = jj + 2; c_k <= n; c_k++) {
        A[c_k - 1] /= A[jj];
      }
    }

    a = 1 - j;
    jA = jj + 5;
    for (c_k = 0; c_k <= a; c_k++) {
      smax = A[(c_k * 3 + jj) + 3];
      if (smax != 0.0) {
        int32_T c;
        c = (jA - j) + 1;
        for (n = jA; n <= c; n++) {
          A[n - 1] += A[((jj + n) - jA) + 1] * -smax;
        }
      }

      jA += 3;
    }
  }

  isodd = (ipiv[0] > 1);
  smax = A[0] * A[4] * A[8];
  if (ipiv[1] > 2) {
    isodd = !isodd;
  }

  if (isodd) {
    smax = -smax;
  }

  if (smax == 0.0) {
    memset(&u[0], 0, 9U * sizeof(real_T));
    u[0] = 1.0;
    u[4] = 1.0;
    u[8] = 1.0;
  }

  for (int32_T j = 0; j < 3; j++) {
    A[3 * j] = u[j];
    A[3 * j + 1] = u[j + 3];
    A[3 * j + 2] = u[j + 6];
  }

  smax = (A[0] + A[4]) + A[8];
  if (smax > 0.0) {
    smax = sqrt(smax + 1.0) * 2.0;
    rty_y[0] = 0.25 * smax;
    rty_y[1] = (A[5] - A[7]) / smax;
    rty_y[2] = (A[6] - A[2]) / smax;
    rty_y[3] = (A[1] - A[3]) / smax;
  } else if ((A[0] > A[4]) && (A[0] > A[8])) {
    smax = sqrt(((A[0] + 1.0) - A[4]) - A[8]) * 2.0;
    rty_y[0] = (A[5] - A[7]) / smax;
    rty_y[1] = 0.25 * smax;
    rty_y[2] = (A[1] + A[3]) / smax;
    rty_y[3] = (A[2] + A[6]) / smax;
  } else if (A[4] > A[8]) {
    smax = sqrt(((A[4] + 1.0) - A[0]) - A[8]) * 2.0;
    rty_y[0] = (A[6] - A[2]) / smax;
    rty_y[1] = (A[1] + A[3]) / smax;
    rty_y[2] = 0.25 * smax;
    rty_y[3] = (A[5] + A[7]) / smax;
  } else {
    smax = sqrt(((A[8] + 1.0) - A[0]) - A[4]) * 2.0;
    rty_y[0] = (A[1] - A[3]) / smax;
    rty_y[1] = (A[2] + A[6]) / smax;
    rty_y[2] = (A[5] + A[7]) / smax;
    rty_y[3] = 0.25 * smax;
  }
}

//
// Output and update for atomic system:
//    '<S170>/MATLAB Function'
//    '<S147>/MATLAB Function'
//    '<S160>/MATLAB Function'
//    '<S137>/MATLAB Function'
//    '<S165>/MATLAB Function'
//    '<S142>/MATLAB Function'
//
void MPC_MATLABFunction_m(real_T rtu_Rz_path, real_T rtu_Rz_measured, real_T
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
//    '<S4>/Disable Thrusters (RED)'
//    '<S4>/Custom Control (ARM)'
//
void MPC_DisableThrustersRED(real_T rty_u[3], P_DisableThrustersRED_MPC_T
  *localP)
{
  // SignalConversion generated from: '<S135>/u' incorporates:
  //   Constant: '<S135>/Zero'

  rty_u[0] = localP->Zero_Value;
  rty_u[1] = localP->Zero_Value;
  rty_u[2] = localP->Zero_Value;
}

//
// System initialize for action system:
//    '<S4>/Default PD Control (BLACK)'
//    '<S4>/Default LQR Control (BLACK)'
//
void MPC_DefaultPDControlBLACK_Init(DW_DefaultPDControlBLACK_MPC_T *localDW,
  P_DefaultPDControlBLACK_MPC_T *localP)
{
  // InitializeConditions for UnitDelay: '<S161>/UD'
  //
  //  Block description for '<S161>/UD':
  //
  //   Store in Global RAM

  localDW->UD_DSTATE = localP->DiscreteDerivative_ICPrevScaled;

  // InitializeConditions for UnitDelay: '<S162>/UD'
  //
  //  Block description for '<S162>/UD':
  //
  //   Store in Global RAM

  localDW->UD_DSTATE_g = localP->DiscreteDerivative1_ICPrevScale;

  // InitializeConditions for UnitDelay: '<S163>/UD'
  //
  //  Block description for '<S163>/UD':
  //
  //   Store in Global RAM

  localDW->UD_DSTATE_e = localP->DiscreteDerivative2_ICPrevScale;
}

//
// Output and update for action system:
//    '<S4>/Default PD Control (BLACK)'
//    '<S4>/Default LQR Control (BLACK)'
//
void MPC_DefaultPDControlBLACK(real_T rty_u[3], real_T rtd_BLACK_CTL_Input[6],
  const real_T rtd_BLACK_Measured_States[9], const real_T rtd_BLACK_Path[3],
  DW_DefaultPDControlBLACK_MPC_T *localDW, P_DefaultPDControlBLACK_MPC_T *localP)
{
  real_T tmp[18];
  real_T rtb_Subtract8_pl;
  real_T rtb_TSamp_a2;
  real_T rtb_TSamp_dr;
  real_T rtb_TSamp_fi;
  int32_T i;
  int32_T i_0;

  // MATLAB Function: '<S160>/MATLAB Function' incorporates:
  //   DataStoreRead: '<S129>/Data Store Read1'
  //   DataStoreRead: '<S129>/Data Store Read13'

  MPC_MATLABFunction_m(rtd_BLACK_Path[2], rtd_BLACK_Measured_States[2],
                       &rtb_Subtract8_pl);

  // SampleTimeMath: '<S161>/TSamp' incorporates:
  //   DataStoreRead: '<S129>/Data Store Read1'
  //
  //  About '<S161>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  rtb_TSamp_fi = rtd_BLACK_Path[0] * localP->TSamp_WtEt;

  // SampleTimeMath: '<S162>/TSamp' incorporates:
  //   DataStoreRead: '<S129>/Data Store Read1'
  //
  //  About '<S162>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  rtb_TSamp_a2 = rtd_BLACK_Path[1] * localP->TSamp_WtEt_l;

  // SampleTimeMath: '<S163>/TSamp' incorporates:
  //   DataStoreRead: '<S129>/Data Store Read1'
  //
  //  About '<S163>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //
  rtb_TSamp_dr = rtd_BLACK_Path[2] * localP->TSamp_WtEt_o;

  // SignalConversion generated from: '<S129>/Matrix Multiply' incorporates:
  //   DataStoreRead: '<S129>/Data Store Read1'
  //   DataStoreRead: '<S129>/Data Store Read13'
  //   Reshape: '<S129>/Reshape1'
  //   Sum: '<S129>/Subtract4'
  //   Sum: '<S129>/Subtract5'
  //   Sum: '<S129>/Subtract6'
  //   Sum: '<S129>/Subtract7'
  //   Sum: '<S129>/Subtract8'
  //   Sum: '<S161>/Diff'
  //   Sum: '<S162>/Diff'
  //   Sum: '<S163>/Diff'
  //   UnitDelay: '<S161>/UD'
  //   UnitDelay: '<S162>/UD'
  //   UnitDelay: '<S163>/UD'
  //
  //  Block description for '<S161>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S162>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S163>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S161>/UD':
  //
  //   Store in Global RAM
  //
  //  Block description for '<S162>/UD':
  //
  //   Store in Global RAM
  //
  //  Block description for '<S163>/UD':
  //
  //   Store in Global RAM

  rtd_BLACK_CTL_Input[0] = rtd_BLACK_Measured_States[0] - rtd_BLACK_Path[0];
  rtd_BLACK_CTL_Input[1] = rtd_BLACK_Measured_States[1] - rtd_BLACK_Path[1];
  rtd_BLACK_CTL_Input[2] = rtb_Subtract8_pl;
  rtd_BLACK_CTL_Input[3] = rtd_BLACK_Measured_States[3] - (rtb_TSamp_fi -
    localDW->UD_DSTATE);
  rtd_BLACK_CTL_Input[4] = rtd_BLACK_Measured_States[4] - (rtb_TSamp_a2 -
    localDW->UD_DSTATE_g);
  rtd_BLACK_CTL_Input[5] = rtd_BLACK_Measured_States[5] - (rtb_TSamp_dr -
    localDW->UD_DSTATE_e);
  for (i = 0; i < 18; i++) {
    // Product: '<S129>/Matrix Multiply' incorporates:
    //   Constant: '<S129>/Constant2'

    tmp[i] = -MPC_P.K_BLACK[i];
  }

  // Reshape: '<S129>/Reshape4' incorporates:
  //   Product: '<S129>/Matrix Multiply'
  //   SignalConversion generated from: '<S129>/Matrix Multiply'

  for (i = 0; i < 3; i++) {
    // Product: '<S129>/Matrix Multiply'
    rtb_Subtract8_pl = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Subtract8_pl += tmp[3 * i_0 + i] * rtd_BLACK_CTL_Input[i_0];
    }

    rty_u[i] = rtb_Subtract8_pl;
  }

  // End of Reshape: '<S129>/Reshape4'

  // Update for UnitDelay: '<S161>/UD'
  //
  //  Block description for '<S161>/UD':
  //
  //   Store in Global RAM

  localDW->UD_DSTATE = rtb_TSamp_fi;

  // Update for UnitDelay: '<S162>/UD'
  //
  //  Block description for '<S162>/UD':
  //
  //   Store in Global RAM

  localDW->UD_DSTATE_g = rtb_TSamp_a2;

  // Update for UnitDelay: '<S163>/UD'
  //
  //  Block description for '<S163>/UD':
  //
  //   Store in Global RAM

  localDW->UD_DSTATE_e = rtb_TSamp_dr;
}

//
// System initialize for action system:
//    '<S5>/Change BLACK Behavior'
//    '<S5>/Change BLUE Behavior'
//    '<S5>/Change RED Behavior'
//
void MPC_ChangeBLACKBehavior_Init(RT_MODEL_MPC_T * const MPC_M,
  DW_ChangeBLACKBehavior_MPC_T *localDW, P_ChangeBLACKBehavior_MPC_T *localP)
{
  char_T *sErr;

  // Start for S-Function (sdspToNetwork): '<S176>/UDP Send'
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
      MPC_M->setErrorStatus(sErr);
      MPC_M->setStopRequested(1);
    }
  }

  // End of Start for S-Function (sdspToNetwork): '<S176>/UDP Send'
}

//
// Output and update for action system:
//    '<S5>/Change BLACK Behavior'
//    '<S5>/Change BLUE Behavior'
//    '<S5>/Change RED Behavior'
//
void MPC_ChangeBLACKBehavior(RT_MODEL_MPC_T * const MPC_M,
  DW_ChangeBLACKBehavior_MPC_T *localDW, P_ChangeBLACKBehavior_MPC_T *localP)
{
  char_T *sErr;

  // Update for S-Function (sdspToNetwork): '<S176>/UDP Send' incorporates:
  //   Constant: '<S176>/Constant1'

  sErr = GetErrorBuffer(&localDW->UDPSend_NetworkLib[0U]);
  LibUpdate_Network(&localDW->UDPSend_NetworkLib[0U], &localP->Constant1_Value,
                    1);
  if (*sErr != 0) {
    MPC_M->setErrorStatus(sErr);
    MPC_M->setStopRequested(1);
  }

  // End of Update for S-Function (sdspToNetwork): '<S176>/UDP Send'
}

//
// Termination for action system:
//    '<S5>/Change BLACK Behavior'
//    '<S5>/Change BLUE Behavior'
//    '<S5>/Change RED Behavior'
//
void MPC_ChangeBLACKBehavior_Term(RT_MODEL_MPC_T * const MPC_M,
  DW_ChangeBLACKBehavior_MPC_T *localDW)
{
  char_T *sErr;

  // Terminate for S-Function (sdspToNetwork): '<S176>/UDP Send'
  sErr = GetErrorBuffer(&localDW->UDPSend_NetworkLib[0U]);
  LibTerminate(&localDW->UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    MPC_M->setErrorStatus(sErr);
    MPC_M->setStopRequested(1);
  }

  LibDestroy(&localDW->UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&localDW->UDPSend_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S176>/UDP Send'
}

//
// Output and update for atomic system:
//    '<S180>/MATLAB Function'
//    '<S182>/MATLAB Function'
//    '<S184>/MATLAB Function'
//    '<S185>/MATLAB Function'
//    '<S188>/MATLAB Function'
//    '<S190>/MATLAB Function'
//    '<S191>/MATLAB Function'
//    '<S195>/MATLAB Function'
//
void MPC_MATLABFunction_f(real_T rtu_u, real_T *rty_y)
{
  if (rtIsNaN(rtu_u)) {
    *rty_y = -1.0;
  } else {
    *rty_y = rtu_u;
  }
}

//
// Output and update for atomic system:
//    '<S181>/MATLAB Function'
//    '<S189>/MATLAB Function'
//    '<S192>/MATLAB Function'
//    '<S193>/MATLAB Function'
//    '<S194>/MATLAB Function'
//    '<S196>/MATLAB Function'
//
void MPC_MATLABFunction_j(const real_T rtu_u[6], real_T rty_y[6])
{
  boolean_T tf;
  tf = false;
  for (int32_T k = 0; k < 6; k++) {
    if (!tf) {
      tf = rtIsNaN(rtu_u[k]);
    }
  }

  for (int32_T k = 0; k < 6; k++) {
    if (tf) {
      rty_y[k] = -1.0;
    } else {
      rty_y[k] = rtu_u[k];
    }
  }
}

//
// Output and update for atomic system:
//    '<S183>/MATLAB Function'
//    '<S186>/MATLAB Function'
//
void MPC_MATLABFunction_c(const real_T rtu_u[3], real_T rty_y[3])
{
  boolean_T tf;
  tf = rtIsNaN(rtu_u[0]);
  if (!tf) {
    tf = rtIsNaN(rtu_u[1]);
  }

  if (!tf) {
    tf = rtIsNaN(rtu_u[2]);
  }

  if (tf) {
    rty_y[0] = -1.0;
    rty_y[1] = -1.0;
    rty_y[2] = -1.0;
  } else {
    rty_y[0] = rtu_u[0];
    rty_y[1] = rtu_u[1];
    rty_y[2] = rtu_u[2];
  }
}

//
// Output and update for atomic system:
//    '<S233>/MATLAB Function'
//    '<S243>/MATLAB Function'
//    '<S253>/MATLAB Function'
//
void MPC_MATLABFunction_jn(real_T rtu_dt, real_T rtu_dataRate, real_T
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
//    '<S234>/Enabled Subsystem'
//    '<S244>/Enabled Subsystem'
//    '<S254>/Enabled Subsystem'
//
void MPC_EnabledSubsystem_Init(real_T rty_dydt[3], DW_EnabledSubsystem_MPC_T
  *localDW, P_EnabledSubsystem_MPC_T *localP)
{
  // InitializeConditions for Delay: '<S239>/Delay'
  localDW->icLoad = true;

  // InitializeConditions for Delay: '<S239>/Delay1'
  localDW->Delay1_DSTATE[0] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S239>/dy//dt'
  rty_dydt[0] = localP->dydt_Y0;

  // InitializeConditions for Delay: '<S239>/Delay1'
  localDW->Delay1_DSTATE[1] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S239>/dy//dt'
  rty_dydt[1] = localP->dydt_Y0;

  // InitializeConditions for Delay: '<S239>/Delay1'
  localDW->Delay1_DSTATE[2] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S239>/dy//dt'
  rty_dydt[2] = localP->dydt_Y0;
}

//
// Disable for enable system:
//    '<S234>/Enabled Subsystem'
//    '<S244>/Enabled Subsystem'
//    '<S254>/Enabled Subsystem'
//
void MPC_EnabledSubsystem_Disable(DW_EnabledSubsystem_MPC_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

//
// Outputs for enable system:
//    '<S234>/Enabled Subsystem'
//    '<S244>/Enabled Subsystem'
//    '<S254>/Enabled Subsystem'
//
void MPC_EnabledSubsystem(const boolean_T rtu_Enable[3], const real_T rtu_y[3],
  real_T rtu_dt, real_T rty_dydt[3], B_EnabledSubsystem_MPC_T *localB,
  DW_EnabledSubsystem_MPC_T *localDW, P_EnabledSubsystem_MPC_T *localP)
{
  real_T ema;
  real_T x;

  // Outputs for Enabled SubSystem: '<S234>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S239>/Enable'

  if (rtu_Enable[0] || rtu_Enable[1] || rtu_Enable[2]) {
    localDW->EnabledSubsystem_MODE = true;
  } else if (localDW->EnabledSubsystem_MODE) {
    MPC_EnabledSubsystem_Disable(localDW);
  }

  if (localDW->EnabledSubsystem_MODE) {
    // Delay: '<S239>/Delay'
    if (localDW->icLoad) {
      localDW->Delay_DSTATE[0] = rtu_y[0];
      localDW->Delay_DSTATE[1] = rtu_y[1];
      localDW->Delay_DSTATE[2] = rtu_y[2];
    }

    // MATLAB Function: '<S239>/MATLAB Function' incorporates:
    //   Constant: '<S239>/Constant2'

    x = exp(-rtu_dt / localP->Constant2_Value);

    // Delay: '<S239>/Delay'
    localB->Delay[0] = localDW->Delay_DSTATE[0];

    // Delay: '<S239>/Delay1'
    localB->Delay1[0] = localDW->Delay1_DSTATE[0];

    // MATLAB Function: '<S239>/MATLAB Function' incorporates:
    //   Delay: '<S239>/Delay'

    ema = (1.0 - (1.0 - x)) * localDW->Delay_DSTATE[0] + (1.0 - x) * rtu_y[0];
    localB->ema[0] = ema;

    // MATLAB Function: '<S239>/MATLAB Function' incorporates:
    //   Delay: '<S239>/Delay'

    rty_dydt[0] = (ema - localDW->Delay_DSTATE[0]) / rtu_dt;

    // Delay: '<S239>/Delay'
    localB->Delay[1] = localDW->Delay_DSTATE[1];

    // Delay: '<S239>/Delay1'
    localB->Delay1[1] = localDW->Delay1_DSTATE[1];

    // MATLAB Function: '<S239>/MATLAB Function' incorporates:
    //   Delay: '<S239>/Delay'

    ema = (1.0 - (1.0 - x)) * localDW->Delay_DSTATE[1] + (1.0 - x) * rtu_y[1];
    localB->ema[1] = ema;

    // MATLAB Function: '<S239>/MATLAB Function' incorporates:
    //   Delay: '<S239>/Delay'

    rty_dydt[1] = (ema - localDW->Delay_DSTATE[1]) / rtu_dt;

    // Delay: '<S239>/Delay'
    localB->Delay[2] = localDW->Delay_DSTATE[2];

    // Delay: '<S239>/Delay1'
    localB->Delay1[2] = localDW->Delay1_DSTATE[2];

    // MATLAB Function: '<S239>/MATLAB Function' incorporates:
    //   Delay: '<S239>/Delay'

    ema = (1.0 - (1.0 - x)) * localDW->Delay_DSTATE[2] + (1.0 - x) * rtu_y[2];
    localB->ema[2] = ema;

    // MATLAB Function: '<S239>/MATLAB Function' incorporates:
    //   Delay: '<S239>/Delay'

    rty_dydt[2] = (ema - localDW->Delay_DSTATE[2]) / rtu_dt;
  }

  // End of Outputs for SubSystem: '<S234>/Enabled Subsystem'
}

//
// Update for enable system:
//    '<S234>/Enabled Subsystem'
//    '<S244>/Enabled Subsystem'
//    '<S254>/Enabled Subsystem'
//
void MPC_EnabledSubsystem_Update(real_T rty_dydt[3], B_EnabledSubsystem_MPC_T
  *localB, DW_EnabledSubsystem_MPC_T *localDW)
{
  // Update for Enabled SubSystem: '<S234>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S239>/Enable'

  if (localDW->EnabledSubsystem_MODE) {
    // Update for Delay: '<S239>/Delay'
    localDW->icLoad = false;
    localDW->Delay_DSTATE[0] = localB->ema[0];

    // Update for Delay: '<S239>/Delay1'
    localDW->Delay1_DSTATE[0] = rty_dydt[0];

    // Update for Delay: '<S239>/Delay'
    localDW->Delay_DSTATE[1] = localB->ema[1];

    // Update for Delay: '<S239>/Delay1'
    localDW->Delay1_DSTATE[1] = rty_dydt[1];

    // Update for Delay: '<S239>/Delay'
    localDW->Delay_DSTATE[2] = localB->ema[2];

    // Update for Delay: '<S239>/Delay1'
    localDW->Delay1_DSTATE[2] = rty_dydt[2];
  }

  // End of Update for SubSystem: '<S234>/Enabled Subsystem'
}

//
// System initialize for enable system:
//    '<S235>/Enabled Subsystem'
//    '<S245>/Enabled Subsystem'
//    '<S255>/Enabled Subsystem'
//
void MPC_EnabledSubsystem_h_Init(real_T rty_dydt[3], DW_EnabledSubsystem_MPC_m_T
  *localDW, P_EnabledSubsystem_MPC_d_T *localP)
{
  // InitializeConditions for Delay: '<S241>/Delay'
  localDW->icLoad = true;

  // InitializeConditions for Delay: '<S241>/Delay1'
  localDW->Delay1_DSTATE[0] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S241>/dy//dt'
  rty_dydt[0] = localP->dydt_Y0;

  // InitializeConditions for Delay: '<S241>/Delay1'
  localDW->Delay1_DSTATE[1] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S241>/dy//dt'
  rty_dydt[1] = localP->dydt_Y0;

  // InitializeConditions for Delay: '<S241>/Delay1'
  localDW->Delay1_DSTATE[2] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S241>/dy//dt'
  rty_dydt[2] = localP->dydt_Y0;
}

//
// Disable for enable system:
//    '<S235>/Enabled Subsystem'
//    '<S245>/Enabled Subsystem'
//    '<S255>/Enabled Subsystem'
//
void MPC_EnabledSubsystem_h_Disable(DW_EnabledSubsystem_MPC_m_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

//
// Outputs for enable system:
//    '<S235>/Enabled Subsystem'
//    '<S245>/Enabled Subsystem'
//    '<S255>/Enabled Subsystem'
//
void MPC_EnabledSubsystem_n(const boolean_T rtu_Enable[3], real_T rtu_y, real_T
  rtu_y_p, real_T rtu_y_o, real_T rtu_dt, real_T rty_dydt[3],
  B_EnabledSubsystem_MPC_b_T *localB, DW_EnabledSubsystem_MPC_m_T *localDW,
  P_EnabledSubsystem_MPC_d_T *localP)
{
  real_T x;

  // Outputs for Enabled SubSystem: '<S235>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S241>/Enable'

  if (rtu_Enable[0] || rtu_Enable[1] || rtu_Enable[2]) {
    localDW->EnabledSubsystem_MODE = true;
  } else if (localDW->EnabledSubsystem_MODE) {
    MPC_EnabledSubsystem_h_Disable(localDW);
  }

  if (localDW->EnabledSubsystem_MODE) {
    // Delay: '<S241>/Delay' incorporates:
    //   SignalConversion generated from: '<S241>/Delay'

    if (localDW->icLoad) {
      localDW->Delay_DSTATE[0] = rtu_y;
      localDW->Delay_DSTATE[1] = rtu_y_p;
      localDW->Delay_DSTATE[2] = rtu_y_o;
    }

    // Delay: '<S241>/Delay'
    localB->Delay[0] = localDW->Delay_DSTATE[0];

    // Delay: '<S241>/Delay1'
    localB->Delay1[0] = localDW->Delay1_DSTATE[0];

    // Delay: '<S241>/Delay'
    localB->Delay[1] = localDW->Delay_DSTATE[1];

    // Delay: '<S241>/Delay1'
    localB->Delay1[1] = localDW->Delay1_DSTATE[1];

    // Delay: '<S241>/Delay'
    localB->Delay[2] = localDW->Delay_DSTATE[2];

    // Delay: '<S241>/Delay1'
    localB->Delay1[2] = localDW->Delay1_DSTATE[2];

    // MATLAB Function: '<S241>/MATLAB Function' incorporates:
    //   Constant: '<S241>/Constant2'
    //   SignalConversion generated from: '<S242>/ SFunction '

    x = exp(-rtu_dt / localP->Constant2_Value);
    localB->ema[0] = (1.0 - (1.0 - x)) * localB->Delay[0] + (1.0 - x) * rtu_y;
    localB->ema[1] = (1.0 - (1.0 - x)) * localB->Delay[1] + (1.0 - x) * rtu_y_p;
    localB->ema[2] = (1.0 - (1.0 - x)) * localB->Delay[2] + (1.0 - x) * rtu_y_o;
    rty_dydt[0] = (localB->ema[0] - localB->Delay[0]) / rtu_dt;
    rty_dydt[1] = (localB->ema[1] - localB->Delay[1]) / rtu_dt;
    rty_dydt[2] = (localB->ema[2] - localB->Delay[2]) / rtu_dt;
  }

  // End of Outputs for SubSystem: '<S235>/Enabled Subsystem'
}

//
// Update for enable system:
//    '<S235>/Enabled Subsystem'
//    '<S245>/Enabled Subsystem'
//    '<S255>/Enabled Subsystem'
//
void MPC_EnabledSubsystem_n_Update(real_T rty_dydt[3],
  B_EnabledSubsystem_MPC_b_T *localB, DW_EnabledSubsystem_MPC_m_T *localDW)
{
  // Update for Enabled SubSystem: '<S235>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S241>/Enable'

  if (localDW->EnabledSubsystem_MODE) {
    // Update for Delay: '<S241>/Delay'
    localDW->icLoad = false;
    localDW->Delay_DSTATE[0] = localB->ema[0];

    // Update for Delay: '<S241>/Delay1'
    localDW->Delay1_DSTATE[0] = rty_dydt[0];

    // Update for Delay: '<S241>/Delay'
    localDW->Delay_DSTATE[1] = localB->ema[1];

    // Update for Delay: '<S241>/Delay1'
    localDW->Delay1_DSTATE[1] = rty_dydt[1];

    // Update for Delay: '<S241>/Delay'
    localDW->Delay_DSTATE[2] = localB->ema[2];

    // Update for Delay: '<S241>/Delay1'
    localDW->Delay1_DSTATE[2] = rty_dydt[2];
  }

  // End of Update for SubSystem: '<S235>/Enabled Subsystem'
}

//
// Output and update for atomic system:
//    '<S266>/MATLAB Function'
//    '<S267>/MATLAB Function'
//
void MPC_MATLABFunction_c1(real_T rtu_dt, const real_T rtu_z[3], const real_T
  rtu_u[3], real_T rty_x[6], real_T rty_P[36])
{
  real_T F[36];
  real_T F_1[36];
  real_T F_2[36];
  real_T F_3[36];
  real_T tmp[36];
  real_T G[18];
  real_T K[18];
  real_T m[9];
  real_T F_0[6];
  real_T G_0[6];
  real_T b[3];
  real_T v[3];
  real_T m_0;
  real_T maxval;
  real_T scale;
  int32_T r1;
  int32_T r2;
  int32_T rtemp;
  int8_T v_tmp[18];
  boolean_T b_b[3];
  boolean_T c_b[3];
  boolean_T y;
  static const int8_T d_b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const int8_T c[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
    0, 1 };

  static const real_T f_b[9] = { 0.0001, 0.0, 0.0, 0.0, 0.0001, 0.0, 0.0, 0.0,
    1.0E-7 };

  static const int8_T b_a[18] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  static const int8_T d[18] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0 };

  static const real_T g_b[9] = { 1.0E-7, 0.0, 0.0, 0.0, 1.0E-7, 0.0, 0.0, 0.0,
    1.0E-7 };

  static const int8_T e[36] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

  boolean_T exitg1;
  for (rtemp = 0; rtemp < 9; rtemp++) {
    m[rtemp] = d_b[rtemp];
  }

  for (rtemp = 0; rtemp < 3; rtemp++) {
    r1 = static_cast<int32_T>(m[3 * rtemp]);
    F[6 * rtemp] = r1;
    r2 = (rtemp + 3) * 6;
    F[r2] = rtu_dt * static_cast<real_T>(r1);
    r1 = static_cast<int32_T>(m[3 * rtemp + 1]);
    F[6 * rtemp + 1] = r1;
    F[r2 + 1] = rtu_dt * static_cast<real_T>(r1);
    r1 = static_cast<int32_T>(m[3 * rtemp + 2]);
    F[6 * rtemp + 2] = r1;
    F[r2 + 2] = rtu_dt * static_cast<real_T>(r1);
  }

  for (rtemp = 0; rtemp < 6; rtemp++) {
    F[6 * rtemp + 3] = c[3 * rtemp];
    F[6 * rtemp + 4] = c[3 * rtemp + 1];
    F[6 * rtemp + 5] = c[3 * rtemp + 2];
  }

  memset(&m[0], 0, 9U * sizeof(real_T));
  m[0] = 1.0 / MPC_P.mBLACK;
  m[4] = 1.0 / MPC_P.mBLACK;
  m[8] = 1.0 / MPC_P.IBLACK;
  scale = rtu_dt * rtu_dt / 2.0;
  for (rtemp = 0; rtemp < 3; rtemp++) {
    m_0 = m[3 * rtemp];
    G[6 * rtemp] = scale * m_0;
    G[6 * rtemp + 3] = rtu_dt * m_0;
    m_0 = m[3 * rtemp + 1];
    G[6 * rtemp + 1] = scale * m_0;
    G[6 * rtemp + 4] = rtu_dt * m_0;
    m_0 = m[3 * rtemp + 2];
    G[6 * rtemp + 2] = scale * m_0;
    G[6 * rtemp + 5] = rtu_dt * m_0;
  }

  for (rtemp = 0; rtemp < 6; rtemp++) {
    scale = 0.0;
    for (r1 = 0; r1 < 6; r1++) {
      scale += F[6 * r1 + rtemp] * rty_x[r1];
    }

    F_0[rtemp] = scale;
    G_0[rtemp] = (G[rtemp + 6] * rtu_u[1] + G[rtemp] * rtu_u[0]) + G[rtemp + 12]
      * rtu_u[2];
  }

  for (rtemp = 0; rtemp < 6; rtemp++) {
    rty_x[rtemp] = F_0[rtemp] + G_0[rtemp];
    for (r1 = 0; r1 < 6; r1++) {
      scale = 0.0;
      for (r2 = 0; r2 < 6; r2++) {
        scale += F[6 * r2 + rtemp] * rty_P[6 * r1 + r2];
      }

      F_1[rtemp + 6 * r1] = scale;
    }

    maxval = G[rtemp + 6];
    scale = G[rtemp];
    m_0 = G[rtemp + 12];
    for (r1 = 0; r1 < 3; r1++) {
      K[rtemp + 6 * r1] = (f_b[3 * r1 + 1] * maxval + f_b[3 * r1] * scale) +
        f_b[3 * r1 + 2] * m_0;
    }

    for (r1 = 0; r1 < 6; r1++) {
      scale = 0.0;
      for (r2 = 0; r2 < 6; r2++) {
        scale += F_1[6 * r2 + rtemp] * F[6 * r2 + r1];
      }

      F_2[rtemp + 6 * r1] = scale;
    }
  }

  for (rtemp = 0; rtemp < 6; rtemp++) {
    maxval = K[rtemp + 6];
    scale = K[rtemp];
    m_0 = K[rtemp + 12];
    for (r1 = 0; r1 < 6; r1++) {
      F[rtemp + 6 * r1] = (G[r1 + 6] * maxval + scale * G[r1]) + G[r1 + 12] *
        m_0;
    }
  }

  for (rtemp = 0; rtemp < 36; rtemp++) {
    rty_P[rtemp] = F_2[rtemp] + F[rtemp];
  }

  b_b[0] = rtIsInf(rtu_z[0]);
  c_b[0] = rtIsNaN(rtu_z[0]);
  b_b[1] = rtIsInf(rtu_z[1]);
  c_b[1] = rtIsNaN(rtu_z[1]);
  b_b[2] = rtIsInf(rtu_z[2]);
  c_b[2] = rtIsNaN(rtu_z[2]);
  y = true;
  rtemp = 0;
  exitg1 = false;
  while ((!exitg1) && (rtemp < 3)) {
    if ((!b_b[rtemp]) && (!c_b[rtemp])) {
      y = false;
      exitg1 = true;
    } else {
      rtemp++;
    }
  }

  if (!y) {
    real_T a21;
    real_T absxk;
    real_T e_in;
    real_T e_in_idx_0;
    real_T e_in_tmp;
    real_T e_in_tmp_tmp;
    real_T t;
    int32_T r3;
    for (rtemp = 0; rtemp < 18; rtemp++) {
      v_tmp[rtemp] = b_a[rtemp];
    }

    for (r1 = 0; r1 < 3; r1++) {
      scale = 0.0;
      for (rtemp = 0; rtemp < 6; rtemp++) {
        scale += static_cast<real_T>(v_tmp[3 * rtemp + r1]) * rty_x[rtemp];
      }

      v[r1] = scale;
      b[r1] = rtu_z[r1] - scale;
    }

    e_in_tmp = sin(v[2]);
    maxval = cos(v[2]);
    a21 = sin(rtu_z[2]);
    e_in_tmp_tmp = cos(rtu_z[2]);
    scale = 3.3121686421112381E-170;
    e_in = (a21 * 0.0 + e_in_tmp_tmp) - (e_in_tmp * 0.0 + maxval);
    e_in_idx_0 = e_in;
    absxk = fabs(e_in);
    if (absxk > 3.3121686421112381E-170) {
      m_0 = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      m_0 = t * t;
    }

    e_in = (e_in_tmp_tmp * 0.0 - a21) - (maxval * 0.0 - e_in_tmp);
    absxk = fabs(e_in);
    if (absxk > scale) {
      t = scale / absxk;
      m_0 = m_0 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      m_0 += t * t;
    }

    e_in_tmp = (cos(rtu_z[2]) * 0.0 + a21) * e_in_idx_0 + (-a21 * 0.0 +
      e_in_tmp_tmp) * e_in;
    if (rtIsNaN(e_in_tmp)) {
      e_in_tmp = (rtNaN);
    } else if (e_in_tmp < 0.0) {
      e_in_tmp = -1.0;
    } else {
      e_in_tmp = (e_in_tmp > 0.0);
    }

    for (rtemp = 0; rtemp < 18; rtemp++) {
      K[rtemp] = d[rtemp];
    }

    for (rtemp = 0; rtemp < 3; rtemp++) {
      for (r1 = 0; r1 < 6; r1++) {
        maxval = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          maxval += static_cast<real_T>(v_tmp[3 * r2 + rtemp]) * rty_P[6 * r1 +
            r2];
        }

        G[rtemp + 3 * r1] = maxval;
      }

      for (r1 = 0; r1 < 3; r1++) {
        maxval = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          maxval += G[3 * r2 + rtemp] * K[6 * r1 + r2];
        }

        r2 = 3 * r1 + rtemp;
        m[r2] = g_b[r2] + maxval;
      }
    }

    for (rtemp = 0; rtemp < 3; rtemp++) {
      for (r1 = 0; r1 < 6; r1++) {
        maxval = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          maxval += rty_P[6 * r2 + r1] * K[6 * rtemp + r2];
        }

        G[r1 + 6 * rtemp] = maxval;
      }
    }

    r1 = 0;
    r2 = 1;
    r3 = 2;
    maxval = fabs(m[0]);
    a21 = fabs(m[1]);
    if (a21 > maxval) {
      maxval = a21;
      r1 = 1;
      r2 = 0;
    }

    if (fabs(m[2]) > maxval) {
      r1 = 2;
      r2 = 1;
      r3 = 0;
    }

    m[r2] /= m[r1];
    m[r3] /= m[r1];
    m[r2 + 3] -= m[r1 + 3] * m[r2];
    m[r3 + 3] -= m[r1 + 3] * m[r3];
    m[r2 + 6] -= m[r1 + 6] * m[r2];
    m[r3 + 6] -= m[r1 + 6] * m[r3];
    if (fabs(m[r3 + 3]) > fabs(m[r2 + 3])) {
      rtemp = r2;
      r2 = r3;
      r3 = rtemp;
    }

    m[r3 + 3] /= m[r2 + 3];
    m[r3 + 6] -= m[r3 + 3] * m[r2 + 6];
    maxval = b[1];
    a21 = b[0];
    scale = scale * sqrt(m_0) * -e_in_tmp;
    for (rtemp = 0; rtemp < 6; rtemp++) {
      int32_T K_tmp;
      int32_T K_tmp_0;
      int32_T K_tmp_1;
      K_tmp = 6 * r1 + rtemp;
      K[K_tmp] = G[rtemp] / m[r1];
      K_tmp_0 = 6 * r2 + rtemp;
      K[K_tmp_0] = G[rtemp + 6] - m[r1 + 3] * K[K_tmp];
      K_tmp_1 = 6 * r3 + rtemp;
      K[K_tmp_1] = G[rtemp + 12] - m[r1 + 6] * K[K_tmp];
      K[K_tmp_0] /= m[r2 + 3];
      K[K_tmp_1] -= m[r2 + 6] * K[K_tmp_0];
      K[K_tmp_1] /= m[r3 + 6];
      K[K_tmp_0] -= m[r3 + 3] * K[K_tmp_1];
      K[K_tmp] -= K[K_tmp_1] * m[r3];
      K[K_tmp] -= K[K_tmp_0] * m[r2];
      rty_x[rtemp] += (K[rtemp + 6] * maxval + K[rtemp] * a21) + K[rtemp + 12] *
        scale;
    }

    for (rtemp = 0; rtemp < 36; rtemp++) {
      F[rtemp] = e[rtemp];
    }

    for (rtemp = 0; rtemp < 6; rtemp++) {
      int8_T v_tmp_0;
      int8_T v_tmp_1;
      int8_T v_tmp_2;
      v_tmp_0 = v_tmp[3 * rtemp + 1];
      v_tmp_1 = v_tmp[3 * rtemp];
      v_tmp_2 = v_tmp[3 * rtemp + 2];
      for (r1 = 0; r1 < 6; r1++) {
        tmp[r1 + 6 * rtemp] = (K[r1 + 6] * static_cast<real_T>(v_tmp_0) +
          static_cast<real_T>(v_tmp_1) * K[r1]) + K[r1 + 12] *
          static_cast<real_T>(v_tmp_2);
      }
    }

    for (rtemp = 0; rtemp < 36; rtemp++) {
      F_1[rtemp] = F[rtemp] - tmp[rtemp];
    }

    for (rtemp = 0; rtemp < 6; rtemp++) {
      for (r1 = 0; r1 < 6; r1++) {
        scale = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          scale += F_1[6 * r2 + rtemp] * rty_P[6 * r1 + r2];
        }

        r2 = 6 * r1 + rtemp;
        F_2[r2] = scale;
        F_3[r1 + 6 * rtemp] = F[r2] - tmp[r2];
      }

      scale = K[rtemp + 6];
      m_0 = K[rtemp];
      e_in_tmp = K[rtemp + 12];
      for (r1 = 0; r1 < 3; r1++) {
        G[rtemp + 6 * r1] = (g_b[3 * r1 + 1] * scale + g_b[3 * r1] * m_0) + g_b
          [3 * r1 + 2] * e_in_tmp;
      }
    }

    for (rtemp = 0; rtemp < 6; rtemp++) {
      for (r1 = 0; r1 < 6; r1++) {
        scale = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          scale += F_2[6 * r2 + rtemp] * F_3[6 * r1 + r2];
        }

        r2 = 6 * r1 + rtemp;
        F[r2] = scale;
        F_1[r2] = (G[rtemp + 6] * K[r1 + 6] + G[rtemp] * K[r1]) + G[rtemp + 12] *
          K[r1 + 12];
      }
    }

    for (rtemp = 0; rtemp < 36; rtemp++) {
      rty_P[rtemp] = F[rtemp] + F_1[rtemp];
    }
  }
}

//
// Output and update for atomic system:
//    '<S270>/MATLAB Function1'
//    '<S273>/MATLAB Function1'
//    '<S276>/MATLAB Function1'
//
void MPC_MATLABFunction1(const real_T rtu_u[9], const real_T rtu_uprev[9],
  real_T rty_y[3])
{
  real_T y[9];
  real_T b_y;
  for (int32_T k = 0; k < 9; k++) {
    y[k] = fabs(rtu_u[k] - rtu_uprev[k]);
  }

  b_y = y[0];
  for (int32_T k = 0; k < 8; k++) {
    b_y += y[k + 1];
  }

  if (b_y < 1.0E-10) {
    rty_y[0] = (rtNaN);
    rty_y[1] = (rtNaN);
    rty_y[2] = (rtNaN);
  } else {
    rty_y[0] = rtu_u[0];
    rty_y[1] = rtu_u[1];
    rty_y[2] = rtu_u[2];
  }
}

//
// Output and update for atomic system:
//    '<S279>/MATLAB Function1'
//    '<S279>/MATLAB Function2'
//
void MPC_MATLABFunction1_e(real_T rtu_z, real_T rtu_zk, real_T *rty_x)
{
  if (fabs(rtu_z - rtu_zk) < 1.0E-10) {
    *rty_x = (rtNaN);
  } else {
    *rty_x = rtu_z;
  }
}

static real_T MPC_xzlangeM(const real_T x[24])
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

static void MPC_xzlascl(real_T cfrom, real_T cto, real_T A[24])
{
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;

  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
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

  // End of Start for MATLABSystem: '<S295>/Pseudoinverse1'
}

static real_T MPC_xnrm2(int32_T n, const real_T x[24], int32_T ix0)
{
  real_T scale;
  real_T y;
  int32_T kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;

  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
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

  // End of Start for MATLABSystem: '<S295>/Pseudoinverse1'
  return scale * sqrt(y);
}

static real_T MPC_xdotc(int32_T n, const real_T x[24], int32_T ix0, const real_T
  y[24], int32_T iy0)
{
  real_T d;
  int32_T b;
  d = 0.0;

  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
  b = static_cast<uint8_T>(n);
  for (int32_T k = 0; k < b; k++) {
    // Start for MATLABSystem: '<S295>/Pseudoinverse1'
    d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
  }

  return d;
}

static void MPC_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[24], int32_T
                      iy0)
{
  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
  if (!(a == 0.0)) {
    for (int32_T k = 0; k < n; k++) {
      int32_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += y[(ix0 + k) - 1] * a;
    }
  }

  // End of Start for MATLABSystem: '<S295>/Pseudoinverse1'
}

static real_T MPC_xdotc_o(const real_T x[9], const real_T y[9], int32_T iy0)
{
  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
  return y[iy0 - 1] * x[1] + x[2] * y[iy0];
}

static void MPC_xaxpy_gop(real_T a, real_T y[9], int32_T iy0)
{
  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
  if (!(a == 0.0)) {
    y[iy0 - 1] += a * y[1];
    y[iy0] += a * y[2];
  }

  // End of Start for MATLABSystem: '<S295>/Pseudoinverse1'
}

static real_T MPC_xnrm2_p(const real_T x[3], int32_T ix0)
{
  real_T scale;
  real_T y;
  y = 0.0;
  scale = 3.3121686421112381E-170;

  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
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

  // End of Start for MATLABSystem: '<S295>/Pseudoinverse1'
  return scale * sqrt(y);
}

static void MPC_xaxpy_g(int32_T n, real_T a, const real_T x[24], int32_T ix0,
  real_T y[8], int32_T iy0)
{
  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
  if (!(a == 0.0)) {
    for (int32_T k = 0; k < n; k++) {
      int32_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += x[(ix0 + k) - 1] * a;
    }
  }

  // End of Start for MATLABSystem: '<S295>/Pseudoinverse1'
}

static void MPC_xaxpy_go(int32_T n, real_T a, const real_T x[8], int32_T ix0,
  real_T y[24], int32_T iy0)
{
  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
  if (!(a == 0.0)) {
    for (int32_T k = 0; k < n; k++) {
      int32_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += x[(ix0 + k) - 1] * a;
    }
  }

  // End of Start for MATLABSystem: '<S295>/Pseudoinverse1'
}

static void MPC_xzlascl_i(real_T cfrom, real_T cto, real_T A[3])
{
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;

  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
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

  // End of Start for MATLABSystem: '<S295>/Pseudoinverse1'
}

static void MPC_xrotg(real_T a, real_T b, real_T *b_a, real_T *b_b, real_T *c,
                      real_T *s)
{
  real_T absa;
  real_T absb;
  real_T roe;
  real_T scale;

  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
  roe = b;
  absa = fabs(a);
  absb = fabs(b);
  if (absa > absb) {
    // Start for MATLABSystem: '<S295>/Pseudoinverse1'
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

    // Start for MATLABSystem: '<S295>/Pseudoinverse1'
    *b_a = sqrt(ads * ads + bds * bds) * scale;
    if (roe < 0.0) {
      *b_a = -*b_a;
    }

    // Start for MATLABSystem: '<S295>/Pseudoinverse1'
    *c = a / *b_a;
    *s = b / *b_a;
    if (absa > absb) {
      *b_b = *s;
    } else if (*c != 0.0) {
      // Start for MATLABSystem: '<S295>/Pseudoinverse1'
      *b_b = 1.0 / *c;
    } else {
      *b_b = 1.0;
    }
  }
}

static void MPC_xrot_ps(real_T x[9], int32_T ix0, int32_T iy0, real_T c, real_T
  s)
{
  real_T temp;
  real_T temp_tmp;

  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
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

static void MPC_xrot_psj(real_T x[24], int32_T ix0, int32_T iy0, real_T c,
  real_T s)
{
  for (int32_T k = 0; k < 8; k++) {
    real_T temp_tmp;
    real_T temp_tmp_0;
    int32_T temp_tmp_tmp;
    int32_T temp_tmp_tmp_0;

    // Start for MATLABSystem: '<S295>/Pseudoinverse1'
    temp_tmp_tmp = (iy0 + k) - 1;
    temp_tmp = x[temp_tmp_tmp];

    // Start for MATLABSystem: '<S295>/Pseudoinverse1'
    temp_tmp_tmp_0 = (ix0 + k) - 1;
    temp_tmp_0 = x[temp_tmp_tmp_0];

    // Start for MATLABSystem: '<S295>/Pseudoinverse1'
    x[temp_tmp_tmp] = temp_tmp * c - temp_tmp_0 * s;
    x[temp_tmp_tmp_0] = temp_tmp_0 * c + temp_tmp * s;
  }
}

static void MPC_xswap_dj(real_T x[9], int32_T ix0, int32_T iy0)
{
  real_T temp;

  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
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

static void MPC_xswap_dj5(real_T x[24], int32_T ix0, int32_T iy0)
{
  for (int32_T k = 0; k < 8; k++) {
    real_T temp;
    int32_T temp_tmp;
    int32_T tmp;

    // Start for MATLABSystem: '<S295>/Pseudoinverse1'
    temp_tmp = (ix0 + k) - 1;
    temp = x[temp_tmp];

    // Start for MATLABSystem: '<S295>/Pseudoinverse1'
    tmp = (iy0 + k) - 1;
    x[temp_tmp] = x[tmp];
    x[tmp] = temp;
  }
}

static void MPC_svd(const real_T A[24], real_T U[24], real_T s[3], real_T V[9])
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

  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
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

  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
  anrm = MPC_xzlangeM(A);
  cscale = anrm;

  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
  if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
    doscale = true;
    cscale = 6.7178761075670888E-139;
    MPC_xzlascl(anrm, cscale, A_0);
  } else if (anrm > 1.4885657073574029E+138) {
    doscale = true;
    cscale = 1.4885657073574029E+138;
    MPC_xzlascl(anrm, cscale, A_0);
  }

  for (i = 0; i < 3; i++) {
    // Start for MATLABSystem: '<S295>/Pseudoinverse1'
    qp1 = i + 2;
    qq_tmp_tmp = i << 3;

    // Start for MATLABSystem: '<S295>/Pseudoinverse1'
    colqp1 = qq_tmp_tmp + i;
    qq = colqp1 + 1;
    apply_transform = false;

    // Start for MATLABSystem: '<S295>/Pseudoinverse1'
    nrm = MPC_xnrm2(8 - i, A_0, colqp1 + 1);
    if (nrm > 0.0) {
      apply_transform = true;

      // Start for MATLABSystem: '<S295>/Pseudoinverse1'
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
      // Start for MATLABSystem: '<S295>/Pseudoinverse1'
      qjj = (((qq - 1) << 3) + i) + 1;
      if (apply_transform) {
        // Start for MATLABSystem: '<S295>/Pseudoinverse1'
        MPC_xaxpy(8 - i, -(MPC_xdotc(8 - i, A_0, colqp1 + 1, A_0, qjj) /
                           A_0[colqp1]), colqp1 + 1, A_0, qjj);
      }

      e[qq - 1] = A_0[qjj - 1];
    }

    // Start for MATLABSystem: '<S295>/Pseudoinverse1'
    for (colqp1 = i + 1; colqp1 < 9; colqp1++) {
      qjj = (qq_tmp_tmp + colqp1) - 1;
      U[qjj] = A_0[qjj];
    }

    if (i + 1 <= 1) {
      nrm = MPC_xnrm2_p(e, i + 2);
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
          MPC_xaxpy_g(7 - i, e[colqp1 - 1], A_0, (i + ((colqp1 - 1) << 3)) + 2,
                      work, i + 2);
        }

        for (colqp1 = qp1; colqp1 < 4; colqp1++) {
          MPC_xaxpy_go(7 - i, -e[colqp1 - 1] / e[i + 1], work, i + 2, A_0, (i +
            ((colqp1 - 1) << 3)) + 2);
        }
      }

      for (colqp1 = qp1; colqp1 < 4; colqp1++) {
        Vf[colqp1 - 1] = e[colqp1 - 1];
      }
    }
  }

  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
  i = 2;
  e[1] = A_0[17];
  e[2] = 0.0;

  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
  for (qp1 = 2; qp1 >= 0; qp1--) {
    colqp1 = qp1 << 3;
    qq = colqp1 + qp1;
    if (s_0[qp1] != 0.0) {
      for (qq_tmp_tmp = qp1 + 2; qq_tmp_tmp < 4; qq_tmp_tmp++) {
        qjj = (((qq_tmp_tmp - 1) << 3) + qp1) + 1;
        MPC_xaxpy(8 - qp1, -(MPC_xdotc(8 - qp1, U, qq + 1, U, qjj) / U[qq]), qq
                  + 1, U, qjj);
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
      MPC_xaxpy_gop(-(MPC_xdotc_o(Vf, Vf, 5) / Vf[1]), Vf, 5);
      MPC_xaxpy_gop(-(MPC_xdotc_o(Vf, Vf, 8) / Vf[1]), Vf, 8);
    }

    Vf[3 * qp1] = 0.0;
    Vf[3 * qp1 + 1] = 0.0;
    Vf[3 * qp1 + 2] = 0.0;
    Vf[qp1 + 3 * qp1] = 1.0;
  }

  for (qp1 = 0; qp1 < 3; qp1++) {
    r = s_0[qp1];
    if (r != 0.0) {
      // Start for MATLABSystem: '<S295>/Pseudoinverse1'
      nrm = fabs(r);
      r /= nrm;
      s_0[qp1] = nrm;

      // Start for MATLABSystem: '<S295>/Pseudoinverse1'
      if (qp1 + 1 < 3) {
        e[qp1] /= r;
      }

      qq = qp1 << 3;

      // Start for MATLABSystem: '<S295>/Pseudoinverse1'
      for (qjj = qq + 1; qjj <= qq + 8; qjj++) {
        U[qjj - 1] *= r;
      }
    }

    // Start for MATLABSystem: '<S295>/Pseudoinverse1'
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

  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
  ztest = fabs(s_0[0]);
  nrm = fabs(e[0]);
  if ((ztest >= nrm) || rtIsNaN(nrm)) {
    nrm = ztest;
  }

  if ((!(nrm <= 0.0)) && (!rtIsNaN(nrm))) {
    r = nrm;
  }

  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
  ztest = fabs(s_0[1]);
  nrm = fabs(e[1]);
  if ((ztest >= nrm) || rtIsNaN(nrm)) {
    nrm = ztest;
  }

  if ((!(r >= nrm)) && (!rtIsNaN(nrm))) {
    r = nrm;
  }

  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
  ztest = fabs(s_0[2]);
  nrm = fabs(e[2]);
  if ((ztest >= nrm) || rtIsNaN(nrm)) {
    nrm = ztest;
  }

  if ((!(r >= nrm)) && (!rtIsNaN(nrm))) {
    r = nrm;
  }

  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
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
        MPC_xrotg(s_0[qq - 1], nrm, &s_0[qq - 1], &nrm, &ztest, &sqds);
        if (qq > colqp1 + 1) {
          nrm = -sqds * e[0];
          e[0] *= ztest;
        }

        MPC_xrot_ps(Vf, 3 * (qq - 1) + 1, 3 * i + 1, ztest, sqds);
      }
      break;

     case 2:
      nrm = e[colqp1 - 1];
      e[colqp1 - 1] = 0.0;
      for (qq = colqp1 + 1; qq <= i + 1; qq++) {
        MPC_xrotg(s_0[qq - 1], nrm, &s_0[qq - 1], &ztest, &sqds, &b);
        ztest = e[qq - 1];
        nrm = -b * ztest;
        e[qq - 1] = ztest * sqds;
        MPC_xrot_psj(U, ((qq - 1) << 3) + 1, ((colqp1 - 1) << 3) + 1, sqds, b);
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
        MPC_xrotg(nrm, ztest, &smm1, &emm1, &sqds, &b);
        if (qq > colqp1 + 1) {
          e[0] = smm1;
        }

        smm1 = e[qq - 1];
        nrm = s_0[qq - 1];
        e[qq - 1] = smm1 * sqds - nrm * b;
        ztest = b * s_0[qq];
        s_0[qq] *= sqds;
        MPC_xrot_ps(Vf, 3 * (qq - 1) + 1, 3 * qq + 1, sqds, b);
        MPC_xrotg(nrm * sqds + smm1 * b, ztest, &s_0[qq - 1], &a__3, &emm1,
                  &d_sn);
        smm1 = e[qq - 1];
        nrm = smm1 * emm1 + d_sn * s_0[qq];
        s_0[qq] = smm1 * -d_sn + emm1 * s_0[qq];
        ztest = d_sn * e[qq];
        e[qq] *= emm1;
        MPC_xrot_psj(U, ((qq - 1) << 3) + 1, (qq << 3) + 1, emm1, d_sn);
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
        MPC_xswap_dj(Vf, 3 * colqp1 + 1, 3 * (colqp1 + 1) + 1);
        MPC_xswap_dj5(U, (colqp1 << 3) + 1, ((colqp1 + 1) << 3) + 1);
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
    // Start for MATLABSystem: '<S295>/Pseudoinverse1'
    MPC_xzlascl_i(cscale, anrm, s);
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
void MPC_Pseudoinverse1_Init(DW_Pseudoinverse1_MPC_T *localDW)
{
  // Start for MATLABSystem: '<S295>/Pseudoinverse1'
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
}

// Output and update for atomic system:
void MPC_Pseudoinverse1(const real_T rtu_0[24], B_Pseudoinverse1_MPC_T *localB)
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

  // MATLABSystem: '<S295>/Pseudoinverse1'
  for (i = 0; i < 24; i++) {
    // Start for MATLABSystem: '<S295>/Pseudoinverse1'
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
      MPC_svd(A, U, s, V);
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

  // End of MATLABSystem: '<S295>/Pseudoinverse1'
}

//
// Output and update for atomic system:
//    '<S298>/Create Rotation Matrix'
//    '<S310>/Create Rotation Matrix'
//    '<S322>/Create Rotation Matrix'
//
void MPC_CreateRotationMatrix(real_T rtu_Rz, real_T rty_C_Ib[4])
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
//    '<S293>/Create Rotation Matrix'
//    '<S305>/Create Rotation Matrix'
//    '<S317>/Create Rotation Matrix'
//
void MPC_CreateRotationMatrix_k(real_T rtu_Rz, real_T rty_C_bI[4])
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

// Function for MATLAB Function: '<S304>/MATLAB Function1'
static real_T MPC_maximum(const real_T x[8])
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
//    '<S304>/MATLAB Function1'
//    '<S316>/MATLAB Function8'
//
void MPC_MATLABFunction1_i(const real_T rtu_ThrustPer[8], real_T
  rty_ThrustPer_Final[8])
{
  real_T TControl;
  real_T ThrustPer_Sat;
  real_T maxval;
  int32_T i;
  TControl = 1.0 / MPC_P.PWMFreq;
  maxval = MPC_maximum(rtu_ThrustPer);
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

// Function for MATLAB Function: '<S283>/MATLAB Function'
void MPC_rotm2Quat(const real_T C[9], real_T q[4])
{
  real_T trace_R;
  trace_R = (C[0] + C[4]) + C[8];
  if (trace_R > 0.0) {
    trace_R = sqrt(trace_R + 1.0) * 2.0;
    q[0] = 0.25 * trace_R;
    q[1] = (C[5] - C[7]) / trace_R;
    q[2] = (C[6] - C[2]) / trace_R;
    q[3] = (C[1] - C[3]) / trace_R;
  } else if ((C[0] > C[4]) && (C[0] > C[8])) {
    trace_R = sqrt(((C[0] + 1.0) - C[4]) - C[8]) * 2.0;
    q[0] = (C[5] - C[7]) / trace_R;
    q[1] = 0.25 * trace_R;
    q[2] = (C[1] + C[3]) / trace_R;
    q[3] = (C[2] + C[6]) / trace_R;
  } else if (C[4] > C[8]) {
    trace_R = sqrt(((C[4] + 1.0) - C[0]) - C[8]) * 2.0;
    q[0] = (C[6] - C[2]) / trace_R;
    q[1] = (C[1] + C[3]) / trace_R;
    q[2] = 0.25 * trace_R;
    q[3] = (C[5] + C[7]) / trace_R;
  } else {
    trace_R = sqrt(((C[8] + 1.0) - C[0]) - C[4]) * 2.0;
    q[0] = (C[1] - C[3]) / trace_R;
    q[1] = (C[2] + C[6]) / trace_R;
    q[2] = (C[5] + C[7]) / trace_R;
    q[3] = 0.25 * trace_R;
  }
}

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static void MPC_timeKeeper(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime)
{
  coderTimespec origTimespec;
  if (!MPC_DW.savedTime_not_empty_n) {
    if (!MPC_DW.freq_not_empty_g) {
      MPC_DW.freq_not_empty_g = true;
      coderInitTimeFunctions(&MPC_DW.freq_m);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, MPC_DW.freq_m);
    MPC_DW.savedTime_not_empty_n = true;
  }

  savedTime->tv_sec = newTime_tv_sec;
  savedTime->tv_nsec = newTime_tv_nsec;
}

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static void MPC_tic(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime)
{
  coderTimespec origTimespec;
  if (!MPC_DW.freq_not_empty_g) {
    MPC_DW.freq_not_empty_g = true;
    coderInitTimeFunctions(&MPC_DW.freq_m);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, MPC_DW.freq_m);
  MPC_timeKeeper(origTimespec.tv_sec, origTimespec.tv_nsec, savedTime);
}

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static real_T MPC_norm(const real_T x[3])
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

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static real_T MPC_norm_j(const real_T x[81])
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

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static void MPC_mpower(const real_T a[81], real_T b, real_T c[81])
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

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static real_T MPC_log2(real_T x)
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

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static void MPC_padeApproximation(const real_T A[81], const real_T A2[81], const
  real_T A4[81], const real_T A6[81], int32_T m, real_T F[81])
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

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static void MPC_recomputeBlockDiag(const real_T A[81], real_T F[81], const
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

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static real_T MPC_xnrm2_o(int32_T n, const real_T x[81], int32_T ix0)
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

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static void MPC_xzsyhetrd(real_T A[81], real_T D[9], real_T E[8], real_T tau[8])
{
  real_T tau_tmp;
  real_T taui;
  real_T temp2;
  real_T xnorm;
  int32_T alpha_tmp_tmp_tmp;
  int32_T b_jj;
  int32_T c_k;
  int32_T i;
  int32_T ii;
  int32_T ix0;
  int32_T j;
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
    xnorm = MPC_xnrm2_o(7 - i, A, ix0);
    if (xnorm != 0.0) {
      xnorm = rt_hypotd_snf(temp2, xnorm);
      if (temp2 >= 0.0) {
        xnorm = -xnorm;
      }

      if (fabs(xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        j = (ix0 - i) + 6;
        do {
          knt++;
          for (c_k = ix0; c_k <= j; c_k++) {
            A[c_k - 1] *= 9.9792015476736E+291;
          }

          xnorm *= 9.9792015476736E+291;
          temp2 *= 9.9792015476736E+291;
        } while ((fabs(xnorm) < 1.0020841800044864E-292) && (knt < 20));

        xnorm = rt_hypotd_snf(temp2, MPC_xnrm2_o(7 - i, A, ix0));
        if (temp2 >= 0.0) {
          xnorm = -xnorm;
        }

        taui = (xnorm - temp2) / xnorm;
        temp2 = 1.0 / (temp2 - xnorm);
        for (c_k = ix0; c_k <= j; c_k++) {
          A[c_k - 1] *= temp2;
        }

        for (ix0 = 0; ix0 < knt; ix0++) {
          xnorm *= 1.0020841800044864E-292;
        }

        temp2 = xnorm;
      } else {
        taui = (xnorm - temp2) / xnorm;
        temp2 = 1.0 / (temp2 - xnorm);
        j = (ix0 - i) + 6;
        for (knt = ix0; knt <= j; knt++) {
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
        j = i + b_jj;
        xnorm = A[(9 * i + j) + 1] * taui;
        temp2 = 0.0;
        c_k = (j + 1) * 9 + i;
        tau[j] += A[(c_k + b_jj) + 1] * xnorm;
        for (ii = b_jj + 2; ii < knt; ii++) {
          tau_tmp_tmp = i + ii;
          tau_tmp = A[c_k + ii];
          tau[tau_tmp_tmp - 1] += tau_tmp * xnorm;
          temp2 += A[9 * i + tau_tmp_tmp] * tau_tmp;
        }

        tau[j] += taui * temp2;
      }

      xnorm = 0.0;
      j = 8 - i;
      for (c_k = 0; c_k < j; c_k++) {
        xnorm += A[(alpha_tmp_tmp_tmp + c_k) + 1] * tau[i + c_k];
      }

      xnorm *= -0.5 * taui;
      if (!(xnorm == 0.0)) {
        for (b_jj = 0; b_jj < j; b_jj++) {
          c_k = i + b_jj;
          tau[c_k] += A[(alpha_tmp_tmp_tmp + b_jj) + 1] * xnorm;
        }
      }

      for (c_k = 0; c_k <= ix0; c_k++) {
        j = i + c_k;
        xnorm = A[(9 * i + j) + 1];
        temp2 = tau[j];
        tau_tmp = temp2 * xnorm;
        b_jj = (j + 1) * 9;
        ii = b_jj + i;
        A[(j + b_jj) + 1] = (A[(ii + c_k) + 1] - tau_tmp) - tau_tmp;
        for (j = c_k + 2; j < knt; j++) {
          tau_tmp_tmp = i + j;
          A[tau_tmp_tmp + b_jj] = (A[ii + j] - tau[tau_tmp_tmp - 1] * xnorm) -
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

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static void MPC_xzlascl_m(real_T cfrom, real_T cto, int32_T m, real_T A[9],
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

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static void MPC_xzlascl_ml(real_T cfrom, real_T cto, int32_T m, real_T A[8],
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

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static void MPC_xzlartg(real_T f, real_T g, real_T *cs, real_T *sn, real_T *r)
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

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static void MPC_rotateRight_b(int32_T n, real_T z[81], int32_T iz0, const real_T
  cs[16], int32_T ic0, int32_T is0)
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

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static void MPC_xdlaev2(real_T a, real_T b, real_T c, real_T *rt1, real_T *rt2,
  real_T *cs1, real_T *sn1)
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

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static void MPC_rotateRight(int32_T n, real_T z[81], int32_T iz0, const real_T
  cs[16], int32_T ic0, int32_T is0)
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

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static int32_T MPC_xzsteqr(real_T d[9], real_T e[8], real_T z[81])
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
            MPC_xzlascl_m(tst, 2.2346346549904327E+153, n_tmp, d, l + 1);
            MPC_xzlascl_ml(tst, 2.2346346549904327E+153, n_tmp - 1, e, l + 1);
          } else if (tst < 3.02546243347603E-123) {
            iscale = 2;
            MPC_xzlascl_m(tst, 3.02546243347603E-123, n_tmp, d, l + 1);
            MPC_xzlascl_ml(tst, 3.02546243347603E-123, n_tmp - 1, e, l + 1);
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
                MPC_xdlaev2(d[l], e[l], d[l + 1], &d[l], &b_anorm, &work[l], &p);
                d[l + 1] = b_anorm;
                work[l + 8] = p;
                MPC_rotateRight(2, z, l * 9 + 1, work, l + 1, l + 9);
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
                  MPC_xzlartg(b_anorm, s * r, &c, &b_s, &b_r);
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

                MPC_rotateRight((m - l) + 1, z, l * 9 + 1, work, l + 1, l + 9);
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
                MPC_xdlaev2(d[l - 1], e[l - 1], d[l], &d[l - 1], &b_anorm,
                            &work[m - 1], &p);
                d[l] = b_anorm;
                work[m + 7] = p;
                MPC_rotateRight_b(2, z, (l - 1) * 9 + 1, work, m, m + 8);
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
                  MPC_xzlartg(b_anorm, s * r, &c, &b_s, &b_r);
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

                MPC_rotateRight_b((l - m) + 2, z, (m - 1) * 9 + 1, work, m, m +
                                  8);
                d[l] -= p;
                e[l - 1] = b_anorm;
              }
            } while (exitg3 == 0);
          }

          switch (iscale) {
           case 1:
            m = lendsv - lsv;
            MPC_xzlascl_m(2.2346346549904327E+153, tst, m + 1, d, lsv);
            MPC_xzlascl_ml(2.2346346549904327E+153, tst, m, e, lsv);
            break;

           case 2:
            m = lendsv - lsv;
            MPC_xzlascl_m(3.02546243347603E-123, tst, m + 1, d, lsv);
            MPC_xzlascl_ml(3.02546243347603E-123, tst, m, e, lsv);
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

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static void MPC_xsyheev(real_T A[81], int32_T *info, real_T W[9])
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

    MPC_xzsyhetrd(A, W, e, tau);
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

    *info = MPC_xzsteqr(W, e, A);
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

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static void MPC_expm(real_T A[81], real_T F[81])
{
  real_T A2[81];
  real_T A4[81];
  real_T A4_0[81];
  real_T A6[81];
  real_T T[81];
  real_T tmp[81];
  real_T w[9];
  real_T A4_1;
  real_T d6;
  real_T d_y;
  real_T eta1;
  real_T exptj;
  int32_T blockFormat[8];
  int32_T b_k;
  int32_T b_s;
  int32_T e_i;
  int32_T e_j;
  int32_T exitg1;
  int32_T k;
  boolean_T exitg2;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T guard3;
  boolean_T guard4;
  boolean_T recomputeDiags;
  recomputeDiags = true;
  for (e_j = 0; e_j < 81; e_j++) {
    if (recomputeDiags) {
      exptj = A[e_j];
      if (rtIsInf(exptj) || rtIsNaN(exptj)) {
        recomputeDiags = false;
      }
    }
  }

  if (!recomputeDiags) {
    for (e_j = 0; e_j < 81; e_j++) {
      F[e_j] = (rtNaN);
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
      memset(&F[0], 0, 81U * sizeof(real_T));
      for (e_j = 0; e_j < 9; e_j++) {
        b_s = 9 * e_j + e_j;
        F[b_s] = exp(A[b_s]);
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
        memcpy(&A2[0], &A[0], 81U * sizeof(real_T));
        MPC_xsyheev(A2, &b_s, w);
        for (e_j = 0; e_j < 9; e_j++) {
          exptj = exp(w[e_j]);
          for (e_i = 0; e_i < 9; e_i++) {
            b_s = 9 * e_j + e_i;
            F[b_s] = A2[b_s] * exptj;
          }
        }

        for (e_j = 0; e_j < 9; e_j++) {
          for (e_i = 0; e_i < 9; e_i++) {
            exptj = 0.0;
            for (b_k = 0; b_k < 9; b_k++) {
              exptj += F[9 * b_k + e_j] * A2[9 * b_k + e_i];
            }

            A4[e_j + 9 * e_i] = exptj;
          }
        }

        memcpy(&F[0], &A4[0], 81U * sizeof(real_T));
        for (e_j = 0; e_j < 9; e_j++) {
          for (e_i = 0; e_i < 9; e_i++) {
            b_s = 9 * e_j + e_i;
            A4[b_s] = (F[9 * e_i + e_j] + F[b_s]) / 2.0;
          }
        }

        memcpy(&F[0], &A4[0], 81U * sizeof(real_T));
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
          b_k = 1;
          exitg2 = false;
          while ((!exitg2) && (b_k - 1 < 8)) {
            e_j = (b_k - 1) * 9 + b_k;
            d6 = A[e_j];
            if (d6 != 0.0) {
              if ((b_k != 8) && (A[(9 * b_k + b_k) + 1] != 0.0)) {
                recomputeDiags = false;
                exitg2 = true;
              } else {
                e_i = 9 * b_k + b_k;
                if (A[e_j - 1] != A[e_i]) {
                  recomputeDiags = false;
                  exitg2 = true;
                } else {
                  exptj = A[e_i - 1];
                  if (rtIsNaN(d6)) {
                    d6 = (rtNaN);
                  } else if (d6 < 0.0) {
                    d6 = -1.0;
                  } else {
                    d6 = (d6 > 0.0);
                  }

                  if (rtIsNaN(exptj)) {
                    exptj = (rtNaN);
                  } else if (exptj < 0.0) {
                    exptj = -1.0;
                  } else {
                    exptj = (exptj > 0.0);
                  }

                  if (d6 * exptj != -1.0) {
                    recomputeDiags = false;
                    exitg2 = true;
                  } else {
                    b_k++;
                  }
                }
              }
            } else {
              b_k++;
            }
          }
        }

        exptj = 0.0;
        for (e_j = 0; e_j < 9; e_j++) {
          for (e_i = 0; e_i < 9; e_i++) {
            d6 = 0.0;
            for (b_k = 0; b_k < 9; b_k++) {
              d6 += A[9 * b_k + e_i] * A[9 * e_j + b_k];
            }

            A2[e_i + 9 * e_j] = d6;
          }
        }

        for (e_j = 0; e_j < 9; e_j++) {
          for (e_i = 0; e_i < 9; e_i++) {
            A4_1 = 0.0;
            for (b_k = 0; b_k < 9; b_k++) {
              A4_1 += A2[9 * b_k + e_j] * A2[9 * e_i + b_k];
            }

            A4[e_j + 9 * e_i] = A4_1;
          }

          for (e_i = 0; e_i < 9; e_i++) {
            d6 = 0.0;
            for (b_k = 0; b_k < 9; b_k++) {
              d6 += A4[9 * b_k + e_j] * A2[9 * e_i + b_k];
            }

            A6[e_j + 9 * e_i] = d6;
          }
        }

        d6 = rt_powd_snf(MPC_norm_j(A6), 0.16666666666666666);
        eta1 = rt_powd_snf(MPC_norm_j(A4), 0.25);
        if ((!(eta1 >= d6)) && (!rtIsNaN(d6))) {
          eta1 = d6;
        }

        guard1 = false;
        guard2 = false;
        guard3 = false;
        guard4 = false;
        if (eta1 <= 0.01495585217958292) {
          for (e_j = 0; e_j < 81; e_j++) {
            A4_0[e_j] = 0.19285012468241128 * fabs(A[e_j]);
          }

          MPC_mpower(A4_0, 7.0, tmp);
          A4_1 = ceil(MPC_log2(MPC_norm_j(tmp) / MPC_norm_j(A) * 2.0 /
                               2.2204460492503131E-16) / 6.0);
          if (!(A4_1 >= 0.0)) {
            A4_1 = 0.0;
          }

          if (A4_1 == 0.0) {
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
              A4_0[e_j] = 0.12321872304378752 * fabs(A[e_j]);
            }

            MPC_mpower(A4_0, 11.0, tmp);
            A4_1 = ceil(MPC_log2(MPC_norm_j(tmp) / MPC_norm_j(A) * 2.0 /
                                 2.2204460492503131E-16) / 10.0);
            if (!(A4_1 >= 0.0)) {
              A4_1 = 0.0;
            }

            if (A4_1 == 0.0) {
              b_s = 5;
            } else {
              guard3 = true;
            }
          } else {
            guard3 = true;
          }
        }

        if (guard3) {
          MPC_mpower(A4, 2.0, tmp);
          eta1 = rt_powd_snf(MPC_norm_j(tmp), 0.125);
          if ((!(d6 >= eta1)) && (!rtIsNaN(eta1))) {
            d6 = eta1;
          }

          if (d6 <= 0.95041789961629319) {
            for (e_j = 0; e_j < 81; e_j++) {
              A4_0[e_j] = 0.090475336558796943 * fabs(A[e_j]);
            }

            MPC_mpower(A4_0, 15.0, tmp);
            A4_1 = ceil(MPC_log2(MPC_norm_j(tmp) / MPC_norm_j(A) * 2.0 /
                                 2.2204460492503131E-16) / 14.0);
            if (!(A4_1 >= 0.0)) {
              A4_1 = 0.0;
            }

            if (A4_1 == 0.0) {
              b_s = 7;
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }
        }

        if (guard2) {
          if (d6 <= 2.097847961257068) {
            for (e_j = 0; e_j < 81; e_j++) {
              A4_0[e_j] = 0.071467735648795785 * fabs(A[e_j]);
            }

            MPC_mpower(A4_0, 19.0, tmp);
            A4_1 = ceil(MPC_log2(MPC_norm_j(tmp) / MPC_norm_j(A) * 2.0 /
                                 2.2204460492503131E-16) / 18.0);
            if (!(A4_1 >= 0.0)) {
              A4_1 = 0.0;
            }

            if (A4_1 == 0.0) {
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
              A4_1 = 0.0;
              for (b_k = 0; b_k < 9; b_k++) {
                A4_1 += A4[9 * b_k + e_i] * A6[9 * e_j + b_k];
              }

              A4_0[e_i + 9 * e_j] = A4_1;
            }
          }

          A4_1 = rt_powd_snf(MPC_norm_j(A4_0), 0.1);
          if ((eta1 >= A4_1) || rtIsNaN(A4_1)) {
            A4_1 = eta1;
          }

          if ((d6 <= A4_1) || rtIsNaN(A4_1)) {
            A4_1 = d6;
          }

          A4_1 = ceil(MPC_log2(A4_1 / 5.3719203511481517));
          if (A4_1 >= 0.0) {
            exptj = A4_1;
          }

          d6 = rt_powd_snf(2.0, exptj);
          for (e_j = 0; e_j < 81; e_j++) {
            eta1 = A[e_j] / d6;
            T[e_j] = eta1;
            A4_0[e_j] = 0.05031554467093536 * fabs(eta1);
          }

          MPC_mpower(A4_0, 27.0, tmp);
          A4_1 = ceil(MPC_log2(MPC_norm_j(tmp) / MPC_norm_j(T) * 2.0 /
                               2.2204460492503131E-16) / 26.0);
          if (!(A4_1 >= 0.0)) {
            A4_1 = 0.0;
          }

          exptj += A4_1;
          if (rtIsInf(exptj)) {
            d6 = MPC_norm_j(A) / 5.3719203511481517;
            if ((!rtIsInf(d6)) && (!rtIsNaN(d6))) {
              d6 = frexp(d6, &b_s);
            } else {
              b_s = 0;
            }

            exptj = b_s;
            if (d6 == 0.5) {
              exptj = static_cast<real_T>(b_s) - 1.0;
            }
          }

          b_s = 13;
        }

        if (exptj != 0.0) {
          d6 = rt_powd_snf(2.0, exptj);
          eta1 = rt_powd_snf(2.0, 2.0 * exptj);
          A4_1 = rt_powd_snf(2.0, 4.0 * exptj);
          d_y = rt_powd_snf(2.0, 6.0 * exptj);
          for (e_j = 0; e_j < 81; e_j++) {
            A[e_j] /= d6;
            A2[e_j] /= eta1;
            A4[e_j] /= A4_1;
            A6[e_j] /= d_y;
          }
        }

        if (recomputeDiags) {
          for (e_j = 0; e_j < 8; e_j++) {
            blockFormat[e_j] = 0;
          }

          e_j = 0;
          while (e_j + 1 < 8) {
            d6 = A[(9 * e_j + e_j) + 1];
            if (d6 != 0.0) {
              blockFormat[e_j] = 2;
              blockFormat[e_j + 1] = 0;
              e_j += 2;
            } else if ((d6 == 0.0) && (A[((e_j + 1) * 9 + e_j) + 2] == 0.0)) {
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

        MPC_padeApproximation(A, A2, A4, A6, b_s, F);
        if (recomputeDiags) {
          MPC_recomputeBlockDiag(A, F, blockFormat);
        }

        b_s = static_cast<int32_T>(exptj);
        for (k = 0; k < b_s; k++) {
          for (e_j = 0; e_j < 9; e_j++) {
            for (e_i = 0; e_i < 9; e_i++) {
              exptj = 0.0;
              for (b_k = 0; b_k < 9; b_k++) {
                exptj += F[9 * b_k + e_j] * F[9 * e_i + b_k];
              }

              A4[e_j + 9 * e_i] = exptj;
            }
          }

          memcpy(&F[0], &A4[0], 81U * sizeof(real_T));
          if (recomputeDiags) {
            for (e_j = 0; e_j < 81; e_j++) {
              A[e_j] *= 2.0;
            }

            MPC_recomputeBlockDiag(A, F, blockFormat);
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S101>/MATLAB Function1'
void MPC_smallQuat(const real_T q[4], real_T p[4])
{
  real_T axis[3];
  real_T a_idx_0;
  real_T a_idx_1;
  real_T angle;
  real_T b_norm;
  real_T den;
  real_T p_tmp;
  boolean_T rEQ0;
  b_norm = sqrt(((q[0] * q[0] + q[1] * q[1]) + q[2] * q[2]) + q[3] * q[3]);
  angle = acos(q[0] / b_norm) * 2.0;
  den = sin(angle / 2.0);
  a_idx_0 = q[1] / b_norm / den;
  a_idx_1 = q[2] / b_norm / den;
  b_norm = q[3] / b_norm / den;
  rEQ0 = rtIsNaN(a_idx_0);
  if (!rEQ0) {
    rEQ0 = rtIsNaN(a_idx_1);
  }

  if (!rEQ0) {
    rEQ0 = rtIsNaN(b_norm);
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
      den = (rtNaN);
    } else if (rtIsInf(angle + 3.1415926535897931)) {
      den = (rtNaN);
    } else if (angle + 3.1415926535897931 == 0.0) {
      den = 0.0;
    } else {
      den = fmod(angle + 3.1415926535897931, 6.2831853071795862);
      rEQ0 = (den == 0.0);
      if (!rEQ0) {
        angle = fabs((angle + 3.1415926535897931) / 6.2831853071795862);
        rEQ0 = !(fabs(angle - floor(angle + 0.5)) > 2.2204460492503131E-16 *
                 angle);
      }

      if (rEQ0) {
        den = 0.0;
      } else if (den < 0.0) {
        den += 6.2831853071795862;
      }
    }

    axis[0] = a_idx_0;
    axis[1] = a_idx_1;
    axis[2] = b_norm;
    angle = MPC_norm(axis);
    den = (den - 3.1415926535897931) / 2.0;
    p_tmp = sin(den);
    p[0] = cos(den);
    p[1] = a_idx_0 / angle * p_tmp;
    p[2] = a_idx_1 / angle * p_tmp;
    p[3] = b_norm / angle * p_tmp;
  }
}

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static real_T MPC_rand(void)
{
  uint32_T b_u[2];
  uint32_T mti;
  uint32_T y;

  // ========================= COPYRIGHT NOTICE ============================
  //  This is a uniform (0,1) pseudorandom number generator based on:
  //
  //  A C-program for MT19937, with initialization improved 2002/1/26.
  //  Coded by Takuji Nishimura and Makoto Matsumoto.
  //
  //  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
  //  All rights reserved.
  //
  //  Redistribution and use in source and binary forms, with or without
  //  modification, are permitted provided that the following conditions
  //  are met:
  //
  //    1. Redistributions of source code must retain the above copyright
  //       notice, this list of conditions and the following disclaimer.
  //
  //    2. Redistributions in binary form must reproduce the above copyright
  //       notice, this list of conditions and the following disclaimer
  //       in the documentation and/or other materials provided with the
  //       distribution.
  //
  //    3. The names of its contributors may not be used to endorse or
  //       promote products derived from this software without specific
  //       prior written permission.
  //
  //  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  //  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  //  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  //  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT
  //  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  //  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  //  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  //  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  //  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  //  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  //  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  //
  // =============================   END   =================================
  int32_T exitg1;
  do {
    int32_T k;
    exitg1 = 0;
    for (k = 0; k < 2; k++) {
      mti = MPC_DW.state_k[624] + 1U;
      if (MPC_DW.state_k[624] + 1U >= 625U) {
        for (int32_T kk = 0; kk < 227; kk++) {
          mti = (MPC_DW.state_k[kk + 1] & 2147483647U) | (MPC_DW.state_k[kk] &
            2147483648U);
          if ((mti & 1U) == 0U) {
            mti >>= 1U;
          } else {
            mti = mti >> 1U ^ 2567483615U;
          }

          MPC_DW.state_k[kk] = MPC_DW.state_k[kk + 397] ^ mti;
        }

        for (int32_T kk = 0; kk < 396; kk++) {
          mti = (MPC_DW.state_k[kk + 227] & 2147483648U) | (MPC_DW.state_k[kk +
            228] & 2147483647U);
          if ((mti & 1U) == 0U) {
            mti >>= 1U;
          } else {
            mti = mti >> 1U ^ 2567483615U;
          }

          MPC_DW.state_k[kk + 227] = MPC_DW.state_k[kk] ^ mti;
        }

        mti = (MPC_DW.state_k[623] & 2147483648U) | (MPC_DW.state_k[0] &
          2147483647U);
        if ((mti & 1U) == 0U) {
          mti >>= 1U;
        } else {
          mti = mti >> 1U ^ 2567483615U;
        }

        MPC_DW.state_k[623] = MPC_DW.state_k[396] ^ mti;
        mti = 1U;
      }

      y = MPC_DW.state_k[static_cast<int32_T>(mti) - 1];
      MPC_DW.state_k[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      b_u[k] = y >> 18U ^ y;
    }

    mti = b_u[0] >> 5U;
    y = b_u[1] >> 6U;
    if ((mti == 0U) && (y == 0U)) {
      boolean_T b_isvalid;
      b_isvalid = ((MPC_DW.state_k[624] >= 1U) && (MPC_DW.state_k[624] < 625U));
      if (b_isvalid) {
        boolean_T exitg2;
        b_isvalid = false;
        k = 1;
        exitg2 = false;
        while ((!exitg2) && (k < 625)) {
          if (MPC_DW.state_k[k - 1] == 0U) {
            k++;
          } else {
            b_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!b_isvalid) {
        MPC_DW.state_k[0] = 5489U;
        MPC_DW.state_k[624] = 624U;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return (static_cast<real_T>(mti) * 6.7108864E+7 + static_cast<real_T>(y)) *
    1.1102230246251565E-16;
}

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static void MPC_xgetrf(real_T A[36], int32_T ipiv[6], int32_T *info)
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

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static void MPC_mrdiv_n(real_T A[72], const real_T B[36])
{
  real_T b_A[36];
  real_T b_temp;
  int32_T ipiv[6];
  int32_T b_j;
  int32_T b_jBcol;
  int32_T info;
  int32_T jAcol;
  int32_T jBcol;
  int32_T k;
  int32_T kBcol;
  memcpy(&b_A[0], &B[0], 36U * sizeof(real_T));
  MPC_xgetrf(b_A, ipiv, &info);
  for (b_j = 0; b_j < 6; b_j++) {
    jBcol = 12 * b_j;
    jAcol = 6 * b_j;
    for (k = 0; k < b_j; k++) {
      kBcol = 12 * k;
      b_temp = b_A[k + jAcol];
      if (b_temp != 0.0) {
        for (b_jBcol = 0; b_jBcol < 12; b_jBcol++) {
          info = b_jBcol + jBcol;
          A[info] -= A[b_jBcol + kBcol] * b_temp;
        }
      }
    }

    b_temp = 1.0 / b_A[b_j + jAcol];
    for (k = 0; k < 12; k++) {
      info = k + jBcol;
      A[info] *= b_temp;
    }
  }

  for (b_j = 5; b_j >= 0; b_j--) {
    b_jBcol = 12 * b_j;
    jAcol = 6 * b_j - 1;
    for (jBcol = b_j + 2; jBcol < 7; jBcol++) {
      kBcol = (jBcol - 1) * 12;
      b_temp = b_A[jBcol + jAcol];
      if (b_temp != 0.0) {
        for (k = 0; k < 12; k++) {
          info = k + b_jBcol;
          A[info] -= A[k + kBcol] * b_temp;
        }
      }
    }
  }

  for (b_j = 4; b_j >= 0; b_j--) {
    k = ipiv[b_j];
    if (b_j + 1 != k) {
      for (jBcol = 0; jBcol < 12; jBcol++) {
        b_jBcol = 12 * b_j + jBcol;
        b_temp = A[b_jBcol];
        info = (k - 1) * 12 + jBcol;
        A[b_jBcol] = A[info];
        A[info] = b_temp;
      }
    }
  }
}

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static void MPC_timeKeeper_m(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime, real_T
  *outTime_tv_sec, real_T *outTime_tv_nsec)
{
  coderTimespec origTimespec;
  if (!MPC_DW.savedTime_not_empty_n) {
    if (!MPC_DW.freq_not_empty_g) {
      MPC_DW.freq_not_empty_g = true;
      coderInitTimeFunctions(&MPC_DW.freq_m);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, MPC_DW.freq_m);
    savedTime->tv_sec = origTimespec.tv_sec;
    savedTime->tv_nsec = origTimespec.tv_nsec;
  }

  *outTime_tv_sec = savedTime->tv_sec;
  *outTime_tv_nsec = savedTime->tv_nsec;
}

// Function for MATLAB Function: '<S97>/MATLAB Function1'
static real_T MPC_toc(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime)
{
  coderTimespec origTimespec;
  real_T t;
  real_T tstart_tv_nsec;
  real_T tstart_tv_sec;
  MPC_timeKeeper_m(savedTime, &tstart_tv_sec, &tstart_tv_nsec);
  if (!MPC_DW.freq_not_empty_g) {
    MPC_DW.freq_not_empty_g = true;
    coderInitTimeFunctions(&MPC_DW.freq_m);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, MPC_DW.freq_m);
  t = (origTimespec.tv_nsec - tstart_tv_nsec) / 1.0E+9 + (origTimespec.tv_sec -
    tstart_tv_sec);
  return t;
}

// Function for MATLAB Function: '<S98>/MATLAB Function1'
static void MPC_timeKeeper_k(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_f)
{
  coderTimespec origTimespec;
  if (!MPC_DW.savedTime_not_empty_e) {
    if (!MPC_DW.freq_not_empty_j) {
      MPC_DW.freq_not_empty_j = true;
      coderInitTimeFunctions(&MPC_DW.freq_f);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, MPC_DW.freq_f);
    MPC_DW.savedTime_not_empty_e = true;
  }

  savedTime_f->tv_sec = newTime_tv_sec;
  savedTime_f->tv_nsec = newTime_tv_nsec;
}

// Function for MATLAB Function: '<S98>/MATLAB Function1'
static void MPC_tic_e(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_f)
{
  coderTimespec origTimespec;
  if (!MPC_DW.freq_not_empty_j) {
    MPC_DW.freq_not_empty_j = true;
    coderInitTimeFunctions(&MPC_DW.freq_f);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, MPC_DW.freq_f);
  MPC_timeKeeper_k(origTimespec.tv_sec, origTimespec.tv_nsec, savedTime_f);
}

// Function for MATLAB Function: '<S98>/MATLAB Function1'
static real_T MPC_norm_a(const real_T x[9])
{
  real_T y;
  int32_T j;
  boolean_T exitg1;
  y = 0.0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 3)) {
    real_T s;
    s = (fabs(x[3 * j + 1]) + fabs(x[3 * j])) + fabs(x[3 * j + 2]);
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

// Function for MATLAB Function: '<S98>/MATLAB Function1'
static void MPC_mpower_m(const real_T a[9], real_T b, real_T c[9])
{
  real_T aBuffer[9];
  real_T b_a[9];
  real_T cBuffer[9];
  real_T cBuffer_0[9];
  real_T cBuffer_1[9];
  real_T e;
  e = fabs(b);
  if (e <= 2.147483647E+9) {
    int32_T b_n;
    int32_T n;
    int32_T nb;
    int32_T nbitson;
    memcpy(&b_a[0], &a[0], 9U * sizeof(real_T));
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
        for (b_n = 0; b_n < 3; b_n++) {
          for (nbitson = 0; nbitson < 3; nbitson++) {
            c[nbitson + 3 * b_n] = (a[3 * b_n + 1] * a[nbitson + 3] + a[3 * b_n]
              * a[nbitson]) + a[3 * b_n + 2] * a[nbitson + 6];
          }
        }
      } else {
        boolean_T firstmult;
        firstmult = false;
        for (b_n = 0; b_n < 9; b_n++) {
          if (!firstmult) {
            firstmult = rtIsNaN(a[b_n]);
          }
        }

        if (firstmult) {
          for (b_n = 0; b_n < 9; b_n++) {
            c[b_n] = (rtNaN);
          }
        } else {
          memset(&c[0], 0, 9U * sizeof(real_T));
          c[0] = 1.0;
          c[4] = 1.0;
          c[8] = 1.0;
        }
      }
    } else {
      real_T c_0;
      real_T c_1;
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
                memcpy(&cBuffer[0], &aBuffer[0], 9U * sizeof(real_T));
              } else {
                memcpy(&cBuffer[0], &b_a[0], 9U * sizeof(real_T));
              }
            } else if (aBufferInUse) {
              memcpy(&c[0], &aBuffer[0], 9U * sizeof(real_T));
            } else {
              memcpy(&c[0], &b_a[0], 9U * sizeof(real_T));
            }
          } else {
            if (aBufferInUse) {
              if (cBufferInUse) {
                for (b_n = 0; b_n < 3; b_n++) {
                  ed2 = cBuffer[b_n + 3];
                  e = cBuffer[b_n];
                  c_0 = cBuffer[b_n + 6];
                  for (nbitson = 0; nbitson < 3; nbitson++) {
                    c[b_n + 3 * nbitson] = (aBuffer[3 * nbitson + 1] * ed2 +
                      aBuffer[3 * nbitson] * e) + aBuffer[3 * nbitson + 2] * c_0;
                  }
                }
              } else {
                for (b_n = 0; b_n < 3; b_n++) {
                  e = c[b_n + 3];
                  c_0 = c[b_n];
                  c_1 = c[b_n + 6];
                  for (nbitson = 0; nbitson < 3; nbitson++) {
                    cBuffer[b_n + 3 * nbitson] = (aBuffer[3 * nbitson + 1] * e +
                      aBuffer[3 * nbitson] * c_0) + aBuffer[3 * nbitson + 2] *
                      c_1;
                  }
                }
              }
            } else if (cBufferInUse) {
              for (b_n = 0; b_n < 3; b_n++) {
                ed2 = cBuffer[b_n + 3];
                e = cBuffer[b_n];
                c_0 = cBuffer[b_n + 6];
                for (nbitson = 0; nbitson < 3; nbitson++) {
                  c[b_n + 3 * nbitson] = (b_a[3 * nbitson + 1] * ed2 + b_a[3 *
                    nbitson] * e) + b_a[3 * nbitson + 2] * c_0;
                }
              }
            } else {
              for (b_n = 0; b_n < 3; b_n++) {
                e = c[b_n + 3];
                c_0 = c[b_n];
                c_1 = c[b_n + 6];
                for (nbitson = 0; nbitson < 3; nbitson++) {
                  cBuffer[b_n + 3 * nbitson] = (b_a[3 * nbitson + 1] * e + b_a[3
                    * nbitson] * c_0) + b_a[3 * nbitson + 2] * c_1;
                }
              }
            }

            cBufferInUse = !cBufferInUse;
          }
        }

        n >>= 1;
        if (aBufferInUse) {
          for (b_n = 0; b_n < 3; b_n++) {
            for (nbitson = 0; nbitson < 3; nbitson++) {
              b_a[b_n + 3 * nbitson] = (aBuffer[3 * nbitson + 1] * aBuffer[b_n +
                3] + aBuffer[3 * nbitson] * aBuffer[b_n]) + aBuffer[3 * nbitson
                + 2] * aBuffer[b_n + 6];
            }
          }
        } else {
          for (b_n = 0; b_n < 3; b_n++) {
            for (nbitson = 0; nbitson < 3; nbitson++) {
              aBuffer[b_n + 3 * nbitson] = (b_a[3 * nbitson + 1] * b_a[b_n + 3]
                + b_a[3 * nbitson] * b_a[b_n]) + b_a[3 * nbitson + 2] * b_a[b_n
                + 6];
            }
          }
        }

        aBufferInUse = !aBufferInUse;
      }

      for (b_n = 0; b_n < 3; b_n++) {
        real_T aBuffer_0;
        real_T aBuffer_1;
        real_T b_a_0;
        real_T b_a_1;
        real_T b_a_2;
        c_1 = aBuffer[3 * b_n];
        n = 3 * b_n + 1;
        aBuffer_0 = aBuffer[n];
        nb = 3 * b_n + 2;
        aBuffer_1 = aBuffer[nb];
        b_a_0 = b_a[3 * b_n];
        b_a_1 = b_a[n];
        b_a_2 = b_a[nb];
        for (nbitson = 0; nbitson < 3; nbitson++) {
          ed2 = cBuffer[nbitson];
          e = c_1 * ed2;
          c_0 = b_a_0 * ed2;
          ed2 = cBuffer[nbitson + 3];
          e += aBuffer_0 * ed2;
          c_0 += b_a_1 * ed2;
          ed2 = cBuffer[nbitson + 6];
          n = 3 * b_n + nbitson;
          cBuffer_1[n] = b_a_2 * ed2 + c_0;
          cBuffer_0[n] = aBuffer_1 * ed2 + e;
        }
      }

      for (b_n = 0; b_n < 9; b_n++) {
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
    memcpy(&b_a[0], &a[0], 9U * sizeof(real_T));
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
            memcpy(&c[0], &b_a[0], 9U * sizeof(real_T));
            firstmult = false;
          } else {
            for (int32_T b_n = 0; b_n < 3; b_n++) {
              real_T c_0;
              real_T c_1;
              e = c[b_n + 3];
              c_0 = c[b_n];
              c_1 = c[b_n + 6];
              for (int32_T nbitson = 0; nbitson < 3; nbitson++) {
                cBuffer[b_n + 3 * nbitson] = (b_a[3 * nbitson + 1] * e + b_a[3 *
                  nbitson] * c_0) + b_a[3 * nbitson + 2] * c_1;
              }
            }

            memcpy(&c[0], &cBuffer[0], 9U * sizeof(real_T));
          }
        }

        if (ed2 == 0.0) {
          exitg1 = 1;
        } else {
          e = ed2;
          for (int32_T b_n = 0; b_n < 3; b_n++) {
            for (int32_T nbitson = 0; nbitson < 3; nbitson++) {
              cBuffer[b_n + 3 * nbitson] = (b_a[3 * nbitson + 1] * b_a[b_n + 3]
                + b_a[3 * nbitson] * b_a[b_n]) + b_a[3 * nbitson + 2] * b_a[b_n
                + 6];
            }
          }

          memcpy(&b_a[0], &cBuffer[0], 9U * sizeof(real_T));
        }
      } while (exitg1 == 0);
    } else {
      for (int32_T b_n = 0; b_n < 9; b_n++) {
        c[b_n] = (rtNaN);
      }
    }
  }
}

// Function for MATLAB Function: '<S98>/MATLAB Function1'
static void MPC_padeApproximation_g(const real_T A[9], const real_T A2[9], const
  real_T A4[9], const real_T A6[9], int32_T m, real_T F[9])
{
  real_T A6_0[9];
  real_T U[9];
  real_T V[9];
  real_T A4_0;
  real_T F_0;
  real_T F_1;
  real_T F_tmp;
  real_T F_tmp_0;
  real_T F_tmp_1;
  real_T F_tmp_2;
  real_T F_tmp_3;
  real_T a21;
  real_T d;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  switch (m) {
   case 3:
    memcpy(&U[0], &A2[0], 9U * sizeof(real_T));
    U[0] += 60.0;
    U[4] += 60.0;
    U[8] += 60.0;
    for (r1 = 0; r1 < 3; r1++) {
      d = U[3 * r1 + 1];
      a21 = U[3 * r1];
      A4_0 = U[3 * r1 + 2];
      for (r2 = 0; r2 < 3; r2++) {
        A6_0[r2 + 3 * r1] = (A[r2 + 3] * d + a21 * A[r2]) + A[r2 + 6] * A4_0;
      }
    }

    for (r1 = 0; r1 < 9; r1++) {
      U[r1] = A6_0[r1];
      V[r1] = 12.0 * A2[r1];
    }

    d = 120.0;
    break;

   case 5:
    for (r1 = 0; r1 < 9; r1++) {
      U[r1] = 420.0 * A2[r1] + A4[r1];
    }

    U[0] += 15120.0;
    U[4] += 15120.0;
    U[8] += 15120.0;
    for (r1 = 0; r1 < 3; r1++) {
      d = U[3 * r1 + 1];
      a21 = U[3 * r1];
      A4_0 = U[3 * r1 + 2];
      for (r2 = 0; r2 < 3; r2++) {
        A6_0[r2 + 3 * r1] = (A[r2 + 3] * d + a21 * A[r2]) + A[r2 + 6] * A4_0;
      }
    }

    for (r1 = 0; r1 < 9; r1++) {
      U[r1] = A6_0[r1];
      V[r1] = 30.0 * A4[r1] + 3360.0 * A2[r1];
    }

    d = 30240.0;
    break;

   case 7:
    for (r1 = 0; r1 < 9; r1++) {
      U[r1] = (1512.0 * A4[r1] + A6[r1]) + 277200.0 * A2[r1];
    }

    U[0] += 8.64864E+6;
    U[4] += 8.64864E+6;
    U[8] += 8.64864E+6;
    for (r1 = 0; r1 < 3; r1++) {
      d = U[3 * r1 + 1];
      a21 = U[3 * r1];
      A4_0 = U[3 * r1 + 2];
      for (r2 = 0; r2 < 3; r2++) {
        A6_0[r2 + 3 * r1] = (A[r2 + 3] * d + a21 * A[r2]) + A[r2 + 6] * A4_0;
      }
    }

    for (r1 = 0; r1 < 9; r1++) {
      U[r1] = A6_0[r1];
      V[r1] = (56.0 * A6[r1] + 25200.0 * A4[r1]) + 1.99584E+6 * A2[r1];
    }

    d = 1.729728E+7;
    break;

   case 9:
    for (r1 = 0; r1 < 3; r1++) {
      a21 = A2[3 * r1 + 1];
      d = A2[3 * r1];
      A4_0 = A2[3 * r1 + 2];
      for (r2 = 0; r2 < 3; r2++) {
        V[r2 + 3 * r1] = (A6[r2 + 3] * a21 + d * A6[r2]) + A6[r2 + 6] * A4_0;
      }
    }

    for (r1 = 0; r1 < 9; r1++) {
      U[r1] = ((3960.0 * A6[r1] + V[r1]) + 2.16216E+6 * A4[r1]) + 3.027024E+8 *
        A2[r1];
    }

    U[0] += 8.8216128E+9;
    U[4] += 8.8216128E+9;
    U[8] += 8.8216128E+9;
    for (r1 = 0; r1 < 3; r1++) {
      d = U[3 * r1 + 1];
      a21 = U[3 * r1];
      A4_0 = U[3 * r1 + 2];
      for (r2 = 0; r2 < 3; r2++) {
        A6_0[r2 + 3 * r1] = (A[r2 + 3] * d + a21 * A[r2]) + A[r2 + 6] * A4_0;
      }
    }

    for (r1 = 0; r1 < 9; r1++) {
      U[r1] = A6_0[r1];
      V[r1] = ((90.0 * V[r1] + 110880.0 * A6[r1]) + 3.027024E+7 * A4[r1]) +
        2.0756736E+9 * A2[r1];
    }

    d = 1.76432256E+10;
    break;

   default:
    for (r1 = 0; r1 < 9; r1++) {
      d = A6[r1];
      A4_0 = A4[r1];
      a21 = A2[r1];
      U[r1] = (3.352212864E+10 * d + 1.05594705216E+13 * A4_0) +
        1.1873537964288E+15 * a21;
      V[r1] = (16380.0 * A4_0 + d) + 4.08408E+7 * a21;
    }

    U[0] += 3.238237626624E+16;
    U[4] += 3.238237626624E+16;
    U[8] += 3.238237626624E+16;
    for (r1 = 0; r1 < 3; r1++) {
      d = A6[r1 + 3];
      a21 = A6[r1];
      A4_0 = A6[r1 + 6];
      for (r2 = 0; r2 < 3; r2++) {
        r3 = 3 * r2 + r1;
        A6_0[r3] = ((V[3 * r2 + 1] * d + V[3 * r2] * a21) + V[3 * r2 + 2] * A4_0)
          + U[r3];
      }
    }

    for (r1 = 0; r1 < 3; r1++) {
      d = A6_0[3 * r1 + 1];
      a21 = A6_0[3 * r1];
      A4_0 = A6_0[3 * r1 + 2];
      for (r2 = 0; r2 < 3; r2++) {
        U[r2 + 3 * r1] = (A[r2 + 3] * d + a21 * A[r2]) + A[r2 + 6] * A4_0;
      }
    }

    for (r1 = 0; r1 < 9; r1++) {
      A6_0[r1] = (182.0 * A6[r1] + 960960.0 * A4[r1]) + 1.32324192E+9 * A2[r1];
    }

    for (r1 = 0; r1 < 3; r1++) {
      for (r2 = 0; r2 < 3; r2++) {
        r3 = 3 * r2 + r1;
        V[r3] = ((((A6_0[3 * r2 + 1] * A6[r1 + 3] + A6_0[3 * r2] * A6[r1]) +
                   A6_0[3 * r2 + 2] * A6[r1 + 6]) + A6[r3] * 6.704425728E+11) +
                 A4[r3] * 1.29060195264E+14) + A2[r3] * 7.7717703038976E+15;
      }
    }

    d = 6.476475253248E+16;
    break;
  }

  V[0] += d;
  V[4] += d;
  V[8] += d;
  for (r1 = 0; r1 < 9; r1++) {
    d = U[r1];
    V[r1] -= d;
    U[r1] = 2.0 * d;
  }

  r1 = 0;
  r2 = 1;
  r3 = 2;
  d = fabs(V[0]);
  a21 = fabs(V[1]);
  if (a21 > d) {
    d = a21;
    r1 = 1;
    r2 = 0;
  }

  if (fabs(V[2]) > d) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  V[r2] /= V[r1];
  V[r3] /= V[r1];
  V[r2 + 3] -= V[r1 + 3] * V[r2];
  V[r3 + 3] -= V[r1 + 3] * V[r3];
  V[r2 + 6] -= V[r1 + 6] * V[r2];
  V[r3 + 6] -= V[r1 + 6] * V[r3];
  if (fabs(V[r3 + 3]) > fabs(V[r2 + 3])) {
    int32_T rtemp;
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }

  V[r3 + 3] /= V[r2 + 3];
  V[r3 + 6] -= V[r3 + 3] * V[r2 + 6];
  d = U[r1];
  a21 = U[r2] - d * V[r2];
  A4_0 = V[r3 + 3];
  F_tmp = V[r3 + 6];
  F_0 = ((U[r3] - d * V[r3]) - A4_0 * a21) / F_tmp;
  F[2] = F_0;
  F_tmp_0 = V[r2 + 6];
  F_tmp_1 = V[r2 + 3];
  a21 = (a21 - F_tmp_0 * F_0) / F_tmp_1;
  F[1] = a21;
  F_tmp_2 = V[r1 + 6];
  F_tmp_3 = V[r1 + 3];
  F_1 = ((d - F_tmp_2 * F_0) - F_tmp_3 * a21) / V[r1];
  d = U[r1 + 3];
  a21 = U[r2 + 3] - d * V[r2];
  F_0 = ((U[r3 + 3] - d * V[r3]) - A4_0 * a21) / F_tmp;
  F[5] = F_0;
  a21 = (a21 - F_tmp_0 * F_0) / F_tmp_1;
  F[4] = a21;
  F[3] = ((d - F_tmp_2 * F_0) - F_tmp_3 * a21) / V[r1];
  d = U[r1 + 6];
  a21 = U[r2 + 6] - d * V[r2];
  F_0 = ((U[r3 + 6] - d * V[r3]) - A4_0 * a21) / F_tmp;
  a21 = (a21 - F_tmp_0 * F_0) / F_tmp_1;
  F[7] = a21;
  F[6] = ((d - F_tmp_2 * F_0) - F_tmp_3 * a21) / V[r1];
  F[0] = F_1 + 1.0;
  F[4]++;
  F[8] = F_0 + 1.0;
}

// Function for MATLAB Function: '<S98>/MATLAB Function1'
static void MPC_recomputeBlockDiag_c(const real_T A[9], real_T F[9], const
  int32_T blockFormat[2])
{
  real_T delta;
  real_T expa;
  real_T sinchdelta;
  real_T u1;
  switch (blockFormat[0]) {
   case 0:
    break;

   case 1:
    delta = exp(A[0]);
    expa = exp(A[4]);
    sinchdelta = (A[0] + A[4]) / 2.0;
    u1 = fabs(A[0] - A[4]) / 2.0;
    if ((sinchdelta >= u1) || rtIsNaN(u1)) {
      u1 = sinchdelta;
    }

    if (u1 < 709.782712893384) {
      u1 = (A[4] - A[0]) / 2.0;
      if (u1 == 0.0) {
        u1 = 1.0;
      } else {
        u1 = sinh(u1) / u1;
      }

      sinchdelta = A[3] * exp(sinchdelta) * u1;
    } else {
      sinchdelta = (expa - delta) * A[3] / (A[4] - A[0]);
    }

    F[0] = delta;
    F[3] = sinchdelta;
    F[4] = expa;
    break;

   default:
    delta = sqrt(fabs(A[1] * A[3]));
    expa = exp(A[0]);
    if (delta == 0.0) {
      sinchdelta = 1.0;
    } else {
      sinchdelta = sin(delta) / delta;
    }

    F[0] = expa * cos(delta);
    F[1] = expa * A[1] * sinchdelta;
    F[3] = expa * A[3] * sinchdelta;
    F[4] = F[0];
    break;
  }

  switch (blockFormat[1]) {
   case 0:
    break;

   case 1:
    delta = exp(A[4]);
    expa = exp(A[8]);
    sinchdelta = (A[4] + A[8]) / 2.0;
    u1 = fabs(A[4] - A[8]) / 2.0;
    if ((sinchdelta >= u1) || rtIsNaN(u1)) {
      u1 = sinchdelta;
    }

    if (u1 < 709.782712893384) {
      u1 = (A[8] - A[4]) / 2.0;
      if (u1 == 0.0) {
        u1 = 1.0;
      } else {
        u1 = sinh(u1) / u1;
      }

      sinchdelta = A[7] * exp(sinchdelta) * u1;
    } else {
      sinchdelta = (expa - delta) * A[7] / (A[8] - A[4]);
    }

    F[4] = delta;
    F[7] = sinchdelta;
    F[8] = expa;
    break;

   default:
    delta = sqrt(fabs(A[5] * A[7]));
    expa = exp(A[4]);
    if (delta == 0.0) {
      sinchdelta = 1.0;
    } else {
      sinchdelta = sin(delta) / delta;
    }

    F[4] = expa * cos(delta);
    F[5] = expa * A[5] * sinchdelta;
    F[7] = expa * A[7] * sinchdelta;
    F[8] = F[4];
    break;
  }

  if (blockFormat[1] == 0) {
    F[8] = exp(A[8]);
  }
}

// Function for MATLAB Function: '<S98>/MATLAB Function1'
static void MPC_xzsyhetrd_c(real_T A[9], real_T D[3], real_T E[2], real_T tau[2])
{
  real_T tau_tmp;
  real_T taui;
  real_T temp1;
  real_T xnorm;
  int32_T alpha_tmp_tmp_tmp;
  int32_T b_c_tmp;
  int32_T b_jj;
  int32_T d_k;
  int32_T h;
  int32_T i;
  int32_T ii;
  int32_T knt;
  for (i = 0; i < 2; i++) {
    alpha_tmp_tmp_tmp = 3 * i + i;
    temp1 = A[alpha_tmp_tmp_tmp + 1];
    b_c_tmp = i * 3 + 3;
    taui = 0.0;
    xnorm = 0.0;
    if (1 - i >= 1) {
      xnorm = fabs(A[b_c_tmp - 1]);
    }

    if (xnorm != 0.0) {
      xnorm = rt_hypotd_snf(temp1, xnorm);
      if (temp1 >= 0.0) {
        xnorm = -xnorm;
      }

      if (fabs(xnorm) < 1.0020841800044864E-292) {
        knt = 0;
        h = b_c_tmp - i;
        do {
          knt++;
          for (d_k = b_c_tmp; d_k <= h; d_k++) {
            A[d_k - 1] *= 9.9792015476736E+291;
          }

          xnorm *= 9.9792015476736E+291;
          temp1 *= 9.9792015476736E+291;
        } while ((fabs(xnorm) < 1.0020841800044864E-292) && (knt < 20));

        taui = 0.0;
        if (1 - i >= 1) {
          taui = fabs(A[b_c_tmp - 1]);
        }

        xnorm = rt_hypotd_snf(temp1, taui);
        if (temp1 >= 0.0) {
          xnorm = -xnorm;
        }

        taui = (xnorm - temp1) / xnorm;
        temp1 = 1.0 / (temp1 - xnorm);
        for (d_k = b_c_tmp; d_k <= h; d_k++) {
          A[d_k - 1] *= temp1;
        }

        for (b_c_tmp = 0; b_c_tmp < knt; b_c_tmp++) {
          xnorm *= 1.0020841800044864E-292;
        }

        temp1 = xnorm;
      } else {
        taui = (xnorm - temp1) / xnorm;
        temp1 = 1.0 / (temp1 - xnorm);
        h = b_c_tmp - i;
        for (knt = b_c_tmp; knt <= h; knt++) {
          A[knt - 1] *= temp1;
        }

        temp1 = xnorm;
      }
    }

    E[i] = temp1;
    if (taui != 0.0) {
      A[alpha_tmp_tmp_tmp + 1] = 1.0;
      for (b_c_tmp = i + 1; b_c_tmp < 3; b_c_tmp++) {
        tau[b_c_tmp - 1] = 0.0;
      }

      b_c_tmp = 1 - i;
      knt = 3 - i;
      for (b_jj = 0; b_jj <= b_c_tmp; b_jj++) {
        h = i + b_jj;
        temp1 = A[(3 * i + h) + 1] * taui;
        xnorm = 0.0;
        d_k = (h + 1) * 3;
        tau[h] += A[((d_k + i) + b_jj) + 1] * temp1;
        for (ii = b_jj + 2; ii < knt; ii++) {
          tau_tmp = A[d_k + 2];
          tau[1] += tau_tmp * temp1;
          xnorm += A[3 * i + 2] * tau_tmp;
        }

        tau[h] += taui * xnorm;
      }

      temp1 = 0.0;
      h = 2 - i;
      for (d_k = 0; d_k < h; d_k++) {
        temp1 += A[(alpha_tmp_tmp_tmp + d_k) + 1] * tau[i + d_k];
      }

      temp1 *= -0.5 * taui;
      if (!(temp1 == 0.0)) {
        for (b_jj = 0; b_jj < h; b_jj++) {
          d_k = i + b_jj;
          tau[d_k] += A[(alpha_tmp_tmp_tmp + b_jj) + 1] * temp1;
        }
      }

      for (d_k = 0; d_k <= b_c_tmp; d_k++) {
        h = i + d_k;
        temp1 = A[(3 * i + h) + 1];
        xnorm = tau[h];
        tau_tmp = xnorm * temp1;
        b_jj = (h + 1) * 3;
        A[(h + b_jj) + 1] = (A[((b_jj + i) + d_k) + 1] - tau_tmp) - tau_tmp;
        for (h = d_k + 2; h < knt; h++) {
          A[b_jj + 2] = (A[b_jj + 2] - tau[1] * temp1) - A[3 * i + 2] * xnorm;
        }
      }
    }

    A[alpha_tmp_tmp_tmp + 1] = E[i];
    D[i] = A[alpha_tmp_tmp_tmp];
    tau[i] = taui;
  }

  D[2] = A[8];
}

// Function for MATLAB Function: '<S98>/MATLAB Function1'
static void MPC_xzlascl_mlt(real_T cfrom, real_T cto, int32_T m, real_T A[3],
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

// Function for MATLAB Function: '<S98>/MATLAB Function1'
static void MPC_xzlascl_mlt2(real_T cfrom, real_T cto, int32_T m, real_T A[2],
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

// Function for MATLAB Function: '<S98>/MATLAB Function1'
static void MPC_rotateRight_m1(int32_T n, real_T z[9], int32_T iz0, const real_T
  cs[4], int32_T ic0, int32_T is0)
{
  for (int32_T b_j = 0; b_j <= n - 2; b_j++) {
    real_T ctemp;
    real_T stemp;
    int32_T offsetj;
    int32_T offsetjp1;
    ctemp = cs[(ic0 + b_j) - 1];
    stemp = cs[(is0 + b_j) - 1];
    offsetj = (b_j * 3 + iz0) - 1;
    offsetjp1 = ((b_j + 1) * 3 + iz0) - 1;
    if ((ctemp != 1.0) || (stemp != 0.0)) {
      real_T temp;
      real_T z_0;
      temp = z[offsetjp1];
      z_0 = z[offsetj];
      z[offsetjp1] = ctemp * temp - stemp * z_0;
      z[offsetj] = stemp * temp + ctemp * z_0;
      temp = z[offsetjp1 + 1];
      z_0 = z[offsetj + 1];
      z[offsetjp1 + 1] = ctemp * temp - z_0 * stemp;
      z[offsetj + 1] = z_0 * ctemp + stemp * temp;
      temp = z[offsetjp1 + 2];
      z_0 = z[offsetj + 2];
      z[offsetjp1 + 2] = ctemp * temp - z_0 * stemp;
      z[offsetj + 2] = z_0 * ctemp + stemp * temp;
    }
  }
}

// Function for MATLAB Function: '<S98>/MATLAB Function1'
static void MPC_rotateRight_m(int32_T n, real_T z[9], int32_T iz0, const real_T
  cs[4], int32_T ic0, int32_T is0)
{
  for (int32_T j = n - 1; j >= 1; j--) {
    real_T ctemp;
    real_T stemp;
    int32_T offsetj;
    int32_T offsetjp1;
    ctemp = cs[(ic0 + j) - 2];
    stemp = cs[(is0 + j) - 2];
    offsetj = ((j - 1) * 3 + iz0) - 1;
    offsetjp1 = (j * 3 + iz0) - 1;
    if ((ctemp != 1.0) || (stemp != 0.0)) {
      real_T temp;
      real_T z_0;
      temp = z[offsetjp1];
      z_0 = z[offsetj];
      z[offsetjp1] = ctemp * temp - stemp * z_0;
      z[offsetj] = stemp * temp + ctemp * z_0;
      temp = z[offsetjp1 + 1];
      z_0 = z[offsetj + 1];
      z[offsetjp1 + 1] = ctemp * temp - z_0 * stemp;
      z[offsetj + 1] = z_0 * ctemp + stemp * temp;
      temp = z[offsetjp1 + 2];
      z_0 = z[offsetj + 2];
      z[offsetjp1 + 2] = ctemp * temp - z_0 * stemp;
      z[offsetj + 2] = z_0 * ctemp + stemp * temp;
    }
  }
}

// Function for MATLAB Function: '<S98>/MATLAB Function1'
static int32_T MPC_xzsteqr_c(real_T d[3], real_T e[2], real_T z[9])
{
  real_T work[4];
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
  int32_T info;
  int32_T iscale;
  int32_T jtot;
  int32_T l;
  int32_T l1;
  int32_T lend;
  int32_T lendsv;
  int32_T lsv;
  int32_T m;
  int32_T n_tmp;
  boolean_T exitg2;
  info = 0;
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  work[3] = 0.0;
  jtot = 0;
  l1 = 1;
  do {
    exitg1 = 0;
    if (l1 > 3) {
      for (jtot = 0; jtot < 2; jtot++) {
        lsv = jtot;
        p = d[jtot];
        for (l1 = jtot + 2; l1 < 4; l1++) {
          tst = d[l1 - 1];
          if (tst < p) {
            lsv = l1 - 1;
            p = tst;
          }
        }

        if (lsv != jtot) {
          d[lsv] = d[jtot];
          d[jtot] = p;
          l1 = jtot * 3;
          lsv *= 3;
          tst = z[l1];
          z[l1] = z[lsv];
          z[lsv] = tst;
          tst = z[l1 + 1];
          z[l1 + 1] = z[lsv + 1];
          z[lsv + 1] = tst;
          tst = z[l1 + 2];
          z[l1 + 2] = z[lsv + 2];
          z[lsv + 2] = tst;
        }
      }

      exitg1 = 1;
    } else {
      if (l1 > 1) {
        e[l1 - 2] = 0.0;
      }

      m = l1;
      exitg2 = false;
      while ((!exitg2) && (m < 3)) {
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
          d[0] = (rtNaN);
          d[1] = (rtNaN);
          d[2] = (rtNaN);
          for (m = 0; m < 9; m++) {
            z[m] = (rtNaN);
          }

          exitg1 = 1;
        } else {
          if (tst > 2.2346346549904327E+153) {
            iscale = 1;
            MPC_xzlascl_mlt(tst, 2.2346346549904327E+153, n_tmp, d, l + 1);
            MPC_xzlascl_mlt2(tst, 2.2346346549904327E+153, n_tmp - 1, e, l + 1);
          } else if (tst < 3.02546243347603E-123) {
            iscale = 2;
            MPC_xzlascl_mlt(tst, 3.02546243347603E-123, n_tmp, d, l + 1);
            MPC_xzlascl_mlt2(tst, 3.02546243347603E-123, n_tmp - 1, e, l + 1);
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
                MPC_xdlaev2(d[l], e[l], d[l + 1], &d[l], &b_anorm, &work[l], &p);
                d[l + 1] = b_anorm;
                work[l + 2] = p;
                MPC_rotateRight_m(2, z, l * 3 + 1, work, l + 1, l + 3);
                e[l] = 0.0;
                l += 2;
                if (l + 1 > lend) {
                  exitg4 = 1;
                }
              } else if (jtot == 90) {
                exitg4 = 1;
              } else {
                jtot++;
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
                  MPC_xzlartg(b_anorm, s * r, &c, &b_s, &b_r);
                  s = b_s;
                  if (n_tmp != m) {
                    e[1] = b_r;
                  }

                  b_anorm = d[n_tmp] - p;
                  r = (d[n_tmp - 1] - b_anorm) * b_s + 2.0 * c * b;
                  p = b_s * r;
                  d[n_tmp] = b_anorm + p;
                  b_anorm = c * r - b;
                  work[n_tmp - 1] = c;
                  work[n_tmp + 1] = -b_s;
                }

                MPC_rotateRight_m((m - l) + 1, z, l * 3 + 1, work, l + 1, l + 3);
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
                MPC_xdlaev2(d[l - 1], e[l - 1], d[l], &d[l - 1], &b_anorm,
                            &work[m - 1], &p);
                d[l] = b_anorm;
                work[m + 1] = p;
                MPC_rotateRight_m1(2, z, (l - 1) * 3 + 1, work, m, m + 2);
                e[l - 1] = 0.0;
                l -= 2;
                if (l + 1 < lend) {
                  exitg3 = 1;
                }
              } else if (jtot == 90) {
                exitg3 = 1;
              } else {
                jtot++;
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
                  MPC_xzlartg(b_anorm, s * r, &c, &b_s, &b_r);
                  s = b_s;
                  if (n_tmp != m) {
                    e[0] = b_r;
                  }

                  b_anorm = d[n_tmp - 1] - p;
                  r = (d[n_tmp] - b_anorm) * b_s + 2.0 * c * b;
                  p = b_s * r;
                  d[n_tmp - 1] = b_anorm + p;
                  b_anorm = c * r - b;
                  work[n_tmp - 1] = c;
                  work[n_tmp + 1] = b_s;
                }

                MPC_rotateRight_m1((l - m) + 2, z, (m - 1) * 3 + 1, work, m, m +
                                   2);
                d[l] -= p;
                e[l - 1] = b_anorm;
              }
            } while (exitg3 == 0);
          }

          switch (iscale) {
           case 1:
            m = lendsv - lsv;
            MPC_xzlascl_mlt(2.2346346549904327E+153, tst, m + 1, d, lsv);
            MPC_xzlascl_mlt2(2.2346346549904327E+153, tst, m, e, lsv);
            break;

           case 2:
            m = lendsv - lsv;
            MPC_xzlascl_mlt(3.02546243347603E-123, tst, m + 1, d, lsv);
            MPC_xzlascl_mlt2(3.02546243347603E-123, tst, m, e, lsv);
            break;
          }

          if (jtot >= 90) {
            if (e[0] != 0.0) {
              info = 1;
            }

            if (e[1] != 0.0) {
              info++;
            }

            exitg1 = 1;
          }
        }
      }
    }
  } while (exitg1 == 0);

  return info;
}

// Function for MATLAB Function: '<S98>/MATLAB Function1'
static void MPC_xsyheev_o(real_T A[9], int32_T *info, real_T W[3])
{
  real_T work[3];
  real_T e[2];
  real_T tau[2];
  real_T absx;
  real_T anrm;
  real_T cfrom1;
  real_T cfromc;
  real_T cto1;
  real_T mul;
  int32_T b_ia;
  int32_T d;
  int32_T e_i;
  int32_T exitg1;
  int32_T ia;
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
  e_i = 0;
  exitg2 = false;
  while ((!exitg2) && (e_i < 3)) {
    iaii = 0;
    do {
      exitg1 = 0;
      if (iaii <= e_i) {
        absx = fabs(A[3 * e_i + iaii]);
        if (rtIsNaN(absx)) {
          anrm = (rtNaN);
          exitg1 = 1;
        } else {
          if (absx > anrm) {
            anrm = absx;
          }

          iaii++;
        }
      } else {
        e_i++;
        exitg1 = 2;
      }
    } while (exitg1 == 0);

    if (exitg1 == 1) {
      exitg2 = true;
    }
  }

  if (rtIsInf(anrm) || rtIsNaN(anrm)) {
    W[0] = (rtNaN);
    W[1] = (rtNaN);
    W[2] = (rtNaN);
    for (e_i = 0; e_i < 9; e_i++) {
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

        for (e_i = 0; e_i < 3; e_i++) {
          iaii = e_i * 3;
          A[iaii] *= mul;
          A[iaii + 1] *= mul;
          A[iaii + 2] *= mul;
        }
      }
    }

    MPC_xzsyhetrd_c(A, W, e, tau);
    for (iaii = 1; iaii >= 0; iaii--) {
      e_i = (iaii + 1) * 3;
      A[e_i] = 0.0;
      for (lastv = iaii + 3; lastv < 4; lastv++) {
        A[e_i + 2] = A[3 * iaii + 2];
      }
    }

    A[0] = 1.0;
    A[1] = 0.0;
    A[2] = 0.0;
    work[0] = 0.0;
    work[1] = 0.0;
    work[2] = 0.0;
    for (e_i = 1; e_i >= 0; e_i--) {
      iaii = (e_i * 3 + e_i) + 8;
      if (e_i + 1 < 2) {
        A[iaii - 4] = 1.0;
        if (tau[e_i] != 0.0) {
          lastv = 2;
          lastc = iaii;
          while ((lastv > 0) && (A[lastc - 3] == 0.0)) {
            lastv--;
            lastc--;
          }

          lastc = 1;
          b_ia = iaii - 1;
          do {
            exitg1 = 0;
            if (b_ia + 1 <= (iaii + lastv) - 1) {
              if (A[b_ia] != 0.0) {
                exitg1 = 1;
              } else {
                b_ia++;
              }
            } else {
              lastc = 0;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        } else {
          lastv = 0;
          lastc = 0;
        }

        if (lastv > 0) {
          if (lastc != 0) {
            work[0] = 0.0;
            for (b_ia = iaii; b_ia <= iaii; b_ia += 3) {
              absx = 0.0;
              jA = (b_ia + lastv) - 1;
              for (ia = b_ia; ia <= jA; ia++) {
                absx += A[((iaii + ia) - b_ia) - 4] * A[ia - 1];
              }

              ia = div_nde_s32_floor(b_ia - iaii, 3);
              work[ia] += absx;
            }
          }

          if (!(-tau[e_i] == 0.0)) {
            jA = iaii;
            for (b_ia = 0; b_ia < lastc; b_ia++) {
              if (work[0] != 0.0) {
                absx = work[0] * -tau[e_i];
                d = lastv + jA;
                for (ia = jA; ia < d; ia++) {
                  A[ia - 1] += A[((iaii + ia) - jA) - 4] * absx;
                }
              }

              jA += 3;
            }
          }
        }

        for (lastv = iaii - 2; lastv <= iaii - 2; lastv++) {
          A[lastv - 1] *= -tau[e_i];
        }
      }

      A[iaii - 4] = 1.0 - tau[e_i];
      for (lastv = 0; lastv < e_i; lastv++) {
        A[iaii - 5] = 0.0;
      }
    }

    *info = MPC_xzsteqr_c(W, e, A);
    if (*info != 0) {
      W[0] = (rtNaN);
      W[1] = (rtNaN);
      W[2] = (rtNaN);
      for (e_i = 0; e_i < 9; e_i++) {
        A[e_i] = (rtNaN);
      }
    } else if (iscale) {
      anrm = 1.0 / anrm;
      W[0] *= anrm;
      W[1] *= anrm;
      W[2] *= anrm;
    }
  }
}

// Function for MATLAB Function: '<S98>/MATLAB Function1'
static void MPC_expm_o(real_T A[9], real_T F[9])
{
  real_T A2[9];
  real_T A4[9];
  real_T A4_0[9];
  real_T A6[9];
  real_T T[9];
  real_T tmp[9];
  real_T w[3];
  real_T A4_1;
  real_T A6_0;
  real_T A6_1;
  real_T d6;
  real_T eta1;
  real_T exptj;
  int32_T blockFormat[2];
  int32_T b_k;
  int32_T b_s;
  int32_T c_i;
  int32_T c_k;
  int32_T exitg1;
  boolean_T exitg2;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T guard3;
  boolean_T guard4;
  boolean_T recomputeDiags;
  recomputeDiags = true;
  for (c_k = 0; c_k < 9; c_k++) {
    if (recomputeDiags) {
      exptj = A[c_k];
      if (rtIsInf(exptj) || rtIsNaN(exptj)) {
        recomputeDiags = false;
      }
    }
  }

  if (!recomputeDiags) {
    for (c_k = 0; c_k < 9; c_k++) {
      F[c_k] = (rtNaN);
    }
  } else {
    recomputeDiags = true;
    c_k = 0;
    exitg2 = false;
    while ((!exitg2) && (c_k < 3)) {
      c_i = 0;
      do {
        exitg1 = 0;
        if (c_i < 3) {
          if ((c_i != c_k) && (!(A[3 * c_k + c_i] == 0.0))) {
            recomputeDiags = false;
            exitg1 = 1;
          } else {
            c_i++;
          }
        } else {
          c_k++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (recomputeDiags) {
      memset(&F[0], 0, 9U * sizeof(real_T));
      F[0] = exp(A[0]);
      F[4] = exp(A[4]);
      F[8] = exp(A[8]);
    } else {
      recomputeDiags = true;
      c_k = 0;
      exitg2 = false;
      while ((!exitg2) && (c_k < 3)) {
        c_i = 0;
        do {
          exitg1 = 0;
          if (c_i <= c_k) {
            if (!(A[3 * c_k + c_i] == A[3 * c_i + c_k])) {
              recomputeDiags = false;
              exitg1 = 1;
            } else {
              c_i++;
            }
          } else {
            c_k++;
            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }

      if (recomputeDiags) {
        memcpy(&A2[0], &A[0], 9U * sizeof(real_T));
        MPC_xsyheev_o(A2, &b_s, w);
        for (c_k = 0; c_k < 3; c_k++) {
          exptj = exp(w[c_k]);
          F[3 * c_k] = A2[3 * c_k] * exptj;
          b_s = 3 * c_k + 1;
          F[b_s] = A2[b_s] * exptj;
          b_s = 3 * c_k + 2;
          F[b_s] = A2[b_s] * exptj;
        }

        for (c_k = 0; c_k < 3; c_k++) {
          exptj = F[c_k + 3];
          d6 = F[c_k];
          eta1 = F[c_k + 6];
          for (c_i = 0; c_i < 3; c_i++) {
            A4[c_k + 3 * c_i] = (A2[c_i + 3] * exptj + d6 * A2[c_i]) + A2[c_i +
              6] * eta1;
          }
        }

        memcpy(&F[0], &A4[0], 9U * sizeof(real_T));
        for (c_k = 0; c_k < 3; c_k++) {
          A4[3 * c_k] = (F[3 * c_k] + F[c_k]) / 2.0;
          b_s = 3 * c_k + 1;
          A4[b_s] = (F[c_k + 3] + F[b_s]) / 2.0;
          b_s = 3 * c_k + 2;
          A4[b_s] = (F[c_k + 6] + F[b_s]) / 2.0;
        }

        memcpy(&F[0], &A4[0], 9U * sizeof(real_T));
      } else {
        recomputeDiags = (A[2] == 0.0);
        if (recomputeDiags) {
          b_k = 0;
          exitg2 = false;
          while ((!exitg2) && (b_k < 2)) {
            c_k = 3 * b_k + b_k;
            d6 = A[c_k + 1];
            if (d6 != 0.0) {
              if ((b_k + 1 != 2) && (A[5] != 0.0)) {
                recomputeDiags = false;
                exitg2 = true;
              } else {
                c_i = (b_k + 1) * 3 + b_k;
                if (A[c_i + 1] != A[c_k]) {
                  recomputeDiags = false;
                  exitg2 = true;
                } else {
                  exptj = A[c_i];
                  if (rtIsNaN(d6)) {
                    d6 = (rtNaN);
                  } else if (d6 < 0.0) {
                    d6 = -1.0;
                  } else {
                    d6 = (d6 > 0.0);
                  }

                  if (rtIsNaN(exptj)) {
                    exptj = (rtNaN);
                  } else if (exptj < 0.0) {
                    exptj = -1.0;
                  } else {
                    exptj = (exptj > 0.0);
                  }

                  if (d6 * exptj != -1.0) {
                    recomputeDiags = false;
                    exitg2 = true;
                  } else {
                    b_k++;
                  }
                }
              }
            } else {
              b_k++;
            }
          }
        }

        exptj = 0.0;
        for (c_k = 0; c_k < 3; c_k++) {
          for (c_i = 0; c_i < 3; c_i++) {
            A2[c_i + 3 * c_k] = (A[3 * c_k + 1] * A[c_i + 3] + A[3 * c_k] *
                                 A[c_i]) + A[3 * c_k + 2] * A[c_i + 6];
          }
        }

        for (c_k = 0; c_k < 3; c_k++) {
          for (c_i = 0; c_i < 3; c_i++) {
            A4[c_k + 3 * c_i] = (A2[3 * c_i + 1] * A2[c_k + 3] + A2[3 * c_i] *
                                 A2[c_k]) + A2[3 * c_i + 2] * A2[c_k + 6];
          }

          d6 = A4[c_k + 3];
          eta1 = A4[c_k];
          A4_1 = A4[c_k + 6];
          for (c_i = 0; c_i < 3; c_i++) {
            A6[c_k + 3 * c_i] = (A2[3 * c_i + 1] * d6 + A2[3 * c_i] * eta1) +
              A2[3 * c_i + 2] * A4_1;
          }
        }

        d6 = rt_powd_snf(MPC_norm_a(A6), 0.16666666666666666);
        eta1 = rt_powd_snf(MPC_norm_a(A4), 0.25);
        if ((!(eta1 >= d6)) && (!rtIsNaN(d6))) {
          eta1 = d6;
        }

        guard1 = false;
        guard2 = false;
        guard3 = false;
        guard4 = false;
        if (eta1 <= 0.01495585217958292) {
          for (c_k = 0; c_k < 9; c_k++) {
            A4_0[c_k] = 0.19285012468241128 * fabs(A[c_k]);
          }

          MPC_mpower_m(A4_0, 7.0, tmp);
          A4_1 = ceil(MPC_log2(MPC_norm_a(tmp) / MPC_norm_a(A) * 2.0 /
                               2.2204460492503131E-16) / 6.0);
          if (!(A4_1 >= 0.0)) {
            A4_1 = 0.0;
          }

          if (A4_1 == 0.0) {
            b_s = 3;
          } else {
            guard4 = true;
          }
        } else {
          guard4 = true;
        }

        if (guard4) {
          if (eta1 <= 0.253939833006323) {
            for (c_k = 0; c_k < 9; c_k++) {
              A4_0[c_k] = 0.12321872304378752 * fabs(A[c_k]);
            }

            MPC_mpower_m(A4_0, 11.0, tmp);
            A4_1 = ceil(MPC_log2(MPC_norm_a(tmp) / MPC_norm_a(A) * 2.0 /
                                 2.2204460492503131E-16) / 10.0);
            if (!(A4_1 >= 0.0)) {
              A4_1 = 0.0;
            }

            if (A4_1 == 0.0) {
              b_s = 5;
            } else {
              guard3 = true;
            }
          } else {
            guard3 = true;
          }
        }

        if (guard3) {
          MPC_mpower_m(A4, 2.0, tmp);
          eta1 = rt_powd_snf(MPC_norm_a(tmp), 0.125);
          if ((!(d6 >= eta1)) && (!rtIsNaN(eta1))) {
            d6 = eta1;
          }

          if (d6 <= 0.95041789961629319) {
            for (c_k = 0; c_k < 9; c_k++) {
              A4_0[c_k] = 0.090475336558796943 * fabs(A[c_k]);
            }

            MPC_mpower_m(A4_0, 15.0, tmp);
            A4_1 = ceil(MPC_log2(MPC_norm_a(tmp) / MPC_norm_a(A) * 2.0 /
                                 2.2204460492503131E-16) / 14.0);
            if (!(A4_1 >= 0.0)) {
              A4_1 = 0.0;
            }

            if (A4_1 == 0.0) {
              b_s = 7;
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }
        }

        if (guard2) {
          if (d6 <= 2.097847961257068) {
            for (c_k = 0; c_k < 9; c_k++) {
              A4_0[c_k] = 0.071467735648795785 * fabs(A[c_k]);
            }

            MPC_mpower_m(A4_0, 19.0, tmp);
            A4_1 = ceil(MPC_log2(MPC_norm_a(tmp) / MPC_norm_a(A) * 2.0 /
                                 2.2204460492503131E-16) / 18.0);
            if (!(A4_1 >= 0.0)) {
              A4_1 = 0.0;
            }

            if (A4_1 == 0.0) {
              b_s = 9;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }
        }

        if (guard1) {
          for (c_k = 0; c_k < 3; c_k++) {
            A4_1 = A6[3 * c_k + 1];
            A6_0 = A6[3 * c_k];
            A6_1 = A6[3 * c_k + 2];
            for (c_i = 0; c_i < 3; c_i++) {
              A4_0[c_i + 3 * c_k] = (A4[c_i + 3] * A4_1 + A6_0 * A4[c_i]) +
                A4[c_i + 6] * A6_1;
            }
          }

          A4_1 = rt_powd_snf(MPC_norm_a(A4_0), 0.1);
          if ((eta1 >= A4_1) || rtIsNaN(A4_1)) {
            A4_1 = eta1;
          }

          if ((d6 <= A4_1) || rtIsNaN(A4_1)) {
            A4_1 = d6;
          }

          A4_1 = ceil(MPC_log2(A4_1 / 5.3719203511481517));
          if (A4_1 >= 0.0) {
            exptj = A4_1;
          }

          d6 = rt_powd_snf(2.0, exptj);
          for (c_k = 0; c_k < 9; c_k++) {
            eta1 = A[c_k] / d6;
            T[c_k] = eta1;
            A4_0[c_k] = 0.05031554467093536 * fabs(eta1);
          }

          MPC_mpower_m(A4_0, 27.0, tmp);
          A4_1 = ceil(MPC_log2(MPC_norm_a(tmp) / MPC_norm_a(T) * 2.0 /
                               2.2204460492503131E-16) / 26.0);
          if (!(A4_1 >= 0.0)) {
            A4_1 = 0.0;
          }

          exptj += A4_1;
          if (rtIsInf(exptj)) {
            d6 = MPC_norm_a(A) / 5.3719203511481517;
            if ((!rtIsInf(d6)) && (!rtIsNaN(d6))) {
              d6 = frexp(d6, &b_s);
            } else {
              b_s = 0;
            }

            exptj = b_s;
            if (d6 == 0.5) {
              exptj = static_cast<real_T>(b_s) - 1.0;
            }
          }

          b_s = 13;
        }

        if (exptj != 0.0) {
          d6 = rt_powd_snf(2.0, exptj);
          eta1 = rt_powd_snf(2.0, 2.0 * exptj);
          A4_1 = rt_powd_snf(2.0, 4.0 * exptj);
          A6_0 = rt_powd_snf(2.0, 6.0 * exptj);
          for (c_k = 0; c_k < 9; c_k++) {
            A[c_k] /= d6;
            A2[c_k] /= eta1;
            A4[c_k] /= A4_1;
            A6[c_k] /= A6_0;
          }
        }

        if (recomputeDiags) {
          blockFormat[1] = 0;
          if (A[1] != 0.0) {
            blockFormat[0] = 2;
            blockFormat[1] = 0;
          } else if (A[5] == 0.0) {
            blockFormat[0] = 1;
          } else {
            blockFormat[0] = 0;
          }

          if (A[5] != 0.0) {
            blockFormat[1] = 2;
          } else {
            switch (blockFormat[0]) {
             case 0:
              blockFormat[1] = 1;
              break;

             case 1:
              blockFormat[1] = 1;
              break;
            }
          }
        }

        MPC_padeApproximation_g(A, A2, A4, A6, b_s, F);
        if (recomputeDiags) {
          MPC_recomputeBlockDiag_c(A, F, blockFormat);
        }

        b_s = static_cast<int32_T>(exptj);
        for (b_k = 0; b_k < b_s; b_k++) {
          for (c_k = 0; c_k < 3; c_k++) {
            for (c_i = 0; c_i < 3; c_i++) {
              A4[c_k + 3 * c_i] = (F[3 * c_i + 1] * F[c_k + 3] + F[3 * c_i] *
                                   F[c_k]) + F[3 * c_i + 2] * F[c_k + 6];
            }
          }

          memcpy(&F[0], &A4[0], 9U * sizeof(real_T));
          if (recomputeDiags) {
            for (c_k = 0; c_k < 9; c_k++) {
              A[c_k] *= 2.0;
            }

            MPC_recomputeBlockDiag_c(A, F, blockFormat);
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S98>/MATLAB Function1'
static real_T MPC_norm_ai(const real_T x[2])
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

  return scale * sqrt(y);
}

// Function for MATLAB Function: '<S98>/MATLAB Function1'
static void MPC_timeKeeper_kw(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_f, real_T
  *outTime_tv_sec, real_T *outTime_tv_nsec)
{
  coderTimespec origTimespec;
  if (!MPC_DW.savedTime_not_empty_e) {
    if (!MPC_DW.freq_not_empty_j) {
      MPC_DW.freq_not_empty_j = true;
      coderInitTimeFunctions(&MPC_DW.freq_f);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, MPC_DW.freq_f);
    savedTime_f->tv_sec = origTimespec.tv_sec;
    savedTime_f->tv_nsec = origTimespec.tv_nsec;
  }

  *outTime_tv_sec = savedTime_f->tv_sec;
  *outTime_tv_nsec = savedTime_f->tv_nsec;
}

// Function for MATLAB Function: '<S98>/MATLAB Function1'
static real_T MPC_toc_f(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_f)
{
  coderTimespec origTimespec;
  real_T t;
  real_T tstart_tv_nsec;
  real_T tstart_tv_sec;
  MPC_timeKeeper_kw(savedTime_f, &tstart_tv_sec, &tstart_tv_nsec);
  if (!MPC_DW.freq_not_empty_j) {
    MPC_DW.freq_not_empty_j = true;
    coderInitTimeFunctions(&MPC_DW.freq_f);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, MPC_DW.freq_f);
  t = (origTimespec.tv_nsec - tstart_tv_nsec) / 1.0E+9 + (origTimespec.tv_sec -
    tstart_tv_sec);
  return t;
}

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static void MPC_timeKeeper_a(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_a)
{
  coderTimespec origTimespec;
  if (!MPC_DW.savedTime_not_empty_m) {
    if (!MPC_DW.freq_not_empty_a) {
      MPC_DW.freq_not_empty_a = true;
      coderInitTimeFunctions(&MPC_DW.freq_c);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, MPC_DW.freq_c);
    MPC_DW.savedTime_not_empty_m = true;
  }

  savedTime_a->tv_sec = newTime_tv_sec;
  savedTime_a->tv_nsec = newTime_tv_nsec;
}

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static void MPC_tic_k(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_a)
{
  coderTimespec origTimespec;
  if (!MPC_DW.freq_not_empty_a) {
    MPC_DW.freq_not_empty_a = true;
    coderInitTimeFunctions(&MPC_DW.freq_c);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, MPC_DW.freq_c);
  MPC_timeKeeper_a(origTimespec.tv_sec, origTimespec.tv_nsec, savedTime_a);
}

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static real_T MPC_rand_p(void)
{
  uint32_T b_u[2];
  uint32_T mti;
  uint32_T y;

  // ========================= COPYRIGHT NOTICE ============================
  //  This is a uniform (0,1) pseudorandom number generator based on:
  //
  //  A C-program for MT19937, with initialization improved 2002/1/26.
  //  Coded by Takuji Nishimura and Makoto Matsumoto.
  //
  //  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
  //  All rights reserved.
  //
  //  Redistribution and use in source and binary forms, with or without
  //  modification, are permitted provided that the following conditions
  //  are met:
  //
  //    1. Redistributions of source code must retain the above copyright
  //       notice, this list of conditions and the following disclaimer.
  //
  //    2. Redistributions in binary form must reproduce the above copyright
  //       notice, this list of conditions and the following disclaimer
  //       in the documentation and/or other materials provided with the
  //       distribution.
  //
  //    3. The names of its contributors may not be used to endorse or
  //       promote products derived from this software without specific
  //       prior written permission.
  //
  //  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  //  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  //  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  //  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT
  //  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  //  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  //  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  //  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  //  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  //  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  //  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  //
  // =============================   END   =================================
  int32_T exitg1;
  do {
    int32_T k;
    exitg1 = 0;
    for (k = 0; k < 2; k++) {
      mti = MPC_DW.state_c[624] + 1U;
      if (MPC_DW.state_c[624] + 1U >= 625U) {
        for (int32_T kk = 0; kk < 227; kk++) {
          mti = (MPC_DW.state_c[kk + 1] & 2147483647U) | (MPC_DW.state_c[kk] &
            2147483648U);
          if ((mti & 1U) == 0U) {
            mti >>= 1U;
          } else {
            mti = mti >> 1U ^ 2567483615U;
          }

          MPC_DW.state_c[kk] = MPC_DW.state_c[kk + 397] ^ mti;
        }

        for (int32_T kk = 0; kk < 396; kk++) {
          mti = (MPC_DW.state_c[kk + 227] & 2147483648U) | (MPC_DW.state_c[kk +
            228] & 2147483647U);
          if ((mti & 1U) == 0U) {
            mti >>= 1U;
          } else {
            mti = mti >> 1U ^ 2567483615U;
          }

          MPC_DW.state_c[kk + 227] = MPC_DW.state_c[kk] ^ mti;
        }

        mti = (MPC_DW.state_c[623] & 2147483648U) | (MPC_DW.state_c[0] &
          2147483647U);
        if ((mti & 1U) == 0U) {
          mti >>= 1U;
        } else {
          mti = mti >> 1U ^ 2567483615U;
        }

        MPC_DW.state_c[623] = MPC_DW.state_c[396] ^ mti;
        mti = 1U;
      }

      y = MPC_DW.state_c[static_cast<int32_T>(mti) - 1];
      MPC_DW.state_c[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      b_u[k] = y >> 18U ^ y;
    }

    mti = b_u[0] >> 5U;
    y = b_u[1] >> 6U;
    if ((mti == 0U) && (y == 0U)) {
      boolean_T b_isvalid;
      b_isvalid = ((MPC_DW.state_c[624] >= 1U) && (MPC_DW.state_c[624] < 625U));
      if (b_isvalid) {
        boolean_T exitg2;
        b_isvalid = false;
        k = 1;
        exitg2 = false;
        while ((!exitg2) && (k < 625)) {
          if (MPC_DW.state_c[k - 1] == 0U) {
            k++;
          } else {
            b_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!b_isvalid) {
        MPC_DW.state_c[0] = 5489U;
        MPC_DW.state_c[624] = 624U;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return (static_cast<real_T>(mti) * 6.7108864E+7 + static_cast<real_T>(y)) *
    1.1102230246251565E-16;
}

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static real_T MPC_det(const real_T x[9])
{
  real_T A[9];
  real_T y;
  int8_T ipiv[3];
  boolean_T isodd;
  memcpy(&A[0], &x[0], 9U * sizeof(real_T));
  ipiv[0] = 1;
  ipiv[1] = 2;
  for (int32_T j = 0; j < 2; j++) {
    real_T smax;
    int32_T a;
    int32_T jA;
    int32_T jj;
    jj = j << 2;
    jA = 2 - j;
    a = 0;
    smax = fabs(A[jj]);
    for (int32_T c_k = 2; c_k <= jA + 1; c_k++) {
      real_T s;
      s = fabs(A[(jj + c_k) - 1]);
      if (s > smax) {
        a = c_k - 1;
        smax = s;
      }
    }

    if (A[jj + a] != 0.0) {
      if (a != 0) {
        jA = j + a;
        ipiv[j] = static_cast<int8_T>(jA + 1);
        smax = A[j];
        A[j] = A[jA];
        A[jA] = smax;
        smax = A[j + 3];
        A[j + 3] = A[jA + 3];
        A[jA + 3] = smax;
        smax = A[j + 6];
        A[j + 6] = A[jA + 6];
        A[jA + 6] = smax;
      }

      jA = (jj - j) + 3;
      for (a = jj + 2; a <= jA; a++) {
        A[a - 1] /= A[jj];
      }
    }

    jA = jj + 5;
    a = 1 - j;
    for (int32_T c_k = 0; c_k <= a; c_k++) {
      smax = A[(c_k * 3 + jj) + 3];
      if (smax != 0.0) {
        int32_T d;
        d = (jA - j) + 1;
        for (int32_T ijA = jA; ijA <= d; ijA++) {
          A[ijA - 1] += A[((jj + ijA) - jA) + 1] * -smax;
        }
      }

      jA += 3;
    }
  }

  isodd = (ipiv[0] > 1);
  y = A[0] * A[4] * A[8];
  if (ipiv[1] > 2) {
    isodd = !isodd;
  }

  if (isodd) {
    y = -y;
  }

  return y;
}

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static boolean_T MPC_hasFiniteBounds(boolean_T hasLB[6], boolean_T hasUB[6])
{
  boolean_T hasBounds;
  hasLB[0] = true;
  hasUB[0] = false;
  hasBounds = true;
  for (int32_T idx = 1; idx < 6; idx++) {
    hasLB[idx] = true;
    hasUB[idx] = false;
  }

  return hasBounds;
}

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static void MPC_corrP4Q_anonFcn1(const real_T P_k[144], const real_T H[72],
  const real_T b_R[36], const real_T V[36], const real_T x[6], real_T
  varargout_1[36])
{
  real_T Lambda[144];
  real_T Lambda_0[144];
  real_T Lambda_1[144];
  real_T H_0[72];
  real_T a[36];
  real_T b_x[36];
  real_T varargin_1[9];
  real_T varargin_2[9];
  real_T varargin_3[9];
  real_T varargin_4[9];
  real_T Lambda_2;
  int32_T ipiv[6];
  int32_T Lambda_tmp;
  int32_T Lambda_tmp_0;
  int32_T b_i;
  int32_T info;
  int32_T jBcol;
  int32_T kAcol;
  int32_T pipk;
  int8_T p[6];
  static const int8_T Izz[36] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

  memset(&varargin_1[0], 0, 9U * sizeof(real_T));
  varargin_1[0] = x[0];
  varargin_1[4] = x[1];
  varargin_1[8] = x[2];
  memset(&varargin_2[0], 0, 9U * sizeof(real_T));
  varargin_2[0] = x[0];
  varargin_2[4] = x[1];
  varargin_2[8] = x[2];
  memset(&varargin_3[0], 0, 9U * sizeof(real_T));
  varargin_3[0] = x[3];
  varargin_3[4] = x[4];
  varargin_3[8] = x[5];
  memset(&varargin_4[0], 0, 9U * sizeof(real_T));
  varargin_4[0] = x[3];
  varargin_4[4] = x[4];
  varargin_4[8] = x[5];
  memset(&Lambda[0], 0, 144U * sizeof(real_T));
  for (info = 0; info < 3; info++) {
    Lambda[12 * info] = varargin_1[3 * info];
    Lambda_tmp_0 = (info + 3) * 12;
    Lambda[Lambda_tmp_0 + 3] = varargin_2[3 * info];
    pipk = (info + 6) * 12;
    Lambda[pipk + 6] = varargin_3[3 * info];
    jBcol = (info + 9) * 12;
    Lambda[jBcol + 9] = varargin_4[3 * info];
    Lambda_tmp = 3 * info + 1;
    Lambda[12 * info + 1] = varargin_1[Lambda_tmp];
    Lambda[Lambda_tmp_0 + 4] = varargin_2[Lambda_tmp];
    Lambda[pipk + 7] = varargin_3[Lambda_tmp];
    Lambda[jBcol + 10] = varargin_4[Lambda_tmp];
    Lambda_tmp = 3 * info + 2;
    Lambda[12 * info + 2] = varargin_1[Lambda_tmp];
    Lambda[Lambda_tmp_0 + 5] = varargin_2[Lambda_tmp];
    Lambda[pipk + 8] = varargin_3[Lambda_tmp];
    Lambda[jBcol + 11] = varargin_4[Lambda_tmp];
  }

  memset(&a[0], 0, 36U * sizeof(real_T));
  for (info = 0; info < 12; info++) {
    for (Lambda_tmp_0 = 0; Lambda_tmp_0 < 12; Lambda_tmp_0++) {
      Lambda_2 = 0.0;
      for (pipk = 0; pipk < 12; pipk++) {
        Lambda_2 += Lambda[12 * pipk + info] * P_k[12 * Lambda_tmp_0 + pipk];
      }

      Lambda_0[info + 12 * Lambda_tmp_0] = Lambda_2;
    }

    for (Lambda_tmp_0 = 0; Lambda_tmp_0 < 12; Lambda_tmp_0++) {
      Lambda_2 = 0.0;
      for (pipk = 0; pipk < 12; pipk++) {
        Lambda_2 += Lambda_0[12 * pipk + info] * Lambda[12 * Lambda_tmp_0 + pipk];
      }

      Lambda_1[info + 12 * Lambda_tmp_0] = Lambda_2;
    }
  }

  for (info = 0; info < 6; info++) {
    for (Lambda_tmp_0 = 0; Lambda_tmp_0 < 12; Lambda_tmp_0++) {
      Lambda_2 = 0.0;
      for (pipk = 0; pipk < 12; pipk++) {
        Lambda_2 += H[6 * pipk + info] * Lambda_1[12 * Lambda_tmp_0 + pipk];
      }

      H_0[info + 6 * Lambda_tmp_0] = Lambda_2;
    }

    for (Lambda_tmp_0 = 0; Lambda_tmp_0 < 6; Lambda_tmp_0++) {
      Lambda_2 = 0.0;
      for (pipk = 0; pipk < 12; pipk++) {
        Lambda_2 += H_0[6 * pipk + info] * H[6 * pipk + Lambda_tmp_0];
      }

      pipk = 6 * Lambda_tmp_0 + info;
      b_x[pipk] = b_R[pipk] + Lambda_2;
    }
  }

  MPC_xgetrf(b_x, ipiv, &info);
  for (info = 0; info < 6; info++) {
    p[info] = static_cast<int8_T>(info + 1);
  }

  for (info = 0; info < 5; info++) {
    Lambda_tmp_0 = ipiv[info];
    if (Lambda_tmp_0 > info + 1) {
      pipk = p[Lambda_tmp_0 - 1];
      p[Lambda_tmp_0 - 1] = p[info];
      p[info] = static_cast<int8_T>(pipk);
    }
  }

  for (pipk = 0; pipk < 6; pipk++) {
    Lambda_tmp_0 = (p[pipk] - 1) * 6;
    a[pipk + Lambda_tmp_0] = 1.0;
    for (jBcol = pipk + 1; jBcol < 7; jBcol++) {
      info = (Lambda_tmp_0 + jBcol) - 1;
      if (a[info] != 0.0) {
        for (Lambda_tmp = jBcol + 1; Lambda_tmp < 7; Lambda_tmp++) {
          kAcol = (Lambda_tmp_0 + Lambda_tmp) - 1;
          a[kAcol] -= b_x[((jBcol - 1) * 6 + Lambda_tmp) - 1] * a[info];
        }
      }
    }
  }

  for (pipk = 0; pipk < 6; pipk++) {
    jBcol = 6 * pipk;
    for (Lambda_tmp = 5; Lambda_tmp >= 0; Lambda_tmp--) {
      kAcol = 6 * Lambda_tmp;
      info = Lambda_tmp + jBcol;
      Lambda_2 = a[info];
      if (Lambda_2 != 0.0) {
        a[info] = Lambda_2 / b_x[Lambda_tmp + kAcol];
        for (b_i = 0; b_i < Lambda_tmp; b_i++) {
          Lambda_tmp_0 = b_i + jBcol;
          a[Lambda_tmp_0] -= b_x[b_i + kAcol] * a[info];
        }
      }
    }
  }

  for (info = 0; info < 6; info++) {
    for (Lambda_tmp_0 = 0; Lambda_tmp_0 < 6; Lambda_tmp_0++) {
      Lambda_2 = 0.0;
      for (pipk = 0; pipk < 6; pipk++) {
        Lambda_2 += a[6 * pipk + info] * V[6 * Lambda_tmp_0 + pipk];
      }

      pipk = 6 * Lambda_tmp_0 + info;
      varargout_1[pipk] = static_cast<real_T>(Izz[pipk]) - Lambda_2;
    }
  }
}

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static void MPC_finDiffEvalAndChkErr(const real_T
  obj_nonlin_workspace_fun_worksp[144], const real_T
  obj_nonlin_workspace_fun_work_0[72], const real_T
  obj_nonlin_workspace_fun_work_1[36], int32_T dim, real_T delta, real_T xk[6],
  boolean_T *evalOK, real_T *fplus, real_T cEqPlus[36])
{
  real_T temp_tmp;
  int32_T idx;
  static const real_T b[36] = { 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001 };

  *fplus = 0.0;
  *evalOK = true;
  temp_tmp = xk[dim - 1];
  xk[dim - 1] = temp_tmp + delta;
  MPC_corrP4Q_anonFcn1(obj_nonlin_workspace_fun_worksp,
                       obj_nonlin_workspace_fun_work_0, b,
                       obj_nonlin_workspace_fun_work_1, xk, cEqPlus);
  idx = 0;
  while ((*evalOK) && (idx + 1 <= 36)) {
    *evalOK = ((!rtIsInf(cEqPlus[idx])) && (!rtIsNaN(cEqPlus[idx])));
    idx++;
  }

  xk[dim - 1] = temp_tmp;
}

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static boolean_T MPC_computeFiniteDifferences(s_B0kB2CQLsoRkj8KoaXWXYC_MPC_T
  *obj, const real_T cEqCurrent[36], real_T xk[6], real_T JacCeqTrans[216])
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
  while ((!exitg1) && (idx < 6)) {
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
    MPC_finDiffEvalAndChkErr(obj->nonlin.workspace.fun.workspace.P_k,
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
          MPC_finDiffEvalAndChkErr(obj->nonlin.workspace.fun.workspace.P_k,
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
        JacCeqTrans[idx + 6 * idx_row] = (obj->cEq_1[idx_row] -
          cEqCurrent[idx_row]) / deltaX;
      }

      idx++;
    }
  }

  return evalOK;
}

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static real_T MPC_computeFirstOrderOpt(const real_T gradf[6], boolean_T
  hasFiniteBounds, const real_T *projSteepestDescentInfNorm)
{
  real_T firstOrderOpt;
  if (hasFiniteBounds) {
    real_T absx;
    real_T b_absx;
    absx = 0.0;
    for (int32_T k = 0; k < 6; k++) {
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
    for (int32_T k = 0; k < 6; k++) {
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

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static real_T MPC_norm_izm(const real_T x[6])
{
  real_T scale;
  real_T y;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (int32_T k = 0; k < 6; k++) {
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

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static int32_T MPC_checkStoppingCriteria(const real_T gradf[6], real_T relFactor,
  const real_T x[6], int32_T funcCount, real_T projSteepestDescentInfNorm,
  boolean_T hasFiniteBounds)
{
  real_T tmp[6];
  real_T absx;
  real_T normGradF;
  int32_T exitflag;
  int32_T k;
  normGradF = 0.0;
  for (k = 0; k < 6; k++) {
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
  } else if (funcCount >= 1200) {
    exitflag = 0;
  } else {
    for (k = 0; k < 6; k++) {
      tmp[k] = (rtInf);
    }

    if (MPC_norm_izm(tmp) < (MPC_norm_izm(x) + 1.4901161193847656E-8) * 1.0E-6)
    {
      exitflag = 4;
    } else {
      exitflag = -5;
    }
  }

  return exitflag;
}

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static real_T MPC_xnrm2_gy(int32_T n, const real_T x[252], int32_T ix0)
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

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static real_T MPC_xzlarfg(int32_T n, real_T *alpha1, real_T x[252], int32_T ix0)
{
  real_T a;
  real_T tau;
  real_T xnorm;
  int32_T c;
  int32_T d_tmp;
  int32_T knt;
  tau = 0.0;
  xnorm = MPC_xnrm2_gy(n - 1, x, ix0);
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

      xnorm = rt_hypotd_snf(*alpha1, MPC_xnrm2_gy(n - 1, x, ix0));
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

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static void MPC_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T C
  [252], int32_T ic0, real_T work[6])
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
      coltop = (lastc - 1) * 42 + ic0;
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
      d = (lastc - 1) * 42 + ic0;
      for (coltop = ic0; coltop <= d; coltop += 42) {
        c = 0.0;
        e = (coltop + lastv) - 1;
        for (jA = coltop; jA <= e; jA++) {
          c += C[((iv0 + jA) - coltop) - 1] * C[jA - 1];
        }

        jA = div_nde_s32_floor(coltop - ic0, 42);
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

        jA += 42;
      }
    }
  }
}

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static void MPC_linearLeastSquares(real_T lhs[252], real_T rhs[42], real_T dx[6])
{
  real_T jpvt[6];
  real_T tau[6];
  real_T vn1[6];
  real_T vn2[6];
  real_T work[6];
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
  for (i = 0; i < 6; i++) {
    jpvt[i] = 0.0;
  }

  nfxd = 0;
  for (r = 0; r < 6; r++) {
    if (jpvt[r] != 0.0) {
      nfxd++;
      if (r + 1 != nfxd) {
        b_ix = r * 42;
        iy = (nfxd - 1) * 42;
        for (ii = 0; ii < 42; ii++) {
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
    ii = i * 42 + i;
    s = lhs[ii];
    temp = MPC_xzlarfg(42 - i, &s, lhs, ii + 2);
    tau[i] = temp;
    lhs[ii] = s;
    if (i + 1 < 6) {
      lhs[ii] = 1.0;
      MPC_xzlarf(42 - i, 5 - i, ii + 1, temp, lhs, ii + 43, work);
      lhs[ii] = s;
    }
  }

  if (nfxd < 6) {
    for (i = 0; i < 6; i++) {
      work[i] = 0.0;
      vn1[i] = 0.0;
      vn2[i] = 0.0;
    }

    for (i = nfxd + 1; i < 7; i++) {
      temp = MPC_xnrm2_gy(42 - nfxd, lhs, ((i - 1) * 42 + nfxd) + 1);
      vn1[i - 1] = temp;
      vn2[i - 1] = temp;
    }

    for (r = nfxd + 1; r < 7; r++) {
      ii = (r - 1) * 42;
      b_ix = (ii + r) - 1;
      iy = 7 - r;
      pvt = -1;
      if (7 - r > 1) {
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
        d_ix = pvt * 42;
        for (iy = 0; iy < 42; iy++) {
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
      temp = MPC_xzlarfg(43 - r, &s, lhs, b_ix + 2);
      tau[r - 1] = temp;
      lhs[b_ix] = s;
      if (r < 6) {
        lhs[b_ix] = 1.0;
        MPC_xzlarf(43 - r, 6 - r, b_ix + 1, temp, lhs, b_ix + 43, work);
        lhs[b_ix] = s;
      }

      for (i = r + 1; i < 7; i++) {
        ii = (i - 1) * 42 + r;
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
            temp = MPC_xnrm2_gy(42 - r, lhs, ii + 1);
            vn1[i - 1] = temp;
            vn2[i - 1] = temp;
          } else {
            vn1[i - 1] = temp * sqrt(s);
          }
        }
      }
    }
  }

  for (nfxd = 0; nfxd < 6; nfxd++) {
    if (tau[nfxd] != 0.0) {
      temp = rhs[nfxd];
      for (i = nfxd + 2; i < 43; i++) {
        temp += lhs[(42 * nfxd + i) - 1] * rhs[i - 1];
      }

      temp *= tau[nfxd];
      if (temp != 0.0) {
        rhs[nfxd] -= temp;
        for (i = nfxd + 2; i < 43; i++) {
          rhs[i - 1] -= lhs[(42 * nfxd + i) - 1] * temp;
        }
      }
    }
  }

  r = 0;
  temp = 9.3258734068513149E-14 * fabs(lhs[0]);
  while ((r < 6) && (!(fabs(lhs[42 * r + r]) <= temp))) {
    r++;
  }

  for (i = 0; i < 6; i++) {
    dx[i] = rhs[i];
  }

  if (r != 0) {
    for (nfxd = r; nfxd >= 1; nfxd--) {
      ii = ((nfxd - 1) * 42 + nfxd) - 2;
      dx[nfxd - 1] /= lhs[ii + 1];
      for (i = 0; i <= nfxd - 2; i++) {
        b_ix = (nfxd - i) - 2;
        dx[b_ix] -= dx[nfxd - 1] * lhs[ii - i];
      }
    }
  }

  for (i = r + 1; i < 7; i++) {
    dx[i - 1] = 0.0;
  }

  for (i = 0; i < 6; i++) {
    tau[i] = dx[i];
  }

  for (i = 0; i < 6; i++) {
    dx[static_cast<int32_T>(jpvt[i]) - 1] = tau[i];
  }
}

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static int32_T MPC_checkStoppingCriteria_o(const real_T gradf[6], real_T
  relFactor, real_T funDiff, const real_T x[6], const real_T dx[6], int32_T
  funcCount, boolean_T stepSuccessful, int32_T *iter, real_T
  projSteepestDescentInfNorm, boolean_T hasFiniteBounds)
{
  real_T absx;
  real_T normGradF;
  int32_T exitflag;
  int32_T k;
  normGradF = 0.0;
  for (k = 0; k < 6; k++) {
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
  } else if (funcCount >= 1200) {
    exitflag = 0;
  } else if (*iter >= 400) {
    exitflag = 0;
  } else if (MPC_norm_izm(dx) < (MPC_norm_izm(x) + 1.4901161193847656E-8) *
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

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static void MPC_lsqnonlin(const real_T fun_workspace_P_k[144], const real_T
  fun_workspace_H[72], const real_T fun_workspace_V[36], real_T xCurrent[6])
{
  s_B0kB2CQLsoRkj8KoaXWXYC_MPC_T FiniteDifferences;
  real_T augJacobian[252];
  real_T JacCeqTrans[216];
  real_T rhs[42];
  real_T fNew[36];
  real_T f_temp[36];
  real_T fval[36];
  real_T a__3[6];
  real_T dx[6];
  real_T gradf[6];
  real_T b_gamma;
  real_T c;
  real_T funDiff;
  real_T projSteepestDescentInfNorm;
  real_T resnorm;
  real_T resnormNew;
  real_T u0;
  int32_T aIdx;
  int32_T bIdx;
  int32_T funcCount;
  int32_T i;
  int32_T iter;
  boolean_T hasLB[6];
  boolean_T hasUB[6];
  boolean_T indActive[6];
  boolean_T hasFiniteBounds;
  boolean_T indActive_0;
  boolean_T stepSuccessful;
  static const real_T b[36] = { 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001 };

  boolean_T exitg1;
  boolean_T guard1;
  for (i = 0; i < 6; i++) {
    indActive[i] = false;
  }

  funDiff = (rtInf);
  iter = 0;
  hasFiniteBounds = MPC_hasFiniteBounds(hasLB, hasUB);
  if (!hasFiniteBounds) {
    for (i = 0; i < 6; i++) {
      xCurrent[i] = 1.0;
    }
  } else {
    for (funcCount = 0; funcCount < 6; funcCount++) {
      xCurrent[funcCount] = 1.0;
    }
  }

  MPC_corrP4Q_anonFcn1(fun_workspace_P_k, fun_workspace_H, b, fun_workspace_V,
                       xCurrent, f_temp);
  resnorm = 0.0;
  for (i = 0; i < 36; i++) {
    b_gamma = f_temp[i];
    fval[i] = b_gamma;
    resnorm += b_gamma * b_gamma;
  }

  memcpy(&FiniteDifferences.nonlin.workspace.fun.workspace.P_k[0],
         &fun_workspace_P_k[0], 144U * sizeof(real_T));
  memcpy(&FiniteDifferences.nonlin.workspace.fun.workspace.H[0],
         &fun_workspace_H[0], 72U * sizeof(real_T));
  memcpy(&FiniteDifferences.nonlin.workspace.fun.workspace.V[0],
         &fun_workspace_V[0], 36U * sizeof(real_T));
  FiniteDifferences.numEvals = 0;
  FiniteDifferences.hasBounds = MPC_hasFiniteBounds(FiniteDifferences.hasLB,
    FiniteDifferences.hasUB);
  for (i = 0; i < 6; i++) {
    a__3[i] = 1.0;
  }

  MPC_computeFiniteDifferences(&FiniteDifferences, fval, a__3, JacCeqTrans);
  for (i = 0; i < 6; i++) {
    for (aIdx = 0; aIdx < 36; aIdx++) {
      augJacobian[aIdx + 42 * i] = JacCeqTrans[6 * aIdx + i];
    }
  }

  funcCount = FiniteDifferences.numEvals + 1;
  for (i = 0; i < 6; i++) {
    memcpy(&JacCeqTrans[i * 36], &augJacobian[i * 42], 36U * sizeof(real_T));
  }

  b_gamma = 0.01;
  for (i = 0; i < 6; i++) {
    aIdx = (i + 1) * 42;
    for (bIdx = 0; bIdx < 6; bIdx++) {
      augJacobian[(aIdx + bIdx) - 6] = 0.0;
    }

    augJacobian[(i + 42 * i) + 36] = 0.1;
    gradf[i] = 0.0;
  }

  for (i = 0; i <= 180; i += 36) {
    c = 0.0;
    for (aIdx = i + 1; aIdx <= i + 36; aIdx++) {
      c += fval[(aIdx - i) - 1] * JacCeqTrans[aIdx - 1];
    }

    aIdx = div_nde_s32_floor(i, 36);
    gradf[aIdx] += c;
  }

  projSteepestDescentInfNorm = 0.0;
  for (i = 0; i < 6; i++) {
    resnormNew = -gradf[i];
    if ((resnormNew <= 0.0) || rtIsNaN(resnormNew)) {
      resnormNew = 0.0;
    }

    if (!(projSteepestDescentInfNorm >= resnormNew)) {
      projSteepestDescentInfNorm = resnormNew;
    }
  }

  c = MPC_computeFirstOrderOpt(gradf, hasFiniteBounds,
    &projSteepestDescentInfNorm);
  if (!(c >= 1.0)) {
    c = 1.0;
  }

  stepSuccessful = true;
  i = MPC_checkStoppingCriteria(gradf, c, xCurrent, FiniteDifferences.numEvals +
    1, projSteepestDescentInfNorm, hasFiniteBounds);
  exitg1 = false;
  while ((!exitg1) && (i == -5)) {
    for (i = 0; i < 36; i++) {
      rhs[i] = -fval[i];
    }

    for (i = 0; i < 6; i++) {
      rhs[i + 36] = 0.0;
    }

    if (hasFiniteBounds) {
      projSteepestDescentInfNorm = 0.0;
      for (i = 0; i < 6; i++) {
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

      for (i = 0; i < 6; i++) {
        if (xCurrent[i] - 1.0 <= projSteepestDescentInfNorm) {
          indActive_0 = (gradf[i] > 0.0);
          indActive[i] = indActive_0;
        } else {
          indActive_0 = false;
          indActive[i] = false;
        }

        if (indActive_0) {
          memset(&augJacobian[42 * i], 0, 36U * sizeof(real_T));
        }
      }
    }

    MPC_linearLeastSquares(augJacobian, rhs, dx);
    for (i = 0; i < 6; i++) {
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

    MPC_corrP4Q_anonFcn1(fun_workspace_P_k, fun_workspace_H, b, fun_workspace_V,
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
      for (i = 0; i < 6; i++) {
        a__3[i] = gradf[i];
      }

      indActive_0 = MPC_computeFiniteDifferences(&FiniteDifferences, fNew, a__3,
        JacCeqTrans);
      funcCount += FiniteDifferences.numEvals;
      for (i = 0; i < 6; i++) {
        for (aIdx = 0; aIdx < 36; aIdx++) {
          augJacobian[aIdx + 42 * i] = JacCeqTrans[6 * aIdx + i];
        }
      }

      memcpy(&fval[0], &fNew[0], 36U * sizeof(real_T));
      for (i = 0; i < 6; i++) {
        memcpy(&JacCeqTrans[i * 36], &augJacobian[i * 42], 36U * sizeof(real_T));
      }

      if (indActive_0) {
        for (i = 0; i < 6; i++) {
          xCurrent[i] = gradf[i];
        }

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
      for (i = 0; i < 6; i++) {
        memcpy(&augJacobian[i * 42], &JacCeqTrans[i * 36], 36U * sizeof(real_T));
      }

      guard1 = true;
    }

    if (guard1) {
      resnormNew = sqrt(b_gamma);
      for (i = 0; i < 6; i++) {
        aIdx = (i + 1) * 42;
        for (bIdx = 0; bIdx < 6; bIdx++) {
          augJacobian[(aIdx + bIdx) - 6] = 0.0;
        }

        augJacobian[(i + 42 * i) + 36] = resnormNew;
        gradf[i] = 0.0;
      }

      for (i = 0; i <= 180; i += 36) {
        resnormNew = 0.0;
        for (aIdx = i + 1; aIdx <= i + 36; aIdx++) {
          resnormNew += fval[(aIdx - i) - 1] * JacCeqTrans[aIdx - 1];
        }

        aIdx = div_nde_s32_floor(i, 36);
        gradf[aIdx] += resnormNew;
      }

      projSteepestDescentInfNorm = 0.0;
      for (i = 0; i < 6; i++) {
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

      i = MPC_checkStoppingCriteria_o(gradf, c, funDiff, xCurrent, dx, funcCount,
        stepSuccessful, &iter, projSteepestDescentInfNorm, hasFiniteBounds);
      if (i != -5) {
        exitg1 = true;
      }
    }
  }
}

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static void MPC_timeKeeper_aw(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_a, real_T
  *outTime_tv_sec, real_T *outTime_tv_nsec)
{
  coderTimespec origTimespec;
  if (!MPC_DW.savedTime_not_empty_m) {
    if (!MPC_DW.freq_not_empty_a) {
      MPC_DW.freq_not_empty_a = true;
      coderInitTimeFunctions(&MPC_DW.freq_c);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, MPC_DW.freq_c);
    savedTime_a->tv_sec = origTimespec.tv_sec;
    savedTime_a->tv_nsec = origTimespec.tv_nsec;
  }

  *outTime_tv_sec = savedTime_a->tv_sec;
  *outTime_tv_nsec = savedTime_a->tv_nsec;
}

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static real_T MPC_toc_h(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_a)
{
  coderTimespec origTimespec;
  real_T t;
  real_T tstart_tv_nsec;
  real_T tstart_tv_sec;
  MPC_timeKeeper_aw(savedTime_a, &tstart_tv_sec, &tstart_tv_nsec);
  if (!MPC_DW.freq_not_empty_a) {
    MPC_DW.freq_not_empty_a = true;
    coderInitTimeFunctions(&MPC_DW.freq_c);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, MPC_DW.freq_c);
  t = (origTimespec.tv_nsec - tstart_tv_nsec) / 1.0E+9 + (origTimespec.tv_sec -
    tstart_tv_sec);
  return t;
}

// Function for MATLAB Function: '<S101>/MATLAB Function1'
static void MPC_mrdiv_dtsy(real_T A[6], const real_T B[36])
{
  real_T b_A[36];
  real_T temp;
  int32_T ipiv[6];
  int32_T info;
  int32_T jAcol;
  int32_T k;
  memcpy(&b_A[0], &B[0], 36U * sizeof(real_T));
  MPC_xgetrf(b_A, ipiv, &info);
  for (info = 0; info < 6; info++) {
    jAcol = 6 * info;
    for (k = 0; k < info; k++) {
      temp = b_A[k + jAcol];
      if (temp != 0.0) {
        A[info] -= temp * A[k];
      }
    }

    A[info] *= 1.0 / b_A[info + jAcol];
  }

  for (info = 5; info >= 0; info--) {
    jAcol = 6 * info - 1;
    for (k = info + 2; k < 7; k++) {
      temp = b_A[k + jAcol];
      if (temp != 0.0) {
        A[info] -= A[k - 1] * temp;
      }
    }
  }

  for (info = 4; info >= 0; info--) {
    k = ipiv[info];
    if (info + 1 != k) {
      temp = A[info];
      A[info] = A[k - 1];
      A[k - 1] = temp;
    }
  }
}

// Function for MATLAB Function: '<S102>/MATLAB Function1'
static void MPC_timeKeeper_g(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_aw)
{
  coderTimespec origTimespec;
  if (!MPC_DW.savedTime_not_empty) {
    if (!MPC_DW.freq_not_empty) {
      MPC_DW.freq_not_empty = true;
      coderInitTimeFunctions(&MPC_DW.freq);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, MPC_DW.freq);
    MPC_DW.savedTime_not_empty = true;
  }

  savedTime_aw->tv_sec = newTime_tv_sec;
  savedTime_aw->tv_nsec = newTime_tv_nsec;
}

// Function for MATLAB Function: '<S102>/MATLAB Function1'
static void MPC_tic_p(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_aw)
{
  coderTimespec origTimespec;
  if (!MPC_DW.freq_not_empty) {
    MPC_DW.freq_not_empty = true;
    coderInitTimeFunctions(&MPC_DW.freq);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, MPC_DW.freq);
  MPC_timeKeeper_g(origTimespec.tv_sec, origTimespec.tv_nsec, savedTime_aw);
}

// Function for MATLAB Function: '<S102>/MATLAB Function1'
static real_T MPC_rand_pn(void)
{
  uint32_T b_u[2];
  uint32_T mti;
  uint32_T y;

  // ========================= COPYRIGHT NOTICE ============================
  //  This is a uniform (0,1) pseudorandom number generator based on:
  //
  //  A C-program for MT19937, with initialization improved 2002/1/26.
  //  Coded by Takuji Nishimura and Makoto Matsumoto.
  //
  //  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
  //  All rights reserved.
  //
  //  Redistribution and use in source and binary forms, with or without
  //  modification, are permitted provided that the following conditions
  //  are met:
  //
  //    1. Redistributions of source code must retain the above copyright
  //       notice, this list of conditions and the following disclaimer.
  //
  //    2. Redistributions in binary form must reproduce the above copyright
  //       notice, this list of conditions and the following disclaimer
  //       in the documentation and/or other materials provided with the
  //       distribution.
  //
  //    3. The names of its contributors may not be used to endorse or
  //       promote products derived from this software without specific
  //       prior written permission.
  //
  //  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  //  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  //  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  //  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT
  //  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  //  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  //  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  //  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  //  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  //  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  //  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  //
  // =============================   END   =================================
  int32_T exitg1;
  do {
    int32_T k;
    exitg1 = 0;
    for (k = 0; k < 2; k++) {
      mti = MPC_DW.state[624] + 1U;
      if (MPC_DW.state[624] + 1U >= 625U) {
        for (int32_T kk = 0; kk < 227; kk++) {
          mti = (MPC_DW.state[kk + 1] & 2147483647U) | (MPC_DW.state[kk] &
            2147483648U);
          if ((mti & 1U) == 0U) {
            mti >>= 1U;
          } else {
            mti = mti >> 1U ^ 2567483615U;
          }

          MPC_DW.state[kk] = MPC_DW.state[kk + 397] ^ mti;
        }

        for (int32_T kk = 0; kk < 396; kk++) {
          mti = (MPC_DW.state[kk + 227] & 2147483648U) | (MPC_DW.state[kk + 228]
            & 2147483647U);
          if ((mti & 1U) == 0U) {
            mti >>= 1U;
          } else {
            mti = mti >> 1U ^ 2567483615U;
          }

          MPC_DW.state[kk + 227] = MPC_DW.state[kk] ^ mti;
        }

        mti = (MPC_DW.state[623] & 2147483648U) | (MPC_DW.state[0] & 2147483647U);
        if ((mti & 1U) == 0U) {
          mti >>= 1U;
        } else {
          mti = mti >> 1U ^ 2567483615U;
        }

        MPC_DW.state[623] = MPC_DW.state[396] ^ mti;
        mti = 1U;
      }

      y = MPC_DW.state[static_cast<int32_T>(mti) - 1];
      MPC_DW.state[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      b_u[k] = y >> 18U ^ y;
    }

    mti = b_u[0] >> 5U;
    y = b_u[1] >> 6U;
    if ((mti == 0U) && (y == 0U)) {
      boolean_T b_isvalid;
      b_isvalid = ((MPC_DW.state[624] >= 1U) && (MPC_DW.state[624] < 625U));
      if (b_isvalid) {
        boolean_T exitg2;
        b_isvalid = false;
        k = 1;
        exitg2 = false;
        while ((!exitg2) && (k < 625)) {
          if (MPC_DW.state[k - 1] == 0U) {
            k++;
          } else {
            b_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!b_isvalid) {
        MPC_DW.state[0] = 5489U;
        MPC_DW.state[624] = 624U;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return (static_cast<real_T>(mti) * 6.7108864E+7 + static_cast<real_T>(y)) *
    1.1102230246251565E-16;
}

// Function for MATLAB Function: '<S102>/MATLAB Function1'
static void MPC_corrP4R_anonFcn1(const real_T P_k[144], const real_T H[72],
  const real_T b_R[36], const real_T V[36], const real_T x[6], real_T
  varargout_1[36])
{
  real_T Lambda[144];
  real_T Lambda_0[144];
  real_T Lambda_1[144];
  real_T H_0[72];
  real_T a[36];
  real_T b_x[36];
  real_T varargin_1[9];
  real_T varargin_2[9];
  real_T varargin_3[9];
  real_T varargin_4[9];
  real_T Lambda_2;
  int32_T ipiv[6];
  int32_T Lambda_tmp;
  int32_T Lambda_tmp_0;
  int32_T b_i;
  int32_T info;
  int32_T jBcol;
  int32_T kAcol;
  int32_T pipk;
  int8_T p[6];
  static const int8_T Izz[36] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

  memset(&varargin_1[0], 0, 9U * sizeof(real_T));
  varargin_1[0] = x[0];
  varargin_1[4] = x[1];
  varargin_1[8] = x[2];
  memset(&varargin_2[0], 0, 9U * sizeof(real_T));
  varargin_2[0] = x[3];
  varargin_2[4] = x[4];
  varargin_2[8] = x[5];
  memset(&varargin_3[0], 0, 9U * sizeof(real_T));
  varargin_3[0] = x[3];
  varargin_3[4] = x[4];
  varargin_3[8] = x[5];
  memset(&varargin_4[0], 0, 9U * sizeof(real_T));
  varargin_4[0] = x[0];
  varargin_4[4] = x[1];
  varargin_4[8] = x[2];
  memset(&Lambda[0], 0, 144U * sizeof(real_T));
  for (info = 0; info < 3; info++) {
    Lambda[12 * info] = varargin_1[3 * info];
    Lambda_tmp_0 = (info + 3) * 12;
    Lambda[Lambda_tmp_0 + 3] = varargin_2[3 * info];
    pipk = (info + 6) * 12;
    Lambda[pipk + 6] = varargin_3[3 * info];
    jBcol = (info + 9) * 12;
    Lambda[jBcol + 9] = varargin_4[3 * info];
    Lambda_tmp = 3 * info + 1;
    Lambda[12 * info + 1] = varargin_1[Lambda_tmp];
    Lambda[Lambda_tmp_0 + 4] = varargin_2[Lambda_tmp];
    Lambda[pipk + 7] = varargin_3[Lambda_tmp];
    Lambda[jBcol + 10] = varargin_4[Lambda_tmp];
    Lambda_tmp = 3 * info + 2;
    Lambda[12 * info + 2] = varargin_1[Lambda_tmp];
    Lambda[Lambda_tmp_0 + 5] = varargin_2[Lambda_tmp];
    Lambda[pipk + 8] = varargin_3[Lambda_tmp];
    Lambda[jBcol + 11] = varargin_4[Lambda_tmp];
  }

  memset(&a[0], 0, 36U * sizeof(real_T));
  for (info = 0; info < 12; info++) {
    for (Lambda_tmp_0 = 0; Lambda_tmp_0 < 12; Lambda_tmp_0++) {
      Lambda_2 = 0.0;
      for (pipk = 0; pipk < 12; pipk++) {
        Lambda_2 += Lambda[12 * pipk + info] * P_k[12 * Lambda_tmp_0 + pipk];
      }

      Lambda_0[info + 12 * Lambda_tmp_0] = Lambda_2;
    }

    for (Lambda_tmp_0 = 0; Lambda_tmp_0 < 12; Lambda_tmp_0++) {
      Lambda_2 = 0.0;
      for (pipk = 0; pipk < 12; pipk++) {
        Lambda_2 += Lambda_0[12 * pipk + info] * Lambda[12 * Lambda_tmp_0 + pipk];
      }

      Lambda_1[info + 12 * Lambda_tmp_0] = Lambda_2;
    }
  }

  for (info = 0; info < 6; info++) {
    for (Lambda_tmp_0 = 0; Lambda_tmp_0 < 12; Lambda_tmp_0++) {
      Lambda_2 = 0.0;
      for (pipk = 0; pipk < 12; pipk++) {
        Lambda_2 += H[6 * pipk + info] * Lambda_1[12 * Lambda_tmp_0 + pipk];
      }

      H_0[info + 6 * Lambda_tmp_0] = Lambda_2;
    }

    for (Lambda_tmp_0 = 0; Lambda_tmp_0 < 6; Lambda_tmp_0++) {
      Lambda_2 = 0.0;
      for (pipk = 0; pipk < 12; pipk++) {
        Lambda_2 += H_0[6 * pipk + info] * H[6 * pipk + Lambda_tmp_0];
      }

      pipk = 6 * Lambda_tmp_0 + info;
      b_x[pipk] = b_R[pipk] + Lambda_2;
    }
  }

  MPC_xgetrf(b_x, ipiv, &info);
  for (info = 0; info < 6; info++) {
    p[info] = static_cast<int8_T>(info + 1);
  }

  for (info = 0; info < 5; info++) {
    Lambda_tmp_0 = ipiv[info];
    if (Lambda_tmp_0 > info + 1) {
      pipk = p[Lambda_tmp_0 - 1];
      p[Lambda_tmp_0 - 1] = p[info];
      p[info] = static_cast<int8_T>(pipk);
    }
  }

  for (pipk = 0; pipk < 6; pipk++) {
    Lambda_tmp_0 = (p[pipk] - 1) * 6;
    a[pipk + Lambda_tmp_0] = 1.0;
    for (jBcol = pipk + 1; jBcol < 7; jBcol++) {
      info = (Lambda_tmp_0 + jBcol) - 1;
      if (a[info] != 0.0) {
        for (Lambda_tmp = jBcol + 1; Lambda_tmp < 7; Lambda_tmp++) {
          kAcol = (Lambda_tmp_0 + Lambda_tmp) - 1;
          a[kAcol] -= b_x[((jBcol - 1) * 6 + Lambda_tmp) - 1] * a[info];
        }
      }
    }
  }

  for (pipk = 0; pipk < 6; pipk++) {
    jBcol = 6 * pipk;
    for (Lambda_tmp = 5; Lambda_tmp >= 0; Lambda_tmp--) {
      kAcol = 6 * Lambda_tmp;
      info = Lambda_tmp + jBcol;
      Lambda_2 = a[info];
      if (Lambda_2 != 0.0) {
        a[info] = Lambda_2 / b_x[Lambda_tmp + kAcol];
        for (b_i = 0; b_i < Lambda_tmp; b_i++) {
          Lambda_tmp_0 = b_i + jBcol;
          a[Lambda_tmp_0] -= b_x[b_i + kAcol] * a[info];
        }
      }
    }
  }

  for (info = 0; info < 6; info++) {
    for (Lambda_tmp_0 = 0; Lambda_tmp_0 < 6; Lambda_tmp_0++) {
      Lambda_2 = 0.0;
      for (pipk = 0; pipk < 6; pipk++) {
        Lambda_2 += a[6 * pipk + info] * V[6 * Lambda_tmp_0 + pipk];
      }

      pipk = 6 * Lambda_tmp_0 + info;
      varargout_1[pipk] = static_cast<real_T>(Izz[pipk]) - Lambda_2;
    }
  }
}

// Function for MATLAB Function: '<S102>/MATLAB Function1'
static void MPC_finDiffEvalAndChkErr_a(const real_T
  obj_nonlin_workspace_fun_worksp[144], const real_T
  obj_nonlin_workspace_fun_work_0[72], const real_T
  obj_nonlin_workspace_fun_work_1[36], int32_T dim, real_T delta, real_T xk[6],
  boolean_T *evalOK, real_T *fplus, real_T cEqPlus[36])
{
  real_T temp_tmp;
  int32_T idx;
  static const real_T b[36] = { 0.006, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.006, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.006, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001 };

  *fplus = 0.0;
  *evalOK = true;
  temp_tmp = xk[dim - 1];
  xk[dim - 1] = temp_tmp + delta;
  MPC_corrP4R_anonFcn1(obj_nonlin_workspace_fun_worksp,
                       obj_nonlin_workspace_fun_work_0, b,
                       obj_nonlin_workspace_fun_work_1, xk, cEqPlus);
  idx = 0;
  while ((*evalOK) && (idx + 1 <= 36)) {
    *evalOK = ((!rtIsInf(cEqPlus[idx])) && (!rtIsNaN(cEqPlus[idx])));
    idx++;
  }

  xk[dim - 1] = temp_tmp;
}

// Function for MATLAB Function: '<S102>/MATLAB Function1'
static boolean_T MPC_computeFiniteDifferences_m(s_B0kB2CQLsoRkj8KoaXWXYC_MPC_T
  *obj, const real_T cEqCurrent[36], real_T xk[6], real_T JacCeqTrans[216])
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
  while ((!exitg1) && (idx < 6)) {
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
    MPC_finDiffEvalAndChkErr_a(obj->nonlin.workspace.fun.workspace.P_k,
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
          MPC_finDiffEvalAndChkErr_a(obj->nonlin.workspace.fun.workspace.P_k,
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
        JacCeqTrans[idx + 6 * idx_row] = (obj->cEq_1[idx_row] -
          cEqCurrent[idx_row]) / deltaX;
      }

      idx++;
    }
  }

  return evalOK;
}

// Function for MATLAB Function: '<S102>/MATLAB Function1'
static void MPC_lsqnonlin_e(const real_T fun_workspace_P_k[144], const real_T
  fun_workspace_H[72], const real_T fun_workspace_V[36], real_T xCurrent[6])
{
  s_B0kB2CQLsoRkj8KoaXWXYC_MPC_T FiniteDifferences;
  real_T augJacobian[252];
  real_T JacCeqTrans[216];
  real_T rhs[42];
  real_T fNew[36];
  real_T f_temp[36];
  real_T fval[36];
  real_T a__3[6];
  real_T dx[6];
  real_T gradf[6];
  real_T b_gamma;
  real_T c;
  real_T funDiff;
  real_T projSteepestDescentInfNorm;
  real_T resnorm;
  real_T resnormNew;
  real_T u0;
  int32_T aIdx;
  int32_T bIdx;
  int32_T funcCount;
  int32_T i;
  int32_T iter;
  boolean_T hasLB[6];
  boolean_T hasUB[6];
  boolean_T indActive[6];
  boolean_T hasFiniteBounds;
  boolean_T indActive_0;
  boolean_T stepSuccessful;
  static const real_T b[36] = { 0.006, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.006, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.006, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001 };

  boolean_T exitg1;
  boolean_T guard1;
  for (i = 0; i < 6; i++) {
    indActive[i] = false;
  }

  funDiff = (rtInf);
  iter = 0;
  hasFiniteBounds = MPC_hasFiniteBounds(hasLB, hasUB);
  if (!hasFiniteBounds) {
    for (i = 0; i < 6; i++) {
      xCurrent[i] = 1.0;
    }
  } else {
    for (funcCount = 0; funcCount < 6; funcCount++) {
      xCurrent[funcCount] = 1.0;
    }
  }

  MPC_corrP4R_anonFcn1(fun_workspace_P_k, fun_workspace_H, b, fun_workspace_V,
                       xCurrent, f_temp);
  resnorm = 0.0;
  for (i = 0; i < 36; i++) {
    b_gamma = f_temp[i];
    fval[i] = b_gamma;
    resnorm += b_gamma * b_gamma;
  }

  memcpy(&FiniteDifferences.nonlin.workspace.fun.workspace.P_k[0],
         &fun_workspace_P_k[0], 144U * sizeof(real_T));
  memcpy(&FiniteDifferences.nonlin.workspace.fun.workspace.H[0],
         &fun_workspace_H[0], 72U * sizeof(real_T));
  memcpy(&FiniteDifferences.nonlin.workspace.fun.workspace.V[0],
         &fun_workspace_V[0], 36U * sizeof(real_T));
  FiniteDifferences.numEvals = 0;
  FiniteDifferences.hasBounds = MPC_hasFiniteBounds(FiniteDifferences.hasLB,
    FiniteDifferences.hasUB);
  for (i = 0; i < 6; i++) {
    a__3[i] = 1.0;
  }

  MPC_computeFiniteDifferences_m(&FiniteDifferences, fval, a__3, JacCeqTrans);
  for (i = 0; i < 6; i++) {
    for (aIdx = 0; aIdx < 36; aIdx++) {
      augJacobian[aIdx + 42 * i] = JacCeqTrans[6 * aIdx + i];
    }
  }

  funcCount = FiniteDifferences.numEvals + 1;
  for (i = 0; i < 6; i++) {
    memcpy(&JacCeqTrans[i * 36], &augJacobian[i * 42], 36U * sizeof(real_T));
  }

  b_gamma = 0.01;
  for (i = 0; i < 6; i++) {
    aIdx = (i + 1) * 42;
    for (bIdx = 0; bIdx < 6; bIdx++) {
      augJacobian[(aIdx + bIdx) - 6] = 0.0;
    }

    augJacobian[(i + 42 * i) + 36] = 0.1;
    gradf[i] = 0.0;
  }

  for (i = 0; i <= 180; i += 36) {
    c = 0.0;
    for (aIdx = i + 1; aIdx <= i + 36; aIdx++) {
      c += fval[(aIdx - i) - 1] * JacCeqTrans[aIdx - 1];
    }

    aIdx = div_nde_s32_floor(i, 36);
    gradf[aIdx] += c;
  }

  projSteepestDescentInfNorm = 0.0;
  for (i = 0; i < 6; i++) {
    resnormNew = -gradf[i];
    if ((resnormNew <= 0.0) || rtIsNaN(resnormNew)) {
      resnormNew = 0.0;
    }

    if (!(projSteepestDescentInfNorm >= resnormNew)) {
      projSteepestDescentInfNorm = resnormNew;
    }
  }

  c = MPC_computeFirstOrderOpt(gradf, hasFiniteBounds,
    &projSteepestDescentInfNorm);
  if (!(c >= 1.0)) {
    c = 1.0;
  }

  stepSuccessful = true;
  i = MPC_checkStoppingCriteria(gradf, c, xCurrent, FiniteDifferences.numEvals +
    1, projSteepestDescentInfNorm, hasFiniteBounds);
  exitg1 = false;
  while ((!exitg1) && (i == -5)) {
    for (i = 0; i < 36; i++) {
      rhs[i] = -fval[i];
    }

    for (i = 0; i < 6; i++) {
      rhs[i + 36] = 0.0;
    }

    if (hasFiniteBounds) {
      projSteepestDescentInfNorm = 0.0;
      for (i = 0; i < 6; i++) {
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

      for (i = 0; i < 6; i++) {
        if (xCurrent[i] - 1.0 <= projSteepestDescentInfNorm) {
          indActive_0 = (gradf[i] > 0.0);
          indActive[i] = indActive_0;
        } else {
          indActive_0 = false;
          indActive[i] = false;
        }

        if (indActive_0) {
          memset(&augJacobian[42 * i], 0, 36U * sizeof(real_T));
        }
      }
    }

    MPC_linearLeastSquares(augJacobian, rhs, dx);
    for (i = 0; i < 6; i++) {
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

    MPC_corrP4R_anonFcn1(fun_workspace_P_k, fun_workspace_H, b, fun_workspace_V,
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
      for (i = 0; i < 6; i++) {
        a__3[i] = gradf[i];
      }

      indActive_0 = MPC_computeFiniteDifferences_m(&FiniteDifferences, fNew,
        a__3, JacCeqTrans);
      funcCount += FiniteDifferences.numEvals;
      for (i = 0; i < 6; i++) {
        for (aIdx = 0; aIdx < 36; aIdx++) {
          augJacobian[aIdx + 42 * i] = JacCeqTrans[6 * aIdx + i];
        }
      }

      memcpy(&fval[0], &fNew[0], 36U * sizeof(real_T));
      for (i = 0; i < 6; i++) {
        memcpy(&JacCeqTrans[i * 36], &augJacobian[i * 42], 36U * sizeof(real_T));
      }

      if (indActive_0) {
        for (i = 0; i < 6; i++) {
          xCurrent[i] = gradf[i];
        }

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
      for (i = 0; i < 6; i++) {
        memcpy(&augJacobian[i * 42], &JacCeqTrans[i * 36], 36U * sizeof(real_T));
      }

      guard1 = true;
    }

    if (guard1) {
      resnormNew = sqrt(b_gamma);
      for (i = 0; i < 6; i++) {
        aIdx = (i + 1) * 42;
        for (bIdx = 0; bIdx < 6; bIdx++) {
          augJacobian[(aIdx + bIdx) - 6] = 0.0;
        }

        augJacobian[(i + 42 * i) + 36] = resnormNew;
        gradf[i] = 0.0;
      }

      for (i = 0; i <= 180; i += 36) {
        resnormNew = 0.0;
        for (aIdx = i + 1; aIdx <= i + 36; aIdx++) {
          resnormNew += fval[(aIdx - i) - 1] * JacCeqTrans[aIdx - 1];
        }

        aIdx = div_nde_s32_floor(i, 36);
        gradf[aIdx] += resnormNew;
      }

      projSteepestDescentInfNorm = 0.0;
      for (i = 0; i < 6; i++) {
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

      i = MPC_checkStoppingCriteria_o(gradf, c, funDiff, xCurrent, dx, funcCount,
        stepSuccessful, &iter, projSteepestDescentInfNorm, hasFiniteBounds);
      if (i != -5) {
        exitg1 = true;
      }
    }
  }
}

// Function for MATLAB Function: '<S102>/MATLAB Function1'
static void MPC_timeKeeper_gw(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_aw,
  real_T *outTime_tv_sec, real_T *outTime_tv_nsec)
{
  coderTimespec origTimespec;
  if (!MPC_DW.savedTime_not_empty) {
    if (!MPC_DW.freq_not_empty) {
      MPC_DW.freq_not_empty = true;
      coderInitTimeFunctions(&MPC_DW.freq);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, MPC_DW.freq);
    savedTime_aw->tv_sec = origTimespec.tv_sec;
    savedTime_aw->tv_nsec = origTimespec.tv_nsec;
  }

  *outTime_tv_sec = savedTime_aw->tv_sec;
  *outTime_tv_nsec = savedTime_aw->tv_nsec;
}

// Function for MATLAB Function: '<S102>/MATLAB Function1'
static real_T MPC_toc_a(sdAmwXbnJnEmimT0NaJRtAD_MPC_T *savedTime_aw)
{
  coderTimespec origTimespec;
  real_T t;
  real_T tstart_tv_nsec;
  real_T tstart_tv_sec;
  MPC_timeKeeper_gw(savedTime_aw, &tstart_tv_sec, &tstart_tv_nsec);
  if (!MPC_DW.freq_not_empty) {
    MPC_DW.freq_not_empty = true;
    coderInitTimeFunctions(&MPC_DW.freq);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, MPC_DW.freq);
  t = (origTimespec.tv_nsec - tstart_tv_nsec) / 1.0E+9 + (origTimespec.tv_sec -
    tstart_tv_sec);
  return t;
}

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static real_T MPC_xnrm2_ob(int32_T n, const real_T x[153], int32_T ix0)
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static real_T MPC_xzlarfg_m(int32_T n, real_T *alpha1, real_T x[153], int32_T
  ix0)
{
  real_T a;
  real_T tau;
  real_T xnorm;
  int32_T c_tmp;
  int32_T d;
  int32_T knt;
  tau = 0.0;
  if (n > 0) {
    xnorm = MPC_xnrm2_ob(n - 1, x, ix0);
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

        xnorm = rt_hypotd_snf(*alpha1, MPC_xnrm2_ob(n - 1, x, ix0));
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_xzlarf_b(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T
  C[153], int32_T ic0, real_T work[17])
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_qrf(real_T A[153], int32_T m, int32_T n, int32_T nfxd, real_T
                    tau[9])
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
      tau_0 = MPC_xzlarfg_m(mmi, &b_atmp, A, ii + 2);
      tau[i] = tau_0;
      A[ii] = b_atmp;
    } else {
      tau_0 = 0.0;
      tau[i] = 0.0;
    }

    if (i + 1 < n) {
      b_atmp = A[ii];
      A[ii] = 1.0;
      MPC_xzlarf_b(mmi, (n - i) - 1, ii + 1, tau_0, A, ii + 10, work);
      A[ii] = b_atmp;
    }
  }
}

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_xgeqp3(real_T A[153], int32_T m, int32_T n, int32_T jpvt[17],
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
    MPC_qrf(A, m, n, nfxd, tau);
    if (nfxd < minmn_tmp) {
      memset(&work[0], 0, 17U * sizeof(real_T));
      memset(&vn1[0], 0, 17U * sizeof(real_T));
      memset(&vn2[0], 0, 17U * sizeof(real_T));
      for (i = nfxd + 1; i <= n; i++) {
        temp = MPC_xnrm2_ob(m - nfxd, A, ((i - 1) * 9 + nfxd) + 1);
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
          temp = MPC_xzlarfg_m(mmi + 1, &s, A, ix + 2);
          tau[i - 1] = temp;
          A[ix] = s;
        } else {
          temp = 0.0;
          tau[i - 1] = 0.0;
        }

        if (i < n) {
          s = A[ix];
          A[ix] = 1.0;
          MPC_xzlarf_b(mmi + 1, iy, ix + 1, temp, A, ix + 10, work);
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
                temp = MPC_xnrm2_ob(mmi, A, ix + 1);
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_countsort(int32_T x[17], int32_T xLen, int32_T workspace[17],
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_removeConstr(srnx7tMxlsAQ9dn31gXFrqF_MPC_T *obj, int32_T
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_RemoveDependentIneq_(srnx7tMxlsAQ9dn31gXFrqF_MPC_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_MPC_T *qrmanager, sLLWTJNyuJQrAxk3RwmbzBG_MPC_T
  *memspace, real_T tolfactor)
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

      MPC_xgeqp3(qrmanager->QR, workingset->nVar, workingset->nActiveConstr,
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

    MPC_countsort(memspace->workspace_int, nDepIneq, memspace->workspace_sort,
                  nFixedConstr + 1, workingset->nActiveConstr);
    for (nFixedConstr = nDepIneq; nFixedConstr >= 1; nFixedConstr--) {
      MPC_removeConstr(workingset, memspace->workspace_int[nFixedConstr - 1]);
    }
  }
}

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_computeQ_(sTj3C1mXm6Z2qP847mPxR8C_MPC_T *obj, int32_T nrows)
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static int32_T MPC_rank(const real_T qrmanager_QR[153], int32_T qrmanager_mrows,
  int32_T qrmanager_ncols)
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static real_T MPC_maxConstraintViolation(const srnx7tMxlsAQ9dn31gXFrqF_MPC_T
  *obj, const real_T x[153], int32_T ix0)
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static boolean_T MPC_feasibleX0ForWorkingSet(real_T workspace[153], real_T
  xCurrent[9], const srnx7tMxlsAQ9dn31gXFrqF_MPC_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_MPC_T *qrmanager)
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

        MPC_xgeqp3(qrmanager->QR, workingset->nActiveConstr, workingset->nVar,
                   qrmanager->jpvt, qrmanager->tau);
      }

      MPC_computeQ_(qrmanager, qrmanager->mrows);
      rankQR = MPC_rank(qrmanager->QR, qrmanager->mrows, qrmanager->ncols);
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

        MPC_xgeqp3(qrmanager->QR, workingset->nVar, workingset->nActiveConstr,
                   qrmanager->jpvt, qrmanager->tau);
      }

      MPC_computeQ_(qrmanager, qrmanager->minRowCol);
      rankQR = MPC_rank(qrmanager->QR, qrmanager->mrows, qrmanager->ncols);
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

        temp = MPC_maxConstraintViolation(workingset, workspace, 1);
        constrViolation_basicX = MPC_maxConstraintViolation(workingset,
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static real_T MPC_maxConstraintViolation_c(const srnx7tMxlsAQ9dn31gXFrqF_MPC_T
  *obj, const real_T x[9])
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_setProblemType(srnx7tMxlsAQ9dn31gXFrqF_MPC_T *obj, int32_T
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_xgemv(int32_T m, int32_T n, const real_T A[64], int32_T lda,
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_computeGrad_StoreHx(s87IldPMN2ICa85Nu8z6UL_MPC_T *obj, const
  real_T H[64], const real_T f[8], const real_T x[9])
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
    MPC_xgemv(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
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
    MPC_xgemv(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static real_T MPC_computeFval_ReuseHx(const s87IldPMN2ICa85Nu8z6UL_MPC_T *obj,
  real_T workspace[153], const real_T f[8], const real_T x[9])
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_factorQR(sTj3C1mXm6Z2qP847mPxR8C_MPC_T *obj, const real_T A[153],
  int32_T mrows, int32_T ncols)
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
      MPC_qrf(obj->QR, mrows, ncols, i, obj->tau);
    }
  }
}

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_xrotg_o(real_T *a, real_T *b, real_T *c, real_T *s)
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_squareQ_appendCol(sTj3C1mXm6Z2qP847mPxR8C_MPC_T *obj, const
  real_T vec[153], int32_T iv0)
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
    MPC_xrotg_o(&obj->QR[c_iy], &temp, &b_c, &s);
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_deleteColMoveEnd(sTj3C1mXm6Z2qP847mPxR8C_MPC_T *obj, int32_T idx)
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
        MPC_xrotg_o(&obj->QR[QRk0 - 1], &b_temp, &c_c, &b_s);
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
        MPC_xrotg_o(&obj->QR[QRk0 - 1], &b_temp, &c_c, &b_s);
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_fullColLDL2_(smSS6fEwaptVbzYAOdOZgjB_MPC_T *obj, int32_T
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_xgemv_a(int32_T m, int32_T n, const real_T A[81], int32_T ia0,
  const real_T x[153], real_T y[9])
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_compute_deltax(const real_T H[64], sraTyWZlTzdIJhNDrRZT2SF_MPC_T
  *solution, sLLWTJNyuJQrAxk3RwmbzBG_MPC_T *memspace, const
  sTj3C1mXm6Z2qP847mPxR8C_MPC_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_MPC_T
  *cholmanager, const s87IldPMN2ICa85Nu8z6UL_MPC_T *objective)
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

        MPC_fullColLDL2_(cholmanager, qrmanager->mrows, temp);
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

        MPC_xgemv_a(qrmanager->mrows, mNull_tmp, qrmanager->Q, A_maxDiag_idx + 1,
                    memspace->workspace_float, solution->searchDir);
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

        MPC_fullColLDL2_(cholmanager, mNull_tmp, temp);
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

          MPC_xgemv_a(qrmanager->mrows, mNull_tmp, qrmanager->Q, A_maxDiag_idx +
                      1, memspace->workspace_float, solution->searchDir);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static real_T MPC_xnrm2_ob0(int32_T n, const real_T x[9])
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_feasibleratiotest(const real_T solution_xstar[9], const real_T
  solution_searchDir[9], int32_T workingset_nVar, const real_T workingset_lb[9],
  const int32_T workingset_indexLB[9], const int32_T workingset_indexUB[9],
  const int32_T workingset_sizes[5], const int32_T workingset_isActiveIdx[6],
  const boolean_T workingset_isActiveConstr[17], const int32_T
  workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha, boolean_T
  *newBlocking, int32_T *constrType, int32_T *constrIdx)
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
  denomTol = 2.2204460492503131E-13 * MPC_xnrm2_ob0(workingset_nVar,
    solution_searchDir);
  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    phaseOneCorrectionX = solution_xstar[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
    phaseOneCorrectionP = solution_searchDir[workingset_nVar - 1] *
      static_cast<real_T>(isPhaseOne);
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_addBoundToActiveSetMatrix_(srnx7tMxlsAQ9dn31gXFrqF_MPC_T *obj,
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_addAineqConstr(const srnx7tMxlsAQ9dn31gXFrqF_MPC_T *obj)
{
  int32_T b;
  b = obj->nVar;
  for (int32_T idx = 0; idx < b; idx++) {
    // Check node always fails. would cause program termination and was eliminated 
  }

  // Check node always fails. would cause program termination and was eliminated 
}

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_compute_lambda(real_T workspace[153],
  sraTyWZlTzdIJhNDrRZT2SF_MPC_T *solution, const s87IldPMN2ICa85Nu8z6UL_MPC_T
  *objective, const sTj3C1mXm6Z2qP847mPxR8C_MPC_T *qrmanager)
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_phaseone(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_MPC_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_MPC_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_MPC_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_MPC_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_MPC_T
  *cholmanager, const sIOJhD9KwAkF5sEguPjYquC_MPC_T *runTimeOptions,
  s87IldPMN2ICa85Nu8z6UL_MPC_T *objective)
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
  MPC_setProblemType(workingset, 1);
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
  MPC_computeGrad_StoreHx(objective, H, f, solution->xstar);
  solution->fstar = MPC_computeFval_ReuseHx(objective, memspace->workspace_float,
    f, solution->xstar);
  solution->state = -5;
  memset(&solution->lambda[0], 0, 17U * sizeof(real_T));
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      guard1 = false;
      if (subProblemChanged) {
        switch (idxEndIneq) {
         case 1:
          MPC_squareQ_appendCol(qrmanager, workingset->ATwset, 9 *
                                (workingset->nActiveConstr - 1) + 1);
          break;

         case -1:
          MPC_deleteColMoveEnd(qrmanager, idxStartIneq);
          break;

         default:
          MPC_factorQR(qrmanager, workingset->ATwset, i,
                       workingset->nActiveConstr);
          MPC_computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        MPC_compute_deltax(H, solution, memspace, qrmanager, cholmanager,
                           objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          normDelta = MPC_xnrm2_ob0(i, solution->searchDir);
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
          MPC_compute_lambda(memspace->workspace_float, solution, objective,
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
              MPC_removeConstr(workingset, idxMinLambda);
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
            MPC_removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda[idxStartIneq_tmp - 1] = 0.0;
          }

          updateFval = false;
        } else {
          MPC_feasibleratiotest(solution->xstar, solution->searchDir,
                                workingset->nVar, workingset->lb,
                                workingset->indexLB, workingset->indexUB,
                                workingset->sizes, workingset->isActiveIdx,
                                workingset->isActiveConstr, workingset->nWConstr,
                                true, &normDelta, &updateFval, &idxStartIneq_tmp,
                                &idxMinLambda);
          if (updateFval) {
            switch (idxStartIneq_tmp) {
             case 3:
              MPC_addAineqConstr(workingset);
              break;

             case 4:
              MPC_addBoundToActiveSetMatrix_(workingset, 4, idxMinLambda);
              break;

             default:
              MPC_addBoundToActiveSetMatrix_(workingset, 5, idxMinLambda);
              break;
            }

            idxEndIneq = 1;
          } else {
            if (objective->objtype == 5) {
              if (MPC_xnrm2_ob0(objective->nvar, solution->searchDir) > 100.0 *
                  static_cast<real_T>(objective->nvar) * 1.4901161193847656E-8)
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

          MPC_computeGrad_StoreHx(objective, H, f, solution->xstar);
          updateFval = true;
        }

        solution->iterations++;
        if (solution->iterations >= 5) {
          solution->state = 0;
        }

        if (solution->iterations - solution->iterations / 50 * 50 == 0) {
          solution->maxConstr = MPC_maxConstraintViolation_c(workingset,
            solution->xstar);
          if (solution->maxConstr - solution->xstar[8] > 1.0E-8) {
            memcpy(&solution->searchDir[0], &solution->xstar[0], 9U * sizeof
                   (real_T));
            nonDegenerateWset = MPC_feasibleX0ForWorkingSet
              (memspace->workspace_float, solution->searchDir, workingset,
               qrmanager);
            if ((!nonDegenerateWset) && (solution->state != 0)) {
              solution->state = -2;
            }

            idxEndIneq = 0;
            normDelta = MPC_maxConstraintViolation_c(workingset,
              solution->searchDir);
            if (normDelta < solution->maxConstr) {
              memcpy(&solution->xstar[0], &solution->searchDir[0], 9U * sizeof
                     (real_T));
            }
          }
        }

        if (updateFval) {
          solution->fstar = MPC_computeFval_ReuseHx(objective,
            memspace->workspace_float, f, solution->xstar);
          if ((solution->fstar < 1.0E-8) && (solution->state != 0)) {
            solution->state = 2;
          }
        }
      }
    } else {
      if (!updateFval) {
        solution->fstar = MPC_computeFval_ReuseHx(objective,
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
        MPC_removeConstr(workingset, i);
        exitg2 = true;
      } else {
        i++;
      }
    }
  }

  for (i = workingset->nActiveConstr; i > 8; i--) {
    MPC_removeConstr(workingset, i);
  }

  solution->maxConstr = solution->xstar[8];
  MPC_setProblemType(workingset, 3);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
}

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static int32_T MPC_RemoveDependentEq_(sLLWTJNyuJQrAxk3RwmbzBG_MPC_T *memspace,
  const srnx7tMxlsAQ9dn31gXFrqF_MPC_T *workingset, sTj3C1mXm6Z2qP847mPxR8C_MPC_T
  *qrmanager)
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

      MPC_xgeqp3(qrmanager->QR, mTotalWorkingEq_tmp, workingset->nVar,
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
      MPC_computeQ_(qrmanager, qrmanager->mrows);
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
        MPC_xgeqp3(qrmanager->QR, workingset->nVar, mTotalWorkingEq_tmp,
                   qrmanager->jpvt, qrmanager->tau);
      }

      for (mWorkingFixed = 0; mWorkingFixed < nDepInd; mWorkingFixed++) {
        memspace->workspace_int[mWorkingFixed] = qrmanager->jpvt
          [(mTotalWorkingEq_tmp - nDepInd) + mWorkingFixed];
      }

      MPC_countsort(memspace->workspace_int, nDepInd, memspace->workspace_sort,
                    1, mTotalWorkingEq_tmp);
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_ratiotest(const real_T solution_xstar[9], const real_T
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
  denomTol = 2.2204460492503131E-13 * MPC_xnrm2_ob0(workingset_nVar,
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_iterate(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_MPC_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_MPC_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_MPC_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_MPC_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_MPC_T
  *cholmanager, s87IldPMN2ICa85Nu8z6UL_MPC_T *objective, boolean_T
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
  MPC_computeGrad_StoreHx(objective, H, f, solution->xstar);
  solution->fstar = MPC_computeFval_ReuseHx(objective, memspace->workspace_float,
    f, solution->xstar);
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
          MPC_squareQ_appendCol(qrmanager, workingset->ATwset, 9 *
                                (workingset->nActiveConstr - 1) + 1);
          break;

         case -1:
          MPC_deleteColMoveEnd(qrmanager, globalActiveConstrIdx);
          break;

         default:
          MPC_factorQR(qrmanager, workingset->ATwset, nVar,
                       workingset->nActiveConstr);
          MPC_computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        MPC_compute_deltax(H, solution, memspace, qrmanager, cholmanager,
                           objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          normDelta = MPC_xnrm2_ob0(nVar, solution->searchDir);
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
          MPC_compute_lambda(memspace->workspace_float, solution, objective,
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
              MPC_removeConstr(workingset, localActiveConstrIdx);
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
            MPC_removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda[localActiveConstrIdx - 1] = 0.0;
          }

          updateFval = false;
        } else {
          updateFval = (TYPE == 5);
          if (updateFval || runTimeOptions_RemainFeasible) {
            MPC_feasibleratiotest(solution->xstar, solution->searchDir,
                                  workingset->nVar, workingset->lb,
                                  workingset->indexLB, workingset->indexUB,
                                  workingset->sizes, workingset->isActiveIdx,
                                  workingset->isActiveConstr,
                                  workingset->nWConstr, updateFval, &normDelta,
                                  &newBlocking, &activeConstrChangedType,
                                  &localActiveConstrIdx);
          } else {
            MPC_ratiotest(solution->xstar, solution->searchDir, workingset->nVar,
                          workingset->lb, workingset->indexLB,
                          workingset->indexUB, workingset->sizes,
                          workingset->isActiveIdx, workingset->isActiveConstr,
                          workingset->nWConstr, &tolDelta, &normDelta,
                          &newBlocking, &activeConstrChangedType,
                          &localActiveConstrIdx);
          }

          if (newBlocking) {
            switch (activeConstrChangedType) {
             case 3:
              MPC_addAineqConstr(workingset);
              break;

             case 4:
              MPC_addBoundToActiveSetMatrix_(workingset, 4, localActiveConstrIdx);
              break;

             default:
              MPC_addBoundToActiveSetMatrix_(workingset, 5, localActiveConstrIdx);
              break;
            }

            activeSetChangeID = 1;
          } else {
            if (objective->objtype == 5) {
              if (MPC_xnrm2_ob0(objective->nvar, solution->searchDir) > 100.0 *
                  static_cast<real_T>(objective->nvar) * 1.4901161193847656E-8)
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

          MPC_computeGrad_StoreHx(objective, H, f, solution->xstar);
          updateFval = true;
        }

        solution->iterations++;
        activeConstrChangedType = objective->nvar;
        if ((solution->iterations >= 5) && ((solution->state != 1) ||
             (objective->objtype == 5))) {
          solution->state = 0;
        }

        if (solution->iterations - solution->iterations / 50 * 50 == 0) {
          solution->maxConstr = MPC_maxConstraintViolation_c(workingset,
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

            newBlocking = MPC_feasibleX0ForWorkingSet(memspace->workspace_float,
              solution->searchDir, workingset, qrmanager);
            if ((!newBlocking) && (solution->state != 0)) {
              solution->state = -2;
            }

            activeSetChangeID = 0;
            normDelta = MPC_maxConstraintViolation_c(workingset,
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
          solution->fstar = MPC_computeFval_ReuseHx(objective,
            memspace->workspace_float, f, solution->xstar);
          if ((solution->fstar < -1.0E+20) && ((solution->state != 0) ||
               (objective->objtype != 5))) {
            solution->state = 2;
          }
        }
      }
    } else {
      if (!updateFval) {
        solution->fstar = MPC_computeFval_ReuseHx(objective,
          memspace->workspace_float, f, solution->xstar);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_computeFirstOrderOpt_h(sraTyWZlTzdIJhNDrRZT2SF_MPC_T *solution,
  const s87IldPMN2ICa85Nu8z6UL_MPC_T *objective, int32_T workingset_nVar, const
  real_T workingset_ATwset[153], int32_T workingset_nActiveConstr, real_T
  workspace[153])
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_phaseone_i(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_MPC_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_MPC_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_MPC_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_MPC_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_MPC_T
  *cholmanager, s87IldPMN2ICa85Nu8z6UL_MPC_T *objective, const
  sIOJhD9KwAkF5sEguPjYquC_MPC_T *runTimeOptions)
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

  MPC_setProblemType(workingset, b_nVar);
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
  MPC_computeGrad_StoreHx(objective, H, f, solution->xstar);
  solution->fstar = MPC_computeFval_ReuseHx(objective, memspace->workspace_float,
    f, solution->xstar);
  solution->state = -5;
  memset(&solution->lambda[0], 0, 17U * sizeof(real_T));
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      guard1 = false;
      if (subProblemChanged) {
        switch (idxEndIneq) {
         case 1:
          MPC_squareQ_appendCol(qrmanager, workingset->ATwset, 9 *
                                (workingset->nActiveConstr - 1) + 1);
          break;

         case -1:
          MPC_deleteColMoveEnd(qrmanager, idxStartIneq);
          break;

         default:
          MPC_factorQR(qrmanager, workingset->ATwset, idxStartIneq_tmp,
                       workingset->nActiveConstr);
          MPC_computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        MPC_compute_deltax(H, solution, memspace, qrmanager, cholmanager,
                           objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          normDelta = MPC_xnrm2_ob0(idxStartIneq_tmp, solution->searchDir);
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
          MPC_compute_lambda(memspace->workspace_float, solution, objective,
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
              MPC_removeConstr(workingset, idxMinLambda);
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
            MPC_removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda[b_nVar - 1] = 0.0;
          }

          updateFval = false;
        } else {
          MPC_feasibleratiotest(solution->xstar, solution->searchDir,
                                workingset->nVar, workingset->lb,
                                workingset->indexLB, workingset->indexUB,
                                workingset->sizes, workingset->isActiveIdx,
                                workingset->isActiveConstr, workingset->nWConstr,
                                true, &normDelta, &updateFval, &b_nVar,
                                &idxMinLambda);
          if (updateFval) {
            switch (b_nVar) {
             case 3:
              MPC_addAineqConstr(workingset);
              break;

             case 4:
              MPC_addBoundToActiveSetMatrix_(workingset, 4, idxMinLambda);
              break;

             default:
              MPC_addBoundToActiveSetMatrix_(workingset, 5, idxMinLambda);
              break;
            }

            idxEndIneq = 1;
          } else {
            if (objective->objtype == 5) {
              if (MPC_xnrm2_ob0(objective->nvar, solution->searchDir) > 100.0 *
                  static_cast<real_T>(objective->nvar) * 1.4901161193847656E-8)
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

          MPC_computeGrad_StoreHx(objective, H, f, solution->xstar);
          updateFval = true;
        }

        solution->iterations++;
        idxMinLambda = objective->nvar;
        if ((solution->iterations >= 5) && ((solution->state != 1) ||
             (objective->objtype == 5))) {
          solution->state = 0;
        }

        if (solution->iterations - solution->iterations / 50 * 50 == 0) {
          solution->maxConstr = MPC_maxConstraintViolation_c(workingset,
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

            nonDegenerateWset = MPC_feasibleX0ForWorkingSet
              (memspace->workspace_float, solution->searchDir, workingset,
               qrmanager);
            if ((!nonDegenerateWset) && (solution->state != 0)) {
              solution->state = -2;
            }

            idxEndIneq = 0;
            normDelta = MPC_maxConstraintViolation_c(workingset,
              solution->searchDir);
            if ((normDelta < solution->maxConstr) && (objective->nvar - 1 >= 0))
            {
              memcpy(&solution->xstar[0], &solution->searchDir[0],
                     static_cast<uint32_T>(objective->nvar) * sizeof(real_T));
            }
          }
        }

        if (updateFval) {
          solution->fstar = MPC_computeFval_ReuseHx(objective,
            memspace->workspace_float, f, solution->xstar);
          if ((solution->fstar < 1.0E-8) && ((solution->state != 0) ||
               (objective->objtype != 5))) {
            solution->state = 2;
          }
        }
      }
    } else {
      if (!updateFval) {
        solution->fstar = MPC_computeFval_ReuseHx(objective,
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
        MPC_removeConstr(workingset, b_nVar);
        exitg2 = true;
      } else {
        b_nVar++;
      }
    }
  }

  b_nVar = workingset->nActiveConstr;
  while ((b_nVar > 0) && (b_nVar > nVar_tmp)) {
    MPC_removeConstr(workingset, b_nVar);
    b_nVar--;
  }

  solution->maxConstr = solution->xstar[8];
  MPC_setProblemType(workingset, PROBTYPE_ORIG);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
}

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar, real_T
  workspace[153], const real_T H[64], const real_T f[8], const real_T x[9])
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static real_T MPC_computeFval(const s87IldPMN2ICa85Nu8z6UL_MPC_T *obj, real_T
  workspace[153], const real_T H[64], const real_T f[8], const real_T x[9])
{
  real_T val;
  int32_T idx;
  int32_T ixlast;
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    MPC_linearForm_(obj->hasLinear, obj->nvar, workspace, H, f, x);
    val = 0.0;
    if (obj->nvar >= 1) {
      ixlast = obj->nvar;
      for (idx = 0; idx < ixlast; idx++) {
        val += x[idx] * workspace[idx];
      }
    }
    break;

   default:
    MPC_linearForm_(obj->hasLinear, obj->nvar, workspace, H, f, x);
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

// Function for MATLAB Function: '<S292>/MATLAB Function5'
static void MPC_quadprog(const real_T H[64], const real_T f[8], const real_T x0
  [8], real_T x[8], real_T *fval, real_T *exitflag)
{
  s87IldPMN2ICa85Nu8z6UL_MPC_T objective;
  sIOJhD9KwAkF5sEguPjYquC_MPC_T runTimeOptions;
  sLLWTJNyuJQrAxk3RwmbzBG_MPC_T memspace;
  sTj3C1mXm6Z2qP847mPxR8C_MPC_T qrmanager;
  sraTyWZlTzdIJhNDrRZT2SF_MPC_T solution;
  srnx7tMxlsAQ9dn31gXFrqF_MPC_T workingset;
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
  MPC_B.obj.ndims = 0;
  MPC_B.obj.info = 0;
  MPC_B.obj.ConvexCheck = true;
  MPC_B.obj.regTol_ = 0.0;
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

  MPC_B.obj.scaleFactor = H_infnrm;
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
  MPC_RemoveDependentIneq_(&workingset, &qrmanager, &memspace, 1.0);
  okWorkingSet = MPC_feasibleX0ForWorkingSet(memspace.workspace_float,
    solution.xstar, &workingset, &qrmanager);
  if (!okWorkingSet) {
    MPC_RemoveDependentIneq_(&workingset, &qrmanager, &memspace, 10.0);
    okWorkingSet = MPC_feasibleX0ForWorkingSet(memspace.workspace_float,
      solution.xstar, &workingset, &qrmanager);
    if (!okWorkingSet) {
      solution.state = -7;
    }
  }

  if (solution.state >= 0) {
    solution.iterations = 0;
    solution.maxConstr = MPC_maxConstraintViolation_c(&workingset,
      solution.xstar);
    guard1 = false;
    if (solution.maxConstr > 1.0E-8) {
      MPC_phaseone(H, f, &solution, &memspace, &workingset, &qrmanager,
                   &MPC_B.obj, &runTimeOptions, &objective);
      if (solution.state == 0) {
      } else {
        solution.maxConstr = MPC_maxConstraintViolation_c(&workingset,
          solution.xstar);
        if (solution.maxConstr > 1.0E-8) {
          solution.fstar = MPC_computeFval(&objective, memspace.workspace_float,
            H, f, solution.xstar);
          solution.state = -2;
        } else {
          if (solution.maxConstr > 0.0) {
            memcpy(&solution.searchDir[0], &solution.xstar[0], sizeof(real_T) <<
                   3U);
            solution.state = 82;
            i = MPC_RemoveDependentEq_(&memspace, &workingset, &qrmanager);
            if ((i != -1) && (workingset.nActiveConstr <= 9)) {
              MPC_RemoveDependentIneq_(&workingset, &qrmanager, &memspace, 1.0);
              okWorkingSet = MPC_feasibleX0ForWorkingSet
                (memspace.workspace_float, solution.xstar, &workingset,
                 &qrmanager);
              guard2 = false;
              if (!okWorkingSet) {
                MPC_RemoveDependentIneq_(&workingset, &qrmanager, &memspace,
                  10.0);
                okWorkingSet = MPC_feasibleX0ForWorkingSet
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
                  f_infnrm = MPC_maxConstraintViolation_c(&workingset,
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

            f_infnrm = MPC_maxConstraintViolation_c(&workingset, solution.xstar);
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
      MPC_iterate(H, f, &solution, &memspace, &workingset, &qrmanager,
                  &MPC_B.obj, &objective, true, H_infnrm);
      if (solution.state != -6) {
        solution.maxConstr = MPC_maxConstraintViolation_c(&workingset,
          solution.xstar);
        MPC_computeFirstOrderOpt_h(&solution, &objective, workingset.nVar,
          workingset.ATwset, workingset.nActiveConstr, memspace.workspace_float);
        runTimeOptions.RemainFeasible = false;
        while ((solution.iterations < 5) && ((solution.state == -7) ||
                ((solution.state == 1) && ((solution.maxConstr > 1.0E-8) ||
                  (solution.firstorderopt > 1.0E-8 * H_infnrm))))) {
          MPC_feasibleX0ForWorkingSet(memspace.workspace_float, solution.xstar,
            &workingset, &qrmanager);
          solution.state = 82;
          i = MPC_RemoveDependentEq_(&memspace, &workingset, &qrmanager);
          if ((i != -1) && (workingset.nActiveConstr <= 9)) {
            MPC_RemoveDependentIneq_(&workingset, &qrmanager, &memspace, 1.0);
            okWorkingSet = MPC_feasibleX0ForWorkingSet(memspace.workspace_float,
              solution.xstar, &workingset, &qrmanager);
            guard2 = false;
            if (!okWorkingSet) {
              MPC_RemoveDependentIneq_(&workingset, &qrmanager, &memspace, 10.0);
              okWorkingSet = MPC_feasibleX0ForWorkingSet
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
                f_infnrm = MPC_maxConstraintViolation_c(&workingset,
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

          MPC_phaseone_i(H, f, &solution, &memspace, &workingset, &qrmanager,
                         &MPC_B.obj, &objective, &runTimeOptions);
          MPC_iterate(H, f, &solution, &memspace, &workingset, &qrmanager,
                      &MPC_B.obj, &objective, false, H_infnrm);
          solution.maxConstr = MPC_maxConstraintViolation_c(&workingset,
            solution.xstar);
          MPC_computeFirstOrderOpt_h(&solution, &objective, workingset.nVar,
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
    *fval = MPC_computeFval(&objective, memspace.workspace_float, H, f,
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

// Function for MATLAB Function: '<S292>/MATLAB Function1'
static real_T MPC_maximum_h(const real_T x[8])
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

static void MPC_pause(real_T varargin_1)
{
  coderTimespec b_timespec;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  if (MPC_DW.pauseState == 0) {
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

  // End of Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
}

static void M_bmi160_set_EnableSecondaryMag(b_bmi160_MPC_T *obj)
{
  b_bmi160_MPC_T *obj_0;
  b_bmi160_MPC_T *obj_1;
  e_matlabshared_devicedrivers__T *obj_3;
  f_matlabshared_sensors_coder__T *obj_2;
  uint8_T b_data[2];
  uint8_T b_status;
  uint8_T slaveAddress;
  uint8_T val;
  obj_0 = obj;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_2 = obj->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 25U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  MPC_pause(0.06);
  obj_1 = obj_0;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 55U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  MPC_pause(0.001);
  obj_2 = obj_1->Device;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 154U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  MPC_pause(0.001);
  obj_2 = obj_1->Device;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 192U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  MPC_pause(0.001);
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 5U;
  b_data[1] = 32U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  obj_2 = obj_0->Device;
  b_status = 75U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 75U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 1U) | 32);
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  MPC_pause(0.001);
  obj_2 = obj_0->Device;
  b_status = 76U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 76U;
  b_data[1] = 131U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  MPC_pause(0.001);
  obj_2 = obj_0->Device;
  b_status = 107U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 107U;
  b_data[1] = 32U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  MPC_pause(0.001);
  obj_2 = obj_0->Device;
  b_status = 79U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  b_status = 78U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
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
  MPC_pause(0.001);
  obj_1 = obj_0;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 77U;
  b_data[1] = 64U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  MPC_pause(0.001);
  obj_2 = obj_1->Device;
  b_status = 4U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  obj_1 = obj_0;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  b_status = 79U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  b_status = 78U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
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
  MPC_pause(0.001);
  obj_2 = obj_1->Device;
  b_status = 79U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  obj_2 = obj_1->Device;
  b_status = 78U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  obj_2 = obj_1->Device;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 79U;
  b_data[1] = 14U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  obj_2 = obj_1->Device;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 78U;
  b_data[1] = 82U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  MPC_pause(0.001);
  obj_2 = obj_0->Device;
  b_status = 79U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  b_status = 78U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
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

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 77U;
  b_data[1] = 66U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
}

static void MPC_SystemCore_setup(nvidiacoder_sensors_BMI160Blo_T *obj)
{
  b_bmi160_MPC_T *b_obj;
  b_bmi160_MPC_T *obj_2;
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

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj->isInitialized = 1;
  obj_0 = obj;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
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

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U, false,
                      true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_2 = &obj->_pobj2;
  obj_3 = obj->_pobj2.Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 182U;
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  MPC_pause(0.06);
  obj_3 = obj_2->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 3U;
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  MPC_pause(0.06);
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 17U;
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  MPC_pause(0.005);
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 21U;
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  MPC_pause(0.085);
  M_bmi160_set_EnableSecondaryMag(b_obj);

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  b_status = 65U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 65U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 240U) | 3);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 64U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 64U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 112U) | 8);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 64U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 64U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 15U) | 32);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 67U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 67U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 248U) | 4);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 66U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 66U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 240U) | 8);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 66U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 66U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 207U) | 32);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 68U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 68U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 240U) | 6);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 76U;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 76U;
  b_data[1] = static_cast<uint8_T>(val & 63);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  MPC_pause(0.001);
  b_obj->matlabCodegenIsDeleted = false;
  obj_1->SensorObject = b_obj;

  // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  obj_0->OutputModules.f1 = &obj_0->_pobj1;
  obj_0->OutputModules.f2 = &obj_0->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

// Model step function
void MPC_step(void)
{
  // local block i/o variables
  real_T rtb_DataStoreRead6;
  real_T rtb_DataStoreRead_p[9];
  real_T rtb_DataStoreRead1_f[9];
  real_T rtb_DataStoreRead2_k[9];
  real_T rtb_ThrustPer_Final_i[8];
  real_T rtb_ThrustPer_Final_n[8];
  real_T rtb_out[13];

  {
    e_matlabshared_devicedrivers__T *obj_0;
    f_matlabshared_sensors_coder__T *obj;
    sdAmwXbnJnEmimT0NaJRtAD_MPC_T savedTime;
    sdAmwXbnJnEmimT0NaJRtAD_MPC_T savedTime_a;
    sdAmwXbnJnEmimT0NaJRtAD_MPC_T savedTime_aw;
    sdAmwXbnJnEmimT0NaJRtAD_MPC_T savedTime_f;
    real_T L[144];
    real_T L_0[144];
    real_T P_k[144];
    real_T QMEKFP_tmp_0[144];
    real_T QMEKFP_tmp_1[144];
    real_T Phi_m[81];
    real_T tmp_1[81];
    real_T H[72];
    real_T H_0[72];
    real_T K_0[72];
    real_T K_tmp[72];
    real_T tmp_0[64];
    real_T y[64];
    real_T BLACK_Estimated_Covar[36];
    real_T BLACK_Estimated_Covar_0[36];
    real_T BLACK_Estimated_Covar_1[36];
    real_T BLACK_Estimated_Covar_2[36];
    real_T BLUE_Estimated_Covar[36];
    real_T Pk[36];
    real_T Phi_m_tmp[27];
    real_T Phi_m_tmp_0[27];
    real_T rtb_H[24];
    real_T rtb_H_tmp[24];
    real_T tmp[24];
    real_T G[18];
    real_T K[18];
    real_T q_0[16];
    real_T x_k[13];
    real_T delta_x[12];
    real_T F_tmp_0[9];
    real_T R_chaser[9];
    real_T R_chaser_0[9];
    real_T R_chaser_tmp[9];
    real_T Rot_error[9];
    real_T Rot_pred[9];
    real_T m[9];
    real_T varargin_4[9];
    real_T x_est[9];
    real_T PWMs[8];
    real_T ThrustPer_Sat[8];
    real_T b_maxval[8];
    real_T prev_duty_cycles[8];
    real_T rtb_TmpSignalConversionAtSFun_a[7];
    real_T rtb_TmpSignalConversionAtSFun_o[7];
    real_T z_bar[7];
    real_T BLACK_CTL_Input[6];
    real_T BLACK_Estimated_States[6];
    real_T BLUE_Estimated_States[6];
    real_T Chaser[6];
    real_T rtb_y_d[6];
    real_T rtb_y_fj[6];
    real_T rtb_y_mu[6];
    real_T rtb_y_p[6];
    real_T rtb_y_pc[6];
    real_T a[4];
    real_T q[4];
    real_T rtb_MatrixConcatenate[4];
    real_T rtb_q_k[4];
    real_T rtb_y_i1[4];
    real_T ARM_Controls[3];
    real_T BLACK_Controls[3];
    real_T BLACK_Path[3];
    real_T RED_Controls[3];
    real_T RED_Path[3];
    real_T Red_x[3];
    real_T axis[3];
    real_T b[3];
    real_T d_a[3];
    real_T d_a_0[3];
    real_T d_a_1[3];
    real_T rtb_y_fe[3];
    real_T b_y_tmp[2];
    real_T c_y_tmp[2];
    real_T e_in[2];
    real_T ARM_Path_idx_0;
    real_T ARM_Path_idx_1;
    real_T ARM_Path_idx_2;
    real_T BLUE_Path_idx_0;
    real_T BLUE_Path_idx_1;
    real_T BLUE_Path_idx_2;
    real_T H_tmp_0;
    real_T b_norm;
    real_T dt;
    real_T e_in_0;
    real_T e_in_tmp;
    real_T rtb_TSamp;
    real_T rtb_TSamp_e;
    real_T rtb_TSamp_h;
    real_T rtb_TSamp_jb;
    real_T rtb_TSamp_lb;
    real_T rtb_TSamp_ne;
    real_T rtb_TSamp_o;
    real_T rtb_y_eu;
    real_T rtb_y_gs;
    real_T sampleTime;
    real_T sampleTime_0;
    real_T sampleTime_1;
    int32_T ipiv[6];
    int32_T BLACK_Estimated_Covar_tmp;
    int32_T i;
    int32_T jBcol;
    int32_T kBcol;
    int32_T nz;
    int32_T r2;
    int32_T r3;
    int32_T rtb_StartClock;
    int32_T rtemp;
    int32_T samplesRead;
    int32_T samplesRead_0;
    int32_T samplesRead_1;
    char_T *sErr;
    int8_T QMEKFP_tmp[144];
    int8_T F_tmp_1[36];
    int8_T F_tmp_2[36];
    int8_T H_tmp[36];
    int8_T v_tmp[18];
    int8_T F_tmp[9];
    int8_T rtAction;
    int8_T rtPrevAction;
    int8_T v_tmp_0;
    uint8_T b_output[6];
    uint8_T b_output_0[6];
    uint8_T b_status;
    uint8_T slaveAddress;
    boolean_T x[8];
    boolean_T RelationalOperator_i[3];
    boolean_T c_b[3];
    boolean_T rEQ0;
    boolean_T rejectPose;
    static const int8_T d_b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    static const int8_T c[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
      0, 1 };

    static const real_T f_b[9] = { 0.0001, 0.0, 0.0, 0.0, 0.0001, 0.0, 0.0, 0.0,
      1.0E-7 };

    static const int8_T b_a[18] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
      0, 0, 0 };

    static const int8_T d[18] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
      0, 0 };

    static const real_T g_b[9] = { 1.0E-7, 0.0, 0.0, 0.0, 1.0E-7, 0.0, 0.0, 0.0,
      1.0E-7 };

    static const int8_T e[36] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
      0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

    static const int8_T b_0[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
      1 };

    static const int8_T b_1[8] = { -1, -1, 0, 0, 1, 1, 0, 0 };

    static const int8_T c_0[8] = { 0, 0, 1, 1, 0, 0, -1, -1 };

    static const real_T c_1[27] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2,
      0.2, 0.2, 0.2 };

    static const int8_T e_0[36] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    static const int8_T d_0[36] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,
      0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    static const real_T b_Q[144] = { 1.0E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 1.0E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 1.0E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 1.0E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 1.0E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      1.0E-10, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      1.0E-10, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      1.0E-10, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      1.0E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-7,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-7 };

    static const int8_T f[36] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    static const int8_T g[144] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 1 };

    static const real_T b_R[36] = { 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001 };

    static const int8_T b_2[36] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    static const real_T b_Q_0[144] = { 0.01, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 1.0E-10, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      1.0E-10, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      1.0E-10, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      1.0E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-7,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-7, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0001, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0001, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0001 };

    static const real_T b_R_0[36] = { 0.006, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.006,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.006, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001 };

    int32_T exitg2;
    const int8_T *QMEKFP_tmp_2;
    boolean_T exitg1;

    // DataStoreRead: '<S19>/Data Store Read6'
    rtb_DataStoreRead6 = MPC_DW.Univ_Time;

    // Sum: '<S19>/Subtract' incorporates:
    //   DataStoreWrite: '<Root>/Data Store Write'
    //   Delay: '<S19>/Delay'

    dt = rtb_DataStoreRead6 - MPC_DW.Delay_DSTATE;

    // Outputs for IfAction SubSystem: '<S2>/Custom PPL (ARM)' incorporates:
    //   ActionPort: '<S63>/Action Port'

    // If: '<S2>/If3' incorporates:
    //   DataStoreRead: '<S73>/Data Store Read'
    //   DataStoreWrite: '<S2>/Data Store Write9'

    ARM_Path_idx_0 = MPC_DW.ARM_Desired_States[0];
    ARM_Path_idx_1 = MPC_DW.ARM_Desired_States[1];
    ARM_Path_idx_2 = MPC_DW.ARM_Desired_States[2];

    // End of Outputs for SubSystem: '<S2>/Custom PPL (ARM)'

    // If: '<S2>/If1' incorporates:
    //   DataStoreRead: '<S2>/Data Store Read1'

    if (MPC_DW.BLACK_Path_Planner_Selection == 1.0) {
      // Outputs for IfAction SubSystem: '<S2>/Default APF PPL (BLACK)' incorporates:
      //   ActionPort: '<S67>/Action Port'

      // Concatenate: '<S79>/Matrix Concatenate' incorporates:
      //   DataStoreRead: '<S80>/Data Store Read1'
      //   DataStoreRead: '<S81>/Data Store Read2'

      rtb_MatrixConcatenate[0] = MPC_DW.BLUE_Measured_States[0];
      rtb_MatrixConcatenate[1] = MPC_DW.RED_Measured_States[0];
      rtb_MatrixConcatenate[2] = MPC_DW.BLUE_Measured_States[1];
      rtb_MatrixConcatenate[3] = MPC_DW.RED_Measured_States[1];

      // DataStoreWrite: '<S2>/Data Store Write3' incorporates:
      //   Constant: '<S67>/Angular Gain'
      //   Constant: '<S67>/Attractive Gain'
      //   Constant: '<S67>/Influence Range'
      //   Constant: '<S67>/Repulsive Gain'
      //   DataStoreRead: '<S67>/RED_Px'
      //   DataStoreRead: '<S77>/RED_Px'
      //   MATLAB Function: '<S67>/MATLAB Function'

      BLACK_Path[0] = MPC_DW.BLACK_Measured_States[0];
      BLACK_Path[1] = MPC_DW.BLACK_Measured_States[1];
      BLACK_Path[2] = MPC_DW.BLACK_Measured_States[2];
      MPC_MATLABFunction(MPC_DW.BLACK_Desired_States, rtb_MatrixConcatenate,
                         MPC_P.AttractiveGain_Value_i,
                         MPC_P.RepulsiveGain_Value_k,
                         MPC_P.InfluenceRange_Value_d, MPC_P.AngularGain_Value_l,
                         BLACK_Path);

      // End of Outputs for SubSystem: '<S2>/Default APF PPL (BLACK)'
    } else {
      // Outputs for IfAction SubSystem: '<S2>/Disable PPL (BLACK)' incorporates:
      //   ActionPort: '<S70>/Action Port'

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLACK)' incorporates:
      //   ActionPort: '<S64>/Action Port'

      // DataStoreWrite: '<S2>/Data Store Write3' incorporates:
      //   DataStoreRead: '<S74>/BLACK_Px'
      //   DataStoreRead: '<S88>/BLACK_Px'

      BLACK_Path[0] = MPC_DW.BLACK_Desired_States[0];
      BLACK_Path[1] = MPC_DW.BLACK_Desired_States[1];
      BLACK_Path[2] = MPC_DW.BLACK_Desired_States[2];

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLACK)'
      // End of Outputs for SubSystem: '<S2>/Disable PPL (BLACK)'
    }

    // End of If: '<S2>/If1'

    // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
    //   ActionPort: '<S65>/Action Port'

    // If: '<S2>/If2' incorporates:
    //   DataStoreRead: '<S75>/Data Store Read4'
    //   DataStoreWrite: '<S2>/Data Store Write6'

    BLUE_Path_idx_0 = MPC_DW.BLUE_Desired_States[0];
    BLUE_Path_idx_1 = MPC_DW.BLUE_Desired_States[1];
    BLUE_Path_idx_2 = MPC_DW.BLUE_Desired_States[2];

    // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

    // If: '<S2>/If' incorporates:
    //   DataStoreRead: '<S2>/Data Store Read'

    if (MPC_DW.RED_Path_Planner_Selection == 1.0) {
      // Outputs for IfAction SubSystem: '<S2>/Default APF PPL (RED)' incorporates:
      //   ActionPort: '<S68>/Action Port'

      // Concatenate: '<S84>/Matrix Concatenate' incorporates:
      //   DataStoreRead: '<S85>/BLACK Measured States '
      //   DataStoreRead: '<S86>/Data Store Read1'

      rtb_MatrixConcatenate[0] = MPC_DW.BLUE_Measured_States[0];
      rtb_MatrixConcatenate[1] = MPC_DW.BLACK_Measured_States[0];
      rtb_MatrixConcatenate[2] = MPC_DW.BLUE_Measured_States[1];
      rtb_MatrixConcatenate[3] = MPC_DW.BLACK_Measured_States[1];

      // DataStoreWrite: '<S2>/Data Store Write' incorporates:
      //   Constant: '<S68>/Angular Gain'
      //   Constant: '<S68>/Attractive Gain'
      //   Constant: '<S68>/Influence Range'
      //   Constant: '<S68>/Repulsive Gain'
      //   DataStoreRead: '<S68>/RED_Px'
      //   DataStoreRead: '<S82>/Data Store Read2'
      //   MATLAB Function: '<S68>/MATLAB Function'

      RED_Path[0] = MPC_DW.RED_Measured_States[0];
      RED_Path[1] = MPC_DW.RED_Measured_States[1];
      RED_Path[2] = MPC_DW.RED_Measured_States[2];
      MPC_MATLABFunction(MPC_DW.RED_Desired_States, rtb_MatrixConcatenate,
                         MPC_P.AttractiveGain_Value, MPC_P.RepulsiveGain_Value,
                         MPC_P.InfluenceRange_Value, MPC_P.AngularGain_Value,
                         RED_Path);

      // End of Outputs for SubSystem: '<S2>/Default APF PPL (RED)'
    } else {
      // Outputs for IfAction SubSystem: '<S2>/Disable PPL (RED)' incorporates:
      //   ActionPort: '<S72>/Action Port'

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (RED)' incorporates:
      //   ActionPort: '<S66>/Action Port'

      // DataStoreWrite: '<S2>/Data Store Write' incorporates:
      //   DataStoreRead: '<S76>/RED_Px'
      //   DataStoreRead: '<S90>/RED_Px'

      RED_Path[0] = MPC_DW.RED_Desired_States[0];
      RED_Path[1] = MPC_DW.RED_Desired_States[1];
      RED_Path[2] = MPC_DW.RED_Desired_States[2];

      // End of Outputs for SubSystem: '<S2>/Custom PPL (RED)'
      // End of Outputs for SubSystem: '<S2>/Disable PPL (RED)'
    }

    // End of If: '<S2>/If'

    // If: '<S4>/If1' incorporates:
    //   DataStoreRead: '<S4>/Data Store Read3'

    if (MPC_DW.BLACK_Control_Law_Enabler == 1.0) {
      // Outputs for IfAction SubSystem: '<S4>/Default PD Control (BLACK)' incorporates:
      //   ActionPort: '<S129>/Action Port'

      // DataStoreWrite: '<S4>/BLACK Controls'
      MPC_DefaultPDControlBLACK(BLACK_Controls, BLACK_CTL_Input,
        MPC_DW.BLACK_Measured_States, BLACK_Path, &MPC_DW.DefaultPDControlBLACK,
        &MPC_P.DefaultPDControlBLACK);

      // End of Outputs for SubSystem: '<S4>/Default PD Control (BLACK)'
    } else if (MPC_DW.BLACK_Control_Law_Enabler == 2.0) {
      // Outputs for IfAction SubSystem: '<S4>/Default LQR Control (BLACK)' incorporates:
      //   ActionPort: '<S125>/Action Port'

      // DataStoreWrite: '<S4>/BLACK Controls'
      MPC_DefaultPDControlBLACK(BLACK_Controls, BLACK_CTL_Input,
        MPC_DW.BLACK_Measured_States, BLACK_Path, &MPC_DW.DefaultLQRControlBLACK,
        &MPC_P.DefaultLQRControlBLACK);

      // End of Outputs for SubSystem: '<S4>/Default LQR Control (BLACK)'
    } else {
      // Outputs for IfAction SubSystem: '<S4>/Disable Thrusters (BLACK)' incorporates:
      //   ActionPort: '<S133>/Action Port'

      // DataStoreWrite: '<S133>/Data Store Write' incorporates:
      //   MATLAB Function: '<S133>/MATLAB Function'

      for (i = 0; i < 6; i++) {
        BLACK_CTL_Input[i] = 0.0;
      }

      // End of DataStoreWrite: '<S133>/Data Store Write'

      // DataStoreWrite: '<S4>/BLACK Controls' incorporates:
      //   Constant: '<S133>/Zero'
      //   SignalConversion generated from: '<S133>/u'

      BLACK_Controls[0] = MPC_P.Zero_Value;
      BLACK_Controls[1] = MPC_P.Zero_Value;
      BLACK_Controls[2] = MPC_P.Zero_Value;

      // End of Outputs for SubSystem: '<S4>/Disable Thrusters (BLACK)'
    }

    // End of If: '<S4>/If1'

    // If: '<S4>/If2' incorporates:
    //   DataStoreRead: '<S4>/Data Store Read2'

    if (MPC_DW.BLUE_Control_Law_Enabler == 1.0) {
      // Outputs for IfAction SubSystem: '<S4>/Default PD Control (BLUE)' incorporates:
      //   ActionPort: '<S130>/Action Port'

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S65>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S130>/Data Store Read2'
      //   DataStoreRead: '<S75>/Data Store Read4'
      //   MATLAB Function: '<S165>/MATLAB Function'
      //   SampleTimeMath: '<S166>/TSamp'
      //
      //  About '<S166>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      MPC_MATLABFunction_m(MPC_DW.BLUE_Desired_States[2],
                           MPC_DW.BLUE_Measured_States[2], &rtb_TSamp_ne);
      rtb_TSamp_o = MPC_DW.BLUE_Desired_States[0] * MPC_P.TSamp_WtEt_p;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Sum: '<S166>/Diff' incorporates:
      //   UnitDelay: '<S166>/UD'
      //
      //  Block description for '<S166>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S166>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_o = rtb_TSamp_o - MPC_DW.UD_DSTATE_o;

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S65>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S75>/Data Store Read4'
      //   SampleTimeMath: '<S167>/TSamp'
      //
      //  About '<S167>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_h = MPC_DW.BLUE_Desired_States[1] * MPC_P.TSamp_WtEt_o;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Sum: '<S167>/Diff' incorporates:
      //   UnitDelay: '<S167>/UD'
      //
      //  Block description for '<S167>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S167>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_n = rtb_TSamp_h - MPC_DW.UD_DSTATE_n;

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S65>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S75>/Data Store Read4'
      //   SampleTimeMath: '<S168>/TSamp'
      //
      //  About '<S168>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_lb = MPC_DW.BLUE_Desired_States[2] * MPC_P.TSamp_WtEt_px;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Sum: '<S168>/Diff' incorporates:
      //   UnitDelay: '<S168>/UD'
      //
      //  Block description for '<S168>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S168>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_hu = rtb_TSamp_lb - MPC_DW.UD_DSTATE_hu;

      // Sum: '<S130>/Subtract7' incorporates:
      //   DataStoreRead: '<S130>/Data Store Read2'
      //   UnitDelay: '<S166>/UD'
      //
      //  Block description for '<S166>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_o = MPC_DW.BLUE_Measured_States[3] - MPC_DW.UD_DSTATE_o;

      // Sum: '<S130>/Subtract6' incorporates:
      //   DataStoreRead: '<S130>/Data Store Read2'
      //   UnitDelay: '<S167>/UD'
      //
      //  Block description for '<S167>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_n = MPC_DW.BLUE_Measured_States[4] - MPC_DW.UD_DSTATE_n;

      // Sum: '<S130>/Subtract8' incorporates:
      //   DataStoreRead: '<S130>/Data Store Read2'
      //   UnitDelay: '<S168>/UD'
      //
      //  Block description for '<S168>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_hu = MPC_DW.BLUE_Measured_States[5] - MPC_DW.UD_DSTATE_hu;

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S65>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S130>/Data Store Read2'
      //   DataStoreRead: '<S75>/Data Store Read4'
      //   Gain: '<S130>/Gain'
      //   Gain: '<S130>/Gain1'
      //   Gain: '<S130>/Gain3'
      //   Gain: '<S130>/Gain4'
      //   Gain: '<S130>/Gain6'
      //   Gain: '<S130>/Gain7'
      //   Merge: '<S4>/Merge2'
      //   Sum: '<S130>/Subtract4'
      //   Sum: '<S130>/Subtract5'
      //   Sum: '<S130>/Sum'
      //   Sum: '<S130>/Sum1'
      //   UnitDelay: '<S166>/UD'
      //   UnitDelay: '<S167>/UD'
      //
      //  Block description for '<S166>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S167>/UD':
      //
      //   Store in Global RAM

      MPC_B.Merge2[0] = ((MPC_DW.BLUE_Measured_States[0] -
                          MPC_DW.BLUE_Desired_States[0]) * MPC_P.Kp_xblue +
                         MPC_P.Kd_xblue * MPC_DW.UD_DSTATE_o) * MPC_P.Gain6_Gain;
      MPC_B.Merge2[1] = ((MPC_DW.BLUE_Measured_States[1] -
                          MPC_DW.BLUE_Desired_States[1]) * MPC_P.Kp_yblue +
                         MPC_P.Kd_yblue * MPC_DW.UD_DSTATE_n) * MPC_P.Gain7_Gain;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Gain: '<S130>/Gain8' incorporates:
      //   Gain: '<S130>/Gain2'
      //   Gain: '<S130>/Gain5'
      //   Merge: '<S4>/Merge2'
      //   Sum: '<S130>/Sum2'
      //   UnitDelay: '<S168>/UD'
      //
      //  Block description for '<S168>/UD':
      //
      //   Store in Global RAM

      MPC_B.Merge2[2] = (MPC_P.Kp_tblue * rtb_TSamp_ne + MPC_P.Kd_tblue *
                         MPC_DW.UD_DSTATE_hu) * MPC_P.Gain8_Gain;

      // Update for UnitDelay: '<S166>/UD'
      //
      //  Block description for '<S166>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_o = rtb_TSamp_o;

      // Update for UnitDelay: '<S167>/UD'
      //
      //  Block description for '<S167>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_n = rtb_TSamp_h;

      // Update for UnitDelay: '<S168>/UD'
      //
      //  Block description for '<S168>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_hu = rtb_TSamp_lb;

      // End of Outputs for SubSystem: '<S4>/Default PD Control (BLUE)'
    } else if (MPC_DW.BLUE_Control_Law_Enabler == 2.0) {
      // Outputs for IfAction SubSystem: '<S4>/Default LQR Control (BLUE)' incorporates:
      //   ActionPort: '<S126>/Action Port'

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S65>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S126>/Data Store Read3'
      //   DataStoreRead: '<S75>/Data Store Read4'
      //   MATLAB Function: '<S142>/MATLAB Function'
      //   Product: '<S126>/Matrix Multiply'
      //   SampleTimeMath: '<S143>/TSamp'
      //
      //  About '<S143>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      MPC_MATLABFunction_m(MPC_DW.BLUE_Desired_States[2],
                           MPC_DW.BLUE_Measured_States_RAW[2],
                           &BLACK_Estimated_States[2]);
      rtb_TSamp_ne = MPC_DW.BLUE_Desired_States[0] * MPC_P.TSamp_WtEt_f;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Sum: '<S143>/Diff' incorporates:
      //   UnitDelay: '<S143>/UD'
      //
      //  Block description for '<S143>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S143>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_l = rtb_TSamp_ne - MPC_DW.UD_DSTATE_l;

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S65>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S75>/Data Store Read4'
      //   SampleTimeMath: '<S144>/TSamp'
      //
      //  About '<S144>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_o = MPC_DW.BLUE_Desired_States[1] * MPC_P.TSamp_WtEt_eh;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Sum: '<S144>/Diff' incorporates:
      //   UnitDelay: '<S144>/UD'
      //
      //  Block description for '<S144>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S144>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_k = rtb_TSamp_o - MPC_DW.UD_DSTATE_k;

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S65>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S75>/Data Store Read4'
      //   SampleTimeMath: '<S145>/TSamp'
      //
      //  About '<S145>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_h = MPC_DW.BLUE_Desired_States[2] * MPC_P.TSamp_WtEt_i;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

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

      MPC_DW.UD_DSTATE_h = rtb_TSamp_h - MPC_DW.UD_DSTATE_h;

      // Sum: '<S126>/Subtract7' incorporates:
      //   DataStoreRead: '<S126>/Data Store Read3'
      //   UnitDelay: '<S143>/UD'
      //
      //  Block description for '<S143>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_l = MPC_DW.BLUE_Measured_States_RAW[3] -
        MPC_DW.UD_DSTATE_l;

      // Sum: '<S126>/Subtract6' incorporates:
      //   DataStoreRead: '<S126>/Data Store Read3'
      //   UnitDelay: '<S144>/UD'
      //
      //  Block description for '<S144>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_k = MPC_DW.BLUE_Measured_States_RAW[4] -
        MPC_DW.UD_DSTATE_k;

      // Sum: '<S126>/Subtract8' incorporates:
      //   DataStoreRead: '<S126>/Data Store Read3'
      //   UnitDelay: '<S145>/UD'
      //
      //  Block description for '<S145>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_h = MPC_DW.BLUE_Measured_States_RAW[5] -
        MPC_DW.UD_DSTATE_h;
      for (rtemp = 0; rtemp < 18; rtemp++) {
        // Product: '<S126>/Matrix Multiply' incorporates:
        //   Constant: '<S126>/Constant2'

        K[rtemp] = -MPC_P.K_BLUE[rtemp];
      }

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S65>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S126>/Data Store Read3'
      //   DataStoreRead: '<S75>/Data Store Read4'
      //   Product: '<S126>/Matrix Multiply'
      //   Reshape: '<S126>/Reshape1'
      //   Sum: '<S126>/Subtract4'
      //   Sum: '<S126>/Subtract5'

      BLACK_Estimated_States[0] = MPC_DW.BLUE_Measured_States_RAW[0] -
        MPC_DW.BLUE_Desired_States[0];
      BLACK_Estimated_States[1] = MPC_DW.BLUE_Measured_States_RAW[1] -
        MPC_DW.BLUE_Desired_States[1];

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Product: '<S126>/Matrix Multiply' incorporates:
      //   Reshape: '<S126>/Reshape2'
      //   UnitDelay: '<S143>/UD'
      //   UnitDelay: '<S144>/UD'
      //   UnitDelay: '<S145>/UD'
      //
      //  Block description for '<S143>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S144>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S145>/UD':
      //
      //   Store in Global RAM

      BLACK_Estimated_States[3] = MPC_DW.UD_DSTATE_l;
      BLACK_Estimated_States[4] = MPC_DW.UD_DSTATE_k;
      BLACK_Estimated_States[5] = MPC_DW.UD_DSTATE_h;
      for (rtemp = 0; rtemp < 3; rtemp++) {
        // Product: '<S126>/Matrix Multiply' incorporates:
        //   Merge: '<S4>/Merge2'

        rtb_TSamp_lb = 0.0;
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          // Merge: '<S4>/Merge2' incorporates:
          //   Product: '<S126>/Matrix Multiply'
          //   Reshape: '<S126>/Reshape4'

          rtb_TSamp_lb += K[3 * BLACK_Estimated_Covar_tmp + rtemp] *
            BLACK_Estimated_States[BLACK_Estimated_Covar_tmp];
        }

        // Merge: '<S4>/Merge2' incorporates:
        //   Product: '<S126>/Matrix Multiply'

        MPC_B.Merge2[rtemp] = rtb_TSamp_lb;
      }

      // Update for UnitDelay: '<S143>/UD'
      //
      //  Block description for '<S143>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_l = rtb_TSamp_ne;

      // Update for UnitDelay: '<S144>/UD'
      //
      //  Block description for '<S144>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_k = rtb_TSamp_o;

      // Update for UnitDelay: '<S145>/UD'
      //
      //  Block description for '<S145>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_h = rtb_TSamp_h;

      // End of Outputs for SubSystem: '<S4>/Default LQR Control (BLUE)'
    } else {
      // Outputs for IfAction SubSystem: '<S4>/Disable Thrusters (BLUE)' incorporates:
      //   ActionPort: '<S134>/Action Port'

      // Merge: '<S4>/Merge2' incorporates:
      //   Constant: '<S134>/Zero'
      //   SignalConversion generated from: '<S134>/Out1'

      MPC_B.Merge2[0] = MPC_P.Zero_Value_j;
      MPC_B.Merge2[1] = MPC_P.Zero_Value_j;
      MPC_B.Merge2[2] = MPC_P.Zero_Value_j;

      // End of Outputs for SubSystem: '<S4>/Disable Thrusters (BLUE)'
    }

    // End of If: '<S4>/If2'

    // DataStoreWrite: '<S4>/BLUE Controls'
    rtb_TSamp_o = MPC_B.Merge2[0];
    rtb_TSamp_h = MPC_B.Merge2[1];
    rtb_TSamp_ne = MPC_B.Merge2[2];

    // If: '<S4>/If3' incorporates:
    //   DataStoreRead: '<S4>/Data Store Read5'

    if (MPC_DW.ARM_Control_Law_Enabler == 1.0) {
      // Outputs for IfAction SubSystem: '<S4>/Default PD (ARM)' incorporates:
      //   ActionPort: '<S128>/Action Port'

      // DataStoreWrite: '<S128>/Data Store Write12' incorporates:
      //   Constant: '<S128>/Constant7'

      MPC_DW.ARM_Control_Mode = MPC_P.Constant7_Value_a;

      // If: '<S128>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
      //   DataStoreRead: '<S128>/Data Store Read4'

      if (MPC_DW.isSim == 1.0) {
        // Outputs for IfAction SubSystem: '<S128>/Simulated Position Controller' incorporates:
        //   ActionPort: '<S153>/Action Port'

        // Outputs for IfAction SubSystem: '<S2>/Custom PPL (ARM)' incorporates:
        //   ActionPort: '<S63>/Action Port'

        // If: '<S2>/If3' incorporates:
        //   DataStoreRead: '<S153>/Data Store Read2'
        //   DataStoreRead: '<S73>/Data Store Read'
        //   Sum: '<S153>/Subtract3'

        rtb_TSamp_lb = MPC_DW.ARM_Desired_States[1] -
          MPC_DW.ARM_Measured_States[1];

        // End of Outputs for SubSystem: '<S2>/Custom PPL (ARM)'

        // SampleTimeMath: '<S157>/TSamp'
        //
        //  About '<S157>/TSamp':
        //   y = u * K where K = 1 / ( w * Ts )
        //
        rtb_TSamp = rtb_TSamp_lb * MPC_P.TSamp_WtEt_pu;

        // Sum: '<S154>/Sum3' incorporates:
        //   Gain: '<S154>/kd_elarm'
        //   Gain: '<S154>/kp_elarm'
        //   Sum: '<S157>/Diff'
        //   UnitDelay: '<S157>/UD'
        //
        //  Block description for '<S157>/Diff':
        //
        //   Add in CPU
        //
        //  Block description for '<S157>/UD':
        //
        //   Store in Global RAM

        MPC_DW.UD_DSTATE = (rtb_TSamp - MPC_DW.UD_DSTATE) * MPC_P.Kd_elarm +
          MPC_P.Kp_elarm * rtb_TSamp_lb;

        // Outputs for IfAction SubSystem: '<S2>/Custom PPL (ARM)' incorporates:
        //   ActionPort: '<S63>/Action Port'

        // If: '<S2>/If3' incorporates:
        //   DataStoreRead: '<S153>/Data Store Read2'
        //   DataStoreRead: '<S73>/Data Store Read'
        //   Sum: '<S153>/Subtract2'

        rtb_TSamp_lb = MPC_DW.ARM_Desired_States[0] -
          MPC_DW.ARM_Measured_States[0];

        // End of Outputs for SubSystem: '<S2>/Custom PPL (ARM)'

        // SampleTimeMath: '<S158>/TSamp'
        //
        //  About '<S158>/TSamp':
        //   y = u * K where K = 1 / ( w * Ts )
        //
        rtb_TSamp_e = rtb_TSamp_lb * MPC_P.TSamp_WtEt_f0;

        // Sum: '<S155>/Sum3' incorporates:
        //   Gain: '<S155>/kd_sharm'
        //   Gain: '<S155>/kp_sharm'
        //   Sum: '<S158>/Diff'
        //   UnitDelay: '<S158>/UD'
        //
        //  Block description for '<S158>/Diff':
        //
        //   Add in CPU
        //
        //  Block description for '<S158>/UD':
        //
        //   Store in Global RAM

        MPC_DW.UD_DSTATE_e = (rtb_TSamp_e - MPC_DW.UD_DSTATE_e) * MPC_P.Kd_sharm
          + MPC_P.Kp_sharm * rtb_TSamp_lb;

        // Outputs for IfAction SubSystem: '<S2>/Custom PPL (ARM)' incorporates:
        //   ActionPort: '<S63>/Action Port'

        // If: '<S2>/If3' incorporates:
        //   DataStoreRead: '<S153>/Data Store Read2'
        //   DataStoreRead: '<S73>/Data Store Read'
        //   Sum: '<S153>/Subtract4'

        rtb_TSamp_lb = MPC_DW.ARM_Desired_States[2] -
          MPC_DW.ARM_Measured_States[2];

        // End of Outputs for SubSystem: '<S2>/Custom PPL (ARM)'

        // SampleTimeMath: '<S159>/TSamp'
        //
        //  About '<S159>/TSamp':
        //   y = u * K where K = 1 / ( w * Ts )
        //
        rtb_TSamp_jb = rtb_TSamp_lb * MPC_P.TSamp_WtEt_nz;

        // Sum: '<S156>/Sum3' incorporates:
        //   Gain: '<S156>/kd_wrarm'
        //   Gain: '<S156>/kp_wrarm'
        //   Sum: '<S159>/Diff'
        //   UnitDelay: '<S159>/UD'
        //
        //  Block description for '<S159>/Diff':
        //
        //   Add in CPU
        //
        //  Block description for '<S159>/UD':
        //
        //   Store in Global RAM

        MPC_DW.UD_DSTATE_a = (rtb_TSamp_jb - MPC_DW.UD_DSTATE_a) *
          MPC_P.Kd_wrarm + MPC_P.Kp_wrarm * rtb_TSamp_lb;

        // Saturate: '<S153>/Saturation' incorporates:
        //   UnitDelay: '<S158>/UD'
        //
        //  Block description for '<S158>/UD':
        //
        //   Store in Global RAM

        if (MPC_DW.UD_DSTATE_e > MPC_P.Tz_lim_sharm) {
          // DataStoreWrite: '<S4>/Data Store Write9' incorporates:
          //   Merge: '<S128>/Merge3'

          ARM_Controls[0] = MPC_P.Tz_lim_sharm;
        } else if (MPC_DW.UD_DSTATE_e < -MPC_P.Tz_lim_sharm) {
          // DataStoreWrite: '<S4>/Data Store Write9' incorporates:
          //   Merge: '<S128>/Merge3'

          ARM_Controls[0] = -MPC_P.Tz_lim_sharm;
        } else {
          // DataStoreWrite: '<S4>/Data Store Write9' incorporates:
          //   Merge: '<S128>/Merge3'

          ARM_Controls[0] = MPC_DW.UD_DSTATE_e;
        }

        // End of Saturate: '<S153>/Saturation'

        // Saturate: '<S153>/Saturation1' incorporates:
        //   UnitDelay: '<S157>/UD'
        //
        //  Block description for '<S157>/UD':
        //
        //   Store in Global RAM

        if (MPC_DW.UD_DSTATE > MPC_P.Tz_lim_elarm) {
          // DataStoreWrite: '<S4>/Data Store Write9' incorporates:
          //   Merge: '<S128>/Merge4'

          ARM_Controls[1] = MPC_P.Tz_lim_elarm;
        } else if (MPC_DW.UD_DSTATE < -MPC_P.Tz_lim_elarm) {
          // DataStoreWrite: '<S4>/Data Store Write9' incorporates:
          //   Merge: '<S128>/Merge4'

          ARM_Controls[1] = -MPC_P.Tz_lim_elarm;
        } else {
          // DataStoreWrite: '<S4>/Data Store Write9' incorporates:
          //   Merge: '<S128>/Merge4'

          ARM_Controls[1] = MPC_DW.UD_DSTATE;
        }

        // End of Saturate: '<S153>/Saturation1'

        // Saturate: '<S153>/Saturation3' incorporates:
        //   UnitDelay: '<S159>/UD'
        //
        //  Block description for '<S159>/UD':
        //
        //   Store in Global RAM

        if (MPC_DW.UD_DSTATE_a > MPC_P.Tz_lim_wrarm) {
          // DataStoreWrite: '<S4>/Data Store Write9' incorporates:
          //   Merge: '<S128>/Merge5'

          ARM_Controls[2] = MPC_P.Tz_lim_wrarm;
        } else if (MPC_DW.UD_DSTATE_a < -MPC_P.Tz_lim_wrarm) {
          // DataStoreWrite: '<S4>/Data Store Write9' incorporates:
          //   Merge: '<S128>/Merge5'

          ARM_Controls[2] = -MPC_P.Tz_lim_wrarm;
        } else {
          // DataStoreWrite: '<S4>/Data Store Write9' incorporates:
          //   Merge: '<S128>/Merge5'

          ARM_Controls[2] = MPC_DW.UD_DSTATE_a;
        }

        // End of Saturate: '<S153>/Saturation3'

        // Update for UnitDelay: '<S157>/UD'
        //
        //  Block description for '<S157>/UD':
        //
        //   Store in Global RAM

        MPC_DW.UD_DSTATE = rtb_TSamp;

        // Update for UnitDelay: '<S158>/UD'
        //
        //  Block description for '<S158>/UD':
        //
        //   Store in Global RAM

        MPC_DW.UD_DSTATE_e = rtb_TSamp_e;

        // Update for UnitDelay: '<S159>/UD'
        //
        //  Block description for '<S159>/UD':
        //
        //   Store in Global RAM

        MPC_DW.UD_DSTATE_a = rtb_TSamp_jb;

        // End of Outputs for SubSystem: '<S128>/Simulated Position Controller'
      } else {
        // Outputs for IfAction SubSystem: '<S128>/Passthrough for Experiment' incorporates:
        //   ActionPort: '<S152>/Action Port'

        // Outputs for IfAction SubSystem: '<S2>/Custom PPL (ARM)' incorporates:
        //   ActionPort: '<S63>/Action Port'

        // If: '<S2>/If3' incorporates:
        //   DataStoreRead: '<S73>/Data Store Read'
        //   DataStoreWrite: '<S4>/Data Store Write9'
        //   Merge: '<S128>/Merge3'
        //   Merge: '<S128>/Merge4'
        //   Merge: '<S128>/Merge5'
        //   SignalConversion generated from: '<S152>/q1_desired'
        //   SignalConversion generated from: '<S152>/q2_desired'
        //   SignalConversion generated from: '<S152>/q3_desired'

        ARM_Controls[0] = MPC_DW.ARM_Desired_States[0];
        ARM_Controls[1] = MPC_DW.ARM_Desired_States[1];
        ARM_Controls[2] = MPC_DW.ARM_Desired_States[2];

        // End of Outputs for SubSystem: '<S2>/Custom PPL (ARM)'
        // End of Outputs for SubSystem: '<S128>/Passthrough for Experiment'
      }

      // End of If: '<S128>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 
      // End of Outputs for SubSystem: '<S4>/Default PD (ARM)'
    } else if (MPC_DW.ARM_Control_Law_Enabler == 2.0) {
      // Outputs for IfAction SubSystem: '<S4>/Custom Control (ARM)' incorporates:
      //   ActionPort: '<S124>/Action Port'

      // DataStoreWrite: '<S4>/Data Store Write9'
      MPC_DisableThrustersRED(ARM_Controls, &MPC_P.CustomControlARM);

      // End of Outputs for SubSystem: '<S4>/Custom Control (ARM)'
    } else {
      // Outputs for IfAction SubSystem: '<S4>/Disable Control (ARM)' incorporates:
      //   ActionPort: '<S132>/Action Port'

      // DataStoreWrite: '<S132>/Data Store Write12' incorporates:
      //   Constant: '<S132>/Constant7'

      MPC_DW.ARM_Control_Mode = MPC_P.Constant7_Value_h;

      // DataStoreWrite: '<S4>/Data Store Write9' incorporates:
      //   Constant: '<S132>/Zero'
      //   SignalConversion generated from: '<S132>/Out1'

      ARM_Controls[0] = MPC_P.Zero_Value_m;
      ARM_Controls[1] = MPC_P.Zero_Value_m;
      ARM_Controls[2] = MPC_P.Zero_Value_m;

      // End of Outputs for SubSystem: '<S4>/Disable Control (ARM)'
    }

    // End of If: '<S4>/If3'

    // If: '<S4>/If' incorporates:
    //   DataStoreRead: '<S4>/Data Store Read1'

    if (MPC_DW.RED_Control_Law_Enabler == 1.0) {
      // Outputs for IfAction SubSystem: '<S4>/Default PD Control (RED)' incorporates:
      //   ActionPort: '<S131>/Action Port'

      // Product: '<S131>/Matrix Multiply' incorporates:
      //   DataStoreRead: '<S131>/Data Store Read2'
      //   DataStoreRead: '<S131>/Data Store Read3'
      //   MATLAB Function: '<S170>/MATLAB Function'

      MPC_MATLABFunction_m(RED_Path[2], MPC_DW.RED_Measured_States[2],
                           &BLUE_Estimated_States[2]);

      // SampleTimeMath: '<S171>/TSamp' incorporates:
      //   DataStoreRead: '<S131>/Data Store Read2'
      //
      //  About '<S171>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp = RED_Path[0] * MPC_P.TSamp_WtEt;

      // Sum: '<S171>/Diff' incorporates:
      //   UnitDelay: '<S171>/UD'
      //
      //  Block description for '<S171>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S171>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_d = rtb_TSamp - MPC_DW.UD_DSTATE_d;

      // SampleTimeMath: '<S172>/TSamp' incorporates:
      //   DataStoreRead: '<S131>/Data Store Read2'
      //
      //  About '<S172>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_e = RED_Path[1] * MPC_P.TSamp_WtEt_l;

      // Sum: '<S172>/Diff' incorporates:
      //   UnitDelay: '<S172>/UD'
      //
      //  Block description for '<S172>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S172>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_j = rtb_TSamp_e - MPC_DW.UD_DSTATE_j;

      // SampleTimeMath: '<S173>/TSamp' incorporates:
      //   DataStoreRead: '<S131>/Data Store Read2'
      //
      //  About '<S173>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_jb = RED_Path[2] * MPC_P.TSamp_WtEt_n;

      // Sum: '<S173>/Diff' incorporates:
      //   UnitDelay: '<S173>/UD'
      //
      //  Block description for '<S173>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S173>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_hb = rtb_TSamp_jb - MPC_DW.UD_DSTATE_hb;

      // Sum: '<S131>/Subtract7' incorporates:
      //   DataStoreRead: '<S131>/Data Store Read3'
      //   UnitDelay: '<S171>/UD'
      //
      //  Block description for '<S171>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_d = MPC_DW.RED_Measured_States[3] - MPC_DW.UD_DSTATE_d;

      // Sum: '<S131>/Subtract6' incorporates:
      //   DataStoreRead: '<S131>/Data Store Read3'
      //   UnitDelay: '<S172>/UD'
      //
      //  Block description for '<S172>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_j = MPC_DW.RED_Measured_States[4] - MPC_DW.UD_DSTATE_j;

      // Sum: '<S131>/Subtract8' incorporates:
      //   DataStoreRead: '<S131>/Data Store Read3'
      //   UnitDelay: '<S173>/UD'
      //
      //  Block description for '<S173>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_hb = MPC_DW.RED_Measured_States[5] - MPC_DW.UD_DSTATE_hb;
      for (rtemp = 0; rtemp < 18; rtemp++) {
        // Product: '<S131>/Matrix Multiply' incorporates:
        //   Constant: '<S131>/Constant2'

        K[rtemp] = -MPC_P.K_BLACK[rtemp];
      }

      // Product: '<S131>/Matrix Multiply' incorporates:
      //   DataStoreRead: '<S131>/Data Store Read2'
      //   DataStoreRead: '<S131>/Data Store Read3'
      //   Reshape: '<S131>/Reshape1'
      //   Reshape: '<S131>/Reshape3'
      //   Sum: '<S131>/Subtract4'
      //   Sum: '<S131>/Subtract5'
      //   UnitDelay: '<S171>/UD'
      //   UnitDelay: '<S172>/UD'
      //   UnitDelay: '<S173>/UD'
      //
      //  Block description for '<S171>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S172>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S173>/UD':
      //
      //   Store in Global RAM

      BLUE_Estimated_States[0] = MPC_DW.RED_Measured_States[0] - RED_Path[0];
      BLUE_Estimated_States[1] = MPC_DW.RED_Measured_States[1] - RED_Path[1];
      BLUE_Estimated_States[3] = MPC_DW.UD_DSTATE_d;
      BLUE_Estimated_States[4] = MPC_DW.UD_DSTATE_j;
      BLUE_Estimated_States[5] = MPC_DW.UD_DSTATE_hb;
      for (rtemp = 0; rtemp < 3; rtemp++) {
        // Product: '<S131>/Matrix Multiply' incorporates:
        //   DataStoreWrite: '<S4>/RED Controls'

        rtb_TSamp_lb = 0.0;
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          // DataStoreWrite: '<S4>/RED Controls' incorporates:
          //   Product: '<S131>/Matrix Multiply'
          //   Reshape: '<S131>/Reshape4'

          rtb_TSamp_lb += K[3 * BLACK_Estimated_Covar_tmp + rtemp] *
            BLUE_Estimated_States[BLACK_Estimated_Covar_tmp];
        }

        // DataStoreWrite: '<S4>/RED Controls' incorporates:
        //   Product: '<S131>/Matrix Multiply'

        RED_Controls[rtemp] = rtb_TSamp_lb;
      }

      // Update for UnitDelay: '<S171>/UD'
      //
      //  Block description for '<S171>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_d = rtb_TSamp;

      // Update for UnitDelay: '<S172>/UD'
      //
      //  Block description for '<S172>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_j = rtb_TSamp_e;

      // Update for UnitDelay: '<S173>/UD'
      //
      //  Block description for '<S173>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_hb = rtb_TSamp_jb;

      // End of Outputs for SubSystem: '<S4>/Default PD Control (RED)'
    } else if (MPC_DW.RED_Control_Law_Enabler == 2.0) {
      // Outputs for IfAction SubSystem: '<S4>/Default LQR Control (RED)' incorporates:
      //   ActionPort: '<S127>/Action Port'

      // Product: '<S127>/Matrix Multiply' incorporates:
      //   DataStoreRead: '<S127>/Data Store Read1'
      //   DataStoreRead: '<S127>/Data Store Read13'
      //   MATLAB Function: '<S147>/MATLAB Function'

      MPC_MATLABFunction_m(RED_Path[2], MPC_DW.RED_Measured_States[2],
                           &BLUE_Estimated_States[2]);

      // SampleTimeMath: '<S148>/TSamp' incorporates:
      //   DataStoreRead: '<S127>/Data Store Read1'
      //
      //  About '<S148>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp = RED_Path[0] * MPC_P.TSamp_WtEt_h;

      // Sum: '<S148>/Diff' incorporates:
      //   UnitDelay: '<S148>/UD'
      //
      //  Block description for '<S148>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S148>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_aq = rtb_TSamp - MPC_DW.UD_DSTATE_aq;

      // SampleTimeMath: '<S149>/TSamp' incorporates:
      //   DataStoreRead: '<S127>/Data Store Read1'
      //
      //  About '<S149>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_e = RED_Path[1] * MPC_P.TSamp_WtEt_e;

      // Sum: '<S149>/Diff' incorporates:
      //   UnitDelay: '<S149>/UD'
      //
      //  Block description for '<S149>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S149>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_p = rtb_TSamp_e - MPC_DW.UD_DSTATE_p;

      // SampleTimeMath: '<S150>/TSamp' incorporates:
      //   DataStoreRead: '<S127>/Data Store Read1'
      //
      //  About '<S150>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_jb = RED_Path[2] * MPC_P.TSamp_WtEt_n3;

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

      MPC_DW.UD_DSTATE_pr = rtb_TSamp_jb - MPC_DW.UD_DSTATE_pr;

      // Sum: '<S127>/Subtract7' incorporates:
      //   DataStoreRead: '<S127>/Data Store Read13'
      //   UnitDelay: '<S148>/UD'
      //
      //  Block description for '<S148>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_aq = MPC_DW.RED_Measured_States[3] - MPC_DW.UD_DSTATE_aq;

      // Sum: '<S127>/Subtract6' incorporates:
      //   DataStoreRead: '<S127>/Data Store Read13'
      //   UnitDelay: '<S149>/UD'
      //
      //  Block description for '<S149>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_p = MPC_DW.RED_Measured_States[4] - MPC_DW.UD_DSTATE_p;

      // Sum: '<S127>/Subtract8' incorporates:
      //   DataStoreRead: '<S127>/Data Store Read13'
      //   UnitDelay: '<S150>/UD'
      //
      //  Block description for '<S150>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_pr = MPC_DW.RED_Measured_States[5] - MPC_DW.UD_DSTATE_pr;
      for (rtemp = 0; rtemp < 18; rtemp++) {
        // Product: '<S127>/Matrix Multiply' incorporates:
        //   Constant: '<S127>/Constant2'

        K[rtemp] = -MPC_P.K_RED[rtemp];
      }

      // Product: '<S127>/Matrix Multiply' incorporates:
      //   DataStoreRead: '<S127>/Data Store Read1'
      //   DataStoreRead: '<S127>/Data Store Read13'
      //   Reshape: '<S127>/Reshape2'
      //   Reshape: '<S127>/Reshape3'
      //   Sum: '<S127>/Subtract4'
      //   Sum: '<S127>/Subtract5'
      //   UnitDelay: '<S148>/UD'
      //   UnitDelay: '<S149>/UD'
      //   UnitDelay: '<S150>/UD'
      //
      //  Block description for '<S148>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S149>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S150>/UD':
      //
      //   Store in Global RAM

      BLUE_Estimated_States[0] = MPC_DW.RED_Measured_States[0] - RED_Path[0];
      BLUE_Estimated_States[1] = MPC_DW.RED_Measured_States[1] - RED_Path[1];
      BLUE_Estimated_States[3] = MPC_DW.UD_DSTATE_aq;
      BLUE_Estimated_States[4] = MPC_DW.UD_DSTATE_p;
      BLUE_Estimated_States[5] = MPC_DW.UD_DSTATE_pr;
      for (rtemp = 0; rtemp < 3; rtemp++) {
        // Product: '<S127>/Matrix Multiply' incorporates:
        //   DataStoreWrite: '<S4>/RED Controls'

        rtb_TSamp_lb = 0.0;
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          // DataStoreWrite: '<S4>/RED Controls' incorporates:
          //   Product: '<S127>/Matrix Multiply'
          //   Reshape: '<S127>/Reshape4'

          rtb_TSamp_lb += K[3 * BLACK_Estimated_Covar_tmp + rtemp] *
            BLUE_Estimated_States[BLACK_Estimated_Covar_tmp];
        }

        // DataStoreWrite: '<S4>/RED Controls' incorporates:
        //   Product: '<S127>/Matrix Multiply'

        RED_Controls[rtemp] = rtb_TSamp_lb;
      }

      // Update for UnitDelay: '<S148>/UD'
      //
      //  Block description for '<S148>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_aq = rtb_TSamp;

      // Update for UnitDelay: '<S149>/UD'
      //
      //  Block description for '<S149>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_p = rtb_TSamp_e;

      // Update for UnitDelay: '<S150>/UD'
      //
      //  Block description for '<S150>/UD':
      //
      //   Store in Global RAM

      MPC_DW.UD_DSTATE_pr = rtb_TSamp_jb;

      // End of Outputs for SubSystem: '<S4>/Default LQR Control (RED)'
    } else if (MPC_DW.RED_Control_Law_Enabler == 3.0) {
      // Outputs for IfAction SubSystem: '<S4>/Model Predictive Control (RED)' incorporates:
      //   ActionPort: '<S136>/Action Port'

      // DataStoreWrite: '<S4>/RED Controls' incorporates:
      //   DataStoreRead: '<S136>/Data Store Read2'

      RED_Controls[0] = MPC_DW.MPC_Controls[0];
      RED_Controls[1] = MPC_DW.MPC_Controls[1];
      RED_Controls[2] = MPC_DW.MPC_Controls[2];

      // End of Outputs for SubSystem: '<S4>/Model Predictive Control (RED)'
    } else {
      // Outputs for IfAction SubSystem: '<S4>/Disable Thrusters (RED)' incorporates:
      //   ActionPort: '<S135>/Action Port'

      // DataStoreWrite: '<S4>/RED Controls'
      MPC_DisableThrustersRED(RED_Controls, &MPC_P.DisableThrustersRED);

      // End of Outputs for SubSystem: '<S4>/Disable Thrusters (RED)'
    }

    // End of If: '<S4>/If'

    // DataStoreRead: '<S12>/Data Store Read'
    memcpy(&rtb_DataStoreRead_p[0], &MPC_DW.RED_Measured_States_RAW[0], 9U *
           sizeof(real_T));

    // MATLAB Function: '<S276>/MATLAB Function1' incorporates:
    //   Delay: '<S276>/Delay2'

    MPC_MATLABFunction1(rtb_DataStoreRead_p, MPC_DW.Delay2_DSTATE, rtb_y_fe);

    // Delay: '<S268>/Delay1'
    for (i = 0; i < 6; i++) {
      MPC_DW.RED_Estimated_States[i] = MPC_DW.Delay1_DSTATE[i];
    }

    // End of Delay: '<S268>/Delay1'

    // Delay: '<S268>/Delay'
    memcpy(&MPC_B.P[0], &MPC_DW.Delay_DSTATE_i[0], 36U * sizeof(real_T));

    // Outputs for IfAction SubSystem: '<S3>/Subsystem' incorporates:
    //   ActionPort: '<S91>/Action Port'

    for (i = 0; i < 9; i++) {
      // Delay: '<S268>/Delay2'
      MPC_B.V[i] = MPC_DW.Delay2_DSTATE_k[i];

      // If: '<S3>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
      //   MATLAB Function: '<S101>/MATLAB Function1'
      //   MATLAB Function: '<S102>/MATLAB Function1'
      //   MATLAB Function: '<S268>/MATLAB Function'
      //   MATLAB Function: '<S92>/MATLAB Function3'
      //   MATLAB Function: '<S92>/MATLAB Function5'
      //   MATLAB Function: '<S92>/MATLAB Function7'
      //   MATLAB Function: '<S97>/MATLAB Function1'
      //   MATLAB Function: '<S98>/MATLAB Function1'

      rtemp = d_b[i];

      // MATLAB Function: '<S268>/MATLAB Function'
      F_tmp[i] = static_cast<int8_T>(rtemp);

      // If: '<S3>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
      //   DataStoreRead: '<S12>/Data Store Read12'
      //   MATLAB Function: '<S101>/MATLAB Function1'
      //   MATLAB Function: '<S102>/MATLAB Function1'
      //   MATLAB Function: '<S268>/MATLAB Function'
      //   MATLAB Function: '<S97>/MATLAB Function1'
      //   MATLAB Function: '<S98>/MATLAB Function1'

      F_tmp_0[i] = dt * static_cast<real_T>(rtemp);
    }

    // End of Outputs for SubSystem: '<S3>/Subsystem'

    // MATLAB Function: '<S268>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S12>/Data Store Read12'
    //   DataStoreRead: '<S12>/Data Store Read6'
    //   DataStoreWrite: '<S12>/Data Store Write1'

    for (rtemp = 0; rtemp < 3; rtemp++) {
      BLACK_Estimated_Covar[6 * rtemp] = F_tmp[3 * rtemp];
      i = (rtemp + 3) * 6;
      BLACK_Estimated_Covar[i] = F_tmp_0[3 * rtemp];
      BLACK_Estimated_Covar_tmp = 3 * rtemp + 1;
      BLACK_Estimated_Covar[6 * rtemp + 1] = F_tmp[BLACK_Estimated_Covar_tmp];
      BLACK_Estimated_Covar[i + 1] = F_tmp_0[BLACK_Estimated_Covar_tmp];
      BLACK_Estimated_Covar_tmp = 3 * rtemp + 2;
      BLACK_Estimated_Covar[6 * rtemp + 2] = F_tmp[BLACK_Estimated_Covar_tmp];
      BLACK_Estimated_Covar[i + 2] = F_tmp_0[BLACK_Estimated_Covar_tmp];
    }

    for (rtemp = 0; rtemp < 6; rtemp++) {
      BLACK_Estimated_Covar[6 * rtemp + 3] = c[3 * rtemp];
      BLACK_Estimated_Covar[6 * rtemp + 4] = c[3 * rtemp + 1];
      BLACK_Estimated_Covar[6 * rtemp + 5] = c[3 * rtemp + 2];
    }

    Red_x[0] = 1.0 / MPC_P.mRED;
    Red_x[1] = 1.0 / MPC_P.mRED;
    Red_x[2] = 1.0 / MPC_P.IRED;
    memset(&m[0], 0, 9U * sizeof(real_T));
    m[0] = Red_x[0];
    m[4] = Red_x[1];
    m[8] = Red_x[2];
    rtb_TSamp = dt * dt / 2.0;
    for (rtemp = 0; rtemp < 3; rtemp++) {
      rtb_TSamp_lb = m[3 * rtemp];
      G[6 * rtemp] = rtb_TSamp * rtb_TSamp_lb;
      G[6 * rtemp + 3] = dt * rtb_TSamp_lb;
      rtb_TSamp_lb = m[3 * rtemp + 1];
      G[6 * rtemp + 1] = rtb_TSamp * rtb_TSamp_lb;
      G[6 * rtemp + 4] = dt * rtb_TSamp_lb;
      rtb_TSamp_lb = m[3 * rtemp + 2];
      G[6 * rtemp + 2] = rtb_TSamp * rtb_TSamp_lb;
      G[6 * rtemp + 5] = dt * rtb_TSamp_lb;
    }

    for (rtemp = 0; rtemp < 6; rtemp++) {
      rtb_TSamp_lb = 0.0;
      for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
           BLACK_Estimated_Covar_tmp++) {
        rtb_TSamp_lb += BLACK_Estimated_Covar[6 * BLACK_Estimated_Covar_tmp +
          rtemp] * MPC_DW.RED_Estimated_States[BLACK_Estimated_Covar_tmp];
      }

      BLACK_Estimated_States[rtemp] = rtb_TSamp_lb;
      BLUE_Estimated_States[rtemp] = (G[rtemp + 6] *
        MPC_DW.RED_Saturated_Controls[1] + G[rtemp] *
        MPC_DW.RED_Saturated_Controls[0]) + G[rtemp + 12] *
        MPC_DW.RED_Saturated_Controls[2];
    }

    for (rtemp = 0; rtemp < 6; rtemp++) {
      MPC_DW.RED_Estimated_States[rtemp] = BLACK_Estimated_States[rtemp] +
        BLUE_Estimated_States[rtemp];
      for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
           BLACK_Estimated_Covar_tmp++) {
        rtb_TSamp_lb = 0.0;
        for (i = 0; i < 6; i++) {
          rtb_TSamp_lb += BLACK_Estimated_Covar[6 * i + rtemp] * MPC_B.P[6 *
            BLACK_Estimated_Covar_tmp + i];
        }

        BLACK_Estimated_Covar_0[rtemp + 6 * BLACK_Estimated_Covar_tmp] =
          rtb_TSamp_lb;
      }

      rtb_TSamp_lb = G[rtemp + 6];
      rtb_TSamp = G[rtemp];
      rtb_TSamp_e = G[rtemp + 12];
      for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
           BLACK_Estimated_Covar_tmp++) {
        K[rtemp + 6 * BLACK_Estimated_Covar_tmp] = (f_b[3 *
          BLACK_Estimated_Covar_tmp + 1] * rtb_TSamp_lb + f_b[3 *
          BLACK_Estimated_Covar_tmp] * rtb_TSamp) + f_b[3 *
          BLACK_Estimated_Covar_tmp + 2] * rtb_TSamp_e;
      }

      for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
           BLACK_Estimated_Covar_tmp++) {
        rtb_TSamp_lb = 0.0;
        for (i = 0; i < 6; i++) {
          rtb_TSamp_lb += BLACK_Estimated_Covar_0[6 * i + rtemp] *
            BLACK_Estimated_Covar[6 * i + BLACK_Estimated_Covar_tmp];
        }

        BLACK_Estimated_Covar_1[rtemp + 6 * BLACK_Estimated_Covar_tmp] =
          rtb_TSamp_lb;
      }
    }

    for (rtemp = 0; rtemp < 6; rtemp++) {
      rtb_TSamp_lb = K[rtemp + 6];
      rtb_TSamp = K[rtemp];
      rtb_TSamp_e = K[rtemp + 12];
      for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
           BLACK_Estimated_Covar_tmp++) {
        BLACK_Estimated_Covar[rtemp + 6 * BLACK_Estimated_Covar_tmp] =
          (G[BLACK_Estimated_Covar_tmp + 6] * rtb_TSamp_lb + rtb_TSamp *
           G[BLACK_Estimated_Covar_tmp]) + G[BLACK_Estimated_Covar_tmp + 12] *
          rtb_TSamp_e;
      }
    }

    for (rtemp = 0; rtemp < 36; rtemp++) {
      Pk[rtemp] = BLACK_Estimated_Covar_1[rtemp] + BLACK_Estimated_Covar[rtemp];
    }

    RelationalOperator_i[0] = rtIsInf(rtb_y_fe[0]);
    c_b[0] = rtIsNaN(rtb_y_fe[0]);
    RelationalOperator_i[1] = rtIsInf(rtb_y_fe[1]);
    c_b[1] = rtIsNaN(rtb_y_fe[1]);
    RelationalOperator_i[2] = rtIsInf(rtb_y_fe[2]);
    c_b[2] = rtIsNaN(rtb_y_fe[2]);
    rEQ0 = true;
    rtemp = 0;
    exitg1 = false;
    while ((!exitg1) && (rtemp < 3)) {
      if ((!RelationalOperator_i[rtemp]) && (!c_b[rtemp])) {
        rEQ0 = false;
        exitg1 = true;
      } else {
        rtemp++;
      }
    }

    if (rEQ0) {
      memcpy(&MPC_B.P[0], &Pk[0], 36U * sizeof(real_T));
    } else {
      for (rtemp = 0; rtemp < 18; rtemp++) {
        v_tmp[rtemp] = b_a[rtemp];
      }

      for (i = 0; i < 3; i++) {
        rtb_TSamp_lb = 0.0;
        for (rtemp = 0; rtemp < 6; rtemp++) {
          rtb_TSamp_lb += static_cast<real_T>(v_tmp[3 * rtemp + i]) *
            MPC_DW.RED_Estimated_States[rtemp];
        }

        Red_x[i] = rtb_TSamp_lb;
        b[i] = rtb_y_fe[i] - rtb_TSamp_lb;
      }

      rtb_TSamp_lb = sin(rtb_y_fe[2]);
      b_norm = cos(rtb_y_fe[2]);
      rtb_y_gs = sin(Red_x[2]);
      e_in_tmp = cos(Red_x[2]);
      rtb_TSamp = 3.3121686421112381E-170;
      e_in_0 = (rtb_TSamp_lb * 0.0 + b_norm) - (rtb_y_gs * 0.0 + e_in_tmp);
      e_in[0] = e_in_0;
      rtb_TSamp_e = fabs(e_in_0);
      if (rtb_TSamp_e > 3.3121686421112381E-170) {
        rtb_y_eu = 1.0;
        rtb_TSamp = rtb_TSamp_e;
      } else {
        rtb_TSamp_jb = rtb_TSamp_e / 3.3121686421112381E-170;
        rtb_y_eu = rtb_TSamp_jb * rtb_TSamp_jb;
      }

      e_in_0 = (b_norm * 0.0 - rtb_TSamp_lb) - (e_in_tmp * 0.0 - rtb_y_gs);
      rtb_TSamp_e = fabs(e_in_0);
      if (rtb_TSamp_e > rtb_TSamp) {
        rtb_TSamp_jb = rtb_TSamp / rtb_TSamp_e;
        rtb_y_eu = rtb_y_eu * rtb_TSamp_jb * rtb_TSamp_jb + 1.0;
        rtb_TSamp = rtb_TSamp_e;
      } else {
        rtb_TSamp_jb = rtb_TSamp_e / rtb_TSamp;
        rtb_y_eu += rtb_TSamp_jb * rtb_TSamp_jb;
      }

      rtb_TSamp_lb = (b_norm * 0.0 + rtb_TSamp_lb) * e_in[0] + (-rtb_TSamp_lb *
        0.0 + b_norm) * e_in_0;
      if (rtIsNaN(rtb_TSamp_lb)) {
        rtb_TSamp_e = (rtNaN);
      } else if (rtb_TSamp_lb < 0.0) {
        rtb_TSamp_e = -1.0;
      } else {
        rtb_TSamp_e = (rtb_TSamp_lb > 0.0);
      }

      for (rtemp = 0; rtemp < 18; rtemp++) {
        K[rtemp] = d[rtemp];
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_lb = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp_lb += static_cast<real_T>(v_tmp[3 * i + rtemp]) * Pk[6 *
              BLACK_Estimated_Covar_tmp + i];
          }

          G[rtemp + 3 * BLACK_Estimated_Covar_tmp] = rtb_TSamp_lb;
        }

        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_jb = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp_jb += G[3 * i + rtemp] * K[6 * BLACK_Estimated_Covar_tmp +
              i];
          }

          i = 3 * BLACK_Estimated_Covar_tmp + rtemp;
          m[i] = g_b[i] + rtb_TSamp_jb;
        }
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_lb = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp_lb += Pk[6 * i + BLACK_Estimated_Covar_tmp] * K[6 * rtemp
              + i];
          }

          G[BLACK_Estimated_Covar_tmp + 6 * rtemp] = rtb_TSamp_lb;
        }
      }

      i = 0;
      r2 = 1;
      r3 = 2;
      rtb_TSamp_lb = fabs(m[0]);
      rtb_TSamp_jb = fabs(m[1]);
      if (rtb_TSamp_jb > rtb_TSamp_lb) {
        rtb_TSamp_lb = rtb_TSamp_jb;
        i = 1;
        r2 = 0;
      }

      if (fabs(m[2]) > rtb_TSamp_lb) {
        i = 2;
        r2 = 1;
        r3 = 0;
      }

      m[r2] /= m[i];
      m[r3] /= m[i];
      m[r2 + 3] -= m[i + 3] * m[r2];
      m[r3 + 3] -= m[i + 3] * m[r3];
      m[r2 + 6] -= m[i + 6] * m[r2];
      m[r3 + 6] -= m[i + 6] * m[r3];
      if (fabs(m[r3 + 3]) > fabs(m[r2 + 3])) {
        rtemp = r2;
        r2 = r3;
        r3 = rtemp;
      }

      m[r3 + 3] /= m[r2 + 3];
      m[r3 + 6] -= m[r3 + 3] * m[r2 + 6];
      rtb_TSamp_lb = b[1];
      rtb_TSamp_jb = b[0];
      rtb_TSamp = rtb_TSamp * sqrt(rtb_y_eu) * -rtb_TSamp_e;
      for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
           BLACK_Estimated_Covar_tmp++) {
        rtemp = 6 * i + BLACK_Estimated_Covar_tmp;
        K[rtemp] = G[BLACK_Estimated_Covar_tmp] / m[i];
        jBcol = 6 * r2 + BLACK_Estimated_Covar_tmp;
        K[jBcol] = G[BLACK_Estimated_Covar_tmp + 6] - m[i + 3] * K[rtemp];
        kBcol = 6 * r3 + BLACK_Estimated_Covar_tmp;
        K[kBcol] = G[BLACK_Estimated_Covar_tmp + 12] - m[i + 6] * K[rtemp];
        K[jBcol] /= m[r2 + 3];
        K[kBcol] -= m[r2 + 6] * K[jBcol];
        K[kBcol] /= m[r3 + 6];
        K[jBcol] -= m[r3 + 3] * K[kBcol];
        K[rtemp] -= K[kBcol] * m[r3];
        K[rtemp] -= K[jBcol] * m[r2];
        MPC_DW.RED_Estimated_States[BLACK_Estimated_Covar_tmp] +=
          (K[BLACK_Estimated_Covar_tmp + 6] * rtb_TSamp_lb +
           K[BLACK_Estimated_Covar_tmp] * rtb_TSamp_jb) +
          K[BLACK_Estimated_Covar_tmp + 12] * rtb_TSamp;
      }

      for (rtemp = 0; rtemp < 36; rtemp++) {
        BLACK_Estimated_Covar[rtemp] = e[rtemp];
      }

      for (rtemp = 0; rtemp < 6; rtemp++) {
        rtPrevAction = v_tmp[3 * rtemp + 1];
        rtAction = v_tmp[3 * rtemp];
        v_tmp_0 = v_tmp[3 * rtemp + 2];
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          BLUE_Estimated_Covar[BLACK_Estimated_Covar_tmp + 6 * rtemp] =
            (K[BLACK_Estimated_Covar_tmp + 6] * static_cast<real_T>(rtPrevAction)
             + static_cast<real_T>(rtAction) * K[BLACK_Estimated_Covar_tmp]) +
            K[BLACK_Estimated_Covar_tmp + 12] * static_cast<real_T>(v_tmp_0);
        }
      }

      for (rtemp = 0; rtemp < 36; rtemp++) {
        BLACK_Estimated_Covar_0[rtemp] = BLACK_Estimated_Covar[rtemp] -
          BLUE_Estimated_Covar[rtemp];
      }

      for (rtemp = 0; rtemp < 6; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_lb = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp_lb += BLACK_Estimated_Covar_0[6 * i + rtemp] * Pk[6 *
              BLACK_Estimated_Covar_tmp + i];
          }

          i = 6 * BLACK_Estimated_Covar_tmp + rtemp;
          BLACK_Estimated_Covar_1[i] = rtb_TSamp_lb;
          BLACK_Estimated_Covar_2[BLACK_Estimated_Covar_tmp + 6 * rtemp] =
            BLACK_Estimated_Covar[i] - BLUE_Estimated_Covar[i];
        }

        rtb_TSamp_e = K[rtemp + 6];
        rtb_TSamp_lb = K[rtemp];
        rtb_TSamp = K[rtemp + 12];
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          G[rtemp + 6 * BLACK_Estimated_Covar_tmp] = (g_b[3 *
            BLACK_Estimated_Covar_tmp + 1] * rtb_TSamp_e + g_b[3 *
            BLACK_Estimated_Covar_tmp] * rtb_TSamp_lb) + g_b[3 *
            BLACK_Estimated_Covar_tmp + 2] * rtb_TSamp;
        }
      }

      for (rtemp = 0; rtemp < 6; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_lb = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp_lb += BLACK_Estimated_Covar_1[6 * i + rtemp] *
              BLACK_Estimated_Covar_2[6 * BLACK_Estimated_Covar_tmp + i];
          }

          i = 6 * BLACK_Estimated_Covar_tmp + rtemp;
          BLACK_Estimated_Covar[i] = rtb_TSamp_lb;
          Pk[i] = (G[rtemp + 6] * K[BLACK_Estimated_Covar_tmp + 6] + G[rtemp] *
                   K[BLACK_Estimated_Covar_tmp]) + G[rtemp + 12] *
            K[BLACK_Estimated_Covar_tmp + 12];
        }
      }

      for (rtemp = 0; rtemp < 36; rtemp++) {
        MPC_B.P[rtemp] = BLACK_Estimated_Covar[rtemp] + Pk[rtemp];
      }
    }

    // DataStoreWrite: '<S12>/Data Store Write'
    memcpy(&Pk[0], &MPC_B.P[0], 36U * sizeof(real_T));

    // DataStoreRead: '<S12>/Data Store Read1'
    memcpy(&rtb_DataStoreRead1_f[0], &MPC_DW.BLACK_Measured_States_RAW[0], 9U *
           sizeof(real_T));

    // MATLAB Function: '<S270>/MATLAB Function1' incorporates:
    //   Delay: '<S270>/Delay2'

    MPC_MATLABFunction1(rtb_DataStoreRead1_f, MPC_DW.Delay2_DSTATE_p, rtb_y_fe);

    // Delay: '<S266>/Delay1'
    for (i = 0; i < 6; i++) {
      MPC_B.x_o[i] = MPC_DW.Delay1_DSTATE_c[i];
    }

    // End of Delay: '<S266>/Delay1'

    // Delay: '<S266>/Delay'
    memcpy(&MPC_B.P_f[0], &MPC_DW.Delay_DSTATE_n[0], 36U * sizeof(real_T));

    // Delay: '<S266>/Delay2'
    memcpy(&MPC_B.V_gq[0], &MPC_DW.Delay2_DSTATE_j[0], 9U * sizeof(real_T));

    // MATLAB Function: '<S266>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S12>/Data Store Read13'
    //   DataStoreRead: '<S12>/Data Store Read7'

    MPC_MATLABFunction_c1(dt, rtb_y_fe, MPC_DW.BLACK_Saturated_Controls,
                          MPC_B.x_o, MPC_B.P_f);

    // DataStoreWrite: '<S12>/Data Store Write2'
    for (i = 0; i < 6; i++) {
      BLACK_Estimated_States[i] = MPC_B.x_o[i];
    }

    // DataStoreWrite: '<S12>/Data Store Write3'
    memcpy(&BLACK_Estimated_Covar[0], &MPC_B.P_f[0], 36U * sizeof(real_T));
    for (i = 0; i < 9; i++) {
      // DataStoreWrite: '<S12>/Data Store Write10' incorporates:
      //   DataStoreRead: '<S12>/Data Store Read10'

      MPC_DW.BLACK_Measured_States[i] = MPC_DW.BLACK_Measured_States_RAW[i];

      // DataStoreWrite: '<S12>/Data Store Write11' incorporates:
      //   DataStoreRead: '<S12>/Data Store Read11'

      rtb_TSamp_lb = MPC_DW.BLUE_Measured_States_RAW[i];
      MPC_DW.BLUE_Measured_States[i] = rtb_TSamp_lb;

      // DataStoreRead: '<S12>/Data Store Read2'
      rtb_DataStoreRead2_k[i] = rtb_TSamp_lb;
    }

    // MATLAB Function: '<S273>/MATLAB Function1' incorporates:
    //   Delay: '<S273>/Delay2'

    MPC_MATLABFunction1(rtb_DataStoreRead2_k, MPC_DW.Delay2_DSTATE_f, rtb_y_fe);

    // Delay: '<S267>/Delay1'
    for (i = 0; i < 6; i++) {
      MPC_B.x_c[i] = MPC_DW.Delay1_DSTATE_g[i];
    }

    // End of Delay: '<S267>/Delay1'

    // Delay: '<S267>/Delay'
    memcpy(&MPC_B.P_g[0], &MPC_DW.Delay_DSTATE_h[0], 36U * sizeof(real_T));

    // Delay: '<S267>/Delay2'
    memcpy(&MPC_B.V_g[0], &MPC_DW.Delay2_DSTATE_n[0], 9U * sizeof(real_T));

    // MATLAB Function: '<S267>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S12>/Data Store Read14'
    //   DataStoreRead: '<S12>/Data Store Read8'

    MPC_MATLABFunction_c1(dt, rtb_y_fe, MPC_DW.BLUE_Saturated_Controls,
                          MPC_B.x_c, MPC_B.P_g);

    // DataStoreWrite: '<S12>/Data Store Write4'
    for (i = 0; i < 6; i++) {
      BLUE_Estimated_States[i] = MPC_B.x_c[i];
    }

    // End of DataStoreWrite: '<S12>/Data Store Write4'

    // DataStoreWrite: '<S12>/Data Store Write5'
    memcpy(&BLUE_Estimated_Covar[0], &MPC_B.P_g[0], 36U * sizeof(real_T));

    // DataStoreWrite: '<S12>/Data Store Write9' incorporates:
    //   DataStoreRead: '<S12>/Data Store Read9'

    memcpy(&MPC_DW.RED_Measured_States[0], &MPC_DW.RED_Measured_States_RAW[0],
           9U * sizeof(real_T));

    // DataStoreWrite: '<S17>/Data Store Write' incorporates:
    //   Constant: '<S17>/Constant'

    MPC_DW.isSim = MPC_P.simMode;

    // If: '<S1>/Separate Phases' incorporates:
    //   Constant: '<S1>/Constant'
    //   Constant: '<S1>/Constant1'
    //   Constant: '<S1>/Constant2'
    //   Constant: '<S1>/Constant3'
    //   Constant: '<S1>/Constant4'
    //   Constant: '<S1>/Constant6'
    //   DataStoreRead: '<S1>/Universal_Time25'

    if (MPC_DW.Univ_Time < MPC_P.Phase0_End) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #0: Synchronization' incorporates:
      //   ActionPort: '<S20>/Action Port'

      MPC_Phase0Synchronization(&MPC_DW.ARM_Control_Law_Enabler, &rtb_TSamp_lb,
        &MPC_DW.BLACK_Control_Law_Enabler, &MPC_DW.BLACK_Path_Planner_Selection,
        &MPC_DW.BLUE_Control_Law_Enabler, &rtb_TSamp, &MPC_DW.Float_State,
        &MPC_DW.RED_Control_Law_Enabler, MPC_DW.RED_Logger,
        &MPC_DW.RED_Path_Planner_Selection, &MPC_DW.Toggle_Nav,
        &MPC_P.Phase0Synchronization);

      // End of Outputs for SubSystem: '<S1>/Phase #0: Synchronization'
    } else if ((MPC_DW.Univ_Time < MPC_P.Phase1_End) && (MPC_DW.Univ_Time >=
                MPC_P.Phase0_End)) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #1: Start Floating ' incorporates:
      //   ActionPort: '<S21>/Action Port'

      MPC_Phase0Synchronization(&MPC_DW.ARM_Control_Law_Enabler, &rtb_TSamp_lb,
        &MPC_DW.BLACK_Control_Law_Enabler, &MPC_DW.BLACK_Path_Planner_Selection,
        &MPC_DW.BLUE_Control_Law_Enabler, &rtb_TSamp, &MPC_DW.Float_State,
        &MPC_DW.RED_Control_Law_Enabler, MPC_DW.RED_Logger,
        &MPC_DW.RED_Path_Planner_Selection, &MPC_DW.Toggle_Nav,
        &MPC_P.Phase1StartFloating);

      // End of Outputs for SubSystem: '<S1>/Phase #1: Start Floating '
    } else if ((MPC_DW.Univ_Time < MPC_P.Phase2_End) && (MPC_DW.Univ_Time >=
                MPC_P.Phase1_End)) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #2: Initial Position' incorporates:
      //   ActionPort: '<S22>/Action Port'

      // DataStoreWrite: '<S22>/Data Store Write24' incorporates:
      //   Constant: '<S22>/Constant11'

      MPC_DW.RED_Path_Planner_Selection = MPC_P.Constant11_Value;

      // DataStoreWrite: '<S22>/Data Store Write23' incorporates:
      //   Constant: '<S22>/Constant14'

      MPC_DW.BLACK_Path_Planner_Selection = MPC_P.Constant14_Value;

      // DataStoreWrite: '<S22>/Data Store Write27' incorporates:
      //   Constant: '<S22>/Constant18'

      MPC_DW.ARM_Control_Law_Enabler = MPC_P.Constant18_Value;

      // DataStoreWrite: '<S22>/Data Store Write4' incorporates:
      //   Constant: '<S22>/Constant4'

      MPC_DW.BLACK_Control_Law_Enabler = MPC_P.Constant4_Value;

      // DataStoreWrite: '<S22>/Data Store Write8' incorporates:
      //   Constant: '<S22>/Constant5'

      MPC_DW.RED_Control_Law_Enabler = MPC_P.Constant5_Value;

      // DataStoreWrite: '<S22>/Data Store Write7' incorporates:
      //   Constant: '<S22>/Constant6'

      MPC_DW.Float_State = MPC_P.Constant6_Value;

      // DataStoreWrite: '<S22>/Data Store Write16' incorporates:
      //   Constant: '<S22>/Constant8'

      MPC_DW.BLUE_Control_Law_Enabler = MPC_P.Constant8_Value;

      // DataStoreWrite: '<S22>/Data Store Write10' incorporates:
      //   Constant: '<S22>/Puck State1'

      MPC_DW.Toggle_Nav = MPC_P.PuckState1_Value;

      // DataStoreWrite: '<S22>/Data Store Write13' incorporates:
      //   Constant: '<S27>/Constant1'
      //   Constant: '<S27>/Constant2'
      //   Constant: '<S27>/Constant3'

      MPC_DW.ARM_Desired_States[0] = MPC_P.Constant3_Value;
      MPC_DW.ARM_Desired_States[1] = MPC_P.Constant1_Value;
      MPC_DW.ARM_Desired_States[2] = MPC_P.Constant2_Value;

      // DataStoreWrite: '<S22>/Data Store Write1' incorporates:
      //   Constant: '<S28>/Desired States (BLACK)'

      MPC_DW.BLACK_Desired_States[0] = MPC_P.init_states_BLACK[0];

      // DataStoreWrite: '<S22>/Data Store Write18' incorporates:
      //   Constant: '<S29>/Desired States (BLUE)'

      MPC_DW.BLUE_Desired_States[0] = MPC_P.init_states_BLUE[0];

      // DataStoreWrite: '<S22>/Data Store Write9' incorporates:
      //   Constant: '<S30>/Constant2'

      MPC_DW.RED_Desired_States[0] = MPC_P.init_states_RED[0];

      // DataStoreWrite: '<S22>/Data Store Write1' incorporates:
      //   Constant: '<S28>/Desired States (BLACK)'

      MPC_DW.BLACK_Desired_States[1] = MPC_P.init_states_BLACK[1];

      // DataStoreWrite: '<S22>/Data Store Write18' incorporates:
      //   Constant: '<S29>/Desired States (BLUE)'

      MPC_DW.BLUE_Desired_States[1] = MPC_P.init_states_BLUE[1];

      // DataStoreWrite: '<S22>/Data Store Write9' incorporates:
      //   Constant: '<S30>/Constant2'

      MPC_DW.RED_Desired_States[1] = MPC_P.init_states_RED[1];

      // DataStoreWrite: '<S22>/Data Store Write1' incorporates:
      //   Constant: '<S28>/Desired States (BLACK)'

      MPC_DW.BLACK_Desired_States[2] = MPC_P.init_states_BLACK[2];

      // DataStoreWrite: '<S22>/Data Store Write18' incorporates:
      //   Constant: '<S29>/Desired States (BLUE)'

      MPC_DW.BLUE_Desired_States[2] = MPC_P.init_states_BLUE[2];

      // DataStoreWrite: '<S22>/Data Store Write9' incorporates:
      //   Constant: '<S30>/Constant2'

      MPC_DW.RED_Desired_States[2] = MPC_P.init_states_RED[2];

      // End of Outputs for SubSystem: '<S1>/Phase #2: Initial Position'
    } else if ((MPC_DW.Univ_Time < MPC_P.Phase3_End) && (MPC_DW.Univ_Time >=
                MPC_P.Phase2_End)) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #3: Experiment' incorporates:
      //   ActionPort: '<S23>/Action Port'

      // If: '<S23>/Experiment Sub-Phases' incorporates:
      //   Constant: '<S23>/Constant1'
      //   Constant: '<S23>/Constant2'
      //   Constant: '<S23>/Constant3'
      //   Constant: '<S23>/Constant4'
      //   DataStoreRead: '<S23>/Universal_Time'

      if (MPC_DW.Univ_Time < MPC_P.Phase3_SubPhase1_End) {
        // Outputs for IfAction SubSystem: '<S23>/Sub-Phase #1' incorporates:
        //   ActionPort: '<S31>/Action Port'

        // DataStoreWrite: '<S31>/Data Store Write24' incorporates:
        //   Constant: '<S31>/Constant11'

        MPC_DW.RED_Path_Planner_Selection = MPC_P.Constant11_Value_h;

        // DataStoreWrite: '<S31>/Data Store Write23' incorporates:
        //   Constant: '<S31>/Constant14'

        MPC_DW.BLACK_Path_Planner_Selection = MPC_P.Constant14_Value_k;

        // DataStoreWrite: '<S31>/Data Store Write2' incorporates:
        //   Constant: '<S31>/Constant18'

        MPC_DW.ARM_Control_Law_Enabler = MPC_P.Constant18_Value_g;

        // DataStoreWrite: '<S31>/Data Store Write4' incorporates:
        //   Constant: '<S31>/Constant4'

        MPC_DW.BLACK_Control_Law_Enabler = MPC_P.Constant4_Value_c;

        // DataStoreWrite: '<S31>/Data Store Write3' incorporates:
        //   Constant: '<S31>/Constant5'

        MPC_DW.RED_Control_Law_Enabler = MPC_P.Constant5_Value_i;

        // DataStoreWrite: '<S31>/Data Store Write7' incorporates:
        //   Constant: '<S31>/Constant6'

        MPC_DW.Float_State = MPC_P.Constant6_Value_j;

        // DataStoreWrite: '<S31>/Data Store Write16' incorporates:
        //   Constant: '<S31>/Constant8'

        MPC_DW.BLUE_Control_Law_Enabler = MPC_P.Constant8_Value_k;

        // DataStoreWrite: '<S31>/Data Store Write10' incorporates:
        //   Constant: '<S31>/Puck State1'

        MPC_DW.Toggle_Nav = MPC_P.PuckState1_Value_o;

        // Sum: '<S40>/Subtract3' incorporates:
        //   Constant: '<S40>/Constant2'
        //   DataStoreRead: '<S42>/Universal_Time'
        //   Sum: '<S37>/Subtract3'

        rtb_TSamp_lb = MPC_DW.Univ_Time - MPC_P.Phase2_End;

        // DataStoreWrite: '<S31>/Data Store Write9' incorporates:
        //   Constant: '<S31>/Constant'

        MPC_DW.RED_Desired_States[0] = MPC_P.Constant_Value[0];

        // DataStoreWrite: '<S31>/Data Store Write13' incorporates:
        //   Constant: '<S31>/Constant1'

        MPC_DW.ARM_Desired_States[0] = MPC_P.Constant1_Value_d[0];

        // Sum: '<S36>/Sum' incorporates:
        //   Constant: '<S36>/Constant'
        //   Constant: '<S36>/Constant1'
        //   Product: '<S36>/Product'
        //   Sum: '<S40>/Subtract3'

        rtb_y_fe[0] = rtb_TSamp_lb * MPC_P.x_BLUE_0[3] + MPC_P.x_BLUE_0[0];

        // DataStoreWrite: '<S31>/Data Store Write9' incorporates:
        //   Constant: '<S31>/Constant'

        MPC_DW.RED_Desired_States[1] = MPC_P.Constant_Value[1];

        // DataStoreWrite: '<S31>/Data Store Write13' incorporates:
        //   Constant: '<S31>/Constant1'

        MPC_DW.ARM_Desired_States[1] = MPC_P.Constant1_Value_d[1];

        // Sum: '<S36>/Sum' incorporates:
        //   Constant: '<S36>/Constant'
        //   Constant: '<S36>/Constant1'
        //   Product: '<S36>/Product'
        //   Sum: '<S40>/Subtract3'

        rtb_y_fe[1] = rtb_TSamp_lb * MPC_P.x_BLUE_0[4] + MPC_P.x_BLUE_0[1];

        // DataStoreWrite: '<S31>/Data Store Write9' incorporates:
        //   Constant: '<S31>/Constant'

        MPC_DW.RED_Desired_States[2] = MPC_P.Constant_Value[2];

        // DataStoreWrite: '<S31>/Data Store Write13' incorporates:
        //   Constant: '<S31>/Constant1'

        MPC_DW.ARM_Desired_States[2] = MPC_P.Constant1_Value_d[2];

        // Sum: '<S36>/Sum' incorporates:
        //   Constant: '<S36>/Constant'
        //   Constant: '<S36>/Constant1'
        //   Product: '<S36>/Product'
        //   Sum: '<S40>/Subtract3'

        rtb_y_fe[2] = rtb_TSamp_lb * MPC_P.x_BLUE_0[5] + MPC_P.x_BLUE_0[2];

        // DataStoreWrite: '<S31>/Data Store Write18' incorporates:
        //   Trigonometry: '<S41>/Atan2'
        //   Trigonometry: '<S41>/Cos'
        //   Trigonometry: '<S41>/Sin'

        MPC_DW.BLUE_Desired_States[0] = rtb_y_fe[0];
        MPC_DW.BLUE_Desired_States[1] = rtb_y_fe[1];
        MPC_DW.BLUE_Desired_States[2] = rt_atan2d_snf(sin(rtb_y_fe[2]), cos
          (rtb_y_fe[2]));

        // Sum: '<S35>/Sum' incorporates:
        //   Constant: '<S35>/Constant'
        //   Constant: '<S35>/Constant1'
        //   Product: '<S35>/Product'

        rtb_y_fe[0] = rtb_TSamp_lb * MPC_P.x_BLACK_0[3] + MPC_P.x_BLACK_0[0];
        rtb_y_fe[1] = rtb_TSamp_lb * MPC_P.x_BLACK_0[4] + MPC_P.x_BLACK_0[1];
        rtb_y_fe[2] = rtb_TSamp_lb * MPC_P.x_BLACK_0[5] + MPC_P.x_BLACK_0[2];

        // DataStoreWrite: '<S31>/Data Store Write5' incorporates:
        //   Trigonometry: '<S38>/Atan2'
        //   Trigonometry: '<S38>/Cos'
        //   Trigonometry: '<S38>/Sin'

        MPC_DW.BLACK_Desired_States[0] = rtb_y_fe[0];
        MPC_DW.BLACK_Desired_States[1] = rtb_y_fe[1];
        MPC_DW.BLACK_Desired_States[2] = rt_atan2d_snf(sin(rtb_y_fe[2]), cos
          (rtb_y_fe[2]));

        // End of Outputs for SubSystem: '<S23>/Sub-Phase #1'
      } else if ((MPC_DW.Univ_Time < MPC_P.Phase3_SubPhase2_End) &&
                 (MPC_DW.Univ_Time >= MPC_P.Phase3_SubPhase1_End)) {
        // Outputs for IfAction SubSystem: '<S23>/Sub-Phase #2 ' incorporates:
        //   ActionPort: '<S32>/Action Port'

        // DataStoreWrite: '<S32>/Data Store Write24' incorporates:
        //   Constant: '<S32>/Constant11'

        MPC_DW.RED_Path_Planner_Selection = MPC_P.Constant11_Value_i;

        // DataStoreWrite: '<S32>/Data Store Write23' incorporates:
        //   Constant: '<S32>/Constant14'

        MPC_DW.BLACK_Path_Planner_Selection = MPC_P.Constant14_Value_p;

        // DataStoreWrite: '<S32>/Data Store Write2' incorporates:
        //   Constant: '<S32>/Constant18'

        MPC_DW.ARM_Control_Law_Enabler = MPC_P.Constant18_Value_n;

        // DataStoreWrite: '<S32>/Data Store Write4' incorporates:
        //   Constant: '<S32>/Constant4'

        MPC_DW.BLACK_Control_Law_Enabler = MPC_P.Constant4_Value_c2;

        // DataStoreWrite: '<S32>/Data Store Write3' incorporates:
        //   Constant: '<S32>/Constant5'

        MPC_DW.RED_Control_Law_Enabler = MPC_P.Constant5_Value_l;

        // DataStoreWrite: '<S32>/Data Store Write7' incorporates:
        //   Constant: '<S32>/Constant6'

        MPC_DW.Float_State = MPC_P.Constant6_Value_l;

        // DataStoreWrite: '<S32>/Data Store Write16' incorporates:
        //   Constant: '<S32>/Constant8'

        MPC_DW.BLUE_Control_Law_Enabler = MPC_P.Constant8_Value_b;

        // DataStoreWrite: '<S32>/Data Store Write10' incorporates:
        //   Constant: '<S32>/Puck State1'

        MPC_DW.Toggle_Nav = MPC_P.PuckState1_Value_m;

        // Sum: '<S44>/Subtract3' incorporates:
        //   Constant: '<S44>/Constant2'
        //   DataStoreRead: '<S46>/Universal_Time'

        rtb_TSamp_lb = MPC_DW.Univ_Time - MPC_P.Phase2_End;

        // DataStoreWrite: '<S32>/Data Store Write9' incorporates:
        //   Constant: '<S32>/Constant'

        MPC_DW.RED_Desired_States[0] = MPC_P.Constant_Value_p[0];

        // DataStoreWrite: '<S32>/Data Store Write13' incorporates:
        //   Constant: '<S32>/Constant1'

        MPC_DW.ARM_Desired_States[0] = MPC_P.Constant1_Value_k[0];

        // DataStoreWrite: '<S32>/Data Store Write18' incorporates:
        //   Constant: '<S32>/Constant2'

        MPC_DW.BLUE_Desired_States[0] = MPC_P.Constant2_Value_c[0];

        // Sum: '<S43>/Sum' incorporates:
        //   Constant: '<S43>/Constant'
        //   Constant: '<S43>/Constant1'
        //   Product: '<S43>/Product'

        rtb_y_fe[0] = rtb_TSamp_lb * MPC_P.x_BLACK_0[3] + MPC_P.x_BLACK_0[0];

        // DataStoreWrite: '<S32>/Data Store Write9' incorporates:
        //   Constant: '<S32>/Constant'

        MPC_DW.RED_Desired_States[1] = MPC_P.Constant_Value_p[1];

        // DataStoreWrite: '<S32>/Data Store Write13' incorporates:
        //   Constant: '<S32>/Constant1'

        MPC_DW.ARM_Desired_States[1] = MPC_P.Constant1_Value_k[1];

        // DataStoreWrite: '<S32>/Data Store Write18' incorporates:
        //   Constant: '<S32>/Constant2'

        MPC_DW.BLUE_Desired_States[1] = MPC_P.Constant2_Value_c[1];

        // Sum: '<S43>/Sum' incorporates:
        //   Constant: '<S43>/Constant'
        //   Constant: '<S43>/Constant1'
        //   Product: '<S43>/Product'

        rtb_y_fe[1] = rtb_TSamp_lb * MPC_P.x_BLACK_0[4] + MPC_P.x_BLACK_0[1];

        // DataStoreWrite: '<S32>/Data Store Write9' incorporates:
        //   Constant: '<S32>/Constant'

        MPC_DW.RED_Desired_States[2] = MPC_P.Constant_Value_p[2];

        // DataStoreWrite: '<S32>/Data Store Write13' incorporates:
        //   Constant: '<S32>/Constant1'

        MPC_DW.ARM_Desired_States[2] = MPC_P.Constant1_Value_k[2];

        // DataStoreWrite: '<S32>/Data Store Write18' incorporates:
        //   Constant: '<S32>/Constant2'

        MPC_DW.BLUE_Desired_States[2] = MPC_P.Constant2_Value_c[2];

        // Sum: '<S43>/Sum' incorporates:
        //   Constant: '<S43>/Constant'
        //   Constant: '<S43>/Constant1'
        //   Product: '<S43>/Product'

        rtb_y_fe[2] = rtb_TSamp_lb * MPC_P.x_BLACK_0[5] + MPC_P.x_BLACK_0[2];

        // DataStoreWrite: '<S32>/Data Store Write5' incorporates:
        //   Trigonometry: '<S45>/Atan2'
        //   Trigonometry: '<S45>/Cos'
        //   Trigonometry: '<S45>/Sin'

        MPC_DW.BLACK_Desired_States[0] = rtb_y_fe[0];
        MPC_DW.BLACK_Desired_States[1] = rtb_y_fe[1];
        MPC_DW.BLACK_Desired_States[2] = rt_atan2d_snf(sin(rtb_y_fe[2]), cos
          (rtb_y_fe[2]));

        // End of Outputs for SubSystem: '<S23>/Sub-Phase #2 '
      } else if ((MPC_DW.Univ_Time < MPC_P.Phase3_SubPhase3_End) &&
                 (MPC_DW.Univ_Time >= MPC_P.Phase3_SubPhase2_End)) {
        // Outputs for IfAction SubSystem: '<S23>/Sub-Phase #3 ' incorporates:
        //   ActionPort: '<S33>/Action Port'

        // DataStoreWrite: '<S33>/Data Store Write24' incorporates:
        //   Constant: '<S33>/Constant11'

        MPC_DW.RED_Path_Planner_Selection = MPC_P.Constant11_Value_b;

        // DataStoreWrite: '<S33>/Data Store Write23' incorporates:
        //   Constant: '<S33>/Constant14'

        MPC_DW.BLACK_Path_Planner_Selection = MPC_P.Constant14_Value_n;

        // DataStoreWrite: '<S33>/Data Store Write2' incorporates:
        //   Constant: '<S33>/Constant18'

        MPC_DW.ARM_Control_Law_Enabler = MPC_P.Constant18_Value_i;

        // DataStoreWrite: '<S33>/Data Store Write4' incorporates:
        //   Constant: '<S33>/Constant4'

        MPC_DW.BLACK_Control_Law_Enabler = MPC_P.Constant4_Value_k;

        // DataStoreWrite: '<S33>/Data Store Write3' incorporates:
        //   Constant: '<S33>/Constant5'

        MPC_DW.RED_Control_Law_Enabler = MPC_P.Constant5_Value_h;

        // DataStoreWrite: '<S33>/Data Store Write7' incorporates:
        //   Constant: '<S33>/Constant6'

        MPC_DW.Float_State = MPC_P.Constant6_Value_d;

        // DataStoreWrite: '<S33>/Data Store Write16' incorporates:
        //   Constant: '<S33>/Constant8'

        MPC_DW.BLUE_Control_Law_Enabler = MPC_P.Constant8_Value_p;

        // DataStoreWrite: '<S33>/Data Store Write10' incorporates:
        //   Constant: '<S33>/Puck State1'

        MPC_DW.Toggle_Nav = MPC_P.PuckState1_Value_k;

        // Sum: '<S48>/Subtract3' incorporates:
        //   Constant: '<S48>/Constant2'
        //   DataStoreRead: '<S50>/Universal_Time'

        rtb_TSamp_lb = MPC_DW.Univ_Time - MPC_P.Phase2_End;

        // DataStoreWrite: '<S33>/Data Store Write9' incorporates:
        //   Constant: '<S33>/Constant'

        MPC_DW.RED_Desired_States[0] = MPC_P.Constant_Value_i[0];

        // DataStoreWrite: '<S33>/Data Store Write13' incorporates:
        //   Constant: '<S33>/Constant1'

        MPC_DW.ARM_Desired_States[0] = MPC_P.Constant1_Value_i[0];

        // DataStoreWrite: '<S33>/Data Store Write18' incorporates:
        //   Constant: '<S33>/Constant2'

        MPC_DW.BLUE_Desired_States[0] = MPC_P.Constant2_Value_g[0];

        // Sum: '<S47>/Sum' incorporates:
        //   Constant: '<S47>/Constant'
        //   Constant: '<S47>/Constant1'
        //   Product: '<S47>/Product'

        rtb_y_fe[0] = rtb_TSamp_lb * MPC_P.x_BLACK_0[3] + MPC_P.x_BLACK_0[0];

        // DataStoreWrite: '<S33>/Data Store Write9' incorporates:
        //   Constant: '<S33>/Constant'

        MPC_DW.RED_Desired_States[1] = MPC_P.Constant_Value_i[1];

        // DataStoreWrite: '<S33>/Data Store Write13' incorporates:
        //   Constant: '<S33>/Constant1'

        MPC_DW.ARM_Desired_States[1] = MPC_P.Constant1_Value_i[1];

        // DataStoreWrite: '<S33>/Data Store Write18' incorporates:
        //   Constant: '<S33>/Constant2'

        MPC_DW.BLUE_Desired_States[1] = MPC_P.Constant2_Value_g[1];

        // Sum: '<S47>/Sum' incorporates:
        //   Constant: '<S47>/Constant'
        //   Constant: '<S47>/Constant1'
        //   Product: '<S47>/Product'

        rtb_y_fe[1] = rtb_TSamp_lb * MPC_P.x_BLACK_0[4] + MPC_P.x_BLACK_0[1];

        // DataStoreWrite: '<S33>/Data Store Write9' incorporates:
        //   Constant: '<S33>/Constant'

        MPC_DW.RED_Desired_States[2] = MPC_P.Constant_Value_i[2];

        // DataStoreWrite: '<S33>/Data Store Write13' incorporates:
        //   Constant: '<S33>/Constant1'

        MPC_DW.ARM_Desired_States[2] = MPC_P.Constant1_Value_i[2];

        // DataStoreWrite: '<S33>/Data Store Write18' incorporates:
        //   Constant: '<S33>/Constant2'

        MPC_DW.BLUE_Desired_States[2] = MPC_P.Constant2_Value_g[2];

        // Sum: '<S47>/Sum' incorporates:
        //   Constant: '<S47>/Constant'
        //   Constant: '<S47>/Constant1'
        //   Product: '<S47>/Product'

        rtb_y_fe[2] = rtb_TSamp_lb * MPC_P.x_BLACK_0[5] + MPC_P.x_BLACK_0[2];

        // DataStoreWrite: '<S33>/Data Store Write5' incorporates:
        //   Trigonometry: '<S49>/Atan2'
        //   Trigonometry: '<S49>/Cos'
        //   Trigonometry: '<S49>/Sin'

        MPC_DW.BLACK_Desired_States[0] = rtb_y_fe[0];
        MPC_DW.BLACK_Desired_States[1] = rtb_y_fe[1];
        MPC_DW.BLACK_Desired_States[2] = rt_atan2d_snf(sin(rtb_y_fe[2]), cos
          (rtb_y_fe[2]));

        // End of Outputs for SubSystem: '<S23>/Sub-Phase #3 '
      } else if ((MPC_DW.Univ_Time < MPC_P.Phase3_SubPhase4_End) &&
                 (MPC_DW.Univ_Time >= MPC_P.Phase3_SubPhase3_End)) {
        // Outputs for IfAction SubSystem: '<S23>/Sub-Phase #4' incorporates:
        //   ActionPort: '<S34>/Action Port'

        // DataStoreWrite: '<S34>/Data Store Write24' incorporates:
        //   Constant: '<S34>/Constant11'

        MPC_DW.RED_Path_Planner_Selection = MPC_P.Constant11_Value_p;

        // DataStoreWrite: '<S34>/Data Store Write23' incorporates:
        //   Constant: '<S34>/Constant14'

        MPC_DW.BLACK_Path_Planner_Selection = MPC_P.Constant14_Value_i;

        // DataStoreWrite: '<S34>/Data Store Write2' incorporates:
        //   Constant: '<S34>/Constant18'

        MPC_DW.ARM_Control_Law_Enabler = MPC_P.Constant18_Value_p;

        // DataStoreWrite: '<S34>/Data Store Write9' incorporates:
        //   Constant: '<S34>/Constant'

        MPC_DW.RED_Desired_States[0] = MPC_P.Constant_Value_h[0];

        // DataStoreWrite: '<S34>/Data Store Write13' incorporates:
        //   Constant: '<S34>/Constant1'

        MPC_DW.ARM_Desired_States[0] = MPC_P.Constant1_Value_ip[0];

        // DataStoreWrite: '<S34>/Data Store Write18' incorporates:
        //   Constant: '<S34>/Constant2'

        MPC_DW.BLUE_Desired_States[0] = MPC_P.Constant2_Value_cp[0];

        // DataStoreWrite: '<S34>/Data Store Write9' incorporates:
        //   Constant: '<S34>/Constant'

        MPC_DW.RED_Desired_States[1] = MPC_P.Constant_Value_h[1];

        // DataStoreWrite: '<S34>/Data Store Write13' incorporates:
        //   Constant: '<S34>/Constant1'

        MPC_DW.ARM_Desired_States[1] = MPC_P.Constant1_Value_ip[1];

        // DataStoreWrite: '<S34>/Data Store Write18' incorporates:
        //   Constant: '<S34>/Constant2'

        MPC_DW.BLUE_Desired_States[1] = MPC_P.Constant2_Value_cp[1];

        // DataStoreWrite: '<S34>/Data Store Write9' incorporates:
        //   Constant: '<S34>/Constant'

        MPC_DW.RED_Desired_States[2] = MPC_P.Constant_Value_h[2];

        // DataStoreWrite: '<S34>/Data Store Write13' incorporates:
        //   Constant: '<S34>/Constant1'

        MPC_DW.ARM_Desired_States[2] = MPC_P.Constant1_Value_ip[2];

        // DataStoreWrite: '<S34>/Data Store Write18' incorporates:
        //   Constant: '<S34>/Constant2'

        MPC_DW.BLUE_Desired_States[2] = MPC_P.Constant2_Value_cp[2];

        // DataStoreWrite: '<S34>/Data Store Write4' incorporates:
        //   Constant: '<S34>/Constant4'

        MPC_DW.BLACK_Control_Law_Enabler = MPC_P.Constant4_Value_a;

        // DataStoreWrite: '<S34>/Data Store Write3' incorporates:
        //   Constant: '<S34>/Constant5'

        MPC_DW.RED_Control_Law_Enabler = MPC_P.Constant5_Value_j;

        // DataStoreWrite: '<S34>/Data Store Write7' incorporates:
        //   Constant: '<S34>/Constant6'

        MPC_DW.Float_State = MPC_P.Constant6_Value_o;

        // DataStoreWrite: '<S34>/Data Store Write16' incorporates:
        //   Constant: '<S34>/Constant8'

        MPC_DW.BLUE_Control_Law_Enabler = MPC_P.Constant8_Value_a;

        // DataStoreWrite: '<S34>/Data Store Write10' incorporates:
        //   Constant: '<S34>/Puck State1'

        MPC_DW.Toggle_Nav = MPC_P.PuckState1_Value_i;

        // Gain: '<S51>/4 deg per sec' incorporates:
        //   Constant: '<S52>/Constant2'
        //   DataStoreRead: '<S54>/Universal_Time'
        //   Sum: '<S52>/Subtract3'

        rtb_TSamp_lb = (MPC_DW.Univ_Time - MPC_P.Phase2_End) *
          MPC_P.udegpersec_Gain;

        // DataStoreWrite: '<S34>/Data Store Write5' incorporates:
        //   Constant: '<S51>/Constant'
        //   Trigonometry: '<S53>/Atan2'
        //   Trigonometry: '<S53>/Cos'
        //   Trigonometry: '<S53>/Sin'

        MPC_DW.BLACK_Desired_States[0] = MPC_P.init_states_BLACK[0];
        MPC_DW.BLACK_Desired_States[1] = MPC_P.init_states_BLACK[1];
        MPC_DW.BLACK_Desired_States[2] = rt_atan2d_snf(sin(rtb_TSamp_lb), cos
          (rtb_TSamp_lb));

        // End of Outputs for SubSystem: '<S23>/Sub-Phase #4'
      }

      // End of If: '<S23>/Experiment Sub-Phases'
      // End of Outputs for SubSystem: '<S1>/Phase #3: Experiment'
    } else if ((MPC_DW.Univ_Time < MPC_P.Phase4_End) && (MPC_DW.Univ_Time >=
                MPC_P.Phase3_End)) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #4: Return Home' incorporates:
      //   ActionPort: '<S24>/Action Port'

      MPC_Phase4ReturnHome(&MPC_DW.ARM_Control_Law_Enabler,
                           MPC_DW.ARM_Desired_States, &rtb_TSamp_lb,
                           &MPC_DW.BLACK_Control_Law_Enabler,
                           MPC_DW.BLACK_Desired_States,
                           &MPC_DW.BLACK_Path_Planner_Selection,
                           &MPC_DW.BLUE_Control_Law_Enabler,
                           MPC_DW.BLUE_Desired_States, &rtb_TSamp,
                           &MPC_DW.Float_State, &MPC_DW.RED_Control_Law_Enabler,
                           MPC_DW.RED_Desired_States,
                           &MPC_DW.RED_Path_Planner_Selection,
                           &MPC_DW.Toggle_Nav, &MPC_P.Phase4ReturnHome);

      // End of Outputs for SubSystem: '<S1>/Phase #4: Return Home'
    } else if ((MPC_DW.Univ_Time < MPC_P.Phase5_End) && (MPC_DW.Univ_Time >=
                MPC_P.Phase4_End)) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #5: Hold Home' incorporates:
      //   ActionPort: '<S25>/Action Port'

      MPC_Phase4ReturnHome(&MPC_DW.ARM_Control_Law_Enabler,
                           MPC_DW.ARM_Desired_States, &rtb_TSamp_lb,
                           &MPC_DW.BLACK_Control_Law_Enabler,
                           MPC_DW.BLACK_Desired_States,
                           &MPC_DW.BLACK_Path_Planner_Selection,
                           &MPC_DW.BLUE_Control_Law_Enabler,
                           MPC_DW.BLUE_Desired_States, &rtb_TSamp,
                           &MPC_DW.Float_State, &MPC_DW.RED_Control_Law_Enabler,
                           MPC_DW.RED_Desired_States,
                           &MPC_DW.RED_Path_Planner_Selection,
                           &MPC_DW.Toggle_Nav, &MPC_P.Phase5HoldHome);

      // End of Outputs for SubSystem: '<S1>/Phase #5: Hold Home'
    } else if (MPC_DW.Univ_Time >= MPC_P.Phase5_End) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #6: Clean Shutdown' incorporates:
      //   ActionPort: '<S26>/Action Port'

      // DataStoreWrite: '<S26>/Data Store Write2' incorporates:
      //   Constant: '<S26>/Constant1'

      MPC_DW.BLACK_Control_Law_Enabler = MPC_P.Constant1_Value_n;

      // DataStoreWrite: '<S26>/Data Store Write3' incorporates:
      //   Constant: '<S26>/Constant2'

      MPC_DW.BLUE_Control_Law_Enabler = MPC_P.Constant2_Value_a;

      // DataStoreWrite: '<S26>/Data Store Write7' incorporates:
      //   Constant: '<S26>/Constant3'

      MPC_DW.RED_Path_Planner_Selection = MPC_P.Constant3_Value_d;

      // DataStoreWrite: '<S26>/Data Store Write' incorporates:
      //   Constant: '<S26>/Constant5'

      MPC_DW.RED_Control_Law_Enabler = MPC_P.Constant5_Value_p;

      // DataStoreWrite: '<S26>/Data Store Write6' incorporates:
      //   Constant: '<S26>/Constant6'

      MPC_DW.BLACK_Path_Planner_Selection = MPC_P.Constant6_Value_do;

      // DataStoreWrite: '<S26>/Data Store Write9' incorporates:
      //   Constant: '<S26>/Constant8'

      MPC_DW.ARM_Control_Law_Enabler = MPC_P.Constant8_Value_h;

      // DataStoreWrite: '<S26>/Data Store Write10' incorporates:
      //   Constant: '<S26>/Puck State1'

      MPC_DW.Toggle_Nav = MPC_P.PuckState1_Value_h;

      // DataStoreWrite: '<S26>/Data Store Write4' incorporates:
      //   Constant: '<S26>/Puck State'

      MPC_DW.Float_State = MPC_P.PuckState_Value;

      // End of Outputs for SubSystem: '<S1>/Phase #6: Clean Shutdown'
    }

    // End of If: '<S1>/Separate Phases'

    // If: '<S3>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
    //   DataStoreRead: '<S3>/Data Store Read2'
    //   MATLAB Function: '<S99>/MATLAB Function'

    if (MPC_DW.Toggle_Nav == 1.0) {
      // Outputs for IfAction SubSystem: '<S3>/Subsystem' incorporates:
      //   ActionPort: '<S91>/Action Port'

      // MATLAB Function: '<S91>/MATLAB Function' incorporates:
      //   DataStoreRead: '<S91>/Data Store Read'

      MPC_MATLABFunction_d(MPC_DW.RED_Estimated_States, &rtb_out[0]);

      // MATLAB Function: '<S99>/MATLAB Function'
      rtb_TSamp = sin(rtb_out[5]);
      rtb_TSamp_e = cos(rtb_out[5]);
      m[0] = rtb_TSamp_e;
      m[3] = rtb_TSamp;
      m[6] = 0.0;
      m[1] = -rtb_TSamp;
      m[4] = rtb_TSamp_e;
      m[7] = 0.0;
      b[0] = rtb_out[0];
      rtb_y_fe[0] = 0.0;

      // MATLAB Function: '<S99>/MATLAB Function'
      m[2] = 0.0;
      b[1] = rtb_out[1];
      rtb_y_fe[1] = 0.0;

      // MATLAB Function: '<S99>/MATLAB Function'
      m[5] = 0.0;
      b[2] = rtb_out[2];
      rtb_y_fe[2] = 1.0;

      // MATLAB Function: '<S99>/MATLAB Function'
      m[8] = 1.0;
      MPC_rotm2Quat(m, rtb_MatrixConcatenate);
      b_norm = sqrt(((rtb_MatrixConcatenate[0] * rtb_MatrixConcatenate[0] +
                      rtb_MatrixConcatenate[1] * rtb_MatrixConcatenate[1]) +
                     rtb_MatrixConcatenate[2] * rtb_MatrixConcatenate[2]) +
                    rtb_MatrixConcatenate[3] * rtb_MatrixConcatenate[3]);
      rtb_MatrixConcatenate[0] /= b_norm;
      rtb_MatrixConcatenate[1] /= b_norm;
      rtb_MatrixConcatenate[2] /= b_norm;
      rtb_MatrixConcatenate[3] /= b_norm;
      rtb_TSamp_lb = 2.0 * acos(rtb_MatrixConcatenate[0]);
      rtb_TSamp = sin(rtb_TSamp_lb / 2.0);
      a[0] = rtb_MatrixConcatenate[1] / rtb_TSamp;
      a[1] = rtb_MatrixConcatenate[2] / rtb_TSamp;
      a[2] = rtb_MatrixConcatenate[3] / rtb_TSamp;
      rEQ0 = rtIsNaN(a[0]);
      if (!rEQ0) {
        rEQ0 = rtIsNaN(a[1]);
      }

      if (!rEQ0) {
        rEQ0 = rtIsNaN(a[2]);
      }

      if (!rEQ0) {
        rEQ0 = rtIsNaN(rtb_TSamp_lb);
      }

      if (rEQ0) {
        a[0] = 1.0;
        a[1] = 0.0;
        a[2] = 0.0;
        a[3] = 0.0;
      } else {
        if (rtIsNaN(rtb_TSamp_lb + 3.1415926535897931)) {
          b_norm = (rtNaN);
        } else if (rtIsInf(rtb_TSamp_lb + 3.1415926535897931)) {
          b_norm = (rtNaN);
        } else if (rtb_TSamp_lb + 3.1415926535897931 == 0.0) {
          b_norm = 0.0;
        } else {
          b_norm = fmod(rtb_TSamp_lb + 3.1415926535897931, 6.2831853071795862);
          rEQ0 = (b_norm == 0.0);
          if (!rEQ0) {
            rtb_TSamp = fabs((rtb_TSamp_lb + 3.1415926535897931) /
                             6.2831853071795862);
            rEQ0 = !(fabs(rtb_TSamp - floor(rtb_TSamp + 0.5)) >
                     2.2204460492503131E-16 * rtb_TSamp);
          }

          if (rEQ0) {
            b_norm = 0.0;
          } else if (b_norm < 0.0) {
            b_norm += 6.2831853071795862;
          }
        }

        rtb_TSamp = 3.3121686421112381E-170;
        rtb_TSamp_e = fabs(a[0]);
        if (rtb_TSamp_e > 3.3121686421112381E-170) {
          rtb_TSamp_lb = 1.0;
          rtb_TSamp = rtb_TSamp_e;
        } else {
          rtb_TSamp_jb = rtb_TSamp_e / 3.3121686421112381E-170;
          rtb_TSamp_lb = rtb_TSamp_jb * rtb_TSamp_jb;
        }

        rtb_TSamp_e = fabs(a[1]);
        if (rtb_TSamp_e > rtb_TSamp) {
          rtb_TSamp_jb = rtb_TSamp / rtb_TSamp_e;
          rtb_TSamp_lb = rtb_TSamp_lb * rtb_TSamp_jb * rtb_TSamp_jb + 1.0;
          rtb_TSamp = rtb_TSamp_e;
        } else {
          rtb_TSamp_jb = rtb_TSamp_e / rtb_TSamp;
          rtb_TSamp_lb += rtb_TSamp_jb * rtb_TSamp_jb;
        }

        rtb_TSamp_e = fabs(a[2]);
        if (rtb_TSamp_e > rtb_TSamp) {
          rtb_TSamp_jb = rtb_TSamp / rtb_TSamp_e;
          rtb_TSamp_lb = rtb_TSamp_lb * rtb_TSamp_jb * rtb_TSamp_jb + 1.0;
          rtb_TSamp = rtb_TSamp_e;
        } else {
          rtb_TSamp_jb = rtb_TSamp_e / rtb_TSamp;
          rtb_TSamp_lb += rtb_TSamp_jb * rtb_TSamp_jb;
        }

        rtb_TSamp_lb = rtb_TSamp * sqrt(rtb_TSamp_lb);
        axis[0] = a[0] / rtb_TSamp_lb;
        axis[1] = a[1] / rtb_TSamp_lb;
        axis[2] = a[2] / rtb_TSamp_lb;
        rtb_TSamp_lb = (b_norm - 3.1415926535897931) / 2.0;
        rtb_TSamp_e = sin(rtb_TSamp_lb);
        a[0] = cos(rtb_TSamp_lb);
        a[1] = axis[0] * rtb_TSamp_e;
        a[2] = axis[1] * rtb_TSamp_e;
        a[3] = axis[2] * rtb_TSamp_e;
      }

      rtb_MatrixConcatenate[0] = a[0];
      rtb_MatrixConcatenate[1] = a[1];
      rtb_MatrixConcatenate[2] = a[2];
      rtb_MatrixConcatenate[3] = a[3];

      // DataStoreWrite: '<S91>/Data Store Write4' incorporates:
      //   MATLAB Function: '<S99>/MATLAB Function'

      Red_x[0] = rtb_out[0];
      Red_x[1] = rtb_out[1];
      Red_x[2] = rtb_out[2];

      // MATLAB Function: '<S91>/MATLAB Function1' incorporates:
      //   DataStoreWrite: '<S12>/Data Store Write2'

      MPC_MATLABFunction_d(MPC_B.x_o, &rtb_out[0]);

      // MATLAB Function: '<S100>/MATLAB Function'
      Rot_error[0] = cos(rtb_out[5]);
      Rot_error[3] = sin(rtb_out[5]);
      Rot_error[6] = 0.0;
      Rot_error[1] = -sin(rtb_out[5]);
      Rot_error[4] = cos(rtb_out[5]);
      Rot_error[7] = 0.0;
      Rot_error[2] = 0.0;
      Rot_error[5] = 0.0;
      Rot_error[8] = 1.0;
      MPC_rotm2Quat(Rot_error, rtb_q_k);
      b_norm = sqrt(((rtb_q_k[0] * rtb_q_k[0] + rtb_q_k[1] * rtb_q_k[1]) +
                     rtb_q_k[2] * rtb_q_k[2]) + rtb_q_k[3] * rtb_q_k[3]);
      rtb_q_k[0] /= b_norm;
      rtb_q_k[1] /= b_norm;
      rtb_q_k[2] /= b_norm;
      rtb_q_k[3] /= b_norm;
      rtb_TSamp_lb = 2.0 * acos(rtb_q_k[0]);
      rtb_TSamp = sin(rtb_TSamp_lb / 2.0);
      a[0] = rtb_q_k[1] / rtb_TSamp;
      a[1] = rtb_q_k[2] / rtb_TSamp;
      a[2] = rtb_q_k[3] / rtb_TSamp;
      rEQ0 = rtIsNaN(a[0]);
      if (!rEQ0) {
        rEQ0 = rtIsNaN(a[1]);
      }

      if (!rEQ0) {
        rEQ0 = rtIsNaN(a[2]);
      }

      if (!rEQ0) {
        rEQ0 = rtIsNaN(rtb_TSamp_lb);
      }

      if (rEQ0) {
        a[0] = 1.0;
        a[1] = 0.0;
        a[2] = 0.0;
        a[3] = 0.0;
      } else {
        if (rtIsNaN(rtb_TSamp_lb + 3.1415926535897931)) {
          b_norm = (rtNaN);
        } else if (rtIsInf(rtb_TSamp_lb + 3.1415926535897931)) {
          b_norm = (rtNaN);
        } else if (rtb_TSamp_lb + 3.1415926535897931 == 0.0) {
          b_norm = 0.0;
        } else {
          b_norm = fmod(rtb_TSamp_lb + 3.1415926535897931, 6.2831853071795862);
          rEQ0 = (b_norm == 0.0);
          if (!rEQ0) {
            rtb_TSamp = fabs((rtb_TSamp_lb + 3.1415926535897931) /
                             6.2831853071795862);
            rEQ0 = !(fabs(rtb_TSamp - floor(rtb_TSamp + 0.5)) >
                     2.2204460492503131E-16 * rtb_TSamp);
          }

          if (rEQ0) {
            b_norm = 0.0;
          } else if (b_norm < 0.0) {
            b_norm += 6.2831853071795862;
          }
        }

        rtb_TSamp = 3.3121686421112381E-170;
        rtb_TSamp_e = fabs(a[0]);
        if (rtb_TSamp_e > 3.3121686421112381E-170) {
          rtb_TSamp_lb = 1.0;
          rtb_TSamp = rtb_TSamp_e;
        } else {
          rtb_TSamp_jb = rtb_TSamp_e / 3.3121686421112381E-170;
          rtb_TSamp_lb = rtb_TSamp_jb * rtb_TSamp_jb;
        }

        rtb_TSamp_e = fabs(a[1]);
        if (rtb_TSamp_e > rtb_TSamp) {
          rtb_TSamp_jb = rtb_TSamp / rtb_TSamp_e;
          rtb_TSamp_lb = rtb_TSamp_lb * rtb_TSamp_jb * rtb_TSamp_jb + 1.0;
          rtb_TSamp = rtb_TSamp_e;
        } else {
          rtb_TSamp_jb = rtb_TSamp_e / rtb_TSamp;
          rtb_TSamp_lb += rtb_TSamp_jb * rtb_TSamp_jb;
        }

        rtb_TSamp_e = fabs(a[2]);
        if (rtb_TSamp_e > rtb_TSamp) {
          rtb_TSamp_jb = rtb_TSamp / rtb_TSamp_e;
          rtb_TSamp_lb = rtb_TSamp_lb * rtb_TSamp_jb * rtb_TSamp_jb + 1.0;
          rtb_TSamp = rtb_TSamp_e;
        } else {
          rtb_TSamp_jb = rtb_TSamp_e / rtb_TSamp;
          rtb_TSamp_lb += rtb_TSamp_jb * rtb_TSamp_jb;
        }

        rtb_TSamp_lb = rtb_TSamp * sqrt(rtb_TSamp_lb);
        axis[0] = a[0] / rtb_TSamp_lb;
        axis[1] = a[1] / rtb_TSamp_lb;
        axis[2] = a[2] / rtb_TSamp_lb;
        rtb_TSamp_lb = (b_norm - 3.1415926535897931) / 2.0;
        rtb_TSamp_e = sin(rtb_TSamp_lb);
        a[0] = cos(rtb_TSamp_lb);
        a[1] = axis[0] * rtb_TSamp_e;
        a[2] = axis[1] * rtb_TSamp_e;
        a[3] = axis[2] * rtb_TSamp_e;
      }

      rtb_q_k[0] = a[0];
      rtb_q_k[1] = a[1];
      rtb_q_k[2] = a[2];
      rtb_q_k[3] = a[3];

      // MATLAB Function: '<S91>/MATLAB Function11' incorporates:
      //   DataStoreRead: '<S91>/Data Store Read14'
      //   DataStoreRead: '<S91>/Data Store Read20'
      //   DataStoreWrite: '<S91>/Data Store Write2'
      //   MATLAB Function: '<S99>/MATLAB Function'

      MPC_MATLABFunction11(rtb_MatrixConcatenate, MPC_DW.Vis_q_zoh,
                           MPC_DW.Vis_x_zoh, b, rtb_TmpSignalConversionAtSFun_o);

      // MATLAB Function: '<S91>/MATLAB Function12' incorporates:
      //   DataStoreRead: '<S91>/Data Store Read18'
      //   DataStoreRead: '<S91>/Data Store Read21'
      //   DataStoreWrite: '<S91>/Data Store Write2'
      //   MATLAB Function: '<S99>/MATLAB Function'

      MPC_MATLABFunction11(rtb_MatrixConcatenate, MPC_DW.Vis_q, MPC_DW.Vis_x, b,
                           rtb_TmpSignalConversionAtSFun_o);

      // DataStoreWrite: '<S92>/Data Store Write28' incorporates:
      //   DataStoreRead: '<S92>/Data Store Read13'
      //   DataStoreWrite: '<S91>/Data Store Write8'
      //   MATLAB Function: '<S100>/MATLAB Function'
      //   MATLAB Function: '<S92>/MATLAB Function1'

      MPC_MATLABFunction_g(rtb_q_k, &rtb_out[0], &rtb_out[9], &rtb_out[6],
                           MPC_DW.STQMEKFx, MPC_DW.STQMEKFerror);

      // DataStoreWrite: '<S92>/Data Store Write31' incorporates:
      //   DataStoreRead: '<S92>/Data Store Read26'
      //   DataStoreWrite: '<S91>/Data Store Write8'
      //   MATLAB Function: '<S100>/MATLAB Function'
      //   MATLAB Function: '<S92>/MATLAB Function2'

      MPC_MATLABFunction_g(rtb_q_k, &rtb_out[0], &rtb_out[9], &rtb_out[6],
                           MPC_DW.RMEKFx, MPC_DW.RMEKFerror);

      // MATLAB Function: '<S92>/MATLAB Function3' incorporates:
      //   DataStoreRead: '<S92>/Data Store Read21'

      axis[0] = MPC_DW.Vis_q_zoh[1];
      axis[1] = MPC_DW.Vis_q_zoh[2];
      axis[2] = MPC_DW.Vis_q_zoh[3];
      rtb_TSamp_e = MPC_DW.Vis_q_zoh[0];
      Rot_error[0] = 0.0;
      Rot_error[3] = -MPC_DW.Vis_q_zoh[3];
      Rot_error[6] = MPC_DW.Vis_q_zoh[2];
      Rot_error[1] = MPC_DW.Vis_q_zoh[3];
      Rot_error[4] = 0.0;
      Rot_error[7] = -MPC_DW.Vis_q_zoh[1];
      Rot_error[2] = -MPC_DW.Vis_q_zoh[2];
      Rot_error[5] = MPC_DW.Vis_q_zoh[1];
      Rot_error[8] = 0.0;
      q_0[0] = MPC_DW.Vis_q_zoh[0];
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_jb = axis[rtemp];
        BLACK_Estimated_Covar_tmp = (rtemp + 1) << 2;
        q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
        q_0[rtemp + 1] = rtb_TSamp_jb;
        q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 * rtemp])
          * rtb_TSamp_e + Rot_error[3 * rtemp];
        i = 3 * rtemp + 1;
        q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp_e + Rot_error[i];
        i = 3 * rtemp + 2;
        q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp_e + Rot_error[i];
      }

      // DataStoreWrite: '<S91>/Data Store Write2' incorporates:
      //   MATLAB Function: '<S92>/MATLAB Function3'

      rtb_TSamp_lb = rtb_MatrixConcatenate[1];
      rtb_TSamp_e = rtb_MatrixConcatenate[0];
      rtb_TSamp_jb = rtb_MatrixConcatenate[2];
      b_norm = rtb_MatrixConcatenate[3];

      // MATLAB Function: '<S92>/MATLAB Function3' incorporates:
      //   DataStoreWrite: '<S91>/Data Store Write2'

      for (rtemp = 0; rtemp < 4; rtemp++) {
        rtb_TSamp = ((q_0[rtemp + 4] * rtb_TSamp_lb + q_0[rtemp] * rtb_TSamp_e)
                     + q_0[rtemp + 8] * rtb_TSamp_jb) + q_0[rtemp + 12] * b_norm;
        rtb_y_i1[rtemp] = rtb_TSamp;
        a[rtemp] = rtb_TSamp * rtb_TSamp;
      }

      b_norm = sqrt(((a[0] + a[1]) + a[2]) + a[3]);
      rtb_y_i1[0] /= b_norm;
      rtb_y_i1[1] /= b_norm;
      rtb_y_i1[2] /= b_norm;
      rtb_y_i1[3] /= b_norm;
      rtb_TSamp_lb = 2.0 * acos(rtb_y_i1[0]);
      rtb_TSamp = sin(rtb_TSamp_lb / 2.0);
      a[0] = rtb_y_i1[1] / rtb_TSamp;
      a[1] = rtb_y_i1[2] / rtb_TSamp;
      a[2] = rtb_y_i1[3] / rtb_TSamp;
      rEQ0 = rtIsNaN(a[0]);
      if (!rEQ0) {
        rEQ0 = rtIsNaN(a[1]);
      }

      if (!rEQ0) {
        rEQ0 = rtIsNaN(a[2]);
      }

      if (!rEQ0) {
        rEQ0 = rtIsNaN(rtb_TSamp_lb);
      }

      if (rEQ0) {
        a[0] = 1.0;
        a[1] = 0.0;
        a[2] = 0.0;
        a[3] = 0.0;
      } else {
        if (rtIsNaN(rtb_TSamp_lb + 3.1415926535897931)) {
          b_norm = (rtNaN);
        } else if (rtIsInf(rtb_TSamp_lb + 3.1415926535897931)) {
          b_norm = (rtNaN);
        } else if (rtb_TSamp_lb + 3.1415926535897931 == 0.0) {
          b_norm = 0.0;
        } else {
          b_norm = fmod(rtb_TSamp_lb + 3.1415926535897931, 6.2831853071795862);
          rEQ0 = (b_norm == 0.0);
          if (!rEQ0) {
            rtb_TSamp = fabs((rtb_TSamp_lb + 3.1415926535897931) /
                             6.2831853071795862);
            rEQ0 = !(fabs(rtb_TSamp - floor(rtb_TSamp + 0.5)) >
                     2.2204460492503131E-16 * rtb_TSamp);
          }

          if (rEQ0) {
            b_norm = 0.0;
          } else if (b_norm < 0.0) {
            b_norm += 6.2831853071795862;
          }
        }

        rtb_TSamp = 3.3121686421112381E-170;
        rtb_TSamp_e = fabs(a[0]);
        if (rtb_TSamp_e > 3.3121686421112381E-170) {
          rtb_TSamp_lb = 1.0;
          rtb_TSamp = rtb_TSamp_e;
        } else {
          rtb_TSamp_jb = rtb_TSamp_e / 3.3121686421112381E-170;
          rtb_TSamp_lb = rtb_TSamp_jb * rtb_TSamp_jb;
        }

        rtb_TSamp_e = fabs(a[1]);
        if (rtb_TSamp_e > rtb_TSamp) {
          rtb_TSamp_jb = rtb_TSamp / rtb_TSamp_e;
          rtb_TSamp_lb = rtb_TSamp_lb * rtb_TSamp_jb * rtb_TSamp_jb + 1.0;
          rtb_TSamp = rtb_TSamp_e;
        } else {
          rtb_TSamp_jb = rtb_TSamp_e / rtb_TSamp;
          rtb_TSamp_lb += rtb_TSamp_jb * rtb_TSamp_jb;
        }

        rtb_TSamp_e = fabs(a[2]);
        if (rtb_TSamp_e > rtb_TSamp) {
          rtb_TSamp_jb = rtb_TSamp / rtb_TSamp_e;
          rtb_TSamp_lb = rtb_TSamp_lb * rtb_TSamp_jb * rtb_TSamp_jb + 1.0;
          rtb_TSamp = rtb_TSamp_e;
        } else {
          rtb_TSamp_jb = rtb_TSamp_e / rtb_TSamp;
          rtb_TSamp_lb += rtb_TSamp_jb * rtb_TSamp_jb;
        }

        rtb_TSamp_lb = rtb_TSamp * sqrt(rtb_TSamp_lb);
        axis[0] = a[0] / rtb_TSamp_lb;
        axis[1] = a[1] / rtb_TSamp_lb;
        axis[2] = a[2] / rtb_TSamp_lb;
        rtb_TSamp_lb = (b_norm - 3.1415926535897931) / 2.0;
        rtb_TSamp_e = sin(rtb_TSamp_lb);
        a[0] = cos(rtb_TSamp_lb);
        a[1] = axis[0] * rtb_TSamp_e;
        a[2] = axis[1] * rtb_TSamp_e;
        a[3] = axis[2] * rtb_TSamp_e;
      }

      // MATLAB Function: '<S92>/MATLAB Function5' incorporates:
      //   DataStoreRead: '<S92>/Data Store Read20'
      //   DataStoreWrite: '<S91>/Data Store Write2'

      b_norm = sqrt(((rtb_MatrixConcatenate[0] * rtb_MatrixConcatenate[0] +
                      rtb_MatrixConcatenate[1] * rtb_MatrixConcatenate[1]) +
                     rtb_MatrixConcatenate[2] * rtb_MatrixConcatenate[2]) +
                    rtb_MatrixConcatenate[3] * rtb_MatrixConcatenate[3]);
      rtb_TSamp_lb = rtb_MatrixConcatenate[0] / b_norm;
      rtb_TSamp_e = rtb_MatrixConcatenate[1] / b_norm;
      rtb_TSamp_jb = rtb_MatrixConcatenate[2] / b_norm;
      b_norm = rtb_MatrixConcatenate[3] / b_norm;
      for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 4;
           BLACK_Estimated_Covar_tmp++) {
        rtb_TSamp = ((static_cast<real_T>(b_0[BLACK_Estimated_Covar_tmp + 4]) *
                      rtb_TSamp_e + static_cast<real_T>
                      (b_0[BLACK_Estimated_Covar_tmp]) * rtb_TSamp_lb) +
                     static_cast<real_T>(b_0[BLACK_Estimated_Covar_tmp + 8]) *
                     rtb_TSamp_jb) + static_cast<real_T>
          (b_0[BLACK_Estimated_Covar_tmp + 12]) * b_norm;
        q[BLACK_Estimated_Covar_tmp] = rtb_TSamp;
        rtb_y_i1[BLACK_Estimated_Covar_tmp] = rtb_TSamp * rtb_TSamp;
      }

      b_norm = sqrt(((rtb_y_i1[0] + rtb_y_i1[1]) + rtb_y_i1[2]) + rtb_y_i1[3]);
      axis[0] = q[1];
      axis[1] = q[2];
      axis[2] = q[3];
      rtb_TSamp = q[0];
      Rot_error[0] = 0.0;
      Rot_error[3] = -q[3];
      Rot_error[6] = q[2];
      Rot_error[1] = q[3];
      Rot_error[4] = 0.0;
      Rot_error[7] = -q[1];
      Rot_error[2] = -q[2];
      Rot_error[5] = q[1];
      Rot_error[8] = 0.0;
      q_0[0] = q[0];
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_jb = axis[rtemp];
        BLACK_Estimated_Covar_tmp = (rtemp + 1) << 2;
        q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
        q_0[rtemp + 1] = rtb_TSamp_jb;
        q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 * rtemp])
          * rtb_TSamp + Rot_error[3 * rtemp];
        i = 3 * rtemp + 1;
        q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
        i = 3 * rtemp + 2;
        q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
        rtb_y_i1[rtemp + 1] = MPC_DW.Vis_x_zoh[rtemp];
      }

      rtb_TSamp_e = rtb_y_i1[1];
      rtb_TSamp_jb = rtb_y_i1[2];
      rtb_y_eu = rtb_y_i1[3];
      for (i = 0; i < 4; i++) {
        rtb_y_i1[i] = ((q_0[i + 4] * rtb_TSamp_e + q_0[i] * 0.0) + q_0[i + 8] *
                       rtb_TSamp_jb) + q_0[i + 12] * rtb_y_eu;

        // SignalConversion generated from: '<S110>/ SFunction ' incorporates:
        //   DataStoreWrite: '<S91>/Data Store Write8'
        //   MATLAB Function: '<S92>/MATLAB Function7'

        rtb_TmpSignalConversionAtSFun_o[i] = rtb_q_k[i];
      }

      axis[0] = rtb_y_i1[1];
      axis[1] = rtb_y_i1[2];
      axis[2] = rtb_y_i1[3];
      rtb_TSamp = rtb_y_i1[0];
      Rot_error[0] = 0.0;
      Rot_error[3] = -rtb_y_i1[3];
      Rot_error[6] = rtb_y_i1[2];
      Rot_error[1] = rtb_y_i1[3];
      Rot_error[4] = 0.0;
      Rot_error[7] = -rtb_y_i1[1];
      Rot_error[2] = -rtb_y_i1[2];
      Rot_error[5] = rtb_y_i1[1];
      Rot_error[8] = 0.0;
      b_norm *= b_norm;
      q_0[0] = rtb_y_i1[0];
      for (i = 0; i < 3; i++) {
        // SignalConversion generated from: '<S110>/ SFunction ' incorporates:
        //   MATLAB Function: '<S100>/MATLAB Function'
        //   MATLAB Function: '<S92>/MATLAB Function7'

        rtb_TmpSignalConversionAtSFun_o[i + 4] = rtb_out[i];

        // MATLAB Function: '<S92>/MATLAB Function5'
        rtb_TSamp_jb = axis[i];
        BLACK_Estimated_Covar_tmp = (i + 1) << 2;
        q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
        q_0[i + 1] = rtb_TSamp_jb;
        q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 * i]) *
          rtb_TSamp + Rot_error[3 * i];
        r2 = 3 * i + 1;
        q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[r2]) *
          rtb_TSamp + Rot_error[r2];
        r2 = 3 * i + 2;
        q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[r2]) *
          rtb_TSamp + Rot_error[r2];
      }

      // MATLAB Function: '<S92>/MATLAB Function5'
      rtb_TSamp_lb = q[0] / b_norm;
      rtb_TSamp = -q[1] / b_norm;
      rtb_TSamp_e = -q[2] / b_norm;
      rtb_TSamp_jb = -q[3] / b_norm;
      for (rtemp = 0; rtemp < 4; rtemp++) {
        rtb_y_i1[rtemp] = ((q_0[rtemp + 4] * rtb_TSamp + q_0[rtemp] *
                            rtb_TSamp_lb) + q_0[rtemp + 8] * rtb_TSamp_e) +
          q_0[rtemp + 12] * rtb_TSamp_jb;

        // SignalConversion generated from: '<S110>/ SFunction ' incorporates:
        //   MATLAB Function: '<S92>/MATLAB Function3'
        //   MATLAB Function: '<S92>/MATLAB Function7'

        rtb_TmpSignalConversionAtSFun_a[rtemp] = a[rtemp];
      }

      // MATLAB Function: '<S92>/MATLAB Function7' incorporates:
      //   SignalConversion generated from: '<S110>/ SFunction '

      b_norm = sqrt(((rtb_TmpSignalConversionAtSFun_o[0] *
                      rtb_TmpSignalConversionAtSFun_o[0] +
                      rtb_TmpSignalConversionAtSFun_o[1] *
                      rtb_TmpSignalConversionAtSFun_o[1]) +
                     rtb_TmpSignalConversionAtSFun_o[2] *
                     rtb_TmpSignalConversionAtSFun_o[2]) +
                    rtb_TmpSignalConversionAtSFun_o[3] *
                    rtb_TmpSignalConversionAtSFun_o[3]);
      rtb_TSamp = rtb_TmpSignalConversionAtSFun_o[0] / b_norm;
      rtb_TmpSignalConversionAtSFun_o[0] = rtb_TSamp;
      a[0] = rtb_TSamp * rtb_TSamp;
      rtb_TSamp = rtb_TmpSignalConversionAtSFun_o[1] / b_norm;
      rtb_TmpSignalConversionAtSFun_o[1] = rtb_TSamp;
      a[1] = rtb_TSamp * rtb_TSamp;
      rtb_TSamp = rtb_TmpSignalConversionAtSFun_o[2] / b_norm;
      rtb_TmpSignalConversionAtSFun_o[2] = rtb_TSamp;
      a[2] = rtb_TSamp * rtb_TSamp;
      rtb_TSamp = rtb_TmpSignalConversionAtSFun_o[3] / b_norm;
      b_norm = sqrt(((a[0] + a[1]) + a[2]) + rtb_TSamp * rtb_TSamp);
      rtb_TSamp_e = b_norm * b_norm;
      a[0] = rtb_TmpSignalConversionAtSFun_o[0] / rtb_TSamp_e;
      rtb_TSamp_lb = -rtb_TmpSignalConversionAtSFun_o[1] / rtb_TSamp_e;
      rtb_TSamp_jb = -rtb_TmpSignalConversionAtSFun_o[2] / rtb_TSamp_e;
      rtb_TSamp_e = -rtb_TSamp / rtb_TSamp_e;
      axis[0] = rtb_TSamp_lb;
      axis[1] = rtb_TSamp_jb;
      axis[2] = rtb_TSamp_e;
      rtb_TSamp = a[0];
      Rot_error[0] = 0.0;
      Rot_error[3] = -rtb_TSamp_e;
      Rot_error[6] = rtb_TSamp_jb;
      Rot_error[1] = rtb_TSamp_e;
      Rot_error[4] = 0.0;
      Rot_error[7] = -rtb_TSamp_lb;
      Rot_error[2] = -rtb_TSamp_jb;
      Rot_error[5] = rtb_TSamp_lb;
      Rot_error[8] = 0.0;
      q_0[0] = a[0];
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_jb = axis[rtemp];
        BLACK_Estimated_Covar_tmp = (rtemp + 1) << 2;
        q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
        q_0[rtemp + 1] = rtb_TSamp_jb;
        q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 * rtemp])
          * rtb_TSamp + Rot_error[3 * rtemp];
        i = 3 * rtemp + 1;
        q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
        i = 3 * rtemp + 2;
        q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
      }

      rtb_TSamp_lb = rtb_TmpSignalConversionAtSFun_a[1];
      rtb_TSamp_e = rtb_TmpSignalConversionAtSFun_a[0];
      rtb_TSamp_jb = rtb_TmpSignalConversionAtSFun_a[2];
      b_norm = rtb_TmpSignalConversionAtSFun_a[3];
      for (i = 0; i < 4; i++) {
        rtb_TSamp = ((q_0[i + 4] * rtb_TSamp_lb + q_0[i] * rtb_TSamp_e) + q_0[i
                     + 8] * rtb_TSamp_jb) + q_0[i + 12] * b_norm;
        q[i] = rtb_TSamp;
        a[i] = rtb_TSamp * rtb_TSamp;
      }

      rtb_TSamp_lb = sqrt(((a[0] + a[1]) + a[2]) + a[3]);
      q[0] /= rtb_TSamp_lb;
      q[1] /= rtb_TSamp_lb;
      q[2] /= rtb_TSamp_lb;
      q[3] /= rtb_TSamp_lb;
      rtb_TSamp_lb = 2.0 * acos(q[0]);
      rtb_TSamp = sin(rtb_TSamp_lb / 2.0);
      a[0] = q[1] / rtb_TSamp;
      a[1] = q[2] / rtb_TSamp;
      a[2] = q[3] / rtb_TSamp;
      rEQ0 = rtIsNaN(a[0]);
      if (!rEQ0) {
        rEQ0 = rtIsNaN(a[1]);
      }

      if (!rEQ0) {
        rEQ0 = rtIsNaN(a[2]);
      }

      if (!rEQ0) {
        rEQ0 = rtIsNaN(rtb_TSamp_lb);
      }

      if (rEQ0) {
        q[0] = 1.0;
        q[3] = 0.0;
      } else {
        if (rtIsNaN(rtb_TSamp_lb + 3.1415926535897931)) {
          b_norm = (rtNaN);
        } else if (rtIsInf(rtb_TSamp_lb + 3.1415926535897931)) {
          b_norm = (rtNaN);
        } else if (rtb_TSamp_lb + 3.1415926535897931 == 0.0) {
          b_norm = 0.0;
        } else {
          b_norm = fmod(rtb_TSamp_lb + 3.1415926535897931, 6.2831853071795862);
          rEQ0 = (b_norm == 0.0);
          if (!rEQ0) {
            rtb_TSamp_lb = fabs((rtb_TSamp_lb + 3.1415926535897931) /
                                6.2831853071795862);
            rEQ0 = !(fabs(rtb_TSamp_lb - floor(rtb_TSamp_lb + 0.5)) >
                     2.2204460492503131E-16 * rtb_TSamp_lb);
          }

          if (rEQ0) {
            b_norm = 0.0;
          } else if (b_norm < 0.0) {
            b_norm += 6.2831853071795862;
          }
        }

        rtb_TSamp = 3.3121686421112381E-170;
        rtb_TSamp_e = fabs(a[0]);
        if (rtb_TSamp_e > 3.3121686421112381E-170) {
          rtb_TSamp_lb = 1.0;
          rtb_TSamp = rtb_TSamp_e;
        } else {
          rtb_TSamp_jb = rtb_TSamp_e / 3.3121686421112381E-170;
          rtb_TSamp_lb = rtb_TSamp_jb * rtb_TSamp_jb;
        }

        rtb_TSamp_e = fabs(a[1]);
        if (rtb_TSamp_e > rtb_TSamp) {
          rtb_TSamp_jb = rtb_TSamp / rtb_TSamp_e;
          rtb_TSamp_lb = rtb_TSamp_lb * rtb_TSamp_jb * rtb_TSamp_jb + 1.0;
          rtb_TSamp = rtb_TSamp_e;
        } else {
          rtb_TSamp_jb = rtb_TSamp_e / rtb_TSamp;
          rtb_TSamp_lb += rtb_TSamp_jb * rtb_TSamp_jb;
        }

        rtb_TSamp_e = fabs(a[2]);
        if (rtb_TSamp_e > rtb_TSamp) {
          rtb_TSamp_jb = rtb_TSamp / rtb_TSamp_e;
          rtb_TSamp_lb = rtb_TSamp_lb * rtb_TSamp_jb * rtb_TSamp_jb + 1.0;
          rtb_TSamp = rtb_TSamp_e;
        } else {
          rtb_TSamp_jb = rtb_TSamp_e / rtb_TSamp;
          rtb_TSamp_lb += rtb_TSamp_jb * rtb_TSamp_jb;
        }

        rtb_TSamp_jb = (b_norm - 3.1415926535897931) / 2.0;
        q[0] = cos(rtb_TSamp_jb);
        q[3] = a[2] / (rtb_TSamp * sqrt(rtb_TSamp_lb)) * sin(rtb_TSamp_jb);
      }

      // DataStoreWrite: '<S92>/Data Store Write29' incorporates:
      //   MATLAB Function: '<S92>/MATLAB Function5'
      //   MATLAB Function: '<S92>/MATLAB Function7'
      //   MATLAB Function: '<S99>/MATLAB Function'

      MPC_DW.CNNError[0] = q[3] / (q[0] + 1.0);
      MPC_DW.CNNError[1] = rtb_TmpSignalConversionAtSFun_o[4] - (b[0] +
        rtb_y_i1[1]);
      MPC_DW.CNNError[2] = rtb_TmpSignalConversionAtSFun_o[5] - (b[1] +
        rtb_y_i1[2]);

      // DataStoreWrite: '<S92>/Data Store Write27' incorporates:
      //   DataStoreRead: '<S92>/Data Store Read8'
      //   DataStoreWrite: '<S91>/Data Store Write8'
      //   MATLAB Function: '<S100>/MATLAB Function'
      //   MATLAB Function: '<S92>/MATLAB Function'

      MPC_MATLABFunction_g(rtb_q_k, &rtb_out[0], &rtb_out[9], &rtb_out[6],
                           MPC_DW.QMEKFx, MPC_DW.QMEKFerror);

      // DataStoreWrite: '<S92>/Data Store Write30' incorporates:
      //   DataStoreRead: '<S92>/Data Store Read32'
      //   DataStoreWrite: '<S91>/Data Store Write8'
      //   MATLAB Function: '<S100>/MATLAB Function'
      //   MATLAB Function: '<S92>/MATLAB Function4'

      MPC_MATLABFunction_g(rtb_q_k, &rtb_out[0], &rtb_out[9], &rtb_out[6],
                           MPC_DW.STRMEKFx, MPC_DW.STRMEKFerror);

      // MATLAB Function: '<S92>/MATLAB Function6' incorporates:
      //   DataStoreRead: '<S92>/Data Store Read37'
      //   DataStoreWrite: '<S91>/Data Store Write8'
      //   MATLAB Function: '<S100>/MATLAB Function'

      MPC_MATLABFunction_g(rtb_q_k, &rtb_out[0], &rtb_out[9], &rtb_out[6],
                           MPC_DW.DQMEKFx, rtb_y_p);

      // DataStoreWrite: '<S92>/Data Store Write32'
      for (i = 0; i < 6; i++) {
        MPC_DW.DQMEKFerror[i] = rtb_y_p[i];
      }

      // End of DataStoreWrite: '<S92>/Data Store Write32'

      // MATLAB Function: '<S92>/MATLAB Function8' incorporates:
      //   DataStoreRead: '<S92>/Data Store Read42'
      //   DataStoreWrite: '<S91>/Data Store Write8'
      //   MATLAB Function: '<S100>/MATLAB Function'

      MPC_MATLABFunction_g(rtb_q_k, &rtb_out[0], &rtb_out[9], &rtb_out[6],
                           MPC_DW.STDQMEKFx, rtb_y_p);

      // DataStoreWrite: '<S92>/Data Store Write33'
      for (i = 0; i < 6; i++) {
        MPC_DW.STDQMEKFerror[i] = rtb_y_p[i];
      }

      // End of DataStoreWrite: '<S92>/Data Store Write33'

      // MATLAB Function: '<S97>/MATLAB Function1' incorporates:
      //   DataStoreRead: '<S97>/Data Store Read3'
      //   DataStoreRead: '<S97>/Data Store Read4'
      //   DataStoreWrite: '<S91>/Data Store Write2'
      //   DataStoreWrite: '<S97>/Data Store Write18'
      //   Delay: '<S97>/Delay'
      //   Delay: '<S97>/Delay1'
      //   MATLAB Function: '<S101>/MATLAB Function1'
      //   MATLAB Function: '<S102>/MATLAB Function1'
      //   MATLAB Function: '<S98>/MATLAB Function1'
      //   MATLAB Function: '<S99>/MATLAB Function'

      rtb_TmpSignalConversionAtSFun_o[0] = MPC_DW.Vis_q[0];
      rtb_TmpSignalConversionAtSFun_o[1] = MPC_DW.Vis_q[1];
      rtb_TmpSignalConversionAtSFun_o[2] = MPC_DW.Vis_q[2];
      rtb_TmpSignalConversionAtSFun_o[3] = MPC_DW.Vis_q[3];
      rtb_TmpSignalConversionAtSFun_o[4] = MPC_DW.Vis_x[0];
      rtb_TmpSignalConversionAtSFun_o[5] = MPC_DW.Vis_x[1];
      rtb_TmpSignalConversionAtSFun_o[6] = MPC_DW.Vis_x[2];
      rtb_TmpSignalConversionAtSFun_a[0] = rtb_MatrixConcatenate[0];
      rtb_TmpSignalConversionAtSFun_a[1] = rtb_MatrixConcatenate[1];
      rtb_TmpSignalConversionAtSFun_a[2] = rtb_MatrixConcatenate[2];
      rtb_TmpSignalConversionAtSFun_a[3] = rtb_MatrixConcatenate[3];
      rtb_TmpSignalConversionAtSFun_a[4] = b[0];
      rtb_TmpSignalConversionAtSFun_a[5] = b[1];
      rtb_TmpSignalConversionAtSFun_a[6] = b[2];
      MPC_tic(&savedTime);
      rtb_TSamp_jb = MPC_norm(&MPC_DW.Delay1_DSTATE_dn[4]);
      if (rtb_TSamp_jb > 1.0E-10) {
        rtb_TSamp_e = rtb_TSamp_jb * dt / 2.0;
        rtb_TSamp = sin(rtb_TSamp_e);
        q[0] = cos(rtb_TSamp_e);
        q[1] = MPC_DW.Delay1_DSTATE_dn[4] / rtb_TSamp_jb * rtb_TSamp;
        q[2] = MPC_DW.Delay1_DSTATE_dn[5] / rtb_TSamp_jb * rtb_TSamp;
        q[3] = MPC_DW.Delay1_DSTATE_dn[6] / rtb_TSamp_jb * rtb_TSamp;
      } else {
        q[0] = 1.0;
        q[1] = 0.0;
        q[2] = 0.0;
        q[3] = 0.0;
      }

      axis[0] = q[1];
      axis[1] = q[2];
      axis[2] = q[3];
      rtb_TSamp = q[0];
      Rot_error[0] = 0.0;
      Rot_error[3] = -q[3];
      Rot_error[6] = q[2];
      Rot_error[1] = q[3];
      Rot_error[4] = 0.0;
      Rot_error[7] = -q[1];
      Rot_error[2] = -q[2];
      Rot_error[5] = q[1];
      Rot_error[8] = 0.0;
      q_0[0] = q[0];
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_jb = axis[rtemp];
        BLACK_Estimated_Covar_tmp = (rtemp + 1) << 2;
        q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
        q_0[rtemp + 1] = rtb_TSamp_jb;
        q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 * rtemp])
          * rtb_TSamp + Rot_error[3 * rtemp];
        i = 3 * rtemp + 1;
        q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
        i = 3 * rtemp + 2;
        q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
      }

      rtb_TSamp_lb = MPC_DW.Delay1_DSTATE_dn[1];
      rtb_TSamp = MPC_DW.Delay1_DSTATE_dn[0];
      rtb_TSamp_e = MPC_DW.Delay1_DSTATE_dn[2];
      rtb_TSamp_jb = MPC_DW.Delay1_DSTATE_dn[3];
      for (rtemp = 0; rtemp < 4; rtemp++) {
        x_k[rtemp] = ((q_0[rtemp + 4] * rtb_TSamp_lb + q_0[rtemp] * rtb_TSamp) +
                      q_0[rtemp + 8] * rtb_TSamp_e) + q_0[rtemp + 12] *
          rtb_TSamp_jb;
      }

      x_k[4] = MPC_DW.Delay1_DSTATE_dn[4];
      x_k[7] = MPC_DW.Delay1_DSTATE_dn[10] * dt + MPC_DW.Delay1_DSTATE_dn[7];
      x_k[10] = MPC_DW.Delay1_DSTATE_dn[10];
      x_k[5] = MPC_DW.Delay1_DSTATE_dn[5];
      x_k[8] = MPC_DW.Delay1_DSTATE_dn[11] * dt + MPC_DW.Delay1_DSTATE_dn[8];
      x_k[11] = MPC_DW.Delay1_DSTATE_dn[11];
      x_k[6] = MPC_DW.Delay1_DSTATE_dn[6];
      x_k[9] = MPC_DW.Delay1_DSTATE_dn[12] * dt + MPC_DW.Delay1_DSTATE_dn[9];
      x_k[12] = MPC_DW.Delay1_DSTATE_dn[12];
      for (rtemp = 0; rtemp < 27; rtemp++) {
        Phi_m_tmp[rtemp] = c_1[rtemp] * dt;
        Phi_m_tmp_0[rtemp] = 0.0 * dt;
      }

      tmp_1[0] = -0.0 * dt;
      tmp_1[9] = MPC_DW.Delay1_DSTATE_dn[6] / 2.0 * dt;
      tmp_1[18] = -MPC_DW.Delay1_DSTATE_dn[5] / 2.0 * dt;
      tmp_1[1] = -MPC_DW.Delay1_DSTATE_dn[6] / 2.0 * dt;
      tmp_1[10] = -0.0 * dt;
      tmp_1[19] = MPC_DW.Delay1_DSTATE_dn[4] / 2.0 * dt;
      tmp_1[2] = MPC_DW.Delay1_DSTATE_dn[5] / 2.0 * dt;
      tmp_1[11] = -MPC_DW.Delay1_DSTATE_dn[4] / 2.0 * dt;
      tmp_1[20] = -0.0 * dt;
      for (rtemp = 0; rtemp < 3; rtemp++) {
        BLACK_Estimated_Covar_tmp = (rtemp + 3) * 9;
        tmp_1[BLACK_Estimated_Covar_tmp] = F_tmp_0[3 * rtemp];
        i = (rtemp + 6) * 9;
        tmp_1[i] = 0.0 * dt;
        tmp_1[BLACK_Estimated_Covar_tmp + 1] = F_tmp_0[3 * rtemp + 1];
        tmp_1[i + 1] = 0.0 * dt;
        tmp_1[BLACK_Estimated_Covar_tmp + 2] = F_tmp_0[3 * rtemp + 2];
        tmp_1[i + 2] = 0.0 * dt;
      }

      for (rtemp = 0; rtemp < 9; rtemp++) {
        tmp_1[9 * rtemp + 3] = Phi_m_tmp[3 * rtemp];
        tmp_1[9 * rtemp + 6] = 0.0 * dt;
        tmp_1[9 * rtemp + 4] = Phi_m_tmp[3 * rtemp + 1];
        tmp_1[9 * rtemp + 7] = 0.0 * dt;
        tmp_1[9 * rtemp + 5] = Phi_m_tmp[3 * rtemp + 2];
        tmp_1[9 * rtemp + 8] = 0.0 * dt;
      }

      MPC_expm(tmp_1, Phi_m);
      for (rtemp = 0; rtemp < 36; rtemp++) {
        F_tmp_1[rtemp] = e_0[rtemp];
        BLACK_Estimated_Covar_1[rtemp] = d_0[rtemp];
      }

      for (rtemp = 0; rtemp < 6; rtemp++) {
        L[12 * rtemp] = Phi_m[9 * rtemp];
        L[12 * rtemp + 1] = Phi_m[9 * rtemp + 1];
        L[12 * rtemp + 2] = Phi_m[9 * rtemp + 2];
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        i = (rtemp + 6) * 12;
        L[i] = 0.0;
        BLACK_Estimated_Covar_tmp = (rtemp + 9) * 12;
        L[BLACK_Estimated_Covar_tmp] = 0.0;
        L[i + 1] = 0.0;
        L[BLACK_Estimated_Covar_tmp + 1] = 0.0;
        L[i + 2] = 0.0;
        L[BLACK_Estimated_Covar_tmp + 2] = 0.0;
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        L[12 * rtemp + 3] = BLACK_Estimated_Covar_1[3 * rtemp];
        L[12 * rtemp + 4] = BLACK_Estimated_Covar_1[3 * rtemp + 1];
        L[12 * rtemp + 5] = BLACK_Estimated_Covar_1[3 * rtemp + 2];
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        L[12 * rtemp + 6] = 0.0;
        i = (rtemp + 3) * 12;
        L[i + 6] = 0.0;
        BLACK_Estimated_Covar_tmp = (rtemp + 6) * 12;
        L[BLACK_Estimated_Covar_tmp + 6] = F_tmp[3 * rtemp];
        r3 = (rtemp + 9) * 12;
        L[r3 + 6] = F_tmp_0[3 * rtemp];
        L[12 * rtemp + 7] = 0.0;
        L[i + 7] = 0.0;
        r2 = 3 * rtemp + 1;
        L[BLACK_Estimated_Covar_tmp + 7] = F_tmp[r2];
        L[r3 + 7] = F_tmp_0[r2];
        L[12 * rtemp + 8] = 0.0;
        L[i + 8] = 0.0;
        i = 3 * rtemp + 2;
        L[BLACK_Estimated_Covar_tmp + 8] = F_tmp[i];
        L[r3 + 8] = F_tmp_0[i];
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        L[12 * rtemp + 9] = F_tmp_1[3 * rtemp];
        L[12 * rtemp + 10] = F_tmp_1[3 * rtemp + 1];
        L[12 * rtemp + 11] = F_tmp_1[3 * rtemp + 2];
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += L[12 * i + rtemp] * MPC_DW.Delay_DSTATE_g[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          L_0[rtemp + 12 * BLACK_Estimated_Covar_tmp] = rtb_TSamp;
        }

        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_e += L_0[12 * i + rtemp] * L[12 * i +
              BLACK_Estimated_Covar_tmp];
          }

          i = 12 * BLACK_Estimated_Covar_tmp + rtemp;
          P_k[i] = b_Q[i] + rtb_TSamp_e;
        }
      }

      b_norm = sqrt(((rtb_TmpSignalConversionAtSFun_a[0] *
                      rtb_TmpSignalConversionAtSFun_a[0] +
                      rtb_TmpSignalConversionAtSFun_a[1] *
                      rtb_TmpSignalConversionAtSFun_a[1]) +
                     rtb_TmpSignalConversionAtSFun_a[2] *
                     rtb_TmpSignalConversionAtSFun_a[2]) +
                    rtb_TmpSignalConversionAtSFun_a[3] *
                    rtb_TmpSignalConversionAtSFun_a[3]);
      rtb_TSamp_e = b_norm * b_norm;
      a[0] = rtb_TmpSignalConversionAtSFun_a[0] / rtb_TSamp_e;
      a[1] = -rtb_TmpSignalConversionAtSFun_a[1] / rtb_TSamp_e;
      a[2] = -rtb_TmpSignalConversionAtSFun_a[2] / rtb_TSamp_e;
      a[3] = -rtb_TmpSignalConversionAtSFun_a[3] / rtb_TSamp_e;
      for (i = 0; i < 7; i++) {
        z_bar[i] = 0.0 * rtb_TmpSignalConversionAtSFun_o[i];
      }

      b_norm = sqrt(((a[0] * a[0] + a[1] * a[1]) + a[2] * a[2]) + a[3] * a[3]);
      axis[0] = a[1];
      axis[1] = a[2];
      axis[2] = a[3];
      rtb_TSamp = a[0];
      Rot_error[0] = 0.0;
      Rot_error[3] = -a[3];
      Rot_error[6] = a[2];
      Rot_error[1] = a[3];
      Rot_error[4] = 0.0;
      Rot_error[7] = -a[1];
      Rot_error[2] = -a[2];
      Rot_error[5] = a[1];
      Rot_error[8] = 0.0;
      q_0[0] = a[0];
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_jb = axis[rtemp];
        BLACK_Estimated_Covar_tmp = (rtemp + 1) << 2;
        q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
        q_0[rtemp + 1] = rtb_TSamp_jb;
        q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 * rtemp])
          * rtb_TSamp + Rot_error[3 * rtemp];
        i = 3 * rtemp + 1;
        q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
        i = 3 * rtemp + 2;
        q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
        rtb_y_i1[rtemp + 1] = x_k[rtemp + 7] -
          rtb_TmpSignalConversionAtSFun_a[rtemp + 4];
      }

      rtb_TSamp_e = rtb_y_i1[1];
      rtb_TSamp_jb = rtb_y_i1[2];
      rtb_y_eu = rtb_y_i1[3];
      for (rtemp = 0; rtemp < 4; rtemp++) {
        rtb_y_i1[rtemp] = ((q_0[rtemp + 4] * rtb_TSamp_e + q_0[rtemp] * 0.0) +
                           q_0[rtemp + 8] * rtb_TSamp_jb) + q_0[rtemp + 12] *
          rtb_y_eu;
      }

      axis[0] = rtb_y_i1[1];
      axis[1] = rtb_y_i1[2];
      axis[2] = rtb_y_i1[3];
      rtb_TSamp = rtb_y_i1[0];
      Rot_error[0] = 0.0;
      Rot_error[3] = -rtb_y_i1[3];
      Rot_error[6] = rtb_y_i1[2];
      Rot_error[1] = rtb_y_i1[3];
      Rot_error[4] = 0.0;
      Rot_error[7] = -rtb_y_i1[1];
      Rot_error[2] = -rtb_y_i1[2];
      Rot_error[5] = rtb_y_i1[1];
      Rot_error[8] = 0.0;
      b_norm *= b_norm;
      q_0[0] = rtb_y_i1[0];
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_jb = axis[rtemp];
        BLACK_Estimated_Covar_tmp = (rtemp + 1) << 2;
        q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
        q_0[rtemp + 1] = rtb_TSamp_jb;
        q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 * rtemp])
          * rtb_TSamp + Rot_error[3 * rtemp];
        r2 = 3 * rtemp + 1;
        q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[r2]) *
          rtb_TSamp + Rot_error[r2];
        r2 = 3 * rtemp + 2;
        q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[r2]) *
          rtb_TSamp + Rot_error[r2];
      }

      rtb_TSamp = a[0] / b_norm;
      rtb_TSamp_e = -a[1] / b_norm;
      rtb_TSamp_jb = -a[2] / b_norm;
      b_norm = -a[3] / b_norm;
      for (rtemp = 0; rtemp < 4; rtemp++) {
        rtb_y_i1[rtemp] = ((q_0[rtemp + 4] * rtb_TSamp_e + q_0[rtemp] *
                            rtb_TSamp) + q_0[rtemp + 8] * rtb_TSamp_jb) +
          q_0[rtemp + 12] * b_norm;
      }

      axis[0] = x_k[1];
      axis[1] = x_k[2];
      axis[2] = x_k[3];
      rtb_TSamp = x_k[0];
      Rot_error[0] = 0.0;
      Rot_error[3] = -x_k[3];
      Rot_error[6] = x_k[2];
      Rot_error[1] = x_k[3];
      Rot_error[4] = 0.0;
      Rot_error[7] = -x_k[1];
      Rot_error[2] = -x_k[2];
      Rot_error[5] = x_k[1];
      Rot_error[8] = 0.0;
      q_0[0] = x_k[0];
      for (rtemp = 0; rtemp < 3; rtemp++) {
        z_bar[rtemp + 4] = rtb_y_i1[rtemp + 1];
        rtb_TSamp_jb = axis[rtemp];
        BLACK_Estimated_Covar_tmp = (rtemp + 1) << 2;
        q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
        q_0[rtemp + 1] = rtb_TSamp_jb;
        q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 * rtemp])
          * rtb_TSamp + Rot_error[3 * rtemp];
        i = 3 * rtemp + 1;
        q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
        i = 3 * rtemp + 2;
        q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
      }

      rtb_TSamp = a[1];
      b_norm = a[0];
      rtb_TSamp_e = a[2];
      rtb_TSamp_jb = a[3];
      for (rtemp = 0; rtemp < 4; rtemp++) {
        z_bar[rtemp] = ((q_0[rtemp + 4] * rtb_TSamp + q_0[rtemp] * b_norm) +
                        q_0[rtemp + 8] * rtb_TSamp_e) + q_0[rtemp + 12] *
          rtb_TSamp_jb;
      }

      MPC_smallQuat(&z_bar[0], rtb_y_i1);
      z_bar[0] = rtb_y_i1[0];
      z_bar[1] = rtb_y_i1[1];
      z_bar[2] = rtb_y_i1[2];
      z_bar[3] = rtb_y_i1[3];
      rtb_TSamp = a[0];
      b_norm = a[1];
      rtb_TSamp_e = a[2];
      rtb_TSamp_jb = a[3];
      for (rtemp = 0; rtemp < 36; rtemp++) {
        H_tmp[rtemp] = f[rtemp];
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        H[6 * rtemp] = H_tmp[3 * rtemp];
        H[6 * rtemp + 1] = H_tmp[3 * rtemp + 1];
        H[6 * rtemp + 2] = H_tmp[3 * rtemp + 2];
      }

      rtb_y_eu = -rtb_TSamp_jb * -rtb_TSamp_jb;
      rtb_y_gs = -rtb_TSamp_e * -rtb_TSamp_e;
      H[39] = 1.0 - (rtb_y_gs + rtb_y_eu) * 2.0;
      e_in_tmp = -b_norm * -rtb_TSamp_e;
      e_in_0 = rtb_TSamp * -rtb_TSamp_jb;
      H[45] = (e_in_tmp + e_in_0) * 2.0;
      H_tmp_0 = (-b_norm * -rtb_TSamp_jb + rtb_TSamp * -rtb_TSamp_e) * 2.0;
      H[51] = H_tmp_0;
      H[40] = (e_in_tmp - e_in_0) * 2.0;
      e_in_tmp = -b_norm * -b_norm;
      H[46] = 1.0 - (e_in_tmp + rtb_y_eu) * 2.0;
      rtb_y_eu = -rtb_TSamp_e * -rtb_TSamp_jb;
      e_in_0 = rtb_TSamp * -b_norm;
      H[52] = (rtb_y_eu + e_in_0) * 2.0;
      H[41] = H_tmp_0;
      H[47] = (rtb_y_eu - e_in_0) * 2.0;
      H[53] = 1.0 - (e_in_tmp + rtb_y_gs) * 2.0;
      for (rtemp = 0; rtemp < 3; rtemp++) {
        H[6 * rtemp + 3] = 0.0;
        r2 = (rtemp + 3) * 6;
        H[r2 + 3] = 0.0;
        BLACK_Estimated_Covar_tmp = (rtemp + 9) * 6;
        H[BLACK_Estimated_Covar_tmp + 3] = 0.0;
        H[6 * rtemp + 4] = 0.0;
        H[r2 + 4] = 0.0;
        H[BLACK_Estimated_Covar_tmp + 4] = 0.0;
        H[6 * rtemp + 5] = 0.0;
        H[r2 + 5] = 0.0;
        H[BLACK_Estimated_Covar_tmp + 5] = 0.0;
      }

      rEQ0 = false;
      for (i = 0; i < 7; i++) {
        if (!rEQ0) {
          rEQ0 = rtIsNaN(rtb_TmpSignalConversionAtSFun_o[i]);
        }
      }

      if (!rEQ0) {
        rtb_TSamp_e = MPC_rand();
        rtb_y_i1[3] = (rtb_TSamp_e - 0.5) * 0.0;
        axis[0] = 0.0;
        axis[1] = 0.0;
        axis[2] = 1.0;
        rtb_TSamp_e = MPC_norm(axis);
        rtb_TSamp_jb = sin(rtb_y_i1[3] / 2.0);
        q[0] = cos(rtb_y_i1[3] / 2.0);
        b_norm = 0.0 / rtb_TSamp_e * rtb_TSamp_jb;
        rtb_TSamp_jb *= 1.0 / rtb_TSamp_e;
        axis[0] = b_norm;
        axis[1] = b_norm;
        axis[2] = rtb_TSamp_jb;
        rtb_TSamp = q[0];
        Rot_error[0] = 0.0;
        Rot_error[3] = -rtb_TSamp_jb;
        Rot_error[6] = b_norm;
        Rot_error[1] = rtb_TSamp_jb;
        Rot_error[4] = 0.0;
        Rot_error[7] = -b_norm;
        Rot_error[2] = -b_norm;
        Rot_error[5] = b_norm;
        Rot_error[8] = 0.0;
        q_0[0] = q[0];
        for (rtemp = 0; rtemp < 3; rtemp++) {
          rtb_TSamp_jb = axis[rtemp];
          BLACK_Estimated_Covar_tmp = (rtemp + 1) << 2;
          q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
          q_0[rtemp + 1] = rtb_TSamp_jb;
          q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 *
            rtemp]) * rtb_TSamp + Rot_error[3 * rtemp];
          i = 3 * rtemp + 1;
          q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[i]) *
            rtb_TSamp + Rot_error[i];
          i = 3 * rtemp + 2;
          q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[i]) *
            rtb_TSamp + Rot_error[i];
        }

        rtb_TSamp = rtb_TmpSignalConversionAtSFun_o[1];
        rtb_TSamp_e = rtb_TmpSignalConversionAtSFun_o[0];
        rtb_TSamp_jb = rtb_TmpSignalConversionAtSFun_o[2];
        b_norm = rtb_TmpSignalConversionAtSFun_o[3];
        for (rtemp = 0; rtemp < 4; rtemp++) {
          q[rtemp] = ((q_0[rtemp + 4] * rtb_TSamp + q_0[rtemp] * rtb_TSamp_e) +
                      q_0[rtemp + 8] * rtb_TSamp_jb) + q_0[rtemp + 12] * b_norm;
        }

        rtb_TmpSignalConversionAtSFun_o[0] = q[0];
        rtb_TmpSignalConversionAtSFun_o[1] = q[1];
        rtb_TmpSignalConversionAtSFun_o[2] = q[2];
        rtb_TmpSignalConversionAtSFun_o[3] = q[3];
      }

      axis[0] = rtb_TmpSignalConversionAtSFun_o[1];
      axis[1] = rtb_TmpSignalConversionAtSFun_o[2];
      axis[2] = rtb_TmpSignalConversionAtSFun_o[3];
      rtb_TSamp = rtb_TmpSignalConversionAtSFun_o[0];
      Rot_error[0] = 0.0;
      Rot_error[3] = -rtb_TmpSignalConversionAtSFun_o[3];
      Rot_error[6] = rtb_TmpSignalConversionAtSFun_o[2];
      Rot_error[1] = rtb_TmpSignalConversionAtSFun_o[3];
      Rot_error[4] = 0.0;
      Rot_error[7] = -rtb_TmpSignalConversionAtSFun_o[1];
      Rot_error[2] = -rtb_TmpSignalConversionAtSFun_o[2];
      Rot_error[5] = rtb_TmpSignalConversionAtSFun_o[1];
      Rot_error[8] = 0.0;
      q_0[0] = rtb_TmpSignalConversionAtSFun_o[0];
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_jb = axis[rtemp];
        BLACK_Estimated_Covar_tmp = (rtemp + 1) << 2;
        q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
        q_0[rtemp + 1] = rtb_TSamp_jb;
        q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 * rtemp])
          * rtb_TSamp + Rot_error[3 * rtemp];
        i = 3 * rtemp + 1;
        q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
        i = 3 * rtemp + 2;
        q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
      }

      rtb_TSamp = z_bar[0];
      rtb_TSamp_e = -z_bar[1];
      rtb_TSamp_jb = -z_bar[2];
      b_norm = -z_bar[3];
      for (rtemp = 0; rtemp < 4; rtemp++) {
        rtb_q_k[rtemp] = ((q_0[rtemp + 4] * rtb_TSamp_e + q_0[rtemp] * rtb_TSamp)
                          + q_0[rtemp + 8] * rtb_TSamp_jb) + q_0[rtemp + 12] *
          b_norm;
      }

      MPC_smallQuat(rtb_q_k, q);
      MPC_DW.QMEKFerror[0] = q[1] / (q[0] + 1.0);
      MPC_DW.QMEKFerror[1] = q[2] / (q[0] + 1.0);
      MPC_DW.QMEKFerror[2] = q[3] / (q[0] + 1.0);
      MPC_DW.QMEKFerror[3] = rtb_TmpSignalConversionAtSFun_o[4] - z_bar[4];
      MPC_DW.QMEKFerror[4] = rtb_TmpSignalConversionAtSFun_o[5] - z_bar[5];
      MPC_DW.QMEKFerror[5] = rtb_TmpSignalConversionAtSFun_o[6] - z_bar[6];
      rEQ0 = rtIsNaN(rtb_TmpSignalConversionAtSFun_o[0]);
      if (!rEQ0) {
        rEQ0 = rtIsNaN(rtb_TmpSignalConversionAtSFun_o[1]);
      }

      if (!rEQ0) {
        rEQ0 = rtIsNaN(rtb_TmpSignalConversionAtSFun_o[2]);
      }

      if (!rEQ0) {
        rEQ0 = rtIsNaN(rtb_TmpSignalConversionAtSFun_o[3]);
      }

      if (rEQ0) {
        rEQ0 = true;
      } else {
        for (rtemp = 0; rtemp < 3; rtemp++) {
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
               BLACK_Estimated_Covar_tmp++) {
            rtb_TSamp = 0.0;
            for (i = 0; i < 12; i++) {
              rtb_TSamp += H[6 * i + rtemp] * P_k[12 * BLACK_Estimated_Covar_tmp
                + i];
            }

            BLACK_Estimated_Covar_0[rtemp + 3 * BLACK_Estimated_Covar_tmp] =
              rtb_TSamp;
          }

          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
               BLACK_Estimated_Covar_tmp++) {
            rtb_TSamp = 0.0;
            for (i = 0; i < 12; i++) {
              rtb_TSamp += BLACK_Estimated_Covar_0[3 * i + rtemp] * H[6 * i +
                BLACK_Estimated_Covar_tmp];
            }

            Rot_error[rtemp + 3 * BLACK_Estimated_Covar_tmp] = rtb_TSamp;
          }
        }

        rtb_TSamp_e = 0.0;
        for (rtemp = 0; rtemp < 3; rtemp++) {
          rtb_TSamp_e += ((Rot_error[3 * rtemp + 1] * MPC_DW.QMEKFerror[1] +
                           Rot_error[3 * rtemp] * MPC_DW.QMEKFerror[0]) +
                          Rot_error[3 * rtemp + 2] * MPC_DW.QMEKFerror[2]) *
            MPC_DW.QMEKFerror[rtemp];
        }

        rEQ0 = !(sqrt(rtb_TSamp_e) < 1.6046);
      }

      rejectPose = rtIsNaN(rtb_TmpSignalConversionAtSFun_o[4]);
      if (!rejectPose) {
        rejectPose = rtIsNaN(rtb_TmpSignalConversionAtSFun_o[5]);
      }

      if (!rejectPose) {
        rejectPose = rtIsNaN(rtb_TmpSignalConversionAtSFun_o[6]);
      }

      if (rejectPose) {
        rejectPose = true;
      } else {
        for (rtemp = 0; rtemp < 3; rtemp++) {
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
               BLACK_Estimated_Covar_tmp++) {
            rtb_TSamp = 0.0;
            for (i = 0; i < 12; i++) {
              rtb_TSamp += H[(6 * i + rtemp) + 3] * P_k[12 *
                BLACK_Estimated_Covar_tmp + i];
            }

            BLACK_Estimated_Covar_0[rtemp + 3 * BLACK_Estimated_Covar_tmp] =
              rtb_TSamp;
          }

          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
               BLACK_Estimated_Covar_tmp++) {
            rtb_TSamp = 0.0;
            for (i = 0; i < 12; i++) {
              rtb_TSamp += H[(6 * i + BLACK_Estimated_Covar_tmp) + 3] *
                BLACK_Estimated_Covar_0[3 * i + rtemp];
            }

            Rot_error[rtemp + 3 * BLACK_Estimated_Covar_tmp] = rtb_TSamp;
          }
        }

        rtb_TSamp_e = 0.0;
        for (rtemp = 0; rtemp < 3; rtemp++) {
          rtb_TSamp_e += ((Rot_error[3 * rtemp + 1] * MPC_DW.QMEKFerror[4] +
                           Rot_error[3 * rtemp] * MPC_DW.QMEKFerror[3]) +
                          Rot_error[3 * rtemp + 2] * MPC_DW.QMEKFerror[5]) *
            MPC_DW.QMEKFerror[rtemp + 3];
        }

        rejectPose = !(sqrt(rtb_TSamp_e) < 5.5866);
      }

      if (rEQ0) {
        MPC_DW.QMEKFerror[0] = 0.0;
        MPC_DW.QMEKFerror[1] = 0.0;
        MPC_DW.QMEKFerror[2] = 0.0;
        for (rtemp = 0; rtemp < 12; rtemp++) {
          H[6 * rtemp] = 0.0;
          H[6 * rtemp + 1] = 0.0;
          H[6 * rtemp + 2] = 0.0;
        }
      }

      if (rejectPose) {
        MPC_DW.QMEKFerror[3] = 0.0;
        MPC_DW.QMEKFerror[4] = 0.0;
        MPC_DW.QMEKFerror[5] = 0.0;
        for (rtemp = 0; rtemp < 12; rtemp++) {
          H[6 * rtemp + 3] = 0.0;
          H[6 * rtemp + 4] = 0.0;
          H[6 * rtemp + 5] = 0.0;
        }
      }

      for (rtemp = 0; rtemp < 6; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          K_tmp[BLACK_Estimated_Covar_tmp + 12 * rtemp] = H[6 *
            BLACK_Estimated_Covar_tmp + rtemp];
        }
      }

      for (rtemp = 0; rtemp < 6; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_e = 0.0;
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_e += P_k[12 * i + BLACK_Estimated_Covar_tmp] * K_tmp[12 *
              rtemp + i];
            rtb_TSamp += H[6 * i + rtemp] * P_k[12 * BLACK_Estimated_Covar_tmp +
              i];
          }

          K_0[BLACK_Estimated_Covar_tmp + 12 * rtemp] = rtb_TSamp_e;
          H_0[rtemp + 6 * BLACK_Estimated_Covar_tmp] = rtb_TSamp;
        }

        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_e += H_0[6 * i + rtemp] * K_tmp[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          r2 = 6 * BLACK_Estimated_Covar_tmp + rtemp;
          BLACK_Estimated_Covar_0[r2] = b_R[r2] + rtb_TSamp_e;
        }
      }

      MPC_mrdiv_n(K_0, BLACK_Estimated_Covar_0);
      QMEKFP_tmp_2 = &g[0];
      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp += K_0[12 * i + rtemp] * H[6 * BLACK_Estimated_Covar_tmp +
              i];
          }

          i = 12 * BLACK_Estimated_Covar_tmp + rtemp;
          L[i] = rtb_TSamp;
          QMEKFP_tmp[BLACK_Estimated_Covar_tmp + 12 * rtemp] = (&g[0])[i];
        }
      }

      for (rtemp = 0; rtemp < 144; rtemp++) {
        L_0[rtemp] = static_cast<real_T>((&g[0])[rtemp]) - L[rtemp];
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += L_0[12 * i + rtemp] * P_k[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          r2 = 12 * BLACK_Estimated_Covar_tmp + rtemp;
          QMEKFP_tmp_0[r2] = rtb_TSamp;
          i = 12 * rtemp + BLACK_Estimated_Covar_tmp;
          QMEKFP_tmp_1[i] = static_cast<real_T>(QMEKFP_tmp[i]) - L[r2];
        }

        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp_e += K_0[12 * i + rtemp] * b_R[6 *
              BLACK_Estimated_Covar_tmp + i];
          }

          H_0[rtemp + 12 * BLACK_Estimated_Covar_tmp] = rtb_TSamp_e;
        }
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += QMEKFP_tmp_0[12 * i + rtemp] * QMEKFP_tmp_1[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          r2 = 12 * BLACK_Estimated_Covar_tmp + rtemp;
          L_0[r2] = rtb_TSamp;
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp_e += H_0[12 * i + rtemp] * K_0[12 * i +
              BLACK_Estimated_Covar_tmp];
          }

          L[r2] = rtb_TSamp_e;
        }
      }

      for (rtemp = 0; rtemp < 144; rtemp++) {
        MPC_DW.QMEKFP[rtemp] = L_0[rtemp] + L[rtemp];
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        rtb_TSamp = 0.0;
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp += K_0[12 * BLACK_Estimated_Covar_tmp + rtemp] *
            MPC_DW.QMEKFerror[BLACK_Estimated_Covar_tmp];
        }

        delta_x[rtemp] = rtb_TSamp;
      }

      rtb_TSamp = MPC_norm(&delta_x[0]);
      rtb_TSamp *= rtb_TSamp;
      rtb_TSamp = (sqrt(rtb_TSamp * 0.0 + 1.0) - rtb_TSamp) / (rtb_TSamp + 1.0);
      rtb_TSamp_jb = (rtb_TSamp + 1.0) * delta_x[0];
      b_norm = (rtb_TSamp + 1.0) * delta_x[1];
      rtb_TSamp_e = (rtb_TSamp + 1.0) * delta_x[2];
      axis[0] = rtb_TSamp_jb;
      axis[1] = b_norm;
      axis[2] = rtb_TSamp_e;
      Rot_error[0] = 0.0;
      Rot_error[3] = -rtb_TSamp_e;
      Rot_error[6] = b_norm;
      Rot_error[1] = rtb_TSamp_e;
      Rot_error[4] = 0.0;
      Rot_error[7] = -rtb_TSamp_jb;
      Rot_error[2] = -b_norm;
      Rot_error[5] = rtb_TSamp_jb;
      Rot_error[8] = 0.0;
      q_0[0] = rtb_TSamp;
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_jb = axis[rtemp];
        BLACK_Estimated_Covar_tmp = (rtemp + 1) << 2;
        q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
        q_0[rtemp + 1] = rtb_TSamp_jb;
        q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 * rtemp])
          * rtb_TSamp + Rot_error[3 * rtemp];
        i = 3 * rtemp + 1;
        q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
        i = 3 * rtemp + 2;
        q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
      }

      rtb_TSamp = x_k[1];
      rtb_TSamp_e = x_k[0];
      rtb_TSamp_jb = x_k[2];
      b_norm = x_k[3];
      for (rtemp = 0; rtemp < 4; rtemp++) {
        MPC_DW.Delay1_DSTATE_dn[rtemp] = ((q_0[rtemp + 4] * rtb_TSamp +
          q_0[rtemp] * rtb_TSamp_e) + q_0[rtemp + 8] * rtb_TSamp_jb) + q_0[rtemp
          + 12] * b_norm;
      }

      for (i = 0; i < 9; i++) {
        MPC_DW.Delay1_DSTATE_dn[i + 4] = x_k[i + 4] + delta_x[i + 3];
      }

      MPC_DW.QMEKFt = MPC_toc(&savedTime);
      for (i = 0; i < 6; i++) {
        rtb_y_pc[i] = MPC_DW.QMEKFerror[i];
        for (rtemp = 0; rtemp < 12; rtemp++) {
          rtb_TSamp = 0.0;
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
               BLACK_Estimated_Covar_tmp++) {
            rtb_TSamp += H[6 * BLACK_Estimated_Covar_tmp + i] * MPC_DW.QMEKFP[12
              * rtemp + BLACK_Estimated_Covar_tmp];
          }

          H_0[i + 6 * rtemp] = rtb_TSamp;
        }

        for (rtemp = 0; rtemp < 6; rtemp++) {
          rtb_TSamp_e = 0.0;
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
               BLACK_Estimated_Covar_tmp++) {
            rtb_TSamp_e += H_0[6 * BLACK_Estimated_Covar_tmp + i] * K_tmp[12 *
              rtemp + BLACK_Estimated_Covar_tmp];
          }

          r2 = 6 * rtemp + i;
          BLACK_Estimated_Covar_0[r2] = b_R[r2] + rtb_TSamp_e;
        }
      }

      MPC_xgetrf(BLACK_Estimated_Covar_0, ipiv, &rtemp);
      for (i = 0; i < 6; i++) {
        r3 = 6 * i;
        for (r2 = 0; r2 < i; r2++) {
          rtb_TSamp_e = BLACK_Estimated_Covar_0[r2 + r3];
          if (rtb_TSamp_e != 0.0) {
            rtb_y_pc[i] -= rtb_TSamp_e * rtb_y_pc[r2];
          }
        }

        rtb_y_pc[i] *= 1.0 / BLACK_Estimated_Covar_0[i + r3];
      }

      for (i = 5; i >= 0; i--) {
        r3 = 6 * i - 1;
        for (rtemp = i + 2; rtemp < 7; rtemp++) {
          rtb_TSamp_e = BLACK_Estimated_Covar_0[rtemp + r3];
          if (rtb_TSamp_e != 0.0) {
            rtb_y_pc[i] -= rtb_y_pc[rtemp - 1] * rtb_TSamp_e;
          }
        }
      }

      for (BLACK_Estimated_Covar_tmp = 4; BLACK_Estimated_Covar_tmp >= 0;
           BLACK_Estimated_Covar_tmp--) {
        r2 = ipiv[BLACK_Estimated_Covar_tmp];
        if (BLACK_Estimated_Covar_tmp + 1 != r2) {
          rtb_TSamp = rtb_y_pc[BLACK_Estimated_Covar_tmp];
          rtb_y_pc[BLACK_Estimated_Covar_tmp] = rtb_y_pc[r2 - 1];
          rtb_y_pc[r2 - 1] = rtb_TSamp;
        }
      }

      MPC_DW.QMEKFNIS = 0.0;
      for (rtemp = 0; rtemp < 6; rtemp++) {
        MPC_DW.QMEKFNIS += rtb_y_pc[rtemp] * MPC_DW.QMEKFerror[rtemp];
      }

      // MATLAB Function: '<S97>/MATLAB Function'
      MPC_MATLABFunction_a(MPC_DW.Delay1_DSTATE_dn, rtb_out);

      // DataStoreWrite: '<S97>/Data Store Write17'
      memcpy(&MPC_DW.QMEKFx[0], &rtb_out[0], 13U * sizeof(real_T));

      // MATLAB Function: '<S98>/MATLAB Function1' incorporates:
      //   DataStoreRead: '<S98>/Data Store Read15'
      //   DataStoreRead: '<S98>/Data Store Read2'
      //   DataStoreRead: '<S98>/Data Store Read4'
      //   DataStoreWrite: '<S98>/Data Store Write18'
      //   Delay: '<S98>/Delay'
      //   Delay: '<S98>/Delay1'
      //   Delay: '<S98>/Delay2'
      //   MATLAB Function: '<S102>/MATLAB Function1'

      rtb_y_pc[0] = Red_x[0];
      rtb_y_pc[1] = Red_x[1];
      rtb_y_pc[2] = rtb_MatrixConcatenate[0];
      rtb_y_pc[3] = rtb_MatrixConcatenate[1];
      rtb_y_pc[4] = rtb_MatrixConcatenate[2];
      rtb_y_pc[5] = rtb_MatrixConcatenate[3];
      for (i = 0; i < 6; i++) {
        Chaser[i] = rtb_y_pc[i];
      }

      MPC_tic_e(&savedTime_f);
      Rot_error[0] = 0.0 * dt;
      b_norm = -MPC_DW.Delay1_DSTATE_ml[8] * dt;
      Rot_error[3] = b_norm;
      rtb_y_gs = MPC_DW.Delay1_DSTATE_ml[7] * dt;
      Rot_error[6] = rtb_y_gs;
      e_in_tmp = MPC_DW.Delay1_DSTATE_ml[8] * dt;
      Rot_error[1] = e_in_tmp;
      Rot_error[4] = 0.0 * dt;
      e_in_0 = -MPC_DW.Delay1_DSTATE_ml[6] * dt;
      Rot_error[7] = e_in_0;
      rtb_y_eu = -MPC_DW.Delay1_DSTATE_ml[7] * dt;
      Rot_error[2] = rtb_y_eu;
      H_tmp_0 = MPC_DW.Delay1_DSTATE_ml[6] * dt;
      Rot_error[5] = H_tmp_0;
      Rot_error[8] = 0.0 * dt;
      MPC_expm_o(Rot_error, R_chaser);
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_lb = MPC_DW.Delay2_DSTATE_j2[3 * rtemp + 1];
        rtb_TSamp = MPC_DW.Delay2_DSTATE_j2[3 * rtemp];
        rtb_TSamp_e = MPC_DW.Delay2_DSTATE_j2[3 * rtemp + 2];
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          Rot_pred[BLACK_Estimated_Covar_tmp + 3 * rtemp] =
            (R_chaser[BLACK_Estimated_Covar_tmp + 3] * rtb_TSamp_lb + rtb_TSamp *
             R_chaser[BLACK_Estimated_Covar_tmp]) +
            R_chaser[BLACK_Estimated_Covar_tmp + 6] * rtb_TSamp_e;
        }
      }

      memcpy(&m[0], &MPC_DW.Delay1_DSTATE_ml[0], 9U * sizeof(real_T));
      m[0] = dt * MPC_DW.Delay1_DSTATE_ml[3] + MPC_DW.Delay1_DSTATE_ml[0];
      m[1] = dt * MPC_DW.Delay1_DSTATE_ml[4] + MPC_DW.Delay1_DSTATE_ml[1];
      m[2] = dt * MPC_DW.Delay1_DSTATE_ml[5] + MPC_DW.Delay1_DSTATE_ml[2];
      for (rtemp = 0; rtemp < 36; rtemp++) {
        F_tmp_2[rtemp] = b_2[rtemp];
      }

      rtb_TSamp_lb = 0.0 * dt + 1.0;
      L[0] = rtb_TSamp_lb;
      L[1] = e_in_tmp;
      L[2] = rtb_y_eu;
      L[12] = b_norm;
      L[13] = rtb_TSamp_lb;
      L[14] = H_tmp_0;
      L[24] = rtb_y_gs;
      L[25] = e_in_0;
      L[26] = rtb_TSamp_lb;
      for (rtemp = 0; rtemp < 6; rtemp++) {
        i = (rtemp + 3) * 12;
        L[i] = 0.0;
        L[i + 1] = 0.0;
        L[i + 2] = 0.0;
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp = F_tmp_0[3 * rtemp];
        i = (rtemp + 9) * 12;
        L[i] = rtb_TSamp;
        L[12 * rtemp + 3] = 0.0;
        BLACK_Estimated_Covar_tmp = (rtemp + 3) * 12;
        L[BLACK_Estimated_Covar_tmp + 3] = F_tmp[3 * rtemp];
        r3 = (rtemp + 6) * 12;
        L[r3 + 3] = rtb_TSamp;
        L[i + 3] = 0.0;
        r2 = 3 * rtemp + 1;
        rtb_TSamp = F_tmp_0[r2];
        L[i + 1] = rtb_TSamp;
        L[12 * rtemp + 4] = 0.0;
        L[BLACK_Estimated_Covar_tmp + 4] = F_tmp[r2];
        L[r3 + 4] = rtb_TSamp;
        L[i + 4] = 0.0;
        r2 = 3 * rtemp + 2;
        rtb_TSamp = F_tmp_0[r2];
        L[i + 2] = rtb_TSamp;
        L[12 * rtemp + 5] = 0.0;
        L[BLACK_Estimated_Covar_tmp + 5] = F_tmp[r2];
        L[r3 + 5] = rtb_TSamp;
        L[i + 5] = 0.0;
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        L[12 * rtemp + 6] = F_tmp_2[3 * rtemp];
        L[12 * rtemp + 9] = F_tmp_1[3 * rtemp];
        i = 3 * rtemp + 1;
        L[12 * rtemp + 7] = F_tmp_2[i];
        L[12 * rtemp + 10] = F_tmp_1[i];
        i = 3 * rtemp + 2;
        L[12 * rtemp + 8] = F_tmp_2[i];
        L[12 * rtemp + 11] = F_tmp_1[i];
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += L[12 * i + rtemp] * MPC_DW.Delay_DSTATE_p[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          L_0[rtemp + 12 * BLACK_Estimated_Covar_tmp] = rtb_TSamp;
        }

        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_e += L_0[12 * i + rtemp] * L[12 * i +
              BLACK_Estimated_Covar_tmp];
          }

          i = 12 * BLACK_Estimated_Covar_tmp + rtemp;
          P_k[i] = b_Q_0[i] + rtb_TSamp_e;
        }
      }

      b[0] = Chaser[3];
      b[1] = Chaser[4];
      b[2] = Chaser[5];
      rtb_TSamp_e = Chaser[2] * Chaser[2] - ((Chaser[3] * Chaser[3] + Chaser[4] *
        Chaser[4]) + Chaser[5] * Chaser[5]);
      rtb_TSamp = 2.0 * Chaser[2];
      d_a[0] = rtb_TSamp * 0.0;
      d_a[1] = rtb_TSamp * -Chaser[5];
      d_a[2] = rtb_TSamp * Chaser[4];
      d_a_0[0] = rtb_TSamp * Chaser[5];
      d_a_0[1] = rtb_TSamp * 0.0;
      d_a_0[2] = rtb_TSamp * -Chaser[3];
      d_a_1[0] = rtb_TSamp * -Chaser[4];
      d_a_1[1] = rtb_TSamp * Chaser[3];
      d_a_1[2] = rtb_TSamp * 0.0;
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp = static_cast<real_T>(F_tmp[3 * rtemp]) * rtb_TSamp_e + 2.0 *
          b[0] * b[rtemp];
        R_chaser_tmp[3 * rtemp] = rtb_TSamp;
        BLACK_Estimated_Covar_tmp = 3 * rtemp + 1;
        rtb_TSamp_jb = 2.0 * b[1] * b[rtemp] + static_cast<real_T>
          (F_tmp[BLACK_Estimated_Covar_tmp]) * rtb_TSamp_e;
        R_chaser_tmp[BLACK_Estimated_Covar_tmp] = rtb_TSamp_jb;
        i = 3 * rtemp + 2;
        b_norm = 2.0 * b[2] * b[rtemp] + static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp_e;
        R_chaser_tmp[i] = b_norm;
        R_chaser[3 * rtemp] = rtb_TSamp + d_a[rtemp];
        R_chaser[BLACK_Estimated_Covar_tmp] = rtb_TSamp_jb + d_a_0[rtemp];
        R_chaser[i] = b_norm + d_a_1[rtemp];
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        H[6 * rtemp] = H_tmp[3 * rtemp];
        H[6 * rtemp + 1] = H_tmp[3 * rtemp + 1];
        H[6 * rtemp + 2] = H_tmp[3 * rtemp + 2];
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        H[6 * rtemp + 3] = 0.0;
        r2 = (rtemp + 3) * 6;
        H[r2 + 3] = R_chaser[3 * rtemp];
        H[6 * rtemp + 4] = 0.0;
        H[r2 + 4] = R_chaser[3 * rtemp + 1];
        H[6 * rtemp + 5] = 0.0;
        H[r2 + 5] = R_chaser[3 * rtemp + 2];
      }

      for (rtemp = 0; rtemp < 6; rtemp++) {
        r2 = (rtemp + 6) * 6;
        H[r2 + 3] = 0.0;
        H[r2 + 4] = 0.0;
        H[r2 + 5] = 0.0;
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp = R_chaser[rtemp + 3];
        rtb_TSamp_e = R_chaser[rtemp];
        rtb_TSamp_jb = R_chaser[rtemp + 6];
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          R_chaser_0[rtemp + 3 * BLACK_Estimated_Covar_tmp] =
            (Rot_pred[BLACK_Estimated_Covar_tmp + 3] * rtb_TSamp + rtb_TSamp_e *
             Rot_pred[BLACK_Estimated_Covar_tmp]) +
            Rot_pred[BLACK_Estimated_Covar_tmp + 6] * rtb_TSamp_jb;
        }

        rtb_TSamp = R_chaser_0[rtemp + 3];
        rtb_TSamp_e = R_chaser_0[rtemp];
        rtb_TSamp_jb = R_chaser_0[rtemp + 6];
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          Rot_error[rtemp + 3 * BLACK_Estimated_Covar_tmp] =
            (MPC_DW.Vis_R[BLACK_Estimated_Covar_tmp + 3] * rtb_TSamp +
             rtb_TSamp_e * MPC_DW.Vis_R[BLACK_Estimated_Covar_tmp]) +
            MPC_DW.Vis_R[BLACK_Estimated_Covar_tmp + 6] * rtb_TSamp_jb;
        }
      }

      rtb_y_eu = (((Rot_error[0] + Rot_error[4]) + Rot_error[8]) - 1.0) / 2.0;
      if (!(rtb_y_eu <= 1.0)) {
        rtb_y_eu = 1.0;
      }

      if (!(rtb_y_eu >= -1.0)) {
        rtb_y_eu = -1.0;
      }

      rtb_TSamp_e = acos(rtb_y_eu);
      if (fabs(rtb_TSamp_e) < 1.0E-8) {
        axis[0] = 0.0;
        axis[1] = 0.0;
        axis[2] = 0.0;
      } else {
        rtb_TSamp = 2.0 * sin(rtb_TSamp_e) * rtb_TSamp_e;
        rtb_TSamp_e = sin(Rot_error[5]);
        rtb_TSamp_jb = cos(Rot_error[5]);
        b_norm = sin(Rot_error[7]);
        rtb_y_eu = cos(Rot_error[7]);
        e_in[0] = (rtb_TSamp_e * 0.0 + rtb_TSamp_jb) - (b_norm * 0.0 + rtb_y_eu);
        e_in[1] = (rtb_TSamp_jb * 0.0 - rtb_TSamp_e) - (rtb_y_eu * 0.0 - b_norm);
        b_norm = sin(Rot_error[6]);
        rtb_y_eu = cos(Rot_error[6]);
        rtb_y_gs = sin(Rot_error[2]);
        e_in_tmp = cos(Rot_error[2]);
        b_y_tmp[0] = (b_norm * 0.0 + rtb_y_eu) - (rtb_y_gs * 0.0 + e_in_tmp);
        b_y_tmp[1] = (rtb_y_eu * 0.0 - b_norm) - (e_in_tmp * 0.0 - rtb_y_gs);
        rtb_y_gs = sin(Rot_error[1]);
        e_in_tmp = cos(Rot_error[1]);
        e_in_0 = sin(Rot_error[3]);
        H_tmp_0 = cos(Rot_error[3]);
        c_y_tmp[0] = (rtb_y_gs * 0.0 + e_in_tmp) - (e_in_0 * 0.0 + H_tmp_0);
        c_y_tmp[1] = (e_in_tmp * 0.0 - rtb_y_gs) - (H_tmp_0 * 0.0 - e_in_0);
        rtb_TSamp_e = (rtb_TSamp_jb * 0.0 + rtb_TSamp_e) * e_in[0] +
          (-rtb_TSamp_e * 0.0 + rtb_TSamp_jb) * e_in[1];
        b_norm = (rtb_y_eu * 0.0 + b_norm) * b_y_tmp[0] + (-b_norm * 0.0 +
          rtb_y_eu) * b_y_tmp[1];
        rtb_y_gs = (e_in_tmp * 0.0 + rtb_y_gs) * c_y_tmp[0] + (-rtb_y_gs * 0.0 +
          e_in_tmp) * c_y_tmp[1];
        if (rtIsNaN(rtb_TSamp_e)) {
          rtb_TSamp_e = (rtNaN);
        } else if (rtb_TSamp_e < 0.0) {
          rtb_TSamp_e = -1.0;
        } else {
          rtb_TSamp_e = (rtb_TSamp_e > 0.0);
        }

        axis[0] = -MPC_norm_ai(e_in) * rtb_TSamp_e * rtb_TSamp;
        if (rtIsNaN(b_norm)) {
          rtb_TSamp_e = (rtNaN);
        } else if (b_norm < 0.0) {
          rtb_TSamp_e = -1.0;
        } else {
          rtb_TSamp_e = (b_norm > 0.0);
        }

        axis[1] = -MPC_norm_ai(b_y_tmp) * rtb_TSamp_e * rtb_TSamp;
        if (rtIsNaN(rtb_y_gs)) {
          rtb_TSamp_e = (rtNaN);
        } else if (rtb_y_gs < 0.0) {
          rtb_TSamp_e = -1.0;
        } else {
          rtb_TSamp_e = (rtb_y_gs > 0.0);
        }

        axis[2] = -MPC_norm_ai(c_y_tmp) * rtb_TSamp_e * rtb_TSamp;
      }

      rtb_TSamp_e = m[0] - Chaser[0];
      rtb_TSamp_jb = m[1] - Chaser[1];
      b_norm = m[2];
      for (rtemp = 0; rtemp < 3; rtemp++) {
        MPC_DW.RMEKFerror[rtemp] = axis[rtemp];
        MPC_DW.RMEKFerror[rtemp + 3] = MPC_DW.Vis_x[rtemp] - ((R_chaser[rtemp +
          3] * rtb_TSamp_jb + R_chaser[rtemp] * rtb_TSamp_e) + R_chaser[rtemp +
          6] * b_norm);
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += H[(6 * i + rtemp) + 3] * P_k[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          BLACK_Estimated_Covar_0[rtemp + 3 * BLACK_Estimated_Covar_tmp] =
            rtb_TSamp;
        }

        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += H[(6 * i + BLACK_Estimated_Covar_tmp) + 3] *
              BLACK_Estimated_Covar_0[3 * i + rtemp];
          }

          Rot_error[rtemp + 3 * BLACK_Estimated_Covar_tmp] = rtb_TSamp;
        }
      }

      rtb_TSamp_e = 0.0;
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_e += ((Rot_error[3 * rtemp + 1] * MPC_DW.RMEKFerror[4] +
                         Rot_error[3 * rtemp] * MPC_DW.RMEKFerror[3]) +
                        Rot_error[3 * rtemp + 2] * MPC_DW.RMEKFerror[5]) *
          MPC_DW.RMEKFerror[rtemp + 3];
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += H[6 * i + rtemp] * P_k[12 * BLACK_Estimated_Covar_tmp +
              i];
          }

          BLACK_Estimated_Covar_0[rtemp + 3 * BLACK_Estimated_Covar_tmp] =
            rtb_TSamp;
        }

        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += BLACK_Estimated_Covar_0[3 * i + rtemp] * H[6 * i +
              BLACK_Estimated_Covar_tmp];
          }

          Rot_error[rtemp + 3 * BLACK_Estimated_Covar_tmp] = rtb_TSamp;
        }
      }

      rtb_TSamp_jb = 0.0;
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_jb += ((Rot_error[3 * rtemp + 1] * MPC_DW.RMEKFerror[1] +
                          Rot_error[3 * rtemp] * MPC_DW.RMEKFerror[0]) +
                         Rot_error[3 * rtemp + 2] * MPC_DW.RMEKFerror[2]) *
          MPC_DW.RMEKFerror[rtemp];
      }

      if (!(sqrt(rtb_TSamp_jb) < 1604.6000000000001)) {
        MPC_DW.RMEKFerror[0] = 0.0;
        MPC_DW.RMEKFerror[1] = 0.0;
        MPC_DW.RMEKFerror[2] = 0.0;
        for (rtemp = 0; rtemp < 12; rtemp++) {
          H[6 * rtemp] = 0.0;
          H[6 * rtemp + 1] = 0.0;
          H[6 * rtemp + 2] = 0.0;
        }
      }

      if (!(sqrt(rtb_TSamp_e) < 5586.5999999999995)) {
        MPC_DW.RMEKFerror[3] = 0.0;
        MPC_DW.RMEKFerror[4] = 0.0;
        MPC_DW.RMEKFerror[5] = 0.0;
        for (rtemp = 0; rtemp < 12; rtemp++) {
          H[6 * rtemp + 3] = 0.0;
          H[6 * rtemp + 4] = 0.0;
          H[6 * rtemp + 5] = 0.0;
        }
      }

      for (rtemp = 0; rtemp < 6; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          K_tmp[BLACK_Estimated_Covar_tmp + 12 * rtemp] = H[6 *
            BLACK_Estimated_Covar_tmp + rtemp];
        }
      }

      for (rtemp = 0; rtemp < 6; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_e = 0.0;
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_e += P_k[12 * i + BLACK_Estimated_Covar_tmp] * K_tmp[12 *
              rtemp + i];
            rtb_TSamp += H[6 * i + rtemp] * P_k[12 * BLACK_Estimated_Covar_tmp +
              i];
          }

          K_0[BLACK_Estimated_Covar_tmp + 12 * rtemp] = rtb_TSamp_e;
          H_0[rtemp + 6 * BLACK_Estimated_Covar_tmp] = rtb_TSamp;
        }

        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_e += H_0[6 * i + rtemp] * K_tmp[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          r2 = 6 * BLACK_Estimated_Covar_tmp + rtemp;
          BLACK_Estimated_Covar_0[r2] = b_R_0[r2] + rtb_TSamp_e;
        }
      }

      MPC_xgetrf(BLACK_Estimated_Covar_0, ipiv, &rtemp);
      for (i = 0; i < 6; i++) {
        jBcol = 12 * i;
        r3 = 6 * i;
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < i;
             BLACK_Estimated_Covar_tmp++) {
          kBcol = 12 * BLACK_Estimated_Covar_tmp;
          rtb_TSamp_e = BLACK_Estimated_Covar_0[BLACK_Estimated_Covar_tmp + r3];
          if (rtb_TSamp_e != 0.0) {
            for (r2 = 0; r2 < 12; r2++) {
              rtemp = r2 + jBcol;
              K_0[rtemp] -= K_0[r2 + kBcol] * rtb_TSamp_e;
            }
          }
        }

        rtb_TSamp = 1.0 / BLACK_Estimated_Covar_0[i + r3];
        for (r2 = 0; r2 < 12; r2++) {
          rtemp = r2 + jBcol;
          K_0[rtemp] *= rtb_TSamp;
        }
      }

      for (i = 5; i >= 0; i--) {
        jBcol = 12 * i;
        r3 = 6 * i - 1;
        for (r2 = i + 2; r2 < 7; r2++) {
          kBcol = (r2 - 1) * 12;
          rtb_TSamp_e = BLACK_Estimated_Covar_0[r2 + r3];
          if (rtb_TSamp_e != 0.0) {
            for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
                 BLACK_Estimated_Covar_tmp++) {
              rtemp = BLACK_Estimated_Covar_tmp + jBcol;
              K_0[rtemp] -= K_0[BLACK_Estimated_Covar_tmp + kBcol] * rtb_TSamp_e;
            }
          }
        }
      }

      for (BLACK_Estimated_Covar_tmp = 4; BLACK_Estimated_Covar_tmp >= 0;
           BLACK_Estimated_Covar_tmp--) {
        r2 = ipiv[BLACK_Estimated_Covar_tmp];
        if (BLACK_Estimated_Covar_tmp + 1 != r2) {
          for (i = 0; i < 12; i++) {
            r3 = 12 * BLACK_Estimated_Covar_tmp + i;
            rtb_TSamp = K_0[r3];
            rtemp = (r2 - 1) * 12 + i;
            K_0[r3] = K_0[rtemp];
            K_0[rtemp] = rtb_TSamp;
          }
        }
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp += K_0[12 * i + BLACK_Estimated_Covar_tmp] * H[6 * rtemp +
              i];
          }

          L[BLACK_Estimated_Covar_tmp + 12 * rtemp] = rtb_TSamp;
        }
      }

      for (rtemp = 0; rtemp < 144; rtemp++) {
        L_0[rtemp] = static_cast<real_T>(QMEKFP_tmp_2[rtemp]) - L[rtemp];
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += L_0[12 * i + rtemp] * P_k[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          r2 = 12 * BLACK_Estimated_Covar_tmp + rtemp;
          QMEKFP_tmp_0[r2] = rtb_TSamp;
          i = 12 * rtemp + BLACK_Estimated_Covar_tmp;
          QMEKFP_tmp_1[i] = static_cast<real_T>(QMEKFP_tmp[i]) - L[r2];
        }

        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp_e += K_0[12 * i + rtemp] * b_R_0[6 *
              BLACK_Estimated_Covar_tmp + i];
          }

          H_0[rtemp + 12 * BLACK_Estimated_Covar_tmp] = rtb_TSamp_e;
        }
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += QMEKFP_tmp_0[12 * i + rtemp] * QMEKFP_tmp_1[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          r2 = 12 * BLACK_Estimated_Covar_tmp + rtemp;
          L_0[r2] = rtb_TSamp;
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp_e += H_0[12 * i + rtemp] * K_0[12 * i +
              BLACK_Estimated_Covar_tmp];
          }

          L[r2] = rtb_TSamp_e;
        }
      }

      for (rtemp = 0; rtemp < 144; rtemp++) {
        MPC_DW.RMEKFP[rtemp] = L_0[rtemp] + L[rtemp];
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        rtb_TSamp = 0.0;
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp += K_0[12 * BLACK_Estimated_Covar_tmp + rtemp] *
            MPC_DW.RMEKFerror[BLACK_Estimated_Covar_tmp];
        }

        delta_x[rtemp] = rtb_TSamp;
      }

      rtb_TSamp = 3.3121686421112381E-170;
      rtb_TSamp_e = fabs(delta_x[0]);
      if (rtb_TSamp_e > 3.3121686421112381E-170) {
        b_norm = 1.0;
        rtb_TSamp = rtb_TSamp_e;
      } else {
        rtb_TSamp_jb = rtb_TSamp_e / 3.3121686421112381E-170;
        b_norm = rtb_TSamp_jb * rtb_TSamp_jb;
      }

      rtb_TSamp_e = fabs(delta_x[1]);
      if (rtb_TSamp_e > rtb_TSamp) {
        rtb_TSamp_jb = rtb_TSamp / rtb_TSamp_e;
        b_norm = b_norm * rtb_TSamp_jb * rtb_TSamp_jb + 1.0;
        rtb_TSamp = rtb_TSamp_e;
      } else {
        rtb_TSamp_jb = rtb_TSamp_e / rtb_TSamp;
        b_norm += rtb_TSamp_jb * rtb_TSamp_jb;
      }

      rtb_TSamp_e = fabs(delta_x[2]);
      if (rtb_TSamp_e > rtb_TSamp) {
        rtb_TSamp_jb = rtb_TSamp / rtb_TSamp_e;
        b_norm = b_norm * rtb_TSamp_jb * rtb_TSamp_jb + 1.0;
        rtb_TSamp = rtb_TSamp_e;
      } else {
        rtb_TSamp_jb = rtb_TSamp_e / rtb_TSamp;
        b_norm += rtb_TSamp_jb * rtb_TSamp_jb;
      }

      b_norm = rtb_TSamp * sqrt(b_norm);
      if (b_norm > 1.0E-8) {
        axis[0] = delta_x[0] / b_norm;
        axis[1] = delta_x[1] / b_norm;
        axis[2] = delta_x[2] / b_norm;
      } else {
        axis[0] = 0.0;
        axis[1] = 0.0;
        axis[2] = 0.0;
      }

      rtb_TSamp = sin(b_norm);
      rtb_TSamp_e = cos(b_norm);
      R_chaser[0] = 0.0;
      R_chaser[3] = -axis[2];
      R_chaser[6] = axis[1];
      R_chaser[1] = axis[2];
      R_chaser[4] = 0.0;
      R_chaser[7] = -axis[0];
      R_chaser[2] = -axis[1];
      R_chaser[5] = axis[0];
      R_chaser[8] = 0.0;
      memset(&Rot_error[0], 0, 9U * sizeof(real_T));
      for (i = 0; i < 3; i++) {
        Rot_error[i + 3 * i] = 1.0;
        for (rtemp = 0; rtemp < 3; rtemp++) {
          R_chaser_0[i + 3 * rtemp] = (R_chaser[3 * rtemp + 1] * R_chaser[i + 3]
            + R_chaser[3 * rtemp] * R_chaser[i]) + R_chaser[3 * rtemp + 2] *
            R_chaser[i + 6];
        }
      }

      R_chaser[0] = rtb_TSamp * 0.0 + Rot_error[0];
      R_chaser[1] = rtb_TSamp * axis[2] + Rot_error[1];
      R_chaser[2] = rtb_TSamp * -axis[1] + Rot_error[2];
      R_chaser[3] = rtb_TSamp * -axis[2] + Rot_error[3];
      R_chaser[4] = rtb_TSamp * 0.0 + Rot_error[4];
      R_chaser[5] = rtb_TSamp * axis[0] + Rot_error[5];
      R_chaser[6] = rtb_TSamp * axis[1] + Rot_error[6];
      R_chaser[7] = rtb_TSamp * -axis[0] + Rot_error[7];
      R_chaser[8] = rtb_TSamp * 0.0 + Rot_error[8];
      for (rtemp = 0; rtemp < 9; rtemp++) {
        Rot_error[rtemp] = (1.0 - rtb_TSamp_e) * R_chaser_0[rtemp] +
          R_chaser[rtemp];
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp = Rot_pred[3 * rtemp + 1];
        rtb_TSamp_e = Rot_pred[3 * rtemp];
        rtb_TSamp_jb = Rot_pred[3 * rtemp + 2];
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          MPC_DW.RMEKFR[BLACK_Estimated_Covar_tmp + 3 * rtemp] =
            (Rot_error[BLACK_Estimated_Covar_tmp + 3] * rtb_TSamp + rtb_TSamp_e *
             Rot_error[BLACK_Estimated_Covar_tmp]) +
            Rot_error[BLACK_Estimated_Covar_tmp + 6] * rtb_TSamp_jb;
        }
      }

      for (rtemp = 0; rtemp < 9; rtemp++) {
        m[rtemp] += delta_x[rtemp + 3];
      }

      MPC_DW.RMEKFt = MPC_toc_f(&savedTime_f);
      for (i = 0; i < 6; i++) {
        Chaser[i] = MPC_DW.RMEKFerror[i];
        for (rtemp = 0; rtemp < 12; rtemp++) {
          rtb_TSamp = 0.0;
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
               BLACK_Estimated_Covar_tmp++) {
            rtb_TSamp += H[6 * BLACK_Estimated_Covar_tmp + i] * MPC_DW.RMEKFP[12
              * rtemp + BLACK_Estimated_Covar_tmp];
          }

          H_0[i + 6 * rtemp] = rtb_TSamp;
        }

        for (rtemp = 0; rtemp < 6; rtemp++) {
          rtb_TSamp_e = 0.0;
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
               BLACK_Estimated_Covar_tmp++) {
            rtb_TSamp_e += H_0[6 * BLACK_Estimated_Covar_tmp + i] * K_tmp[12 *
              rtemp + BLACK_Estimated_Covar_tmp];
          }

          r2 = 6 * rtemp + i;
          BLACK_Estimated_Covar_0[r2] = b_R_0[r2] + rtb_TSamp_e;
        }
      }

      MPC_xgetrf(BLACK_Estimated_Covar_0, ipiv, &rtemp);
      for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
           BLACK_Estimated_Covar_tmp++) {
        i = 6 * BLACK_Estimated_Covar_tmp;
        for (rtemp = 0; rtemp < BLACK_Estimated_Covar_tmp; rtemp++) {
          rtb_TSamp_e = BLACK_Estimated_Covar_0[rtemp + i];
          if (rtb_TSamp_e != 0.0) {
            Chaser[BLACK_Estimated_Covar_tmp] -= rtb_TSamp_e * Chaser[rtemp];
          }
        }

        Chaser[BLACK_Estimated_Covar_tmp] *= 1.0 /
          BLACK_Estimated_Covar_0[BLACK_Estimated_Covar_tmp + i];
      }

      for (BLACK_Estimated_Covar_tmp = 5; BLACK_Estimated_Covar_tmp >= 0;
           BLACK_Estimated_Covar_tmp--) {
        i = 6 * BLACK_Estimated_Covar_tmp - 1;
        for (r2 = BLACK_Estimated_Covar_tmp + 2; r2 < 7; r2++) {
          rtb_TSamp_e = BLACK_Estimated_Covar_0[r2 + i];
          if (rtb_TSamp_e != 0.0) {
            Chaser[BLACK_Estimated_Covar_tmp] -= Chaser[r2 - 1] * rtb_TSamp_e;
          }
        }
      }

      for (rtemp = 4; rtemp >= 0; rtemp--) {
        r2 = ipiv[rtemp];
        if (rtemp + 1 != r2) {
          rtb_TSamp = Chaser[rtemp];
          Chaser[rtemp] = Chaser[r2 - 1];
          Chaser[r2 - 1] = rtb_TSamp;
        }
      }

      MPC_DW.RMEKFNIS = 0.0;
      for (rtemp = 0; rtemp < 6; rtemp++) {
        MPC_DW.RMEKFNIS += Chaser[rtemp] * MPC_DW.RMEKFerror[rtemp];
      }

      // MATLAB Function: '<S98>/MATLAB Function11'
      MPC_MATLABFunction11_l(MPC_DW.RMEKFR, &rtb_y_p[0]);

      // MATLAB Function: '<S98>/MATLAB Function'
      MPC_MATLABFunction_gs(m, &rtb_y_p[0], rtb_out);

      // DataStoreWrite: '<S98>/Data Store Write17'
      memcpy(&MPC_DW.RMEKFx[0], &rtb_out[0], 13U * sizeof(real_T));

      // MATLAB Function: '<S101>/MATLAB Function1' incorporates:
      //   DataStoreRead: '<S101>/Data Store Read2'
      //   DataStoreRead: '<S101>/Data Store Read3'
      //   DataStoreRead: '<S101>/Data Store Read4'
      //   DataStoreWrite: '<S101>/Data Store Write18'
      //   Delay: '<S101>/Delay'
      //   Delay: '<S101>/Delay1'
      //   Delay: '<S101>/Delay2'

      rtb_TmpSignalConversionAtSFun_o[0] = MPC_DW.Vis_q[0];
      rtb_TmpSignalConversionAtSFun_o[1] = MPC_DW.Vis_q[1];
      rtb_TmpSignalConversionAtSFun_o[2] = MPC_DW.Vis_q[2];
      rtb_TmpSignalConversionAtSFun_o[3] = MPC_DW.Vis_q[3];
      rtb_TmpSignalConversionAtSFun_o[4] = MPC_DW.Vis_x[0];
      rtb_TmpSignalConversionAtSFun_o[5] = MPC_DW.Vis_x[1];
      rtb_TmpSignalConversionAtSFun_o[6] = MPC_DW.Vis_x[2];
      rtb_TmpSignalConversionAtSFun_a[0] = rtb_MatrixConcatenate[0];
      rtb_TmpSignalConversionAtSFun_a[1] = rtb_MatrixConcatenate[1];
      rtb_TmpSignalConversionAtSFun_a[2] = rtb_MatrixConcatenate[2];
      rtb_TmpSignalConversionAtSFun_a[3] = rtb_MatrixConcatenate[3];
      rtb_TmpSignalConversionAtSFun_a[4] = Red_x[0];
      rtb_TmpSignalConversionAtSFun_a[5] = Red_x[1];
      rtb_TmpSignalConversionAtSFun_a[6] = Red_x[2];
      MPC_tic_k(&savedTime_a);
      rtb_TSamp_jb = MPC_norm(&MPC_DW.Delay1_DSTATE_gw[4]);
      if (rtb_TSamp_jb > 1.0E-10) {
        rtb_TSamp_e = rtb_TSamp_jb * dt / 2.0;
        rtb_TSamp = sin(rtb_TSamp_e);
        q[0] = cos(rtb_TSamp_e);
        q[1] = MPC_DW.Delay1_DSTATE_gw[4] / rtb_TSamp_jb * rtb_TSamp;
        q[2] = MPC_DW.Delay1_DSTATE_gw[5] / rtb_TSamp_jb * rtb_TSamp;
        q[3] = MPC_DW.Delay1_DSTATE_gw[6] / rtb_TSamp_jb * rtb_TSamp;
      } else {
        q[0] = 1.0;
        q[1] = 0.0;
        q[2] = 0.0;
        q[3] = 0.0;
      }

      axis[0] = q[1];
      axis[1] = q[2];
      axis[2] = q[3];
      rtb_TSamp = q[0];
      Rot_error[0] = 0.0;
      Rot_error[3] = -q[3];
      Rot_error[6] = q[2];
      Rot_error[1] = q[3];
      Rot_error[4] = 0.0;
      Rot_error[7] = -q[1];
      Rot_error[2] = -q[2];
      Rot_error[5] = q[1];
      Rot_error[8] = 0.0;
      q_0[0] = q[0];
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_jb = axis[rtemp];
        BLACK_Estimated_Covar_tmp = (rtemp + 1) << 2;
        q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
        q_0[rtemp + 1] = rtb_TSamp_jb;
        q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 * rtemp])
          * rtb_TSamp + Rot_error[3 * rtemp];
        i = 3 * rtemp + 1;
        q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
        i = 3 * rtemp + 2;
        q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
      }

      rtb_TSamp = MPC_DW.Delay1_DSTATE_gw[1];
      rtb_TSamp_e = MPC_DW.Delay1_DSTATE_gw[0];
      rtb_TSamp_jb = MPC_DW.Delay1_DSTATE_gw[2];
      b_norm = MPC_DW.Delay1_DSTATE_gw[3];
      for (rtemp = 0; rtemp < 4; rtemp++) {
        x_k[rtemp] = ((q_0[rtemp + 4] * rtb_TSamp + q_0[rtemp] * rtb_TSamp_e) +
                      q_0[rtemp + 8] * rtb_TSamp_jb) + q_0[rtemp + 12] * b_norm;
      }

      tmp_1[0] = -0.0 * dt;
      tmp_1[9] = MPC_DW.Delay1_DSTATE_gw[6] / 2.0 * dt;
      tmp_1[18] = -MPC_DW.Delay1_DSTATE_gw[5] / 2.0 * dt;
      tmp_1[1] = -MPC_DW.Delay1_DSTATE_gw[6] / 2.0 * dt;
      tmp_1[10] = -0.0 * dt;
      tmp_1[19] = MPC_DW.Delay1_DSTATE_gw[4] / 2.0 * dt;
      tmp_1[2] = MPC_DW.Delay1_DSTATE_gw[5] / 2.0 * dt;
      tmp_1[11] = -MPC_DW.Delay1_DSTATE_gw[4] / 2.0 * dt;
      tmp_1[20] = -0.0 * dt;
      for (rtemp = 0; rtemp < 3; rtemp++) {
        x_k[rtemp + 4] = MPC_DW.Delay1_DSTATE_gw[rtemp + 4];
        rtb_TSamp = MPC_DW.Delay1_DSTATE_gw[rtemp + 10];
        x_k[rtemp + 7] = MPC_DW.Delay1_DSTATE_gw[rtemp + 7] + rtb_TSamp * dt;
        x_k[rtemp + 10] = rtb_TSamp;
        BLACK_Estimated_Covar_tmp = (rtemp + 3) * 9;
        tmp_1[BLACK_Estimated_Covar_tmp] = F_tmp_0[3 * rtemp];
        i = (rtemp + 6) * 9;
        tmp_1[i] = 0.0 * dt;
        tmp_1[BLACK_Estimated_Covar_tmp + 1] = F_tmp_0[3 * rtemp + 1];
        tmp_1[i + 1] = 0.0 * dt;
        tmp_1[BLACK_Estimated_Covar_tmp + 2] = F_tmp_0[3 * rtemp + 2];
        tmp_1[i + 2] = 0.0 * dt;
      }

      for (rtemp = 0; rtemp < 9; rtemp++) {
        tmp_1[9 * rtemp + 3] = Phi_m_tmp[3 * rtemp];
        tmp_1[9 * rtemp + 6] = Phi_m_tmp_0[3 * rtemp];
        BLACK_Estimated_Covar_tmp = 3 * rtemp + 1;
        tmp_1[9 * rtemp + 4] = Phi_m_tmp[BLACK_Estimated_Covar_tmp];
        tmp_1[9 * rtemp + 7] = Phi_m_tmp_0[BLACK_Estimated_Covar_tmp];
        BLACK_Estimated_Covar_tmp = 3 * rtemp + 2;
        tmp_1[9 * rtemp + 5] = Phi_m_tmp[BLACK_Estimated_Covar_tmp];
        tmp_1[9 * rtemp + 8] = Phi_m_tmp_0[BLACK_Estimated_Covar_tmp];
      }

      MPC_expm(tmp_1, Phi_m);
      for (rtemp = 0; rtemp < 6; rtemp++) {
        L[12 * rtemp] = Phi_m[9 * rtemp];
        L[12 * rtemp + 1] = Phi_m[9 * rtemp + 1];
        L[12 * rtemp + 2] = Phi_m[9 * rtemp + 2];
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        i = (rtemp + 6) * 12;
        L[i] = 0.0;
        BLACK_Estimated_Covar_tmp = (rtemp + 9) * 12;
        L[BLACK_Estimated_Covar_tmp] = 0.0;
        L[i + 1] = 0.0;
        L[BLACK_Estimated_Covar_tmp + 1] = 0.0;
        L[i + 2] = 0.0;
        L[BLACK_Estimated_Covar_tmp + 2] = 0.0;
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        L[12 * rtemp + 3] = BLACK_Estimated_Covar_1[3 * rtemp];
        L[12 * rtemp + 4] = BLACK_Estimated_Covar_1[3 * rtemp + 1];
        L[12 * rtemp + 5] = BLACK_Estimated_Covar_1[3 * rtemp + 2];
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        L[12 * rtemp + 6] = 0.0;
        i = (rtemp + 3) * 12;
        L[i + 6] = 0.0;
        BLACK_Estimated_Covar_tmp = (rtemp + 6) * 12;
        L[BLACK_Estimated_Covar_tmp + 6] = F_tmp[3 * rtemp];
        r3 = (rtemp + 9) * 12;
        L[r3 + 6] = F_tmp_0[3 * rtemp];
        L[12 * rtemp + 7] = 0.0;
        L[i + 7] = 0.0;
        r2 = 3 * rtemp + 1;
        L[BLACK_Estimated_Covar_tmp + 7] = F_tmp[r2];
        L[r3 + 7] = F_tmp_0[r2];
        L[12 * rtemp + 8] = 0.0;
        L[i + 8] = 0.0;
        i = 3 * rtemp + 2;
        L[BLACK_Estimated_Covar_tmp + 8] = F_tmp[i];
        L[r3 + 8] = F_tmp_0[i];
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        L[12 * rtemp + 9] = F_tmp_1[3 * rtemp];
        L[12 * rtemp + 10] = F_tmp_1[3 * rtemp + 1];
        L[12 * rtemp + 11] = F_tmp_1[3 * rtemp + 2];
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += L[12 * i + rtemp] * MPC_DW.Delay_DSTATE_a[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          L_0[rtemp + 12 * BLACK_Estimated_Covar_tmp] = rtb_TSamp;
        }

        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_e += L_0[12 * i + rtemp] * L[12 * i +
              BLACK_Estimated_Covar_tmp];
          }

          i = 12 * BLACK_Estimated_Covar_tmp + rtemp;
          P_k[i] = b_Q[i] + rtb_TSamp_e;
        }
      }

      b_norm = sqrt(((rtb_TmpSignalConversionAtSFun_a[0] *
                      rtb_TmpSignalConversionAtSFun_a[0] +
                      rtb_TmpSignalConversionAtSFun_a[1] *
                      rtb_TmpSignalConversionAtSFun_a[1]) +
                     rtb_TmpSignalConversionAtSFun_a[2] *
                     rtb_TmpSignalConversionAtSFun_a[2]) +
                    rtb_TmpSignalConversionAtSFun_a[3] *
                    rtb_TmpSignalConversionAtSFun_a[3]);
      rtb_TSamp_e = b_norm * b_norm;
      a[0] = rtb_TmpSignalConversionAtSFun_a[0] / rtb_TSamp_e;
      a[1] = -rtb_TmpSignalConversionAtSFun_a[1] / rtb_TSamp_e;
      a[2] = -rtb_TmpSignalConversionAtSFun_a[2] / rtb_TSamp_e;
      a[3] = -rtb_TmpSignalConversionAtSFun_a[3] / rtb_TSamp_e;
      for (i = 0; i < 7; i++) {
        z_bar[i] = 0.0 * rtb_TmpSignalConversionAtSFun_o[i];
      }

      b_norm = sqrt(((a[0] * a[0] + a[1] * a[1]) + a[2] * a[2]) + a[3] * a[3]);
      axis[0] = a[1];
      axis[1] = a[2];
      axis[2] = a[3];
      rtb_TSamp = a[0];
      Rot_error[0] = 0.0;
      Rot_error[3] = -a[3];
      Rot_error[6] = a[2];
      Rot_error[1] = a[3];
      Rot_error[4] = 0.0;
      Rot_error[7] = -a[1];
      Rot_error[2] = -a[2];
      Rot_error[5] = a[1];
      Rot_error[8] = 0.0;
      q_0[0] = a[0];
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_jb = axis[rtemp];
        BLACK_Estimated_Covar_tmp = (rtemp + 1) << 2;
        q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
        q_0[rtemp + 1] = rtb_TSamp_jb;
        q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 * rtemp])
          * rtb_TSamp + Rot_error[3 * rtemp];
        i = 3 * rtemp + 1;
        q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
        i = 3 * rtemp + 2;
        q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
        rtb_y_i1[rtemp + 1] = x_k[rtemp + 7] -
          rtb_TmpSignalConversionAtSFun_a[rtemp + 4];
      }

      rtb_TSamp_e = rtb_y_i1[1];
      rtb_TSamp_jb = rtb_y_i1[2];
      rtb_y_eu = rtb_y_i1[3];
      for (rtemp = 0; rtemp < 4; rtemp++) {
        rtb_y_i1[rtemp] = ((q_0[rtemp + 4] * rtb_TSamp_e + q_0[rtemp] * 0.0) +
                           q_0[rtemp + 8] * rtb_TSamp_jb) + q_0[rtemp + 12] *
          rtb_y_eu;
      }

      axis[0] = rtb_y_i1[1];
      axis[1] = rtb_y_i1[2];
      axis[2] = rtb_y_i1[3];
      rtb_TSamp = rtb_y_i1[0];
      Rot_error[0] = 0.0;
      Rot_error[3] = -rtb_y_i1[3];
      Rot_error[6] = rtb_y_i1[2];
      Rot_error[1] = rtb_y_i1[3];
      Rot_error[4] = 0.0;
      Rot_error[7] = -rtb_y_i1[1];
      Rot_error[2] = -rtb_y_i1[2];
      Rot_error[5] = rtb_y_i1[1];
      Rot_error[8] = 0.0;
      b_norm *= b_norm;
      q_0[0] = rtb_y_i1[0];
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_jb = axis[rtemp];
        BLACK_Estimated_Covar_tmp = (rtemp + 1) << 2;
        q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
        q_0[rtemp + 1] = rtb_TSamp_jb;
        q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 * rtemp])
          * rtb_TSamp + Rot_error[3 * rtemp];
        r2 = 3 * rtemp + 1;
        q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[r2]) *
          rtb_TSamp + Rot_error[r2];
        r2 = 3 * rtemp + 2;
        q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[r2]) *
          rtb_TSamp + Rot_error[r2];
      }

      rtb_TSamp = a[0] / b_norm;
      rtb_TSamp_e = -a[1] / b_norm;
      rtb_TSamp_jb = -a[2] / b_norm;
      b_norm = -a[3] / b_norm;
      for (rtemp = 0; rtemp < 4; rtemp++) {
        rtb_y_i1[rtemp] = ((q_0[rtemp + 4] * rtb_TSamp_e + q_0[rtemp] *
                            rtb_TSamp) + q_0[rtemp + 8] * rtb_TSamp_jb) +
          q_0[rtemp + 12] * b_norm;
      }

      axis[0] = x_k[1];
      axis[1] = x_k[2];
      axis[2] = x_k[3];
      rtb_TSamp = x_k[0];
      Rot_error[0] = 0.0;
      Rot_error[3] = -x_k[3];
      Rot_error[6] = x_k[2];
      Rot_error[1] = x_k[3];
      Rot_error[4] = 0.0;
      Rot_error[7] = -x_k[1];
      Rot_error[2] = -x_k[2];
      Rot_error[5] = x_k[1];
      Rot_error[8] = 0.0;
      q_0[0] = x_k[0];
      for (rtemp = 0; rtemp < 3; rtemp++) {
        z_bar[rtemp + 4] = rtb_y_i1[rtemp + 1];
        rtb_TSamp_jb = axis[rtemp];
        BLACK_Estimated_Covar_tmp = (rtemp + 1) << 2;
        q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
        q_0[rtemp + 1] = rtb_TSamp_jb;
        q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 * rtemp])
          * rtb_TSamp + Rot_error[3 * rtemp];
        i = 3 * rtemp + 1;
        q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
        i = 3 * rtemp + 2;
        q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
      }

      rtb_TSamp = a[1];
      b_norm = a[0];
      rtb_TSamp_e = a[2];
      rtb_TSamp_jb = a[3];
      for (rtemp = 0; rtemp < 4; rtemp++) {
        z_bar[rtemp] = ((q_0[rtemp + 4] * rtb_TSamp + q_0[rtemp] * b_norm) +
                        q_0[rtemp + 8] * rtb_TSamp_e) + q_0[rtemp + 12] *
          rtb_TSamp_jb;
      }

      MPC_smallQuat(&z_bar[0], rtb_y_i1);
      z_bar[0] = rtb_y_i1[0];
      z_bar[1] = rtb_y_i1[1];
      z_bar[2] = rtb_y_i1[2];
      z_bar[3] = rtb_y_i1[3];
      rtb_TSamp = a[0];
      b_norm = a[1];
      rtb_TSamp_e = a[2];
      rtb_TSamp_jb = a[3];
      a[0] = a[0];
      a[1] = -b_norm;
      a[2] = -rtb_TSamp_e;
      a[3] = -rtb_TSamp_jb;
      for (rtemp = 0; rtemp < 12; rtemp++) {
        H[6 * rtemp] = H_tmp[3 * rtemp];
        H[6 * rtemp + 1] = H_tmp[3 * rtemp + 1];
        H[6 * rtemp + 2] = H_tmp[3 * rtemp + 2];
      }

      rtb_y_eu = -rtb_TSamp_jb * -rtb_TSamp_jb;
      rtb_y_gs = -rtb_TSamp_e * -rtb_TSamp_e;
      H[39] = 1.0 - (rtb_y_gs + rtb_y_eu) * 2.0;
      e_in_tmp = -b_norm * -rtb_TSamp_e;
      e_in_0 = rtb_TSamp * -rtb_TSamp_jb;
      H[45] = (e_in_tmp + e_in_0) * 2.0;
      H_tmp_0 = (-b_norm * -rtb_TSamp_jb + rtb_TSamp * -rtb_TSamp_e) * 2.0;
      H[51] = H_tmp_0;
      H[40] = (e_in_tmp - e_in_0) * 2.0;
      e_in_tmp = -b_norm * -b_norm;
      H[46] = 1.0 - (e_in_tmp + rtb_y_eu) * 2.0;
      rtb_y_eu = -rtb_TSamp_e * -rtb_TSamp_jb;
      e_in_0 = rtb_TSamp * -b_norm;
      H[52] = (rtb_y_eu + e_in_0) * 2.0;
      H[41] = H_tmp_0;
      H[47] = (rtb_y_eu - e_in_0) * 2.0;
      H[53] = 1.0 - (e_in_tmp + rtb_y_gs) * 2.0;
      for (rtemp = 0; rtemp < 3; rtemp++) {
        H[6 * rtemp + 3] = 0.0;
        r2 = (rtemp + 3) * 6;
        H[r2 + 3] = 0.0;
        BLACK_Estimated_Covar_tmp = (rtemp + 9) * 6;
        H[BLACK_Estimated_Covar_tmp + 3] = 0.0;
        H[6 * rtemp + 4] = 0.0;
        H[r2 + 4] = 0.0;
        H[BLACK_Estimated_Covar_tmp + 4] = 0.0;
        H[6 * rtemp + 5] = 0.0;
        H[r2 + 5] = 0.0;
        H[BLACK_Estimated_Covar_tmp + 5] = 0.0;
      }

      rEQ0 = false;
      for (i = 0; i < 7; i++) {
        if (!rEQ0) {
          rEQ0 = rtIsNaN(rtb_TmpSignalConversionAtSFun_o[i]);
        }
      }

      if (!rEQ0) {
        rtb_TSamp_e = MPC_rand_p();
        rtb_y_i1[3] = (rtb_TSamp_e - 0.5) * 0.0;
        axis[0] = 0.0;
        axis[1] = 0.0;
        axis[2] = 1.0;
        rtb_TSamp_e = MPC_norm(axis);
        rtb_TSamp_jb = sin(rtb_y_i1[3] / 2.0);
        q[0] = cos(rtb_y_i1[3] / 2.0);
        b_norm = 0.0 / rtb_TSamp_e * rtb_TSamp_jb;
        rtb_TSamp_jb *= 1.0 / rtb_TSamp_e;
        axis[0] = b_norm;
        axis[1] = b_norm;
        axis[2] = rtb_TSamp_jb;
        rtb_TSamp = q[0];
        Rot_error[0] = 0.0;
        Rot_error[3] = -rtb_TSamp_jb;
        Rot_error[6] = b_norm;
        Rot_error[1] = rtb_TSamp_jb;
        Rot_error[4] = 0.0;
        Rot_error[7] = -b_norm;
        Rot_error[2] = -b_norm;
        Rot_error[5] = b_norm;
        Rot_error[8] = 0.0;
        q_0[0] = q[0];
        for (rtemp = 0; rtemp < 3; rtemp++) {
          rtb_TSamp_jb = axis[rtemp];
          BLACK_Estimated_Covar_tmp = (rtemp + 1) << 2;
          q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
          q_0[rtemp + 1] = rtb_TSamp_jb;
          q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 *
            rtemp]) * rtb_TSamp + Rot_error[3 * rtemp];
          i = 3 * rtemp + 1;
          q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[i]) *
            rtb_TSamp + Rot_error[i];
          i = 3 * rtemp + 2;
          q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[i]) *
            rtb_TSamp + Rot_error[i];
        }

        rtb_TSamp = rtb_TmpSignalConversionAtSFun_o[1];
        rtb_TSamp_e = rtb_TmpSignalConversionAtSFun_o[0];
        rtb_TSamp_jb = rtb_TmpSignalConversionAtSFun_o[2];
        b_norm = rtb_TmpSignalConversionAtSFun_o[3];
        for (rtemp = 0; rtemp < 4; rtemp++) {
          q[rtemp] = ((q_0[rtemp + 4] * rtb_TSamp + q_0[rtemp] * rtb_TSamp_e) +
                      q_0[rtemp + 8] * rtb_TSamp_jb) + q_0[rtemp + 12] * b_norm;
        }

        rtb_TmpSignalConversionAtSFun_o[0] = q[0];
        rtb_TmpSignalConversionAtSFun_o[1] = q[1];
        rtb_TmpSignalConversionAtSFun_o[2] = q[2];
        rtb_TmpSignalConversionAtSFun_o[3] = q[3];
      }

      axis[0] = rtb_TmpSignalConversionAtSFun_o[1];
      axis[1] = rtb_TmpSignalConversionAtSFun_o[2];
      axis[2] = rtb_TmpSignalConversionAtSFun_o[3];
      rtb_TSamp = rtb_TmpSignalConversionAtSFun_o[0];
      Rot_error[0] = 0.0;
      Rot_error[3] = -rtb_TmpSignalConversionAtSFun_o[3];
      Rot_error[6] = rtb_TmpSignalConversionAtSFun_o[2];
      Rot_error[1] = rtb_TmpSignalConversionAtSFun_o[3];
      Rot_error[4] = 0.0;
      Rot_error[7] = -rtb_TmpSignalConversionAtSFun_o[1];
      Rot_error[2] = -rtb_TmpSignalConversionAtSFun_o[2];
      Rot_error[5] = rtb_TmpSignalConversionAtSFun_o[1];
      Rot_error[8] = 0.0;
      q_0[0] = rtb_TmpSignalConversionAtSFun_o[0];
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_jb = axis[rtemp];
        BLACK_Estimated_Covar_tmp = (rtemp + 1) << 2;
        q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
        q_0[rtemp + 1] = rtb_TSamp_jb;
        q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 * rtemp])
          * rtb_TSamp + Rot_error[3 * rtemp];
        i = 3 * rtemp + 1;
        q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
        i = 3 * rtemp + 2;
        q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
      }

      rtb_TSamp = z_bar[0];
      rtb_TSamp_e = -z_bar[1];
      rtb_TSamp_jb = -z_bar[2];
      b_norm = -z_bar[3];
      for (rtemp = 0; rtemp < 4; rtemp++) {
        rtb_q_k[rtemp] = ((q_0[rtemp + 4] * rtb_TSamp_e + q_0[rtemp] * rtb_TSamp)
                          + q_0[rtemp + 8] * rtb_TSamp_jb) + q_0[rtemp + 12] *
          b_norm;
      }

      MPC_smallQuat(rtb_q_k, q);
      MPC_DW.STQMEKFerror[0] = q[1] / (q[0] + 1.0);
      MPC_DW.STQMEKFerror[1] = q[2] / (q[0] + 1.0);
      MPC_DW.STQMEKFerror[2] = q[3] / (q[0] + 1.0);
      MPC_DW.STQMEKFerror[3] = rtb_TmpSignalConversionAtSFun_o[4] - z_bar[4];
      MPC_DW.STQMEKFerror[4] = rtb_TmpSignalConversionAtSFun_o[5] - z_bar[5];
      MPC_DW.STQMEKFerror[5] = rtb_TmpSignalConversionAtSFun_o[6] - z_bar[6];
      rEQ0 = rtIsNaN(rtb_TmpSignalConversionAtSFun_o[0]);
      if (!rEQ0) {
        rEQ0 = rtIsNaN(rtb_TmpSignalConversionAtSFun_o[1]);
      }

      if (!rEQ0) {
        rEQ0 = rtIsNaN(rtb_TmpSignalConversionAtSFun_o[2]);
      }

      if (!rEQ0) {
        rEQ0 = rtIsNaN(rtb_TmpSignalConversionAtSFun_o[3]);
      }

      if (rEQ0) {
        rEQ0 = true;
      } else {
        for (rtemp = 0; rtemp < 3; rtemp++) {
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
               BLACK_Estimated_Covar_tmp++) {
            rtb_TSamp = 0.0;
            for (i = 0; i < 12; i++) {
              rtb_TSamp += H[6 * i + rtemp] * P_k[12 * BLACK_Estimated_Covar_tmp
                + i];
            }

            BLACK_Estimated_Covar_0[rtemp + 3 * BLACK_Estimated_Covar_tmp] =
              rtb_TSamp;
          }

          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
               BLACK_Estimated_Covar_tmp++) {
            rtb_TSamp = 0.0;
            for (i = 0; i < 12; i++) {
              rtb_TSamp += BLACK_Estimated_Covar_0[3 * i + rtemp] * H[6 * i +
                BLACK_Estimated_Covar_tmp];
            }

            Rot_error[rtemp + 3 * BLACK_Estimated_Covar_tmp] = rtb_TSamp;
          }
        }

        rtb_TSamp_e = 0.0;
        for (rtemp = 0; rtemp < 3; rtemp++) {
          rtb_TSamp_e += ((Rot_error[3 * rtemp + 1] * MPC_DW.STQMEKFerror[1] +
                           Rot_error[3 * rtemp] * MPC_DW.STQMEKFerror[0]) +
                          Rot_error[3 * rtemp + 2] * MPC_DW.STQMEKFerror[2]) *
            MPC_DW.STQMEKFerror[rtemp];
        }

        rEQ0 = !(sqrt(rtb_TSamp_e) < 1.6046);
      }

      rejectPose = rtIsNaN(rtb_TmpSignalConversionAtSFun_o[4]);
      if (!rejectPose) {
        rejectPose = rtIsNaN(rtb_TmpSignalConversionAtSFun_o[5]);
      }

      if (!rejectPose) {
        rejectPose = rtIsNaN(rtb_TmpSignalConversionAtSFun_o[6]);
      }

      if (rejectPose) {
        rejectPose = true;
      } else {
        for (rtemp = 0; rtemp < 3; rtemp++) {
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
               BLACK_Estimated_Covar_tmp++) {
            rtb_TSamp = 0.0;
            for (i = 0; i < 12; i++) {
              rtb_TSamp += H[(6 * i + rtemp) + 3] * P_k[12 *
                BLACK_Estimated_Covar_tmp + i];
            }

            BLACK_Estimated_Covar_0[rtemp + 3 * BLACK_Estimated_Covar_tmp] =
              rtb_TSamp;
          }

          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
               BLACK_Estimated_Covar_tmp++) {
            rtb_TSamp = 0.0;
            for (i = 0; i < 12; i++) {
              rtb_TSamp += H[(6 * i + BLACK_Estimated_Covar_tmp) + 3] *
                BLACK_Estimated_Covar_0[3 * i + rtemp];
            }

            Rot_error[rtemp + 3 * BLACK_Estimated_Covar_tmp] = rtb_TSamp;
          }
        }

        rtb_TSamp_e = 0.0;
        for (rtemp = 0; rtemp < 3; rtemp++) {
          rtb_TSamp_e += ((Rot_error[3 * rtemp + 1] * MPC_DW.STQMEKFerror[4] +
                           Rot_error[3 * rtemp] * MPC_DW.STQMEKFerror[3]) +
                          Rot_error[3 * rtemp + 2] * MPC_DW.STQMEKFerror[5]) *
            MPC_DW.STQMEKFerror[rtemp + 3];
        }

        rejectPose = !(sqrt(rtb_TSamp_e) < 5.5866);
      }

      if (rEQ0) {
        MPC_DW.STQMEKFerror[0] = 0.0;
        MPC_DW.STQMEKFerror[1] = 0.0;
        MPC_DW.STQMEKFerror[2] = 0.0;
        for (rtemp = 0; rtemp < 12; rtemp++) {
          H[6 * rtemp] = 0.0;
          H[6 * rtemp + 1] = 0.0;
          H[6 * rtemp + 2] = 0.0;
        }
      }

      if (rejectPose) {
        MPC_DW.STQMEKFerror[3] = 0.0;
        MPC_DW.STQMEKFerror[4] = 0.0;
        MPC_DW.STQMEKFerror[5] = 0.0;
        for (rtemp = 0; rtemp < 12; rtemp++) {
          H[6 * rtemp + 3] = 0.0;
          H[6 * rtemp + 4] = 0.0;
          H[6 * rtemp + 5] = 0.0;
        }
      }

      if ((!rEQ0) || (!rejectPose)) {
        if (rEQ0) {
          for (rtemp = 0; rtemp < 3; rtemp++) {
            BLACK_Estimated_Covar_tmp = (rtemp + 3) * 6;
            R_chaser[3 * rtemp] =
              MPC_DW.Delay2_DSTATE_nz[BLACK_Estimated_Covar_tmp + 3];
            R_chaser[3 * rtemp + 1] =
              MPC_DW.Delay2_DSTATE_nz[BLACK_Estimated_Covar_tmp + 4];
            R_chaser[3 * rtemp + 2] =
              MPC_DW.Delay2_DSTATE_nz[BLACK_Estimated_Covar_tmp + 5];
          }

          if (MPC_det(R_chaser) == 0.0) {
            for (rtemp = 0; rtemp < 3; rtemp++) {
              rtb_TSamp = MPC_DW.STQMEKFerror[rtemp + 3];
              R_chaser[3 * rtemp] = rtb_TSamp * MPC_DW.STQMEKFerror[3];
              R_chaser[3 * rtemp + 1] = rtb_TSamp * MPC_DW.STQMEKFerror[4];
              R_chaser[3 * rtemp + 2] = rtb_TSamp * MPC_DW.STQMEKFerror[5];
            }
          }

          for (rtemp = 0; rtemp < 3; rtemp++) {
            i = (rtemp + 3) * 6;
            MPC_DW.Delay2_DSTATE_nz[i + 3] = (R_chaser[3 * rtemp] * 0.98 +
              MPC_DW.STQMEKFerror[rtemp + 3] * MPC_DW.STQMEKFerror[3]) / 1.98;
            MPC_DW.Delay2_DSTATE_nz[i + 4] = (R_chaser[3 * rtemp + 1] * 0.98 +
              MPC_DW.STQMEKFerror[rtemp + 3] * MPC_DW.STQMEKFerror[4]) / 1.98;
            MPC_DW.Delay2_DSTATE_nz[i + 5] = (R_chaser[3 * rtemp + 2] * 0.98 +
              MPC_DW.STQMEKFerror[rtemp + 3] * MPC_DW.STQMEKFerror[5]) / 1.98;
          }
        } else if (rejectPose) {
          for (rtemp = 0; rtemp < 3; rtemp++) {
            R_chaser[3 * rtemp] = MPC_DW.Delay2_DSTATE_nz[6 * rtemp];
            R_chaser[3 * rtemp + 1] = MPC_DW.Delay2_DSTATE_nz[6 * rtemp + 1];
            R_chaser[3 * rtemp + 2] = MPC_DW.Delay2_DSTATE_nz[6 * rtemp + 2];
          }

          if (MPC_det(R_chaser) == 0.0) {
            for (rtemp = 0; rtemp < 3; rtemp++) {
              R_chaser[3 * rtemp] = MPC_DW.STQMEKFerror[0] *
                MPC_DW.STQMEKFerror[rtemp];
              R_chaser[3 * rtemp + 1] = MPC_DW.STQMEKFerror[1] *
                MPC_DW.STQMEKFerror[rtemp];
              R_chaser[3 * rtemp + 2] = MPC_DW.STQMEKFerror[2] *
                MPC_DW.STQMEKFerror[rtemp];
            }
          }

          for (rtemp = 0; rtemp < 3; rtemp++) {
            MPC_DW.Delay2_DSTATE_nz[6 * rtemp] = (R_chaser[3 * rtemp] * 0.98 +
              MPC_DW.STQMEKFerror[0] * MPC_DW.STQMEKFerror[rtemp]) / 1.98;
            MPC_DW.Delay2_DSTATE_nz[6 * rtemp + 1] = (R_chaser[3 * rtemp + 1] *
              0.98 + MPC_DW.STQMEKFerror[1] * MPC_DW.STQMEKFerror[rtemp]) / 1.98;
            MPC_DW.Delay2_DSTATE_nz[6 * rtemp + 2] = (R_chaser[3 * rtemp + 2] *
              0.98 + MPC_DW.STQMEKFerror[2] * MPC_DW.STQMEKFerror[rtemp]) / 1.98;
          }
        } else {
          memcpy(&BLACK_Estimated_Covar_1[0], &MPC_DW.Delay2_DSTATE_nz[0], 36U *
                 sizeof(real_T));
          MPC_xgetrf(BLACK_Estimated_Covar_1, ipiv, &rtemp);
          rtb_y_eu = BLACK_Estimated_Covar_1[0];
          rEQ0 = false;
          for (r2 = 0; r2 < 5; r2++) {
            rtb_y_eu *= BLACK_Estimated_Covar_1[((r2 + 1) * 6 + r2) + 1];
            if (ipiv[r2] > r2 + 1) {
              rEQ0 = !rEQ0;
            }
          }

          if (rEQ0) {
            rtb_y_eu = -rtb_y_eu;
          }

          if (rtb_y_eu == 0.0) {
            for (rtemp = 0; rtemp < 6; rtemp++) {
              for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
                   BLACK_Estimated_Covar_tmp++) {
                MPC_DW.Delay2_DSTATE_nz[BLACK_Estimated_Covar_tmp + 6 * rtemp] =
                  MPC_DW.STQMEKFerror[BLACK_Estimated_Covar_tmp] *
                  MPC_DW.STQMEKFerror[rtemp];
              }
            }
          }

          for (rtemp = 0; rtemp < 6; rtemp++) {
            for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
                 BLACK_Estimated_Covar_tmp++) {
              i = 6 * rtemp + BLACK_Estimated_Covar_tmp;
              MPC_DW.Delay2_DSTATE_nz[i] = (MPC_DW.Delay2_DSTATE_nz[i] * 0.98 +
                MPC_DW.STQMEKFerror[BLACK_Estimated_Covar_tmp] *
                MPC_DW.STQMEKFerror[rtemp]) / 1.98;
            }
          }
        }
      }

      MPC_lsqnonlin(P_k, H, MPC_DW.Delay2_DSTATE_nz, Chaser);
      memset(&R_chaser[0], 0, 9U * sizeof(real_T));
      R_chaser[0] = Chaser[0];
      R_chaser[4] = Chaser[1];
      R_chaser[8] = Chaser[2];
      memset(&Rot_pred[0], 0, 9U * sizeof(real_T));
      Rot_pred[0] = Chaser[0];
      Rot_pred[4] = Chaser[1];
      Rot_pred[8] = Chaser[2];
      memset(&R_chaser_0[0], 0, 9U * sizeof(real_T));
      R_chaser_0[0] = Chaser[3];
      R_chaser_0[4] = Chaser[4];
      R_chaser_0[8] = Chaser[5];
      memset(&varargin_4[0], 0, 9U * sizeof(real_T));
      varargin_4[0] = Chaser[3];
      varargin_4[4] = Chaser[4];
      varargin_4[8] = Chaser[5];
      memset(&L[0], 0, 144U * sizeof(real_T));
      for (rtemp = 0; rtemp < 3; rtemp++) {
        L[12 * rtemp] = R_chaser[3 * rtemp];
        i = (rtemp + 3) * 12;
        L[i + 3] = Rot_pred[3 * rtemp];
        BLACK_Estimated_Covar_tmp = (rtemp + 6) * 12;
        L[BLACK_Estimated_Covar_tmp + 6] = R_chaser_0[3 * rtemp];
        r3 = (rtemp + 9) * 12;
        L[r3 + 9] = varargin_4[3 * rtemp];
        r2 = 3 * rtemp + 1;
        L[12 * rtemp + 1] = R_chaser[r2];
        L[i + 4] = Rot_pred[r2];
        L[BLACK_Estimated_Covar_tmp + 7] = R_chaser_0[r2];
        L[r3 + 10] = varargin_4[r2];
        r2 = 3 * rtemp + 2;
        L[12 * rtemp + 2] = R_chaser[r2];
        L[i + 5] = Rot_pred[r2];
        L[BLACK_Estimated_Covar_tmp + 8] = R_chaser_0[r2];
        L[r3 + 11] = varargin_4[r2];
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += L[12 * i + BLACK_Estimated_Covar_tmp] * P_k[12 * rtemp
              + i];
          }

          L_0[BLACK_Estimated_Covar_tmp + 12 * rtemp] = rtb_TSamp;
        }
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += L_0[12 * i + BLACK_Estimated_Covar_tmp] * L[12 * rtemp
              + i];
          }

          P_k[BLACK_Estimated_Covar_tmp + 12 * rtemp] = rtb_TSamp;
        }
      }

      for (rtemp = 0; rtemp < 36; rtemp++) {
        MPC_DW.Delay2_DSTATE_nz[rtemp] *= 0.98;
      }

      for (rtemp = 0; rtemp < 6; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          K_tmp[BLACK_Estimated_Covar_tmp + 12 * rtemp] = H[6 *
            BLACK_Estimated_Covar_tmp + rtemp];
        }
      }

      for (rtemp = 0; rtemp < 6; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_e = 0.0;
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_e += P_k[12 * i + BLACK_Estimated_Covar_tmp] * K_tmp[12 *
              rtemp + i];
            rtb_TSamp += H[6 * i + rtemp] * P_k[12 * BLACK_Estimated_Covar_tmp +
              i];
          }

          K_0[BLACK_Estimated_Covar_tmp + 12 * rtemp] = rtb_TSamp_e;
          H_0[rtemp + 6 * BLACK_Estimated_Covar_tmp] = rtb_TSamp;
        }

        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_e += H_0[6 * i + rtemp] * K_tmp[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          r2 = 6 * BLACK_Estimated_Covar_tmp + rtemp;
          BLACK_Estimated_Covar_0[r2] = b_R[r2] + rtb_TSamp_e;
        }
      }

      MPC_mrdiv_n(K_0, BLACK_Estimated_Covar_0);
      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp += K_0[12 * i + BLACK_Estimated_Covar_tmp] * H[6 * rtemp +
              i];
          }

          L[BLACK_Estimated_Covar_tmp + 12 * rtemp] = rtb_TSamp;
        }
      }

      for (rtemp = 0; rtemp < 144; rtemp++) {
        L_0[rtemp] = static_cast<real_T>(QMEKFP_tmp_2[rtemp]) - L[rtemp];
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += L_0[12 * i + rtemp] * P_k[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          r2 = 12 * BLACK_Estimated_Covar_tmp + rtemp;
          QMEKFP_tmp_0[r2] = rtb_TSamp;
          i = 12 * rtemp + BLACK_Estimated_Covar_tmp;
          QMEKFP_tmp_1[i] = static_cast<real_T>(QMEKFP_tmp[i]) - L[r2];
        }

        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp_e += K_0[12 * i + rtemp] * b_R[6 *
              BLACK_Estimated_Covar_tmp + i];
          }

          H_0[rtemp + 12 * BLACK_Estimated_Covar_tmp] = rtb_TSamp_e;
        }
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += QMEKFP_tmp_0[12 * i + rtemp] * QMEKFP_tmp_1[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          r2 = 12 * BLACK_Estimated_Covar_tmp + rtemp;
          L_0[r2] = rtb_TSamp;
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp_e += H_0[12 * i + rtemp] * K_0[12 * i +
              BLACK_Estimated_Covar_tmp];
          }

          L[r2] = rtb_TSamp_e;
        }
      }

      for (rtemp = 0; rtemp < 144; rtemp++) {
        MPC_DW.STQMEKFP[rtemp] = L_0[rtemp] + L[rtemp];
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        rtb_TSamp = 0.0;
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp += K_0[12 * BLACK_Estimated_Covar_tmp + rtemp] *
            MPC_DW.STQMEKFerror[BLACK_Estimated_Covar_tmp];
        }

        delta_x[rtemp] = rtb_TSamp;
      }

      rtb_TSamp = MPC_norm(&delta_x[0]);
      rtb_TSamp *= rtb_TSamp;
      rtb_TSamp = (sqrt(rtb_TSamp * 0.0 + 1.0) - rtb_TSamp) / (rtb_TSamp + 1.0);
      rtb_TSamp_jb = (rtb_TSamp + 1.0) * delta_x[0];
      b_norm = (rtb_TSamp + 1.0) * delta_x[1];
      rtb_TSamp_e = (rtb_TSamp + 1.0) * delta_x[2];
      axis[0] = rtb_TSamp_jb;
      axis[1] = b_norm;
      axis[2] = rtb_TSamp_e;
      Rot_error[0] = 0.0;
      Rot_error[3] = -rtb_TSamp_e;
      Rot_error[6] = b_norm;
      Rot_error[1] = rtb_TSamp_e;
      Rot_error[4] = 0.0;
      Rot_error[7] = -rtb_TSamp_jb;
      Rot_error[2] = -b_norm;
      Rot_error[5] = rtb_TSamp_jb;
      Rot_error[8] = 0.0;
      q_0[0] = rtb_TSamp;
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_jb = axis[rtemp];
        BLACK_Estimated_Covar_tmp = (rtemp + 1) << 2;
        q_0[BLACK_Estimated_Covar_tmp] = -rtb_TSamp_jb;
        q_0[rtemp + 1] = rtb_TSamp_jb;
        q_0[BLACK_Estimated_Covar_tmp + 1] = static_cast<real_T>(F_tmp[3 * rtemp])
          * rtb_TSamp + Rot_error[3 * rtemp];
        i = 3 * rtemp + 1;
        q_0[BLACK_Estimated_Covar_tmp + 2] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
        i = 3 * rtemp + 2;
        q_0[BLACK_Estimated_Covar_tmp + 3] = static_cast<real_T>(F_tmp[i]) *
          rtb_TSamp + Rot_error[i];
      }

      rtb_TSamp = x_k[1];
      rtb_TSamp_e = x_k[0];
      rtb_TSamp_jb = x_k[2];
      b_norm = x_k[3];
      for (rtemp = 0; rtemp < 4; rtemp++) {
        MPC_DW.Delay1_DSTATE_gw[rtemp] = ((q_0[rtemp + 4] * rtb_TSamp +
          q_0[rtemp] * rtb_TSamp_e) + q_0[rtemp + 8] * rtb_TSamp_jb) + q_0[rtemp
          + 12] * b_norm;
      }

      for (i = 0; i < 9; i++) {
        MPC_DW.Delay1_DSTATE_gw[i + 4] = x_k[i + 4] + delta_x[i + 3];
      }

      MPC_DW.STQMEKFt = MPC_toc_h(&savedTime_a);
      for (i = 0; i < 6; i++) {
        Chaser[i] = MPC_DW.STQMEKFerror[i];
        for (rtemp = 0; rtemp < 12; rtemp++) {
          rtb_TSamp = 0.0;
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
               BLACK_Estimated_Covar_tmp++) {
            rtb_TSamp += H[6 * BLACK_Estimated_Covar_tmp + i] * MPC_DW.STQMEKFP
              [12 * rtemp + BLACK_Estimated_Covar_tmp];
          }

          H_0[i + 6 * rtemp] = rtb_TSamp;
        }

        for (rtemp = 0; rtemp < 6; rtemp++) {
          rtb_TSamp_e = 0.0;
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
               BLACK_Estimated_Covar_tmp++) {
            rtb_TSamp_e += H_0[6 * BLACK_Estimated_Covar_tmp + i] * K_tmp[12 *
              rtemp + BLACK_Estimated_Covar_tmp];
          }

          r2 = 6 * rtemp + i;
          BLACK_Estimated_Covar_0[r2] = b_R[r2] + rtb_TSamp_e;
        }
      }

      MPC_mrdiv_dtsy(Chaser, BLACK_Estimated_Covar_0);
      MPC_DW.STQMEKFNIS = 0.0;
      for (rtemp = 0; rtemp < 6; rtemp++) {
        MPC_DW.STQMEKFNIS += Chaser[rtemp] * MPC_DW.STQMEKFerror[rtemp];
      }

      // MATLAB Function: '<S101>/MATLAB Function2'
      MPC_MATLABFunction_a(MPC_DW.Delay1_DSTATE_gw, rtb_out);

      // DataStoreWrite: '<S101>/Data Store Write17'
      memcpy(&MPC_DW.STQMEKFx[0], &rtb_out[0], 13U * sizeof(real_T));

      // MATLAB Function: '<S102>/MATLAB Function1' incorporates:
      //   DataStoreRead: '<S102>/Data Store Read1'
      //   DataStoreRead: '<S102>/Data Store Read4'
      //   DataStoreWrite: '<S102>/Data Store Write18'
      //   Delay: '<S102>/Delay1'
      //   Delay: '<S102>/Delay2'
      //   Delay: '<S102>/Delay3'
      //   Delay: '<S102>/Delay4'

      MPC_tic_p(&savedTime_aw);
      Rot_error[0] = 0.0 * dt;
      b_norm = -MPC_DW.Delay1_DSTATE_n[8] * dt;
      Rot_error[3] = b_norm;
      rtb_y_gs = MPC_DW.Delay1_DSTATE_n[7] * dt;
      Rot_error[6] = rtb_y_gs;
      e_in_tmp = MPC_DW.Delay1_DSTATE_n[8] * dt;
      Rot_error[1] = e_in_tmp;
      Rot_error[4] = 0.0 * dt;
      e_in_0 = -MPC_DW.Delay1_DSTATE_n[6] * dt;
      Rot_error[7] = e_in_0;
      rtb_y_eu = -MPC_DW.Delay1_DSTATE_n[7] * dt;
      Rot_error[2] = rtb_y_eu;
      H_tmp_0 = MPC_DW.Delay1_DSTATE_n[6] * dt;
      Rot_error[5] = H_tmp_0;
      Rot_error[8] = 0.0 * dt;
      MPC_expm_o(Rot_error, R_chaser);
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp = MPC_DW.Delay4_DSTATE[3 * rtemp + 1];
        rtb_TSamp_e = MPC_DW.Delay4_DSTATE[3 * rtemp];
        rtb_TSamp_jb = MPC_DW.Delay4_DSTATE[3 * rtemp + 2];
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          Rot_pred[BLACK_Estimated_Covar_tmp + 3 * rtemp] =
            (R_chaser[BLACK_Estimated_Covar_tmp + 3] * rtb_TSamp + rtb_TSamp_e *
             R_chaser[BLACK_Estimated_Covar_tmp]) +
            R_chaser[BLACK_Estimated_Covar_tmp + 6] * rtb_TSamp_jb;
        }
      }

      memcpy(&x_est[0], &MPC_DW.Delay1_DSTATE_n[0], 9U * sizeof(real_T));
      x_est[0] = dt * MPC_DW.Delay1_DSTATE_n[3] + MPC_DW.Delay1_DSTATE_n[0];
      x_est[1] = dt * MPC_DW.Delay1_DSTATE_n[4] + MPC_DW.Delay1_DSTATE_n[1];
      x_est[2] = dt * MPC_DW.Delay1_DSTATE_n[5] + MPC_DW.Delay1_DSTATE_n[2];
      L[0] = rtb_TSamp_lb;
      L[1] = e_in_tmp;
      L[2] = rtb_y_eu;
      L[12] = b_norm;
      L[13] = rtb_TSamp_lb;
      L[14] = H_tmp_0;
      L[24] = rtb_y_gs;
      L[25] = e_in_0;
      L[26] = rtb_TSamp_lb;
      for (rtemp = 0; rtemp < 6; rtemp++) {
        i = (rtemp + 3) * 12;
        L[i] = 0.0;
        L[i + 1] = 0.0;
        L[i + 2] = 0.0;
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp = F_tmp_0[3 * rtemp];
        i = (rtemp + 9) * 12;
        L[i] = rtb_TSamp;
        L[12 * rtemp + 3] = 0.0;
        BLACK_Estimated_Covar_tmp = (rtemp + 3) * 12;
        L[BLACK_Estimated_Covar_tmp + 3] = F_tmp[3 * rtemp];
        r3 = (rtemp + 6) * 12;
        L[r3 + 3] = rtb_TSamp;
        L[i + 3] = 0.0;
        r2 = 3 * rtemp + 1;
        rtb_TSamp = F_tmp_0[r2];
        L[i + 1] = rtb_TSamp;
        L[12 * rtemp + 4] = 0.0;
        L[BLACK_Estimated_Covar_tmp + 4] = F_tmp[r2];
        L[r3 + 4] = rtb_TSamp;
        L[i + 4] = 0.0;
        r2 = 3 * rtemp + 2;
        rtb_TSamp = F_tmp_0[r2];
        L[i + 2] = rtb_TSamp;
        L[12 * rtemp + 5] = 0.0;
        L[BLACK_Estimated_Covar_tmp + 5] = F_tmp[r2];
        L[r3 + 5] = rtb_TSamp;
        L[i + 5] = 0.0;
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        L[12 * rtemp + 6] = F_tmp_2[3 * rtemp];
        L[12 * rtemp + 9] = F_tmp_1[3 * rtemp];
        i = 3 * rtemp + 1;
        L[12 * rtemp + 7] = F_tmp_2[i];
        L[12 * rtemp + 10] = F_tmp_1[i];
        i = 3 * rtemp + 2;
        L[12 * rtemp + 8] = F_tmp_2[i];
        L[12 * rtemp + 11] = F_tmp_1[i];
      }

      rtb_TSamp = 2.0 * rtb_y_pc[2];
      R_chaser[0] = rtb_TSamp * 0.0 + R_chaser_tmp[0];
      R_chaser[1] = rtb_TSamp * b[2] + R_chaser_tmp[1];
      R_chaser[2] = rtb_TSamp * -b[1] + R_chaser_tmp[2];
      R_chaser[3] = rtb_TSamp * -b[2] + R_chaser_tmp[3];
      R_chaser[4] = rtb_TSamp * 0.0 + R_chaser_tmp[4];
      R_chaser[5] = rtb_TSamp * b[0] + R_chaser_tmp[5];
      R_chaser[6] = rtb_TSamp * b[1] + R_chaser_tmp[6];
      R_chaser[7] = rtb_TSamp * -b[0] + R_chaser_tmp[7];
      R_chaser[8] = rtb_TSamp * 0.0 + R_chaser_tmp[8];
      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += L[12 * i + rtemp] * MPC_DW.Delay2_DSTATE_kf[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          L_0[rtemp + 12 * BLACK_Estimated_Covar_tmp] = rtb_TSamp;
        }

        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_e += L_0[12 * i + rtemp] * L[12 * i +
              BLACK_Estimated_Covar_tmp];
          }

          i = 12 * BLACK_Estimated_Covar_tmp + rtemp;
          P_k[i] = b_Q_0[i] + rtb_TSamp_e;
        }

        H[6 * rtemp] = H_tmp[3 * rtemp];
        H[6 * rtemp + 1] = H_tmp[3 * rtemp + 1];
        H[6 * rtemp + 2] = H_tmp[3 * rtemp + 2];
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        H[6 * rtemp + 3] = 0.0;
        r2 = (rtemp + 3) * 6;
        H[r2 + 3] = R_chaser[3 * rtemp];
        H[6 * rtemp + 4] = 0.0;
        H[r2 + 4] = R_chaser[3 * rtemp + 1];
        H[6 * rtemp + 5] = 0.0;
        H[r2 + 5] = R_chaser[3 * rtemp + 2];
      }

      for (rtemp = 0; rtemp < 6; rtemp++) {
        r2 = (rtemp + 6) * 6;
        H[r2 + 3] = 0.0;
        H[r2 + 4] = 0.0;
        H[r2 + 5] = 0.0;
      }

      rtb_TSamp_e = (MPC_rand_pn() - 0.5) * 0.0;
      dt = sin(rtb_TSamp_e);
      Rot_error[0] = 1.0;
      Rot_error[3] = dt;
      Rot_error[6] = 0.0;
      Rot_error[1] = -dt;
      Rot_error[4] = 1.0;
      Rot_error[7] = 0.0;
      for (rtemp = 0; rtemp < 3; rtemp++) {
        Rot_error[3 * rtemp + 2] = rtb_y_fe[rtemp];
        rtb_TSamp = R_chaser[rtemp + 3];
        rtb_TSamp_e = R_chaser[rtemp];
        rtb_TSamp_jb = R_chaser[rtemp + 6];
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          R_chaser_0[rtemp + 3 * BLACK_Estimated_Covar_tmp] =
            (Rot_pred[BLACK_Estimated_Covar_tmp + 3] * rtb_TSamp + rtb_TSamp_e *
             Rot_pred[BLACK_Estimated_Covar_tmp]) +
            Rot_pred[BLACK_Estimated_Covar_tmp + 6] * rtb_TSamp_jb;
        }
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        dt = MPC_DW.Vis_R[3 * rtemp + 1];
        rtb_TSamp_lb = MPC_DW.Vis_R[3 * rtemp];
        rtb_TSamp = MPC_DW.Vis_R[3 * rtemp + 2];
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          F_tmp_0[rtemp + 3 * BLACK_Estimated_Covar_tmp] =
            (Rot_error[BLACK_Estimated_Covar_tmp + 3] * dt + rtb_TSamp_lb *
             Rot_error[BLACK_Estimated_Covar_tmp]) +
            Rot_error[BLACK_Estimated_Covar_tmp + 6] * rtb_TSamp;
        }
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_e = F_tmp_0[3 * rtemp + 1];
        rtb_TSamp_jb = F_tmp_0[3 * rtemp];
        rtb_y_eu = F_tmp_0[3 * rtemp + 2];
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          Rot_error[BLACK_Estimated_Covar_tmp + 3 * rtemp] =
            (R_chaser_0[BLACK_Estimated_Covar_tmp + 3] * rtb_TSamp_e +
             rtb_TSamp_jb * R_chaser_0[BLACK_Estimated_Covar_tmp]) +
            R_chaser_0[BLACK_Estimated_Covar_tmp + 6] * rtb_y_eu;
        }
      }

      rtb_y_eu = (((Rot_error[0] + Rot_error[4]) + Rot_error[8]) - 1.0) / 2.0;
      if (!(rtb_y_eu <= 1.0)) {
        rtb_y_eu = 1.0;
      }

      if (!(rtb_y_eu >= -1.0)) {
        rtb_y_eu = -1.0;
      }

      rtb_TSamp_e = acos(rtb_y_eu);
      if (fabs(rtb_TSamp_e) < 1.0E-8) {
        axis[0] = 0.0;
        axis[1] = 0.0;
        axis[2] = 0.0;
      } else {
        rtb_TSamp = 2.0 * sin(rtb_TSamp_e) * rtb_TSamp_e;
        rtb_TSamp_e = sin(Rot_error[5]);
        rtb_TSamp_jb = cos(Rot_error[5]);
        b_norm = sin(Rot_error[7]);
        rtb_y_eu = cos(Rot_error[7]);
        e_in[0] = (rtb_TSamp_e * 0.0 + rtb_TSamp_jb) - (b_norm * 0.0 + rtb_y_eu);
        e_in[1] = (rtb_TSamp_jb * 0.0 - rtb_TSamp_e) - (rtb_y_eu * 0.0 - b_norm);
        b_norm = sin(Rot_error[6]);
        rtb_y_eu = cos(Rot_error[6]);
        rtb_y_gs = sin(Rot_error[2]);
        e_in_tmp = cos(Rot_error[2]);
        b_y_tmp[0] = (b_norm * 0.0 + rtb_y_eu) - (rtb_y_gs * 0.0 + e_in_tmp);
        b_y_tmp[1] = (rtb_y_eu * 0.0 - b_norm) - (e_in_tmp * 0.0 - rtb_y_gs);
        rtb_y_gs = sin(Rot_error[1]);
        e_in_tmp = cos(Rot_error[1]);
        e_in_0 = sin(Rot_error[3]);
        H_tmp_0 = cos(Rot_error[3]);
        c_y_tmp[0] = (rtb_y_gs * 0.0 + e_in_tmp) - (e_in_0 * 0.0 + H_tmp_0);
        c_y_tmp[1] = (e_in_tmp * 0.0 - rtb_y_gs) - (H_tmp_0 * 0.0 - e_in_0);
        rtb_TSamp_e = (rtb_TSamp_jb * 0.0 + rtb_TSamp_e) * e_in[0] +
          (-rtb_TSamp_e * 0.0 + rtb_TSamp_jb) * e_in[1];
        b_norm = (rtb_y_eu * 0.0 + b_norm) * b_y_tmp[0] + (-b_norm * 0.0 +
          rtb_y_eu) * b_y_tmp[1];
        rtb_y_gs = (e_in_tmp * 0.0 + rtb_y_gs) * c_y_tmp[0] + (-rtb_y_gs * 0.0 +
          e_in_tmp) * c_y_tmp[1];
        if (rtIsNaN(rtb_TSamp_e)) {
          rtb_TSamp_e = (rtNaN);
        } else if (rtb_TSamp_e < 0.0) {
          rtb_TSamp_e = -1.0;
        } else {
          rtb_TSamp_e = (rtb_TSamp_e > 0.0);
        }

        axis[0] = -MPC_norm_ai(e_in) * rtb_TSamp_e * rtb_TSamp;
        if (rtIsNaN(b_norm)) {
          rtb_TSamp_e = (rtNaN);
        } else if (b_norm < 0.0) {
          rtb_TSamp_e = -1.0;
        } else {
          rtb_TSamp_e = (b_norm > 0.0);
        }

        axis[1] = -MPC_norm_ai(b_y_tmp) * rtb_TSamp_e * rtb_TSamp;
        if (rtIsNaN(rtb_y_gs)) {
          rtb_TSamp_e = (rtNaN);
        } else if (rtb_y_gs < 0.0) {
          rtb_TSamp_e = -1.0;
        } else {
          rtb_TSamp_e = (rtb_y_gs > 0.0);
        }

        axis[2] = -MPC_norm_ai(c_y_tmp) * rtb_TSamp_e * rtb_TSamp;
      }

      dt = x_est[0] - rtb_y_pc[0];
      rtb_TSamp_lb = x_est[1] - rtb_y_pc[1];
      rtb_TSamp_e = x_est[2];
      for (rtemp = 0; rtemp < 3; rtemp++) {
        MPC_DW.STRMEKFerror[rtemp] = axis[rtemp];
        MPC_DW.STRMEKFerror[rtemp + 3] = MPC_DW.Vis_x[rtemp] - ((R_chaser[rtemp
          + 3] * rtb_TSamp_lb + R_chaser[rtemp] * dt) + R_chaser[rtemp + 6] *
          rtb_TSamp_e);
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += H[(6 * i + rtemp) + 3] * P_k[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          BLACK_Estimated_Covar_0[rtemp + 3 * BLACK_Estimated_Covar_tmp] =
            rtb_TSamp;
        }

        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += H[(6 * i + BLACK_Estimated_Covar_tmp) + 3] *
              BLACK_Estimated_Covar_0[3 * i + rtemp];
          }

          Rot_error[rtemp + 3 * BLACK_Estimated_Covar_tmp] = rtb_TSamp;
        }
      }

      rtb_TSamp_e = 0.0;
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_e += ((Rot_error[3 * rtemp + 1] * MPC_DW.STRMEKFerror[4] +
                         Rot_error[3 * rtemp] * MPC_DW.STRMEKFerror[3]) +
                        Rot_error[3 * rtemp + 2] * MPC_DW.STRMEKFerror[5]) *
          MPC_DW.STRMEKFerror[rtemp + 3];
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += H[6 * i + rtemp] * P_k[12 * BLACK_Estimated_Covar_tmp +
              i];
          }

          BLACK_Estimated_Covar_0[rtemp + 3 * BLACK_Estimated_Covar_tmp] =
            rtb_TSamp;
        }

        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += BLACK_Estimated_Covar_0[3 * i + rtemp] * H[6 * i +
              BLACK_Estimated_Covar_tmp];
          }

          Rot_error[rtemp + 3 * BLACK_Estimated_Covar_tmp] = rtb_TSamp;
        }
      }

      rtb_TSamp_jb = 0.0;
      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_jb += ((Rot_error[3 * rtemp + 1] * MPC_DW.STRMEKFerror[1] +
                          Rot_error[3 * rtemp] * MPC_DW.STRMEKFerror[0]) +
                         Rot_error[3 * rtemp + 2] * MPC_DW.STRMEKFerror[2]) *
          MPC_DW.STRMEKFerror[rtemp];
      }

      if (!(sqrt(rtb_TSamp_jb) < 1604.6000000000001)) {
        MPC_DW.STRMEKFerror[0] = 0.0;
        MPC_DW.STRMEKFerror[1] = 0.0;
        MPC_DW.STRMEKFerror[2] = 0.0;
        for (rtemp = 0; rtemp < 12; rtemp++) {
          H[6 * rtemp] = 0.0;
          H[6 * rtemp + 1] = 0.0;
          H[6 * rtemp + 2] = 0.0;
        }
      }

      if (!(sqrt(rtb_TSamp_e) < 5586.5999999999995)) {
        MPC_DW.STRMEKFerror[3] = 0.0;
        MPC_DW.STRMEKFerror[4] = 0.0;
        MPC_DW.STRMEKFerror[5] = 0.0;
        for (rtemp = 0; rtemp < 12; rtemp++) {
          H[6 * rtemp + 3] = 0.0;
          H[6 * rtemp + 4] = 0.0;
          H[6 * rtemp + 5] = 0.0;
        }
      }

      memcpy(&BLACK_Estimated_Covar_1[0], &MPC_DW.Delay3_DSTATE[0], 36U * sizeof
             (real_T));
      MPC_xgetrf(BLACK_Estimated_Covar_1, ipiv, &rtemp);
      rtb_TSamp_lb = BLACK_Estimated_Covar_1[0];
      rEQ0 = false;
      for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 5;
           BLACK_Estimated_Covar_tmp++) {
        rtb_TSamp_lb *= BLACK_Estimated_Covar_1[((BLACK_Estimated_Covar_tmp + 1)
          * 6 + BLACK_Estimated_Covar_tmp) + 1];
        if (ipiv[BLACK_Estimated_Covar_tmp] > BLACK_Estimated_Covar_tmp + 1) {
          rEQ0 = !rEQ0;
        }
      }

      if (rEQ0) {
        rtb_TSamp_lb = -rtb_TSamp_lb;
      }

      if (rtb_TSamp_lb == 0.0) {
        for (rtemp = 0; rtemp < 6; rtemp++) {
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
               BLACK_Estimated_Covar_tmp++) {
            MPC_DW.Delay3_DSTATE[BLACK_Estimated_Covar_tmp + 6 * rtemp] =
              MPC_DW.STRMEKFerror[BLACK_Estimated_Covar_tmp] *
              MPC_DW.STRMEKFerror[rtemp];
          }
        }
      }

      for (rtemp = 0; rtemp < 6; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          i = 6 * rtemp + BLACK_Estimated_Covar_tmp;
          MPC_DW.Delay3_DSTATE[i] = (MPC_DW.Delay3_DSTATE[i] * 0.98 +
            MPC_DW.STRMEKFerror[BLACK_Estimated_Covar_tmp] *
            MPC_DW.STRMEKFerror[rtemp]) / 1.98;
        }
      }

      MPC_lsqnonlin_e(P_k, H, MPC_DW.Delay3_DSTATE, rtb_y_pc);
      memset(&R_chaser[0], 0, 9U * sizeof(real_T));
      R_chaser[0] = rtb_y_pc[0];
      R_chaser[4] = rtb_y_pc[1];
      R_chaser[8] = rtb_y_pc[2];
      memset(&Rot_error[0], 0, 9U * sizeof(real_T));
      Rot_error[0] = rtb_y_pc[3];
      Rot_error[4] = rtb_y_pc[4];
      Rot_error[8] = rtb_y_pc[5];
      memset(&R_chaser_0[0], 0, 9U * sizeof(real_T));
      R_chaser_0[0] = rtb_y_pc[3];
      R_chaser_0[4] = rtb_y_pc[4];
      R_chaser_0[8] = rtb_y_pc[5];
      memset(&varargin_4[0], 0, 9U * sizeof(real_T));
      varargin_4[0] = rtb_y_pc[0];
      varargin_4[4] = rtb_y_pc[1];
      varargin_4[8] = rtb_y_pc[2];
      memset(&L[0], 0, 144U * sizeof(real_T));
      for (rtemp = 0; rtemp < 3; rtemp++) {
        L[12 * rtemp] = R_chaser[3 * rtemp];
        i = (rtemp + 3) * 12;
        L[i + 3] = Rot_error[3 * rtemp];
        BLACK_Estimated_Covar_tmp = (rtemp + 6) * 12;
        L[BLACK_Estimated_Covar_tmp + 6] = R_chaser_0[3 * rtemp];
        r3 = (rtemp + 9) * 12;
        L[r3 + 9] = varargin_4[3 * rtemp];
        r2 = 3 * rtemp + 1;
        L[12 * rtemp + 1] = R_chaser[r2];
        L[i + 4] = Rot_error[r2];
        L[BLACK_Estimated_Covar_tmp + 7] = R_chaser_0[r2];
        L[r3 + 10] = varargin_4[r2];
        r2 = 3 * rtemp + 2;
        L[12 * rtemp + 2] = R_chaser[r2];
        L[i + 5] = Rot_error[r2];
        L[BLACK_Estimated_Covar_tmp + 8] = R_chaser_0[r2];
        L[r3 + 11] = varargin_4[r2];
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += L[12 * i + BLACK_Estimated_Covar_tmp] * P_k[12 * rtemp
              + i];
          }

          L_0[BLACK_Estimated_Covar_tmp + 12 * rtemp] = rtb_TSamp;
        }
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += L_0[12 * i + BLACK_Estimated_Covar_tmp] * L[12 * rtemp
              + i];
          }

          P_k[BLACK_Estimated_Covar_tmp + 12 * rtemp] = rtb_TSamp;
        }
      }

      for (rtemp = 0; rtemp < 36; rtemp++) {
        MPC_DW.Delay3_DSTATE[rtemp] *= 0.98;
      }

      for (rtemp = 0; rtemp < 6; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          K_tmp[BLACK_Estimated_Covar_tmp + 12 * rtemp] = H[6 *
            BLACK_Estimated_Covar_tmp + rtemp];
        }
      }

      for (rtemp = 0; rtemp < 6; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_e = 0.0;
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_e += P_k[12 * i + BLACK_Estimated_Covar_tmp] * K_tmp[12 *
              rtemp + i];
            rtb_TSamp += H[6 * i + rtemp] * P_k[12 * BLACK_Estimated_Covar_tmp +
              i];
          }

          K_0[BLACK_Estimated_Covar_tmp + 12 * rtemp] = rtb_TSamp_e;
          H_0[rtemp + 6 * BLACK_Estimated_Covar_tmp] = rtb_TSamp;
        }

        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp_e += H_0[6 * i + rtemp] * K_tmp[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          r2 = 6 * BLACK_Estimated_Covar_tmp + rtemp;
          BLACK_Estimated_Covar_1[r2] = b_R_0[r2] + rtb_TSamp_e;
        }
      }

      MPC_xgetrf(BLACK_Estimated_Covar_1, ipiv, &rtemp);
      for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
           BLACK_Estimated_Covar_tmp++) {
        jBcol = 12 * BLACK_Estimated_Covar_tmp;
        r3 = 6 * BLACK_Estimated_Covar_tmp;
        for (i = 0; i < BLACK_Estimated_Covar_tmp; i++) {
          kBcol = 12 * i;
          rtb_TSamp_e = BLACK_Estimated_Covar_1[i + r3];
          if (rtb_TSamp_e != 0.0) {
            for (r2 = 0; r2 < 12; r2++) {
              rtemp = r2 + jBcol;
              K_0[rtemp] -= K_0[r2 + kBcol] * rtb_TSamp_e;
            }
          }
        }

        rtb_TSamp = 1.0 / BLACK_Estimated_Covar_1[BLACK_Estimated_Covar_tmp + r3];
        for (r2 = 0; r2 < 12; r2++) {
          rtemp = r2 + jBcol;
          K_0[rtemp] *= rtb_TSamp;
        }
      }

      for (r2 = 5; r2 >= 0; r2--) {
        jBcol = 12 * r2;
        r3 = 6 * r2 - 1;
        for (i = r2 + 2; i < 7; i++) {
          kBcol = (i - 1) * 12;
          rtb_TSamp_e = BLACK_Estimated_Covar_1[i + r3];
          if (rtb_TSamp_e != 0.0) {
            for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
                 BLACK_Estimated_Covar_tmp++) {
              rtemp = BLACK_Estimated_Covar_tmp + jBcol;
              K_0[rtemp] -= K_0[BLACK_Estimated_Covar_tmp + kBcol] * rtb_TSamp_e;
            }
          }
        }
      }

      for (BLACK_Estimated_Covar_tmp = 4; BLACK_Estimated_Covar_tmp >= 0;
           BLACK_Estimated_Covar_tmp--) {
        r2 = ipiv[BLACK_Estimated_Covar_tmp];
        if (BLACK_Estimated_Covar_tmp + 1 != r2) {
          for (i = 0; i < 12; i++) {
            r3 = 12 * BLACK_Estimated_Covar_tmp + i;
            rtb_TSamp = K_0[r3];
            rtemp = (r2 - 1) * 12 + i;
            K_0[r3] = K_0[rtemp];
            K_0[rtemp] = rtb_TSamp;
          }
        }
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp += K_0[12 * i + BLACK_Estimated_Covar_tmp] * H[6 * rtemp +
              i];
          }

          L[BLACK_Estimated_Covar_tmp + 12 * rtemp] = rtb_TSamp;
        }
      }

      for (rtemp = 0; rtemp < 144; rtemp++) {
        L_0[rtemp] = static_cast<real_T>(QMEKFP_tmp_2[rtemp]) - L[rtemp];
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += L_0[12 * i + rtemp] * P_k[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          r2 = 12 * BLACK_Estimated_Covar_tmp + rtemp;
          QMEKFP_tmp_0[r2] = rtb_TSamp;
          i = 12 * rtemp + BLACK_Estimated_Covar_tmp;
          QMEKFP_tmp_1[i] = static_cast<real_T>(QMEKFP_tmp[i]) - L[r2];
        }

        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp_e += K_0[12 * i + rtemp] * b_R_0[6 *
              BLACK_Estimated_Covar_tmp + i];
          }

          H_0[rtemp + 12 * BLACK_Estimated_Covar_tmp] = rtb_TSamp_e;
        }
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp = 0.0;
          for (i = 0; i < 12; i++) {
            rtb_TSamp += QMEKFP_tmp_0[12 * i + rtemp] * QMEKFP_tmp_1[12 *
              BLACK_Estimated_Covar_tmp + i];
          }

          r2 = 12 * BLACK_Estimated_Covar_tmp + rtemp;
          L_0[r2] = rtb_TSamp;
          rtb_TSamp_e = 0.0;
          for (i = 0; i < 6; i++) {
            rtb_TSamp_e += H_0[12 * i + rtemp] * K_0[12 * i +
              BLACK_Estimated_Covar_tmp];
          }

          L[r2] = rtb_TSamp_e;
        }
      }

      for (rtemp = 0; rtemp < 144; rtemp++) {
        MPC_DW.STRMEKFP[rtemp] = L_0[rtemp] + L[rtemp];
      }

      for (rtemp = 0; rtemp < 12; rtemp++) {
        rtb_TSamp = 0.0;
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp += K_0[12 * BLACK_Estimated_Covar_tmp + rtemp] *
            MPC_DW.STRMEKFerror[BLACK_Estimated_Covar_tmp];
        }

        delta_x[rtemp] = rtb_TSamp;
      }

      rtb_TSamp = 3.3121686421112381E-170;
      rtb_TSamp_e = fabs(delta_x[0]);
      if (rtb_TSamp_e > 3.3121686421112381E-170) {
        b_norm = 1.0;
        rtb_TSamp = rtb_TSamp_e;
      } else {
        rtb_TSamp_jb = rtb_TSamp_e / 3.3121686421112381E-170;
        b_norm = rtb_TSamp_jb * rtb_TSamp_jb;
      }

      rtb_TSamp_e = fabs(delta_x[1]);
      if (rtb_TSamp_e > rtb_TSamp) {
        rtb_TSamp_jb = rtb_TSamp / rtb_TSamp_e;
        b_norm = b_norm * rtb_TSamp_jb * rtb_TSamp_jb + 1.0;
        rtb_TSamp = rtb_TSamp_e;
      } else {
        rtb_TSamp_jb = rtb_TSamp_e / rtb_TSamp;
        b_norm += rtb_TSamp_jb * rtb_TSamp_jb;
      }

      rtb_TSamp_e = fabs(delta_x[2]);
      if (rtb_TSamp_e > rtb_TSamp) {
        rtb_TSamp_jb = rtb_TSamp / rtb_TSamp_e;
        b_norm = b_norm * rtb_TSamp_jb * rtb_TSamp_jb + 1.0;
        rtb_TSamp = rtb_TSamp_e;
      } else {
        rtb_TSamp_jb = rtb_TSamp_e / rtb_TSamp;
        b_norm += rtb_TSamp_jb * rtb_TSamp_jb;
      }

      b_norm = rtb_TSamp * sqrt(b_norm);
      if (b_norm > 1.0E-8) {
        axis[0] = delta_x[0] / b_norm;
        axis[1] = delta_x[1] / b_norm;
        axis[2] = delta_x[2] / b_norm;
      } else {
        axis[0] = 0.0;
        axis[1] = 0.0;
        axis[2] = 0.0;
      }

      rtb_TSamp = sin(b_norm);
      dt = cos(b_norm);
      R_chaser[0] = 0.0;
      R_chaser[3] = -axis[2];
      R_chaser[6] = axis[1];
      R_chaser[1] = axis[2];
      R_chaser[4] = 0.0;
      R_chaser[7] = -axis[0];
      R_chaser[2] = -axis[1];
      R_chaser[5] = axis[0];
      R_chaser[8] = 0.0;
      memset(&Rot_error[0], 0, 9U * sizeof(real_T));
      for (r2 = 0; r2 < 3; r2++) {
        Rot_error[r2 + 3 * r2] = 1.0;
        for (rtemp = 0; rtemp < 3; rtemp++) {
          R_chaser_0[r2 + 3 * rtemp] = (R_chaser[3 * rtemp + 1] * R_chaser[r2 +
            3] + R_chaser[3 * rtemp] * R_chaser[r2]) + R_chaser[3 * rtemp + 2] *
            R_chaser[r2 + 6];
        }
      }

      R_chaser[0] = rtb_TSamp * 0.0 + Rot_error[0];
      R_chaser[1] = rtb_TSamp * axis[2] + Rot_error[1];
      R_chaser[2] = rtb_TSamp * -axis[1] + Rot_error[2];
      R_chaser[3] = rtb_TSamp * -axis[2] + Rot_error[3];
      R_chaser[4] = rtb_TSamp * 0.0 + Rot_error[4];
      R_chaser[5] = rtb_TSamp * axis[0] + Rot_error[5];
      R_chaser[6] = rtb_TSamp * axis[1] + Rot_error[6];
      R_chaser[7] = rtb_TSamp * -axis[0] + Rot_error[7];
      R_chaser[8] = rtb_TSamp * 0.0 + Rot_error[8];
      for (rtemp = 0; rtemp < 9; rtemp++) {
        Rot_error[rtemp] = (1.0 - dt) * R_chaser_0[rtemp] + R_chaser[rtemp];
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp = Rot_pred[3 * rtemp + 1];
        rtb_TSamp_e = Rot_pred[3 * rtemp];
        rtb_TSamp_jb = Rot_pred[3 * rtemp + 2];
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          MPC_DW.STRMEKFR[BLACK_Estimated_Covar_tmp + 3 * rtemp] =
            (Rot_error[BLACK_Estimated_Covar_tmp + 3] * rtb_TSamp + rtb_TSamp_e *
             Rot_error[BLACK_Estimated_Covar_tmp]) +
            Rot_error[BLACK_Estimated_Covar_tmp + 6] * rtb_TSamp_jb;
        }
      }

      for (rtemp = 0; rtemp < 9; rtemp++) {
        x_est[rtemp] += delta_x[rtemp + 3];
      }

      MPC_DW.STRMEKFt = MPC_toc_a(&savedTime_aw);
      for (i = 0; i < 6; i++) {
        rtb_y_pc[i] = MPC_DW.STRMEKFerror[i];
        for (rtemp = 0; rtemp < 12; rtemp++) {
          rtb_TSamp = 0.0;
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
               BLACK_Estimated_Covar_tmp++) {
            rtb_TSamp += H[6 * BLACK_Estimated_Covar_tmp + i] * MPC_DW.STRMEKFP
              [12 * rtemp + BLACK_Estimated_Covar_tmp];
          }

          H_0[i + 6 * rtemp] = rtb_TSamp;
        }

        for (rtemp = 0; rtemp < 6; rtemp++) {
          rtb_TSamp_e = 0.0;
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 12;
               BLACK_Estimated_Covar_tmp++) {
            rtb_TSamp_e += H_0[6 * BLACK_Estimated_Covar_tmp + i] * K_tmp[12 *
              rtemp + BLACK_Estimated_Covar_tmp];
          }

          r2 = 6 * rtemp + i;
          BLACK_Estimated_Covar_1[r2] = b_R_0[r2] + rtb_TSamp_e;
        }
      }

      MPC_xgetrf(BLACK_Estimated_Covar_1, ipiv, &rtemp);
      for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 6;
           BLACK_Estimated_Covar_tmp++) {
        i = 6 * BLACK_Estimated_Covar_tmp;
        for (rtemp = 0; rtemp < BLACK_Estimated_Covar_tmp; rtemp++) {
          rtb_TSamp_e = BLACK_Estimated_Covar_1[rtemp + i];
          if (rtb_TSamp_e != 0.0) {
            rtb_y_pc[BLACK_Estimated_Covar_tmp] -= rtb_TSamp_e * rtb_y_pc[rtemp];
          }
        }

        rtb_y_pc[BLACK_Estimated_Covar_tmp] *= 1.0 /
          BLACK_Estimated_Covar_1[BLACK_Estimated_Covar_tmp + i];
      }

      for (rtemp = 5; rtemp >= 0; rtemp--) {
        i = 6 * rtemp - 1;
        for (BLACK_Estimated_Covar_tmp = rtemp + 2; BLACK_Estimated_Covar_tmp <
             7; BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_e = BLACK_Estimated_Covar_1[BLACK_Estimated_Covar_tmp + i];
          if (rtb_TSamp_e != 0.0) {
            rtb_y_pc[rtemp] -= rtb_y_pc[BLACK_Estimated_Covar_tmp - 1] *
              rtb_TSamp_e;
          }
        }
      }

      for (rtemp = 4; rtemp >= 0; rtemp--) {
        r2 = ipiv[rtemp];
        if (rtemp + 1 != r2) {
          rtb_TSamp = rtb_y_pc[rtemp];
          rtb_y_pc[rtemp] = rtb_y_pc[r2 - 1];
          rtb_y_pc[r2 - 1] = rtb_TSamp;
        }
      }

      MPC_DW.STRMEKFNIS = 0.0;
      for (rtemp = 0; rtemp < 6; rtemp++) {
        MPC_DW.STRMEKFNIS += rtb_y_pc[rtemp] * MPC_DW.STRMEKFerror[rtemp];
      }

      // MATLAB Function: '<S102>/MATLAB Function11'
      MPC_MATLABFunction11_l(MPC_DW.STRMEKFR, &rtb_y_p[0]);

      // MATLAB Function: '<S102>/MATLAB Function'
      MPC_MATLABFunction_gs(x_est, &rtb_y_p[0], rtb_out);

      // DataStoreWrite: '<S102>/Data Store Write17'
      memcpy(&MPC_DW.STRMEKFx[0], &rtb_out[0], 13U * sizeof(real_T));

      // Update for Delay: '<S97>/Delay' incorporates:
      //   DataStoreWrite: '<S97>/Data Store Write18'

      memcpy(&MPC_DW.Delay_DSTATE_g[0], &MPC_DW.QMEKFP[0], 144U * sizeof(real_T));

      // Update for Delay: '<S98>/Delay1'
      memcpy(&MPC_DW.Delay1_DSTATE_ml[0], &m[0], 9U * sizeof(real_T));

      // Update for Delay: '<S98>/Delay2'
      memcpy(&MPC_DW.Delay2_DSTATE_j2[0], &MPC_DW.RMEKFR[0], 9U * sizeof(real_T));

      // Update for Delay: '<S98>/Delay' incorporates:
      //   DataStoreWrite: '<S98>/Data Store Write18'

      memcpy(&MPC_DW.Delay_DSTATE_p[0], &MPC_DW.RMEKFP[0], 144U * sizeof(real_T));

      // Update for Delay: '<S101>/Delay' incorporates:
      //   DataStoreWrite: '<S101>/Data Store Write18'

      memcpy(&MPC_DW.Delay_DSTATE_a[0], &MPC_DW.STQMEKFP[0], 144U * sizeof
             (real_T));

      // Update for Delay: '<S102>/Delay1'
      memcpy(&MPC_DW.Delay1_DSTATE_n[0], &x_est[0], 9U * sizeof(real_T));

      // Update for Delay: '<S102>/Delay4'
      memcpy(&MPC_DW.Delay4_DSTATE[0], &MPC_DW.STRMEKFR[0], 9U * sizeof(real_T));

      // Update for Delay: '<S102>/Delay2' incorporates:
      //   DataStoreWrite: '<S102>/Data Store Write18'

      memcpy(&MPC_DW.Delay2_DSTATE_kf[0], &MPC_DW.STRMEKFP[0], 144U * sizeof
             (real_T));

      // End of Outputs for SubSystem: '<S3>/Subsystem'
    }

    // If: '<S5>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
    //   DataStoreRead: '<S5>/Data Store Read'
    //   DataStoreRead: '<S5>/Data Store Read1'

    if ((MPC_DW.WhoAmI == 2.0) && (MPC_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S5>/Change BLACK Behavior' incorporates:
      //   ActionPort: '<S176>/Action Port'

      MPC_ChangeBLACKBehavior(MPC_M, &MPC_DW.ChangeBLACKBehavior,
        &MPC_P.ChangeBLACKBehavior);

      // End of Outputs for SubSystem: '<S5>/Change BLACK Behavior'
    }

    // End of If: '<S5>/This IF block determines whether or not to run the BLACK sim//exp' 

    // If: '<S5>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
    //   DataStoreRead: '<S5>/Data Store Read'
    //   DataStoreRead: '<S5>/Data Store Read1'

    if ((MPC_DW.WhoAmI == 3.0) && (MPC_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S5>/Change BLUE Behavior' incorporates:
      //   ActionPort: '<S177>/Action Port'

      MPC_ChangeBLACKBehavior(MPC_M, &MPC_DW.ChangeBLUEBehavior,
        &MPC_P.ChangeBLUEBehavior);

      // End of Outputs for SubSystem: '<S5>/Change BLUE Behavior'
    }

    // End of If: '<S5>/This IF block determines whether or not to run the BLUE sim//exp' 

    // If: '<S5>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   DataStoreRead: '<S5>/Data Store Read'
    //   DataStoreRead: '<S5>/Data Store Read1'

    if ((MPC_DW.WhoAmI == 1.0) && (MPC_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S5>/Change RED Behavior' incorporates:
      //   ActionPort: '<S178>/Action Port'

      MPC_ChangeBLACKBehavior(MPC_M, &MPC_DW.ChangeREDBehavior,
        &MPC_P.ChangeREDBehavior);

      // End of Outputs for SubSystem: '<S5>/Change RED Behavior'
    }

    // End of If: '<S5>/This IF block determines whether or not to run the RED sim//exp ' 

    // MATLAB Function: '<S196>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read47'

    MPC_MATLABFunction_j(MPC_DW.QMEKFerror, rtb_y_p);

    // MATLAB Function: '<S195>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read48'

    MPC_MATLABFunction_f(MPC_DW.QMEKFNIS, &dt);

    // MATLAB Function: '<S181>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read49'

    MPC_MATLABFunction_j(MPC_DW.STQMEKFerror, rtb_y_pc);

    // MATLAB Function: '<S188>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read50'

    MPC_MATLABFunction_f(MPC_DW.STQMEKFNIS, &rtb_TSamp_lb);

    // MATLAB Function: '<S194>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read51'

    MPC_MATLABFunction_j(MPC_DW.DQMEKFerror, Chaser);

    // MATLAB Function: '<S190>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read52'

    MPC_MATLABFunction_f(MPC_DW.DQMEKFNIS, &rtb_TSamp);

    // MATLAB Function: '<S189>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read55'

    MPC_MATLABFunction_j(MPC_DW.STDQMEKFerror, rtb_y_fj);

    // MATLAB Function: '<S180>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read56'

    MPC_MATLABFunction_f(MPC_DW.STDQMEKFNIS, &rtb_TSamp_e);

    // MATLAB Function: '<S193>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read64'

    MPC_MATLABFunction_j(MPC_DW.RMEKFerror, rtb_y_d);

    // MATLAB Function: '<S182>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read21'

    MPC_MATLABFunction_f(MPC_DW.RMEKFNIS, &rtb_TSamp_jb);

    // MATLAB Function: '<S192>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read59'

    MPC_MATLABFunction_j(MPC_DW.STRMEKFerror, rtb_y_mu);

    // MATLAB Function: '<S191>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read60'

    MPC_MATLABFunction_f(MPC_DW.STRMEKFNIS, &b_norm);

    // MATLAB Function: '<S187>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read29'

    rEQ0 = rtIsNaN(MPC_DW.Vis_q[0]);
    if (!rEQ0) {
      rEQ0 = rtIsNaN(MPC_DW.Vis_q[1]);
    }

    if (!rEQ0) {
      rEQ0 = rtIsNaN(MPC_DW.Vis_q[2]);
    }

    if (!rEQ0) {
      rEQ0 = rtIsNaN(MPC_DW.Vis_q[3]);
    }

    // MATLAB Function: '<S186>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read30'

    MPC_MATLABFunction_c(MPC_DW.Vis_x, rtb_y_fe);

    // MATLAB Function: '<S185>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read33'

    MPC_MATLABFunction_f(MPC_DW.Conf, &rtb_y_eu);

    // MATLAB Function: '<S184>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read34'

    MPC_MATLABFunction_f(MPC_DW.Conf_zoh, &rtb_y_gs);

    // MATLAB Function: '<S183>/MATLAB Function' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read41'

    MPC_MATLABFunction_c(MPC_DW.CNNError, Red_x);

    // MATLABSystem: '<S179>/MATLAB System' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read'
    //   DataStoreRead: '<S6>/Data Store Read1'
    //   DataStoreRead: '<S6>/Data Store Read10'
    //   DataStoreRead: '<S6>/Data Store Read11'
    //   DataStoreRead: '<S6>/Data Store Read12'
    //   DataStoreRead: '<S6>/Data Store Read13'
    //   DataStoreRead: '<S6>/Data Store Read133'
    //   DataStoreRead: '<S6>/Data Store Read14'
    //   DataStoreRead: '<S6>/Data Store Read15'
    //   DataStoreRead: '<S6>/Data Store Read16'
    //   DataStoreRead: '<S6>/Data Store Read17'
    //   DataStoreRead: '<S6>/Data Store Read18'
    //   DataStoreRead: '<S6>/Data Store Read19'
    //   DataStoreRead: '<S6>/Data Store Read20'
    //   DataStoreRead: '<S6>/Data Store Read22'
    //   DataStoreRead: '<S6>/Data Store Read23'
    //   DataStoreRead: '<S6>/Data Store Read24'
    //   DataStoreRead: '<S6>/Data Store Read25'
    //   DataStoreRead: '<S6>/Data Store Read26'
    //   DataStoreRead: '<S6>/Data Store Read27'
    //   DataStoreRead: '<S6>/Data Store Read28'
    //   DataStoreRead: '<S6>/Data Store Read3'
    //   DataStoreRead: '<S6>/Data Store Read35'
    //   DataStoreRead: '<S6>/Data Store Read36'
    //   DataStoreRead: '<S6>/Data Store Read37'
    //   DataStoreRead: '<S6>/Data Store Read38'
    //   DataStoreRead: '<S6>/Data Store Read39'
    //   DataStoreRead: '<S6>/Data Store Read4'
    //   DataStoreRead: '<S6>/Data Store Read40'
    //   DataStoreRead: '<S6>/Data Store Read42'
    //   DataStoreRead: '<S6>/Data Store Read43'
    //   DataStoreRead: '<S6>/Data Store Read44'
    //   DataStoreRead: '<S6>/Data Store Read45'
    //   DataStoreRead: '<S6>/Data Store Read46'
    //   DataStoreRead: '<S6>/Data Store Read5'
    //   DataStoreRead: '<S6>/Data Store Read53'
    //   DataStoreRead: '<S6>/Data Store Read54'
    //   DataStoreRead: '<S6>/Data Store Read57'
    //   DataStoreRead: '<S6>/Data Store Read58'
    //   DataStoreRead: '<S6>/Data Store Read6'
    //   DataStoreRead: '<S6>/Data Store Read61'
    //   DataStoreRead: '<S6>/Data Store Read62'
    //   DataStoreRead: '<S6>/Data Store Read63'
    //   DataStoreRead: '<S6>/Data Store Read65'
    //   DataStoreRead: '<S6>/Data Store Read66'
    //   DataStoreRead: '<S6>/Data Store Read67'
    //   DataStoreRead: '<S6>/Data Store Read68'
    //   DataStoreRead: '<S6>/Data Store Read69'
    //   DataStoreRead: '<S6>/Data Store Read7'
    //   DataStoreRead: '<S6>/Data Store Read71'
    //   DataStoreRead: '<S6>/Data Store Read72'
    //   DataStoreRead: '<S6>/Data Store Read73'
    //   DataStoreRead: '<S6>/Data Store Read74'
    //   DataStoreRead: '<S6>/Data Store Read75'
    //   DataStoreRead: '<S6>/Data Store Read76'
    //   DataStoreRead: '<S6>/Data Store Read77'
    //   DataStoreRead: '<S6>/Data Store Read78'
    //   DataStoreRead: '<S6>/Data Store Read79'
    //   DataStoreRead: '<S6>/Data Store Read8'
    //   DataStoreRead: '<S6>/Data Store Read80'
    //   DataStoreRead: '<S6>/Data Store Read81'
    //   DataStoreRead: '<S6>/Data Store Read87'
    //   DataStoreRead: '<S6>/Data Store Read9'
    //   DataStoreRead: '<S6>/Data Store Read91'
    //   SignalConversion generated from: '<S179>/MATLAB System'

    //         %% Define input properties
    //  Call C-function implementing device output
    MPC_B.b_u1[0] = MPC_DW.Univ_Time;
    MPC_B.b_u1[1] = RED_Controls[0];
    MPC_B.b_u1[4] = MPC_DW.RED_Saturated_Controls[0];
    MPC_B.b_u1[2] = RED_Controls[1];
    MPC_B.b_u1[5] = MPC_DW.RED_Saturated_Controls[1];
    MPC_B.b_u1[3] = RED_Controls[2];
    MPC_B.b_u1[6] = MPC_DW.RED_Saturated_Controls[2];
    memcpy(&MPC_B.b_u1[7], &MPC_DW.RED_Measured_States_RAW[0], 9U * sizeof
           (real_T));
    MPC_B.b_u1[22] = MPC_DW.RED_Thruster_ON_Count;
    MPC_B.b_u1[23] = MPC_DW.RED_Control_Law_Enabler;
    MPC_B.b_u1[27] = MPC_DW.ARM_Control_Mode;
    MPC_B.b_u1[16] = MPC_DW.RED_Desired_States[0];
    MPC_B.b_u1[19] = MPC_DW.RED_IMU_Measurements[0];
    MPC_B.b_u1[24] = RED_Path[0];
    MPC_B.b_u1[28] = ARM_Controls[0];
    MPC_B.b_u1[17] = MPC_DW.RED_Desired_States[1];
    MPC_B.b_u1[20] = MPC_DW.RED_IMU_Measurements[1];
    MPC_B.b_u1[25] = RED_Path[1];
    MPC_B.b_u1[29] = ARM_Controls[1];
    MPC_B.b_u1[18] = MPC_DW.RED_Desired_States[2];
    MPC_B.b_u1[21] = MPC_DW.RED_IMU_Measurements[2];
    MPC_B.b_u1[26] = RED_Path[2];
    MPC_B.b_u1[30] = ARM_Controls[2];
    for (rtemp = 0; rtemp < 6; rtemp++) {
      MPC_B.b_u1[rtemp + 31] = MPC_DW.ARM_Measured_States[rtemp];
    }

    MPC_B.b_u1[37] = ARM_Path_idx_0;
    MPC_B.b_u1[40] = MPC_DW.ARM_Desired_States[0];
    MPC_B.b_u1[43] = BLACK_Controls[0];
    MPC_B.b_u1[46] = MPC_DW.BLACK_Saturated_Controls[0];
    MPC_B.b_u1[38] = ARM_Path_idx_1;
    MPC_B.b_u1[41] = MPC_DW.ARM_Desired_States[1];
    MPC_B.b_u1[44] = BLACK_Controls[1];
    MPC_B.b_u1[47] = MPC_DW.BLACK_Saturated_Controls[1];
    MPC_B.b_u1[39] = ARM_Path_idx_2;
    MPC_B.b_u1[42] = MPC_DW.ARM_Desired_States[2];
    MPC_B.b_u1[45] = BLACK_Controls[2];
    MPC_B.b_u1[48] = MPC_DW.BLACK_Saturated_Controls[2];
    MPC_B.b_u1[64] = MPC_DW.BLACK_Thruster_ON_Count;
    MPC_B.b_u1[65] = MPC_DW.BLACK_Control_Law_Enabler;
    MPC_B.b_u1[58] = MPC_DW.BLACK_Desired_States[0];
    MPC_B.b_u1[61] = MPC_DW.BLACK_IMU_Measurements[0];
    MPC_B.b_u1[66] = BLACK_Path[0];
    MPC_B.b_u1[69] = rtb_TSamp_o;
    MPC_B.b_u1[72] = MPC_DW.BLUE_Saturated_Controls[0];
    MPC_B.b_u1[59] = MPC_DW.BLACK_Desired_States[1];
    MPC_B.b_u1[62] = MPC_DW.BLACK_IMU_Measurements[1];
    MPC_B.b_u1[67] = BLACK_Path[1];
    MPC_B.b_u1[70] = rtb_TSamp_h;
    MPC_B.b_u1[73] = MPC_DW.BLUE_Saturated_Controls[1];
    MPC_B.b_u1[60] = MPC_DW.BLACK_Desired_States[2];
    MPC_B.b_u1[63] = MPC_DW.BLACK_IMU_Measurements[2];
    MPC_B.b_u1[68] = BLACK_Path[2];
    MPC_B.b_u1[71] = rtb_TSamp_ne;
    MPC_B.b_u1[74] = MPC_DW.BLUE_Saturated_Controls[2];
    for (rtemp = 0; rtemp < 9; rtemp++) {
      MPC_B.b_u1[rtemp + 49] = MPC_DW.BLACK_Measured_States_RAW[rtemp];
      MPC_B.b_u1[rtemp + 75] = MPC_DW.BLUE_Measured_States_RAW[rtemp];
    }

    MPC_B.b_u1[90] = MPC_DW.BLUE_Thruster_ON_Count;
    MPC_B.b_u1[91] = MPC_DW.BLUE_Control_Law_Enabler;
    MPC_B.b_u1[84] = MPC_DW.BLUE_Desired_States[0];
    MPC_B.b_u1[87] = MPC_DW.BLUE_IMU_Measurements[0];
    MPC_B.b_u1[92] = BLUE_Path_idx_0;
    MPC_B.b_u1[85] = MPC_DW.BLUE_Desired_States[1];
    MPC_B.b_u1[88] = MPC_DW.BLUE_IMU_Measurements[1];
    MPC_B.b_u1[93] = BLUE_Path_idx_1;
    MPC_B.b_u1[86] = MPC_DW.BLUE_Desired_States[2];
    MPC_B.b_u1[89] = MPC_DW.BLUE_IMU_Measurements[2];
    MPC_B.b_u1[94] = BLUE_Path_idx_2;
    MPC_B.b_u1[95] = MPC_DW.Float_State;
    MPC_B.b_u1[96] = MPC_DW.WhoAmI;
    MPC_B.b_u1[97] = MPC_DW.isSim;
    MPC_B.b_u1[98] = MPC_DW.MPC_Docking_Enabler;
    MPC_B.b_u1[99] = MPC_DW.MPC_Target_Holding_Radius[0];
    MPC_B.b_u1[100] = MPC_DW.MPC_Target_Holding_Radius[1];
    MPC_B.b_u1[101] = MPC_DW.MPC_Controls[0];
    MPC_B.b_u1[104] = MPC_DW.MPC_Solver_Result[0];
    MPC_B.b_u1[102] = MPC_DW.MPC_Controls[1];
    MPC_B.b_u1[105] = MPC_DW.MPC_Solver_Result[1];
    MPC_B.b_u1[103] = MPC_DW.MPC_Controls[2];
    MPC_B.b_u1[106] = MPC_DW.MPC_Solver_Result[2];
    for (rtemp = 0; rtemp < 135; rtemp++) {
      MPC_B.b_u1[rtemp + 107] = MPC_DW.MPC_Optimization_Var[rtemp];
      MPC_B.b_u1[rtemp + 242] = MPC_DW.MPC_Target_Trajectory[rtemp];
    }

    for (rtemp = 0; rtemp < 6; rtemp++) {
      MPC_B.b_u1[rtemp + 377] = MPC_DW.RED_Estimated_States[rtemp];
    }

    memcpy(&MPC_B.b_u1[383], &Pk[0], 36U * sizeof(real_T));
    for (rtemp = 0; rtemp < 6; rtemp++) {
      MPC_B.b_u1[rtemp + 419] = BLACK_Estimated_States[rtemp];
    }

    memcpy(&MPC_B.b_u1[425], &BLACK_Estimated_Covar[0], 36U * sizeof(real_T));
    for (rtemp = 0; rtemp < 6; rtemp++) {
      MPC_B.b_u1[rtemp + 461] = BLUE_Estimated_States[rtemp];
    }

    memcpy(&MPC_B.b_u1[467], &BLUE_Estimated_Covar[0], 36U * sizeof(real_T));
    memcpy(&MPC_B.b_u1[503], &MPC_DW.QMEKFx[0], 13U * sizeof(real_T));
    memcpy(&MPC_B.b_u1[516], &MPC_DW.QMEKFP[0], 144U * sizeof(real_T));
    MPC_B.b_u1[660] = MPC_DW.QMEKFt;
    for (rtemp = 0; rtemp < 6; rtemp++) {
      MPC_B.b_u1[rtemp + 661] = rtb_y_p[rtemp];
    }

    MPC_B.b_u1[667] = dt;
    memcpy(&MPC_B.b_u1[668], &MPC_DW.STQMEKFx[0], 13U * sizeof(real_T));
    memcpy(&MPC_B.b_u1[681], &MPC_DW.STQMEKFP[0], 144U * sizeof(real_T));
    MPC_B.b_u1[825] = MPC_DW.STQMEKFt;
    for (rtemp = 0; rtemp < 6; rtemp++) {
      MPC_B.b_u1[rtemp + 826] = rtb_y_pc[rtemp];
    }

    MPC_B.b_u1[832] = rtb_TSamp_lb;
    memcpy(&MPC_B.b_u1[833], &MPC_DW.DQMEKFx[0], 13U * sizeof(real_T));
    memcpy(&MPC_B.b_u1[846], &MPC_DW.DQMEKFP[0], 144U * sizeof(real_T));
    MPC_B.b_u1[990] = MPC_DW.DQMEKFt;
    for (rtemp = 0; rtemp < 6; rtemp++) {
      MPC_B.b_u1[rtemp + 991] = Chaser[rtemp];
    }

    MPC_B.b_u1[997] = rtb_TSamp;
    memcpy(&MPC_B.b_u1[998], &MPC_DW.STDQMEKFx[0], 13U * sizeof(real_T));
    memcpy(&MPC_B.b_u1[1011], &MPC_DW.STDQMEKFP[0], 144U * sizeof(real_T));
    MPC_B.b_u1[1155] = MPC_DW.STDQMEKFt;
    for (rtemp = 0; rtemp < 6; rtemp++) {
      MPC_B.b_u1[rtemp + 1156] = rtb_y_fj[rtemp];
    }

    MPC_B.b_u1[1162] = rtb_TSamp_e;
    memcpy(&MPC_B.b_u1[1163], &MPC_DW.RMEKFx[0], 13U * sizeof(real_T));
    memcpy(&MPC_B.b_u1[1176], &MPC_DW.RMEKFP[0], 144U * sizeof(real_T));
    MPC_B.b_u1[1320] = MPC_DW.RMEKFt;
    memcpy(&MPC_B.b_u1[1321], &MPC_DW.RMEKFR[0], 9U * sizeof(real_T));
    for (rtemp = 0; rtemp < 6; rtemp++) {
      MPC_B.b_u1[rtemp + 1330] = rtb_y_d[rtemp];
    }

    MPC_B.b_u1[1336] = rtb_TSamp_jb;
    memcpy(&MPC_B.b_u1[1337], &MPC_DW.STRMEKFx[0], 13U * sizeof(real_T));
    memcpy(&MPC_B.b_u1[1350], &MPC_DW.STRMEKFP[0], 144U * sizeof(real_T));
    MPC_B.b_u1[1494] = MPC_DW.STRMEKFt;
    memcpy(&MPC_B.b_u1[1495], &MPC_DW.STRMEKFR[0], 9U * sizeof(real_T));
    for (rtemp = 0; rtemp < 6; rtemp++) {
      MPC_B.b_u1[rtemp + 1504] = rtb_y_mu[rtemp];
    }

    MPC_B.b_u1[1510] = b_norm;

    // MATLAB Function: '<S187>/MATLAB Function'
    if (rEQ0) {
      // MATLABSystem: '<S179>/MATLAB System' incorporates:
      //   SignalConversion generated from: '<S179>/MATLAB System'

      MPC_B.b_u1[1511] = -1.0;
      MPC_B.b_u1[1512] = -1.0;
      MPC_B.b_u1[1513] = -1.0;
      MPC_B.b_u1[1514] = -1.0;
    } else {
      // MATLABSystem: '<S179>/MATLAB System' incorporates:
      //   DataStoreRead: '<S6>/Data Store Read29'
      //   SignalConversion generated from: '<S179>/MATLAB System'

      MPC_B.b_u1[1511] = MPC_DW.Vis_q[0];
      MPC_B.b_u1[1512] = MPC_DW.Vis_q[1];
      MPC_B.b_u1[1513] = MPC_DW.Vis_q[2];
      MPC_B.b_u1[1514] = MPC_DW.Vis_q[3];
    }

    // MATLABSystem: '<S179>/MATLAB System' incorporates:
    //   DataStoreRead: '<S6>/Data Store Read31'
    //   DataStoreRead: '<S6>/Data Store Read32'
    //   DataStoreRead: '<S6>/Data Store Read70'
    //   MATLAB Function: '<S179>/MATLAB Function'
    //   SignalConversion generated from: '<S179>/MATLAB System'

    MPC_B.b_u1[1515] = rtb_y_fe[0];
    MPC_B.b_u1[1516] = rtb_y_fe[1];
    MPC_B.b_u1[1517] = rtb_y_fe[2];
    MPC_B.b_u1[1518] = rtb_y_eu;
    MPC_B.b_u1[1519] = MPC_DW.Vis_q_zoh[0];
    MPC_B.b_u1[1520] = MPC_DW.Vis_q_zoh[1];
    MPC_B.b_u1[1521] = MPC_DW.Vis_q_zoh[2];
    MPC_B.b_u1[1522] = MPC_DW.Vis_q_zoh[3];
    MPC_B.b_u1[1526] = rtb_y_gs;
    MPC_B.b_u1[1523] = MPC_DW.Vis_x_zoh[0];
    MPC_B.b_u1[1527] = Red_x[0];
    MPC_B.b_u1[1524] = MPC_DW.Vis_x_zoh[1];
    MPC_B.b_u1[1528] = Red_x[1];
    MPC_B.b_u1[1525] = MPC_DW.Vis_x_zoh[2];
    MPC_B.b_u1[1529] = Red_x[2];
    for (rtemp = 0; rtemp < 6; rtemp++) {
      MPC_B.b_u1[rtemp + 1530] = BLACK_CTL_Input[rtemp];
    }

    appendDataToFile(&MPC_B.b_u1[0], 1536.0);

    // If: '<S7>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
    //   DataStoreRead: '<S7>/Data Store Read'
    //   DataStoreRead: '<S7>/Data Store Read1'

    if ((MPC_DW.WhoAmI == 2.0) && (MPC_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S7>/Change BLACK Behavior' incorporates:
      //   ActionPort: '<S215>/Action Port'

      // StringToASCII: '<S215>/String to ASCII1' incorporates:
      //   StringConstant: '<S215>/String Constant1'

      strncpy((char_T *)&MPC_B.StringtoASCII1[0], &MPC_P.StringConstant1_String
              [0], 31U);

      // Update for S-Function (sdspToNetwork): '<S215>/UDP Send1' incorporates:
      //   StringToASCII: '<S215>/String to ASCII1'
      //
      sErr = GetErrorBuffer(&MPC_DW.UDPSend1_NetworkLib[0U]);
      LibUpdate_Network(&MPC_DW.UDPSend1_NetworkLib[0U], &MPC_B.StringtoASCII1
                        [0U], 31);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }

      // End of Update for S-Function (sdspToNetwork): '<S215>/UDP Send1'
      // End of Outputs for SubSystem: '<S7>/Change BLACK Behavior'
    }

    // End of If: '<S7>/This IF block determines whether or not to run the BLACK sim//exp' 

    // If: '<S7>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
    //   DataStoreRead: '<S7>/Data Store Read'
    //   DataStoreRead: '<S7>/Data Store Read1'

    if ((MPC_DW.WhoAmI == 3.0) && (MPC_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S7>/Change BLUE Behavior' incorporates:
      //   ActionPort: '<S216>/Action Port'

      // StringToASCII: '<S216>/String to ASCII2' incorporates:
      //   StringConstant: '<S216>/String Constant2'

      strncpy((char_T *)&MPC_B.StringtoASCII2[0], &MPC_P.StringConstant2_String
              [0], 31U);

      // Update for S-Function (sdspToNetwork): '<S216>/UDP Send2' incorporates:
      //   StringToASCII: '<S216>/String to ASCII2'
      //
      sErr = GetErrorBuffer(&MPC_DW.UDPSend2_NetworkLib[0U]);
      LibUpdate_Network(&MPC_DW.UDPSend2_NetworkLib[0U], &MPC_B.StringtoASCII2
                        [0U], 31);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }

      // End of Update for S-Function (sdspToNetwork): '<S216>/UDP Send2'
      // End of Outputs for SubSystem: '<S7>/Change BLUE Behavior'
    }

    // End of If: '<S7>/This IF block determines whether or not to run the BLUE sim//exp' 

    // If: '<S7>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   DataStoreRead: '<S7>/Data Store Read'
    //   DataStoreRead: '<S7>/Data Store Read1'

    if ((MPC_DW.WhoAmI == 1.0) && (MPC_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S7>/Change RED Behavior' incorporates:
      //   ActionPort: '<S217>/Action Port'

      // StringToASCII: '<S217>/String to ASCII' incorporates:
      //   DataStoreRead: '<S217>/Data Store Read'

      strncpy((char_T *)&MPC_B.StringtoASCII[0], &MPC_DW.RED_Logger[0], 31U);

      // Update for S-Function (sdspToNetwork): '<S217>/UDP Send3' incorporates:
      //   StringToASCII: '<S217>/String to ASCII'
      //
      sErr = GetErrorBuffer(&MPC_DW.UDPSend3_NetworkLib[0U]);
      LibUpdate_Network(&MPC_DW.UDPSend3_NetworkLib[0U], &MPC_B.StringtoASCII[0U],
                        31);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }

      // End of Update for S-Function (sdspToNetwork): '<S217>/UDP Send3'
      // End of Outputs for SubSystem: '<S7>/Change RED Behavior'
    }

    // End of If: '<S7>/This IF block determines whether or not to run the RED sim//exp ' 

    // If: '<S8>/This IF block determines whether or not to run the exp code' incorporates:
    //   DataStoreRead: '<S8>/Data Store Read'
    //   If: '<S9>/This IF block determines whether or not to run the exp code'

    if (MPC_DW.isSim == 0.0) {
      // Outputs for IfAction SubSystem: '<S8>/Enable Pucks' incorporates:
      //   ActionPort: '<S218>/Action Port'

      // MATLABSystem: '<S218>/GPIO Write1' incorporates:
      //   DataStoreRead: '<S218>/Data Store Read1'

      if (MPC_DW.obj_c.gpioPin != MPC_P.GPIOWrite1_gpioPin) {
        MPC_DW.obj_c.gpioPin = MPC_P.GPIOWrite1_gpioPin;
      }

      if (MPC_DW.obj_c.pinDirection != MPC_P.GPIOWrite1_pinDirection) {
        MPC_DW.obj_c.pinDirection = MPC_P.GPIOWrite1_pinDirection;
      }

      //         %% Define input properties
      //  Call C-function implementing device output
      // coder.ceval('export_gpio', obj.gpioPin);
      set_pin_direction(MPC_DW.obj_c.gpioPin, MPC_DW.obj_c.pinDirection);
      change_gpio_value(MPC_DW.obj_c.gpioPin, MPC_DW.Float_State);

      // End of MATLABSystem: '<S218>/GPIO Write1'
      // End of Outputs for SubSystem: '<S8>/Enable Pucks'

      // Outputs for IfAction SubSystem: '<S9>/Log Gyro//Accel' incorporates:
      //   ActionPort: '<S219>/Action Port'

      // MATLABSystem: '<S219>/Gyroscope//Accelerometer'
      if (MPC_DW.obj.SampleTime != MPC_P.GyroscopeAccelerometer_SampleTi) {
        MPC_DW.obj.SampleTime = MPC_P.GyroscopeAccelerometer_SampleTi;
      }

      if (MPC_DW.obj.TunablePropsChanged) {
        MPC_DW.obj.TunablePropsChanged = false;
      }

      obj = MPC_DW.obj.SensorObject->Device;
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

      obj = MPC_DW.obj.SensorObject->Device;
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

      // End of MATLABSystem: '<S219>/Gyroscope//Accelerometer'

      // MATLAB Function: '<S219>/Parse IMU Data' incorporates:
      //   DataStoreRead: '<S219>/Data Store Read'

      if (MPC_DW.WhoAmI == 1.0) {
        // DataStoreWrite: '<S219>/Data Store Write9'
        MPC_DW.RED_IMU_Measurements[0] = ARM_Path_idx_0;
        MPC_DW.RED_IMU_Measurements[1] = ARM_Path_idx_1;
        MPC_DW.RED_IMU_Measurements[2] = BLACK_Path[2];

        // DataStoreWrite: '<S219>/Data Store Write10'
        MPC_DW.BLACK_IMU_Measurements[0] = 0.0;
        MPC_DW.BLACK_IMU_Measurements[1] = 0.0;
        MPC_DW.BLACK_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S219>/Data Store Write11'
        MPC_DW.BLUE_IMU_Measurements[0] = 0.0;
        MPC_DW.BLUE_IMU_Measurements[1] = 0.0;
        MPC_DW.BLUE_IMU_Measurements[2] = 0.0;
      } else if (MPC_DW.WhoAmI == 2.0) {
        // DataStoreWrite: '<S219>/Data Store Write9'
        MPC_DW.RED_IMU_Measurements[0] = 0.0;
        MPC_DW.RED_IMU_Measurements[1] = 0.0;
        MPC_DW.RED_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S219>/Data Store Write10'
        MPC_DW.BLACK_IMU_Measurements[0] = ARM_Path_idx_0;
        MPC_DW.BLACK_IMU_Measurements[1] = ARM_Path_idx_1;
        MPC_DW.BLACK_IMU_Measurements[2] = BLACK_Path[2];

        // DataStoreWrite: '<S219>/Data Store Write11'
        MPC_DW.BLUE_IMU_Measurements[0] = 0.0;
        MPC_DW.BLUE_IMU_Measurements[1] = 0.0;
        MPC_DW.BLUE_IMU_Measurements[2] = 0.0;
      } else if (MPC_DW.WhoAmI == 3.0) {
        // DataStoreWrite: '<S219>/Data Store Write9'
        MPC_DW.RED_IMU_Measurements[0] = 0.0;
        MPC_DW.RED_IMU_Measurements[1] = 0.0;
        MPC_DW.RED_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S219>/Data Store Write10'
        MPC_DW.BLACK_IMU_Measurements[0] = 0.0;
        MPC_DW.BLACK_IMU_Measurements[1] = 0.0;
        MPC_DW.BLACK_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S219>/Data Store Write11'
        MPC_DW.BLUE_IMU_Measurements[0] = ARM_Path_idx_0;
        MPC_DW.BLUE_IMU_Measurements[1] = ARM_Path_idx_1;
        MPC_DW.BLUE_IMU_Measurements[2] = BLACK_Path[2];
      } else {
        // DataStoreWrite: '<S219>/Data Store Write9'
        MPC_DW.RED_IMU_Measurements[0] = 0.0;
        MPC_DW.RED_IMU_Measurements[1] = 0.0;
        MPC_DW.RED_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S219>/Data Store Write10'
        MPC_DW.BLACK_IMU_Measurements[0] = 0.0;
        MPC_DW.BLACK_IMU_Measurements[1] = 0.0;
        MPC_DW.BLACK_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S219>/Data Store Write11'
        MPC_DW.BLUE_IMU_Measurements[0] = 0.0;
        MPC_DW.BLUE_IMU_Measurements[1] = 0.0;
        MPC_DW.BLUE_IMU_Measurements[2] = 0.0;
      }

      // End of MATLAB Function: '<S219>/Parse IMU Data'
      // End of Outputs for SubSystem: '<S9>/Log Gyro//Accel'
    }

    // End of If: '<S8>/This IF block determines whether or not to run the exp code' 

    // If: '<S10>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   DataStoreRead: '<S10>/Data Store Read1'
    //   DataStoreRead: '<S10>/Data Store Read2'

    if ((MPC_DW.WhoAmI == 1.0) && (MPC_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S10>/Change ARM Behavior' incorporates:
      //   ActionPort: '<S221>/Action Port'

      // MATLABSystem: '<S221>/Read Joint Positions using  Dynamixel Encoders'
      if (MPC_DW.obj_d.SampleTime != MPC_P.baseRate) {
        if (((!rtIsInf(MPC_P.baseRate)) && (!rtIsNaN(MPC_P.baseRate))) ||
            rtIsInf(MPC_P.baseRate)) {
          sampleTime = MPC_P.baseRate;
        }

        MPC_DW.obj_d.SampleTime = sampleTime;
      }

      //         %% Define input properties
      //         %% Define output properties
      ARM_Path_idx_2 = 0.0;
      ARM_Path_idx_0 = 0.0;
      ARM_Path_idx_1 = 0.0;

      // DataStoreWrite: '<S221>/Data Store Write' incorporates:
      //   Delay: '<S221>/Delay'
      //   Delay: '<S221>/Delay1'
      //   Delay: '<S221>/Delay2'
      //   MATLABSystem: '<S221>/Read Joint Positions using  Dynamixel Encoders'

      MPC_DW.ARM_Measured_States[3] = 0.0;
      MPC_DW.ARM_Measured_States[4] = 0.0;
      MPC_DW.ARM_Measured_States[5] = 0.0;
      read_dynamixel_position(&ARM_Path_idx_2, &ARM_Path_idx_0, &ARM_Path_idx_1,
        &MPC_DW.ARM_Measured_States[3], &MPC_DW.ARM_Measured_States[4],
        &MPC_DW.ARM_Measured_States[5], MPC_DW.Delay_DSTATE_o,
        MPC_DW.Delay1_DSTATE_cg, MPC_DW.Delay2_DSTATE_h);

      // MATLABSystem: '<S221>/Read Joint Positions using  Dynamixel Encoders' incorporates:
      //   Delay: '<S221>/Delay'
      //   Delay: '<S221>/Delay1'
      //   Delay: '<S221>/Delay2'

      MPC_DW.Delay_DSTATE_o = ARM_Path_idx_2;
      MPC_DW.Delay1_DSTATE_cg = ARM_Path_idx_0;
      MPC_DW.Delay2_DSTATE_h = ARM_Path_idx_1;

      // DataStoreWrite: '<S221>/Data Store Write' incorporates:
      //   Delay: '<S221>/Delay'
      //   Delay: '<S221>/Delay1'
      //   Delay: '<S221>/Delay2'

      MPC_DW.ARM_Measured_States[0] = MPC_DW.Delay_DSTATE_o;
      MPC_DW.ARM_Measured_States[1] = MPC_DW.Delay1_DSTATE_cg;
      MPC_DW.ARM_Measured_States[2] = MPC_DW.Delay2_DSTATE_h;

      // End of Outputs for SubSystem: '<S10>/Change ARM Behavior'
    }

    // End of If: '<S10>/This IF block determines whether or not to run the RED sim//exp ' 

    // If: '<S11>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' incorporates:
    //   Constant: '<S228>/Constant'
    //   Constant: '<S233>/Constant3'
    //   Constant: '<S243>/Constant3'
    //   Constant: '<S253>/Constant3'
    //   DataStoreRead: '<S11>/Data Store Read2'
    //   Delay: '<S233>/Delay1'
    //   Delay: '<S243>/Delay1'
    //   Delay: '<S253>/Delay1'
    //   RelationalOperator: '<S228>/Relational Operator'
    //   RelationalOperator: '<S233>/Relational Operator'
    //   RelationalOperator: '<S234>/Relational Operator'
    //   RelationalOperator: '<S243>/Relational Operator'
    //   RelationalOperator: '<S244>/Relational Operator'
    //   RelationalOperator: '<S253>/Relational Operator'
    //   RelationalOperator: '<S254>/Relational Operator'
    //   SignalConversion generated from: '<S239>/Enable'
    //   SignalConversion generated from: '<S241>/Enable'
    //   SignalConversion generated from: '<S249>/Enable'
    //   SignalConversion generated from: '<S251>/Enable'
    //   SignalConversion generated from: '<S259>/Enable'
    //   SignalConversion generated from: '<S261>/Enable'
    //   Sum: '<S233>/Subtract2'
    //   Sum: '<S243>/Subtract2'
    //   Sum: '<S253>/Subtract2'

    rtPrevAction = MPC_DW.Ifperforminganexperimentgrabthe;
    rtAction = -1;
    if (MPC_DW.isSim == 0.0) {
      rtAction = 0;
    } else if (MPC_DW.isSim == 1.0) {
      rtAction = 1;
    }

    MPC_DW.Ifperforminganexperimentgrabthe = rtAction;
    if (rtPrevAction != rtAction) {
      rtsiSetBlockStateForSolverChangedAtMajorStep(&MPC_M->solverInfo, true);
      if (rtPrevAction == 0) {
        // Disable for Enabled SubSystem: '<S235>/Enabled Subsystem'
        if (MPC_DW.EnabledSubsystem_n.EnabledSubsystem_MODE) {
          MPC_EnabledSubsystem_h_Disable(&MPC_DW.EnabledSubsystem_n);
        }

        // End of Disable for SubSystem: '<S235>/Enabled Subsystem'

        // Disable for Enabled SubSystem: '<S234>/Enabled Subsystem'
        if (MPC_DW.EnabledSubsystem_m.EnabledSubsystem_MODE) {
          MPC_EnabledSubsystem_Disable(&MPC_DW.EnabledSubsystem_m);
        }

        // End of Disable for SubSystem: '<S234>/Enabled Subsystem'

        // Disable for Enabled SubSystem: '<S245>/Enabled Subsystem'
        if (MPC_DW.EnabledSubsystem_g.EnabledSubsystem_MODE) {
          MPC_EnabledSubsystem_h_Disable(&MPC_DW.EnabledSubsystem_g);
        }

        // End of Disable for SubSystem: '<S245>/Enabled Subsystem'

        // Disable for Enabled SubSystem: '<S244>/Enabled Subsystem'
        if (MPC_DW.EnabledSubsystem_l.EnabledSubsystem_MODE) {
          MPC_EnabledSubsystem_Disable(&MPC_DW.EnabledSubsystem_l);
        }

        // End of Disable for SubSystem: '<S244>/Enabled Subsystem'

        // Disable for Enabled SubSystem: '<S255>/Enabled Subsystem'
        if (MPC_DW.EnabledSubsystem_a.EnabledSubsystem_MODE) {
          MPC_EnabledSubsystem_h_Disable(&MPC_DW.EnabledSubsystem_a);
        }

        // End of Disable for SubSystem: '<S255>/Enabled Subsystem'

        // Disable for Enabled SubSystem: '<S254>/Enabled Subsystem'
        if (MPC_DW.EnabledSubsystem_k.EnabledSubsystem_MODE) {
          MPC_EnabledSubsystem_Disable(&MPC_DW.EnabledSubsystem_k);
        }

        // End of Disable for SubSystem: '<S254>/Enabled Subsystem'
      }
    }

    switch (rtAction) {
     case 0:
      // Outputs for IfAction SubSystem: '<S11>/Use Hardware to Obtain States' incorporates:
      //   ActionPort: '<S223>/Action Port'

      // S-Function (sdspFromNetwork): '<S224>/Receive PhaseSpace Data'
      sErr = GetErrorBuffer(&MPC_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
      samplesRead = 19;
      LibOutputs_Network(&MPC_DW.ReceivePhaseSpaceData_NetworkLi[0U],
                         &MPC_B.ReceivePhaseSpaceData_o1[0U], &samplesRead);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }

      // End of S-Function (sdspFromNetwork): '<S224>/Receive PhaseSpace Data'

      // Gain: '<S225>/Convert BLAX from [mm] to [m]'
      MPC_B.ConvertBLAXfrommmtom = MPC_P.ConvertBLAXfrommmtom_Gain *
        MPC_B.ReceivePhaseSpaceData_o1[4];

      // Gain: '<S225>/Convert BLAY from [mm] to [m]'
      ARM_Path_idx_0 = MPC_P.ConvertBLAYfrommmtom_Gain *
        MPC_B.ReceivePhaseSpaceData_o1[5];

      // Trigonometry: '<S236>/Sin'
      ARM_Path_idx_1 = sin(MPC_B.ReceivePhaseSpaceData_o1[6]);

      // Trigonometry: '<S236>/Cos'
      ARM_Path_idx_2 = cos(MPC_B.ReceivePhaseSpaceData_o1[6]);

      // DataStoreWrite: '<S225>/Data Store Write' incorporates:
      //   Gain: '<S225>/Convert BLACKVX from [mm] to [m]'
      //   Gain: '<S225>/Convert BLACKVY from [mm] to [m]'
      //   Trigonometry: '<S236>/Atan2'

      MPC_DW.BLACK_Measured_States_RAW[2] = rt_atan2d_snf(ARM_Path_idx_1,
        ARM_Path_idx_2);
      MPC_DW.BLACK_Measured_States_RAW[3] = MPC_P.ConvertBLACKVXfrommmtom_Gain *
        MPC_B.ReceivePhaseSpaceData_o1[13];
      MPC_DW.BLACK_Measured_States_RAW[4] = MPC_P.ConvertBLACKVYfrommmtom_Gain *
        MPC_B.ReceivePhaseSpaceData_o1[14];

      // Sum: '<S233>/Subtract1' incorporates:
      //   Delay: '<S233>/Delay2'

      ARM_Path_idx_2 = MPC_B.ReceivePhaseSpaceData_o1[0] -
        MPC_DW.Delay2_DSTATE_jo;

      // Outputs for Enabled SubSystem: '<S233>/Enabled Subsystem3' incorporates:
      //   EnablePort: '<S237>/Enable'

      if (MPC_B.ConvertBLAXfrommmtom - MPC_DW.Delay1_DSTATE_i !=
          MPC_P.Constant3_Value_e) {
        // SignalConversion generated from: '<S237>/y2-y1'
        MPC_B.y2y1_ob = ARM_Path_idx_2;
      }

      // End of Outputs for SubSystem: '<S233>/Enabled Subsystem3'

      // MATLAB Function: '<S233>/MATLAB Function' incorporates:
      //   Constant: '<S233>/Constant'
      //   Constant: '<S233>/Constant3'
      //   Delay: '<S233>/Delay1'
      //   RelationalOperator: '<S233>/Relational Operator'
      //   Sum: '<S233>/Subtract2'

      MPC_MATLABFunction_jn(MPC_B.y2y1_ob, MPC_P.dataRate, &ARM_Path_idx_1);

      // Sum: '<S235>/Subtract1' incorporates:
      //   Delay: '<S235>/Delay1'

      ARM_Path_idx_2 = MPC_B.ReceivePhaseSpaceData_o1[6] -
        MPC_DW.Delay1_DSTATE_g3[2];

      // RelationalOperator: '<S235>/Relational Operator' incorporates:
      //   Constant: '<S235>/Constant3'
      //   Delay: '<S235>/Delay1'
      //   Sum: '<S235>/Subtract1'

      RelationalOperator_i[0] = (MPC_B.ConvertBLAXfrommmtom -
        MPC_DW.Delay1_DSTATE_g3[0] != MPC_P.Constant3_Value_a);
      RelationalOperator_i[1] = (ARM_Path_idx_0 - MPC_DW.Delay1_DSTATE_g3[1] !=
        MPC_P.Constant3_Value_a);
      RelationalOperator_i[2] = (ARM_Path_idx_2 != MPC_P.Constant3_Value_a);

      // Outputs for Enabled SubSystem: '<S235>/Enabled Subsystem'
      MPC_EnabledSubsystem_n(RelationalOperator_i, MPC_B.ConvertBLAXfrommmtom,
        ARM_Path_idx_0, MPC_B.ReceivePhaseSpaceData_o1[6], ARM_Path_idx_1,
        MPC_B.dy_i, &MPC_B.EnabledSubsystem_n, &MPC_DW.EnabledSubsystem_n,
        &MPC_P.EnabledSubsystem_n);

      // End of Outputs for SubSystem: '<S235>/Enabled Subsystem'

      // RelationalOperator: '<S234>/Relational Operator' incorporates:
      //   Constant: '<S234>/Constant3'
      //   Delay: '<S234>/Delay1'
      //   SignalConversion generated from: '<S241>/Enable'
      //   Sum: '<S234>/Subtract1'

      RelationalOperator_i[0] = (MPC_B.dy_i[0] - MPC_DW.Delay1_DSTATE_b[0] !=
        MPC_P.Constant3_Value_d4);
      RelationalOperator_i[1] = (MPC_B.dy_i[1] - MPC_DW.Delay1_DSTATE_b[1] !=
        MPC_P.Constant3_Value_d4);
      RelationalOperator_i[2] = (MPC_B.dy_i[2] - MPC_DW.Delay1_DSTATE_b[2] !=
        MPC_P.Constant3_Value_d4);

      // Outputs for Enabled SubSystem: '<S234>/Enabled Subsystem'
      MPC_EnabledSubsystem(RelationalOperator_i, MPC_B.dy_i, ARM_Path_idx_1,
                           MPC_B.dy_k, &MPC_B.EnabledSubsystem_m,
                           &MPC_DW.EnabledSubsystem_m, &MPC_P.EnabledSubsystem_m);

      // End of Outputs for SubSystem: '<S234>/Enabled Subsystem'

      // DataStoreWrite: '<S225>/Data Store Write' incorporates:
      //   RelationalOperator: '<S234>/Relational Operator'
      //   SignalConversion generated from: '<S239>/Enable'

      MPC_DW.BLACK_Measured_States_RAW[0] = MPC_B.ConvertBLAXfrommmtom;
      MPC_DW.BLACK_Measured_States_RAW[1] = ARM_Path_idx_0;
      MPC_DW.BLACK_Measured_States_RAW[5] = MPC_B.ReceivePhaseSpaceData_o1[15];
      MPC_DW.BLACK_Measured_States_RAW[6] = MPC_B.dy_k[0];
      MPC_DW.BLACK_Measured_States_RAW[7] = MPC_B.dy_k[1];
      MPC_DW.BLACK_Measured_States_RAW[8] = MPC_B.dy_k[2];

      // SignalConversion generated from: '<S235>/Delay1' incorporates:
      //   Delay: '<S235>/Delay1'

      MPC_DW.Delay1_DSTATE_g3[0] = MPC_B.ConvertBLAXfrommmtom;
      MPC_DW.Delay1_DSTATE_g3[1] = ARM_Path_idx_0;
      MPC_DW.Delay1_DSTATE_g3[2] = MPC_B.ReceivePhaseSpaceData_o1[6];

      // Gain: '<S226>/Convert BLUX from [mm] to [m]'
      MPC_B.ConvertBLUXfrommmtom = MPC_P.ConvertBLUXfrommmtom_Gain *
        MPC_B.ReceivePhaseSpaceData_o1[7];

      // Gain: '<S226>/Convert BLUY from [mm] to [m]'
      ARM_Path_idx_0 = MPC_P.ConvertBLUYfrommmtom_Gain *
        MPC_B.ReceivePhaseSpaceData_o1[8];

      // Trigonometry: '<S246>/Sin'
      ARM_Path_idx_1 = sin(MPC_B.ReceivePhaseSpaceData_o1[9]);

      // Trigonometry: '<S246>/Cos'
      ARM_Path_idx_2 = cos(MPC_B.ReceivePhaseSpaceData_o1[9]);

      // DataStoreWrite: '<S226>/Data Store Write' incorporates:
      //   Gain: '<S226>/Convert BLUEVX from [mm] to [m]'
      //   Gain: '<S226>/Convert BLUEVY from [mm] to [m]'
      //   Trigonometry: '<S246>/Atan2'

      MPC_DW.BLUE_Measured_States_RAW[2] = rt_atan2d_snf(ARM_Path_idx_1,
        ARM_Path_idx_2);
      MPC_DW.BLUE_Measured_States_RAW[3] = MPC_P.ConvertBLUEVXfrommmtom_Gain *
        MPC_B.ReceivePhaseSpaceData_o1[16];
      MPC_DW.BLUE_Measured_States_RAW[4] = MPC_P.ConvertBLUEVYfrommmtom_Gain *
        MPC_B.ReceivePhaseSpaceData_o1[17];

      // Sum: '<S243>/Subtract1' incorporates:
      //   Delay: '<S243>/Delay2'

      ARM_Path_idx_2 = MPC_B.ReceivePhaseSpaceData_o1[0] -
        MPC_DW.Delay2_DSTATE_l;

      // Outputs for Enabled SubSystem: '<S243>/Enabled Subsystem3' incorporates:
      //   EnablePort: '<S247>/Enable'

      if (MPC_B.ConvertBLUXfrommmtom - MPC_DW.Delay1_DSTATE_l !=
          MPC_P.Constant3_Value_o) {
        // SignalConversion generated from: '<S247>/y2-y1'
        MPC_B.y2y1_o = ARM_Path_idx_2;
      }

      // End of Outputs for SubSystem: '<S243>/Enabled Subsystem3'

      // MATLAB Function: '<S243>/MATLAB Function' incorporates:
      //   Constant: '<S243>/Constant'
      //   Constant: '<S243>/Constant3'
      //   Delay: '<S243>/Delay1'
      //   RelationalOperator: '<S243>/Relational Operator'
      //   Sum: '<S243>/Subtract2'

      MPC_MATLABFunction_jn(MPC_B.y2y1_o, MPC_P.dataRate, &ARM_Path_idx_1);

      // Sum: '<S245>/Subtract1' incorporates:
      //   Delay: '<S245>/Delay1'

      ARM_Path_idx_2 = MPC_B.ReceivePhaseSpaceData_o1[9] -
        MPC_DW.Delay1_DSTATE_m[2];

      // RelationalOperator: '<S245>/Relational Operator' incorporates:
      //   Constant: '<S245>/Constant3'
      //   Delay: '<S245>/Delay1'
      //   Sum: '<S245>/Subtract1'

      RelationalOperator_i[0] = (MPC_B.ConvertBLUXfrommmtom -
        MPC_DW.Delay1_DSTATE_m[0] != MPC_P.Constant3_Value_c);
      RelationalOperator_i[1] = (ARM_Path_idx_0 - MPC_DW.Delay1_DSTATE_m[1] !=
        MPC_P.Constant3_Value_c);
      RelationalOperator_i[2] = (ARM_Path_idx_2 != MPC_P.Constant3_Value_c);

      // Outputs for Enabled SubSystem: '<S245>/Enabled Subsystem'
      MPC_EnabledSubsystem_n(RelationalOperator_i, MPC_B.ConvertBLUXfrommmtom,
        ARM_Path_idx_0, MPC_B.ReceivePhaseSpaceData_o1[9], ARM_Path_idx_1,
        MPC_B.dy_c, &MPC_B.EnabledSubsystem_g, &MPC_DW.EnabledSubsystem_g,
        &MPC_P.EnabledSubsystem_g);

      // End of Outputs for SubSystem: '<S245>/Enabled Subsystem'

      // RelationalOperator: '<S244>/Relational Operator' incorporates:
      //   Constant: '<S244>/Constant3'
      //   Delay: '<S244>/Delay1'
      //   SignalConversion generated from: '<S251>/Enable'
      //   Sum: '<S244>/Subtract1'

      RelationalOperator_i[0] = (MPC_B.dy_c[0] - MPC_DW.Delay1_DSTATE_lv[0] !=
        MPC_P.Constant3_Value_k);
      RelationalOperator_i[1] = (MPC_B.dy_c[1] - MPC_DW.Delay1_DSTATE_lv[1] !=
        MPC_P.Constant3_Value_k);
      RelationalOperator_i[2] = (MPC_B.dy_c[2] - MPC_DW.Delay1_DSTATE_lv[2] !=
        MPC_P.Constant3_Value_k);

      // Outputs for Enabled SubSystem: '<S244>/Enabled Subsystem'
      MPC_EnabledSubsystem(RelationalOperator_i, MPC_B.dy_c, ARM_Path_idx_1,
                           MPC_B.dy_e, &MPC_B.EnabledSubsystem_l,
                           &MPC_DW.EnabledSubsystem_l, &MPC_P.EnabledSubsystem_l);

      // End of Outputs for SubSystem: '<S244>/Enabled Subsystem'

      // DataStoreWrite: '<S226>/Data Store Write' incorporates:
      //   RelationalOperator: '<S244>/Relational Operator'
      //   SignalConversion generated from: '<S249>/Enable'

      MPC_DW.BLUE_Measured_States_RAW[0] = MPC_B.ConvertBLUXfrommmtom;
      MPC_DW.BLUE_Measured_States_RAW[1] = ARM_Path_idx_0;
      MPC_DW.BLUE_Measured_States_RAW[5] = MPC_B.ReceivePhaseSpaceData_o1[18];
      MPC_DW.BLUE_Measured_States_RAW[6] = MPC_B.dy_e[0];
      MPC_DW.BLUE_Measured_States_RAW[7] = MPC_B.dy_e[1];
      MPC_DW.BLUE_Measured_States_RAW[8] = MPC_B.dy_e[2];

      // SignalConversion generated from: '<S245>/Delay1' incorporates:
      //   Delay: '<S245>/Delay1'

      MPC_DW.Delay1_DSTATE_m[0] = MPC_B.ConvertBLUXfrommmtom;
      MPC_DW.Delay1_DSTATE_m[1] = ARM_Path_idx_0;
      MPC_DW.Delay1_DSTATE_m[2] = MPC_B.ReceivePhaseSpaceData_o1[9];

      // Gain: '<S227>/Convert REDX from [mm] to [m]'
      MPC_B.ConvertREDXfrommmtom = MPC_P.ConvertREDXfrommmtom_Gain *
        MPC_B.ReceivePhaseSpaceData_o1[1];

      // Gain: '<S227>/Convert REDY from [mm] to [m]'
      ARM_Path_idx_0 = MPC_P.ConvertREDYfrommmtom_Gain *
        MPC_B.ReceivePhaseSpaceData_o1[2];

      // Trigonometry: '<S256>/Sin'
      ARM_Path_idx_1 = sin(MPC_B.ReceivePhaseSpaceData_o1[3]);

      // Trigonometry: '<S256>/Cos'
      ARM_Path_idx_2 = cos(MPC_B.ReceivePhaseSpaceData_o1[3]);

      // DataStoreWrite: '<S227>/Data Store Write' incorporates:
      //   Gain: '<S227>/Convert REDVX from [mm] to [m]'
      //   Gain: '<S227>/Convert REDVY from [mm] to [m]'
      //   Trigonometry: '<S256>/Atan2'

      MPC_DW.RED_Measured_States_RAW[2] = rt_atan2d_snf(ARM_Path_idx_1,
        ARM_Path_idx_2);
      MPC_DW.RED_Measured_States_RAW[3] = MPC_P.ConvertREDVXfrommmtom_Gain *
        MPC_B.ReceivePhaseSpaceData_o1[10];
      MPC_DW.RED_Measured_States_RAW[4] = MPC_P.ConvertREDVYfrommmtom_Gain *
        MPC_B.ReceivePhaseSpaceData_o1[11];

      // Sum: '<S253>/Subtract1' incorporates:
      //   Delay: '<S253>/Delay2'

      ARM_Path_idx_2 = MPC_B.ReceivePhaseSpaceData_o1[0] -
        MPC_DW.Delay2_DSTATE_l0;

      // Outputs for Enabled SubSystem: '<S253>/Enabled Subsystem3' incorporates:
      //   EnablePort: '<S257>/Enable'

      if (MPC_B.ConvertREDXfrommmtom - MPC_DW.Delay1_DSTATE_ld !=
          MPC_P.Constant3_Value_f) {
        // SignalConversion generated from: '<S257>/y2-y1'
        MPC_B.y2y1 = ARM_Path_idx_2;
      }

      // End of Outputs for SubSystem: '<S253>/Enabled Subsystem3'

      // MATLAB Function: '<S253>/MATLAB Function' incorporates:
      //   Constant: '<S253>/Constant'
      //   Constant: '<S253>/Constant3'
      //   Delay: '<S253>/Delay1'
      //   RelationalOperator: '<S253>/Relational Operator'
      //   Sum: '<S253>/Subtract2'

      MPC_MATLABFunction_jn(MPC_B.y2y1, MPC_P.dataRate, &ARM_Path_idx_1);

      // Sum: '<S255>/Subtract1' incorporates:
      //   Delay: '<S255>/Delay1'

      ARM_Path_idx_2 = MPC_B.ReceivePhaseSpaceData_o1[3] -
        MPC_DW.Delay1_DSTATE_cd[2];

      // RelationalOperator: '<S255>/Relational Operator' incorporates:
      //   Constant: '<S255>/Constant3'
      //   Delay: '<S255>/Delay1'
      //   Sum: '<S255>/Subtract1'

      RelationalOperator_i[0] = (MPC_B.ConvertREDXfrommmtom -
        MPC_DW.Delay1_DSTATE_cd[0] != MPC_P.Constant3_Value_dh);
      RelationalOperator_i[1] = (ARM_Path_idx_0 - MPC_DW.Delay1_DSTATE_cd[1] !=
        MPC_P.Constant3_Value_dh);
      RelationalOperator_i[2] = (ARM_Path_idx_2 != MPC_P.Constant3_Value_dh);

      // Outputs for Enabled SubSystem: '<S255>/Enabled Subsystem'
      MPC_EnabledSubsystem_n(RelationalOperator_i, MPC_B.ConvertREDXfrommmtom,
        ARM_Path_idx_0, MPC_B.ReceivePhaseSpaceData_o1[3], ARM_Path_idx_1,
        MPC_B.dy, &MPC_B.EnabledSubsystem_a, &MPC_DW.EnabledSubsystem_a,
        &MPC_P.EnabledSubsystem_a);

      // End of Outputs for SubSystem: '<S255>/Enabled Subsystem'

      // RelationalOperator: '<S254>/Relational Operator' incorporates:
      //   Constant: '<S254>/Constant3'
      //   Delay: '<S254>/Delay1'
      //   SignalConversion generated from: '<S261>/Enable'
      //   Sum: '<S254>/Subtract1'

      RelationalOperator_i[0] = (MPC_B.dy[0] - MPC_DW.Delay1_DSTATE_cq[0] !=
        MPC_P.Constant3_Value_dz);
      RelationalOperator_i[1] = (MPC_B.dy[1] - MPC_DW.Delay1_DSTATE_cq[1] !=
        MPC_P.Constant3_Value_dz);
      RelationalOperator_i[2] = (MPC_B.dy[2] - MPC_DW.Delay1_DSTATE_cq[2] !=
        MPC_P.Constant3_Value_dz);

      // Outputs for Enabled SubSystem: '<S254>/Enabled Subsystem'
      MPC_EnabledSubsystem(RelationalOperator_i, MPC_B.dy, ARM_Path_idx_1,
                           MPC_B.dy_l, &MPC_B.EnabledSubsystem_k,
                           &MPC_DW.EnabledSubsystem_k, &MPC_P.EnabledSubsystem_k);

      // End of Outputs for SubSystem: '<S254>/Enabled Subsystem'

      // DataStoreWrite: '<S227>/Data Store Write' incorporates:
      //   RelationalOperator: '<S254>/Relational Operator'
      //   SignalConversion generated from: '<S259>/Enable'

      MPC_DW.RED_Measured_States_RAW[0] = MPC_B.ConvertREDXfrommmtom;
      MPC_DW.RED_Measured_States_RAW[1] = ARM_Path_idx_0;
      MPC_DW.RED_Measured_States_RAW[5] = MPC_B.ReceivePhaseSpaceData_o1[12];
      MPC_DW.RED_Measured_States_RAW[6] = MPC_B.dy_l[0];
      MPC_DW.RED_Measured_States_RAW[7] = MPC_B.dy_l[1];
      MPC_DW.RED_Measured_States_RAW[8] = MPC_B.dy_l[2];

      // MATLAB Function: '<S229>/MATLAB Function' incorporates:
      //   Delay: '<S229>/Delay'
      //   Delay: '<S229>/Delay1'
      //   Delay: '<S229>/Delay2'

      rtb_StartClock = 0;
      if (MPC_P.platformSelection == 1.0) {
        rtb_StartClock = (MPC_DW.Delay_DSTATE_ip[0] == 1);
      } else if (MPC_P.platformSelection == 2.0) {
        rtb_StartClock = (MPC_DW.Delay1_DSTATE_h[0] == 1);
      } else if (MPC_P.platformSelection == 3.0) {
        rtb_StartClock = ((MPC_DW.Delay_DSTATE_ip[0] == 1) &&
                          (MPC_DW.Delay1_DSTATE_h[0] == 1));
      } else if (MPC_P.platformSelection == 4.0) {
        rtb_StartClock = ((MPC_DW.Delay_DSTATE_ip[0] == 1) &&
                          (MPC_DW.Delay1_DSTATE_h[0] == 1));
      } else if (MPC_P.platformSelection == 5.0) {
        rtb_StartClock = (MPC_DW.Delay_DSTATE_ip[0] == 1);
      } else if (MPC_P.platformSelection == 6.0) {
        rtb_StartClock = (MPC_DW.Delay2_DSTATE_hq[0] == 1);
      } else if (MPC_P.platformSelection == 7.0) {
        rtb_StartClock = ((MPC_DW.Delay_DSTATE_ip[0] == 1) &&
                          (MPC_DW.Delay2_DSTATE_hq[0] == 1));
      } else if (MPC_P.platformSelection == 8.0) {
        rtb_StartClock = ((MPC_DW.Delay_DSTATE_ip[0] == 1) &&
                          (MPC_DW.Delay1_DSTATE_h[0] == 1) &&
                          (MPC_DW.Delay2_DSTATE_hq[0] == 1));
      } else if (MPC_P.platformSelection == 9.0) {
        rtb_StartClock = ((MPC_DW.Delay1_DSTATE_h[0] == 1) &&
                          (MPC_DW.Delay2_DSTATE_hq[0] == 1));
      } else if (MPC_P.platformSelection == 10.0) {
        rtb_StartClock = ((MPC_DW.Delay_DSTATE_ip[0] == 1) &&
                          (MPC_DW.Delay2_DSTATE_hq[0] == 1));
      } else if (MPC_P.platformSelection == 11.0) {
        rtb_StartClock = ((MPC_DW.Delay_DSTATE_ip[0] == 1) &&
                          (MPC_DW.Delay1_DSTATE_h[0] == 1) &&
                          (MPC_DW.Delay2_DSTATE_hq[0] == 1));
      }

      // End of MATLAB Function: '<S229>/MATLAB Function'

      // RelationalOperator: '<S228>/Relational Operator1' incorporates:
      //   Constant: '<S228>/Constant'

      MPC_B.RelationalOperator1 = (rtb_StartClock != MPC_P.Constant_Value_e);

      // Outputs for Enabled SubSystem: '<S228>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S230>/Enable'

      if (MPC_B.RelationalOperator1) {
        // Memory: '<S230>/Memory'
        MPC_B.Memory = MPC_DW.Memory_PreviousInput;
      }

      // End of Outputs for SubSystem: '<S228>/Enabled Subsystem'

      // Clock: '<S224>/Clock'
      MPC_B.Clock = MPC_M->Timing.t[0];

      // Outputs for Enabled SubSystem: '<S228>/Enabled Subsystem1' incorporates:
      //   EnablePort: '<S231>/Enable'

      if (rtb_StartClock == MPC_P.Constant_Value_e) {
        // Sum: '<S231>/Subtract'
        MPC_B.Subtract = MPC_B.Clock - MPC_B.Memory;
      }

      // End of Outputs for SubSystem: '<S228>/Enabled Subsystem1'

      // DataStoreWrite: '<S227>/Universal_Time' incorporates:
      //   Constant: '<S228>/Constant'
      //   RelationalOperator: '<S228>/Relational Operator'

      MPC_DW.Univ_Time = MPC_B.Subtract;

      // SignalConversion generated from: '<S255>/Delay1' incorporates:
      //   Delay: '<S255>/Delay1'

      MPC_DW.Delay1_DSTATE_cd[0] = MPC_B.ConvertREDXfrommmtom;
      MPC_DW.Delay1_DSTATE_cd[1] = ARM_Path_idx_0;
      MPC_DW.Delay1_DSTATE_cd[2] = MPC_B.ReceivePhaseSpaceData_o1[3];

      // S-Function (sdspFromNetwork): '<S229>/UDP Receive'
      sErr = GetErrorBuffer(&MPC_DW.UDPReceive_NetworkLib[0U]);
      rtb_StartClock = 1;
      LibOutputs_Network(&MPC_DW.UDPReceive_NetworkLib[0U], &MPC_B.UDPReceive_o1,
                         &rtb_StartClock);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }

      // End of S-Function (sdspFromNetwork): '<S229>/UDP Receive'

      // S-Function (sdspFromNetwork): '<S229>/UDP Receive2'
      sErr = GetErrorBuffer(&MPC_DW.UDPReceive2_NetworkLib[0U]);
      samplesRead_1 = 1;
      LibOutputs_Network(&MPC_DW.UDPReceive2_NetworkLib[0U],
                         &MPC_B.UDPReceive2_o1, &samplesRead_1);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }

      // End of S-Function (sdspFromNetwork): '<S229>/UDP Receive2'

      // S-Function (sdspFromNetwork): '<S229>/UDP Receive3'
      sErr = GetErrorBuffer(&MPC_DW.UDPReceive3_NetworkLib[0U]);
      nz = 1;
      LibOutputs_Network(&MPC_DW.UDPReceive3_NetworkLib[0U],
                         &MPC_B.UDPReceive3_o1, &nz);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }

      // End of S-Function (sdspFromNetwork): '<S229>/UDP Receive3'
      // End of Outputs for SubSystem: '<S11>/Use Hardware to Obtain States'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S11>/Initialize Universal Time (Simulation)' incorporates:
      //   ActionPort: '<S222>/Action Port'

      // Clock: '<S222>/Set Universal Time (If this is a simulation)' incorporates:
      //   DataStoreWrite: '<S222>/Universal_Time'

      MPC_DW.Univ_Time = MPC_M->Timing.t[0];

      // End of Outputs for SubSystem: '<S11>/Initialize Universal Time (Simulation)' 
      break;
    }

    // End of If: '<S11>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 

    // If: '<S14>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
    //   DataStoreRead: '<S13>/Data Store Read1'
    //   If: '<S13>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.'

    if (MPC_DW.isSim == 0.0) {
      // Outputs for IfAction SubSystem: '<S13>/Subsystem' incorporates:
      //   ActionPort: '<S278>/Action Port'

      // MATLABSystem: '<S278>/WhoAmI' incorporates:
      //   DataStoreWrite: '<S278>/Data Store Write'

      if (MPC_DW.obj_dk.SampleTime != MPC_P.baseRate) {
        if (((!rtIsInf(MPC_P.baseRate)) && (!rtIsNaN(MPC_P.baseRate))) ||
            rtIsInf(MPC_P.baseRate)) {
          sampleTime_0 = MPC_P.baseRate;
        }

        MPC_DW.obj_dk.SampleTime = sampleTime_0;
      }

      //         %% Define output properties
      //  Call C-function implementing device output
      MPC_DW.WhoAmI = WhoAmI();

      // End of MATLABSystem: '<S278>/WhoAmI'
      // End of Outputs for SubSystem: '<S13>/Subsystem'

      // Outputs for IfAction SubSystem: '<S14>/Subsystem' incorporates:
      //   ActionPort: '<S279>/Action Port'

      // S-Function (sdspFromNetwork): '<S279>/UDP Receive1'
      sErr = GetErrorBuffer(&MPC_DW.UDPReceive1_NetworkLib[0U]);
      samplesRead_0 = 4;
      LibOutputs_Network(&MPC_DW.UDPReceive1_NetworkLib[0U],
                         &MPC_B.UDPReceive1_o1[0U], &samplesRead_0);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }

      // End of S-Function (sdspFromNetwork): '<S279>/UDP Receive1'

      // DataTypeConversion: '<S279>/Cast To Double'
      ARM_Path_idx_0 = MPC_B.UDPReceive1_o1[0];

      // DataTypeConversion: '<S279>/Cast To Double1'
      ARM_Path_idx_1 = MPC_B.UDPReceive1_o1[1];

      // SignalConversion generated from: '<S279>/Delay' incorporates:
      //   Constant: '<S279>/Constant'
      //   DataStoreWrite: '<S279>/Data Store Write1'

      MPC_DW.Vis_x_zoh[0] = ARM_Path_idx_0;
      MPC_DW.Vis_x_zoh[1] = ARM_Path_idx_1;
      MPC_DW.Vis_x_zoh[2] = MPC_P.Constant_Value_o;

      // DataTypeConversion: '<S279>/Cast To Double2' incorporates:
      //   DataStoreWrite: '<S279>/Data Store Write2'

      sampleTime_0 = MPC_B.UDPReceive1_o1[2];

      // DataStoreWrite: '<S279>/Data Store Write20' incorporates:
      //   DataStoreWrite: '<S279>/Data Store Write2'
      //   Delay: '<S279>/Delay2'
      //   MATLAB Function: '<S279>/MATLAB Function2'

      MPC_MATLABFunction1_e(sampleTime_0, MPC_DW.Delay2_DSTATE_e,
                            &ARM_Path_idx_2);

      // MATLAB Function: '<S279>/MATLAB Function4' incorporates:
      //   Constant: '<S279>/Constant'
      //   Delay: '<S279>/Delay'
      //   SignalConversion generated from: '<S282>/ SFunction '

      MPC_DW.Delay_DSTATE_c[0] = ARM_Path_idx_0 - MPC_DW.Delay_DSTATE_c[0];
      MPC_DW.Delay_DSTATE_c[1] = ARM_Path_idx_1 - MPC_DW.Delay_DSTATE_c[1];
      MPC_DW.Delay_DSTATE_c[2] = MPC_P.Constant_Value_o - MPC_DW.Delay_DSTATE_c
        [2];
      if ((fabs(MPC_DW.Delay_DSTATE_c[0]) + fabs(MPC_DW.Delay_DSTATE_c[1])) +
          fabs(MPC_DW.Delay_DSTATE_c[2]) < 1.0E-10) {
        // DataStoreWrite: '<S279>/Data Store Write21'
        MPC_DW.Vis_x[0] = (rtNaN);
        MPC_DW.Vis_x[1] = (rtNaN);
        MPC_DW.Vis_x[2] = (rtNaN);
      } else {
        // DataStoreWrite: '<S279>/Data Store Write21'
        MPC_DW.Vis_x[0] = ARM_Path_idx_0;
        MPC_DW.Vis_x[1] = ARM_Path_idx_1;
        MPC_DW.Vis_x[2] = MPC_P.Constant_Value_o;
      }

      // End of MATLAB Function: '<S279>/MATLAB Function4'

      // DataTypeConversion: '<S279>/Cast To Double3' incorporates:
      //   DataStoreWrite: '<S279>/Data Store Write23'

      MPC_DW.Conf_zoh = MPC_B.UDPReceive1_o1[3];

      // DataStoreWrite: '<S279>/Data Store Write22' incorporates:
      //   DataStoreWrite: '<S279>/Data Store Write23'
      //   Delay: '<S279>/Delay1'
      //   MATLAB Function: '<S279>/MATLAB Function1'

      MPC_MATLABFunction1_e(MPC_DW.Conf_zoh, MPC_DW.Delay1_DSTATE_d,
                            &MPC_DW.Conf);

      // MATLAB Function: '<S284>/MATLAB Function' incorporates:
      //   DataStoreRead: '<S279>/Data Store Read1'
      //   DataStoreWrite: '<S279>/Data Store Write15'

      ARM_Path_idx_0 = sin(ARM_Path_idx_2);
      ARM_Path_idx_2 = cos(ARM_Path_idx_2);
      MPC_DW.Vis_R[0] = ARM_Path_idx_2;
      MPC_DW.Vis_R[3] = ARM_Path_idx_0;
      MPC_DW.Vis_R[6] = 0.0;
      MPC_DW.Vis_R[1] = -ARM_Path_idx_0;
      MPC_DW.Vis_R[4] = ARM_Path_idx_2;
      MPC_DW.Vis_R[7] = 0.0;

      // MATLAB Function: '<S283>/MATLAB Function' incorporates:
      //   DataStoreRead: '<S279>/Data Store Read5'

      rtb_TSamp_e = sin(sampleTime_0);
      rtb_TSamp_jb = cos(sampleTime_0);
      Rot_error[0] = rtb_TSamp_jb;
      Rot_error[3] = rtb_TSamp_e;
      Rot_error[6] = 0.0;
      Rot_error[1] = -rtb_TSamp_e;
      Rot_error[4] = rtb_TSamp_jb;
      Rot_error[7] = 0.0;

      // Update for Delay: '<S279>/Delay2' incorporates:
      //   DataStoreWrite: '<S279>/Data Store Write2'

      MPC_DW.Delay2_DSTATE_e = sampleTime_0;

      // MATLAB Function: '<S284>/MATLAB Function' incorporates:
      //   DataStoreWrite: '<S279>/Data Store Write15'

      MPC_DW.Vis_R[2] = 0.0;

      // MATLAB Function: '<S283>/MATLAB Function'
      Rot_error[2] = 0.0;

      // Update for Delay: '<S279>/Delay' incorporates:
      //   DataStoreWrite: '<S279>/Data Store Write1'

      MPC_DW.Delay_DSTATE_c[0] = MPC_DW.Vis_x_zoh[0];

      // MATLAB Function: '<S284>/MATLAB Function' incorporates:
      //   DataStoreWrite: '<S279>/Data Store Write15'

      MPC_DW.Vis_R[5] = 0.0;

      // MATLAB Function: '<S283>/MATLAB Function'
      Rot_error[5] = 0.0;

      // Update for Delay: '<S279>/Delay' incorporates:
      //   DataStoreWrite: '<S279>/Data Store Write1'

      MPC_DW.Delay_DSTATE_c[1] = MPC_DW.Vis_x_zoh[1];

      // MATLAB Function: '<S284>/MATLAB Function' incorporates:
      //   DataStoreWrite: '<S279>/Data Store Write15'

      MPC_DW.Vis_R[8] = 1.0;

      // MATLAB Function: '<S283>/MATLAB Function'
      Rot_error[8] = 1.0;

      // Update for Delay: '<S279>/Delay' incorporates:
      //   DataStoreWrite: '<S279>/Data Store Write1'

      MPC_DW.Delay_DSTATE_c[2] = MPC_DW.Vis_x_zoh[2];

      // MATLAB Function: '<S284>/MATLAB Function' incorporates:
      //   DataStoreWrite: '<S279>/Data Store Write14'
      //   DataStoreWrite: '<S279>/Data Store Write15'

      MPC_rotm2Quat(MPC_DW.Vis_R, MPC_DW.Vis_q);

      // MATLAB Function: '<S283>/MATLAB Function' incorporates:
      //   DataStoreWrite: '<S279>/Data Store Write25'

      MPC_rotm2Quat(Rot_error, MPC_DW.Vis_q_zoh);

      // Update for Delay: '<S279>/Delay1' incorporates:
      //   DataStoreWrite: '<S279>/Data Store Write23'

      MPC_DW.Delay1_DSTATE_d = MPC_DW.Conf_zoh;

      // End of Outputs for SubSystem: '<S14>/Subsystem'
    }

    // End of If: '<S14>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 

    // If: '<S15>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   DataStoreRead: '<S15>/Data Store Read'
    //   DataStoreRead: '<S15>/Data Store Read1'

    if ((MPC_DW.WhoAmI == 1.0) && (MPC_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S15>/Change ARM Behavior' incorporates:
      //   ActionPort: '<S287>/Action Port'

      // MATLABSystem: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' incorporates:
      //   DataStoreRead: '<S287>/Arm Control Mode'
      //   DataStoreRead: '<S287>/Command'

      if (MPC_DW.obj_n.POSITION_P_GAIN != MPC_P.ControlDynamixelActuatorsineith)
      {
        MPC_DW.obj_n.POSITION_P_GAIN = MPC_P.ControlDynamixelActuatorsineith;
      }

      if (MPC_DW.obj_n.POSITION_I_GAIN != MPC_P.ControlDynamixelActuatorsinei_b)
      {
        MPC_DW.obj_n.POSITION_I_GAIN = MPC_P.ControlDynamixelActuatorsinei_b;
      }

      if (MPC_DW.obj_n.POSITION_D_GAIN != MPC_P.ControlDynamixelActuatorsinei_h)
      {
        MPC_DW.obj_n.POSITION_D_GAIN = MPC_P.ControlDynamixelActuatorsinei_h;
      }

      if (MPC_DW.obj_n.MAX_POSITION != MPC_P.ControlDynamixelActuatorsinei_j) {
        MPC_DW.obj_n.MAX_POSITION = MPC_P.ControlDynamixelActuatorsinei_j;
      }

      if (MPC_DW.obj_n.MIN_POSITION != MPC_P.ControlDynamixelActuatorsinei_m) {
        MPC_DW.obj_n.MIN_POSITION = MPC_P.ControlDynamixelActuatorsinei_m;
      }

      if (MPC_DW.obj_n.MOVE_TIME != MPC_P.ControlDynamixelActuatorsine_hy) {
        MPC_DW.obj_n.MOVE_TIME = MPC_P.ControlDynamixelActuatorsine_hy;
      }

      if (MPC_DW.obj_n.CURRENT_LIMIT != MPC_P.ControlDynamixelActuatorsinei_i) {
        MPC_DW.obj_n.CURRENT_LIMIT = MPC_P.ControlDynamixelActuatorsinei_i;
      }

      if (MPC_DW.obj_n.SPEED_P_GAIN != MPC_P.ControlDynamixelActuatorsinei_g) {
        MPC_DW.obj_n.SPEED_P_GAIN = MPC_P.ControlDynamixelActuatorsinei_g;
      }

      if (MPC_DW.obj_n.SPEED_I_GAIN != MPC_P.ControlDynamixelActuatorsine_g3) {
        MPC_DW.obj_n.SPEED_I_GAIN = MPC_P.ControlDynamixelActuatorsine_g3;
      }

      if (MPC_DW.obj_n.VELOCITY_LIMIT != MPC_P.ControlDynamixelActuatorsine_bf)
      {
        MPC_DW.obj_n.VELOCITY_LIMIT = MPC_P.ControlDynamixelActuatorsine_bf;
      }

      if (MPC_DW.obj_n.ACCELERATION_TIME !=
          MPC_P.ControlDynamixelActuatorsinei_l) {
        MPC_DW.obj_n.ACCELERATION_TIME = MPC_P.ControlDynamixelActuatorsinei_l;
      }

      if (MPC_DW.obj_n.SampleTime != MPC_P.baseRate) {
        if (((!rtIsInf(MPC_P.baseRate)) && (!rtIsNaN(MPC_P.baseRate))) ||
            rtIsInf(MPC_P.baseRate)) {
          sampleTime_1 = MPC_P.baseRate;
        }

        MPC_DW.obj_n.SampleTime = sampleTime_1;
      }

      //         %% Define input properties
      //  Call C-function implementing device output
      //  include the dynamicel functions
      //  Run the main controller code. If the switch state is
      //  true then this code will initialize the parameters and
      //  then start the actuator, and THEN run the command. If the
      //  switch state is false, it will not reinitialize the
      //  motor
      dynamixel_controller(MPC_DW.ARM_Control_Mode, MPC_DW.obj_n.POSITION_P_GAIN,
                           MPC_DW.obj_n.POSITION_I_GAIN,
                           MPC_DW.obj_n.POSITION_D_GAIN,
                           MPC_DW.obj_n.MAX_POSITION, MPC_DW.obj_n.MIN_POSITION,
                           MPC_DW.obj_n.MOVE_TIME, ARM_Controls[0],
                           ARM_Controls[1], ARM_Controls[2],
                           MPC_DW.obj_n.CURRENT_LIMIT, ARM_Controls[0],
                           ARM_Controls[1], ARM_Controls[2],
                           MPC_DW.obj_n.SPEED_P_GAIN, MPC_DW.obj_n.SPEED_I_GAIN,
                           MPC_DW.obj_n.VELOCITY_LIMIT, ARM_Controls[0],
                           ARM_Controls[1], ARM_Controls[2],
                           MPC_DW.obj_n.ACCELERATION_TIME);

      // End of MATLABSystem: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
      // End of Outputs for SubSystem: '<S15>/Change ARM Behavior'
    }

    // End of If: '<S15>/This IF block determines whether or not to run the RED sim//exp ' 

    // If: '<S16>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
    //   DataStoreRead: '<S16>/Data Store Read1'

    if (MPC_DW.isSim == 0.0) {
      // Outputs for IfAction SubSystem: '<S16>/Subsystem' incorporates:
      //   ActionPort: '<S288>/Action Port'

      // SignalConversion generated from: '<S288>/UDP Send' incorporates:
      //   DataStoreRead: '<S288>/BLACK States'
      //   DataStoreRead: '<S288>/BLUE States'
      //   DataStoreRead: '<S288>/Data Store Read2'
      //   DataStoreRead: '<S288>/Time'

      MPC_B.TmpSignalConversionAtUDPSendI_o[0] = MPC_DW.Univ_Time;
      for (i = 0; i < 9; i++) {
        MPC_B.TmpSignalConversionAtUDPSendI_o[i + 1] =
          MPC_DW.RED_Measured_States[i];
        MPC_B.TmpSignalConversionAtUDPSendI_o[i + 10] =
          MPC_DW.BLACK_Measured_States[i];
        MPC_B.TmpSignalConversionAtUDPSendI_o[i + 19] =
          MPC_DW.BLUE_Measured_States[i];
      }

      // Update for S-Function (sdspToNetwork): '<S288>/UDP Send' incorporates:
      //   SignalConversion generated from: '<S288>/UDP Send'
      //
      sErr = GetErrorBuffer(&MPC_DW.UDPSend_NetworkLib_m[0U]);
      LibUpdate_Network(&MPC_DW.UDPSend_NetworkLib_m[0U],
                        &MPC_B.TmpSignalConversionAtUDPSendI_o[0U], 28);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }

      // End of Update for S-Function (sdspToNetwork): '<S288>/UDP Send'
      // End of Outputs for SubSystem: '<S16>/Subsystem'
    }

    // End of If: '<S16>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 

    // If: '<S18>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   Constant: '<S318>/Constant1'
    //   Constant: '<S318>/Constant2'
    //   DataStoreRead: '<S18>/Data Store Read'
    //   DataStoreRead: '<S18>/Data Store Read1'
    //   Delay: '<S318>/Delay'
    //   RelationalOperator: '<S318>/Relational Operator1'
    //   RelationalOperator: '<S318>/Relational Operator2'

    if ((MPC_DW.WhoAmI == 1.0) || (MPC_DW.isSim == 1.0)) {
      // Outputs for IfAction SubSystem: '<S18>/Change RED Behavior' incorporates:
      //   ActionPort: '<S291>/Action Port'

      // MATLAB Function: '<S322>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S291>/Data Store Read2'

      MPC_CreateRotationMatrix(MPC_DW.RED_Measured_States_RAW[2],
        rtb_MatrixConcatenate);

      // MATLAB Function: '<S317>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S291>/Data Store Read2'

      MPC_CreateRotationMatrix_k(MPC_DW.RED_Measured_States_RAW[2],
        &rtb_ThrustPer_Final_i[0]);

      // Product: '<S317>/Rotate F_I to F_b' incorporates:
      //   DataStoreRead: '<S291>/Data Store Read'

      rtb_TSamp_e = rtb_ThrustPer_Final_i[0] * RED_Controls[0] + RED_Controls[1]
        * rtb_ThrustPer_Final_i[2];
      rtb_TSamp_jb = RED_Controls[0] * rtb_ThrustPer_Final_i[1] + RED_Controls[1]
        * rtb_ThrustPer_Final_i[3];

      // SignalConversion generated from: '<S319>/Product3' incorporates:
      //   DataStoreRead: '<S291>/Data Store Read'

      ARM_Controls[2] = RED_Controls[2];

      // MATLAB Function: '<S319>/MATLAB Function'
      for (i = 0; i < 8; i++) {
        prev_duty_cycles[i] = MPC_P.F_thrusters_RED[i] / 2.0;
      }

      memset(&y[0], 0, sizeof(real_T) << 6U);
      for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 8;
           BLACK_Estimated_Covar_tmp++) {
        y[BLACK_Estimated_Covar_tmp + (BLACK_Estimated_Covar_tmp << 3)] =
          prev_duty_cycles[BLACK_Estimated_Covar_tmp];

        // MATLAB Function: '<S316>/MATLAB Function5'
        rtb_H_tmp[3 * BLACK_Estimated_Covar_tmp] = b_1[BLACK_Estimated_Covar_tmp];
        rtb_H_tmp[3 * BLACK_Estimated_Covar_tmp + 1] =
          c_0[BLACK_Estimated_Covar_tmp];
        rtb_H_tmp[3 * BLACK_Estimated_Covar_tmp + 2] =
          MPC_P.thruster_dist2CG_RED[BLACK_Estimated_Covar_tmp] / 1000.0;
      }

      for (rtemp = 0; rtemp < 8; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          sampleTime_1 = 0.0;
          for (i = 0; i < 8; i++) {
            sampleTime_1 += rtb_H_tmp[3 * i + BLACK_Estimated_Covar_tmp] * y
              [(rtemp << 3) + i];
          }

          rtb_H[BLACK_Estimated_Covar_tmp + 3 * rtemp] = sampleTime_1;
        }
      }

      // End of MATLAB Function: '<S319>/MATLAB Function'
      MPC_Pseudoinverse1(rtb_H, &MPC_B.Pseudoinverse1_pn);

      // MATLAB Function: '<S316>/MATLAB Function5'
      sampleTime_1 = 1.0;
      rtb_y_eu = 2.0 * MPC_P.MATLABFunction5_tol_j;
      for (rtemp = 0; rtemp < 8; rtemp++) {
        // Product: '<S319>/Product3' incorporates:
        //   MATLABSystem: '<S319>/Pseudoinverse1'
        //   Product: '<S317>/Rotate F_I to F_b'

        sampleTime_0 = (MPC_B.Pseudoinverse1_pn.Pseudoinverse1[rtemp + 8] *
                        rtb_TSamp_jb +
                        MPC_B.Pseudoinverse1_pn.Pseudoinverse1[rtemp] *
                        rtb_TSamp_e) +
          MPC_B.Pseudoinverse1_pn.Pseudoinverse1[rtemp + 16] * ARM_Controls[2];
        MPC_B.duty_cycles[rtemp] = sampleTime_0;

        // MATLAB Function: '<S316>/MATLAB Function5' incorporates:
        //   Product: '<S319>/Product3'

        prev_duty_cycles[rtemp] = sampleTime_0 + rtb_y_eu;
      }

      // MATLAB Function: '<S316>/MATLAB Function5'
      samplesRead = 0;
      do {
        exitg2 = 0;
        if (samplesRead <= static_cast<int32_T>
            (MPC_P.MATLABFunction5_max_iters_o) - 1) {
          dt = MPC_P.F_red_X_nominal * sampleTime_1 / 2.0;
          ThrustPer_Sat[0] = dt;
          ThrustPer_Sat[1] = dt;
          sampleTime_1 = MPC_P.F_red_Y_nominal * sampleTime_1 / 2.0;
          ThrustPer_Sat[2] = sampleTime_1;
          ThrustPer_Sat[3] = sampleTime_1;
          ThrustPer_Sat[4] = dt;
          ThrustPer_Sat[5] = dt;
          ThrustPer_Sat[6] = sampleTime_1;
          ThrustPer_Sat[7] = sampleTime_1;
          memset(&y[0], 0, sizeof(real_T) << 6U);
          for (i = 0; i < 8; i++) {
            y[i + (i << 3)] = ThrustPer_Sat[i];
          }

          for (rtemp = 0; rtemp < 3; rtemp++) {
            for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 8;
                 BLACK_Estimated_Covar_tmp++) {
              sampleTime_1 = 0.0;
              for (i = 0; i < 8; i++) {
                sampleTime_1 += rtb_H_tmp[3 * i + rtemp] * y
                  [(BLACK_Estimated_Covar_tmp << 3) + i];
              }

              rtb_H[rtemp + 3 * BLACK_Estimated_Covar_tmp] = sampleTime_1;
              tmp[BLACK_Estimated_Covar_tmp + (rtemp << 3)] = sampleTime_1;
            }
          }

          for (rtemp = 0; rtemp < 8; rtemp++) {
            rtb_y_eu = tmp[rtemp + 8];
            sampleTime_1 = tmp[rtemp];
            sampleTime_0 = tmp[rtemp + 16];
            for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 8;
                 BLACK_Estimated_Covar_tmp++) {
              y[rtemp + (BLACK_Estimated_Covar_tmp << 3)] = (rtb_H[3 *
                BLACK_Estimated_Covar_tmp + 1] * rtb_y_eu + rtb_H[3 *
                BLACK_Estimated_Covar_tmp] * sampleTime_1) + rtb_H[3 *
                BLACK_Estimated_Covar_tmp + 2] * sampleTime_0;
            }

            ThrustPer_Sat[rtemp] = (rtb_y_eu * rtb_TSamp_jb + sampleTime_1 *
              rtb_TSamp_e) + sampleTime_0 * ARM_Controls[2];
          }

          for (rtemp = 0; rtemp < 64; rtemp++) {
            tmp_0[rtemp] = 2.0 * y[rtemp];
          }

          for (rtemp = 0; rtemp < 8; rtemp++) {
            PWMs[rtemp] = -2.0 * ThrustPer_Sat[rtemp];
          }

          MPC_quadprog(tmp_0, PWMs, MPC_B.duty_cycles, ThrustPer_Sat,
                       &sampleTime_1, &sampleTime_0);
          rtb_TSamp_lb = MPC_maximum_h(ThrustPer_Sat);
          for (i = 0; i < 8; i++) {
            sampleTime_1 = ThrustPer_Sat[i];
            MPC_B.duty_cycles[i] = sampleTime_1;
            PWMs[i] = sampleTime_1;
            if (rtb_TSamp_lb > 1.0) {
              sampleTime_1 /= rtb_TSamp_lb;
              PWMs[i] = sampleTime_1;
            }

            x[i] = (sampleTime_1 > 0.0);
          }

          nz = x[0];
          for (rtemp = 0; rtemp < 7; rtemp++) {
            nz += x[rtemp + 1];
          }

          for (samplesRead_1 = 0; samplesRead_1 < 8; samplesRead_1++) {
            rtb_y_eu = PWMs[samplesRead_1];
            if (rtb_y_eu >= 0.0) {
              b_maxval[samplesRead_1] = rtb_y_eu;
            } else {
              b_maxval[samplesRead_1] = 0.0;
            }
          }

          rtb_y_eu = b_maxval[0];
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 7;
               BLACK_Estimated_Covar_tmp++) {
            rtb_y_eu += b_maxval[BLACK_Estimated_Covar_tmp + 1];
          }

          if (nz >= 1) {
            rtemp = nz;
          } else {
            rtemp = 1;
          }

          sampleTime_1 = rtb_y_eu / static_cast<real_T>(rtemp);
          if ((sampleTime_1 < 0.3) || (nz == 0)) {
            sampleTime_1 = 1.0;
          } else {
            sampleTime_1 = (0.6 - 2.0 * sampleTime_1) + 1.0;
            if (!(sampleTime_1 >= 0.5)) {
              sampleTime_1 = 0.5;
            }
          }

          sampleTime_0 = 0.0;
          for (r2 = 0; r2 < 8; r2++) {
            ARM_Path_idx_2 = ThrustPer_Sat[r2] - prev_duty_cycles[r2];
            prev_duty_cycles[r2] = ARM_Path_idx_2;
            ARM_Path_idx_2 = fabs(ARM_Path_idx_2);
            if (rtIsNaN(ARM_Path_idx_2)) {
              sampleTime_0 = (rtNaN);
            } else if (ARM_Path_idx_2 > sampleTime_0) {
              sampleTime_0 = ARM_Path_idx_2;
            }
          }

          if (sampleTime_0 < MPC_P.MATLABFunction5_tol_j) {
            dt = MPC_P.F_red_X_nominal * sampleTime_1;
            ThrustPer_Sat[0] = dt;
            ThrustPer_Sat[1] = dt;
            sampleTime_1 *= MPC_P.F_red_Y_nominal;
            ThrustPer_Sat[2] = sampleTime_1;
            ThrustPer_Sat[3] = sampleTime_1;
            ThrustPer_Sat[4] = dt;
            ThrustPer_Sat[5] = dt;
            ThrustPer_Sat[6] = sampleTime_1;
            ThrustPer_Sat[7] = sampleTime_1;
            memset(&y[0], 0, sizeof(real_T) << 6U);
            for (i = 0; i < 8; i++) {
              y[i + (i << 3)] = ThrustPer_Sat[i];
            }

            for (rtemp = 0; rtemp < 8; rtemp++) {
              for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
                   BLACK_Estimated_Covar_tmp++) {
                sampleTime_1 = 0.0;
                for (i = 0; i < 8; i++) {
                  sampleTime_1 += rtb_H_tmp[3 * i + BLACK_Estimated_Covar_tmp] *
                    y[(rtemp << 3) + i];
                }

                rtb_H[BLACK_Estimated_Covar_tmp + 3 * rtemp] = sampleTime_1;
              }
            }

            exitg2 = 1;
          } else {
            memcpy(&prev_duty_cycles[0], &ThrustPer_Sat[0], sizeof(real_T) << 3U);
            samplesRead++;
          }
        } else {
          dt = MPC_P.F_red_X_nominal * sampleTime_1;
          ThrustPer_Sat[0] = dt;
          ThrustPer_Sat[1] = dt;
          sampleTime_1 *= MPC_P.F_red_Y_nominal;
          ThrustPer_Sat[2] = sampleTime_1;
          ThrustPer_Sat[3] = sampleTime_1;
          ThrustPer_Sat[4] = dt;
          ThrustPer_Sat[5] = dt;
          ThrustPer_Sat[6] = sampleTime_1;
          ThrustPer_Sat[7] = sampleTime_1;
          memset(&y[0], 0, sizeof(real_T) << 6U);
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 8;
               BLACK_Estimated_Covar_tmp++) {
            y[BLACK_Estimated_Covar_tmp + (BLACK_Estimated_Covar_tmp << 3)] =
              ThrustPer_Sat[BLACK_Estimated_Covar_tmp];
          }

          for (rtemp = 0; rtemp < 8; rtemp++) {
            for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
                 BLACK_Estimated_Covar_tmp++) {
              sampleTime_1 = 0.0;
              for (i = 0; i < 8; i++) {
                sampleTime_1 += rtb_H_tmp[3 * i + BLACK_Estimated_Covar_tmp] *
                  y[(rtemp << 3) + i];
              }

              rtb_H[BLACK_Estimated_Covar_tmp + 3 * rtemp] = sampleTime_1;
            }
          }

          exitg2 = 1;
        }
      } while (exitg2 == 0);

      // MATLAB Function: '<S316>/MATLAB Function8'
      MPC_MATLABFunction1_i(MPC_B.duty_cycles, rtb_ThrustPer_Final_i);

      // Outputs for Enabled SubSystem: '<S318>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S323>/Enable'

      if (MPC_DW.Delay_DSTATE_hj >= 1.0 / MPC_P.PWMFreq) {
        // SignalConversion generated from: '<S323>/In1' incorporates:
        //   DataStoreRead: '<S318>/Data Store Read'

        MPC_B.In1 = MPC_DW.Univ_Time;
      }

      // End of Outputs for SubSystem: '<S318>/Enabled Subsystem'

      // Sum: '<S318>/Subtract' incorporates:
      //   Constant: '<S318>/Constant1'
      //   DataStoreRead: '<S318>/Data Store Read'
      //   Delay: '<S318>/Delay'
      //   RelationalOperator: '<S318>/Relational Operator1'

      MPC_DW.Delay_DSTATE_hj = MPC_DW.Univ_Time - MPC_B.In1;

      // Outputs for Enabled SubSystem: '<S318>/Enabled Subsystem1' incorporates:
      //   EnablePort: '<S324>/Enable'

      if (MPC_DW.Delay_DSTATE_hj == MPC_P.Constant2_Value_h) {
        // SignalConversion generated from: '<S324>/ThrustPer_Final'
        memcpy(&MPC_B.ThrustPer_Final[0], &rtb_ThrustPer_Final_i[0], sizeof
               (real_T) << 3U);
      }

      // End of Outputs for SubSystem: '<S318>/Enabled Subsystem1'

      // Product: '<S316>/Product1' incorporates:
      //   Constant: '<S318>/Constant2'
      //   Delay: '<S318>/Delay'
      //   RelationalOperator: '<S318>/Relational Operator2'

      for (rtemp = 0; rtemp < 3; rtemp++) {
        sampleTime_1 = 0.0;
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 8;
             BLACK_Estimated_Covar_tmp++) {
          sampleTime_1 += rtb_H[3 * BLACK_Estimated_Covar_tmp + rtemp] *
            MPC_B.ThrustPer_Final[BLACK_Estimated_Covar_tmp];
        }

        ARM_Controls[rtemp] = sampleTime_1;
      }

      // End of Product: '<S316>/Product1'

      // DataStoreWrite: '<S291>/Data Store Write1' incorporates:
      //   Product: '<S322>/Rotate F_b to F_I'

      MPC_DW.RED_Saturated_Controls[0] = rtb_MatrixConcatenate[0] *
        ARM_Controls[0] + ARM_Controls[1] * rtb_MatrixConcatenate[2];
      MPC_DW.RED_Saturated_Controls[1] = ARM_Controls[0] *
        rtb_MatrixConcatenate[1] + ARM_Controls[1] * rtb_MatrixConcatenate[3];
      MPC_DW.RED_Saturated_Controls[2] = ARM_Controls[2];

      // End of Outputs for SubSystem: '<S18>/Change RED Behavior'
    }

    // End of If: '<S18>/This IF block determines whether or not to run the RED sim//exp ' 

    // If: '<S18>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
    //   Constant: '<S294>/Constant1'
    //   Constant: '<S294>/Constant2'
    //   DataStoreRead: '<S18>/Data Store Read'
    //   DataStoreRead: '<S18>/Data Store Read1'
    //   Delay: '<S294>/Delay'
    //   RelationalOperator: '<S294>/Relational Operator1'
    //   RelationalOperator: '<S294>/Relational Operator2'

    if ((MPC_DW.WhoAmI == 2.0) || (MPC_DW.isSim == 1.0)) {
      // Outputs for IfAction SubSystem: '<S18>/Change BLACK Behavior' incorporates:
      //   ActionPort: '<S289>/Action Port'

      // MATLAB Function: '<S298>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S289>/Data Store Read'

      MPC_CreateRotationMatrix(MPC_DW.BLACK_Measured_States_RAW[2],
        rtb_MatrixConcatenate);

      // MATLAB Function: '<S293>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S289>/Data Store Read'

      MPC_CreateRotationMatrix_k(MPC_DW.BLACK_Measured_States_RAW[2], a);

      // Product: '<S293>/Rotate F_I to F_b' incorporates:
      //   DataStoreRead: '<S289>/BLACK Controls'

      rtb_TSamp = a[0] * BLACK_Controls[0] + BLACK_Controls[1] * a[2];
      b_norm = BLACK_Controls[0] * a[1] + BLACK_Controls[1] * a[3];

      // SignalConversion generated from: '<S295>/Product3' incorporates:
      //   DataStoreRead: '<S289>/BLACK Controls'

      RED_Controls[2] = BLACK_Controls[2];

      // MATLAB Function: '<S295>/MATLAB Function'
      for (i = 0; i < 8; i++) {
        prev_duty_cycles[i] = MPC_P.F_thrusters_BLACK[i] / 2.0;
      }

      memset(&y[0], 0, sizeof(real_T) << 6U);
      for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 8;
           BLACK_Estimated_Covar_tmp++) {
        y[BLACK_Estimated_Covar_tmp + (BLACK_Estimated_Covar_tmp << 3)] =
          prev_duty_cycles[BLACK_Estimated_Covar_tmp];

        // MATLAB Function: '<S292>/MATLAB Function5'
        rtb_H_tmp[3 * BLACK_Estimated_Covar_tmp] = b_1[BLACK_Estimated_Covar_tmp];
        rtb_H_tmp[3 * BLACK_Estimated_Covar_tmp + 1] =
          c_0[BLACK_Estimated_Covar_tmp];
        rtb_H_tmp[3 * BLACK_Estimated_Covar_tmp + 2] =
          MPC_P.thruster_dist2CG_BLACK[BLACK_Estimated_Covar_tmp] / 1000.0;
      }

      for (rtemp = 0; rtemp < 8; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          sampleTime_1 = 0.0;
          for (i = 0; i < 8; i++) {
            sampleTime_1 += rtb_H_tmp[3 * i + BLACK_Estimated_Covar_tmp] * y
              [(rtemp << 3) + i];
          }

          rtb_H[BLACK_Estimated_Covar_tmp + 3 * rtemp] = sampleTime_1;
        }
      }

      // End of MATLAB Function: '<S295>/MATLAB Function'
      MPC_Pseudoinverse1(rtb_H, &MPC_B.Pseudoinverse1);

      // MATLAB Function: '<S292>/MATLAB Function5'
      sampleTime_1 = 1.0;
      rtb_TSamp_e = 2.0 * MPC_P.MATLABFunction5_tol;
      for (rtemp = 0; rtemp < 8; rtemp++) {
        // Product: '<S295>/Product3' incorporates:
        //   MATLABSystem: '<S295>/Pseudoinverse1'
        //   Product: '<S293>/Rotate F_I to F_b'

        sampleTime_0 = (MPC_B.Pseudoinverse1.Pseudoinverse1[rtemp + 8] * b_norm
                        + MPC_B.Pseudoinverse1.Pseudoinverse1[rtemp] * rtb_TSamp)
          + MPC_B.Pseudoinverse1.Pseudoinverse1[rtemp + 16] * RED_Controls[2];
        MPC_B.duty_cycles_n[rtemp] = sampleTime_0;

        // MATLAB Function: '<S292>/MATLAB Function5' incorporates:
        //   Product: '<S295>/Product3'

        prev_duty_cycles[rtemp] = sampleTime_0 + rtb_TSamp_e;
      }

      // MATLAB Function: '<S292>/MATLAB Function5'
      samplesRead = 0;
      do {
        exitg2 = 0;
        if (samplesRead <= static_cast<int32_T>(MPC_P.MATLABFunction5_max_iters)
            - 1) {
          dt = MPC_P.F_black_X_nominal * sampleTime_1 / 2.0;
          ThrustPer_Sat[0] = dt;
          ThrustPer_Sat[1] = dt;
          sampleTime_1 = MPC_P.F_black_Y_nominal * sampleTime_1 / 2.0;
          ThrustPer_Sat[2] = sampleTime_1;
          ThrustPer_Sat[3] = sampleTime_1;
          ThrustPer_Sat[4] = dt;
          ThrustPer_Sat[5] = dt;
          ThrustPer_Sat[6] = sampleTime_1;
          ThrustPer_Sat[7] = sampleTime_1;
          memset(&y[0], 0, sizeof(real_T) << 6U);
          for (i = 0; i < 8; i++) {
            y[i + (i << 3)] = ThrustPer_Sat[i];
          }

          for (rtemp = 0; rtemp < 3; rtemp++) {
            for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 8;
                 BLACK_Estimated_Covar_tmp++) {
              sampleTime_1 = 0.0;
              for (i = 0; i < 8; i++) {
                sampleTime_1 += rtb_H_tmp[3 * i + rtemp] * y
                  [(BLACK_Estimated_Covar_tmp << 3) + i];
              }

              rtb_H[rtemp + 3 * BLACK_Estimated_Covar_tmp] = sampleTime_1;
              tmp[BLACK_Estimated_Covar_tmp + (rtemp << 3)] = sampleTime_1;
            }
          }

          for (rtemp = 0; rtemp < 8; rtemp++) {
            rtb_TSamp_e = tmp[rtemp + 8];
            rtb_TSamp_jb = tmp[rtemp];
            rtb_y_eu = tmp[rtemp + 16];
            for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 8;
                 BLACK_Estimated_Covar_tmp++) {
              y[rtemp + (BLACK_Estimated_Covar_tmp << 3)] = (rtb_H[3 *
                BLACK_Estimated_Covar_tmp + 1] * rtb_TSamp_e + rtb_H[3 *
                BLACK_Estimated_Covar_tmp] * rtb_TSamp_jb) + rtb_H[3 *
                BLACK_Estimated_Covar_tmp + 2] * rtb_y_eu;
            }

            ThrustPer_Sat[rtemp] = (rtb_TSamp_e * b_norm + rtb_TSamp_jb *
              rtb_TSamp) + rtb_y_eu * RED_Controls[2];
          }

          for (rtemp = 0; rtemp < 64; rtemp++) {
            tmp_0[rtemp] = 2.0 * y[rtemp];
          }

          for (rtemp = 0; rtemp < 8; rtemp++) {
            PWMs[rtemp] = -2.0 * ThrustPer_Sat[rtemp];
          }

          MPC_quadprog(tmp_0, PWMs, MPC_B.duty_cycles_n, ThrustPer_Sat,
                       &sampleTime_1, &sampleTime_0);
          rtb_TSamp_lb = MPC_maximum_h(ThrustPer_Sat);
          for (i = 0; i < 8; i++) {
            sampleTime_1 = ThrustPer_Sat[i];
            MPC_B.duty_cycles_n[i] = sampleTime_1;
            PWMs[i] = sampleTime_1;
            if (rtb_TSamp_lb > 1.0) {
              sampleTime_1 /= rtb_TSamp_lb;
              PWMs[i] = sampleTime_1;
            }

            x[i] = (sampleTime_1 > 0.0);
          }

          nz = x[0];
          for (rtemp = 0; rtemp < 7; rtemp++) {
            nz += x[rtemp + 1];
          }

          for (samplesRead_1 = 0; samplesRead_1 < 8; samplesRead_1++) {
            rtb_y_eu = PWMs[samplesRead_1];
            if (rtb_y_eu >= 0.0) {
              b_maxval[samplesRead_1] = rtb_y_eu;
            } else {
              b_maxval[samplesRead_1] = 0.0;
            }
          }

          rtb_y_eu = b_maxval[0];
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 7;
               BLACK_Estimated_Covar_tmp++) {
            rtb_y_eu += b_maxval[BLACK_Estimated_Covar_tmp + 1];
          }

          if (nz >= 1) {
            rtemp = nz;
          } else {
            rtemp = 1;
          }

          sampleTime_1 = rtb_y_eu / static_cast<real_T>(rtemp);
          if ((sampleTime_1 < 0.3) || (nz == 0)) {
            sampleTime_1 = 1.0;
          } else {
            sampleTime_1 = (0.6 - 2.0 * sampleTime_1) + 1.0;
            if (!(sampleTime_1 >= 0.5)) {
              sampleTime_1 = 0.5;
            }
          }

          sampleTime_0 = 0.0;
          for (r2 = 0; r2 < 8; r2++) {
            ARM_Path_idx_2 = ThrustPer_Sat[r2] - prev_duty_cycles[r2];
            prev_duty_cycles[r2] = ARM_Path_idx_2;
            ARM_Path_idx_2 = fabs(ARM_Path_idx_2);
            if (rtIsNaN(ARM_Path_idx_2)) {
              sampleTime_0 = (rtNaN);
            } else if (ARM_Path_idx_2 > sampleTime_0) {
              sampleTime_0 = ARM_Path_idx_2;
            }
          }

          if (sampleTime_0 < MPC_P.MATLABFunction5_tol) {
            dt = MPC_P.F_black_X_nominal * sampleTime_1;
            ThrustPer_Sat[0] = dt;
            ThrustPer_Sat[1] = dt;
            sampleTime_1 *= MPC_P.F_black_Y_nominal;
            ThrustPer_Sat[2] = sampleTime_1;
            ThrustPer_Sat[3] = sampleTime_1;
            ThrustPer_Sat[4] = dt;
            ThrustPer_Sat[5] = dt;
            ThrustPer_Sat[6] = sampleTime_1;
            ThrustPer_Sat[7] = sampleTime_1;
            memset(&y[0], 0, sizeof(real_T) << 6U);
            for (i = 0; i < 8; i++) {
              y[i + (i << 3)] = ThrustPer_Sat[i];
            }

            for (rtemp = 0; rtemp < 8; rtemp++) {
              for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
                   BLACK_Estimated_Covar_tmp++) {
                sampleTime_1 = 0.0;
                for (i = 0; i < 8; i++) {
                  sampleTime_1 += rtb_H_tmp[3 * i + BLACK_Estimated_Covar_tmp] *
                    y[(rtemp << 3) + i];
                }

                rtb_H[BLACK_Estimated_Covar_tmp + 3 * rtemp] = sampleTime_1;
              }
            }

            exitg2 = 1;
          } else {
            memcpy(&prev_duty_cycles[0], &ThrustPer_Sat[0], sizeof(real_T) << 3U);
            samplesRead++;
          }
        } else {
          dt = MPC_P.F_black_X_nominal * sampleTime_1;
          ThrustPer_Sat[0] = dt;
          ThrustPer_Sat[1] = dt;
          sampleTime_1 *= MPC_P.F_black_Y_nominal;
          ThrustPer_Sat[2] = sampleTime_1;
          ThrustPer_Sat[3] = sampleTime_1;
          ThrustPer_Sat[4] = dt;
          ThrustPer_Sat[5] = dt;
          ThrustPer_Sat[6] = sampleTime_1;
          ThrustPer_Sat[7] = sampleTime_1;
          memset(&y[0], 0, sizeof(real_T) << 6U);
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 8;
               BLACK_Estimated_Covar_tmp++) {
            y[BLACK_Estimated_Covar_tmp + (BLACK_Estimated_Covar_tmp << 3)] =
              ThrustPer_Sat[BLACK_Estimated_Covar_tmp];
          }

          for (rtemp = 0; rtemp < 8; rtemp++) {
            for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
                 BLACK_Estimated_Covar_tmp++) {
              sampleTime_1 = 0.0;
              for (i = 0; i < 8; i++) {
                sampleTime_1 += rtb_H_tmp[3 * i + BLACK_Estimated_Covar_tmp] *
                  y[(rtemp << 3) + i];
              }

              rtb_H[BLACK_Estimated_Covar_tmp + 3 * rtemp] = sampleTime_1;
            }
          }

          exitg2 = 1;
        }
      } while (exitg2 == 0);

      // MATLAB Function: '<S292>/MATLAB Function1'
      sampleTime_0 = 1.0 / MPC_P.PWMFreq;
      rtb_TSamp_lb = MPC_maximum_h(MPC_B.duty_cycles_n);
      for (i = 0; i < 8; i++) {
        prev_duty_cycles[i] = 0.0;
        if (rtb_TSamp_lb > 1.0) {
          sampleTime_1 = MPC_B.duty_cycles_n[i] / rtb_TSamp_lb;
        } else {
          sampleTime_1 = MPC_B.duty_cycles_n[i];
        }

        if (sampleTime_1 > 0.007 / sampleTime_0) {
          prev_duty_cycles[i] = sampleTime_1;
        }
      }

      // End of MATLAB Function: '<S292>/MATLAB Function1'

      // Outputs for Enabled SubSystem: '<S294>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S299>/Enable'

      if (MPC_DW.Delay_DSTATE_j >= 1.0 / MPC_P.PWMFreq) {
        // SignalConversion generated from: '<S299>/In1' incorporates:
        //   DataStoreRead: '<S294>/Data Store Read'

        MPC_B.In1_g2 = MPC_DW.Univ_Time;
      }

      // End of Outputs for SubSystem: '<S294>/Enabled Subsystem'

      // Sum: '<S294>/Subtract' incorporates:
      //   Constant: '<S294>/Constant1'
      //   DataStoreRead: '<S294>/Data Store Read'
      //   Delay: '<S294>/Delay'
      //   RelationalOperator: '<S294>/Relational Operator1'

      MPC_DW.Delay_DSTATE_j = MPC_DW.Univ_Time - MPC_B.In1_g2;

      // Outputs for Enabled SubSystem: '<S294>/Enabled Subsystem1' incorporates:
      //   EnablePort: '<S300>/Enable'

      if (MPC_DW.Delay_DSTATE_j == MPC_P.Constant2_Value_o) {
        // SignalConversion generated from: '<S300>/ThrustPer_Final'
        memcpy(&MPC_B.ThrustPer_Final_h5[0], &prev_duty_cycles[0], sizeof(real_T)
               << 3U);
      }

      // End of Outputs for SubSystem: '<S294>/Enabled Subsystem1'

      // Product: '<S292>/Product1' incorporates:
      //   Constant: '<S294>/Constant2'
      //   Delay: '<S294>/Delay'
      //   RelationalOperator: '<S294>/Relational Operator2'

      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_lb = 0.0;
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 8;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_lb += rtb_H[3 * BLACK_Estimated_Covar_tmp + rtemp] *
            MPC_B.ThrustPer_Final_h5[BLACK_Estimated_Covar_tmp];
        }

        RED_Controls[rtemp] = rtb_TSamp_lb;
      }

      // End of Product: '<S292>/Product1'

      // DataStoreWrite: '<S289>/Data Store Write2' incorporates:
      //   Product: '<S298>/Rotate F_b to F_I'

      MPC_DW.BLACK_Saturated_Controls[0] = rtb_MatrixConcatenate[0] *
        RED_Controls[0] + RED_Controls[1] * rtb_MatrixConcatenate[2];
      MPC_DW.BLACK_Saturated_Controls[1] = RED_Controls[0] *
        rtb_MatrixConcatenate[1] + RED_Controls[1] * rtb_MatrixConcatenate[3];
      MPC_DW.BLACK_Saturated_Controls[2] = RED_Controls[2];

      // End of Outputs for SubSystem: '<S18>/Change BLACK Behavior'
    }

    // End of If: '<S18>/This IF block determines whether or not to run the BLACK sim//exp' 

    // If: '<S18>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
    //   Constant: '<S306>/Constant1'
    //   Constant: '<S306>/Constant2'
    //   DataStoreRead: '<S18>/Data Store Read'
    //   DataStoreRead: '<S18>/Data Store Read1'
    //   Delay: '<S306>/Delay'
    //   RelationalOperator: '<S306>/Relational Operator1'
    //   RelationalOperator: '<S306>/Relational Operator2'

    if ((MPC_DW.WhoAmI == 3.0) || (MPC_DW.isSim == 1.0)) {
      // Outputs for IfAction SubSystem: '<S18>/Change BLUE Behavior' incorporates:
      //   ActionPort: '<S290>/Action Port'

      // MATLAB Function: '<S310>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S290>/Data Store Read1'

      MPC_CreateRotationMatrix(MPC_DW.BLUE_Measured_States_RAW[2],
        rtb_MatrixConcatenate);

      // MATLAB Function: '<S305>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S290>/Data Store Read1'

      MPC_CreateRotationMatrix_k(MPC_DW.BLUE_Measured_States_RAW[2],
        &rtb_ThrustPer_Final_n[0]);

      // Product: '<S305>/Rotate F_I to F_b' incorporates:
      //   DataStoreRead: '<S290>/Data Store Read'

      rtb_TSamp_e = rtb_ThrustPer_Final_n[0] * rtb_TSamp_o +
        rtb_ThrustPer_Final_n[2] * rtb_TSamp_h;
      rtb_TSamp_jb = rtb_ThrustPer_Final_n[1] * rtb_TSamp_o +
        rtb_ThrustPer_Final_n[3] * rtb_TSamp_h;

      // MATLAB Function: '<S307>/MATLAB Function'
      for (i = 0; i < 8; i++) {
        prev_duty_cycles[i] = MPC_P.F_thrusters_BLUE[i] / 2.0;
      }

      memset(&y[0], 0, sizeof(real_T) << 6U);
      for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 8;
           BLACK_Estimated_Covar_tmp++) {
        y[BLACK_Estimated_Covar_tmp + (BLACK_Estimated_Covar_tmp << 3)] =
          prev_duty_cycles[BLACK_Estimated_Covar_tmp];

        // MATLAB Function: '<S304>/MATLAB Function5'
        rtb_H_tmp[3 * BLACK_Estimated_Covar_tmp] = b_1[BLACK_Estimated_Covar_tmp];
        rtb_H_tmp[3 * BLACK_Estimated_Covar_tmp + 1] =
          c_0[BLACK_Estimated_Covar_tmp];
        rtb_H_tmp[3 * BLACK_Estimated_Covar_tmp + 2] =
          MPC_P.thruster_dist2CG_BLUE[BLACK_Estimated_Covar_tmp] / 1000.0;
      }

      for (rtemp = 0; rtemp < 8; rtemp++) {
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
             BLACK_Estimated_Covar_tmp++) {
          sampleTime_1 = 0.0;
          for (i = 0; i < 8; i++) {
            sampleTime_1 += rtb_H_tmp[3 * i + BLACK_Estimated_Covar_tmp] * y
              [(rtemp << 3) + i];
          }

          rtb_H[BLACK_Estimated_Covar_tmp + 3 * rtemp] = sampleTime_1;
        }
      }

      // End of MATLAB Function: '<S307>/MATLAB Function'
      MPC_Pseudoinverse1(rtb_H, &MPC_B.Pseudoinverse1_p);

      // MATLAB Function: '<S304>/MATLAB Function5'
      sampleTime_1 = 1.0;
      rtb_y_eu = 2.0 * MPC_P.MATLABFunction5_tol_i;
      for (rtemp = 0; rtemp < 8; rtemp++) {
        // Product: '<S307>/Product3' incorporates:
        //   DataStoreRead: '<S290>/Data Store Read'
        //   MATLABSystem: '<S307>/Pseudoinverse1'
        //   Product: '<S305>/Rotate F_I to F_b'
        //   SignalConversion generated from: '<S307>/Product3'

        rtb_TSamp_o = (MPC_B.Pseudoinverse1_p.Pseudoinverse1[rtemp + 8] *
                       rtb_TSamp_jb +
                       MPC_B.Pseudoinverse1_p.Pseudoinverse1[rtemp] *
                       rtb_TSamp_e) +
          MPC_B.Pseudoinverse1_p.Pseudoinverse1[rtemp + 16] * rtb_TSamp_ne;
        MPC_B.duty_cycles_k[rtemp] = rtb_TSamp_o;

        // MATLAB Function: '<S304>/MATLAB Function5' incorporates:
        //   Product: '<S307>/Product3'

        prev_duty_cycles[rtemp] = rtb_TSamp_o + rtb_y_eu;
      }

      // MATLAB Function: '<S304>/MATLAB Function5'
      samplesRead = 0;
      do {
        exitg2 = 0;
        if (samplesRead <= static_cast<int32_T>
            (MPC_P.MATLABFunction5_max_iters_l) - 1) {
          dt = MPC_P.F_blue_X_nominal * sampleTime_1 / 2.0;
          ThrustPer_Sat[0] = dt;
          ThrustPer_Sat[1] = dt;
          sampleTime_1 = MPC_P.F_blue_Y_nominal * sampleTime_1 / 2.0;
          ThrustPer_Sat[2] = sampleTime_1;
          ThrustPer_Sat[3] = sampleTime_1;
          ThrustPer_Sat[4] = dt;
          ThrustPer_Sat[5] = dt;
          ThrustPer_Sat[6] = sampleTime_1;
          ThrustPer_Sat[7] = sampleTime_1;
          memset(&y[0], 0, sizeof(real_T) << 6U);
          for (i = 0; i < 8; i++) {
            y[i + (i << 3)] = ThrustPer_Sat[i];
          }

          for (rtemp = 0; rtemp < 3; rtemp++) {
            for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 8;
                 BLACK_Estimated_Covar_tmp++) {
              sampleTime_1 = 0.0;
              for (i = 0; i < 8; i++) {
                sampleTime_1 += rtb_H_tmp[3 * i + rtemp] * y
                  [(BLACK_Estimated_Covar_tmp << 3) + i];
              }

              rtb_H[rtemp + 3 * BLACK_Estimated_Covar_tmp] = sampleTime_1;
              tmp[BLACK_Estimated_Covar_tmp + (rtemp << 3)] = sampleTime_1;
            }
          }

          for (rtemp = 0; rtemp < 8; rtemp++) {
            rtb_y_eu = tmp[rtemp + 8];
            sampleTime_1 = tmp[rtemp];
            sampleTime_0 = tmp[rtemp + 16];
            for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 8;
                 BLACK_Estimated_Covar_tmp++) {
              y[rtemp + (BLACK_Estimated_Covar_tmp << 3)] = (rtb_H[3 *
                BLACK_Estimated_Covar_tmp + 1] * rtb_y_eu + rtb_H[3 *
                BLACK_Estimated_Covar_tmp] * sampleTime_1) + rtb_H[3 *
                BLACK_Estimated_Covar_tmp + 2] * sampleTime_0;
            }

            ThrustPer_Sat[rtemp] = (rtb_y_eu * rtb_TSamp_jb + sampleTime_1 *
              rtb_TSamp_e) + sampleTime_0 * rtb_TSamp_ne;
          }

          for (rtemp = 0; rtemp < 64; rtemp++) {
            tmp_0[rtemp] = 2.0 * y[rtemp];
          }

          for (rtemp = 0; rtemp < 8; rtemp++) {
            PWMs[rtemp] = -2.0 * ThrustPer_Sat[rtemp];
          }

          MPC_quadprog(tmp_0, PWMs, MPC_B.duty_cycles_k, ThrustPer_Sat,
                       &sampleTime_1, &sampleTime_0);
          rtb_TSamp_lb = MPC_maximum_h(ThrustPer_Sat);
          for (i = 0; i < 8; i++) {
            sampleTime_1 = ThrustPer_Sat[i];
            MPC_B.duty_cycles_k[i] = sampleTime_1;
            PWMs[i] = sampleTime_1;
            if (rtb_TSamp_lb > 1.0) {
              sampleTime_1 /= rtb_TSamp_lb;
              PWMs[i] = sampleTime_1;
            }

            x[i] = (sampleTime_1 > 0.0);
          }

          nz = x[0];
          for (rtemp = 0; rtemp < 7; rtemp++) {
            nz += x[rtemp + 1];
          }

          for (samplesRead_1 = 0; samplesRead_1 < 8; samplesRead_1++) {
            rtb_y_eu = PWMs[samplesRead_1];
            if (rtb_y_eu >= 0.0) {
              b_maxval[samplesRead_1] = rtb_y_eu;
            } else {
              b_maxval[samplesRead_1] = 0.0;
            }
          }

          rtb_y_eu = b_maxval[0];
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 7;
               BLACK_Estimated_Covar_tmp++) {
            rtb_y_eu += b_maxval[BLACK_Estimated_Covar_tmp + 1];
          }

          if (nz >= 1) {
            rtemp = nz;
          } else {
            rtemp = 1;
          }

          sampleTime_1 = rtb_y_eu / static_cast<real_T>(rtemp);
          if ((sampleTime_1 < 0.3) || (nz == 0)) {
            sampleTime_1 = 1.0;
          } else {
            sampleTime_1 = (0.6 - 2.0 * sampleTime_1) + 1.0;
            if (!(sampleTime_1 >= 0.5)) {
              sampleTime_1 = 0.5;
            }
          }

          sampleTime_0 = 0.0;
          for (r2 = 0; r2 < 8; r2++) {
            ARM_Path_idx_2 = ThrustPer_Sat[r2] - prev_duty_cycles[r2];
            prev_duty_cycles[r2] = ARM_Path_idx_2;
            ARM_Path_idx_2 = fabs(ARM_Path_idx_2);
            if (rtIsNaN(ARM_Path_idx_2)) {
              sampleTime_0 = (rtNaN);
            } else if (ARM_Path_idx_2 > sampleTime_0) {
              sampleTime_0 = ARM_Path_idx_2;
            }
          }

          if (sampleTime_0 < MPC_P.MATLABFunction5_tol_i) {
            dt = MPC_P.F_blue_X_nominal * sampleTime_1;
            ThrustPer_Sat[0] = dt;
            ThrustPer_Sat[1] = dt;
            sampleTime_1 *= MPC_P.F_blue_Y_nominal;
            ThrustPer_Sat[2] = sampleTime_1;
            ThrustPer_Sat[3] = sampleTime_1;
            ThrustPer_Sat[4] = dt;
            ThrustPer_Sat[5] = dt;
            ThrustPer_Sat[6] = sampleTime_1;
            ThrustPer_Sat[7] = sampleTime_1;
            memset(&y[0], 0, sizeof(real_T) << 6U);
            for (i = 0; i < 8; i++) {
              y[i + (i << 3)] = ThrustPer_Sat[i];
            }

            for (rtemp = 0; rtemp < 8; rtemp++) {
              for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
                   BLACK_Estimated_Covar_tmp++) {
                sampleTime_1 = 0.0;
                for (i = 0; i < 8; i++) {
                  sampleTime_1 += rtb_H_tmp[3 * i + BLACK_Estimated_Covar_tmp] *
                    y[(rtemp << 3) + i];
                }

                rtb_H[BLACK_Estimated_Covar_tmp + 3 * rtemp] = sampleTime_1;
              }
            }

            exitg2 = 1;
          } else {
            memcpy(&prev_duty_cycles[0], &ThrustPer_Sat[0], sizeof(real_T) << 3U);
            samplesRead++;
          }
        } else {
          dt = MPC_P.F_blue_X_nominal * sampleTime_1;
          ThrustPer_Sat[0] = dt;
          ThrustPer_Sat[1] = dt;
          sampleTime_1 *= MPC_P.F_blue_Y_nominal;
          ThrustPer_Sat[2] = sampleTime_1;
          ThrustPer_Sat[3] = sampleTime_1;
          ThrustPer_Sat[4] = dt;
          ThrustPer_Sat[5] = dt;
          ThrustPer_Sat[6] = sampleTime_1;
          ThrustPer_Sat[7] = sampleTime_1;
          memset(&y[0], 0, sizeof(real_T) << 6U);
          for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 8;
               BLACK_Estimated_Covar_tmp++) {
            y[BLACK_Estimated_Covar_tmp + (BLACK_Estimated_Covar_tmp << 3)] =
              ThrustPer_Sat[BLACK_Estimated_Covar_tmp];
          }

          for (rtemp = 0; rtemp < 8; rtemp++) {
            for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 3;
                 BLACK_Estimated_Covar_tmp++) {
              sampleTime_1 = 0.0;
              for (i = 0; i < 8; i++) {
                sampleTime_1 += rtb_H_tmp[3 * i + BLACK_Estimated_Covar_tmp] *
                  y[(rtemp << 3) + i];
              }

              rtb_H[BLACK_Estimated_Covar_tmp + 3 * rtemp] = sampleTime_1;
            }
          }

          exitg2 = 1;
        }
      } while (exitg2 == 0);

      // MATLAB Function: '<S304>/MATLAB Function1'
      MPC_MATLABFunction1_i(MPC_B.duty_cycles_k, rtb_ThrustPer_Final_n);

      // Outputs for Enabled SubSystem: '<S306>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S311>/Enable'

      if (MPC_DW.Delay_DSTATE_ik >= 1.0 / MPC_P.PWMFreq) {
        // SignalConversion generated from: '<S311>/In1' incorporates:
        //   DataStoreRead: '<S306>/Data Store Read'

        MPC_B.In1_g = MPC_DW.Univ_Time;
      }

      // End of Outputs for SubSystem: '<S306>/Enabled Subsystem'

      // Sum: '<S306>/Subtract' incorporates:
      //   Constant: '<S306>/Constant1'
      //   DataStoreRead: '<S306>/Data Store Read'
      //   Delay: '<S306>/Delay'
      //   RelationalOperator: '<S306>/Relational Operator1'

      MPC_DW.Delay_DSTATE_ik = MPC_DW.Univ_Time - MPC_B.In1_g;

      // Outputs for Enabled SubSystem: '<S306>/Enabled Subsystem1' incorporates:
      //   EnablePort: '<S312>/Enable'

      if (MPC_DW.Delay_DSTATE_ik == MPC_P.Constant2_Value_ab) {
        // SignalConversion generated from: '<S312>/ThrustPer_Final'
        memcpy(&MPC_B.ThrustPer_Final_h[0], &rtb_ThrustPer_Final_n[0], sizeof
               (real_T) << 3U);
      }

      // End of Outputs for SubSystem: '<S306>/Enabled Subsystem1'

      // Product: '<S304>/Product1' incorporates:
      //   Constant: '<S306>/Constant2'
      //   Delay: '<S306>/Delay'
      //   RelationalOperator: '<S306>/Relational Operator2'

      for (rtemp = 0; rtemp < 3; rtemp++) {
        rtb_TSamp_ne = 0.0;
        for (BLACK_Estimated_Covar_tmp = 0; BLACK_Estimated_Covar_tmp < 8;
             BLACK_Estimated_Covar_tmp++) {
          rtb_TSamp_ne += rtb_H[3 * BLACK_Estimated_Covar_tmp + rtemp] *
            MPC_B.ThrustPer_Final_h[BLACK_Estimated_Covar_tmp];
        }

        BLACK_Controls[rtemp] = rtb_TSamp_ne;
      }

      // End of Product: '<S304>/Product1'

      // DataStoreWrite: '<S290>/Data Store Write3' incorporates:
      //   Product: '<S310>/Rotate F_b to F_I'

      MPC_DW.BLUE_Saturated_Controls[0] = rtb_MatrixConcatenate[0] *
        BLACK_Controls[0] + BLACK_Controls[1] * rtb_MatrixConcatenate[2];
      MPC_DW.BLUE_Saturated_Controls[1] = BLACK_Controls[0] *
        rtb_MatrixConcatenate[1] + BLACK_Controls[1] * rtb_MatrixConcatenate[3];
      MPC_DW.BLUE_Saturated_Controls[2] = BLACK_Controls[2];

      // End of Outputs for SubSystem: '<S18>/Change BLUE Behavior'
    }

    // End of If: '<S18>/This IF block determines whether or not to run the BLUE sim//exp' 

    // SignalConversion generated from: '<S18>/UDP Send' incorporates:
    //   Constant: '<S18>/PWM Frequency'
    //   Constant: '<S18>/Safety Number'
    //   Gain: '<S18>/Gain'
    //   Gain: '<S18>/Gain1'
    //   Gain: '<S18>/Gain2'
    //   Gain: '<S18>/Gain3'
    //   Gain: '<S18>/Gain4'
    //   Gain: '<S18>/Gain5'
    //   Gain: '<S18>/Gain6'
    //   Gain: '<S18>/Gain7'
    //   Sum: '<S18>/Sum'
    //   Sum: '<S18>/Sum1'
    //   Sum: '<S18>/Sum2'
    //   Sum: '<S18>/Sum3'
    //   Sum: '<S18>/Sum4'
    //   Sum: '<S18>/Sum5'
    //   Sum: '<S18>/Sum6'
    //   Sum: '<S18>/Sum7'

    MPC_B.TmpSignalConversionAtUDPSendInp[0] = MPC_P.SafetyNumber_Value;
    MPC_B.TmpSignalConversionAtUDPSendInp[1] = MPC_P.PWMFreq;
    MPC_B.TmpSignalConversionAtUDPSendInp[2] = ((MPC_B.duty_cycles[0] +
      MPC_B.duty_cycles_n[0]) + MPC_B.duty_cycles_k[0]) * MPC_P.Gain_Gain;
    MPC_B.TmpSignalConversionAtUDPSendInp[3] = ((MPC_B.duty_cycles[1] +
      MPC_B.duty_cycles_n[1]) + MPC_B.duty_cycles_k[1]) * MPC_P.Gain1_Gain;
    MPC_B.TmpSignalConversionAtUDPSendInp[4] = ((MPC_B.duty_cycles[2] +
      MPC_B.duty_cycles_n[2]) + MPC_B.duty_cycles_k[2]) * MPC_P.Gain2_Gain;
    MPC_B.TmpSignalConversionAtUDPSendInp[5] = ((MPC_B.duty_cycles[3] +
      MPC_B.duty_cycles_n[3]) + MPC_B.duty_cycles_k[3]) * MPC_P.Gain3_Gain;
    MPC_B.TmpSignalConversionAtUDPSendInp[6] = ((MPC_B.duty_cycles[4] +
      MPC_B.duty_cycles_n[4]) + MPC_B.duty_cycles_k[4]) * MPC_P.Gain4_Gain;
    MPC_B.TmpSignalConversionAtUDPSendInp[7] = ((MPC_B.duty_cycles[5] +
      MPC_B.duty_cycles_n[5]) + MPC_B.duty_cycles_k[5]) * MPC_P.Gain5_Gain;
    MPC_B.TmpSignalConversionAtUDPSendInp[8] = ((MPC_B.duty_cycles[6] +
      MPC_B.duty_cycles_n[6]) + MPC_B.duty_cycles_k[6]) * MPC_P.Gain6_Gain_m;
    MPC_B.TmpSignalConversionAtUDPSendInp[9] = ((MPC_B.duty_cycles[7] +
      MPC_B.duty_cycles_n[7]) + MPC_B.duty_cycles_k[7]) * MPC_P.Gain7_Gain_n;
  }

  {
    int32_T i;
    char_T *sErr;

    // Update for Delay: '<S19>/Delay'
    MPC_DW.Delay_DSTATE = rtb_DataStoreRead6;

    // Update for Delay: '<S276>/Delay2'
    memcpy(&MPC_DW.Delay2_DSTATE[0], &rtb_DataStoreRead_p[0], 9U * sizeof(real_T));

    // Update for Delay: '<S268>/Delay1' incorporates:
    //   DataStoreWrite: '<S12>/Data Store Write1'

    for (i = 0; i < 6; i++) {
      MPC_DW.Delay1_DSTATE[i] = MPC_DW.RED_Estimated_States[i];
    }

    // End of Update for Delay: '<S268>/Delay1'

    // Update for Delay: '<S268>/Delay'
    memcpy(&MPC_DW.Delay_DSTATE_i[0], &MPC_B.P[0], 36U * sizeof(real_T));

    // Update for Delay: '<S268>/Delay2'
    memcpy(&MPC_DW.Delay2_DSTATE_k[0], &MPC_B.V[0], 9U * sizeof(real_T));

    // Update for Delay: '<S270>/Delay2'
    memcpy(&MPC_DW.Delay2_DSTATE_p[0], &rtb_DataStoreRead1_f[0], 9U * sizeof
           (real_T));

    // Update for Delay: '<S266>/Delay1'
    for (i = 0; i < 6; i++) {
      MPC_DW.Delay1_DSTATE_c[i] = MPC_B.x_o[i];
    }

    // End of Update for Delay: '<S266>/Delay1'

    // Update for Delay: '<S266>/Delay'
    memcpy(&MPC_DW.Delay_DSTATE_n[0], &MPC_B.P_f[0], 36U * sizeof(real_T));

    // Update for Delay: '<S266>/Delay2'
    memcpy(&MPC_DW.Delay2_DSTATE_j[0], &MPC_B.V_gq[0], 9U * sizeof(real_T));

    // Update for Delay: '<S273>/Delay2'
    memcpy(&MPC_DW.Delay2_DSTATE_f[0], &rtb_DataStoreRead2_k[0], 9U * sizeof
           (real_T));

    // Update for Delay: '<S267>/Delay1'
    for (i = 0; i < 6; i++) {
      MPC_DW.Delay1_DSTATE_g[i] = MPC_B.x_c[i];
    }

    // End of Update for Delay: '<S267>/Delay1'

    // Update for Delay: '<S267>/Delay'
    memcpy(&MPC_DW.Delay_DSTATE_h[0], &MPC_B.P_g[0], 36U * sizeof(real_T));

    // Update for Delay: '<S267>/Delay2'
    memcpy(&MPC_DW.Delay2_DSTATE_n[0], &MPC_B.V_g[0], 9U * sizeof(real_T));

    // Update for If: '<S11>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 
    if (MPC_DW.Ifperforminganexperimentgrabthe == 0) {
      // Update for IfAction SubSystem: '<S11>/Use Hardware to Obtain States' incorporates:
      //   ActionPort: '<S223>/Action Port'

      // Update for Delay: '<S233>/Delay2'
      MPC_DW.Delay2_DSTATE_jo = MPC_B.ReceivePhaseSpaceData_o1[0];

      // Update for Delay: '<S233>/Delay1'
      MPC_DW.Delay1_DSTATE_i = MPC_B.ConvertBLAXfrommmtom;

      // Update for Enabled SubSystem: '<S235>/Enabled Subsystem'
      MPC_EnabledSubsystem_n_Update(MPC_B.dy_i, &MPC_B.EnabledSubsystem_n,
        &MPC_DW.EnabledSubsystem_n);

      // End of Update for SubSystem: '<S235>/Enabled Subsystem'

      // Update for Delay: '<S234>/Delay1'
      MPC_DW.Delay1_DSTATE_b[0] = MPC_B.dy_i[0];
      MPC_DW.Delay1_DSTATE_b[1] = MPC_B.dy_i[1];
      MPC_DW.Delay1_DSTATE_b[2] = MPC_B.dy_i[2];

      // Update for Enabled SubSystem: '<S234>/Enabled Subsystem'
      MPC_EnabledSubsystem_Update(MPC_B.dy_k, &MPC_B.EnabledSubsystem_m,
        &MPC_DW.EnabledSubsystem_m);

      // End of Update for SubSystem: '<S234>/Enabled Subsystem'

      // Update for Delay: '<S243>/Delay2'
      MPC_DW.Delay2_DSTATE_l = MPC_B.ReceivePhaseSpaceData_o1[0];

      // Update for Delay: '<S243>/Delay1'
      MPC_DW.Delay1_DSTATE_l = MPC_B.ConvertBLUXfrommmtom;

      // Update for Enabled SubSystem: '<S245>/Enabled Subsystem'
      MPC_EnabledSubsystem_n_Update(MPC_B.dy_c, &MPC_B.EnabledSubsystem_g,
        &MPC_DW.EnabledSubsystem_g);

      // End of Update for SubSystem: '<S245>/Enabled Subsystem'

      // Update for Delay: '<S244>/Delay1'
      MPC_DW.Delay1_DSTATE_lv[0] = MPC_B.dy_c[0];
      MPC_DW.Delay1_DSTATE_lv[1] = MPC_B.dy_c[1];
      MPC_DW.Delay1_DSTATE_lv[2] = MPC_B.dy_c[2];

      // Update for Enabled SubSystem: '<S244>/Enabled Subsystem'
      MPC_EnabledSubsystem_Update(MPC_B.dy_e, &MPC_B.EnabledSubsystem_l,
        &MPC_DW.EnabledSubsystem_l);

      // End of Update for SubSystem: '<S244>/Enabled Subsystem'

      // Update for Delay: '<S253>/Delay2'
      MPC_DW.Delay2_DSTATE_l0 = MPC_B.ReceivePhaseSpaceData_o1[0];

      // Update for Delay: '<S253>/Delay1'
      MPC_DW.Delay1_DSTATE_ld = MPC_B.ConvertREDXfrommmtom;

      // Update for Enabled SubSystem: '<S255>/Enabled Subsystem'
      MPC_EnabledSubsystem_n_Update(MPC_B.dy, &MPC_B.EnabledSubsystem_a,
        &MPC_DW.EnabledSubsystem_a);

      // End of Update for SubSystem: '<S255>/Enabled Subsystem'

      // Update for Delay: '<S254>/Delay1'
      MPC_DW.Delay1_DSTATE_cq[0] = MPC_B.dy[0];
      MPC_DW.Delay1_DSTATE_cq[1] = MPC_B.dy[1];
      MPC_DW.Delay1_DSTATE_cq[2] = MPC_B.dy[2];

      // Update for Enabled SubSystem: '<S254>/Enabled Subsystem'
      MPC_EnabledSubsystem_Update(MPC_B.dy_l, &MPC_B.EnabledSubsystem_k,
        &MPC_DW.EnabledSubsystem_k);

      // End of Update for SubSystem: '<S254>/Enabled Subsystem'

      // Update for Delay: '<S229>/Delay'
      MPC_DW.Delay_DSTATE_ip[0] = MPC_DW.Delay_DSTATE_ip[1];

      // Update for Delay: '<S229>/Delay1'
      MPC_DW.Delay1_DSTATE_h[0] = MPC_DW.Delay1_DSTATE_h[1];

      // Update for Delay: '<S229>/Delay2'
      MPC_DW.Delay2_DSTATE_hq[0] = MPC_DW.Delay2_DSTATE_hq[1];

      // Update for Delay: '<S229>/Delay'
      MPC_DW.Delay_DSTATE_ip[1] = MPC_DW.Delay_DSTATE_ip[2];

      // Update for Delay: '<S229>/Delay1'
      MPC_DW.Delay1_DSTATE_h[1] = MPC_DW.Delay1_DSTATE_h[2];

      // Update for Delay: '<S229>/Delay2'
      MPC_DW.Delay2_DSTATE_hq[1] = MPC_DW.Delay2_DSTATE_hq[2];

      // Update for Delay: '<S229>/Delay'
      MPC_DW.Delay_DSTATE_ip[2] = MPC_DW.Delay_DSTATE_ip[3];

      // Update for Delay: '<S229>/Delay1'
      MPC_DW.Delay1_DSTATE_h[2] = MPC_DW.Delay1_DSTATE_h[3];

      // Update for Delay: '<S229>/Delay2'
      MPC_DW.Delay2_DSTATE_hq[2] = MPC_DW.Delay2_DSTATE_hq[3];

      // Update for Delay: '<S229>/Delay'
      MPC_DW.Delay_DSTATE_ip[3] = MPC_DW.Delay_DSTATE_ip[4];

      // Update for Delay: '<S229>/Delay1'
      MPC_DW.Delay1_DSTATE_h[3] = MPC_DW.Delay1_DSTATE_h[4];

      // Update for Delay: '<S229>/Delay2'
      MPC_DW.Delay2_DSTATE_hq[3] = MPC_DW.Delay2_DSTATE_hq[4];

      // Update for Delay: '<S229>/Delay'
      MPC_DW.Delay_DSTATE_ip[4] = MPC_B.UDPReceive_o1;

      // Update for Delay: '<S229>/Delay1'
      MPC_DW.Delay1_DSTATE_h[4] = MPC_B.UDPReceive2_o1;

      // Update for Delay: '<S229>/Delay2'
      MPC_DW.Delay2_DSTATE_hq[4] = MPC_B.UDPReceive3_o1;

      // Update for Enabled SubSystem: '<S228>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S230>/Enable'

      if (MPC_B.RelationalOperator1) {
        // Update for Memory: '<S230>/Memory'
        MPC_DW.Memory_PreviousInput = MPC_B.Clock;
      }

      // End of Update for SubSystem: '<S228>/Enabled Subsystem'
      // End of Update for SubSystem: '<S11>/Use Hardware to Obtain States'
    }

    // End of Update for If: '<S11>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 

    // Update for S-Function (sdspToNetwork): '<S18>/UDP Send' incorporates:
    //   SignalConversion generated from: '<S18>/UDP Send'

    sErr = GetErrorBuffer(&MPC_DW.UDPSend_NetworkLib[0U]);
    LibUpdate_Network(&MPC_DW.UDPSend_NetworkLib[0U],
                      &MPC_B.TmpSignalConversionAtUDPSendInp[0U], 10);
    if (*sErr != 0) {
      MPC_M->setErrorStatus(sErr);
      MPC_M->setStopRequested(1);
    }

    // End of Update for S-Function (sdspToNetwork): '<S18>/UDP Send'
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  MPC_M->Timing.t[0] =
    ((time_T)(++MPC_M->Timing.clockTick0)) * MPC_M->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.05s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.05, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    MPC_M->Timing.clockTick1++;
  }
}

// Model initialize function
void MPC_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&MPC_M->solverInfo, &MPC_M->Timing.simTimeStep);
    rtsiSetTPtr(&MPC_M->solverInfo, MPC_M->getTPtrPtr());
    rtsiSetStepSizePtr(&MPC_M->solverInfo, &MPC_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&MPC_M->solverInfo, MPC_M->getErrorStatusPtr());
    rtsiSetRTModelPtr(&MPC_M->solverInfo, MPC_M);
  }

  rtsiSetSimTimeStep(&MPC_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&MPC_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&MPC_M->solverInfo, false);
  rtsiSetSolverName(&MPC_M->solverInfo,"FixedStepDiscrete");
  MPC_M->setTPtr(&MPC_M->Timing.tArray[0]);
  MPC_M->Timing.stepSize0 = 0.05;

  {
    real_T sampleTime;
    real_T sampleTime_0;
    real_T sampleTime_1;
    int32_T i;
    char_T *sErr;
    static const uint32_T tmp[625] = { 5489U, 1301868182U, 2938499221U,
      2950281878U, 1875628136U, 751856242U, 944701696U, 2243192071U, 694061057U,
      219885934U, 2066767472U, 3182869408U, 485472502U, 2336857883U, 1071588843U,
      3418470598U, 951210697U, 3693558366U, 2923482051U, 1793174584U,
      2982310801U, 1586906132U, 1951078751U, 1808158765U, 1733897588U,
      431328322U, 4202539044U, 530658942U, 1714810322U, 3025256284U, 3342585396U,
      1937033938U, 2640572511U, 1654299090U, 3692403553U, 4233871309U,
      3497650794U, 862629010U, 2943236032U, 2426458545U, 1603307207U,
      1133453895U, 3099196360U, 2208657629U, 2747653927U, 931059398U, 761573964U,
      3157853227U, 785880413U, 730313442U, 124945756U, 2937117055U, 3295982469U,
      1724353043U, 3021675344U, 3884886417U, 4010150098U, 4056961966U,
      699635835U, 2681338818U, 1339167484U, 720757518U, 2800161476U, 2376097373U,
      1532957371U, 3902664099U, 1238982754U, 3725394514U, 3449176889U,
      3570962471U, 4287636090U, 4087307012U, 3603343627U, 202242161U,
      2995682783U, 1620962684U, 3704723357U, 371613603U, 2814834333U,
      2111005706U, 624778151U, 2094172212U, 4284947003U, 1211977835U, 991917094U,
      1570449747U, 2962370480U, 1259410321U, 170182696U, 146300961U, 2836829791U,
      619452428U, 2723670296U, 1881399711U, 1161269684U, 1675188680U,
      4132175277U, 780088327U, 3409462821U, 1036518241U, 1834958505U,
      3048448173U, 161811569U, 618488316U, 44795092U, 3918322701U, 1924681712U,
      3239478144U, 383254043U, 4042306580U, 2146983041U, 3992780527U,
      3518029708U, 3545545436U, 3901231469U, 1896136409U, 2028528556U,
      2339662006U, 501326714U, 2060962201U, 2502746480U, 561575027U, 581893337U,
      3393774360U, 1778912547U, 3626131687U, 2175155826U, 319853231U, 986875531U,
      819755096U, 2915734330U, 2688355739U, 3482074849U, 2736559U, 2296975761U,
      1029741190U, 2876812646U, 690154749U, 579200347U, 4027461746U, 1285330465U,
      2701024045U, 4117700889U, 759495121U, 3332270341U, 2313004527U,
      2277067795U, 4131855432U, 2722057515U, 1264804546U, 3848622725U,
      2211267957U, 4100593547U, 959123777U, 2130745407U, 3194437393U, 486673947U,
      1377371204U, 17472727U, 352317554U, 3955548058U, 159652094U, 1232063192U,
      3835177280U, 49423123U, 3083993636U, 733092U, 2120519771U, 2573409834U,
      1112952433U, 3239502554U, 761045320U, 1087580692U, 2540165110U, 641058802U,
      1792435497U, 2261799288U, 1579184083U, 627146892U, 2165744623U,
      2200142389U, 2167590760U, 2381418376U, 1793358889U, 3081659520U,
      1663384067U, 2009658756U, 2689600308U, 739136266U, 2304581039U,
      3529067263U, 591360555U, 525209271U, 3131882996U, 294230224U, 2076220115U,
      3113580446U, 1245621585U, 1386885462U, 3203270426U, 123512128U, 12350217U,
      354956375U, 4282398238U, 3356876605U, 3888857667U, 157639694U, 2616064085U,
      1563068963U, 2762125883U, 4045394511U, 4180452559U, 3294769488U,
      1684529556U, 1002945951U, 3181438866U, 22506664U, 691783457U, 2685221343U,
      171579916U, 3878728600U, 2475806724U, 2030324028U, 3331164912U,
      1708711359U, 1970023127U, 2859691344U, 2588476477U, 2748146879U,
      136111222U, 2967685492U, 909517429U, 2835297809U, 3206906216U, 3186870716U,
      341264097U, 2542035121U, 3353277068U, 548223577U, 3170936588U, 1678403446U,
      297435620U, 2337555430U, 466603495U, 1132321815U, 1208589219U, 696392160U,
      894244439U, 2562678859U, 470224582U, 3306867480U, 201364898U, 2075966438U,
      1767227936U, 2929737987U, 3674877796U, 2654196643U, 3692734598U,
      3528895099U, 2796780123U, 3048728353U, 842329300U, 191554730U, 2922459673U,
      3489020079U, 3979110629U, 1022523848U, 2202932467U, 3583655201U,
      3565113719U, 587085778U, 4176046313U, 3013713762U, 950944241U, 396426791U,
      3784844662U, 3477431613U, 3594592395U, 2782043838U, 3392093507U,
      3106564952U, 2829419931U, 1358665591U, 2206918825U, 3170783123U, 31522386U,
      2988194168U, 1782249537U, 1105080928U, 843500134U, 1225290080U,
      1521001832U, 3605886097U, 2802786495U, 2728923319U, 3996284304U,
      903417639U, 1171249804U, 1020374987U, 2824535874U, 423621996U, 1988534473U,
      2493544470U, 1008604435U, 1756003503U, 1488867287U, 1386808992U,
      732088248U, 1780630732U, 2482101014U, 976561178U, 1543448953U, 2602866064U,
      2021139923U, 1952599828U, 2360242564U, 2117959962U, 2753061860U,
      2388623612U, 4138193781U, 2962920654U, 2284970429U, 766920861U,
      3457264692U, 2879611383U, 815055854U, 2332929068U, 1254853997U,
      3740375268U, 3799380844U, 4091048725U, 2006331129U, 1982546212U,
      686850534U, 1907447564U, 2682801776U, 2780821066U, 998290361U, 1342433871U,
      4195430425U, 607905174U, 3902331779U, 2454067926U, 1708133115U,
      1170874362U, 2008609376U, 3260320415U, 2211196135U, 433538229U,
      2728786374U, 2189520818U, 262554063U, 1182318347U, 3710237267U,
      1221022450U, 715966018U, 2417068910U, 2591870721U, 2870691989U,
      3418190842U, 4238214053U, 1540704231U, 1575580968U, 2095917976U,
      4078310857U, 2313532447U, 2110690783U, 4056346629U, 4061784526U,
      1123218514U, 551538993U, 597148360U, 4120175196U, 3581618160U, 3181170517U,
      422862282U, 3227524138U, 1713114790U, 662317149U, 1230418732U, 928171837U,
      1324564878U, 1928816105U, 1786535431U, 2878099422U, 3290185549U,
      539474248U, 1657512683U, 552370646U, 1671741683U, 3655312128U, 1552739510U,
      2605208763U, 1441755014U, 181878989U, 3124053868U, 1447103986U,
      3183906156U, 1728556020U, 3502241336U, 3055466967U, 1013272474U,
      818402132U, 1715099063U, 2900113506U, 397254517U, 4194863039U, 1009068739U,
      232864647U, 2540223708U, 2608288560U, 2415367765U, 478404847U, 3455100648U,
      3182600021U, 2115988978U, 434269567U, 4117179324U, 3461774077U, 887256537U,
      3545801025U, 286388911U, 3451742129U, 1981164769U, 786667016U, 3310123729U,
      3097811076U, 2224235657U, 2959658883U, 3370969234U, 2514770915U,
      3345656436U, 2677010851U, 2206236470U, 271648054U, 2342188545U,
      4292848611U, 3646533909U, 3754009956U, 3803931226U, 4160647125U,
      1477814055U, 4043852216U, 1876372354U, 3133294443U, 3871104810U,
      3177020907U, 2074304428U, 3479393793U, 759562891U, 164128153U, 1839069216U,
      2114162633U, 3989947309U, 3611054956U, 1333547922U, 835429831U, 494987340U,
      171987910U, 1252001001U, 370809172U, 3508925425U, 2535703112U, 1276855041U,
      1922855120U, 835673414U, 3030664304U, 613287117U, 171219893U, 3423096126U,
      3376881639U, 2287770315U, 1658692645U, 1262815245U, 3957234326U,
      1168096164U, 2968737525U, 2655813712U, 2132313144U, 3976047964U,
      326516571U, 353088456U, 3679188938U, 3205649712U, 2654036126U, 1249024881U,
      880166166U, 691800469U, 2229503665U, 1673458056U, 4032208375U, 1851778863U,
      2563757330U, 376742205U, 1794655231U, 340247333U, 1505873033U, 396524441U,
      879666767U, 3335579166U, 3260764261U, 3335999539U, 506221798U, 4214658741U,
      975887814U, 2080536343U, 3360539560U, 571586418U, 138896374U, 4234352651U,
      2737620262U, 3928362291U, 1516365296U, 38056726U, 3599462320U, 3585007266U,
      3850961033U, 471667319U, 1536883193U, 2310166751U, 1861637689U,
      2530999841U, 4139843801U, 2710569485U, 827578615U, 2012334720U,
      2907369459U, 3029312804U, 2820112398U, 1965028045U, 35518606U, 2478379033U,
      643747771U, 1924139484U, 4123405127U, 3811735531U, 3429660832U,
      3285177704U, 1948416081U, 1311525291U, 1183517742U, 1739192232U,
      3979815115U, 2567840007U, 4116821529U, 213304419U, 4125718577U,
      1473064925U, 2442436592U, 1893310111U, 4195361916U, 3747569474U,
      828465101U, 2991227658U, 750582866U, 1205170309U, 1409813056U, 678418130U,
      1171531016U, 3821236156U, 354504587U, 4202874632U, 3882511497U,
      1893248677U, 1903078632U, 26340130U, 2069166240U, 3657122492U, 3725758099U,
      831344905U, 811453383U, 3447711422U, 2434543565U, 4166886888U, 3358210805U,
      4142984013U, 2988152326U, 3527824853U, 982082992U, 2809155763U, 190157081U,
      3340214818U, 2365432395U, 2548636180U, 2894533366U, 3474657421U,
      2372634704U, 2845748389U, 43024175U, 2774226648U, 1987702864U, 3186502468U,
      453610222U, 4204736567U, 1392892630U, 2471323686U, 2470534280U,
      3541393095U, 4269885866U, 3909911300U, 759132955U, 1482612480U, 667715263U,
      1795580598U, 2337923983U, 3390586366U, 581426223U, 1515718634U, 476374295U,
      705213300U, 363062054U, 2084697697U, 2407503428U, 2292957699U, 2426213835U,
      2199989172U, 1987356470U, 4026755612U, 2147252133U, 270400031U,
      1367820199U, 2369854699U, 2844269403U, 79981964U, 624U };

    // Start for If: '<S11>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 
    MPC_DW.Ifperforminganexperimentgrabthe = -1;

    // Start for S-Function (sdspToNetwork): '<S18>/UDP Send'
    sErr = GetErrorBuffer(&MPC_DW.UDPSend_NetworkLib[0U]);
    CreateUDPInterface(&MPC_DW.UDPSend_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&MPC_DW.UDPSend_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "127.0.0.1", MPC_P.UDPSend_Port_g, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&MPC_DW.UDPSend_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&MPC_DW.UDPSend_NetworkLib[0U]);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S18>/UDP Send'

    // Start for DataStoreMemory: '<Root>/Data Store Memory13'
    MPC_DW.Vis_q[0] = MPC_P.DataStoreMemory13_InitialValue[0];
    MPC_DW.Vis_q[1] = MPC_P.DataStoreMemory13_InitialValue[1];
    MPC_DW.Vis_q[2] = MPC_P.DataStoreMemory13_InitialValue[2];
    MPC_DW.Vis_q[3] = MPC_P.DataStoreMemory13_InitialValue[3];

    // Start for DataStoreMemory: '<Root>/Data Store Memory14'
    memcpy(&MPC_DW.Vis_R[0], &MPC_P.DataStoreMemory14_InitialValue[0], 9U *
           sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory15'
    MPC_DW.Vis_x[0] = MPC_P.DataStoreMemory15_InitialValue[0];
    MPC_DW.Vis_x[1] = MPC_P.DataStoreMemory15_InitialValue[1];
    MPC_DW.Vis_x[2] = MPC_P.DataStoreMemory15_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Data Store Memory17'
    memcpy(&MPC_DW.QMEKFx[0], &MPC_P.DataStoreMemory17_InitialValue[0], 13U *
           sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory18'
    memcpy(&MPC_DW.QMEKFP[0], &MPC_P.DataStoreMemory18_InitialValue[0], 144U *
           sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory19'
    MPC_DW.QMEKFt = MPC_P.DataStoreMemory19_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory20'
    memcpy(&MPC_DW.STQMEKFx[0], &MPC_P.DataStoreMemory20_InitialValue[0], 13U *
           sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory21'
    memcpy(&MPC_DW.STQMEKFP[0], &MPC_P.DataStoreMemory21_InitialValue[0], 144U *
           sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory22'
    MPC_DW.STQMEKFt = MPC_P.DataStoreMemory22_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory23'
    memcpy(&MPC_DW.DQMEKFx[0], &MPC_P.DataStoreMemory23_InitialValue[0], 13U *
           sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory24'
    memcpy(&MPC_DW.DQMEKFP[0], &MPC_P.DataStoreMemory24_InitialValue[0], 144U *
           sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory25'
    MPC_DW.DQMEKFt = MPC_P.DataStoreMemory25_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory26'
    memcpy(&MPC_DW.STDQMEKFx[0], &MPC_P.DataStoreMemory26_InitialValue[0], 13U *
           sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory27'
    memcpy(&MPC_DW.STDQMEKFP[0], &MPC_P.DataStoreMemory27_InitialValue[0], 144U *
           sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory28'
    MPC_DW.STDQMEKFt = MPC_P.DataStoreMemory28_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory29'
    memcpy(&MPC_DW.RMEKFx[0], &MPC_P.DataStoreMemory29_InitialValue[0], 13U *
           sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory30'
    memcpy(&MPC_DW.RMEKFP[0], &MPC_P.DataStoreMemory30_InitialValue[0], 144U *
           sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory31'
    MPC_DW.RMEKFt = MPC_P.DataStoreMemory31_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory32'
    memcpy(&MPC_DW.STRMEKFx[0], &MPC_P.DataStoreMemory32_InitialValue[0], 13U *
           sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory33'
    memcpy(&MPC_DW.STRMEKFP[0], &MPC_P.DataStoreMemory33_InitialValue[0], 144U *
           sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory34'
    MPC_DW.STRMEKFt = MPC_P.DataStoreMemory34_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory38'
    memcpy(&MPC_DW.RMEKFR[0], &MPC_P.DataStoreMemory38_InitialValue[0], 9U *
           sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory39'
    memcpy(&MPC_DW.STRMEKFR[0], &MPC_P.DataStoreMemory39_InitialValue[0], 9U *
           sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory40'
    MPC_DW.Conf = MPC_P.DataStoreMemory40_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory41'
    MPC_DW.Vis_x_zoh[0] = MPC_P.DataStoreMemory41_InitialValue[0];
    MPC_DW.Vis_x_zoh[1] = MPC_P.DataStoreMemory41_InitialValue[1];
    MPC_DW.Vis_x_zoh[2] = MPC_P.DataStoreMemory41_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Data Store Memory43'
    MPC_DW.Conf_zoh = MPC_P.DataStoreMemory43_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory45'
    MPC_DW.Vis_q_zoh[0] = MPC_P.DataStoreMemory45_InitialValue[0];
    MPC_DW.Vis_q_zoh[1] = MPC_P.DataStoreMemory45_InitialValue[1];
    MPC_DW.Vis_q_zoh[2] = MPC_P.DataStoreMemory45_InitialValue[2];
    MPC_DW.Vis_q_zoh[3] = MPC_P.DataStoreMemory45_InitialValue[3];

    // Start for DataStoreMemory: '<Root>/Data Store Memory49'
    MPC_DW.CNNError[0] = MPC_P.DataStoreMemory49_InitialValue[0];
    MPC_DW.CNNError[1] = MPC_P.DataStoreMemory49_InitialValue[1];
    MPC_DW.CNNError[2] = MPC_P.DataStoreMemory49_InitialValue[2];
    for (i = 0; i < 6; i++) {
      // Start for DataStoreMemory: '<Root>/Data Store Memory47'
      MPC_DW.QMEKFerror[i] = MPC_P.DataStoreMemory47_InitialValue[i];

      // Start for DataStoreMemory: '<Root>/Data Store Memory48'
      MPC_DW.STQMEKFerror[i] = MPC_P.DataStoreMemory48_InitialValue[i];

      // Start for DataStoreMemory: '<Root>/Data Store Memory50'
      MPC_DW.RMEKFerror[i] = MPC_P.DataStoreMemory50_InitialValue[i];

      // Start for DataStoreMemory: '<Root>/Data Store Memory51'
      MPC_DW.STRMEKFerror[i] = MPC_P.DataStoreMemory51_InitialValue[i];

      // Start for DataStoreMemory: '<Root>/Data Store Memory52'
      MPC_DW.DQMEKFerror[i] = MPC_P.DataStoreMemory52_InitialValue[i];

      // Start for DataStoreMemory: '<Root>/Data Store Memory53'
      MPC_DW.STDQMEKFerror[i] = MPC_P.DataStoreMemory53_InitialValue[i];
    }

    // Start for DataStoreMemory: '<Root>/Data Store Memory57'
    MPC_DW.QMEKFNIS = MPC_P.DataStoreMemory57_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory58'
    MPC_DW.STQMEKFNIS = MPC_P.DataStoreMemory58_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory59'
    MPC_DW.STRMEKFNIS = MPC_P.DataStoreMemory59_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory60'
    MPC_DW.RMEKFNIS = MPC_P.DataStoreMemory60_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory61'
    MPC_DW.DQMEKFNIS = MPC_P.DataStoreMemory61_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory62'
    MPC_DW.STDQMEKFNIS = MPC_P.DataStoreMemory62_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz1'
    MPC_DW.BLUE_Control_Law_Enabler = MPC_P.RED_Tz1_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz15'
    MPC_DW.ARM_Control_Mode = MPC_P.RED_Tz15_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz20'
    MPC_DW.RED_Control_Law_Enabler = MPC_P.RED_Tz20_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz25'
    MPC_DW.RED_Path_Planner_Selection = MPC_P.RED_Tz25_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz3'
    strncpy(&MPC_DW.RED_Logger[0], &MPC_P.RED_Tz3_InitialValue[0], 255U);
    MPC_DW.RED_Logger[255] = '\x00';

    // Start for DataStoreMemory: '<Root>/RED_Tz38'
    MPC_DW.ARM_Control_Law_Enabler = MPC_P.RED_Tz38_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz7'
    MPC_DW.Float_State = MPC_P.RED_Tz7_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz8'
    MPC_DW.BLACK_Control_Law_Enabler = MPC_P.RED_Tz8_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz9'
    MPC_DW.BLACK_Path_Planner_Selection = MPC_P.RED_Tz9_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time'
    MPC_DW.Univ_Time = MPC_P.Universal_Time_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time10'
    memcpy(&MPC_DW.BLACK_Measured_States[0],
           &MPC_P.Universal_Time10_InitialValue[0], 9U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Universal_Time14'
    MPC_DW.BLUE_Thruster_ON_Count = MPC_P.Universal_Time14_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time13'
    MPC_DW.BLUE_Desired_States[0] = MPC_P.Universal_Time13_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time15'
    MPC_DW.BLACK_Saturated_Controls[0] = MPC_P.Universal_Time15_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time13'
    MPC_DW.BLUE_Desired_States[1] = MPC_P.Universal_Time13_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time15'
    MPC_DW.BLACK_Saturated_Controls[1] = MPC_P.Universal_Time15_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time13'
    MPC_DW.BLUE_Desired_States[2] = MPC_P.Universal_Time13_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time15'
    MPC_DW.BLACK_Saturated_Controls[2] = MPC_P.Universal_Time15_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time16'
    MPC_DW.RED_Thruster_ON_Count = MPC_P.Universal_Time16_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time19'
    MPC_DW.WhoAmI = MPC_P.Universal_Time19_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time20'
    MPC_DW.isSim = MPC_P.Universal_Time20_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time21'
    memcpy(&MPC_DW.MPC_Optimization_Var[0], &MPC_P.z_0[0], 135U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Universal_Time23'
    MPC_DW.MPC_Solver_Result[0] = MPC_P.Universal_Time23_InitialValue[0];
    MPC_DW.MPC_Solver_Result[1] = MPC_P.Universal_Time23_InitialValue[1];
    MPC_DW.MPC_Solver_Result[2] = MPC_P.Universal_Time23_InitialValue[2];
    for (i = 0; i < 6; i++) {
      // Start for DataStoreMemory: '<Root>/Universal_Time22'
      MPC_DW.RED_Estimated_States[i] = MPC_P.Universal_Time22_InitialValue[i];

      // Start for DataStoreMemory: '<Root>/Universal_Time24'
      MPC_DW.ARM_Measured_States[i] = MPC_P.Universal_Time24_InitialValue[i];
    }

    // Start for DataStoreMemory: '<Root>/Universal_Time25'
    MPC_DW.BLACK_Desired_States[0] = MPC_P.Universal_Time25_InitialValue[0];
    MPC_DW.BLACK_Desired_States[1] = MPC_P.Universal_Time25_InitialValue[1];
    MPC_DW.BLACK_Desired_States[2] = MPC_P.Universal_Time25_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time26'
    memcpy(&MPC_DW.RED_Measured_States[0], &MPC_P.Universal_Time26_InitialValue
           [0], 9U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Universal_Time3'
    MPC_DW.BLACK_Thruster_ON_Count = MPC_P.Universal_Time3_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time28'
    MPC_DW.RED_Saturated_Controls[0] = MPC_P.Universal_Time28_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time29'
    MPC_DW.RED_Desired_States[0] = MPC_P.Universal_Time29_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time31'
    MPC_DW.RED_IMU_Measurements[0] = MPC_P.Universal_Time31_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time33'
    MPC_DW.BLACK_IMU_Measurements[0] = MPC_P.Universal_Time33_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time34'
    MPC_DW.BLUE_IMU_Measurements[0] = MPC_P.Universal_Time34_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time28'
    MPC_DW.RED_Saturated_Controls[1] = MPC_P.Universal_Time28_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time29'
    MPC_DW.RED_Desired_States[1] = MPC_P.Universal_Time29_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time31'
    MPC_DW.RED_IMU_Measurements[1] = MPC_P.Universal_Time31_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time33'
    MPC_DW.BLACK_IMU_Measurements[1] = MPC_P.Universal_Time33_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time34'
    MPC_DW.BLUE_IMU_Measurements[1] = MPC_P.Universal_Time34_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time28'
    MPC_DW.RED_Saturated_Controls[2] = MPC_P.Universal_Time28_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time29'
    MPC_DW.RED_Desired_States[2] = MPC_P.Universal_Time29_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time31'
    MPC_DW.RED_IMU_Measurements[2] = MPC_P.Universal_Time31_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time33'
    MPC_DW.BLACK_IMU_Measurements[2] = MPC_P.Universal_Time33_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time34'
    MPC_DW.BLUE_IMU_Measurements[2] = MPC_P.Universal_Time34_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time37'
    MPC_DW.MPC_Target_Holding_Radius[0] = MPC_P.r_hold_tar_0[0];
    MPC_DW.MPC_Target_Holding_Radius[1] = MPC_P.r_hold_tar_0[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time38'
    memcpy(&MPC_DW.MPC_Target_Trajectory[0], &MPC_P.z_0[0], 135U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Universal_Time41'
    MPC_DW.MPC_Docking_Enabler = MPC_P.Universal_Time41_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time4'
    memcpy(&MPC_DW.BLUE_Measured_States[0], &MPC_P.Universal_Time4_InitialValue
           [0], 9U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Universal_Time42'
    memcpy(&MPC_DW.RED_Measured_States_RAW[0],
           &MPC_P.Universal_Time42_InitialValue[0], 9U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Universal_Time43'
    memcpy(&MPC_DW.BLACK_Measured_States_RAW[0],
           &MPC_P.Universal_Time43_InitialValue[0], 9U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Universal_Time44'
    memcpy(&MPC_DW.BLUE_Measured_States_RAW[0],
           &MPC_P.Universal_Time44_InitialValue[0], 9U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Universal_Time45'
    MPC_DW.Toggle_Nav = MPC_P.Universal_Time45_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time6'
    MPC_DW.BLUE_Saturated_Controls[0] = MPC_P.Universal_Time6_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time8'
    MPC_DW.ARM_Desired_States[0] = MPC_P.Universal_Time8_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time9'
    MPC_DW.MPC_Controls[0] = MPC_P.Universal_Time9_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time6'
    MPC_DW.BLUE_Saturated_Controls[1] = MPC_P.Universal_Time6_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time8'
    MPC_DW.ARM_Desired_States[1] = MPC_P.Universal_Time8_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time9'
    MPC_DW.MPC_Controls[1] = MPC_P.Universal_Time9_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time6'
    MPC_DW.BLUE_Saturated_Controls[2] = MPC_P.Universal_Time6_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time8'
    MPC_DW.ARM_Desired_States[2] = MPC_P.Universal_Time8_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time9'
    MPC_DW.MPC_Controls[2] = MPC_P.Universal_Time9_InitialValue[2];

    // InitializeConditions for Delay: '<S19>/Delay'
    MPC_DW.Delay_DSTATE = MPC_P.Delay_InitialCondition_g;

    // InitializeConditions for Delay: '<S276>/Delay2'
    for (i = 0; i < 9; i++) {
      MPC_DW.Delay2_DSTATE[i] = MPC_P.Delay2_InitialCondition_eh;
    }

    // End of InitializeConditions for Delay: '<S276>/Delay2'

    // InitializeConditions for Delay: '<S268>/Delay1'
    for (i = 0; i < 6; i++) {
      MPC_DW.Delay1_DSTATE[i] = MPC_P.Delay1_InitialCondition_eh[i];
    }

    // End of InitializeConditions for Delay: '<S268>/Delay1'

    // InitializeConditions for Delay: '<S268>/Delay'
    memcpy(&MPC_DW.Delay_DSTATE_i[0], &MPC_P.Delay_InitialCondition_h[0], 36U *
           sizeof(real_T));
    for (i = 0; i < 9; i++) {
      // InitializeConditions for Delay: '<S268>/Delay2'
      MPC_DW.Delay2_DSTATE_k[i] = MPC_P.Delay2_InitialCondition_jw[i];

      // InitializeConditions for Delay: '<S270>/Delay2'
      MPC_DW.Delay2_DSTATE_p[i] = MPC_P.Delay2_InitialCondition_p;
    }

    // InitializeConditions for Delay: '<S266>/Delay1'
    for (i = 0; i < 6; i++) {
      MPC_DW.Delay1_DSTATE_c[i] = MPC_P.Delay1_InitialCondition_n[i];
    }

    // End of InitializeConditions for Delay: '<S266>/Delay1'

    // InitializeConditions for Delay: '<S266>/Delay'
    memcpy(&MPC_DW.Delay_DSTATE_n[0], &MPC_P.Delay_InitialCondition_f[0], 36U *
           sizeof(real_T));
    for (i = 0; i < 9; i++) {
      // InitializeConditions for Delay: '<S266>/Delay2'
      MPC_DW.Delay2_DSTATE_j[i] = MPC_P.Delay2_InitialCondition_ji[i];

      // InitializeConditions for Delay: '<S273>/Delay2'
      MPC_DW.Delay2_DSTATE_f[i] = MPC_P.Delay2_InitialCondition_jn;
    }

    // InitializeConditions for Delay: '<S267>/Delay1'
    for (i = 0; i < 6; i++) {
      MPC_DW.Delay1_DSTATE_g[i] = MPC_P.Delay1_InitialCondition_cb[i];
    }

    // End of InitializeConditions for Delay: '<S267>/Delay1'

    // InitializeConditions for Delay: '<S267>/Delay'
    memcpy(&MPC_DW.Delay_DSTATE_h[0], &MPC_P.Delay_InitialCondition_ga[0], 36U *
           sizeof(real_T));

    // InitializeConditions for Delay: '<S267>/Delay2'
    memcpy(&MPC_DW.Delay2_DSTATE_n[0], &MPC_P.Delay2_InitialCondition_c[0], 9U *
           sizeof(real_T));

    // SystemInitialize for IfAction SubSystem: '<S4>/Default PD Control (BLACK)' 
    MPC_DefaultPDControlBLACK_Init(&MPC_DW.DefaultPDControlBLACK,
      &MPC_P.DefaultPDControlBLACK);

    // End of SystemInitialize for SubSystem: '<S4>/Default PD Control (BLACK)'

    // SystemInitialize for IfAction SubSystem: '<S4>/Default LQR Control (BLACK)' 
    MPC_DefaultPDControlBLACK_Init(&MPC_DW.DefaultLQRControlBLACK,
      &MPC_P.DefaultLQRControlBLACK);

    // End of SystemInitialize for SubSystem: '<S4>/Default LQR Control (BLACK)' 

    // SystemInitialize for IfAction SubSystem: '<S4>/Default PD Control (BLUE)' 
    // InitializeConditions for UnitDelay: '<S166>/UD'
    //
    //  Block description for '<S166>/UD':
    //
    //   Store in Global RAM

    MPC_DW.UD_DSTATE_o = MPC_P.DiscreteDerivative_ICPrevScal_p;

    // InitializeConditions for UnitDelay: '<S167>/UD'
    //
    //  Block description for '<S167>/UD':
    //
    //   Store in Global RAM

    MPC_DW.UD_DSTATE_n = MPC_P.DiscreteDerivative1_ICPrevSca_l;

    // InitializeConditions for UnitDelay: '<S168>/UD'
    //
    //  Block description for '<S168>/UD':
    //
    //   Store in Global RAM

    MPC_DW.UD_DSTATE_hu = MPC_P.DiscreteDerivative2_ICPrevSc_on;

    // End of SystemInitialize for SubSystem: '<S4>/Default PD Control (BLUE)'

    // SystemInitialize for IfAction SubSystem: '<S4>/Default LQR Control (BLUE)' 
    // InitializeConditions for UnitDelay: '<S143>/UD'
    //
    //  Block description for '<S143>/UD':
    //
    //   Store in Global RAM

    MPC_DW.UD_DSTATE_l = MPC_P.DiscreteDerivative_ICPrevScal_n;

    // InitializeConditions for UnitDelay: '<S144>/UD'
    //
    //  Block description for '<S144>/UD':
    //
    //   Store in Global RAM

    MPC_DW.UD_DSTATE_k = MPC_P.DiscreteDerivative1_ICPrevSca_f;

    // InitializeConditions for UnitDelay: '<S145>/UD'
    //
    //  Block description for '<S145>/UD':
    //
    //   Store in Global RAM

    MPC_DW.UD_DSTATE_h = MPC_P.DiscreteDerivative2_ICPrevSca_g;

    // End of SystemInitialize for SubSystem: '<S4>/Default LQR Control (BLUE)'

    // SystemInitialize for Merge: '<S4>/Merge2'
    MPC_B.Merge2[0] = MPC_P.Merge2_InitialOutput;
    MPC_B.Merge2[1] = MPC_P.Merge2_InitialOutput;
    MPC_B.Merge2[2] = MPC_P.Merge2_InitialOutput;

    // SystemInitialize for IfAction SubSystem: '<S4>/Default PD (ARM)'
    // SystemInitialize for IfAction SubSystem: '<S128>/Simulated Position Controller' 
    // InitializeConditions for UnitDelay: '<S157>/UD'
    //
    //  Block description for '<S157>/UD':
    //
    //   Store in Global RAM

    MPC_DW.UD_DSTATE = MPC_P.DiscreteDerivative1_ICPrevSca_j;

    // InitializeConditions for UnitDelay: '<S158>/UD'
    //
    //  Block description for '<S158>/UD':
    //
    //   Store in Global RAM

    MPC_DW.UD_DSTATE_e = MPC_P.DiscreteDerivative1_ICPrevSca_a;

    // InitializeConditions for UnitDelay: '<S159>/UD'
    //
    //  Block description for '<S159>/UD':
    //
    //   Store in Global RAM

    MPC_DW.UD_DSTATE_a = MPC_P.DiscreteDerivative1_ICPrevSca_k;

    // End of SystemInitialize for SubSystem: '<S128>/Simulated Position Controller' 
    // End of SystemInitialize for SubSystem: '<S4>/Default PD (ARM)'

    // SystemInitialize for IfAction SubSystem: '<S4>/Default PD Control (RED)'
    // InitializeConditions for UnitDelay: '<S171>/UD'
    //
    //  Block description for '<S171>/UD':
    //
    //   Store in Global RAM

    MPC_DW.UD_DSTATE_d = MPC_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for UnitDelay: '<S172>/UD'
    //
    //  Block description for '<S172>/UD':
    //
    //   Store in Global RAM

    MPC_DW.UD_DSTATE_j = MPC_P.DiscreteDerivative1_ICPrevScale;

    // InitializeConditions for UnitDelay: '<S173>/UD'
    //
    //  Block description for '<S173>/UD':
    //
    //   Store in Global RAM

    MPC_DW.UD_DSTATE_hb = MPC_P.DiscreteDerivative2_ICPrevScale;

    // End of SystemInitialize for SubSystem: '<S4>/Default PD Control (RED)'

    // SystemInitialize for IfAction SubSystem: '<S4>/Default LQR Control (RED)' 
    // InitializeConditions for UnitDelay: '<S148>/UD'
    //
    //  Block description for '<S148>/UD':
    //
    //   Store in Global RAM

    MPC_DW.UD_DSTATE_aq = MPC_P.DiscreteDerivative_ICPrevScal_i;

    // InitializeConditions for UnitDelay: '<S149>/UD'
    //
    //  Block description for '<S149>/UD':
    //
    //   Store in Global RAM

    MPC_DW.UD_DSTATE_p = MPC_P.DiscreteDerivative1_ICPrevSca_e;

    // InitializeConditions for UnitDelay: '<S150>/UD'
    //
    //  Block description for '<S150>/UD':
    //
    //   Store in Global RAM

    MPC_DW.UD_DSTATE_pr = MPC_P.DiscreteDerivative2_ICPrevSca_o;

    // End of SystemInitialize for SubSystem: '<S4>/Default LQR Control (RED)'

    // SystemInitialize for IfAction SubSystem: '<S3>/Subsystem'
    // InitializeConditions for Delay: '<S97>/Delay1'
    memcpy(&MPC_DW.Delay1_DSTATE_dn[0], &MPC_P.Delay1_InitialCondition[0], 13U *
           sizeof(real_T));

    // InitializeConditions for Delay: '<S97>/Delay'
    memcpy(&MPC_DW.Delay_DSTATE_g[0], &MPC_P.PQ[0], 144U * sizeof(real_T));

    // InitializeConditions for Delay: '<S98>/Delay1'
    memcpy(&MPC_DW.Delay1_DSTATE_ml[0], &MPC_P.Delay1_InitialCondition_j[0], 9U *
           sizeof(real_T));

    // InitializeConditions for Delay: '<S98>/Delay2'
    memcpy(&MPC_DW.Delay2_DSTATE_j2[0], &MPC_P.Delay2_InitialCondition[0], 9U *
           sizeof(real_T));

    // InitializeConditions for Delay: '<S98>/Delay'
    memcpy(&MPC_DW.Delay_DSTATE_p[0], &MPC_P.PR[0], 144U * sizeof(real_T));

    // InitializeConditions for Delay: '<S101>/Delay1'
    memcpy(&MPC_DW.Delay1_DSTATE_gw[0], &MPC_P.Delay1_InitialCondition_g[0], 13U
           * sizeof(real_T));

    // InitializeConditions for Delay: '<S101>/Delay'
    memcpy(&MPC_DW.Delay_DSTATE_a[0], &MPC_P.PQ[0], 144U * sizeof(real_T));

    // InitializeConditions for Delay: '<S101>/Delay2'
    memcpy(&MPC_DW.Delay2_DSTATE_nz[0], &MPC_P.Delay2_InitialCondition_m[0], 36U
           * sizeof(real_T));

    // InitializeConditions for Delay: '<S102>/Delay1'
    memcpy(&MPC_DW.Delay1_DSTATE_n[0], &MPC_P.Delay1_InitialCondition_e[0], 9U *
           sizeof(real_T));

    // InitializeConditions for Delay: '<S102>/Delay4'
    memcpy(&MPC_DW.Delay4_DSTATE[0], &MPC_P.Delay4_InitialCondition[0], 9U *
           sizeof(real_T));

    // InitializeConditions for Delay: '<S102>/Delay2'
    memcpy(&MPC_DW.Delay2_DSTATE_kf[0], &MPC_P.PR[0], 144U * sizeof(real_T));

    // InitializeConditions for Delay: '<S102>/Delay3'
    memcpy(&MPC_DW.Delay3_DSTATE[0], &MPC_P.Delay3_InitialCondition[0], 36U *
           sizeof(real_T));

    // SystemInitialize for MATLAB Function: '<S97>/MATLAB Function1'
    memcpy(&MPC_DW.state_k[0], &tmp[0], 625U * sizeof(uint32_T));

    // SystemInitialize for MATLAB Function: '<S101>/MATLAB Function1'
    memcpy(&MPC_DW.state_c[0], &tmp[0], 625U * sizeof(uint32_T));

    // SystemInitialize for MATLAB Function: '<S102>/MATLAB Function1'
    memcpy(&MPC_DW.state[0], &tmp[0], 625U * sizeof(uint32_T));

    // End of SystemInitialize for SubSystem: '<S3>/Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S5>/Change BLACK Behavior'
    MPC_ChangeBLACKBehavior_Init(MPC_M, &MPC_DW.ChangeBLACKBehavior,
      &MPC_P.ChangeBLACKBehavior);

    // End of SystemInitialize for SubSystem: '<S5>/Change BLACK Behavior'

    // SystemInitialize for IfAction SubSystem: '<S5>/Change BLUE Behavior'
    MPC_ChangeBLACKBehavior_Init(MPC_M, &MPC_DW.ChangeBLUEBehavior,
      &MPC_P.ChangeBLUEBehavior);

    // End of SystemInitialize for SubSystem: '<S5>/Change BLUE Behavior'

    // SystemInitialize for IfAction SubSystem: '<S5>/Change RED Behavior'
    MPC_ChangeBLACKBehavior_Init(MPC_M, &MPC_DW.ChangeREDBehavior,
      &MPC_P.ChangeREDBehavior);

    // End of SystemInitialize for SubSystem: '<S5>/Change RED Behavior'

    // SystemInitialize for IfAction SubSystem: '<S7>/Change BLACK Behavior'
    // Start for S-Function (sdspToNetwork): '<S215>/UDP Send1'
    sErr = GetErrorBuffer(&MPC_DW.UDPSend1_NetworkLib[0U]);
    CreateUDPInterface(&MPC_DW.UDPSend1_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&MPC_DW.UDPSend1_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "255.255.255.255", MPC_P.UDPSend1_Port, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&MPC_DW.UDPSend1_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&MPC_DW.UDPSend1_NetworkLib[0U]);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S215>/UDP Send1'
    // End of SystemInitialize for SubSystem: '<S7>/Change BLACK Behavior'

    // SystemInitialize for IfAction SubSystem: '<S7>/Change BLUE Behavior'
    // Start for S-Function (sdspToNetwork): '<S216>/UDP Send2'
    sErr = GetErrorBuffer(&MPC_DW.UDPSend2_NetworkLib[0U]);
    CreateUDPInterface(&MPC_DW.UDPSend2_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&MPC_DW.UDPSend2_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "255.255.255.255", MPC_P.UDPSend2_Port, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&MPC_DW.UDPSend2_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&MPC_DW.UDPSend2_NetworkLib[0U]);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S216>/UDP Send2'
    // End of SystemInitialize for SubSystem: '<S7>/Change BLUE Behavior'

    // SystemInitialize for IfAction SubSystem: '<S7>/Change RED Behavior'
    // Start for S-Function (sdspToNetwork): '<S217>/UDP Send3'
    sErr = GetErrorBuffer(&MPC_DW.UDPSend3_NetworkLib[0U]);
    CreateUDPInterface(&MPC_DW.UDPSend3_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&MPC_DW.UDPSend3_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "255.255.255.255", MPC_P.UDPSend3_Port, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&MPC_DW.UDPSend3_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&MPC_DW.UDPSend3_NetworkLib[0U]);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S217>/UDP Send3'
    // End of SystemInitialize for SubSystem: '<S7>/Change RED Behavior'

    // SystemInitialize for IfAction SubSystem: '<S8>/Enable Pucks'
    // Start for MATLABSystem: '<S218>/GPIO Write1'
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    MPC_DW.obj_c.matlabCodegenIsDeleted = false;
    MPC_DW.obj_c.gpioPin = MPC_P.GPIOWrite1_gpioPin;
    MPC_DW.obj_c.pinDirection = MPC_P.GPIOWrite1_pinDirection;
    MPC_DW.obj_c.isInitialized = 1;

    //         %% Define input properties
    //  Call C-function implementing device initialization
    export_gpio(MPC_DW.obj_c.gpioPin);
    set_pin_direction(MPC_DW.obj_c.gpioPin, MPC_DW.obj_c.pinDirection);
    MPC_DW.obj_c.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S8>/Enable Pucks'

    // SystemInitialize for IfAction SubSystem: '<S9>/Log Gyro//Accel'
    // Start for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
    MPC_DW.obj._pobj2.matlabCodegenIsDeleted = true;
    MPC_DW.obj.isInitialized = 0;
    MPC_DW.obj.matlabCodegenIsDeleted = false;
    MPC_DW.obj.SampleTime = MPC_P.GyroscopeAccelerometer_SampleTi;
    MPC_SystemCore_setup(&MPC_DW.obj);

    // End of SystemInitialize for SubSystem: '<S9>/Log Gyro//Accel'

    // SystemInitialize for IfAction SubSystem: '<S10>/Change ARM Behavior'
    // InitializeConditions for Delay: '<S221>/Delay'
    MPC_DW.Delay_DSTATE_o = MPC_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S221>/Delay1'
    MPC_DW.Delay1_DSTATE_cg = MPC_P.Delay1_InitialCondition_l;

    // InitializeConditions for Delay: '<S221>/Delay2'
    MPC_DW.Delay2_DSTATE_h = MPC_P.Delay2_InitialCondition_j;

    // Start for MATLABSystem: '<S221>/Read Joint Positions using  Dynamixel Encoders' 
    MPC_DW.obj_d.matlabCodegenIsDeleted = false;
    if (((!rtIsInf(MPC_P.baseRate)) && (!rtIsNaN(MPC_P.baseRate))) || rtIsInf
        (MPC_P.baseRate)) {
      sampleTime = MPC_P.baseRate;
    }

    MPC_DW.obj_d.SampleTime = sampleTime;
    MPC_DW.obj_d.isInitialized = 1;

    //         %% Define input properties
    //  Call C-function implementing device initialization
    MPC_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S221>/Read Joint Positions using  Dynamixel Encoders' 
    // End of SystemInitialize for SubSystem: '<S10>/Change ARM Behavior'

    // SystemInitialize for IfAction SubSystem: '<S11>/Use Hardware to Obtain States' 
    // Start for S-Function (sdspFromNetwork): '<S224>/Receive PhaseSpace Data'
    sErr = GetErrorBuffer(&MPC_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
    CreateUDPInterface(&MPC_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&MPC_DW.ReceivePhaseSpaceData_NetworkLi[0U], 0,
                        "0.0.0.0", MPC_P.ReceivePhaseSpaceData_Port, "0.0.0.0",
                        -1, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&MPC_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&MPC_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S224>/Receive PhaseSpace Data' 

    // Start for S-Function (sdspFromNetwork): '<S229>/UDP Receive'
    sErr = GetErrorBuffer(&MPC_DW.UDPReceive_NetworkLib[0U]);
    CreateUDPInterface(&MPC_DW.UDPReceive_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&MPC_DW.UDPReceive_NetworkLib[0U], 0, "0.0.0.0",
                        MPC_P.UDPReceive_Port, "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&MPC_DW.UDPReceive_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&MPC_DW.UDPReceive_NetworkLib[0U]);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S229>/UDP Receive'

    // Start for S-Function (sdspFromNetwork): '<S229>/UDP Receive2'
    sErr = GetErrorBuffer(&MPC_DW.UDPReceive2_NetworkLib[0U]);
    CreateUDPInterface(&MPC_DW.UDPReceive2_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&MPC_DW.UDPReceive2_NetworkLib[0U], 0, "0.0.0.0",
                        MPC_P.UDPReceive2_Port, "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&MPC_DW.UDPReceive2_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&MPC_DW.UDPReceive2_NetworkLib[0U]);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S229>/UDP Receive2'

    // Start for S-Function (sdspFromNetwork): '<S229>/UDP Receive3'
    sErr = GetErrorBuffer(&MPC_DW.UDPReceive3_NetworkLib[0U]);
    CreateUDPInterface(&MPC_DW.UDPReceive3_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&MPC_DW.UDPReceive3_NetworkLib[0U], 0, "0.0.0.0",
                        MPC_P.UDPReceive3_Port, "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&MPC_DW.UDPReceive3_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&MPC_DW.UDPReceive3_NetworkLib[0U]);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S229>/UDP Receive3'

    // InitializeConditions for Delay: '<S233>/Delay2'
    MPC_DW.Delay2_DSTATE_jo = MPC_P.Delay2_InitialCondition_e;

    // InitializeConditions for Delay: '<S233>/Delay1'
    MPC_DW.Delay1_DSTATE_i = MPC_P.Delay1_InitialCondition_m;

    // InitializeConditions for Delay: '<S243>/Delay2'
    MPC_DW.Delay2_DSTATE_l = MPC_P.Delay2_InitialCondition_a;

    // InitializeConditions for Delay: '<S243>/Delay1'
    MPC_DW.Delay1_DSTATE_l = MPC_P.Delay1_InitialCondition_i3;

    // InitializeConditions for Delay: '<S253>/Delay2'
    MPC_DW.Delay2_DSTATE_l0 = MPC_P.Delay2_InitialCondition_mu;

    // InitializeConditions for Delay: '<S253>/Delay1'
    MPC_DW.Delay1_DSTATE_ld = MPC_P.Delay1_InitialCondition_lm;

    // InitializeConditions for Delay: '<S235>/Delay1'
    MPC_DW.Delay1_DSTATE_g3[0] = MPC_P.Delay1_InitialCondition_i;

    // InitializeConditions for Delay: '<S234>/Delay1'
    MPC_DW.Delay1_DSTATE_b[0] = MPC_P.Delay1_InitialCondition_it;

    // InitializeConditions for Delay: '<S245>/Delay1'
    MPC_DW.Delay1_DSTATE_m[0] = MPC_P.Delay1_InitialCondition_h;

    // InitializeConditions for Delay: '<S244>/Delay1'
    MPC_DW.Delay1_DSTATE_lv[0] = MPC_P.Delay1_InitialCondition_ja;

    // InitializeConditions for Delay: '<S255>/Delay1'
    MPC_DW.Delay1_DSTATE_cd[0] = MPC_P.Delay1_InitialCondition_k;

    // InitializeConditions for Delay: '<S254>/Delay1'
    MPC_DW.Delay1_DSTATE_cq[0] = MPC_P.Delay1_InitialCondition_c;

    // InitializeConditions for Delay: '<S235>/Delay1'
    MPC_DW.Delay1_DSTATE_g3[1] = MPC_P.Delay1_InitialCondition_i;

    // InitializeConditions for Delay: '<S234>/Delay1'
    MPC_DW.Delay1_DSTATE_b[1] = MPC_P.Delay1_InitialCondition_it;

    // InitializeConditions for Delay: '<S245>/Delay1'
    MPC_DW.Delay1_DSTATE_m[1] = MPC_P.Delay1_InitialCondition_h;

    // InitializeConditions for Delay: '<S244>/Delay1'
    MPC_DW.Delay1_DSTATE_lv[1] = MPC_P.Delay1_InitialCondition_ja;

    // InitializeConditions for Delay: '<S255>/Delay1'
    MPC_DW.Delay1_DSTATE_cd[1] = MPC_P.Delay1_InitialCondition_k;

    // InitializeConditions for Delay: '<S254>/Delay1'
    MPC_DW.Delay1_DSTATE_cq[1] = MPC_P.Delay1_InitialCondition_c;

    // InitializeConditions for Delay: '<S235>/Delay1'
    MPC_DW.Delay1_DSTATE_g3[2] = MPC_P.Delay1_InitialCondition_i;

    // InitializeConditions for Delay: '<S234>/Delay1'
    MPC_DW.Delay1_DSTATE_b[2] = MPC_P.Delay1_InitialCondition_it;

    // InitializeConditions for Delay: '<S245>/Delay1'
    MPC_DW.Delay1_DSTATE_m[2] = MPC_P.Delay1_InitialCondition_h;

    // InitializeConditions for Delay: '<S244>/Delay1'
    MPC_DW.Delay1_DSTATE_lv[2] = MPC_P.Delay1_InitialCondition_ja;

    // InitializeConditions for Delay: '<S255>/Delay1'
    MPC_DW.Delay1_DSTATE_cd[2] = MPC_P.Delay1_InitialCondition_k;

    // InitializeConditions for Delay: '<S254>/Delay1'
    MPC_DW.Delay1_DSTATE_cq[2] = MPC_P.Delay1_InitialCondition_c;
    for (i = 0; i < 5; i++) {
      // InitializeConditions for Delay: '<S229>/Delay'
      MPC_DW.Delay_DSTATE_ip[i] = MPC_P.Delay_InitialCondition_j;

      // InitializeConditions for Delay: '<S229>/Delay1'
      MPC_DW.Delay1_DSTATE_h[i] = MPC_P.Delay1_InitialCondition_d;

      // InitializeConditions for Delay: '<S229>/Delay2'
      MPC_DW.Delay2_DSTATE_hq[i] = MPC_P.Delay2_InitialCondition_ak;
    }

    // SystemInitialize for Enabled SubSystem: '<S233>/Enabled Subsystem3'
    // SystemInitialize for SignalConversion generated from: '<S237>/y2-y1' incorporates:
    //   Outport: '<S237>/dy(t)//dt'

    MPC_B.y2y1_ob = MPC_P.dytdt_Y0;

    // End of SystemInitialize for SubSystem: '<S233>/Enabled Subsystem3'

    // SystemInitialize for Enabled SubSystem: '<S235>/Enabled Subsystem'
    MPC_EnabledSubsystem_h_Init(MPC_B.dy_i, &MPC_DW.EnabledSubsystem_n,
      &MPC_P.EnabledSubsystem_n);

    // End of SystemInitialize for SubSystem: '<S235>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S234>/Enabled Subsystem'
    MPC_EnabledSubsystem_Init(MPC_B.dy_k, &MPC_DW.EnabledSubsystem_m,
      &MPC_P.EnabledSubsystem_m);

    // End of SystemInitialize for SubSystem: '<S234>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S243>/Enabled Subsystem3'
    // SystemInitialize for SignalConversion generated from: '<S247>/y2-y1' incorporates:
    //   Outport: '<S247>/dy(t)//dt'

    MPC_B.y2y1_o = MPC_P.dytdt_Y0_j;

    // End of SystemInitialize for SubSystem: '<S243>/Enabled Subsystem3'

    // SystemInitialize for Enabled SubSystem: '<S245>/Enabled Subsystem'
    MPC_EnabledSubsystem_h_Init(MPC_B.dy_c, &MPC_DW.EnabledSubsystem_g,
      &MPC_P.EnabledSubsystem_g);

    // End of SystemInitialize for SubSystem: '<S245>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S244>/Enabled Subsystem'
    MPC_EnabledSubsystem_Init(MPC_B.dy_e, &MPC_DW.EnabledSubsystem_l,
      &MPC_P.EnabledSubsystem_l);

    // End of SystemInitialize for SubSystem: '<S244>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S253>/Enabled Subsystem3'
    // SystemInitialize for SignalConversion generated from: '<S257>/y2-y1' incorporates:
    //   Outport: '<S257>/dy(t)//dt'

    MPC_B.y2y1 = MPC_P.dytdt_Y0_d;

    // End of SystemInitialize for SubSystem: '<S253>/Enabled Subsystem3'

    // SystemInitialize for Enabled SubSystem: '<S255>/Enabled Subsystem'
    MPC_EnabledSubsystem_h_Init(MPC_B.dy, &MPC_DW.EnabledSubsystem_a,
      &MPC_P.EnabledSubsystem_a);

    // End of SystemInitialize for SubSystem: '<S255>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S254>/Enabled Subsystem'
    MPC_EnabledSubsystem_Init(MPC_B.dy_l, &MPC_DW.EnabledSubsystem_k,
      &MPC_P.EnabledSubsystem_k);

    // End of SystemInitialize for SubSystem: '<S254>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S228>/Enabled Subsystem'
    // InitializeConditions for Memory: '<S230>/Memory'
    MPC_DW.Memory_PreviousInput = MPC_P.Memory_InitialCondition;

    // SystemInitialize for Memory: '<S230>/Memory' incorporates:
    //   Outport: '<S230>/Out1'

    MPC_B.Memory = MPC_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S228>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S228>/Enabled Subsystem1'
    // SystemInitialize for Sum: '<S231>/Subtract' incorporates:
    //   Outport: '<S231>/Out1'

    MPC_B.Subtract = MPC_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S228>/Enabled Subsystem1'
    // End of SystemInitialize for SubSystem: '<S11>/Use Hardware to Obtain States' 

    // SystemInitialize for IfAction SubSystem: '<S13>/Subsystem'
    // Start for MATLABSystem: '<S278>/WhoAmI'
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    MPC_DW.obj_dk.matlabCodegenIsDeleted = false;
    if (((!rtIsInf(MPC_P.baseRate)) && (!rtIsNaN(MPC_P.baseRate))) || rtIsInf
        (MPC_P.baseRate)) {
      sampleTime_0 = MPC_P.baseRate;
    }

    MPC_DW.obj_dk.SampleTime = sampleTime_0;
    MPC_DW.obj_dk.isInitialized = 1;

    //         %% Define output properties
    //  Call C-function implementing device initialization
    MPC_DW.obj_dk.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S278>/WhoAmI'
    // End of SystemInitialize for SubSystem: '<S13>/Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S14>/Subsystem'
    // Start for S-Function (sdspFromNetwork): '<S279>/UDP Receive1'
    sErr = GetErrorBuffer(&MPC_DW.UDPReceive1_NetworkLib[0U]);
    CreateUDPInterface(&MPC_DW.UDPReceive1_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&MPC_DW.UDPReceive1_NetworkLib[0U], 0, "0.0.0.0",
                        MPC_P.UDPReceive1_Port, "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&MPC_DW.UDPReceive1_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&MPC_DW.UDPReceive1_NetworkLib[0U]);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S279>/UDP Receive1'

    // InitializeConditions for Delay: '<S279>/Delay2'
    MPC_DW.Delay2_DSTATE_e = MPC_P.Delay2_InitialCondition_l;

    // InitializeConditions for Delay: '<S279>/Delay'
    MPC_DW.Delay_DSTATE_c[0] = MPC_P.Delay_InitialCondition_p[0];
    MPC_DW.Delay_DSTATE_c[1] = MPC_P.Delay_InitialCondition_p[1];
    MPC_DW.Delay_DSTATE_c[2] = MPC_P.Delay_InitialCondition_p[2];

    // InitializeConditions for Delay: '<S279>/Delay1'
    MPC_DW.Delay1_DSTATE_d = MPC_P.Delay1_InitialCondition_kb;

    // End of SystemInitialize for SubSystem: '<S14>/Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S15>/Change ARM Behavior'
    // Start for MATLABSystem: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    MPC_DW.obj_n.matlabCodegenIsDeleted = false;
    MPC_DW.obj_n.POSITION_P_GAIN = MPC_P.ControlDynamixelActuatorsineith;
    MPC_DW.obj_n.POSITION_I_GAIN = MPC_P.ControlDynamixelActuatorsinei_b;
    MPC_DW.obj_n.POSITION_D_GAIN = MPC_P.ControlDynamixelActuatorsinei_h;
    MPC_DW.obj_n.MAX_POSITION = MPC_P.ControlDynamixelActuatorsinei_j;
    MPC_DW.obj_n.MIN_POSITION = MPC_P.ControlDynamixelActuatorsinei_m;
    MPC_DW.obj_n.MOVE_TIME = MPC_P.ControlDynamixelActuatorsine_hy;
    MPC_DW.obj_n.CURRENT_LIMIT = MPC_P.ControlDynamixelActuatorsinei_i;
    MPC_DW.obj_n.SPEED_P_GAIN = MPC_P.ControlDynamixelActuatorsinei_g;
    MPC_DW.obj_n.SPEED_I_GAIN = MPC_P.ControlDynamixelActuatorsine_g3;
    MPC_DW.obj_n.VELOCITY_LIMIT = MPC_P.ControlDynamixelActuatorsine_bf;
    MPC_DW.obj_n.ACCELERATION_TIME = MPC_P.ControlDynamixelActuatorsinei_l;
    if (((!rtIsInf(MPC_P.baseRate)) && (!rtIsNaN(MPC_P.baseRate))) || rtIsInf
        (MPC_P.baseRate)) {
      sampleTime_1 = MPC_P.baseRate;
    }

    MPC_DW.obj_n.SampleTime = sampleTime_1;
    MPC_DW.obj_n.isInitialized = 1;

    //         %% Define input properties
    initialize_dynamixel();
    MPC_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
    // End of SystemInitialize for SubSystem: '<S15>/Change ARM Behavior'

    // SystemInitialize for IfAction SubSystem: '<S16>/Subsystem'
    // Start for S-Function (sdspToNetwork): '<S288>/UDP Send'
    sErr = GetErrorBuffer(&MPC_DW.UDPSend_NetworkLib_m[0U]);
    CreateUDPInterface(&MPC_DW.UDPSend_NetworkLib_m[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&MPC_DW.UDPSend_NetworkLib_m[0U], 1, "0.0.0.0", -1,
                        "192.168.1.115", MPC_P.UDPSend_Port, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&MPC_DW.UDPSend_NetworkLib_m[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&MPC_DW.UDPSend_NetworkLib_m[0U]);
      if (*sErr != 0) {
        MPC_M->setErrorStatus(sErr);
        MPC_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S288>/UDP Send'
    // End of SystemInitialize for SubSystem: '<S16>/Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S18>/Change RED Behavior'
    // InitializeConditions for Delay: '<S318>/Delay'
    MPC_DW.Delay_DSTATE_hj = MPC_P.Delay_InitialCondition_i;

    // SystemInitialize for Enabled SubSystem: '<S318>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S323>/In1' incorporates:
    //   Outport: '<S323>/Out1'

    MPC_B.In1 = MPC_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S318>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S318>/Enabled Subsystem1'
    for (i = 0; i < 8; i++) {
      // SystemInitialize for SignalConversion generated from: '<S324>/ThrustPer_Final' incorporates:
      //   Outport: '<S324>/Out1'

      MPC_B.ThrustPer_Final[i] = MPC_P.Out1_Y0_d;
    }

    // End of SystemInitialize for SubSystem: '<S318>/Enabled Subsystem1'
    MPC_Pseudoinverse1_Init(&MPC_DW.Pseudoinverse1_pn);

    // End of SystemInitialize for SubSystem: '<S18>/Change RED Behavior'

    // SystemInitialize for IfAction SubSystem: '<S18>/Change BLACK Behavior'
    // InitializeConditions for Delay: '<S294>/Delay'
    MPC_DW.Delay_DSTATE_j = MPC_P.Delay_InitialCondition_e;

    // SystemInitialize for Enabled SubSystem: '<S294>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S299>/In1' incorporates:
    //   Outport: '<S299>/Out1'

    MPC_B.In1_g2 = MPC_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S294>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S294>/Enabled Subsystem1'
    // SystemInitialize for IfAction SubSystem: '<S18>/Change RED Behavior'
    for (i = 0; i < 8; i++) {
      // SystemInitialize for Outport: '<S291>/RED DC'
      MPC_B.duty_cycles[i] = MPC_P.REDDC_Y0;

      // SystemInitialize for SignalConversion generated from: '<S300>/ThrustPer_Final' incorporates:
      //   Outport: '<S300>/Out1'

      MPC_B.ThrustPer_Final_h5[i] = MPC_P.Out1_Y0_a;
    }

    // End of SystemInitialize for SubSystem: '<S18>/Change RED Behavior'
    // End of SystemInitialize for SubSystem: '<S294>/Enabled Subsystem1'
    MPC_Pseudoinverse1_Init(&MPC_DW.Pseudoinverse1);

    // End of SystemInitialize for SubSystem: '<S18>/Change BLACK Behavior'

    // SystemInitialize for IfAction SubSystem: '<S18>/Change BLUE Behavior'
    // InitializeConditions for Delay: '<S306>/Delay'
    MPC_DW.Delay_DSTATE_ik = MPC_P.Delay_InitialCondition_l;

    // SystemInitialize for Enabled SubSystem: '<S306>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S311>/In1' incorporates:
    //   Outport: '<S311>/Out1'

    MPC_B.In1_g = MPC_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<S306>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S306>/Enabled Subsystem1'
    // SystemInitialize for IfAction SubSystem: '<S18>/Change BLACK Behavior'
    for (i = 0; i < 8; i++) {
      // SystemInitialize for Outport: '<S289>/BLACK DC'
      MPC_B.duty_cycles_n[i] = MPC_P.BLACKDC_Y0;

      // SystemInitialize for SignalConversion generated from: '<S312>/ThrustPer_Final' incorporates:
      //   Outport: '<S312>/Out1'

      MPC_B.ThrustPer_Final_h[i] = MPC_P.Out1_Y0_l;
    }

    // End of SystemInitialize for SubSystem: '<S18>/Change BLACK Behavior'
    // End of SystemInitialize for SubSystem: '<S306>/Enabled Subsystem1'
    MPC_Pseudoinverse1_Init(&MPC_DW.Pseudoinverse1_p);

    // SystemInitialize for Outport: '<S290>/BLUE DC'
    for (i = 0; i < 8; i++) {
      MPC_B.duty_cycles_k[i] = MPC_P.BLUEDC_Y0;
    }

    // End of SystemInitialize for Outport: '<S290>/BLUE DC'
    // End of SystemInitialize for SubSystem: '<S18>/Change BLUE Behavior'

    // Start for MATLABSystem: '<S179>/MATLAB System'
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    MPC_DW.obj_i.matlabCodegenIsDeleted = false;
    MPC_DW.obj_i.isInitialized = 1;

    //         %% Define input properties
    //  Call C-function implementing device initialization
    createFile();
    MPC_DW.obj_i.isSetupComplete = true;
  }
}

// Model terminate function
void MPC_terminate(void)
{
  char_T *sErr;

  // Terminate for IfAction SubSystem: '<S5>/Change BLACK Behavior'
  MPC_ChangeBLACKBehavior_Term(MPC_M, &MPC_DW.ChangeBLACKBehavior);

  // End of Terminate for SubSystem: '<S5>/Change BLACK Behavior'

  // Terminate for IfAction SubSystem: '<S5>/Change BLUE Behavior'
  MPC_ChangeBLACKBehavior_Term(MPC_M, &MPC_DW.ChangeBLUEBehavior);

  // End of Terminate for SubSystem: '<S5>/Change BLUE Behavior'

  // Terminate for IfAction SubSystem: '<S5>/Change RED Behavior'
  MPC_ChangeBLACKBehavior_Term(MPC_M, &MPC_DW.ChangeREDBehavior);

  // End of Terminate for SubSystem: '<S5>/Change RED Behavior'

  // Terminate for MATLABSystem: '<S179>/MATLAB System'
  if (!MPC_DW.obj_i.matlabCodegenIsDeleted) {
    MPC_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S179>/MATLAB System'

  // Terminate for IfAction SubSystem: '<S7>/Change BLACK Behavior'
  // Terminate for S-Function (sdspToNetwork): '<S215>/UDP Send1'
  sErr = GetErrorBuffer(&MPC_DW.UDPSend1_NetworkLib[0U]);
  LibTerminate(&MPC_DW.UDPSend1_NetworkLib[0U]);
  if (*sErr != 0) {
    MPC_M->setErrorStatus(sErr);
    MPC_M->setStopRequested(1);
  }

  LibDestroy(&MPC_DW.UDPSend1_NetworkLib[0U], 1);
  DestroyUDPInterface(&MPC_DW.UDPSend1_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S215>/UDP Send1'
  // End of Terminate for SubSystem: '<S7>/Change BLACK Behavior'

  // Terminate for IfAction SubSystem: '<S7>/Change BLUE Behavior'
  // Terminate for S-Function (sdspToNetwork): '<S216>/UDP Send2'
  sErr = GetErrorBuffer(&MPC_DW.UDPSend2_NetworkLib[0U]);
  LibTerminate(&MPC_DW.UDPSend2_NetworkLib[0U]);
  if (*sErr != 0) {
    MPC_M->setErrorStatus(sErr);
    MPC_M->setStopRequested(1);
  }

  LibDestroy(&MPC_DW.UDPSend2_NetworkLib[0U], 1);
  DestroyUDPInterface(&MPC_DW.UDPSend2_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S216>/UDP Send2'
  // End of Terminate for SubSystem: '<S7>/Change BLUE Behavior'

  // Terminate for IfAction SubSystem: '<S7>/Change RED Behavior'
  // Terminate for S-Function (sdspToNetwork): '<S217>/UDP Send3'
  sErr = GetErrorBuffer(&MPC_DW.UDPSend3_NetworkLib[0U]);
  LibTerminate(&MPC_DW.UDPSend3_NetworkLib[0U]);
  if (*sErr != 0) {
    MPC_M->setErrorStatus(sErr);
    MPC_M->setStopRequested(1);
  }

  LibDestroy(&MPC_DW.UDPSend3_NetworkLib[0U], 1);
  DestroyUDPInterface(&MPC_DW.UDPSend3_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S217>/UDP Send3'
  // End of Terminate for SubSystem: '<S7>/Change RED Behavior'

  // Terminate for IfAction SubSystem: '<S8>/Enable Pucks'
  // Terminate for MATLABSystem: '<S218>/GPIO Write1'
  if (!MPC_DW.obj_c.matlabCodegenIsDeleted) {
    MPC_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((MPC_DW.obj_c.isInitialized == 1) && MPC_DW.obj_c.isSetupComplete) {
      //  Call C-function implementing device termination
      change_gpio_value(MPC_DW.obj_c.gpioPin, 0.0);
      unexport_gpio(MPC_DW.obj_c.gpioPin);
    }
  }

  // End of Terminate for MATLABSystem: '<S218>/GPIO Write1'
  // End of Terminate for SubSystem: '<S8>/Enable Pucks'

  // Terminate for IfAction SubSystem: '<S9>/Log Gyro//Accel'
  // Terminate for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  if (!MPC_DW.obj.matlabCodegenIsDeleted) {
    MPC_DW.obj.matlabCodegenIsDeleted = true;
  }

  if (!MPC_DW.obj._pobj2.matlabCodegenIsDeleted) {
    MPC_DW.obj._pobj2.matlabCodegenIsDeleted = true;
    if (MPC_DW.obj._pobj2.isInitialized == 1) {
      MPC_DW.obj._pobj2.isInitialized = 2;
    }
  }

  // End of Terminate for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
  // End of Terminate for SubSystem: '<S9>/Log Gyro//Accel'

  // Terminate for IfAction SubSystem: '<S10>/Change ARM Behavior'
  // Terminate for MATLABSystem: '<S221>/Read Joint Positions using  Dynamixel Encoders' 
  if (!MPC_DW.obj_d.matlabCodegenIsDeleted) {
    MPC_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S221>/Read Joint Positions using  Dynamixel Encoders' 
  // End of Terminate for SubSystem: '<S10>/Change ARM Behavior'

  // Terminate for IfAction SubSystem: '<S11>/Use Hardware to Obtain States'
  // Terminate for S-Function (sdspFromNetwork): '<S224>/Receive PhaseSpace Data' 
  sErr = GetErrorBuffer(&MPC_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
  LibTerminate(&MPC_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
  if (*sErr != 0) {
    MPC_M->setErrorStatus(sErr);
    MPC_M->setStopRequested(1);
  }

  LibDestroy(&MPC_DW.ReceivePhaseSpaceData_NetworkLi[0U], 0);
  DestroyUDPInterface(&MPC_DW.ReceivePhaseSpaceData_NetworkLi[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S224>/Receive PhaseSpace Data' 

  // Terminate for S-Function (sdspFromNetwork): '<S229>/UDP Receive'
  sErr = GetErrorBuffer(&MPC_DW.UDPReceive_NetworkLib[0U]);
  LibTerminate(&MPC_DW.UDPReceive_NetworkLib[0U]);
  if (*sErr != 0) {
    MPC_M->setErrorStatus(sErr);
    MPC_M->setStopRequested(1);
  }

  LibDestroy(&MPC_DW.UDPReceive_NetworkLib[0U], 0);
  DestroyUDPInterface(&MPC_DW.UDPReceive_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S229>/UDP Receive'

  // Terminate for S-Function (sdspFromNetwork): '<S229>/UDP Receive2'
  sErr = GetErrorBuffer(&MPC_DW.UDPReceive2_NetworkLib[0U]);
  LibTerminate(&MPC_DW.UDPReceive2_NetworkLib[0U]);
  if (*sErr != 0) {
    MPC_M->setErrorStatus(sErr);
    MPC_M->setStopRequested(1);
  }

  LibDestroy(&MPC_DW.UDPReceive2_NetworkLib[0U], 0);
  DestroyUDPInterface(&MPC_DW.UDPReceive2_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S229>/UDP Receive2'

  // Terminate for S-Function (sdspFromNetwork): '<S229>/UDP Receive3'
  sErr = GetErrorBuffer(&MPC_DW.UDPReceive3_NetworkLib[0U]);
  LibTerminate(&MPC_DW.UDPReceive3_NetworkLib[0U]);
  if (*sErr != 0) {
    MPC_M->setErrorStatus(sErr);
    MPC_M->setStopRequested(1);
  }

  LibDestroy(&MPC_DW.UDPReceive3_NetworkLib[0U], 0);
  DestroyUDPInterface(&MPC_DW.UDPReceive3_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S229>/UDP Receive3'
  // End of Terminate for SubSystem: '<S11>/Use Hardware to Obtain States'

  // Terminate for IfAction SubSystem: '<S13>/Subsystem'
  // Terminate for MATLABSystem: '<S278>/WhoAmI'
  if (!MPC_DW.obj_dk.matlabCodegenIsDeleted) {
    MPC_DW.obj_dk.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S278>/WhoAmI'
  // End of Terminate for SubSystem: '<S13>/Subsystem'

  // Terminate for IfAction SubSystem: '<S14>/Subsystem'
  // Terminate for S-Function (sdspFromNetwork): '<S279>/UDP Receive1'
  sErr = GetErrorBuffer(&MPC_DW.UDPReceive1_NetworkLib[0U]);
  LibTerminate(&MPC_DW.UDPReceive1_NetworkLib[0U]);
  if (*sErr != 0) {
    MPC_M->setErrorStatus(sErr);
    MPC_M->setStopRequested(1);
  }

  LibDestroy(&MPC_DW.UDPReceive1_NetworkLib[0U], 0);
  DestroyUDPInterface(&MPC_DW.UDPReceive1_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S279>/UDP Receive1'
  // End of Terminate for SubSystem: '<S14>/Subsystem'

  // Terminate for IfAction SubSystem: '<S15>/Change ARM Behavior'
  // Terminate for MATLABSystem: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
  if (!MPC_DW.obj_n.matlabCodegenIsDeleted) {
    MPC_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((MPC_DW.obj_n.isInitialized == 1) && MPC_DW.obj_n.isSetupComplete) {
      terminate_dynamixel();
    }
  }

  // End of Terminate for MATLABSystem: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
  // End of Terminate for SubSystem: '<S15>/Change ARM Behavior'

  // Terminate for IfAction SubSystem: '<S16>/Subsystem'
  // Terminate for S-Function (sdspToNetwork): '<S288>/UDP Send'
  sErr = GetErrorBuffer(&MPC_DW.UDPSend_NetworkLib_m[0U]);
  LibTerminate(&MPC_DW.UDPSend_NetworkLib_m[0U]);
  if (*sErr != 0) {
    MPC_M->setErrorStatus(sErr);
    MPC_M->setStopRequested(1);
  }

  LibDestroy(&MPC_DW.UDPSend_NetworkLib_m[0U], 1);
  DestroyUDPInterface(&MPC_DW.UDPSend_NetworkLib_m[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S288>/UDP Send'
  // End of Terminate for SubSystem: '<S16>/Subsystem'

  // Terminate for S-Function (sdspToNetwork): '<S18>/UDP Send'
  sErr = GetErrorBuffer(&MPC_DW.UDPSend_NetworkLib[0U]);
  LibTerminate(&MPC_DW.UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    MPC_M->setErrorStatus(sErr);
    MPC_M->setStopRequested(1);
  }

  LibDestroy(&MPC_DW.UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&MPC_DW.UDPSend_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S18>/UDP Send'
}

time_T** RT_MODEL_MPC_T::getTPtrPtr()
{
  return &(Timing.t);
}

boolean_T RT_MODEL_MPC_T::getStopRequested() const
{
  return (Timing.stopRequestedFlag);
}

void RT_MODEL_MPC_T::setStopRequested(boolean_T aStopRequested)
{
  (Timing.stopRequestedFlag = aStopRequested);
}

const char_T* RT_MODEL_MPC_T::getErrorStatus() const
{
  return (errorStatus);
}

void RT_MODEL_MPC_T::setErrorStatus(const char_T* const aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

time_T* RT_MODEL_MPC_T::getTPtr() const
{
  return (Timing.t);
}

void RT_MODEL_MPC_T::setTPtr(time_T* aTPtr)
{
  (Timing.t = aTPtr);
}

boolean_T* RT_MODEL_MPC_T::getStopRequestedPtr()
{
  return (&(Timing.stopRequestedFlag));
}

const char_T** RT_MODEL_MPC_T::getErrorStatusPtr()
{
  return &errorStatus;
}

boolean_T RT_MODEL_MPC_T::isMajorTimeStep() const
{
  return ((Timing.simTimeStep) == MAJOR_TIME_STEP);
}

boolean_T RT_MODEL_MPC_T::isMinorTimeStep() const
{
  return ((Timing.simTimeStep) == MINOR_TIME_STEP);
}

//
// File trailer for generated code.
//
// [EOF]
//
