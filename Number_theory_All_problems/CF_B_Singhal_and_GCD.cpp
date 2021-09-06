//link: https://codeforces.com/gym/283180/problem/B
//AN array will be given..Have to find the maximum subarray that have maximum gcd.

//tech: we can find the max gcd from only two numbers .. then we have to find the max subarray  that have equal to the max gcd.

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
    ll a,max_gcd;
    cin>>a;
    while(a--){
        ll b;
        cin>>b;
        vector<ll>abc(b);


        // from line 63-70 I found the largest gcd ...
        // the technique is to check the every 2 numbers gcd...and store that largest gcd in z.
        ll z=0;
        for(ll i=0;i<b;i++){
            cin>>abc[i];
        } 
        for(ll i=0;i<b-1;i++){
            z=max(z,__gcd(abc[i],abc[i+1]));

        }


        //now I have to find that what is the largest subarray that contains the largest  gcd. 
        ll gcd=0;
        ll len=0,m_len=-1;
        for(int i=0;i<b-1;i++){
            gcd=__gcd(abc[i],abc[i+1]);
            if(gcd==z){
                len=2;
                i++;
                while(z==__gcd(abc[i],abc[i+1])&&i<b-1){
                    len++;
                    i++;
                }
            }
            m_len=max(len,m_len);
        }
        cout<<z<<" "<<m_len<<endl;
        abc.clear();
    }
}