
// https://leetcode.com/problems/sort-colors/?envType=daily-question&envId=2024-06-12


// 1)- use three pointers one for left end , one for right end and one for iteration.
// 2)-if you see 0 swap it with left pointer and increase the left pointer by one.
// 3)-if you see 2 swap it with right pointer and decrease right pointer by one.
// 4)-else increase the iterating pointer.
// 5)-run this loop while the iterating pointer<=right pointer.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if (nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
};
