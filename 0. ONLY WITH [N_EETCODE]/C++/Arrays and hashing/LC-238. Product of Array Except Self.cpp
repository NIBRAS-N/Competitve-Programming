/*
    Random approach:
        Using suffix and prefix array.
        Time complexity: O(n)
        Space complexity: O(n)
    Best Approach:
        using suffix and prefix variable
        Time complexity: O(n)
        Space Complexity: O(1)


*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long int
using vi = vector<int>;
using vll = vector<ll>;
#define pb push_back;
#define fo(i, a, b) for (ll i = (a); i < (b); i++)
#define w(x)  \
    ll x;     \
    cin >> x; \
    while (x--)

#define b() begin()
#define e() end()
#define cY cout << "YES\n"
#define cN cout << "NO\n"
#define cy cout << "Yes\n"
#define cn cout << "No\n"

// Space complexity O(n)

vi sol(vi abc)
{
    vi prefix;
    vi postfix(abc.size());
    vi ans(abc.size());
    prefix.push_back(abc[0]);
    fo(i, 1, abc.size())
    {
        prefix.push_back(prefix[i - 1] * abc[i]);
    }
    postfix[abc.size() - 1] = abc[abc.size() - 1];
    for (int i = abc.size() - 2; i >= 0; i--)
    {
        postfix[i] = postfix[i + 1] * abc[i];
    }
    ans[0] = postfix[1];
    ans[abc.size() - 1] = prefix[abc.size() - 2];
    for (int i = 1; i < abc.size() - 1; i++)
    {
        // cout<<prefix[i-1]<<" "<<postfix[i+1]<<endl;
        ans[i] = prefix[i - 1] * postfix[i + 1];
    }
    return ans;
}

// space complexity O(1). Output vector doesnt count as a space complexity
vi sol2(vi abc)
{
    ll prefix = 1;
    ll postfix = 1;
    vi res(abc.size());
    for (int i = 0; i < abc.size(); i++)
    {
        res[i] = prefix;
        prefix = prefix * abc[i];
    }
    for (int i = abc.size() - 1; i >= 0; i--)
    {
        res[i] = res[i] * postfix;
        postfix = postfix * abc[i];
    }
    return res;
}
int main()
{
    ll a;
    cin >> a;
    vi abc(a);
    fo(i, 0, a) cin >> abc[i];

    vi ans = sol2(abc);

    for (auto &i : ans)
    {
        cout << i << " ";
    }

    return 0;
}