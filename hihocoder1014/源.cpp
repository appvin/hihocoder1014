#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <iterator>
#include <vector>

using namespace std;

struct node
{
	map<string, node*> child;
	int flag = 0;
};

class trie
{
private:
	node *root;

public:
	trie()
	{
		root = new node;
	}

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
				node* nn = new node;
				n->child[t] = nn;
				n = nn;
				n->flag++;
			}
			else
			{
				n = n->child[t];
				n->flag++;
			}
		}
		return root;
	}

	int find_pre(string pre)
	{
		int s = int(pre.size());
		queue<node*> q;
		node* n = root;
		string t;
		for (int i = 0; i < s; i++)
		{
			t = pre[i];
			if (n->child.count(t) == 0)
			{
				return 0;
			}
			else
			{
				n = n->child[t];
			}
		}
		return n->flag;
		/*q.push(n);
		int sum = 0;
		while (!q.empty())
		{
			n = q.front();
			q.pop();
			if (n->child.size() == 0)
			{
				sum++;
			}
			else
			{
				map<string, node*>::iterator it = n->child.begin();
				for (; it != n->child.end(); it++)
				{
					if ((it->second->flag == 1)&&!(it->second->child.empty()))
						sum++;
					q.push(it->second);
				}
			}
		}
		return sum;*/
	}

	void print()
	{
		queue<node*> q;
		q.push(root);
		node *n;
		while (!q.empty())
		{
			n = q.front();
			q.pop();
			map<string, node*>::iterator it = n->child.begin();
			for (; it != n->child.end(); it++)
			{
				cout << it->first << it->second->flag;
				q.push(it->second);
			}
			cout << " ";
		}
	}
};

int main()
{
	int n;
	trie t;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		t.add_word(s);
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		cout << t.find_pre(s) << endl;
	}
}