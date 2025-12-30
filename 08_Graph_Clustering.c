#include <stdio.h>
#include <stdbool.h>


/// The General Logic
/*
Iterate through all the nodes one by one.
If a node has not been visited yet, that node is the starting point of a new cluster.
Start from that node, traverse every reachable node, and mark them as visited (This forms one complete cluster).
Continue the loop; if you encounter another unvisited node, that indicates the start of a second cluster.
*/


int adj[10][10];
int visited[10];
int numNodes;


void DFS(int startNode) {
    printf("%d ", startNode);
    visited[startNode] = 1;

    for (int i = 0; i < numNodes; i++) {
        if (adj[startNode][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}




int main() {


    /// HW 8: How to create clusters in a graph, and how to distinguish between multiple clusters?
    /// alternate way of typing: Extracting clusters from a graph given as an array.


    numNodes = 6;
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            adj[i][j] = 0;


    for(int i=0; i<10; i++)
        visited[i] = 0;

    // Cluster 1: 0-1, 1-2
    adj[0][1] = 1; adj[1][0] = 1; adj[1][2] = 1; adj[2][1] = 1;

    // Cluster 2: 3-4
    adj[3][4] = 1; adj[4][3] = 1;

    // Cluster 3: 5 // no connection

    int clusterCount = 0;

    printf("Clusters inside of the graph (Connected Components):\n");

    for (int i = 0; i < numNodes; i++) {
        if (visited[i] == 0) {
            clusterCount++;
            printf("Cluster %d: { ", clusterCount);
            DFS(i);
            printf("}\n");
        }
    }

    printf("\nSum of Clusters: %d\n", clusterCount);





     ///  How is it distinguished
/*
The for loop inside the main function is the heart of the distinction process:
The loop starts from node 0.
It checks visited[0]. If it is 0 (unvisited), it means a new cluster has been found.
DFS(0) is called. This function visits 1 and 2 (which are connected to 0), marks all of them as visited = 1, and prints them.
When DFS finishes, the loop moves to node 1. However, since 1 was just visited (visited[1] == 1) during the previous step, the code skips it (It understands that it belongs to the previous cluster).
When the loop reaches node 3, it sees that visited[3] == 0. It realizes: "I could not reach this node in the previous rounds, so this must be a separate cluster (Cluster 2)."
It starts DFS(3) again and visits only 3 and 4.
Summary: The visited array and the if(visited[i] == 0) check are the boundaries that distinguish and separate the clusters from each other.
*/



    return 0;
}