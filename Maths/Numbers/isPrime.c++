#include<iostream>
#include<cmath>
bool isPrime(int n){
	if(n == 1){
		return false;
	}
	for(int i = 2 ; i <= floor(sqrt(n));i++){
		if(n % i == 0)
			return false;
	}
	return true;
	
}
using namespace std;
int main(){
	int n ;
	cin>>n;
	if(isPrime(n)){
		cout<<n<<" is prime number"<<endl;
	}else{
		cout<<n<<" not prime number"<<endl;
	}
	
	return 0;
}