#include "Animal.h"
#include <iostream>
using namespace std;

CAnimal::CAnimal(int nAge, int dbWeight) :m_nAge(nAge), m_dbWeight(dbWeight)
{
}

CAnimal::~CAnimal()
{
}

void CAnimal::EatAndDrink()
{
    cout << "animal eat and drink" << endl;
}

void CAnimal::Sleep()
{
    cout << "animal sleep" << endl;
}

void CAnimal::ShowInfo()
{
    cout << "animal:age=" << m_nAge << ",weight=" << m_dbWeight << endl;
}

CDog::CDog(int nAge, int dbWeight, char* szBelong) :CAnimal(nAge, dbWeight)
{
    memset(m_szBelong, 0, 128);
    strcpy_s(m_szBelong, szBelong);
}

CDog::~CDog()
{
    memset(m_szBelong, 0, 128);
}

void CDog::SetBelong(char* szBelong)
{
    memset(m_szBelong, 0, 128);
    strcpy_s(m_szBelong, szBelong);
}

char* CDog::GetBelong()
{
    return m_szBelong;
}

void CDog::EatAndDrink()
{
    cout << "dog eat and drink" << endl;
}

void CDog::Sleep()
{
    cout << "dog sleep" << endl;
}

void CDog::Bark()
{
    cout << "dog wangwang" << endl;
}

void CDog::ShowInfo()
{
    cout << "dog:belong=" << m_szBelong << ",age=" << m_nAge << ",weight=" << m_dbWeight << endl;
}

