/*
 * muldiv.h
 *
 *  Created on: Dec 14, 2021
 *      Author: cyril
 */

#ifndef MULDIV_H_
#define MULDIV_H_

#include <stdint.h>

inline static uint8_t muldiv8(uint8_t val, uint8_t mul, uint8_t div)
{
	uint32_t ret_val = ((uint32_t) val) * mul / div;
	if (ret_val > UINT8_MAX)
		return UINT8_MAX;
	return ret_val;
}

inline static uint16_t muldiv16(uint16_t val, uint16_t mul, uint16_t div)
{
	uint32_t ret_val = ((uint32_t) val) * mul / div;
	if (ret_val > UINT16_MAX)
		return UINT16_MAX;
	return ret_val;
}

#endif /* MULDIV_H_ */
