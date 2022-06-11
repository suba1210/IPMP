#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int src, dest, weight;
};

struct Graph {
	int V, E;
	struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

void printArr(int dist[], int n)
{
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < n; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

void BellmanFord(struct Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}


	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX
			&& dist[u] + weight < dist[v]) {
			printf("Graph contains negative weight cycle");
			return; 
		}
	}

	printArr(dist, V);

	return;
}

int main()
{
	int V; 
	int E = 8; 
    cout<<"\nEnter the number of vertices : ";
    cin>>V;

    cout<<"\nEnter the number of edges : ";
    cin>>E;
	struct Graph* graph = createGraph(V, E);

    cout<<"\nEnter the edges of the graph : ";

    for(int i=0;i<E;i++){
        cout<<"\nSource, destination, weight of edge "<<i+1<<" : ";
        int x,y,z;
        cin>>x>>y>>z;
	    graph->edge[i].src = x;
	    graph->edge[i].dest = y;
	    graph->edge[i].weight = z;        
    }

	BellmanFord(graph, 0);

	return 0;
}
