#include<iostream>
#include<vector>
using namespace std;

int combination(int n , int k){
	if(k == 0 || n == k){
		return 1;
	}
	return  combination(n - 1 , k-1) + combination(n-1 , k);
}
int main(){
	int n, k;
	cin>>n>>k;
	int ans = combination(n,k);
	cout<<ans<<endl;
	return 0;
}