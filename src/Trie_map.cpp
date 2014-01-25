#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <string>

using namespace std;

list<string> *listOfStrings;
int countOfWords;

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
						listOfStrings[iter->second->freq - 1].push_back(next_prefix);
					iterate(iter->second, next_prefix);
				}
			}
		}

		void printInReverseFreq() {
			iterate();

			for (int index = countOfWords - 1; index >= 0; index--)
			{
				list<string>::iterator iter;
				for (iter = listOfStrings[index].begin(); iter != listOfStrings[index].end(); iter++)
				{
					cout<<"\n"<<*iter<<" ";
				}
			}
		}

		list<string> getTopNMostFrequent(int num) {
			iterate();

			list<string> topNList;
			for (int index = countOfWords - 1; index >= 0; index--)
			{
				if (num > 0) {
					list<string>::iterator iter;
					for (iter = listOfStrings[index].begin(); iter != listOfStrings[index].end(); iter++)
					{
						if (num-- > 0) {
							topNList.push_back(*iter);
						} else {
							break;
						}
					}
				} else {
					break;
				}
			}
			return topNList;
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

list<string> getTopNMostFrequent(string file_string, int num) {
	Trie *trie = new Trie();

	list<string> topNList;

	char ch;
	const char *file_name = file_string.c_str();
	FILE *file = fopen(file_name, "r");
	if (file) {
		string word = "";
		while ((ch = getc(file)) != EOF) {
			if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' || ch == '\x0b') {
				countOfWords++;
				trie->insert(word);
				word = "";
			} else {
				word += ch;
			}
		}

		listOfStrings = new list<string>[countOfWords];

		topNList = trie->getTopNMostFrequent(num);

		fclose(file);
	}

	return topNList;
}

int main()
{
	list<string> topNList = getTopNMostFrequent("test", 2);
	for(list<string>::iterator iter = topNList.begin(); iter != topNList.end(); ++iter)
	{
	     cout<<*iter<<"\n";
	}
}
