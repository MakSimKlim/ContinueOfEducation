// 230911_binary tree code
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>

using namespace std;

struct TeamMatch
{
	string Name;
	int Points;

	TeamMatch(string name, int points):
		Name{ name }, Points{points}
	{}
};

class Match
{
public:
	TeamMatch Owner;
	TeamMatch Opponent;
	string Score;
	
	Match* left, * right, * parent;

	Match(TeamMatch tm1, TeamMatch tm2)
		:Owner{ tm1 }, Opponent{tm2},
		Score{to_string(tm1.Points) + " : " + to_string(tm2.Points)}
	{}

	int getScore() const
	{
		return Owner.Points + Opponent.Points;
	}

	friend bool operator==(Match m1, Match m2);
	friend bool operator!=(Match m1, Match m2);
	friend bool operator>(Match m1, Match m2);
	friend bool operator<(Match m1, Match m2);
	friend bool operator>=(Match m1, Match m2);
	friend bool operator<=(Match m1, Match m2);

	friend ostream& operator<<(ostream& out, Match m);

};
//операторы сравнения
bool operator==(Match m1, Match m2)
{
	return m1.Owner.Name == m2.Owner.Name;
}
bool operator!=(Match m1, Match m2)
{
	return !(m1 == m2);
}
bool operator>(Match m1, Match m2)
{
	return m1.Owner.Name > m2.Owner.Name;
}
bool operator<(Match m1, Match m2)
{
	return m1.Owner.Name < m2.Owner.Name;
}
bool operator>=(Match m1, Match m2)
{
	return !(m1.Owner.Name < m2.Owner.Name);
}
bool operator<=(Match m1, Match m2)
{
	return !(m1.Owner.Name > m2.Owner.Name);
}
ostream& operator<<(ostream& out, Match m)
{
	out << m.Owner.Name << " " << m.Score << " " << m.Opponent.Name;
}


class MatchTree
{
	Match* root;
public:
	MatchTree();
	~MatchTree();
	void Display(Match* node);//узел графа - node
	Match* Search(Match* node, string key);
	Match* Min(Match* node);
	Match* Max(Match* node);
	Match* Next(Match* node);
	Match* Prev(Match* node);
	void Insert(Match* newNode);
	//Если передается 0, удаляем всё дерево
	void Delete(Match* newNode = 0);
	Match* GetRoot() const { return root; }

};

MatchTree::MatchTree()
{
	root = nullptr;
}
MatchTree::~MatchTree()
{
	Delete();
}

void MatchTree::Display(Match* node)
{
	if (node != nullptr)
	{
		Display(node->left);
		cout << *node << endl;
		Display(node->right);
	}

}

Match* MatchTree::Search(Match* node, string name)
{
	while (node != nullptr && name != node->Owner.Name)
	{

		if (name < node->Owner.Name)
			node = node->left;
		else
			node = node->right;

	}
	return node;

}
Match* MatchTree::Min(Match* node)
{
	
	if (node != nullptr)
		while (node->left != nullptr)
			node = node->left;
	return node;
}
Match* MatchTree::Max(Match* node)
{

	if (node != nullptr)
		while (node->right != nullptr)
			node = node->right;
	return node;
}
Match* MatchTree::Next(Match* node)
{

	Match* y = nullptr;
	if (node != nullptr)
	{
		if (node->right != nullptr)
		{
			return Min(node->right);
		}
		y = node->parent;
		while (y != nullptr && node == y->right)
		{
			node = y;
			y = y->parent;

		}
	}
	return y;
}
Match* MatchTree::Prev(Match* node)
{

	Match* y = nullptr;
	if (node != nullptr)
	{
		if (node->left != nullptr)
		{
			return Max(node->left);
		}
		y = node->parent;
		while (y != nullptr && node == y->left)
		{
			node = y;
			y = y->parent;

		}
	}
	return y;
}

Match* MatchTree::GetRoot() const
{
	return root;
}

void MatchTree::Insert(Match* newNode)
{
	newNode->left = nullptr;
	newNode->right = nullptr;

	Match* y = nullptr;
	Match* node = root;

	while (node != nullptr)
	{
		y = node;
		if (*newNode < *node)
		{
			node = node->left;
		}
		else 
		{
			node = node->right;
		}
	}

	newNode->parent = y;
	if (y==nullptr)
	{
		root = newNode;
	}
	else if (*newNode < *y)
	{
		y->left = newNode;
	}
	else
	{
		y->right = newNode;
	}
}


