//https://www.spoj.com/problems/AGGRCOW/

//ttttffff types monotonic function.


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define max 1000000
ll stall_n, cows;
ll stalls[max];
bool mon(ll min_dist){
    ll cows_cnt=cows;
    ll last_pos=-1;
        
    for(int i=0;i<stall_n;i++){
        if(stalls[i]-last_pos>=min_dist || last_pos==-1){
            last_pos=stalls[i];
            cows_cnt--;
        }    
        if(cows_cnt==0)break;
    }
    return cows_cnt==0;
}
int main()
{
    ll t;
    cin>>t;
    while(t--){
        cin>>stall_n>>cows;
        for(int i=0;i<stall_n;i++){
            cin>>stalls[i];
        }
        sort(stalls,stalls+stall_n);
        ll low=0;
        ll high=(ll)1e9;
        while(high-low>1){
            ll mid=(high+low)/2;
            if(mon(mid))low=mid;
            else high=mid-1;
        }
        if(mon(high)) cout<<high<<endl;
        else cout<<low<<endl;
    }   
    return 0;
}