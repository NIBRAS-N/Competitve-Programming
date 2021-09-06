#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define maxi 1000

#define ll long long int
ll lanterns,length;
ll arr[maxi];
bool mon(double light){
    return (double)lanterns*light;
}
int main()
{
   ll lanterns,length,dist=-1;
   cin>>lanterns>>length;
   for(int i=0;i<lanterns;i++){
       cin>>arr[i];
   }
    sort(arr,arr+lanterns);
   for(int i=1;i<lanterns;i++){
       if(abs(arr[i]-arr[i-1])>dist){
           dist=abs(arr[i]-arr[i-1]);
       }
   }
    double y=(double)dist/2;
    double x=arr[0];
    double z=max(y,x);
    double zz=length-arr[lanterns-1];
    double ans=max(zz,z);
    cout<<fixed<<setprecision(10)<<ans<<endl;

    return 0;
}