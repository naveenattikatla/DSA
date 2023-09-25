#include<iostream>
#include<vector>

using namespace std;
void bubbleSort(vector<int>& nums){
	for(int i = 0;i < nums.size() ; i++){
		for(int j = i+1 ; j < nums.size() - i ; j++){
			if(nums[i] > nums[j]){
				swap(nums[i],nums[j]);
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i =0 ; i < n ;i++)
		cin>>v[i];
	bubbleSort(v);
	for(int i = 0; i < v.size() ;i++){
		cout<<v[i]<<" ";
	}
		
	return 0;
}