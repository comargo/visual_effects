/*
 * color_types.h
 *
 *  Created on: 15 дек. 2021 г.
 *      Author: Кирилл
 */

#ifndef COLOR_TYPES_H_
#define COLOR_TYPES_H_

#include <stdint.h>

#define RED(c) ((uint8_t)(((c)>>16)&0xFF))
#define GREEN(c) ((uint8_t)(((c)>>8)&0xFF))
#define BLUE(c) ((uint8_t)((c)&0xFF))

#define RGB(r,g,b) ((uint32_t)(((r)<<16)|((g)<<8)|(b)))

#define HUE(c) ((uint8_t)(((c)>>16)&0xFF))
#define SAT(c) ((uint8_t)(((c)>>8)&0xFF))
#define VAL(c) ((uint8_t)((c)&0xFF))

#define HSV(h,s,v) ((uint32_t)(((h)<<16)|((s)<<8)|(v)))


#endif /* COLOR_TYPES_H_ */
