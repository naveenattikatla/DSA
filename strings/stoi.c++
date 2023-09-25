#include<iostream>
using namespace std;

int strtoi(string s){
	int ans = 0 ;
	for(int i = 0 ; i < s.length();i++){
		int num = s[i] -  48;
		ans =  ans * 10 + num;
	}
	return ans;
}
int main(){
	string s;
	cin>>s;
	int num= strtoi(s);
	cout<<num<<endl;
	return 0;
}