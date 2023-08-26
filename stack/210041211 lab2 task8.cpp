#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stack>


using namespace std;

bool isBalanced(string str) {
    stack<char> my_stack;
    char a;
    for (int i=0; i<str.length(); i++) {
        if ( str[i] == '(' ||
            str[i]== '[' ||
            str[i]== '{')
        {
            my_stack.push(str[i]);
            continue;
        }

        if(str[i] == ')'){
            if (my_stack.empty())
                return false;
            a = my_stack.top();
            my_stack.pop();
            if(a == '{' || a == '['){
                return false;
            }
        }
        else if(str[i] == '}'){
            if (my_stack.empty())
                return false;
            a = my_stack.top();
            my_stack.pop();
            if(a == '(' || a == '['){
                return false;
            }
        }
        else if(str[i] == ']'){
            if (my_stack.empty())
                return false;
            a = my_stack.top();
            my_stack.pop();
            if(a == '{' || a == '('){
                return false;
            }
        }
    }
    return (my_stack.empty());
}
main() {
    int n;
    cin >> n;
    fflush(stdin);
    string data,a;
    for(int i=0; i<n; i++){
        getline(cin, a);
        data+=a;

    }
    if (isBalanced(data)){
            cout << "No Error" << endl;
        }

    else{
            cout << "Error" << endl;
        }


}
