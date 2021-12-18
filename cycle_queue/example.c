#include "cycle_queue_ipc.h"

#define EXAMPLE_SIZE (1024 * 4)

uint8_t cycle_queue_buffer[EXAMPLE_SIZE];

void main(void)
{
    cbuf_handle_t cbuf = cycle_buf_init(cycle_queue_buffer, EXAMPLE_SIZE);
    bool full = cycle_buf_full(cbuf);
    bool empty = cycle_buf_empty(cbuf);
}