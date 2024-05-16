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