class Solution {
public:
    

    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));

        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                int left=1,right=1;
                if(i-2>=0) left=nums[i-2];
                if(j<n) right=nums[j];

                for(int k=i;k<=j;k++){
                    
                    dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+left*nums[k-1]*right);
                }
                
            }
        }

        return dp[1][n];
    }
};
