//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MPC_types.h
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
#ifndef MPC_types_h_
#define MPC_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"
#ifndef struct_dsp_simulink_Pseudoinverse_MP_T
#define struct_dsp_simulink_Pseudoinverse_MP_T

struct dsp_simulink_Pseudoinverse_MP_T
{
  int32_T isInitialized;
};

#endif                                // struct_dsp_simulink_Pseudoinverse_MP_T

// Custom Type definition for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
#include "coder_posix_time.h"

// Custom Type definition for MATLAB Function: '<S102>/MATLAB Function1'
#ifndef struct_sdAmwXbnJnEmimT0NaJRtAD_MPC_T
#define struct_sdAmwXbnJnEmimT0NaJRtAD_MPC_T

struct sdAmwXbnJnEmimT0NaJRtAD_MPC_T
{
  real_T tv_sec;
  real_T tv_nsec;
};

#endif                                 // struct_sdAmwXbnJnEmimT0NaJRtAD_MPC_T

#ifndef struct_CustomDataLogger_MPC_T
#define struct_CustomDataLogger_MPC_T

struct CustomDataLogger_MPC_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 // struct_CustomDataLogger_MPC_T

#ifndef struct_GPIO_Write_MPC_T
#define struct_GPIO_Write_MPC_T

struct GPIO_Write_MPC_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T gpioPin;
  real_T pinDirection;
};

#endif                                 // struct_GPIO_Write_MPC_T

// Custom Type definition for MATLABSystem: '<S219>/Gyroscope//Accelerometer'
#include "MW_SVD.h"
#ifndef struct_e_codertarget_jetson_sensors__T
#define struct_e_codertarget_jetson_sensors__T

struct e_codertarget_jetson_sensors__T
{
  real_T currentTime;
};

#endif                                // struct_e_codertarget_jetson_sensors__T

#ifndef struct_e_matlabshared_devicedrivers__T
#define struct_e_matlabshared_devicedrivers__T

struct e_matlabshared_devicedrivers__T
{
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                // struct_e_matlabshared_devicedrivers__T

#ifndef struct_e_matlabshared_sensors_coder__T
#define struct_e_matlabshared_sensors_coder__T

struct e_matlabshared_sensors_coder__T
{
  uint8_T Bus;
  uint8_T DeviceAddress;
  e_matlabshared_devicedrivers__T *InterfaceObj;
  e_matlabshared_devicedrivers__T _pobj0;
};

#endif                                // struct_e_matlabshared_sensors_coder__T

#ifndef struct_f_matlabshared_sensors_coder__T
#define struct_f_matlabshared_sensors_coder__T

struct f_matlabshared_sensors_coder__T
{
  int32_T isInitialized;
  e_matlabshared_sensors_coder__T Device;
  real_T BusI2CDriver;
  real_T Bus;
};

#endif                                // struct_f_matlabshared_sensors_coder__T

#ifndef struct_b_bmi160_MPC_T
#define struct_b_bmi160_MPC_T

struct b_bmi160_MPC_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  e_codertarget_jetson_sensors__T *Parent;
  f_matlabshared_sensors_coder__T *Device;
  f_matlabshared_sensors_coder__T _pobj0;
};

#endif                                 // struct_b_bmi160_MPC_T

#ifndef struct_f_matlabshared_sensors_simuli_T
#define struct_f_matlabshared_sensors_simuli_T

struct f_matlabshared_sensors_simuli_T
{
  int32_T __dummy;
};

#endif                                // struct_f_matlabshared_sensors_simuli_T

#ifndef struct_g_matlabshared_sensors_simuli_T
#define struct_g_matlabshared_sensors_simuli_T

struct g_matlabshared_sensors_simuli_T
{
  int32_T __dummy;
};

#endif                                // struct_g_matlabshared_sensors_simuli_T

#ifndef struct_hb_cell_MPC_T
#define struct_hb_cell_MPC_T

struct hb_cell_MPC_T
{
  f_matlabshared_sensors_simuli_T *f1;
  g_matlabshared_sensors_simuli_T *f2;
};

#endif                                 // struct_hb_cell_MPC_T

#ifndef struct_nvidiacoder_sensors_BMI160Blo_T
#define struct_nvidiacoder_sensors_BMI160Blo_T

struct nvidiacoder_sensors_BMI160Blo_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  real_T SampleTime;
  e_codertarget_jetson_sensors__T *HwUtilityObject;
  b_bmi160_MPC_T *SensorObject;
  hb_cell_MPC_T OutputModules;
  boolean_T __OutputModules_AssignmentSentinel;
  g_matlabshared_sensors_simuli_T _pobj0;
  f_matlabshared_sensors_simuli_T _pobj1;
  b_bmi160_MPC_T _pobj2;
  e_codertarget_jetson_sensors__T _pobj3;
};

#endif                                // struct_nvidiacoder_sensors_BMI160Blo_T

#ifndef struct_ReadArm_Position_Rates_MPC_T
#define struct_ReadArm_Position_Rates_MPC_T

struct ReadArm_Position_Rates_MPC_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
};

#endif                                 // struct_ReadArm_Position_Rates_MPC_T

#ifndef struct_IdentifyPlatform_MPC_T
#define struct_IdentifyPlatform_MPC_T

struct IdentifyPlatform_MPC_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
};

#endif                                 // struct_IdentifyPlatform_MPC_T

#ifndef struct_Dynamixel_Controller_MPC_T
#define struct_Dynamixel_Controller_MPC_T

struct Dynamixel_Controller_MPC_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  real_T POSITION_P_GAIN;
  real_T POSITION_I_GAIN;
  real_T POSITION_D_GAIN;
  real_T MAX_POSITION;
  real_T MIN_POSITION;
  real_T MOVE_TIME;
  real_T CURRENT_LIMIT;
  real_T SPEED_P_GAIN;
  real_T SPEED_I_GAIN;
  real_T VELOCITY_LIMIT;
  real_T ACCELERATION_TIME;
};

#endif                                 // struct_Dynamixel_Controller_MPC_T

// Custom Type definition for MATLAB Function: '<S316>/MATLAB Function5'
#ifndef struct_sraTyWZlTzdIJhNDrRZT2SF_MPC_T
#define struct_sraTyWZlTzdIJhNDrRZT2SF_MPC_T

struct sraTyWZlTzdIJhNDrRZT2SF_MPC_T
{
  real_T xstar[9];
  real_T fstar;
  real_T firstorderopt;
  real_T lambda[17];
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  real_T searchDir[9];
};

#endif                                 // struct_sraTyWZlTzdIJhNDrRZT2SF_MPC_T

#ifndef struct_s87IldPMN2ICa85Nu8z6UL_MPC_T
#define struct_s87IldPMN2ICa85Nu8z6UL_MPC_T

struct s87IldPMN2ICa85Nu8z6UL_MPC_T
{
  real_T grad[9];
  real_T Hx[8];
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
};

#endif                                 // struct_s87IldPMN2ICa85Nu8z6UL_MPC_T

#ifndef struct_smSS6fEwaptVbzYAOdOZgjB_MPC_T
#define struct_smSS6fEwaptVbzYAOdOZgjB_MPC_T

struct smSS6fEwaptVbzYAOdOZgjB_MPC_T
{
  real_T FMat[81];
  int32_T ldm;
  int32_T ndims;
  int32_T info;
  real_T scaleFactor;
  boolean_T ConvexCheck;
  real_T regTol_;
  real_T workspace_[432];
  real_T workspace2_[432];
};

#endif                                 // struct_smSS6fEwaptVbzYAOdOZgjB_MPC_T

#ifndef struct_sIOJhD9KwAkF5sEguPjYquC_MPC_T
#define struct_sIOJhD9KwAkF5sEguPjYquC_MPC_T

struct sIOJhD9KwAkF5sEguPjYquC_MPC_T
{
  boolean_T RemainFeasible;
  int32_T MaxIterations;
  real_T ConstrRelTolFactor;
  real_T ProbRelTolFactor;
};

#endif                                 // struct_sIOJhD9KwAkF5sEguPjYquC_MPC_T

#ifndef struct_sTj3C1mXm6Z2qP847mPxR8C_MPC_T
#define struct_sTj3C1mXm6Z2qP847mPxR8C_MPC_T

struct sTj3C1mXm6Z2qP847mPxR8C_MPC_T
{
  int32_T ldq;
  real_T QR[153];
  real_T Q[81];
  int32_T jpvt[17];
  int32_T mrows;
  int32_T ncols;
  real_T tau[9];
  int32_T minRowCol;
  boolean_T usedPivoting;
};

#endif                                 // struct_sTj3C1mXm6Z2qP847mPxR8C_MPC_T

#ifndef struct_sLLWTJNyuJQrAxk3RwmbzBG_MPC_T
#define struct_sLLWTJNyuJQrAxk3RwmbzBG_MPC_T

struct sLLWTJNyuJQrAxk3RwmbzBG_MPC_T
{
  real_T workspace_float[153];
  int32_T workspace_int[17];
  int32_T workspace_sort[17];
};

#endif                                 // struct_sLLWTJNyuJQrAxk3RwmbzBG_MPC_T

// Custom Type definition for MATLAB Function: '<S102>/MATLAB Function1'
#ifndef struct_sizqrrDnCZNkAfKt1PT2RqF_MPC_T
#define struct_sizqrrDnCZNkAfKt1PT2RqF_MPC_T

struct sizqrrDnCZNkAfKt1PT2RqF_MPC_T
{
  real_T P_k[144];
  real_T H[72];
  real_T V[36];
};

#endif                                 // struct_sizqrrDnCZNkAfKt1PT2RqF_MPC_T

#ifndef struct_anonymous_function_MPC_T
#define struct_anonymous_function_MPC_T

struct anonymous_function_MPC_T
{
  sizqrrDnCZNkAfKt1PT2RqF_MPC_T workspace;
};

#endif                                 // struct_anonymous_function_MPC_T

#ifndef struct_s_FZgTJKlbHYUjzcW9Gv0Az_MPC_T
#define struct_s_FZgTJKlbHYUjzcW9Gv0Az_MPC_T

struct s_FZgTJKlbHYUjzcW9Gv0Az_MPC_T
{
  anonymous_function_MPC_T fun;
};

#endif                                 // struct_s_FZgTJKlbHYUjzcW9Gv0Az_MPC_T

#ifndef struct_anonymous_function_2_MPC_T
#define struct_anonymous_function_2_MPC_T

struct anonymous_function_2_MPC_T
{
  s_FZgTJKlbHYUjzcW9Gv0Az_MPC_T workspace;
};

#endif                                 // struct_anonymous_function_2_MPC_T

#ifndef struct_s_B0kB2CQLsoRkj8KoaXWXYC_MPC_T
#define struct_s_B0kB2CQLsoRkj8KoaXWXYC_MPC_T

struct s_B0kB2CQLsoRkj8KoaXWXYC_MPC_T
{
  anonymous_function_2_MPC_T nonlin;
  real_T f_1;
  real_T cEq_1[36];
  real_T f_2;
  real_T cEq_2[36];
  int32_T nVar;
  int32_T mIneq;
  int32_T mEq;
  int32_T numEvals;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T isEmptyNonlcon;
  boolean_T hasLB[6];
  boolean_T hasUB[6];
  boolean_T hasBounds;
  int32_T FiniteDifferenceType;
};

#endif                                 // struct_s_B0kB2CQLsoRkj8KoaXWXYC_MPC_T

// Custom Type definition for MATLAB Function: '<S316>/MATLAB Function5'
#ifndef struct_srnx7tMxlsAQ9dn31gXFrqF_MPC_T
#define struct_srnx7tMxlsAQ9dn31gXFrqF_MPC_T

struct srnx7tMxlsAQ9dn31gXFrqF_MPC_T
{
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  real_T lb[9];
  real_T ub[9];
  int32_T indexLB[9];
  int32_T indexUB[9];
  int32_T indexFixed[9];
  int32_T mEqRemoved;
  real_T ATwset[153];
  real_T bwset[17];
  int32_T nActiveConstr;
  real_T maxConstrWorkspace[17];
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  boolean_T isActiveConstr[17];
  int32_T Wid[17];
  int32_T Wlocalidx[17];
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
};

#endif                                 // struct_srnx7tMxlsAQ9dn31gXFrqF_MPC_T

// Parameters for system: '<S1>/Phase #0: Synchronization'
typedef struct P_Phase0Synchronization_MPC_T_ P_Phase0Synchronization_MPC_T;

// Parameters for system: '<S1>/Phase #4: Return Home'
typedef struct P_Phase4ReturnHome_MPC_T_ P_Phase4ReturnHome_MPC_T;

// Parameters for system: '<S4>/Disable Thrusters (RED)'
typedef struct P_DisableThrustersRED_MPC_T_ P_DisableThrustersRED_MPC_T;

// Parameters for system: '<S4>/Default PD Control (BLACK)'
typedef struct P_DefaultPDControlBLACK_MPC_T_ P_DefaultPDControlBLACK_MPC_T;

// Parameters for system: '<S5>/Change BLACK Behavior'
typedef struct P_ChangeBLACKBehavior_MPC_T_ P_ChangeBLACKBehavior_MPC_T;

// Parameters for system: '<S234>/Enabled Subsystem'
typedef struct P_EnabledSubsystem_MPC_T_ P_EnabledSubsystem_MPC_T;

// Parameters for system: '<S235>/Enabled Subsystem'
typedef struct P_EnabledSubsystem_MPC_d_T_ P_EnabledSubsystem_MPC_d_T;

// Parameters (default storage)
typedef struct P_MPC_T_ P_MPC_T;

// Forward declaration for rtModel
typedef struct tag_RTM_MPC_T RT_MODEL_MPC_T;

#endif                                 // MPC_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
