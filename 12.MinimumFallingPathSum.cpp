class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row=matrix.size();int col=matrix[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        for(int i=0;i<col;i++)dp[0][i]=matrix[0][i];
        
        for(int i=1;i<row;i++){
            for(int j=0;j<col;j++){
                
                if(j==0){
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
                }
                else if(j==col-1){
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                }
                else{
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j],min ( dp[i-1][j-1],dp[i-1][j+1]) ) ;
                }
                
            }
            
        }
        int ans=1e9;
        for(int i=0;i<col;i++){
            ans=min(ans,dp[row-1][i]);
        }
        return ans;
    }
};
