#include<iostream>
#include<vector>
using namespace std;
class Solution{
	public:
		void ncr(vector<int>& nums,vector<vector<int> >& ans,int index){
			if(index == nums.size()){
				ans.push_back(nums);
				return ;
			}
			
			for(int i = index ; i < nums.size() ; i++){
				swap(nums[i],nums[index]);
				ncr(nums,ans,index+1);
				swap(nums[i],nums[index]);
			}
			
		}
		vector<vector<int> > permutation(vector<int> nums){
			vector<vector<int> > ans;
			ncr(nums,ans,0);
			return ans;
		}
};
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i  = 0 ; i < n ; i++)
		cin>>v[i];
	Solution s;
	vector<vector<int> > ans = s.permutation(v);
	for(int i = 0 ; i< ans.size();i++){
		for(int j = 0 ; j < ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}