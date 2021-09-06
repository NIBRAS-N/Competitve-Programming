// //https://codeforces.com/problemset/problem/26/A
// // a number will be given,, I have to find how many almost prime number there will be between 1 to n.

// //almos prime is the prime jetar prime divisor only 2 ta....



// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define ld long double
// #define mod 10000000007
// #define vl vector<ll>

// #define vs vector<string>
// #define s(a) scanf("%d",&a)
// #define sl(a) scanf("%lld",&a)
// #define sd(a) scanf("%lf",&a)
// #define ss(a) scanf("%s",a)
// #define p(a) printf("%d\n",a)
// #define pl(a) printf("%lld\n",a)
// #define pd(a) printf("%lf\n",a)
// #define ps(a) printf("%s\n",a)


// #define FOR(i,a,b)      for(int i=a;i<=b;i++)
// #define ROF(i,a,b)      for(int i=a;i>=b;i--)
// #define REP(i,b)        for(int i=0;i<b;i++)
// #define MEM(a,x)        memset(a,x,sizeof(a))
// #define ABS(x)          ((x)<0?-(x):(x))

// #define min3(a,b,c)     min(a,min(b,c))
// #define max3(a,b,c)     max(a,max(b,c))
// #define min4(a,b,c,d)   min(a,min(b,min(c,d)))
// #define max4(a,b,c,d)   max(a,max(b,max(c,d)))


// ll gcd(ll a, ll b) {
// 	if (b == 0)
// 		return a;
// 	return gcd(b, a%b);
// }
 

// ll digitsum(ll a){
//     if(a==0) return 0;
//     return digitsum(a/10)+a%10;
// }

// ll lcd(ll a, ll b) {
// 	if (a % b == 0)
// 		return a;
// 	return a / gcd(a, b) * b;
// }
// const ll LIM=3003;
// char prime[LIM];
// vector<int> primes;

// void gen() {
//     prime[0] = prime[1] = 1;
//     for(int j=4; j<LIM; j+=2) prime[j] = 1;
//     for(ll i=3; i*i<LIM; i+=2) {
//         if(!prime[i]) {
//             for(ll j=i*i; j<LIM; j+=i) prime[j] = 1;
//         }
//     }
//     primes.push_back(2);
//     for(int i=3; i<LIM; i+=2) if(!prime[i]) primes.push_back(i);
// }

// vector<ll> factor(ll b){
//     vector<ll> v;
//     for(ll i=1;i*i<b;i++){
//         if(b%i==0){
//             v.push_back(i);
//             if(i!=b/i){
//                 v.push_back(b/i);
//             }
//         }
//     }
//     return v;
// }

// int main()
// {
//     gen();
//     ll a;
//     cin>>a;
//     ll count2=0;
//     for(int k=2;k<=a;k++){
//         ll count=0;
//     vector<ll>cdf=factor(k);
//     for(auto &i:cdf){ // 2 3 6 12
//         for(auto &j:primes){
//             if(i==j){
//                 count++;
//             }
//             if(i<j) break;
//         }
//     }
//     if(count==2) count2++;
//     }
//     cout<<count2<<endl;
// }





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
vector<int>abc(1003,-1);

ll s_factor(ll b){
    ll sum=0;
    for(ll i=1;i*i<=b;i++){
        if(b%i==0){
            sum+=i;
            if(i!=b/i){
                sum+=(b/i);
            }
        }
        if(sum>1000) break;
    }
    return sum;
}

int main()
{
   ll a;
    int j=0;
    for(int i=0;i<=1000;i++){
        ll x=s_factor(i);
        if(x<=1000) abc[x]=i;
    }
    cout<<abc[15]<<endl;
    while(cin>>a && a){
        printf ("Case %d: %d\n", ++j, abc[a]);
        cout<<s_factor(a)<<endl;
    }
    return 0;
}
