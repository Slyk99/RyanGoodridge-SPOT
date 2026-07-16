//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MPC.h
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
#ifndef MPC_h_
#define MPC_h_
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
#include "MPC_types.h"

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

// Block states (default storage) for system '<S4>/Default PD Control (BLACK)'
struct DW_DefaultPDControlBLACK_MPC_T {
  real_T UD_DSTATE;                    // '<S161>/UD'
  real_T UD_DSTATE_g;                  // '<S162>/UD'
  real_T UD_DSTATE_e;                  // '<S163>/UD'
};

// Block states (default storage) for system '<S5>/Change BLACK Behavior'
struct DW_ChangeBLACKBehavior_MPC_T {
  real_T UDPSend_NetworkLib[137];      // '<S176>/UDP Send'
};

// Block signals for system '<S234>/Enabled Subsystem'
struct B_EnabledSubsystem_MPC_T {
  real_T Delay[3];                     // '<S239>/Delay'
  real_T Delay1[3];                    // '<S239>/Delay1'
  real_T ema[3];                       // '<S239>/MATLAB Function'
};

// Block states (default storage) for system '<S234>/Enabled Subsystem'
struct DW_EnabledSubsystem_MPC_T {
  real_T Delay_DSTATE[3];              // '<S239>/Delay'
  real_T Delay1_DSTATE[3];             // '<S239>/Delay1'
  boolean_T icLoad;                    // '<S239>/Delay'
  boolean_T EnabledSubsystem_MODE;     // '<S234>/Enabled Subsystem'
};

// Block signals for system '<S235>/Enabled Subsystem'
struct B_EnabledSubsystem_MPC_b_T {
  real_T Delay[3];                     // '<S241>/Delay'
  real_T Delay1[3];                    // '<S241>/Delay1'
  real_T ema[3];                       // '<S241>/MATLAB Function'
};

// Block states (default storage) for system '<S235>/Enabled Subsystem'
struct DW_EnabledSubsystem_MPC_m_T {
  real_T Delay_DSTATE[3];              // '<S241>/Delay'
  real_T Delay1_DSTATE[3];             // '<S241>/Delay1'
  boolean_T icLoad;                    // '<S241>/Delay'
  boolean_T EnabledSubsystem_MODE;     // '<S235>/Enabled Subsystem'
};

// Block signals for system '<S295>/Pseudoinverse1'
struct B_Pseudoinverse1_MPC_T {
  real_T Pseudoinverse1[24];           // '<S295>/Pseudoinverse1'
};

// Block states (default storage) for system '<S295>/Pseudoinverse1'
struct DW_Pseudoinverse1_MPC_T {
  dsp_simulink_Pseudoinverse_MP_T obj; // '<S295>/Pseudoinverse1'
  boolean_T objisempty;                // '<S295>/Pseudoinverse1'
};

// Block signals (default storage)
struct B_MPC_T {
  real_T b_u1[1536];
  smSS6fEwaptVbzYAOdOZgjB_MPC_T obj;
  smSS6fEwaptVbzYAOdOZgjB_MPC_T obj_m;
  smSS6fEwaptVbzYAOdOZgjB_MPC_T obj_c;
  real_T Merge2[3];                    // '<S4>/Merge2'
  real_T TmpSignalConversionAtUDPSendInp[10];
  real_T duty_cycles[8];               // '<S316>/MATLAB Function5'
  real_T ThrustPer_Final[8];           // '<S324>/ThrustPer_Final'
  real_T In1;                          // '<S323>/In1'
  real_T duty_cycles_k[8];             // '<S304>/MATLAB Function5'
  real_T ThrustPer_Final_h[8];         // '<S312>/ThrustPer_Final'
  real_T In1_g;                        // '<S311>/In1'
  real_T duty_cycles_n[8];             // '<S292>/MATLAB Function5'
  real_T ThrustPer_Final_h5[8];        // '<S300>/ThrustPer_Final'
  real_T In1_g2;                       // '<S299>/In1'
  real_T TmpSignalConversionAtUDPSendI_o[28];
  real_T P[36];                        // '<S268>/MATLAB Function'
  real_T V[9];                         // '<S268>/MATLAB Function'
  real_T x_c[6];                       // '<S267>/MATLAB Function'
  real_T P_g[36];                      // '<S267>/MATLAB Function'
  real_T V_g[9];                       // '<S267>/MATLAB Function'
  real_T x_o[6];                       // '<S266>/MATLAB Function'
  real_T P_f[36];                      // '<S266>/MATLAB Function'
  real_T V_gq[9];                      // '<S266>/MATLAB Function'
  real_T ReceivePhaseSpaceData_o1[19]; // '<S224>/Receive PhaseSpace Data'
  real_T ConvertBLAXfrommmtom;        // '<S225>/Convert BLAX from [mm] to [m]'
  real_T ConvertBLUXfrommmtom;        // '<S226>/Convert BLUX from [mm] to [m]'
  real_T ConvertREDXfrommmtom;        // '<S227>/Convert REDX from [mm] to [m]'
  real_T Clock;                        // '<S224>/Clock'
  real_T dy[3];                        // '<S261>/MATLAB Function'
  real_T dy_l[3];                      // '<S259>/MATLAB Function'
  real_T y2y1;                         // '<S257>/y2-y1'
  real_T dy_c[3];                      // '<S251>/MATLAB Function'
  real_T dy_e[3];                      // '<S249>/MATLAB Function'
  real_T y2y1_o;                       // '<S247>/y2-y1'
  real_T dy_i[3];                      // '<S241>/MATLAB Function'
  real_T dy_k[3];                      // '<S239>/MATLAB Function'
  real_T y2y1_ob;                      // '<S237>/y2-y1'
  real_T Subtract;                     // '<S231>/Subtract'
  real_T Memory;                       // '<S230>/Memory'
  real32_T UDPReceive1_o1[4];          // '<S279>/UDP Receive1'
  int32_T UDPReceive_o1;               // '<S229>/UDP Receive'
  int32_T UDPReceive2_o1;              // '<S229>/UDP Receive2'
  int32_T UDPReceive3_o1;              // '<S229>/UDP Receive3'
  uint8_T StringtoASCII[31];           // '<S217>/String to ASCII'
  uint8_T StringtoASCII2[31];          // '<S216>/String to ASCII2'
  uint8_T StringtoASCII1[31];          // '<S215>/String to ASCII1'
  boolean_T RelationalOperator1;       // '<S228>/Relational Operator1'
  B_Pseudoinverse1_MPC_T Pseudoinverse1_pn;// '<S295>/Pseudoinverse1'
  B_Pseudoinverse1_MPC_T Pseudoinverse1_p;// '<S295>/Pseudoinverse1'
  B_Pseudoinverse1_MPC_T Pseudoinverse1;// '<S295>/Pseudoinverse1'
  B_EnabledSubsystem_MPC_b_T EnabledSubsystem_a;// '<S255>/Enabled Subsystem'
  B_EnabledSubsystem_MPC_T EnabledSubsystem_k;// '<S254>/Enabled Subsystem'
  B_EnabledSubsystem_MPC_b_T EnabledSubsystem_g;// '<S245>/Enabled Subsystem'
  B_EnabledSubsystem_MPC_T EnabledSubsystem_l;// '<S244>/Enabled Subsystem'
  B_EnabledSubsystem_MPC_b_T EnabledSubsystem_n;// '<S235>/Enabled Subsystem'
  B_EnabledSubsystem_MPC_T EnabledSubsystem_m;// '<S234>/Enabled Subsystem'
};

// Block states (default storage) for system '<Root>'
struct DW_MPC_T {
  nvidiacoder_sensors_BMI160Blo_T obj; // '<S219>/Gyroscope//Accelerometer'
  Dynamixel_Controller_MPC_T obj_n;
  // '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes' 
  GPIO_Write_MPC_T obj_c;              // '<S218>/GPIO Write1'
  ReadArm_Position_Rates_MPC_T obj_d;
                     // '<S221>/Read Joint Positions using  Dynamixel Encoders'
  IdentifyPlatform_MPC_T obj_dk;       // '<S278>/WhoAmI'
  CustomDataLogger_MPC_T obj_i;        // '<S179>/MATLAB System'
  real_T Delay_DSTATE;                 // '<S19>/Delay'
  real_T Delay2_DSTATE[9];             // '<S276>/Delay2'
  real_T Delay1_DSTATE[6];             // '<S268>/Delay1'
  real_T Delay_DSTATE_i[36];           // '<S268>/Delay'
  real_T Delay2_DSTATE_k[9];           // '<S268>/Delay2'
  real_T Delay2_DSTATE_p[9];           // '<S270>/Delay2'
  real_T Delay1_DSTATE_c[6];           // '<S266>/Delay1'
  real_T Delay_DSTATE_n[36];           // '<S266>/Delay'
  real_T Delay2_DSTATE_j[9];           // '<S266>/Delay2'
  real_T Delay2_DSTATE_f[9];           // '<S273>/Delay2'
  real_T Delay1_DSTATE_g[6];           // '<S267>/Delay1'
  real_T Delay_DSTATE_h[36];           // '<S267>/Delay'
  real_T Delay2_DSTATE_n[9];           // '<S267>/Delay2'
  real_T Delay_DSTATE_hj;              // '<S318>/Delay'
  real_T Delay_DSTATE_ik;              // '<S306>/Delay'
  real_T Delay_DSTATE_j;               // '<S294>/Delay'
  real_T Delay2_DSTATE_e;              // '<S279>/Delay2'
  real_T Delay_DSTATE_c[3];            // '<S279>/Delay'
  real_T Delay1_DSTATE_d;              // '<S279>/Delay1'
  real_T Delay2_DSTATE_jo;             // '<S233>/Delay2'
  real_T Delay1_DSTATE_i;              // '<S233>/Delay1'
  real_T Delay1_DSTATE_g3[3];          // '<S235>/Delay1'
  real_T Delay1_DSTATE_b[3];           // '<S234>/Delay1'
  real_T Delay2_DSTATE_l;              // '<S243>/Delay2'
  real_T Delay1_DSTATE_l;              // '<S243>/Delay1'
  real_T Delay1_DSTATE_m[3];           // '<S245>/Delay1'
  real_T Delay1_DSTATE_lv[3];          // '<S244>/Delay1'
  real_T Delay2_DSTATE_l0;             // '<S253>/Delay2'
  real_T Delay1_DSTATE_ld;             // '<S253>/Delay1'
  real_T Delay1_DSTATE_cd[3];          // '<S255>/Delay1'
  real_T Delay1_DSTATE_cq[3];          // '<S254>/Delay1'
  real_T Delay_DSTATE_o;               // '<S221>/Delay'
  real_T Delay1_DSTATE_cg;             // '<S221>/Delay1'
  real_T Delay2_DSTATE_h;              // '<S221>/Delay2'
  real_T UD_DSTATE;                    // '<S157>/UD'
  real_T UD_DSTATE_e;                  // '<S158>/UD'
  real_T UD_DSTATE_a;                  // '<S159>/UD'
  real_T UD_DSTATE_l;                  // '<S143>/UD'
  real_T UD_DSTATE_k;                  // '<S144>/UD'
  real_T UD_DSTATE_h;                  // '<S145>/UD'
  real_T UD_DSTATE_o;                  // '<S166>/UD'
  real_T UD_DSTATE_n;                  // '<S167>/UD'
  real_T UD_DSTATE_hu;                 // '<S168>/UD'
  real_T UD_DSTATE_aq;                 // '<S148>/UD'
  real_T UD_DSTATE_p;                  // '<S149>/UD'
  real_T UD_DSTATE_pr;                 // '<S150>/UD'
  real_T UD_DSTATE_d;                  // '<S171>/UD'
  real_T UD_DSTATE_j;                  // '<S172>/UD'
  real_T UD_DSTATE_hb;                 // '<S173>/UD'
  real_T Delay1_DSTATE_dn[13];         // '<S97>/Delay1'
  real_T Delay_DSTATE_g[144];          // '<S97>/Delay'
  real_T Delay1_DSTATE_ml[9];          // '<S98>/Delay1'
  real_T Delay2_DSTATE_j2[9];          // '<S98>/Delay2'
  real_T Delay_DSTATE_p[144];          // '<S98>/Delay'
  real_T Delay1_DSTATE_gw[13];         // '<S101>/Delay1'
  real_T Delay_DSTATE_a[144];          // '<S101>/Delay'
  real_T Delay2_DSTATE_nz[36];         // '<S101>/Delay2'
  real_T Delay1_DSTATE_n[9];           // '<S102>/Delay1'
  real_T Delay4_DSTATE[9];             // '<S102>/Delay4'
  real_T Delay2_DSTATE_kf[144];        // '<S102>/Delay2'
  real_T Delay3_DSTATE[36];            // '<S102>/Delay3'
  real_T UDPSend_NetworkLib[137];      // '<S18>/UDP Send'
  real_T Vis_q[4];                     // '<Root>/Data Store Memory13'
  real_T Vis_R[9];                     // '<Root>/Data Store Memory14'
  real_T Vis_x[3];                     // '<Root>/Data Store Memory15'
  real_T QMEKFx[13];                   // '<Root>/Data Store Memory17'
  real_T QMEKFP[144];                  // '<Root>/Data Store Memory18'
  real_T QMEKFt;                       // '<Root>/Data Store Memory19'
  real_T STQMEKFx[13];                 // '<Root>/Data Store Memory20'
  real_T STQMEKFP[144];                // '<Root>/Data Store Memory21'
  real_T STQMEKFt;                     // '<Root>/Data Store Memory22'
  real_T DQMEKFx[13];                  // '<Root>/Data Store Memory23'
  real_T DQMEKFP[144];                 // '<Root>/Data Store Memory24'
  real_T DQMEKFt;                      // '<Root>/Data Store Memory25'
  real_T STDQMEKFx[13];                // '<Root>/Data Store Memory26'
  real_T STDQMEKFP[144];               // '<Root>/Data Store Memory27'
  real_T STDQMEKFt;                    // '<Root>/Data Store Memory28'
  real_T RMEKFx[13];                   // '<Root>/Data Store Memory29'
  real_T RMEKFP[144];                  // '<Root>/Data Store Memory30'
  real_T RMEKFt;                       // '<Root>/Data Store Memory31'
  real_T STRMEKFx[13];                 // '<Root>/Data Store Memory32'
  real_T STRMEKFP[144];                // '<Root>/Data Store Memory33'
  real_T STRMEKFt;                     // '<Root>/Data Store Memory34'
  real_T RMEKFR[9];                    // '<Root>/Data Store Memory38'
  real_T STRMEKFR[9];                  // '<Root>/Data Store Memory39'
  real_T Conf;                         // '<Root>/Data Store Memory40'
  real_T Vis_x_zoh[3];                 // '<Root>/Data Store Memory41'
  real_T Conf_zoh;                     // '<Root>/Data Store Memory43'
  real_T Vis_q_zoh[4];                 // '<Root>/Data Store Memory45'
  real_T QMEKFerror[6];                // '<Root>/Data Store Memory47'
  real_T STQMEKFerror[6];              // '<Root>/Data Store Memory48'
  real_T CNNError[3];                  // '<Root>/Data Store Memory49'
  real_T RMEKFerror[6];                // '<Root>/Data Store Memory50'
  real_T STRMEKFerror[6];              // '<Root>/Data Store Memory51'
  real_T DQMEKFerror[6];               // '<Root>/Data Store Memory52'
  real_T STDQMEKFerror[6];             // '<Root>/Data Store Memory53'
  real_T QMEKFNIS;                     // '<Root>/Data Store Memory57'
  real_T STQMEKFNIS;                   // '<Root>/Data Store Memory58'
  real_T STRMEKFNIS;                   // '<Root>/Data Store Memory59'
  real_T RMEKFNIS;                     // '<Root>/Data Store Memory60'
  real_T DQMEKFNIS;                    // '<Root>/Data Store Memory61'
  real_T STDQMEKFNIS;                  // '<Root>/Data Store Memory62'
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
  real_T MPC_Optimization_Var[135];    // '<Root>/Universal_Time21'
  real_T RED_Estimated_States[6];      // '<Root>/Universal_Time22'
  real_T MPC_Solver_Result[3];         // '<Root>/Universal_Time23'
  real_T ARM_Measured_States[6];       // '<Root>/Universal_Time24'
  real_T BLACK_Desired_States[3];      // '<Root>/Universal_Time25'
  real_T RED_Measured_States[9];       // '<Root>/Universal_Time26'
  real_T RED_Saturated_Controls[3];    // '<Root>/Universal_Time28'
  real_T RED_Desired_States[3];        // '<Root>/Universal_Time29'
  real_T BLACK_Thruster_ON_Count;      // '<Root>/Universal_Time3'
  real_T RED_IMU_Measurements[3];      // '<Root>/Universal_Time31'
  real_T BLACK_IMU_Measurements[3];    // '<Root>/Universal_Time33'
  real_T BLUE_IMU_Measurements[3];     // '<Root>/Universal_Time34'
  real_T MPC_Target_Holding_Radius[2]; // '<Root>/Universal_Time37'
  real_T MPC_Target_Trajectory[135];   // '<Root>/Universal_Time38'
  real_T BLUE_Measured_States[9];      // '<Root>/Universal_Time4'
  real_T MPC_Docking_Enabler;          // '<Root>/Universal_Time41'
  real_T RED_Measured_States_RAW[9];   // '<Root>/Universal_Time42'
  real_T BLACK_Measured_States_RAW[9]; // '<Root>/Universal_Time43'
  real_T BLUE_Measured_States_RAW[9];  // '<Root>/Universal_Time44'
  real_T Toggle_Nav;                   // '<Root>/Universal_Time45'
  real_T BLUE_Saturated_Controls[3];   // '<Root>/Universal_Time6'
  real_T ARM_Desired_States[3];        // '<Root>/Universal_Time8'
  real_T MPC_Controls[3];              // '<Root>/Universal_Time9'
  real_T UDPSend_NetworkLib_m[137];    // '<S288>/UDP Send'
  real_T UDPReceive1_NetworkLib[137];  // '<S279>/UDP Receive1'
  real_T ReceivePhaseSpaceData_NetworkLi[137];// '<S224>/Receive PhaseSpace Data' 
  real_T UDPReceive_NetworkLib[137];   // '<S229>/UDP Receive'
  real_T UDPReceive2_NetworkLib[137];  // '<S229>/UDP Receive2'
  real_T UDPReceive3_NetworkLib[137];  // '<S229>/UDP Receive3'
  real_T Memory_PreviousInput;         // '<S230>/Memory'
  real_T UDPSend3_NetworkLib[137];     // '<S217>/UDP Send3'
  real_T UDPSend2_NetworkLib[137];     // '<S216>/UDP Send2'
  real_T UDPSend1_NetworkLib[137];     // '<S215>/UDP Send1'
  real_T freq;                         // '<S102>/MATLAB Function1'
  real_T freq_c;                       // '<S101>/MATLAB Function1'
  real_T freq_f;                       // '<S98>/MATLAB Function1'
  real_T freq_m;                       // '<S97>/MATLAB Function1'
  char_T RED_Logger[256];              // '<Root>/RED_Tz3'
  int32_T Delay_DSTATE_ip[5];          // '<S229>/Delay'
  int32_T Delay1_DSTATE_h[5];          // '<S229>/Delay1'
  int32_T Delay2_DSTATE_hq[5];         // '<S229>/Delay2'
  uint32_T state[625];                 // '<S102>/MATLAB Function1'
  uint32_T state_c[625];               // '<S101>/MATLAB Function1'
  uint32_T state_k[625];               // '<S97>/MATLAB Function1'
  int8_T Ifperforminganexperimentgrabthe;
  // '<S11>/If performing an experiment, grab the PhaseSpace data. Otherwise, use a clock to set time in SIM.' 
  uint8_T pauseState;                  // '<S219>/Gyroscope//Accelerometer'
  boolean_T freq_not_empty;            // '<S102>/MATLAB Function1'
  boolean_T savedTime_not_empty;       // '<S102>/MATLAB Function1'
  boolean_T freq_not_empty_a;          // '<S101>/MATLAB Function1'
  boolean_T savedTime_not_empty_m;     // '<S101>/MATLAB Function1'
  boolean_T freq_not_empty_j;          // '<S98>/MATLAB Function1'
  boolean_T savedTime_not_empty_e;     // '<S98>/MATLAB Function1'
  boolean_T freq_not_empty_g;          // '<S97>/MATLAB Function1'
  boolean_T savedTime_not_empty_n;     // '<S97>/MATLAB Function1'
  DW_Pseudoinverse1_MPC_T Pseudoinverse1_pn;// '<S295>/Pseudoinverse1'
  DW_Pseudoinverse1_MPC_T Pseudoinverse1_p;// '<S295>/Pseudoinverse1'
  DW_Pseudoinverse1_MPC_T Pseudoinverse1;// '<S295>/Pseudoinverse1'
  DW_EnabledSubsystem_MPC_m_T EnabledSubsystem_a;// '<S255>/Enabled Subsystem'
  DW_EnabledSubsystem_MPC_T EnabledSubsystem_k;// '<S254>/Enabled Subsystem'
  DW_EnabledSubsystem_MPC_m_T EnabledSubsystem_g;// '<S245>/Enabled Subsystem'
  DW_EnabledSubsystem_MPC_T EnabledSubsystem_l;// '<S244>/Enabled Subsystem'
  DW_EnabledSubsystem_MPC_m_T EnabledSubsystem_n;// '<S235>/Enabled Subsystem'
  DW_EnabledSubsystem_MPC_T EnabledSubsystem_m;// '<S234>/Enabled Subsystem'
  DW_ChangeBLACKBehavior_MPC_T ChangeREDBehavior;// '<S5>/Change RED Behavior'
  DW_ChangeBLACKBehavior_MPC_T ChangeBLUEBehavior;// '<S5>/Change BLUE Behavior' 
  DW_ChangeBLACKBehavior_MPC_T ChangeBLACKBehavior;// '<S5>/Change BLACK Behavior' 
  DW_DefaultPDControlBLACK_MPC_T DefaultLQRControlBLACK;// '<S4>/Default LQR Control (BLACK)' 
  DW_DefaultPDControlBLACK_MPC_T DefaultPDControlBLACK;// '<S4>/Default PD Control (BLACK)' 
};

// Parameters for system: '<S1>/Phase #0: Synchronization'
struct P_Phase0Synchronization_MPC_T_ {
  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S20>/Constant1'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S20>/Constant2'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<S20>/Constant3'

  real_T Constant4_Value;              // Expression: 0
                                          //  Referenced by: '<S20>/Constant4'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<S20>/Constant5'

  real_T Constant6_Value;              // Expression: 0
                                          //  Referenced by: '<S20>/Constant6'

  real_T Constant7_Value;              // Expression: 0
                                          //  Referenced by: '<S20>/Constant7'

  real_T Constant8_Value;              // Expression: 0
                                          //  Referenced by: '<S20>/Constant8'

  real_T PuckState1_Value;             // Expression: 0
                                          //  Referenced by: '<S20>/Puck State1'

  real_T PuckState_Value;              // Expression: 0
                                          //  Referenced by: '<S20>/Puck State'

  char_T StringConstant_String[256];   // Expression: "Chaser: Running Phase 0"
                                          //  Referenced by: '<S20>/String Constant'

};

// Parameters for system: '<S1>/Phase #4: Return Home'
struct P_Phase4ReturnHome_MPC_T_ {
  real_T Constant11_Value;             // Expression: 0
                                          //  Referenced by: '<S24>/Constant11'

  real_T Constant12_Value;             // Expression: 0
                                          //  Referenced by: '<S24>/Constant12'

  real_T Constant14_Value;             // Expression: 0
                                          //  Referenced by: '<S24>/Constant14'

  real_T Constant15_Value;             // Expression: 0
                                          //  Referenced by: '<S24>/Constant15'

  real_T Constant18_Value;             // Expression: 0
                                          //  Referenced by: '<S24>/Constant18'

  real_T Constant4_Value;              // Expression: 2
                                          //  Referenced by: '<S24>/Constant4'

  real_T Constant5_Value;              // Expression: 2
                                          //  Referenced by: '<S24>/Constant5'

  real_T Constant6_Value;              // Expression: 1
                                          //  Referenced by: '<S24>/Constant6'

  real_T Constant8_Value;              // Expression: 2
                                          //  Referenced by: '<S24>/Constant8'

  real_T PuckState1_Value;             // Expression: 0
                                          //  Referenced by: '<S24>/Puck State1'

  real_T Constant3_Value;              // Expression: pi/2
                                          //  Referenced by: '<S55>/Constant3'

  real_T Constant1_Value;              // Expression: pi/2
                                          //  Referenced by: '<S55>/Constant1'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S55>/Constant2'

};

// Parameters for system: '<S4>/Disable Thrusters (RED)'
struct P_DisableThrustersRED_MPC_T_ {
  real_T Zero_Value;                   // Expression: 0
                                          //  Referenced by: '<S135>/Zero'

};

// Parameters for system: '<S4>/Default PD Control (BLACK)'
struct P_DefaultPDControlBLACK_MPC_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S161>/UD'

  real_T DiscreteDerivative1_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative1_ICPrevScale
                                 //  Referenced by: '<S162>/UD'

  real_T DiscreteDerivative2_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative2_ICPrevScale
                                 //  Referenced by: '<S163>/UD'

  real_T TSamp_WtEt;                   // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S161>/TSamp'

  real_T TSamp_WtEt_l;                 // Computed Parameter: TSamp_WtEt_l
                                          //  Referenced by: '<S162>/TSamp'

  real_T TSamp_WtEt_o;                 // Computed Parameter: TSamp_WtEt_o
                                          //  Referenced by: '<S163>/TSamp'

};

// Parameters for system: '<S5>/Change BLACK Behavior'
struct P_ChangeBLACKBehavior_MPC_T_ {
  int32_T Constant1_Value;             // Computed Parameter: Constant1_Value
                                          //  Referenced by: '<S176>/Constant1'

  int32_T UDPSend_Port;                // Computed Parameter: UDPSend_Port
                                          //  Referenced by: '<S176>/UDP Send'

};

// Parameters for system: '<S234>/Enabled Subsystem'
struct P_EnabledSubsystem_MPC_T_ {
  real_T dydt_Y0;                      // Computed Parameter: dydt_Y0
                                          //  Referenced by: '<S239>/dy//dt'

  real_T Constant2_Value;              // Expression: 0.1
                                          //  Referenced by: '<S239>/Constant2'

  real_T Delay1_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S239>/Delay1'

};

// Parameters for system: '<S235>/Enabled Subsystem'
struct P_EnabledSubsystem_MPC_d_T_ {
  real_T dydt_Y0;                      // Computed Parameter: dydt_Y0
                                          //  Referenced by: '<S241>/dy//dt'

  real_T Constant2_Value;              // Expression: 0.1
                                          //  Referenced by: '<S241>/Constant2'

  real_T Delay1_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S241>/Delay1'

};

// Parameters (default storage)
struct P_MPC_T_ {
  real_T F_black_X_nominal;            // Variable: F_black_X_nominal
                                          //  Referenced by: '<S292>/MATLAB Function5'

  real_T F_black_Y_nominal;            // Variable: F_black_Y_nominal
                                          //  Referenced by: '<S292>/MATLAB Function5'

  real_T F_blue_X_nominal;             // Variable: F_blue_X_nominal
                                          //  Referenced by: '<S304>/MATLAB Function5'

  real_T F_blue_Y_nominal;             // Variable: F_blue_Y_nominal
                                          //  Referenced by: '<S304>/MATLAB Function5'

  real_T F_red_X_nominal;              // Variable: F_red_X_nominal
                                          //  Referenced by: '<S316>/MATLAB Function5'

  real_T F_red_Y_nominal;              // Variable: F_red_Y_nominal
                                          //  Referenced by: '<S316>/MATLAB Function5'

  real_T F_thrusters_BLACK[8];         // Variable: F_thrusters_BLACK
                                          //  Referenced by: '<S295>/MATLAB Function'

  real_T F_thrusters_BLUE[8];          // Variable: F_thrusters_BLUE
                                          //  Referenced by: '<S307>/MATLAB Function'

  real_T F_thrusters_RED[8];           // Variable: F_thrusters_RED
                                          //  Referenced by: '<S319>/MATLAB Function'

  real_T IBLACK;                       // Variable: IBLACK
                                          //  Referenced by:
                                          //    '<S266>/MATLAB Function'
                                          //    '<S267>/MATLAB Function'

  real_T IRED;                         // Variable: IRED
                                          //  Referenced by: '<S268>/MATLAB Function'

  real_T K_BLACK[18];                  // Variable: K_BLACK
                                          //  Referenced by:
                                          //    '<S125>/Constant2'
                                          //    '<S129>/Constant2'
                                          //    '<S131>/Constant2'

  real_T K_BLUE[18];                   // Variable: K_BLUE
                                          //  Referenced by: '<S126>/Constant2'

  real_T K_RED[18];                    // Variable: K_RED
                                          //  Referenced by: '<S127>/Constant2'

  real_T Kd_elarm;                     // Variable: Kd_elarm
                                          //  Referenced by: '<S154>/kd_elarm'

  real_T Kd_sharm;                     // Variable: Kd_sharm
                                          //  Referenced by: '<S155>/kd_sharm'

  real_T Kd_tblue;                     // Variable: Kd_tblue
                                          //  Referenced by: '<S130>/Gain5'

  real_T Kd_wrarm;                     // Variable: Kd_wrarm
                                          //  Referenced by: '<S156>/kd_wrarm'

  real_T Kd_xblue;                     // Variable: Kd_xblue
                                          //  Referenced by: '<S130>/Gain3'

  real_T Kd_yblue;                     // Variable: Kd_yblue
                                          //  Referenced by: '<S130>/Gain4'

  real_T Kp_elarm;                     // Variable: Kp_elarm
                                          //  Referenced by: '<S154>/kp_elarm'

  real_T Kp_sharm;                     // Variable: Kp_sharm
                                          //  Referenced by: '<S155>/kp_sharm'

  real_T Kp_tblue;                     // Variable: Kp_tblue
                                          //  Referenced by: '<S130>/Gain2'

  real_T Kp_wrarm;                     // Variable: Kp_wrarm
                                          //  Referenced by: '<S156>/kp_wrarm'

  real_T Kp_xblue;                     // Variable: Kp_xblue
                                          //  Referenced by: '<S130>/Gain'

  real_T Kp_yblue;                     // Variable: Kp_yblue
                                          //  Referenced by: '<S130>/Gain1'

  real_T PQ[144];                      // Variable: PQ
                                          //  Referenced by:
                                          //    '<S97>/Delay'
                                          //    '<S101>/Delay'

  real_T PR[144];                      // Variable: PR
                                          //  Referenced by:
                                          //    '<S98>/Delay'
                                          //    '<S102>/Delay2'

  real_T PWMFreq;                      // Variable: PWMFreq
                                          //  Referenced by:
                                          //    '<S18>/PWM Frequency'
                                          //    '<S292>/MATLAB Function1'
                                          //    '<S304>/MATLAB Function1'
                                          //    '<S316>/MATLAB Function8'
                                          //    '<S294>/Constant1'
                                          //    '<S306>/Constant1'
                                          //    '<S318>/Constant1'

  real_T Phase0_End;                   // Variable: Phase0_End
                                          //  Referenced by: '<S1>/Constant4'

  real_T Phase1_End;                   // Variable: Phase1_End
                                          //  Referenced by: '<S1>/Constant'

  real_T Phase2_End;                   // Variable: Phase2_End
                                          //  Referenced by:
                                          //    '<S1>/Constant1'
                                          //    '<S37>/Constant2'
                                          //    '<S40>/Constant2'
                                          //    '<S44>/Constant2'
                                          //    '<S48>/Constant2'
                                          //    '<S52>/Constant2'

  real_T Phase3_End;                   // Variable: Phase3_End
                                          //  Referenced by: '<S1>/Constant2'

  real_T Phase3_SubPhase1_End;         // Variable: Phase3_SubPhase1_End
                                          //  Referenced by: '<S23>/Constant4'

  real_T Phase3_SubPhase2_End;         // Variable: Phase3_SubPhase2_End
                                          //  Referenced by: '<S23>/Constant1'

  real_T Phase3_SubPhase3_End;         // Variable: Phase3_SubPhase3_End
                                          //  Referenced by: '<S23>/Constant2'

  real_T Phase3_SubPhase4_End;         // Variable: Phase3_SubPhase4_End
                                          //  Referenced by: '<S23>/Constant3'

  real_T Phase4_End;                   // Variable: Phase4_End
                                          //  Referenced by: '<S1>/Constant3'

  real_T Phase5_End;                   // Variable: Phase5_End
                                          //  Referenced by: '<S1>/Constant6'

  real_T Q[144];                       // Variable: Q
                                          //  Referenced by:
                                          //    '<S97>/MATLAB Function1'
                                          //    '<S98>/MATLAB Function1'
                                          //    '<S101>/MATLAB Function1'
                                          //    '<S102>/MATLAB Function1'

  real_T R[36];                        // Variable: R
                                          //  Referenced by:
                                          //    '<S97>/MATLAB Function1'
                                          //    '<S98>/MATLAB Function1'
                                          //    '<S101>/MATLAB Function1'
                                          //    '<S102>/MATLAB Function1'

  real_T Tz_lim_elarm;                 // Variable: Tz_lim_elarm
                                          //  Referenced by: '<S153>/Saturation1'

  real_T Tz_lim_sharm;                 // Variable: Tz_lim_sharm
                                          //  Referenced by: '<S153>/Saturation'

  real_T Tz_lim_wrarm;                 // Variable: Tz_lim_wrarm
                                          //  Referenced by: '<S153>/Saturation3'

  real_T baseRate;                     // Variable: baseRate
                                          //  Referenced by:
                                          //    '<S67>/MATLAB Function'
                                          //    '<S68>/MATLAB Function'
                                          //    '<S221>/Read Joint Positions using  Dynamixel Encoders'
                                          //    '<S278>/WhoAmI'
                                          //    '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T dataRate;                     // Variable: dataRate
                                          //  Referenced by:
                                          //    '<S233>/Constant'
                                          //    '<S243>/Constant'
                                          //    '<S253>/Constant'

  real_T home_states_BLACK[3];         // Variable: home_states_BLACK
                                          //  Referenced by:
                                          //    '<S56>/Desired States (BLACK)'
                                          //    '<S60>/Desired States (BLACK)'

  real_T home_states_BLUE[3];          // Variable: home_states_BLUE
                                          //  Referenced by:
                                          //    '<S57>/Desired States (BLUE)'
                                          //    '<S61>/Desired States (BLUE)'

  real_T home_states_RED[3];           // Variable: home_states_RED
                                          //  Referenced by:
                                          //    '<S58>/Constant2'
                                          //    '<S62>/Constant2'

  real_T init_states_BLACK[3];         // Variable: init_states_BLACK
                                          //  Referenced by:
                                          //    '<S28>/Desired States (BLACK)'
                                          //    '<S51>/Constant'

  real_T init_states_BLUE[3];          // Variable: init_states_BLUE
                                          //  Referenced by: '<S29>/Desired States (BLUE)'

  real_T init_states_RED[3];           // Variable: init_states_RED
                                          //  Referenced by: '<S30>/Constant2'

  real_T mBLACK;                       // Variable: mBLACK
                                          //  Referenced by:
                                          //    '<S266>/MATLAB Function'
                                          //    '<S267>/MATLAB Function'

  real_T mRED;                         // Variable: mRED
                                          //  Referenced by: '<S268>/MATLAB Function'

  real_T maxd[2];                      // Variable: maxd
                                          //  Referenced by:
                                          //    '<S97>/MATLAB Function1'
                                          //    '<S98>/MATLAB Function1'
                                          //    '<S101>/MATLAB Function1'
                                          //    '<S102>/MATLAB Function1'

  real_T platformSelection;            // Variable: platformSelection
                                          //  Referenced by: '<S229>/MATLAB Function'

  real_T r_hold_tar_0[2];              // Variable: r_hold_tar_0
                                          //  Referenced by: '<Root>/Universal_Time37'

  real_T rho;                          // Variable: rho
                                          //  Referenced by: '<S101>/MATLAB Function1'

  real_T simMode;                      // Variable: simMode
                                          //  Referenced by: '<S17>/Constant'

  real_T thruster_dist2CG_BLACK[8];    // Variable: thruster_dist2CG_BLACK
                                          //  Referenced by:
                                          //    '<S292>/MATLAB Function5'
                                          //    '<S295>/MATLAB Function'

  real_T thruster_dist2CG_BLUE[8];     // Variable: thruster_dist2CG_BLUE
                                          //  Referenced by:
                                          //    '<S304>/MATLAB Function5'
                                          //    '<S307>/MATLAB Function'

  real_T thruster_dist2CG_RED[8];      // Variable: thruster_dist2CG_RED
                                          //  Referenced by:
                                          //    '<S316>/MATLAB Function5'
                                          //    '<S319>/MATLAB Function'

  real_T x_BLACK_0[6];                 // Variable: x_BLACK_0
                                          //  Referenced by:
                                          //    '<S35>/Constant'
                                          //    '<S35>/Constant1'
                                          //    '<S43>/Constant'
                                          //    '<S43>/Constant1'
                                          //    '<S47>/Constant'
                                          //    '<S47>/Constant1'

  real_T x_BLUE_0[6];                  // Variable: x_BLUE_0
                                          //  Referenced by:
                                          //    '<S36>/Constant'
                                          //    '<S36>/Constant1'

  real_T z_0[135];                     // Variable: z_0
                                          //  Referenced by:
                                          //    '<Root>/Universal_Time21'
                                          //    '<Root>/Universal_Time38'

  real_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S171>/UD'

  real_T DiscreteDerivative1_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative1_ICPrevScale
                                 //  Referenced by: '<S172>/UD'

  real_T DiscreteDerivative2_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative2_ICPrevScale
                                 //  Referenced by: '<S173>/UD'

  real_T DiscreteDerivative_ICPrevScal_i;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_i
                                 //  Referenced by: '<S148>/UD'

  real_T DiscreteDerivative1_ICPrevSca_e;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_e
                                 //  Referenced by: '<S149>/UD'

  real_T DiscreteDerivative2_ICPrevSca_o;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_o
                                 //  Referenced by: '<S150>/UD'

  real_T DiscreteDerivative_ICPrevScal_p;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_p
                                 //  Referenced by: '<S166>/UD'

  real_T DiscreteDerivative1_ICPrevSca_l;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_l
                                 //  Referenced by: '<S167>/UD'

  real_T DiscreteDerivative2_ICPrevSc_on;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSc_on
                                 //  Referenced by: '<S168>/UD'

  real_T DiscreteDerivative_ICPrevScal_n;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_n
                                 //  Referenced by: '<S143>/UD'

  real_T DiscreteDerivative1_ICPrevSca_f;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_f
                                 //  Referenced by: '<S144>/UD'

  real_T DiscreteDerivative2_ICPrevSca_g;
                              // Mask Parameter: DiscreteDerivative2_ICPrevSca_g
                                 //  Referenced by: '<S145>/UD'

  real_T DiscreteDerivative1_ICPrevSca_j;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_j
                                 //  Referenced by: '<S157>/UD'

  real_T DiscreteDerivative1_ICPrevSca_a;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_a
                                 //  Referenced by: '<S158>/UD'

  real_T DiscreteDerivative1_ICPrevSca_k;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_k
                                 //  Referenced by: '<S159>/UD'

  real_T MATLABFunction5_max_iters; // Mask Parameter: MATLABFunction5_max_iters
                                       //  Referenced by: '<S292>/MATLAB Function5'

  real_T MATLABFunction5_max_iters_l;
                                  // Mask Parameter: MATLABFunction5_max_iters_l
                                     //  Referenced by: '<S304>/MATLAB Function5'

  real_T MATLABFunction5_max_iters_o;
                                  // Mask Parameter: MATLABFunction5_max_iters_o
                                     //  Referenced by: '<S316>/MATLAB Function5'

  real_T MATLABFunction5_tol;          // Mask Parameter: MATLABFunction5_tol
                                          //  Referenced by: '<S292>/MATLAB Function5'

  real_T MATLABFunction5_tol_i;        // Mask Parameter: MATLABFunction5_tol_i
                                          //  Referenced by: '<S304>/MATLAB Function5'

  real_T MATLABFunction5_tol_j;        // Mask Parameter: MATLABFunction5_tol_j
                                          //  Referenced by: '<S316>/MATLAB Function5'

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

  real_T PuckState1_Value;             // Expression: 0
                                          //  Referenced by: '<S22>/Puck State1'

  real_T Constant3_Value;              // Expression: pi/2
                                          //  Referenced by: '<S27>/Constant3'

  real_T Constant1_Value;              // Expression: pi/2
                                          //  Referenced by: '<S27>/Constant1'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S27>/Constant2'

  real_T Constant_Value[3];            // Expression: [0 0 0]
                                          //  Referenced by: '<S31>/Constant'

  real_T Constant1_Value_d[3];         // Expression: [0 0 0]
                                          //  Referenced by: '<S31>/Constant1'

  real_T Constant11_Value_h;           // Expression: 0
                                          //  Referenced by: '<S31>/Constant11'

  real_T Constant12_Value_i;           // Expression: 0
                                          //  Referenced by: '<S31>/Constant12'

  real_T Constant14_Value_k;           // Expression: 0
                                          //  Referenced by: '<S31>/Constant14'

  real_T Constant15_Value_h;           // Expression: 0
                                          //  Referenced by: '<S31>/Constant15'

  real_T Constant18_Value_g;           // Expression: 0
                                          //  Referenced by: '<S31>/Constant18'

  real_T Constant4_Value_c;            // Expression: 2
                                          //  Referenced by: '<S31>/Constant4'

  real_T Constant5_Value_i;            // Expression: 3
                                          //  Referenced by: '<S31>/Constant5'

  real_T Constant6_Value_j;            // Expression: 1
                                          //  Referenced by: '<S31>/Constant6'

  real_T Constant8_Value_k;            // Expression: 2
                                          //  Referenced by: '<S31>/Constant8'

  real_T PuckState1_Value_o;           // Expression: 1
                                          //  Referenced by: '<S31>/Puck State1'

  real_T Constant_Value_p[3];          // Expression: [0 0 0]
                                          //  Referenced by: '<S32>/Constant'

  real_T Constant1_Value_k[3];         // Expression: [0 0 0]
                                          //  Referenced by: '<S32>/Constant1'

  real_T Constant11_Value_i;           // Expression: 0
                                          //  Referenced by: '<S32>/Constant11'

  real_T Constant12_Value_e;           // Expression: 0
                                          //  Referenced by: '<S32>/Constant12'

  real_T Constant14_Value_p;           // Expression: 0
                                          //  Referenced by: '<S32>/Constant14'

  real_T Constant15_Value_n;           // Expression: 0
                                          //  Referenced by: '<S32>/Constant15'

  real_T Constant18_Value_n;           // Expression: 0
                                          //  Referenced by: '<S32>/Constant18'

  real_T Constant2_Value_c[3];         // Expression: [0 0 0]
                                          //  Referenced by: '<S32>/Constant2'

  real_T Constant4_Value_c2;           // Expression: 0
                                          //  Referenced by: '<S32>/Constant4'

  real_T Constant5_Value_l;            // Expression: 3
                                          //  Referenced by: '<S32>/Constant5'

  real_T Constant6_Value_l;            // Expression: 1
                                          //  Referenced by: '<S32>/Constant6'

  real_T Constant8_Value_b;            // Expression: 0
                                          //  Referenced by: '<S32>/Constant8'

  real_T PuckState1_Value_m;           // Expression: 1
                                          //  Referenced by: '<S32>/Puck State1'

  real_T Constant_Value_i[3];          // Expression: [0 0 0]
                                          //  Referenced by: '<S33>/Constant'

  real_T Constant1_Value_i[3];         // Expression: [0 0 0]
                                          //  Referenced by: '<S33>/Constant1'

  real_T Constant11_Value_b;           // Expression: 0
                                          //  Referenced by: '<S33>/Constant11'

  real_T Constant12_Value_h;           // Expression: 0
                                          //  Referenced by: '<S33>/Constant12'

  real_T Constant14_Value_n;           // Expression: 0
                                          //  Referenced by: '<S33>/Constant14'

  real_T Constant15_Value_d;           // Expression: 0
                                          //  Referenced by: '<S33>/Constant15'

  real_T Constant18_Value_i;           // Expression: 0
                                          //  Referenced by: '<S33>/Constant18'

  real_T Constant2_Value_g[3];         // Expression: [0 0 0]
                                          //  Referenced by: '<S33>/Constant2'

  real_T Constant4_Value_k;            // Expression: 0
                                          //  Referenced by: '<S33>/Constant4'

  real_T Constant5_Value_h;            // Expression: 3
                                          //  Referenced by: '<S33>/Constant5'

  real_T Constant6_Value_d;            // Expression: 1
                                          //  Referenced by: '<S33>/Constant6'

  real_T Constant8_Value_p;            // Expression: 0
                                          //  Referenced by: '<S33>/Constant8'

  real_T PuckState1_Value_k;           // Expression: 1
                                          //  Referenced by: '<S33>/Puck State1'

  real_T Constant_Value_h[3];          // Expression: [0 0 0]
                                          //  Referenced by: '<S34>/Constant'

  real_T Constant1_Value_ip[3];        // Expression: [0 0 0]
                                          //  Referenced by: '<S34>/Constant1'

  real_T Constant11_Value_p;           // Expression: 0
                                          //  Referenced by: '<S34>/Constant11'

  real_T Constant12_Value_eu;          // Expression: 0
                                          //  Referenced by: '<S34>/Constant12'

  real_T Constant14_Value_i;           // Expression: 0
                                          //  Referenced by: '<S34>/Constant14'

  real_T Constant15_Value_f;           // Expression: 0
                                          //  Referenced by: '<S34>/Constant15'

  real_T Constant18_Value_p;           // Expression: 0
                                          //  Referenced by: '<S34>/Constant18'

  real_T Constant2_Value_cp[3];        // Expression: [0 0 0]
                                          //  Referenced by: '<S34>/Constant2'

  real_T Constant4_Value_a;            // Expression: 1
                                          //  Referenced by: '<S34>/Constant4'

  real_T Constant5_Value_j;            // Expression: 1
                                          //  Referenced by: '<S34>/Constant5'

  real_T Constant6_Value_o;            // Expression: 1
                                          //  Referenced by: '<S34>/Constant6'

  real_T Constant8_Value_a;            // Expression: 0
                                          //  Referenced by: '<S34>/Constant8'

  real_T PuckState1_Value_i;           // Expression: 0
                                          //  Referenced by: '<S34>/Puck State1'

  real_T udegpersec_Gain;              // Expression: 4*pi/180
                                          //  Referenced by: '<S51>/4 deg per sec'

  real_T Constant1_Value_n;            // Expression: 0
                                          //  Referenced by: '<S26>/Constant1'

  real_T Constant2_Value_a;            // Expression: 0
                                          //  Referenced by: '<S26>/Constant2'

  real_T Constant3_Value_d;            // Expression: 0
                                          //  Referenced by: '<S26>/Constant3'

  real_T Constant4_Value_k3;           // Expression: 0
                                          //  Referenced by: '<S26>/Constant4'

  real_T Constant5_Value_p;            // Expression: 0
                                          //  Referenced by: '<S26>/Constant5'

  real_T Constant6_Value_do;           // Expression: 0
                                          //  Referenced by: '<S26>/Constant6'

  real_T Constant7_Value;              // Expression: 0
                                          //  Referenced by: '<S26>/Constant7'

  real_T Constant8_Value_h;            // Expression: 0
                                          //  Referenced by: '<S26>/Constant8'

  real_T PuckState1_Value_h;           // Expression: 0
                                          //  Referenced by: '<S26>/Puck State1'

  real_T PuckState_Value;              // Expression: 0
                                          //  Referenced by: '<S26>/Puck State'

  real_T AngularGain_Value;            // Expression: 200
                                          //  Referenced by: '<S68>/Angular Gain'

  real_T AttractiveGain_Value;         // Expression: 200
                                          //  Referenced by: '<S68>/Attractive Gain'

  real_T InfluenceRange_Value;         // Expression: 1
                                          //  Referenced by: '<S68>/Influence Range'

  real_T RepulsiveGain_Value;          // Expression: 5
                                          //  Referenced by: '<S68>/Repulsive Gain'

  real_T AngularGain_Value_l;          // Expression: 200
                                          //  Referenced by: '<S67>/Angular Gain'

  real_T AttractiveGain_Value_i;       // Expression: 200
                                          //  Referenced by: '<S67>/Attractive Gain'

  real_T InfluenceRange_Value_d;       // Expression: 1
                                          //  Referenced by: '<S67>/Influence Range'

  real_T RepulsiveGain_Value_k;        // Expression: 5
                                          //  Referenced by: '<S67>/Repulsive Gain'

  real_T Delay1_InitialCondition[13];  // Expression: [1;zeros(12,1)]
                                          //  Referenced by: '<S97>/Delay1'

  real_T Delay1_InitialCondition_j[9]; // Expression: zeros(9,1)
                                          //  Referenced by: '<S98>/Delay1'

  real_T Delay2_InitialCondition[9];   // Expression: eye(3)
                                          //  Referenced by: '<S98>/Delay2'

  real_T Delay1_InitialCondition_g[13];// Expression: [1;zeros(12,1)]
                                          //  Referenced by: '<S101>/Delay1'

  real_T Delay2_InitialCondition_m[36];// Expression: zeros(6)
                                          //  Referenced by: '<S101>/Delay2'

  real_T Delay1_InitialCondition_e[9]; // Expression: zeros(9,1)
                                          //  Referenced by: '<S102>/Delay1'

  real_T Delay4_InitialCondition[9];   // Expression: eye(3)
                                          //  Referenced by: '<S102>/Delay4'

  real_T Delay3_InitialCondition[36];  // Expression: zeros(6)
                                          //  Referenced by: '<S102>/Delay3'

  real_T TSamp_WtEt;                   // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S171>/TSamp'

  real_T TSamp_WtEt_l;                 // Computed Parameter: TSamp_WtEt_l
                                          //  Referenced by: '<S172>/TSamp'

  real_T TSamp_WtEt_n;                 // Computed Parameter: TSamp_WtEt_n
                                          //  Referenced by: '<S173>/TSamp'

  real_T TSamp_WtEt_h;                 // Computed Parameter: TSamp_WtEt_h
                                          //  Referenced by: '<S148>/TSamp'

  real_T TSamp_WtEt_e;                 // Computed Parameter: TSamp_WtEt_e
                                          //  Referenced by: '<S149>/TSamp'

  real_T TSamp_WtEt_n3;                // Computed Parameter: TSamp_WtEt_n3
                                          //  Referenced by: '<S150>/TSamp'

  real_T Zero_Value;                   // Expression: 0
                                          //  Referenced by: '<S133>/Zero'

  real_T TSamp_WtEt_p;                 // Computed Parameter: TSamp_WtEt_p
                                          //  Referenced by: '<S166>/TSamp'

  real_T TSamp_WtEt_o;                 // Computed Parameter: TSamp_WtEt_o
                                          //  Referenced by: '<S167>/TSamp'

  real_T TSamp_WtEt_px;                // Computed Parameter: TSamp_WtEt_px
                                          //  Referenced by: '<S168>/TSamp'

  real_T Gain6_Gain;                   // Expression: -1
                                          //  Referenced by: '<S130>/Gain6'

  real_T Gain7_Gain;                   // Expression: -1
                                          //  Referenced by: '<S130>/Gain7'

  real_T Gain8_Gain;                   // Expression: -1
                                          //  Referenced by: '<S130>/Gain8'

  real_T TSamp_WtEt_f;                 // Computed Parameter: TSamp_WtEt_f
                                          //  Referenced by: '<S143>/TSamp'

  real_T TSamp_WtEt_eh;                // Computed Parameter: TSamp_WtEt_eh
                                          //  Referenced by: '<S144>/TSamp'

  real_T TSamp_WtEt_i;                 // Computed Parameter: TSamp_WtEt_i
                                          //  Referenced by: '<S145>/TSamp'

  real_T Zero_Value_j;                 // Expression: 0
                                          //  Referenced by: '<S134>/Zero'

  real_T TSamp_WtEt_pu;                // Computed Parameter: TSamp_WtEt_pu
                                          //  Referenced by: '<S157>/TSamp'

  real_T TSamp_WtEt_f0;                // Computed Parameter: TSamp_WtEt_f0
                                          //  Referenced by: '<S158>/TSamp'

  real_T TSamp_WtEt_nz;                // Computed Parameter: TSamp_WtEt_nz
                                          //  Referenced by: '<S159>/TSamp'

  real_T Constant7_Value_a;            // Expression: 1
                                          //  Referenced by: '<S128>/Constant7'

  real_T Merge3_InitialOutput;       // Computed Parameter: Merge3_InitialOutput
                                        //  Referenced by: '<S128>/Merge3'

  real_T Merge4_InitialOutput;       // Computed Parameter: Merge4_InitialOutput
                                        //  Referenced by: '<S128>/Merge4'

  real_T Merge5_InitialOutput;       // Computed Parameter: Merge5_InitialOutput
                                        //  Referenced by: '<S128>/Merge5'

  real_T Constant7_Value_h;            // Expression: 0
                                          //  Referenced by: '<S132>/Constant7'

  real_T Zero_Value_m;                 // Expression: 0
                                          //  Referenced by: '<S132>/Zero'

  real_T GPIOWrite1_gpioPin;           // Expression: 428
                                          //  Referenced by: '<S218>/GPIO Write1'

  real_T GPIOWrite1_pinDirection;      // Expression: 1
                                          //  Referenced by: '<S218>/GPIO Write1'

  real_T GyroscopeAccelerometer_SampleTi;// Expression: -1
                                            //  Referenced by: '<S219>/Gyroscope//Accelerometer'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S221>/Delay'

  real_T Delay1_InitialCondition_l;    // Expression: 0.0
                                          //  Referenced by: '<S221>/Delay1'

  real_T Delay2_InitialCondition_j;    // Expression: 0.0
                                          //  Referenced by: '<S221>/Delay2'

  real_T Out1_Y0;                      // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S230>/Out1'

  real_T Memory_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S230>/Memory'

  real_T Out1_Y0_i;                    // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S231>/Out1'

  real_T dytdt_Y0;                     // Computed Parameter: dytdt_Y0
                                          //  Referenced by: '<S237>/dy(t)//dt'

  real_T dytdt_Y0_j;                   // Computed Parameter: dytdt_Y0_j
                                          //  Referenced by: '<S247>/dy(t)//dt'

  real_T dytdt_Y0_d;                   // Computed Parameter: dytdt_Y0_d
                                          //  Referenced by: '<S257>/dy(t)//dt'

  real_T ConvertBLAXfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S225>/Convert BLAX from [mm] to [m]'

  real_T ConvertBLAYfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S225>/Convert BLAY from [mm] to [m]'

  real_T ConvertBLACKVXfrommmtom_Gain; // Expression: 1/1000
                                          //  Referenced by: '<S225>/Convert BLACKVX from [mm] to [m]'

  real_T ConvertBLACKVYfrommmtom_Gain; // Expression: 1/1000
                                          //  Referenced by: '<S225>/Convert BLACKVY from [mm] to [m]'

  real_T Delay2_InitialCondition_e;    // Expression: 0
                                          //  Referenced by: '<S233>/Delay2'

  real_T Delay1_InitialCondition_m;    // Expression: 0
                                          //  Referenced by: '<S233>/Delay1'

  real_T Constant3_Value_e;            // Expression: 0
                                          //  Referenced by: '<S233>/Constant3'

  real_T Delay1_InitialCondition_i;    // Expression: 0.0
                                          //  Referenced by: '<S235>/Delay1'

  real_T Constant3_Value_a;            // Expression: 0
                                          //  Referenced by: '<S235>/Constant3'

  real_T Delay1_InitialCondition_it;   // Expression: 0.0
                                          //  Referenced by: '<S234>/Delay1'

  real_T Constant3_Value_d4;           // Expression: 0
                                          //  Referenced by: '<S234>/Constant3'

  real_T ConvertBLUXfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S226>/Convert BLUX from [mm] to [m]'

  real_T ConvertBLUYfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S226>/Convert BLUY from [mm] to [m]'

  real_T ConvertBLUEVXfrommmtom_Gain;  // Expression: 1/1000
                                          //  Referenced by: '<S226>/Convert BLUEVX from [mm] to [m]'

  real_T ConvertBLUEVYfrommmtom_Gain;  // Expression: 1/1000
                                          //  Referenced by: '<S226>/Convert BLUEVY from [mm] to [m]'

  real_T Delay2_InitialCondition_a;    // Expression: 0
                                          //  Referenced by: '<S243>/Delay2'

  real_T Delay1_InitialCondition_i3;   // Expression: 0
                                          //  Referenced by: '<S243>/Delay1'

  real_T Constant3_Value_o;            // Expression: 0
                                          //  Referenced by: '<S243>/Constant3'

  real_T Delay1_InitialCondition_h;    // Expression: 0.0
                                          //  Referenced by: '<S245>/Delay1'

  real_T Constant3_Value_c;            // Expression: 0
                                          //  Referenced by: '<S245>/Constant3'

  real_T Delay1_InitialCondition_ja;   // Expression: 0.0
                                          //  Referenced by: '<S244>/Delay1'

  real_T Constant3_Value_k;            // Expression: 0
                                          //  Referenced by: '<S244>/Constant3'

  real_T ConvertREDXfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S227>/Convert REDX from [mm] to [m]'

  real_T ConvertREDYfrommmtom_Gain;    // Expression: 1/1000
                                          //  Referenced by: '<S227>/Convert REDY from [mm] to [m]'

  real_T ConvertREDVXfrommmtom_Gain;   // Expression: 1/1000
                                          //  Referenced by: '<S227>/Convert REDVX from [mm] to [m]'

  real_T ConvertREDVYfrommmtom_Gain;   // Expression: 1/1000
                                          //  Referenced by: '<S227>/Convert REDVY from [mm] to [m]'

  real_T Delay2_InitialCondition_mu;   // Expression: 0
                                          //  Referenced by: '<S253>/Delay2'

  real_T Delay1_InitialCondition_lm;   // Expression: 0
                                          //  Referenced by: '<S253>/Delay1'

  real_T Constant3_Value_f;            // Expression: 0
                                          //  Referenced by: '<S253>/Constant3'

  real_T Delay1_InitialCondition_k;    // Expression: 0.0
                                          //  Referenced by: '<S255>/Delay1'

  real_T Constant3_Value_dh;           // Expression: 0
                                          //  Referenced by: '<S255>/Constant3'

  real_T Delay1_InitialCondition_c;    // Expression: 0.0
                                          //  Referenced by: '<S254>/Delay1'

  real_T Constant3_Value_dz;           // Expression: 0
                                          //  Referenced by: '<S254>/Constant3'

  real_T Constant_Value_e;             // Expression: 1
                                          //  Referenced by: '<S228>/Constant'

  real_T Constant_Value_o;             // Expression: 0
                                          //  Referenced by: '<S279>/Constant'

  real_T Delay2_InitialCondition_l;    // Expression: 0
                                          //  Referenced by: '<S279>/Delay2'

  real_T Delay_InitialCondition_p[3];  // Expression: [0;0;0]
                                          //  Referenced by: '<S279>/Delay'

  real_T Delay1_InitialCondition_kb;   // Expression: 0
                                          //  Referenced by: '<S279>/Delay1'

  real_T ControlDynamixelActuatorsineith;// Expression: 400
                                            //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_b;// Expression: 0
                                            //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_h;// Expression: 200
                                            //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_j;// Expression: 3072
                                            //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_m;// Expression: 1024
                                            //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsine_hy;// Expression: 0
                                            //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_i;// Expression: 850
                                            //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_g;// Expression: 400
                                            //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsine_g3;// Expression: 100
                                            //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsine_bf;// Expression: 50
                                            //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T ControlDynamixelActuatorsinei_l;// Expression: 0
                                            //  Referenced by: '<S287>/Control Dynamixel Actuators in  either Position, Current, or Speed  Control Modes'

  real_T Out1_Y0_c;                    // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S299>/Out1'

  real_T Out1_Y0_a;                    // Computed Parameter: Out1_Y0_a
                                          //  Referenced by: '<S300>/Out1'

  real_T BLACKDC_Y0;                   // Computed Parameter: BLACKDC_Y0
                                          //  Referenced by: '<S289>/BLACK DC'

  real_T Delay_InitialCondition_e;     // Expression: 0.0
                                          //  Referenced by: '<S294>/Delay'

  real_T Constant2_Value_o;            // Expression: 0
                                          //  Referenced by: '<S294>/Constant2'

  real_T Out1_Y0_n;                    // Computed Parameter: Out1_Y0_n
                                          //  Referenced by: '<S311>/Out1'

  real_T Out1_Y0_l;                    // Computed Parameter: Out1_Y0_l
                                          //  Referenced by: '<S312>/Out1'

  real_T BLUEDC_Y0;                    // Computed Parameter: BLUEDC_Y0
                                          //  Referenced by: '<S290>/BLUE DC'

  real_T Delay_InitialCondition_l;     // Expression: 0.0
                                          //  Referenced by: '<S306>/Delay'

  real_T Constant2_Value_ab;           // Expression: 0
                                          //  Referenced by: '<S306>/Constant2'

  real_T Out1_Y0_o;                    // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S323>/Out1'

  real_T Out1_Y0_d;                    // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S324>/Out1'

  real_T REDDC_Y0;                     // Computed Parameter: REDDC_Y0
                                          //  Referenced by: '<S291>/RED DC'

  real_T Delay_InitialCondition_i;     // Expression: 0.0
                                          //  Referenced by: '<S318>/Delay'

  real_T Constant2_Value_h;            // Expression: 0
                                          //  Referenced by: '<S318>/Constant2'

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

  real_T Delay_InitialCondition_g;     // Expression: 0.0
                                          //  Referenced by: '<S19>/Delay'

  real_T Merge2_InitialOutput;       // Computed Parameter: Merge2_InitialOutput
                                        //  Referenced by: '<S4>/Merge2'

  real_T Delay2_InitialCondition_eh;   // Expression: 0.0
                                          //  Referenced by: '<S276>/Delay2'

  real_T Delay1_InitialCondition_eh[6];// Expression: [init_states_BLACK';0;0;0]
                                          //  Referenced by: '<S268>/Delay1'

  real_T Delay_InitialCondition_h[36]; // Expression: 0.002*eye(6)
                                          //  Referenced by: '<S268>/Delay'

  real_T Delay2_InitialCondition_jw[9];// Expression: 0*eye(3)
                                          //  Referenced by: '<S268>/Delay2'

  real_T Delay2_InitialCondition_p;    // Expression: 0.0
                                          //  Referenced by: '<S270>/Delay2'

  real_T Delay1_InitialCondition_n[6]; // Expression: [init_states_BLACK';0;0;0]
                                          //  Referenced by: '<S266>/Delay1'

  real_T Delay_InitialCondition_f[36]; // Expression: 0.002*eye(6)
                                          //  Referenced by: '<S266>/Delay'

  real_T Delay2_InitialCondition_ji[9];// Expression: 0*eye(3)
                                          //  Referenced by: '<S266>/Delay2'

  real_T Delay2_InitialCondition_jn;   // Expression: 0.0
                                          //  Referenced by: '<S273>/Delay2'

  real_T Delay1_InitialCondition_cb[6];// Expression: [init_states_BLACK';0;0;0]
                                          //  Referenced by: '<S267>/Delay1'

  real_T Delay_InitialCondition_ga[36];// Expression: 0.002*eye(6)
                                          //  Referenced by: '<S267>/Delay'

  real_T Delay2_InitialCondition_c[9]; // Expression: 0*eye(3)
                                          //  Referenced by: '<S267>/Delay2'

  real_T SafetyNumber_Value;           // Expression: 568471
                                          //  Referenced by: '<S18>/Safety Number'

  real_T Gain_Gain;                    // Expression: 100
                                          //  Referenced by: '<S18>/Gain'

  real_T Gain1_Gain;                   // Expression: 100
                                          //  Referenced by: '<S18>/Gain1'

  real_T Gain2_Gain;                   // Expression: 100
                                          //  Referenced by: '<S18>/Gain2'

  real_T Gain3_Gain;                   // Expression: 100
                                          //  Referenced by: '<S18>/Gain3'

  real_T Gain4_Gain;                   // Expression: 100
                                          //  Referenced by: '<S18>/Gain4'

  real_T Gain5_Gain;                   // Expression: 100
                                          //  Referenced by: '<S18>/Gain5'

  real_T Gain6_Gain_m;                 // Expression: 100
                                          //  Referenced by: '<S18>/Gain6'

  real_T Gain7_Gain_n;                 // Expression: 100
                                          //  Referenced by: '<S18>/Gain7'

  real_T DataStoreMemory_InitialValue[8];
                                     // Expression: [[1; 0; 0; 0], [0; 0; 0; 0]]
                                        //  Referenced by: '<Root>/Data Store Memory'

  real_T DataStoreMemory1_InitialValue[4];// Expression: [1;0;0;0]
                                             //  Referenced by: '<Root>/Data Store Memory1'

  real_T DataStoreMemory10_InitialValue[3];// Expression: zeros(3,1)
                                              //  Referenced by: '<Root>/Data Store Memory10'

  real_T DataStoreMemory11_InitialValue[3];// Expression: zeros(3,1)
                                              //  Referenced by: '<Root>/Data Store Memory11'

  real_T DataStoreMemory12_InitialValue[8];
                                     // Expression: [[1; 0; 0; 0], [0; 0; 0; 0]]
                                        //  Referenced by: '<Root>/Data Store Memory12'

  real_T DataStoreMemory13_InitialValue[4];// Expression: [1;0;0;0]
                                              //  Referenced by: '<Root>/Data Store Memory13'

  real_T DataStoreMemory14_InitialValue[9];// Expression: eye(3)
                                              //  Referenced by: '<Root>/Data Store Memory14'

  real_T DataStoreMemory15_InitialValue[3];// Expression: zeros(3,1)
                                              //  Referenced by: '<Root>/Data Store Memory15'

  real_T DataStoreMemory16_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory16'

  real_T DataStoreMemory17_InitialValue[13];// Expression: [1;zeros(12,1)]
                                               //  Referenced by: '<Root>/Data Store Memory17'

  real_T DataStoreMemory18_InitialValue[144];// Expression: zeros(12)
                                                //  Referenced by: '<Root>/Data Store Memory18'

  real_T DataStoreMemory19_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory19'

  real_T DataStoreMemory2_InitialValue[9];// Expression: eye(3)
                                             //  Referenced by: '<Root>/Data Store Memory2'

  real_T DataStoreMemory20_InitialValue[13];// Expression: [1;zeros(12,1)]
                                               //  Referenced by: '<Root>/Data Store Memory20'

  real_T DataStoreMemory21_InitialValue[144];// Expression: zeros(12)
                                                //  Referenced by: '<Root>/Data Store Memory21'

  real_T DataStoreMemory22_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory22'

  real_T DataStoreMemory23_InitialValue[13];// Expression: [1;zeros(12,1)]
                                               //  Referenced by: '<Root>/Data Store Memory23'

  real_T DataStoreMemory24_InitialValue[144];// Expression: zeros(12)
                                                //  Referenced by: '<Root>/Data Store Memory24'

  real_T DataStoreMemory25_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory25'

  real_T DataStoreMemory26_InitialValue[13];// Expression: [1;zeros(12,1)]
                                               //  Referenced by: '<Root>/Data Store Memory26'

  real_T DataStoreMemory27_InitialValue[144];// Expression: zeros(12)
                                                //  Referenced by: '<Root>/Data Store Memory27'

  real_T DataStoreMemory28_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory28'

  real_T DataStoreMemory29_InitialValue[13];// Expression: [1;zeros(12,1)]
                                               //  Referenced by: '<Root>/Data Store Memory29'

  real_T DataStoreMemory3_InitialValue[3];// Expression: zeros(3,1)
                                             //  Referenced by: '<Root>/Data Store Memory3'

  real_T DataStoreMemory30_InitialValue[144];// Expression: zeros(12)
                                                //  Referenced by: '<Root>/Data Store Memory30'

  real_T DataStoreMemory31_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory31'

  real_T DataStoreMemory32_InitialValue[13];// Expression: [1;zeros(12,1)]
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

  real_T DataStoreMemory38_InitialValue[9];// Expression: eye(3)
                                              //  Referenced by: '<Root>/Data Store Memory38'

  real_T DataStoreMemory39_InitialValue[9];// Expression: eye(3)
                                              //  Referenced by: '<Root>/Data Store Memory39'

  real_T DataStoreMemory4_InitialValue[3];// Expression: zeros(3,1)
                                             //  Referenced by: '<Root>/Data Store Memory4'

  real_T DataStoreMemory40_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory40'

  real_T DataStoreMemory41_InitialValue[3];// Expression: zeros(3,1)
                                              //  Referenced by: '<Root>/Data Store Memory41'

  real_T DataStoreMemory42_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory42'

  real_T DataStoreMemory43_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory43'

  real_T DataStoreMemory44_InitialValue[8];
                                     // Expression: [[1; 0; 0; 0], [0; 0; 0; 0]]
                                        //  Referenced by: '<Root>/Data Store Memory44'

  real_T DataStoreMemory45_InitialValue[4];// Expression: [1;0;0;0]
                                              //  Referenced by: '<Root>/Data Store Memory45'

  real_T DataStoreMemory46_InitialValue[9];// Expression: eye(3)
                                              //  Referenced by: '<Root>/Data Store Memory46'

  real_T DataStoreMemory47_InitialValue[6];// Expression: zeros(6,1)
                                              //  Referenced by: '<Root>/Data Store Memory47'

  real_T DataStoreMemory48_InitialValue[6];// Expression: zeros(6,1)
                                              //  Referenced by: '<Root>/Data Store Memory48'

  real_T DataStoreMemory49_InitialValue[3];// Expression: zeros(3,1)
                                              //  Referenced by: '<Root>/Data Store Memory49'

  real_T DataStoreMemory5_InitialValue[3];// Expression: zeros(3,1)
                                             //  Referenced by: '<Root>/Data Store Memory5'

  real_T DataStoreMemory50_InitialValue[6];// Expression: zeros(6,1)
                                              //  Referenced by: '<Root>/Data Store Memory50'

  real_T DataStoreMemory51_InitialValue[6];// Expression: zeros(6,1)
                                              //  Referenced by: '<Root>/Data Store Memory51'

  real_T DataStoreMemory52_InitialValue[6];// Expression: zeros(6,1)
                                              //  Referenced by: '<Root>/Data Store Memory52'

  real_T DataStoreMemory53_InitialValue[6];// Expression: zeros(6,1)
                                              //  Referenced by: '<Root>/Data Store Memory53'

  real_T DataStoreMemory57_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory57'

  real_T DataStoreMemory58_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory58'

  real_T DataStoreMemory59_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory59'

  real_T DataStoreMemory6_InitialValue[8];
                                     // Expression: [[1; 0; 0; 0], [0; 0; 0; 0]]
                                        //  Referenced by: '<Root>/Data Store Memory6'

  real_T DataStoreMemory60_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory60'

  real_T DataStoreMemory61_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory61'

  real_T DataStoreMemory62_InitialValue;// Expression: 0
                                           //  Referenced by: '<Root>/Data Store Memory62'

  real_T DataStoreMemory63_InitialValue[7];// Expression: zeros(7,1)
                                              //  Referenced by: '<Root>/Data Store Memory63'

  real_T DataStoreMemory64_InitialValue[7];// Expression: zeros(7,1)
                                              //  Referenced by: '<Root>/Data Store Memory64'

  real_T DataStoreMemory7_InitialValue[4];// Expression: [1; 0; 0; 0]
                                             //  Referenced by: '<Root>/Data Store Memory7'

  real_T DataStoreMemory8_InitialValue[9];// Expression: eye(3)
                                             //  Referenced by: '<Root>/Data Store Memory8'

  real_T DataStoreMemory9_InitialValue[3];// Expression: zeros(3,1)
                                             //  Referenced by: '<Root>/Data Store Memory9'

  real_T RED_Tz1_InitialValue;         // Expression: 0
                                          //  Referenced by: '<Root>/RED_Tz1'

  real_T RED_Tz10_InitialValue[36];    // Expression: zeros(6*6,1)
                                          //  Referenced by: '<Root>/RED_Tz10'

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

  real_T RED_Tz6_InitialValue[6];      // Expression: [0;0;0;0;0;0]
                                          //  Referenced by: '<Root>/RED_Tz6'

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

  real_T Universal_Time22_InitialValue[6];// Expression: [0;0;0;0;0;0;]
                                             //  Referenced by: '<Root>/Universal_Time22'

  real_T Universal_Time23_InitialValue[3];// Expression: [0,0,0]
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

  real_T Universal_Time36_InitialValue[36];// Expression: zeros(6*6,1)
                                              //  Referenced by: '<Root>/Universal_Time36'

  real_T Universal_Time39_InitialValue[6];// Expression: [0;0;0;0;0;0]
                                             //  Referenced by: '<Root>/Universal_Time39'

  real_T Universal_Time4_InitialValue[9];// Expression: [0;0;0;0;0;0;0;0;0]
                                            //  Referenced by: '<Root>/Universal_Time4'

  real_T Universal_Time40_InitialValue[36];// Expression: zeros(6*6,1)
                                              //  Referenced by: '<Root>/Universal_Time40'

  real_T Universal_Time41_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time41'

  real_T Universal_Time42_InitialValue[9];
                                   // Expression: [init_states_RED';0;0;0;0;0;0]
                                      //  Referenced by: '<Root>/Universal_Time42'

  real_T Universal_Time43_InitialValue[9];
                                 // Expression: [init_states_BLACK';0;0;0;0;0;0]
                                    //  Referenced by: '<Root>/Universal_Time43'

  real_T Universal_Time44_InitialValue[9];
                                  // Expression: [init_states_BLUE';0;0;0;0;0;0]
                                     //  Referenced by: '<Root>/Universal_Time44'

  real_T Universal_Time45_InitialValue;// Expression: 0
                                          //  Referenced by: '<Root>/Universal_Time45'

  real_T Universal_Time46_InitialValue[6];// Expression: [0;0;0;0;0;0;]
                                             //  Referenced by: '<Root>/Universal_Time46'

  real_T Universal_Time5_InitialValue[3];// Expression: [0;0;0]
                                            //  Referenced by: '<Root>/Universal_Time5'

  real_T Universal_Time6_InitialValue[3];// Expression: [0;0;0]
                                            //  Referenced by: '<Root>/Universal_Time6'

  real_T Universal_Time8_InitialValue[3];// Expression: [0;0;0]
                                            //  Referenced by: '<Root>/Universal_Time8'

  real_T Universal_Time9_InitialValue[3];// Expression: [0 0 0]
                                            //  Referenced by: '<Root>/Universal_Time9'

  char_T StringConstant1_String[256];  // Expression: "Target: Hello"
                                          //  Referenced by: '<S215>/String Constant1'

  char_T StringConstant2_String[256];  // Expression: "Obstacle: Hello"
                                          //  Referenced by: '<S216>/String Constant2'

  char_T RED_Tz3_InitialValue[256];  // Computed Parameter: RED_Tz3_InitialValue
                                        //  Referenced by: '<Root>/RED_Tz3'

  int32_T UDPSend1_Port;               // Computed Parameter: UDPSend1_Port
                                          //  Referenced by: '<S215>/UDP Send1'

  int32_T UDPSend2_Port;               // Computed Parameter: UDPSend2_Port
                                          //  Referenced by: '<S216>/UDP Send2'

  int32_T UDPSend3_Port;               // Computed Parameter: UDPSend3_Port
                                          //  Referenced by: '<S217>/UDP Send3'

  int32_T ReceivePhaseSpaceData_Port;
                               // Computed Parameter: ReceivePhaseSpaceData_Port
                                  //  Referenced by: '<S224>/Receive PhaseSpace Data'

  int32_T Delay_InitialCondition_j;
                                 // Computed Parameter: Delay_InitialCondition_j
                                    //  Referenced by: '<S229>/Delay'

  int32_T Delay1_InitialCondition_d;
                                // Computed Parameter: Delay1_InitialCondition_d
                                   //  Referenced by: '<S229>/Delay1'

  int32_T Delay2_InitialCondition_ak;
                               // Computed Parameter: Delay2_InitialCondition_ak
                                  //  Referenced by: '<S229>/Delay2'

  int32_T UDPReceive_Port;             // Computed Parameter: UDPReceive_Port
                                          //  Referenced by: '<S229>/UDP Receive'

  int32_T UDPReceive2_Port;            // Computed Parameter: UDPReceive2_Port
                                          //  Referenced by: '<S229>/UDP Receive2'

  int32_T UDPReceive3_Port;            // Computed Parameter: UDPReceive3_Port
                                          //  Referenced by: '<S229>/UDP Receive3'

  int32_T UDPReceive1_Port;            // Computed Parameter: UDPReceive1_Port
                                          //  Referenced by: '<S279>/UDP Receive1'

  int32_T UDPSend_Port;                // Computed Parameter: UDPSend_Port
                                          //  Referenced by: '<S288>/UDP Send'

  int32_T UDPSend_Port_g;              // Computed Parameter: UDPSend_Port_g
                                          //  Referenced by: '<S18>/UDP Send'

  P_EnabledSubsystem_MPC_d_T EnabledSubsystem_a;// '<S255>/Enabled Subsystem'
  P_EnabledSubsystem_MPC_T EnabledSubsystem_k;// '<S254>/Enabled Subsystem'
  P_EnabledSubsystem_MPC_d_T EnabledSubsystem_g;// '<S245>/Enabled Subsystem'
  P_EnabledSubsystem_MPC_T EnabledSubsystem_l;// '<S244>/Enabled Subsystem'
  P_EnabledSubsystem_MPC_d_T EnabledSubsystem_n;// '<S235>/Enabled Subsystem'
  P_EnabledSubsystem_MPC_T EnabledSubsystem_m;// '<S234>/Enabled Subsystem'
  P_ChangeBLACKBehavior_MPC_T ChangeREDBehavior;// '<S5>/Change RED Behavior'
  P_ChangeBLACKBehavior_MPC_T ChangeBLUEBehavior;// '<S5>/Change BLUE Behavior'
  P_ChangeBLACKBehavior_MPC_T ChangeBLACKBehavior;// '<S5>/Change BLACK Behavior' 
  P_DisableThrustersRED_MPC_T CustomControlARM;// '<S4>/Custom Control (ARM)'
  P_DefaultPDControlBLACK_MPC_T DefaultLQRControlBLACK;// '<S4>/Default LQR Control (BLACK)' 
  P_DefaultPDControlBLACK_MPC_T DefaultPDControlBLACK;// '<S4>/Default PD Control (BLACK)' 
  P_DisableThrustersRED_MPC_T DisableThrustersRED;// '<S4>/Disable Thrusters (RED)' 
  P_Phase4ReturnHome_MPC_T Phase5HoldHome;// '<S1>/Phase #5: Hold Home'
  P_Phase4ReturnHome_MPC_T Phase4ReturnHome;// '<S1>/Phase #4: Return Home'
  P_Phase0Synchronization_MPC_T Phase1StartFloating;// '<S1>/Phase #1: Start Floating ' 
  P_Phase0Synchronization_MPC_T Phase0Synchronization;// '<S1>/Phase #0: Synchronization' 
};

// Real-time Model Data Structure
struct tag_RTM_MPC_T {
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

  extern P_MPC_T MPC_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_MPC_T MPC_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_MPC_T MPC_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void MPC_initialize(void);
  extern void MPC_step(void);
  extern void MPC_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_MPC_T *const MPC_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S138>/Data Type Duplicate' : Unused code path elimination
//  Block '<S139>/Data Type Duplicate' : Unused code path elimination
//  Block '<S140>/Data Type Duplicate' : Unused code path elimination
//  Block '<S143>/Data Type Duplicate' : Unused code path elimination
//  Block '<S144>/Data Type Duplicate' : Unused code path elimination
//  Block '<S145>/Data Type Duplicate' : Unused code path elimination
//  Block '<S148>/Data Type Duplicate' : Unused code path elimination
//  Block '<S149>/Data Type Duplicate' : Unused code path elimination
//  Block '<S150>/Data Type Duplicate' : Unused code path elimination
//  Block '<S128>/Scope' : Unused code path elimination
//  Block '<S157>/Data Type Duplicate' : Unused code path elimination
//  Block '<S158>/Data Type Duplicate' : Unused code path elimination
//  Block '<S159>/Data Type Duplicate' : Unused code path elimination
//  Block '<S161>/Data Type Duplicate' : Unused code path elimination
//  Block '<S162>/Data Type Duplicate' : Unused code path elimination
//  Block '<S163>/Data Type Duplicate' : Unused code path elimination
//  Block '<S166>/Data Type Duplicate' : Unused code path elimination
//  Block '<S167>/Data Type Duplicate' : Unused code path elimination
//  Block '<S168>/Data Type Duplicate' : Unused code path elimination
//  Block '<S171>/Data Type Duplicate' : Unused code path elimination
//  Block '<S172>/Data Type Duplicate' : Unused code path elimination
//  Block '<S173>/Data Type Duplicate' : Unused code path elimination
//  Block '<Root>/If 'simMode' set to '1', then this is a simulation and the dynamics will be simulated. Otherwise, this is an experiment, and the simulation will not be run.' : Unused code path elimination
//  Block '<S263>/Data Type Duplicate' : Unused code path elimination
//  Block '<S263>/Diff' : Unused code path elimination
//  Block '<S263>/TSamp' : Unused code path elimination
//  Block '<S263>/UD' : Unused code path elimination
//  Block '<S264>/Data Type Duplicate' : Unused code path elimination
//  Block '<S264>/Diff' : Unused code path elimination
//  Block '<S264>/TSamp' : Unused code path elimination
//  Block '<S264>/UD' : Unused code path elimination
//  Block '<S265>/Data Type Duplicate' : Unused code path elimination
//  Block '<S265>/Diff' : Unused code path elimination
//  Block '<S265>/TSamp' : Unused code path elimination
//  Block '<S265>/UD' : Unused code path elimination
//  Block '<S80>/Reshape' : Reshape block reduction
//  Block '<S81>/Reshape1' : Reshape block reduction
//  Block '<S67>/Reshape' : Reshape block reduction
//  Block '<S67>/Reshape1' : Reshape block reduction
//  Block '<S85>/Reshape1' : Reshape block reduction
//  Block '<S86>/Reshape' : Reshape block reduction
//  Block '<S68>/Reshape' : Reshape block reduction
//  Block '<S68>/Reshape1' : Reshape block reduction
//  Block '<S6>/Reshape1' : Reshape block reduction
//  Block '<S6>/Reshape13' : Reshape block reduction
//  Block '<S6>/Reshape14' : Reshape block reduction
//  Block '<S6>/Reshape2' : Reshape block reduction
//  Block '<S6>/Reshape3' : Reshape block reduction
//  Block '<S6>/Reshape4' : Reshape block reduction
//  Block '<S6>/Reshape5' : Reshape block reduction
//  Block '<S6>/Reshape6' : Reshape block reduction
//  Block '<S6>/Reshape7' : Reshape block reduction
//  Block '<S6>/Reshape8' : Reshape block reduction
//  Block '<S180>/Reshape13' : Reshape block reduction
//  Block '<S181>/Reshape13' : Reshape block reduction
//  Block '<S182>/Reshape13' : Reshape block reduction
//  Block '<S183>/Reshape13' : Reshape block reduction
//  Block '<S184>/Reshape13' : Reshape block reduction
//  Block '<S185>/Reshape13' : Reshape block reduction
//  Block '<S186>/Reshape13' : Reshape block reduction
//  Block '<S187>/Reshape13' : Reshape block reduction
//  Block '<S188>/Reshape13' : Reshape block reduction
//  Block '<S189>/Reshape13' : Reshape block reduction
//  Block '<S190>/Reshape13' : Reshape block reduction
//  Block '<S191>/Reshape13' : Reshape block reduction
//  Block '<S192>/Reshape13' : Reshape block reduction
//  Block '<S193>/Reshape13' : Reshape block reduction
//  Block '<S194>/Reshape13' : Reshape block reduction
//  Block '<S195>/Reshape13' : Reshape block reduction
//  Block '<S196>/Reshape13' : Reshape block reduction
//  Block '<S215>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S216>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S217>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S224>/Reshape' : Reshape block reduction
//  Block '<S225>/Reshape' : Reshape block reduction
//  Block '<S226>/Reshape' : Reshape block reduction
//  Block '<S227>/Reshape' : Reshape block reduction
//  Block '<S266>/Reshape' : Reshape block reduction
//  Block '<S267>/Reshape' : Reshape block reduction
//  Block '<S268>/Reshape' : Reshape block reduction


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
//  '<Root>' : 'MPC'
//  '<S1>'   : 'MPC/1 - Experiment Logic'
//  '<S2>'   : 'MPC/2 - Guidance'
//  '<S3>'   : 'MPC/3 - Navigation'
//  '<S4>'   : 'MPC/4 - Control'
//  '<S5>'   : 'MPC/Check  Connection'
//  '<S6>'   : 'MPC/Data Logger Subsystem'
//  '<S7>'   : 'MPC/Debugger1'
//  '<S8>'   : 'MPC/Float Code'
//  '<S9>'   : 'MPC/Gyro.//Accel. Code'
//  '<S10>'  : 'MPC/Manipulator Encoder Data'
//  '<S11>'  : 'MPC/PhaseSpace Camera Code'
//  '<S12>'  : 'MPC/PhaseSpace Filter Code'
//  '<S13>'  : 'MPC/Platform  Identification'
//  '<S14>'  : 'MPC/Receive Data '
//  '<S15>'  : 'MPC/Robotic  Arm Code'
//  '<S16>'  : 'MPC/Send Data  to Orin'
//  '<S17>'  : 'MPC/Simulation  Status'
//  '<S18>'  : 'MPC/Thruster Control Code'
//  '<S19>'  : 'MPC/dt'
//  '<S20>'  : 'MPC/1 - Experiment Logic/Phase #0: Synchronization'
//  '<S21>'  : 'MPC/1 - Experiment Logic/Phase #1: Start Floating '
//  '<S22>'  : 'MPC/1 - Experiment Logic/Phase #2: Initial Position'
//  '<S23>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment'
//  '<S24>'  : 'MPC/1 - Experiment Logic/Phase #4: Return Home'
//  '<S25>'  : 'MPC/1 - Experiment Logic/Phase #5: Hold Home'
//  '<S26>'  : 'MPC/1 - Experiment Logic/Phase #6: Clean Shutdown'
//  '<S27>'  : 'MPC/1 - Experiment Logic/Phase #2: Initial Position/Desired Joint Angles RED'
//  '<S28>'  : 'MPC/1 - Experiment Logic/Phase #2: Initial Position/Desired Position BLACK'
//  '<S29>'  : 'MPC/1 - Experiment Logic/Phase #2: Initial Position/Desired Position BLUE'
//  '<S30>'  : 'MPC/1 - Experiment Logic/Phase #2: Initial Position/Desired Position RED'
//  '<S31>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1'
//  '<S32>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 '
//  '<S33>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 '
//  '<S34>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4'
//  '<S35>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLACK'
//  '<S36>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLUE'
//  '<S37>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLACK/Calculate Time since Phase #3 Start'
//  '<S38>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLACK/Wrap'
//  '<S39>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLACK/Calculate Time since Phase #3 Start/Subsystem'
//  '<S40>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLUE/Calculate Time since Phase #3 Start'
//  '<S41>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLUE/Wrap'
//  '<S42>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #1/Desired Position BLUE/Calculate Time since Phase #3 Start/Subsystem'
//  '<S43>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLACK'
//  '<S44>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLACK/Calculate Time since Phase #3 Start'
//  '<S45>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLACK/Wrap'
//  '<S46>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #2 /Desired Position BLACK/Calculate Time since Phase #3 Start/Subsystem'
//  '<S47>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position BLACK'
//  '<S48>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position BLACK/Calculate Time since Phase #3 Start'
//  '<S49>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position BLACK/Wrap'
//  '<S50>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #3 /Desired Position BLACK/Calculate Time since Phase #3 Start/Subsystem'
//  '<S51>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position BLACK'
//  '<S52>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position BLACK/Calculate Time since Phase #3 Start'
//  '<S53>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position BLACK/Wrap'
//  '<S54>'  : 'MPC/1 - Experiment Logic/Phase #3: Experiment/Sub-Phase #4/Desired Position BLACK/Calculate Time since Phase #3 Start/Subsystem'
//  '<S55>'  : 'MPC/1 - Experiment Logic/Phase #4: Return Home/Desired Joint Angles RED'
//  '<S56>'  : 'MPC/1 - Experiment Logic/Phase #4: Return Home/Desired Position BLACK'
//  '<S57>'  : 'MPC/1 - Experiment Logic/Phase #4: Return Home/Desired Position BLUE'
//  '<S58>'  : 'MPC/1 - Experiment Logic/Phase #4: Return Home/Desired Position RED'
//  '<S59>'  : 'MPC/1 - Experiment Logic/Phase #5: Hold Home/Desired Joint Angles RED'
//  '<S60>'  : 'MPC/1 - Experiment Logic/Phase #5: Hold Home/Desired Position BLACK'
//  '<S61>'  : 'MPC/1 - Experiment Logic/Phase #5: Hold Home/Desired Position BLUE'
//  '<S62>'  : 'MPC/1 - Experiment Logic/Phase #5: Hold Home/Desired Position RED'
//  '<S63>'  : 'MPC/2 - Guidance/Custom PPL (ARM)'
//  '<S64>'  : 'MPC/2 - Guidance/Custom PPL (BLACK)'
//  '<S65>'  : 'MPC/2 - Guidance/Custom PPL (BLUE)'
//  '<S66>'  : 'MPC/2 - Guidance/Custom PPL (RED)'
//  '<S67>'  : 'MPC/2 - Guidance/Default APF PPL (BLACK)'
//  '<S68>'  : 'MPC/2 - Guidance/Default APF PPL (RED)'
//  '<S69>'  : 'MPC/2 - Guidance/Disable PPL (ARM)'
//  '<S70>'  : 'MPC/2 - Guidance/Disable PPL (BLACK)'
//  '<S71>'  : 'MPC/2 - Guidance/Disable PPL (BLUE)'
//  '<S72>'  : 'MPC/2 - Guidance/Disable PPL (RED)'
//  '<S73>'  : 'MPC/2 - Guidance/Custom PPL (ARM)/Desired Position'
//  '<S74>'  : 'MPC/2 - Guidance/Custom PPL (BLACK)/Desired Position'
//  '<S75>'  : 'MPC/2 - Guidance/Custom PPL (BLUE)/Desired Position'
//  '<S76>'  : 'MPC/2 - Guidance/Custom PPL (RED)/Desired Position'
//  '<S77>'  : 'MPC/2 - Guidance/Default APF PPL (BLACK)/Current Position RED'
//  '<S78>'  : 'MPC/2 - Guidance/Default APF PPL (BLACK)/MATLAB Function'
//  '<S79>'  : 'MPC/2 - Guidance/Default APF PPL (BLACK)/Obstacles'
//  '<S80>'  : 'MPC/2 - Guidance/Default APF PPL (BLACK)/Obstacles/Current Position BLUE'
//  '<S81>'  : 'MPC/2 - Guidance/Default APF PPL (BLACK)/Obstacles/Current Position RED'
//  '<S82>'  : 'MPC/2 - Guidance/Default APF PPL (RED)/Current Position RED'
//  '<S83>'  : 'MPC/2 - Guidance/Default APF PPL (RED)/MATLAB Function'
//  '<S84>'  : 'MPC/2 - Guidance/Default APF PPL (RED)/Obstacles'
//  '<S85>'  : 'MPC/2 - Guidance/Default APF PPL (RED)/Obstacles/Current Position BLACK'
//  '<S86>'  : 'MPC/2 - Guidance/Default APF PPL (RED)/Obstacles/Current Position BLUE'
//  '<S87>'  : 'MPC/2 - Guidance/Disable PPL (ARM)/Desired Position'
//  '<S88>'  : 'MPC/2 - Guidance/Disable PPL (BLACK)/Desired Position'
//  '<S89>'  : 'MPC/2 - Guidance/Disable PPL (BLUE)/Desired Position'
//  '<S90>'  : 'MPC/2 - Guidance/Disable PPL (RED)/Desired Position'
//  '<S91>'  : 'MPC/3 - Navigation/Subsystem'
//  '<S92>'  : 'MPC/3 - Navigation/Subsystem/Filter Error'
//  '<S93>'  : 'MPC/3 - Navigation/Subsystem/MATLAB Function'
//  '<S94>'  : 'MPC/3 - Navigation/Subsystem/MATLAB Function1'
//  '<S95>'  : 'MPC/3 - Navigation/Subsystem/MATLAB Function11'
//  '<S96>'  : 'MPC/3 - Navigation/Subsystem/MATLAB Function12'
//  '<S97>'  : 'MPC/3 - Navigation/Subsystem/QMEKF'
//  '<S98>'  : 'MPC/3 - Navigation/Subsystem/RMEKF'
//  '<S99>'  : 'MPC/3 - Navigation/Subsystem/Representations'
//  '<S100>' : 'MPC/3 - Navigation/Subsystem/Representations1'
//  '<S101>' : 'MPC/3 - Navigation/Subsystem/STQMEKF'
//  '<S102>' : 'MPC/3 - Navigation/Subsystem/STRMEKF'
//  '<S103>' : 'MPC/3 - Navigation/Subsystem/Filter Error/MATLAB Function'
//  '<S104>' : 'MPC/3 - Navigation/Subsystem/Filter Error/MATLAB Function1'
//  '<S105>' : 'MPC/3 - Navigation/Subsystem/Filter Error/MATLAB Function2'
//  '<S106>' : 'MPC/3 - Navigation/Subsystem/Filter Error/MATLAB Function3'
//  '<S107>' : 'MPC/3 - Navigation/Subsystem/Filter Error/MATLAB Function4'
//  '<S108>' : 'MPC/3 - Navigation/Subsystem/Filter Error/MATLAB Function5'
//  '<S109>' : 'MPC/3 - Navigation/Subsystem/Filter Error/MATLAB Function6'
//  '<S110>' : 'MPC/3 - Navigation/Subsystem/Filter Error/MATLAB Function7'
//  '<S111>' : 'MPC/3 - Navigation/Subsystem/Filter Error/MATLAB Function8'
//  '<S112>' : 'MPC/3 - Navigation/Subsystem/QMEKF/MATLAB Function'
//  '<S113>' : 'MPC/3 - Navigation/Subsystem/QMEKF/MATLAB Function1'
//  '<S114>' : 'MPC/3 - Navigation/Subsystem/RMEKF/MATLAB Function'
//  '<S115>' : 'MPC/3 - Navigation/Subsystem/RMEKF/MATLAB Function1'
//  '<S116>' : 'MPC/3 - Navigation/Subsystem/RMEKF/MATLAB Function11'
//  '<S117>' : 'MPC/3 - Navigation/Subsystem/Representations/MATLAB Function'
//  '<S118>' : 'MPC/3 - Navigation/Subsystem/Representations1/MATLAB Function'
//  '<S119>' : 'MPC/3 - Navigation/Subsystem/STQMEKF/MATLAB Function1'
//  '<S120>' : 'MPC/3 - Navigation/Subsystem/STQMEKF/MATLAB Function2'
//  '<S121>' : 'MPC/3 - Navigation/Subsystem/STRMEKF/MATLAB Function'
//  '<S122>' : 'MPC/3 - Navigation/Subsystem/STRMEKF/MATLAB Function1'
//  '<S123>' : 'MPC/3 - Navigation/Subsystem/STRMEKF/MATLAB Function11'
//  '<S124>' : 'MPC/4 - Control/Custom Control (ARM)'
//  '<S125>' : 'MPC/4 - Control/Default LQR Control (BLACK)'
//  '<S126>' : 'MPC/4 - Control/Default LQR Control (BLUE)'
//  '<S127>' : 'MPC/4 - Control/Default LQR Control (RED)'
//  '<S128>' : 'MPC/4 - Control/Default PD (ARM)'
//  '<S129>' : 'MPC/4 - Control/Default PD Control (BLACK)'
//  '<S130>' : 'MPC/4 - Control/Default PD Control (BLUE)'
//  '<S131>' : 'MPC/4 - Control/Default PD Control (RED)'
//  '<S132>' : 'MPC/4 - Control/Disable Control (ARM)'
//  '<S133>' : 'MPC/4 - Control/Disable Thrusters (BLACK)'
//  '<S134>' : 'MPC/4 - Control/Disable Thrusters (BLUE)'
//  '<S135>' : 'MPC/4 - Control/Disable Thrusters (RED)'
//  '<S136>' : 'MPC/4 - Control/Model Predictive Control (RED)'
//  '<S137>' : 'MPC/4 - Control/Default LQR Control (BLACK)/Calculate Error'
//  '<S138>' : 'MPC/4 - Control/Default LQR Control (BLACK)/Discrete Derivative'
//  '<S139>' : 'MPC/4 - Control/Default LQR Control (BLACK)/Discrete Derivative1'
//  '<S140>' : 'MPC/4 - Control/Default LQR Control (BLACK)/Discrete Derivative2'
//  '<S141>' : 'MPC/4 - Control/Default LQR Control (BLACK)/Calculate Error/MATLAB Function'
//  '<S142>' : 'MPC/4 - Control/Default LQR Control (BLUE)/Calculate Error'
//  '<S143>' : 'MPC/4 - Control/Default LQR Control (BLUE)/Discrete Derivative'
//  '<S144>' : 'MPC/4 - Control/Default LQR Control (BLUE)/Discrete Derivative1'
//  '<S145>' : 'MPC/4 - Control/Default LQR Control (BLUE)/Discrete Derivative2'
//  '<S146>' : 'MPC/4 - Control/Default LQR Control (BLUE)/Calculate Error/MATLAB Function'
//  '<S147>' : 'MPC/4 - Control/Default LQR Control (RED)/Calculate Error'
//  '<S148>' : 'MPC/4 - Control/Default LQR Control (RED)/Discrete Derivative'
//  '<S149>' : 'MPC/4 - Control/Default LQR Control (RED)/Discrete Derivative1'
//  '<S150>' : 'MPC/4 - Control/Default LQR Control (RED)/Discrete Derivative2'
//  '<S151>' : 'MPC/4 - Control/Default LQR Control (RED)/Calculate Error/MATLAB Function'
//  '<S152>' : 'MPC/4 - Control/Default PD (ARM)/Passthrough for Experiment'
//  '<S153>' : 'MPC/4 - Control/Default PD (ARM)/Simulated Position Controller'
//  '<S154>' : 'MPC/4 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Elbow)'
//  '<S155>' : 'MPC/4 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Shoulder)'
//  '<S156>' : 'MPC/4 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Wrist)'
//  '<S157>' : 'MPC/4 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Elbow)/Discrete Derivative1'
//  '<S158>' : 'MPC/4 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Shoulder)/Discrete Derivative1'
//  '<S159>' : 'MPC/4 - Control/Default PD (ARM)/Simulated Position Controller/Custom Discrete PD (Wrist)/Discrete Derivative1'
//  '<S160>' : 'MPC/4 - Control/Default PD Control (BLACK)/Calculate Error'
//  '<S161>' : 'MPC/4 - Control/Default PD Control (BLACK)/Discrete Derivative'
//  '<S162>' : 'MPC/4 - Control/Default PD Control (BLACK)/Discrete Derivative1'
//  '<S163>' : 'MPC/4 - Control/Default PD Control (BLACK)/Discrete Derivative2'
//  '<S164>' : 'MPC/4 - Control/Default PD Control (BLACK)/Calculate Error/MATLAB Function'
//  '<S165>' : 'MPC/4 - Control/Default PD Control (BLUE)/Calculate Error'
//  '<S166>' : 'MPC/4 - Control/Default PD Control (BLUE)/Discrete Derivative'
//  '<S167>' : 'MPC/4 - Control/Default PD Control (BLUE)/Discrete Derivative1'
//  '<S168>' : 'MPC/4 - Control/Default PD Control (BLUE)/Discrete Derivative2'
//  '<S169>' : 'MPC/4 - Control/Default PD Control (BLUE)/Calculate Error/MATLAB Function'
//  '<S170>' : 'MPC/4 - Control/Default PD Control (RED)/Calculate Error'
//  '<S171>' : 'MPC/4 - Control/Default PD Control (RED)/Discrete Derivative'
//  '<S172>' : 'MPC/4 - Control/Default PD Control (RED)/Discrete Derivative1'
//  '<S173>' : 'MPC/4 - Control/Default PD Control (RED)/Discrete Derivative2'
//  '<S174>' : 'MPC/4 - Control/Default PD Control (RED)/Calculate Error/MATLAB Function'
//  '<S175>' : 'MPC/4 - Control/Disable Thrusters (BLACK)/MATLAB Function'
//  '<S176>' : 'MPC/Check  Connection/Change BLACK Behavior'
//  '<S177>' : 'MPC/Check  Connection/Change BLUE Behavior'
//  '<S178>' : 'MPC/Check  Connection/Change RED Behavior'
//  '<S179>' : 'MPC/Data Logger Subsystem/Data Logger1'
//  '<S180>' : 'MPC/Data Logger Subsystem/Subsystem1'
//  '<S181>' : 'MPC/Data Logger Subsystem/Subsystem10'
//  '<S182>' : 'MPC/Data Logger Subsystem/Subsystem11'
//  '<S183>' : 'MPC/Data Logger Subsystem/Subsystem12'
//  '<S184>' : 'MPC/Data Logger Subsystem/Subsystem13'
//  '<S185>' : 'MPC/Data Logger Subsystem/Subsystem14'
//  '<S186>' : 'MPC/Data Logger Subsystem/Subsystem15'
//  '<S187>' : 'MPC/Data Logger Subsystem/Subsystem16'
//  '<S188>' : 'MPC/Data Logger Subsystem/Subsystem17'
//  '<S189>' : 'MPC/Data Logger Subsystem/Subsystem2'
//  '<S190>' : 'MPC/Data Logger Subsystem/Subsystem3'
//  '<S191>' : 'MPC/Data Logger Subsystem/Subsystem4'
//  '<S192>' : 'MPC/Data Logger Subsystem/Subsystem5'
//  '<S193>' : 'MPC/Data Logger Subsystem/Subsystem6'
//  '<S194>' : 'MPC/Data Logger Subsystem/Subsystem7'
//  '<S195>' : 'MPC/Data Logger Subsystem/Subsystem8'
//  '<S196>' : 'MPC/Data Logger Subsystem/Subsystem9'
//  '<S197>' : 'MPC/Data Logger Subsystem/Data Logger1/MATLAB Function'
//  '<S198>' : 'MPC/Data Logger Subsystem/Subsystem1/MATLAB Function'
//  '<S199>' : 'MPC/Data Logger Subsystem/Subsystem10/MATLAB Function'
//  '<S200>' : 'MPC/Data Logger Subsystem/Subsystem11/MATLAB Function'
//  '<S201>' : 'MPC/Data Logger Subsystem/Subsystem12/MATLAB Function'
//  '<S202>' : 'MPC/Data Logger Subsystem/Subsystem13/MATLAB Function'
//  '<S203>' : 'MPC/Data Logger Subsystem/Subsystem14/MATLAB Function'
//  '<S204>' : 'MPC/Data Logger Subsystem/Subsystem15/MATLAB Function'
//  '<S205>' : 'MPC/Data Logger Subsystem/Subsystem16/MATLAB Function'
//  '<S206>' : 'MPC/Data Logger Subsystem/Subsystem17/MATLAB Function'
//  '<S207>' : 'MPC/Data Logger Subsystem/Subsystem2/MATLAB Function'
//  '<S208>' : 'MPC/Data Logger Subsystem/Subsystem3/MATLAB Function'
//  '<S209>' : 'MPC/Data Logger Subsystem/Subsystem4/MATLAB Function'
//  '<S210>' : 'MPC/Data Logger Subsystem/Subsystem5/MATLAB Function'
//  '<S211>' : 'MPC/Data Logger Subsystem/Subsystem6/MATLAB Function'
//  '<S212>' : 'MPC/Data Logger Subsystem/Subsystem7/MATLAB Function'
//  '<S213>' : 'MPC/Data Logger Subsystem/Subsystem8/MATLAB Function'
//  '<S214>' : 'MPC/Data Logger Subsystem/Subsystem9/MATLAB Function'
//  '<S215>' : 'MPC/Debugger1/Change BLACK Behavior'
//  '<S216>' : 'MPC/Debugger1/Change BLUE Behavior'
//  '<S217>' : 'MPC/Debugger1/Change RED Behavior'
//  '<S218>' : 'MPC/Float Code/Enable Pucks'
//  '<S219>' : 'MPC/Gyro.//Accel. Code/Log Gyro//Accel'
//  '<S220>' : 'MPC/Gyro.//Accel. Code/Log Gyro//Accel/Parse IMU Data'
//  '<S221>' : 'MPC/Manipulator Encoder Data/Change ARM Behavior'
//  '<S222>' : 'MPC/PhaseSpace Camera Code/Initialize Universal Time (Simulation)'
//  '<S223>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States'
//  '<S224>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data'
//  '<S225>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data'
//  '<S226>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data'
//  '<S227>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data'
//  '<S228>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data/Adjust Time '
//  '<S229>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data/Check for Sychronization'
//  '<S230>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data/Adjust Time /Enabled Subsystem'
//  '<S231>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data/Adjust Time /Enabled Subsystem1'
//  '<S232>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Receive and Process Phasespace Data/Check for Sychronization/MATLAB Function'
//  '<S233>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Calculate True  Time Step'
//  '<S234>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem1'
//  '<S235>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem2'
//  '<S236>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Wrap'
//  '<S237>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Calculate True  Time Step/Enabled Subsystem3'
//  '<S238>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Calculate True  Time Step/MATLAB Function'
//  '<S239>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem1/Enabled Subsystem'
//  '<S240>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem1/Enabled Subsystem/MATLAB Function'
//  '<S241>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem2/Enabled Subsystem'
//  '<S242>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLACK Data/Subsystem2/Enabled Subsystem/MATLAB Function'
//  '<S243>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Calculate True  Time Step'
//  '<S244>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem1'
//  '<S245>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem2'
//  '<S246>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Wrap'
//  '<S247>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Calculate True  Time Step/Enabled Subsystem3'
//  '<S248>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Calculate True  Time Step/MATLAB Function'
//  '<S249>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem1/Enabled Subsystem'
//  '<S250>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem1/Enabled Subsystem/MATLAB Function'
//  '<S251>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem2/Enabled Subsystem'
//  '<S252>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store BLUE Data/Subsystem2/Enabled Subsystem/MATLAB Function'
//  '<S253>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Calculate True  Time Step'
//  '<S254>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem1'
//  '<S255>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem2'
//  '<S256>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Wrap'
//  '<S257>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Calculate True  Time Step/Enabled Subsystem3'
//  '<S258>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Calculate True  Time Step/MATLAB Function'
//  '<S259>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem1/Enabled Subsystem'
//  '<S260>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem1/Enabled Subsystem/MATLAB Function'
//  '<S261>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem2/Enabled Subsystem'
//  '<S262>' : 'MPC/PhaseSpace Camera Code/Use Hardware to Obtain States/Store RED Data/Subsystem2/Enabled Subsystem/MATLAB Function'
//  '<S263>' : 'MPC/PhaseSpace Filter Code/Discrete Derivative'
//  '<S264>' : 'MPC/PhaseSpace Filter Code/Discrete Derivative1'
//  '<S265>' : 'MPC/PhaseSpace Filter Code/Discrete Derivative2'
//  '<S266>' : 'MPC/PhaseSpace Filter Code/Subsystem1'
//  '<S267>' : 'MPC/PhaseSpace Filter Code/Subsystem2'
//  '<S268>' : 'MPC/PhaseSpace Filter Code/Subsystem3'
//  '<S269>' : 'MPC/PhaseSpace Filter Code/Subsystem1/MATLAB Function'
//  '<S270>' : 'MPC/PhaseSpace Filter Code/Subsystem1/Subsystem'
//  '<S271>' : 'MPC/PhaseSpace Filter Code/Subsystem1/Subsystem/MATLAB Function1'
//  '<S272>' : 'MPC/PhaseSpace Filter Code/Subsystem2/MATLAB Function'
//  '<S273>' : 'MPC/PhaseSpace Filter Code/Subsystem2/Subsystem'
//  '<S274>' : 'MPC/PhaseSpace Filter Code/Subsystem2/Subsystem/MATLAB Function1'
//  '<S275>' : 'MPC/PhaseSpace Filter Code/Subsystem3/MATLAB Function'
//  '<S276>' : 'MPC/PhaseSpace Filter Code/Subsystem3/Subsystem'
//  '<S277>' : 'MPC/PhaseSpace Filter Code/Subsystem3/Subsystem/MATLAB Function1'
//  '<S278>' : 'MPC/Platform  Identification/Subsystem'
//  '<S279>' : 'MPC/Receive Data /Subsystem'
//  '<S280>' : 'MPC/Receive Data /Subsystem/MATLAB Function1'
//  '<S281>' : 'MPC/Receive Data /Subsystem/MATLAB Function2'
//  '<S282>' : 'MPC/Receive Data /Subsystem/MATLAB Function4'
//  '<S283>' : 'MPC/Receive Data /Subsystem/Pose1'
//  '<S284>' : 'MPC/Receive Data /Subsystem/Pose2'
//  '<S285>' : 'MPC/Receive Data /Subsystem/Pose1/MATLAB Function'
//  '<S286>' : 'MPC/Receive Data /Subsystem/Pose2/MATLAB Function'
//  '<S287>' : 'MPC/Robotic  Arm Code/Change ARM Behavior'
//  '<S288>' : 'MPC/Send Data  to Orin/Subsystem'
//  '<S289>' : 'MPC/Thruster Control Code/Change BLACK Behavior'
//  '<S290>' : 'MPC/Thruster Control Code/Change BLUE Behavior'
//  '<S291>' : 'MPC/Thruster Control Code/Change RED Behavior'
//  '<S292>' : 'MPC/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle'
//  '<S293>' : 'MPC/Thruster Control Code/Change BLACK Behavior/Rotate Forces to Body'
//  '<S294>' : 'MPC/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Duty Cycle @ PWM'
//  '<S295>' : 'MPC/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Generate Initial Guess'
//  '<S296>' : 'MPC/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/MATLAB Function1'
//  '<S297>' : 'MPC/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/MATLAB Function5'
//  '<S298>' : 'MPC/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Rotate Forces to Inertial'
//  '<S299>' : 'MPC/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem'
//  '<S300>' : 'MPC/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem1'
//  '<S301>' : 'MPC/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Generate Initial Guess/MATLAB Function'
//  '<S302>' : 'MPC/Thruster Control Code/Change BLACK Behavior/Calculate Duty Cycle/Rotate Forces to Inertial/Create Rotation Matrix'
//  '<S303>' : 'MPC/Thruster Control Code/Change BLACK Behavior/Rotate Forces to Body/Create Rotation Matrix'
//  '<S304>' : 'MPC/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle'
//  '<S305>' : 'MPC/Thruster Control Code/Change BLUE Behavior/Rotate Forces to Body'
//  '<S306>' : 'MPC/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Duty Cycle @ PWM'
//  '<S307>' : 'MPC/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Generate Initial Guess'
//  '<S308>' : 'MPC/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/MATLAB Function1'
//  '<S309>' : 'MPC/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/MATLAB Function5'
//  '<S310>' : 'MPC/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Rotate Forces to Inertial'
//  '<S311>' : 'MPC/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem'
//  '<S312>' : 'MPC/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem1'
//  '<S313>' : 'MPC/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Generate Initial Guess/MATLAB Function'
//  '<S314>' : 'MPC/Thruster Control Code/Change BLUE Behavior/Calculate Duty Cycle/Rotate Forces to Inertial/Create Rotation Matrix'
//  '<S315>' : 'MPC/Thruster Control Code/Change BLUE Behavior/Rotate Forces to Body/Create Rotation Matrix'
//  '<S316>' : 'MPC/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle'
//  '<S317>' : 'MPC/Thruster Control Code/Change RED Behavior/Rotate Forces to Body'
//  '<S318>' : 'MPC/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Duty Cycle @ PWM'
//  '<S319>' : 'MPC/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Generate Initial Guess'
//  '<S320>' : 'MPC/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/MATLAB Function5'
//  '<S321>' : 'MPC/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/MATLAB Function8'
//  '<S322>' : 'MPC/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Rotate Forces to Inertial'
//  '<S323>' : 'MPC/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem'
//  '<S324>' : 'MPC/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Duty Cycle @ PWM/Enabled Subsystem1'
//  '<S325>' : 'MPC/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Generate Initial Guess/MATLAB Function'
//  '<S326>' : 'MPC/Thruster Control Code/Change RED Behavior/Calculate Duty Cycle/Rotate Forces to Inertial/Create Rotation Matrix'
//  '<S327>' : 'MPC/Thruster Control Code/Change RED Behavior/Rotate Forces to Body/Create Rotation Matrix'

#endif                                 // MPC_h_

//
// File trailer for generated code.
//
// [EOF]
//
