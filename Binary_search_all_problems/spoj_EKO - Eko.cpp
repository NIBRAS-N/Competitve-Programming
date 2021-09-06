// // //link: https://www.spoj.com/problems/EKO/

// // //n trees will be given..we have to cut trees of maximum height so that we can collect exactly m woods.

// // //tecnique: binary search monotonic function . [ttttffff] types.

// // #include <iostream>
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define max 1000000
// // #define ll long long int
// // int trees[max];
// // ll a,b;

// // bool mon(ll h){
// //     ll wood=0;
// //     for(int i=0;i<a;i++){
// //         if(trees[i]>=h)
// //         wood+=(trees[i]-h);
// //     }
// //     return wood>=b;
// // }
// // int main()
// // {
    
// //     cin>>a>>b;
// //     for(int i=0;i<a;i++){
// //         cin>>trees[i];
// //     }
// //     ll low=0;
// //     ll high=1e9;
// //     while(high-low>1){
// //         ll mid=(high+low)/2;
// //         if(mon(mid)){
// //             low=mid;
// //         }
// //         else high=mid-1;
// //     }
// //     if(mon(high)) cout<<high<<endl;
// //     else cout<<low<<endl;
// //     return 0;
// // }
//
