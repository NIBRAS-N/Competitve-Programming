// infinity array means we dont know where is the end
// and start.

// so we have to find the end and start by doing a trick.

//note: we cant use arr.size()


// time complexity: for selecting the search space we need to 
// log n time.. as we will double the search space every time.

// for applying binary search in that search space we need total 
// logn time....   

// so total time complexity is logn*logn


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

//initialy start will be 0 and end will be 1
static int s=0;
static int e=1;
void find_start_end(int ar[],int target){
    while(ar[e]<target){
        int temp=e+1;
        //in every step we will double the size of searchoing space
        e=e+((e-s+1) *2);
        s=temp;

    }
}
int main()
{
    int ar[]={5,10,11,12,13,15,18,30,46,55,59,60,75,56,88,78,98,100,105,109,200};
    int target=46;
    find_start_end(ar,target);
    cout<<"start = "<<s<<" end= "<<e<<endl;   
    int ans=0;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(target < ar[mid])e=mid-1;
        else if(target>ar[mid]) s= mid+1;
        else if(ar[mid]==target) {ans=mid;break;}
    }
    if(ans==0) cout<<"the value is not here"<<endl;
    else cout<<"The value is in "<<ans <<" No index"<<endl;
    return 0;
}