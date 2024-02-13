
/* 
    In a rotated array count how many times it has been 
    rotated.
    ar[]=4 , 5 , 6 ,7 ,0 , 1 , 2
    it has been rotated for 4 times.
    pivot is 7.. it is in 4th position.. so the rotation is 4 
    in this array.

*/

/* 
    Logic:
        1) FIND  pivot
        2)Answer will be the position of the pivot.(1 base index)

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


int main()
{
    vi abc{5,6,7,4};
    cout<<"The count of rotation is "<<findPivotForDuplicateValue(abc)+1<<endl;
    
    return 0;
}




