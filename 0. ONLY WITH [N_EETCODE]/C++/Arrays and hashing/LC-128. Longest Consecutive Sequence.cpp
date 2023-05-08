/*
    Approach 1:
        Time complexity: O(N logN)
        Space Complexity: O(N)
    Approach 2:[Using set]***[learn different use of set]

        Time complexity: O(N)
        Space Complexity: O(N)

*/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        map<int, int> abc;
        for (int i = 0; i < nums.size(); i++)
        {
            abc[nums[i]]++;
        }

        vector<int> ff;
        for (auto i = abc.begin(); i != abc.end(); i++)
        {
            ff.push_back(i->first);
        }
        int cnt = 1;
        int ans = -1;
        if (ff.size() == 1)
            return 1;
        for (int i = 1; i < ff.size(); i++)
        {
            if (ff[i - 1] == ff[i] - 1)
                cnt++;
            else
            {

                cnt = 1;
            }
            ans = max(cnt, ans);
        }
        ans == -1 ? ans = 1 : ans = ans;
        return ans;
    }
};

// Approach 2: different use of set

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> cd;
        for (auto &i : nums)
        {
            cd.insert(i);
        }
        int length = 1;
        int res = 0;
        for (auto &i : cd)
        {

            // this is the start of new sequence.
            // If i-1 is not found in the set, that means its the new sequence
            if (!cd.count(i - 1))
            {
                length = 1;
                while (cd.find(i + length) != cd.end())
                {
                    length++;
                }
            }
            res = max(res, length);
        }
        // cout<<res<<endl;
        return res;
    }
};