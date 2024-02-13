//Find the biggest number smaller or equal to the target number.

// target number theke choto ba shoman shobcheye boro shonkha ta ber koro

//int ar[]={3,4,8,10,19,29,33,40,50};

//******If target ==10 ,, then 10 will be the answer.. 

//******If target==15,, 10 will be the answer. ]
//Because 15 is not present and biggest number smaller than 
//target(15) is 10

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
using vi = vector <int>;
using vll = vector <ll>;
#define pb push_back;
#define fo(i,a,b) for(ll i=(a);i<(b);i++)

int main()
{
    int ar[]={3,4,8,10,19,29,33,40,50};
    ll s=0;
    ll e=8;
    ll target=15;
    bool f=true;
    while(s<=e){
        ll mid=s+(e-s)/2;
        if(ar[mid]>target){
            e=mid-1;        
            cout<<"end "<<e<<endl;
        }
        else if(ar[mid]<target){
            s=mid+1;
            cout<<"Start "<<s<<endl;
        }
        else if(ar[mid]==target){
            cout<<ar[mid]<<endl;
            f=false;
            break;
        }
    }
    if(f==true){
        cout<<ar[e]<<endl;
    }
    return 0;
}
