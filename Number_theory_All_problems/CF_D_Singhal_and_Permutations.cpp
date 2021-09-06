// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define ld long double
// #define mod 1000000007
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

// ll lcm(ll a, ll b) {
// 	if (a % b == 0)
// 		return a;
// 	return a / gcd(a, b) * b;
// }
// ll factor(ll b){
//     ll c=0;
//     for(ll i=1;i*i<=b;i++){
//         if(b%i==0){
//             c++;
//             if(i!=b/i){
//                 c++;
//             }
//         }
//     }
//     return c;
// }
// ll get(ll b, ll p)
// {
// 	ll res = 1;
// 	while (p > 0)
// 	{
// 		if (p & 1)
// 			res = (res * b) % mod;
// 		b = (b * b) % mod;
// 		p >>= 1;
// 	}
// 	return res;
// }  

// int main()
// {
//     ll a;
//     cin>>a;
//     while(a--){
//         bool f=1;
//         ll count=0,count2=0,zz=2,ans=1;
//         ll b;
//         cin>>b;
//         ll z=-1;
//         unordered_map<ll,int>ab;
//         unordered_map<ll,int>cd;
//         vector<ll>abc(b);
//         for(auto &i:abc){
//             cin>>i;
//             ab[i]++;
//             if(ab[i]>2){ab.clear();abc.clear();cout<<0<<endl;f=0;break;}
//             z=max(z,i);
//         }
//         if(f==0){continue;}
//         for(auto &i:abc ){
//             if(i!=z)cd[i]++;
//         }
//         if(ab[z]>1) {ab.clear();abc.clear();cout<<0<<endl;cd.clear();continue;}
//         else{
//             for(auto &i:cd){
//                 if(i.second==2) count++;
//                 if(i.second==1) count2++;
//             }
//             ll res=get(2,count2);
//             cout<<res<<endl;
//             abc.clear();
//             abc.clear();
//         }
//     }
// }




#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
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

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define umii            unordered_map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define rep(i,n)        for(int i=0;i<n;i++)
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int get(int b, int p)
{
	int res = 1;
	while (p > 0)
	{
		if (p & 1)
			res = (res * b) % mod;
		b = (b * b) % mod;
		p >>= 1;
	}
	return res;
}
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	w(t)
	{
		int n; cin >> n; int arr[n]; rep(i, n)cin >> arr[i];
		int maxi = *max_element(arr, arr + n);
		int a = 0;
		rep(i, n)if (arr[i] == maxi)a++;
 
		if (a >= 2)
		{
			cout << 0 << endl;
			continue;
		}
		else
		{
			map<int, int>m;
 
			rep(i, n)
			{
				if (arr[i] != maxi)
					m[arr[i]]++;
			}
			bool flag = true;
			int o = 0, d = 0;
			for (auto j : m)
			{
				if (j.second == 2)
					d++;
				else if (j.second == 1)
					o++;
				else
				{
					cout << 0 << endl;
					flag = false;
					break;
				}
			}
			if (flag)
			{
				cout << get(2, o) << endl;
			}
		}
	}
 
}
 
 
 
 
 
 
 
 
 