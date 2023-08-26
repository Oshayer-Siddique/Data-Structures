#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int getIndex(stack<int> stk, int element)
{

    stack<int> tempstk;

    int index = 0;

    while (!stk.empty())
    {
        if (stk.top() == element)
        {
            break;
        }
        tempstk.push(stk.top());
        stk.pop();
    }

    while (!tempstk.empty())
    {
        stk.push(tempstk.top());
        tempstk.pop();
        ++index;
    }

    return index;
}

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

void printvector(vector<int> &vec, int &size)
{
    for (int i = 0; i < size; i++)
    {
        cout << vec[i] << " ";
    }
}

// void removeelement(stack<int> &stk, int element){
//     stack<int> tempstk;
//     while (!stk.empty())
//     {
//         if(stk.top() != element){
//             tempstk.push(stk.top());
//         }
//         stk.pop();
//     }
//     while(!tempstk.empty()){
//         stk.push(tempstk.top());
//         tempstk.pop();
//     }

// }

void removeIndx(stack<int> &stk, int index)
{
    stack<int> tempstk;

    int size = stk.size();
    for (int i = 0; i < size; i++)
    {
        if (i != index)
        {
            tempstk.push(stk.top());
        }
        stk.pop();
    }

    while (!tempstk.empty())
    {
        stk.push(tempstk.top());
        tempstk.pop();
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    stack<int> a;
    vector<int> arr(n, 0), brr(n, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }

    for (int i = 0; i < q; i++)
    {
        int y;
        cin >> y;
        brr[i] = y;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        a.push(arr[i]);
    }

    // cout<<val<<endl;

    // cout<<getIndex(arr,q)<<endl;

    // cout<<a.top()<<endl;

    // removeelement(a,3);

    for (int i = 0; i < q; i++)
    {

        int x = getIndex(a, brr[i]);
        //cout << x << endl;
        //printstack(a);
        //cout << "\n";
        removeIndx(a, x);
        //printstack(a);
        //cout << "\n";
        a.push(brr[i]);

        //printstack(a);
        //cout << "\n";
        //cout << "\n";


        cout<<x+1<<endl;
    }

    // printvector(arr,n);

    


}