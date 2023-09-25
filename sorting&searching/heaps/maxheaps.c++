#include<iostream>
#include<vector>
using namespace std;
class Solution{
	
	public:
		void  heapify(vector<int>& nums,int index){
			int largest = index;
			int left = 2*largest + 1;
			int right = 2*largest+ 2;
			if(left < nums.size() && nums[left] > nums[largest]){
				largest = left;
			}
			if(right < nums.size() && nums[right] > nums[largest]){
				largest = right;
			}
			if(largest != index){
				swap(nums[largest],nums[index]);
				heapify(nums,largest);
			}
		}
		void heapsort(vector<int>& nums){
			for(int i = nums.size()-1 ; i >=0 ; i-- ){
				heapify(nums,i);			
			}
	}
};
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0 ; i < n ;i++){
		cin>>v[i];
	}
	Solution s ;
	s.heapsort(v);
	for(int i = 0; i< n;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}