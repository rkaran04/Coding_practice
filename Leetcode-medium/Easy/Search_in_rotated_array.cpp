
// Here the entire array is not sorted. one way is to identify pivot with BS(Binary search), then apply BS in both sorted arrays.
// Other method(Striver): With respect to a mid, either the left or right half will be sorted. We first identify which half, then we see if the 
// element can be there by sinmply checking the extremes in that sorted portion. if yes then, other is eliminated, else the sorted part is eliminated.


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0,mid,right=n-1;
        while(left<=right){
            mid=(left+right)/2;
            if(target==nums[mid])return mid;
          // if left half sorted
            if(nums[left]<=nums[mid]){
                if(target<=nums[mid] && target>=nums[left]){
                    right=mid-1;
                }
                else left=mid+1;
            }
              // if right half sorted
            else{
                if(target<=nums[right] && target>=nums[mid])left=mid+1;
                else right=mid-1;
            }
        }
        return -1;
    }
};
