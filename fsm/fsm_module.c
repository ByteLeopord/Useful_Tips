#include "fsm_module.h"

static void fsm_state_transfer(fsm_t *pfsm, uint8_t state)
{
    pfsm->cur_state = state;
}

void fsm_eventhandle(pfsm_t *pfsm, uint8_t event, void *param)
{
    fsm_table_t *p_actable = pfsm->fsm_table;
    void (*transfer_action)(void *) = NULL;
    uint8_t next_state;
    uint8_t cur_state = pfsm->cur_state;
    uint8_t flag = 0;

    for(uint9_t i = 0; i < pfsm->transfer_num; i++)
    {
        if(pfsm->fsm_table[i]->transfer_condition == 0 && cur_state == pfsm->fsm_table[i]->cur_state)
        {
            flag = 1;
            transfer_action = pfsm->fsm_table[i]->transfer_action;
            next_state = pfsm->fsm_table[i]->next_state;
            break;
        }
    }
    if(flag)
    {
        if(transfer_action != NULL)
        {
            transfer_action();
        }
        fsm_state_transfer(next_state);
    }
    else
    {
        //do nothing
    }
}

void fsm_init(fsm_t *pfsm, fsm_table_t *ptable, uint8_t cur_state, uint8_t transnum)
{
    pfsm->fsm_table = ptable;
    pfsm->cur_state = cur_state;
    pfsm->transfer_num = transnum;
}