#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>

using namespace std;



int findElement(priority_queue<int> &pq,int m){
    
    for(int i = 0;i < m;i++){
    
        pq.pop();
        
    }
    return pq.top();

    
}




int main(){

    priority_queue<int> pq;
    

    int n;
    cin >> n;
    int flag = 1;
    if(n % 2 == 0){
        flag = 0;
    }
    else{
        flag = 1;
    }

    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        pq.push(x);

    }

    priority_queue<int> pq_copy = pq;


    if(flag == 1){
        cout<<findElement(pq,n/2)<<endl;

    }
    else{
        float x = findElement(pq,n/2);

        float y = findElement(pq_copy,n/2 - 1);

        cout<<((x+y)/2)<<endl;



    }


    

    


    
}