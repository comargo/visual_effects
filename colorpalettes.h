/*
 * colorpalettes.h
 *
 *  Created on: Dec 15, 2021
 *      Author: cyril
 */

#ifndef COLORPALETTES_H_
#define COLORPALETTES_H_

#include <stdint.h>
#include "color_types.h"

#define DECLARE_PALETTE(Name) \
	extern const RGB Name[]

#define DECLARE_GRADIENT_PALETTE(Name) \
	extern const NRGB Name[]

/// Cloudy color pallete
DECLARE_PALETTE(CloudColors_p16);
/// Lava colors
DECLARE_PALETTE(LavaColors_p16);
/// Ocean colors, blues and whites
DECLARE_PALETTE(OceanColors_p16);
/// Forest colors, greens
DECLARE_PALETTE(ForestColors_p16);

/// HSV Rainbow
DECLARE_PALETTE(RainbowColors_p16);

/// HSV Rainbow colors with alternatating stripes of black
DECLARE_PALETTE(RainbowStripeColors_p16);

/// HSV color ramp: blue purple ping red orange yellow (and back)
/// Basically, everything but the greens, which tend to make
/// people's skin look unhealthy.  This palette is good for
/// lighting at a club or party, where it'll be shining on people.
DECLARE_PALETTE(PartyColors_p16);

/// Approximate "black body radiation" palette, akin to
/// the FastLED 'HeatColor' function.
/// Recommend that you use values 0-240 rather than
/// the usual 0-255, as the last 15 colors will be
/// 'wrapping around' from the hot end to the cold end,
/// which looks wrong.
DECLARE_PALETTE(HeatColors_p16);


DECLARE_GRADIENT_PALETTE( Rainbow_gp);

#endif /* COLORPALETTES_H_ */
