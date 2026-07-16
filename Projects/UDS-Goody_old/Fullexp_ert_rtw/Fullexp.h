//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Fullexp.h
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
#ifndef Fullexp_h_
#define Fullexp_h_
#include <cstdio>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "coder_posix_time.h"
#include "DAHostLib_Network.h"
#include "custom_data_logger.h"
#include "gpio_control.h"
#include "MW_I2C.h"
#include "dynamixel_functions.h"
#include "dynamixel_sdk.h"
#include "resource_headers.h"
#include "Fullexp_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

extern "C"
{

#include "rtGetInf.h"

}

#include <stddef.h>

// Block states (default storage) for system '<S4>/Change BLACK Behavior'
struct DW_ChangeBLACKBehavior_Fullex_T {
  real_T UDPSend_NetworkLib[137];      // '<S168>/UDP Send'
};

// Block signals for system '<S193>/Enabled Subsystem'
struct B_EnabledSubsystem_Fullexp_T {
  real_T Delay[3];                     // '<S198>/Delay'
  real_T Delay1[3];                    // '<S198>/Delay1'
  real_T ema[3];                       // '<S198>/MATLAB Function'
};

// Block states (default storage) for system '<S193>/Enabled Subsystem'
struct DW_EnabledSubsystem_Fullexp_T {
  real_T Delay_DSTATE[3];              // '<S198>/Delay'
  real_T Delay1_DSTATE[3];             // '<S198>/Delay1'
  boolean_T icLoad;                    // '<S198>/Delay'
  boolean_T EnabledSubsystem_MODE;     // '<S193>/Enabled Subsystem'
};

// Block signals for system '<S194>/Enabled Subsystem'
struct B_EnabledSubsystem_Fullexp_b_T {
  real_T Delay[3];                     // '<S200>/Delay'
  real_T Delay1[3];                    // '<S200>/Delay1'
  real_T ema[3];                       // '<S200>/MATLAB Function'
};

// Block states (default storage) for system '<S194>/Enabled Subsystem'
struct DW_EnabledSubsystem_Fullexp_m_T {
  real_T Delay_DSTATE[3];              // '<S200>/Delay'
  real_T Delay1_DSTATE[3];             // '<S200>/Delay1'
  boolean_T icLoad;                    // '<S200>/Delay'
  boolean_T EnabledSubsystem_MODE;     // '<S194>/Enabled Subsystem'
};

// Block signals for system '<S239>/Pseudoinverse1'
struct B_Pseudoinverse1_Fullexp_T {
  real_T Pseudoinverse1[24];           // '<S239>/Pseudoinverse1'
};

// Block states (default storage) for system '<S239>/Pseudoinverse1'
struct DW_Pseudoinverse1_Fullexp_T {
  dsp_simulink_Pseudoinverse_Fu_T obj; // '<S239>/Pseudoinverse1'
  boolean_T objisempty;                // '<S239>/Pseudoinverse1'
};

// Block signals (default storage)
struct B_Fullexp_T {
  real_T b_u1[1084];
  smSS6fEwaptVbzYAOdOZgjB_Fulle_T obj;
  smSS6fEwaptVbzYAOdOZgjB_Fulle_T obj_m;
  smSS6fEwaptVbzYAOdOZgjB_Fulle_T obj_c;
  real_T Clock;                        // '<Root>/Clock'
  real_T Merge1[3];                    // '<S3>/Merge1'
  real_T Merge2[3];                    // '<S3>/Merge2'
  real_T Merge[3];                     // '<S3>/Merge'
  real_T TmpSignalConversionAtUDPSendInp[10];
  real_T duty_cycles[8];               // '<S260>/MATLAB Function5'
  real_T ThrustPer_Final[8];           // '<S268>/ThrustPer_Final'
  real_T In1;                          // '<S267>/In1'
  real_T duty_cycles_p[8];             // '<S248>/MATLAB Function5'
  real_T ThrustPer_Final_h[8];         // '<S256>/ThrustPer_Final'
  real_T In1_g;                        // '<S255>/In1'
  real_T duty_cycles_l[8];             // '<S236>/MATLAB Function5'
  real_T ThrustPer_Final_h5[8];        // '<S244>/ThrustPer_Final'
  real_T In1_g2;                       // '<S243>/In1'
  real_T TmpSignalConversionAtUDPSendI_o[28];
  real_T x_est[13];                    // '<S23>/MATLAB Function1'
  real_T V_est[36];                    // '<S23>/MATLAB Function1'
  real_T x_est_d[14];                  // '<S22>/MATLAB Function1'
  real_T V_est_n[36];                  // '<S22>/MATLAB Function1'
  real_T x_est_m[9];                   // '<S17>/MATLAB Function1'
  real_T x_est_dp[13];                 // '<S16>/MATLAB Function1'
  real_T ReceivePhaseSpaceData_o1[19]; // '<S183>/Receive PhaseSpace Data'
  real_T ConvertBLAXfrommmtom;        // '<S184>/Convert BLAX from [mm] to [m]'
  real_T ConvertBLUXfrommmtom;        // '<S185>/Convert BLUX from [mm] to [m]'
  real_T ConvertREDXfrommmtom;        // '<S186>/Convert REDX from [mm] to [m]'
  real_T Clock_o;                      // '<S183>/Clock'
  real_T dy[3];                        // '<S220>/MATLAB Function'
  real_T dy_l[3];                      // '<S218>/MATLAB Function'
  real_T y2y1;                         // '<S216>/y2-y1'
  real_T dy_c[3];                      // '<S210>/MATLAB Function'
  real_T dy_e[3];                      // '<S208>/MATLAB Function'
  real_T y2y1_o;                       // '<S206>/y2-y1'
  real_T dy_i[3];                      // '<S200>/MATLAB Function'
  real_T dy_k[3];                      // '<S198>/MATLAB Function'
  real_T y2y1_ob;                      // '<S196>/y2-y1'
  real_T Subtract;                     // '<S190>/Subtract'
  real_T Memory;                       // '<S189>/Memory'
  real_T x_est_c[14];                  // '<S5>/MATLAB Function1'
  real32_T UDPReceive1_o1[4];          // '<S226>/UDP Receive1'
  int32_T UDPReceive_o1;               // '<S188>/UDP Receive'
  int32_T UDPReceive2_o1;              // '<S188>/UDP Receive2'
  int32_T UDPReceive3_o1;              // '<S188>/UDP Receive3'
  uint8_T StringtoASCII[31];           // '<S176>/String to ASCII'
  uint8_T StringtoASCII2[31];          // '<S175>/String to ASCII2'
  uint8_T StringtoASCII1[31];          // '<S174>/String to ASCII1'
  boolean_T RelationalOperator1;       // '<S187>/Relational Operator1'
  B_Pseudoinverse1_Fullexp_T Pseudoinverse1_pn;// '<S239>/Pseudoinverse1'
  B_Pseudoinverse1_Fullexp_T Pseudoinverse1_p;// '<S239>/Pseudoinverse1'
  B_Pseudoinverse1_Fullexp_T Pseudoinverse1;// '<S239>/Pseudoinverse1'
  B_EnabledSubsystem_Fullexp_b_T EnabledSubsystem_a;// '<S214>/Enabled Subsystem' 
  B_EnabledSubsystem_Fullexp_T EnabledSubsystem_k;// '<S213>/Enabled Subsystem'
  B_EnabledSubsystem_Fullexp_b_T EnabledSubsystem_g;// '<S204>/Enabled Subsystem' 
  B_EnabledSubsystem_Fullexp_T EnabledSubsystem_l;// '<S203>/Enabled Subsystem'
  B_EnabledSubsystem_Fullexp_b_T EnabledSubsystem_n;// '<S194>/Enabled Subsystem' 
  B_EnabledSubsystem_Fullexp_T EnabledSubsystem_m;// '<S193>/Enabled Subsystem'
};

// Block states (default storage) for system '<Root>'
struct DW_Fullexp_T {
  nvidiacoder_sensors_BMI160Blo_T obj; // '<S178>/Gyroscope//Accelerometer'
  Dynamixel_Controller_Fullexp_T obj_n;
  // '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
  GPIO_Write_Fullexp_T obj_c;          // '<S177>/GPIO Write1'
  ReadArm_Position_Rates_Fullex_T obj_d;
                     // '<S180>/Read Joint Positions using  Dynamixel Encoders'
  IdentifyPlatform_Fullexp_T obj_dk;   // '<S222>/WhoAmI'
  CustomDataLogger_Fullexp_T obj_b;    // '<S172>/MATLAB System'
  real_T Delay_DSTATE;                 // '<Root>/Delay'
  real_T Delay1_DSTATE[14];            // '<S5>/Delay1'
  real_T Delay_DSTATE_d[144];          // '<S5>/Delay'
  real_T Delay1_DSTATE_e[13];          // '<S16>/Delay1'
  real_T Delay_DSTATE_k[144];          // '<S16>/Delay'
  real_T Delay1_DSTATE_o[9];           // '<S17>/Delay1'
  real_T Delay2_DSTATE[9];             // '<S17>/Delay2'
  real_T Delay_DSTATE_n[144];          // '<S17>/Delay'
  real_T Delay1_DSTATE_b[14];          // '<S22>/Delay1'
  real_T Delay_DSTATE_p[144];          // '<S22>/Delay'
  real_T Delay2_DSTATE_d[36];          // '<S22>/Delay2'
  real_T Delay1_DSTATE_er[13];         // '<S23>/Delay1'
  real_T Delay_DSTATE_l[144];          // '<S23>/Delay'
  real_T Delay2_DSTATE_p[36];          // '<S23>/Delay2'
  real_T Delay_DSTATE_b;               // '<S262>/Delay'
  real_T Delay_DSTATE_kf;              // '<S250>/Delay'
  real_T Delay_DSTATE_kz;              // '<S238>/Delay'
  real_T Delay2_DSTATE_j;              // '<S192>/Delay2'
  real_T Delay1_DSTATE_i;              // '<S192>/Delay1'
  real_T Delay1_DSTATE_g[3];           // '<S194>/Delay1'
  real_T Delay1_DSTATE_bv[3];          // '<S193>/Delay1'
  real_T Delay2_DSTATE_l;              // '<S202>/Delay2'
  real_T Delay1_DSTATE_l;              // '<S202>/Delay1'
  real_T Delay1_DSTATE_m[3];           // '<S204>/Delay1'
  real_T Delay1_DSTATE_lv[3];          // '<S203>/Delay1'
  real_T Delay2_DSTATE_l0;             // '<S212>/Delay2'
  real_T Delay1_DSTATE_ld;             // '<S212>/Delay1'
  real_T Delay1_DSTATE_c[3];           // '<S214>/Delay1'
  real_T Delay1_DSTATE_cq[3];          // '<S213>/Delay1'
  real_T Delay_DSTATE_o;               // '<S180>/Delay'
  real_T Delay1_DSTATE_cg;             // '<S180>/Delay1'
  real_T Delay2_DSTATE_h;              // '<S180>/Delay2'
  real_T UD_DSTATE;                    // '<S150>/UD'
  real_T UD_DSTATE_e;                  // '<S151>/UD'
  real_T UD_DSTATE_a;                  // '<S152>/UD'
  real_T UD_DSTATE_l;                  // '<S136>/UD'
  real_T UD_DSTATE_k;                  // '<S137>/UD'
  real_T UD_DSTATE_h;                  // '<S138>/UD'
  real_T UD_DSTATE_o;                  // '<S159>/UD'
  real_T UD_DSTATE_n;                  // '<S160>/UD'
  real_T UD_DSTATE_hu;                 // '<S161>/UD'
  real_T UD_DSTATE_j;                  // '<S131>/UD'
  real_T UD_DSTATE_c;                  // '<S132>/UD'
  real_T UD_DSTATE_d;                  // '<S133>/UD'
  real_T UD_DSTATE_eh;                 // '<S154>/UD'
  real_T UD_DSTATE_hv;                 // '<S155>/UD'
  real_T UD_DSTATE_kv;                 // '<S156>/UD'
  real_T UD_DSTATE_aq;                 // '<S141>/UD'
  real_T UD_DSTATE_p;                  // '<S142>/UD'
  real_T UD_DSTATE_pr;                 // '<S143>/UD'
  real_T UD_DSTATE_eg;                 // '<S164>/UD'
  real_T UD_DSTATE_cd;                 // '<S165>/UD'
  real_T UD_DSTATE_hd;                 // '<S166>/UD'
  real_T UDPSend_NetworkLib[137];      // '<S26>/UDP Send'
  real_T Vis_x[3];                     // '<Root>/Data Store Memory15'
  real_T QMEKFP[144];                  // '<Root>/Data Store Memory18'
  real_T STQMEKFP[144];                // '<Root>/Data Store Memory21'
  real_T DQMEKFP[144];                 // '<Root>/Data Store Memory24'
  real_T STDQMEKFP[144];               // '<Root>/Data Store Memory27'
  real_T RMEKFP[144];                  // '<Root>/Data Store Memory30'
  real_T STRMEKFx[9];                  // '<Root>/Data Store Memory32'
  real_T STRMEKFP[144];                // '<Root>/Data Store Memory33'
  real_T STRMEKFt;                     // '<Root>/Data Store Memory34'
  real_T Vis_yaw;                      // '<Root>/Data Store Memory37'
  real_T RMEKFR[9];                    // '<Root>/Data Store Memory38'
  real_T STRMEKFR[9];                  // '<Root>/Data Store Memory39'
  real_T Conf;                         // '<Root>/Data Store Memory40'
  real_T BLUE_Control_Law_Enabler;     // '<Root>/RED_Tz1'
  real_T ARM_Control_Mode;             // '<Root>/RED_Tz15'
  real_T RED_Control_Law_Enabler;      // '<Root>/RED_Tz20'
  real_T RED_Path_Planner_Selection;   // '<Root>/RED_Tz25'
  real_T ARM_Control_Law_Enabler;      // '<Root>/RED_Tz38'
  real_T Float_State;                  // '<Root>/RED_Tz7'
  real_T BLACK_Control_Law_Enabler;    // '<Root>/RED_Tz8'
  real_T BLACK_Path_Planner_Selection; // '<Root>/RED_Tz9'
  real_T Univ_Time;                    // '<Root>/Universal_Time'
  real_T BLACK_Measured_States[9];     // '<Root>/Universal_Time10'
  real_T BLUE_Desired_States[3];       // '<Root>/Universal_Time13'
  real_T BLUE_Thruster_ON_Count;       // '<Root>/Universal_Time14'
  real_T BLACK_Saturated_Controls[3];  // '<Root>/Universal_Time15'
  real_T RED_Thruster_ON_Count;        // '<Root>/Universal_Time16'
  real_T WhoAmI;                       // '<Root>/Universal_Time19'
  real_T isSim;                        // '<Root>/Universal_Time20'
  real_T ARM_Measured_States[6];       // '<Root>/Universal_Time24'
  real_T BLACK_Desired_States[3];      // '<Root>/Universal_Time25'
  real_T RED_Measured_States[9];       // '<Root>/Universal_Time26'
  real_T RED_Saturated_Controls[3];    // '<Root>/Universal_Time28'
  real_T RED_Desired_States[3];        // '<Root>/Universal_Time29'
  real_T BLACK_Thruster_ON_Count;      // '<Root>/Universal_Time3'
  real_T RED_IMU_Measurements[3];      // '<Root>/Universal_Time31'
  real_T BLACK_IMU_Measurements[3];    // '<Root>/Universal_Time33'
  real_T BLUE_IMU_Measurements[3];     // '<Root>/Universal_Time34'
  real_T BLUE_Measured_States[9];      // '<Root>/Universal_Time4'
  real_T BLUE_Saturated_Controls[3];   // '<Root>/Universal_Time6'
  real_T ARM_Desired_States[3];        // '<Root>/Universal_Time8'
  real_T UDPSend_NetworkLib_m[137];    // '<S232>/UDP Send'
  real_T freq;                         // '<S23>/MATLAB Function1'
  real_T freq_n;                       // '<S22>/MATLAB Function1'
  real_T UDPReceive1_NetworkLib[137];  // '<S226>/UDP Receive1'
  real_T freq_e;                       // '<S17>/MATLAB Function1'
  real_T freq_i;                       // '<S16>/MATLAB Function1'
  real_T ReceivePhaseSpaceData_NetworkLi[137];// '<S183>/Receive PhaseSpace Data' 
  real_T UDPReceive_NetworkLib[137];   // '<S188>/UDP Receive'
  real_T UDPReceive2_NetworkLib[137];  // '<S188>/UDP Receive2'
  real_T UDPReceive3_NetworkLib[137];  // '<S188>/UDP Receive3'
  real_T Memory_PreviousInput;         // '<S189>/Memory'
  real_T UDPSend3_NetworkLib[137];     // '<S176>/UDP Send3'
  real_T UDPSend2_NetworkLib[137];     // '<S175>/UDP Send2'
  real_T UDPSend1_NetworkLib[137];     // '<S174>/UDP Send1'
  real_T freq_l;                       // '<S5>/MATLAB Function1'
  char_T RED_Logger[256];              // '<Root>/RED_Tz3'
  int32_T Delay_DSTATE_i[5];           // '<S188>/Delay'
  int32_T Delay1_DSTATE_h[5];          // '<S188>/Delay1'
  int32_T Delay2_DSTATE_hq[5];         // '<S188>/Delay2'
  uint32_T state[625];                 // '<S23>/MATLAB Function1'
  uint32_T state_j[625];               // '<S22>/MATLAB Function1'
  uint32_T state_p[625];               // '<S17>/MATLAB Function1'
  uint32_T state_a[625];               // '<S16>/MATLAB Function1'
  uint32_T state_k[625];               // '<S5>/MATLAB Function1'
  int8_T Ifperforminganexperimentgrabthe;
  // '<S13>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 
  uint8_T pauseState;                  // '<S178>/Gyroscope//Accelerometer'
  boolean_T freq_not_empty;            // '<S23>/MATLAB Function1'
  boolean_T savedTime_not_empty;       // '<S23>/MATLAB Function1'
  boolean_T freq_not_empty_n;          // '<S22>/MATLAB Function1'
  boolean_T savedTime_not_empty_k;     // '<S22>/MATLAB Function1'
  boolean_T freq_not_empty_l;          // '<S17>/MATLAB Function1'
  boolean_T savedTime_not_empty_ki;    // '<S17>/MATLAB Function1'
  boolean_T freq_not_empty_a;          // '<S16>/MATLAB Function1'
  boolean_T savedTime_not_empty_g;     // '<S16>/MATLAB Function1'
  boolean_T freq_not_empty_m;          // '<S5>/MATLAB Function1'
  boolean_T savedTime_not_empty_d;     // '<S5>/MATLAB Function1'
  DW_Pseudoinverse1_Fullexp_T Pseudoinverse1_pn;// '<S239>/Pseudoinverse1'
  DW_Pseudoinverse1_Fullexp_T Pseudoinverse1_p;// '<S239>/Pseudoinverse1'
  DW_Pseudoinverse1_Fullexp_T Pseudoinverse1;// '<S239>/Pseudoinverse1'
  DW_EnabledSubsystem_Fullexp_m_T EnabledSubsystem_a;// '<S214>/Enabled Subsystem' 
  DW_EnabledSubsystem_Fullexp_T EnabledSubsystem_k;// '<S213>/Enabled Subsystem' 
  DW_EnabledSubsystem_Fullexp_m_T EnabledSubsystem_g;// '<S204>/Enabled Subsystem' 
  DW_EnabledSubsystem_Fullexp_T EnabledSubsystem_l;// '<S203>/Enabled Subsystem' 
  DW_EnabledSubsystem_Fullexp_m_T EnabledSubsystem_n;// '<S194>/Enabled Subsystem' 
  DW_EnabledSubsystem_Fullexp_T EnabledSubsystem_m;// '<S193>/Enabled Subsystem' 
  DW_ChangeBLACKBehavior_Fullex_T ChangeREDBehavior;// '<S4>/Change RED Behavior' 
  DW_ChangeBLACKBehavior_Fullex_T ChangeBLUEBehavior;// '<S4>/Change BLUE Behavior' 
  DW_ChangeBLACKBehavior_Fullex_T ChangeBLACKBehavior;// '<S4>/Change BLACK Behavior' 
};

// Parameters for system: '<S1>/Phase #0: Synchronization'
struct P_Phase0Synchronization_Fulle_T_ {
  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S27>/Constant1'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S27>/Constant2'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<S27>/Constant3'

  real_T Constant4_Value;              // Expression: 0
                                          //  Referenced by: '<S27>/Constant4'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<S27>/Constant5'

  real_T Constant6_Value;              // Expression: 0
                                          //  Referenced by: '<S27>/Constant6'

  real_T Constant7_Value;              // Expression: 0
                                          //  Referenced by: '<S27>/Constant7'

  real_T Constant8_Value;              // Expression: 0
                                          //  Referenced by: '<S27>/Constant8'

  real_T PuckState_Value;              // Expression: 0
                                          //  Referenced by: '<S27>/Puck State'

  char_T StringConstant_String[256];   // Expression: "Chaser: Running Phase 0"
                                          //  Referenced by: '<S27>/String Constant'

};

// Parameters for system: '<S1>/Phase #4: Return Home'
struct P_Phase4ReturnHome_Fullexp_T_ {
  real_T Constant11_Value;             // Expression: 0
                                          //  Referenced by: '<S31>/Constant11'

  real_T Constant12_Value;             // Expression: 0
                                          //  Referenced by: '<S31>/Constant12'

  real_T Constant14_Value;             // Expression: 0
                                          //  Referenced by: '<S31>/Constant14'

  real_T Constant15_Value;             // Expression: 0
                                          //  Referenced by: '<S31>/Constant15'

  real_T Constant18_Value;             // Expression: 0
                                          //  Referenced by: '<S31>/Constant18'

  real_T Constant4_Value;              // Expression: 2
                                          //  Referenced by: '<S31>/Constant4'

  real_T Constant5_Value;              // Expression: 2
                                          //  Referenced by: '<S31>/Constant5'

  real_T Constant6_Value;              // Expression: 1
                                          //  Referenced by: '<S31>/Constant6'

  real_T Constant8_Value;              // Expression: 2
                                          //  Referenced by: '<S31>/Constant8'

  real_T Constant3_Value;              // Expression: pi/2
                                          //  Referenced by: '<S81>/Constant3'

  real_T Constant1_Value;              // Expression: pi/2
                                          //  Referenced by: '<S81>/Constant1'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S81>/Constant2'

};

// Parameters for system: '<S3>/Custom Control (RED)'
struct P_CustomControlRED_Fullexp_T_ {
  real_T Zero_Value;                   // Expression: 0
                                          //  Referenced by: '<S118>/Zero'

};

// Parameters for system: '<S3>/Disable Thrusters (BLACK)'
struct P_DisableThrustersBLACK_Fulle_T_ {
  real_T Zero_Value;                   // Expression: 0
                                          //  Referenced by: '<S127>/Zero'

};

// Parameters for system: '<S4>/Change BLACK Behavior'
struct P_ChangeBLACKBehavior_Fullexp_T_ {
  int32_T Constant1_Value;             // Computed Parameter: Constant1_Value
                                          //  Referenced by: '<S168>/Constant1'

  int32_T UDPSend_Port;                // Computed Parameter: UDPSend_Port
                                          //  Referenced by: '<S168>/UDP Send'

};

// Parameters for system: '<S193>/Enabled Subsystem'
struct P_EnabledSubsystem_Fullexp_T_ {
  real_T dydt_Y0;                      // Computed Parameter: dydt_Y0
                                          //  Referenced by: '<S198>/dy//dt'

  real_T Constant2_Value;              // Expression: 0.1
                                          //  Referenced by: '<S198>/Constant2'

  real_T Delay1_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S198>/Delay1'

};

// Parameters for system: '<S194>/Enabled Subsystem'
struct P_EnabledSubsystem_Fullexp_d_T_ {
  real_T dydt_Y0;                      // Computed Parameter: dydt_Y0
                                          //  Referenced by: '<S200>/dy//dt'

  real_T Constant2_Value;              // Expression: 0.1
                                          //  Referenced by: '<S200>/Constant2'

  real_T Delay1_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S200>/Delay1'

};

// Parameters (default storage)
struct P_Fullexp_T_ {
  real_T F_black_X_nominal;            // Variable: F_black_X_nominal
                                          //  Referenced by: '<S236>/MATLAB Function5'

  real_T F_black_Y_nominal;            // Variable: F_black_Y_nominal
                                          //  Referenced by: '<S236>/MATLAB Function5'

  real_T F_blue_X_nominal;             // Variable: F_blue_X_nominal
                                          //  Referenced by: '<S248>/MATLAB Function5'

  real_T F_blue_Y_nominal;             // Variable: F_blue_Y_nominal
                                          //  Referenced by: '<S248>/MATLAB Function5'

  real_T F_red_X_nominal;              // Variable: F_red_X_nominal
                                          //  Referenced by: '<S260>/MATLAB Function5'

  real_T F_red_Y_nominal;              // Variable: F_red_Y_nominal
                                          //  Referenced by: '<S260>/MATLAB Function5'

  real_T F_thrusters_BLACK[8];         // Variable: F_thrusters_BLACK
                                          //  Referenced by: '<S239>/MATLAB Function'

  real_T F_thrusters_BLUE[8];          // Variable: F_thrusters_BLUE
                                          //  Referenced by: '<S251>/MATLAB Function'

  real_T F_thrusters_RED[8];           // Variable: F_thrusters_RED
                                          //  Referenced by: '<S263>/MATLAB Function'

  real_T K_BLACK[18];                  // Variable: K_BLACK
                                          //  Referenced by: '<S119>/Constant2'

  real_T K_BLUE[18];                   // Variable: K_BLUE
                                          //  Referenced by: '<S120>/Constant2'

  real_T K_RED[18];                    // Variable: K_RED
                                          //  Referenced by: '<S121>/Constant2'

  real_T Kd_elarm;                     // Variable: Kd_elarm
                                          //  Referenced by: '<S147>/kd_elarm'

  real_T Kd_sharm;                     // Variable: Kd_sharm
                                          //  Referenced by: '<S148>/kd_sharm'

  real_T Kd_tb;                        // Variable: Kd_tb
                                          //  Referenced by: '<S123>/Gain5'

  real_T Kd_tblue;                     // Variable: Kd_tblue
                                          //  Referenced by: '<S124>/Gain5'

  real_T Kd_tr;                        // Variable: Kd_tr
                                          //  Referenced by: '<S125>/Gain5'

  real_T Kd_wrarm;                     // Variable: Kd_wrarm
                                          //  Referenced by: '<S149>/kd_wrarm'

  real_T Kd_xb;                        // Variable: Kd_xb
                                          //  Referenced by: '<S123>/Gain3'

  real_T Kd_xblue;                     // Variable: Kd_xblue
                                          //  Referenced by: '<S124>/Gain3'

  real_T Kd_xr;                        // Variable: Kd_xr
                                          //  Referenced by: '<S125>/Gain3'

  real_T Kd_yb;                        // Variable: Kd_yb
                                          //  Referenced by: '<S123>/Gain4'

  real_T Kd_yblue;                     // Variable: Kd_yblue
                                          //  Referenced by: '<S124>/Gain4'

  real_T Kd_yr;                        // Variable: Kd_yr
                                          //  Referenced by: '<S125>/Gain4'

  real_T Kp_elarm;                     // Variable: Kp_elarm
                                          //  Referenced by: '<S147>/kp_elarm'

  real_T Kp_sharm;                     // Variable: Kp_sharm
                                          //  Referenced by: '<S148>/kp_sharm'

  real_T Kp_tb;                        // Variable: Kp_tb
                                          //  Referenced by: '<S123>/Gain2'

  real_T Kp_tblue;                     // Variable: Kp_tblue
                                          //  Referenced by: '<S124>/Gain2'

  real_T Kp_tr;                        // Variable: Kp_tr
                                          //  Referenced by: '<S125>/Gain2'

  real_T Kp_wrarm;                     // Variable: Kp_wrarm
                                          //  Referenced by: '<S149>/kp_wrarm'

  real_T Kp_xb;                        // Variable: Kp_xb
                                          //  Referenced by: '<S123>/Gain'

  real_T Kp_xblue;                     // Variable: Kp_xblue
                                          //  Referenced by: '<S124>/Gain'

  real_T Kp_xr;                        // Variable: Kp_xr
                                          //  Referenced by: '<S125>/Gain'

  real_T Kp_yb;                        // Variable: Kp_yb
                                          //  Referenced by: '<S123>/Gain1'

  real_T Kp_yblue;                     // Variable: Kp_yblue
                                          //  Referenced by: '<S124>/Gain1'

  real_T Kp_yr;                        // Variable: Kp_yr
                                          //  Referenced by: '<S125>/Gain1'

  real_T P[144];                       // Variable: P
                                          //  Referenced by:
                                          //    '<S5>/Delay'
                                          //    '<S16>/Delay'
                                          //    '<S17>/Delay'
                                          //    '<S22>/Delay'
                                          //    '<S23>/Delay'

  real_T PWMFreq;                      // Variable: PWMFreq
                                          //  Referenced by:
                                          //    '<S26>/PWM Frequency'
                                          //    '<S236>/MATLAB Function1'
                                          //    '<S248>/MATLAB Function1'
                                          //    '<S260>/MATLAB Function8'
                                          //    '<S238>/Constant1'
                                          //    '<S250>/Constant1'
                                          //    '<S262>/Constant1'

  real_T Phase0_End;                   // Variable: Phase0_End
                                          //  Referenced by: '<S1>/Constant4'

  real_T Phase1_End;                   // Variable: Phase1_End
                                          //  Referenced by: '<S1>/Constant'

  real_T Phase2_End;                   // Variable: Phase2_End
                                          //  Referenced by:
                                          //    '<S1>/Constant1'
                                          //    '<S47>/Constant2'
                                          //    '<S58>/Constant2'
                                          //    '<S66>/Constant2'
                                          //    '<S78>/Constant2'
                                          //    '<S56>/Constant1'
                                          //    '<S72>/Constant1'

  real_T Phase3_End;                   // Variable: Phase3_End
                                          //  Referenced by: '<S1>/Constant2'

  real_T Phase3_SubPhase1_End;         // Variable: Phase3_SubPhase1_End
                                          //  Referenced by: '<S30>/Constant4'

  real_T Phase3_SubPhase2_End;         // Variable: Phase3_SubPhase2_End
                                          //  Referenced by:
                                          //    '<S30>/Constant1'
                                          //    '<S64>/Constant'

  real_T Phase3_SubPhase3_End;         // Variable: Phase3_SubPhase3_End
                                          //  Referenced by: '<S30>/Constant2'

  real_T Phase3_SubPhase4_End;         // Variable: Phase3_SubPhase4_End
                                          //  Referenced by: '<S30>/Constant3'

  real_T Phase4_End;                   // Variable: Phase4_End
                                          //  Referenced by: '<S1>/Constant3'

  real_T Phase5_End;                   // Variable: Phase5_End
                                          //  Referenced by: '<S1>/Constant6'

  real_T Tz_lim_elarm;                 // Variable: Tz_lim_elarm
                                          //  Referenced by: '<S146>/Saturation1'

  real_T Tz_lim_sharm;                 // Variable: Tz_lim_sharm
                                          //  Referenced by: '<S146>/Saturation'

  real_T Tz_lim_wrarm;                 // Variable: Tz_lim_wrarm
                                          //  Referenced by: '<S146>/Saturation3'

  real_T baseRate;                     // Variable: baseRate
                                          //  Referenced by:
                                          //    '<S93>/MATLAB Function'
                                          //    '<S94>/MATLAB Function'
                                          //    '<S180>/Read Joint Positions using  Dynamixel Encoders'
                                          //    '<S222>/WhoAmI'
                                          //    '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T dataRate;                     // Variable: dataRate
                                          //  Referenced by:
                                          //    '<S192>/Constant'
                                          //    '<S202>/Constant'
                                          //    '<S212>/Constant'

  real_T home_states_BLACK[3];         // Variable: home_states_BLACK
                                          //  Referenced by:
                                          //    '<S82>/Desired States (BLACK)'
                                          //    '<S86>/Desired States (BLACK)'
                                          //    '<S74>/Constant'

  real_T home_states_BLUE[3];          // Variable: home_states_BLUE
                                          //  Referenced by:
                                          //    '<S83>/Desired States (BLUE)'
                                          //    '<S87>/Desired States (BLUE)'

  real_T home_states_RED[3];           // Variable: home_states_RED
                                          //  Referenced by:
                                          //    '<S84>/Constant2'
                                          //    '<S88>/Constant2'
                                          //    '<S76>/Constant'

  real_T init_states_BLACK[3];         // Variable: init_states_BLACK
                                          //  Referenced by:
                                          //    '<S35>/Desired States (BLACK)'
                                          //    '<S43>/Constant'

  real_T init_states_BLUE[3];          // Variable: init_states_BLUE
                                          //  Referenced by: '<S36>/Desired States (BLUE)'

  real_T init_states_RED[3];           // Variable: init_states_RED
                                          //  Referenced by:
                                          //    '<S37>/Constant2'
                                          //    '<S45>/Constant'
                                          //    '<S53>/Constant'
                                          //    '<S53>/Constant1'
                                          //    '<S53>/Constant4'
                                          //    '<S63>/Constant'

  real_T platformSelection;            // Variable: platformSelection
                                          //  Referenced by: '<S188>/MATLAB Function'

  real_T simMode;                      // Variable: simMode
                                          //  Referenced by: '<S25>/Constant'

  real_T thruster_dist2CG_BLACK[8];    // Variable: thruster_dist2CG_BLACK
                                          //  Referenced by:
                                          //    '<S236>/MATLAB Function5'
                                          //    '<S239>/MATLAB Function'

  real_T thruster_dist2CG_BLUE[8];     // Variable: thruster_dist2CG_BLUE
                                          //  Referenced by:
                                          //    '<S248>/MATLAB Function5'
                                          //    '<S251>/MATLAB Function'

  real_T thruster_dist2CG_RED[8];      // Variable: thruster_dist2CG_RED
                                          //  Referenced by:
                                          //    '<S260>/MATLAB Function5'
                                          //    '<S263>/MATLAB Function'

  real_T xLength;                      // Variable: xLength
                                          //  Referenced by:
                                          //    '<S51>/Desired X-Position (BLACK)'
                                          //    '<S46>/Constant1'
                                          //    '<S57>/Constant1'
                                          //    '<S65>/Constant1'
                                          //    '<S77>/Constant1'

  real_T yLength;                      // Variable: yLength
                                          //  Referenced by:
                                          //    '<S51>/Desired Y-Position (BLACK)'
                                          //    '<S46>/Constant2'
                                          //    '<S57>/Constant2'
                                          //    '<S65>/Constant2'
                                          //    '<S77>/Constant2'

  real_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S164>/UD'

  real_T DiscreteDerivative1_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative1_ICPrevScale
                                 //  Referenced by: '<S165>/UD'

  real_T DiscreteDerivative2_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative2_ICPrevScale
                                 //  Referenced by: '<S166>/UD'

  real_T DiscreteDerivative_ICPrevScal_i;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_i
                                 //  Referenced by: '<S141>/UD'

  real_T DiscreteDerivative1_ICPrevSca_e;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_e
                                 //  Referenced by: '<S142>/UD'

  real_T DiscreteDerivative2_ICPrevSca_o;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_o
                                 //  Referenced by: '<S143>/UD'

  real_T DiscreteDerivative_ICPrevScal_p;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_p
                                 //  Referenced by: '<S154>/UD'

  real_T DiscreteDerivative1_ICPrevSca_m;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_m
                                 //  Referenced by: '<S155>/UD'

  real_T DiscreteDerivative2_ICPrevSca_a;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_a
                                 //  Referenced by: '<S156>/UD'

  real_T DiscreteDerivative_ICPrevScal_d;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_d
                                 //  Referenced by: '<S131>/UD'

  real_T DiscreteDerivative1_ICPrevSca_i;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_i
                                 //  Referenced by: '<S132>/UD'

  real_T DiscreteDerivative2_ICPrevSc_oo;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSc_oo
                                 //  Referenced by: '<S133>/UD'

  real_T DiscreteDerivative_ICPrevSca_pf;
                              // Mask Parameter: DiscreteDerivative_ICPrevSca_pf
                                 //  Referenced by: '<S159>/UD'

  real_T DiscreteDerivative1_ICPrevSca_l;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_l
                                 //  Referenced by: '<S160>/UD'

  real_T DiscreteDerivative2_ICPrevSc_on;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSc_on
                                 //  Referenced by: '<S161>/UD'

  real_T DiscreteDerivative_ICPrevScal_n;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_n
                                 //  Referenced by: '<S136>/UD'

  real_T DiscreteDerivative1_ICPrevSca_f;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_f
                                 //  Referenced by: '<S137>/UD'

  real_T DiscreteDerivative2_ICPrevSca_g;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_g
                                 //  Referenced by: '<S138>/UD'

  real_T DiscreteDerivative1_ICPrevSca_j;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_j
                                 //  Referenced by: '<S150>/UD'

  real_T DiscreteDerivative1_ICPrevSca_a;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_a
                                 //  Referenced by: '<S151>/UD'

  real_T DiscreteDerivative1_ICPrevSca_k;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_k
                                 //  Referenced by: '<S152>/UD'

  real_T MATLABFunction5_max_iters; // Mask Parameter: MATLABFunction5_max_iters
                                       //  Referenced by: '<S236>/MATLAB Function5'

  real_T MATLABFunction5_max_iters_c;
                                  // Mask Parameter: MATLABFunction5_max_iters_c
                                     //  Referenced by: '<S248>/MATLAB Function5'

  real_T MATLABFunction5_max_iters_e;
                                  // Mask Parameter: MATLABFunction5_max_iters_e
                                     //  Referenced by: '<S260>/MATLAB Function5'

  real_T MATLABFunction5_tol;          // Mask Parameter: MATLABFunction5_tol
                                          //  Referenced by: '<S236>/MATLAB Function5'

  real_T MATLABFunction5_tol_m;        // Mask Parameter: MATLABFunction5_tol_m
                                          //  Referenced by: '<S248>/MATLAB Function5'

  real_T MATLABFunction5_tol_g;        // Mask Parameter: MATLABFunction5_tol_g
                                          //  Referenced by: '<S260>/MATLAB Function5'

  real_T Constant11_Value;             // Expression: 0
                                          //  Referenced by: '<S29>/Constant11'

  real_T Constant12_Value;             // Expression: 0
                                          //  Referenced by: '<S29>/Constant12'

  real_T Constant14_Value;             // Expression: 0
                                          //  Referenced by: '<S29>/Constant14'

  real_T Constant15_Value;             // Expression: 0
                                          //  Referenced by: '<S29>/Constant15'

  real_T Constant18_Value;             // Expression: 0
                                          //  Referenced by: '<S29>/Constant18'

  real_T Constant4_Value;              // Expression: 2
                                          //  Referenced by: '<S29>/Constant4'

  real_T Constant5_Value;              // Expression: 2
                                          //  Referenced by: '<S29>/Constant5'

  real_T Constant6_Value;              // Expression: 1
                                          //  Referenced by: '<S29>/Constant6'

  real_T Constant8_Value;              // Expression: 2
                                          //  Referenced by: '<S29>/Constant8'

  real_T Constant3_Value;              // Expression: pi/2
                                          //  Referenced by: '<S34>/Constant3'

  real_T Constant1_Value;              // Expression: pi/2
                                          //  Referenced by: '<S34>/Constant1'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S34>/Constant2'

  real_T Constant11_Value_e;           // Expression: 0
                                          //  Referenced by: '<S38>/Constant11'

  real_T Constant12_Value_g;           // Expression: 0
                                          //  Referenced by: '<S38>/Constant12'

  real_T Constant14_Value_f;           // Expression: 0
                                          //  Referenced by: '<S38>/Constant14'

  real_T Constant15_Value_o;           // Expression: 0
                                          //  Referenced by: '<S38>/Constant15'

  real_T Constant18_Value_m;           // Expression: 0
                                          //  Referenced by: '<S38>/Constant18'

  real_T Constant4_Value_g;            // Expression: 2
                                          //  Referenced by: '<S38>/Constant4'

  real_T Constant5_Value_o;            // Expression: 2
                                          //  Referenced by: '<S38>/Constant5'

  real_T Constant6_Value_i;            // Expression: 1
                                          //  Referenced by: '<S38>/Constant6'

  real_T Constant8_Value_m;            // Expression: 2
                                          //  Referenced by: '<S38>/Constant8'

  real_T Constant3_Value_b;            // Expression: pi/2
                                          //  Referenced by: '<S42>/Constant3'

  real_T Constant1_Value_o;            // Expression: pi/2
                                          //  Referenced by: '<S42>/Constant1'

  real_T Constant2_Value_f;            // Expression: 0
                                          //  Referenced by: '<S42>/Constant2'

  real_T DesiredRate_Value;            // Expression: 0.03490659
                                          //  Referenced by: '<S44>/Desired Rate '

  real_T Gain_Gain;                    // Expression: -0.85
                                          //  Referenced by: '<S46>/Gain'

  real_T Gain1_Gain;                   // Expression: -0.85
                                          //  Referenced by: '<S46>/Gain1'

  real_T SignalGenerator_Amplitude;    // Expression: 0.5
                                          //  Referenced by: '<S43>/Signal Generator'

  real_T SignalGenerator_Frequency;    // Expression: 1/60
                                          //  Referenced by: '<S43>/Signal Generator'

  real_T Constant11_Value_m;           // Expression: 0
                                          //  Referenced by: '<S39>/Constant11'

  real_T Constant12_Value_k;           // Expression: 0
                                          //  Referenced by: '<S39>/Constant12'

  real_T Constant14_Value_i;           // Expression: 0
                                          //  Referenced by: '<S39>/Constant14'

  real_T Constant15_Value_o1;          // Expression: 0
                                          //  Referenced by: '<S39>/Constant15'

  real_T Constant18_Value_n;           // Expression: 0
                                          //  Referenced by: '<S39>/Constant18'

  real_T Constant4_Value_a;            // Expression: 2
                                          //  Referenced by: '<S39>/Constant4'

  real_T Constant5_Value_m;            // Expression: 2
                                          //  Referenced by: '<S39>/Constant5'

  real_T Constant6_Value_p;            // Expression: 1
                                          //  Referenced by: '<S39>/Constant6'

  real_T Constant8_Value_o;            // Expression: 2
                                          //  Referenced by: '<S39>/Constant8'

  real_T Constant3_Value_p;            // Expression: pi/2
                                          //  Referenced by: '<S50>/Constant3'

  real_T Constant1_Value_m;            // Expression: pi/2
                                          //  Referenced by: '<S50>/Constant1'

  real_T Constant2_Value_p;            // Expression: 0
                                          //  Referenced by: '<S50>/Constant2'

  real_T DesiredRate_Value_h;          // Expression: 0.03490659
                                          //  Referenced by: '<S52>/Desired Rate '

  real_T Gain_Gain_h;                  // Expression: -0.85
                                          //  Referenced by: '<S57>/Gain'

  real_T Gain1_Gain_c;                 // Expression: -0.85
                                          //  Referenced by: '<S57>/Gain1'

  real_T DesiredRateBLACK_Value;       // Expression: 0.8*pi/120
                                          //  Referenced by: '<S54>/Desired Rate (BLACK)'

  real_T Constant11_Value_b;           // Expression: 0
                                          //  Referenced by: '<S40>/Constant11'

  real_T Constant12_Value_ku;          // Expression: 0
                                          //  Referenced by: '<S40>/Constant12'

  real_T Constant14_Value_n;           // Expression: 0
                                          //  Referenced by: '<S40>/Constant14'

  real_T Constant15_Value_o2;          // Expression: 0
                                          //  Referenced by: '<S40>/Constant15'

  real_T Constant18_Value_l;           // Expression: 0
                                          //  Referenced by: '<S40>/Constant18'

  real_T Constant4_Value_b;            // Expression: 2
                                          //  Referenced by: '<S40>/Constant4'

  real_T Constant5_Value_n;            // Expression: 2
                                          //  Referenced by: '<S40>/Constant5'

  real_T Constant6_Value_n;            // Expression: 1
                                          //  Referenced by: '<S40>/Constant6'

  real_T Constant8_Value_f;            // Expression: 2
                                          //  Referenced by: '<S40>/Constant8'

  real_T Constant3_Value_e;            // Expression: pi/2
                                          //  Referenced by: '<S61>/Constant3'

  real_T Constant1_Value_p;            // Expression: pi/2
                                          //  Referenced by: '<S61>/Constant1'

  real_T Constant2_Value_c;            // Expression: 0
                                          //  Referenced by: '<S61>/Constant2'

  real_T DesiredRate_Value_l;          // Expression: 0.03490659
                                          //  Referenced by: '<S62>/Desired Rate '

  real_T Gain_Gain_b;                  // Expression: -0.85
                                          //  Referenced by: '<S65>/Gain'

  real_T Gain1_Gain_k;                 // Expression: -0.85
                                          //  Referenced by: '<S65>/Gain1'

  real_T DesiredRateBLACK_Value_c;     // Expression: 4*pi/120
                                          //  Referenced by: '<S69>/Desired Rate (BLACK)'

  real_T Constant11_Value_p;           // Expression: 0
                                          //  Referenced by: '<S41>/Constant11'

  real_T Constant12_Value_n;           // Expression: 0
                                          //  Referenced by: '<S41>/Constant12'

  real_T Constant14_Value_f2;          // Expression: 0
                                          //  Referenced by: '<S41>/Constant14'

  real_T Constant15_Value_n;           // Expression: 0
                                          //  Referenced by: '<S41>/Constant15'

  real_T Constant18_Value_e;           // Expression: 0
                                          //  Referenced by: '<S41>/Constant18'

  real_T Constant4_Value_l;            // Expression: 2
                                          //  Referenced by: '<S41>/Constant4'

  real_T Constant5_Value_p;            // Expression: 2
                                          //  Referenced by: '<S41>/Constant5'

  real_T Constant6_Value_m;            // Expression: 1
                                          //  Referenced by: '<S41>/Constant6'

  real_T Constant8_Value_j;            // Expression: 2
                                          //  Referenced by: '<S41>/Constant8'

  real_T Constant3_Value_k;            // Expression: 0
                                          //  Referenced by: '<S73>/Constant3'

  real_T Constant1_Value_b;            // Expression: 0
                                          //  Referenced by: '<S73>/Constant1'

  real_T Constant2_Value_g;            // Expression: 0
                                          //  Referenced by: '<S73>/Constant2'

  real_T DesiredRate_Value_ha;         // Expression: 0.03490659
                                          //  Referenced by: '<S75>/Desired Rate '

  real_T Gain_Gain_o;                  // Expression: -0.85
                                          //  Referenced by: '<S77>/Gain'

  real_T Gain1_Gain_b;                 // Expression: -0.85
                                          //  Referenced by: '<S77>/Gain1'

  real_T Constant1_Value_n;            // Expression: 0
                                          //  Referenced by: '<S33>/Constant1'

  real_T Constant2_Value_a;            // Expression: 0
                                          //  Referenced by: '<S33>/Constant2'

  real_T Constant3_Value_d;            // Expression: 0
                                          //  Referenced by: '<S33>/Constant3'

  real_T Constant4_Value_k;            // Expression: 0
                                          //  Referenced by: '<S33>/Constant4'

  real_T Constant5_Value_ph;           // Expression: 0
                                          //  Referenced by: '<S33>/Constant5'

  real_T Constant6_Value_d;            // Expression: 0
                                          //  Referenced by: '<S33>/Constant6'

  real_T Constant7_Value;              // Expression: 0
                                          //  Referenced by: '<S33>/Constant7'

  real_T Constant8_Value_h;            // Expression: 0
                                          //  Referenced by: '<S33>/Constant8'

  real_T PuckState_Value;              // Expression: 0
                                          //  Referenced by: '<S33>/Puck State'

  real_T AngularGain_Value;            // Expression: 200
                                          //  Referenced by: '<S94>/Angular Gain'

  real_T AttractiveGain_Value;         // Expression: 200
                                          //  Referenced by: '<S94>/Attractive Gain'

  real_T InfluenceRange_Value;         // Expression: 1
                                          //  Referenced by: '<S94>/Influence Range'

  real_T RepulsiveGain_Value;          // Expression: 5
                                          //  Referenced by: '<S94>/Repulsive Gain'

  real_T AngularGain_Value_l;          // Expression: 200
                                          //  Referenced by: '<S93>/Angular Gain'

  real_T AttractiveGain_Value_i;       // Expression: 200
                                          //  Referenced by: '<S93>/Attractive Gain'

  real_T InfluenceRange_Value_d;       // Expression: 1
                                          //  Referenced by: '<S93>/Influence Range'

  real_T RepulsiveGain_Value_k;        // Expression: 5
                                          //  Referenced by: '<S93>/Repulsive Gain'

  real_T TSamp_WtEt;                   // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S164>/TSamp'

  real_T TSamp_WtEt_f;                 // Computed Parameter: TSamp_WtEt_f
                                          //  Referenced by: '<S165>/TSamp'

  real_T TSamp_WtEt_c;                 // Computed Parameter: TSamp_WtEt_c
                                          //  Referenced by: '<S166>/TSamp'

  real_T Gain6_Gain;                   // Expression: -1
                                          //  Referenced by: '<S125>/Gain6'

  real_T Gain7_Gain;                   // Expression: -1
                                          //  Referenced by: '<S125>/Gain7'

  real_T Gain8_Gain;                   // Expression: -1
                                          //  Referenced by: '<S125>/Gain8'

  real_T TSamp_WtEt_h;                 // Computed Parameter: TSamp_WtEt_h
                                          //  Referenced by: '<S141>/TSamp'

  real_T TSamp_WtEt_e;                 // Computed Parameter: TSamp_WtEt_e
                                          //  Referenced by: '<S142>/TSamp'

  real_T TSamp_WtEt_n;                 // Computed Parameter: TSamp_WtEt_n
                                          //  Referenced by: '<S143>/TSamp'

  real_T TSamp_WtEt_i;                 // Computed Parameter: TSamp_WtEt_i
                                          //  Referenced by: '<S154>/TSamp'

  real_T TSamp_WtEt_hr;                // Computed Parameter: TSamp_WtEt_hr
                                          //  Referenced by: '<S155>/TSamp'

  real_T TSamp_WtEt_ca;                // Computed Parameter: TSamp_WtEt_ca
                                          //  Referenced by: '<S156>/TSamp'

  real_T Gain6_Gain_g;                 // Expression: -1
                                          //  Referenced by: '<S123>/Gain6'

  real_T Gain7_Gain_b;                 // Expression: -1
                                          //  Referenced by: '<S123>/Gain7'

  real_T Gain8_Gain_m;                 // Expression: -1
                                          //  Referenced by: '<S123>/Gain8'

  real_T TSamp_WtEt_nd;                // Computed Parameter: TSamp_WtEt_nd
                                          //  Referenced by: '<S131>/TSamp'

  real_T TSamp_WtEt_co;                // Computed Parameter: TSamp_WtEt_co
                                          //  Referenced by: '<S132>/TSamp'

  real_T TSamp_WtEt_no;                // Computed Parameter: TSamp_WtEt_no
                                          //  Referenced by: '<S133>/TSamp'

  real_T TSamp_WtEt_p;                 // Computed Parameter: TSamp_WtEt_p
                                          //  Referenced by: '<S159>/TSamp'

  real_T TSamp_WtEt_o;                 // Computed Parameter: TSamp_WtEt_o
                                          //  Referenced by: '<S160>/TSamp'

  real_T TSamp_WtEt_px;                // Computed Parameter: TSamp_WtEt_px
                                          //  Referenced by: '<S161>/TSamp'

  real_T Gain6_Gain_a;                 // Expression: -1
                                          //  Referenced by: '<S124>/Gain6'

  real_T Gain7_Gain_e;                 // Expression: -1
                                          //  Referenced by: '<S124>/Gain7'

  real_T Gain8_Gain_g;                 // Expression: -1
                                          //  Referenced by: '<S124>/Gain8'

  real_T TSamp_WtEt_ft;                // Computed Parameter: TSamp_WtEt_ft
                                          //  Referenced by: '<S136>/TSamp'

  real_T TSamp_WtEt_eh;                // Computed Parameter: TSamp_WtEt_eh
                                          //  Referenced by: '<S137>/TSamp'

  real_T TSamp_WtEt_ii;                // Computed Parameter: TSamp_WtEt_ii
                                          //  Referenced by: '<S138>/TSamp'

  real_T TSamp_WtEt_pu;                // Computed Parameter: TSamp_WtEt_pu
                                          //  Referenced by: '<S150>/TSamp'

  real_T TSamp_WtEt_f0;                // Computed Parameter: TSamp_WtEt_f0
                                          //  Referenced by: '<S151>/TSamp'

  real_T TSamp_WtEt_nz;                // Computed Parameter: TSamp_WtEt_nz
                                          //  Referenced by: '<S152>/TSamp'

  real_T Constant7_Value_a;            // Expression: 1
                                          //  Referenced by: '<S122>/Constant7'

  real_T Merge3_InitialOutput;       // Computed Parameter: Merge3_InitialOutput
                                        //  Referenced by: '<S122>/Merge3'

  real_T Merge4_InitialOutput;       // Computed Parameter: Merge4_InitialOutput
                                        //  Referenced by: '<S122>/Merge4'

  real_T Merge5_InitialOutput;       // Computed Parameter: Merge5_InitialOutput
                                        //  Referenced by: '<S122>/Merge5'

  real_T Constant7_Value_h;            // Expression: 0
                                          //  Referenced by: '<S126>/Constant7'

  real_T Zero_Value;                   // Expression: 0
                                          //  Referenced by: '<S126>/Zero'

  real_T GPIOWrite1_gpioPin;           // Expression: 428
                                          //  Referenced by: '<S177>/GPIO Write1'

  real_T GPIOWrite1_pinDirection;      // Expression: 1
                                          //  Referenced by: '<S177>/GPIO Write1'

  real_T GyroscopeAccelerometer_SampleTi;// Expression: -1
                                            //  Referenced by: '<S178>/Gyroscope//Accelerometer'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S180>/Delay'

  real_T Delay1_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S180>/Delay1'

  real_T Delay2_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S180>/Delay2'

  real_T Out1_Y0;                      // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S189>/Out1'

  real_T Memory_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S189>/Memory'

  real_T Out1_Y0_i;                    // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S190>/Out1'

  real_T dytdt_Y0;                     // Computed Parameter: dytdt_Y0
                                          //  Referenced by: '<S196>/dy(t)//dt'

  real_T dytdt_Y0_j;                   // Computed Parameter: dytdt_Y0_j
                                          //  Referenced by: '<S206>/dy(t)//dt'

  real_T dytdt_Y0_d;                   // Computed Parameter: dytdt_Y0_d
                                          //  Referenced by: '<S216>/dy(t)//dt'

  real_T ConvertBLAXfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S184>/Convert BLAX from [mm] to [m]'

  real_T ConvertBLAYfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S184>/Convert BLAY from [mm] to [m]'

  real_T ConvertBLACKVXfrommmtom_Gain; // Expression: 1/1000
                                          //  Referenced by: '<S184>/Convert BLACKVX from [mm] to [m]'

  real_T ConvertBLACKVYfrommmtom_Gain; // Expression: 1/1000
                                          //  Referenced by: '<S184>/Convert BLACKVY from [mm] to [m]'

  real_T Delay2_InitialCondition_e;    // Expression: 0
                                          //  Referenced by: '<S192>/Delay2'

  real_T Delay1_InitialCondition_m;    // Expression: 0
                                          //  Referenced by: '<S192>/Delay1'

  real_T Constant3_Value_eq;           // Expression: 0
                                          //  Referenced by: '<S192>/Constant3'

  real_T Delay1_InitialCondition_i;    // Expression: 0.0
                                          //  Referenced by: '<S194>/Delay1'

  real_T Constant3_Value_a;            // Expression: 0
                                          //  Referenced by: '<S194>/Constant3'

  real_T Delay1_InitialCondition_it;   // Expression: 0.0
                                          //  Referenced by: '<S193>/Delay1'

  real_T Constant3_Value_d4;           // Expression: 0
                                          //  Referenced by: '<S193>/Constant3'

  real_T ConvertBLUXfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S185>/Convert BLUX from [mm] to [m]'

  real_T ConvertBLUYfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S185>/Convert BLUY from [mm] to [m]'

  real_T ConvertBLUEVXfrommmtom_Gain;  // Expression: 1/1000
                                          //  Referenced by: '<S185>/Convert BLUEVX from [mm] to [m]'

  real_T ConvertBLUEVYfrommmtom_Gain;  // Expression: 1/1000
                                          //  Referenced by: '<S185>/Convert BLUEVY from [mm] to [m]'

  real_T Delay2_InitialCondition_a;    // Expression: 0
                                          //  Referenced by: '<S202>/Delay2'

  real_T Delay1_InitialCondition_i3;   // Expression: 0
                                          //  Referenced by: '<S202>/Delay1'

  real_T Constant3_Value_o;            // Expression: 0
                                          //  Referenced by: '<S202>/Constant3'

  real_T Delay1_InitialCondition_h;    // Expression: 0.0
                                          //  Referenced by: '<S204>/Delay1'

  real_T Constant3_Value_c;            // Expression: 0
                                          //  Referenced by: '<S204>/Constant3'

  real_T Delay1_InitialCondition_j;    // Expression: 0.0
                                          //  Referenced by: '<S203>/Delay1'

  real_T Constant3_Value_ke;           // Expression: 0
                                          //  Referenced by: '<S203>/Constant3'

  real_T ConvertREDXfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S186>/Convert REDX from [mm] to [m]'

  real_T ConvertREDYfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S186>/Convert REDY from [mm] to [m]'

  real_T ConvertREDVXfrommmtom_Gain;   // Expression: 1/1000
                                          //  Referenced by: '<S186>/Convert REDVX from [mm] to [m]'

  real_T ConvertREDVYfrommmtom_Gain;   // Expression: 1/1000
                                          //  Referenced by: '<S186>/Convert REDVY from [mm] to [m]'

  real_T Delay2_InitialCondition_m;    // Expression: 0
                                          //  Referenced by: '<S212>/Delay2'

  real_T Delay1_InitialCondition_l;    // Expression: 0
                                          //  Referenced by: '<S212>/Delay1'

  real_T Constant3_Value_f;            // Expression: 0
                                          //  Referenced by: '<S212>/Constant3'

  real_T Delay1_InitialCondition_k;    // Expression: 0.0
                                          //  Referenced by: '<S214>/Delay1'

  real_T Constant3_Value_dh;           // Expression: 0
                                          //  Referenced by: '<S214>/Constant3'

  real_T Delay1_InitialCondition_c;    // Expression: 0.0
                                          //  Referenced by: '<S213>/Delay1'

  real_T Constant3_Value_dz;           // Expression: 0
                                          //  Referenced by: '<S213>/Constant3'

  real_T Constant_Value;               // Expression: 1
                                          //  Referenced by: '<S187>/Constant'

  real_T Constant_Value_d;             // Expression: 0
                                          //  Referenced by: '<S226>/Constant'

  real_T ControlDynamixelActuatorsineith;// Expression: 400
                                            //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_b;// Expression: 0
                                            //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_h;// Expression: 200
                                            //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_j;// Expression: 3072
                                            //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_m;// Expression: 1024
                                            //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsine_hy;// Expression: 0
                                            //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_i;// Expression: 850
                                            //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_g;// Expression: 400
                                            //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsine_g3;// Expression: 100
                                            //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsine_bf;// Expression: 50
                                            //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_l;// Expression: 0
                                            //  Referenced by: '<S229>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T Out1_Y0_f;                    // Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S243>/Out1'

  real_T Out1_Y0_j;                    // Computed Parameter: Out1_Y0_j
                                          //  Referenced by: '<S244>/Out1'

  real_T BLACKDC_Y0;                   // Computed Parameter: BLACKDC_Y0
                                          //  Referenced by: '<S233>/BLACK DC'

  real_T Delay_InitialCondition_i;     // Expression: 0.0
                                          //  Referenced by: '<S238>/Delay'

  real_T Constant2_Value_h;            // Expression: 0
                                          //  Referenced by: '<S238>/Constant2'

  real_T Out1_Y0_n;                    // Computed Parameter: Out1_Y0_n
                                          //  Referenced by: '<S255>/Out1'

  real_T Out1_Y0_js;                   // Computed Parameter: Out1_Y0_js
                                          //  Referenced by: '<S256>/Out1'

  real_T BLUEDC_Y0;                    // Computed Parameter: BLUEDC_Y0
                                          //  Referenced by: '<S234>/BLUE DC'

  real_T Delay_InitialCondition_n;     // Expression: 0.0
                                          //  Referenced by: '<S250>/Delay'

  real_T Constant2_Value_fq;           // Expression: 0
                                          //  Referenced by: '<S250>/Constant2'

  real_T Out1_Y0_c;                    // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S267>/Out1'

  real_T Out1_Y0_d;                    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S268>/Out1'

  real_T REDDC_Y0;                     // Computed Parameter: REDDC_Y0
                                          //  Referenced by: '<S235>/RED DC'

  real_T Delay_InitialCondition_p;     // Expression: 0.0
                                          //  Referenced by: '<S262>/Delay'

  real_T Constant2_Value_e;            // Expression: 0
                                          //  Referenced by: '<S262>/Constant2'

  real_T RED_Tz4_InitialValue;         // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz4'

  real_T RED_Tz5_InitialValue;         // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz5'

  real_T Universal_Time1_InitialValue[9];// Expression: [0;0;0;0;0;0;0;0;0]
                                            //  Referenced by: '<Root>/Universal_Time1'

  real_T Universal_Time12_InitialValue[9];// Expression: [0;0;0;0;0;0;0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time12'

  real_T Universal_Time2_InitialValue[9];// Expression: [0;0;0;0;0;0;0;0;0]
                                            //  Referenced by: '<Root>/Universal_Time2'

  real_T Universal_Time7_InitialValue[6];// Expression: [0;0;0;0;0;0]
                                            //  Referenced by: '<Root>/Universal_Time7'

  real_T Delay_InitialCondition_e;     // Expression: 0.0
                                          //  Referenced by: '<Root>/Delay'

  real_T Merge1_InitialOutput;       // Computed Parameter: Merge1_InitialOutput
                                        //  Referenced by: '<S3>/Merge1'

  real_T Merge2_InitialOutput;       // Computed Parameter: Merge2_InitialOutput
                                        //  Referenced by: '<S3>/Merge2'

  real_T Merge_InitialOutput;         // Computed Parameter: Merge_InitialOutput
                                         //  Referenced by: '<S3>/Merge'

  real_T Delay1_InitialCondition_f[14];// Expression: [1;zeros(13,1)]
                                          //  Referenced by: '<S5>/Delay1'

  real_T Delay1_InitialCondition_k5[13];// Expression: [1;zeros(12,1)]
                                           //  Referenced by: '<S16>/Delay1'

  real_T Delay1_InitialCondition_ic[9];// Expression: zeros(9,1)
                                          //  Referenced by: '<S17>/Delay1'

  real_T Delay2_InitialCondition_d[9]; // Expression: eye(3)
                                          //  Referenced by: '<S17>/Delay2'

  real_T Delay1_InitialCondition_je[14];// Expression: [1;zeros(13,1)]
                                           //  Referenced by: '<S22>/Delay1'

  real_T Delay2_InitialCondition_l[36];// Expression: zeros(6)
                                          //  Referenced by: '<S22>/Delay2'

  real_T Delay1_InitialCondition_p[13];// Expression: [1;zeros(12,1)]
                                          //  Referenced by: '<S23>/Delay1'

  real_T Delay2_InitialCondition_f[36];// Expression: zeros(6)
                                          //  Referenced by: '<S23>/Delay2'

  real_T SafetyNumber_Value;           // Expression: 568471
                                          //  Referenced by: '<S26>/Safety Number'

  real_T Gain_Gain_oy;                 // Expression: 100
                                          //  Referenced by: '<S26>/Gain'

  real_T Gain1_Gain_e;                 // Expression: 100
                                          //  Referenced by: '<S26>/Gain1'

  real_T Gain2_Gain;                   // Expression: 100
                                          //  Referenced by: '<S26>/Gain2'

  real_T Gain3_Gain;                   // Expression: 100
                                          //  Referenced by: '<S26>/Gain3'

  real_T Gain4_Gain;                   // Expression: 100
                                          //  Referenced by: '<S26>/Gain4'

  real_T Gain5_Gain;                   // Expression: 100
                                          //  Referenced by: '<S26>/Gain5'

  real_T Gain6_Gain_c;                 // Expression: 100
                                          //  Referenced by: '<S26>/Gain6'

  real_T Gain7_Gain_l;                 // Expression: 100
                                          //  Referenced by: '<S26>/Gain7'

  real_T DataStoreMemory_InitialValue[8];// Expression: zeros(4,2)
                                            //  Referenced by: '<Root>/Data Store Memory'

  real_T DataStoreMemory1_InitialValue[4];// Expression: zeros(4,1)
                                             //  Referenced by: '<Root>/Data Store Memory1'

  real_T DataStoreMemory10_InitialValue[3];// Expression: zeros(3,1)
                                              //  Referenced by: '<Root>/Data Store Memory10'

  real_T DataStoreMemory11_InitialValue[3];// Expression: zeros(3,1)
                                              //  Referenced by: '<Root>/Data Store Memory11'

  real_T DataStoreMemory12_InitialValue[8];// Expression: zeros(4,2)
                                              //  Referenced by: '<Root>/Data Store Memory12'

  real_T DataStoreMemory13_InitialValue[4];// Expression: zeros(4,1)
                                              //  Referenced by: '<Root>/Data Store Memory13'

  real_T DataStoreMemory14_InitialValue[9];// Expression: zeros(3)
                                              //  Referenced by: '<Root>/Data Store Memory14'

  real_T DataStoreMemory15_InitialValue[3];// Expression: zeros(3,1)
                                              //  Referenced by: '<Root>/Data Store Memory15'

  real_T DataStoreMemory16_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory16'

  real_T DataStoreMemory17_InitialValue[13];// Expression: zeros(13,1)
                                               //  Referenced by: '<Root>/Data Store Memory17'

  real_T DataStoreMemory18_InitialValue[144];// Expression: zeros(12)
                                                //  Referenced by: '<Root>/Data Store Memory18'

  real_T DataStoreMemory19_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory19'

  real_T DataStoreMemory2_InitialValue[9];// Expression: zeros(3)
                                             //  Referenced by: '<Root>/Data Store Memory2'

  real_T DataStoreMemory20_InitialValue[13];// Expression: zeros(13,1)
                                               //  Referenced by: '<Root>/Data Store Memory20'

  real_T DataStoreMemory21_InitialValue[144];// Expression: zeros(12)
                                                //  Referenced by: '<Root>/Data Store Memory21'

  real_T DataStoreMemory22_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory22'

  real_T DataStoreMemory23_InitialValue[14];// Expression: zeros(14,1)
                                               //  Referenced by: '<Root>/Data Store Memory23'

  real_T DataStoreMemory24_InitialValue[144];// Expression: zeros(12)
                                                //  Referenced by: '<Root>/Data Store Memory24'

  real_T DataStoreMemory25_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory25'

  real_T DataStoreMemory26_InitialValue[14];// Expression: zeros(14,1)
                                               //  Referenced by: '<Root>/Data Store Memory26'

  real_T DataStoreMemory27_InitialValue[144];// Expression: zeros(12)
                                                //  Referenced by: '<Root>/Data Store Memory27'

  real_T DataStoreMemory28_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory28'

  real_T DataStoreMemory29_InitialValue[9];// Expression: zeros(9,1)
                                              //  Referenced by: '<Root>/Data Store Memory29'

  real_T DataStoreMemory3_InitialValue[3];// Expression: zeros(3,1)
                                             //  Referenced by: '<Root>/Data Store Memory3'

  real_T DataStoreMemory30_InitialValue[144];// Expression: zeros(12)
                                                //  Referenced by: '<Root>/Data Store Memory30'

  real_T DataStoreMemory31_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory31'

  real_T DataStoreMemory32_InitialValue[9];// Expression: zeros(9,1)
                                              //  Referenced by: '<Root>/Data Store Memory32'

  real_T DataStoreMemory33_InitialValue[144];// Expression: zeros(12)
                                                //  Referenced by: '<Root>/Data Store Memory33'

  real_T DataStoreMemory34_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory34'

  real_T DataStoreMemory35_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory35'

  real_T DataStoreMemory36_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory36'

  real_T DataStoreMemory37_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory37'

  real_T DataStoreMemory38_InitialValue[9];// Expression: zeros(3)
                                              //  Referenced by: '<Root>/Data Store Memory38'

  real_T DataStoreMemory39_InitialValue[9];// Expression: zeros(3)
                                              //  Referenced by: '<Root>/Data Store Memory39'

  real_T DataStoreMemory4_InitialValue[3];// Expression: zeros(3,1)
                                             //  Referenced by: '<Root>/Data Store Memory4'

  real_T DataStoreMemory40_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory40'

  real_T DataStoreMemory5_InitialValue[3];// Expression: zeros(3,1)
                                             //  Referenced by: '<Root>/Data Store Memory5'

  real_T DataStoreMemory6_InitialValue[8];// Expression: zeros(4,2)
                                             //  Referenced by: '<Root>/Data Store Memory6'

  real_T DataStoreMemory7_InitialValue[4];// Expression: zeros(4,1)
                                             //  Referenced by: '<Root>/Data Store Memory7'

  real_T DataStoreMemory8_InitialValue[9];// Expression: zeros(3)
                                             //  Referenced by: '<Root>/Data Store Memory8'

  real_T DataStoreMemory9_InitialValue[3];// Expression: zeros(3,1)
                                             //  Referenced by: '<Root>/Data Store Memory9'

  real_T RED_Tz1_InitialValue;         // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz1'

  real_T RED_Tz15_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz15'

  real_T RED_Tz2_InitialValue;         // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz2'

  real_T RED_Tz20_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz20'

  real_T RED_Tz25_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz25'

  real_T RED_Tz37_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz37'

  real_T RED_Tz38_InitialValue;        // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz38'

  real_T RED_Tz7_InitialValue;         // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz7'

  real_T RED_Tz8_InitialValue;         // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz8'

  real_T RED_Tz9_InitialValue;         // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz9'

  real_T Universal_Time_InitialValue;  // Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time'

  real_T Universal_Time10_InitialValue[9];// Expression: [0;0;0;0;0;0;0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time10'

  real_T Universal_Time11_InitialValue[3];// Expression: [0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time11'

  real_T Universal_Time13_InitialValue[3];// Expression: [0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time13'

  real_T Universal_Time14_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time14'

  real_T Universal_Time15_InitialValue[3];// Expression: [0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time15'

  real_T Universal_Time16_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time16'

  real_T Universal_Time17_InitialValue[3];// Expression: [0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time17'

  real_T Universal_Time18_InitialValue[3];// Expression: [0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time18'

  real_T Universal_Time19_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time19'

  real_T Universal_Time20_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time20'

  real_T Universal_Time24_InitialValue[6];// Expression: [0;0;0;0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time24'

  real_T Universal_Time25_InitialValue[3];// Expression: [0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time25'

  real_T Universal_Time26_InitialValue[9];// Expression: [0;0;0;0;0;0;0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time26'

  real_T Universal_Time27_InitialValue[3];// Expression: [0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time27'

  real_T Universal_Time28_InitialValue[3];// Expression: [0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time28'

  real_T Universal_Time29_InitialValue[3];// Expression: [0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time29'

  real_T Universal_Time3_InitialValue; // Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time3'

  real_T Universal_Time30_InitialValue[3];// Expression: [0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time30'

  real_T Universal_Time31_InitialValue[3];// Expression: [0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time31'

  real_T Universal_Time32_InitialValue[3];// Expression: [0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time32'

  real_T Universal_Time33_InitialValue[3];// Expression: [0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time33'

  real_T Universal_Time34_InitialValue[3];// Expression: [0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time34'

  real_T Universal_Time35_InitialValue[3];// Expression: [0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time35'

  real_T Universal_Time4_InitialValue[9];// Expression: [0;0;0;0;0;0;0;0;0]
                                            //  Referenced by: '<Root>/Universal_Time4'

  real_T Universal_Time5_InitialValue[3];// Expression: [0;0;0]
                                            //  Referenced by: '<Root>/Universal_Time5'

  real_T Universal_Time6_InitialValue[3];// Expression: [0;0;0]
                                            //  Referenced by: '<Root>/Universal_Time6'

  real_T Universal_Time8_InitialValue[3];// Expression: [0;0;0]
                                            //  Referenced by: '<Root>/Universal_Time8'

  char_T StringConstant1_String[256];  // Expression: "Target: Hello"
                                          //  Referenced by: '<S174>/String Constant1'

  char_T StringConstant2_String[256];  // Expression: "Obstacle: Hello"
                                          //  Referenced by: '<S175>/String Constant2'

  char_T RED_Tz3_InitialValue[256];  // Computed Parameter: RED_Tz3_InitialValue
                                        //  Referenced by: '<Root>/RED_Tz3'

  int32_T UDPSend1_Port;               // Computed Parameter: UDPSend1_Port
                                          //  Referenced by: '<S174>/UDP Send1'

  int32_T UDPSend2_Port;               // Computed Parameter: UDPSend2_Port
                                          //  Referenced by: '<S175>/UDP Send2'

  int32_T UDPSend3_Port;               // Computed Parameter: UDPSend3_Port
                                          //  Referenced by: '<S176>/UDP Send3'

  int32_T ReceivePhaseSpaceData_Port;
                               // Computed Parameter: ReceivePhaseSpaceData_Port
                                  //  Referenced by: '<S183>/Receive PhaseSpace Data'

  int32_T Delay_InitialCondition_j;
                                 // Computed Parameter: Delay_InitialCondition_j
                                    //  Referenced by: '<S188>/Delay'

  int32_T Delay1_InitialCondition_d;
                                // Computed Parameter: Delay1_InitialCondition_d
                                   //  Referenced by: '<S188>/Delay1'

  int32_T Delay2_InitialCondition_ak;
                               // Computed Parameter: Delay2_InitialCondition_ak
                                  //  Referenced by: '<S188>/Delay2'

  int32_T UDPReceive_Port;             // Computed Parameter: UDPReceive_Port
                                          //  Referenced by: '<S188>/UDP Receive'

  int32_T UDPReceive2_Port;            // Computed Parameter: UDPReceive2_Port
                                          //  Referenced by: '<S188>/UDP Receive2'

  int32_T UDPReceive3_Port;            // Computed Parameter: UDPReceive3_Port
                                          //  Referenced by: '<S188>/UDP Receive3'

  int32_T UDPReceive1_Port;            // Computed Parameter: UDPReceive1_Port
                                          //  Referenced by: '<S226>/UDP Receive1'

  int32_T UDPSend_Port;                // Computed Parameter: UDPSend_Port
                                          //  Referenced by: '<S232>/UDP Send'

  int32_T UDPSend_Port_h;              // Computed Parameter: UDPSend_Port_h
                                          //  Referenced by: '<S26>/UDP Send'

  P_EnabledSubsystem_Fullexp_d_T EnabledSubsystem_a;// '<S214>/Enabled Subsystem' 
  P_EnabledSubsystem_Fullexp_T EnabledSubsystem_k;// '<S213>/Enabled Subsystem'
  P_EnabledSubsystem_Fullexp_d_T EnabledSubsystem_g;// '<S204>/Enabled Subsystem' 
  P_EnabledSubsystem_Fullexp_T EnabledSubsystem_l;// '<S203>/Enabled Subsystem'
  P_EnabledSubsystem_Fullexp_d_T EnabledSubsystem_n;// '<S194>/Enabled Subsystem' 
  P_EnabledSubsystem_Fullexp_T EnabledSubsystem_m;// '<S193>/Enabled Subsystem'
  P_ChangeBLACKBehavior_Fullexp_T ChangeREDBehavior;// '<S4>/Change RED Behavior' 
  P_ChangeBLACKBehavior_Fullexp_T ChangeBLUEBehavior;// '<S4>/Change BLUE Behavior' 
  P_ChangeBLACKBehavior_Fullexp_T ChangeBLACKBehavior;// '<S4>/Change BLACK Behavior' 
  P_CustomControlRED_Fullexp_T CustomControlARM;// '<S3>/Custom Control (ARM)'
  P_DisableThrustersBLACK_Fulle_T DisableThrustersBLUE;// '<S3>/Disable Thrusters (BLUE)' 
  P_DisableThrustersBLACK_Fulle_T DisableThrustersBLACK;// '<S3>/Disable Thrusters (BLACK)' 
  P_CustomControlRED_Fullexp_T DisableThrustersRED;// '<S3>/Disable Thrusters (RED)' 
  P_CustomControlRED_Fullexp_T CustomControlRED;// '<S3>/Custom Control (RED)'
  P_Phase4ReturnHome_Fullexp_T Phase5HoldHome;// '<S1>/Phase #5: Hold Home'
  P_Phase4ReturnHome_Fullexp_T Phase4ReturnHome;// '<S1>/Phase #4: Return Home'
  P_Phase0Synchronization_Fulle_T Phase1StartFloating;// '<S1>/Phase #1: Start Floating ' 
  P_Phase0Synchronization_Fulle_T Phase0Synchronization;// '<S1>/Phase #0: Synchronization' 
};

// Real-time Model Data Structure
struct tag_RTM_Fullexp_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;

  time_T** getTPtrPtr();
  boolean_T getStopRequested() const;
  void setStopRequested(boolean_T aStopRequested);
  const char_T* getErrorStatus() const;
  void setErrorStatus(const char_T* const aErrorStatus);
  time_T* getTPtr() const;
  void setTPtr(time_T* aTPtr);
  boolean_T* getStopRequestedPtr();
  const char_T** getErrorStatusPtr();
  boolean_T isMajorTimeStep() const;
  boolean_T isMinorTimeStep() const;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_Fullexp_T Fullexp_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_Fullexp_T Fullexp_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_Fullexp_T Fullexp_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void Fullexp_initialize(void);
  extern void Fullexp_step(void);
  extern void Fullexp_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_Fullexp_T *const Fullexp_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S131>/Data Type Duplicate' : Unused code path elimination
//  Block '<S132>/Data Type Duplicate' : Unused code path elimination
//  Block '<S133>/Data Type Duplicate' : Unused code path elimination
//  Block '<S136>/Data Type Duplicate' : Unused code path elimination
//  Block '<S137>/Data Type Duplicate' : Unused code path elimination
//  Block '<S138>/Data Type Duplicate' : Unused code path elimination
//  Block '<S141>/Data Type Duplicate' : Unused code path elimination
//  Block '<S142>/Data Type Duplicate' : Unused code path elimination
//  Block '<S143>/Data Type Duplicate' : Unused code path elimination
//  Block '<S122>/Scope' : Unused code path elimination
//  Block '<S150>/Data Type Duplicate' : Unused code path elimination
//  Block '<S151>/Data Type Duplicate' : Unused code path elimination
//  Block '<S152>/Data Type Duplicate' : Unused code path elimination
//  Block '<S154>/Data Type Duplicate' : Unused code path elimination
//  Block '<S155>/Data Type Duplicate' : Unused code path elimination
//  Block '<S156>/Data Type Duplicate' : Unused code path elimination
//  Block '<S159>/Data Type Duplicate' : Unused code path elimination
//  Block '<S160>/Data Type Duplicate' : Unused code path elimination
//  Block '<S161>/Data Type Duplicate' : Unused code path elimination
//  Block '<S164>/Data Type Duplicate' : Unused code path elimination
//  Block '<S165>/Data Type Duplicate' : Unused code path elimination
//  Block '<S166>/Data Type Duplicate' : Unused code path elimination
//  Block '<Root>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' : Unused code path elimination
//  Block '<S106>/Reshape' : Reshape block reduction
//  Block '<S107>/Reshape1' : Reshape block reduction
//  Block '<S93>/Reshape' : Reshape block reduction
//  Block '<S93>/Reshape1' : Reshape block reduction
//  Block '<S111>/Reshape1' : Reshape block reduction
//  Block '<S112>/Reshape' : Reshape block reduction
//  Block '<S94>/Reshape' : Reshape block reduction
//  Block '<S94>/Reshape1' : Reshape block reduction
//  Block '<S6>/Reshape' : Reshape block reduction
//  Block '<S6>/Reshape1' : Reshape block reduction
//  Block '<S6>/Reshape2' : Reshape block reduction
//  Block '<S6>/Reshape3' : Reshape block reduction
//  Block '<S6>/Reshape4' : Reshape block reduction
//  Block '<S6>/Reshape5' : Reshape block reduction
//  Block '<S6>/Reshape6' : Reshape block reduction
//  Block '<S6>/Reshape7' : Reshape block reduction
//  Block '<S6>/Reshape8' : Reshape block reduction
//  Block '<S6>/Reshape9' : Reshape block reduction
//  Block '<S174>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S175>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S176>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S183>/Reshape' : Reshape block reduction
//  Block '<S184>/Reshape' : Reshape block reduction
//  Block '<S185>/Reshape' : Reshape block reduction
//  Block '<S186>/Reshape' : Reshape block reduction


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'Fullexp'
//  '<S1>'   : 'Fullexp/1 - Experiment Logic'
//  '<S2>'   : 'Fullexp/2 - Guidance'
//  '<S3>'   : 'Fullexp/3 - Control'
//  '<S4>'   : 'Fullexp/Check  Connection'
//  '<S5>'   : 'Fullexp/DQMEKF'
//  '<S6>'   : 'Fullexp/Data Logger Subsystem'
//  '<S7>'   : 'Fullexp/Debugger'
//  '<S8>'   : 'Fullexp/Float Code'
//  '<S9>'   : 'Fullexp/Gyro.//Accel. Code'
//  '<S10>'  : 'Fullexp/MATLAB Function'
//  '<S11>'  : 'Fullexp/MATLAB Function1'
//  '<S12>'  : 'Fullexp/Manipulator Encoder Data'
//  '<S13>'  : 'Fullexp/PhaseSpace Camera Code'
//  '<S14>'  : 'Fullexp/Platform  Identification'
//  '<S15>'  : 'Fullexp/Pose'
//  '<S16>'  : 'Fullexp/QMEKF'
//  '<S17>'  : 'Fullexp/RMEKF'
//  '<S18>'  : 'Fullexp/Receive Data '
//  '<S19>'  : 'Fullexp/Representations'
//  '<S20>'  : 'Fullexp/Representations1'
//  '<S21>'  : 'Fullexp/Robotic  Arm Code'
//  '<S22>'  : 'Fullexp/STDQMEKF'
//  '<S23>'  : 'Fullexp/STQMEKF'
//  '<S24>'  : 'Fullexp/Send Data  to Orin'
//  '<S25>'  : 'Fullexp/Simulation  Status'
//  '<S26>'  : 'Fullexp/Thruster Control Code'
//  '<S27>'  : 'Fullexp/1 - Experiment Logic/Phase #0: Synchronization'
//  '<S28>'  : 'Fullexp/1 - Experiment Logic/Phase #1: Start Floating '
//  '<S29>'  : 'Fullexp/1 - Experiment Logic/Phase #2: Initial Position'
//  '<S30>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment'
//  '<S31>'  : 'Fullexp/1 - Experiment Logic/Phase #4: Return Home'
//  '<S32>'  : 'Fullexp/1 - Experiment Logic/Phase #5: Hold Home'
//  '<S33>'  : 'Fullexp/1 - Experiment Logic/Phase #6: Clean Shutdown'
//  '<S34>'  : 'Fullexp/1 - Experiment Logic/Phase #2: Initial Position/Desired Joint Angles RED'
//  '<S35>'  : 'Fullexp/1 - Experiment Logic/Phase #2: Initial Position/Desired Position BLACK'
//  '<S36>'  : 'Fullexp/1 - Experiment Logic/Phase #2: Initial Position/Desired Position BLUE'
//  '<S37>'  : 'Fullexp/1 - Experiment Logic/Phase #2: Initial Position/Desired Position RED'
//  '<S38>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1'
//  '<S39>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 '
//  '<S40>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 '
//  '<S41>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4'
//  '<S42>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Joint Angles RED'
//  '<S43>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLACK'
//  '<S44>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLUE'
//  '<S45>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position RED'
//  '<S46>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLUE/Calculate Circular Tracking'
//  '<S47>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLUE/Calculate Time since Phase #3 Start'
//  '<S48>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLUE/Wrap'
//  '<S49>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLUE/Calculate Time since Phase #3 Start/Subsystem'
//  '<S50>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Joint Angles RED'
//  '<S51>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLACK'
//  '<S52>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLUE'
//  '<S53>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position RED'
//  '<S54>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLACK/BLACK_Rz Desired'
//  '<S55>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLACK/Wrap'
//  '<S56>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLACK/BLACK_Rz Desired/Subsystem'
//  '<S57>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLUE/Calculate Circular Tracking'
//  '<S58>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLUE/Calculate Time since Phase #3 Start'
//  '<S59>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLUE/Wrap'
//  '<S60>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLUE/Calculate Time since Phase #3 Start/Subsystem'
//  '<S61>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Joint Angles RED'
//  '<S62>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position BLUE'
//  '<S63>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position RED1'
//  '<S64>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position RED2'
//  '<S65>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position BLUE/Calculate Circular Tracking'
//  '<S66>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position BLUE/Calculate Time since Phase #3 Start'
//  '<S67>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position BLUE/Wrap'
//  '<S68>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position BLUE/Calculate Time since Phase #3 Start/Subsystem'
//  '<S69>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position RED2/BLACK_Rz Desired'
//  '<S70>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position RED2/MATLAB Function'
//  '<S71>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position RED2/Wrap'
//  '<S72>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position RED2/BLACK_Rz Desired/Subsystem'
//  '<S73>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Joint Angles RED'
//  '<S74>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position BLACK1'
//  '<S75>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position BLUE'
//  '<S76>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position RED1'
//  '<S77>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position BLUE/Calculate Circular Tracking'
//  '<S78>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position BLUE/Calculate Time since Phase #3 Start'
//  '<S79>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position BLUE/Wrap'
//  '<S80>'  : 'Fullexp/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position BLUE/Calculate Time since Phase #3 Start/Subsystem'
//  '<S81>'  : 'Fullexp/1 - Experiment Logic/Phase #4: Return Home/Desired Joint Angles RED'
//  '<S82>'  : 'Fullexp/1 - Experiment Logic/Phase #4: Return Home/Desired Position BLACK'
//  '<S83>'  : 'Fullexp/1 - Experiment Logic/Phase #4: Return Home/Desired Position BLUE'
//  '<S84>'  : 'Fullexp/1 - Experiment Logic/Phase #4: Return Home/Desired Position RED'
//  '<S85>'  : 'Fullexp/1 - Experiment Logic/Phase #5: Hold Home/Desired Joint Angles RED'
//  '<S86>'  : 'Fullexp/1 - Experiment Logic/Phase #5: Hold Home/Desired Position BLACK'
//  '<S87>'  : 'Fullexp/1 - Experiment Logic/Phase #5: Hold Home/Desired Position BLUE'
//  '<S88>'  : 'Fullexp/1 - Experiment Logic/Phase #5: Hold Home/Desired Position RED'
//  '<S89>'  : 'Fullexp/2 - Guidance/Custom PPL (ARM)'
//  '<S90>'  : 'Fullexp/2 - Guidance/Custom PPL (BLACK)'
//  '<S91>'  : 'Fullexp/2 - Guidance/Custom PPL (BLUE)'
//  '<S92>'  : 'Fullexp/2 - Guidance/Custom PPL (RED)'
//  '<S93>'  : 'Fullexp/2 - Guidance/Default APF PPL (BLACK)'
//  '<S94>'  : 'Fullexp/2 - Guidance/Default APF PPL (RED)'
//  '<S95>'  : 'Fullexp/2 - Guidance/Disable PPL (ARM)'
//  '<S96>'  : 'Fullexp/2 - Guidance/Disable PPL (BLACK)'
//  '<S97>'  : 'Fullexp/2 - Guidance/Disable PPL (BLUE)'
//  '<S98>'  : 'Fullexp/2 - Guidance/Disable PPL (RED)'
//  '<S99>'  : 'Fullexp/2 - Guidance/Custom PPL (ARM)/Desired Position'
//  '<S100>' : 'Fullexp/2 - Guidance/Custom PPL (BLACK)/Desired Position'
//  '<S101>' : 'Fullexp/2 - Guidance/Custom PPL (BLUE)/Desired Position'
//  '<S102>' : 'Fullexp/2 - Guidance/Custom PPL (RED)/Desired Position'
//  '<S103>' : 'Fullexp/2 - Guidance/Default APF PPL (BLACK)/Current Position RED'
//  '<S104>' : 'Fullexp/2 - Guidance/Default APF PPL (BLACK)/MATLAB Function'
//  '<S105>' : 'Fullexp/2 - Guidance/Default APF PPL (BLACK)/Obstacles'
//  '<S106>' : 'Fullexp/2 - Guidance/Default APF PPL (BLACK)/Obstacles/Current Position BLUE'
//  '<S107>' : 'Fullexp/2 - Guidance/Default APF PPL (BLACK)/Obstacles/Current Position RED'
//  '<S108>' : 'Fullexp/2 - Guidance/Default APF PPL (RED)/Current Position RED'
//  '<S109>' : 'Fullexp/2 - Guidance/Default APF PPL (RED)/MATLAB Function'
//  '<S110>' : 'Fullexp/2 - Guidance/Default APF PPL (RED)/Obstacles'
//  '<S111>' : 'Fullexp/2 - Guidance/Default APF PPL (RED)/Obstacles/Current Position BLACK'
//  '<S112>' : 'Fullexp/2 - Guidance/Default APF PPL (RED)/Obstacles/Current Position BLUE'
//  '<S113>' : 'Fullexp/2 - Guidance/Disable PPL (ARM)/Desired Position'
//  '<S114>' : 'Fullexp/2 - Guidance/Disable PPL (BLACK)/Desired Position'
//  '<S115>' : 'Fullexp/2 - Guidance/Disable PPL (BLUE)/Desired Position'
//  '<S116>' : 'Fullexp/2 - Guidance/Disable PPL (RED)/Desired Position'
//  '<S117>' : 'Fullexp/3 - Control/Custom Control (ARM)'
//  '<S118>' : 'Fullexp/3 - Control/Custom Control (RED)'
//  '<S119>' : 'Fullexp/3 - Control/Default LQR Control (BLACK)'
//  '<S120>' : 'Fullexp/3 - Control/Default LQR Control (BLUE)'
//  '<S121>' : 'Fullexp/3 - Control/Default LQR Control (RED)'
//  '<S122>' : 'Fullexp/3 - Control/Default PD (ARM)'
//  '<S123>' : 'Fullexp/3 - Control/Default PD Control (BLACK)'
//  '<S124>' : 'Fullexp/3 - Control/Default PD Control (BLUE)'
//  '<S125>' : 'Fullexp/3 - Control/Default PD Control (RED)'
//  '<S126>' : 'Fullexp/3 - Control/Disable Control (ARM)'
//  '<S127>' : 'Fullexp/3 - Control/Disable Thrusters (BLACK)'
//  '<S128>' : 'Fullexp/3 - Control/Disable Thrusters (BLUE)'
//  '<S129>' : 'Fullexp/3 - Control/Disable Thrusters (RED)'
//  '<S130>' : 'Fullexp/3 - Control/Default LQR Control (BLACK)/Calculate Error'
//  '<S131>' : 'Fullexp/3 - Control/Default LQR Control (BLACK)/Discrete Derivative'
//  '<S132>' : 'Fullexp/3 - Control/Default LQR Control (BLACK)/Discrete Derivative1'
//  '<S133>' : 'Fullexp/3 - Control/Default LQR Control (BLACK)/Discrete Derivative2'
//  '<S134>' : 'Fullexp/3 - Control/Default LQR Control (BLACK)/Calculate Error/MATLAB Function'
//  '<S135>' : 'Fullexp/3 - Control/Default LQR Control (BLUE)/Calculate Error'
//  '<S136>' : 'Fullexp/3 - Control/Default LQR Control (BLUE)/Discrete Derivative'
//  '<S137>' : 'Fullexp/3 - Control/Default LQR Control (BLUE)/Discrete Derivative1'
//  '<S138>' : 'Fullexp/3 - Control/Default LQR Control (BLUE)/Discrete Derivative2'
//  '<S139>' : 'Fullexp/3 - Control/Default LQR Control (BLUE)/Calculate Error/MATLAB Function'
//  '<S140>' : 'Fullexp/3 - Control/Default LQR Control (RED)/Calculate Error'
//  '<S141>' : 'Fullexp/3 - Control/Default LQR Control (RED)/Discrete Derivative'
//  '<S142>' : 'Fullexp/3 - Control/Default LQR Control (RED)/Discrete Derivative1'
//  '<S143>' : 'Fullexp/3 - Control/Default LQR Control (RED)/Discrete Derivative2'
//  '<S144>' : 'Fullexp/3 - Control/Default LQR Control (RED)/Calculate Error/MATLAB Function'
//  '<S145>' : 'Fullexp/3 - Control/Default PD (ARM)/Passthrough for Experiment'
//  '<S146>' : 'Fullexp/3 - Control/Default PD (ARM)/Simulated Position Controller'
//  '<S147>' : 'Fullexp/3 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Elbow)'
//  '<S148>' : 'Fullexp/3 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Shoulder)'
//  '<S149>' : 'Fullexp/3 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Wrist)'
//  '<S150>' : 'Fullexp/3 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Elbow)/Discrete Derivative1'
//  '<S151>' : 'Fullexp/3 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Shoulder)/Discrete Derivative1'
//  '<S152>' : 'Fullexp/3 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Wrist)/Discrete Derivative1'
//  '<S153>' : 'Fullexp/3 - Control/Default PD Control (BLACK)/Calculate Error'
//  '<S154>' : 'Fullexp/3 - Control/Default PD Control (BLACK)/Discrete Derivative'
//  '<S155>' : 'Fullexp/3 - Control/Default PD Control (BLACK)/Discrete Derivative1'
//  '<S156>' : 'Fullexp/3 - Control/Default PD Control (BLACK)/Discrete Derivative2'
//  '<S157>' : 'Fullexp/3 - Control/Default PD Control (BLACK)/Calculate Error/MATLAB Function'
//  '<S158>' : 'Fullexp/3 - Control/Default PD Control (BLUE)/Calculate Error'
//  '<S159>' : 'Fullexp/3 - Control/Default PD Control (BLUE)/Discrete Derivative'
//  '<S160>' : 'Fullexp/3 - Control/Default PD Control (BLUE)/Discrete Derivative1'
//  '<S161>' : 'Fullexp/3 - Control/Default PD Control (BLUE)/Discrete Derivative2'
//  '<S162>' : 'Fullexp/3 - Control/Default PD Control (BLUE)/Calculate Error/MATLAB Function'
//  '<S163>' : 'Fullexp/3 - Control/Default PD Control (RED)/Calculate Error'
//  '<S164>' : 'Fullexp/3 - Control/Default PD Control (RED)/Discrete Derivative'
//  '<S165>' : 'Fullexp/3 - Control/Default PD Control (RED)/Discrete Derivative1'
//  '<S166>' : 'Fullexp/3 - Control/Default PD Control (RED)/Discrete Derivative2'
//  '<S167>' : 'Fullexp/3 - Control/Default PD Control (RED)/Calculate Error/MATLAB Function'
//  '<S168>' : 'Fullexp/Check  Connection/Change BLACK Behavior'
//  '<S169>' : 'Fullexp/Check  Connection/Change BLUE Behavior'
//  '<S170>' : 'Fullexp/Check  Connection/Change RED Behavior'
//  '<S171>' : 'Fullexp/DQMEKF/MATLAB Function1'
//  '<S172>' : 'Fullexp/Data Logger Subsystem/Data Logger1'
//  '<S173>' : 'Fullexp/Data Logger Subsystem/Data Logger1/MATLAB Function'
//  '<S174>' : 'Fullexp/Debugger/Change BLACK Behavior'
//  '<S175>' : 'Fullexp/Debugger/Change BLUE Behavior'
//  '<S176>' : 'Fullexp/Debugger/Change RED Behavior'
//  '<S177>' : 'Fullexp/Float Code/Enable Pucks'
//  '<S178>' : 'Fullexp/Gyro.//Accel. Code/Log Gyro//Accel'
//  '<S179>' : 'Fullexp/Gyro.//Accel. Code/Log Gyro//Accel/Parse IMU Data'
//  '<S180>' : 'Fullexp/Manipulator Encoder Data/Change ARM Behavior'
//  '<S181>' : 'Fullexp/PhaseSpace Camera Code/Initialize Universal Time (Simulation)'
//  '<S182>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States'
//  '<S183>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data'
//  '<S184>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data'
//  '<S185>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data'
//  '<S186>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data'
//  '<S187>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data/Adjust Time '
//  '<S188>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data/Check for Sychronization'
//  '<S189>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data/Adjust Time /Enabled Subsystem'
//  '<S190>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data/Adjust Time /Enabled Subsystem1'
//  '<S191>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data/Check for Sychronization/MATLAB Function'
//  '<S192>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Calculate True  Time Step'
//  '<S193>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem1'
//  '<S194>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem2'
//  '<S195>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Wrap'
//  '<S196>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Calculate True  Time Step/Enabled Subsystem3'
//  '<S197>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Calculate True  Time Step/MATLAB Function'
//  '<S198>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem1/Enabled Subsystem'
//  '<S199>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem1/Enabled Subsystem/MATLAB Function'
//  '<S200>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem2/Enabled Subsystem'
//  '<S201>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem2/Enabled Subsystem/MATLAB Function'
//  '<S202>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Calculate True  Time Step'
//  '<S203>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem1'
//  '<S204>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem2'
//  '<S205>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Wrap'
//  '<S206>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Calculate True  Time Step/Enabled Subsystem3'
//  '<S207>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Calculate True  Time Step/MATLAB Function'
//  '<S208>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem1/Enabled Subsystem'
//  '<S209>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem1/Enabled Subsystem/MATLAB Function'
//  '<S210>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem2/Enabled Subsystem'
//  '<S211>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem2/Enabled Subsystem/MATLAB Function'
//  '<S212>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Calculate True  Time Step'
//  '<S213>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem1'
//  '<S214>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem2'
//  '<S215>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Wrap'
//  '<S216>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Calculate True  Time Step/Enabled Subsystem3'
//  '<S217>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Calculate True  Time Step/MATLAB Function'
//  '<S218>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem1/Enabled Subsystem'
//  '<S219>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem1/Enabled Subsystem/MATLAB Function'
//  '<S220>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem2/Enabled Subsystem'
//  '<S221>' : 'Fullexp/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem2/Enabled Subsystem/MATLAB Function'
//  '<S222>' : 'Fullexp/Platform  Identification/Subsystem'
//  '<S223>' : 'Fullexp/Pose/MATLAB Function'
//  '<S224>' : 'Fullexp/QMEKF/MATLAB Function1'
//  '<S225>' : 'Fullexp/RMEKF/MATLAB Function1'
//  '<S226>' : 'Fullexp/Receive Data /Subsystem'
//  '<S227>' : 'Fullexp/Representations/MATLAB Function'
//  '<S228>' : 'Fullexp/Representations1/MATLAB Function'
//  '<S229>' : 'Fullexp/Robotic  Arm Code/Change ARM Behavior'
//  '<S230>' : 'Fullexp/STDQMEKF/MATLAB Function1'
//  '<S231>' : 'Fullexp/STQMEKF/MATLAB Function1'
//  '<S232>' : 'Fullexp/Send Data  to Orin/Subsystem'
//  '<S233>' : 'Fullexp/Thruster Control Code/Change BLACK Behavior'
//  '<S234>' : 'Fullexp/Thruster Control Code/Change BLUE Behavior'
//  '<S235>' : 'Fullexp/Thruster Control Code/Change RED Behavior'
//  '<S236>' : 'Fullexp/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle'
//  '<S237>' : 'Fullexp/Thruster Control Code/Change BLACK Behavior/Rotate Forces to Body'
//  '<S238>' : 'Fullexp/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Duty Cycle @ PWM'
//  '<S239>' : 'Fullexp/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Generate Initial Guess'
//  '<S240>' : 'Fullexp/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/MATLAB Function1'
//  '<S241>' : 'Fullexp/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/MATLAB Function5'
//  '<S242>' : 'Fullexp/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Rotate Forces to Inertial'
//  '<S243>' : 'Fullexp/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem'
//  '<S244>' : 'Fullexp/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem1'
//  '<S245>' : 'Fullexp/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Generate Initial Guess/MATLAB Function'
//  '<S246>' : 'Fullexp/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Rotate Forces to Inertial/Create Rotation Matrix'
//  '<S247>' : 'Fullexp/Thruster Control Code/Change BLACK Behavior/Rotate Forces to Body/Create Rotation Matrix'
//  '<S248>' : 'Fullexp/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle'
//  '<S249>' : 'Fullexp/Thruster Control Code/Change BLUE Behavior/Rotate Forces to Body'
//  '<S250>' : 'Fullexp/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Duty Cycle @ PWM'
//  '<S251>' : 'Fullexp/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Generate Initial Guess'
//  '<S252>' : 'Fullexp/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/MATLAB Function1'
//  '<S253>' : 'Fullexp/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/MATLAB Function5'
//  '<S254>' : 'Fullexp/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Rotate Forces to Inertial'
//  '<S255>' : 'Fullexp/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem'
//  '<S256>' : 'Fullexp/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem1'
//  '<S257>' : 'Fullexp/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Generate Initial Guess/MATLAB Function'
//  '<S258>' : 'Fullexp/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Rotate Forces to Inertial/Create Rotation Matrix'
//  '<S259>' : 'Fullexp/Thruster Control Code/Change BLUE Behavior/Rotate Forces to Body/Create Rotation Matrix'
//  '<S260>' : 'Fullexp/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle'
//  '<S261>' : 'Fullexp/Thruster Control Code/Change RED Behavior/Rotate Forces to Body'
//  '<S262>' : 'Fullexp/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Duty Cycle @ PWM'
//  '<S263>' : 'Fullexp/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Generate Initial Guess'
//  '<S264>' : 'Fullexp/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/MATLAB Function5'
//  '<S265>' : 'Fullexp/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/MATLAB Function8'
//  '<S266>' : 'Fullexp/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Rotate Forces to Inertial'
//  '<S267>' : 'Fullexp/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem'
//  '<S268>' : 'Fullexp/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem1'
//  '<S269>' : 'Fullexp/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Generate Initial Guess/MATLAB Function'
//  '<S270>' : 'Fullexp/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Rotate Forces to Inertial/Create Rotation Matrix'
//  '<S271>' : 'Fullexp/Thruster Control Code/Change RED Behavior/Rotate Forces to Body/Create Rotation Matrix'

#endif                                 // Fullexp_h_

//
// File trailer for generated code.
//
// [EOF]
//
