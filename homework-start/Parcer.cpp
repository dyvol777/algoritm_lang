
#include "stdafx.h"
#include "Parcer.h"
string variables("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
string operators("&|+-");//êîíúþíêöèÿ, äèçúþíêöèÿ, áóëåâ ïëþñ, ðàâåíñòâî
deque<char> tempOutput;
Parcer::Parcer(string data)
{
	input = "(" + data + ")";
	precedence['&'] = 2;
	precedence['|'] = 2;
	precedence['+'] = 2;
	precedence['-'] = 2;//equal
}
bool Parcer::isOperator(char c)
{
	for (auto v : operators)
	{
		if (c == v)
			return true;
	}
	return false;
}
bool Parcer::isVariable(char c)
{
	for (auto v : variables)
	{
		if (c == v)
			return true;
	}
	return false;
}
bool Parcer::higherPrecedence(char previous, char last)
{
	if (precedence[previous] < precedence[last])
		return true;
	return false;
}
int Parcer::goPolish()
{
	for (auto token : input)
	{
		if (isVariable(token))
			output.push_back(token);
		if (isOperator(token))
		{
			if (isOperator(operations.top()) && !higherPrecedence(operations.top(), token))
			{
				output.push_back(operations.top());
				operations.pop();
			}
			operations.push(token);
		}
		if (token == '(')
		{
			operations.push(token);
		}
		if (token == ')')
		{
			while (operations.top() != '(')
			{
				output.push_back(operations.top());
				operations.pop();
			}
			operations.pop();
		}
	}
	return output.size();
}
void Parcer::logPolish()
{

	deque<char> temp(output);
	while (temp.size() != 0)
	{
		cout << temp.front() << endl;
		temp.pop_front();
	}
}
void Parcer::setValues(map<char, char> init)
{
	values = init;
	values['f'] = '2';
}
int Parcer::count()
{
	vector<char> temp;
	int cur;
	char rez;
	for (int i = 0; i < output.size(); i++)//set formula with values
	{
		if (isVariable(output[i]))
			temp.push_back(values[output[i]]);
		if (isOperator(output[i]))
			temp.push_back(output[i]);
	}

	while (temp.size() != 1)
	{
		for (int j = 0; j < temp.size(); j++)
		{
			if (isOperator(temp[j]))
			{
				cur = j;
				break;
			}
		}
		switch (temp[cur])
		{
			{
		case '&':
			if ((temp[cur - 1] == '1') && (temp[cur - 2] == '1'))
				rez = '1';
			else
				rez = '0';
			temp[cur] = rez;
			temp.erase(temp.begin() + (cur - 1));
			temp.erase(temp.begin() + (cur - 2));
			break;
			}
			{
		case '|':
			if ((temp[cur - 1] == '1') || (temp[cur - 2] == '1'))
				rez = '1';
			else
				rez = '0';
			temp[cur] = rez;
			temp.erase(temp.begin() + (cur - 1));
			temp.erase(temp.begin() + (cur - 2));
			break;
			}
			{
		case '+':
			if ((temp[cur - 1] == '1') && (temp[cur - 2] == '1'))
				rez = '0';
			if ((temp[cur - 1] == '0') && (temp[cur - 2] == '0'))
				rez = '0';
			if ((temp[cur - 1] == '1') && (temp[cur - 2] == '0'))
				rez = '1';
			if ((temp[cur - 1] == '0') && (temp[cur - 2] == '1'))
				rez = '1';
			temp[cur] = rez;
			temp.erase(temp.begin() + (cur - 1));
			temp.erase(temp.begin() + (cur - 2));
			break;
			}
			{
		case '-':
			if (temp[cur - 1] == temp[cur - 2])
				rez = '1';
			else
				rez = '0';
			temp[cur] = rez;
			temp.erase(temp.begin() + (cur - 1));
			temp.erase(temp.begin() + (cur - 2));
			break;
			}

			{
		default:
			break;
			}
		}
	}
	values['r'] = temp[0];
	cout << "The result is " << values['r'] << endl;
	if (temp[0] == '1')
		return 1;
	else
		return 0;
}

void tree::set(Parcer &a)
{
	for (auto b : a.output)
	{
		tempOutput.push_back(b);
	}
}
bool tree::isOperator(char c)
{
	for (auto v : operators)
	{
		if (c == v)
			return true;
	}
	return false;
}
void tree::buildTree(tree* current)
{
	
	current->right = new tree;
	current->right->data= tempOutput.back();
	tempOutput.pop_back();
	current->right->level = current->level+1;
	if (current->right->level > biggestLevel)
		biggestLevel = current->right->level;
	current->right->top = current;
	if (isOperator(current->right->data))
	{
		buildTree(current->right);
		current->left = new tree;
		current->left->data = tempOutput.back();
		tempOutput.pop_back();
		current->left->level = current->level+1;
		if (current->left->level > biggestLevel)
			biggestLevel = current->left->level;
		current->left->top = current;
		if (isOperator(current->left->data))
		{
			buildTree(current->left);
		}
		else
			return;
	}
	else {
		current->left = new tree;
		current->left->data = tempOutput.back();
		tempOutput.pop_back();
		current->left->level = current->level+1;
		if (current->left->level > biggestLevel)
			biggestLevel = current->left->level;
		current->left->top = current;
		if (!isOperator(current->left->data))
			return;
		buildTree(current->left);
	}

}
void tree::setCoord(tree* current)
{
	
	current->right->coord.first = current->coord.first + (pow(2, (biggestLevel - current->right->level)) * 20);
	current->right->coord.second = current->coord.second + 40;
	if (isOperator(current->right->data))
	{
		setCoord(current->right);
		current->left->coord.first = current->coord.first - (pow(2, (biggestLevel - current->right->level)) * 20);
		current->left->coord.second = current->coord.second + 40;
		if (isOperator(current->left->data))
		{
			setCoord(current->left);
		}
		else
			return;
	}
	else {
		current->left->coord.first = current->coord.first - (pow(2, (biggestLevel - current->right->level)) * 20);
		current->left->coord.second = current->coord.second + 40;
		if (!isOperator(current->left->data))
			return;
		setCoord(current->left);
	}

}
