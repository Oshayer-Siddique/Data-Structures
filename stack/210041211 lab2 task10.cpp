#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>


using namespace std;

int main()
{
    string str = "";
    int n,a;
    cin >> n;

    stack <int> st1,st2;
    for(int i=1; i<=n; i++)
    {
        cin >> a;

        if( a==1 || (!(st1.empty()) && (a-st1.top() ==1) ))
        {
            st1.push(a);

        }
        else
        {
            st2.push(a);
        }
        if(!st1.empty() && !st2.empty() && (st2.top() - st1.top() == 1)){
            st1.push(st2.top());
            st2.pop();
        }
    }
    if(st1.size() == n && st2.empty()){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }



}