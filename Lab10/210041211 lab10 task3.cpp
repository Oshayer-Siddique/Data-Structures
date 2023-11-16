#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;



class TrieNode{
    public:
        map<char,TrieNode*> children;
        bool isEnd;

        TrieNode(){
            isEnd = true;
        }
};


class Trie{

public:
    TrieNode * root;

    Trie(){
        root = new TrieNode();
    }


    void insert(string& word){
        TrieNode* current = root;

        for(char ch : word){
            if(current->children.find(ch) == current->children.end()){
                current->children[ch] = new TrieNode();

            }
            else{
                current = current->children[ch];
            }
        }

        current->isEnd = true;

    }


};

