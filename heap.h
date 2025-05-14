#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:
    MinHeap(int capacity) {
        capacity = capacity;
        size = 0;
        keyArray = new int[capacity];
        heapArray = new int[capacity];
        position = new int[capacity];
    }
    ~MinHeap() {
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
        capacity = NULL;
        size = NULL;
    }
    void insert(int vertex, int key) {
        heapArray[size] = vertex;
        keyArray[vertex] = key;
        position[vertex] = size;
        size++;

        int i = position[vertex];
        while (i != 0 && keyArray[heapArray[(i - 1) / 2]] > keyArray[heapArray[i]]) {
            int parentIdx = (i - 1) / 2;
            int temp = heapArray[i];
            heapArray[i] = heapArray[parentIdx];
            heapArray[parentIdx] = temp;

            position[heapArray[i]] = i;
            position[heapArray[parentIdx]] = parentIdx;

            i = parentIdx;
        }
    }
    int extractMin() {
        int root = heapArray[0];
        position[root] = 0;

        if (size == 1) {
            position[root] = 0;
            size--;
            return root;
        }

        heapArray[0] = heapArray[size - 1];
        position[heapArray[0]] = 0;
        position[root] = 0;
        size--;
        minHeapify(0);
        return root;
    }
    void decreaseKey(int vertex, int newKey) {
        int i = position[vertex];
        keyArray[vertex] = newKey;
        while (i != 0 && keyArray[heapArray[(i - 1) / 2]] > keyArray[heapArray[i]]) {
            int parentIdx = (i - 1) / 2;
            int temp = heapArray[i];
            heapArray[i] = heapArray[parentIdx];
            heapArray[parentIdx] = temp;

            position[heapArray[i]] = i;
            position[heapArray[parentIdx]] = parentIdx;

            i = parentIdx;
        }
    }
    bool isInMinHeap(int vertex) {
        if (position[vertex] != 0) {
            return true;
        }
        return false;
    }
    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    void minHeapify(int idx) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[smallest]]) {
            smallest = left;
        }
        if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[smallest]]) {
            smallest = right;
        }

        if (smallest != idx) {
            int temp = heapArray[idx];
            heapArray[idx] = heapArray[smallest];
            heapArray[smallest] = temp;

            position[heapArray[idx]] = idx;
            position[heapArray[smallest]] = smallest;

            minHeapify(smallest);
        }
    }
};

#endif