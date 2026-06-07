#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000;
vector<pair<int,int>> graph[100];

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

    cout<<"Jarak Terpendek"<<endl;

    for(int i=0;i<V;i++)cout<<i<<" : "<<dist[i]<<endl;
}

int main(){
    graph[0].push_back({1,5});
    graph[1].push_back({0,5});
    graph[0].push_back({2,3});
    graph[2].push_back({0,3});

    dijkstra(0, 3);

    return 0;
}
