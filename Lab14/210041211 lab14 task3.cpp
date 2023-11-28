#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
 
    ll n, q,a,b;
    cin >> n >> q;
    vector<ll>arr(n+1);
 
    for(int i = 1; i<= n; i++)
    {
        cin >> arr[i];
    }
 
 
 
 
 
 
 
 
 
    vector<ll> pref(n+1,0);
    pref[1] = arr[1];
    for(int i = 2; i <= n; i++)
    {
        pref[i] = pref[i-1] ^ arr[i];
        //cout<<pref[i]<<" ";
    }
    ll ans = 0;
 
    for(int i = 0; i < q; i++)
    {
        cin>> a >> b;
        ans = pref[b] ^ pref[a-1];
        cout<<ans<<endl;
    }
 
 
 
 
 
}