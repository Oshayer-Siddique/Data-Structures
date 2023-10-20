#include<iostream>
#include<stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
};

Node* root = NULL;

void inorderPrint(Node *temp)
{
    stack<Node*> s;
    while (temp != NULL || !s.empty())
    {
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();

        cout << temp->data << " ";
        temp = temp->right;
    }
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
Node* Predecessor(Node *x)
{
    if(x == tree_minimum(root))
    {
        return NULL;
    }
    else if(x->left != NULL)
        return tree_maximum(x->left);
    else
    {
        Node *xp = x->parent;
        while(xp->data > x->data)
            xp = xp->parent;
        return xp;
    }
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
int main()
{
    int n;
    while(true)
    {
        Node *temp, *smaller, *bigger;
        cin >> n;
        if(n==-1) break;
        temp = bst_insert(n);
        smaller = Predecessor(temp);
        bigger = Successor(temp);
        //if(bigger) cout << " B=" <<bigger->data;
        //if(smaller) cout << " S=" <<smaller->data;
        //cout << endl;
        if((bigger && bigger->data - temp->data <=3) || (smaller && temp->data - smaller->data <= 3))
        {
            if(temp->data < temp->parent->data) temp->parent->left = NULL;
            else temp->parent->right = NULL;
            free(temp);
            inorderPrint(root);
            cout << "(Reservation failed)" << endl;
        }
        else
        {
            inorderPrint(root);
            cout << endl;
        }
    }
    return 0;
}