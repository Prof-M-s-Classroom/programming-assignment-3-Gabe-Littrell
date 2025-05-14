#ifndef GRAPH_H
#define GRAPH_H
#include <math.h>
#include "heap.h"
using namespace std;

class Graph {
public:
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                if (i == j) {
                    adjMatrix[i][j] = 0;
                }
                else {
                    adjMatrix[i][j] = INFINITY;
                }
            }
        }
    }
    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
        numVertices = NULL;
    }
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }
    void primMST() {
        // Must print MST edges and total weight
        int* parent = new int[numVertices];
        int* key = new int[numVertices];
        MinHeap minHeap(numVertices);

        for (int i = 0; i < numVertices; i++) {
            key[i] = INFINITY;
            parent[i] = -1;
            minHeap.insert(i, key[i]);
        }

        key[0] = 0;
        minHeap.decreaseKey(0, 0);

        while (!minHeap.isEmpty()) {
            int u = minHeap.extractMin();

            for (int v = 0; v < numVertices; v++) {
                int weight = adjMatrix[u][v];
                if (weight && minHeap.isInMinHeap(v) && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    minHeap.decreaseKey(v, weight);
                }
            }
        }

        int totalWeight = 0;
        for (int i = 1; i < numVertices; i++) {
            cout << parent[i] << " -- " << i << "\t" << adjMatrix[i][parent[i]] << endl;
            totalWeight += adjMatrix[i][parent[i]];
        }
        cout << "Total weight: " << totalWeight << endl;

        delete[] parent;
        delete[] key;
    }

private:
    int** adjMatrix;
    int numVertices;
};

#endif