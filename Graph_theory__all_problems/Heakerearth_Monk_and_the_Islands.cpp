//problem link:  https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/

//problem type: SSSP==>single source shortest path.
//given a tree..You have to tell the shortest path of the first node to last node.
#include<bits/stdc++.h>
using namespace std;
#define max 100005
vector<int>adj[max];
int ar[max];
int ar2[max];//for tracking distance
void bfs(int src){
    ar[src]=1;
    queue<int>q;
    q.push(src);
    ar[src]=1;
    ar2[src]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto child:adj[curr]){
            if(ar[child]==0){
                q.push(child);
                ar2[child]=ar2[curr]+1;
                ar[child]=1;
            }
        }
    }
}
int main()
{
    int x;
    cin>>x;
    while(x--){
        for (auto& v : adj) {
            v.clear();
        }
        for(int i=0;i<=max;i++) {ar2[i]=0;ar[i]=0;}
        int total_node,total_edge;
        cin>>total_node>>total_edge;
        for(int i=1;i<=total_edge;i++){
            int node1,node2;//two nodes that are connected with edge i.
            cin>>node1>>node2;
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);//if the graph is directed then this line will not applied.
        }
        bfs(1);
        cout<<ar2[total_node]<<endl;
    }
    return 0;
}