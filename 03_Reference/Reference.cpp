#include <iostream>
using namespace std;

int main()
{
    //引用&，给变量取个别名，引用不可以修改引用的变量对象
    int nVal = 9;
    int nTemp = 9;
    int& nRefVal = nVal;
    nRefVal = 8;//允许
    cout << "val:" << nVal << endl;
    cout << "refval:" << nRefVal << endl;
    nRefVal = nTemp;//不允许
    cout << "val:" << nVal << endl;
    cout << "refval:" << nRefVal << endl;

    //指针和引用的区别，引用必须初始化
    char ch = 'a';
    char* pa = &ch;
    char*& pb = pa;
    //编译器在处理引用的时候，内部仍然是使用指针操作
    cout << "ch:" << ch << endl;

    return 0;
}

