#include <iostream>
#include<vector>

using namespace std;

const int N = 1e5 + 2;

vector<int> arr(N,0);
vector<int>tree(4 * N,0);


void make_it_empty(vector<int> &arr,int idx){
    
    
    arr[idx-1] = 0;



}


int poor_mon(vector<int> &arr,int idx){
    return arr[idx-1];


}


void add_amount(vector<int> &arr,int idx,int val){
    arr[idx - 1] += val;


}


void build_sum(int node,int st,int end){
    if(st == end){
        tree[node] = arr[st];
        return;

    }
    else{
        int mid = (st + end) / 2;
        build_sum(2*node,st,mid);
        build_sum(2*node+1,mid+1,end);

        tree[node] = tree[2* node] + tree[2*node + 1];
    }

}

int sum_query(int node,int st,int end,int left,int right){
    if(st > right || end < left){
        return 0;

    }
    if(st >= left && end <= right){
        return tree[node];

    }
    else{
        int mid = (st + end)/2;
        int q1 = sum_query(2*node,st,mid,left,right);
        int q2 = sum_query(2*node+1,mid+1,end,left,right);
        return q1+q2;

    }

}


void printvec(vector<int> &arr,int n){
    for(int i = 0;i < n;i++){
        cout<<arr[i]<<" ";

    }
}


int main(){

    int n,q;
    cin >> n >> q;

    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    int f_id;



    
    while (q--)
    {
        cin >> f_id;
        if(f_id == 1){
            int a;
            cin >> a;
            cout<<poor_mon(arr,a)<<endl;
            make_it_empty(arr,a);
            printvec(arr,n);
            cout<<endl;

        }
        else if(f_id == 2){
            int a, b;
            cin >> a >> b;
            add_amount(arr,a,b);

            printvec(arr,n);
            cout<<endl;

        }

        else if(f_id == 3){
            int x,y;
            cin >> x >> y;
            build_sum(1,0,n-1);
            int ans = sum_query(1,0,n-1,x-1,y-1);

            cout<<ans<<endl;


        }
        
    }
    


}

