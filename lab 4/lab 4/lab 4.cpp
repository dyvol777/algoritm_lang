// lab 4.cpp: определяет точку входа для консольного приложения.
//

#pragma once
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include "stdafx.h"
#include <tchar.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

const int modul = 1000;

class element
{
protected:
	int data;
public:
	element(int a = 0)
	{
		data = a%modul;
	}
	friend element operator+(const element& s1, const element& s2);
	friend element operator*(const element& s1, const element& s2);
	
};

element operator+(const element& s1, const element& s2)
{
	int q = s1.data + s2.data;
	element a(q);
	return a;
}

element operator*(const element& s1, const element& s2)
{
	int q = s1.data * s2.data;
	element a(q);
	return a;
}

class matrix
{
protected:
	element** a;
	int stroki, stolbcu;
public:
	matrix(element** dv, int s1, int s2)
	{
		a = new element*[s1];
		for (int i = 0;i < s1; i++)
		{
			a[i] = new element[s2];
		}
		for (int i = 0;i < s1; i++)
		{
			for (int j = 0;j < s2; j++)
			{
				if (dv != 0)
				{
					a[i][j] = dv[i][j];
				}
				else a[i][j] = 0;
			}
		}
		stroki = s1;
		stolbcu = s2;
	}
	element poluch(int c, int b)
	{
		return a[c][b];
	}
	void vstav(int c, int b, element d)
	{
		a[c][b] = d;
		return;
	}
	matrix operator+(const matrix& s)
	{
		matrix q(0,stroki, stolbcu);
		for (int i = 0;i < stroki; i++)
		{
			for (int j = 0;j < stolbcu; j++)
			{
				q.a[i][j] = a[i][j] + s.a[i][j];
			}
		}
		return q;
	}
	matrix operator|(const matrix& s)
	{
		matrix q(0, stroki, (stolbcu+s.stolbcu));
		for (int i = 0;i < stroki; i++)
		{
			for (int j = 0;j < (stolbcu + s.stolbcu); j++)
			{
				if (j < stolbcu)
				{
					q.a[i][j] = a[i][j];
				}
				else q.a[i][j] = s.a[i][j];
			}
		}
		return q;
	}
	matrix povorot(const matrix& s)
	{
		matrix q(0, s.stolbcu, s.stroki);
		for (int i = 0; i<s.stroki;i++)
		{
			for (int j = 0; j < s.stolbcu;j++)
			{
				q.a[j][s.stolbcu - 1 - i] = s.a[i][j];
			}
		}
		return q;
	}
	~matrix()
	{

	}
};

//ostream& operator<<(ostream& ost, Rational const& rat)
//{
//	return ost << "[" << rat.num << '/' << rat.den << "]";
//}
//
//istream& operator>>(istream& ist, Rational& r)
//{
//	string rational;
//	ist >> rational;
//	auto d = find(rational.begin(), rational.end(), '/');
//	if (rational.front() != '[' || rational.back() != ']' || d == rational.end())
//		throw runtime_error("Bad input");
//	*d = ' ';
//	string tmp(rational.begin() + 1, --(rational.end()));
//	stringstream ss;
//	ss << tmp;
//	ss >> r.num >> r.den;
//	return ist;
//}

int main()
{
    return 0;
}

