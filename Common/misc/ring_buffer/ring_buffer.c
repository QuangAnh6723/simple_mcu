/*
 * ring_buffer.c
 *
 *  Created on: Mar 25, 2026
 *      Author: AnhLe
 */

#include "ring_buffer.h"
#include "misc/my_inc/my_inc.h"

ringbufError_t rb_init(ringbuffer_t *rb)
{
	if (rb == NULL)
	{
		return RB_NOT_VALID;
	}
	rb->head = 0;
	rb->tail = 0;

	return RB_OK;
}

ringbufError_t rb_clear(ringbuffer_t *rb)
{
	return rb_init(rb);
}

ringbufError_t rb_push(ringbuffer_t *rb ,uint8_t data[], uint16_t len)
{
	if (rb == NULL || data == NULL)
	{
		return RB_NOT_VALID;
	}

	if (len > rb_remain(rb))
	{
		return RB_NOT_ENOUGH_SPACE;
	}

	for (uint16_t i = 0; i < len; i++)
	{
		rb->buffer[rb->head++] = data[i];
		if(rb->head == MAX_RING_BUFFER)
		{
			rb->head = 0;
		}
	}

	return RB_OK;
}

ringbufError_t rb_pop(ringbuffer_t *rb ,uint8_t data[], uint16_t len)
{
	if (rb == NULL || data == NULL)
	{
		return RB_NOT_VALID;
	}

	if ( len > rb_available(rb))
	{
		return RB_NOT_ENOUGH_DATA;
	}

	for (uint16_t i = 0; i < len; i++)
	{
		data[i] = rb->buffer[rb->tail++];
		if(rb->tail == MAX_RING_BUFFER)
		{
			rb->tail = 0;
		}

	}
	return RB_OK;
}

uint16_t rb_remain(ringbuffer_t *rb)
{
	if (rb == NULL)
    {
        return 0;
    }

    uint16_t available = rb_available(rb);
    if (available >= MAX_RING_BUFFER)
    {
        return 0;
    }

    return (uint16_t)(MAX_RING_BUFFER - available - 1U);
}

uint16_t rb_available(ringbuffer_t *rb)
{
	if (rb == NULL)
    {
        return 0;
    }
	uint16_t head = rb->head;
	uint16_t tail = rb->tail;

	if (head >= tail)
	{
		return head - tail;
	}
	return MAX_RING_BUFFER - tail + head;
}


