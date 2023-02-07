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
        string b;
        cin>>b;
        map<string,ll>cd;
        
        for(int i=0;i<b.size()-1;i++){
            if(b[i]==b[i+1] && b[i+1]==b[i+2])
            {    string z=b.substr(i,2);
                cd[z]++;
                i++;
            }    
            else {
                 string z=b.substr(i,2);
                cd[z]++;
            }
        }
        bool f=true;
        for(auto i:cd){
            if(i.second>1){
                //cout<<i.first<<" "<<i.second<<endl;
                f=false;
                break;
            }
        }
        if(f){
            cN;
        }
        else cY;
    }
    return 0;
}