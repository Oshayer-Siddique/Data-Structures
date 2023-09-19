#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void max_heapify(vector<int> &arr, int indx){

    int left = 2 * indx + 1;
    int right = 2 * indx + 2;
    int largest = indx;
    if(left < arr.size() && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < arr.size() && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != indx){
        swap(arr[largest],arr[indx]);
        max_heapify(arr,largest);
    }



}



void min_heapify(vector<int> &arr, int indx){
    int left = 2 * indx + 1;
    int right = 2 * indx + 2;

    int smallest = indx;
    if(left < arr.size() && arr[left] < arr[smallest]){
        smallest = left;

    }
    if(right < arr.size() && arr[right] < arr[smallest]){
        smallest = right;
    }
    if(smallest != indx){
        swap(arr[smallest],arr[indx]);
        min_heapify(arr,smallest);
    }

}



void build_max_heap(vector<int> &arr){
    for(int i = arr.size()/2 - 1;i >=0;i--){
        max_heapify(arr,i);
    }
    
}



void build_min_heap(vector<int> &arr){
    for(int i = arr.size()/2 - 1;i >=0;i--){
        min_heapify(arr,i);
    }
    
}



void sort_heapify(vector<int> &arr, int indx,int size){

    int left = 2 * indx + 1;
    int right = 2 * indx + 2;
    int largest = indx;
    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != indx){
        swap(arr[largest],arr[indx]);
        sort_heapify(arr,largest,size);
    }



}


void sort_heapify_des(vector<int> &arr, int indx,int size){

    int left = 2 * indx + 1;
    int right = 2 * indx + 2;
    int small = indx;
    if(left < size && arr[left] < arr[small]){
        small = left;
    }
    if(right < size && arr[right] < arr[small]){
        small = right;
    }
    if(small != indx){
        swap(arr[small],arr[indx]);
        sort_heapify(arr,small,size);
    }



}


void sort_ascending(vector<int> &arr){
    build_max_heap(arr);
    int temp = arr.size();
    for(int i = temp-1;i > 0;i--){
        swap(arr[0],arr[i]);
        
        sort_heapify(arr,0,i);

    }
    

}

void sort_desc(vector<int> &arr){
    build_min_heap(arr);
    int temp = arr.size();
    for(int i = temp-1;i > 0;i--){
        swap(arr[0],arr[i]);
        
        sort_heapify_des(arr,0,i);

    }
    

}



int Heap_min(vector<int> &arr){
    sort_ascending(arr);
    return arr[0];

    
}

int Heap_max(vector<int> &arr){
    sort_desc(arr);
    return arr[3];


}



void display(vector<int> &arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
}


int main(){

    int n;
    cin >> n;

    vector<int> arr;
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        arr.push_back(x);

    }

    build_max_heap(arr);
    display(arr);
    cout<<endl;
    build_min_heap(arr);
    display(arr);
    cout<<endl;
    sort_ascending(arr);
    display(arr);
    cout<<endl;
    sort_desc(arr);
    display(arr);
    cout<<endl;
    cout<<Heap_min<<endl;
    //cout<<Heap_max<<endl;


}

