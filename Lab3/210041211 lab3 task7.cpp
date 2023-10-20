#include<bits/stdc++.h>
#include <stdlib.h>

using namespace std;


int main(){
    stack<int>stk;
    vector<string> s;
    string str;
    
   
    for(int i = 0;i < 5;i++){
        cin >> str;
        s.push_back(str);
    }
    for(int i = 0;i < s.size();i++){
        if(s[i] !=  "+" && s[i] != "-" && s[i] != "/" && s[i] != "*"){
            stk.push(stoi(s[i]));

        }
        else{
            int x = stk.top();
            stk.pop();
            int y = stk.top();
            stk.pop();
            if(s[i] == "+"){
                stk.push(y+x);

            }
            else if(s[i] == "-"){
                stk.push(y-x);
            }
            else if(s[i] == "*"){
                stk.push(y*x);
            }
            else if(s[i] == "/"){
                stk.push(y/x);
            }

        }
    }

    int m = stk.top();

    cout<<m<<endl;
    




    


}