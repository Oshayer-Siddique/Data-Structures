#include<iostream>
#include<stack>
using namespace std;

struct Node
{
    int data, left_sub_tree;
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

        cout << temp->data << "(" << temp->left_sub_tree <<") ";
        temp = temp->right;
    }
}

Node* createNode(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->left_sub_tree = 0;
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
            if(x->data < temp->data){
                temp->left_sub_tree++;
                temp = temp->left;
            }
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
        cin >> n;
        if(n==-1) break;
        bst_insert(n);
    }

    cin>>n;
    while(n--){
        int stamp, ans = 0;
        Node* temp = root;
        cin >> stamp;
        while(temp->data != stamp){
            if(temp->data < stamp){
                ans += temp->left_sub_tree + 1;
                temp = temp->right;
            }
            else{
                temp = temp->left;
            }
        }
        ans += temp->left_sub_tree;
        cout << ans << endl;
    }
    return 0;
}
