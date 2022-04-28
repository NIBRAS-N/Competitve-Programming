# B - Frog 2
Problem link:  https://atcoder.jp/contests/dp/tasks/dp_b
## Problem Statement briefly in Bangla:
    আগের প্রব্লেমের মতোই এই প্রব্লেম টি।  
    এই প্রব্লেমে একটা স্টোন থেকে তারপরের  k  সংখ্যক যেকোনো  স্টোনে এ যাওয়া যাবে।
    যেখানে আগের প্রব্লেমে একটা স্টোন থেকে শুধুমাত্র তারপরের ২ টা স্টোনে যাওয়া  যেত। 
# Input
    10 4
    40 10 20 70 80 10 20 70 80 60
# Output
    40
If we follow the path 1 → 4 → 8 → 10, the total cost incurred would be ∣40−70∣+∣70−70∣+∣70−60∣=40.
# C++ code.
```c++
    
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
using vi = vector <int>;
using vll = vector <ll>;
#define pb push_back;
#define fo(i,a,b) for(ll i=(a);i<(b);i++)
#define w(x)            ll x; cin>>x; while(x--)

#define b() begin()
#define e() end()
#define cY cout<<"YES\n"
#define cN cout<<"NO\n"
#define cy cout<<"Yes\n"
#define cn cout<<"No\n"
ll n,k;
vll abc(100005);
ll dp[100005];
ll frog_min_cost(ll i){
    //complexity O(k*n)
    if(i==n-1) return 0;
    ll res=INT_FAST32_MAX;
    if(dp[i]!=-1) return dp[i];
    for(ll j=1;j<=k;j++){
        if(i+j<=n-1)res=min(res,abs(abc[i]-abc[i+j])+frog_min_cost(i+j)  );
    }
    return dp[i]=res;
}
int main()
{
    
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    fo(i,0,n) cin>>abc[i];
    //cout<<abc[n-1]<<endl;
    cout<<frog_min_cost(0)<<endl;
    return 0;
}
```
## Time complexity:
---
    For every state a loop is running k time.
    There is n states and k loop is running for every state.
    So, The time complexity will be O(k*n). 