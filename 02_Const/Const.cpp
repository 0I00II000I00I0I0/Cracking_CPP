/*
1. 实现strlen, 使用const保证参数操作的安全性
2. 实现strcpy, 使用const保证参数操作的安全性
3. 实现strcat, 使用const保证参数操作的安全性
4. 实现函数swap交换两数，使用const保证参数的值不可修改
5. 实现函数swap，使用引用完成两数交换
6. 使用引用来操作一个其它的整型局部变量
7. 使用引用来操作一个其它的指针局部变量
8. 编写一个函数实现求圆的面积
9. 编写一个函数实现求长方形的面积 编写一个函数实现求长方体的体积
*/

#include <iostream>
#include "ConstString.h"
using namespace std;
#define VALUE 10000

int main()
{
    //宏会隐式转换，没有类型检查，C++会把const定义的常量进行值替换
    char ch = VALUE;
    cout << "define:" << (int)ch << endl;
    const int CVALUE = 10000;
    char cch = CVALUE;
    cout << "const:" << (int)cch << endl;

    //常量必须初始化，debug版本通过地址能修改，但是结果不能用
    const int nVal = 9;
    *(int*)&nVal = 8;
    cout << "const:" << nVal << endl;

    //const修饰指针，防止误操作，arrNum[0] = 3不行
    const int arrNum[] = { 1,2,3 };

    //const的位置对指针的影响
    int nValA = 8;
    int nValB = 9;
    const int* pConstVal = &nValA;
    pConstVal = &nValB;
    //*pConstVal = nValB不行
    int* const constpVal = &nValA;
    *constpVal = nValB;
    //constpVal = &nValB不行
    const int* const constpConstVal = &nValA;
    //*constpConstVal = nValB不行
    //constpConstVal = &nValB不行

    //const修饰的指针的转换
    const int* pa = nullptr;
    //int* const pb = pa不行
    const int* const pc = pa;
    //int* const pd = pc不行
    const int* pe = pc;

    const char* szHello = "hello";
    const char szName[] = "xiaoxin";
    char szText[16] = { 0 };
    int len = MyStrlen(szName);
    cout << "length:" << len << endl;
    MyStrcpy(szText, szHello);
    cout << "mystrcpy:" << szText << endl;
    MyStrcat(szText, szName);
    cout << "mystrcat:" << szText << endl;

    int a = 8;
    int b = 9;
    cout << "a b:" << a << " " << b << endl;
    ConstSwap(a, b);
    cout << "constswap(a,b):" << a << " " << b << endl;
    MySwap(a, b);
    cout << "myswap(a,b):" << a << " " << b << endl;
    MyAdd(a);
    cout << "myadd(a):" << a << endl;
    int* pNum = (int*)arrNum;
    MyChange(pNum);
    cout << "mychange(&):" << *pNum << endl;

    double radius = 30.0f;
    cout << "areacircle:" << AreaCircle(radius) << endl;

    double length = 10.0f;
    double width = 5.0f;
    double height = 5.0f;
    cout << "arearectangle:" << AreaRectangle(length, width) << endl;
    cout << "volumecuboid:" << VolumeCuboid(length, width, height) << endl;

    return 0;
}
