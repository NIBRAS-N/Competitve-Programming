// Here is an adjacent list for undirected graph:.

// v[1]={2} node 1 is connected to node 2...degree of node 1 is 1.
// v[2]={1,3,4} node 2 is connected to node 1 ,3 ,4..degree of node 2  is 3.
// v[3]={2} node 3 is connected to node 2.. degree of node 3 is 1.
// v[4]={2} node 4 is connected to node 2..degree of node 4 is 1.

// important theory: number of total edge  =  number of total degree / 2.


// total degree of a graph means total int values needs to represnt the graph.

// if in a graph , m edge is given,Then total memory needs is 2*m

// memory complexity O(n)

//  here total degree=6 , so edge will be 6/2=3;

//for unwighted graph
// #include<bits/stdc++.h>
// using namespace std;
// #define  max 100005 // max will highest number of nodes that can be.
// vector<int>adj[max];
// int main()
// {
//     int total_node,total_edge;
//     cin>>total_node>>total_edge;
//     for(int i=1;i<=total_edge;i++){
//         int node1,node2;//two nodes thatare connected with edge i.
//         cin>>node1>>node2;
//         adj[node1].push_back(node2);
//         adj[node2].push_back(node1);//if the graph is directed then this line will not applied.
//     }
//     for(int i=1;i<=total_node;i++){
//         cout<<"adjacent list of : "<<i<<"->";
//         for(auto j:adj[i]){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }

// }

// for weighted Graph:

#include<bits/stdc++.h>
using namespace std;
#define  max 10000 // max will highest number of nodes that can be.

vector<pair<int,int> > adj[max];

int main()
{
    
    int total_node,total_edge;
    cin>>total_node>>total_edge;
    for(int i=1;i<=total_edge;i++){
        int node1,node2,weight_edge;//two nodes thata re connected with edge i.
        cin>>node1>>node2>>weight_edge;
        adj[node1].push_back ( {node2,weight_edge} );
        adj[node2].push_back ( {node1,weight_edge} );//if the graph is directed then this line will not applied.
    }
    for(int i=1;i<=total_node;i++){
        cout<<"adjacent list of : "<<i<<"->";
        for(auto j:adj[i]){
            cout<<"{"<<j.first<<" the cost is : "<<j.second<<"} ";
        }
        cout<<endl;
    }

}
