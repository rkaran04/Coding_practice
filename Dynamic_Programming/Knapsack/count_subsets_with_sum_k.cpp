#define ll long long 
#define mod 1000000007
// learning: even sum 0 can be made in mutliple ways if there are 0s int the array. Just initialise 0,0 as 1. rest will be filled by the loop
int findWays(vector<int>& arr, int sum)
{
	int n=arr.size();
	vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                ll temp=0;
                if(arr[i-1]<=j){
                    temp=dp[i-1][j-arr[i-1]]+dp[i-1][j];
                }
                else temp=dp[i-1][j];
                dp[i][j]=temp%mod;
            }
        }
        
        return dp[n][sum];
}
