#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0 ;
        int countodd = 0;
        int counteven = 0;
        for(int i = 0 ; i < 32 ; i++){
            countodd = 0 ;
            counteven = 0;
            for(int j = 0;  j < nums.size() ; j++){
                if( (1 << i) & nums[j] ){
                    counteven++;
                }else{
                    countodd++;
                }
                
            }
            if((counteven % 3) == 1){
                ans =  ans | (1 << i);   
            }
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