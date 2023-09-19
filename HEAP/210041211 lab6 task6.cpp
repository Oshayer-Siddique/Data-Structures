#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


int main(){

    string s;
    cin >> s;


    string final = "";

    vector<pair<char,int>> pairVector;

    map<char,int> m;
    for(int i = 0;i < s.length();i++){
        m[s[i]]++;
    } 
    map<char,int>::iterator itr;
    for(itr = m.begin();itr != m.end();itr++){

        pairVector.push_back(make_pair(itr->first,itr->second));


        //cout<<itr->first<<" - "<<itr->second<<endl;
    }


    auto customComparator = [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    };


    sort(pairVector.begin(),pairVector.end(),customComparator);


    for(auto& ptr: pairVector){
        //cout<<ptr.first<<" - "<<ptr.second<<endl;
        while (ptr.second--)
        {
            final += ptr.first;
        }
        


        
    }

    cout<<final<<endl;


}