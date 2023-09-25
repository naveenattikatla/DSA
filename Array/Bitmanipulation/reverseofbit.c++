
// reverse of bits
#include<iostream>
using namespace std;
class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        for(int i = 0 ; i < 32 ; i++){
            if((1 << i ) & n ){
                ans = ans | ( 1 << (31 - i ));
            }
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    Solution obj ;
    int result =obj.reverseBits(n);
    cout<<result<<endl;
    return 0;
}
