#  Sum of Different Primes

## Problem Link:
https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3654

## Problem statement briefly in bengali:
    প্রব্লেমে  N এবং k দেওয়া থাকবে.
    k সংখ্যক আলাদা আলাদা prime number এর জোগফল দ্বারা N তৈরী করতে হবে . এভাবে কয়টি উপায়ে N তৈরী করা যাবে বের করতে হবে.

    N =২৪ 
    k =৩ 
    ২+৩+১৯=২৪[২+৩+১৯  যে কথা ৩+২+১৯ একই কথা ]
    ২+৫+১৭=২৪
    সুতরাং ২ টা উপায়ে ২৪ বানানো যায়. উত্তর হবে ২.

## Approach:
1. সব ধরণের  possibility  ট্রাই করতে হবে. 
2. এর জন্য ২-N পর্যন্ত সব ধরণের প্রাইম বের করে রাখতে হবে. 
3. takng এন্ড not taking এপ্রোচ এপ্লাই করতে হবে. 

## C++ code:
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
bool seive[1010000];
vi prime;


const ll mx_N=1200;
ll dp[270][mx_N][16];
ll n,k;
//maximum of N <= 1120. we will take 1200 for safety
// maximum of k=14. we will take 16 for safety
/*  
    total number  prime  before 1200 will be  approximately
    (1200/ln(1200))*1.6 =270.

    [this equation will give  the total number of prime before any number in upper bound].

 */

void seiveGen(int limit) {
    limit += 100;
    int sqrtn = sqrt(limit);
    for(int i = 3; i <= sqrtn; i += 2) {
            if(!seive[i>>1]) {
                    for(int j = i * i; j < limit; j += i + i) {
                            seive[j>>1] = 1;
                    }
            }
    }

    prime.push_back(2);
    for(int i = 3; i < limit; i += 2) {
            if(!seive[i>>1]) prime.push_back(i);
    }
}

ll solve ( ll prime_index ,ll sum,ll cnt){
    if(prime_index==prime.size() || sum>=n || cnt>=k){
        return (sum==n && cnt==k);
    }
    if(dp[prime_index][sum][cnt]!=-1) return dp[prime_index][sum][cnt];
    ll ret=0;
    //taking prime[i]
    ret+=solve( prime_index+1 , sum+prime[prime_index] , cnt+1);
    //not taking prime[i]
    ret+=solve( prime_index+1 , sum , cnt);
    return dp[prime_index][sum][cnt]=ret;
}

int main()
{
    seiveGen(1200);// generating  prime 
    while (cin >> n >> k)
    {
        if (n == 0 && k == 0)
            break;

        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0, 0) << endl;
    }
    return 0;
}
```
## Time Complexity:
---
    The size of dp array is : 270*12000*16 = 5184000 which is less than 10^7. 
