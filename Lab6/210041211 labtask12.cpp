#include<iostream>
#include<queue>
#include<vector>

using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cost =0;
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i = 0;i < n;i++){
            int x;
            cin >> x;
            pq.push(x);

        }

        while (1)
        {
            int x = pq.top();
            pq.pop();
            if(pq.empty()){
                break;
            }
            int y = pq.top();
            pq.pop();
            int sum  = x + y;
            cost += sum;
            pq.push(sum);

        }

        cout<<cost<<endl;
        
    }
}