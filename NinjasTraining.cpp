#include<bits/stdc++.h>
int solve(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp)  { 
       if(dp[day][last]!=-1)return dp[day][last];
    if(day==0){
             int ans=0;
       for(int i=0;i<=2;i++){
           if(i!=last){
               ans=max(ans,points[0][i]);
           }
       }
              return dp[day][last]=ans;
        
        
   }
   
    int ans=0;
    for(int i=0;i<=2;i++){
       //doing work which are valid
        if(i!=last){
            ans=max(ans,points[day][i]+solve(day-1,i,points,dp));
        }
        
    }
      return dp[day][last]=ans;
   

}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
   // vector<vector<int> >dp(n,vector<int>(4,-1));;
      vector<vector<int>> dp( n , vector<int> (4, -1)); 
    //memset(dp,-1,sizeof(dp));
    int ans=solve(n-1,3 ,points,dp);
    return ans;
}
