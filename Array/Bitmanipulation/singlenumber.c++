#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int ans = 0 ;
      for(int i = 0 ; i < nums.size() ; i++){
          ans ^= nums[i];
      }  
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
    int result = obj.singleNumber(v);
    cout<<result<<endl;
}