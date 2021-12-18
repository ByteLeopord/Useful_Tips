#include "cycle_queue_ipc.h"

uint8_t cycle_queue_buffer[1024 * 4];
cycle_queue_t que = {0};

cbuf_handle_t cycle_buf_init(uint8_t *buffer, size_t size)
{
    assert(buffer && size);
    cbuf_handle_t cbuf = &que;

    cbuf->buf = cycle_queue_buffer;
    cbuf->max = size;
    cycle_buf_reset(cbuf);

    return cbuf;
}

void cycle_buf_free(cbuf_handle_t cbuf)
{
    cbuf = NULL;
}

void cycle_buf_reset(cbuf_handle_t cbuf)
{
    cbuf->head = 0;
    cbuf->tail = 0;
    cbuf->is_full = false;
}

void cycle_buf_put(cbuf_handle_t cbuf, uint8_t data);
int cycle_buf_put2(cbuf_handle_t cbuf, uint8_t data);
int cycle_buf_get(cbuf_handle_t cbuf, uint8_t *data);
bool cycle_buf_empty(cbuf_handle_t cbuf)
{
    return (!cbuf->is_full && (cbuf->head == cbuf->tail));
}

bool cycle_buf_full(cbuf_handle_t cbuf)
{
    return cbuf->is_full;
}

size_t cycle_buf_capacity(cbuf_handle_t cbuf)
{
    return cbuf->max;
}

size_t cycle_buf_size(cbuf_handle_t cbuf)
{
    size_t size = cbuf->max;

    if(!cbuf->full)
    {
        if(cbuf->head >= cbuf->tail)
        {
            size = (cbuf->head - cbuf->tail);
        }
        else
        {
            size = (cbuf->max + cbuf->head - cbuf->tial);
        }
    }
    return size;
}
