// Online C++ compiler to run C++ program online
#include<iostream>

using namespace std;


    void push(int *arr, int num,int &top){
        top++;
        arr[top] = num;

    }
    
    void pop(int *arr,int &top){
        top--;
        
    }
    
    bool isEmpty(int *arr , int &top){
        
        if(top == -1){
            cout<<"True"<<endl;
        }
        else{
            cout<<"false"<<endl;
        }
        
    }
    bool isFull(int *arr, int &top, int n){
        if(top == n-1){
            cout<<"True"<<endl;
        }
        else{
            cout<<"False"<<endl;
        }
    }
    
    int  size(int *arr,int &top){
        if(top >= 0){
            return top+1;
            
        }
        
    }
    
    int peek(int *arr,int &top){
        if(top > 0){
            return arr[top];
        }
    }
    

int main(){
    int n,f_id;
    cin >> n;

    int stack[n];

    int top = -1;



    while(1){
        cin >> f_id;
        if(f_id == 1){
            
            int num;
            cin >> num;
            if(top == n){
                cout<<"Overflow"<<endl;
                top--;


            }
            else{
                push(stack,num,top);
                
                
                for(int i = 0;i <= top;i++){
                    cout<<stack[i]<<" ";

                }
                cout<<endl;
            }
            

        }
        else if(f_id == 2){
            if(top == 0){
                cout<<"Underflow"<<endl;
            }
            else{
                pop(stack,top);
                for(int i = 0;i <= top;i++){
                    cout<<stack[i]<<" ";
                }
                cout<<endl;
                
            }
            
        }
        else if(f_id == 3){
            isEmpty(stack,top);
            //cout<<endl;
        }
        else if(f_id == 4){
            isFull(stack,top,n);
            //cout<<endl;
        }
        else if(f_id == 5){
            cout<<size(stack,top)<<endl;

        }
        else if(f_id == 6){
            cout<<peek(stack,top)<<endl;
        }

        else if(f_id == -1){
            cout<<"Exit"<<endl;
            break;
        }
    }



}