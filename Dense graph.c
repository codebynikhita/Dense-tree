#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Define the graph structure
typedef struct {
    int vertices;
    int edges;
    Node** adjacencyList;  // Array of adjacency lists
} DenseGraph;

// Function to initialize a graph
void initializeGraph(DenseGraph *graph, int vertices) {
    graph->vertices = vertices;
    graph->edges = 0;

    // Allocate memory for array of adjacency lists
    graph->adjacencyList = (Node**)malloc(vertices * sizeof(Node*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++) {
        graph->adjacencyList[i] = NULL;
    }
}

// Function to add an edge to the graph
void addEdge(DenseGraph *graph, int source, int destination) {
    // Create a new node for the destination vertex
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = destination;
    newNode->next = graph->adjacencyList[source];

    // Update the adjacency list of the source vertex
    graph->adjacencyList[source] = newNode;

    // Increment the edge count
    graph->edges++;
}

// Function to print the adjacency list representation of the graph
void printGraph(DenseGraph *graph) {
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("Vertex %d:", i);
        Node* current = graph->adjacencyList[i];
        while (current != NULL) {
            printf(" -> %d", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    DenseGraph graph;
    int vertices, edges, source, destination;

    // Take input for the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initializeGraph(&graph, vertices);

    // Take input for the number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Take input for each edge
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &source, &destination);
        addEdge(&graph, source, destination);
    }

    // Print the graph
    printGraph(&graph);

    return 0;
}
