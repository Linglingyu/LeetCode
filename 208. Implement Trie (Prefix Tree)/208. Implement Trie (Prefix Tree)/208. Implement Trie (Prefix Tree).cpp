// 208. Implement Trie (Prefix Tree).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<string>
#include<vector>

using namespace std;

class TrieNode{
public:
	char content;
	bool isend;
	vector<TrieNode *> next;//ÿ���ڵ����һ���ڵ�����һ��vector��

	TrieNode():content(' '),isend(false){} //Trie���Կո���Ϊ���ڵ�
	TrieNode(char ch) :content(ch), isend(false){}
	TrieNode* subNode(char ch){
		if (!next.empty()){
			for (auto child : next){
				if (child->content == ch)
					return child;
			}
		}
		return nullptr;
	}

	~TrieNode(){
		for (auto child : next)
			delete child;
	}
};

class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		if (search(word))return;
		TrieNode* curr = root;
		for (auto ch : word){
			TrieNode* child = curr->subNode(ch);
			if (child != nullptr){
				curr = child;
			}
			else{
				TrieNode *newNode = new TrieNode(ch);
				curr->next.push_back(newNode);
				curr = newNode;
			}
		}
		curr->isend = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* curr = root;
		for (auto ch : word){
			curr = curr->subNode(ch);
			if (curr == NULL)
				return false;
		}
		return curr->isend == true;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode* curr = root;
		for (auto ch : prefix){
			curr = curr->subNode(ch);
			if (curr == nullptr)
				return false;
		}
		return true;
	}

	~Trie(){
		delete root;
	}

private:
	TrieNode *root;

};

int _tmain(int argc, _TCHAR* argv[])
{
	Trie *obj = new Trie();
	obj->insert("word");
	obj->insert("world");
	obj->insert("prefix");
	bool param_2 = obj->search("word");
	bool param_3 = obj->startsWith("wor");
	system("pause");
	return 0;
}

