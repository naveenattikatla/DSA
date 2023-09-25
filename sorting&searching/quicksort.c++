#include<iostream>
#include<vector>
using namespace std;
int pivoting(vector<int>& nums,int start, int end){
	int j = start - 1 ;
	int pivotE = nums[end];
	for(int i = start ; i < end ; i++){
		if(nums[i] <= pivotE){
			j++;
			swap(nums[i],nums[j]);
		}
	}
	j++;
	int temp = nums[j];
	nums[j] = pivotE;
	nums[end] = temp;
	
	return j;	
}

void quicksort(vector<int>& nums,int start , int end){
	if(start < end){
		int pivot = pivoting(nums,start , end);
		quicksort(nums, start , pivot-1);
		quicksort(nums,pivot+1,end);
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0 ; i < n ;i++)
		cin>>v[i];
	quicksort(v,0,n-1);
	for(int i= 0 ; i < n;i++){
		cout<<v[i]<<" ";
	}
	
	return 0;
}