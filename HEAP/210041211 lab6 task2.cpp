#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;


    void min_heapify(vector<int> &array,int index) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int smallest = index;

        if (left_child < array.size() && array[left_child] < array[smallest]) {
            smallest = left_child;
        }

        if (right_child < array.size() && array[right_child] < array[smallest]) {
            smallest = right_child;
        }

        if (smallest != index) {
            swap(array[index], array[smallest]);
            min_heapify(array,smallest);
        }
    }


void build_heap(vector<int> &array){
    for(int i = array.size()/2;i >= 0;i--){
        min_heapify(array,i);
    }
}


int Heap_minimum(vector<int> &array){
    return array[0];

}

int heap_extract_min(vector<int> &array){
    return array[0];
}


void min_heap_insert(int value, vector<int> &array){
    array.push_back(value);
    build_heap(array);


}

void heap_decrease_key(int p,int k ,vector<int> &array){
    array[p] -= k;
    build_heap(array);


}

void heap_increase_key(int p,int k ,vector<int> &array){
    array[p] += k;
    build_heap(array);


}


void display(vector<int> &array){
    for(int i = 0;i < array.size();i++){
        cout<<array[i]<<" ";
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
    int f_id;
    while (1)
    {
        cin >> f_id;
        if(f_id == -1){
            build_heap(arr);
            cout<<"Min Heap : "<<endl;
            display(arr);
            cout<<endl;
        }
        else if(f_id == 1){
            build_heap(arr);
            cout<<Heap_minimum(arr)<<endl;
            display(arr);
            cout<<endl;

        }
        else if(f_id == 2){
            build_heap(arr);
            cout<<heap_extract_min(arr)<<endl;
            
            arr.erase(arr.begin());
            build_heap(arr);
            display(arr);
            cout<<endl;

        }
        else if(f_id ==3){
            int val;
            cin >> val;
            min_heap_insert(val,arr);
            display(arr);
            cout<<endl;
        }
        else if(f_id ==4){
            int p;
            cin >> p;
            int k;
            cin >> k;
            heap_decrease_key(p,k,arr);
            display(arr);
            cout<<endl;

        }
        else if(f_id == 5){
            int p;
            cin >> p;
            int k;
            cin >> k;
            heap_increase_key(p,k,arr);
            display(arr);
            cout<<endl;

        }
    }
    


}