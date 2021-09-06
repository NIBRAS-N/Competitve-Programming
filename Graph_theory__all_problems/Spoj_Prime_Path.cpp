// //problem link: https://www.spoj.com/problems/PPATH/

// //Explaination link : https://www.youtube.com/watch?v=eYf4NFc2s1w&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=19

// /* technique: make a graph among  all 4 digits prime numbers..
//     two  primes of 4  digits  will be connected if only one digit is diffrent.
//     for easy example 13 will be connectod to 19 as only one digit is different.

//     now run a bfs and  count shortest path of every prime.
// */

// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long int
// #define max 1003
// vector<int>prime;
// vector<int>adj[100005];
// int ar[100005];
// int dis[100005];
// bool is_prime(int a){
//     for(int i=2;i*i<=a  ;i++){
//         if(a%i==0) return false;
//     }
//     return true;
// }
// bool is_valid(int a,int b){
//     int count =0; 
//     while(a>0){
//         if(a%10 != b%10) count++;
//         a/=10;
//         b/=10;
//     }
//     return count==1;
// }
// void prime_set(){
//     for(int i=1000;i<=9999;i++){
//         if(is_prime(i)) prime.push_back(i);
//     }
//     for(int i=0;i<prime.size()-1;i++){
//         for(int j=i+1;j<prime.size();j++){
//             int x=prime[i];
//             int y=prime[j];
//             if(is_valid(x,y)){
//                 adj[x].push_back(y);
//                 adj[y].push_back(x);
//             }
//         }
//     }

// }
// void bfs(int a){
//     queue<int>q;
//     q.push(a);
//     dis[a]=0;
//     ar[a]=1;
//     while(!q.empty()){
//         int cur=q.front(); 
//         q.pop();
//         for(auto &child:adj[cur]){
//             if(ar[child]==0){
//                 q.push(child);
//                 ar[child]=1;
//                 dis[child]=dis[cur]+1;
//             }
//         }
//     }
// }
// int main()
// {
//     prime_set();
//     // for(auto &i:adj){
//     //     for(auto &j:i){
//     //         cout<<j<<endl;
//     //     }
//     // }
//     int a;
//     cin>>a;
    
//     while(a--){
//         int b,c;
//         cin>>b>>c;
        
//         for(int i=1000;i<=9999;i++){
//             ar[i]=0;
//             dis[i]=-1;
//         }

//         bfs(b);
//         if(dis[c]==-1)cout<<"Impossible"<<endl;
//         else cout<<dis[c]<<endl;;
//     }
//     return 0;
// }


