
// O(n) O(1) solution: use the array itself as the hash. Ans range can be [1,n+1] only. If any number bigger than n is 
// present in the array a smaller number has to be missing. worst case we have 1 to n all there, so n+1 is the max possible.
// First make all negative entries and 0 to -n+2(useless to us). We iterate in array, if we find something between 1 and n we make 
// array[i-1] negative of what it is. while checking always take abs.



class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int n_1=0;
        for(int i=0;i<n;i++){
            if(nums[i]<0) nums[i]=0;
        }

        for(int i=0;i<n;i++){
            int ind=abs(nums[i])-1;
            if(ind<n && ind>=0){
                nums[ind]=-abs(nums[ind]);
                if(nums[ind]==0) nums[ind]=-n-2;
            }
            if(ind==n) n_1=1;
        }
        for(int i=0;i<n;i++){
            if(nums[i]>=0) return i+1;
        }
        return n+1;
        // return 0;
    }
};
