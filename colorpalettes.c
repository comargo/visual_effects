/*
 * colorpalettes.c
 *
 *  Created on: Dec 15, 2021
 *      Author: cyril
 */


#include "color_types.h"
#include "colorpalettes.h"

#include "html_colors.h"

// Preset color schemes, such as they are.

// These schemes are all declared as "PROGMEM", meaning
// that they won't take up SRAM on AVR chips until used.
// Furthermore, the compiler won't even include these
// in your PROGMEM (flash) storage unless you specifically
// use each one, so you only 'pay for' those you actually use.


const RGB CloudColors_p[16] =
{
    RGB_Blue,
    RGB_DarkBlue,
    RGB_DarkBlue,
    RGB_DarkBlue,

    RGB_DarkBlue,
    RGB_DarkBlue,
    RGB_DarkBlue,
    RGB_DarkBlue,

    RGB_Blue,
    RGB_DarkBlue,
    RGB_SkyBlue,
    RGB_SkyBlue,

    RGB_LightBlue,
    RGB_White,
    RGB_LightBlue,
    RGB_SkyBlue
};

const RGB LavaColors_p[16] =
{
    RGB_Black,
    RGB_Maroon,
    RGB_Black,
    RGB_Maroon,

    RGB_DarkRed,
    RGB_Maroon,
    RGB_DarkRed,

    RGB_DarkRed,
    RGB_DarkRed,
    RGB_Red,
    RGB_Orange,

    RGB_White,
    RGB_Orange,
    RGB_Red,
    RGB_DarkRed
};


const RGB OceanColors_p[16] =
{
    RGB_MidnightBlue,
    RGB_DarkBlue,
    RGB_MidnightBlue,
    RGB_Navy,

    RGB_DarkBlue,
    RGB_MediumBlue,
    RGB_SeaGreen,
    RGB_Teal,

    RGB_CadetBlue,
    RGB_Blue,
    RGB_DarkCyan,
    RGB_CornflowerBlue,

    RGB_Aquamarine,
    RGB_SeaGreen,
    RGB_Aqua,
    RGB_LightSkyBlue
};

const RGB ForestColors_p[16] =
{
    RGB_DarkGreen,
    RGB_DarkGreen,
    RGB_DarkOliveGreen,
    RGB_DarkGreen,

    RGB_Green,
    RGB_ForestGreen,
    RGB_OliveDrab,
    RGB_Green,

    RGB_SeaGreen,
    RGB_MediumAquamarine,
    RGB_LimeGreen,
    RGB_YellowGreen,

    RGB_LightGreen,
    RGB_LawnGreen,
    RGB_MediumAquamarine,
    RGB_ForestGreen
};

/// HSV Rainbow
const RGB RainbowColors_p [16] =
{
    {{0xFF, 0x00, 0x00}}, {{0xD5, 0x2A, 0x00}}, {{0xAB, 0x55, 0x00}}, {{0xAB, 0x7F, 0x00}},
    {{0xAB, 0xAB, 0x00}}, {{0x56, 0xD5, 0x00}}, {{0x00, 0xFF, 0x00}}, {{0x00, 0xD5, 0x2A}},
    {{0x00, 0xAB, 0x55}}, {{0x00, 0x56, 0xAA}}, {{0x00, 0x00, 0xFF}}, {{0x2A, 0x00, 0xD5}},
    {{0x55, 0x00, 0xAB}}, {{0x7F, 0x00, 0x81}}, {{0xAB, 0x00, 0x55}}, {{0xD5, 0x00, 0x2B}}
};

/// HSV Rainbow colors with alternatating stripes of black
const RGB RainbowStripeColors_p [16] =
{
    {{0xFF, 0x00, 0x00}}, {{0x00, 0x00, 0x00}}, {{0xAB, 0x55, 0x00}}, {{0x00, 0x00, 0x00}},
    {{0xAB, 0xAB, 0x00}}, {{0x00, 0x00, 0x00}}, {{0x00, 0xFF, 0x00}}, {{0x00, 0x00, 0x00}},
    {{0x00, 0xAB, 0x55}}, {{0x00, 0x00, 0x00}}, {{0x00, 0x00, 0xFF}}, {{0x00, 0x00, 0x00}},
    {{0x55, 0x00, 0xAB}}, {{0x00, 0x00, 0x00}}, {{0xAB, 0x00, 0x55}}, {{0x00, 0x00, 0x00}}
};

/// HSV color ramp: blue purple ping red orange yellow (and back)
/// Basically, everything but the greens, which tend to make
/// people's skin look unhealthy.  This palette is good for
/// lighting at a club or party, where it'll be shining on people.
const RGB PartyColors_p [16] =
{
    {{0x55, 0x00, 0xAB}}, {{0x84, 0x00, 0x7C}}, {{0xB5, 0x00, 0x4B}}, {{0xE5, 0x00, 0x1B}},
    {{0xE8, 0x17, 0x00}}, {{0xB8, 0x47, 0x00}}, {{0xAB, 0x77, 0x00}}, {{0xAB, 0xAB, 0x00}},
    {{0xAB, 0x55, 0x00}}, {{0xDD, 0x22, 0x00}}, {{0xF2, 0x00, 0x0E}}, {{0xC2, 0x00, 0x3E}},
    {{0x8F, 0x00, 0x71}}, {{0x5F, 0x00, 0xA1}}, {{0x2F, 0x00, 0xD0}}, {{0x00, 0x07, 0xF9}}
};

/// Approximate "black body radiation" palette, akin to
/// the FastLED 'HeatColor' function.
/// Recommend that you use values 0-240 rather than
/// the usual 0-255, as the last 15 colors will be
/// 'wrapping around' from the hot end to the cold end,
/// which looks wrong.
const RGB HeatColors_p [16] =
{
    {{0x00, 0x00, 0x00}},
    {{0x33, 0x00, 0x00}}, {{0x66, 0x00, 0x00}}, {{0x99, 0x00, 0x00}}, {{0xCC, 0x00, 0x00}}, {{0xFF, 0x00, 0x00}},
    {{0xFF, 0x33, 0x00}}, {{0xFF, 0x66, 0x00}}, {{0xFF, 0x99, 0x00}}, {{0xFF, 0xCC, 0x00}}, {{0xFF, 0xFF, 0x00}},
    {{0xFF, 0xFF, 0x33}}, {{0xFF, 0xFF, 0x66}}, {{0xFF, 0xFF, 0x99}}, {{0xFF, 0xFF, 0xCC}}, {{0xFF, 0xFF, 0xFF}}
};


// Gradient palette "Rainbow_gp",
// provided for situations where you're going
// to use a number of other gradient palettes, AND
// you want a 'standard' FastLED rainbow as well.

const NRGB Rainbow_gp [] =
{
	{{0,255,0,0}}, // Red
	{{32,171,85,0}}, // Orange
	{{64,171,171,0}}, // Yellow
	{{96,0,255,0}}, // Green
	{{128,0,171,85}}, // Aqua
	{{160,0,0,255}}, // Blue
	{{192,85,0,171}}, // Purple
	{{224,171,0,85}}, // Pink
	{{255,255,0,0}}  // and back to Red
};
