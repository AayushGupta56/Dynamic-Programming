int dp[51][51][51];
int helper(int i,int j1,int j2,vector<vector<int>> &a,int n,int m){
    if(j1<0 or j2<0 or j1>=m or j2>=m)
        return -1e9;
    if(i==n-1){
        if(j1==j2) return a[i][j1];
        else return a[i][j1]+a[i][j2];
    }
    
    if(dp[i][j1][j2]!=-1)
        return dp[i][j1][j2];
    
    int maxi=0,k;
    if(j1==j2) k=a[i][j1];
    else k=a[i][j1]+a[i][j2];
    
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
            maxi=max(maxi,k+helper(i+1,j1+dj1,j2+dj2,a,n,m));
        }
    }
    
    return dp[i][j1][j2]=maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    memset(dp,-1,sizeof(dp));
    return helper(0,0,c-1,grid,r,c);
}
