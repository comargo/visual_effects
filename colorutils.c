#define FASTLED_INTERNAL
#define __PROG_TYPES_COMPAT__

#include <stdint.h>
#include <math.h>
#include "color_types.h"
#include "color_ops.h"
#include "colorutils.h"
#include "hsv2rgb.h"

void fill_rainbow(uint8_t * pFirstLED, int numToFill,
                  uint8_t initialhue,
                  uint8_t deltahue )
{
    uint16_t hue = initialhue;
    uint8_t val = 255;
    uint8_t sat = 240;
    for( int i = 0; i < numToFill; ++i, hue += deltahue) {
      set_pixel(pFirstLED+i*3, hsv2rgb_rainbow(HSV(hue, sat, val)));
    }
}

void fill_gradient_RGB( uint8_t* leds,
                   uint16_t startpos, uint32_t startcolor,
                   uint16_t endpos,   uint32_t endcolor )
{
    // if the points are in the wrong order, straighten them
    if( endpos < startpos ) {
        uint16_t t = endpos;
        uint32_t tc = endcolor;
        endcolor = startcolor;
        endpos = startpos;
        startpos = t;
        startcolor = tc;
    }

    saccum87 rdistance87;
    saccum87 gdistance87;
    saccum87 bdistance87;

    rdistance87 = (RED(endcolor) - RED(startcolor)) << 7;
    gdistance87 = (GREEN(endcolor) - GREEN(startcolor)) << 7;
    bdistance87 = (BLUE(endcolor) - BLUE(startcolor)) << 7;

    uint16_t pixeldistance = endpos - startpos;
    int16_t divisor = pixeldistance ? pixeldistance : 1;

    saccum87 rdelta87 = rdistance87 / divisor;
    saccum87 gdelta87 = gdistance87 / divisor;
    saccum87 bdelta87 = bdistance87 / divisor;

    rdelta87 *= 2;
    gdelta87 *= 2;
    bdelta87 *= 2;

    accum88 r88 = RED(startcolor) << 8;
    accum88 g88 = GREEN(startcolor) << 8;
    accum88 b88 = BLUE(startcolor) << 8;
    for( uint16_t i = startpos; i <= endpos; ++i) {
        set_pixel(leds+i*3, RGB( r88 >> 8, g88 >> 8, b88 >> 8));
        r88 += rdelta87;
        g88 += gdelta87;
        b88 += bdelta87;
    }
}

void fill_gradient_RGB2( uint8_t* leds, uint16_t numLeds, uint32_t c1, uint32_t c2)
{
    uint16_t last = numLeds - 1;
    fill_gradient_RGB( leds, 0, c1, last, c2);
}


void fill_gradient_RGB3( uint8_t* leds, uint16_t numLeds, uint32_t c1, uint32_t c2, uint32_t c3)
{
    uint16_t half = (numLeds / 2);
    uint16_t last = numLeds - 1;
    fill_gradient_RGB( leds,    0, c1, half, c2);
    fill_gradient_RGB( leds, half, c2, last, c3);
}

void fill_gradient_RGB4( uint8_t* leds, uint16_t numLeds, uint32_t c1, uint32_t c2, uint32_t c3, uint32_t c4)
{
    uint16_t onethird = (numLeds / 3);
    uint16_t twothirds = ((numLeds * 2) / 3);
    uint16_t last = numLeds - 1;
    fill_gradient_RGB( leds,         0, c1,  onethird, c2);
    fill_gradient_RGB( leds,  onethird, c2, twothirds, c3);
    fill_gradient_RGB( leds, twothirds, c3,      last, c4);
}


void nscale8_video( uint8_t* leds, uint16_t num_leds, uint8_t scale)
{
    for( uint16_t i = 0; i < num_leds; ++i) {
      uint32_t pixel = get_pixel(leds+i*3);
      set_pixel(leds+i*3, RGB(
          scale8_video(RED(pixel),  scale),
          scale8_video(GREEN(pixel),scale),
          scale8_video(BLUE(pixel), scale)
          ));
    }
}

void fade_video(uint8_t* leds, uint16_t num_leds, uint8_t fadeBy)
{
    nscale8_video( leds, num_leds, 255 - fadeBy);
}

void fadeLightBy(uint8_t* leds, uint16_t num_leds, uint8_t fadeBy)
{
    nscale8_video( leds, num_leds, 255 - fadeBy);
}


void fadeToBlackBy( uint8_t* leds, uint16_t num_leds, uint8_t fadeBy)
{
    nscale8( leds, num_leds, 255 - fadeBy);
}

void fade_raw( uint8_t* leds, uint16_t num_leds, uint8_t fadeBy)
{
    nscale8( leds, num_leds, 255 - fadeBy);
}

void nscale8_raw( uint8_t* leds, uint16_t num_leds, uint8_t scale)
{
    nscale8( leds, num_leds, scale);
}

void nscale8( uint8_t* leds, uint16_t num_leds, uint8_t scale)
{
  for( uint16_t i = 0; i < num_leds; ++i) {
    uint32_t pixel = get_pixel(leds+i*3);
    set_pixel(leds+i*3, RGB(
        scale8(RED(pixel),  scale),
        scale8(GREEN(pixel),scale),
        scale8(BLUE(pixel), scale)
        ));
  }
}

void fadeUsingColor( uint8_t* leds, uint16_t numLeds, uint32_t colormask)
{
    uint8_t fr, fg, fb;
    fr = RED(colormask);
    fg = GREEN(colormask);
    fb = BLUE(colormask);

    for( uint16_t i = 0; i < numLeds; ++i) {
      uint32_t pixel = get_pixel(leds+i*3);
      set_pixel(leds+i*3, RGB(
          scale8(RED(pixel),  fr),
          scale8(GREEN(pixel),fg),
          scale8(BLUE(pixel), fb)
          ));
    }
}


uint32_t* nblend( uint32_t *existing, uint32_t overlay, fract8 amountOfOverlay )
{
    if( amountOfOverlay == 0) {
        return existing;
    }

    if( amountOfOverlay == 255) {
        *existing = overlay;
        return existing;
    }
    *existing = blend8(*existing, overlay, amountOfOverlay);
    return existing;
}



void nblend_leds( uint8_t* existing, uint8_t* overlay, uint16_t count, fract8 amountOfOverlay)
{
    for( uint16_t i = count; i; --i) {
      set_pixel(existing+i*3, blend(get_pixel(existing+i*3), get_pixel(overlay+ i*3), amountOfOverlay));
    }
}

uint32_t blend( uint32_t p1, uint32_t p2, fract8 amountOfP2 )
{
  return RGB(
      blend8(RED(p1),   RED(p2),   amountOfP2),
      blend8(GREEN(p1), GREEN(p2), amountOfP2),
      blend8(BLUE(p1),  BLUE(p2),  amountOfP2)
      );
}

uint8_t* blend_leds( uint8_t* src1, uint8_t* src2, uint8_t* dest, uint16_t count, fract8 amountOfsrc2 )
{
    for( uint16_t i = 0; i < count; ++i) {
      set_pixel(dest+i*3, blend(get_pixel(src1+i*3), get_pixel(src2+i*3), amountOfsrc2));
    }
    return dest;
}

// Forward declaration of the function "XY" which must be provided by
// the application for use in two-dimensional filter functions.
uint16_t XY( uint8_t, uint8_t);// __attribute__ ((weak));


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
void blur1d( uint8_t* leds, uint16_t numLeds, fract8 blur_amount)
{
    uint8_t keep = 255 - blur_amount;
    uint8_t seep = blur_amount >> 1;
    uint32_t carryover = 0;
    for( uint16_t i = 0; i < numLeds; ++i) {
        uint32_t cur = get_pixel(leds+i*3);
        uint32_t part = cur;
        part = RGB(
            scale8(RED(part),seep),
            scale8(GREEN(part),seep),
            scale8(BLUE(part),seep)
            );
        cur = RGB(
            scale8(RED(cur),keep),
            scale8(GREEN(cur),keep),
            scale8(BLUE(cur),keep)
            );
        cur = color_sum(cur, carryover);
        if(i)
          set_pixel(leds+(i-1)*3, color_sum(get_pixel(leds+(i-1)*3),part));
        set_pixel(leds+i*3, cur);
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

uint32_t HeatColor( uint8_t temperature)
{
    uint32_t heatcolor;

    // Scale 'heat' down from 0-255 to 0-191,
    // which can then be easily divided into three
    // equal 'thirds' of 64 units each.
    uint8_t t192 = scale8_video( temperature, 191);

    // calculate a value that ramps up from
    // zero to 255 in each 'third' of the scale.
    uint8_t heatramp = t192 & 0x3F; // 0..63
    heatramp <<= 2; // scale up to 0..252

    // now figure out which third of the spectrum we're in:
    if( t192 & 0x80) {
        // we're in the hottest third
        heatcolor = RGB(255, // full red
                        255, // full green
                        heatramp); // ramp up blue

    } else if( t192 & 0x40 ) {
        // we're in the middle third
        heatcolor = RGB(255, // full red
                        heatramp, // ramp up green
                        0); // no blue

    } else {
        // we're in the coolest third
        heatcolor = RGB(heatramp, // ramp up red
                        0, // no green
                        0); // no blue
    }

    return heatcolor;
}


// lsrX4: helper function to divide a number by 16, aka four LSR's.
// On avr-gcc, "u8 >> 4" generates a loop, which is big, and slow.
// merely forcing it to be four /=2's causes avr-gcc to emit
// a SWAP instruction followed by an AND 0x0F, which is faster, and smaller.
inline uint8_t lsrX4( uint8_t dividend) __attribute__((always_inline));
inline uint8_t lsrX4( uint8_t dividend)
{
    dividend >>= 4;
    return dividend;
}

uint32_t ColorFromPalette16( const uint32_t* pal, uint8_t index, uint8_t brightness, TBlendType blendType)
{
    //      hi4 = index >> 4;
    uint8_t hi4 = lsrX4(index);
    uint8_t lo4 = index & 0x0F;
    
    // const CRGB* entry = &(pal[0]) + hi4;
    // since hi4 is always 0..15, hi4 * sizeof(CRGB) can be a single-byte value,
    // instead of the two byte 'int' that avr-gcc defaults to.
    // So, we multiply hi4 X sizeof(CRGB), giving hi4XsizeofCRGB;
    uint8_t hi4XsizeofCRGB = hi4 * sizeof(uint32_t);
    // We then add that to a base array pointer.
    const uint32_t* entry = (uint32_t*)( (uint8_t*)(&(pal[0])) + hi4XsizeofCRGB);
    
    uint8_t blend = lo4 && (blendType != NOBLEND);
    
    uint8_t red1   = RED(*entry);
    uint8_t green1 = GREEN(*entry);
    uint8_t blue1  = BLUE(*entry);
    
    
    if( blend ) {
        
        if( hi4 == 15 ) {
            entry = &(pal[0]);
        } else {
            ++entry;
        }
        
        uint8_t f2 = lo4 << 4;
        uint8_t f1 = 255 - f2;
        
        //    rgb1.nscale8(f1);
        uint8_t red2   = RED(*entry);
        red1   = scale8( red1,   f1);
        red2   = scale8( red2,   f2);
        red1   += red2;

        uint8_t green2 = GREEN(*entry);
        green1 = scale8( green1, f1);
        green2 = scale8( green2, f2);
        green1 += green2;

        uint8_t blue2  = BLUE(*entry);
        blue1  = scale8( blue1,  f1);
        blue2  = scale8( blue2,  f2);
        blue1  += blue2;
    }
    
    if( brightness != 255) {
        if( brightness ) {
            ++brightness; // adjust for rounding
            // Now, since brightness is nonzero, we don't need the full scale8_video logic;
            // we can just to scale8 and then add one (unless scale8 fixed) to all nonzero inputs.
            if( red1 )   {
                red1 = scale8( red1, brightness);
            }
            if( green1 ) {
                green1 = scale8( green1, brightness);
            }
            if( blue1 )  {
                blue1 = scale8( blue1, brightness);
            }
        } else {
            red1 = 0;
            green1 = 0;
            blue1 = 0;
        }
    }
    
    return RGB( red1, green1, blue1);
}

uint32_t ColorFromPalette32( const uint32_t *pal, uint8_t index, uint8_t brightness, TBlendType blendType)
{
    uint8_t hi5 = index;
    hi5 >>= 3;
    uint8_t lo3 = index & 0x07;
    
    // const CRGB* entry = &(pal[0]) + hi5;
    // since hi5 is always 0..31, hi4 * sizeof(CRGB) can be a single-byte value,
    // instead of the two byte 'int' that avr-gcc defaults to.
    // So, we multiply hi5 X sizeof(CRGB), giving hi5XsizeofCRGB;
    uint8_t hi5XsizeofCRGB = hi5 * sizeof(uint32_t);
    // We then add that to a base array pointer.
    const uint32_t* entry = (uint32_t*)( (uint8_t*)(&(pal[0])) + hi5XsizeofCRGB);
    
    uint8_t red1   = RED(*entry);
    uint8_t green1 = GREEN(*entry);
    uint8_t blue1  = BLUE(*entry);
    
    uint8_t blend = lo3 && (blendType != NOBLEND);
    
    if( blend ) {
        
        if( hi5 == 31 ) {
            entry = &(pal[0]);
        } else {
            ++entry;
        }
        
        uint8_t f2 = lo3 << 5;
        uint8_t f1 = 255 - f2;
        
        uint8_t red2   = RED(*entry);
        red1   = scale8( red1,   f1);
        red2   = scale8( red2,   f2);
        red1   += red2;
        
        uint8_t green2 = GREEN(*entry);
        green1 = scale8( green1, f1);
        green2 = scale8( green2, f2);
        green1 += green2;
        
        uint8_t blue2  = BLUE(*entry);
        blue1  = scale8( blue1,  f1);
        blue2  = scale8( blue2,  f2);
        blue1  += blue2;
        
    }
    
    if( brightness != 255) {
        if( brightness ) {
            ++brightness; // adjust for rounding
            // Now, since brightness is nonzero, we don't need the full scale8_video logic;
            // we can just to scale8 and then add one (unless scale8 fixed) to all nonzero inputs.
            if( red1 )   {
                red1 = scale8( red1, brightness);
            }
            if( green1 ) {
                green1 = scale8( green1, brightness);
            }
            if( blue1 )  {
                blue1 = scale8( blue1, brightness);
            }
        } else {
            red1 = 0;
            green1 = 0;
            blue1 = 0;
        }
    }
    
    return RGB( red1, green1, blue1);
}

uint32_t ColorFromPalette256( const uint32_t *pal, uint8_t index, uint8_t brightness, TBlendType blendType)
{
    const uint32_t* entry = &(pal[0]) + index;

    uint8_t red   = RED(*entry);
    uint8_t green = GREEN(*entry);
    uint8_t blue  = BLUE(*entry);

    if( brightness != 255) {
        ++brightness; // adjust for rounding
        red   = scale8_video( red,   brightness);
        green = scale8_video( green, brightness);
        blue  = scale8_video( blue,  brightness);
    }

    return RGB( red, green, blue);
}

void UpscalePalette16_256(uint32_t *srcpal16, uint32_t *destpal256)
{
    for( int i = 0; i < 256; ++i) {
        destpal256[(uint8_t)(i)] = ColorFromPalette16( srcpal16, i, 255, LINEARBLEND);
    }
}

void UpscalePalette16_32(uint32_t *srcpal16, uint32_t *destpal32)
{
    for( uint8_t i = 0; i < 16; ++i) {
        uint8_t j = i * 2;
        destpal32[j+0] = srcpal16[i];
        destpal32[j+1] = srcpal16[i];
    }
}

void UpscalePalette32_256(uint32_t *srcpal32, uint32_t *destpal256)
{
    for( int i = 0; i < 256; ++i) {
        destpal256[(uint8_t)(i)] = ColorFromPalette32( srcpal32, i, 255, LINEARBLEND);
    }
}

void nblendPaletteTowardPalette16( uint32_t *current, uint32_t *target, uint8_t maxChanges)
{
    uint8_t* p1;
    uint8_t* p2;
    uint8_t  changes = 0;

    p1 = (uint8_t*)current;
    p2 = (uint8_t*)target;

    const uint8_t totalChannels = 16*sizeof(uint32_t);
    for( uint8_t i = 0; i < totalChannels; ++i) {
        // if the values are equal, no changes are needed
        if( p1[i] == p2[i] ) { continue; }

        // if the current value is less than the target, increase it by one
        if( p1[i] < p2[i] ) { ++p1[i]; ++changes; }

        // if the current value is greater than the target,
        // increase it by one (or two if it's still greater).
        if( p1[i] > p2[i] ) {
            --p1[i]; ++changes;
            if( p1[i] > p2[i] ) { --p1[i]; }
        }

        // if we've hit the maximum number of changes, exit
        if( changes >= maxChanges) { break; }
    }
}


uint8_t applyGamma_video( uint8_t brightness, float gamma)
{
    float orig;
    float adj;
    orig = (float)(brightness) / (255.0);
    adj =  pow( orig, gamma)   * (255.0);
    uint8_t result = (uint8_t)(adj);
    if( (brightness > 0) && (result == 0)) {
        result = 1; // never gamma-adjust a positive number down to zero
    }
    return result;
}

uint32_t applyGamma_videoRGB( uint32_t orig, float gamma)
{
  return RGB(
      applyGamma_video(RED(orig), gamma),
      applyGamma_video(GREEN(orig), gamma),
      applyGamma_video(BLUE(orig), gamma)
      );
}

uint32_t applyGammaRGB_videoRGB( uint32_t orig, float gammaR, float gammaG, float gammaB)
{
  return RGB(
      applyGamma_video(RED(orig), gammaR),
      applyGamma_video(GREEN(orig), gammaG),
      applyGamma_video(BLUE(orig), gammaB)
      );
}

uint32_t *napplyGamma_videoRGB( uint32_t *rgb, float gamma)
{
    *rgb = applyGamma_video( *rgb, gamma);
    return rgb;
}

uint32_t *napplyGammaRGB_videoRGB( uint32_t *rgb, float gammaR, float gammaG, float gammaB)
{
    *rgb = applyGammaRGB_videoRGB(*rgb, gammaR, gammaG, gammaB);
    return rgb;
}

void napplyGamma_videoLeds( uint8_t *rgbarray, uint16_t count, float gamma)
{
    for( uint16_t i = 0; i < count; ++i) {
      set_pixel(rgbarray+i*3, applyGamma_videoRGB(get_pixel(rgbarray+i*3), gamma));
    }
}

void napplyGammaRGB_videoLeds( uint8_t* rgbarray, uint16_t count, float gammaR, float gammaG, float gammaB)
{
    for( uint16_t i = 0; i < count; ++i) {
      set_pixel(rgbarray+i*3, applyGammaRGB_videoRGB(get_pixel(rgbarray+i*3), gammaR, gammaG, gammaB));
    }
}



