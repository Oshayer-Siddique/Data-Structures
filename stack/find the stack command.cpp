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





int main()
{
    stack<int> a, b;
    while (1)
    {
        char ch;
        scanf("%c", &ch);

        if (ch == '\n')
        {
            break;
        }
        else if(ch != ' '){
            b.push(ch - 48);

        }
        
    }

    int size;
    cin >> size;


    //printstack(a);

    for(int i = 1;i <= size;i++){
        a.push(i);
    }

    //printstack(b);

    vector<string> ans;


    while(!b.empty()){
        int x = b.top();
        int y = a.top();
        if(x == y){
            b.pop();
            a.pop();
            ans.push_back("push");
            

        }
        else{
            a.pop();
            ans.push_back("pop");
            ans.push_back("push");
        }
       

    }


    int u = ans.size();


    // for(int i = 0;i < u;i++){
    //     cout<<ans[i]<<" ";
    // }

    // cout<<"\n";







    for(int i = u-1;i >= 0;i--){
        cout<<ans[i]<<" ";
    }

    






    
}