#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000;
vector<pair<int,int>> graph[100];
vector<string> names={
    "Andi","Budi","Citra","Dina","Eko"
};

class Graph{
private:
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;
public:
    Graph(int vertices){
        V=vertices;
        adj.resize(V);
        visited.resize(V,false);
    }

    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int start){
        vector<bool> visited(V,false);
        queue<int> q;

        visited[start]=true;
        q.push(start);

        while(!q.empty()){
            int v=q.front();
            q.pop();
            cout<<names[v]<<" ";

            for(int u : adj[v]){
                if(!visited[u]){
                    visited[u]=true;
                    q.push(u);
                }
            }
        }
    }

    void DFS(int v){
        visited[v]=true;
        cout<<names[v]<<" ";

        for(int u : adj[v]){
            if(!visited[u])DFS(u);
        }
    }
};

void dijkstra(int start,int V){
    vector<int> dist(V,INF);
    priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
    > pq;

    dist[start]=0;
    pq.push({0,start});

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();

        for(auto edge : graph[u]){
            int v=edge.first;
            int w=edge.second;

            if(dist[v] > dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }

    cout<<"\nJarak Terpendek dari Andi:\n";

    for(int i=0;i<V;i++)cout<<names[i]<<" : "<<dist[i]<<endl;
}

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    cout<<"BFS:\n";
    g.BFS(0);

    cout<<"\n\nDFS:\n";
    g.DFS(0);

    graph[0].push_back({1,1});
    graph[1].push_back({0,1});

    graph[0].push_back({2,1});
    graph[2].push_back({0,1});

    graph[1].push_back({3,1});
    graph[3].push_back({1,1});

    graph[2].push_back({4,1});
    graph[4].push_back({2,1});

    cout<<"\n\nDijkstra:";
    dijkstra(0,5);

    return 0;
}
