#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
};

Node* root = NULL;

Node* createNode(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}

void bst_insert(int val)
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
    //Keep going from root to both elements. Remove overlaps to get continuous path
    cin >> n;
    while(n--){
        int a, b, i=0, Max, start = 0;
        vector<int> List1, List2;
        cin >> a >> b;

        Node* temp = root;
        while(true){
            List1.push_back(temp->data);
            if(temp->data == a) break;
            if(temp->data > a) temp =  temp->left;
            else temp = temp->right;
        }
        temp = root;
        while(true){
            List2.push_back(temp->data);
            if(temp->data == b) break;
            if(temp->data > b) temp =  temp->left;
            else temp = temp->right;
        }
        i = 0;
        while(List1[i] == List2[i]){
            if(List1[i+1] == List2[i+1]){
                List1[i] = -1;
                List2[i] = -1;
            }
            i++;
        }

        /*for(i=0;i<List1.size();i++){
            cout << List1[i] << " ";
        }
        cout<<endl;
        for(i=0;i<List2.size();i++){
            cout << List2[i] << " ";
        }
        cout<<endl;*/
        Max = List1[0];
        for(i=1;i<List1.size();i++){
            if(List1[i] > Max) Max = List1[i];
        }
        for(i=0;i<List2.size();i++){
            if(List2[i] > Max) Max = List2[i];
        }
        cout << Max << endl;
    }

    return 0;
}


/*

50 75 25 29 45 60 10 80 12 -1
8
10 50
25 45
60 80
25 60
12 25
10 60
50 60
75 80


*/