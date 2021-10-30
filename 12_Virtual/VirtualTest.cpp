/*
使用函数指针实现类的多态
*/
#include <iostream>
using namespace std;

class CPerson;
typedef void(CPerson::* PFN_PERSON_SAYHELLO)();
typedef void(CPerson::* PFN_PERSON_SAYBAY)();

union PERSON_FUNS
{
	PFN_PERSON_SAYHELLO m_pfnPersonSayHello;
	PFN_PERSON_SAYBAY m_pfnPersonSayBye;
};

class CPerson
{
public:
	CPerson()
	{
		m_pfnPersonFuncs = m_arrPersonFuncs;
	}
	~CPerson()
	{
	}
	void SayHello()
	{
		cout << "hello" << endl;
	}
	void SayBye()
	{
		cout << "bye" << endl;
	}
public:
	PERSON_FUNS* m_pfnPersonFuncs;
	static PERSON_FUNS m_arrPersonFuncs[2];
};
PERSON_FUNS CPerson::m_arrPersonFuncs[2] = { &CPerson::SayHello,&CPerson::SayBye };

class CStudent :public CPerson
{
public:
	CStudent()
	{
		m_pfnPersonFuncs = m_arrStudentFuncs;
	}
	~CStudent()
	{
	}
	void SayHello()
	{
		cout << "student hello" << endl;
	}
	void SayBye()
	{
		cout << "student bye" << endl;
	}

public:
	static PERSON_FUNS m_arrStudentFuncs[2];
};
PERSON_FUNS CStudent::m_arrStudentFuncs[2] = {
	(PFN_PERSON_SAYHELLO)&CStudent::SayHello,
	(PFN_PERSON_SAYBAY)&CStudent::SayBye
};

int main()
{
	CPerson* arrPerson[2] = { 0 };
	arrPerson[0] = new CStudent;
	arrPerson[1] = new CPerson;
	for (auto& pPerson : arrPerson)
	{
		(pPerson->*(pPerson->m_pfnPersonFuncs[0].m_pfnPersonSayHello))();
		(pPerson->*(pPerson->m_pfnPersonFuncs[0].m_pfnPersonSayBye))();
		(pPerson->*(pPerson->m_pfnPersonFuncs[1].m_pfnPersonSayHello))();
		(pPerson->*(pPerson->m_pfnPersonFuncs[1].m_pfnPersonSayBye))();
	}

	return 0;
}
