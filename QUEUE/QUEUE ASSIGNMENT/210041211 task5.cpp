#include <iostream>
#include <deque>
#include <vector>
#include <queue>

using namespace std;


void printvec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}


void printdq(deque<int> &dq)
{
    for (int i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << " ";
    }
}



int main(){

    int k;
    //cin >> n >> k;
    deque<int> dq;
    int cnt = 0;

    vector<int> arr;

    while (1)
    {
        int x;
        if(x == -1){
            break;
        }
        else{
            cin >> x;
            arr.push_back(x);
        }
    }

    cin >> k;
    


    for(int i = 0;i < arr.size()-1;i++){
        dq.push_back(i);
    }
    
    while (!dq.empty())
    {
        cnt++;
        int x = dq.front();
        dq.pop_front();
        if(arr[x] >= 1){
            arr[x]--;
        }
        if(x != k && arr[x] == 0){
            continue;
        }
        else if(x == k && arr[x] == 0){
            break;
        }
        
        dq.push_back(x);
        
    }


    cout<<cnt<<endl;
    


    


    

}
