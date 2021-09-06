//problem link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1045

// ax+by=d [d=gcd(a,b)]

//here 2 numbers will be given ..they are a,b...we have to print x,y,d.

//technique:
// a and b can be find using extended uclid algorithm.


#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long int
ll x,y,d;
void extended_euclid(ll a,ll b){
    if(b==0){x=1;y=0;d=a;return;}
    extended_euclid(b,a%b);
    ll x1=y;
    ll y1=x-((a/b)*y);
    x=x1;
    y=y1;
    //cout<<x<<" "<<y<<endl;
}
int main()
{
    ll a,b;
    while(cin>>a>>b){
    if(b==0) swap(a,b);
    extended_euclid(a,b);
    cout<<x<<" "<<y<<" "<<__gcd(a,b)<<endl;
    }
}