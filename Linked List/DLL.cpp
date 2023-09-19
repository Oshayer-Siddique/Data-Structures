#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* previous;




//constructor
    Node(int x){
        this->data = x;
        this->next = NULL;
        this->previous = NULL;

    }
};



int getSize(Node* &head){
    Node* temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;



}



void insert_head(Node* &head, int x){
    Node* temp = new Node(x);
    temp->next = head;
    head->previous = temp;
    head = temp;

}


void insert_tail(Node* &tail,int x){
    Node* temp = new Node(x);
    tail->next = temp;
    temp->previous = tail;
    temp = tail;



}


void Print(Node* head){
    Node* temp = head;
    while (temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    


}

int main(){
    Node* node1 = new Node(45);


    Node* head = node1;
    Node* tail = node1;

    insert_head(head,11);
    insert_tail(tail,10);
    insert_head(head,100);
    insert_head(head,210);

    

    Print(head);
    cout<<endl;
    cout<<getSize(head)<<endl;
}