#include<iostream>
#include<algorithm>
using namespace std;
bool isAnagrams(string s1,string s2){
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	if(s1==s2){
		return true;
	}
	return false;
}
int main(){
	string s1,s2;
	cin>>s1>>s2;
	if(isAnagrams(s1,s2)){
		cout<<s1<<" and "<<s1<<" are anagrams"<<endl;
	}else{
		cout<<s1<<" and "<<s1<<" are not  anagrams"<<endl;
	}
	return 0;
}