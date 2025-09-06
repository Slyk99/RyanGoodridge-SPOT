//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Fullexp_data.cpp
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

// Block parameters (default storage)
P_Fullexp_T Fullexp_P = {
  // Variable: F_black_X_nominal
  //  Referenced by: '<S236>/MATLAB Function5'

  0.2825,

  // Variable: F_black_Y_nominal
  //  Referenced by: '<S236>/MATLAB Function5'

  0.2825,

  // Variable: F_blue_X_nominal
  //  Referenced by: '<S248>/MATLAB Function5'

  0.2825,

  // Variable: F_blue_Y_nominal
  //  Referenced by: '<S248>/MATLAB Function5'

  0.2825,

  // Variable: F_red_X_nominal
  //  Referenced by: '<S260>/MATLAB Function5'

  0.2825,

  // Variable: F_red_Y_nominal
  //  Referenced by: '<S260>/MATLAB Function5'

  0.2825,

  // Variable: F_thrusters_BLACK
  //  Referenced by: '<S239>/MATLAB Function'

  { 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825 },

  // Variable: F_thrusters_BLUE
  //  Referenced by: '<S251>/MATLAB Function'

  { 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825 },

  // Variable: F_thrusters_RED
  //  Referenced by: '<S263>/MATLAB Function'

  { 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825 },

  // Variable: K_BLACK
  //  Referenced by: '<S119>/Constant2'

  { 2.7844260657770121, -2.0916601783937949E-13, 1.1983819127218421E-14,
    -1.0633570757396355E-13, 2.7844260657771169, 2.4393327651452324E-14,
    -2.6581021571831372E-14, -3.8493723536320054E-16, 1.0501640787731181,
    8.0513293077522583, -4.5095027697002723E-13, 1.1911026046120391E-14,
    -2.9790830726359336E-14, 8.0513293077526171, 7.7175752314139672E-14,
    -1.0492303740862294E-14, 4.4091456409580755E-16, 0.72762437215538911 },

  // Variable: K_BLUE
  //  Referenced by: '<S120>/Constant2'

  { 0.40218238973674775, 1.683962826555525E-15, 7.5785945510315839E-15,
    3.9111419922025071E-15, 0.40218238973675713, 6.6736196360470178E-15,
    4.9400995945260145E-16, 4.4420114922023327E-16, 0.081407426263066282,
    3.2133409169777383, 5.46229728115577E-14, 7.5629359369335219E-14,
    4.34773196942792E-15, 3.213340916977828, 8.08249183037409E-14,
    2.74871748743334E-16, 1.4383159062603373E-16, 0.40554915553132154 },

  // Variable: K_RED
  //  Referenced by: '<S121>/Constant2'

  { 0.40232877970259667, -2.0263012511229824E-14, -8.4051443133328233E-16,
    5.8702555000223288E-16, 0.40232877970262537, -5.6425539336462471E-15,
    -6.41430742891448E-16, 1.1731704775391289E-15, 0.08149590638118985,
    3.2724457090025347, -1.3522860420014287E-13, 1.7987277018860464E-14,
    4.2362751675083559E-14, 3.2724457090028443, -3.58115642612403E-14,
    5.2160424216070551E-17, 5.5541095421028447E-16, 0.40636232022479724 },

  // Variable: Kd_elarm
  //  Referenced by: '<S147>/kd_elarm'

  0.8,

  // Variable: Kd_sharm
  //  Referenced by: '<S148>/kd_sharm'

  1.0,

  // Variable: Kd_tb
  //  Referenced by: '<S123>/Gain5'

  1.8,

  // Variable: Kd_tblue
  //  Referenced by: '<S124>/Gain5'

  1.8,

  // Variable: Kd_tr
  //  Referenced by: '<S125>/Gain5'

  1.8,

  // Variable: Kd_wrarm
  //  Referenced by: '<S149>/kd_wrarm'

  0.6,

  // Variable: Kd_xb
  //  Referenced by: '<S123>/Gain3'

  3.6,

  // Variable: Kd_xblue
  //  Referenced by: '<S124>/Gain3'

  3.6,

  // Variable: Kd_xr
  //  Referenced by: '<S125>/Gain3'

  3.6,

  // Variable: Kd_yb
  //  Referenced by: '<S123>/Gain4'

  3.6,

  // Variable: Kd_yblue
  //  Referenced by: '<S124>/Gain4'

  3.6,

  // Variable: Kd_yr
  //  Referenced by: '<S125>/Gain4'

  3.6,

  // Variable: Kp_elarm
  //  Referenced by: '<S147>/kp_elarm'

  1.2,

  // Variable: Kp_sharm
  //  Referenced by: '<S148>/kp_sharm'

  1.5,

  // Variable: Kp_tb
  //  Referenced by: '<S123>/Gain2'

  0.5,

  // Variable: Kp_tblue
  //  Referenced by: '<S124>/Gain2'

  0.5,

  // Variable: Kp_tr
  //  Referenced by: '<S125>/Gain2'

  0.5,

  // Variable: Kp_wrarm
  //  Referenced by: '<S149>/kp_wrarm'

  1.0,

  // Variable: Kp_xb
  //  Referenced by: '<S123>/Gain'

  1.0,

  // Variable: Kp_xblue
  //  Referenced by: '<S124>/Gain'

  1.0,

  // Variable: Kp_xr
  //  Referenced by: '<S125>/Gain'

  1.0,

  // Variable: Kp_yb
  //  Referenced by: '<S123>/Gain1'

  1.0,

  // Variable: Kp_yblue
  //  Referenced by: '<S124>/Gain1'

  1.0,

  // Variable: Kp_yr
  //  Referenced by: '<S125>/Gain1'

  1.0,

  // Variable: P
  //  Referenced by:
  //    '<S5>/Delay'
  //    '<S16>/Delay'
  //    '<S17>/Delay'
  //    '<S22>/Delay'
  //    '<S23>/Delay'

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

  // Variable: PWMFreq
  //  Referenced by:
  //    '<S26>/PWM Frequency'
  //    '<S236>/MATLAB Function1'
  //    '<S248>/MATLAB Function1'
  //    '<S260>/MATLAB Function8'
  //    '<S238>/Constant1'
  //    '<S250>/Constant1'
  //    '<S262>/Constant1'

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
  //    '<S47>/Constant2'
  //    '<S58>/Constant2'
  //    '<S66>/Constant2'
  //    '<S78>/Constant2'
  //    '<S56>/Constant1'
  //    '<S72>/Constant1'

  45.0,

  // Variable: Phase3_End
  //  Referenced by: '<S1>/Constant2'

  135.0,

  // Variable: Phase3_SubPhase1_End
  //  Referenced by: '<S30>/Constant4'

  45.0,

  // Variable: Phase3_SubPhase2_End
  //  Referenced by:
  //    '<S30>/Constant1'
  //    '<S64>/Constant'

  45.0,

  // Variable: Phase3_SubPhase3_End
  //  Referenced by: '<S30>/Constant2'

  105.0,

  // Variable: Phase3_SubPhase4_End
  //  Referenced by: '<S30>/Constant3'

  135.0,

  // Variable: Phase4_End
  //  Referenced by: '<S1>/Constant3'

  135.0,

  // Variable: Phase5_End
  //  Referenced by: '<S1>/Constant6'

  136.0,

  // Variable: Tz_lim_elarm
  //  Referenced by: '<S146>/Saturation1'

  0.1,

  // Variable: Tz_lim_sharm
  //  Referenced by: '<S146>/Saturation'

  0.1,

  // Variable: Tz_lim_wrarm
  //  Referenced by: '<S146>/Saturation3'

  0.1,

  // Variable: baseRate
  //  Referenced by:
  //    '<S93>/MATLAB Function'
  //    '<S94>/MATLAB Function'
  //    '<S180>/Read Joint Positions using  Dynamixel Encoders'
  //    '<S222>/WhoAmI'
  //    '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.05,

  // Variable: dataRate
  //  Referenced by:
  //    '<S192>/Constant'
  //    '<S202>/Constant'
  //    '<S212>/Constant'

  0.1,

  // Variable: home_states_BLACK
  //  Referenced by:
  //    '<S82>/Desired States (BLACK)'
  //    '<S86>/Desired States (BLACK)'
  //    '<S74>/Constant'

  { 0.4, 0.4, 0.0 },

  // Variable: home_states_BLUE
  //  Referenced by:
  //    '<S83>/Desired States (BLUE)'
  //    '<S87>/Desired States (BLUE)'

  { 0.85577500000000006, 1.209675, 0.0 },

  // Variable: home_states_RED
  //  Referenced by:
  //    '<S84>/Constant2'
  //    '<S88>/Constant2'
  //    '<S76>/Constant'

  { 2.655775, 1.209675, 3.1415926535897931 },

  // Variable: init_states_BLACK
  //  Referenced by:
  //    '<S35>/Desired States (BLACK)'
  //    '<S43>/Constant'

  { 2.0, 2.0, 0.0 },

  // Variable: init_states_BLUE
  //  Referenced by: '<S36>/Desired States (BLUE)'

  { 0.85577500000000006, 1.209675, 0.0 },

  // Variable: init_states_RED
  //  Referenced by:
  //    '<S37>/Constant2'
  //    '<S45>/Constant'
  //    '<S53>/Constant'
  //    '<S53>/Constant1'
  //    '<S53>/Constant4'
  //    '<S63>/Constant'

  { 2.655775, 1.209675, 3.1415926535897931 },

  // Variable: platformSelection
  //  Referenced by: '<S188>/MATLAB Function'

  3.0,

  // Variable: simMode
  //  Referenced by: '<S25>/Constant'

  0.0,

  // Variable: thruster_dist2CG_BLACK
  //  Referenced by:
  //    '<S236>/MATLAB Function5'
  //    '<S239>/MATLAB Function'

  { 87.2054215807076, -50.794578419292378, 67.834888223904244,
    -73.665111776095742, 50.794578419292378, -79.6054215807076,
    68.165111776095742, -60.834888223904244 },

  // Variable: thruster_dist2CG_BLUE
  //  Referenced by:
  //    '<S248>/MATLAB Function5'
  //    '<S251>/MATLAB Function'

  { 84.3010033444816, -53.698996655518386, 79.980637211758491,
    -61.519362788241494, 53.698996655518386, -76.7010033444816,
    56.019362788241487, -72.9806372117585 },

  // Variable: thruster_dist2CG_RED
  //  Referenced by:
  //    '<S260>/MATLAB Function5'
  //    '<S263>/MATLAB Function'

  { 64.335708595202249, -67.664291404797723, 93.129636186598191,
    -51.370363813401788, 70.664291404797723, -63.335708595202256,
    43.870363813401781, -85.629636186598219 },

  // Variable: xLength
  //  Referenced by:
  //    '<S51>/Desired X-Position (BLACK)'
  //    '<S46>/Constant1'
  //    '<S57>/Constant1'
  //    '<S65>/Constant1'
  //    '<S77>/Constant1'

  3.51155,

  // Variable: yLength
  //  Referenced by:
  //    '<S51>/Desired Y-Position (BLACK)'
  //    '<S46>/Constant2'
  //    '<S57>/Constant2'
  //    '<S65>/Constant2'
  //    '<S77>/Constant2'

  2.41935,

  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S164>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevScale
  //  Referenced by: '<S165>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevScale
  //  Referenced by: '<S166>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_i
  //  Referenced by: '<S141>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_e
  //  Referenced by: '<S142>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_o
  //  Referenced by: '<S143>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_p
  //  Referenced by: '<S154>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_m
  //  Referenced by: '<S155>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_a
  //  Referenced by: '<S156>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_d
  //  Referenced by: '<S131>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_i
  //  Referenced by: '<S132>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevSc_oo
  //  Referenced by: '<S133>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevSca_pf
  //  Referenced by: '<S159>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_l
  //  Referenced by: '<S160>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevSc_on
  //  Referenced by: '<S161>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_n
  //  Referenced by: '<S136>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_f
  //  Referenced by: '<S137>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_g
  //  Referenced by: '<S138>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_j
  //  Referenced by: '<S150>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_a
  //  Referenced by: '<S151>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_k
  //  Referenced by: '<S152>/UD'

  0.0,

  // Mask Parameter: MATLABFunction5_max_iters
  //  Referenced by: '<S236>/MATLAB Function5'

  1.0,

  // Mask Parameter: MATLABFunction5_max_iters_c
  //  Referenced by: '<S248>/MATLAB Function5'

  1.0,

  // Mask Parameter: MATLABFunction5_max_iters_e
  //  Referenced by: '<S260>/MATLAB Function5'

  1.0,

  // Mask Parameter: MATLABFunction5_tol
  //  Referenced by: '<S236>/MATLAB Function5'

  0.001,

  // Mask Parameter: MATLABFunction5_tol_m
  //  Referenced by: '<S248>/MATLAB Function5'

  0.001,

  // Mask Parameter: MATLABFunction5_tol_g
  //  Referenced by: '<S260>/MATLAB Function5'

  0.001,

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
  //  Referenced by: '<S34>/Constant3'

  1.5707963267948966,

  // Expression: pi/2
  //  Referenced by: '<S34>/Constant1'

  1.5707963267948966,

  // Expression: 0
  //  Referenced by: '<S34>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S38>/Constant11'

  0.0,

  // Expression: 0
  //  Referenced by: '<S38>/Constant12'

  0.0,

  // Expression: 0
  //  Referenced by: '<S38>/Constant14'

  0.0,

  // Expression: 0
  //  Referenced by: '<S38>/Constant15'

  0.0,

  // Expression: 0
  //  Referenced by: '<S38>/Constant18'

  0.0,

  // Expression: 2
  //  Referenced by: '<S38>/Constant4'

  2.0,

  // Expression: 2
  //  Referenced by: '<S38>/Constant5'

  2.0,

  // Expression: 1
  //  Referenced by: '<S38>/Constant6'

  1.0,

  // Expression: 2
  //  Referenced by: '<S38>/Constant8'

  2.0,

  // Expression: pi/2
  //  Referenced by: '<S42>/Constant3'

  1.5707963267948966,

  // Expression: pi/2
  //  Referenced by: '<S42>/Constant1'

  1.5707963267948966,

  // Expression: 0
  //  Referenced by: '<S42>/Constant2'

  0.0,

  // Expression: 0.03490659
  //  Referenced by: '<S44>/Desired Rate '

  0.03490659,

  // Expression: -0.85
  //  Referenced by: '<S46>/Gain'

  -0.85,

  // Expression: -0.85
  //  Referenced by: '<S46>/Gain1'

  -0.85,

  // Expression: 0.5
  //  Referenced by: '<S43>/Signal Generator'

  0.5,

  // Expression: 1/60
  //  Referenced by: '<S43>/Signal Generator'

  0.016666666666666666,

  // Expression: 0
  //  Referenced by: '<S39>/Constant11'

  0.0,

  // Expression: 0
  //  Referenced by: '<S39>/Constant12'

  0.0,

  // Expression: 0
  //  Referenced by: '<S39>/Constant14'

  0.0,

  // Expression: 0
  //  Referenced by: '<S39>/Constant15'

  0.0,

  // Expression: 0
  //  Referenced by: '<S39>/Constant18'

  0.0,

  // Expression: 2
  //  Referenced by: '<S39>/Constant4'

  2.0,

  // Expression: 2
  //  Referenced by: '<S39>/Constant5'

  2.0,

  // Expression: 1
  //  Referenced by: '<S39>/Constant6'

  1.0,

  // Expression: 2
  //  Referenced by: '<S39>/Constant8'

  2.0,

  // Expression: pi/2
  //  Referenced by: '<S50>/Constant3'

  1.5707963267948966,

  // Expression: pi/2
  //  Referenced by: '<S50>/Constant1'

  1.5707963267948966,

  // Expression: 0
  //  Referenced by: '<S50>/Constant2'

  0.0,

  // Expression: 0.03490659
  //  Referenced by: '<S52>/Desired Rate '

  0.03490659,

  // Expression: -0.85
  //  Referenced by: '<S57>/Gain'

  -0.85,

  // Expression: -0.85
  //  Referenced by: '<S57>/Gain1'

  -0.85,

  // Expression: 0.8*pi/120
  //  Referenced by: '<S54>/Desired Rate (BLACK)'

  0.020943951023931952,

  // Expression: 0
  //  Referenced by: '<S40>/Constant11'

  0.0,

  // Expression: 0
  //  Referenced by: '<S40>/Constant12'

  0.0,

  // Expression: 0
  //  Referenced by: '<S40>/Constant14'

  0.0,

  // Expression: 0
  //  Referenced by: '<S40>/Constant15'

  0.0,

  // Expression: 0
  //  Referenced by: '<S40>/Constant18'

  0.0,

  // Expression: 2
  //  Referenced by: '<S40>/Constant4'

  2.0,

  // Expression: 2
  //  Referenced by: '<S40>/Constant5'

  2.0,

  // Expression: 1
  //  Referenced by: '<S40>/Constant6'

  1.0,

  // Expression: 2
  //  Referenced by: '<S40>/Constant8'

  2.0,

  // Expression: pi/2
  //  Referenced by: '<S61>/Constant3'

  1.5707963267948966,

  // Expression: pi/2
  //  Referenced by: '<S61>/Constant1'

  1.5707963267948966,

  // Expression: 0
  //  Referenced by: '<S61>/Constant2'

  0.0,

  // Expression: 0.03490659
  //  Referenced by: '<S62>/Desired Rate '

  0.03490659,

  // Expression: -0.85
  //  Referenced by: '<S65>/Gain'

  -0.85,

  // Expression: -0.85
  //  Referenced by: '<S65>/Gain1'

  -0.85,

  // Expression: 4*pi/120
  //  Referenced by: '<S69>/Desired Rate (BLACK)'

  0.10471975511965977,

  // Expression: 0
  //  Referenced by: '<S41>/Constant11'

  0.0,

  // Expression: 0
  //  Referenced by: '<S41>/Constant12'

  0.0,

  // Expression: 0
  //  Referenced by: '<S41>/Constant14'

  0.0,

  // Expression: 0
  //  Referenced by: '<S41>/Constant15'

  0.0,

  // Expression: 0
  //  Referenced by: '<S41>/Constant18'

  0.0,

  // Expression: 2
  //  Referenced by: '<S41>/Constant4'

  2.0,

  // Expression: 2
  //  Referenced by: '<S41>/Constant5'

  2.0,

  // Expression: 1
  //  Referenced by: '<S41>/Constant6'

  1.0,

  // Expression: 2
  //  Referenced by: '<S41>/Constant8'

  2.0,

  // Expression: 0
  //  Referenced by: '<S73>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S73>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S73>/Constant2'

  0.0,

  // Expression: 0.03490659
  //  Referenced by: '<S75>/Desired Rate '

  0.03490659,

  // Expression: -0.85
  //  Referenced by: '<S77>/Gain'

  -0.85,

  // Expression: -0.85
  //  Referenced by: '<S77>/Gain1'

  -0.85,

  // Expression: 0
  //  Referenced by: '<S33>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Constant4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Constant5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Constant6'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Constant7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Constant8'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Puck State'

  0.0,

  // Expression: 200
  //  Referenced by: '<S94>/Angular Gain'

  200.0,

  // Expression: 200
  //  Referenced by: '<S94>/Attractive Gain'

  200.0,

  // Expression: 1
  //  Referenced by: '<S94>/Influence Range'

  1.0,

  // Expression: 5
  //  Referenced by: '<S94>/Repulsive Gain'

  5.0,

  // Expression: 200
  //  Referenced by: '<S93>/Angular Gain'

  200.0,

  // Expression: 200
  //  Referenced by: '<S93>/Attractive Gain'

  200.0,

  // Expression: 1
  //  Referenced by: '<S93>/Influence Range'

  1.0,

  // Expression: 5
  //  Referenced by: '<S93>/Repulsive Gain'

  5.0,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S164>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_f
  //  Referenced by: '<S165>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_c
  //  Referenced by: '<S166>/TSamp'

  20.0,

  // Expression: -1
  //  Referenced by: '<S125>/Gain6'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S125>/Gain7'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S125>/Gain8'

  -1.0,

  // Computed Parameter: TSamp_WtEt_h
  //  Referenced by: '<S141>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_e
  //  Referenced by: '<S142>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_n
  //  Referenced by: '<S143>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_i
  //  Referenced by: '<S154>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_hr
  //  Referenced by: '<S155>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_ca
  //  Referenced by: '<S156>/TSamp'

  20.0,

  // Expression: -1
  //  Referenced by: '<S123>/Gain6'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S123>/Gain7'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S123>/Gain8'

  -1.0,

  // Computed Parameter: TSamp_WtEt_nd
  //  Referenced by: '<S131>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_co
  //  Referenced by: '<S132>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_no
  //  Referenced by: '<S133>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_p
  //  Referenced by: '<S159>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_o
  //  Referenced by: '<S160>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_px
  //  Referenced by: '<S161>/TSamp'

  20.0,

  // Expression: -1
  //  Referenced by: '<S124>/Gain6'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S124>/Gain7'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S124>/Gain8'

  -1.0,

  // Computed Parameter: TSamp_WtEt_ft
  //  Referenced by: '<S136>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_eh
  //  Referenced by: '<S137>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_ii
  //  Referenced by: '<S138>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_pu
  //  Referenced by: '<S150>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_f0
  //  Referenced by: '<S151>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_nz
  //  Referenced by: '<S152>/TSamp'

  20.0,

  // Expression: 1
  //  Referenced by: '<S122>/Constant7'

  1.0,

  // Computed Parameter: Merge3_InitialOutput
  //  Referenced by: '<S122>/Merge3'

  0.0,

  // Computed Parameter: Merge4_InitialOutput
  //  Referenced by: '<S122>/Merge4'

  0.0,

  // Computed Parameter: Merge5_InitialOutput
  //  Referenced by: '<S122>/Merge5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S126>/Constant7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S126>/Zero'

  0.0,

  // Expression: 428
  //  Referenced by: '<S177>/GPIO Write1'

  428.0,

  // Expression: 1
  //  Referenced by: '<S177>/GPIO Write1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S178>/Gyroscope//Accelerometer'

  -1.0,

  // Expression: 0.0
  //  Referenced by: '<S180>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S180>/Delay1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S180>/Delay2'

  0.0,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S189>/Out1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S189>/Memory'

  0.0,

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S190>/Out1'

  0.0,

  // Computed Parameter: dytdt_Y0
  //  Referenced by: '<S196>/dy(t)//dt'

  0.0,

  // Computed Parameter: dytdt_Y0_j
  //  Referenced by: '<S206>/dy(t)//dt'

  0.0,

  // Computed Parameter: dytdt_Y0_d
  //  Referenced by: '<S216>/dy(t)//dt'

  0.0,

  // Expression: 1/1000
  //  Referenced by: '<S184>/Convert BLAX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S184>/Convert BLAY from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S184>/Convert BLACKVX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S184>/Convert BLACKVY from [mm] to [m]'

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
  //  Referenced by: '<S185>/Convert BLUX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S185>/Convert BLUY from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S185>/Convert BLUEVX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S185>/Convert BLUEVY from [mm] to [m]'

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

  // Expression: 1/1000
  //  Referenced by: '<S186>/Convert REDX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S186>/Convert REDY from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S186>/Convert REDVX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S186>/Convert REDVY from [mm] to [m]'

  0.001,

  // Expression: 0
  //  Referenced by: '<S212>/Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S212>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S212>/Constant3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S214>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S214>/Constant3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S213>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S213>/Constant3'

  0.0,

  // Expression: 1
  //  Referenced by: '<S187>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S226>/Constant'

  0.0,

  // Expression: 400
  //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  400.0,

  // Expression: 0
  //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.0,

  // Expression: 200
  //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  200.0,

  // Expression: 3072
  //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  3072.0,

  // Expression: 1024
  //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  1024.0,

  // Expression: 0
  //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.0,

  // Expression: 850
  //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  850.0,

  // Expression: 400
  //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  400.0,

  // Expression: 100
  //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  100.0,

  // Expression: 50
  //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  50.0,

  // Expression: 0
  //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.0,

  // Computed Parameter: Out1_Y0_f
  //  Referenced by: '<S243>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_j
  //  Referenced by: '<S244>/Out1'

  0.0,

  // Computed Parameter: BLACKDC_Y0
  //  Referenced by: '<S233>/BLACK DC'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S238>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S238>/Constant2'

  0.0,

  // Computed Parameter: Out1_Y0_n
  //  Referenced by: '<S255>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_js
  //  Referenced by: '<S256>/Out1'

  0.0,

  // Computed Parameter: BLUEDC_Y0
  //  Referenced by: '<S234>/BLUE DC'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S250>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S250>/Constant2'

  0.0,

  // Computed Parameter: Out1_Y0_c
  //  Referenced by: '<S267>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S268>/Out1'

  0.0,

  // Computed Parameter: REDDC_Y0
  //  Referenced by: '<S235>/RED DC'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S262>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S262>/Constant2'

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

  // Expression: 0.0
  //  Referenced by: '<Root>/Delay'

  0.0,

  // Computed Parameter: Merge1_InitialOutput
  //  Referenced by: '<S3>/Merge1'

  0.0,

  // Computed Parameter: Merge2_InitialOutput
  //  Referenced by: '<S3>/Merge2'

  0.0,

  // Computed Parameter: Merge_InitialOutput
  //  Referenced by: '<S3>/Merge'

  0.0,

  // Expression: [1;zeros(13,1)]
  //  Referenced by: '<S5>/Delay1'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [1;zeros(12,1)]
  //  Referenced by: '<S16>/Delay1'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(9,1)
  //  Referenced by: '<S17>/Delay1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: eye(3)
  //  Referenced by: '<S17>/Delay2'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Expression: [1;zeros(13,1)]
  //  Referenced by: '<S22>/Delay1'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(6)
  //  Referenced by: '<S22>/Delay2'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [1;zeros(12,1)]
  //  Referenced by: '<S23>/Delay1'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(6)
  //  Referenced by: '<S23>/Delay2'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 568471
  //  Referenced by: '<S26>/Safety Number'

  568471.0,

  // Expression: 100
  //  Referenced by: '<S26>/Gain'

  100.0,

  // Expression: 100
  //  Referenced by: '<S26>/Gain1'

  100.0,

  // Expression: 100
  //  Referenced by: '<S26>/Gain2'

  100.0,

  // Expression: 100
  //  Referenced by: '<S26>/Gain3'

  100.0,

  // Expression: 100
  //  Referenced by: '<S26>/Gain4'

  100.0,

  // Expression: 100
  //  Referenced by: '<S26>/Gain5'

  100.0,

  // Expression: 100
  //  Referenced by: '<S26>/Gain6'

  100.0,

  // Expression: 100
  //  Referenced by: '<S26>/Gain7'

  100.0,

  // Expression: zeros(4,2)
  //  Referenced by: '<Root>/Data Store Memory'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(4,1)
  //  Referenced by: '<Root>/Data Store Memory1'

  { 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(3,1)
  //  Referenced by: '<Root>/Data Store Memory10'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(3,1)
  //  Referenced by: '<Root>/Data Store Memory11'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(4,2)
  //  Referenced by: '<Root>/Data Store Memory12'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(4,1)
  //  Referenced by: '<Root>/Data Store Memory13'

  { 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(3)
  //  Referenced by: '<Root>/Data Store Memory14'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(3,1)
  //  Referenced by: '<Root>/Data Store Memory15'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory16'

  0.0,

  // Expression: zeros(13,1)
  //  Referenced by: '<Root>/Data Store Memory17'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(12)
  //  Referenced by: '<Root>/Data Store Memory18'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory19'

  0.0,

  // Expression: zeros(3)
  //  Referenced by: '<Root>/Data Store Memory2'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(13,1)
  //  Referenced by: '<Root>/Data Store Memory20'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(12)
  //  Referenced by: '<Root>/Data Store Memory21'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory22'

  0.0,

  // Expression: zeros(14,1)
  //  Referenced by: '<Root>/Data Store Memory23'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(12)
  //  Referenced by: '<Root>/Data Store Memory24'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory25'

  0.0,

  // Expression: zeros(14,1)
  //  Referenced by: '<Root>/Data Store Memory26'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(12)
  //  Referenced by: '<Root>/Data Store Memory27'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory28'

  0.0,

  // Expression: zeros(9,1)
  //  Referenced by: '<Root>/Data Store Memory29'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(3,1)
  //  Referenced by: '<Root>/Data Store Memory3'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(12)
  //  Referenced by: '<Root>/Data Store Memory30'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory31'

  0.0,

  // Expression: zeros(9,1)
  //  Referenced by: '<Root>/Data Store Memory32'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(12)
  //  Referenced by: '<Root>/Data Store Memory33'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory34'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory35'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory36'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory37'

  0.0,

  // Expression: zeros(3)
  //  Referenced by: '<Root>/Data Store Memory38'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(3)
  //  Referenced by: '<Root>/Data Store Memory39'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(3,1)
  //  Referenced by: '<Root>/Data Store Memory4'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory40'

  0.0,

  // Expression: zeros(3,1)
  //  Referenced by: '<Root>/Data Store Memory5'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(4,2)
  //  Referenced by: '<Root>/Data Store Memory6'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(4,1)
  //  Referenced by: '<Root>/Data Store Memory7'

  { 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(3)
  //  Referenced by: '<Root>/Data Store Memory8'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(3,1)
  //  Referenced by: '<Root>/Data Store Memory9'

  { 0.0, 0.0, 0.0 },

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

  // Expression: "Target: Hello"
  //  Referenced by: '<S174>/String Constant1'

  "Target: Hello",

  // Expression: "Obstacle: Hello"
  //  Referenced by: '<S175>/String Constant2'

  "Obstacle: Hello",

  // Computed Parameter: RED_Tz3_InitialValue
  //  Referenced by: '<Root>/RED_Tz3'

  "",

  // Computed Parameter: UDPSend1_Port
  //  Referenced by: '<S174>/UDP Send1'

  55000,

  // Computed Parameter: UDPSend2_Port
  //  Referenced by: '<S175>/UDP Send2'

  55000,

  // Computed Parameter: UDPSend3_Port
  //  Referenced by: '<S176>/UDP Send3'

  55000,

  // Computed Parameter: ReceivePhaseSpaceData_Port
  //  Referenced by: '<S183>/Receive PhaseSpace Data'

  31534,

  // Computed Parameter: Delay_InitialCondition_j
  //  Referenced by: '<S188>/Delay'

  0,

  // Computed Parameter: Delay1_InitialCondition_d
  //  Referenced by: '<S188>/Delay1'

  0,

  // Computed Parameter: Delay2_InitialCondition_ak
  //  Referenced by: '<S188>/Delay2'

  0,

  // Computed Parameter: UDPReceive_Port
  //  Referenced by: '<S188>/UDP Receive'

  33001,

  // Computed Parameter: UDPReceive2_Port
  //  Referenced by: '<S188>/UDP Receive2'

  33002,

  // Computed Parameter: UDPReceive3_Port
  //  Referenced by: '<S188>/UDP Receive3'

  33003,

  // Computed Parameter: UDPReceive1_Port
  //  Referenced by: '<S226>/UDP Receive1'

  30172,

  // Computed Parameter: UDPSend_Port
  //  Referenced by: '<S232>/UDP Send'

  46875,

  // Computed Parameter: UDPSend_Port_h
  //  Referenced by: '<S26>/UDP Send'

  48291,

  // Start of '<S214>/Enabled Subsystem'
  {
    // Computed Parameter: dydt_Y0
    //  Referenced by: '<S220>/dy//dt'

    0.0,

    // Expression: 0.1
    //  Referenced by: '<S220>/Constant2'

    0.1,

    // Expression: 0.0
    //  Referenced by: '<S220>/Delay1'

    0.0
  }
  ,

  // End of '<S214>/Enabled Subsystem'

  // Start of '<S213>/Enabled Subsystem'
  {
    // Computed Parameter: dydt_Y0
    //  Referenced by: '<S218>/dy//dt'

    0.0,

    // Expression: 0.1
    //  Referenced by: '<S218>/Constant2'

    0.1,

    // Expression: 0.0
    //  Referenced by: '<S218>/Delay1'

    0.0
  }
  ,

  // End of '<S213>/Enabled Subsystem'

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

  // Start of '<S4>/Change RED Behavior'
  {
    // Computed Parameter: Constant1_Value
    //  Referenced by: '<S170>/Constant1'

    1,

    // Computed Parameter: UDPSend_Port
    //  Referenced by: '<S170>/UDP Send'

    33001
  }
  ,

  // End of '<S4>/Change RED Behavior'

  // Start of '<S4>/Change BLUE Behavior'
  {
    // Computed Parameter: Constant1_Value
    //  Referenced by: '<S169>/Constant1'

    1,

    // Computed Parameter: UDPSend_Port
    //  Referenced by: '<S169>/UDP Send'

    33003
  }
  ,

  // End of '<S4>/Change BLUE Behavior'

  // Start of '<S4>/Change BLACK Behavior'
  {
    // Computed Parameter: Constant1_Value
    //  Referenced by: '<S168>/Constant1'

    1,

    // Computed Parameter: UDPSend_Port
    //  Referenced by: '<S168>/UDP Send'

    33002
  }
  ,

  // End of '<S4>/Change BLACK Behavior'

  // Start of '<S3>/Custom Control (ARM)'
  {
    // Expression: 0
    //  Referenced by: '<S117>/Zero'

    0.0
  }
  ,

  // End of '<S3>/Custom Control (ARM)'

  // Start of '<S3>/Disable Thrusters (BLUE)'
  {
    // Expression: 0
    //  Referenced by: '<S128>/Zero'

    0.0
  }
  ,

  // End of '<S3>/Disable Thrusters (BLUE)'

  // Start of '<S3>/Disable Thrusters (BLACK)'
  {
    // Expression: 0
    //  Referenced by: '<S127>/Zero'

    0.0
  }
  ,

  // End of '<S3>/Disable Thrusters (BLACK)'

  // Start of '<S3>/Disable Thrusters (RED)'
  {
    // Expression: 0
    //  Referenced by: '<S129>/Zero'

    0.0
  }
  ,

  // End of '<S3>/Disable Thrusters (RED)'

  // Start of '<S3>/Custom Control (RED)'
  {
    // Expression: 0
    //  Referenced by: '<S118>/Zero'

    0.0
  }
  ,

  // End of '<S3>/Custom Control (RED)'

  // Start of '<S1>/Phase #5: Hold Home'
  {
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

    // Expression: pi/2
    //  Referenced by: '<S85>/Constant3'

    1.5707963267948966,

    // Expression: pi/2
    //  Referenced by: '<S85>/Constant1'

    1.5707963267948966,

    // Expression: 0
    //  Referenced by: '<S85>/Constant2'

    0.0
  }
  ,

  // End of '<S1>/Phase #5: Hold Home'

  // Start of '<S1>/Phase #4: Return Home'
  {
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
    //  Referenced by: '<S81>/Constant3'

    1.5707963267948966,

    // Expression: pi/2
    //  Referenced by: '<S81>/Constant1'

    1.5707963267948966,

    // Expression: 0
    //  Referenced by: '<S81>/Constant2'

    0.0
  }
  ,

  // End of '<S1>/Phase #4: Return Home'

  // Start of '<S1>/Phase #1: Start Floating '
  {
    // Expression: 0
    //  Referenced by: '<S28>/Constant1'

    0.0,

    // Expression: 0
    //  Referenced by: '<S28>/Constant2'

    0.0,

    // Expression: 0
    //  Referenced by: '<S28>/Constant3'

    0.0,

    // Expression: 0
    //  Referenced by: '<S28>/Constant4'

    0.0,

    // Expression: 0
    //  Referenced by: '<S28>/Constant5'

    0.0,

    // Expression: 0
    //  Referenced by: '<S28>/Constant6'

    0.0,

    // Expression: 0
    //  Referenced by: '<S28>/Constant7'

    0.0,

    // Expression: 0
    //  Referenced by: '<S28>/Constant8'

    0.0,

    // Expression: 1
    //  Referenced by: '<S28>/Puck State'

    1.0,

    // Expression: "Chaser: Running Phase 1"
    //  Referenced by: '<S28>/String Constant'

    "Chaser: Running Phase 1"
  }
  ,

  // End of '<S1>/Phase #1: Start Floating '

  // Start of '<S1>/Phase #0: Synchronization'
  {
    // Expression: 0
    //  Referenced by: '<S27>/Constant1'

    0.0,

    // Expression: 0
    //  Referenced by: '<S27>/Constant2'

    0.0,

    // Expression: 0
    //  Referenced by: '<S27>/Constant3'

    0.0,

    // Expression: 0
    //  Referenced by: '<S27>/Constant4'

    0.0,

    // Expression: 0
    //  Referenced by: '<S27>/Constant5'

    0.0,

    // Expression: 0
    //  Referenced by: '<S27>/Constant6'

    0.0,

    // Expression: 0
    //  Referenced by: '<S27>/Constant7'

    0.0,

    // Expression: 0
    //  Referenced by: '<S27>/Constant8'

    0.0,

    // Expression: 0
    //  Referenced by: '<S27>/Puck State'

    0.0,

    // Expression: "Chaser: Running Phase 0"
    //  Referenced by: '<S27>/String Constant'

    "Chaser: Running Phase 0"
  }
  // End of '<S1>/Phase #0: Synchronization'
};

//
// File trailer for generated code.
//
// [EOF]
//
