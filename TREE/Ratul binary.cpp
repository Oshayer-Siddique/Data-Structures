#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int number;
    string line;
    double fraction;
    char character;
    Node *parent;
    Node *leftchild;
    Node *rightchild;

    Node() : parent(nullptr), leftchild(nullptr), rightchild(nullptr) {}
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree() : root(nullptr) {}

    void insert_in_binary_tree(int value, int parent, int child);

    void level_order_traversal(Node *current);
    Node *find_by_level_order_traversal(int data);
    void pre_order_traversal(Node *current);
    Node *find_by_pre_order_traversal(int data, Node *current);
    void in_order_traversal(Node *current);
    Node *find_by_in_order_traversal(int data, Node *current);
    void post_order_traversal(Node *current);
    Node *find_by_post_order_traversal(int data, Node *current);

    int find_height(Node *current);



    void insert_in_binary_search_tree(Node *temp, int value);
    void delete_from_binary_search_tree(int value);

    Node * search_by_binary_search_tree(Node * temp, int value);
    Node * minimum_value_in_binary_search_tree(Node * current);
    Node * maximum_value_in_binary_search_tree(Node * current);
    void sorting_using_binary_search_tree(Node * temp, vector<int>&sorted);
    Node * find_successor_from_binary_search_tree(Node * current);
    Node * find_predecessor_from_binary_search_tree(Node * current);
    

};

int main()
{
    // BinaryTree bst;
    // int total_node;
    // cin >> total_node;



    // while (total_node--)
    // {
    //     int val, par, cld;
    //     cin >> val >> par >> cld;
    //     bst.insert_in_binary_tree(val, par, cld);
    // }


    // while (total_node--)
    // {
    //     int num;
    //     cin >> num;
    //     bst.insert_in_binary_search_tree(bst.root, num);
    // }
}

void BinaryTree::insert_in_binary_tree(int value, int parent, int child)
{
    Node *newNode = new Node();
    newNode->number = value;

    if (parent == 0)
    {
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        else
        {
            cout << "Error: Root node already exists." << endl;
            delete newNode;
            return;
        }
    }

    queue<Node *> tree;
    tree.push(root);

    while (!tree.empty())
    {
        Node *current = tree.front();
        tree.pop();

        if (current->number == parent)
        {
            if (child == 1)
            {
                if (current->leftchild == nullptr)
                {
                    current->leftchild = newNode;
                    newNode->parent = current;
                    return;
                }
                else
                {
                    cout << "Error: Left child already exists for parent " << parent << endl;
                    delete newNode;
                    return;
                }
            }
            else if (child == 2)
            {
                if (current->rightchild == nullptr)
                {
                    current->rightchild = newNode;
                    newNode->parent = current;
                    return;
                }
                else
                {
                    cout << "Error: Right child already exists for parent " << parent << endl;
                    delete newNode;
                    return;
                }
            }
        }

        if (current->leftchild != nullptr)
            tree.push(current->leftchild);

        if (current->rightchild != nullptr)
            tree.push(current->rightchild);
    }

    cout << "Error: Parent " << parent << " not found in the tree." << endl;
    delete newNode;
}

void BinaryTree::pre_order_traversal(Node *current)
{
    if (current == nullptr)
        return;

    cout << current->number << endl;

    pre_order_traversal(current->leftchild);
    pre_order_traversal(current->rightchild);
}

Node *BinaryTree::find_by_pre_order_traversal(int data, Node *current)
{
    if (current == nullptr)
        return nullptr;

    if (current->number == data)
        return current;

    Node *foundNode = find_by_pre_order_traversal(data, current->leftchild);
    if (foundNode != nullptr)
        return foundNode;

    return find_by_pre_order_traversal(data, current->rightchild);
}

void BinaryTree::in_order_traversal(Node *current)
{
    if (current == nullptr)
        return;

    in_order_traversal(current->leftchild);

    cout << current->number << endl;

    in_order_traversal(current->rightchild);
}

Node *BinaryTree::find_by_in_order_traversal(int data, Node *current)
{
    if (current == nullptr)
        return nullptr;

    Node *foundNode = find_by_in_order_traversal(data, current->leftchild);
    if (foundNode != nullptr)
        return foundNode;

    if (current->number == data)
        return current;

    Node *foundNode2 = find_by_in_order_traversal(data, current->rightchild);
    if (foundNode2 != nullptr)
        return foundNode2;

    return nullptr;
}

void BinaryTree::post_order_traversal(Node *current)
{
    if (current == nullptr)
        return;

    post_order_traversal(current->leftchild);
    post_order_traversal(current->rightchild);

    cout << current->number << endl;
}

Node *BinaryTree::find_by_post_order_traversal(int data, Node *current)
{
    if (current == nullptr)
        return nullptr;

    Node *foundNode = find_by_post_order_traversal(data, current->leftchild);
    if (foundNode != nullptr)
        return foundNode;

    Node *foundNode2 = find_by_post_order_traversal(data, current->rightchild);
    if (foundNode2 != nullptr)
        return foundNode2;

    if (current->number == data)
        return current;

    return nullptr;
}

int BinaryTree::find_height(Node *current)
{
    if (current == nullptr)
        return -1;

    int left_child_height = find_height(current->leftchild) + 1;
    int right_child_height = find_height(current->rightchild) + 1;
    return max(left_child_height, right_child_height);
}

void BinaryTree::level_order_traversal(Node *current)
{
    if (current == nullptr)
        return;

    queue<Node *> tree;
    tree.push(current);

    while (!tree.empty())
    {
        Node *temp = tree.front();
        tree.pop();

        cout << temp->number << endl;

        if (temp->leftchild != nullptr)
            tree.push(temp->leftchild);

        if (temp->rightchild != nullptr)
            tree.push(temp->rightchild);
    }
}

Node *BinaryTree::find_by_level_order_traversal(int data)
{
    if (root == nullptr)
        return nullptr;

    queue<Node *> tree;
    tree.push(root);

    while (!tree.empty())
    {
        Node *temp = tree.front();
        tree.pop();

        if (temp->number == data)
            return temp;

        if (temp->leftchild != nullptr)
            tree.push(temp->leftchild);

        if (temp->rightchild != nullptr)
            tree.push(temp->rightchild);
    }

    return nullptr;
}

void BinaryTree::insert_in_binary_search_tree(Node *temp, int value)
{
    Node *newNode = new Node();
    newNode->number = value;
    if (temp == nullptr)
        root = newNode;
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
                    break;
                }
                else
                    temp = temp->rightchild;
            }
        }
    }
}

Node * BinaryTree::search_by_binary_search_tree(Node * temp, int value)
{
    while(temp != nullptr && temp->number != value)
    {
        if(temp->number > value)
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

Node * BinaryTree::minimum_value_in_binary_search_tree(Node * current)
{
    while(current->leftchild != nullptr)
    {
        current = current->leftchild;
    }
    return current;
}


Node * BinaryTree::maximum_value_in_binary_search_tree(Node * current)
{
    while(current->rightchild != nullptr)
    {
        current = current->rightchild;
    }
    return current;
}

void BinaryTree::sorting_using_binary_search_tree(Node * current, vector<int>& sorted)
{
    if (current == nullptr)
        return;

    sorting_using_binary_search_tree(current->leftchild, sorted);

    sorted.push_back(current->number);

    sorting_using_binary_search_tree(current->rightchild, sorted);
    
}

Node * BinaryTree::find_successor_from_binary_search_tree(Node * current)
{
    if (current == nullptr) {
        cout << "No Successor" << endl;
        return nullptr;
    }
    
    if (current->rightchild != nullptr) {
        return minimum_value_in_binary_search_tree(current->rightchild);
    }
    
    Node * current_parent = current->parent;
    while (current_parent != nullptr && current->number > current_parent->number) {
        current_parent = current_parent->parent;
    }
    
    if (current_parent == nullptr) {
        cout << "No Successor" << endl;
        return nullptr;
    }
    
    return current_parent;
}

Node * BinaryTree::find_predecessor_from_binary_search_tree(Node * current)
{
    if (current == nullptr) {
        cout << "No Predecessor" << endl;
        return nullptr;
    }
    
    if (current->leftchild != nullptr) {
        return maximum_value_in_binary_search_tree(current->leftchild);
    }
    
    Node * current_parent = current->parent;
    while (current_parent != nullptr && current->number < current_parent->number) {
        current_parent = current_parent->parent;
    }
    
    if (current_parent == nullptr) {
        cout << "No Predecessor" << endl;
        return nullptr;
    }
    
    return current_parent;
}


void BinaryTree::delete_from_binary_search_tree(int value)
{
    Node *target = search_by_binary_search_tree(root, value);
    if (target == nullptr)
    {
        cout << "Node doesn't exist" << endl;
        return;
    }

    Node *target_parent = target->parent;

    if (target->leftchild == nullptr && target->rightchild == nullptr)
    {
        if (target_parent == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (target_parent->leftchild == target)
        {
            target_parent->leftchild = nullptr;
            delete target;
        }
        else
        {
            target_parent->rightchild = nullptr;
            delete target;
        }
    }
    else if (target->leftchild == nullptr || target->rightchild == nullptr)
    {
        Node *child = (target->leftchild != nullptr) ? target->leftchild : target->rightchild;

        if (target_parent == nullptr)
        {
            delete root;
            root = child;
            child->parent = nullptr;
        }
        else if (target_parent->leftchild == target)
        {
            target_parent->leftchild = child;
            child->parent = target_parent;
            delete target;
        }
        else
        {
            target_parent->rightchild = child;
            child->parent = target_parent;
            delete target;
        }
    }
    else
    {
        Node * target_successor = find_successor_from_binary_search_tree(target);
            if(target->parent == nullptr)
            {
                target_successor->leftchild = target->leftchild;
                target->leftchild->parent = target_successor;
                target->rightchild->parent == nullptr;
                root = target->rightchild;
                delete target;
            }
            else if(target == target_parent->rightchild)
            {
                target_parent->rightchild = target->rightchild;
            }
            else
            {
                target_parent->leftchild = target->rightchild;
            }
            target->rightchild->parent = target_parent;
            target_successor->leftchild = target->leftchild;
            target->leftchild->parent = target_successor;
    }
}
