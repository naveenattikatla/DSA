#include<iostream>
#include<cstdlib>
#include<queue>
#include<vector>
using namespace std;
class Graph{
	public :
		int v;
		int e;
		vector<vector<int> > graph_matrix;
	private :
		vector<bool> visited ;
		queue<int> q;
	public:
		Graph(int v){
			this->v = v;
			int minEdges = v - 1 ; 
			int maxEdges = ((v * ( v - 1) ) / 2 ) - minEdges + 1 ;
			this->e =  rand() %  maxEdges + minEdges; //  number of edges -> minimum 9 , maximum 45 if v is 10
			this->graph_matrix.resize(v,vector<int> (v,0)); // adj. matrix for graph
		}
	void add_edge(int src , int dest){
		this->graph_matrix[src][dest] = 1;
	}
	void create_random_graph(){
		// generting e edges
		int src, dest;
		for(int i = 0 ; i < this->e ; i++){
			src = rand() % this->v;
			dest = rand() % this->v;
			while(src == dest && graph_matrix[src][dest] == 1 ){
				src = rand() % this->v;
			 	dest = rand() % this->v;
			}
			graph_matrix[src][dest] = 1;
			
		}
	}
	int num_of_edges(){
		return this->e;
	}
	void BFS(){
		this->visited.resize(v,false);
		for(int i = 0 ; i < this->v ; i++){
			if(!this->visited[i]){
				this->trversal_bfs(i);
			}
		}
	}
	void trversal_bfs(int node){
		q.push(node);
		visited[node]= true;
		while(!q.empty()){
			node = q.front();
			cout<<node<<" ";
			q.pop();
			for(int i = 0  ; i < graph_matrix[node].size();i++){
				if(!visited[i] && graph_matrix[node][i]){
					visited[i] = true;
					q.push(i);
				}
			}
		}
	}
	void print_adj_matrix(){
		cout<<endl;
		for(int i = 0 ; i < this->v ; i++){
			for(int j = 0; j < this->graph_matrix[i].size() ; j++){
				cout<<this->graph_matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
};
int main(){
	int n;
	cin>>n;
	Graph g(n);
	// g.create_random_graph(); 
	
	g.add_edge(0,1);
	g.add_edge(1,2);
	g.add_edge(0,3);
	g.add_edge(3,4);
	g.add_edge(4,3);
	g.add_edge(4,2);
	g.add_edge(0,2);
	
	// g.print_adj_matrix();
	
	g.BFS();
	
	return 0;
}