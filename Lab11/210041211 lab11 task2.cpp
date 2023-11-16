#include<iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<int,int> X;
    vector<int> arr;
    int x;
    while(1){
        cin >> x;
        if(x == -1){
            break;
        }
        else{
            arr.push_back(x);
            X[x]++;
        }
    }

    int target;
    cin >> target;
    int flag = 0;
    for(int i = 0;i < arr.size();i++){
        int another = target - arr[i];
        if(X[another] > 0){
            cout<<"("<<arr[i]<<" "<<another<<") ";
            X[arr[i]]--;
            X[another]--;
            flag = 1;
        }


    }
    if(flag == 0){
        cout<<"No pair found"<<endl;
    }


}
