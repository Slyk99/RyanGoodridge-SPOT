//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: STQMEKF.h
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
#ifndef STQMEKF_h_
#define STQMEKF_h_
#include <cstdio>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "DAHostLib_Network.h"
#include "custom_data_logger.h"
#include "gpio_control.h"
#include "MW_I2C.h"
#include "dynamixel_functions.h"
#include "dynamixel_sdk.h"
#include "resource_headers.h"
#include "STQMEKF_types.h"

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
struct DW_ChangeBLACKBehavior_STQMEK_T {
  real_T UDPSend_NetworkLib[137];      // '<S159>/UDP Send'
};

// Block signals for system '<S183>/Enabled Subsystem'
struct B_EnabledSubsystem_STQMEKF_T {
  real_T Delay[3];                     // '<S188>/Delay'
  real_T Delay1[3];                    // '<S188>/Delay1'
  real_T ema[3];                       // '<S188>/MATLAB Function'
};

// Block states (default storage) for system '<S183>/Enabled Subsystem'
struct DW_EnabledSubsystem_STQMEKF_T {
  real_T Delay_DSTATE[3];              // '<S188>/Delay'
  real_T Delay1_DSTATE[3];             // '<S188>/Delay1'
  boolean_T icLoad;                    // '<S188>/Delay'
  boolean_T EnabledSubsystem_MODE;     // '<S183>/Enabled Subsystem'
};

// Block signals for system '<S184>/Enabled Subsystem'
struct B_EnabledSubsystem_STQMEKF_b_T {
  real_T Delay[3];                     // '<S190>/Delay'
  real_T Delay1[3];                    // '<S190>/Delay1'
  real_T ema[3];                       // '<S190>/MATLAB Function'
};

// Block states (default storage) for system '<S184>/Enabled Subsystem'
struct DW_EnabledSubsystem_STQMEKF_m_T {
  real_T Delay_DSTATE[3];              // '<S190>/Delay'
  real_T Delay1_DSTATE[3];             // '<S190>/Delay1'
  boolean_T icLoad;                    // '<S190>/Delay'
  boolean_T EnabledSubsystem_MODE;     // '<S184>/Enabled Subsystem'
};

// Block signals for system '<S231>/Pseudoinverse1'
struct B_Pseudoinverse1_STQMEKF_T {
  real_T Pseudoinverse1[24];           // '<S231>/Pseudoinverse1'
};

// Block states (default storage) for system '<S231>/Pseudoinverse1'
struct DW_Pseudoinverse1_STQMEKF_T {
  dsp_simulink_Pseudoinverse_ST_T obj; // '<S231>/Pseudoinverse1'
  boolean_T objisempty;                // '<S231>/Pseudoinverse1'
};

// Block signals (default storage)
struct B_STQMEKF_T {
  smSS6fEwaptVbzYAOdOZgjB_STQME_T obj;
  smSS6fEwaptVbzYAOdOZgjB_STQME_T obj_m;
  smSS6fEwaptVbzYAOdOZgjB_STQME_T obj_c;
  real_T augJacobian[576];
  real_T Merge1[3];                    // '<S3>/Merge1'
  real_T Merge2[3];                    // '<S3>/Merge2'
  real_T Merge[3];                     // '<S3>/Merge'
  real_T TmpSignalConversionAtUDPSendInp[10];
  real_T duty_cycles[8];               // '<S252>/MATLAB Function5'
  real_T ThrustPer_Final[8];           // '<S260>/ThrustPer_Final'
  real_T In1;                          // '<S259>/In1'
  real_T duty_cycles_p[8];             // '<S240>/MATLAB Function5'
  real_T ThrustPer_Final_h[8];         // '<S248>/ThrustPer_Final'
  real_T In1_g;                        // '<S247>/In1'
  real_T duty_cycles_l[8];             // '<S228>/MATLAB Function5'
  real_T ThrustPer_Final_h5[8];        // '<S236>/ThrustPer_Final'
  real_T In1_g2;                       // '<S235>/In1'
  real_T TmpSignalConversionAtUDPSendI_o[28];
  real_T x[13];                        // '<S218>/MATLAB Function'
  real_T P[144];                       // '<S218>/MATLAB Function'
  real_T V[36];                        // '<S218>/MATLAB Function'
  real_T ReceivePhaseSpaceData_o1[19]; // '<S173>/Receive PhaseSpace Data'
  real_T ConvertBLAXfrommmtom;        // '<S174>/Convert BLAX from [mm] to [m]'
  real_T ConvertBLUXfrommmtom;        // '<S175>/Convert BLUX from [mm] to [m]'
  real_T ConvertREDXfrommmtom;        // '<S176>/Convert REDX from [mm] to [m]'
  real_T Clock;                        // '<S173>/Clock'
  real_T dy[3];                        // '<S210>/MATLAB Function'
  real_T dy_l[3];                      // '<S208>/MATLAB Function'
  real_T y2y1;                         // '<S206>/y2-y1'
  real_T dy_c[3];                      // '<S200>/MATLAB Function'
  real_T dy_e[3];                      // '<S198>/MATLAB Function'
  real_T y2y1_o;                       // '<S196>/y2-y1'
  real_T dy_i[3];                      // '<S190>/MATLAB Function'
  real_T dy_k[3];                      // '<S188>/MATLAB Function'
  real_T y2y1_ob;                      // '<S186>/y2-y1'
  real_T Subtract;                     // '<S180>/Subtract'
  real_T Memory;                       // '<S179>/Memory'
  real32_T UDPReceive1_o1[4];          // '<S213>/UDP Receive1'
  int32_T UDPReceive_o1;               // '<S178>/UDP Receive'
  int32_T UDPReceive2_o1;              // '<S178>/UDP Receive2'
  int32_T UDPReceive3_o1;              // '<S178>/UDP Receive3'
  uint8_T StringtoASCII[31];           // '<S166>/String to ASCII'
  uint8_T StringtoASCII2[31];          // '<S165>/String to ASCII2'
  uint8_T StringtoASCII1[31];          // '<S164>/String to ASCII1'
  boolean_T RelationalOperator1;       // '<S177>/Relational Operator1'
  B_Pseudoinverse1_STQMEKF_T Pseudoinverse1_pn;// '<S231>/Pseudoinverse1'
  B_Pseudoinverse1_STQMEKF_T Pseudoinverse1_p;// '<S231>/Pseudoinverse1'
  B_Pseudoinverse1_STQMEKF_T Pseudoinverse1;// '<S231>/Pseudoinverse1'
  B_EnabledSubsystem_STQMEKF_b_T EnabledSubsystem_a;// '<S204>/Enabled Subsystem' 
  B_EnabledSubsystem_STQMEKF_T EnabledSubsystem_k;// '<S203>/Enabled Subsystem'
  B_EnabledSubsystem_STQMEKF_b_T EnabledSubsystem_g;// '<S194>/Enabled Subsystem' 
  B_EnabledSubsystem_STQMEKF_T EnabledSubsystem_l;// '<S193>/Enabled Subsystem'
  B_EnabledSubsystem_STQMEKF_b_T EnabledSubsystem_n;// '<S184>/Enabled Subsystem' 
  B_EnabledSubsystem_STQMEKF_T EnabledSubsystem_m;// '<S183>/Enabled Subsystem'
};

// Block states (default storage) for system '<Root>'
struct DW_STQMEKF_T {
  nvidiacoder_sensors_BMI160Blo_T obj; // '<S168>/Gyroscope//Accelerometer'
  Dynamixel_Controller_STQMEKF_T obj_n;
  // '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
  GPIO_Write_STQMEKF_T obj_c;          // '<S167>/GPIO Write1'
  ReadArm_Position_Rates_STQMEK_T obj_d;
                     // '<S170>/Read Joint Positions using  Dynamixel Encoders'
  IdentifyPlatform_STQMEKF_T obj_dk;   // '<S212>/WhoAmI'
  CustomDataLogger_STQMEKF_T obj_m;    // '<S162>/MATLAB System'
  real_T Delay1_DSTATE;                // '<S217>/Delay1'
  real_T Delay_DSTATE;                 // '<S217>/Delay'
  real_T Delay2_DSTATE[13];            // '<S218>/Delay2'
  real_T Delay1_DSTATE_n[144];         // '<S218>/Delay1'
  real_T Delay3_DSTATE[36];            // '<S218>/Delay3'
  real_T Delay_DSTATE_b;               // '<S254>/Delay'
  real_T Delay_DSTATE_k;               // '<S242>/Delay'
  real_T Delay_DSTATE_kz;              // '<S230>/Delay'
  real_T Delay2_DSTATE_j;              // '<S182>/Delay2'
  real_T Delay1_DSTATE_i;              // '<S182>/Delay1'
  real_T Delay1_DSTATE_g[3];           // '<S184>/Delay1'
  real_T Delay1_DSTATE_b[3];           // '<S183>/Delay1'
  real_T Delay2_DSTATE_l;              // '<S192>/Delay2'
  real_T Delay1_DSTATE_l;              // '<S192>/Delay1'
  real_T Delay1_DSTATE_m[3];           // '<S194>/Delay1'
  real_T Delay1_DSTATE_lv[3];          // '<S193>/Delay1'
  real_T Delay2_DSTATE_l0;             // '<S202>/Delay2'
  real_T Delay1_DSTATE_ld;             // '<S202>/Delay1'
  real_T Delay1_DSTATE_c[3];           // '<S204>/Delay1'
  real_T Delay1_DSTATE_cq[3];          // '<S203>/Delay1'
  real_T Delay_DSTATE_o;               // '<S170>/Delay'
  real_T Delay1_DSTATE_cg;             // '<S170>/Delay1'
  real_T Delay2_DSTATE_h;              // '<S170>/Delay2'
  real_T UD_DSTATE;                    // '<S141>/UD'
  real_T UD_DSTATE_e;                  // '<S142>/UD'
  real_T UD_DSTATE_a;                  // '<S143>/UD'
  real_T UD_DSTATE_l;                  // '<S127>/UD'
  real_T UD_DSTATE_k;                  // '<S128>/UD'
  real_T UD_DSTATE_h;                  // '<S129>/UD'
  real_T UD_DSTATE_o;                  // '<S150>/UD'
  real_T UD_DSTATE_n;                  // '<S151>/UD'
  real_T UD_DSTATE_hu;                 // '<S152>/UD'
  real_T UD_DSTATE_j;                  // '<S122>/UD'
  real_T UD_DSTATE_c;                  // '<S123>/UD'
  real_T UD_DSTATE_d;                  // '<S124>/UD'
  real_T UD_DSTATE_eh;                 // '<S145>/UD'
  real_T UD_DSTATE_hv;                 // '<S146>/UD'
  real_T UD_DSTATE_kv;                 // '<S147>/UD'
  real_T UD_DSTATE_aq;                 // '<S132>/UD'
  real_T UD_DSTATE_p;                  // '<S133>/UD'
  real_T UD_DSTATE_pr;                 // '<S134>/UD'
  real_T UD_DSTATE_eg;                 // '<S155>/UD'
  real_T UD_DSTATE_cd;                 // '<S156>/UD'
  real_T UD_DSTATE_hd;                 // '<S157>/UD'
  real_T UDPSend_NetworkLib[137];      // '<S17>/UDP Send'
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
  real_T Confidance;                   // '<Root>/Universal_Time38'
  real_T BLUE_Measured_States[9];      // '<Root>/Universal_Time4'
  real_T BLUE_Saturated_Controls[3];   // '<Root>/Universal_Time6'
  real_T ARM_Desired_States[3];        // '<Root>/Universal_Time8'
  real_T BLACK_States_Vis_raw[7];      // '<Root>/Universal_Time9'
  real_T UDPSend_NetworkLib_m[137];    // '<S224>/UDP Send'
  real_T UDPReceive1_NetworkLib[137];  // '<S213>/UDP Receive1'
  real_T ReceivePhaseSpaceData_NetworkLi[137];// '<S173>/Receive PhaseSpace Data' 
  real_T UDPReceive_NetworkLib[137];   // '<S178>/UDP Receive'
  real_T UDPReceive2_NetworkLib[137];  // '<S178>/UDP Receive2'
  real_T UDPReceive3_NetworkLib[137];  // '<S178>/UDP Receive3'
  real_T Memory_PreviousInput;         // '<S179>/Memory'
  real_T UDPSend3_NetworkLib[137];     // '<S166>/UDP Send3'
  real_T UDPSend2_NetworkLib[137];     // '<S165>/UDP Send2'
  real_T UDPSend1_NetworkLib[137];     // '<S164>/UDP Send1'
  char_T RED_Logger[256];              // '<Root>/RED_Tz3'
  int32_T Delay_DSTATE_i[5];           // '<S178>/Delay'
  int32_T Delay1_DSTATE_h[5];          // '<S178>/Delay1'
  int32_T Delay2_DSTATE_hq[5];         // '<S178>/Delay2'
  int8_T Ifperforminganexperimentgrabthe;
  // '<S10>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 
  uint8_T pauseState;                  // '<S168>/Gyroscope//Accelerometer'
  DW_Pseudoinverse1_STQMEKF_T Pseudoinverse1_pn;// '<S231>/Pseudoinverse1'
  DW_Pseudoinverse1_STQMEKF_T Pseudoinverse1_p;// '<S231>/Pseudoinverse1'
  DW_Pseudoinverse1_STQMEKF_T Pseudoinverse1;// '<S231>/Pseudoinverse1'
  DW_EnabledSubsystem_STQMEKF_m_T EnabledSubsystem_a;// '<S204>/Enabled Subsystem' 
  DW_EnabledSubsystem_STQMEKF_T EnabledSubsystem_k;// '<S203>/Enabled Subsystem' 
  DW_EnabledSubsystem_STQMEKF_m_T EnabledSubsystem_g;// '<S194>/Enabled Subsystem' 
  DW_EnabledSubsystem_STQMEKF_T EnabledSubsystem_l;// '<S193>/Enabled Subsystem' 
  DW_EnabledSubsystem_STQMEKF_m_T EnabledSubsystem_n;// '<S184>/Enabled Subsystem' 
  DW_EnabledSubsystem_STQMEKF_T EnabledSubsystem_m;// '<S183>/Enabled Subsystem' 
  DW_ChangeBLACKBehavior_STQMEK_T ChangeREDBehavior;// '<S4>/Change RED Behavior' 
  DW_ChangeBLACKBehavior_STQMEK_T ChangeBLUEBehavior;// '<S4>/Change BLUE Behavior' 
  DW_ChangeBLACKBehavior_STQMEK_T ChangeBLACKBehavior;// '<S4>/Change BLACK Behavior' 
};

// Parameters for system: '<S1>/Phase #0: Synchronization'
struct P_Phase0Synchronization_STQME_T_ {
  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S18>/Constant1'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S18>/Constant2'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<S18>/Constant3'

  real_T Constant4_Value;              // Expression: 0
                                          //  Referenced by: '<S18>/Constant4'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<S18>/Constant5'

  real_T Constant6_Value;              // Expression: 0
                                          //  Referenced by: '<S18>/Constant6'

  real_T Constant7_Value;              // Expression: 0
                                          //  Referenced by: '<S18>/Constant7'

  real_T Constant8_Value;              // Expression: 0
                                          //  Referenced by: '<S18>/Constant8'

  real_T PuckState_Value;              // Expression: 0
                                          //  Referenced by: '<S18>/Puck State'

  char_T StringConstant_String[256];   // Expression: "Chaser: Running Phase 0"
                                          //  Referenced by: '<S18>/String Constant'

};

// Parameters for system: '<S1>/Phase #4: Return Home'
struct P_Phase4ReturnHome_STQMEKF_T_ {
  real_T Constant11_Value;             // Expression: 0
                                          //  Referenced by: '<S22>/Constant11'

  real_T Constant12_Value;             // Expression: 0
                                          //  Referenced by: '<S22>/Constant12'

  real_T Constant14_Value;             // Expression: 0
                                          //  Referenced by: '<S22>/Constant14'

  real_T Constant15_Value;             // Expression: 0
                                          //  Referenced by: '<S22>/Constant15'

  real_T Constant18_Value;             // Expression: 0
                                          //  Referenced by: '<S22>/Constant18'

  real_T Constant4_Value;              // Expression: 2
                                          //  Referenced by: '<S22>/Constant4'

  real_T Constant5_Value;              // Expression: 2
                                          //  Referenced by: '<S22>/Constant5'

  real_T Constant6_Value;              // Expression: 1
                                          //  Referenced by: '<S22>/Constant6'

  real_T Constant8_Value;              // Expression: 2
                                          //  Referenced by: '<S22>/Constant8'

  real_T Constant3_Value;              // Expression: pi/2
                                          //  Referenced by: '<S72>/Constant3'

  real_T Constant1_Value;              // Expression: pi/2
                                          //  Referenced by: '<S72>/Constant1'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S72>/Constant2'

};

// Parameters for system: '<S3>/Custom Control (RED)'
struct P_CustomControlRED_STQMEKF_T_ {
  real_T Zero_Value;                   // Expression: 0
                                          //  Referenced by: '<S109>/Zero'

};

// Parameters for system: '<S3>/Disable Thrusters (BLACK)'
struct P_DisableThrustersBLACK_STQME_T_ {
  real_T Zero_Value;                   // Expression: 0
                                          //  Referenced by: '<S118>/Zero'

};

// Parameters for system: '<S4>/Change BLACK Behavior'
struct P_ChangeBLACKBehavior_STQMEKF_T_ {
  int32_T Constant1_Value;             // Computed Parameter: Constant1_Value
                                          //  Referenced by: '<S159>/Constant1'

  int32_T UDPSend_Port;                // Computed Parameter: UDPSend_Port
                                          //  Referenced by: '<S159>/UDP Send'

};

// Parameters for system: '<S183>/Enabled Subsystem'
struct P_EnabledSubsystem_STQMEKF_T_ {
  real_T dydt_Y0;                      // Computed Parameter: dydt_Y0
                                          //  Referenced by: '<S188>/dy//dt'

  real_T Constant2_Value;              // Expression: 0.1
                                          //  Referenced by: '<S188>/Constant2'

  real_T Delay1_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S188>/Delay1'

};

// Parameters for system: '<S184>/Enabled Subsystem'
struct P_EnabledSubsystem_STQMEKF_d_T_ {
  real_T dydt_Y0;                      // Computed Parameter: dydt_Y0
                                          //  Referenced by: '<S190>/dy//dt'

  real_T Constant2_Value;              // Expression: 0.1
                                          //  Referenced by: '<S190>/Constant2'

  real_T Delay1_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S190>/Delay1'

};

// Parameters (default storage)
struct P_STQMEKF_T_ {
  real_T F_black_X_nominal;            // Variable: F_black_X_nominal
                                          //  Referenced by: '<S228>/MATLAB Function5'

  real_T F_black_Y_nominal;            // Variable: F_black_Y_nominal
                                          //  Referenced by: '<S228>/MATLAB Function5'

  real_T F_blue_X_nominal;             // Variable: F_blue_X_nominal
                                          //  Referenced by: '<S240>/MATLAB Function5'

  real_T F_blue_Y_nominal;             // Variable: F_blue_Y_nominal
                                          //  Referenced by: '<S240>/MATLAB Function5'

  real_T F_red_X_nominal;              // Variable: F_red_X_nominal
                                          //  Referenced by: '<S252>/MATLAB Function5'

  real_T F_red_Y_nominal;              // Variable: F_red_Y_nominal
                                          //  Referenced by: '<S252>/MATLAB Function5'

  real_T F_thrusters_BLACK[8];         // Variable: F_thrusters_BLACK
                                          //  Referenced by: '<S231>/MATLAB Function'

  real_T F_thrusters_BLUE[8];          // Variable: F_thrusters_BLUE
                                          //  Referenced by: '<S243>/MATLAB Function'

  real_T F_thrusters_RED[8];           // Variable: F_thrusters_RED
                                          //  Referenced by: '<S255>/MATLAB Function'

  real_T K_BLACK[18];                  // Variable: K_BLACK
                                          //  Referenced by: '<S110>/Constant2'

  real_T K_BLUE[18];                   // Variable: K_BLUE
                                          //  Referenced by: '<S111>/Constant2'

  real_T K_RED[18];                    // Variable: K_RED
                                          //  Referenced by: '<S112>/Constant2'

  real_T Kd_elarm;                     // Variable: Kd_elarm
                                          //  Referenced by: '<S138>/kd_elarm'

  real_T Kd_sharm;                     // Variable: Kd_sharm
                                          //  Referenced by: '<S139>/kd_sharm'

  real_T Kd_tb;                        // Variable: Kd_tb
                                          //  Referenced by: '<S114>/Gain5'

  real_T Kd_tblue;                     // Variable: Kd_tblue
                                          //  Referenced by: '<S115>/Gain5'

  real_T Kd_tr;                        // Variable: Kd_tr
                                          //  Referenced by: '<S116>/Gain5'

  real_T Kd_wrarm;                     // Variable: Kd_wrarm
                                          //  Referenced by: '<S140>/kd_wrarm'

  real_T Kd_xb;                        // Variable: Kd_xb
                                          //  Referenced by: '<S114>/Gain3'

  real_T Kd_xblue;                     // Variable: Kd_xblue
                                          //  Referenced by: '<S115>/Gain3'

  real_T Kd_xr;                        // Variable: Kd_xr
                                          //  Referenced by: '<S116>/Gain3'

  real_T Kd_yb;                        // Variable: Kd_yb
                                          //  Referenced by: '<S114>/Gain4'

  real_T Kd_yblue;                     // Variable: Kd_yblue
                                          //  Referenced by: '<S115>/Gain4'

  real_T Kd_yr;                        // Variable: Kd_yr
                                          //  Referenced by: '<S116>/Gain4'

  real_T Kp_elarm;                     // Variable: Kp_elarm
                                          //  Referenced by: '<S138>/kp_elarm'

  real_T Kp_sharm;                     // Variable: Kp_sharm
                                          //  Referenced by: '<S139>/kp_sharm'

  real_T Kp_tb;                        // Variable: Kp_tb
                                          //  Referenced by: '<S114>/Gain2'

  real_T Kp_tblue;                     // Variable: Kp_tblue
                                          //  Referenced by: '<S115>/Gain2'

  real_T Kp_tr;                        // Variable: Kp_tr
                                          //  Referenced by: '<S116>/Gain2'

  real_T Kp_wrarm;                     // Variable: Kp_wrarm
                                          //  Referenced by: '<S140>/kp_wrarm'

  real_T Kp_xb;                        // Variable: Kp_xb
                                          //  Referenced by: '<S114>/Gain'

  real_T Kp_xblue;                     // Variable: Kp_xblue
                                          //  Referenced by: '<S115>/Gain'

  real_T Kp_xr;                        // Variable: Kp_xr
                                          //  Referenced by: '<S116>/Gain'

  real_T Kp_yb;                        // Variable: Kp_yb
                                          //  Referenced by: '<S114>/Gain1'

  real_T Kp_yblue;                     // Variable: Kp_yblue
                                          //  Referenced by: '<S115>/Gain1'

  real_T Kp_yr;                        // Variable: Kp_yr
                                          //  Referenced by: '<S116>/Gain1'

  real_T PWMFreq;                      // Variable: PWMFreq
                                          //  Referenced by:
                                          //    '<S17>/PWM Frequency'
                                          //    '<S228>/MATLAB Function1'
                                          //    '<S240>/MATLAB Function1'
                                          //    '<S252>/MATLAB Function8'
                                          //    '<S230>/Constant1'
                                          //    '<S242>/Constant1'
                                          //    '<S254>/Constant1'

  real_T Phase0_End;                   // Variable: Phase0_End
                                          //  Referenced by: '<S1>/Constant4'

  real_T Phase1_End;                   // Variable: Phase1_End
                                          //  Referenced by: '<S1>/Constant'

  real_T Phase2_End;                   // Variable: Phase2_End
                                          //  Referenced by:
                                          //    '<S1>/Constant1'
                                          //    '<S38>/Constant2'
                                          //    '<S49>/Constant2'
                                          //    '<S57>/Constant2'
                                          //    '<S69>/Constant2'
                                          //    '<S47>/Constant1'
                                          //    '<S63>/Constant1'

  real_T Phase3_End;                   // Variable: Phase3_End
                                          //  Referenced by: '<S1>/Constant2'

  real_T Phase3_SubPhase1_End;         // Variable: Phase3_SubPhase1_End
                                          //  Referenced by: '<S21>/Constant4'

  real_T Phase3_SubPhase2_End;         // Variable: Phase3_SubPhase2_End
                                          //  Referenced by:
                                          //    '<S21>/Constant1'
                                          //    '<S55>/Constant'

  real_T Phase3_SubPhase3_End;         // Variable: Phase3_SubPhase3_End
                                          //  Referenced by: '<S21>/Constant2'

  real_T Phase3_SubPhase4_End;         // Variable: Phase3_SubPhase4_End
                                          //  Referenced by: '<S21>/Constant3'

  real_T Phase4_End;                   // Variable: Phase4_End
                                          //  Referenced by: '<S1>/Constant3'

  real_T Phase5_End;                   // Variable: Phase5_End
                                          //  Referenced by: '<S1>/Constant6'

  real_T Tz_lim_elarm;                 // Variable: Tz_lim_elarm
                                          //  Referenced by: '<S137>/Saturation1'

  real_T Tz_lim_sharm;                 // Variable: Tz_lim_sharm
                                          //  Referenced by: '<S137>/Saturation'

  real_T Tz_lim_wrarm;                 // Variable: Tz_lim_wrarm
                                          //  Referenced by: '<S137>/Saturation3'

  real_T baseRate;                     // Variable: baseRate
                                          //  Referenced by:
                                          //    '<S84>/MATLAB Function'
                                          //    '<S85>/MATLAB Function'
                                          //    '<S170>/Read Joint Positions using  Dynamixel Encoders'
                                          //    '<S212>/WhoAmI'
                                          //    '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T dataRate;                     // Variable: dataRate
                                          //  Referenced by:
                                          //    '<S182>/Constant'
                                          //    '<S192>/Constant'
                                          //    '<S202>/Constant'

  real_T home_states_BLACK[3];         // Variable: home_states_BLACK
                                          //  Referenced by:
                                          //    '<S73>/Desired States (BLACK)'
                                          //    '<S77>/Desired States (BLACK)'
                                          //    '<S65>/Constant'

  real_T home_states_BLUE[3];          // Variable: home_states_BLUE
                                          //  Referenced by:
                                          //    '<S74>/Desired States (BLUE)'
                                          //    '<S78>/Desired States (BLUE)'

  real_T home_states_RED[3];           // Variable: home_states_RED
                                          //  Referenced by:
                                          //    '<S75>/Constant2'
                                          //    '<S79>/Constant2'
                                          //    '<S67>/Constant'

  real_T init_states_BLACK[3];         // Variable: init_states_BLACK
                                          //  Referenced by:
                                          //    '<S26>/Desired States (BLACK)'
                                          //    '<S34>/Constant'

  real_T init_states_BLUE[3];          // Variable: init_states_BLUE
                                          //  Referenced by: '<S27>/Desired States (BLUE)'

  real_T init_states_RED[3];           // Variable: init_states_RED
                                          //  Referenced by:
                                          //    '<S28>/Constant2'
                                          //    '<S36>/Constant'
                                          //    '<S44>/Constant'
                                          //    '<S44>/Constant1'
                                          //    '<S44>/Constant4'
                                          //    '<S54>/Constant'

  real_T platformSelection;            // Variable: platformSelection
                                          //  Referenced by: '<S178>/MATLAB Function'

  real_T simMode;                      // Variable: simMode
                                          //  Referenced by: '<S16>/Constant'

  real_T thruster_dist2CG_BLACK[8];    // Variable: thruster_dist2CG_BLACK
                                          //  Referenced by:
                                          //    '<S228>/MATLAB Function5'
                                          //    '<S231>/MATLAB Function'

  real_T thruster_dist2CG_BLUE[8];     // Variable: thruster_dist2CG_BLUE
                                          //  Referenced by:
                                          //    '<S240>/MATLAB Function5'
                                          //    '<S243>/MATLAB Function'

  real_T thruster_dist2CG_RED[8];      // Variable: thruster_dist2CG_RED
                                          //  Referenced by:
                                          //    '<S252>/MATLAB Function5'
                                          //    '<S255>/MATLAB Function'

  real_T xLength;                      // Variable: xLength
                                          //  Referenced by:
                                          //    '<S42>/Desired X-Position (BLACK)'
                                          //    '<S37>/Constant1'
                                          //    '<S48>/Constant1'
                                          //    '<S56>/Constant1'
                                          //    '<S68>/Constant1'

  real_T yLength;                      // Variable: yLength
                                          //  Referenced by:
                                          //    '<S42>/Desired Y-Position (BLACK)'
                                          //    '<S37>/Constant2'
                                          //    '<S48>/Constant2'
                                          //    '<S56>/Constant2'
                                          //    '<S68>/Constant2'

  real_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S155>/UD'

  real_T DiscreteDerivative1_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative1_ICPrevScale
                                 //  Referenced by: '<S156>/UD'

  real_T DiscreteDerivative2_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative2_ICPrevScale
                                 //  Referenced by: '<S157>/UD'

  real_T DiscreteDerivative_ICPrevScal_i;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_i
                                 //  Referenced by: '<S132>/UD'

  real_T DiscreteDerivative1_ICPrevSca_e;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_e
                                 //  Referenced by: '<S133>/UD'

  real_T DiscreteDerivative2_ICPrevSca_o;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_o
                                 //  Referenced by: '<S134>/UD'

  real_T DiscreteDerivative_ICPrevScal_p;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_p
                                 //  Referenced by: '<S145>/UD'

  real_T DiscreteDerivative1_ICPrevSca_m;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_m
                                 //  Referenced by: '<S146>/UD'

  real_T DiscreteDerivative2_ICPrevSca_a;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_a
                                 //  Referenced by: '<S147>/UD'

  real_T DiscreteDerivative_ICPrevScal_d;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_d
                                 //  Referenced by: '<S122>/UD'

  real_T DiscreteDerivative1_ICPrevSca_i;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_i
                                 //  Referenced by: '<S123>/UD'

  real_T DiscreteDerivative2_ICPrevSc_oo;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSc_oo
                                 //  Referenced by: '<S124>/UD'

  real_T DiscreteDerivative_ICPrevSca_pf;
                              // Mask Parameter: DiscreteDerivative_ICPrevSca_pf
                                 //  Referenced by: '<S150>/UD'

  real_T DiscreteDerivative1_ICPrevSca_l;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_l
                                 //  Referenced by: '<S151>/UD'

  real_T DiscreteDerivative2_ICPrevSc_on;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSc_on
                                 //  Referenced by: '<S152>/UD'

  real_T DiscreteDerivative_ICPrevScal_n;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_n
                                 //  Referenced by: '<S127>/UD'

  real_T DiscreteDerivative1_ICPrevSca_f;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_f
                                 //  Referenced by: '<S128>/UD'

  real_T DiscreteDerivative2_ICPrevSca_g;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_g
                                 //  Referenced by: '<S129>/UD'

  real_T DiscreteDerivative1_ICPrevSca_j;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_j
                                 //  Referenced by: '<S141>/UD'

  real_T DiscreteDerivative1_ICPrevSca_a;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_a
                                 //  Referenced by: '<S142>/UD'

  real_T DiscreteDerivative1_ICPrevSca_k;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_k
                                 //  Referenced by: '<S143>/UD'

  real_T MATLABFunction5_max_iters; // Mask Parameter: MATLABFunction5_max_iters
                                       //  Referenced by: '<S228>/MATLAB Function5'

  real_T MATLABFunction5_max_iters_c;
                                  // Mask Parameter: MATLABFunction5_max_iters_c
                                     //  Referenced by: '<S240>/MATLAB Function5'

  real_T MATLABFunction5_max_iters_e;
                                  // Mask Parameter: MATLABFunction5_max_iters_e
                                     //  Referenced by: '<S252>/MATLAB Function5'

  real_T MATLABFunction5_tol;          // Mask Parameter: MATLABFunction5_tol
                                          //  Referenced by: '<S228>/MATLAB Function5'

  real_T MATLABFunction5_tol_m;        // Mask Parameter: MATLABFunction5_tol_m
                                          //  Referenced by: '<S240>/MATLAB Function5'

  real_T MATLABFunction5_tol_g;        // Mask Parameter: MATLABFunction5_tol_g
                                          //  Referenced by: '<S252>/MATLAB Function5'

  real_T Constant11_Value;             // Expression: 0
                                          //  Referenced by: '<S20>/Constant11'

  real_T Constant12_Value;             // Expression: 0
                                          //  Referenced by: '<S20>/Constant12'

  real_T Constant14_Value;             // Expression: 0
                                          //  Referenced by: '<S20>/Constant14'

  real_T Constant15_Value;             // Expression: 0
                                          //  Referenced by: '<S20>/Constant15'

  real_T Constant18_Value;             // Expression: 0
                                          //  Referenced by: '<S20>/Constant18'

  real_T Constant4_Value;              // Expression: 2
                                          //  Referenced by: '<S20>/Constant4'

  real_T Constant5_Value;              // Expression: 2
                                          //  Referenced by: '<S20>/Constant5'

  real_T Constant6_Value;              // Expression: 1
                                          //  Referenced by: '<S20>/Constant6'

  real_T Constant8_Value;              // Expression: 2
                                          //  Referenced by: '<S20>/Constant8'

  real_T Constant3_Value;              // Expression: pi/2
                                          //  Referenced by: '<S25>/Constant3'

  real_T Constant1_Value;              // Expression: pi/2
                                          //  Referenced by: '<S25>/Constant1'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S25>/Constant2'

  real_T Constant11_Value_e;           // Expression: 0
                                          //  Referenced by: '<S29>/Constant11'

  real_T Constant12_Value_g;           // Expression: 0
                                          //  Referenced by: '<S29>/Constant12'

  real_T Constant14_Value_f;           // Expression: 0
                                          //  Referenced by: '<S29>/Constant14'

  real_T Constant15_Value_o;           // Expression: 0
                                          //  Referenced by: '<S29>/Constant15'

  real_T Constant18_Value_m;           // Expression: 0
                                          //  Referenced by: '<S29>/Constant18'

  real_T Constant4_Value_g;            // Expression: 2
                                          //  Referenced by: '<S29>/Constant4'

  real_T Constant5_Value_o;            // Expression: 2
                                          //  Referenced by: '<S29>/Constant5'

  real_T Constant6_Value_i;            // Expression: 1
                                          //  Referenced by: '<S29>/Constant6'

  real_T Constant8_Value_m;            // Expression: 2
                                          //  Referenced by: '<S29>/Constant8'

  real_T Constant3_Value_b;            // Expression: pi/2
                                          //  Referenced by: '<S33>/Constant3'

  real_T Constant1_Value_o;            // Expression: pi/2
                                          //  Referenced by: '<S33>/Constant1'

  real_T Constant2_Value_f;            // Expression: 0
                                          //  Referenced by: '<S33>/Constant2'

  real_T DesiredRate_Value;            // Expression: 0.03490659
                                          //  Referenced by: '<S35>/Desired Rate '

  real_T Gain_Gain;                    // Expression: -0.85
                                          //  Referenced by: '<S37>/Gain'

  real_T Gain1_Gain;                   // Expression: -0.85
                                          //  Referenced by: '<S37>/Gain1'

  real_T SignalGenerator_Amplitude;    // Expression: 0.75
                                          //  Referenced by: '<S34>/Signal Generator'

  real_T SignalGenerator_Frequency;    // Expression: 1/60
                                          //  Referenced by: '<S34>/Signal Generator'

  real_T Constant11_Value_m;           // Expression: 0
                                          //  Referenced by: '<S30>/Constant11'

  real_T Constant12_Value_k;           // Expression: 0
                                          //  Referenced by: '<S30>/Constant12'

  real_T Constant14_Value_i;           // Expression: 0
                                          //  Referenced by: '<S30>/Constant14'

  real_T Constant15_Value_o1;          // Expression: 0
                                          //  Referenced by: '<S30>/Constant15'

  real_T Constant18_Value_n;           // Expression: 0
                                          //  Referenced by: '<S30>/Constant18'

  real_T Constant4_Value_a;            // Expression: 2
                                          //  Referenced by: '<S30>/Constant4'

  real_T Constant5_Value_m;            // Expression: 2
                                          //  Referenced by: '<S30>/Constant5'

  real_T Constant6_Value_p;            // Expression: 1
                                          //  Referenced by: '<S30>/Constant6'

  real_T Constant8_Value_o;            // Expression: 2
                                          //  Referenced by: '<S30>/Constant8'

  real_T Constant3_Value_p;            // Expression: pi/2
                                          //  Referenced by: '<S41>/Constant3'

  real_T Constant1_Value_m;            // Expression: pi/2
                                          //  Referenced by: '<S41>/Constant1'

  real_T Constant2_Value_p;            // Expression: 0
                                          //  Referenced by: '<S41>/Constant2'

  real_T DesiredRate_Value_h;          // Expression: 0.03490659
                                          //  Referenced by: '<S43>/Desired Rate '

  real_T Gain_Gain_h;                  // Expression: -0.85
                                          //  Referenced by: '<S48>/Gain'

  real_T Gain1_Gain_c;                 // Expression: -0.85
                                          //  Referenced by: '<S48>/Gain1'

  real_T DesiredRateBLACK_Value;       // Expression: 4*pi/120
                                          //  Referenced by: '<S45>/Desired Rate (BLACK)'

  real_T Constant11_Value_b;           // Expression: 0
                                          //  Referenced by: '<S31>/Constant11'

  real_T Constant12_Value_ku;          // Expression: 0
                                          //  Referenced by: '<S31>/Constant12'

  real_T Constant14_Value_n;           // Expression: 0
                                          //  Referenced by: '<S31>/Constant14'

  real_T Constant15_Value_o2;          // Expression: 0
                                          //  Referenced by: '<S31>/Constant15'

  real_T Constant18_Value_l;           // Expression: 0
                                          //  Referenced by: '<S31>/Constant18'

  real_T Constant4_Value_b;            // Expression: 2
                                          //  Referenced by: '<S31>/Constant4'

  real_T Constant5_Value_n;            // Expression: 2
                                          //  Referenced by: '<S31>/Constant5'

  real_T Constant6_Value_n;            // Expression: 1
                                          //  Referenced by: '<S31>/Constant6'

  real_T Constant8_Value_f;            // Expression: 2
                                          //  Referenced by: '<S31>/Constant8'

  real_T Constant3_Value_e;            // Expression: pi/2
                                          //  Referenced by: '<S52>/Constant3'

  real_T Constant1_Value_p;            // Expression: pi/2
                                          //  Referenced by: '<S52>/Constant1'

  real_T Constant2_Value_c;            // Expression: 0
                                          //  Referenced by: '<S52>/Constant2'

  real_T DesiredRate_Value_l;          // Expression: 0.03490659
                                          //  Referenced by: '<S53>/Desired Rate '

  real_T Gain_Gain_b;                  // Expression: -0.85
                                          //  Referenced by: '<S56>/Gain'

  real_T Gain1_Gain_k;                 // Expression: -0.85
                                          //  Referenced by: '<S56>/Gain1'

  real_T DesiredRateBLACK_Value_c;     // Expression: 4*pi/120
                                          //  Referenced by: '<S60>/Desired Rate (BLACK)'

  real_T Constant11_Value_p;           // Expression: 0
                                          //  Referenced by: '<S32>/Constant11'

  real_T Constant12_Value_n;           // Expression: 0
                                          //  Referenced by: '<S32>/Constant12'

  real_T Constant14_Value_f2;          // Expression: 0
                                          //  Referenced by: '<S32>/Constant14'

  real_T Constant15_Value_n;           // Expression: 0
                                          //  Referenced by: '<S32>/Constant15'

  real_T Constant18_Value_e;           // Expression: 0
                                          //  Referenced by: '<S32>/Constant18'

  real_T Constant4_Value_l;            // Expression: 2
                                          //  Referenced by: '<S32>/Constant4'

  real_T Constant5_Value_p;            // Expression: 2
                                          //  Referenced by: '<S32>/Constant5'

  real_T Constant6_Value_m;            // Expression: 1
                                          //  Referenced by: '<S32>/Constant6'

  real_T Constant8_Value_j;            // Expression: 2
                                          //  Referenced by: '<S32>/Constant8'

  real_T Constant3_Value_k;            // Expression: 0
                                          //  Referenced by: '<S64>/Constant3'

  real_T Constant1_Value_b;            // Expression: 0
                                          //  Referenced by: '<S64>/Constant1'

  real_T Constant2_Value_g;            // Expression: 0
                                          //  Referenced by: '<S64>/Constant2'

  real_T DesiredRate_Value_ha;         // Expression: 0.03490659
                                          //  Referenced by: '<S66>/Desired Rate '

  real_T Gain_Gain_o;                  // Expression: -0.85
                                          //  Referenced by: '<S68>/Gain'

  real_T Gain1_Gain_b;                 // Expression: -0.85
                                          //  Referenced by: '<S68>/Gain1'

  real_T Constant1_Value_n;            // Expression: 0
                                          //  Referenced by: '<S24>/Constant1'

  real_T Constant2_Value_a;            // Expression: 0
                                          //  Referenced by: '<S24>/Constant2'

  real_T Constant3_Value_d;            // Expression: 0
                                          //  Referenced by: '<S24>/Constant3'

  real_T Constant4_Value_k;            // Expression: 0
                                          //  Referenced by: '<S24>/Constant4'

  real_T Constant5_Value_ph;           // Expression: 0
                                          //  Referenced by: '<S24>/Constant5'

  real_T Constant6_Value_d;            // Expression: 0
                                          //  Referenced by: '<S24>/Constant6'

  real_T Constant7_Value;              // Expression: 0
                                          //  Referenced by: '<S24>/Constant7'

  real_T Constant8_Value_h;            // Expression: 0
                                          //  Referenced by: '<S24>/Constant8'

  real_T PuckState_Value;              // Expression: 0
                                          //  Referenced by: '<S24>/Puck State'

  real_T AngularGain_Value;            // Expression: 200
                                          //  Referenced by: '<S85>/Angular Gain'

  real_T AttractiveGain_Value;         // Expression: 200
                                          //  Referenced by: '<S85>/Attractive Gain'

  real_T InfluenceRange_Value;         // Expression: 1
                                          //  Referenced by: '<S85>/Influence Range'

  real_T RepulsiveGain_Value;          // Expression: 5
                                          //  Referenced by: '<S85>/Repulsive Gain'

  real_T AngularGain_Value_l;          // Expression: 200
                                          //  Referenced by: '<S84>/Angular Gain'

  real_T AttractiveGain_Value_i;       // Expression: 200
                                          //  Referenced by: '<S84>/Attractive Gain'

  real_T InfluenceRange_Value_d;       // Expression: 1
                                          //  Referenced by: '<S84>/Influence Range'

  real_T RepulsiveGain_Value_k;        // Expression: 5
                                          //  Referenced by: '<S84>/Repulsive Gain'

  real_T TSamp_WtEt;                   // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S155>/TSamp'

  real_T TSamp_WtEt_f;                 // Computed Parameter: TSamp_WtEt_f
                                          //  Referenced by: '<S156>/TSamp'

  real_T TSamp_WtEt_c;                 // Computed Parameter: TSamp_WtEt_c
                                          //  Referenced by: '<S157>/TSamp'

  real_T Gain6_Gain;                   // Expression: -1
                                          //  Referenced by: '<S116>/Gain6'

  real_T Gain7_Gain;                   // Expression: -1
                                          //  Referenced by: '<S116>/Gain7'

  real_T Gain8_Gain;                   // Expression: -1
                                          //  Referenced by: '<S116>/Gain8'

  real_T TSamp_WtEt_h;                 // Computed Parameter: TSamp_WtEt_h
                                          //  Referenced by: '<S132>/TSamp'

  real_T TSamp_WtEt_e;                 // Computed Parameter: TSamp_WtEt_e
                                          //  Referenced by: '<S133>/TSamp'

  real_T TSamp_WtEt_n;                 // Computed Parameter: TSamp_WtEt_n
                                          //  Referenced by: '<S134>/TSamp'

  real_T TSamp_WtEt_i;                 // Computed Parameter: TSamp_WtEt_i
                                          //  Referenced by: '<S145>/TSamp'

  real_T TSamp_WtEt_hr;                // Computed Parameter: TSamp_WtEt_hr
                                          //  Referenced by: '<S146>/TSamp'

  real_T TSamp_WtEt_ca;                // Computed Parameter: TSamp_WtEt_ca
                                          //  Referenced by: '<S147>/TSamp'

  real_T Gain6_Gain_g;                 // Expression: -1
                                          //  Referenced by: '<S114>/Gain6'

  real_T Gain7_Gain_b;                 // Expression: -1
                                          //  Referenced by: '<S114>/Gain7'

  real_T Gain8_Gain_m;                 // Expression: -1
                                          //  Referenced by: '<S114>/Gain8'

  real_T TSamp_WtEt_nd;                // Computed Parameter: TSamp_WtEt_nd
                                          //  Referenced by: '<S122>/TSamp'

  real_T TSamp_WtEt_co;                // Computed Parameter: TSamp_WtEt_co
                                          //  Referenced by: '<S123>/TSamp'

  real_T TSamp_WtEt_no;                // Computed Parameter: TSamp_WtEt_no
                                          //  Referenced by: '<S124>/TSamp'

  real_T TSamp_WtEt_p;                 // Computed Parameter: TSamp_WtEt_p
                                          //  Referenced by: '<S150>/TSamp'

  real_T TSamp_WtEt_o;                 // Computed Parameter: TSamp_WtEt_o
                                          //  Referenced by: '<S151>/TSamp'

  real_T TSamp_WtEt_px;                // Computed Parameter: TSamp_WtEt_px
                                          //  Referenced by: '<S152>/TSamp'

  real_T Gain6_Gain_a;                 // Expression: -1
                                          //  Referenced by: '<S115>/Gain6'

  real_T Gain7_Gain_e;                 // Expression: -1
                                          //  Referenced by: '<S115>/Gain7'

  real_T Gain8_Gain_g;                 // Expression: -1
                                          //  Referenced by: '<S115>/Gain8'

  real_T TSamp_WtEt_ft;                // Computed Parameter: TSamp_WtEt_ft
                                          //  Referenced by: '<S127>/TSamp'

  real_T TSamp_WtEt_eh;                // Computed Parameter: TSamp_WtEt_eh
                                          //  Referenced by: '<S128>/TSamp'

  real_T TSamp_WtEt_ii;                // Computed Parameter: TSamp_WtEt_ii
                                          //  Referenced by: '<S129>/TSamp'

  real_T TSamp_WtEt_pu;                // Computed Parameter: TSamp_WtEt_pu
                                          //  Referenced by: '<S141>/TSamp'

  real_T TSamp_WtEt_f0;                // Computed Parameter: TSamp_WtEt_f0
                                          //  Referenced by: '<S142>/TSamp'

  real_T TSamp_WtEt_nz;                // Computed Parameter: TSamp_WtEt_nz
                                          //  Referenced by: '<S143>/TSamp'

  real_T Constant7_Value_a;            // Expression: 1
                                          //  Referenced by: '<S113>/Constant7'

  real_T Merge3_InitialOutput;       // Computed Parameter: Merge3_InitialOutput
                                        //  Referenced by: '<S113>/Merge3'

  real_T Merge4_InitialOutput;       // Computed Parameter: Merge4_InitialOutput
                                        //  Referenced by: '<S113>/Merge4'

  real_T Merge5_InitialOutput;       // Computed Parameter: Merge5_InitialOutput
                                        //  Referenced by: '<S113>/Merge5'

  real_T Constant7_Value_h;            // Expression: 0
                                          //  Referenced by: '<S117>/Constant7'

  real_T Zero_Value;                   // Expression: 0
                                          //  Referenced by: '<S117>/Zero'

  real_T GPIOWrite1_gpioPin;           // Expression: 428
                                          //  Referenced by: '<S167>/GPIO Write1'

  real_T GPIOWrite1_pinDirection;      // Expression: 1
                                          //  Referenced by: '<S167>/GPIO Write1'

  real_T GyroscopeAccelerometer_SampleTi;// Expression: -1
                                            //  Referenced by: '<S168>/Gyroscope//Accelerometer'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S170>/Delay'

  real_T Delay1_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S170>/Delay1'

  real_T Delay2_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S170>/Delay2'

  real_T Out1_Y0;                      // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S179>/Out1'

  real_T Memory_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S179>/Memory'

  real_T Out1_Y0_i;                    // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S180>/Out1'

  real_T dytdt_Y0;                     // Computed Parameter: dytdt_Y0
                                          //  Referenced by: '<S186>/dy(t)//dt'

  real_T dytdt_Y0_j;                   // Computed Parameter: dytdt_Y0_j
                                          //  Referenced by: '<S196>/dy(t)//dt'

  real_T dytdt_Y0_d;                   // Computed Parameter: dytdt_Y0_d
                                          //  Referenced by: '<S206>/dy(t)//dt'

  real_T ConvertBLAXfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S174>/Convert BLAX from [mm] to [m]'

  real_T ConvertBLAYfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S174>/Convert BLAY from [mm] to [m]'

  real_T ConvertBLACKVXfrommmtom_Gain; // Expression: 1/1000
                                          //  Referenced by: '<S174>/Convert BLACKVX from [mm] to [m]'

  real_T ConvertBLACKVYfrommmtom_Gain; // Expression: 1/1000
                                          //  Referenced by: '<S174>/Convert BLACKVY from [mm] to [m]'

  real_T Delay2_InitialCondition_e;    // Expression: 0
                                          //  Referenced by: '<S182>/Delay2'

  real_T Delay1_InitialCondition_m;    // Expression: 0
                                          //  Referenced by: '<S182>/Delay1'

  real_T Constant3_Value_eq;           // Expression: 0
                                          //  Referenced by: '<S182>/Constant3'

  real_T Delay1_InitialCondition_i;    // Expression: 0.0
                                          //  Referenced by: '<S184>/Delay1'

  real_T Constant3_Value_a;            // Expression: 0
                                          //  Referenced by: '<S184>/Constant3'

  real_T Delay1_InitialCondition_it;   // Expression: 0.0
                                          //  Referenced by: '<S183>/Delay1'

  real_T Constant3_Value_d4;           // Expression: 0
                                          //  Referenced by: '<S183>/Constant3'

  real_T ConvertBLUXfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S175>/Convert BLUX from [mm] to [m]'

  real_T ConvertBLUYfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S175>/Convert BLUY from [mm] to [m]'

  real_T ConvertBLUEVXfrommmtom_Gain;  // Expression: 1/1000
                                          //  Referenced by: '<S175>/Convert BLUEVX from [mm] to [m]'

  real_T ConvertBLUEVYfrommmtom_Gain;  // Expression: 1/1000
                                          //  Referenced by: '<S175>/Convert BLUEVY from [mm] to [m]'

  real_T Delay2_InitialCondition_a;    // Expression: 0
                                          //  Referenced by: '<S192>/Delay2'

  real_T Delay1_InitialCondition_i3;   // Expression: 0
                                          //  Referenced by: '<S192>/Delay1'

  real_T Constant3_Value_o;            // Expression: 0
                                          //  Referenced by: '<S192>/Constant3'

  real_T Delay1_InitialCondition_h;    // Expression: 0.0
                                          //  Referenced by: '<S194>/Delay1'

  real_T Constant3_Value_c;            // Expression: 0
                                          //  Referenced by: '<S194>/Constant3'

  real_T Delay1_InitialCondition_j;    // Expression: 0.0
                                          //  Referenced by: '<S193>/Delay1'

  real_T Constant3_Value_ke;           // Expression: 0
                                          //  Referenced by: '<S193>/Constant3'

  real_T ConvertREDXfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S176>/Convert REDX from [mm] to [m]'

  real_T ConvertREDYfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S176>/Convert REDY from [mm] to [m]'

  real_T ConvertREDVXfrommmtom_Gain;   // Expression: 1/1000
                                          //  Referenced by: '<S176>/Convert REDVX from [mm] to [m]'

  real_T ConvertREDVYfrommmtom_Gain;   // Expression: 1/1000
                                          //  Referenced by: '<S176>/Convert REDVY from [mm] to [m]'

  real_T Delay2_InitialCondition_m;    // Expression: 0
                                          //  Referenced by: '<S202>/Delay2'

  real_T Delay1_InitialCondition_l;    // Expression: 0
                                          //  Referenced by: '<S202>/Delay1'

  real_T Constant3_Value_f;            // Expression: 0
                                          //  Referenced by: '<S202>/Constant3'

  real_T Delay1_InitialCondition_k;    // Expression: 0.0
                                          //  Referenced by: '<S204>/Delay1'

  real_T Constant3_Value_dh;           // Expression: 0
                                          //  Referenced by: '<S204>/Constant3'

  real_T Delay1_InitialCondition_c;    // Expression: 0.0
                                          //  Referenced by: '<S203>/Delay1'

  real_T Constant3_Value_dz;           // Expression: 0
                                          //  Referenced by: '<S203>/Constant3'

  real_T Constant_Value;               // Expression: 1
                                          //  Referenced by: '<S177>/Constant'

  real_T ControlDynamixelActuatorsineith;// Expression: 400
                                            //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_b;// Expression: 0
                                            //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_h;// Expression: 200
                                            //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_j;// Expression: 3072
                                            //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_m;// Expression: 1024
                                            //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsine_hy;// Expression: 0
                                            //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_i;// Expression: 850
                                            //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_g;// Expression: 400
                                            //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsine_g3;// Expression: 100
                                            //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsine_bf;// Expression: 50
                                            //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_l;// Expression: 0
                                            //  Referenced by: '<S215>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T Out1_Y0_f;                    // Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S235>/Out1'

  real_T Out1_Y0_j;                    // Computed Parameter: Out1_Y0_j
                                          //  Referenced by: '<S236>/Out1'

  real_T BLACKDC_Y0;                   // Computed Parameter: BLACKDC_Y0
                                          //  Referenced by: '<S225>/BLACK DC'

  real_T Delay_InitialCondition_i;     // Expression: 0.0
                                          //  Referenced by: '<S230>/Delay'

  real_T Constant2_Value_h;            // Expression: 0
                                          //  Referenced by: '<S230>/Constant2'

  real_T Out1_Y0_n;                    // Computed Parameter: Out1_Y0_n
                                          //  Referenced by: '<S247>/Out1'

  real_T Out1_Y0_js;                   // Computed Parameter: Out1_Y0_js
                                          //  Referenced by: '<S248>/Out1'

  real_T BLUEDC_Y0;                    // Computed Parameter: BLUEDC_Y0
                                          //  Referenced by: '<S226>/BLUE DC'

  real_T Delay_InitialCondition_n;     // Expression: 0.0
                                          //  Referenced by: '<S242>/Delay'

  real_T Constant2_Value_fq;           // Expression: 0
                                          //  Referenced by: '<S242>/Constant2'

  real_T Out1_Y0_c;                    // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S259>/Out1'

  real_T Out1_Y0_d;                    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S260>/Out1'

  real_T REDDC_Y0;                     // Computed Parameter: REDDC_Y0
                                          //  Referenced by: '<S227>/RED DC'

  real_T Delay_InitialCondition_p;     // Expression: 0.0
                                          //  Referenced by: '<S254>/Delay'

  real_T Constant2_Value_e;            // Expression: 0
                                          //  Referenced by: '<S254>/Constant2'

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

  real_T Merge1_InitialOutput;       // Computed Parameter: Merge1_InitialOutput
                                        //  Referenced by: '<S3>/Merge1'

  real_T Merge2_InitialOutput;       // Computed Parameter: Merge2_InitialOutput
                                        //  Referenced by: '<S3>/Merge2'

  real_T Merge_InitialOutput;         // Computed Parameter: Merge_InitialOutput
                                         //  Referenced by: '<S3>/Merge'

  real_T Delay1_InitialCondition_o;    // Expression: 0.0
                                          //  Referenced by: '<S217>/Delay1'

  real_T Delay_InitialCondition_h;     // Expression: 0.0
                                          //  Referenced by: '<S217>/Delay'

  real_T Delay2_InitialCondition_h[13];// Expression: [1; zeros(12,1)]
                                          //  Referenced by: '<S218>/Delay2'

  real_T Delay1_InitialCondition_jf[144];// Expression: 0.2*eye(12)
                                            //  Referenced by: '<S218>/Delay1'

  real_T Delay3_InitialCondition[36];  // Expression: 0*eye(6)
                                          //  Referenced by: '<S218>/Delay3'

  real_T SafetyNumber_Value;           // Expression: 568471
                                          //  Referenced by: '<S17>/Safety Number'

  real_T Gain_Gain_oy;                 // Expression: 100
                                          //  Referenced by: '<S17>/Gain'

  real_T Gain1_Gain_e;                 // Expression: 100
                                          //  Referenced by: '<S17>/Gain1'

  real_T Gain2_Gain;                   // Expression: 100
                                          //  Referenced by: '<S17>/Gain2'

  real_T Gain3_Gain;                   // Expression: 100
                                          //  Referenced by: '<S17>/Gain3'

  real_T Gain4_Gain;                   // Expression: 100
                                          //  Referenced by: '<S17>/Gain4'

  real_T Gain5_Gain;                   // Expression: 100
                                          //  Referenced by: '<S17>/Gain5'

  real_T Gain6_Gain_c;                 // Expression: 100
                                          //  Referenced by: '<S17>/Gain6'

  real_T Gain7_Gain_l;                 // Expression: 100
                                          //  Referenced by: '<S17>/Gain7'

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

  real_T Universal_Time21_InitialValue[7];// Expression: [1;0;0;0;0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time21'

  real_T Universal_Time22_InitialValue[7];// Expression: [1;0;0;0;0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time22'

  real_T Universal_Time23_InitialValue;// Expression: [0]
                                          //  Referenced by: '<Root>/Universal_Time23'

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

  real_T Universal_Time36_InitialValue[13];
                                      // Expression: [1;0;0;0;0;0;0;0;0;0;0;0;0]
                                         //  Referenced by: '<Root>/Universal_Time36'

  real_T Universal_Time37_InitialValue;// Expression: [0]
                                          //  Referenced by: '<Root>/Universal_Time37'

  real_T Universal_Time38_InitialValue;// Expression: [0]
                                          //  Referenced by: '<Root>/Universal_Time38'

  real_T Universal_Time4_InitialValue[9];// Expression: [0;0;0;0;0;0;0;0;0]
                                            //  Referenced by: '<Root>/Universal_Time4'

  real_T Universal_Time5_InitialValue[3];// Expression: [0;0;0]
                                            //  Referenced by: '<Root>/Universal_Time5'

  real_T Universal_Time6_InitialValue[3];// Expression: [0;0;0]
                                            //  Referenced by: '<Root>/Universal_Time6'

  real_T Universal_Time8_InitialValue[3];// Expression: [0;0;0]
                                            //  Referenced by: '<Root>/Universal_Time8'

  real_T Universal_Time9_InitialValue[7];// Expression: [1;0;0;0;0;0;0]
                                            //  Referenced by: '<Root>/Universal_Time9'

  char_T StringConstant1_String[256];  // Expression: "Target: Hello"
                                          //  Referenced by: '<S164>/String Constant1'

  char_T StringConstant2_String[256];  // Expression: "Obstacle: Hello"
                                          //  Referenced by: '<S165>/String Constant2'

  char_T RED_Tz3_InitialValue[256];  // Computed Parameter: RED_Tz3_InitialValue
                                        //  Referenced by: '<Root>/RED_Tz3'

  int32_T UDPSend1_Port;               // Computed Parameter: UDPSend1_Port
                                          //  Referenced by: '<S164>/UDP Send1'

  int32_T UDPSend2_Port;               // Computed Parameter: UDPSend2_Port
                                          //  Referenced by: '<S165>/UDP Send2'

  int32_T UDPSend3_Port;               // Computed Parameter: UDPSend3_Port
                                          //  Referenced by: '<S166>/UDP Send3'

  int32_T ReceivePhaseSpaceData_Port;
                               // Computed Parameter: ReceivePhaseSpaceData_Port
                                  //  Referenced by: '<S173>/Receive PhaseSpace Data'

  int32_T Delay_InitialCondition_j;
                                 // Computed Parameter: Delay_InitialCondition_j
                                    //  Referenced by: '<S178>/Delay'

  int32_T Delay1_InitialCondition_d;
                                // Computed Parameter: Delay1_InitialCondition_d
                                   //  Referenced by: '<S178>/Delay1'

  int32_T Delay2_InitialCondition_ak;
                               // Computed Parameter: Delay2_InitialCondition_ak
                                  //  Referenced by: '<S178>/Delay2'

  int32_T UDPReceive_Port;             // Computed Parameter: UDPReceive_Port
                                          //  Referenced by: '<S178>/UDP Receive'

  int32_T UDPReceive2_Port;            // Computed Parameter: UDPReceive2_Port
                                          //  Referenced by: '<S178>/UDP Receive2'

  int32_T UDPReceive3_Port;            // Computed Parameter: UDPReceive3_Port
                                          //  Referenced by: '<S178>/UDP Receive3'

  int32_T UDPReceive1_Port;            // Computed Parameter: UDPReceive1_Port
                                          //  Referenced by: '<S213>/UDP Receive1'

  int32_T UDPSend_Port;                // Computed Parameter: UDPSend_Port
                                          //  Referenced by: '<S224>/UDP Send'

  int32_T UDPSend_Port_h;              // Computed Parameter: UDPSend_Port_h
                                          //  Referenced by: '<S17>/UDP Send'

  P_EnabledSubsystem_STQMEKF_d_T EnabledSubsystem_a;// '<S204>/Enabled Subsystem' 
  P_EnabledSubsystem_STQMEKF_T EnabledSubsystem_k;// '<S203>/Enabled Subsystem'
  P_EnabledSubsystem_STQMEKF_d_T EnabledSubsystem_g;// '<S194>/Enabled Subsystem' 
  P_EnabledSubsystem_STQMEKF_T EnabledSubsystem_l;// '<S193>/Enabled Subsystem'
  P_EnabledSubsystem_STQMEKF_d_T EnabledSubsystem_n;// '<S184>/Enabled Subsystem' 
  P_EnabledSubsystem_STQMEKF_T EnabledSubsystem_m;// '<S183>/Enabled Subsystem'
  P_ChangeBLACKBehavior_STQMEKF_T ChangeREDBehavior;// '<S4>/Change RED Behavior' 
  P_ChangeBLACKBehavior_STQMEKF_T ChangeBLUEBehavior;// '<S4>/Change BLUE Behavior' 
  P_ChangeBLACKBehavior_STQMEKF_T ChangeBLACKBehavior;// '<S4>/Change BLACK Behavior' 
  P_CustomControlRED_STQMEKF_T CustomControlARM;// '<S3>/Custom Control (ARM)'
  P_DisableThrustersBLACK_STQME_T DisableThrustersBLUE;// '<S3>/Disable Thrusters (BLUE)' 
  P_DisableThrustersBLACK_STQME_T DisableThrustersBLACK;// '<S3>/Disable Thrusters (BLACK)' 
  P_CustomControlRED_STQMEKF_T DisableThrustersRED;// '<S3>/Disable Thrusters (RED)' 
  P_CustomControlRED_STQMEKF_T CustomControlRED;// '<S3>/Custom Control (RED)'
  P_Phase4ReturnHome_STQMEKF_T Phase5HoldHome;// '<S1>/Phase #5: Hold Home'
  P_Phase4ReturnHome_STQMEKF_T Phase4ReturnHome;// '<S1>/Phase #4: Return Home'
  P_Phase0Synchronization_STQME_T Phase1StartFloating;// '<S1>/Phase #1: Start Floating ' 
  P_Phase0Synchronization_STQME_T Phase0Synchronization;// '<S1>/Phase #0: Synchronization' 
};

// Real-time Model Data Structure
struct tag_RTM_STQMEKF_T {
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

  extern P_STQMEKF_T STQMEKF_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_STQMEKF_T STQMEKF_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_STQMEKF_T STQMEKF_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void STQMEKF_initialize(void);
  extern void STQMEKF_step(void);
  extern void STQMEKF_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_STQMEKF_T *const STQMEKF_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S122>/Data Type Duplicate' : Unused code path elimination
//  Block '<S123>/Data Type Duplicate' : Unused code path elimination
//  Block '<S124>/Data Type Duplicate' : Unused code path elimination
//  Block '<S127>/Data Type Duplicate' : Unused code path elimination
//  Block '<S128>/Data Type Duplicate' : Unused code path elimination
//  Block '<S129>/Data Type Duplicate' : Unused code path elimination
//  Block '<S132>/Data Type Duplicate' : Unused code path elimination
//  Block '<S133>/Data Type Duplicate' : Unused code path elimination
//  Block '<S134>/Data Type Duplicate' : Unused code path elimination
//  Block '<S113>/Scope' : Unused code path elimination
//  Block '<S141>/Data Type Duplicate' : Unused code path elimination
//  Block '<S142>/Data Type Duplicate' : Unused code path elimination
//  Block '<S143>/Data Type Duplicate' : Unused code path elimination
//  Block '<S145>/Data Type Duplicate' : Unused code path elimination
//  Block '<S146>/Data Type Duplicate' : Unused code path elimination
//  Block '<S147>/Data Type Duplicate' : Unused code path elimination
//  Block '<S150>/Data Type Duplicate' : Unused code path elimination
//  Block '<S151>/Data Type Duplicate' : Unused code path elimination
//  Block '<S152>/Data Type Duplicate' : Unused code path elimination
//  Block '<S155>/Data Type Duplicate' : Unused code path elimination
//  Block '<S156>/Data Type Duplicate' : Unused code path elimination
//  Block '<S157>/Data Type Duplicate' : Unused code path elimination
//  Block '<Root>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' : Unused code path elimination
//  Block '<S216>/Reshape2' : Unused code path elimination
//  Block '<S97>/Reshape' : Reshape block reduction
//  Block '<S98>/Reshape1' : Reshape block reduction
//  Block '<S84>/Reshape' : Reshape block reduction
//  Block '<S84>/Reshape1' : Reshape block reduction
//  Block '<S102>/Reshape1' : Reshape block reduction
//  Block '<S103>/Reshape' : Reshape block reduction
//  Block '<S85>/Reshape' : Reshape block reduction
//  Block '<S85>/Reshape1' : Reshape block reduction
//  Block '<S164>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S165>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S166>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S173>/Reshape' : Reshape block reduction
//  Block '<S174>/Reshape' : Reshape block reduction
//  Block '<S175>/Reshape' : Reshape block reduction
//  Block '<S176>/Reshape' : Reshape block reduction
//  Block '<S216>/Reshape' : Reshape block reduction
//  Block '<S216>/Reshape1' : Reshape block reduction


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
//  '<Root>' : 'STQMEKF'
//  '<S1>'   : 'STQMEKF/1 - Experiment Logic'
//  '<S2>'   : 'STQMEKF/2 - Guidance'
//  '<S3>'   : 'STQMEKF/3 - Control'
//  '<S4>'   : 'STQMEKF/Check  Connection'
//  '<S5>'   : 'STQMEKF/Data Logger Subsystem'
//  '<S6>'   : 'STQMEKF/Debugger'
//  '<S7>'   : 'STQMEKF/Float Code'
//  '<S8>'   : 'STQMEKF/Gyro.//Accel. Code'
//  '<S9>'   : 'STQMEKF/Manipulator Encoder Data'
//  '<S10>'  : 'STQMEKF/PhaseSpace Camera Code'
//  '<S11>'  : 'STQMEKF/Platform  Identification'
//  '<S12>'  : 'STQMEKF/Receive Data '
//  '<S13>'  : 'STQMEKF/Robotic  Arm Code'
//  '<S14>'  : 'STQMEKF/STQMEKF'
//  '<S15>'  : 'STQMEKF/Send Data  to Orin'
//  '<S16>'  : 'STQMEKF/Simulation  Status'
//  '<S17>'  : 'STQMEKF/Thruster Control Code'
//  '<S18>'  : 'STQMEKF/1 - Experiment Logic/Phase #0: Synchronization'
//  '<S19>'  : 'STQMEKF/1 - Experiment Logic/Phase #1: Start Floating '
//  '<S20>'  : 'STQMEKF/1 - Experiment Logic/Phase #2: Initial Position'
//  '<S21>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment'
//  '<S22>'  : 'STQMEKF/1 - Experiment Logic/Phase #4: Return Home'
//  '<S23>'  : 'STQMEKF/1 - Experiment Logic/Phase #5: Hold Home'
//  '<S24>'  : 'STQMEKF/1 - Experiment Logic/Phase #6: Clean Shutdown'
//  '<S25>'  : 'STQMEKF/1 - Experiment Logic/Phase #2: Initial Position/Desired Joint Angles RED'
//  '<S26>'  : 'STQMEKF/1 - Experiment Logic/Phase #2: Initial Position/Desired Position BLACK'
//  '<S27>'  : 'STQMEKF/1 - Experiment Logic/Phase #2: Initial Position/Desired Position BLUE'
//  '<S28>'  : 'STQMEKF/1 - Experiment Logic/Phase #2: Initial Position/Desired Position RED'
//  '<S29>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1'
//  '<S30>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 '
//  '<S31>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 '
//  '<S32>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4'
//  '<S33>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Joint Angles RED'
//  '<S34>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLACK'
//  '<S35>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLUE'
//  '<S36>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position RED'
//  '<S37>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLUE/Calculate Circular Tracking'
//  '<S38>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLUE/Calculate Time since Phase #3 Start'
//  '<S39>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLUE/Wrap'
//  '<S40>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLUE/Calculate Time since Phase #3 Start/Subsystem'
//  '<S41>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Joint Angles RED'
//  '<S42>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLACK'
//  '<S43>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLUE'
//  '<S44>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position RED'
//  '<S45>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLACK/BLACK_Rz Desired'
//  '<S46>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLACK/Wrap'
//  '<S47>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLACK/BLACK_Rz Desired/Subsystem'
//  '<S48>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLUE/Calculate Circular Tracking'
//  '<S49>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLUE/Calculate Time since Phase #3 Start'
//  '<S50>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLUE/Wrap'
//  '<S51>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLUE/Calculate Time since Phase #3 Start/Subsystem'
//  '<S52>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Joint Angles RED'
//  '<S53>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position BLUE'
//  '<S54>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position RED1'
//  '<S55>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position RED2'
//  '<S56>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position BLUE/Calculate Circular Tracking'
//  '<S57>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position BLUE/Calculate Time since Phase #3 Start'
//  '<S58>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position BLUE/Wrap'
//  '<S59>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position BLUE/Calculate Time since Phase #3 Start/Subsystem'
//  '<S60>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position RED2/BLACK_Rz Desired'
//  '<S61>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position RED2/MATLAB Function'
//  '<S62>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position RED2/Wrap'
//  '<S63>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position RED2/BLACK_Rz Desired/Subsystem'
//  '<S64>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Joint Angles RED'
//  '<S65>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position BLACK1'
//  '<S66>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position BLUE'
//  '<S67>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position RED1'
//  '<S68>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position BLUE/Calculate Circular Tracking'
//  '<S69>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position BLUE/Calculate Time since Phase #3 Start'
//  '<S70>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position BLUE/Wrap'
//  '<S71>'  : 'STQMEKF/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position BLUE/Calculate Time since Phase #3 Start/Subsystem'
//  '<S72>'  : 'STQMEKF/1 - Experiment Logic/Phase #4: Return Home/Desired Joint Angles RED'
//  '<S73>'  : 'STQMEKF/1 - Experiment Logic/Phase #4: Return Home/Desired Position BLACK'
//  '<S74>'  : 'STQMEKF/1 - Experiment Logic/Phase #4: Return Home/Desired Position BLUE'
//  '<S75>'  : 'STQMEKF/1 - Experiment Logic/Phase #4: Return Home/Desired Position RED'
//  '<S76>'  : 'STQMEKF/1 - Experiment Logic/Phase #5: Hold Home/Desired Joint Angles RED'
//  '<S77>'  : 'STQMEKF/1 - Experiment Logic/Phase #5: Hold Home/Desired Position BLACK'
//  '<S78>'  : 'STQMEKF/1 - Experiment Logic/Phase #5: Hold Home/Desired Position BLUE'
//  '<S79>'  : 'STQMEKF/1 - Experiment Logic/Phase #5: Hold Home/Desired Position RED'
//  '<S80>'  : 'STQMEKF/2 - Guidance/Custom PPL (ARM)'
//  '<S81>'  : 'STQMEKF/2 - Guidance/Custom PPL (BLACK)'
//  '<S82>'  : 'STQMEKF/2 - Guidance/Custom PPL (BLUE)'
//  '<S83>'  : 'STQMEKF/2 - Guidance/Custom PPL (RED)'
//  '<S84>'  : 'STQMEKF/2 - Guidance/Default APF PPL (BLACK)'
//  '<S85>'  : 'STQMEKF/2 - Guidance/Default APF PPL (RED)'
//  '<S86>'  : 'STQMEKF/2 - Guidance/Disable PPL (ARM)'
//  '<S87>'  : 'STQMEKF/2 - Guidance/Disable PPL (BLACK)'
//  '<S88>'  : 'STQMEKF/2 - Guidance/Disable PPL (BLUE)'
//  '<S89>'  : 'STQMEKF/2 - Guidance/Disable PPL (RED)'
//  '<S90>'  : 'STQMEKF/2 - Guidance/Custom PPL (ARM)/Desired Position'
//  '<S91>'  : 'STQMEKF/2 - Guidance/Custom PPL (BLACK)/Desired Position'
//  '<S92>'  : 'STQMEKF/2 - Guidance/Custom PPL (BLUE)/Desired Position'
//  '<S93>'  : 'STQMEKF/2 - Guidance/Custom PPL (RED)/Desired Position'
//  '<S94>'  : 'STQMEKF/2 - Guidance/Default APF PPL (BLACK)/Current Position RED'
//  '<S95>'  : 'STQMEKF/2 - Guidance/Default APF PPL (BLACK)/MATLAB Function'
//  '<S96>'  : 'STQMEKF/2 - Guidance/Default APF PPL (BLACK)/Obstacles'
//  '<S97>'  : 'STQMEKF/2 - Guidance/Default APF PPL (BLACK)/Obstacles/Current Position BLUE'
//  '<S98>'  : 'STQMEKF/2 - Guidance/Default APF PPL (BLACK)/Obstacles/Current Position RED'
//  '<S99>'  : 'STQMEKF/2 - Guidance/Default APF PPL (RED)/Current Position RED'
//  '<S100>' : 'STQMEKF/2 - Guidance/Default APF PPL (RED)/MATLAB Function'
//  '<S101>' : 'STQMEKF/2 - Guidance/Default APF PPL (RED)/Obstacles'
//  '<S102>' : 'STQMEKF/2 - Guidance/Default APF PPL (RED)/Obstacles/Current Position BLACK'
//  '<S103>' : 'STQMEKF/2 - Guidance/Default APF PPL (RED)/Obstacles/Current Position BLUE'
//  '<S104>' : 'STQMEKF/2 - Guidance/Disable PPL (ARM)/Desired Position'
//  '<S105>' : 'STQMEKF/2 - Guidance/Disable PPL (BLACK)/Desired Position'
//  '<S106>' : 'STQMEKF/2 - Guidance/Disable PPL (BLUE)/Desired Position'
//  '<S107>' : 'STQMEKF/2 - Guidance/Disable PPL (RED)/Desired Position'
//  '<S108>' : 'STQMEKF/3 - Control/Custom Control (ARM)'
//  '<S109>' : 'STQMEKF/3 - Control/Custom Control (RED)'
//  '<S110>' : 'STQMEKF/3 - Control/Default LQR Control (BLACK)'
//  '<S111>' : 'STQMEKF/3 - Control/Default LQR Control (BLUE)'
//  '<S112>' : 'STQMEKF/3 - Control/Default LQR Control (RED)'
//  '<S113>' : 'STQMEKF/3 - Control/Default PD (ARM)'
//  '<S114>' : 'STQMEKF/3 - Control/Default PD Control (BLACK)'
//  '<S115>' : 'STQMEKF/3 - Control/Default PD Control (BLUE)'
//  '<S116>' : 'STQMEKF/3 - Control/Default PD Control (RED)'
//  '<S117>' : 'STQMEKF/3 - Control/Disable Control (ARM)'
//  '<S118>' : 'STQMEKF/3 - Control/Disable Thrusters (BLACK)'
//  '<S119>' : 'STQMEKF/3 - Control/Disable Thrusters (BLUE)'
//  '<S120>' : 'STQMEKF/3 - Control/Disable Thrusters (RED)'
//  '<S121>' : 'STQMEKF/3 - Control/Default LQR Control (BLACK)/Calculate Error'
//  '<S122>' : 'STQMEKF/3 - Control/Default LQR Control (BLACK)/Discrete Derivative'
//  '<S123>' : 'STQMEKF/3 - Control/Default LQR Control (BLACK)/Discrete Derivative1'
//  '<S124>' : 'STQMEKF/3 - Control/Default LQR Control (BLACK)/Discrete Derivative2'
//  '<S125>' : 'STQMEKF/3 - Control/Default LQR Control (BLACK)/Calculate Error/MATLAB Function'
//  '<S126>' : 'STQMEKF/3 - Control/Default LQR Control (BLUE)/Calculate Error'
//  '<S127>' : 'STQMEKF/3 - Control/Default LQR Control (BLUE)/Discrete Derivative'
//  '<S128>' : 'STQMEKF/3 - Control/Default LQR Control (BLUE)/Discrete Derivative1'
//  '<S129>' : 'STQMEKF/3 - Control/Default LQR Control (BLUE)/Discrete Derivative2'
//  '<S130>' : 'STQMEKF/3 - Control/Default LQR Control (BLUE)/Calculate Error/MATLAB Function'
//  '<S131>' : 'STQMEKF/3 - Control/Default LQR Control (RED)/Calculate Error'
//  '<S132>' : 'STQMEKF/3 - Control/Default LQR Control (RED)/Discrete Derivative'
//  '<S133>' : 'STQMEKF/3 - Control/Default LQR Control (RED)/Discrete Derivative1'
//  '<S134>' : 'STQMEKF/3 - Control/Default LQR Control (RED)/Discrete Derivative2'
//  '<S135>' : 'STQMEKF/3 - Control/Default LQR Control (RED)/Calculate Error/MATLAB Function'
//  '<S136>' : 'STQMEKF/3 - Control/Default PD (ARM)/Passthrough for Experiment'
//  '<S137>' : 'STQMEKF/3 - Control/Default PD (ARM)/Simulated Position Controller'
//  '<S138>' : 'STQMEKF/3 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Elbow)'
//  '<S139>' : 'STQMEKF/3 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Shoulder)'
//  '<S140>' : 'STQMEKF/3 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Wrist)'
//  '<S141>' : 'STQMEKF/3 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Elbow)/Discrete Derivative1'
//  '<S142>' : 'STQMEKF/3 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Shoulder)/Discrete Derivative1'
//  '<S143>' : 'STQMEKF/3 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Wrist)/Discrete Derivative1'
//  '<S144>' : 'STQMEKF/3 - Control/Default PD Control (BLACK)/Calculate Error'
//  '<S145>' : 'STQMEKF/3 - Control/Default PD Control (BLACK)/Discrete Derivative'
//  '<S146>' : 'STQMEKF/3 - Control/Default PD Control (BLACK)/Discrete Derivative1'
//  '<S147>' : 'STQMEKF/3 - Control/Default PD Control (BLACK)/Discrete Derivative2'
//  '<S148>' : 'STQMEKF/3 - Control/Default PD Control (BLACK)/Calculate Error/MATLAB Function'
//  '<S149>' : 'STQMEKF/3 - Control/Default PD Control (BLUE)/Calculate Error'
//  '<S150>' : 'STQMEKF/3 - Control/Default PD Control (BLUE)/Discrete Derivative'
//  '<S151>' : 'STQMEKF/3 - Control/Default PD Control (BLUE)/Discrete Derivative1'
//  '<S152>' : 'STQMEKF/3 - Control/Default PD Control (BLUE)/Discrete Derivative2'
//  '<S153>' : 'STQMEKF/3 - Control/Default PD Control (BLUE)/Calculate Error/MATLAB Function'
//  '<S154>' : 'STQMEKF/3 - Control/Default PD Control (RED)/Calculate Error'
//  '<S155>' : 'STQMEKF/3 - Control/Default PD Control (RED)/Discrete Derivative'
//  '<S156>' : 'STQMEKF/3 - Control/Default PD Control (RED)/Discrete Derivative1'
//  '<S157>' : 'STQMEKF/3 - Control/Default PD Control (RED)/Discrete Derivative2'
//  '<S158>' : 'STQMEKF/3 - Control/Default PD Control (RED)/Calculate Error/MATLAB Function'
//  '<S159>' : 'STQMEKF/Check  Connection/Change BLACK Behavior'
//  '<S160>' : 'STQMEKF/Check  Connection/Change BLUE Behavior'
//  '<S161>' : 'STQMEKF/Check  Connection/Change RED Behavior'
//  '<S162>' : 'STQMEKF/Data Logger Subsystem/Data Logger'
//  '<S163>' : 'STQMEKF/Data Logger Subsystem/Data Logger/MATLAB Function'
//  '<S164>' : 'STQMEKF/Debugger/Change BLACK Behavior'
//  '<S165>' : 'STQMEKF/Debugger/Change BLUE Behavior'
//  '<S166>' : 'STQMEKF/Debugger/Change RED Behavior'
//  '<S167>' : 'STQMEKF/Float Code/Enable Pucks'
//  '<S168>' : 'STQMEKF/Gyro.//Accel. Code/Log Gyro//Accel'
//  '<S169>' : 'STQMEKF/Gyro.//Accel. Code/Log Gyro//Accel/Parse IMU Data'
//  '<S170>' : 'STQMEKF/Manipulator Encoder Data/Change ARM Behavior'
//  '<S171>' : 'STQMEKF/PhaseSpace Camera Code/Initialize Universal Time (Simulation)'
//  '<S172>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States'
//  '<S173>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data'
//  '<S174>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data'
//  '<S175>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data'
//  '<S176>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data'
//  '<S177>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data/Adjust Time '
//  '<S178>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data/Check for Sychronization'
//  '<S179>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data/Adjust Time /Enabled Subsystem'
//  '<S180>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data/Adjust Time /Enabled Subsystem1'
//  '<S181>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data/Check for Sychronization/MATLAB Function'
//  '<S182>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Calculate True  Time Step'
//  '<S183>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem1'
//  '<S184>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem2'
//  '<S185>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Wrap'
//  '<S186>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Calculate True  Time Step/Enabled Subsystem3'
//  '<S187>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Calculate True  Time Step/MATLAB Function'
//  '<S188>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem1/Enabled Subsystem'
//  '<S189>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem1/Enabled Subsystem/MATLAB Function'
//  '<S190>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem2/Enabled Subsystem'
//  '<S191>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem2/Enabled Subsystem/MATLAB Function'
//  '<S192>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Calculate True  Time Step'
//  '<S193>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem1'
//  '<S194>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem2'
//  '<S195>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Wrap'
//  '<S196>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Calculate True  Time Step/Enabled Subsystem3'
//  '<S197>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Calculate True  Time Step/MATLAB Function'
//  '<S198>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem1/Enabled Subsystem'
//  '<S199>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem1/Enabled Subsystem/MATLAB Function'
//  '<S200>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem2/Enabled Subsystem'
//  '<S201>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem2/Enabled Subsystem/MATLAB Function'
//  '<S202>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Calculate True  Time Step'
//  '<S203>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem1'
//  '<S204>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem2'
//  '<S205>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Wrap'
//  '<S206>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Calculate True  Time Step/Enabled Subsystem3'
//  '<S207>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Calculate True  Time Step/MATLAB Function'
//  '<S208>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem1/Enabled Subsystem'
//  '<S209>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem1/Enabled Subsystem/MATLAB Function'
//  '<S210>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem2/Enabled Subsystem'
//  '<S211>' : 'STQMEKF/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem2/Enabled Subsystem/MATLAB Function'
//  '<S212>' : 'STQMEKF/Platform  Identification/Subsystem'
//  '<S213>' : 'STQMEKF/Receive Data /Subsystem'
//  '<S214>' : 'STQMEKF/Receive Data /Subsystem/Build quat'
//  '<S215>' : 'STQMEKF/Robotic  Arm Code/Change ARM Behavior'
//  '<S216>' : 'STQMEKF/STQMEKF/Data Store'
//  '<S217>' : 'STQMEKF/STQMEKF/Input Handling'
//  '<S218>' : 'STQMEKF/STQMEKF/ST-Q-MEKF'
//  '<S219>' : 'STQMEKF/STQMEKF/Data Store/Nis'
//  '<S220>' : 'STQMEKF/STQMEKF/Input Handling/Build quat '
//  '<S221>' : 'STQMEKF/STQMEKF/Input Handling/Pre-Process'
//  '<S222>' : 'STQMEKF/STQMEKF/Input Handling/Rel 2 Global'
//  '<S223>' : 'STQMEKF/STQMEKF/ST-Q-MEKF/MATLAB Function'
//  '<S224>' : 'STQMEKF/Send Data  to Orin/Subsystem'
//  '<S225>' : 'STQMEKF/Thruster Control Code/Change BLACK Behavior'
//  '<S226>' : 'STQMEKF/Thruster Control Code/Change BLUE Behavior'
//  '<S227>' : 'STQMEKF/Thruster Control Code/Change RED Behavior'
//  '<S228>' : 'STQMEKF/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle'
//  '<S229>' : 'STQMEKF/Thruster Control Code/Change BLACK Behavior/Rotate Forces to Body'
//  '<S230>' : 'STQMEKF/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Duty Cycle @ PWM'
//  '<S231>' : 'STQMEKF/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Generate Initial Guess'
//  '<S232>' : 'STQMEKF/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/MATLAB Function1'
//  '<S233>' : 'STQMEKF/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/MATLAB Function5'
//  '<S234>' : 'STQMEKF/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Rotate Forces to Inertial'
//  '<S235>' : 'STQMEKF/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem'
//  '<S236>' : 'STQMEKF/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem1'
//  '<S237>' : 'STQMEKF/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Generate Initial Guess/MATLAB Function'
//  '<S238>' : 'STQMEKF/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Rotate Forces to Inertial/Create Rotation Matrix'
//  '<S239>' : 'STQMEKF/Thruster Control Code/Change BLACK Behavior/Rotate Forces to Body/Create Rotation Matrix'
//  '<S240>' : 'STQMEKF/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle'
//  '<S241>' : 'STQMEKF/Thruster Control Code/Change BLUE Behavior/Rotate Forces to Body'
//  '<S242>' : 'STQMEKF/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Duty Cycle @ PWM'
//  '<S243>' : 'STQMEKF/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Generate Initial Guess'
//  '<S244>' : 'STQMEKF/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/MATLAB Function1'
//  '<S245>' : 'STQMEKF/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/MATLAB Function5'
//  '<S246>' : 'STQMEKF/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Rotate Forces to Inertial'
//  '<S247>' : 'STQMEKF/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem'
//  '<S248>' : 'STQMEKF/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem1'
//  '<S249>' : 'STQMEKF/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Generate Initial Guess/MATLAB Function'
//  '<S250>' : 'STQMEKF/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Rotate Forces to Inertial/Create Rotation Matrix'
//  '<S251>' : 'STQMEKF/Thruster Control Code/Change BLUE Behavior/Rotate Forces to Body/Create Rotation Matrix'
//  '<S252>' : 'STQMEKF/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle'
//  '<S253>' : 'STQMEKF/Thruster Control Code/Change RED Behavior/Rotate Forces to Body'
//  '<S254>' : 'STQMEKF/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Duty Cycle @ PWM'
//  '<S255>' : 'STQMEKF/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Generate Initial Guess'
//  '<S256>' : 'STQMEKF/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/MATLAB Function5'
//  '<S257>' : 'STQMEKF/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/MATLAB Function8'
//  '<S258>' : 'STQMEKF/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Rotate Forces to Inertial'
//  '<S259>' : 'STQMEKF/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem'
//  '<S260>' : 'STQMEKF/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem1'
//  '<S261>' : 'STQMEKF/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Generate Initial Guess/MATLAB Function'
//  '<S262>' : 'STQMEKF/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Rotate Forces to Inertial/Create Rotation Matrix'
//  '<S263>' : 'STQMEKF/Thruster Control Code/Change RED Behavior/Rotate Forces to Body/Create Rotation Matrix'

#endif                                 // STQMEKF_h_

//
// File trailer for generated code.
//
// [EOF]
//
