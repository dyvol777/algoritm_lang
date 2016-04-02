// lab 4.cpp: определяет точку входа для консольного приложения.
//

#pragma once
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include "stdafx.h"
#include "stdio.h"
#include <tchar.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include <time.h>
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
	friend ostream& operator << (ostream& out, element const& a);
	friend istream& operator >> (istream& in, element& a);
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
ostream& operator << (ostream& out, element const& a)
{
	out << "zn " << a.data;
	return out;
}
istream& operator >> (istream& in, element& a)
{
	string el;
	in >> el;
	stringstream ss;
	ss << el;
	ss >> a.data;
	return in;
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
				else q.a[i][j] = s.a[i][j-stolbcu];
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
		for (int i = 0;i < stolbcu; i++)
		{
			delete []a[i];
		}
		delete []a;
	}
	friend ostream& operator << (ostream& out, matrix const& a);
	friend istream& operator >> (istream& in, matrix& a);
};

ostream& operator << (ostream& out, matrix const& a)
{
	for (int i = 0;i < a.stroki; i++)
	{
		for (int j = 0;j < a.stolbcu; j++)
		{
			out << setw(4) << a.a[i][j];
		}
		out << endl;
	}
	return out;
}
istream& operator >> (istream& in, matrix& a)
{
	string el;
	in >> el;
	stringstream ss;
	ss << el;	
	for (int i = 0;i < a.stroki; i++)
	{
		for (int j = 0;j < a.stolbcu; j++)
		{
			ss >> a.a[i][j];
		}
	}
	return in;
}

int main()
{
    return 0;
}

