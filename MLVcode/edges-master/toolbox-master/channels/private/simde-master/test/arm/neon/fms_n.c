#define SIMDE_TEST_ARM_NEON_INSN fms_n

#include "test-neon.h"
#include "../../../simde/arm/neon/fms_n.h"

static int
test_simde_vfms_n_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[4];
    simde_float16_t b[4];
    simde_float16_t c;
    simde_float16_t r[4];
  } test_vec[] = {
   { {  SIMDE_FLOAT16_VALUE(-4.51), SIMDE_FLOAT16_VALUE(-3.15), SIMDE_FLOAT16_VALUE(4.65), SIMDE_FLOAT16_VALUE(-2.79) },
     {  SIMDE_FLOAT16_VALUE(1.88), SIMDE_FLOAT16_VALUE(2.18), SIMDE_FLOAT16_VALUE(-5.14), SIMDE_FLOAT16_VALUE(6.04) },
        SIMDE_FLOAT16_VALUE(8.46),
     {  SIMDE_FLOAT16_VALUE(-20.42), SIMDE_FLOAT16_VALUE(-21.56), SIMDE_FLOAT16_VALUE(48.18), SIMDE_FLOAT16_VALUE(-53.91) } },
   { {  SIMDE_FLOAT16_VALUE(-8.79), SIMDE_FLOAT16_VALUE(7.93), SIMDE_FLOAT16_VALUE(6.44), SIMDE_FLOAT16_VALUE(3.93) },
     {  SIMDE_FLOAT16_VALUE(8.41), SIMDE_FLOAT16_VALUE(-1.86), SIMDE_FLOAT16_VALUE(-8.29), SIMDE_FLOAT16_VALUE(6.98) },
        SIMDE_FLOAT16_VALUE(-6.90),
     {  SIMDE_FLOAT16_VALUE(49.22), SIMDE_FLOAT16_VALUE(-4.89), SIMDE_FLOAT16_VALUE(-50.75), SIMDE_FLOAT16_VALUE(52.13) } },
   { {  SIMDE_FLOAT16_VALUE(-5.03), SIMDE_FLOAT16_VALUE(6.91), SIMDE_FLOAT16_VALUE(-1.39), SIMDE_FLOAT16_VALUE(-0.79) },
     {  SIMDE_FLOAT16_VALUE(9.89), SIMDE_FLOAT16_VALUE(6.99), SIMDE_FLOAT16_VALUE(8.53), SIMDE_FLOAT16_VALUE(-2.51) },
        SIMDE_FLOAT16_VALUE(2.63),
     {  SIMDE_FLOAT16_VALUE(-31.05), SIMDE_FLOAT16_VALUE(-11.49), SIMDE_FLOAT16_VALUE(-23.83), SIMDE_FLOAT16_VALUE(5.81) } },
   { {  SIMDE_FLOAT16_VALUE(-6.05), SIMDE_FLOAT16_VALUE(-8.23), SIMDE_FLOAT16_VALUE(0.70), SIMDE_FLOAT16_VALUE(-1.65) },
     {  SIMDE_FLOAT16_VALUE(-5.28), SIMDE_FLOAT16_VALUE(-9.29), SIMDE_FLOAT16_VALUE(0.62), SIMDE_FLOAT16_VALUE(-4.37) },
        SIMDE_FLOAT16_VALUE(7.61),
     {  SIMDE_FLOAT16_VALUE(34.19), SIMDE_FLOAT16_VALUE(62.51), SIMDE_FLOAT16_VALUE(-4.01), SIMDE_FLOAT16_VALUE(31.65) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16_t c = test_vec[i].c;
    simde_float16x4_t r = simde_vfms_n_f16(a, b, c);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmsq_n_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[8];
    simde_float16_t b[8];
    simde_float16_t c;
    simde_float16_t r[8];
  } test_vec[] = {
   { {  SIMDE_FLOAT16_VALUE(-0.26), SIMDE_FLOAT16_VALUE(1.88), SIMDE_FLOAT16_VALUE(-3.00), SIMDE_FLOAT16_VALUE(-4.73),
        SIMDE_FLOAT16_VALUE(-5.26), SIMDE_FLOAT16_VALUE(3.81), SIMDE_FLOAT16_VALUE(5.67), SIMDE_FLOAT16_VALUE(8.36) },
     {  SIMDE_FLOAT16_VALUE(-2.29), SIMDE_FLOAT16_VALUE(-8.62), SIMDE_FLOAT16_VALUE(9.46), SIMDE_FLOAT16_VALUE(-3.37),
        SIMDE_FLOAT16_VALUE(2.94), SIMDE_FLOAT16_VALUE(-5.91), SIMDE_FLOAT16_VALUE(-0.56), SIMDE_FLOAT16_VALUE(1.85) },
        SIMDE_FLOAT16_VALUE(-4.07),
     {  SIMDE_FLOAT16_VALUE(-9.56), SIMDE_FLOAT16_VALUE(-33.16), SIMDE_FLOAT16_VALUE(35.46), SIMDE_FLOAT16_VALUE(-18.41),
        SIMDE_FLOAT16_VALUE(6.71), SIMDE_FLOAT16_VALUE(-20.22), SIMDE_FLOAT16_VALUE(3.39), SIMDE_FLOAT16_VALUE(15.91) } },
   { {  SIMDE_FLOAT16_VALUE(-7.17), SIMDE_FLOAT16_VALUE(2.26), SIMDE_FLOAT16_VALUE(-4.52), SIMDE_FLOAT16_VALUE(-3.35),
        SIMDE_FLOAT16_VALUE(0.91), SIMDE_FLOAT16_VALUE(6.24), SIMDE_FLOAT16_VALUE(7.97), SIMDE_FLOAT16_VALUE(-2.56) },
     {  SIMDE_FLOAT16_VALUE(-6.02), SIMDE_FLOAT16_VALUE(-6.45), SIMDE_FLOAT16_VALUE(-0.61), SIMDE_FLOAT16_VALUE(-1.14),
        SIMDE_FLOAT16_VALUE(-1.96), SIMDE_FLOAT16_VALUE(6.05), SIMDE_FLOAT16_VALUE(1.48), SIMDE_FLOAT16_VALUE(3.90) },
        SIMDE_FLOAT16_VALUE(-3.01),
     {  SIMDE_FLOAT16_VALUE(-25.27), SIMDE_FLOAT16_VALUE(-17.14), SIMDE_FLOAT16_VALUE(-6.36), SIMDE_FLOAT16_VALUE(-6.77),
        SIMDE_FLOAT16_VALUE(-4.98), SIMDE_FLOAT16_VALUE(24.43), SIMDE_FLOAT16_VALUE(12.41), SIMDE_FLOAT16_VALUE(9.17) } },
   { {  SIMDE_FLOAT16_VALUE(7.80), SIMDE_FLOAT16_VALUE(5.47), SIMDE_FLOAT16_VALUE(-3.01), SIMDE_FLOAT16_VALUE(-9.75),
        SIMDE_FLOAT16_VALUE(7.74), SIMDE_FLOAT16_VALUE(2.65), SIMDE_FLOAT16_VALUE(2.24), SIMDE_FLOAT16_VALUE(6.66) },
     {  SIMDE_FLOAT16_VALUE(-3.26), SIMDE_FLOAT16_VALUE(6.55), SIMDE_FLOAT16_VALUE(4.39), SIMDE_FLOAT16_VALUE(2.46),
        SIMDE_FLOAT16_VALUE(5.08), SIMDE_FLOAT16_VALUE(-4.99), SIMDE_FLOAT16_VALUE(3.28), SIMDE_FLOAT16_VALUE(2.77) },
        SIMDE_FLOAT16_VALUE(-8.81),
     {  SIMDE_FLOAT16_VALUE(-20.90), SIMDE_FLOAT16_VALUE(63.19), SIMDE_FLOAT16_VALUE(35.66), SIMDE_FLOAT16_VALUE(11.96),
        SIMDE_FLOAT16_VALUE(52.54), SIMDE_FLOAT16_VALUE(-41.37), SIMDE_FLOAT16_VALUE(31.15), SIMDE_FLOAT16_VALUE(31.03) } },
   { {  SIMDE_FLOAT16_VALUE(6.93), SIMDE_FLOAT16_VALUE(9.09), SIMDE_FLOAT16_VALUE(-4.77), SIMDE_FLOAT16_VALUE(4.57),
        SIMDE_FLOAT16_VALUE(-7.31), SIMDE_FLOAT16_VALUE(9.96), SIMDE_FLOAT16_VALUE(-0.37), SIMDE_FLOAT16_VALUE(-9.60) },
     {  SIMDE_FLOAT16_VALUE(5.24), SIMDE_FLOAT16_VALUE(0.24), SIMDE_FLOAT16_VALUE(1.86), SIMDE_FLOAT16_VALUE(-5.77),
        SIMDE_FLOAT16_VALUE(7.31), SIMDE_FLOAT16_VALUE(4.13), SIMDE_FLOAT16_VALUE(5.84), SIMDE_FLOAT16_VALUE(-6.57) },
        SIMDE_FLOAT16_VALUE(7.40),
     {  SIMDE_FLOAT16_VALUE(-31.91), SIMDE_FLOAT16_VALUE(7.33), SIMDE_FLOAT16_VALUE(-18.57), SIMDE_FLOAT16_VALUE(47.32),
        SIMDE_FLOAT16_VALUE(-61.41), SIMDE_FLOAT16_VALUE(-20.61), SIMDE_FLOAT16_VALUE(-43.59), SIMDE_FLOAT16_VALUE(39.08) } },
   { {  SIMDE_FLOAT16_VALUE(-1.88), SIMDE_FLOAT16_VALUE(8.86), SIMDE_FLOAT16_VALUE(0.06), SIMDE_FLOAT16_VALUE(-10.00),
        SIMDE_FLOAT16_VALUE(-5.39), SIMDE_FLOAT16_VALUE(1.98), SIMDE_FLOAT16_VALUE(-0.77), SIMDE_FLOAT16_VALUE(-2.07) },
     {  SIMDE_FLOAT16_VALUE(9.69), SIMDE_FLOAT16_VALUE(6.76), SIMDE_FLOAT16_VALUE(-6.89), SIMDE_FLOAT16_VALUE(-8.13),
        SIMDE_FLOAT16_VALUE(1.66), SIMDE_FLOAT16_VALUE(-1.01), SIMDE_FLOAT16_VALUE(-7.80), SIMDE_FLOAT16_VALUE(-3.81) },
        SIMDE_FLOAT16_VALUE(-0.02),
     {  SIMDE_FLOAT16_VALUE(-1.72), SIMDE_FLOAT16_VALUE(8.97), SIMDE_FLOAT16_VALUE(-0.05), SIMDE_FLOAT16_VALUE(-10.13),
        SIMDE_FLOAT16_VALUE(-5.36), SIMDE_FLOAT16_VALUE(1.97), SIMDE_FLOAT16_VALUE(-0.90), SIMDE_FLOAT16_VALUE(-2.13) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16_t c = test_vec[i].c;
    simde_float16x8_t r = simde_vfmsq_n_f16(a, b, c);

    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfms_n_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 c;
    simde_float32 r[2];
  } test_vec[] = {
   { {  SIMDE_FLOAT32_C(-35.57796), SIMDE_FLOAT32_C(-59.85786) },
     {  SIMDE_FLOAT32_C(17.28136), SIMDE_FLOAT32_C(84.77423) },
        SIMDE_FLOAT32_C(-45.20424),
     {  SIMDE_FLOAT32_C(745.61292), SIMDE_FLOAT32_C(3772.29681) } },
   { {  SIMDE_FLOAT32_C(-17.99824), SIMDE_FLOAT32_C(30.49420) },
     {  SIMDE_FLOAT32_C(-20.95882), SIMDE_FLOAT32_C(25.34221) },
        SIMDE_FLOAT32_C(45.99718),
     {  SIMDE_FLOAT32_C(946.04844), SIMDE_FLOAT32_C(-1135.17594) } },
   { {  SIMDE_FLOAT32_C(62.43086), SIMDE_FLOAT32_C(-77.10995) },
     {  SIMDE_FLOAT32_C(9.37372), SIMDE_FLOAT32_C(99.88405) },
        SIMDE_FLOAT32_C(-86.22524),
     {  SIMDE_FLOAT32_C(870.68200), SIMDE_FLOAT32_C(8535.41651) } },
   { {  SIMDE_FLOAT32_C(99.02511), SIMDE_FLOAT32_C(72.49425) },
     {  SIMDE_FLOAT32_C(22.97394), SIMDE_FLOAT32_C(-52.48535) },
        SIMDE_FLOAT32_C(39.95098),
     {  SIMDE_FLOAT32_C(-818.80616), SIMDE_FLOAT32_C(2169.33519) } },
   { {  SIMDE_FLOAT32_C(41.76455), SIMDE_FLOAT32_C(-70.21716) },
     {  SIMDE_FLOAT32_C(-33.65310), SIMDE_FLOAT32_C(3.84507) },
        SIMDE_FLOAT32_C(56.99074),
     {  SIMDE_FLOAT32_C(1959.67983), SIMDE_FLOAT32_C(-289.35081) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32 c = test_vec[i].c;
    simde_float32x2_t r = simde_vfms_n_f32(a, b, c);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfms_n_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 c;
    simde_float64 r[1];
  } test_vec[] = {
   { {  SIMDE_FLOAT64_C(-337.20280) },
     {  SIMDE_FLOAT64_C(929.21901) },
        SIMDE_FLOAT64_C(-356.58915),
     {  SIMDE_FLOAT64_C(331012.21427) } },
   { {  SIMDE_FLOAT64_C(264.59177) },
     {  SIMDE_FLOAT64_C(46.08190) },
        SIMDE_FLOAT64_C(-602.18916),
     {  SIMDE_FLOAT64_C(28014.61335) } },
   { {  SIMDE_FLOAT64_C(-652.94501) },
     {  SIMDE_FLOAT64_C(83.67625) },
        SIMDE_FLOAT64_C(607.85645),
     {  SIMDE_FLOAT64_C(-51516.09546) } },
   { {  SIMDE_FLOAT64_C(-359.35028) },
     {  SIMDE_FLOAT64_C(-580.59986) },
        SIMDE_FLOAT64_C(254.44176),
     {  SIMDE_FLOAT64_C(147369.49847) } },
   { {  SIMDE_FLOAT64_C(952.75267) },
     {  SIMDE_FLOAT64_C(405.32469) },
        SIMDE_FLOAT64_C(781.41408),
     {  SIMDE_FLOAT64_C(-315773.66520) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64 c = test_vec[i].c;
    simde_float64x1_t r = simde_vfms_n_f64(a, b, c);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmsq_n_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 c;
    simde_float32 r[4];
  } test_vec[] = {
   { {  SIMDE_FLOAT32_C(-76.22244), SIMDE_FLOAT32_C(-7.91594), SIMDE_FLOAT32_C(-21.59222), SIMDE_FLOAT32_C(-84.47692) },
     {  SIMDE_FLOAT32_C(88.23311), SIMDE_FLOAT32_C(81.35067), SIMDE_FLOAT32_C(69.16915), SIMDE_FLOAT32_C(-74.96321) },
        SIMDE_FLOAT32_C(-18.21288),
     {  SIMDE_FLOAT32_C(1530.75616), SIMDE_FLOAT32_C(1473.71374), SIMDE_FLOAT32_C(1238.17683), SIMDE_FLOAT32_C(-1449.77260) } },
   { {  SIMDE_FLOAT32_C(75.52575), SIMDE_FLOAT32_C(-81.92949), SIMDE_FLOAT32_C(-11.90210), SIMDE_FLOAT32_C(87.65228) },
     {  SIMDE_FLOAT32_C(65.27611), SIMDE_FLOAT32_C(20.43275), SIMDE_FLOAT32_C(-1.91278), SIMDE_FLOAT32_C(-50.01227) },
        SIMDE_FLOAT32_C(0.51320),
     {  SIMDE_FLOAT32_C(42.02623), SIMDE_FLOAT32_C(-92.41553), SIMDE_FLOAT32_C(-10.92047), SIMDE_FLOAT32_C(113.31844) } },
   { {  SIMDE_FLOAT32_C(66.81045), SIMDE_FLOAT32_C(18.76226), SIMDE_FLOAT32_C(-56.30699), SIMDE_FLOAT32_C(-50.25232) },
     {  SIMDE_FLOAT32_C(75.53020), SIMDE_FLOAT32_C(45.16634), SIMDE_FLOAT32_C(-50.05386), SIMDE_FLOAT32_C(-97.11726) },
        SIMDE_FLOAT32_C(94.17368),
     {  SIMDE_FLOAT32_C(-7046.14671), SIMDE_FLOAT32_C(-4234.71828), SIMDE_FLOAT32_C(4657.44900), SIMDE_FLOAT32_C(9095.63779) } },
   { {  SIMDE_FLOAT32_C(-57.65770), SIMDE_FLOAT32_C(-33.06791), SIMDE_FLOAT32_C(68.12496), SIMDE_FLOAT32_C(-28.74269) },
     {  SIMDE_FLOAT32_C(99.08967), SIMDE_FLOAT32_C(-9.21892), SIMDE_FLOAT32_C(2.91902), SIMDE_FLOAT32_C(35.54978) },
        SIMDE_FLOAT32_C(-93.38670),
     {  SIMDE_FLOAT32_C(9195.99960), SIMDE_FLOAT32_C(-893.99220), SIMDE_FLOAT32_C(340.72239), SIMDE_FLOAT32_C(3291.13349) } },
   { {  SIMDE_FLOAT32_C(26.08616), SIMDE_FLOAT32_C(-31.72849), SIMDE_FLOAT32_C(19.87012), SIMDE_FLOAT32_C(96.24746) },
     {  SIMDE_FLOAT32_C(76.20837), SIMDE_FLOAT32_C(47.45190), SIMDE_FLOAT32_C(22.96593), SIMDE_FLOAT32_C(88.46029) },
        SIMDE_FLOAT32_C(-49.17426),
     {  SIMDE_FLOAT32_C(3773.57590), SIMDE_FLOAT32_C(2301.68334), SIMDE_FLOAT32_C(1149.20249), SIMDE_FLOAT32_C(4446.21640) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32 c = test_vec[i].c;
    simde_float32x4_t r = simde_vfmsq_n_f32(a, b, c);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmsq_n_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 c;
    simde_float64 r[2];
  } test_vec[] = {
   { {  SIMDE_FLOAT64_C(338.30974), SIMDE_FLOAT64_C(488.97921) },
     {  SIMDE_FLOAT64_C(-590.49049), SIMDE_FLOAT64_C(-185.60857) },
        SIMDE_FLOAT64_C(367.60822),
     {  SIMDE_FLOAT64_C(217407.47232), SIMDE_FLOAT64_C(68720.21765) } },
   { {  SIMDE_FLOAT64_C(-790.00195), SIMDE_FLOAT64_C(-762.94472) },
     {  SIMDE_FLOAT64_C(-496.73977), SIMDE_FLOAT64_C(86.61846) },
        SIMDE_FLOAT64_C(-65.57304),
     {  SIMDE_FLOAT64_C(-33362.73803), SIMDE_FLOAT64_C(4916.89121) } },
   { {  SIMDE_FLOAT64_C(235.45170), SIMDE_FLOAT64_C(-183.40964) },
     {  SIMDE_FLOAT64_C(-591.37023), SIMDE_FLOAT64_C(-176.48337) },
        SIMDE_FLOAT64_C(-197.75591),
     {  SIMDE_FLOAT64_C(-116711.50776), SIMDE_FLOAT64_C(-35084.04028) } },
   { {  SIMDE_FLOAT64_C(911.19764), SIMDE_FLOAT64_C(-667.08555) },
     {  SIMDE_FLOAT64_C(-241.31170), SIMDE_FLOAT64_C(-569.81857) },
        SIMDE_FLOAT64_C(-413.42624),
     {  SIMDE_FLOAT64_C(-98853.39065), SIMDE_FLOAT64_C(-236245.03073) } },
   { {  SIMDE_FLOAT64_C(173.38963), SIMDE_FLOAT64_C(-355.04043) },
     {  SIMDE_FLOAT64_C(471.15737), SIMDE_FLOAT64_C(779.68624) },
        SIMDE_FLOAT64_C(-562.91794),
     {  SIMDE_FLOAT64_C(265396.32192), SIMDE_FLOAT64_C(438544.33004) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64 c = test_vec[i].c;
    simde_float64x2_t r = simde_vfmsq_n_f64(a, b, c);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vfms_n_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfms_n_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vfms_n_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmsq_n_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmsq_n_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmsq_n_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
