//explaination link:
//  https://www.youtube.com/watch?v=eCG3T1m7rFY&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=11


//theory:

//I have to check whetere there is a back edge or not..if there is a back edge then there should be a cycle.

//Guess , in adjacent list of  node x, childs are y z.
//if y or z is visited , then check that x is parent or not..if x is parent then no cycle..else yes.
//if y or z is not visited we should call the dfs and check its parent.


#include<bits/stdc++.h>
using namespace std;
#define max 100005
vector<int>adj[max];
int ar[max];
bool dfs(int node,int par){
    ar[node]=1;
    //cout<<node<< "->";
    for(auto child:adj[node]){
        if(ar[child]==0){//node is not visited.
            if(dfs(child,node)==true) return true;//checking its parent.
        }
        else{
            if(child!=par)return true;//if the visited node is not parent then return true.
        }
    }
    return false;
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
    if(dfs(1,-1)==true) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    // for(int i=1;i<=total_node;i++){
    //     cout<<"adjacent list of : "<<i<<"->";
    //     for(auto j:adj[i]){
    //         cout<<"{"<<j.first<<" the cost is : "<<j.second<<"} ";
    //     }
    //     cout<<endl;
    // }

}


