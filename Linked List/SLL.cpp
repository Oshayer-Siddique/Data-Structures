#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;




//constructor
    Node(int x){
        this->data = x;
        this->next = NULL;
    }
};


void insertHead(Node* &head,int x){
    Node* temp = new Node(x);
    temp->next = head;
    head = temp;

}


void InsertTail(Node* &tail,int x){
    Node* temp = new Node(x);
    tail->next = temp;
    tail = tail->next;

}


void insertPosition(Node* &head,Node* &tail,int pos,int x){
    Node* temp = head;
    int cnt = 1;

    if(pos == 1){
        insertHead(head,x);
        return;
    }

    if(temp->next == NULL){
        InsertTail(temp,x);
        return;
    }

    while (cnt < pos-1)
    {
        temp = temp->next;
        cnt++;
    }
    Node* nodeInsert = new Node(x);


    nodeInsert -> next = temp->next;

    temp->next = nodeInsert;

}

void delete_head(Node* &head,Node* &tail){
    Node* temp = head;
    head = head->next;
    free(temp);

}

void delete_end(Node* &head,Node* &tail){
    Node* temp = head;
    if(temp->next == NULL){
        free(temp);
        return;
    }
    else{

    

    
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node* t = tail;
        temp->next = NULL;
        tail = temp;
        free(t);
        //cout << "Called 2"<<endl;
        
    


    }

}


void delete_element(Node* &head,Node* &tail,int x){
    Node* temp = head;
    if(temp->data == x){
        free(temp);
        return;

    }
    else{
        while (temp->next && temp->next->data != x)
        {
            temp = temp->next;
        }
        if(temp->next == NULL){
            cout<<"Value Not Found"<<endl;
            return;
        }
        else{
            Node* t = temp->next;
            temp->next = temp->next->next;
            
            if(t == tail) tail = temp;
            free(t);
        }
        
        
    }

}

void Update_node (Node*head,int key, int v){
    if(head != NULL){
        Node *temp = head;
        while(temp && temp->data != v){
            temp = temp->next;
        }
        if(temp!=NULL){
            temp->data = key;
            return;
        }
    }
    cout << "Value Not found" <<endl;
}





void print(Node* &head){
    Node* temp = head;
    while (temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    




}




int main(){
    Node* node1 = new Node(45);
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;
    Node* head = node1;
    Node* tail = node1;
    insertHead(head,100);
    insertHead(head,300);
    InsertTail(tail,200);
    insertPosition(head,tail,2,22);
    insertPosition(head,tail,1,400);
    delete_head(head,tail);
    delete_head(head,tail);
    delete_end(head,tail);
    delete_element(head,tail,45);
    insertHead(head,100);
    insertHead(head,300);
    Update_node(head,-100,100);
    

    
    
    print(head);


}