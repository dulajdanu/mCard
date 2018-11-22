#include<stdio.h>
#include<stdlib.h>
 
//Create adjacency list node structure
typedef struct AdjListNode{
    int data;
    struct AdjListNode* next;
}ALN;
 
//Create Adjacency list structure
typedef struct AdjList{
    ALN* head;
}AL;
 
//Create structure to represent a graph.
//A graph is an array of adjacency lists.
//Size of array will be V.
typedef struct Graph{
    int V;
    AL* array;
}GP;
 
//Create a new adjacency list node function.
ALN* newALN(int data)
{
    ALN* newNode = (ALN*)malloc(sizeof(ALN));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
 
//A function to create a graph of v vertices.
//GP = Graph
GP* createGP(int V)
{
    GP* graph = (GP*)malloc(sizeof(GP));
    graph->V = V;
 
    /*Create an array of adjacency list where
    size will be V.*/
    graph->array = (AL*)malloc(V * sizeof(AL));
 
    /*Initialize each adjacency list as empty
    by making head is NULL*/
    int i;
    for(i=0;i<V;++i)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}
 
//Adds an edge to directed graph.
void addEdge(GP* graph, int src, int data)
{
    ALN* newNode = newALN(data);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}
 
/*A function to print the adjacency list
representation of graph*/
void printGraph(GP* graph)
{
    int v;
    for(v=1;v<graph->V;++v)
    {
        ALN* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head", v);
        while(pCrawl)
        {
            printf("-> %d", pCrawl->data);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
//Add to edges to the graph.
int main()
{
    int V = 5;
    GP* graph = createGP(V);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 1);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 2);
 
    //print the graph using above implementation.
    printGraph(graph);
 
    return 0;
}
