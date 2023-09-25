#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> merging(vector<int>& nums,int value){
	if(nums.size() == 0 || nums.front() <= value){
		nums.push_back(value);
		return nums;
	}else{
		int last = nums.back();
		nums.pop_back();
		vector<int> ans = merging(nums,value);
		ans.push_back(last);
		return ans;
	}
}
vector<int> sorting(vector<int>& nums){
	if(nums.size() == 1){
		return nums;
	}
	int last = nums.back();
	nums.pop_back();
	vector<int> ans = sorting(nums);
	return merging(ans , last);
	
}
int main(){
	int n ;
	cin>>n;
	vector<int> v(n);
	for(int i =0 ;i < n;i++)
		cin>>v[i];
	vector<int> ans = sorting(v);
	for(int i = 0 ; i < ans.size();i++)
		cout<<ans[i]<<" ";
	return 0;
}