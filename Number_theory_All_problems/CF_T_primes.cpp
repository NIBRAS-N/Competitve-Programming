

//https://codeforces.com/problemset/problem/230/B


//here q quiries will be given .. in every quiries we have to tell if the 
//number has exactly 3 divisors.

//observation:
//there is always 2 divisors..1 and that number.
//if x is divisors of (int)y than y/x is also a divisors of (int)y;
//only those numbers have 3 divisors who are a square of  prime.. 
//exmple: 4 have 3 divisors -->1,2,4..[4=2*2]
//9 have 3 divisors --> 1 3 9[9==> 3*3]
//25 have 3 divisors --> 1 5 25[25==>5*5]


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define max 1000006
set<ll>tprime;
ll arr[max];
void t_prime(){
    tprime.insert(4);
    for(ll i=3;i<max;i+=2){
        
        if(arr[i]==0)
            tprime.insert(i*i); 
            for(ll j=i;j<max;j+=i){
                arr[j]=1;
            }
    }
}
int main()
{
    t_prime();
    ll x;
    cin>>x;
    while(x--){
        ll a;
        cin>>a;
        //auto z=find(tprime.begin(),tprime.end(),a);
        //auto z=find(tprime.begin(),tprime.end(),a);
        if(tprime.find(a)!=tprime.end())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}