#include <iostream>
#include <stack>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

void printstack(stack<char> &stk)
{
    if (stk.empty())
    {
        return;
    }
    char x = stk.top();
    stk.pop();

    printstack(stk);

    cout << x << " ";

    stk.push(x);
}


int main(){
    string input;
    cin >> input;
    int n = input.size();

    stack<char> stk;

    for(int i = 0;i < n;i++){
        char c = input[i];
        if(c == '('){
            stk.push(c);

        }
        else if(c == ')'){
            stk.pop();
        }
    }

    //printstack(stk);

    cout<<n-stk.size()<<endl;

}