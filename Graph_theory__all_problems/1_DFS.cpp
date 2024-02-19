
//v[1]={2} node 1 is connected to node 2...degree of node 1 is 1.
//v[2]={1,3,4} node 2 is connected to node 1 ,3 ,4..degree of node 2  is 3.
//v[3]={2} node 3 is connected to node 2.. degree of node 3 is 1.
//v[4]={2} node 4 is connected to node 2..degree of node 4 is 1.


#include<bits/stdc++.h>
using namespace std;
#define max 100005
vector<int>adj[max];
int ar[max];//for checking visited or not
void dfs(int v){
    ar[v]=1;
    //cout<<v<< "->";
    for(auto child:adj[v]){//1-->2
        if(ar[child]==0) dfs(child);
    }
}
int main()
{
    int total_node,total_edge;// 5 5 
    cin>>total_node>>total_edge;
   
    for(int i=1;i<=total_edge;i++){
        int node1,node2;//two nodes thatare connected with edge i.
        cin>>node1>>node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);//if the graph is directed then this line will not applied.
    }
    dfs(1);
    for(int i=1;i<=total_node;i++){
        cout<<"adjacent list of : "<<i<<"->";
        for(auto j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

