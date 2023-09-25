#include<iostream>
using namespace std;
int nthFibonacci(int n){
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return nthFibonacci(n-1)+ nthFibonacci(n-2);
}

int main(){
	int n ;
	cin>>n;
	int result = nthFibonacci(n);
	cout<<n<<" fibonacci number is "<<result<<endl;
	return 0;
}