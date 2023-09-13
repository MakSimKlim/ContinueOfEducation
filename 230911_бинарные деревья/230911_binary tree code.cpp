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

	TeamMatch() :
		TeamMatch{ "", 0 }
	{}
};

class Match
{
public:
	TeamMatch Owner;
	TeamMatch Opponent;
	string Score;
	
	Match* left, * right, * parent; // Дерево: указаьели - левый потомок, правый потомок, родитель

	Match(TeamMatch tm1, TeamMatch tm2) // новый узел
		:Owner{ tm1 }, Opponent{tm2},
		Score{to_string(tm1.Points) + " : " + to_string(tm2.Points)}
	{}

	int GetScore() const
	{
		return Owner.Points + Opponent.Points; 
	}

	// Дружественные функции (объявление)
	friend bool operator==(Match m1, Match m2); 
	friend bool operator!=(Match m1, Match m2);
	friend bool operator>(Match m1, Match m2);
	friend bool operator<(Match m1, Match m2);
	friend bool operator>=(Match m1, Match m2);
	friend bool operator<=(Match m1, Match m2);

	friend ostream& operator<<(ostream& out, Match m);

};
//операторы сравнения (реализация дружественных функций)
// чтобы при необходимости изменить операцию сравнения, нужно как можно
// больше завязать из друг на дружке, чтобы при иправлении меньше работы было
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
	return !(m1 < m2);
}
bool operator<=(Match m1, Match m2)
{
	return !(m1 > m2);
}
ostream& operator<<(ostream& out, Match m)
{
	out << m.Owner.Name << " " << m.Score << " " << m.Opponent.Name;
}


class MatchTree // дерево
{
	Match* root; // указатель на узел (здесь это корень)
public:
	MatchTree();
	~MatchTree();

	// действия начиная с определенного узла
	void Display(Match* node);//узел графа - node
	Match* Search(Match* node, string key);//поиск с определенного узла
	Match* Min(Match* node);
	Match* Max(Match* node);
	Match* Next(Match* node);
	Match* Prev(Match* node);
	void Insert(Match* newNode);
	//Если передается 0, удаляем всё дерево
	void Delete(Match* nodeDel = 0);
	Match* GetRoot() const { return root; }// функция получения корня

};

MatchTree::MatchTree()
{
	root = nullptr;// изначально дерево пустое, т.е. корень его пустой
}
MatchTree::~MatchTree()
{
	Delete();// удаляем всё дерево
}

void MatchTree::Display(Match* node)// рекурсия функцмии показа
{
	if (node != nullptr)
	{
		Display(node->left);// идем в левый узел
		cout << *node << endl;//выводим что нам надо
		Display(node->right);// идем в правый узел
	}

}

// псевдо  рекурсия, потому что меняем то, что передали (node)
Match* MatchTree::Search(Match* node, string name)// поиск имя команды владельца
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
Match* MatchTree::Min(Match* node)//поиск минимума
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

	Match* y = nullptr;// берем некий узел, делаем его nullptr
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
		//псевро рекурмивный объект
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

void MatchTree::Delete(Match* nodeDel = 0)
{
	if (nodeDel != 0)
	{
		Match* node, * y;
		if (nodeDel->left == nullptr || nodeDel->right == nullptr)
			y = nodeDel;
		else
			y = Next(nodeDel);

		if (y->left != nullptr)
			node = y->left;
		else
			node = y->right;

		if (node != nullptr)
			node->parent = y->parent;

		if (y->parent == nullptr)
			root = node;
		else if (y == y->parent -> left)
			y->parent->left = node;
		else
			y->parent->right = node;
		
		if (y != nodeDel)
		{
			nodeDel->Owner = y->Owner;
			nodeDel->Opponent = y->Opponent;
			nodeDel->Score = y->Score;

		}
		delete y;


	}
	else
	{
		while (root != nullptr)
			Delete(root);
	}
}

MatchTree tournament;
const int teamsCount = 4;

void Game(string teams[])
{
	int i, j;
	int p1, p2;
	int k;

	Match* temp;
	TeamMatch owner, oppnt;
	for (k = 0; k < 2; k++)
	{
		for (i = 0; i < teamsCount; i++)
		{
			for (j = i+1; j < teamsCount; j++)
			{
				TeamMatch owner;
				TeamMatch oppnt;
				if (k==0)
				{
					owner.Name = teams[i];
					owner.Name = teams[j];
				}
				else
				{
					owner.Name = teams[j];
					owner.Name = teams[i];
				}
				owner.Points = rand() % 6;
				oppnt.Points = rand() % 6;
				temp = new Match{ owner, oppnt };
				tournament.Insert(temp);
				
			}

		}

	}

}

int main()
{
	srand(time(0));

	string teams[]
	{
		"Armory",
		"Bavario",
		"Chestno",
		"Derevenskie"
	};

	Game(teams);
	tournament.Display(tournament.GetRoot());

	return 0;
}