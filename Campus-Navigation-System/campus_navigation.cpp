#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

// Represents a pathway from one building to another.
struct Edge {
    int destination;
    int distance;
};

class CampusNavigation {
private:
    vector<string> buildings;
    vector<vector<Edge>> campus;
    int totalBuildings;

public:
    explicit CampusNavigation(int n)
        : buildings(n), campus(n), totalBuildings(n) {}

    // Set the name of a building at a given index.
    void addBuilding(int index, const string& name) {
        if (index >= 0 && index < totalBuildings) {
            buildings[index] = name;
        }
    }

    // Add a two-way pathway between two buildings.
    void addPath(int u, int v, int distance) {
        if (u < 0 || v < 0 ||
            u >= totalBuildings || v >= totalBuildings ||
            distance <= 0) {
            return;
        }

        campus[u].push_back({v, distance});
        campus[v].push_back({u, distance});
    }

    // Display all available buildings.
    void displayBuildings() const {
        cout << "\n========== CAMPUS BUILDINGS ==========\n";

        for (int i = 0; i < totalBuildings; ++i) {
            cout << i << ". " << buildings[i] << '\n';
        }
    }

    // Find and display the shortest route using Dijkstra's algorithm.
    void findShortestPath(int source, int destination) const {
        if (source < 0 || destination < 0 ||
            source >= totalBuildings || destination >= totalBuildings) {
            cout << "\nInvalid source or destination.\n";
            return;
        }

        vector<int> dist(totalBuildings, INT_MAX);
        vector<int> parent(totalBuildings, -1);

        // Min-priority queue: {distance, vertex}.
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int currentDistance = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Ignore an outdated queue entry.
            if (currentDistance != dist[u]) {
                continue;
            }

            if (u == destination) {
                break;
            }

            // Relax all neighbouring pathways.
            for (const Edge& edge : campus[u]) {
                int v = edge.destination;
                int weight = edge.distance;

                if (dist[u] != INT_MAX &&
                    dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[destination] == INT_MAX) {
            cout << "\nNo route is available to "
                 << buildings[destination] << ".\n";
            return;
        }

        // Reconstruct the route by following parent links.
        vector<int> path;
        for (int v = destination; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << "\n========== SHORTEST ROUTE ==========\n";
        cout << "Starting Point: " << buildings[source] << '\n';
        cout << "Destination: " << buildings[destination] << '\n';
        cout << "\nRoute:\n";

        for (size_t i = 0; i < path.size(); ++i) {
            cout << buildings[path[i]];
            if (i + 1 < path.size()) {
                cout << " --> ";
            }
        }

        cout << "\n\nTotal Distance: " << dist[destination]
             << " meters\n";
        cout << "====================================\n";
    }
};

int main() {
    // Create a campus graph containing 8 buildings.
    CampusNavigation college(8);

    // Add building names. Index 0 is the Main Gate.
    college.addBuilding(0, "Main Gate");
    college.addBuilding(1, "Administrative Block");
    college.addBuilding(2, "Library");
    college.addBuilding(3, "Computer Science Block");
    college.addBuilding(4, "Electronics Block");
    college.addBuilding(5, "Mechanical Block");
    college.addBuilding(6, "Canteen");
    college.addBuilding(7, "Auditorium");

    // Add two-way pathways and their distances in meters.
    college.addPath(0, 1, 100);
    college.addPath(0, 2, 150);
    college.addPath(1, 2, 50);
    college.addPath(1, 3, 120);
    college.addPath(2, 3, 80);
    college.addPath(2, 4, 100);
    college.addPath(3, 4, 60);
    college.addPath(3, 5, 150);
    college.addPath(4, 5, 90);
    college.addPath(4, 6, 70);
    college.addPath(5, 6, 100);
    college.addPath(5, 7, 120);
    college.addPath(6, 7, 80);

    cout << "\n========================================\n";
    cout << "          CAMPUS NAVIGATION SYSTEM\n";
    cout << "========================================\n";
    cout << "Starting Location: Main Gate\n";

    int choice;

    while (true) {
        college.displayBuildings();

        cout << "\nEnter the building number (1-7), "
             << "or 0 to exit: ";

        if (!(cin >> choice)) {
            cout << "\nInvalid input. Please enter a number.\n";
            return 1;
        }

        if (choice == 0) {
            cout << "\nThank you for using Campus Navigation System!\n";
            break;
        }

        if (choice < 1 || choice >= 8) {
            cout << "\nInvalid building selection. Please try again.\n";
            continue;
        }

        // Find the shortest route from Main Gate (vertex 0).
        college.findShortestPath(0, choice);
    }

    return 0;
}
