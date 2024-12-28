// C program for BFS and DFS traversal of an undirected graph
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in adjacency list
struct Node
{
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data)
 {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Node* adj[], int u, int v)
 {
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
void bfs(struct Node* adj[], int vertices, int source, int visited[], int distance[], int parent[])
{
    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Mark the current node as visited and enqueue it
    visited[source] = 1;
    distance[source] = 0;
    parent[source] = -1;
    queue[rear++] = source;

    // Iterate over the queue
    while (front != rear)
        {
        // Dequeue a vertex from queue
        int curr = queue[front++];

        // Get all adjacent vertices of the dequeued vertex
        struct Node* temp = adj[curr];
        while (temp != NULL)
            {
            int neighbor = temp->data;
            if (visited[neighbor] == 0)
            {
                // Mark neighbor as visited
                visited[neighbor] = 1;
                // Update distance and parent
                distance[neighbor] = distance[curr] + 1;
                parent[neighbor] = curr;
                // Enqueue neighbor
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
}

// Function to perform Depth First Search on a graph
// represented using adjacency list
void dfs_visit(struct Node* adj[], int u, int visited[])
{
    visited[u] = 1;
    printf("%d ", u);

    struct Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->data;
        if (visited[v] == 0)
            {
            dfs_visit(adj, v, visited);
        }
        temp = temp->next;
    }
}

void dfs(struct Node* adj[], int vertices, int source)
{
    int visited[MAX_VERTICES] = {0};  // Local visited array for DFS
    printf("\n\nDepth First Traversal starting from vertex %d: ", source);
    dfs_visit(adj, source, visited);
}

int main()
    {
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

    // Arrays to store distance and parent information
    int distance[vertices];
    int parent[vertices];

    int choice;

    while (1)
        {
        printf("\n\nMenu\n1. BFS\n2. DFS\n0. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            {
            // Perform BFS
            int visited[vertices]; // Local visited array for BFS
            for (int i = 0; i < vertices; i++)
            {
                visited[i] = 0;
                distance[i] = -1; // Initialize distance to -1
                parent[i] = -1;   // Initialize parent to -1
            }

            printf("\nBreadth First Traversal starting from vertex 0: ");
            bfs(adj, vertices, 0, visited, distance, parent);
            printf("\n\nVertex\tDistance\tParent");
            for (int i = 0; i < vertices; i++)
                {
                printf("\n%d\t%d\t\t%d", i, distance[i], parent[i]);
            }

        } else if (choice == 2)
        {
            // Perform DFS
            dfs(adj, vertices, 0);
        } else if (choice == 0)
        {
            return 0;
        } else
        {
            printf("\nWrong choice, try again! \n");
        }
    }

    return 0;
}
