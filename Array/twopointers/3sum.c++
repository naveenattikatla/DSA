#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        for(int i = 0 ;i < nums.size()-2;i++ ){
            
            int start = i + 1 ;
            int end = nums.size()-1;
            while(start < end){
                if(nums[i]+ nums[start] + nums[end] == 0){
                   s.insert({nums[i],nums[start],nums[end]});
                   start ++;
                   end--;
                    
                }
                else{
                    if(nums[i]+ nums[start] + nums[end] > 0 ){
                        end = end -1 ;
                    }
                    else{
                        start = start + 1;
                    }
                }
            }
        }
        for(auto triplets : s){
            ans.push_back(triplets);
        }
        return ans;
    }
};

int main(){
	int n, target;
	cin>>n>>target;
	vector<int> v(n); 
	for(int i = 0 ; i < n ; i++)
		cin>>v[i];
	Solution s;
	vector<vector<int>> ans = s.threeSum(v);
    for(int i = 0 ;i < ans.size();i++){
        cout<<"[";
        for(int j = 0 ; j < ans[i].size();j++){
            cout<<ans[i][j]<<",";
        }
        cout<<"]";
    }
	return 0;
}