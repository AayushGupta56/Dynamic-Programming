long long int houseRobber(vector<int>& arr)
{   
    if(arr.size()==1)return arr[0];
     int n=arr.size();
    // Write your code here.
    vector<long long>dp(n+5,-1);
    dp[0]=arr[0];
    for(int i=1;i<n;i++){
        long long pick=arr[i];
        if(i>1)pick+=dp[i-2];
        long long notpick=dp[i-1];
        dp[i]=max(pick,notpick);
     }
    long long  ans1=dp[n-2];
     vector<long long>dp2(n+5,-1);
    dp2[1]=arr[1];
    for(int i=2;i<n;i++){
        long long pick=arr[i];
        if(i>2)pick+=dp2[i-2];
        long long notpick=dp2[i-1];
        dp2[i]=max(pick,notpick);
     }
    long long ans2=dp2[n-1];
   // for(int i=0;i<n;i++)cout<<"DP["<<i<<"]"<<dp[i]<<endl;
    //  for(int i=0;i<n;i++)cout<<"dp2["<<i<<"]"<<dp2[i]<<endl;
   // cout<<ans1<<" JJ"<<ans2;
    return max(ans1,ans2);
}
