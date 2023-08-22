
#include <iostream>
#include <stack>

using namespace std;


void inseratbottom(stack<int> &stk,int element){

    if(stk.empty()){
        stk.push(element);
        return;
    }
    int num = stk.top();
    stk.pop();


    inseratbottom(stk,element);
    stk.push(num);


}




void solve(stack<int> &stk){
    if(stk.empty()){
        return;
    }
    int num = stk.top();
    stk.pop();
    solve(stk);
    inseratbottom(stk,num);


    
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

    solve(stk);
    printstack(stk);




}