//problem link: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1348

//multiple array will be given..you have to answer for every array..

//Find a mamximum number that provide a same reminder if we devide every number of that array.

//Techniques:
//we need to know about congruences..[   if a≡b(modd)d  then d|(a−b)    ]
//substract the elements.[a1-a2,a2-a3,a3-a4]
//then find gcd of all the array
//answer link:  https://www.programmersought.com/article/86565255859/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,y,z;
    while(cin>>x && x){
        int f=0;
        while(cin>>y && y){
            int d=abs(x-y);
            if(d){
                if(f) f=__gcd(d,f);
                else f=d;
            }
            x=y;
        }
        cout<<f<<endl;
    }
}


