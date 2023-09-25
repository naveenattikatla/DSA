#include<iostream>
using namespace std;
int pow(int a, int b){
	if( b == 0){
		return 1;
	}
	int result = pow(a , b / 2 );
	if( b % 2 == 0){
		return result * result;
	}
	else{
		return result * result * a;
	}
}
int main(){
	int a , b ;
	cin>>a>>b;
	int result =  pow(a ,b);
	cout<<result<<endl;
	
	return 0;
}