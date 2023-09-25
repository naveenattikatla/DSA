#include<iostream>
#include<vector>
using namespace std;
vector<int> dp;
int fibo(int n){
	if(n < dp.size()){
		return dp[n];
	}
	int result =  fibo(n-1)+fibo(n-2);
	dp.push_back(result);
	return result;
}
int main(){
	int n;
	cin>>n;
	dp.push_back(0);
	dp.push_back(1);
	int ans = fibo(n);
	cout<<n<<" th fibonacci number "<<ans<<endl;
	return 0;
}