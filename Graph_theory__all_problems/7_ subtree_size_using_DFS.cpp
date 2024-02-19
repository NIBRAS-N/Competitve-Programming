//explaination link:
//https://www.youtube.com/watch?v=rFVKXZZMH-U&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=16&t=310s


// Here a tree is given.
/* 
    1->2                    subarray size of node 1 is 7.. elements are 1,2,3,4,5,6,7
    2->1,3,4                subarray size of node 2 is 6.. elements are 2,3,4,5,6,7
    3->2,7
    4->2,5,6
    5->4
    6->4
    7->3
*/
 
 #include <iostream>
 #include<bits/stdc++.h>
 using namespace std;
 
 #define ll long long int
 #define max 10004
 int ar[max];
 int sub_size[max];
 vector<int>adj[max];
 int dfs(int node)
 {
     ar[node]=1;
     int cur_size=1;
     for(auto &child:adj[node]){
         if(ar[child]==0){
             cur_size+=dfs(child);
         }
     }
    sub_size[node]=cur_size;
    return cur_size;
 }
 int main()
 {
     int node,edge;
     cin>>node>>edge;
     for(int i=1;i<=edge;i++){
         int node1,node2;
         cin>>node1>>node2;
         adj[node1].push_back(node2);
         adj[node2].push_back(node1);
     }

    //call dfs(1) when 1 is root , if another node is root than pass that node

     dfs(1);
	for(int i=1;i<=node;i++)
	    cout<<"sub tree size of node "<<i<<" is "<<sub_size[i]<<endl;
     return 0;
 }