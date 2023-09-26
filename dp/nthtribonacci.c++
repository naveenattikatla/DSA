#include<iostream>
#include<vector>
using namespace std;
int nthTribonacci(int n,vector<int>& tabu){
	if(n<=2){
		return tabu[n];
	}
	int result = nthTribonacci(n-1,tabu)+nthTribonacci(n-2,tabu)+nthTribonacci(n-3,tabu);
	tabu.push_back(result);
	return result;
}
int main(){
	vector<int> tabu;
	tabu.push_back(0);
	tabu.push_back(1);
	tabu.push_back(1);
	int n;
	cin>>n;
	int result = nthTribonacci(n,tabu);
	cout<<result<<endl;
	return 0;
}