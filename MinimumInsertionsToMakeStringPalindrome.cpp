#include<bits/stdc++.h>
int minInsertion(string &s)
{
   string t=s;
    reverse(t.begin(),t.end());
    //the longest subsequence in s and t will be ans because only order palindromic subsequence will not change after reversing if it is not palindromic subseq then it will not remain common as order will change
    int n=s.size();int m=t.size();
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
    
    int ans=s.size()-dp[n][m];//ans will be size of string- lenghth of lps
    return ans;
            
}
