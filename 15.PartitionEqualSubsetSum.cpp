bool solve(int i,int current,int total,int n,vector<int>arr,vector<vector<int>>&dp){
   if(current*2==total)return true;
    if(i==0){
        if((current+arr[i])*2==total)return true;
        else return false;
    }
     
    if(dp[i][current]!=-1)return dp[i][current];
    bool pick=false;bool notpick=false;
  if(2*(current+arr[i])<=total)pick=  solve(i-1,current+arr[i],total,n,arr,dp);
      notpick=solve(i-1,current,total,n,arr,dp);
     return dp[i][current]= pick|notpick;
    
    
}

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
   // vector<vector<int>>dp(n,vector<int>(total/2,-1));
    int total=0;
    for(int i=0;i<n;i++)total+=arr[i];
    
    if(total%2==1)return false;
    total=total/2;
    vector<vector<bool>>dp(n,vector<bool>(total+5,false));
    for(int i=0;i<n;i++)dp[i][0]=true;
        if(arr[0]<=total)dp[0][arr[0]]=true;
              
         for(int i=1;i<n;i++){///////////don't start loop with 0
             for(int target=1;target<=total;target++){
                 bool pick=false;bool notpick=false;
                 if(target-arr[i]>=0)pick=dp[i-1][target-arr[i]];
                 notpick=dp[i-1][target];
                 dp[i][target]=pick|notpick;
             }
         }  
   
    return dp[n-1][total];
}
