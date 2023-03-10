/*
Approach1:
    Greedy
    Time complexity: O(n^2)
    Space complexity:O(1)
*/
/*
Approach 2:
    Sorting
    Time Complexity: O(n log(n) )
    Space Complexity: O(1)
*/
/*
Approach 3:
    Hashing/Map
    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>abc;
        for(int i=0;i<nums.size();i++){
            if(abc[nums[i]]>0) return true;
            abc[nums[i]]++;

        }
        return false;
    }
};