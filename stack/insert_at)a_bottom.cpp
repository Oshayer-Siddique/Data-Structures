#include<bits/stdc++.h>

using namespace std;


void insertatbottom(stack<int> &stk,int element){
    if(stk.empty()){
        stk.push(element);
        return;
    }
    int num = stk.top();
    stk.pop();

    insertatbottom(stk,element);
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

    insertatbottom(stk,100);
    printstack(stk);
}