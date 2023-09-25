#include<iostream>
using namespace std;
int number(int n){
	if( n == 1){
		return 2;
	} 
	if(n == 2){
		return 3;
	}
	return ( number( n-1 ) + number(n -2) ) % 1000000007 ; 
}
int main(){
	int result = number(3);
	cout<<result<<endl;
	return 0;
}