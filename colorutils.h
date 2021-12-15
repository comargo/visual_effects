#ifndef __INC_COLORUTILS_H
#define __INC_COLORUTILS_H

#include "color_types.h"
#include "lib8tion.h"

///@file colorutils.h
/// functions for color fill, paletters, blending, and more

///@defgroup Colorutils Color utility functions
///A variety of functions for working with color, palletes, and leds
///@{

static inline void set_pixel(uint8_t *pLED, uint32_t rgb)
{
  pLED[0] = RED(rgb);
  pLED[1] = GREEN(rgb);
  pLED[2] = BLUE(rgb);
}


static inline uint32_t get_pixel(uint8_t *pLED)
{
  return RGB(pLED[0], pLED[1], pLED[2]);
}


/// fill_rainbow - fill a range of LEDs with a rainbow of colors, at
///                full saturation and full value (brightness)
void fill_rainbow( uint8_t * pFirstLED, int numToFill,
                   uint8_t initialhue,
                   uint8_t deltahue);

// fill_gradient - fill an array of colors with a smooth HSV gradient
//                 between two specified HSV colors.
//                 Since 'hue' is a value around a color wheel,
//                 there are always two ways to sweep from one hue
//                 to another.
//                 This function lets you specify which way you want
//                 the hue gradient to sweep around the color wheel:
//                   FORWARD_HUES: hue always goes clockwise
//                   BACKWARD_HUES: hue always goes counter-clockwise
//                   SHORTEST_HUES: hue goes whichever way is shortest
//                   LONGEST_HUES: hue goes whichever way is longest
//                 The default is SHORTEST_HUES, as this is nearly
//                 always what is wanted.
//
// fill_gradient can write the gradient colors EITHER
//     (1) into an array of CRGBs (e.g., into leds[] array, or an RGB Palette)
//   OR
//     (2) into an array of CHSVs (e.g. an HSV Palette).
//
//   In the case of writing into a CRGB array, the gradient is
//   computed in HSV space, and then HSV values are converted to RGB
//   as they're written into the RGB array.

typedef enum { FORWARD_HUES, BACKWARD_HUES, SHORTEST_HUES, LONGEST_HUES } TGradientDirectionCode;



#define saccum87 int16_t

// fill_gradient_RGB - fill a range of LEDs with a smooth RGB gradient
//                     between two specified RGB colors.
//                     Unlike HSV, there is no 'color wheel' in RGB space,
//                     and therefore there's only one 'direction' for the
//                     gradient to go, and no 'direction code' is needed.
void fill_gradient_RGB( uint8_t* leds,
                   uint16_t startpos, uint32_t startcolor,
                   uint16_t endpos,   uint32_t endcolor );
void fill_gradient_RGB2( uint8_t* leds, uint16_t numLeds, uint32_t c1, uint32_t c2);
void fill_gradient_RGB3( uint8_t* leds, uint16_t numLeds, uint32_t c1, uint32_t c2, uint32_t c3);
void fill_gradient_RGB4( uint8_t* leds, uint16_t numLeds, uint32_t c1, uint32_t c2, uint32_t c3, uint32_t c4);


// fadeLightBy and fade_video - reduce the brightness of an array
//                              of pixels all at once.  Guaranteed
//                              to never fade all the way to black.
//                              (The two names are synonyms.)
void fadeLightBy(   uint8_t* leds, uint16_t num_leds, uint8_t fadeBy);
void fade_video(    uint8_t* leds, uint16_t num_leds, uint8_t fadeBy);

// nscale8_video - scale down the brightness of an array of pixels
//                 all at once.  Guaranteed to never scale a pixel
//                 all the way down to black, unless 'scale' is zero.
void nscale8_video( uint8_t* leds, uint16_t num_leds, uint8_t scale);

// fadeToBlackBy and fade_raw - reduce the brightness of an array
//                              of pixels all at once.  These
//                              functions will eventually fade all
//                              the way to black.
//                              (The two names are synonyms.)
void fadeToBlackBy( uint8_t* leds, uint16_t num_leds, uint8_t fadeBy);
void fade_raw(      uint8_t* leds, uint16_t num_leds, uint8_t fadeBy);

// nscale8 - scale down the brightness of an array of pixels
//           all at once.  This function can scale pixels all the
//           way down to black even if 'scale' is not zero.
void nscale8(       uint8_t* leds, uint16_t num_leds, uint8_t scale);

// fadeUsingColor - scale down the brightness of an array of pixels,
//                  as though it were seen through a transparent
//                  filter with the specified color.
//                  For example, if the colormask is
//                    CRGB( 200, 100, 50)
//                  then the pixels' red will be faded to 200/256ths,
//                  their green to 100/256ths, and their blue to 50/256ths.
//                  This particular example give a 'hot fade' look,
//                  with white fading to yellow, then red, then black.
//                  You can also use colormasks like CRGB::Blue to
//                  zero out the red and green elements, leaving blue
//                  (largely) the same.
void fadeUsingColor( uint8_t* leds, uint16_t numLeds, uint32_t colormask);


// Pixel blending
//
// blend - computes a new color blended some fraction of the way
//         between two other colors.
uint32_t  blend( uint32_t p1, uint32_t p2, fract8 amountOfP2 );

// blend - computes a new color blended array of colors, each
//         a given fraction of the way between corresponding
//         elements of two source arrays of colors.
//         Useful for blending palettes.
uint8_t* blend_leds( uint8_t* src1, uint8_t* src2, uint8_t* dest,
             uint16_t count, fract8 amountOfsrc2 );

// nblend - destructively modifies one color, blending
//          in a given fraction of an overlay color
uint32_t* nblend( uint32_t *existing, uint32_t overlay, fract8 amountOfOverlay );

// nblend - destructively blends a given fraction of
//          a new color array into an existing color array
void  nblend_leds( uint8_t* existing, uint8_t* overlay, uint16_t count, fract8 amountOfOverlay);
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
void blur1d( uint8_t* leds, uint16_t numLeds, fract8 blur_amount);


// CRGB HeatColor( uint8_t temperature)
//
// Approximates a 'black body radiation' spectrum for
// a given 'heat' level.  This is useful for animations of 'fire'.
// Heat is specified as an arbitrary scale from 0 (cool) to 255 (hot).
// This is NOT a chromatically correct 'black body radiation'
// spectrum, but it's surprisingly close, and it's fast and small.
uint32_t HeatColor( uint8_t temperature);


// Palettes
//
// RGB Palettes map an 8-bit value (0..255) to an RGB color.
//
// You can create any color palette you wish; a couple of starters
// are provided: Forest, Clouds, Lava, Ocean, Rainbow, and Rainbow Stripes.
//
// Palettes come in the traditional 256-entry variety, which take
// up 768 bytes of RAM, and lightweight 16-entry varieties.  The 16-entry
// variety automatically interpolates between its entries to produce
// a full 256-element color map, but at a cost of only 48 bytes or RAM.
//
// Basic operation is like this: (example shows the 16-entry variety)
// 1. Declare your palette storage:
//    CRGBPalette16 myPalette;
//
// 2. Fill myPalette with your own 16 colors, or with a preset color scheme.
//    You can specify your 16 colors a variety of ways:
//      CRGBPalette16 myPalette(
//          CRGB::Black,
//          CRGB::Black,
//          CRGB::Red,
//          CRGB::Yellow,
//          CRGB::Green,
//          CRGB::Blue,
//          CRGB::Purple,
//          CRGB::Black,
//
//          0x100000,
//          0x200000,
//          0x400000,
//          0x800000,
//
//          CHSV( 30,255,255),
//          CHSV( 50,255,255),
//          CHSV( 70,255,255),
//          CHSV( 90,255,255)
//      );
//
//    Or you can initiaize your palette with a preset color scheme:
//      myPalette = RainbowStripesColors_p;
//
// 3. Any time you want to set a pixel to a color from your palette, use
//    "ColorFromPalette(...)" as shown:
//
//      uint8_t index = /* any value 0..255 */;
//      leds[i] = ColorFromPalette( myPalette, index);
//
//    Even though your palette has only 16 explicily defined entries, you
//    can use an 'index' from 0..255.  The 16 explicit palette entries will
//    be spread evenly across the 0..255 range, and the intermedate values
//    will be RGB-interpolated between adjacent explicit entries.
//
//    It's easier to use than it sounds.
//

// Convert a 16-entry palette to a 256-entry palette
void UpscalePalette16_256(uint32_t *srcpal16, uint32_t *destpal256);

// Convert a 16-entry palette to a 32-entry palette
void UpscalePalette16_32(uint32_t *srcpal16, uint32_t *destpal32);

// Convert a 32-entry palette to a 256-entry palette
void UpscalePalette32_256(uint32_t *srcpal32, uint32_t *destpal256);


typedef enum { NOBLEND=0, LINEARBLEND=1 } TBlendType;

uint32_t ColorFromPalette16( const uint32_t *pal,
                      uint8_t index,
                      uint8_t brightness/*=255*/,
                      TBlendType blendType/*=LINEARBLEND*/);

uint32_t ColorFromPalette256( const uint32_t *pal,
                       uint8_t index,
                       uint8_t brightness/*=255*/,
                       TBlendType blendType/*=NOBLEND*/ );

uint32_t ColorFromPalette32( const uint32_t *pal,
                      uint8_t index,
                      uint8_t brightness/*=255*/,
                      TBlendType blendType/*=LINEARBLEND*/);

// nblendPaletteTowardPalette:
//               Alter one palette by making it slightly more like
//               a 'target palette', used for palette cross-fades.
//
//               It does this by comparing each of the R, G, and B channels
//               of each entry in the current palette to the corresponding
//               entry in the target palette and making small adjustments:
//                 If the Red channel is too low, it will be increased.
//                 If the Red channel is too high, it will be slightly reduced.
//                 ... and likewise for Green and Blue channels.
//
//               Additionally, there are two significant visual improvements
//               to this algorithm implemented here.  First is this:
//                 When increasing a channel, it is stepped up by ONE.
//                 When decreasing a channel, it is stepped down by TWO.
//               Due to the way the eye perceives light, and the way colors
//               are represented in RGB, this produces a more uniform apparent
//               brightness when cross-fading between most palette colors.
//
//               The second visual tweak is limiting the number of changes
//               that will be made to the palette at once.  If all the palette
//               entries are changed at once, it can give a muddled appearance.
//               However, if only a few palette entries are changed at once,
//               you get a visually smoother transition: in the middle of the
//               cross-fade your current palette will actually contain some
//               colors from the old palette, a few blended colors, and some
//               colors from the new palette.
//               The maximum number of possible palette changes per call
//               is 48 (sixteen color entries time three channels each).
//               The default 'maximim number of changes' here is 12, meaning
//               that only approximately a quarter of the palette entries
//               will be changed per call.
void nblendPaletteTowardPalette16( uint32_t *currentPalette,
                                uint32_t *targetPalette,
                                uint8_t maxChanges/*=24*/);




//  You can also define a static RGB palette very compactly in terms of a series
//  of connected color gradients.
//  For example, if you want the first 3/4ths of the palette to be a slow
//  gradient ramping from black to red, and then the remaining 1/4 of the
//  palette to be a quicker ramp to white, you specify just three points: the
//  starting black point (at index 0), the red midpoint (at index 192),
//  and the final white point (at index 255).  It looks like this:
//
//    index:  0                                    192          255
//            |----------r-r-r-rrrrrrrrRrRrRrRrRRRR-|-RRWRWWRWWW-|
//    color: (0,0,0)                           (255,0,0)    (255,255,255)
//
//  Here's how you'd define that gradient palette:
//
//    DEFINE_GRADIENT_PALETTE( black_to_red_to_white_p ) {
//          0,      0,  0,  0,    /* at index 0, black(0,0,0) */
//        192,    255,  0,  0,    /* at index 192, red(255,0,0) */
//        255,    255,255,255    /* at index 255, white(255,255,255) */
//    };
//
//  This format is designed for compact storage.  The example palette here
//  takes up just 12 bytes of PROGMEM (flash) storage, and zero bytes
//  of SRAM when not currently in use.
//
//  To use one of these gradient palettes, simply assign it into a
//  CRGBPalette16 or a CRGBPalette256, like this:
//
//    CRGBPalette16 pal = black_to_red_to_white_p;
//
//  When the assignment is made, the gradients are expanded out into
//  either 16 or 256 palette entries, depending on the kind of palette
//  object they're assigned to.
//
//  IMPORTANT NOTES & CAVEATS:
//
//  - The last 'index' position MUST BE 255!  Failure to end with
//    index 255 will result in program hangs or crashes.
//
//  - At this point, these gradient palette definitions MUST BE
//    stored in PROGMEM on AVR-based Arduinos.  If you use the
//    DEFINE_GRADIENT_PALETTE macro, this is taken care of automatically.
//

#define DEFINE_GRADIENT_PALETTE(X) \
  extern const TProgmemRGBGradientPalette_byte X[] FL_PROGMEM =

#define DECLARE_GRADIENT_PALETTE(X) \
  extern const TProgmemRGBGradientPalette_byte X[] FL_PROGMEM


// Functions to apply gamma adjustments, either:
// - a single gamma adjustment to a single scalar value,
// - a single gamma adjustment to each channel of a CRGB color, or
// - different gamma adjustments for each channel of a CRFB color.
//
// Note that the gamma is specified as a traditional floating point value
// e.g., "2.5", and as such these functions should not be called in
// your innermost pixel loops, or in animations that are extremely
// low on program storage space.  Nevertheless, if you need these
// functions, here they are.
//
// Furthermore, bear in mind that CRGB leds have only eight bits
// per channel of color resolution, and that very small, subtle shadings
// may not be visible.
uint8_t  applyGamma_videoY( uint8_t brightness, float gamma);
uint32_t applyGamma_videoRGB( uint32_t orig, float gamma);
uint32_t applyGammaRGB_videoRGB( uint32_t orig, float gammaR, float gammaG, float gammaB);
// The "n" versions below modify their arguments in-place.
uint32_t *napplyGamma_videoRGB( uint32_t *rgb, float gamma);
uint32_t *napplyGammaRGB_videoRGB( uint32_t *rgb, float gammaR, float gammaG, float gammaB);
void   napplyGamma_videoLeds( uint8_t *rgbarray, uint16_t count, float gamma);
void   napplyGammaRGB_videoLeds( uint8_t* rgbarray, uint16_t count, float gammaR, float gammaG, float gammaB);

///@}
#endif
