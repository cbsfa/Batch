#ifndef BATCH_ONE_h
#define BATCH_ONE_h

#include "Struct.h"

void Running_One(queue<JcbPoint>jcb);//运行
void FCFS_One(Jcb jcb[], int n);//先来先服务作业调度
void SFC_One(Jcb jcb[], int n);//最短作业优先作业调度
void HRFC_One(Jcb jcb[], int n);//最高响应比作业调度

void Running_One(queue<JcbPoint>jcb)//运行
{
    JcbPoint jcbPoint;
    jcbPoint = jcb.front();
    Time time;
    time = jcbPoint->enter;
    time = jcbPoint->SetAndGet(time);
    jcb.pop();
    while (!jcb.empty())
    {
        Time over = jcbPoint->over;
        jcbPoint = jcb.front();
        jcb.pop();
        if (jcbPoint->enter.sum > over.sum) time = jcbPoint->enter;
        time = jcbPoint->SetAndGet(time);
    }
}
void FCFS_One(Jcb jcb[], int n)//先来先服务作业调度
{
    queue<JcbPoint>qjcb;
    Sort_No(jcb, n);
    Sort_Enter(jcb, n);
    for (int i = 0; i < n; i++) qjcb.push(&jcb[i]);
    Running_One(qjcb);
    Display(jcb, n);
    InitJcb(jcb, n);
}
void SFC_One(Jcb jcb[], int n)//最短作业优先作业调度
{
    queue<JcbPoint>qjcb;
    qjcb.push(&jcb[0]);
    Time time = jcb[0].GetTime();
    jcb[0].state = true;
    int t = n - 1;
    while (t)
    {
        int i = 1;
        while (jcb[i].state) i++;
        for (int j = i; j < n; j++)
        {
            if (jcb[j].enter.sum > time.sum) break;
            if (!jcb[j].state && (jcb[i].operation > jcb[j].operation)) i = j;
        }
        qjcb.push(&jcb[i]);
        jcb[i].state = true;
        time.Add(jcb[i].operation);
        t--;
    }
    Running_One(qjcb);
    Display(jcb, n);
    InitJcb(jcb, n);
}
void HRFC_One(Jcb jcb[], int n)//最高响应比作业调度
{
    queue<JcbPoint>qjcb;
    qjcb.push(&jcb[0]);
    Time time = jcb[0].GetTime();
    int t = n - 1;
    jcb[0].state = true;
    while (t)
    {
        int i = 1;
        while (jcb[i].state) i++;
        for (int j = i; j < n; j++)
        {
            if (jcb[j].enter.sum > time.sum) break;
            if (!jcb[j].state)
            {
                double time_i = time.sum - jcb[i].enter.sum;
                double time_j = time.sum - jcb[j].enter.sum;
                time_i /= jcb[i].operation;
                time_j /= jcb[j].operation;
                if (time_i < time_j) i = j;
            }
        }
        qjcb.push(&jcb[i]);
        jcb[i].state = true;
        time.Add(jcb[i].operation);
        t--;
    }
    Running_One(qjcb);
    Display(jcb, n);
    InitJcb(jcb, n);
}

#endif