#pragma once
#include <stack>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <iostream>
#include <deque>
#include <qstring.h>

using namespace std;
//explicit deque<char> tempOutput;
class Parcer
{
	friend class tree;
public:
	Parcer() = default;
	Parcer(string);
	int goPolish();
	QString count(vector<char>,vector<vector<char>>);
	//void buildTree();
	void logPolish();
	void setValues(map<char, char>);
	~Parcer() = default;
	bool isOperator(char);
	bool isVariable(char);

protected:
	
	bool higherPrecedence(char, char);
	string input;
	deque<char> output;
	stack<char> operations;
	map<char, int> precedence;
	map<char, char> values;
};

class tree

{
public:
	tree() {};
	bool isOperator(char);
	void set(Parcer&);
	friend Parcer;
	char data;
	int level = 0;
	pair<int, int> coord;
	tree* right = nullptr;
	tree* left = nullptr;
	tree* top = nullptr;
	tree* current = this;
	void buildTree(tree* current);
	static deque<char> tempOutput;
	static int biggestLevel;
	void setCoord(tree*);
};