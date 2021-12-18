#ifndef CYCLE_QUEUE_IPC
#define CYCLE_QUEUE_IPC

typedef struct CYCLE_BUFFER_T cycle_queue_t;
typedef cycle_queue_t* cbuf_handle_t;
typedef size_t uint32_t;

struct cycle_queue_t
{
    uint8_t *buf;
    size_t head;
    size_t tail;
    size_t max;
    bool is_full;
};

cbuf_handle_t cycle_buf_init(uint8_t *buffer, size_t size);
void cycle_buf_free(cbuf_handle_t cbuf);
void cycle_buf_reset(cbuf_handle_t cbuf);
void cycle_buf_put(cbuf_handle_t cbuf, uint8_t data);
int cycle_buf_put2(cbuf_handle_t cbuf, uint8_t data);
int cycle_buf_get(cbuf_handle_t cbuf, uint8_t *data);
bool cycle_buf_empty(cbuf_handle_t cbuf);
bool cycle_buf_full(cbuf_handle_t cbuf);
size_t cycle_buf_capacity(cbuf_handle_t cbuf);
size_t cycle_buf_size(cbuf_handle_t cbuf);

#endif
