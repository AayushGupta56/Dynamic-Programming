int mod=1e9+7; 
int solve(int i,int k,vector<int>&arr,vector<vector<int >>&dp){
     
    
  
     if(i==0){
        if(k==0&&arr[0]==0)return 2;
        else if(k==0||k==arr[0]) return 1;
        else return 0;
    }
    if(dp[i][k]!=-1)return dp[i][k];  
     int pick=0;
    if(arr[i]<=k)  pick=solve(i-1,k-arr[i],arr,dp);
    int notpick=solve(i-1,k,arr,dp);
    return dp[i][k]=(pick+notpick)%mod; 
}
int targetSum(int n, int d, vector<int>& arr) {
    int total=0;
     for(int i=0;i<n;i++)total+=arr[i];
  //int s1;int s2=total-s1;
    //s1-s2=d;
    //s1-total+s1=d;
   int s1=(total-d)/2;
    if(total-d<0)return 0;
    if((total-d)%2)return 0;
    vector<vector<int >>dp(n,vector<int>(total,-1)); //for recursion
  
    return solve(n-1,s1,arr,dp);
 ///always use recursion///  
 ////tabulation/////
 //vector<vector<int >>dp(n,vector<int>(k+1,0));
//      for(int i=0;i<n;i++)dp[i][0]=1;
//     if(arr[0]<=k)
//     dp[0][arr[0]]=1;
    
//     for(int i=1;i<n;i++){
//         for(int target=0;target<k+1;target++){
            
//             int pick=0; int  notpick=dp[i-1][target];
//             if(arr[i]<=target)pick=dp[i-1][target-arr[i]];
          
//             dp[i][target]=pick+notpick;
            
//         }
//     }
//    return dp[n-1][k]; 
}
