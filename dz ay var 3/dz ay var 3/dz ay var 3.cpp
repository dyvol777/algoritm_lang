// dz ay var 3.cpp: ���������� ����� ����� ��� ����������� ����������.
//
//��������� ������, �����������, ���������� � ��������������
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
		nakogo=q;
	}
	~rab()
	{

	}
private:
	string name;
	podr* nakogo;
	vector<podr*> nakogo2;//2 ������. �� ���� ������� � ������� �� � ����� ���������
	vector<string> history;
};

class podr
{
public:
	friend rab;
	podr(string s,podr* q)
	{
		name = s;
		pnak=q;
	}
	void addrab(string s)
	{
		rab* pnew = new rab(s, this);//smartpointer?
		pnew->history.push_back(this->name);
		prab.push_back(pnew);
	}
	void addrab(rab* s)
	{
		s->history.push_back(this->name);
		prab.push_back(s);
	}
	void dellrab(string s)
	{
		for (int i = 0; i < prab.size();i++)
		{
			if (prab[i]->name == s) prab.erase(prab.begin() + i);
		}
	}
	void addpodr(string s)
	{
		podr* pnew = new podr(s, this);
		ppodr.push_back(pnew);
	}
	void addpodr(podr* s)
	{
		ppodr.push_back(s);
	}
	void dellpodr(string s)
	{
		for (int i = 0; i < ppodr.size();i++)
		{
			if (ppodr[i]->name == s) ppodr.erase(ppodr.begin() + i);
		}
	}
	podr* searchrab(string name) 
	{
		for (int i = 0; i < prab.size(); i++)
		{
			if (prab[i]->name == name)
				return this;
		}

		for (podr* k : ppodr) 
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

		for (podr* k : ppodr) 
		{
			if (k->searchpodr(name) != 0) return k->searchpodr(name);
		}
		return 0;
	}
	void show()
	{
		cout <<'\t'<< this->name << endl;
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
	podr* gethos()
	{
		return pnak;
	}
	void printrab(string a)
	{
		for (rab* k : prab)
		{
			if (k->name == a)
			{
				cout << k->name << " rabotaet na " << this->name<<endl;
				cout << "rabotal na: ";
				for (int i = 0;i<k->history.size();i++)
					cout << k->history[i] << ' ';
				cout << endl;
			}
		}
	}
	rab* gettrab(string a)
	{
		for (rab* k : prab)
		{
			if (k->name == a)
				return k;
		}
	}
	//~podr();
private:
	vector<podr*> ppodr;//��� ���������
	podr* pnak;//�� ���� ��������
	vector<rab*> prab;//��� � ��� ���������
	vector<rab*> prab2;//��� �������� �� 2 ������
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
				if (komp.searchrab(value2) == 0)
				{
					cin >> value3;//��� �������
					if (komp.searchpodr(value3)!=0)
						komp.searchpodr(value3)->addrab(value2);//create
					else cout << "net podr"; 
				}
				else cout << "takoi sotr est";
			}//vot tak pisat!!
			if (value1 == "podr")
			{
				cin >> value2;//���
				if (komp.searchpodr(value2) == 0)
				{
					cin >> value3;//��� ��������� �������
					if(komp.searchpodr(value3) != 0)
						komp.searchpodr(value3)->addpodr(value2);//������� ������ �������������
					else cout << "net podr";
				}
				else cout << "takoe podr est";
			}
			if ((value1!="sotr")&&(value1!="podr")) cout << "not right command" << endl;//������ �� ������������� �����
		}
		if (data == "show")
		{
			m = 1;
			komp.show();
		}
		if (data == "dell")
		{
			m=1;
			cin >> value1;
			if (value1 == "sotr")
			{
				cin >> value2;//���
				if (komp.searchrab(value2) != 0)
				{
					komp.searchrab(value2)->dellrab(value2);//������� ������ �������������
				}
				else cout << "takogo sotr net";
			}
			if (value1 == "podr")
			{
				cin >> value2;//���
				if (komp.searchpodr(value2) != 0)
				{
					komp.searchpodr(value2)->gethos()->dellpodr(value2);//������� ������ �������������
				}		
				else cout << "takogo podr net";
			}
			if ((value1 != "sotr") && (value1 != "podr")) cout << "not right command" << endl;
		}
		if (data == "goto")//�������
		{
			m = 1;
			cin >> value1;
			if (value1 == "sotr")
			{
				cin >> value2;//���
				if (komp.searchrab(value2) != 0)
				{
					cin >> value3;//��� �������
					if (komp.searchpodr(value3) != 0)
					{
						rab* k;
						k = komp.searchrab(value2)->gettrab(value2);
						komp.searchrab(value2)->dellrab(value2);
						komp.searchpodr(value3)->addrab(k);
					}//������ �� ����������� ���� �� ����� ������?
					else cout << "net takogo podr";
				}
				else cout << "takogo sotr net";
			}
			if (value1 == "podr")
			{
				cin >> value2;//���
				if (komp.searchpodr(value2) != 0)
				{
					cin >> value3;//��� �������
					if (komp.searchpodr(value3) != 0)
					{
						podr* k;
						k = komp.searchpodr(value2);
						komp.searchpodr(value2)->gethos()->dellpodr(value2);
						komp.searchpodr(value3)->addpodr(k);
					}
					else cout << "net takogo podr";
				}
				else cout << "net takogo podr";
			}
			if ((value1 != "sotr") && (value1 != "podr")) cout << "not right command" << endl;
		}

		//if (data == "obed")
		//{
		//	m = 1;
		//	cin >> value1;
		//	cin >> value2;//������
		//	obed(komp.searchpodr(value1), komp.searchpodr(value2));//�������� ������� ����������� 2 ������� � 1 
		//�� ��� ������ ��� ��� �����(�������� ��������?)
		//}

		if (data == "search")
		{
			m = 1;
			cin >> value1;
			if (komp.searchrab(value1) != 0)
				komp.searchrab(value1)->printrab(value1);
			else cout << "takogo net";
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