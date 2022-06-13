#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src, dest, weight;
    Edge(int src, int dest, int weight)
    {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }
};

class Graph
{
public:
    int V, E;
    vector<Edge> edges;
};

Graph *createGraph(int V, int E)
{
    Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    return graph;
}

class subset
{
public:
    int parent;
    int rank;
};

int find(subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void union1(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void kruskalAlgorithm(Graph *graph)
{
    int V = graph->V;
    vector<Edge> edges = graph->edges;
    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
         { return a.weight < b.weight; });
    subset subsets[V];
    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    int E = 0;
    int i = 0, totalWeight = 0;
    cout << "Minimum Spanning Tree : " << '\n';
    while (E < V - 1 && i < graph->E)
    {
        Edge nextEdge = edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        if (x != y)
        {
            E++;
            cout << nextEdge.src << " - " << nextEdge.dest << " : " << nextEdge.weight << endl;
            union1(subsets, x, y);
            totalWeight += nextEdge.weight;
        }
    }

    cout << "Total Weight : " << totalWeight << endl;
}

int main()
{
    int V;
    int E;
    cout << "Enter the number of vertices of the graph : ";
    cin >> V;
    cout << "Enter the number of edges of the graph : ";
    cin >> E;
    Graph *graph = createGraph(V, E);

    cout << "\n---------------------------------------\n\n";

    cout << "Enter the edges of the graph : " << '\n';

    for (int i = 0; i < E; i++)
    {
        cout << "Enter the source, destination and the weight of the edge " << i + 1 << " : " << '\n';
        int src, dest, weight;
        cin >> src >> dest >> weight;
        Edge edge(src, dest, weight);
        graph->edges.push_back(edge);
    }

    kruskalAlgorithm(graph);
}
