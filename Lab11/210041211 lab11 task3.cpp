#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


using namespace std;

string removePunct(string& word) {
    string result;
    for (char c : word) {
        if (!ispunct(c)) {
            result += c;
        }
    }
    return result;
}

int main(){

    string sent;
    getline(cin,sent);

    istringstream a(sent);
    string w;
    unordered_map<string,int> wf;

    while(a >> w){
        string data = removePunct(w);

        for(char &ch : data){
            ch = tolower(ch);

        }
        wf[data]++;
    }

    for(auto& pair : wf){
        if(pair.second > 1){
            cout<<pair.first<<" "<<pair.second<<endl;
        }
    }



}
