#include<iostream>
using namespace std;
long int fact(int n){
	if(n ==  0 ){
		return 1;
	}
	return n*fact(n-1);
}
int main(){
	int n;
	cin>>n;
	long int ans = fact(n);
	cout<<"factorial of "<<n<<" is "<<ans<<endl;
	return 0;
}