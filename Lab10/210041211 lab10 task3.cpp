// #include <iostream>
// #include <map>
// #include <vector>
// #include <algorithm>

// using namespace std;



// class TrieNode{
//     public:
//         map<char,TrieNode*> children;
//         bool isEnd;

//         TrieNode(){
//             isEnd = true;
//         }
// };


// class Trie{

// public:
//     TrieNode * root;

//     Trie(){
//         root = new TrieNode();
//     }


//     void insert(string& word){
//         TrieNode* current = root;

//         for(char ch : word){
//             if(current->children.find(ch) == current->children.end()){
//                 current->children[ch] = new TrieNode();

//             }
//             else{
//                 current = current->children[ch];
//             }
//         }

//         current->isEnd = true;

//     }


// };


#include<iostream>
#include<cstdio>
#include<string>
#define SIZE 26
using namespace std;

struct Node{
    Node *next[SIZE];
    bool endmark;
    Node(){
        endmark = false;
        for(int i=0; i< SIZE; i++){
            next[i] = NULL;
        }
    }
};

Node *root = new Node();

void Insert(string str){
    Node *curr = root;
    for(int i=0; i<str.length(); i++){
        int idx = str[i] - 'a';
        //cout << idx << endl;
        if(curr->next[idx] == NULL){
            curr->next[idx] = new Node();
        }
        curr = curr->next[idx];
    }
    curr->endmark = true;
}

void Display(Node *curr, string str){
    if(curr->endmark){
        cout << str << " ";
    }
    for(int i=0; i< SIZE; i++){
        if(curr->next[i] != NULL){
            char c = i + 'a';
            str += c;
            Display(curr->next[i], str);
            str.pop_back();
        }
    }
}

bool Search(string str){
    Node *curr = root;
    for(int i=0; i<str.length(); i++){
        int idx = str[i] - 'a';
        if(curr->next[idx] == NULL){
            return false;
        }
        curr = curr->next[idx];
    }
    return curr->endmark;
}

int main(){
    char c;
    string str = "";
    while(true){
        scanf("%c", &c);
        if('a' <= c && c <= 'z'){
            str += c;
        }
        else{
            Insert(str);
            str = "";
            if(c=='\n') break;
        }
    }
    Display(root, "");
    cout << endl;
    cin.ignore();
    str = "";
    while(true){
        scanf("%c", &c);
        if('a' <= c && c <= 'z'){
            str += c;
        }
        else{
            bool found = Search(str);
            //cout << str << endl;
            str = "";
            cout << (found?"T":"F") << " ";
            if(c=='\n') break;
        }
    }
    return 0;
}

