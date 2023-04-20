// Sorting character according to ascii order

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
int main()
{
    string a;
    cin >> a;
    ll ar[128] = {0};
    // ar[(int)'a']++;
    // cout << ar[97] << endl;
    for (int i = 0; i < a.size(); i++)
    {
        ar[(int)a[i]]++;
    }
    string b = "";
    for (int i = 0; i < 128; i++)
    {
        // cout << ar[i] << endl;
        b.append(ar[i], char(i));
    }
    cout << b << endl;
    return 0;
}