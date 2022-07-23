#ifndef FSM_MODULE_H
#define FSM_MODULE_H

typedef struct
{
    uint8_t cur_state;                  /* 当前状态 */
    uint8_t next_state;                 /* 下一个状态 */
    void (*transfer_condition)(void *); /* 状态转移条件 */
    void (*transfer_action)(void *);    /* 状态转移动作 */
}fsm_table_t;

typedef struct
{
    fsm_table_t *fsm_table;              /* 状态转移表 */
    uint8_t cur_state;                  /* 当前状态 */
    uint8_t transfer_num;               /* 状态迁移路径 */
}fsm_t;

void fsm_init(fsm_t *pfsm, fsm_table_t *ptable, uint8_t cur_state, uint8_t transnum);
void fsm_eventhandle(fsm_t *pfsm, uint8_t event, void *param);

#endif