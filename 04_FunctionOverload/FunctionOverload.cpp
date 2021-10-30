#include "FunctionOverload.h"

int Max(int a, int b)
{
	return a > b ? a : b;
}

double Max(double a, double b)
{
	return a > b ? a : b;
}

bool IsEvenNum(int a)
{
	if (a % 2 == 0)
	{
		return true;
	}
	return false;
}

bool IsEvenNum(double a)
{
	if (a - (int)a == 0 && (int)a % 2 == 0)
	{
		return true;
	}
	return false;
}

int GetSquare(int a)
{
	return a * a;
}

double  GetSquare(double a)
{
	return a * a;
}

int GetAbsolute(int a)
{
	if (a < 0)
	{
		return -a;
	}
	return a;
}

double GetAbsolute(double a)
{
	if (a < 0)
	{
		return -a;
	}
	return a;
}

double AreaTriangle(int bottom, int height)
{
	return (double)bottom * height / 2;
}

double AreaTriangle(double bottom, double height)
{
	return bottom * height / 2;
}
