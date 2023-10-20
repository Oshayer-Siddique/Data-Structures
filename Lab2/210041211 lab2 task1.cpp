#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,r;
    cin >> n >> r;
    int arr[100];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    int x = 0;
   
    
    for(int j = 0;j < r;j++){
        int sum = 0;
        int cnt = 0;
        cin >> x;
        for(int i = 0;i < n;i++){
            if(arr[i] <= x){
                sum = sum + arr[i];
                cnt+=1;

            }
        }

        cout<<cnt<<" "<<sum<<endl;

    }



}