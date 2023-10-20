#include<bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;

    string str;
    cin >> str;

    for(int i = 3;i < n;i++){
        if(str[i] == 'd' && str[i+1] == 'u' && str[i+2] == 'b'){
            cout<<' ';
            i = i+ 2;

        }
        else{
            cout<<str[i];
        }
    }

    // for(int i = 3;i < n;i++){
    //     cout<<s[i];
    // }


}