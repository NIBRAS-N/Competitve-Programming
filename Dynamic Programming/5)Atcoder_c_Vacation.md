# Acoder_C - Vacation
Problem Link:  
https://atcoder.jp/contests/dp/tasks/dp_c

## Problem statement briefly in bengali:
---
    তারুর গ্রীষ্মের ছুটি N দিন। প্রত্যেক দিন সে নিচের কাজ গুলোর মধ্যে যে কোনো একটি করবে এবং array[i] হ্যাপিনেস অর্জন করবে। 
    A: সমুদ্রে সাঁতার কাটা। এর জন্য array[1] হ্যাপিনেস  পাবে ।  
    B: পাহাড়ে পোকা  ধরা। এর জন্য array[২] হ্যাপিনেস পাবে ।  

    C:বাড়িতে হোমওয়ার্ক করবে। এর জন্য array [৩] হ্যাপিনেস পাব। 

    তার সর্বাধিক সম্ভাব্য মোট হ্যাপিনেস কত?

    শর্ত: সে একই কাজ পরপর দুই বা তার বেশি দিন করতে পারবে  না।

    
## Input:
    3
    10 40 70
    20 50 80
    30 60 90
## Output:
    210

If Taro does activities in the order C, B, C, he will gain 70+50+90=210 points of happiness.

---
## Recursion Tree:

<img src="At c.jpeg" width=390 />

## Code in c++ :
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
ll days;
ll dp[100005][4];
ll happiness[100005][4];

ll max_happiness(ll cur_day,ll cur_hap){
    //time complexity O(3*n) [loop run time for very state*the time of filling the dp array]
    if(cur_day>days)  return 0;
    if(dp[cur_day][cur_hap]!=-1) return dp[cur_day][cur_hap];
    ll res=0;
    for(int i=1;i<=3;i++){
        if(cur_hap!=i)
        {
            res=max(res,happiness[cur_day][i] + max_happiness( cur_day+1,i) );
        }
    }
    return dp[cur_day][cur_hap]=res;
}
int main()
{

    cin>>days;
    for(int i=1;i<=days;i++)    {
        cin>>happiness[i][1]>>happiness[i][2]>>happiness[i][3];
    }
    memset(dp,-1,sizeof(dp));
    cout<<max_happiness(1,0)<<endl;
    return 0;
}
```
## Time Complexity:
    For every state loop is running for at most 3 times.
    And here the dp array is filling in O(N) times.
    So time complexity is O(3*N). We can call it O(N).