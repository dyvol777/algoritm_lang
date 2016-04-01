// lab 3-4.cpp: определяет точку входа для консольного приложения.
//

#pragma once
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include "stdafx.h"
#include <tchar.h>
#include <string>
#include <stdlib.h>
#include <iostream>


using namespace std;

class mosh
{
public:
	virtual void moshn(void) = 0;
};

class avt : public mosh// Базовый класс 
{
protected:
	string nazv;
	double sk;
public:
	avt() { nazv = "default"; sk = 0; cout << "sozdan avtom" << endl;}
	void moshn(void)
	{
		cout << "abstract";
	}
	avt(string s, double y) 
	{
		nazv = s; sk = y; cout << "sozdan avtom" << endl;
	}
	virtual void print() // Метод для печати полей (виртуальный)
	{
		cout << endl << "virtual nazvanie =" << nazv << " skorost=" << sk; 
	}

	bool operator==(avt &object)
	{
		if (sk == object.sk) return(true); else return (false);
	}

	virtual ~avt() { cout << "da"; }
};


class gravt : public avt // Производный класс 
{
private:
	int z; 
public:
	gravt(string s, double y, int z) : // Конструктор
		avt(s, y) // Явный вызов конструктора базового класса
	{
		this->z = z;
		cout << "sozdan avtobus" << endl;
	}
	void print() // Переопределенный метод print
	{
		avt::print(); // Вызов в переопределенном методе метода 
					  // базового класса
		cout << " passagiri=" << z << endl; 
	}
	~gravt() { cout << "dg"; }

};

class functor;

class vector //контейнерный класс
{
protected:
	avt* v; //начало
	int n;
	avt* sh;//конец
public:
	friend class functor;
	vector() { v = 0; cout << "sozdan vector" << endl; };
	vector(int i) { v = new avt[i]; n = i; sh = v; cout << "sozdan vector" << endl;
	}

	avt operator[](int i)
	{
		return(v[i]);
	}

	void operator+(avt& sp)
	{
		cout << " + ";
		if (sh == v+n) cout << endl << "error!" << endl; else
		{
			*sh = sp;
			sh++;
		}
	}

	void operator-(avt& sp)
		/*{
		cout << "-";
		avt* sh1 = v;
		if (*sh1 == sp)
		{
		while (sh1 < sh-1)
		{
		*sh1 = *(sh1 + 1);
		}
		sh--;
		}
		else sh1++;
		}*/
	{
		cout << " - ";
		for (int i = 0;i < sh-v;i++)
			if (v[i] == sp) {
								v[i] = v[i + 1]; sh--; for (int j = i;j < sh - v;j++, v[j] = v[j + 1]);
							}
	}

	void operator&(const vector& sp)
	{
		cout << endl << "and";
		for (int i = 0;i < sh-v;i++)
			for (int j = 0; j < sp.sh - sp.v; j++)
			{
				if (v[i] == sp.v[j]) sp.v[j].print();
			}
	}

	void operator|(const vector& sp)
	{
		cout << endl << " or ";
		for (int i = 0;i < sh - v;i++)
		{
			int l = 0;
			for (int j = 0;j < sp.sh - sp.v;j++)
			{
				if (v[i] == sp.v[j]) l = 1;
			}
			if (l == 0) v[i].print();
		}

		for (int j = 0;j < sp.n;j++)
			sp.v[j].print();

	}

virtual	~vector()
	{
		delete[]v;
	}
};

class functor
{
public:
	const void operator()(avt& avt)
	{
		avt.print();
	}
};

void foreach(functor& a, vector& vec, int n)
{
	for (int i = 0; i < n;i++)
		a(vec[i]);
}

int main(int argc, char* argv[])
{
	string s; double v; int ves;
	cout << "vvedite nazvane skorost " << endl;
	cin >> s >> v;
	avt p1(s, v); // Создается объект с вызовом конструктора
	cout << "vvedite nazvane skorost passagiri " << endl;
	cin >> s >> v >> ves;
	gravt p2(s, v, ves); // Создается объект с вызовом конструктора

	avt *pp; // Указатель типа базового класса
	pp = &p1; // Настраиваем на объект базового класса
	pp->print(); // Вызов метода через указатель
	pp = &p2; // Настриваем указатель на объект производного класса 
	pp->print(); // вызывается грузовик из за виртуал

	mosh* m;
	m = new avt("asdasd", 2);
	m->moshn();
	//delete m;

	cout << endl << "vvedite nazvane skorost " << endl;
	cin >> s >> v;
	avt p3(s, v); // Создается объект с вызовом конструктора

	if (p1 == p3) cout << "ravn"; else cout << "neravn";


	//реализация контейнерого класса
	vector vect(5);
	vect + p1;
	vect + p3;
	vect + p1;
	vector vect1(1);
	vect1 + p3;
	vect & vect1;
	vect | vect1;
	vect - p3;
	cout << endl;


	cout << endl << "!!!" << endl;
	
	vect[0].print();
	vect[1].print();
	vect[2].print();
	vect1 + p1;
	system("pause");
	//реализация функтора
	functor a;
	foreach(a,vect,3);	
	system("pause");
	return 0;
}


