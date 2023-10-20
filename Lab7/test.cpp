#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};
Node *head = NULL, *tail = NULL;

Node* createNode(int x){
    Node *newnode = new Node();
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void PrintList(){
    cout << ">>> ";
    Node *temp = head;
    if(head==NULL) cout << "Head=Null, Tail=Null, Empty";
    else {
        cout << "Head="<<head->data<<", Tail="<<tail->data<<", ";
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}

void Insert_front(int key){
    Node *newnode = createNode(key);
    if(head==NULL){
        head = newnode;
        tail = newnode;
    }
    else{
        newnode -> next = head;
        head = newnode;
    }
}

void Insert_back(int key){
    Node *newnode = createNode(key);
    if(tail==NULL){
        head = newnode;
        tail = newnode;
    }
    else{
        tail->next = newnode;
        tail = newnode;
    }
}

void Insert_after_node (int key,  int v){
    if(head != NULL){
        Node *temp = head;
        while(temp && temp->data != v){
            temp = temp->next;
        }
        if(temp!=NULL){
            if(temp==tail) Insert_back(key);
            else{
                Node *temp2 = createNode(key);
                temp2->next = temp->next;
                temp->next = temp2;
            }
            return;
        }
    }
    cout << "Value Not found" <<endl;
}

void Update_node (int key, int v){
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

void Remove_head (){
    if(head !=NULL){
        Node *temp = head;
        head = head->next;
        free(temp);
        if(head==NULL) tail = NULL;
    }
    else{
        cout << "Underflow" << endl;
    }
}

void Remove_element (int key){
    if(head != NULL) {
        Node *temp = head;
        if(temp->data == key){
            Remove_head();
            //cout << "Off with the head!"<<endl;
            return;
        }
        else {
            while(temp->next && temp->next->data != key){
                temp = temp->next;
            }
            if(temp->next==NULL){
                cout << "Value Not found" <<endl;
                return;
            }
            Node *t2 = temp->next;
            temp->next = temp->next->next;
            if(t2 == tail) tail = temp;
            free(t2);
        }
    }
    else cout << "Value Not found" <<endl;
}

void Remove_end (){
    Node *temp = head;
    if(head == NULL){
        cout << "Underflow" << endl;
        return;
    }
    if(temp->next == NULL){
        Remove_head();
    }
    else{
        while(temp->next->next != NULL)
            temp = temp->next;

        //free(temp->next);
        Node *t2 = tail;
        temp->next = NULL;
        tail = temp;
        free(t2);
    }
}

int main(){
    int inp, param1, param2;
    while(true){
        cin >> inp;
        if(inp == 0) break;
        switch(inp){
        case 1:
            cin >> param1;
            Insert_front(param1);
            break;
        case 2:
            cin >> param1;
            Insert_back(param1);
            break;
        case 3:
            cin >> param1 >> param2;
            Insert_after_node(param1, param2);
            break;
        case 4:
            cin >> param1 >> param2;
            Update_node(param1, param2);
            break;
        case 5:
            Remove_head();
            break;
        case 6:
            cin >> param1;
            Remove_element(param1);
            break;
        case 7:
            Remove_end();
            break;
        }
        PrintList();
    }
    return 0;
}