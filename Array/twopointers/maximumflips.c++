#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        int solve(vector<int>& nums,int n){
            int i  = 0 ;
            int flip = 0 ;
            int ans = 0 ;
            int j = 0 ;
            while(i < nums.size()){
                if(nums[i] == 0){
                    flip++;
                }
                while(flip > n){
                    if(nums[j] == 0 ){
                        flip--;
                    }
                    j++;
                }
                ans = max(ans , i - j + 1);
                i++;
            }
            return ans;
    }
};
int main(){
    int n,b;
    cin>>n>>b;
    vector<int> v(n);
    for(int i = 0 ; i < n ;i++)
        cin>>v[i];
    Solution s;
    int ans  = s.solve(v,b);
    cout<<ans<<endl;
    return 0;
}