/*
 * color_ops.h
 *
 *  Created on: 15 дек. 2021 г.
 *      Author: Кирилл
 */

#ifndef COLOR_OPS_H_
#define COLOR_OPS_H_

#include "color_types.h"
#include "lib8tion.h"

static inline RGB color_sum(RGB c1, RGB c2)
{
	RGB out = { .r = qadd8(c1.r, c2.r), .g = qadd8(c1.g, c2.g), .b = qadd8(c1.b, c2.b) };
	return out;
}

#endif /* COLOR_OPS_H_ */
