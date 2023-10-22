#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert_front(int val)
    {

        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insert_back(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
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



    void remove_end(){
        Node * temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
        


        
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

    void display_head_tail()
    {

        Node *temp = head;
        cout << "Head = " << head->data << endl;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        cout << "Tail = " << temp->data << endl;
    }

    void display()
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList sl;

    sl.insert_front(100);
    sl.insert_front(12);
    sl.insert_back(24);
    sl.insert_after_node(1, 3);
    sl.insert_after_node(0, 34);
    sl.insert_after_node(5,133);
    sl.remove_head();
    sl.remove_element(24);
    sl.remove_element(3);
    sl.remove_element(12);
    sl.remove_end();
    sl.update_node(-100,100);
    sl.display_head_tail();
    
    sl.display();
}