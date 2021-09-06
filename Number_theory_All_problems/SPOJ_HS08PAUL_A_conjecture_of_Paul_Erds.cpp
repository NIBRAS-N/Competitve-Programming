//problem link: https://www.spoj.com/problems/HS08PAUL/
//in this problem a number n will be given.[1<=n<=10^7]
// I have to count how many primes are there from 1 to n..
// note: the prime must be the result of this equation --> x^2 + y^4... x and y can be any number...


//technique:
//1.apply the gen()  function.
//2.run for(for) loop to calculate the equation x^2+y^4<=n..then calculate how many primes there .

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
#define w(x)                 ll x; cin>>x; while(x--)

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

const int LIM=10000007;
ll prime[LIM];
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

vector<ll>abc(10000007);//here the prime which satisfy the equation will be store as index
int main()
{
	gen();
	ll dd=0;
	//this loop wont work in laptop for the large value
	for(ll xx=1;xx<3200;xx++){

		//x=sqroot(10^7).reason is simple.

		for(ll i=1;i<58;i++){
			//y=(10^7)^(1/4)
			dd= ((xx*xx) + (i*i*i*i));//dd=2
			if(dd>LIM){ continue;}
			if(!prime[dd]) {abc[dd]=1;}//abc[2]
		}
	}
	for(int i=1;i<10000007;i++){
		abc[i]+=abc[i-1];//
	}
	// for(int i=0;i<30;i++) cout<<abc[i]<<endl;
	w(t){
		int x;//2
		cin>>x;//
		cout<<abc[x]<<endl;
	}
}