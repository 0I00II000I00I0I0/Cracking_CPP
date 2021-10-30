#include <iostream>
using namespace std;
/*
构造函数初始化列表：
1、用来给成员赋初值：常成员、非常成员、类对象成员
2、初始化列表要早于构造函数
3、成员变量的初始化顺序与初始化列表中列出的变量的顺序无关，它只与成员变量在类中声明的顺序有关
4、构造函数：先成员、再自己，析构函数：先自己、再成员
*/
/*
const成员变量：
1、初始化 const 成员变量的唯一方法就是使用初始化列表
const成员函数：常成员函数
1、通常将 get 函数设置为常成员函数
2、常成员函数需要在声明和定义的时候在函数头部的结尾加上 const 关键字
3、常成员函数内部不能修改成员变量，不能调用非常成员函数
4、常成员函数会将this指针的类型改为const type* const this
5、常成员函数是语法层限制，可以突破语法的限制
*/
/*
静态成员变量：
1、声明和实现分开
2、有独立的内存，存放在全局数据区
3、属于类，所有的对象共享，生命周期和全局变量一样
4、静态成员变量必须初始化，而且只能在类体外进行
静态成员函数：
1、没有this指针
2、属于类，可以直接通过类名调用
3、静态成员函数只能访问静态成员
*/

class CStudent
{
public:
    CStudent(int nID, char* szName, double nScore);
    ~CStudent();
    int GetID() const;
    static int GetTotal();
    void ShowStudent();
private:
    const int m_nID = 0;
    char m_szName[128] = { 0 };
    double m_nScore = 0;
    static int m_nTotal;
};

int CStudent::m_nTotal = 0;

CStudent::CStudent(int nID = 0, char* szName = (char*)"unknow", double nScore = 0) :m_nID(nID), m_nScore(nScore)
{
    strcpy_s(m_szName, szName);
    m_nTotal++;
}

CStudent::~CStudent()
{
    m_nTotal--;
}

int CStudent::GetID() const
{
    return m_nID;
}

int CStudent::GetTotal()
{
    return m_nTotal;
}

void CStudent::ShowStudent()
{
    cout << "ID=" << m_nID << endl;
    cout << "Name=" << m_szName << endl;
    cout << "Score=" << m_nScore << endl;
    cout << "Total=:" << m_nTotal << endl;
}

int main()
{
    CStudent Student;
    Student.ShowStudent();
    const CStudent StudentA(1, (char*)"xiaobai", 90);
    // StudentA->ShowStudent(); 不行
    cout << "ID=" << StudentA.GetID() << endl;
    CStudent* pStudent = new CStudent(2, (char*)"xiaoxin", 90);
    pStudent->ShowStudent();

    cout << "GetTotal=" << StudentA.GetTotal() << endl;
    delete pStudent;
    cout << "GetTotal=" << StudentA.GetTotal() << endl;

    return 0;
}

