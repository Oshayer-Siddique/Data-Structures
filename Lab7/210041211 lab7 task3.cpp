#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};
Node *root = NULL;

Node* createNode(int x){
    Node *newnode = new Node();
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;
    return newnode;
}

int find_height(Node* x){
    if(x==NULL) return -1;
    int left_h = find_height(x->left);
    int right_h = find_height(x->right);
    return max(left_h, right_h) + 1;
}

void printTree(Node *x, int par){
    if(x==NULL) return;
    if(par==0) cout << x->data<<"(N)"<<" ";
    else cout << x->data<<"("<<par<<")"<<" ";
    printTree(x->left, x->data);
    printTree(x->right, x->data);
}

Node* Search(int val, Node* x){
    if(x==NULL) return x;
    if(x->data == val) return x;
    Node *temp;
    temp = Search(val, x->left);
    if(temp != NULL) return temp;
    temp = Search(val, x->right);
    if(temp != NULL) return temp;
    return NULL;
}

void Remove(int val){
    queue<Node*> Q;
    Q.push(root);
    bool found = false;
    Node *temp;
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        if(temp->data == val){
            found = true;
            break;
        }
        if(temp->left != NULL){
            Q.push(temp->left);
        }
        if(temp->right != NULL){
            Q.push(temp->right);
        }
    }
    if(!found){
        cout << "Not found" << endl;
        return;
    }
    if(temp->parent){
        if(temp->parent->left == temp) temp->parent->left = NULL;
        else temp->parent->right = NULL;
    }
    else{
        root = NULL;
    }
    while(Q.size()) Q.pop();
    Q.push(temp);
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        if(temp->left != NULL){
            Q.push(temp->left);
        }
        if(temp->right != NULL){
            Q.push(temp->right);
        }
        free(temp);
    }
    printTree(root, 0);
    cout << "(preorder)" <<endl;
}


int main(){
    int N;
    int inp, param1;
    Node* x;
    cin >> N;
    for(int i=0; i<N; i++){
        int val, par, childtype;
        queue<Node*> Q;
        cin >> val >> par >> childtype;
        Node *child = createNode(val);
        if(par==0) {
            root = child;
        }
        else{
            //Traverse tree using Queue
            Q.push(root);
            while(!Q.empty()){
                Node *temp = Q.front();
                Q.pop();
                if(temp->data == par){
                    if(childtype==1){
                        temp->left = child;
                    }
                    else{
                        temp->right = child;
                    }
                    child->parent = temp;
                    break;
                }
                if(temp->left != NULL){
                    Q.push(temp->left);
                }
                if(temp->right != NULL){
                    Q.push(temp->right);
                }
            }
        }
    }
    printTree(root, 0);
    cout << "(preorder)" <<endl;
    while(true){
        cin >> inp;
        if(inp == 0) break;
        switch(inp){
        case 2:
            cin >> param1;
            Remove(param1);
            break;
        case 3:
            cin >> param1;
            x = Search(param1, root);
            if(x==NULL) cout<<"Not present";
            else{
                cout<<"Present, ";
                cout<<"Left(";
                if(x->left) cout<<x->left->data;
                else cout<<"null";
                cout<<"), Right(";
                if(x->right) cout<<x->right->data;
                else cout<<"null";
                cout<<")";
            }
            cout<<endl;
            break;
        case 4:
            cout << find_height(root) << endl;
            break;
        }
    }
    return 0;
}


