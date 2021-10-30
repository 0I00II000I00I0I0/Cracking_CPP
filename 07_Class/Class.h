#pragma once
/*
1. 定义一个点类，其属性包括点的坐标，提供计算两点之间距离的方法
2. 定义一个矩形类，其属性包括点的长度和宽度，提供计算矩形面积的方法
3. 定义一个日期类，其属性包括年、月、日，提供求闰年、星期的方法
4. 定义一个时间类，其属性包括时、分、秒，提供求总秒数的方法
5. 定义一个储户类, 其属性包括储户姓名、账号、存款，提供存入指定的存款、取出指定的存款的方法
7. 定义一个书类, 其属性包括书名、价格、出版日期，提供出版年限的方法
*/
#include <math.h>
#include <string.h>
#include <time.h>

class CPoint
{
public:
	CPoint();
	~CPoint();
	int GetX();
	int GetY();
	void SetX(int X);
	void SetY(int Y);
	void InitPoint(int nX = 0, int nY = 0);
	double Distance(CPoint* pPoint);
private:
	double Pow(int n1, int n2);
private:
	int m_nX = 0;
	int m_nY = 0;
};

class CRectangle
{
public:
	CRectangle();
	~CRectangle();
	double GetLength();
	double GetWidth();
	void SetLength(double dbLength);
	void SetWidth(double dbWidth);
	double AreaOfRectangle();
private:
	double m_dbLength = 0;
	double m_dbWidth = 0;
};

class CDate
{
public:
	CDate();
	~CDate();
	int GetYear();
	int GetMonth();
	int GetDay();
	void SetYear(int nYear);
	void SetMonth(int nMonth);
	void SetDay(int nDay);
	void SetDate(int nYear, int nMonth, int nDay);
	bool IsLeapYear();
	const char* GetWeekday();
private:
	int m_nYear = 0;
	int m_nMonth = 0;
	int m_nDay = 0;
};

class CTime
{
public:
	CTime();
	~CTime();
	int GetHour();
	int GetMinute();
	int GetSecond();
	void SetHour(int nHour);
	void SetMinute(int nMinute);
	void SetSecond(int nSecond);
	void SetTime(int nHour, int nMinute, int nSecond);
	int GetTotalSecond();
private:
	int m_nHour = 0;
	int m_nMinute = 0;
	int m_nSecond = 0;
};

class CDepositor
{
public:
	CDepositor();
	~CDepositor();
	int GetID();
	char* GetName();
	double GetDeposit();
	void SetID(int nID);
	void SetName(char* pName);
	void SetDeposit(double dbDeposit);
	void SetDepositor(int nID, char* pName, double dbDeposit);
	double DrawMoney(double dbMoney);
	double SaveMoney(double dbMoney);
private:
	int m_nID = 0;
	char m_szName[128] = { 0 };
	double m_dbDeposit = 0;
};

class CBookInfo
{
public:
	CBookInfo();
	~CBookInfo();
	char* GetBookName();
	double GetBookPrice();
	CDate GetPublishDate();
	void SetBookInfo(char* szBookName, double dbBookPrice, CDate pPublishDate);
	int GetPublishYear();
private:
	char m_szBookName[128] = { 0 };
	double m_dbBookPrice = 0;
	CDate m_pPublishDate;
};

