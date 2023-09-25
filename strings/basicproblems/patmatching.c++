#include<iostream>
using namespace std;
void patmat(string txt,string pat){
	int count = 0;
	for(int i =  0 ; i <= txt.length() - pat.length();i++){
		count  = 0 ;
		for(int j = 0 ; j < pat.length() ; j++){
			if(pat[j] == txt[i+j]){
				count++;
			}else{
				break;
			}
		}
		if(count == pat.length()){
			cout<<i<<endl;
		}
	}
}
int main(){
	string txt,pat;
	cin>>txt>>pat;
	patmat(txt,pat);
	
	return 0;
}