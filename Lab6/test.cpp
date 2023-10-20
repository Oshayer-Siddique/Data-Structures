#include <bits/stdc++.h>
#include <string>
#define M = 10000000007
#define ll long long
#define ull unsigned long long

using namespace std;

int main()
{
    priority_queue<int>pq1;
    int size,value,total,one,two;
    cin>>size;
    for (size_t i = 0; i < size; i++)
    {
        total=0;
        cin>>value;
        if(i>1)
        {
           pq1.push(value);
         one=pq1.top();
         pq1.pop();
         two=pq1.top();
         pq1.pop();
         
         total=one*two*pq1.top();
         cout<<total<<endl;

        pq1.push(one);
        pq1.push(two);
        }
        else
        {
        
        pq1.push(value);
        cout<<-1<<endl;
        
        }

    }
    

    return 0;
}