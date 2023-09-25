#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> factorsOfnumber(int n){
	vector<int > ans;
	for(int i = 1 ; i < ceil(sqrt(n)) ; i++){
		if(n % i == 0){
			ans.push_back(i);
			ans.push_back( n / i);
		}
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	vector<int> ans;
	ans = factorsOfnumber(n);
	for(int i = 0 ; i < ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	
	return 0;
}