// once iterate from left and then from right. while iterating from left, keep a count of open and closed
// if open=close, then valid, if close greater then reset both to 0. This will miss some strings.(eq think about "(()" Do the 
// opposite from right.  there will be cases where this will not see few strings at all in both the cases, 
// but it becoz there are better cases. 



class Solution {
public:

    int longestValidParentheses(string s) {
        int ans=0;
        int open=0,close=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') open++;
            else close++;
            if(open==close) ans=max(ans,open+close);
            if(close>open) open=close=0;
        }
        open=close=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(') open++;
            else close++;
            if(open==close) ans=max(ans,open+close);
            if(close<open) open=close=0;
        }
        return ans;
    }
};
