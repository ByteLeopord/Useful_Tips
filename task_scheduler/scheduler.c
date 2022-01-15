#include <stdio.h>
#include "scheduler.h"

/**
 * 接口定义
 */
#define MAX_TASKS 10
static volatile unsigned char cur_task_num = 0;

/**
 * 变量定义
 */
static running_queue_def running_queue[MAX_TASKS] = {0};

/**
 * 函数定义
 */
int create_task(const void (*fun)(), unsigned short period)
{
    unsigned char i;

    if(cur_task_num >= MAX_TASKS)
    {
        return -1;
    }
    running_queue[i].fun = fun;
    running_queue[i].period = period;
    running_queue[i].cnt = 0;

    cur_task_num++;
    return 0;
}

int scheduler_run(void)
{
    unsigned char i;
    for(i = 0; i < cur_task_num; i++)
    {
        if(running_queue[i].cnt > 0)
        {
            running_queue[i].cnt--;
        }
        else
        {
            running_queue[i].cnt = running_queue[i].period;
            running_queue[i].fun();
        }
    }

    return 0;
}
