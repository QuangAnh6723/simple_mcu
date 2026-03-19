/*
 * utils.c
 *
 *  Created on: Mar 20, 2026
 *      Author: AnhLe
 */

#include "utils/utils.h"

int _write(int file, char *ptr, int len) {
    SEGGER_RTT_Write(0, ptr, len); // Send data to RTT Channel 0
    return len;
}
