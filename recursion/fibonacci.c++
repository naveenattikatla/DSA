#include<iostream>
using namespace std;
int nthFibonacci(int n){
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return nthFibonacci(n-1)+ nthFibonacci(n-2);
}

#include<iostream>
using namespace std;
int nthTribonacci(int n){
	if(n == 0)
		return 0;
	if(n == 1 || n == 2)
		return 1;
	return nthTribonacci(n-1)+nthTribonacci(n-2)+nthTribonacci(n-3);
}
int main(){
	int n ;
	cin>>n;
	int result = nthFibonacci(n);
	// int result = nthTribonacci(n);
	cout<<n<<" fibonacci number is "<<result<<endl;
	return 0;
}