#pragma once
/*
编写程序，使用函数重载使以下函数支持各种基本数据类型：
1. 比较两数大小
2. 求偶数
3. 求平方
4. 求绝对值
5. 求三角形的面积
*/
int Max(int a, int b);

double Max(double a, double b);

bool IsEvenNum(int a);

bool IsEvenNum(double a);

int GetSquare(int a);

double  GetSquare(double a);

int GetAbsolute(int a);

double GetAbsolute(double a);

double AreaTriangle(int bottom, int height);

double AreaTriangle(double bottom, double height);
