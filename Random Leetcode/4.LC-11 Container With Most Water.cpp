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



ll sol(vll abc, ll a){
    ll res=0;
    ll left=0;
    ll right=a-1;
    while(left<right){
        res=max(res,(min(abc[left],abc[right])*(right-left)));
        if(abc[left]<=abc[right]){
            left++;
        }
        else right--;

    }
    return res;

}
int main()
{
    ll a;
    cin>>a;
    vll abc(a);
    for(int i=0;i<a;i++){
        cin>>abc[i];
    }
    cout<<sol(abc,abc.size())<<endl;;
    return 0;
}