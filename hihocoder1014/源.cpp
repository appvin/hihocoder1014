#include <iostream>
#include <string>
#include <map>

using namespace std;

class node
{
public:
	map<string, node*> child;

	node(string nn)
	{
		c = nn;
	}
};

class trie
{
private:
	node *root;

public:
	node* add_word(string word)
	{
		int s = int(word.size());
		string t = "";
		node *n = root;
		for (int i = 0; i < s; i++)
		{
			t = word[i];
			if (n->child.count(t) == 0)
			{
				node* nn = new node(t);
				n->child[t] = nn;
				n = nn;
			}
			else
			{
				n = n->child[t];
			}
		}
		return root;
	}

	int find_pre(string pre)
	{

	}
};

int main()
{

}