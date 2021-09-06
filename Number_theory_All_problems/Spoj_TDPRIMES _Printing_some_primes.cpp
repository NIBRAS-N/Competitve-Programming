//link:https://www.spoj.com/problems/TDPRIMES/en/

//write all the primes from 2 to 10^8.
//To make the problem less output related write out only the 1st, 101st, 201st, ... 1st mod 100.

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

ll lcd(ll a, ll b) {
	if (a % b == 0)
		return a;
	return a / gcd(a, b) * b;
}

const ll LIM=100000008;
char prime[LIM];
vector<int> primes;

void gen() {
    prime[0] = prime[1] = 1;
    for(int j=4; j<LIM; j+=2) prime[j] = 1;
    for(ll i=3; i*i<LIM; i+=2) {
        if(!prime[i]) {
            for(ll j=i*i; j<LIM; j+=i) prime[j] = 1;
        }
    }
    primes.push_back(2);
    for(int i=3; i<LIM; i+=2) if(!prime[i]) primes.push_back(i);
}

int main()
{
    gen();
    for(int i=1;i<primes.size();i+=100){
        cout<<primes[i-1]<<endl;
    }
    return 0;
}
