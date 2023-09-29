// Binary tree implementation
#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* left;
		node* right;
		node(int data){
			this->data = data;
			this->left = NULL;
			this->right= NULL;
		}
};
node* buildtree(node* root){
	
	int value;
	cin>>value;
	if(value == -1)
		return NULL;
	root = new node(value);
	cout<<"Enter left value"<<endl;
	root->left = buildtree(root->left);
	cout<<"Enter rigth value"<<endl;
	root->right = buildtree(root->right);
	
	return root;
		
}
void display(node* root){
	if(root == NULL)
		return ;
	cout<<root->data<<endl;
	display(root->left);
	display(root->right);
}
void inorder(node* root){
	if(root == NULL)
		return ;
	
	display(root->left);
	cout<<root->data<<endl;
	display(root->right);
}
int main(){
	
	node* root = NULL;
	root = buildtree(root);
	display(root);
	
	
	
	return 0;
}