#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair

#define Fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void build_tree(ll node, ll begin, ll end);
ll build_query(ll node, ll begin, ll end, ll start_range, ll end_range);
//void update_build_tree(ll node, ll begin, ll end, ll start_range, ll end_range, ll value);
void lazy_update_of_build_tree(ll node, ll begin, ll end, ll start_range, ll end_range, ll value);

const int MX = 1e9+3, N = 1e6;
vector<ll>arr(N), segment_tree(4*N, 0), lazy_tree(4*N, 0);

int main(){

    ll n, q, i, j;
    cin >> n >> q;

    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    build_tree(1,1,n);


    ll f_id;
    while (q--)
    {
        cin >> f_id;
        if(f_id == 1){
            ll a , b ,c;
            cin >> a >> b >> c;
            lazy_update_of_build_tree(1,1,n,a,b,c);
        }
        else if(f_id == 2){
            ll k;
            cin >> k;
            cout<<build_query(1,1,n,k,k)<<endl;

        }
    }
    



}


void build_tree(ll node, ll begin, ll end){

    if(begin == end){
        segment_tree[node] = arr[begin];

    }
    else{
        ll mid = (begin + end)/2;
        build_tree(2*node,begin,mid);
        build_tree(2*node+1,mid+1,end);

        segment_tree[node] = segment_tree[2*node] + segment_tree[2*node+1]; 
    }

}


ll build_query(ll node, ll begin, ll end, ll start_range, ll end_range)
{
    if(lazy_tree[node] != 0)
    {
        segment_tree[node] += lazy_tree[node];
        if(begin != end)
        {
            lazy_tree[node*2] += lazy_tree[node];
            lazy_tree[node*2+1] += lazy_tree[node];
        }
        lazy_tree[node] = 0;
    }

    if (begin > end_range || end < start_range)
    {
        return 0;
    }
    else if (begin >= start_range && end <= end_range)
    {
        return segment_tree[node];
    }
    else
    {
        ll left = node * 2;
        ll right = node * 2 + 1;
        ll mid = (begin + end) / 2;

        ll a, b;

        a = build_query(left, begin, mid, start_range, end_range);
        b = build_query(right, mid + 1, end, start_range, end_range);

        return a + b;
    }
}



void lazy_update_of_build_tree(ll node, ll begin, ll end, ll start_range, ll end_range, ll value)
{
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (begin + end) / 2;

    if(lazy_tree[node] != 0)
    {
        segment_tree[node] += lazy_tree[node];
        if(begin != end)
        {
            lazy_tree[node*2] += lazy_tree[node];
            lazy_tree[node*2+1] += lazy_tree[node];
        }
        lazy_tree[node] = 0;
    }

    if (begin > end_range || end < start_range)
    {
        return;
    }
    else if (begin >= start_range && end <= end_range)
    {
        segment_tree[node] += value*(end-begin+1);
        if(begin != end)
        {
            lazy_tree[node*2] += value;
            lazy_tree[node*2+1] += value;
        }
        return;
    }
    else
    {
        lazy_update_of_build_tree(left, begin, mid, start_range, end_range, value);
        lazy_update_of_build_tree(right, mid + 1, end, start_range, end_range, value);

        segment_tree[node] = segment_tree[left] + segment_tree[right];
    }
}


