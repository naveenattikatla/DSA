#include<iostream>
#include<vector>
using namespace std;
int ncr(int n , int k,vector<vector<int> >& dp){
	if(n < k ){
		dp[n][k] = 0;
		return 0;
	}
	if(n == k ){
		dp[n][k] = 1;
		return 1;
	}
	if(dp[n][k]){
		return dp[n][k];
	}
	int result =  ncr(n-1 , k-1,dp ) + ncr(n-1 , k,dp);
	dp[n][k] = result;
	return result;
}
int main(){
	int n, k;
	cin>>n>>k;
	vector<int> v(k+1);
	vector<vector<int> > dp(n+1 , v);
	for(int i = 0 ; i <=n ; i++){
		dp[i][0] = 1;
	}
	int result = ncr(n,k,dp);
	cout<<result<<endl;
	return 0;
}