//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

//find the pivot and pivot+1  will be the answer

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

int findPivot(vector<int>&nums){
    int s=0;
    int e=nums.size()-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        
        if(mid<e && nums[mid]>nums[mid+1]) return nums[mid+1];//pivot is ar[mid]. so min value is ar[mid+1]
        else if(mid>s && nums[mid]<nums[mid-1]) return nums[mid];//pivot is ar[mid-1]. so min value is ar[mid]
        else if(nums[s]>=nums[mid]) e=mid-1;
        else if(nums[s]<nums[mid]) s=mid+1;
    }
    return nums[0];//the array is not rotated array.. it is like sorted array. where last element is pivot. so, we will return the 0th element

}


int main()
{
    vector<int>ar{1,2,3,4,5,6}   ;
    cout<<findPivot(ar)<<endl;
    

    return 0;
}
