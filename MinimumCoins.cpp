#include<bits/stdc++.h>
int solve(vector<int>&arr,int x,int n,vector<vector<int>>&dp){
   // if(x<=0)return 0;
    if(n==0){
        if(x%arr[0]==0)return x/arr[0];
        
        else return 1e9;
    }
    if(dp[n][x]!=-1)return dp[n][x];
    int pick=1e9;
    if(arr[n]<=x)pick=1+solve(arr,x-arr[n],n,dp);
    int notpick=0+solve(arr,x,n-1,dp);
return dp[n][x]=min(pick,notpick);
   // return pick+notpick;
    
}
int minimumElements(vector<int> &arr, int x)
{
             int n=arr.size();
           vector<vector<int>>dp(n,vector<int>(x+1,-1));
           int ans= solve(arr,x,n-1,dp);
              if(ans>=1e9)return -1;
              else return ans;
              
            ///tabulation;//////
    
//     vector<vector<int>>dp(n,vector<int>(x+1,0));
//     for(int i=0;i<=x;i++){
//         if(i%arr[0]==0)dp[0][i]=i/arr[0];
//         else dp[0][i]=1e9;
//     }
 
//     for(int i=1;i<n;i++){
//         for(int target=0;target<=x;target++){
//             int pick=1e9;
//             if(arr[i]<=target)pick=1+dp[i][target-arr[i]];
//             int notpick=dp[i-1][target];
            
//             dp[i][target]=min(pick,notpick);
            
//         }
//     }
//     if( dp[n-1][x]>=1e9) return -1;
//     else return dp[n-1][x];
}
