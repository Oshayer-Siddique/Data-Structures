#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair

#define Fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void addition_segment_tree(ll index, ll begin, ll end);
ll addition_query(ll index, ll begin, ll end, ll start_range, ll end_range);
void update_addition_segment_tree(ll index, ll begin, ll end, ll start_range, ll end_range, ll value);
void lazy_update_of_addition_segment_tree(ll index, ll begin, ll end, ll start_range, ll end_range, ll value);

const int MX = 1e9+3, N = 1e6;
vector<ll>given_input(N), segment_tree(4*N, 0), lazy_tree(4*N, 0);


int main()
{
    Fast;
    
    ll n, q, i, j;
    cin >> n >> q;

    for (ll i = 1; i <= n; i++)
    {
        cin >> given_input[i];
    }

    addition_segment_tree(1,1,n);

    ll choice;
    
    while(q--)
    {
        cin >> choice;
        if(choice == 1)
        {
            ll a, b, u;
            cin >> a >> b >> u;
            lazy_update_of_addition_segment_tree(1,1,n,a,b,u);
        }
        else if(choice == 2)
        {
            ll position;
            cin >> position;
            cout << addition_query(1,1,n,position,position) << endl;
        }
    }

}


void addition_segment_tree(ll index, ll begin, ll end)
{
    if (begin == end)
    {
        segment_tree[index] = given_input[begin];
    }
    else
    {
        ll left = index * 2;
        ll right = index * 2 + 1;
        ll mid = (begin + end) / 2;

        addition_segment_tree(left, begin, mid);
        addition_segment_tree(right, mid + 1, end);

        segment_tree[index] = segment_tree[left] + segment_tree[right];
    }
}

ll addition_query(ll index, ll begin, ll end, ll start_range, ll end_range)
{
    if(lazy_tree[index] != 0)
    {
        segment_tree[index] += lazy_tree[index];
        if(begin != end)
        {
            lazy_tree[index*2] += lazy_tree[index];
            lazy_tree[index*2+1] += lazy_tree[index];
        }
        lazy_tree[index] = 0;
    }

    if (begin > end_range || end < start_range)
    {
        return 0;
    }
    else if (begin >= start_range && end <= end_range)
    {
        return segment_tree[index];
    }
    else
    {
        ll left = index * 2;
        ll right = index * 2 + 1;
        ll mid = (begin + end) / 2;

        ll a, b;

        a = addition_query(left, begin, mid, start_range, end_range);
        b = addition_query(right, mid + 1, end, start_range, end_range);

        return a + b;
    }
}

void lazy_update_of_addition_segment_tree(ll index, ll begin, ll end, ll start_range, ll end_range, ll value)
{
    ll left = index * 2;
    ll right = index * 2 + 1;
    ll mid = (begin + end) / 2;

    if(lazy_tree[index] != 0)
    {
        segment_tree[index] += lazy_tree[index];
        if(begin != end)
        {
            lazy_tree[index*2] += lazy_tree[index];
            lazy_tree[index*2+1] += lazy_tree[index];
        }
        lazy_tree[index] = 0;
    }

    if (begin > end_range || end < start_range)
    {
        return;
    }
    else if (begin >= start_range && end <= end_range)
    {
        segment_tree[index] += value*(end-begin+1);
        if(begin != end)
        {
            lazy_tree[index*2] += value;
            lazy_tree[index*2+1] += value;
        }
        return;
    }
    else
    {
        lazy_update_of_addition_segment_tree(left, begin, mid, start_range, end_range, value);
        lazy_update_of_addition_segment_tree(right, mid + 1, end, start_range, end_range, value);

        segment_tree[index] = segment_tree[left] + segment_tree[right];
    }
}




void update_addition_segment_tree(ll index, ll begin, ll end, ll start_range, ll end_range, ll value)
{
    ll left = index * 2;
    ll right = index * 2 + 1;
    ll mid = (begin + end) / 2;

    if (begin > end_range || end < start_range)
    {
        return;
    }
    else if (begin >= start_range && end <= end_range && begin == end)
    {
        segment_tree[index] += value;
        return;
    }
    else
    {
        update_addition_segment_tree(left, begin, mid, start_range, end_range, value);
        update_addition_segment_tree(right, mid + 1, end, start_range, end_range, value);

        segment_tree[index] = segment_tree[left] + segment_tree[right];
  }
}