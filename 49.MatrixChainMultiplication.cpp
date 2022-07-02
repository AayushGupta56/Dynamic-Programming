int solve(int i,int j,vector<int>&arr,  vector<vector<int>>&dp){
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=1e9;
    for(int k=i;k<j;k++){
        //trying every partitioning that is possible btw i to j
        int steps=arr[i-1]*arr[k]*arr[j]+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
        if(steps<ans)ans=steps;
    }
    return dp[i][j]=ans;
}
int matrixMultiplication(vector<int> &arr, int n)
{
    // Write your code here.
//     vector<vector<int>>dp(n,vector<int>(n,-1));//recursion
//     return solve(1,n-1,arr,dp );//recursion
       
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=1;i<n;i++)dp[i][i]=0;//base case
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int ans=1e9;
            for(int k=i;k<j;k++){
                int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                if(steps<ans)ans=steps;
            }
            dp[i][j]=ans;
        }
    }
       return dp[1][n-1];
}
