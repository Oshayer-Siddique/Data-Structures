#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 2;

int arr[N];

class Info
{
public:
    int sum, prop;
};
Info Tree[N * 4];

void build_sum(int node, int st, int end)
{

    if (st == end)
    {
        Tree[node].sum = arr[st];
        return;
    }
    else
    {
        int mid = (st + end) / 2;
        build_sum(2 * node, st, mid);
        build_sum(2 * node + 1, mid + 1, end);

        Tree[node].sum = Tree[2 * node].sum + Tree[2 * node + 1].sum;
    }
}

void update(int node, int st, int end, int i, int j, int incre)
{
    if (i > end || j < st)
    {
        return;
    }
    if (st >= i && end <= j)
    {
        Tree[node].sum += ((end - st + 1) * incre);
        Tree[node].prop += incre;
        return;
    }
    else
    {
        int mid = (st + end) / 2;
        update(2 * node, st, mid, i, j, incre);
        update(2 * node + 1, mid + 1, end, i, j, incre);
        Tree[node].sum = Tree[2 * node].sum + Tree[2 * node + 1].sum + (end - st + 1) * Tree[node].prop;
    }
}

// int lazy_query(int node, int st, int end, int i, int j, int carry = 0)
// {

//     if (i > end || j < st)
//     {
//         return 1e5;
//     }
//     if (st >= i && end <= j)
//     {
//         return Tree[node].sum + carry * (end - st + 1);
//     }
//     int mid = (st + end) / 2;

//     int q1 = lazy_query(2 * node, st, mid, i, j, carry + Tree[node].prop);
//     int q2 = lazy_query(2 * node + 1, mid + 1, end, i, j, carry + Tree[node].prop);

//     return min(q1,q2);
// }

void build_min(int node, int st, int end)
{

    if (st == end)
    {
        Tree[node].sum = arr[st];
        return;
    }
    else
    {
        int mid = (st + end) / 2;
        build_min(2 * node, st, mid);
        build_min(2 * node + 1, mid + 1, end);

        Tree[node].sum = min(Tree[2 * node].sum, Tree[2 * node + 1].sum);
    }
}


int lazy_query(int node, int st, int end, int i, int j)
{

    if (i > end || j < st)
    {
        return 1e5;
    }
    if (st >= i && end <= j)
    {
        return Tree[node].sum ;
    }
    int mid = (st + end) / 2;

    int q1 = lazy_query(2 * node, st, mid, i, j);
    int q2 = lazy_query(2 * node + 1, mid + 1, end, i, j);
    

    return min(q1,q2);
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // for (int i = 1; i < 15; i++)
    // {
    //     cout << Tree[i].sum << " ";
    // }

    // update(1, 0, n - 1, 0, 3, 3);

    // cout<<endl;

    // for (int i = 1; i < 16; i++)
    // {
    //     cout << Tree[i].sum << " ";
    // }

    build_sum(1,0,n-1);

    int f_id;
    while (q--)
    {
        cin >> f_id;
        if (f_id == 1)
        {
            int x, y;
            cin >> x >> y;
            build_min(1, 0, n - 1);
            int ans = lazy_query(1, 0, n - 1, x - 1, y - 1);
            cout << ans << endl;
        }
        else if (f_id == 2)
        {
            int x, y, increa;
            cin >> x >> y >> increa;
            //build_sum(1, 0, n - 1);
            update(1, 0, n - 1, x - 1, y - 1, increa);
            cout << endl;
            for (int i = 1; i < 3 * n; i++)
            {
                cout << Tree[i].sum << " ";
                //
            }
            cout << endl;
            for (int i = 1; i < 3 * n; i++)
            {
                cout << Tree[i].prop << " ";
                //
            }
            cout<<endl;
        }
    }
}
