//Sorted array: [1 2 3 4 5]
//Rotated sorted array:[4 5 1 2 3]
/* 
    Find pivot
    ****all values should be unique..*****



    **PIVOT** --> [4 5 1 2 3] here 5 is the pivot.. 

    Logic: Pivot is the largest number. pivot-1<pivot>pivot+1


    -->Finding pivot using Binary Search:

    Case 1: ar[mid]>ar[mid+1] --> mid is the answer.
            [4 5 1 2 3] 5>1 then 5 is the answer
    case 2: ar[mid] < ar[mid-1] --> mid-1 is the answer
            [4 5 1 2 3] 5>1 then 5 is the answer
    
    Case:3 start >= mid --> end=mid-1
        if start greater or equal to mid,, then we can say that
        after mid there lies all the smaller number.As we need to
        find the pivot[largest number] , we can avoid all smaller
        number.
        [4 5 1 2 3] if 4>=2, then end = mid - 1.

    Case:4 start < mid  --> start = mid + 1
        [3 4 5 6 2] if start=3, mid =5 
        it means start and mid both lies before the pivot
        mid cant be pivot because if it is pivot then we can access
        it in case 1 and 2.
    
*/


/* 
    Find PIVOT
    ****Values in array can be duplicate*****
    -->see code

*/
/* 
    Search a number in rotated sort array.
    find the pivot.
    then do binary search from before and after pivot and search
    the target
*/








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



int findPivotForDuplicateValue(vector<int>&ar){
    int s=0;
    int e=ar.size()-1;

    while(s<=e){
        int mid=s+(e-s)/2;
        if( mid <e && ar[mid]>ar[mid+1]){
            return mid;
        }
        if(mid>s && ar[mid-1]>ar[mid] )return mid-1;

// if ar[mid]==ar[start]==ar[end]  we have to skip this duplicate
        if(ar[mid]==ar[s] && ar[s]==ar[e]){
//if start is pivot we have to use it
            if(ar[s]>ar[s+1]){
                return s;
            }

            s++;
//if end is pivot         
            if(ar[e] < ar[e-1]) return e-1;

            e--;

        }
//if the mid lies before pivot
        else if(ar[s]<ar[mid] || (ar[s]==ar[mid] && ar[mid]>ar[e])){
            s=mid+1;
        }
        else e=mid-1;
    }
    return -1;

}
int findPivotForUniqueValue(vector<int>&ar){
    int s=0;
    int e=ar.size()-1;
    
    while(s<=e){
        int mid=s+(e-s)/2;
        if(mid<e   &&   ar[mid]>ar[mid+1]) return mid;
        else if(mid>s  &&   ar[mid]<ar[mid-1]) return mid-1;
        else if(ar[s]>=ar[mid]) e=mid-1;
        else if(ar[s]<ar[mid]) s=mid+1;
    }
    //cout<<s<<" "<<e<<endl;
    return -1;
}

int search(vector<int>& nums, int target) {
    int s = 0;
    int tem =findPivotForDuplicateValue(nums);
     //cout<<tem<<endl;
    int e = tem;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        // cout<<mid<<endl;
        if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else if (nums[mid] > target)
        {
            e = mid - 1;
        }
        else if (nums[mid] == target)
        {
            return mid;
        }
    }
    s = tem + 1;
    e = nums.size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] < target)
        {
            s = mid + 1;
            
        }
        else if (nums[mid] > target)
        {
            e = mid - 1;
        }
        else if (nums[mid] == target)
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int>ar{8,1,2,3,4,5,6,7};
    //cout<<search(ar,7)<<endl;
    cout<<findPivotForUniqueValue(ar)<<endl;
    //vector<int>dup{3,3,4,4,9,1,2,2};
    //cout<<search(dup,1)<<endl;
    //cout<<findPivotForDuplicateValue(dup)<<endl;

    return 0;
}


