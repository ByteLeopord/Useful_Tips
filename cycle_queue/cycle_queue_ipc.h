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

#endif
