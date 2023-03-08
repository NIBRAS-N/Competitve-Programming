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
int main()
{
    w(t){
        ll a;
        cin>>a;
        priority_queue<int,vector<int>>abc;
        ll ans=0;
        fo(i,0,a){
            ll z;
            cin>>z;
            if(z==0){
                if(abc.empty())continue;
                else{
                    
                    ans+=abc.top();
                    //cout<<ans<<" "<<i<<endl;
                    abc.pop();
                }
            }
            else abc.push(z);
        }
        cout<<ans<<endl;

    }
    return 0;
}