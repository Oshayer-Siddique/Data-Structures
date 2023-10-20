#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
int queue[MAX_SIZE];
int front = -1, rear = -1;

bool isEmpty() {
    if(front == -1){
        return true;

    }
    else{
        return false;
    }
}

bool isFull() {
    if((rear + 1) % MAX_SIZE == front){
        return true;
    }
    else{
        return false;
    }

}

void enqueue(int item) {
    if (isFull()) {
        cout << "Overflow" << endl;
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
        
    }
    queue[rear] = item;

    
   
}

int dequeue() {
    if (isEmpty()) {
        cout << "Underflow" << endl;
        return -1;
    }

    int item = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }

    //cout << "Dequeued: " << item <<endl;
    return item;
}

void display() {
    if (isEmpty()) {
        cout << "Underflow." << endl;
        return;
    }

    //std::cout << "Queue elements: ";
    int i = front;
    while (i != rear) {
        cout << queue[i] << " ";
        i = (i + 1) % MAX_SIZE;
    }
    cout << queue[rear] <<endl;
}

int main() {
    // enqueue(1);
    // enqueue(2);
    // enqueue(3);
    // enqueue(4);
    // enqueue(5);

    // display();

    // dequeue();
    // dequeue();

    // enqueue(6);
    // enqueue(7);

    // display();

    int n;
    cin >> n;
    int f_id;
    while (1)
    {
        /* code */
        cin >> f_id;

        if(f_id == 1){
            int num;
            cin >> num;
            enqueue(num);
           
        }
        else if(f_id == 2){
            dequeue();
        }
        else if(f_id == 3){
            if(isFull() == true){
                cout<<"Full"<<endl;
            }
            else{
                cout<<"Not full"<<endl;
            }
        }
        else if(f_id == 4){
            if(isEmpty() == true){
                cout<<"Empty"<<endl;
            }
            else{
                cout<<" NOt Empty"<<endl;
            }
        }
        else if(f_id == 5){
            cout<<rear - front + 1<<endl;
        }
        display();

        
    }
    






    return 0;
}
