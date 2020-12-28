#ifndef BATCH_TEST_H
#define BATCH_TEST_H

#include "One.h"
#include "Two.h"

void Test1();//单道环境——同一批次作业——不同算法
void Test2();//单道环境——不同批次作业——同一算法
void Test3();//两道环境——同一批次作业——不同算法
void Test4();//两道环境——不同批次作业——同一算法

void Test1()//单道环境——同一批次作业——不同算法
{
    int n;
    JcbPoint jcb;
    cout << "——————————————————单道环境——同一批次作业——不同算法——————————————————" << endl;
    cout << "请输入作业数目：";
    cin >> n;
    cout << endl;
    jcb = new Jcb[n];
    CreateJcb(jcb, n);
    cout << endl;
    cout << "——————————————————单道环境——同一批次作业——不同算法——————————————————" << endl;
    cout << endl;
    cout << "先来先服务作业调度：" << endl;
    FCFS_One(jcb, n);
    cout << "最短时间优先服务作业调度：" << endl;
    SFC_One(jcb, n);
    cout << "最高响应比优先作业调度算法：" << endl;
    HRFC_One(jcb, n);
}
void Test2()//单道环境——不同批次作业——同一算法
{
    int n1, n2, n3;
    JcbPoint jcb1, jcb2, jcb3;
    cout << "——————————————————单道环境——不同批次作业——同一算法——————————————————" << endl;
    cout << "批次一作业：" << endl;
    cout << "请输入作业数目：";
    cin >> n1;
    cout << endl;
    jcb1 = new Jcb[n1];
    CreateJcb(jcb1, n1);
    cout << "批次二作业：" << endl;
    cout << "请输入作业数目：";
    cin >> n2;
    cout << endl;
    jcb2 = new Jcb[n2];
    CreateJcb(jcb2, n2);
    cout << "批次三作业：" << endl;
    cout << "请输入作业数目：";
    cin >> n3;
    cout << endl;
    jcb3 = new Jcb[n3];
    CreateJcb(jcb3, n3);
    cout << endl;
    cout << "——————————————————单道环境——不同批次作业——同一算法——————————————————" << endl;
    cout << "——————————————————————先来先服务作业调度———————————————————————" << endl;
    cout << "批次一作业：" << endl;
    FCFS_One(jcb1, n1);
    cout << "批次二作业：" << endl;
    FCFS_One(jcb2, n2);
    cout << "批次三作业：" << endl;
    FCFS_One(jcb3, n3);
    cout << "——————————————————————最短优先服务作业调度——————————————————————" << endl;
    cout << "批次一作业：" << endl;
    SFC_One(jcb1, n1);
    cout << "批次二作业：" << endl;
    SFC_One(jcb2, n2);
    cout << "批次三作业：" << endl;
    SFC_One(jcb3, n3);
    cout << "——————————————————-—--最高响应比优先服务作业调度——————-—————————————--" << endl;
    cout << "批次一作业：" << endl;
    HRFC_One(jcb1, n1);
    cout << "批次二作业：" << endl;
    HRFC_One(jcb2, n2);
    cout << "批次三作业：" << endl;
    HRFC_One(jcb3, n3);
}
void Test3()//两道环境——同一批次作业——不同算法
{
    int n;
    JcbPoint jcb;
    cout << "——————————————————两道环境——同一批次作业——不同算法——————————————————" << endl;
    cout << "请输入作业数目：";
    cin >> n;
    cout << endl;
    jcb = new Jcb[n];
    CreateJcb(jcb, n);
    cout << endl;
    cout << "——————————————————两道环境——同一批次作业——不同算法——————————————————" << endl;
    cout << endl;
    cout << "先来先服务作业调度：" << endl;
    FCFS_Two(jcb, n);
    cout << "最短时间优先服务作业调度：" << endl;
    SFC_Two(jcb, n);
    cout << "最高响应比优先作业调度算法：" << endl;
    HRFC_Two(jcb, n);
}
void Test4()//两道环境——不同批次作业——同一算法
{
    int n1, n2, n3;
    JcbPoint jcb1, jcb2, jcb3;
    cout << "——————————————————两道环境——不同批次作业——同一算法——————————————————" << endl;
    cout << "批次一作业：" << endl;
    cout << "请输入作业数目：";
    cin >> n1;
    cout << endl;
    jcb1 = new Jcb[n1];
    CreateJcb(jcb1, n1);
    cout << "批次二作业：" << endl;
    cout << "请输入作业数目：";
    cin >> n2;
    cout << endl;
    jcb2 = new Jcb[n2];
    CreateJcb(jcb2, n2);
    cout << "批次三作业：" << endl;
    cout << "请输入作业数目：";
    cin >> n3;
    cout << endl;
    jcb3 = new Jcb[n3];
    CreateJcb(jcb3, n3);
    cout << endl;
    cout << "——————————————————两道环境——不同批次作业——同一算法——————————————————" << endl;
    cout << "——————————————————————先来先服务作业调度———————————————————————" << endl;
    cout << "批次一作业：" << endl;
    FCFS_Two(jcb1, n1);
    cout << "批次二作业：" << endl;
    FCFS_Two(jcb2, n2);
    cout << "批次三作业：" << endl;
    FCFS_Two(jcb3, n3);
    cout << "——————————————————————最短优先服务作业调度——————————————————————" << endl;
    cout << "批次一作业：" << endl;
    SFC_Two(jcb1, n1);
    cout << "批次二作业：" << endl;
    SFC_Two(jcb2, n2);
    cout << "批次三作业：" << endl;
    SFC_Two(jcb3, n3);
    cout << "——————————————————-—--最高响应比优先服务作业调度——————-—————————————--" << endl;
    cout << "批次一作业：" << endl;
    HRFC_Two(jcb1, n1);
    cout << "批次二作业：" << endl;
    HRFC_Two(jcb2, n2);
    cout << "批次三作业：" << endl;
    HRFC_Two(jcb3, n3);
}

#endif