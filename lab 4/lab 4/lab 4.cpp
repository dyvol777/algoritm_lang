// lab 4.cpp: ���������� ����� ����� ��� ����������� ����������.
//


#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include "stdafx.h"

using namespace std;

const int modul = 100;

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
	out << a.data;
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
	matrix(int s1, int s2, element** dv = 0)
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
		if ((stolbcu != s.stolbcu) || (stroki != s.stroki))
		throw "ne ravn razmer";
		matrix q(stroki, stolbcu);
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
		matrix q(stroki, (stolbcu+s.stolbcu));
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
	matrix povorot(void)
	{
		matrix q(stolbcu, stroki);
		for (int i = 0; i<stroki;i++)
		{
			for (int j = 0; j < stolbcu;j++)
			{
				q.a[j][stroki-1-i] = a[i][j];
			}
		}
		return q;
	}
	/*~matrix()
	{
		for (int i = 0;i < stolbcu; i++)
		{
			delete []a[i];
		}
		delete []a;
	}*/
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
	//in >> el;
	//stringstream ss;
	//ss << el;	
	for (int i = 0;i < a.stroki; i++)
	{
		for (int j = 0;j < a.stolbcu; j++)
		{
			in >> el;
			stringstream ss;
			ss << el;
			ss >> a.a[i][j];
		}
	}
	return in;
}

int main()
{
	srand(time(NULL));
	fstream m1("m1.txt");
	fstream m2("m2.txt"); 

	element** a;
	a = new element*[5];
	for (int i = 0;i < 5; i++)
	{
		a[i] = new element[5];
	}
	for (int i = 0;i < 5; i++)
	{
		for (int j = 0;j < 5; j++)
		{
				a[i][j] = rand();
		}
	}

	matrix b(5, 5, a);	
	cout << "prost" << endl << b;
	m1 << b;

	b = b + b;
	cout << "plus" << endl << b;

	b = b | b;
	cout << "prisoed" << endl << b;

	b = b.povorot();
	cout << "povorot" << endl << b;

	matrix c(5, 5);
	m2 >> c;
	cout << "from file" << endl << c;

	cout << "enter new matrix 2x2" << endl;
	matrix d(2, 2);
	cin >> d;
	cout << "new d" << endl << d;

	try
	{
		c = c + d;
		cout << b;
	}
	catch (char*& a)
	{
		cout << "iskluch " << a << endl;
	}

	system("pause");
    return 0;
}

