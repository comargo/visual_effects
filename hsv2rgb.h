/*
 * hsv2rgb.h
 *
 *  Created on: Dec 14, 2021
 *      Author: cyril
 */

#ifndef HSV2RGB_H_
#define HSV2RGB_H_

#include <stdint.h>

RGB hsv2rgb_raw(HSV hsv);
RGB hsv2rgb_spectrum(HSV hsv);
RGB hsv2rgb_rainbow(HSV hsv);

#endif /* HSV2RGB_H_ */
