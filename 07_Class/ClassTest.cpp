/*
1. 面对对象编程思想：抽象、封装、继承、多态
2. 简单抽象方法：对象分类

类：关键字class
语法：数据和函数写在类里面，函数声明写在头文件中，函数实现写在cpp文件中
访问标号：
1. public公有的，类外面可以访问类里面的成员
2. private私有的，类外面不可以访问类里面的成员
3. struct默认public权限，class默认private权限
*/

#include <iostream>
using namespace std;
#include "Class.h"

int main()
{
    CPoint pt1;
    CPoint pt2;
    pt2.InitPoint(5, 12);
    cout << "distance:" << pt1.Distance(&pt2) << endl;

    CRectangle Rectangle;
    Rectangle.SetLength(5.0);
    Rectangle.SetWidth(6.0);
    cout << "area:" << Rectangle.AreaOfRectangle() << endl;

    CDate Date;
    Date.SetDate(2020, 1, 1);
    cout << "isleapyear:" << Date.IsLeapYear() << " and weekday:" << Date.GetWeekday() << endl;

    CTime Time;
    Time.SetTime(9, 30, 30);
    cout << "totalsecond:" << Time.GetTotalSecond() << endl;

    CDepositor Depositor;
    Depositor.SetDepositor(20210123, (char*)"xiaoxin", 99999.99);
    cout << Depositor.GetID() << " " << Depositor.GetName() << " " << Depositor.GetDeposit() << endl;
    Depositor.SaveMoney(6);
    cout << Depositor.GetID() << " " << Depositor.GetName() << " " << Depositor.GetDeposit() << endl;
    Depositor.DrawMoney(3);
    cout << Depositor.GetID() << " " << Depositor.GetName() << " " << Depositor.GetDeposit() << endl;

    CBookInfo pBookInfo;
    pBookInfo.SetBookInfo((char*)"面对对象编程思想", 36.9, Date);
    cout << pBookInfo.GetBookName() << " " << pBookInfo.GetBookPrice() << " " << pBookInfo.GetPublishDate().GetYear() << endl;
    cout << "publishyear:" << pBookInfo.GetPublishYear() << endl;

    return 0;
}
