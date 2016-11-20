// binari_math.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include "Parcer.h"

deque<char> tree::tempOutput;
int tree::biggestLevel = 0;
map<char, char> placeValues()
{
	map<char, char> val;
	char c;
	char v;
	int n;
	cout << "Enter amount of variables" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter name of variable A-Z" << endl;
		cin >> c;
		cout << "Enter value for the variable 0-1" << endl;
		cin >> v;
		val[c] = v;
	}
	return val;
}
int main()
{

	string input("A|B&C&(D|G)+C+A");
	Parcer data(input);
	data.goPolish();
	data.logPolish();

	tree head;
	head.set(data);
	head.data = head.tempOutput.back();
	head.tempOutput.pop_back();
	head.buildTree(head.current);
	head.coord.first = 500;
	head.coord.second = 0;
	head.setCoord(head.current);
	cout << head.left->right->level;
	cout << head.right->coord.first << " " << head.right->coord.second;
	
	//current->data = tempOutput.back();
	//tempOutput.pop_back();
	



	//data.setValues(placeValues());
	//data.count();
	system("pause");
	return 0;
}