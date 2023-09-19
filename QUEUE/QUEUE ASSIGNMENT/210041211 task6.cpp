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



int main()
{
    int n;
    cin >> n;
    deque<int> s1, s2;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s1.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s2.push_back(x);
    }

    int cnt = 0;

    while (!s2.empty())
    {
        if(s1.front() == s2.front()){
            s1.pop_front();
            s2.pop_front();
            cnt = 0;
        }
        else{
            int x = s1.front();
            s1.pop_front();
            s1.push_back(x);
            cnt++;

        }

        if(cnt == s1.size()){
            break;
        }
    }

    cout<<cnt<<endl;
    


}