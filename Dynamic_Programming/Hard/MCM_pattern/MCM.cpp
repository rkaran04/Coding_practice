// N sized array ---> N-1 matrices
class Solution{
public:
    
    int matrixMultiplication(int N, int arr[])
    {
        
        vector<vector<int>>dp(N,vector<int>(N,0));
        
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
                int mini=1e9;
                
                for(int k=i;k<j;k++){
                    int left=dp[i][k];
                    int right=dp[k+1][j];
                    mini=min(mini,left+right+arr[i-1]*arr[k]*arr[j]);
                }
                dp[i][j]=mini;
        
            }
        }
       return dp[1][N-1];
    }
};
