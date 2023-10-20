#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;


void max_heap(vector<int> &vec, int indx){
    int left = 2*indx+1;
    int right = 2*indx + 2;
    int largest = indx;
    if(left < vec.size() && vec[left] > vec[largest]){
        largest = left;


    }
    if(right < vec.size() && vec[right] > vec[largest]){
        largest = right;
    }
    if(largest != indx){
        swap(vec[largest],vec[indx]);
        max_heap(vec,largest);
    }


}

void build_heap(vector<int> &vec){
    for(int i = vec.size()/2;i >= 0;i--){
        max_heap(vec,i);
    }
}


    void sort_heapify(vector<int> &vec,int index, int size) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int largest = index;

        if (left_child < size && vec[left_child] > vec[largest]) {
            largest = left_child;
        }

        if (right_child < size && vec[right_child] > vec[largest]) {
            largest = right_child;
        }

        if (largest != index) {
            swap(vec[index], vec[largest]);
            sort_heapify(vec,largest ,size);
        }
    }


void sort(vector<int> &vec){
    build_heap(vec);
    int temp = vec.size() - 1;
    for(int i = temp;i >= 0;i--){
        swap(vec[i],vec[0]);
        sort_heapify(vec,0,i);
        //reverse(vec.begin(),vec.end());
        
    }
}

void display(vector<int> &vec){
    for(int i = 0;i < vec.size();i++){
        cout<<vec[i]<<" ";
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

    build_heap(arr);
    cout<<"Max Heap : "<<endl;
    display(arr);

    cout<<endl;

    sort(arr);
    
    reverse(arr.begin(),arr.end());
    cout<<"sorted : "<<endl;
    display(arr);


}