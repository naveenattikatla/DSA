#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void merging(vector<int>& nums , int start , int mid , int end){
	int n1 = mid -  start  + 1;
	int n2 = end - mid ;
	vector<int> v1;
	vector<int> v2;
	
	for(int i = start  ; i <=mid ;i++){
		v1.push_back(nums[i]);
	}
	v1.push_back(INT_MAX);
	for(int i = mid+1  ; i <=end ;i++){
		v2.push_back(nums[i]);
	}
	v2.push_back(INT_MAX);
	vector<int> v3;
	int i = 0 ;
	int j = 0;
	for(int k = 0 ; k < n1+n2;k++){
		if(v1[i] > v2[j]){
			v3.push_back(v2[j]);
			j++;
		}
		else{
			v3.push_back(v1[i]);
			i++;
		}
	}
	int k = 0;
	for(i = start ;i <=end ;i++){
		nums[i] = v3[k];
		k++;
	}
	return ;
	
}
void mergeSort(vector<int>& nums,int start ,int end){
	if(start < end){
		int mid = floor((start + end )/ 2);
		mergeSort(nums , start , mid);
		mergeSort(nums, mid+1 , end);
		merging(nums, start , mid , end);
	}
	return ;
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i =0 ; i < n ;i++)
		cin>>v[i];
	mergeSort(v, 0 , n - 1);
	for(int i = 0; i < v.size() ;i++){
		cout<<v[i]<<" ";
	}
		
	return 0;
}