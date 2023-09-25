#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end  = numbers.size()- 1;
        vector<int> ans;
        while(start < end){
            if(numbers[start] + numbers[end] == target){
                ans.push_back(start + 1);
                ans.push_back(end + 1);
                return ans;
            }
            else{
                if(numbers[start] + numbers[end] > target){
                    end = end - 1; 
                }else{
                    start = start +1 ;
                }

            }
        }
       ans.push_back(-1);
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
	vector<int>  ans = s.twoSum(v,target);
	for(int i = 0 ;i < ans.size();i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}