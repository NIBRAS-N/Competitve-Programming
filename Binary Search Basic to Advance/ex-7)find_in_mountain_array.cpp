//https://leetcode.com/problems/find-in-mountain-array/


// A mountain array will be given. A target element will be given.
// You have to search the target and return the the index
//If multiple value exist,, return the smallest ones index


//LOGIC:
// FIND THE PEAK VALUE.
// Do binary search in ihcrement part and search the target
//Do Binary search in the decrement part and search the target



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
int findInMountainArray(int target, vector<int>&mountainArr) {
    int s=0;
    int tem=peakIndexInMountainArray(mountainArr);
    //cout<<tem<<endl;
    int e=tem;
    //search space--> 0 to tem
    while(s<=e){
        int mid=s+(e-s)/2;
        //cout<<mid<<endl;
        if(mountainArr[mid]<target){
            s=mid+1;
            
        }
        else if(mountainArr[mid]>target){
            e=mid-1;
            
        }
        else if(mountainArr[mid]==target){
            return mid;
        }

        
    }
    // search space tem+1  to  end
    // here the values are in descending order.. So conditions 
    // are changed
    s=tem+1;
    e=mountainArr.size()-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(mountainArr[mid]<target){
            e=mid-1;
        }
        else if(mountainArr[mid]>target){
            s=mid+1;
        }
        else if(mountainArr[mid]==target){
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int>ar{0,5,3,1};
    cout<<findInMountainArray(1,ar)<<endl;  
    return 0;
}


