#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > MatrixMultilpication(vector<vector<int> >& v1,vector<vector<int> >& v2){
	vector<vector<int> > ans;
	int result = 0;
	for(int i = 0 ; i < v1.size(); i++){
		vector<int> v;
		for(int j = 0 ;  j < v2[0].size();j++){
			result =0;
			for(int k = 0 ; k < v2.size();k++){
				 result += v1[i][k]*v2[k][j];
			}
			v.push_back(result);
		}
		ans.push_back(v);
		v.clear();
	}

	return ans;

}
vector<vector<int> >IdentityMatrix(vector<vector<int> >& v1){
	vector<vector<int> > ans ;
	for(int i = 0 ; i < v1.size();i++){
		vector<int> v;
		for(int j = 0 ; j < v1[0].size() ; j++){
			if( i == j)
				v.push_back(1);
			else
				v.push_back(0);
		}
		ans.push_back(v);
		v.clear();
	}
	return ans;
}
vector<vector<int> > MatrixExpo(vector<vector<int> >& v1 ,int n){
	if(n == 0){
		return IdentityMatrix(v1);
	}
	vector<vector<int> > result = MatrixExpo(v1, n / 2);
	if(n % 2 == 0){
		return MatrixMultilpication(result ,result);
	}else{
		
		result =  MatrixMultilpication(result , result);
		return MatrixMultilpication(result , v1);	
	}
	
}
int main(){
	vector<vector<int> > v1;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v1.push_back(v);
	v.clear();
	v.push_back(3);
	v.push_back(4);
	v1.push_back(v);
	v.clear();
	
	v1 = MatrixExpo(v1,3); // 3 is for just cheking purpose
	for(int i = 0 ; i < v1.size();i++){
		for(int j = 0 ; j < v1[0].size();j++){
			cout<<v1[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;	
	return 0;
}