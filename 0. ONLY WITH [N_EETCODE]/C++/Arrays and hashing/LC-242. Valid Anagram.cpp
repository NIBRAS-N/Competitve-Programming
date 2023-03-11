/*
    Hashing and Mapping:
        TIME COMPLEXITY: O(n)
        SPACE COMPLEXITY: o(1)

    SORTING
        TIME COMPLEXITY: O(n)
        SPACE COMPLEXITY: o(1)
*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t){
            return true;
        }
        return false;

    }
};