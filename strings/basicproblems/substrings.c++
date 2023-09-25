#include<iostream>
using namespace std;
void substrings(string s){
	for(int diff = 0 ; diff < s.length();diff++){
		for(int  i  = 0 , j = i+diff ; j < s.length() ; i++,j++){
			cout<<s.substr(i, j- i + 1 )<<endl;
		}
	}	
}
int main(){
	string s;
	cin>>s;
	substrings(s);
	return 0;
}