#include<iostream>
using namespace std;
string rev(string s){
	string ans ;
	for(int i = s.length()-1 ; i >= 0  ; i--){
		ans.push_back(s[i]);
	}
	return ans;
}
int main(){
	string s;
	getline(cin,s);
	string ans = rev(s);
	cout<<ans<<endl;
	return 0;
}