#include<iostream>
#include<algorithm>
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
string strcom(string s){
	string ans;
	ans.push_back(s[0]);
	int count = 1;
	for(int i = 1; i< s.length(); i++){
		if(s[i] == s[i-1]){
			count++;
		}
		else{
			if(count != 1 ){
				ans.append(tostring(count));
				count = 1;
				ans.push_back(s[i]);
			}
		}
	}
	if(count !=1)
		ans.append(tostring(count));
	return ans;
}

int main(){
	string s;
	cin>>s;
	string op;
	op = strcom(s);
	cout<<op<<endl;
	return 0;
}