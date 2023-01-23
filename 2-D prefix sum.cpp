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
    ll row,col;
    cin>>row>>col;
    vector<vector<ll>> abc( row , vector<ll> (col)); 
    
    vector<vector<ll>> prefix_sum( row , vector<ll> (col)); 

    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>abc[i][j];
        }
    }

    prefix_sum[0][0]=abc[0][0];

    for(int i=1;i<col;i++)
        prefix_sum[0][i]=prefix_sum[0][i-1]+abc[0][i];

    for(int i=1;i<row;i++)
        prefix_sum[i][0]=prefix_sum[i-1][0]+abc[i][0];

    for(ll i=1;i<row;i++){
        for(ll j=1;j<col;j++){
            prefix_sum[i][j]=prefix_sum[i-1][j]+prefix_sum[i][j-1]+abc[i][j]-prefix_sum[i-1][j-1];
        }
    }
    
    for(ll i=0;i<row;i++){
        for(ll j=0;j<col;j++){
            cout<<prefix_sum[i][j]<<" ";
        }
        cout<<endl;
    }


    

    
    return 0;
}