// https://leetcode.com/problems/dungeon-game/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // dp matrix will store the maximum min power loss, i.e., abs(dp)+1 is the energy required to gp from that
        // cell to the bottom right. Also, if max min power is positive, that means from that cell we do not 
        // need any extra power to go the end. 

        int m=dungeon.size();
        int n=dungeon[0].size();
        int dp[m+1][n+1];
        memset(dp,-2e5+1,sizeof(dp));

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) {
                    // last cell
                    dp[i][j]=dungeon[i][j];
                    continue;
                    }
                
                int curr=dungeon[i][j]+max(dp[i+1][j],dp[i][j+1]);
                curr=min(0,curr); //put 0 if positive

                dp[i][j]=curr;                
            }
        }
        return abs(dp[0][0])+1;
    }
};
