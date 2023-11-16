#include<iostream>
#include<vector>


using namespace std;


const int N = 1e5 + 2;

vector<int> arr(N,1000);
vector<int>tree(4 * N,1000);


void build_sum(int node ,int st,int end){

    if(st == end){
        tree[node] = arr[st];
        return;
    }
    else{
        int mid = (st + end) / 2;
        build_sum(2*node,st,mid);
        build_sum(2*node+1,mid+1,end);

        tree[node] = tree[2*node] + tree[2*node + 1];


    }


}


int sum_query(int node, int st, int end,int left,int  right){
    if(st > right || end < left){
        return 0;

    }
    if ( left <= st && end <= right)
    {
        return tree[node];
    }
    else{
        int mid = (st + end)/2;
        int x = sum_query(2*node,st,mid,left,right);
        int y = sum_query(2*node+1,mid+1,end,left,right);
        return x + y;

        
    }
    




}


void build_max(int node ,int st,int end){

    if(st == end){
        tree[node] = arr[st];
        return;
    }
    else{
        int mid = (st + end) / 2;
        build_max(2*node,st,mid);
        build_max(2*node+1,mid+1,end);

        tree[node] = max(tree[2*node] , tree[2*node + 1]);


    }


}


int max_query(int node, int st, int end,int left,int  right){
    if(st > right || end < left){
        return 0;

    }
    if ( left <= st && end <= right)
    {
        return tree[node];
    }
    else{
        int mid = (st + end)/2;
        int x = max_query(2*node,st,mid,left,right);
        int y = max_query(2*node+1,mid+1,end,left,right);
        return max(x,y);

        
    }
    




}



void build_min(int node, int st, int end)
{

    if (st == end)
    {
        tree[node] = arr[st];
        return;
    }
    else
    {
        int mid = (st + end) / 2;
        build_min(2 * node, st, mid);
        build_min(2 * node + 1, mid + 1, end);

        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

int min_query(int node, int st, int end, int left, int right)
{
    if (st > right || end < left)
    {
        return 10000000;
    }
    if (left <= st && end <= right)
    {
        return tree[node];
    }
    else
    {
        int mid = (st + end) / 2;
        int x = min_query(2 * node, st, mid, left, right);
        int y = min_query(2 * node + 1, mid + 1, end, left, right);
        return min(x, y);
    }
}


void update(int node,int st,int end, int idx,int val){
    if(st == end){
        arr[st] = val;
        tree[node] = val;
        return;
    }
    else{
        int mid  = (st + end) / 2;
        if(idx <= mid){
            update(2*node,st,mid,idx,val);

        }
        else{
            update(2*node+1,mid+1,end,idx,val);

        }
        tree[node] = max(tree[2*node] , tree[2*node + 1]);
    }
}





int main(){

    int n ;
    cin >> n;

    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    // build_sum(1,0,n-1);
    // cout<<tree[1]<<endl;
    // int ans = sum_query(1,0,n-1,1,5);

    // cout<<ans<<endl;




    // for(int i = 1;i <= 15;i++){
    //     cout<<tree[i]<<endl;
    // }


    // build_max(1,0,n-1);

    // int ans = max_query(1,0,n-1,1,5);

    // cout<<ans<<endl;

    // build_max(1,0,n-1);
    // update(1,0,n-1,1,100);

    // cout<<max_query(1,0,n-1,0,n-1)<<endl;

    build_min(1,0,n-1);

    
    for(int i = 1;i <= 15;i++){
        cout<<tree[i]<<endl;
    }


    

    int ans = min_query(1,0,n-1,1,2);

    cout<<ans<<endl;











}



