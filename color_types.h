/*
 * color_types.h
 *
 *  Created on: 15 дек. 2021 г.
 *      Author: Кирилл
 */

#ifndef COLOR_TYPES_H_
#define COLOR_TYPES_H_

#include <stdint.h>

typedef union RGB
{
	uint8_t raw[3];
	struct
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
	};
} RGB;

typedef union NRGB
{
	uint8_t raw[4];
	struct
	{
		uint8_t index;
		RGB rgb;
	};
	uint32_t dw;
} NRGB;

typedef union HSV
{
	struct
	{
		uint8_t h;
		uint8_t s;
		uint8_t v;
	};
	uint8_t raw[3];
} HSV;

#endif /* COLOR_TYPES_H_ */
