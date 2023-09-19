#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr;

    vector<pair<int,int>> pairVector;

    vector<int>final;


    while (1)
    {
        

        int x;
        cin >> x;
        if(x == -1){
            break;
        }
        arr.push_back(x);
    }


    int k;
    cin >> k;



    map<int,int> m;
    for(int i = 0;i < arr.size();i++){
        m[arr[i]]++;
    }

    map<int,int>::iterator itr;
    for(itr = m.begin();itr != m.end();itr++){
        pairVector.push_back(make_pair(itr->first,itr->second));

    }

    auto customComparator = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    };

    sort(pairVector.begin(),pairVector.end(),customComparator);


    for(auto& ptr: pairVector){
        //cout<<ptr.first<<" - "<<ptr.second<<endl;
        final.push_back(ptr.first);
    }

    for(int i = 0;i < k;i++){
        cout<<final[i]<<" ";
    }

    

}
