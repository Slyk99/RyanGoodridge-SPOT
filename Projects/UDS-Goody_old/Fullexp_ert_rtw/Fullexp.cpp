//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Fullexp.cpp
//
// Code generated for Simulink model 'Fullexp'.
//
// Model version                  : 4.649
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Wed May 21 17:34:11 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Fullexp.h"
#include "rtwtypes.h"
#include "Fullexp_types.h"
#include "Fullexp_private.h"
#include <string.h>
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "coder_posix_time.h"
#include "rt_defines.h"

// Block signals (default storage)
B_Fullexp_T Fullexp_B;

// Block states (default storage)
DW_Fullexp_T Fullexp_DW;

// Real-time model
RT_MODEL_Fullexp_T Fullexp_M_ = RT_MODEL_Fullexp_T();
RT_MODEL_Fullexp_T *const Fullexp_M = &Fullexp_M_;

// Forward declaration for local functions
static real_T Fullexp_xzlangeM(const real_T x[24]);
static void Fullexp_xzlascl(real_T cfrom, real_T cto, real_T A[24]);
static real_T Fullexp_xnrm2(int32_T n, const real_T x[24], int32_T ix0);
static real_T Fullexp_xdotc(int32_T n, const real_T x[24], int32_T ix0, const
  real_T y[24], int32_T iy0);
static void Fullexp_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[24],
  int32_T iy0);
static real_T Fullexp_xdotc_o(const real_T x[9], const real_T y[9], int32_T iy0);
static void Fullexp_xaxpy_gop(real_T a, real_T y[9], int32_T iy0);
static real_T Fullexp_xnrm2_p(const real_T x[3], int32_T ix0);
static void Fullexp_xaxpy_g(int32_T n, real_T a, const real_T x[24], int32_T ix0,
  real_T y[8], int32_T iy0);
static void Fullexp_xaxpy_go(int32_T n, real_T a, const real_T x[8], int32_T ix0,
  real_T y[24], int32_T iy0);
static void Fullexp_xzlascl_i(real_T cfrom, real_T cto, real_T A[3]);
static void Fullexp_xrotg(real_T a, real_T b, real_T *b_a, real_T *b_b, real_T
  *c, real_T *s);
static void Fullexp_xrot_ps(real_T x[9], int32_T ix0, int32_T iy0, real_T c,
  real_T s);
static void Fullexp_xrot_psj(real_T x[24], int32_T ix0, int32_T iy0, real_T c,
  real_T s);
static void Fullexp_xswap_dj(real_T x[9], int32_T ix0, int32_T iy0);
static void Fullexp_xswap_dj5(real_T x[24], int32_T ix0, int32_T iy0);
static void Fullexp_svd(const real_T A[24], real_T U[24], real_T s[3], real_T V
  [9]);

// Forward declaration for local functions
static real_T Fullexp_maximum(const real_T x[8]);

// Forward declaration for local functions
static void Fullexp_timeKeeper(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime);
static void Fullexp_tic(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime);
static real_T Fullexp_rand(void);
static real_T Fullexp_norm(const real_T x[3]);
static void Fullexp_mrdiv_h(real_T A[72], const real_T B[36]);
static void Fullexp_timeKeeper_e(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime,
  real_T *outTime_tv_sec, real_T *outTime_tv_nsec);
static real_T Fullexp_toc(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime);
static void Fullexp_timeKeeper_h(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_o);
static void Fullexp_tic_k(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_o);
static real_T Fullexp_norm_hq(const real_T x[81]);
static void Fullexp_mpower(const real_T a[81], real_T b, real_T c[81]);
static real_T Fullexp_log2(real_T x);
static void Fullexp_padeApproximation(const real_T A[81], const real_T A2[81],
  const real_T A4[81], const real_T A6[81], int32_T m, real_T F[81]);
static void Fullexp_recomputeBlockDiag(const real_T A[81], real_T F[81], const
  int32_T blockFormat[8]);
static real_T Fullexp_xnrm2_n(int32_T n, const real_T x[81], int32_T ix0);
static void Fullexp_xzsyhetrd(real_T A[81], real_T D[9], real_T E[8], real_T
  tau[8]);
static void Fullexp_xzlascl_h(real_T cfrom, real_T cto, int32_T m, real_T A[9],
  int32_T iA0);
static void Fullexp_xzlascl_ha(real_T cfrom, real_T cto, int32_T m, real_T A[8],
  int32_T iA0);
static void Fullexp_xzlartg(real_T f, real_T g, real_T *cs, real_T *sn, real_T
  *r);
static void Fullexp_rotateRight_c(int32_T n, real_T z[81], int32_T iz0, const
  real_T cs[16], int32_T ic0, int32_T is0);
static void Fullexp_xdlaev2(real_T a, real_T b, real_T c, real_T *rt1, real_T
  *rt2, real_T *cs1, real_T *sn1);
static void Fullexp_rotateRight(int32_T n, real_T z[81], int32_T iz0, const
  real_T cs[16], int32_T ic0, int32_T is0);
static int32_T Fullexp_xzsteqr(real_T d[9], real_T e[8], real_T z[81]);
static void Fullexp_xsyheev(real_T A[81], int32_T *info, real_T W[9]);
static void Fullexp_expm(real_T A[81], real_T F[81]);
static real_T Fullexp_mod(real_T x);
static real_T Fullexp_rand_m(void);
static void Fullexp_timeKeeper_hm(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_o,
  real_T *outTime_tv_sec, real_T *outTime_tv_nsec);
static real_T Fullexp_toc_i(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_o);
static void Fullexp_timeKeeper_hc(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_a);
static void Fullexp_tic_p(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_a);
static real_T Fullexp_norm_l(const real_T x[9]);
static void Fullexp_mpower_g(const real_T a[9], real_T b, real_T c[9]);
static void Fullexp_padeApproximation_n(const real_T A[9], const real_T A2[9],
  const real_T A4[9], const real_T A6[9], int32_T m, real_T F[9]);
static void Fullexp_recomputeBlockDiag_i(const real_T A[9], real_T F[9], const
  int32_T blockFormat[2]);
static void Fullexp_xzsyhetrd_d(real_T A[9], real_T D[3], real_T E[2], real_T
  tau[2]);
static void Fullexp_xzlascl_c(real_T cfrom, real_T cto, int32_T m, real_T A[3],
  int32_T iA0);
static void Fullexp_xzlascl_cm(real_T cfrom, real_T cto, int32_T m, real_T A[2],
  int32_T iA0);
static void Fullexp_rotateRight_oq(int32_T n, real_T z[9], int32_T iz0, const
  real_T cs[4], int32_T ic0, int32_T is0);
static void Fullexp_rotateRight_o(int32_T n, real_T z[9], int32_T iz0, const
  real_T cs[4], int32_T ic0, int32_T is0);
static int32_T Fullexp_xzsteqr_n(real_T d[3], real_T e[2], real_T z[9]);
static void Fullexp_xsyheev_m(real_T A[9], int32_T *info, real_T W[3]);
static void Fullexp_expm_h(real_T A[9], real_T F[9]);
static real_T Fullexp_rand_a(void);
static real_T Fullexp_norm_lf(const real_T x[2]);
static void Fullexp_timeKeeper_hc0(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_a,
  real_T *outTime_tv_sec, real_T *outTime_tv_nsec);
static real_T Fullexp_toc_b(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_a);
static void Fullexp_timeKeeper_k(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_o2);
static void Fullexp_tic_b(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_o2);
static real_T Fullexp_rand_p(void);
static void Fullexp_xzgetrf(real_T A[36], int32_T ipiv[6], int32_T *info);
static boolean_T Fullexp_hasFiniteBounds(boolean_T hasLB[6], boolean_T hasUB[6]);
static void Fullexp_corrP4DQ_anonFcn1(const real_T P_k[144], const real_T H[72],
  const real_T R[36], const real_T V[36], const real_T x[6], real_T varargout_1
  [36]);
static void Fullexp_finDiffEvalAndChkErr(const real_T
  obj_nonlin_workspace_fun_worksp[144], const real_T
  obj_nonlin_workspace_fun_work_0[36], int32_T dim, real_T delta, real_T xk[6],
  boolean_T *evalOK, real_T *fplus, real_T cEqPlus[36]);
static boolean_T Fullex_computeFiniteDifferences(s_XBLL4znh7jruOucykDXjzD_Full_T
  *obj, const real_T cEqCurrent[36], real_T xk[6], real_T JacCeqTrans[216]);
static real_T Fullexp_computeFirstOrderOpt(const real_T gradf[6], boolean_T
  hasFiniteBounds, const real_T *projSteepestDescentInfNorm);
static real_T Fullexp_norm_du(const real_T x[6]);
static int32_T Fullexp_checkStoppingCriteria(const real_T gradf[6], real_T
  relFactor, const real_T x[6], int32_T funcCount, real_T
  projSteepestDescentInfNorm, boolean_T hasFiniteBounds);
static real_T Fullexp_xnrm2_pl(int32_T n, const real_T x[252], int32_T ix0);
static real_T Fullexp_xzlarfg(int32_T n, real_T *alpha1, real_T x[252], int32_T
  ix0);
static void Fullexp_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T
  C[252], int32_T ic0, real_T work[6]);
static void Fullexp_linearLeastSquares(real_T lhs[252], real_T rhs[42], real_T
  dx[6]);
static int32_T Fullexp_checkStoppingCriteria_a(const real_T gradf[6], real_T
  relFactor, real_T funDiff, const real_T x[6], const real_T dx[6], int32_T
  funcCount, boolean_T stepSuccessful, int32_T *iter, real_T
  projSteepestDescentInfNorm, boolean_T hasFiniteBounds);
static void Fullexp_lsqnonlin(const real_T fun_workspace_P_k[144], const real_T
  fun_workspace_V[36], real_T xCurrent[6]);
static void Fullexp_mrdiv_eg(real_T A[72], const real_T B[36]);
static void Fullexp_timeKeeper_kf(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_o2,
  real_T *outTime_tv_sec, real_T *outTime_tv_nsec);
static real_T Fullexp_toc_m(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_o2);
static void Fullexp_timeKeeper_ed(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_os);
static void Fullexp_tic_g(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_os);
static real_T Fullexp_rand_k(void);
static void Fullexp_corrP4Q_anonFcn1(const real_T P_k[144], const real_T H[72],
  const real_T R[36], const real_T V[36], const real_T x[6], real_T varargout_1
  [36]);
static void Fullexp_finDiffEvalAndChkErr_n(const real_T
  obj_nonlin_workspace_fun_worksp[144], const real_T
  obj_nonlin_workspace_fun_work_0[72], const real_T
  obj_nonlin_workspace_fun_work_1[36], int32_T dim, real_T delta, real_T xk[6],
  boolean_T *evalOK, real_T *fplus, real_T cEqPlus[36]);
static boolean_T Full_computeFiniteDifferences_h(s_B0kB2CQLsoRkj8KoaXWXYC_Full_T
  *obj, const real_T cEqCurrent[36], real_T xk[6], real_T JacCeqTrans[216]);
static void Fullexp_lsqnonlin_k(const real_T fun_workspace_P_k[144], const
  real_T fun_workspace_H[72], const real_T fun_workspace_V[36], real_T xCurrent
  [6]);
static void Fullexp_timeKeeper_ed1(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_os,
  real_T *outTime_tv_sec, real_T *outTime_tv_nsec);
static real_T Fullexp_toc_k(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_os);
static real_T Fullexp_xnrm2_j(int32_T n, const real_T x[153], int32_T ix0);
static real_T Fullexp_xzlarfg_a(int32_T n, real_T *alpha1, real_T x[153],
  int32_T ix0);
static void Fullexp_xzlarf_p(int32_T m, int32_T n, int32_T iv0, real_T tau,
  real_T C[153], int32_T ic0, real_T work[17]);
static void Fullexp_qrf(real_T A[153], int32_T m, int32_T n, int32_T nfxd,
  real_T tau[9]);
static void Fullexp_xgeqp3(real_T A[153], int32_T m, int32_T n, int32_T jpvt[17],
  real_T tau[9]);
static void Fullexp_countsort(int32_T x[17], int32_T xLen, int32_T workspace[17],
  int32_T xMin, int32_T xMax);
static void Fullexp_removeConstr(srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *obj, int32_T
  idx_global);
static void Fullexp_RemoveDependentIneq_(srnx7tMxlsAQ9dn31gXFrqF_Fulle_T
  *workingset, sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *qrmanager,
  sLLWTJNyuJQrAxk3RwmbzBG_Fulle_T *memspace, real_T tolfactor);
static void Fullexp_computeQ_(sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *obj, int32_T
  nrows);
static int32_T Fullexp_rank(const real_T qrmanager_QR[153], int32_T
  qrmanager_mrows, int32_T qrmanager_ncols);
static real_T Fullexp_maxConstraintViolation(const
  srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *obj, const real_T x[153], int32_T ix0);
static boolean_T Fullexp_feasibleX0ForWorkingSet(real_T workspace[153], real_T
  xCurrent[9], const srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *qrmanager);
static real_T Fullex_maxConstraintViolation_b(const
  srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *obj, const real_T x[9]);
static void Fullexp_setProblemType(srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *obj, int32_T
  PROBLEM_TYPE);
static void Fullexp_xgemv(int32_T m, int32_T n, const real_T A[64], int32_T lda,
  const real_T x[9], real_T y[8]);
static void Fullexp_computeGrad_StoreHx(s87IldPMN2ICa85Nu8z6UL_Fullex_T *obj,
  const real_T H[64], const real_T f[8], const real_T x[9]);
static real_T Fullexp_computeFval_ReuseHx(const s87IldPMN2ICa85Nu8z6UL_Fullex_T *
  obj, real_T workspace[153], const real_T f[8], const real_T x[9]);
static void Fullexp_factorQR(sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *obj, const real_T
  A[153], int32_T mrows, int32_T ncols);
static void Fullexp_xrotg_j(real_T *a, real_T *b, real_T *c, real_T *s);
static void Fullexp_squareQ_appendCol(sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *obj,
  const real_T vec[153], int32_T iv0);
static void Fullexp_deleteColMoveEnd(sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *obj,
  int32_T idx);
static void Fullexp_fullColLDL2_(smSS6fEwaptVbzYAOdOZgjB_Fulle_T *obj, int32_T
  NColsRemain, real_T REG_PRIMAL);
static void Fullexp_xgemv_k(int32_T m, int32_T n, const real_T A[81], int32_T
  ia0, const real_T x[153], real_T y[9]);
static void Fullexp_compute_deltax(const real_T H[64],
  sraTyWZlTzdIJhNDrRZT2SF_Fulle_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_Fulle_T
  *memspace, const sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *qrmanager,
  smSS6fEwaptVbzYAOdOZgjB_Fulle_T *cholmanager, const
  s87IldPMN2ICa85Nu8z6UL_Fullex_T *objective);
static real_T Fullexp_xnrm2_jd(int32_T n, const real_T x[9]);
static void Fullexp_feasibleratiotest(const real_T solution_xstar[9], const
  real_T solution_searchDir[9], int32_T workingset_nVar, const real_T
  workingset_lb[9], const int32_T workingset_indexLB[9], const int32_T
  workingset_indexUB[9], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[17],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx);
static void Full_addBoundToActiveSetMatrix_(srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *obj,
  int32_T TYPE, int32_T idx_local);
static void Fullexp_addAineqConstr(const srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *obj);
static void Fullexp_compute_lambda(real_T workspace[153],
  sraTyWZlTzdIJhNDrRZT2SF_Fulle_T *solution, const
  s87IldPMN2ICa85Nu8z6UL_Fullex_T *objective, const
  sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *qrmanager);
static void Fullexp_phaseone(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_Fulle_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_Fulle_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_Fulle_T
  *cholmanager, const sIOJhD9KwAkF5sEguPjYquC_Fulle_T *runTimeOptions,
  s87IldPMN2ICa85Nu8z6UL_Fullex_T *objective);
static int32_T Fullexp_RemoveDependentEq_(sLLWTJNyuJQrAxk3RwmbzBG_Fulle_T
  *memspace, const srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *qrmanager);
static void Fullexp_ratiotest(const real_T solution_xstar[9], const real_T
  solution_searchDir[9], int32_T workingset_nVar, const real_T workingset_lb[9],
  const int32_T workingset_indexLB[9], const int32_T workingset_indexUB[9],
  const int32_T workingset_sizes[5], const int32_T workingset_isActiveIdx[6],
  const boolean_T workingset_isActiveConstr[17], const int32_T
  workingset_nWConstr[5], real_T *toldelta, real_T *alpha, boolean_T
  *newBlocking, int32_T *constrType, int32_T *constrIdx);
static void Fullexp_iterate(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_Fulle_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_Fulle_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_Fulle_T
  *cholmanager, s87IldPMN2ICa85Nu8z6UL_Fullex_T *objective, boolean_T
  runTimeOptions_RemainFeasible, real_T runTimeOptions_ProbRelTolFactor);
static void Fullexp_computeFirstOrderOpt_m(sraTyWZlTzdIJhNDrRZT2SF_Fulle_T
  *solution, const s87IldPMN2ICa85Nu8z6UL_Fullex_T *objective, int32_T
  workingset_nVar, const real_T workingset_ATwset[153], int32_T
  workingset_nActiveConstr, real_T workspace[153]);
static void Fullexp_phaseone_o(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_Fulle_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_Fulle_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_Fulle_T
  *cholmanager, s87IldPMN2ICa85Nu8z6UL_Fullex_T *objective, const
  sIOJhD9KwAkF5sEguPjYquC_Fulle_T *runTimeOptions);
static void Fullexp_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
  real_T workspace[153], const real_T H[64], const real_T f[8], const real_T x[9]);
static real_T Fullexp_computeFval(const s87IldPMN2ICa85Nu8z6UL_Fullex_T *obj,
  real_T workspace[153], const real_T H[64], const real_T f[8], const real_T x[9]);
static void Fullexp_quadprog(const real_T H[64], const real_T f[8], const real_T
  x0[8], real_T x[8], real_T *fval, real_T *exitflag);
static real_T Fullexp_maximum_i(const real_T x[8]);
static void Fullexp_pause(real_T varargin_1);
static void F_bmi160_set_EnableSecondaryMag(b_bmi160_Fullexp_T *obj);
static void Fullexp_SystemCore_setup(nvidiacoder_sensors_BMI160Blo_T *obj);
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
void Fullexp_Phase0Synchronization(real_T *rtd_ARM_Control_Law_Enabler, real_T
  *rtd_ARM_Path_Planner_Selection, real_T *rtd_BLACK_Control_Law_Enabler, real_T
  *rtd_BLACK_Path_Planner_Selectio, real_T *rtd_BLUE_Control_Law_Enabler, real_T
  *rtd_BLUE_Path_Planner_Selection, real_T *rtd_Float_State, real_T
  *rtd_RED_Control_Law_Enabler, char_T rtd_RED_Logger[256], real_T
  *rtd_RED_Path_Planner_Selection, P_Phase0Synchronization_Fulle_T *localP)
{
  // DataStoreWrite: '<S27>/Data Store Write2' incorporates:
  //   Constant: '<S27>/Constant1'

  *rtd_BLACK_Control_Law_Enabler = localP->Constant1_Value;

  // DataStoreWrite: '<S27>/Data Store Write3' incorporates:
  //   Constant: '<S27>/Constant2'

  *rtd_BLUE_Control_Law_Enabler = localP->Constant2_Value;

  // DataStoreWrite: '<S27>/Data Store Write7' incorporates:
  //   Constant: '<S27>/Constant3'

  *rtd_RED_Path_Planner_Selection = localP->Constant3_Value;

  // DataStoreWrite: '<S27>/Data Store Write8' incorporates:
  //   Constant: '<S27>/Constant4'

  *rtd_ARM_Path_Planner_Selection = localP->Constant4_Value;

  // DataStoreWrite: '<S27>/Data Store Write' incorporates:
  //   Constant: '<S27>/Constant5'

  *rtd_RED_Control_Law_Enabler = localP->Constant5_Value;

  // DataStoreWrite: '<S27>/Data Store Write6' incorporates:
  //   Constant: '<S27>/Constant6'

  *rtd_BLACK_Path_Planner_Selectio = localP->Constant6_Value;

  // DataStoreWrite: '<S27>/Data Store Write5' incorporates:
  //   Constant: '<S27>/Constant7'

  *rtd_BLUE_Path_Planner_Selection = localP->Constant7_Value;

  // DataStoreWrite: '<S27>/Data Store Write9' incorporates:
  //   Constant: '<S27>/Constant8'

  *rtd_ARM_Control_Law_Enabler = localP->Constant8_Value;

  // StringConstant: '<S27>/String Constant' incorporates:
  //   DataStoreWrite: '<S27>/Data Store Write1'

  strncpy(&rtd_RED_Logger[0], &localP->StringConstant_String[0], 255U);
  rtd_RED_Logger[255] = '\x00';

  // DataStoreWrite: '<S27>/Data Store Write4' incorporates:
  //   Constant: '<S27>/Puck State'

  *rtd_Float_State = localP->PuckState_Value;
}

//
// Output and update for action system:
//    '<S1>/Phase #4: Return Home'
//    '<S1>/Phase #5: Hold Home'
//
void Fullexp_Phase4ReturnHome(real_T *rtd_ARM_Control_Law_Enabler, real_T
  rtd_ARM_Desired_States[3], real_T *rtd_ARM_Path_Planner_Selection, real_T
  *rtd_BLACK_Control_Law_Enabler, real_T rtd_BLACK_Desired_States[3], real_T
  *rtd_BLACK_Path_Planner_Selectio, real_T *rtd_BLUE_Control_Law_Enabler, real_T
  rtd_BLUE_Desired_States[3], real_T *rtd_BLUE_Path_Planner_Selection, real_T
  *rtd_Float_State, real_T *rtd_RED_Control_Law_Enabler, real_T
  rtd_RED_Desired_States[3], real_T *rtd_RED_Path_Planner_Selection,
  P_Phase4ReturnHome_Fullexp_T *localP)
{
  // DataStoreWrite: '<S31>/Data Store Write24' incorporates:
  //   Constant: '<S31>/Constant11'

  *rtd_RED_Path_Planner_Selection = localP->Constant11_Value;

  // DataStoreWrite: '<S31>/Data Store Write3' incorporates:
  //   Constant: '<S31>/Constant12'

  *rtd_ARM_Path_Planner_Selection = localP->Constant12_Value;

  // DataStoreWrite: '<S31>/Data Store Write23' incorporates:
  //   Constant: '<S31>/Constant14'

  *rtd_BLACK_Path_Planner_Selectio = localP->Constant14_Value;

  // DataStoreWrite: '<S31>/Data Store Write22' incorporates:
  //   Constant: '<S31>/Constant15'

  *rtd_BLUE_Path_Planner_Selection = localP->Constant15_Value;

  // DataStoreWrite: '<S31>/Data Store Write4' incorporates:
  //   Constant: '<S31>/Constant18'

  *rtd_ARM_Control_Law_Enabler = localP->Constant18_Value;

  // DataStoreWrite: '<S31>/Data Store Write5' incorporates:
  //   Constant: '<S31>/Constant4'

  *rtd_BLACK_Control_Law_Enabler = localP->Constant4_Value;

  // DataStoreWrite: '<S31>/Data Store Write8' incorporates:
  //   Constant: '<S31>/Constant5'

  *rtd_RED_Control_Law_Enabler = localP->Constant5_Value;

  // DataStoreWrite: '<S31>/Data Store Write7' incorporates:
  //   Constant: '<S31>/Constant6'

  *rtd_Float_State = localP->Constant6_Value;

  // DataStoreWrite: '<S31>/Data Store Write16' incorporates:
  //   Constant: '<S31>/Constant8'

  *rtd_BLUE_Control_Law_Enabler = localP->Constant8_Value;

  // DataStoreWrite: '<S31>/Data Store Write13' incorporates:
  //   Constant: '<S81>/Constant1'
  //   Constant: '<S81>/Constant2'
  //   Constant: '<S81>/Constant3'

  rtd_ARM_Desired_States[0] = localP->Constant3_Value;
  rtd_ARM_Desired_States[1] = localP->Constant1_Value;
  rtd_ARM_Desired_States[2] = localP->Constant2_Value;

  // DataStoreWrite: '<S31>/Data Store Write18' incorporates:
  //   Constant: '<S83>/Desired States (BLUE)'

  rtd_BLUE_Desired_States[0] = Fullexp_P.home_states_BLUE[0];

  // DataStoreWrite: '<S31>/Data Store Write6' incorporates:
  //   Constant: '<S82>/Desired States (BLACK)'

  rtd_BLACK_Desired_States[0] = Fullexp_P.home_states_BLACK[0];

  // DataStoreWrite: '<S31>/Data Store Write9' incorporates:
  //   Constant: '<S84>/Constant2'

  rtd_RED_Desired_States[0] = Fullexp_P.home_states_RED[0];

  // DataStoreWrite: '<S31>/Data Store Write18' incorporates:
  //   Constant: '<S83>/Desired States (BLUE)'

  rtd_BLUE_Desired_States[1] = Fullexp_P.home_states_BLUE[1];

  // DataStoreWrite: '<S31>/Data Store Write6' incorporates:
  //   Constant: '<S82>/Desired States (BLACK)'

  rtd_BLACK_Desired_States[1] = Fullexp_P.home_states_BLACK[1];

  // DataStoreWrite: '<S31>/Data Store Write9' incorporates:
  //   Constant: '<S84>/Constant2'

  rtd_RED_Desired_States[1] = Fullexp_P.home_states_RED[1];

  // DataStoreWrite: '<S31>/Data Store Write18' incorporates:
  //   Constant: '<S83>/Desired States (BLUE)'

  rtd_BLUE_Desired_States[2] = Fullexp_P.home_states_BLUE[2];

  // DataStoreWrite: '<S31>/Data Store Write6' incorporates:
  //   Constant: '<S82>/Desired States (BLACK)'

  rtd_BLACK_Desired_States[2] = Fullexp_P.home_states_BLACK[2];

  // DataStoreWrite: '<S31>/Data Store Write9' incorporates:
  //   Constant: '<S84>/Constant2'

  rtd_RED_Desired_States[2] = Fullexp_P.home_states_RED[2];
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
//    '<S94>/MATLAB Function'
//    '<S93>/MATLAB Function'
//
void Fullexp_MATLABFunction(const real_T rtu_desiredPosition[3], const real_T
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
    Fullexp_P.baseRate + rty_currentPosition[2];
  rty_currentPosition[0] += ((rtu_desiredPosition[0] - rty_currentPosition[0]) *
    rtu_attractiveGain + repulsiveForce_idx_0) * Fullexp_P.baseRate;
  rty_currentPosition[1] += ((rtu_desiredPosition[1] - rty_currentPosition[1]) *
    rtu_attractiveGain + repulsiveForce_idx_1) * Fullexp_P.baseRate;
  rty_currentPosition[2] = rt_atan2d_snf(sin(newTheta), cos(newTheta));
}

//
// Output and update for atomic system:
//    '<S163>/MATLAB Function'
//    '<S140>/MATLAB Function'
//    '<S153>/MATLAB Function'
//    '<S130>/MATLAB Function'
//    '<S158>/MATLAB Function'
//    '<S135>/MATLAB Function'
//
void Fullexp_MATLABFunction_n(real_T rtu_Rz_path, real_T rtu_Rz_measured, real_T
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
void Fullexp_CustomControlRED(real_T rty_u[3], P_CustomControlRED_Fullexp_T
  *localP)
{
  // SignalConversion generated from: '<S118>/u' incorporates:
  //   Constant: '<S118>/Zero'

  rty_u[0] = localP->Zero_Value;
  rty_u[1] = localP->Zero_Value;
  rty_u[2] = localP->Zero_Value;
}

//
// Output and update for action system:
//    '<S3>/Disable Thrusters (BLACK)'
//    '<S3>/Disable Thrusters (BLUE)'
//
void Fullexp_DisableThrustersBLACK(real_T rty_Out1[3],
  P_DisableThrustersBLACK_Fulle_T *localP)
{
  // SignalConversion generated from: '<S127>/Out1' incorporates:
  //   Constant: '<S127>/Zero'

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
void Fullex_ChangeBLACKBehavior_Init(RT_MODEL_Fullexp_T * const Fullexp_M,
  DW_ChangeBLACKBehavior_Fullex_T *localDW, P_ChangeBLACKBehavior_Fullexp_T
  *localP)
{
  char_T *sErr;

  // Start for S-Function (sdspToNetwork): '<S168>/UDP Send'
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
      Fullexp_M->setErrorStatus(sErr);
      Fullexp_M->setStopRequested(1);
    }
  }

  // End of Start for S-Function (sdspToNetwork): '<S168>/UDP Send'
}

//
// Output and update for action system:
//    '<S4>/Change BLACK Behavior'
//    '<S4>/Change BLUE Behavior'
//    '<S4>/Change RED Behavior'
//
void Fullexp_ChangeBLACKBehavior(RT_MODEL_Fullexp_T * const Fullexp_M,
  DW_ChangeBLACKBehavior_Fullex_T *localDW, P_ChangeBLACKBehavior_Fullexp_T
  *localP)
{
  char_T *sErr;

  // Update for S-Function (sdspToNetwork): '<S168>/UDP Send' incorporates:
  //   Constant: '<S168>/Constant1'

  sErr = GetErrorBuffer(&localDW->UDPSend_NetworkLib[0U]);
  LibUpdate_Network(&localDW->UDPSend_NetworkLib[0U], &localP->Constant1_Value,
                    1);
  if (*sErr != 0) {
    Fullexp_M->setErrorStatus(sErr);
    Fullexp_M->setStopRequested(1);
  }

  // End of Update for S-Function (sdspToNetwork): '<S168>/UDP Send'
}

//
// Termination for action system:
//    '<S4>/Change BLACK Behavior'
//    '<S4>/Change BLUE Behavior'
//    '<S4>/Change RED Behavior'
//
void Fullex_ChangeBLACKBehavior_Term(RT_MODEL_Fullexp_T * const Fullexp_M,
  DW_ChangeBLACKBehavior_Fullex_T *localDW)
{
  char_T *sErr;

  // Terminate for S-Function (sdspToNetwork): '<S168>/UDP Send'
  sErr = GetErrorBuffer(&localDW->UDPSend_NetworkLib[0U]);
  LibTerminate(&localDW->UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    Fullexp_M->setErrorStatus(sErr);
    Fullexp_M->setStopRequested(1);
  }

  LibDestroy(&localDW->UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&localDW->UDPSend_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S168>/UDP Send'
}

//
// Output and update for atomic system:
//    '<Root>/MATLAB Function'
//    '<Root>/MATLAB Function1'
//
void Fullexp_MATLABFunction_f(const real_T rtu_z[9], real_T rty_x[12])
{
  rty_x[0] = rtu_z[0];
  rty_x[1] = rtu_z[1];
  rty_x[2] = 0.0;
  rty_x[3] = 0.0;
  rty_x[4] = 0.0;
  rty_x[5] = rtu_z[2];
  rty_x[6] = rtu_z[3];
  rty_x[7] = rtu_z[4];
  rty_x[8] = 0.0;
  rty_x[9] = 0.0;
  rty_x[10] = 0.0;
  rty_x[11] = rtu_z[5];
}

//
// Output and update for atomic system:
//    '<S192>/MATLAB Function'
//    '<S202>/MATLAB Function'
//    '<S212>/MATLAB Function'
//
void Fullexp_MATLABFunction_j(real_T rtu_dt, real_T rtu_dataRate, real_T
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
//    '<S193>/Enabled Subsystem'
//    '<S203>/Enabled Subsystem'
//    '<S213>/Enabled Subsystem'
//
void Fullexp_EnabledSubsystem_Init(real_T rty_dydt[3],
  DW_EnabledSubsystem_Fullexp_T *localDW, P_EnabledSubsystem_Fullexp_T *localP)
{
  // InitializeConditions for Delay: '<S198>/Delay'
  localDW->icLoad = true;

  // InitializeConditions for Delay: '<S198>/Delay1'
  localDW->Delay1_DSTATE[0] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S198>/dy//dt'
  rty_dydt[0] = localP->dydt_Y0;

  // InitializeConditions for Delay: '<S198>/Delay1'
  localDW->Delay1_DSTATE[1] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S198>/dy//dt'
  rty_dydt[1] = localP->dydt_Y0;

  // InitializeConditions for Delay: '<S198>/Delay1'
  localDW->Delay1_DSTATE[2] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S198>/dy//dt'
  rty_dydt[2] = localP->dydt_Y0;
}

//
// Disable for enable system:
//    '<S193>/Enabled Subsystem'
//    '<S203>/Enabled Subsystem'
//    '<S213>/Enabled Subsystem'
//
void Fullex_EnabledSubsystem_Disable(DW_EnabledSubsystem_Fullexp_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

//
// Outputs for enable system:
//    '<S193>/Enabled Subsystem'
//    '<S203>/Enabled Subsystem'
//    '<S213>/Enabled Subsystem'
//
void Fullexp_EnabledSubsystem(const boolean_T rtu_Enable[3], const real_T rtu_y
  [3], real_T rtu_dt, real_T rty_dydt[3], B_EnabledSubsystem_Fullexp_T *localB,
  DW_EnabledSubsystem_Fullexp_T *localDW, P_EnabledSubsystem_Fullexp_T *localP)
{
  real_T ema;
  real_T x;

  // Outputs for Enabled SubSystem: '<S193>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S198>/Enable'

  if (rtu_Enable[0] || rtu_Enable[1] || rtu_Enable[2]) {
    localDW->EnabledSubsystem_MODE = true;
  } else if (localDW->EnabledSubsystem_MODE) {
    Fullex_EnabledSubsystem_Disable(localDW);
  }

  if (localDW->EnabledSubsystem_MODE) {
    // Delay: '<S198>/Delay'
    if (localDW->icLoad) {
      localDW->Delay_DSTATE[0] = rtu_y[0];
      localDW->Delay_DSTATE[1] = rtu_y[1];
      localDW->Delay_DSTATE[2] = rtu_y[2];
    }

    // MATLAB Function: '<S198>/MATLAB Function' incorporates:
    //   Constant: '<S198>/Constant2'

    x = exp(-rtu_dt / localP->Constant2_Value);

    // Delay: '<S198>/Delay'
    localB->Delay[0] = localDW->Delay_DSTATE[0];

    // Delay: '<S198>/Delay1'
    localB->Delay1[0] = localDW->Delay1_DSTATE[0];

    // MATLAB Function: '<S198>/MATLAB Function' incorporates:
    //   Delay: '<S198>/Delay'

    ema = (1.0 - (1.0 - x)) * localDW->Delay_DSTATE[0] + (1.0 - x) * rtu_y[0];
    localB->ema[0] = ema;

    // MATLAB Function: '<S198>/MATLAB Function' incorporates:
    //   Delay: '<S198>/Delay'

    rty_dydt[0] = (ema - localDW->Delay_DSTATE[0]) / rtu_dt;

    // Delay: '<S198>/Delay'
    localB->Delay[1] = localDW->Delay_DSTATE[1];

    // Delay: '<S198>/Delay1'
    localB->Delay1[1] = localDW->Delay1_DSTATE[1];

    // MATLAB Function: '<S198>/MATLAB Function' incorporates:
    //   Delay: '<S198>/Delay'

    ema = (1.0 - (1.0 - x)) * localDW->Delay_DSTATE[1] + (1.0 - x) * rtu_y[1];
    localB->ema[1] = ema;

    // MATLAB Function: '<S198>/MATLAB Function' incorporates:
    //   Delay: '<S198>/Delay'

    rty_dydt[1] = (ema - localDW->Delay_DSTATE[1]) / rtu_dt;

    // Delay: '<S198>/Delay'
    localB->Delay[2] = localDW->Delay_DSTATE[2];

    // Delay: '<S198>/Delay1'
    localB->Delay1[2] = localDW->Delay1_DSTATE[2];

    // MATLAB Function: '<S198>/MATLAB Function' incorporates:
    //   Delay: '<S198>/Delay'

    ema = (1.0 - (1.0 - x)) * localDW->Delay_DSTATE[2] + (1.0 - x) * rtu_y[2];
    localB->ema[2] = ema;

    // MATLAB Function: '<S198>/MATLAB Function' incorporates:
    //   Delay: '<S198>/Delay'

    rty_dydt[2] = (ema - localDW->Delay_DSTATE[2]) / rtu_dt;
  }

  // End of Outputs for SubSystem: '<S193>/Enabled Subsystem'
}

//
// Update for enable system:
//    '<S193>/Enabled Subsystem'
//    '<S203>/Enabled Subsystem'
//    '<S213>/Enabled Subsystem'
//
void Fullexp_EnabledSubsystem_Update(real_T rty_dydt[3],
  B_EnabledSubsystem_Fullexp_T *localB, DW_EnabledSubsystem_Fullexp_T *localDW)
{
  // Update for Enabled SubSystem: '<S193>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S198>/Enable'

  if (localDW->EnabledSubsystem_MODE) {
    // Update for Delay: '<S198>/Delay'
    localDW->icLoad = false;
    localDW->Delay_DSTATE[0] = localB->ema[0];

    // Update for Delay: '<S198>/Delay1'
    localDW->Delay1_DSTATE[0] = rty_dydt[0];

    // Update for Delay: '<S198>/Delay'
    localDW->Delay_DSTATE[1] = localB->ema[1];

    // Update for Delay: '<S198>/Delay1'
    localDW->Delay1_DSTATE[1] = rty_dydt[1];

    // Update for Delay: '<S198>/Delay'
    localDW->Delay_DSTATE[2] = localB->ema[2];

    // Update for Delay: '<S198>/Delay1'
    localDW->Delay1_DSTATE[2] = rty_dydt[2];
  }

  // End of Update for SubSystem: '<S193>/Enabled Subsystem'
}

//
// System initialize for enable system:
//    '<S194>/Enabled Subsystem'
//    '<S204>/Enabled Subsystem'
//    '<S214>/Enabled Subsystem'
//
void Fullexp_EnabledSubsystem_o_Init(real_T rty_dydt[3],
  DW_EnabledSubsystem_Fullexp_m_T *localDW, P_EnabledSubsystem_Fullexp_d_T
  *localP)
{
  // InitializeConditions for Delay: '<S200>/Delay'
  localDW->icLoad = true;

  // InitializeConditions for Delay: '<S200>/Delay1'
  localDW->Delay1_DSTATE[0] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S200>/dy//dt'
  rty_dydt[0] = localP->dydt_Y0;

  // InitializeConditions for Delay: '<S200>/Delay1'
  localDW->Delay1_DSTATE[1] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S200>/dy//dt'
  rty_dydt[1] = localP->dydt_Y0;

  // InitializeConditions for Delay: '<S200>/Delay1'
  localDW->Delay1_DSTATE[2] = localP->Delay1_InitialCondition;

  // SystemInitialize for Outport: '<S200>/dy//dt'
  rty_dydt[2] = localP->dydt_Y0;
}

//
// Disable for enable system:
//    '<S194>/Enabled Subsystem'
//    '<S204>/Enabled Subsystem'
//    '<S214>/Enabled Subsystem'
//
void Full_EnabledSubsystem_g_Disable(DW_EnabledSubsystem_Fullexp_m_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

//
// Outputs for enable system:
//    '<S194>/Enabled Subsystem'
//    '<S204>/Enabled Subsystem'
//    '<S214>/Enabled Subsystem'
//
void Fullexp_EnabledSubsystem_n(const boolean_T rtu_Enable[3], real_T rtu_y,
  real_T rtu_y_p, real_T rtu_y_o, real_T rtu_dt, real_T rty_dydt[3],
  B_EnabledSubsystem_Fullexp_b_T *localB, DW_EnabledSubsystem_Fullexp_m_T
  *localDW, P_EnabledSubsystem_Fullexp_d_T *localP)
{
  real_T x;

  // Outputs for Enabled SubSystem: '<S194>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S200>/Enable'

  if (rtu_Enable[0] || rtu_Enable[1] || rtu_Enable[2]) {
    localDW->EnabledSubsystem_MODE = true;
  } else if (localDW->EnabledSubsystem_MODE) {
    Full_EnabledSubsystem_g_Disable(localDW);
  }

  if (localDW->EnabledSubsystem_MODE) {
    // Delay: '<S200>/Delay' incorporates:
    //   SignalConversion generated from: '<S200>/Delay'

    if (localDW->icLoad) {
      localDW->Delay_DSTATE[0] = rtu_y;
      localDW->Delay_DSTATE[1] = rtu_y_p;
      localDW->Delay_DSTATE[2] = rtu_y_o;
    }

    // Delay: '<S200>/Delay'
    localB->Delay[0] = localDW->Delay_DSTATE[0];

    // Delay: '<S200>/Delay1'
    localB->Delay1[0] = localDW->Delay1_DSTATE[0];

    // Delay: '<S200>/Delay'
    localB->Delay[1] = localDW->Delay_DSTATE[1];

    // Delay: '<S200>/Delay1'
    localB->Delay1[1] = localDW->Delay1_DSTATE[1];

    // Delay: '<S200>/Delay'
    localB->Delay[2] = localDW->Delay_DSTATE[2];

    // Delay: '<S200>/Delay1'
    localB->Delay1[2] = localDW->Delay1_DSTATE[2];

    // MATLAB Function: '<S200>/MATLAB Function' incorporates:
    //   Constant: '<S200>/Constant2'
    //   SignalConversion generated from: '<S201>/ SFunction '

    x = exp(-rtu_dt / localP->Constant2_Value);
    localB->ema[0] = (1.0 - (1.0 - x)) * localB->Delay[0] + (1.0 - x) * rtu_y;
    localB->ema[1] = (1.0 - (1.0 - x)) * localB->Delay[1] + (1.0 - x) * rtu_y_p;
    localB->ema[2] = (1.0 - (1.0 - x)) * localB->Delay[2] + (1.0 - x) * rtu_y_o;
    rty_dydt[0] = (localB->ema[0] - localB->Delay[0]) / rtu_dt;
    rty_dydt[1] = (localB->ema[1] - localB->Delay[1]) / rtu_dt;
    rty_dydt[2] = (localB->ema[2] - localB->Delay[2]) / rtu_dt;
  }

  // End of Outputs for SubSystem: '<S194>/Enabled Subsystem'
}

//
// Update for enable system:
//    '<S194>/Enabled Subsystem'
//    '<S204>/Enabled Subsystem'
//    '<S214>/Enabled Subsystem'
//
void Fulle_EnabledSubsystem_g_Update(real_T rty_dydt[3],
  B_EnabledSubsystem_Fullexp_b_T *localB, DW_EnabledSubsystem_Fullexp_m_T
  *localDW)
{
  // Update for Enabled SubSystem: '<S194>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S200>/Enable'

  if (localDW->EnabledSubsystem_MODE) {
    // Update for Delay: '<S200>/Delay'
    localDW->icLoad = false;
    localDW->Delay_DSTATE[0] = localB->ema[0];

    // Update for Delay: '<S200>/Delay1'
    localDW->Delay1_DSTATE[0] = rty_dydt[0];

    // Update for Delay: '<S200>/Delay'
    localDW->Delay_DSTATE[1] = localB->ema[1];

    // Update for Delay: '<S200>/Delay1'
    localDW->Delay1_DSTATE[1] = rty_dydt[1];

    // Update for Delay: '<S200>/Delay'
    localDW->Delay_DSTATE[2] = localB->ema[2];

    // Update for Delay: '<S200>/Delay1'
    localDW->Delay1_DSTATE[2] = rty_dydt[2];
  }

  // End of Update for SubSystem: '<S194>/Enabled Subsystem'
}

// Function for MATLAB Function: '<S19>/MATLAB Function'
void Fullexp_rotm2Quat(const real_T C[9], real_T q[4])
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

//
// Output and update for atomic system:
//    '<S19>/MATLAB Function'
//    '<S20>/MATLAB Function'
//
void Fullexp_MATLABFunction_l(const real_T rtu_u[12], real_T rty_dq[8], real_T
  rty_q[4], real_T rty_R[9], real_T rty_x[3], real_T rty_v[3], real_T rty_w[3],
  real_T *rty_yaw)
{
  real_T T[16];
  real_T T_0[9];
  real_T qr[4];
  real_T v[3];
  real_T v_0[3];
  real_T c;
  real_T qr_0;
  real_T v_1;
  int32_T T_tmp;
  int32_T i;
  v_1 = sin(rtu_u[5]);
  c = cos(rtu_u[5]);
  rty_R[0] = c;
  rty_R[3] = v_1;
  rty_R[6] = 0.0;
  rty_R[1] = -v_1;
  rty_R[4] = c;
  rty_R[7] = 0.0;
  rty_v[0] = rtu_u[6];
  rty_w[0] = rtu_u[9];
  rty_R[2] = 0.0;
  rty_v[1] = rtu_u[7];
  rty_w[1] = rtu_u[10];
  rty_R[5] = 0.0;
  rty_v[2] = rtu_u[8];
  rty_w[2] = rtu_u[11];
  rty_R[8] = 1.0;
  *rty_yaw = rtu_u[5];
  for (i = 0; i < 3; i++) {
    rty_x[i] = 0.0;
    T_tmp = i << 2;
    T[T_tmp] = rty_R[3 * i];
    T[T_tmp + 1] = rty_R[3 * i + 1];
    T[T_tmp + 2] = rty_R[3 * i + 2];
    T[i + 12] = 0.0;
  }

  T[3] = 0.0;
  T[7] = 0.0;
  T[11] = 0.0;
  T[15] = 1.0;
  Fullexp_rotm2Quat(rty_R, rty_q);
  for (i = 0; i < 3; i++) {
    T_tmp = i << 2;
    T_0[3 * i] = T[T_tmp];
    T_0[3 * i + 1] = T[T_tmp + 1];
    T_0[3 * i + 2] = T[T_tmp + 2];
  }

  Fullexp_rotm2Quat(T_0, qr);
  v_1 = T[12] / 2.0;
  v[0] = v_1;
  c = qr[1] * v_1;
  v_1 = T[13] / 2.0;
  v[1] = v_1;
  c += qr[2] * v_1;
  v_1 = T[14] / 2.0;
  v[2] = v_1;
  qr_0 = qr[0];
  T_0[0] = 0.0;
  T_0[3] = -qr[3];
  T_0[6] = qr[2];
  T_0[1] = qr[3];
  T_0[4] = 0.0;
  T_0[7] = -qr[1];
  T_0[2] = -qr[2];
  T_0[5] = qr[1];
  T_0[8] = 0.0;
  for (i = 0; i < 3; i++) {
    v_0[i] = v[i] * qr_0 - ((T_0[i + 3] * v[1] + T_0[i] * v[0]) + T_0[i + 6] *
      v_1);
  }

  rty_dq[0] = qr[0];
  rty_dq[1] = qr[1];
  rty_dq[2] = qr[2];
  rty_dq[3] = qr[3];
  rty_dq[4] = -(qr[3] * v_1 + c);
  rty_dq[5] = v_0[0];
  rty_dq[6] = v_0[1];
  rty_dq[7] = v_0[2];
}

static real_T Fullexp_xzlangeM(const real_T x[24])
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

static void Fullexp_xzlascl(real_T cfrom, real_T cto, real_T A[24])
{
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;

  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
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

  // End of Start for MATLABSystem: '<S239>/Pseudoinverse1'
}

static real_T Fullexp_xnrm2(int32_T n, const real_T x[24], int32_T ix0)
{
  real_T scale;
  real_T y;
  int32_T kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;

  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
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

  // End of Start for MATLABSystem: '<S239>/Pseudoinverse1'
  return scale * sqrt(y);
}

static real_T Fullexp_xdotc(int32_T n, const real_T x[24], int32_T ix0, const
  real_T y[24], int32_T iy0)
{
  real_T d;
  int32_T b;
  d = 0.0;

  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
  b = static_cast<uint8_T>(n);
  for (int32_T k = 0; k < b; k++) {
    // Start for MATLABSystem: '<S239>/Pseudoinverse1'
    d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
  }

  return d;
}

static void Fullexp_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[24],
  int32_T iy0)
{
  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
  if (!(a == 0.0)) {
    for (int32_T k = 0; k < n; k++) {
      int32_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += y[(ix0 + k) - 1] * a;
    }
  }

  // End of Start for MATLABSystem: '<S239>/Pseudoinverse1'
}

static real_T Fullexp_xdotc_o(const real_T x[9], const real_T y[9], int32_T iy0)
{
  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
  return y[iy0 - 1] * x[1] + x[2] * y[iy0];
}

static void Fullexp_xaxpy_gop(real_T a, real_T y[9], int32_T iy0)
{
  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
  if (!(a == 0.0)) {
    y[iy0 - 1] += a * y[1];
    y[iy0] += a * y[2];
  }

  // End of Start for MATLABSystem: '<S239>/Pseudoinverse1'
}

static real_T Fullexp_xnrm2_p(const real_T x[3], int32_T ix0)
{
  real_T scale;
  real_T y;
  y = 0.0;
  scale = 3.3121686421112381E-170;

  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
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

  // End of Start for MATLABSystem: '<S239>/Pseudoinverse1'
  return scale * sqrt(y);
}

static void Fullexp_xaxpy_g(int32_T n, real_T a, const real_T x[24], int32_T ix0,
  real_T y[8], int32_T iy0)
{
  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
  if (!(a == 0.0)) {
    for (int32_T k = 0; k < n; k++) {
      int32_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += x[(ix0 + k) - 1] * a;
    }
  }

  // End of Start for MATLABSystem: '<S239>/Pseudoinverse1'
}

static void Fullexp_xaxpy_go(int32_T n, real_T a, const real_T x[8], int32_T ix0,
  real_T y[24], int32_T iy0)
{
  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
  if (!(a == 0.0)) {
    for (int32_T k = 0; k < n; k++) {
      int32_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += x[(ix0 + k) - 1] * a;
    }
  }

  // End of Start for MATLABSystem: '<S239>/Pseudoinverse1'
}

static void Fullexp_xzlascl_i(real_T cfrom, real_T cto, real_T A[3])
{
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;

  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
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

  // End of Start for MATLABSystem: '<S239>/Pseudoinverse1'
}

static void Fullexp_xrotg(real_T a, real_T b, real_T *b_a, real_T *b_b, real_T
  *c, real_T *s)
{
  real_T absa;
  real_T absb;
  real_T roe;
  real_T scale;

  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
  roe = b;
  absa = fabs(a);
  absb = fabs(b);
  if (absa > absb) {
    // Start for MATLABSystem: '<S239>/Pseudoinverse1'
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

    // Start for MATLABSystem: '<S239>/Pseudoinverse1'
    *b_a = sqrt(ads * ads + bds * bds) * scale;
    if (roe < 0.0) {
      *b_a = -*b_a;
    }

    // Start for MATLABSystem: '<S239>/Pseudoinverse1'
    *c = a / *b_a;
    *s = b / *b_a;
    if (absa > absb) {
      *b_b = *s;
    } else if (*c != 0.0) {
      // Start for MATLABSystem: '<S239>/Pseudoinverse1'
      *b_b = 1.0 / *c;
    } else {
      *b_b = 1.0;
    }
  }
}

static void Fullexp_xrot_ps(real_T x[9], int32_T ix0, int32_T iy0, real_T c,
  real_T s)
{
  real_T temp;
  real_T temp_tmp;

  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
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

static void Fullexp_xrot_psj(real_T x[24], int32_T ix0, int32_T iy0, real_T c,
  real_T s)
{
  for (int32_T k = 0; k < 8; k++) {
    real_T temp_tmp;
    real_T temp_tmp_0;
    int32_T temp_tmp_tmp;
    int32_T temp_tmp_tmp_0;

    // Start for MATLABSystem: '<S239>/Pseudoinverse1'
    temp_tmp_tmp = (iy0 + k) - 1;
    temp_tmp = x[temp_tmp_tmp];

    // Start for MATLABSystem: '<S239>/Pseudoinverse1'
    temp_tmp_tmp_0 = (ix0 + k) - 1;
    temp_tmp_0 = x[temp_tmp_tmp_0];

    // Start for MATLABSystem: '<S239>/Pseudoinverse1'
    x[temp_tmp_tmp] = temp_tmp * c - temp_tmp_0 * s;
    x[temp_tmp_tmp_0] = temp_tmp_0 * c + temp_tmp * s;
  }
}

static void Fullexp_xswap_dj(real_T x[9], int32_T ix0, int32_T iy0)
{
  real_T temp;

  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
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

static void Fullexp_xswap_dj5(real_T x[24], int32_T ix0, int32_T iy0)
{
  for (int32_T k = 0; k < 8; k++) {
    real_T temp;
    int32_T temp_tmp;
    int32_T tmp;

    // Start for MATLABSystem: '<S239>/Pseudoinverse1'
    temp_tmp = (ix0 + k) - 1;
    temp = x[temp_tmp];

    // Start for MATLABSystem: '<S239>/Pseudoinverse1'
    tmp = (iy0 + k) - 1;
    x[temp_tmp] = x[tmp];
    x[tmp] = temp;
  }
}

static void Fullexp_svd(const real_T A[24], real_T U[24], real_T s[3], real_T V
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

  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
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

  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
  anrm = Fullexp_xzlangeM(A);
  cscale = anrm;

  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
  if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
    doscale = true;
    cscale = 6.7178761075670888E-139;
    Fullexp_xzlascl(anrm, cscale, A_0);
  } else if (anrm > 1.4885657073574029E+138) {
    doscale = true;
    cscale = 1.4885657073574029E+138;
    Fullexp_xzlascl(anrm, cscale, A_0);
  }

  for (i = 0; i < 3; i++) {
    // Start for MATLABSystem: '<S239>/Pseudoinverse1'
    qp1 = i + 2;
    qq_tmp_tmp = i << 3;

    // Start for MATLABSystem: '<S239>/Pseudoinverse1'
    colqp1 = qq_tmp_tmp + i;
    qq = colqp1 + 1;
    apply_transform = false;

    // Start for MATLABSystem: '<S239>/Pseudoinverse1'
    nrm = Fullexp_xnrm2(8 - i, A_0, colqp1 + 1);
    if (nrm > 0.0) {
      apply_transform = true;

      // Start for MATLABSystem: '<S239>/Pseudoinverse1'
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
      // Start for MATLABSystem: '<S239>/Pseudoinverse1'
      qjj = (((qq - 1) << 3) + i) + 1;
      if (apply_transform) {
        // Start for MATLABSystem: '<S239>/Pseudoinverse1'
        Fullexp_xaxpy(8 - i, -(Fullexp_xdotc(8 - i, A_0, colqp1 + 1, A_0, qjj) /
          A_0[colqp1]), colqp1 + 1, A_0, qjj);
      }

      e[qq - 1] = A_0[qjj - 1];
    }

    // Start for MATLABSystem: '<S239>/Pseudoinverse1'
    for (colqp1 = i + 1; colqp1 < 9; colqp1++) {
      qjj = (qq_tmp_tmp + colqp1) - 1;
      U[qjj] = A_0[qjj];
    }

    if (i + 1 <= 1) {
      nrm = Fullexp_xnrm2_p(e, i + 2);
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
          Fullexp_xaxpy_g(7 - i, e[colqp1 - 1], A_0, (i + ((colqp1 - 1) << 3)) +
                          2, work, i + 2);
        }

        for (colqp1 = qp1; colqp1 < 4; colqp1++) {
          Fullexp_xaxpy_go(7 - i, -e[colqp1 - 1] / e[i + 1], work, i + 2, A_0,
                           (i + ((colqp1 - 1) << 3)) + 2);
        }
      }

      for (colqp1 = qp1; colqp1 < 4; colqp1++) {
        Vf[colqp1 - 1] = e[colqp1 - 1];
      }
    }
  }

  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
  i = 2;
  e[1] = A_0[17];
  e[2] = 0.0;

  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
  for (qp1 = 2; qp1 >= 0; qp1--) {
    colqp1 = qp1 << 3;
    qq = colqp1 + qp1;
    if (s_0[qp1] != 0.0) {
      for (qq_tmp_tmp = qp1 + 2; qq_tmp_tmp < 4; qq_tmp_tmp++) {
        qjj = (((qq_tmp_tmp - 1) << 3) + qp1) + 1;
        Fullexp_xaxpy(8 - qp1, -(Fullexp_xdotc(8 - qp1, U, qq + 1, U, qjj) /
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
      Fullexp_xaxpy_gop(-(Fullexp_xdotc_o(Vf, Vf, 5) / Vf[1]), Vf, 5);
      Fullexp_xaxpy_gop(-(Fullexp_xdotc_o(Vf, Vf, 8) / Vf[1]), Vf, 8);
    }

    Vf[3 * qp1] = 0.0;
    Vf[3 * qp1 + 1] = 0.0;
    Vf[3 * qp1 + 2] = 0.0;
    Vf[qp1 + 3 * qp1] = 1.0;
  }

  for (qp1 = 0; qp1 < 3; qp1++) {
    r = s_0[qp1];
    if (r != 0.0) {
      // Start for MATLABSystem: '<S239>/Pseudoinverse1'
      nrm = fabs(r);
      r /= nrm;
      s_0[qp1] = nrm;

      // Start for MATLABSystem: '<S239>/Pseudoinverse1'
      if (qp1 + 1 < 3) {
        e[qp1] /= r;
      }

      qq = qp1 << 3;

      // Start for MATLABSystem: '<S239>/Pseudoinverse1'
      for (qjj = qq + 1; qjj <= qq + 8; qjj++) {
        U[qjj - 1] *= r;
      }
    }

    // Start for MATLABSystem: '<S239>/Pseudoinverse1'
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

  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
  ztest = fabs(s_0[0]);
  nrm = fabs(e[0]);
  if ((ztest >= nrm) || rtIsNaN(nrm)) {
    nrm = ztest;
  }

  if ((!(nrm <= 0.0)) && (!rtIsNaN(nrm))) {
    r = nrm;
  }

  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
  ztest = fabs(s_0[1]);
  nrm = fabs(e[1]);
  if ((ztest >= nrm) || rtIsNaN(nrm)) {
    nrm = ztest;
  }

  if ((!(r >= nrm)) && (!rtIsNaN(nrm))) {
    r = nrm;
  }

  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
  ztest = fabs(s_0[2]);
  nrm = fabs(e[2]);
  if ((ztest >= nrm) || rtIsNaN(nrm)) {
    nrm = ztest;
  }

  if ((!(r >= nrm)) && (!rtIsNaN(nrm))) {
    r = nrm;
  }

  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
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
        Fullexp_xrotg(s_0[qq - 1], nrm, &s_0[qq - 1], &nrm, &ztest, &sqds);
        if (qq > colqp1 + 1) {
          nrm = -sqds * e[0];
          e[0] *= ztest;
        }

        Fullexp_xrot_ps(Vf, 3 * (qq - 1) + 1, 3 * i + 1, ztest, sqds);
      }
      break;

     case 2:
      nrm = e[colqp1 - 1];
      e[colqp1 - 1] = 0.0;
      for (qq = colqp1 + 1; qq <= i + 1; qq++) {
        Fullexp_xrotg(s_0[qq - 1], nrm, &s_0[qq - 1], &ztest, &sqds, &b);
        ztest = e[qq - 1];
        nrm = -b * ztest;
        e[qq - 1] = ztest * sqds;
        Fullexp_xrot_psj(U, ((qq - 1) << 3) + 1, ((colqp1 - 1) << 3) + 1, sqds,
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
        Fullexp_xrotg(nrm, ztest, &smm1, &emm1, &sqds, &b);
        if (qq > colqp1 + 1) {
          e[0] = smm1;
        }

        smm1 = e[qq - 1];
        nrm = s_0[qq - 1];
        e[qq - 1] = smm1 * sqds - nrm * b;
        ztest = b * s_0[qq];
        s_0[qq] *= sqds;
        Fullexp_xrot_ps(Vf, 3 * (qq - 1) + 1, 3 * qq + 1, sqds, b);
        Fullexp_xrotg(nrm * sqds + smm1 * b, ztest, &s_0[qq - 1], &a__3, &emm1,
                      &d_sn);
        smm1 = e[qq - 1];
        nrm = smm1 * emm1 + d_sn * s_0[qq];
        s_0[qq] = smm1 * -d_sn + emm1 * s_0[qq];
        ztest = d_sn * e[qq];
        e[qq] *= emm1;
        Fullexp_xrot_psj(U, ((qq - 1) << 3) + 1, (qq << 3) + 1, emm1, d_sn);
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
        Fullexp_xswap_dj(Vf, 3 * colqp1 + 1, 3 * (colqp1 + 1) + 1);
        Fullexp_xswap_dj5(U, (colqp1 << 3) + 1, ((colqp1 + 1) << 3) + 1);
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
    // Start for MATLABSystem: '<S239>/Pseudoinverse1'
    Fullexp_xzlascl_i(cscale, anrm, s);
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
void Fullexp_Pseudoinverse1_Init(DW_Pseudoinverse1_Fullexp_T *localDW)
{
  // Start for MATLABSystem: '<S239>/Pseudoinverse1'
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
}

// Output and update for atomic system:
void Fullexp_Pseudoinverse1(const real_T rtu_0[24], B_Pseudoinverse1_Fullexp_T
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

  // MATLABSystem: '<S239>/Pseudoinverse1'
  for (i = 0; i < 24; i++) {
    // Start for MATLABSystem: '<S239>/Pseudoinverse1'
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
      Fullexp_svd(A, U, s, V);
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

  // End of MATLABSystem: '<S239>/Pseudoinverse1'
}

// Function for MATLAB Function: '<S236>/MATLAB Function1'
static real_T Fullexp_maximum(const real_T x[8])
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
//    '<S236>/MATLAB Function1'
//    '<S248>/MATLAB Function1'
//    '<S260>/MATLAB Function8'
//
void Fullexp_MATLABFunction1(const real_T rtu_ThrustPer[8], real_T
  rty_ThrustPer_Final[8])
{
  real_T TControl;
  real_T ThrustPer_Sat;
  real_T maxval;
  int32_T i;
  TControl = 1.0 / Fullexp_P.PWMFreq;
  maxval = Fullexp_maximum(rtu_ThrustPer);
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
//    '<S242>/Create Rotation Matrix'
//    '<S254>/Create Rotation Matrix'
//    '<S266>/Create Rotation Matrix'
//
void Fullexp_CreateRotationMatrix(real_T rtu_Rz, real_T rty_C_Ib[4])
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
//    '<S237>/Create Rotation Matrix'
//    '<S249>/Create Rotation Matrix'
//    '<S261>/Create Rotation Matrix'
//
void Fullexp_CreateRotationMatrix_a(real_T rtu_Rz, real_T rty_C_bI[4])
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

// Function for MATLAB Function: '<S5>/MATLAB Function1'
static void Fullexp_timeKeeper(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime)
{
  coderTimespec origTimespec;
  if (!Fullexp_DW.savedTime_not_empty_d) {
    if (!Fullexp_DW.freq_not_empty_m) {
      Fullexp_DW.freq_not_empty_m = true;
      coderInitTimeFunctions(&Fullexp_DW.freq_l);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq_l);
    Fullexp_DW.savedTime_not_empty_d = true;
  }

  savedTime->tv_sec = newTime_tv_sec;
  savedTime->tv_nsec = newTime_tv_nsec;
}

// Function for MATLAB Function: '<S5>/MATLAB Function1'
static void Fullexp_tic(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime)
{
  coderTimespec origTimespec;
  if (!Fullexp_DW.freq_not_empty_m) {
    Fullexp_DW.freq_not_empty_m = true;
    coderInitTimeFunctions(&Fullexp_DW.freq_l);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq_l);
  Fullexp_timeKeeper(origTimespec.tv_sec, origTimespec.tv_nsec, savedTime);
}

// Function for MATLAB Function: '<S22>/MATLAB Function1'
void Fullexp_dqMultiply(const real_T q[8], const real_T p[8], real_T dq[8])
{
  real_T q_1[16];
  real_T q_2[16];
  real_T q_3[16];
  real_T dq_tmp[9];
  real_T tmp_1[9];
  real_T c_vector[3];
  real_T tmp[3];
  real_T tmp_0[3];
  real_T vector_tmp[3];
  real_T vector_tmp_0[3];
  real_T vector_tmp_1[3];
  real_T vector_tmp_2[3];
  real_T vector_tmp_3[3];
  real_T dq_tmp_0;
  real_T dq_tmp_1;
  real_T dq_tmp_2;
  real_T p_0;
  real_T p_1;
  real_T p_2;
  real_T q_0;
  real_T vector_tmp_4;
  int32_T dq_tmp_tmp_0;
  int8_T dq_tmp_tmp[9];
  static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  vector_tmp[0] = q[1];
  vector_tmp[1] = q[2];
  vector_tmp[2] = q[3];
  c_vector[0] = q[5];
  c_vector[1] = q[6];
  c_vector[2] = q[7];
  q_0 = q[0];
  for (int32_T i = 0; i < 9; i++) {
    dq_tmp_tmp_0 = b[i];
    dq_tmp_tmp[i] = static_cast<int8_T>(dq_tmp_tmp_0);
    dq_tmp[i] = q_0 * static_cast<real_T>(dq_tmp_tmp_0);
  }

  tmp[0] = 0.0;
  tmp[1] = -q[3];
  tmp[2] = q[2];
  vector_tmp_0[0] = q[3];
  vector_tmp_0[1] = 0.0;
  vector_tmp_0[2] = -q[1];
  vector_tmp_1[0] = -q[2];
  vector_tmp_1[1] = q[1];
  vector_tmp_1[2] = 0.0;
  q_1[0] = q[0];
  tmp_0[0] = 0.0;
  tmp_0[1] = -q[3];
  tmp_0[2] = q[2];
  vector_tmp_2[0] = q[3];
  vector_tmp_2[1] = 0.0;
  vector_tmp_2[2] = -q[1];
  vector_tmp_3[0] = -q[2];
  vector_tmp_3[1] = q[1];
  vector_tmp_3[2] = 0.0;
  q_2[0] = q[0];
  q_0 = q[4];
  tmp_1[0] = 0.0;
  tmp_1[3] = -q[7];
  tmp_1[6] = q[6];
  tmp_1[1] = q[7];
  tmp_1[4] = 0.0;
  tmp_1[7] = -q[5];
  tmp_1[2] = -q[6];
  tmp_1[5] = q[5];
  tmp_1[8] = 0.0;
  q_3[0] = q[4];
  for (int32_T i = 0; i < 3; i++) {
    int32_T dq_tmp_tmp_1;
    int32_T q_tmp;
    vector_tmp_4 = vector_tmp[i];
    q_tmp = (i + 1) << 2;
    q_1[q_tmp] = -vector_tmp_4;
    q_1[i + 1] = vector_tmp_4;
    dq_tmp_0 = dq_tmp[3 * i];
    q_1[q_tmp + 1] = dq_tmp_0 + tmp[i];
    dq_tmp_tmp_0 = 3 * i + 1;
    dq_tmp_1 = dq_tmp[dq_tmp_tmp_0];
    q_1[q_tmp + 2] = dq_tmp_1 + vector_tmp_0[i];
    dq_tmp_tmp_1 = 3 * i + 2;
    dq_tmp_2 = dq_tmp[dq_tmp_tmp_1];
    q_1[q_tmp + 3] = dq_tmp_2 + vector_tmp_1[i];
    q_2[q_tmp] = -vector_tmp_4;
    q_2[i + 1] = vector_tmp_4;
    q_2[q_tmp + 1] = dq_tmp_0 + tmp_0[i];
    q_2[q_tmp + 2] = dq_tmp_1 + vector_tmp_2[i];
    q_2[q_tmp + 3] = dq_tmp_2 + vector_tmp_3[i];
    vector_tmp_4 = c_vector[i];
    q_3[q_tmp] = -vector_tmp_4;
    q_3[i + 1] = vector_tmp_4;
    q_3[q_tmp + 1] = static_cast<real_T>(dq_tmp_tmp[3 * i]) * q_0 + tmp_1[3 * i];
    q_3[q_tmp + 2] = static_cast<real_T>(dq_tmp_tmp[dq_tmp_tmp_0]) * q_0 +
      tmp_1[dq_tmp_tmp_0];
    q_3[q_tmp + 3] = static_cast<real_T>(dq_tmp_tmp[dq_tmp_tmp_1]) * q_0 +
      tmp_1[dq_tmp_tmp_1];
  }

  q_0 = p[1];
  vector_tmp_4 = p[0];
  dq_tmp_0 = p[2];
  dq_tmp_1 = p[3];
  dq_tmp_2 = p[5];
  p_0 = p[4];
  p_1 = p[6];
  p_2 = p[7];
  for (int32_T i = 0; i < 4; i++) {
    dq[i] = ((q_1[i + 4] * q_0 + q_1[i] * vector_tmp_4) + q_1[i + 8] * dq_tmp_0)
      + q_1[i + 12] * dq_tmp_1;
    dq[i + 4] = (((q_2[i + 4] * dq_tmp_2 + q_2[i] * p_0) + q_2[i + 8] * p_1) +
                 q_2[i + 12] * p_2) + (((q_3[i + 4] * q_0 + q_3[i] *
      vector_tmp_4) + q_3[i + 8] * dq_tmp_0) + q_3[i + 12] * dq_tmp_1);
  }
}

// Function for MATLAB Function: '<S5>/MATLAB Function1'
static real_T Fullexp_rand(void)
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
      mti = Fullexp_DW.state_k[624] + 1U;
      if (Fullexp_DW.state_k[624] + 1U >= 625U) {
        for (int32_T kk = 0; kk < 227; kk++) {
          mti = (Fullexp_DW.state_k[kk + 1] & 2147483647U) |
            (Fullexp_DW.state_k[kk] & 2147483648U);
          if ((mti & 1U) == 0U) {
            mti >>= 1U;
          } else {
            mti = mti >> 1U ^ 2567483615U;
          }

          Fullexp_DW.state_k[kk] = Fullexp_DW.state_k[kk + 397] ^ mti;
        }

        for (int32_T kk = 0; kk < 396; kk++) {
          mti = (Fullexp_DW.state_k[kk + 227] & 2147483648U) |
            (Fullexp_DW.state_k[kk + 228] & 2147483647U);
          if ((mti & 1U) == 0U) {
            mti >>= 1U;
          } else {
            mti = mti >> 1U ^ 2567483615U;
          }

          Fullexp_DW.state_k[kk + 227] = Fullexp_DW.state_k[kk] ^ mti;
        }

        mti = (Fullexp_DW.state_k[623] & 2147483648U) | (Fullexp_DW.state_k[0] &
          2147483647U);
        if ((mti & 1U) == 0U) {
          mti >>= 1U;
        } else {
          mti = mti >> 1U ^ 2567483615U;
        }

        Fullexp_DW.state_k[623] = Fullexp_DW.state_k[396] ^ mti;
        mti = 1U;
      }

      y = Fullexp_DW.state_k[static_cast<int32_T>(mti) - 1];
      Fullexp_DW.state_k[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      b_u[k] = y >> 18U ^ y;
    }

    mti = b_u[0] >> 5U;
    y = b_u[1] >> 6U;
    if ((mti == 0U) && (y == 0U)) {
      boolean_T b_isvalid;
      b_isvalid = ((Fullexp_DW.state_k[624] >= 1U) && (Fullexp_DW.state_k[624] <
        625U));
      if (b_isvalid) {
        boolean_T exitg2;
        b_isvalid = false;
        k = 1;
        exitg2 = false;
        while ((!exitg2) && (k < 625)) {
          if (Fullexp_DW.state_k[k - 1] == 0U) {
            k++;
          } else {
            b_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!b_isvalid) {
        Fullexp_DW.state_k[0] = 5489U;
        Fullexp_DW.state_k[624] = 624U;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return (static_cast<real_T>(mti) * 6.7108864E+7 + static_cast<real_T>(y)) *
    1.1102230246251565E-16;
}

// Function for MATLAB Function: '<S5>/MATLAB Function1'
static real_T Fullexp_norm(const real_T x[3])
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

// Function for MATLAB Function: '<S5>/MATLAB Function1'
static void Fullexp_mrdiv_h(real_T A[72], const real_T B[36])
{
  real_T b_A[36];
  real_T smax;
  int32_T d_j;
  int32_T jA;
  int32_T jAcol;
  int32_T jBcol;
  int32_T jj;
  int32_T kBcol;
  int32_T n;
  int8_T ipiv[6];
  memcpy(&b_A[0], &B[0], 36U * sizeof(real_T));
  for (d_j = 0; d_j < 6; d_j++) {
    ipiv[d_j] = static_cast<int8_T>(d_j + 1);
  }

  for (d_j = 0; d_j < 5; d_j++) {
    jj = d_j * 7;
    n = 5 - d_j;
    jA = 0;
    smax = fabs(b_A[jj]);
    for (jBcol = 2; jBcol <= n + 1; jBcol++) {
      real_T s;
      s = fabs(b_A[(jj + jBcol) - 1]);
      if (s > smax) {
        jA = jBcol - 1;
        smax = s;
      }
    }

    if (b_A[jj + jA] != 0.0) {
      if (jA != 0) {
        n = d_j + jA;
        ipiv[d_j] = static_cast<int8_T>(n + 1);
        for (jBcol = 0; jBcol < 6; jBcol++) {
          jA = jBcol * 6 + d_j;
          smax = b_A[jA];
          jAcol = jBcol * 6 + n;
          b_A[jA] = b_A[jAcol];
          b_A[jAcol] = smax;
        }
      }

      n = (jj - d_j) + 6;
      for (jBcol = jj + 2; jBcol <= n; jBcol++) {
        b_A[jBcol - 1] /= b_A[jj];
      }
    }

    jA = jj + 8;
    jAcol = 4 - d_j;
    for (jBcol = 0; jBcol <= jAcol; jBcol++) {
      smax = b_A[(jBcol * 6 + jj) + 6];
      if (smax != 0.0) {
        kBcol = (jA - d_j) + 4;
        for (n = jA; n <= kBcol; n++) {
          b_A[n - 1] += b_A[((jj + n) - jA) + 1] * -smax;
        }
      }

      jA += 6;
    }
  }

  for (jj = 0; jj < 6; jj++) {
    jBcol = 12 * jj;
    jAcol = 6 * jj;
    for (n = 0; n < jj; n++) {
      kBcol = 12 * n;
      smax = b_A[n + jAcol];
      if (smax != 0.0) {
        for (jA = 0; jA < 12; jA++) {
          d_j = jA + jBcol;
          A[d_j] -= A[jA + kBcol] * smax;
        }
      }
    }

    smax = 1.0 / b_A[jj + jAcol];
    for (n = 0; n < 12; n++) {
      d_j = n + jBcol;
      A[d_j] *= smax;
    }
  }

  for (jj = 5; jj >= 0; jj--) {
    jA = 12 * jj;
    jAcol = 6 * jj - 1;
    for (jBcol = jj + 2; jBcol < 7; jBcol++) {
      kBcol = (jBcol - 1) * 12;
      smax = b_A[jBcol + jAcol];
      if (smax != 0.0) {
        for (n = 0; n < 12; n++) {
          d_j = n + jA;
          A[d_j] -= A[n + kBcol] * smax;
        }
      }
    }
  }

  for (jj = 4; jj >= 0; jj--) {
    int8_T ipiv_0;
    ipiv_0 = ipiv[jj];
    if (jj + 1 != ipiv_0) {
      for (jBcol = 0; jBcol < 12; jBcol++) {
        n = 12 * jj + jBcol;
        smax = A[n];
        d_j = (ipiv_0 - 1) * 12 + jBcol;
        A[n] = A[d_j];
        A[d_j] = smax;
      }
    }
  }
}

// Function for MATLAB Function: '<S5>/MATLAB Function1'
static void Fullexp_timeKeeper_e(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime,
  real_T *outTime_tv_sec, real_T *outTime_tv_nsec)
{
  coderTimespec origTimespec;
  if (!Fullexp_DW.savedTime_not_empty_d) {
    if (!Fullexp_DW.freq_not_empty_m) {
      Fullexp_DW.freq_not_empty_m = true;
      coderInitTimeFunctions(&Fullexp_DW.freq_l);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq_l);
    savedTime->tv_sec = origTimespec.tv_sec;
    savedTime->tv_nsec = origTimespec.tv_nsec;
  }

  *outTime_tv_sec = savedTime->tv_sec;
  *outTime_tv_nsec = savedTime->tv_nsec;
}

// Function for MATLAB Function: '<S5>/MATLAB Function1'
static real_T Fullexp_toc(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime)
{
  coderTimespec origTimespec;
  real_T t;
  real_T tstart_tv_nsec;
  real_T tstart_tv_sec;
  Fullexp_timeKeeper_e(savedTime, &tstart_tv_sec, &tstart_tv_nsec);
  if (!Fullexp_DW.freq_not_empty_m) {
    Fullexp_DW.freq_not_empty_m = true;
    coderInitTimeFunctions(&Fullexp_DW.freq_l);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq_l);
  t = (origTimespec.tv_nsec - tstart_tv_nsec) / 1.0E+9 + (origTimespec.tv_sec -
    tstart_tv_sec);
  return t;
}

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static void Fullexp_timeKeeper_h(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_o)
{
  coderTimespec origTimespec;
  if (!Fullexp_DW.savedTime_not_empty_g) {
    if (!Fullexp_DW.freq_not_empty_a) {
      Fullexp_DW.freq_not_empty_a = true;
      coderInitTimeFunctions(&Fullexp_DW.freq_i);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq_i);
    Fullexp_DW.savedTime_not_empty_g = true;
  }

  savedTime_o->tv_sec = newTime_tv_sec;
  savedTime_o->tv_nsec = newTime_tv_nsec;
}

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static void Fullexp_tic_k(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_o)
{
  coderTimespec origTimespec;
  if (!Fullexp_DW.freq_not_empty_a) {
    Fullexp_DW.freq_not_empty_a = true;
    coderInitTimeFunctions(&Fullexp_DW.freq_i);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq_i);
  Fullexp_timeKeeper_h(origTimespec.tv_sec, origTimespec.tv_nsec, savedTime_o);
}

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static real_T Fullexp_norm_hq(const real_T x[81])
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

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static void Fullexp_mpower(const real_T a[81], real_T b, real_T c[81])
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

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static real_T Fullexp_log2(real_T x)
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

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static void Fullexp_padeApproximation(const real_T A[81], const real_T A2[81],
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

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static void Fullexp_recomputeBlockDiag(const real_T A[81], real_T F[81], const
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

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static real_T Fullexp_xnrm2_n(int32_T n, const real_T x[81], int32_T ix0)
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

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static void Fullexp_xzsyhetrd(real_T A[81], real_T D[9], real_T E[8], real_T
  tau[8])
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
    xnorm = Fullexp_xnrm2_n(7 - i, A, ix0);
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

        xnorm = rt_hypotd_snf(temp2, Fullexp_xnrm2_n(7 - i, A, ix0));
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

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static void Fullexp_xzlascl_h(real_T cfrom, real_T cto, int32_T m, real_T A[9],
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

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static void Fullexp_xzlascl_ha(real_T cfrom, real_T cto, int32_T m, real_T A[8],
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

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static void Fullexp_xzlartg(real_T f, real_T g, real_T *cs, real_T *sn, real_T
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

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static void Fullexp_rotateRight_c(int32_T n, real_T z[81], int32_T iz0, const
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

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static void Fullexp_xdlaev2(real_T a, real_T b, real_T c, real_T *rt1, real_T
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

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static void Fullexp_rotateRight(int32_T n, real_T z[81], int32_T iz0, const
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

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static int32_T Fullexp_xzsteqr(real_T d[9], real_T e[8], real_T z[81])
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
            Fullexp_xzlascl_h(tst, 2.2346346549904327E+153, n_tmp, d, l + 1);
            Fullexp_xzlascl_ha(tst, 2.2346346549904327E+153, n_tmp - 1, e, l + 1);
          } else if (tst < 3.02546243347603E-123) {
            iscale = 2;
            Fullexp_xzlascl_h(tst, 3.02546243347603E-123, n_tmp, d, l + 1);
            Fullexp_xzlascl_ha(tst, 3.02546243347603E-123, n_tmp - 1, e, l + 1);
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
                Fullexp_xdlaev2(d[l], e[l], d[l + 1], &d[l], &b_anorm, &work[l],
                                &p);
                d[l + 1] = b_anorm;
                work[l + 8] = p;
                Fullexp_rotateRight(2, z, l * 9 + 1, work, l + 1, l + 9);
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
                  Fullexp_xzlartg(b_anorm, s * r, &c, &b_s, &b_r);
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

                Fullexp_rotateRight((m - l) + 1, z, l * 9 + 1, work, l + 1, l +
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
                Fullexp_xdlaev2(d[l - 1], e[l - 1], d[l], &d[l - 1], &b_anorm,
                                &work[m - 1], &p);
                d[l] = b_anorm;
                work[m + 7] = p;
                Fullexp_rotateRight_c(2, z, (l - 1) * 9 + 1, work, m, m + 8);
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
                  Fullexp_xzlartg(b_anorm, s * r, &c, &b_s, &b_r);
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

                Fullexp_rotateRight_c((l - m) + 2, z, (m - 1) * 9 + 1, work, m,
                                      m + 8);
                d[l] -= p;
                e[l - 1] = b_anorm;
              }
            } while (exitg3 == 0);
          }

          switch (iscale) {
           case 1:
            m = lendsv - lsv;
            Fullexp_xzlascl_h(2.2346346549904327E+153, tst, m + 1, d, lsv);
            Fullexp_xzlascl_ha(2.2346346549904327E+153, tst, m, e, lsv);
            break;

           case 2:
            m = lendsv - lsv;
            Fullexp_xzlascl_h(3.02546243347603E-123, tst, m + 1, d, lsv);
            Fullexp_xzlascl_ha(3.02546243347603E-123, tst, m, e, lsv);
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

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static void Fullexp_xsyheev(real_T A[81], int32_T *info, real_T W[9])
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

    Fullexp_xzsyhetrd(A, W, e, tau);
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

    *info = Fullexp_xzsteqr(W, e, A);
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

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static void Fullexp_expm(real_T A[81], real_T F[81])
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
        Fullexp_xsyheev(A2, &b_s, w);
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

        d6 = rt_powd_snf(Fullexp_norm_hq(A6), 0.16666666666666666);
        eta1 = rt_powd_snf(Fullexp_norm_hq(A4), 0.25);
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

          Fullexp_mpower(A4_0, 7.0, tmp);
          A4_1 = ceil(Fullexp_log2(Fullexp_norm_hq(tmp) / Fullexp_norm_hq(A) *
            2.0 / 2.2204460492503131E-16) / 6.0);
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

            Fullexp_mpower(A4_0, 11.0, tmp);
            A4_1 = ceil(Fullexp_log2(Fullexp_norm_hq(tmp) / Fullexp_norm_hq(A) *
              2.0 / 2.2204460492503131E-16) / 10.0);
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
          Fullexp_mpower(A4, 2.0, tmp);
          eta1 = rt_powd_snf(Fullexp_norm_hq(tmp), 0.125);
          if ((!(d6 >= eta1)) && (!rtIsNaN(eta1))) {
            d6 = eta1;
          }

          if (d6 <= 0.95041789961629319) {
            for (e_j = 0; e_j < 81; e_j++) {
              A4_0[e_j] = 0.090475336558796943 * fabs(A[e_j]);
            }

            Fullexp_mpower(A4_0, 15.0, tmp);
            A4_1 = ceil(Fullexp_log2(Fullexp_norm_hq(tmp) / Fullexp_norm_hq(A) *
              2.0 / 2.2204460492503131E-16) / 14.0);
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

            Fullexp_mpower(A4_0, 19.0, tmp);
            A4_1 = ceil(Fullexp_log2(Fullexp_norm_hq(tmp) / Fullexp_norm_hq(A) *
              2.0 / 2.2204460492503131E-16) / 18.0);
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

          A4_1 = rt_powd_snf(Fullexp_norm_hq(A4_0), 0.1);
          if ((eta1 >= A4_1) || rtIsNaN(A4_1)) {
            A4_1 = eta1;
          }

          if ((d6 <= A4_1) || rtIsNaN(A4_1)) {
            A4_1 = d6;
          }

          A4_1 = ceil(Fullexp_log2(A4_1 / 5.3719203511481517));
          if (A4_1 >= 0.0) {
            exptj = A4_1;
          }

          d6 = rt_powd_snf(2.0, exptj);
          for (e_j = 0; e_j < 81; e_j++) {
            eta1 = A[e_j] / d6;
            T[e_j] = eta1;
            A4_0[e_j] = 0.05031554467093536 * fabs(eta1);
          }

          Fullexp_mpower(A4_0, 27.0, tmp);
          A4_1 = ceil(Fullexp_log2(Fullexp_norm_hq(tmp) / Fullexp_norm_hq(T) *
            2.0 / 2.2204460492503131E-16) / 26.0);
          if (!(A4_1 >= 0.0)) {
            A4_1 = 0.0;
          }

          exptj += A4_1;
          if (rtIsInf(exptj)) {
            d6 = Fullexp_norm_hq(A) / 5.3719203511481517;
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

        Fullexp_padeApproximation(A, A2, A4, A6, b_s, F);
        if (recomputeDiags) {
          Fullexp_recomputeBlockDiag(A, F, blockFormat);
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

            Fullexp_recomputeBlockDiag(A, F, blockFormat);
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static real_T Fullexp_mod(real_T x)
{
  real_T r;
  if (rtIsNaN(x)) {
    r = (rtNaN);
  } else if (rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    boolean_T rEQ0;
    r = fmod(x, 6.2831853071795862);
    rEQ0 = (r == 0.0);
    if (!rEQ0) {
      real_T q;
      q = fabs(x / 6.2831853071795862);
      rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
    }

    if (rEQ0) {
      r = 0.0;
    } else if (r < 0.0) {
      r += 6.2831853071795862;
    }
  }

  return r;
}

// Function for MATLAB Function: '<S23>/MATLAB Function1'
void Fullexp_smallQuat(const real_T q[4], real_T p[4])
{
  real_T axis[3];
  real_T a_idx_0;
  real_T a_idx_1;
  real_T angle;
  real_T den;
  real_T p_tmp;
  real_T tmp;
  boolean_T tf;
  angle = 2.0 * acos(q[0]);
  den = sin(angle / 2.0);
  a_idx_0 = q[1] / den;
  a_idx_1 = q[2] / den;
  den = q[3] / den;
  tf = rtIsNaN(a_idx_0);
  if (!tf) {
    tf = rtIsNaN(a_idx_1);
  }

  if (!tf) {
    tf = rtIsNaN(den);
  }

  if (!tf) {
    tf = rtIsNaN(angle);
  }

  if (tf) {
    p[0] = 1.0;
    p[1] = 0.0;
    p[2] = 0.0;
    p[3] = 0.0;
  } else {
    angle = Fullexp_mod(angle + 3.1415926535897931) - 3.1415926535897931;
    axis[0] = a_idx_0;
    axis[1] = a_idx_1;
    axis[2] = den;
    tmp = Fullexp_norm(axis);
    p_tmp = sin(angle / 2.0);
    p[0] = cos(angle / 2.0);
    p[1] = a_idx_0 / tmp * p_tmp;
    p[2] = a_idx_1 / tmp * p_tmp;
    p[3] = den / tmp * p_tmp;
  }
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

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static real_T Fullexp_rand_m(void)
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
      mti = Fullexp_DW.state_a[624] + 1U;
      if (Fullexp_DW.state_a[624] + 1U >= 625U) {
        for (int32_T kk = 0; kk < 227; kk++) {
          mti = (Fullexp_DW.state_a[kk + 1] & 2147483647U) |
            (Fullexp_DW.state_a[kk] & 2147483648U);
          if ((mti & 1U) == 0U) {
            mti >>= 1U;
          } else {
            mti = mti >> 1U ^ 2567483615U;
          }

          Fullexp_DW.state_a[kk] = Fullexp_DW.state_a[kk + 397] ^ mti;
        }

        for (int32_T kk = 0; kk < 396; kk++) {
          mti = (Fullexp_DW.state_a[kk + 227] & 2147483648U) |
            (Fullexp_DW.state_a[kk + 228] & 2147483647U);
          if ((mti & 1U) == 0U) {
            mti >>= 1U;
          } else {
            mti = mti >> 1U ^ 2567483615U;
          }

          Fullexp_DW.state_a[kk + 227] = Fullexp_DW.state_a[kk] ^ mti;
        }

        mti = (Fullexp_DW.state_a[623] & 2147483648U) | (Fullexp_DW.state_a[0] &
          2147483647U);
        if ((mti & 1U) == 0U) {
          mti >>= 1U;
        } else {
          mti = mti >> 1U ^ 2567483615U;
        }

        Fullexp_DW.state_a[623] = Fullexp_DW.state_a[396] ^ mti;
        mti = 1U;
      }

      y = Fullexp_DW.state_a[static_cast<int32_T>(mti) - 1];
      Fullexp_DW.state_a[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      b_u[k] = y >> 18U ^ y;
    }

    mti = b_u[0] >> 5U;
    y = b_u[1] >> 6U;
    if ((mti == 0U) && (y == 0U)) {
      boolean_T b_isvalid;
      b_isvalid = ((Fullexp_DW.state_a[624] >= 1U) && (Fullexp_DW.state_a[624] <
        625U));
      if (b_isvalid) {
        boolean_T exitg2;
        b_isvalid = false;
        k = 1;
        exitg2 = false;
        while ((!exitg2) && (k < 625)) {
          if (Fullexp_DW.state_a[k - 1] == 0U) {
            k++;
          } else {
            b_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!b_isvalid) {
        Fullexp_DW.state_a[0] = 5489U;
        Fullexp_DW.state_a[624] = 624U;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return (static_cast<real_T>(mti) * 6.7108864E+7 + static_cast<real_T>(y)) *
    1.1102230246251565E-16;
}

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static void Fullexp_timeKeeper_hm(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_o,
  real_T *outTime_tv_sec, real_T *outTime_tv_nsec)
{
  coderTimespec origTimespec;
  if (!Fullexp_DW.savedTime_not_empty_g) {
    if (!Fullexp_DW.freq_not_empty_a) {
      Fullexp_DW.freq_not_empty_a = true;
      coderInitTimeFunctions(&Fullexp_DW.freq_i);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq_i);
    savedTime_o->tv_sec = origTimespec.tv_sec;
    savedTime_o->tv_nsec = origTimespec.tv_nsec;
  }

  *outTime_tv_sec = savedTime_o->tv_sec;
  *outTime_tv_nsec = savedTime_o->tv_nsec;
}

// Function for MATLAB Function: '<S16>/MATLAB Function1'
static real_T Fullexp_toc_i(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_o)
{
  coderTimespec origTimespec;
  real_T t;
  real_T tstart_tv_nsec;
  real_T tstart_tv_sec;
  Fullexp_timeKeeper_hm(savedTime_o, &tstart_tv_sec, &tstart_tv_nsec);
  if (!Fullexp_DW.freq_not_empty_a) {
    Fullexp_DW.freq_not_empty_a = true;
    coderInitTimeFunctions(&Fullexp_DW.freq_i);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq_i);
  t = (origTimespec.tv_nsec - tstart_tv_nsec) / 1.0E+9 + (origTimespec.tv_sec -
    tstart_tv_sec);
  return t;
}

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static void Fullexp_timeKeeper_hc(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_a)
{
  coderTimespec origTimespec;
  if (!Fullexp_DW.savedTime_not_empty_ki) {
    if (!Fullexp_DW.freq_not_empty_l) {
      Fullexp_DW.freq_not_empty_l = true;
      coderInitTimeFunctions(&Fullexp_DW.freq_e);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq_e);
    Fullexp_DW.savedTime_not_empty_ki = true;
  }

  savedTime_a->tv_sec = newTime_tv_sec;
  savedTime_a->tv_nsec = newTime_tv_nsec;
}

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static void Fullexp_tic_p(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_a)
{
  coderTimespec origTimespec;
  if (!Fullexp_DW.freq_not_empty_l) {
    Fullexp_DW.freq_not_empty_l = true;
    coderInitTimeFunctions(&Fullexp_DW.freq_e);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq_e);
  Fullexp_timeKeeper_hc(origTimespec.tv_sec, origTimespec.tv_nsec, savedTime_a);
}

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static real_T Fullexp_norm_l(const real_T x[9])
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

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static void Fullexp_mpower_g(const real_T a[9], real_T b, real_T c[9])
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

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static void Fullexp_padeApproximation_n(const real_T A[9], const real_T A2[9],
  const real_T A4[9], const real_T A6[9], int32_T m, real_T F[9])
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

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static void Fullexp_recomputeBlockDiag_i(const real_T A[9], real_T F[9], const
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

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static void Fullexp_xzsyhetrd_d(real_T A[9], real_T D[3], real_T E[2], real_T
  tau[2])
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

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static void Fullexp_xzlascl_c(real_T cfrom, real_T cto, int32_T m, real_T A[3],
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

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static void Fullexp_xzlascl_cm(real_T cfrom, real_T cto, int32_T m, real_T A[2],
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

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static void Fullexp_rotateRight_oq(int32_T n, real_T z[9], int32_T iz0, const
  real_T cs[4], int32_T ic0, int32_T is0)
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

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static void Fullexp_rotateRight_o(int32_T n, real_T z[9], int32_T iz0, const
  real_T cs[4], int32_T ic0, int32_T is0)
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

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static int32_T Fullexp_xzsteqr_n(real_T d[3], real_T e[2], real_T z[9])
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
            Fullexp_xzlascl_c(tst, 2.2346346549904327E+153, n_tmp, d, l + 1);
            Fullexp_xzlascl_cm(tst, 2.2346346549904327E+153, n_tmp - 1, e, l + 1);
          } else if (tst < 3.02546243347603E-123) {
            iscale = 2;
            Fullexp_xzlascl_c(tst, 3.02546243347603E-123, n_tmp, d, l + 1);
            Fullexp_xzlascl_cm(tst, 3.02546243347603E-123, n_tmp - 1, e, l + 1);
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
                Fullexp_xdlaev2(d[l], e[l], d[l + 1], &d[l], &b_anorm, &work[l],
                                &p);
                d[l + 1] = b_anorm;
                work[l + 2] = p;
                Fullexp_rotateRight_o(2, z, l * 3 + 1, work, l + 1, l + 3);
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
                  Fullexp_xzlartg(b_anorm, s * r, &c, &b_s, &b_r);
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

                Fullexp_rotateRight_o((m - l) + 1, z, l * 3 + 1, work, l + 1, l
                                      + 3);
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
                Fullexp_xdlaev2(d[l - 1], e[l - 1], d[l], &d[l - 1], &b_anorm,
                                &work[m - 1], &p);
                d[l] = b_anorm;
                work[m + 1] = p;
                Fullexp_rotateRight_oq(2, z, (l - 1) * 3 + 1, work, m, m + 2);
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
                  Fullexp_xzlartg(b_anorm, s * r, &c, &b_s, &b_r);
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

                Fullexp_rotateRight_oq((l - m) + 2, z, (m - 1) * 3 + 1, work, m,
                  m + 2);
                d[l] -= p;
                e[l - 1] = b_anorm;
              }
            } while (exitg3 == 0);
          }

          switch (iscale) {
           case 1:
            m = lendsv - lsv;
            Fullexp_xzlascl_c(2.2346346549904327E+153, tst, m + 1, d, lsv);
            Fullexp_xzlascl_cm(2.2346346549904327E+153, tst, m, e, lsv);
            break;

           case 2:
            m = lendsv - lsv;
            Fullexp_xzlascl_c(3.02546243347603E-123, tst, m + 1, d, lsv);
            Fullexp_xzlascl_cm(3.02546243347603E-123, tst, m, e, lsv);
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

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static void Fullexp_xsyheev_m(real_T A[9], int32_T *info, real_T W[3])
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

    Fullexp_xzsyhetrd_d(A, W, e, tau);
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

    *info = Fullexp_xzsteqr_n(W, e, A);
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

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static void Fullexp_expm_h(real_T A[9], real_T F[9])
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
        Fullexp_xsyheev_m(A2, &b_s, w);
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

        d6 = rt_powd_snf(Fullexp_norm_l(A6), 0.16666666666666666);
        eta1 = rt_powd_snf(Fullexp_norm_l(A4), 0.25);
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

          Fullexp_mpower_g(A4_0, 7.0, tmp);
          A4_1 = ceil(Fullexp_log2(Fullexp_norm_l(tmp) / Fullexp_norm_l(A) * 2.0
            / 2.2204460492503131E-16) / 6.0);
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

            Fullexp_mpower_g(A4_0, 11.0, tmp);
            A4_1 = ceil(Fullexp_log2(Fullexp_norm_l(tmp) / Fullexp_norm_l(A) *
              2.0 / 2.2204460492503131E-16) / 10.0);
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
          Fullexp_mpower_g(A4, 2.0, tmp);
          eta1 = rt_powd_snf(Fullexp_norm_l(tmp), 0.125);
          if ((!(d6 >= eta1)) && (!rtIsNaN(eta1))) {
            d6 = eta1;
          }

          if (d6 <= 0.95041789961629319) {
            for (c_k = 0; c_k < 9; c_k++) {
              A4_0[c_k] = 0.090475336558796943 * fabs(A[c_k]);
            }

            Fullexp_mpower_g(A4_0, 15.0, tmp);
            A4_1 = ceil(Fullexp_log2(Fullexp_norm_l(tmp) / Fullexp_norm_l(A) *
              2.0 / 2.2204460492503131E-16) / 14.0);
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

            Fullexp_mpower_g(A4_0, 19.0, tmp);
            A4_1 = ceil(Fullexp_log2(Fullexp_norm_l(tmp) / Fullexp_norm_l(A) *
              2.0 / 2.2204460492503131E-16) / 18.0);
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

          A4_1 = rt_powd_snf(Fullexp_norm_l(A4_0), 0.1);
          if ((eta1 >= A4_1) || rtIsNaN(A4_1)) {
            A4_1 = eta1;
          }

          if ((d6 <= A4_1) || rtIsNaN(A4_1)) {
            A4_1 = d6;
          }

          A4_1 = ceil(Fullexp_log2(A4_1 / 5.3719203511481517));
          if (A4_1 >= 0.0) {
            exptj = A4_1;
          }

          d6 = rt_powd_snf(2.0, exptj);
          for (c_k = 0; c_k < 9; c_k++) {
            eta1 = A[c_k] / d6;
            T[c_k] = eta1;
            A4_0[c_k] = 0.05031554467093536 * fabs(eta1);
          }

          Fullexp_mpower_g(A4_0, 27.0, tmp);
          A4_1 = ceil(Fullexp_log2(Fullexp_norm_l(tmp) / Fullexp_norm_l(T) * 2.0
            / 2.2204460492503131E-16) / 26.0);
          if (!(A4_1 >= 0.0)) {
            A4_1 = 0.0;
          }

          exptj += A4_1;
          if (rtIsInf(exptj)) {
            d6 = Fullexp_norm_l(A) / 5.3719203511481517;
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

        Fullexp_padeApproximation_n(A, A2, A4, A6, b_s, F);
        if (recomputeDiags) {
          Fullexp_recomputeBlockDiag_i(A, F, blockFormat);
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

            Fullexp_recomputeBlockDiag_i(A, F, blockFormat);
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static real_T Fullexp_rand_a(void)
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
      mti = Fullexp_DW.state_p[624] + 1U;
      if (Fullexp_DW.state_p[624] + 1U >= 625U) {
        for (int32_T kk = 0; kk < 227; kk++) {
          mti = (Fullexp_DW.state_p[kk + 1] & 2147483647U) |
            (Fullexp_DW.state_p[kk] & 2147483648U);
          if ((mti & 1U) == 0U) {
            mti >>= 1U;
          } else {
            mti = mti >> 1U ^ 2567483615U;
          }

          Fullexp_DW.state_p[kk] = Fullexp_DW.state_p[kk + 397] ^ mti;
        }

        for (int32_T kk = 0; kk < 396; kk++) {
          mti = (Fullexp_DW.state_p[kk + 227] & 2147483648U) |
            (Fullexp_DW.state_p[kk + 228] & 2147483647U);
          if ((mti & 1U) == 0U) {
            mti >>= 1U;
          } else {
            mti = mti >> 1U ^ 2567483615U;
          }

          Fullexp_DW.state_p[kk + 227] = Fullexp_DW.state_p[kk] ^ mti;
        }

        mti = (Fullexp_DW.state_p[623] & 2147483648U) | (Fullexp_DW.state_p[0] &
          2147483647U);
        if ((mti & 1U) == 0U) {
          mti >>= 1U;
        } else {
          mti = mti >> 1U ^ 2567483615U;
        }

        Fullexp_DW.state_p[623] = Fullexp_DW.state_p[396] ^ mti;
        mti = 1U;
      }

      y = Fullexp_DW.state_p[static_cast<int32_T>(mti) - 1];
      Fullexp_DW.state_p[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      b_u[k] = y >> 18U ^ y;
    }

    mti = b_u[0] >> 5U;
    y = b_u[1] >> 6U;
    if ((mti == 0U) && (y == 0U)) {
      boolean_T b_isvalid;
      b_isvalid = ((Fullexp_DW.state_p[624] >= 1U) && (Fullexp_DW.state_p[624] <
        625U));
      if (b_isvalid) {
        boolean_T exitg2;
        b_isvalid = false;
        k = 1;
        exitg2 = false;
        while ((!exitg2) && (k < 625)) {
          if (Fullexp_DW.state_p[k - 1] == 0U) {
            k++;
          } else {
            b_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!b_isvalid) {
        Fullexp_DW.state_p[0] = 5489U;
        Fullexp_DW.state_p[624] = 624U;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return (static_cast<real_T>(mti) * 6.7108864E+7 + static_cast<real_T>(y)) *
    1.1102230246251565E-16;
}

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static real_T Fullexp_norm_lf(const real_T x[2])
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

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static void Fullexp_timeKeeper_hc0(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_a,
  real_T *outTime_tv_sec, real_T *outTime_tv_nsec)
{
  coderTimespec origTimespec;
  if (!Fullexp_DW.savedTime_not_empty_ki) {
    if (!Fullexp_DW.freq_not_empty_l) {
      Fullexp_DW.freq_not_empty_l = true;
      coderInitTimeFunctions(&Fullexp_DW.freq_e);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq_e);
    savedTime_a->tv_sec = origTimespec.tv_sec;
    savedTime_a->tv_nsec = origTimespec.tv_nsec;
  }

  *outTime_tv_sec = savedTime_a->tv_sec;
  *outTime_tv_nsec = savedTime_a->tv_nsec;
}

// Function for MATLAB Function: '<S17>/MATLAB Function1'
static real_T Fullexp_toc_b(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_a)
{
  coderTimespec origTimespec;
  real_T t;
  real_T tstart_tv_nsec;
  real_T tstart_tv_sec;
  Fullexp_timeKeeper_hc0(savedTime_a, &tstart_tv_sec, &tstart_tv_nsec);
  if (!Fullexp_DW.freq_not_empty_l) {
    Fullexp_DW.freq_not_empty_l = true;
    coderInitTimeFunctions(&Fullexp_DW.freq_e);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq_e);
  t = (origTimespec.tv_nsec - tstart_tv_nsec) / 1.0E+9 + (origTimespec.tv_sec -
    tstart_tv_sec);
  return t;
}

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static void Fullexp_timeKeeper_k(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_o2)
{
  coderTimespec origTimespec;
  if (!Fullexp_DW.savedTime_not_empty_k) {
    if (!Fullexp_DW.freq_not_empty_n) {
      Fullexp_DW.freq_not_empty_n = true;
      coderInitTimeFunctions(&Fullexp_DW.freq_n);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq_n);
    Fullexp_DW.savedTime_not_empty_k = true;
  }

  savedTime_o2->tv_sec = newTime_tv_sec;
  savedTime_o2->tv_nsec = newTime_tv_nsec;
}

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static void Fullexp_tic_b(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_o2)
{
  coderTimespec origTimespec;
  if (!Fullexp_DW.freq_not_empty_n) {
    Fullexp_DW.freq_not_empty_n = true;
    coderInitTimeFunctions(&Fullexp_DW.freq_n);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq_n);
  Fullexp_timeKeeper_k(origTimespec.tv_sec, origTimespec.tv_nsec, savedTime_o2);
}

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static real_T Fullexp_rand_p(void)
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
      mti = Fullexp_DW.state_j[624] + 1U;
      if (Fullexp_DW.state_j[624] + 1U >= 625U) {
        for (int32_T kk = 0; kk < 227; kk++) {
          mti = (Fullexp_DW.state_j[kk + 1] & 2147483647U) |
            (Fullexp_DW.state_j[kk] & 2147483648U);
          if ((mti & 1U) == 0U) {
            mti >>= 1U;
          } else {
            mti = mti >> 1U ^ 2567483615U;
          }

          Fullexp_DW.state_j[kk] = Fullexp_DW.state_j[kk + 397] ^ mti;
        }

        for (int32_T kk = 0; kk < 396; kk++) {
          mti = (Fullexp_DW.state_j[kk + 227] & 2147483648U) |
            (Fullexp_DW.state_j[kk + 228] & 2147483647U);
          if ((mti & 1U) == 0U) {
            mti >>= 1U;
          } else {
            mti = mti >> 1U ^ 2567483615U;
          }

          Fullexp_DW.state_j[kk + 227] = Fullexp_DW.state_j[kk] ^ mti;
        }

        mti = (Fullexp_DW.state_j[623] & 2147483648U) | (Fullexp_DW.state_j[0] &
          2147483647U);
        if ((mti & 1U) == 0U) {
          mti >>= 1U;
        } else {
          mti = mti >> 1U ^ 2567483615U;
        }

        Fullexp_DW.state_j[623] = Fullexp_DW.state_j[396] ^ mti;
        mti = 1U;
      }

      y = Fullexp_DW.state_j[static_cast<int32_T>(mti) - 1];
      Fullexp_DW.state_j[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      b_u[k] = y >> 18U ^ y;
    }

    mti = b_u[0] >> 5U;
    y = b_u[1] >> 6U;
    if ((mti == 0U) && (y == 0U)) {
      boolean_T b_isvalid;
      b_isvalid = ((Fullexp_DW.state_j[624] >= 1U) && (Fullexp_DW.state_j[624] <
        625U));
      if (b_isvalid) {
        boolean_T exitg2;
        b_isvalid = false;
        k = 1;
        exitg2 = false;
        while ((!exitg2) && (k < 625)) {
          if (Fullexp_DW.state_j[k - 1] == 0U) {
            k++;
          } else {
            b_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!b_isvalid) {
        Fullexp_DW.state_j[0] = 5489U;
        Fullexp_DW.state_j[624] = 624U;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return (static_cast<real_T>(mti) * 6.7108864E+7 + static_cast<real_T>(y)) *
    1.1102230246251565E-16;
}

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static void Fullexp_xzgetrf(real_T A[36], int32_T ipiv[6], int32_T *info)
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

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static boolean_T Fullexp_hasFiniteBounds(boolean_T hasLB[6], boolean_T hasUB[6])
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

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static void Fullexp_corrP4DQ_anonFcn1(const real_T P_k[144], const real_T H[72],
  const real_T R[36], const real_T V[36], const real_T x[6], real_T varargout_1
  [36])
{
  real_T Lambda[144];
  real_T Lambda_0[144];
  real_T Lambda_1[144];
  real_T H_0[72];
  real_T varargin_1[36];
  real_T varargin_2[36];
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

  memset(&varargin_1[0], 0, 36U * sizeof(real_T));
  for (j = 0; j < 6; j++) {
    varargin_1[j + 6 * j] = x[j];
  }

  memset(&varargin_2[0], 0, 36U * sizeof(real_T));
  for (j = 0; j < 6; j++) {
    varargin_2[j + 6 * j] = x[j];
  }

  memset(&Lambda[0], 0, 144U * sizeof(real_T));
  for (j = 0; j < 6; j++) {
    for (ipiv_0 = 0; ipiv_0 < 6; ipiv_0++) {
      pipk = 6 * j + ipiv_0;
      Lambda[ipiv_0 + 12 * j] = varargin_1[pipk];
      Lambda[(ipiv_0 + 12 * (j + 6)) + 6] = varargin_2[pipk];
    }
  }

  memset(&varargin_2[0], 0, 36U * sizeof(real_T));
  for (j = 0; j < 12; j++) {
    for (ipiv_0 = 0; ipiv_0 < 12; ipiv_0++) {
      Lambda_2 = 0.0;
      for (pipk = 0; pipk < 12; pipk++) {
        Lambda_2 += Lambda[12 * pipk + j] * P_k[12 * ipiv_0 + pipk];
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
      varargin_1[pipk] = R[pipk] + Lambda_2;
    }
  }

  Fullexp_xzgetrf(varargin_1, ipiv, &j);
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
    varargin_2[pipk + ipiv_0] = 1.0;
    for (jBcol = pipk + 1; jBcol < 7; jBcol++) {
      j = (ipiv_0 + jBcol) - 1;
      if (varargin_2[j] != 0.0) {
        for (i = jBcol + 1; i < 7; i++) {
          kAcol = (ipiv_0 + i) - 1;
          varargin_2[kAcol] -= varargin_1[((jBcol - 1) * 6 + i) - 1] *
            varargin_2[j];
        }
      }
    }
  }

  for (pipk = 0; pipk < 6; pipk++) {
    jBcol = 6 * pipk;
    for (i = 5; i >= 0; i--) {
      kAcol = 6 * i;
      j = i + jBcol;
      Lambda_2 = varargin_2[j];
      if (Lambda_2 != 0.0) {
        varargin_2[j] = Lambda_2 / varargin_1[i + kAcol];
        for (b_i = 0; b_i < i; b_i++) {
          ipiv_0 = b_i + jBcol;
          varargin_2[ipiv_0] -= varargin_1[b_i + kAcol] * varargin_2[j];
        }
      }
    }
  }

  for (j = 0; j < 6; j++) {
    for (ipiv_0 = 0; ipiv_0 < 6; ipiv_0++) {
      Lambda_2 = 0.0;
      for (pipk = 0; pipk < 6; pipk++) {
        Lambda_2 += varargin_2[6 * pipk + j] * V[6 * ipiv_0 + pipk];
      }

      pipk = 6 * ipiv_0 + j;
      varargout_1[pipk] = static_cast<real_T>(Izz[pipk]) - Lambda_2;
    }
  }
}

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static void Fullexp_finDiffEvalAndChkErr(const real_T
  obj_nonlin_workspace_fun_worksp[144], const real_T
  obj_nonlin_workspace_fun_work_0[36], int32_T dim, real_T delta, real_T xk[6],
  boolean_T *evalOK, real_T *fplus, real_T cEqPlus[36])
{
  real_T temp_tmp;
  int32_T idx;
  static const real_T b[72] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const real_T c[36] = { 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9 };

  *fplus = 0.0;
  *evalOK = true;
  temp_tmp = xk[dim - 1];
  xk[dim - 1] = temp_tmp + delta;
  Fullexp_corrP4DQ_anonFcn1(obj_nonlin_workspace_fun_worksp, b, c,
    obj_nonlin_workspace_fun_work_0, xk, cEqPlus);
  idx = 0;
  while ((*evalOK) && (idx + 1 <= 36)) {
    *evalOK = ((!rtIsInf(cEqPlus[idx])) && (!rtIsNaN(cEqPlus[idx])));
    idx++;
  }

  xk[dim - 1] = temp_tmp;
}

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static boolean_T Fullex_computeFiniteDifferences(s_XBLL4znh7jruOucykDXjzD_Full_T
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
    Fullexp_finDiffEvalAndChkErr(obj->nonlin.workspace.fun.workspace.P_k,
      obj->nonlin.workspace.fun.workspace.V, idx + 1, u0, xk, &evalOK, &b,
      obj->cEq_1);
    obj->f_1 = 0.0;
    obj->numEvals++;
    guard1 = false;
    if (!evalOK) {
      if (!modifiedStep) {
        deltaX = -u0;
        if (!obj->hasBounds) {
          Fullexp_finDiffEvalAndChkErr(obj->nonlin.workspace.fun.workspace.P_k,
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

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static real_T Fullexp_computeFirstOrderOpt(const real_T gradf[6], boolean_T
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

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static real_T Fullexp_norm_du(const real_T x[6])
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

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static int32_T Fullexp_checkStoppingCriteria(const real_T gradf[6], real_T
  relFactor, const real_T x[6], int32_T funcCount, real_T
  projSteepestDescentInfNorm, boolean_T hasFiniteBounds)
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

    if (Fullexp_norm_du(tmp) < (Fullexp_norm_du(x) + 1.4901161193847656E-8) *
        1.0E-6) {
      exitflag = 4;
    } else {
      exitflag = -5;
    }
  }

  return exitflag;
}

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static real_T Fullexp_xnrm2_pl(int32_T n, const real_T x[252], int32_T ix0)
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

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static real_T Fullexp_xzlarfg(int32_T n, real_T *alpha1, real_T x[252], int32_T
  ix0)
{
  real_T a;
  real_T tau;
  real_T xnorm;
  int32_T c;
  int32_T d_tmp;
  int32_T knt;
  tau = 0.0;
  xnorm = Fullexp_xnrm2_pl(n - 1, x, ix0);
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

      xnorm = rt_hypotd_snf(*alpha1, Fullexp_xnrm2_pl(n - 1, x, ix0));
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

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static void Fullexp_xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T
  C[252], int32_T ic0, real_T work[6])
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

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static void Fullexp_linearLeastSquares(real_T lhs[252], real_T rhs[42], real_T
  dx[6])
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
    temp = Fullexp_xzlarfg(42 - i, &s, lhs, ii + 2);
    tau[i] = temp;
    lhs[ii] = s;
    if (i + 1 < 6) {
      lhs[ii] = 1.0;
      Fullexp_xzlarf(42 - i, 5 - i, ii + 1, temp, lhs, ii + 43, work);
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
      temp = Fullexp_xnrm2_pl(42 - nfxd, lhs, ((i - 1) * 42 + nfxd) + 1);
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
      temp = Fullexp_xzlarfg(43 - r, &s, lhs, b_ix + 2);
      tau[r - 1] = temp;
      lhs[b_ix] = s;
      if (r < 6) {
        lhs[b_ix] = 1.0;
        Fullexp_xzlarf(43 - r, 6 - r, b_ix + 1, temp, lhs, b_ix + 43, work);
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
            temp = Fullexp_xnrm2_pl(42 - r, lhs, ii + 1);
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

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static int32_T Fullexp_checkStoppingCriteria_a(const real_T gradf[6], real_T
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
  } else if (Fullexp_norm_du(dx) < (Fullexp_norm_du(x) + 1.4901161193847656E-8) *
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

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static void Fullexp_lsqnonlin(const real_T fun_workspace_P_k[144], const real_T
  fun_workspace_V[36], real_T xCurrent[6])
{
  s_XBLL4znh7jruOucykDXjzD_Full_T FiniteDifferences;
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
  static const real_T b[72] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  static const real_T d[36] = { 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9 };

  boolean_T exitg1;
  boolean_T guard1;
  for (i = 0; i < 6; i++) {
    indActive[i] = false;
  }

  funDiff = (rtInf);
  iter = 0;
  hasFiniteBounds = Fullexp_hasFiniteBounds(hasLB, hasUB);
  if (!hasFiniteBounds) {
    for (i = 0; i < 6; i++) {
      xCurrent[i] = 1.0;
    }
  } else {
    for (funcCount = 0; funcCount < 6; funcCount++) {
      xCurrent[funcCount] = 1.0;
    }
  }

  Fullexp_corrP4DQ_anonFcn1(fun_workspace_P_k, b, d, fun_workspace_V, xCurrent,
    f_temp);
  resnorm = 0.0;
  for (i = 0; i < 36; i++) {
    b_gamma = f_temp[i];
    fval[i] = b_gamma;
    resnorm += b_gamma * b_gamma;
  }

  memcpy(&FiniteDifferences.nonlin.workspace.fun.workspace.P_k[0],
         &fun_workspace_P_k[0], 144U * sizeof(real_T));
  memcpy(&FiniteDifferences.nonlin.workspace.fun.workspace.V[0],
         &fun_workspace_V[0], 36U * sizeof(real_T));
  FiniteDifferences.numEvals = 0;
  FiniteDifferences.hasBounds = Fullexp_hasFiniteBounds(FiniteDifferences.hasLB,
    FiniteDifferences.hasUB);
  for (i = 0; i < 6; i++) {
    a__3[i] = 1.0;
  }

  Fullex_computeFiniteDifferences(&FiniteDifferences, fval, a__3, JacCeqTrans);
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

  c = Fullexp_computeFirstOrderOpt(gradf, hasFiniteBounds,
    &projSteepestDescentInfNorm);
  if (!(c >= 1.0)) {
    c = 1.0;
  }

  stepSuccessful = true;
  i = Fullexp_checkStoppingCriteria(gradf, c, xCurrent,
    FiniteDifferences.numEvals + 1, projSteepestDescentInfNorm, hasFiniteBounds);
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

    Fullexp_linearLeastSquares(augJacobian, rhs, dx);
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

    Fullexp_corrP4DQ_anonFcn1(fun_workspace_P_k, b, d, fun_workspace_V, gradf,
      f_temp);
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

      indActive_0 = Fullex_computeFiniteDifferences(&FiniteDifferences, fNew,
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

      i = Fullexp_checkStoppingCriteria_a(gradf, c, funDiff, xCurrent, dx,
        funcCount, stepSuccessful, &iter, projSteepestDescentInfNorm,
        hasFiniteBounds);
      if (i != -5) {
        exitg1 = true;
      }
    }
  }
}

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static void Fullexp_mrdiv_eg(real_T A[72], const real_T B[36])
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
  Fullexp_xzgetrf(b_A, ipiv, &info);
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

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static void Fullexp_timeKeeper_kf(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_o2,
  real_T *outTime_tv_sec, real_T *outTime_tv_nsec)
{
  coderTimespec origTimespec;
  if (!Fullexp_DW.savedTime_not_empty_k) {
    if (!Fullexp_DW.freq_not_empty_n) {
      Fullexp_DW.freq_not_empty_n = true;
      coderInitTimeFunctions(&Fullexp_DW.freq_n);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq_n);
    savedTime_o2->tv_sec = origTimespec.tv_sec;
    savedTime_o2->tv_nsec = origTimespec.tv_nsec;
  }

  *outTime_tv_sec = savedTime_o2->tv_sec;
  *outTime_tv_nsec = savedTime_o2->tv_nsec;
}

// Function for MATLAB Function: '<S22>/MATLAB Function1'
static real_T Fullexp_toc_m(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_o2)
{
  coderTimespec origTimespec;
  real_T t;
  real_T tstart_tv_nsec;
  real_T tstart_tv_sec;
  Fullexp_timeKeeper_kf(savedTime_o2, &tstart_tv_sec, &tstart_tv_nsec);
  if (!Fullexp_DW.freq_not_empty_n) {
    Fullexp_DW.freq_not_empty_n = true;
    coderInitTimeFunctions(&Fullexp_DW.freq_n);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq_n);
  t = (origTimespec.tv_nsec - tstart_tv_nsec) / 1.0E+9 + (origTimespec.tv_sec -
    tstart_tv_sec);
  return t;
}

// Function for MATLAB Function: '<S23>/MATLAB Function1'
static void Fullexp_timeKeeper_ed(real_T newTime_tv_sec, real_T newTime_tv_nsec,
  sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_os)
{
  coderTimespec origTimespec;
  if (!Fullexp_DW.savedTime_not_empty) {
    if (!Fullexp_DW.freq_not_empty) {
      Fullexp_DW.freq_not_empty = true;
      coderInitTimeFunctions(&Fullexp_DW.freq);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq);
    Fullexp_DW.savedTime_not_empty = true;
  }

  savedTime_os->tv_sec = newTime_tv_sec;
  savedTime_os->tv_nsec = newTime_tv_nsec;
}

// Function for MATLAB Function: '<S23>/MATLAB Function1'
static void Fullexp_tic_g(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_os)
{
  coderTimespec origTimespec;
  if (!Fullexp_DW.freq_not_empty) {
    Fullexp_DW.freq_not_empty = true;
    coderInitTimeFunctions(&Fullexp_DW.freq);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq);
  Fullexp_timeKeeper_ed(origTimespec.tv_sec, origTimespec.tv_nsec, savedTime_os);
}

// Function for MATLAB Function: '<S23>/MATLAB Function1'
static real_T Fullexp_rand_k(void)
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
      mti = Fullexp_DW.state[624] + 1U;
      if (Fullexp_DW.state[624] + 1U >= 625U) {
        for (int32_T kk = 0; kk < 227; kk++) {
          mti = (Fullexp_DW.state[kk + 1] & 2147483647U) | (Fullexp_DW.state[kk]
            & 2147483648U);
          if ((mti & 1U) == 0U) {
            mti >>= 1U;
          } else {
            mti = mti >> 1U ^ 2567483615U;
          }

          Fullexp_DW.state[kk] = Fullexp_DW.state[kk + 397] ^ mti;
        }

        for (int32_T kk = 0; kk < 396; kk++) {
          mti = (Fullexp_DW.state[kk + 227] & 2147483648U) |
            (Fullexp_DW.state[kk + 228] & 2147483647U);
          if ((mti & 1U) == 0U) {
            mti >>= 1U;
          } else {
            mti = mti >> 1U ^ 2567483615U;
          }

          Fullexp_DW.state[kk + 227] = Fullexp_DW.state[kk] ^ mti;
        }

        mti = (Fullexp_DW.state[623] & 2147483648U) | (Fullexp_DW.state[0] &
          2147483647U);
        if ((mti & 1U) == 0U) {
          mti >>= 1U;
        } else {
          mti = mti >> 1U ^ 2567483615U;
        }

        Fullexp_DW.state[623] = Fullexp_DW.state[396] ^ mti;
        mti = 1U;
      }

      y = Fullexp_DW.state[static_cast<int32_T>(mti) - 1];
      Fullexp_DW.state[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      b_u[k] = y >> 18U ^ y;
    }

    mti = b_u[0] >> 5U;
    y = b_u[1] >> 6U;
    if ((mti == 0U) && (y == 0U)) {
      boolean_T b_isvalid;
      b_isvalid = ((Fullexp_DW.state[624] >= 1U) && (Fullexp_DW.state[624] <
        625U));
      if (b_isvalid) {
        boolean_T exitg2;
        b_isvalid = false;
        k = 1;
        exitg2 = false;
        while ((!exitg2) && (k < 625)) {
          if (Fullexp_DW.state[k - 1] == 0U) {
            k++;
          } else {
            b_isvalid = true;
            exitg2 = true;
          }
        }
      }

      if (!b_isvalid) {
        Fullexp_DW.state[0] = 5489U;
        Fullexp_DW.state[624] = 624U;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return (static_cast<real_T>(mti) * 6.7108864E+7 + static_cast<real_T>(y)) *
    1.1102230246251565E-16;
}

// Function for MATLAB Function: '<S23>/MATLAB Function1'
static void Fullexp_corrP4Q_anonFcn1(const real_T P_k[144], const real_T H[72],
  const real_T R[36], const real_T V[36], const real_T x[6], real_T varargout_1
  [36])
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
      b_x[pipk] = R[pipk] + Lambda_2;
    }
  }

  Fullexp_xzgetrf(b_x, ipiv, &info);
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

// Function for MATLAB Function: '<S23>/MATLAB Function1'
static void Fullexp_finDiffEvalAndChkErr_n(const real_T
  obj_nonlin_workspace_fun_worksp[144], const real_T
  obj_nonlin_workspace_fun_work_0[72], const real_T
  obj_nonlin_workspace_fun_work_1[36], int32_T dim, real_T delta, real_T xk[6],
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
  Fullexp_corrP4Q_anonFcn1(obj_nonlin_workspace_fun_worksp,
    obj_nonlin_workspace_fun_work_0, b, obj_nonlin_workspace_fun_work_1, xk,
    cEqPlus);
  idx = 0;
  while ((*evalOK) && (idx + 1 <= 36)) {
    *evalOK = ((!rtIsInf(cEqPlus[idx])) && (!rtIsNaN(cEqPlus[idx])));
    idx++;
  }

  xk[dim - 1] = temp_tmp;
}

// Function for MATLAB Function: '<S23>/MATLAB Function1'
static boolean_T Full_computeFiniteDifferences_h(s_B0kB2CQLsoRkj8KoaXWXYC_Full_T
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
    Fullexp_finDiffEvalAndChkErr_n(obj->nonlin.workspace.fun.workspace.P_k,
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
          Fullexp_finDiffEvalAndChkErr_n(obj->nonlin.workspace.fun.workspace.P_k,
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

// Function for MATLAB Function: '<S23>/MATLAB Function1'
static void Fullexp_lsqnonlin_k(const real_T fun_workspace_P_k[144], const
  real_T fun_workspace_H[72], const real_T fun_workspace_V[36], real_T xCurrent
  [6])
{
  s_B0kB2CQLsoRkj8KoaXWXYC_Full_T FiniteDifferences;
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
    0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9 };

  boolean_T exitg1;
  boolean_T guard1;
  for (i = 0; i < 6; i++) {
    indActive[i] = false;
  }

  funDiff = (rtInf);
  iter = 0;
  hasFiniteBounds = Fullexp_hasFiniteBounds(hasLB, hasUB);
  if (!hasFiniteBounds) {
    for (i = 0; i < 6; i++) {
      xCurrent[i] = 1.0;
    }
  } else {
    for (funcCount = 0; funcCount < 6; funcCount++) {
      xCurrent[funcCount] = 1.0;
    }
  }

  Fullexp_corrP4Q_anonFcn1(fun_workspace_P_k, fun_workspace_H, b,
    fun_workspace_V, xCurrent, f_temp);
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
  FiniteDifferences.hasBounds = Fullexp_hasFiniteBounds(FiniteDifferences.hasLB,
    FiniteDifferences.hasUB);
  for (i = 0; i < 6; i++) {
    a__3[i] = 1.0;
  }

  Full_computeFiniteDifferences_h(&FiniteDifferences, fval, a__3, JacCeqTrans);
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

  c = Fullexp_computeFirstOrderOpt(gradf, hasFiniteBounds,
    &projSteepestDescentInfNorm);
  if (!(c >= 1.0)) {
    c = 1.0;
  }

  stepSuccessful = true;
  i = Fullexp_checkStoppingCriteria(gradf, c, xCurrent,
    FiniteDifferences.numEvals + 1, projSteepestDescentInfNorm, hasFiniteBounds);
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

    Fullexp_linearLeastSquares(augJacobian, rhs, dx);
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

    Fullexp_corrP4Q_anonFcn1(fun_workspace_P_k, fun_workspace_H, b,
      fun_workspace_V, gradf, f_temp);
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

      indActive_0 = Full_computeFiniteDifferences_h(&FiniteDifferences, fNew,
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

      i = Fullexp_checkStoppingCriteria_a(gradf, c, funDiff, xCurrent, dx,
        funcCount, stepSuccessful, &iter, projSteepestDescentInfNorm,
        hasFiniteBounds);
      if (i != -5) {
        exitg1 = true;
      }
    }
  }
}

// Function for MATLAB Function: '<S23>/MATLAB Function1'
static void Fullexp_timeKeeper_ed1(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_os,
  real_T *outTime_tv_sec, real_T *outTime_tv_nsec)
{
  coderTimespec origTimespec;
  if (!Fullexp_DW.savedTime_not_empty) {
    if (!Fullexp_DW.freq_not_empty) {
      Fullexp_DW.freq_not_empty = true;
      coderInitTimeFunctions(&Fullexp_DW.freq);
    }

    coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq);
    savedTime_os->tv_sec = origTimespec.tv_sec;
    savedTime_os->tv_nsec = origTimespec.tv_nsec;
  }

  *outTime_tv_sec = savedTime_os->tv_sec;
  *outTime_tv_nsec = savedTime_os->tv_nsec;
}

// Function for MATLAB Function: '<S23>/MATLAB Function1'
static real_T Fullexp_toc_k(sdAmwXbnJnEmimT0NaJRtAD_Fulle_T *savedTime_os)
{
  coderTimespec origTimespec;
  real_T t;
  real_T tstart_tv_nsec;
  real_T tstart_tv_sec;
  Fullexp_timeKeeper_ed1(savedTime_os, &tstart_tv_sec, &tstart_tv_nsec);
  if (!Fullexp_DW.freq_not_empty) {
    Fullexp_DW.freq_not_empty = true;
    coderInitTimeFunctions(&Fullexp_DW.freq);
  }

  coderTimeClockGettimeMonotonic(&origTimespec, Fullexp_DW.freq);
  t = (origTimespec.tv_nsec - tstart_tv_nsec) / 1.0E+9 + (origTimespec.tv_sec -
    tstart_tv_sec);
  return t;
}

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static real_T Fullexp_xnrm2_j(int32_T n, const real_T x[153], int32_T ix0)
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static real_T Fullexp_xzlarfg_a(int32_T n, real_T *alpha1, real_T x[153],
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
    xnorm = Fullexp_xnrm2_j(n - 1, x, ix0);
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

        xnorm = rt_hypotd_snf(*alpha1, Fullexp_xnrm2_j(n - 1, x, ix0));
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_xzlarf_p(int32_T m, int32_T n, int32_T iv0, real_T tau,
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_qrf(real_T A[153], int32_T m, int32_T n, int32_T nfxd,
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
      tau_0 = Fullexp_xzlarfg_a(mmi, &b_atmp, A, ii + 2);
      tau[i] = tau_0;
      A[ii] = b_atmp;
    } else {
      tau_0 = 0.0;
      tau[i] = 0.0;
    }

    if (i + 1 < n) {
      b_atmp = A[ii];
      A[ii] = 1.0;
      Fullexp_xzlarf_p(mmi, (n - i) - 1, ii + 1, tau_0, A, ii + 10, work);
      A[ii] = b_atmp;
    }
  }
}

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_xgeqp3(real_T A[153], int32_T m, int32_T n, int32_T jpvt[17],
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
    Fullexp_qrf(A, m, n, nfxd, tau);
    if (nfxd < minmn_tmp) {
      memset(&work[0], 0, 17U * sizeof(real_T));
      memset(&vn1[0], 0, 17U * sizeof(real_T));
      memset(&vn2[0], 0, 17U * sizeof(real_T));
      for (i = nfxd + 1; i <= n; i++) {
        temp = Fullexp_xnrm2_j(m - nfxd, A, ((i - 1) * 9 + nfxd) + 1);
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
          temp = Fullexp_xzlarfg_a(mmi + 1, &s, A, ix + 2);
          tau[i - 1] = temp;
          A[ix] = s;
        } else {
          temp = 0.0;
          tau[i - 1] = 0.0;
        }

        if (i < n) {
          s = A[ix];
          A[ix] = 1.0;
          Fullexp_xzlarf_p(mmi + 1, iy, ix + 1, temp, A, ix + 10, work);
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
                temp = Fullexp_xnrm2_j(mmi, A, ix + 1);
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_countsort(int32_T x[17], int32_T xLen, int32_T workspace[17],
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_removeConstr(srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *obj, int32_T
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_RemoveDependentIneq_(srnx7tMxlsAQ9dn31gXFrqF_Fulle_T
  *workingset, sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *qrmanager,
  sLLWTJNyuJQrAxk3RwmbzBG_Fulle_T *memspace, real_T tolfactor)
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

      Fullexp_xgeqp3(qrmanager->QR, workingset->nVar, workingset->nActiveConstr,
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

    Fullexp_countsort(memspace->workspace_int, nDepIneq,
                      memspace->workspace_sort, nFixedConstr + 1,
                      workingset->nActiveConstr);
    for (nFixedConstr = nDepIneq; nFixedConstr >= 1; nFixedConstr--) {
      Fullexp_removeConstr(workingset, memspace->workspace_int[nFixedConstr - 1]);
    }
  }
}

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_computeQ_(sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *obj, int32_T
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static int32_T Fullexp_rank(const real_T qrmanager_QR[153], int32_T
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static real_T Fullexp_maxConstraintViolation(const
  srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *obj, const real_T x[153], int32_T ix0)
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static boolean_T Fullexp_feasibleX0ForWorkingSet(real_T workspace[153], real_T
  xCurrent[9], const srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *qrmanager)
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

        Fullexp_xgeqp3(qrmanager->QR, workingset->nActiveConstr,
                       workingset->nVar, qrmanager->jpvt, qrmanager->tau);
      }

      Fullexp_computeQ_(qrmanager, qrmanager->mrows);
      rankQR = Fullexp_rank(qrmanager->QR, qrmanager->mrows, qrmanager->ncols);
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

        Fullexp_xgeqp3(qrmanager->QR, workingset->nVar,
                       workingset->nActiveConstr, qrmanager->jpvt,
                       qrmanager->tau);
      }

      Fullexp_computeQ_(qrmanager, qrmanager->minRowCol);
      rankQR = Fullexp_rank(qrmanager->QR, qrmanager->mrows, qrmanager->ncols);
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

        temp = Fullexp_maxConstraintViolation(workingset, workspace, 1);
        constrViolation_basicX = Fullexp_maxConstraintViolation(workingset,
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static real_T Fullex_maxConstraintViolation_b(const
  srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *obj, const real_T x[9])
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_setProblemType(srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *obj, int32_T
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_xgemv(int32_T m, int32_T n, const real_T A[64], int32_T lda,
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_computeGrad_StoreHx(s87IldPMN2ICa85Nu8z6UL_Fullex_T *obj,
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
    Fullexp_xgemv(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
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
    Fullexp_xgemv(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static real_T Fullexp_computeFval_ReuseHx(const s87IldPMN2ICa85Nu8z6UL_Fullex_T *
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_factorQR(sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *obj, const real_T
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
      Fullexp_qrf(obj->QR, mrows, ncols, i, obj->tau);
    }
  }
}

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_xrotg_j(real_T *a, real_T *b, real_T *c, real_T *s)
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_squareQ_appendCol(sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *obj,
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
    Fullexp_xrotg_j(&obj->QR[c_iy], &temp, &b_c, &s);
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_deleteColMoveEnd(sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *obj,
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
        Fullexp_xrotg_j(&obj->QR[QRk0 - 1], &b_temp, &c_c, &b_s);
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
        Fullexp_xrotg_j(&obj->QR[QRk0 - 1], &b_temp, &c_c, &b_s);
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_fullColLDL2_(smSS6fEwaptVbzYAOdOZgjB_Fulle_T *obj, int32_T
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_xgemv_k(int32_T m, int32_T n, const real_T A[81], int32_T
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_compute_deltax(const real_T H[64],
  sraTyWZlTzdIJhNDrRZT2SF_Fulle_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_Fulle_T
  *memspace, const sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *qrmanager,
  smSS6fEwaptVbzYAOdOZgjB_Fulle_T *cholmanager, const
  s87IldPMN2ICa85Nu8z6UL_Fullex_T *objective)
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

        Fullexp_fullColLDL2_(cholmanager, qrmanager->mrows, temp);
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

        Fullexp_xgemv_k(qrmanager->mrows, mNull_tmp, qrmanager->Q, A_maxDiag_idx
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

        Fullexp_fullColLDL2_(cholmanager, mNull_tmp, temp);
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

          Fullexp_xgemv_k(qrmanager->mrows, mNull_tmp, qrmanager->Q,
                          A_maxDiag_idx + 1, memspace->workspace_float,
                          solution->searchDir);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static real_T Fullexp_xnrm2_jd(int32_T n, const real_T x[9])
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_feasibleratiotest(const real_T solution_xstar[9], const
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
  denomTol = 2.2204460492503131E-13 * Fullexp_xnrm2_jd(workingset_nVar,
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Full_addBoundToActiveSetMatrix_(srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *obj,
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_addAineqConstr(const srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *obj)
{
  int32_T b;
  b = obj->nVar;
  for (int32_T idx = 0; idx < b; idx++) {
    // Check node always fails. would cause program termination and was eliminated 
  }

  // Check node always fails. would cause program termination and was eliminated 
}

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_compute_lambda(real_T workspace[153],
  sraTyWZlTzdIJhNDrRZT2SF_Fulle_T *solution, const
  s87IldPMN2ICa85Nu8z6UL_Fullex_T *objective, const
  sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *qrmanager)
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_phaseone(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_Fulle_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_Fulle_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_Fulle_T
  *cholmanager, const sIOJhD9KwAkF5sEguPjYquC_Fulle_T *runTimeOptions,
  s87IldPMN2ICa85Nu8z6UL_Fullex_T *objective)
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
  Fullexp_setProblemType(workingset, 1);
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
  Fullexp_computeGrad_StoreHx(objective, H, f, solution->xstar);
  solution->fstar = Fullexp_computeFval_ReuseHx(objective,
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
          Fullexp_squareQ_appendCol(qrmanager, workingset->ATwset, 9 *
            (workingset->nActiveConstr - 1) + 1);
          break;

         case -1:
          Fullexp_deleteColMoveEnd(qrmanager, idxStartIneq);
          break;

         default:
          Fullexp_factorQR(qrmanager, workingset->ATwset, i,
                           workingset->nActiveConstr);
          Fullexp_computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        Fullexp_compute_deltax(H, solution, memspace, qrmanager, cholmanager,
          objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          normDelta = Fullexp_xnrm2_jd(i, solution->searchDir);
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
          Fullexp_compute_lambda(memspace->workspace_float, solution, objective,
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
              Fullexp_removeConstr(workingset, idxMinLambda);
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
            Fullexp_removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda[idxStartIneq_tmp - 1] = 0.0;
          }

          updateFval = false;
        } else {
          Fullexp_feasibleratiotest(solution->xstar, solution->searchDir,
            workingset->nVar, workingset->lb, workingset->indexLB,
            workingset->indexUB, workingset->sizes, workingset->isActiveIdx,
            workingset->isActiveConstr, workingset->nWConstr, true, &normDelta,
            &updateFval, &idxStartIneq_tmp, &idxMinLambda);
          if (updateFval) {
            switch (idxStartIneq_tmp) {
             case 3:
              Fullexp_addAineqConstr(workingset);
              break;

             case 4:
              Full_addBoundToActiveSetMatrix_(workingset, 4, idxMinLambda);
              break;

             default:
              Full_addBoundToActiveSetMatrix_(workingset, 5, idxMinLambda);
              break;
            }

            idxEndIneq = 1;
          } else {
            if (objective->objtype == 5) {
              if (Fullexp_xnrm2_jd(objective->nvar, solution->searchDir) > 100.0
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

          Fullexp_computeGrad_StoreHx(objective, H, f, solution->xstar);
          updateFval = true;
        }

        solution->iterations++;
        if (solution->iterations >= 5) {
          solution->state = 0;
        }

        if (solution->iterations - solution->iterations / 50 * 50 == 0) {
          solution->maxConstr = Fullex_maxConstraintViolation_b(workingset,
            solution->xstar);
          if (solution->maxConstr - solution->xstar[8] > 1.0E-8) {
            memcpy(&solution->searchDir[0], &solution->xstar[0], 9U * sizeof
                   (real_T));
            nonDegenerateWset = Fullexp_feasibleX0ForWorkingSet
              (memspace->workspace_float, solution->searchDir, workingset,
               qrmanager);
            if ((!nonDegenerateWset) && (solution->state != 0)) {
              solution->state = -2;
            }

            idxEndIneq = 0;
            normDelta = Fullex_maxConstraintViolation_b(workingset,
              solution->searchDir);
            if (normDelta < solution->maxConstr) {
              memcpy(&solution->xstar[0], &solution->searchDir[0], 9U * sizeof
                     (real_T));
            }
          }
        }

        if (updateFval) {
          solution->fstar = Fullexp_computeFval_ReuseHx(objective,
            memspace->workspace_float, f, solution->xstar);
          if ((solution->fstar < 1.0E-8) && (solution->state != 0)) {
            solution->state = 2;
          }
        }
      }
    } else {
      if (!updateFval) {
        solution->fstar = Fullexp_computeFval_ReuseHx(objective,
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
        Fullexp_removeConstr(workingset, i);
        exitg2 = true;
      } else {
        i++;
      }
    }
  }

  for (i = workingset->nActiveConstr; i > 8; i--) {
    Fullexp_removeConstr(workingset, i);
  }

  solution->maxConstr = solution->xstar[8];
  Fullexp_setProblemType(workingset, 3);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
}

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static int32_T Fullexp_RemoveDependentEq_(sLLWTJNyuJQrAxk3RwmbzBG_Fulle_T
  *memspace, const srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *qrmanager)
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

      Fullexp_xgeqp3(qrmanager->QR, mTotalWorkingEq_tmp, workingset->nVar,
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
      Fullexp_computeQ_(qrmanager, qrmanager->mrows);
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
        Fullexp_xgeqp3(qrmanager->QR, workingset->nVar, mTotalWorkingEq_tmp,
                       qrmanager->jpvt, qrmanager->tau);
      }

      for (mWorkingFixed = 0; mWorkingFixed < nDepInd; mWorkingFixed++) {
        memspace->workspace_int[mWorkingFixed] = qrmanager->jpvt
          [(mTotalWorkingEq_tmp - nDepInd) + mWorkingFixed];
      }

      Fullexp_countsort(memspace->workspace_int, nDepInd,
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_ratiotest(const real_T solution_xstar[9], const real_T
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
  denomTol = 2.2204460492503131E-13 * Fullexp_xnrm2_jd(workingset_nVar,
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_iterate(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_Fulle_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_Fulle_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_Fulle_T
  *cholmanager, s87IldPMN2ICa85Nu8z6UL_Fullex_T *objective, boolean_T
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
  Fullexp_computeGrad_StoreHx(objective, H, f, solution->xstar);
  solution->fstar = Fullexp_computeFval_ReuseHx(objective,
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
          Fullexp_squareQ_appendCol(qrmanager, workingset->ATwset, 9 *
            (workingset->nActiveConstr - 1) + 1);
          break;

         case -1:
          Fullexp_deleteColMoveEnd(qrmanager, globalActiveConstrIdx);
          break;

         default:
          Fullexp_factorQR(qrmanager, workingset->ATwset, nVar,
                           workingset->nActiveConstr);
          Fullexp_computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        Fullexp_compute_deltax(H, solution, memspace, qrmanager, cholmanager,
          objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          normDelta = Fullexp_xnrm2_jd(nVar, solution->searchDir);
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
          Fullexp_compute_lambda(memspace->workspace_float, solution, objective,
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
              Fullexp_removeConstr(workingset, localActiveConstrIdx);
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
            Fullexp_removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda[localActiveConstrIdx - 1] = 0.0;
          }

          updateFval = false;
        } else {
          updateFval = (TYPE == 5);
          if (updateFval || runTimeOptions_RemainFeasible) {
            Fullexp_feasibleratiotest(solution->xstar, solution->searchDir,
              workingset->nVar, workingset->lb, workingset->indexLB,
              workingset->indexUB, workingset->sizes, workingset->isActiveIdx,
              workingset->isActiveConstr, workingset->nWConstr, updateFval,
              &normDelta, &newBlocking, &activeConstrChangedType,
              &localActiveConstrIdx);
          } else {
            Fullexp_ratiotest(solution->xstar, solution->searchDir,
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
              Fullexp_addAineqConstr(workingset);
              break;

             case 4:
              Full_addBoundToActiveSetMatrix_(workingset, 4,
                localActiveConstrIdx);
              break;

             default:
              Full_addBoundToActiveSetMatrix_(workingset, 5,
                localActiveConstrIdx);
              break;
            }

            activeSetChangeID = 1;
          } else {
            if (objective->objtype == 5) {
              if (Fullexp_xnrm2_jd(objective->nvar, solution->searchDir) > 100.0
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

          Fullexp_computeGrad_StoreHx(objective, H, f, solution->xstar);
          updateFval = true;
        }

        solution->iterations++;
        activeConstrChangedType = objective->nvar;
        if ((solution->iterations >= 5) && ((solution->state != 1) ||
             (objective->objtype == 5))) {
          solution->state = 0;
        }

        if (solution->iterations - solution->iterations / 50 * 50 == 0) {
          solution->maxConstr = Fullex_maxConstraintViolation_b(workingset,
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

            newBlocking = Fullexp_feasibleX0ForWorkingSet
              (memspace->workspace_float, solution->searchDir, workingset,
               qrmanager);
            if ((!newBlocking) && (solution->state != 0)) {
              solution->state = -2;
            }

            activeSetChangeID = 0;
            normDelta = Fullex_maxConstraintViolation_b(workingset,
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
          solution->fstar = Fullexp_computeFval_ReuseHx(objective,
            memspace->workspace_float, f, solution->xstar);
          if ((solution->fstar < -1.0E+20) && ((solution->state != 0) ||
               (objective->objtype != 5))) {
            solution->state = 2;
          }
        }
      }
    } else {
      if (!updateFval) {
        solution->fstar = Fullexp_computeFval_ReuseHx(objective,
          memspace->workspace_float, f, solution->xstar);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_computeFirstOrderOpt_m(sraTyWZlTzdIJhNDrRZT2SF_Fulle_T
  *solution, const s87IldPMN2ICa85Nu8z6UL_Fullex_T *objective, int32_T
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_phaseone_o(const real_T H[64], const real_T f[8],
  sraTyWZlTzdIJhNDrRZT2SF_Fulle_T *solution, sLLWTJNyuJQrAxk3RwmbzBG_Fulle_T
  *memspace, srnx7tMxlsAQ9dn31gXFrqF_Fulle_T *workingset,
  sTj3C1mXm6Z2qP847mPxR8C_Fulle_T *qrmanager, smSS6fEwaptVbzYAOdOZgjB_Fulle_T
  *cholmanager, s87IldPMN2ICa85Nu8z6UL_Fullex_T *objective, const
  sIOJhD9KwAkF5sEguPjYquC_Fulle_T *runTimeOptions)
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

  Fullexp_setProblemType(workingset, b_nVar);
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
  Fullexp_computeGrad_StoreHx(objective, H, f, solution->xstar);
  solution->fstar = Fullexp_computeFval_ReuseHx(objective,
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
          Fullexp_squareQ_appendCol(qrmanager, workingset->ATwset, 9 *
            (workingset->nActiveConstr - 1) + 1);
          break;

         case -1:
          Fullexp_deleteColMoveEnd(qrmanager, idxStartIneq);
          break;

         default:
          Fullexp_factorQR(qrmanager, workingset->ATwset, idxStartIneq_tmp,
                           workingset->nActiveConstr);
          Fullexp_computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        Fullexp_compute_deltax(H, solution, memspace, qrmanager, cholmanager,
          objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          normDelta = Fullexp_xnrm2_jd(idxStartIneq_tmp, solution->searchDir);
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
          Fullexp_compute_lambda(memspace->workspace_float, solution, objective,
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
              Fullexp_removeConstr(workingset, idxMinLambda);
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
            Fullexp_removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda[b_nVar - 1] = 0.0;
          }

          updateFval = false;
        } else {
          Fullexp_feasibleratiotest(solution->xstar, solution->searchDir,
            workingset->nVar, workingset->lb, workingset->indexLB,
            workingset->indexUB, workingset->sizes, workingset->isActiveIdx,
            workingset->isActiveConstr, workingset->nWConstr, true, &normDelta,
            &updateFval, &b_nVar, &idxMinLambda);
          if (updateFval) {
            switch (b_nVar) {
             case 3:
              Fullexp_addAineqConstr(workingset);
              break;

             case 4:
              Full_addBoundToActiveSetMatrix_(workingset, 4, idxMinLambda);
              break;

             default:
              Full_addBoundToActiveSetMatrix_(workingset, 5, idxMinLambda);
              break;
            }

            idxEndIneq = 1;
          } else {
            if (objective->objtype == 5) {
              if (Fullexp_xnrm2_jd(objective->nvar, solution->searchDir) > 100.0
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

          Fullexp_computeGrad_StoreHx(objective, H, f, solution->xstar);
          updateFval = true;
        }

        solution->iterations++;
        idxMinLambda = objective->nvar;
        if ((solution->iterations >= 5) && ((solution->state != 1) ||
             (objective->objtype == 5))) {
          solution->state = 0;
        }

        if (solution->iterations - solution->iterations / 50 * 50 == 0) {
          solution->maxConstr = Fullex_maxConstraintViolation_b(workingset,
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

            nonDegenerateWset = Fullexp_feasibleX0ForWorkingSet
              (memspace->workspace_float, solution->searchDir, workingset,
               qrmanager);
            if ((!nonDegenerateWset) && (solution->state != 0)) {
              solution->state = -2;
            }

            idxEndIneq = 0;
            normDelta = Fullex_maxConstraintViolation_b(workingset,
              solution->searchDir);
            if ((normDelta < solution->maxConstr) && (objective->nvar - 1 >= 0))
            {
              memcpy(&solution->xstar[0], &solution->searchDir[0],
                     static_cast<uint32_T>(objective->nvar) * sizeof(real_T));
            }
          }
        }

        if (updateFval) {
          solution->fstar = Fullexp_computeFval_ReuseHx(objective,
            memspace->workspace_float, f, solution->xstar);
          if ((solution->fstar < 1.0E-8) && ((solution->state != 0) ||
               (objective->objtype != 5))) {
            solution->state = 2;
          }
        }
      }
    } else {
      if (!updateFval) {
        solution->fstar = Fullexp_computeFval_ReuseHx(objective,
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
        Fullexp_removeConstr(workingset, b_nVar);
        exitg2 = true;
      } else {
        b_nVar++;
      }
    }
  }

  b_nVar = workingset->nActiveConstr;
  while ((b_nVar > 0) && (b_nVar > nVar_tmp)) {
    Fullexp_removeConstr(workingset, b_nVar);
    b_nVar--;
  }

  solution->maxConstr = solution->xstar[8];
  Fullexp_setProblemType(workingset, PROBTYPE_ORIG);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
}

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_linearForm_(boolean_T obj_hasLinear, int32_T obj_nvar,
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static real_T Fullexp_computeFval(const s87IldPMN2ICa85Nu8z6UL_Fullex_T *obj,
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
    Fullexp_linearForm_(obj->hasLinear, obj->nvar, workspace, H, f, x);
    val = 0.0;
    if (obj->nvar >= 1) {
      ixlast = obj->nvar;
      for (idx = 0; idx < ixlast; idx++) {
        val += x[idx] * workspace[idx];
      }
    }
    break;

   default:
    Fullexp_linearForm_(obj->hasLinear, obj->nvar, workspace, H, f, x);
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static void Fullexp_quadprog(const real_T H[64], const real_T f[8], const real_T
  x0[8], real_T x[8], real_T *fval, real_T *exitflag)
{
  s87IldPMN2ICa85Nu8z6UL_Fullex_T objective;
  sIOJhD9KwAkF5sEguPjYquC_Fulle_T runTimeOptions;
  sLLWTJNyuJQrAxk3RwmbzBG_Fulle_T memspace;
  sTj3C1mXm6Z2qP847mPxR8C_Fulle_T qrmanager;
  sraTyWZlTzdIJhNDrRZT2SF_Fulle_T solution;
  srnx7tMxlsAQ9dn31gXFrqF_Fulle_T workingset;
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
  Fullexp_B.obj.ndims = 0;
  Fullexp_B.obj.info = 0;
  Fullexp_B.obj.ConvexCheck = true;
  Fullexp_B.obj.regTol_ = 0.0;
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

  Fullexp_B.obj.scaleFactor = H_infnrm;
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
  Fullexp_RemoveDependentIneq_(&workingset, &qrmanager, &memspace, 1.0);
  okWorkingSet = Fullexp_feasibleX0ForWorkingSet(memspace.workspace_float,
    solution.xstar, &workingset, &qrmanager);
  if (!okWorkingSet) {
    Fullexp_RemoveDependentIneq_(&workingset, &qrmanager, &memspace, 10.0);
    okWorkingSet = Fullexp_feasibleX0ForWorkingSet(memspace.workspace_float,
      solution.xstar, &workingset, &qrmanager);
    if (!okWorkingSet) {
      solution.state = -7;
    }
  }

  if (solution.state >= 0) {
    solution.iterations = 0;
    solution.maxConstr = Fullex_maxConstraintViolation_b(&workingset,
      solution.xstar);
    guard1 = false;
    if (solution.maxConstr > 1.0E-8) {
      Fullexp_phaseone(H, f, &solution, &memspace, &workingset, &qrmanager,
                       &Fullexp_B.obj, &runTimeOptions, &objective);
      if (solution.state == 0) {
      } else {
        solution.maxConstr = Fullex_maxConstraintViolation_b(&workingset,
          solution.xstar);
        if (solution.maxConstr > 1.0E-8) {
          solution.fstar = Fullexp_computeFval(&objective,
            memspace.workspace_float, H, f, solution.xstar);
          solution.state = -2;
        } else {
          if (solution.maxConstr > 0.0) {
            memcpy(&solution.searchDir[0], &solution.xstar[0], sizeof(real_T) <<
                   3U);
            solution.state = 82;
            i = Fullexp_RemoveDependentEq_(&memspace, &workingset, &qrmanager);
            if ((i != -1) && (workingset.nActiveConstr <= 9)) {
              Fullexp_RemoveDependentIneq_(&workingset, &qrmanager, &memspace,
                1.0);
              okWorkingSet = Fullexp_feasibleX0ForWorkingSet
                (memspace.workspace_float, solution.xstar, &workingset,
                 &qrmanager);
              guard2 = false;
              if (!okWorkingSet) {
                Fullexp_RemoveDependentIneq_(&workingset, &qrmanager, &memspace,
                  10.0);
                okWorkingSet = Fullexp_feasibleX0ForWorkingSet
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
                  f_infnrm = Fullex_maxConstraintViolation_b(&workingset,
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

            f_infnrm = Fullex_maxConstraintViolation_b(&workingset,
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
      Fullexp_iterate(H, f, &solution, &memspace, &workingset, &qrmanager,
                      &Fullexp_B.obj, &objective, true, H_infnrm);
      if (solution.state != -6) {
        solution.maxConstr = Fullex_maxConstraintViolation_b(&workingset,
          solution.xstar);
        Fullexp_computeFirstOrderOpt_m(&solution, &objective, workingset.nVar,
          workingset.ATwset, workingset.nActiveConstr, memspace.workspace_float);
        runTimeOptions.RemainFeasible = false;
        while ((solution.iterations < 5) && ((solution.state == -7) ||
                ((solution.state == 1) && ((solution.maxConstr > 1.0E-8) ||
                  (solution.firstorderopt > 1.0E-8 * H_infnrm))))) {
          Fullexp_feasibleX0ForWorkingSet(memspace.workspace_float,
            solution.xstar, &workingset, &qrmanager);
          solution.state = 82;
          i = Fullexp_RemoveDependentEq_(&memspace, &workingset, &qrmanager);
          if ((i != -1) && (workingset.nActiveConstr <= 9)) {
            Fullexp_RemoveDependentIneq_(&workingset, &qrmanager, &memspace, 1.0);
            okWorkingSet = Fullexp_feasibleX0ForWorkingSet
              (memspace.workspace_float, solution.xstar, &workingset, &qrmanager);
            guard2 = false;
            if (!okWorkingSet) {
              Fullexp_RemoveDependentIneq_(&workingset, &qrmanager, &memspace,
                10.0);
              okWorkingSet = Fullexp_feasibleX0ForWorkingSet
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
                f_infnrm = Fullex_maxConstraintViolation_b(&workingset,
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

          Fullexp_phaseone_o(H, f, &solution, &memspace, &workingset, &qrmanager,
                             &Fullexp_B.obj, &objective, &runTimeOptions);
          Fullexp_iterate(H, f, &solution, &memspace, &workingset, &qrmanager,
                          &Fullexp_B.obj, &objective, false, H_infnrm);
          solution.maxConstr = Fullex_maxConstraintViolation_b(&workingset,
            solution.xstar);
          Fullexp_computeFirstOrderOpt_m(&solution, &objective, workingset.nVar,
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
    *fval = Fullexp_computeFval(&objective, memspace.workspace_float, H, f,
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

// Function for MATLAB Function: '<S236>/MATLAB Function5'
static real_T Fullexp_maximum_i(const real_T x[8])
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

static void Fullexp_pause(real_T varargin_1)
{
  coderTimespec b_timespec;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  if (Fullexp_DW.pauseState == 0) {
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

  // End of Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
}

static void F_bmi160_set_EnableSecondaryMag(b_bmi160_Fullexp_T *obj)
{
  b_bmi160_Fullexp_T *obj_0;
  b_bmi160_Fullexp_T *obj_1;
  e_matlabshared_devicedrivers__T *obj_3;
  f_matlabshared_sensors_coder__T *obj_2;
  uint8_T b_data[2];
  uint8_T b_status;
  uint8_T slaveAddress;
  uint8_T val;
  obj_0 = obj;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_2 = obj->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 25U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  Fullexp_pause(0.06);
  obj_1 = obj_0;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 55U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  Fullexp_pause(0.001);
  obj_2 = obj_1->Device;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 154U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  Fullexp_pause(0.001);
  obj_2 = obj_1->Device;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 192U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  Fullexp_pause(0.001);
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 5U;
  b_data[1] = 32U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  obj_2 = obj_0->Device;
  b_status = 75U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 75U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 1U) | 32);
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  Fullexp_pause(0.001);
  obj_2 = obj_0->Device;
  b_status = 76U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 76U;
  b_data[1] = 131U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  Fullexp_pause(0.001);
  obj_2 = obj_0->Device;
  b_status = 107U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 107U;
  b_data[1] = 32U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  Fullexp_pause(0.001);
  obj_2 = obj_0->Device;
  b_status = 79U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  b_status = 78U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
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
  Fullexp_pause(0.001);
  obj_1 = obj_0;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 77U;
  b_data[1] = 64U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  Fullexp_pause(0.001);
  obj_2 = obj_1->Device;
  b_status = 4U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  obj_1 = obj_0;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  b_status = 79U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  b_status = 78U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
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
  Fullexp_pause(0.001);
  obj_2 = obj_1->Device;
  b_status = 79U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  obj_2 = obj_1->Device;
  b_status = 78U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  obj_2 = obj_1->Device;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 79U;
  b_data[1] = 14U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  obj_2 = obj_1->Device;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 78U;
  b_data[1] = 82U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
  Fullexp_pause(0.001);
  obj_2 = obj_0->Device;
  b_status = 79U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  b_status = 78U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
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

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_status,
    1U, true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_3->MW_I2C_HANDLE, slaveAddress, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_2 = obj_0->Device;
  obj_3 = obj_2->Device.InterfaceObj;
  slaveAddress = obj_2->Device.DeviceAddress;
  b_data[0] = 77U;
  b_data[1] = 66U;
  MW_I2C_MasterWrite(obj_3->MW_I2C_HANDLE, slaveAddress, &b_data[0], 2U, false,
                     false);
}

static void Fullexp_SystemCore_setup(nvidiacoder_sensors_BMI160Blo_T *obj)
{
  b_bmi160_Fullexp_T *b_obj;
  b_bmi160_Fullexp_T *obj_2;
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

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj->isInitialized = 1;
  obj_0 = obj;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
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

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U, false,
                      true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_2 = &obj->_pobj2;
  obj_3 = obj->_pobj2.Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 182U;
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  Fullexp_pause(0.06);
  obj_3 = obj_2->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 3U;
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  Fullexp_pause(0.06);
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 17U;
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  Fullexp_pause(0.005);
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 126U;
  b_data[1] = 21U;
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  Fullexp_pause(0.085);
  F_bmi160_set_EnableSecondaryMag(b_obj);

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  b_status = 65U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 65U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 240U) | 3);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 64U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 64U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 112U) | 8);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 64U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 64U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 15U) | 32);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 67U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 67U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 248U) | 4);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 66U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 66U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 240U) | 8);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 66U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 66U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 207U) | 32);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 68U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 68U;
  b_data[1] = static_cast<uint8_T>(static_cast<int32_T>(val & 240U) | 6);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  obj_3 = b_obj->Device;
  b_status = 76U;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  val = 0U;
  b_status = MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_status, 1U,
    true, false);
  if (b_status == 0) {
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    MW_I2C_MasterRead(obj_4->MW_I2C_HANDLE, i2cModule, &val, 1U, false, true);
  }

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_3 = b_obj->Device;
  obj_4 = obj_3->Device.InterfaceObj;
  i2cModule = obj_3->Device.DeviceAddress;
  b_data[0] = 76U;
  b_data[1] = static_cast<uint8_T>(val & 63);
  MW_I2C_MasterWrite(obj_4->MW_I2C_HANDLE, i2cModule, &b_data[0], 2U, false,
                     false);
  Fullexp_pause(0.001);
  b_obj->matlabCodegenIsDeleted = false;
  obj_1->SensorObject = b_obj;

  // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  obj_0->OutputModules.f1 = &obj_0->_pobj1;
  obj_0->OutputModules.f2 = &obj_0->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

// Model step function
void Fullexp_step(void)
{
  // local block i/o variables
  real_T rtb_ThrustPer_Final[8];
  real_T rtb_ThrustPer_Final_b[8];
  real_T rtb_ThrustPer_Final_d[8];

  {
    e_matlabshared_devicedrivers__T *obj_0;
    f_matlabshared_sensors_coder__T *obj;
    sdAmwXbnJnEmimT0NaJRtAD_Fulle_T savedTime;
    sdAmwXbnJnEmimT0NaJRtAD_Fulle_T savedTime_a;
    sdAmwXbnJnEmimT0NaJRtAD_Fulle_T savedTime_o;
    sdAmwXbnJnEmimT0NaJRtAD_Fulle_T savedTime_o2;
    sdAmwXbnJnEmimT0NaJRtAD_Fulle_T savedTime_os;
    real_T DQMEKFP_tmp[144];
    real_T DQMEKFP_tmp_0[144];
    real_T L[144];
    real_T P_k[144];
    real_T Phi[144];
    real_T Phi_0[144];
    real_T Phi_m[81];
    real_T tmp_3[81];
    real_T H[72];
    real_T H_1[72];
    real_T K[72];
    real_T tmp_4[64];
    real_T y_0[64];
    real_T A[36];
    real_T H_0[36];
    real_T Phi_m_tmp_0[27];
    real_T Phi_m_tmp_1[27];
    real_T rtb_H[24];
    real_T rtb_H_tmp[24];
    real_T tmp[24];
    real_T tmp_0[18];
    real_T T[16];
    real_T dq_corr_dual_0[16];
    real_T DQMEKFx[14];
    real_T STDQMEKFx[14];
    real_T QMEKFx[13];
    real_T STQMEKFx[13];
    real_T x_k[13];
    real_T rtb_x_k[12];
    real_T Phi_m_tmp[9];
    real_T R_chaser[9];
    real_T Rot_error[9];
    real_T T_0[9];
    real_T dt_0[9];
    real_T dt_1[9];
    real_T rtb_R_g[9];
    real_T varargin_4[9];
    real_T Red_dq[8];
    real_T q_minus_inv_0[8];
    real_T q_pred[8];
    real_T rtb_dq_e[8];
    real_T tmp_2[8];
    real_T z_meas[8];
    real_T Chaser_tmp[7];
    real_T z[7];
    real_T z_bar[7];
    real_T Lambda_sol[6];
    real_T tmp_1[6];
    real_T y[6];
    real_T Red_q[4];
    real_T dq_corr_dual[4];
    real_T q_minus_inv[4];
    real_T qr[4];
    real_T qr_0[4];
    real_T rtb_q_f[4];
    real_T ARM_Controls[3];
    real_T BLACK_Path[3];
    real_T RED_Path[3];
    real_T Red_x[3];
    real_T b_vector[3];
    real_T rtb_v[3];
    real_T rtb_v_0[3];
    real_T rtb_w[3];
    real_T rtb_x_b[3];
    real_T vector[3];
    real_T vector_0[3];
    real_T vector_1[3];
    real_T b_y_tmp[2];
    real_T c_y_tmp[2];
    real_T y_tmp[2];
    real_T ARM_Path_idx_1;
    real_T ARM_Path_idx_2;
    real_T BLUE_Path_idx_0;
    real_T BLUE_Path_idx_1;
    real_T BLUE_Path_idx_2;
    real_T H_tmp_0;
    real_T H_tmp_1;
    real_T H_tmp_2;
    real_T H_tmp_3;
    real_T H_tmp_4;
    real_T H_tmp_5;
    real_T H_tmp_6;
    real_T H_tmp_7;
    real_T Red_yaw;
    real_T dt;
    real_T n2;
    real_T q_mag;
    real_T qr_idx_1_tmp;
    real_T qr_idx_2_tmp;
    real_T qr_idx_2_tmp_0;
    real_T qr_idx_3_tmp;
    real_T qr_idx_3_tmp_0;
    real_T rtb_Atan2_n;
    real_T rtb_Sum6;
    real_T rtb_TSamp_af;
    real_T rtb_TSamp_k;
    real_T rtb_TSamp_n5;
    real_T rtb_TSamp_o;
    real_T sampleTime;
    real_T sampleTime_0;
    real_T sampleTime_1;
    real_T theta;
    real_T thrust_decay_factor;
    real_T yaw_quant;
    int32_T ipiv_0[6];
    int32_T Phi_tmp;
    int32_T d_j;
    int32_T i;
    int32_T jA;
    int32_T jAcol;
    int32_T kBcol;
    int32_T nz;
    int32_T q_minus_inv_tmp;
    int32_T rtb_StartClock;
    int32_T samplesRead;
    int32_T samplesRead_0;
    int32_T samplesRead_1;
    char_T *sErr;
    int8_T F_tmp[36];
    int8_T F_tmp_0[36];
    int8_T H_tmp[36];
    int8_T dq_corr_dual_tmp[9];
    int8_T ipiv[6];
    int8_T rtAction;
    int8_T rtPrevAction;
    uint8_T b_output[6];
    uint8_T b_output_0[6];
    uint8_T b_status;
    uint8_T slaveAddress;
    boolean_T x[8];
    boolean_T RelationalOperator_i[3];
    boolean_T rEQ0;
    boolean_T rejectPose;
    static const int8_T b_b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    static const real_T f[9] = { -0.5, -0.0, -0.0, -0.0, -0.5, -0.0, -0.0, -0.0,
      -0.5 };

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

    static const int8_T c[72] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      0, 0, 0, 0, 0, 0 };

    static const int8_T a[72] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
      0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0 };

    static const int8_T b[144] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 1 };

    static const real_T R[36] = { 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9 };

    static const real_T c_0[27] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2,
      0.2, 0.2, 0.2 };

    static const int8_T e[36] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    static const int8_T d[36] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
      0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    static const int8_T f_0[36] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    static const real_T axis[3] = { 0.0, 0.0, 1.0 };

    static const int8_T e_0[36] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    static const real_T l[9] = { 0.99875026039496628, -0.049979169270678331, 0.0,
      0.049979169270678331, 0.99875026039496628, 0.0, 0.0, 0.0, 1.0 };

    static const int8_T b_0[8] = { -1, -1, 0, 0, 1, 1, 0, 0 };

    static const int8_T c_1[8] = { 0, 0, 1, 1, 0, 0, -1, -1 };

    real_T dt_tmp;
    real_T n2_tmp;
    real_T n2_tmp_0;
    real_T n2_tmp_1;
    int32_T exitg1;
    const int8_T *DQMEKFP_tmp_1;
    const int8_T *tmp_5;
    const int8_T *tmp_6;

    // Outputs for IfAction SubSystem: '<S13>/Use Hardware to Obtain States' incorporates:
    //   ActionPort: '<S182>/Action Port'

    // Outputs for IfAction SubSystem: '<S1>/Phase #3: Experiment' incorporates:
    //   ActionPort: '<S30>/Action Port'

    // Outputs for IfAction SubSystem: '<S30>/Sub-Phase #1' incorporates:
    //   ActionPort: '<S38>/Action Port'

    // Outputs for IfAction SubSystem: '<S30>/Sub-Phase #3 ' incorporates:
    //   ActionPort: '<S40>/Action Port'

    // If: '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' incorporates:
    //   Clock: '<Root>/Clock'
    //   Clock: '<S183>/Clock'
    //   Clock: '<S64>/Clock'
    //   If: '<S1>/Separate Phases'
    //   If: '<S30>/Experiment Sub-Phases'
    //   SignalGenerator: '<S43>/Signal Generator'

    thrust_decay_factor = Fullexp_M->Timing.t[0];

    // End of Outputs for SubSystem: '<S30>/Sub-Phase #3 '
    // End of Outputs for SubSystem: '<S30>/Sub-Phase #1'
    // End of Outputs for SubSystem: '<S1>/Phase #3: Experiment'
    // End of Outputs for SubSystem: '<S13>/Use Hardware to Obtain States'

    // Clock: '<Root>/Clock'
    Fullexp_B.Clock = thrust_decay_factor;

    // Sum: '<Root>/Sum' incorporates:
    //   DataStoreWrite: '<Root>/Data Store Write'
    //   Delay: '<Root>/Delay'

    dt = Fullexp_B.Clock - Fullexp_DW.Delay_DSTATE;

    // MATLAB Function: '<Root>/MATLAB Function' incorporates:
    //   DataStoreRead: '<Root>/Data Store Read'

    Fullexp_MATLABFunction_f(Fullexp_DW.RED_Measured_States, rtb_x_k);

    // DataStoreWrite: '<Root>/Data Store Write4' incorporates:
    //   DataStoreWrite: '<Root>/Data Store Write1'
    //   DataStoreWrite: '<Root>/Data Store Write17'
    //   MATLAB Function: '<S19>/MATLAB Function'

    Fullexp_MATLABFunction_l(rtb_x_k, Red_dq, rtb_q_f, rtb_R_g, Red_x, rtb_v,
      rtb_x_b, &Red_yaw);

    // DataStoreWrite: '<Root>/Data Store Write2'
    Red_q[0] = rtb_q_f[0];
    Red_q[1] = rtb_q_f[1];
    Red_q[2] = rtb_q_f[2];
    Red_q[3] = rtb_q_f[3];

    // MATLAB Function: '<Root>/MATLAB Function1' incorporates:
    //   DataStoreRead: '<Root>/Data Store Read2'

    Fullexp_MATLABFunction_f(Fullexp_DW.BLACK_Measured_States, rtb_x_k);

    // MATLAB Function: '<S20>/MATLAB Function'
    Fullexp_MATLABFunction_l(rtb_x_k, rtb_dq_e, rtb_q_f, rtb_R_g, rtb_x_b, rtb_v,
      rtb_w, &rtb_Sum6);

    // MATLAB Function: '<S15>/MATLAB Function' incorporates:
    //   DataStoreRead: '<Root>/Data Store Read4'
    //   DataStoreWrite: '<Root>/Data Store Write13'
    //   DataStoreWrite: '<Root>/Data Store Write14'
    //   DataStoreWrite: '<Root>/Data Store Write15'

    rtb_Sum6 = sin(Fullexp_DW.Vis_yaw);
    ARM_Path_idx_1 = cos(Fullexp_DW.Vis_yaw);
    rtb_R_g[0] = ARM_Path_idx_1;
    rtb_R_g[3] = rtb_Sum6;
    rtb_R_g[6] = 0.0;
    rtb_R_g[1] = -rtb_Sum6;
    rtb_R_g[4] = ARM_Path_idx_1;
    rtb_R_g[7] = 0.0;
    rtb_R_g[2] = 0.0;
    rtb_R_g[5] = 0.0;
    rtb_R_g[8] = 1.0;
    for (d_j = 0; d_j < 3; d_j++) {
      i = d_j << 2;
      T[i] = rtb_R_g[3 * d_j];
      T[i + 1] = rtb_R_g[3 * d_j + 1];
      T[i + 2] = rtb_R_g[3 * d_j + 2];
      T[d_j + 12] = 0.0;
    }

    T[3] = 0.0;
    T[7] = 0.0;
    T[11] = 0.0;
    T[15] = 1.0;
    Fullexp_rotm2Quat(rtb_R_g, rtb_q_f);
    for (d_j = 0; d_j < 3; d_j++) {
      i = d_j << 2;
      T_0[3 * d_j] = T[i];
      T_0[3 * d_j + 1] = T[i + 1];
      T_0[3 * d_j + 2] = T[i + 2];
    }

    Fullexp_rotm2Quat(T_0, qr);
    rtb_Sum6 = T[12] / 2.0;
    rtb_v[0] = rtb_Sum6;
    ARM_Path_idx_1 = qr[1] * rtb_Sum6;
    rtb_Sum6 = T[13] / 2.0;
    rtb_v[1] = rtb_Sum6;
    ARM_Path_idx_1 += qr[2] * rtb_Sum6;
    rtb_Sum6 = T[14] / 2.0;
    rtb_v[2] = rtb_Sum6;
    yaw_quant = qr[0];
    dt_0[0] = 0.0;
    dt_0[3] = -qr[3];
    dt_0[6] = qr[2];
    dt_0[1] = qr[3];
    dt_0[4] = 0.0;
    dt_0[7] = -qr[1];
    dt_0[2] = -qr[2];
    dt_0[5] = qr[1];
    dt_0[8] = 0.0;
    for (d_j = 0; d_j < 3; d_j++) {
      rtb_v_0[d_j] = rtb_v[d_j] * yaw_quant - ((dt_0[d_j + 3] * rtb_v[1] +
        dt_0[d_j] * rtb_v[0]) + dt_0[d_j + 6] * rtb_Sum6);
    }

    rtb_dq_e[0] = qr[0];
    rtb_dq_e[1] = qr[1];
    rtb_dq_e[2] = qr[2];
    rtb_dq_e[3] = qr[3];
    rtb_dq_e[4] = -(qr[3] * rtb_Sum6 + ARM_Path_idx_1);
    rtb_dq_e[5] = rtb_v_0[0];

    // Outputs for IfAction SubSystem: '<S2>/Custom PPL (ARM)' incorporates:
    //   ActionPort: '<S89>/Action Port'

    // If: '<S2>/If3' incorporates:
    //   DataStoreRead: '<S99>/Data Store Read'
    //   DataStoreWrite: '<S2>/Data Store Write9'

    rtb_Sum6 = Fullexp_DW.ARM_Desired_States[0];

    // End of Outputs for SubSystem: '<S2>/Custom PPL (ARM)'

    // MATLAB Function: '<S15>/MATLAB Function' incorporates:
    //   DataStoreWrite: '<Root>/Data Store Write13'

    rtb_dq_e[6] = rtb_v_0[1];

    // Outputs for IfAction SubSystem: '<S2>/Custom PPL (ARM)' incorporates:
    //   ActionPort: '<S89>/Action Port'

    // If: '<S2>/If3' incorporates:
    //   DataStoreRead: '<S99>/Data Store Read'
    //   DataStoreWrite: '<S2>/Data Store Write9'

    ARM_Path_idx_1 = Fullexp_DW.ARM_Desired_States[1];

    // End of Outputs for SubSystem: '<S2>/Custom PPL (ARM)'

    // MATLAB Function: '<S15>/MATLAB Function' incorporates:
    //   DataStoreWrite: '<Root>/Data Store Write13'

    rtb_dq_e[7] = rtb_v_0[2];

    // Outputs for IfAction SubSystem: '<S2>/Custom PPL (ARM)' incorporates:
    //   ActionPort: '<S89>/Action Port'

    // If: '<S2>/If3' incorporates:
    //   DataStoreRead: '<S99>/Data Store Read'
    //   DataStoreWrite: '<S2>/Data Store Write9'

    ARM_Path_idx_2 = Fullexp_DW.ARM_Desired_States[2];

    // End of Outputs for SubSystem: '<S2>/Custom PPL (ARM)'

    // If: '<S2>/If1' incorporates:
    //   DataStoreRead: '<S2>/Data Store Read1'

    if (Fullexp_DW.BLACK_Path_Planner_Selection == 1.0) {
      // Outputs for IfAction SubSystem: '<S2>/Default APF PPL (BLACK)' incorporates:
      //   ActionPort: '<S93>/Action Port'

      // Concatenate: '<S105>/Matrix Concatenate' incorporates:
      //   DataStoreRead: '<S106>/Data Store Read1'
      //   DataStoreRead: '<S107>/RED Measured States '

      qr[0] = Fullexp_DW.BLUE_Measured_States[0];
      qr[1] = Fullexp_DW.RED_Measured_States[0];
      qr[2] = Fullexp_DW.BLUE_Measured_States[1];
      qr[3] = Fullexp_DW.RED_Measured_States[1];

      // DataStoreWrite: '<S2>/Data Store Write3' incorporates:
      //   Constant: '<S93>/Angular Gain'
      //   Constant: '<S93>/Attractive Gain'
      //   Constant: '<S93>/Influence Range'
      //   Constant: '<S93>/Repulsive Gain'
      //   DataStoreRead: '<S103>/RED_Px'
      //   DataStoreRead: '<S93>/RED_Px'
      //   MATLAB Function: '<S93>/MATLAB Function'

      BLACK_Path[0] = Fullexp_DW.BLACK_Measured_States[0];
      BLACK_Path[1] = Fullexp_DW.BLACK_Measured_States[1];
      BLACK_Path[2] = Fullexp_DW.BLACK_Measured_States[2];
      Fullexp_MATLABFunction(Fullexp_DW.BLACK_Desired_States, qr,
        Fullexp_P.AttractiveGain_Value_i, Fullexp_P.RepulsiveGain_Value_k,
        Fullexp_P.InfluenceRange_Value_d, Fullexp_P.AngularGain_Value_l,
        BLACK_Path);

      // End of Outputs for SubSystem: '<S2>/Default APF PPL (BLACK)'
    } else {
      // Outputs for IfAction SubSystem: '<S2>/Disable PPL (BLACK)' incorporates:
      //   ActionPort: '<S96>/Action Port'

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLACK)' incorporates:
      //   ActionPort: '<S90>/Action Port'

      // DataStoreWrite: '<S2>/Data Store Write3' incorporates:
      //   DataStoreRead: '<S100>/BLACK_Px'
      //   DataStoreRead: '<S114>/BLACK_Px'
      //   Merge: '<S3>/Merge6'

      BLACK_Path[0] = Fullexp_DW.BLACK_Desired_States[0];
      BLACK_Path[1] = Fullexp_DW.BLACK_Desired_States[1];
      BLACK_Path[2] = Fullexp_DW.BLACK_Desired_States[2];

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLACK)'
      // End of Outputs for SubSystem: '<S2>/Disable PPL (BLACK)'
    }

    // End of If: '<S2>/If1'

    // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
    //   ActionPort: '<S91>/Action Port'

    // If: '<S2>/If2' incorporates:
    //   DataStoreRead: '<S101>/Data Store Read4'
    //   DataStoreWrite: '<S2>/Data Store Write6'

    BLUE_Path_idx_0 = Fullexp_DW.BLUE_Desired_States[0];
    BLUE_Path_idx_1 = Fullexp_DW.BLUE_Desired_States[1];
    BLUE_Path_idx_2 = Fullexp_DW.BLUE_Desired_States[2];

    // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

    // If: '<S2>/If' incorporates:
    //   DataStoreRead: '<S2>/Data Store Read'

    if (Fullexp_DW.RED_Path_Planner_Selection == 1.0) {
      // Outputs for IfAction SubSystem: '<S2>/Default APF PPL (RED)' incorporates:
      //   ActionPort: '<S94>/Action Port'

      // Concatenate: '<S110>/Matrix Concatenate' incorporates:
      //   DataStoreRead: '<S111>/BLACK Measured States '
      //   DataStoreRead: '<S112>/Data Store Read1'

      qr[0] = Fullexp_DW.BLUE_Measured_States[0];
      qr[1] = Fullexp_DW.BLACK_Measured_States[0];
      qr[2] = Fullexp_DW.BLUE_Measured_States[1];
      qr[3] = Fullexp_DW.BLACK_Measured_States[1];

      // DataStoreWrite: '<S2>/Data Store Write' incorporates:
      //   Constant: '<S94>/Angular Gain'
      //   Constant: '<S94>/Attractive Gain'
      //   Constant: '<S94>/Influence Range'
      //   Constant: '<S94>/Repulsive Gain'
      //   DataStoreRead: '<S108>/RED_Px'
      //   DataStoreRead: '<S94>/RED_Px'
      //   MATLAB Function: '<S94>/MATLAB Function'

      RED_Path[0] = Fullexp_DW.RED_Measured_States[0];
      RED_Path[1] = Fullexp_DW.RED_Measured_States[1];
      RED_Path[2] = Fullexp_DW.RED_Measured_States[2];
      Fullexp_MATLABFunction(Fullexp_DW.RED_Desired_States, qr,
        Fullexp_P.AttractiveGain_Value, Fullexp_P.RepulsiveGain_Value,
        Fullexp_P.InfluenceRange_Value, Fullexp_P.AngularGain_Value, RED_Path);

      // End of Outputs for SubSystem: '<S2>/Default APF PPL (RED)'
    } else {
      // Outputs for IfAction SubSystem: '<S2>/Disable PPL (RED)' incorporates:
      //   ActionPort: '<S98>/Action Port'

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (RED)' incorporates:
      //   ActionPort: '<S92>/Action Port'

      // DataStoreWrite: '<S2>/Data Store Write' incorporates:
      //   DataStoreRead: '<S102>/RED_Px'
      //   DataStoreRead: '<S116>/RED_Px'
      //   Merge: '<S3>/Merge6'

      RED_Path[0] = Fullexp_DW.RED_Desired_States[0];
      RED_Path[1] = Fullexp_DW.RED_Desired_States[1];
      RED_Path[2] = Fullexp_DW.RED_Desired_States[2];

      // End of Outputs for SubSystem: '<S2>/Custom PPL (RED)'
      // End of Outputs for SubSystem: '<S2>/Disable PPL (RED)'
    }

    // End of If: '<S2>/If'

    // If: '<S3>/If1' incorporates:
    //   DataStoreRead: '<S3>/Data Store Read3'

    if (Fullexp_DW.BLACK_Control_Law_Enabler == 1.0) {
      // Outputs for IfAction SubSystem: '<S3>/Default PD Control (BLACK)' incorporates:
      //   ActionPort: '<S123>/Action Port'

      // MATLAB Function: '<S153>/MATLAB Function' incorporates:
      //   DataStoreRead: '<S123>/Data Store Read1'
      //   DataStoreRead: '<S123>/Data Store Read13'

      Fullexp_MATLABFunction_n(BLACK_Path[2], Fullexp_DW.BLACK_Measured_States[2],
        &rtb_TSamp_k);

      // SampleTimeMath: '<S154>/TSamp' incorporates:
      //   DataStoreRead: '<S123>/Data Store Read1'
      //
      //  About '<S154>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_af = BLACK_Path[0] * Fullexp_P.TSamp_WtEt_i;

      // Sum: '<S154>/Diff' incorporates:
      //   UnitDelay: '<S154>/UD'
      //
      //  Block description for '<S154>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S154>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_eh = rtb_TSamp_af - Fullexp_DW.UD_DSTATE_eh;

      // SampleTimeMath: '<S155>/TSamp' incorporates:
      //   DataStoreRead: '<S123>/Data Store Read1'
      //
      //  About '<S155>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_o = BLACK_Path[1] * Fullexp_P.TSamp_WtEt_hr;

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

      Fullexp_DW.UD_DSTATE_hv = rtb_TSamp_o - Fullexp_DW.UD_DSTATE_hv;

      // SampleTimeMath: '<S156>/TSamp' incorporates:
      //   DataStoreRead: '<S123>/Data Store Read1'
      //
      //  About '<S156>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_n5 = BLACK_Path[2] * Fullexp_P.TSamp_WtEt_ca;

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

      Fullexp_DW.UD_DSTATE_kv = rtb_TSamp_n5 - Fullexp_DW.UD_DSTATE_kv;

      // Sum: '<S123>/Subtract7' incorporates:
      //   DataStoreRead: '<S123>/Data Store Read13'
      //   UnitDelay: '<S154>/UD'
      //
      //  Block description for '<S154>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_eh = Fullexp_DW.BLACK_Measured_States[3] -
        Fullexp_DW.UD_DSTATE_eh;

      // Sum: '<S123>/Subtract6' incorporates:
      //   DataStoreRead: '<S123>/Data Store Read13'
      //   UnitDelay: '<S155>/UD'
      //
      //  Block description for '<S155>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_hv = Fullexp_DW.BLACK_Measured_States[4] -
        Fullexp_DW.UD_DSTATE_hv;

      // Sum: '<S123>/Subtract8' incorporates:
      //   DataStoreRead: '<S123>/Data Store Read13'
      //   UnitDelay: '<S156>/UD'
      //
      //  Block description for '<S156>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_kv = Fullexp_DW.BLACK_Measured_States[5] -
        Fullexp_DW.UD_DSTATE_kv;

      // Gain: '<S123>/Gain6' incorporates:
      //   DataStoreRead: '<S123>/Data Store Read1'
      //   DataStoreRead: '<S123>/Data Store Read13'
      //   Gain: '<S123>/Gain'
      //   Gain: '<S123>/Gain3'
      //   Merge: '<S3>/Merge1'
      //   Sum: '<S123>/Subtract5'
      //   Sum: '<S123>/Sum'
      //   UnitDelay: '<S154>/UD'
      //
      //  Block description for '<S154>/UD':
      //
      //   Store in Global RAM

      Fullexp_B.Merge1[0] = ((Fullexp_DW.BLACK_Measured_States[0] - BLACK_Path[0])
        * Fullexp_P.Kp_xb + Fullexp_P.Kd_xb * Fullexp_DW.UD_DSTATE_eh) *
        Fullexp_P.Gain6_Gain_g;

      // Gain: '<S123>/Gain7' incorporates:
      //   DataStoreRead: '<S123>/Data Store Read1'
      //   DataStoreRead: '<S123>/Data Store Read13'
      //   Gain: '<S123>/Gain1'
      //   Gain: '<S123>/Gain4'
      //   Merge: '<S3>/Merge1'
      //   Sum: '<S123>/Subtract4'
      //   Sum: '<S123>/Sum1'
      //   UnitDelay: '<S155>/UD'
      //
      //  Block description for '<S155>/UD':
      //
      //   Store in Global RAM

      Fullexp_B.Merge1[1] = ((Fullexp_DW.BLACK_Measured_States[1] - BLACK_Path[1])
        * Fullexp_P.Kp_yb + Fullexp_P.Kd_yb * Fullexp_DW.UD_DSTATE_hv) *
        Fullexp_P.Gain7_Gain_b;

      // Gain: '<S123>/Gain8' incorporates:
      //   Gain: '<S123>/Gain2'
      //   Gain: '<S123>/Gain5'
      //   Merge: '<S3>/Merge1'
      //   Sum: '<S123>/Sum2'
      //   UnitDelay: '<S156>/UD'
      //
      //  Block description for '<S156>/UD':
      //
      //   Store in Global RAM

      Fullexp_B.Merge1[2] = (Fullexp_P.Kp_tb * rtb_TSamp_k + Fullexp_P.Kd_tb *
        Fullexp_DW.UD_DSTATE_kv) * Fullexp_P.Gain8_Gain_m;

      // Update for UnitDelay: '<S154>/UD'
      //
      //  Block description for '<S154>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_eh = rtb_TSamp_af;

      // Update for UnitDelay: '<S155>/UD'
      //
      //  Block description for '<S155>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_hv = rtb_TSamp_o;

      // Update for UnitDelay: '<S156>/UD'
      //
      //  Block description for '<S156>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_kv = rtb_TSamp_n5;

      // End of Outputs for SubSystem: '<S3>/Default PD Control (BLACK)'
    } else if (Fullexp_DW.BLACK_Control_Law_Enabler == 2.0) {
      // Outputs for IfAction SubSystem: '<S3>/Default LQR Control (BLACK)' incorporates:
      //   ActionPort: '<S119>/Action Port'

      // Product: '<S119>/Matrix Multiply' incorporates:
      //   DataStoreRead: '<S119>/Data Store Read1'
      //   DataStoreRead: '<S119>/Data Store Read13'
      //   MATLAB Function: '<S130>/MATLAB Function'

      Fullexp_MATLABFunction_n(BLACK_Path[2], Fullexp_DW.BLACK_Measured_States[2],
        &y[2]);

      // SampleTimeMath: '<S131>/TSamp' incorporates:
      //   DataStoreRead: '<S119>/Data Store Read1'
      //
      //  About '<S131>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_k = BLACK_Path[0] * Fullexp_P.TSamp_WtEt_nd;

      // Sum: '<S131>/Diff' incorporates:
      //   UnitDelay: '<S131>/UD'
      //
      //  Block description for '<S131>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S131>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_j = rtb_TSamp_k - Fullexp_DW.UD_DSTATE_j;

      // SampleTimeMath: '<S132>/TSamp' incorporates:
      //   DataStoreRead: '<S119>/Data Store Read1'
      //
      //  About '<S132>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_af = BLACK_Path[1] * Fullexp_P.TSamp_WtEt_co;

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

      Fullexp_DW.UD_DSTATE_c = rtb_TSamp_af - Fullexp_DW.UD_DSTATE_c;

      // SampleTimeMath: '<S133>/TSamp' incorporates:
      //   DataStoreRead: '<S119>/Data Store Read1'
      //
      //  About '<S133>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_o = BLACK_Path[2] * Fullexp_P.TSamp_WtEt_no;

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

      Fullexp_DW.UD_DSTATE_d = rtb_TSamp_o - Fullexp_DW.UD_DSTATE_d;

      // Sum: '<S119>/Subtract7' incorporates:
      //   DataStoreRead: '<S119>/Data Store Read13'
      //   UnitDelay: '<S131>/UD'
      //
      //  Block description for '<S131>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_j = Fullexp_DW.BLACK_Measured_States[3] -
        Fullexp_DW.UD_DSTATE_j;

      // Sum: '<S119>/Subtract6' incorporates:
      //   DataStoreRead: '<S119>/Data Store Read13'
      //   UnitDelay: '<S132>/UD'
      //
      //  Block description for '<S132>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_c = Fullexp_DW.BLACK_Measured_States[4] -
        Fullexp_DW.UD_DSTATE_c;

      // Sum: '<S119>/Subtract8' incorporates:
      //   DataStoreRead: '<S119>/Data Store Read13'
      //   UnitDelay: '<S133>/UD'
      //
      //  Block description for '<S133>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_d = Fullexp_DW.BLACK_Measured_States[5] -
        Fullexp_DW.UD_DSTATE_d;
      for (d_j = 0; d_j < 18; d_j++) {
        // Product: '<S119>/Matrix Multiply' incorporates:
        //   Constant: '<S119>/Constant2'

        tmp_0[d_j] = -Fullexp_P.K_BLACK[d_j];
      }

      // Product: '<S119>/Matrix Multiply' incorporates:
      //   DataStoreRead: '<S119>/Data Store Read1'
      //   DataStoreRead: '<S119>/Data Store Read13'
      //   Reshape: '<S119>/Reshape1'
      //   Reshape: '<S119>/Reshape3'
      //   Sum: '<S119>/Subtract4'
      //   Sum: '<S119>/Subtract5'
      //   UnitDelay: '<S131>/UD'
      //   UnitDelay: '<S132>/UD'
      //   UnitDelay: '<S133>/UD'
      //
      //  Block description for '<S131>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S132>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S133>/UD':
      //
      //   Store in Global RAM

      y[0] = Fullexp_DW.BLACK_Measured_States[0] - BLACK_Path[0];
      y[1] = Fullexp_DW.BLACK_Measured_States[1] - BLACK_Path[1];
      y[3] = Fullexp_DW.UD_DSTATE_j;
      y[4] = Fullexp_DW.UD_DSTATE_c;
      y[5] = Fullexp_DW.UD_DSTATE_d;
      for (d_j = 0; d_j < 3; d_j++) {
        // Product: '<S119>/Matrix Multiply' incorporates:
        //   Merge: '<S3>/Merge1'

        rtb_TSamp_n5 = 0.0;
        for (i = 0; i < 6; i++) {
          // Merge: '<S3>/Merge1' incorporates:
          //   Product: '<S119>/Matrix Multiply'
          //   Reshape: '<S119>/Reshape4'

          rtb_TSamp_n5 += tmp_0[3 * i + d_j] * y[i];
        }

        // Merge: '<S3>/Merge1' incorporates:
        //   Product: '<S119>/Matrix Multiply'

        Fullexp_B.Merge1[d_j] = rtb_TSamp_n5;
      }

      // Update for UnitDelay: '<S131>/UD'
      //
      //  Block description for '<S131>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_j = rtb_TSamp_k;

      // Update for UnitDelay: '<S132>/UD'
      //
      //  Block description for '<S132>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_c = rtb_TSamp_af;

      // Update for UnitDelay: '<S133>/UD'
      //
      //  Block description for '<S133>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_d = rtb_TSamp_o;

      // End of Outputs for SubSystem: '<S3>/Default LQR Control (BLACK)'
    } else {
      // Outputs for IfAction SubSystem: '<S3>/Disable Thrusters (BLACK)' incorporates:
      //   ActionPort: '<S127>/Action Port'

      Fullexp_DisableThrustersBLACK(Fullexp_B.Merge1,
        &Fullexp_P.DisableThrustersBLACK);

      // End of Outputs for SubSystem: '<S3>/Disable Thrusters (BLACK)'
    }

    // End of If: '<S3>/If1'

    // DataStoreWrite: '<S3>/BLACK Controls'
    rtb_x_b[0] = Fullexp_B.Merge1[0];
    rtb_x_b[1] = Fullexp_B.Merge1[1];
    rtb_x_b[2] = Fullexp_B.Merge1[2];

    // If: '<S3>/If2' incorporates:
    //   DataStoreRead: '<S3>/Data Store Read2'

    if (Fullexp_DW.BLUE_Control_Law_Enabler == 1.0) {
      // Outputs for IfAction SubSystem: '<S3>/Default PD Control (BLUE)' incorporates:
      //   ActionPort: '<S124>/Action Port'

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S91>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S101>/Data Store Read4'
      //   DataStoreRead: '<S124>/Data Store Read2'
      //   MATLAB Function: '<S158>/MATLAB Function'
      //   SampleTimeMath: '<S159>/TSamp'
      //
      //  About '<S159>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      Fullexp_MATLABFunction_n(Fullexp_DW.BLUE_Desired_States[2],
        Fullexp_DW.BLUE_Measured_States[2], &rtb_TSamp_k);
      rtb_TSamp_af = Fullexp_DW.BLUE_Desired_States[0] * Fullexp_P.TSamp_WtEt_p;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Sum: '<S159>/Diff' incorporates:
      //   UnitDelay: '<S159>/UD'
      //
      //  Block description for '<S159>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S159>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_o = rtb_TSamp_af - Fullexp_DW.UD_DSTATE_o;

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S91>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S101>/Data Store Read4'
      //   SampleTimeMath: '<S160>/TSamp'
      //
      //  About '<S160>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_o = Fullexp_DW.BLUE_Desired_States[1] * Fullexp_P.TSamp_WtEt_o;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Sum: '<S160>/Diff' incorporates:
      //   UnitDelay: '<S160>/UD'
      //
      //  Block description for '<S160>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S160>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_n = rtb_TSamp_o - Fullexp_DW.UD_DSTATE_n;

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S91>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S101>/Data Store Read4'
      //   SampleTimeMath: '<S161>/TSamp'
      //
      //  About '<S161>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_n5 = Fullexp_DW.BLUE_Desired_States[2] * Fullexp_P.TSamp_WtEt_px;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Sum: '<S161>/Diff' incorporates:
      //   UnitDelay: '<S161>/UD'
      //
      //  Block description for '<S161>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S161>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_hu = rtb_TSamp_n5 - Fullexp_DW.UD_DSTATE_hu;

      // Sum: '<S124>/Subtract7' incorporates:
      //   DataStoreRead: '<S124>/Data Store Read2'
      //   UnitDelay: '<S159>/UD'
      //
      //  Block description for '<S159>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_o = Fullexp_DW.BLUE_Measured_States[3] -
        Fullexp_DW.UD_DSTATE_o;

      // Sum: '<S124>/Subtract6' incorporates:
      //   DataStoreRead: '<S124>/Data Store Read2'
      //   UnitDelay: '<S160>/UD'
      //
      //  Block description for '<S160>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_n = Fullexp_DW.BLUE_Measured_States[4] -
        Fullexp_DW.UD_DSTATE_n;

      // Sum: '<S124>/Subtract8' incorporates:
      //   DataStoreRead: '<S124>/Data Store Read2'
      //   UnitDelay: '<S161>/UD'
      //
      //  Block description for '<S161>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_hu = Fullexp_DW.BLUE_Measured_States[5] -
        Fullexp_DW.UD_DSTATE_hu;

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S91>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S101>/Data Store Read4'
      //   DataStoreRead: '<S124>/Data Store Read2'
      //   Gain: '<S124>/Gain'
      //   Gain: '<S124>/Gain1'
      //   Gain: '<S124>/Gain3'
      //   Gain: '<S124>/Gain4'
      //   Gain: '<S124>/Gain6'
      //   Gain: '<S124>/Gain7'
      //   Merge: '<S3>/Merge2'
      //   Sum: '<S124>/Subtract4'
      //   Sum: '<S124>/Subtract5'
      //   Sum: '<S124>/Sum'
      //   Sum: '<S124>/Sum1'
      //   UnitDelay: '<S159>/UD'
      //   UnitDelay: '<S160>/UD'
      //
      //  Block description for '<S159>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S160>/UD':
      //
      //   Store in Global RAM

      Fullexp_B.Merge2[0] = ((Fullexp_DW.BLUE_Measured_States[0] -
        Fullexp_DW.BLUE_Desired_States[0]) * Fullexp_P.Kp_xblue +
        Fullexp_P.Kd_xblue * Fullexp_DW.UD_DSTATE_o) * Fullexp_P.Gain6_Gain_a;
      Fullexp_B.Merge2[1] = ((Fullexp_DW.BLUE_Measured_States[1] -
        Fullexp_DW.BLUE_Desired_States[1]) * Fullexp_P.Kp_yblue +
        Fullexp_P.Kd_yblue * Fullexp_DW.UD_DSTATE_n) * Fullexp_P.Gain7_Gain_e;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Gain: '<S124>/Gain8' incorporates:
      //   Gain: '<S124>/Gain2'
      //   Gain: '<S124>/Gain5'
      //   Merge: '<S3>/Merge2'
      //   Sum: '<S124>/Sum2'
      //   UnitDelay: '<S161>/UD'
      //
      //  Block description for '<S161>/UD':
      //
      //   Store in Global RAM

      Fullexp_B.Merge2[2] = (Fullexp_P.Kp_tblue * rtb_TSamp_k +
        Fullexp_P.Kd_tblue * Fullexp_DW.UD_DSTATE_hu) * Fullexp_P.Gain8_Gain_g;

      // Update for UnitDelay: '<S159>/UD'
      //
      //  Block description for '<S159>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_o = rtb_TSamp_af;

      // Update for UnitDelay: '<S160>/UD'
      //
      //  Block description for '<S160>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_n = rtb_TSamp_o;

      // Update for UnitDelay: '<S161>/UD'
      //
      //  Block description for '<S161>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_hu = rtb_TSamp_n5;

      // End of Outputs for SubSystem: '<S3>/Default PD Control (BLUE)'
    } else if (Fullexp_DW.BLUE_Control_Law_Enabler == 2.0) {
      // Outputs for IfAction SubSystem: '<S3>/Default LQR Control (BLUE)' incorporates:
      //   ActionPort: '<S120>/Action Port'

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S91>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S101>/Data Store Read4'
      //   DataStoreRead: '<S120>/Data Store Read2'
      //   MATLAB Function: '<S135>/MATLAB Function'
      //   Product: '<S120>/Matrix Multiply'
      //   SampleTimeMath: '<S136>/TSamp'
      //
      //  About '<S136>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      Fullexp_MATLABFunction_n(Fullexp_DW.BLUE_Desired_States[2],
        Fullexp_DW.BLUE_Measured_States[2], &Lambda_sol[2]);
      rtb_TSamp_k = Fullexp_DW.BLUE_Desired_States[0] * Fullexp_P.TSamp_WtEt_ft;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Sum: '<S136>/Diff' incorporates:
      //   UnitDelay: '<S136>/UD'
      //
      //  Block description for '<S136>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S136>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_l = rtb_TSamp_k - Fullexp_DW.UD_DSTATE_l;

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S91>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S101>/Data Store Read4'
      //   SampleTimeMath: '<S137>/TSamp'
      //
      //  About '<S137>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_af = Fullexp_DW.BLUE_Desired_States[1] * Fullexp_P.TSamp_WtEt_eh;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Sum: '<S137>/Diff' incorporates:
      //   UnitDelay: '<S137>/UD'
      //
      //  Block description for '<S137>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S137>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_k = rtb_TSamp_af - Fullexp_DW.UD_DSTATE_k;

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S91>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S101>/Data Store Read4'
      //   SampleTimeMath: '<S138>/TSamp'
      //
      //  About '<S138>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_o = Fullexp_DW.BLUE_Desired_States[2] * Fullexp_P.TSamp_WtEt_ii;

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Sum: '<S138>/Diff' incorporates:
      //   UnitDelay: '<S138>/UD'
      //
      //  Block description for '<S138>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S138>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_h = rtb_TSamp_o - Fullexp_DW.UD_DSTATE_h;

      // Sum: '<S120>/Subtract7' incorporates:
      //   DataStoreRead: '<S120>/Data Store Read2'
      //   UnitDelay: '<S136>/UD'
      //
      //  Block description for '<S136>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_l = Fullexp_DW.BLUE_Measured_States[3] -
        Fullexp_DW.UD_DSTATE_l;

      // Sum: '<S120>/Subtract6' incorporates:
      //   DataStoreRead: '<S120>/Data Store Read2'
      //   UnitDelay: '<S137>/UD'
      //
      //  Block description for '<S137>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_k = Fullexp_DW.BLUE_Measured_States[4] -
        Fullexp_DW.UD_DSTATE_k;

      // Sum: '<S120>/Subtract8' incorporates:
      //   DataStoreRead: '<S120>/Data Store Read2'
      //   UnitDelay: '<S138>/UD'
      //
      //  Block description for '<S138>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_h = Fullexp_DW.BLUE_Measured_States[5] -
        Fullexp_DW.UD_DSTATE_h;
      for (d_j = 0; d_j < 18; d_j++) {
        // Product: '<S120>/Matrix Multiply' incorporates:
        //   Constant: '<S120>/Constant2'

        tmp_0[d_j] = -Fullexp_P.K_BLUE[d_j];
      }

      // Outputs for IfAction SubSystem: '<S2>/Custom PPL (BLUE)' incorporates:
      //   ActionPort: '<S91>/Action Port'

      // If: '<S2>/If2' incorporates:
      //   DataStoreRead: '<S101>/Data Store Read4'
      //   DataStoreRead: '<S120>/Data Store Read2'
      //   Product: '<S120>/Matrix Multiply'
      //   Reshape: '<S120>/Reshape1'
      //   Sum: '<S120>/Subtract4'
      //   Sum: '<S120>/Subtract5'

      Lambda_sol[0] = Fullexp_DW.BLUE_Measured_States[0] -
        Fullexp_DW.BLUE_Desired_States[0];
      Lambda_sol[1] = Fullexp_DW.BLUE_Measured_States[1] -
        Fullexp_DW.BLUE_Desired_States[1];

      // End of Outputs for SubSystem: '<S2>/Custom PPL (BLUE)'

      // Product: '<S120>/Matrix Multiply' incorporates:
      //   Reshape: '<S120>/Reshape2'
      //   UnitDelay: '<S136>/UD'
      //   UnitDelay: '<S137>/UD'
      //   UnitDelay: '<S138>/UD'
      //
      //  Block description for '<S136>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S137>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S138>/UD':
      //
      //   Store in Global RAM

      Lambda_sol[3] = Fullexp_DW.UD_DSTATE_l;
      Lambda_sol[4] = Fullexp_DW.UD_DSTATE_k;
      Lambda_sol[5] = Fullexp_DW.UD_DSTATE_h;
      for (d_j = 0; d_j < 3; d_j++) {
        // Product: '<S120>/Matrix Multiply' incorporates:
        //   Merge: '<S3>/Merge2'

        rtb_TSamp_n5 = 0.0;
        for (i = 0; i < 6; i++) {
          // Merge: '<S3>/Merge2' incorporates:
          //   Product: '<S120>/Matrix Multiply'
          //   Reshape: '<S120>/Reshape4'

          rtb_TSamp_n5 += tmp_0[3 * i + d_j] * Lambda_sol[i];
        }

        // Merge: '<S3>/Merge2' incorporates:
        //   Product: '<S120>/Matrix Multiply'

        Fullexp_B.Merge2[d_j] = rtb_TSamp_n5;
      }

      // Update for UnitDelay: '<S136>/UD'
      //
      //  Block description for '<S136>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_l = rtb_TSamp_k;

      // Update for UnitDelay: '<S137>/UD'
      //
      //  Block description for '<S137>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_k = rtb_TSamp_af;

      // Update for UnitDelay: '<S138>/UD'
      //
      //  Block description for '<S138>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_h = rtb_TSamp_o;

      // End of Outputs for SubSystem: '<S3>/Default LQR Control (BLUE)'
    } else {
      // Outputs for IfAction SubSystem: '<S3>/Disable Thrusters (BLUE)' incorporates:
      //   ActionPort: '<S128>/Action Port'

      Fullexp_DisableThrustersBLACK(Fullexp_B.Merge2,
        &Fullexp_P.DisableThrustersBLUE);

      // End of Outputs for SubSystem: '<S3>/Disable Thrusters (BLUE)'
    }

    // End of If: '<S3>/If2'

    // DataStoreWrite: '<S3>/BLUE Controls'
    rtb_v[0] = Fullexp_B.Merge2[0];
    rtb_v[1] = Fullexp_B.Merge2[1];
    rtb_v[2] = Fullexp_B.Merge2[2];

    // If: '<S3>/If3' incorporates:
    //   DataStoreRead: '<S3>/Data Store Read5'

    if (Fullexp_DW.ARM_Control_Law_Enabler == 1.0) {
      // Outputs for IfAction SubSystem: '<S3>/Default PD (ARM)' incorporates:
      //   ActionPort: '<S122>/Action Port'

      // DataStoreWrite: '<S122>/Data Store Write12' incorporates:
      //   Constant: '<S122>/Constant7'

      Fullexp_DW.ARM_Control_Mode = Fullexp_P.Constant7_Value_a;

      // If: '<S122>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
      //   DataStoreRead: '<S122>/Data Store Read4'

      if (Fullexp_DW.isSim == 1.0) {
        // Outputs for IfAction SubSystem: '<S122>/Simulated Position Controller' incorporates:
        //   ActionPort: '<S146>/Action Port'

        // Outputs for IfAction SubSystem: '<S2>/Custom PPL (ARM)' incorporates:
        //   ActionPort: '<S89>/Action Port'

        // If: '<S2>/If3' incorporates:
        //   DataStoreRead: '<S146>/Data Store Read2'
        //   DataStoreRead: '<S99>/Data Store Read'
        //   Sum: '<S146>/Subtract3'

        rtb_TSamp_k = Fullexp_DW.ARM_Desired_States[1] -
          Fullexp_DW.ARM_Measured_States[1];

        // End of Outputs for SubSystem: '<S2>/Custom PPL (ARM)'

        // SampleTimeMath: '<S150>/TSamp'
        //
        //  About '<S150>/TSamp':
        //   y = u * K where K = 1 / ( w * Ts )
        //
        rtb_TSamp_af = rtb_TSamp_k * Fullexp_P.TSamp_WtEt_pu;

        // Sum: '<S147>/Sum3' incorporates:
        //   Gain: '<S147>/kd_elarm'
        //   Gain: '<S147>/kp_elarm'
        //   Sum: '<S150>/Diff'
        //   UnitDelay: '<S150>/UD'
        //
        //  Block description for '<S150>/Diff':
        //
        //   Add in CPU
        //
        //  Block description for '<S150>/UD':
        //
        //   Store in Global RAM

        Fullexp_DW.UD_DSTATE = (rtb_TSamp_af - Fullexp_DW.UD_DSTATE) *
          Fullexp_P.Kd_elarm + Fullexp_P.Kp_elarm * rtb_TSamp_k;

        // Outputs for IfAction SubSystem: '<S2>/Custom PPL (ARM)' incorporates:
        //   ActionPort: '<S89>/Action Port'

        // If: '<S2>/If3' incorporates:
        //   DataStoreRead: '<S146>/Data Store Read2'
        //   DataStoreRead: '<S99>/Data Store Read'
        //   Sum: '<S146>/Subtract2'

        rtb_TSamp_k = Fullexp_DW.ARM_Desired_States[0] -
          Fullexp_DW.ARM_Measured_States[0];

        // End of Outputs for SubSystem: '<S2>/Custom PPL (ARM)'

        // SampleTimeMath: '<S151>/TSamp'
        //
        //  About '<S151>/TSamp':
        //   y = u * K where K = 1 / ( w * Ts )
        //
        rtb_TSamp_o = rtb_TSamp_k * Fullexp_P.TSamp_WtEt_f0;

        // Sum: '<S148>/Sum3' incorporates:
        //   Gain: '<S148>/kd_sharm'
        //   Gain: '<S148>/kp_sharm'
        //   Sum: '<S151>/Diff'
        //   UnitDelay: '<S151>/UD'
        //
        //  Block description for '<S151>/Diff':
        //
        //   Add in CPU
        //
        //  Block description for '<S151>/UD':
        //
        //   Store in Global RAM

        Fullexp_DW.UD_DSTATE_e = (rtb_TSamp_o - Fullexp_DW.UD_DSTATE_e) *
          Fullexp_P.Kd_sharm + Fullexp_P.Kp_sharm * rtb_TSamp_k;

        // Outputs for IfAction SubSystem: '<S2>/Custom PPL (ARM)' incorporates:
        //   ActionPort: '<S89>/Action Port'

        // If: '<S2>/If3' incorporates:
        //   DataStoreRead: '<S146>/Data Store Read2'
        //   DataStoreRead: '<S99>/Data Store Read'
        //   Sum: '<S146>/Subtract4'

        rtb_TSamp_k = Fullexp_DW.ARM_Desired_States[2] -
          Fullexp_DW.ARM_Measured_States[2];

        // End of Outputs for SubSystem: '<S2>/Custom PPL (ARM)'

        // SampleTimeMath: '<S152>/TSamp'
        //
        //  About '<S152>/TSamp':
        //   y = u * K where K = 1 / ( w * Ts )
        //
        rtb_TSamp_n5 = rtb_TSamp_k * Fullexp_P.TSamp_WtEt_nz;

        // Sum: '<S149>/Sum3' incorporates:
        //   Gain: '<S149>/kd_wrarm'
        //   Gain: '<S149>/kp_wrarm'
        //   Sum: '<S152>/Diff'
        //   UnitDelay: '<S152>/UD'
        //
        //  Block description for '<S152>/Diff':
        //
        //   Add in CPU
        //
        //  Block description for '<S152>/UD':
        //
        //   Store in Global RAM

        Fullexp_DW.UD_DSTATE_a = (rtb_TSamp_n5 - Fullexp_DW.UD_DSTATE_a) *
          Fullexp_P.Kd_wrarm + Fullexp_P.Kp_wrarm * rtb_TSamp_k;

        // Saturate: '<S146>/Saturation' incorporates:
        //   UnitDelay: '<S151>/UD'
        //
        //  Block description for '<S151>/UD':
        //
        //   Store in Global RAM

        if (Fullexp_DW.UD_DSTATE_e > Fullexp_P.Tz_lim_sharm) {
          // DataStoreWrite: '<S3>/Data Store Write9' incorporates:
          //   Merge: '<S122>/Merge3'

          ARM_Controls[0] = Fullexp_P.Tz_lim_sharm;
        } else if (Fullexp_DW.UD_DSTATE_e < -Fullexp_P.Tz_lim_sharm) {
          // DataStoreWrite: '<S3>/Data Store Write9' incorporates:
          //   Merge: '<S122>/Merge3'

          ARM_Controls[0] = -Fullexp_P.Tz_lim_sharm;
        } else {
          // DataStoreWrite: '<S3>/Data Store Write9' incorporates:
          //   Merge: '<S122>/Merge3'

          ARM_Controls[0] = Fullexp_DW.UD_DSTATE_e;
        }

        // End of Saturate: '<S146>/Saturation'

        // Saturate: '<S146>/Saturation1' incorporates:
        //   UnitDelay: '<S150>/UD'
        //
        //  Block description for '<S150>/UD':
        //
        //   Store in Global RAM

        if (Fullexp_DW.UD_DSTATE > Fullexp_P.Tz_lim_elarm) {
          // DataStoreWrite: '<S3>/Data Store Write9' incorporates:
          //   Merge: '<S122>/Merge4'

          ARM_Controls[1] = Fullexp_P.Tz_lim_elarm;
        } else if (Fullexp_DW.UD_DSTATE < -Fullexp_P.Tz_lim_elarm) {
          // DataStoreWrite: '<S3>/Data Store Write9' incorporates:
          //   Merge: '<S122>/Merge4'

          ARM_Controls[1] = -Fullexp_P.Tz_lim_elarm;
        } else {
          // DataStoreWrite: '<S3>/Data Store Write9' incorporates:
          //   Merge: '<S122>/Merge4'

          ARM_Controls[1] = Fullexp_DW.UD_DSTATE;
        }

        // End of Saturate: '<S146>/Saturation1'

        // Saturate: '<S146>/Saturation3' incorporates:
        //   UnitDelay: '<S152>/UD'
        //
        //  Block description for '<S152>/UD':
        //
        //   Store in Global RAM

        if (Fullexp_DW.UD_DSTATE_a > Fullexp_P.Tz_lim_wrarm) {
          // DataStoreWrite: '<S3>/Data Store Write9' incorporates:
          //   Merge: '<S122>/Merge5'

          ARM_Controls[2] = Fullexp_P.Tz_lim_wrarm;
        } else if (Fullexp_DW.UD_DSTATE_a < -Fullexp_P.Tz_lim_wrarm) {
          // DataStoreWrite: '<S3>/Data Store Write9' incorporates:
          //   Merge: '<S122>/Merge5'

          ARM_Controls[2] = -Fullexp_P.Tz_lim_wrarm;
        } else {
          // DataStoreWrite: '<S3>/Data Store Write9' incorporates:
          //   Merge: '<S122>/Merge5'

          ARM_Controls[2] = Fullexp_DW.UD_DSTATE_a;
        }

        // End of Saturate: '<S146>/Saturation3'

        // Update for UnitDelay: '<S150>/UD'
        //
        //  Block description for '<S150>/UD':
        //
        //   Store in Global RAM

        Fullexp_DW.UD_DSTATE = rtb_TSamp_af;

        // Update for UnitDelay: '<S151>/UD'
        //
        //  Block description for '<S151>/UD':
        //
        //   Store in Global RAM

        Fullexp_DW.UD_DSTATE_e = rtb_TSamp_o;

        // Update for UnitDelay: '<S152>/UD'
        //
        //  Block description for '<S152>/UD':
        //
        //   Store in Global RAM

        Fullexp_DW.UD_DSTATE_a = rtb_TSamp_n5;

        // End of Outputs for SubSystem: '<S122>/Simulated Position Controller'
      } else {
        // Outputs for IfAction SubSystem: '<S122>/Passthrough for Experiment' incorporates:
        //   ActionPort: '<S145>/Action Port'

        // Outputs for IfAction SubSystem: '<S2>/Custom PPL (ARM)' incorporates:
        //   ActionPort: '<S89>/Action Port'

        // If: '<S2>/If3' incorporates:
        //   DataStoreRead: '<S99>/Data Store Read'
        //   DataStoreWrite: '<S3>/Data Store Write9'
        //   Merge: '<S122>/Merge3'
        //   Merge: '<S122>/Merge4'
        //   Merge: '<S122>/Merge5'
        //   SignalConversion generated from: '<S145>/q1_desired'
        //   SignalConversion generated from: '<S145>/q2_desired'
        //   SignalConversion generated from: '<S145>/q3_desired'

        ARM_Controls[0] = Fullexp_DW.ARM_Desired_States[0];
        ARM_Controls[1] = Fullexp_DW.ARM_Desired_States[1];
        ARM_Controls[2] = Fullexp_DW.ARM_Desired_States[2];

        // End of Outputs for SubSystem: '<S2>/Custom PPL (ARM)'
        // End of Outputs for SubSystem: '<S122>/Passthrough for Experiment'
      }

      // End of If: '<S122>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 
      // End of Outputs for SubSystem: '<S3>/Default PD (ARM)'
    } else if (Fullexp_DW.ARM_Control_Law_Enabler == 2.0) {
      // Outputs for IfAction SubSystem: '<S3>/Custom Control (ARM)' incorporates:
      //   ActionPort: '<S117>/Action Port'

      // DataStoreWrite: '<S3>/Data Store Write9'
      Fullexp_CustomControlRED(ARM_Controls, &Fullexp_P.CustomControlARM);

      // End of Outputs for SubSystem: '<S3>/Custom Control (ARM)'
    } else {
      // Outputs for IfAction SubSystem: '<S3>/Disable Control (ARM)' incorporates:
      //   ActionPort: '<S126>/Action Port'

      // DataStoreWrite: '<S126>/Data Store Write12' incorporates:
      //   Constant: '<S126>/Constant7'

      Fullexp_DW.ARM_Control_Mode = Fullexp_P.Constant7_Value_h;

      // DataStoreWrite: '<S3>/Data Store Write9' incorporates:
      //   Constant: '<S126>/Zero'
      //   Merge: '<S3>/Merge6'
      //   SignalConversion generated from: '<S126>/Out1'

      ARM_Controls[0] = Fullexp_P.Zero_Value;
      ARM_Controls[1] = Fullexp_P.Zero_Value;
      ARM_Controls[2] = Fullexp_P.Zero_Value;

      // End of Outputs for SubSystem: '<S3>/Disable Control (ARM)'
    }

    // End of If: '<S3>/If3'

    // If: '<S3>/If' incorporates:
    //   DataStoreRead: '<S3>/Data Store Read1'

    if (Fullexp_DW.RED_Control_Law_Enabler == 1.0) {
      // Outputs for IfAction SubSystem: '<S3>/Default PD Control (RED)' incorporates:
      //   ActionPort: '<S125>/Action Port'

      // MATLAB Function: '<S163>/MATLAB Function' incorporates:
      //   DataStoreRead: '<S125>/Data Store Read1'
      //   DataStoreRead: '<S125>/Data Store Read13'

      Fullexp_MATLABFunction_n(RED_Path[2], Fullexp_DW.RED_Measured_States[2],
        &rtb_TSamp_k);

      // SampleTimeMath: '<S164>/TSamp' incorporates:
      //   DataStoreRead: '<S125>/Data Store Read1'
      //
      //  About '<S164>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_af = RED_Path[0] * Fullexp_P.TSamp_WtEt;

      // Sum: '<S164>/Diff' incorporates:
      //   UnitDelay: '<S164>/UD'
      //
      //  Block description for '<S164>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S164>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_eg = rtb_TSamp_af - Fullexp_DW.UD_DSTATE_eg;

      // SampleTimeMath: '<S165>/TSamp' incorporates:
      //   DataStoreRead: '<S125>/Data Store Read1'
      //
      //  About '<S165>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_o = RED_Path[1] * Fullexp_P.TSamp_WtEt_f;

      // Sum: '<S165>/Diff' incorporates:
      //   UnitDelay: '<S165>/UD'
      //
      //  Block description for '<S165>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S165>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_cd = rtb_TSamp_o - Fullexp_DW.UD_DSTATE_cd;

      // SampleTimeMath: '<S166>/TSamp' incorporates:
      //   DataStoreRead: '<S125>/Data Store Read1'
      //
      //  About '<S166>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_n5 = RED_Path[2] * Fullexp_P.TSamp_WtEt_c;

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

      Fullexp_DW.UD_DSTATE_hd = rtb_TSamp_n5 - Fullexp_DW.UD_DSTATE_hd;

      // Sum: '<S125>/Subtract7' incorporates:
      //   DataStoreRead: '<S125>/Data Store Read13'
      //   UnitDelay: '<S164>/UD'
      //
      //  Block description for '<S164>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_eg = Fullexp_DW.RED_Measured_States[3] -
        Fullexp_DW.UD_DSTATE_eg;

      // Sum: '<S125>/Subtract6' incorporates:
      //   DataStoreRead: '<S125>/Data Store Read13'
      //   UnitDelay: '<S165>/UD'
      //
      //  Block description for '<S165>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_cd = Fullexp_DW.RED_Measured_States[4] -
        Fullexp_DW.UD_DSTATE_cd;

      // Sum: '<S125>/Subtract8' incorporates:
      //   DataStoreRead: '<S125>/Data Store Read13'
      //   UnitDelay: '<S166>/UD'
      //
      //  Block description for '<S166>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_hd = Fullexp_DW.RED_Measured_States[5] -
        Fullexp_DW.UD_DSTATE_hd;

      // Gain: '<S125>/Gain6' incorporates:
      //   DataStoreRead: '<S125>/Data Store Read1'
      //   DataStoreRead: '<S125>/Data Store Read13'
      //   Gain: '<S125>/Gain'
      //   Gain: '<S125>/Gain3'
      //   Merge: '<S3>/Merge'
      //   Sum: '<S125>/Subtract5'
      //   Sum: '<S125>/Sum'
      //   UnitDelay: '<S164>/UD'
      //
      //  Block description for '<S164>/UD':
      //
      //   Store in Global RAM

      Fullexp_B.Merge[0] = ((Fullexp_DW.RED_Measured_States[0] - RED_Path[0]) *
                            Fullexp_P.Kp_xr + Fullexp_P.Kd_xr *
                            Fullexp_DW.UD_DSTATE_eg) * Fullexp_P.Gain6_Gain;

      // Gain: '<S125>/Gain7' incorporates:
      //   DataStoreRead: '<S125>/Data Store Read1'
      //   DataStoreRead: '<S125>/Data Store Read13'
      //   Gain: '<S125>/Gain1'
      //   Gain: '<S125>/Gain4'
      //   Merge: '<S3>/Merge'
      //   Sum: '<S125>/Subtract4'
      //   Sum: '<S125>/Sum1'
      //   UnitDelay: '<S165>/UD'
      //
      //  Block description for '<S165>/UD':
      //
      //   Store in Global RAM

      Fullexp_B.Merge[1] = ((Fullexp_DW.RED_Measured_States[1] - RED_Path[1]) *
                            Fullexp_P.Kp_yr + Fullexp_P.Kd_yr *
                            Fullexp_DW.UD_DSTATE_cd) * Fullexp_P.Gain7_Gain;

      // Gain: '<S125>/Gain8' incorporates:
      //   Gain: '<S125>/Gain2'
      //   Gain: '<S125>/Gain5'
      //   Merge: '<S3>/Merge'
      //   Sum: '<S125>/Sum2'
      //   UnitDelay: '<S166>/UD'
      //
      //  Block description for '<S166>/UD':
      //
      //   Store in Global RAM

      Fullexp_B.Merge[2] = (Fullexp_P.Kp_tr * rtb_TSamp_k + Fullexp_P.Kd_tr *
                            Fullexp_DW.UD_DSTATE_hd) * Fullexp_P.Gain8_Gain;

      // Update for UnitDelay: '<S164>/UD'
      //
      //  Block description for '<S164>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_eg = rtb_TSamp_af;

      // Update for UnitDelay: '<S165>/UD'
      //
      //  Block description for '<S165>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_cd = rtb_TSamp_o;

      // Update for UnitDelay: '<S166>/UD'
      //
      //  Block description for '<S166>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_hd = rtb_TSamp_n5;

      // End of Outputs for SubSystem: '<S3>/Default PD Control (RED)'
    } else if (Fullexp_DW.RED_Control_Law_Enabler == 2.0) {
      // Outputs for IfAction SubSystem: '<S3>/Default LQR Control (RED)' incorporates:
      //   ActionPort: '<S121>/Action Port'

      // Product: '<S121>/Matrix Multiply' incorporates:
      //   DataStoreRead: '<S121>/Data Store Read1'
      //   DataStoreRead: '<S121>/Data Store Read13'
      //   MATLAB Function: '<S140>/MATLAB Function'

      Fullexp_MATLABFunction_n(RED_Path[2], Fullexp_DW.RED_Measured_States[2],
        &tmp_1[2]);

      // SampleTimeMath: '<S141>/TSamp' incorporates:
      //   DataStoreRead: '<S121>/Data Store Read1'
      //
      //  About '<S141>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_k = RED_Path[0] * Fullexp_P.TSamp_WtEt_h;

      // Sum: '<S141>/Diff' incorporates:
      //   UnitDelay: '<S141>/UD'
      //
      //  Block description for '<S141>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S141>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_aq = rtb_TSamp_k - Fullexp_DW.UD_DSTATE_aq;

      // SampleTimeMath: '<S142>/TSamp' incorporates:
      //   DataStoreRead: '<S121>/Data Store Read1'
      //
      //  About '<S142>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_af = RED_Path[1] * Fullexp_P.TSamp_WtEt_e;

      // Sum: '<S142>/Diff' incorporates:
      //   UnitDelay: '<S142>/UD'
      //
      //  Block description for '<S142>/Diff':
      //
      //   Add in CPU
      //
      //  Block description for '<S142>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_p = rtb_TSamp_af - Fullexp_DW.UD_DSTATE_p;

      // SampleTimeMath: '<S143>/TSamp' incorporates:
      //   DataStoreRead: '<S121>/Data Store Read1'
      //
      //  About '<S143>/TSamp':
      //   y = u * K where K = 1 / ( w * Ts )
      //
      rtb_TSamp_o = RED_Path[2] * Fullexp_P.TSamp_WtEt_n;

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

      Fullexp_DW.UD_DSTATE_pr = rtb_TSamp_o - Fullexp_DW.UD_DSTATE_pr;

      // Sum: '<S121>/Subtract7' incorporates:
      //   DataStoreRead: '<S121>/Data Store Read13'
      //   UnitDelay: '<S141>/UD'
      //
      //  Block description for '<S141>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_aq = Fullexp_DW.RED_Measured_States[3] -
        Fullexp_DW.UD_DSTATE_aq;

      // Sum: '<S121>/Subtract6' incorporates:
      //   DataStoreRead: '<S121>/Data Store Read13'
      //   UnitDelay: '<S142>/UD'
      //
      //  Block description for '<S142>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_p = Fullexp_DW.RED_Measured_States[4] -
        Fullexp_DW.UD_DSTATE_p;

      // Sum: '<S121>/Subtract8' incorporates:
      //   DataStoreRead: '<S121>/Data Store Read13'
      //   UnitDelay: '<S143>/UD'
      //
      //  Block description for '<S143>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_pr = Fullexp_DW.RED_Measured_States[5] -
        Fullexp_DW.UD_DSTATE_pr;
      for (d_j = 0; d_j < 18; d_j++) {
        // Product: '<S121>/Matrix Multiply' incorporates:
        //   Constant: '<S121>/Constant2'

        tmp_0[d_j] = -Fullexp_P.K_RED[d_j];
      }

      // Product: '<S121>/Matrix Multiply' incorporates:
      //   DataStoreRead: '<S121>/Data Store Read1'
      //   DataStoreRead: '<S121>/Data Store Read13'
      //   Reshape: '<S121>/Reshape2'
      //   Reshape: '<S121>/Reshape3'
      //   Sum: '<S121>/Subtract4'
      //   Sum: '<S121>/Subtract5'
      //   UnitDelay: '<S141>/UD'
      //   UnitDelay: '<S142>/UD'
      //   UnitDelay: '<S143>/UD'
      //
      //  Block description for '<S141>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S142>/UD':
      //
      //   Store in Global RAM
      //
      //  Block description for '<S143>/UD':
      //
      //   Store in Global RAM

      tmp_1[0] = Fullexp_DW.RED_Measured_States[0] - RED_Path[0];
      tmp_1[1] = Fullexp_DW.RED_Measured_States[1] - RED_Path[1];
      tmp_1[3] = Fullexp_DW.UD_DSTATE_aq;
      tmp_1[4] = Fullexp_DW.UD_DSTATE_p;
      tmp_1[5] = Fullexp_DW.UD_DSTATE_pr;
      for (d_j = 0; d_j < 3; d_j++) {
        // Product: '<S121>/Matrix Multiply' incorporates:
        //   Merge: '<S3>/Merge'

        rtb_TSamp_n5 = 0.0;
        for (i = 0; i < 6; i++) {
          // Merge: '<S3>/Merge' incorporates:
          //   Product: '<S121>/Matrix Multiply'
          //   Reshape: '<S121>/Reshape4'

          rtb_TSamp_n5 += tmp_0[3 * i + d_j] * tmp_1[i];
        }

        // Merge: '<S3>/Merge' incorporates:
        //   Product: '<S121>/Matrix Multiply'

        Fullexp_B.Merge[d_j] = rtb_TSamp_n5;
      }

      // Update for UnitDelay: '<S141>/UD'
      //
      //  Block description for '<S141>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_aq = rtb_TSamp_k;

      // Update for UnitDelay: '<S142>/UD'
      //
      //  Block description for '<S142>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_p = rtb_TSamp_af;

      // Update for UnitDelay: '<S143>/UD'
      //
      //  Block description for '<S143>/UD':
      //
      //   Store in Global RAM

      Fullexp_DW.UD_DSTATE_pr = rtb_TSamp_o;

      // End of Outputs for SubSystem: '<S3>/Default LQR Control (RED)'
    } else if (Fullexp_DW.RED_Control_Law_Enabler == 3.0) {
      // Outputs for IfAction SubSystem: '<S3>/Custom Control (RED)' incorporates:
      //   ActionPort: '<S118>/Action Port'

      Fullexp_CustomControlRED(Fullexp_B.Merge, &Fullexp_P.CustomControlRED);

      // End of Outputs for SubSystem: '<S3>/Custom Control (RED)'
    } else {
      // Outputs for IfAction SubSystem: '<S3>/Disable Thrusters (RED)' incorporates:
      //   ActionPort: '<S129>/Action Port'

      Fullexp_CustomControlRED(Fullexp_B.Merge, &Fullexp_P.DisableThrustersRED);

      // End of Outputs for SubSystem: '<S3>/Disable Thrusters (RED)'
    }

    // End of If: '<S3>/If'

    // DataStoreWrite: '<S3>/RED Controls'
    rtb_w[0] = Fullexp_B.Merge[0];
    rtb_w[1] = Fullexp_B.Merge[1];
    rtb_w[2] = Fullexp_B.Merge[2];

    // MATLAB Function: '<S5>/MATLAB Function1' incorporates:
    //   DataStoreRead: '<S5>/Data Store Read1'
    //   DataStoreRead: '<S5>/Data Store Read2'
    //   DataStoreWrite: '<S5>/Data Store Write18'
    //   Delay: '<S5>/Delay'
    //   Delay: '<S5>/Delay1'
    //   MATLAB Function: '<S22>/MATLAB Function1'

    Fullexp_tic(&savedTime);
    memcpy(&z_meas[0], &rtb_dq_e[0], sizeof(real_T) << 3U);
    n2_tmp_0 = dt * -Fullexp_DW.Delay1_DSTATE[8];
    n2 = n2_tmp_0 / 4.0;
    qr[1] = n2;
    dq_corr_dual[1] = 0.0 - n2;
    n2_tmp_1 = dt * -Fullexp_DW.Delay1_DSTATE[9];
    n2 = n2_tmp_1 / 4.0;
    qr[2] = n2;
    dq_corr_dual[2] = 0.0 - n2;
    n2_tmp = dt * -Fullexp_DW.Delay1_DSTATE[10];
    n2 = n2_tmp / 4.0;
    q_mag = sqrt(((dq_corr_dual[1] * dq_corr_dual[1] + 1.0) + dq_corr_dual[2] *
                  dq_corr_dual[2]) + (0.0 - n2) * (0.0 - n2));
    q_mag *= q_mag;
    q_minus_inv[0] = 1.0 / q_mag;
    q_minus_inv[1] = -dq_corr_dual[1] / q_mag;
    q_minus_inv[2] = -dq_corr_dual[2] / q_mag;
    q_minus_inv[3] = -(0.0 - n2) / q_mag;
    vector[0] = qr[1];
    vector[1] = qr[2];
    vector[2] = n2;
    b_vector[0] = q_minus_inv[1];
    b_vector[1] = q_minus_inv[2];
    b_vector[2] = q_minus_inv[3];
    for (d_j = 0; d_j < 9; d_j++) {
      // MATLAB Function: '<S16>/MATLAB Function1' incorporates:
      //   MATLAB Function: '<S17>/MATLAB Function1'
      //   MATLAB Function: '<S23>/MATLAB Function1'

      dq_corr_dual_tmp[d_j] = b_b[d_j];
    }

    yaw_quant = q_minus_inv[0];
    dt_0[0] = 0.0;
    dt_0[3] = -q_minus_inv[3];
    dt_0[6] = q_minus_inv[2];
    dt_0[1] = q_minus_inv[3];
    dt_0[4] = 0.0;
    dt_0[7] = -q_minus_inv[1];
    dt_0[2] = -q_minus_inv[2];
    dt_0[5] = q_minus_inv[1];
    dt_0[8] = 0.0;
    T[0] = q_minus_inv[0];
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = b_vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * yaw_quant +
        dt_0[3 * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
      dq_corr_dual[d_j + 1] = -Fullexp_DW.Delay1_DSTATE[d_j + 11] * dt / 4.0;
    }

    q_mag = dq_corr_dual[1];
    yaw_quant = dq_corr_dual[2];
    theta = dq_corr_dual[3];
    for (d_j = 0; d_j < 4; d_j++) {
      dq_corr_dual[d_j] = ((T[d_j + 4] * q_mag + T[d_j] * 0.0) + T[d_j + 8] *
                           yaw_quant) + T[d_j + 12] * theta;
    }

    b_vector[0] = dq_corr_dual[1];
    b_vector[1] = dq_corr_dual[2];
    b_vector[2] = dq_corr_dual[3];
    rtb_v_0[0] = 0.0;
    rtb_v_0[1] = -n2;
    rtb_v_0[2] = qr[2];
    vector_0[0] = n2;
    vector_0[1] = 0.0;
    vector_0[2] = -qr[1];
    vector_1[0] = -qr[2];
    vector_1[1] = qr[1];
    vector_1[2] = 0.0;
    T[0] = 1.0;
    rtb_TSamp_k = dq_corr_dual[0];
    dt_0[0] = 0.0;
    dt_0[3] = -dq_corr_dual[3];
    dt_0[6] = dq_corr_dual[2];
    dt_0[1] = dq_corr_dual[3];
    dt_0[4] = 0.0;
    dt_0[7] = -dq_corr_dual[1];
    dt_0[2] = -dq_corr_dual[2];
    dt_0[5] = dq_corr_dual[1];
    dt_0[8] = 0.0;
    dq_corr_dual_0[0] = dq_corr_dual[0];
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(b_b[3 * d_j]) + rtb_v_0[d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(b_b[q_minus_inv_tmp]) + vector_0[d_j];
      Phi_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(b_b[Phi_tmp]) + vector_1[d_j];
      n2 = b_vector[d_j];
      dq_corr_dual_0[i] = -n2;
      dq_corr_dual_0[d_j + 1] = n2;
      dq_corr_dual_0[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) *
        rtb_TSamp_k + dt_0[3 * d_j];
      dq_corr_dual_0[i + 2] = static_cast<real_T>
        (dq_corr_dual_tmp[q_minus_inv_tmp]) * rtb_TSamp_k + dt_0[q_minus_inv_tmp];
      dq_corr_dual_0[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[Phi_tmp]) *
        rtb_TSamp_k + dt_0[Phi_tmp];
    }

    yaw_quant = q_minus_inv[1];
    n2 = q_minus_inv[0];
    q_mag = q_minus_inv[2];
    theta = q_minus_inv[3];
    for (d_j = 0; d_j < 4; d_j++) {
      q_minus_inv_0[d_j] = Fullexp_DW.Delay1_DSTATE[d_j];
      q_minus_inv_0[d_j + 4] = Fullexp_DW.Delay1_DSTATE[d_j + 4];
      tmp_2[d_j] = ((T[d_j + 4] * yaw_quant + T[d_j] * n2) + T[d_j + 8] * q_mag)
        + T[d_j + 12] * theta;
      tmp_2[d_j + 4] = (((dq_corr_dual_0[d_j + 4] * yaw_quant +
                          dq_corr_dual_0[d_j] * n2) + dq_corr_dual_0[d_j + 8] *
                         q_mag) + dq_corr_dual_0[d_j + 12] * theta) * 2.0;
    }

    Fullexp_dqMultiply(q_minus_inv_0, tmp_2, q_pred);
    memcpy(&STDQMEKFx[0], &Fullexp_DW.Delay1_DSTATE[0], 14U * sizeof(real_T));
    STDQMEKFx[0] = q_pred[0];
    STDQMEKFx[4] = q_pred[4];
    STDQMEKFx[1] = q_pred[1];
    STDQMEKFx[5] = q_pred[5];
    STDQMEKFx[2] = q_pred[2];
    STDQMEKFx[6] = q_pred[6];
    STDQMEKFx[3] = q_pred[3];
    STDQMEKFx[7] = q_pred[7];
    memset(&P_k[0], 0, 144U * sizeof(real_T));
    for (i = 0; i < 12; i++) {
      P_k[i + 12 * i] = 1.0;
    }

    for (d_j = 0; d_j < 9; d_j++) {
      T_0[d_j] = dt * f[d_j];
    }

    dt_0[0] = dt * 0.0;
    dt_0[3] = n2_tmp;
    yaw_quant = dt * Fullexp_DW.Delay1_DSTATE[9];
    dt_0[6] = yaw_quant;
    theta = dt * Fullexp_DW.Delay1_DSTATE[10];
    dt_0[1] = theta;
    dt_0[4] = dt * 0.0;
    dt_0[7] = n2_tmp_0;
    dt_0[2] = n2_tmp_1;
    dt_tmp = dt * Fullexp_DW.Delay1_DSTATE[8];
    dt_0[5] = dt_tmp;
    dt_0[8] = dt * 0.0;
    Rot_error[0] = dt * 0.0;
    Rot_error[3] = dt * -Fullexp_DW.Delay1_DSTATE[13];
    Rot_error[6] = dt * Fullexp_DW.Delay1_DSTATE[12];
    Rot_error[1] = dt * Fullexp_DW.Delay1_DSTATE[13];
    Rot_error[4] = dt * 0.0;
    Rot_error[7] = dt * -Fullexp_DW.Delay1_DSTATE[11];
    Rot_error[2] = dt * -Fullexp_DW.Delay1_DSTATE[12];
    Rot_error[5] = dt * Fullexp_DW.Delay1_DSTATE[11];
    Rot_error[8] = dt * 0.0;
    dt_1[0] = dt * 0.0;
    dt_1[3] = n2_tmp;
    dt_1[6] = yaw_quant;
    dt_1[1] = theta;
    dt_1[4] = dt * 0.0;
    dt_1[7] = n2_tmp_0;
    dt_1[2] = n2_tmp_1;
    dt_1[5] = dt_tmp;
    dt_1[8] = dt * 0.0;
    for (d_j = 0; d_j < 3; d_j++) {
      Phi[12 * d_j] = P_k[12 * d_j] + dt_0[3 * d_j];
      i = (d_j + 3) * 12;
      Phi[i] = dt * 0.0 + P_k[i];
      n2 = T_0[3 * d_j];
      q_minus_inv_tmp = (d_j + 6) * 12;
      Phi[q_minus_inv_tmp] = P_k[q_minus_inv_tmp] + n2;
      Phi_tmp = (d_j + 9) * 12;
      Phi[Phi_tmp] = dt * 0.0 + P_k[Phi_tmp];
      jA = 12 * d_j + 3;
      Phi[jA] = Rot_error[3 * d_j] + P_k[jA];
      Phi[i + 3] = P_k[i + 3] + dt_1[3 * d_j];
      Phi[q_minus_inv_tmp + 3] = P_k[q_minus_inv_tmp + 3] + dt * 0.0;
      Phi[Phi_tmp + 3] = P_k[Phi_tmp + 3] + n2;
      jA = 12 * d_j + 1;
      jAcol = 3 * d_j + 1;
      Phi[jA] = P_k[jA] + dt_0[jAcol];
      Phi[i + 1] = P_k[i + 1] + dt * 0.0;
      n2 = T_0[jAcol];
      Phi[q_minus_inv_tmp + 1] = P_k[q_minus_inv_tmp + 1] + n2;
      Phi[Phi_tmp + 1] = P_k[Phi_tmp + 1] + dt * 0.0;
      jA = 12 * d_j + 4;
      Phi[jA] = P_k[jA] + Rot_error[jAcol];
      Phi[i + 4] = P_k[i + 4] + dt_1[jAcol];
      Phi[q_minus_inv_tmp + 4] = P_k[q_minus_inv_tmp + 4] + dt * 0.0;
      Phi[Phi_tmp + 4] = P_k[Phi_tmp + 4] + n2;
      jA = 12 * d_j + 2;
      jAcol = 3 * d_j + 2;
      Phi[jA] = P_k[jA] + dt_0[jAcol];
      Phi[i + 2] = P_k[i + 2] + dt * 0.0;
      n2 = T_0[jAcol];
      Phi[q_minus_inv_tmp + 2] = P_k[q_minus_inv_tmp + 2] + n2;
      Phi[Phi_tmp + 2] = P_k[Phi_tmp + 2] + dt * 0.0;
      jA = 12 * d_j + 5;
      Phi[jA] = P_k[jA] + Rot_error[jAcol];
      Phi[i + 5] = P_k[i + 5] + dt_1[jAcol];
      Phi[q_minus_inv_tmp + 5] = P_k[q_minus_inv_tmp + 5] + dt * 0.0;
      Phi[Phi_tmp + 5] = P_k[Phi_tmp + 5] + n2;
    }

    for (d_j = 0; d_j < 12; d_j++) {
      i = 12 * d_j + 6;
      Phi[i] = dt * 0.0 + P_k[i];
      i = 12 * d_j + 9;
      Phi[i] = dt * 0.0 + P_k[i];
      i = 12 * d_j + 7;
      Phi[i] = dt * 0.0 + P_k[i];
      i = 12 * d_j + 10;
      Phi[i] = dt * 0.0 + P_k[i];
      i = 12 * d_j + 8;
      Phi[i] = dt * 0.0 + P_k[i];
      i = 12 * d_j + 11;
      Phi[i] = dt * 0.0 + P_k[i];
    }

    for (d_j = 0; d_j < 12; d_j++) {
      for (i = 0; i < 12; i++) {
        n2 = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          n2 += Phi[12 * q_minus_inv_tmp + d_j] * Fullexp_DW.Delay_DSTATE_d[12 *
            i + q_minus_inv_tmp];
        }

        Phi_0[d_j + 12 * i] = n2;
      }

      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += Phi_0[12 * q_minus_inv_tmp + d_j] * Phi[12 * q_minus_inv_tmp
            + i];
        }

        q_minus_inv_tmp = 12 * i + d_j;
        P_k[q_minus_inv_tmp] = Q[q_minus_inv_tmp] + q_mag;
      }
    }

    rEQ0 = false;
    for (i = 0; i < 8; i++) {
      if (!rEQ0) {
        rEQ0 = rtIsNaN(rtb_dq_e[i]);
      }
    }

    if (!rEQ0) {
      Fullexp_rand();
      q_pred[0] = 0.99968751627570263;
      q_pred[1] = 0.0;
      q_pred[2] = 0.0;
      q_pred[3] = -0.024997395914712332;
      q_pred[4] = -0.0;
      q_pred[5] = 0.0;
      q_pred[6] = 0.0;
      q_pred[7] = 0.0;
      Fullexp_dqMultiply(q_pred, rtb_dq_e, z_meas);
    }

    n2 = ((STDQMEKFx[0] * STDQMEKFx[0] + STDQMEKFx[1] * STDQMEKFx[1]) +
          STDQMEKFx[2] * STDQMEKFx[2]) + STDQMEKFx[3] * STDQMEKFx[3];
    q_minus_inv[0] = STDQMEKFx[0] / n2;
    q_minus_inv[1] = -STDQMEKFx[1] / n2;
    q_minus_inv[2] = -STDQMEKFx[2] / n2;
    q_minus_inv[3] = -STDQMEKFx[3] / n2;
    vector[0] = q_minus_inv[1];
    vector[1] = q_minus_inv[2];
    vector[2] = q_minus_inv[3];
    yaw_quant = q_minus_inv[0];
    dt_0[0] = 0.0;
    dt_0[3] = -q_minus_inv[3];
    dt_0[6] = q_minus_inv[2];
    dt_0[1] = q_minus_inv[3];
    dt_0[4] = 0.0;
    dt_0[7] = -q_minus_inv[1];
    dt_0[2] = -q_minus_inv[2];
    dt_0[5] = q_minus_inv[1];
    dt_0[8] = 0.0;
    T[0] = q_minus_inv[0];
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * yaw_quant +
        dt_0[3 * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
    }

    n2 = STDQMEKFx[5];
    q_mag = STDQMEKFx[4];
    yaw_quant = STDQMEKFx[6];
    theta = STDQMEKFx[7];
    for (d_j = 0; d_j < 4; d_j++) {
      qr[d_j] = ((T[d_j + 4] * n2 + T[d_j] * q_mag) + T[d_j + 8] * yaw_quant) +
        T[d_j + 12] * theta;
    }

    vector[0] = qr[1];
    vector[1] = qr[2];
    vector[2] = qr[3];
    yaw_quant = qr[0];
    dt_0[0] = 0.0;
    dt_0[3] = -qr[3];
    dt_0[6] = qr[2];
    dt_0[1] = qr[3];
    dt_0[4] = 0.0;
    dt_0[7] = -qr[1];
    dt_0[2] = -qr[2];
    dt_0[5] = qr[1];
    dt_0[8] = 0.0;
    T[0] = qr[0];
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * yaw_quant +
        dt_0[3 * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
    }

    for (d_j = 0; d_j < 4; d_j++) {
      q_minus_inv_0[d_j] = q_minus_inv[d_j];
      q_minus_inv_0[d_j + 4] = -(((T[d_j + 4] * q_minus_inv[1] + T[d_j] *
        q_minus_inv[0]) + T[d_j + 8] * q_minus_inv[2]) + T[d_j + 12] *
        q_minus_inv[3]);
    }

    Fullexp_dqMultiply(Red_dq, z_meas, tmp_2);
    Fullexp_dqMultiply(q_minus_inv_0, tmp_2, q_pred);
    vector[0] = q_pred[5];
    vector[1] = q_pred[6];
    vector[2] = q_pred[7];
    n2 = 2.0 * acos(q_pred[0]);
    q_mag = sin(n2 / 2.0);
    q_minus_inv[0] = q_pred[1] / q_mag;
    q_minus_inv[1] = q_pred[2] / q_mag;
    q_minus_inv[2] = q_pred[3] / q_mag;
    rEQ0 = rtIsNaN(q_minus_inv[0]);
    if (!rEQ0) {
      rEQ0 = rtIsNaN(q_minus_inv[1]);
    }

    if (!rEQ0) {
      rEQ0 = rtIsNaN(q_minus_inv[2]);
    }

    if (!rEQ0) {
      rEQ0 = rtIsNaN(n2);
    }

    if (rEQ0) {
      q_minus_inv[0] = 1.0;
      q_minus_inv[1] = 0.0;
      q_minus_inv[2] = 0.0;
      q_minus_inv[3] = 0.0;
    } else {
      if (rtIsNaN(n2 + 3.1415926535897931)) {
        rtb_TSamp_k = (rtNaN);
      } else if (rtIsInf(n2 + 3.1415926535897931)) {
        rtb_TSamp_k = (rtNaN);
      } else if (n2 + 3.1415926535897931 == 0.0) {
        rtb_TSamp_k = 0.0;
      } else {
        rtb_TSamp_k = fmod(n2 + 3.1415926535897931, 6.2831853071795862);
        rEQ0 = (rtb_TSamp_k == 0.0);
        if (!rEQ0) {
          rtb_TSamp_af = fabs((n2 + 3.1415926535897931) / 6.2831853071795862);
          rEQ0 = !(fabs(rtb_TSamp_af - floor(rtb_TSamp_af + 0.5)) >
                   2.2204460492503131E-16 * rtb_TSamp_af);
        }

        if (rEQ0) {
          rtb_TSamp_k = 0.0;
        } else if (rtb_TSamp_k < 0.0) {
          rtb_TSamp_k += 6.2831853071795862;
        }
      }

      b_vector[0] = q_minus_inv[0];
      b_vector[1] = q_minus_inv[1];
      b_vector[2] = q_minus_inv[2];
      q_mag = Fullexp_norm(b_vector);
      b_vector[0] = q_minus_inv[0] / q_mag;
      b_vector[1] = q_minus_inv[1] / q_mag;
      b_vector[2] = q_minus_inv[2] / q_mag;
      rtb_TSamp_k = (rtb_TSamp_k - 3.1415926535897931) / 2.0;
      q_mag = sin(rtb_TSamp_k);
      q_minus_inv[0] = cos(rtb_TSamp_k);
      q_minus_inv[1] = b_vector[0] * q_mag;
      q_minus_inv[2] = b_vector[1] * q_mag;
      q_minus_inv[3] = b_vector[2] * q_mag;
    }

    n2 = q_pred[4];
    dt_0[0] = 0.0;
    dt_0[3] = -q_pred[7];
    dt_0[6] = q_pred[6];
    dt_0[1] = q_pred[7];
    dt_0[4] = 0.0;
    dt_0[7] = -q_pred[5];
    dt_0[2] = -q_pred[6];
    dt_0[5] = q_pred[5];
    dt_0[8] = 0.0;
    T[0] = q_pred[4];
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * n2 + dt_0[3 *
        d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) * n2 +
        dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) * n2 +
        dt_0[q_minus_inv_tmp];
    }

    n2 = q_pred[0];
    q_mag = -q_pred[1];
    yaw_quant = -q_pred[2];
    theta = -q_pred[3];
    for (d_j = 0; d_j < 4; d_j++) {
      qr[d_j] = ((T[d_j + 4] * q_mag + T[d_j] * n2) + T[d_j + 8] * yaw_quant) +
        T[d_j + 12] * theta;
    }

    vector[0] = 2.0 * qr[1] * 0.5;
    vector[1] = 2.0 * qr[2] * 0.5;
    vector[2] = 2.0 * qr[3] * 0.5;
    T[0] = 0.0;
    T[4] = -vector[0];
    T[1] = vector[0];
    T[5] = 0.0;
    T[6] = vector[2];
    T[7] = -vector[1];
    T[8] = -vector[1];
    T[2] = vector[1];
    T[9] = -vector[2];
    T[10] = 0.0;
    T[11] = vector[0];
    T[12] = -vector[2];
    T[3] = vector[2];
    T[13] = vector[1];
    T[14] = -vector[0];
    T[15] = 0.0;
    for (d_j = 0; d_j < 4; d_j++) {
      q_pred[d_j] = q_minus_inv[d_j];
      q_pred[d_j + 4] = ((T[d_j + 4] * q_minus_inv[1] + T[d_j] * q_minus_inv[0])
                         + T[d_j + 8] * q_minus_inv[2]) + T[d_j + 12] *
        q_minus_inv[3];
    }

    y[0] = q_pred[1];
    y[3] = q_pred[5];
    y[1] = q_pred[2];
    y[4] = q_pred[6];
    y[2] = q_pred[3];
    y[5] = q_pred[7];
    tmp_5 = &c[0];
    tmp_6 = &a[0];
    for (d_j = 0; d_j < 6; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += static_cast<real_T>((&a[0])[6 * q_minus_inv_tmp + d_j]) *
            P_k[12 * i + q_minus_inv_tmp];
        }

        H[d_j + 6 * i] = q_mag;
      }

      for (i = 0; i < 6; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += H[6 * q_minus_inv_tmp + d_j] * static_cast<real_T>((&c[0])[12
            * i + q_minus_inv_tmp]);
        }

        H_0[d_j + 6 * i] = q_mag;
      }
    }

    yaw_quant = 0.0;
    for (d_j = 0; d_j < 3; d_j++) {
      yaw_quant += ((H_0[6 * d_j + 1] * y[1] + H_0[6 * d_j] * y[0]) + H_0[6 *
                    d_j + 2] * y[2]) * y[d_j];
    }

    if (!(sqrt(yaw_quant) < 0.1)) {
      memcpy(&Fullexp_B.x_est_c[0], &STDQMEKFx[0], 14U * sizeof(real_T));
      memcpy(&Fullexp_DW.DQMEKFP[0], &P_k[0], 144U * sizeof(real_T));
    } else {
      for (d_j = 0; d_j < 6; d_j++) {
        for (i = 0; i < 12; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += P_k[12 * q_minus_inv_tmp + i] * static_cast<real_T>((&c[0])
              [12 * d_j + q_minus_inv_tmp]);
          }

          K[i + 12 * d_j] = q_mag;
        }

        for (i = 0; i < 6; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += H[6 * q_minus_inv_tmp + d_j] * static_cast<real_T>((&c[0])
              [12 * i + q_minus_inv_tmp]);
          }

          q_minus_inv_tmp = 6 * i + d_j;
          H_0[q_minus_inv_tmp] = R[q_minus_inv_tmp] + q_mag;
        }
      }

      Fullexp_mrdiv_h(K, H_0);
      for (d_j = 0; d_j < 12; d_j++) {
        for (i = 0; i < 12; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
            q_mag += K[12 * q_minus_inv_tmp + i] * static_cast<real_T>((&a[0])[6
              * d_j + q_minus_inv_tmp]);
          }

          DQMEKFP_tmp[i + 12 * d_j] = q_mag;
        }
      }

      for (d_j = 0; d_j < 144; d_j++) {
        Phi[d_j] = static_cast<real_T>((&b[0])[d_j]) - DQMEKFP_tmp[d_j];
      }

      for (d_j = 0; d_j < 12; d_j++) {
        for (i = 0; i < 12; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += Phi[12 * q_minus_inv_tmp + d_j] * P_k[12 * i +
              q_minus_inv_tmp];
          }

          Phi_tmp = 12 * i + d_j;
          Phi_0[Phi_tmp] = q_mag;
          DQMEKFP_tmp_0[i + 12 * d_j] = static_cast<real_T>((&b[0])[Phi_tmp]) -
            DQMEKFP_tmp[Phi_tmp];
        }

        for (i = 0; i < 6; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
            q_mag += K[12 * q_minus_inv_tmp + d_j] * R[6 * i + q_minus_inv_tmp];
          }

          H[d_j + 12 * i] = q_mag;
        }
      }

      for (d_j = 0; d_j < 12; d_j++) {
        for (i = 0; i < 12; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += Phi_0[12 * q_minus_inv_tmp + d_j] * DQMEKFP_tmp_0[12 * i +
              q_minus_inv_tmp];
          }

          Phi_tmp = 12 * i + d_j;
          DQMEKFP_tmp[Phi_tmp] = q_mag;
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
            q_mag += H[12 * q_minus_inv_tmp + d_j] * K[12 * q_minus_inv_tmp + i];
          }

          P_k[Phi_tmp] = q_mag;
        }
      }

      for (d_j = 0; d_j < 144; d_j++) {
        Fullexp_DW.DQMEKFP[d_j] = DQMEKFP_tmp[d_j] + P_k[d_j];
      }

      for (d_j = 0; d_j < 12; d_j++) {
        q_mag = 0.0;
        for (i = 0; i < 6; i++) {
          q_mag += K[12 * i + d_j] * y[i];
        }

        rtb_x_k[d_j] = q_mag;
      }

      rtb_v_0[0] = rtb_x_k[0];
      rtb_v_0[1] = rtb_x_k[1];
      rtb_v_0[2] = rtb_x_k[2];
      n2 = Fullexp_norm(rtb_v_0);
      if (n2 <= 1.0) {
        n2 = sqrt(1.0 - n2 * n2);
        q_minus_inv[0] = n2;
        q_minus_inv[1] = rtb_x_k[0];
        dq_corr_dual[1] = rtb_x_k[3];
        q_minus_inv[2] = rtb_x_k[1];
        dq_corr_dual[2] = rtb_x_k[4];
        q_minus_inv[3] = rtb_x_k[2];
        dq_corr_dual[3] = rtb_x_k[5];
        dq_corr_dual[0] = -((rtb_x_k[0] * rtb_x_k[3] + rtb_x_k[1] * rtb_x_k[4])
                            + rtb_x_k[2] * rtb_x_k[5]) / n2;
      } else {
        q_mag = sqrt(n2 * n2 + 1.0);
        n2 = 1.0 / q_mag;
        q_minus_inv[0] = n2;
        q_minus_inv[1] = rtb_x_k[0] * n2;
        dq_corr_dual[1] = rtb_x_k[3];
        q_minus_inv[2] = rtb_x_k[1] * n2;
        dq_corr_dual[2] = rtb_x_k[4];
        q_minus_inv[3] = rtb_x_k[2] * n2;
        dq_corr_dual[3] = rtb_x_k[5];
        dq_corr_dual[0] = -((rtb_x_k[0] * rtb_x_k[3] + rtb_x_k[1] * rtb_x_k[4])
                            + rtb_x_k[2] * rtb_x_k[5]) * q_mag;
      }

      z_meas[0] = STDQMEKFx[0];
      z_meas[4] = STDQMEKFx[4];
      q_minus_inv_0[0] = q_minus_inv[0];
      q_minus_inv_0[4] = dq_corr_dual[0];
      z_meas[1] = STDQMEKFx[1];
      z_meas[5] = STDQMEKFx[5];
      q_minus_inv_0[1] = q_minus_inv[1];
      q_minus_inv_0[5] = dq_corr_dual[1];
      z_meas[2] = STDQMEKFx[2];
      z_meas[6] = STDQMEKFx[6];
      q_minus_inv_0[2] = q_minus_inv[2];
      q_minus_inv_0[6] = dq_corr_dual[2];
      z_meas[3] = STDQMEKFx[3];
      z_meas[7] = STDQMEKFx[7];
      q_minus_inv_0[3] = q_minus_inv[3];
      q_minus_inv_0[7] = dq_corr_dual[3];
      Fullexp_dqMultiply(z_meas, q_minus_inv_0, q_pred);
      Fullexp_B.x_est_c[0] = q_pred[0];
      Fullexp_B.x_est_c[4] = q_pred[4];
      Fullexp_B.x_est_c[1] = q_pred[1];
      Fullexp_B.x_est_c[5] = q_pred[5];
      Fullexp_B.x_est_c[2] = q_pred[2];
      Fullexp_B.x_est_c[6] = q_pred[6];
      Fullexp_B.x_est_c[3] = q_pred[3];
      Fullexp_B.x_est_c[7] = q_pred[7];
      Fullexp_B.x_est_c[8] = rtb_x_k[6] + STDQMEKFx[8];
      Fullexp_B.x_est_c[11] = rtb_x_k[9] + STDQMEKFx[11];
      Fullexp_B.x_est_c[9] = rtb_x_k[7] + STDQMEKFx[9];
      Fullexp_B.x_est_c[12] = rtb_x_k[10] + STDQMEKFx[12];
      Fullexp_B.x_est_c[10] = rtb_x_k[8] + STDQMEKFx[10];
      Fullexp_B.x_est_c[13] = rtb_x_k[11] + STDQMEKFx[13];
    }

    rtb_TSamp_k = Fullexp_toc(&savedTime);

    // DataStoreWrite: '<S5>/Data Store Write17'
    memcpy(&DQMEKFx[0], &Fullexp_B.x_est_c[0], 14U * sizeof(real_T));

    // MATLAB Function: '<S16>/MATLAB Function1' incorporates:
    //   DataStoreRead: '<S16>/Data Store Read1'
    //   DataStoreRead: '<S16>/Data Store Read2'
    //   DataStoreRead: '<S16>/Data Store Read3'
    //   DataStoreRead: '<S16>/Data Store Read4'
    //   DataStoreWrite: '<S16>/Data Store Write18'
    //   Delay: '<S16>/Delay'
    //   Delay: '<S16>/Delay1'
    //   MATLAB Function: '<S17>/MATLAB Function1'
    //   MATLAB Function: '<S22>/MATLAB Function1'
    //   MATLAB Function: '<S23>/MATLAB Function1'
    //   MATLAB Function: '<S5>/MATLAB Function1'

    z[0] = rtb_q_f[0];
    z[1] = rtb_q_f[1];
    z[2] = rtb_q_f[2];
    z[3] = rtb_q_f[3];
    z[4] = Fullexp_DW.Vis_x[0];
    z[5] = Fullexp_DW.Vis_x[1];
    z[6] = Fullexp_DW.Vis_x[2];
    Chaser_tmp[0] = Red_q[0];
    Chaser_tmp[1] = Red_q[1];
    Chaser_tmp[2] = Red_q[2];
    Chaser_tmp[3] = Red_q[3];
    Chaser_tmp[4] = Red_x[0];
    Chaser_tmp[5] = Red_x[1];
    Chaser_tmp[6] = Red_x[2];
    Fullexp_tic_k(&savedTime_o);
    memcpy(&STQMEKFx[0], &Fullexp_DW.Delay1_DSTATE_e[0], 13U * sizeof(real_T));
    q_mag = Fullexp_norm(&Fullexp_DW.Delay1_DSTATE_e[4]);
    if (q_mag > 1.0E-10) {
      theta = q_mag * dt / 2.0;
      yaw_quant = sin(theta);
      qr[0] = cos(theta);
      qr[1] = Fullexp_DW.Delay1_DSTATE_e[4] / q_mag * yaw_quant;
      qr[2] = Fullexp_DW.Delay1_DSTATE_e[5] / q_mag * yaw_quant;
      qr[3] = Fullexp_DW.Delay1_DSTATE_e[6] / q_mag * yaw_quant;
    } else {
      qr[0] = 1.0;
      qr[1] = 0.0;
      qr[2] = 0.0;
      qr[3] = 0.0;
    }

    vector[0] = qr[1];
    vector[1] = qr[2];
    vector[2] = qr[3];
    yaw_quant = qr[0];
    dt_0[0] = 0.0;
    dt_0[3] = -qr[3];
    dt_0[6] = qr[2];
    dt_0[1] = qr[3];
    dt_0[4] = 0.0;
    dt_0[7] = -qr[1];
    dt_0[2] = -qr[2];
    dt_0[5] = qr[1];
    dt_0[8] = 0.0;
    T[0] = qr[0];
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * yaw_quant +
        dt_0[3 * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
    }

    rtb_TSamp_af = Fullexp_DW.Delay1_DSTATE_e[1];
    rtb_TSamp_o = Fullexp_DW.Delay1_DSTATE_e[0];
    rtb_TSamp_n5 = Fullexp_DW.Delay1_DSTATE_e[2];
    rtb_Atan2_n = Fullexp_DW.Delay1_DSTATE_e[3];
    for (d_j = 0; d_j < 4; d_j++) {
      x_k[d_j] = ((T[d_j + 4] * rtb_TSamp_af + T[d_j] * rtb_TSamp_o) + T[d_j + 8]
                  * rtb_TSamp_n5) + T[d_j + 12] * rtb_Atan2_n;
    }

    x_k[4] = Fullexp_DW.Delay1_DSTATE_e[4];
    x_k[7] = Fullexp_DW.Delay1_DSTATE_e[10] * dt + Fullexp_DW.Delay1_DSTATE_e[7];
    x_k[10] = Fullexp_DW.Delay1_DSTATE_e[10];
    x_k[5] = Fullexp_DW.Delay1_DSTATE_e[5];
    x_k[8] = Fullexp_DW.Delay1_DSTATE_e[11] * dt + Fullexp_DW.Delay1_DSTATE_e[8];
    x_k[11] = Fullexp_DW.Delay1_DSTATE_e[11];
    x_k[6] = Fullexp_DW.Delay1_DSTATE_e[6];
    x_k[9] = Fullexp_DW.Delay1_DSTATE_e[12] * dt + Fullexp_DW.Delay1_DSTATE_e[9];
    x_k[12] = Fullexp_DW.Delay1_DSTATE_e[12];
    for (d_j = 0; d_j < 9; d_j++) {
      Phi_m_tmp[d_j] = static_cast<real_T>(dq_corr_dual_tmp[d_j]) * dt;
    }

    for (d_j = 0; d_j < 27; d_j++) {
      Phi_m_tmp_0[d_j] = c_0[d_j] * dt;
      Phi_m_tmp_1[d_j] = 0.0 * dt;
    }

    tmp_3[0] = -0.0 * dt;
    tmp_3[9] = Fullexp_DW.Delay1_DSTATE_e[6] / 2.0 * dt;
    tmp_3[18] = -Fullexp_DW.Delay1_DSTATE_e[5] / 2.0 * dt;
    tmp_3[1] = -Fullexp_DW.Delay1_DSTATE_e[6] / 2.0 * dt;
    tmp_3[10] = -0.0 * dt;
    tmp_3[19] = Fullexp_DW.Delay1_DSTATE_e[4] / 2.0 * dt;
    tmp_3[2] = Fullexp_DW.Delay1_DSTATE_e[5] / 2.0 * dt;
    tmp_3[11] = -Fullexp_DW.Delay1_DSTATE_e[4] / 2.0 * dt;
    tmp_3[20] = -0.0 * dt;
    for (d_j = 0; d_j < 3; d_j++) {
      i = (d_j + 3) * 9;
      tmp_3[i] = Phi_m_tmp[3 * d_j];
      q_minus_inv_tmp = (d_j + 6) * 9;
      tmp_3[q_minus_inv_tmp] = 0.0 * dt;
      tmp_3[i + 1] = Phi_m_tmp[3 * d_j + 1];
      tmp_3[q_minus_inv_tmp + 1] = 0.0 * dt;
      tmp_3[i + 2] = Phi_m_tmp[3 * d_j + 2];
      tmp_3[q_minus_inv_tmp + 2] = 0.0 * dt;
    }

    for (d_j = 0; d_j < 9; d_j++) {
      tmp_3[9 * d_j + 3] = Phi_m_tmp_0[3 * d_j];
      tmp_3[9 * d_j + 6] = 0.0 * dt;
      tmp_3[9 * d_j + 4] = Phi_m_tmp_0[3 * d_j + 1];
      tmp_3[9 * d_j + 7] = 0.0 * dt;
      tmp_3[9 * d_j + 5] = Phi_m_tmp_0[3 * d_j + 2];
      tmp_3[9 * d_j + 8] = 0.0 * dt;
    }

    Fullexp_expm(tmp_3, Phi_m);
    for (d_j = 0; d_j < 36; d_j++) {
      F_tmp[d_j] = e[d_j];
      F_tmp_0[d_j] = d[d_j];
    }

    for (d_j = 0; d_j < 6; d_j++) {
      L[12 * d_j] = Phi_m[9 * d_j];
      L[12 * d_j + 1] = Phi_m[9 * d_j + 1];
      L[12 * d_j + 2] = Phi_m[9 * d_j + 2];
    }

    for (d_j = 0; d_j < 3; d_j++) {
      q_minus_inv_tmp = (d_j + 6) * 12;
      L[q_minus_inv_tmp] = 0.0;
      i = (d_j + 9) * 12;
      L[i] = 0.0;
      L[q_minus_inv_tmp + 1] = 0.0;
      L[i + 1] = 0.0;
      L[q_minus_inv_tmp + 2] = 0.0;
      L[i + 2] = 0.0;
    }

    for (d_j = 0; d_j < 12; d_j++) {
      L[12 * d_j + 3] = F_tmp_0[3 * d_j];
      L[12 * d_j + 4] = F_tmp_0[3 * d_j + 1];
      L[12 * d_j + 5] = F_tmp_0[3 * d_j + 2];
    }

    for (d_j = 0; d_j < 3; d_j++) {
      L[12 * d_j + 6] = 0.0;
      q_minus_inv_tmp = (d_j + 3) * 12;
      L[q_minus_inv_tmp + 6] = 0.0;
      i = (d_j + 6) * 12;
      L[i + 6] = dq_corr_dual_tmp[3 * d_j];
      Phi_tmp = (d_j + 9) * 12;
      L[Phi_tmp + 6] = Phi_m_tmp[3 * d_j];
      L[12 * d_j + 7] = 0.0;
      L[q_minus_inv_tmp + 7] = 0.0;
      jA = 3 * d_j + 1;
      L[i + 7] = dq_corr_dual_tmp[jA];
      L[Phi_tmp + 7] = Phi_m_tmp[jA];
      L[12 * d_j + 8] = 0.0;
      L[q_minus_inv_tmp + 8] = 0.0;
      q_minus_inv_tmp = 3 * d_j + 2;
      L[i + 8] = dq_corr_dual_tmp[q_minus_inv_tmp];
      L[Phi_tmp + 8] = Phi_m_tmp[q_minus_inv_tmp];
    }

    for (d_j = 0; d_j < 12; d_j++) {
      L[12 * d_j + 9] = F_tmp[3 * d_j];
      L[12 * d_j + 10] = F_tmp[3 * d_j + 1];
      L[12 * d_j + 11] = F_tmp[3 * d_j + 2];
    }

    for (d_j = 0; d_j < 12; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += L[12 * q_minus_inv_tmp + d_j] * Fullexp_DW.Delay_DSTATE_k[12 *
            i + q_minus_inv_tmp];
        }

        Phi[d_j + 12 * i] = q_mag;
      }

      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += Phi[12 * q_minus_inv_tmp + d_j] * L[12 * q_minus_inv_tmp + i];
        }

        q_minus_inv_tmp = 12 * i + d_j;
        P_k[q_minus_inv_tmp] = Q[q_minus_inv_tmp] + q_mag;
      }
    }

    rtb_TSamp_af = sqrt(((Chaser_tmp[0] * Chaser_tmp[0] + Chaser_tmp[1] *
                          Chaser_tmp[1]) + Chaser_tmp[2] * Chaser_tmp[2]) +
                        Chaser_tmp[3] * Chaser_tmp[3]);
    rtb_TSamp_o = rtb_TSamp_af * rtb_TSamp_af;
    rtb_TSamp_n5 = Chaser_tmp[0] / rtb_TSamp_o;
    rtb_Atan2_n = -Chaser_tmp[1] / rtb_TSamp_o;
    qr_idx_2_tmp = -Chaser_tmp[2] / rtb_TSamp_o;
    qr_idx_3_tmp = -Chaser_tmp[3] / rtb_TSamp_o;
    for (i = 0; i < 7; i++) {
      z_bar[i] = 0.0 * z[i];
    }

    rtb_TSamp_af = sqrt(((rtb_TSamp_n5 * rtb_TSamp_n5 + rtb_Atan2_n *
                          rtb_Atan2_n) + qr_idx_2_tmp * qr_idx_2_tmp) +
                        qr_idx_3_tmp * qr_idx_3_tmp);
    vector[0] = rtb_Atan2_n;
    vector[1] = qr_idx_2_tmp;
    vector[2] = qr_idx_3_tmp;
    dt_0[0] = 0.0;
    dt_0[3] = -qr_idx_3_tmp;
    dt_0[6] = qr_idx_2_tmp;
    dt_0[1] = qr_idx_3_tmp;
    dt_0[4] = 0.0;
    dt_0[7] = -rtb_Atan2_n;
    dt_0[2] = -qr_idx_2_tmp;
    dt_0[5] = rtb_Atan2_n;
    dt_0[8] = 0.0;
    T[0] = rtb_TSamp_n5;
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * rtb_TSamp_n5 +
        dt_0[3 * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        rtb_TSamp_n5 + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        rtb_TSamp_n5 + dt_0[q_minus_inv_tmp];
      dq_corr_dual[d_j + 1] = x_k[d_j + 7] - Chaser_tmp[d_j + 4];
    }

    q_mag = dq_corr_dual[1];
    yaw_quant = dq_corr_dual[2];
    theta = dq_corr_dual[3];
    for (d_j = 0; d_j < 4; d_j++) {
      Red_q[d_j] = ((T[d_j + 4] * q_mag + T[d_j] * 0.0) + T[d_j + 8] * yaw_quant)
        + T[d_j + 12] * theta;
    }

    vector[0] = Red_q[1];
    vector[1] = Red_q[2];
    vector[2] = Red_q[3];
    theta = Red_q[0];
    dt_0[0] = 0.0;
    dt_0[3] = -Red_q[3];
    dt_0[6] = Red_q[2];
    dt_0[1] = Red_q[3];
    dt_0[4] = 0.0;
    dt_0[7] = -Red_q[1];
    dt_0[2] = -Red_q[2];
    dt_0[5] = Red_q[1];
    dt_0[8] = 0.0;
    rtb_TSamp_af *= rtb_TSamp_af;
    dq_corr_dual_0[0] = Red_q[0];
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      dq_corr_dual_0[i] = -q_mag;
      dq_corr_dual_0[d_j + 1] = q_mag;
      dq_corr_dual_0[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) *
        theta + dt_0[3 * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      dq_corr_dual_0[i + 2] = static_cast<real_T>
        (dq_corr_dual_tmp[q_minus_inv_tmp]) * theta + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      dq_corr_dual_0[i + 3] = static_cast<real_T>
        (dq_corr_dual_tmp[q_minus_inv_tmp]) * theta + dt_0[q_minus_inv_tmp];
    }

    rtb_TSamp_o = rtb_TSamp_n5 / rtb_TSamp_af;
    qr_idx_1_tmp = -rtb_Atan2_n / rtb_TSamp_af;
    qr_idx_2_tmp_0 = -qr_idx_2_tmp / rtb_TSamp_af;
    qr_idx_3_tmp_0 = -qr_idx_3_tmp / rtb_TSamp_af;
    for (d_j = 0; d_j < 4; d_j++) {
      Red_q[d_j] = ((dq_corr_dual_0[d_j + 4] * qr_idx_1_tmp + dq_corr_dual_0[d_j]
                     * rtb_TSamp_o) + dq_corr_dual_0[d_j + 8] * qr_idx_2_tmp_0)
        + dq_corr_dual_0[d_j + 12] * qr_idx_3_tmp_0;
    }

    vector[0] = x_k[1];
    vector[1] = x_k[2];
    vector[2] = x_k[3];
    yaw_quant = x_k[0];
    dt_0[0] = 0.0;
    dt_0[3] = -x_k[3];
    dt_0[6] = x_k[2];
    dt_0[1] = x_k[3];
    dt_0[4] = 0.0;
    dt_0[7] = -x_k[1];
    dt_0[2] = -x_k[2];
    dt_0[5] = x_k[1];
    dt_0[8] = 0.0;
    T[0] = x_k[0];
    for (d_j = 0; d_j < 3; d_j++) {
      z_bar[d_j + 4] = Red_q[d_j + 1];
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * yaw_quant +
        dt_0[3 * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
    }

    for (d_j = 0; d_j < 4; d_j++) {
      z_bar[d_j] = ((T[d_j + 4] * rtb_Atan2_n + T[d_j] * rtb_TSamp_n5) + T[d_j +
                    8] * qr_idx_2_tmp) + T[d_j + 12] * qr_idx_3_tmp;
    }

    Fullexp_smallQuat(&z_bar[0], Red_q);
    yaw_quant = rt_roundd_snf(Fullexp_mod(2.0 * rt_atan2d_snf(Red_q[3], Red_q[0]))
      / 0.049087385212340517) * 0.049087385212340517 + Fullexp_rand_m() * 1.0E-5;
    for (d_j = 0; d_j < 36; d_j++) {
      H_tmp[d_j] = f_0[d_j];
    }

    for (d_j = 0; d_j < 12; d_j++) {
      H[6 * d_j] = H_tmp[3 * d_j];
      H[6 * d_j + 1] = H_tmp[3 * d_j + 1];
      H[6 * d_j + 2] = H_tmp[3 * d_j + 2];
    }

    H_tmp_1 = -qr_idx_3_tmp * -qr_idx_3_tmp;
    H_tmp_4 = -qr_idx_2_tmp * -qr_idx_2_tmp;
    H_tmp_5 = 1.0 - (H_tmp_4 + H_tmp_1) * 2.0;
    H[39] = H_tmp_5;
    H_tmp_0 = -rtb_Atan2_n * -qr_idx_2_tmp;
    rtb_TSamp_af = rtb_TSamp_n5 * -qr_idx_3_tmp;
    H_tmp_6 = (H_tmp_0 + rtb_TSamp_af) * 2.0;
    H[45] = H_tmp_6;
    H_tmp_2 = (-rtb_Atan2_n * -qr_idx_3_tmp + rtb_TSamp_n5 * -qr_idx_2_tmp) *
      2.0;
    H[51] = H_tmp_2;
    H_tmp_0 = (H_tmp_0 - rtb_TSamp_af) * 2.0;
    H[40] = H_tmp_0;
    rtb_TSamp_af = -rtb_Atan2_n * -rtb_Atan2_n;
    H_tmp_1 = 1.0 - (rtb_TSamp_af + H_tmp_1) * 2.0;
    H[46] = H_tmp_1;
    H_tmp_3 = -qr_idx_2_tmp * -qr_idx_3_tmp;
    n2 = rtb_TSamp_n5 * -rtb_Atan2_n;
    H_tmp_7 = (H_tmp_3 + n2) * 2.0;
    H[52] = H_tmp_7;
    H[41] = H_tmp_2;
    H_tmp_3 = (H_tmp_3 - n2) * 2.0;
    H[47] = H_tmp_3;
    H_tmp_4 = 1.0 - (rtb_TSamp_af + H_tmp_4) * 2.0;
    H[53] = H_tmp_4;
    for (d_j = 0; d_j < 3; d_j++) {
      H[6 * d_j + 3] = 0.0;
      q_minus_inv_tmp = (d_j + 3) * 6;
      H[q_minus_inv_tmp + 3] = 0.0;
      i = (d_j + 9) * 6;
      H[i + 3] = 0.0;
      H[6 * d_j + 4] = 0.0;
      H[q_minus_inv_tmp + 4] = 0.0;
      H[i + 4] = 0.0;
      H[6 * d_j + 5] = 0.0;
      H[q_minus_inv_tmp + 5] = 0.0;
      H[i + 5] = 0.0;
    }

    rEQ0 = false;
    for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 7; q_minus_inv_tmp++) {
      if (!rEQ0) {
        rEQ0 = rtIsNaN(z[q_minus_inv_tmp]);
      }
    }

    if (!rEQ0) {
      Fullexp_rand_m();
      q_mag = Fullexp_norm(axis);
      theta = 0.0 / q_mag * 0.024997395914712332;
      q_mag = 1.0 / q_mag * 0.024997395914712332;
      vector[0] = theta;
      vector[1] = theta;
      vector[2] = q_mag;
      dt_0[0] = 0.0;
      dt_0[3] = -q_mag;
      dt_0[6] = theta;
      dt_0[1] = q_mag;
      dt_0[4] = 0.0;
      dt_0[7] = -theta;
      dt_0[2] = -theta;
      dt_0[5] = theta;
      dt_0[8] = 0.0;
      T[0] = 0.99968751627570263;
      for (d_j = 0; d_j < 3; d_j++) {
        q_mag = vector[d_j];
        i = (d_j + 1) << 2;
        T[i] = -q_mag;
        T[d_j + 1] = q_mag;
        T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) *
          0.99968751627570263 + dt_0[3 * d_j];
        q_minus_inv_tmp = 3 * d_j + 1;
        T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
          0.99968751627570263 + dt_0[q_minus_inv_tmp];
        q_minus_inv_tmp = 3 * d_j + 2;
        T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
          0.99968751627570263 + dt_0[q_minus_inv_tmp];
      }

      q_mag = z[1];
      theta = z[0];
      dt_tmp = z[2];
      n2_tmp_0 = z[3];
      for (d_j = 0; d_j < 4; d_j++) {
        dq_corr_dual[d_j] = ((T[d_j + 4] * q_mag + T[d_j] * theta) + T[d_j + 8] *
                             dt_tmp) + T[d_j + 12] * n2_tmp_0;
      }

      z[0] = dq_corr_dual[0];
      z[1] = dq_corr_dual[1];
      z[2] = dq_corr_dual[2];
      z[3] = dq_corr_dual[3];
    }

    vector[0] = z[1];
    vector[1] = z[2];
    vector[2] = z[3];
    theta = z[0];
    dt_0[0] = 0.0;
    dt_0[3] = -z[3];
    dt_0[6] = z[2];
    dt_0[1] = z[3];
    dt_0[4] = 0.0;
    dt_0[7] = -z[1];
    dt_0[2] = -z[2];
    dt_0[5] = z[1];
    dt_0[8] = 0.0;
    T[0] = z[0];
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * theta + dt_0[3
        * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) * theta
        + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) * theta
        + dt_0[q_minus_inv_tmp];
    }

    q_mag = cos(yaw_quant / 2.0);
    yaw_quant = -sin(yaw_quant / 2.0);
    for (d_j = 0; d_j < 4; d_j++) {
      q_minus_inv[d_j] = ((T[d_j + 4] * -0.0 + T[d_j] * q_mag) + T[d_j + 8] *
                          -0.0) + T[d_j + 12] * yaw_quant;
    }

    Fullexp_smallQuat(q_minus_inv, qr);
    y[0] = qr[1] / (qr[0] + 1.0);
    y[1] = qr[2] / (qr[0] + 1.0);
    y[2] = qr[3] / (qr[0] + 1.0);
    y[3] = z[4] - z_bar[4];
    y[4] = z[5] - z_bar[5];
    y[5] = z[6] - z_bar[6];
    rEQ0 = rtIsNaN(z[0]);
    if (!rEQ0) {
      rEQ0 = rtIsNaN(z[1]);
    }

    if (!rEQ0) {
      rEQ0 = rtIsNaN(z[2]);
    }

    if (!rEQ0) {
      rEQ0 = rtIsNaN(z[3]);
    }

    if (rEQ0) {
      rEQ0 = true;
    } else {
      for (d_j = 0; d_j < 3; d_j++) {
        for (i = 0; i < 12; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += H[6 * q_minus_inv_tmp + d_j] * P_k[12 * i + q_minus_inv_tmp];
          }

          H_0[d_j + 3 * i] = q_mag;
        }

        for (i = 0; i < 3; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += H_0[3 * q_minus_inv_tmp + d_j] * H[6 * q_minus_inv_tmp + i];
          }

          Rot_error[d_j + 3 * i] = q_mag;
        }
      }

      yaw_quant = 0.0;
      for (d_j = 0; d_j < 3; d_j++) {
        yaw_quant += ((Rot_error[3 * d_j + 1] * y[1] + Rot_error[3 * d_j] * y[0])
                      + Rot_error[3 * d_j + 2] * y[2]) * y[d_j];
      }

      rEQ0 = !(sqrt(yaw_quant) < 0.03);
    }

    rejectPose = rtIsNaN(z[4]);
    if (!rejectPose) {
      rejectPose = rtIsNaN(z[5]);
    }

    if (!rejectPose) {
      rejectPose = rtIsNaN(z[6]);
    }

    if (rejectPose) {
      rejectPose = true;
    } else {
      for (d_j = 0; d_j < 3; d_j++) {
        for (i = 0; i < 12; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += H[(6 * q_minus_inv_tmp + d_j) + 3] * P_k[12 * i +
              q_minus_inv_tmp];
          }

          H_0[d_j + 3 * i] = q_mag;
        }

        for (i = 0; i < 3; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += H[(6 * q_minus_inv_tmp + i) + 3] * H_0[3 * q_minus_inv_tmp
              + d_j];
          }

          Rot_error[d_j + 3 * i] = q_mag;
        }
      }

      yaw_quant = 0.0;
      for (d_j = 0; d_j < 3; d_j++) {
        yaw_quant += ((Rot_error[3 * d_j + 1] * y[4] + Rot_error[3 * d_j] * y[3])
                      + Rot_error[3 * d_j + 2] * y[5]) * y[d_j + 3];
      }

      rejectPose = !(sqrt(yaw_quant) < 0.1);
    }

    if (rEQ0) {
      y[0] = 0.0;
      y[1] = 0.0;
      y[2] = 0.0;
      for (d_j = 0; d_j < 12; d_j++) {
        H[6 * d_j] = 0.0;
        H[6 * d_j + 1] = 0.0;
        H[6 * d_j + 2] = 0.0;
      }
    }

    if (rejectPose) {
      y[3] = 0.0;
      y[4] = 0.0;
      y[5] = 0.0;
      for (d_j = 0; d_j < 12; d_j++) {
        H[6 * d_j + 3] = 0.0;
        H[6 * d_j + 4] = 0.0;
        H[6 * d_j + 5] = 0.0;
      }
    }

    for (d_j = 0; d_j < 6; d_j++) {
      for (i = 0; i < 12; i++) {
        Phi_tmp = 6 * i + d_j;
        K[i + 12 * d_j] = H[Phi_tmp];
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += H[6 * q_minus_inv_tmp + d_j] * P_k[12 * i + q_minus_inv_tmp];
        }

        H_1[Phi_tmp] = q_mag;
      }
    }

    for (d_j = 0; d_j < 6; d_j++) {
      for (i = 0; i < 6; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += H_1[6 * q_minus_inv_tmp + d_j] * K[12 * i + q_minus_inv_tmp];
        }

        q_minus_inv_tmp = 6 * i + d_j;
        H_0[q_minus_inv_tmp] = R[q_minus_inv_tmp] + q_mag;
      }
    }

    for (d_j = 0; d_j < 6; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += P_k[12 * q_minus_inv_tmp + i] * K[12 * d_j + q_minus_inv_tmp];
        }

        H_1[i + 12 * d_j] = q_mag;
      }
    }

    memcpy(&K[0], &H_1[0], 72U * sizeof(real_T));
    Fullexp_mrdiv_h(K, H_0);
    DQMEKFP_tmp_1 = &b[0];
    for (d_j = 0; d_j < 12; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
          q_mag += K[12 * q_minus_inv_tmp + d_j] * H[6 * i + q_minus_inv_tmp];
        }

        q_minus_inv_tmp = 12 * i + d_j;
        L[q_minus_inv_tmp] = q_mag;
        DQMEKFP_tmp[i + 12 * d_j] = (&b[0])[q_minus_inv_tmp];
      }
    }

    for (d_j = 0; d_j < 144; d_j++) {
      Phi[d_j] = static_cast<real_T>((&b[0])[d_j]) - L[d_j];
    }

    for (d_j = 0; d_j < 12; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += Phi[12 * q_minus_inv_tmp + d_j] * P_k[12 * i +
            q_minus_inv_tmp];
        }

        Phi_tmp = 12 * i + d_j;
        Phi_0[Phi_tmp] = q_mag;
        q_minus_inv_tmp = 12 * d_j + i;
        DQMEKFP_tmp_0[q_minus_inv_tmp] = DQMEKFP_tmp[q_minus_inv_tmp] -
          L[Phi_tmp];
      }

      for (i = 0; i < 6; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
          q_mag += K[12 * q_minus_inv_tmp + d_j] * R[6 * i + q_minus_inv_tmp];
        }

        H[d_j + 12 * i] = q_mag;
      }
    }

    for (d_j = 0; d_j < 12; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += Phi_0[12 * q_minus_inv_tmp + d_j] * DQMEKFP_tmp_0[12 * i +
            q_minus_inv_tmp];
        }

        Phi_tmp = 12 * i + d_j;
        Phi[Phi_tmp] = q_mag;
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
          q_mag += H[12 * q_minus_inv_tmp + d_j] * K[12 * q_minus_inv_tmp + i];
        }

        P_k[Phi_tmp] = q_mag;
      }
    }

    for (d_j = 0; d_j < 144; d_j++) {
      Fullexp_DW.QMEKFP[d_j] = Phi[d_j] + P_k[d_j];
    }

    for (d_j = 0; d_j < 12; d_j++) {
      q_mag = 0.0;
      for (i = 0; i < 6; i++) {
        q_mag += K[12 * i + d_j] * y[i];
      }

      rtb_x_k[d_j] = q_mag;
    }

    q_mag = Fullexp_norm(&rtb_x_k[0]);
    q_mag *= q_mag;
    yaw_quant = (sqrt(q_mag * 0.0 + 1.0) - q_mag) / (q_mag + 1.0);
    theta = (yaw_quant + 1.0) * rtb_x_k[0];
    q_mag = (yaw_quant + 1.0) * rtb_x_k[1];
    dt_tmp = (yaw_quant + 1.0) * rtb_x_k[2];
    vector[0] = theta;
    vector[1] = q_mag;
    vector[2] = dt_tmp;
    dt_0[0] = 0.0;
    dt_0[3] = -dt_tmp;
    dt_0[6] = q_mag;
    dt_0[1] = dt_tmp;
    dt_0[4] = 0.0;
    dt_0[7] = -theta;
    dt_0[2] = -q_mag;
    dt_0[5] = theta;
    dt_0[8] = 0.0;
    T[0] = yaw_quant;
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * yaw_quant +
        dt_0[3 * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
    }

    yaw_quant = x_k[1];
    q_mag = x_k[0];
    theta = x_k[2];
    dt_tmp = x_k[3];
    for (d_j = 0; d_j < 4; d_j++) {
      STQMEKFx[d_j] = ((T[d_j + 4] * yaw_quant + T[d_j] * q_mag) + T[d_j + 8] *
                       theta) + T[d_j + 12] * dt_tmp;
    }

    for (i = 0; i < 9; i++) {
      STQMEKFx[i + 4] = x_k[i + 4] + rtb_x_k[i + 3];
    }

    memcpy(&Fullexp_B.x_est_dp[0], &STQMEKFx[0], 13U * sizeof(real_T));
    rtb_TSamp_af = Fullexp_toc_i(&savedTime_o);

    // DataStoreWrite: '<S16>/Data Store Write17'
    memcpy(&QMEKFx[0], &Fullexp_B.x_est_dp[0], 13U * sizeof(real_T));

    // MATLAB Function: '<S17>/MATLAB Function1' incorporates:
    //   DataStoreRead: '<S17>/Data Store Read2'
    //   DataStoreRead: '<S17>/Data Store Read3'
    //   DataStoreRead: '<S17>/Data Store Read4'
    //   DataStoreWrite: '<S17>/Data Store Write1'
    //   DataStoreWrite: '<S17>/Data Store Write18'
    //   Delay: '<S17>/Delay'
    //   Delay: '<S17>/Delay1'
    //   Delay: '<S17>/Delay2'
    //   MATLAB Function: '<S23>/MATLAB Function1'

    b_vector[0] = Red_x[0];
    b_vector[1] = Red_x[1];
    b_vector[2] = Red_yaw;
    Fullexp_tic_p(&savedTime_a);
    dt_0[0] = 0.0 * dt;
    yaw_quant = -Fullexp_DW.Delay1_DSTATE_o[8] * dt;
    dt_0[3] = yaw_quant;
    theta = Fullexp_DW.Delay1_DSTATE_o[7] * dt;
    dt_0[6] = theta;
    dt_tmp = Fullexp_DW.Delay1_DSTATE_o[8] * dt;
    dt_0[1] = dt_tmp;
    dt_0[4] = 0.0 * dt;
    n2_tmp_0 = -Fullexp_DW.Delay1_DSTATE_o[6] * dt;
    dt_0[7] = n2_tmp_0;
    n2_tmp_1 = -Fullexp_DW.Delay1_DSTATE_o[7] * dt;
    dt_0[2] = n2_tmp_1;
    n2_tmp = Fullexp_DW.Delay1_DSTATE_o[6] * dt;
    dt_0[5] = n2_tmp;
    dt_0[8] = 0.0 * dt;
    Fullexp_expm_h(dt_0, R_chaser);
    for (d_j = 0; d_j < 3; d_j++) {
      Red_yaw = Fullexp_DW.Delay2_DSTATE[3 * d_j + 1];
      n2 = Fullexp_DW.Delay2_DSTATE[3 * d_j];
      q_mag = Fullexp_DW.Delay2_DSTATE[3 * d_j + 2];
      for (i = 0; i < 3; i++) {
        dt_0[i + 3 * d_j] = (R_chaser[i + 3] * Red_yaw + n2 * R_chaser[i]) +
          R_chaser[i + 6] * q_mag;
      }
    }

    memcpy(&Fullexp_B.x_est_m[0], &Fullexp_DW.Delay1_DSTATE_o[0], 9U * sizeof
           (real_T));
    Fullexp_B.x_est_m[0] = dt * Fullexp_DW.Delay1_DSTATE_o[3] +
      Fullexp_DW.Delay1_DSTATE_o[0];
    Fullexp_B.x_est_m[1] = dt * Fullexp_DW.Delay1_DSTATE_o[4] +
      Fullexp_DW.Delay1_DSTATE_o[1];
    Fullexp_B.x_est_m[2] = dt * Fullexp_DW.Delay1_DSTATE_o[5] +
      Fullexp_DW.Delay1_DSTATE_o[2];
    memset(&varargin_4[0], 0, 9U * sizeof(real_T));
    Red_yaw = 0.0 * dt + 1.0;
    L[0] = Red_yaw;
    L[1] = dt_tmp;
    L[2] = n2_tmp_1;
    L[12] = yaw_quant;
    L[13] = Red_yaw;
    L[14] = n2_tmp;
    L[24] = theta;
    L[25] = n2_tmp_0;
    L[26] = Red_yaw;
    for (d_j = 0; d_j < 6; d_j++) {
      q_minus_inv_tmp = (d_j + 3) * 12;
      L[q_minus_inv_tmp] = 0.0;
      L[q_minus_inv_tmp + 1] = 0.0;
      L[q_minus_inv_tmp + 2] = 0.0;
    }

    for (d_j = 0; d_j < 3; d_j++) {
      Red_yaw = Phi_m_tmp[3 * d_j];
      q_minus_inv_tmp = (d_j + 9) * 12;
      L[q_minus_inv_tmp] = Red_yaw;
      L[12 * d_j + 3] = 0.0;
      i = (d_j + 3) * 12;
      L[i + 3] = dq_corr_dual_tmp[3 * d_j];
      Phi_tmp = (d_j + 6) * 12;
      L[Phi_tmp + 3] = Red_yaw;
      L[q_minus_inv_tmp + 3] = 0.0;
      jA = 3 * d_j + 1;
      Red_yaw = Phi_m_tmp[jA];
      L[q_minus_inv_tmp + 1] = Red_yaw;
      L[12 * d_j + 4] = 0.0;
      L[i + 4] = dq_corr_dual_tmp[jA];
      L[Phi_tmp + 4] = Red_yaw;
      L[q_minus_inv_tmp + 4] = 0.0;
      jA = 3 * d_j + 2;
      Red_yaw = Phi_m_tmp[jA];
      L[q_minus_inv_tmp + 2] = Red_yaw;
      L[12 * d_j + 5] = 0.0;
      L[i + 5] = dq_corr_dual_tmp[jA];
      L[Phi_tmp + 5] = Red_yaw;
      L[q_minus_inv_tmp + 5] = 0.0;
    }

    for (d_j = 0; d_j < 12; d_j++) {
      L[12 * d_j + 6] = e_0[3 * d_j];
      L[12 * d_j + 9] = F_tmp[3 * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      L[12 * d_j + 7] = e_0[q_minus_inv_tmp];
      L[12 * d_j + 10] = F_tmp[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      L[12 * d_j + 8] = e_0[q_minus_inv_tmp];
      L[12 * d_j + 11] = F_tmp[q_minus_inv_tmp];
    }

    Red_yaw = sin(b_vector[2]);
    n2 = cos(b_vector[2]);
    R_chaser[0] = n2;
    R_chaser[3] = Red_yaw;
    R_chaser[6] = 0.0;
    R_chaser[1] = -Red_yaw;
    R_chaser[4] = n2;
    R_chaser[7] = 0.0;
    R_chaser[2] = 0.0;
    R_chaser[5] = 0.0;
    R_chaser[8] = 1.0;
    for (d_j = 0; d_j < 12; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += L[12 * q_minus_inv_tmp + d_j] * Fullexp_DW.Delay_DSTATE_n[12 *
            i + q_minus_inv_tmp];
        }

        Phi[d_j + 12 * i] = q_mag;
      }

      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += Phi[12 * q_minus_inv_tmp + d_j] * L[12 * q_minus_inv_tmp + i];
        }

        q_minus_inv_tmp = 12 * i + d_j;
        P_k[q_minus_inv_tmp] = Q[q_minus_inv_tmp] + q_mag;
      }

      H[6 * d_j] = H_tmp[3 * d_j];
      H[6 * d_j + 1] = H_tmp[3 * d_j + 1];
      H[6 * d_j + 2] = H_tmp[3 * d_j + 2];
    }

    for (d_j = 0; d_j < 3; d_j++) {
      H[6 * d_j + 3] = 0.0;
      q_minus_inv_tmp = (d_j + 3) * 6;
      H[q_minus_inv_tmp + 3] = R_chaser[3 * d_j];
      H[6 * d_j + 4] = 0.0;
      H[q_minus_inv_tmp + 4] = R_chaser[3 * d_j + 1];
      H[6 * d_j + 5] = 0.0;
      H[q_minus_inv_tmp + 5] = R_chaser[3 * d_j + 2];
    }

    for (d_j = 0; d_j < 6; d_j++) {
      q_minus_inv_tmp = (d_j + 6) * 6;
      H[q_minus_inv_tmp + 3] = 0.0;
      H[q_minus_inv_tmp + 4] = 0.0;
      H[q_minus_inv_tmp + 5] = 0.0;
    }

    Fullexp_rand_a();
    for (d_j = 0; d_j < 3; d_j++) {
      Red_yaw = dt_0[d_j + 3];
      n2 = dt_0[d_j];
      q_mag = dt_0[d_j + 6];
      for (i = 0; i < 3; i++) {
        dt_1[d_j + 3 * i] = (R_chaser[i + 3] * Red_yaw + n2 * R_chaser[i]) +
          R_chaser[i + 6] * q_mag;
      }

      Red_yaw = dt_1[d_j + 3];
      n2 = dt_1[d_j];
      q_mag = dt_1[d_j + 6];
      for (i = 0; i < 3; i++) {
        Rot_error[d_j + 3 * i] = (l[i + 3] * Fullexp_DW.Vis_yaw * Red_yaw + l[i]
          * Fullexp_DW.Vis_yaw * n2) + l[i + 6] * Fullexp_DW.Vis_yaw * q_mag;
      }
    }

    theta = (((Rot_error[0] + Rot_error[4]) + Rot_error[8]) - 1.0) / 2.0;
    if (!(theta <= 1.0)) {
      theta = 1.0;
    }

    if (!(theta >= -1.0)) {
      theta = -1.0;
    }

    theta = acos(theta);
    if (fabs(theta) < 1.0E-8) {
      Red_x[0] = 0.0;
      Red_x[1] = 0.0;
      Red_x[2] = 0.0;
    } else {
      yaw_quant = 2.0 * sin(theta) * theta;
      Red_yaw = sin(Rot_error[5]);
      n2 = cos(Rot_error[5]);
      q_mag = sin(Rot_error[7]);
      theta = cos(Rot_error[7]);
      y_tmp[0] = (Red_yaw * 0.0 + n2) - (q_mag * 0.0 + theta);
      y_tmp[1] = (n2 * 0.0 - Red_yaw) - (theta * 0.0 - q_mag);
      theta = sin(Rot_error[6]);
      q_mag = cos(Rot_error[6]);
      dt_tmp = sin(Rot_error[2]);
      n2_tmp_0 = cos(Rot_error[2]);
      b_y_tmp[0] = (theta * 0.0 + q_mag) - (dt_tmp * 0.0 + n2_tmp_0);
      b_y_tmp[1] = (q_mag * 0.0 - theta) - (n2_tmp_0 * 0.0 - dt_tmp);
      dt_tmp = sin(Rot_error[1]);
      n2_tmp_0 = cos(Rot_error[1]);
      n2_tmp_1 = sin(Rot_error[3]);
      n2_tmp = cos(Rot_error[3]);
      c_y_tmp[0] = (dt_tmp * 0.0 + n2_tmp_0) - (n2_tmp_1 * 0.0 + n2_tmp);
      c_y_tmp[1] = (n2_tmp_0 * 0.0 - dt_tmp) - (n2_tmp * 0.0 - n2_tmp_1);
      Red_yaw = (n2 * 0.0 + Red_yaw) * y_tmp[0] + (-Red_yaw * 0.0 + n2) * y_tmp
        [1];
      theta = (q_mag * 0.0 + theta) * b_y_tmp[0] + (-theta * 0.0 + q_mag) *
        b_y_tmp[1];
      dt_tmp = (n2_tmp_0 * 0.0 + dt_tmp) * c_y_tmp[0] + (-dt_tmp * 0.0 +
        n2_tmp_0) * c_y_tmp[1];
      if (rtIsNaN(Red_yaw)) {
        q_mag = (rtNaN);
      } else if (Red_yaw < 0.0) {
        q_mag = -1.0;
      } else {
        q_mag = (Red_yaw > 0.0);
      }

      Red_x[0] = -Fullexp_norm_lf(y_tmp) * q_mag * yaw_quant;
      if (rtIsNaN(theta)) {
        q_mag = (rtNaN);
      } else if (theta < 0.0) {
        q_mag = -1.0;
      } else {
        q_mag = (theta > 0.0);
      }

      Red_x[1] = -Fullexp_norm_lf(b_y_tmp) * q_mag * yaw_quant;
      if (rtIsNaN(dt_tmp)) {
        q_mag = (rtNaN);
      } else if (dt_tmp < 0.0) {
        q_mag = -1.0;
      } else {
        q_mag = (dt_tmp > 0.0);
      }

      Red_x[2] = -Fullexp_norm_lf(c_y_tmp) * q_mag * yaw_quant;
    }

    Red_yaw = Fullexp_B.x_est_m[0] - b_vector[0];
    n2 = Fullexp_B.x_est_m[1] - b_vector[1];
    yaw_quant = Fullexp_B.x_est_m[2];
    for (d_j = 0; d_j < 3; d_j++) {
      y[d_j] = Red_x[d_j];
      y[d_j + 3] = Fullexp_DW.Vis_x[d_j] - ((R_chaser[d_j + 3] * n2 +
        R_chaser[d_j] * Red_yaw) + R_chaser[d_j + 6] * yaw_quant);
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += H[(6 * q_minus_inv_tmp + d_j) + 3] * P_k[12 * i +
            q_minus_inv_tmp];
        }

        H_0[d_j + 3 * i] = q_mag;
      }

      for (i = 0; i < 3; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += H[(6 * q_minus_inv_tmp + i) + 3] * H_0[3 * q_minus_inv_tmp +
            d_j];
        }

        Rot_error[d_j + 3 * i] = q_mag;
      }
    }

    yaw_quant = 0.0;
    for (d_j = 0; d_j < 3; d_j++) {
      yaw_quant += ((Rot_error[3 * d_j + 1] * y[4] + Rot_error[3 * d_j] * y[3])
                    + Rot_error[3 * d_j + 2] * y[5]) * y[d_j + 3];
    }

    for (d_j = 0; d_j < 3; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += H[6 * q_minus_inv_tmp + d_j] * P_k[12 * i + q_minus_inv_tmp];
        }

        H_0[d_j + 3 * i] = q_mag;
      }

      for (i = 0; i < 3; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += H_0[3 * q_minus_inv_tmp + d_j] * H[6 * q_minus_inv_tmp + i];
        }

        Rot_error[d_j + 3 * i] = q_mag;
      }
    }

    Red_yaw = 0.0;
    for (d_j = 0; d_j < 3; d_j++) {
      Red_yaw += ((Rot_error[3 * d_j + 1] * y[1] + Rot_error[3 * d_j] * y[0]) +
                  Rot_error[3 * d_j + 2] * y[2]) * y[d_j];
    }

    if (!(sqrt(Red_yaw) < 0.03)) {
      y[0] = 0.0;
      y[1] = 0.0;
      y[2] = 0.0;
      for (d_j = 0; d_j < 12; d_j++) {
        H[6 * d_j] = 0.0;
        H[6 * d_j + 1] = 0.0;
        H[6 * d_j + 2] = 0.0;
      }
    }

    if (!(sqrt(yaw_quant) < 0.1)) {
      y[3] = 0.0;
      y[4] = 0.0;
      y[5] = 0.0;
      for (d_j = 0; d_j < 12; d_j++) {
        H[6 * d_j + 3] = 0.0;
        H[6 * d_j + 4] = 0.0;
        H[6 * d_j + 5] = 0.0;
      }
    }

    for (d_j = 0; d_j < 6; d_j++) {
      for (i = 0; i < 12; i++) {
        Phi_tmp = 6 * i + d_j;
        K[i + 12 * d_j] = H[Phi_tmp];
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += H[6 * q_minus_inv_tmp + d_j] * P_k[12 * i + q_minus_inv_tmp];
        }

        H_1[Phi_tmp] = q_mag;
      }
    }

    for (d_j = 0; d_j < 6; d_j++) {
      for (i = 0; i < 6; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += H_1[6 * q_minus_inv_tmp + d_j] * K[12 * i + q_minus_inv_tmp];
        }

        Phi_tmp = 6 * i + d_j;
        A[Phi_tmp] = R[Phi_tmp] + q_mag;
      }
    }

    for (d_j = 0; d_j < 6; d_j++) {
      for (i = 0; i < 12; i++) {
        Red_yaw = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          Red_yaw += P_k[12 * q_minus_inv_tmp + i] * K[12 * d_j +
            q_minus_inv_tmp];
        }

        H_1[i + 12 * d_j] = Red_yaw;
      }

      ipiv[d_j] = static_cast<int8_T>(d_j + 1);
    }

    for (d_j = 0; d_j < 5; d_j++) {
      i = d_j * 7;
      Phi_tmp = 5 - d_j;
      jA = 0;
      Red_yaw = fabs(A[i]);
      for (q_minus_inv_tmp = 2; q_minus_inv_tmp <= Phi_tmp + 1; q_minus_inv_tmp
           ++) {
        q_mag = fabs(A[(i + q_minus_inv_tmp) - 1]);
        if (q_mag > Red_yaw) {
          jA = q_minus_inv_tmp - 1;
          Red_yaw = q_mag;
        }
      }

      if (A[i + jA] != 0.0) {
        if (jA != 0) {
          jA += d_j;
          ipiv[d_j] = static_cast<int8_T>(jA + 1);
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
            jAcol = q_minus_inv_tmp * 6 + d_j;
            Red_yaw = A[jAcol];
            Phi_tmp = q_minus_inv_tmp * 6 + jA;
            A[jAcol] = A[Phi_tmp];
            A[Phi_tmp] = Red_yaw;
          }
        }

        Phi_tmp = (i - d_j) + 6;
        for (q_minus_inv_tmp = i + 2; q_minus_inv_tmp <= Phi_tmp;
             q_minus_inv_tmp++) {
          A[q_minus_inv_tmp - 1] /= A[i];
        }
      }

      jA = i + 8;
      jAcol = 4 - d_j;
      for (q_minus_inv_tmp = 0; q_minus_inv_tmp <= jAcol; q_minus_inv_tmp++) {
        Red_yaw = A[(q_minus_inv_tmp * 6 + i) + 6];
        if (Red_yaw != 0.0) {
          kBcol = (jA - d_j) + 4;
          for (Phi_tmp = jA; Phi_tmp <= kBcol; Phi_tmp++) {
            A[Phi_tmp - 1] += A[((i + Phi_tmp) - jA) + 1] * -Red_yaw;
          }
        }

        jA += 6;
      }
    }

    for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
      jA = 12 * q_minus_inv_tmp;
      jAcol = 6 * q_minus_inv_tmp;
      for (i = 0; i < q_minus_inv_tmp; i++) {
        kBcol = 12 * i;
        q_mag = A[i + jAcol];
        if (q_mag != 0.0) {
          for (Phi_tmp = 0; Phi_tmp < 12; Phi_tmp++) {
            d_j = Phi_tmp + jA;
            H_1[d_j] -= H_1[Phi_tmp + kBcol] * q_mag;
          }
        }
      }

      Red_yaw = 1.0 / A[q_minus_inv_tmp + jAcol];
      for (i = 0; i < 12; i++) {
        d_j = i + jA;
        H_1[d_j] *= Red_yaw;
      }
    }

    for (q_minus_inv_tmp = 5; q_minus_inv_tmp >= 0; q_minus_inv_tmp--) {
      jA = 12 * q_minus_inv_tmp;
      jAcol = 6 * q_minus_inv_tmp - 1;
      for (i = q_minus_inv_tmp + 2; i < 7; i++) {
        kBcol = (i - 1) * 12;
        q_mag = A[i + jAcol];
        if (q_mag != 0.0) {
          for (Phi_tmp = 0; Phi_tmp < 12; Phi_tmp++) {
            d_j = Phi_tmp + jA;
            H_1[d_j] -= H_1[Phi_tmp + kBcol] * q_mag;
          }
        }
      }
    }

    for (q_minus_inv_tmp = 4; q_minus_inv_tmp >= 0; q_minus_inv_tmp--) {
      rtPrevAction = ipiv[q_minus_inv_tmp];
      if (q_minus_inv_tmp + 1 != rtPrevAction) {
        for (i = 0; i < 12; i++) {
          Phi_tmp = 12 * q_minus_inv_tmp + i;
          Red_yaw = H_1[Phi_tmp];
          d_j = (rtPrevAction - 1) * 12 + i;
          H_1[Phi_tmp] = H_1[d_j];
          H_1[d_j] = Red_yaw;
        }
      }
    }

    for (d_j = 0; d_j < 12; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
          q_mag += H_1[12 * q_minus_inv_tmp + i] * H[6 * d_j + q_minus_inv_tmp];
        }

        L[i + 12 * d_j] = q_mag;
      }
    }

    for (d_j = 0; d_j < 144; d_j++) {
      Phi[d_j] = static_cast<real_T>(DQMEKFP_tmp_1[d_j]) - L[d_j];
    }

    for (d_j = 0; d_j < 12; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += Phi[12 * q_minus_inv_tmp + d_j] * P_k[12 * i +
            q_minus_inv_tmp];
        }

        Phi_tmp = 12 * i + d_j;
        Phi_0[Phi_tmp] = q_mag;
        q_minus_inv_tmp = 12 * d_j + i;
        DQMEKFP_tmp_0[q_minus_inv_tmp] = DQMEKFP_tmp[q_minus_inv_tmp] -
          L[Phi_tmp];
      }

      for (i = 0; i < 6; i++) {
        Red_yaw = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
          Red_yaw += H_1[12 * q_minus_inv_tmp + d_j] * R[6 * i + q_minus_inv_tmp];
        }

        K[d_j + 12 * i] = Red_yaw;
      }
    }

    for (d_j = 0; d_j < 12; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += Phi_0[12 * q_minus_inv_tmp + d_j] * DQMEKFP_tmp_0[12 * i +
            q_minus_inv_tmp];
        }

        Phi_tmp = 12 * i + d_j;
        Phi[Phi_tmp] = q_mag;
        Red_yaw = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
          Red_yaw += K[12 * q_minus_inv_tmp + d_j] * H_1[12 * q_minus_inv_tmp +
            i];
        }

        P_k[Phi_tmp] = Red_yaw;
      }
    }

    for (d_j = 0; d_j < 144; d_j++) {
      Fullexp_DW.RMEKFP[d_j] = Phi[d_j] + P_k[d_j];
    }

    for (d_j = 0; d_j < 12; d_j++) {
      q_mag = 0.0;
      for (i = 0; i < 6; i++) {
        q_mag += H_1[12 * i + d_j] * y[i];
      }

      rtb_x_k[d_j] = q_mag;
    }

    n2 = 3.3121686421112381E-170;
    q_mag = fabs(rtb_x_k[0]);
    if (q_mag > 3.3121686421112381E-170) {
      Red_yaw = 1.0;
      n2 = q_mag;
    } else {
      yaw_quant = q_mag / 3.3121686421112381E-170;
      Red_yaw = yaw_quant * yaw_quant;
    }

    q_mag = fabs(rtb_x_k[1]);
    if (q_mag > n2) {
      yaw_quant = n2 / q_mag;
      Red_yaw = Red_yaw * yaw_quant * yaw_quant + 1.0;
      n2 = q_mag;
    } else {
      yaw_quant = q_mag / n2;
      Red_yaw += yaw_quant * yaw_quant;
    }

    q_mag = fabs(rtb_x_k[2]);
    if (q_mag > n2) {
      yaw_quant = n2 / q_mag;
      Red_yaw = Red_yaw * yaw_quant * yaw_quant + 1.0;
      n2 = q_mag;
    } else {
      yaw_quant = q_mag / n2;
      Red_yaw += yaw_quant * yaw_quant;
    }

    Red_yaw = n2 * sqrt(Red_yaw);
    if (Red_yaw > 1.0E-8) {
      Red_x[0] = rtb_x_k[0] / Red_yaw;
      Red_x[1] = rtb_x_k[1] / Red_yaw;
      Red_x[2] = rtb_x_k[2] / Red_yaw;
    } else {
      Red_x[0] = 0.0;
      Red_x[1] = 0.0;
      Red_x[2] = 0.0;
    }

    n2 = sin(Red_yaw);
    q_mag = cos(Red_yaw);
    R_chaser[0] = 0.0;
    R_chaser[3] = -Red_x[2];
    R_chaser[6] = Red_x[1];
    R_chaser[1] = Red_x[2];
    R_chaser[4] = 0.0;
    R_chaser[7] = -Red_x[0];
    R_chaser[2] = -Red_x[1];
    R_chaser[5] = Red_x[0];
    R_chaser[8] = 0.0;
    memset(&Rot_error[0], 0, 9U * sizeof(real_T));
    for (i = 0; i < 3; i++) {
      Rot_error[i + 3 * i] = 1.0;
      for (d_j = 0; d_j < 3; d_j++) {
        dt_1[i + 3 * d_j] = (R_chaser[3 * d_j + 1] * R_chaser[i + 3] + R_chaser
                             [3 * d_j] * R_chaser[i]) + R_chaser[3 * d_j + 2] *
          R_chaser[i + 6];
      }
    }

    R_chaser[0] = n2 * 0.0 + Rot_error[0];
    R_chaser[1] = n2 * Red_x[2] + Rot_error[1];
    R_chaser[2] = n2 * -Red_x[1] + Rot_error[2];
    R_chaser[3] = n2 * -Red_x[2] + Rot_error[3];
    R_chaser[4] = n2 * 0.0 + Rot_error[4];
    R_chaser[5] = n2 * Red_x[0] + Rot_error[5];
    R_chaser[6] = n2 * Red_x[1] + Rot_error[6];
    R_chaser[7] = n2 * -Red_x[0] + Rot_error[7];
    R_chaser[8] = n2 * 0.0 + Rot_error[8];
    for (d_j = 0; d_j < 9; d_j++) {
      Rot_error[d_j] = (1.0 - q_mag) * dt_1[d_j] + R_chaser[d_j];
    }

    for (d_j = 0; d_j < 3; d_j++) {
      Red_yaw = dt_0[3 * d_j + 1];
      n2 = dt_0[3 * d_j];
      q_mag = dt_0[3 * d_j + 2];
      for (i = 0; i < 3; i++) {
        Fullexp_DW.RMEKFR[i + 3 * d_j] = (Rot_error[i + 3] * Red_yaw + n2 *
          Rot_error[i]) + Rot_error[i + 6] * q_mag;
      }
    }

    for (d_j = 0; d_j < 9; d_j++) {
      Fullexp_B.x_est_m[d_j] += rtb_x_k[d_j + 3];
    }

    Red_yaw = Fullexp_toc_b(&savedTime_a);

    // DataStoreWrite: '<S17>/Data Store Write17'
    memcpy(&R_chaser[0], &Fullexp_B.x_est_m[0], 9U * sizeof(real_T));

    // MATLAB Function: '<S22>/MATLAB Function1' incorporates:
    //   DataStoreRead: '<S22>/Data Store Read1'
    //   DataStoreRead: '<S22>/Data Store Read2'
    //   DataStoreWrite: '<S22>/Data Store Write18'
    //   Delay: '<S22>/Delay'
    //   Delay: '<S22>/Delay1'
    //   Delay: '<S22>/Delay2'

    Fullexp_tic_b(&savedTime_o2);
    memcpy(&z_meas[0], &rtb_dq_e[0], sizeof(real_T) << 3U);
    n2_tmp_0 = dt * -Fullexp_DW.Delay1_DSTATE_b[8];
    n2 = n2_tmp_0 / 4.0;
    qr[1] = n2;
    Red_q[1] = 0.0 - n2;
    n2_tmp_1 = dt * -Fullexp_DW.Delay1_DSTATE_b[9];
    n2 = n2_tmp_1 / 4.0;
    qr[2] = n2;
    Red_q[2] = 0.0 - n2;
    n2_tmp = dt * -Fullexp_DW.Delay1_DSTATE_b[10];
    n2 = n2_tmp / 4.0;
    q_mag = sqrt(((Red_q[1] * Red_q[1] + 1.0) + Red_q[2] * Red_q[2]) + (0.0 - n2)
                 * (0.0 - n2));
    q_mag *= q_mag;
    q_minus_inv[0] = 1.0 / q_mag;
    q_minus_inv[1] = -Red_q[1] / q_mag;
    q_minus_inv[2] = -Red_q[2] / q_mag;
    q_minus_inv[3] = -(0.0 - n2) / q_mag;
    vector[0] = qr[1];
    vector[1] = qr[2];
    vector[2] = n2;
    b_vector[0] = q_minus_inv[1];
    b_vector[1] = q_minus_inv[2];
    b_vector[2] = q_minus_inv[3];
    yaw_quant = q_minus_inv[0];
    dt_0[0] = 0.0;
    dt_0[3] = -q_minus_inv[3];
    dt_0[6] = q_minus_inv[2];
    dt_0[1] = q_minus_inv[3];
    dt_0[4] = 0.0;
    dt_0[7] = -q_minus_inv[1];
    dt_0[2] = -q_minus_inv[2];
    dt_0[5] = q_minus_inv[1];
    dt_0[8] = 0.0;
    T[0] = q_minus_inv[0];
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = b_vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * yaw_quant +
        dt_0[3 * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
      dq_corr_dual[d_j + 1] = -Fullexp_DW.Delay1_DSTATE_b[d_j + 11] * dt / 4.0;
    }

    q_mag = dq_corr_dual[1];
    yaw_quant = dq_corr_dual[2];
    theta = dq_corr_dual[3];
    for (d_j = 0; d_j < 4; d_j++) {
      Red_q[d_j] = ((T[d_j + 4] * q_mag + T[d_j] * 0.0) + T[d_j + 8] * yaw_quant)
        + T[d_j + 12] * theta;
    }

    b_vector[0] = Red_q[1];
    b_vector[1] = Red_q[2];
    b_vector[2] = Red_q[3];
    rtb_v_0[0] = 0.0;
    rtb_v_0[1] = -n2;
    rtb_v_0[2] = qr[2];
    vector_0[0] = n2;
    vector_0[1] = 0.0;
    vector_0[2] = -qr[1];
    vector_1[0] = -qr[2];
    vector_1[1] = qr[1];
    vector_1[2] = 0.0;
    T[0] = 1.0;
    theta = Red_q[0];
    dt_0[0] = 0.0;
    dt_0[3] = -Red_q[3];
    dt_0[6] = Red_q[2];
    dt_0[1] = Red_q[3];
    dt_0[4] = 0.0;
    dt_0[7] = -Red_q[1];
    dt_0[2] = -Red_q[2];
    dt_0[5] = Red_q[1];
    dt_0[8] = 0.0;
    dq_corr_dual_0[0] = Red_q[0];
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(b_b[3 * d_j]) + rtb_v_0[d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(b_b[q_minus_inv_tmp]) + vector_0[d_j];
      Phi_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(b_b[Phi_tmp]) + vector_1[d_j];
      n2 = b_vector[d_j];
      dq_corr_dual_0[i] = -n2;
      dq_corr_dual_0[d_j + 1] = n2;
      dq_corr_dual_0[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) *
        theta + dt_0[3 * d_j];
      dq_corr_dual_0[i + 2] = static_cast<real_T>
        (dq_corr_dual_tmp[q_minus_inv_tmp]) * theta + dt_0[q_minus_inv_tmp];
      dq_corr_dual_0[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[Phi_tmp]) *
        theta + dt_0[Phi_tmp];
    }

    yaw_quant = q_minus_inv[1];
    n2 = q_minus_inv[0];
    q_mag = q_minus_inv[2];
    theta = q_minus_inv[3];
    for (d_j = 0; d_j < 4; d_j++) {
      q_minus_inv_0[d_j] = Fullexp_DW.Delay1_DSTATE_b[d_j];
      q_minus_inv_0[d_j + 4] = Fullexp_DW.Delay1_DSTATE_b[d_j + 4];
      tmp_2[d_j] = ((T[d_j + 4] * yaw_quant + T[d_j] * n2) + T[d_j + 8] * q_mag)
        + T[d_j + 12] * theta;
      tmp_2[d_j + 4] = (((dq_corr_dual_0[d_j + 4] * yaw_quant +
                          dq_corr_dual_0[d_j] * n2) + dq_corr_dual_0[d_j + 8] *
                         q_mag) + dq_corr_dual_0[d_j + 12] * theta) * 2.0;
    }

    Fullexp_dqMultiply(q_minus_inv_0, tmp_2, q_pred);
    memcpy(&STDQMEKFx[0], &Fullexp_DW.Delay1_DSTATE_b[0], 14U * sizeof(real_T));
    STDQMEKFx[0] = q_pred[0];
    STDQMEKFx[4] = q_pred[4];
    STDQMEKFx[1] = q_pred[1];
    STDQMEKFx[5] = q_pred[5];
    STDQMEKFx[2] = q_pred[2];
    STDQMEKFx[6] = q_pred[6];
    STDQMEKFx[3] = q_pred[3];
    STDQMEKFx[7] = q_pred[7];
    memset(&L[0], 0, 144U * sizeof(real_T));
    for (i = 0; i < 12; i++) {
      L[i + 12 * i] = 1.0;
    }

    dt_0[0] = dt * 0.0;
    dt_0[3] = n2_tmp;
    yaw_quant = dt * Fullexp_DW.Delay1_DSTATE_b[9];
    dt_0[6] = yaw_quant;
    theta = dt * Fullexp_DW.Delay1_DSTATE_b[10];
    dt_0[1] = theta;
    dt_0[4] = dt * 0.0;
    dt_0[7] = n2_tmp_0;
    dt_0[2] = n2_tmp_1;
    dt_tmp = dt * Fullexp_DW.Delay1_DSTATE_b[8];
    dt_0[5] = dt_tmp;
    dt_0[8] = dt * 0.0;
    Rot_error[0] = dt * 0.0;
    Rot_error[3] = dt * -Fullexp_DW.Delay1_DSTATE_b[13];
    Rot_error[6] = dt * Fullexp_DW.Delay1_DSTATE_b[12];
    Rot_error[1] = dt * Fullexp_DW.Delay1_DSTATE_b[13];
    Rot_error[4] = dt * 0.0;
    Rot_error[7] = dt * -Fullexp_DW.Delay1_DSTATE_b[11];
    Rot_error[2] = dt * -Fullexp_DW.Delay1_DSTATE_b[12];
    Rot_error[5] = dt * Fullexp_DW.Delay1_DSTATE_b[11];
    Rot_error[8] = dt * 0.0;
    dt_1[0] = dt * 0.0;
    dt_1[3] = n2_tmp;
    dt_1[6] = yaw_quant;
    dt_1[1] = theta;
    dt_1[4] = dt * 0.0;
    dt_1[7] = n2_tmp_0;
    dt_1[2] = n2_tmp_1;
    dt_1[5] = dt_tmp;
    dt_1[8] = dt * 0.0;
    for (d_j = 0; d_j < 3; d_j++) {
      Phi[12 * d_j] = L[12 * d_j] + dt_0[3 * d_j];
      i = (d_j + 3) * 12;
      Phi[i] = dt * 0.0 + L[i];
      n2 = T_0[3 * d_j];
      q_minus_inv_tmp = (d_j + 6) * 12;
      Phi[q_minus_inv_tmp] = L[q_minus_inv_tmp] + n2;
      Phi_tmp = (d_j + 9) * 12;
      Phi[Phi_tmp] = dt * 0.0 + L[Phi_tmp];
      jA = 12 * d_j + 3;
      Phi[jA] = Rot_error[3 * d_j] + L[jA];
      Phi[i + 3] = L[i + 3] + dt_1[3 * d_j];
      Phi[q_minus_inv_tmp + 3] = L[q_minus_inv_tmp + 3] + dt * 0.0;
      Phi[Phi_tmp + 3] = L[Phi_tmp + 3] + n2;
      jA = 12 * d_j + 1;
      jAcol = 3 * d_j + 1;
      Phi[jA] = L[jA] + dt_0[jAcol];
      Phi[i + 1] = L[i + 1] + dt * 0.0;
      n2 = T_0[jAcol];
      Phi[q_minus_inv_tmp + 1] = L[q_minus_inv_tmp + 1] + n2;
      Phi[Phi_tmp + 1] = L[Phi_tmp + 1] + dt * 0.0;
      jA = 12 * d_j + 4;
      Phi[jA] = L[jA] + Rot_error[jAcol];
      Phi[i + 4] = L[i + 4] + dt_1[jAcol];
      Phi[q_minus_inv_tmp + 4] = L[q_minus_inv_tmp + 4] + dt * 0.0;
      Phi[Phi_tmp + 4] = L[Phi_tmp + 4] + n2;
      jA = 12 * d_j + 2;
      jAcol = 3 * d_j + 2;
      Phi[jA] = L[jA] + dt_0[jAcol];
      Phi[i + 2] = L[i + 2] + dt * 0.0;
      n2 = T_0[jAcol];
      Phi[q_minus_inv_tmp + 2] = L[q_minus_inv_tmp + 2] + n2;
      Phi[Phi_tmp + 2] = L[Phi_tmp + 2] + dt * 0.0;
      jA = 12 * d_j + 5;
      Phi[jA] = L[jA] + Rot_error[jAcol];
      Phi[i + 5] = L[i + 5] + dt_1[jAcol];
      Phi[q_minus_inv_tmp + 5] = L[q_minus_inv_tmp + 5] + dt * 0.0;
      Phi[Phi_tmp + 5] = L[Phi_tmp + 5] + n2;
    }

    for (d_j = 0; d_j < 12; d_j++) {
      i = 12 * d_j + 6;
      Phi[i] = dt * 0.0 + L[i];
      i = 12 * d_j + 9;
      Phi[i] = dt * 0.0 + L[i];
      i = 12 * d_j + 7;
      Phi[i] = dt * 0.0 + L[i];
      i = 12 * d_j + 10;
      Phi[i] = dt * 0.0 + L[i];
      i = 12 * d_j + 8;
      Phi[i] = dt * 0.0 + L[i];
      i = 12 * d_j + 11;
      Phi[i] = dt * 0.0 + L[i];
    }

    for (d_j = 0; d_j < 12; d_j++) {
      for (i = 0; i < 12; i++) {
        n2 = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          n2 += Phi[12 * q_minus_inv_tmp + d_j] * Fullexp_DW.Delay_DSTATE_p[12 *
            i + q_minus_inv_tmp];
        }

        Phi_0[d_j + 12 * i] = n2;
      }

      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += Phi_0[12 * q_minus_inv_tmp + d_j] * Phi[12 * q_minus_inv_tmp
            + i];
        }

        q_minus_inv_tmp = 12 * i + d_j;
        P_k[q_minus_inv_tmp] = Q[q_minus_inv_tmp] + q_mag;
      }
    }

    rEQ0 = false;
    for (i = 0; i < 8; i++) {
      if (!rEQ0) {
        rEQ0 = rtIsNaN(rtb_dq_e[i]);
      }
    }

    if (!rEQ0) {
      q_mag = (Fullexp_rand_p() - 0.5) * 0.1;
      n2 = sin(q_mag);
      q_mag = cos(q_mag);
      yaw_quant = (q_mag + q_mag) + 1.0;
      if (yaw_quant > 0.0) {
        q_mag = sqrt(yaw_quant + 1.0) * 2.0;
        qr_0[0] = 0.25 * q_mag;
        qr_0[1] = 0.0;
        qr_0[2] = 0.0;
        qr_0[3] = (-n2 - n2) / q_mag;
      } else {
        q_mag = sqrt((2.0 - q_mag) - q_mag) * 2.0;
        qr_0[0] = (-n2 - n2) / q_mag;
        qr_0[1] = 0.0 / q_mag;
        qr_0[2] = 0.0 / q_mag;
        qr_0[3] = 0.25 * q_mag;
      }

      yaw_quant = qr_0[0];
      dt_0[0] = 0.0;
      dt_0[3] = -qr_0[3];
      dt_0[6] = qr_0[2];
      dt_0[1] = qr_0[3];
      dt_0[4] = 0.0;
      dt_0[7] = -qr_0[1];
      dt_0[2] = -qr_0[2];
      dt_0[5] = qr_0[1];
      dt_0[8] = 0.0;
      for (d_j = 0; d_j < 3; d_j++) {
        rtb_v_0[d_j] = 0.0 * yaw_quant - ((dt_0[d_j + 3] * 0.0 + dt_0[d_j] * 0.0)
          + dt_0[d_j + 6] * 0.0);
      }

      q_pred[0] = qr_0[0];
      q_pred[1] = qr_0[1];
      q_pred[2] = qr_0[2];
      q_pred[3] = qr_0[3];
      q_pred[4] = -((qr_0[1] * 0.0 + qr_0[2] * 0.0) + qr_0[3] * 0.0);
      q_pred[5] = rtb_v_0[0];
      q_pred[6] = rtb_v_0[1];
      q_pred[7] = rtb_v_0[2];
      Fullexp_dqMultiply(q_pred, rtb_dq_e, z_meas);
    }

    n2 = ((STDQMEKFx[0] * STDQMEKFx[0] + STDQMEKFx[1] * STDQMEKFx[1]) +
          STDQMEKFx[2] * STDQMEKFx[2]) + STDQMEKFx[3] * STDQMEKFx[3];
    q_minus_inv[0] = STDQMEKFx[0] / n2;
    q_minus_inv[1] = -STDQMEKFx[1] / n2;
    q_minus_inv[2] = -STDQMEKFx[2] / n2;
    q_minus_inv[3] = -STDQMEKFx[3] / n2;
    vector[0] = q_minus_inv[1];
    vector[1] = q_minus_inv[2];
    vector[2] = q_minus_inv[3];
    yaw_quant = q_minus_inv[0];
    dt_0[0] = 0.0;
    dt_0[3] = -q_minus_inv[3];
    dt_0[6] = q_minus_inv[2];
    dt_0[1] = q_minus_inv[3];
    dt_0[4] = 0.0;
    dt_0[7] = -q_minus_inv[1];
    dt_0[2] = -q_minus_inv[2];
    dt_0[5] = q_minus_inv[1];
    dt_0[8] = 0.0;
    T[0] = q_minus_inv[0];
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * yaw_quant +
        dt_0[3 * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
    }

    n2 = STDQMEKFx[5];
    q_mag = STDQMEKFx[4];
    yaw_quant = STDQMEKFx[6];
    theta = STDQMEKFx[7];
    for (d_j = 0; d_j < 4; d_j++) {
      qr[d_j] = ((T[d_j + 4] * n2 + T[d_j] * q_mag) + T[d_j + 8] * yaw_quant) +
        T[d_j + 12] * theta;
    }

    vector[0] = qr[1];
    vector[1] = qr[2];
    vector[2] = qr[3];
    yaw_quant = qr[0];
    dt_0[0] = 0.0;
    dt_0[3] = -qr[3];
    dt_0[6] = qr[2];
    dt_0[1] = qr[3];
    dt_0[4] = 0.0;
    dt_0[7] = -qr[1];
    dt_0[2] = -qr[2];
    dt_0[5] = qr[1];
    dt_0[8] = 0.0;
    T[0] = qr[0];
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * yaw_quant +
        dt_0[3 * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
    }

    for (d_j = 0; d_j < 4; d_j++) {
      q_minus_inv_0[d_j] = q_minus_inv[d_j];
      q_minus_inv_0[d_j + 4] = -(((T[d_j + 4] * q_minus_inv[1] + T[d_j] *
        q_minus_inv[0]) + T[d_j + 8] * q_minus_inv[2]) + T[d_j + 12] *
        q_minus_inv[3]);
    }

    Fullexp_dqMultiply(Red_dq, z_meas, tmp_2);
    Fullexp_dqMultiply(q_minus_inv_0, tmp_2, q_pred);
    vector[0] = q_pred[5];
    vector[1] = q_pred[6];
    vector[2] = q_pred[7];
    n2 = 2.0 * acos(q_pred[0]);
    q_mag = sin(n2 / 2.0);
    q_minus_inv[0] = q_pred[1] / q_mag;
    q_minus_inv[1] = q_pred[2] / q_mag;
    q_minus_inv[2] = q_pred[3] / q_mag;
    rEQ0 = rtIsNaN(q_minus_inv[0]);
    if (!rEQ0) {
      rEQ0 = rtIsNaN(q_minus_inv[1]);
    }

    if (!rEQ0) {
      rEQ0 = rtIsNaN(q_minus_inv[2]);
    }

    if (!rEQ0) {
      rEQ0 = rtIsNaN(n2);
    }

    if (rEQ0) {
      Red_q[0] = 1.0;
      Red_q[1] = 0.0;
      Red_q[2] = 0.0;
      Red_q[3] = 0.0;
    } else {
      q_minus_inv[3] = Fullexp_mod(n2 + 3.1415926535897931) - 3.1415926535897931;
      b_vector[0] = q_minus_inv[0];
      b_vector[1] = q_minus_inv[1];
      b_vector[2] = q_minus_inv[2];
      q_mag = Fullexp_norm(b_vector);
      n2 = sin(q_minus_inv[3] / 2.0);
      Red_q[0] = cos(q_minus_inv[3] / 2.0);
      Red_q[1] = q_minus_inv[0] / q_mag * n2;
      Red_q[2] = q_minus_inv[1] / q_mag * n2;
      Red_q[3] = q_minus_inv[2] / q_mag * n2;
    }

    n2 = q_pred[4];
    dt_0[0] = 0.0;
    dt_0[3] = -q_pred[7];
    dt_0[6] = q_pred[6];
    dt_0[1] = q_pred[7];
    dt_0[4] = 0.0;
    dt_0[7] = -q_pred[5];
    dt_0[2] = -q_pred[6];
    dt_0[5] = q_pred[5];
    dt_0[8] = 0.0;
    T[0] = q_pred[4];
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * n2 + dt_0[3 *
        d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) * n2 +
        dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) * n2 +
        dt_0[q_minus_inv_tmp];
    }

    n2 = q_pred[0];
    q_mag = -q_pred[1];
    yaw_quant = -q_pred[2];
    theta = -q_pred[3];
    for (d_j = 0; d_j < 4; d_j++) {
      qr[d_j] = ((T[d_j + 4] * q_mag + T[d_j] * n2) + T[d_j + 8] * yaw_quant) +
        T[d_j + 12] * theta;
    }

    vector[0] = 2.0 * qr[1] * 0.5;
    vector[1] = 2.0 * qr[2] * 0.5;
    vector[2] = 2.0 * qr[3] * 0.5;
    T[0] = 0.0;
    T[4] = -vector[0];
    T[1] = vector[0];
    T[5] = 0.0;
    T[6] = vector[2];
    T[7] = -vector[1];
    T[8] = -vector[1];
    T[2] = vector[1];
    T[9] = -vector[2];
    T[10] = 0.0;
    T[11] = vector[0];
    T[12] = -vector[2];
    T[3] = vector[2];
    T[13] = vector[1];
    T[14] = -vector[0];
    T[15] = 0.0;
    for (d_j = 0; d_j < 4; d_j++) {
      q_pred[d_j] = Red_q[d_j];
      q_pred[d_j + 4] = ((T[d_j + 4] * Red_q[1] + T[d_j] * Red_q[0]) + T[d_j + 8]
                         * Red_q[2]) + T[d_j + 12] * Red_q[3];
    }

    y[0] = q_pred[1];
    y[3] = q_pred[5];
    y[1] = q_pred[2];
    y[4] = q_pred[6];
    y[2] = q_pred[3];
    y[5] = q_pred[7];
    for (d_j = 0; d_j < 6; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += static_cast<real_T>(tmp_6[6 * q_minus_inv_tmp + d_j]) * P_k
            [12 * i + q_minus_inv_tmp];
        }

        H[d_j + 6 * i] = q_mag;
      }

      for (i = 0; i < 6; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += H[6 * q_minus_inv_tmp + d_j] * static_cast<real_T>(tmp_5[12 *
            i + q_minus_inv_tmp]);
        }

        H_0[d_j + 6 * i] = q_mag;
      }
    }

    yaw_quant = 0.0;
    for (d_j = 0; d_j < 3; d_j++) {
      yaw_quant += ((H_0[6 * d_j + 1] * y[1] + H_0[6 * d_j] * y[0]) + H_0[6 *
                    d_j + 2] * y[2]) * y[d_j];
    }

    if (!(sqrt(yaw_quant) < 0.1)) {
      memcpy(&Fullexp_B.x_est_d[0], &STDQMEKFx[0], 14U * sizeof(real_T));
      memcpy(&Fullexp_DW.STDQMEKFP[0], &P_k[0], 144U * sizeof(real_T));
      for (d_j = 0; d_j < 6; d_j++) {
        for (i = 0; i < 6; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += H[6 * q_minus_inv_tmp + d_j] * static_cast<real_T>(tmp_5[12
              * i + q_minus_inv_tmp]);
          }

          q_minus_inv_tmp = 6 * i + d_j;
          Fullexp_B.V_est_n[q_minus_inv_tmp] = R[q_minus_inv_tmp] + q_mag;
        }
      }
    } else {
      memcpy(&Fullexp_B.V_est_n[0], &Fullexp_DW.Delay2_DSTATE_d[0], 36U * sizeof
             (real_T));
      memcpy(&A[0], &Fullexp_DW.Delay2_DSTATE_d[0], 36U * sizeof(real_T));
      Fullexp_xzgetrf(A, ipiv_0, &d_j);
      n2 = A[0];
      rEQ0 = false;
      for (d_j = 0; d_j < 5; d_j++) {
        n2 *= A[((d_j + 1) * 6 + d_j) + 1];
        if (ipiv_0[d_j] > d_j + 1) {
          rEQ0 = !rEQ0;
        }
      }

      if (rEQ0) {
        n2 = -n2;
      }

      if (n2 == 0.0) {
        for (d_j = 0; d_j < 6; d_j++) {
          for (i = 0; i < 6; i++) {
            Fullexp_B.V_est_n[i + 6 * d_j] = y[i] * y[d_j];
          }
        }
      }

      for (d_j = 0; d_j < 6; d_j++) {
        for (i = 0; i < 6; i++) {
          q_minus_inv_tmp = 6 * d_j + i;
          Fullexp_B.V_est_n[q_minus_inv_tmp] =
            (Fullexp_B.V_est_n[q_minus_inv_tmp] * 0.9 + y[i] * y[d_j]) / 1.9;
        }
      }

      Fullexp_lsqnonlin(P_k, Fullexp_B.V_est_n, Lambda_sol);
      memset(&A[0], 0, 36U * sizeof(real_T));
      for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
        A[q_minus_inv_tmp + 6 * q_minus_inv_tmp] = Lambda_sol[q_minus_inv_tmp];
      }

      memset(&H_0[0], 0, 36U * sizeof(real_T));
      for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
        H_0[q_minus_inv_tmp + 6 * q_minus_inv_tmp] = Lambda_sol[q_minus_inv_tmp];
      }

      memset(&L[0], 0, 144U * sizeof(real_T));
      for (d_j = 0; d_j < 6; d_j++) {
        for (i = 0; i < 6; i++) {
          q_minus_inv_tmp = 6 * d_j + i;
          L[i + 12 * d_j] = A[q_minus_inv_tmp];
          L[(i + 12 * (d_j + 6)) + 6] = H_0[q_minus_inv_tmp];
        }
      }

      for (d_j = 0; d_j < 12; d_j++) {
        for (i = 0; i < 12; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += L[12 * q_minus_inv_tmp + i] * P_k[12 * d_j +
              q_minus_inv_tmp];
          }

          Phi[i + 12 * d_j] = q_mag;
        }
      }

      for (d_j = 0; d_j < 12; d_j++) {
        for (i = 0; i < 12; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += Phi[12 * q_minus_inv_tmp + d_j] * L[12 * i +
              q_minus_inv_tmp];
          }

          P_k[d_j + 12 * i] = q_mag;
        }

        for (i = 0; i < 6; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += P_k[12 * q_minus_inv_tmp + d_j] * static_cast<real_T>
              (tmp_5[12 * i + q_minus_inv_tmp]);
          }

          K[d_j + 12 * i] = q_mag;
        }
      }

      for (d_j = 0; d_j < 6; d_j++) {
        for (i = 0; i < 12; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += static_cast<real_T>(tmp_6[6 * q_minus_inv_tmp + d_j]) *
              P_k[12 * i + q_minus_inv_tmp];
          }

          H[d_j + 6 * i] = q_mag;
        }

        for (i = 0; i < 6; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += H[6 * q_minus_inv_tmp + d_j] * static_cast<real_T>(tmp_5[12
              * i + q_minus_inv_tmp]);
          }

          q_minus_inv_tmp = 6 * i + d_j;
          H_0[q_minus_inv_tmp] = R[q_minus_inv_tmp] + q_mag;
        }
      }

      Fullexp_mrdiv_eg(K, H_0);
      for (d_j = 0; d_j < 12; d_j++) {
        for (i = 0; i < 12; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
            q_mag += K[12 * q_minus_inv_tmp + i] * static_cast<real_T>(tmp_6[6 *
              d_j + q_minus_inv_tmp]);
          }

          L[i + 12 * d_j] = q_mag;
        }
      }

      for (d_j = 0; d_j < 144; d_j++) {
        Phi[d_j] = static_cast<real_T>(DQMEKFP_tmp_1[d_j]) - L[d_j];
      }

      for (d_j = 0; d_j < 12; d_j++) {
        for (i = 0; i < 12; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += Phi[12 * q_minus_inv_tmp + d_j] * P_k[12 * i +
              q_minus_inv_tmp];
          }

          Phi_tmp = 12 * i + d_j;
          Phi_0[Phi_tmp] = q_mag;
          q_minus_inv_tmp = 12 * d_j + i;
          DQMEKFP_tmp_0[q_minus_inv_tmp] = DQMEKFP_tmp[q_minus_inv_tmp] -
            L[Phi_tmp];
        }

        for (i = 0; i < 6; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
            q_mag += K[12 * q_minus_inv_tmp + d_j] * R[6 * i + q_minus_inv_tmp];
          }

          H[d_j + 12 * i] = q_mag;
        }
      }

      for (d_j = 0; d_j < 12; d_j++) {
        for (i = 0; i < 12; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += Phi_0[12 * q_minus_inv_tmp + d_j] * DQMEKFP_tmp_0[12 * i +
              q_minus_inv_tmp];
          }

          Phi_tmp = 12 * i + d_j;
          Phi[Phi_tmp] = q_mag;
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
            q_mag += H[12 * q_minus_inv_tmp + d_j] * K[12 * q_minus_inv_tmp + i];
          }

          P_k[Phi_tmp] = q_mag;
        }
      }

      for (d_j = 0; d_j < 144; d_j++) {
        Fullexp_DW.STDQMEKFP[d_j] = Phi[d_j] + P_k[d_j];
      }

      for (d_j = 0; d_j < 12; d_j++) {
        q_mag = 0.0;
        for (i = 0; i < 6; i++) {
          q_mag += K[12 * i + d_j] * y[i];
        }

        rtb_x_k[d_j] = q_mag;
      }

      rtb_v_0[0] = rtb_x_k[0];
      rtb_v_0[1] = rtb_x_k[1];
      rtb_v_0[2] = rtb_x_k[2];
      n2 = Fullexp_norm(rtb_v_0);
      if (n2 <= 1.0) {
        n2 = sqrt(1.0 - n2 * n2);
        q_minus_inv[0] = n2;
        q_minus_inv[1] = rtb_x_k[0];
        Red_q[1] = rtb_x_k[3];
        q_minus_inv[2] = rtb_x_k[1];
        Red_q[2] = rtb_x_k[4];
        q_minus_inv[3] = rtb_x_k[2];
        Red_q[3] = rtb_x_k[5];
        Red_q[0] = -((rtb_x_k[0] * rtb_x_k[3] + rtb_x_k[1] * rtb_x_k[4]) +
                     rtb_x_k[2] * rtb_x_k[5]) / n2;
      } else {
        q_mag = sqrt(n2 * n2 + 1.0);
        n2 = 1.0 / q_mag;
        q_minus_inv[0] = n2;
        q_minus_inv[1] = rtb_x_k[0] * n2;
        Red_q[1] = rtb_x_k[3];
        q_minus_inv[2] = rtb_x_k[1] * n2;
        Red_q[2] = rtb_x_k[4];
        q_minus_inv[3] = rtb_x_k[2] * n2;
        Red_q[3] = rtb_x_k[5];
        Red_q[0] = -((rtb_x_k[0] * rtb_x_k[3] + rtb_x_k[1] * rtb_x_k[4]) +
                     rtb_x_k[2] * rtb_x_k[5]) * q_mag;
      }

      z_meas[0] = STDQMEKFx[0];
      z_meas[4] = STDQMEKFx[4];
      q_minus_inv_0[0] = q_minus_inv[0];
      q_minus_inv_0[4] = Red_q[0];
      z_meas[1] = STDQMEKFx[1];
      z_meas[5] = STDQMEKFx[5];
      q_minus_inv_0[1] = q_minus_inv[1];
      q_minus_inv_0[5] = Red_q[1];
      z_meas[2] = STDQMEKFx[2];
      z_meas[6] = STDQMEKFx[6];
      q_minus_inv_0[2] = q_minus_inv[2];
      q_minus_inv_0[6] = Red_q[2];
      z_meas[3] = STDQMEKFx[3];
      z_meas[7] = STDQMEKFx[7];
      q_minus_inv_0[3] = q_minus_inv[3];
      q_minus_inv_0[7] = Red_q[3];
      Fullexp_dqMultiply(z_meas, q_minus_inv_0, q_pred);
      Fullexp_B.x_est_d[0] = q_pred[0];
      Fullexp_B.x_est_d[4] = q_pred[4];
      Fullexp_B.x_est_d[1] = q_pred[1];
      Fullexp_B.x_est_d[5] = q_pred[5];
      Fullexp_B.x_est_d[2] = q_pred[2];
      Fullexp_B.x_est_d[6] = q_pred[6];
      Fullexp_B.x_est_d[3] = q_pred[3];
      Fullexp_B.x_est_d[7] = q_pred[7];
      Fullexp_B.x_est_d[8] = rtb_x_k[6] + STDQMEKFx[8];
      Fullexp_B.x_est_d[11] = rtb_x_k[9] + STDQMEKFx[11];
      Fullexp_B.x_est_d[9] = rtb_x_k[7] + STDQMEKFx[9];
      Fullexp_B.x_est_d[12] = rtb_x_k[10] + STDQMEKFx[12];
      Fullexp_B.x_est_d[10] = rtb_x_k[8] + STDQMEKFx[10];
      Fullexp_B.x_est_d[13] = rtb_x_k[11] + STDQMEKFx[13];
    }

    n2 = Fullexp_toc_m(&savedTime_o2);

    // DataStoreWrite: '<S22>/Data Store Write17'
    memcpy(&STDQMEKFx[0], &Fullexp_B.x_est_d[0], 14U * sizeof(real_T));

    // MATLAB Function: '<S23>/MATLAB Function1' incorporates:
    //   DataStoreRead: '<S23>/Data Store Read3'
    //   DataStoreRead: '<S23>/Data Store Read4'
    //   DataStoreWrite: '<S23>/Data Store Write18'
    //   Delay: '<S23>/Delay'
    //   Delay: '<S23>/Delay1'
    //   Delay: '<S23>/Delay2'

    z[0] = rtb_q_f[0];
    z[1] = rtb_q_f[1];
    z[2] = rtb_q_f[2];
    z[3] = rtb_q_f[3];
    z[4] = Fullexp_DW.Vis_x[0];
    z[5] = Fullexp_DW.Vis_x[1];
    z[6] = Fullexp_DW.Vis_x[2];
    Fullexp_tic_g(&savedTime_os);
    memcpy(&STQMEKFx[0], &Fullexp_DW.Delay1_DSTATE_er[0], 13U * sizeof(real_T));
    memcpy(&Fullexp_B.V_est[0], &Fullexp_DW.Delay2_DSTATE_p[0], 36U * sizeof
           (real_T));
    q_mag = Fullexp_norm(&Fullexp_DW.Delay1_DSTATE_er[4]);
    if (q_mag > 1.0E-10) {
      theta = q_mag * dt / 2.0;
      yaw_quant = sin(theta);
      qr[0] = cos(theta);
      qr[1] = Fullexp_DW.Delay1_DSTATE_er[4] / q_mag * yaw_quant;
      qr[2] = Fullexp_DW.Delay1_DSTATE_er[5] / q_mag * yaw_quant;
      qr[3] = Fullexp_DW.Delay1_DSTATE_er[6] / q_mag * yaw_quant;
    } else {
      qr[0] = 1.0;
      qr[1] = 0.0;
      qr[2] = 0.0;
      qr[3] = 0.0;
    }

    vector[0] = qr[1];
    vector[1] = qr[2];
    vector[2] = qr[3];
    yaw_quant = qr[0];
    dt_0[0] = 0.0;
    dt_0[3] = -qr[3];
    dt_0[6] = qr[2];
    dt_0[1] = qr[3];
    dt_0[4] = 0.0;
    dt_0[7] = -qr[1];
    dt_0[2] = -qr[2];
    dt_0[5] = qr[1];
    dt_0[8] = 0.0;
    T[0] = qr[0];
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * yaw_quant +
        dt_0[3 * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
    }

    q_mag = Fullexp_DW.Delay1_DSTATE_er[1];
    yaw_quant = Fullexp_DW.Delay1_DSTATE_er[0];
    theta = Fullexp_DW.Delay1_DSTATE_er[2];
    dt_tmp = Fullexp_DW.Delay1_DSTATE_er[3];
    for (d_j = 0; d_j < 4; d_j++) {
      x_k[d_j] = ((T[d_j + 4] * q_mag + T[d_j] * yaw_quant) + T[d_j + 8] * theta)
        + T[d_j + 12] * dt_tmp;
    }

    tmp_3[0] = -0.0 * dt;
    tmp_3[9] = Fullexp_DW.Delay1_DSTATE_er[6] / 2.0 * dt;
    tmp_3[18] = -Fullexp_DW.Delay1_DSTATE_er[5] / 2.0 * dt;
    tmp_3[1] = -Fullexp_DW.Delay1_DSTATE_er[6] / 2.0 * dt;
    tmp_3[10] = -0.0 * dt;
    tmp_3[19] = Fullexp_DW.Delay1_DSTATE_er[4] / 2.0 * dt;
    tmp_3[2] = Fullexp_DW.Delay1_DSTATE_er[5] / 2.0 * dt;
    tmp_3[11] = -Fullexp_DW.Delay1_DSTATE_er[4] / 2.0 * dt;
    tmp_3[20] = -0.0 * dt;
    for (d_j = 0; d_j < 3; d_j++) {
      x_k[d_j + 4] = Fullexp_DW.Delay1_DSTATE_er[d_j + 4];
      q_mag = Fullexp_DW.Delay1_DSTATE_er[d_j + 10];
      x_k[d_j + 7] = Fullexp_DW.Delay1_DSTATE_er[d_j + 7] + q_mag * dt;
      x_k[d_j + 10] = q_mag;
      i = (d_j + 3) * 9;
      tmp_3[i] = Phi_m_tmp[3 * d_j];
      q_minus_inv_tmp = (d_j + 6) * 9;
      tmp_3[q_minus_inv_tmp] = 0.0 * dt;
      tmp_3[i + 1] = Phi_m_tmp[3 * d_j + 1];
      tmp_3[q_minus_inv_tmp + 1] = 0.0 * dt;
      tmp_3[i + 2] = Phi_m_tmp[3 * d_j + 2];
      tmp_3[q_minus_inv_tmp + 2] = 0.0 * dt;
    }

    for (d_j = 0; d_j < 9; d_j++) {
      tmp_3[9 * d_j + 3] = Phi_m_tmp_0[3 * d_j];
      tmp_3[9 * d_j + 6] = Phi_m_tmp_1[3 * d_j];
      i = 3 * d_j + 1;
      tmp_3[9 * d_j + 4] = Phi_m_tmp_0[i];
      tmp_3[9 * d_j + 7] = Phi_m_tmp_1[i];
      i = 3 * d_j + 2;
      tmp_3[9 * d_j + 5] = Phi_m_tmp_0[i];
      tmp_3[9 * d_j + 8] = Phi_m_tmp_1[i];
    }

    Fullexp_expm(tmp_3, Phi_m);
    for (d_j = 0; d_j < 6; d_j++) {
      L[12 * d_j] = Phi_m[9 * d_j];
      L[12 * d_j + 1] = Phi_m[9 * d_j + 1];
      L[12 * d_j + 2] = Phi_m[9 * d_j + 2];
    }

    for (d_j = 0; d_j < 3; d_j++) {
      q_minus_inv_tmp = (d_j + 6) * 12;
      L[q_minus_inv_tmp] = 0.0;
      i = (d_j + 9) * 12;
      L[i] = 0.0;
      L[q_minus_inv_tmp + 1] = 0.0;
      L[i + 1] = 0.0;
      L[q_minus_inv_tmp + 2] = 0.0;
      L[i + 2] = 0.0;
    }

    for (d_j = 0; d_j < 12; d_j++) {
      L[12 * d_j + 3] = F_tmp_0[3 * d_j];
      L[12 * d_j + 4] = F_tmp_0[3 * d_j + 1];
      L[12 * d_j + 5] = F_tmp_0[3 * d_j + 2];
    }

    for (d_j = 0; d_j < 3; d_j++) {
      L[12 * d_j + 6] = 0.0;
      q_minus_inv_tmp = (d_j + 3) * 12;
      L[q_minus_inv_tmp + 6] = 0.0;
      i = (d_j + 6) * 12;
      L[i + 6] = dq_corr_dual_tmp[3 * d_j];
      Phi_tmp = (d_j + 9) * 12;
      L[Phi_tmp + 6] = Phi_m_tmp[3 * d_j];
      L[12 * d_j + 7] = 0.0;
      L[q_minus_inv_tmp + 7] = 0.0;
      jA = 3 * d_j + 1;
      L[i + 7] = dq_corr_dual_tmp[jA];
      L[Phi_tmp + 7] = Phi_m_tmp[jA];
      L[12 * d_j + 8] = 0.0;
      L[q_minus_inv_tmp + 8] = 0.0;
      q_minus_inv_tmp = 3 * d_j + 2;
      L[i + 8] = dq_corr_dual_tmp[q_minus_inv_tmp];
      L[Phi_tmp + 8] = Phi_m_tmp[q_minus_inv_tmp];
    }

    for (d_j = 0; d_j < 12; d_j++) {
      L[12 * d_j + 9] = F_tmp[3 * d_j];
      L[12 * d_j + 10] = F_tmp[3 * d_j + 1];
      L[12 * d_j + 11] = F_tmp[3 * d_j + 2];
    }

    for (d_j = 0; d_j < 12; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += L[12 * q_minus_inv_tmp + d_j] * Fullexp_DW.Delay_DSTATE_l[12 *
            i + q_minus_inv_tmp];
        }

        Phi[d_j + 12 * i] = q_mag;
      }

      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += Phi[12 * q_minus_inv_tmp + d_j] * L[12 * q_minus_inv_tmp + i];
        }

        q_minus_inv_tmp = 12 * i + d_j;
        P_k[q_minus_inv_tmp] = Q[q_minus_inv_tmp] + q_mag;
      }
    }

    for (i = 0; i < 7; i++) {
      z_bar[i] = 0.0 * z[i];
    }

    vector[0] = rtb_Atan2_n;
    vector[1] = qr_idx_2_tmp;
    vector[2] = qr_idx_3_tmp;
    dt_0[0] = 0.0;
    dt_0[3] = -qr_idx_3_tmp;
    dt_0[6] = qr_idx_2_tmp;
    dt_0[1] = qr_idx_3_tmp;
    dt_0[4] = 0.0;
    dt_0[7] = -rtb_Atan2_n;
    dt_0[2] = -qr_idx_2_tmp;
    dt_0[5] = rtb_Atan2_n;
    dt_0[8] = 0.0;
    T[0] = rtb_TSamp_n5;
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * rtb_TSamp_n5 +
        dt_0[3 * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        rtb_TSamp_n5 + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        rtb_TSamp_n5 + dt_0[q_minus_inv_tmp];
      dq_corr_dual[d_j + 1] = x_k[d_j + 7] - Chaser_tmp[d_j + 4];
    }

    q_mag = dq_corr_dual[1];
    yaw_quant = dq_corr_dual[2];
    theta = dq_corr_dual[3];
    for (d_j = 0; d_j < 4; d_j++) {
      Red_q[d_j] = ((T[d_j + 4] * q_mag + T[d_j] * 0.0) + T[d_j + 8] * yaw_quant)
        + T[d_j + 12] * theta;
    }

    vector[0] = Red_q[1];
    vector[1] = Red_q[2];
    vector[2] = Red_q[3];
    theta = Red_q[0];
    dt_0[0] = 0.0;
    dt_0[3] = -Red_q[3];
    dt_0[6] = Red_q[2];
    dt_0[1] = Red_q[3];
    dt_0[4] = 0.0;
    dt_0[7] = -Red_q[1];
    dt_0[2] = -Red_q[2];
    dt_0[5] = Red_q[1];
    dt_0[8] = 0.0;
    dq_corr_dual_0[0] = Red_q[0];
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      dq_corr_dual_0[i] = -q_mag;
      dq_corr_dual_0[d_j + 1] = q_mag;
      dq_corr_dual_0[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) *
        theta + dt_0[3 * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      dq_corr_dual_0[i + 2] = static_cast<real_T>
        (dq_corr_dual_tmp[q_minus_inv_tmp]) * theta + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      dq_corr_dual_0[i + 3] = static_cast<real_T>
        (dq_corr_dual_tmp[q_minus_inv_tmp]) * theta + dt_0[q_minus_inv_tmp];
    }

    for (d_j = 0; d_j < 4; d_j++) {
      Red_q[d_j] = ((dq_corr_dual_0[d_j + 4] * qr_idx_1_tmp + dq_corr_dual_0[d_j]
                     * rtb_TSamp_o) + dq_corr_dual_0[d_j + 8] * qr_idx_2_tmp_0)
        + dq_corr_dual_0[d_j + 12] * qr_idx_3_tmp_0;
    }

    vector[0] = x_k[1];
    vector[1] = x_k[2];
    vector[2] = x_k[3];
    yaw_quant = x_k[0];
    dt_0[0] = 0.0;
    dt_0[3] = -x_k[3];
    dt_0[6] = x_k[2];
    dt_0[1] = x_k[3];
    dt_0[4] = 0.0;
    dt_0[7] = -x_k[1];
    dt_0[2] = -x_k[2];
    dt_0[5] = x_k[1];
    dt_0[8] = 0.0;
    T[0] = x_k[0];
    for (d_j = 0; d_j < 3; d_j++) {
      z_bar[d_j + 4] = Red_q[d_j + 1];
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * yaw_quant +
        dt_0[3 * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
    }

    for (d_j = 0; d_j < 4; d_j++) {
      z_bar[d_j] = ((T[d_j + 4] * rtb_Atan2_n + T[d_j] * rtb_TSamp_n5) + T[d_j +
                    8] * qr_idx_2_tmp) + T[d_j + 12] * qr_idx_3_tmp;
    }

    Fullexp_smallQuat(&z_bar[0], Red_q);
    yaw_quant = rt_roundd_snf(Fullexp_mod(2.0 * rt_atan2d_snf(Red_q[3], Red_q[0]))
      / 0.049087385212340517) * 0.049087385212340517 + Fullexp_rand_k() * 1.0E-5;
    for (d_j = 0; d_j < 12; d_j++) {
      H[6 * d_j] = H_tmp[3 * d_j];
      H[6 * d_j + 1] = H_tmp[3 * d_j + 1];
      H[6 * d_j + 2] = H_tmp[3 * d_j + 2];
    }

    H[39] = H_tmp_5;
    H[45] = H_tmp_6;
    H[51] = H_tmp_2;
    H[40] = H_tmp_0;
    H[46] = H_tmp_1;
    H[52] = H_tmp_7;
    H[41] = H_tmp_2;
    H[47] = H_tmp_3;
    H[53] = H_tmp_4;
    for (d_j = 0; d_j < 3; d_j++) {
      H[6 * d_j + 3] = 0.0;
      q_minus_inv_tmp = (d_j + 3) * 6;
      H[q_minus_inv_tmp + 3] = 0.0;
      i = (d_j + 9) * 6;
      H[i + 3] = 0.0;
      H[6 * d_j + 4] = 0.0;
      H[q_minus_inv_tmp + 4] = 0.0;
      H[i + 4] = 0.0;
      H[6 * d_j + 5] = 0.0;
      H[q_minus_inv_tmp + 5] = 0.0;
      H[i + 5] = 0.0;
    }

    rEQ0 = false;
    for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 7; q_minus_inv_tmp++) {
      if (!rEQ0) {
        rEQ0 = rtIsNaN(z[q_minus_inv_tmp]);
      }
    }

    if (!rEQ0) {
      Fullexp_rand_k();
      q_mag = Fullexp_norm(axis);
      theta = 0.0 / q_mag * 0.024997395914712332;
      q_mag = 1.0 / q_mag * 0.024997395914712332;
      vector[0] = theta;
      vector[1] = theta;
      vector[2] = q_mag;
      dt_0[0] = 0.0;
      dt_0[3] = -q_mag;
      dt_0[6] = theta;
      dt_0[1] = q_mag;
      dt_0[4] = 0.0;
      dt_0[7] = -theta;
      dt_0[2] = -theta;
      dt_0[5] = theta;
      dt_0[8] = 0.0;
      T[0] = 0.99968751627570263;
      for (d_j = 0; d_j < 3; d_j++) {
        q_mag = vector[d_j];
        i = (d_j + 1) << 2;
        T[i] = -q_mag;
        T[d_j + 1] = q_mag;
        T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) *
          0.99968751627570263 + dt_0[3 * d_j];
        q_minus_inv_tmp = 3 * d_j + 1;
        T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
          0.99968751627570263 + dt_0[q_minus_inv_tmp];
        q_minus_inv_tmp = 3 * d_j + 2;
        T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
          0.99968751627570263 + dt_0[q_minus_inv_tmp];
      }

      q_mag = z[1];
      theta = z[0];
      dt_tmp = z[2];
      n2_tmp_0 = z[3];
      for (d_j = 0; d_j < 4; d_j++) {
        dq_corr_dual[d_j] = ((T[d_j + 4] * q_mag + T[d_j] * theta) + T[d_j + 8] *
                             dt_tmp) + T[d_j + 12] * n2_tmp_0;
      }

      z[0] = dq_corr_dual[0];
      z[1] = dq_corr_dual[1];
      z[2] = dq_corr_dual[2];
      z[3] = dq_corr_dual[3];
    }

    vector[0] = z[1];
    vector[1] = z[2];
    vector[2] = z[3];
    theta = z[0];
    dt_0[0] = 0.0;
    dt_0[3] = -z[3];
    dt_0[6] = z[2];
    dt_0[1] = z[3];
    dt_0[4] = 0.0;
    dt_0[7] = -z[1];
    dt_0[2] = -z[2];
    dt_0[5] = z[1];
    dt_0[8] = 0.0;
    T[0] = z[0];
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * theta + dt_0[3
        * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) * theta
        + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) * theta
        + dt_0[q_minus_inv_tmp];
    }

    q_mag = cos(yaw_quant / 2.0);
    yaw_quant = -sin(yaw_quant / 2.0);
    for (d_j = 0; d_j < 4; d_j++) {
      q_minus_inv[d_j] = ((T[d_j + 4] * -0.0 + T[d_j] * q_mag) + T[d_j + 8] *
                          -0.0) + T[d_j + 12] * yaw_quant;
    }

    Fullexp_smallQuat(q_minus_inv, qr);
    y[0] = qr[1] / (qr[0] + 1.0);
    y[1] = qr[2] / (qr[0] + 1.0);
    y[2] = qr[3] / (qr[0] + 1.0);
    y[3] = z[4] - z_bar[4];
    y[4] = z[5] - z_bar[5];
    y[5] = z[6] - z_bar[6];
    rEQ0 = rtIsNaN(z[0]);
    if (!rEQ0) {
      rEQ0 = rtIsNaN(z[1]);
    }

    if (!rEQ0) {
      rEQ0 = rtIsNaN(z[2]);
    }

    if (!rEQ0) {
      rEQ0 = rtIsNaN(z[3]);
    }

    if (rEQ0) {
      rEQ0 = true;
    } else {
      for (d_j = 0; d_j < 3; d_j++) {
        for (i = 0; i < 12; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += H[6 * q_minus_inv_tmp + d_j] * P_k[12 * i + q_minus_inv_tmp];
          }

          H_0[d_j + 3 * i] = q_mag;
        }

        for (i = 0; i < 3; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += H_0[3 * q_minus_inv_tmp + d_j] * H[6 * q_minus_inv_tmp + i];
          }

          Rot_error[d_j + 3 * i] = q_mag;
        }
      }

      yaw_quant = 0.0;
      for (d_j = 0; d_j < 3; d_j++) {
        yaw_quant += ((Rot_error[3 * d_j + 1] * y[1] + Rot_error[3 * d_j] * y[0])
                      + Rot_error[3 * d_j + 2] * y[2]) * y[d_j];
      }

      rEQ0 = !(sqrt(yaw_quant) < 0.03);
    }

    rejectPose = rtIsNaN(z[4]);
    if (!rejectPose) {
      rejectPose = rtIsNaN(z[5]);
    }

    if (!rejectPose) {
      rejectPose = rtIsNaN(z[6]);
    }

    if (rejectPose) {
      rejectPose = true;
    } else {
      for (d_j = 0; d_j < 3; d_j++) {
        for (i = 0; i < 12; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += H[(6 * q_minus_inv_tmp + d_j) + 3] * P_k[12 * i +
              q_minus_inv_tmp];
          }

          H_0[d_j + 3 * i] = q_mag;
        }

        for (i = 0; i < 3; i++) {
          q_mag = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
            q_mag += H[(6 * q_minus_inv_tmp + i) + 3] * H_0[3 * q_minus_inv_tmp
              + d_j];
          }

          Rot_error[d_j + 3 * i] = q_mag;
        }
      }

      yaw_quant = 0.0;
      for (d_j = 0; d_j < 3; d_j++) {
        yaw_quant += ((Rot_error[3 * d_j + 1] * y[4] + Rot_error[3 * d_j] * y[3])
                      + Rot_error[3 * d_j + 2] * y[5]) * y[d_j + 3];
      }

      rejectPose = !(sqrt(yaw_quant) < 0.1);
    }

    if (rEQ0) {
      y[0] = 0.0;
      y[1] = 0.0;
      y[2] = 0.0;
      for (d_j = 0; d_j < 12; d_j++) {
        H[6 * d_j] = 0.0;
        H[6 * d_j + 1] = 0.0;
        H[6 * d_j + 2] = 0.0;
      }
    }

    if (rejectPose) {
      y[3] = 0.0;
      y[4] = 0.0;
      y[5] = 0.0;
      for (d_j = 0; d_j < 12; d_j++) {
        H[6 * d_j + 3] = 0.0;
        H[6 * d_j + 4] = 0.0;
        H[6 * d_j + 5] = 0.0;
      }
    }

    memcpy(&A[0], &Fullexp_DW.Delay2_DSTATE_p[0], 36U * sizeof(real_T));
    Fullexp_xzgetrf(A, ipiv_0, &d_j);
    dt = A[0];
    rEQ0 = false;
    for (i = 0; i < 5; i++) {
      dt *= A[((i + 1) * 6 + i) + 1];
      if (ipiv_0[i] > i + 1) {
        rEQ0 = !rEQ0;
      }
    }

    if (rEQ0) {
      dt = -dt;
    }

    if (dt == 0.0) {
      for (d_j = 0; d_j < 6; d_j++) {
        for (i = 0; i < 6; i++) {
          Fullexp_B.V_est[i + 6 * d_j] = y[i] * y[d_j];
        }
      }
    }

    for (d_j = 0; d_j < 6; d_j++) {
      for (i = 0; i < 6; i++) {
        q_minus_inv_tmp = 6 * d_j + i;
        Fullexp_B.V_est[q_minus_inv_tmp] = (Fullexp_B.V_est[q_minus_inv_tmp] *
          0.9 + y[i] * y[d_j]) / 1.9;
      }
    }

    Fullexp_lsqnonlin_k(P_k, H, Fullexp_B.V_est, Lambda_sol);
    memset(&T_0[0], 0, 9U * sizeof(real_T));
    T_0[0] = Lambda_sol[0];
    T_0[4] = Lambda_sol[1];
    T_0[8] = Lambda_sol[2];
    memset(&dt_0[0], 0, 9U * sizeof(real_T));
    dt_0[0] = Lambda_sol[0];
    dt_0[4] = Lambda_sol[1];
    dt_0[8] = Lambda_sol[2];
    memset(&Phi_m_tmp[0], 0, 9U * sizeof(real_T));
    Phi_m_tmp[0] = Lambda_sol[3];
    varargin_4[0] = Lambda_sol[3];
    Phi_m_tmp[4] = Lambda_sol[4];
    varargin_4[4] = Lambda_sol[4];
    Phi_m_tmp[8] = Lambda_sol[5];
    varargin_4[8] = Lambda_sol[5];
    memset(&L[0], 0, 144U * sizeof(real_T));
    for (d_j = 0; d_j < 3; d_j++) {
      L[12 * d_j] = T_0[3 * d_j];
      q_minus_inv_tmp = (d_j + 3) * 12;
      L[q_minus_inv_tmp + 3] = dt_0[3 * d_j];
      i = (d_j + 6) * 12;
      L[i + 6] = Phi_m_tmp[3 * d_j];
      Phi_tmp = (d_j + 9) * 12;
      L[Phi_tmp + 9] = varargin_4[3 * d_j];
      jA = 3 * d_j + 1;
      L[12 * d_j + 1] = T_0[jA];
      L[q_minus_inv_tmp + 4] = dt_0[jA];
      L[i + 7] = Phi_m_tmp[jA];
      L[Phi_tmp + 10] = varargin_4[jA];
      jA = 3 * d_j + 2;
      L[12 * d_j + 2] = T_0[jA];
      L[q_minus_inv_tmp + 5] = dt_0[jA];
      L[i + 8] = Phi_m_tmp[jA];
      L[Phi_tmp + 11] = varargin_4[jA];
    }

    for (d_j = 0; d_j < 12; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += L[12 * q_minus_inv_tmp + i] * P_k[12 * d_j + q_minus_inv_tmp];
        }

        Phi[i + 12 * d_j] = q_mag;
      }
    }

    for (d_j = 0; d_j < 12; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += Phi[12 * q_minus_inv_tmp + i] * L[12 * d_j + q_minus_inv_tmp];
        }

        P_k[i + 12 * d_j] = q_mag;
      }
    }

    for (d_j = 0; d_j < 6; d_j++) {
      for (i = 0; i < 12; i++) {
        Phi_tmp = 6 * i + d_j;
        K[i + 12 * d_j] = H[Phi_tmp];
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += H[6 * q_minus_inv_tmp + d_j] * P_k[12 * i + q_minus_inv_tmp];
        }

        H_1[Phi_tmp] = q_mag;
      }
    }

    for (d_j = 0; d_j < 6; d_j++) {
      for (i = 0; i < 6; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += H_1[6 * q_minus_inv_tmp + d_j] * K[12 * i + q_minus_inv_tmp];
        }

        q_minus_inv_tmp = 6 * i + d_j;
        H_0[q_minus_inv_tmp] = R[q_minus_inv_tmp] + q_mag;
      }
    }

    for (d_j = 0; d_j < 6; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += P_k[12 * q_minus_inv_tmp + i] * K[12 * d_j + q_minus_inv_tmp];
        }

        H_1[i + 12 * d_j] = q_mag;
      }
    }

    memcpy(&K[0], &H_1[0], 72U * sizeof(real_T));
    Fullexp_mrdiv_eg(K, H_0);
    for (d_j = 0; d_j < 12; d_j++) {
      for (i = 0; i < 12; i++) {
        dt = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
          dt += K[12 * q_minus_inv_tmp + i] * H[6 * d_j + q_minus_inv_tmp];
        }

        L[i + 12 * d_j] = dt;
      }
    }

    for (d_j = 0; d_j < 144; d_j++) {
      Phi[d_j] = static_cast<real_T>(DQMEKFP_tmp_1[d_j]) - L[d_j];
    }

    for (d_j = 0; d_j < 12; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += Phi[12 * q_minus_inv_tmp + d_j] * P_k[12 * i +
            q_minus_inv_tmp];
        }

        Phi_tmp = 12 * i + d_j;
        Phi_0[Phi_tmp] = q_mag;
        q_minus_inv_tmp = 12 * d_j + i;
        DQMEKFP_tmp_0[q_minus_inv_tmp] = DQMEKFP_tmp[q_minus_inv_tmp] -
          L[Phi_tmp];
      }

      for (i = 0; i < 6; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
          q_mag += K[12 * q_minus_inv_tmp + d_j] * R[6 * i + q_minus_inv_tmp];
        }

        H[d_j + 12 * i] = q_mag;
      }
    }

    for (d_j = 0; d_j < 12; d_j++) {
      for (i = 0; i < 12; i++) {
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 12; q_minus_inv_tmp++) {
          q_mag += Phi_0[12 * q_minus_inv_tmp + d_j] * DQMEKFP_tmp_0[12 * i +
            q_minus_inv_tmp];
        }

        Phi_tmp = 12 * i + d_j;
        DQMEKFP_tmp[Phi_tmp] = q_mag;
        q_mag = 0.0;
        for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 6; q_minus_inv_tmp++) {
          q_mag += H[12 * q_minus_inv_tmp + d_j] * K[12 * q_minus_inv_tmp + i];
        }

        P_k[Phi_tmp] = q_mag;
      }
    }

    for (d_j = 0; d_j < 144; d_j++) {
      Fullexp_DW.STQMEKFP[d_j] = DQMEKFP_tmp[d_j] + P_k[d_j];
    }

    for (d_j = 0; d_j < 12; d_j++) {
      q_mag = 0.0;
      for (i = 0; i < 6; i++) {
        q_mag += K[12 * i + d_j] * y[i];
      }

      rtb_x_k[d_j] = q_mag;
    }

    q_mag = Fullexp_norm(&rtb_x_k[0]);
    q_mag *= q_mag;
    yaw_quant = (sqrt(q_mag * 0.0 + 1.0) - q_mag) / (q_mag + 1.0);
    theta = (yaw_quant + 1.0) * rtb_x_k[0];
    q_mag = (yaw_quant + 1.0) * rtb_x_k[1];
    dt_tmp = (yaw_quant + 1.0) * rtb_x_k[2];
    vector[0] = theta;
    vector[1] = q_mag;
    vector[2] = dt_tmp;
    dt_0[0] = 0.0;
    dt_0[3] = -dt_tmp;
    dt_0[6] = q_mag;
    dt_0[1] = dt_tmp;
    dt_0[4] = 0.0;
    dt_0[7] = -theta;
    dt_0[2] = -q_mag;
    dt_0[5] = theta;
    dt_0[8] = 0.0;
    T[0] = yaw_quant;
    for (d_j = 0; d_j < 3; d_j++) {
      q_mag = vector[d_j];
      i = (d_j + 1) << 2;
      T[i] = -q_mag;
      T[d_j + 1] = q_mag;
      T[i + 1] = static_cast<real_T>(dq_corr_dual_tmp[3 * d_j]) * yaw_quant +
        dt_0[3 * d_j];
      q_minus_inv_tmp = 3 * d_j + 1;
      T[i + 2] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
      q_minus_inv_tmp = 3 * d_j + 2;
      T[i + 3] = static_cast<real_T>(dq_corr_dual_tmp[q_minus_inv_tmp]) *
        yaw_quant + dt_0[q_minus_inv_tmp];
    }

    yaw_quant = x_k[1];
    q_mag = x_k[0];
    theta = x_k[2];
    dt_tmp = x_k[3];
    for (d_j = 0; d_j < 4; d_j++) {
      STQMEKFx[d_j] = ((T[d_j + 4] * yaw_quant + T[d_j] * q_mag) + T[d_j + 8] *
                       theta) + T[d_j + 12] * dt_tmp;
    }

    for (i = 0; i < 9; i++) {
      STQMEKFx[i + 4] = x_k[i + 4] + rtb_x_k[i + 3];
    }

    memcpy(&Fullexp_B.x_est[0], &STQMEKFx[0], 13U * sizeof(real_T));
    dt = Fullexp_toc_k(&savedTime_os);

    // DataStoreWrite: '<S23>/Data Store Write17'
    memcpy(&STQMEKFx[0], &Fullexp_B.x_est[0], 13U * sizeof(real_T));

    // DataStoreWrite: '<S25>/Data Store Write' incorporates:
    //   Constant: '<S25>/Constant'

    Fullexp_DW.isSim = Fullexp_P.simMode;

    // If: '<S1>/Separate Phases' incorporates:
    //   Constant: '<S1>/Constant'
    //   Constant: '<S1>/Constant1'
    //   Constant: '<S1>/Constant2'
    //   Constant: '<S1>/Constant3'
    //   Constant: '<S1>/Constant4'
    //   Constant: '<S1>/Constant6'
    //   DataStoreRead: '<S1>/Universal_Time25'

    if (Fullexp_DW.Univ_Time < Fullexp_P.Phase0_End) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #0: Synchronization' incorporates:
      //   ActionPort: '<S27>/Action Port'

      Fullexp_Phase0Synchronization(&Fullexp_DW.ARM_Control_Law_Enabler,
        &rtb_TSamp_o, &Fullexp_DW.BLACK_Control_Law_Enabler,
        &Fullexp_DW.BLACK_Path_Planner_Selection,
        &Fullexp_DW.BLUE_Control_Law_Enabler, &rtb_TSamp_n5,
        &Fullexp_DW.Float_State, &Fullexp_DW.RED_Control_Law_Enabler,
        Fullexp_DW.RED_Logger, &Fullexp_DW.RED_Path_Planner_Selection,
        &Fullexp_P.Phase0Synchronization);

      // End of Outputs for SubSystem: '<S1>/Phase #0: Synchronization'
    } else if ((Fullexp_DW.Univ_Time < Fullexp_P.Phase1_End) &&
               (Fullexp_DW.Univ_Time >= Fullexp_P.Phase0_End)) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #1: Start Floating ' incorporates:
      //   ActionPort: '<S28>/Action Port'

      Fullexp_Phase0Synchronization(&Fullexp_DW.ARM_Control_Law_Enabler,
        &rtb_TSamp_o, &Fullexp_DW.BLACK_Control_Law_Enabler,
        &Fullexp_DW.BLACK_Path_Planner_Selection,
        &Fullexp_DW.BLUE_Control_Law_Enabler, &rtb_TSamp_n5,
        &Fullexp_DW.Float_State, &Fullexp_DW.RED_Control_Law_Enabler,
        Fullexp_DW.RED_Logger, &Fullexp_DW.RED_Path_Planner_Selection,
        &Fullexp_P.Phase1StartFloating);

      // End of Outputs for SubSystem: '<S1>/Phase #1: Start Floating '
    } else if ((Fullexp_DW.Univ_Time < Fullexp_P.Phase2_End) &&
               (Fullexp_DW.Univ_Time >= Fullexp_P.Phase1_End)) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #2: Initial Position' incorporates:
      //   ActionPort: '<S29>/Action Port'

      // DataStoreWrite: '<S29>/Data Store Write24' incorporates:
      //   Constant: '<S29>/Constant11'

      Fullexp_DW.RED_Path_Planner_Selection = Fullexp_P.Constant11_Value;

      // DataStoreWrite: '<S29>/Data Store Write23' incorporates:
      //   Constant: '<S29>/Constant14'

      Fullexp_DW.BLACK_Path_Planner_Selection = Fullexp_P.Constant14_Value;

      // DataStoreWrite: '<S29>/Data Store Write27' incorporates:
      //   Constant: '<S29>/Constant18'

      Fullexp_DW.ARM_Control_Law_Enabler = Fullexp_P.Constant18_Value;

      // DataStoreWrite: '<S29>/Data Store Write4' incorporates:
      //   Constant: '<S29>/Constant4'

      Fullexp_DW.BLACK_Control_Law_Enabler = Fullexp_P.Constant4_Value;

      // DataStoreWrite: '<S29>/Data Store Write8' incorporates:
      //   Constant: '<S29>/Constant5'

      Fullexp_DW.RED_Control_Law_Enabler = Fullexp_P.Constant5_Value;

      // DataStoreWrite: '<S29>/Data Store Write7' incorporates:
      //   Constant: '<S29>/Constant6'

      Fullexp_DW.Float_State = Fullexp_P.Constant6_Value;

      // DataStoreWrite: '<S29>/Data Store Write16' incorporates:
      //   Constant: '<S29>/Constant8'

      Fullexp_DW.BLUE_Control_Law_Enabler = Fullexp_P.Constant8_Value;

      // DataStoreWrite: '<S29>/Data Store Write13' incorporates:
      //   Constant: '<S34>/Constant1'
      //   Constant: '<S34>/Constant2'
      //   Constant: '<S34>/Constant3'

      Fullexp_DW.ARM_Desired_States[0] = Fullexp_P.Constant3_Value;
      Fullexp_DW.ARM_Desired_States[1] = Fullexp_P.Constant1_Value;
      Fullexp_DW.ARM_Desired_States[2] = Fullexp_P.Constant2_Value;

      // DataStoreWrite: '<S29>/Data Store Write1' incorporates:
      //   Constant: '<S35>/Desired States (BLACK)'

      Fullexp_DW.BLACK_Desired_States[0] = Fullexp_P.init_states_BLACK[0];

      // DataStoreWrite: '<S29>/Data Store Write18' incorporates:
      //   Constant: '<S36>/Desired States (BLUE)'

      Fullexp_DW.BLUE_Desired_States[0] = Fullexp_P.init_states_BLUE[0];

      // DataStoreWrite: '<S29>/Data Store Write9' incorporates:
      //   Constant: '<S37>/Constant2'

      Fullexp_DW.RED_Desired_States[0] = Fullexp_P.init_states_RED[0];

      // DataStoreWrite: '<S29>/Data Store Write1' incorporates:
      //   Constant: '<S35>/Desired States (BLACK)'

      Fullexp_DW.BLACK_Desired_States[1] = Fullexp_P.init_states_BLACK[1];

      // DataStoreWrite: '<S29>/Data Store Write18' incorporates:
      //   Constant: '<S36>/Desired States (BLUE)'

      Fullexp_DW.BLUE_Desired_States[1] = Fullexp_P.init_states_BLUE[1];

      // DataStoreWrite: '<S29>/Data Store Write9' incorporates:
      //   Constant: '<S37>/Constant2'

      Fullexp_DW.RED_Desired_States[1] = Fullexp_P.init_states_RED[1];

      // DataStoreWrite: '<S29>/Data Store Write1' incorporates:
      //   Constant: '<S35>/Desired States (BLACK)'

      Fullexp_DW.BLACK_Desired_States[2] = Fullexp_P.init_states_BLACK[2];

      // DataStoreWrite: '<S29>/Data Store Write18' incorporates:
      //   Constant: '<S36>/Desired States (BLUE)'

      Fullexp_DW.BLUE_Desired_States[2] = Fullexp_P.init_states_BLUE[2];

      // DataStoreWrite: '<S29>/Data Store Write9' incorporates:
      //   Constant: '<S37>/Constant2'

      Fullexp_DW.RED_Desired_States[2] = Fullexp_P.init_states_RED[2];

      // End of Outputs for SubSystem: '<S1>/Phase #2: Initial Position'
    } else if ((Fullexp_DW.Univ_Time < Fullexp_P.Phase3_End) &&
               (Fullexp_DW.Univ_Time >= Fullexp_P.Phase2_End)) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #3: Experiment' incorporates:
      //   ActionPort: '<S30>/Action Port'

      // If: '<S30>/Experiment Sub-Phases' incorporates:
      //   Constant: '<S30>/Constant1'
      //   Constant: '<S30>/Constant2'
      //   Constant: '<S30>/Constant3'
      //   Constant: '<S30>/Constant4'
      //   DataStoreRead: '<S30>/Universal_Time'

      if (Fullexp_DW.Univ_Time < Fullexp_P.Phase3_SubPhase1_End) {
        // Outputs for IfAction SubSystem: '<S30>/Sub-Phase #1' incorporates:
        //   ActionPort: '<S38>/Action Port'

        // DataStoreWrite: '<S38>/Data Store Write24' incorporates:
        //   Constant: '<S38>/Constant11'

        Fullexp_DW.RED_Path_Planner_Selection = Fullexp_P.Constant11_Value_e;

        // DataStoreWrite: '<S38>/Data Store Write23' incorporates:
        //   Constant: '<S38>/Constant14'

        Fullexp_DW.BLACK_Path_Planner_Selection = Fullexp_P.Constant14_Value_f;

        // DataStoreWrite: '<S38>/Data Store Write2' incorporates:
        //   Constant: '<S38>/Constant18'

        Fullexp_DW.ARM_Control_Law_Enabler = Fullexp_P.Constant18_Value_m;

        // DataStoreWrite: '<S38>/Data Store Write4' incorporates:
        //   Constant: '<S38>/Constant4'

        Fullexp_DW.BLACK_Control_Law_Enabler = Fullexp_P.Constant4_Value_g;

        // DataStoreWrite: '<S38>/Data Store Write3' incorporates:
        //   Constant: '<S38>/Constant5'

        Fullexp_DW.RED_Control_Law_Enabler = Fullexp_P.Constant5_Value_o;

        // DataStoreWrite: '<S38>/Data Store Write7' incorporates:
        //   Constant: '<S38>/Constant6'

        Fullexp_DW.Float_State = Fullexp_P.Constant6_Value_i;

        // DataStoreWrite: '<S38>/Data Store Write16' incorporates:
        //   Constant: '<S38>/Constant8'

        Fullexp_DW.BLUE_Control_Law_Enabler = Fullexp_P.Constant8_Value_m;

        // DataStoreWrite: '<S38>/Data Store Write13' incorporates:
        //   Constant: '<S42>/Constant1'
        //   Constant: '<S42>/Constant2'
        //   Constant: '<S42>/Constant3'

        Fullexp_DW.ARM_Desired_States[0] = Fullexp_P.Constant3_Value_b;
        Fullexp_DW.ARM_Desired_States[1] = Fullexp_P.Constant1_Value_o;
        Fullexp_DW.ARM_Desired_States[2] = Fullexp_P.Constant2_Value_f;

        // Product: '<S44>/Product' incorporates:
        //   Constant: '<S44>/Desired Rate '
        //   Constant: '<S47>/Constant2'
        //   DataStoreRead: '<S49>/Universal_Time'
        //   Sum: '<S47>/Subtract3'

        rtb_TSamp_n5 = (Fullexp_DW.Univ_Time - Fullexp_P.Phase2_End) *
          Fullexp_P.DesiredRate_Value;

        // Trigonometry: '<S46>/Sin' incorporates:
        //   Trigonometry: '<S48>/Sin'

        rtb_TSamp_o = sin(rtb_TSamp_n5);

        // Trigonometry: '<S46>/Cos' incorporates:
        //   Trigonometry: '<S48>/Cos'

        rtb_TSamp_n5 = cos(rtb_TSamp_n5);

        // DataStoreWrite: '<S38>/Data Store Write18' incorporates:
        //   Constant: '<S46>/Constant1'
        //   Constant: '<S46>/Constant2'
        //   Gain: '<S46>/Gain'
        //   Gain: '<S46>/Gain1'
        //   Sum: '<S46>/Sum1'
        //   Sum: '<S46>/Sum2'
        //   Trigonometry: '<S46>/Cos'
        //   Trigonometry: '<S46>/Sin'
        //   Trigonometry: '<S48>/Atan2'

        Fullexp_DW.BLUE_Desired_States[0] = Fullexp_P.Gain_Gain * rtb_TSamp_n5 +
          Fullexp_P.xLength / 2.0;
        Fullexp_DW.BLUE_Desired_States[1] = Fullexp_P.Gain1_Gain * rtb_TSamp_o +
          Fullexp_P.yLength / 2.0;
        Fullexp_DW.BLUE_Desired_States[2] = rt_atan2d_snf(rtb_TSamp_o,
          rtb_TSamp_n5);

        // DataStoreWrite: '<S38>/Data Store Write5' incorporates:
        //   Constant: '<S43>/Constant'
        //   SignalGenerator: '<S43>/Signal Generator'
        //   Sum: '<S43>/Sum'

        Fullexp_DW.BLACK_Desired_States[0] = sin(6.2831853071795862 *
          thrust_decay_factor * Fullexp_P.SignalGenerator_Frequency) *
          Fullexp_P.SignalGenerator_Amplitude + Fullexp_P.init_states_BLACK[0];
        Fullexp_DW.BLACK_Desired_States[1] = Fullexp_P.init_states_BLACK[1];
        Fullexp_DW.BLACK_Desired_States[2] = Fullexp_P.init_states_BLACK[2];

        // DataStoreWrite: '<S38>/Data Store Write9' incorporates:
        //   Constant: '<S45>/Constant'

        Fullexp_DW.RED_Desired_States[0] = Fullexp_P.init_states_RED[0];
        Fullexp_DW.RED_Desired_States[1] = Fullexp_P.init_states_RED[1];
        Fullexp_DW.RED_Desired_States[2] = Fullexp_P.init_states_RED[2];

        // End of Outputs for SubSystem: '<S30>/Sub-Phase #1'
      } else if ((Fullexp_DW.Univ_Time < Fullexp_P.Phase3_SubPhase2_End) &&
                 (Fullexp_DW.Univ_Time >= Fullexp_P.Phase3_SubPhase1_End)) {
        // Outputs for IfAction SubSystem: '<S30>/Sub-Phase #2 ' incorporates:
        //   ActionPort: '<S39>/Action Port'

        // DataStoreWrite: '<S39>/Data Store Write24' incorporates:
        //   Constant: '<S39>/Constant11'

        Fullexp_DW.RED_Path_Planner_Selection = Fullexp_P.Constant11_Value_m;

        // DataStoreWrite: '<S39>/Data Store Write23' incorporates:
        //   Constant: '<S39>/Constant14'

        Fullexp_DW.BLACK_Path_Planner_Selection = Fullexp_P.Constant14_Value_i;

        // DataStoreWrite: '<S39>/Data Store Write2' incorporates:
        //   Constant: '<S39>/Constant18'

        Fullexp_DW.ARM_Control_Law_Enabler = Fullexp_P.Constant18_Value_n;

        // DataStoreWrite: '<S39>/Data Store Write4' incorporates:
        //   Constant: '<S39>/Constant4'

        Fullexp_DW.BLACK_Control_Law_Enabler = Fullexp_P.Constant4_Value_a;

        // DataStoreWrite: '<S39>/Data Store Write3' incorporates:
        //   Constant: '<S39>/Constant5'

        Fullexp_DW.RED_Control_Law_Enabler = Fullexp_P.Constant5_Value_m;

        // DataStoreWrite: '<S39>/Data Store Write7' incorporates:
        //   Constant: '<S39>/Constant6'

        Fullexp_DW.Float_State = Fullexp_P.Constant6_Value_p;

        // DataStoreWrite: '<S39>/Data Store Write16' incorporates:
        //   Constant: '<S39>/Constant8'

        Fullexp_DW.BLUE_Control_Law_Enabler = Fullexp_P.Constant8_Value_o;

        // DataStoreWrite: '<S39>/Data Store Write13' incorporates:
        //   Constant: '<S50>/Constant1'
        //   Constant: '<S50>/Constant2'
        //   Constant: '<S50>/Constant3'

        Fullexp_DW.ARM_Desired_States[0] = Fullexp_P.Constant3_Value_p;
        Fullexp_DW.ARM_Desired_States[1] = Fullexp_P.Constant1_Value_m;
        Fullexp_DW.ARM_Desired_States[2] = Fullexp_P.Constant2_Value_p;

        // Sum: '<S58>/Subtract3' incorporates:
        //   Constant: '<S58>/Constant2'
        //   DataStoreRead: '<S60>/Universal_Time'
        //   Sum: '<S56>/Subtract'

        rtb_Atan2_n = Fullexp_DW.Univ_Time - Fullexp_P.Phase2_End;

        // Product: '<S52>/Product' incorporates:
        //   Constant: '<S52>/Desired Rate '
        //   Sum: '<S58>/Subtract3'

        rtb_TSamp_n5 = rtb_Atan2_n * Fullexp_P.DesiredRate_Value_h;

        // Trigonometry: '<S57>/Sin' incorporates:
        //   Trigonometry: '<S59>/Sin'

        rtb_TSamp_o = sin(rtb_TSamp_n5);

        // Trigonometry: '<S57>/Cos' incorporates:
        //   Trigonometry: '<S59>/Cos'

        rtb_TSamp_n5 = cos(rtb_TSamp_n5);

        // DataStoreWrite: '<S39>/Data Store Write18' incorporates:
        //   Constant: '<S57>/Constant1'
        //   Constant: '<S57>/Constant2'
        //   Gain: '<S57>/Gain'
        //   Gain: '<S57>/Gain1'
        //   Sum: '<S57>/Sum1'
        //   Sum: '<S57>/Sum2'
        //   Trigonometry: '<S57>/Cos'
        //   Trigonometry: '<S57>/Sin'
        //   Trigonometry: '<S59>/Atan2'

        Fullexp_DW.BLUE_Desired_States[0] = Fullexp_P.Gain_Gain_h * rtb_TSamp_n5
          + Fullexp_P.xLength / 2.0;
        Fullexp_DW.BLUE_Desired_States[1] = Fullexp_P.Gain1_Gain_c * rtb_TSamp_o
          + Fullexp_P.yLength / 2.0;
        Fullexp_DW.BLUE_Desired_States[2] = rt_atan2d_snf(rtb_TSamp_o,
          rtb_TSamp_n5);

        // Product: '<S54>/Product' incorporates:
        //   Constant: '<S54>/Desired Rate (BLACK)'

        rtb_TSamp_o = rtb_Atan2_n * Fullexp_P.DesiredRateBLACK_Value;

        // DataStoreWrite: '<S39>/Data Store Write5' incorporates:
        //   Constant: '<S51>/Desired X-Position (BLACK)'
        //   Constant: '<S51>/Desired Y-Position (BLACK)'
        //   Trigonometry: '<S55>/Atan2'
        //   Trigonometry: '<S55>/Cos'
        //   Trigonometry: '<S55>/Sin'

        Fullexp_DW.BLACK_Desired_States[0] = Fullexp_P.xLength / 2.0;
        Fullexp_DW.BLACK_Desired_States[1] = Fullexp_P.yLength / 2.0;
        Fullexp_DW.BLACK_Desired_States[2] = rt_atan2d_snf(sin(rtb_TSamp_o), cos
          (rtb_TSamp_o));

        // DataStoreWrite: '<S39>/Data Store Write9' incorporates:
        //   Constant: '<S53>/Constant'
        //   Constant: '<S53>/Constant1'
        //   Constant: '<S53>/Constant4'

        Fullexp_DW.RED_Desired_States[0] = Fullexp_P.init_states_RED[0];
        Fullexp_DW.RED_Desired_States[1] = Fullexp_P.init_states_RED[1];
        Fullexp_DW.RED_Desired_States[2] = Fullexp_P.init_states_RED[2];

        // End of Outputs for SubSystem: '<S30>/Sub-Phase #2 '
      } else if ((Fullexp_DW.Univ_Time < Fullexp_P.Phase3_SubPhase3_End) &&
                 (Fullexp_DW.Univ_Time >= Fullexp_P.Phase3_SubPhase2_End)) {
        // Outputs for IfAction SubSystem: '<S30>/Sub-Phase #3 ' incorporates:
        //   ActionPort: '<S40>/Action Port'

        // DataStoreWrite: '<S40>/Data Store Write24' incorporates:
        //   Constant: '<S40>/Constant11'

        Fullexp_DW.RED_Path_Planner_Selection = Fullexp_P.Constant11_Value_b;

        // DataStoreWrite: '<S40>/Data Store Write23' incorporates:
        //   Constant: '<S40>/Constant14'

        Fullexp_DW.BLACK_Path_Planner_Selection = Fullexp_P.Constant14_Value_n;

        // DataStoreWrite: '<S40>/Data Store Write2' incorporates:
        //   Constant: '<S40>/Constant18'

        Fullexp_DW.ARM_Control_Law_Enabler = Fullexp_P.Constant18_Value_l;

        // DataStoreWrite: '<S40>/Data Store Write4' incorporates:
        //   Constant: '<S40>/Constant4'

        Fullexp_DW.BLACK_Control_Law_Enabler = Fullexp_P.Constant4_Value_b;

        // DataStoreWrite: '<S40>/Data Store Write3' incorporates:
        //   Constant: '<S40>/Constant5'

        Fullexp_DW.RED_Control_Law_Enabler = Fullexp_P.Constant5_Value_n;

        // DataStoreWrite: '<S40>/Data Store Write7' incorporates:
        //   Constant: '<S40>/Constant6'

        Fullexp_DW.Float_State = Fullexp_P.Constant6_Value_n;

        // DataStoreWrite: '<S40>/Data Store Write16' incorporates:
        //   Constant: '<S40>/Constant8'

        Fullexp_DW.BLUE_Control_Law_Enabler = Fullexp_P.Constant8_Value_f;

        // DataStoreWrite: '<S40>/Data Store Write13' incorporates:
        //   Constant: '<S61>/Constant1'
        //   Constant: '<S61>/Constant2'
        //   Constant: '<S61>/Constant3'

        Fullexp_DW.ARM_Desired_States[0] = Fullexp_P.Constant3_Value_e;
        Fullexp_DW.ARM_Desired_States[1] = Fullexp_P.Constant1_Value_p;
        Fullexp_DW.ARM_Desired_States[2] = Fullexp_P.Constant2_Value_c;

        // Sum: '<S66>/Subtract3' incorporates:
        //   Constant: '<S66>/Constant2'
        //   DataStoreRead: '<S68>/Universal_Time'
        //   Sum: '<S72>/Subtract'

        rtb_Atan2_n = Fullexp_DW.Univ_Time - Fullexp_P.Phase2_End;

        // Product: '<S62>/Product' incorporates:
        //   Constant: '<S62>/Desired Rate '
        //   Sum: '<S66>/Subtract3'

        rtb_TSamp_n5 = rtb_Atan2_n * Fullexp_P.DesiredRate_Value_l;

        // Trigonometry: '<S65>/Sin' incorporates:
        //   Trigonometry: '<S67>/Sin'

        rtb_TSamp_o = sin(rtb_TSamp_n5);

        // Trigonometry: '<S65>/Cos' incorporates:
        //   Trigonometry: '<S67>/Cos'

        rtb_TSamp_n5 = cos(rtb_TSamp_n5);

        // DataStoreWrite: '<S40>/Data Store Write18' incorporates:
        //   Constant: '<S65>/Constant1'
        //   Constant: '<S65>/Constant2'
        //   Gain: '<S65>/Gain'
        //   Gain: '<S65>/Gain1'
        //   Sum: '<S65>/Sum1'
        //   Sum: '<S65>/Sum2'
        //   Trigonometry: '<S65>/Cos'
        //   Trigonometry: '<S65>/Sin'
        //   Trigonometry: '<S67>/Atan2'

        Fullexp_DW.BLUE_Desired_States[0] = Fullexp_P.Gain_Gain_b * rtb_TSamp_n5
          + Fullexp_P.xLength / 2.0;
        Fullexp_DW.BLUE_Desired_States[1] = Fullexp_P.Gain1_Gain_k * rtb_TSamp_o
          + Fullexp_P.yLength / 2.0;
        Fullexp_DW.BLUE_Desired_States[2] = rt_atan2d_snf(rtb_TSamp_o,
          rtb_TSamp_n5);

        // Sum: '<S64>/Subtract' incorporates:
        //   Constant: '<S64>/Constant'

        theta = thrust_decay_factor - Fullexp_P.Phase3_SubPhase2_End;

        // MATLAB Function: '<S64>/MATLAB Function'
        if (!(theta <= 60.0)) {
          theta = 60.0;
        }

        if (theta <= 0.0) {
          theta = 0.0;
        }

        if (theta <= 30.0) {
          q_mag = (1.0 - cos(theta / 30.0 * 3.1415926535897931)) / 4.0;
        } else {
          q_mag = (1.0 - cos((theta - 30.0) / 30.0 * 3.1415926535897931)) / 4.0
            + 0.5;
        }

        rtb_TSamp_o = rt_powd_snf(1.0 - q_mag, 3.0);
        rtb_TSamp_n5 = rt_powd_snf(q_mag, 3.0);

        // Product: '<S69>/Product' incorporates:
        //   Constant: '<S69>/Desired Rate (BLACK)'

        rtb_Atan2_n *= Fullexp_P.DesiredRateBLACK_Value_c;

        // MATLAB Function: '<S64>/MATLAB Function'
        qr_idx_2_tmp = (1.0 - q_mag) * (1.0 - q_mag) * 3.0 * q_mag;
        qr_idx_3_tmp = (1.0 - q_mag) * 3.0 * (q_mag * q_mag);

        // DataStoreWrite: '<S40>/Data Store Write5' incorporates:
        //   MATLAB Function: '<S64>/MATLAB Function'
        //   Trigonometry: '<S71>/Atan2'
        //   Trigonometry: '<S71>/Cos'
        //   Trigonometry: '<S71>/Sin'

        Fullexp_DW.BLACK_Desired_States[0] = ((qr_idx_2_tmp * 2.0 + rtb_TSamp_o *
          2.0) + qr_idx_3_tmp * 0.4) + rtb_TSamp_n5 * 0.4;
        Fullexp_DW.BLACK_Desired_States[1] = ((rtb_TSamp_o * 2.0 + qr_idx_2_tmp)
          + qr_idx_3_tmp) + rtb_TSamp_n5 * 0.4;
        Fullexp_DW.BLACK_Desired_States[2] = rt_atan2d_snf(sin(rtb_Atan2_n), cos
          (rtb_Atan2_n));

        // DataStoreWrite: '<S40>/Data Store Write9' incorporates:
        //   Constant: '<S63>/Constant'

        Fullexp_DW.RED_Desired_States[0] = Fullexp_P.init_states_RED[0];
        Fullexp_DW.RED_Desired_States[1] = Fullexp_P.init_states_RED[1];
        Fullexp_DW.RED_Desired_States[2] = Fullexp_P.init_states_RED[2];

        // End of Outputs for SubSystem: '<S30>/Sub-Phase #3 '
      } else if ((Fullexp_DW.Univ_Time < Fullexp_P.Phase3_SubPhase4_End) &&
                 (Fullexp_DW.Univ_Time >= Fullexp_P.Phase3_SubPhase3_End)) {
        // Outputs for IfAction SubSystem: '<S30>/Sub-Phase #4' incorporates:
        //   ActionPort: '<S41>/Action Port'

        // DataStoreWrite: '<S41>/Data Store Write24' incorporates:
        //   Constant: '<S41>/Constant11'

        Fullexp_DW.RED_Path_Planner_Selection = Fullexp_P.Constant11_Value_p;

        // DataStoreWrite: '<S41>/Data Store Write23' incorporates:
        //   Constant: '<S41>/Constant14'

        Fullexp_DW.BLACK_Path_Planner_Selection = Fullexp_P.Constant14_Value_f2;

        // DataStoreWrite: '<S41>/Data Store Write2' incorporates:
        //   Constant: '<S41>/Constant18'

        Fullexp_DW.ARM_Control_Law_Enabler = Fullexp_P.Constant18_Value_e;

        // DataStoreWrite: '<S41>/Data Store Write4' incorporates:
        //   Constant: '<S41>/Constant4'

        Fullexp_DW.BLACK_Control_Law_Enabler = Fullexp_P.Constant4_Value_l;

        // DataStoreWrite: '<S41>/Data Store Write3' incorporates:
        //   Constant: '<S41>/Constant5'

        Fullexp_DW.RED_Control_Law_Enabler = Fullexp_P.Constant5_Value_p;

        // DataStoreWrite: '<S41>/Data Store Write7' incorporates:
        //   Constant: '<S41>/Constant6'

        Fullexp_DW.Float_State = Fullexp_P.Constant6_Value_m;

        // DataStoreWrite: '<S41>/Data Store Write16' incorporates:
        //   Constant: '<S41>/Constant8'

        Fullexp_DW.BLUE_Control_Law_Enabler = Fullexp_P.Constant8_Value_j;

        // DataStoreWrite: '<S41>/Data Store Write13' incorporates:
        //   Constant: '<S73>/Constant1'
        //   Constant: '<S73>/Constant2'
        //   Constant: '<S73>/Constant3'

        Fullexp_DW.ARM_Desired_States[0] = Fullexp_P.Constant3_Value_k;
        Fullexp_DW.ARM_Desired_States[1] = Fullexp_P.Constant1_Value_b;
        Fullexp_DW.ARM_Desired_States[2] = Fullexp_P.Constant2_Value_g;

        // Product: '<S75>/Product' incorporates:
        //   Constant: '<S75>/Desired Rate '
        //   Constant: '<S78>/Constant2'
        //   DataStoreRead: '<S80>/Universal_Time'
        //   Sum: '<S78>/Subtract3'

        rtb_TSamp_n5 = (Fullexp_DW.Univ_Time - Fullexp_P.Phase2_End) *
          Fullexp_P.DesiredRate_Value_ha;

        // Trigonometry: '<S77>/Sin' incorporates:
        //   Trigonometry: '<S79>/Sin'

        rtb_TSamp_o = sin(rtb_TSamp_n5);

        // Trigonometry: '<S77>/Cos' incorporates:
        //   Trigonometry: '<S79>/Cos'

        rtb_TSamp_n5 = cos(rtb_TSamp_n5);

        // DataStoreWrite: '<S41>/Data Store Write18' incorporates:
        //   Constant: '<S77>/Constant1'
        //   Constant: '<S77>/Constant2'
        //   Gain: '<S77>/Gain'
        //   Gain: '<S77>/Gain1'
        //   Sum: '<S77>/Sum1'
        //   Sum: '<S77>/Sum2'
        //   Trigonometry: '<S77>/Cos'
        //   Trigonometry: '<S77>/Sin'
        //   Trigonometry: '<S79>/Atan2'

        Fullexp_DW.BLUE_Desired_States[0] = Fullexp_P.Gain_Gain_o * rtb_TSamp_n5
          + Fullexp_P.xLength / 2.0;
        Fullexp_DW.BLUE_Desired_States[1] = Fullexp_P.Gain1_Gain_b * rtb_TSamp_o
          + Fullexp_P.yLength / 2.0;
        Fullexp_DW.BLUE_Desired_States[2] = rt_atan2d_snf(rtb_TSamp_o,
          rtb_TSamp_n5);

        // DataStoreWrite: '<S41>/Data Store Write5' incorporates:
        //   Constant: '<S74>/Constant'

        Fullexp_DW.BLACK_Desired_States[0] = Fullexp_P.home_states_BLACK[0];

        // DataStoreWrite: '<S41>/Data Store Write9' incorporates:
        //   Constant: '<S76>/Constant'

        Fullexp_DW.RED_Desired_States[0] = Fullexp_P.home_states_RED[0];

        // DataStoreWrite: '<S41>/Data Store Write5' incorporates:
        //   Constant: '<S74>/Constant'

        Fullexp_DW.BLACK_Desired_States[1] = Fullexp_P.home_states_BLACK[1];

        // DataStoreWrite: '<S41>/Data Store Write9' incorporates:
        //   Constant: '<S76>/Constant'

        Fullexp_DW.RED_Desired_States[1] = Fullexp_P.home_states_RED[1];

        // DataStoreWrite: '<S41>/Data Store Write5' incorporates:
        //   Constant: '<S74>/Constant'

        Fullexp_DW.BLACK_Desired_States[2] = Fullexp_P.home_states_BLACK[2];

        // DataStoreWrite: '<S41>/Data Store Write9' incorporates:
        //   Constant: '<S76>/Constant'

        Fullexp_DW.RED_Desired_States[2] = Fullexp_P.home_states_RED[2];

        // End of Outputs for SubSystem: '<S30>/Sub-Phase #4'
      }

      // End of Outputs for SubSystem: '<S1>/Phase #3: Experiment'
    } else if ((Fullexp_DW.Univ_Time < Fullexp_P.Phase4_End) &&
               (Fullexp_DW.Univ_Time >= Fullexp_P.Phase3_End)) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #4: Return Home' incorporates:
      //   ActionPort: '<S31>/Action Port'

      Fullexp_Phase4ReturnHome(&Fullexp_DW.ARM_Control_Law_Enabler,
        Fullexp_DW.ARM_Desired_States, &rtb_TSamp_o,
        &Fullexp_DW.BLACK_Control_Law_Enabler, Fullexp_DW.BLACK_Desired_States,
        &Fullexp_DW.BLACK_Path_Planner_Selection,
        &Fullexp_DW.BLUE_Control_Law_Enabler, Fullexp_DW.BLUE_Desired_States,
        &rtb_TSamp_n5, &Fullexp_DW.Float_State,
        &Fullexp_DW.RED_Control_Law_Enabler, Fullexp_DW.RED_Desired_States,
        &Fullexp_DW.RED_Path_Planner_Selection, &Fullexp_P.Phase4ReturnHome);

      // End of Outputs for SubSystem: '<S1>/Phase #4: Return Home'
    } else if ((Fullexp_DW.Univ_Time < Fullexp_P.Phase5_End) &&
               (Fullexp_DW.Univ_Time >= Fullexp_P.Phase4_End)) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #5: Hold Home' incorporates:
      //   ActionPort: '<S32>/Action Port'

      Fullexp_Phase4ReturnHome(&Fullexp_DW.ARM_Control_Law_Enabler,
        Fullexp_DW.ARM_Desired_States, &rtb_TSamp_o,
        &Fullexp_DW.BLACK_Control_Law_Enabler, Fullexp_DW.BLACK_Desired_States,
        &Fullexp_DW.BLACK_Path_Planner_Selection,
        &Fullexp_DW.BLUE_Control_Law_Enabler, Fullexp_DW.BLUE_Desired_States,
        &rtb_TSamp_n5, &Fullexp_DW.Float_State,
        &Fullexp_DW.RED_Control_Law_Enabler, Fullexp_DW.RED_Desired_States,
        &Fullexp_DW.RED_Path_Planner_Selection, &Fullexp_P.Phase5HoldHome);

      // End of Outputs for SubSystem: '<S1>/Phase #5: Hold Home'
    } else if (Fullexp_DW.Univ_Time >= Fullexp_P.Phase5_End) {
      // Outputs for IfAction SubSystem: '<S1>/Phase #6: Clean Shutdown' incorporates:
      //   ActionPort: '<S33>/Action Port'

      // DataStoreWrite: '<S33>/Data Store Write2' incorporates:
      //   Constant: '<S33>/Constant1'

      Fullexp_DW.BLACK_Control_Law_Enabler = Fullexp_P.Constant1_Value_n;

      // DataStoreWrite: '<S33>/Data Store Write3' incorporates:
      //   Constant: '<S33>/Constant2'

      Fullexp_DW.BLUE_Control_Law_Enabler = Fullexp_P.Constant2_Value_a;

      // DataStoreWrite: '<S33>/Data Store Write7' incorporates:
      //   Constant: '<S33>/Constant3'

      Fullexp_DW.RED_Path_Planner_Selection = Fullexp_P.Constant3_Value_d;

      // DataStoreWrite: '<S33>/Data Store Write' incorporates:
      //   Constant: '<S33>/Constant5'

      Fullexp_DW.RED_Control_Law_Enabler = Fullexp_P.Constant5_Value_ph;

      // DataStoreWrite: '<S33>/Data Store Write6' incorporates:
      //   Constant: '<S33>/Constant6'

      Fullexp_DW.BLACK_Path_Planner_Selection = Fullexp_P.Constant6_Value_d;

      // DataStoreWrite: '<S33>/Data Store Write9' incorporates:
      //   Constant: '<S33>/Constant8'

      Fullexp_DW.ARM_Control_Law_Enabler = Fullexp_P.Constant8_Value_h;

      // DataStoreWrite: '<S33>/Data Store Write4' incorporates:
      //   Constant: '<S33>/Puck State'

      Fullexp_DW.Float_State = Fullexp_P.PuckState_Value;

      // End of Outputs for SubSystem: '<S1>/Phase #6: Clean Shutdown'
    }

    // If: '<S4>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
    //   DataStoreRead: '<S4>/Data Store Read'
    //   DataStoreRead: '<S4>/Data Store Read1'

    if ((Fullexp_DW.WhoAmI == 2.0) && (Fullexp_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S4>/Change BLACK Behavior' incorporates:
      //   ActionPort: '<S168>/Action Port'

      Fullexp_ChangeBLACKBehavior(Fullexp_M, &Fullexp_DW.ChangeBLACKBehavior,
        &Fullexp_P.ChangeBLACKBehavior);

      // End of Outputs for SubSystem: '<S4>/Change BLACK Behavior'
    }

    // End of If: '<S4>/This IF block determines whether or not to run the BLACK sim//exp' 

    // If: '<S4>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
    //   DataStoreRead: '<S4>/Data Store Read'
    //   DataStoreRead: '<S4>/Data Store Read1'

    if ((Fullexp_DW.WhoAmI == 3.0) && (Fullexp_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S4>/Change BLUE Behavior' incorporates:
      //   ActionPort: '<S169>/Action Port'

      Fullexp_ChangeBLACKBehavior(Fullexp_M, &Fullexp_DW.ChangeBLUEBehavior,
        &Fullexp_P.ChangeBLUEBehavior);

      // End of Outputs for SubSystem: '<S4>/Change BLUE Behavior'
    }

    // End of If: '<S4>/This IF block determines whether or not to run the BLUE sim//exp' 

    // If: '<S4>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   DataStoreRead: '<S4>/Data Store Read'
    //   DataStoreRead: '<S4>/Data Store Read1'

    if ((Fullexp_DW.WhoAmI == 1.0) && (Fullexp_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S4>/Change RED Behavior' incorporates:
      //   ActionPort: '<S170>/Action Port'

      Fullexp_ChangeBLACKBehavior(Fullexp_M, &Fullexp_DW.ChangeREDBehavior,
        &Fullexp_P.ChangeREDBehavior);

      // End of Outputs for SubSystem: '<S4>/Change RED Behavior'
    }

    // End of If: '<S4>/This IF block determines whether or not to run the RED sim//exp ' 

    // MATLABSystem: '<S172>/MATLAB System' incorporates:
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
    //   DataStoreRead: '<S6>/Data Store Read2'
    //   DataStoreRead: '<S6>/Data Store Read21'
    //   DataStoreRead: '<S6>/Data Store Read22'
    //   DataStoreRead: '<S6>/Data Store Read23'
    //   DataStoreRead: '<S6>/Data Store Read24'
    //   DataStoreRead: '<S6>/Data Store Read25'
    //   DataStoreRead: '<S6>/Data Store Read26'
    //   DataStoreRead: '<S6>/Data Store Read27'
    //   DataStoreRead: '<S6>/Data Store Read28'
    //   DataStoreRead: '<S6>/Data Store Read29'
    //   DataStoreRead: '<S6>/Data Store Read3'
    //   DataStoreRead: '<S6>/Data Store Read30'
    //   DataStoreRead: '<S6>/Data Store Read4'
    //   DataStoreRead: '<S6>/Data Store Read42'
    //   DataStoreRead: '<S6>/Data Store Read43'
    //   DataStoreRead: '<S6>/Data Store Read44'
    //   DataStoreRead: '<S6>/Data Store Read45'
    //   DataStoreRead: '<S6>/Data Store Read5'
    //   DataStoreRead: '<S6>/Data Store Read57'
    //   DataStoreRead: '<S6>/Data Store Read6'
    //   DataStoreRead: '<S6>/Data Store Read61'
    //   DataStoreRead: '<S6>/Data Store Read62'
    //   DataStoreRead: '<S6>/Data Store Read63'
    //   DataStoreRead: '<S6>/Data Store Read64'
    //   DataStoreRead: '<S6>/Data Store Read65'
    //   DataStoreRead: '<S6>/Data Store Read66'
    //   DataStoreRead: '<S6>/Data Store Read67'
    //   DataStoreRead: '<S6>/Data Store Read68'
    //   DataStoreRead: '<S6>/Data Store Read69'
    //   DataStoreRead: '<S6>/Data Store Read70'
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
    //   MATLAB Function: '<S172>/MATLAB Function'
    //   MATLAB Function: '<S23>/MATLAB Function1'
    //   SignalConversion generated from: '<S172>/MATLAB System'

    //         %% Define input properties
    //  Call C-function implementing device output
    Fullexp_B.b_u1[0] = Fullexp_DW.Univ_Time;
    Fullexp_B.b_u1[1] = rtb_w[0];
    Fullexp_B.b_u1[4] = Fullexp_DW.RED_Saturated_Controls[0];
    Fullexp_B.b_u1[2] = rtb_w[1];
    Fullexp_B.b_u1[5] = Fullexp_DW.RED_Saturated_Controls[1];
    Fullexp_B.b_u1[3] = rtb_w[2];
    Fullexp_B.b_u1[6] = Fullexp_DW.RED_Saturated_Controls[2];
    memcpy(&Fullexp_B.b_u1[7], &Fullexp_DW.RED_Measured_States[0], 9U * sizeof
           (real_T));
    Fullexp_B.b_u1[22] = Fullexp_DW.RED_Thruster_ON_Count;
    Fullexp_B.b_u1[23] = Fullexp_DW.RED_Control_Law_Enabler;
    Fullexp_B.b_u1[27] = Fullexp_DW.ARM_Control_Mode;
    Fullexp_B.b_u1[16] = Fullexp_DW.RED_Desired_States[0];
    Fullexp_B.b_u1[19] = Fullexp_DW.RED_IMU_Measurements[0];
    Fullexp_B.b_u1[24] = RED_Path[0];
    Fullexp_B.b_u1[28] = ARM_Controls[0];
    Fullexp_B.b_u1[17] = Fullexp_DW.RED_Desired_States[1];
    Fullexp_B.b_u1[20] = Fullexp_DW.RED_IMU_Measurements[1];
    Fullexp_B.b_u1[25] = RED_Path[1];
    Fullexp_B.b_u1[29] = ARM_Controls[1];
    Fullexp_B.b_u1[18] = Fullexp_DW.RED_Desired_States[2];
    Fullexp_B.b_u1[21] = Fullexp_DW.RED_IMU_Measurements[2];
    Fullexp_B.b_u1[26] = RED_Path[2];
    Fullexp_B.b_u1[30] = ARM_Controls[2];
    for (d_j = 0; d_j < 6; d_j++) {
      Fullexp_B.b_u1[d_j + 31] = Fullexp_DW.ARM_Measured_States[d_j];
    }

    Fullexp_B.b_u1[37] = rtb_Sum6;
    Fullexp_B.b_u1[40] = Fullexp_DW.ARM_Desired_States[0];
    Fullexp_B.b_u1[43] = rtb_x_b[0];
    Fullexp_B.b_u1[46] = Fullexp_DW.BLACK_Saturated_Controls[0];
    Fullexp_B.b_u1[38] = ARM_Path_idx_1;
    Fullexp_B.b_u1[41] = Fullexp_DW.ARM_Desired_States[1];
    Fullexp_B.b_u1[44] = rtb_x_b[1];
    Fullexp_B.b_u1[47] = Fullexp_DW.BLACK_Saturated_Controls[1];
    Fullexp_B.b_u1[39] = ARM_Path_idx_2;
    Fullexp_B.b_u1[42] = Fullexp_DW.ARM_Desired_States[2];
    Fullexp_B.b_u1[45] = rtb_x_b[2];
    Fullexp_B.b_u1[48] = Fullexp_DW.BLACK_Saturated_Controls[2];
    Fullexp_B.b_u1[64] = Fullexp_DW.BLACK_Thruster_ON_Count;
    Fullexp_B.b_u1[65] = Fullexp_DW.BLACK_Control_Law_Enabler;
    Fullexp_B.b_u1[58] = Fullexp_DW.BLACK_Desired_States[0];
    Fullexp_B.b_u1[61] = Fullexp_DW.BLACK_IMU_Measurements[0];
    Fullexp_B.b_u1[66] = BLACK_Path[0];
    Fullexp_B.b_u1[69] = rtb_v[0];
    Fullexp_B.b_u1[72] = Fullexp_DW.BLUE_Saturated_Controls[0];
    Fullexp_B.b_u1[59] = Fullexp_DW.BLACK_Desired_States[1];
    Fullexp_B.b_u1[62] = Fullexp_DW.BLACK_IMU_Measurements[1];
    Fullexp_B.b_u1[67] = BLACK_Path[1];
    Fullexp_B.b_u1[70] = rtb_v[1];
    Fullexp_B.b_u1[73] = Fullexp_DW.BLUE_Saturated_Controls[1];
    Fullexp_B.b_u1[60] = Fullexp_DW.BLACK_Desired_States[2];
    Fullexp_B.b_u1[63] = Fullexp_DW.BLACK_IMU_Measurements[2];
    Fullexp_B.b_u1[68] = BLACK_Path[2];
    Fullexp_B.b_u1[71] = rtb_v[2];
    Fullexp_B.b_u1[74] = Fullexp_DW.BLUE_Saturated_Controls[2];
    for (d_j = 0; d_j < 9; d_j++) {
      Fullexp_B.b_u1[d_j + 49] = Fullexp_DW.BLACK_Measured_States[d_j];
      Fullexp_B.b_u1[d_j + 75] = Fullexp_DW.BLUE_Measured_States[d_j];
    }

    Fullexp_B.b_u1[90] = Fullexp_DW.BLUE_Thruster_ON_Count;
    Fullexp_B.b_u1[91] = Fullexp_DW.BLUE_Control_Law_Enabler;
    Fullexp_B.b_u1[84] = Fullexp_DW.BLUE_Desired_States[0];
    Fullexp_B.b_u1[87] = Fullexp_DW.BLUE_IMU_Measurements[0];
    Fullexp_B.b_u1[92] = BLUE_Path_idx_0;
    Fullexp_B.b_u1[85] = Fullexp_DW.BLUE_Desired_States[1];
    Fullexp_B.b_u1[88] = Fullexp_DW.BLUE_IMU_Measurements[1];
    Fullexp_B.b_u1[93] = BLUE_Path_idx_1;
    Fullexp_B.b_u1[86] = Fullexp_DW.BLUE_Desired_States[2];
    Fullexp_B.b_u1[89] = Fullexp_DW.BLUE_IMU_Measurements[2];
    Fullexp_B.b_u1[94] = BLUE_Path_idx_2;
    Fullexp_B.b_u1[95] = Fullexp_DW.Float_State;
    Fullexp_B.b_u1[96] = Fullexp_DW.WhoAmI;
    Fullexp_B.b_u1[97] = Fullexp_DW.isSim;
    memcpy(&Fullexp_B.b_u1[98], &rtb_dq_e[0], sizeof(real_T) << 3U);
    Fullexp_B.b_u1[106] = rtb_q_f[0];
    Fullexp_B.b_u1[107] = rtb_q_f[1];
    Fullexp_B.b_u1[108] = rtb_q_f[2];
    Fullexp_B.b_u1[109] = rtb_q_f[3];
    memcpy(&Fullexp_B.b_u1[110], &rtb_R_g[0], 9U * sizeof(real_T));
    Fullexp_B.b_u1[119] = Fullexp_DW.Vis_x[0];
    Fullexp_B.b_u1[120] = Fullexp_DW.Vis_x[1];
    Fullexp_B.b_u1[121] = Fullexp_DW.Vis_x[2];
    Fullexp_B.b_u1[122] = Fullexp_DW.Vis_yaw;
    Fullexp_B.b_u1[123] = Fullexp_DW.Conf;
    memcpy(&Fullexp_B.b_u1[124], &QMEKFx[0], 13U * sizeof(real_T));
    memcpy(&Fullexp_B.b_u1[137], &Fullexp_DW.QMEKFP[0], 144U * sizeof(real_T));
    Fullexp_B.b_u1[281] = rtb_TSamp_af;
    memcpy(&Fullexp_B.b_u1[282], &STQMEKFx[0], 13U * sizeof(real_T));
    memcpy(&Fullexp_B.b_u1[295], &Fullexp_DW.STQMEKFP[0], 144U * sizeof(real_T));
    Fullexp_B.b_u1[439] = dt;
    memcpy(&Fullexp_B.b_u1[440], &DQMEKFx[0], 14U * sizeof(real_T));
    memcpy(&Fullexp_B.b_u1[454], &Fullexp_DW.DQMEKFP[0], 144U * sizeof(real_T));
    Fullexp_B.b_u1[598] = rtb_TSamp_k;
    memcpy(&Fullexp_B.b_u1[599], &STDQMEKFx[0], 14U * sizeof(real_T));
    memcpy(&Fullexp_B.b_u1[613], &Fullexp_DW.STDQMEKFP[0], 144U * sizeof(real_T));
    Fullexp_B.b_u1[757] = n2;
    memcpy(&Fullexp_B.b_u1[758], &R_chaser[0], 9U * sizeof(real_T));
    memcpy(&Fullexp_B.b_u1[767], &Fullexp_DW.RMEKFP[0], 144U * sizeof(real_T));
    Fullexp_B.b_u1[911] = Red_yaw;
    for (d_j = 0; d_j < 9; d_j++) {
      Fullexp_B.b_u1[d_j + 912] = Fullexp_DW.RMEKFR[d_j];
      Fullexp_B.b_u1[d_j + 921] = Fullexp_DW.STRMEKFx[d_j];
    }

    memcpy(&Fullexp_B.b_u1[930], &Fullexp_DW.STRMEKFP[0], 144U * sizeof(real_T));
    Fullexp_B.b_u1[1074] = Fullexp_DW.STRMEKFt;
    memcpy(&Fullexp_B.b_u1[1075], &Fullexp_DW.STRMEKFR[0], 9U * sizeof(real_T));
    appendDataToFile(&Fullexp_B.b_u1[0], 1084.0);

    // End of MATLABSystem: '<S172>/MATLAB System'

    // If: '<S7>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
    //   DataStoreRead: '<S7>/Data Store Read'
    //   DataStoreRead: '<S7>/Data Store Read1'

    if ((Fullexp_DW.WhoAmI == 2.0) && (Fullexp_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S7>/Change BLACK Behavior' incorporates:
      //   ActionPort: '<S174>/Action Port'

      // StringToASCII: '<S174>/String to ASCII1' incorporates:
      //   StringConstant: '<S174>/String Constant1'

      strncpy((char_T *)&Fullexp_B.StringtoASCII1[0],
              &Fullexp_P.StringConstant1_String[0], 31U);

      // Update for S-Function (sdspToNetwork): '<S174>/UDP Send1' incorporates:
      //   StringToASCII: '<S174>/String to ASCII1'
      //
      sErr = GetErrorBuffer(&Fullexp_DW.UDPSend1_NetworkLib[0U]);
      LibUpdate_Network(&Fullexp_DW.UDPSend1_NetworkLib[0U],
                        &Fullexp_B.StringtoASCII1[0U], 31);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }

      // End of Update for S-Function (sdspToNetwork): '<S174>/UDP Send1'
      // End of Outputs for SubSystem: '<S7>/Change BLACK Behavior'
    }

    // End of If: '<S7>/This IF block determines whether or not to run the BLACK sim//exp' 

    // If: '<S7>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
    //   DataStoreRead: '<S7>/Data Store Read'
    //   DataStoreRead: '<S7>/Data Store Read1'

    if ((Fullexp_DW.WhoAmI == 3.0) && (Fullexp_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S7>/Change BLUE Behavior' incorporates:
      //   ActionPort: '<S175>/Action Port'

      // StringToASCII: '<S175>/String to ASCII2' incorporates:
      //   StringConstant: '<S175>/String Constant2'

      strncpy((char_T *)&Fullexp_B.StringtoASCII2[0],
              &Fullexp_P.StringConstant2_String[0], 31U);

      // Update for S-Function (sdspToNetwork): '<S175>/UDP Send2' incorporates:
      //   StringToASCII: '<S175>/String to ASCII2'
      //
      sErr = GetErrorBuffer(&Fullexp_DW.UDPSend2_NetworkLib[0U]);
      LibUpdate_Network(&Fullexp_DW.UDPSend2_NetworkLib[0U],
                        &Fullexp_B.StringtoASCII2[0U], 31);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }

      // End of Update for S-Function (sdspToNetwork): '<S175>/UDP Send2'
      // End of Outputs for SubSystem: '<S7>/Change BLUE Behavior'
    }

    // End of If: '<S7>/This IF block determines whether or not to run the BLUE sim//exp' 

    // If: '<S7>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   DataStoreRead: '<S7>/Data Store Read'
    //   DataStoreRead: '<S7>/Data Store Read1'

    if ((Fullexp_DW.WhoAmI == 1.0) && (Fullexp_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S7>/Change RED Behavior' incorporates:
      //   ActionPort: '<S176>/Action Port'

      // StringToASCII: '<S176>/String to ASCII' incorporates:
      //   DataStoreRead: '<S176>/Data Store Read'

      strncpy((char_T *)&Fullexp_B.StringtoASCII[0], &Fullexp_DW.RED_Logger[0],
              31U);

      // Update for S-Function (sdspToNetwork): '<S176>/UDP Send3' incorporates:
      //   StringToASCII: '<S176>/String to ASCII'
      //
      sErr = GetErrorBuffer(&Fullexp_DW.UDPSend3_NetworkLib[0U]);
      LibUpdate_Network(&Fullexp_DW.UDPSend3_NetworkLib[0U],
                        &Fullexp_B.StringtoASCII[0U], 31);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }

      // End of Update for S-Function (sdspToNetwork): '<S176>/UDP Send3'
      // End of Outputs for SubSystem: '<S7>/Change RED Behavior'
    }

    // End of If: '<S7>/This IF block determines whether or not to run the RED sim//exp ' 

    // If: '<S8>/This IF block determines whether or not to run the exp code' incorporates:
    //   DataStoreRead: '<S8>/Data Store Read'
    //   If: '<S9>/This IF block determines whether or not to run the exp code'

    if (Fullexp_DW.isSim == 0.0) {
      // Outputs for IfAction SubSystem: '<S8>/Enable Pucks' incorporates:
      //   ActionPort: '<S177>/Action Port'

      // MATLABSystem: '<S177>/GPIO Write1' incorporates:
      //   DataStoreRead: '<S177>/Data Store Read1'

      if (Fullexp_DW.obj_c.gpioPin != Fullexp_P.GPIOWrite1_gpioPin) {
        Fullexp_DW.obj_c.gpioPin = Fullexp_P.GPIOWrite1_gpioPin;
      }

      if (Fullexp_DW.obj_c.pinDirection != Fullexp_P.GPIOWrite1_pinDirection) {
        Fullexp_DW.obj_c.pinDirection = Fullexp_P.GPIOWrite1_pinDirection;
      }

      //         %% Define input properties
      //  Call C-function implementing device output
      // coder.ceval('export_gpio', obj.gpioPin);
      set_pin_direction(Fullexp_DW.obj_c.gpioPin, Fullexp_DW.obj_c.pinDirection);
      change_gpio_value(Fullexp_DW.obj_c.gpioPin, Fullexp_DW.Float_State);

      // End of MATLABSystem: '<S177>/GPIO Write1'
      // End of Outputs for SubSystem: '<S8>/Enable Pucks'

      // Outputs for IfAction SubSystem: '<S9>/Log Gyro//Accel' incorporates:
      //   ActionPort: '<S178>/Action Port'

      // MATLABSystem: '<S178>/Gyroscope//Accelerometer'
      if (Fullexp_DW.obj.SampleTime != Fullexp_P.GyroscopeAccelerometer_SampleTi)
      {
        Fullexp_DW.obj.SampleTime = Fullexp_P.GyroscopeAccelerometer_SampleTi;
      }

      if (Fullexp_DW.obj.TunablePropsChanged) {
        Fullexp_DW.obj.TunablePropsChanged = false;
      }

      obj = Fullexp_DW.obj.SensorObject->Device;
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

      obj = Fullexp_DW.obj.SensorObject->Device;
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

      Red_x[0] = static_cast<real_T>(static_cast<int16_T>(static_cast<int16_T>
        (b_output[1] << 8) | b_output[0])) * 6.103515625E-5 * 9.81;
      Red_x[1] = static_cast<real_T>(static_cast<int16_T>(static_cast<int16_T>
        (b_output[3] << 8) | b_output[2])) * 6.103515625E-5 * 9.81;
      rtb_Sum6 = static_cast<real_T>(static_cast<int16_T>(static_cast<int16_T>
        (b_output_0[5] << 8) | b_output_0[4])) * 6.6512957317073178E-5;

      // End of MATLABSystem: '<S178>/Gyroscope//Accelerometer'

      // MATLAB Function: '<S178>/Parse IMU Data' incorporates:
      //   DataStoreRead: '<S178>/Data Store Read'

      if (Fullexp_DW.WhoAmI == 1.0) {
        // DataStoreWrite: '<S178>/Data Store Write9'
        Fullexp_DW.RED_IMU_Measurements[0] = Red_x[0];
        Fullexp_DW.RED_IMU_Measurements[1] = Red_x[1];
        Fullexp_DW.RED_IMU_Measurements[2] = rtb_Sum6;

        // DataStoreWrite: '<S178>/Data Store Write10'
        Fullexp_DW.BLACK_IMU_Measurements[0] = 0.0;
        Fullexp_DW.BLACK_IMU_Measurements[1] = 0.0;
        Fullexp_DW.BLACK_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S178>/Data Store Write11'
        Fullexp_DW.BLUE_IMU_Measurements[0] = 0.0;
        Fullexp_DW.BLUE_IMU_Measurements[1] = 0.0;
        Fullexp_DW.BLUE_IMU_Measurements[2] = 0.0;
      } else if (Fullexp_DW.WhoAmI == 2.0) {
        // DataStoreWrite: '<S178>/Data Store Write9'
        Fullexp_DW.RED_IMU_Measurements[0] = 0.0;
        Fullexp_DW.RED_IMU_Measurements[1] = 0.0;
        Fullexp_DW.RED_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S178>/Data Store Write10'
        Fullexp_DW.BLACK_IMU_Measurements[0] = Red_x[0];
        Fullexp_DW.BLACK_IMU_Measurements[1] = Red_x[1];
        Fullexp_DW.BLACK_IMU_Measurements[2] = rtb_Sum6;

        // DataStoreWrite: '<S178>/Data Store Write11'
        Fullexp_DW.BLUE_IMU_Measurements[0] = 0.0;
        Fullexp_DW.BLUE_IMU_Measurements[1] = 0.0;
        Fullexp_DW.BLUE_IMU_Measurements[2] = 0.0;
      } else if (Fullexp_DW.WhoAmI == 3.0) {
        // DataStoreWrite: '<S178>/Data Store Write9'
        Fullexp_DW.RED_IMU_Measurements[0] = 0.0;
        Fullexp_DW.RED_IMU_Measurements[1] = 0.0;
        Fullexp_DW.RED_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S178>/Data Store Write10'
        Fullexp_DW.BLACK_IMU_Measurements[0] = 0.0;
        Fullexp_DW.BLACK_IMU_Measurements[1] = 0.0;
        Fullexp_DW.BLACK_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S178>/Data Store Write11'
        Fullexp_DW.BLUE_IMU_Measurements[0] = Red_x[0];
        Fullexp_DW.BLUE_IMU_Measurements[1] = Red_x[1];
        Fullexp_DW.BLUE_IMU_Measurements[2] = rtb_Sum6;
      } else {
        // DataStoreWrite: '<S178>/Data Store Write9'
        Fullexp_DW.RED_IMU_Measurements[0] = 0.0;
        Fullexp_DW.RED_IMU_Measurements[1] = 0.0;
        Fullexp_DW.RED_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S178>/Data Store Write10'
        Fullexp_DW.BLACK_IMU_Measurements[0] = 0.0;
        Fullexp_DW.BLACK_IMU_Measurements[1] = 0.0;
        Fullexp_DW.BLACK_IMU_Measurements[2] = 0.0;

        // DataStoreWrite: '<S178>/Data Store Write11'
        Fullexp_DW.BLUE_IMU_Measurements[0] = 0.0;
        Fullexp_DW.BLUE_IMU_Measurements[1] = 0.0;
        Fullexp_DW.BLUE_IMU_Measurements[2] = 0.0;
      }

      // End of MATLAB Function: '<S178>/Parse IMU Data'
      // End of Outputs for SubSystem: '<S9>/Log Gyro//Accel'
    }

    // End of If: '<S8>/This IF block determines whether or not to run the exp code' 

    // If: '<S12>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   DataStoreRead: '<S12>/Data Store Read1'
    //   DataStoreRead: '<S12>/Data Store Read2'

    if ((Fullexp_DW.WhoAmI == 1.0) && (Fullexp_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S12>/Change ARM Behavior' incorporates:
      //   ActionPort: '<S180>/Action Port'

      // MATLABSystem: '<S180>/Read Joint Positions using  Dynamixel Encoders'
      if (Fullexp_DW.obj_d.SampleTime != Fullexp_P.baseRate) {
        if (((!rtIsInf(Fullexp_P.baseRate)) && (!rtIsNaN(Fullexp_P.baseRate))) ||
            rtIsInf(Fullexp_P.baseRate)) {
          sampleTime = Fullexp_P.baseRate;
        }

        Fullexp_DW.obj_d.SampleTime = sampleTime;
      }

      //         %% Define input properties
      //         %% Define output properties
      sampleTime = 0.0;
      rtb_Sum6 = 0.0;
      ARM_Path_idx_1 = 0.0;

      // DataStoreWrite: '<S180>/Data Store Write' incorporates:
      //   Delay: '<S180>/Delay'
      //   Delay: '<S180>/Delay1'
      //   Delay: '<S180>/Delay2'
      //   MATLABSystem: '<S180>/Read Joint Positions using  Dynamixel Encoders'

      Fullexp_DW.ARM_Measured_States[3] = 0.0;
      Fullexp_DW.ARM_Measured_States[4] = 0.0;
      Fullexp_DW.ARM_Measured_States[5] = 0.0;
      read_dynamixel_position(&sampleTime, &rtb_Sum6, &ARM_Path_idx_1,
        &Fullexp_DW.ARM_Measured_States[3], &Fullexp_DW.ARM_Measured_States[4],
        &Fullexp_DW.ARM_Measured_States[5], Fullexp_DW.Delay_DSTATE_o,
        Fullexp_DW.Delay1_DSTATE_cg, Fullexp_DW.Delay2_DSTATE_h);

      // MATLABSystem: '<S180>/Read Joint Positions using  Dynamixel Encoders' incorporates:
      //   Delay: '<S180>/Delay'
      //   Delay: '<S180>/Delay1'
      //   Delay: '<S180>/Delay2'

      Fullexp_DW.Delay_DSTATE_o = sampleTime;
      Fullexp_DW.Delay1_DSTATE_cg = rtb_Sum6;
      Fullexp_DW.Delay2_DSTATE_h = ARM_Path_idx_1;

      // DataStoreWrite: '<S180>/Data Store Write' incorporates:
      //   Delay: '<S180>/Delay'
      //   Delay: '<S180>/Delay1'
      //   Delay: '<S180>/Delay2'

      Fullexp_DW.ARM_Measured_States[0] = Fullexp_DW.Delay_DSTATE_o;
      Fullexp_DW.ARM_Measured_States[1] = Fullexp_DW.Delay1_DSTATE_cg;
      Fullexp_DW.ARM_Measured_States[2] = Fullexp_DW.Delay2_DSTATE_h;

      // End of Outputs for SubSystem: '<S12>/Change ARM Behavior'
    }

    // End of If: '<S12>/This IF block determines whether or not to run the RED sim//exp ' 

    // If: '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' incorporates:
    //   Constant: '<S187>/Constant'
    //   Constant: '<S192>/Constant3'
    //   Constant: '<S202>/Constant3'
    //   Constant: '<S212>/Constant3'
    //   DataStoreRead: '<S13>/Data Store Read2'
    //   Delay: '<S192>/Delay1'
    //   Delay: '<S202>/Delay1'
    //   Delay: '<S212>/Delay1'
    //   RelationalOperator: '<S187>/Relational Operator'
    //   RelationalOperator: '<S192>/Relational Operator'
    //   RelationalOperator: '<S193>/Relational Operator'
    //   RelationalOperator: '<S202>/Relational Operator'
    //   RelationalOperator: '<S203>/Relational Operator'
    //   RelationalOperator: '<S212>/Relational Operator'
    //   RelationalOperator: '<S213>/Relational Operator'
    //   SignalConversion generated from: '<S198>/Enable'
    //   SignalConversion generated from: '<S200>/Enable'
    //   SignalConversion generated from: '<S208>/Enable'
    //   SignalConversion generated from: '<S210>/Enable'
    //   SignalConversion generated from: '<S218>/Enable'
    //   SignalConversion generated from: '<S220>/Enable'
    //   Sum: '<S192>/Subtract2'
    //   Sum: '<S202>/Subtract2'
    //   Sum: '<S212>/Subtract2'

    rtPrevAction = Fullexp_DW.Ifperforminganexperimentgrabthe;
    rtAction = -1;
    if (Fullexp_DW.isSim == 0.0) {
      rtAction = 0;
    } else if (Fullexp_DW.isSim == 1.0) {
      rtAction = 1;
    }

    Fullexp_DW.Ifperforminganexperimentgrabthe = rtAction;
    if (rtPrevAction != rtAction) {
      rtsiSetBlockStateForSolverChangedAtMajorStep(&Fullexp_M->solverInfo, true);
      if (rtPrevAction == 0) {
        // Disable for Enabled SubSystem: '<S194>/Enabled Subsystem'
        if (Fullexp_DW.EnabledSubsystem_n.EnabledSubsystem_MODE) {
          Full_EnabledSubsystem_g_Disable(&Fullexp_DW.EnabledSubsystem_n);
        }

        // End of Disable for SubSystem: '<S194>/Enabled Subsystem'

        // Disable for Enabled SubSystem: '<S193>/Enabled Subsystem'
        if (Fullexp_DW.EnabledSubsystem_m.EnabledSubsystem_MODE) {
          Fullex_EnabledSubsystem_Disable(&Fullexp_DW.EnabledSubsystem_m);
        }

        // End of Disable for SubSystem: '<S193>/Enabled Subsystem'

        // Disable for Enabled SubSystem: '<S204>/Enabled Subsystem'
        if (Fullexp_DW.EnabledSubsystem_g.EnabledSubsystem_MODE) {
          Full_EnabledSubsystem_g_Disable(&Fullexp_DW.EnabledSubsystem_g);
        }

        // End of Disable for SubSystem: '<S204>/Enabled Subsystem'

        // Disable for Enabled SubSystem: '<S203>/Enabled Subsystem'
        if (Fullexp_DW.EnabledSubsystem_l.EnabledSubsystem_MODE) {
          Fullex_EnabledSubsystem_Disable(&Fullexp_DW.EnabledSubsystem_l);
        }

        // End of Disable for SubSystem: '<S203>/Enabled Subsystem'

        // Disable for Enabled SubSystem: '<S214>/Enabled Subsystem'
        if (Fullexp_DW.EnabledSubsystem_a.EnabledSubsystem_MODE) {
          Full_EnabledSubsystem_g_Disable(&Fullexp_DW.EnabledSubsystem_a);
        }

        // End of Disable for SubSystem: '<S214>/Enabled Subsystem'

        // Disable for Enabled SubSystem: '<S213>/Enabled Subsystem'
        if (Fullexp_DW.EnabledSubsystem_k.EnabledSubsystem_MODE) {
          Fullex_EnabledSubsystem_Disable(&Fullexp_DW.EnabledSubsystem_k);
        }

        // End of Disable for SubSystem: '<S213>/Enabled Subsystem'
      }
    }

    switch (rtAction) {
     case 0:
      // Outputs for IfAction SubSystem: '<S13>/Use Hardware to Obtain States' incorporates:
      //   ActionPort: '<S182>/Action Port'

      // S-Function (sdspFromNetwork): '<S183>/Receive PhaseSpace Data'
      sErr = GetErrorBuffer(&Fullexp_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
      samplesRead = 19;
      LibOutputs_Network(&Fullexp_DW.ReceivePhaseSpaceData_NetworkLi[0U],
                         &Fullexp_B.ReceivePhaseSpaceData_o1[0U], &samplesRead);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }

      // End of S-Function (sdspFromNetwork): '<S183>/Receive PhaseSpace Data'

      // Gain: '<S184>/Convert BLAX from [mm] to [m]'
      Fullexp_B.ConvertBLAXfrommmtom = Fullexp_P.ConvertBLAXfrommmtom_Gain *
        Fullexp_B.ReceivePhaseSpaceData_o1[4];

      // Gain: '<S184>/Convert BLAY from [mm] to [m]'
      sampleTime = Fullexp_P.ConvertBLAYfrommmtom_Gain *
        Fullexp_B.ReceivePhaseSpaceData_o1[5];

      // Trigonometry: '<S195>/Sin'
      ARM_Path_idx_1 = sin(Fullexp_B.ReceivePhaseSpaceData_o1[6]);

      // Trigonometry: '<S195>/Cos'
      rtb_Sum6 = cos(Fullexp_B.ReceivePhaseSpaceData_o1[6]);

      // DataStoreWrite: '<S184>/RED_Px7' incorporates:
      //   Gain: '<S184>/Convert BLACKVX from [mm] to [m]'
      //   Gain: '<S184>/Convert BLACKVY from [mm] to [m]'
      //   Trigonometry: '<S195>/Atan2'

      Fullexp_DW.BLACK_Measured_States[2] = rt_atan2d_snf(ARM_Path_idx_1,
        rtb_Sum6);
      Fullexp_DW.BLACK_Measured_States[3] =
        Fullexp_P.ConvertBLACKVXfrommmtom_Gain *
        Fullexp_B.ReceivePhaseSpaceData_o1[13];
      Fullexp_DW.BLACK_Measured_States[4] =
        Fullexp_P.ConvertBLACKVYfrommmtom_Gain *
        Fullexp_B.ReceivePhaseSpaceData_o1[14];

      // Sum: '<S192>/Subtract1' incorporates:
      //   Delay: '<S192>/Delay2'

      rtb_Sum6 = Fullexp_B.ReceivePhaseSpaceData_o1[0] -
        Fullexp_DW.Delay2_DSTATE_j;

      // Outputs for Enabled SubSystem: '<S192>/Enabled Subsystem3' incorporates:
      //   EnablePort: '<S196>/Enable'

      if (Fullexp_B.ConvertBLAXfrommmtom - Fullexp_DW.Delay1_DSTATE_i !=
          Fullexp_P.Constant3_Value_eq) {
        // SignalConversion generated from: '<S196>/y2-y1'
        Fullexp_B.y2y1_ob = rtb_Sum6;
      }

      // End of Outputs for SubSystem: '<S192>/Enabled Subsystem3'

      // MATLAB Function: '<S192>/MATLAB Function' incorporates:
      //   Constant: '<S192>/Constant'
      //   Constant: '<S192>/Constant3'
      //   Delay: '<S192>/Delay1'
      //   RelationalOperator: '<S192>/Relational Operator'
      //   Sum: '<S192>/Subtract2'

      Fullexp_MATLABFunction_j(Fullexp_B.y2y1_ob, Fullexp_P.dataRate, &rtb_Sum6);

      // Sum: '<S194>/Subtract1' incorporates:
      //   Delay: '<S194>/Delay1'

      Red_x[2] = Fullexp_B.ReceivePhaseSpaceData_o1[6] -
        Fullexp_DW.Delay1_DSTATE_g[2];

      // RelationalOperator: '<S194>/Relational Operator' incorporates:
      //   Constant: '<S194>/Constant3'
      //   Delay: '<S194>/Delay1'
      //   Sum: '<S194>/Subtract1'

      RelationalOperator_i[0] = (Fullexp_B.ConvertBLAXfrommmtom -
        Fullexp_DW.Delay1_DSTATE_g[0] != Fullexp_P.Constant3_Value_a);
      RelationalOperator_i[1] = (sampleTime - Fullexp_DW.Delay1_DSTATE_g[1] !=
        Fullexp_P.Constant3_Value_a);
      RelationalOperator_i[2] = (Red_x[2] != Fullexp_P.Constant3_Value_a);

      // Outputs for Enabled SubSystem: '<S194>/Enabled Subsystem'
      Fullexp_EnabledSubsystem_n(RelationalOperator_i,
        Fullexp_B.ConvertBLAXfrommmtom, sampleTime,
        Fullexp_B.ReceivePhaseSpaceData_o1[6], rtb_Sum6, Fullexp_B.dy_i,
        &Fullexp_B.EnabledSubsystem_n, &Fullexp_DW.EnabledSubsystem_n,
        &Fullexp_P.EnabledSubsystem_n);

      // End of Outputs for SubSystem: '<S194>/Enabled Subsystem'

      // RelationalOperator: '<S193>/Relational Operator' incorporates:
      //   Constant: '<S193>/Constant3'
      //   Delay: '<S193>/Delay1'
      //   SignalConversion generated from: '<S200>/Enable'
      //   Sum: '<S193>/Subtract1'

      RelationalOperator_i[0] = (Fullexp_B.dy_i[0] -
        Fullexp_DW.Delay1_DSTATE_bv[0] != Fullexp_P.Constant3_Value_d4);
      RelationalOperator_i[1] = (Fullexp_B.dy_i[1] -
        Fullexp_DW.Delay1_DSTATE_bv[1] != Fullexp_P.Constant3_Value_d4);
      RelationalOperator_i[2] = (Fullexp_B.dy_i[2] -
        Fullexp_DW.Delay1_DSTATE_bv[2] != Fullexp_P.Constant3_Value_d4);

      // Outputs for Enabled SubSystem: '<S193>/Enabled Subsystem'
      Fullexp_EnabledSubsystem(RelationalOperator_i, Fullexp_B.dy_i, rtb_Sum6,
        Fullexp_B.dy_k, &Fullexp_B.EnabledSubsystem_m,
        &Fullexp_DW.EnabledSubsystem_m, &Fullexp_P.EnabledSubsystem_m);

      // End of Outputs for SubSystem: '<S193>/Enabled Subsystem'

      // DataStoreWrite: '<S184>/RED_Px7' incorporates:
      //   RelationalOperator: '<S193>/Relational Operator'
      //   SignalConversion generated from: '<S198>/Enable'

      Fullexp_DW.BLACK_Measured_States[0] = Fullexp_B.ConvertBLAXfrommmtom;
      Fullexp_DW.BLACK_Measured_States[1] = sampleTime;
      Fullexp_DW.BLACK_Measured_States[5] = Fullexp_B.ReceivePhaseSpaceData_o1
        [15];
      Fullexp_DW.BLACK_Measured_States[6] = Fullexp_B.dy_k[0];
      Fullexp_DW.BLACK_Measured_States[7] = Fullexp_B.dy_k[1];
      Fullexp_DW.BLACK_Measured_States[8] = Fullexp_B.dy_k[2];

      // SignalConversion generated from: '<S194>/Delay1' incorporates:
      //   Delay: '<S194>/Delay1'

      Fullexp_DW.Delay1_DSTATE_g[0] = Fullexp_B.ConvertBLAXfrommmtom;
      Fullexp_DW.Delay1_DSTATE_g[1] = sampleTime;
      Fullexp_DW.Delay1_DSTATE_g[2] = Fullexp_B.ReceivePhaseSpaceData_o1[6];

      // Gain: '<S185>/Convert BLUX from [mm] to [m]'
      Fullexp_B.ConvertBLUXfrommmtom = Fullexp_P.ConvertBLUXfrommmtom_Gain *
        Fullexp_B.ReceivePhaseSpaceData_o1[7];

      // Gain: '<S185>/Convert BLUY from [mm] to [m]'
      sampleTime = Fullexp_P.ConvertBLUYfrommmtom_Gain *
        Fullexp_B.ReceivePhaseSpaceData_o1[8];

      // Trigonometry: '<S205>/Sin'
      ARM_Path_idx_1 = sin(Fullexp_B.ReceivePhaseSpaceData_o1[9]);

      // Trigonometry: '<S205>/Cos'
      rtb_Sum6 = cos(Fullexp_B.ReceivePhaseSpaceData_o1[9]);

      // DataStoreWrite: '<S185>/RED_Px7' incorporates:
      //   Gain: '<S185>/Convert BLUEVX from [mm] to [m]'
      //   Gain: '<S185>/Convert BLUEVY from [mm] to [m]'
      //   Trigonometry: '<S205>/Atan2'

      Fullexp_DW.BLUE_Measured_States[2] = rt_atan2d_snf(ARM_Path_idx_1,
        rtb_Sum6);
      Fullexp_DW.BLUE_Measured_States[3] = Fullexp_P.ConvertBLUEVXfrommmtom_Gain
        * Fullexp_B.ReceivePhaseSpaceData_o1[16];
      Fullexp_DW.BLUE_Measured_States[4] = Fullexp_P.ConvertBLUEVYfrommmtom_Gain
        * Fullexp_B.ReceivePhaseSpaceData_o1[17];

      // Sum: '<S202>/Subtract1' incorporates:
      //   Delay: '<S202>/Delay2'

      rtb_Sum6 = Fullexp_B.ReceivePhaseSpaceData_o1[0] -
        Fullexp_DW.Delay2_DSTATE_l;

      // Outputs for Enabled SubSystem: '<S202>/Enabled Subsystem3' incorporates:
      //   EnablePort: '<S206>/Enable'

      if (Fullexp_B.ConvertBLUXfrommmtom - Fullexp_DW.Delay1_DSTATE_l !=
          Fullexp_P.Constant3_Value_o) {
        // SignalConversion generated from: '<S206>/y2-y1'
        Fullexp_B.y2y1_o = rtb_Sum6;
      }

      // End of Outputs for SubSystem: '<S202>/Enabled Subsystem3'

      // MATLAB Function: '<S202>/MATLAB Function' incorporates:
      //   Constant: '<S202>/Constant'
      //   Constant: '<S202>/Constant3'
      //   Delay: '<S202>/Delay1'
      //   RelationalOperator: '<S202>/Relational Operator'
      //   Sum: '<S202>/Subtract2'

      Fullexp_MATLABFunction_j(Fullexp_B.y2y1_o, Fullexp_P.dataRate, &rtb_Sum6);

      // Sum: '<S204>/Subtract1' incorporates:
      //   Delay: '<S204>/Delay1'

      Red_x[2] = Fullexp_B.ReceivePhaseSpaceData_o1[9] -
        Fullexp_DW.Delay1_DSTATE_m[2];

      // RelationalOperator: '<S204>/Relational Operator' incorporates:
      //   Constant: '<S204>/Constant3'
      //   Delay: '<S204>/Delay1'
      //   Sum: '<S204>/Subtract1'

      RelationalOperator_i[0] = (Fullexp_B.ConvertBLUXfrommmtom -
        Fullexp_DW.Delay1_DSTATE_m[0] != Fullexp_P.Constant3_Value_c);
      RelationalOperator_i[1] = (sampleTime - Fullexp_DW.Delay1_DSTATE_m[1] !=
        Fullexp_P.Constant3_Value_c);
      RelationalOperator_i[2] = (Red_x[2] != Fullexp_P.Constant3_Value_c);

      // Outputs for Enabled SubSystem: '<S204>/Enabled Subsystem'
      Fullexp_EnabledSubsystem_n(RelationalOperator_i,
        Fullexp_B.ConvertBLUXfrommmtom, sampleTime,
        Fullexp_B.ReceivePhaseSpaceData_o1[9], rtb_Sum6, Fullexp_B.dy_c,
        &Fullexp_B.EnabledSubsystem_g, &Fullexp_DW.EnabledSubsystem_g,
        &Fullexp_P.EnabledSubsystem_g);

      // End of Outputs for SubSystem: '<S204>/Enabled Subsystem'

      // RelationalOperator: '<S203>/Relational Operator' incorporates:
      //   Constant: '<S203>/Constant3'
      //   Delay: '<S203>/Delay1'
      //   SignalConversion generated from: '<S210>/Enable'
      //   Sum: '<S203>/Subtract1'

      RelationalOperator_i[0] = (Fullexp_B.dy_c[0] -
        Fullexp_DW.Delay1_DSTATE_lv[0] != Fullexp_P.Constant3_Value_ke);
      RelationalOperator_i[1] = (Fullexp_B.dy_c[1] -
        Fullexp_DW.Delay1_DSTATE_lv[1] != Fullexp_P.Constant3_Value_ke);
      RelationalOperator_i[2] = (Fullexp_B.dy_c[2] -
        Fullexp_DW.Delay1_DSTATE_lv[2] != Fullexp_P.Constant3_Value_ke);

      // Outputs for Enabled SubSystem: '<S203>/Enabled Subsystem'
      Fullexp_EnabledSubsystem(RelationalOperator_i, Fullexp_B.dy_c, rtb_Sum6,
        Fullexp_B.dy_e, &Fullexp_B.EnabledSubsystem_l,
        &Fullexp_DW.EnabledSubsystem_l, &Fullexp_P.EnabledSubsystem_l);

      // End of Outputs for SubSystem: '<S203>/Enabled Subsystem'

      // DataStoreWrite: '<S185>/RED_Px7' incorporates:
      //   RelationalOperator: '<S203>/Relational Operator'
      //   SignalConversion generated from: '<S208>/Enable'

      Fullexp_DW.BLUE_Measured_States[0] = Fullexp_B.ConvertBLUXfrommmtom;
      Fullexp_DW.BLUE_Measured_States[1] = sampleTime;
      Fullexp_DW.BLUE_Measured_States[5] = Fullexp_B.ReceivePhaseSpaceData_o1[18];
      Fullexp_DW.BLUE_Measured_States[6] = Fullexp_B.dy_e[0];
      Fullexp_DW.BLUE_Measured_States[7] = Fullexp_B.dy_e[1];
      Fullexp_DW.BLUE_Measured_States[8] = Fullexp_B.dy_e[2];

      // SignalConversion generated from: '<S204>/Delay1' incorporates:
      //   Delay: '<S204>/Delay1'

      Fullexp_DW.Delay1_DSTATE_m[0] = Fullexp_B.ConvertBLUXfrommmtom;
      Fullexp_DW.Delay1_DSTATE_m[1] = sampleTime;
      Fullexp_DW.Delay1_DSTATE_m[2] = Fullexp_B.ReceivePhaseSpaceData_o1[9];

      // Gain: '<S186>/Convert REDX from [mm] to [m]'
      Fullexp_B.ConvertREDXfrommmtom = Fullexp_P.ConvertREDXfrommmtom_Gain *
        Fullexp_B.ReceivePhaseSpaceData_o1[1];

      // Gain: '<S186>/Convert REDY from [mm] to [m]'
      sampleTime = Fullexp_P.ConvertREDYfrommmtom_Gain *
        Fullexp_B.ReceivePhaseSpaceData_o1[2];

      // Trigonometry: '<S215>/Sin'
      ARM_Path_idx_1 = sin(Fullexp_B.ReceivePhaseSpaceData_o1[3]);

      // Trigonometry: '<S215>/Cos'
      rtb_Sum6 = cos(Fullexp_B.ReceivePhaseSpaceData_o1[3]);

      // DataStoreWrite: '<S186>/RED_Px7' incorporates:
      //   Gain: '<S186>/Convert REDVX from [mm] to [m]'
      //   Gain: '<S186>/Convert REDVY from [mm] to [m]'
      //   Trigonometry: '<S215>/Atan2'

      Fullexp_DW.RED_Measured_States[2] = rt_atan2d_snf(ARM_Path_idx_1, rtb_Sum6);
      Fullexp_DW.RED_Measured_States[3] = Fullexp_P.ConvertREDVXfrommmtom_Gain *
        Fullexp_B.ReceivePhaseSpaceData_o1[10];
      Fullexp_DW.RED_Measured_States[4] = Fullexp_P.ConvertREDVYfrommmtom_Gain *
        Fullexp_B.ReceivePhaseSpaceData_o1[11];

      // Sum: '<S212>/Subtract1' incorporates:
      //   Delay: '<S212>/Delay2'

      rtb_Sum6 = Fullexp_B.ReceivePhaseSpaceData_o1[0] -
        Fullexp_DW.Delay2_DSTATE_l0;

      // Outputs for Enabled SubSystem: '<S212>/Enabled Subsystem3' incorporates:
      //   EnablePort: '<S216>/Enable'

      if (Fullexp_B.ConvertREDXfrommmtom - Fullexp_DW.Delay1_DSTATE_ld !=
          Fullexp_P.Constant3_Value_f) {
        // SignalConversion generated from: '<S216>/y2-y1'
        Fullexp_B.y2y1 = rtb_Sum6;
      }

      // End of Outputs for SubSystem: '<S212>/Enabled Subsystem3'

      // MATLAB Function: '<S212>/MATLAB Function' incorporates:
      //   Constant: '<S212>/Constant'
      //   Constant: '<S212>/Constant3'
      //   Delay: '<S212>/Delay1'
      //   RelationalOperator: '<S212>/Relational Operator'
      //   Sum: '<S212>/Subtract2'

      Fullexp_MATLABFunction_j(Fullexp_B.y2y1, Fullexp_P.dataRate, &rtb_Sum6);

      // Sum: '<S214>/Subtract1' incorporates:
      //   Delay: '<S214>/Delay1'

      Red_x[2] = Fullexp_B.ReceivePhaseSpaceData_o1[3] -
        Fullexp_DW.Delay1_DSTATE_c[2];

      // RelationalOperator: '<S214>/Relational Operator' incorporates:
      //   Constant: '<S214>/Constant3'
      //   Delay: '<S214>/Delay1'
      //   Sum: '<S214>/Subtract1'

      RelationalOperator_i[0] = (Fullexp_B.ConvertREDXfrommmtom -
        Fullexp_DW.Delay1_DSTATE_c[0] != Fullexp_P.Constant3_Value_dh);
      RelationalOperator_i[1] = (sampleTime - Fullexp_DW.Delay1_DSTATE_c[1] !=
        Fullexp_P.Constant3_Value_dh);
      RelationalOperator_i[2] = (Red_x[2] != Fullexp_P.Constant3_Value_dh);

      // Outputs for Enabled SubSystem: '<S214>/Enabled Subsystem'
      Fullexp_EnabledSubsystem_n(RelationalOperator_i,
        Fullexp_B.ConvertREDXfrommmtom, sampleTime,
        Fullexp_B.ReceivePhaseSpaceData_o1[3], rtb_Sum6, Fullexp_B.dy,
        &Fullexp_B.EnabledSubsystem_a, &Fullexp_DW.EnabledSubsystem_a,
        &Fullexp_P.EnabledSubsystem_a);

      // End of Outputs for SubSystem: '<S214>/Enabled Subsystem'

      // RelationalOperator: '<S213>/Relational Operator' incorporates:
      //   Constant: '<S213>/Constant3'
      //   Delay: '<S213>/Delay1'
      //   SignalConversion generated from: '<S220>/Enable'
      //   Sum: '<S213>/Subtract1'

      RelationalOperator_i[0] = (Fullexp_B.dy[0] - Fullexp_DW.Delay1_DSTATE_cq[0]
        != Fullexp_P.Constant3_Value_dz);
      RelationalOperator_i[1] = (Fullexp_B.dy[1] - Fullexp_DW.Delay1_DSTATE_cq[1]
        != Fullexp_P.Constant3_Value_dz);
      RelationalOperator_i[2] = (Fullexp_B.dy[2] - Fullexp_DW.Delay1_DSTATE_cq[2]
        != Fullexp_P.Constant3_Value_dz);

      // Outputs for Enabled SubSystem: '<S213>/Enabled Subsystem'
      Fullexp_EnabledSubsystem(RelationalOperator_i, Fullexp_B.dy, rtb_Sum6,
        Fullexp_B.dy_l, &Fullexp_B.EnabledSubsystem_k,
        &Fullexp_DW.EnabledSubsystem_k, &Fullexp_P.EnabledSubsystem_k);

      // End of Outputs for SubSystem: '<S213>/Enabled Subsystem'

      // DataStoreWrite: '<S186>/RED_Px7' incorporates:
      //   RelationalOperator: '<S213>/Relational Operator'
      //   SignalConversion generated from: '<S218>/Enable'

      Fullexp_DW.RED_Measured_States[0] = Fullexp_B.ConvertREDXfrommmtom;
      Fullexp_DW.RED_Measured_States[1] = sampleTime;
      Fullexp_DW.RED_Measured_States[5] = Fullexp_B.ReceivePhaseSpaceData_o1[12];
      Fullexp_DW.RED_Measured_States[6] = Fullexp_B.dy_l[0];
      Fullexp_DW.RED_Measured_States[7] = Fullexp_B.dy_l[1];
      Fullexp_DW.RED_Measured_States[8] = Fullexp_B.dy_l[2];

      // MATLAB Function: '<S188>/MATLAB Function' incorporates:
      //   Delay: '<S188>/Delay'
      //   Delay: '<S188>/Delay1'
      //   Delay: '<S188>/Delay2'

      rtb_StartClock = 0;
      if (Fullexp_P.platformSelection == 1.0) {
        rtb_StartClock = (Fullexp_DW.Delay_DSTATE_i[0] == 1);
      } else if (Fullexp_P.platformSelection == 2.0) {
        rtb_StartClock = (Fullexp_DW.Delay1_DSTATE_h[0] == 1);
      } else if (Fullexp_P.platformSelection == 3.0) {
        rtb_StartClock = ((Fullexp_DW.Delay_DSTATE_i[0] == 1) &&
                          (Fullexp_DW.Delay1_DSTATE_h[0] == 1));
      } else if (Fullexp_P.platformSelection == 4.0) {
        rtb_StartClock = ((Fullexp_DW.Delay_DSTATE_i[0] == 1) &&
                          (Fullexp_DW.Delay1_DSTATE_h[0] == 1));
      } else if (Fullexp_P.platformSelection == 5.0) {
        rtb_StartClock = (Fullexp_DW.Delay_DSTATE_i[0] == 1);
      } else if (Fullexp_P.platformSelection == 6.0) {
        rtb_StartClock = (Fullexp_DW.Delay2_DSTATE_hq[0] == 1);
      } else if (Fullexp_P.platformSelection == 7.0) {
        rtb_StartClock = ((Fullexp_DW.Delay_DSTATE_i[0] == 1) &&
                          (Fullexp_DW.Delay2_DSTATE_hq[0] == 1));
      } else if (Fullexp_P.platformSelection == 8.0) {
        rtb_StartClock = ((Fullexp_DW.Delay_DSTATE_i[0] == 1) &&
                          (Fullexp_DW.Delay1_DSTATE_h[0] == 1) &&
                          (Fullexp_DW.Delay2_DSTATE_hq[0] == 1));
      } else if (Fullexp_P.platformSelection == 9.0) {
        rtb_StartClock = ((Fullexp_DW.Delay1_DSTATE_h[0] == 1) &&
                          (Fullexp_DW.Delay2_DSTATE_hq[0] == 1));
      } else if (Fullexp_P.platformSelection == 10.0) {
        rtb_StartClock = ((Fullexp_DW.Delay_DSTATE_i[0] == 1) &&
                          (Fullexp_DW.Delay2_DSTATE_hq[0] == 1));
      } else if (Fullexp_P.platformSelection == 11.0) {
        rtb_StartClock = ((Fullexp_DW.Delay_DSTATE_i[0] == 1) &&
                          (Fullexp_DW.Delay1_DSTATE_h[0] == 1) &&
                          (Fullexp_DW.Delay2_DSTATE_hq[0] == 1));
      }

      // End of MATLAB Function: '<S188>/MATLAB Function'

      // RelationalOperator: '<S187>/Relational Operator1' incorporates:
      //   Constant: '<S187>/Constant'

      Fullexp_B.RelationalOperator1 = (rtb_StartClock !=
        Fullexp_P.Constant_Value);

      // Outputs for Enabled SubSystem: '<S187>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S189>/Enable'

      if (Fullexp_B.RelationalOperator1) {
        // Memory: '<S189>/Memory'
        Fullexp_B.Memory = Fullexp_DW.Memory_PreviousInput;
      }

      // End of Outputs for SubSystem: '<S187>/Enabled Subsystem'

      // Clock: '<S183>/Clock'
      Fullexp_B.Clock_o = thrust_decay_factor;

      // Outputs for Enabled SubSystem: '<S187>/Enabled Subsystem1' incorporates:
      //   EnablePort: '<S190>/Enable'

      if (rtb_StartClock == Fullexp_P.Constant_Value) {
        // Sum: '<S190>/Subtract'
        Fullexp_B.Subtract = Fullexp_B.Clock_o - Fullexp_B.Memory;
      }

      // End of Outputs for SubSystem: '<S187>/Enabled Subsystem1'

      // DataStoreWrite: '<S186>/Universal_Time' incorporates:
      //   Constant: '<S187>/Constant'
      //   RelationalOperator: '<S187>/Relational Operator'

      Fullexp_DW.Univ_Time = Fullexp_B.Subtract;

      // SignalConversion generated from: '<S214>/Delay1' incorporates:
      //   Delay: '<S214>/Delay1'

      Fullexp_DW.Delay1_DSTATE_c[0] = Fullexp_B.ConvertREDXfrommmtom;
      Fullexp_DW.Delay1_DSTATE_c[1] = sampleTime;
      Fullexp_DW.Delay1_DSTATE_c[2] = Fullexp_B.ReceivePhaseSpaceData_o1[3];

      // S-Function (sdspFromNetwork): '<S188>/UDP Receive'
      sErr = GetErrorBuffer(&Fullexp_DW.UDPReceive_NetworkLib[0U]);
      rtb_StartClock = 1;
      LibOutputs_Network(&Fullexp_DW.UDPReceive_NetworkLib[0U],
                         &Fullexp_B.UDPReceive_o1, &rtb_StartClock);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }

      // End of S-Function (sdspFromNetwork): '<S188>/UDP Receive'

      // S-Function (sdspFromNetwork): '<S188>/UDP Receive2'
      sErr = GetErrorBuffer(&Fullexp_DW.UDPReceive2_NetworkLib[0U]);
      samplesRead_1 = 1;
      LibOutputs_Network(&Fullexp_DW.UDPReceive2_NetworkLib[0U],
                         &Fullexp_B.UDPReceive2_o1, &samplesRead_1);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }

      // End of S-Function (sdspFromNetwork): '<S188>/UDP Receive2'

      // S-Function (sdspFromNetwork): '<S188>/UDP Receive3'
      sErr = GetErrorBuffer(&Fullexp_DW.UDPReceive3_NetworkLib[0U]);
      nz = 1;
      LibOutputs_Network(&Fullexp_DW.UDPReceive3_NetworkLib[0U],
                         &Fullexp_B.UDPReceive3_o1, &nz);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }

      // End of S-Function (sdspFromNetwork): '<S188>/UDP Receive3'
      // End of Outputs for SubSystem: '<S13>/Use Hardware to Obtain States'
      break;

     case 1:
      // Outputs for IfAction SubSystem: '<S13>/Initialize Universal Time (Simulation)' incorporates:
      //   ActionPort: '<S181>/Action Port'

      // Clock: '<S181>/Set Universal Time (If this is a simulation)' incorporates:
      //   DataStoreWrite: '<S181>/Universal_Time'

      Fullexp_DW.Univ_Time = Fullexp_M->Timing.t[0];

      // End of Outputs for SubSystem: '<S13>/Initialize Universal Time (Simulation)' 
      break;
    }

    // If: '<S18>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
    //   DataStoreRead: '<S14>/Data Store Read1'
    //   If: '<S14>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.'

    if (Fullexp_DW.isSim == 0.0) {
      // Outputs for IfAction SubSystem: '<S14>/Subsystem' incorporates:
      //   ActionPort: '<S222>/Action Port'

      // MATLABSystem: '<S222>/WhoAmI' incorporates:
      //   DataStoreWrite: '<S222>/Data Store Write'

      if (Fullexp_DW.obj_dk.SampleTime != Fullexp_P.baseRate) {
        if (((!rtIsInf(Fullexp_P.baseRate)) && (!rtIsNaN(Fullexp_P.baseRate))) ||
            rtIsInf(Fullexp_P.baseRate)) {
          sampleTime_0 = Fullexp_P.baseRate;
        }

        Fullexp_DW.obj_dk.SampleTime = sampleTime_0;
      }

      //         %% Define output properties
      //  Call C-function implementing device output
      Fullexp_DW.WhoAmI = WhoAmI();

      // End of MATLABSystem: '<S222>/WhoAmI'
      // End of Outputs for SubSystem: '<S14>/Subsystem'

      // Outputs for IfAction SubSystem: '<S18>/Subsystem' incorporates:
      //   ActionPort: '<S226>/Action Port'

      // S-Function (sdspFromNetwork): '<S226>/UDP Receive1'
      sErr = GetErrorBuffer(&Fullexp_DW.UDPReceive1_NetworkLib[0U]);
      samplesRead_0 = 4;
      LibOutputs_Network(&Fullexp_DW.UDPReceive1_NetworkLib[0U],
                         &Fullexp_B.UDPReceive1_o1[0U], &samplesRead_0);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }

      // End of S-Function (sdspFromNetwork): '<S226>/UDP Receive1'

      // DataTypeConversion: '<S226>/Cast To Double2' incorporates:
      //   DataStoreWrite: '<S226>/Data Store Write20'

      Fullexp_DW.Vis_yaw = Fullexp_B.UDPReceive1_o1[2];

      // DataStoreWrite: '<S226>/Data Store Write21' incorporates:
      //   Constant: '<S226>/Constant'
      //   DataTypeConversion: '<S226>/Cast To Double'
      //   DataTypeConversion: '<S226>/Cast To Double1'

      Fullexp_DW.Vis_x[0] = Fullexp_B.UDPReceive1_o1[0];
      Fullexp_DW.Vis_x[1] = Fullexp_B.UDPReceive1_o1[1];
      Fullexp_DW.Vis_x[2] = Fullexp_P.Constant_Value_d;

      // DataTypeConversion: '<S226>/Cast To Double3' incorporates:
      //   DataStoreWrite: '<S226>/Data Store Write22'

      Fullexp_DW.Conf = Fullexp_B.UDPReceive1_o1[3];

      // End of Outputs for SubSystem: '<S18>/Subsystem'
    }

    // End of If: '<S18>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 

    // If: '<S21>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   DataStoreRead: '<S21>/Data Store Read'
    //   DataStoreRead: '<S21>/Data Store Read1'

    if ((Fullexp_DW.WhoAmI == 1.0) && (Fullexp_DW.isSim == 0.0)) {
      // Outputs for IfAction SubSystem: '<S21>/Change ARM Behavior' incorporates:
      //   ActionPort: '<S229>/Action Port'

      // MATLABSystem: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' incorporates:
      //   DataStoreRead: '<S229>/Arm Control Mode'
      //   DataStoreRead: '<S229>/Command'

      if (Fullexp_DW.obj_n.POSITION_P_GAIN !=
          Fullexp_P.ControlDynamixelActuatorsineith) {
        Fullexp_DW.obj_n.POSITION_P_GAIN =
          Fullexp_P.ControlDynamixelActuatorsineith;
      }

      if (Fullexp_DW.obj_n.POSITION_I_GAIN !=
          Fullexp_P.ControlDynamixelActuatorsinei_b) {
        Fullexp_DW.obj_n.POSITION_I_GAIN =
          Fullexp_P.ControlDynamixelActuatorsinei_b;
      }

      if (Fullexp_DW.obj_n.POSITION_D_GAIN !=
          Fullexp_P.ControlDynamixelActuatorsinei_h) {
        Fullexp_DW.obj_n.POSITION_D_GAIN =
          Fullexp_P.ControlDynamixelActuatorsinei_h;
      }

      if (Fullexp_DW.obj_n.MAX_POSITION !=
          Fullexp_P.ControlDynamixelActuatorsinei_j) {
        Fullexp_DW.obj_n.MAX_POSITION =
          Fullexp_P.ControlDynamixelActuatorsinei_j;
      }

      if (Fullexp_DW.obj_n.MIN_POSITION !=
          Fullexp_P.ControlDynamixelActuatorsinei_m) {
        Fullexp_DW.obj_n.MIN_POSITION =
          Fullexp_P.ControlDynamixelActuatorsinei_m;
      }

      if (Fullexp_DW.obj_n.MOVE_TIME !=
          Fullexp_P.ControlDynamixelActuatorsine_hy) {
        Fullexp_DW.obj_n.MOVE_TIME = Fullexp_P.ControlDynamixelActuatorsine_hy;
      }

      if (Fullexp_DW.obj_n.CURRENT_LIMIT !=
          Fullexp_P.ControlDynamixelActuatorsinei_i) {
        Fullexp_DW.obj_n.CURRENT_LIMIT =
          Fullexp_P.ControlDynamixelActuatorsinei_i;
      }

      if (Fullexp_DW.obj_n.SPEED_P_GAIN !=
          Fullexp_P.ControlDynamixelActuatorsinei_g) {
        Fullexp_DW.obj_n.SPEED_P_GAIN =
          Fullexp_P.ControlDynamixelActuatorsinei_g;
      }

      if (Fullexp_DW.obj_n.SPEED_I_GAIN !=
          Fullexp_P.ControlDynamixelActuatorsine_g3) {
        Fullexp_DW.obj_n.SPEED_I_GAIN =
          Fullexp_P.ControlDynamixelActuatorsine_g3;
      }

      if (Fullexp_DW.obj_n.VELOCITY_LIMIT !=
          Fullexp_P.ControlDynamixelActuatorsine_bf) {
        Fullexp_DW.obj_n.VELOCITY_LIMIT =
          Fullexp_P.ControlDynamixelActuatorsine_bf;
      }

      if (Fullexp_DW.obj_n.ACCELERATION_TIME !=
          Fullexp_P.ControlDynamixelActuatorsinei_l) {
        Fullexp_DW.obj_n.ACCELERATION_TIME =
          Fullexp_P.ControlDynamixelActuatorsinei_l;
      }

      if (Fullexp_DW.obj_n.SampleTime != Fullexp_P.baseRate) {
        if (((!rtIsInf(Fullexp_P.baseRate)) && (!rtIsNaN(Fullexp_P.baseRate))) ||
            rtIsInf(Fullexp_P.baseRate)) {
          sampleTime_1 = Fullexp_P.baseRate;
        }

        Fullexp_DW.obj_n.SampleTime = sampleTime_1;
      }

      //         %% Define input properties
      //  Call C-function implementing device output
      //  include the dynamicel functions
      //  Run the main controller code. If the switch state is
      //  true then this code will initialize the parameters and
      //  then start the actuator, and THEN run the command. If the
      //  switch state is false, it will not reinitialize the
      //  motor
      dynamixel_controller(Fullexp_DW.ARM_Control_Mode,
                           Fullexp_DW.obj_n.POSITION_P_GAIN,
                           Fullexp_DW.obj_n.POSITION_I_GAIN,
                           Fullexp_DW.obj_n.POSITION_D_GAIN,
                           Fullexp_DW.obj_n.MAX_POSITION,
                           Fullexp_DW.obj_n.MIN_POSITION,
                           Fullexp_DW.obj_n.MOVE_TIME, ARM_Controls[0],
                           ARM_Controls[1], ARM_Controls[2],
                           Fullexp_DW.obj_n.CURRENT_LIMIT, ARM_Controls[0],
                           ARM_Controls[1], ARM_Controls[2],
                           Fullexp_DW.obj_n.SPEED_P_GAIN,
                           Fullexp_DW.obj_n.SPEED_I_GAIN,
                           Fullexp_DW.obj_n.VELOCITY_LIMIT, ARM_Controls[0],
                           ARM_Controls[1], ARM_Controls[2],
                           Fullexp_DW.obj_n.ACCELERATION_TIME);

      // End of MATLABSystem: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
      // End of Outputs for SubSystem: '<S21>/Change ARM Behavior'
    }

    // End of If: '<S21>/This IF block determines whether or not to run the RED sim//exp ' 

    // If: '<S24>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' incorporates:
    //   DataStoreRead: '<S24>/Data Store Read1'

    if (Fullexp_DW.isSim == 0.0) {
      // Outputs for IfAction SubSystem: '<S24>/Subsystem' incorporates:
      //   ActionPort: '<S232>/Action Port'

      // SignalConversion generated from: '<S232>/UDP Send' incorporates:
      //   DataStoreRead: '<S232>/BLACK States'
      //   DataStoreRead: '<S232>/BLUE States'
      //   DataStoreRead: '<S232>/RED States'
      //   DataStoreRead: '<S232>/Time'

      Fullexp_B.TmpSignalConversionAtUDPSendI_o[0] = Fullexp_DW.Univ_Time;
      for (i = 0; i < 9; i++) {
        Fullexp_B.TmpSignalConversionAtUDPSendI_o[i + 1] =
          Fullexp_DW.RED_Measured_States[i];
        Fullexp_B.TmpSignalConversionAtUDPSendI_o[i + 10] =
          Fullexp_DW.BLACK_Measured_States[i];
        Fullexp_B.TmpSignalConversionAtUDPSendI_o[i + 19] =
          Fullexp_DW.BLUE_Measured_States[i];
      }

      // Update for S-Function (sdspToNetwork): '<S232>/UDP Send' incorporates:
      //   SignalConversion generated from: '<S232>/UDP Send'
      //
      sErr = GetErrorBuffer(&Fullexp_DW.UDPSend_NetworkLib_m[0U]);
      LibUpdate_Network(&Fullexp_DW.UDPSend_NetworkLib_m[0U],
                        &Fullexp_B.TmpSignalConversionAtUDPSendI_o[0U], 28);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }

      // End of Update for S-Function (sdspToNetwork): '<S232>/UDP Send'
      // End of Outputs for SubSystem: '<S24>/Subsystem'
    }

    // End of If: '<S24>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' 

    // If: '<S26>/This IF block determines whether or not to run the RED sim//exp ' incorporates:
    //   Constant: '<S262>/Constant1'
    //   Constant: '<S262>/Constant2'
    //   DataStoreRead: '<S26>/Data Store Read'
    //   DataStoreRead: '<S26>/Data Store Read1'
    //   Delay: '<S262>/Delay'
    //   RelationalOperator: '<S262>/Relational Operator1'
    //   RelationalOperator: '<S262>/Relational Operator2'

    if ((Fullexp_DW.WhoAmI == 1.0) || (Fullexp_DW.isSim == 1.0)) {
      // Outputs for IfAction SubSystem: '<S26>/Change RED Behavior' incorporates:
      //   ActionPort: '<S235>/Action Port'

      // MATLAB Function: '<S266>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S235>/Data Store Read1'

      Fullexp_CreateRotationMatrix(Fullexp_DW.RED_Measured_States[2], qr_0);

      // MATLAB Function: '<S261>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S235>/Data Store Read1'

      Fullexp_CreateRotationMatrix_a(Fullexp_DW.RED_Measured_States[2],
        &rtb_ThrustPer_Final[0]);

      // Product: '<S261>/Rotate F_I to F_b' incorporates:
      //   DataStoreRead: '<S235>/Data Store Read'

      q_mag = rtb_ThrustPer_Final[0] * rtb_w[0] + rtb_w[1] *
        rtb_ThrustPer_Final[2];
      yaw_quant = rtb_w[0] * rtb_ThrustPer_Final[1] + rtb_w[1] *
        rtb_ThrustPer_Final[3];

      // SignalConversion generated from: '<S263>/Product3' incorporates:
      //   DataStoreRead: '<S235>/Data Store Read'

      Red_x[2] = rtb_w[2];

      // MATLAB Function: '<S263>/MATLAB Function'
      for (i = 0; i < 8; i++) {
        Red_dq[i] = Fullexp_P.F_thrusters_RED[i] / 2.0;
      }

      memset(&y_0[0], 0, sizeof(real_T) << 6U);
      for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++) {
        y_0[q_minus_inv_tmp + (q_minus_inv_tmp << 3)] = Red_dq[q_minus_inv_tmp];

        // MATLAB Function: '<S260>/MATLAB Function5'
        rtb_H_tmp[3 * q_minus_inv_tmp] = b_0[q_minus_inv_tmp];
        rtb_H_tmp[3 * q_minus_inv_tmp + 1] = c_1[q_minus_inv_tmp];
        rtb_H_tmp[3 * q_minus_inv_tmp + 2] =
          Fullexp_P.thruster_dist2CG_RED[q_minus_inv_tmp] / 1000.0;
      }

      for (d_j = 0; d_j < 8; d_j++) {
        for (i = 0; i < 3; i++) {
          thrust_decay_factor = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++) {
            thrust_decay_factor += rtb_H_tmp[3 * q_minus_inv_tmp + i] * y_0[(d_j
              << 3) + q_minus_inv_tmp];
          }

          rtb_H[i + 3 * d_j] = thrust_decay_factor;
        }
      }

      // End of MATLAB Function: '<S263>/MATLAB Function'
      Fullexp_Pseudoinverse1(rtb_H, &Fullexp_B.Pseudoinverse1_pn);

      // MATLAB Function: '<S260>/MATLAB Function5'
      thrust_decay_factor = 1.0;
      theta = 2.0 * Fullexp_P.MATLABFunction5_tol_g;
      for (d_j = 0; d_j < 8; d_j++) {
        // Product: '<S263>/Product3' incorporates:
        //   MATLABSystem: '<S263>/Pseudoinverse1'
        //   Product: '<S261>/Rotate F_I to F_b'

        sampleTime_0 = (Fullexp_B.Pseudoinverse1_pn.Pseudoinverse1[d_j + 8] *
                        yaw_quant +
                        Fullexp_B.Pseudoinverse1_pn.Pseudoinverse1[d_j] * q_mag)
          + Fullexp_B.Pseudoinverse1_pn.Pseudoinverse1[d_j + 16] * Red_x[2];
        Fullexp_B.duty_cycles[d_j] = sampleTime_0;

        // MATLAB Function: '<S260>/MATLAB Function5' incorporates:
        //   Product: '<S263>/Product3'

        Red_dq[d_j] = sampleTime_0 + theta;
      }

      // MATLAB Function: '<S260>/MATLAB Function5'
      samplesRead = 0;
      do {
        exitg1 = 0;
        if (samplesRead <= static_cast<int32_T>
            (Fullexp_P.MATLABFunction5_max_iters_e) - 1) {
          dt = Fullexp_P.F_red_X_nominal * thrust_decay_factor / 2.0;
          rtb_dq_e[0] = dt;
          rtb_dq_e[1] = dt;
          thrust_decay_factor = Fullexp_P.F_red_Y_nominal * thrust_decay_factor /
            2.0;
          rtb_dq_e[2] = thrust_decay_factor;
          rtb_dq_e[3] = thrust_decay_factor;
          rtb_dq_e[4] = dt;
          rtb_dq_e[5] = dt;
          rtb_dq_e[6] = thrust_decay_factor;
          rtb_dq_e[7] = thrust_decay_factor;
          memset(&y_0[0], 0, sizeof(real_T) << 6U);
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++) {
            y_0[q_minus_inv_tmp + (q_minus_inv_tmp << 3)] =
              rtb_dq_e[q_minus_inv_tmp];
          }

          for (d_j = 0; d_j < 3; d_j++) {
            for (i = 0; i < 8; i++) {
              thrust_decay_factor = 0.0;
              for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++)
              {
                thrust_decay_factor += rtb_H_tmp[3 * q_minus_inv_tmp + d_j] *
                  y_0[(i << 3) + q_minus_inv_tmp];
              }

              rtb_H[d_j + 3 * i] = thrust_decay_factor;
              tmp[i + (d_j << 3)] = thrust_decay_factor;
            }
          }

          for (d_j = 0; d_j < 8; d_j++) {
            theta = tmp[d_j + 8];
            thrust_decay_factor = tmp[d_j];
            sampleTime_0 = tmp[d_j + 16];
            for (i = 0; i < 8; i++) {
              y_0[d_j + (i << 3)] = (rtb_H[3 * i + 1] * theta + rtb_H[3 * i] *
                thrust_decay_factor) + rtb_H[3 * i + 2] * sampleTime_0;
            }

            q_minus_inv_0[d_j] = (theta * yaw_quant + thrust_decay_factor *
                                  q_mag) + sampleTime_0 * Red_x[2];
          }

          for (d_j = 0; d_j < 64; d_j++) {
            tmp_4[d_j] = 2.0 * y_0[d_j];
          }

          for (d_j = 0; d_j < 8; d_j++) {
            tmp_2[d_j] = -2.0 * q_minus_inv_0[d_j];
          }

          Fullexp_quadprog(tmp_4, tmp_2, Fullexp_B.duty_cycles, rtb_dq_e,
                           &thrust_decay_factor, &sampleTime_0);
          memcpy(&Fullexp_B.duty_cycles[0], &rtb_dq_e[0], sizeof(real_T) << 3U);
          memcpy(&z_meas[0], &rtb_dq_e[0], sizeof(real_T) << 3U);
          thrust_decay_factor = Fullexp_maximum_i(rtb_dq_e);
          if (thrust_decay_factor > 1.0) {
            for (d_j = 0; d_j < 8; d_j++) {
              z_meas[d_j] = rtb_dq_e[d_j] / thrust_decay_factor;
            }
          }

          for (d_j = 0; d_j < 8; d_j++) {
            x[d_j] = (z_meas[d_j] > 0.0);
          }

          nz = x[0];
          for (samplesRead_1 = 0; samplesRead_1 < 7; samplesRead_1++) {
            nz += x[samplesRead_1 + 1];
          }

          for (samplesRead_1 = 0; samplesRead_1 < 8; samplesRead_1++) {
            theta = z_meas[samplesRead_1];
            if (theta >= 0.0) {
              q_pred[samplesRead_1] = theta;
            } else {
              q_pred[samplesRead_1] = 0.0;
            }
          }

          n2 = q_pred[0];
          for (i = 0; i < 7; i++) {
            n2 += q_pred[i + 1];
          }

          if (nz >= 1) {
            d_j = nz;
          } else {
            d_j = 1;
          }

          thrust_decay_factor = n2 / static_cast<real_T>(d_j);
          if ((thrust_decay_factor < 0.3) || (nz == 0)) {
            thrust_decay_factor = 1.0;
          } else {
            thrust_decay_factor = (0.6 - 2.0 * thrust_decay_factor) + 1.0;
            if (!(thrust_decay_factor >= 0.5)) {
              thrust_decay_factor = 0.5;
            }
          }

          dt = 0.0;
          for (i = 0; i < 8; i++) {
            sampleTime_0 = rtb_dq_e[i] - Red_dq[i];
            Red_dq[i] = sampleTime_0;
            sampleTime_0 = fabs(sampleTime_0);
            if (rtIsNaN(sampleTime_0)) {
              dt = (rtNaN);
            } else if (sampleTime_0 > dt) {
              dt = sampleTime_0;
            }
          }

          if (dt < Fullexp_P.MATLABFunction5_tol_g) {
            dt = Fullexp_P.F_red_X_nominal * thrust_decay_factor;
            rtb_dq_e[0] = dt;
            rtb_dq_e[1] = dt;
            thrust_decay_factor *= Fullexp_P.F_red_Y_nominal;
            rtb_dq_e[2] = thrust_decay_factor;
            rtb_dq_e[3] = thrust_decay_factor;
            rtb_dq_e[4] = dt;
            rtb_dq_e[5] = dt;
            rtb_dq_e[6] = thrust_decay_factor;
            rtb_dq_e[7] = thrust_decay_factor;
            memset(&y_0[0], 0, sizeof(real_T) << 6U);
            for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++) {
              y_0[q_minus_inv_tmp + (q_minus_inv_tmp << 3)] =
                rtb_dq_e[q_minus_inv_tmp];
            }

            for (d_j = 0; d_j < 8; d_j++) {
              for (i = 0; i < 3; i++) {
                thrust_decay_factor = 0.0;
                for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++)
                {
                  thrust_decay_factor += rtb_H_tmp[3 * q_minus_inv_tmp + i] *
                    y_0[(d_j << 3) + q_minus_inv_tmp];
                }

                rtb_H[i + 3 * d_j] = thrust_decay_factor;
              }
            }

            exitg1 = 1;
          } else {
            memcpy(&Red_dq[0], &rtb_dq_e[0], sizeof(real_T) << 3U);
            samplesRead++;
          }
        } else {
          dt = Fullexp_P.F_red_X_nominal * thrust_decay_factor;
          rtb_dq_e[0] = dt;
          rtb_dq_e[1] = dt;
          thrust_decay_factor *= Fullexp_P.F_red_Y_nominal;
          rtb_dq_e[2] = thrust_decay_factor;
          rtb_dq_e[3] = thrust_decay_factor;
          rtb_dq_e[4] = dt;
          rtb_dq_e[5] = dt;
          rtb_dq_e[6] = thrust_decay_factor;
          rtb_dq_e[7] = thrust_decay_factor;
          memset(&y_0[0], 0, sizeof(real_T) << 6U);
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++) {
            y_0[q_minus_inv_tmp + (q_minus_inv_tmp << 3)] =
              rtb_dq_e[q_minus_inv_tmp];
          }

          for (d_j = 0; d_j < 8; d_j++) {
            for (i = 0; i < 3; i++) {
              thrust_decay_factor = 0.0;
              for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++)
              {
                thrust_decay_factor += rtb_H_tmp[3 * q_minus_inv_tmp + i] * y_0
                  [(d_j << 3) + q_minus_inv_tmp];
              }

              rtb_H[i + 3 * d_j] = thrust_decay_factor;
            }
          }

          exitg1 = 1;
        }
      } while (exitg1 == 0);

      // MATLAB Function: '<S260>/MATLAB Function8'
      Fullexp_MATLABFunction1(Fullexp_B.duty_cycles, rtb_ThrustPer_Final);

      // Outputs for Enabled SubSystem: '<S262>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S267>/Enable'

      if (Fullexp_DW.Delay_DSTATE_b >= 1.0 / Fullexp_P.PWMFreq) {
        // SignalConversion generated from: '<S267>/In1' incorporates:
        //   DataStoreRead: '<S262>/Data Store Read'

        Fullexp_B.In1 = Fullexp_DW.Univ_Time;
      }

      // End of Outputs for SubSystem: '<S262>/Enabled Subsystem'

      // Sum: '<S262>/Subtract' incorporates:
      //   Constant: '<S262>/Constant1'
      //   DataStoreRead: '<S262>/Data Store Read'
      //   Delay: '<S262>/Delay'
      //   RelationalOperator: '<S262>/Relational Operator1'

      Fullexp_DW.Delay_DSTATE_b = Fullexp_DW.Univ_Time - Fullexp_B.In1;

      // Outputs for Enabled SubSystem: '<S262>/Enabled Subsystem1' incorporates:
      //   EnablePort: '<S268>/Enable'

      if (Fullexp_DW.Delay_DSTATE_b == Fullexp_P.Constant2_Value_e) {
        // SignalConversion generated from: '<S268>/ThrustPer_Final'
        memcpy(&Fullexp_B.ThrustPer_Final[0], &rtb_ThrustPer_Final[0], sizeof
               (real_T) << 3U);
      }

      // End of Outputs for SubSystem: '<S262>/Enabled Subsystem1'

      // Product: '<S260>/Product1' incorporates:
      //   Constant: '<S262>/Constant2'
      //   Delay: '<S262>/Delay'
      //   RelationalOperator: '<S262>/Relational Operator2'

      for (d_j = 0; d_j < 3; d_j++) {
        thrust_decay_factor = 0.0;
        for (i = 0; i < 8; i++) {
          thrust_decay_factor += rtb_H[3 * i + d_j] *
            Fullexp_B.ThrustPer_Final[i];
        }

        Red_x[d_j] = thrust_decay_factor;
      }

      // End of Product: '<S260>/Product1'

      // DataStoreWrite: '<S235>/Data Store Write1' incorporates:
      //   Product: '<S266>/Rotate F_b to F_I'

      Fullexp_DW.RED_Saturated_Controls[0] = qr_0[0] * Red_x[0] + Red_x[1] *
        qr_0[2];
      Fullexp_DW.RED_Saturated_Controls[1] = Red_x[0] * qr_0[1] + Red_x[1] *
        qr_0[3];
      Fullexp_DW.RED_Saturated_Controls[2] = Red_x[2];

      // End of Outputs for SubSystem: '<S26>/Change RED Behavior'
    }

    // End of If: '<S26>/This IF block determines whether or not to run the RED sim//exp ' 

    // If: '<S26>/This IF block determines whether or not to run the BLACK sim//exp' incorporates:
    //   Constant: '<S238>/Constant1'
    //   Constant: '<S238>/Constant2'
    //   DataStoreRead: '<S26>/Data Store Read'
    //   DataStoreRead: '<S26>/Data Store Read1'
    //   Delay: '<S238>/Delay'
    //   RelationalOperator: '<S238>/Relational Operator1'
    //   RelationalOperator: '<S238>/Relational Operator2'

    if ((Fullexp_DW.WhoAmI == 2.0) || (Fullexp_DW.isSim == 1.0)) {
      // Outputs for IfAction SubSystem: '<S26>/Change BLACK Behavior' incorporates:
      //   ActionPort: '<S233>/Action Port'

      // MATLAB Function: '<S242>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S233>/BLACK States'

      Fullexp_CreateRotationMatrix(Fullexp_DW.BLACK_Measured_States[2], qr_0);

      // MATLAB Function: '<S237>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S233>/BLACK States'

      Fullexp_CreateRotationMatrix_a(Fullexp_DW.BLACK_Measured_States[2],
        &rtb_ThrustPer_Final_d[0]);

      // Product: '<S237>/Rotate F_I to F_b' incorporates:
      //   DataStoreRead: '<S233>/BLACK Controls'

      q_mag = rtb_ThrustPer_Final_d[0] * rtb_x_b[0] + rtb_x_b[1] *
        rtb_ThrustPer_Final_d[2];
      yaw_quant = rtb_x_b[0] * rtb_ThrustPer_Final_d[1] + rtb_x_b[1] *
        rtb_ThrustPer_Final_d[3];

      // SignalConversion generated from: '<S239>/Product3' incorporates:
      //   DataStoreRead: '<S233>/BLACK Controls'

      rtb_w[2] = rtb_x_b[2];

      // MATLAB Function: '<S239>/MATLAB Function'
      for (i = 0; i < 8; i++) {
        Red_dq[i] = Fullexp_P.F_thrusters_BLACK[i] / 2.0;
      }

      memset(&y_0[0], 0, sizeof(real_T) << 6U);
      for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++) {
        y_0[q_minus_inv_tmp + (q_minus_inv_tmp << 3)] = Red_dq[q_minus_inv_tmp];

        // MATLAB Function: '<S236>/MATLAB Function5'
        rtb_H_tmp[3 * q_minus_inv_tmp] = b_0[q_minus_inv_tmp];
        rtb_H_tmp[3 * q_minus_inv_tmp + 1] = c_1[q_minus_inv_tmp];
        rtb_H_tmp[3 * q_minus_inv_tmp + 2] =
          Fullexp_P.thruster_dist2CG_BLACK[q_minus_inv_tmp] / 1000.0;
      }

      for (d_j = 0; d_j < 8; d_j++) {
        for (i = 0; i < 3; i++) {
          thrust_decay_factor = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++) {
            thrust_decay_factor += rtb_H_tmp[3 * q_minus_inv_tmp + i] * y_0[(d_j
              << 3) + q_minus_inv_tmp];
          }

          rtb_H[i + 3 * d_j] = thrust_decay_factor;
        }
      }

      // End of MATLAB Function: '<S239>/MATLAB Function'
      Fullexp_Pseudoinverse1(rtb_H, &Fullexp_B.Pseudoinverse1);

      // MATLAB Function: '<S236>/MATLAB Function5'
      thrust_decay_factor = 1.0;
      theta = 2.0 * Fullexp_P.MATLABFunction5_tol;
      for (d_j = 0; d_j < 8; d_j++) {
        // Product: '<S239>/Product3' incorporates:
        //   MATLABSystem: '<S239>/Pseudoinverse1'
        //   Product: '<S237>/Rotate F_I to F_b'

        sampleTime_0 = (Fullexp_B.Pseudoinverse1.Pseudoinverse1[d_j + 8] *
                        yaw_quant + Fullexp_B.Pseudoinverse1.Pseudoinverse1[d_j]
                        * q_mag) + Fullexp_B.Pseudoinverse1.Pseudoinverse1[d_j +
          16] * rtb_w[2];
        Fullexp_B.duty_cycles_l[d_j] = sampleTime_0;

        // MATLAB Function: '<S236>/MATLAB Function5' incorporates:
        //   Product: '<S239>/Product3'

        Red_dq[d_j] = sampleTime_0 + theta;
      }

      // MATLAB Function: '<S236>/MATLAB Function5'
      samplesRead = 0;
      do {
        exitg1 = 0;
        if (samplesRead <= static_cast<int32_T>
            (Fullexp_P.MATLABFunction5_max_iters) - 1) {
          dt = Fullexp_P.F_black_X_nominal * thrust_decay_factor / 2.0;
          rtb_dq_e[0] = dt;
          rtb_dq_e[1] = dt;
          thrust_decay_factor = Fullexp_P.F_black_Y_nominal *
            thrust_decay_factor / 2.0;
          rtb_dq_e[2] = thrust_decay_factor;
          rtb_dq_e[3] = thrust_decay_factor;
          rtb_dq_e[4] = dt;
          rtb_dq_e[5] = dt;
          rtb_dq_e[6] = thrust_decay_factor;
          rtb_dq_e[7] = thrust_decay_factor;
          memset(&y_0[0], 0, sizeof(real_T) << 6U);
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++) {
            y_0[q_minus_inv_tmp + (q_minus_inv_tmp << 3)] =
              rtb_dq_e[q_minus_inv_tmp];
          }

          for (d_j = 0; d_j < 3; d_j++) {
            for (i = 0; i < 8; i++) {
              thrust_decay_factor = 0.0;
              for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++)
              {
                thrust_decay_factor += rtb_H_tmp[3 * q_minus_inv_tmp + d_j] *
                  y_0[(i << 3) + q_minus_inv_tmp];
              }

              rtb_H[d_j + 3 * i] = thrust_decay_factor;
              tmp[i + (d_j << 3)] = thrust_decay_factor;
            }
          }

          for (d_j = 0; d_j < 8; d_j++) {
            theta = tmp[d_j + 8];
            thrust_decay_factor = tmp[d_j];
            sampleTime_0 = tmp[d_j + 16];
            for (i = 0; i < 8; i++) {
              y_0[d_j + (i << 3)] = (rtb_H[3 * i + 1] * theta + rtb_H[3 * i] *
                thrust_decay_factor) + rtb_H[3 * i + 2] * sampleTime_0;
            }

            q_minus_inv_0[d_j] = (theta * yaw_quant + thrust_decay_factor *
                                  q_mag) + sampleTime_0 * rtb_w[2];
          }

          for (d_j = 0; d_j < 64; d_j++) {
            tmp_4[d_j] = 2.0 * y_0[d_j];
          }

          for (d_j = 0; d_j < 8; d_j++) {
            tmp_2[d_j] = -2.0 * q_minus_inv_0[d_j];
          }

          Fullexp_quadprog(tmp_4, tmp_2, Fullexp_B.duty_cycles_l, rtb_dq_e,
                           &thrust_decay_factor, &sampleTime_0);
          memcpy(&Fullexp_B.duty_cycles_l[0], &rtb_dq_e[0], sizeof(real_T) << 3U);
          memcpy(&z_meas[0], &rtb_dq_e[0], sizeof(real_T) << 3U);
          thrust_decay_factor = Fullexp_maximum_i(rtb_dq_e);
          if (thrust_decay_factor > 1.0) {
            for (d_j = 0; d_j < 8; d_j++) {
              z_meas[d_j] = rtb_dq_e[d_j] / thrust_decay_factor;
            }
          }

          for (d_j = 0; d_j < 8; d_j++) {
            x[d_j] = (z_meas[d_j] > 0.0);
          }

          nz = x[0];
          for (samplesRead_1 = 0; samplesRead_1 < 7; samplesRead_1++) {
            nz += x[samplesRead_1 + 1];
          }

          for (samplesRead_1 = 0; samplesRead_1 < 8; samplesRead_1++) {
            theta = z_meas[samplesRead_1];
            if (theta >= 0.0) {
              q_pred[samplesRead_1] = theta;
            } else {
              q_pred[samplesRead_1] = 0.0;
            }
          }

          n2 = q_pred[0];
          for (i = 0; i < 7; i++) {
            n2 += q_pred[i + 1];
          }

          if (nz >= 1) {
            d_j = nz;
          } else {
            d_j = 1;
          }

          thrust_decay_factor = n2 / static_cast<real_T>(d_j);
          if ((thrust_decay_factor < 0.3) || (nz == 0)) {
            thrust_decay_factor = 1.0;
          } else {
            thrust_decay_factor = (0.6 - 2.0 * thrust_decay_factor) + 1.0;
            if (!(thrust_decay_factor >= 0.5)) {
              thrust_decay_factor = 0.5;
            }
          }

          dt = 0.0;
          for (i = 0; i < 8; i++) {
            sampleTime_0 = rtb_dq_e[i] - Red_dq[i];
            Red_dq[i] = sampleTime_0;
            sampleTime_0 = fabs(sampleTime_0);
            if (rtIsNaN(sampleTime_0)) {
              dt = (rtNaN);
            } else if (sampleTime_0 > dt) {
              dt = sampleTime_0;
            }
          }

          if (dt < Fullexp_P.MATLABFunction5_tol) {
            dt = Fullexp_P.F_black_X_nominal * thrust_decay_factor;
            rtb_dq_e[0] = dt;
            rtb_dq_e[1] = dt;
            thrust_decay_factor *= Fullexp_P.F_black_Y_nominal;
            rtb_dq_e[2] = thrust_decay_factor;
            rtb_dq_e[3] = thrust_decay_factor;
            rtb_dq_e[4] = dt;
            rtb_dq_e[5] = dt;
            rtb_dq_e[6] = thrust_decay_factor;
            rtb_dq_e[7] = thrust_decay_factor;
            memset(&y_0[0], 0, sizeof(real_T) << 6U);
            for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++) {
              y_0[q_minus_inv_tmp + (q_minus_inv_tmp << 3)] =
                rtb_dq_e[q_minus_inv_tmp];
            }

            for (d_j = 0; d_j < 8; d_j++) {
              for (i = 0; i < 3; i++) {
                thrust_decay_factor = 0.0;
                for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++)
                {
                  thrust_decay_factor += rtb_H_tmp[3 * q_minus_inv_tmp + i] *
                    y_0[(d_j << 3) + q_minus_inv_tmp];
                }

                rtb_H[i + 3 * d_j] = thrust_decay_factor;
              }
            }

            exitg1 = 1;
          } else {
            memcpy(&Red_dq[0], &rtb_dq_e[0], sizeof(real_T) << 3U);
            samplesRead++;
          }
        } else {
          dt = Fullexp_P.F_black_X_nominal * thrust_decay_factor;
          rtb_dq_e[0] = dt;
          rtb_dq_e[1] = dt;
          thrust_decay_factor *= Fullexp_P.F_black_Y_nominal;
          rtb_dq_e[2] = thrust_decay_factor;
          rtb_dq_e[3] = thrust_decay_factor;
          rtb_dq_e[4] = dt;
          rtb_dq_e[5] = dt;
          rtb_dq_e[6] = thrust_decay_factor;
          rtb_dq_e[7] = thrust_decay_factor;
          memset(&y_0[0], 0, sizeof(real_T) << 6U);
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++) {
            y_0[q_minus_inv_tmp + (q_minus_inv_tmp << 3)] =
              rtb_dq_e[q_minus_inv_tmp];
          }

          for (d_j = 0; d_j < 8; d_j++) {
            for (i = 0; i < 3; i++) {
              thrust_decay_factor = 0.0;
              for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++)
              {
                thrust_decay_factor += rtb_H_tmp[3 * q_minus_inv_tmp + i] * y_0
                  [(d_j << 3) + q_minus_inv_tmp];
              }

              rtb_H[i + 3 * d_j] = thrust_decay_factor;
            }
          }

          exitg1 = 1;
        }
      } while (exitg1 == 0);

      // MATLAB Function: '<S236>/MATLAB Function1'
      Fullexp_MATLABFunction1(Fullexp_B.duty_cycles_l, rtb_ThrustPer_Final_d);

      // Outputs for Enabled SubSystem: '<S238>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S243>/Enable'

      if (Fullexp_DW.Delay_DSTATE_kz >= 1.0 / Fullexp_P.PWMFreq) {
        // SignalConversion generated from: '<S243>/In1' incorporates:
        //   DataStoreRead: '<S238>/Data Store Read'

        Fullexp_B.In1_g2 = Fullexp_DW.Univ_Time;
      }

      // End of Outputs for SubSystem: '<S238>/Enabled Subsystem'

      // Sum: '<S238>/Subtract' incorporates:
      //   Constant: '<S238>/Constant1'
      //   DataStoreRead: '<S238>/Data Store Read'
      //   Delay: '<S238>/Delay'
      //   RelationalOperator: '<S238>/Relational Operator1'

      Fullexp_DW.Delay_DSTATE_kz = Fullexp_DW.Univ_Time - Fullexp_B.In1_g2;

      // Outputs for Enabled SubSystem: '<S238>/Enabled Subsystem1' incorporates:
      //   EnablePort: '<S244>/Enable'

      if (Fullexp_DW.Delay_DSTATE_kz == Fullexp_P.Constant2_Value_h) {
        // SignalConversion generated from: '<S244>/ThrustPer_Final'
        memcpy(&Fullexp_B.ThrustPer_Final_h5[0], &rtb_ThrustPer_Final_d[0],
               sizeof(real_T) << 3U);
      }

      // End of Outputs for SubSystem: '<S238>/Enabled Subsystem1'

      // Product: '<S236>/Product1' incorporates:
      //   Constant: '<S238>/Constant2'
      //   Delay: '<S238>/Delay'
      //   RelationalOperator: '<S238>/Relational Operator2'

      for (d_j = 0; d_j < 3; d_j++) {
        thrust_decay_factor = 0.0;
        for (i = 0; i < 8; i++) {
          thrust_decay_factor += rtb_H[3 * i + d_j] *
            Fullexp_B.ThrustPer_Final_h5[i];
        }

        rtb_w[d_j] = thrust_decay_factor;
      }

      // End of Product: '<S236>/Product1'

      // DataStoreWrite: '<S233>/Data Store Write2' incorporates:
      //   Product: '<S242>/Rotate F_b to F_I'

      Fullexp_DW.BLACK_Saturated_Controls[0] = qr_0[0] * rtb_w[0] + rtb_w[1] *
        qr_0[2];
      Fullexp_DW.BLACK_Saturated_Controls[1] = rtb_w[0] * qr_0[1] + rtb_w[1] *
        qr_0[3];
      Fullexp_DW.BLACK_Saturated_Controls[2] = rtb_w[2];

      // End of Outputs for SubSystem: '<S26>/Change BLACK Behavior'
    }

    // End of If: '<S26>/This IF block determines whether or not to run the BLACK sim//exp' 

    // If: '<S26>/This IF block determines whether or not to run the BLUE sim//exp' incorporates:
    //   Constant: '<S250>/Constant1'
    //   Constant: '<S250>/Constant2'
    //   DataStoreRead: '<S26>/Data Store Read'
    //   DataStoreRead: '<S26>/Data Store Read1'
    //   Delay: '<S250>/Delay'
    //   RelationalOperator: '<S250>/Relational Operator1'
    //   RelationalOperator: '<S250>/Relational Operator2'

    if ((Fullexp_DW.WhoAmI == 3.0) || (Fullexp_DW.isSim == 1.0)) {
      // Outputs for IfAction SubSystem: '<S26>/Change BLUE Behavior' incorporates:
      //   ActionPort: '<S234>/Action Port'

      // MATLAB Function: '<S254>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S234>/Data Store Read1'

      Fullexp_CreateRotationMatrix(Fullexp_DW.BLUE_Measured_States[2], qr_0);

      // MATLAB Function: '<S249>/Create Rotation Matrix' incorporates:
      //   DataStoreRead: '<S234>/Data Store Read1'

      Fullexp_CreateRotationMatrix_a(Fullexp_DW.BLUE_Measured_States[2],
        &rtb_ThrustPer_Final_b[0]);

      // Product: '<S249>/Rotate F_I to F_b' incorporates:
      //   DataStoreRead: '<S234>/Data Store Read'

      q_mag = rtb_ThrustPer_Final_b[0] * rtb_v[0] + rtb_v[1] *
        rtb_ThrustPer_Final_b[2];
      yaw_quant = rtb_v[0] * rtb_ThrustPer_Final_b[1] + rtb_v[1] *
        rtb_ThrustPer_Final_b[3];

      // SignalConversion generated from: '<S251>/Product3' incorporates:
      //   DataStoreRead: '<S234>/Data Store Read'

      rtb_x_b[2] = rtb_v[2];

      // MATLAB Function: '<S251>/MATLAB Function'
      for (i = 0; i < 8; i++) {
        Red_dq[i] = Fullexp_P.F_thrusters_BLUE[i] / 2.0;
      }

      memset(&y_0[0], 0, sizeof(real_T) << 6U);
      for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++) {
        y_0[q_minus_inv_tmp + (q_minus_inv_tmp << 3)] = Red_dq[q_minus_inv_tmp];

        // MATLAB Function: '<S248>/MATLAB Function5'
        rtb_H_tmp[3 * q_minus_inv_tmp] = b_0[q_minus_inv_tmp];
        rtb_H_tmp[3 * q_minus_inv_tmp + 1] = c_1[q_minus_inv_tmp];
        rtb_H_tmp[3 * q_minus_inv_tmp + 2] =
          Fullexp_P.thruster_dist2CG_BLUE[q_minus_inv_tmp] / 1000.0;
      }

      for (d_j = 0; d_j < 8; d_j++) {
        for (i = 0; i < 3; i++) {
          thrust_decay_factor = 0.0;
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++) {
            thrust_decay_factor += rtb_H_tmp[3 * q_minus_inv_tmp + i] * y_0[(d_j
              << 3) + q_minus_inv_tmp];
          }

          rtb_H[i + 3 * d_j] = thrust_decay_factor;
        }
      }

      // End of MATLAB Function: '<S251>/MATLAB Function'
      Fullexp_Pseudoinverse1(rtb_H, &Fullexp_B.Pseudoinverse1_p);

      // MATLAB Function: '<S248>/MATLAB Function5'
      thrust_decay_factor = 1.0;
      theta = 2.0 * Fullexp_P.MATLABFunction5_tol_m;
      for (d_j = 0; d_j < 8; d_j++) {
        // Product: '<S251>/Product3' incorporates:
        //   MATLABSystem: '<S251>/Pseudoinverse1'
        //   Product: '<S249>/Rotate F_I to F_b'

        sampleTime_0 = (Fullexp_B.Pseudoinverse1_p.Pseudoinverse1[d_j + 8] *
                        yaw_quant +
                        Fullexp_B.Pseudoinverse1_p.Pseudoinverse1[d_j] * q_mag)
          + Fullexp_B.Pseudoinverse1_p.Pseudoinverse1[d_j + 16] * rtb_x_b[2];
        Fullexp_B.duty_cycles_p[d_j] = sampleTime_0;

        // MATLAB Function: '<S248>/MATLAB Function5' incorporates:
        //   Product: '<S251>/Product3'

        Red_dq[d_j] = sampleTime_0 + theta;
      }

      // MATLAB Function: '<S248>/MATLAB Function5'
      samplesRead = 0;
      do {
        exitg1 = 0;
        if (samplesRead <= static_cast<int32_T>
            (Fullexp_P.MATLABFunction5_max_iters_c) - 1) {
          dt = Fullexp_P.F_blue_X_nominal * thrust_decay_factor / 2.0;
          rtb_dq_e[0] = dt;
          rtb_dq_e[1] = dt;
          thrust_decay_factor = Fullexp_P.F_blue_Y_nominal * thrust_decay_factor
            / 2.0;
          rtb_dq_e[2] = thrust_decay_factor;
          rtb_dq_e[3] = thrust_decay_factor;
          rtb_dq_e[4] = dt;
          rtb_dq_e[5] = dt;
          rtb_dq_e[6] = thrust_decay_factor;
          rtb_dq_e[7] = thrust_decay_factor;
          memset(&y_0[0], 0, sizeof(real_T) << 6U);
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++) {
            y_0[q_minus_inv_tmp + (q_minus_inv_tmp << 3)] =
              rtb_dq_e[q_minus_inv_tmp];
          }

          for (d_j = 0; d_j < 3; d_j++) {
            for (i = 0; i < 8; i++) {
              thrust_decay_factor = 0.0;
              for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++)
              {
                thrust_decay_factor += rtb_H_tmp[3 * q_minus_inv_tmp + d_j] *
                  y_0[(i << 3) + q_minus_inv_tmp];
              }

              rtb_H[d_j + 3 * i] = thrust_decay_factor;
              tmp[i + (d_j << 3)] = thrust_decay_factor;
            }
          }

          for (d_j = 0; d_j < 8; d_j++) {
            theta = tmp[d_j + 8];
            thrust_decay_factor = tmp[d_j];
            sampleTime_0 = tmp[d_j + 16];
            for (i = 0; i < 8; i++) {
              y_0[d_j + (i << 3)] = (rtb_H[3 * i + 1] * theta + rtb_H[3 * i] *
                thrust_decay_factor) + rtb_H[3 * i + 2] * sampleTime_0;
            }

            q_minus_inv_0[d_j] = (theta * yaw_quant + thrust_decay_factor *
                                  q_mag) + sampleTime_0 * rtb_x_b[2];
          }

          for (d_j = 0; d_j < 64; d_j++) {
            tmp_4[d_j] = 2.0 * y_0[d_j];
          }

          for (d_j = 0; d_j < 8; d_j++) {
            tmp_2[d_j] = -2.0 * q_minus_inv_0[d_j];
          }

          Fullexp_quadprog(tmp_4, tmp_2, Fullexp_B.duty_cycles_p, rtb_dq_e,
                           &thrust_decay_factor, &sampleTime_0);
          memcpy(&Fullexp_B.duty_cycles_p[0], &rtb_dq_e[0], sizeof(real_T) << 3U);
          memcpy(&z_meas[0], &rtb_dq_e[0], sizeof(real_T) << 3U);
          thrust_decay_factor = Fullexp_maximum_i(rtb_dq_e);
          if (thrust_decay_factor > 1.0) {
            for (d_j = 0; d_j < 8; d_j++) {
              z_meas[d_j] = rtb_dq_e[d_j] / thrust_decay_factor;
            }
          }

          for (d_j = 0; d_j < 8; d_j++) {
            x[d_j] = (z_meas[d_j] > 0.0);
          }

          nz = x[0];
          for (samplesRead_1 = 0; samplesRead_1 < 7; samplesRead_1++) {
            nz += x[samplesRead_1 + 1];
          }

          for (samplesRead_1 = 0; samplesRead_1 < 8; samplesRead_1++) {
            theta = z_meas[samplesRead_1];
            if (theta >= 0.0) {
              q_pred[samplesRead_1] = theta;
            } else {
              q_pred[samplesRead_1] = 0.0;
            }
          }

          n2 = q_pred[0];
          for (i = 0; i < 7; i++) {
            n2 += q_pred[i + 1];
          }

          if (nz >= 1) {
            d_j = nz;
          } else {
            d_j = 1;
          }

          thrust_decay_factor = n2 / static_cast<real_T>(d_j);
          if ((thrust_decay_factor < 0.3) || (nz == 0)) {
            thrust_decay_factor = 1.0;
          } else {
            thrust_decay_factor = (0.6 - 2.0 * thrust_decay_factor) + 1.0;
            if (!(thrust_decay_factor >= 0.5)) {
              thrust_decay_factor = 0.5;
            }
          }

          dt = 0.0;
          for (i = 0; i < 8; i++) {
            sampleTime_0 = rtb_dq_e[i] - Red_dq[i];
            Red_dq[i] = sampleTime_0;
            sampleTime_0 = fabs(sampleTime_0);
            if (rtIsNaN(sampleTime_0)) {
              dt = (rtNaN);
            } else if (sampleTime_0 > dt) {
              dt = sampleTime_0;
            }
          }

          if (dt < Fullexp_P.MATLABFunction5_tol_m) {
            dt = Fullexp_P.F_blue_X_nominal * thrust_decay_factor;
            rtb_dq_e[0] = dt;
            rtb_dq_e[1] = dt;
            thrust_decay_factor *= Fullexp_P.F_blue_Y_nominal;
            rtb_dq_e[2] = thrust_decay_factor;
            rtb_dq_e[3] = thrust_decay_factor;
            rtb_dq_e[4] = dt;
            rtb_dq_e[5] = dt;
            rtb_dq_e[6] = thrust_decay_factor;
            rtb_dq_e[7] = thrust_decay_factor;
            memset(&y_0[0], 0, sizeof(real_T) << 6U);
            for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++) {
              y_0[q_minus_inv_tmp + (q_minus_inv_tmp << 3)] =
                rtb_dq_e[q_minus_inv_tmp];
            }

            for (d_j = 0; d_j < 8; d_j++) {
              for (i = 0; i < 3; i++) {
                thrust_decay_factor = 0.0;
                for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++)
                {
                  thrust_decay_factor += rtb_H_tmp[3 * q_minus_inv_tmp + i] *
                    y_0[(d_j << 3) + q_minus_inv_tmp];
                }

                rtb_H[i + 3 * d_j] = thrust_decay_factor;
              }
            }

            exitg1 = 1;
          } else {
            memcpy(&Red_dq[0], &rtb_dq_e[0], sizeof(real_T) << 3U);
            samplesRead++;
          }
        } else {
          dt = Fullexp_P.F_blue_X_nominal * thrust_decay_factor;
          rtb_dq_e[0] = dt;
          rtb_dq_e[1] = dt;
          thrust_decay_factor *= Fullexp_P.F_blue_Y_nominal;
          rtb_dq_e[2] = thrust_decay_factor;
          rtb_dq_e[3] = thrust_decay_factor;
          rtb_dq_e[4] = dt;
          rtb_dq_e[5] = dt;
          rtb_dq_e[6] = thrust_decay_factor;
          rtb_dq_e[7] = thrust_decay_factor;
          memset(&y_0[0], 0, sizeof(real_T) << 6U);
          for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++) {
            y_0[q_minus_inv_tmp + (q_minus_inv_tmp << 3)] =
              rtb_dq_e[q_minus_inv_tmp];
          }

          for (d_j = 0; d_j < 8; d_j++) {
            for (i = 0; i < 3; i++) {
              thrust_decay_factor = 0.0;
              for (q_minus_inv_tmp = 0; q_minus_inv_tmp < 8; q_minus_inv_tmp++)
              {
                thrust_decay_factor += rtb_H_tmp[3 * q_minus_inv_tmp + i] * y_0
                  [(d_j << 3) + q_minus_inv_tmp];
              }

              rtb_H[i + 3 * d_j] = thrust_decay_factor;
            }
          }

          exitg1 = 1;
        }
      } while (exitg1 == 0);

      // MATLAB Function: '<S248>/MATLAB Function1'
      Fullexp_MATLABFunction1(Fullexp_B.duty_cycles_p, rtb_ThrustPer_Final_b);

      // Outputs for Enabled SubSystem: '<S250>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S255>/Enable'

      if (Fullexp_DW.Delay_DSTATE_kf >= 1.0 / Fullexp_P.PWMFreq) {
        // SignalConversion generated from: '<S255>/In1' incorporates:
        //   DataStoreRead: '<S250>/Data Store Read'

        Fullexp_B.In1_g = Fullexp_DW.Univ_Time;
      }

      // End of Outputs for SubSystem: '<S250>/Enabled Subsystem'

      // Sum: '<S250>/Subtract' incorporates:
      //   Constant: '<S250>/Constant1'
      //   DataStoreRead: '<S250>/Data Store Read'
      //   Delay: '<S250>/Delay'
      //   RelationalOperator: '<S250>/Relational Operator1'

      Fullexp_DW.Delay_DSTATE_kf = Fullexp_DW.Univ_Time - Fullexp_B.In1_g;

      // Outputs for Enabled SubSystem: '<S250>/Enabled Subsystem1' incorporates:
      //   EnablePort: '<S256>/Enable'

      if (Fullexp_DW.Delay_DSTATE_kf == Fullexp_P.Constant2_Value_fq) {
        // SignalConversion generated from: '<S256>/ThrustPer_Final'
        memcpy(&Fullexp_B.ThrustPer_Final_h[0], &rtb_ThrustPer_Final_b[0],
               sizeof(real_T) << 3U);
      }

      // End of Outputs for SubSystem: '<S250>/Enabled Subsystem1'

      // Product: '<S248>/Product1' incorporates:
      //   Constant: '<S250>/Constant2'
      //   Delay: '<S250>/Delay'
      //   RelationalOperator: '<S250>/Relational Operator2'

      for (d_j = 0; d_j < 3; d_j++) {
        thrust_decay_factor = 0.0;
        for (i = 0; i < 8; i++) {
          thrust_decay_factor += rtb_H[3 * i + d_j] *
            Fullexp_B.ThrustPer_Final_h[i];
        }

        rtb_x_b[d_j] = thrust_decay_factor;
      }

      // End of Product: '<S248>/Product1'

      // DataStoreWrite: '<S234>/Data Store Write3' incorporates:
      //   Product: '<S254>/Rotate F_b to F_I'

      Fullexp_DW.BLUE_Saturated_Controls[0] = qr_0[0] * rtb_x_b[0] + rtb_x_b[1] *
        qr_0[2];
      Fullexp_DW.BLUE_Saturated_Controls[1] = rtb_x_b[0] * qr_0[1] + rtb_x_b[1] *
        qr_0[3];
      Fullexp_DW.BLUE_Saturated_Controls[2] = rtb_x_b[2];

      // End of Outputs for SubSystem: '<S26>/Change BLUE Behavior'
    }

    // End of If: '<S26>/This IF block determines whether or not to run the BLUE sim//exp' 

    // SignalConversion generated from: '<S26>/UDP Send' incorporates:
    //   Constant: '<S26>/PWM Frequency'
    //   Constant: '<S26>/Safety Number'
    //   Gain: '<S26>/Gain'
    //   Gain: '<S26>/Gain1'
    //   Gain: '<S26>/Gain2'
    //   Gain: '<S26>/Gain3'
    //   Gain: '<S26>/Gain4'
    //   Gain: '<S26>/Gain5'
    //   Gain: '<S26>/Gain6'
    //   Gain: '<S26>/Gain7'
    //   Sum: '<S26>/Sum'
    //   Sum: '<S26>/Sum1'
    //   Sum: '<S26>/Sum2'
    //   Sum: '<S26>/Sum3'
    //   Sum: '<S26>/Sum4'
    //   Sum: '<S26>/Sum5'
    //   Sum: '<S26>/Sum6'
    //   Sum: '<S26>/Sum7'

    Fullexp_B.TmpSignalConversionAtUDPSendInp[0] = Fullexp_P.SafetyNumber_Value;
    Fullexp_B.TmpSignalConversionAtUDPSendInp[1] = Fullexp_P.PWMFreq;
    Fullexp_B.TmpSignalConversionAtUDPSendInp[2] = ((Fullexp_B.duty_cycles[0] +
      Fullexp_B.duty_cycles_l[0]) + Fullexp_B.duty_cycles_p[0]) *
      Fullexp_P.Gain_Gain_oy;
    Fullexp_B.TmpSignalConversionAtUDPSendInp[3] = ((Fullexp_B.duty_cycles[1] +
      Fullexp_B.duty_cycles_l[1]) + Fullexp_B.duty_cycles_p[1]) *
      Fullexp_P.Gain1_Gain_e;
    Fullexp_B.TmpSignalConversionAtUDPSendInp[4] = ((Fullexp_B.duty_cycles[2] +
      Fullexp_B.duty_cycles_l[2]) + Fullexp_B.duty_cycles_p[2]) *
      Fullexp_P.Gain2_Gain;
    Fullexp_B.TmpSignalConversionAtUDPSendInp[5] = ((Fullexp_B.duty_cycles[3] +
      Fullexp_B.duty_cycles_l[3]) + Fullexp_B.duty_cycles_p[3]) *
      Fullexp_P.Gain3_Gain;
    Fullexp_B.TmpSignalConversionAtUDPSendInp[6] = ((Fullexp_B.duty_cycles[4] +
      Fullexp_B.duty_cycles_l[4]) + Fullexp_B.duty_cycles_p[4]) *
      Fullexp_P.Gain4_Gain;
    Fullexp_B.TmpSignalConversionAtUDPSendInp[7] = ((Fullexp_B.duty_cycles[5] +
      Fullexp_B.duty_cycles_l[5]) + Fullexp_B.duty_cycles_p[5]) *
      Fullexp_P.Gain5_Gain;
    Fullexp_B.TmpSignalConversionAtUDPSendInp[8] = ((Fullexp_B.duty_cycles[6] +
      Fullexp_B.duty_cycles_l[6]) + Fullexp_B.duty_cycles_p[6]) *
      Fullexp_P.Gain6_Gain_c;
    Fullexp_B.TmpSignalConversionAtUDPSendInp[9] = ((Fullexp_B.duty_cycles[7] +
      Fullexp_B.duty_cycles_l[7]) + Fullexp_B.duty_cycles_p[7]) *
      Fullexp_P.Gain7_Gain_l;
  }

  {
    char_T *sErr;

    // Update for Delay: '<Root>/Delay'
    Fullexp_DW.Delay_DSTATE = Fullexp_B.Clock;

    // Update for Delay: '<S5>/Delay1'
    memcpy(&Fullexp_DW.Delay1_DSTATE[0], &Fullexp_B.x_est_c[0], 14U * sizeof
           (real_T));

    // Update for Delay: '<S5>/Delay' incorporates:
    //   DataStoreWrite: '<S5>/Data Store Write18'

    memcpy(&Fullexp_DW.Delay_DSTATE_d[0], &Fullexp_DW.DQMEKFP[0], 144U * sizeof
           (real_T));

    // Update for Delay: '<S16>/Delay1'
    memcpy(&Fullexp_DW.Delay1_DSTATE_e[0], &Fullexp_B.x_est_dp[0], 13U * sizeof
           (real_T));

    // Update for Delay: '<S16>/Delay' incorporates:
    //   DataStoreWrite: '<S16>/Data Store Write18'

    memcpy(&Fullexp_DW.Delay_DSTATE_k[0], &Fullexp_DW.QMEKFP[0], 144U * sizeof
           (real_T));

    // Update for Delay: '<S17>/Delay1'
    memcpy(&Fullexp_DW.Delay1_DSTATE_o[0], &Fullexp_B.x_est_m[0], 9U * sizeof
           (real_T));

    // Update for Delay: '<S17>/Delay2' incorporates:
    //   DataStoreWrite: '<S17>/Data Store Write1'

    memcpy(&Fullexp_DW.Delay2_DSTATE[0], &Fullexp_DW.RMEKFR[0], 9U * sizeof
           (real_T));

    // Update for Delay: '<S17>/Delay' incorporates:
    //   DataStoreWrite: '<S17>/Data Store Write18'

    memcpy(&Fullexp_DW.Delay_DSTATE_n[0], &Fullexp_DW.RMEKFP[0], 144U * sizeof
           (real_T));

    // Update for Delay: '<S22>/Delay1'
    memcpy(&Fullexp_DW.Delay1_DSTATE_b[0], &Fullexp_B.x_est_d[0], 14U * sizeof
           (real_T));

    // Update for Delay: '<S22>/Delay' incorporates:
    //   DataStoreWrite: '<S22>/Data Store Write18'

    memcpy(&Fullexp_DW.Delay_DSTATE_p[0], &Fullexp_DW.STDQMEKFP[0], 144U *
           sizeof(real_T));

    // Update for Delay: '<S22>/Delay2'
    memcpy(&Fullexp_DW.Delay2_DSTATE_d[0], &Fullexp_B.V_est_n[0], 36U * sizeof
           (real_T));

    // Update for Delay: '<S23>/Delay1'
    memcpy(&Fullexp_DW.Delay1_DSTATE_er[0], &Fullexp_B.x_est[0], 13U * sizeof
           (real_T));

    // Update for Delay: '<S23>/Delay' incorporates:
    //   DataStoreWrite: '<S23>/Data Store Write18'

    memcpy(&Fullexp_DW.Delay_DSTATE_l[0], &Fullexp_DW.STQMEKFP[0], 144U * sizeof
           (real_T));

    // Update for Delay: '<S23>/Delay2'
    memcpy(&Fullexp_DW.Delay2_DSTATE_p[0], &Fullexp_B.V_est[0], 36U * sizeof
           (real_T));

    // Update for If: '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 
    if (Fullexp_DW.Ifperforminganexperimentgrabthe == 0) {
      // Update for IfAction SubSystem: '<S13>/Use Hardware to Obtain States' incorporates:
      //   ActionPort: '<S182>/Action Port'

      // Update for Delay: '<S192>/Delay2'
      Fullexp_DW.Delay2_DSTATE_j = Fullexp_B.ReceivePhaseSpaceData_o1[0];

      // Update for Delay: '<S192>/Delay1'
      Fullexp_DW.Delay1_DSTATE_i = Fullexp_B.ConvertBLAXfrommmtom;

      // Update for Enabled SubSystem: '<S194>/Enabled Subsystem'
      Fulle_EnabledSubsystem_g_Update(Fullexp_B.dy_i,
        &Fullexp_B.EnabledSubsystem_n, &Fullexp_DW.EnabledSubsystem_n);

      // End of Update for SubSystem: '<S194>/Enabled Subsystem'

      // Update for Delay: '<S193>/Delay1'
      Fullexp_DW.Delay1_DSTATE_bv[0] = Fullexp_B.dy_i[0];
      Fullexp_DW.Delay1_DSTATE_bv[1] = Fullexp_B.dy_i[1];
      Fullexp_DW.Delay1_DSTATE_bv[2] = Fullexp_B.dy_i[2];

      // Update for Enabled SubSystem: '<S193>/Enabled Subsystem'
      Fullexp_EnabledSubsystem_Update(Fullexp_B.dy_k,
        &Fullexp_B.EnabledSubsystem_m, &Fullexp_DW.EnabledSubsystem_m);

      // End of Update for SubSystem: '<S193>/Enabled Subsystem'

      // Update for Delay: '<S202>/Delay2'
      Fullexp_DW.Delay2_DSTATE_l = Fullexp_B.ReceivePhaseSpaceData_o1[0];

      // Update for Delay: '<S202>/Delay1'
      Fullexp_DW.Delay1_DSTATE_l = Fullexp_B.ConvertBLUXfrommmtom;

      // Update for Enabled SubSystem: '<S204>/Enabled Subsystem'
      Fulle_EnabledSubsystem_g_Update(Fullexp_B.dy_c,
        &Fullexp_B.EnabledSubsystem_g, &Fullexp_DW.EnabledSubsystem_g);

      // End of Update for SubSystem: '<S204>/Enabled Subsystem'

      // Update for Delay: '<S203>/Delay1'
      Fullexp_DW.Delay1_DSTATE_lv[0] = Fullexp_B.dy_c[0];
      Fullexp_DW.Delay1_DSTATE_lv[1] = Fullexp_B.dy_c[1];
      Fullexp_DW.Delay1_DSTATE_lv[2] = Fullexp_B.dy_c[2];

      // Update for Enabled SubSystem: '<S203>/Enabled Subsystem'
      Fullexp_EnabledSubsystem_Update(Fullexp_B.dy_e,
        &Fullexp_B.EnabledSubsystem_l, &Fullexp_DW.EnabledSubsystem_l);

      // End of Update for SubSystem: '<S203>/Enabled Subsystem'

      // Update for Delay: '<S212>/Delay2'
      Fullexp_DW.Delay2_DSTATE_l0 = Fullexp_B.ReceivePhaseSpaceData_o1[0];

      // Update for Delay: '<S212>/Delay1'
      Fullexp_DW.Delay1_DSTATE_ld = Fullexp_B.ConvertREDXfrommmtom;

      // Update for Enabled SubSystem: '<S214>/Enabled Subsystem'
      Fulle_EnabledSubsystem_g_Update(Fullexp_B.dy,
        &Fullexp_B.EnabledSubsystem_a, &Fullexp_DW.EnabledSubsystem_a);

      // End of Update for SubSystem: '<S214>/Enabled Subsystem'

      // Update for Delay: '<S213>/Delay1'
      Fullexp_DW.Delay1_DSTATE_cq[0] = Fullexp_B.dy[0];
      Fullexp_DW.Delay1_DSTATE_cq[1] = Fullexp_B.dy[1];
      Fullexp_DW.Delay1_DSTATE_cq[2] = Fullexp_B.dy[2];

      // Update for Enabled SubSystem: '<S213>/Enabled Subsystem'
      Fullexp_EnabledSubsystem_Update(Fullexp_B.dy_l,
        &Fullexp_B.EnabledSubsystem_k, &Fullexp_DW.EnabledSubsystem_k);

      // End of Update for SubSystem: '<S213>/Enabled Subsystem'

      // Update for Delay: '<S188>/Delay'
      Fullexp_DW.Delay_DSTATE_i[0] = Fullexp_DW.Delay_DSTATE_i[1];

      // Update for Delay: '<S188>/Delay1'
      Fullexp_DW.Delay1_DSTATE_h[0] = Fullexp_DW.Delay1_DSTATE_h[1];

      // Update for Delay: '<S188>/Delay2'
      Fullexp_DW.Delay2_DSTATE_hq[0] = Fullexp_DW.Delay2_DSTATE_hq[1];

      // Update for Delay: '<S188>/Delay'
      Fullexp_DW.Delay_DSTATE_i[1] = Fullexp_DW.Delay_DSTATE_i[2];

      // Update for Delay: '<S188>/Delay1'
      Fullexp_DW.Delay1_DSTATE_h[1] = Fullexp_DW.Delay1_DSTATE_h[2];

      // Update for Delay: '<S188>/Delay2'
      Fullexp_DW.Delay2_DSTATE_hq[1] = Fullexp_DW.Delay2_DSTATE_hq[2];

      // Update for Delay: '<S188>/Delay'
      Fullexp_DW.Delay_DSTATE_i[2] = Fullexp_DW.Delay_DSTATE_i[3];

      // Update for Delay: '<S188>/Delay1'
      Fullexp_DW.Delay1_DSTATE_h[2] = Fullexp_DW.Delay1_DSTATE_h[3];

      // Update for Delay: '<S188>/Delay2'
      Fullexp_DW.Delay2_DSTATE_hq[2] = Fullexp_DW.Delay2_DSTATE_hq[3];

      // Update for Delay: '<S188>/Delay'
      Fullexp_DW.Delay_DSTATE_i[3] = Fullexp_DW.Delay_DSTATE_i[4];

      // Update for Delay: '<S188>/Delay1'
      Fullexp_DW.Delay1_DSTATE_h[3] = Fullexp_DW.Delay1_DSTATE_h[4];

      // Update for Delay: '<S188>/Delay2'
      Fullexp_DW.Delay2_DSTATE_hq[3] = Fullexp_DW.Delay2_DSTATE_hq[4];

      // Update for Delay: '<S188>/Delay'
      Fullexp_DW.Delay_DSTATE_i[4] = Fullexp_B.UDPReceive_o1;

      // Update for Delay: '<S188>/Delay1'
      Fullexp_DW.Delay1_DSTATE_h[4] = Fullexp_B.UDPReceive2_o1;

      // Update for Delay: '<S188>/Delay2'
      Fullexp_DW.Delay2_DSTATE_hq[4] = Fullexp_B.UDPReceive3_o1;

      // Update for Enabled SubSystem: '<S187>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S189>/Enable'

      if (Fullexp_B.RelationalOperator1) {
        // Update for Memory: '<S189>/Memory'
        Fullexp_DW.Memory_PreviousInput = Fullexp_B.Clock_o;
      }

      // End of Update for SubSystem: '<S187>/Enabled Subsystem'
      // End of Update for SubSystem: '<S13>/Use Hardware to Obtain States'
    }

    // End of Update for If: '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 

    // Update for S-Function (sdspToNetwork): '<S26>/UDP Send' incorporates:
    //   SignalConversion generated from: '<S26>/UDP Send'

    sErr = GetErrorBuffer(&Fullexp_DW.UDPSend_NetworkLib[0U]);
    LibUpdate_Network(&Fullexp_DW.UDPSend_NetworkLib[0U],
                      &Fullexp_B.TmpSignalConversionAtUDPSendInp[0U], 10);
    if (*sErr != 0) {
      Fullexp_M->setErrorStatus(sErr);
      Fullexp_M->setStopRequested(1);
    }

    // End of Update for S-Function (sdspToNetwork): '<S26>/UDP Send'
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  Fullexp_M->Timing.t[0] =
    ((time_T)(++Fullexp_M->Timing.clockTick0)) * Fullexp_M->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.05s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.05, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    Fullexp_M->Timing.clockTick1++;
  }
}

// Model initialize function
void Fullexp_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&Fullexp_M->solverInfo, &Fullexp_M->Timing.simTimeStep);
    rtsiSetTPtr(&Fullexp_M->solverInfo, Fullexp_M->getTPtrPtr());
    rtsiSetStepSizePtr(&Fullexp_M->solverInfo, &Fullexp_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Fullexp_M->solverInfo, Fullexp_M->getErrorStatusPtr());
    rtsiSetRTModelPtr(&Fullexp_M->solverInfo, Fullexp_M);
  }

  rtsiSetSimTimeStep(&Fullexp_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Fullexp_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&Fullexp_M->solverInfo, false);
  rtsiSetSolverName(&Fullexp_M->solverInfo,"FixedStepDiscrete");
  Fullexp_M->setTPtr(&Fullexp_M->Timing.tArray[0]);
  Fullexp_M->Timing.stepSize0 = 0.05;

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

    // Start for If: '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 
    Fullexp_DW.Ifperforminganexperimentgrabthe = -1;

    // Start for S-Function (sdspToNetwork): '<S26>/UDP Send'
    sErr = GetErrorBuffer(&Fullexp_DW.UDPSend_NetworkLib[0U]);
    CreateUDPInterface(&Fullexp_DW.UDPSend_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&Fullexp_DW.UDPSend_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "127.0.0.1", Fullexp_P.UDPSend_Port_h, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&Fullexp_DW.UDPSend_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&Fullexp_DW.UDPSend_NetworkLib[0U]);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S26>/UDP Send'

    // Start for DataStoreMemory: '<Root>/Data Store Memory15'
    Fullexp_DW.Vis_x[0] = Fullexp_P.DataStoreMemory15_InitialValue[0];
    Fullexp_DW.Vis_x[1] = Fullexp_P.DataStoreMemory15_InitialValue[1];
    Fullexp_DW.Vis_x[2] = Fullexp_P.DataStoreMemory15_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Data Store Memory18'
    memcpy(&Fullexp_DW.QMEKFP[0], &Fullexp_P.DataStoreMemory18_InitialValue[0],
           144U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory21'
    memcpy(&Fullexp_DW.STQMEKFP[0], &Fullexp_P.DataStoreMemory21_InitialValue[0],
           144U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory24'
    memcpy(&Fullexp_DW.DQMEKFP[0], &Fullexp_P.DataStoreMemory24_InitialValue[0],
           144U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory27'
    memcpy(&Fullexp_DW.STDQMEKFP[0], &Fullexp_P.DataStoreMemory27_InitialValue[0],
           144U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory30'
    memcpy(&Fullexp_DW.RMEKFP[0], &Fullexp_P.DataStoreMemory30_InitialValue[0],
           144U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory32'
    memcpy(&Fullexp_DW.STRMEKFx[0], &Fullexp_P.DataStoreMemory32_InitialValue[0],
           9U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory33'
    memcpy(&Fullexp_DW.STRMEKFP[0], &Fullexp_P.DataStoreMemory33_InitialValue[0],
           144U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory34'
    Fullexp_DW.STRMEKFt = Fullexp_P.DataStoreMemory34_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory37'
    Fullexp_DW.Vis_yaw = Fullexp_P.DataStoreMemory37_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory40'
    Fullexp_DW.Conf = Fullexp_P.DataStoreMemory40_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz1'
    Fullexp_DW.BLUE_Control_Law_Enabler = Fullexp_P.RED_Tz1_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz15'
    Fullexp_DW.ARM_Control_Mode = Fullexp_P.RED_Tz15_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz20'
    Fullexp_DW.RED_Control_Law_Enabler = Fullexp_P.RED_Tz20_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz25'
    Fullexp_DW.RED_Path_Planner_Selection = Fullexp_P.RED_Tz25_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz3'
    strncpy(&Fullexp_DW.RED_Logger[0], &Fullexp_P.RED_Tz3_InitialValue[0], 255U);
    Fullexp_DW.RED_Logger[255] = '\x00';

    // Start for DataStoreMemory: '<Root>/RED_Tz38'
    Fullexp_DW.ARM_Control_Law_Enabler = Fullexp_P.RED_Tz38_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz7'
    Fullexp_DW.Float_State = Fullexp_P.RED_Tz7_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz8'
    Fullexp_DW.BLACK_Control_Law_Enabler = Fullexp_P.RED_Tz8_InitialValue;

    // Start for DataStoreMemory: '<Root>/RED_Tz9'
    Fullexp_DW.BLACK_Path_Planner_Selection = Fullexp_P.RED_Tz9_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time'
    Fullexp_DW.Univ_Time = Fullexp_P.Universal_Time_InitialValue;

    // Start for DataStoreMemory: '<Root>/Data Store Memory38'
    memcpy(&Fullexp_DW.RMEKFR[0], &Fullexp_P.DataStoreMemory38_InitialValue[0],
           9U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Data Store Memory39'
    memcpy(&Fullexp_DW.STRMEKFR[0], &Fullexp_P.DataStoreMemory39_InitialValue[0],
           9U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Universal_Time10'
    memcpy(&Fullexp_DW.BLACK_Measured_States[0],
           &Fullexp_P.Universal_Time10_InitialValue[0], 9U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Universal_Time14'
    Fullexp_DW.BLUE_Thruster_ON_Count = Fullexp_P.Universal_Time14_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time13'
    Fullexp_DW.BLUE_Desired_States[0] = Fullexp_P.Universal_Time13_InitialValue
      [0];

    // Start for DataStoreMemory: '<Root>/Universal_Time15'
    Fullexp_DW.BLACK_Saturated_Controls[0] =
      Fullexp_P.Universal_Time15_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time13'
    Fullexp_DW.BLUE_Desired_States[1] = Fullexp_P.Universal_Time13_InitialValue
      [1];

    // Start for DataStoreMemory: '<Root>/Universal_Time15'
    Fullexp_DW.BLACK_Saturated_Controls[1] =
      Fullexp_P.Universal_Time15_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time13'
    Fullexp_DW.BLUE_Desired_States[2] = Fullexp_P.Universal_Time13_InitialValue
      [2];

    // Start for DataStoreMemory: '<Root>/Universal_Time15'
    Fullexp_DW.BLACK_Saturated_Controls[2] =
      Fullexp_P.Universal_Time15_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time16'
    Fullexp_DW.RED_Thruster_ON_Count = Fullexp_P.Universal_Time16_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time19'
    Fullexp_DW.WhoAmI = Fullexp_P.Universal_Time19_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time20'
    Fullexp_DW.isSim = Fullexp_P.Universal_Time20_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time24'
    for (i = 0; i < 6; i++) {
      Fullexp_DW.ARM_Measured_States[i] =
        Fullexp_P.Universal_Time24_InitialValue[i];
    }

    // End of Start for DataStoreMemory: '<Root>/Universal_Time24'

    // Start for DataStoreMemory: '<Root>/Universal_Time25'
    Fullexp_DW.BLACK_Desired_States[0] =
      Fullexp_P.Universal_Time25_InitialValue[0];
    Fullexp_DW.BLACK_Desired_States[1] =
      Fullexp_P.Universal_Time25_InitialValue[1];
    Fullexp_DW.BLACK_Desired_States[2] =
      Fullexp_P.Universal_Time25_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time3'
    Fullexp_DW.BLACK_Thruster_ON_Count = Fullexp_P.Universal_Time3_InitialValue;

    // Start for DataStoreMemory: '<Root>/Universal_Time28'
    Fullexp_DW.RED_Saturated_Controls[0] =
      Fullexp_P.Universal_Time28_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time29'
    Fullexp_DW.RED_Desired_States[0] = Fullexp_P.Universal_Time29_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time31'
    Fullexp_DW.RED_IMU_Measurements[0] =
      Fullexp_P.Universal_Time31_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time33'
    Fullexp_DW.BLACK_IMU_Measurements[0] =
      Fullexp_P.Universal_Time33_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time34'
    Fullexp_DW.BLUE_IMU_Measurements[0] =
      Fullexp_P.Universal_Time34_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time28'
    Fullexp_DW.RED_Saturated_Controls[1] =
      Fullexp_P.Universal_Time28_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time29'
    Fullexp_DW.RED_Desired_States[1] = Fullexp_P.Universal_Time29_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time31'
    Fullexp_DW.RED_IMU_Measurements[1] =
      Fullexp_P.Universal_Time31_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time33'
    Fullexp_DW.BLACK_IMU_Measurements[1] =
      Fullexp_P.Universal_Time33_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time34'
    Fullexp_DW.BLUE_IMU_Measurements[1] =
      Fullexp_P.Universal_Time34_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time28'
    Fullexp_DW.RED_Saturated_Controls[2] =
      Fullexp_P.Universal_Time28_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time29'
    Fullexp_DW.RED_Desired_States[2] = Fullexp_P.Universal_Time29_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time31'
    Fullexp_DW.RED_IMU_Measurements[2] =
      Fullexp_P.Universal_Time31_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time33'
    Fullexp_DW.BLACK_IMU_Measurements[2] =
      Fullexp_P.Universal_Time33_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time34'
    Fullexp_DW.BLUE_IMU_Measurements[2] =
      Fullexp_P.Universal_Time34_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time26'
    memcpy(&Fullexp_DW.RED_Measured_States[0],
           &Fullexp_P.Universal_Time26_InitialValue[0], 9U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Universal_Time4'
    memcpy(&Fullexp_DW.BLUE_Measured_States[0],
           &Fullexp_P.Universal_Time4_InitialValue[0], 9U * sizeof(real_T));

    // Start for DataStoreMemory: '<Root>/Universal_Time6'
    Fullexp_DW.BLUE_Saturated_Controls[0] =
      Fullexp_P.Universal_Time6_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time8'
    Fullexp_DW.ARM_Desired_States[0] = Fullexp_P.Universal_Time8_InitialValue[0];

    // Start for DataStoreMemory: '<Root>/Universal_Time6'
    Fullexp_DW.BLUE_Saturated_Controls[1] =
      Fullexp_P.Universal_Time6_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time8'
    Fullexp_DW.ARM_Desired_States[1] = Fullexp_P.Universal_Time8_InitialValue[1];

    // Start for DataStoreMemory: '<Root>/Universal_Time6'
    Fullexp_DW.BLUE_Saturated_Controls[2] =
      Fullexp_P.Universal_Time6_InitialValue[2];

    // Start for DataStoreMemory: '<Root>/Universal_Time8'
    Fullexp_DW.ARM_Desired_States[2] = Fullexp_P.Universal_Time8_InitialValue[2];

    // InitializeConditions for Delay: '<Root>/Delay'
    Fullexp_DW.Delay_DSTATE = Fullexp_P.Delay_InitialCondition_e;

    // InitializeConditions for Delay: '<S5>/Delay1'
    memcpy(&Fullexp_DW.Delay1_DSTATE[0], &Fullexp_P.Delay1_InitialCondition_f[0],
           14U * sizeof(real_T));

    // InitializeConditions for Delay: '<S5>/Delay'
    memcpy(&Fullexp_DW.Delay_DSTATE_d[0], &Fullexp_P.P[0], 144U * sizeof(real_T));

    // InitializeConditions for Delay: '<S16>/Delay1'
    memcpy(&Fullexp_DW.Delay1_DSTATE_e[0],
           &Fullexp_P.Delay1_InitialCondition_k5[0], 13U * sizeof(real_T));

    // InitializeConditions for Delay: '<S16>/Delay'
    memcpy(&Fullexp_DW.Delay_DSTATE_k[0], &Fullexp_P.P[0], 144U * sizeof(real_T));

    // InitializeConditions for Delay: '<S17>/Delay1'
    memcpy(&Fullexp_DW.Delay1_DSTATE_o[0],
           &Fullexp_P.Delay1_InitialCondition_ic[0], 9U * sizeof(real_T));

    // InitializeConditions for Delay: '<S17>/Delay2'
    memcpy(&Fullexp_DW.Delay2_DSTATE[0], &Fullexp_P.Delay2_InitialCondition_d[0],
           9U * sizeof(real_T));

    // InitializeConditions for Delay: '<S17>/Delay'
    memcpy(&Fullexp_DW.Delay_DSTATE_n[0], &Fullexp_P.P[0], 144U * sizeof(real_T));

    // InitializeConditions for Delay: '<S22>/Delay1'
    memcpy(&Fullexp_DW.Delay1_DSTATE_b[0],
           &Fullexp_P.Delay1_InitialCondition_je[0], 14U * sizeof(real_T));

    // InitializeConditions for Delay: '<S22>/Delay'
    memcpy(&Fullexp_DW.Delay_DSTATE_p[0], &Fullexp_P.P[0], 144U * sizeof(real_T));

    // InitializeConditions for Delay: '<S22>/Delay2'
    memcpy(&Fullexp_DW.Delay2_DSTATE_d[0], &Fullexp_P.Delay2_InitialCondition_l
           [0], 36U * sizeof(real_T));

    // InitializeConditions for Delay: '<S23>/Delay1'
    memcpy(&Fullexp_DW.Delay1_DSTATE_er[0],
           &Fullexp_P.Delay1_InitialCondition_p[0], 13U * sizeof(real_T));

    // InitializeConditions for Delay: '<S23>/Delay'
    memcpy(&Fullexp_DW.Delay_DSTATE_l[0], &Fullexp_P.P[0], 144U * sizeof(real_T));

    // InitializeConditions for Delay: '<S23>/Delay2'
    memcpy(&Fullexp_DW.Delay2_DSTATE_p[0], &Fullexp_P.Delay2_InitialCondition_f
           [0], 36U * sizeof(real_T));

    // SystemInitialize for IfAction SubSystem: '<S3>/Default PD Control (BLACK)' 
    // InitializeConditions for UnitDelay: '<S154>/UD'
    //
    //  Block description for '<S154>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_eh = Fullexp_P.DiscreteDerivative_ICPrevScal_p;

    // InitializeConditions for UnitDelay: '<S155>/UD'
    //
    //  Block description for '<S155>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_hv = Fullexp_P.DiscreteDerivative1_ICPrevSca_m;

    // InitializeConditions for UnitDelay: '<S156>/UD'
    //
    //  Block description for '<S156>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_kv = Fullexp_P.DiscreteDerivative2_ICPrevSca_a;

    // End of SystemInitialize for SubSystem: '<S3>/Default PD Control (BLACK)'

    // SystemInitialize for IfAction SubSystem: '<S3>/Default LQR Control (BLACK)' 
    // InitializeConditions for UnitDelay: '<S131>/UD'
    //
    //  Block description for '<S131>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_j = Fullexp_P.DiscreteDerivative_ICPrevScal_d;

    // InitializeConditions for UnitDelay: '<S132>/UD'
    //
    //  Block description for '<S132>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_c = Fullexp_P.DiscreteDerivative1_ICPrevSca_i;

    // InitializeConditions for UnitDelay: '<S133>/UD'
    //
    //  Block description for '<S133>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_d = Fullexp_P.DiscreteDerivative2_ICPrevSc_oo;

    // End of SystemInitialize for SubSystem: '<S3>/Default LQR Control (BLACK)' 

    // SystemInitialize for IfAction SubSystem: '<S3>/Default PD Control (BLUE)' 
    // InitializeConditions for UnitDelay: '<S159>/UD'
    //
    //  Block description for '<S159>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_o = Fullexp_P.DiscreteDerivative_ICPrevSca_pf;

    // InitializeConditions for UnitDelay: '<S160>/UD'
    //
    //  Block description for '<S160>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_n = Fullexp_P.DiscreteDerivative1_ICPrevSca_l;

    // InitializeConditions for UnitDelay: '<S161>/UD'
    //
    //  Block description for '<S161>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_hu = Fullexp_P.DiscreteDerivative2_ICPrevSc_on;

    // End of SystemInitialize for SubSystem: '<S3>/Default PD Control (BLUE)'

    // SystemInitialize for IfAction SubSystem: '<S3>/Default LQR Control (BLUE)' 
    // InitializeConditions for UnitDelay: '<S136>/UD'
    //
    //  Block description for '<S136>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_l = Fullexp_P.DiscreteDerivative_ICPrevScal_n;

    // InitializeConditions for UnitDelay: '<S137>/UD'
    //
    //  Block description for '<S137>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_k = Fullexp_P.DiscreteDerivative1_ICPrevSca_f;

    // InitializeConditions for UnitDelay: '<S138>/UD'
    //
    //  Block description for '<S138>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_h = Fullexp_P.DiscreteDerivative2_ICPrevSca_g;

    // End of SystemInitialize for SubSystem: '<S3>/Default LQR Control (BLUE)'

    // SystemInitialize for IfAction SubSystem: '<S3>/Default PD (ARM)'
    // SystemInitialize for IfAction SubSystem: '<S122>/Simulated Position Controller' 
    // InitializeConditions for UnitDelay: '<S150>/UD'
    //
    //  Block description for '<S150>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE = Fullexp_P.DiscreteDerivative1_ICPrevSca_j;

    // InitializeConditions for UnitDelay: '<S151>/UD'
    //
    //  Block description for '<S151>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_e = Fullexp_P.DiscreteDerivative1_ICPrevSca_a;

    // InitializeConditions for UnitDelay: '<S152>/UD'
    //
    //  Block description for '<S152>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_a = Fullexp_P.DiscreteDerivative1_ICPrevSca_k;

    // End of SystemInitialize for SubSystem: '<S122>/Simulated Position Controller' 
    // End of SystemInitialize for SubSystem: '<S3>/Default PD (ARM)'

    // SystemInitialize for IfAction SubSystem: '<S3>/Default PD Control (RED)'
    // InitializeConditions for UnitDelay: '<S164>/UD'
    //
    //  Block description for '<S164>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_eg = Fullexp_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for UnitDelay: '<S165>/UD'
    //
    //  Block description for '<S165>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_cd = Fullexp_P.DiscreteDerivative1_ICPrevScale;

    // InitializeConditions for UnitDelay: '<S166>/UD'
    //
    //  Block description for '<S166>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_hd = Fullexp_P.DiscreteDerivative2_ICPrevScale;

    // End of SystemInitialize for SubSystem: '<S3>/Default PD Control (RED)'

    // SystemInitialize for IfAction SubSystem: '<S3>/Default LQR Control (RED)' 
    // InitializeConditions for UnitDelay: '<S141>/UD'
    //
    //  Block description for '<S141>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_aq = Fullexp_P.DiscreteDerivative_ICPrevScal_i;

    // InitializeConditions for UnitDelay: '<S142>/UD'
    //
    //  Block description for '<S142>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_p = Fullexp_P.DiscreteDerivative1_ICPrevSca_e;

    // InitializeConditions for UnitDelay: '<S143>/UD'
    //
    //  Block description for '<S143>/UD':
    //
    //   Store in Global RAM

    Fullexp_DW.UD_DSTATE_pr = Fullexp_P.DiscreteDerivative2_ICPrevSca_o;

    // End of SystemInitialize for SubSystem: '<S3>/Default LQR Control (RED)'

    // SystemInitialize for Merge: '<S3>/Merge1'
    Fullexp_B.Merge1[0] = Fullexp_P.Merge1_InitialOutput;

    // SystemInitialize for Merge: '<S3>/Merge2'
    Fullexp_B.Merge2[0] = Fullexp_P.Merge2_InitialOutput;

    // SystemInitialize for Merge: '<S3>/Merge'
    Fullexp_B.Merge[0] = Fullexp_P.Merge_InitialOutput;

    // SystemInitialize for Merge: '<S3>/Merge1'
    Fullexp_B.Merge1[1] = Fullexp_P.Merge1_InitialOutput;

    // SystemInitialize for Merge: '<S3>/Merge2'
    Fullexp_B.Merge2[1] = Fullexp_P.Merge2_InitialOutput;

    // SystemInitialize for Merge: '<S3>/Merge'
    Fullexp_B.Merge[1] = Fullexp_P.Merge_InitialOutput;

    // SystemInitialize for Merge: '<S3>/Merge1'
    Fullexp_B.Merge1[2] = Fullexp_P.Merge1_InitialOutput;

    // SystemInitialize for Merge: '<S3>/Merge2'
    Fullexp_B.Merge2[2] = Fullexp_P.Merge2_InitialOutput;

    // SystemInitialize for Merge: '<S3>/Merge'
    Fullexp_B.Merge[2] = Fullexp_P.Merge_InitialOutput;

    // SystemInitialize for MATLAB Function: '<S5>/MATLAB Function1'
    memcpy(&Fullexp_DW.state_k[0], &tmp[0], 625U * sizeof(uint32_T));

    // SystemInitialize for MATLAB Function: '<S16>/MATLAB Function1'
    memcpy(&Fullexp_DW.state_a[0], &tmp[0], 625U * sizeof(uint32_T));

    // SystemInitialize for MATLAB Function: '<S17>/MATLAB Function1'
    memcpy(&Fullexp_DW.state_p[0], &tmp[0], 625U * sizeof(uint32_T));

    // SystemInitialize for MATLAB Function: '<S22>/MATLAB Function1'
    memcpy(&Fullexp_DW.state_j[0], &tmp[0], 625U * sizeof(uint32_T));

    // SystemInitialize for MATLAB Function: '<S23>/MATLAB Function1'
    memcpy(&Fullexp_DW.state[0], &tmp[0], 625U * sizeof(uint32_T));

    // SystemInitialize for IfAction SubSystem: '<S4>/Change BLACK Behavior'
    Fullex_ChangeBLACKBehavior_Init(Fullexp_M, &Fullexp_DW.ChangeBLACKBehavior,
      &Fullexp_P.ChangeBLACKBehavior);

    // End of SystemInitialize for SubSystem: '<S4>/Change BLACK Behavior'

    // SystemInitialize for IfAction SubSystem: '<S4>/Change BLUE Behavior'
    Fullex_ChangeBLACKBehavior_Init(Fullexp_M, &Fullexp_DW.ChangeBLUEBehavior,
      &Fullexp_P.ChangeBLUEBehavior);

    // End of SystemInitialize for SubSystem: '<S4>/Change BLUE Behavior'

    // SystemInitialize for IfAction SubSystem: '<S4>/Change RED Behavior'
    Fullex_ChangeBLACKBehavior_Init(Fullexp_M, &Fullexp_DW.ChangeREDBehavior,
      &Fullexp_P.ChangeREDBehavior);

    // End of SystemInitialize for SubSystem: '<S4>/Change RED Behavior'

    // SystemInitialize for IfAction SubSystem: '<S7>/Change BLACK Behavior'
    // Start for S-Function (sdspToNetwork): '<S174>/UDP Send1'
    sErr = GetErrorBuffer(&Fullexp_DW.UDPSend1_NetworkLib[0U]);
    CreateUDPInterface(&Fullexp_DW.UDPSend1_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&Fullexp_DW.UDPSend1_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "255.255.255.255", Fullexp_P.UDPSend1_Port, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&Fullexp_DW.UDPSend1_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&Fullexp_DW.UDPSend1_NetworkLib[0U]);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S174>/UDP Send1'
    // End of SystemInitialize for SubSystem: '<S7>/Change BLACK Behavior'

    // SystemInitialize for IfAction SubSystem: '<S7>/Change BLUE Behavior'
    // Start for S-Function (sdspToNetwork): '<S175>/UDP Send2'
    sErr = GetErrorBuffer(&Fullexp_DW.UDPSend2_NetworkLib[0U]);
    CreateUDPInterface(&Fullexp_DW.UDPSend2_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&Fullexp_DW.UDPSend2_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "255.255.255.255", Fullexp_P.UDPSend2_Port, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&Fullexp_DW.UDPSend2_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&Fullexp_DW.UDPSend2_NetworkLib[0U]);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S175>/UDP Send2'
    // End of SystemInitialize for SubSystem: '<S7>/Change BLUE Behavior'

    // SystemInitialize for IfAction SubSystem: '<S7>/Change RED Behavior'
    // Start for S-Function (sdspToNetwork): '<S176>/UDP Send3'
    sErr = GetErrorBuffer(&Fullexp_DW.UDPSend3_NetworkLib[0U]);
    CreateUDPInterface(&Fullexp_DW.UDPSend3_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&Fullexp_DW.UDPSend3_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "255.255.255.255", Fullexp_P.UDPSend3_Port, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&Fullexp_DW.UDPSend3_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&Fullexp_DW.UDPSend3_NetworkLib[0U]);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S176>/UDP Send3'
    // End of SystemInitialize for SubSystem: '<S7>/Change RED Behavior'

    // SystemInitialize for IfAction SubSystem: '<S8>/Enable Pucks'
    // Start for MATLABSystem: '<S177>/GPIO Write1'
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    Fullexp_DW.obj_c.matlabCodegenIsDeleted = false;
    Fullexp_DW.obj_c.gpioPin = Fullexp_P.GPIOWrite1_gpioPin;
    Fullexp_DW.obj_c.pinDirection = Fullexp_P.GPIOWrite1_pinDirection;
    Fullexp_DW.obj_c.isInitialized = 1;

    //         %% Define input properties
    //  Call C-function implementing device initialization
    export_gpio(Fullexp_DW.obj_c.gpioPin);
    set_pin_direction(Fullexp_DW.obj_c.gpioPin, Fullexp_DW.obj_c.pinDirection);
    Fullexp_DW.obj_c.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S8>/Enable Pucks'

    // SystemInitialize for IfAction SubSystem: '<S9>/Log Gyro//Accel'
    // Start for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
    Fullexp_DW.obj._pobj2.matlabCodegenIsDeleted = true;
    Fullexp_DW.obj.isInitialized = 0;
    Fullexp_DW.obj.matlabCodegenIsDeleted = false;
    Fullexp_DW.obj.SampleTime = Fullexp_P.GyroscopeAccelerometer_SampleTi;
    Fullexp_SystemCore_setup(&Fullexp_DW.obj);

    // End of SystemInitialize for SubSystem: '<S9>/Log Gyro//Accel'

    // SystemInitialize for IfAction SubSystem: '<S12>/Change ARM Behavior'
    // InitializeConditions for Delay: '<S180>/Delay'
    Fullexp_DW.Delay_DSTATE_o = Fullexp_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S180>/Delay1'
    Fullexp_DW.Delay1_DSTATE_cg = Fullexp_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S180>/Delay2'
    Fullexp_DW.Delay2_DSTATE_h = Fullexp_P.Delay2_InitialCondition;

    // Start for MATLABSystem: '<S180>/Read Joint Positions using  Dynamixel Encoders' 
    Fullexp_DW.obj_d.matlabCodegenIsDeleted = false;
    if (((!rtIsInf(Fullexp_P.baseRate)) && (!rtIsNaN(Fullexp_P.baseRate))) ||
        rtIsInf(Fullexp_P.baseRate)) {
      sampleTime = Fullexp_P.baseRate;
    }

    Fullexp_DW.obj_d.SampleTime = sampleTime;
    Fullexp_DW.obj_d.isInitialized = 1;

    //         %% Define input properties
    //  Call C-function implementing device initialization
    Fullexp_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S180>/Read Joint Positions using  Dynamixel Encoders' 
    // End of SystemInitialize for SubSystem: '<S12>/Change ARM Behavior'

    // SystemInitialize for IfAction SubSystem: '<S13>/Use Hardware to Obtain States' 
    // Start for S-Function (sdspFromNetwork): '<S183>/Receive PhaseSpace Data'
    sErr = GetErrorBuffer(&Fullexp_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
    CreateUDPInterface(&Fullexp_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&Fullexp_DW.ReceivePhaseSpaceData_NetworkLi[0U], 0,
                        "0.0.0.0", Fullexp_P.ReceivePhaseSpaceData_Port,
                        "0.0.0.0", -1, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&Fullexp_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&Fullexp_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S183>/Receive PhaseSpace Data' 

    // Start for S-Function (sdspFromNetwork): '<S188>/UDP Receive'
    sErr = GetErrorBuffer(&Fullexp_DW.UDPReceive_NetworkLib[0U]);
    CreateUDPInterface(&Fullexp_DW.UDPReceive_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&Fullexp_DW.UDPReceive_NetworkLib[0U], 0, "0.0.0.0",
                        Fullexp_P.UDPReceive_Port, "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&Fullexp_DW.UDPReceive_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&Fullexp_DW.UDPReceive_NetworkLib[0U]);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S188>/UDP Receive'

    // Start for S-Function (sdspFromNetwork): '<S188>/UDP Receive2'
    sErr = GetErrorBuffer(&Fullexp_DW.UDPReceive2_NetworkLib[0U]);
    CreateUDPInterface(&Fullexp_DW.UDPReceive2_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&Fullexp_DW.UDPReceive2_NetworkLib[0U], 0, "0.0.0.0",
                        Fullexp_P.UDPReceive2_Port, "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&Fullexp_DW.UDPReceive2_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&Fullexp_DW.UDPReceive2_NetworkLib[0U]);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S188>/UDP Receive2'

    // Start for S-Function (sdspFromNetwork): '<S188>/UDP Receive3'
    sErr = GetErrorBuffer(&Fullexp_DW.UDPReceive3_NetworkLib[0U]);
    CreateUDPInterface(&Fullexp_DW.UDPReceive3_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&Fullexp_DW.UDPReceive3_NetworkLib[0U], 0, "0.0.0.0",
                        Fullexp_P.UDPReceive3_Port, "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&Fullexp_DW.UDPReceive3_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&Fullexp_DW.UDPReceive3_NetworkLib[0U]);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S188>/UDP Receive3'

    // InitializeConditions for Delay: '<S192>/Delay2'
    Fullexp_DW.Delay2_DSTATE_j = Fullexp_P.Delay2_InitialCondition_e;

    // InitializeConditions for Delay: '<S192>/Delay1'
    Fullexp_DW.Delay1_DSTATE_i = Fullexp_P.Delay1_InitialCondition_m;

    // InitializeConditions for Delay: '<S202>/Delay2'
    Fullexp_DW.Delay2_DSTATE_l = Fullexp_P.Delay2_InitialCondition_a;

    // InitializeConditions for Delay: '<S202>/Delay1'
    Fullexp_DW.Delay1_DSTATE_l = Fullexp_P.Delay1_InitialCondition_i3;

    // InitializeConditions for Delay: '<S212>/Delay2'
    Fullexp_DW.Delay2_DSTATE_l0 = Fullexp_P.Delay2_InitialCondition_m;

    // InitializeConditions for Delay: '<S212>/Delay1'
    Fullexp_DW.Delay1_DSTATE_ld = Fullexp_P.Delay1_InitialCondition_l;

    // InitializeConditions for Delay: '<S194>/Delay1'
    Fullexp_DW.Delay1_DSTATE_g[0] = Fullexp_P.Delay1_InitialCondition_i;

    // InitializeConditions for Delay: '<S193>/Delay1'
    Fullexp_DW.Delay1_DSTATE_bv[0] = Fullexp_P.Delay1_InitialCondition_it;

    // InitializeConditions for Delay: '<S204>/Delay1'
    Fullexp_DW.Delay1_DSTATE_m[0] = Fullexp_P.Delay1_InitialCondition_h;

    // InitializeConditions for Delay: '<S203>/Delay1'
    Fullexp_DW.Delay1_DSTATE_lv[0] = Fullexp_P.Delay1_InitialCondition_j;

    // InitializeConditions for Delay: '<S214>/Delay1'
    Fullexp_DW.Delay1_DSTATE_c[0] = Fullexp_P.Delay1_InitialCondition_k;

    // InitializeConditions for Delay: '<S213>/Delay1'
    Fullexp_DW.Delay1_DSTATE_cq[0] = Fullexp_P.Delay1_InitialCondition_c;

    // InitializeConditions for Delay: '<S194>/Delay1'
    Fullexp_DW.Delay1_DSTATE_g[1] = Fullexp_P.Delay1_InitialCondition_i;

    // InitializeConditions for Delay: '<S193>/Delay1'
    Fullexp_DW.Delay1_DSTATE_bv[1] = Fullexp_P.Delay1_InitialCondition_it;

    // InitializeConditions for Delay: '<S204>/Delay1'
    Fullexp_DW.Delay1_DSTATE_m[1] = Fullexp_P.Delay1_InitialCondition_h;

    // InitializeConditions for Delay: '<S203>/Delay1'
    Fullexp_DW.Delay1_DSTATE_lv[1] = Fullexp_P.Delay1_InitialCondition_j;

    // InitializeConditions for Delay: '<S214>/Delay1'
    Fullexp_DW.Delay1_DSTATE_c[1] = Fullexp_P.Delay1_InitialCondition_k;

    // InitializeConditions for Delay: '<S213>/Delay1'
    Fullexp_DW.Delay1_DSTATE_cq[1] = Fullexp_P.Delay1_InitialCondition_c;

    // InitializeConditions for Delay: '<S194>/Delay1'
    Fullexp_DW.Delay1_DSTATE_g[2] = Fullexp_P.Delay1_InitialCondition_i;

    // InitializeConditions for Delay: '<S193>/Delay1'
    Fullexp_DW.Delay1_DSTATE_bv[2] = Fullexp_P.Delay1_InitialCondition_it;

    // InitializeConditions for Delay: '<S204>/Delay1'
    Fullexp_DW.Delay1_DSTATE_m[2] = Fullexp_P.Delay1_InitialCondition_h;

    // InitializeConditions for Delay: '<S203>/Delay1'
    Fullexp_DW.Delay1_DSTATE_lv[2] = Fullexp_P.Delay1_InitialCondition_j;

    // InitializeConditions for Delay: '<S214>/Delay1'
    Fullexp_DW.Delay1_DSTATE_c[2] = Fullexp_P.Delay1_InitialCondition_k;

    // InitializeConditions for Delay: '<S213>/Delay1'
    Fullexp_DW.Delay1_DSTATE_cq[2] = Fullexp_P.Delay1_InitialCondition_c;
    for (i = 0; i < 5; i++) {
      // InitializeConditions for Delay: '<S188>/Delay'
      Fullexp_DW.Delay_DSTATE_i[i] = Fullexp_P.Delay_InitialCondition_j;

      // InitializeConditions for Delay: '<S188>/Delay1'
      Fullexp_DW.Delay1_DSTATE_h[i] = Fullexp_P.Delay1_InitialCondition_d;

      // InitializeConditions for Delay: '<S188>/Delay2'
      Fullexp_DW.Delay2_DSTATE_hq[i] = Fullexp_P.Delay2_InitialCondition_ak;
    }

    // SystemInitialize for Enabled SubSystem: '<S192>/Enabled Subsystem3'
    // SystemInitialize for SignalConversion generated from: '<S196>/y2-y1' incorporates:
    //   Outport: '<S196>/dy(t)//dt'

    Fullexp_B.y2y1_ob = Fullexp_P.dytdt_Y0;

    // End of SystemInitialize for SubSystem: '<S192>/Enabled Subsystem3'

    // SystemInitialize for Enabled SubSystem: '<S194>/Enabled Subsystem'
    Fullexp_EnabledSubsystem_o_Init(Fullexp_B.dy_i,
      &Fullexp_DW.EnabledSubsystem_n, &Fullexp_P.EnabledSubsystem_n);

    // End of SystemInitialize for SubSystem: '<S194>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S193>/Enabled Subsystem'
    Fullexp_EnabledSubsystem_Init(Fullexp_B.dy_k, &Fullexp_DW.EnabledSubsystem_m,
      &Fullexp_P.EnabledSubsystem_m);

    // End of SystemInitialize for SubSystem: '<S193>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S202>/Enabled Subsystem3'
    // SystemInitialize for SignalConversion generated from: '<S206>/y2-y1' incorporates:
    //   Outport: '<S206>/dy(t)//dt'

    Fullexp_B.y2y1_o = Fullexp_P.dytdt_Y0_j;

    // End of SystemInitialize for SubSystem: '<S202>/Enabled Subsystem3'

    // SystemInitialize for Enabled SubSystem: '<S204>/Enabled Subsystem'
    Fullexp_EnabledSubsystem_o_Init(Fullexp_B.dy_c,
      &Fullexp_DW.EnabledSubsystem_g, &Fullexp_P.EnabledSubsystem_g);

    // End of SystemInitialize for SubSystem: '<S204>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S203>/Enabled Subsystem'
    Fullexp_EnabledSubsystem_Init(Fullexp_B.dy_e, &Fullexp_DW.EnabledSubsystem_l,
      &Fullexp_P.EnabledSubsystem_l);

    // End of SystemInitialize for SubSystem: '<S203>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S212>/Enabled Subsystem3'
    // SystemInitialize for SignalConversion generated from: '<S216>/y2-y1' incorporates:
    //   Outport: '<S216>/dy(t)//dt'

    Fullexp_B.y2y1 = Fullexp_P.dytdt_Y0_d;

    // End of SystemInitialize for SubSystem: '<S212>/Enabled Subsystem3'

    // SystemInitialize for Enabled SubSystem: '<S214>/Enabled Subsystem'
    Fullexp_EnabledSubsystem_o_Init(Fullexp_B.dy, &Fullexp_DW.EnabledSubsystem_a,
      &Fullexp_P.EnabledSubsystem_a);

    // End of SystemInitialize for SubSystem: '<S214>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S213>/Enabled Subsystem'
    Fullexp_EnabledSubsystem_Init(Fullexp_B.dy_l, &Fullexp_DW.EnabledSubsystem_k,
      &Fullexp_P.EnabledSubsystem_k);

    // End of SystemInitialize for SubSystem: '<S213>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S187>/Enabled Subsystem'
    // InitializeConditions for Memory: '<S189>/Memory'
    Fullexp_DW.Memory_PreviousInput = Fullexp_P.Memory_InitialCondition;

    // SystemInitialize for Memory: '<S189>/Memory' incorporates:
    //   Outport: '<S189>/Out1'

    Fullexp_B.Memory = Fullexp_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S187>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S187>/Enabled Subsystem1'
    // SystemInitialize for Sum: '<S190>/Subtract' incorporates:
    //   Outport: '<S190>/Out1'

    Fullexp_B.Subtract = Fullexp_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S187>/Enabled Subsystem1'
    // End of SystemInitialize for SubSystem: '<S13>/Use Hardware to Obtain States' 

    // SystemInitialize for IfAction SubSystem: '<S14>/Subsystem'
    // Start for MATLABSystem: '<S222>/WhoAmI'
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    Fullexp_DW.obj_dk.matlabCodegenIsDeleted = false;
    if (((!rtIsInf(Fullexp_P.baseRate)) && (!rtIsNaN(Fullexp_P.baseRate))) ||
        rtIsInf(Fullexp_P.baseRate)) {
      sampleTime_0 = Fullexp_P.baseRate;
    }

    Fullexp_DW.obj_dk.SampleTime = sampleTime_0;
    Fullexp_DW.obj_dk.isInitialized = 1;

    //         %% Define output properties
    //  Call C-function implementing device initialization
    Fullexp_DW.obj_dk.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S222>/WhoAmI'
    // End of SystemInitialize for SubSystem: '<S14>/Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S18>/Subsystem'
    // Start for S-Function (sdspFromNetwork): '<S226>/UDP Receive1'
    sErr = GetErrorBuffer(&Fullexp_DW.UDPReceive1_NetworkLib[0U]);
    CreateUDPInterface(&Fullexp_DW.UDPReceive1_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&Fullexp_DW.UDPReceive1_NetworkLib[0U], 0, "0.0.0.0",
                        Fullexp_P.UDPReceive1_Port, "0.0.0.0", -1, 8192, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&Fullexp_DW.UDPReceive1_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&Fullexp_DW.UDPReceive1_NetworkLib[0U]);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S226>/UDP Receive1'
    // End of SystemInitialize for SubSystem: '<S18>/Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S21>/Change ARM Behavior'
    // Start for MATLABSystem: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    Fullexp_DW.obj_n.matlabCodegenIsDeleted = false;
    Fullexp_DW.obj_n.POSITION_P_GAIN = Fullexp_P.ControlDynamixelActuatorsineith;
    Fullexp_DW.obj_n.POSITION_I_GAIN = Fullexp_P.ControlDynamixelActuatorsinei_b;
    Fullexp_DW.obj_n.POSITION_D_GAIN = Fullexp_P.ControlDynamixelActuatorsinei_h;
    Fullexp_DW.obj_n.MAX_POSITION = Fullexp_P.ControlDynamixelActuatorsinei_j;
    Fullexp_DW.obj_n.MIN_POSITION = Fullexp_P.ControlDynamixelActuatorsinei_m;
    Fullexp_DW.obj_n.MOVE_TIME = Fullexp_P.ControlDynamixelActuatorsine_hy;
    Fullexp_DW.obj_n.CURRENT_LIMIT = Fullexp_P.ControlDynamixelActuatorsinei_i;
    Fullexp_DW.obj_n.SPEED_P_GAIN = Fullexp_P.ControlDynamixelActuatorsinei_g;
    Fullexp_DW.obj_n.SPEED_I_GAIN = Fullexp_P.ControlDynamixelActuatorsine_g3;
    Fullexp_DW.obj_n.VELOCITY_LIMIT = Fullexp_P.ControlDynamixelActuatorsine_bf;
    Fullexp_DW.obj_n.ACCELERATION_TIME =
      Fullexp_P.ControlDynamixelActuatorsinei_l;
    if (((!rtIsInf(Fullexp_P.baseRate)) && (!rtIsNaN(Fullexp_P.baseRate))) ||
        rtIsInf(Fullexp_P.baseRate)) {
      sampleTime_1 = Fullexp_P.baseRate;
    }

    Fullexp_DW.obj_n.SampleTime = sampleTime_1;
    Fullexp_DW.obj_n.isInitialized = 1;

    //         %% Define input properties
    initialize_dynamixel();
    Fullexp_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
    // End of SystemInitialize for SubSystem: '<S21>/Change ARM Behavior'

    // SystemInitialize for IfAction SubSystem: '<S24>/Subsystem'
    // Start for S-Function (sdspToNetwork): '<S232>/UDP Send'
    sErr = GetErrorBuffer(&Fullexp_DW.UDPSend_NetworkLib_m[0U]);
    CreateUDPInterface(&Fullexp_DW.UDPSend_NetworkLib_m[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&Fullexp_DW.UDPSend_NetworkLib_m[0U], 1, "0.0.0.0", -1,
                        "192.168.1.115", Fullexp_P.UDPSend_Port, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&Fullexp_DW.UDPSend_NetworkLib_m[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&Fullexp_DW.UDPSend_NetworkLib_m[0U]);
      if (*sErr != 0) {
        Fullexp_M->setErrorStatus(sErr);
        Fullexp_M->setStopRequested(1);
      }
    }

    // End of Start for S-Function (sdspToNetwork): '<S232>/UDP Send'
    // End of SystemInitialize for SubSystem: '<S24>/Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S26>/Change RED Behavior'
    // InitializeConditions for Delay: '<S262>/Delay'
    Fullexp_DW.Delay_DSTATE_b = Fullexp_P.Delay_InitialCondition_p;

    // SystemInitialize for Enabled SubSystem: '<S262>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S267>/In1' incorporates:
    //   Outport: '<S267>/Out1'

    Fullexp_B.In1 = Fullexp_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S262>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S262>/Enabled Subsystem1'
    for (i = 0; i < 8; i++) {
      // SystemInitialize for SignalConversion generated from: '<S268>/ThrustPer_Final' incorporates:
      //   Outport: '<S268>/Out1'

      Fullexp_B.ThrustPer_Final[i] = Fullexp_P.Out1_Y0_d;
    }

    // End of SystemInitialize for SubSystem: '<S262>/Enabled Subsystem1'
    Fullexp_Pseudoinverse1_Init(&Fullexp_DW.Pseudoinverse1_pn);

    // End of SystemInitialize for SubSystem: '<S26>/Change RED Behavior'

    // SystemInitialize for IfAction SubSystem: '<S26>/Change BLACK Behavior'
    // InitializeConditions for Delay: '<S238>/Delay'
    Fullexp_DW.Delay_DSTATE_kz = Fullexp_P.Delay_InitialCondition_i;

    // SystemInitialize for Enabled SubSystem: '<S238>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S243>/In1' incorporates:
    //   Outport: '<S243>/Out1'

    Fullexp_B.In1_g2 = Fullexp_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S238>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S238>/Enabled Subsystem1'
    // SystemInitialize for IfAction SubSystem: '<S26>/Change RED Behavior'
    for (i = 0; i < 8; i++) {
      // SystemInitialize for Outport: '<S235>/RED DC'
      Fullexp_B.duty_cycles[i] = Fullexp_P.REDDC_Y0;

      // SystemInitialize for SignalConversion generated from: '<S244>/ThrustPer_Final' incorporates:
      //   Outport: '<S244>/Out1'

      Fullexp_B.ThrustPer_Final_h5[i] = Fullexp_P.Out1_Y0_j;
    }

    // End of SystemInitialize for SubSystem: '<S26>/Change RED Behavior'
    // End of SystemInitialize for SubSystem: '<S238>/Enabled Subsystem1'
    Fullexp_Pseudoinverse1_Init(&Fullexp_DW.Pseudoinverse1);

    // End of SystemInitialize for SubSystem: '<S26>/Change BLACK Behavior'

    // SystemInitialize for IfAction SubSystem: '<S26>/Change BLUE Behavior'
    // InitializeConditions for Delay: '<S250>/Delay'
    Fullexp_DW.Delay_DSTATE_kf = Fullexp_P.Delay_InitialCondition_n;

    // SystemInitialize for Enabled SubSystem: '<S250>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S255>/In1' incorporates:
    //   Outport: '<S255>/Out1'

    Fullexp_B.In1_g = Fullexp_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<S250>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S250>/Enabled Subsystem1'
    // SystemInitialize for IfAction SubSystem: '<S26>/Change BLACK Behavior'
    for (i = 0; i < 8; i++) {
      // SystemInitialize for Outport: '<S233>/BLACK DC'
      Fullexp_B.duty_cycles_l[i] = Fullexp_P.BLACKDC_Y0;

      // SystemInitialize for SignalConversion generated from: '<S256>/ThrustPer_Final' incorporates:
      //   Outport: '<S256>/Out1'

      Fullexp_B.ThrustPer_Final_h[i] = Fullexp_P.Out1_Y0_js;
    }

    // End of SystemInitialize for SubSystem: '<S26>/Change BLACK Behavior'
    // End of SystemInitialize for SubSystem: '<S250>/Enabled Subsystem1'
    Fullexp_Pseudoinverse1_Init(&Fullexp_DW.Pseudoinverse1_p);

    // SystemInitialize for Outport: '<S234>/BLUE DC'
    for (i = 0; i < 8; i++) {
      Fullexp_B.duty_cycles_p[i] = Fullexp_P.BLUEDC_Y0;
    }

    // End of SystemInitialize for Outport: '<S234>/BLUE DC'
    // End of SystemInitialize for SubSystem: '<S26>/Change BLUE Behavior'

    // Start for MATLABSystem: '<S172>/MATLAB System'
    //  Constructor
    //  Support name-value pair arguments when constructing the object.
    Fullexp_DW.obj_b.matlabCodegenIsDeleted = false;
    Fullexp_DW.obj_b.isInitialized = 1;

    //         %% Define input properties
    //  Call C-function implementing device initialization
    createFile();
    Fullexp_DW.obj_b.isSetupComplete = true;
  }
}

// Model terminate function
void Fullexp_terminate(void)
{
  char_T *sErr;

  // Terminate for IfAction SubSystem: '<S4>/Change BLACK Behavior'
  Fullex_ChangeBLACKBehavior_Term(Fullexp_M, &Fullexp_DW.ChangeBLACKBehavior);

  // End of Terminate for SubSystem: '<S4>/Change BLACK Behavior'

  // Terminate for IfAction SubSystem: '<S4>/Change BLUE Behavior'
  Fullex_ChangeBLACKBehavior_Term(Fullexp_M, &Fullexp_DW.ChangeBLUEBehavior);

  // End of Terminate for SubSystem: '<S4>/Change BLUE Behavior'

  // Terminate for IfAction SubSystem: '<S4>/Change RED Behavior'
  Fullex_ChangeBLACKBehavior_Term(Fullexp_M, &Fullexp_DW.ChangeREDBehavior);

  // End of Terminate for SubSystem: '<S4>/Change RED Behavior'

  // Terminate for MATLABSystem: '<S172>/MATLAB System'
  if (!Fullexp_DW.obj_b.matlabCodegenIsDeleted) {
    Fullexp_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S172>/MATLAB System'

  // Terminate for IfAction SubSystem: '<S7>/Change BLACK Behavior'
  // Terminate for S-Function (sdspToNetwork): '<S174>/UDP Send1'
  sErr = GetErrorBuffer(&Fullexp_DW.UDPSend1_NetworkLib[0U]);
  LibTerminate(&Fullexp_DW.UDPSend1_NetworkLib[0U]);
  if (*sErr != 0) {
    Fullexp_M->setErrorStatus(sErr);
    Fullexp_M->setStopRequested(1);
  }

  LibDestroy(&Fullexp_DW.UDPSend1_NetworkLib[0U], 1);
  DestroyUDPInterface(&Fullexp_DW.UDPSend1_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S174>/UDP Send1'
  // End of Terminate for SubSystem: '<S7>/Change BLACK Behavior'

  // Terminate for IfAction SubSystem: '<S7>/Change BLUE Behavior'
  // Terminate for S-Function (sdspToNetwork): '<S175>/UDP Send2'
  sErr = GetErrorBuffer(&Fullexp_DW.UDPSend2_NetworkLib[0U]);
  LibTerminate(&Fullexp_DW.UDPSend2_NetworkLib[0U]);
  if (*sErr != 0) {
    Fullexp_M->setErrorStatus(sErr);
    Fullexp_M->setStopRequested(1);
  }

  LibDestroy(&Fullexp_DW.UDPSend2_NetworkLib[0U], 1);
  DestroyUDPInterface(&Fullexp_DW.UDPSend2_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S175>/UDP Send2'
  // End of Terminate for SubSystem: '<S7>/Change BLUE Behavior'

  // Terminate for IfAction SubSystem: '<S7>/Change RED Behavior'
  // Terminate for S-Function (sdspToNetwork): '<S176>/UDP Send3'
  sErr = GetErrorBuffer(&Fullexp_DW.UDPSend3_NetworkLib[0U]);
  LibTerminate(&Fullexp_DW.UDPSend3_NetworkLib[0U]);
  if (*sErr != 0) {
    Fullexp_M->setErrorStatus(sErr);
    Fullexp_M->setStopRequested(1);
  }

  LibDestroy(&Fullexp_DW.UDPSend3_NetworkLib[0U], 1);
  DestroyUDPInterface(&Fullexp_DW.UDPSend3_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S176>/UDP Send3'
  // End of Terminate for SubSystem: '<S7>/Change RED Behavior'

  // Terminate for IfAction SubSystem: '<S8>/Enable Pucks'
  // Terminate for MATLABSystem: '<S177>/GPIO Write1'
  if (!Fullexp_DW.obj_c.matlabCodegenIsDeleted) {
    Fullexp_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((Fullexp_DW.obj_c.isInitialized == 1) &&
        Fullexp_DW.obj_c.isSetupComplete) {
      //  Call C-function implementing device termination
      change_gpio_value(Fullexp_DW.obj_c.gpioPin, 0.0);
      unexport_gpio(Fullexp_DW.obj_c.gpioPin);
    }
  }

  // End of Terminate for MATLABSystem: '<S177>/GPIO Write1'
  // End of Terminate for SubSystem: '<S8>/Enable Pucks'

  // Terminate for IfAction SubSystem: '<S9>/Log Gyro//Accel'
  // Terminate for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  if (!Fullexp_DW.obj.matlabCodegenIsDeleted) {
    Fullexp_DW.obj.matlabCodegenIsDeleted = true;
  }

  if (!Fullexp_DW.obj._pobj2.matlabCodegenIsDeleted) {
    Fullexp_DW.obj._pobj2.matlabCodegenIsDeleted = true;
    if (Fullexp_DW.obj._pobj2.isInitialized == 1) {
      Fullexp_DW.obj._pobj2.isInitialized = 2;
    }
  }

  // End of Terminate for MATLABSystem: '<S178>/Gyroscope//Accelerometer'
  // End of Terminate for SubSystem: '<S9>/Log Gyro//Accel'

  // Terminate for IfAction SubSystem: '<S12>/Change ARM Behavior'
  // Terminate for MATLABSystem: '<S180>/Read Joint Positions using  Dynamixel Encoders' 
  if (!Fullexp_DW.obj_d.matlabCodegenIsDeleted) {
    Fullexp_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S180>/Read Joint Positions using  Dynamixel Encoders' 
  // End of Terminate for SubSystem: '<S12>/Change ARM Behavior'

  // Terminate for IfAction SubSystem: '<S13>/Use Hardware to Obtain States'
  // Terminate for S-Function (sdspFromNetwork): '<S183>/Receive PhaseSpace Data' 
  sErr = GetErrorBuffer(&Fullexp_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
  LibTerminate(&Fullexp_DW.ReceivePhaseSpaceData_NetworkLi[0U]);
  if (*sErr != 0) {
    Fullexp_M->setErrorStatus(sErr);
    Fullexp_M->setStopRequested(1);
  }

  LibDestroy(&Fullexp_DW.ReceivePhaseSpaceData_NetworkLi[0U], 0);
  DestroyUDPInterface(&Fullexp_DW.ReceivePhaseSpaceData_NetworkLi[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S183>/Receive PhaseSpace Data' 

  // Terminate for S-Function (sdspFromNetwork): '<S188>/UDP Receive'
  sErr = GetErrorBuffer(&Fullexp_DW.UDPReceive_NetworkLib[0U]);
  LibTerminate(&Fullexp_DW.UDPReceive_NetworkLib[0U]);
  if (*sErr != 0) {
    Fullexp_M->setErrorStatus(sErr);
    Fullexp_M->setStopRequested(1);
  }

  LibDestroy(&Fullexp_DW.UDPReceive_NetworkLib[0U], 0);
  DestroyUDPInterface(&Fullexp_DW.UDPReceive_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S188>/UDP Receive'

  // Terminate for S-Function (sdspFromNetwork): '<S188>/UDP Receive2'
  sErr = GetErrorBuffer(&Fullexp_DW.UDPReceive2_NetworkLib[0U]);
  LibTerminate(&Fullexp_DW.UDPReceive2_NetworkLib[0U]);
  if (*sErr != 0) {
    Fullexp_M->setErrorStatus(sErr);
    Fullexp_M->setStopRequested(1);
  }

  LibDestroy(&Fullexp_DW.UDPReceive2_NetworkLib[0U], 0);
  DestroyUDPInterface(&Fullexp_DW.UDPReceive2_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S188>/UDP Receive2'

  // Terminate for S-Function (sdspFromNetwork): '<S188>/UDP Receive3'
  sErr = GetErrorBuffer(&Fullexp_DW.UDPReceive3_NetworkLib[0U]);
  LibTerminate(&Fullexp_DW.UDPReceive3_NetworkLib[0U]);
  if (*sErr != 0) {
    Fullexp_M->setErrorStatus(sErr);
    Fullexp_M->setStopRequested(1);
  }

  LibDestroy(&Fullexp_DW.UDPReceive3_NetworkLib[0U], 0);
  DestroyUDPInterface(&Fullexp_DW.UDPReceive3_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S188>/UDP Receive3'
  // End of Terminate for SubSystem: '<S13>/Use Hardware to Obtain States'

  // Terminate for IfAction SubSystem: '<S14>/Subsystem'
  // Terminate for MATLABSystem: '<S222>/WhoAmI'
  if (!Fullexp_DW.obj_dk.matlabCodegenIsDeleted) {
    Fullexp_DW.obj_dk.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S222>/WhoAmI'
  // End of Terminate for SubSystem: '<S14>/Subsystem'

  // Terminate for IfAction SubSystem: '<S18>/Subsystem'
  // Terminate for S-Function (sdspFromNetwork): '<S226>/UDP Receive1'
  sErr = GetErrorBuffer(&Fullexp_DW.UDPReceive1_NetworkLib[0U]);
  LibTerminate(&Fullexp_DW.UDPReceive1_NetworkLib[0U]);
  if (*sErr != 0) {
    Fullexp_M->setErrorStatus(sErr);
    Fullexp_M->setStopRequested(1);
  }

  LibDestroy(&Fullexp_DW.UDPReceive1_NetworkLib[0U], 0);
  DestroyUDPInterface(&Fullexp_DW.UDPReceive1_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S226>/UDP Receive1'
  // End of Terminate for SubSystem: '<S18>/Subsystem'

  // Terminate for IfAction SubSystem: '<S21>/Change ARM Behavior'
  // Terminate for MATLABSystem: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
  if (!Fullexp_DW.obj_n.matlabCodegenIsDeleted) {
    Fullexp_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Fullexp_DW.obj_n.isInitialized == 1) &&
        Fullexp_DW.obj_n.isSetupComplete) {
      terminate_dynamixel();
    }
  }

  // End of Terminate for MATLABSystem: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
  // End of Terminate for SubSystem: '<S21>/Change ARM Behavior'

  // Terminate for IfAction SubSystem: '<S24>/Subsystem'
  // Terminate for S-Function (sdspToNetwork): '<S232>/UDP Send'
  sErr = GetErrorBuffer(&Fullexp_DW.UDPSend_NetworkLib_m[0U]);
  LibTerminate(&Fullexp_DW.UDPSend_NetworkLib_m[0U]);
  if (*sErr != 0) {
    Fullexp_M->setErrorStatus(sErr);
    Fullexp_M->setStopRequested(1);
  }

  LibDestroy(&Fullexp_DW.UDPSend_NetworkLib_m[0U], 1);
  DestroyUDPInterface(&Fullexp_DW.UDPSend_NetworkLib_m[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S232>/UDP Send'
  // End of Terminate for SubSystem: '<S24>/Subsystem'

  // Terminate for S-Function (sdspToNetwork): '<S26>/UDP Send'
  sErr = GetErrorBuffer(&Fullexp_DW.UDPSend_NetworkLib[0U]);
  LibTerminate(&Fullexp_DW.UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    Fullexp_M->setErrorStatus(sErr);
    Fullexp_M->setStopRequested(1);
  }

  LibDestroy(&Fullexp_DW.UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&Fullexp_DW.UDPSend_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspToNetwork): '<S26>/UDP Send'
}

time_T** RT_MODEL_Fullexp_T::getTPtrPtr()
{
  return &(Timing.t);
}

boolean_T RT_MODEL_Fullexp_T::getStopRequested() const
{
  return (Timing.stopRequestedFlag);
}

void RT_MODEL_Fullexp_T::setStopRequested(boolean_T aStopRequested)
{
  (Timing.stopRequestedFlag = aStopRequested);
}

const char_T* RT_MODEL_Fullexp_T::getErrorStatus() const
{
  return (errorStatus);
}

void RT_MODEL_Fullexp_T::setErrorStatus(const char_T* const aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

time_T* RT_MODEL_Fullexp_T::getTPtr() const
{
  return (Timing.t);
}

void RT_MODEL_Fullexp_T::setTPtr(time_T* aTPtr)
{
  (Timing.t = aTPtr);
}

boolean_T* RT_MODEL_Fullexp_T::getStopRequestedPtr()
{
  return (&(Timing.stopRequestedFlag));
}

const char_T** RT_MODEL_Fullexp_T::getErrorStatusPtr()
{
  return &errorStatus;
}

boolean_T RT_MODEL_Fullexp_T::isMajorTimeStep() const
{
  return ((Timing.simTimeStep) == MAJOR_TIME_STEP);
}

boolean_T RT_MODEL_Fullexp_T::isMinorTimeStep() const
{
  return ((Timing.simTimeStep) == MINOR_TIME_STEP);
}

//
// File trailer for generated code.
//
// [EOF]
//
