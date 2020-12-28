#ifndef BATCH_TWO_H
#define BATCH_TWO_H

#include "Struct.h"

void FCFS_Two(Jcb jcb[], int n);//先来先服务作业调度
void SFC_Two(Jcb jcb[], int n);//最短作业优先作业调度
void HRFC_Two(Jcb jcb[], int n);//最高响应比作业调度

void FCFS_Two(Jcb jcb[], int n)//先来先服务作业调度
{
    queue<JcbPoint>qjcb;
    Sort_No(jcb, n);
    Sort_Enter(jcb, n);
    for (int i = 0; i < n; i++) qjcb.push(&jcb[i]);
    JcbPoint jcbPoint;
    jcbPoint = qjcb.front();
    Time time;
    time = jcbPoint->enter;
    time = jcbPoint->SetAndGet(time);
    qjcb.pop();
    while (!qjcb.empty())
    {
        Time over = jcbPoint->over;
        jcbPoint = qjcb.front();
        qjcb.pop();
        if (jcbPoint->enter.sum > over.sum) time = jcbPoint->enter;
        time = jcbPoint->SetAndGet(time);
    }
    Display(jcb, n);
    InitJcb(jcb, n);
}
void SFC_Two(Jcb jcb[], int n)//最短作业优先作业调度
{
    int work1 = 0, work2 = 1, t = 2;
    int* operation = new int[n];
    Time time = jcb[work1].enter;
    for (int i = 0; i < n; i++) operation[i] = jcb[i].operation;
    jcb[work1].state = true;
    jcb[work1].SetStart();
    while (t <= n)
    {
        if (jcb[work2].enter.sum > (jcb[work1].start.sum + operation[work1]))
        {
            jcb[work1].SetAndGet(operation[work1], time);
            time = jcb[work2].enter;
            jcb[work2].state = true;
            jcb[work2].SetStart();
            work1 = work2;
            work2++;
        }
        else if (jcb[work1].operation > jcb[work2].operation)
        {
            operation[work1] += jcb[work2].operation;
            if (t == 2) time = jcb[work2].enter;
            time = jcb[work2].SetAndGet(operation[work2], time);
            work2 = -1;
        }
        else
        {
            jcb[work1].SetAndGet(operation[work1], time);
            time = jcb[work1].over;
            jcb[work2].start = time;
            work1 = work2;
            work2 = -1;
        }
        int i = 1;
        while (jcb[i].state) i++;
        for (int j = i; j < n; j++)
        {
            if (jcb[j].enter.sum > time.sum) break;
            if (!jcb[j].state && jcb[i].operation > jcb[j].operation) i = j;
        }
        work2 = i;
        t++;
        jcb[work2].state = true;
    }
    jcb[work1].SetOver(operation[work1]);
    jcb[work1].SetTurnover();
    jcb[work1].SetWeighted();
    Display(jcb, n);
    InitJcb(jcb, n);
}
void HRFC_Two(Jcb jcb[], int n)//最高响应比作业调度
{
    int work1 = 0, work2 = 1, t = 2;
    int* operation = new int[n];
    Time time = jcb[work1].enter;
    for (int i = 0; i < n; i++) operation[i] = jcb[i].operation;
    jcb[work1].state = true;
    jcb[work1].SetStart();
    while (t <= n)
    {
        if (jcb[work2].enter.sum > (jcb[work1].start.sum + operation[work1]))
        {
            jcb[work1].SetAndGet(operation[work1], time);
            time = jcb[work2].enter;
            jcb[work2].state = true;
            jcb[work2].SetStart();
            work1 = work2;
            work2++;
        }
        else
        {
            double time_work1 = time.sum + operation[work1] - jcb[work1].enter.sum;
            double time_work2 = time.sum + operation[work1] - jcb[work2].enter.sum;
            time_work1 /= operation[work1];
            time_work2 /= operation[work2];
            if (time_work1 < time_work2)
            {
                operation[work1] += jcb[work2].operation;
                if (t == 2) time = jcb[work2].enter;
                time = jcb[work2].SetAndGet(operation[work2], time);
                work2 = -1;
            }
            else
            {
                jcb[work1].SetAndGet(operation[work1], time);
                time = jcb[work1].over;
                jcb[work2].start = time;
                work1 = work2;
                work2 = -1;
            }
        }
        int i = 1;
        while (jcb[i].state) i++;
        for (int j = i; j < n; j++)
        {
            if (jcb[j].enter.sum > time.sum) break;
            if (!jcb[j].state && jcb[i].operation > jcb[j].operation) i = j;
        }
        work2 = i;
        t++;
        jcb[work2].state = true;
    }
    jcb[work1].SetOver(operation[work1]);
    jcb[work1].SetTurnover();
    jcb[work1].SetWeighted();
    Display(jcb, n);
    InitJcb(jcb, n);
}

#endif