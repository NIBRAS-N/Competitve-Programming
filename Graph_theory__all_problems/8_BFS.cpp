//Breadth first search==>BFS

//In this process,,,we will travarse the every node of the graph.

//we can find the shortest way of reaching a node using BFS.

#include<bits/stdc++.h>
using namespace std;
#define max 100005 // the higest number of nodes that can be
vector<int>adj[max];
int ar[max];//visted or not
int ar2[max];//for tracking distance
void bfs(int src){// 2 -> 3   ,  4
//    ar[src]=1;
    queue<int>q;
    q.push(src);//1
    ar[src]=1;
    ar2[src]=0;//
    while(!q.empty()){
        int curr=q.front();//1
        q.pop();
        for(auto child:adj[curr]){
            if(ar[child]==0){
                q.push(child);
                ar2[child]=ar2[curr]+1;// current node
                ar[child]=1;
            }
        }
    }
}
int main()
{
    int total_node,total_edge;
    cin>>total_node>>total_edge;
   
   for(int i=1;i<=total_edge;i++){//1 3  
        int node1,node2;//two nodes that are connected with edge i.
        cin>>node1>>node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);//if the graph is directed then this line will not applied.
    }
    bfs(1);
    for(int i=1;i<=total_node;i++) cout<<ar[i]<<" "<<ar2[i]<<" "<<i<<endl;
}

