#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

const int ALPHABET_SIZE = 26;
list<string> listOfStrings[4];

struct trie_node {
	int freq;
	trie_node *child[ALPHABET_SIZE];

	trie_node() {
		for(int index = 0; index < ALPHABET_SIZE; index++)
			child[index] = NULL;
		freq = 0;
	}
};

class Trie {
	public:
		Trie():root(new trie_node){
		}

		~Trie() {
			delete_trie(root);
		}

		void insert(string word)
		{
			trie_node *temp = root;
			for (unsigned int index = 0; index < word.length(); index++)
			{
				if (temp->child[word[index] - 'a'] == NULL)
				{
					temp->child[word[index] - 'a'] = new trie_node;
				}
				temp = temp->child[word[index] - 'a'];
			}
			temp->freq++;
		}

		void iterate() {
			iterate(root, "");
		}

		void iterate(trie_node *trie_node, string prefix)
		{
			if (trie_node != NULL)
			{
				for (int index = 0; index < 26; index++)
				{
					if (trie_node->child[index] != NULL)
					{
						string next_prefix = prefix + char('a' + index);
						if (trie_node->child[index]->freq > 0)
							listOfStrings[trie_node->child[index]->freq].push_front(next_prefix);
						iterate(trie_node->child[index], next_prefix);
					}
				}
			}
		}

	private:
		trie_node *root;

		void delete_trie (trie_node* t) {
		        int index;
		        if (t != NULL) {
		            for(index = 0; index < ALPHABET_SIZE; index++)
		                delete_trie(t->child[index]);
		            delete t;
		        }
		}
};

int main()
{
	Trie *trie = new Trie();
	trie->insert("one");
	trie->insert("two");
	trie->insert("one");
	trie->insert("two");
	trie->insert("two");
	cout<<"Added all";

	trie->iterate();

	for (unsigned int index = 3; index > 0; index--)
	{
		list<string>::iterator iter;
		for (iter = listOfStrings[index].begin(); iter != listOfStrings[index].end(); iter++)
		{
			cout<<"\n"<<*iter<<" ";
		}
	}

	cout<<"\n"<<"print";
}
