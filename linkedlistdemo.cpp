#include <iostream>

using namespace std; 

struct Node {
    int data;
    Node* next;
};

Node* append(Node* head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        return newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        return head;
    }
}

void display(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    int choice;
    int element;

    do {
        cout << "Menu: \n";
        cout << "1. Tambahkan elemen ke linked list\n";
        cout << "2. Tampilkan linked list\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan elemen yang ingin ditambahkan: ";
                cin >> element;
                head = append(head, element);
                break;
            case 2:
                cout << "Isi linked list: ";
                display(head);
                break;
            case 3:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (choice != 3);


    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
