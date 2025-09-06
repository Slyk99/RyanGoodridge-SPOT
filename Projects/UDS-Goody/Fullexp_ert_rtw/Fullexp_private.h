//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Fullexp_private.h
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
#ifndef Fullexp_private_h_
#define Fullexp_private_h_
#include "rtwtypes.h"
#include "Fullexp.h"
#include "Fullexp_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

extern real_T rt_atan2d_snf(real_T u0, real_T u1);

#ifdef __cplusplus

extern "C"
{

#endif

  // Exported functions
  extern void Fullexp_rotm2Quat(const real_T C[9], real_T q[4]);

#ifdef __cplusplus

}

#endif

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);

// Exported functions
extern void Fullexp_dqMultiply(const real_T q[8], const real_T p[8], real_T dq[8]);
extern void Fullexp_smallQuat(const real_T q[4], real_T p[4]);
extern int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);
extern void Fullexp_Phase0Synchronization(real_T *rtd_ARM_Control_Law_Enabler,
  real_T *rtd_ARM_Path_Planner_Selection, real_T *rtd_BLACK_Control_Law_Enabler,
  real_T *rtd_BLACK_Path_Planner_Selectio, real_T *rtd_BLUE_Control_Law_Enabler,
  real_T *rtd_BLUE_Path_Planner_Selection, real_T *rtd_Float_State, real_T
  *rtd_RED_Control_Law_Enabler, char_T rtd_RED_Logger[256], real_T
  *rtd_RED_Path_Planner_Selection, P_Phase0Synchronization_Fulle_T *localP);
extern void Fullexp_Phase4ReturnHome(real_T *rtd_ARM_Control_Law_Enabler, real_T
  rtd_ARM_Desired_States[3], real_T *rtd_ARM_Path_Planner_Selection, real_T
  *rtd_BLACK_Control_Law_Enabler, real_T rtd_BLACK_Desired_States[3], real_T
  *rtd_BLACK_Path_Planner_Selectio, real_T *rtd_BLUE_Control_Law_Enabler, real_T
  rtd_BLUE_Desired_States[3], real_T *rtd_BLUE_Path_Planner_Selection, real_T
  *rtd_Float_State, real_T *rtd_RED_Control_Law_Enabler, real_T
  rtd_RED_Desired_States[3], real_T *rtd_RED_Path_Planner_Selection,
  P_Phase4ReturnHome_Fullexp_T *localP);
extern void Fullexp_MATLABFunction(const real_T rtu_desiredPosition[3], const
  real_T rtu_obstacles[4], real_T rtu_attractiveGain, real_T rtu_repulsiveGain,
  real_T rtu_influenceRange, real_T rtu_angularGain, real_T rty_currentPosition
  [3]);
extern void Fullexp_MATLABFunction_n(real_T rtu_Rz_path, real_T rtu_Rz_measured,
  real_T *rty_Rz_error);
extern void Fullexp_CustomControlRED(real_T rty_u[3],
  P_CustomControlRED_Fullexp_T *localP);
extern void Fullexp_DisableThrustersBLACK(real_T rty_Out1[3],
  P_DisableThrustersBLACK_Fulle_T *localP);
extern void Fullex_ChangeBLACKBehavior_Init(RT_MODEL_Fullexp_T * const Fullexp_M,
  DW_ChangeBLACKBehavior_Fullex_T *localDW, P_ChangeBLACKBehavior_Fullexp_T
  *localP);
extern void Fullexp_ChangeBLACKBehavior(RT_MODEL_Fullexp_T * const Fullexp_M,
  DW_ChangeBLACKBehavior_Fullex_T *localDW, P_ChangeBLACKBehavior_Fullexp_T
  *localP);
extern void Fullexp_MATLABFunction_f(const real_T rtu_z[9], real_T rty_x[12]);
extern void Fullexp_MATLABFunction_j(real_T rtu_dt, real_T rtu_dataRate, real_T *
  rty_dt_out);
extern void Fullexp_EnabledSubsystem_Init(real_T rty_dydt[3],
  DW_EnabledSubsystem_Fullexp_T *localDW, P_EnabledSubsystem_Fullexp_T *localP);
extern void Fullex_EnabledSubsystem_Disable(DW_EnabledSubsystem_Fullexp_T
  *localDW);
extern void Fullexp_EnabledSubsystem_Update(real_T rty_dydt[3],
  B_EnabledSubsystem_Fullexp_T *localB, DW_EnabledSubsystem_Fullexp_T *localDW);
extern void Fullexp_EnabledSubsystem(const boolean_T rtu_Enable[3], const real_T
  rtu_y[3], real_T rtu_dt, real_T rty_dydt[3], B_EnabledSubsystem_Fullexp_T
  *localB, DW_EnabledSubsystem_Fullexp_T *localDW, P_EnabledSubsystem_Fullexp_T *
  localP);
extern void Fullexp_EnabledSubsystem_o_Init(real_T rty_dydt[3],
  DW_EnabledSubsystem_Fullexp_m_T *localDW, P_EnabledSubsystem_Fullexp_d_T
  *localP);
extern void Full_EnabledSubsystem_g_Disable(DW_EnabledSubsystem_Fullexp_m_T
  *localDW);
extern void Fulle_EnabledSubsystem_g_Update(real_T rty_dydt[3],
  B_EnabledSubsystem_Fullexp_b_T *localB, DW_EnabledSubsystem_Fullexp_m_T
  *localDW);
extern void Fullexp_EnabledSubsystem_n(const boolean_T rtu_Enable[3], real_T
  rtu_y, real_T rtu_y_p, real_T rtu_y_o, real_T rtu_dt, real_T rty_dydt[3],
  B_EnabledSubsystem_Fullexp_b_T *localB, DW_EnabledSubsystem_Fullexp_m_T
  *localDW, P_EnabledSubsystem_Fullexp_d_T *localP);
extern void Fullexp_MATLABFunction_l(const real_T rtu_u[12], real_T rty_dq[8],
  real_T rty_q[4], real_T rty_R[9], real_T rty_x[3], real_T rty_v[3], real_T
  rty_w[3], real_T *rty_yaw);
extern void Fullexp_Pseudoinverse1_Init(DW_Pseudoinverse1_Fullexp_T *localDW);
extern void Fullexp_Pseudoinverse1(const real_T rtu_0[24],
  B_Pseudoinverse1_Fullexp_T *localB);
extern void Fullexp_MATLABFunction1(const real_T rtu_ThrustPer[8], real_T
  rty_ThrustPer_Final[8]);
extern void Fullexp_CreateRotationMatrix(real_T rtu_Rz, real_T rty_C_Ib[4]);
extern void Fullexp_CreateRotationMatrix_a(real_T rtu_Rz, real_T rty_C_bI[4]);
extern void Fullex_ChangeBLACKBehavior_Term(RT_MODEL_Fullexp_T * const Fullexp_M,
  DW_ChangeBLACKBehavior_Fullex_T *localDW);

#endif                                 // Fullexp_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
