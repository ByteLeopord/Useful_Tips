#ifndef FSM_MODULE_H
#define FSM_MODULE_H

typedef struct
{
    uint8_t cur_state;                  /* ��ǰ״̬ */
    uint8_t next_state;                 /* ��һ��״̬ */
    void (*transfer_condition)(void *); /* ״̬ת������ */
    void (*transfer_action)(void *);    /* ״̬ת�ƶ��� */
}fsm_table_t;

typedef struct
{
    fsm_table_t *fsm_table;              /* ״̬ת�Ʊ� */
    uint8_t cur_state;                  /* ��ǰ״̬ */
    uint8_t transfer_num;               /* ״̬Ǩ��·�� */
}fsm_t;

void fsm_init(fsm_t *pfsm, fsm_table_t *ptable, uint8_t cur_state, uint8_t transnum);
void fsm_eventhandle(fsm_t *pfsm, uint8_t event, void *param);

#endif