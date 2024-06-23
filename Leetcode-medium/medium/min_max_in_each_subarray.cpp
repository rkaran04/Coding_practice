// the actual question is: Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/?envType=daily-question&envId=2024-06-23

// we use deques to store elements to know min and max in each subarray. whenver we delete an element from subarray
// we delete it from deques also. When we add an element, we delete all less than that in max dq and then add it, and delete all 
// larger than than in  min dq and then add it.


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int n=nums.size();
        int i=0;
        int j=0;
  
        deque<int>maxi;
        deque<int>mini;
 
        int ans=0;
        while(i<n && j<n){

            while(!maxi.empty() && nums[j]>maxi.back()) maxi.pop_back();
            while(!mini.empty() && nums[j]<mini.back()) mini.pop_back();

            maxi.push_back(nums[j]);
            mini.push_back(nums[j]);

            while((maxi.front()-mini.front())>limit && (i<j)){
                
                if(maxi.front()==nums[i]) maxi.pop_front();
                if(mini.front()==nums[i]) mini.pop_front();
                i++;
            }


            ans=max(ans,j-i+1);
            j++;            
        }
        return ans;
    }
};
