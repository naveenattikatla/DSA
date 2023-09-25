#include<iostream>
#include<vector>
using namespace std;
int countways(int n){
	if(n == 2){
		return 2;
	}
	if(n == 1){
		return 1;
	}
	return countways(n-1) + countways(n-2);
}
int main(){
	int n;
	cin>>n;
	int numOfways = countways(n);
	cout<<numOfways<<endl;
	return 0;
}