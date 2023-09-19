#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){

    priority_queue<int, vector<int>, greater<int> > pq;

    int n,k;
    cin >> n >> k;
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        pq.push(x);
    }

    int cnt = 0;

    while (pq.top() < k)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sweetmess = 1 * a + 2 * b;
        pq.push(sweetmess);
        cnt++;

    }

    cout<<cnt<<endl;
    

}