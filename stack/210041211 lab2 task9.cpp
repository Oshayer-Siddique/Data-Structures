#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void printstack(stack<char> &stk){
    if(stk.empty()){
        return;
    }
    char x = stk.top();
    stk.pop();

    printstack(stk);

    cout<<x<<" ";
    


}


void printvector(vector<int> &vec,int &size){
    for(int i =0;i < size;i++){
        cout<<vec[i]<<" ";
    }
}


int main(){
    string s;
    cin >> s;

    stack<char> stk;
    for(int i = 0;i < s.size();i++){

        if(!stk.empty() && stk.top() == s[i]){
            stk.pop();
        }
        else{
            stk.push(s[i]);
        }



    }

    printstack(stk);
}