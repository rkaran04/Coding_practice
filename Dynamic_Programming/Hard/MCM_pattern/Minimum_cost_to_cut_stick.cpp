class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());

        int m=cuts.size(); 

        int  dp[m+1][m+1];
        memset(dp,0,sizeof(dp));

        for(int i=m-2;i>=1;i--){
            for(int j=i;j<=m-2;j++){
                int temp=1e9;
                for(int k=i;k<=j;k++){
                    temp=min(temp,dp[i][k-1]+dp[k+1][j]);
                }
                // cout<<i<<" "<<j<<endl;
                dp[i][j]=temp+cuts[j+1]-cuts[i-1];
            }
        }
        return dp[1][m-2];
    }
};
