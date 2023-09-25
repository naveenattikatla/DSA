#include<iostream>
#include<vector>

using namespace std;
void selectionSort(vector<int>& nums){
	for(int i = 0 ; i < nums.size() ;i++){
		int minindex = i ;
		for(int j = i+1 ; j < nums.size()  ; j++ ){
			if(nums[minindex] > nums[j]){
				minindex = j;
			}
		}
		swap(nums[minindex] , nums[i]);
	}
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i =0 ; i < n ;i++)
		cin>>v[i];
	selectionSort(v);
	for(int i = 0; i < v.size() ;i++){
		cout<<v[i]<<" ";
	}
		
	return 0;
}