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

        ll a,b,xk,yk,xq,yq;
        cin>>a>>b>>xk>>yk>>xq>>yq;


        ll arx[8] = {-a,-a,a,a,b,b,-b,-b};
        ll ary[8] = {b,-b,-b,b,a,-a,a,-a};

        set<pair<int,int> >king;
        set<pair<int,int> >queen;
        for(int i=0;i<8;i++){
            king.insert({xk+arx[i],yk+ary[i]});
            queen.insert({xq+arx[i],yq+ary[i]});
        }
        // for(auto &i:king){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        // cout<<endl;
        // for(auto &j:queen){
        //     cout<<j.first<<" "<<j.second<<endl;
        // }    
        ll ans=0;
        for(auto &i:king){
            if(queen.find(i)!=queen.end()){
                ans++;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}