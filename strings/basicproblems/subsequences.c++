#include<iostream>
using namespace std;
// using bit manipulation
void subsequence(string s){
	for(int i = 0 ; i < (1  << s.length()) ; i++){
		string temp;
		for(int j = 0 ;j < s.length();j++){
			if((1<<j)& i){
				temp.push_back(s[j]);
			}
		}
		cout<<temp<<endl;
		temp.clear();
	}	
}
// using recursion
void subsequence(string s , string output){
	
	if(s.empty()){
		cout<<output<<endl;
		return ;
	}
	char c = s[0];
	s.erase(0 ,1);
	subsequence(s,output);
	output.push_back(c);
	subsequence(s,output);
	
	
}
int main(){
	string s;
	cin>>s;
	// using recursion
	// string ans;
	// subsequence(s,ans);
	subsequence(s);
	return 0;
}