#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
       for(int i = 0 ; i< nums.size() ; i++){
            ans ^= nums[i];
            ans ^= i;
       } 
       ans ^= n ;
       return ans;
    }
};
int  main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n ;i++){
        cin>>v[i];
    }
    Solution obj;
    int result = obj.missingNumber(v);
    cout<<result<<endl;
}