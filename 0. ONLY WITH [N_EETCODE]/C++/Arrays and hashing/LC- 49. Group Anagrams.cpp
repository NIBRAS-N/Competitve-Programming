/*
Approach 1: Using STL sort
    Time Complexity: O(M * Nlog(n)[for sorting] + Nlog(n)[for using map])
    Space Complexity: O(M * Nlog(n))

Approach 2: Using Normal Sort
    Time Complexity: O(M * N*26(sorting) + Nlog(n)[mapping])
    Space Complexity: O(M * N)
*/





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

void counting(string& s){
        int n=s.size();
        vector<int>mp(26,0);
        string ans;
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            //cout<<ans<<" "<<i<<" "<<mp[i]<<endl;
          ans.append(mp[i],i+'a');
        }
        s=ans;
}


vector<vector<string> > using_normal_sorting( vector<string> abc){
    map<string,vector<string> > cd;
    for(int i=0;i<abc.size();i++){
        string z=abc[i];
        counting(z);
        cd[z].push_back(abc[i]);
    }
    vector<vector<string> >ff;
    for(auto &i:cd){
        ff.push_back(i.second);
    }
    return ff;
}


vector<vector<string> > using_stl_sort( vector<string> abc){
    map<string,vector<string> > cd;
    for(int i=0;i<abc.size();i++){
        string z=abc[i];
        sort(z.begin(),z.end());
        cd[z].push_back(abc[i]);
    }
    vector<vector<string> >ff;
    for(auto &i:cd){
        ff.push_back(i.second);
    }
    return ff;
}

int main()
{
    vector<string> abc;
    ll a;
    cin>>a;
    for(int i=0;i<a;i++){
        string z;
        cin>>z;
        abc.push_back(z);
    }
    vector<vector<string> > cd;

    cd = using_stl_sort(abc);
    for(int i=0;i<cd.size();i++){
        for(auto &j:cd[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    
    cd = using_normal_sorting(abc);
    for(int i=0;i<cd.size();i++){
        for(auto &j:cd[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}