#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

#define max 1000006
vector<ll> adj[ max ];

ll curr_cunn;
ll ar[max];
ll components[max];
void dfs(ll node){
    ar[node]=1;
    components[node]=curr_cunn;
    for(auto &child:adj[node]){
        if(ar[child]==0){
            dfs(child);  
        }
    }
}
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string z;
    ll x,y;
    ll a;
    cin>>a;
    while(a--){
        curr_cunn=0;
        ll node,edge;
        cin>>node>>edge;
        vector<pair<ll,ll> > for_not_eq;
        for (int i = 1; i <= node; i++)
        {
            components[i]=0;
            ar[i] = 0;
            adj[i].clear();
        }
        for(int i=1;i<=edge;i++){
           
            cin>>x>>z>>y;
            if(z=="="){
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
            else if(z=="!="){
                for_not_eq.push_back({x,y});
            } 
        }
        for(int i=1;i<=node;i++){
            if(ar[i]==0){
                curr_cunn++;
                dfs(i);
            }
        }
        bool flag=true;
        int kk=for_not_eq.size();
        for(int i=0;i<kk;i++){
            ll p=for_not_eq[i].first;
            ll q=for_not_eq[i].second;
            if(components[p]==components[q]){
                flag=false;
                break;
            }
        }
        if(flag==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}