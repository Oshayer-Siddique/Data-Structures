#include <iostream>
#include <stack>
//#include <queue>



using namespace std;


const int max_size = 5;
int arr[max_size];
int front = 0,rear = 0;



bool isFull(){
    if(rear  - front  == max_size){
        return true;
    }
    else{
        return false;

    }
}


bool isEmpty(){
    if(front == 0 && rear == 0){
        return true;
    }
    else {
        return false;
    }
}

void push_back(int val){

    if(isFull()){
        cout<<"Overflow"<<endl;
        return;
    }

    else{
        rear++;
        
    }
    arr[rear] = val;

    
    
   


}

void pop_back(){
    if(isEmpty()){
        cout<<"Underflow"<<endl;
    }
    else{
        rear--;

    }
}

void pop_front(){
    if(isEmpty()){
        cout<<"Underflow"<<endl;
    }
    else{
        front++;
    }
}

void push_front(int element){
    if(isFull()){
        cout<<"Overflow"<<endl;
        return;
    }
    else if(front > 0){
        front--;
    }

    arr[front] = element;

    

}

void display(){
    if(isEmpty()){
        cout<<"Uderflow"<<endl;
    }
    else{
        for(int i = front+1;i != rear;i++){
            cout<<arr[i]<<" ";
        }
    }


    cout<<arr[rear]<<endl;
}



int main(){

    int f_id;

    while (1)
    {
        cin >> f_id;
        if(f_id == 1){
            int num;
            cin >> num;
            push_back(num);
        }
        else if(f_id == 2){
            pop_back();
        }
        else if(f_id == 3){
            pop_front();
        }
        else if(f_id == 4){
            int val;
            cin >> val;
            push_front(val);
        }

        display();
    }
    

}