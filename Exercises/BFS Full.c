// C program for BFS of an undirected graph
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    // Undirected graph
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Function to perform Breadth First Search on a graph
// represented using adjacency list
void bfs(struct Node* adj[], int vertices, int source, int visited[]) {
    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Mark the current node as visited and enqueue it
    visited[source] = 1;
    queue[rear++] = source;

    // Iterate over the queue
    while (front != rear) {

        // Dequeue a vertex from queue and print it
        int curr = queue[front++];
        printf("%d ", curr);

        // Get all adjacent vertices of the dequeued vertex
        // curr If an adjacent has not been visited,
        // then mark it visited and enqueue it
        struct Node* temp = adj[curr];
        while (temp != NULL) {
            int neighbor = temp->data;
            if (visited[neighbor]==0) {

                visited[neighbor] = 1;
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
}

int main() {
    // Number of vertices in the graph
    int vertices = 5;

    // Adjacency list representation of the graph

    struct Node* adj[vertices];

    for (int i = 0; i < vertices; ++i)
        adj[i] = NULL;

    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    // Mark all the vertices as not visited
    int visited[vertices];
    for (int i = 0; i < vertices; ++i)
        visited[i] = 0;

    int choice;


    while(1)
    {
        printf("\n\nMenu\n1. BFS\n2.DFS\n0. Exit\nEnter choice: ");
        scanf("%d", &choice);
            if(choice==1)
            {
                    printf("\n\nBreadth First Traversal starting from vertex 0: ");
                    bfs(adj, vertices, 0, visited);
            }
            else if(choice==2)
            {
                ///call necessary functions for DFS
            }
            else if(choice==0)
            {
                return 0;
            }
            else
            {
                    printf("\nWrong choice, try again! \n");
            }
    }

    return 0;
}
