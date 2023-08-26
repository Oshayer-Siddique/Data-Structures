#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void printstack(stack<int> &stk)
{
    if (stk.empty())
    {
        return;
    }
    int x = stk.top();
    stk.pop();

    printstack(stk);

    cout << x << " ";

    stk.push(x);
}


int main(){

    vector<int> arr;


    int x;
    while (1)
    {
        /* code */
        cin >> x;
        if(x == -1){
            break;
        }
        arr.push_back(x);
    }

    int n = arr.size();

    vector<int> nge;
    stack<int> stk;

    for(int i = 0;i < n;i++){
        if(stk.size() == 0){
            stk.push(i);
            
        }
        while(stk.size() > 0 && arr[i] > arr[stk.top()]){

            cout<<stk.top()<<" ";
            nge[stk.top()] = arr[i];

        }

        stk.push(i);
    }

    while(stk.size() > 0){
        nge[stk.top()] == -1;
    }

    for(int i = 0;i < n;i++){
        cout<<nge[i]<<" ";
    }

    

}