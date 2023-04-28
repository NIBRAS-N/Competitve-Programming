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
    w(t)
    {
        int n, k;
        cin >> n >> k;
        bool f = 1;
        for (int i = 0; i <= 100; i++)
        {
            int j = n - i;
            int temp = (i * (i - 1)) / 2 + (j * (j - 1)) / 2;
            if (temp == k)
            {
                cout << "YES" << endl;
                for (int z = 1; z <= i; z++)
                {
                    cout << "1 ";
                }
                for (int z = 1; z <= n - i; z++)
                {
                    cout << "-1 ";
                }
                cout << endl;
                f = false;
                break;
            }
        }
        if (f == true)
            cout << "NO" << endl;
    }
    return 0;
}