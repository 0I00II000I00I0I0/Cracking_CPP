#include "ConstString.h"

int MyStrlen(const char* string)
{
	int len = 0;
	while (*string++ != '\0')
	{
		len++;
	}
	return len;
}

void MyStrcpy(char* dest, const char* src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
}

void MyStrcat(char* dest, const char* src)
{
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
}

void ConstSwap(const int& nNumA, const int& nNumB)
{
	int temp = nNumA;
	*(int*)&nNumA = nNumB;
	*(int*)&nNumB = temp;
}

void MySwap(int& nNumA, int& nNumB)
{
	int temp = nNumA;
	nNumA = nNumB;
	nNumB = temp;
}

void MyAdd(int& nNum)
{
	nNum = nNum + 1;
}

void MyChange(int*& nNum)
{
	nNum = nNum + 1;
}

double AreaCircle(double& radius)
{
	return 3.14 * radius * radius;
}

double AreaRectangle(double& length, double& width)
{
	return length * width;
}

double VolumeCuboid(double& length, double& width, double& height)
{
	return length * width * height;
}
