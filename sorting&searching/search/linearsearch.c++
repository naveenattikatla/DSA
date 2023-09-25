#include<iostream>
#include<vector>
using namespace std;
int linearSearch(vector<int>& nums,int target){
	for(int i = 0 ; i < nums.size() ; i++){
		if(nums[i] == target){
			return i ;
		}
	}
	return -1;
}
int main(){
	int n,target;
	cin>>n>>target;
	vector<int> v(n);
	for(int i =0 ; i < n ;i++)
		cin>>v[i];
	int result = linearSearch(v,target);	
	cout<<result<<endl;
	return 0;
}