#include <iostream>
#include<queue>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *parent;

    Node(int val = 0)
    {
        this->val = val;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class Tree
{
public:
    Node *root;

    Tree(int val_root){
        root = new Node(val_root);
    }

    void insert(int val);
    void inordertraversal(Node * root);
    void preordertraversal(Node * root);
    void postordertraversal(Node * root);
    int findmax(Node * root);
    int findmin(Node * root);
    void level_order_traversal(Node * root);
    int find_height(Node * root);




};

void Tree::insert(int val)
{
    Node *new_node;
    new_node = new Node(val);
    Node *temp = root;
    if (root == nullptr)
    {
        root = new_node;
    }
    else
    {
        while (1)
        {
            if (val > temp->val)
            {
                if (temp->right != nullptr)
                {
                    temp = temp->right;
                }
                else
                {
                    temp->right = new_node;
                    new_node->parent = temp;
                    break;
                }
            }
            else
            {
                if (temp->left != nullptr)
                {
                    temp = temp->left;
                }
                else
                {
                    temp->left = new_node;
                    new_node->parent = temp;
                    break;
                }
            }
        }
    }
}


void Tree::inordertraversal(Node * root){
    if(root == nullptr){
        return;
    }
    else{
        inordertraversal(root->left);

        cout<<root->val<<" ";

        inordertraversal(root->right);

    }
}

void Tree::preordertraversal(Node * root){
    if(root == nullptr){
        return;
    }
    else{
        

        cout<<root->val<<" ";

        preordertraversal(root->left);

        preordertraversal(root->right);
        
    }
}


void Tree::postordertraversal(Node * root){
    if(root == nullptr){
        return;
    }
    else{
        postordertraversal(root->left);

        postordertraversal(root->right);

        cout<<root->val<<" ";

        
        
    }
}


int  Tree::findmax(Node * root){
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root->val;
    
}


int Tree::findmin(Node * root){
    while (root->left != nullptr)
    {
        root = root->left;

    }
    return root->val;
    
}

void Tree::level_order_traversal(Node * root){
    queue<Node * > q;
    q.push(root);
    while (!q.empty())
    {
        Node * temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left != nullptr){
            q.push(temp->left);
        }
        if(temp -> right){
            q.push(temp->right);
            
        }

    }
    

}


int Tree::find_height(Node * root){
    if(root == nullptr){
        return -1;
    }
    else{
        int L = find_height(root->left);
        int R = find_height(root->right);
        return max(L,R) + 1;
    }

}




int main(){
    Tree T(10);
    T.insert(1);
    T.insert(11);
    T.insert(120);
    T.insert(30);
    T.inordertraversal(T.root);

    cout<<endl;

    cout<<"Max = "<<T.findmax(T.root)<<endl;

    

    cout<<"Min = "<<T.findmin(T.root)<<endl;

    T.level_order_traversal(T.root);

    cout<<endl;

    cout<<"Height  = "<<T.find_height(T.root)<<endl;

    
    
    
}
