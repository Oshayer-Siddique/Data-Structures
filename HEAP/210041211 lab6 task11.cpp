#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
    priority_queue<int> pq;
    while (1)
    {
        int x;
        cin >> x;
        
        if(x == -1){
            break;
        }
        pq.push(x);
        
    }


    while (pq.size() != 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        if(a != b)
            pq.push(a-b);
        else{
            pq.push(0);
        }

        
    }

    cout<<pq.top()<<endl;

    
}