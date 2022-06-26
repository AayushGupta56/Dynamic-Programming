#include<bits/stdc++.h>
string shortestSupersequence(string s, string t)
{
  int n=s.size();int m=t.size();
 
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
    int i=n;int j=m;string ans;
    while(i>0&&j>0){
        if(s[i-1]==t[j-1]){
            ans.push_back(s[i-1]);//0 based indexing thats why s[i-1] and not s[i]
            i--;j--;
        }
       else if(dp[i-1][j]>dp[i][j-1]){
            ans.push_back(s[i-1]);
            i--;
        }
        else {
            ans.push_back(t[j-1]);
            j--;
        }
    }
        while(i>0){ans.push_back(s[i-1]);i--;}
        while(j>0){ans.push_back(t[j-1]);j--;}
      reverse(ans.begin(),ans.end());//    answer is in reverse order
        return ans;
        
    
    
           
}
