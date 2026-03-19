/*
 * i2c_helper.c
 *
 *  Created on: Mar 20, 2026
 *      Author: AnhLe
 */

#include "main.h"
#include "utils/utils.h"

void i2c_scanBus(I2C_HandleTypeDef *hi2c)
{
	HAL_StatusTypeDef status = HAL_ERROR;
	uint8_t trials = 1;
	uint8_t timeout = 10;

	for (uint8_t i = 0; i < 127; i ++)
	{
		uint8_t addr = i << 1;
		status = HAL_I2C_IsDeviceReady(hi2c, addr ,trials, timeout);

		if(status == HAL_OK)
		{
			PRINT_DEBUG("I2C have device 0x%02X, dec %d", addr, addr);
		}
	}
}
