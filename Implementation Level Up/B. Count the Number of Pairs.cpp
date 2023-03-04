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
        ll a,b;
        cin>>a>>b;
        string c;
        cin>>c;
        map<char,ll>abc;
        fo(i,0,a){
            abc[c[i]]++;
        }
        ll ans=0;
        for(char i='a';i<='z';i++){
            ll z=abc[i];
            ll zz=abc[i-32];
             ans += min(z,zz);
            if(b>0){
                ll k=(max(z,zz)-min(z,zz))/2;
                ans += min(k,b) ;
                b-=min(k,b);
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}