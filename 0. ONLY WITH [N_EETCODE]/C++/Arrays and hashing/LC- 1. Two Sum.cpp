/*
    Brute Force:
        Time complexity: O(n*n)
        Space Complexity: O(1)

    Hashmap:
        Time complexity: O(n)
        Space Complexity: O(n)
*/



class Solution {
#define ll long long int
#define vll vector<int>
public:
 vll sol2(vll abc,ll targ){
    vll lol;
    unordered_map<ll,ll>cd;
    
    for(int i=0;i<abc.size();i++){
        ll num=abc[i];
        ll y = targ-abc[i];
        if(cd.find(y)!=cd.end()){
            lol.push_back(i);
            lol.push_back(cd[y]);
            break;
        }
        cd[abc[i]]=i;
    }
    return lol;
}

    vector<int> twoSum(vector<int>& nums, int target) {
        return sol2(nums,target);
    }
};