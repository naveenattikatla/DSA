#include<iostream>
#include<vector>
using namespace std;
class Solution{
	
	public:
		void  heapify(vector<int>& nums,int index){
			int smallest = index;
			int left = 2*smallest + 1;
			int right = 2*smallest+ 2;
			if(left < nums.size() && nums[left] < nums[smallest]){
				smallest = left;
			}
			if(right < nums.size() && nums[right] < nums[smallest]){
				smallest = right;
			}
			if(smallest != index){
				swap(nums[smallest],nums[index]);
				heapify(nums,smallest);
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