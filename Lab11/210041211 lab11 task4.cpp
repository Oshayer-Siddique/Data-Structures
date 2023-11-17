#include<iostream>
#include <unordered_map>
using namespace std;

int main(){
    char c;
    string word, meaning;
    unordered_map<string, string> dictionary;
    while(true){
        char c;
        c = cin.peek();
        if(c=='\n') break;
        cin >> meaning >> word;
        dictionary[word] = meaning;
        cout << dictionary[word] << endl;
        cin.ignore();
    }
    while(true){
        cin >> word;
        if(dictionary[word] != ""){
            cout << dictionary[word] <<endl;
        }
        else{
            cout << "eh" << endl;
        }
    }
    return 0;
}