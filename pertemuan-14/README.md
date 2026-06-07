# Graf

## Adjacency Matrix
**Full Code**:
```cpp
#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int matrix[100][100];
    int vertices;
public:
    Graph(int v){
        vertices = v;
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++) matrix[i][j]=0;
        }
    }

    void addEdge(int u,int v){
        matrix[u][v]=1;
        matrix[v][u]=1;
    }

    void display(){
        cout<<"Adjacency Matrix"<<endl;
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++) cout<<matrix[i][j]<<" ";

            cout<<endl;
        }
    }
};

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.display();

    return 0;
}
```

### Penjelasan Kode
#### 1. `Graph(int v)`
Merupakan _constructor_ yang berfungsi untuk membuat graf dengan jumlah vertex sebanyak `v`. Pada fungsi ini, dilakukan inisialisasi kepada seluruh elemen _adjacency matrix_ menjadi bernilai nol, menandakan bahwa belum terdapat hubungan antar vertex.

#### 2. `void addEdge(int u, int v)`
Fungsi tersebut digunakan untuk menambahkan sisi (_edge_) antara vertex `u` dan vertex `v`. Karena graf yang digunakan merupakan _undirected graph_ (graf tak berarah), maka nilai pada `matrix[u][v]` dan `matrix[v][u]` sama-sama bernilai satu.

#### 3. `void display()`
Fungsi tersebut digunakan untuk menampilkan _adjacency matrix_. Setiap baris dan kolom pada matriks menunjukkan hubungan antar vertex dalam graf.

**Output**:

![Output adj_matrix.cpp](image/adj_matrix.png)

## Adjacency List
**Full Code**:
```cpp
#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    int V;
    vector<vector<int>> adj;
public:
    Graph(int vertices){
        V=vertices;
        adj.resize(V);
    }

    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void display(){
        for(int i=0;i<V;i++){
            cout<<i<<" -> ";
            for(int node : adj[i])cout<<node<<" ";
            cout<<endl;
        }
    }
};

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.display();

    return 0;
}
```

### Penjelasan Kode
#### 1. `Graph(int vertices)`
Merupakan _constructor_ yang digunakan untuk membuat graf dengan jumlah vertex sebanyak `vertices`. Fungsi tersebut juga digunakan untuk menginisialisasi _adjacency list_ dengan ukuran yang sesuai menggunakan `adj.resize(V)`.

#### 2. `void addEdge(int u, int v)`
Fungsi tersebut digunakan untuk menambahkan hubungan (_edge_) antara vertex `u` dan vertex `v`. Karena graf yang digunakan merupakan _undirected graph_ (graf tak berarah), maka `v` ditambahkan ke daftar tetangga `u` dan `u` juga ditambahkan ke daftar tetangga `v`.

#### 3. `void display()`
Fungsi tersebut digunakan untuk menampilkan _adjacency list_. Setiap vertex akan ditampilkan bersama daftar vertex lain yang terhubung langsung dengannya.

**Output**:

![Output adj_list.cpp](image/adj_list.png)

## BFS (Breadth-First Search)
**Full Code**:
```cpp
#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    int V;
    vector<vector<int>> adj;
public:
    Graph(int vertices){
        V=vertices;
        adj.resize(V);
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
            cout<<v<<" ";

            for(int u : adj[v]){
                if(!visited[u]){
                    visited[u]=true;
                    q.push(u);
                }
            }
        }
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    cout<<"BFS : "<<endl;
    g.BFS(0);

    return 0;
}
```

### Penjelasan Kode
#### 1. `Graph (int vertices)`
Merupakan _constructor_ yang digunakan untuk membuat graf dengan jumlah vertex sebanyak `vertices`. Fungsi tersebut juga digunakan untuk menginisialisasi _adjacency list_ dengan ukuran yang sesuai menggunakan `adj.resize(V)`.

#### 2. `void addEdge(int u, int v)`
Fungsi tersebut digunakan untuk menambahkan hubungan (_edge_) antara vertex `u` dan vertex `v`. Karena graf yang digunakan merupakan _undirected graph_ (graf tak berarah), maka `v` ditambahkan ke daftar tetangga `u` dan `u` juga ditambahkan ke daftar tetangga `v`.

#### 3. `void BFS(int start)`
Fungsi tersebut mengimplementasikan algoritma `Breadth-First Search` (BFS), yang dalam kasus ini proses traversal akan dimulai dari vertex `start`. Struktur data _queue_ akan digunakan untuk mengunjungi vertex secara bertahap berdasarkan tingkat kedekatannya. Selain itu, _array_ `visited` digunakan untuk memastikan setiap vertex hanya dikunjungi satu kali.

**Output**:

![Output bfs.cpp](image/bfs.png)

## DFS (Depth-First Search)
**Full Code**:
```cpp
#include <bits/stdc++.h>
using namespace std;

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

    void DFS(int v){
        visited[v]=true;
        cout<<v<<" ";

        for(int u : adj[v]){
            if(!visited[u])DFS(u);
        }
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    cout<<"DFS : "<<endl;
    g.DFS(0);

    return 0;
}
```

### Penjelasan Kode
#### 1. `Graph (int vertices)`
Merupakan _constructor_ yang digunakan untuk membuat graf dengan jumlah vertex sebanyak `vertices`. Fungsi tersebut juga digunakan untuk menginisialisasi _adjacency list_ dengan ukuran yang sesuai menggunakan `adj.resize(V)`. Selanjutnya, _constructor_ ini juga akan menginisialisasi _vector_ `visited` dengan nilai `false` untuk menandai bahwa seluruh vertex belum pernah dikunjungi.

#### 2. `void addEdge(int u, int v)`
Fungsi tersebut digunakan untuk menambahkan hubungan (_edge_) antara vertex `u` dan vertex `v`. Karena graf yang digunakan merupakan _undirected graph_ (graf tak berarah), maka `v` ditambahkan ke daftar tetangga `u` dan `u` juga ditambahkan ke daftar tetangga `v`.

#### 3. `void DFS(int v)`
Fungsi tersebut mengimplementasikan algoritma `Depth First Search` (DFS) secara rekursif. Vertex yang sedang dikunjungi akan ditandai sebagai telah dikunjungi (`visited[v] = true`), kemudian seluruh tetangganya akan ditelusuri secara mendalam hingga tidak ada lagi vertex yang dapat dikunjungi.

**Output**:

![Output dfs.cpp](image/dfs.png)

## Graf Berbobot
**Full Code**:
```cpp
#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    int V;
    vector<pair<int,int>> adj[100];
public:
    Graph(int vertices){
        V=vertices;
    }

    void addEdge(int u,int v,int weight){
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }

    void display(){
        for(int i=0;i<V;i++){
            cout<<"Vertex "<<i<<" : ";

            for(auto edge : adj[i])cout<<"("<<edge.first<<","<<edge.second<<") ";

            cout<<endl;
        }
    }
};

int main(){
    Graph g(4);
    g.addEdge(0,1,3);
    g.addEdge(1,2,2);
    g.addEdge(2,3,0);
    g.addEdge(3,0,1);

    g.display();

    return 0;
}
```

### Penjelasan Kode
#### 1. `Graph(int vertices)`
Merupakan _constructor_ yang berfungsi untuk membuat graf berbobot (_weighted graph_) dengan jumlah vertex sebanyak `vertices`. Nilai tersebut disimpan ke dalam variabel `V` untuk digunakan pada operasi graf selanjutnya.

#### 2. `void addEdge(int u, int v, int weight)`
Fungsi tersebut digunakan untuk menambahkan hubungan (_edge_) antara vertex `u` dan vertex `v`. Karena graf yang digunakan merupakan _undirected graph_ (graf tak berarah), maka pasangan `(v, weight)` ditambahkan ke daftar tetangga `u` dan `(u, weight)` juga ditambahkan ke daftar tetangga `v`.

#### 3. `void display()`
Fungsi tersebut digunakan untuk menampilkan _adjacency list_ berbobot. Setiap vertex akan ditampilkan bersama daftar vertex lain yang terhubung langsung dengannya, beserta bobot dari masing-masing _edge_.

**Output**:

![Output graf_berbobot.cpp](image/graf_berbobot.png)

## Dijkstra
**Full Code**:
```cpp
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
```

### Penjelasan Kode
#### 1. `void dijkstra(int start, int V)`
Fungsi tersebut mengimplementasikan algoritma `Dijkstra` untuk mencari jarak terpendek dari vertex awal (_start_) ke seluruh vertex lain dalam graf berbobot. Algoritma ini menggunakan struktur data _priority queue_ untuk memilih vertex dengan jarak sementara terkecil yang akan diproses terlebih dahulu.

#### 2. Alur Program
1. Semua jarak diinisialisasi dengan nilai `INF`.
2. Jarak vertex awal diubah menjadi nol.
3. Vertex awal dimasukkan ke dalam _priority queue_.
4. Selama _priority queue_ tidak kosong, vertex dengan jarak terkecil akan diambil.
5. Semua tetangga dari vertex tersebut diperiksa.
6. Jika ditemukan jalur yang lebih pendek, nilai jarak diperbarui dan vertex dimasukkan kembali ke _priority queue_.
7. Setelah seluruh vertex diproses, hasil jarak terpendek ditampilkan.

**Output**:

![Output dijkstra.cpp](image/dijkstra.png)

## Studi Kasus: Pertemanan Media Sosial
**Full Code**:
```cpp
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
```

### Penjelasan Kode
#### 1. `Graph(int vertices)`
Merupakan _constructor_ yang digunakan untuk membuat graf dengan jumlah vertex sebanyak `vertices`. Fungsi tersebut juga digunakan untuk menginisialisasi _adjacency list_ dengan ukuran yang sesuai menggunakan `adj.resize(V)`. Selanjutnya, _constructor_ ini juga akan menginisialisasi _vector_ `visited` dengan nilai `false` untuk menandai bahwa seluruh vertex belum pernah dikunjungi (inisialisasi nilai `false` tersebut nantinya akan digunakan pada proses DFS).

#### 2. `void addEdge(int u, int v)`
Fungsi yang digunakan untuk menambahkan hubungan pertemanan antara dua pengguna. Karena graf bersifat _undirected graph_ (graf tak berarah), maka setiap pengguna akan disimpan sebagai tetangga satu sama lain.

#### 3. `void BFS(int start)`
Fungsi tersebut mengimplementasikan algoritma `Breadth First Search` (BFS). Traversal dimulai dari vertex `start` dan menggunakan struktur data _queue_ untuk mengunjungi setiap pengguna berdasarkan tingkat kedekatan hubungan. Pada studi kasus ini, BFS digunakan untuk menelusuri jaringan pertemanan dari Andi ke teman-teman yang terhubung dengannya.

#### 4. `void DFS(int v)`
Fungsi tersebut mengimplementasikan algoritma `Depth First Search` (DFS) secara rekursif. Vertex yang dikunjungi akan ditandai pada _vector_ `visited`, kemudian algoritma akan menelusuri setiap cabang pertemanan sedalam mungkin sebelum kembali ke cabang sebelumnya (_backtracking_).

#### 5. `void dijkstra(int start, int V)`
Fungsi tersebut mengimplementasikan algoritma `Dijkstra` untuk mencari jarak terpendek dari pengguna awal (`start`) ke seluruh pengguna lain dalam graf berbobot. _Priority queue_ digunakan untuk memilih vertex dengan jarak sementara terkecil sehingga proses pencarian jalur terpendek menjadi lebih efisien.

**Output**:

![Output pertemanan_medsos.cpp](image/pertemanan_medsos.png)
