#include<iostream>
#include<vector>

using namespace std;
void insertionSort(vector<int>& nums){
	for(int i = 1 ; i < nums.size() ; i++){
		int value = nums[i];
		int j =i - 1 ;
		while(j >= 0 && value < nums[j]){
			nums[j+1] = nums[j];
			j--;
		}
		j++;
		swap(nums[j],value);
	}
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i =0 ; i < n ;i++)
		cin>>v[i];
	insertionSort(v);
	for(int i = 0; i < v.size() ;i++){
		cout<<v[i]<<" ";
	}
		
	return 0;
}