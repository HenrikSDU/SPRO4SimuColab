/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Controller_implementation_data.c
 *
 * Code generated for Simulink model 'Controller_implementation'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon May 27 17:16:40 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Controller_implementation.h"

/* Block parameters (default storage) */
P_Controller_implementation_T Controller_implementation_P = {
  /* Variable: F
   * Referenced by: '<S2>/Gain1'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 },

  /* Variable: KV_rating
   * Referenced by:
   *   '<S66>/Constant1'
   *   '<S75>/Constant'
   */
  2800.0,

  /* Variable: K_mm
   * Referenced by: '<S66>/Gain'
   */
  { 0.25, 0.25, 0.24999999999999994, 0.25, 3.0799556486386588,
    -3.0799556486386588, -3.0799556486386597, 3.0799556486386597,
    3.0799556486386597, 3.0799556486386588, -3.0799556486386588,
    -3.0799556486386597, 15.094412367154886, -15.094412367154886,
    15.094412367154886, -15.094412367154886 },

  /* Variable: Ki_D_lqi_reduced_a
   * Referenced by: '<S2>/Gain2'
   */
  { -39.240000000001018, 2.5870514251349964E-15, -3.01028838879467E-14,
    2.1342505622833488E-14, -5.9554027427506754E-13, -9.9999999999999609,
    5.6205249996478852E-13, -3.6584402793076448E-14, -1.1561994467764894E-13,
    2.3243562386277609E-12, -10.000000000001206, 3.0573846674546583E-14,
    9.1425578253150825E-14, -2.2820681654451703E-15, 3.0679054457819819E-15,
    -0.999999999999906 },

  /* Variable: Kx_D_lqi_reduced_a
   * Referenced by: '<S2>/Gain'
   */
  { 163.43301266009598, -2.7165656406245385E-14, 4.1394531370083686E-14,
    -2.945286575749255E-14, 5.86288031520079E-13, 8.539930428625766,
    -4.633974628000558E-13, 1.8933150346405054E-14, 3.7859013090781409E-14,
    -1.6371403064260762E-13, 8.5399304286259881, 3.2988775040603508E-15,
    -5.1119021936266558E-14, -4.1983138697318568E-14, -6.3828342880184789E-15,
    6.3505401512198976, 261.86594326140175, 4.7144051140552548E-15,
    -1.7546939567664659E-15, 6.332055988680194E-16, 1.1733713655521714E-13,
    2.0051174112826118, -5.3994740076259107E-15, -2.0308504147737184E-16,
    -8.04283889638786E-15, 1.5406408219548214E-14, 2.0051174112826251,
    1.8991637876258213E-16, -9.9882619235431257E-13, -2.6919998044500862E-14,
    -4.2915052192622979E-14, 20.000539788628444 },

  /* Variable: Ts
   * Referenced by:
   *   '<S7>/Barometer'
   *   '<S7>/MPU9250'
   */
  0.01,

  /* Variable: battery_voltage
   * Referenced by:
   *   '<S66>/Constant'
   *   '<S75>/Battery Voltage'
   */
  25.0,

  /* Variable: dis
   * Referenced by: '<S8>/Constant'
   */
  0.08117,

  /* Variable: drag_co
   * Referenced by: '<S75>/Gain1'
   */
  9.7533277591854016E-12,

  /* Variable: lift_co
   * Referenced by:
   *   '<S66>/Constant2'
   *   '<S75>/Gain'
   */
  5.8888300459665265E-10,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S64>/Constant'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S61>/L*(y[k]-yhat[k|k-1])'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S63>/deltax'
   */
  0.0,

  /* Expression: 1.0
   * Referenced by: '<S69>/Moving Average'
   */
  1.0,

  /* Expression: initCond
   * Referenced by: '<S73>/ '
   */
  1.0E+8,

  /* Expression: pInitialization.A
   * Referenced by: '<S9>/A'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.01,
    0.0, 0.0, 0.0, 1.0 },

  /* Expression: pInitialization.M
   * Referenced by: '<S10>/KalmanGainM'
   */
  { 0.00076495029425736644, -2.1325025409412695E-17, 1.1901358892754266E-20,
    7.2341655191271969E-19, 2.9268642162454212E-5, 1.8436854679601463E-19,
    -1.3749439510878775E-20, -1.5378730968185371E-20, -3.9966926281198571E-13,
    0.008910944526886528, 1.1363337746510453E-14, -9.0087092512382637E-15,
    2.1111517275827663E-14, 0.003988848460545532, -1.6449163064463685E-14,
    -9.7454019367663083E-16, 4.1654169681094563E-16, 2.1220550839738848E-14,
    0.0058684594002320345, 5.2310094643697371E-15, 3.7744070151782285E-17,
    1.8973254100346308E-14, 0.0017270441788018902, 1.1383626206077151E-15,
    1.3558124994370543E-14, -9.0087092512382637E-15, 2.8011396946167864E-15,
    0.0050220817125431394, -8.3114372682409772E-16, 6.31012355276963E-16,
    -5.6672152296432257E-15, 0.0012642897017935966, 3.6036242214912363E-18,
    4.1599586146963653E-6, 1.0595770859400121E-17, 6.5808097481728887E-19,
    -1.8552706543526086E-19, 3.7418227736701545E-6, -1.5263518424837136E-17,
    -8.354332346613932E-21, -1.1567538012746824E-19, -7.383946720860661E-18,
    4.151427499459184E-7, -2.5439844657956806E-18, -7.5781430495857825E-21,
    -6.5698874721263063E-18, 2.4507324369737543E-7, -1.0449529136593851E-18,
    -1.7953502851195403E-19, -6.0703992990587881E-19, 3.7970594091047332E-19,
    7.8752455459232739E-7, -1.6074436500934E-18, -4.9898533122831775E-21,
    -1.4500049208773031E-18, 3.9752907508688712E-7 },

  /* Expression: pInitialization.C
   * Referenced by: '<S9>/C'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: pInitialization.L
   * Referenced by: '<S10>/KalmanGainL'
   */
  { 0.00076524298067899078, -2.1327733297792331E-17, 2.2513365110200429E-20,
    7.14786477690291E-19, 2.9268642162454192E-5, 1.7290227554314542E-19,
    -1.3394052912140385E-20, -1.5932407977831466E-20, -3.74693908716064E-13,
    0.0089508330114922048, 7.3800711196864584E-15, -8.4925275434094123E-15,
    1.9812970999716027E-14, 0.00398884846054568, -1.5713832706058364E-14,
    -9.1865451282246349E-16, 3.3387632272475844E-16, 1.989787543148601E-14,
    0.0058857298420201456, 5.0514416844552075E-15, 3.1974767158851663E-17,
    2.0719304104804821E-14, 0.0017270441788019494, 1.3629051977505335E-15,
    1.2587655394737464E-14, -8.44186549476033E-15, 2.03935573777876E-15,
    0.005034724609560828, -8.3731086899246383E-16, 7.3691271195440061E-16,
    -5.544925336655158E-15, 0.0012642897017935396, 5.03054398145571E-18,
    4.1973768424330823E-6, 1.0219765374157438E-17, 6.90150380982654E-19,
    -2.6107113466639294E-19, 3.7418227736701659E-6, -1.5219984426697242E-17,
    -4.4980721296873911E-21, -1.1575757389959822E-19, -7.4516154941553533E-18,
    4.175934823828924E-7, -2.5544332792000539E-18, -7.5785672069529579E-21,
    -6.5660731942750864E-18, 2.4507324369737553E-7, -1.0444314330416303E-18,
    -2.0619414447169159E-19, -6.0062237871637588E-19, 3.5791932141297522E-19,
    7.9149984534319311E-7, -1.6073416019952075E-18, -3.8612887777048385E-21,
    -1.4485262882957672E-18, 3.9752907508688622E-7 },

  /* Expression: pInitialization.B
   * Referenced by: '<S9>/B'
   */
  { 0.00011739845034045551, 0.0, 0.0, 0.0, 0.023479690068091103, 0.0, 0.0, 0.0,
    0.0, 0.041666666666666664, 0.0, 0.0, 0.0, 8.3333333333333339, 0.0, 0.0, 0.0,
    0.0, 0.041666666666666664, 0.0, 0.0, 0.0, 8.3333333333333339, 0.0, 0.0, 0.0,
    0.0, 0.029411764705882356, 0.0, 0.0, 0.0, 5.882352941176471 },

  /* Expression: pInitialization.D
   * Referenced by: '<S9>/D'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S7>/Constant'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S68>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S9>/X0'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 255
   * Referenced by: '<S3>/PWM limit'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<S3>/PWM limit'
   */
  0.0,

  /* Expression: [1;-1;1;-1]
   * Referenced by: '<S75>/Sign Convention'
   */
  { 1.0, -1.0, 1.0, -1.0 },

  /* Expression: [0;0;0;0]
   * Referenced by: '<S8>/Constant1'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: [0;0;0;0;]
   * Referenced by: '<S6>/Constant'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 180/pi
   * Referenced by: '<S4>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<S5>/Gain'
   */
  57.295779513082323,

  /* Expression: pInitialization.Z
   * Referenced by: '<S10>/CovarianceZ'
   */
  { 8.9226883682834443E-5, -2.4874368648833703E-18, 1.3882224421161803E-21,
    8.4382220670192E-20, 3.4140123213092771E-6, 2.1505489968746157E-20,
    -1.6037900098232875E-21, -1.7938371284895615E-21, -2.4874368648833707E-18,
    5.5459385996204106E-8, 7.0722439398817762E-20, -5.6067848047367808E-20,
    1.3139255687575741E-19, 2.4825548603325536E-8, -1.0237528479209799E-19,
    -6.0652830468031047E-21, 1.3882224421161801E-21, 7.072243939881775E-20,
    1.9558010884435654E-8, 1.7433560166861522E-20, 1.2579092475655074E-22,
    6.32327984058413E-20, 5.7557778870504022E-9, 3.7938591725453666E-21,
    8.4382220670192E-20, -5.606784804736782E-20, 1.7433560166861519E-20,
    3.12561218802383E-8, -5.1728209759562593E-21, 3.9272557105578089E-21,
    -3.5271264005294641E-20, 7.8686081336537655E-9, 3.4140123213092771E-6,
    1.3139255687575744E-19, 1.2579092475655069E-22, -5.1728209759562593E-21,
    2.61354896483447E-7, -1.1071771637159911E-21, -1.0506773440073991E-22,
    -1.606088864881503E-20, 2.1505489968746157E-20, 2.4825548603325539E-8,
    6.3232798405841283E-20, 3.9272557105578081E-21, -1.1071771637159909E-21,
    2.2330222902844676E-8, -9.1088699097841118E-20, -4.9856477654967481E-23,
    -1.6037900098232877E-21, -1.02375284792098E-19, 5.7557778870504014E-9,
    -3.5271264005294647E-20, -1.0506773440073991E-22, -9.10886990978411E-20,
    3.3978364236514504E-9, -1.4487828281315524E-20, -1.7938371284895623E-21,
    -6.0652830468031047E-21, 3.7938591725453666E-21, 7.8686081336537671E-9,
    -1.6060888648815027E-20, -4.9856477654967487E-23, -1.4487828281315527E-20,
    3.9719402974194115E-9 },

  /* Expression: 5
   * Referenced by: '<S69>/Step3'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S69>/Step3'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S69>/Step3'
   */
  1.0,

  /* Computed Parameter: Servolimit_UpperSat
   * Referenced by: '<S3>/Servo limit'
   */
  60,

  /* Computed Parameter: Servolimit_LowerSat
   * Referenced by: '<S3>/Servo limit'
   */
  40,

  /* Expression: true()
   * Referenced by: '<S9>/Enable'
   */
  true,

  /* Expression: pInitialization.isSqrtUsed
   * Referenced by: '<S59>/isSqrtUsed'
   */
  false,

  /* Computed Parameter: Initial1_Value
   * Referenced by: '<S3>/Initial1'
   */
  { 40U, 40U, 40U, 40U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
