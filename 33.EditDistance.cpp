int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
    if(i==0){
   return j;//if ith string i.e if s1 is exhausted(i==0) then to make s1 to s2 we will insert 
        //all the  charcters left of s2 in s1 which will be j as j characters are left 
    }
    if(j==0){
        return i;//if jth i.e if s2 is exhausted(j==0) then to make s1 to s2 we will delete 
        //all the  characters left of s1 so it will become s2
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i-1]==s2[j-1]){
        return dp[i][j]=solve(i-1,j-1,s1,s2,dp);
    }
    else {
        //if  erasing ith character then we have to move to i-1 to search for s2[j]
        int a=1+solve(i-1,j,s1,s2,dp);
        //if inserting jth charcter then we have to go search for j-1th character
        int b=1+solve(i,j-1,s1,s2,dp);
        //if we replace then ith charcter is gone as well as jth character is gone so we start searching for j-1th char at i-th index
        int c=1+solve(i-1,j-1,s1,s2,dp);
        
        return dp[i][j]=min(a,min(b,c));
        
    }
    
}
int editDistance(string s1, string s2)
{
    int  n=s1.size();int m=s2.size();
  //  vector<vector<int>>dp(i+1,vector<int>(j+1,-1));//for recursion
  // return solve(n,m,s1,s2,dp);//for recursion
    
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++)dp[i][0]=i;/////if ith string i.e if s1 is exhausted(i==0) then to make s1 to s2 we will insert 
    //all the  charcters left of s2 in s1 which will be j as j characters are left 
    for(int  j=0;j<=m;j++)dp[0][j]=j;////if jth i.e if s2 is exhausted(j==0) then to make s1 to s2 we will delete all the 
    // characters left of s1 so it will become s2
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             if(s1[i-1]==s2[j-1]){
         dp[i][j]=dp[i-1][j-1];
            }
         else {
          //if  erasing ith character then we have to move to i-1 to search for s2[j]
        int a=1+dp[i-1][j];
        //if inserting jth charcter then we have to go search for j-1th character
        int b=1+dp[i][j-1];
       //if we replace then ith charcter is gone as well as jth character is gone so we start searching for j-1th char at i-th index
        int c=1+dp[i-1][j-1];
        
        dp[i][j]=min(a,min(b,c));
        
    }   
            
        }
    }
    return dp[n][m];
    
}
