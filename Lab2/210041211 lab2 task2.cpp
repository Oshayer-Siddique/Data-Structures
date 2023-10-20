#include<bits/stdc++.h>

using namespace std;


int main(){
    string a,b;

    cin >> a >> b;
    int cnt1 = 0;
    for(int i = 0;i < a.length();i++){
        if(a[i] == b[i]){
            cnt1++;
        }
    }
    cout<<cnt1<<endl;

    int freq1[10] = {0};
    int freq2[10] = {0};

    int i,cnt2 = 0;


    for(int i = 0;i < a.length();i++){
        freq1[a[i] - 48]++;

    }
    for(int i = 0;i < b.length();i++){
        freq2[b[i] - 48]++;
        

    }



    for(int i = 0;i< 10;i++){
        cnt2  += (min(freq1[i],freq2[i]));


    }

    //cout<<cnt2<<endl;

    cout<<cnt1<<"B"<<cnt2-cnt1<<"C"<<endl;




}