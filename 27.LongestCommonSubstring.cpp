int lcs(string &s, string &t){
	//	Write your code here.
    int n=s.size();int m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int ans=0;
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int i=0;i<=m;i++)dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                //we can only take just 1 back from both string as q is for substring
                ans=max(ans,dp[i][j]);
            }
            else dp[i][j]=0;
        }
    }
    return ans;
}
