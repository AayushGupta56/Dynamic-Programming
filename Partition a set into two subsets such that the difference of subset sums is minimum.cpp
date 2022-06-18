int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
       if(n==1){return arr[0];}
    
    int total=0;int ans=1e9;
    for(int i=0;i<n;i++)total=total+arr[i];
    
    vector<vector<bool>>dp(n,vector<bool>(total+5,false));
    
    for(int i=0;i<n;i++)dp[i][0]=true;
    if(arr[0]<=total)dp[0][arr[0]]=true;
    
    for(int i=1;i<n;i++){
        for(int target=0;target<=total;target++){
            bool pick=false;bool notpick=false;
            
            if(arr[i]<=target)pick=dp[i-1][target-arr[i]];
            
            notpick=dp[i-1][target];
          //if we have made the target then we will take the difference of two subsets
            //because the target will be made of some numbers which will  make a unique subset 
            if(pick){
                int temp=abs(target-(total-target));
                ans=min(ans,temp);
            }
            
             if(notpick){
                int temp=abs(target-(total-target));
                ans=min(ans,temp);
           }
            
            dp[i][target]=pick|notpick;
            }
    }
    return ans;
}
