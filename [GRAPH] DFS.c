#include <stdio.h>
#include<stdlib.h>
#define N 50

struct node {
    int vertex;
    struct node * next;
};

struct Graph{
    int num_vertices;
    struct node ** adjlist;
    int * visited;
};

void DFS(struct Graph * graph,int vertex){
    struct node * adj_list=graph->adjlist[vertex];
    struct node * temp=adj_list;
    
    graph->visited[vertex]=1;
    printf("\n visited %d ",vertex);
    
    while(temp!=NULL){
        int adj_vertex=temp->vertex;

        if(graph->visited[adj_vertex]==0){
           
            DFS(graph,adj_vertex);
        }
        temp=temp->next;
    }
    
}

struct node * createNode(int n){
    struct node * newnode =(struct node *) malloc(sizeof(struct node));
    newnode->vertex=n;
    newnode->next=NULL;
    return newnode;
}

struct Graph * createGraph(int num_v){
    struct Graph * graph = malloc(sizeof(struct Graph));
    graph->num_vertices=num_v;
    graph->adjlist=malloc(num_v * sizeof(struct node));
    graph->visited=malloc(num_v * sizeof(int));
    
    int i;
    for(i=0;i<num_v;i++){
        graph->adjlist[i]=NULL;
        graph->visited[i]=0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjlist[src];
  graph->adjlist[src] = newNode;

  // Add edge from dest to src
  newNode = createNode(src);
  newNode->next = graph->adjlist[dest];
  graph->adjlist[dest] = newNode;
}

void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->num_vertices; v++) {
    struct node* temp = graph->adjlist[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}



int main(void) {
	// your code goes here
	struct Graph * graph = createGraph(4);
	addEdge(graph,0,1);
	addEdge(graph,0,2);
	addEdge(graph,1,2);
	addEdge(graph,2,3);
	printGraph(graph);
	
	DFS(graph,0);
	return 0;
}

