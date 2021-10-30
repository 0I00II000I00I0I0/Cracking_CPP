/*
1. 类的不同对象，数据成员是独享的，成员函数是共享的
2. 类的对象调用成员函数时，默认传入this指针，指向调用函数的对象的首地址
3. this指针通过ecx寄存器传入，这种调用约定叫做thiscall调用约定
4. this指针的类型是class* const this
5. 排除多态的情况下，类和结构体的成员变量在内存中的布局规划一致
*/
/*
构造函数和析构函数：
1. 构造函数（初始化），函数名和类名相同，没有返回值，可以有参数，可以带默认参数，可以重载
2. 析构函数（反初始化），函数名和类名相同，前面加~，没有返回值，没有参数，不能重载
3. 构造函数在对象的生命周期开始被调用
4. 析构函数在对象的生命周期结束被调用
*/

#include <iostream>
using namespace std;

typedef struct _STUDENT
{
    int nID;
    char m_szName[128];
    double nScore;
}STUDENT, * PSTUDENT;

void ShowInfo(PSTUDENT tagStudent)
{
    cout << "ID=" << tagStudent->nID << endl;
    cout << "Name=" << tagStudent->m_szName << endl;
    cout << "Score=" << tagStudent->nScore << endl;
}

class CStudent
{
public:
    CStudent()
    {
        cout << "CStudent" << endl;
    }
    ~CStudent()
    {
        cout << "~CStudent" << endl;
    }
    void ShowInfo()
    {
        cout << "ID=" << m_nID << endl;
        cout << "Name=" << m_szName << endl;
        cout << "Score=" << m_nScore << endl;
    }
public:
    int m_nID = 0;
    char m_szName[128] = { 0 };
    double m_nScore = 0;
};


int main()
{
    STUDENT tagStudent = { 123,"xiaoxin",99 };
    ShowInfo(&tagStudent);
    cout << "sizeof struct:" << sizeof(tagStudent) << endl;

    CStudent Student;
    Student.m_nID = 1;
    Student.m_nScore = 9;
    strcpy_s(Student.m_szName, "xiaoming");
    Student.ShowInfo();
    cout << "sizeof class:" << sizeof(Student) << endl;

    CStudent* pStudent = new CStudent;
    CStudent* pStudentArray = new CStudent[2];

    pStudent->m_nID = 2;
    pStudent->m_nScore = 8;
    strcpy_s(pStudent->m_szName, "xiaobai");
    pStudent->ShowInfo();

    /*
    1. new：申请堆内存，然后调用构造函数
    2. delete：调用析构函数，然后释放堆内存
    3. new和delete配对使用，new[ ]和delete[ ]配对使用
    */
    delete pStudent;
    delete[] pStudentArray;

    return 0;
}

