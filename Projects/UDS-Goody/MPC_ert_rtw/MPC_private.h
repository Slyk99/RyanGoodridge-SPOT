//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MPC_private.h
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
#ifndef MPC_private_h_
#define MPC_private_h_
#include "rtwtypes.h"
#include "MPC.h"
#include "MPC_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);

// Exported functions
extern void MPC_rotm2Quat(const real_T C[9], real_T q[4]);
extern void MPC_smallQuat(const real_T q[4], real_T p[4]);
extern int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);
extern void MPC_Phase0Synchronization(real_T *rtd_ARM_Control_Law_Enabler,
  real_T *rtd_ARM_Path_Planner_Selection, real_T *rtd_BLACK_Control_Law_Enabler,
  real_T *rtd_BLACK_Path_Planner_Selectio, real_T *rtd_BLUE_Control_Law_Enabler,
  real_T *rtd_BLUE_Path_Planner_Selection, real_T *rtd_Float_State, real_T
  *rtd_RED_Control_Law_Enabler, char_T rtd_RED_Logger[256], real_T
  *rtd_RED_Path_Planner_Selection, real_T *rtd_Toggle_Nav,
  P_Phase0Synchronization_MPC_T *localP);
extern void MPC_Phase4ReturnHome(real_T *rtd_ARM_Control_Law_Enabler, real_T
  rtd_ARM_Desired_States[3], real_T *rtd_ARM_Path_Planner_Selection, real_T
  *rtd_BLACK_Control_Law_Enabler, real_T rtd_BLACK_Desired_States[3], real_T
  *rtd_BLACK_Path_Planner_Selectio, real_T *rtd_BLUE_Control_Law_Enabler, real_T
  rtd_BLUE_Desired_States[3], real_T *rtd_BLUE_Path_Planner_Selection, real_T
  *rtd_Float_State, real_T *rtd_RED_Control_Law_Enabler, real_T
  rtd_RED_Desired_States[3], real_T *rtd_RED_Path_Planner_Selection, real_T
  *rtd_Toggle_Nav, P_Phase4ReturnHome_MPC_T *localP);
extern void MPC_MATLABFunction(const real_T rtu_desiredPosition[3], const real_T
  rtu_obstacles[4], real_T rtu_attractiveGain, real_T rtu_repulsiveGain, real_T
  rtu_influenceRange, real_T rtu_angularGain, real_T rty_currentPosition[3]);
extern void MPC_MATLABFunction_g(const real_T rtu_true[4], const real_T
  rtu_true_m[3], const real_T rtu_true_b[3], const real_T rtu_true_g[3], const
  real_T rtu_est[13], real_T rty_y[6]);
extern void MPC_MATLABFunction_d(const real_T rtu_u[6], real_T rty_states[12]);
extern void MPC_MATLABFunction11(const real_T rtu_q_red[4], const real_T
  rtu_q_vis[4], const real_T rtu_v[3], const real_T rtu_x[3], real_T rty_y[7]);
extern void MPC_MATLABFunction_a(const real_T rtu_u[13], real_T rty_out[13]);
extern void MPC_MATLABFunction_gs(const real_T rtu_x[9], const real_T rtu_q[4],
  real_T rty_out[13]);
extern void MPC_MATLABFunction11_l(const real_T rtu_u[9], real_T rty_y[4]);
extern void MPC_MATLABFunction_m(real_T rtu_Rz_path, real_T rtu_Rz_measured,
  real_T *rty_Rz_error);
extern void MPC_DisableThrustersRED(real_T rty_u[3], P_DisableThrustersRED_MPC_T
  *localP);
extern void MPC_DefaultPDControlBLACK_Init(DW_DefaultPDControlBLACK_MPC_T
  *localDW, P_DefaultPDControlBLACK_MPC_T *localP);
extern void MPC_DefaultPDControlBLACK(real_T rty_u[3], real_T
  rtd_BLACK_CTL_Input[6], const real_T rtd_BLACK_Measured_States[9], const
  real_T rtd_BLACK_Path[3], DW_DefaultPDControlBLACK_MPC_T *localDW,
  P_DefaultPDControlBLACK_MPC_T *localP);
extern void MPC_ChangeBLACKBehavior_Init(RT_MODEL_MPC_T * const MPC_M,
  DW_ChangeBLACKBehavior_MPC_T *localDW, P_ChangeBLACKBehavior_MPC_T *localP);
extern void MPC_ChangeBLACKBehavior(RT_MODEL_MPC_T * const MPC_M,
  DW_ChangeBLACKBehavior_MPC_T *localDW, P_ChangeBLACKBehavior_MPC_T *localP);
extern void MPC_MATLABFunction_f(real_T rtu_u, real_T *rty_y);
extern void MPC_MATLABFunction_j(const real_T rtu_u[6], real_T rty_y[6]);
extern void MPC_MATLABFunction_c(const real_T rtu_u[3], real_T rty_y[3]);
extern void MPC_MATLABFunction_jn(real_T rtu_dt, real_T rtu_dataRate, real_T
  *rty_dt_out);
extern void MPC_EnabledSubsystem_Init(real_T rty_dydt[3],
  DW_EnabledSubsystem_MPC_T *localDW, P_EnabledSubsystem_MPC_T *localP);
extern void MPC_EnabledSubsystem_Disable(DW_EnabledSubsystem_MPC_T *localDW);
extern void MPC_EnabledSubsystem_Update(real_T rty_dydt[3],
  B_EnabledSubsystem_MPC_T *localB, DW_EnabledSubsystem_MPC_T *localDW);
extern void MPC_EnabledSubsystem(const boolean_T rtu_Enable[3], const real_T
  rtu_y[3], real_T rtu_dt, real_T rty_dydt[3], B_EnabledSubsystem_MPC_T *localB,
  DW_EnabledSubsystem_MPC_T *localDW, P_EnabledSubsystem_MPC_T *localP);
extern void MPC_EnabledSubsystem_h_Init(real_T rty_dydt[3],
  DW_EnabledSubsystem_MPC_m_T *localDW, P_EnabledSubsystem_MPC_d_T *localP);
extern void MPC_EnabledSubsystem_h_Disable(DW_EnabledSubsystem_MPC_m_T *localDW);
extern void MPC_EnabledSubsystem_n_Update(real_T rty_dydt[3],
  B_EnabledSubsystem_MPC_b_T *localB, DW_EnabledSubsystem_MPC_m_T *localDW);
extern void MPC_EnabledSubsystem_n(const boolean_T rtu_Enable[3], real_T rtu_y,
  real_T rtu_y_p, real_T rtu_y_o, real_T rtu_dt, real_T rty_dydt[3],
  B_EnabledSubsystem_MPC_b_T *localB, DW_EnabledSubsystem_MPC_m_T *localDW,
  P_EnabledSubsystem_MPC_d_T *localP);
extern void MPC_MATLABFunction_c1(real_T rtu_dt, const real_T rtu_z[3], const
  real_T rtu_u[3], real_T rty_x[6], real_T rty_P[36]);
extern void MPC_MATLABFunction1(const real_T rtu_u[9], const real_T rtu_uprev[9],
  real_T rty_y[3]);
extern void MPC_MATLABFunction1_e(real_T rtu_z, real_T rtu_zk, real_T *rty_x);
extern void MPC_Pseudoinverse1_Init(DW_Pseudoinverse1_MPC_T *localDW);
extern void MPC_Pseudoinverse1(const real_T rtu_0[24], B_Pseudoinverse1_MPC_T
  *localB);
extern void MPC_CreateRotationMatrix(real_T rtu_Rz, real_T rty_C_Ib[4]);
extern void MPC_CreateRotationMatrix_k(real_T rtu_Rz, real_T rty_C_bI[4]);
extern void MPC_MATLABFunction1_i(const real_T rtu_ThrustPer[8], real_T
  rty_ThrustPer_Final[8]);
extern void MPC_ChangeBLACKBehavior_Term(RT_MODEL_MPC_T * const MPC_M,
  DW_ChangeBLACKBehavior_MPC_T *localDW);

#endif                                 // MPC_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
