//question Link:  https://codeforces.com/gym/283180/problem/C#

// lcm(a,b) / a...here b will be given...a can be any number from 1 to 10^18..have to tell how many number is satisfied for the eqn.


//lcm(a,b)/a== (a*b)/(gcd(a,b)*a) == b/(gcd(a,b))...So the answer wil be the number of factors of b.


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
ll factor(ll b){
    ll c=0;
    for(ll i=1;i*i<=b;i++){
        if(b%i==0){
            c++;
            if(i!=b/i){
                c++;
            }
        }
    }
    return c;
}

int main()
{
    ll a;
    cin>>a;
    cout<<factor(a)<<endl;
    return 0;
}
