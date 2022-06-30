int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
    if(i==0){
        return j;
    }
    if(j==0){
        return i;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i-1]==s2[j-1]){
        return dp[i][j]=solve(i-1,j-1,s1,s2,dp);
    }
    else {
        //for erasing
        int a=1+solve(i-1,j,s1,s2,dp);
        //for inserting
        int b=1+solve(i,j-1,s1,s2,dp);
        //for replacing
        int c=1+solve(i-1,j-1,s1,s2,dp);
        
        return dp[i][j]=min(a,min(b,c));
        
    }
    
}
int editDistance(string s1, string s2)
{
    int  n=s1.size();int m=s2.size();
  //  vector<vector<int>>dp(i+1,vector<int>(j+1,-1));//for recursion
  // return solve(n,m,s1,s2,dp);//for recursion
    
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++)dp[i][0]=i;////////////////
    for(int  j=0;j<=m;j++)dp[0][j]=j;//////////////
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             if(s1[i-1]==s2[j-1]){
         dp[i][j]=dp[i-1][j-1];
            }
         else {
        //for erasing
        int a=1+dp[i-1][j];
        //for inserting
        int b=1+dp[i][j-1];
        //for replacing
        int c=1+dp[i-1][j-1];
        
        dp[i][j]=min(a,min(b,c));
        
    }   
            
        }
    }
    return dp[n][m];
    
}
