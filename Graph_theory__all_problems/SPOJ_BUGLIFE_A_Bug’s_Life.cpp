// // //problem link:  https://www.spoj.com/problems/BUGLIFE/

// // // i have to check whether the graph is bipartite or not


#include<bits/stdc++.h>
using namespace std;
#define max 20002
vector<int>adj[max];

int ar[max];
int ar2[max];//for colouring the node
bool dfs(int node,int col){ 
    ar[node]=1;
    ar2[node]=col;//colouring the node.
    //cout<<node<< "->";
    for(auto child:adj[node]){
        if(ar[child]==0){//node is not visited.
            bool y=dfs(child,col^1);
            if(y==false) return false;//going to the adj list of child and colourig it opposit.
        }
        else{
            if(ar2[node]==ar2[child])return false;//if parent and child both are same colour than its not
        }
    }
    return true;
}
int main()
{
    int x;
    cin>>x;
    for(int i=1;i<=x;i++){
        int total_node,total_edge;
        cin>>total_node>>total_edge;
       
        for(int j=1;j<=total_node;j++) {adj[j].clear();ar[j]=0;}
        for(int j=1;j<=total_edge;j++){
            int node1,node2;//two nodes that are connected with edge i.
            cin>>node1>>node2;
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);//if the graph is directed then this line will not applied.
        }
        bool f=true;
        for(int j=1;j<=total_node;j++){
            if(ar[j]==0){
                bool x=dfs(j,0);
                if(x==false ) {f=false;break;}
            }
        }    
        cout<<"Scenario #"<<i<<":"<<endl;
        if(f){
            cout<<("No suspicious bugs found!")<<endl;
        }
        else{
            cout<<("Suspicious bugs found!")<<endl;
        }
    }
}











