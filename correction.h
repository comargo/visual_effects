/*
 * compensation.h
 *
 *  Created on: Dec 15, 2021
 *      Author: cyril
 */

#ifndef CORRECTION_H_
#define CORRECTION_H_

#include "color_types.h"

///@file color.h
/// contains definitions for color correction and temperature
///@defgroup ColorEnums Color correction/temperature
/// definitions for color correction and light temperatures
///@{
// Color correction starting points

/// typical values for SMD5050 LEDs
///@{
static const RGB TypicalSMD5050 = { .raw = { 0xFF, 0xB0, 0xF0 } }; /* 255, 176, 240 */
static const RGB TypicalLEDStrip = { .raw = { 0xFF, 0xB0, 0xF0 } }; /* 255, 176, 240 */
///@}

/// typical values for 8mm "pixels on a string"
/// also for many through-hole 'T' package LEDs
///@{
static const RGB Typical8mmPixel = { .raw = { 0xFF, 0xE0, 0x8C } }; /* 255, 224, 140 */
static const RGB TypicalPixelString = { .raw = { 0xFF, 0xE0, 0x8C } }; /* 255, 224, 140 */
///@}

/// uncorrected color
static const RGB UncorrectedColor = { .raw = { 0xFF, 0xFF, 0xFF } };

/// @name Black-body radiation light sources
/// Black-body radiation light sources emit a (relatively) continuous
/// spectrum, and can be described as having a Kelvin 'temperature'
///@{
/// 1900 Kelvin
static const RGB Candle = { .raw = { 0xFF, 0x93, 0x29 } }; /* 1900 K, 255, 147, 41 */
/// 2600 Kelvin
static const RGB Tungsten40W = { .raw = { 0xFF, 0xC5, 0x8F } }; /* 2600 K, 255, 197, 143 */
/// 2850 Kelvin
static const RGB Tungsten100W = { .raw = { 0xFF, 0xD6, 0xAA } }; /* 2850 K, 255, 214, 170 */
/// 3200 Kelvin
static const RGB Halogen = { .raw = { 0xFF, 0xF1, 0xE0 } }; /* 3200 K, 255, 241, 224 */
/// 5200 Kelvin
static const RGB CarbonArc = { .raw = { 0xFF, 0xFA, 0xF4 } }; /* 5200 K, 255, 250, 244 */
/// 5400 Kelvin
static const RGB HighNoonSun = { .raw = { 0xFF, 0xFF, 0xFB } }; /* 5400 K, 255, 255, 251 */
/// 6000 Kelvin
static const RGB DirectSunlight = { .raw = { 0xFF, 0xFF, 0xFF } }; /* 6000 K, 255, 255, 255 */
/// 7000 Kelvin
static const RGB OvercastSky = { .raw = { 0xC9, 0xE2, 0xFF } }; /* 7000 K, 201, 226, 255 */
/// 20000 Kelvin
static const RGB ClearBlueSky = { .raw = { 0x40, 0x9C, 0xFF } }; /* 20000 K, 64, 156, 255 */
///@}

/// @name Gaseous light sources
/// Gaseous light sources emit discrete spectral bands, and while we can
/// approximate their aggregate hue with RGB values, they don't actually
/// have a proper Kelvin temperature.
///@{
static const RGB WarmFluorescent = { .raw = { 0xFF, 0xF4, 0xE5 } }; /* 0 K, 255, 244, 229 */
static const RGB StandardFluorescent = { .raw = { 0xF4, 0xFF, 0xFA } }; /* 0 K, 244, 255, 250 */
static const RGB CoolWhiteFluorescent = { .raw = { 0xD4, 0xEB, 0xFF } }; /* 0 K, 212, 235, 255 */
static const RGB FullSpectrumFluorescent = { .raw = { 0xFF, 0xF4, 0xF2 } }; /* 0 K, 255, 244, 242 */
static const RGB GrowLightFluorescent = { .raw = { 0xFF, 0xEF, 0xF7 } }; /* 0 K, 255, 239, 247 */
static const RGB BlackLightFluorescent = { .raw = { 0xA7, 0x00, 0xFF } }; /* 0 K, 167, 0, 255 */
static const RGB MercuryVapor = { .raw = { 0xD8, 0xF7, 0xFF } }; /* 0 K, 216, 247, 255 */
static const RGB SodiumVapor = { .raw = { 0xFF, 0xD1, 0xB2 } }; /* 0 K, 255, 209, 178 */
static const RGB MetalHalide = { .raw = { 0xF2, 0xFC, 0xFF } }; /* 0 K, 242, 252, 255 */
static const RGB HighPressureSodium = { .raw = { 0xFF, 0xB7, 0x4C } }; /* 0 K, 255, 183, 76 */
///@}

/// Uncorrected temperature 0xFFFFFF
static const RGB UncorrectedTemperature = { .raw = { 0xFF, 0xFF, 0xFF } };

#endif /* CORRECTION_H_ */
