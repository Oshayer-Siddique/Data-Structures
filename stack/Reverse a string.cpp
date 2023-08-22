#include<bits/stdc++.h>

using namespace std;


int main(){
    string s;
    cin >> s;
    stack<char> stk;

    string ans = " ";

    for(int i = 0;i < s.length();i++){
        char ch = s[i];
        stk.push(ch);
    }

    while (!stk.empty())
    {
        char a = stk.top();
        ans.push_back(a);
        stk.pop();


    }

    cout<<ans<<endl;
    


}