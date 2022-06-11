#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int src, dest, weight;
    Edge(int src, int dest, int weight){
        this->src=src;
        this->dest=dest;
        this->weight=weight;
    }
};

class Graph{
    public:
    int V, E;
    vector<Edge> edges;
    Graph(int V,int E){
        this->V=V;
        this->E=E;
    }
};

class subset{
    public:
    int parent, rank;
};

bool compare(Edge a, Edge b){
    return a.weight<b.weight;
}

int find(subset subsets[], int i){
    if(subsets[i].parent!=i){
        subsets[i].parent = find(subsets, subsets[i].parent);
    } 
    return subsets[i].parent;
}

void union1(subset subsets[], int x, int y){
    int xroot = find(subsets,x);
    int yroot = find(subsets,y);

    if(subsets[xroot].rank>subsets[yroot].rank){
        subsets[yroot].parent=xroot;
    }
    else if(subsets[xroot].rank<subsets[yroot].rank){
        subsets[xroot].parent=yroot;
    }
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void kruskalAlgorithm(Graph* graph){
    int V = graph->V;
    vector<Edge> edges = graph->edges;
    sort(edges.begin(), edges.end(), compare);

    subset subsets[V];

    for(int i=0;i<V;i++){
        subsets[i].parent = i;
        subsets[i].rank=0;
    }

    int E=0, i=0, totalWeight=0;

    cout<<"Minimum Spanning Tree : "<<endl;

    while(E<V-1 && i<graph->E){
        Edge nextEdge = edges[i++];
        int xroot = find(subsets, nextEdge.src);
        int yroot = find(subsets, nextEdge.dest);

        if(xroot!=yroot){
            E++;
            cout<<nextEdge.src<<" - "<<nextEdge.dest<<" : "<<nextEdge.weight<<endl;
            union1(subsets,xroot,yroot);
            totalWeight += nextEdge.weight;
        }

    }

    cout << "Total Weight : " << totalWeight << endl;

}

int main(){
    int V, E;
    cout<<"Vertices : ";
    cin>>V;
    cout<<"\nEdges : ";
    cin>>E;
    Graph* graph = new Graph(V,E);
    cout<<"\nAll Edges : "<<endl;
    int s,d,w;
    for(int i=0;i<E;i++){
        cout<<"\nSource, destination, weight of vertex "<<i+1<<" : ";
        cin>>s>>d>>w;
        Edge edge(s,d,w);
        graph->edges.push_back(edge);
    }
    kruskalAlgorithm(graph);
}
