//problem link: https://www.spoj.com/problems/PT07Y/

//problem type: check it is graph or not

//Here  n nodes and m edges wil be given. next m line will be u and v.
//I have to tell if it is graph or not..

//technique: it is graph if it has only one connected component and has exactly n-1 edges.
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



#define  max 20004 // max will highest number of nodes that can be.
vector<int>adj[max];
int ar[max];
void dfs(int v){
    ar[v]=1;
    //cout<<v<< "->";
    for(auto child:adj[v]){
        if(ar[child]==0) dfs(child);
    }
}

int main()
{
    int total_node,total_edge;
    cin>>total_node>>total_edge;
    if(total_edge==total_node-1){
        for(int i=1;i<=total_edge;i++){
            int node1,node2;//two nodes thatare connected with edge i.
            cin>>node1>>node2;
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);//if the graph is directed then this line will not applied.
        }
        dfs(1);
        for(int i=1;i<=total_node;i++){
            if(ar[i]==0) {cout<<"NO"<<endl;return 0;}
        }
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}