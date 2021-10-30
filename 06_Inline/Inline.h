#pragma once
/*
编写程序，使用内联函数实现以下功能：
1. 判断一个字符是否是数字
2. 判断一个字符是否是字母
3. 将一个字符转换为大写
4. 将一个字符转换为小写
*/

inline bool IsInt(char ch)
{
	if (ch > 47 && ch < 58)
	{
		return true;
	}
	return false;
}

inline bool IsChar(char ch)
{
	if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123))
	{
		return true;
	}
	return false;
}

inline void ToUpper(char& ch)
{
	if (ch > 96 && ch < 123)
	{
		ch = ch - 32;
	}
}

inline void ToLower(char& ch)
{
	if (ch > 64 && ch < 91)
	{
		ch = ch + 32;
	}
}


