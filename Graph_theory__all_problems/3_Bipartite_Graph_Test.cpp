/*A bipartite graph is a graph whose vertices can be divided into two disjoint sets so 
    that every edge connects two vertices from different sets 
    (i.e. there are no edges which connect vertices from the same set)
*/
//technique:

//pashapai node goloke 1 and 0 diye fill up korbo . jodi kono parent node same colour hoy tyle 
// tyle graph ta bipartite na..
//tutorial link:
//https://www.youtube.com/watch?v=MtFPqCcsoeA&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=9&t=245s

//Universal truth:
//every tree is bipartite graph.

#include<bits/stdc++.h>
using namespace std;
#define max 100005
vector<int>adj[max];
int ar[max];
int ar2[max];//for colouring the node
bool dfs(int node,int col){ 
    ar[node]=1;
    ar2[node]=col;//colouring the node.
    //cout<<node<< "->";
    for(auto child:adj[node]){
        if(ar[child]==0){//node is not visited.
            if(dfs(child,col^1)==false) return false;//going to the adj list of child and colourig it opposit.
        }
        else{
            if(ar2[node]==ar2[child])return false;//if parent and child both are same colour than its not
        }
    }
    return true;
}
int main()
{
    int total_node,total_edge;
    cin>>total_node>>total_edge;
   
    for(int i=1;i<=total_edge;i++){
        int node1,node2;//two nodes that are connected with edge i.
        cin>>node1>>node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);//if the graph is directed then this line will not applied.
    }
    if(dfs(1,0)==true) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    // for(int i=1;i<=total_node;i++){
    //     cout<<"adjacent list of : "<<i<<"->";
    //     for(auto j:adj[i]){
    //         cout<<"{"<<j.first<<" the cost is : "<<j.second<<"} ";
    //     }
    //     cout<<endl;
    // }

}
