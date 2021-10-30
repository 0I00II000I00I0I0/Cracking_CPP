#include <stdio.h>
#include <iostream>
using namespace std;

void Test()
{
	cout << "global test" << endl;
}
/*
1、命名空间，用来解决命名冲突问题
2、所有在全局作用域里可以做的事情，都可以在namespace中实现
3、项目名_模块名_函数名：太长，缩写可读性会损失
*/
namespace NSpaceA
{
	int g_nValA = 9;
	void Test()
	{
		cout << "namespaceA" << endl;
	}
}
//命名空间拆分
namespace NSpaceA
{
	typedef struct _DATA
	{
		int a;
		int b;
	}DATA, * PDATA;
}
//命名空间嵌套
namespace NSpaceB
{
	int g_nValB = 8;
	namespace NSpaceC
	{
		int g_nValC = 9;
	}
	typedef struct _DATAB
	{
		int a;
		int b;
	}DATAB, * PDATAB;
}

//把NSpaceA中的名字拉到当前作用域中
using namespace NSpaceA;
using NSpaceA::g_nValA;
//命名空间可以声明别名
namespace NSpace = NSpaceB;
using namespace NSpace;

int main()
{
	::Test();
	NSpaceA::Test();
	cout << "namespaceA:" << g_nValA << endl;
	cout << "namespaceB:" << g_nValB << endl;
	cout << "namespaceC:" << NSpaceB::NSpaceC::g_nValC << endl;

	DATA tagData = { 8,9 };
	NSpaceB::DATAB tagDataB = { 8,9 };
	cout << "namespaceA:" << tagData.a << endl;
	cout << "namespaceB:" << tagDataB.a << endl;

	return 0;
}
