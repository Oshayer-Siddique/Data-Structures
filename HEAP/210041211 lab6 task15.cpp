#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pqmax;
priority_queue<int, vector<int>, greater<int> > pqmin;

void insert(int x){
    if(pqmin.size() == pqmax.size()){
        if(pqmax.size() == 0){
            pqmax.push(x);

        }
        if(pqmax.top() < x){
            pqmax.push(x);
        }
        else{
            pqmin.push(x);
        }
    }
    else{
        if(pqmax.size() > pqmin.size()){
            if(x >= pqmax.top()){
                pqmin.push(x);

            }
            else{
                int t = pqmax.top();
                pqmax.pop();
                pqmin.push(t);
                pqmax.push(x);
            }


        }
        else{
            if(x <= pqmin.top()){
                pqmax.push(x);
            }
            else{
                int t = pqmin.top();
                pqmin.pop();
                pqmax.push(t);
                pqmin.push(x);
            }


            
        }
    }




}

float findmedian(){
    if(pqmax.size() == pqmin.size()){
        return (pqmax.top() + pqmin.top()) / 2.0;
    }
    else if(pqmax.size() > pqmin.size()){
        return pqmax.top();
    }
    else{
        return pqmin.top();
    }


}



int main(){

        insert(10);
    cout<<findmedian()<<endl;
        insert(15);
    cout<<findmedian()<<endl;
        insert(5);
    cout<<findmedian()<<endl;
        insert(1);
    cout<<findmedian()<<endl;
        insert(3);
    cout<<findmedian()<<endl;
        insert(8);
    cout<<findmedian()<<endl;




}