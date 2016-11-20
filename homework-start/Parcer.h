#pragma once
#include "stdafx.h"
#include <stack>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <iostream>
#include <deque>

using namespace std;
//explicit deque<char> tempOutput;
class Parcer
{
	friend class tree;
public:
	Parcer() = default;
	Parcer(string);
	int goPolish();
	int count();
	//void buildTree();
	void logPolish();
	void setValues(map<char, char>);
	~Parcer() = default;

protected:
	bool isOperator(char);
	bool isVariable(char);
	bool higherPrecedence(char, char);
	string input;
	deque<char> output;
	stack<char> operations;
	map<char, int> precedence;
	map<char, char> values;
};

struct tree 
	
{
	tree() {};
	bool isOperator(char);
	void set(Parcer&) ;
	friend Parcer;
	char data;
	int level = 0;
	pair<int, int> coord;
	tree* right=nullptr;
	tree* left=nullptr;
	tree* top=nullptr;
	tree* current=this;
	void buildTree(tree* current);
	static deque<char> tempOutput;
	static int biggestLevel;
	void setCoord(tree*);
};