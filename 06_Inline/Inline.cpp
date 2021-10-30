/*
内联函数：
1. inline会建议编译器进行内联展开
2. 内联函数是文件作用域，声明和实现直接放在头文件中
3. 内联函数像宏一样在调用点展开，同时保留函数的类型检查（debug版不会展开，方便调试)
4. 短函数效率低，体积小，时间换空间，宏效率高，体积大，空间换时间
*/
#include <iostream>
using namespace std;
#include "Inline.h"

inline int Max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	cout << "max(a,b):" << Max(8, 9) << endl;

	char a = 'a';
	char b = 'A';
	char c = '9';
	cout << "a b c:" << a << b << c << endl;
	//判断数字字母
	cout << "isint(a):" << IsInt(a) << endl;
	cout << "isint(c):" << IsInt(c) << endl;
	cout << "ischar(a):" << IsChar(a) << endl;
	cout << "ischar(c):" << IsChar(c) << endl;
	//大小写转换
	cout << "a b:" << a << b << endl;
	ToUpper(a);
	ToLower(b);
	cout << "a b:" << a << b << endl;

	return 0;
}
