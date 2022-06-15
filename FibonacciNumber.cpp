class Solution {
public:
     int solve(int n,int dp[]) {
        if(n<=1){
            return dp[n]=n;
        }
         
        if(dp[n]!=-1)return dp[n];
         
        dp[n]=solve(n-1,dp)+solve(n-2,dp);
         
        return dp[n];
    }
    int fib(int n) {
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        int ans=solve(n,dp);
       return ans;
    }
};
