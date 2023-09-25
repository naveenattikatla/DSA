#include<iostream>
using namespace std;
int cnt = 0;
struct queue{
	int data;
	queue* next;
};
queue* createNode(int data){
	cnt++;
	queue* node = new queue();
	node->data = data;
	node->next = NULL;
	return node;
}
queue*  push(queue* head , int data){
	queue* node = createNode(data);
	if(head==NULL){
		head = node;
		return head;
	}
	queue* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = node;
	return head;
}

bool empty(queue* head){
	if(head==NULL)
		return true;
	return false;
}
queue* pop(queue* head){
	cnt--;
	queue* node = head;
	head = head->next;
	delete(node);
	return head;
}
int front(queue* head){
	if(head==NULL)
		return -1;
	return head->data;
}
int size(queue* head){
	return cnt;
}

int  main(){
	queue* head = NULL;
	head =push(head,12);
	head =push(head,2);
	head =push(head,21);
	
	while(head!=NULL){
		cout<<front(head)<<" ";
		head = pop(head);
	}
	cout<<endl;
	cout<<"size is "<<size(head)<<endl;
	return 0;
}