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
		vector<int> dist;
		vector<bool> visited;
		Graph(int v){
			this->v = v;
			int minEdges = v - 1 ; 
			int maxEdges = ((v * ( v - 1) ) / 2 ) - minEdges + 1 ;
			this->e =  rand() %  maxEdges + minEdges; 
			this->graph_matrix.resize(v,vector<int> (v,0)); 
		}
		void add_edge(int src,int dest,int weigth){
			this->graph_matrix[src][dest] = weigth;
			this->graph_matrix[dest][src] = weigth;
		}
		void create_random_graph(){
		int src, dest;
		for(int i = 0 ; i < this->e ; i++){
			src = rand() % this->v;
			dest = rand() % this->v;
			while(src == dest ||  graph_matrix[src][dest]){
				src = rand() % this->v;
			 	dest = rand() % this->v;
			}
			int weight = rand() % 12 + 2;
			graph_matrix[src][dest] = weight;
			graph_matrix[dest][src] = weight;
			
		}
	}
	void dijstraAlgo(int src){
		int temp = src;
		this->dist.resize(this->v,INT_MAX);
		this->visited.resize(this->v,false);
		visited[src] = true;
		this->dist[src] = 0;
		priority_queue<pair<int,int>,vector<pair<int,int> > , greater<pair<int,int> > > pq;
		pq.push({ 0 , src });
		while(!pq.empty()){
			src = pq.top().second;
			pq.pop();
			this->visited[src] = true;
			for(int i = 0 ; i < this->graph_matrix[src].size();i++){
				if(!this->visited[i] && graph_matrix[src][i]){
					this->dist[i] = min(this->graph_matrix[src][i]+this->dist[src],this->dist[i]);
					pq.push({this->graph_matrix[src][i] , i});
					 
				}
			}
		}
		cout<<"Minimum distance from "<<temp<<" node to all nodes in a graph "<<endl;
		for(int i = 0 ; i < this->dist.size();i++){
			cout<<this->dist[i]<<" ";
		}
		return ;
	}
	void print_adj_matrix(){
		for(int i = 0 ; i < this->v ; i++){
			for(int j = 0; j < this->graph_matrix[i].size() ; j++){
				cout<<this->graph_matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
};
int main(){
	int n ,src;
	cin>>n>>src;
	Graph g(n);
	g.create_random_graph(); 
	g.print_adj_matrix();
	g.dijstraAlgo(src);
	return 0;
}
// why - > shortest path between given node to all other nodes
// when -> weighted , cyclic / Acylic, direc/undirected
// when fails -> -ve weights