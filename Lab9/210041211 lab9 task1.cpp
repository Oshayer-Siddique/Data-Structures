#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;
    Node *previous;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
        previous = nullptr;
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

    void insert(int ele)
    {
        if (root == nullptr)
        {
            root = new Node(ele);
            return;
        }
        Node *temp = root;
        while (1)
        {
            if (ele < temp->data)
            {
                if (temp->left == nullptr)
                {
                    temp->left = new Node(ele);
                    temp->left->previous = temp;
                    return;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if (ele > temp->data)
            {
                if (temp->right == nullptr)
                {
                    temp->right = new Node(ele);
                    temp->right->previous = temp;
                    return;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }

    void inorderprint()
    {
        inordertraversal(root);
    }

    void inordertraversal(Node *root)
    {
        if (root != nullptr)
        {
            inordertraversal(root->left);
            cout << root->data << " ";
            inordertraversal(root->right);
        }
    }

    void searchbst(int val)
    {
        if (search(val, root) == nullptr)
        {
            cout << "Not Present" << endl;
        }
        else
        {
            cout << "Present" << endl;

            if (search(val, root)->left == nullptr)
            {
                cout << "Left = "
                     << "null"<<endl;
            }
            else
            {
                cout << "Left = " << search(val, root)->left->data << endl;
            }
            // cout<<"Left = "<<search(val,root)->left->data<<endl;
            if (search(val, root)->right == nullptr)
            {
                cout << "Right = "
                     << "null"<<endl;
            }
            else
            {
                cout << "Right = " << search(val, root)->right->data << endl;
            }

            if(search(val,root)->previous == nullptr){
                cout<<"ROOT NODE"<<endl;
            }
            else{
                cout<<"Parent = "<<search(val,root)->previous->data<<endl;

            }

            

        
        }
    }

    Node *search(int x, Node *root)
    {
        while (root != nullptr && root->data != x)
        {
            if (x < root->data)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return root;
    }

    void findH(int val){

        cout<<find_h_root(root) - find_heightrecursive(val,root)<<" = Height"<<endl;

    }





    int find_heightrecursive(int x,Node * root){
        if(root == nullptr){
            return -1;
        }
        if(x == root->data){
            return 0;

        }
        if(x < root->data){
            int L_H = find_heightrecursive(x,root->left);
            if(L_H != -1){
                return 1+ L_H;
            }
        }
        else{
            
            int R_H = find_heightrecursive(x,root->right);
            if(R_H != -1){
                return 1 + R_H;
            }

        }

        


    }


    int find_h_root(Node * root){
        if(root == nullptr){
            return - 1;
        }
        else{
            int l = find_h_root(root->left);
            int h = find_h_root(root->right);
            return max(l,h) + 1;
        }

    }



};

int main()
{

    BST bst;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        bst.insert(x);
    }
    bst.inorderprint();
    cout << endl;

    // bst.searchbst(125);
    // bst.searchbst(100);
    // bst.searchbst(140);
    // bst.findH(100);
    // bst.findH(50);
    // bst.findH(135);
    while (1)
    {
        int fid;
        cin >> fid;
        if(fid == 3){
            int a;
            cin >> a;
            bst.searchbst(a);

        }
        else if(fid == 4){
            int b;
            cin >> b;
            bst.findH(b);
        }
        else{
            break;
        }
    }
    
}