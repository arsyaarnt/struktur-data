# Queue

## Implementasi _Queue_ dengan _Array_

**Full Code**:
```cpp
#include <iostream>
using namespace std;

#define MAX 5

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return(front == -1);
    }

    bool isFull() {
        return(rear == MAX - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        if (isEmpty()) front = 0;

        arr[++rear] = x;
        cout << "Elemen " << x << " masuk ke queue\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Elemen " << arr[front] << " keluar dari queue\n";

        if (front == rear) front = rear = -1;
        else front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue kosong\n";
            return;
        }

        cout << "Isi Queue: ";

        for (int i = front; i <= rear; i++) cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}

```

### Penjelasan Kode
Pada awal kode tersebut, dibuat `class` _queue_ yang memiliki ukuran = `MAX` (lima), serta `front` dan `rear`. `Front` menunjuk pada elemen pertama dari _queue_, sedangkan `rear` merujuk pada elemen terakhir dari _queue_. Pada kondisi awal, `front` dan `rear` dari _queue_ akan di-set terlebih dahulu menjadi = -1, menandakan bahwa _queue_ masih kosong.

#### Penjelasan Fungsi
##### 1. `isEmpty()`
Fungsi tersebut digunakan untuk mengecek, apakah _queue_ masih kosong atau tidak. _Queue_ dikatakan masih kosong, apabila nilai `front` = 1.

##### 2. `isFull()`
Fungsi tersebut digunakan untuk mengecek, apakah _queue_ sudah penuh (dalam kasus ini, _queue_ maksimal berisi lima elemen/antrean). _Queue_ dikatakan penuh, apabila nilai `rear` = `MAX` - 1 (indeks terakhir).

##### 3. `enqueue(int x)`
Fungsi tersebut digunakan untuk menambah elemen pada _queue_. _Queue_ akan dicek terlebih dahulu, jika ia sudah penuh (`isFull()` = _true_), maka elemen di dalam _queue_ sudah tidak dapat ditambah. Namun, jika _queue_ masih kosong (`isEmpty()` = _true_), maka `front` akan di-_set_ ke index 0. Setelah itu, `rear` akan di-_increment_ terlebih dahulu, dan selanjutnya nilai (yang dalam kasus ini ada pada variabel `x`) dimasukkan.

##### 4. `dequeque()`
Fungsi tersebut digunakan untuk menghapus elemen pada _queue_. _Queue_ akan dicek terlebih dahulu, jika ia sudah kosong (`isEmpty()` = _true_), maka sudah tidak ada elemen yang dapat dihapus. Namun, jika belum, maka `front` dapat di-_increment_ (atau digeser ke kanan) (jika tinggal satu elemen, maka nilai `front` = `rear` = 1).

##### 5. `display()`
Fungsi tersebut digunakan untuk menampilkan isi _queue_. _Queue_ akan dicek terlebih dahulu, jika ia memiliki isi (`isEmpty()` = _false_), maka isi _queue_ dapat ditampilkan satu per satu menggunakan _for loop_.

**Output**:

![Output File queue_array.cpp](image/queue_array.png)

## Implementasi _Queue_ dengan _Linked List_

**Full Code**:
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void enqueue(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if (rear == NULL) front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Elemen " << x << " masuk ke queue\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong\n";
            return;
        }

        Node* temp = front;
        cout << "Elemen " << temp->data << " keluar dari queue\n";

        front = front->next;

        if (front == NULL) rear = NULL;

        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue kosong\n";
            return;
        }

        Node* temp = front;
        cout << "Isi Queue: ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}
```

### Penjelasan Kode
Terdapat _struct_ `Node` yang digunakan untuk menyimpan nilai elemen dan _pointer_ ke _node_ berikutnya. Lalu, terdapat pula _class queue_ dengan _pointer_ ke _node_ paling depan (`*front`) dan ke _node_ paling belakang (`*rear`). Selanjutnya, `front` dan `rear` akan di-_set_ = `NULL`.

#### Penjelasan Fungsi
##### 1. `isEmpty()`
Fungsi tersebut digunakan untuk mengecek, apakah _queue_ masih kosong atau tidak. _Queue_ dikatakan masih kosong, apabila nilai `front` = `NULL`.

##### 2. `enqueue(int x)`
Fungsi tersebut digunakan untuk menambah elemen pada _queue_. Pertama, _node_ baru akan dibuat di _heap memory_, lalu di-_set_ = `NULL`. Setelahnya, jika _queue_ kosong, maka _node_ baru tersebut akan menjadi satu-satunya elemen. Namun, jika tidak, maka _node_ baru akan disambungkan dengan _node_ yang lama, lalu _rear_ akan di-_update_ ke _node_ yang baru.

##### 3. `dequeue()`
Fungsi tersebut digunakan untuk menghapus elemen pada _queue_. Apabila _queue_ belum kosong, maka _node_ yang akan dihapus (umumnya _node_ terdepan) akan disimpan di variabel sementara untuk di-_print_. Setelah itu, `front` akan digeser ke _node_ berikutnya. Apabila _queue_ menjadi kosong setelah proses penghapusan tersebut, maka `rear` = `NULL`. Terakhir, memori _node_ yang dihapus akan dibebaskan.

##### 4. `display()`
Fungsi tersebut digunakan untuk menampilkan isi _queue_. Apabila _queue_ tidak kosong, maka dimulai dari depan, dengan menggunakan variabel sementara dan _while loop_, isi dari _queue_ akan di-_print_ satu per satu, diikuti dengan variabel sementara yang akan pindah ke _node_ berikutnya.

**Output**:

![Output File queue_linked_list.cpp](image/queue_linked_list.png)
