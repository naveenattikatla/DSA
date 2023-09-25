#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int binarySearch(vector<int>& nums,int target){
	int start = 0 ;
	int end = nums.size() - 1;
	while(start <= end){
		int mid = floor(start + end ) / 2;
		if(nums[mid] == target){
			return mid;
			
		}
		else{
			if(nums[mid] <= target){
				start = mid+1;
			}else{
				end = mid - 1;
			}
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
	sort(v.begin(),v.end());
	int result = binarySearch(v,target);
	cout<<result<<endl;
		
	return 0;
}