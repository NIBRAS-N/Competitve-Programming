Link: https://leetcode.com/contest/weekly-contest-389/problems/existence-of-a-substring-in-a-string-and-its-reverse/

## How to print all substring using for loop- take idea from this code:
```C++
class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string>abc;
        for(int i=0;i<s.size();i++){
            for(int l=2;l<=s.size()-i;++l){
                // cout<<s.size()-i<<" "<<i<<" "<<l<<endl;
                // cout<<s.substr(i,l)<<endl;
                abc.insert(s.substr(i,l));
            }
        }
        
        reverse(s.begin(),s.end());
        // cout<<s<<endl;
        for(int i=0;i<s.size();i++){
            for(int l=2;l<=s.size()-i;++l){
                
                string temp = s.substr(i,l);
                // cout<<abc.count(temp)<<" "<<temp<<endl;
                if(abc.find(temp) != abc.end()) return true;
            }
        }
        return false;
    }
};
```
