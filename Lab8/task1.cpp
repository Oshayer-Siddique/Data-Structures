#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *parent;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
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

    void BST_INSERT(int val)
    {
        root = bst_insert(root, val);
    }

    void inorderprint()
    {
        inordertraversal(root);
    }

    bool SEARCH(int val)
    {
        if (search_bst(root, val) == nullptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    int minimum()
    {
        return minimum_recur(root)->data;
    }

    int maximum()
    {

        return maximum_recur(root)->data;
    }

    Node *successor(Node *temp)
    {
        if (temp == maximum_recur(root))
        {
            return nullptr;
        }
        else if (temp->right != nullptr)
        {
            return minimum_recur(temp->right);
        }
        else
        {
            Node *xp;
            xp = temp->parent;
            while (xp->data < temp->data)
            {
                xp = xp->parent;
                return xp;
            }
        }
    }



    Node * predecessor(Node * temp){
        if(temp == minimum_recur(root)){
            return nullptr;
        }
        else if(temp->left != nullptr){
            return maximum_recur(temp->left);

        }
        else{
            Node * xp;
            xp = temp->parent;
            while (xp->data > temp->data)
            {
                xp = xp->parent;
                return xp;
            }
            

        }

    }

    Node *minimum_recur(Node *temp)
    {

        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp;
    }

    Node *maximum_recur(Node *temp)
    {
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }

        return temp;
    }

    Node *search_bst(Node *temp, int val)
    {
        if (temp->data != val)
        {
            return nullptr;
        }

        if (temp->data == val)
        {
            return temp;
        }
        else if (val < temp->data)
        {
            temp = search_bst(temp, val);
        }
        else
        {
            temp = search_bst(temp, val);
        }
        return temp;
    }

    Node *bst_insert(Node *temp, int ele)
    {
        if (temp == nullptr)
        {
            return new Node(ele);
        }

        if (ele < temp->data)
        {
            temp->left = bst_insert(temp->left, ele);
            temp->left->parent = temp;
        }
        else
        {
            temp->right = bst_insert(temp->right, ele);
            temp->right->parent = temp;
        }

        return temp;
    }

    void inordertraversal(Node *root)
    {
        if (root != nullptr)
        {
            inordertraversal(root->left);
            if (root->parent == nullptr)
            {
                cout << root->data << "(null)"
                     << " ";
            }
            else
            {
                cout << root->data << "(" << root->parent->data << ")"
                     << " ";
            }

            inordertraversal(root->right);
        }
    }
};

int main()
{

    // BST A;
    // A.BST_INSERT(11);
    // A.BST_INSERT(123);
    // A.BST_INSERT(0);
    // A.BST_INSERT(-12);
    // A.BST_INSERT(100);
    // A.inorderprint();

    // cout << endl;

    // A.SEARCH(11);
    // A.SEARCH(445);

    // cout << A.maximum();
    // cout << endl;
    // cout << A.minimum();

    BST A;

    int n;
    while (1)
    {
        /* code */
        Node *temp, *smalller, *larger;
        cin >> n;
        if(n == -1){
            break;
        }
        
        
    }
    


}
