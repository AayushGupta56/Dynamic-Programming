#include<bits/stdc++.h>
int solve(string&s,string&t,int n,int m, vector<vector<int>>&dp){
    
     if(n==0||m==0){
         return 0;
     } 
    if(dp[n][m]!=-1)return dp[n][m];
    if(s[n-1]==t[m-1]){
         dp[n][m]=1+solve(s,t,n-1,m-1,dp);
    }
    else{
        int a= solve(s,t,n,m-1,dp);//moving index of only 2nd string
        int b=solve(s,t,n-1,m,dp);//moving index of 1st string
        return dp[n][m]=max(a,b);
    }
}
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
    
    return dp[n][m];
    
    
    
    
}
