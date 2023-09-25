#include<iostream>
using namespace std;
class Solution {
public:
    string toLowerCase(string s) {
        string ans ;
        for(int i = 0 ; i < s.length();i++){
            if(s[i]>=65 && s[i] <= 90){
                ans.push_back(s[i]+32);
            }
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};
int main(){
    string s;
    getline(cin,s);
    Solution obj;
    string ans = obj.toLowerCase(s);
    cout<<ans<<endl;
}