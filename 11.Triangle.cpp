int minimumPathSum(vector<vector<int>>& triangle, int n){
	
         int row=triangle.size()-1;int col=triangle[row].size()-1;
        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
        dp[0][0]=triangle[0][0];
         for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                int straight=triangle[i][j];int side=triangle[i][j];
               
                  if(j==0){straight+=dp[i-1][j];side=1e9;}
              else if(j==triangle[i].size()-1){straight+=1e9;side+=dp[i-1][j-1];}
                else {side+=dp[i-1][j-1];straight+=dp[i-1][j];}
                
                dp[i][j]=min(side,straight);
            }
        }
        int  ans=1e9;
        for(int i=0;i<=col;i++){
            ans = min(ans , dp[row][i] );
        }
        return ans;
}
