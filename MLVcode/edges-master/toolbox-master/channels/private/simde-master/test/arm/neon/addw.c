#define SIMDE_TEST_ARM_NEON_INSN addw

#include "test-neon.h"
#include "../../../simde/arm/neon/addw.h"

static int
test_simde_vaddw_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int8_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(  1399), -INT16_C( 17500), -INT16_C( 22993), -INT16_C( 21510),  INT16_C( 23499),  INT16_C(  6907),  INT16_C( 18650), -INT16_C( 25560) },
      { -INT8_C(  17),  INT8_C(  18), -INT8_C(  39), -INT8_C(  77),  INT8_C(  69),  INT8_C(  53),  INT8_C(  99),  INT8_C( 113) },
      {  INT16_C(  1382), -INT16_C( 17482), -INT16_C( 23032), -INT16_C( 21587),  INT16_C( 23568),  INT16_C(  6960),  INT16_C( 18749), -INT16_C( 25447) } },
    { {  INT16_C(  2134), -INT16_C( 30371),  INT16_C(  8145),  INT16_C( 18599),  INT16_C( 19236),  INT16_C( 21252), -INT16_C(   271), -INT16_C( 16898) },
      {  INT8_C(  89), -INT8_C(   7), -INT8_C(  41),  INT8_C(  51),  INT8_C(  65),  INT8_C(   0), -INT8_C(  49),  INT8_C(  49) },
      {  INT16_C(  2223), -INT16_C( 30378),  INT16_C(  8104),  INT16_C( 18650),  INT16_C( 19301),  INT16_C( 21252), -INT16_C(   320), -INT16_C( 16849) } },
    { { -INT16_C( 22254),  INT16_C( 22500),  INT16_C( 18398),  INT16_C( 13768),  INT16_C(  9807),  INT16_C(  8638),  INT16_C( 25925),  INT16_C( 27241) },
      { -INT8_C(  80),  INT8_C( 109), -INT8_C(  67), -INT8_C(  94),  INT8_C( 108), -INT8_C(  68),  INT8_C(  95), -INT8_C(  59) },
      { -INT16_C( 22334),  INT16_C( 22609),  INT16_C( 18331),  INT16_C( 13674),  INT16_C(  9915),  INT16_C(  8570),  INT16_C( 26020),  INT16_C( 27182) } },
    { {  INT16_C( 14005), -INT16_C(  2055), -INT16_C( 14282),  INT16_C( 18472),  INT16_C(  3185),  INT16_C( 20639),  INT16_C( 26707), -INT16_C( 23931) },
      { -INT8_C( 114),  INT8_C(  67), -INT8_C(  61), -INT8_C(  45), -INT8_C(  87),  INT8_C(  45),  INT8_C(  61),  INT8_C(  89) },
      {  INT16_C( 13891), -INT16_C(  1988), -INT16_C( 14343),  INT16_C( 18427),  INT16_C(  3098),  INT16_C( 20684),  INT16_C( 26768), -INT16_C( 23842) } },
    { { -INT16_C(  1126),  INT16_C(  1787),  INT16_C( 23223),  INT16_C( 27852), -INT16_C( 14959), -INT16_C( 14493), -INT16_C( 29811), -INT16_C(   240) },
      { -INT8_C( 105), -INT8_C(  81),  INT8_C(  79), -INT8_C(  22),  INT8_C(  23), -INT8_C(  44), -INT8_C( 115), -INT8_C(  91) },
      { -INT16_C(  1231),  INT16_C(  1706),  INT16_C( 23302),  INT16_C( 27830), -INT16_C( 14936), -INT16_C( 14537), -INT16_C( 29926), -INT16_C(   331) } },
    { {  INT16_C( 20503), -INT16_C( 16263), -INT16_C( 18819),  INT16_C(  6170),  INT16_C(  5553),  INT16_C( 26654), -INT16_C(  5520),  INT16_C(   469) },
      { -INT8_C(  81),  INT8_C(  56), -INT8_C(  56),  INT8_C(  61), -INT8_C(  60), -INT8_C(  40),  INT8_C(  60),  INT8_C(  91) },
      {  INT16_C( 20422), -INT16_C( 16207), -INT16_C( 18875),  INT16_C(  6231),  INT16_C(  5493),  INT16_C( 26614), -INT16_C(  5460),  INT16_C(   560) } },
    { { -INT16_C( 29816), -INT16_C( 24762), -INT16_C( 11425),  INT16_C( 30277), -INT16_C( 16861), -INT16_C( 24265),  INT16_C( 20852),  INT16_C(  9913) },
      {  INT8_C( 102), -INT8_C(  41), -INT8_C( 114), -INT8_C(  42), -INT8_C(  62),  INT8_C(  99), -INT8_C(  41),  INT8_C( 113) },
      { -INT16_C( 29714), -INT16_C( 24803), -INT16_C( 11539),  INT16_C( 30235), -INT16_C( 16923), -INT16_C( 24166),  INT16_C( 20811),  INT16_C( 10026) } },
    { { -INT16_C( 24420),  INT16_C( 24750), -INT16_C(  5512),  INT16_C(   187),  INT16_C(   373), -INT16_C( 11104), -INT16_C(  6700), -INT16_C(  1973) },
      { -INT8_C(  93), -INT8_C( 126), -INT8_C( 103),  INT8_C(  23), -INT8_C(  45),  INT8_C(  82),  INT8_C(  61),  INT8_C(  57) },
      { -INT16_C( 24513),  INT16_C( 24624), -INT16_C(  5615),  INT16_C(   210),  INT16_C(   328), -INT16_C( 11022), -INT16_C(  6639), -INT16_C(  1916) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int16x8_t r = simde_vaddw_s8(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddw_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int16_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1388212854), -INT32_C(   137385825), -INT32_C(  2114199091), -INT32_C(  1388281654) },
      { -INT16_C( 16021),  INT16_C( 14313),  INT16_C(  1415),  INT16_C( 13855) },
      { -INT32_C(  1388228875), -INT32_C(   137371512), -INT32_C(  2114197676), -INT32_C(  1388267799) } },
    { {  INT32_C(  1434567342),  INT32_C(   335417737),  INT32_C(  1052852126), -INT32_C(  1271557913) },
      {  INT16_C( 12401),  INT16_C( 15157),  INT16_C( 30129),  INT16_C(  7401) },
      {  INT32_C(  1434579743),  INT32_C(   335432894),  INT32_C(  1052882255), -INT32_C(  1271550512) } },
    { { -INT32_C(  1101802954), -INT32_C(  2030799912), -INT32_C(  1092913867),  INT32_C(   617798022) },
      { -INT16_C( 27880), -INT16_C(   158), -INT16_C( 26845), -INT16_C( 27469) },
      { -INT32_C(  1101830834), -INT32_C(  2030800070), -INT32_C(  1092940712),  INT32_C(   617770553) } },
    { {  INT32_C(  2043734216), -INT32_C(  1802127010),  INT32_C(  1666378123), -INT32_C(  1846917540) },
      { -INT16_C( 14917),  INT16_C( 16719),  INT16_C(  8607), -INT16_C( 18586) },
      {  INT32_C(  2043719299), -INT32_C(  1802110291),  INT32_C(  1666386730), -INT32_C(  1846936126) } },
    { { -INT32_C(   675821388),  INT32_C(   678193760), -INT32_C(  1314833325), -INT32_C(  2142947595) },
      { -INT16_C( 26593),  INT16_C( 31716), -INT16_C( 12578), -INT16_C( 26100) },
      { -INT32_C(   675847981),  INT32_C(   678225476), -INT32_C(  1314845903), -INT32_C(  2142973695) } },
    { {  INT32_C(   853236883),  INT32_C(   854212989),  INT32_C(  1779015946),  INT32_C(  1586656523) },
      {  INT16_C( 13233), -INT16_C( 23025),  INT16_C( 21865), -INT16_C( 30425) },
      {  INT32_C(   853250116),  INT32_C(   854189964),  INT32_C(  1779037811),  INT32_C(  1586626098) } },
    { { -INT32_C(   888927251),  INT32_C(  1818563033), -INT32_C(   358661779), -INT32_C(  1944286846) },
      {  INT16_C(  9770),  INT16_C( 13814), -INT16_C( 30565),  INT16_C( 19860) },
      { -INT32_C(   888917481),  INT32_C(  1818576847), -INT32_C(   358692344), -INT32_C(  1944266986) } },
    { {  INT32_C(   636724155), -INT32_C(   441574664), -INT32_C(    21908955),  INT32_C(   812324547) },
      {  INT16_C(  2647), -INT16_C(  9701),  INT16_C( 14227), -INT16_C( 17050) },
      {  INT32_C(   636726802), -INT32_C(   441584365), -INT32_C(    21894728),  INT32_C(   812307497) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int32x4_t r = simde_vaddw_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddw_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int32_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C(   35941828180514250), -INT64_C( 3275167048482511539) },
      {  INT32_C(  1164837346),  INT32_C(   810152381) },
      { -INT64_C(   35941827015676904), -INT64_C( 3275167047672359158) } },
    { {  INT64_C( 7520367280355497394), -INT64_C( 5568442117108591200) },
      {  INT32_C(  2092554896),  INT32_C(    21972255) },
      {  INT64_C( 7520367282448052290), -INT64_C( 5568442117086618945) } },
    { {  INT64_C( 6932324803500490054), -INT64_C( 7385863836118137883) },
      { -INT32_C(  1655510216),  INT32_C(  1716456406) },
      {  INT64_C( 6932324801844979838), -INT64_C( 7385863834401681477) } },
    { { -INT64_C( 7780757470541838107), -INT64_C( 4468190007372788497) },
      {  INT32_C(   148488975),  INT32_C(   513891046) },
      { -INT64_C( 7780757470393349132), -INT64_C( 4468190006858897451) } },
    { { -INT64_C( 1981007695762885563), -INT64_C( 8721521294389451500) },
      {  INT32_C(   371429178),  INT32_C(  1809326171) },
      { -INT64_C( 1981007695391456385), -INT64_C( 8721521292580125329) } },
    { {  INT64_C( 5901990452037661155), -INT64_C( 4328821606770170871) },
      { -INT32_C(   333064875), -INT32_C(    26010428) },
      {  INT64_C( 5901990451704596280), -INT64_C( 4328821606796181299) } },
    { { -INT64_C( 7317806549163469141),  INT64_C(  286907640752432542) },
      { -INT32_C(  1626642192), -INT32_C(  1402734761) },
      { -INT64_C( 7317806550790111333),  INT64_C(  286907639349697781) } },
    { {  INT64_C( 5732814751622858957),  INT64_C( 3527663835220976802) },
      { -INT32_C(  1495639892), -INT32_C(  1800809052) },
      {  INT64_C( 5732814750127219065),  INT64_C( 3527663833420167750) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int64x2_t r = simde_vaddw_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddw_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint8_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(10834), UINT16_C(14742), UINT16_C(18794), UINT16_C(53447), UINT16_C(64764), UINT16_C(23788), UINT16_C( 4099), UINT16_C(38745) },
      { UINT8_C(208), UINT8_C(229), UINT8_C( 91), UINT8_C(123), UINT8_C( 81), UINT8_C(202), UINT8_C( 74), UINT8_C(  0) },
      { UINT16_C(11042), UINT16_C(14971), UINT16_C(18885), UINT16_C(53570), UINT16_C(64845), UINT16_C(23990), UINT16_C( 4173), UINT16_C(38745) } },
    { { UINT16_C( 1758), UINT16_C(13153), UINT16_C(29583), UINT16_C(57738), UINT16_C( 8349), UINT16_C( 1818), UINT16_C(57962), UINT16_C(26327) },
      { UINT8_C(222), UINT8_C(195), UINT8_C(194), UINT8_C(225), UINT8_C(211), UINT8_C( 28), UINT8_C(120), UINT8_C(164) },
      { UINT16_C( 1980), UINT16_C(13348), UINT16_C(29777), UINT16_C(57963), UINT16_C( 8560), UINT16_C( 1846), UINT16_C(58082), UINT16_C(26491) } },
    { { UINT16_C(54017), UINT16_C(21023), UINT16_C(27038), UINT16_C(31827), UINT16_C(46191), UINT16_C(65199), UINT16_C(14631), UINT16_C(50400) },
      { UINT8_C( 90), UINT8_C(250), UINT8_C(203), UINT8_C(196), UINT8_C(220), UINT8_C(162), UINT8_C( 42), UINT8_C(186) },
      { UINT16_C(54107), UINT16_C(21273), UINT16_C(27241), UINT16_C(32023), UINT16_C(46411), UINT16_C(65361), UINT16_C(14673), UINT16_C(50586) } },
    { { UINT16_C(60518), UINT16_C(14747), UINT16_C( 4872), UINT16_C( 2781), UINT16_C(64999), UINT16_C(34140), UINT16_C(44902), UINT16_C(54785) },
      { UINT8_C( 99), UINT8_C(177), UINT8_C(212), UINT8_C(138), UINT8_C(234), UINT8_C(180), UINT8_C( 78), UINT8_C( 68) },
      { UINT16_C(60617), UINT16_C(14924), UINT16_C( 5084), UINT16_C( 2919), UINT16_C(65233), UINT16_C(34320), UINT16_C(44980), UINT16_C(54853) } },
    { { UINT16_C( 6575), UINT16_C(35592), UINT16_C(12988), UINT16_C( 8774), UINT16_C(57631), UINT16_C(10075), UINT16_C(14837), UINT16_C(56369) },
      { UINT8_C( 54), UINT8_C(142), UINT8_C( 97), UINT8_C(156), UINT8_C( 61), UINT8_C( 98), UINT8_C(114), UINT8_C(161) },
      { UINT16_C( 6629), UINT16_C(35734), UINT16_C(13085), UINT16_C( 8930), UINT16_C(57692), UINT16_C(10173), UINT16_C(14951), UINT16_C(56530) } },
    { { UINT16_C(18195), UINT16_C(65067), UINT16_C(31483), UINT16_C(43586), UINT16_C(19347), UINT16_C(20278), UINT16_C(31869), UINT16_C(40049) },
      { UINT8_C( 93), UINT8_C(205), UINT8_C(196), UINT8_C( 82), UINT8_C(  6), UINT8_C(245), UINT8_C( 46), UINT8_C( 60) },
      { UINT16_C(18288), UINT16_C(65272), UINT16_C(31679), UINT16_C(43668), UINT16_C(19353), UINT16_C(20523), UINT16_C(31915), UINT16_C(40109) } },
    { { UINT16_C(36739), UINT16_C(49624), UINT16_C(19442), UINT16_C( 1378), UINT16_C(36242), UINT16_C(36099), UINT16_C(17927), UINT16_C(39736) },
      { UINT8_C(145), UINT8_C(110), UINT8_C(234), UINT8_C( 14), UINT8_C(234), UINT8_C( 92), UINT8_C(171), UINT8_C( 71) },
      { UINT16_C(36884), UINT16_C(49734), UINT16_C(19676), UINT16_C( 1392), UINT16_C(36476), UINT16_C(36191), UINT16_C(18098), UINT16_C(39807) } },
    { { UINT16_C(28457), UINT16_C(12186), UINT16_C(51300), UINT16_C(59499), UINT16_C(17240), UINT16_C(19113), UINT16_C( 2958), UINT16_C( 8271) },
      { UINT8_C(152), UINT8_C( 83), UINT8_C(174), UINT8_C(160), UINT8_C(153), UINT8_C(230), UINT8_C( 59), UINT8_C( 42) },
      { UINT16_C(28609), UINT16_C(12269), UINT16_C(51474), UINT16_C(59659), UINT16_C(17393), UINT16_C(19343), UINT16_C( 3017), UINT16_C( 8313) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint16x8_t r = simde_vaddw_u8(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddw_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint16_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 125494402), UINT32_C(3611639350), UINT32_C(3234195889), UINT32_C( 286950810) },
      { UINT16_C(45973), UINT16_C(17753), UINT16_C(40022), UINT16_C(16530) },
      { UINT32_C( 125540375), UINT32_C(3611657103), UINT32_C(3234235911), UINT32_C( 286967340) } },
    { { UINT32_C(4019197649), UINT32_C(1265827017), UINT32_C( 374598880), UINT32_C(3689846826) },
      { UINT16_C(45953), UINT16_C( 7068), UINT16_C(46649), UINT16_C(52780) },
      { UINT32_C(4019243602), UINT32_C(1265834085), UINT32_C( 374645529), UINT32_C(3689899606) } },
    { { UINT32_C(3222504809), UINT32_C(4076905762), UINT32_C(2246218171), UINT32_C(1842369677) },
      { UINT16_C( 9024), UINT16_C(27267), UINT16_C(29115), UINT16_C(15430) },
      { UINT32_C(3222513833), UINT32_C(4076933029), UINT32_C(2246247286), UINT32_C(1842385107) } },
    { { UINT32_C(1582817829), UINT32_C(  36471704), UINT32_C( 734150409), UINT32_C(2686370532) },
      { UINT16_C(   83), UINT16_C(57381), UINT16_C(62805), UINT16_C(38221) },
      { UINT32_C(1582817912), UINT32_C(  36529085), UINT32_C( 734213214), UINT32_C(2686408753) } },
    { { UINT32_C(3556823321), UINT32_C(1729185346), UINT32_C(3234162728), UINT32_C(4123193836) },
      { UINT16_C(33840), UINT16_C( 5408), UINT16_C(15943), UINT16_C(39605) },
      { UINT32_C(3556857161), UINT32_C(1729190754), UINT32_C(3234178671), UINT32_C(4123233441) } },
    { { UINT32_C(2474367550), UINT32_C(3895052495), UINT32_C(3703384473), UINT32_C(2537803375) },
      { UINT16_C( 2358), UINT16_C( 8791), UINT16_C( 6906), UINT16_C(11031) },
      { UINT32_C(2474369908), UINT32_C(3895061286), UINT32_C(3703391379), UINT32_C(2537814406) } },
    { { UINT32_C(3846191006), UINT32_C(3028350325), UINT32_C(2655517647), UINT32_C(1569157315) },
      { UINT16_C(17561), UINT16_C( 2105), UINT16_C(31762), UINT16_C(18591) },
      { UINT32_C(3846208567), UINT32_C(3028352430), UINT32_C(2655549409), UINT32_C(1569175906) } },
    { { UINT32_C(2154559365), UINT32_C(2947252753), UINT32_C( 798354362), UINT32_C(2950895072) },
      { UINT16_C(11024), UINT16_C(54093), UINT16_C(54427), UINT16_C(13616) },
      { UINT32_C(2154570389), UINT32_C(2947306846), UINT32_C( 798408789), UINT32_C(2950908688) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint32x4_t r = simde_vaddw_u16(a, b);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddw_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    uint32_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(18246032550608320754), UINT64_C( 5491972490029369669) },
      { UINT32_C(2534732259), UINT32_C(4282430487) },
      { UINT64_C(18246032553143053013), UINT64_C( 5491972494311800156) } },
    { { UINT64_C( 6488175683242448873), UINT64_C( 8558374424049239001) },
      { UINT32_C(1597976701), UINT32_C(2074834583) },
      { UINT64_C( 6488175684840425574), UINT64_C( 8558374426124073584) } },
    { { UINT64_C( 6664856254073192296), UINT64_C(17829150720575962538) },
      { UINT32_C(1405070114), UINT32_C(2647229471) },
      { UINT64_C( 6664856255478262410), UINT64_C(17829150723223192009) } },
    { { UINT64_C(16701501908321044661), UINT64_C(15507834351980567142) },
      { UINT32_C(2162756194), UINT32_C( 175593192) },
      { UINT64_C(16701501910483800855), UINT64_C(15507834352156160334) } },
    { { UINT64_C( 8123974462495078145), UINT64_C(14381546540155910703) },
      { UINT32_C(2342583390), UINT32_C(1130551009) },
      { UINT64_C( 8123974464837661535), UINT64_C(14381546541286461712) } },
    { { UINT64_C(11876901113150262496), UINT64_C( 9772111181212103025) },
      { UINT32_C(2654362173), UINT32_C(1030081503) },
      { UINT64_C(11876901115804624669), UINT64_C( 9772111182242184528) } },
    { { UINT64_C(13613022525382002119), UINT64_C( 6538762566695759479) },
      { UINT32_C(3800531850), UINT32_C(1130964230) },
      { UINT64_C(13613022529182533969), UINT64_C( 6538762567826723709) } },
    { { UINT64_C( 3646867225230548863), UINT64_C(  640855369439733067) },
      { UINT32_C(1579313525), UINT32_C(1287184578) },
      { UINT64_C( 3646867226809862388), UINT64_C(  640855370726917645) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint64x2_t r = simde_vaddw_u32(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vaddw_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddw_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddw_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddw_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddw_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddw_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
