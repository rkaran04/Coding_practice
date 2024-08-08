// rather than recursively trying all paths, we try finding ranges we can reach with a particular number of jumps. We start at 0, see the max we can jump 
// from here. Then we increase jump variable by 1. Now we have l=1, r=max from 0 as the range that can be reached with 1 jump. we iterate in l,r and see
// the farthest we can jump, jump=2 would then correspond to r+1,max . we procedd this way. 

class Solution {
public:

    
    int jump(vector<int>& nums) {
        int n=nums.size();

        int jumps=0;
        int l=0,r=0;
        
        while(r<n-1){
            int maxi=0;
            for(int j=l;j<=r;j++){
                maxi=max(maxi,j+nums[j]);
            }
            l=r+1;
            r=maxi;
            jumps++;
            
        }

        return jumps;

        
    }
};
