#include<iostream>
using namespace std;
bool ispower3(int n){
	if(n == 1)
		return true;
	if( n % 3 != 0 || n <= 0 )
		return false;
	return ispower3(n / 3);
}
int main(){
	int num;
	cin>>num;
	ispower3(num) ? cout<<num<<" is power 3" : cout<<num<<" is not power 3" <<endl;
	
	
	return 0;
}