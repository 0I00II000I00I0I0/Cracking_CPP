#include "Class.h"

CPoint::CPoint()
{
}

CPoint::~CPoint()
{
}

int CPoint::GetX()
{
	return m_nX;
}

int CPoint::GetY()
{
	return m_nY;
}

void CPoint::SetX(int X)
{
	m_nX = X;
}

void CPoint::SetY(int Y)
{
	m_nY = Y;
}

void CPoint::InitPoint(int nX, int nY)
{
	m_nX = nX;
	m_nY = nY;
}

double CPoint::Distance(CPoint* pPoint)
{
	return sqrt(Pow(m_nX, pPoint->m_nX) + Pow(m_nY, pPoint->m_nY));
}

double CPoint::Pow(int n1, int n2)
{
	return ((double)n1 - n2) * ((double)n1 - n2);
}

CRectangle::CRectangle()
{
}

CRectangle::~CRectangle()
{
}

double CRectangle::GetLength()
{
	return m_dbLength;
}

double CRectangle::GetWidth()
{
	return m_dbWidth;
}

void CRectangle::SetLength(double dbLength)
{
	m_dbLength = dbLength;
}

void CRectangle::SetWidth(double dbWidth)
{
	m_dbWidth = dbWidth;
}

double CRectangle::AreaOfRectangle()
{
	return m_dbLength * m_dbWidth;
}

CDate::CDate()
{
}

CDate::~CDate()
{
}

int CDate::GetYear()
{
	return m_nYear;
}

int CDate::GetMonth()
{
	return m_nMonth;
}

int CDate::GetDay()
{
	return m_nDay;
}

void CDate::SetYear(int nYear)
{
	m_nYear = nYear;
}

void CDate::SetMonth(int nMonth)
{
	m_nMonth = nMonth;
}

void CDate::SetDay(int nDay)
{
	m_nDay = nDay;
}

void CDate::SetDate(int nYear, int nMonth, int nDay)
{
	m_nYear = nYear;
	m_nMonth = nMonth;
	m_nDay = nDay;
}

bool CDate::IsLeapYear()
{
	if (m_nYear % 4 == 0 && m_nYear % 100 != 0 || m_nYear % 400 == 0)
	{
		return true;
	}
	return false;
}

const char* CDate::GetWeekday()
{
	int nYear = m_nYear;
	int nMonth = m_nMonth;
	if (nMonth == 1 || nMonth == 2)
	{
		nMonth += 12;
		nYear--;
	}
	int nWeekday = (m_nDay + 1 + 2 * nMonth + 3 * (nMonth + 1) / 5 + nYear + nYear / 4 - nYear / 100 + nYear / 400) % 7;
	switch (nWeekday)
	{
	case 0:
		return "Sunday";
		break;
	case 1:
		return "Monday";
		break;
	case 2:
		return "Tuesday";
		break;
	case 3:
		return "Wednesday";
		break;
	case 4:
		return "Thursday";
		break;
	case 5:
		return "Friday";
		break;
	case 6:
		return "Saturday";
		break;
	default:
		return nullptr;
		break;
	}
	return nullptr;
}

CTime::CTime()
{
}

CTime::~CTime()
{
}

int CTime::GetHour()
{
	return m_nHour;
}

int CTime::GetMinute()
{
	return m_nMinute;
}

int CTime::GetSecond()
{
	return m_nSecond;
}

void CTime::SetHour(int nHour)
{
	m_nHour = nHour;
}

void CTime::SetMinute(int nMinute)
{
	m_nMinute = nMinute;
}

void CTime::SetSecond(int nSecond)
{
	m_nSecond = nSecond;
}

void CTime::SetTime(int nHour, int nMinute, int nSecond)
{
	m_nHour = nHour;
	m_nMinute = nMinute;
	m_nSecond = nSecond;
}

int CTime::GetTotalSecond()
{
	return 3600 * m_nHour + 60 * m_nMinute + m_nSecond;
}

CDepositor::CDepositor()
{
}

CDepositor::~CDepositor()
{
}

int CDepositor::GetID()
{
	return m_nID;
}

char* CDepositor::GetName()
{
	return m_szName;
}

double CDepositor::GetDeposit()
{
	return m_dbDeposit;
}

void CDepositor::SetID(int nID)
{
	m_nID = nID;
}

void CDepositor::SetName(char* pName)
{
	strcpy_s(m_szName, pName);
}

void CDepositor::SetDeposit(double dbDeposit)
{
	m_dbDeposit = dbDeposit;
}

void CDepositor::SetDepositor(int nID, char* pName, double dbDeposit)
{
	m_nID = nID;
	strcpy_s(m_szName, pName);
	m_dbDeposit = dbDeposit;
}

double CDepositor::DrawMoney(double dbMoney)
{
	m_dbDeposit = m_dbDeposit - dbMoney;
	return m_dbDeposit;
}

double CDepositor::SaveMoney(double dbMoney)
{
	m_dbDeposit = m_dbDeposit + dbMoney;
	return m_dbDeposit;
}

CBookInfo::CBookInfo()
{
}

CBookInfo::~CBookInfo()
{
}

char* CBookInfo::GetBookName()
{
	return m_szBookName;
}

double CBookInfo::GetBookPrice()
{
	return m_dbBookPrice;
}

CDate CBookInfo::GetPublishDate()
{
	return m_pPublishDate;
}

void CBookInfo::SetBookInfo(char* szBookName, double dbBookPrice, CDate pPublishDate)
{
	strcpy_s(m_szBookName, szBookName);
	m_dbBookPrice = dbBookPrice;
	m_pPublishDate = pPublishDate;
}

int CBookInfo::GetPublishYear()
{
	struct tm t;
	time_t timeNow;
	time(&timeNow);
	localtime_s(&t, &timeNow);
	return t.tm_year - m_pPublishDate.GetYear() + 1900;
}
