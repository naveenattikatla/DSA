#include<iostream>
#include<cmath>
using namespace std;
bool ispalindrome(string s){
	int n = s.length() - 1;
	for(int  i = 0 ; i< ceil(n / 2 ); i++){
		if(s[i] != s[ n - i]){
			return false;
		}
	}
	return true;
	
}
int main(){
	string s;
	getline(cin,s);
	if(ispalindrome(s)){
		cout<<s<<" is palindrome"<<endl;
	}
	else{
		cout<<s<<" is not palindrime"<<endl;
	}
	return 0;
}