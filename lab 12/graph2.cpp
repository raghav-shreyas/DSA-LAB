//Program to implement graph using adjacency list
#include <iostream>
#include <list>
#define MAX_VERTICES 10
using namespace std;

class Graph {
private:
    int numVertices;
    list<int> adjList[MAX_VERTICES];

    bool isValidVertex(int v) {
        return (v >= 0 && v < numVertices);
    }

public:
    Graph(int vertices) {
        if (vertices <= 0 || vertices > MAX_VERTICES) {
            cout << "Number of vertices must be between 1 and " << MAX_VERTICES << ".\n";
            numVertices = 0;
            return;
        }
        numVertices = vertices;
    }
    void insertEdge(int src, int dest) ;
    void deleteEdge(int src, int dest) ;
    void searchEdge(int src, int dest) ;
    void display() ;
    
};

int main() {
    int vertices;
    cout << "Enter number of vertices (max " << MAX_VERTICES << "): ";
    cin >> vertices;

    Graph g(vertices);
    int choice, src, dest;

    do {
        cout << "\n--- Graph Menu ---\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search Edge\n";
        cout << "4. Display Graph\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter source and destination: ";
            cin >> src >> dest;
            g.insertEdge(src, dest);
            break;
        case 2:
            cout << "Enter source and destination: ";
            cin >> src >> dest;
            g.deleteEdge(src, dest);
            break;
        case 3:
            cout << "Enter source and destination: ";
            cin >> src >> dest;
            g.searchEdge(src, dest);
            break;
        case 4:
            g.display();
            break;
        case 5:
            cout << "Exiting.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}

//Function to add edge in graph
void Graph::insertEdge(int src, int dest) {
    if (isValidVertex(src) && isValidVertex(dest)) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // Undirected graph
        cout << "Edge inserted between " << src << " and " << dest << ".\n";
    } else {
        cout << "Invalid vertex number.\n";
    }
}
//Function to delete edge of graph
void Graph::deleteEdge(int src, int dest) {
    if (isValidVertex(src) && isValidVertex(dest)) {
        adjList[src].remove(dest);
        adjList[dest].remove(src);
        cout << "Edge deleted between " << src << " and " << dest << ".\n";
    } else {
        cout << "Invalid vertex number.\n";
    }
}
//Function to search for edge in graph
void Graph::searchEdge(int src, int dest) {
    if (isValidVertex(src) && isValidVertex(dest)) {
        for (int v : adjList[src]) {
            if (v == dest) {
                cout << "Edge exists between " << src << " and " << dest << ".\n";
                return;
            }
        }
        cout << "No edge exists between " << src << " and " << dest << ".\n";
    } else {
        cout << "Invalid vertex number.\n";
    }
}
//Function to display adjency matrix
void Graph::display() {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < numVertices; i++) {
        cout << i << " --> ";
        for (int v : adjList[i])
            cout << v << " ";
        cout << "\n";
    }
}