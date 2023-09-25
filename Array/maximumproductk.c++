#include<iostream>
#include<vector>
using namespace std;
// Product of K integers
int maxProdK(vector<int>&nums){
	    int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for(int i = 0; i < nums.size();i++){
            if(nums[i] > max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }else if(nums[i] > max2){
                max3 = max2;
                max2 = nums[i];
            }else if(nums[i] > max3){
                max3 = nums[i];
            }
            if(nums[i] < min1){
                min2 = min1;
                min1 = nums[i];
            }else if(nums[i] < min2){
                min2 = nums[i];
            }
        }
        
        return max(max1 * max2 * max3 , max1* min1 * min2);
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0 ; i < n ; i++)
		cin>>v[i];
	int ans = maxProdK(v);
	cout<<"Maximum Product of "<<n<<" Integers is "<<ans<<endl;
	return 0;
}