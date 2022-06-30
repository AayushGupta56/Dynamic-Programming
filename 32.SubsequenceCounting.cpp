int mod=1e9+7;
int solve(int i,int j,string&s1,string &s2,vector<vector<int>>&dp){
      if(j==0)return 1;///////always j==0 will  come first
    if(i==0)return 0;
  
    
    
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i-1]==s2[j-1]){
        return dp[i][j]=solve(i-1,j-1,s1,s2,dp)+solve(i-1,j,s1,s2,dp);
    }
    else{
        return dp[i][j]=solve(i-1,j,s1,s2,dp);
    }
}

// i j j j j j m
// i
// i
// i
// n
int subsequenceCounting(string &s1, string &s2, int s1size, int s2size) {
    // Write your code here.
    int n=s1.size();int m=s2.size();
    //vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //return solve(n,m,s1,s2,dp);
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
  
    for(int j=0;j<=m;j++)dp[0][j]=0;//always write 0 one first as o will override 1
                                   //if we write this after i line
      for(int i=0;i<=n;i++)dp[i][0]=1;//when s2 is empty i.e j=0 then its a way so 1
    for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
     if(s1[i-1]==s2[j-1]){
         //once taking ith position and once not taking ith positon
         dp[i][j]=((dp[i-1][j-1]%mod)+(dp[i-1][j]%mod))%mod;
    }
     else{
         //no option we have to shift ith position
         dp[i][j]=dp[i-1][j];
    }
  
    
    }
    }
    return dp[n][m];
} 
