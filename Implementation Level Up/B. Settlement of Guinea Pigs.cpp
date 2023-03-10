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
        ll ar[a];
        fo(i,0,a){
            cin>>ar[i];
        }
        ll total_box=0,leftover=0,overall=0;
        fo(i,0,a){
            if(ar[i]==1){
                overall++;
                if(leftover>0)leftover--;
                else total_box++;
            }
            else{
                ll required= (overall==0?0:overall/2) + 1;
                leftover=total_box-required;
            }

        }
        cout<<total_box<<endl;
    }
    return 0;
}