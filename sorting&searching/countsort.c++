// Negative numbers are not allowed

#include<iostream>
#include<vector>
using namespace std;
void countSort(vector<int>& nums){
	if(!nums.size()){
		cout<<"No elemente to sort "<<endl;
		return ;
	}
	int max = INT_MIN;
	for(int i = 0 ; i < nums.size();i++){
		if(nums[i] > max){
			max = nums[i];
		}
	}
	vector<int> v(max+1,0);
	for(int i = 0;i< nums.size();i++){
		v[nums[i]]++;
	}
	for(int i = 0 ;i < v.size();i++){
		if(v[i]!=0){
			while(v[i]){
				cout<<i<<" ";
				v[i]--;
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0 ; i < n ;i++)
		cin>>v[i];
	countSort(v);
	
	
	return 0;
}