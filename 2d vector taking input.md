# 2d vector taking input method:

- A 2d vector which have `a` number  rows and `only one` coloumn . That coloumn have 2 values. 
- scenario is:
    - [  
        [1,2]  -> 0th row  
        [2,3]  -> 1st row   
        [3,4]  -> 3rd row   
        [1,3]  -> 4th row  
      ]

- 1st way of taking input
    - ```C++
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
            ll a;
            cin >> a;
            vector<vector<pair<int, int>>> abc(a, vector<pair<int, int>>(1));
            for(int i=0;i<a;i++){
                vector< pair<int,int> >cd;
                for(int j=0;j<1;j++ ){
                    ll a,b;
                    cin>>a>>b;
                    cd.push_back({a,b});
                }
                abc[i]=cd;
            }
            

            for (auto &i : abc)
            {
                for (auto &j : i)
                {
                    cout << j.first << " " << j.second << endl;
                }
            }
            
            return 0;
        }
      ```

    - 2nd way
        ```C++
            #include <iostream>
            #include<bits/stdc++.h>
            using namespace std;
            #define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
            #define ll long long int
            using vi = vector <int>;
            using vll = vector <ll>;
            #define pb push_back;
            #define fo(i,a,b) for(ll i=(a);i<(b);i++)
            #define w(x)            ll x; cin>>x; while(x--)

            #define b() begin()
            #define e() end()
            #define cY cout<<"YES\n"
            #define cN cout<<"NO\n"
            #define cy cout<<"Yes\n"
            #define cn cout<<"No\n"
            int main()
            {
                
                ll a;
                cin>>a;
                vector<vector<int>>abc(a,vector<int>(2));

                for(int i=0;i<a;i++){
                    vector<int>ff;
                    for(int j=0;j<2;j++){
                        ll a;
                        cin>>a;
                        ff.push_back(a);
                        //Or simply we can use this:
                        // cin>>abc[i][j];
                    }
                    abc[i]=ff;
                }
                for(auto &i:abc){
                    for(auto &j:i){
                        cout<<j<<" ";
                    }
                    cout<<endl;
                }
                
                return 0;
            }
        ```