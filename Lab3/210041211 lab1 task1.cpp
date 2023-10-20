#include <bits/stdc++.h>

using namespace std;


void sort(int arr[],int n){
    for(int i = 0;i< n-1;i++){
        for(int j = i+1;j < n;j++){
            if(arr[i] > arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}



int main(){

    int n = 1000;
    int array[n] = {0};

    int t = 1;
    while(t > 0 && t < n){
        cin>> t;
        if(t > 0){
            array[t]++;
        }
    }

    for(int i = 0;i < n;i++){
        if(array[i] > 0){
            cout<<i<<" occurs "<<array[i]<<" times "<<endl;

           

        }

    }


}
