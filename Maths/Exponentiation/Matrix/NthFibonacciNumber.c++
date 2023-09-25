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
int NthFibonacci(vector<vector<int> >&v ,int n){
	vector<vector<int > > ans;
	vector<vector<int> > v1;
	vector<int> temp;
	temp.push_back(1);
	v1.push_back(temp);
	temp.clear();
	temp.push_back(0);
	v1.push_back(temp);
	temp.clear();
	ans = (MatrixExpo(v , n-2));
	ans = MatrixMultilpication(ans , v1 );
	return ans[0][0];
}
int main(){
	vector<vector<int> > v1;
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v1.push_back(v);
	v.clear();
	v.push_back(1);
	v.push_back(0);
	v1.push_back(v);
	
	int n;
	cin>>n;
	int result = NthFibonacci(v1 ,n);
	cout<<result<<endl;
	
	cout<<endl;	
	return 0;
}