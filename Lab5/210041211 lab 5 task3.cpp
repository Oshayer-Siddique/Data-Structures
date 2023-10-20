#include<iostream>
#include<stack>
#include<vector>
using namespace std;


void printstack(stack<int> &stk){
    if(stk.empty()){
        return;
    }
    int x = stk.top();
    stk.pop();

    printstack(stk);

    cout<<x<<" ";

    stk.push(x);
    
    


}


void printvector(vector<int> &vec){
    for(int i =0;i < vec.size();i++){
        cout<<vec[i]<<" ";
    }
}


void next_smaller_element(stack<int> &stk,vector<int> &vec,vector<int> &final){
    stk.push(-1);
    for(int i = vec.size();i >= 0;i--){
        int curr = vec[i];
        while (stk.top() >= curr)
        {
            stk.pop();
        }
        final[i] = stk.top();
        stk.push(curr);

        
    }
    //printvector(final);

}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n),brr(n),crr(n,0);
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        arr[i] = x;
    }
     stack<int>stk1,stk2;
     stk1.push(-1);
     stk2.push(-1);

    for(int i = n-1;i >= 0;i--){
        int curr = arr[i];
        while (stk1.top() != -1 && arr[stk1.top()] >= curr)
        {
            stk1.pop();
        }

        brr[i] = stk1.top();
        stk1.push(i);


        
    }
    printvector(brr);
    cout<<endl;

    for(int i = 0;i < n;i++){
        int curr = arr[i];
        while (stk2.top() != -1 && arr[stk2.top()] >= curr)
        {
            stk2.pop();
        }

        crr[i] = stk2.top();
        stk2.push(i);
        
    }




    
    cout<<endl;
    printvector(crr);

    // cout<<endl;
    // cout<<"Hello"<<endl;
    // next_smaller_element(stk1,arr,brr);
    // printvector(brr);

    // printvector(arr);

    // next_smaller_element(stk1,arr,brr);
    // printvector(brr);
    // cout<<endl;
    // cout<<endl;
    // for(int i = 0;i < n;i++){

    //     if(brr[i] == -1){
    //         brr[i] = n;
    //     }
    //     int b = brr[i] - crr[i];
    //     cout<<b<<" ";
    // }

    // cout<<endl;
    // cout<<endl;

    // printvector(arr);

    cout<<endl;
    int area = -10000;
    for(int i = 0;i < n;i++){
        if(brr[i] == -1){
            brr[i] = n;
        }
        area = max(area,arr[i]*(brr[i] - crr[i] - 1));

    }
    cout<<area<<endl;
}