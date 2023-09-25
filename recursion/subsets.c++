#include<iostream>
#include<vector>
using namespace std;
class Solution{
	public:
		void generateSubsets(vector<int>& nums,int currentIndex,vector<int>& res,vector<vector<int> >& ans){
			
			if(currentIndex >= nums.size()){
				ans.push_back(res);
				return ;
			}
			int num = nums[currentIndex];
			res.push_back(num);
			generateSubsets(nums,currentIndex+1 ,res, ans);
			res.pop_back();
			generateSubsets(nums,currentIndex+1,res, ans);
			
		}
		vector<vector<int> > subsets(vector<int>& nums){
			vector<vector<int> > ans ;
			vector<int> res;
			generateSubsets(nums,0,res ,ans);
			return ans;
		}
		
};
int main(){
	vector<int> v;
	int num;
	cin>>num;
	v.resize(num);
	for(int i = 0; i < num ; i++)
		cin>>v[i];
	Solution s;
	vector<vector<int> > ans = s.subsets(v);
	for(int i = 0 ; i < ans.size() ; i++){
		for(int j= 0 ; j < ans[i].size() ; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	
	return 0;
}