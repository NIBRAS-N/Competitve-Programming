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
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

ll stock(vll ar){
    ll b=0;
    ll res=0;
    for(int i=0;i<ar.size()-1;i++){
        if(ar[i]<=ar[i+1]){
            
            b=ar[i];
            bool t = true;
            while(ar[i]<=ar[i+1]){
                
                if(i==ar.size()-2){
                    
                    res+=(ar[i+1]-b);
                    t=false;
                    break;
                }
                i++;
            }
            if(t==false) break;
            res+=(ar[i]-b);
        }
        else{
            continue;
        }
    }
    return res;
}
int main()
{
    ll a;
    cin>>a;
    vll ar(a);
    for(int i=0;i<a;i++){
        cin>>ar[i];
    }
    cout<<stock(ar)<<endl;
    return 0;
}