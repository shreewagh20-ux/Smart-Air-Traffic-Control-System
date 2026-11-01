# Campus Navigation System Using Dijkstra's Algorithm

## Project Overview

The Campus Navigation System is a C++ application that finds the shortest route from the Main Gate to a selected building within a college campus.

The campus is represented as a **weighted graph**:

- **Vertices** represent campus buildings.
- **Edges** represent pathways connecting buildings.
- **Weights** represent the distance between buildings in meters.

The program uses **Dijkstra's Shortest Path Algorithm** to calculate the minimum-distance route from the Main Gate to the selected destination.

## Objectives

- Understand and implement graph data structures.
- Represent buildings and pathways using an adjacency list.
- Implement Dijkstra's shortest path algorithm.
- Calculate the shortest distance between campus locations.
- Display the route and its total distance.

## Technologies and Concepts

- **Programming Language:** C++
- **Data Structure:** Weighted Graph
- **Graph Representation:** Adjacency List
- **Algorithm:** Dijkstra's Shortest Path Algorithm
- **Priority Queue:** Min-priority queue from the C++ Standard Template Library
- **C++ Standard:** C++17

## Campus Locations

The sample program contains these locations:

| Vertex | Building |
|---:|---|
| 0 | Main Gate |
| 1 | Administrative Block |
| 2 | Library |
| 3 | Computer Science Block |
| 4 | Electronics Block |
| 5 | Mechanical Block |
| 6 | Canteen |
| 7 | Auditorium |

The Main Gate is the source vertex. The user selects one of the other buildings as the destination.

## How the Program Works

1. Each campus building is assigned a vertex number.
2. A pathway between two buildings is stored as an edge.
3. The distance of each pathway is stored as the edge weight.
4. The graph is stored using an adjacency list.
5. Dijkstra's algorithm starts from vertex `0` (Main Gate).
6. The user selects a destination building.
7. The program calculates the shortest distance and reconstructs the route.
8. The route and total distance are displayed.

## Algorithm: Dijkstra's Shortest Path

Dijkstra's algorithm finds shortest paths from a source vertex in a graph with non-negative edge weights.

### Steps

1. Set the distance of every vertex to infinity.
2. Set the source vertex distance to zero.
3. Insert the source vertex into a min-priority queue.
4. Remove the vertex with the smallest tentative distance.
5. Examine its neighbouring vertices.
6. If a shorter route to a neighbour is found, update its distance and parent.
7. Continue until the destination is reached or no reachable vertices remain.
8. Follow the parent links to display the shortest route.

## Sample Pathway Distances

The following are illustrative distances used in the program:

| Connected Buildings | Distance |
|---|---:|
| Main Gate – Administrative Block | 100 m |
| Main Gate – Library | 150 m |
| Administrative Block – Library | 50 m |
| Administrative Block – Computer Science Block | 120 m |
| Library – Computer Science Block | 80 m |
| Library – Electronics Block | 100 m |
| Computer Science Block – Electronics Block | 60 m |
| Computer Science Block – Mechanical Block | 150 m |
| Electronics Block – Mechanical Block | 90 m |
| Electronics Block – Canteen | 70 m |
| Mechanical Block – Canteen | 100 m |
| Mechanical Block – Auditorium | 120 m |
| Canteen – Auditorium | 80 m |

These distances and the campus layout are sample data. Replace them with the actual buildings and approximate pathway distances of your campus when adapting the project.

## Sample Output

```text
========================================
          CAMPUS NAVIGATION SYSTEM
========================================
Starting Location: Main Gate

========== CAMPUS BUILDINGS ==========
0. Main Gate
1. Administrative Block
2. Library
3. Computer Science Block
4. Electronics Block
5. Mechanical Block
6. Canteen
7. Auditorium

Enter the building number (1-7), or 0 to exit: 4

========== SHORTEST ROUTE ==========
Starting Point: Main Gate
Destination: Electronics Block

Route:
Main Gate --> Library --> Electronics Block

Total Distance: 250 meters
====================================
```

## Time and Space Complexity

Let:

- `V` = number of vertices (buildings)
- `E` = number of edges (pathways)

| Operation | Complexity |
|---|---|
| Graph storage | O(V + E) |
| Dijkstra's algorithm with adjacency list and priority queue | O((V + E) log V) |
| Path reconstruction | O(V) |
| Auxiliary space | O(V) |

## How to Compile and Run

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/Campus-Navigation-System.git
```

### 2. Open the Project Folder

```bash
cd Campus-Navigation-System
```

### 3. Compile the C++ Program

Using GCC or MinGW:

```bash
g++ -std=c++17 campus_navigation.cpp -o campus_navigation
```

### 4. Run the Program

**Windows:**

```bash
campus_navigation.exe
```

**Linux / macOS:**

```bash
./campus_navigation
```

## Repository Structure

```text
Campus-Navigation-System/
|
|-- campus_navigation.cpp
|-- README.md
|-- LICENSE
```

## Applications

- Navigation within colleges and universities.
- Finding shortest walking routes between campus buildings.
- Demonstrating graph algorithms through a practical example.
- Understanding route planning and weighted graphs.

## Future Enhancements

- Add a graphical user interface.
- Display a visual campus map.
- Allow users to add or remove buildings and pathways.
- Use actual campus distances.
- Allow route searches between any two buildings.
- Display alternative routes.

## Conclusion

The Campus Navigation System demonstrates how graph data structures and Dijkstra's Shortest Path Algorithm can solve a practical route-planning problem. It calculates and displays the shortest route from the Main Gate to a selected campus building, helping illustrate an important real-world application of Data Structures.

---

**Project Type:** Data Structures Mini Project  
**Programming Language:** C++  
**Algorithm:** Dijkstra's Shortest Path Algorithm
