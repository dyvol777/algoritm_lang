// dz ay var 3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
using namespace std;

class podr;
class rab
{
public:
	friend podr;
	rab(string s,podr* q)
	{
		name = s;
		nakogo.push_back(q);
	}
	void addnach(podr* q)//��������� �� ���� ��������
	{
		nakogo.push_back(q);
	}
	void uvol(podr* q)
	{
		int z;
		for (int i = 0;i < nakogo.size();i++)
		{
			if (nakogo[i] == q) z = i; else  z = -1;
		}
		if (z != -1)
		{
			nakogo.erase(nakogo.begin() + z);//���������? ��������� �� ������� ��� ��������
		}
	}
	~rab();//����� �������?
private:
	string name;
	vector<podr*> nakogo;//���������?
};

class podr
{
public:
	friend rab;
	podr(string s,podr* q)
	{
		name = s;
		pnak.push_back(q);
	}
	void addrab(string s)
	{
		rab* pnew = new rab(s, this);//smartpointer?
		prab.push_back(pnew);
	}
	void addpodr(string s)
	{
		podr* pnew = new podr(s, this);
		ppodr.push_back(pnew);
	}
	rab* searchrab(string name) 
	{
		for (int i = 0; i < prab.size(); i++)
		{
			if (prab[i]->name == name)
				return prab[i];
		}

		for (podr* k : ppodr) //��� ����� �����?
		{
			if(k->searchrab(name)!=0) return k->searchrab(name);
		}
		return 0;
	}
	podr* searchpodr(string name)
	{
		if (name == "company") return this;
		for (int i = 0; i < ppodr.size(); i++)
		{
			if (ppodr[i]->name == name)
				return ppodr[i];
		}

		for (podr* k : ppodr) //��� ����� �����?
		{
			if (k->searchpodr(name) != 0) return k->searchpodr(name);
		}
		return 0;
	}
	void show()
	{
		cout << this->name << endl;
		cout << "rab: ";
		for (int i = 0; i < prab.size(); i++)
			cout << prab[i]->name << ' ';
		cout << endl << "podr: ";
		for (int i = 0; i < ppodr.size(); i++)
			cout << ppodr[i]->name << ' ';
		cout << endl;
		for (podr* k : ppodr)
		{
			k->show();
		}

	}
	//~podr();
private:
	vector<podr*> ppodr;//��� ���������
	vector<podr*> pnak;//�� ���� ��������
	vector<rab*> prab;//��� � ��� ���������
	string name;
};


int main()
{
	podr komp("company", 0);
	string data, value1,value2,value3;
	int m = 0;
	while (data != "exit")
	{
		cin >> data;
		if (data == "add")//������ ����������
		{
			m = 1;
			cin >> value1;//���?
			if (value1 == "sotr")
			{
				cin >> value2;//���
				cin >> value3;//��� �������
				komp.searchpodr(value3)->addrab(value2);//������� ������ �������������
				//�� ��� ������������� ������� ���������
			}
			if (value1 == "podr")
			{
				cin >> value2;//���
				cin >> value3;//��� ��������� �������
				komp.searchpodr(value3)->addpodr(value2);//������� ������ �������������
				//komp.addpodr(value2);										 //�� ��� ������������� ������� 
			}
			//������ �� ������������� �����
		}
		if (data == "show")
		{
			m = 1;
			komp.show();
		}
		if (data == "exit")
		{
			m = 1;
		}
		if (m == 0) cout << "not right command" << endl;
		m = 0;
	}
	return 0;
}


