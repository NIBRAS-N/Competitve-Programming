//we wil track when we enter in a node and when we left from from a node.

//this topic is used to check wheter one node lies in another nodes subtree or not

//facts:
//.........

//in time of parent will be smaller than children
//out time of parent will be greater than children


//if node x lies in the subtree of node y then,,, in time of node x will be higher than y,and out time
//of node x will be lower than y
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define max 1005
vector<int>adj[max];
int ar[max];
int in_time[max];
int out_time[max];
static int tim=0;
void dfs(int v){
    ar[v]=1;
    in_time[v]=++tim;
    for(auto &child:adj[v]){
        if(ar[child]==0) dfs(child);
    }
    out_time[v]=++tim;
}
int main()
{
   
    int total_node,total_edge;
    cin>>total_node>>total_edge;
    for(int i=1;i<=total_edge;i++){
        int node1,node2;
        cin>>node1>>node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    dfs(1);
    for(int i=1;i<=total_node;i++){
        cout<<i<<" "<<in_time[i]<<" "<<out_time[i]<<endl;
    }
    return 0;
}

