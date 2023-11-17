#include<iostream>
#include<cstdio>
#include<string>
#define SIZE 26
using namespace std;

struct Node{
    Node *next[SIZE];
    bool endmark;
    int count;
    Node(){
        endmark = false;
        count = 0;
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
        curr->count++;
        //cout << idx << endl;
        if(curr->next[idx] == NULL){
            curr->next[idx] = new Node();
        }
        curr = curr->next[idx];
    }
    curr->count++;
    curr->endmark = true;
}

int Search(string str){
    Node *curr = root;
    for(int i=0; i<str.length(); i++){
        int idx = str[i] - 'a';
        if(curr->next[idx] == NULL){
            return 0;
        }
        curr = curr->next[idx];
    }
    return curr->count;
}

int main(){
    char c;
    string str = "";
    int N, Q;
    cin >> N >> Q;
    cin.ignore();
    while(N){
        scanf("%c", &c);
        if('a' <= c && c <= 'z'){
            str += c;
        }
        else if('A' <= c && c <= 'Z'){
            c += 32;
            str += c;
        }
        else{
            Insert(str);
            str = "";
            N--;
        }
    }
    //Display(root, "");
    //cin.ignore();
    str = "";
    while(Q){
        scanf("%c", &c);
        if('a' <= c && c <= 'z'){
            str += c;
        }
        else if('A' <= c && c <= 'Z'){
            c += 32;
            str += c;
        }
        else{
            cout << Search(str) << endl;
            str = "";
            Q--;
        }
    }
    return 0;
}
