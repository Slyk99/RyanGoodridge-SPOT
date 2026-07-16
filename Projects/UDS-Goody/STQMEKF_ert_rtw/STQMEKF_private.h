//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: STQMEKF_private.h
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
#ifndef STQMEKF_private_h_
#define STQMEKF_private_h_
#include "rtwtypes.h"
#include "STQMEKF.h"
#include "STQMEKF_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);
extern int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);
extern void STQMEKF_Phase0Synchronization(real_T *rtd_ARM_Control_Law_Enabler,
  real_T *rtd_ARM_Path_Planner_Selection, real_T *rtd_BLACK_Control_Law_Enabler,
  real_T *rtd_BLACK_Path_Planner_Selectio, real_T *rtd_BLUE_Control_Law_Enabler,
  real_T *rtd_BLUE_Path_Planner_Selection, real_T *rtd_Float_State, real_T
  *rtd_RED_Control_Law_Enabler, char_T rtd_RED_Logger[256], real_T
  *rtd_RED_Path_Planner_Selection, P_Phase0Synchronization_STQME_T *localP);
extern void STQMEKF_Phase4ReturnHome(real_T *rtd_ARM_Control_Law_Enabler, real_T
  rtd_ARM_Desired_States[3], real_T *rtd_ARM_Path_Planner_Selection, real_T
  *rtd_BLACK_Control_Law_Enabler, real_T rtd_BLACK_Desired_States[3], real_T
  *rtd_BLACK_Path_Planner_Selectio, real_T *rtd_BLUE_Control_Law_Enabler, real_T
  rtd_BLUE_Desired_States[3], real_T *rtd_BLUE_Path_Planner_Selection, real_T
  *rtd_Float_State, real_T *rtd_RED_Control_Law_Enabler, real_T
  rtd_RED_Desired_States[3], real_T *rtd_RED_Path_Planner_Selection,
  P_Phase4ReturnHome_STQMEKF_T *localP);
extern void STQMEKF_MATLABFunction(const real_T rtu_desiredPosition[3], const
  real_T rtu_obstacles[4], real_T rtu_attractiveGain, real_T rtu_repulsiveGain,
  real_T rtu_influenceRange, real_T rtu_angularGain, real_T rty_currentPosition
  [3]);
extern void STQMEKF_MATLABFunction_n(real_T rtu_Rz_path, real_T rtu_Rz_measured,
  real_T *rty_Rz_error);
extern void STQMEKF_CustomControlRED(real_T rty_u[3],
  P_CustomControlRED_STQMEKF_T *localP);
extern void STQMEKF_DisableThrustersBLACK(real_T rty_Out1[3],
  P_DisableThrustersBLACK_STQME_T *localP);
extern void STQMEK_ChangeBLACKBehavior_Init(RT_MODEL_STQMEKF_T * const STQMEKF_M,
  DW_ChangeBLACKBehavior_STQMEK_T *localDW, P_ChangeBLACKBehavior_STQMEKF_T
  *localP);
extern void STQMEKF_ChangeBLACKBehavior(RT_MODEL_STQMEKF_T * const STQMEKF_M,
  DW_ChangeBLACKBehavior_STQMEK_T *localDW, P_ChangeBLACKBehavior_STQMEKF_T
  *localP);
extern void STQMEKF_MATLABFunction_j(real_T rtu_dt, real_T rtu_dataRate, real_T *
  rty_dt_out);
extern void STQMEKF_EnabledSubsystem_Init(real_T rty_dydt[3],
  DW_EnabledSubsystem_STQMEKF_T *localDW, P_EnabledSubsystem_STQMEKF_T *localP);
extern void STQMEK_EnabledSubsystem_Disable(DW_EnabledSubsystem_STQMEKF_T
  *localDW);
extern void STQMEKF_EnabledSubsystem_Update(real_T rty_dydt[3],
  B_EnabledSubsystem_STQMEKF_T *localB, DW_EnabledSubsystem_STQMEKF_T *localDW);
extern void STQMEKF_EnabledSubsystem(const boolean_T rtu_Enable[3], const real_T
  rtu_y[3], real_T rtu_dt, real_T rty_dydt[3], B_EnabledSubsystem_STQMEKF_T
  *localB, DW_EnabledSubsystem_STQMEKF_T *localDW, P_EnabledSubsystem_STQMEKF_T *
  localP);
extern void STQMEKF_EnabledSubsystem_e_Init(real_T rty_dydt[3],
  DW_EnabledSubsystem_STQMEKF_m_T *localDW, P_EnabledSubsystem_STQMEKF_d_T
  *localP);
extern void STQM_EnabledSubsystem_l_Disable(DW_EnabledSubsystem_STQMEKF_m_T
  *localDW);
extern void STQME_EnabledSubsystem_n_Update(real_T rty_dydt[3],
  B_EnabledSubsystem_STQMEKF_b_T *localB, DW_EnabledSubsystem_STQMEKF_m_T
  *localDW);
extern void STQMEKF_EnabledSubsystem_n(const boolean_T rtu_Enable[3], real_T
  rtu_y, real_T rtu_y_p, real_T rtu_y_o, real_T rtu_dt, real_T rty_dydt[3],
  B_EnabledSubsystem_STQMEKF_b_T *localB, DW_EnabledSubsystem_STQMEKF_m_T
  *localDW, P_EnabledSubsystem_STQMEKF_d_T *localP);
extern void STQMEKF_Pseudoinverse1_Init(DW_Pseudoinverse1_STQMEKF_T *localDW);
extern void STQMEKF_Pseudoinverse1(const real_T rtu_0[24],
  B_Pseudoinverse1_STQMEKF_T *localB);
extern void STQMEKF_MATLABFunction1(const real_T rtu_ThrustPer[8], real_T
  rty_ThrustPer_Final[8]);
extern void STQMEKF_CreateRotationMatrix(real_T rtu_Rz, real_T rty_C_Ib[4]);
extern void STQMEKF_CreateRotationMatrix_a(real_T rtu_Rz, real_T rty_C_bI[4]);
extern void STQMEK_ChangeBLACKBehavior_Term(RT_MODEL_STQMEKF_T * const STQMEKF_M,
  DW_ChangeBLACKBehavior_STQMEK_T *localDW);

#endif                                 // STQMEKF_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
