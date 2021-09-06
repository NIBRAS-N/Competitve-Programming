//problem link: https://www.spoj.com/problems/PT07Z/

//a tree is given..I Have to tell the diameter of the tree..
//Diameter of a tree is actually longest path between two nodes in a tree..

//details in microsoft_one_note -> theory based classes -> graph_theory ->  topics 6

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int


#define max 10004
vector<ll> adj[max];
ll ar[max];
ll max_d_node;
ll max_d;
void dfs(ll node,ll dis){
    ar[node]=1;
    if(dis>max_d){max_d=dis;max_d_node=node;}
    for(auto &child:adj[node]){
        if(ar[child]==0){
            dfs(child,dis+1);
        }
    }
}
int main()
{
    ll node;
    cin>>node;
    for(int i=1;i<=node-1;i++){
        ll node1,node2;
        cin>>node1>>node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }    
    max_d=-1;
    dfs(1,0);
    for(int i=1;i<=node;i++){
        ar[i]=0;
    }
    max_d=-1;
    dfs(max_d_node,0);
    cout<<max_d<<endl;
    return 0;
}