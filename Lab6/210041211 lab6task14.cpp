#include<iostream>
#include<vector>
#include<queue>


using namespace std;

int main(){
    priority_queue<int> pq;

    int n;
    cin >> n;
    int res;
    int x;
    for(int i = 0;i < n;i++){
        
        cin >> x;
        res = 0;
        if(i > 1){
            pq.push(x);
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            cout<<a * b * pq.top()<<endl;
            pq.push(a);
            pq.push(b);

        }
        else{
            pq.push(x);
            cout<<-1<<endl;
        }


        }
    }


