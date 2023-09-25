#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxlength = 0 ;
        string ans;
        vector<vector<int> > dp( n , vector<int> (n , 0));
        for(int diff = 0 ; diff < n ;diff++){
            for(int i = 0 , j = i+diff ; j < n ; i++,j++){
                if(i == j ){
                    dp[i][j] = 1;
                }
                else if( j == i + 1){
                    if(s[i] == s[j]){
                        dp[i][j] = 2;
                    }
                }
                else{
                    if(dp[i+1][j-1] && s[i] == s[j]){
                        dp[i][j] = dp[i+1][j-1] + 2;          
                    }
                }
                // update maxlength when palindrome encounter.
            	if(maxlength < (j-i+1) && dp[i][j] ){
                    maxlength = j - i + 1 ;
                    ans = s.substr( i , maxlength);
                }
            }
            
        }
        return ans;
        
    }
};
int main(){
	string s1;
	cin>>s1;
	Solution s;
	string ans =s.longestPalindrome(s1);
	cout<<ans<<endl;
	return 0;
}