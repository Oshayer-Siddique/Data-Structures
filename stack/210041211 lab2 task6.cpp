#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void printvector(vector<int> &vec,int &size){
    for(int i =0;i < size;i++){
        cout<<vec[i]<<" ";
    }
}



int main(){


    string expression;


    while(1)
    {
        /* code */

        stack<char> stk;
        getline(cin , expression);
        if(expression.empty()){
            break;
        }

        //cout<<expression<<endl;

        int n = expression.size();
        for(int i=  0;i < n;i++){
            if(expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
                stk.push(expression[i]);

            }
            else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){
                stk.pop();
            }
        }

        if(stk.empty() == true){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }




    }
    







}