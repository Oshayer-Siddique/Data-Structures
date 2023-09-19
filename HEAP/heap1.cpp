#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Heap {
private:
    vector<int> array;
    int max_size;

public:
    Heap(const vector<int>& array, int max_size) : array(array), max_size(max_size) {}

    void max_heapify(int index) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int largest = index;

        if (left_child < max_size && array[left_child] > array[largest]) {
            largest = left_child;
        }

        if (right_child < max_size && array[right_child] > array[largest]) {
            largest = right_child;
        }

        if (largest != index) {
            swap(array[index], array[largest]);
            max_heapify(largest);
        }
    }

    void min_heapify(int index) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int smallest = index;

        if (left_child < max_size && array[left_child] < array[smallest]) {
            smallest = left_child;
        }

        if (right_child < max_size && array[right_child] < array[smallest]) {
            smallest = right_child;
        }

        if (smallest != index) {
            swap(array[index], array[smallest]);
            min_heapify(smallest);
        }
    }

    void sort_heapify(int index, int size) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int largest = index;

        if (left_child < size && array[left_child] > array[largest]) {
            largest = left_child;
        }

        if (right_child < size && array[right_child] > array[largest]) {
            largest = right_child;
        }

        if (largest != index) {
            swap(array[index], array[largest]);
            sort_heapify(largest, size);
        }
    }

    void build_heap(int choice) {
        if (choice == 0) {
            for (int i = max_size / 2 - 1; i >= 0; i--) {  
                min_heapify(i);
            }
        } else { 
            for (int i = max_size / 2 - 1; i >= 0; i--) {
                max_heapify(i);
            }
        }
    }

    void display() {
        for (int i = 0; i < max_size; i++) {  
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void heap_sort_ascending(){
        build_heap(1);
        int temp = max_size-1;
        for(int i=temp; i>=0; i--){
            swap(array[i], array[0]);
            sort_heapify(0, i);
        }
    }

    void heap_sort_descending(){
        heap_sort_ascending();
        reverse(array.begin(), array.end());
    }

};

int main() {
    enum heap_builder { minimum, maximum };
    int n;
    cin >> n;
    vector<int> v(n);  
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    Heap h1(v, n);
    h1.build_heap(maximum);
    h1.display();
    h1.build_heap(minimum);
    h1.display();
    h1.heap_sort_ascending();
    h1.display();
    h1.heap_sort_descending();
    h1.display();
    return 0;
}
