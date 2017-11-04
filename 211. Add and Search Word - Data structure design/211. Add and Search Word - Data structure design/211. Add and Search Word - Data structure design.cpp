// 211. Add and Search Word - Data structure design.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class TrieNode{
public:
	TrieNode() :content(' '), isend(false){}
	TrieNode(char ch) :content(ch), isend(false){}
	TrieNode* subnode(char ch){
		if (next.empty()){
			return nullptr;
		}
		for (auto i : next){
			if (i->content == ch)
				return i;
		}
		return nullptr;
	}

	~TrieNode(){
		for (auto i : next)
			delete i;
	}

	char content;
	bool isend;
	vector<TrieNode *> next;
};

class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new TrieNode();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		if (search(word))return;
		TrieNode *curr = root;
		for (auto ch : word){
			if (curr->subnode(ch) != nullptr)
				curr = curr->subnode(ch);
			else{
				TrieNode *newnode = new TrieNode(ch);
				curr->next.push_back(newnode);
				curr = newnode;
			}
		}
		curr->isend = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return query(word.c_str(), root);
	}

private:
	TrieNode *root;
	bool query(const char* ch, TrieNode* curr){
		TrieNode* run = curr;
		for (int i = 0; ch[i]; i++){
			if (run&&ch[i] != '.')
				run = run->subnode(ch[i]);
			else if (run&&ch[i] == '.'){
				TrieNode* tmp = run;
				for (int j = 0; j < tmp->next.size(); j++){
					run = tmp->next[j];
					if (query(ch + i + 1, run))
						return true;
				}
			}
			else
				break;
		}
		return run->next.empty() && run->isend;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	WordDictionary *obj = new WordDictionary();
	obj->addWord("a");
	obj->addWord("a");
	cout<<obj->search(".")<<endl;
	cout<<obj->search("a")<<endl;
	cout<<obj->search("aa")<<endl;
	cout<<obj->search("a")<<endl;
	cout<<obj->search(".a")<<endl;
	cout<<obj->search("a.")<<endl;
	system("pause");

	return 0;
}

