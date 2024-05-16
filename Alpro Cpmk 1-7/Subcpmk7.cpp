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