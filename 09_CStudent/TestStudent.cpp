#include <iostream>
using namespace  std;

class CStudent
{
public:
    //默认构造函数
    //CStudent();
    //使用默认参数的默认构造函数
    CStudent(char* szName = (char*)"xiaoxin", int nScore = 9);
    //使用初始化列表的重载构造函数
    CStudent(int nID, char* szName, double nScore);
    //拷贝构造函数
    CStudent(const CStudent& student);
    //析构函数
    ~CStudent();
    void ShowInfo();
public:
    int m_nID = 0;
    char m_szName[128] = { 0 };
    double m_nScore = 0;
};

CStudent::CStudent(char* szName, int nScore)
{
    m_nID = 1;
    strcpy_s(m_szName, szName);
    m_nScore = nScore;
}
CStudent::CStudent(int nID, char* szName, double nScore) :m_nID(nID), m_nScore(nScore)
{
    strcpy_s(m_szName, szName);
}
CStudent::CStudent(const CStudent& student)
{
    m_nID = student.m_nID;
    strcpy_s(m_szName, student.m_szName);
    m_nScore = student.m_nScore;
}
CStudent::~CStudent()
{
    cout << "~CStudent" << endl;
}
void CStudent::ShowInfo()
{
    cout << "ID=" << m_nID << endl;
    cout << "Name=" << m_szName << endl;
    cout << "Score=" << m_nScore << endl;
}

int main()
{
    CStudent StudentA;
    StudentA.ShowInfo();
    CStudent StudentB(2, (char*)"xiaobai", 8);
    StudentB.ShowInfo();
    CStudent StudentC(StudentB);
    StudentC.ShowInfo();

    return 0;
}
