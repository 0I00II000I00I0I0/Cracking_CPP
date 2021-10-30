#include <iostream>
using namespace std;
/*
引用计数
*/

class CMyString
{
public:
	CMyString(const char* string = nullptr, int nLen = 0)
	{
		if (string == nullptr)
		{
			m_nLength = 0;
			m_szBuf = nullptr;
			m_pReferCount = 0;
		}
		else
		{
			AllocNewBuff(string, nLen);
		}
	}

	CMyString(const CMyString& string)
	{
		m_nLength = string.m_nLength;
		m_szBuf = string.m_szBuf;
		m_pReferCount = string.m_pReferCount;
		(*m_pReferCount)++;
	}

	~CMyString()
	{
		ReleaseBuff();
	}

	void SetChar(int offset, char ch)
	{
		if (offset > m_nLength)
		{
			return;
		}
		CMyString szBuf(m_szBuf, m_nLength);
		ReleaseBuff();
		AllocNewBuff(szBuf.m_szBuf, szBuf.m_nLength);
		m_szBuf[offset] = ch;
	}

	void SetString(const char* string, int nLen)
	{
		ReleaseBuff();
		AllocNewBuff(string, nLen);
	}

	const char* GetString()
	{
		return m_szBuf;
	}

	int GetReferCount()
	{
		return *m_pReferCount;
	}

private:
	void ReleaseBuff()
	{
		--(*m_pReferCount);
		if (m_szBuf != nullptr)
		{
			if ((*m_pReferCount) == 0)
			{
				m_nLength = 0;
				delete[] m_szBuf;
				delete m_pReferCount;
				m_szBuf = nullptr;
				m_pReferCount = nullptr;
			}
		}
	}
	void AllocNewBuff(const char* pData, int nLen)
	{
		m_nLength = nLen;
		m_szBuf = new char[m_nLength];
		m_pReferCount = new int;
		memcpy(m_szBuf, pData, m_nLength);
		*m_pReferCount = 1;
	}

private:
	int m_nLength;
	char* m_szBuf;
	int* m_pReferCount;
};

int main()
{
	CMyString stringA("test refercount", strlen("test refercount") + 1);
	cout << "stringA:" << stringA.GetString() << " refercount:" << stringA.GetReferCount() << endl;

	stringA.SetChar(5, 'R');
	cout << "stringA:" << stringA.GetString() << " refercount:" << stringA.GetReferCount() << endl;

	CMyString stringB(stringA);
	cout << "stringA:" << stringA.GetString() << " refercount:" << stringA.GetReferCount() << endl;
	cout << "stringB:" << stringB.GetString() << " refercount:" << stringB.GetReferCount() << endl;

	CMyString stringC(stringB);
	cout << "stringA:" << stringA.GetString() << " refercount:" << stringA.GetReferCount() << endl;
	cout << "stringB:" << stringB.GetString() << " refercount:" << stringB.GetReferCount() << endl;
	cout << "stringC:" << stringC.GetString() << " refercount:" << stringC.GetReferCount() << endl;

	stringC.SetString("setstring", strlen("setstring") + 1);
	cout << "stringA:" << stringA.GetString() << " refercount:" << stringA.GetReferCount() << endl;
	cout << "stringB:" << stringB.GetString() << " refercount:" << stringB.GetReferCount() << endl;
	cout << "stringC:" << stringC.GetString() << " refercount:" << stringC.GetReferCount() << endl;

	return 0;
}
