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


void printvector(vector<int> &vec,int &size){
    for(int i =0;i < size;i++){
        cout<<vec[i]<<" ";
    }
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

    vector<int>b(n,-1);

    
    stack<int> stk;

    for(int i = n-1;i >= 0;i--){
        while(!stk.empty() && stk.top() <= arr[i] ){
            stk.pop();

        }
        if(stk.empty() == false){
            b[i] = stk.top();
        }
        stk.push(arr[i]);

    }


    printvector(b,n);





    

}