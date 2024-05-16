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