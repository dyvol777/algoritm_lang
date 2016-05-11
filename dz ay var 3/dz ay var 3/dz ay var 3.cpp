// dz ay var 3.cpp: определ€ет точку входа дл€ консольного приложени€.
//
//несколько ставок
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
	friend ofstream& operator<<(ofstream& os, const podr& p);
	~rab()
	{

	}
private:
	string name;
	podr* nakogo;
	vector<podr*> nakogo2;//2 ставка. но если удал€ют с главной то и сэтой удал€етс€
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
	friend void obed(podr*a, podr* b);
	friend ofstream& operator<<(ofstream& os, const podr& p);
	void addrab(string s)
	{
		rab* pnew = new rab(s, this);//smartpointer?
		pnew->history.push_back(this->name);
		prab.push_back(pnew);
	}
	void addrab(rab* s)
	{
		s->nakogo = this;
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
		s->pnak = this;
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
	vector<podr*> ppodr;//кем управл€ют
	podr* pnak;//на кого работают
	vector<rab*> prab;//кто у них работатет
	vector<rab*> prab2;//кто работает на 2 ставке
	string name;
};

void obed(podr*a, podr* b)
{
	for (int i = 0;i < b->prab.size();i++)
		a->addrab(b->prab[i]);
	for (int i = 0;i < b->ppodr.size();i++)
		a->addpodr(b->ppodr[i]);
}

ofstream& operator<<(ofstream& os, const podr& p)
{
	for (int i = 0;i < p.prab.size();i++)
		os << "sotr " << p.prab[i]->name << ' ' << p.prab[i]->nakogo->name<<endl;
	for (int i = 0;i < p.ppodr.size();i++)
		os << "podr " << p.ppodr[i]->name << ' ' << p.ppodr[i]->pnak->name<<endl;
	for (int i = 0;i < p.ppodr.size();i++)
		os << *p.ppodr[i];
	return os;
}

int main()
{
	podr komp("company", 0);
	string data, value1,value2,value3;
	int m = 0;
	while (data != "exit")
	{
		cin >> data;
		if (data == "add")//просто добавление
		{
			m = 1;
			cin >> value1;//что?
			if (value1 == "sotr")
			{
				cin >> value2;//им€
				if (komp.searchrab(value2) == 0)
				{
					cin >> value3;//им€ подразд
					if (komp.searchpodr(value3)!=0)
						komp.searchpodr(value3)->addrab(value2);//create
					else cout << "net podr"; 
				}
				else cout << "takoi sotr est";
			}//vot tak pisat!!
			if (value1 == "podr")
			{
				cin >> value2;//им€
				if (komp.searchpodr(value2) == 0)
				{
					cin >> value3;//им€ головного подразд
					if(komp.searchpodr(value3) != 0)
						komp.searchpodr(value3)->addpodr(value2);//функци€ поиска подразделени€
					else cout << "net podr";
				}
				else cout << "takoe podr est";
			}
			if ((value1!="sotr")&&(value1!="podr")) cout << "not right command" << endl;//защита от неправильного ввода
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
				cin >> value2;//им€
				if (komp.searchrab(value2) != 0)
				{
					komp.searchrab(value2)->dellrab(value2);//функци€ поиска подразделени€
				}
				else cout << "takogo sotr net";
			}
			if (value1 == "podr")
			{
				cin >> value2;//им€
				if (komp.searchpodr(value2) != 0)
				{
					komp.searchpodr(value2)->gethos()->dellpodr(value2);//функци€ поиска подразделени€
				}		
				else cout << "takogo podr net";
			}
			if ((value1 != "sotr") && (value1 != "podr")) cout << "not right command" << endl;
		}
		if (data == "goto")//перевод
		{
			m = 1;
			cin >> value1;
			if (value1 == "sotr")
			{
				cin >> value2;//им€
				if (komp.searchrab(value2) != 0)
				{
					cin >> value3;//им€ подразд
					if (komp.searchpodr(value3) != 0)
					{
						rab* k;
						k = komp.searchrab(value2)->gettrab(value2);
						komp.searchrab(value2)->dellrab(value2);
						komp.searchpodr(value3)->addrab(k);
					}//защита от перемещени€ ниже по ветке дерева?
					else cout << "net takogo podr";
				}
				else cout << "takogo sotr net";
			}
			if (value1 == "podr")
			{
				cin >> value2;//им€
				if (komp.searchpodr(value2) != 0)
				{
					cin >> value3;//им€ подразд
					if (komp.searchpodr(value3) != 0)
					{
						podr* k;
						k = komp.searchpodr(value2);
						if (k->searchpodr(value3) == 0)
						{
							komp.searchpodr(value2)->gethos()->dellpodr(value2);
							komp.searchpodr(value3)->addpodr(k);
						}
						else cout << "nevozmoshno";
					}
					else cout << "net takogo podr";
				}
				else cout << "net takogo podr";
			}
			if ((value1 != "sotr") && (value1 != "podr")) cout << "not right command" << endl;
		}
		if (data == "obed")
		{
			m = 1;
			cin >> value1;
			if (komp.searchpodr(value1) != 0)
			{
				cin >> value2;
				if (komp.searchpodr(value2) != 0)
				{
					if (komp.searchpodr(value1)->searchpodr(value2) != 0)
					{
						obed(komp.searchpodr(value1), komp.searchpodr(value2));
						komp.searchpodr(value2)->gethos()->dellpodr(value2);
					}
					if (komp.searchpodr(value2)->searchpodr(value1) != 0)
					{
						obed(komp.searchpodr(value2), komp.searchpodr(value1));
						komp.searchpodr(value1)->gethos()->dellpodr(value1);
					}
					if ((komp.searchpodr(value1)->searchpodr(value2) == 0) && (komp.searchpodr(value2)->searchpodr(value1) == 0))
					{
						obed(komp.searchpodr(value2), komp.searchpodr(value1));
						komp.searchpodr(value1)->gethos()->dellpodr(value1);
					}
				}
				else cout << "ne takogo";
			}
			else cout << "ne takogo";
		}
		if (data == "search")
		{
			m = 1;
			cin >> value1;
			if (komp.searchrab(value1) != 0)
				komp.searchrab(value1)->printrab(value1);
			else cout << "takogo net";
		}
		if (data == "save")
		{
			m = 1;
			ofstream fout;
			fout.open("data.txt");
			fout << komp;

			fout.close();
		}
		if (data == "open")
		{
			m = 1;
			ifstream fin;
			fin.open("data.txt");
			podr q("company", 0);
			komp = q;
			while (!fin.eof())
			{
				fin >> value1;
				fin >> value2;
				fin >> value3;
				if (value1 == "sotr")
				{
					komp.searchpodr(value3)->addrab(value2);
				}
				if (value1 == "podr")
				{
					komp.searchpodr(value3)->addpodr(value2);
				}
			}//прикрутить на дубл в конце

			if (value1 == "sotr")
				komp.searchrab(value2)->dellrab(value2);//функци€ поиска подразделени€
			if (value1 == "podr")
				komp.searchpodr(value2)->gethos()->dellpodr(value2);//функци€ поиска подразделени€
			fin.close();
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