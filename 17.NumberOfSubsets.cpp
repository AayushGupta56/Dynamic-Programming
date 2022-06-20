 
int solve(int i,int k,vector<int>&arr,vector<vector<int >>&dp){
      if(dp[i][k]!=-1)return dp[i][k];  
    
    
     if(i==0){
        if(k==0&&arr[0]==0)return 2;
        else if(k==0||k==arr[0]) return 1;
        else return 0;
    }
 
     int pick=0;
    if(arr[i]<=k)  pick=solve(i-1,k-arr[i],arr,dp);
    int notpick=solve(i-1,k,arr,dp);
    return dp[i][k]=pick+notpick; 
}
int findWays(vector<int> &arr, int k)
{  int n=arr.size();
 
    // Write your code here.
  //  vector<vector<int >>dp(n,vector<int>(k+1,-1)); //for recursion
   
   // return solve(n-1,k,arr,dp);

 vector<vector<int >>dp(n,vector<int>(k+1,0));
if(arr[0]==0)dp[0][0]=2;
  else dp[0][0]=1;
    if(arr[0]!=0&&arr[0]<=k)
    dp[0][arr[0]]=1;
    
    for(int i=1;i<n;i++){
        for(int target=0;target<k+1;target++){
            
            int pick=0; int  notpick=dp[i-1][target];
            if(arr[i]<=target)pick=dp[i-1][target-arr[i]];
          
            dp[i][target]=pick+notpick;
            
        }
    }
   return dp[n-1][k]; 
} 
