#include <iostream>
#include<stack>
using namespace std;


void Push(stack<int> &s1, stack<int> &s2,int x){
    s1.push(x);


}

void Pop(stack<int> &s1, stack<int> &s2){

    if(s1.size() == 0 && s2.size() == 0){
        cout<<"Empty"<<endl;
    }
    else{
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        
        
    }

}



void display(stack<int> s){
    if(s.empty()){
        return;
    }
    int x = s.top();
    s.pop();
    display(s);
    cout<<x<<" ";
    s.push(x);

}



int main(){
    int n , q;
    cin >> n >> q;

    stack<int> s1,s2;
    int f_id;
    while (q--)
    {
        cin >> f_id;
        if(f_id == 1){
            int x;
            cin >> x;
            Push(s1,s1,x);
            cout<<"Size :"<<s1.size()<<endl;
            display(s1);
            cout<<endl;


        }
        else if(f_id == 2){
            Pop(s1,s2);
            if(s1.size() == 0){
                cout<<"Empty"<<endl;
            }
            cout<<"Size :"<<s1.size()<<endl;
            display(s1);
            cout<<endl;

        }

        
    }
    
}