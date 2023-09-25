#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
       int start = 0;
       for(int i = 0 ; i < s.length();i++){
           if(s[i]!='*'){
               swap(s[i],s[start]);
               start++;
           }else{
               start--;
           }
          
       }
       return s.substr(0, start);
        
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        Solution obj;
        string r = obj.removeStars(s);
        cout<< r;
    }

}