#ifndef __SCHEDULER_H_
#define __SCHEDULER_H_

typedef struct
{
    void (*fun)();          //运行函数
    unsigned short period;  //周期
    unsigned short cnt;
}running_queue_def;

int create_task(const void (*fun)(), unsigned short period);
int schduler_run();

#endif
