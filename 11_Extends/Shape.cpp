#include "Shape.h"

CPoint::CPoint(int nX, int nY)
{
	m_nX = nX;
	m_nY = nY;
}

CPoint::~CPoint()
{
}

void CPoint::ShowPoint()
{
	cout << "point:(" << m_nX << "," << m_nY << ")" << endl;
}

double CPoint::Distance(CPoint* pPoint)
{
	return sqrt(Pow(m_nX, pPoint->m_nX) + Pow(m_nY, pPoint->m_nY));
}

double CPoint::Pow(int n1, int n2)
{
	return ((double)n1 - n2) * ((double)n1 - n2);
}

C3DPoint::C3DPoint(int nX, int nY, int nZ) :CPoint(nX, nY)
{
	m_nZ = nZ;
}

C3DPoint::~C3DPoint()
{
}

void C3DPoint::ShowPoint()
{
	cout << "3Dpoint:(" << m_nX << "," << m_nY << "," << m_nZ << ")" << endl;
}

CShape::CShape(CPoint pStartPoint, CPoint pEndPoint)
{
	m_pStartPoint = pStartPoint;
	m_pEndPoint = pEndPoint;
}

CShape::~CShape()
{
}

void CShape::SetStartPoint(CPoint pStartPoint)
{
	m_pStartPoint = pStartPoint;
}

void CShape::SetEndPoint(CPoint pEndPoint)
{
	m_pEndPoint = pEndPoint;
}

CLine::CLine(CPoint pStartPoint, CPoint pEndPoint) :CShape(pStartPoint, pEndPoint)
{
	m_dbLength = pStartPoint.Distance(&pEndPoint);
}

CLine::~CLine()
{
}

double CLine::GetLength()
{
	return m_dbLength;
}

CRectangle::CRectangle(CPoint pStartPoint, CPoint pEndPoint) :CShape(pStartPoint, pEndPoint)
{
	m_LengthLine = abs(m_pStartPoint.m_nX - m_pEndPoint.m_nX);
	m_WidthLine = abs(m_pStartPoint.m_nY - m_pEndPoint.m_nY);
}

CRectangle::~CRectangle()
{
}

double CRectangle::GetLengthLine()
{
	return m_LengthLine;
}

double CRectangle::GetWidthLine()
{
	return m_WidthLine;
}

double CRectangle::AreaOfRectangle()
{
	return m_LengthLine * m_WidthLine;
}

