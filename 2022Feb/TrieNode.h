#ifndef TRIENODE_H
#define TRIENODE_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>

struct TrieNode{
    int end;
    int pass;
    TrieNode *nexts[26];

    TrieNode() : end(0), pass(0) {
        for (int i = 0; i < 26; ++i)
        {
            nexts[i] = nullptr;
        }
    }
};

class Trie
{
private:
    TrieNode *root;
public:
    Trie();
    ~Trie();
    void insert(std::string word);
    void del(std::string word);
    int search(std::string word);
    int prefixNumber(std::string pre);
};

Trie::Trie()
{
    root = new TrieNode();
}

Trie::~Trie()
{
}

void Trie::insert(std::string word){
    TrieNode *cur;
    cur = root;
    cur->pass++;

    //HashMap
    std::vector<char> chr;

    for (auto c : word){
        chr.push_back(c);
    }

    for (int i = 0; i < word.length(); ++i)
    { 
        int index = chr[i] - 'a';  
        if (cur->nexts[index] == nullptr) {
            cur->nexts[index] = new TrieNode();
        }
        cur = cur->nexts[index];
        cur->pass++;
    }
    cur->end++;
    return;
}

void Trie::del(std::string word){
    if(search(word) == 0) return;
    TrieNode *cur = root;
    std::vector<char> chr;
    std::stack<TrieNode*> deleteNode;

    for(auto c : word){
        chr.push_back(c);
    }

    for (int i = 0; i < word.length(); ++i)
    {
        int index = chr[i] - 'a';
        if(--cur->pass == 0){
            deleteNode.push(cur->nexts[i]);
        }
        cur = cur->nexts[index];
    }
    cur->end--;
    
    while(!deleteNode.empty()){
        cur = deleteNode.top();
        delete cur;
        deleteNode.pop();
    }
}

int Trie::search(std::string word){
    TrieNode *cur = root;

    std::vector<char> chr;
    for (auto c : word) {
        chr.push_back(c);
    }

    for (int i = 0; i < word.length(); ++i)
    {
        int index = chr[i] - 'a';
        if (cur->nexts[index] == nullptr) {
            return 0;
        }
        cur = cur->nexts[index];
    }
    return cur->end;
    
}

int Trie::prefixNumber(std::string pre){
    TrieNode *cur = root;
    std::vector<char> chr;

    for (auto c : pre) {
        chr.push_back(c);
    }

    for (int i = 0; i < pre.length(); ++i)
    {
        int index = chr[i] - 'a';
        if (cur->nexts[index] == nullptr)
        {
            return 0;
        }
        cur = cur->nexts[index];
    }
    return cur->pass;
}


#endif //TRIENODE_H