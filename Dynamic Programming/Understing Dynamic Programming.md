# Why Usisng dynamic programming?
---
<p>To understand the use of Dynamic programming we need to  see a problem  name fibonacci siries. </p>
To generate fibonacci siries the c++ code is:

```c++ 
    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
    ll fib(ll n){
        if(n==0)return 0;
        if(n==1) return 1;
        return fib(n-1)+fib(n-2);
    }
    int main(){
        ll n;
        cin>>n;
        cout<<fib(n)<<endl;
    }
```
## Recursion tree of previous code is:
<img src="fib rec tree.jpeg" width="500">

    Here the time complexity is 2^n and fib(n-3) is calling for multiple times.
    To optimize these types of problems we use dynamic programming.

> In dynamic programming , The function which has been computed once,We will never compute that again. We will store them in array, and use them in future call from the array.

## So the optimized code using dp is:

```c++
    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
    const ll N=1e5+10;
    ll dp[N];
    //N will be given in the question
    ll fib(int n){

        if(n==0)return 0;
        if(n==1) return 1;
        
        if(dp[n]!=-1)return dp[n];//It is called memoising
        return dp[n]= fib(n-1)+fib(n-2);
    }
    int main(){
        ll n;
        cin>>n;
        memset(dp,-1,sizeof(dp));
        cout<<fib(n)<<endl;
    }    
```
> We will call this '__TOP DOWN__' APPROACH.

    After using this technique, the time complexity will reduce to 0(n).Mainly the size of the array.IN fact here simply we are filling the array.
## Now the recursion tree will be:
<img src='fib rec tree using dp.jpeg'>

---

## So what is the main adavantage of dynamic programming?
    It helps to efficiently solve a class of problems that have overlapping subproblems and optimal substructure property.
    
    The actual advantage of dp is that it can obtain both local and total optimal solution.