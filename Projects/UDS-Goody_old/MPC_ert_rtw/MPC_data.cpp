//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MPC_data.cpp
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

// Block parameters (default storage)
P_MPC_T MPC_P = {
  // Variable: F_black_X_nominal
  //  Referenced by: '<S292>/MATLAB Function5'

  0.2825,

  // Variable: F_black_Y_nominal
  //  Referenced by: '<S292>/MATLAB Function5'

  0.2825,

  // Variable: F_blue_X_nominal
  //  Referenced by: '<S304>/MATLAB Function5'

  0.2825,

  // Variable: F_blue_Y_nominal
  //  Referenced by: '<S304>/MATLAB Function5'

  0.2825,

  // Variable: F_red_X_nominal
  //  Referenced by: '<S316>/MATLAB Function5'

  0.2825,

  // Variable: F_red_Y_nominal
  //  Referenced by: '<S316>/MATLAB Function5'

  0.2825,

  // Variable: F_thrusters_BLACK
  //  Referenced by: '<S295>/MATLAB Function'

  { 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825 },

  // Variable: F_thrusters_BLUE
  //  Referenced by: '<S307>/MATLAB Function'

  { 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825 },

  // Variable: F_thrusters_RED
  //  Referenced by: '<S319>/MATLAB Function'

  { 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825, 0.2825 },

  // Variable: IBLACK
  //  Referenced by:
  //    '<S266>/MATLAB Function'
  //    '<S267>/MATLAB Function'

  0.19956537087503129,

  // Variable: IRED
  //  Referenced by: '<S268>/MATLAB Function'

  0.19816136536704418,

  // Variable: K_BLACK
  //  Referenced by:
  //    '<S125>/Constant2'
  //    '<S129>/Constant2'
  //    '<S131>/Constant2'

  { 0.40234817833208658, 1.0311844491536458E-14, 3.3280085097900945E-15,
    -3.4849626273831559E-15, 0.4023481783320994, 2.4071774753115092E-15,
    2.1672051737834689E-15, 1.2843486460872702E-16, 0.081554964432253255,
    3.2805183386913637, 7.43122876806996E-14, 1.5522271489125213E-14,
    1.8053332398460726E-14, 3.2805183386913552, 1.0150603020041256E-14,
    8.2159574762201189E-16, -3.2725287139997539E-16, 0.40690949597934378 },

  // Variable: K_BLUE
  //  Referenced by: '<S126>/Constant2'

  { 0.40218238973674775, 1.683962826555525E-15, 7.5785945510315839E-15,
    3.9111419922025071E-15, 0.40218238973675713, 6.6736196360470178E-15,
    4.9400995945260145E-16, 4.4420114922023327E-16, 0.081407426263066282,
    3.2133409169777383, 5.46229728115577E-14, 7.5629359369335219E-14,
    4.34773196942792E-15, 3.213340916977828, 8.08249183037409E-14,
    2.74871748743334E-16, 1.4383159062603373E-16, 0.40554915553132154 },

  // Variable: K_RED
  //  Referenced by: '<S127>/Constant2'

  { 0.40232877970259667, -2.0263012511229824E-14, -8.4051443133328233E-16,
    5.8702555000223288E-16, 0.40232877970262537, -5.6425539336462471E-15,
    -6.41430742891448E-16, 1.1731704775391289E-15, 0.08149590638118985,
    3.2724457090025347, -1.3522860420014287E-13, 1.7987277018860464E-14,
    4.2362751675083559E-14, 3.2724457090028443, -3.58115642612403E-14,
    5.2160424216070551E-17, 5.5541095421028447E-16, 0.40636232022479724 },

  // Variable: Kd_elarm
  //  Referenced by: '<S154>/kd_elarm'

  0.8,

  // Variable: Kd_sharm
  //  Referenced by: '<S155>/kd_sharm'

  1.0,

  // Variable: Kd_tblue
  //  Referenced by: '<S130>/Gain5'

  1.8,

  // Variable: Kd_wrarm
  //  Referenced by: '<S156>/kd_wrarm'

  0.6,

  // Variable: Kd_xblue
  //  Referenced by: '<S130>/Gain3'

  3.6,

  // Variable: Kd_yblue
  //  Referenced by: '<S130>/Gain4'

  3.6,

  // Variable: Kp_elarm
  //  Referenced by: '<S154>/kp_elarm'

  1.2,

  // Variable: Kp_sharm
  //  Referenced by: '<S155>/kp_sharm'

  1.5,

  // Variable: Kp_tblue
  //  Referenced by: '<S130>/Gain2'

  0.5,

  // Variable: Kp_wrarm
  //  Referenced by: '<S156>/kp_wrarm'

  1.0,

  // Variable: Kp_xblue
  //  Referenced by: '<S130>/Gain'

  1.0,

  // Variable: Kp_yblue
  //  Referenced by: '<S130>/Gain1'

  1.0,

  // Variable: PQ
  //  Referenced by:
  //    '<S97>/Delay'
  //    '<S101>/Delay'

  { 20.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 20.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 20.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  // Variable: PR
  //  Referenced by:
  //    '<S98>/Delay'
  //    '<S102>/Delay2'

  { 20.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 20.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 20.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0001, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0001, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0001 },

  // Variable: PWMFreq
  //  Referenced by:
  //    '<S18>/PWM Frequency'
  //    '<S292>/MATLAB Function1'
  //    '<S304>/MATLAB Function1'
  //    '<S316>/MATLAB Function8'
  //    '<S294>/Constant1'
  //    '<S306>/Constant1'
  //    '<S318>/Constant1'

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
  //    '<S37>/Constant2'
  //    '<S40>/Constant2'
  //    '<S44>/Constant2'
  //    '<S48>/Constant2'
  //    '<S52>/Constant2'

  15.0,

  // Variable: Phase3_End
  //  Referenced by: '<S1>/Constant2'

  135.0,

  // Variable: Phase3_SubPhase1_End
  //  Referenced by: '<S23>/Constant4'

  135.0,

  // Variable: Phase3_SubPhase2_End
  //  Referenced by: '<S23>/Constant1'

  135.0,

  // Variable: Phase3_SubPhase3_End
  //  Referenced by: '<S23>/Constant2'

  135.0,

  // Variable: Phase3_SubPhase4_End
  //  Referenced by: '<S23>/Constant3'

  135.0,

  // Variable: Phase4_End
  //  Referenced by: '<S1>/Constant3'

  135.0,

  // Variable: Phase5_End
  //  Referenced by: '<S1>/Constant6'

  135.0,

  // Variable: Q
  //  Referenced by:
  //    '<S97>/MATLAB Function1'
  //    '<S98>/MATLAB Function1'
  //    '<S101>/MATLAB Function1'
  //    '<S102>/MATLAB Function1'

  { 0.01, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-10, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-10, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-10, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0001,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0001 },

  // Variable: R
  //  Referenced by:
  //    '<S97>/MATLAB Function1'
  //    '<S98>/MATLAB Function1'
  //    '<S101>/MATLAB Function1'
  //    '<S102>/MATLAB Function1'

  { 0.006, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.006, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.006, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001 },

  // Variable: Tz_lim_elarm
  //  Referenced by: '<S153>/Saturation1'

  0.1,

  // Variable: Tz_lim_sharm
  //  Referenced by: '<S153>/Saturation'

  0.1,

  // Variable: Tz_lim_wrarm
  //  Referenced by: '<S153>/Saturation3'

  0.1,

  // Variable: baseRate
  //  Referenced by:
  //    '<S67>/MATLAB Function'
  //    '<S68>/MATLAB Function'
  //    '<S221>/Read Joint Positions using  Dynamixel Encoders'
  //    '<S278>/WhoAmI'
  //    '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.05,

  // Variable: dataRate
  //  Referenced by:
  //    '<S233>/Constant'
  //    '<S243>/Constant'
  //    '<S253>/Constant'

  0.1,

  // Variable: home_states_BLACK
  //  Referenced by:
  //    '<S56>/Desired States (BLACK)'
  //    '<S60>/Desired States (BLACK)'

  { 1.755775, 1.209675, 0.0 },

  // Variable: home_states_BLUE
  //  Referenced by:
  //    '<S57>/Desired States (BLUE)'
  //    '<S61>/Desired States (BLUE)'

  { 0.85577500000000006, 1.209675, 0.0 },

  // Variable: home_states_RED
  //  Referenced by:
  //    '<S58>/Constant2'
  //    '<S62>/Constant2'

  { 2.655775, 1.209675, 3.1415926535897931 },

  // Variable: init_states_BLACK
  //  Referenced by:
  //    '<S28>/Desired States (BLACK)'
  //    '<S51>/Constant'

  { 1.7, 1.2, 0.0 },

  // Variable: init_states_BLUE
  //  Referenced by: '<S29>/Desired States (BLUE)'

  { 0.0, 0.0, 0.0 },

  // Variable: init_states_RED
  //  Referenced by: '<S30>/Constant2'

  { 3.2, 2.1, -2.6975403981943264 },

  // Variable: mBLACK
  //  Referenced by:
  //    '<S266>/MATLAB Function'
  //    '<S267>/MATLAB Function'

  11.362,

  // Variable: mRED
  //  Referenced by: '<S268>/MATLAB Function'

  11.296999999999999,

  // Variable: maxd
  //  Referenced by:
  //    '<S97>/MATLAB Function1'
  //    '<S98>/MATLAB Function1'
  //    '<S101>/MATLAB Function1'
  //    '<S102>/MATLAB Function1'

  { 1.6046, 5.5866 },

  // Variable: platformSelection
  //  Referenced by: '<S229>/MATLAB Function'

  3.0,

  // Variable: r_hold_tar_0
  //  Referenced by: '<Root>/Universal_Time37'

  { 0.85, 0.85 },

  // Variable: rho
  //  Referenced by: '<S101>/MATLAB Function1'

  0.98,

  // Variable: simMode
  //  Referenced by: '<S17>/Constant'

  0.0,

  // Variable: thruster_dist2CG_BLACK
  //  Referenced by:
  //    '<S292>/MATLAB Function5'
  //    '<S295>/MATLAB Function'

  { 87.2054215807076, -50.794578419292378, 67.834888223904244,
    -73.665111776095742, 50.794578419292378, -79.6054215807076,
    68.165111776095742, -60.834888223904244 },

  // Variable: thruster_dist2CG_BLUE
  //  Referenced by:
  //    '<S304>/MATLAB Function5'
  //    '<S307>/MATLAB Function'

  { 84.3010033444816, -53.698996655518386, 79.980637211758491,
    -61.519362788241494, 53.698996655518386, -76.7010033444816,
    56.019362788241487, -72.9806372117585 },

  // Variable: thruster_dist2CG_RED
  //  Referenced by:
  //    '<S316>/MATLAB Function5'
  //    '<S319>/MATLAB Function'

  { 64.335708595202249, -67.664291404797723, 93.129636186598191,
    -51.370363813401788, 70.664291404797723, -63.335708595202256,
    43.870363813401781, -85.629636186598219 },

  // Variable: x_BLACK_0
  //  Referenced by:
  //    '<S35>/Constant'
  //    '<S35>/Constant1'
  //    '<S43>/Constant'
  //    '<S43>/Constant1'
  //    '<S47>/Constant'
  //    '<S47>/Constant1'

  { 1.7, 1.2, 5.2359877559829888, 0.0, 0.0, 0.069813170079773182 },

  // Variable: x_BLUE_0
  //  Referenced by:
  //    '<S36>/Constant'
  //    '<S36>/Constant1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Variable: z_0
  //  Referenced by:
  //    '<Root>/Universal_Time21'
  //    '<Root>/Universal_Time38'

  { 0.0, -0.1, 0.0, 3.2, 2.0822961848278303, -2.6975403981943264, 0.0,
    -0.017703815172169606, 0.0, 0.0, 0.0, 0.0, 3.2, 2.0468885544834912,
    -2.6975403981943264, 0.0, -0.017703815172169606, 0.0, 0.0, 0.0, 0.0, 3.2,
    2.011480924139152, -2.6975403981943264, 0.0, -0.017703815172169606, 0.0, 0.0,
    0.0, 0.0, 3.2, 1.9760732937948129, -2.6975403981943264, 0.0,
    -0.017703815172169606, 0.0, 0.0, 0.0, 0.0, 3.2, 1.9406656634504738,
    -2.6975403981943264, 0.0, -0.017703815172169606, 0.0, 0.0, 0.0, 0.0, 3.2,
    1.9052580331061346, -2.6975403981943264, 0.0, -0.017703815172169606, 0.0,
    0.0, 0.0, 0.0, 3.2, 1.8698504027617955, -2.6975403981943264, 0.0,
    -0.017703815172169606, 0.0, 0.0, 0.0, 0.0, 3.2, 1.8344427724174563,
    -2.6975403981943264, 0.0, -0.017703815172169606, 0.0, 0.0, 0.0, 0.0, 3.2,
    1.7990351420731172, -2.6975403981943264, 0.0, -0.017703815172169606, 0.0,
    0.0, 0.0, 0.0, 3.2, 1.7636275117287781, -2.6975403981943264, 0.0,
    -0.017703815172169606, 0.0, 0.0, 0.0, 0.0, 3.2, 1.7282198813844389,
    -2.6975403981943264, 0.0, -0.017703815172169606, 0.0, 0.0, 0.0, 0.0, 3.2,
    1.6928122510400998, -2.6975403981943264, 0.0, -0.017703815172169606, 0.0,
    0.0, 0.0, 0.0, 3.2, 1.6574046206957607, -2.6975403981943264, 0.0,
    -0.017703815172169606, 0.0, 0.0, 0.0, 0.0, 3.2, 1.6219969903514215,
    -2.6975403981943264, 0.0, -0.017703815172169606, 0.0, 0.0, 0.0, 0.0, 3.2,
    1.5865893600070824, -2.6975403981943264, 0.0, -0.017703815172169606, 0.0 },

  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S171>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevScale
  //  Referenced by: '<S172>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevScale
  //  Referenced by: '<S173>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_i
  //  Referenced by: '<S148>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_e
  //  Referenced by: '<S149>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_o
  //  Referenced by: '<S150>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_p
  //  Referenced by: '<S166>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_l
  //  Referenced by: '<S167>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevSc_on
  //  Referenced by: '<S168>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_n
  //  Referenced by: '<S143>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_f
  //  Referenced by: '<S144>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative2_ICPrevSca_g
  //  Referenced by: '<S145>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_j
  //  Referenced by: '<S157>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_a
  //  Referenced by: '<S158>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevSca_k
  //  Referenced by: '<S159>/UD'

  0.0,

  // Mask Parameter: MATLABFunction5_max_iters
  //  Referenced by: '<S292>/MATLAB Function5'

  1.0,

  // Mask Parameter: MATLABFunction5_max_iters_l
  //  Referenced by: '<S304>/MATLAB Function5'

  1.0,

  // Mask Parameter: MATLABFunction5_max_iters_o
  //  Referenced by: '<S316>/MATLAB Function5'

  1.0,

  // Mask Parameter: MATLABFunction5_tol
  //  Referenced by: '<S292>/MATLAB Function5'

  0.001,

  // Mask Parameter: MATLABFunction5_tol_i
  //  Referenced by: '<S304>/MATLAB Function5'

  0.001,

  // Mask Parameter: MATLABFunction5_tol_j
  //  Referenced by: '<S316>/MATLAB Function5'

  0.001,

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

  // Expression: 0
  //  Referenced by: '<S22>/Puck State1'

  0.0,

  // Expression: pi/2
  //  Referenced by: '<S27>/Constant3'

  1.5707963267948966,

  // Expression: pi/2
  //  Referenced by: '<S27>/Constant1'

  1.5707963267948966,

  // Expression: 0
  //  Referenced by: '<S27>/Constant2'

  0.0,

  // Expression: [0 0 0]
  //  Referenced by: '<S31>/Constant'

  { 0.0, 0.0, 0.0 },

  // Expression: [0 0 0]
  //  Referenced by: '<S31>/Constant1'

  { 0.0, 0.0, 0.0 },

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

  // Expression: 3
  //  Referenced by: '<S31>/Constant5'

  3.0,

  // Expression: 1
  //  Referenced by: '<S31>/Constant6'

  1.0,

  // Expression: 2
  //  Referenced by: '<S31>/Constant8'

  2.0,

  // Expression: 1
  //  Referenced by: '<S31>/Puck State1'

  1.0,

  // Expression: [0 0 0]
  //  Referenced by: '<S32>/Constant'

  { 0.0, 0.0, 0.0 },

  // Expression: [0 0 0]
  //  Referenced by: '<S32>/Constant1'

  { 0.0, 0.0, 0.0 },

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

  // Expression: [0 0 0]
  //  Referenced by: '<S32>/Constant2'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S32>/Constant4'

  0.0,

  // Expression: 3
  //  Referenced by: '<S32>/Constant5'

  3.0,

  // Expression: 1
  //  Referenced by: '<S32>/Constant6'

  1.0,

  // Expression: 0
  //  Referenced by: '<S32>/Constant8'

  0.0,

  // Expression: 1
  //  Referenced by: '<S32>/Puck State1'

  1.0,

  // Expression: [0 0 0]
  //  Referenced by: '<S33>/Constant'

  { 0.0, 0.0, 0.0 },

  // Expression: [0 0 0]
  //  Referenced by: '<S33>/Constant1'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S33>/Constant11'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Constant12'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Constant14'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Constant15'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Constant18'

  0.0,

  // Expression: [0 0 0]
  //  Referenced by: '<S33>/Constant2'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S33>/Constant4'

  0.0,

  // Expression: 3
  //  Referenced by: '<S33>/Constant5'

  3.0,

  // Expression: 1
  //  Referenced by: '<S33>/Constant6'

  1.0,

  // Expression: 0
  //  Referenced by: '<S33>/Constant8'

  0.0,

  // Expression: 1
  //  Referenced by: '<S33>/Puck State1'

  1.0,

  // Expression: [0 0 0]
  //  Referenced by: '<S34>/Constant'

  { 0.0, 0.0, 0.0 },

  // Expression: [0 0 0]
  //  Referenced by: '<S34>/Constant1'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S34>/Constant11'

  0.0,

  // Expression: 0
  //  Referenced by: '<S34>/Constant12'

  0.0,

  // Expression: 0
  //  Referenced by: '<S34>/Constant14'

  0.0,

  // Expression: 0
  //  Referenced by: '<S34>/Constant15'

  0.0,

  // Expression: 0
  //  Referenced by: '<S34>/Constant18'

  0.0,

  // Expression: [0 0 0]
  //  Referenced by: '<S34>/Constant2'

  { 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<S34>/Constant4'

  1.0,

  // Expression: 1
  //  Referenced by: '<S34>/Constant5'

  1.0,

  // Expression: 1
  //  Referenced by: '<S34>/Constant6'

  1.0,

  // Expression: 0
  //  Referenced by: '<S34>/Constant8'

  0.0,

  // Expression: 0
  //  Referenced by: '<S34>/Puck State1'

  0.0,

  // Expression: 4*pi/180
  //  Referenced by: '<S51>/4 deg per sec'

  0.069813170079773182,

  // Expression: 0
  //  Referenced by: '<S26>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S26>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S26>/Constant3'

  0.0,

  // Expression: 0
  //  Referenced by: '<S26>/Constant4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S26>/Constant5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S26>/Constant6'

  0.0,

  // Expression: 0
  //  Referenced by: '<S26>/Constant7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S26>/Constant8'

  0.0,

  // Expression: 0
  //  Referenced by: '<S26>/Puck State1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S26>/Puck State'

  0.0,

  // Expression: 200
  //  Referenced by: '<S68>/Angular Gain'

  200.0,

  // Expression: 200
  //  Referenced by: '<S68>/Attractive Gain'

  200.0,

  // Expression: 1
  //  Referenced by: '<S68>/Influence Range'

  1.0,

  // Expression: 5
  //  Referenced by: '<S68>/Repulsive Gain'

  5.0,

  // Expression: 200
  //  Referenced by: '<S67>/Angular Gain'

  200.0,

  // Expression: 200
  //  Referenced by: '<S67>/Attractive Gain'

  200.0,

  // Expression: 1
  //  Referenced by: '<S67>/Influence Range'

  1.0,

  // Expression: 5
  //  Referenced by: '<S67>/Repulsive Gain'

  5.0,

  // Expression: [1;zeros(12,1)]
  //  Referenced by: '<S97>/Delay1'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(9,1)
  //  Referenced by: '<S98>/Delay1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: eye(3)
  //  Referenced by: '<S98>/Delay2'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Expression: [1;zeros(12,1)]
  //  Referenced by: '<S101>/Delay1'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(6)
  //  Referenced by: '<S101>/Delay2'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(9,1)
  //  Referenced by: '<S102>/Delay1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: eye(3)
  //  Referenced by: '<S102>/Delay4'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Expression: zeros(6)
  //  Referenced by: '<S102>/Delay3'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S171>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_l
  //  Referenced by: '<S172>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_n
  //  Referenced by: '<S173>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_h
  //  Referenced by: '<S148>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_e
  //  Referenced by: '<S149>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_n3
  //  Referenced by: '<S150>/TSamp'

  20.0,

  // Expression: 0
  //  Referenced by: '<S133>/Zero'

  0.0,

  // Computed Parameter: TSamp_WtEt_p
  //  Referenced by: '<S166>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_o
  //  Referenced by: '<S167>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_px
  //  Referenced by: '<S168>/TSamp'

  20.0,

  // Expression: -1
  //  Referenced by: '<S130>/Gain6'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S130>/Gain7'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S130>/Gain8'

  -1.0,

  // Computed Parameter: TSamp_WtEt_f
  //  Referenced by: '<S143>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_eh
  //  Referenced by: '<S144>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_i
  //  Referenced by: '<S145>/TSamp'

  20.0,

  // Expression: 0
  //  Referenced by: '<S134>/Zero'

  0.0,

  // Computed Parameter: TSamp_WtEt_pu
  //  Referenced by: '<S157>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_f0
  //  Referenced by: '<S158>/TSamp'

  20.0,

  // Computed Parameter: TSamp_WtEt_nz
  //  Referenced by: '<S159>/TSamp'

  20.0,

  // Expression: 1
  //  Referenced by: '<S128>/Constant7'

  1.0,

  // Computed Parameter: Merge3_InitialOutput
  //  Referenced by: '<S128>/Merge3'

  0.0,

  // Computed Parameter: Merge4_InitialOutput
  //  Referenced by: '<S128>/Merge4'

  0.0,

  // Computed Parameter: Merge5_InitialOutput
  //  Referenced by: '<S128>/Merge5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S132>/Constant7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S132>/Zero'

  0.0,

  // Expression: 428
  //  Referenced by: '<S218>/GPIO Write1'

  428.0,

  // Expression: 1
  //  Referenced by: '<S218>/GPIO Write1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S219>/Gyroscope//Accelerometer'

  -1.0,

  // Expression: 0.0
  //  Referenced by: '<S221>/Delay'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S221>/Delay1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S221>/Delay2'

  0.0,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S230>/Out1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S230>/Memory'

  0.0,

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S231>/Out1'

  0.0,

  // Computed Parameter: dytdt_Y0
  //  Referenced by: '<S237>/dy(t)//dt'

  0.0,

  // Computed Parameter: dytdt_Y0_j
  //  Referenced by: '<S247>/dy(t)//dt'

  0.0,

  // Computed Parameter: dytdt_Y0_d
  //  Referenced by: '<S257>/dy(t)//dt'

  0.0,

  // Expression: 1/1000
  //  Referenced by: '<S225>/Convert BLAX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S225>/Convert BLAY from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S225>/Convert BLACKVX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S225>/Convert BLACKVY from [mm] to [m]'

  0.001,

  // Expression: 0
  //  Referenced by: '<S233>/Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S233>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S233>/Constant3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S235>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S235>/Constant3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S234>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S234>/Constant3'

  0.0,

  // Expression: 1/1000
  //  Referenced by: '<S226>/Convert BLUX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S226>/Convert BLUY from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S226>/Convert BLUEVX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S226>/Convert BLUEVY from [mm] to [m]'

  0.001,

  // Expression: 0
  //  Referenced by: '<S243>/Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S243>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S243>/Constant3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S245>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S245>/Constant3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S244>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S244>/Constant3'

  0.0,

  // Expression: 1/1000
  //  Referenced by: '<S227>/Convert REDX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S227>/Convert REDY from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S227>/Convert REDVX from [mm] to [m]'

  0.001,

  // Expression: 1/1000
  //  Referenced by: '<S227>/Convert REDVY from [mm] to [m]'

  0.001,

  // Expression: 0
  //  Referenced by: '<S253>/Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S253>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S253>/Constant3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S255>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S255>/Constant3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S254>/Delay1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S254>/Constant3'

  0.0,

  // Expression: 1
  //  Referenced by: '<S228>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S279>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S279>/Delay2'

  0.0,

  // Expression: [0;0;0]
  //  Referenced by: '<S279>/Delay'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S279>/Delay1'

  0.0,

  // Expression: 400
  //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  400.0,

  // Expression: 0
  //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.0,

  // Expression: 200
  //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  200.0,

  // Expression: 3072
  //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  3072.0,

  // Expression: 1024
  //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  1024.0,

  // Expression: 0
  //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.0,

  // Expression: 850
  //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  850.0,

  // Expression: 400
  //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  400.0,

  // Expression: 100
  //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  100.0,

  // Expression: 50
  //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  50.0,

  // Expression: 0
  //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  0.0,

  // Computed Parameter: Out1_Y0_c
  //  Referenced by: '<S299>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_a
  //  Referenced by: '<S300>/Out1'

  0.0,

  // Computed Parameter: BLACKDC_Y0
  //  Referenced by: '<S289>/BLACK DC'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S294>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S294>/Constant2'

  0.0,

  // Computed Parameter: Out1_Y0_n
  //  Referenced by: '<S311>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_l
  //  Referenced by: '<S312>/Out1'

  0.0,

  // Computed Parameter: BLUEDC_Y0
  //  Referenced by: '<S290>/BLUE DC'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S306>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S306>/Constant2'

  0.0,

  // Computed Parameter: Out1_Y0_o
  //  Referenced by: '<S323>/Out1'

  0.0,

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S324>/Out1'

  0.0,

  // Computed Parameter: REDDC_Y0
  //  Referenced by: '<S291>/RED DC'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S318>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S318>/Constant2'

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
  //  Referenced by: '<S19>/Delay'

  0.0,

  // Computed Parameter: Merge2_InitialOutput
  //  Referenced by: '<S4>/Merge2'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S276>/Delay2'

  0.0,

  // Expression: [init_states_BLACK';0;0;0]
  //  Referenced by: '<S268>/Delay1'

  { 1.7, 1.2, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0.002*eye(6)
  //  Referenced by: '<S268>/Delay'

  { 0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.002 },

  // Expression: 0*eye(3)
  //  Referenced by: '<S268>/Delay2'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0.0
  //  Referenced by: '<S270>/Delay2'

  0.0,

  // Expression: [init_states_BLACK';0;0;0]
  //  Referenced by: '<S266>/Delay1'

  { 1.7, 1.2, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0.002*eye(6)
  //  Referenced by: '<S266>/Delay'

  { 0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.002 },

  // Expression: 0*eye(3)
  //  Referenced by: '<S266>/Delay2'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0.0
  //  Referenced by: '<S273>/Delay2'

  0.0,

  // Expression: [init_states_BLACK';0;0;0]
  //  Referenced by: '<S267>/Delay1'

  { 1.7, 1.2, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0.002*eye(6)
  //  Referenced by: '<S267>/Delay'

  { 0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.002 },

  // Expression: 0*eye(3)
  //  Referenced by: '<S267>/Delay2'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 568471
  //  Referenced by: '<S18>/Safety Number'

  568471.0,

  // Expression: 100
  //  Referenced by: '<S18>/Gain'

  100.0,

  // Expression: 100
  //  Referenced by: '<S18>/Gain1'

  100.0,

  // Expression: 100
  //  Referenced by: '<S18>/Gain2'

  100.0,

  // Expression: 100
  //  Referenced by: '<S18>/Gain3'

  100.0,

  // Expression: 100
  //  Referenced by: '<S18>/Gain4'

  100.0,

  // Expression: 100
  //  Referenced by: '<S18>/Gain5'

  100.0,

  // Expression: 100
  //  Referenced by: '<S18>/Gain6'

  100.0,

  // Expression: 100
  //  Referenced by: '<S18>/Gain7'

  100.0,

  // Expression: [[1; 0; 0; 0], [0; 0; 0; 0]]
  //  Referenced by: '<Root>/Data Store Memory'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [1;0;0;0]
  //  Referenced by: '<Root>/Data Store Memory1'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(3,1)
  //  Referenced by: '<Root>/Data Store Memory10'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(3,1)
  //  Referenced by: '<Root>/Data Store Memory11'

  { 0.0, 0.0, 0.0 },

  // Expression: [[1; 0; 0; 0], [0; 0; 0; 0]]
  //  Referenced by: '<Root>/Data Store Memory12'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [1;0;0;0]
  //  Referenced by: '<Root>/Data Store Memory13'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: eye(3)
  //  Referenced by: '<Root>/Data Store Memory14'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Expression: zeros(3,1)
  //  Referenced by: '<Root>/Data Store Memory15'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory16'

  0.0,

  // Expression: [1;zeros(12,1)]
  //  Referenced by: '<Root>/Data Store Memory17'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

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

  // Expression: eye(3)
  //  Referenced by: '<Root>/Data Store Memory2'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Expression: [1;zeros(12,1)]
  //  Referenced by: '<Root>/Data Store Memory20'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

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

  // Expression: [1;zeros(12,1)]
  //  Referenced by: '<Root>/Data Store Memory23'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

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

  // Expression: [1;zeros(12,1)]
  //  Referenced by: '<Root>/Data Store Memory26'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

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

  // Expression: [1;zeros(12,1)]
  //  Referenced by: '<Root>/Data Store Memory29'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

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

  // Expression: [1;zeros(12,1)]
  //  Referenced by: '<Root>/Data Store Memory32'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

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

  // Expression: eye(3)
  //  Referenced by: '<Root>/Data Store Memory38'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Expression: eye(3)
  //  Referenced by: '<Root>/Data Store Memory39'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Expression: zeros(3,1)
  //  Referenced by: '<Root>/Data Store Memory4'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory40'

  0.0,

  // Expression: zeros(3,1)
  //  Referenced by: '<Root>/Data Store Memory41'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory42'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory43'

  0.0,

  // Expression: [[1; 0; 0; 0], [0; 0; 0; 0]]
  //  Referenced by: '<Root>/Data Store Memory44'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [1;0;0;0]
  //  Referenced by: '<Root>/Data Store Memory45'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: eye(3)
  //  Referenced by: '<Root>/Data Store Memory46'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Expression: zeros(6,1)
  //  Referenced by: '<Root>/Data Store Memory47'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(6,1)
  //  Referenced by: '<Root>/Data Store Memory48'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(3,1)
  //  Referenced by: '<Root>/Data Store Memory49'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(3,1)
  //  Referenced by: '<Root>/Data Store Memory5'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(6,1)
  //  Referenced by: '<Root>/Data Store Memory50'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(6,1)
  //  Referenced by: '<Root>/Data Store Memory51'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(6,1)
  //  Referenced by: '<Root>/Data Store Memory52'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(6,1)
  //  Referenced by: '<Root>/Data Store Memory53'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory57'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory58'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory59'

  0.0,

  // Expression: [[1; 0; 0; 0], [0; 0; 0; 0]]
  //  Referenced by: '<Root>/Data Store Memory6'

  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory60'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory61'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory62'

  0.0,

  // Expression: zeros(7,1)
  //  Referenced by: '<Root>/Data Store Memory63'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(7,1)
  //  Referenced by: '<Root>/Data Store Memory64'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [1; 0; 0; 0]
  //  Referenced by: '<Root>/Data Store Memory7'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: eye(3)
  //  Referenced by: '<Root>/Data Store Memory8'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Expression: zeros(3,1)
  //  Referenced by: '<Root>/Data Store Memory9'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/RED_Tz1'

  0.0,

  // Expression: zeros(6*6,1)
  //  Referenced by: '<Root>/RED_Tz10'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

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

  // Expression: [0;0;0;0;0;0]
  //  Referenced by: '<Root>/RED_Tz6'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

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

  // Expression: [0;0;0;0;0;0;]
  //  Referenced by: '<Root>/Universal_Time22'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0,0,0]
  //  Referenced by: '<Root>/Universal_Time23'

  { 0.0, 0.0, 0.0 },

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

  // Expression: zeros(6*6,1)
  //  Referenced by: '<Root>/Universal_Time36'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0;0;0;0;0;0]
  //  Referenced by: '<Root>/Universal_Time39'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0;0;0;0;0;0;0;0;0]
  //  Referenced by: '<Root>/Universal_Time4'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(6*6,1)
  //  Referenced by: '<Root>/Universal_Time40'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time41'

  0.0,

  // Expression: [init_states_RED';0;0;0;0;0;0]
  //  Referenced by: '<Root>/Universal_Time42'

  { 3.2, 2.1, -2.6975403981943264, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [init_states_BLACK';0;0;0;0;0;0]
  //  Referenced by: '<Root>/Universal_Time43'

  { 1.7, 1.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [init_states_BLUE';0;0;0;0;0;0]
  //  Referenced by: '<Root>/Universal_Time44'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Universal_Time45'

  0.0,

  // Expression: [0;0;0;0;0;0;]
  //  Referenced by: '<Root>/Universal_Time46'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time5'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time6'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<Root>/Universal_Time8'

  { 0.0, 0.0, 0.0 },

  // Expression: [0 0 0]
  //  Referenced by: '<Root>/Universal_Time9'

  { 0.0, 0.0, 0.0 },

  // Expression: "Target: Hello"
  //  Referenced by: '<S215>/String Constant1'

  "Target: Hello",

  // Expression: "Obstacle: Hello"
  //  Referenced by: '<S216>/String Constant2'

  "Obstacle: Hello",

  // Computed Parameter: RED_Tz3_InitialValue
  //  Referenced by: '<Root>/RED_Tz3'

  "",

  // Computed Parameter: UDPSend1_Port
  //  Referenced by: '<S215>/UDP Send1'

  55000,

  // Computed Parameter: UDPSend2_Port
  //  Referenced by: '<S216>/UDP Send2'

  55000,

  // Computed Parameter: UDPSend3_Port
  //  Referenced by: '<S217>/UDP Send3'

  55000,

  // Computed Parameter: ReceivePhaseSpaceData_Port
  //  Referenced by: '<S224>/Receive PhaseSpace Data'

  31534,

  // Computed Parameter: Delay_InitialCondition_j
  //  Referenced by: '<S229>/Delay'

  0,

  // Computed Parameter: Delay1_InitialCondition_d
  //  Referenced by: '<S229>/Delay1'

  0,

  // Computed Parameter: Delay2_InitialCondition_ak
  //  Referenced by: '<S229>/Delay2'

  0,

  // Computed Parameter: UDPReceive_Port
  //  Referenced by: '<S229>/UDP Receive'

  33001,

  // Computed Parameter: UDPReceive2_Port
  //  Referenced by: '<S229>/UDP Receive2'

  33002,

  // Computed Parameter: UDPReceive3_Port
  //  Referenced by: '<S229>/UDP Receive3'

  33003,

  // Computed Parameter: UDPReceive1_Port
  //  Referenced by: '<S279>/UDP Receive1'

  30172,

  // Computed Parameter: UDPSend_Port
  //  Referenced by: '<S288>/UDP Send'

  46875,

  // Computed Parameter: UDPSend_Port_g
  //  Referenced by: '<S18>/UDP Send'

  48291,

  // Start of '<S255>/Enabled Subsystem'
  {
    // Computed Parameter: dydt_Y0
    //  Referenced by: '<S261>/dy//dt'

    0.0,

    // Expression: 0.1
    //  Referenced by: '<S261>/Constant2'

    0.1,

    // Expression: 0.0
    //  Referenced by: '<S261>/Delay1'

    0.0
  }
  ,

  // End of '<S255>/Enabled Subsystem'

  // Start of '<S254>/Enabled Subsystem'
  {
    // Computed Parameter: dydt_Y0
    //  Referenced by: '<S259>/dy//dt'

    0.0,

    // Expression: 0.1
    //  Referenced by: '<S259>/Constant2'

    0.1,

    // Expression: 0.0
    //  Referenced by: '<S259>/Delay1'

    0.0
  }
  ,

  // End of '<S254>/Enabled Subsystem'

  // Start of '<S245>/Enabled Subsystem'
  {
    // Computed Parameter: dydt_Y0
    //  Referenced by: '<S251>/dy//dt'

    0.0,

    // Expression: 0.1
    //  Referenced by: '<S251>/Constant2'

    0.1,

    // Expression: 0.0
    //  Referenced by: '<S251>/Delay1'

    0.0
  }
  ,

  // End of '<S245>/Enabled Subsystem'

  // Start of '<S244>/Enabled Subsystem'
  {
    // Computed Parameter: dydt_Y0
    //  Referenced by: '<S249>/dy//dt'

    0.0,

    // Expression: 0.1
    //  Referenced by: '<S249>/Constant2'

    0.1,

    // Expression: 0.0
    //  Referenced by: '<S249>/Delay1'

    0.0
  }
  ,

  // End of '<S244>/Enabled Subsystem'

  // Start of '<S235>/Enabled Subsystem'
  {
    // Computed Parameter: dydt_Y0
    //  Referenced by: '<S241>/dy//dt'

    0.0,

    // Expression: 0.1
    //  Referenced by: '<S241>/Constant2'

    0.1,

    // Expression: 0.0
    //  Referenced by: '<S241>/Delay1'

    0.0
  }
  ,

  // End of '<S235>/Enabled Subsystem'

  // Start of '<S234>/Enabled Subsystem'
  {
    // Computed Parameter: dydt_Y0
    //  Referenced by: '<S239>/dy//dt'

    0.0,

    // Expression: 0.1
    //  Referenced by: '<S239>/Constant2'

    0.1,

    // Expression: 0.0
    //  Referenced by: '<S239>/Delay1'

    0.0
  }
  ,

  // End of '<S234>/Enabled Subsystem'

  // Start of '<S5>/Change RED Behavior'
  {
    // Computed Parameter: Constant1_Value
    //  Referenced by: '<S178>/Constant1'

    1,

    // Computed Parameter: UDPSend_Port
    //  Referenced by: '<S178>/UDP Send'

    33001
  }
  ,

  // End of '<S5>/Change RED Behavior'

  // Start of '<S5>/Change BLUE Behavior'
  {
    // Computed Parameter: Constant1_Value
    //  Referenced by: '<S177>/Constant1'

    1,

    // Computed Parameter: UDPSend_Port
    //  Referenced by: '<S177>/UDP Send'

    33003
  }
  ,

  // End of '<S5>/Change BLUE Behavior'

  // Start of '<S5>/Change BLACK Behavior'
  {
    // Computed Parameter: Constant1_Value
    //  Referenced by: '<S176>/Constant1'

    1,

    // Computed Parameter: UDPSend_Port
    //  Referenced by: '<S176>/UDP Send'

    33002
  }
  ,

  // End of '<S5>/Change BLACK Behavior'

  // Start of '<S4>/Custom Control (ARM)'
  {
    // Expression: 0
    //  Referenced by: '<S124>/Zero'

    0.0
  }
  ,

  // End of '<S4>/Custom Control (ARM)'

  // Start of '<S4>/Default LQR Control (BLACK)'
  {
    // Mask Parameter: DiscreteDerivative_ICPrevScaled
    //  Referenced by: '<S138>/UD'

    0.0,

    // Mask Parameter: DiscreteDerivative1_ICPrevScale
    //  Referenced by: '<S139>/UD'

    0.0,

    // Mask Parameter: DiscreteDerivative2_ICPrevScale
    //  Referenced by: '<S140>/UD'

    0.0,

    // Computed Parameter: TSamp_WtEt
    //  Referenced by: '<S138>/TSamp'

    20.0,

    // Computed Parameter: TSamp_WtEt_l
    //  Referenced by: '<S139>/TSamp'

    20.0,

    // Computed Parameter: TSamp_WtEt_o
    //  Referenced by: '<S140>/TSamp'

    20.0
  }
  ,

  // End of '<S4>/Default LQR Control (BLACK)'

  // Start of '<S4>/Default PD Control (BLACK)'
  {
    // Mask Parameter: DiscreteDerivative_ICPrevScaled
    //  Referenced by: '<S161>/UD'

    0.0,

    // Mask Parameter: DiscreteDerivative1_ICPrevScale
    //  Referenced by: '<S162>/UD'

    0.0,

    // Mask Parameter: DiscreteDerivative2_ICPrevScale
    //  Referenced by: '<S163>/UD'

    0.0,

    // Computed Parameter: TSamp_WtEt
    //  Referenced by: '<S161>/TSamp'

    20.0,

    // Computed Parameter: TSamp_WtEt_l
    //  Referenced by: '<S162>/TSamp'

    20.0,

    // Computed Parameter: TSamp_WtEt_o
    //  Referenced by: '<S163>/TSamp'

    20.0
  }
  ,

  // End of '<S4>/Default PD Control (BLACK)'

  // Start of '<S4>/Disable Thrusters (RED)'
  {
    // Expression: 0
    //  Referenced by: '<S135>/Zero'

    0.0
  }
  ,

  // End of '<S4>/Disable Thrusters (RED)'

  // Start of '<S1>/Phase #5: Hold Home'
  {
    // Expression: 0
    //  Referenced by: '<S25>/Constant11'

    0.0,

    // Expression: 0
    //  Referenced by: '<S25>/Constant12'

    0.0,

    // Expression: 0
    //  Referenced by: '<S25>/Constant14'

    0.0,

    // Expression: 0
    //  Referenced by: '<S25>/Constant15'

    0.0,

    // Expression: 0
    //  Referenced by: '<S25>/Constant18'

    0.0,

    // Expression: 2
    //  Referenced by: '<S25>/Constant4'

    2.0,

    // Expression: 2
    //  Referenced by: '<S25>/Constant5'

    2.0,

    // Expression: 1
    //  Referenced by: '<S25>/Constant6'

    1.0,

    // Expression: 2
    //  Referenced by: '<S25>/Constant8'

    2.0,

    // Expression: 0
    //  Referenced by: '<S25>/Puck State1'

    0.0,

    // Expression: pi/2
    //  Referenced by: '<S59>/Constant3'

    1.5707963267948966,

    // Expression: pi/2
    //  Referenced by: '<S59>/Constant1'

    1.5707963267948966,

    // Expression: 0
    //  Referenced by: '<S59>/Constant2'

    0.0
  }
  ,

  // End of '<S1>/Phase #5: Hold Home'

  // Start of '<S1>/Phase #4: Return Home'
  {
    // Expression: 0
    //  Referenced by: '<S24>/Constant11'

    0.0,

    // Expression: 0
    //  Referenced by: '<S24>/Constant12'

    0.0,

    // Expression: 0
    //  Referenced by: '<S24>/Constant14'

    0.0,

    // Expression: 0
    //  Referenced by: '<S24>/Constant15'

    0.0,

    // Expression: 0
    //  Referenced by: '<S24>/Constant18'

    0.0,

    // Expression: 2
    //  Referenced by: '<S24>/Constant4'

    2.0,

    // Expression: 2
    //  Referenced by: '<S24>/Constant5'

    2.0,

    // Expression: 1
    //  Referenced by: '<S24>/Constant6'

    1.0,

    // Expression: 2
    //  Referenced by: '<S24>/Constant8'

    2.0,

    // Expression: 0
    //  Referenced by: '<S24>/Puck State1'

    0.0,

    // Expression: pi/2
    //  Referenced by: '<S55>/Constant3'

    1.5707963267948966,

    // Expression: pi/2
    //  Referenced by: '<S55>/Constant1'

    1.5707963267948966,

    // Expression: 0
    //  Referenced by: '<S55>/Constant2'

    0.0
  }
  ,

  // End of '<S1>/Phase #4: Return Home'

  // Start of '<S1>/Phase #1: Start Floating '
  {
    // Expression: 0
    //  Referenced by: '<S21>/Constant1'

    0.0,

    // Expression: 0
    //  Referenced by: '<S21>/Constant2'

    0.0,

    // Expression: 0
    //  Referenced by: '<S21>/Constant3'

    0.0,

    // Expression: 0
    //  Referenced by: '<S21>/Constant4'

    0.0,

    // Expression: 0
    //  Referenced by: '<S21>/Constant5'

    0.0,

    // Expression: 0
    //  Referenced by: '<S21>/Constant6'

    0.0,

    // Expression: 0
    //  Referenced by: '<S21>/Constant7'

    0.0,

    // Expression: 0
    //  Referenced by: '<S21>/Constant8'

    0.0,

    // Expression: 0
    //  Referenced by: '<S21>/Puck State1'

    0.0,

    // Expression: 1
    //  Referenced by: '<S21>/Puck State'

    1.0,

    // Expression: "Chaser: Running Phase 1"
    //  Referenced by: '<S21>/String Constant'

    "Chaser: Running Phase 1"
  }
  ,

  // End of '<S1>/Phase #1: Start Floating '

  // Start of '<S1>/Phase #0: Synchronization'
  {
    // Expression: 0
    //  Referenced by: '<S20>/Constant1'

    0.0,

    // Expression: 0
    //  Referenced by: '<S20>/Constant2'

    0.0,

    // Expression: 0
    //  Referenced by: '<S20>/Constant3'

    0.0,

    // Expression: 0
    //  Referenced by: '<S20>/Constant4'

    0.0,

    // Expression: 0
    //  Referenced by: '<S20>/Constant5'

    0.0,

    // Expression: 0
    //  Referenced by: '<S20>/Constant6'

    0.0,

    // Expression: 0
    //  Referenced by: '<S20>/Constant7'

    0.0,

    // Expression: 0
    //  Referenced by: '<S20>/Constant8'

    0.0,

    // Expression: 0
    //  Referenced by: '<S20>/Puck State1'

    0.0,

    // Expression: 0
    //  Referenced by: '<S20>/Puck State'

    0.0,

    // Expression: "Chaser: Running Phase 0"
    //  Referenced by: '<S20>/String Constant'

    "Chaser: Running Phase 0"
  }
  // End of '<S1>/Phase #0: Synchronization'
};

//
// File trailer for generated code.
//
// [EOF]
//
