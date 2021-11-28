#define SAMPLE_RATE (20000) //unit:Hz
#define IPC_UP_RATE (0.04f) //unit:s
#define LOW_TASK_RATE (0.002f)  //unit:s
#define MAX_BUFFER_LEN (SAMPLE_RATE * IPC_UP_RATE)

typedef struct
{
    uint16_t size;
    uint16_t index;
    float data_buf[MAX_BUFFER_LEN];
}sweep_ipc;
float test_data = 0.001f;

/* 50us */
uint16_t m_block_index = 0;
uint16_t m_buf_index = 0;
float m_sweep_raw[SAMPLE_RATE * LOW_TASK_RATE] = {0.0f};
float data_2ms_buf[SAMPLE_RATE * LOW_TASK_RATE] = {0.0f};
void highrate_interrupt(void)
{
    /* 记录采样数据 */
    data_2ms_buf[m_buf_index++] = test_data;
    /* 复制到待拼接缓冲区 */
    if(m_buf_index >= SAMPLE_RATE*LOW_TASK_RATE)
    {
        m_buf_index = 0;
        m_block_index++;
        memcpy(&m_sweep_raw, &data_2ms_buf, sizeof(float)*SAMPLE_RATE*LOW_TASK_RATE);
        memset(&data_2ms_buf, 0, sizeof(float)*SAMPLE_RATE*LOW_TASK_RATE);
    }
}

/* 2ms */
sweep_ipc m_sweep_tmp;
float data_40ms_buf[MAX_BUFFER_LEN] = {0.0f};
void lowrate_interrupt(void)
{
    /* data拼接 */
    uint16_t buf_init_add = m_block_index * SAMPLE_RATE*LOW_TASK_RATE;
    for(uint16_t i = 0; i < SAMPLE_RATE*LOW_TASK_RATE; i++)
    {
        data_40ms_buf[buf_init_add + i] = m_sweep_raw[i];
    }
    /* 复制到待发送缓冲区 */
    if(m_block_index >= IPC_UP_RATE/LOW_TASK_RATE)
    {
        m_block_index = 0;
        m_sweep_tmp.index++;
        memcpy(&m_sweep_tmp.data_buf, &data_40ms_buf, sizeof(float)*MAX_BUFFER_LEN);
        memset(&data_40ms_buf, 0, sizeof(float)*MAX_BUFFER_LEN);
    }
}

/* 40ms */
sweep_ipc *p_share_sweep_area;
void esc_ipc(void)
{
    *p_share_sweep_area -> size = ;
    *p_share_sweep_area -> index = m_sweep_tmp.index;
    for(uint32_t i = 0; i < MAX_BUFFER_LEN; i++)
    {
        *p_share_sweep_area -> data_buf[i] = m_sweep_tmp.data_buf[i];
    }
    test_data += 0.001f;
}

void main(void)
{

}