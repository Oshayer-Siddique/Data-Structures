#include<bits/stdc++.h>

using namespace std;


void solve(stack<int> &stk,int cnt, int size){
    if(cnt == size /2){
        stk.pop();
        return;
    }
    int num = stk.top();
    stk.pop();
    


    solve(stk,cnt+1,size);
    stk.push(num);






}




void printstack(stack<int> &stk){
    if(stk.empty()){
        return;
    }
    int x = stk.top();
    stk.pop();

    printstack(stk);

    cout<<x<<" ";
    


}


int main(){

    stack<int> stk;

    int size;
    cin >> size;

    for(int i =0;i < size;i++){
        int x;
        cin >> x;
        stk.push(x);
        
    }

    int cnt = 0;
    solve(stk,cnt,size);
    printstack(stk);






}