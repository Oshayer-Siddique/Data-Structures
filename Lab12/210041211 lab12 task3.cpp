#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 2;

vector<int> arr(N, 0);
vector<int> tree(4 * N, 0);
vector<int> lazy(N, 0);

class Lazysegment
{
public:
    vector<int> arr;
    vector<int> tree;
    vector<int> lazy;

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

    void update_range(int node, int st, int end, int left, int right, int increament)
    {
        if (lazy[node] != 0)
        {
            tree[node] += lazy[node];

            if (st != end)
            {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (st > right || end < left)
        {
            return;
        }

        if (st >= left && end <= right)
        {
            tree[node] += increament;

            if (st != end)
            {
                lazy[2 * node] += increament;
                lazy[2 * node + 1] += increament;
            }

            
            return;
        
        }

        else
        {
            int mid = (st + end) / 2;
            update_range(2 * node, st, mid, left, right, increament);
            update_range(2 * node + 1, mid + 1, end, left, right, increament);

            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int min_query(int node, int st, int end, int left, int right)
    {

        if (lazy[node] != 0)
        {
            tree[node] += lazy[node];

            if (st != end)
            {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }
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
};

void printvec(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // for(int i = 1;i < 15;i++){
    //     cout<<tree[i]<<" ";
    // }
    

}