Prim's and Kruskal's Algorithm Visualizer : 
This project is a C++-based visualizer for Prim's and Kruskal's algorithms, commonly used for finding the Minimum Spanning Tree (MST) of a connected, undirected, weighted graph. It is developed as a part of the Design and Analysis of Algorithms (DAA) coursework.

[+]Features
Visual representation of graph and MST

Implementation of both Prim’s and Kruskal’s algorithms

Simple command-line interface

Graph input through adjacency matrix

Technologies Used
C++

Graphics.h (for visualization — Turbo C++ or similar environments)

Requires support for BGI graphics (e.g., Turbo C++ on Windows/DOSBox). May not run on modern IDEs without adaptation.

📁 File Structure

├── kruskal.cpp       # Kruskal's algorithm with visualization
├── prim.cpp          # Prim's algorithm with visualization
├── graph_input.txt   # (Optional) Sample input format for testing
├── README.md         # Project documentation

Getting Started:
Requirements:
Turbo C++ / DOSBox (for graphics.h)

Windows OS (recommended for compatibility with graphics.h)

Running the Code
Open Turbo C++ or your compatible IDE.

Load kruskal.cpp or prim.cpp.

Compile and run the program.

Enter the number of nodes and the adjacency matrix as prompted.

Example input:

Enter number of vertices: 4
Enter adjacency matrix:
0 1 3 0
1 0 2 4
3 2 0 5
0 4 5 0

Algorithms Overview:
Prim's Algorithm
Builds the MST incrementally by adding the lowest-weight edge from the existing tree to a new vertex.

Kruskal's Algorithm
Sorts all edges by weight and adds the smallest one to the MST that doesn’t form a cycle (using Union-Find for cycle detection).


References
GeeksforGeeks - Prim’s Algorithm

GeeksforGeeks - Kruskal’s Algorithm
