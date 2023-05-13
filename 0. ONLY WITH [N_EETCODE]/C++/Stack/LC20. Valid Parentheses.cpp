/*
    Basic stack
        Time complexity : O(N)
        space Complexity : O(N)
*/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> abc;
        map<char, char> cd;
        cd['}'] = '{';
        cd[']'] = '[';
        cd[')'] = '(';
        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                abc.push(s[i]);
            }
            else
            {
                //  cout<<cd[s[i]]<<" "<<abc.top()<<endl;
                if (abc.empty())
                    return false;
                else if (cd[s[i]] == abc.top())
                {

                    abc.pop();
                }
                else
                    return false;
            }
        }
        if (abc.empty())
            return true;
        else
            return false;
    }
};