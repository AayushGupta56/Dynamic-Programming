int mod=1e9+7;
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n,vector<int>(m,-1));
   
        dp[0][0]=1;
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1){dp[i][j]=0;continue;}///change
            int up=0;int left=0;
            if(i==0&&j==0){dp[i][j]=1;continue;}
            if(i>0 )up=dp[i-1][j]%mod;
            if(j>0 )left=dp[i][j-1]%mod;
            dp[i][j]=(up+left)%mod;
            
        }
        }
        return dp[n-1][m-1];
}
