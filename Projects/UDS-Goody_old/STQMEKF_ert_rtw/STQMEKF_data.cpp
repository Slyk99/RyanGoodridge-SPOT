//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: STQMEKF_data.cpp
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

// Block parameters (default storage)
P_STQMEKF_T STQMEKF_P = {
  // Variable: F_black_X_nominal
  //  Referenced by: '<S228>/MATLAB Function5'

  0.2825,

  // Variable: F_black_Y_nominal
  //  Referenced by: '<S228>/MATLAB Function5'

  0.2825,

  // Variable: F_blue_X_nominal
  //  Referenced by: '<S240>/MATLAB Function5'

  0.2825,

  // Variable: F_blue_Y_nominal
  //  Referenced by: '<S240>/MATLAB Function5'

  0.2825,

  // Variable: F_red_X_nominal
  //  Referenced by: '<S252>/MATLAB Function5'

  0.2825,

  // Variable: F_red_Y_nominal
  //  Referenced by: '<S252>/MATLAB Function5'

  0.2825,

  // Variable: F_thrusters_BLACK
  //  Referenced by: '<S231>/MATLAB Function'

  { 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825 },

  // Variable: F_thrusters_BLUE
  //  Referenced by: '<S243>/MATLAB Function'

  { 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825 },

  // Variable: F_thrusters_RED
  //  Referenced by: '<S255>/MATLAB Function'

  { 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825 },

  // Variable: K_BLACK
  //  Referenced by: '<S110>/Constant2'

  { 0.40234817833208658, 1.0311844491536458E-14, 3.3280085097900945E-15,
    -3.4849626273831559E-15, 0.4023481783320994, 2.4071774753115092E-15,
    2.1672051737834689E-15, 1.2843486460872702E-16, 0.081554964432253255,
    3.2805183386913637, 7.43122876806996E-14, 1.5522271489125213E-14,
    1.8053332398460726E-14, 3.2805183386913552, 1.0150603020041256E-14,
    8.2159574762201189E-16, -3.2725287139997539E-16, 0.40690949597934378 },

  // Variable: K_BLUE
  //  Referenced by: '<S111>/Constant2'

  { 0.40218238973674775, 1.683962826555525E-15, 7.5785945510315839E-15,
    3.9111419922025071E-15, 0.40218238973675713, 6.6736196360470178E-15,
    4.9400995945260145E-16, 4.4420114922023327E-16, 0.081407426263066282,
    3.2133409169777383, 5.46229728115577E-14, 7.5629359369335219E-14,
    4.34773196942792E-15, 3.213340916977828, 8.08249183037409E-14,
    2.74871748743334E-16, 1.4383159062603373E-16, 0.40554915553132154 },

  // Variable: K_RED
  //  Referenced by: '<S112>/Constant2'

  { 0.40232877970259667, -2.0263012511229824E-14, -8.4051443133328233E-16,
    5.8702555000223288E-16, 0.40232877970262537, -5.6425539336462471E-15,
    -6.41430742891448E-16, 1.1731704775391289E-15, 0.08149590638118985,
    3.2724457090025347, -1.3522860420014287E-13, 1.7987277018860464E-14,
    4.2362751675083559E-14, 3.2724457090028443, -3.58115642612403E-14,
    5.2160424216070551E-17, 5.5541095421028447E-16, 0.40636232022479724 },

  // Variable: Kd_elarm
  //  Referenced by: '<S138>/kd_elarm'

  0.8,

  // Variable: Kd_sharm
  //  Referenced by: '<S139>/kd_sharm'

  1.0,

  // Variable: Kd_tb
  //  Referenced by: '<S114>/Gain5'

  1.8,

  // Variable: Kd_tblue
  //  Referenced by: '<S115>/Gain5'

  1.8,

  // Variable: Kd_tr
  //  Referenced by: '<S116>/Gain5'

  1.8,

  // Variable: Kd_wrarm
  //  Referenced by: '<S140>/kd_wrarm'

  0.6,

  // Variable: Kd_xb
  //  Referenced by: '<S114>/Gain3'

  3.6,

  // Variable: Kd_xblue
  //  Referenced by: '<S115>/Gain3'

  3.6,

  // Variable: Kd_xr
  //  Referenced by: '<S116>/Gain3'

  3.6,

  // Variable: Kd_yb
  //  Referenced by: '<S114>/Gain4'

  3.6,

  // Variable: Kd_yblue
  //  Referenced by: '<S115>/Gain4'

  3.6,

  // Variable: Kd_yr
  //  Referenced by: '<S116>/Gain4'

  3.6,

  // Variable: Kp_elarm
  //  Referenced by: '<S138>/kp_elarm'

  1.2,

  // Variable: Kp_sharm
  //  Referenced by: '<S139>/kp_sharm'

  1.5,

  // Variable: Kp_tb
  //  Referenced by: '<S114>/Gain2'

  0.5,

  // Variable: Kp_tblue
  //  Referenced by: '<S115>/Gain2'

  0.5,

  // Variable: Kp_tr
  //  Referenced by: '<S116>/Gain2'

  0.5,

  // Variable: Kp_wrarm
  //  Referenced by: '<S140>/kp_wrarm'

  1.0,

  // Variable: Kp_xb
  //  Referenced by: '<S114>/Gain'

  1.0,

  // Variable: Kp_xblue
  //  Referenced by: '<S115>/Gain'

  1.0,

  // Variable: Kp_xr
  //  Referenced by: '<S116>/Gain'

  1.0,

  // Variable: Kp_yb
  //  Referenced by: '<S114>/Gain1'

  1.0,

  // Variable: Kp_yblue
  //  Referenced by: '<S115>/Gain1'

  1.0,

  // Variable: Kp_yr
  //  Referenced by: '<S116>/Gain1'

  1.0,

  // Variable: PWMFreq
  //  Referenced by:
  //    '<S17>/PWM Frequency'
  //    '<S228>/MATLAB Function1'
  //    '<S240>/MATLAB Function1'
  //    '<S252>/MATLAB Function8'
  //    '<S230>/Constant1'
  //    '<S242>/Constant1'
  //    '<S254>/Constant1'

  5.0,

  // Variable: Phase0_End
  //  Referenced by: '<S1>/Constant4'

  10.0,

  // Variable: Phase1_End
  //  Referenced by: '<S1>/Constant'

  15.0,

  // Variable: Phase2_End
  //  Referenced by:
  //    '<S1>/Constant1'
  //    '<S38>/Constant2'
  //    '<S49>/Constant2'
  //    '<S57>/Constant2'
  //    '<S69>/Constant2'
  //    '<S47>/Constant1'
  //    '<S63>/Constant1'

  15.0,

  // Variable: Phase3_End
  //  Referenced by: '<S1>/Constant2'

  135.0,

  // Variable: Phase3_SubPhase1_End
  //  Referenced by: '<S21>/Constant4'

  135.0,

  // Variable: Phase3_SubPhase2_End
  //  Referenced by:
  //    '<S21>/Constant1'
  //    '<S55>/Constant'

  135.0,

  // Variable: Phase3_SubPhase3_End
  //  Referenced by: '<S21>/Constant2'

  135.0,

  // Variable: Phase3_SubPhase4_End
  //  Referenced by: '<S21>/Constant3'

  135.0,

  // Variable: Phase4_End
  //  Referenced by: '<S1>/Constant3'

  135.0,

  // Variable: Phase5_End
  //  Referenced by: '<S1>/Constant6'

  136.0,

  // Variable: Tz_lim_elarm
  //  Referenced by: '<S137>/Saturation1'

  0.1,

  // Variable: Tz_lim_sharm
  //  Referenced by: '<S137>/Saturation'

  0.1,

  // Variable: Tz_lim_wrarm
  //  Referenced by: '<S137>/Saturation3'

  0.1,

  // Variable: baseRate
  //  Referenced by:
  //    '<S84>/MATLAB Function'
  //    '<S85>/MATLAB Function'
  //    '<S170>/Read Joint Positions using  Dynamixel Encoders'
  //    '<S212>/WhoAmI'
  //    '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.05,

  // Variable: dataRate
  //  Referenced by:
  //    '<S182>/Constant'
  //    '<S192>/Constant'
  //    '<S202>/Constant'

  0.1,

  // Variable: home_states_BLACK
  //  Referenced by:
  //    '<S73>/Desired States (BLACK)'
  //    '<S77>/Desired States (BLACK)'
  //    '<S65>/Constant'

  { 1.755775, 1.209675, 0.0 },

  // Variable: home_states_BLUE
  //  Referenced by:
  //    '<S74>/Desired States (BLUE)'
  //    '<S78>/Desired States (BLUE)'

  { 0.85577500000000006, 1.209675, 0.0 },

  // Variable: home_states_RED
  //  Referenced by:
  //    '<S75>/Constant2'
  //    '<S79>/Constant2'
  //    '<S67>/Constant'

  { 2.655775, 1.209675, 3.1415926535897931 },

  // Variable: init_states_BLACK
  //  Referenced by:
  //    '<S26>/Desired States (BLACK)'
  //    '<S34>/Constant'

  { 1.755775, 1.209675, 0.0 },

  // Variable: init_states_BLUE
  //  Referenced by: '<S27>/Desired States (BLUE)'

  { 0.85577500000000006, 1.209675, 0.0 },

  // Variable: init_states_RED
  //  Referenced by:
  //    '<S28>/Constant2'
  //    '<S36>/Constant'
  //    '<S44>/Constant'
  //    '<S44>/Constant1'
  //    '<S44>/Constant4'
  //    '<S54>/Constant'

  { 2.655775, 1.209675, 3.1415926535897931 },

  // Variable: platformSelection
  //  Referenced by: '<S178>/MATLAB Function'

  3.0,

  // Variable: simMode
  //  Referenced by: '<S16>/Constant'

  0.0,

  // Variable: thruster_dist2CG_BLACK
  //  Referenced by:
  //    '<S228>/MATLAB Function5'
  //    '<S231>/MATLAB Function'

  { 87.2054215807076, -50.794578419292378, 67.834888223904244,
    -73.665111776095742, 50.794578419292378, -79.6054215807076,
    68.165111776095742, -60.834888223904244 },

  // Variable: thruster_dist2CG_BLUE
  //  Referenced by:
  //    '<S240>/MATLAB Function5'
  //    '<S243>/MATLAB Function'

  { 84.3010033444816, -53.698996655518386, 79.980637211758491,
    -61.519362788241494, 53.698996655518386, -76.7010033444816,
    56.019362788241487, -72.9806372117585 },

  // Variable: thruster_dist2CG_RED
  //  Referenced by:
  //    '<S252>/MATLAB Function5'
  //    '<S255>/MATLAB Function'

  { 64.335708595202249, -67.664291404797723, 93.129636186598191,
    -51.370363813401788, 70.664291404797723, -63.335708595202256,
    43.870363813401781, -85.629636186598219 },

  // Variable: xLength
  //  Referenced by:
  //    '<S42>/Desired X-Position (BLACK)'
  //    '<S37>/Constant1'
  //    '<S48>/Constant1'
  //    '<S56>/Constant1'
  //    '<S68>/Constant1'

  3.51155,

  // Variable: yLength
  //  Referenced by:
  //    '<S42>/Desired Y-Position (BLACK)'
  //    '<S37>/Constant2'
  //    '<S48>/Constant2'
  //    '<S56>/Constant2'
  //    '<S68>/Constant2'

  2.41935,

  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S155>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevScale
  //  Referenced by: '<S156>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevScale
  //  Referenced by: '<S157>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_i
  //  Referenced by: '<S132>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_e
  //  Referenced by: '<S133>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_o
  //  Referenced by: '<S134>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_p
  //  Referenced by: '<S145>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_m
  //  Referenced by: '<S146>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_a
  //  Referenced by: '<S147>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_d
  //  Referenced by: '<S122>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_i
  //  Referenced by: '<S123>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevSc_oo
  //  Referenced by: '<S124>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevSca_pf
  //  Referenced by: '<S150>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_l
  //  Referenced by: '<S151>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevSc_on
  //  Referenced by: '<S152>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_n
  //  Referenced by: '<S127>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_f
  //  Referenced by: '<S128>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_g
  //  Referenced by: '<S129>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_j
  //  Referenced by: '<S141>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_a
  //  Referenced by: '<S142>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_k
  //  Referenced by: '<S143>/UD'

  0.0,

  // Mask Parameter: MATLABFunction5_max_iters
  //  Referenced by: '<S228>/MATLAB Function5'

  1.0,

  // Mask Parameter: MATLABFunction5_max_iters_c
  //  Referenced by: '<S240>/MATLAB Function5'

  1.0,

  // Mask Parameter: MATLABFunction5_max_iters_e
  //  Referenced by: '<S252>/MATLAB Function5'

  1.0,

  // Mask Parameter: MATLABFunction5_tol
  //  Referenced by: '<S228>/MATLAB Function5'

  0.001,

  // Mask Parameter: MATLABFunction5_tol_m
  //  Referenced by: '<S240>/MATLAB Function5'

  0.001,

  // Mask Parameter: MATLABFunction5_tol_g
  //  Referenced by: '<S252>/MATLAB Function5'

  0.001,

  // Expression: 0
  //  Referenced by: '<S20>/Constant11'

  0.0,

  // Expression: 0
  //  Referenced by: '<S20>/Constant12'

  0.0,

  // Expression: 0
  //  Referenced by: '<S20>/Constant14'

  0.0,

  // Expression: 0
  //  Referenced by: '<S20>/Constant15'

  0.0,

  // Expression: 0
  //  Referenced by: '<S20>/Constant18'

  0.0,

  // Expression: 2
  //  Referenced by: '<S20>/Constant4'

  2.0,

  // Expression: 2
  //  Referenced by: '<S20>/Constant5'

  2.0,

  // Expression: 1
  //  Referenced by: '<S20>/Constant6'

  1.0,

  // Expression: 2
  //  Referenced by: '<S20>/Constant8'

  2.0,

  // Expression: pi/2
  //  Referenced by: '<S25>/Constant3'

  1.5707963267948966,

  // Expression: pi/2
  //  Referenced by: '<S25>/Constant1'

  1.5707963267948966,

  // Expression: 0
  //  Referenced by: '<S25>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S29>/Constant11'

  0.0,

  // Expression: 0
  //  Referenced by: '<S29>/Constant12'

  0.0,

  // Expression: 0
  //  Referenced by: '<S29>/Constant14'

  0.0,

  // Expression: 0
  //  Referenced by: '<S29>/Constant15'

  0.0,

  // Expression: 0
  //  Referenced by: '<S29>/Constant18'

  0.0,

  // Expression: 2
  //  Referenced by: '<S29>/Constant4'

  2.0,

  // Expression: 2
  //  Referenced by: '<S29>/Constant5'

  2.0,

  // Expression: 1
  //  Referenced by: '<S29>/Constant6'

  1.0,

  // Expression: 2
  //  Referenced by: '<S29>/Constant8'

  2.0,

  // Expression: pi/2
  //  Referenced by: '<S33>/Constant3'

  1.5707963267948966,

  // Expression: pi/2
  //  Referenced by: '<S33>/Constant1'

  1.5707963267948966,

  // Expression: 0
  //  Referenced by: '<S33>/Constant2'

  0.0,

  // Expression: 0.03490659
  //  Referenced by: '<S35>/Desired Rate '

  0.03490659,

  // Expression: -0.85
  //  Referenced by: '<S37>/Gain'

  -0.85,

  // Expression: -0.85
  //  Referenced by: '<S37>/Gain1'

  -0.85,

  // Expression: 0.75
  //  Referenced by: '<S34>/Signal Generator'

  0.75,

  // Expression: 1/60
  //  Referenced by: '<S34>/Signal Generator'

  0.016666666666666666,

  // Expression: 0
  //  Referenced by: '<S30>/Constant11'

  0.0,

  // Expression: 0
  //  Referenced by: '<S30>/Constant12'

  0.0,

  // Expression: 0
  //  Referenced by: '<S30>/Constant14'

  0.0,

  // Expression: 0
  //  Referenced by: '<S30>/Constant15'

  0.0,

  // Expression: 0
  //  Referenced by: '<S30>/Constant18'

  0.0,

  // Expression: 2
  //  Referenced by: '<S30>/Constant4'

  2.0,

  // Expression: 2
  //  Referenced by: '<S30>/Constant5'

  2.0,

  // Expression: 1
  //  Referenced by: '<S30>/Constant6'

  1.0,

  // Expression: 2
  //  Referenced by: '<S30>/Constant8'

  2.0,

  // Expression: pi/2
  //  Referenced by: '<S41>/Constant3'

  1.5707963267948966,

  // Expression: pi/2
  //  Referenced by: '<S41>/Constant1'

  1.5707963267948966,

  // Expression: 0
  //  Referenced by: '<S41>/Constant2'

  0.0,

  // Expression: 0.03490659
  //  Referenced by: '<S43>/Desired Rate '

  0.03490659,

  // Expression: -0.85
  //  Referenced by: '<S48>/Gain'

  -0.85,

  // Expression: -0.85
  //  Referenced by: '<S48>/Gain1'

  -0.85,

  // Expression: 4*pi/120
  //  Referenced by: '<S45>/Desired Rate (BLACK)'

  0.10471975511965977,

  // Expression: 0
  //  Referenced by: '<S31>/Constant11'

  0.0,

  // Expression: 0
  //  Referenced by: '<S31>/Constant12'

  0.0,

  // Expression: 0
  //  Referenced by: '<S31>/Constant14'

  0.0,

  // Expression: 0
  //  Referenced by: '<S31>/Constant15'

  0.0,

  // Expression: 0
  //  Referenced by: '<S31>/Constant18'

  0.0,

  // Expression: 2
  //  Referenced by: '<S31>/Constant4'

  2.0,

  // Expression: 2
  //  Referenced by: '<S31>/Constant5'

  2.0,

  // Expression: 1
  //  Referenced by: '<S31>/Constant6'

  1.0,

  // Expression: 2
  //  Referenced by: '<S31>/Constant8'

  2.0,

  // Expression: pi/2
  //  Referenced by: '<S52>/Constant3'

  1.5707963267948966,

  // Expression: pi/2
  //  Referenced by: '<S52>/Constant1'

  1.5707963267948966,

  // Expression: 0
  //  Referenced by: '<S52>/Constant2'

  0.0,

  // Expression: 0.03490659
  //  Referenced by: '<S53>/Desired Rate '

  0.03490659,

  // Expression: -0.85
  //  Referenced by: '<S56>/Gain'

  -0.85,

  // Expression: -0.85
  //  Referenced by: '<S56>/Gain1'

  -0.85,

  // Expression: 4*pi/120
  //  Referenced by: '<S60>/Desired Rate (BLACK)'

  0.10471975511965977,

  // Expression: 0
  //  Referenced by: '<S32>/Constant11'

  0.0,

  // Expression: 0
  //  Referenced by: '<S32>/Constant12'

  0.0,

  // Expression: 0
  //  Referenced by: '<S32>/Constant14'

  0.0,

  // Expression: 0
  //  Referenced by: '<S32>/Constant15'

  0.0,

  // Expression: 0
  //  Referenced by: '<S32>/Constant18'

  0.0,

  // Expression: 2
  //  Referenced by: '<S32>/Constant4'

  2.0,

  // Expression: 2
  //  Referenced by: '<S32>/Constant5'

  2.0,

  // Expression: 1
  //  Referenced by: '<S32>/Constant6'

  1.0,

  // Expression: 2
  //  Referenced by: '<S32>/Constant8'

  2.0,

  // Expression: 0
  //  Referenced by: '<S64>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S64>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S64>/Constant2'

  0.0,

  // Expression: 0.03490659
  //  Referenced by: '<S66>/Desired Rate '

  0.03490659,

  // Expression: -0.85
  //  Referenced by: '<S68>/Gain'

  -0.85,

  // Expression: -0.85
  //  Referenced by: '<S68>/Gain1'

  -0.85,

  // Expression: 0
  //  Referenced by: '<S24>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S24>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S24>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S24>/Constant4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S24>/Constant5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S24>/Constant6'

  0.0,

  // Expression: 0
  //  Referenced by: '<S24>/Constant7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S24>/Constant8'

  0.0,

  // Expression: 0
  //  Referenced by: '<S24>/Puck State'

  0.0,

  // Expression: 200
  //  Referenced by: '<S85>/Angular Gain'

  200.0,

  // Expression: 200
  //  Referenced by: '<S85>/Attractive Gain'

  200.0,

  // Expression: 1
  //  Referenced by: '<S85>/Influence Range'

  1.0,

  // Expression: 5
  //  Referenced by: '<S85>/Repulsive Gain'

  5.0,

  // Expression: 200
  //  Referenced by: '<S84>/Angular Gain'

  200.0,

  // Expression: 200
  //  Referenced by: '<S84>/Attractive Gain'

  200.0,

  // Expression: 1
  //  Referenced by: '<S84>/Influence Range'

  1.0,

  // Expression: 5
  //  Referenced by: '<S84>/Repulsive Gain'

  5.0,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S155>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_f
  //  Referenced by: '<S156>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_c
  //  Referenced by: '<S157>/TSamp'

  20.0,

  // Expression: -1
  //  Referenced by: '<S116>/Gain6'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S116>/Gain7'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S116>/Gain8'

  -1.0,

  // Computed Parameter: TSamp_WtEt_h
  //  Referenced by: '<S132>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_e
  //  Referenced by: '<S133>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_n
  //  Referenced by: '<S134>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_i
  //  Referenced by: '<S145>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_hr
  //  Referenced by: '<S146>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_ca
  //  Referenced by: '<S147>/TSamp'

  20.0,

  // Expression: -1
  //  Referenced by: '<S114>/Gain6'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S114>/Gain7'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S114>/Gain8'

  -1.0,

  // Computed Parameter: TSamp_WtEt_nd
  //  Referenced by: '<S122>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_co
  //  Referenced by: '<S123>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_no
  //  Referenced by: '<S124>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_p
  //  Referenced by: '<S150>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_o
  //  Referenced by: '<S151>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_px
  //  Referenced by: '<S152>/TSamp'

  20.0,

  // Expression: -1
  //  Referenced by: '<S115>/Gain6'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S115>/Gain7'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S115>/Gain8'

  -1.0,

  // Computed Parameter: TSamp_WtEt_ft
  //  Referenced by: '<S127>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_eh
  //  Referenced by: '<S128>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_ii
  //  Referenced by: '<S129>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_pu
  //  Referenced by: '<S141>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_f0
  //  Referenced by: '<S142>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_nz
  //  Referenced by: '<S143>/TSamp'

  20.0,

  // Expression: 1
  //  Referenced by: '<S113>/Constant7'

  1.0,

  // Computed Parameter: Merge3_InitialOutput
  //  Referenced by: '<S113>/Merge3'

  0.0,

  // Computed Parameter: Merge4_InitialOutput
  //  Referenced by: '<S113>/Merge4'

  0.0,

  // Computed Parameter: Merge5_InitialOutput
  //  Referenced by: '<S113>/Merge5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S117>/Constant7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S117>/Zero'

  0.0,

  // Expression: 428
  //  Referenced by: '<S167>/GPIO Write1'

  428.0,

  // Expression: 1
  //  Referenced by: '<S167>/GPIO Write1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S168>/Gyroscope//Accelerometer'

  -1.0,

  // Expression: 0.0
  //  Referenced by: '<S170>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S170>/Delay1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S170>/Delay2'

  0.0,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S179>/Out1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S179>/Memory'

  0.0,

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S180>/Out1'

  0.0,

  // Computed Parameter: dytdt_Y0
  //  Referenced by: '<S186>/dy(t)//dt'

  0.0,

  // Computed Parameter: dytdt_Y0_j
  //  Referenced by: '<S196>/dy(t)//dt'

  0.0,

  // Computed Parameter: dytdt_Y0_d
  //  Referenced by: '<S206>/dy(t)//dt'

  0.0,

  // Expression: 1/1000
  //  Referenced by: '<S174>/Convert BLAX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S174>/Convert BLAY from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S174>/Convert BLACKVX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S174>/Convert BLACKVY from [mm] to [m]'

  0.001,

  // Expression: 0
  //  Referenced by: '<S182>/Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S182>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S182>/Constant3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S184>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S184>/Constant3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S183>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S183>/Constant3'

  0.0,

  // Expression: 1/1000
  //  Referenced by: '<S175>/Convert BLUX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S175>/Convert BLUY from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S175>/Convert BLUEVX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S175>/Convert BLUEVY from [mm] to [m]'

  0.001,

  // Expression: 0
  //  Referenced by: '<S192>/Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S192>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S192>/Constant3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S194>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S194>/Constant3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S193>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S193>/Constant3'

  0.0,

  // Expression: 1/1000
  //  Referenced by: '<S176>/Convert REDX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S176>/Convert REDY from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S176>/Convert REDVX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S176>/Convert REDVY from [mm] to [m]'

  0.001,

  // Expression: 0
  //  Referenced by: '<S202>/Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S202>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S202>/Constant3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S204>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S204>/Constant3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S203>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S203>/Constant3'

  0.0,

  // Expression: 1
  //  Referenced by: '<S177>/Constant'

  1.0,

  // Expression: 400
  //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  400.0,

  // Expression: 0
  //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.0,

  // Expression: 200
  //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  200.0,

  // Expression: 3072
  //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  3072.0,

  // Expression: 1024
  //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  1024.0,

  // Expression: 0
  //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.0,

  // Expression: 850
  //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  850.0,

  // Expression: 400
  //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  400.0,

  // Expression: 100
  //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  100.0,

  // Expression: 50
  //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  50.0,

  // Expression: 0
  //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.0,

  // Computed Parameter: Out1_Y0_f
  //  Referenced by: '<S235>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_j
  //  Referenced by: '<S236>/Out1'

  0.0,

  // Computed Parameter: BLACKDC_Y0
  //  Referenced by: '<S225>/BLACK DC'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S230>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S230>/Constant2'

  0.0,

  // Computed Parameter: Out1_Y0_n
  //  Referenced by: '<S247>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_js
  //  Referenced by: '<S248>/Out1'

  0.0,

  // Computed Parameter: BLUEDC_Y0
  //  Referenced by: '<S226>/BLUE DC'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S242>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S242>/Constant2'

  0.0,

  // Computed Parameter: Out1_Y0_c
  //  Referenced by: '<S259>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S260>/Out1'

  0.0,

  // Computed Parameter: REDDC_Y0
  //  Referenced by: '<S227>/RED DC'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S254>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S254>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz4'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz5'

  0.0,

  // Expression: [0;0;0;0;0;0;0;0;0]
  //  Referenced by: '<Root>/Universal_Time1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0;0;0;0;0;0;0;0;0]
  //  Referenced by: '<Root>/Universal_Time12'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0;0;0;0;0;0;0;0;0]
  //  Referenced by: '<Root>/Universal_Time2'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0;0;0;0;0;0]
  //  Referenced by: '<Root>/Universal_Time7'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Computed Parameter: Merge1_InitialOutput
  //  Referenced by: '<S3>/Merge1'

  0.0,

  // Computed Parameter: Merge2_InitialOutput
  //  Referenced by: '<S3>/Merge2'

  0.0,

  // Computed Parameter: Merge_InitialOutput
  //  Referenced by: '<S3>/Merge'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S217>/Delay1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S217>/Delay'

  0.0,

  // Expression: [1; zeros(12,1)]
  //  Referenced by: '<S218>/Delay2'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0.2*eye(12)
  //  Referenced by: '<S218>/Delay1'

  { 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2 },

  // Expression: 0*eye(6)
  //  Referenced by: '<S218>/Delay3'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 568471
  //  Referenced by: '<S17>/Safety Number'

  568471.0,

  // Expression: 100
  //  Referenced by: '<S17>/Gain'

  100.0,

  // Expression: 100
  //  Referenced by: '<S17>/Gain1'

  100.0,

  // Expression: 100
  //  Referenced by: '<S17>/Gain2'

  100.0,

  // Expression: 100
  //  Referenced by: '<S17>/Gain3'

  100.0,

  // Expression: 100
  //  Referenced by: '<S17>/Gain4'

  100.0,

  // Expression: 100
  //  Referenced by: '<S17>/Gain5'

  100.0,

  // Expression: 100
  //  Referenced by: '<S17>/Gain6'

  100.0,

  // Expression: 100
  //  Referenced by: '<S17>/Gain7'

  100.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz1'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz15'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz2'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz20'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz25'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz37'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz38'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz7'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz8'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz9'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time'

  0.0,

  // Expression: [0;0;0;0;0;0;0;0;0]
  //  Referenced by: '<Root>/Universal_Time10'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time11'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time13'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time14'

  0.0,

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time15'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time16'

  0.0,

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time17'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time18'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time19'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time20'

  0.0,

  // Expression: [1;0;0;0;0;0;0]
  //  Referenced by: '<Root>/Universal_Time21'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [1;0;0;0;0;0;0]
  //  Referenced by: '<Root>/Universal_Time22'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0]
  //  Referenced by: '<Root>/Universal_Time23'

  0.0,

  // Expression: [0;0;0;0;0;0]
  //  Referenced by: '<Root>/Universal_Time24'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time25'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0;0;0;0;0;0;0]
  //  Referenced by: '<Root>/Universal_Time26'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time27'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time28'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time29'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time3'

  0.0,

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time30'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time31'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time32'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time33'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time34'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time35'

  { 0.0, 0.0, 0.0 },

  // Expression: [1;0;0;0;0;0;0;0;0;0;0;0;0]
  //  Referenced by: '<Root>/Universal_Time36'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0]
  //  Referenced by: '<Root>/Universal_Time37'

  0.0,

  // Expression: [0]
  //  Referenced by: '<Root>/Universal_Time38'

  0.0,

  // Expression: [0;0;0;0;0;0;0;0;0]
  //  Referenced by: '<Root>/Universal_Time4'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time5'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time6'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time8'

  { 0.0, 0.0, 0.0 },

  // Expression: [1;0;0;0;0;0;0]
  //  Referenced by: '<Root>/Universal_Time9'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: "Target: Hello"
  //  Referenced by: '<S164>/String Constant1'

  "Target: Hello",

  // Expression: "Obstacle: Hello"
  //  Referenced by: '<S165>/String Constant2'

  "Obstacle: Hello",

  // Computed Parameter: RED_Tz3_InitialValue
  //  Referenced by: '<Root>/RED_Tz3'

  "",

  // Computed Parameter: UDPSend1_Port
  //  Referenced by: '<S164>/UDP Send1'

  55000,

  // Computed Parameter: UDPSend2_Port
  //  Referenced by: '<S165>/UDP Send2'

  55000,

  // Computed Parameter: UDPSend3_Port
  //  Referenced by: '<S166>/UDP Send3'

  55000,

  // Computed Parameter: ReceivePhaseSpaceData_Port
  //  Referenced by: '<S173>/Receive PhaseSpace Data'

  31534,

  // Computed Parameter: Delay_InitialCondition_j
  //  Referenced by: '<S178>/Delay'

  0,

  // Computed Parameter: Delay1_InitialCondition_d
  //  Referenced by: '<S178>/Delay1'

  0,

  // Computed Parameter: Delay2_InitialCondition_ak
  //  Referenced by: '<S178>/Delay2'

  0,

  // Computed Parameter: UDPReceive_Port
  //  Referenced by: '<S178>/UDP Receive'

  33001,

  // Computed Parameter: UDPReceive2_Port
  //  Referenced by: '<S178>/UDP Receive2'

  33002,

  // Computed Parameter: UDPReceive3_Port
  //  Referenced by: '<S178>/UDP Receive3'

  33003,

  // Computed Parameter: UDPReceive1_Port
  //  Referenced by: '<S213>/UDP Receive1'

  30172,

  // Computed Parameter: UDPSend_Port
  //  Referenced by: '<S224>/UDP Send'

  46875,

  // Computed Parameter: UDPSend_Port_h
  //  Referenced by: '<S17>/UDP Send'

  48291,

  // Start of '<S204>/Enabled Subsystem'
  {
    // Computed Parameter: dydt_Y0
    //  Referenced by: '<S210>/dy//dt'

    0.0,

    // Expression: 0.1
    //  Referenced by: '<S210>/Constant2'

    0.1,

    // Expression: 0.0
    //  Referenced by: '<S210>/Delay1'

    0.0
  }
  ,

  // End of '<S204>/Enabled Subsystem'

  // Start of '<S203>/Enabled Subsystem'
  {
    // Computed Parameter: dydt_Y0
    //  Referenced by: '<S208>/dy//dt'

    0.0,

    // Expression: 0.1
    //  Referenced by: '<S208>/Constant2'

    0.1,

    // Expression: 0.0
    //  Referenced by: '<S208>/Delay1'

    0.0
  }
  ,

  // End of '<S203>/Enabled Subsystem'

  // Start of '<S194>/Enabled Subsystem'
  {
    // Computed Parameter: dydt_Y0
    //  Referenced by: '<S200>/dy//dt'

    0.0,

    // Expression: 0.1
    //  Referenced by: '<S200>/Constant2'

    0.1,

    // Expression: 0.0
    //  Referenced by: '<S200>/Delay1'

    0.0
  }
  ,

  // End of '<S194>/Enabled Subsystem'

  // Start of '<S193>/Enabled Subsystem'
  {
    // Computed Parameter: dydt_Y0
    //  Referenced by: '<S198>/dy//dt'

    0.0,

    // Expression: 0.1
    //  Referenced by: '<S198>/Constant2'

    0.1,

    // Expression: 0.0
    //  Referenced by: '<S198>/Delay1'

    0.0
  }
  ,

  // End of '<S193>/Enabled Subsystem'

  // Start of '<S184>/Enabled Subsystem'
  {
    // Computed Parameter: dydt_Y0
    //  Referenced by: '<S190>/dy//dt'

    0.0,

    // Expression: 0.1
    //  Referenced by: '<S190>/Constant2'

    0.1,

    // Expression: 0.0
    //  Referenced by: '<S190>/Delay1'

    0.0
  }
  ,

  // End of '<S184>/Enabled Subsystem'

  // Start of '<S183>/Enabled Subsystem'
  {
    // Computed Parameter: dydt_Y0
    //  Referenced by: '<S188>/dy//dt'

    0.0,

    // Expression: 0.1
    //  Referenced by: '<S188>/Constant2'

    0.1,

    // Expression: 0.0
    //  Referenced by: '<S188>/Delay1'

    0.0
  }
  ,

  // End of '<S183>/Enabled Subsystem'

  // Start of '<S4>/Change RED Behavior'
  {
    // Computed Parameter: Constant1_Value
    //  Referenced by: '<S161>/Constant1'

    1,

    // Computed Parameter: UDPSend_Port
    //  Referenced by: '<S161>/UDP Send'

    33001
  }
  ,

  // End of '<S4>/Change RED Behavior'

  // Start of '<S4>/Change BLUE Behavior'
  {
    // Computed Parameter: Constant1_Value
    //  Referenced by: '<S160>/Constant1'

    1,

    // Computed Parameter: UDPSend_Port
    //  Referenced by: '<S160>/UDP Send'

    33003
  }
  ,

  // End of '<S4>/Change BLUE Behavior'

  // Start of '<S4>/Change BLACK Behavior'
  {
    // Computed Parameter: Constant1_Value
    //  Referenced by: '<S159>/Constant1'

    1,

    // Computed Parameter: UDPSend_Port
    //  Referenced by: '<S159>/UDP Send'

    33002
  }
  ,

  // End of '<S4>/Change BLACK Behavior'

  // Start of '<S3>/Custom Control (ARM)'
  {
    // Expression: 0
    //  Referenced by: '<S108>/Zero'

    0.0
  }
  ,

  // End of '<S3>/Custom Control (ARM)'

  // Start of '<S3>/Disable Thrusters (BLUE)'
  {
    // Expression: 0
    //  Referenced by: '<S119>/Zero'

    0.0
  }
  ,

  // End of '<S3>/Disable Thrusters (BLUE)'

  // Start of '<S3>/Disable Thrusters (BLACK)'
  {
    // Expression: 0
    //  Referenced by: '<S118>/Zero'

    0.0
  }
  ,

  // End of '<S3>/Disable Thrusters (BLACK)'

  // Start of '<S3>/Disable Thrusters (RED)'
  {
    // Expression: 0
    //  Referenced by: '<S120>/Zero'

    0.0
  }
  ,

  // End of '<S3>/Disable Thrusters (RED)'

  // Start of '<S3>/Custom Control (RED)'
  {
    // Expression: 0
    //  Referenced by: '<S109>/Zero'

    0.0
  }
  ,

  // End of '<S3>/Custom Control (RED)'

  // Start of '<S1>/Phase #5: Hold Home'
  {
    // Expression: 0
    //  Referenced by: '<S23>/Constant11'

    0.0,

    // Expression: 0
    //  Referenced by: '<S23>/Constant12'

    0.0,

    // Expression: 0
    //  Referenced by: '<S23>/Constant14'

    0.0,

    // Expression: 0
    //  Referenced by: '<S23>/Constant15'

    0.0,

    // Expression: 0
    //  Referenced by: '<S23>/Constant18'

    0.0,

    // Expression: 2
    //  Referenced by: '<S23>/Constant4'

    2.0,

    // Expression: 2
    //  Referenced by: '<S23>/Constant5'

    2.0,

    // Expression: 1
    //  Referenced by: '<S23>/Constant6'

    1.0,

    // Expression: 2
    //  Referenced by: '<S23>/Constant8'

    2.0,

    // Expression: pi/2
    //  Referenced by: '<S76>/Constant3'

    1.5707963267948966,

    // Expression: pi/2
    //  Referenced by: '<S76>/Constant1'

    1.5707963267948966,

    // Expression: 0
    //  Referenced by: '<S76>/Constant2'

    0.0
  }
  ,

  // End of '<S1>/Phase #5: Hold Home'

  // Start of '<S1>/Phase #4: Return Home'
  {
    // Expression: 0
    //  Referenced by: '<S22>/Constant11'

    0.0,

    // Expression: 0
    //  Referenced by: '<S22>/Constant12'

    0.0,

    // Expression: 0
    //  Referenced by: '<S22>/Constant14'

    0.0,

    // Expression: 0
    //  Referenced by: '<S22>/Constant15'

    0.0,

    // Expression: 0
    //  Referenced by: '<S22>/Constant18'

    0.0,

    // Expression: 2
    //  Referenced by: '<S22>/Constant4'

    2.0,

    // Expression: 2
    //  Referenced by: '<S22>/Constant5'

    2.0,

    // Expression: 1
    //  Referenced by: '<S22>/Constant6'

    1.0,

    // Expression: 2
    //  Referenced by: '<S22>/Constant8'

    2.0,

    // Expression: pi/2
    //  Referenced by: '<S72>/Constant3'

    1.5707963267948966,

    // Expression: pi/2
    //  Referenced by: '<S72>/Constant1'

    1.5707963267948966,

    // Expression: 0
    //  Referenced by: '<S72>/Constant2'

    0.0
  }
  ,

  // End of '<S1>/Phase #4: Return Home'

  // Start of '<S1>/Phase #1: Start Floating '
  {
    // Expression: 0
    //  Referenced by: '<S19>/Constant1'

    0.0,

    // Expression: 0
    //  Referenced by: '<S19>/Constant2'

    0.0,

    // Expression: 0
    //  Referenced by: '<S19>/Constant3'

    0.0,

    // Expression: 0
    //  Referenced by: '<S19>/Constant4'

    0.0,

    // Expression: 0
    //  Referenced by: '<S19>/Constant5'

    0.0,

    // Expression: 0
    //  Referenced by: '<S19>/Constant6'

    0.0,

    // Expression: 0
    //  Referenced by: '<S19>/Constant7'

    0.0,

    // Expression: 0
    //  Referenced by: '<S19>/Constant8'

    0.0,

    // Expression: 1
    //  Referenced by: '<S19>/Puck State'

    1.0,

    // Expression: "Chaser: Running Phase 1"
    //  Referenced by: '<S19>/String Constant'

    "Chaser: Running Phase 1"
  }
  ,

  // End of '<S1>/Phase #1: Start Floating '

  // Start of '<S1>/Phase #0: Synchronization'
  {
    // Expression: 0
    //  Referenced by: '<S18>/Constant1'

    0.0,

    // Expression: 0
    //  Referenced by: '<S18>/Constant2'

    0.0,

    // Expression: 0
    //  Referenced by: '<S18>/Constant3'

    0.0,

    // Expression: 0
    //  Referenced by: '<S18>/Constant4'

    0.0,

    // Expression: 0
    //  Referenced by: '<S18>/Constant5'

    0.0,

    // Expression: 0
    //  Referenced by: '<S18>/Constant6'

    0.0,

    // Expression: 0
    //  Referenced by: '<S18>/Constant7'

    0.0,

    // Expression: 0
    //  Referenced by: '<S18>/Constant8'

    0.0,

    // Expression: 0
    //  Referenced by: '<S18>/Puck State'

    0.0,

    // Expression: "Chaser: Running Phase 0"
    //  Referenced by: '<S18>/String Constant'

    "Chaser: Running Phase 0"
  }
  // End of '<S1>/Phase #0: Synchronization'
};

//
// File trailer for generated code.
//
// [EOF]
//
