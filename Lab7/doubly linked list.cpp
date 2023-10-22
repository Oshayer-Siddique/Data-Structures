#include <iostream>

using namespace std;


class Node{
    public:
        int data;
        Node * next;
        Node * previous;

        Node(int data){
            this->data = data;
            this->next = nullptr;
            this->previous = previous;

        }

};


class LinkedList{
    public:
        Node * head;
        Node * tail;

    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }


    void insert_front(int val){
        Node *newNode = new Node(val);

        if(head == nullptr){
            head = tail = newNode;

        }
        else{
        newNode->next = head;
        head->previous = newNode;
        head = newNode;

        }


    }
    void insert_back(int val){
        Node *newNode = new Node(val);

        if(head == nullptr){
            head = tail = newNode;

        }
        else{
            newNode->previous = tail;
            tail->next = newNode;
            tail = newNode;
        }


        
    }

    void insert_after_node(int key, int val)
    {
        Node *newNode = new Node(val);

        Node *temp = head;

        int cnt = 1;

        if (key == 0)
        {
            insert_front(val);
        }
        
        else
        {

            while (cnt < key)
            {
                temp = temp->next;
                cnt++;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }


    void remove_head(){
        Node * temp = head;
        head = head->next;
        delete temp;
    }

    void remove_element(int val){
        Node * temp = head;

        if(head->data == val){
            Node *x = head;
            head = head->next;
            delete x;
            
            return;
        }

        

        while (temp->next != nullptr)
        {
            if(temp->next->data == val){
                Node * curr = temp->next;
                temp->next = temp->next->next;
                delete curr;
            }
            else{
                temp = temp->next;
            }
        }  

    }

    void update_node(int key,int val){
        Node * temp = head;


        while (temp)
        {
            if(temp->data == val){
                temp->data = key;
                return;
                

            }
            else{
                temp = temp->next;
            }

        }
        

    }

    void remove_end(){
        Node * temp = tail;
        tail = tail->previous;
        delete temp;
        tail->next = nullptr;
    }




    void display_head_tail()
    {

        Node *temp = head;
        cout << "Head = " << head->data << endl;
        cout << "Tail = " << tail->data << endl;
    }




    void display()
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout<<endl;
            
            
    }


    void display_rev(){
        Node * temp = tail;
        while (temp->previous->previous)
        {
            cout<<temp->data<<" ";
            temp = temp->previous;
        }

        cout<<endl;
        
    }
};


int main(){
    LinkedList dll;
    dll.insert_front(100);
    dll.insert_front(120);
    dll.insert_back(300);
    dll.insert_after_node(1,1000);
    dll.insert_after_node(0,-11);
    dll.remove_head();
    dll.remove_element(1000);
    dll.update_node(-100,120);
    dll.remove_end();
    dll.display_head_tail();
    dll.display();
    dll.display_rev();
}