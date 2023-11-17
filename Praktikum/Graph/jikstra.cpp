#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>  // Include the algorithm header
using namespace std;

class GraphAdjMatrix
{
public:
    int vertices;
    vector<vector<int>> adjMatrix;
    bool isDirected;
    bool isWeighted;

    GraphAdjMatrix(int numVertices, bool isDirected = false, bool isWeighted = false)
    {
        this->vertices = numVertices;
        this->adjMatrix = vector<vector<int>>(numVertices, vector<int>(numVertices, 0));
        this->isDirected = isDirected;
        this->isWeighted = isWeighted;
    }

    void addEdge(int from, int to, int weight = 1)
    {
        // Check out of bounds
        if (from < 0 || from >= this->vertices ||
            to < 0 || to >= this->vertices)
        {
            cout << "Vertex does not exist\n";
            return;
        }

        if (!this->isWeighted)
        {
            weight = 1;
        }

        this->adjMatrix[from][to] = weight;

        if (!this->isDirected)
        {
            this->adjMatrix[to][from] = weight;
        }
    }

    void printGraph()
    {
        for (int i = 0; i < this->vertices; i++)
        {
            for (int j = 0; j < this->vertices; j++)
            {
                cout << this->adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dijkstra(int startVertex, int target) {
        if (startVertex < 0 || startVertex >= this->vertices)
        {
            cout << "Invalid vertex\n";
            return;
        }

        vector<int> distance(this->vertices, INT_MAX);
        vector<bool> visited(this->vertices, false);
        vector<int> previous(this->vertices, -1);

        distance[startVertex] = 0;

        for (int count = 0; count < this->vertices - 1; count++)
        {
            int u = minDistance(distance, visited);

            visited[u] = true;

            for (int v = 0; v < this->vertices; v++)
            {
                if (!visited[v] && this->adjMatrix[u][v] && distance[u] != INT_MAX &&
                    distance[u] + this->adjMatrix[u][v] < distance[v])
                {
                    distance[v] = distance[u] + this->adjMatrix[u][v];
                    previous[v] = u;
                }
            }
        }

        if (distance[target] == INT_MAX) {
            cout << "No path from vertex " << startVertex << " to vertex " << target << endl;
            return;
        }

        cout << "Shortest Path from vertex " << startVertex << " to vertex " << target << ":\n";
        int current = target;
        vector<int> path;
        while (current != startVertex) {
            path.push_back(current);
            current = previous[current];
        }
        path.push_back(startVertex);
        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++) {
            cout << "Vertex " << path[i];
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << "\nTotal Distance = " << distance[target] << endl;
    }

    int minDistance(const vector<int> &distance, const vector<bool> &visited)
    {
        int minDistance = INT_MAX, minIndex;

        for (int v = 0; v < this->vertices; v++)
        {
            if (!visited[v] && distance[v] <= minDistance)
            {
                minDistance = distance[v];
                minIndex = v;
            }
        }

        return minIndex;
    }
};

int main()
{
    GraphAdjMatrix graph(9, false, true);
    graph.addEdge(0, 1, 3);
    graph.addEdge(0, 2, 2);
    graph.addEdge(0, 3, 8);
    graph.addEdge(0, 4, 4);
    graph.addEdge(1, 5, 2);
    graph.addEdge(1, 6, 3);
    graph.addEdge(2, 6, 1);
    graph.addEdge(3, 5, 6);
    graph.addEdge(4, 5, 1);
    graph.addEdge(5, 6, 4);
    graph.addEdge(5, 7, 2);
    graph.addEdge(5, 8, 9);
    graph.addEdge(6, 7, 2);
    graph.addEdge(7, 8, 4);

    graph.printGraph();

    graph.dijkstra(0, 8);

    return 0;
}