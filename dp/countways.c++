#include<iostream>
#include<vector>
using namespace std;

int countways(int n,vector<int>& dp){
	if(n < dp.size()){
		return dp[n];
	}
	int numways = countways(n-1 ,dp) + countways(n-2 ,dp);
	dp.push_back(numways);
	return numways;
}
int main(){
	int n;
	cin>>n;
	vector<int> dp;
	dp.push_back(1);
	dp.push_back(1);
	int numOfways = countways(n,dp);
	cout<<numOfways<<endl;
	return 0;
}