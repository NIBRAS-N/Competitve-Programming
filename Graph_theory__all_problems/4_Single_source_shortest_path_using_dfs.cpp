//problem link:  https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/


/*problem_type: finding that node which contains lowest distance &&  lowest edges && the node must 
lowest ID.[id means int number]
*/


//here n nodes and n-1 edges will be given.
//we have to calculate that node which has min distance from node 1 and  has loewst edges+lowest Id.. 



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



#define  max 1003 // max will highest number of nodes that can be.
vector<int>adj[max];
int ar[max];
int ar2[max];//will track the distance
void dfs(int v,int x){
    ar[v]=1;
    ar2[v]=x;
    //cout<<v<< "->";
    for(auto child:adj[v]){
        if(ar[child]==0) dfs(child,(ar2[v]+1));
    }
}

int main()
{
    int total_node,total_edge;
    cin>>total_node;
    total_edge=total_node-1;
    for(int i=1;i<=total_edge;i++){
        int node1,node2;//two nodes thatare connected with edge i.
        cin>>node1>>node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);//if the graph is directed then this line will not applied.
    }
    dfs(1,0);
    // for(int i=1;i<=total_node;i++){
    //     cout<<"adjacent list of : "<<i<<"->";
    //     for(auto j:adj[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    int number_girl;
    cin>>number_girl;
    int z=number_girl;
    int min_dis=1003;
    int number_of_edge=1003;
    while(number_girl--){
        int girls_add;
        cin>>girls_add;
        if(number_of_edge>adj[girls_add].size()){
            number_of_edge=adj[girls_add].size();//node with lowest edges 
        }
    }
    for(int i=1;i<=z;i++){
        // if(adj[i].size()==number_of_edge && min_dis>i ){
        //     min_dis=i;
        // }
        if(adj[i].size()==number_of_edge) {cout<<i<<endl;break;}
    }
    //cout<<min_dis<<endl;
}
