# UVA_10616 - Divisible Group Sums

## Problem_link:
https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1557

## Problem statement briefly in bengali:
    ১ম লাইন:  N , Q int দেওয়া আছে,
    তার পরে N সংখ্যক নাম্বার এবং Q  সংখ্যক কুয়েরি দেওয়া আছ। 

    কুয়েরি তে D  এবং M দেওয়া আছে। 
    N সংখ্যক নাম্বার থেকে বরারব M সংখ্যক নাম্বার নিয়ে তা জোগ করে  জোগফল D দ্বারা বিভাজ্য হতে হবে। 

    এরকম কয়ভাবে সম্ভব?

## Approach:
1. আগের প্রব্লেমের মতো  সব ধরণের  possibility  ট্রাই করতে হবে. 
2. তবে জোগফল D দ্বারা বিভাজ্য কিনা এটা  __modular arithmetic__ ব্যাবহার করে চ্যাক করতে হবে।  
    কারণ সর্বোচ্চ n  হতে পারে 200।  সর্বোচ্চ n এর ম্যান  ৩২ ডিজিট ,  মানে ১০^৯ ।  সর্বোচ্চ m হতে পারে ১০। 
    সুতরাং time complexity হবে 200 *10^9 * 10 যা ১ সেকেন্ডে পসিবল না। 
    modular arithmetic  ব্যাবহার করলে complexity  হবে 200 * 20 * 10। 
    কারণ সর্বোচ্চ D = 20 .

## Code in C++
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
ll abc[212];
ll d;
ll m;

ll dp[205][22][25];
ll solve(ll index , ll sum , ll cnt ){

    if( index>n || cnt==m ){
        return ( sum==0 && cnt==m );
    }
    if( dp[index][sum][cnt]!=-1 ) return dp[index][sum][cnt];
    ll ret=0;
    //Moduler arithmatic part
    ll rem=( sum + abc[index] ) %d;
    if(rem<0)rem+=d;// dealing with neg value
    // Taking
    ret +=solve( index+1 , rem , cnt+1 );
    //Not taking
    ret +=solve( index+1,sum,cnt);
    return dp[index][sum][cnt]=ret;
}
int main()
{
    ll q, tc = 0;
    while (cin >> n >> q)
    {
        if (n == 0 && q == 0)
            break;
        tc++;

        for (int i = 1; i <= n; i++)
            cin >> abc[i];

        cout << "SET " << tc << ":\n";
        for (int i = 1; i <= q; i++)
        {
            cin >> d >> m;
            memset(dp, -1, sizeof(dp));
            cout << "QUERY " << i << ": " << solve(1, 0, 0) << endl;
        }
    }

    return 0;
}

```
## Time complexity:
The size of dp will be the time complexity.
