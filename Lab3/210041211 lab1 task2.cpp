#include<bits/stdc++.h>

using namespace std;

int factorial(int n){
    if(n > 1){
        return n* factorial(n-1);
    }
    else{
        return 1;
    }
}


int main(){
    int n;

    cin >> n;

    int fact1 = 1;
    for(int i = 1;i <= n;i++){
        fact1 = fact1 * (i);


    }

    cout<<fact1<<endl<<"Using iteration"<<endl;

    cout<<factorial(n)<<endl<<"using recurrsion ";


}