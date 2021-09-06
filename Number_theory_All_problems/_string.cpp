#include<bits/stdc++.h>

using namespace std;

/// Typedef
typedef long long ll;

#define sc1(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)

#define pf1(a) printf("%lld\n",a)
#define pf2(a,b) printf("%lld %lld\n",a,b)

#define mx 10000007
#define mod 100000007
#define PI acos(-1.0)

#define mx1 5005

int dr[] = {-2,-2,-1,-1,1,1,2,2};
int dc[] = {-1,1,-2,2,-2,2,-1,1};

ll BigMod(ll base, ll pow, ll modvalue){

    if (pow == 0) return 1;

    ll ans = BigMod(base, pow / 2, modvalue);

    ll total = ((ans % modvalue) * (ans % modvalue)) % modvalue;

    if(pow % 2 == 0)
        return total;
    else{
        return (total * (base % modvalue) ) % modvalue;
    }
}

bool isPrime(ll num) {

    for(ll i = 2; i*i <= num; i++)
        if(num % i == 0)
            return false;
    return true;
}

int main()
{
   int ar[5];
   int ar3[5]; //1 2 3 4 5
   int ar2[5];//5 4 3 2 1
   for(int i=0;i<5;i++){//0 1 2 3 4
       cin>>ar[i];
   }
   int j=0;
   for(int i=5-1;i>=0;i--){//4
        ar2[j]=ar[i];//ar2 er 0 number index e anlam ar er 4 number index er value ke 
        j++;
        //cout<<ar[i]<<" ";
   }
   cout<<endl;
    for(int i=0;i<5;i++){
        cout<<ar2[i]<<" ";
    }
}