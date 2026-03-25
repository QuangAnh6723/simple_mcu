/*
 * ring_buffer.h
 *
 *  Created on: Mar 25, 2026
 *      Author: AnhLe
 */

#ifndef MISC_RING_BUFFER_RING_BUFFER_H_
#define MISC_RING_BUFFER_RING_BUFFER_H_

#include "stdint.h"
#include "misc/my_inc/my_inc.h"

#define MAX_RING_BUFFER		1024

typedef struct {
	uint16_t 	head;				// write
	uint16_t 	tail;				// read
	uint8_t 	buffer[MAX_RING_BUFFER];
} ringbuffer_t;

typedef enum {
	RB_OK 				= 0,
	RB_NOT_VALID		= 1,
	RB_NOT_ENOUGH_SPACE = 2,
	RB_NOT_ENOUGH_DATA	= 3,
} ringbufError_t;

ringbufError_t 	rb_init(ringbuffer_t *rb);
ringbufError_t 	rb_clear(ringbuffer_t *rb);
uint16_t		rb_available(ringbuffer_t *rb);
ringbufError_t 	rb_push(ringbuffer_t *rb ,uint8_t data[], uint16_t len);
ringbufError_t 	rb_pop(ringbuffer_t *rb ,uint8_t data[], uint16_t len);
uint16_t 		rb_remain(ringbuffer_t *rb);

#endif /* MISC_RING_BUFFER_RING_BUFFER_H_ */
