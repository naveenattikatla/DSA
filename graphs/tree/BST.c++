#include<iostream>
#include<cmath>
using namespace std;

struct Node{
	int data ;
	Node* next;
	Node* back;
};

Node* createNode(int data){
	Node* node = new Node();
	node->data = data;
	node->back =NULL;
	node->next = NULL;
	return node;
}

void add(Node* node,Node* head){
	if(head->next == NULL && node->data >= head->data ){
		head->next = node;
		return ;
	}
	if(head->back == NULL && node->data < head->data){
		head->back = node;
		return ;
	}
	if(head->data > node->data){
		head = head->back;
		add(node , head);
	}else{
		head = head->next;
		add(node,head);
	}
}
void display(Node* head){
	if(head ==NULL){
		return;
	}
	
	display(head->back);
	cout<<head->data<<" ";
	display(head->next);
}
int heightofNode(Node* head,int data){
	if(head->data == data){
		return 0;
	}
	if(head->data < data){
		head = head->next;
		return 1 + heightofNode(head , data);
	}
	else{
		head = head->back;
		return 1 + heightofNode(head,data);
	}
}
Node* insert(Node* head ,int data){
	Node* node = createNode(data);
	if(head == NULL){
		head = node;
		return head;
	}
	else{
		add(node , head);
		return head;
	}
}
int heightBST(Node* head){
	if(head->next == NULL && head->back == NULL){
		return 0;
	}
	if(head->next == NULL){
		return 1 + heightBST(head->back);
	}
	if(head->back == NULL){
		return 1 + heightBST(head->next);
	}
	return max( 1 + heightBST(head->back) , 1 + heightBST(head->next) );
	
}
int main(){
	Node* head  = NULL;
	
	head = insert(head , 34);
	head = insert(head , 4);
	head = insert(head , 3);
	head = insert(head , 9);
	head = insert(head , 340);
	head = insert(head , -4);
	head = insert(head , 13);
	head = insert(head , 90);
	display(head);
	int height = heightBST(head);
	cout<<"height is "<<height<<endl;
	height  = heightofNode(head , 4); // heght of node 4 
	cout<<"height of 4 node "<<height<<endl;
	return 0;
}