#ifndef BATCH_STRUCT_H
#define BATCH_STRUCT_H

#include <iostream>
#include <queue>
using namespace std;

typedef struct Time//时间
{
    int hour;//小时
    int minute;//分钟
    int sum;//总分钟
    Time() :hour(0), minute(0), sum(0) {}//初始化
    Time(int hour, int minute) :hour(hour), minute(minute), sum(0)//初始化（赋值）
    {
        UpdateSum();
    }
    void Add(int _minute)//增加时间
    {
        hour += (minute + _minute) / 60;
        minute = (minute + _minute) % 60;
        UpdateSum();
    }
    void UpdateSum()//更新总分钟
    {
        sum = hour * 60 + minute;
    }
}Time;
typedef struct Jcb//作业
{
    int no;//作业编号
    int operation;//估计运行时间
    int turnover;//周转时间
    double weighted;//带权周转时间
    bool state;//标记作业是否进入运行状态
    Time enter;//进入时间
    Time start;//开始时间
    Time over;//结束时间
    Jcb() :no(0), operation(0), turnover(0), weighted(0), state(false), enter(), start(), over() {}//初始化
    Jcb(int no, int operation, int hour, int minute) :no(no), operation(operation), turnover(0), weighted(0), state(false), enter(hour, minute), start(), over() {}//初始化（赋值）
    Time GetTime()//返回进入时间+估计运行时间
    {
        Time time = enter;
        time.Add(operation);
        return time;
    }
    void SetStart()//设置开始时间
    {
        start = enter;
    }
    void SetStart(Time time)//设置开始时间
    {
        start = time;
    }
    void SetOver()//设置结束时间
    {
        over = start;
        over.Add(operation);
    }
    void SetOver(Time time)//设置结束时间
    {
        over = time;
    }
    void SetOver(int _operation)//设置结束时间
    {
        over = start;
        over.Add(_operation);
    }
    void SetTurnover()//设置周转时间
    {
        turnover = over.sum - enter.sum;
    }
    void SetWeighted()//设置带权周转时间
    {
        weighted = turnover / (double)operation;
    }
    void Display() const//输出
    {
        printf("Job%2d\t%2d:%02d\t    %-14d\t  %2d:%02d\t    %2d:%02d\t   %-14d\t%-5.2f\t\n",
            no,//作业编号
            enter.hour, enter.minute,//进入时间
            operation,//估计运行时间
            start.hour, start.minute,//开始时间
            over.hour, over.minute,//结束时间
            turnover,//周转时间
            weighted);//带权周转时间
    }
    void Init()//初始化
    {
        turnover = 0;
        weighted = 0;
        state = false;
        start = over = Time();
    }
    Time SetAndGet(int _operation, Time time)//设置开始时间、周转时间、带权周转时间，返回结束时间（传入估计运行时间）
    {
        state = true;
        start = time;
        SetOver(_operation);
        SetTurnover();
        SetWeighted();
        time = over;
        return time;
    }
    Time SetAndGet(Time time)//设置开始时间、周转时间、带权周转时间，返回结束时间（不传入估计运行时间）
    {
        state = true;
        start = time;
        SetOver();
        SetTurnover();
        SetWeighted();
        time = over;
        return time;
    }
}Jcb, * JcbPoint;

void CreateJcb(Jcb jcb[], int n);//创建作业数组
void InitJcb(Jcb jcb[], int n);//初始化作业数组
void Display(Jcb jcb[], int n);//输出
void Sort_No(Jcb jcb[], int n);//按照作业编号排序
void Sort_Enter(Jcb jcb[], int n);//按照进入时间排序

void CreateJcb(Jcb jcb[], int n)//创建作业数组
{
    cout << "请依次输入作业信息：" << endl;
    for (int i = 0; i < n; i++)
    {
        int operation, hour, minute;
        cout << i + 1 << "." << endl;
        cout << "估计运行时间：";
        cin >> operation;
        cout << "进入时间（小时）：";
        cin >> hour;
        cout << "进入时间（分钟）：";
        cin >> minute;
        jcb[i] = Jcb(i + 1, operation, hour, minute);
    }
    cout << endl;
    Sort_Enter(jcb, n);
}
void InitJcb(Jcb jcb[], int n)//初始化作业数组
{
    for (int i = 0; i < n; i++) jcb[i].Init();
    Sort_Enter(jcb, n);
}
void Display(Jcb jcb[], int n)//输出
{
    double T = 0, W = 0;
    Sort_No(jcb, n);
    cout << "作业    进入时间      估计运行时间（分钟）  开始时间   结束时间     周转时间（分钟）    带权周转时间" << endl;
    for (int i = 0; i < n; i++)
    {
        T += jcb[i].turnover;
        W += jcb[i].weighted;
        jcb[i].Display();
    }
    T /= n;
    W /= n;
    printf("作业平均周转时间 T=%.2lf 分钟\n", T);
    printf("作业带权平均周转时间 W=%.3lf\n\n\n", W);
}
void Sort_No(Jcb jcb[], int n)//按照作业编号排序
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (jcb[i].no > jcb[j].no)
            {
                Jcb temp = jcb[i];
                jcb[i] = jcb[j];
                jcb[j] = temp;
            }
        }
    }
}
void Sort_Enter(Jcb jcb[], int n)//按照进入时间排序
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (jcb[i].enter.sum > jcb[j].enter.sum)
            {
                Jcb temp = jcb[i];
                jcb[i] = jcb[j];
                jcb[j] = temp;
            }
        }
    }
}

#endif