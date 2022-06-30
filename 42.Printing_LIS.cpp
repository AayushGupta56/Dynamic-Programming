#include<bits/stdc++.h>
int solve(int arr[],int i,int last,int n,vector<vector<int>>&dp){
     if(i==n)return 0;
    if(dp[i][last+1]!=-1)return dp[i][last+1];
    int pick=-1e9;
    if(last==-1||arr[i]>arr[last])pick=1+ solve(arr,i+1,i,n,dp);
    int notpick=solve(arr,i+1,last,n,dp);
    return max(pick,notpick);
    return dp[i][last+1]=max(pick,notpick);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
  // vector<vector<int>>dp(n,vector<int>(n+1,-1));
  // return  solve(arr,0,-1,n,dp);
      vector<int>dp(n,1);int length=0;int lastindex=0;
      vector<int>hash(n);
    for(int i=0;i<n;i++)hash[i]=i;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){//checking if any of previous element can be combined
            if(arr[j]<arr[i]&&1+dp[j]>dp[i]){
                 dp[i]=1+dp[j];
                   hash[i]=j; 
                
            }
        }
         
        if(dp[i]>length){
            length =dp[i];
            lastindex=i;
        }
    }
    vector<int>temp;
    temp.push_back(arr[lastindex]);
    while(hash[lastindex]!=lastindex){
        lastindex=hash[lastindex];
        temp.push_back(arr[lastindex]);
    }
    reverse(temp.begin(),temp.end());
    for(auto:it)cout<<it<<" ";
    return length;
}
