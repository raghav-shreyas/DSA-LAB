//Program to implement graph using adjacency matrix
#include <iostream>
#define MAX_VERTICES 10
using namespace std;

class Graph {
private:
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
    bool isvalidvertex(int v){
        if (v >= numVertices || v < 0){
            return false;
        }
        return true;
    }
public:
    Graph(int vertices){
        if (vertices > MAX_VERTICES || vertices < 0){
            cout << "Maximum number of vertices is " << MAX_VERTICES << endl;
            numVertices = 0;
            return;
        }
        numVertices = vertices;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }
    void addEdge(int, int, int);
    bool SeachEdge(int, int); 
    void deleteEdge(int, int);
    void display();
};

int main() {
    int vertices;
    cout << "Enter number of vertices in the graph: ";
    cin >> vertices;

    Graph obj(vertices);

    int choice, src, dest, weight;
    do {
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search Edge\n";
        cout << "4. Display Graph\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter source and destination to insert edge: ";
            cin >> src >> dest;
            cout << "Enter weight: ";
            cin >> weight;
            obj.addEdge(src, dest,weight);
            break;
        case 2:
            cout << "Enter source and destination to delete edge: ";
            cin >> src >> dest;
            obj.deleteEdge(src, dest);
            break;
        case 3:
            cout << "Enter source and destination to search edge: ";
            cin >> src >> dest;
            obj.SeachEdge(src, dest);
            break;
        case 4:
            obj.display();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

//Function to display adjency matrix
void Graph::display() {
    cout << "\nAdjacency Matrix:\n   ";
    for (int i = 0; i < numVertices; i++) {
        cout << i << " ";
    }
    cout << "\n";
    for (int i = 0; i < numVertices; i++) {
        cout << i << ": ";
        for (int j = 0; j < numVertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

//Function to add edge in graph
void Graph::addEdge(int src, int dest,int weight){
    if (isvalidvertex(src) && isvalidvertex(dest)){
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight;
        cout << "Edge added between " << src << " and " << dest << ".\n";
    }
    else{
        cout << "Invalid vertex number.\n";
    }
}

//Function to search for edge in graph
bool Graph::SeachEdge(int src, int dest) {
    if (isvalidvertex(src) && isvalidvertex(dest)) {
        if (adjMatrix[src][dest] == 1){
            cout << "Edge exists between " << src << " and " << dest << ".\n";
            return true;
        }
        else{
            cout << "No edge exists between " << src << " and " << dest << ".\n";
            return false;
        }
    }
    else{
        cout << "Invalid vertex number.\n";
    }
}
//Function to delete edge of graph
void Graph::deleteEdge(int src, int dest) {
    if (isvalidvertex(src) && isvalidvertex(dest)) {
        adjMatrix[src][dest] = 0;
        adjMatrix[dest][src] = 0;
        cout << "Edge deleted between " << src << " and " << dest << ".\n";
    } else {
        cout << "Invalid vertex number.\n";
    }
}