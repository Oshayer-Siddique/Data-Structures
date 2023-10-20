#include<bits/stdc++.h>

using namespace std;


int binarysearchiterative(int arr[], int x, int low , int high){
    while(low < high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == x){
            return mid;
        }
        if(arr[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}


int binarysearchrecursive(int arr[],int x,int low, int high){
    if(low > high){
        return -1;

    }
    int mid = low + (high - low)/2;
    if(x == arr[mid]){
        return mid;
    }
    else if(x < arr[mid]){
        return binarysearchrecursive(arr,x,low, mid-1);

    }
    else{
        return binarysearchrecursive(arr,x,mid+1,high);

    }

}


int main(){
    int n;

    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    int x;
    cin >> x;

    cout<<binarysearchiterative(arr,x,0,n-1)<<"  Iterative way"<<endl;
    cout<<binarysearchrecursive(arr,x,0,n-1)<<"  Recurrsive way"<<endl;

}