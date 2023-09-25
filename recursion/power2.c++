#include<iostream>
using namespace std;
bool ispower2(int num){
	cout<<num<<endl;
	if(num == 1){
		return true;
	}
	if(num % 2 != 0){
		return false;
	}
	return ispower2(num / 2); 
}
int main(){
	int num;
	cin>>num;
	ispower2(num) ? cout<<num<<" is power 2" : cout<<num<<" is not power 2" <<endl;
	
	
	return 0;
}