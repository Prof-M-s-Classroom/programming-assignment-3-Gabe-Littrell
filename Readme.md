[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Gabe Littrell

## Description
Briefly describe what your program does and how the code is structured.
This program uses the Graph class in combination with the MinHeap class to print out an MST based on Prim's algorithm. 
The Graph class uses a 2D adjacency matrix in order to keep track of the inputted edge weight between vertices. The 
Graph class then uses the primMST function which makes use of the MinHeap class in order to print out the MST based on 
Prim's algorithm. The MinHeap class uses a combination of 3 arrays to replicate an STL priority queue. The class can be 
used to insert a vertex and key, extract a minimum, decrease a key based on a vertex and a new key, and it even has a 
private method that can be used to minheapify the values.
## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(logV)         |
| Extract Min          | O(logV)         |
| Decrease Key         | O(logV)         |
| Prim’s MST Overall   | O(ElogV)        |

_Explain why your MST implementation has the above runtime._
When inserting into the min heap to initialize it, V vertices are inserted which is O(VlogV). When extracting the min,
extraction only happens once per vertex so it's O(VlogV) as well. When decreasing the key, all adjacent vertices are 
considered which means that each edge is considered once. This means that it runs at O(ElogV) which is the dominant 
term.

## Test Case Description

Input:  
0 -- 1  2
0 -- 3  6
1 -- 2  3
1 -- 3  8
1 -- 4  5
2 -- 4  7
3 -- 4  9
Output:
0 -- 1  2
1 -- 2  3
0 -- 3  6
1 -- 4  5
Total weight: 16

## Assumptions
I had difficulty implementing the position matrix to keep track of everything and I ended up having to use arrays within 
arrays to keep everything in line. I used my knowledge on min heaps in order to build this program in the best, most 
efficient way I could.