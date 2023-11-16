#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *parent;
    int height;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        height = 0;
    }
};

class BST
{

public:
    Node *root;
    BST()
    {
        root = nullptr;
    }

    void print_inorder()
    {
        inordertraversal(root);
    }

    void inordertraversal(Node *curr)
    {
        if (curr != nullptr)
        {
            inordertraversal(curr->left);
            // cout<<curr->data<<""<<"("<<find_height(curr->left)<<","<<find_height(curr->right)<<")"<<" ";
            // cout<<endl;
            cout << curr->data << "(" << find_height(curr->left) - find_height(curr->right) << ")"
                 << " ";
            inordertraversal(curr->right);
        }
    }

    int find_height(Node *curr)
    {
        if (curr == nullptr)
        {
            return 0;
        }
        else
        {
            int L_H = find_height(curr->left);
            int R_H = find_height(curr->right);
            return max(L_H, R_H) + 1;
        }
    }

    void insert(int val)
    {

        if (root == nullptr)
        {
            root = new Node(val);
            return;
        }
        Node *temp = root;
        while (1)
        {
            if (val < temp->data)
            {
                if (temp->left == nullptr)
                {
                    temp->left = new Node(val);
                    temp->left->parent = temp;
                    return;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if (val > temp->data)
            {
                if (temp->right == nullptr)
                {
                    temp->right = new Node(val);
                    temp->right->parent = temp;
                    return;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
};

int main()
{
    BST A;


    while (1)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            break;
        }
        else{

        
        A.insert(x);
        A.print_inorder();

        }
        

    }

}