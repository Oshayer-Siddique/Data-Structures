#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* previous;




//constructor
// Node(){
//     this->data = -1;
//     this->next = NULL;
//     this->previous = NULL;

// }


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

void insertPosition(Node *&head, Node *&tail, int pos, int x)
{
    Node *temp = head;
    int cnt = 1;

    if (pos == 1)
    {
        insert_head(head, x);
        return;
    }

    if (temp->next == NULL)
    {
        insert_tail(temp, x);
        return;
    }

    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    Node *nodeInsert = new Node(x);

    nodeInsert->next = temp->next;

    temp->next = nodeInsert;
}


void delete_head(Node* &head, Node* &tail)
{
    Node *temp = head;
    head = head->next;
    free(temp);
}

void delete_end(Node* &head, Node* &tail){
    Node* temp = tail;
    Node* t = temp->next;
    t = t->previous;
    free(t);
    
    //cout<<t->data<<endl;



}


void Print(Node* &head,Node* &tail){
    Node* temp = head;
    //cout << "Head="<<head->data<<", Tail="<<tail->data<<", ";
    while (temp != nullptr)
    {
        if(temp->data == -1){
            temp = temp->next;
            continue;
        }
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
    insertPosition(head,tail,3,1000);
    insertPosition(head,tail,3,2000);
    delete_head(head,tail);
    delete_end(head,tail);

    

    Print(head,tail);
    cout<<endl;
    cout<<getSize(head)<<endl;
    // Node* node1 = new Node();
    // Node *head = node1;
    // Node *tail = node1;
    // int f_id;
    // if(f_id == 1){
    //     int x;
    //     cin >> x;
    //     insert_head(head,x);
    // }

    // Print(head,tail);








}