#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
};

Node* root = NULL;

void LevelOrderPrint(){
    queue<Node*> Q;
    Q.push(root);
    while(Q.size()){
        Node *temp = Q.front();
        cout << temp->data << " ";
        if(temp->left) Q.push(temp->left);
        if(temp->right) Q.push(temp->right);
        Q.pop();
    }
    cout << endl;
}

Node* createNode(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}

Node* bst_insert(int val)
{
    Node *x = createNode(val);
    Node *temp = root;
    Node *target;
    if(temp == NULL) root = x;
    else
    {
        while(temp != NULL)
        {
            target = temp;
            if(x->data < temp->data) temp = temp->left;
            else temp = temp->right;
        }
        x->parent = target;
        if(x->data<target->data) target->left = x;
        else target->right = x;
    }
    return x;
}

Node* Search(int val)
{
    Node* temp = root;
    while(temp->data != val)
    {
        if(temp->data < val)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return temp;
}


Node* tree_minimum(Node *x)
{
    while(x->left != NULL)
    {
        x = x->left;
    }
    return x;
}

Node* tree_maximum(Node *x)
{
    while(x->right != NULL)
    {
        x = x->right;
    }
    return x;
}
Node* Successor(Node *x)
{
    if(x == tree_maximum(root))
    {
        return NULL;
    }
    else if(x->right != NULL)
        return tree_minimum(x->right);
    else
    {
        Node *xp = x->parent;
        while(xp->data < x->data)
            xp = xp->parent;
        return xp;
    }
}

void DeleteNode(int val){
    Node* z = Search(val);
    if(z->left == NULL && z->right == NULL){
        if(z->parent != NULL){
            Node *zp = z->parent;
            if(z==zp->left) zp->left = NULL;
            else zp->right = NULL;
            free(z);
        }
        else{
            root = NULL;
            free(z);
        }
    }
    else if(z->left == NULL || z->right == NULL){
        if(z==root){
            if(z->left){
                root = z->left;
            }
            else{
                root = z->right;
            }
            root->parent = NULL;
            free(z);
            return;
        }
        Node *zp = z->parent;
        if(z==zp->right){
            if(z->right){
                zp->right = z->right;
                z->right->parent = zp;
                free(z);
            }
            else{
                zp->right = z->left;
                z->left->parent = zp;
                free(z);
            }
        }
        else{
            if(z->right){
                zp->left = z->right;
                z->right->parent = zp;
                free(z);
            }
            else{
                zp->left = z->left;
                z->left->parent = zp;
                free(z);
            }
        }
    }
    else{
        Node *z_succ = Successor(z);
        if(z==root){
            z_succ->left = z->left;
            root = z->right;
            root->parent = NULL;
            free(z);
        }
        else{
            Node *zp = z->parent;
            if(z==zp->right)
                zp->right = z->right;
            else
                zp->left = z->right;
            z->right->parent = zp;
            z_succ->left = z->left;
            z->left->parent = z_succ;
            free(z);
        }
    }
}

int main()
{
    int n;
    while(true)
    {
        cin >> n;
        if(n==-1) break;
        bst_insert(n);
    }
    LevelOrderPrint();
    cin>>n;
    while(n--)
    {
        int val;
        cin>>val;
        DeleteNode(val);
        LevelOrderPrint();
    }
    return 0;
}
