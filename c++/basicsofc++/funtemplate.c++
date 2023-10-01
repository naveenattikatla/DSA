#include<iostream>
using namespace std;
template <class T>
T add(T a , T b){
	T result = a + b;
	return result;
}
int main(){
	int result = add<int>(1,2);
	float ans = add<float>(1.433,9.33);
	cout<<result<<endl;
	cout<<ans<<endl;
	return 0;
}