// we keep l=0,r=0. we slide r till we find a substring encompassing all char in target string. Then we start moving l to right 
// and keep storing possible answers till the substr is valid. As soon as it becomes invalid, i.e., 1 char less than target, we again
// start moving r to right. We keep a count array of size 256(ascii) and add all char in target. So some char have positive count.
// We keep a var cnt=0, which will keep count of char we matched with target. We dec count if of char at r in string, if it was positive 
// before that means we matched a char. When we slide l, we increase count. If count becomes positive, we decrease cnt. So we need to move r now. 

class Solution {
public:
    string minWindow(string s, string t) {
        
        int ans=1e9;
        int ind=-1;

        int m=s.size();
        int n=t.size();
        

        int l=0;
        int r=0;

        vector<int>count(256,0);
        for(auto it: t) count[int(it)]++;
        int cnt=0;

        while(r<m){
            
            char curr=s[r];
            if(count[int(curr)]>0) cnt++;
            count[int(curr)]--;
            
            
            while(cnt==n){ //move l until str becomes invalid
                    if(ans>r-l+1) {
                        ans=r-l+1;
                        ind=l;}
                    
                    char curr2=s[l];
                    count[int(curr2)]++;
                    if(count[int(curr2)]>0) cnt--;
                    l++;
                }
            r++;
            
        }

        if(ind!=-1){
            return s.substr(ind,ans);
        }
        else return "";
    }
};
