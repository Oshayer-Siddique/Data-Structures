#include <iostream>
using namespace std;

int front = -1;
int rear = -1;

bool isEmpty(int arr[], int size)
{
    if (front == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(int arr[], int size)
{
    if ((rear + 1) % size == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void push_back(int arr[], int size, int x){
    if (isFull(arr, size) == true)
    {
        cout << "OVERFLOW" << endl;
    }
    if (isEmpty(arr, size) == true)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % size;
    }
    arr[rear] = x;


}

void pop_front(int arr[], int size){
    if(isEmpty(arr,size) == true){
        cout<<"Underflow"<<endl;
    }
    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1) % size;
    }

}

void pop_back(int arr[], int size){
    if(isEmpty(arr,size) == true){
        cout<<"UNDERFLOW"<<endl;
    }
    if(rear == front){
        front = rear = -1;

    }
    else if(rear == 0){
        rear = size  - 1;
    }
    else{
        rear--;
    }
}


void push_front(int arr[],int size,int x){
    if(isFull(arr,size) == true){
        cout<<"OVERFLOW"<<endl;
    }
    if(front == -1){
        front = 0;
        rear = 0;
    }
    else if(front == 0){
        front = size - 1;

    }
    else{
        front--;
    }
    arr[front] = x;


}



void display(int arr[], int size)
{
    if (isEmpty(arr, size) == true)
    {
        cout << "UNDERFLOW" << endl;
    }
    int i = front;
    while (i != rear)
    {
        cout << arr[i] << " ";
        i = (i + 1) % size;
    }
    cout << arr[rear] << endl;
}



int main(){
    int size;
    cin >> size;
    int f_id;
    int Q[size];
    while (1)
    {
        cin >> f_id;
        if(f_id == 2){
            int x;
            cin >> x;
            push_back(Q,size,x);
        }
        else if(f_id == 3){
            pop_front(Q,size);
        }
        else if(f_id == 1){
            int x;
            cin >> x;
            push_front(Q,size,x);

        }
        else if(f_id == 4){
            pop_back(Q,size);
        }

        else if(f_id == 6){
            cout<<"EXIT"<<endl;
            break;
        }

        
        display(Q,size);
    }
    
}