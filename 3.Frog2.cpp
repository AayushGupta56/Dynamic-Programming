#include<bits/stdc++.h>
using namespace std;
#define N 10000000
int dp[N];
int solve(int arr[],int n,int k,int i){
     if(i==0){return 0;}
      if(dp[i]!=-1)return dp[i];
 
   int cost=INT_MAX;
    for(int j=1;j<=k;j++){
       if(i-j>=0){
      cost=min(cost,solve(arr,n,k,i-j)+abs(arr[i]-arr[i-j])  );
  }
}
   return dp[i]=cost;
 
 
}
int main(){
	memset(dp,-1,sizeof(dp));
   int n,k;cin>>n>>k;
   int arr[n];
   for(int i=0;i<n;i++){cin>>arr[i];}
    cout<<solve(arr,n,k,n-1);
 
 
 
}
