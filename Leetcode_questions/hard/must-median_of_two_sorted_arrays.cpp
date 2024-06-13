// https://www.youtube.com/watch?v=F9c7LpRZWVQ&ab_channel=takeUforward
// https://leetcode.com/problems/median-of-two-sorted-arrays/

// We try to find the elements from both arrays that will be in left halfo or right half.
// we do binary search on length of smaller array, the mid is the number of elements from left
// of smaller array that will lie in the left half. From total elements we will know till which
// element in 2nd array we have to add to left half. so we know all boundary elements. l1,l2,r1,r2


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);  //reverse order of arrays if first array larger, 
                                                              //solution is written for when first array is smaller

        int l=0,r=n-1;  //binary search
        int left=(n+m)/2; 
        int odd=1;
        if((n+m)%2==0) odd=0;
        double median=0;
        while(1){
            int mid=l+(r-l)/2;
            int l1=-1e9,l2=-1e9,r1=1e9,r2=1e9;   
            if(mid-1>=0) l1=nums1[mid-1];
            if(mid<n) r1=nums1[mid];
            if(left-mid-1>=0) l2=nums2[left-mid-1];
            if(left-mid<m) r2=nums2[left-mid];


            if(l1<=r2 && l2<=r1){
                if(odd) median=double(min(r1,r2));
                else median=(double)((double)max(l1,l2)+(double)min(r1,r2))/2.0;
                break;
            }
            else if(l1<=r2){
                l=mid+1;
            }
            else r=mid-1;
        }

        return median;
    }
};
