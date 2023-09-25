#include<iostream>
#include<vector>
using namespace std;
void MatrixMultilpication(vector<vector<int> >& v1 , vector<vector<int> >& v2){
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
	for(int i = 0 ; i < ans.size();i++){
		for(int j = 0 ; j < ans[0].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

}
int main(){
	vector<vector<int> > v1;
	vector<vector<int> >v2;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v1.push_back(v);
	v.clear();
	v.push_back(3);
	v.push_back(4);
	v1.push_back(v);
	v.clear();
	
	v.push_back(2);
	v.push_back(3);
	v2.push_back(v);
	v.clear();
	v.push_back(3);
	v.push_back(1);
	v2.push_back(v);
	v.clear();
	
	MatrixMultilpication(v1,v2);
	cout<<"Matrix addition"<<endl;
	// matrixAddition(v1,v2);
	cout<<endl;	
	return 0;
}