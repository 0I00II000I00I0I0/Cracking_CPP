#include <iostream>
using namespace std;
#include "FunctionOverload.h"

//默认参数只能在声明中提供，默认参数只能从右向左提供
void Hello(const char* name, const char* text = "hello");
void Hello(const char* name, const char* text)
{
    cout << text << name << endl;
}

/*
函数重载条件：
1、函数名相同，参数类型不同，参数个数不同，参数位置不用
2、返回值类型不同，调用约定不同，不构成重载
3、作用域不同，不构成重载
4、函数重载原理：名称粉碎
5、二义性：函数重载调用的时候，类型精确匹配，默认参数也会影响
*/
int Add(int a, int b)
{
    return a + b;
}

float Add(float a, float b)
{
    return a + b;
}

/*
float Add(float a, float b, float c = 0)
{
    return a + b + c;
}
*/

int main()

{
    //可以给参数提供一个默认值，当调用函数时，如果没有提供实参，则使用默认参数
    Hello("xiaoxin");
    Hello("xiaoming", "hi");
    //函数重载
    cout << "add(int,int):" << Add(1, 2) << endl;
    cout << "add(float,float):" << Add(3.3f, 6.6f) << endl;
    cout << "add(int,int):" << Add(3, (int)3.3f) << endl;
    //比较大小
    cout << "max(a,b):" << Max(8, 9) << endl;
    cout << "max(a,b):" << Max(8.0, 9.9) << endl;
    //求偶数
    cout << "isevennum(a):" << IsEvenNum(8) << endl;
    cout << "isevennum(a):" << IsEvenNum(8.0) << endl;
    cout << "isevennum(a):" << IsEvenNum(8.9) << endl;
    cout << "isevennum(a):" << IsEvenNum(9.0) << endl;
    cout << "isevennum(a):" << IsEvenNum(9.9) << endl;
    //求平方
    cout << "gesquare(a):" << GetSquare(9) << endl;
    cout << "gesquare(a):" << GetSquare(9.9) << endl;
    //求绝对值
    cout << "getabsolute(a):" << GetAbsolute(9) << endl;
    cout << "getabsolute(a):" << GetAbsolute(-9) << endl;
    cout << "getabsolute(a):" << GetAbsolute(9.0) << endl;
    cout << "getabsolute(a):" << GetAbsolute(-9.0) << endl;
    //求三角形面积
    cout << "areatriangle(a,b):" << AreaTriangle(9, 9) << endl;
    cout << "areatriangle(a,b):" << AreaTriangle(9.0, 9.0) << endl;

    return 0;
}
