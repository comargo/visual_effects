/*
 * hsv2rgb.h
 *
 *  Created on: Dec 14, 2021
 *      Author: cyril
 */

#ifndef HSV2RGB_H_
#define HSV2RGB_H_

#include <stdint.h>

uint32_t hsv2rgb_raw(uint32_t hsv);
uint32_t hsv2rgb_spectrum( uint32_t hsv);
uint32_t hsv2rgb_rainbow( uint32_t hsv);

#endif /* HSV2RGB_H_ */
