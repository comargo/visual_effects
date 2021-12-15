/*
 * gradient_palettes.c
 *
 *  Created on: Dec 15, 2021
 *      Author: cyril
 */


#include "gradient_palettes.h"
#include "color_types.h"

// From ColorWavesWithPalettes by Mark Kriegsman: https://gist.github.com/kriegsman/8281905786e8b2632aeb

#define DEFINE_GRADIENT_PALETTE(Name) \
	const NRGB Name[] =
// Gradient Color Palette definitions for 33 different cpt-city color palettes.
//    956 bytes of PROGMEM for all of the palettes together,
//   +618 bytes of PROGMEM for gradient palette code (AVR).
//  1,494 bytes total for all 34 color palettes and associated code.

// Gradient palette "ib_jul01_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ing/xmas/tn/ib_jul01.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE( ib_jul01_gp ) {
  (NRGB){{0, 194,  1,  1}},
  (NRGB){{94,   1, 29, 18}},
  (NRGB){{132,  57, 131, 28}},
  (NRGB){{255, 113,  1,  1}}
};

// Gradient palette "es_vintage_57_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/vintage/tn/es_vintage_57.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_vintage_57_gp ) {
  (NRGB){{0,   2,  1,  1}},
  (NRGB){{53,  18,  1,  0}},
  (NRGB){{104,  69, 29,  1}},
  (NRGB){{153, 167, 135, 10}},
  (NRGB){{255,  46, 56,  4}}
};

// Gradient palette "es_vintage_01_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/vintage/tn/es_vintage_01.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_vintage_01_gp ) {
  (NRGB){{0,   4,  1,  1}},
  (NRGB){{51,  16,  0,  1}},
  (NRGB){{76,  97, 104,  3}},
  (NRGB){{101, 255, 131, 19}},
  (NRGB){{127,  67,  9,  4}},
  (NRGB){{153,  16,  0,  1}},
  (NRGB){{229,   4,  1,  1}},
  (NRGB){{255,   4,  1,  1}}
};

// Gradient palette "es_rivendell_15_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/rivendell/tn/es_rivendell_15.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_rivendell_15_gp ) {
  (NRGB){{0,   1, 14,  5}},
  (NRGB){{101,  16, 36, 14}},
  (NRGB){{165,  56, 68, 30}},
  (NRGB){{242, 150, 156, 99}},
  (NRGB){{255, 150, 156, 99}}
};

// Gradient palette "rgi_15_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds/rgi/tn/rgi_15.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 36 bytes of program space.

DEFINE_GRADIENT_PALETTE( rgi_15_gp ) {
  (NRGB){{0,   4,  1, 31}},
  (NRGB){{31,  55,  1, 16}},
  (NRGB){{63, 197,  3,  7}},
  (NRGB){{95,  59,  2, 17}},
  (NRGB){{127,   6,  2, 34}},
  (NRGB){{159,  39,  6, 33}},
  (NRGB){{191, 112, 13, 32}},
  (NRGB){{223,  56,  9, 35}},
  (NRGB){{255,  22,  6, 38}}
};

// Gradient palette "retro2_16_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ma/retro2/tn/retro2_16.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 8 bytes of program space.

DEFINE_GRADIENT_PALETTE( retro2_16_gp ) {
  (NRGB){{0, 188, 135,  1}},
  (NRGB){{255,  46,  7,  1}}
};

// Gradient palette "Analogous_1_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/red/tn/Analogous_1.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( Analogous_1_gp ) {
  (NRGB){{0,   3,  0, 255}},
  (NRGB){{63,  23,  0, 255}},
  (NRGB){{127,  67,  0, 255}},
  (NRGB){{191, 142,  0, 45}},
  (NRGB){{255, 255,  0,  0}}
};

// Gradient palette "es_pinksplash_08_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/pink_splash/tn/es_pinksplash_08.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_pinksplash_08_gp ) {
  (NRGB){{0, 126, 11, 255}},
  (NRGB){{127, 197,  1, 22}},
  (NRGB){{175, 210, 157, 172}},
  (NRGB){{221, 157,  3, 112}},
  (NRGB){{255, 157,  3, 112}}
};

// Gradient palette "es_pinksplash_07_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/pink_splash/tn/es_pinksplash_07.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_pinksplash_07_gp ) {
  (NRGB){{0, 229,  1,  1}},
  (NRGB){{61, 242,  4, 63}},
  (NRGB){{101, 255, 12, 255}},
  (NRGB){{127, 249, 81, 252}},
  (NRGB){{153, 255, 11, 235}},
  (NRGB){{193, 244,  5, 68}},
  (NRGB){{255, 232,  1,  5}}
};

// Gradient palette "Coral_reef_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/other/tn/Coral_reef.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( Coral_reef_gp ) {
  (NRGB){{0,  40, 199, 197}},
  (NRGB){{50,  10, 152, 155}},
  (NRGB){{96,   1, 111, 120}},
  (NRGB){{96,  43, 127, 162}},
  (NRGB){{139,  10, 73, 111}},
  (NRGB){{255,   1, 34, 71}}
};

// Gradient palette "es_ocean_breeze_068_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/ocean_breeze/tn/es_ocean_breeze_068.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_ocean_breeze_068_gp ) {
  (NRGB){{0, 100, 156, 153}},
  (NRGB){{51,   1, 99, 137}},
  (NRGB){{101,   1, 68, 84}},
  (NRGB){{104,  35, 142, 168}},
  (NRGB){{178,   0, 63, 117}},
  (NRGB){{255,   1, 10, 10}}
};

// Gradient palette "es_ocean_breeze_036_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/ocean_breeze/tn/es_ocean_breeze_036.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_ocean_breeze_036_gp ) {
  (NRGB){{0,   1,  6,  7}},
  (NRGB){{89,   1, 99, 111}},
  (NRGB){{153, 144, 209, 255}},
  (NRGB){{255,   0, 73, 82}}
};

// Gradient palette "departure_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/mjf/tn/departure.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 88 bytes of program space.

DEFINE_GRADIENT_PALETTE( departure_gp ) {
  (NRGB){{0,   8,  3,  0}},
  (NRGB){{42,  23,  7,  0}},
  (NRGB){{63,  75, 38,  6}},
  (NRGB){{84, 169, 99, 38}},
  (NRGB){{106, 213, 169, 119}},
  (NRGB){{116, 255, 255, 255}},
  (NRGB){{138, 135, 255, 138}},
  (NRGB){{148,  22, 255, 24}},
  (NRGB){{170,   0, 255,  0}},
  (NRGB){{191,   0, 136,  0}},
  (NRGB){{212,   0, 55,  0}},
  (NRGB){{255,   0, 55,  0}}
};

// Gradient palette "es_landscape_64_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/landscape/tn/es_landscape_64.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 36 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_landscape_64_gp ) {
  (NRGB){{0,   0,  0,  0}},
  (NRGB){{37,   2, 25,  1}},
  (NRGB){{76,  15, 115,  5}},
  (NRGB){{127,  79, 213,  1}},
  (NRGB){{128, 126, 211, 47}},
  (NRGB){{130, 188, 209, 247}},
  (NRGB){{153, 144, 182, 205}},
  (NRGB){{204,  59, 117, 250}},
  (NRGB){{255,   1, 37, 192}}
};

// Gradient palette "es_landscape_33_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/landscape/tn/es_landscape_33.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_landscape_33_gp ) {
  (NRGB){{0,   1,  5,  0}},
  (NRGB){{19,  32, 23,  1}},
  (NRGB){{38, 161, 55,  1}},
  (NRGB){{63, 229, 144,  1}},
  (NRGB){{66,  39, 142, 74}},
  (NRGB){{255,   1,  4,  1}}
};

// Gradient palette "rainbowsherbet_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ma/icecream/tn/rainbowsherbet.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( rainbowsherbet_gp ) {
  (NRGB){{0, 255, 33,  4}},
  (NRGB){{43, 255, 68, 25}},
  (NRGB){{86, 255,  7, 25}},
  (NRGB){{127, 255, 82, 103}},
  (NRGB){{170, 255, 255, 242}},
  (NRGB){{209,  42, 255, 22}},
  (NRGB){{255,  87, 255, 65}}
};

// Gradient palette "gr65_hult_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/hult/tn/gr65_hult.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( gr65_hult_gp ) {
  (NRGB){{0, 247, 176, 247}},
  (NRGB){{48, 255, 136, 255}},
  (NRGB){{89, 220, 29, 226}},
  (NRGB){{160,   7, 82, 178}},
  (NRGB){{216,   1, 124, 109}},
  (NRGB){{255,   1, 124, 109}}
};

// Gradient palette "gr64_hult_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/hult/tn/gr64_hult.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE( gr64_hult_gp ) {
  (NRGB){{0,   1, 124, 109}},
  (NRGB){{66,   1, 93, 79}},
  (NRGB){{104,  52, 65,  1}},
  (NRGB){{130, 115, 127,  1}},
  (NRGB){{150,  52, 65,  1}},
  (NRGB){{201,   1, 86, 72}},
  (NRGB){{239,   0, 55, 45}},
  (NRGB){{255,   0, 55, 45}}
};

// Gradient palette "GMT_drywet_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/gmt/tn/GMT_drywet.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( GMT_drywet_gp ) {
  (NRGB){{0,  47, 30,  2}},
  (NRGB){{42, 213, 147, 24}},
  (NRGB){{84, 103, 219, 52}},
  (NRGB){{127,   3, 219, 207}},
  (NRGB){{170,   1, 48, 214}},
  (NRGB){{212,   1,  1, 111}},
  (NRGB){{255,   1,  7, 33}}
};

// Gradient palette "ib15_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ing/general/tn/ib15.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( ib15_gp ) {
  (NRGB){{0, 113, 91, 147}},
  (NRGB){{72, 157, 88, 78}},
  (NRGB){{89, 208, 85, 33}},
  (NRGB){{107, 255, 29, 11}},
  (NRGB){{141, 137, 31, 39}},
  (NRGB){{255,  59, 33, 89}}
};

// Gradient palette "Fuschia_7_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/ds/fuschia/tn/Fuschia-7.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( Fuschia_7_gp ) {
  (NRGB){{0,  43,  3, 153}},
  (NRGB){{63, 100,  4, 103}},
  (NRGB){{127, 188,  5, 66}},
  (NRGB){{191, 161, 11, 115}},
  (NRGB){{255, 135, 20, 182}}
};

// Gradient palette "es_emerald_dragon_08_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/emerald_dragon/tn/es_emerald_dragon_08.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_emerald_dragon_08_gp ) {
  (NRGB){{0,  97, 255,  1}},
  (NRGB){{101,  47, 133,  1}},
  (NRGB){{178,  13, 43,  1}},
  (NRGB){{255,   2, 10,  1}}
};

// Gradient palette "lava_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/neota/elem/tn/lava.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 52 bytes of program space.

DEFINE_GRADIENT_PALETTE( lava_gp ) {
  (NRGB){{0,   0,  0,  0}},
  (NRGB){{46,  18,  0,  0}},
  (NRGB){{96, 113,  0,  0}},
  (NRGB){{108, 142,  3,  1}},
  (NRGB){{119, 175, 17,  1}},
  (NRGB){{146, 213, 44,  2}},
  (NRGB){{174, 255, 82,  4}},
  (NRGB){{188, 255, 115,  4}},
  (NRGB){{202, 255, 156,  4}},
  (NRGB){{218, 255, 203,  4}},
  (NRGB){{234, 255, 255,  4}},
  (NRGB){{244, 255, 255, 71}},
  (NRGB){{255, 255, 255, 255}}
};

// Gradient palette "fire_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/neota/elem/tn/fire.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( fire_gp ) {
  (NRGB){{0,   1,  1,  0}},
  (NRGB){{76,  32,  5,  0}},
  (NRGB){{146, 192, 24,  0}},
  (NRGB){{197, 220, 105,  5}},
  (NRGB){{240, 252, 255, 31}},
  (NRGB){{250, 252, 255, 111}},
  (NRGB){{255, 255, 255, 255}}
};

// Gradient palette "Colorfull_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/atmospheric/tn/Colorfull.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 44 bytes of program space.

DEFINE_GRADIENT_PALETTE( Colorfull_gp ) {
  (NRGB){{0,  10, 85,  5}},
  (NRGB){{25,  29, 109, 18}},
  (NRGB){{60,  59, 138, 42}},
  (NRGB){{93,  83, 99, 52}},
  (NRGB){{106, 110, 66, 64}},
  (NRGB){{109, 123, 49, 65}},
  (NRGB){{113, 139, 35, 66}},
  (NRGB){{116, 192, 117, 98}},
  (NRGB){{124, 255, 255, 137}},
  (NRGB){{168, 100, 180, 155}},
  (NRGB){{255,  22, 121, 174}}
};

// Gradient palette "Magenta_Evening_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/atmospheric/tn/Magenta_Evening.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( Magenta_Evening_gp ) {
  (NRGB){{0,  71, 27, 39}},
  (NRGB){{31, 130, 11, 51}},
  (NRGB){{63, 213,  2, 64}},
  (NRGB){{70, 232,  1, 66}},
  (NRGB){{76, 252,  1, 69}},
  (NRGB){{108, 123,  2, 51}},
  (NRGB){{255,  46,  9, 35}}
};

// Gradient palette "Pink_Purple_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/atmospheric/tn/Pink_Purple.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 44 bytes of program space.

DEFINE_GRADIENT_PALETTE( Pink_Purple_gp ) {
  (NRGB){{0,  19,  2, 39}},
  (NRGB){{25,  26,  4, 45}},
  (NRGB){{51,  33,  6, 52}},
  (NRGB){{76,  68, 62, 125}},
  (NRGB){{102, 118, 187, 240}},
  (NRGB){{109, 163, 215, 247}},
  (NRGB){{114, 217, 244, 255}},
  (NRGB){{122, 159, 149, 221}},
  (NRGB){{149, 113, 78, 188}},
  (NRGB){{183, 128, 57, 155}},
  (NRGB){{255, 146, 40, 123}}
};

// Gradient palette "Sunset_Real_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/atmospheric/tn/Sunset_Real.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( Sunset_Real_gp ) {
  (NRGB){{0, 120,  0,  0}},
  (NRGB){{22, 179, 22,  0}},
  (NRGB){{51, 255, 104,  0}},
  (NRGB){{85, 167, 22, 18}},
  (NRGB){{135, 100,  0, 103}},
  (NRGB){{198,  16,  0, 130}},
  (NRGB){{255,   0,  0, 160}}
};

// Gradient palette "es_autumn_19_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/es/autumn/tn/es_autumn_19.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 52 bytes of program space.

DEFINE_GRADIENT_PALETTE( es_autumn_19_gp ) {
  (NRGB){{0,  26,  1,  1}},
  (NRGB){{51,  67,  4,  1}},
  (NRGB){{84, 118, 14,  1}},
  (NRGB){{104, 137, 152, 52}},
  (NRGB){{112, 113, 65,  1}},
  (NRGB){{122, 133, 149, 59}},
  (NRGB){{124, 137, 152, 52}},
  (NRGB){{135, 113, 65,  1}},
  (NRGB){{142, 139, 154, 46}},
  (NRGB){{163, 113, 13,  1}},
  (NRGB){{204,  55,  3,  1}},
  (NRGB){{249,  17,  1,  1}},
  (NRGB){{255,  17,  1,  1}}
};

// Gradient palette "BlacK_Blue_Magenta_White_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/basic/tn/BlacK_Blue_Magenta_White.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( BlacK_Blue_Magenta_White_gp ) {
  (NRGB){{0,   0,  0,  0}},
  (NRGB){{42,   0,  0, 45}},
  (NRGB){{84,   0,  0, 255}},
  (NRGB){{127,  42,  0, 255}},
  (NRGB){{170, 255,  0, 255}},
  (NRGB){{212, 255, 55, 255}},
  (NRGB){{255, 255, 255, 255}}
};

// Gradient palette "BlacK_Magenta_Red_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/basic/tn/BlacK_Magenta_Red.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( BlacK_Magenta_Red_gp ) {
  (NRGB){{0,   0,  0,  0}},
  (NRGB){{63,  42,  0, 45}},
  (NRGB){{127, 255,  0, 255}},
  (NRGB){{191, 255,  0, 45}},
  (NRGB){{255, 255,  0,  0}}
};

// Gradient palette "BlacK_Red_Magenta_Yellow_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/basic/tn/BlacK_Red_Magenta_Yellow.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( BlacK_Red_Magenta_Yellow_gp ) {
  (NRGB){{0,   0,  0,  0}},
  (NRGB){{42,  42,  0,  0}},
  (NRGB){{84, 255,  0,  0}},
  (NRGB){{127, 255,  0, 45}},
  (NRGB){{170, 255,  0, 255}},
  (NRGB){{212, 255, 55, 45}},
  (NRGB){{255, 255, 255,  0}}
};

// Gradient palette "Blue_Cyan_Yellow_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/nd/basic/tn/Blue_Cyan_Yellow.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( Blue_Cyan_Yellow_gp ) {
  (NRGB){{0,   0,  0, 255}},
  (NRGB){{63,   0, 55, 255}},
  (NRGB){{127,   0, 255, 255}},
  (NRGB){{191,  42, 255, 45}},
  (NRGB){{255, 255, 255,  0}}
};

// Gradient palette "bhw1_28_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_28.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE( bhw1_28_gp ) {
  (NRGB){{0,  75,  1, 221}},
  (NRGB){{30, 252, 73, 255}},
  (NRGB){{48, 169,  0, 242}},
  (NRGB){{119,   0, 149, 242}},
  (NRGB){{170,  43,  0, 242}},
  (NRGB){{206, 252, 73, 255}},
  (NRGB){{232,  78, 12, 214}},
  (NRGB){{255,   0, 149, 242}}
};
