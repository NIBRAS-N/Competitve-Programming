//question link:  https://codeforces.com/gym/283180/problem/A

//details: a array will be given..Find such number in the array, that all array elements are divisible by it.

//technique: find the gcd of all number,,if the gcd is present int the array print the number...-1 otherwise.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 10000000007
#define vl vector<ll>

#define vs vector<string>
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sd(a) scanf("%lf",&a)
#define ss(a) scanf("%s",a)
#define p(a) printf("%d\n",a)
#define pl(a) printf("%lld\n",a)
#define pd(a) printf("%lf\n",a)
#define ps(a) printf("%s\n",a)


#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))


ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
 

ll digitsum(ll a){
    if(a==0) return 0;
    return digitsum(a/10)+a%10;
}

ll lcm(ll a, ll b) {
	if (a % b == 0)
		return a;
	return a / gcd(a, b) * b;
}

int main()
{
    ll a,z;
    cin>>a;
    if(a==1){
        ll xx;
        cin>>xx;
        cout<<xx<<endl;
    }
    else{
    vector<ll>abc(a);
    ll k=0;
    for(ll i=0;i<a;i++){
        cin>>abc[i];
    }
    z=abc[0];
    for(ll i=1;i<a;i++){
        z=gcd(z,abc[i]);
    }
    auto x=find(abc.begin(),abc.end(),z);
    if(x==abc.end())cout<<-1<<endl;
    else cout<<z<<endl;
    }
}