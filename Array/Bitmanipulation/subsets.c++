// subsets of an array using m=bit manipulation
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> >  ans;
        int n  = nums.size() ;
         vector<int> v;
        for(int  i = 0; i < (1 << ( n )) ; i++){
            for(int j = 0 ; j < n ; j++){
                if((( 1 << j) & i) ){
                    v.push_back(nums[j]) ;
                }
               
            }
            ans.push_back(v);
            v.clear();
        }
         return ans;
    }
   
};
int main(){
    Solution* obj = new Solution();
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0 ; i < n ;i++){
        cin>>v[i];
    }
    vector<vector<int> >  ans ;
    ans =  obj->subsets(v); 
    return 0;

}