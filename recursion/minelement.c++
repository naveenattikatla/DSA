#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int minElement(vector<int>& nums,int n){
	if(n==0){
		return nums[0];	
	}
	return min(nums[n] , minElement(nums,n-1));
}

int main(){
	int n ;
	cin>>n;
	vector<int> v(n);
	for(int i =0 ;i < n;i++)
		cin>>v[i];
	int min = minElement(v,n-1);
	cout<<"minimum Element is "<<min<<endl;
	return 0;
}