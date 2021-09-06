//Problem Link:https://codeforces.com/group/MWSDmqGsZm/contest/326907/problem/D
//we have to find the sum of the range L ot R.
//wae cant use prefix sum or run loop as the constrain is big
//we have to use this equation:(R−L+1)*((R+L)/2)

//or this equation: (r*r+1)/2-((L-1)*((L-1)+1))/2

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main()
{
    ll x;
    cin>>x;
    while(x--){
        unsigned long long int a,b;

        cin>>a>>b;
        if(a>b) swap(a,b);
        double c=(double)((a+b)/2.00);
        cout<<(unsigned long long int) ((double)c*((b-a)+1))<<endl;
    }
    return 0;
}
