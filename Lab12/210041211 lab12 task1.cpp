#include <iostream>
#include<vector>

using namespace std;

const int N = 1e5 + 2;

vector<int> arr(N,0);
vector<int>tree(4 * N,0);

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
        return 1e7;
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

int main()
{


    int n,q ;
    cin >> n >> q;

    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    int x,y;


    build_min(1,0,n-1);

    while (q--)
    {
        cin >> x >> y;
        int ans = min_query(1,0,n-1,x-1,y-1);

        cout<<ans<<endl;

    }
  
}