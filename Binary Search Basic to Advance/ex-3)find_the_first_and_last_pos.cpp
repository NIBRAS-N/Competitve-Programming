//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

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
int searcht(vector<int> nums,int target,bool grt);

vector<int> searchRange(vector<int>& nums, int target) {
      int first=searcht(nums,target,true);
      int last=searcht(nums,target,false);
      vector<int>abc(2);
      abc[0]=last;
      abc[1]=first;
      return abc;  
}
int searcht(vector<int> nums,int target,bool grt){
    int ans=-1;
    int s=0;
    int e=nums.size()-1;
     while(s<=e){

            int mid=s+(e-s)/2;
            if(nums[mid]>target){
                e=mid-1;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else if(nums[mid]==target){
                ans=mid;
                if(grt){
                    s=mid+1;
                }else e=mid -1;
            }

        }
        return ans;
}
int main()
{
    vector<int>abc{1,2,3};
    vi cd=searchRange(abc,5);
    for(int i=cd.size()-1;i>=0;i--){
        cout<<cd[i]<<" ";
    }
}
