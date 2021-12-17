#define FASTLED_INTERNAL
#define __PROG_TYPES_COMPAT__

#include <stdint.h>
#include <math.h>
#include "color_types.h"
#include "color_ops.h"
#include "colorutils.h"
#include "hsv2rgb.h"
#include "colorpalettes.h"

void fill_solid(RGB *leds, int numToFill, RGB color)
{
	for (int i = 0; i < numToFill; ++i) {
		leds[i] = color;
	}
}

void fill_rainbow(RGB *pFirstLED, int numToFill, uint8_t initialhue, uint8_t deltahue)
{
	HSV hsv = { .h = initialhue, .s = 240, .v = 255 };
	for (int i = 0; i < numToFill; ++i, hsv.h += deltahue) {
		pFirstLED[i] = hsv2rgb_rainbow(hsv);
	}
}

void fill_gradient_RGB(RGB *leds, uint16_t startpos, RGB startcolor, uint16_t endpos, RGB endcolor)
{
	// if the points are in the wrong order, straighten them
	if (endpos < startpos) {
		uint16_t t = endpos;
		RGB tc = endcolor;
		endcolor = startcolor;
		endpos = startpos;
		startpos = t;
		startcolor = tc;
	}

	saccum87 rdistance87;
	saccum87 gdistance87;
	saccum87 bdistance87;

	rdistance87 = (endcolor.r - startcolor.r) << 7;
	gdistance87 = (endcolor.g - startcolor.g) << 7;
	bdistance87 = (endcolor.b - startcolor.b) << 7;

	uint16_t pixeldistance = endpos - startpos;
	int16_t divisor = pixeldistance ? pixeldistance : 1;

	saccum87 rdelta87 = rdistance87 / divisor;
	saccum87 gdelta87 = gdistance87 / divisor;
	saccum87 bdelta87 = bdistance87 / divisor;

	rdelta87 *= 2;
	gdelta87 *= 2;
	bdelta87 *= 2;

	accum88 r88 = startcolor.r << 8;
	accum88 g88 = startcolor.g << 8;
	accum88 b88 = startcolor.b << 8;
	for (uint16_t i = startpos; i <= endpos; ++i) {
		leds[i] = (RGB ) { { r88 >> 8, g88 >> 8, b88 >> 8 } };
		r88 += rdelta87;
		g88 += gdelta87;
		b88 += bdelta87;
	}
}

void fill_gradient_RGB2(RGB *leds, uint16_t numLeds, RGB c1, RGB c2)
{
	uint16_t last = numLeds - 1;
	fill_gradient_RGB(leds, 0, c1, last, c2);
}

void fill_gradient_RGB3(RGB *leds, uint16_t numLeds, RGB c1, RGB c2, RGB c3)
{
	uint16_t half = (numLeds / 2);
	uint16_t last = numLeds - 1;
	fill_gradient_RGB(leds, 0, c1, half, c2);
	fill_gradient_RGB(leds, half, c2, last, c3);
}

void fill_gradient_RGB4(RGB *leds, uint16_t numLeds, RGB c1, RGB c2, RGB c3, RGB c4)
{
	uint16_t onethird = (numLeds / 3);
	uint16_t twothirds = ((numLeds * 2) / 3);
	uint16_t last = numLeds - 1;
	fill_gradient_RGB(leds, 0, c1, onethird, c2);
	fill_gradient_RGB(leds, onethird, c2, twothirds, c3);
	fill_gradient_RGB(leds, twothirds, c3, last, c4);
}

void nscale8_video(RGB *leds, uint16_t num_leds, uint8_t scale)
{
	for (uint16_t i = 0; i < num_leds; ++i) {
		leds[i] = (RGB ) { {
						scale8_video(leds[i].r, scale),
						scale8_video(leds[i].g, scale),
						scale8_video(leds[i].b, scale) } };
	}
}

void fade_video(RGB *leds, uint16_t num_leds, uint8_t fadeBy)
{
	nscale8_video(leds, num_leds, 255 - fadeBy);
}

void fadeLightBy(RGB *leds, uint16_t num_leds, uint8_t fadeBy)
{
	nscale8_video(leds, num_leds, 255 - fadeBy);
}

void fadeToBlackBy(RGB *leds, uint16_t num_leds, uint8_t fadeBy)
{
	nscale8(leds, num_leds, 255 - fadeBy);
}

void fade_raw(RGB *leds, uint16_t num_leds, uint8_t fadeBy)
{
	nscale8(leds, num_leds, 255 - fadeBy);
}

void nscale8_raw(RGB *leds, uint16_t num_leds, uint8_t scale)
{
	nscale8(leds, num_leds, scale);
}

void nscale8(RGB *leds, uint16_t num_leds, uint8_t scale)
{
	for (uint16_t i = 0; i < num_leds; ++i) {
		leds[i] = (RGB ) { { scale8(leds[i].r, scale), scale8(leds[i].g, scale), scale8(leds[i].b,
						scale) } };
	}
}

void fadeUsingColor(RGB *leds, uint16_t numLeds, RGB colormask)
{
	for (uint16_t i = 0; i < numLeds; ++i) {
		leds[i] = (RGB ) { { scale8(leds[i].r, colormask.r), scale8(leds[i].g, colormask.g), scale8(
						leds[i].b, colormask.b) } };
	}
}

RGB* nblend(RGB *existing, RGB overlay, fract8 amountOfOverlay)
{
	if (amountOfOverlay == 0) {
		return existing;
	}

	if (amountOfOverlay == 255) {
		*existing = overlay;
		return existing;
	}
	*existing = blend(*existing, overlay, amountOfOverlay);
	return existing;
}

void nblend_leds(RGB *existing, RGB *overlay, uint16_t count, fract8 amountOfOverlay)
{
	for (uint16_t i = count; i; --i) {
		existing[i] = blend(existing[i], overlay[i], amountOfOverlay);
	}
}

RGB blend(RGB p1, RGB p2, fract8 amountOfP2)
{
	return (RGB ) { { blend8(p1.r, p2.r, amountOfP2), blend8(p1.g, p2.g, amountOfP2), blend8(p1.b,
					p2.b, amountOfP2) } } ;
		}

		RGB* blend_leds(RGB *src1, RGB *src2, RGB *dest, uint16_t count, fract8 amountOfsrc2)
		{
			for (uint16_t i = 0; i < count; ++i) {
				dest[i] = blend(src1[i], src2[i], amountOfsrc2);
			}
			return dest;
		}

// blur1d: one-dimensional blur filter. Spreads light to 2 line neighbors.
// blur2d: two-dimensional blur filter. Spreads light to 8 XY neighbors.
//
//           0 = no spread at all
//          64 = moderate spreading
//         172 = maximum smooth, even spreading
//
//         173..255 = wider spreading, but increasing flicker
//
//         Total light is NOT entirely conserved, so many repeated
//         calls to 'blur' will also result in the light fading,
//         eventually all the way to black; this is by design so that
//         it can be used to (slowly) clear the LEDs to black.
		void blur1d(RGB *leds, uint16_t numLeds, fract8 blur_amount)
		{
			uint8_t keep = 255 - blur_amount;
			uint8_t seep = blur_amount >> 1;
			RGB carryover = { 0 };
			for (uint16_t i = 0; i < numLeds; ++i) {
				RGB cur = leds[i];
				RGB part = cur;
				part = (RGB ) { { scale8(part.r, seep), scale8(part.g, seep), scale8(part.b, seep) } };
				cur = (RGB ) { { scale8(cur.r, keep), scale8(cur.g, keep), scale8(cur.b, keep) } };
				cur = color_sum(cur, carryover);
				if (i)
					leds[i] = color_sum(leds[i - 1], part);
				leds[i] = cur;
				carryover = part;
			}
		}

// CRGB HeatColor( uint8_t temperature)
//
// Approximates a 'black body radiation' spectrum for
// a given 'heat' level.  This is useful for animations of 'fire'.
// Heat is specified as an arbitrary scale from 0 (cool) to 255 (hot).
// This is NOT a chromatically correct 'black body radiation'
// spectrum, but it's surprisingly close, and it's fast and small.
//
// On AVR/Arduino, this typically takes around 70 bytes of program memory,
// versus 768 bytes for a full 256-entry RGB lookup table.

		RGB HeatColor(uint8_t temperature)
		{
			RGB heatcolor;

			// Scale 'heat' down from 0-255 to 0-191,
			// which can then be easily divided into three
			// equal 'thirds' of 64 units each.
			uint8_t t192 = scale8_video(temperature, 191);

			// calculate a value that ramps up from
			// zero to 255 in each 'third' of the scale.
			uint8_t heatramp = t192 & 0x3F; // 0..63
			heatramp <<= 2; // scale up to 0..252

			// now figure out which third of the spectrum we're in:
			if (t192 & 0x80) {
				// we're in the hottest third
				heatcolor = (RGB ) { { 255, // full red
								255, // full green
								heatramp } }; // ramp up blue

			}
			else if (t192 & 0x40) {
				// we're in the middle third
				heatcolor = (RGB ) { { 255, // full red
								heatramp, // ramp up green
								0 } }; // no blue

			}
			else {
				// we're in the coolest third
				heatcolor = (RGB ) { { heatramp, // ramp up red
								0, // no green
								0 } }; // no blue
			}

			return heatcolor;
		}

// lsrX4: helper function to divide a number by 16, aka four LSR's.
// On avr-gcc, "u8 >> 4" generates a loop, which is big, and slow.
// merely forcing it to be four /=2's causes avr-gcc to emit
// a SWAP instruction followed by an AND 0x0F, which is faster, and smaller.
		inline uint8_t lsrX4(uint8_t dividend) __attribute__((always_inline));
		inline uint8_t lsrX4(uint8_t dividend)
		{
			dividend >>= 4;
			return dividend;
		}

		RGB ColorFromPalette16(const RGB *pal, uint8_t index, uint8_t brightness, TBlendType blendType)
		{
			//      hi4 = index >> 4;
			uint8_t hi4 = lsrX4(index);
			uint8_t lo4 = index & 0x0F;

			// const CRGB* entry = &(pal[0]) + hi4;
			// since hi4 is always 0..15, hi4 * sizeof(CRGB) can be a single-byte value,
			// instead of the two byte 'int' that avr-gcc defaults to.
			// So, we multiply hi4 X sizeof(CRGB), giving hi4XsizeofCRGB;
			uint8_t hi4XsizeofCRGB = hi4 * sizeof(RGB);
			// We then add that to a base array pointer.
			const RGB *entry = (RGB*) ((uint8_t*) (&(pal[0])) + hi4XsizeofCRGB);

			uint8_t blend = lo4 && (blendType != NOBLEND);

			uint8_t red1 = entry->r;
			uint8_t green1 = entry->g;
			uint8_t blue1 = entry->b;

			if (blend) {

				if (hi4 == 15) {
					entry = &(pal[0]);
				}
				else {
					++entry;
				}

				uint8_t f2 = lo4 << 4;
				uint8_t f1 = 255 - f2;

				//    rgb1.nscale8(f1);
				uint8_t red2 = entry->r;
				red1 = scale8(red1, f1);
				red2 = scale8(red2, f2);
				red1 += red2;

				uint8_t green2 = entry->g;
				green1 = scale8(green1, f1);
				green2 = scale8(green2, f2);
				green1 += green2;

				uint8_t blue2 = entry->b;
				blue1 = scale8(blue1, f1);
				blue2 = scale8(blue2, f2);
				blue1 += blue2;
			}

			if (brightness != 255) {
				if (brightness) {
					++brightness; // adjust for rounding
					// Now, since brightness is nonzero, we don't need the full scale8_video logic;
					// we can just to scale8 and then add one (unless scale8 fixed) to all nonzero inputs.
					if (red1) {
						red1 = scale8(red1, brightness);
					}
					if (green1) {
						green1 = scale8(green1, brightness);
					}
					if (blue1) {
						blue1 = scale8(blue1, brightness);
					}
				}
				else {
					red1 = 0;
					green1 = 0;
					blue1 = 0;
				}
			}

			return (RGB ) { { red1, green1, blue1 } } ;
				}

				RGB ColorFromPalette32(const RGB *pal, uint8_t index, uint8_t brightness,
						TBlendType blendType)
				{
					uint8_t hi5 = index;
					hi5 >>= 3;
					uint8_t lo3 = index & 0x07;

					// const CRGB* entry = &(pal[0]) + hi5;
					// since hi5 is always 0..31, hi4 * sizeof(CRGB) can be a single-byte value,
					// instead of the two byte 'int' that avr-gcc defaults to.
					// So, we multiply hi5 X sizeof(CRGB), giving hi5XsizeofCRGB;
					uint8_t hi5XsizeofCRGB = hi5 * sizeof(RGB);
					// We then add that to a base array pointer.
					const RGB *entry = (RGB*) ((uint8_t*) (&(pal[0])) + hi5XsizeofCRGB);

					uint8_t red1 = entry->r;
					uint8_t green1 = entry->g;
					uint8_t blue1 = entry->b;

					uint8_t blend = lo3 && (blendType != NOBLEND);

					if (blend) {

						if (hi5 == 31) {
							entry = &(pal[0]);
						}
						else {
							++entry;
						}

						uint8_t f2 = lo3 << 5;
						uint8_t f1 = 255 - f2;

						uint8_t red2 = entry->r;
						red1 = scale8(red1, f1);
						red2 = scale8(red2, f2);
						red1 += red2;

						uint8_t green2 = entry->g;
						green1 = scale8(green1, f1);
						green2 = scale8(green2, f2);
						green1 += green2;

						uint8_t blue2 = entry->b;
						blue1 = scale8(blue1, f1);
						blue2 = scale8(blue2, f2);
						blue1 += blue2;

					}

					if (brightness != 255) {
						if (brightness) {
							++brightness; // adjust for rounding
							// Now, since brightness is nonzero, we don't need the full scale8_video logic;
							// we can just to scale8 and then add one (unless scale8 fixed) to all nonzero inputs.
							if (red1) {
								red1 = scale8(red1, brightness);
							}
							if (green1) {
								green1 = scale8(green1, brightness);
							}
							if (blue1) {
								blue1 = scale8(blue1, brightness);
							}
						}
						else {
							red1 = 0;
							green1 = 0;
							blue1 = 0;
						}
					}

					return (RGB ) { { red1, green1, blue1 } } ;
						}

						RGB ColorFromPalette256(const RGB *pal, uint8_t index, uint8_t brightness,
								TBlendType blendType)
						{
							const RGB *entry = &(pal[0]) + index;

							uint8_t red = entry->r;
							uint8_t green = entry->g;
							uint8_t blue = entry->b;

							if (brightness != 255) {
								++brightness; // adjust for rounding
								red = scale8_video(red, brightness);
								green = scale8_video(green, brightness);
								blue = scale8_video(blue, brightness);
							}

							return (RGB ) { { red, green, blue } } ;
								}

								void UpscalePalette16_256(RGB *srcpal16, RGB *destpal256)
								{
									for (int i = 0; i < 256; ++i) {
										destpal256[(uint8_t) (i)] = ColorFromPalette16(srcpal16, i, 255, LINEARBLEND);
									}
								}

								void UpscalePalette16_32(RGB *srcpal16, RGB *destpal32)
								{
									for (uint8_t i = 0; i < 16; ++i) {
										uint8_t j = i * 2;
										destpal32[j + 0] = srcpal16[i];
										destpal32[j + 1] = srcpal16[i];
									}
								}

								void UpscalePalette32_256(RGB *srcpal32, RGB *destpal256)
								{
									for (int i = 0; i < 256; ++i) {
										destpal256[(uint8_t) (i)] = ColorFromPalette32(srcpal32, i, 255, LINEARBLEND);
									}
								}

								void nblendPaletteTowardPalette16(RGB *current, RGB *target, uint8_t maxChanges)
								{
									uint8_t *p1;
									uint8_t *p2;
									uint8_t changes = 0;

									p1 = (uint8_t*) current;
									p2 = (uint8_t*) target;

									const uint8_t totalChannels = 16 * sizeof(RGB);
									for (uint8_t i = 0; i < totalChannels; ++i) {
										// if the values are equal, no changes are needed
										if (p1[i] == p2[i]) {
											continue;
										}

										// if the current value is less than the target, increase it by one
										if (p1[i] < p2[i]) {
											++p1[i];
											++changes;
										}

										// if the current value is greater than the target,
										// increase it by one (or two if it's still greater).
										if (p1[i] > p2[i]) {
											--p1[i];
											++changes;
											if (p1[i] > p2[i]) {
												--p1[i];
											}
										}

										// if we've hit the maximum number of changes, exit
										if (changes >= maxChanges) {
											break;
										}
									}
								}

								uint8_t applyGamma_video(uint8_t brightness, float gamma)
								{
									float orig;
									float adj;
									orig = (float) (brightness) / (255.0);
									adj = pow(orig, gamma) * (255.0);
									uint8_t result = (uint8_t) (adj);
									if ((brightness > 0) && (result == 0)) {
										result = 1; // never gamma-adjust a positive number down to zero
									}
									return result;
								}

								RGB applyGamma_videoRGB(RGB orig, float gamma)
								{
									return (RGB ) { { applyGamma_video(orig.r, gamma), applyGamma_video(orig.g,
													gamma), applyGamma_video(orig.b, gamma) } } ;
										}

										RGB applyGammaRGB_videoRGB(RGB orig, float gammaR, float gammaG, float gammaB)
										{
											return (RGB ) { { applyGamma_video(orig.r, gammaR), applyGamma_video(orig.g,
															gammaG), applyGamma_video(orig.b, gammaB) } } ;
												}

												RGB* napplyGamma_videoRGB(RGB *rgb, float gamma)
												{
													*rgb = applyGamma_videoRGB(*rgb, gamma);
													return rgb;
												}

												RGB* napplyGammaRGB_videoRGB(RGB *rgb, float gammaR, float gammaG,
														float gammaB)
												{
													*rgb = applyGammaRGB_videoRGB(*rgb, gammaR, gammaG, gammaB);
													return rgb;
												}

												void napplyGamma_videoLeds(RGB *rgbarray, uint16_t count, float gamma)
												{
													for (uint16_t i = 0; i < count; ++i) {
														napplyGamma_videoRGB(&rgbarray[i], gamma);
													}
												}

												void napplyGammaRGB_videoLeds(RGB *rgbarray, uint16_t count, float gammaR,
														float gammaG, float gammaB)
												{
													for (uint16_t i = 0; i < count; ++i) {
														napplyGammaRGB_videoRGB(&rgbarray[i], gammaR, gammaG, gammaB);
													}
												}

// Gradient palettes are loaded into CRGB16Palettes in such a way
// that, if possible, every color represented in the gradient palette
// is also represented in the CRGBPalette16.
// For example, consider a gradient palette that is all black except
// for a single, one-element-wide (1/256th!) spike of red in the middle:
//     0,   0,0,0
//   124,   0,0,0
//   125, 255,0,0  // one 1/256th-palette-wide red stripe
//   126,   0,0,0
//   255,   0,0,0
// A naive conversion of this 256-element palette to a 16-element palette
// might accidentally completely eliminate the red spike, rendering the
// palette completely black.
// However, the conversions provided here would attempt to include a
// the red stripe in the output, more-or-less as faithfully as possible.
// So in this case, the resulting CRGBPalette16 palette would have a red
// stripe in the middle which was 1/16th of a palette wide -- the
// narrowest possible in a CRGBPalette16.
// This means that the relative width of stripes in a CRGBPalette16
// will be, by definition, different from the widths in the gradient
// palette.  This code attempts to preserve "all the colors", rather than
// the exact stripe widths at the expense of dropping some colors.
												void Palette16FromGradientPalette(RGB *dstPal16, const NRGB *srcGradPalette)
												{
													NRGB u;
													int count = 0;
													do {
														u = srcGradPalette[count];
														++count;
													} while (u.index != 255);

													int8_t lastSlotUsed = -1;
													int indexstart = 0;
													uint8_t istart8 = 0;
													uint8_t iend8 = 0;

													u = *srcGradPalette;
													RGB rgbstart = u.rgb;

													while (indexstart < 255) {
														++srcGradPalette;
														u = *srcGradPalette;
														int indexend = u.index;
														RGB rgbend = u.rgb;
														istart8 = indexstart / 16;
														iend8 = indexend / 16;
														if (count < 16) {
															if ((istart8 <= lastSlotUsed) && (lastSlotUsed < 15)) {
																istart8 = lastSlotUsed + 1;
																if (iend8 < istart8) {
																	iend8 = istart8;
																}
															}
															lastSlotUsed = iend8;
														}
														fill_gradient_RGB(dstPal16, istart8, rgbstart, iend8, rgbend);
														indexstart = indexend;
														rgbstart = rgbend;
													}
												}
