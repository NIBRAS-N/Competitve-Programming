/*
    Stack, if num comes push in stack, if operator  comes apply to top 2 nums

    Time: O(n)
    Space: O(n)
*/


class Solution {
    #define ll long long int
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>abc;
        for(auto &i : tokens){
            if(i=="+"){
                ll x=abc.top();
                abc.pop();
                ll xx = abc.top();
                abc.pop();
                // cout<<x<<" "<<xx<<endl;
                abc.push(x+xx);
            }
            else if(i=="*"){
                ll x=abc.top();
                abc.pop();
                ll xx = abc.top();
                abc.pop();
                // cout<<x<<" "<<xx<<endl;
                abc.push(x*xx);
            }
            else if(i=="-"){
                ll x=abc.top();
                abc.pop();
                ll xx = abc.top();
                abc.pop();
                // cout<<x<<" "<<xx<<endl;
                abc.push(xx-x);
            }
            else if(i=="/"){
                ll x=abc.top();
                abc.pop();
                ll xx = abc.top();
                abc.pop();
                // cout<<x<<" "<<xx<<endl;
                abc.push(xx/x);
            }
            else{
                abc.push(stoi(i));
            }
        }

       return abc.top() ;
    }
};
