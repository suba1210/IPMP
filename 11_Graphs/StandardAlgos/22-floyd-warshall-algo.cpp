#include <bits/stdc++.h>
using namespace std;
#define INF 99999

void floydWarshall(vector<vector<int> > graph, int V){
    
    int i,j,k;
    vector<vector<int> > dist(V, vector<int>(V));

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            dist[i][j] = graph[i][j];
        }
    }

    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            for(k=0;k<V;k++){
                if((dist[i][k]+dist[k][j] < dist[i][j]) && (dist[i][k]!=INF && dist[k][j]!=INF)){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j]==INF){
                cout<<"INF"<<" ";
            }
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }


}

int main()
{
    int V = 4;
	vector<vector<int> > graph     
    { 
        { 0, 5, INF, 10 },
	    { INF, 0, 3, INF },
		{ INF, INF, 0, 1 },
		{ INF, INF, INF, 0 } 
    };

	floydWarshall(graph,V);
	return 0;
}
