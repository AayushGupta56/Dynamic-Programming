int lcs(string s, string t)
{
    //Write your code here
     int n=s.size();int m=t.size();
//     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));//recursion
//     return solve(s,t,n,m,dp);//recursion
    ///tabulaion////
     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
      
      for(int i=0;i<=n;i++)dp[i][0]=0;//for index -1 answer will be zero
      for(int i=0;i<=m;i++)dp[0][i]=0; //for index -1 answer will be zero 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){// if noth are equal then move both indices by -1
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                int a=dp[i][j-1];//moving index of only 2nd string
                int b=dp[i-1][j];//moving index of 1st string
                dp[i][j]=max(a,b);
            }  
        }  
    }
    
    
           return dp[n][m];//return the length of coomon subsequence
    ///for returning the common subsequence

    int len=dp[n][m];
    int index=len-1;
    string ans(len,'a');
    int i=n;int j=m;
    while(i>0&&j>0){
        if(ans[i-1]==ans[j-1]){
            ans[index]=ans[i-1];index--;
          i=i-1;j=j-1;
        }
        else if(dp[i][j-1]>dp[i-1][j]){
            j=j-1;
        }
        else{
            i=i-1;
        }
    }
    for(int i=0;i<len;i++)cout<<s[i];
  
}
