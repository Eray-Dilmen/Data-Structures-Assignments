#include <stdio.h>
#include <stdbool.h>


int adj[10][10];
int visited[10];
int numVertices;

// Queue implementation for BFS
int queue[10];
int front = -1;
int rear = -1;




void enqueue(int vertex) {
    if (rear == 10 - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}




int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}




bool isQueueEmpty() {
    return front == -1 || front > rear;
}




void resetQueue() {
    front = -1;
    rear = -1;
}



//------------------------------------------------------------------------



void DFS(int startNode) {
    printf("%d ", startNode);
    visited[startNode] = 1;

    for (int i = 0; i < numVertices; i++) {
        if (adj[startNode][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}




void BFS(int startNode) {

    printf("%d ", startNode);
    visited[startNode] = 1;
    enqueue(startNode);

    while (!isQueueEmpty()) {
        int current = dequeue();
        for (int i = 0; i < numVertices; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}





// Helper to reset visited array between DFS and BFS calls
void resetVisited() {
    for (int i = 0; i < 10; i++) {
        visited[i] = 0;
    }
}





int main() {

    /// HW 9: DFS, BFS application




/*
    1. DFS (Depth-First Search)
DFS explores as far as possible along each branch before backtracking. It goes "deep" into the graph.
Logic: It uses the Stack data structure (often implemented via Recursion).
Imagine solving a maze. You walk down a path until you hit a dead end, then you turn back (backtrack) to the last intersection and try a different path.
Key Mechanism: LIFO (Last In, First Out).



2. BFS (Breadth-First Search)

BFS explores all the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level. It goes "wide" across the graph.
Logic: It uses the Queue data structure.
Imagine a ripple in water. It starts at the center and expands outward in circles (layers). It visits everyone at "Distance 1", then everyone at "Distance 2", etc.
Key Mechanism: FIFO (First In, First Out).
*/





/*   ex: graph with 5 nodes (0 to 4)
     0 -- 1
     |    |
     2 -- 3 -- 4
*/

    numVertices = 5;
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            adj[i][j] = 0;

    // (Undirected Graph)
    adj[0][1] = 1; adj[1][0] = 1; adj[0][2] = 1; adj[2][0] = 1; adj[1][3] = 1;
    adj[3][1] = 1; adj[2][3] = 1; adj[3][2] = 1; adj[3][4] = 1; adj[4][3] = 1;

    // DFS
    resetVisited();
    printf("Depth-First Search (DFS) starting from node 0:\n");
    DFS(0);
    printf("\n");

    // BFS
    resetVisited();
    resetQueue();
    printf("Breadth-First Search (BFS) starting from node 0:\n");
    BFS(0);
    printf("\n");

    return 0;
}