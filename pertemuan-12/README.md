# B-Tree & BST

**Full Code**:
```cpp
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

// CLASS NODE
class Node {
public:
    string name;
    Node* parent;
    vector<Node*> children;

    Node(string folderName, Node* p = NULL) {
        name = folderName;
        parent = p;
    }
};

// CLASS GENERAL TREE
class FolderTree {
private:
    Node* root;
public:

    FolderTree() {
        root = new Node("Root");
    }

    // GET ROOT
    Node* getRoot() {
        return root;
    }

    // MENAMBAH FOLDER
    void addFolder(Node* parent, string folderName) {
        Node* newFolder = new Node(folderName, parent);

        parent->children.push_back(newFolder);

        cout << "Folder '" << folderName
        << "' berhasil ditambahkan ke '"
        << parent->name << "'\n";
    }

    // MENAMPILKAN TREE
    void printTree(Node* node, int level = 0) {
        if(node == NULL) return;

        for(int i = 0; i < level; i++) cout << "│ ";

        if(level > 0) cout << "├── ";

        cout << node->name << endl;

        for(Node* child : node->children) printTree(child, level + 1);
    }

    // PREORDER TRAVERSAL
    // Root -> Child
    void preorder(Node* node) {
        if(node == NULL) return;

        cout << node->name << endl;

        for(Node* child : node->children) preorder(child);
    }

    // POSTORDER TRAVERSAL
    // Child -> Root
    void postorder(Node* node) {
        if(node == NULL) return;

        for(Node* child : node->children) postorder(child);

        cout << node->name << endl;
    }

    // SEARCH FOLDER
    // DFS Recursive
    Node* search(Node* node, string target) {
        if(node == NULL) return NULL;

        if(node->name == target) return node;

        for(Node* child : node->children) {
            Node* result = search(child, target);

            if(result != NULL) return result;
        }

        return NULL;
    }

    // HITUNG JUMLAH FOLDER
    int countFolder(Node* node) {
        if(node == NULL) return 0;

        int total = 1;
        for(Node* child : node->children) total += countFolder(child);

        return total;
    }

    // MENAMPILKAN PATH
    void showPath(Node* node) {
        if(node == NULL)return;

        vector<string> path;
        Node* current = node;

        while(current != NULL) {
            path.push_back(current->name);
            current = current->parent;
        }

        cout << "Path : ";

        for(int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];

            if(i != 0) cout << "/";
        }

        cout << endl;
    }

    // DELETE SUBTREE
    void deleteSubtree(Node* node) {
        if(node == NULL) return;

        for(Node* child : node->children) deleteSubtree(child);

        delete node;
    }

    // HAPUS FOLDER
    void deleteFolder(string folderName) {
        Node* target = search(root, folderName);
        if(target == NULL) {
            cout << "Folder tidak ditemukan!\n";
            return;
        }

        if(target == root) {
            cout << "Root tidak dapat dihapus!\n";
            return;
        }

        Node* parent = target->parent;

        for(auto it = parent->children.begin();
            it != parent->children.end(); it++) {

            if(*it == target) {
                parent->children.erase(it);
                break;
            }
        }

        deleteSubtree(target);
        cout << "Folder berhasil dihapus!\n";
    }
};

// MAIN PROGRAM
int main() {
    SetConsoleOutputCP(65001);
    
    FolderTree tree;
    Node* root = tree.getRoot();

    // MEMBUAT STRUKTUR FOLDER
    tree.addFolder(root, "Documents");
    tree.addFolder(root, "Pictures");
    tree.addFolder(root, "Music");

    Node* documents = tree.search(root, "Documents");
    tree.addFolder(documents, "Kuliah");
    tree.addFolder(documents, "Tugas");

    // TAMPILKAN TREE
    cout << "\n===== STRUKTUR FOLDER =====\n";
    tree.printTree(root);

    // PREORDER
    cout << "\n===== PREORDER TRAVERSAL =====\n";
    tree.preorder(root);

    // POSTORDER
    cout << "\n===== POSTORDER TRAVERSAL =====\n";
    tree.postorder(root);

    // SEARCH
    cout << "\n===== SEARCH FOLDER =====\n";
    Node* result = tree.search(root, "Tugas");

    if(result != NULL) {
        cout << "Folder ditemukan : "
        << result->name << endl;
        tree.showPath(result);
    }
    else cout << "Folder tidak ditemukan\n";

    // COUNT FOLDER
    cout << "\n===== JUMLAH FOLDER =====\n";
    cout << "Total Folder : "
    << tree.countFolder(root)
    << endl;

    // DELETE FOLDER
    cout << "\n===== HAPUS FOLDER =====\n";
    tree.deleteFolder("Pictures");

    // TAMPILKAN TREE SETELAH DELETE
    cout << "\n===== STRUKTUR SETELAH DELETE =====\n";
    tree.printTree(root);

    return 0;
}
```

### Penjelasan Kode
#### 1. `class Node`
Pada bagian ini, variabel `name` digunakan untuk memberi nama folder. Selain itu, terdapat pula variabel `parent` digunakan sebagai _pointer_ ke folder induk, dan variabel `children` yang merupakan _vector_ berisi _pointer_ ke semua folder anak. Selanjutnya, terdapat _constructor_ yang akan mengisi nama folder dan `parent`.

#### 2. `class FolderTree`
Pada bagian ini, akan dibuat folder `Root` sebagai _node_ awal, lalu melalui `Node* getRoot()`, akan dikembalikan _pointer_ ke _root_ agar _main program_ dapat mengaksesnya.

#### 3. `void addFolder(Node* parent, string folderName)`
Fungsi ini digunakan untuk menambah folder baru. Folder baru akan dibuat dengan _parent_ yang ditentukan, lalu dimasukkan ke _vector children_ milik _parent_. Jika folder baru berhasil ditambahkan, maka pesan sukses akan ditampilkan.

#### 4. `void printTree(Node* node, int level = 0)`
Fungsi tersebut digunakan untuk menampilkan struktur _tree_ dari folder-folder yang sudah ada. Parameter `level` menandakan kedalaman (_depth_) yang dimulai dari _root_ (level 0). Fungsi ini akan merekursif ke semua anak.

#### 5. `void preorder(Node* node)`
Fungsi ini digunakan untuk menampilkan urutan folder secara _preorder_, atau lebih jelasnya dimulai dari _root_ terlebih dahulu baru dilanjut dengan anak-anaknya (_root_ > anak pertama > ... > anak kedua > ... > dst).

#### 6. `void postorder(Node* node)`
Fungsi ini digunakan untuk menampilkan urutan folder secara _postorder_, atau dengan urutan dari anak-anak terlebih dahulu (dari kiri ke kanan), baru _root_ setelahnya.

#### 7. `Node* search(Node* node, string target)`
Fungsi tersebut digunakan untuk mencari folder yang ditargetkan. Fungsi tersebut memiliki algoritma pencarian sebagai berikut:
1. Cek _node_ saat ini
2. Jika sama dengan target, _return_ pada _node_ tersebut
3. Jika tidak, maka cari ke semua anak (rekursif)
4. Jika ditemukan di salah satu cabang, _return_ hasil tersebut
5. Jika tidak ditemukan di mana pun, _return_ `NULL`

#### 8. `int countFolder(Node* node)`
Fungsi tersebut digunakan untuk menghitung total folder yang ada. Logika penjumlahan dari total folder yang ada adalah dengan menjumlahkan folder _root_ dengan jumlah semua folder di setiap anak.

#### 9. `void showPath(Node* node)`
Fungsi tersebut digunakan untuk mencari `path` dari folder yang ditargetkan, dengan prosesnya sebagai berikut:
1. Kumpulkan nama folder dari target sampai ke _root_ (ke atas)
2. Simpan dalam _vector_ `path`
3. Cetak dari belakang (_root_ terlebih dahulu) dengan separator `/`

#### 10. `void deleteSubtree(Node* node)`
Fungsi tersebut digunakan untuk menghapus sebuah _subtree_. Penghapusan _subtree_ dilakukan secara _postorder_ (anak dihapus terlebih dahulu, baru _parent_ dihapus setelahnya) agar tidak ada _memory leak_.

#### 11. `void deleteFolder(string folderName)`
Fungsi tersebut digunakan untuk menghapus folder yang ditargetkan, dengan prosesnya sebagai berikut:
1. Cari folder target
2. Lakukan validasi
3. Dapatkan _parent_ dari target
4. Hapus target dari _vector children_ milik _parent_
5. Hapus _subtree_ target (folder dan seluruh isinya)

**Output**:
#### Menambahkan Folder
![Output: Add Folder](image/add_folder.png)

#### Struktur Folder
![Output: Struktur Folder](image/struktur_folder.png)

#### _Preorder Traversal_
![Output: _Preorder Traversal_](image/preorder_traversal.png)

#### _Postorder Traversal_
![Output: _Postorder Traversal_](image/postorder_traversal.png)

#### _Search_, Total, dan Penghapusan Folder
![Output: _Search_, Total, dan Penghapusan Folder](image/search_total_del_folder.png)

#### Struktur Folder setelah Penghapusan
![Output: _After Folder Deletion_](image/after_del.png)
