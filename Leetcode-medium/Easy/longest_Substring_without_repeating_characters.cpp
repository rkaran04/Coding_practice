// sliding window problem

// iterate, stop where you see first repetition, then bring window's left to the char just after the 
// previous occurence of the repeated character. Below code does it with deque, but can be done with 
// simple l and r variable. 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<char>dq;
        // unordered_map<char,int>mp;
        vector<int>mp(128,0);
        int ans=0;
        for(auto ch:s){
            mp[ch]++;
            dq.push_back(ch);
            if(mp[ch]>1){
                while(!dq.empty()){
                    char temp=dq.front();
                    dq.pop_front();
                    mp[temp]--;
                    if(temp==ch) break;
                    
                }
            }
            ans=max(ans,int(dq.size()));
        }
        return ans;
    }
};
