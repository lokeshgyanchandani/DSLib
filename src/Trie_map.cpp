#include <iostream>
#include <list>
#include <iterator>
#include <map>

using namespace std;

list<string> listOfStrings[4];

struct TrieNode {
	int freq;
	typedef map<char, TrieNode*> span;
	span child_map;

	TrieNode() : freq(0), child_map(map<char, TrieNode*>()) {}
};

class Trie {
	public:
		Trie():root(new TrieNode) {
		}

		~Trie() {
			delete_trie(root);
		}

		void insert(string word)
		{
			TrieNode *temp = root;
			string::iterator iter_word = word.begin();
			for (iter_word = word.begin(); iter_word != word.end(); iter_word++) {
				char cur_char = *iter_word;
				if (temp->child_map.find(cur_char) == temp->child_map.end()) {
					temp->child_map[cur_char] = new TrieNode;
				}
				temp = temp->child_map[cur_char];
			}
			temp->freq++;
		}

		void iterate() {
			iterate(root, "");
		}

		void iterate(TrieNode *node, string prefix) {
			if (node != NULL) {
				map<char, TrieNode*>::iterator iter;
				for (iter = node->child_map.begin(); iter != node->child_map.end(); iter++) {
					string next_prefix = prefix + (char)iter->first;
					if(iter->second->freq > 0)
						listOfStrings[iter->second->freq].push_front(next_prefix);
					iterate(iter->second, next_prefix);
				}
			}
		}

	private:
		TrieNode *root;

		void delete_trie (TrieNode* node) {
		        if (node != NULL) {
		        	map<char, TrieNode*>::iterator iter;
		        	for (iter = node->child_map.begin(); iter != node->child_map.end(); iter++) {
		        		delete_trie(iter->second);
		        	}
		            delete node;
		        }
		}
};

int main()
{
	Trie *trie = new Trie();
	trie->insert("one");
	trie->insert("two");
	trie->insert("one;");
	trie->insert("one;");
	trie->insert("one;");
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
