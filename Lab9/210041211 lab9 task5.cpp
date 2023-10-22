#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int number;
    Node *parent;
    Node *leftchild;
    Node *rightchild;
    int height;

    Node() : parent(nullptr), leftchild(nullptr), rightchild(nullptr), height(0) {}
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree() : root(nullptr) {}

    void insert_in_binary_search_tree(Node *temp, int value);
    Node * search_by_binary_search_tree(Node * temp, int value);
    void in_order_traversal(Node *current);
    int print_left_path_and_get_path_distance(Node * current, int data);
    int print_right_path_and_get_path_distance(Node * current, int data);
};

int main()
{
    BinaryTree bst;
    int total_node, total_query;
    cin >> total_node;
    while(total_node--)
    {
        int data;
        cin >> data;
        bst.insert_in_binary_search_tree(bst.root,data);
    }
    cout << "Status: ";
    bst.in_order_traversal(bst.root);
    cout << endl;
    while(1)
    {
        int query_a, query_b;
        cin >> query_a >> query_b;
        if(query_a == 0 && query_b == 0)
            break;

        Node * temp = bst.root;
        while(1)
        {
            if( (query_a < temp->number && query_b > temp->number) )
            {
                int len = bst.print_left_path_and_get_path_distance(temp,query_a);
                int lenr = bst.print_right_path_and_get_path_distance(temp,query_b);
                cout << endl << len+lenr << endl;
                break;
            }
            else if(query_a == temp->number)
            {
                cout << temp->number << ' ';
                int len = bst.print_right_path_and_get_path_distance(temp,query_b);
                cout << endl << len+1 << endl;
                break;
            }
            else if(query_b == temp->number)
            {
                int len = bst.print_left_path_and_get_path_distance(temp,query_a);
                cout << endl << len << endl;
                break;
            }
            else if(query_a > temp->number && query_b > temp->number)
            {
                temp = temp->rightchild;
            }
            else if(query_a < temp->number && query_b < temp->number)
            {
                temp = temp->leftchild;
            }
        }
    }
}

void BinaryTree::insert_in_binary_search_tree(Node *temp, int value)
{
    Node *newNode = new Node();
    newNode->number = value;
    if (temp == nullptr)
    {
        root = newNode;
        newNode->height = 0;
    }
    else
    {
        while (1)
        {
            if (temp->number > value)
            {
                if (temp->leftchild == nullptr)
                {
                    temp->leftchild = newNode;
                    newNode->parent = temp;
                    temp = newNode;
                    for (int i = 0;; i++)
                    {
                        temp->height = max(i, temp->height);
                        if (temp->parent == nullptr)
                            break;
                        else
                            temp = temp->parent;
                    }
                    break;
                }
                else
                    temp = temp->leftchild;
            }
            else
            {
                if (temp->rightchild == nullptr)
                {
                    temp->rightchild = newNode;
                    newNode->parent = temp;
                    temp = newNode;
                    for (int i = 0;; i++)
                    {
                        temp->height = max(i, temp->height);
                        if (temp->parent == nullptr)
                            break;
                        else
                            temp = temp->parent;
                    }
                    break;
                }
                else
                    temp = temp->rightchild;
            }
        }
    }
}

Node *BinaryTree::search_by_binary_search_tree(Node *temp, int value)
{
    while (temp != nullptr && temp->number != value)
    {
        if (temp->number > value)
        {
            temp = temp->leftchild;
        }
        else
        {
            temp = temp->rightchild;
        }
    }
    return temp;
}

void BinaryTree::in_order_traversal(Node *current)
{
    if (current == nullptr)
        return;

    in_order_traversal(current->leftchild);

    cout << current->number;
    cout << "(" << current->height << ") ";

    in_order_traversal(current->rightchild);
}

int BinaryTree::print_left_path_and_get_path_distance(Node* current, int data) 
{
    stack<int>left_path;
    while(current->number != data)
    {
        if(current->number > data)
        {
            left_path.push(current->number);
            current = current->leftchild;
        }
        else if(current->number < data)
        {
            left_path.push(current->number);
            current = current->rightchild;
        }
    }
    left_path.push(current->number);
    int total = left_path.size();
    while(!left_path.empty())
    {
        cout << left_path.top() << ' ';
        left_path.pop();
    }
    return total;
}

int BinaryTree::print_right_path_and_get_path_distance(Node* current, int data) 
{
    int total = 1;
    if(current->number > data)
        current = current->leftchild;
    else
        current = current->rightchild;
    while(current->number != data)
    {
        if(current->number > data)
        {
            total++;
            cout << current->number << ' ';
            current = current->leftchild;
        }
        else if(current->number < data)
        {
            total++;
            cout << current->number << ' ';
            current = current->rightchild;
        }
    }
    cout << current->number;
    return total;
}