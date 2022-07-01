#include<bits/stdc++.h>
long long solve(int arr[],int x,int n,vector<vector<long long>>&dp){
     //if(x==0)return 0;
    if(n==0){
        if(x%arr[0]==0)return 1;
        
        else return 0;
    }
    if(dp[n][x]!=-1)return dp[n][x];
    long long pick=0;
    if(arr[n]<=x)pick=solve(arr,x-arr[n],n,dp);
    long long notpick=0+solve(arr,x,n-1,dp);
return dp[n][x]=pick+notpick;
   // return pick+notpick;
    
}
long countWaysToMakeChange(int *arr, int n, int x)
{
    
                 
              vector<vector<long long>>dp(n,vector<long long>(x+1,-1));
             long long ans= solve(arr,x,n-1,dp);
             
             return ans;
    ///tabulation;//////
    
//     vector<vector<long long>>dp(n,vector<long long >(x+1,0));
//     for(int i=0;i<=x;i++){
//         if(i%arr[0]==0)dp[0][i]=1;
//         else dp[0][i]=0;
//     }
 
//     for(int i=1;i<n;i++){
//         for(int target=0;target<=x;target++){
//             long long pick=0;
//             if(arr[i]<=target)pick=dp[i][target-arr[i]];
//             long long  notpick=dp[i-1][target];
            
//             dp[i][target]=pick+notpick;
            
//         }
//     }
//   return dp[n-1][x];
}
