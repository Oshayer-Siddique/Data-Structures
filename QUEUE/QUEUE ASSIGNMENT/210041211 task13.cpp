#include <iostream>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

void printdq(deque<int> &dq)
{
    for (int i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << " ";
    }
}

void printvec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}

int main()
{
    int n;
    
    while (1)
    {   
        cin >> n;
        if(n == 0){
            break;
        }
        vector<int> res;
        deque<int> dq;
        for (int i = 1; i <= n; i++)
        {
            dq.push_back(i);
        }

        while (dq.size() != 1)
        {
            int x = dq.front();
            res.push_back(x);
            dq.pop_front();
            int y = dq.front();
            dq.pop_front();
            dq.push_back(y);
        }

        cout << "Discarded card" << endl;

        printvec(res);
        cout << endl;
        cout << "Remaining card" << endl;
        printdq(dq);
        cout << endl;
    }
}
