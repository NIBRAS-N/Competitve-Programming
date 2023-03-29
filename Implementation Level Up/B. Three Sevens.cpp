// https://codeforces.com/contest/1798/problem/B

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
        map<ll,ll>cd;
        fo(i,0,a){
            ll b;       cin>>b;
            fo(j,0,b){
                ll d;
                cin>>d;
                cd[d]=i;
            }

        }
        vll ans(a,-1);
        for(auto &i:cd){
            //cout<<i.first<<" "<<i.second<<" ";
            if(ans[i.second]==-1){
                ans[i.second]=i.first;
            }
            //cout<<endl;
        }
        bool f=true;
        for(auto &i:ans){
            if(i==-1) {f=false;break;}
        }
        if(f==0) cout<<-1<<endl;
        else{
            for(auto &i:ans){
                 {cout<<i<<" ";}
            }   
            cout<<endl;
        }
        
    }
    return 0;
}