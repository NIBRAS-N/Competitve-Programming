//prblem link : https://www.codechef.com/problems/FIRESC

// connected components and combinatorics basic.

#include<iostream>
#include<vector>
using namespace std;
#define max 100005
#define mod 1000000007
 int node_in_a_component=0;
vector<int>adj[max];
int ar[max];    
void dfs(int v){
    ar[v]=1;
    node_in_a_component++;
    for(auto &child:adj[v]){
        if(ar[child]==0)dfs(child);
    }
}
int main()
{
    int a;
    cin>>a;
    while(a--){
        int total_node,total_edge;
        cin>>total_node>>total_edge;
        for(int i=1;i<=total_node;i++){
            adj[i].clear();
            ar[i]=0;
        }
        for(int i=1;i<=total_edge;i++){
            int node1,node2;
            cin>>node1>>node2;
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        int count=0;
        long long int count2=1;
        for(int i=1;i<=total_node;i++){
            if(ar[i]==0){
                
                node_in_a_component=0;
                dfs(i),count++;
                count2=((count2*node_in_a_component) % mod) ;
            }
        }
        cout<<count<<" "<<count2<<endl;
    }
    return 0;
}