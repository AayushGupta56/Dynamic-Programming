#include<bits/stdc++.h>
int solve(int i,vector<int>nums,vector<int>&dp){
    if(i==0)return nums[0];
    if(i<0)return 0;
    if(dp[i]!=-1)return dp[i];
    //take
    int a=nums[i]+solve(i-2,nums,dp);
    //not take
    int b=0+solve(i-1,nums,dp);
    return dp[i]= max(a,b);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size(); vector<int> dp(n,-1);
    return solve(n-1,nums,dp);
}
