#include<iostream>
#include<cmath>
using namespace std;
int reverse(int n,int rev){
	if(n / 10 == 0){
		return rev * 10 + n;
	}
	rev = rev * 10  + (n % 10);
	return reverse( n / 10 , rev);	
    
}
int main(){
	int n ;
	cin>>n;
	int rev = reverse(n,0);
	cout<<"reverse is "<<rev<<endl;
	
	return 0;
}