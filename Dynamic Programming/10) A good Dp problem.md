# Partition a set into two subsets such that the difference of subset sums is minimum.

## problem statement:
    You are given an array containing N non-negative integers. Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
    You just need to find the minimum absolute difference considering any valid division of the array elements.
## sample input and output:
    4
    1 2 3 4  
    output: 0
    Explaination:
    We can partition the given array into {2,3} and {1,4}, as this will give us the minimum possible absolute difference i.e (5-5=0) in this case.

    3
    8 6 5
    Output:
    3
    Explaination:
    We can partition the given array into {8} and {6,5}, as this will give us the minimum possible absolute difference i.e (11-8=3) in this case

# Code in c++:
```C++

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
ll n;
ll arr[1003];
ll dp[1003][10004];
ll solve(int index,int t_sum,int a){
    if(index<0) return abs(t_sum-a);
    if(dp[index][t_sum]!=-1) return dp[index][t_sum];
    a+=arr[index];
    t_sum-=arr[index];
    ll first=solve(index-1,t_sum,a);
    a-=arr[index];
    t_sum+=arr[index];
    ll sec=solve(index-1,t_sum,a);
    return dp[index][t_sum]=min(first,sec);
}
int main()
{

    w(t){
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
         int t_s=0;
        for(int i=0;i<n;i++){
         t_s+=arr[i];
        }
        cout<<solve(n-1,t_s,0)<<endl;
    }
    return 0;
}
```
## Complexity:
    Size of the dp array.