int solve(vector<int>& weight, vector<int> &value, int n, int maxWeight, vector<vector<int>>&dp){
    if(maxWeight<=0)return 0;
    if(n==0){
       if(weight[0]<=maxWeight)  return value[0];
        else return 0;
    }
    if(dp[n][maxWeight]!=-1)return dp[n][maxWeight];
    
    int pick=-1e9;
    if(weight[n]<=maxWeight)pick=value[n]+solve(weight,value,n-1,maxWeight-weight[n],dp);
    int notpick=solve(weight,value,n-1,maxWeight,dp);
    return dp[n][maxWeight]=max(pick,notpick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	  
     // vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1)); for recursion
    //  return solve(weight,value,n-1,maxWeight,dp);//for recursion
    ///////tabulation/////
     vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
    for(int i=weight[0];i<=maxWeight;i++)dp[0][i]=value[0];////////////
    
    for(int i=1;i<n;i++){
        for(int wt=0;wt<=maxWeight;wt++){
            int pick=-1e9;
            if(weight[i]<=wt)pick=value[i]+dp[i-1][wt-weight[i]];
            int notpick=dp[i-1][wt];
            dp[i][wt]=max(pick,notpick);
            
        }
    }
    return dp[n-1][maxWeight];
}
