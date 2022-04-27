#include<stdio.h>

struct node {
	int data;	
	struct node* next;
};

struct graph {
	int vertices;
	int *visited;
	struct node **adjlist;
};

struct node* createNode(int value){
	struct node* temp=(struct node*)malloc(sizeof(struct node*);
	temp->data=value;
	temp->next=NULL;
	return temp;
}

struct graph* createGraph(int nodes){
	struct graph* temp = malloc(sizeof(struct graph));
	temp->vertices=nodes;
	temp->vertices=(int)malloc(sizeof(int));
	temp->adjlist=(struct node*)malloc(nodes*sizeof(struct node*));	//making nodes number of lists
	return  temp;
}

void addedge(struct graph* g,int src,int des){
	struct node* temp=createNode(des);
	adjList[src]->next=temp;
	
}
int main(){
	int n,e;
	
	printf("Enter the number of nodes and edges:\t");
	scanf("%d%d",&n,&e);
	struct graph* g=createGraph(n);
	int x,y;
	for(int i=0;i<e;i++){
		printf("Enter edge values:\t");
		scanf("%d%d",&x,&y);
		addedge(g,x,y);
	}
}

