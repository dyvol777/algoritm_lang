// optim1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;
class table
{
protected:
	int a;//stroki
	int b;//stolbcu
	float **t;//matrix
	string* n;//basis
	string* m;//fictiv

public:
	table(int q, int w)
	{
		a = q;
		b = w;
		t = new float*[a];
		for (int i = 0;i < a; i++)
		{
			t[i] = new float[b];
		}
		n = new string[a];
		m = new string[b];
	};

	table(table& cop) 
	{
		a = cop.a;
		b = cop.b;
		t = new float*[a];
		for (int i = 0;i < a; i++)
		{
			t[i] = new float[b];
		}
		n = new string[a];
		m = new string[b];
		for (int i = 0;i < a;i++)
		{
			for (int j = 0;j < b;j++)
			{
				t[i][j] = cop.t[i][j];
			}
		}
		for (int i = 0;i < a;i++)
		{
			n[i]=cop.n[i];
		}
		for (int i = 0;i < b;i++)
		{
			m[i]=cop.m[i];
		}
	}

	~table()
	{
		for (int i = 0;i < a; i++)
		{
			delete[]t[i];
		}
		delete[]t;
		delete[]n;
		delete[]m;
	};

	void vvod()
	{
		cout << "vvedite dly c" << endl;
		for (int i = 1;i < b;i++)
		{
			cin >> t[a - 1][i];
		}
		cout << "vvedite b" << endl;
		for (int i = 0;i < a-1;i++)
		{
			cin >> t[i][0];
		}
		cout << "vvedite a" << endl;
		for (int i = 0;i < a-1;i++)
		{
			for (int j = 1;j < b;j++)
			{
				cin >> t[i][j];
			}
		}
		t[a-1][0] = 0;
		cout << "basis" << endl;
		for (int i = 0;i < a-1;i++)
		{
			cin >> n[i];
		}
		n[a - 1] = "F";
		cout << "fiktiv" << endl;
		for (int i = 1;i < b;i++)
		{
			cin >> m[i];
		}
		m[0] = "S";
	}

	void print()
	{
		for (int i = 0;i < a;i++)
		{
			for (int j = 0; j < b;j++)
			{
				cout.width(15);
				cout << t[i][j];
			}
			cout.width(15);
			cout << n[i];
			cout << endl;
		}

		for (int j = 0; j < b;j++)
		{
			cout.width(15);
			cout << m[j];
		}
		cout << endl << endl;
		return;
	};

	void dzordan(int q, int w)
	{
		float** y;
		y = new float*[a];
		for (int i = 0;i < a; i++)
		{
			y[i] = new float[b];
		}

		for (int i = 0;i < a;i++)
		{
			for (int j = 0;j < b;j++)
			{
				y[i][j] = t[i][j];
			}
		};

		for (int i = 0;i < a;i++)
		{
			for (int j = 0;j < b;j++)
			{
				t[i][j] = y[i][j] - y[i][w] * y[q][j] / y[q][w];
			}
		};//vse

		for (int i = 0;i < a;i++)
		{
			t[i][w] = -y[i][w] / y[q][w];
		};//stolbec

		for (int i = 0;i < b;i++)
		{
			t[q][i] = y[q][i] / y[q][w];
		};//stroka

		t[q][w] = 1 / y[q][w];//elemnt

		string u;
		u = n[q];
		n[q] = m[w];
		m[w] = u;

		for (int i = 0;i < a; i++)
		{
			delete[]y[i];
		}
		delete[]y;

		return;
	}

	int opornoe()
	{
		int w = -1;
		int q = -1;
		int r = -1;
		float *z = new float[a];

		for (int i = 0;i < a-1;i++)
		{
			if (t[i][0] < 0)
			{
				w = i;
				break;
			}
		}//ishem poch nedopust

		if (w==-1) return 1;//k sled etapu

		for (int i = 1;i < b;i++)
		{
			if (t[w][i] < 0)
			{
				q = i;
				break;
			}
		}//ishem rasr stolb

		if (q == -1) return 2;//nevozm

		for (int i = 0;i < a-1;i++)
		{
			if (t[i][q] == 0)
				z[i] = -1;
			else
				z[i] = t[i][0] / t[i][q];
		}
		float e = 1000000;

		for (int i = 0;i < a-1;i++)
		{
			if ((z[i] < e) && (z[i]>0))
			{
				e = z[i];
				r = i;
			}
		}//ishem razr str
		if (r == -1) return 2;//nevozm
		delete[] z;
		dzordan(r, q);
		return 0;//povtor
	}
	
	int optimal()
	{
		int q = -1;
		int r = -1;
		float *z = new float[a];

		for (int i = 1;i < b;i++)
		{
			if (t[a-1][i] > 0)
			{
				q = i;
				break;
			}
		}//ishem rasr stolb

		if (q == -1) return 1;//optimal

		for (int i = 0;i < a - 1;i++)
		{
			if (t[i][q] == 0)
				z[i] = -1;
			else
				z[i] = t[i][0] / t[i][q];
		}
		float e = 1000000;

		for (int i = 0;i < a - 1;i++)
		{
			if ((z[i] < e) && (z[i]>0))
			{
				e = z[i];
				r = i;
			}
		}//ishem razr str
		if (r == -1) return 2;//nevozm
		delete[] z;
		dzordan(r, q);
		return 0;//povtor
	}

	void transform()
	{
		float** y;
		y = new float*[a];
		for (int i = 0;i < a; i++)
		{
			y[i] = new float[b];
		}

		for (int i = 0;i < a;i++)
		{
			for (int j = 0;j < b;j++)
			{
				y[i][j] = t[i][j];
			}
		}

		for (int i = 0;i < a; i++)
		{
			delete[]t[i];
		}
		delete[]t;
		swap(a, b);
		//swap(m, n);
		t = new float*[a];
		for (int i = 0;i < a; i++)
		{
			t[i] = new float[b];
		}

		for (int i = 0;i < a-1;i++)
		{
			t[i][0] = y[b - 1][i+1];
		}
		for (int i = 1;i < b;i++)
		{
			t[a-1][i] = y[i - 1][0];
		}
		for (int i = 0;i < a - 1;i++)
		{
			for (int j = 1;j < b;j++)
			{
				t[i][j]=y[j-1][i+1];
			}
		}
		t[a - 1][0] = 0;
		for (int i = 0;i < a;i++)
		{
			for (int j = 0;j < b;j++)
			{
				t[i][j] = -t[i][j];
			}
		}
		t[a - 1][0] = 0;
		for (int i = 0;i < b; i++)
		{
			delete[]y[i];
		}
		delete[]y;
	}
};

void deistviya(table& w)
{
	cout << "dano" << endl;
	w.print();

	cout << "poisk oporu " << endl;
	while (1)
	{
		int p;
		p = w.opornoe();
		if (p == 0) {};
		if (p == 1) { break; };
		if (p == 2) { cout << "error"; break; };
		w.print();
	};

	cout << "poisk optimalnogo " << endl;
	while (1)
	{
		int p;
		p = w.optimal();
		if (p == 0) {};
		if (p == 1) { break; };
		if (p == 2) { cout << "error"; break; };
		w.print();
	}

	system("pause");
}

int main()
{
	int k, l;
	cout << "vvedite stroki i stolbcu"<<endl;
	cin >> k >> l;

	table q(k, l);
	q.vvod();
	table e(q);

	e.transform();
	deistviya(q);
	deistviya(e);	
    return 0;
}
