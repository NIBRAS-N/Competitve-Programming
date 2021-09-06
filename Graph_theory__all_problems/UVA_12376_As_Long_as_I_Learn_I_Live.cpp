// problem link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3798

//an directed weighted graph is given..
//u have to taravel through the largest weighted edges and tell the last point of the graph


#include<bits/stdc++.h>

using namespace std;
vector<int>adj[1005];
int a[1005];
int ans1,ans2;
bool compare(int x,int y){
   return a[x]>a[y];
}
void dfs(int s){

    if(adj[s].size()==0){//for the lst node that have no adjacent list
        ans1=s;
        return;
    }
    ans2+=a[adj[s][0]];//adding the weight

    dfs(adj[s][0]);//dfs call of the largest weight
}
int main()
{
    int t,cas=0,node,edge,u,v;
    cin>>t;
    while(t--){
        cas++;
        cin>>node>>edge;
        for(int i=0;i<node;i++){adj[i].clear();a[i]=0;}
        for(int i=0;i<node;i++)
            cin>>a[i];
        for(int i=0;i<edge;i++){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        for(int i=0;i<=node;i++){
            sort(adj[i].begin(),adj[i].end(),compare);
        }
        ans2=0;
        dfs(0);
        cout<<"Case "<<cas<<": "<<ans2<<" "<<ans1<<endl;

    }
    return 0;
}