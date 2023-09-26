#include <iostream>

using namespace std;

class Node{
    public:
        int val;
        Node * left;
        Node * right;
        Node * parent;

    Node(int val = 0){
        this->val = val;
        left = nullptr;
        right = nullptr;
        parent = nullptr;

    }


};


class Tree{
    public:
        Node * root;
        Tree(int val_root);
        void insert(int val);
        void display(Node * root);

};


Tree::Tree(int val_root){
    root = new Node(val_root);
}

void Tree::insert(int val){
    Node * new_node;
    new_node = new Node(val);
    Node * temp = root;
    if(root == nullptr){
        root = new_node;
    }
    else{
        while (1)
        {
            if(val > temp->val){
                if(temp->right != nullptr){
                    temp = temp->right;

                }
                else{
                    temp->right = new_node;
                    new_node->parent = temp;
                    break;
                }
                
            }
            else{
                if(temp->left != nullptr){
                    temp = temp->left;

                }
                else{
                    temp->left = new_node;
                    new_node->parent = temp;
                    break;
                }

            }
        }
        

    }






}

void Tree::display(Node * root){
    if(root == nullptr){
        return;
    }
    else{
        display(root->left);
        cout<<root->val<<" ";
        display(root->right);
    }
}


int main(){
    Tree T(10);
    T.insert(10);
    T.insert(10);
    T.insert(110);
    T.insert(10);
    
    T.display(T.root);
}


