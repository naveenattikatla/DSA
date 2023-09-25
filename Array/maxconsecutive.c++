#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int >  v(n);
    for(int i = 0 ; i < n ;i++){
        cin>>v[i];
    }
    int count = 0 ;
    int ans = INT_MIN;
    for(int i = 0  ; i < n ; i++){
        if(v[i] == 1){
            count++;
        }
        else{
            ans = max(ans , count);
            count = 0 ;
        }
    }
    ans = max(ans ,count);
    cout<<ans<<endl;
    return 0;
}