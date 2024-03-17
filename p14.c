#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
} Graph;

// Function to create a new node
Node* newNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a graph with numVertices vertices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // Create an adjacency list for each vertex
    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    Node* new_node = newNode(dest);
    new_node->next = graph->adjLists[src];
    graph->adjLists[src] = new_node;

    // Since graph is undirected, add an edge from dest to src also
    new_node = newNode(src);
    new_node->next = graph->adjLists[dest];
    graph->adjLists[dest] = new_node;
}

// Function to print the graph
void printGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->numVertices; ++v) {
        printf("\n Adjacency list of vertex %d\n head ", v);
        Node* temp = graph->adjLists[v];
        while (temp) {
            printf("-> %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int numVertices, choice, src, dest;
    Graph* graph;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    graph = createGraph(numVertices);

    while (1) {
        printf("\n1.Add Edge\n");
        printf("2.Print the graph\n");
        printf("3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                printf("Enter destination vertex: ");
                scanf("%d", &dest);

                // Check if vertices are within bounds
                if (src >= numVertices || dest >= numVertices) {
                    printf("Invalid vertex\n");
                } else {
                    addEdge(graph, src, dest);
                    printf("Edge added successfully\n");
                }
                break;

            case 2:
                printGraph(graph);
                break;

            case 3:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
