
//https://leetcode.com/problems/peak-index-in-a-mountain-array/#

// Mountain array: 1 2 3 4 5 4 3 2 
// In mountain array , no two elements will be equal
//there will be a decrement part and a increment part
//we have to find the peak  element using binary search


//Logic:
//start=0, end=arr.size()-1, mid=start+end/2

//if the mid is in decrement part we will do end=mid.Because
// the mid is a possible answer and also before  the mid could be
// the answer lies

//If the mid is in increment part , we will do star=mid+1.
//because the answer surely will lie in front

//if start==end we will go out from the while loop



#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
using vi = vector <int>;
using vll = vector <ll>;
#define pb push_back;
#define fo(i,a,b) for(ll i=(a);i<(b);i++)
#define w(x)            ll x; cin>>x; while(x--)





int peakIndexInMountainArray(vector<int>& arr) {
    int s=0;
    int e=arr.size()-1;
    while(s!=e){
        int mid=s+(e-s)/2;
    
        if(arr[mid]>arr[mid+1]){
        // for this condition the mid is in in decrement part    
            e=mid;
        }
        else if(arr[mid]<arr[mid+1]){
        // for this condition the mid is in increment part                 
            s=mid+1;
        }

    }
    return s;
}
int main()
{
   vector<int>ar{0,10,5,2};
   cout<<peakIndexInMountainArray(ar)<<endl;
    return 0;
}