#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
string tostring(int n){
	string s;
	while(n!=0){
		s.push_back(48 + ( n %10)); 
		n = n/10;
	}
	reverse(s.begin(),s.end());	
	return s;
	
}
int main(){
	int n;
	cin>>n;
	string s;
	s = tostring(n);
	cout<<s<<endl;
	return 0;
}