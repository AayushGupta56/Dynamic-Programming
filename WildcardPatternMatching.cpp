#include<bits/stdc++.h>
bool match(string s1,string s2,int i,int j,vector<vector<int>>&dp){
        if(i<0 and j<0) {
           return true;
         }
       if(i<0 and j>=0) return false;
        if(i>=0 and j<0){
          for(int ii=0;ii<=i;ii++){
           if(s1[ii]!='*') return false;
         }
       return true;
        }
        if(dp[i][j]!=-1){
           return dp[i][j];
            }
         if(s1[i]==s2[j] || s1[i]=='?'){
                 return dp[i][j]= match(s1,s2,i-1,j-1,dp);
                  }
          if(s1[i]=='*'){
            return dp[i][j]=((match(s1,s2,i-1,j,dp))|(match(s1,s2,i,j-1,dp)));
           }
       return dp[i][j]=false;
}
bool wildcardMatching(string s1, string s2)
{
    // Write your code here.
       int n = s1.size()-1;  int m = s2.size()-1;
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
         return match (s1,s2,n,m,dp);
  
}
