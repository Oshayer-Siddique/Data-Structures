#include<iostream>
using namespace std;

int front = -1;
int rear = -1;





bool isFull(int arr[],int size){

    if(rear == size - 1){
        return true;
    }
    else{
        return false;
    }


}

bool isEmpty(int arr[],int size){
    if(front == -1){
        return true;
    }
    else{
        return false;
    }
}


void enqueue(int arr[],int size,int x){
    if(isFull(arr, size) == true){
        cout<<"OVERFLOW"<<endl;

    }
    else{
        if(front == -1){
            front = 0;
        }
        rear++;
        arr[rear] = x;


    }




}


void dequeue(int arr[], int size){
    if(front == rear){
        cout<<"UNDERFLOW"<<endl;
    }
    else{
        front++;
    }

}

void display(int arr[], int size){
    if(isEmpty(arr,size) == true){
        cout<<"UNDERFLOW"<<endl;
    }
    int i = front;
    while (i != rear) {
        cout << arr[i] << " ";
        i = i+1;
    }
    cout << arr[rear] <<endl;


}




int main(){

    int size;
    cin >> size;
    int f_id;
    int Q[size];


    while (1)
    {
        cin >> f_id;
        if(f_id == 4){
            if(isFull(Q,size) == true){
                cout<<"FULL"<<endl;
            }
            else{
                cout<<"Not full"<<endl;
            }
        }
        else if(f_id == 3){
            if(isEmpty(Q,size) == true){
                cout<<"Empty"<<endl;

            }
            else{
                cout<<"Not empty"<<endl;
            }

        }
        else if(f_id == 1){
            int x;
            cin >> x;
            enqueue(Q,size,x);
        }
        else if(f_id == 2){
            dequeue(Q,size);
        }
        display(Q,size);
    }
    






}
