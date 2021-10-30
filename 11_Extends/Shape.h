#pragma once
#include <math.h>
#include <iostream>
using namespace std;

class CPoint
{
public:
	CPoint(int nX = 0, int nY = 0);
	~CPoint();
	void ShowPoint();
	double Distance(CPoint* pPoint);
private:
	double Pow(int nVal1, int nVal2);
public:
	int m_nX = 0;
	int m_nY = 0;
};

class C3DPoint :public CPoint
{
public:
	C3DPoint(int nX = 0, int nY = 0, int nZ = 0);
	~C3DPoint();
	void ShowPoint();
private:
	int m_nZ = 0;
};

class CShape
{
public:
	CShape(CPoint pStartPoint = CPoint(0, 0), CPoint pEndPoint = CPoint(0, 0));
	~CShape();
	void SetStartPoint(CPoint pStartPoint);
	void SetEndPoint(CPoint pEndPoint);
protected:
	CPoint m_pStartPoint;
	CPoint m_pEndPoint;
};

class CLine :public CShape
{
public:
	CLine(CPoint pStartPoint = CPoint(0, 0), CPoint pEndPoint = CPoint(0, 0));
	~CLine();
	double GetLength();
private:
	double m_dbLength;
};

class CRectangle :public CShape
{
public:
	CRectangle(CPoint pStartPoint = CPoint(0, 0), CPoint pEndPoint = CPoint(0, 0));
	~CRectangle();
	double GetLengthLine();
	double GetWidthLine();
	double AreaOfRectangle();

private:
	double m_LengthLine;
	double m_WidthLine;
};

