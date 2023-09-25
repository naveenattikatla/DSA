#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
// 0/1 knapsackproblem
int knapsackproblem(vector<int>& w , vector<int>&p ,int n , int target){
	if(target <= 0 || n  <  0 )
		return 0;
	
	if(w[n] <= target){
	return max( p[n] + knapsackproblem(w,p,n-1 , target - w[n]) , knapsackproblem(w, p , n-1 ,target));
	}
	else{
		return knapsackproblem(w,p , n-1 , target);
	}
}
int main(){
	int n,target ;
	cin>>n>>target;
	vector<int> w(n);
	vector<int> p(n);
	for(int i =0 ;i < n;i++)
		cin>>w[i];
	for(int i =0 ;i < n;i++)
		cin>>p[i];
	int result = knapsackproblem(w,p,n - 1 ,target);
	cout<<"Maximum profit is "<<result<<endl;
	return 0;
} 