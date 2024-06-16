
// https://www.youtube.com/watch?v=UuiTKBwPgAo&ab_channel=NeetCode
// keep two pointers at both ends. get their volume, then move the smaller one. why? because for the smaller one
// even if we find a bigger other height, we will lawys have min as smaller one and ifcourse with lesser width.
// so its better to move away from smaller, and keep the taller, as we might find a taller bar than the current bigger,
// which may give more area with less with. 



class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=0;
        
        int l=0;
        int r=n-1;

        while(l<r){
            ans=max(ans,min(height[l],height[r])*(r-l));
            if(height[l]<height[r]) l++;
            else r--;
        }


        return ans;
    }
};
