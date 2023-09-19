#include <iostream>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

void printdeque(deque<int> &dq)
{
    for (int i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << " ";
    }
}

int find_max(deque<int> &dq){
    int max_m = dq.front();
    for(int i = 0;i < dq.size();i++){
        if(dq[i] > max_m){
            max_m = dq[i];
        }
    }
    return max_m;

}


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }

    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        dq.push_back(arr[i]);
    }

    // printdeque(dq);
    cout << endl;
    cout << find_max(dq) << endl;

    for (int i = k; i < n; i++)
    {
        dq.pop_front();
        dq.push_back(arr[i]);
        // printdeque(dq);

        cout << find_max(dq) <<endl;
    }
}
