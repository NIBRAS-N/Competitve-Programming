# Knapsack 1
Problem link: https://atcoder.jp/contests/dp/tasks/dp_d

> This is a simple knapsack problem  

## Problem statement briefly in bangla:
---
    N টি আইটেম দেওয়া থাকবে।  knapsack এর সর্বোচ্চ  ধারণ ক্ষমতা দেওয়া থাকবে এবং আইটেম এর ওজন + মূল্য দেওয়া থাকব।।  knapsack    এর মধ্যে সর্বোচ্চ কত মূল্যের আইটেম রাখা যাবে বের করতে হবে। 

## Sample Input 
    3 8
    3 30
    4 50
    5 60
## Sample Output 
    90
Items 1 and 3 should be taken. Then, the sum of the weights is 3+5=8, and the sum of the values is 30+60=90.

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
ll item;
ll max_weight;
ll item_weight[105];
ll value[105];
ll dp[105][100005];

ll knapsack(ll cur_item,ll cur_weight){
    if(cur_item>item) return 0;
    if(dp[cur_item][cur_weight]!=-1) return dp[cur_item][cur_weight];
    ll res=0;
    ll res2=0;
    if(cur_weight+item_weight[cur_item]<=max_weight){
        //cout<<cur_item<<" "<<cur_weight<<endl;
        res=value[cur_item]+knapsack(cur_item+1,cur_weight+item_weight[cur_item]);

    }
    res2=knapsack(cur_item+1,cur_weight);
    return dp[cur_item][cur_weight]=max(res,res2);
}
int main()
{
    cin>>item>>max_weight;
    for(int i=1;i<=item;i++){
        cin>>item_weight[i]>>value[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<knapsack(1,0)<<endl;
    return 0;
}
```
## Time complexity:
    In this problem maximum item can be 100 and maximum item weight will be 10^5.

    So, time complexity will be 100*10^5=10^7. As it is the size of the dp array. So, this approach will  run under 1 second.