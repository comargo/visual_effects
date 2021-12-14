/*
 * hsv2rgb.h
 *
 *  Created on: Dec 14, 2021
 *      Author: cyril
 */

#ifndef HSV2RGB_H_
#define HSV2RGB_H_

#include <stdint.h>

#define RED(c) ((uint8_t)(((c)>>16)&0xFF))
#define GREEN(c) ((uint8_t)(((c)>>8)&0xFF))
#define BLUE(c) ((uint8_t)((c)&0xFF))

#define RGB(r,g,b) ((uint32_t)(((r)<<16)|((g)<<8)|(b)))

#define HUE(c) ((uint8_t)(((c)>>16)&0xFF))
#define SAT(c) ((uint8_t)(((c)>>8)&0xFF))
#define VAL(c) ((uint8_t)((c)&0xFF))

#define HSV(h,s,v) ((uint32_t)(((h)<<16)|((s)<<8)|(v)))

uint32_t hsv2rgb_raw(uint32_t hsv);
uint32_t hsv2rgb_spectrum( uint32_t hsv);
uint32_t hsv2rgb_rainbow( uint32_t hsv);

#endif /* HSV2RGB_H_ */
