#include<bits/stdc++.h>
int solve(int i,vector<int>&height,int dp[]){
    if(i==1)return 0;
    if(dp[i]!=-1)return dp[i];
    
    int left=INT_MAX;int right=INT_MAX;/////dont initialise with 0
    ///taking that we are coming from i-1th stair
    left=abs(height[i]-height[i-1])+solve(i-1,height,dp);
    if(i>=3){
          ///taking that we are coming from i-2th stair
         right=abs(height[i]-height[i-2])+solve(i-2,height,dp);
    }
    return dp[i]=min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int dp[100005];
    memset(dp,-1,sizeof(dp));
    vector<int>v(heights.size()+2);
    for(int i=0;i<heights.size();i++){
        v[i+1]=heights[i];
    }
    return solve(n,v,dp);
    
    
}
