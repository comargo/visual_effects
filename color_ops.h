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

static inline uint32_t color_sum(uint32_t c1, uint32_t c2)
{
  return RGB(
      qadd8(RED(c1), RED(c2)),
      qadd8(GREEN(c1), GREEN(c2)),
      qadd8(BLUE(c1), BLUE(c2))
      );
}


#endif /* COLOR_OPS_H_ */
