# <h1 align="center">TUGAS</h1>
<p align="center">Ananda Rizky</p>

## Subcpmk 2

4.	Tulislah sebuah fungsi program dengan asumsi sebagai berikut:
Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut! (30 Poin)

#### Jawab

```c++
#include <iostream>
#include <vector>
#include <algorithm>

void mergeAndSort(std::vector<int>& A, int m, std::vector<int>& B, int n) {
    int i = m - 1;
    int j = n - 1; 
    int k = m + n - 1;
    
    while (i >= 0 && j >= 0) {
        if (A[i] > B[j]) {
            A[k] = A[i];
            i--;
        } else {
            A[k] = B[j];
            j--;
        }
        k--;
    }
    
    while (j >= 0) {
        A[k] = B[j];
        j--;
        k--;
    }
}

int main() {
    std::vector<int> A = {1, 3, 5, 7, 9, 0, 0, 0, 0, 0}; 
    std::vector<int> B = {2, 4, 6, 8, 10};
    int m = 5; 
    int n = B.size(); 
    
    mergeAndSort(A, m, B, n);
    
    for (int i = 0; i < m + n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

#### Output :

![Screenshot (146)](https://github.com/Zvarxs/Ananda-Rizky-Alpro/assets/162097128/7bed89cd-e701-46c1-a33d-c266da48d8c7)

#### Penjelasan :

Kodingan di atas mendefinisikan sebuah fungsi `mergeAndSort` yang menggabungkan dua array terurut `A` dan `B` dengan asumsi bahwa array `A` memiliki ruang yang cukup untuk menampung elemen-elemen dari array `B`. Fungsi ini menerima referensi ke dua `std::vector<int>` yaitu `A` dan `B`, serta dua integer `m` dan `n` yang menyatakan jumlah elemen valid dalam `A` dan jumlah elemen dalam `B` masing-masing. Proses penggabungan dilakukan dari belakang ke depan untuk menghindari penimpaaan elemen yang belum diproses. Fungsi membandingkan elemen terakhir dari bagian valid `A` dan elemen terakhir `B`, kemudian memindahkan elemen yang lebih besar ke posisi terakhir gabungan `A`. Proses ini diulangi hingga salah satu dari `A` atau `B` habis. Jika masih ada elemen yang tersisa di `B`, elemen-elemen tersebut dipindahkan ke `A`. Setelah penggabungan, array `A` akan berisi semua elemen dari `A` dan `B` dalam urutan yang terurut. Fungsi ini diilustrasikan dalam fungsi `main`, di mana array `A` dan `B` diinisialisasi dan hasil akhir dari array `A` dicetak.

## Subcpmk 3

3.	Tulislah sebuah fungsi program dengan kondisi sebagai berikut:
Terdapat sebuah sorted array of strings yang mana terdapat string kosong diantaranya, carilah lokasi/indeks dari kata yang dicari! (30 Poin)
Input: bola, {“Adi”,””,””, “”, “bermain”, “”, “bola”, “”, “”, “sedang”}
Output: 6

#### Jawab

```c++
#include <iostream>
#include <string>

int findString(const std::string arr[], int size, const std::string& target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == "") {
            int leftMid = mid - 1;
            int rightMid = mid + 1;
            
            while (true) {
                if (leftMid < left && rightMid > right) {
                    return -1; 
                } else if (rightMid <= right && arr[rightMid] != "") {
                    mid = rightMid;
                    break;
                } else if (leftMid >= left && arr[leftMid] != "") {
                    mid = leftMid;
                    break;
                }
                rightMid++;
                leftMid--;
            }
        }

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}

int main() {
    const int size = 10;
    std::string arr[size] = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};
    std::string target = "bola";
    
    int index = findString(arr, size, target);
    
    if (index != -1) {
        std::cout << "Kata '" << target << "' ditemukan di indeks " << index << std::endl;
    } else {
        std::cout << "Kata '" << target << "' tidak ditemukan" << std::endl;
    }

    return 0;
}
```

#### Output :

![Screenshot (147)](https://github.com/Zvarxs/Ananda-Rizky-Alpro/assets/162097128/243733a6-b7b9-4fb4-ac1c-84000281d4f7)

#### Penjelasan :

Kodingan di atas mendefinisikan fungsi `findString` untuk mencari indeks dari kata yang dicari dalam sebuah array terurut yang berisi string kosong di antara string-string lainnya, tanpa menggunakan `std::vector`. Fungsi ini menerima array `arr` dari tipe `std::string`, ukuran array `size`, dan target string `target`. Proses pencarian menggunakan binary search yang dimodifikasi untuk menangani string kosong. Jika elemen tengah (`mid`) adalah string kosong, fungsi mencari string non-kosong terdekat di kiri atau kanan. Setelah menemukan elemen valid di `mid`, fungsi membandingkannya dengan target. Jika cocok, indeks `mid` dikembalikan. Jika target lebih besar, pencarian dilanjutkan di setengah bagian kanan; jika lebih kecil, di setengah bagian kiri. Fungsi ini mengembalikan indeks dari kata yang dicari atau -1 jika tidak ditemukan. Contoh penggunaan fungsi `findString` ditunjukkan dalam `main`, di mana array dan target string diberikan, dan hasil pencarian dicetak.

## Subcpmk 4

1.	Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct! (100 poin)

#### Jawab

```c++
#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int publicationYear;
    std::string publisher;
    float price;
};

void printBookInfo(const Book& book) {
    std::cout << "Title: " << book.title << std::endl;
    std::cout << "Author: " << book.author << std::endl;
    std::cout << "Publication Year: " << book.publicationYear << std::endl;
    std::cout << "Publisher: " << book.publisher << std::endl;
    std::cout << "Price: $" << book.price << std::endl;
}

int main() {
    Book book1;
    book1.title = "C++ Programming";
    book1.author = "Bjarne Stroustrup";
    book1.publicationYear = 1985;
    book1.publisher = "Addison-Wesley";
    book1.price = 59.99f;

    Book book2 = {"The C++ Standard Library", "Nicolai M. Josuttis", 1999, "Addison-Wesley", 69.99f};

    std::cout << "Information about book1:" << std::endl;
    printBookInfo(book1);
    std::cout << std::endl;

    std::cout << "Information about book2:" << std::endl;
    printBookInfo(book2);
    std::cout << std::endl;

    return 0;
}
```

#### Output :

![Screenshot (148)](https://github.com/Zvarxs/Ananda-Rizky-Alpro/assets/162097128/6b2a8c6a-f925-428f-9c21-890e21c1f804)

#### Penjelasan :

Kodingan di atas menunjukkan penggunaan `struct`, sebuah fitur yang memungkinkan pengelompokkan data terkait ke dalam satu entitas. Dalam contoh ini, kita mendefinisikan sebuah `struct` bernama `Book` yang memiliki lima anggota: `title`, `author`, `publicationYear`, `publisher`, dan `price`. Setiap anggota dapat memiliki tipe data yang berbeda, misalnya `std::string` untuk `title` dan `author`, dan `int` untuk `publicationYear`. 

Program juga menyertakan fungsi `printBookInfo`, yang digunakan untuk mencetak informasi tentang buku, menerima objek `Book` sebagai argumen. Fungsi `main` kemudian membuat dua objek dari `Book`, `book1` dan `book2`, masing-masing diinisialisasi dengan menggunakan sintaks yang berbeda. `book1` diinisialisasi dengan mengatur anggota-anggotanya satu per satu, sementara `book2` diinisialisasi secara langsung dengan daftar inisialisasi.

Melalui program ini, kita dapat dengan jelas melihat bagaimana `struct` dapat digunakan untuk mengelompokkan data terkait menjadi satu unit yang dapat diakses dan dikelola bersama. Dengan memanfaatkan `struct`, kode program menjadi lebih terstruktur dan mudah dipahami, sehingga memudahkan dalam pengembangan dan pemeliharaan aplikasi.

## Subcpmk 5

3.	Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom! (50 Poin)

#### Jawab

```c++
#include <iostream>
#include <stack>

struct Node {
    char data;
    Node* next;
    Node(char d) : data(d), next(nullptr) {}
};

void push(Node*& head, char data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

bool isPalindrome(Node* head) {
    std::stack<char> charStack;
    Node* current = head;

    while (current != nullptr) {
        charStack.push(current->data);
        current = current->next;
    }

    current = head;
    while (current != nullptr) {
        char topChar = charStack.top();
        charStack.pop();
        if (current->data != topChar) {
            return false;
        }
        current = current->next;
    }

    return true;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    push(head, 'r');
    push(head, 'a');
    push(head, 'd');
    push(head, 'a');
    push(head, 'r');

    std::cout << "Linked list: ";
    printLinkedList(head);

    if (isPalindrome(head)) {
        std::cout << "Linked list adalah sebuah palindrom." << std::endl;
    } else {
        std::cout << "Linked list bukan sebuah palindrom." << std::endl;
    }

    return 0;
}
```

#### Output :

![Screenshot (149)](https://github.com/Zvarxs/Ananda-Rizky-Alpro/assets/162097128/d54a766b-790c-4d84-bc3a-7337c8069a30)

#### Penjelasan :

Kodingan di atas digunakan untuk mengecek apakah sebuah linked list merupakan sebuah palindrom atau tidak. Palindrom adalah sebuah kata, frasa, angka, atau urutan lainnya yang sama jika dibaca dari depan maupun dari belakang. Dalam konteks linked list, program menggunakan pendekatan menggunakan stack. Pertama, program menambahkan setiap karakter dari linked list ke dalam sebuah stack. Kemudian, program membandingkan setiap karakter pada linked list dengan karakter yang ada di atas stack. Jika semua karakter pada linked list sama dengan karakter yang diambil dari stack, maka linked list tersebut adalah sebuah palindrom. Namun, jika terdapat perbedaan minimal satu karakter, maka linked list tersebut bukanlah sebuah palindrom. Program juga menyediakan fungsi untuk mencetak linked list dan contoh penggunaan program untuk mengecek sebuah linked list yang terdiri dari karakter "r", "a", "d", "a", "r", yang merupakan sebuah palindrom. Dengan menggunakan pendekatan stack, program memberikan solusi yang efisien dalam mengecek palindrom pada linked list.

## Subcpmk 6

1.	Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)! (60 Poin)

#### Jawab

```c++
#include <iostream>

#define MAX_SIZE 5

struct Stack {
    int top;
    int items[MAX_SIZE];
};

Stack createStack() {
    Stack stack;
    stack.top = -1;
    return stack;
}

bool isEmpty(const Stack& stack) {
    return stack.top == -1;
}

bool isFull(const Stack& stack) {
    return stack.top == MAX_SIZE - 1;
}

void push(Stack& stack, int newItem) {
    if (isFull(stack)) {
        std::cout << "Stack penuh. Penambahan gagal." << std::endl;
    } else {
        stack.items[++stack.top] = newItem;
        std::cout << "Elemen " << newItem << " ditambahkan ke stack." << std::endl;
    }
}

void pop(Stack& stack) {
    if (isEmpty(stack)) {
        std::cout << "Stack kosong. Penghapusan gagal." << std::endl;
    } else {
        std::cout << "Elemen " << stack.items[stack.top--] << " dihapus dari stack." << std::endl;
    }
}

int peek(const Stack& stack) {
    if (isEmpty(stack)) {
        std::cout << "Stack kosong. Tidak ada elemen untuk dilihat." << std::endl;
        return -1;
    } else {
        return stack.items[stack.top];
    }
}

int main() {
    Stack stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    std::cout << "Elemen teratas dari stack: " << peek(stack) << std::endl;

    pop(stack);

    std::cout << "Elemen teratas dari stack setelah penghapusan: " << peek(stack) << std::endl;

    return 0;
}
```

#### Output :

![Screenshot (150)](https://github.com/Zvarxs/Ananda-Rizky-Alpro/assets/162097128/8d906137-3877-4f2a-9773-7aab562356c2)

#### Penjelasan :

Dari operasi-operasi dasar pada struktur data stack. Struktur data `Stack` didefinisikan menggunakan sebuah array yang berukuran tetap. Program menyediakan operasi untuk membuat stack baru, mengecek apakah stack kosong atau penuh, menambahkan elemen ke dalam stack (push), menghapus elemen teratas dari stack (pop), serta melihat elemen teratas dari stack tanpa menghapusnya (peek). Setiap operasi dilakukan dengan memanipulasi nilai `top` yang merupakan indeks teratas dari stack. Program utama menunjukkan contoh penggunaan operasi-operasi stack, yaitu menambahkan beberapa elemen ke dalam stack, melihat elemen teratas dari stack, dan menghapus elemen teratas dari stack. Dengan menggunakan pendekatan ini, program memberikan solusi yang efisien untuk mengelola data dengan struktur stack.

## Subcpmk 7

1.	Tulislah sebuah program dari operasi queue seperti enqueue/add, dequeue/remove, isEmpty, isFull, dll(min 5)! (60 Poin)

#### Jawab

```c++
#include <iostream>

#define MAX_SIZE 5

struct Queue {
    int front, rear, size;
    int elements[MAX_SIZE];
};

Queue createQueue() {
    Queue queue;
    queue.front = 0;
    queue.rear = -1;
    queue.size = 0;
    return queue;
}

bool isEmpty(const Queue& queue) {
    return queue.size == 0;
}

bool isFull(const Queue& queue) {
    return queue.size == MAX_SIZE;
}

void enqueue(Queue& queue, int newItem) {
    if (isFull(queue)) {
        std::cout << "Queue penuh. Penambahan gagal." << std::endl;
    } else {
        queue.rear = (queue.rear + 1) % MAX_SIZE;
        queue.elements[queue.rear] = newItem;
        queue.size++;
        std::cout << "Elemen " << newItem << " ditambahkan ke dalam queue." << std::endl;
    }
}

void dequeue(Queue& queue) {
    if (isEmpty(queue)) {
        std::cout << "Queue kosong. Penghapusan gagal." << std::endl;
    } else {
        std::cout << "Elemen " << queue.elements[queue.front] << " dihapus dari queue." << std::endl;
        queue.front = (queue.front + 1) % MAX_SIZE;
        queue.size--;
    }
}

int peek(const Queue& queue) {
    if (isEmpty(queue)) {
        std::cout << "Queue kosong. Tidak ada elemen untuk dilihat." << std::endl;
        return -1;
    } else {
        return queue.elements[queue.front];
    }
}

int main() {
    Queue queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    std::cout << "Elemen depan dari queue: " << peek(queue) << std::endl;

    dequeue(queue);

    std::cout << "Elemen depan dari queue setelah penghapusan: " << peek(queue) << std::endl;

    return 0;
}
```

#### Output :

![Screenshot (151)](https://github.com/Zvarxs/Ananda-Rizky-Alpro/assets/162097128/0bf1b18e-14fc-4332-9f8a-adf0a3a9dbc5)

#### Penjelasan :

Dari operasi-operasi dasar pada struktur data queue. Struktur data `Queue` didefinisikan menggunakan sebuah array yang berukuran tetap. Program menyediakan operasi untuk membuat queue baru, mengecek apakah queue kosong atau penuh, menambahkan elemen ke dalam queue (enqueue/add), menghapus elemen dari depan queue (dequeue/remove), serta melihat elemen depan dari queue tanpa menghapusnya. Operasi-operasi ini dilakukan dengan memanipulasi nilai `front`, `rear`, dan `size` yang merupakan atribut-atribut dari queue. Program utama menunjukkan contoh penggunaan operasi-operasi queue, yaitu menambahkan beberapa elemen ke dalam queue, melihat elemen depan dari queue, dan menghapus elemen depan dari queue. Dengan menggunakan pendekatan ini, program memberikan solusi yang efisien dalam mengelola data dengan struktur queue.