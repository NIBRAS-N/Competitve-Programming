//problem link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=400

//node are given as char..we have to turn them into int..then calculate how many componenets are there


#include<bits/stdc++.h>
using namespace std;
#define max 30
vector<int>adj[max];
bool ar[max];//for checking visited or not
void dfs(int v){
    if(ar[v]==1) return;
    ar[v]=1;
    //cout<<v<< "->";
    for(auto child:adj[v]){
        if(ar[child]==0) dfs(child);
    }
}
int main()
{
    char xx[2],x[5];
    int y;
    scanf("%d\n",&y);
    while(y--){
        gets(xx);
        int total_node=xx[0]-64;
        for(int i=0;i<total_node;i++){adj[i].clear(); ar[i]=0;}
    while(gets(x) )
    {   
        if(x[0]=='\0') break;
        //cout<<x[0]<<" "<<x[1]<<endl;
        int node1=x[0]-65;
        int node2=x[1]-65;
        //cout<<node1<<" "<<node2<<endl;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);//if the graph is directed then this line will not applied.
    }
    // for(int i=0;i<total_node;i++){
    //     cout<<"adjacent list of : "<<i<<"->";
    //     for(auto j:adj[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    int count=0;
    for(int i=0;i< total_node;i++){
        if(ar[i]==0){
            dfs(i);
            count++;
        }
    }
    if(y==0)
    cout<<count<<endl;
    else cout<<count<<endl<<endl;
    }
}


